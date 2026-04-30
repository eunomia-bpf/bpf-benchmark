# P89H Snapshot Report

Date: 2026-04-30

Base HEAD at task start: `0ab0d0d35ca465e65f25bdebb4b6248e94bc29a8`

## Fixes

1. `503338e9 fix(daemon): snapshot replay side inputs`
   - Daemon now captures `verifier-states.json` for every handled program immediately after `bpfget --full`.
   - Daemon now captures `map-values.json` for every handled program immediately after `bpfget --full`.
   - Existing `map_inline` and `const_prop` paths reuse those captured side inputs instead of creating them only when the requested pass list needs them.
   - Failure workdirs and `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS=1` debug workdirs preserve both snapshot files because they are now base workdir artifacts.

2. `2fb3004a fix(bpfverify): replay maps with dummy fixtures`
   - `bpfget --full` now includes portable map metadata fields in `map_fds.json`: flags, ifindex, BTF ids, and `map_extra`.
   - `kernel-sys` exposes a libbpf-backed `create_map` wrapper for host-local dummy map creation.
   - `bpfverify` now supports `--dummy-map-fds --prog-info prog_info.json`, validates map fixtures, creates dummy maps from metadata, and patches pseudo-map references from `prog_info.map_ids` order rather than reopening guest map ids.

## Validation

Passed:

- `cargo test --manifest-path bpfopt/Cargo.toml -p bpfverify -p bpfget -p kernel-sys`
- `cargo test --manifest-path daemon/Cargo.toml`
- `cargo build --manifest-path bpfopt/Cargo.toml -p bpfverify -p bpfget -p kernel-sys --release`
- `cargo build --manifest-path daemon/Cargo.toml --release`
- `bash -n docs/tmp/p89h_reproduce.sh`

Blocked:

- `cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt` currently fails in unrelated P89H-Root work:
  - `bpfopt/crates/bpfopt/src/passes/utils.rs`: `idx`/`count` type mismatch.
  - `bpfopt/crates/bpfopt/src/pass_tests.rs`: missing new `KinsnRegistry` fields.
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs`: missing new `ProfilingData` fields.
- `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS=1 BPFREJIT_BENCH_PASSES=bulk_memory,rotate,cond_select,extract,endian_fusion make vm-corpus SAMPLES=1` failed during Docker image build before corpus execution. The kinsn layer built 6 modules including `bpf_prefetch.ko`, but the x86 image still expects 5 modules.

Because the VM corpus build did not complete, no new P89H failure/debug workdirs were produced in this run.

## Host Replay Status

- Default 11-pass host replay: not measured in this run because the new corpus snapshot could not be collected while P89H-Root module/pass changes are incomplete.
- Host `bpfverify --dummy-map-fds` dryrun: not measured on the corpus for the same reason.

The latest existing corpus remains `corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524`, which predates these snapshot fixes and lacks the new artifacts.

## Repository Checks

- `vendor/linux-framework` remains at `a1b8bade169fae6e174ef022fa96fb1c626d96df`.
