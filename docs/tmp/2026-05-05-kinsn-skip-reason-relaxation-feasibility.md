# Feasibility study for kinsn skip-reason relaxation

Date: 2026-05-05

Input result:
`corpus/results/x86_kvm_corpus_20260505_220116_564226/details/result.json`

Scope constraints:
- This is a source and artifact feasibility study only. No code changes were made.
- Rotate matcher coverage is owned by the separate rotate investigation and is not re-analyzed here.
- Endian load16/load32 enablement is already in flight; this report only confirms current status and likely remaining gaps.

## Executive summary

The largest recoverable skip family is the kinsn tail-call guard, and source inspection confirms it is a true program-wide blanket: if any instruction in the program is a tail-call helper, every kinsn replacement site in that program is skipped. The current artifacts show 1,887 tail-call skips across `cond_select`, `bulk_memory`, `extract`, and `endian_fusion`, much larger than the prompt's approximate count because `result.json` counts every skipped site across every live program. The best first relaxation is a layout-safe tail-call rule, not a semantic CFG reachability rule: allow replacements that cannot move tail-call instruction indices, especially fixed-length replacements after the last tail-call, while keeping the current fail-fast skip for size-changing or tail-call-overlapping sites. Endian load16/load32 should mostly disappear after the current daemon probe fix is rerun. `cond_select` scratch spilling has real upside but needs stack-slot liveness or verifier-state support. `bulk_memory` different-base aliasing is tractable only with a conservative pointer provenance analysis. Interior branch targets have the worst risk-to-upside ratio because multi-entry replacement regions require semantic equivalence for every branch entry.

- A, tail-call blanket: highest new-code ROI, but start with layout-preserving per-site relaxation rather than broad CFG reachability.
- B, no immediate scratch register: good upside, medium cost; needs conservative stack-spill support and stack-slot safety analysis.
- C, different-base memcpy alias: modest upside; safe only with pointer provenance and interval reasoning, not a broad "different regs are different objects" rule.
- D, interior branch target: small to moderate upside, high semantic risk; only internal-target or PC-stable cases are good candidates.
- E, endian load16/load32 missing: likely already fixed by the in-flight daemon probe change; rerun before doing more work.

## Per-family deep dive

### A. `kinsn site in program with tail-call helper`

#### 1. Current code path

Every kinsn pass uses the same shared guard:

- `bpfopt/crates/bpfopt/src/passes/cond_select.rs:188` calls `kinsn_replacement_subprog_skip_reason`.
- `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:176` calls `kinsn_replacement_subprog_skip_reason`.
- `bpfopt/crates/bpfopt/src/passes/extract.rs:145` calls `kinsn_replacement_subprog_skip_reason`.
- `bpfopt/crates/bpfopt/src/passes/endian.rs:459` calls `kinsn_replacement_subprog_skip_reason`.
- `bpfopt/crates/bpfopt/src/passes/rotate.rs:65` has the same call, but rotate has zero matches in this result and is out of scope here.
- `bpfopt/crates/bpfopt/src/passes/ccmp.rs:197` has the same call for the arm64-only pass.

The shared implementation is in `bpfopt/crates/bpfopt/src/passes/utils.rs`:

- `kinsn_replacement_subprog_skip_reason` at `utils.rs:719` checks subprogram boundaries, replacement boundaries, and subprogram entry overlap.
- It then calls `kinsn_replacement_tail_call_skip_reason` at `utils.rs:769`.
- `kinsn_replacement_tail_call_skip_reason` at `utils.rs:773` scans every instruction in the program and returns the first tail-call helper it finds.
- The exact emitted skip is at `utils.rs:779`: `kinsn site in program with tail-call helper (tail call pc {pc}, site pc {start_pc})`.
- Tail calls are detected by `is_tail_call_insn` at `utils.rs:805`, either helper call immediate `BPF_FUNC_tail_call` or the tail-call pseudo encoding.

The guard does not compare the tail-call PC with the candidate site, does not inspect CFG reachability, and does not inspect whether the replacement changes instruction count before a tail-call site. It is a blanket per-program disable for kinsn replacements.

The exact assumption is: in a program containing any tail-call helper, any kinsn replacement may invalidate kernel tail-call poke descriptors or text-poke state, so every site in that program is skipped.

Related source: `tail_call_protected_prefix_end` at `utils.rs:787` returns the end of the last tail-call instruction. Non-kinsn passes use this more granular concept. For example, `const_prop` has tail-safe replacement filtering, while `dce` disables instruction-deleting cleanup when tail calls are present.

#### 2. Minimum required relaxation

The smallest safe relaxation is layout-based, not full CFG reachability:

```text
tail = TailCallLayoutAnalysis::run(program)
if tail.tail_pcs.is_empty():
    allow

if replacement_len == old_len and site_start >= tail.last_tail_end:
    allow

skip("kinsn site in program with tail-call helper ...")
```

This would preserve the current behavior for all size-changing replacements before or through tail-call instructions, while allowing fixed-length replacements that occur after the tail-call-protected prefix. The implementation can live inside the existing shared helper so individual passes do not grow custom tail-call policies.

A second-stage relaxation can be more aggressive:

```text
tail = TailCallLayoutAnalysis::run(program)
if replacement range contains a tail-call pc:
    skip
if replacement changes instruction count before any tail-call pc:
    skip
if all affected branch and subprog metadata remap cleanly:
    allow
```

That second stage depends on an explicit invariant: no rewrite may move a tail-call instruction PC unless the kernel-side ReJIT path is known to rebuild all tail-call poke descriptors correctly. The sibling error-analysis report shows tail-call/text-poke failures are still a real kernel-side risk, so this invariant should stay conservative.

Full CFG reachability from a tail-call dispatch is not the right minimum change. A branch-unreachable site can still precede a tail-call instruction in linear instruction order and move its PC if the replacement changes length. The first safety condition is layout stability of tail-call PCs; reachability is secondary.

#### 3. Correctness obligations

- Tail-call instruction PCs must not move unless kernel ReJIT is proven to refresh all related poke descriptors. This needs a small new `TailCallLayoutAnalysis`, using the existing `is_tail_call_insn` logic.
- The replacement range must not include a tail-call instruction. This is a small extension to the same layout analysis.
- The replacement must remain inside one subprogram and must not cover a subprogram entry. This is already enforced by `kinsn_replacement_subprog_skip_reason`.
- Branch targets and BTF metadata must remap consistently when the replacement changes length. Existing helpers `fixup_all_branches` and `remap_kinsn_btf_metadata` already provide this for normal sites.
- Tail-call verifier or text-poke failures must surface naturally as ReJIT errors. This is a hard kernel constraint, not something bpfopt should paper over.

#### 4. Implementation cost estimate

- First-stage layout relaxation: about 60-120 LOC, mostly in `bpfopt/crates/bpfopt/src/passes/utils.rs`, plus tests.
- If promoted to a reusable analysis module: about 100-180 LOC across `bpfopt/crates/bpfopt/src/analysis/` and the shared pass utility.
- No daemon-side change required.
- No new kinsn registration required.
- No new BPF syscall behavior required.
- CFG/reachability variant: about 150-300 LOC and more tests, but should not be the first implementation.

#### 5. Apply-count upside estimate

From `result.json`, this family accounts for 1,887 skipped sites:

- `cond_select`: 1,504
- `bulk_memory`: 192
- `extract`: 185
- `endian_fusion`: 6

Parsing the embedded `tail call pc` and `site pc` text shows 1,512 skipped sites have `site_pc > first_tail_call_pc`, and 375 have `site_pc < first_tail_call_pc`. This is only a lower-quality proxy because the skip reason records the first tail call found, not the last tail call in the program.

Conservative first-stage unlock is indeterminate and needs a prototype, because the current artifacts do not record replacement length or last-tail-call PC for each skipped site. Likely high-confidence wins are exact-length replacements after the protected tail-call prefix, especially `extract` and some `endian_fusion` sites. `cond_select` and `bulk_memory` may often change instruction count, so they need the length check before counting them as unlockable.

The theoretical upper bound is 1,887 sites, but that is not a realistic first patch target.

#### 6. Risk of regression

Current kinsn sites in programs without tail calls should not change if the guard is relaxed only for tail-call programs. The regression risk is in newly applied sites:

- ReJIT may fail with tail-call/text-poke errors if the layout invariant is wrong.
- A size-changing replacement before a tail-call PC could corrupt kernel poke metadata.
- Existing tests in `utils.rs` that assert blanket rejection for sites before and after a tail call need to be split into before-prefix rejection and after-prefix fixed-length allowance.
- Pass happy-path tests should stay valid, but new positive tests should be added for at least one fixed-length replacement after the tail-call-protected prefix.

### B. `no dead register available to materialize immediate operand`

#### 1. Current code path

This skip is specific to `cond_select`.

- `CondSelectPass::required_analyses` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:89` requires `branch_targets` and `liveness`.
- The pass obtains `live_after` for the site at `cond_select.rs:150`.
- `build_lowering` at `cond_select.rs:401` calls `condition_prefix` and `materialize_value`.
- `materialize_value` at `cond_select.rs:562` must materialize an immediate alternative into a temporary register.
- The exact skip is emitted at `cond_select.rs:577`: `no dead register available to materialize immediate operand`.
- `choose_temp_reg` at `cond_select.rs:599` only chooses `dst_reg` or `r0..r9` if the register is not protected, not already allocated, and not live after the site, except that the destination register is allowed.

The exact assumption is: an immediate alternative can only be materialized into an already dead register. The pass does not spill a live register, does not allocate a stack scratch slot, and cannot use `r10` as a general temporary.

#### 2. Minimum required relaxation

The smallest behavior change that can unblock most sites is a conservative spill-and-restore fallback when no register is dead:

```text
tmp = choose_temp_reg(...)
if tmp exists:
    materialize immediate into tmp
else:
    victim = choose_spillable_live_reg(...)
    slot = choose_safe_stack_slot(site_pc)
    prefix += STXDW [r10 + slot], victim
    prefix += MOV64_IMM victim, imm
    use victim as the kinsn operand
    suffix += LDXDW victim, [r10 + slot]
```

This requires `CondSelectLowering` to support a suffix after the kinsn call, not only a prefix before it. The current implementation builds a prefix, sidecar load, and call replacement. It does not currently restore a spilled live register after the call.

A narrower, lower-risk first step is to improve temporary reuse before stack spilling:

```text
after predicate has been computed:
    release condition temp if no longer needed
    allow it to materialize one immediate operand
```

That helps only if failures are caused by conservative temp reservation rather than genuinely all registers being live. It is unlikely to recover most of the 320 sites by itself.

#### 3. Correctness obligations

- The spill slot must not clobber live stack data. Existing liveness tracks registers only, not stack slots, so this needs a new stack-slot safety analysis.
- The spill and restore must dominate all uses of the victim register. Current `cond_select` rejects interior branch targets before lowering, so the replacement region is straight-line; this makes the spill tractable as long as family D is not relaxed at the same time.
- The victim register must remain a scalar value acceptable to spill and reload. This can be enforced using verifier-state metadata if available for the site; otherwise the analysis should be very conservative.
- The kinsn call must not leave the victim live-clobbered after restore. A suffix restore is needed because helper/kfunc calls normally clobber caller-saved registers.
- Program growth must stay within ReJIT size limits. The sibling report shows size-related failures already occur for some `cond_select` growth cases. A spill fallback adds at least two more instructions per site.

Existing analysis coverage:

- Register live-out: already available from `LivenessAnalysis`.
- Branch-free replacement window: already available through `BranchTargetAnalysis` and the current interior-target rejection.
- Stack-slot liveness: not available; this is a small new analysis if restricted to verifier-known stack slots, but hard if inferred only from raw instruction scans.
- ReJIT size budget: hard kernel constraint; bpfopt should not guess past it.

#### 4. Implementation cost estimate

- Temp reuse only: about 30-80 LOC in `cond_select.rs`, low risk, limited upside.
- Spill-and-restore fallback: about 120-250 LOC in `cond_select.rs` for suffix support, victim selection, address-map handling, and tests.
- Stack-slot safety analysis: about 80-160 LOC if built from verifier-state stack facts; more if implemented as raw instruction analysis.
- No daemon-side change required.
- No new kinsn registration required.
- No kernel change required.

#### 5. Apply-count upside estimate

This family accounts for 320 skipped `cond_select` sites across 55 programs. By app, the skips are concentrated in Tetragon, with smaller counts in Tracee and otelcol.

An exact unlock count is indeterminate without a prototype because the artifacts do not record live register sets or stack-slot availability for skipped sites. A stack-spill fallback could plausibly unlock a majority of the 320 if safe stack slots are common. A conservative estimate is 150-250 sites. Temp reuse alone is likely much lower and should be measured before relying on it.

#### 6. Risk of regression

Existing applied `cond_select` sites can regress if the lowering refactor changes prefix generation or address remapping. The risk is mostly in the implementation structure, not in the new sites.

Tests that need attention:

- Immediate materialization happy paths in `cond_select_tests` around the immediate/reg and both-immediate cases.
- `test_cond_select_packed_keeps_live_regs` should continue to prove live registers are preserved.
- `test_cond_select_packed_no_callee_saved_dependency` should remain valid because the spill fallback must not depend on callee-saved behavior.
- Add one positive test where all usable registers are live and a stack spill enables the rewrite.
- Add one negative test where no safe stack slot is available.

The main behavioral risk is silent stack corruption from an unsound stack-slot analysis. That must be prevented by keeping the first implementation verifier-state-backed or very conservative.

### C. `different-base memcpy alias not provably safe`

#### 1. Current code path

This skip is specific to `bulk_memory`.

- `BulkMemoryPass::required_analyses` at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:109` requires `branch_targets` and `liveness`.
- `try_match_memcpy_run_at` at `bulk_memory.rs:308` builds a run of load/store pairs.
- The alias gate is at `bulk_memory.rs:133`.
- It calls `is_likely_stack_ptr` for the source and destination base registers at `bulk_memory.rs:138`.
- If the source and destination bases differ but both are classified the same way, the pass emits the skip at `bulk_memory.rs:142`: `different-base memcpy alias not provably safe (src r{src_base}, dst r{dst_base})`.

The exact assumption is: when source and destination base registers differ, the pass can only prove non-aliasing if one base is likely stack-derived and the other is not. If both look stack-like or both look non-stack-like, the copy may overlap and must not be replaced by the bulk memcpy kinsn.

Existing same-base overlap is handled separately by offset interval checks and `ranges_overlap`. Existing `RegValue` tracking in the file only supports local constant propagation for memset-like patterns. It is not pointer provenance analysis.

#### 2. Minimum required relaxation

The smallest safe relaxation is conservative pointer provenance plus byte interval reasoning:

```text
src_ptr = pointer_provenance_at(site_pc, src_base)
dst_ptr = pointer_provenance_at(site_pc, dst_base)

src_range = src_ptr.offset_range + copied_src_offsets
dst_range = dst_ptr.offset_range + copied_dst_offsets

if proven_disjoint(src_ptr, src_range, dst_ptr, dst_range):
    allow bulk memcpy
else:
    skip different-base alias
```

The first implementation should only prove simple cases:

- `r10` stack-derived base plus known fixed offset.
- Register copies from stack-derived bases with immediate add/sub adjustments.
- Clearly disjoint provenance categories, for example stack versus map value, packet data, or context, only when the category is known and not inferred by naming.
- Two stack-derived bases with exact non-overlapping intervals.

An overlap-safe variant would be a different feature: a new `memmove_bulk` or directional-copy kinsn. That is not the minimum relaxation because it requires new module registrations and new JIT emit code.

#### 3. Correctness obligations

- If the analysis says source and destination are disjoint, they must be disjoint for every verifier-accepted runtime state. Existing analyses do not provide this; a new pointer provenance analysis is required.
- Stack intervals must be exact when used to prove non-overlap. The existing `is_likely_stack_ptr` lookback is not enough because it returns only a boolean.
- Unknown pointer provenance must stay skipped. The analysis cannot treat different registers as different objects.
- Overlapping copies must preserve original load/store ordering. With the existing memcpy kinsn, overlapping different-base copies should remain skipped unless a new overlap-safe kinsn exists.
- Existing temporary-register liveness checks at `bulk_memory.rs:373` must remain in force.

#### 4. Implementation cost estimate

- Restricted provenance analysis in `bulk_memory.rs` or a new analysis module: about 150-300 LOC plus tests.
- More general may-alias graph: 400+ LOC and not recommended as a first patch.
- Overlap-safe kinsn route: about 250-500 LOC across module x86/arm64 emit code, daemon probing, bpfopt registry, pass logic, and tests.
- No daemon-side change is needed for the conservative provenance route.
- No new kinsn registration is needed for the conservative provenance route.

#### 5. Apply-count upside estimate

This family accounts for 99 skipped `bulk_memory` sites:

- `src r0, dst r7`: 60
- `src r0, dst r8`: 30
- Smaller counts for `r0 -> r9`, `r0 -> r6`, `r1 -> r8`, `r8 -> r7`, and `r0 -> r2`

By app, 97 of these are in Tracee and 2 are in Tetragon.

Because most sites are `r0` to a callee-saved register, many may be helper-return pointer to stack or object-buffer copies. If a prototype proves `r0` provenance and stack destination intervals, a restricted analysis might unlock 60-90 sites. If `r0` provenance is unknown at those PCs, the safe unlock count is indeterminate and could be much smaller.

#### 6. Risk of regression

The regression risk is semantic: an unsound alias proof can change overlapping copy behavior. This is higher risk than a missed optimization because the original sequence has precise load/store order and the bulk kinsn may not.

Tests that need attention:

- `test_different_base_regs_not_merged` should remain a negative for unknown-vs-unknown provenance.
- `test_non_stack_base_memcpy_skipped_by_alias_gate` should be split so unknown non-stack pairs still skip but provably disjoint pairs can apply.
- `test_same_base_chunked_overlap_skipped` should remain unchanged.
- `test_memcpy_pattern_8_pairs`, `test_memcpy_preserves_surrounding`, and branch-fixup tests should continue to pass for already-applied sites.
- Add positives for stack-vs-known-disjoint and stack-vs-stack non-overlapping intervals.

### D. `interior branch target`

#### 1. Current code path

This family appears in `cond_select` and `extract` in the latest result.

`cond_select`:

- Uses `BranchTargetAnalysis` from `cond_select.rs:88`.
- Checks every PC inside the matched site at `cond_select.rs:169`.
- It has a special exception for the conditional jump's own target in 3- and 4-instruction select patterns.
- Emits the exact skip at `cond_select.rs:183`: `interior branch target`.

`extract`:

- Requires `BranchTargetAnalysis` at `extract.rs:104`.
- Checks interior PCs at `extract.rs:134`.
- Emits the exact skip at `extract.rs:140`: `interior branch target`.

The shared analysis is `bpfopt/crates/bpfopt/src/analysis/branch_target.rs`. It records `is_target: Vec<bool>`, where each PC is either a branch/call target or not. It does not record source PCs, branch direction, whether the target is internal to the matched region, or reachability.

The exact assumption is: a multi-instruction replacement is unsafe if any interior instruction is the target of a branch, because the branch could land in the middle of code that will be deleted, moved, or semantically replaced by a sidecar/call sequence.

#### 2. Minimum required relaxation

The safe minimum is source-aware target classification:

```text
sources = BranchTargetSourcesAnalysis::sources_for(target_pc)
if all sources are inside the matched site and the target is one of the pattern's own control-flow labels:
    allow existing pattern-specific lowering
else:
    skip interior branch target
```

For `cond_select`, this generalizes the existing own-JCC-target exception without allowing external loop backedges into the replacement body.

For `extract`, suffix splitting is tempting but not generally correct. A typical extract site is `RSH; AND`. If an external branch targets the `AND`, the branch-entry semantics are "mask the already shifted value" only if the branch source guarantees the value is already shifted. The current `BranchTargetAnalysis` cannot prove that. Replacing only the suffix would need per-entry semantic proof, not just branch metadata.

A broader split rewrite would clone or preserve entry-specific original code and replace only the normal-entry path, but that is no longer a local kinsn replacement. It is higher risk and should not be the first relaxation.

#### 3. Correctness obligations

- Every predecessor of an interior target must land on code with the same semantics as before. This requires a new branch-target-source analysis.
- For multi-entry regions, equivalence must hold for every entry point, not only the normal fallthrough entry. Existing analyses do not prove this.
- Branch targets must not be remapped into the middle of a sidecar load or kinsn call pair. This is a hard verifier/code-generation wall.
- Replacement must stay within one subprogram and preserve metadata remapping. Existing shared utilities already handle this for normal single-entry sites.
- If family A tail-call relaxation is active too, the replacement must also preserve tail-call layout invariants.

#### 4. Implementation cost estimate

- Source-aware branch-target analysis: about 80-150 LOC in `analysis/branch_target.rs` or a new `branch_sources` module, plus tests.
- Conservative internal-only relaxation in passes: about 30-80 LOC per pass touched.
- General multi-entry splitting/cloning: about 250-500 LOC and high test burden; not recommended first.
- No daemon-side change required.
- No new kinsn registration required.

#### 5. Apply-count upside estimate

This family accounts for 133 skipped sites:

- `cond_select`: 123
- `extract`: 10

The exact unlock count is indeterminate because the artifacts do not record target PCs or branch source PCs. A conservative source-aware relaxation may unlock only a small subset, likely internal pattern labels currently missed by the hardcoded exception. The theoretical upper bound is 133, but most external backedges should remain skipped.

#### 6. Risk of regression

Existing applied sites should not regress if the analysis is additive and the old no-interior-target path remains unchanged. Newly applied sites are risky because the failure mode is semantic miscompile, not just ReJIT rejection.

Tests that need attention:

- `test_extract_pass_interior_branch_target` should remain a negative for external branch entries.
- `test_extract_pass_branch_fixup` should continue to prove normal branch remapping.
- Add branch-source-analysis tests for internal-only targets versus external backedges.
- `cond_select` needs a positive test for an internal pattern target if the generalization actually unlocks one, and a negative test for a loop backedge into the replacement body.

### E. `bpf_endian_load{16,32} kfunc not available`

#### 1. Current code path

The implementation file is `bpfopt/crates/bpfopt/src/passes/endian.rs`. The prompt's `endian_fusion.rs` path is stale; `passes/mod.rs` exports `EndianFusionPass` from `endian.rs`, and the pass name is still `endian_fusion`.

Relevant code:

- `btf_id_for_size` at `endian.rs:229` maps 16, 32, and 64-bit load sizes to registry entries.
- `target_name_for_size` at `endian.rs:239` maps those sizes to `bpf_endian_load16`, `bpf_endian_load32`, and `bpf_endian_load64`.
- The pass-level availability check is at `endian.rs:403`.
- The exact per-size skips are emitted at `endian.rs:410`: `bpf_endian_load{16,32,64} kfunc not available`.

In the input result, `endian_fusion` found 248 sites but applied only 2. It skipped 232 sites for missing load16 and 8 sites for missing load32, while load64 was available.

Current source status:

- `daemon/src/bpf.rs` now probes `bpf_endian_load16`, `bpf_endian_load32`, and `bpf_endian_load64`.
- `module/x86/bpf_endian.c` defines and registers all three endian load kinsns.
- `module/arm64/bpf_endian.c` also contains all three definitions by source inspection.
- Git history contains `a91d5753 Probe all endian load kinsns`, whose message says the modules already provided all three and the daemon probe list was the missing piece.

The input result predates that daemon probe fix, so this skip family is probably stale data.

#### 2. Minimum required relaxation

No bpfopt pass relaxation is required. The minimum behavior change is complete target discovery:

```text
daemon target probe includes:
    bpf_endian_load16
    bpf_endian_load32
    bpf_endian_load64
bpfopt target registry receives all three BTF ids.
```

That is already present in current `main`. The next action is to rerun the corpus after the in-flight fix lands cleanly, not to duplicate the work.

One possible remaining gap is test/reporting coverage around target JSON aliases: the main target JSON parsing test currently focuses on `bpf_endian_load64`. The registry setter does handle 16 and 32, so this is likely a test coverage gap rather than a functional blocker.

#### 3. Correctness obligations

- The daemon must probe all three public kinsn symbols and pass their BTF ids to bpfopt. Current source appears to satisfy this.
- bpfopt must map each name to the matching registry field. `set_kinsn_btf_id` handles `bpf_endian_load16`, `bpf_endian_load32`, and `bpf_endian_load64`.
- The x86 and arm64 kinsn modules must register and emit correct code for all three sizes. Source inspection confirms all three are present; runtime ReJIT validation still needs the rerun.
- Per-size call offsets must remain correct when multiple endian kinsns share a module. Existing endian tests cover per-size call offsets.

#### 4. Implementation cost estimate

- Functional fix: already landed in the in-flight daemon probe change.
- Additional test hardening, if desired by that task owner: less than 30 LOC.
- No bpfopt pass change required.
- No new kinsn module registration appears required.
- No daemon-side work beyond the existing probe-list update appears required.

#### 5. Apply-count upside estimate

This family accounts for 240 skipped `endian_fusion` sites:

- `bpf_endian_load16 kfunc not available`: 232
- `bpf_endian_load32 kfunc not available`: 8

Expected unlock is close to 240 minus sites that then hit a later guard such as tail-call or interior branch handling. Because the direct blocker was missing target discovery, this is the most deterministic upside in the current result, but it should be verified by a fresh corpus run rather than estimated further.

#### 6. Risk of regression

Risk is low for already-applied sites because load64 behavior is unchanged. The main risk is exposing latent module/JIT bugs in 16-bit or 32-bit emit paths that were previously unreachable due to missing discovery.

Tests to preserve or extend:

- `test_endian_fusion_pass_specific_size_unavailable` should remain as partial-target coverage.
- `test_endian_fusion_pass_all_three_sizes` should prove all sizes apply when all BTF ids exist.
- `test_endian_fusion_pass_uses_per_size_call_offsets` should keep covering offset selection.
- Any extra test work should stay with the in-flight endian task and should not be duplicated here.

## Cross-cutting findings

### Tail-call mechanism

`grep -RN "tail.call\|tail_call\|tail-call" bpfopt/` shows all kinsn tail-call rejection flows through `passes/utils.rs`, with additional tail-call-specific behavior in non-kinsn passes such as `const_prop` and `dce`.

For kinsn replacements, the mechanism is truly program-wide:

```text
for pc in 0..program.insns.len():
    if is_tail_call_insn(program.insns[pc]):
        return SkipReason("kinsn site in program with tail-call helper ...")
```

There is no CFG check, no relation check between tail-call PC and site PC, and no replacement-length check. This makes family A a high-ROI target.

From the input result, tail-call skips total 1,887. Parsing the embedded PCs in the skip strings gives:

- 1,512 sites after the first detected tail-call PC.
- 375 sites before the first detected tail-call PC.
- 0 sites at the same PC.

This supports a per-site/prefix investigation, but it does not prove the unlock count because the skip string records only the first tail-call PC and the artifacts do not record replacement length.

### Available analyses inventory

Current shared analyses in `bpfopt/crates/bpfopt/src/analysis/`:

- `BranchTargetAnalysis`: boolean `is_target` per PC. It answers "is this PC targeted?" but not "which instruction targets it?", branch direction, internal/external source, or reachability.
- `CFGAnalysis`: basic blocks, instruction-to-block mapping, predecessor/successor sets, and subprogram ranges. It can support local reachability work, but it does not model tail-call poke layout or provide dominators.
- `LivenessAnalysis`: register `live_out` sets per instruction. It does not expose stack-slot liveness and does not track pointer provenance.
- `MapInfoAnalysis`: map metadata support for map-inline style passes; not directly useful for the five skip families.

Pass-local logic that should not be mistaken for reusable analysis:

- `bulk_memory` has a local `RegValue` constant tracker and `is_likely_stack_ptr` lookback. These are not enough for sound different-base alias relaxation.
- `prefetch` has packet/map-value-oriented tracking for insertion decisions. It is useful as prior art but not a general alias analysis.
- `cond_select` already uses register liveness for scratch selection but has no spill-slot model.

New small analyses likely needed:

- `TailCallLayoutAnalysis`: tail-call PCs, last protected PC, and range-overlap checks.
- `BranchTargetSourcesAnalysis`: target PC to source PC list, with internal/external classification.
- `StackSlotSafetyAnalysis`: conservative available spill slots, ideally using verifier-state stack facts.
- `PointerProvenanceAnalysis`: restricted base provenance and exact offsets for stack and known disjoint objects.

### Per-app JSON schema

The app detail files under:

```text
corpus/results/x86_kvm_corpus_20260505_220116_564226/details/apps/*.json
```

contain the same aggregate structure as each app entry in `result.json`.

Top-level per-app keys:

```text
app
baseline
error
post_rejit
rejit_result
runner
selected_workload
status
```

`rejit_result.per_program[].passes[]` contains:

```text
pass
status
error
bpfopt_summary
```

`bpfopt_summary` contains:

```text
pass
insn_count_before
insn_count_after
insn_delta
sites_matched
sites_applied
sites_skipped
skip_reasons
diagnostics
```

The files do not record per-site PCs, before/after register state, verifier dataflow snapshots, matched instruction windows, replacement lengths, or branch target source PCs. The only per-site-ish data available for this study is encoded in some skip-reason strings, such as tail-call PC and site PC.

This means exact unlock counts for A, B, C, and D require either a local prototype or a temporary developer-only diagnostic run. The framework result payload should not grow informational-only fields just for rollups.

## Recommended priority order

1. E, endian load16/load32 target discovery. This is already fixed in current source and has a deterministic upside of up to 240 sites. The right next step is to verify with a fresh run after the in-flight task lands, not to write more pass logic.
2. A, tail-call layout relaxation. It has the largest upper bound at 1,887 sites. Implement the layout-safe subset first: fixed-length replacements after the tail-call-protected prefix, with current blanket behavior retained for size-changing earlier sites.
3. B, `cond_select` spill-backed immediate materialization. The upper bound is 320 sites, with plausible majority recovery if safe spill slots are available. Do it after A because it needs new stack-slot safety and increases program size.
4. C, `bulk_memory` different-base alias. The upper bound is 99 sites. It is worth doing only as a conservative pointer provenance analysis; a general alias system or new memmove kinsn is not justified by the current count.
5. D, interior branch target. The upper bound is 133 sites, but most safe relaxation requires source-aware or multi-entry semantic proof. Implement only internal-target classification unless a prototype shows a larger recoverable subset.

If asked to fix one this week, choose A after confirming E is present in the run environment. If asked to fix two, choose A and B.

## If we do nothing else, do X

Replace the shared program-wide tail-call kinsn skip with a tail-call-layout-aware guard that allows fixed-length replacements after the last tail-call instruction and preserves the current skip for every size-changing replacement before or across a tail-call site. That single shared change targets the largest blanket skip family, keeps the correctness invariant simple, and avoids touching daemon/kernel behavior.
