# Crash Path Trace: 从 daemon apply-all 到 QEMU segfault

**日期**: 2026-03-25
**分析方法**: 从 bug 复现报告逆向追踪，对照 dump 和源码精确定位

---

## 总结：两个独立的 bug，容易混淆

本报告确认复现报告中存在**两个独立 bug**，以及它们之间被错误关联的过程：

| Bug | 症状 | Root Cause | 严重性 |
|-----|------|------------|--------|
| Bug A | REJIT verifier 拒绝 (多个 scx/tracee 程序) | daemon `const_prop` pass 丢弃 map-value 指针类型 | P1 (correctness) |
| Bug B | QEMU TCG segfault at `tlb_set_dirty` | `probe_bpftool_register()` + 第二次 `scx_rusty` load 后，`bpftool prog show` 触发内核 `prog->stats == NULL` 解引用 + 残余竞态 | P0 (host crash) |

**关键发现**：Bug A 和 Bug B 不是同一条路径。Bug A 的 REJIT 恶意字节码被 verifier 正确拒绝，不会导致 QEMU crash。Bug B 完全不需要 REJIT — 它在纯 struct_ops probe + 枚举路径就能触发。

---

## Bug A：REJIT Correctness — `const_prop` 丢弃 map-value 指针类型

### 完整调用链

```
daemon apply <prog_id>
  -> enumerate: 读取 xlated bytecode（已含内核地址）
  -> const_prop pass:
     1. analyze_instruction() 看到 pc 4: LD_IMM64(r1, src=2, map_id=0x11, off=0x1a8)
        -> decode_ldimm64() 读取 lo=0x11, hi=0x1a8 -> value = 0x1a800000011
        ⚠️ 错误：这是 xlated 前的 map_id/offset，不是实际的内核地址
        但在某些 daemon 版本中，daemon 先做了地址解析，此时 value 已是内核地址
     2. analyze_instruction() 看到 pc 6: ALU64_ADD r1, 16
        -> evaluate_alu_result() 计算 value + 16
        -> fold_alu_instruction() 决定替换
     3. emit_constant_load(r1, computed_value)
        -> emit_ldimm64(r1, computed_value)
        -> 生成: LD_IMM64(r1, src=0, imm_lo=..., imm_hi=...)
                                    ^^^^
                                    关键：src=0 是 plain scalar！
  -> 最终 bytecode: r1 从 map_value 变成 plain scalar
  -> BPF_PROG_REJIT syscall
  -> kernel verifier 拒绝: "R1 type=scalar expected=fp, pkt, map_value, ..."
  -> daemon 报告 "BPF_PROG_REJIT: Permission denied (os error 13)"
```

### Root Cause 精确位置

**文件**: `daemon/src/passes/const_prop.rs`
**函数**: `emit_ldimm64()` (第 456-471 行)
**核心问题**: 第 460 行 `regs: BpfInsn::make_regs(dst_reg, 0)` — `src=0`

```rust
fn emit_ldimm64(dst_reg: u8, value: u64) -> Vec<BpfInsn> {
    vec![
        BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(dst_reg, 0),  // <-- src=0: plain scalar
            off: 0,
            imm: value as u32 as i32,
        },
        // ...
    ]
}
```

原始指令是 `LD_IMM64(r1, src=2, ...)` 其中 `src=2` = `BPF_PSEUDO_MAP_IDX_VALUE`，
表示"这是一个 map value 的指针"。`const_prop` 把 `r1 = map_value_ptr; r1 += offset`
折叠成一个新的 `LD_IMM64(r1, src=0, computed_value)` — 类型信息丢失。

**更上层的问题**: `const_prop` 的 `analyze_instruction()` (第 193-235 行) 在处理 `BPF_LD` 类指令时，
只保存了数值 (`decode_ldimm64()`，第 203-209 行)，**完全不区分 typed (src!=0) 和 plain (src=0)
的 LD_IMM64**。`RegConstState` 是 `[Option<u64>; 11]`，只存数值不存类型。

### 受影响程序

| 程序 | Verifier 错误 | 根因 |
|------|---------------|------|
| `rusty_exit` (prog 20) | `R1 type=scalar` | `const_prop` 折叠 map_value + offset |
| `rusty_init_task` (prog 17) | `R2 invalid mem access 'scalar'` | 同上 |
| `rusty_exit_task` (prog 18) | `R2 invalid mem access 'scalar'` | 同上 |
| `rusty_init` (prog 19) | `R2 invalid mem access 'scalar'` | 同上 |

### Bytecode 差异对比 (`rusty_exit`)

**原始 xlated (kernel 解析后)**:
```
pc 4-5: 18 21 00 00 11 00 00 00 | 00 00 00 00 a8 01 00 00
         LD_IMM64 r1, src=2(map_value), map_id=0x11, off=0x1a8
pc 6:   07 01 00 00 10 00 00 00
         r1 += 16
```
Verifier 知道: `r1 = map_value(map=bpf_bpf.data, off=424)`, 然后 `r1 += 16` 得
`r1 = map_value(off=440)` — 合法。

**const_prop 改写后**:
```
pc 4-5: 18 21 00 00 11 00 00 00 | 00 00 00 00 a8 01 00 00
         LD_IMM64 r1, src=2, map_id=0x11, off=0x1a8  (保留)
pc 6-7: 18 01 00 00 21 00 00 00 | 00 00 00 00 a8 01 00 00
         LD_IMM64 r1, src=0(!), value=0x1a800000021  (新生成，覆盖 r1)
```
Verifier 看到: pc 4 `r1 = map_value`，然后 pc 6 `r1 = 0x1a800000021` (scalar) — `r1`
变成 scalar，后续 `call bpf_probe_read_kernel_str` 在 insn 9 拒绝。

### 为什么 replay 正确拒绝？

replay (`scx_bad20_replay/`) 使用相同的 malformed bytecode 直接提交 `BPF_PROG_REJIT`，
verifier 同样在 insn 9 拒绝 (`R1 type=scalar`)。replay 和 live 场景的 verifier 行为
**完全一致** — 两者都正确拒绝了。

误导来自：最早的 crash 报告将"prog 20 REJIT 失败"和"QEMU crash"时间上关联了，
但实际上 REJIT 的 verifier 拒绝是 safe failure，QEMU crash 是独立的 Bug B。

### 为什么修复 daemon 后 crash 消失？

报告的 "Update After Rebuilding" (第 300-309 行) 说：重建 daemon 后 prog 20 从 `30->31`
变成 `30->29`，两个 bogus `LD_IMM64` scalar loads 消失，REJIT 成功。

这是因为不同 daemon 版本中 `const_prop` 的行为不同。重建后的 daemon（对应
`scx_rejit_workload_probe/apply-20.stderr`）的 `const_prop` 只 apply 了 1 site（折叠了
branch `16 01 02 00` → `ja +0`），没有折叠 `r1 += 16` 和 `r1 += 144`。这暗示
可能是 daemon 的 xlated bytecode 读取方式在不同版本间有差异（是否读取 kernel-resolved
addresses vs raw map_id/offset）。

---

## Bug B：QEMU TCG Crash — struct_ops 枚举路径的内核 null pointer + 竞态

### 完整调用链

```
1. probe_bpftool_register()                       [guest]
   -> bpftool struct_ops register scx_rusty.bpf.o
   -> kernel: bpf_struct_ops_map_update_elem()
   -> 创建第一组 struct_ops programs (ids: ~7-20)
   -> bpftool 退出，fd 关闭
   -> kernel: bpf_struct_ops_map_free()
     -> bpf_struct_ops_map_dissoc_progs()         # 解除 prog->st_ops_assoc
     -> bpf_struct_ops_map_del_ksyms()            # 删除 trampoline ksyms
     -> synchronize_rcu_mult()                     # 等待 RCU GP
     -> __bpf_struct_ops_map_free()               # 释放 trampoline image
       -> bpf_struct_ops_map_put_progs()          # bpf_link_put → prog refcount--

2. scx_rusty --stats 1                            [guest]
   -> 创建第二组 struct_ops programs (ids: ~37-50)
   -> sched_ext 变为 "enabled"

3. find_bpf_programs(pid) / bpftool prog show     [guest]
   -> 遍历 /proc/<pid>/fdinfo → 获取 owner prog IDs
   -> 对每个 prog_id 调用 bpf_prog_get_fd_by_id()
   -> 对每个 fd 调用 bpf_prog_get_info_by_fd()
     -> bpf_prog_get_stats(prog, &stats)          [kernel: syscall.c:5770]
       -> per_cpu_ptr(prog->stats, cpu)
       ⚠️ 如果 prog->stats == NULL → 空指针解引用
          → guest kernel oops
          → QEMU TCG: guest 试图访问非法内存
          → QEMU 在 tlb_set_dirty 中 segfault
          → host 记录 "qemu-system-x86[PID]: segfault at ... ip ... 0x8d8f21"

4. [如果 null-stats guard 已修复]
   -> bpf_prog_get_info_by_fd() 继续
   -> 访问 prog->aux->func[i]->jited_len          [kernel: syscall.c:5823]
   -> 访问 prog->aux->func[i]->bpf_func           [kernel: syscall.c:5842]
   ⚠️ 在 probe 注册/注销和第二次 load 之间的窗口：
      func[] 数组可能指向已释放的子程序
      → 同样触发 guest kernel oops → QEMU segfault
```

### Root Cause 精确位置

**已确认的 Bug B-1**: `bpf_prog_get_stats()` 空指针

- **文件**: `vendor/linux-framework/kernel/bpf/syscall.c:2460-2470`
- **函数**: `bpf_prog_get_stats()`
- **调用者**: `bpf_prog_get_info_by_fd()` (syscall.c:5770)
- **问题**: `per_cpu_ptr(prog->stats, cpu)` 没检查 `prog->stats == NULL`
- **状态**: 已修复（dirty tree 中加了 `if (unlikely(!prog->stats))` guard）

**残留的 Bug B-2**: `func[]` 数组竞态

- **文件**: `vendor/linux-framework/kernel/bpf/syscall.c:5823-5906`
- **函数**: `bpf_prog_get_info_by_fd()` 中多处 `prog->aux->func[i]` 访问
- **问题**: `bpf_prog_rejit_swap()` 通过 `swap(prog->aux->func, tmp->aux->func)` 替换 `func[]`，
  但 `bpf_prog_get_info_by_fd()` 不在 `rejit_mutex` 保护下，可能读到 swap 过程中的中间状态
- **触发条件**: probe 注册创建的 struct_ops 在 free 过程中，第二次 `scx_rusty` load 同时进行，
  `bpftool prog show` 在这个窗口查询 — timing-sensitive

### 为什么 `prog->stats == NULL` 对 struct_ops 程序？

在 `verifier.c:23198`，`jit_subprogs()` 对子程序使用 `bpf_prog_alloc_no_stats()` 分配，
这些子程序的 `prog->stats = NULL`（注释在 verifier.c:23193-23197 明确说了
"subprogs don't have IDs and not reachable via prog_get_next_id, func[i]->stats will
never be accessed and stays NULL"）。

但问题是：`bpf_prog_get_info_by_fd()` 在查询**主程序**时，会遍历
`prog->aux->func[i]` 数组。在正常情况下主程序有 `stats`，但如果
`bpf_prog_rejit_swap()` 交换了 `func[]` 数组，并且旧的 tmp 被 RCU 释放，
`func[i]` 指针可能变成 dangling。

另一个路径：struct_ops map free 时 `bpf_struct_ops_map_put_progs()` 调用
`bpf_link_put()` 减少程序 refcount，如果 refcount 归零，程序被释放。但如果
在释放完成前有另一个路径通过 `bpf_prog_get_fd_by_id()` 获取了 fd，就可能
读到一个正在释放中的程序。

### 触发条件的精确描述

复现报告通过系统化的 split 测试确认了以下关键条件：

1. **probe 单独不 crash** — struct_ops register + 注销本身是安全的
2. **scx_rusty 单独不 crash** — 第二次 load 本身也是安全的
3. **probe + scx_rusty + 重复 `bpftool prog show` → crash** — 关键组合
4. **fdinfo 扫描单独不 crash** — `/proc/<pid>/fdinfo` 读取是安全的
5. **单次 `bpftool prog show` 不 crash** — 需要重复调用
6. **重复 fdinfo 不 crash** — 只有重复 `bpftool prog show` 才 crash
7. **精确到 prog_id=42 (推测为 `rusty_running`)** — 单个 query 就够

这确认了竞态窗口：probe 创建的第一组程序在 free 过程中，第二组程序正在 load，
重复的 `bpf_prog_get_info_by_fd()` 调用在这个窗口捕获到处于不一致状态的程序。

### 为什么之前的 review 没发现

1. **Bug A** (`const_prop` pointer type loss): 之前的 review 只关注 map_inline pass
   和 branch fixup，没有审查 `const_prop` 对 typed LD_IMM64 的处理。`const_prop`
   的 `RegConstState` 设计从一开始就没有区分 "pointer constant" 和 "scalar constant"，
   这个架构缺陷只在 xlated bytecode 包含已解析的内核地址时暴露。

2. **Bug B** (`prog->stats` null deref + `func[]` 竞态):
   - `prog->stats == NULL` 的可能性在 upstream kernel 的 `bpf_prog_get_stats()` 注释中
     被明确排除（"subprogs don't have IDs and not reachable via prog_get_next_id"）。
     但 REJIT 的 `bpf_prog_rejit_swap()` 打破了这个不变量。
   - `func[]` 竞态需要 probe + 第二次 load + 枚举的精确 timing 才能触发，
     单纯的代码审查很难发现。
   - 之前的 kernel review 主要关注 REJIT swap 本身的正确性，没有关注
     "swap 改变了 `bpf_prog_get_info_by_fd()` 的并发安全假设"。

### 历史 bisect 证据

- **Good**: `909f6ef / 1d040ec0c` (2026-03-21) — 100 iterations 无 crash
- **Good**: `72051ac / e7d27ef37` (2026-03-21 later) — 100 iterations 无 crash
- **Bad**: 当前 HEAD (`2d3c5adb3`) — 反复 crash

这说明 Bug B 是在 `e7d27ef37..2d3c5adb3` 范围内引入的回归。最可能的 commit 是
引入 `bpf_struct_ops_refresh_prog()` 两阶段改写和 `st_ops_assoc` 机制的那些 commit。

---

## 回答关键问题：为什么 live 场景 crash 但 replay 不 crash？

**答案是假说 D 的变体，但需要更精确的拆分**：

这个问题本身基于一个错误的假设 — 即 "live 场景 crash" 和 "REJIT malformed code"
是同一条路径。实际上：

- **Bug A (REJIT malformed)**: live 和 replay **都被 verifier 正确拒绝**，两者行为一致。
  没有 verifier bypass。verifier log 在两种场景下是相同的。

- **Bug B (QEMU crash)**: **完全不需要 REJIT**。它只需要 `probe_bpftool_register()`
  + 第二次 `scx_rusty` load + `bpftool prog show` 枚举。replay harness
  (`scx_bad_rejit_replay.c`) 不执行这个枚举路径，所以不会触发 Bug B。

时间上的关联导致了混淆：在 e2e 测试中，`scx --smoke` 先 probe，再 load `scx_rusty`，
再 `find_bpf_programs()`（内部调用 `bpftool prog show`），再尝试 REJIT。crash 发生在
`find_bpf_programs()` 阶段（Bug B），但因为 e2e 流程中紧接着就会做 REJIT（触发 Bug A），
两者被错误地归因到同一个 root cause。

---

## 修复方案

### Bug A 修复 (daemon 侧)

**文件**: `daemon/src/passes/const_prop.rs`

1. **短期**: 在 `analyze_instruction()` 的 `BPF_LD` 分支中，如果 `insn.src_reg() != 0`
   （表示这是一个 typed LD_IMM64，如 map_value/map_fd/kfunc_btf），**不记录为已知常量**，
   直接 `set_reg_const(&mut next, insn.dst_reg(), None)`

2. **短期**: 在 `fold_alu_instruction()` 中，如果 dst_reg 的值来源于一个 typed LD_IMM64
   的 fold chain，不生成替换

3. **长期**: `RegConstState` 应扩展为 `[Option<(u64, bool)>; 11]`，其中 bool 标记
   "is_typed_pointer"，只有 scalar 常量才允许被折叠

### Bug B 修复 (kernel 侧)

1. **Bug B-1** (已在 dirty tree): `bpf_prog_get_stats()` 的 null guard — 保留

2. **Bug B-2**: 需要在 `bpf_prog_get_info_by_fd()` 中对所有 `prog->aux->func[i]` 访问
   添加 `READ_ONCE` + validity check，或者在 `rejit_mutex` 保护下访问

3. **更根本的**: 需要 git bisect `e7d27ef37..2d3c5adb3` 找到精确的回归 commit，
   然后决定是 revert 还是修复

### 优先级

- Bug B: **P0** — 导致 QEMU 进程 crash，可间接导致 host 重启
- Bug A: **P1** — 只是 correctness 失败，verifier 正确拒绝，不危及安全
