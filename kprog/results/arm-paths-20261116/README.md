# Do the two arms run the same programs as often?

Operator 2026-11-16: "为啥一直路径不同?什么原因?哪里出bug?" and "我们是不是所有程序都走一样的路径? 路径正确吗?"

`paths.py` reads the per-program `run_cnt_delta` of both arms in stats-on runs and lists every program whose native/eBPF run ratio leaves 0.7x-1.3x of the app's median ratio, or that runs in one arm only. Output: `result.txt`.

Measured 2026-11-16T14:11:00Z:

- OTel (125155_179400, 053859_493069), Katran (072549_683704), Tracee (20261114_085217_843248, 24 of 24 programs): the arms run the same programs in proportion.
- Cilium (063056_107201): the native arm runs cil_to_host and cil_from_host once per packet (740,557,968 each); the eBPF arm runs them 4 and 2 times. Different packet path.
- BCC (060435_731340): 7 of 11 programs track the median 1.293; sched_switch and sched_wakeup run 2.51x as often in the native arm (176,296,084 vs 70,242,816), so the guest had 2.5 times as many context switches; block_rq_* counts are small (1,800 vs 440).
- Tetragon: no stats-on run with the native side loaded yet.
