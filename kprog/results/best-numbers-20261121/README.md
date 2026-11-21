# Best x86 numbers on the current system (2026-11-21, coordinator)

Operator 2026-11-21 ~09:1x UTC: "我们现在最好的数字是啥??? 看看"; 2026-11-18: "你要用历史上最好的数据作为合理的数据 … 功能正常就可以".

`best.py` scans every x86 run of 11-16..11-21 with the frozen settings (3 samples x 180 s, status ok) and takes each
app's maximum with the 05-29 parser (`raw-maxima.txt`, 82 runs). Maxima whose arms did different work are set aside,
with the receipt that shows it:

| Max in raw-maxima.txt | Set aside because |
|---|---|
| OTel per call 14.4x, throughput 1.866x / 2.020x (11-16) | the native path's unrolling did no work, as in 05-29's 1.849x (perf-history-review-20261120: 913,099,438 unroll attempts to 0) |
| Cilium per call 4.103x (11-16), stats off 3.564x (11-19 202033) | 11-16: natives built with the sample config, the eBPF arm with the agent's; 11-19: native packets also crossed cil_to_host, the sender ran about 3x the packets (todo, coordinator 2026-11-19T21:30:54Z) |
| Tetragon per call 2.790x, throughput 2.995x / 3.291x | post arm recorded 129 programs against 287, or the eBPF arm ran a third of its own stats-on rate (rotate-3b5fa4b40-20261120) |
| Katran per call 1.094x (11-16 145408) | samples 1.25 / 0.95 / 1.04 (trend-20261116) |
| BCC throughput stats on 1.268x (11-16 060435) | sched_switch and sched_wakeup ran 2.51x as often in the native arm (arm-paths-20261116) |

What stands: image 3b5fa4b40, frozen entry rotate (kprog/results/rotate-3b5fa4b40-20261120), against the 05-29 x86
matrix (the kinsn-era system; stats off throughput).

| App | Per call | Throughput stats off | Throughput stats on | 05-29 |
|---|---|---|---|---|
| Tracee | 2.036x | 1.884x | 1.659x | 0.948x |
| Tetragon | 1.248x | (unequal work) | 1.093x | 1.009x |
| BCC | 1.144x | rerun queued (best earlier 1.023x, 11-19) | 1.251x | 0.985x |
| Katran | 1.017x | 0.962x | 1.004x | 1.113x (above its BPF-share bound, about 1.10x) |
| Cilium | 1.012x | rerun queued | 0.992x | 1.319x |
| OTel | 0.936x | rerun queued | 0.961x | 1.849x (unrolling did no work) |

Per-call geomean 1.187x (20% target: 1.20x). Above the 05-29 number: Tracee, Tetragon, BCC. Below: Cilium (107 of its
135 programs are per-endpoint programs the agent compiles with other constants; they stay on eBPF), and Katran and OTel
against 05-29 figures that themselves exceed what equal work allows.
