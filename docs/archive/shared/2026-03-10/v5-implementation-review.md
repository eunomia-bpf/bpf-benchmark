# v5 Declarative Pattern JIT Implementation Review

Date: 2026-03-10

Scope reviewed:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/jit-pass-framework-v5-design.md`
- `docs/tmp/jit-pass-framework-v5-review.md`
- `docs/tmp/v5-minimal-poc-results.md`
- `docs/tmp/framework-architecture-review.md`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `micro/runner/src/kernel_runner.cpp`
- `micro/runner/include/micro_exec.hpp`
- `micro/runner/src/common.cpp`
- `scanner/src/scanner.cpp`
- `scanner/include/bpf_jit_scanner/types.h`
- `scanner/include/bpf_jit_scanner/policy.h`

## Scores

| Area | Score | Assessment |
|------|:-----:|------------|
| Design conformance | 5.0/10 | The code implements a bounded v2 variable-length matcher, but not the full v5 architecture described in the design doc. |
| Security & correctness | 4.0/10 | The matcher is bounded, but unchecked index arithmetic and CPU-feature trust in userspace are still serious problems. |
| Extensibility | 4.0/10 | Some rotate/wide/lea variants moved to userspace, but the canonical-lowering contract is not actually decoupled from pattern shape. |
| Code quality & integration | 5.0/10 | Kernel v1/v2 coexistence is reasonable; userspace integration is fragmented and still runner-local. |
| **Overall** | **4.5/10** | Credible as a narrow v5 POC; not yet credible as the general extensible framework claimed in the docs. |

## Executive Summary

This implementation does make real progress beyond v4:

- it adds a versioned v2 blob parser and bounded generic matcher in the kernel (`vendor/linux-framework/kernel/bpf/jit_directives.c:1428-1889`);
- it addresses 4 of the 5 must-fix items from the previous v5 design review:
  - `DIFF_CONST` exists (`vendor/linux-framework/include/uapi/linux/bpf.h:1555-1563`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1542-1549`);
  - the pattern length limit is now 24 (`vendor/linux-framework/include/uapi/linux/bpf.h:1545-1547`);
  - type-consistent variable binding is implemented (`vendor/linux-framework/kernel/bpf/jit_directives.c:1428-1447`);
  - exact dst/src/off checks exist (`vendor/linux-framework/include/uapi/linux/bpf.h:1549-1575`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1467-1477`).

The main problem is that the implementation stops halfway through the v5 design. The design doc’s core split is:

1. userspace owns pattern recognition;
2. kernel owns canonical semantic forms plus parametric lowering.

The code only implements (1) partially. It does **not** implement the binding-table / canonical-parameter half of the design (`docs/tmp/jit-pass-framework-v5-design.md:589-702`, `docs/tmp/jit-pass-framework-v5-design.md:806-839`). Instead, the x86 emitters still re-parse raw BPF instructions using old fixed-shape assumptions (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2110-2174`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2199-2339`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2343-2419`). That means the current code is not yet a true “new patterns require only userspace changes” substrate.

To be fair, it does match the narrower POC scope documented in `docs/tmp/v5-minimal-poc-results.md:7-18`: a minimal exact-opcode matcher, existing x86 emitters reused unchanged, and v5 living only in `micro/runner`.

## Design Conformance

### What matches the v5 design

| Design item | Status | Evidence |
|------------|--------|----------|
| Versioned v2 variable-length policy blob | Implemented | `vendor/linux-framework/kernel/bpf/jit_directives.c:1787-1889` |
| Bounded generic matcher | Implemented | `vendor/linux-framework/kernel/bpf/jit_directives.c:1449-1491` |
| Bounded constraint interpreter | Implemented | `vendor/linux-framework/kernel/bpf/jit_directives.c:1493-1566` |
| 24-element pattern limit for 8-byte wide load | Implemented | `vendor/linux-framework/include/uapi/linux/bpf.h:1545-1547` |
| `DIFF_CONST` support | Implemented | `vendor/linux-framework/include/uapi/linux/bpf.h:1555-1563`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1542-1549` |
| Expected dst/src/off checks | Implemented | `vendor/linux-framework/include/uapi/linux/bpf.h:1549-1575`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1467-1477` |
| v4/v5 coexistence by blob version | Implemented | `vendor/linux-framework/kernel/bpf/jit_directives.c:1993-2001` |

### What does not match the v5 design

| Design item | Design doc | Current implementation | Impact |
|------------|------------|------------------------|--------|
| Pattern opcode matching | `opcode_mask` + `opcode_value` (`docs/tmp/jit-pass-framework-v5-design.md:166-178`) | Exact `opcode` only (`vendor/linux-framework/include/uapi/linux/bpf.h:1565-1575`) | Much weaker DSL; no compact encoding of “any conditional jump” or class/op families. |
| Canonical bindings in blob | Required (`docs/tmp/jit-pass-framework-v5-design.md:593-655`, `docs/tmp/jit-pass-framework-v5-design.md:825-839`) | Missing entirely; v2 rule carries only pattern + constraints (`vendor/linux-framework/include/uapi/linux/bpf.h:1588-1600`) | Canonical lowering is not parameterized; emitters remain tied to pattern shape. |
| Canonical emitter interface | Binding-array based (`docs/tmp/jit-pass-framework-v5-design.md:547-585`) | Old emitters still read raw BPF insns (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2110-2174`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2199-2339`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2343-2419`) | New variants are only userspace-only if they accidentally fit existing emitter assumptions. |
| Canonical form vocabulary | Semantic forms (`SELECT`, `WIDE_LOAD`, `ROTATE`, `FUSED_ADDR`, future forms) (`docs/tmp/jit-pass-framework-v5-design.md:393-523`) | Thin relabeling of current v4 families (`vendor/linux-framework/include/uapi/linux/bpf.h:1500-1505`) | The “canonical form” layer is still mostly a family alias, not a semantic contract. |
| v5 userspace support for all four v4 families | Includes `CF_SELECT` (`docs/tmp/jit-pass-framework-v5-design.md:882-885`, `docs/tmp/jit-pass-framework-v5-design.md:1280-1282`) | `--recompile-v5` only supports wide/rotate/lea (`micro/runner/src/common.cpp:265-271`, `micro/runner/src/kernel_runner.cpp:1475-1490`) | One of the headline motivating optimizations remains outside the v5 path. |

### Must-fix Status From `jit-pass-framework-v5-review.md`

| Previous must-fix | Status | Notes |
|-------------------|--------|-------|
| Add `DIFF_CONST` | Fixed | Implemented in UAPI and kernel matcher. |
| Raise pattern length to support 8-byte wide load | Fixed | Limit is now 24. |
| Enforce variable type consistency | Fixed | `bpf_jit_bind_pattern_var()` checks both type and value. |
| Add expected dst/src checking for `ja` / exact register constraints | Fixed | Expected dst/src/off fields exist and are enforced. |
| Implement documented binding extraction / canonical param layer | **Not fixed** | The implementation removed bindings from the blob instead of implementing them. This is the largest remaining design gap. |

## Top Issues Ranked By Severity

### 1. Critical: unchecked `site_start + site_len` arithmetic can bypass bounds checks and drive OOB instruction access

Representative locations:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:574`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:1393`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:1458-1463`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:1597-1600`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:1773-1774`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:1871-1872`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2052`

Why this matters:

- v5 rules are userspace-provided.
- the parser stores `site_start` directly from the blob (`vendor/linux-framework/kernel/bpf/jit_directives.c:1866-1869`);
- multiple validation paths then do unchecked `site_start + site_len` arithmetic on `u32`.

A malicious `site_start` near `U32_MAX` can wrap:

- `bpf_jit_validate_rule()` may accept it (`vendor/linux-framework/kernel/bpf/jit_directives.c:1597-1600`);
- `bpf_jit_match_pattern()` may then read `insns[rule->site_start + i]` out of bounds (`vendor/linux-framework/kernel/bpf/jit_directives.c:1458-1463`);
- `bpf_jit_site_has_side_effects()` and `bpf_jit_has_interior_edge()` can also miscompute empty or wrapped ranges (`vendor/linux-framework/kernel/bpf/jit_directives.c:574`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1393`).

This is the clearest kernel-side correctness/security bug still present.

### 2. Critical: the canonical-binding half of v5 is missing, so emitters still depend on old fixed instruction layouts

Design reference:

- `docs/tmp/jit-pass-framework-v5-design.md:589-702`
- `docs/tmp/jit-pass-framework-v5-design.md:806-839`

Current code:

- v2 rule ABI has no `binding_count` or binding table (`vendor/linux-framework/include/uapi/linux/bpf.h:1588-1600`);
- v5 validation only does generic match + constraints (`vendor/linux-framework/kernel/bpf/jit_directives.c:1568-1588`);
- x86 dispatch then routes directly into old emitters by canonical form (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2456-2525`).

The emitters still recover operands from raw instruction positions:

- wide load: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2110-2174`
- rotate: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2199-2339`
- lea: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2343-2419`
- cond-select: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1352-1455`

Effect:

- a new pattern variant is only safe if it happens to match the emitter’s existing positional assumptions;
- new site lengths or alternate operand layouts still need kernel changes;
- the central v5 claim, “new patterns need only userspace changes,” is not generally true in the current artifact.

### 3. High: the implemented pattern language is materially weaker than the v5 design spec

Design:

- masked/value opcode matching (`docs/tmp/jit-pass-framework-v5-design.md:166-178`)
- binding tables (`docs/tmp/jit-pass-framework-v5-design.md:593-655`)

Implementation:

- exact opcode only (`vendor/linux-framework/include/uapi/linux/bpf.h:1565-1575`)
- exact opcode matching in kernel (`vendor/linux-framework/kernel/bpf/jit_directives.c:1465`)
- exact opcode matching in userspace (`micro/runner/src/kernel_runner.cpp:707`)

This matters because the current DSL cannot compactly express:

- “any conditional jump” style matches from the design;
- compact families that vary only in condition opcode or source mode;
- canonical mappings that need operand roles separated from instruction position.

This is not just a nice-to-have discrepancy. It is one of the reasons `COND_SELECT` is still not on the v5 userspace path.

### 4. High: CPU legality is still partly delegated to userspace; `RORX` can be emitted without BMI2

Relevant code:

- native-choice validity only checks enum membership: `vendor/linux-framework/kernel/bpf/jit_directives.c:517-535`
- CPU features are checked only if userspace sets `cpu_features_required`: `vendor/linux-framework/kernel/bpf/jit_directives.c:1603-1607`
- BMI2 feature bits exist but are advisory: `vendor/linux-framework/include/uapi/linux/bpf.h:1532-1534`
- x86 emits `rorx` unconditionally once `native_choice == BPF_JIT_ROT_RORX`: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2280-2303`

So a blob can request `BPF_JIT_ROT_RORX` with `cpu_features_required = 0`. The rule remains active, and the JIT emits an illegal instruction on a non-BMI2 CPU. That breaks the design’s “kernel legality plane” story.

### 5. High: `COND_SELECT`/CMOV is still outside the v5 path

Relevant code:

- CLI rejects `--recompile-v5` with `--recompile-cmov` / `--recompile-all`: `micro/runner/src/common.cpp:265-271`
- v5 descriptor builders exist only for wide/rotate/lea: `micro/runner/src/kernel_runner.cpp:841-878`, `micro/runner/src/kernel_runner.cpp:880-1008`, `micro/runner/src/kernel_runner.cpp:1010-1035`
- v5 application path only appends those three families: `micro/runner/src/kernel_runner.cpp:1475-1490`

Design reference:

- `docs/tmp/jit-pass-framework-v5-design.md:882-885`
- `docs/tmp/jit-pass-framework-v5-design.md:1280-1282`

This is a paper-level gap, not a small feature omission. `COND_SELECT` was one of the most visible motivating examples in the plan and the v4 story. If the strongest “branch vs cmov” example still needs the old path, reviewers will challenge the generality claim immediately.

### 6. High: the shared scanner library is still v4-only; v5 lives in `micro/runner`

Evidence:

- `scanner/src/scanner.cpp:5-7` says scanner is the authoritative userspace matcher;
- `scanner/include/bpf_jit_scanner/types.h:45-46` still defines policy version 1 only;
- `scanner/include/bpf_jit_scanner/policy.h:3-6` explicitly describes a v4 blob builder;
- `micro/runner/src/kernel_runner.cpp:118-179` and `micro/runner/src/kernel_runner.cpp:528-1105` contain a private v5 ABI, matcher, descriptor library, and blob builder.

This is the opposite of the design intent. Today, “add a new v5 pattern” means editing benchmark-runner code, not the authoritative userspace library.

### 7. Medium-High: overlap and priority semantics are still not correctly implemented

Relevant code:

- `priority` is exposed in the v1/v2 ABIs: `vendor/linux-framework/include/uapi/linux/bpf.h:1541`, `vendor/linux-framework/include/uapi/linux/bpf.h:1595`
- kernel sorts by `(site_start, -priority)`: `vendor/linux-framework/kernel/bpf/jit_directives.c:481-495`
- lookup returns only the one binary-search hit, and only if `insn_idx == site_start`: `vendor/linux-framework/kernel/bpf/jit_directives.c:2037-2069`
- v5 userspace builder assigns `priority = 0` to everything: `micro/runner/src/kernel_runner.cpp:748`
- v5 userspace scanning is greedy first-match and skips ahead: `micro/runner/src/kernel_runner.cpp:777-791`

Net effect:

- later-start overlapping rules are not arbitrated correctly;
- same-start alternatives are not a real policy mechanism in userspace;
- the actual behavior is descriptor-order driven, not priority driven.

### 8. Medium: userspace says it scans full translated programs, but the kernel still silently restricts active rules to the main subprogram

Kernel:

- main-subprog cutoff: `vendor/linux-framework/kernel/bpf/jit_directives.c:1633-1640`
- active rule gating in both parsers: `vendor/linux-framework/kernel/bpf/jit_directives.c:1773-1774`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1871-1872`

Userspace:

- comment claims full-program scan is okay because kernel only rejects cross-subprog sites: `micro/runner/src/kernel_runner.cpp:1447-1452`

The current kernel does not merely reject cross-subprog patterns. It deactivates any rule whose end is beyond `main_subprog_end`. That weakens the “real multi-function program” story and makes the userspace comment misleading.

### 9. Medium: `bpf_jit_pattern_rule_shape_valid()` hardcodes per-form site lengths, so some “new patterns” still require kernel edits before matching even starts

Relevant code:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:538-553`

Current allowed lengths:

- rotate: 4, 5, 6
- wide_mem: 4, 10, 22
- addr_calc: 3
- cond_select: 3, 4

This means a new pattern for an existing canonical form is only userspace-only if it uses an already-whitelisted length and an emitter-understood layout. A new valid 7-insn rotate-like lowering, or a new wide form with a different canonical span, still requires kernel modification.

## Security & Correctness Assessment

### What is good

- The kernel matcher and constraint interpreter are bounded by explicit constants (`vendor/linux-framework/include/uapi/linux/bpf.h:1545-1547`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1449-1566`).
- Variable ID bounds and constraint-type validation are fail-closed (`vendor/linux-framework/kernel/bpf/jit_directives.c:1657-1727`).
- v2 rule parsing does real length arithmetic with `check_mul_overflow()` / `check_add_overflow()` for inline payload sizes (`vendor/linux-framework/kernel/bpf/jit_directives.c:1831-1845`).
- Pattern/constraint pointers are kept backed by the retained policy blob (`vendor/linux-framework/kernel/bpf/jit_directives.c:1888-1889`), which avoids per-rule allocation lifetime bugs.

### What is still wrong

- The unchecked range arithmetic above is still a serious kernel bug.
- CPU legality is still not fully kernel-owned.
- The semantic trust gap remains: the kernel validates that a pattern matches a blob-defined shape, not that the blob-defined shape is semantically the claimed canonical form (`vendor/linux-framework/kernel/bpf/jit_directives.c:1568-1588`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2456-2525`). This is an accepted design tradeoff, but it is still a reviewer-visible limitation.

## Extensibility Assessment

### Adding a new canonical form

Current reality: **not cheap**.

Minimum files to touch:

1. `vendor/linux-framework/include/uapi/linux/bpf.h`
2. `vendor/linux-framework/kernel/bpf/jit_directives.c`
3. `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
4. `micro/runner/src/kernel_runner.cpp`

Likely work:

- add canonical-form enum + native-choice constants;
- extend `bpf_jit_rule_form()`, `bpf_jit_native_choice_valid()`, and probably `bpf_jit_pattern_rule_shape_valid()` in the kernel;
- add x86 emitter logic and `bpf_jit_try_emit_rule()` dispatch;
- add userspace descriptor definitions and scanning glue.

Estimated cost: roughly **140-300 LOC across 4 files**, before tests.

This is acceptable for a new canonical form. That part of the story is plausible.

### Adding a new pattern for an existing canonical form

Current reality: **only sometimes userspace-only**.

Best case:

- 1 userspace file: `micro/runner/src/kernel_runner.cpp`
- about **10-30 LOC** for another descriptor entry

This is true for variants that:

- use an already-accepted site length (`vendor/linux-framework/kernel/bpf/jit_directives.c:538-553`);
- fit the existing emitter’s operand extraction logic.

Realistic case:

- also touch `vendor/linux-framework/kernel/bpf/jit_directives.c` for shape admission;
- also touch `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` because the emitter still parses raw insn positions.

Estimated cost then becomes **50-150 additional kernel LOC**. That directly contradicts the paper claim.

### Pattern language expressiveness

What it can express today:

- fixed exact-opcode rotate idioms
- fixed exact-opcode wide-load ladders
- fixed exact-opcode `mov + shl + add` LEA fusion
- exact-offset / exact-register structural checks

What it cannot express cleanly today:

- opcode-mask classes like “any conditional jump” from the design
- alternation or wildcarded opcode families without enumerating every exact opcode
- patterns whose semantic operand mapping is not recoverable from fixed insn positions
- future variants whose canonical span length is not already hardcoded in `bpf_jit_pattern_rule_shape_valid()`

For the specific examples in the design:

- complex rotate variants: partially expressible if they fit current exact-opcode descriptor style and current x86 emitter assumptions;
- CMOV diamond/compact family: not integrated, and much less elegant than the design because lack of opcode masks forces descriptor explosion.

## Code Quality & Integration

### Kernel/userspace coexistence

Kernel coexistence is fairly clean:

- v1 and v2 blobs share the same outer parser (`vendor/linux-framework/kernel/bpf/jit_directives.c:1993-2001`);
- x86 routing uses a common canonical-form switch (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2456-2525`).

Userspace coexistence is not clean:

- v4 goes through `scanner/`;
- v5 lives only in `micro/runner`.

That means there is no single authoritative policy plane implementation.

### Code duplication

There is duplicated pattern logic in two places:

- shared v4 scanner library: `scanner/src/scanner.cpp`
- private v5 matcher/blob builder: `micro/runner/src/kernel_runner.cpp:528-1105`

There is also duplicated ABI knowledge:

- scanner v4 constants: `scanner/include/bpf_jit_scanner/types.h:44-125`
- runner-local v5 constants and structs: `micro/runner/src/kernel_runner.cpp:70-155`

This duplication is already causing conceptual drift. The scanner says it is authoritative while the runner carries the only v5 implementation.

## Gap To Paper-Ready

### What is still missing for the paper story

1. **Actual canonical bindings and emitter refactor**
   - Without binding tables and parameterized emitters, the core extensibility claim is not true.

2. **A shared authoritative v5 userspace library**
   - Move v5 descriptors, matcher, and blob building into `scanner/`.

3. **`COND_SELECT` on the v5 path**
   - This is too central to leave on the legacy path.

4. **Overflow-safe site range validation everywhere**
   - This is a hard blocker for a credible kernel mechanism claim.

5. **Kernel-owned CPU legality**
   - Derive required feature bits from `canonical_form + native_choice`, do not trust blob-supplied `cpu_features_required`.

6. **Real overlap/arbitration semantics**
   - Either reject overlaps outright or implement correct priority handling.

7. **Subprogram story consistency**
   - Either support subprogs end-to-end or scope the design down honestly.

### What a reviewer will challenge

- “You say new patterns are userspace-only, but where are the canonical bindings?”
- “Why is the strongest `cmov` example still on the old path?”
- “Why does the authoritative scanner library not know about v5?”
- “Why are canonical forms still basically aliases for current v4 families?”
- “Can privileged userspace ask for `rorx` on a non-BMI2 CPU?”
- “What prevents `site_start + site_len` wraparound from skipping validation?”

## Overall Assessment Of The “Extensible Framework” Claim

**Not yet credible in the strong form claimed by the docs.**

The current code is credible as:

- a bounded variable-length pattern-matching POC in the kernel;
- a proof that some pattern diversity can move to userspace for rotate/wide/lea;
- a useful bridge from v4 to a fuller v5 design.

It is **not** yet credible as:

- a general “new patterns need only userspace changes” framework;
- a clean separation of pattern recognition from canonical lowering;
- a submission-ready implementation of the design doc’s v5 architecture.

The decisive missing piece is the canonical binding / parameterized emitter layer. Until that exists, the framework still depends on hidden kernel knowledge of pattern layout, and the extensibility claim remains only partially true.

## Recommended Next Steps

1. Fix all unchecked `site_start + site_len` arithmetic with overflow-safe helpers before any more feature work.
2. Derive CPU legality in-kernel from `(canonical_form, native_choice)` and reject inconsistent `cpu_features_required`.
3. Add binding tables to the v2 blob ABI and refactor x86 emitters to consume canonical parameters instead of raw BPF instruction positions.
4. Move v5 descriptor definitions, scanning, and blob serialization into `scanner/`; delete or wrap the runner-local copies.
5. Implement `COND_SELECT` on the v5 path and make `--recompile-v5 --recompile-all` viable.
6. Either reject overlapping rules explicitly or implement correct priority-aware arbitration.
7. Decide whether subprogram support is in-scope; then make code, comments, and paper text agree.
