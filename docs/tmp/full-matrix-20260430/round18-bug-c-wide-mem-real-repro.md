# Round 18 Bug C：wide_mem calico/felix prog 102 真实复现

## 复现

preserved workdir：

`corpus/results/failures/102/`

复现命令：

```bash
cargo build --release --workspace --manifest-path bpfopt/Cargo.toml
cat corpus/results/failures/102/pass-00-wide_mem.in.bin \
  | ./bpfopt/target/release/bpfopt --pass wide_mem --prog-type sched_cls \
  > /tmp/wide_mem_102.out.bin
diff <(xxd /tmp/wide_mem_102.out.bin) \
     <(xxd corpus/results/failures/102/pass-00-wide_mem.out.bin)
```

`--prog-type sched_cls` 是 daemon 实际传给 `bpfopt` 的上下文。带该上下文时，新生成 output 与 preserved bad output 完全一致：183 条输入指令变成 171 条输出指令，`wide_mem` 应用 4 个 site。

## Bytecode 复核

真实 input/output 对比结果：

- `func#0 @0`、`func#1 @34`。
- `LD_IMM64 src_reg=BPF_PSEUDO_FUNC` 位于 pc 19。
- input：pc 19 `imm=14`，目标 `19 + 1 + 14 = 34`。
- output：pc 19 仍为 `imm=14`，目标仍是 34。
- 4 个 `wide_mem` 折叠点都在 func#1 内，未跨 func boundary。
- branch offsets 已随长度变化正确修正。
- map `LD_IMM64` 的 pseudo src_reg 未被 `wide_mem` 改写。

因此 758e90d1 修的 pseudo_func branch-target 方向不是这次失败的根因；当前 preserved case 里 bytecode 的 pseudo_func 目标没有被改坏。

## 根因

verifier 拒绝点是：

```text
19: (18) r2 = 0xe
missing btf func_info
```

vendor kernel 的 `BPF_PROG_REJIT` 临时程序只在 `BPF_PROG_TYPE_EXT` 时从原 live program 预填 `aux->btf` / `aux->func_info` / `aux->func_info_aux`。calico/felix `conntrack_clean` 是 `sched_cls`，但它通过 `BPF_PSEUDO_FUNC` 把 func#1 callback 传给 `bpf_for_each_map_elem`。REJIT attr 不重放 func_info，verifier 的 BTF setup 又因为 `func_info_cnt == 0` 提前返回，导致 `resolve_pseudo_ldimm64()` 处理 `BPF_PSEUDO_FUNC` 时看到 `aux->func_info == NULL` 并直接 EINVAL。

所以失败不是 `wide_mem` 把 callback offset 算错，而是 REJIT 没有为非 EXT 的 helper callback 程序继承原 program BTF func metadata。

## 修复

- `vendor/linux-framework/kernel/bpf/syscall.c`
  - `BPF_PROG_REJIT` 不再只为 EXT 复制 BTF func metadata。
  - 只要原程序有 `aux->btf`、`aux->func_info`、`aux->func_info_aux`、`func_info_cnt`，就复制到 tmp program。
  - `func_info_aux` 改为复制原 aux，而不是分配全 0 数组，保留 callback linkage / unreliable 标记。
  - verifier 成功后仍由 `adjust_btf_func()` 将 `func_info.insn_off` 更新到新 subprog layout。

- `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs`
  - 新增基于 calico/felix prog 102 callback 中真实 high-first byte pair 的单元测试。
  - 断言 `wide_mem` 折叠后 `PSEUDO_FUNC` 仍指向 func#1 @34，并且 `func_info` offset 仍正确。

## 验证

已运行：

```bash
cargo build --release --workspace --manifest-path bpfopt/Cargo.toml
cargo test --release --workspace --manifest-path bpfopt/Cargo.toml wide_mem_calico_callback -- --nocapture
cargo test --release --workspace --manifest-path bpfopt/Cargo.toml wide_mem -- --nocapture
cargo test --release --workspace --manifest-path bpfopt/Cargo.toml
git diff --check -- bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs
git -C vendor/linux-framework diff --check -- kernel/bpf/syscall.c
```

未运行：`vm-corpus`、`vm-e2e`、`vm-micro`、`make check`。
