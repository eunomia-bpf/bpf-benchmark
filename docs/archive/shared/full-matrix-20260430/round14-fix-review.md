# Round 14 修复 review（cff84bff 后续）

## 背景

Subagent commit `cff84bff` 恢复了 daemon `bpfget` 的 `call_offset` + `build_rejit_fd_array` 加载 BTF module fd，解决了 round 14 三类 bug 中的 A/B（kinsn 跨 BTF 分不清）。但实现存在 off-by-one 错误。

## 发现的问题

### Off-by-one in fd_array indexing（关键 bug）

`cff84bff` 把 module BTF fd 放在 `fd_array[call_offset - 1]`，但 kernel verifier 实际读 `fd_array[insn->off]`：

```c
// vendor/linux-framework/kernel/bpf/verifier.c:3293-3296
copy_from_bpfptr_offset(&btf_fd, env->fd_array,
                        offset * sizeof(btf_fd),
                        sizeof(btf_fd))
```

`offset * sizeof(btf_fd)` 直接用 offset 当 index（不减 1）。所以 cff84bff 实现下，`insn->off=N` 时 verifier 去 `fd_array[N]` 拿 fd，但 daemon 把 fd 放在了 `fd_array[N-1]`，全错位。

`call_offset=0` 走 `btf_vmlinux` 分支，不查 fd_array，不需要 daemon 提供。

### TargetKinsnJson 字段过宽

`btf_id` / `call_offset` 都用 `#[serde(default)]`，意味着缺字段时静默 fallback 到 0。这违反 fail-fast：daemon 应该在 target.json 缺字段时立刻报错而不是装作 vmlinux。

## 修复

### `daemon/src/commands.rs`

- `build_rejit_fd_array` 改为：将 module BTF fd 放在 `fd_array[call_offset]`，slot 0 复用第一个 module fd 当占位符（kernel 不读，但 fd_array_cnt 长度需匹配）
- 新增校验：`btf_id == 0` 但 `call_offset != 0` 时 `bail!`（fail-fast）
- 新增校验：同一 btf_id 不能有冲突 `call_offset`
- 新增 `build_rejit_fd_array_with_openers`：通过 closure 注入 BTF fd opener，使单元测试可注入 mock
- docstring 改正 `fd_array[call_offset]` 语义

### `daemon/src/commands.rs::TargetKinsnJson`

- 移除 `#[serde(default)]`，要求 `btf_id` 和 `call_offset` 必填

### `bpfopt/crates/bpfopt/src/main.rs`

- 同步：`KinsnJson.call_offset` 从 `Option<i16>` 改为 `i16`，移除 `serde(default, alias)`

### `daemon/src/bpf.rs::relocate_map_fds_for_rejit`

- 复核：当前实现已支持 `BPF_PSEUDO_MAP_IDX (=5)` 和 `BPF_PSEUDO_MAP_IDX_VALUE (=6)`，会将 IDX 形式 lower 成 FD 形式（参考 v2 commit `9874f2b2`）。无需新增。
- 注意 IDX 形式查的是 `fd_array` 切片（map-only slice），不和 BTF prefix 串扰。

### Unit tests（commands.rs）

新增 4 个测试，每个都断言具体 fd_array index 和值：

- `rejit_fd_array_builder_places_module_btf_fds_at_call_offsets`：2 module（call_offset 1, 2）+ 2 map → btf_count=3, fd_array[0]=fd_array[1]（占位等于 module 1 fd）, fd_array[3..]=maps
- `rejit_fd_array_builder_rejects_missing_module_slot`：call_offset=2 但没 1，触发 contiguous 校验
- `rejit_fd_array_builder_rejects_conflicting_module_offsets`：同一 btf_id 两个不同 call_offset
- `rejit_fd_array_builder_rejects_call_offset_without_btf_id`：fail-fast on missing btf_id

## 文档同步

- `docs/tmp/bpfopt_design_v3.md`：fd_array 段更新为「kernel 用 `fd_array[CALL.off]`，daemon 占位 fd_array[0]」
- `docs/tmp/full-matrix-20260430/restore-pseudo-map-rewrite.md`：boundary table 的 PSEUDO row + Implementation step 3 重写

## 验证

- `cargo test --release --workspace --manifest-path daemon/Cargo.toml`：33 passed（含新 4 个）
- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`：351+ passed
- `make check` 由于纯 daemon-side 修复，跳过（kernel 端无变化）

## Bug C false alarm 复核

Subagent 报告说 calico/felix 的 multi-subprog wide_mem 失败是 false alarm，因为 kernel REJIT 在 non-EXT 程序里 clear `func_info` 并从 pseudo-call 重算 subprog 边界。需在 round 15 vm-corpus 重跑确认。

## Bug B 复核

prefetch pass returncode 1 after 11 passes 在 BTF fd_array 修复后是否仍存在，需 round 15 vm-corpus 验证。preserved workdir `/home/yunwei37/workspace/bpf-benchmark/bpfrejit-failures/{40,44,120}` 保留作为对比 baseline。

## 剩余风险

1. fd_array[0] 用 module 1 fd 占位是「合法但有点 hack」的做法。若未来 kernel 加了对 fd_array[0] 的检查（例如 verifier 预扫所有 entry），可能 break。当前 verifier 行为是 lazy resolution，所以安全。
2. PSEUDO_MAP_IDX 的 lowering 在 daemon-side，但 kernel REJIT 应该原本支持 IDX 形式直接通过 fd_array。lowering 是 v2 历史选择，没有改回去的紧迫性。
