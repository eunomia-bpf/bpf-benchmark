# Step 0048 — KVM corpus `tracee/monitor` at `65a34c7cd`

Date: 2026-09-30 UTC (make launch 03:48:34Z; in-VM suite
2026-09-30T03:53:20 → 04:00:32Z; VM power-down 04:00:40Z)

## Scope

Fifth corpus-app increment on the KVM line, the first *process-tracer*
app (tracepoint/kprobe/raw-tracepoint attachments, vs. the network
XDP/skb corpus apps `katran`, `bcc/set`, `cilium/agent` already
evidenced): `BPFREJIT_CORPUS_APPS="tracee/monitor" make corpus` —
default `PLATFORM=kvm ARCH=x86`, default policy (`SAMPLES=3`,
`WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`), zero extra env vars.
HEAD `65a34c7cd` (= `origin/master` after step 0047). x86 image cached
from the step 0041 build. Tracee boots a full `tracee monitor` BPF
graph (151 programs) and the `stress_ng_tracee_syscall_hot` workload
drives syscalls through a 7-stressor `stress-ng` run, exercising the
two-start load-time ReJIT protocol on a real, multi-attachment
(kprobe + raw_tracepoint + tracepoint) BPF graph.

## Result

- Run `corpus/results/x86_kvm_corpus_20260930_035320_255208/`
  `metadata.json` `status: completed` (`progress.json` status
  `completed`); suite `details/result.json` `status: ok`,
  `suite_name: macro_apps`, `samples: 3`. App `details/apps/
  tracee__monitor.json` `status: ok`, `error: ''`.
- `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]`, `selected_workload: stress_ng_tracee_syscall_hot`,
  `runner: tracee`.
- **151 BPF programs** recorded per start (baseline and post_rejit) —
  the largest program count of the session (vs. 53 for cilium). 56
  programs had a nonzero `run_cnt_delta` per start. The full 151-program
  table (all names/types/ids + all four counters) is preserved verbatim
  in `details/apps/tracee__monitor.json` (tracked into git this step).
  Top hot programs by `run_cnt_delta` (raw two-start BPF counters, raw
  only, no ratios; in-VM ids differ between starts so the pairs are
  matched by `name`):

  | program (name, id) | start | `run_cnt_delta` | `run_time_ns_delta` | `bytes_jited` | `bytes_xlated` |
  |---|---|---|---|---|---|
  | `tracepoint__raw_sys_enter` (id 19) | baseline | 248,150,238 | 98,946,033,709 | 8,194 | 13,768 |
  | `tracepoint__raw_sys_exit` (id 20) | baseline | 248,150,245 | 100,255,357,349 | 8,227 | 13,824 |
  | `tracepoint__raw_sys_enter` (id 373) | post_rejit | 245,748,172 | 97,468,963,109 | 7,593 | 11,976 |
  | `tracepoint__raw_sys_exit` (id 386) | post_rejit | 245,748,176 | 96,695,526,877 | 7,618 | 12,016 |
  | `trace_ret_vfs_read` (id 99) | baseline | 26,831,607 | 16,952,575,632 | 19,031 | 31,504 |
  | `trace_ret_vfs_read` (id 1263) | post_rejit | 27,000,454 | 17,052,628,007 | 19,031 | 31,504 |
  | `trace_ret_vfs_write` (id 85) | baseline | 6,636,561 | 4,141,436,590 | 19,028 | 31,504 |
  | `trace_ret_vfs_write` (id 1111) | post_rejit | 6,688,343 | 4,247,010,022 | 19,028 | 31,504 |

  - `bytes_jited` dropped for the two hottest sys_enter/sys_exit
    tracepoint progs (8,194/8,227 → 7,593/7,618) and the security
    kprobe progs after the ReJIT pass chain; full per-program detail is
    in the tracked JSON.
- Raw app-side workload counters (`stress_ng_tracee_syscall_hot`,
  7-stressor `stress-ng` run, all six runs `rc=0`, `failed: 0`,
  `metrics untrustworthy: 0`; per-stressor raw bogo-ops, raw only):

  | stressor | baseline s0 | baseline s1 | baseline s2 | post_rejit s0 | post_rejit s1 | post_rejit s2 |
  |---|---|---|---|---|---|---|
  | cap | 1,846,802 | 1,797,365 | 1,923,882 | 1,875,575 | 1,863,837 | 1,808,564 |
  | set | 151,535 | 154,866 | 152,477 | 151,571 | 150,084 | 151,152 |
  | sigfd | 4,568,349 | 4,517,945 | 4,672,999 | 4,566,239 | 4,743,076 | 4,516,371 |
  | eventfd | 1,091,014 | 1,085,741 | 1,090,194 | 1,103,945 | 1,093,747 | 1,094,724 |
  | kill | 823,490 | 836,935 | 812,020 | 820,893 | 765,786 | 794,342 |
  | futex | 4,328,636 | 4,394,750 | 4,483,028 | 4,406,154 | 4,525,774 | 4,478,158 |
  | prctl | 11,786 | 8,708 | 8,099 | 8,150 | 9,724 | 9,980 |

  - No ratio, geomean, or win/loss tally is computed here — any
    cross-start comparison is analysis per `rejit/docs/evaluation.md` §5.

## Evidence pointers

- `run-marker.txt` (this dir); the retained 455-line host log is
  `make-corpus.log` (copied in after completion).
- `corpus/results/x86_kvm_corpus_20260930_035320_255208/` run dir:
  tracked `metadata.json`, `details/result.json`, `details/progress.json`,
  `details/apps/tracee__monitor.json`, `details/loadtime-reports/
  tracee__monitor.jsonl`; `details/shim-logs/` and `details/
  loadtime-plans/` stay ignored.

## Caveats

- In-VM BPF program ids differ between the two starts (e.g. 19/20 →
  373/386 for `tracepoint__raw_sys_enter`/`_exit`), so hot progs are
  matched by `name`, not id. Program `name` strings are stored
  truncated to 16 chars (kernel convention).
- Single app (`tracee/monitor`); the remaining corpus apps
  (`tetragon/observer`, `otelcol-ebpf-profiler/profiling`) are out of
  scope for this increment.
- `SAMPLES=3` is the default (a full variance sample).
- Raw two-start counters + raw workload counters only; no ratio /
  geomean / rollup in the framework — analysis per `rejit/docs/evaluation.md`
  §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from the step
  0041 build. Paper-B speculative evidence stays blocked.

## Open

- `PLATFORM=aws ARCH=arm64` corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host. Genuine
  external blocker; resume when credentials land.
