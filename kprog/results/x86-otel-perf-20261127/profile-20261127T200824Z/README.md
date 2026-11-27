# Current-image OTel PMU observation

Both corpus phases succeeded. Entry: eBPF4163.82ns, native438.54ns, diagnostic ratio9.49470x. This does not replace full timing.

| Group | eBPF sampled periods / entry | Native | Native / eBPF |
|---|---:|---:|---:|
| unwinder | 960.52 | 0.00 | 0.000 |
| trie_lookup_elem | 2043.21 | 287.24 | 0.141 |
| array_map_lookup_elem | 270.62 | 0.00 | 0.000 |
| hash-named functions | 621.67 | 28.34 | 0.046 |
| copy_from_user_nofault | 1382.00 | 0.00 | 0.000 |

Group directions are specific to this observation. PMU differences identify residual work to investigate; they do not establish a causal per-call latency or justify changing a kernel function.

Whole measurement socket windows are approximations of stats boundaries; PMU period sums have skid/frequency/multiplexing limits. Different entry counts and changing lookup/query paths prevent assigning exact kernel ns or causal call-cost changes. Native direct relocation count is static, not dynamic helper invocation parity. This10s PMU check is separate from full timing and does not establish a new optimization gain.

The native unwind blob has 4 direct relocations to the boot trie_lookup_elem address. Both phase PMU samples resolve to that same kernel implementation. Dynamic call counts/path lengths remain unmeasured. No production change follows solely from a flat sample difference. Historical and current-image profiles must be distinguished.


The map observer resolves the work difference (see map-path-analysis.json and DWARF extracts). Stress PID initial mapping lookups hit in both phases. Native program-array slot1 contains the14373-byte native unwinder28. Baseline snapshots98.27/103.90 record87,895,455→114,191,061 native unwind attempts and80,737,239→104,924,365 frames. Native126.53 has zero attempts/frames; all8per-CPU records show stack_len0/tailCalls1 while several contain valid nonzero user PCs. Baseline records contain deep stacks and repeated tails. Metric IDs5/6 and record offsets come from actual P source/DWARF, with matching5000-byte map value size.

Actual linked entry argument setup jumps over the shared inline tail expansion because the original helper address was not retained. A populated-map/count0 host regression reproduces no transfer; the common first-instruction anchor repair passes the same test with count1 and preserved context/frame. Therefore this9.494x observation and the preceding11.938x observation include proven skipped work. Both raw/app-ok results stay recorded; neither is an equal-work optimization gain. This conclusion does not reclassify other historical functional runs based on counts or PMU absence. The corrected common linker and frozen guest check are in ../shared-call-anchor-20261127.
