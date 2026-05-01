# v2-Style Rollback Implementation Plan

## Background

7 轮 vm-corpus 修复 + 8/9 轮 pivot 后调试暴露：daemon 内 dry-run + GET_ORIGINAL replay 协议占了 ~50% 的 bug source（multi-map relocation, BTF line_info offset, replay context 不全, timeout ramp, verifier-states-out 协议）。

参考报告：
- `docs/tmp/full-matrix-20260430/v2-style-rollback-review.md`（量化分析）
- `docs/tmp/full-matrix-20260430/v2-vs-v3-bug-attribution.md`（bug 归因）
- `docs/tmp/full-matrix-20260430/v3-pivot-review.md`（pivot 后 review）

结论：**保留 v3 已经做对的（bpfopt/bpfprof CLI + kernel-sys boundary），删 v3 引入的 replay protocol 复杂度**。

## Implementation Status

2026-05-01 已按本计划实施 v2-style rollback：

- daemon 主路径切成 snapshot → `bpfopt` CLI → direct `kernel_sys::prog_rejit()`，不再做 final `BPF_PROG_LOAD` dry-run。
- `daemon/crates/bpfverify` 和 `daemon/crates/bpfrejit` 已删除；`bpfget` 压缩为 live snapshot / map metadata / target probing。
- 2026-05-01 revision 推翻原 plan §B.3：恢复 v2 行为，默认 12-pass pipeline 包含 `const_prop`，daemon 自动为 `map_inline` / `const_prop` 等需要 side-input 的 pass 准备数据，且 thin dry-run 不传 BTF func_info/line_info。
- `map_fds.json` / `fd_array.json` / `btf-info` / `verifier-states-out` / replay 协议已从 daemon 主路径删除。
- 实际测试和行数见 `docs/tmp/full-matrix-20260430/v2-style-rollback-impl.md`。

## 不是 revert v2 daemon

- ❌ 不带回 v2 daemon 内嵌 `PassManager` / pass 代码
- ❌ 不带回 v2 daemon 内置 profiler
- ❌ 不带回 v2 一体化 syscall 调用（仍走 kernel-sys）

## 保留的部分（v3 对的）

- `bpfopt` CLI（pure bytecode transformer，零 kernel dep，stdin/stdout binary `bpf_insn[]`）
- `bpfprof` CLI（PMU profiling，独立工具）
- `kernel-sys`（唯一 syscall boundary）
- daemon socket 协议（runner Python 边界不动）
- daemon watch + invalidation（仍需要监听 prog/map 变化）
- 8 个 supported apps + 22 macro corpus cases
- 12 个 bpfopt passes（const_prop 行为变化见下）
- 所有 corpus / e2e / micro Python framework

## 删除的部分（v3 引入的不必要复杂度）

- `daemon/crates/bpfverify` 整个 lib（1,369 行）
- `daemon/crates/bpfget` 内的 BTF normalization / multi-map relocation reconstruction / verifier-states-out 协议（保留 ~250-450 行做 snapshot + thin fd_array builder）
- `daemon/src/commands.rs` 内的 verifier-states.json 协议、BTF side-files 写读、final dry-run + replay 编排（2,148 → ~700-1000 行）
- `daemon/crates/bpfrejit` 整个 crate（77 行内联到 daemon/src 几十行）
- ProgramSnapshot 的 BTF func_info/line_info normalization fields
- 5s/30s/60s timeout ramp（替换成单一 5s 兜底）
- map_fds.json / fd_array.json / btf-info / replay_bpfverify_report 任何残留

## B 方案三条设计原则

设计 B 方案的 dry-run（给需要 verifier states 的 pass 用）必须遵守：

1. **零 reconstruction** — 所有字段直接从 `prog_info` 读，不变形不规范化。`prog_type / expected_attach_type / prog_flags / btf_id / btf_obj_id / attach_btf_id / dst_prog_fd` 全部 read-as-is 填到 `bpf_attr`。
2. **不传 BTF func_info / line_info** — `bpf_attr.line_info_cnt = 0`、`bpf_attr.func_info_cnt = 0`。verifier 不需要 source-level metadata 来跑 verify + 输出 register state log。
3. **默认 12-pass + 自动 side-input** — daemon 默认启用 v2 时代 12 个 pass：`wide_mem, rotate, cond_select, extract, endian_fusion, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch`。调用方不需要 side-input opt-in；daemon 看到 `map_inline` 自动生成 live map values 和 verifier states，看到 `const_prop` 自动生成 verifier states，看到 kinsn pass 自动 probe target / 构造 fd_array。`branch_flip` 仍不在默认 12 pass 中。

## 新主路径

```
runner Python ─[socket optimize]→ daemon
                                    │
                                    ├─ snapshot bytecode (kernel-sys::prog_get_original)
                                    ├─ build fd_array from prog_info.used_maps[] (几行)
                                    ├─ fork+exec: bpfopt optimize (stdin bytecode → stdout bytecode)
                                    └─ kernel-sys::prog_rejit(prog_fd, optimized, fd_array)
                                       └─ kernel REJIT 内部走完整 verifier path
                                          失败 → errno 22 + log_buf
```

错误处理：
- bpfopt subprocess 失败 → daemon 报 transform error
- REJIT syscall 失败 → daemon 解析 errno + log_buf 写 preserved workdir（含 original bytecode + optimized bytecode + verifier_log），返回 result.json
- 单个 prog REJIT 失败**不影响其它 prog**（per-app lifecycle 已修，保留）
- main `BPF_PROG_REJIT` 无 daemon-side timeout；如果 kernel verifier hang，daemon 会同步卡住。当前选择文档化接受该限制，不加 subprocess fallback。

## 自动 side-input 机制

```
默认/显式调用：enabled_passes 含 map_inline 或 const_prop
         daemon 检测到 verifier-state consumer → 在调 bpfopt 前先做一次 thin dry-run
         dry-run 用 BPF_PROG_LOAD 喂原 bytecode + minimal LoadAttr (no BTF info)
         → 拿 verifier_log → parse register state → 写 states.json
         → 然后 bpfopt 用 states.json 跑 map_inline / const_prop
```

thin dry-run 函数（约 200-300 行）：
```rust
fn capture_verifier_states(prog_info: &ProgInfo, bytecode: &[Insn], fd_array: &[OwnedFd])
  -> Result<VerifierStatesJson> {
    let attr = bpf_attr {
        prog_type: prog_info.prog_type,
        expected_attach_type: prog_info.expected_attach_type,
        prog_flags: prog_info.prog_flags,
        btf_id: prog_info.btf_id,
        btf_obj_id: prog_info.btf_obj_id,
        attach_btf_id: prog_info.attach_btf_id,
        dst_prog_fd: prog_info.dst_prog_fd,
        insns: bytecode.as_ptr(),
        insn_cnt: bytecode.len(),
        log_level: BPF_LOG_VERBOSE | BPF_LOG_REGS,
        log_buf, log_size,
        fd_array: fd_array.as_ptr(),
        fd_array_cnt: fd_array.len(),
        // line_info_cnt = 0, func_info_cnt = 0  ← 关键
    };
    let result = kernel_sys::bpf_syscall(BPF_PROG_LOAD, attr, 5_seconds_timeout);
    parse_register_states(log_buf)
}
```

不要写 BTF normalize、不要 reverse PSEUDO immediate、不要 map_fds.json 协议。

## 量化预期

| 模块 | 当前行数 | B 方案后 | 净减少 |
|---|---:|---:|---:|
| `daemon/crates/bpfverify` | 1,369 | 0（删整个 crate） | -1,369 |
| `daemon/crates/bpfget` | 1,851 | 250-450 | -1,400 |
| `daemon/src/commands.rs` | 2,148 | 700-1,000 | -1,150 |
| `daemon/crates/bpfrejit` | 77 | 0（内联到 daemon/src） | -77 |
| 残留协议代码（map_fds 序列化等） | scattered | 0 | -200 |
| 加：thin dry-run 模块（verifier-state side-input 用） | 0 | 200-300 | +250 |
| 加：minimal fd_array builder | 0 | 30-50 | +40 |
| **净** | **6,756 daemon kernel-facing** | **~2,300** | **~-4,200 行** |

预期 daemon 体积下降 **65-70%**。

## 实施步骤

按依赖顺序：

### Step 1: 切 daemon 主路径（删 dry-run 主依赖）
- `daemon/src/commands.rs::optimize_prog`：从「snapshot → bpfopt → bpfverify dry-run → bpfrejit」改成「snapshot → bpfopt → REJIT」
- 移除 final verify 调用、verifier-states-out 调用、replay_bpfverify_report 处理
- 错误处理改成 `kernel_sys::prog_rejit` 直接返 errno + log_buf
- 估计 commands.rs `-1,000` 行

### Step 2: 删 bpfverify lib
- `rm -rf daemon/crates/bpfverify`
- 从 `daemon/Cargo.toml` workspace 移除
- 删 `daemon/src/commands.rs` 内 `use bpfverify::*` 残留 import
- 估计 `-1,369` 行

### Step 3: 压缩 bpfget
- 保留：`prog_get_original` snapshot、`prog_info` 字段读取、`map_id → fd_array` builder、kinsn target probing
- 删：`normalize_func_info_for_insns`、`normalize_line_info_for_insns`、`relocate_for_load`、resolved kernel pointer rewrite、ProgramSnapshot 的 BTF metadata fields
- 不再需要 `OwnedFd` 长期持有（map fd 只在 dry-run / REJIT 调用时短期持有）
- 估计 `-1,400` 行

### Step 4: 内联 bpfrejit 到 daemon/src
- `rm -rf daemon/crates/bpfrejit`
- daemon/src/commands.rs 直接调 `kernel_sys::prog_rejit`
- 估计 `-77 + 30 = -47` 行

### Step 5: 加 thin dry-run（自动 verifier-state side-input）
- 新文件 `daemon/src/dry_run.rs` 或加到 `commands.rs`
- 严格按"三条原则"实现（200-300 行）
- 加 unit test 覆盖：
  - dry-run 接受合法 bytecode（一个简单 fixture）
  - dry-run 拒绝非法 bytecode（errno 22）
  - dry-run timeout 5s 兜底
  - 不传 line_info/func_info 不影响 register state 解析

### Step 6: daemon side-input 集成
- daemon 检测 `enabled_passes` 含 `map_inline` / `const_prop` → 触发 dry-run 写 states.json → 传给 bpfopt CLI
- daemon 检测 `enabled_passes` 含 `map_inline` → 写 live `map-values.json` 和 `--map-ids`
- daemon 检测 kinsn pass → probe `target.json` 并构造 fd_array call offsets
- 加 integration test：包含 `const_prop` 的默认 12-pass 语义会触发 dry-run

### Step 7: 删除残留协议代码
- `bpfopt/crates/kernel-sys/src/lib.rs`：删 `FdArray::from_json_file`（review P2#5 提到，dead code）
- 删任何 `map_fds.json` / `fd_array.json` / `verifier-states-out` 字符串残留
- 删 `daemon/src/commands.rs` 内的 verifier watchdog（fca13a39 加的，dry-run 不再是主路径就不需要复杂 watchdog；保留单一 5s timeout）

### Step 8: 文档更新
更新以下文档：
- `CLAUDE.md` § "Daemon Owns Kernel Calls; Runner Stays Untouched"：改成「daemon 主路径直接 ReJIT；需要 side-input 的 pass 自动准备数据」
- `docs/tmp/bpfopt_design_v3.md`：把 v3 daemon-owned bpfverify lib 段全删；写新主路径 + 自动 side-input 机制
- `docs/kernel-jit-optimization-plan.md` § 4 architecture：同步
- `daemon/README.md`：更新 socket 协议描述

### Step 9: 测试
- `cargo test --workspace --manifest-path daemon/Cargo.toml`
- `cargo test --workspace --manifest-path bpfopt/Cargo.toml`
- `make daemon-tests`
- `make check`（含 vm-test selftest + fuzz 1000 rounds）
- 新增覆盖：
  - 主路径 ReJIT errno 报错被正确转成 result.json
  - const_prop 默认路径 dry-run 触发 + states.json 生成 + bpfopt 接收
  - thin dry-run 5s timeout
  - 多 map prog REJIT 主路径成功（不需要 reconstruction）
- 报告每个 test pass/fail

### Step 10: 写交付报告 + commit
- 报告路径：`docs/tmp/full-matrix-20260430/v2-style-rollback-impl.md`
  - 实际删除/新增行数（量化）vs 预期 ~4,200 行
  - 每个 commit 的覆盖范围
  - 新主路径示意
  - 测试结果
  - 给 Claude 的 vm-corpus 验证提示
- git add 全部改动 + 报告
- git commit 直接到 main（不开分支，按 memory）
- 不要 push（除非用户授权）
- **退出**——不要跑 make vm-corpus / vm-e2e / vm-micro

## 不要做的事（防止走偏）

- ❌ 不要回 v2 daemon 嵌入 PassManager
- ❌ 不要把 bpfopt 改成 lib（永远是 CLI）
- ❌ 不要改 BPF_PROG_REJIT syscall ABI（kernel 不动）
- ❌ 不要重建 BTF func_info/line_info normalize 逻辑（即使看着像 bug 兜底也别加回去）
- ❌ 不要重建 multi-map relocation 反向解析（fd_array 直接从 used_maps 来）
- ❌ 不要在 final ReJIT 接受路径留任何 dry-run；thin dry-run 只允许作为需要 verifier states 的 pass 的 side-input 生成步骤
- ❌ 不要跑 make vm-corpus / vm-e2e / vm-micro（让 Claude 跑）
- ❌ 不要分多个 commit（一个干净的 commit 含完整 rollback；docs/report 可以是单独 commit）

## 验收标准

- 量化：daemon kernel-facing Rust 行数从 6,756 减至 ≤ 2,400（净减 ≥ 4,300）
- cargo test --workspace、make daemon-tests、make check 全过（vm-test selftest 仍 27 passed）
- daemon final ReJIT 接受路径不调用 BPF_PROG_LOAD；只有需要 verifier states 的 pass 才触发 side-input thin dry-run
- daemon 不再写 / 读 map_fds.json / verifier-states-out / btf-info 任何 JSON
- ProgramSnapshot 不含 BTF func_info/line_info bytes
- 删完 docs 跟实现一致（CLAUDE.md/bpfopt_design_v3.md/plan doc）

## 后续验证（Claude 跑）

实施完成后 Claude 跑 `make vm-corpus` round 10 验证：
- 期望 round 9 留下的 6 类 ReJIT bug 全部消失（multi-map relocation, BTF line_info, replay context, timeout ramp, line_info Invalid offset, kernel pointer immediate）
- 期望 workload bug 仍存在（HTTP/1.1, timerfd, open stressor —— 这些跟 daemon 架构无关）
- 期望 corpus 达到 8/8 app `rejit_done ok`（除 calico/cilium baseline 仍 EADDRNOTAVAIL 类 workload bug 待另修）
