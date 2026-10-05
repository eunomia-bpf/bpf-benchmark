# New Image Corpus Results - 2026-04-27

Source artifact:
`corpus/results/x86_kvm_corpus_20260428_053606_121660/details/result.json`

Comparator artifact for the `1.125x` baseline:
`corpus/results/x86_kvm_corpus_20260428_021257_300217/details/result.json`
as documented in `docs/tmp/per-program-analysis-20260427.md`.

Notes:

- The root result directory did not contain `result.json`; the completed artifact was written as `details/result.json`.
- QEMU PID `3228454` was monitored every 2 minutes. It exited at `2026-04-27T23:20:06-07:00`.
- No app result files appeared during the run. `details/result.json` and `details/result.md` appeared only at completion.
- Ratio is `post_rejit_avg_ns_per_run / baseline_avg_ns_per_run`; values below `1.0` are faster after ReJIT.
- The top-level result status is `error`, but the payload contains a generated `per_program` summary.

## Headline

| metric | current run | previous 1.125x artifact |
|---|---:|---:|
| samples | 30 | 1 |
| status | error | error |
| ok/error app cases | 8 / 14 | 20 / 2 |
| comparable programs | 78 | 157 |
| per-program geomean | 0.971 | 1.125 |
| wins / losses | 20 / 58 | 47 / 110 |

Directly comparing geomeans, the current run moved from `1.125x` to `0.971x`, a relative ratio drop of `13.7%`. In plain terms, the previous artifact was `12.5%` slower after ReJIT, while this artifact is `2.9%` faster by per-program geomean.

This comparison is not clean enough for a final performance claim: the comparable program set dropped from 157 to 78, and app-case failures increased from 2 to 14. The result is useful for debugging the new image/workload behavior, but it is not an authoritative corpus performance result.

## App Family Summary

| family | app cases ok/error | programs | geomean | wins/losses |
|---|---:|---:|---:|---:|
| bcc | 3 / 7 | 6 | 0.613 | 5 / 1 |
| bpftrace | 2 / 4 | 3 | 1.042 | 0 / 3 |
| calico | 1 / 0 | 1 | 0.984 | 1 / 0 |
| cilium | 0 / 1 | 0 |  | 0 / 0 |
| katran | 1 / 0 | 1 | 1.185 | 0 / 1 |
| otelcol-ebpf-profiler | 1 / 0 | 2 | 0.603 | 2 / 0 |
| tetragon | 0 / 1 | 0 |  | 0 / 0 |
| tracee | 0 / 1 | 65 | 1.022 | 12 / 53 |

Tracee dominates the comparable rows: 65 of 78 programs. Its workload ops were stable, but its byte-delta subset still regressed slightly.

## App Case Program Counts

`requested/applied/not` comes from `rejit_result.program_counts`. `comparable` is the number of programs included in the generated `per_program` summary.

| app case | status | requested/applied/not | comparable | geomean | wins/losses | changed |
|---|---|---:|---:|---:|---:|---|
| bcc/bindsnoop | error |  | 0 |  | 0 / 0 |  |
| bcc/biosnoop | ok | 3 / 3 / 0 | 3 | 0.430 | 3 / 0 | true |
| bcc/capable | ok | 1 / 1 / 0 | 1 | 0.677 | 1 / 0 | true |
| bcc/execsnoop | error |  | 0 |  | 0 / 0 |  |
| bcc/opensnoop | error |  | 0 |  | 0 / 0 |  |
| bcc/runqlat | error |  | 0 |  | 0 / 0 |  |
| bcc/syscount | ok | 2 / 2 / 0 | 2 | 0.996 | 1 / 1 | false |
| bcc/tcpconnect | error |  | 0 |  | 0 / 0 |  |
| bcc/tcplife | error |  | 0 |  | 0 / 0 |  |
| bcc/vfsstat | error |  | 0 |  | 0 / 0 |  |
| bpftrace/biosnoop | ok | 2 / 2 / 0 | 2 | 1.040 | 0 / 2 | false |
| bpftrace/capable | ok | 1 / 1 / 0 | 1 | 1.046 | 0 / 1 | false |
| bpftrace/runqlat | error |  | 0 |  | 0 / 0 |  |
| bpftrace/tcplife | error |  | 0 |  | 0 / 0 |  |
| bpftrace/tcpretrans | error |  | 0 |  | 0 / 0 |  |
| bpftrace/vfsstat | error |  | 0 |  | 0 / 0 |  |
| calico/felix | ok | 6 / 6 / 0 | 1 | 0.984 | 1 / 0 | false |
| cilium/agent | error |  | 0 |  | 0 / 0 |  |
| katran | ok | 3 / 3 / 0 | 1 | 1.185 | 0 / 1 | false |
| otelcol-ebpf-profiler/profiling | ok | 13 / 13 / 0 | 2 | 0.603 | 2 / 0 | false |
| tetragon/observer | error |  | 0 |  | 0 / 0 |  |
| tracee/monitor | error | 158 / 157 / 1 | 65 | 1.022 | 12 / 53 | true |

## Workload Ops Stability

Only app cases with baseline and post-ReJIT workload records are shown. Stable means absolute ops delta is at most `10%`.

| app case | workload | status | comparable | baseline ops | post-ReJIT ops | delta | stable |
|---|---|---|---:|---:|---:|---:|---|
| bcc/biosnoop | fio_randrw | ok | 3 | 382366 | 2242839 | +486.6% | no |
| calico/felix | network | ok | 1 | 11738 | 41399 | +252.7% | no |
| bcc/capable | stress_ng_os | ok | 1 | 164822 | 178436 | +8.3% | yes |
| bcc/syscount | stress_ng_os | ok | 2 | 167841 | 179416 | +6.9% | yes |
| bpftrace/biosnoop | fio_randrw | ok | 2 | 2064865 | 2172741 | +5.2% | yes |
| katran | test_run | ok | 1 | 43264 | 40960 | -5.3% | yes |
| bpftrace/capable | stress_ng_os | ok | 1 | 180082 | 179548 | -0.3% | yes |
| otelcol-ebpf-profiler/profiling | stress_ng_cpu | ok | 2 | 60150 | 60150 | +0.0% | yes |
| tracee/monitor | stress_ng_os | error | 65 | 186720 | 186720 | +0.0% | yes |

Summary: 7 of 9 measurable app cases were stable by ops. The two unstable cases are large enough to make their per-program ratios suspect. Tracee is the important exception: workload ops were exactly matched, yet its byte-delta subset regressed.

## Bytes JIT Delta / Applied Signal

Apps with at least one comparable program where `bytes_jited_delta != 0`:

| app case | programs with byte delta | sum bytes_jited_delta | geomean | wins/losses |
|---|---:|---:|---:|---:|
| bcc/biosnoop | 1 | -2 | 0.099 | 1 / 0 |
| bcc/capable | 1 | +3 | 0.677 | 1 / 0 |
| tracee/monitor | 53 | -9653 | 1.035 | 11 / 42 |

Overall split:

| subset | programs | geomean | wins/losses |
|---|---:|---:|---:|
| `bytes_jited_delta != 0` | 55 | 0.984 | 13 / 42 |
| `bytes_jited_delta == 0` | 23 | 0.943 | 7 / 16 |

The byte-delta subset is slightly faster overall, but this is mostly pulled by BCC rows. Tracee is the better ReJIT signal because its workload ops were stable and it has most of the changed programs; tracee byte-delta rows are `1.035x`.

## Bpftrace Discovery

Current bpftrace comparable programs:

| app case | status | baseline BPF records | post-ReJIT BPF records | comparable | names |
|---|---|---:|---:|---:|---|
| bpftrace/biosnoop | ok | 2 | 2 | 2 | `block_io_done`, `block_io_start` |
| bpftrace/capable | ok | 1 | 1 | 1 | `cap_capable` |
| bpftrace/runqlat | error | 0 | 0 | 0 |  |
| bpftrace/tcplife | error | 0 | 0 | 0 |  |
| bpftrace/tcpretrans | error | 0 | 0 | 0 |  |
| bpftrace/vfsstat | error | 0 | 0 | 0 |  |

The previous `1.125x` artifact had 9 bpftrace comparable programs across 5 app cases: biosnoop 2, capable 1, runqlat 3, tcplife 1, and vfsstat 2.

This run does not validate the intended no-name-hint bpftrace discovery improvement. The failed bpftrace app cases produced zero baseline/post BPF records because their workloads failed before comparable measurement, not because a name hint filtered programs out.

## Error Surface

The result surfaced errors instead of filtering them:

- `exec` stressor cannot run as root: `bcc/execsnoop`, `bcc/runqlat`, `bpftrace/runqlat`.
- `dccp` stressor unsupported: `bcc/bindsnoop`, `bcc/tcpconnect`, `bcc/tcplife`, `tetragon/observer`, `bpftrace/tcplife`, `bpftrace/tcpretrans`.
- filesystem stressor timeout: `bcc/vfsstat`, `bcc/opensnoop`, `bpftrace/vfsstat`.
- BPF stats read failure: `cilium/agent`.
- ReJIT EINVAL surfaced naturally: `tracee/monitor` program 689.

## Payload Shape Checks

The ReJIT result payloads no longer contain the old redundant fields such as `applied_site_totals` or `output_chars`. Successful app cases now carry only `applied`, `changed`, `enabled_passes`, `error`, `exit_code`, and `program_counts`; Tracee also carries `error_programs`.

The VM guest script used the runtime image with only `corpus/results` and system paths mounted into Docker. It did not bind mount the host workspace into the runtime container.

## Interpretation

The current new-image run is directionally better than the previous `1.125x` artifact by the generated per-program geomean, but the run itself is not clean: too many app cases failed, and bpftrace discovery coverage got worse because workload failures prevented measurement.

The most actionable finding is workload-driver breakage from running individual fixed stressors. `exec` and `dccp` are invalid in this environment, and some filesystem stressors time out. Until those workload errors are fixed, this artifact should not replace the previous authoritative corpus result.
