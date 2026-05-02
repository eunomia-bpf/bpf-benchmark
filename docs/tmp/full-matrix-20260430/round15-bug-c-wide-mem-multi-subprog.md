# Round 15 Bug C：wide_mem multi-subprog 边界修复

## 背景

calico/felix prog 102 在第一个 pass `wide_mem`、0 committed passes 时被 verifier 拒绝。失败日志显示程序含 `func#0 @0` 和 `func#1 @34`，并在主函数中通过 `LD_IMM64` callback 引用传给 `bpf_for_each_map_elem`。

## 结论

`wide_mem` 本身只合并 byte-load ladder 为单条宽 load，不会合并 `LD_IMM64 + STORE`，也不会改写 map fd/value/index 形式的 `LD_IMM64` immediate。现有 `fixup_all_branches` 已会重写 `BPF_PSEUDO_FUNC` 和 `BPF_PSEUDO_CALL` 的相对 offset。

实际缺口在 `BranchTargetAnalysis`：它只把 jump 和 `BPF_PSEUDO_CALL` 目标标成 branch target，漏掉了 `LD_IMM64 src_reg=BPF_PSEUDO_FUNC` callback subprog 入口。`wide_mem` 依赖该分析跳过含内部 branch target 的 byte-ladder；漏标后，byte-ladder 可能跨 callback subprog 入口被合并，导致函数边界被折叠到错误 PC。

## 修复

- `bpfopt/crates/bpfopt/src/analysis/branch_target.rs`
  - 将 `insn.is_ldimm64_pseudo_func()` 的目标 PC 标记为 `is_target[target] = true`。
  - 新增 `branch_target_pseudo_func_callback`，验证 callback subprog 入口会进入 branch target 集合。

- `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs`
  - 新增 `test_wide_mem_skips_byte_ladder_with_pseudo_func_boundary_inside`。
  - 构造 `BPF_PSEUDO_MAP_FD` map ref + `BPF_PSEUDO_FUNC` callback ref + byte-ladder，断言 `wide_mem` 因内部 subprog target 跳过该 site，并保持 map ref / callback imm 不变。

## 验证

- `cargo fmt --manifest-path bpfopt/crates/bpfopt/Cargo.toml --check`
- `cargo test --release --manifest-path bpfopt/Cargo.toml pseudo_func`
- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`

完整 release workspace 结果：405 tests passed（lib 353、bin/CLI/bpfprof/kernel-sys/integration 合计 52），0 failed。
