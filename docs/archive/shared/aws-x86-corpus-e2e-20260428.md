# AWS x86 Corpus and E2E Results - 2026-04-28

Target: `aws-x86` / `x86_64`

## Run Notes

- Corpus attempt 1 failed during `tracee` ReJIT because the daemon client timed out after 120s while the daemon was still making progress.
- The daemon request fallback timeout was raised to 600s in `runner/libs/rejit.py`, with `BPFREJIT_DAEMON_REQUEST_TIMEOUT_S` as an override.
- Corpus attempt 2 completed measurements and wrote results. `make` returned nonzero because `tracee/monitor` surfaced the known `EINVAL`.
- E2E attempt 1 failed before the AWS benchmark started: local `docker save` hit `no space left on device`. Failed `.tmp-x86_64-runner-runtime.image.tar*` files were removed.
- E2E attempt 2 completed all cases. `make` returned nonzero because `tracee` surfaced the known `EINVAL`; `tetragon`, `bpftrace`, `bcc`, and `katran` were OK.

Artifacts:

- Corpus: `corpus/results/aws_x86_corpus_20260428_184822_640612/details/result.json`
- Corpus remote log: `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.54d84e2d_20260428_184819.remote.log`
- E2E remote log: `.cache/aws-x86/results/logs/e2e_run.aws-x86.e2e.43ae2002_20260428_202225.remote.log`
- E2E results:
  - `e2e/results/tracee_20260428_202228_130325/details/result.json`
  - `e2e/results/tetragon_20260428_203353_300654/details/result.json`
  - `e2e/results/bpftrace_20260428_204855_642339/details/result.json`
  - `e2e/results/bcc_20260428_205037_731222/details/result.json`
  - `e2e/results/katran_20260428_205509_175611/details/result.json`

## Corpus Summary

Corpus status: `error` due to known `tracee` `EINVAL`.

For corpus, ratio semantics are `post_rejit_avg / baseline_avg`; lower than 1.0 means faster after ReJIT.

| metric | value |
| --- | ---: |
| per_program_geomean | 0.9820106488194009 |
| wins | 61 |
| losses | 87 |
| program_count | 148 |

## Corpus App Status

| app | runner | status | error |
| --- | --- | --- | --- |
| bcc/capable | bcc | ok |  |
| bcc/execsnoop | bcc | ok |  |
| bcc/bindsnoop | bcc | ok |  |
| bcc/biosnoop | bcc | ok |  |
| bcc/vfsstat | bcc | ok |  |
| bcc/opensnoop | bcc | ok |  |
| bcc/syscount | bcc | ok |  |
| bcc/tcpconnect | bcc | ok |  |
| bcc/tcplife | bcc | ok |  |
| bcc/runqlat | bcc | ok |  |
| calico/felix | calico | ok |  |
| otelcol-ebpf-profiler/profiling | otelcol-ebpf-profiler | ok |  |
| cilium/agent | cilium | ok |  |
| tetragon/observer | tetragon | ok |  |
| katran | katran | ok |  |
| tracee/monitor | tracee | error | prog 714: BPF_PROG_REJIT: Invalid argument (os error 22) |
| bpftrace/capable | bpftrace | ok |  |
| bpftrace/biosnoop | bpftrace | ok |  |
| bpftrace/vfsstat | bpftrace | ok |  |
| bpftrace/runqlat | bpftrace | ok |  |
| bpftrace/tcplife | bpftrace | ok |  |
| bpftrace/tcpretrans | bpftrace | ok |  |

## E2E Case Status

| case | status | note |
| --- | --- | --- |
| tracee | error | known `EINVAL`: cycle 0 prog 189, cycle 1 prog 706 |
| tetragon | ok |  |
| bpftrace | ok |  |
| bcc | ok |  |
| katran | ok |  |

## E2E Performance

For E2E throughput ratios, `ratio = post_rejit / baseline`; higher than 1.0 means higher workload throughput after ReJIT.

| case | status | metric | baseline | post_rejit | ratio | error |
| --- | --- | --- | ---: | ---: | ---: | --- |
| tracee | error | stress_ng_os mean ops/s | 678.815657 | 691.923375 | 1.019310 | cycle 0: prog 189: BPF_PROG_REJIT: Invalid argument (os error 22); cycle 1: prog 706: BPF_PROG_REJIT: Invalid argument (os error 22) |
| tetragon | ok | stress_ng_os_io_network ops/s | 677.612049 | 831.544645 | 1.227169 |  |
| bpftrace/tcplife | ok | ops/s | 4906.706674 | 3203.854315 | 0.652954 |  |
| bpftrace/biosnoop | ok | ops/s | 5450.714760 | 5690.420738 | 1.043977 |  |
| bpftrace/runqlat | ok | ops/s | 1072.327650 | 1069.010718 | 0.996907 |  |
| bpftrace/tcpretrans | ok | ops/s | 5081.004832 | 5097.125843 | 1.003173 |  |
| bpftrace/capable | ok | ops/s | 2165.758395 | 2266.877341 | 1.046690 |  |
| bpftrace/vfsstat | ok | ops/s | 511.770058 | 520.298788 | 1.016665 |  |
| bcc/tcplife | ok | ops/s | 4980.923172 | 5050.187781 | 1.013906 |  |
| bcc/biosnoop | ok | ops/s | 5687.353724 | 4271.888449 | 0.751121 |  |
| bcc/runqlat | ok | ops/s | 555.562397 | 554.966735 | 0.998928 |  |
| bcc/syscount | ok | ops/s | 4619.519757 | 4772.824457 | 1.033186 |  |
| bcc/execsnoop | ok | ops/s | 554.825302 | 554.988620 | 1.000294 |  |
| bcc/opensnoop | ok | ops/s | 375.697843 | 381.939798 | 1.016614 |  |
| bcc/capable | ok | ops/s | 4676.194310 | 4540.795104 | 0.971045 |  |
| bcc/vfsstat | ok | ops/s | 384.344616 | 377.057622 | 0.981040 |  |
| bcc/tcpconnect | ok | ops/s | 5072.737313 | 5005.889048 | 0.986822 |  |
| bcc/bindsnoop | ok | ops/s | 3324.217495 | 4912.991996 | 1.477939 |  |
| katran | ok | ops/s | 681.638215 | 959.399866 | 1.407491 |  |
