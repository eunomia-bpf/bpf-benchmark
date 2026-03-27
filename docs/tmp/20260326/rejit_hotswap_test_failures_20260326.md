# REJIT Hotswap 压力测试失败报告

日期：2026-03-26

## 概述

为 6 个 prog_type 编写了 REJIT hot-swap 压力测试（真实 attach + 持续触发 + 并发 REJIT）。
VM 验证结果：1/6 PASS，5/6 FAIL。

## 测试结果

| prog_type | 测试文件 | 结果 | 错误信息 |
|-----------|---------|------|---------|
| tracepoint | `rejit_hotswap_tracepoint.c` | ✅ PASS | - |
| kprobe | `rejit_hotswap_kprobe.c` | ❌ FAIL | `failed to patch total delta immediate` |
| perf_event | `rejit_hotswap_perf_event.c` | ❌ FAIL | `perf_event_open failed` |
| fentry | `rejit_hotswap_fentry.c` | ❌ FAIL | `BPF_PROG_REJIT failed` + verifier: `FENTRY/FEXIT program can only be attached to another program annotated with BTF` |
| LSM | `rejit_hotswap_lsm.c` | ❌ FAIL | `timed out waiting for delta=1 (total_delta=0 event_delta=0)` |
| XDP | `rejit_hotswap_xdp.c` | ❌ FAIL | `timed out waiting for delta=1 (total_delta=8 event_delta=8)` |

## 逐项分析

### 1. kprobe: `failed to patch total delta immediate`

**类别**：测试代码 bug

**分析**：测试通过扫描 `orig_insns` 查找 `BPF_MOV_IMM` 指令来定位要 patch 的常量。但 clang 编译后的 bytecode 可能用不同的指令模式加载常量（如 `LD_IMM64`、或把常量内联到 ALU 指令的 imm 字段），导致 pattern 匹配失败。

**修复方向**：改用更鲁棒的 patch 方式 — 在 .bpf.c 中用 volatile global 变量存储 delta，REJIT 时通过 map_inline 或直接修改 .rodata section 中的值。或者改用双程序切换方式（REJIT 替换整个 bytecode 而非 patch 单条指令）。

### 2. perf_event: `perf_event_open failed`

**类别**：VM 环境问题

**分析**：VM 中可能缺少 `PERF_TYPE_SOFTWARE` / `PERF_COUNT_SW_CPU_CLOCK` 的支持，或缺少 `CAP_PERFMON` 权限。virtme-ng VM 中 perf 子系统可能未完全初始化。

**修复方向**：检查 perf_event_open 的 errno，如果是 ENOENT/EACCES 则尝试其他 perf event 类型（如 PERF_COUNT_SW_PAGE_FAULTS）或改用 timer-based 触发。

### 3. fentry: `BPF_PROG_REJIT failed` (BTF annotation)

**类别**：**真实内核限制 / bug**

**分析**：
- verifier 报 `FENTRY/FEXIT program can only be attached to another program annotated with BTF`
- REJIT 创建 tmp prog 时需要正确传递 `attach_btf_id` 和 `attach_prog_fd`，否则 verifier 拒绝
- 当前 REJIT syscall 可能没有正确传递 tracing 程序的 attach 上下文

**更深层问题**：即使 REJIT 成功，target-side trampoline 也不会刷新（见 #491 已知限制）。

**修复方向**：
- 短期：测试改为 REJIT **fentry 程序自身**（而非 target），需要正确传 attach_btf_id
- 长期：内核补 target-side trampoline refresh

### 4. LSM: `timed out (total_delta=0 event_delta=0)`

**类别**：测试代码 bug 或 LSM hook 未触发

**分析**：counter 始终为 0，说明 LSM 程序从未被执行。可能原因：
1. `SEC("lsm/file_open")` 在当前内核中未启用（需要 `CONFIG_BPF_LSM` + LSM boot param `lsm=bpf,...`）
2. attach 成功但 hook 不在当前 LSM 调用链中
3. open() 调用没走到 BPF LSM hook

**修复方向**：检查内核 config 和 `/sys/kernel/security/lsm`，确认 BPF LSM 已启用。如果未启用，在 defconfig 中加上。

### 5. XDP: `timed out (total_delta=8 event_delta=8 但期望变化)`

**类别**：测试代码 bug

**分析**：counter 在增长（total_delta=8, event_delta=8），说明 XDP 程序在执行。但增量始终是 1，REJIT 后没变成 2。可能原因：
1. REJIT patch 逻辑和 kprobe 一样有 pattern 匹配问题
2. REJIT 返回成功但实际 bytecode 没变（identity transform）
3. veth 路径下 XDP 执行可能走不同的 bpf_func 指针

**修复方向**：先确认 REJIT syscall 返回值，再检查 patch 后的 bytecode 是否真的改变了 delta 值。

## 共性问题

5 个失败中有 2 个（kprobe + XDP）是 **patch pattern 匹配** 问题，说明当前的 "扫描 orig_insns 找 MOV_IMM 指令并替换 imm 值" 方案在 clang 不同优化下不够鲁棒。

**建议改为更可靠的 REJIT 方式**：
1. 在 .bpf.c 中定义两个版本的程序（delta=1 和 delta=2）
2. REJIT 时直接提交第二个版本的完整 bytecode
3. 或用 .rodata map 存储 delta 值，通过 map_update 改变行为（但这不测试 REJIT）

## 优先级

1. kprobe + XDP（共性 patch pattern 问题，修一个方案可复用）
2. perf_event（VM 环境配置问题）
3. LSM（内核 config 问题）
4. fentry（真实内核限制，需要内核改动）
