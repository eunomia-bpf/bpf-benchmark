# Cilium JIT versus whole-program native profile

These profiling runs are separate from timing runs and reuse the unchanged Cilium corpus setup.

| Arm | Packets | BPF runs/packet | cycles/packet | instructions/packet | IPC | branches/packet | branch misses/packet | branch miss rate | cache misses/packet |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| jit | 40233686 | 1.000 | 9551.225 | 14997.458 | 1.570 | 2732.086 | 4.216881 | 0.154347% | 8.901780 |
| kprog | 38928324 | 1.000 | 9857.488 | 15207.088 | 1.543 | 2872.214 | 3.393561 | 0.118151% | 7.087662 |

## Outcome counters

| Arm | Sent | Received | Component errors | RX errors | RX drops | Allow dir. 1 | Allow dir. 2 | Other verdicts |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| jit | 40233686 | 40233825 | 0 | 0 | 0 | 40233816 | 40233822 | 9 |
| kprog | 38928324 | 38928460 | 0 | 0 | 0 | 38928454 | 38928455 | 3 |

## Resolved non-idle leaf-sample split

This heuristic classifies resolved sampled leaves by symbol name. It excludes unresolved leaves and does not attribute inclusive callchain ancestry.

| Arm | BPF code ns/packet | Helpers ns/packet | Maps ns/packet | Rest ns/packet |
| --- | ---: | ---: | ---: | ---: |
| jit | 91.988 | 34.399 | 567.087 | 2138.258 |
| kprog | 100.210 | 37.864 | 517.490 | 2431.623 |

| Arm | Unresolved leaf samples | Estimated unresolved sampled ns/packet | Unresolved share of non-idle samples |
| --- | ---: | ---: | ---: |
| jit | 6443 | 160.139 | 5.352% |
| kprog | 149 | 3.828 | 0.124% |

Raw counters, perf data, symbol snapshots, full call graphs, and per-program tables are in each arm directory.

## Findings

This diagnostic does **not** reproduce a whole-program-native throughput gain.
With profiling enabled, kprog processes 3.244% fewer packets than JIT
(38,928,324 versus 40,233,686) and consumes 3.207% more cycles/packet.  It
also executes 1.398% more instructions/packet, has 1.753% lower IPC, and
executes 5.129% more branches/packet.  The two hot `cil_from_container`
roots agree with the aggregate result: kprog is 7.654% slower on
`lxcbench0` (1643.872 versus 1527.000 ns/run) and 7.851% slower on
`lxcbench1` (1664.688 versus 1543.511 ns/run).

The resolved, non-idle kernel leaf samples show both a native benefit and
larger costs elsewhere.  Relative to JIT, kprog's estimated map-leaf time per
packet is 8.746% lower; `lookup_nulls_elem_raw` falls from 12,620 to 8,223
leaf samples.  However, BPF-code leaves are 8.938% higher, helper leaves are
10.074% higher, and other resolved kernel leaves are 13.720% higher.  The
LRU update path moves in the other direction: `htab_lru_map_update_elem`
grows from 5,969 to 7,865 samples.  `_raw_spin_unlock_irqrestore` remains the
largest leaf and grows from 28,045 to 32,742 samples.  The kprog-only top-20
entry `mod_cur_headers` is pktgen code (`[pktgen]` in kallsyms), not
unattributed native BPF code.

Native also improves locality/control-flow counters: branch misses/packet
fall 19.524%, branch-miss rate falls 23.451%, and cache misses/packet fall
20.379%.  These benefits and the lower resolved map-leaf estimate coexist
with higher instruction and branch counts and more samples in BPF, helpers,
and other kernel leaves.  They identify where native looks better, but do not
establish an inclusive or causal time breakdown, and there is no net native
throughput gain in this profiled configuration.

The outcome counters confirm the same successful bidirectional packet path
and outcome class, with no evidence that either arm skips the measured
datapath.  Both have zero component errors, RX errors, and RX drops.  JIT
records one BPF root run per sent packet plus 151 startup/control runs; kprog
records one per packet plus 139.  In direction 1, the allow verdict exceeds
the sent count by exactly 130 in both arms.  In direction 2 it exceeds sent
by 136 for JIT and 131 for kprog; received packets exceed sent by 139 and
136, respectively.  The remaining verdicts are only nine events for JIT and
three for kprog.  These counters do not prove identical internal instruction
sequences, but they rule out a missing packet direction, outcome class, or
root datapath invocation as the explanation.

Across all 163 replaced programs, the original JIT images total 687,766
bytes, while native blobs total 792,890 bytes (+15.285%); the BPF-callable
native stub images total 797,332 bytes (+15.931%).  The complete paired
per-program size table is in `kprog/report.md` and `kprog/report.json`.

## Provenance and interpretation boundary

These are separate 60-second, one-sample profiling runs on host CPUs 16--19,
with BPF statistics and 1 ms `cpu-clock` frame-pointer call graphs enabled.
They used the runtime tar accepted by the coordination record
`2026-10-10T05:26:11Z agent1 CILIUM-GATES-PASSED (native vs JIT)`, SHA-256
`e1192651c83290a830b7bdee79c8e3c27ac15d727e2fce42fa7b14844cf93110`.
Capture used Git commit `1965f416c41297c9f77187edecdd82f263432290`;
the final reports were generated with analyzer commit
`53f145a1f8939974ad164f7fa6051a8d11f94860`.

The profiling runs are diagnostic and intentionally separate from the timing
suite; their packet-rate difference must not replace the multi-sample timing
result.  The four-way split classifies resolved, non-idle sampled leaf symbols
and does not use inclusive callchain ancestry.  JIT excludes 6,443 unresolved
leaves (160.139 sampled ns/packet, 5.352% of non-idle samples), while kprog
excludes 149 (3.828 ns/packet, 0.124%).  The estimates are sample count times
1 ms divided by packets, not deterministic accounting of every packet.
