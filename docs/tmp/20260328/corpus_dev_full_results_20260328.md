# Corpus Dev Full Results 2026-03-28

## Status

- Requested run: `make vm-corpus TARGET=x86 PROFILE=dev`
- Overall status: `FAILED / PARTIAL`
- Artifact root: `runner/corpus/results/vm_corpus_20260328_194356`
- Metadata: `runner/corpus/results/vm_corpus_20260328_194356/metadata.json`
- Result JSON: `runner/corpus/results/vm_corpus_20260328_194356/details/result.json`
- Started at: `2026-03-28T19:43:56.830159+00:00`
- Last update: `2026-03-28T20:34:31.854597+00:00`
- Failure: guest batch exited with `139` and the host surfaced `RuntimeError: vm guest batch failed`
- Failure point from `details/progress.json`: object index `288 / 469`, current object `linux-selftests:tools/testing/selftests/bpf/progs/test_map_init.bpf.o`
- Guest log tail: `docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json.stdout_log.txt` shows `python3 corpus/driver.py ...` segfaulting inside the VM

This means the run did not finish the full dev corpus. The metrics below are the last persisted partial snapshot from the failed artifact, not a complete corpus result.

## Coverage Snapshot Before Crash

- Profile selection: `469` objects, `2009` programs
- Completed/attempted before crash: `288 / 469` objects (`61.4%`), `1149 / 2009` programs (`57.2%`)
- Compile pairs: `648`
  - `32.3%` of selected programs
  - `56.4%` of attempted programs
- Measured pairs: `483`
  - `24.0%` of selected programs
  - `42.0%` of attempted programs
- Applied programs: `364`
  - `18.1%` of selected programs
  - `31.7%` of attempted programs

## Geomean

- Exec geomean (`baseline / rejit`): `0.980x`
  - Computed on `255` program records with numeric `speedup_ratio`
  - Interpreted literally, this partial snapshot is about `1.97%` slower overall
- Code-size geomean (`baseline / rejit`): `1.006x`
  - Computed on `648` compile pairs with non-null `size_ratio`
  - Interpreted literally, this partial snapshot is about `0.63%` smaller overall
- Applied-only exec geomean: `0.995x` on `170` numeric ratios
- Applied-only code-size geomean: `1.011x` on `364` applied compile pairs

## Pass Hit Counts

| Pass | Total hits | Compile hits | Run hits |
| --- | ---: | ---: | ---: |
| `const_prop` | 635 | 353 | 282 |
| `map_inline` | 465 | 258 | 207 |
| `dce` | 458 | 254 | 204 |

## Applied Distribution By Repo

These rows cover only repos reached before the crash.

| Repo | Applied programs | Share of applied | Programs | Compile pairs | Measured pairs | Exec geomean | Code-size geomean |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `bcc` | 204 | 56.0% | 365 | 241 | 206 | `0.978x` | `1.012x` |
| `calico` | 51 | 14.0% | 59 | 59 | 59 | `1.125x` | `1.000x` |
| `linux-selftests` | 51 | 14.0% | 589 | 278 | 176 | `0.874x` | `1.002x` |
| `coroot-node-agent` | 46 | 12.6% | 46 | 46 | 26 | `1.005x` | `1.000x` |
| `libbpf-bootstrap` | 9 | 2.5% | 21 | 18 | 10 | `0.997x` | `1.006x` |
| `katran` | 2 | 0.5% | 5 | 5 | 5 | `0.919x` | `1.135x` |
| `datadog-agent` | 1 | 0.3% | 1 | 1 | 1 | `n/a` | `1.006x` |
| `KubeArmor` | 0 | 0.0% | 63 | 0 | 0 | `n/a` | `n/a` |

## Failure Reasons Distribution

These counters are taken directly from `summary.failure_reasons`; they count failure events, not unique programs, so baseline/rejit prepared-state misses appear separately.

| Reason | Count |
| --- | ---: |
| `prepared kernel state for ref object-0001:baseline:prepared is unavailable because prepare failed: bpf_object__load failed: Invalid argument` | 627 |
| `prepared kernel state for ref object-0001:rejit:prepared is unavailable because prepare failed: bpf_object__load failed: Invalid argument` | 627 |
| `prepared kernel state for ref object-0001:baseline:prepared is unavailable because prepare failed: bpf_object__load failed: No such process` | 184 |
| `prepared kernel state for ref object-0001:rejit:prepared is unavailable because prepare failed: bpf_object__load failed: No such process` | 184 |
| `prepared kernel state for ref object-0001:baseline:prepared is unavailable because prepare failed: bpf_object__load failed: Permission denied` | 102 |
| `prepared kernel state for ref object-0001:rejit:prepared is unavailable because prepare failed: bpf_object__load failed: Permission denied` | 102 |
| `bpf_program__attach failed: Operation not supported` | 116 |
| `bpf_program__attach failed: No such file or directory` | 70 |
| `prepared kernel state for ref object-0001:baseline:prepared is unavailable because prepare failed: prepared kernel state did not load any programs` | 54 |
| `prepared kernel state for ref object-0001:rejit:prepared is unavailable because prepare failed: prepared kernel state did not load any programs` | 54 |
| `bpf_program__attach failed: Invalid argument` | 52 |
| `bpf_program__attach failed: Bad file descriptor` | 20 |
| `io-mode packet requires an XDP or skb packet context` | 14 |
| `prepared kernel state is missing program: not_ptr_to_stack` | 4 |
| `prepared kernel state is missing program: not_valid_dynptr` | 4 |
| `bpf_program__attach failed: Device or resource busy` | 2 |

## Wins vs Losses

Wins/losses are derived from `program_records[].speedup_ratio`, where `speedup_ratio = baseline_exec_ns / rejit_exec_ns`.

| Slice | Numeric ratios | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: |
| Overall measured subset | 255 | 119 | 131 | 5 |
| Applied-only subset | 170 | 78 | 89 | 3 |

The partial run is therefore slightly loss-heavy both overall and within the applied-only subset, although the applied-only exec geomean (`0.995x`) is much closer to parity than the raw overall geomean (`0.980x`).

## Notes

- This artifact is useful for debugging coverage, pass hits, repo distribution, and the crash point.
- It is not a valid replacement for a complete full-corpus dev run because `181` objects and `860` selected programs were never reached.
- The first thing to fix before any rerun is the guest-side `SIGSEGV` in `python3 corpus/driver.py`; otherwise a second full run is likely to die again after another long partial execution.
