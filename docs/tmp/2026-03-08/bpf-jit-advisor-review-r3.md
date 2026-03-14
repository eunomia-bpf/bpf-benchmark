# Review of BPF-JIT Advisor Design (Round 3)

## Overall Verdict

v3 resolves the two main R2 blockers in substance. This now reads as a plausible **verifier-assisted JIT** design, not a fragile "userspace hint UAPI" story. For the narrowed scope, I no longer see a conceptual blocker.

That said, this is true only for the narrow v1 the draft now describes:

- `wide-load-ok` only for aligned constant-offset `PTR_TO_STACK` / `PTR_TO_MAP_VALUE` byte-load regions;
- `select-region` as a local post-verifier control-flow pattern;
- userspace as optional candidate discovery only;
- permanent UAPI acceptance as a non-goal.

If the authors drift back toward generic hint-UAPI or broad cross-arch claims, the design becomes overstated again.

## 1. Post-Verifier Drift (`orig_to_post`)

**Assessment: mostly resolved.**

- The explicit `orig_insn_off -> post_insn_off` remap is the right fix. It is much more realistic than trying to reuse `orig_idx`.
- The proposed update points are the right ones: the verifier already adjusts other instruction-sensitive metadata in the same patch/remove paths.
- Anchoring each original instruction to the **first** rewritten slot is the correct JIT contract, because the JIT rematches locally on the post-verifier program anyway.
- The fail-closed behavior is now right: deleted anchors become `U32_MAX`, and userspace never supplies post-verifier coordinates.

One missing implementation detail still needs to be written down explicitly:

- the temporary per-insn JIT scratch metadata must be shifted/zeroed on the same insert/remove paths as `insn_aux_data`; otherwise the final copied summary can drift even if `orig_to_post` itself is correct.

## 2. Verifier-Retained Facts

**Assessment: now concrete enough for a v1 prototype, but one conservative-merge rule is still missing.**

- The retained fields are now small, concrete, and tied to real verifier state: `ptr_type`, `mem_class`, `fixed_off`, `max_readable_bytes`, `max_aligned_width`.
- The update point is believable: snapshot the facts at `check_load_mem()` time, while the verifier still has `bpf_reg_state`, stack state, and map metadata.
- Narrowing `wide-load-ok` to aligned stack/map-value byte loads was the right decision. Packet/ctx were the parts that kept the previous draft non-credible.

The remaining missing detail is path merging:

- if the same load is reached under multiple verifier states, the document should say exactly how facts are joined;
- the safe rule is conservative intersection: disagreement on memory class or fixed offset kills the candidate; readable/alignment widths become the minimum across paths.

I would also make one small implementation correction:

- `fixed_off` should probably be stored as `s32`, not `s16`, to avoid an unnecessary truncation hazard.

## 3. Framing: Verifier-Assisted JIT vs Hint UAPI

**Assessment: much stronger than the original framing.**

- The main architectural story is now the right one: verifier computes the legality basis; JIT consumes it; userspace is optional.
- That is both more realistic technically and more defensible to systems reviewers.
- The paper now compares against the right baseline: **verifier-assisted JIT without userspace**.

This is the right direction. The authors should keep saying:

- this is a research prototype for factorization and candidate discovery;
- direct peepholes remain the more upstreamable end state for mature local patterns;
- permanent hint UAPI is not the paper's claim.

## 4. Minimum Viable Prototype in 2-4 Weeks

**Assessment: yes, but only for a very narrow MVP.**

Plausible 2-4 week MVP:

1. x86-64 only;
2. verifier-retained summary plus **kernel-only full local scan** first;
3. `wide-load-ok` only for aligned 2/4/8-byte stack/map-value regions;
4. `select-region` only if it lands cheaply after wide-load;
5. microbenchmarks first, not broad corpus coverage;
6. optional userspace candidate transport only after the kernel-only path works.

One practical caveat should be stated explicitly:

- a region-consuming JIT optimization still has to assign coherent per-insn `addrs[]` / offset-table entries for every consumed BPF slot, and must reject interior branch targets. This is feasible, but it is not "just emit one instruction and skip N."

Not plausible in 2-4 weeks:

- x86 + arm64 together;
- polished `hint_fd` transport plus robust llvmbpf extraction;
- broad real-program coverage;
- any upstream-ready story.

So the MVP is buildable, but it should be framed as:

- week 1-2: verifier summary + x86 JIT consumer;
- week 3: direct-peephole and verifier-assisted baselines;
- week 4: optional userspace candidate path and robustness tests.

## 5. Remaining Showstoppers

**For the narrowed prototype: no fundamental showstopper remains.**

The remaining risks are now engineering details, not missing core ideas:

- specify conservative join semantics for `record_jit_load_aux()` across verifier path merges;
- state explicitly that the temporary JIT scratch array follows the same rewrite adjustments as `insn_aux_data`;
- keep evaluation centered on `stock JIT` vs `direct peepholes` vs `verifier-assisted JIT` vs `+ userspace candidates`.

These are important, but they are not the same kind of blocker as R2's "post-verifier drift is unsolved" or "retained facts are vague."

## 6. Updated Scores

| Dimension | R2 | R3 | Rationale |
| --- | ---: | ---: | --- |
| Technical quality | 7/10 | **8/10** | The hard kernel-side story is now explicit and narrow enough to implement. Remaining issues are conservative merge details, not an absent mechanism. |
| Novelty | 7/10 | **7/10** | The core novelty is unchanged, but it is now framed more cleanly as verifier-assisted backend lowering rather than as a hint ABI. |
| Presentation clarity | 9/10 | **9/10** | This revision is clear, disciplined, and much better scoped than earlier versions. |
| Feasibility | 5/10 | **7/10** | A narrow x86-first prototype is now believable. A broad cross-arch / UAPI-heavy system is still not. |
| Overall publishability at OSDI/SOSP | 6/10 | **7/10** | This is now paper-shaped. The remaining gap is prototype evidence, not a broken design core. |

## 7. Recommended Next Steps

1. Add one paragraph defining how per-load facts merge across revisited verifier states.
2. State explicitly that the temporary `jit_load_aux` array is updated on every verifier patch/remove path, just like `insn_aux_data`.
3. Freeze the MVP to x86-only verifier-assisted JIT first; treat userspace candidates as a second-stage ablation, not the first milestone.
4. Keep `wide-load-ok` restricted to aligned stack/map-value loads and defer packet/ctx completely.
5. Make the evaluation table front-and-center: `stock`, `direct peephole`, `verifier-assisted JIT`, `verifier-assisted JIT + candidates`.
6. Do not let the paper claim drift back toward "this hint UAPI should be upstreamed."

## Bottom Line

R2's two main blockers are now largely resolved. The design is finally credible as a **narrow verifier-assisted JIT prototype**. What remains is not a missing idea, but the usual systems-paper work: pin down two conservative implementation rules, build the narrow x86 prototype, and show that optional userspace candidates buy something beyond verifier-assisted JIT alone.
