# BPF JIT Policy Framework v5 Design Review

Reviewer: Claude Sonnet 4.6
Date: 2026-03-09
Document under review: `docs/tmp/jit-pass-framework-v5-design.md`
Reference: `docs/kernel-jit-optimization-plan.md`, `docs/tmp/jit-pass-framework-v4-design.md`
Implementation: `vendor/linux/kernel/bpf/jit_directives.c`, `vendor/linux/arch/x86/net/bpf_jit_comp.c`

---

## Overall Score: 7.5 / 10

v5 addresses a genuine extensibility problem in v4 with a principled solution. The declarative pattern + canonical lowering split is correct, the safety model is sound for the common cases, and the core implementation (~340 LOC delta) is realistic. However, there are several correctness gaps in the pattern language, one significant security trust-boundary issue, and the 8-byte wide load limitation is an unresolved blocker for the paper's strongest claim.

---

## 1. Correctness: Can the Pattern Language Express the Required Patterns?

**Score: 6.5 / 10**

### 1.1 Patterns That Work Cleanly

| Pattern | Elements | Assessment |
|---------|----------|-----------|
| 4-insn rotate | 4 | Works. `opcode_mask+value` + `reg_bind` cross-references + `SUM_CONST` constraint cleanly express `mov tmp, src; lsh dst, N; rsh tmp, W-N; or dst, tmp`. |
| 6-insn masked rotate | 6 | Works. `AND` instruction with `imm_binding` for mask, then same structure. The v5 document correctly encodes this. |
| Low-first 2-byte wide_mem | 4 | Works. All four BPF opcodes are fixed (`BPF_LDX|BPF_MEM|BPF_B`, `BPF_ALU64|BPF_LSH|BPF_K`, etc.), `expected_imm` pins the shift amount, `off_binding` captures offsets. |
| ADDR_CALC (mov+shl+add) | 3 | Works. Standard 3-element pattern with `reg_bind` and `imm_bind` for scale. |

### 1.2 Critical Gap: Diamond COND_SELECT Cannot Be Expressed

The diamond cmov pattern in v4 is:
```
[0] jcc+2       (conditional jump forward 2 slots)
[1] mov dst, A  (fallthrough arm)
[2] ja+1        (unconditional jump forward 1)
[3] mov dst, B  (taken arm)
```

v4's validator checks (in `bpf_jit_cmov_select_match_diamond()`):
- `bpf_jmp_offset(jmp_insn) == 2` — the conditional jump MUST point exactly 2 slots ahead
- `ja_insn->off == 1` — the unconditional jump MUST point exactly 1 slot ahead
- `ja_insn->code == (BPF_JMP | BPF_JA)` — must be unconditional ja, NOT jcc

**The v5 pattern language has no way to express "this instruction's `off` field must equal a fixed constant that is NOT the same as the instruction's immediate."** The `off_binding` field binds `insn.off` to a variable, which can then be cross-referenced in constraints. The pattern CAN encode `off_bind=$X` and then add `IMM_RANGE($X, 2, 2)` to require `off==2`. However:

1. The `bpf_jmp_offset()` function in v4 does NOT simply read `insn.off`. It handles the `BPF_JMP32` vs `BPF_JMP` difference via `insn.imm` for some variants. The v5 pattern language treats `off_binding` as `insn.off` — this may not capture what v4's `bpf_jmp_offset()` computes.

2. For the compact form (`mov_default, jcc+1, mov_override`), the match function in v4 is called with `idx` pointing to the **jcc**, but the validator `bpf_jit_validate_cond_select_rule()` calls it with `idx+1` because `site_start` points to `mov_default`. The v5 element ordering must account for this — the design document correctly lists compact as `(mov, jcc+1, mov)`, but does not specify that the `off_bind` variable must be checked with `IMM_RANGE(1,1)`. The v5 example at §9.2 (`build_select_diamond_pattern()` and `build_select_compact_pattern()`) is referenced but NOT spelled out. This is a gap.

3. The v4 validator also checks `ja_insn->imm == 0 && ja_insn->dst_reg == 0 && ja_insn->src_reg == 0` — the `BPF_JA` instruction must have zero imm/dst/src. The v5 pattern language can encode `expected_imm` (flag bit 2 + `expected_imm=0`), but there is no `expected_dst` or `expected_src` field. A malicious userspace could submit a pattern matching a `ja` instruction that has nonzero `dst_reg` or `src_reg`, creating a situation where the pattern "matches" but the actual instruction is not a pure unconditional jump.

**Must-fix**: Add `expected_dst_reg` and `expected_src_reg` fields to `bpf_jit_pattern_elem`, or add a constraint type `REG_ZERO(var_id)`.

### 1.3 High-Byte-First Wide Mem: Missing DIFF_CONST Constraint

The `high-first-2B` pattern requires: `lo_load.off == hi_load.off - 1` (i.e., the low byte's offset is exactly one less than the high byte's offset).

v5's constraint language has `SUM_CONST(var_a, var_b, constant)`, meaning `var_a + var_b == constant`. To express `off_hi - off_lo == 1` as a sum constraint: `off_lo + 1 == off_hi` → `SUM_CONST(off_lo, 1, off_hi)` — but `var_b` must be a variable ID, not a constant. The correct constraint type would be `DIFF_CONST: var_a - var_b == constant`, which is NOT in the current constraint set.

The v5 document acknowledges this at §10.2:
> "Expressed as: var[3] - var[5] == 1 ... Alternative: we use a DIFF_CONST constraint type. For POC: embed the offset check in the pattern via relative offset binding"

This is left unresolved. The "relative offset binding" workaround is not explained and not implementable with the current `off_binding` system (which binds the raw `insn.off` value, a signed 16-bit integer). Without `DIFF_CONST`, the high-byte-first pattern **cannot be correctly expressed**, and the v5 document's claim that "v4 Round 2 changes become purely userspace changes" is false for this specific pattern.

**Must-fix**: Add `DIFF_CONST` constraint type: `var[var_a] - var[var_b] == constant`.

### 1.4 Low-First 4-Byte Wide Mem: 10 Elements, Within Limit

The v4 implementation validates `(site_len + 2) / 3` bytes. For 4 bytes: `site_len = 3*4-2 = 10`. This is within `BPF_JIT_MAX_PATTERN_LEN = 16`. A v5 pattern with 10 elements can express this. But the v4 pattern is non-trivial: for each subsequent byte group `i`, it checks `load_insn.off == base_off + i` and `shift_insn.imm == i*8`. These cross-instruction arithmetic relationships between `off_binding` values and the loop index `i` are not expressible with independent `IMM_RANGE` constraints.

Specifically: for the 4-byte pattern, the pattern needs:
- `off[0] + 1 == off[1]` (bytes 0 and 1 are adjacent)
- `off[0] + 2 == off[2]` (bytes 0 and 2)
- `shift[1].imm == 8`, `shift[2].imm == 16`, `shift[3].imm == 24`

The shift amounts are fixed constants and can be expressed with `expected_imm`. The offset adjacency requires `DIFF_CONST` (3 instances of it for 4 bytes). Without `DIFF_CONST`, the 4-byte pattern cannot verify that the loaded bytes are truly contiguous.

### 1.5 Low-First 8-Byte Wide Mem: Exceeds Pattern Length Limit

For 8 bytes: `site_len = 3*8-2 = 22`. This exceeds `BPF_JIT_MAX_PATTERN_LEN = 16`. The v5 document notes this "(22-elem, exceeds limit -- must chunk)" but does not explain the chunking mechanism. There is no current v5 mechanism for expressing patterns that span more than 16 BPF instructions. This means the most impactful optimization (8-byte wide load, the "50.7% surplus" case) **cannot be expressed as a single v5 pattern**.

The workaround of "chunking" would require either:
a) Raising `BPF_JIT_MAX_PATTERN_LEN` to 24, or
b) Expressing the 8-byte case as a different canonical form with different internal loop semantics

Neither is specified. This is a blocker for the paper's characterization of v5 as handling "all 4 existing v4 patterns."

**Must-fix**: Either raise `BPF_JIT_MAX_PATTERN_LEN` to at least 24, or add a REPEAT semantic to the pattern language, or declare 8-byte wide load is handled by a special-case kernel validator that remains in v4 format.

### 1.6 Summary of Pattern Expressibility

| Pattern | v5 Expressible? | Gap |
|---------|:--------------:|-----|
| 4-insn rotate | ✅ | None |
| 6-insn masked rotate | ✅ | None |
| ADDR_CALC (3-insn) | ✅ | None |
| Low-first 2-byte wide_mem | ⚠️ Partial | DIFF_CONST needed for offset contiguity proof |
| High-first 2-byte wide_mem | ❌ | DIFF_CONST missing |
| Low-first 4-byte wide_mem | ⚠️ Partial | DIFF_CONST needed × 3 |
| Low-first 8-byte wide_mem | ❌ | Exceeds 16-element limit |
| Diamond cmov SELECT | ⚠️ Partial | `expected_dst_reg=0`/`expected_src_reg=0` on `ja` not expressible |
| Compact cmov SELECT | ⚠️ Partial | Same `off` constraint expressible; `ja` zero-check not |

---

## 2. Security: Is Pattern Matching Truly Safe?

**Score: 7.5 / 10**

### 2.1 What Is Safe

- **Termination**: Proven. Pattern matching loops exactly `elem_count` times, bounded by `BPF_JIT_MAX_PATTERN_LEN = 16`. No recursion, no dynamic dispatch.
- **No OOB reads**: `site_start + site_len <= insn_cnt` is checked before the loop. Variable IDs are bounds-checked against `BPF_JIT_MAX_VARIABLES`.
- **No division by zero**: Constraint language has no division operation.
- **Canonical emitters are kernel code**: Userspace cannot inject native machine code — only parameter values (register numbers 0-10, immediates).
- **Fail-closed**: Unrecognized opcodes, unsatisfied constraints, and emitter errors all fall back to stock emission.

### 2.2 The Semantic Trust Gap (Residual Risk)

v5 explicitly acknowledges at §6.3: "v5 trusts the userspace-provided pattern-to-canonical mapping. If the pattern says 'this 4-insn sequence is a ROTATE' but it is actually a different computation, the emitter will produce wrong native code."

This is a real issue. v4's hardcoded validators are auditable C code in the kernel; a kernel developer can read `bpf_jit_validate_rotate_4insn()` and confirm it only matches sequences that implement bitwise rotation. In v5, the kernel reads a binary blob and trusts that the opcode values in `pattern_elem[].opcode_value` correctly identify instructions that compute rotation.

**Attack scenario** (requires `CAP_BPF`): An adversary constructs a pattern that describes a 4-instruction sequence computing `dst = src + imm * index` (e.g., a linear combination of registers), marks it as `CF_ROTATE`, and submits it. The kernel's generic matcher will accept the pattern if the opcodes match the declared pattern elements, then dispatch `emit_canonical_rotate_x86()` which emits `ror dst, imm`. The program now computes a rotation instead of the intended computation.

The mitigations listed (CAP_BPF privilege, functional testing before deployment, constraint narrowing) are valid but insufficient for high-assurance environments:
- CAP_BPF grants the user comprehensive BPF control already; this is a marginal increase in risk within that trust boundary.
- Functional testing is user responsibility, not kernel enforcement.
- Constraint narrowing helps but does not prove semantic equivalence.

**Assessment**: Acceptable for the paper's use case (trusted operators in Cilium/Katran). Not acceptable for multi-tenant or zero-trust environments. The design document should clearly state this limitation and its scope.

### 2.3 Variable Binding Confusion: Registers vs. Immediates

The `bpf_jit_var` structure tracks a `type` field (`BPF_JIT_VAR_REG` or `BPF_JIT_VAR_IMM`), but cross-reference checking in the generic matcher does NOT check that the type is consistent across binding sites. Specifically:

```c
/* Step 3: register binding - dst */
if (!vars[var_id].bound) {
    vars[var_id].value = insn->dst_reg;
    vars[var_id].type = BPF_JIT_VAR_REG;
    vars[var_id].bound = true;
} else {
    /* Cross-reference: must match previously bound value */
    if (vars[var_id].value != insn->dst_reg)
        return false;
}
```

If variable `$3` is first bound via `reg_bind_dst` (registers 0-10), and later the same variable `$3` appears in `imm_binding` for a different instruction, the matcher would check `insn.imm == var[3].value`. A register value of 5 would "cross-reference match" an immediate value of 5. This is a bug: the types should be checked for consistency.

**Must-fix**: Add type consistency check in cross-reference validation:
```c
if (vars[var_id].bound && vars[var_id].type != expected_type)
    return false;
```

### 2.4 Constraint Overflow: `val_a + val_b` for SUM_CONST

The `SUM_CONST` check does:
```c
if (val_a + val_b != (s64)c->constant)
    return false;
```

Both `val_a` and `val_b` are `s64`. For register values (0-10), no overflow. For immediates (up to `INT_MAX`), sum can overflow `s64` only if both are near `LLONG_MAX`, which BPF immediates cannot reach. This is safe as written.

### 2.5 Security Comparison vs. v4

| Property | v4 | v5 |
|----------|----|----|
| Semantic correctness proof | Kernel C code (auditable) | Trusts userspace pattern description |
| Attack surface for wrong native code | Requires kernel bug | Requires only malformed pattern (by CAP_BPF holder) |
| New pattern = new kernel review | Yes | No |
| Attack surface for kernel crash | Same as v4 | Same as v4 (bounded loops, no OOB) |

---

## 3. Feasibility: ~200 LOC Generic Matcher?

**Score: 8.5 / 10**

### 3.1 LOC Estimate Accuracy

The document claims "~200 LOC" for the generic pattern matcher. Looking at the provided implementation at §8.1:

- `bpf_jit_match_pattern()`: ~80 LOC as written (accurate)
- `bpf_jit_check_constraints()`: ~60 LOC (accurate)
- `bpf_jit_extract_bindings()` (binding extractor): ~30 LOC (not shown; plausible)
- `bpf_jit_parse_policy_v5()`: ~100 LOC (plausible, variable-length blob parsing is tricky)
- Canonical emitter registry: ~20 LOC (accurate)
- v4 emitter refactoring: ~50 LOC modification (plausible; emitters need to read `canonical_params` instead of re-parsing `insns`)

Total: ~340 LOC. The "~200 LOC generic matcher" statement is correct for the matcher alone; the full delta is ~340 LOC as stated in §8.5.

### 3.2 Performance Overhead vs. Hardcoded Validators

The generic matcher performs per-element: 1 opcode comparison + up to 4 array accesses + 4 conditional branches + 4 integer comparisons = ~13 operations per element.

v4's hardcoded validators perform equivalent work with direct struct field accesses, which compile to ~3-5 operations per instruction check. So v5 has roughly 2-3x overhead per instruction in the matching phase.

For a 4-element pattern, that's ~52 operations vs ~20 — a difference of ~32 additional operations. At modern CPU speeds, this is on the order of 10-20ns per rule. For 10-20 rules per JIT compilation that itself takes milliseconds, the overhead is utterly negligible. The document's performance assessment at §12.2 is correct.

### 3.3 The `bpf_jit_extract_bindings()` Function Is Missing

Section 8.3 calls `bpf_jit_extract_bindings()` but this function is not implemented in the document. The logic is: for each `bpf_jit_binding` entry, look up `vars[source_var].value` and store it into `rule->params.params[canonical_param]`. This is ~30 LOC, but its absence means the implementation plan at §14 is slightly incomplete for validation.

### 3.4 v4 Emitter Refactoring Complexity

The v4 emitters (`emit_bpf_cmov_select`, `emit_bpf_wide_load`, `emit_bpf_rotate`, `emit_bpf_lea`) currently take `(u8 **pprog, const struct bpf_insn *insns, const struct bpf_jit_rule *rule, ...)` and re-read BPF instructions to determine registers and immediates. Converting them to `(... const struct bpf_jit_canonical_params *params ...)` requires:

1. Replacing all `rule->site_start`, `insns[rule->site_start + N].dst_reg`, etc. with `params->params[P].value`
2. Handling the `native_choice` dispatch (currently via `rule->native_choice`) — unchanged
3. Testing that the refactored emitters produce bit-identical output

This is ~50 LOC modification but requires careful testing. The estimate is plausible.

---

## 4. Novelty: Is This Genuinely Novel vs. Existing Work?

**Score: 8 / 10**

### 4.1 What Is Novel

The combination of:
1. Declarative pattern matching (like LLVM TableGen) +
2. In-kernel execution with formal safety properties +
3. Runtime updatability without kernel changes +
4. User-controllable policy (not just compiler-internal)

...is indeed a new point in the design space. No existing system combines all four. The comparison table at §13.5 is accurate.

### 4.2 The LLVM TableGen Comparison Is Apt

The v5 design draws the right analogy to LLVM SelectionDAG patterns. The key differences (kernel safety, runtime loadability) are the actual contributions. The design document handles this comparison well.

### 4.3 One Underexplored Related Work: eBPF Verifier's Own Pattern Matching

The BPF verifier itself does pattern matching on BPF instructions (e.g., `optimize_bpf_loop()`, the 31 `bpf_patch_insn_data()` sites). v5 is explicitly doing something the verifier does NOT do (post-verifier JIT-level matching for native code selection), so the distinction is clear. However, the document does not discuss this internal comparison, which could be a question from reviewers.

### 4.4 The Paper Story Improvement

The document's §15.3 ("The analogy to eBPF itself becomes precise") is the strongest framing:

> "Just as eBPF separates program semantics (defined by userspace) from safe execution (guaranteed by the kernel verifier), v5 separates optimization decisions (defined by userspace patterns) from safe lowering (guaranteed by canonical form emitters)."

This is a genuinely elegant framing that strengthens the paper's core thesis. v5 is not just a technical improvement over v4; it makes the conceptual argument more precise and defensible.

---

## 5. Backward Compatibility: Can v4 Blobs Coexist with v5 Blobs?

**Score: 9 / 10**

The backward compatibility design at §7.4 is sound:
- `version = 1` → v4 parser (hardcoded validators)
- `version = 2` → v5 parser (generic matcher)
- Dispatch on `hdr->version` in `bpf_jit_parse_policy()`

The v4 emitters continue to work unchanged via the existing `switch(rule->rule_kind)` path. v5 rules use the canonical emitter registry `canonical_emitters[rule->canonical_form]`. Both paths can coexist in the same kernel build.

The auto-translation table at §7.5 is correct for the patterns that work. The blob size increase (5-12x per rule) is within the 64KB limit for realistic programs.

**Minor issue**: The v5 rule header `bpf_jit_rule_v2` renames `rule_kind` to `canonical_form`. The kernel's internal `struct bpf_jit_rule` (used for the ruleset after parsing) must accommodate both the v4 `rule_kind` and v5 `canonical_form`. The design document does not specify the internal rule struct for the post-parse ruleset — it uses `rule->canonical_form` in `do_jit()` dispatch but does not show how v4 rules (which have `rule_kind`) are stored. This needs to be addressed in implementation.

---

## 6. Gap Analysis: What Is Missing or Unrealistic?

### 6.1 Must-Fix Items (Blockers)

| # | Gap | Section | Impact |
|---|-----|---------|--------|
| G1 | **`DIFF_CONST` constraint missing** | §3.3, §10.2 | High-first 2B and contiguous offset checks for N-byte patterns cannot be expressed. The paper's claim that Round 2 changes are "purely userspace" is false without this. |
| G2 | **8-byte wide_mem exceeds 16-element limit** | §7.5 | The highest-impact optimization (50.7% surplus, 2.24x penalty) cannot be expressed as a single v5 pattern. Must either raise limit or document a chunking protocol. |
| G3 | **Variable type consistency not checked in cross-reference** | §8.1 | `reg_bind_dst` and `imm_binding` can share the same variable ID, allowing type confusion. Low-severity but incorrect. |
| G4 | **Diamond cmov: `ja` instruction cannot have zero dst/src checked** | §3.2, §6.3 | Cannot express `ja_insn->dst_reg == 0 && ja_insn->src_reg == 0` constraint. Pattern could match non-ja instructions. |
| G5 | **`bpf_jit_extract_bindings()` not specified** | §8.3 | Called but not implemented. The binding extraction is not straightforward (type checking, range validation of register numbers). |

### 6.2 Should-Fix Items (Significant Gaps)

| # | Gap | Section | Impact |
|---|-----|---------|--------|
| G6 | **No specification of internal `bpf_jit_rule` struct for v4/v5 coexistence** | §7.4 | Implementation requires a concrete answer. Either the internal struct has both `rule_kind` and `canonical_form` fields, or they are unified. |
| G7 | **`build_select_diamond_pattern()` and `build_select_compact_pattern()` not specified** | §9.2 | Critical patterns mentioned but not demonstrated. Readers cannot verify correctness of the cmov encoding. |
| G8 | **Jump offset constraint expressibility not analyzed** | §3.3 | The `off_binding` captures `insn.off`, but for BPF_JMP vs BPF_JMP32 the "jump distance" may differ from `insn.off` (via `bpf_jmp_offset()`). The document does not address this discrepancy. |
| G9 | **`FLAGS_EXACT_MATCH` (flag bit 1) is described but not implemented in matcher** | §3.1 | The flags field doc says "bit 1: if set, register binding requires exact match against a previously bound value (cross-reference)" — but the matcher code at §8.1 ALWAYS does cross-reference checking for already-bound variables, regardless of this flag. The flag is redundant as described, which is confusing. |
| G10 | **Canonical emitter contract: who validates register number ranges?** | §4.3 | The document says "If any parameter is out of range (e.g., register number > 10), the emitter returns an error." But userspace controls `source_var` bindings. A register number `>10` extracted via pattern matching from real BPF instructions is impossible (BPF register space is 0-10), but the emitter validation adds defense-in-depth. Should be in `bpf_jit_extract_bindings()`. |

### 6.3 Design Tension: v5's Core Claim vs. Semantic Safety

The paper argues that "canonical forms ARE the legality plane." But in v5, the legality of any given transformation depends on:
1. The pattern description (userspace-provided) correctly identifying the BPF instruction sequence's semantics, AND
2. The canonical form emitter correctly computing those semantics in native code

v4's legality plane was purely in (2): the kernel C validator proved (1). v5 moves (1) to userspace. This is a weakening of the legality guarantee. The paper must explicitly defend this trade-off: the legality plane is now "CAP_BPF holder can specify pattern semantics" rather than "kernel enforces semantic equivalence." The document's §6.3 and §15.1 partially address this but should be more explicit.

### 6.4 Pattern Library Bootstrap Problem

For v5 to be useful from day one, the pattern library must already contain descriptions for all common clang patterns. If the userspace tool ships with an empty library, users must write patterns themselves. The document describes the library but does not specify:
- Who maintains the canonical library?
- How are new patterns validated before being added to the library?
- Is there a reference test suite?

This is a deployment gap, not a design gap, but it affects the paper's "deployment operators can manage policy" story.

### 6.5 Minor Issues

- The `BPF_JIT_MAX_VARIABLES = 15` limit means only variable IDs 1-15. Variable `$0` is reserved as "unbound." This is fine but should be documented as a UAPI constant.
- The rule header `bpf_jit_rule_v2` drops the `payload_off` and `payload_len` fields from v4's `bpf_jit_rewrite_rule`. This is intentional (patterns replace payloads) but should be stated explicitly.
- `BPF_JIT_MAX_BINDINGS = 8` — `CF_SELECT` has 9 parameters (DST_REG, COND_OP, COND_SRC, COND_A_REG, COND_B_REG, COND_B_IMM, TRUE_VAL, FALSE_VAL, TRUE_SRC_KIND, FALSE_SRC_KIND = 10). This exceeds the limit of 8. Must either increase `BPF_JIT_MAX_BINDINGS` or reduce the CF_SELECT parameter set.

---

## 7. Relationship to `docs/kernel-jit-optimization-plan.md`

### 7.1 Alignment

v5 is fully consistent with the hub document's position (§1.7, §1.9) that v5 is "声明式 Pattern + Canonical Lowering (pattern 描述在 userspace blob，kernel 通用 matcher + 固定 canonical lowering)." The design implements exactly what the plan describes.

The hub document's "正确 directive 的判断标准" (can userspace do it without kernel JIT involvement?) is fully satisfied: pattern recognition moves to userspace, but canonical lowering (native instruction emission) remains in the kernel. This is the correct layering.

### 7.2 Remaining Gaps Relative to Plan

The plan's P0.5 TODO (§9, item 42-r: "v5 设计 review") is what this document addresses. The plan's assessment that "v4 POC 必须先做到有真实性能优化证据，v5 是设计层面的升级" is accurate — v5 does not change the evaluation story, only the extensibility architecture.

### 7.3 OSDI Readiness Impact

v5 strengthens the paper's OSDI story from the hub document (§9, OSDI readiness currently 4/10). The declarative pattern language:
- Directly addresses "原型实现多个 directive，展示框架的泛化能力" — v5 makes generalization the central contribution rather than just a side effect
- Does NOT address "评估包含真实多函数程序" or "Fixed kernel baseline" — these remain blockers

---

## 8. Summary Scorecard

| Criterion | Score | Key Finding |
|-----------|:-----:|-------------|
| Correctness (pattern expressibility) | 6.5 | 4 patterns work; 5 have gaps (DIFF_CONST missing, 8-byte limit, ja checks) |
| Security (safety properties) | 7.5 | Matcher is provably safe; trust boundary slightly wider than v4 |
| Feasibility (implementation size) | 8.5 | ~340 LOC estimate realistic; emitter refactor needs care |
| Novelty vs. existing work | 8.0 | Clean analogy to LLVM TableGen with correct differentiation |
| Backward compatibility | 9.0 | Version dispatch design is sound; internal struct unification needs spec |
| Gap analysis completeness | 6.5 | Document acknowledges gaps but leaves 5 unresolved |
| **Overall** | **7.5** | Strong architectural direction; must fix DIFF_CONST + 8-byte limit + binding count before implementation |

---

## 9. Must-Fix Before Implementation

1. **Add `DIFF_CONST` constraint type** (`var[a] - var[b] == constant`). This is required for all multi-byte wide_mem patterns and any pattern where two offset variables must differ by a known constant. Without this, the high-first 2B and low-first 4B/8B patterns cannot be correctly expressed.

2. **Resolve the 8-byte wide_mem limit**. Either raise `BPF_JIT_MAX_PATTERN_LEN` to 24, add a REPEAT primitive (`repeat_from: X, repeat_count: N`), or explicitly declare 8-byte wide_mem remains a v4 hardcoded validator and document that v5 patterns only handle 2B and 4B cases.

3. **Fix variable type consistency in cross-reference matching**. A variable bound as REG must always be used as REG; a variable bound as IMM must always be used as IMM. Add the type check to the cross-reference path.

4. **Add way to constrain `expected_dst_reg=0`/`expected_src_reg=0`**. For the diamond cmov, the `ja` instruction must have zero `dst_reg` and `src_reg`. Either add `expected_dst_reg`/`expected_src_reg` fields to `bpf_jit_pattern_elem`, or add a `REG_CONST(var_id, expected_value)` constraint type.

5. **Implement and document `bpf_jit_extract_bindings()`**. Include bounds checking on extracted register numbers (0-10). Without this, the pipeline described at §8.3 is incomplete.

6. **Increase `BPF_JIT_MAX_BINDINGS` to at least 10** to accommodate `CF_SELECT`'s full parameter set. Or reduce `CF_SELECT` parameters by folding TRUE_SRC_KIND/FALSE_SRC_KIND into the value encoding.

7. **Spell out `build_select_diamond_pattern()` and `build_select_compact_pattern()`** in the document. These are the highest-value patterns and their correctness cannot be assumed.
