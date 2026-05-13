# C3 bounds_check_merge reg equality evidence (2026-05-13)

## Verdict
Keep C3 for now: the current testbin corpus has zero C3-rejected ladder candidates and relaxing the check would add zero `bounds_check_merge` applications.

## Apply-rewrites code analysis
`scan_guard_sites` only records the exact immediate packet guard shape:

```text
mov64 cursor, root
add64 cursor, imm
if cursor >/>=/</<= data_end goto slow
```

At detection time, `root_reg` is the `mov.src_reg()` packet-data register, `data_end_reg` is the compare's packet-end register, and the guard output register is the normalized compare cursor. `root_ptr_def` is the lifted packet pointer identity; matching `root_ptr_def` proves the packet-data and packet-end values came from the same underlying context load chain.

When a ladder rewrite is built, the first guard is dominant. `apply_rewrites` does exactly this:

1. Replaces only the dominant guard's `add` instruction with the same instruction but a widened `imm = merged_end`.
2. For each consumed guard, deletes every site placed in `skip_sites`.
3. Body sites in `skip_sites` are deleted by `delete_body_sites_reverse`.
4. Terminator sites in `skip_sites` are converted from conditional branch to fallthrough by `delete_cond_branch`.

`build_ladder_rewrite` decides the consumed sites:

```text
if consumed_guard.can_remove_setup:
    delete consumed mov + consumed add + consumed compare
else:
    delete consumed compare only
```

`can_remove_setup` is gated by `cursor_dead_after_compare`, which proves the consumed guard's `add` definition of the cursor register has no uses except the consumed compare. Therefore the only register whose defined value can be lost by deleting a consumed guard's setup is already proven dead. If that cursor is live after the compare, current code keeps the consumed `mov+add` and removes only the redundant compare, so downstream non-guard users still read the computed value.

The current C3 check is therefore not what protects the consumed cursor register. The protection is `cursor_dead_after_compare` plus the `can_remove_setup` split in `build_ladder_rewrite`. `root_reg` and `data_end_reg` are read by the guard but not defined by the consumed setup; deleting the consumed compare cannot stale either register.

`interleaves_are_merge_safe` only proves the path between the previous compare fallthrough and the next guard setup is structurally simple: same frame, no branch target entry, no jump/call/exit, no non-stack store. It does not prove post-compare cursor deadness. Post-compare cursor safety comes from the use-def query in `cursor_dead_after_compare`.

## Statistics
- Packet-gated testbin programs scanned: 52 (`cilium_agent` SCHED_CLS/XDP plus `katran` XDP; `cilium_agent` IDs 63/64 are type 26 and do not pass the pass gate)
- Exact guard sites matched by current pass logic: 1
- Total guard ladders detected (would-be candidates): 0
- Currently rejected by C3 (root_ptr_def match, reg mismatch): 0
- Among rejected: dead-reg case (relaxable): 0
- Among rejected: live-reg case (would need preservation if setup were deleted): 0
- Current apply count: 0
- Relaxed-C3 estimated apply count: 0
- Estimated apply-count delta: 0

Per-app scan:

| app | packet programs | guard sites | current ladders | relaxed ladders | C3-rejected extensions |
| --- | ---: | ---: | ---: | ---: | ---: |
| cilium_agent | 51 | 0 | 0 | 0 | 0 |
| katran | 1 | 1 | 0 | 0 | 0 |

The one matched guard is in `bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin`:

```text
pc 2: r8 = *(u32 *)(r6 +0)      ; ctx->data
pc 3: r9 = *(u32 *)(r6 +4)      ; ctx->data_end
pc 4: alu64 r1 = r8
pc 5: alu64 r1 += 14
pc 6: if r1 > r9 goto +1553
```

It has no next guard to merge with, so it is skipped as `guard not part of a mergeable ladder`.

I also ran the real pass over all 52 packet-gated testbin inputs:

```text
count=52 matched=1 applied=0 skipped=1
```

## Concrete examples
None. The exact scanner found no consecutive guards where `root_ptr_def` matches and either `root_reg` or `data_end_reg` differs. There are therefore no 3-5 concrete C3-rejected examples in the current testbin corpus.

## Recommendation
Keep C3 until there is a real corpus or microbenchmark case that benefits from relaxing it.

If a future case appears, the low-risk implementation is probably to delete only the two physical-register equality checks in `can_extend_ladder` and add a focused regression test for a mismatched physical root/data_end ladder. The current rewrite path already preserves live consumed cursors by keeping `mov+add` when `cursor_dead_after_compare` is false, so mov insertion does not look necessary. Estimated production LOC would be roughly -2 to +0, plus about 30-50 LOC of targeted tests. Given the current apply delta is zero, that change is not justified by corpus evidence today.
