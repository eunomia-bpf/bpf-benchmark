# Per-Pass ReJIT Daemon Implementation Report

Date: 2026-05-01

## Summary

This change moves daemon optimization to the clean ReJIT-only model:

```text
snapshot live prog
for pass in fixed daemon 12-pass list:
  bpfopt --pass <name> < current.bin > pass.out.bin
  BPF_PROG_REJIT(log_level=2, insns=pass.out, fd_array=used_maps only)
  parse verifier log -> verifier-states.json for later passes
```

There is no daemon `BPF_PROG_LOAD`, no `daemon/src/dry_run.rs`, no `LoadAttr` rebuild, no BTF metadata replay, no pseudo-map fd-to-idx rewrite, and no final aggregate ReJIT. A successful pass is committed immediately by the kernel. If a later pass fails, the program remains in the partial state produced by the previous successful passes and the result records the failed pass.

## Three Designs Checked

1. **Keep thin `BPF_PROG_LOAD` dry-run for verifier states**: rejected. It preserves the v3 failure mode from `LoadAttr` reconstruction, attach/BTF replay, map rebinding, and verifier acceptance differences from real ReJIT.
2. **Run a full `bpfopt` pipeline then one final ReJIT**: rejected. It gives one acceptance point, cannot feed real per-pass ReJIT states to `map_inline` / `const_prop`, and loses precise partial failure reporting.
3. **Run `bpfopt --pass` + `BPF_PROG_REJIT(log_level=2)` per pass**: implemented. It uses the kernel's rollback path for each pass, lets the kernel reuse `prog->aux` metadata, and makes verifier logs the only source of per-pass register states.

## Implementation Details

- `bpfopt` CLI now requires `--pass <name>` for optimization. It no longer has a default optimize pipeline or multi-pass `--enabled-passes` interface.
- daemon default pass list is hardcoded to 12 passes: `wide_mem`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`, `bulk_memory`, `prefetch`.
- daemon builds `fd_array` only by opening `prog_info.map_ids` / `used_maps` in order with `BPF_MAP_GET_FD_BY_ID`.
- `kernel-sys::prog_rejit()` supplies `log_level=2 | BPF_LOG_STATS` and retries `ENOSPC` log-buffer failures up to 256 MiB.
- verifier states are parsed with `kernel_sys::verifier_states_from_log()` after every successful pass ReJIT.
- `optimize-batch` uses a per-program Rayon worker pool with default `min(num_cpus, 16)` workers, halved on small VM CPU counts.
- dead `kernel-sys` `prog_load_dryrun_report` API was removed to avoid a hidden fallback surface.

## Failure Semantics

On a pass failure, the preserved workdir contains the pass input bytecode, pass output bytecode when available, verifier log when available, `failed_pass.txt`, `partial_failure.json`, and ReJIT errno/error text. The socket result includes:

- `error_message`
- `summary.failed_pass`
- `summary.committed_passes_before_failure`

One program failure does not stop other programs in an `optimize-batch`.

## Pseudo-Map Handling

The daemon no longer rewrites `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE` to `BPF_PSEUDO_MAP_IDX`. Per the new model, ReJIT receives the pass output directly plus the minimal used-map fd array. If a pass emits a pseudo-map shape the kernel rejects, that pass fails normally with the preserved verifier log and errno. The final `make check` run included the existing ReJIT fd-array and pseudo-map verifier negative coverage.

## Code Size

Focused implementation diff:

```text
11 files changed, 728 insertions(+), 1429 deletions(-)
net: -701 lines
```

Notable removals:

```text
daemon/src/dry_run.rs                         -239 lines
bpfopt/crates/kernel-sys/src/lib.rs           -198 lines
bpfopt/crates/bpfopt/src/main.rs              -150 net lines
daemon/src/commands.rs                        -100 net lines
```

This meets the expected net reduction target of at least 700 lines.

## Acceptance

Final checks run:

```text
cargo test --workspace                         PASS
cargo test --workspace --manifest-path daemon/Cargo.toml  PASS
make daemon-tests                              PASS
make check                                     PASS
```

`make check` final VM result:

```text
RESULTS: 27 passed, 0 failed
vm-test: ALL PASSED
```

Forbidden targets were not run: `make vm-corpus`, `make vm-e2e`, `make vm-micro`.
