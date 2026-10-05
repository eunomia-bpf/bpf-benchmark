# skb_load_bytes_spec inline-unlock analysis (2026-05-13)

End-to-end analysis of what would have to change to lift `skb_load_bytes_spec`
applied counts on Cilium tail programs. Starts from the C2 audit finding,
goes through corpus measurement, root-cause investigation, fix proposals,
and the dependency between arg1 (Gate 1) and offset (Gate 2). Companion
to:
- `correctness_and_guard_audit_20260513.md` (initial audit, contains C2)
- `c2_skb_load_bytes_len_distribution_20260513.md` (len-cap distribution)
- `arg1_not_ctx_root_cause_20260513.md` (concrete trace + fix-option matrix)
- `bounds_check_merge_detector_rewrite_20260513.md` (parallel investigation, not relevant here)

## Summary

| | apply | LOC |
|---|---:|---:|
| baseline (K=8) | 8 | — |
| K=20 only | 8 | 1 |
| arg1 fix (Option C, simplified) | 15 (+7) | ~220 |
| arg1 fix + Gate 2 (dynamic offset) | 242 (+234) | ~620 |

Gate 2 alone is 0 increment because arg1 is the earlier filter; the gates
must be unlocked in order.

## 1. Background: what the pass does

`bpf_skb_load_bytes(skb, offset, dest, len)` is the standard helper to copy
`len` bytes from `skb->data + offset` to a destination buffer. The pass
`skb_load_bytes_spec` (`bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs`)
rewrites such calls into a verifier-friendly fast path that does the bounds
check and bytewise copy inline, falling back to the helper only when the
packet is non-linear or the bounds check fails. Net win is one
helper-call worth of latency (~50-200 ns per call → single-digit ns
inline).

Emitted shape today, for the constant-offset case:

```text
r5 = skb->data
r0 = skb->data_end
r2 = r5
r2 += CONST_OFFSET + CONST_LEN           ; ALU64_ADD imm
if r2 > r0 goto slow_helper_call
r5 += CONST_OFFSET                       ; ALU64_ADD imm
ldx_b r4, [r5 + 0]                       ; bytewise inline copy
stx_b [r3 + 0], r4
... (× len)
```

## 2. The five admission gates (`classify_site`)

The pass admits a call site only if all five succeed:

| Gate | Condition | Today | Codex C2 audit |
|---|---|---|---|
| 0 | not a branch target | rare reject | unchanged |
| 1 | `reg_fact_at(site, 1) == LiftedRegFact::Ctx` | arg1 is skb pointer | unchanged |
| 2 | `reg_fact_at(site, 2)` is `Const(non-negative i32)` | offset is compile-time constant | unchanged |
| 3 | `reg_fact_at(site, 3)` is `FpOff(<0)` | dest is fp-relative stack | unchanged |
| 4 | `len` const and `0 < len <= 8` | len cap | C2 proposed `<= 20` |
| 5 | `offset + len` doesn't overflow i32 | safety | unchanged |

## 3. Measurement: K=8 vs K=20, isolated Cilium

Setup: `BPFREJIT_CORPUS_APPS="cilium/agent" BPFREJIT_BENCH_PASSES="noop,skb_load_bytes_spec" SAMPLES=1 WORKLOAD_DURATION=10 make corpus`.

| | applied | matched | skipped | skip reasons |
|---|---:|---:|---:|---|
| K=8 (`x86_kvm_corpus_20260513_195951_262316`) | 8 | 242 | 234 | 100% "arg1 is not ctx" |
| K=20 (`x86_kvm_corpus_20260513_200534_705861`) | 8 | 195 | 187 | 100% "arg1 is not ctx" |

The K cap raise produced **+0 applied sites**. The 6 Cilium NAT/NodePort
`len == 20` iphdr copies that the C2 audit predicted would unlock at K=20
all hit Gate 1 first. Per-call output preserved in `corpus/results/`.

Matched count differs (242 vs 195) because the underlying corpus run
loaded slightly different program subsets at different timestamps; that
delta is noise, not signal.

## 4. Root cause for "arg1 is not ctx" (Gate 1)

Investigation in `arg1_not_ctx_root_cause_20260513.md`. Concrete program:
Cilium `tail_handle_snat_fwd_ipv4` (testbin index 166, prog_id 109,
`sites_matched=13`, `sites_applied=0`, `sites_skipped=13`).

The skb-context flow at one helper call (PC 93):

```text
entry: r1 = Ctx
  PC 0:  r9 = r1                    (r9 = Ctx)
  ...
  PC 31: *(u64)(fp - 168) = r9      (spill ctx to stack)
  ...
  PC 86: r9 = *(u64)(fp - 168)      (reload ctx)
  PC 90: r1 = r9
  PC 93: call bpf_skb_load_bytes
```

Two independent losses of the `Ctx` lifted fact:

### 4.1 Loss at the first block join

`compute_lifted_reg_facts` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1343`)
does a linear forward walk. At each non-entry block,
`should_reset_linear_state_at_block` (line 228) returns `true` whenever any
of:
- `preds.len() != 1`
- predecessor is not the layout-adjacent block
- predecessor terminator is not a fallthrough/cond-branch into this block

For SNAT prog, the first multi-predecessor block (B3) is reached before
PC 31. Both predecessors carry `r9 = Ctx`, but the join blasts all
non-`r10` regs to `Unknown`.

### 4.2 Loss at stack spill/reload

`LiftedRegFact` does not track stack slots. Even if 4.1 were fixed, the
spill at PC 31 stores `r9 (Unknown after join) → fp[-168]`, and the
reload at PC 86 produces `r9 = Unknown`.

Both losses contribute. A reg-only fix recovers ~145/234 sites; a full
fix (reg meet + stack tracking) recovers all 234.

## 5. Deflation: 234 → 7

The unlock matrix from the codex investigation:

| | K=8 (234 skips) | K=20 (187 skips) |
|---|---:|---:|
| Total arg1 false negatives | 234 | 187 |
| Recovered by reg-only meet (Option A) | 145 | 98 |
| Still need stack spill/reload tracking | 89 | 89 |
| Recovered by CFG meet + stack facts (Options B/C) | 234 | 187 |
| Of those, would pass remaining gates and apply | **7** | **7** |
| Of those, die at Gate 2 ("offset is not constant") | 227 | 180 |

87% of the unblocked arg1 sites then fail at Gate 2. The pattern is
Cilium NAT/NodePort code that computes
`offset = ETH_HLEN + (iph->ihl << 2)` — a runtime-derived IP header
length, not a constant.

## 6. Fix options for Gate 1

| Option | Production LOC | Affected APIs | Risk | arg1 unlock |
|---|---:|---|---|---:|
| **C** Targeted use-def fallback inside `skb_load_bytes.rs` | ~95-135 | none public; optional private CFG helper | low, only this pass | 234/234 K=8, 187/187 K=20 |
| **A** `should_reset_linear_state_at_block` does pred meet on equal facts | ~80-120 | internal in `bbprogram.rs`; all `reg_fact_at` consumers see less-conservative facts | medium-low, soundness needs care for helper clobbers/loops | 145/234 K=8, 98/187 K=20 |
| **B** Full forward dataflow with worklist + meet + stack facts | ~180-260 | structural change in `bbprogram.rs`; introduces `LiftedFactState`; broad consumer impact | medium | 234/234 K=8, 187/187 K=20 |

All three deliver the same `+7` applied sites on the current Cilium
runs, because the remaining 227/187 sites die at Gate 2. The difference
is coverage (false-negative count) and architectural cleanliness.

### 6.1 Option C LOC breakdown (realistic)

| Production | LOC |
|---|---:|
| `arg1_is_ctx_via_use_def` entry | ~5 |
| `is_ctx_origin` recursive (MOV chain, LDX stack reload, budget, visited, entry-block termination) | ~50-60 |
| `find_last_stack_store` + intermediate-overwrite check | ~25-35 |
| single-reaching-def query (use existing `prev_def_in_frame` or add CFG-aware variant) | ~10-30 |
| swap the Gate 1 check | ~5 |
| **production total** | **~95-135** |

| Tests | LOC |
|---|---:|
| direct ctx (baseline regression) | ~25 |
| single-reg chain `r9 = r1; r1 = r9; call` | ~30 |
| stack spill/reload (SNAT pattern) | ~35 |
| stack slot overwritten → reject | ~30 |
| helper call clobber → reject | ~30 |
| budget exhaustion → reject | ~20 |
| **tests total** | **~170** |

Total Option C: **~265-305 LOC** including tests.

Simplified Option C (single-reaching-def via `prev_def_in_frame` only,
reject at any join): production ~70 LOC, tests ~150 LOC = ~220 LOC.

Codex's original 60-100 LOC estimate counts only the main recursion,
omits stack-store reverse lookup, overlap checks, and tests.

## 7. Gate 2 (offset non-constant) — why it is the bigger lever

The pass currently requires `arg2` to be `LiftedRegFact::Const(N)` for a
non-negative `N`. Cilium NAT/NodePort traffic computes offset
dynamically:

```c
ip_offset = ETH_HLEN + ((iph->ihl) << 2);
bpf_skb_load_bytes(skb, ip_offset, &nat_state, 20);
```

`arg2` at the call site is a register holding the result of an `lsh`/`add`
chain — not a compile-time constant. 227/234 (and 180/187 at K=20)
sites are this shape.

### 7.1 Why this can be inlined

BPF supports register-register ALU. The emit can change two `ALU64_ADD imm`
instructions to `ALU64_ADD reg`:

```text
r5 = skb->data
r0 = skb->data_end
r2 = r5
r2 += r_offset                           ; reg-reg ADD (was imm)
r2 += CONST_LEN                          ; reg-imm ADD
if r2 > r0 goto slow_helper_call
r5 += r_offset                           ; reg-reg ADD (was imm)
ldx_b r4, [r5 + 0]
stx_b [r3 + 0], r4
...
```

Semantically identical to the const-offset rewrite plus a runtime bounds
check on the dynamic value.

### 7.2 Why the pass author didn't do it

For the verifier to accept the rewrite, the dynamic offset value must be
provably:
1. Non-negative (otherwise `r5 += negative` underflows out of
   PacketData range and the verifier rejects subsequent loads).
2. Bounded above (otherwise `r2 = r5 + offset + len` overflows or
   verifier gives up on packet range tracking).

These properties are available in the verifier's `umin_value` /
`umax_value` for the register, but `LiftedRegFact` (the in-pass abstract
domain) only has `Const(i64)` — no range. The pass author chose the
simpler const-only admission instead of plumbing verifier range info
into the abstract domain.

### 7.3 Implementation cost

| Task | LOC |
|---|---:|
| `emit_replacement` accepts `(offset_arg, len_const)` and emits reg-reg ADD | ~30 |
| `classify_site` admits non-`Const` arg2 when verifier range proves non-negative and bounded | ~50 |
| Read verifier-state range info (extend `RegKind` / `verifier_log` parse to surface `umin/umax`) | ~40-80 |
| Overflow / upper-bound safety in emit (reject when `umax + len >= MAX_PACKET_SIZE`) | ~20 |
| Tests (const baseline, non-neg dynamic, bounded dynamic, unbounded → reject) | ~100 |
| **total** | **~240-280** |

## 8. Gate 1 and Gate 2 dependency

| Scenario | arg1 modified | offset support | Applied gain |
|---|---|---|---:|
| Today | — | — | 0 |
| Option C only | yes | no | +7 |
| Gate 2 only | no | yes | **0** (arg1 still kills 234) |
| Option C + Gate 2 | yes | yes | **+234** |

Gate 2 alone has zero gain because Gate 1 is checked first and rejects
all 234 sites before `arg2` is read. The two fixes are necessary in
order: arg1 must be unblocked for any of the 227 offset-dynamic sites to
even reach the Gate 2 check.

## 9. Other-pass impact summary

Option C is pass-local; no impact on other passes.

| Pass | Option C | Option B (full dataflow) |
|---|---|---|
| `skb_load_bytes_spec` | +7 applied | +7 applied (same) |
| `bounds_check_merge` | 0 | possible small gain on Cilium diamond joins, blocked elsewhere by detector / ladder safety (see separate report) |
| `const_prop` | 0 (uses verifier states, not LiftedRegFact) | 0 |
| `map_inline` | 0 (uses alias maps / verifier side input) | 0 |

## 10. Final recommendation

| Plan | Action | Apply gain | LOC |
|---|---|---:|---:|
| A (do nothing) | revert K=20, accept current 8 applied | 0 | 0 |
| B (small) | Option C only (simplified), keep K=20 | +7 | ~220 |
| C (full) | Option C + Gate 2 dynamic-offset support | +234 | ~620 |

Recommendation: pursue plan **C**, in two phases:

1. **Phase 1**: implement Option C (simplified) + keep K=20. Verify the
   predicted +7 in a Cilium isolated run. Total ~220 LOC.
2. **Phase 2**: implement Gate 2 dynamic-offset support. Verify the
   predicted +220 in a second Cilium isolated run. Total ~280 LOC.

Phase 1 is prerequisite for Phase 2 (Gate 1 must unblock the water for
Gate 2's reduction to materialize). Splitting into two commits gives
clean before/after numbers per phase and matches the "fix forward in
small steps" convention.

If the project decides paper-grade apply gains on Cilium NAT path are
not a priority right now, plan **A** (revert K=20) is the clean exit.

## 11. Open questions for follow-up

- Concrete Cilium offset patterns: is `ip_offset = ETH_HLEN + (iph->ihl << 2)`
  the dominant shape, or are there others (e.g. encapsulation offsets,
  TLV walks)? A small grep across `runner/repos/cilium/bpf/lib/` would
  inform whether the range bound is uniformly `< 80` (Ethernet + max
  IPv4) or whether arbitrary depths exist.
- Verifier range info plumbing: does `verifier_log` already parse
  `umax_value` / `umin_value` from the verifier log, or does that need
  to be added? If yes, Phase 2 cost drops by ~40-80 LOC.
- `BPF_MAP_TYPE_LRU_HASH` and similar map-induced helper clobbers in
  Option C's stack-overwrite walk: helpers can clobber stack slots only
  via written-pointer arguments, not arbitrarily. Confirm via reading
  `helper-related stack invalidation rules` in
  `runner/repos/linux/kernel/bpf/verifier.c` before implementing the
  conservative clobber check.
