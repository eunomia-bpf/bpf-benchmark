# Daemon exit 256 根因分析报告

**日期**: 2026-03-22
**问题**: VM micro benchmark (#338) 中，5 个程序对 daemon apply 返回 `exit code 256`
**受影响程序**: cmov_select, bounds_check_heavy, bpf_call_chain, local_call_fanout, packet_redundant_bounds

---

## 1. exit 256 的含义

Runner (`micro_exec`) 通过 `std::system(cmd)` 调用 daemon。`std::system()` 返回的是 `waitpid()` 的原始 `wstatus`，而非 shell exit code。当子进程以 exit code 1 退出时，`wstatus = 0x0100 = 256`。

因此：**daemon exit 256 = daemon 进程以 exit code 1 退出**。

Rust 程序中，`fn main() -> Result<()>` 返回 `Err(...)` 时，Rust 运行时会打印错误到 stderr 并以 exit code 1 退出。即 **daemon 内部发生了 `anyhow::Error` propagation 到 main()**。

错误路径：
```
cmd_apply(prog_id) → bpf_prog_rejit(fd, &program.insns, &[]) → Err("BPF_PROG_REJIT: EINVAL/EOPNOTSUPP") → main() 返回 Err → exit code 1 → std::system() 返回 256
```

---

## 2. apply 流程分析

`cmd_apply()` 的逻辑（`daemon/src/main.rs` 第 187-242 行）：

1. 读取 `orig_prog_insns`（原始字节码的平铺序列）
2. 调用 `passes::build_default_pipeline()` 运行 PassManager
3. 如果 `!pipeline_result.program_changed` → 直接 `return Ok(())` (exit 0，无错误)
4. 如果 program_changed → 调用 `bpf_prog_rejit(fd, &program.insns, &[])` → **这里可能失败**

`build_default_pipeline()` 包含的 pass（`daemon/src/passes.rs` 第 967-983 行）：
- `WideMemPass` — 将 byte-load+shift+OR 序列替换为单个 wide load
- `RotatePass` — 需要 `rotate64_btf_id > 0`（test_default 中为 -1），**不会触发**
- `CondSelectPass` — 仅检测，`changed: false`，**不会触发**
- `BranchFlipPass` — 需要 PGO branch profile 数据，test_default 无数据，**不会触发**

结论：**唯一可能改变程序的是 WideMemPass**。

---

## 3. WideMemPass 是否会触发？

`micro/programs/common.h` 定义的 `micro_read_u32_le` 和 `micro_read_u64_le` 是字节逐个加载并移位 OR 的函数：

```c
static __always_inline u32 micro_read_u32_le(const u8 *data, u32 offset) {
    return (u32)data[offset] | ((u32)data[offset + 1] << 8) |
           ((u32)data[offset + 2] << 16) | ((u32)data[offset + 3] << 24);
}
```

这完全匹配 WideMemPass 的 pattern（`LDX_B + LSH + OR` 序列）。所有使用 `micro_read_u32_le` / `micro_read_u64_le` 的程序都会触发 WideMemPass，产生 `program_changed = true`，进而执行 `bpf_prog_rejit`。

5 个程序均使用上述函数，因此 WideMemPass 在所有 5 个程序上都会触发。

---

## 4. 两类不同的根因

### 根因 A：多子程序（subprog）程序——BPF pseudo-call 偏移未修正

**受影响程序**: cmov_select, bpf_call_chain, local_call_fanout

这 3 个程序使用 `__noinline` 定义了 BPF-to-BPF 子程序：
- `cmov_select`: `cmov_select_pick()` (1 个 noinline subprog)
- `bpf_call_chain`: `sub_hash()`, `sub_fold()`, `sub_combine()` (3 个 noinline subprogs)
- `local_call_fanout`: `local_call_linear()`, `local_call_pressure()`, `local_call_crossload()`, `local_call_bytes()` (4 个 noinline subprogs)

**内核行为**：`orig_prog_insns` 返回的是所有 subprog 指令的平铺序列（主程序 + 所有子程序）。BPF-to-BPF 调用用 `BPF_CALL` 指令（`src_reg=1`）表示，偏移量存储在 `imm` 字段（相对于下一条指令的 insn 偏移）。

**rewriter 的 bug**：`rewriter.rs` 中的 `fixup_branches()` 函数（第 114-162 行）只修正 `is_jmp_class() && !is_call() && !is_exit()` 的分支，即：
```rust
if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
```

BPF pseudo-call（`code = BPF_JMP | BPF_CALL, src_reg = 1`）的 `imm` 字段存储相对指令偏移，`fixup_branches` 因为 `is_call()` 返回 true 而**跳过了对 pseudo-call imm 的修正**。

WideMemPass 将某些位置的 10 条指令替换为 1 条（缩短 9 条），导致 addr_map 发生变化。所有后续的 pseudo-call `imm` 偏移都指向错误位置。送入 `bpf_prog_rejit` 的字节码通不过 BPF verifier → **EINVAL**。

**内核侧验证**：`vendor/linux-framework/kernel/bpf/syscall.c` 第 3177-3194 行 `bpf_prog_rejit_subprog_layout_match()` 还要求新旧程序的 `real_func_cnt` 相同，且每个子程序的指令数相同（`func[i]->len`）。WideMemPass 改变了总指令数和各 subprog 的长度，因此即使 verifier 通过（它不会通过），这个检查也会返回 `false` → `EOPNOTSUPP`。

### 根因 B：单子程序程序——修正后字节码被 verifier 拒绝

**受影响程序**: bounds_check_heavy, packet_redundant_bounds

这 2 个程序是纯单函数 XDP 程序（所有辅助函数均为 `__always_inline`），不涉及 pseudo-call 偏移问题。

**问题**：WideMemPass 的 `fixup_branches` 将所有 `jmp_class && !call && !exit` 指令的 `off` 字段重算，包括 `JMP32` 类条件跳转（bounds_check_heavy 有大量由 bounds check + switch 产生的 JMP32 指令）。

当 WideMemPass 替换位于控制流中的 wide-mem site（例如 `bounds_check_heavy` 中循环体内的 `micro_read_u32_le` 调用），发生以下情况：

1. 指令总数减少，`addr_map[old_pc] → new_pc` 正确构建
2. `fixup_branches` 遍历 **old_insns**，找到 jmp 指令，计算 `old_target`，查 `addr_map[old_target]` 得 `new_target`，写入 `new_insns[new_pc].off`
3. 但是：**`new_insns[new_pc]` 是已经复制的旧指令**，写入 `off` 是正确的

这里存在一个更微妙的问题：`fixup_branches` 中仅检查 `new_insns[new_pc].is_jmp_class()` 才写入 off（第 147 行）。如果原始位置的 jmp 指令被替换（例如它在一个 wide-mem site 内部），那么 `new_pc` 处可能是 wide load 指令，而不是 jmp，导致该分支的 off 完全没有被修正。

不过，WideMemPass 的 site 过滤会跳过"interior branch target"的 site（第 48-61 行），以避免分支进入 site 内部。但 **site 起始指令自身可能是分支目标**，而 site 起始指令是 LDX_B，它会被保留为新的 wide load 的起点——这是安全的。

实际上，对于 `bounds_check_heavy` 和 `packet_redundant_bounds`，最可能的失败原因是：**BPF verifier 对 REJIT 的语义检查更严格**，WideMemPass 生成的代码（特别是寄存器使用方式）在某些情况下不满足 verifier 的约束。例如，wide load 目标寄存器与 verifier 跟踪的类型信息不符，或者 verifier 的 scalar range tracking 在修改后的代码路径上失败。

另一个可能：`packet_redundant_bounds` 使用 packet-backed XDP，verifier 对 packet pointer 的 range check 比 staged XDP 更严格。WideMemPass 生成的 `LDX_MEM W/H/DW` 宽加载指令中，verifier 需要重新 track 该寄存器的 packet boundary 约束，可能与后续 bounds check 的 range 不兼容。

---

## 5. 关键代码位置

| 文件 | 行号 | 说明 |
|------|------|------|
| `daemon/src/main.rs` | 187-242 | `cmd_apply()` 主流程 |
| `daemon/src/passes.rs` | 967-983 | `build_default_pipeline()` |
| `daemon/src/passes.rs` | 33-106 | `WideMemPass::run()` |
| `daemon/src/rewriter.rs` | 109-162 | `fixup_branches()` — 不修正 pseudo-call imm |
| `daemon/src/bpf.rs` | 269-294 | `bpf_prog_rejit()` — 失败路径 |
| `runner/src/kernel_runner.cpp` | 1472-1494 | daemon 调用与 exit code 处理 |
| `vendor/linux-framework/kernel/bpf/syscall.c` | 3177-3194 | `bpf_prog_rejit_subprog_layout_match()` |

---

## 6. 修复建议

### 修复 A（多 subprog 程序）——两种方案：

**方案 A1（保守）**: 在 WideMemPass（及其他改变指令数的 pass）中，检测程序是否包含 BPF pseudo-calls（`src_reg == 1`），若有则跳过整个 pass 或只在单个 subprog 范围内操作：

```rust
// 在 WideMemPass::run() 开头检测
let has_pseudo_calls = program.insns.iter().any(|i| {
    i.is_call() && i.src_reg() == 1
});
if has_pseudo_calls {
    return Ok(PassResult { changed: false, ... });
}
```

**方案 A2（完整）**: 在 `fixup_branches` 中，对 BPF pseudo-call（`src_reg == 1`）的 `imm` 偏移也进行修正：

```rust
if insn.is_call() && insn.src_reg() == 1 {
    // pseudo-call: imm is pc-relative insn offset
    let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
    let new_target = addr_map[old_target];
    let new_pc = addr_map[old_pc];
    if new_pc < new_insns.len() {
        let new_imm = new_target as i64 - (new_pc as i64 + 1);
        new_insns[new_pc].imm = new_imm as i32;
    }
}
```

并且，还需要保证每个 subprog 内部的 WideMemPass 结果不改变该 subprog 的总指令数（否则 `bpf_prog_rejit_subprog_layout_match` 拒绝）。这意味着 pass 需要感知 subprog 边界，只在 insn 数不变的情况下（或者内核放宽 subprog layout match 检查后）才能对多 subprog 程序操作。

**最简修复**：方案 A1，即当程序含 pseudo-calls 时直接跳过 WideMemPass。

### 修复 B（单 subprog 程序，verifier 拒绝）：

需要更多调试信息才能确定具体原因。建议在 daemon 中启用 REJIT log 输出（`log_level > 0`），以获取 verifier 的具体错误。

临时缓解：为 `bounds_check_heavy` 和 `packet_redundant_bounds` 添加 debug 输出，确认 WideMemPass 具体在哪些 PC 触发了替换，然后手动检查生成的字节码是否满足 verifier 约束。

---

## 7. 影响范围

### 对权威 benchmark 的影响

**权威结果（2026-03-14）来自 commit 前，使用的是旧的 scanner/rewriter 路径**，而非新的 pass framework（pass framework 在 2026-03-19 之后才加入）。因此：

- **已发布的权威结果不受影响**：权威结果中的 `kernel-rejit` 是用旧的 daemon（v1 rewriter 路径）跑出的，不涉及 pass framework
- **当前 (#338) benchmark 受影响**：这 5 个程序在 kernel-rejit runtime 下，daemon 返回 exit 256，`rejit.applied = false`，实际上 benchmark 仍以 **stock kernel JIT** 运行（未应用任何优化），但被错误地标记为 `kernel-rejit` runtime

**具体影响**：
1. `cmov_select`, `bpf_call_chain`, `local_call_fanout` — 有 subprog，daemon 理应跳过（这些程序不应出现在 kernel-rejit applied 列表中），但 daemon 应该优雅返回 `Ok(())`（no transforms）而不是 `Err`
2. `bounds_check_heavy`, `packet_redundant_bounds` — WideMemPass 触发但 REJIT 失败，这是真实的 bug

### 5 个程序在过去是否属于 "applied" 程序

根据 memory 中的权威结果，applied 集合有 16 个程序，cmov_select 的 policy 文件显示 `sites: []`（已清空），bpf_call_chain 有 2 个 WIDE sites。如果这 5 个程序之前是用旧 daemon 成功 applied 的，说明旧的 rewriter 对这些情况处理更好，或者 v2 pass framework 引入了新的 regression。

---

## 8. 总结

| 程序 | 根因 | 类型 |
|------|------|------|
| cmov_select | 含 `__noinline` subprog；WideMemPass 改变指令数后，pseudo-call imm 未修正；`bpf_prog_rejit_subprog_layout_match` 也拒绝 | 根因 A |
| bpf_call_chain | 同上（3 个 subprogs） | 根因 A |
| local_call_fanout | 同上（4 个 subprogs） | 根因 A |
| bounds_check_heavy | WideMemPass 触发，修改后字节码被 verifier 拒绝（具体原因需 REJIT log 确认） | 根因 B |
| packet_redundant_bounds | WideMemPass 触发，packet pointer 约束可能导致 verifier 拒绝 | 根因 B |

**最小修复**：在 WideMemPass 开头检测 pseudo-calls，有则跳过整个 pass（修复 A）；对 B 类，开启 REJIT log 定位 verifier 具体报错后再修。
