# AWS x86 e2e and corpus run summary

Date: 2026-04-18 America/Vancouver

## Final commits

- No code changes were made for this AWS x86 verification.
- Runtime-image commit under test: `1c8da845a51710e64be9432310ea8117035038c9` (`[runtime-image] mirror tracee musl libs into loader path`)
- Doc-only tracker commit after verification: `b3cc3bd8feaf50c408c2e481600f8ed49a6fe842` (`docs: record AWS x86 runtime verification`)
- Existing uncommitted changes in `Makefile` and `runner/containers/runner-runtime.Dockerfile` were not touched.

## Runtime image

- Reused existing tar: `.cache/container-images/x86_64-runner-runtime.image.tar`
- Image rebuild: not performed
- Remote `docker load` succeeded for both e2e and corpus runs:
  - `Loaded image: bpf-benchmark/runner-runtime:x86_64`

## AWS target

| Suite | Instance ID | Instance type | Region | AZ | Final state |
| --- | --- | --- | --- | --- | --- |
| e2e | `i-04551d31d861c7fb1` | `t3.large` | `us-east-1` | `us-east-1f` | terminated |
| corpus | `i-0f01866bb3a11c9d9` | `t3.large` | `us-east-1` | `us-east-1f` | terminated |

Both instances booted the benchmark kernel `7.0.0-rc2` and verified `/boot/vmlinuz-7.0.0-rc2`.

## e2e run

Command:

```sh
make aws-e2e RUN_TARGET_ARCH=x86_64
```

Result: pass, `e2e: ALL PASSED`

Result log:

- `.cache/aws-x86/results/logs/e2e_run.aws-x86.e2e.b4fcb7fd_20260419_031814.remote.log`

Cases:

| Case | Status | Result session |
| --- | --- | --- |
| tracee | pass | `e2e/results/tracee_20260419_031818_008621` |
| tetragon | pass | `e2e/results/tetragon_20260419_032815_142316` |
| bpftrace | pass | `e2e/results/bpftrace_20260419_032927_308672` |
| scx | pass | `e2e/results/scx_20260419_033546_904404` |
| bcc | pass | `e2e/results/bcc_20260419_033726_422628` |
| katran | pass | `e2e/results/katran_20260419_034826_414060` |

## corpus run

Command:

```sh
make aws-corpus RUN_TARGET_ARCH=x86_64
```

Result: pass, corpus status `ok`

Result session:

- `corpus/results/aws_x86_corpus_20260419_040503_116383`

Result log:

- `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.bed5c674_20260419_040500.remote.log`

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

- None for AWS x86 e2e/corpus verification.
- Note: the first local invocation failed before provisioning because the current shell did not have `AWS_X86_*` environment values. The successful runs used the same AWS x86 configuration values as prior preserved run configs.
