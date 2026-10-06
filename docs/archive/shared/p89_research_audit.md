# P89 Research Audit

Scope: audit the six `📝 待做（待调研）` entries in `docs/kernel-jit-optimization-plan.md` §3.1 and check whether prior research or pass implementation already exists.

Current repo note: this audit was run on the current workspace HEAD `9b9bd28e`; the task context mentioned `f9429b0c`, but the local branch had advanced before this edit.

## Search Summary

Broad searches covered `docs/tmp/`, `docs/kernel-jit-optimization-plan*.md`, and `bpfopt/crates/bpfopt/src/passes/` with the requested keyword families:

- `setcc`, `cset`, `boolean[-_]set`, `cmp.*set`, `cond.*store`
- `andn\b`, `BMI1`, `mask[-_]clear`, `a & ~b`
- `blsi`, `blsr`, `blsmsk`, `lowest[-_]set[-_]bit`, `bitmap.*census`
- `division[-_]reduction`, `const.*div`, `mulhi`, `shift[-_]multiply`, `magic[-_]number`, `granlund`, `divisor`
- `register[-_](alloc|reall|map)`, `liveness`, `callee[-_]saved`, `R6.*spill`
- `region[-_]kinsn`, `region.*proof`, `region.*ABI`, `extended[-_]register`
- top-level docs: `bit_ops_kinsn_research`, `arm64_kinsn_research`, `x86_kinsn_research`, `kinsn_audit`, `kinsn_census`

Implementation sweep:

```bash
rg -n -i "(setcc|cset|andn|blsi|blsr|division|register_realloc|region_kinsn|spill_to_reg)" bpfopt/crates/bpfopt/src/passes
```

Result: no dedicated pass implementation for these six items. A broader `div|mod|BPF_DIV|BPF_MOD` sweep only found `const_prop.rs` constant evaluation and divide-by-zero handling, not division strength reduction.

Existing passes under `bpfopt/crates/bpfopt/src/passes/` are `wide_mem`, `rotate`, `cond_select`, `extract`, `endian`, `branch_flip`, `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `bulk_memory`, `prefetch`, `skb_load_bytes`, and `ccmp`; none are SETcc/ANDN/BLS*/division-reduction/register-realloc/region-kinsn passes.

## SETcc/CSET

Current status: `📝 待做（待调研）` is accurate.

Found research/docs:

- `docs/tmp/20260319/arm64_emitter_design_20260319.md:50` and `:773-797` cover ARM64 `cset/csetm` as `COND_SELECT` lowering details.
- `docs/tmp/pass-coverage-analysis-20260428.md:409` lists `SETcc`/`CSET` boolean materialization as a new opportunity; `:490` ranks immediate-operand `cond_select` / boolean `SETcc` as P1.
- `docs/tmp/p89_plan_status_review.md:38` already concluded there was no dedicated research document.

Conclusion: related docs cover existing `COND_SELECT`/ARM64 CSET lowering and identify SETcc as a possible P1 opportunity, but no standalone boolean-set corpus census or implementation plan exists.

Existing code: no `setcc`/`cset` pass in `bpfopt/crates/bpfopt/src/passes/`. `cond_select.rs` exists, but it is not a standalone boolean-materialization pass.

Recommended next step:

```bash
find corpus/build -name '*.bpf.o' -print0 |
  xargs -0 llvm-objdump -d |
  rg -n "if r[0-9]+ .* goto|r[0-9]+ = 0|r[0-9]+ = 1"
```

Follow with a parser that groups compare/branch plus `0/1` materialization and subtracts sites already matched by `cond_select`.

## ANDN

Current status: `📝 待做（待调研）` is accurate.

Found research/docs:

- `docs/tmp/20260320/x86_new_optimization_opportunities_20260320.md:146` observes `sete/setne + andn` in a Tracee LLVM-vs-stock native gap.
- `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:5` scopes bit-op research to `POPCNT/CLZ/CTZ + PDEP/PEXT + SHRX/SHLX`; it does not cover `ANDN`.
- `docs/tmp/p89_plan_status_review.md:39` already concluded no dedicated ANDN research was found.

Conclusion: no corpus-wide `a & ~b` / mask-clear census exists. The Tracee observation is useful seed evidence, not a completed ANDN study.

Existing code: no `andn` pass or implementation in `bpfopt/crates/bpfopt/src/passes/`.

Recommended next step:

```bash
find corpus/build -name '*.bpf.o' -print0 |
  xargs -0 llvm-objdump -d |
  rg -n "(\^= -1|= -1|&= r[0-9]+|&= 0x|~)"
```

Follow with a BPF-instruction parser for canonical `not tmp; and dst,tmp`, `xor -1; and`, and mask-clear idioms, then split x86-only BMI1 wins from ARM64 fallback cost.

## BLSI/BLSR/BLSMSK

Current status: `📝 待做（待调研）` is accurate.

Found research/docs:

- `docs/tmp/2026-03-07/additional_jit_optimizations.md:332-340` discusses only the microbenchmark pattern `x &= x - 1 -> blsr`, with likely benefit limited to `bitcount`.
- `docs/tmp/2026-03-08/directive-discovery-analysis.md:241` says the narrow `blsr`-style idiom is too small to drive the roadmap.
- `docs/tmp/2026-03-13/ablation-byte-recompose-callee-bmi.md:30` reports near-zero BMI-only delta in a proxy estimate and includes `blsr` in that proxy family.
- `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md` does not include BLSI/BLSR/BLSMSK in its scope.
- `docs/tmp/p89_plan_status_review.md:40` already concluded no dedicated BLS* research was found.

Conclusion: there is partial historical coverage for `BLSR` in one microbenchmark, but no current corpus bitmap / lowest-set-bit census covering BLSI, BLSR, and BLSMSK.

Existing code: no `blsi`, `blsr`, or `blsmsk` pass in `bpfopt/crates/bpfopt/src/passes/`.

Recommended next step:

```bash
find corpus/build -name '*.bpf.o' -print0 |
  xargs -0 llvm-objdump -d |
  rg -n "(\\-= 1|\\+= -1|&= r[0-9]+|\\^= r[0-9]+|neg)"
```

Follow with exact idiom matching for `x & -x` (BLSI), `x & (x - 1)` (BLSR), and `x ^ (x - 1)` / `(x & -x) - 1` (BLSMSK).

## Division Strength Reduction

Current status: `📝 待做（待调研）` is accurate.

Found research/docs:

- `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md:13` says verifier-assisted const propagation can feed downstream `strength reduction`.
- `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md:318` describes generic strength-reduction potential from const-prop consumers.
- `docs/tmp/2026-03-11/v6-interface-design.md:592-650` covers `DIV_LIVENESS`, which is a liveness-sensitive native DIV save/restore choice, not constant-divisor strength reduction.
- `docs/tmp/p89_plan_status_review.md:41` already concluded there was no division-specific corpus census.

Conclusion: existing research only supports the generic premise that const-prop can open strength-reduction opportunities. It does not quantify constant-divisor division/modulo sites or recommend an implementation policy.

Existing code: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:516-552` evaluates constant `BPF_DIV`/`BPF_MOD` and rejects zero divisors, but there is no shift/multiply or magic-number division-reduction pass.

Recommended next step:

```bash
find corpus/build -name '*.bpf.o' -print0 |
  xargs -0 llvm-objdump -d |
  rg -n "(r[0-9]+ /=[[:space:]]*-?[0-9]+|r[0-9]+ %= [[:space:]]*-?[0-9]+)"
```

Then rerun against verifier-const-prop output to count only sites where the divisor is provably constant and non-zero.

## Register Reallocation

Current status: `📝 待做（待调研）` is accurate.

Found research/docs:

- `docs/tmp/20260329/rejit_register_mapping_research_20260329.md:10-20` and `:790` study REJIT-level native `reg_map` / spill-to-register. That is the adjacent row in the plan, not pure BPF bytecode register reallocation.
- `docs/tmp/2026-03-13/ablation-byte-recompose-callee-bmi.md:8-14` says current stock callee-saved contribution is near zero, but that is about native prologue/epilogue trimming, not BPF R6-R9 reallocation.
- `docs/tmp/p89_plan_status_review.md:43` already warns not to mix this item with `REJIT spill-to-register`.

Conclusion: no dedicated research exists for a pure bytecode pass that remaps BPF register usage via liveness to reduce spill/fill. Existing liveness analyses are infrastructure, not this optimization.

Existing code: many passes use `LivenessAnalysis`, but there is no `register_realloc`, `register_reall`, `spill_to_reg`, or equivalent pass in `bpfopt/crates/bpfopt/src/passes/`.

Recommended next step:

```bash
find corpus/build -name '*.bpf.o' -print0 |
  xargs -0 llvm-objdump -d |
  rg -n "(\\*\\(u64 \\*\\)\\(r10 -[0-9]+\\) = r[6-9]|r[6-9] = \\*\\(u64 \\*\\)\\(r10 -[0-9]+\\))"
```

Follow with a liveness-aware script that counts R6-R9 live ranges, spill/fill pairs, and conflicts with helper-call ABI boundaries.

## Region kinsn

Current status: `📝 待做（待调研）` is accurate.

Found research/docs:

- `docs/tmp/20260325/kinsn_kfunc_unification_codex_research_20260325.md:10` and `:31` document the current `struct bpf_kinsn` plus `lower_kinsn_proof_regions()` model.
- `docs/tmp/20260326/kinsn_formal_semantics_review_20260326.md:24-35` reviews current proof-lowering semantics.
- `docs/tmp/p89_plan_status_review.md:45` already concluded no dedicated extended-register region-kinsn research was found.

Conclusion: current kinsn proof-region docs explain how existing sidecar+kfunc kinsn calls are lowered for verifier proof. They do not define a region ABI, proof model, or native emit callback model for wrapping high-register-pressure code and using extra native registers.

Existing code: `bpfopt/crates/bpfopt/src/passes/utils.rs` contains proof-region utilities for existing kinsn calls, but there is no `region_kinsn` pass or extended-register region ABI implementation.

Recommended next step:

```bash
find corpus/build -name '*.bpf.o' -print0 |
  xargs -0 llvm-objdump -d |
  rg -n "(\\*\\(u64 \\*\\)\\(r10 -[0-9]+\\)|r[0-9]+ = \\*\\(u64 \\*\\)\\(r10 -[0-9]+\\))"
```

Use that only as a pressure seed. The real next artifact should be a design doc for region ABI, verifier proof-lowering boundaries, allowed live-in/live-out registers, and how this relates to existing kinsn v2 proof regions.

## Final Classification

| Item | Classification | Plan action |
| --- | --- | --- |
| SETcc/CSET | Related docs only; no dedicated research, no implementation | Keep `📝 待做（待调研）`; link this audit |
| ANDN | Related Tracee observation only; no dedicated research, no implementation | Keep `📝 待做（待调研）`; link this audit |
| BLSI/BLSR/BLSMSK | Partial historical BLSR/micro evidence only; no current corpus census, no implementation | Keep `📝 待做（待调研）`; link this audit |
| Division strength reduction | Generic const-prop research only; no division-specific census, no implementation | Keep `📝 待做（待调研）`; link this audit |
| Register reallocation | Adjacent REJIT spill-to-register research exists, but not this bytecode pass; no implementation | Keep `📝 待做（待调研）`; link this audit |
| Region kinsn | Current proof-lowering docs exist, but not extended-register region ABI/proof research; no implementation | Keep `📝 待做（待调研）`; link this audit |
