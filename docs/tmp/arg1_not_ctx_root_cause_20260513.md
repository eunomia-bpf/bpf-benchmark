# arg1_not_ctx root cause and fix proposal (2026-05-13)

## Verdict

Root cause confirmed, with one important refinement: the first loss is the reset-on-join in `compute_lifted_reg_facts`, but the concrete Cilium SNAT program also needs ctx spill/reload recovery before the helper call; recommended fix is Option C, a targeted CFG/use-def fallback for `skb_load_bytes_spec` arg1 that recognizes entry-ctx callee-saved regs and ctx stack spills, with expected immediate gain of about +7 newly applied `skb_load_bytes_spec` sites on the current Cilium runs.

## Concrete trace

Chosen program: baseline result `corpus/results/x86_kvm_corpus_20260513_195951_262316/details/apps/cilium__agent.json`, `prog_id=109`, `prog_name=tail_handle_sna`, `orig_insn_count=2617`. Its `skb_load_bytes_spec` report says `sites_matched=13`, `sites_applied=0`, `sites_skipped=13`, all skipped as `arg1 is not ctx`.

Concrete bytecode artifact: `bpfopt/testbin/cilium_agent/166_tail_handle_snat_fwd_ipv4/canonicalize_output.bin`, 20936 bytes = 2617 raw little-endian `struct bpf_insn` entries. Helper 26 call PCs:

```text
93, 105, 205, 389, 463, 475, 501, 556, 630, 654, 796, 809, 1042
```

Entry setup shows the original skb ctx is preserved in `r9`, not `r6` or `r7` in this concrete program:

```text
0:  r9 = r1
1:  r7 = 0
...
13: r2 = *(u32)[r9+80]   ; skb data_end field
14: r6 = *(u32)[r9+76]   ; skb data field, not ctx
15: r6 += r1             ; lifted fact becomes Unknown
...
31: *(u64)[r10-168] = r9 ; ctx spill
```

So the skb ctx carrier is:

```text
entry r1(ctx) -> r9 -> fp[-168] -> r9 or r1 -> helper arg1
```

Decoded window for helper site PC 93:

```text
63: r1 = ldimm64(src=5, imm_lo=1)
65: call helper 1
67: if r0 == 0 goto 310
68: r1 = *(u32)[r0+36]
69: if r1 == 0 goto 310
70: r2 = ldimm64(src=6, imm_lo=0)
72: r2 = *(u32)[r2+0]
73: if r1 == r2 goto 310
74: r1 = *(u8)[r10-148]
75: if r1 == 17 goto 173
76: if r1 == 6 goto 173
77: if r1 != 1 goto 245
78: r7 = r0
79: r1 = 0 (32)
80: *(u16)[r10-24] = r1
81: r1 = ldimm64(src=0, imm_lo=0)
83: r2 = r8
84: r2 &= r1
85: r8 = -134 (32)
86: r9 = *(u64)[r10-168]
87: if r2 != 0 goto 261
88: r3 = r10
89: r3 += -40
90: r1 = r9
91: r2 = *(u32)[r10-208]
92: r4 = 2 (32)
93: call helper 26
```

Decoded window for helper site PC 205:

```text
175: *(u32)[r10-144] = r1
176: r1 = *(u32)[r6+12]
177: r2 = 0 (32)
178: *(u8)[r10-133] = r2
179: r2 = r8
180: r2 >>= 32
181: *(u8)[r10-134] = r2
182: *(u16)[r10-136] = r8
183: *(u32)[r10-140] = r1
184: r1 = ldimm64(src=0, imm_lo=0)
186: r2 = r8
187: r2 &= r1
188: if r2 == 0 goto 199
189: r2 = r10
190: r2 += -144
191: r1 = ldimm64(src=5, imm_lo=4)
193: call helper 1
195: if r0 == 0 goto 252
196: r1 = *(u32)[r0+0]
197: *(u32)[r10-152] = r1
198: goto 2563
199: r7 = r10
200: r7 += -152
201: r1 = *(u64)[r10-168]
202: r2 = *(u32)[r10-208]
203: r3 = r7
204: r4 = 4 (32)
205: call helper 26
```

Use-def chain at PC 93:

```text
PC 93 arg1
  <- PC 90: r1 = r9
  <- PC 86: r9 = *(u64)[fp-168]
  <- PC 31: *(u64)[fp-168] = r9
  <- PC 0:  r9 = r1
  <- entry: r1 is ctx
```

Use-def chain at PC 205:

```text
PC 205 arg1
  <- PC 201: r1 = *(u64)[fp-168]
  <- PC 31:  *(u64)[fp-168] = r9
  <- PC 0:   r9 = r1
  <- entry:  r1 is ctx
```

First join where lifted ctx is lost:

```text
B1 pc 19..27 terminator: if r3 == 0 goto B3, fallthrough B2
B2 pc 28..30 terminator: fallthrough B3
B3 pc 31..33 predecessors: [B1, B2]
```

`should_reset_linear_state_at_block(B3)` returns `true` because `preds.len() != 1`. Along both predecessors, `r9` still carries the original ctx and `r10` is still `fp`, but the current linear walker resets all regs to `Unknown` except `r10 = FpOff(0)`. Therefore the lifted fact sequence is:

```text
entry:      r1 = Ctx
after PC0:  r9 = Ctx
B3 entry:   reset -> r9 = Unknown
PC31 store: fp[-168] is written from Unknown r9
PC86 load:  r9 = Unknown, because stack facts are not tracked
PC90 mov:   r1 = Unknown
PC93 call:  reg_fact_at(site, 1) = Unknown -> "arg1 is not ctx"
```

The join reset is the first incorrect loss of `Ctx`. However, for this concrete program a reg-only join fix would still leave PC 93 blocked at PC 86, because `LiftedRegFact` does not currently preserve ctx through stack spill/reload.

## Apply-gain projection

Method: matched result skip sites from the two Cilium runs to local `bpfopt/testbin/cilium_agent/*/canonicalize_output.bin` artifacts by instruction count plus helper-26 PC list, then ran a read-only decoder/CFG analysis over raw `struct bpf_insn[]`.

For baseline K=8 result `x86_kvm_corpus_20260513_195951_262316`:

| Classification | Sites |
| --- | ---: |
| Current `arg1 is not ctx` skips | 234 |
| Would have `arg1 == Ctx` with reg-only predecessor meet | 145 |
| Still need ctx stack spill/reload recovery | 89 |
| Would have `arg1 == Ctx` with CFG meet plus ctx stack recovery | 234 |
| Then pass offset/dest/len gates and should apply | 7 |
| Then fail next gate, almost entirely non-constant offset | 227 |

For K=20-shaped result `x86_kvm_corpus_20260513_200534_705861`:

| Classification | Sites |
| --- | ---: |
| Current `arg1 is not ctx` skips | 187 |
| Would have `arg1 == Ctx` with reg-only predecessor meet | 98 |
| Still need ctx stack spill/reload recovery | 89 |
| Would have `arg1 == Ctx` with CFG meet plus ctx stack recovery | 187 |
| Then pass offset/dest/len gates and should apply | 7 |
| Then fail next gate, almost entirely non-constant offset | 180 |

Interpretation: all 234 and all 187 `arg1` skips are false negatives for ctx under a CFG-aware ctx propagation model. The immediate `sites_applied` increase is much smaller, about +7, because most newly unblocked sites then fail the `offset is not constant` gate. This matches the shape of the C2 audit: the arg1 filter hid the later gates, but the paper-visible near-term application gain is single digit unless offset recovery is also improved.

## Fix proposal

| Option | Production LOC | Affected APIs | Risk to other passes | Expected `arg1` unlock | Expected `skb_load_bytes_spec` apply gain |
| --- | ---: | --- | --- | ---: | ---: |
| C. Targeted site-level fallback | 60-100 | None if private to `skb_load_bytes.rs`; optional new private `ProgramCFG` helper if shared | Low. Only changes arg1 admission for helper 26. Must be CFG-aware, not linear last-def only, and must recognize ctx stack spills conservatively. | 234/234 K=8, 187/187 K=20 | About +7 |
| A. Small reg-only predecessor meet | 80-120 | No public API change; internal `compute_lifted_reg_facts` tracks per-block entry/exit regs and meets equal predecessor facts | Medium-low. Sound if equality meet handles helper clobbers, pseudo-calls, and loops correctly. Global `reg_fact_at` becomes less conservative. | 145/234 K=8, 98/187 K=20 | About +7 if the apply-ready sites are in direct-reg ctx cases |
| B. Full forward dataflow | 180-260 | Internal structural change: introduce a `LiftedFactState`, make `advance_lifted_regs` state-transforming, add worklist meet. Public `reg_fact_at` can stay unchanged. If stack facts are included, `LiftedRegFacts` grows an internal stack-fact map. | Medium. Best long-term shape, but broadest behavior change for all consumers of `reg_fact_at`. Needs careful tests around joins, loops, helper clobbers, stack overwrite aliasing, and subprog boundaries. | Reg-only: 145/234 and 98/187. With ctx stack facts: 234/234 and 187/187 | About +7 now; more only if offset recovery improves |

Option C should include stack-spill recognition. A fallback that only recognizes `r1 = rN` where `rN` was assigned from entry ctx misses the concrete SNAT program, because PC 93 goes through `fp[-168]`.

## Other-pass impact

`skb_load_bytes_spec`: high impact on Cilium tail programs. Reg-only meet fixes many direct callee-saved ctx cases, but the concrete SNAT path needs stack spill/reload recovery. Expected immediate `sites_applied` delta is about +7 on both current K=8 and K=20-shaped runs; arg1 false-negative count drops to zero with Option C or Option B plus stack facts.

`bounds_check_merge`: consumes `LiftedRegFact::PacketData` and `PacketEnd` at guard compare sites. A global join meet can expose packet facts across simple diamonds, so apply counts may increase on Cilium tail programs, but expected delta is low because most Cilium packet guard ladders are already local or blocked by structural ladder rules. Option C has no impact.

`const_prop`: no expected impact. It does not consume `LiftedRegFact`; it uses verifier-derived `reg_kind` and `reg_known_constant`.

`map_inline`: low expected impact. The main map-value alias recovery uses local alias maps and verifier/map side inputs; `reg_fact_at` is only used for frame-pointer stack-base recognition in key extraction helpers. A global join meet may help a few stack-base cases, but Cilium skips are primarily key materialization and map-value availability, not ctx propagation. Option C has no impact.

Unknown-meaning-no-info soundness: no pass should rely on `Unknown` as a positive fact. The risk is not semantic dependence on `Unknown`; the risk is making `reg_fact_at` less conservative by mistake. Equality meet over all predecessors is sound for registers. Stack facts require conservative overwrite/overlap handling.

## Recommendation

Implement Option C first in `skb_load_bytes_spec`: when `prog.reg_fact_at(site, 1)` is `Unknown`, run a bounded CFG/use-def ctx-origin query for arg1 that accepts only values proven to originate from entry `r1` through callee-saved moves and exact ctx stack spill/reload slots. Keep it local to helper-26 admission, add focused tests for the SNAT pattern (`r9 -> fp[-168] -> r1`) and a negative conflicting-store case, then rerun Cilium corpus through `make corpus` with `BPFREJIT_BENCH_PASSES=skb_load_bytes_spec`.

Do not implement a broad `reg_fact_at` dataflow rewrite as the first fix. It is the right cleanup direction, but it is larger and still incomplete for the concrete SNAT program unless stack facts are added.
