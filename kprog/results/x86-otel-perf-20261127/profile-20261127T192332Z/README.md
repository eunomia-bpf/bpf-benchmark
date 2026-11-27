# Current-image OTel PMU observation

Both corpus phases succeeded. Entry: eBPF2280.68ns, native3967.35ns, diagnostic ratio0.57486x. This does not replace full timing.

| Group | eBPF sampled periods / entry | Native | Native / eBPF |
|---|---:|---:|---:|
| unwinder | 816.34 | 917.10 | 1.123 |
| trie_lookup_elem | 1786.33 | 2991.04 | 1.674 |
| array_map_lookup_elem | 149.46 | 208.67 | 1.396 |
| hash-named functions | 508.75 | 703.65 | 1.383 |
| copy_from_user_nofault | 1138.93 | 1727.51 | 1.517 |

Group directions are specific to this observation. PMU differences identify residual work to investigate; they do not establish a causal per-call latency or justify changing a kernel function.

Whole measurement socket windows are approximations of stats boundaries; PMU period sums have skid/frequency/multiplexing limits. Different entry counts and changing lookup/query paths prevent assigning exact kernel ns or causal call-cost changes. Native direct relocation count is static, not dynamic helper invocation parity. This10s PMU check is separate from full timing and does not establish a new optimization gain.

The native unwind blob has 4 direct relocations to the boot trie_lookup_elem address. Both phase PMU samples resolve to that same kernel implementation. Dynamic call counts/path lengths remain unmeasured. No production change follows solely from a flat sample difference. Historical and current-image profiles must be distinguished.
