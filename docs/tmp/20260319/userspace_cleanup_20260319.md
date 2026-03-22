# Userspace Cleanup Report (2026-03-19)

Source audit: `docs/tmp/userspace_code_audit_20260319.md`

## Summary

- Deleted files: `47`
- Deleted lines from removed files: `20,818`
- Active-file cleanup: `226` deletions, `14` insertions, net `212` lines removed
- Overall diff: `64 files changed, 14 insertions(+), 21,044 deletions(-)`

## 1. Completely DEAD Large Files

| Path | Deleted lines |
| --- | ---: |
| `micro/run_kernel_recompile_per_family.py` | 1397 |
| `corpus/run_post_cmov_fix_corpus_ablation.py` | 1121 |
| `e2e/run_e2e_tetragon.py` | 1693 |
| `e2e/run_e2e_bpftrace.py` | 1519 |
| `e2e/run_tetragon_authoritative_wrapper.py` | 202 |
| **Subtotal** | **5932** |

## 2. Redundant Wrappers

| Path | Deleted lines |
| --- | ---: |
| `micro/run_micro.py` | 21 |
| `corpus/run_macro_corpus.py` | 26 |
| `corpus/run_corpus_perf.py` | 26 |
| `corpus/run_corpus_tracing.py` | 26 |
| `corpus/run_corpus_tracing_exec.py` | 27 |
| `corpus/run_tracing_corpus_vm.py` | 27 |
| `corpus/run_corpus_v5_framework.py` | 26 |
| `corpus/run_production_corpus_v5_framework.py` | 26 |
| `corpus/run_corpus_v5_vm_batch.py` | 26 |
| **Subtotal** | **231** |

## 3. Archive / History Directory Removal

### `micro/archive/scripts/`

| Path | Deleted lines |
| --- | ---: |
| `micro/archive/scripts/README.md` | 10 |
| `micro/archive/scripts/analyze_jit.py` | 1299 |
| `micro/archive/scripts/analyze_paradox.py` | 638 |
| `micro/archive/scripts/analyze_performance_deep.py` | 800 |
| `micro/archive/scripts/analyze_pmu.py` | 150 |
| `micro/archive/scripts/analyze_representativeness.py` | 316 |
| `micro/archive/scripts/analyze_stability.py` | 336 |
| `micro/archive/scripts/analyze_statistics.py` | 717 |
| `micro/archive/scripts/build_policy_blob.py` | 495 |
| `micro/archive/scripts/demo_policy_iteration.py` | 545 |
| `micro/archive/scripts/run_pass_ablation.py` | 22 |
| `micro/archive/scripts/run_rigorous.py` | 30 |
| `micro/archive/scripts/run_rigorous_framework_vm.py` | 30 |
| **Subtotal** | **5388** |

### `micro/programs/archive/runtime/`

| Path | Deleted lines |
| --- | ---: |
| `micro/programs/archive/runtime/README.md` | 10 |
| `micro/programs/archive/runtime/atomic_counter_xadd.bpf.c` | 79 |
| `micro/programs/archive/runtime/get_time_heavy.bpf.c` | 49 |
| `micro/programs/archive/runtime/hash_map_lookup.bpf.c` | 108 |
| `micro/programs/archive/runtime/helper_call_1.bpf.c` | 44 |
| `micro/programs/archive/runtime/helper_call_10.bpf.c` | 56 |
| `micro/programs/archive/runtime/helper_call_100.bpf.c` | 68 |
| `micro/programs/archive/runtime/map_lookup_churn.bpf.c` | 63 |
| `micro/programs/archive/runtime/map_lookup_repeat.bpf.c` | 97 |
| `micro/programs/archive/runtime/map_roundtrip.bpf.c` | 63 |
| `micro/programs/archive/runtime/percpu_map_update.bpf.c` | 55 |
| `micro/programs/archive/runtime/probe_read_heavy.bpf.c` | 61 |
| **Subtotal** | **753** |

### `corpus/archive/`

| Path | Deleted lines |
| --- | ---: |
| `corpus/archive/run_bflip_endian_skip_sweep.py` | 1031 |
| **Subtotal** | **1031** |

### `config/ablation/`

| Path | Deleted lines |
| --- | ---: |
| `config/ablation/ablation_branch_flip.yaml` | 1069 |
| `config/ablation/ablation_cmov.yaml` | 1069 |
| `config/ablation/ablation_endian.yaml` | 1069 |
| `config/ablation/ablation_extract.yaml` | 1069 |
| `config/ablation/ablation_lea.yaml` | 1069 |
| `config/ablation/ablation_rotate.yaml` | 1069 |
| `config/ablation/ablation_wide.yaml` | 1069 |
| **Subtotal** | **7483** |

### Archive / History Total

- Deleted lines: `14,655`

## 4. Active-File Dead Code Cleanup

These are in-place removals from live modules, plus the minimal reroutes needed so surviving entrypoints do not point at deleted wrappers.

| Path | Diff |
| --- | --- |
| `micro/orchestrator/inventory.py` | `+1 / -59` |
| `micro/orchestrator/environment.py` | `-7` |
| `micro/orchestrator/results.py` | `-22` |
| `micro/orchestrator/corpus.py` | `+1 / -7` |
| `micro/_driver_impl_run_micro.py` | `-1` |
| `micro/driver.py` | `+3 / -8` |
| `corpus/directive_census.py` | `-37` |
| `corpus/policy_utils.py` | `-39` |
| `corpus/auto_tune.py` | `-8` |
| `e2e/common/recompile.py` | `-26` |
| `e2e/cases/katran/case.py` | `+1 / -5` |
| `e2e/run.py` | `-1` |
| `e2e/cases/tracee/case.py` | `-1` |
| `e2e/cases/tetragon/case.py` | `-1` |
| `micro/run_corpus_tracing.sh` | `+1 / -1` |
| `corpus/_driver_impl_run_tracing_corpus_vm.py` | `+4 / -2` |
| `corpus/_driver_impl_run_corpus_tracing_exec.py` | `+3 / -1` |
| **Subtotal** | **`+14 / -226`** |

## Compatibility Follow-Ups

- `micro/run_corpus_tracing.sh` now dispatches to `python3 micro/driver.py corpus tracing` because `corpus/run_corpus_tracing.py` was removed.
- `corpus/_driver_impl_run_tracing_corpus_vm.py` command previews / metadata now point at `micro/driver.py corpus tracing-vm`.
- `corpus/_driver_impl_run_corpus_tracing_exec.py` guest VM invocation now points at `micro/driver.py corpus tracing-exec`.

## Verification

### `python3 -m py_compile`

- Passed for all modified `.py` files that still exist after cleanup.

### `make smoke`

- Passed.
- Harness warnings were unchanged environment warnings, not cleanup regressions:
- CPU governor is `powersave`
- turbo boost is enabled
- `perf_event_paranoid=2`
- no explicit CPU affinity set

### `python3 micro/driver.py --help`

- Passed.
- Usage head: `usage: driver.py [-h] {suite,rigorous,census,corpus} ...`

### `python3 e2e/run.py --help`

- Passed.
- Usage head: `usage: run.py [-h] ... {tracee,tetragon,bpftrace,scx,katran}`
