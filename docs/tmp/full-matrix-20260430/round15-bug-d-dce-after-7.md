# Round 15 Bug D: dce after 7 committed passes

## 背景

在 commit `4522507e` 之后，otelcol-ebpf-profiler `prog 129` / `prog 131` 在默认 pass list 的第 8 个 pass `dce` 上被 verifier 拒绝，errno 22：

```text
func#0 @0
no direct value access support for this map type
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
```

该 verifier 文本对应 `BPF_PSEUDO_MAP_VALUE` direct value load 指向了不支持 direct value access 的 map 类型。`processed 0 insns` 说明失败发生在候选 bytecode 的第一条指令。

## 结论

`dce` 删除指令时需要把 `LD_IMM64` 两个 `bpf_insn` slot 当作不可拆分的 bundle。当前 `eliminate_marked_insns()` 按第一 slot 的删除位决定整条宽指令是否删除；如果 CFG/清理阶段只标记第二 slot，旧逻辑会忽略这个删除标记并保留整条 `LD_IMM64`。这会让后续 branch/nop 清理在地址重映射后保留一个本该被删除的 `PSEUDO_MAP_VALUE` 宽指令。

## 修复

- `bpfopt/crates/bpfopt/src/passes/utils.rs`
  - 新增 `normalize_ldimm64_deletions()`。
  - `eliminate_marked_insns()` 在构造新指令流前先归一化删除位图：任意 slot 被标记删除时，整条 `LD_IMM64` 两个 slot 都标记删除。
  - 分支修正继续使用归一化后的删除位图，因此 surviving branch 的目标按整条宽指令删除后的地址重写。

- `bpfopt/crates/bpfopt/src/passes/dce.rs`
  - 新增 DCE 层测试：不可达分支中的 `LD_IMM64 BPF_PSEUDO_MAP_VALUE` 必须整条删除，输出不能留下宽指令碎片。

- `bpfopt/crates/bpfopt/src/passes/utils.rs`
  - 新增低层回归测试：当 `LD_IMM64` 第二 slot 被标记删除时，`eliminate_marked_insns()` 必须删除两个 slot，并把两个旧地址都映射到同一个新 PC。

## 验证

只运行了 cargo 测试，未运行 `make check` / `vm-corpus` / `vm-e2e` / `vm-micro`。

```text
cargo test --release --manifest-path bpfopt/Cargo.toml dce -- --nocapture
12 passed

cargo test --release --manifest-path bpfopt/Cargo.toml test_eliminate_marked_insns_deletes_ldimm64_when_second_slot_is_marked -- --nocapture
1 passed

cargo test --release --workspace --manifest-path bpfopt/Cargo.toml
355 lib tests passed; bpfopt CLI 9 passed; cli_pipeline 9 passed; bpfprof 7 passed; bpfprof CLI 4 passed; kernel_sys 21 passed; kernel-sys integration 2 passed; doc tests 0.
```
