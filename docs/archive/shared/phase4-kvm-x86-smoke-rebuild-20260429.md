# Phase 4 KVM x86 Smoke Rebuild - 2026-04-29

Base checkout before this report: `5fbe934b83e90108ee017ebf88d63b680286599e`
(`fix(daemon): skip hash map inline when live lookup returns null`).

Overall result: **FAIL**. The rebuilt image includes the full daemon plan B fix chain and the e2e daemon early-exit blocker is resolved: all five e2e cases ran to result artifacts. Remaining failures are surfaced as verifier/ReJIT errors, not daemon startup exits. `vm-micro` passed; `vm-corpus` and `vm-e2e` exited non-zero.

## Commands

| Step | Command | Exit | Result | Artifact |
| --- | --- | ---: | --- | --- |
| corpus | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-corpus SAMPLES=1` | 2 | FAIL | `corpus/results/x86_kvm_corpus_20260429_113603_787483` |
| e2e | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-e2e SAMPLES=1` | 2 | FAIL | `e2e/results/{tracee,tetragon,bpftrace,bcc,katran}_20260429_11*_12*` |
| micro | `source /home/yunwei37/workspace/.venv/bin/activate && make vm-micro SAMPLES=3` | 0 | PASS | `micro/results/x86_kvm_micro_20260429_121823_720416` |

## Rebuild Evidence

The run did not reuse the previous old runtime image. `vm-corpus` rebuilt and exported `bpf-benchmark/runner-runtime:x86_64` as image digest `sha256:c94385668959557c3b3a86630432bf6e3bf0c85226fa5833b06da916d23502cd`, then saved it to `.cache/container-images/x86_64-runner-runtime.image.tar`.

Observed rebuilt layers included:

| Layer | Evidence |
| --- | --- |
| daemon | `COPY daemon ./daemon`, then `cargo build --release ... daemon` |
| bpfopt CLI suite | `COPY bpfopt ./bpfopt`, then `cargo build --release --workspace ... -p bpfopt -p bpfget -p bpfrejit -p bpfverify -p bpfprof` |
| kinsn modules | `bpf_bulk_memory`, `bpf_endian`, `bpf_extract`, `bpf_rotate`, and `bpf_select` loaded; no missing expected module was reported |

## Old Smoke Comparison

| Check | Old smoke at `152956c4` | Rebuilt smoke at `5fbe934b` |
| --- | --- | --- |
| Runtime image | old image | rebuilt image with full plan B chain |
| Corpus | PASS, geomean about `0.94` | FAIL, geomean `0.9276669469349486` |
| Corpus ReJIT applied | positive | positive: `28/519` requested programs applied |
| E2E daemon behavior | all five FAIL from `daemon session exited early (rc=1)` | early exit resolved; all five cases produced case artifacts |
| E2E result | all FAIL before workload result | all FAIL from surfaced verifier/ReJIT errors |
| Micro | not part of the supplied old result | PASS, `62/62` benchmarks |

## Corpus

Corpus produced a performance summary, but suite status was `error`.

| Metric | Value |
| --- | ---: |
| status | `error` |
| per_program_geomean | `0.9276669469349486` |
| program_count | `136` |
| wins | `46` |
| losses | `90` |
| ratio min | `0.03614058355437666` |
| ratio max | `2.295882310521382` |
| apps ok/error | `11 / 11` |
| requested ReJIT programs | `519` |
| applied ReJIT programs | `28` |
| not_applied ReJIT programs | `491` |
| apps with applied programs | `10` |

Primary corpus failures recorded in the artifact were `bpfverify` dry-run/load errors: `EINVAL`, `EACCES`, missing `btf_id` for tracing programs, `fd_idx without fd_array is invalid`, plus one `BPF_PROG_REJIT: No space left on device (os error 28)` on an otelcol program. No panic was observed.

## E2E

Daemon early exit is fixed for this smoke: all five case directories have `details/result.json`. The e2e suite still failed because every case reached a post-ReJIT verifier/ReJIT error.

Throughput ratio below is `post_rejit / baseline`; values below `1.0` are app-throughput regressions.

| Case | Status | Completed | Baseline tput | Post tput | Ratio | Ratio check | Primary failure |
| --- | --- | --- | ---: | ---: | ---: | --- | --- |
| tracee | FAIL | yes | `4553.378272669419` | `4485.018762423089` | `0.9849870785705107` | FAIL | raw_tracepoint/kprobe `BPF_PROG_LOAD` dry-run `EINVAL`/`EACCES`; tracee known EINVAL path surfaced |
| tetragon | FAIL | yes | `2138.0075748213303` | `1970.0568662954513` | `0.9214452228776999` | FAIL | `bpfverify` failures across kprobe/tracepoint programs; ReJIT `2/287` applied |
| bpftrace | FAIL | yes | `8305.674984242925` | `7348.3820663394945` | `0.884742309358414` | FAIL | `tcplife` post-ReJIT `BPF_PROG_LOAD` dry-run `EACCES`; `5/6` records ok |
| bcc | FAIL | yes | `8452.604262634282` | `9297.000438012976` | `1.0998977533008902` | PASS | `opensnoop`, `capable`, `vfsstat`, `bindsnoop` verifier errors; `6/10` records ok |
| katran | FAIL | yes | `8968.65296393022` | `8905.436552803783` | `0.9929514040312767` | FAIL | xdp/sched_cls `bpfverify` and dry-run errors; ReJIT `0/3` applied |

The specific check "tetragon / katran / bcc / bpftrace completed and ratio did not regress" is **FAIL**: all four completed, but only `bcc` had ratio >= `1.0`.

## Micro

`vm-micro SAMPLES=3` passed.

| Metric | Value |
| --- | ---: |
| suite | `micro_staged_codegen` |
| benchmarks | `62` |
| completed benchmarks | `62` |
| samples | `3` |
| correctness mismatches | `0` |
| llvmbpf/kernel exec ratio geomean | `0.4842962465087073` |
| ratio min | `0.2219804134929271` |
| ratio max | `2.237082066869301` |

Micro emitted measurement-environment warnings for CPU governor, turbo boost, `perf_event_paranoid=2`, and no CPU affinity. These did not fail the suite.

## 12-Pass Coverage

The rebuilt smoke exercised the default benchmark pass list found in result artifacts. That list contains 11 passes; `branch_flip` is not in the default benchmark profile and still requires PGO/profile input. The saved artifact proves enabled-pass coverage of `11/12`, which meets the requested `>=9/12` threshold if "coverage" means pass requested in the default ReJIT pipeline.

Applied-site coverage is **inconclusive** from this compact artifact: successful applied program details retain aggregate `program_counts.applied`, but do not retain per-pass `sites_applied` for the changed programs. The preserved detailed pass reports are from noop/error program records and all show zero applied sites.

| Pass | Enabled in rebuilt smoke | Preserved applied-site evidence | Notes |
| --- | --- | ---: | --- |
| wide_mem | yes | `0` | successful applied-site details not persisted |
| rotate | yes | `0` | kinsn module loaded |
| cond_select | yes | `0` | kinsn module loaded |
| extract | yes | `0` | kinsn module loaded |
| endian_fusion | yes | `0` | kinsn module loaded |
| map_inline | yes | `0` | enabled with plan B live-value fixes |
| const_prop | yes | `0` | successful applied-site details not persisted |
| dce | yes | `0` | successful applied-site details not persisted |
| bounds_check_merge | yes | `0` | successful applied-site details not persisted |
| skb_load_bytes_spec | yes | `0` | successful applied-site details not persisted |
| bulk_memory | yes | `0` | kinsn module loaded |
| branch_flip | no | `0` | not in default benchmark profile; PGO-dependent |

Coverage summary:

- Enabled-pass coverage: **PASS**, `11/12`.
- Applied-site coverage: **INCONCLUSIVE**, because the compact result artifact does not preserve per-pass applied-site data for changed programs.
- Aggregate application: **PASS**, corpus applied `28` programs, so ReJIT application is not globally zero.

## Blockers

- e2e daemon early exit from the old smoke is resolved.
- Corpus still fails overall because 11 corpus app runs reported verifier/ReJIT errors.
- E2E still fails overall because all five cases reported verifier/ReJIT errors after reaching workload artifacts.
- No panic was observed.
- No source fixes were made in this run.
