# x86 frozen-entry run, 2026-11-22T12:22Z – 17:40Z

Operator 2026-11-22: "确定好就可以测试性能", "可以 profile 但是不允许做任何设计之外的事情或者细节调优, 必须跑几次确保数据全部都在."

Entry: `make -C kprog/perf/one-image rotate` (frozen defaults: 3 samples x 180 s per arm, stats off then on,
breadth first), started by the coordinator's chain19 after the x86 and arm64 function checks of chain18.
Image bpf-benchmark/kprog:current built 2026-11-22T10:44–10:51Z from the tree at 09613661f (path code; later
commits to the run's start dbed668ab touch docs and the verify side only). Function check on that image
(10:51–11:11Z): six apps rc=0, every running program replaced natively (OTel 14, BCC 25, Cilium 135,
Tetragon 288, Tracee 169, Katran 1). Ratios native/eBPF from kprog/results/flag-tuning-20261117/may29_ratio.py.
Every run: rc=0, three samples per arm.

| App | Throughput, stats off | Per call, stats on | Throughput, stats on | 8430daa81 (stats off / per call) | 05-29 per call |
|---|---|---|---|---|---|
| OTel | 0.994x (0.977, 0.994, 1.019) | 0.943x (eBPF 3201.7 ns, native 3393.5 ns) | 1.013x | void / void | 1.849x (void, same defect) |
| BCC | 1.013x (1.020, 1.011, 1.004) | 0.993x (15/25 active) | 1.000x | 1.014x / 0.999x | 0.985x |
| Cilium | 0.667x (0.678, 0.668, 0.636) | 0.461x (eBPF 622.9 ns, native 1350.7 ns) | 0.698x | 1.026x / 1.108x | 1.319x |
| Tetragon | 1.337x (1.311, 1.343, 1.337) | 2.237x (eBPF 740.2 ns, native 330.9 ns) | 1.307x | 1.335x / 2.439x | 1.009x |
| Tracee | 1.871x (1.842, 1.928, 1.872) | 1.987x (41/167 active) | 1.681x | 1.908x / 1.978x | 0.948x |
| Katran | 1.022x (1.025, 1.021, 1.028) | 1.007x (1/1) | 1.011x | 1.106x / 1.239x | 1.113x |

Runs (corpus/results): stats off OTel x86_kvm_corpus_20261122_122355_899601, BCC _124949_242263, Cilium
_131621_631047, Tetragon _134250_130700, Tracee _140920_477520, Katran _143640_457375; stats on OTel
_150245_285011, BCC _152855_732291, Cilium _155511_408865, Tetragon _162144_505539, Tracee _164820_504768,
Katran _171542_684932.

- OTel now unwinds natively (the entry reads the kernel's perf-event context); this is its first valid
  number on the restored path.
- Cilium and Katran fall against 8430daa81: Cilium per call 1.108x to 0.461x, Katran 1.239x to 1.007x.
  The path changes since 8430daa81 are map calls bound by map name (a name carried through a register copy
  or a stack slot is dropped and the call goes to the kernel's generic helper), helpers called by name,
  map update/delete calling the map type's function, and the loader holding the data map it finds.
  The coordinator investigates (todo section 五 item 0).
- Katran: both arms report pktgen errors of the same order, a property of the workload.
