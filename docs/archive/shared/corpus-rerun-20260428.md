# x86 Corpus Rerun - 2026-04-28

## Commands

- Activated `/home/yunwei37/workspace/.venv`.
- Removed stale runtime image tars:
  - `.cache/container-images/x86-runner-runtime.image.tar`
  - `.cache/container-images/x86_64-runner-runtime.image.tar`
- `make x86-runner-runtime-image` does not exist in this Makefile, so the equivalent existing target was used:
  - `make image-runner-runtime-image-tar RUN_TARGET_ARCH=x86_64`
- Katran artifacts image was already present and was loaded from `.cache/container-images/x86_64-katran-artifacts.image.tar`; it did not need a rebuild.
- Smoke test:
  - `make vm-corpus SAMPLES=1`
- Full run:
  - `make vm-corpus`

## Fixes Applied

- The first smoke run exposed another root-incompatible stress-ng workload: `spawn`.
- Removed `spawn` from the scheduler/process stress-ng workload in `runner/libs/workload.py`.
- Rebuilt the x86 runtime image after the workload fix.

## Runs

- Runtime image tar: `.cache/container-images/x86_64-runner-runtime.image.tar`
- Smoke result: `corpus/results/x86_kvm_corpus_20260428_064836_962442/details/result.json`
  - Status: `error`, with only accepted `tracee/monitor` EINVAL.
  - `per_program_geomean`: `0.9821015349185259`
  - `program_count`: `133`
  - `wins/losses`: `63/70`
- Full result: `corpus/results/x86_kvm_corpus_20260428_070851_973550/details/result.json`
  - Status: `error`, with only accepted `tracee/monitor` EINVAL.
  - Samples: `30`
  - Workload seconds: `1.0`

## Full Run Summary

- `per_program_geomean`: `1.0038275637087666`
- `program_count`: `146`
- `wins/losses`: `81/65`

Lower ratios are better because `ratio = post_rejit_avg / baseline_avg`.

- Compared with previous `0.9714`: current is higher by `0.03242756370876654` (`+3.34%`), so it is slower than that prior result.
- Compared with previous `1.125`: current is lower by `0.12117243629123342` (`-10.77%`), so it is better than that prior result.

## App Status

| App | Status |
| --- | --- |
| `bcc/capable` | `ok` |
| `bcc/execsnoop` | `ok` |
| `bcc/bindsnoop` | `ok` |
| `bcc/biosnoop` | `ok` |
| `bcc/vfsstat` | `ok` |
| `bcc/opensnoop` | `ok` |
| `bcc/syscount` | `ok` |
| `bcc/tcpconnect` | `ok` |
| `bcc/tcplife` | `ok` |
| `bcc/runqlat` | `ok` |
| `calico/felix` | `ok` |
| `otelcol-ebpf-profiler/profiling` | `ok` |
| `cilium/agent` | `ok` |
| `tetragon/observer` | `ok` |
| `katran` | `ok` |
| `tracee/monitor` | `error` |
| `bpftrace/capable` | `ok` |
| `bpftrace/biosnoop` | `ok` |
| `bpftrace/vfsstat` | `ok` |
| `bpftrace/runqlat` | `ok` |
| `bpftrace/tcplife` | `ok` |
| `bpftrace/tcpretrans` | `ok` |

## Failed Apps

| App | Error |
| --- | --- |
| `tracee/monitor` | `prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)` |

This is the known accepted tracee EINVAL from the kernel REJIT poke-table limitation for direct tail calls.

## Notes

- Cilium completed with status `ok`; stale BPF program IDs from agent reloads were reported as warnings, not failures.
- No calico `workload_miss` was present in this full run.
- No commits were made.
