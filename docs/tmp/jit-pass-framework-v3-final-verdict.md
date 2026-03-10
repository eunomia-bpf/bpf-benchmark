# JIT Pass Framework v3 Final Verdict

- Score: 8/10
- Ready for implementation?: No

The document is substantially improved and covers the six review targets well. It now has an explicit supersedes / out-of-scope section (§1.1) and an honest contribution boundary (§10.3). Policy ownership is mostly clear in §3.4.1: userspace owns cross-site priority and budget intent, kernel owns legality, alt availability, and mechanical budget accounting, and hidden kernel policy override is explicitly forbidden. The constant blinding contract in §2.2.1 is also specific enough for implementation: it binds materialization to the post-fixup, pre-blinding image; disables v3 on blinded paths; and clearly separates whole-bundle disable from per-site reject/fallback.

`WIDE_MEM` is close to implementation-grade. §8.4.1 gives canonical positive shapes, explicit negative shapes, and precise reject conditions; the claim hierarchy is also now honest and repeated consistently: `SELECT` is the policy-sensitive anchor, `WIDE_MEM` is the largest-gap JIT-only recovery, and `ADDR_MODE` / `ROTATE` are extensibility witnesses rather than equal-strength evidence.

Top 3 remaining risks:

1. The runtime plan model is internally inconsistent. The state stores `bpf_jit_plan_hdr *plans`, but the dispatcher/emitter contracts consume `bpf_jit_region_plan *`; separately, `start_map[bpf_idx]` is described as dense O(1) lookup while the declared `start_map.entries[]` shape looks sparse. These need to be unified into one concrete runtime representation.
2. The policy-priority contract still lacks an encoding for “userspace did not specify `policy_prio`”. The UAPI record always carries a `u16 policy_prio`, but §3.4.1 relies on the distinction between explicit priority and missing priority for `default_policy_prio` and tie-break behavior.
3. The `WIDE_MEM` alignment rule is assigned to exact validation, but the current `family_ops.exact_validate()` API has no target/alt input; target-dependent alignment capability only appears in `select_alt()`. Either move that rule into alt selection or extend the validator API so the contract is implementable as written.

If those three contract gaps are resolved, the design is ready to implement.
