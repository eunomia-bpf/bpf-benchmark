# Round 18 Bug D: DCE 真实复现与修复

## 复现

已用 preserved workdir 真实 bytecode 复现：

```bash
cargo build --release --workspace --manifest-path bpfopt/Cargo.toml
./bpfopt/target/release/bpfopt --pass dce \
  < corpus/results/failures/129/pass-07-dce.in.bin \
  > /tmp/dce-129-out.bin 2> /tmp/dce-129-stderr
diff <(xxd /tmp/dce-129-out.bin) \
     <(xxd corpus/results/failures/129/pass-07-dce.out.bin)
```

129 / 131 的 diff 都为空，说明当前 `bpfopt --pass dce` 输出与 preserved 失败输出字节一致。

失败日志：

```text
func#0 @0
no direct value access support for this map type
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
```

## 关键观察

`ad3e401a` 的 LD_IMM64 原子删除修复不到位，因为真实输出里没有发现半条 `LD_IMM64` 残留，也没有发现 DCE 改写 `src_reg`。DCE 的确删除了若干早期 `BPF_PSEUDO_MAP_VALUE old_fd=42` dead-def 片段，但 surviving 指令本身仍是合法的原始 old fd 形态。

真实问题在 daemon ReJIT 前的 map fd relocation：它用“当前 pass 输出 bytecode 的首次出现 old_fd 顺序”去配对 `prog_info.map_ids` / map fd array。DCE 删除早期 old_fd=42 后，剩余 old_fd 的首次出现顺序改变，daemon 把 old_fd=42 绑定到了错误 map。

129：

```text
pass-07 input unique old fds:  41,25,42,24,26
pass-07 output unique old fds: 41,25,24,26,42
map_ids: 489,466,490,465,471
```

`42` 在 input 中绑定 map_id 490，map_type 2 ARRAY，支持 direct value access；在 output 顺序中会被旧 daemon 误绑到 map_id 471，map_type 4 PERF_EVENT_ARRAY，不支持 direct value access。

131：

```text
pass-07 input unique old fds:  38,35,47,42,24,20,48
pass-07 output unique old fds: 38,35,47,24,20,48,42
map_ids: 488,481,495,490,465,464,496
```

`42` 从 map_id 490 ARRAY 被误绑到 map_id 496 PERF_EVENT_ARRAY。

`processed 0 insns` 表示 verifier 在候选程序正式状态遍历前处理 direct map value 时失败；不能推断候选 bytecode 第 0 条就是 `LD_IMM64 PSEUDO_MAP_VALUE`。

## 根因

跨进程 ReJIT 必须把 loader 进程的旧 map fd immediate 改成 daemon 进程打开的 map fd。这个 old_fd -> live fd 绑定必须来自原始 snapshot bytecode 的 first-seen old_fd 顺序，因为 `prog_info.map_ids` 也是原始 verifier 记录的 used_maps 顺序。

优化 pass 可以删除、重排或保留任意 map 引用子集。用 transformed candidate 重新推导 first-seen 顺序不是语义保持操作，会在 DCE 删除早期 map 引用后错绑 map。

DCE 是触发器，不是 `src_reg` 损坏根因；前序 `map_inline` / `const_prop` 输出中 old_fd=42 仍按原顺序绑定到 ARRAY，并已成功 committed。

## 修复

- `daemon/src/bpf.rs`
  - `relocate_map_fds_for_rejit()` 新增 `original_insns` 参数。
  - FD-form `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE` 的 old_fd -> daemon fd 绑定改为从原始 snapshot bytecode 收集。
  - transformed candidate 中出现原始 snapshot 没有的 old fd 时 fail-fast 报错，不静默保留 stale fd。
  - `BPF_PSEUDO_MAP_IDX` / `BPF_PSEUDO_MAP_IDX_VALUE` 仍按 map-only fd_array slice 转 FD form。

- `daemon/src/commands.rs`
  - `rejit_program()` 调用 relocation 时传入 `snapshot.insns`。

- 单元测试
  - 新增 `relocate_keeps_original_fd_binding_after_otelcol_dce_deletes_early_map_value_refs`，用 129/131 的真实 old_fd 顺序抽出的最小 case 覆盖 fd42 被 DCE 推迟后的错绑。
  - 新增 `relocate_rejects_fd_form_map_ref_missing_from_original_snapshot`，保证未知 old fd fail-fast。

## 验证

只运行 cargo test，未运行 `vm-corpus` / `vm-e2e` / `vm-micro` / `make check`。

```text
cargo test --release --workspace --manifest-path daemon/Cargo.toml
37 passed

cargo test --release --workspace --manifest-path bpfopt/Cargo.toml
bpfopt lib 355 passed; bpfopt bin 9 passed; cli_pipeline 9 passed;
bpfprof 7 passed; bpfprof CLI 4 passed; kernel_sys 21 passed;
kernel-sys integration 2 passed.
```
