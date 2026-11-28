# Current-image OTel PMU observation

Both corpus phases succeeded. Entry: eBPF3076.59ns, native3062.41ns, diagnostic ratio1.00463x. This does not replace full timing.

| Group | eBPF sampled periods / entry | Native | Native / eBPF |
|---|---:|---:|---:|
| unwinder | 783.51 | 2393.85 | 3.055 |
| trie_lookup_elem | 2151.94 | 0.00 | 0.000 |
| array_map_lookup_elem | 110.05 | 93.67 | 0.851 |
| hash-named functions | 574.16 | 515.15 | 0.897 |
| copy_from_user_nofault | 1352.93 | 1424.69 | 1.053 |

Group directions are specific to this observation. PMU differences identify residual work to investigate; they do not establish a causal per-call latency or justify changing a kernel function.

Whole measurement socket windows are approximations of stats boundaries; PMU period sums have skid/frequency/multiplexing limits. Different entry counts and changing lookup/query paths prevent assigning exact kernel ns or causal call-cost changes. Native direct relocation count is static, not dynamic helper invocation parity. This10s PMU check is separate from full timing and does not establish a new optimization gain.

The native unwind blob has 0 direct relocations to the boot trie_lookup_elem address. An inlined native trie body may have no samples at the external kernel symbol; inspect the installed code and work records before interpretation. Dynamic call counts/path lengths remain unmeasured. No production change follows solely from a flat sample difference. Historical and current-image profiles must be distinguished.
