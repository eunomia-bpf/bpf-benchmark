# x86 frozen-entry run on 30e401e37, 2026-11-23T19:38Z – 11-24T00:02Z

Code: bpf-benchmark 30e401e37 (77908203a LPM trie direct call; inner-map template forms). Image built
2026-11-23 17:59–18:06Z from 0234daa7c, check 18:06–18:29Z (six applications rc=0, every running program native).
Entry: `make -C kprog/perf/one-image rotate ORDER="otelcol-ebpf-profiler/profiling cilium/agent tetragon/observer
tracee/monitor katran"` (frozen defaults: 3 x 180 s per arm, stats off then on; chain.sh in this directory). Every
run rc=0 with three samples per arm. Ratios native/eBPF from kprog/results/flag-tuning-20261117/may29_ratio.py.

The last two columns are the mean busy cores on the lab host's E-cores (CPUs 8-23; the guest runs on P-cores 0-7)
during the eBPF half and the native half of each run (Prometheus node_cpu_seconds_total, 1-minute steps). The lab
host also runs the eunomia CI runners and eight other Workspaces.

| App | Stats | Ratio | eBPF samples | native samples | E-cores eBPF half | E-cores native half |
|---|---|---|---|---|---|---|
| OTel | off | throughput 1.019x | 41385375, 41650167, 41821483 | 42424162, 43615833, 40596152 | 5.1 | 3.2 |
| Cilium | off | throughput 1.190x | 1282988, 1320539, 1333930 | 1559986, 1571500, 1591672 | 1.9 | 0.9 |
| Tetragon | off | throughput 0.459x | 340246, 332651, 334617 | 184987, 139311, 153628 | 1.1 | 5.2 |
| Tracee | off | throughput 1.928x | 315484, 332118, 311028 | 592946, 659538, 608100 | 7.5 | 6.9 |
| Katran | off | throughput 1.037x | 2774953, 2881824, 2863892 | 2968493, 2953257, 2976549 | 4.3 | 1.5 |
| OTel | on | per call 0.944x (3183.7 / 3371.2 ns); throughput 0.964x | 42083203, 41731423, 41981139 | 40489573, 42454686, 40369945 | 1.9 | 1.7 |
| Cilium | on | per call 1.105x (678.0 / 613.6 ns); throughput 1.105x | 1359725, 1279441, 1201475 | 1420425, 1413280, 1402998 | 4.2 | 2.7 |
| Tetragon | on | per call 2.876x (3107.5 / 1080.5 ns); throughput 2.401x | 159931, 89660, 91395 | 146856, 293196, 219426 | 8.3 | 6.3 |
| Tracee | on | per call 2.112x (411.1 / 194.6 ns); throughput 1.865x | 278192, 310883, 278962 | 466201, 520184, 522325 | 6.3 | 5.5 |
| Katran | on | per call 1.042x (182.5 / 175.1 ns); throughput 1.021x | 2345126, 2397524, 2386238 | 2430843, 2473149, 2437450 | 6.9 | 6.0 |

The dcf4a1aef run of 11-23 morning (kprog/results/x86-rotate-20261123) had E-core means of 0.7 / 0.8 (Tetragon
off), 2.0 / 1.9 (Tetragon on), 0.4 / 0.4 (Cilium off), 2.1 / 2.8 (Cilium on), 4.4 / 1.2 (OTel off) and 1.1 / 3.5
(OTel on).

Tetragon: its native code differs from dcf4a1aef's in 35 programs, each an inner-map lookup in its direct form
(1329 -> 1338, 10463 -> 10499, 10371 -> 10407, 13483 -> 13492 bytes). In the stats-on run the eBPF arm, whose code
is the same as on 11-23 morning, took 3107.5 ns per call (11-23 morning: 748.0 ns); its generic tracepoint program
took 4973.6 ns (770.1 ns). On arm64 the same commit measures Tetragon at 1.384x per call and 1.222x stats-off
throughput, equal to dcf4a1aef's 1.384x and 1.237x (kprog/results/arm64-spark-run6-20261124).

Rerun of Tetragon, Cilium, OTel and BCC on the same image from 2026-11-24T03:33Z:
/workspaces/kprog-raw/coordinator/rerun-20261124 (chain.sh, progress.log).
