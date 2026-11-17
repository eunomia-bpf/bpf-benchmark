# Do the two arms run the same programs as often?

Operator 2026-11-16: "为啥一直路径不同?什么原因?哪里出bug?" and "我们是不是所有程序都走一样的路径? 路径正确吗?"

`paths.py` reads the per-program `run_cnt_delta` of both arms in stats-on runs and lists every program whose native/eBPF run ratio leaves 0.7x-1.3x of the app's median ratio, or that runs in one arm only. Output: `result.txt`.

Measured 2026-11-16T14:11:00Z:

- OTel (125155_179400, 053859_493069), Katran (072549_683704), Tracee (20261114_085217_843248, 24 of 24 programs): the arms run the same programs in proportion.
- Cilium (063056_107201): the native arm runs cil_to_host and cil_from_host once per packet (740,557,968 each); the eBPF arm runs them 4 and 2 times. Different packet path.
- BCC (060435_731340): 7 of 11 programs track the median 1.293; sched_switch and sched_wakeup run 2.51x as often in the native arm (176,296,084 vs 70,242,816), one instance each (program ids 76 and 180). These two are runqlat's tracing (tp_btf) programs, which keep a histogram in maps and emit no events. 2.51 / 1.293 = 1.94, so in the native arm each sched event most likely runs, or is counted, twice for this program type; "2.5 times as many context switches" was a wrong reading (corrected 2026-11-16T14:18:50Z); block_rq_* counts are small (1,800 vs 440).
- Tetragon: no stats-on run with the native side loaded yet.


## Correction (2026-11-16T15:43:46Z)

The reading "tracing programs run about twice per event in the native arm" is withdrawn. sched_wakeup_new is not doubled, the sched_switch : sched_wakeup ratio is 2.00 in both arms, and the next run on image 3a1906ab1 (131847_109569) has matching counts in both arms. The 2.51x most likely came from workload variation between the two arms of run 060435_731340. What the counts do show is a per-call cost: native sched_switch takes 180.2 ns against 129.6 ns for eBPF, with installed code 3,916 B against 935 B (kprog/results/perf-review-20261116).
## Measured on image 55c1c443 (2026-11-17, batch 2)

Six-app check runs (`kprog/results/leaf-batch2-20261117/summary.txt`), stats on, `paths.py` output in `result-20261117.txt`. Executing programs and median native/eBPF run ratio per app:

| app | run | executing | median ratio | note |
|---|---|---|---|---|
| OTel | 165519_616823 | 1 | 0.909 | 1 of 1 tracks |
| BCC | 165851_063935 | 9 | 0.897 | 9 of 9 track |
| Cilium | 170144_141033 | 1 | 0.985 | 1 of 1 tracks |
| Tetragon | 170444_997304 | 3 | 0.727 | `generic_tracepo` 31,719,545 -> 0; see the window artifact below |
| Tracee | 170828_760536 | 24 | 1.107 | 24 of 24 track |
| Katran | 171249_269819 | 1 | 0.996 | 1 of 1 tracks |

The whole-image ratios being below 1 in OTel, BCC and Tetragon is a count difference, not a different path: the same programs execute, and per-call cost is what the timing runs report (Tracee `171629_853367` throughput 1.383x, ns/inv 1.587x at a 1.401 run ratio; Cilium `172834_854761` 1.008x throughput, 1.099x ns/inv at 1.016), with installed code smaller in both (Tracee JIT 2,068,918 -> native 1,763,639 B, 0.85x; Cilium 581,577 -> 464,536 B, 0.80x).

**Cilium: the per-packet path difference is gone.** In `170144_141033` the baseline arm has 53 counter entries and 12,410,933 total runs, the native arm 62 entries and 12,220,197. `cil_to_netdev`, `cil_to_host` and `cil_from_host` run exactly 1 time in both arms (they ran 740,557,968 times each in the native arm of 063056_107201), and `cil_from_contai` carries the work in both (6,274,069 + 6,136,861 baseline, 6,145,489 + 6,074,708 native). The 2.8x unequal work is gone.

**Cilium: 16 leaf loads stay on eBPF** in `170144_141033` (8 `tail_drop_notif`, 6 `cil_host_policy`, 2 `cil_lxc_policy_`) against 83 substitutions; the timing run `172834_854761` has 22 (11/9/2) against 113. The loader's shim-log line is `no manifest match`. All of these leaves are cold in both arms (every retained entry has `run_cnt_delta` 0 in the check run, and 10 baseline entries of the same prefixes also report 0), so they cost no equal work — they only add installed programs. Cause unchanged and still open: `native_loader_manifest.hpp:626-630` selects an object by `source_map_prefix`, so leaves of these prefixes have no manifest entry at all. Inventory tool: `kprog/results/lto-review-20261117/native_coverage_inventory.py`; §11 of that directory's README.

**BCC: the sched doubling is an outlier, not a rule.** Across 225 `bcc__set` runs with `sched_switch` >= 1,000 in both arms, the ratio is p10 0.834, p50 0.999, p90 1.097; 4 runs exceed 1.5 (2.631, 2.510, 2.083, 1.605), matching the 15:43:46Z withdrawal. `block_rq_comple` / `block_rq_issue` with both arms >= 100 (n=99/97): p10 0.33, p50 1.01, p90 1.10. The counts are tiny — 107/99 baseline against 105/97 native in the check run — so the spread is noise on ~100 events, and the two arms run the same programs: all 9 executing programs in `165851_063935` track the median 0.897 to within 0.84-1.00.

**Tracee: one uniform per-call change.** In the timing run `171629_853367` all 24 executing programs have >= 1,000 runs and name-based ratios 1.188-1.480 (median 1.403): `tracepoint__raw` 1.480 at 735.9 M runs, `trace_sys_enter`/`trace_sys_exit` 1.480 at 367.9 M each, and the smallest populations at 1.188. No program is left behind. The check run `170828_760536` sits at median 1.107 (0.849-1.152) on the same program set. `trace_file_upda`, called out in item 2, is small-count noise: over 17 runs with >= 1,000 runs in both arms its ratio is p10 0.60, p50 1.02, p90 1.26, range 0.35-2.02 (`trace_ret_file_` alike, p50 1.02); the two hot programs have 338 and 273-observation distributions with p50 1.00.

**Tetragon: 287 entry populations against 184, and all 82 missing entries ran zero times.** Baseline `170444_997304`: 287 entries (231 `generic_kprobe_`, 36 `generic_retkpro`, 6 `generic_tracepo`, 7 `generic_rawtp_*`), 34 executing, 65,546,490 runs. Native: 184 entries (147/28/2/0), 21 executing, 24,077,941 runs. Every one of the 82 dropped entries has `run_cnt_delta` 0 in the baseline arm — they are cold programs whose manifest has no replacement, not lost work. Drop-in-program count: `generic_kprobe_` executing 22 -> 13, `generic_retkpro_` 6 -> 4. Where both arms keep all 287 entries the arms agree: `043157_792401`, `074317_231933`, `084929_629134` pair 27 executing programs at ratio p50 1.024-1.059 (range 0.889-1.337).

**Tetragon: the hot tracepoint's zero is a counter-window artifact.** `emit_measure_start` (`bpfopt/shim/shim_measure.h:48`) snapshots the `prog_table` entries; a program replaced after that snapshot gets a new kernel prog id whose `run_cnt` accumulates outside the snapshot, so it is reported at 0 for the window. In `170444_997304` the measurement window is 159.06-177.70 s and the hot `generic_tracepo` (`bytes_xlated` 26,568, baseline 31,719,545 runs) is replaced at 178.78 s, i.e. 1.08 s after `measure_finish`; the native arm's two remaining `generic_tracepo` entries (both `bytes_xlated` 24) report 0. Of the 288 substitutions, 158 landed before the window, 27 inside it (all but one report delta 0; the exception is a `generic_kprobe_` with 6 runs), and 103 after `measure_finish` (84 `generic_kprobe_`, 8 `generic_retkpro`, 4 `generic_tracepo`, 7 `generic_rawtp_*`). The whole load phase runs late in this arm: last program load 195.18 s against the baseline's 111.15 s, whose window is 105.16-115.23 s. Attach counts agree exactly (6 `RAW_TRACEPOINT_OPEN`, 54 `LINK_CREATE`; attach_type 42 `BPF_TRACE_KPROBE_MULTI`, 48 `BPF_TRACE_UPROBE_MULTI`, 41 `BPF_PERF_EVENT`, 27 `BPF_LSM_MAC`).

Across the 34 Tetragon runs with a non-zero baseline tracepoint count and a stats-on window, binning by the lead time between the hot tracepoint's own replacement (matched by its `bytes_xlated`, 26,568 here) and `measure_finish`, with counts normalized per workload event (stress-ng bogo ops of eventfd+udp+sockfd+sockpair):

| lead before window close | n | per-event native/eBPF |
|---|---|---|
| >= 30 s | 17 | 0.997-1.185, median 1.104 |
| 10-30 s | 1 | 0.298 |
| 3-10 s | 6 | 0.374-0.900, median 0.635 |
| 0-3 s | 4 | 0.028-0.134 |
| < 0 (after close) | 5 | 0.000 |
| no replacement of that program in the arm | 1 | 0.994 |

The correlation between the fraction of the window that follows the hot tracepoint's replacement and the per-event run ratio is 0.956 (n=33). The normalization also resolves the one run whose raw ratio misleads: `232218_353786` has raw ratio 0.058 but per-event 1.104, because its native-arm workload collapsed (eventfd 6,274,679 -> 232,712 bogo ops in the same 120 s). Rows at 3-10 s (`232540_669421` 0.560, `083929_625195` 0.374, `072157_986675` 0.623, `122045_221621` 0.648, `062009_586769` 0.840, `034829_591728` 0.900) show the same partial coverage in proportion to the lead.

**What this does and does not mean for the paper's equal-work check.** The arms run the same programs; the counter differences are (i) cold entries the manifest has no replacement for, and (ii) programs whose replacement lands at or after the window close, for which the counter window misses them entirely. Neither is a program left on JIT during the measured window. What it does mean is that in short-window runs (10-30 s here) the native arm's own load phase can overrun `measure_finish`, so per-program run ratios from such runs understate the native side and a longer workload or a later `measure_start` is required before quoting run ratios as equal work. Timing runs on this image used 180 s windows and report run ratios 1.016 (Cilium) and 1.401 (Tracee).
