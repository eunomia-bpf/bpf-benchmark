# x86 frozen-entry run on the fixed linker, 2026-11-23T08:03Z – 13:21Z

Operator 2026-11-23: "x86 / arm 性能都要完整汇报并且检查是不是和设计完全符合".

Code: bpf-benchmark dcf4a1aef (jiffies_64 address kept; frozen .rodata read as constants). Image
bpf-benchmark/kprog:current built 2026-11-23T06:03–06:10Z; function check 06:10–06:32Z: six apps rc=0,
every running program replaced natively (OTel 14, BCC 25, Cilium 135, Tetragon 288, Tracee 169,
Katran 1; Tetragon's library runtime probe stays eBPF). Entry: `make -C kprog/perf/one-image rotate`
(frozen: 3 samples x 180 s per arm, breadth first, stats off then on). Every run rc=0 with three
samples per arm. Ratios native/eBPF from kprog/results/flag-tuning-20261117/may29_ratio.py.

| App | Throughput, stats off | Per call, stats on | Throughput, stats on | 11-22 run (off / per call) | 8430daa81 (off / per call) | 05-29 floor (stats off) |
|---|---|---|---|---|---|---|
| OTel | 1.061x (1.059, 1.007, 1.094) | 0.930x (eBPF 3161.2, native 3399.6 ns) | 0.975x | 0.994x / 0.943x | void / void | 1.849x (void, same defect) |
| BCC | 1.006x (1.010, 0.999, 1.007) | 0.984x (106.4 / 108.1 ns) | 0.988x | 1.013x / 0.993x | 1.014x / 0.999x | 0.985x |
| Cilium | 1.169x (1.163, 1.169, 1.174) | 1.205x (726.7 / 602.9 ns) | 1.142x | 0.667x / 0.461x | 1.026x / 1.108x | 1.319x (below) |
| Tetragon | 1.291x (1.291, 1.292, 1.294) | 2.351x (748.0 / 318.1 ns) | 1.344x | 1.337x / 2.237x | 1.335x / 2.439x | 1.009x |
| Tracee | 1.901x (1.893, 1.882, 1.917) | 1.793x (378.8 / 211.3 ns) | 1.374x | 1.871x / 1.987x | 1.908x / 1.978x | 0.948x |
| Katran | 1.006x (0.985, 1.016, 0.987) | 1.002x (180.1 / 179.8 ns) | 0.981x | 1.022x / 1.007x | 1.106x / 1.239x | 1.113x (below) |

Geomean over six: throughput stats off 1.206x, per call 1.292x.

Runs (corpus/results): stats off OTel x86_kvm_corpus_20261123_080423_940699, BCC _083036_509601,
Cilium _085723_497058, Tetragon _092400_737974, Tracee _095043_770328, Katran _101811_087803; stats on
OTel _104425_910099, BCC _111038_481045, Cilium _113701_916596, Tetragon (12:01–12:28Z), Tracee
_122951_540329, Katran _125701_042461.

Host load during the run (lab node, Prometheus, 10-minute steps): P-cores 0-7 carried the timing guest
(2.3–8.0 busy). E-cores 8-23 were at 0.4–1.1 busy for most of the run, with 7.0 at 11:00Z (the coordinator
copying and parsing the arm64 results), 7.8 at 12:50Z and 6.2–6.7 at 13:10–13:20Z (during Katran stats on;
the lab node also runs CI runners and other Workspaces).

- Cilium: the jiffies_64 fix brings it from 0.461x to 1.205x per call, above 8430daa81's 1.108x; stats-off
  throughput 1.169x stays below the 05-29 floor 1.319x.
- Katran: per call 1.002x, below 8430daa81's 1.239x and the 05-29 floor; the native program's hottest
  load (the consistent-hash ring read) matches the eBPF one in the 11-23 profile. Next: link the same
  Katran object with the 8430daa81 and the current linker and diff the code.
- OTel per call 0.930x: 72 of the 110 lookups in its hottest unwinder reach the generic map helper
  (the map name is lost through register copies and stack slots).
