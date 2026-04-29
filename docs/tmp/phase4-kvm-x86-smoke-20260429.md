# Phase4 KVM x86 Functional Smoke - 2026-04-29

Base checkout: `59a5e82b` (`fix(daemon, bpfopt): map-inline must use live map values; invalidation must rerun with same pass list`)

Overall result: **FAIL**. `vm-corpus` and `vm-micro` completed, but `vm-e2e` failed all five cases with `daemon session exited early (rc=1)`. Corpus ReJIT applied programs were > 0, but the requested 12-pass coverage check did not pass: the observed benchmark default list has 11 enabled passes, `branch_flip` is not enabled, and three enabled passes had zero observed hits in this run.

## Commands

| Step | Command | Exit | Result | Artifact |
| --- | --- | ---: | --- | --- |
| corpus | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-corpus SAMPLES=1` | 0 | PASS for run completion | `corpus/results/x86_kvm_corpus_20260429_101106_713274` |
| e2e | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-e2e SAMPLES=1` | 2 | FAIL | `e2e/results/*_20260429_10*` |
| micro | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-micro SAMPLES=3` | 0 | PASS | `micro/results/x86_kvm_micro_20260429_105608_026269` |

Run logs are local under `docs/tmp/phase4-kvm-x86-smoke-20260429-logs/`:

- `vm-corpus.log`
- `vm-e2e.log`
- `vm-micro.log`

## Corpus

Corpus command completed successfully. All 22 corpus apps reached `app_done` with `status=ok`; no panic, Docker build failure, VM startup failure, or daemon crash surfaced in the command log.

Summary from `details/result.json`:

| Metric | Value |
| --- | ---: |
| per_program_geomean | 0.9409667886569882 |
| program_count | 131 |
| wins | 64 |
| losses | 67 |
| requested ReJIT programs | 519 |
| final ReJIT applied programs | 25 |
| final ReJIT not_applied programs | 494 |

Kinsn module state was OK: expected modules `bpf_bulk_memory`, `bpf_endian`, `bpf_extract`, `bpf_rotate`, and `bpf_select` were resident; `failed_modules=[]`.

Note on the coverage table: the persisted artifact compacts successful per-program ReJIT details and keeps detailed pass summaries for non-applied/noop program records. The table below is computed from the available compact per-program pass summaries (`noop_programs[].passes`) and should be read as observed pass-site hits in the saved artifact, while final successful ReJIT application is represented separately by `program_counts.applied=25`.

| Pass | Enabled in benchmark config | Programs with sites | Sites applied | Coverage |
| --- | --- | ---: | ---: | --- |
| wide_mem | yes | 248 | 3335 | PASS |
| rotate | yes | 0 | 0 | FAIL |
| cond_select | yes | 1 | 1 | PASS |
| extract | yes | 92 | 190 | PASS |
| endian_fusion | yes | 5 | 8 | PASS |
| map_inline | yes | 273 | 557 | PASS |
| const_prop | yes | 240 | 23005 | PASS |
| dce | yes | 343 | 22724 | PASS |
| bounds_check_merge | yes | 0 | 0 | FAIL |
| skb_load_bytes_spec | yes | 0 | 0 | FAIL |
| bulk_memory | yes | 186 | 277 | PASS |
| branch_flip | no | 0 | 0 | FAIL |

Coverage summary: 8/12 registry passes had observed hits; 8/11 configured benchmark passes had observed hits. The benchmark default in `corpus/config/benchmark_config.yaml` contains 11 passes, not 12; `branch_flip` is in the bpfopt pass registry but absent from the benchmark default list.

Verifier rejection details recorded in the corpus artifact:

| Reason | Count |
| --- | ---: |
| `BPF_PROG_LOAD dry-run failed: Invalid argument (os error 22)` | 1783 |
| `BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)` | 809 |

These were recorded inside pass verification summaries and did not make the corpus command fail.

## E2E

`make vm-e2e SAMPLES=1` built/refreshed the runtime image and entered the VM, but all five cases failed because the daemon session exited early. The preserved runner-contract debug artifact path printed by the runner was `.state/runner-contracts/run.x86-kvm.e2e.1d12911c`; the directory exists but contains no files.

| Case | Status | Ratio | Error |
| --- | --- | --- | --- |
| tracee | FAIL | N/A | `Tracee case could not run: daemon session exited early (rc=1)` |
| tetragon | FAIL | N/A | `Tetragon case could not run: daemon session exited early (rc=1)` |
| bpftrace | FAIL | N/A | all six baselines failed with `daemon session exited early (rc=1)` |
| bcc | FAIL | N/A | all ten baselines failed with `daemon session exited early (rc=1)` |
| katran | FAIL | N/A | `daemon session exited early (rc=1)` |

Tracee did not reach the known `EINVAL` ReJIT behavior; it failed earlier during daemon-backed case startup. No ratio was produced for any e2e case.

## Micro

`make vm-micro SAMPLES=3` completed successfully.

| Metric | Value |
| --- | ---: |
| suite | `micro_staged_codegen` |
| manifest | `micro/config/micro_pure_jit.yaml` |
| benchmarks | 62 |
| runtimes | `kernel`, `llvmbpf` |
| runs | 124 |
| samples per run | 3 |
| correctness mismatches | 0 |

Warnings observed during micro:

- CPU governor reported `unknown`, turbo boost enabled, `perf_event_paranoid=2`, and no CPU affinity set.
- Docker build emitted Rust warning: unused import `anyhow::Context` in `crates/bpfopt/src/passes/map_inline.rs:8`.

No panic, Docker build failure, VM startup failure, or daemon crash surfaced in the micro command log.

## Error Summary

- **Blocker:** e2e daemon session exited early with rc=1 for all cases.
- **Coverage failure:** 12-pass expectation was not met. Observed config enables 11 passes; `branch_flip` is absent. `rotate`, `bounds_check_merge`, and `skb_load_bytes_spec` had zero observed hits.
- **Corpus verifier rejections:** non-fatal `bpfverify` dry-run rejections were recorded: 1783 `EINVAL` and 809 `EACCES`.
- **No source fixes were made** in this run.
