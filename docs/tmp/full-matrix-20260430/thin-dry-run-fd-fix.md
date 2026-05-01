# Thin Dry-Run fd_array Fix Report

Date: 2026-05-01

## Failure

`vm-corpus` round 11 在第一个 app `bcc/capable` 的 prog 6 触发：

```text
capture verifier states for prog 6: thin verifier dry-run failed:
thin verifier dry-run rejected original bytecode (errno 22):
fd 4 is not pointing to valid bpf_map
```

`bcc/capable` 只有 1 个 program 和 1 个 map。该失败不是 app-specific，而是 daemon thin verifier dry-run 对原始 bytecode/map fd 语义处理错误。

## Audit

本轮至少检查了三条可能根因：

1. **OwnedFd 生命周期**：`build_rejit_fd_array()` 构造的 `RejitFdArray` 在 `write_original_verifier_states()` 和最终 `BPF_PROG_REJIT` 返回前仍活着，raw fd 没有在 syscall 前被 drop。该方向不是主因。
2. **stale fd**：`BPF_PROG_GET_ORIGINAL` 返回的是 loader 当时提交的原始指令。BCC 程序使用 `BPF_PSEUDO_MAP_FD imm=4`，这个 `4` 是 loader 进程里的旧 map fd，不是 daemon 当前进程里的 live map fd。thin dry-run 直接把原 bytecode 交给 `BPF_PROG_LOAD`，verifier 因此按 stale fd 解析并报 `valid bpf_map`。这是主因。
3. **fd_array 顺序/语义**：fork kernel verifier 对 `BPF_PSEUDO_MAP_IDX` 使用 `fd_array[imm]`，对 `BPF_PSEUDO_MAP_FD` 不使用 `fd_array`。daemon 已按 `prog_info.map_ids` 构造 live map fd 前缀，顺序可用；bug 是原始/candidate bytecode 没有在提交前切到 idx 语义。

也检查了 kinsn BTF fd 分支：`fd_array_cnt` 非零时 kernel 允许 fd_array 里有 map 或 BTF fd；module kinsn 通过 insn `off` 索引 BTF fd。因此 BTF fd 不是这次 `fd 4 is not pointing to valid bpf_map` 的直接原因。

## Fix

修复位置：`daemon/src/commands.rs`。

- 保留 bpfopt 输入 bytecode 不变，避免破坏 `map_inline` 对旧 fd 的分析。
- 在 thin dry-run 进入 `kernel_sys::prog_load_dryrun_report()` 前，把 `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE` 改写为 `BPF_PSEUDO_MAP_IDX` / `BPF_PSEUDO_MAP_IDX_VALUE`。
- 在最终 `BPF_PROG_REJIT` 前对 optimized bytecode 做同样改写，防止同类 stale fd 在主路径暴露。
- 旧 fd 到 map index 的绑定只从原始 bytecode 建一次，并按 `prog_info.map_ids` / verifier used_maps 顺序解析；optimized bytecode 使用同一绑定，避免“第一个 map load 被优化删除后，第二个 map 被错误映射到 index 0”。
- `RejitFdArray` 仍是唯一 live fd 构造路径；测试注入 BTF opener 覆盖 map-only、map+kinsn、no-map+kinsn 三个分支。

## Tests

Allowed validation passed:

- `cargo test --workspace --manifest-path daemon/Cargo.toml`: passed, 33 daemon tests.
- `cargo test --workspace --manifest-path bpfopt/Cargo.toml`: passed.
- `make daemon-tests`: passed, 33 daemon tests.
- `make check`: passed. Final guest summary: `RESULTS: 27 passed, 0 failed`, including `fuzz_rejit (1000 rounds)`.

New focused coverage:

- stale loader fd `4` is rewritten to `BPF_PSEUDO_MAP_IDX imm=0` before verifier-state capture.
- original old-fd binding survives optimized bytecode that deleted an earlier map load.
- ReJIT fd_array construction keeps live OwnedFd objects for map-only, map+kinsn, and no-map+kinsn target cases.

Forbidden targets were not run:

- `make vm-corpus`: not run.
- `make vm-e2e`: not run.
- `make vm-micro`: not run.
