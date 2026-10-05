# Prog 43 E2BIG ReJIT Failure Investigation

Date: 2026-05-03
Run: tracee/monitor KVM corpus smoke, `/tmp/kvm-tracee-only-v9-1777793671.log`

## Symptom

During the `prefetch` pass (12th in the x86 pass list), after 11 prior passes ran and 5 committed
bytecode changes, `BPF_PROG_REJIT` for tracee/monitor prog 43 returns errno 7 (E2BIG). The error
is correctly recorded and surfaced — current behavior is already compliant with the No ReJIT
Filtering rule.

## Kernel Side: What Triggers E2BIG

`vendor/linux-framework/kernel/bpf/syscall.c` line 3775:

```c
if (bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE) {
    err = -E2BIG;
    goto free_tmp_noref;
}
```

`bpf_prog_size(n)` returns the bytecode struct allocation size (`offsetof(struct bpf_prog, insns[n])`
for large n — effectively a fixed header plus `n * 8` bytes). `prog->pages` is set **once** at
`BPF_PROG_LOAD` time (`core.c` line 124: `fp->pages = size / PAGE_SIZE`) and is **never updated**
during any subsequent `BPF_PROG_REJIT`. The swap path (`syscall.c` line 3487) updates `prog->len`
in-place but leaves `prog->pages` frozen. This means `prog->pages * PAGE_SIZE` is an immutable
capacity ceiling set from the original bytecode size at load time.

The other two E2BIG paths (line 3622: `insn_cnt > BPF_COMPLEXITY_LIMIT_INSNS`, line 3624:
`fd_array_cnt > 64`) are not involved here; prog 43 is well under 1M insns.

## Prefetch Pass: Insn-Count Inflation

The `prefetch` pass (`bpfopt/crates/bpfopt/src/passes/prefetch.rs`) inserts `bpf_prefetch` kop
calls before pointer dereferences. Each insertion is exactly 2 instructions
(`emit_packed_kop_call_with_off` returns `[kop_sidecar, call_kop_with_off]`). The pass only
scans two kinds of sites: map-value dereferences (after `bpf_map_lookup_elem`) and packet data
dereferences (for XDP/sched_cls program types only).

Prog 43 is a `kprobe`-type tracing program (`tracee/monitor`). `packet_ctx_layout()` returns `None`
for kprobe, so no packet prefetch sites are generated. Only map-value sites apply. The verifier log
shows exactly 2 `bpf_map_lookup_elem` calls (insns 7 and 14), producing at most 2 prefetch
candidates, i.e. **4 inserted instructions maximum**.

## Why This Prog Specifically

The verifier log shows `if r0 == 0 goto pc+3907` at insn 9, placing the total insn count at
roughly 3917 (lower bound from a single subprog). At load time:

- `bpf_prog_size(3917)` ≈ 256 bytes header + 3917 × 8 = ~31,592 bytes
- Rounded up to page boundary: 8 pages = 32,768 bytes capacity
- Maximum insns that fit in 8 pages: ~4,064 (leaving ~147 insns of slack)

After 11 passes ran (5 committed bytecode changes), expansion passes — principally `map_inline`
(which can duplicate subgraphs) and `bulk_memory` (which inserts kop calls) — consumed most of
that slack. When prefetch adds its 4 final instructions, `bpf_prog_size(new_len)` exceeds
`prog->pages * PAGE_SIZE` (32,768 bytes), triggering E2BIG. Prefetch is simply last in the pass
order; any earlier pass that inserted the same 4 instructions would have triggered the same error
at that step.

## Ranked Fix Options

1. **Accept as-is (current behavior).** The error is recorded correctly, no filtering or silencing
   occurs. Per the No ReJIT Filtering rule, this is the intended outcome. The prog continues running
   with the 5 committed optimizations from earlier passes. Tradeoff: one pass's benefit is lost, but
   nothing is hidden.

2. **Kernel-fork: grow `prog->pages` on each successful REJIT.** Update `prog->pages` inside the
   REJIT swap path after `bpf_prog_realloc` succeeds for the new insn count. This removes the
   fixed-capacity ceiling and allows unlimited per-pass growth. Tradeoff: violates the no-kernel-
   changes rule and changes kernel ABI semantics; the frozen-pages design is intentional (it bounds
   in-place insn copying and prevents unbounded memory growth across repeated ReJITs).

3. **prefetch pass: gate on remaining insn budget.** Before inserting, check
   `orig_insn_cnt + sites * 2 <= capacity_insns`. Requires the pass to receive the original
   `prog->pages` value as context side-input. Tradeoff: adds a size-check coupling between the
   pure bytecode transform and kernel-visible state; complicates the CLI boundary; partial prefetch
   (insert fewer sites to stay under the limit) would be a new code path.

4. **prefetch pass: cap inserted sites to a hard maximum (e.g. 8).** Tradeoff: arbitrary and
   incorrect for large programs; does not address the root cause for other passes; would not have
   helped prog 43 which only has 2 sites anyway.

## Recommended Action

**Accept as-is (option 1).** The E2BIG is correctly surfaced as an error and recorded in results —
exactly what No ReJIT Filtering requires. The root cause is the kernel's immutable `prog->pages`
ceiling combined with cumulative insn growth across 11 passes. For prog 43, the 5 committed passes
already applied their optimizations successfully. Option 2 requires a kernel change (forbidden).
Option 3 adds significant coupling for a marginal benefit (only 2 sites were being inserted
anyway). The failure is a known, visible kernel-side capacity limit and not a daemon or pass bug.
