# KVM x86 e2e and corpus run summary

Date: 2026-04-18 America/Vancouver

## Final commits

- `1c8da845a51710e64be9432310ea8117035038c9` `[runtime-image] mirror tracee musl libs into loader path`

## Fix summary

- Mirrored Tracee's bundled musl runtime dependencies into the musl loader search directory selected by `/etc/ld-musl-x86_64.path`.
- This keeps the runtime image self-contained and avoids a KVM-specific `LD_LIBRARY_PATH` override.
- Rebuilt the x86_64 runtime image tar with:
  - `make image-runner-runtime-image-tar RUN_TARGET_ARCH=x86_64`
- Verified Tracee starts directly in the rebuilt runtime image without `LD_LIBRARY_PATH`:
  - `/artifacts/tracee/bin/tracee version` -> `Tracee version: v0.24.1`

## e2e run

Command:

```sh
make vm-e2e
```

Result: pass, `e2e: ALL PASSED`

Cases:

| Case | Status | Result session |
| --- | --- | --- |
| tracee | pass | `e2e/results/tracee_20260419_014239_667395` |
| tetragon | pass | `e2e/results/tetragon_20260419_015204_837606` |
| bpftrace | pass | `e2e/results/bpftrace_20260419_015316_935634` |
| scx | pass | `e2e/results/scx_20260419_020052_575503` |
| bcc | pass | `e2e/results/bcc_20260419_020207_536662` |
| katran | pass | `e2e/results/katran_20260419_021258_340716` |

## corpus run

Command:

```sh
make vm-corpus
```

Result: pass, corpus status `ok`

Result session:

- `corpus/results/x86_kvm_corpus_20260419_021913_955464`

Cases:

| App | Runner | Workload | Status |
| --- | --- | --- | --- |
| bcc/capable | bcc | exec_storm | pass |
| bcc/execsnoop | bcc | exec_storm | pass |
| bcc/bindsnoop | bcc | bind_storm | pass |
| bcc/biosnoop | bcc | block_io | pass |
| bcc/vfsstat | bcc | vfs_create_write_fsync | pass |
| bcc/opensnoop | bcc | file_open_storm | pass |
| bcc/syscount | bcc | file_open_storm | pass |
| bcc/tcpconnect | bcc | network | pass |
| bcc/tcplife | bcc | network | pass |
| bcc/runqlat | bcc | hackbench | pass |
| scx/rusty | scx | hackbench | pass |
| tetragon/default | tetragon | exec_storm | pass |
| katran | katran | test_run | pass |
| tracee/default | tracee | tracee_default | pass |
| bpftrace/capable | bpftrace | exec_storm | pass |
| bpftrace/biosnoop | bpftrace | block_io | pass |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | pass |
| bpftrace/runqlat | bpftrace | hackbench | pass |
| bpftrace/tcplife | bpftrace | network | pass |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | pass |

## Outstanding issues

- None for the requested KVM x86 Tracee runtime fix.
- Out of scope: pre-existing uncommitted changes remain in `Makefile`, the SCX section of `runner/containers/runner-runtime.Dockerfile`, and `docs/tmp/kheaders-fix-20260418/`. They were not included in the commit above.
