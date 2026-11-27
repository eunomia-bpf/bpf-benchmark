# Current-image OTel PMU observation

Both corpus phases succeeded. Entry: eBPF3193.13ns, native3287.88ns, diagnostic ratio0.97118x. This does not replace full timing.

| Group | eBPF sampled periods / entry | Native | Native / eBPF |
|---|---:|---:|---:|
| unwinder | 1063.49 | 873.77 | 0.822 |
| trie_lookup_elem | 2815.13 | 3298.16 | 1.172 |
| array_map_lookup_elem | 145.09 | 115.96 | 0.799 |
| hash-named functions | 716.86 | 694.88 | 0.969 |
| copy_from_user_nofault | 1775.59 | 1752.71 | 0.987 |

Native unwinder body, named hash group, array helper and user copy have lower sampled cycle-period sums per entry here. Trie group is higher. This identifies a current residual difference, not a proven reason for it or justification for modifying a kernel function.

Whole measurement socket windows are approximations of stats boundaries; PMU period sums have skid/frequency/multiplexing limits. Different entry counts and changing lookup/query paths prevent assigning exact kernel ns or causal call-cost changes. Native direct relocation count is static, not dynamic helper invocation parity. This10s PMU check is separate from full timing and does not establish a new optimization gain.

The native unwind blob has 4 direct relocations to the boot trie_lookup_elem address. Both phase PMU samples resolve to that same kernel implementation. Dynamic call counts/path lengths remain unmeasured. No production change follows solely from a flat sample difference. Historical and current-image profiles must be distinguished.
