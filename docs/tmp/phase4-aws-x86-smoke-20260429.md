# Phase4 AWS x86 Functional Smoke - 2026-04-29

Requested baseline: `5fbe934b` (`fix(bpfopt, daemon): hash null is legitimate skip; scan-map-keys covers LD_IMM64 PSEUDO_MAP_VALUE`). The branch advanced during parallel work before this report was written; no source or v3 design document changes were made by this smoke run.

Overall result: **FAIL** for benchmark suites, **PASS** for `aws-x86-test`. AWS remote build/packaging, image push/load, instance boot, kernel install, and result sync all executed. The corpus and e2e suites produced results but returned nonzero because ReJIT/verify errors surfaced naturally in app results. No panic, Python traceback, or segfault was found in the local or remote logs.

## Commands

The requested shorthand make targets do not exist in this checkout:

| Command | Exit | Note |
| --- | ---: | --- |
| `make aws-x86-corpus SAMPLES=1` | 2 | `No rule to make target 'aws-x86-corpus'` |
| `make aws-x86-e2e SAMPLES=1` | 2 | `No rule to make target 'aws-x86-e2e'` |

Canonical AWS targets were used:

| Step | Command | Exit | Result | Artifact |
| --- | --- | ---: | --- | --- |
| corpus | `source /home/yunwei37/workspace/.venv/bin/activate && make aws-x86-benchmark AWS_X86_BENCH_MODE=corpus AWS_X86_BENCH_SAMPLES=1` | 2 | results produced; suite failed on recorded ReJIT/verify errors | `corpus/results/aws_x86_corpus_20260429_114243_566474` |
| e2e | `source /home/yunwei37/workspace/.venv/bin/activate && make aws-x86-benchmark AWS_X86_BENCH_MODE=e2e` | 2 | all five case result dirs produced; suite failed on recorded ReJIT/verify errors | `e2e/results/*_20260429_12*` / `*_13*` |
| test | `source /home/yunwei37/workspace/.venv/bin/activate && make aws-x86-test` | 0 | PASS | `tests/results/run.aws-x86.test.f2b70fff` |

Run logs:

- `/tmp/bpf-benchmark-phase4-aws-x86-20260429/aws-x86-corpus.log`
- `/tmp/bpf-benchmark-phase4-aws-x86-20260429/aws-x86-e2e.log`
- `/tmp/bpf-benchmark-phase4-aws-x86-20260429/aws-x86-test.log`
- `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.42054b44_20260429_114240.remote.log`
- `.cache/aws-x86/results/logs/e2e_run.aws-x86.e2e.2cf43c71_20260429_125537.remote.log`

## AWS Path

Observed for corpus and e2e:

- daemon binary target checked/reused: `daemon/target/release/bpfrejit-daemon`
- runtime image checked/reused or rebuilt, then transferred to EC2 and `docker load`ed
- EC2 benchmark instances booted as `t3.medium`
- kernel `7.0.0-rc2` and modules installed, instance rebooted, 2 GiB swap configured
- benchmark containers ran with real app startup and synced results back

`aws-x86-test` used the default test target contract (`t3.micro`), installed the same kernel, synced `tests/results/run.aws-x86.test.f2b70fff/run-contract.json`, and exited 0.

## Corpus

Corpus status: `error`. Results were written to `corpus/results/aws_x86_corpus_20260429_114243_566474/details/result.json`.

| Metric | Value |
| --- | ---: |
| per_program_geomean | 0.8969242364687509 |
| historical geomean, 2026-04-28 | 0.9820106488194009 |
| relative change vs historical | -8.66% |
| program_count | 136 |
| wins | 61 |
| losses | 75 |
| requested ReJIT programs | 519 |
| final ReJIT applied programs | 28 |
| final ReJIT not_applied programs | 491 |

Kinsn module load was OK: `bpf_bulk_memory`, `bpf_endian`, `bpf_extract`, `bpf_rotate`, and `bpf_select` were resident; `failed_modules=[]`.

Corpus app status:

| App | Status | Requested | Applied | Not Applied |
| --- | --- | ---: | ---: | ---: |
| bcc/capable | error | 1 | 0 | 1 |
| bcc/execsnoop | ok | 2 | 0 | 2 |
| bcc/bindsnoop | error | 3 | 0 | 3 |
| bcc/biosnoop | ok | 3 | 1 | 2 |
| bcc/vfsstat | error | 5 | 0 | 5 |
| bcc/opensnoop | error | 3 | 0 | 3 |
| bcc/syscount | ok | 2 | 0 | 2 |
| bcc/tcpconnect | ok | 3 | 0 | 3 |
| bcc/tcplife | ok | 1 | 1 | 0 |
| bcc/runqlat | ok | 3 | 1 | 2 |
| calico/felix | error | 6 | 0 | 6 |
| otelcol-ebpf-profiler/profiling | error | 13 | 0 | 13 |
| cilium/agent | error | 16 | 6 | 10 |
| tetragon/observer | error | 287 | 2 | 285 |
| katran | error | 3 | 0 | 3 |
| tracee/monitor | error | 158 | 13 | 145 |
| bpftrace/capable | ok | 1 | 1 | 0 |
| bpftrace/biosnoop | ok | 2 | 1 | 1 |
| bpftrace/vfsstat | ok | 2 | 0 | 2 |
| bpftrace/runqlat | ok | 3 | 1 | 2 |
| bpftrace/tcplife | error | 1 | 0 | 1 |
| bpftrace/tcpretrans | ok | 1 | 1 | 0 |

Verifier/ReJIT errors were recorded in the artifact, not hidden:

| Reason | Count in corpus JSON |
| --- | ---: |
| `BPF_PROG_LOAD dry-run failed: Invalid argument (os error 22)` | 462 |
| `BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)` | 264 |
| `BPF_PROG_REJIT: Invalid argument (os error 22)` | 3 |

## 12 Pass Coverage

The benchmark config enabled 11 passes. `branch_flip` remains a registered pass but is not in `corpus/config/benchmark_config.yaml` default policy. The persisted AWS artifact compacts successful/error per-program ReJIT details and only preserves detailed pass summaries for no-op program records; those preserved pass summaries had zero observed sites. The table therefore reports the saved-artifact coverage surface, while final program application is represented by `program_counts.applied=28`.

| Pass | Enabled in benchmark config | Programs with sites in saved summaries | Sites applied in saved summaries | Coverage |
| --- | --- | ---: | ---: | --- |
| wide_mem | yes | 0 | 0 | FAIL |
| rotate | yes | 0 | 0 | FAIL |
| cond_select | yes | 0 | 0 | FAIL |
| extract | yes | 0 | 0 | FAIL |
| endian_fusion | yes | 0 | 0 | FAIL |
| map_inline | yes | 0 | 0 | FAIL |
| const_prop | yes | 0 | 0 | FAIL |
| dce | yes | 0 | 0 | FAIL |
| bounds_check_merge | yes | 0 | 0 | FAIL |
| skb_load_bytes_spec | yes | 0 | 0 | FAIL |
| bulk_memory | yes | 0 | 0 | FAIL |
| branch_flip | no | 0 | 0 | FAIL |

Coverage summary: 0/12 registry passes had observable site hits in the saved compact summaries; 0/11 configured passes had observable site hits there. This is a reporting/coverage check failure for this smoke artifact, not evidence that no program changed, because the corpus result separately records 28 applied programs.

## E2E

All requested e2e case result directories were produced:

- `e2e/results/tracee_20260429_125540_177019/details/result.json`
- `e2e/results/tetragon_20260429_130536_109650/details/result.json`
- `e2e/results/bpftrace_20260429_132109_905286/details/result.json`
- `e2e/results/bcc_20260429_132249_980380/details/result.json`
- `e2e/results/katran_20260429_132720_149345/details/result.json`

Top-level case status and ratio:

| Case | Status | Baseline | Post-ReJIT | Ratio | Historical ratio | Note |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| tracee | error | 667.908370 | 695.462715 | 1.041255 | 1.019310 | mean app throughput across 2 cycles; post phase status error |
| tetragon | error | 702.020493 | 717.080289 | 1.021452 | 1.227169 | completed result; post phase status error |
| bpftrace | error | n/a | n/a | 0.995930 | n/a | geomean across 6 tool ratios; 5 ok, 1 error |
| bcc | error | n/a | n/a | 0.973453 | n/a | geomean across 10 tool ratios; 6 ok, 4 error |
| katran | error | 757.204472 | 1051.261582 | 1.388346 | 1.407491 | completed result; post phase status error |

Compared with the 2026-04-28 historical e2e run, tetragon moved from +22.7% to +2.1% and changed from `ok` to `error`; katran moved from +40.7% to +38.8% and changed from `ok` to `error`.

Detailed bpftrace and bcc ratios:

| Case | Tool | Status | Baseline | Post-ReJIT | Ratio |
| --- | --- | --- | ---: | ---: | ---: |
| bpftrace | tcplife | error | 3803.614284 | 3846.736473 | 1.011337 |
| bpftrace | biosnoop | ok | 5392.674679 | 5669.371039 | 1.051310 |
| bpftrace | runqlat | ok | 1072.824689 | 1072.594902 | 0.999786 |
| bpftrace | tcpretrans | ok | 5038.199221 | 5034.586474 | 0.999283 |
| bpftrace | capable | ok | 2379.414912 | 2212.595595 | 0.929891 |
| bpftrace | vfsstat | ok | 559.330727 | 552.568814 | 0.987911 |
| bcc | tcplife | ok | 5044.105800 | 5150.019286 | 1.020997 |
| bcc | biosnoop | ok | 4262.548565 | 5724.906828 | 1.343071 |
| bcc | runqlat | ok | 554.115209 | 555.336269 | 1.002204 |
| bcc | syscount | ok | 5002.181366 | 5010.866774 | 1.001736 |
| bcc | execsnoop | ok | 555.280567 | 555.002059 | 0.999498 |
| bcc | opensnoop | error | 386.425024 | 385.086632 | 0.996536 |
| bcc | capable | error | 4653.798021 | 4363.967352 | 0.937722 |
| bcc | vfsstat | error | 376.838046 | 389.546961 | 1.033725 |
| bcc | tcpconnect | ok | 4991.236135 | 3797.547911 | 0.760843 |
| bcc | bindsnoop | error | 5012.179695 | 3786.991182 | 0.755558 |

## Test Target

`make aws-x86-test` completed with exit 0. It synced `tests/results/run.aws-x86.test.f2b70fff/run-contract.json`, installed and booted kernel `7.0.0-rc2`, and terminated the EC2 instance cleanly.

## Error Summary

- Corpus produced a result JSON and per-program summary, but suite status was `error`.
- E2E produced result JSONs for tracee, tetragon, bpftrace, bcc, and katran, but all five top-level statuses were `error`.
- The 12-pass coverage check did not pass in the saved compact summaries; benchmark default still enables 11 passes and excludes `branch_flip`.
- No panic, Python traceback, segfault, Docker build failure, AWS boot failure, or result-sync failure was observed.
