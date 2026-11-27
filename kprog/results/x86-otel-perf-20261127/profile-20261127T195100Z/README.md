# Current-image OTel PMU observation

Both corpus phases succeeded. Entry: eBPF3042.03ns, native254.81ns, diagnostic ratio11.93835x. This does not replace full timing.

| Group | eBPF sampled periods / entry | Native | Native / eBPF |
|---|---:|---:|---:|
| unwinder | 981.43 | 0.00 | 0.000 |
| trie_lookup_elem | 2494.02 | 321.50 | 0.129 |
| array_map_lookup_elem | 127.53 | 0.00 | 0.000 |
| hash-named functions | 667.67 | 34.22 | 0.051 |
| copy_from_user_nofault | 1619.58 | 0.00 | 0.000 |

Group directions are specific to this observation. PMU differences identify residual work to investigate; they do not establish a causal per-call latency or justify changing a kernel function.

Whole measurement socket windows are approximations of stats boundaries; PMU period sums have skid/frequency/multiplexing limits. Different entry counts and changing lookup/query paths prevent assigning exact kernel ns or causal call-cost changes. Native direct relocation count is static, not dynamic helper invocation parity. This10s PMU check is separate from full timing and does not establish a new optimization gain.

The native unwind blob has 4 direct relocations to the boot trie_lookup_elem address. Both phase PMU samples resolve to that same kernel implementation. Dynamic call counts/path lengths remain unmeasured. No production change follows solely from a flat sample difference. Historical and current-image profiles must be distinguished.
