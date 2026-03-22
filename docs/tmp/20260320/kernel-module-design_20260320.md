# BpfReJIT Kernel Module Design

## Scope

This document describes the `BPF_PROG_JIT_RECOMPILE` path implemented in the current tree under `vendor/linux-framework`. It is based on direct code tracing through the shared parser, validator, orchestration, x86 and arm64 JIT backends, trampoline regeneration, the UAPI definitions, the design notes in `docs/kernel-jit-optimization-plan.md`, and the selftests in `tests/kernel/test_recompile.c`.

## 1. System overview

BpfReJIT is a controlled re-JIT path for already verified BPF programs. Userspace supplies a sealed memfd containing a policy blob that names canonical BPF instruction sites and requests one of a small set of backend-specific lowerings for each site. The kernel does not execute user code or user-provided machine code. Instead, it validates that each requested rewrite matches a recognized BPF pattern, checks that the target architecture supports the requested native lowering, and then re-runs the normal BPF JIT with selective alternate emission at those sites.

Relative to the existing BPF subsystem, BpfReJIT sits after verification and inside the normal JIT lifecycle. The verifier still owns safety of the original BPF program. `bpf_prog` ownership, `bpf_prog_aux`, subprogram arrays, JIT staging, exception tables, kallsyms, and trampoline retargeting all remain standard kernel mechanisms. BpfReJIT adds a second, narrower validation domain for "which already-verified BPF site may be lowered in which alternative native way", but it does not replace the verifier, add a second execution engine, or create a separate machine-code patching subsystem.

## 2. Three-layer safety model

The implementation follows a deliberately stratified model that mirrors the existing verifier/JIT split.

### Layer 0: interface and policy parsing

`kernel/bpf/jit_policy.c` handles untrusted userspace input. Its job is format safety, not semantic safety.

It enforces:

1. The policy comes from a sealed memfd.
2. Blob size is sane and the header is fully present.
3. Magic, version, header length, total length, rule count, and flags are valid.
4. The policy matches the live program by instruction count, tag, and architecture id.
5. Each rule has a syntactically valid canonical-form/native-choice/`site_start`/`site_len` shape.
6. Each rule stays within a single subprogram.
7. The final active rule set is sorted and non-overlapping.

The important design choice is that parsing does not stop at wire-format validation. It immediately calls `bpf_jit_validate_rule()` against the program's live `insnsi` array and only marks rules active if the validator accepts them. That makes "policy parse" the point where untrusted input is converted into trusted canonical parameters.

### Layer 0.5: architecture capability gate

`bpf_jit_arch_form_supported()` is the narrow capability bridge between the shared validator and each architecture backend.

The shared validator calls it before accepting a rule. The default weak definition returns false, so a new architecture gets no support unless it opts in explicitly. In this tree:

- x86-64 supports all eight forms, but some choices are CPU-feature gated:
  - `COND_SELECT` requires `CMOV`
  - `ROTATE` with `RORX` requires `BMI2`
  - `BITFIELD_EXTRACT` requires `BMI1`
  - `ENDIAN_FUSION` requires `MOVBE`
- arm64 supports only four forms:
  - `COND_SELECT`
  - `WIDE_MEM`
  - `ROTATE`
  - `BITFIELD_EXTRACT`

This is not the main safety gate, but it prevents the validator from accepting a rule whose emitter does not exist on the current backend.

### Layer 1: validation

`kernel/bpf/jit_validators.c` is the sole semantic safety gate. This matches design constraint 11 in `docs/kernel-jit-optimization-plan.md`: the emitter trusts validator-filled parameters.

For every rule, the validator:

1. Clears any previous parameter state.
2. Verifies header-level shape.
3. Verifies the site range is in bounds.
4. Verifies the requested native choice is legal for the canonical form.
5. Verifies the architecture advertises support for that form and choice.
6. Rejects side effects unless the form explicitly allows them.
7. Recognizes one exact canonical BPF pattern and normalizes it into `struct bpf_jit_canonical_params`.
8. Rejects interior control-flow edges into the middle of the site.

The validator is intentionally stronger than a pattern matcher. It also enforces control-flow locality, width agreement, operand shape, and side-effect restrictions. For `BRANCH_FLIP` it deep-copies both branch bodies into canonical parameters; for `ENDIAN_FUSION` it is the one place that explicitly allows a store.

### Layer 2: emission

The arch emitters in `arch/x86/net/bpf_jit_comp.c` and `arch/arm64/net/bpf_jit_comp.c` are mechanical encoders. They do not re-parse raw BPF bytecode. They read validator-produced canonical parameters and emit native instructions accordingly.

Examples:

- x86 `emit_canonical_select()` assumes the validator already proved a legal select idiom and emits compare plus `cmovcc`.
- x86 `emit_canonical_bitfield_extract()` assumes a normalized low-mask extract and emits `BEXTR`.
- arm64 `emit_canonical_select_arm64()` assumes the same canonical contract and emits `CSEL`, `CSET`, or `CSETM`.
- arm64 `emit_canonical_rotate_arm64()` assumes a valid rotate amount and emits a `ROR` immediate form.

If an emitter still returns an error, both backends treat it as a fallback to stock JIT at that site and log it on the final image pass. Safety still comes from the validator; liveness degrades to "rewrite not applied".

### Orchestration

`kernel/bpf/jit_directives.c` owns the lifecycle around the validator and emitters:

- syscall entry
- policy installation
- rollback snapshot
- staged recompilation of all program images
- commit or abort
- trampoline regeneration
- RCU synchronization
- kallsyms handoff and old-image retirement

### Why this mirrors the verifier/JIT model

The existing kernel BPF stack already separates "prove the BPF program is safe" from "lower the proven program into native code." BpfReJIT repeats the same pattern at a smaller scope:

- Layer 0 parses untrusted control data.
- Layer 1 proves a site matches one safe canonical contract.
- Layer 2 lowers that canonical contract into machine code.

That division is the main reason the feature is defensible in kernel terms. The emitter is not asked to make safety decisions from raw user input.

## 3. Recompile lifecycle

The actual control flow is centered on `bpf_prog_jit_recompile()` in `kernel/bpf/jit_directives.c`.

### 3.1 Syscall entry and front-end checks

1. Userspace calls `bpf(BPF_PROG_JIT_RECOMPILE, ...)`.
2. The syscall rejects nonzero flags.
3. It requires `bpf_jit_supports_recompile()`.
4. It requires `CAP_BPF` or `CAP_SYS_ADMIN`.
5. It resolves `prog_fd` to a live `bpf_prog`.
6. It takes `main_aux->jit_recompile_mutex` with `mutex_trylock()`, returning `-EBUSY` on contention.
7. It optionally installs a verifier-style log buffer.
8. It requires the target program to already be JITed.
9. It rejects two known unsupported situations:
   - blinded programs (`prog->blinded`)
   - live `struct_ops` programs with trampoline dependencies

`policy_fd == 0` is a special case: it means "stock re-JIT", not "policy with zero rules".

### 3.2 Policy parse and activation

If `policy_fd != 0`, `bpf_jit_parse_policy()` reads the sealed blob, validates the header, allocates `struct bpf_jit_policy`, copies each user rule into an internal `struct bpf_jit_rule`, and immediately validates every rule against the current program.

Rules that validate are marked `BPF_JIT_REWRITE_F_ACTIVE`, then sorted by `site_start`, then checked for overlap. A parsed policy with zero active rules is rejected. This means the live JIT never sees raw user rule records; it only sees trusted, normalized internal rules.

### 3.3 Snapshot and rollback state

Before replacing anything, `bpf_jit_recompile_snapshot()` saves enough state to restore the original live image:

- current `bpf_func`
- current private stack pointer
- current exception table
- current `jit_data`
- a full copy of each program image's `insnsi`
- jited length and extable count
- frame-pointer symbol range
- JITed flag and exception boundary
- the main program's exception callback

Snapshotting `insnsi` matters because the multi-function recompile path temporarily mutates pseudo-call and subprogram call immediates in place while wiring staged addresses together.

### 3.4 Policy install and stage setup

The syscall swaps the new policy into `main_aux->jit_policy` or clears the policy for a stock re-JIT, then zeroes `jit_recompile_num_applied`.

`bpf_jit_recompile_prog_images()` then drives the actual recompilation of the main image and every subprogram image.

### 3.5 First-stage compile

For every program image in the `bpf_prog` family:

1. Mark `aux->jit_recompile_active = true`.
2. Call `bpf_int_jit_compile()`.
3. The backend emits into staged storage under `aux->jit_recompile_*` instead of replacing the live image.

At this point the two backends differ in compilation model:

- x86 reuses its normal shrink-to-fit convergence loop in `do_jit()`. It repeatedly emits the whole program until `proglen` stops changing, then emits the final image.
- arm64 reuses its normal three-pass pipeline:
  - size estimation
  - layout/offset determination
  - final write with resolved jumps

In both backends the rewrite logic is not a separate optimization pass. It is a conditional branch inside the normal per-instruction body emitter:

- x86: `do_jit()` calls `bpf_jit_apply_prog_rule()` before stock emission.
- arm64: `build_body()` calls `bpf_jit_apply_prog_rule()` before `build_insn()`.

If a rule applies, the emitter consumes `site_len` BPF instructions at once and updates the backend's address map (`addrs[]` on x86, `offset[]` on arm64) so the rest of the JIT still sees consistent control-flow layout.

### 3.6 Multi-function restitching

For programs with subprograms, the first staged compile does not yet know all final subprogram entry addresses. `bpf_jit_recompile_prog_images()` therefore patches the in-memory `insnsi` arrays:

- `BPF_PSEUDO_FUNC` loads are rebound to staged function addresses.
- `BPF_PSEUDO_CALL` immediates are recomputed against staged subprogram targets.

Then it runs `bpf_int_jit_compile()` again for each image.

This second compile is what turns the staged main image into a self-consistent family of direct calls against the new staged subprogram addresses.

### 3.7 Rule application and convergence

The validator ran earlier at parse time. During JIT, the backend only performs rule lookup and emission:

1. Convert the backend-local instruction index into a policy-global site index when needed.
2. Look up a rule by exact `site_start`.
3. Attempt to emit the requested canonical lowering.
4. If emission succeeds, mark the region as consumed and continue from the next BPF instruction after the site.
5. If emission fails, reset local state for that site, log `emitter fallback`, and use the stock lowering instead.

`jit_recompile_num_applied` increments only on the final image-writing pass. Estimation passes do not count as application.

On x86 the rewrite participates in the existing whole-image convergence loop. There is no additional rule-specific fixed-point test. The only explicit convergence condition is still `proglen == oldproglen`.

On arm64 there is no x86-style shrink loop. The rewrite participates in the normal pass structure and in the extra pass used when staged offsets already exist.

### 3.8 Commit, no-op abort, or full rollback

After all images are successfully staged:

- If a policy exists but `jit_recompile_num_applied == 0`, the function aborts the staged images, restores the original live image, and returns success with a log message that no rules applied. This avoids replacing the live image with bytewise-different but semantically identical stock JIT output.
- Otherwise it computes the staged exception callback target if needed, adds shadow kallsyms entries for the staged images, and calls `bpf_jit_recompile_commit()` for each image.

`bpf_jit_recompile_commit()` is arch-specific. It installs the staged machine code, exception table, private stack pointer, instruction pointers, frame-pointer ranges, and other JIT metadata into the live `bpf_prog`.

If any earlier step fails, `bpf_jit_recompile_restore()` reinstalls the saved `bpf_func`, extable, `jit_data`, private stack, `insnsi`, symbol range, exception boundary, and policy pointer from the snapshot.

### 3.9 Trampoline regeneration, RCU, and kallsyms handoff

The actual post-commit order in the code is:

1. Commit staged images.
2. Regenerate trampolines with `bpf_prog_regenerate_trampolines(prog, old_prog_func)`.
3. Call `synchronize_rcu()`.
4. Replace kallsyms with `bpf_prog_kallsyms_replace()`.
5. Free old JIT images and old private stacks unless the trampoline path requested `keep_old_images`.

This is important because the question is easy to invert conceptually. The code does not wait for the grace period before attempting trampoline retargeting. It commits first, regenerates trampolines next, then waits for readers, then finalizes symbol ownership and frees old images.

Trampoline regeneration is intentionally warning-only. If it fails, the new image remains committed and the code keeps the old image memory alive rather than rolling back the recompile.

### 3.10 Snapshot/rollback summary

The rollback model is conservative:

- compile into staged state
- never overwrite live text during staging
- keep a complete snapshot of the old live state
- commit only after all staged images are ready
- preserve old text until after trampoline work and an RCU grace period

That is the core lifecycle invariant of the feature.

## 4. Per-form analysis

The fresh corpus counts below come from a local run of `corpus/directive_census.py` in this workspace. They are raw scanner-backed candidate counts over corpus ELF program sections, not live xlated acceptance counts. They are still useful for relative prevalence.

| Form | Corpus sites / objects | x86-64 support | arm64 support |
| --- | ---: | --- | --- |
| `COND_SELECT` | 7689 / 129 | Yes | Yes |
| `WIDE_MEM` | 2832 / 32 | Yes | Yes |
| `ROTATE` | 0 / 0 | Yes | Yes |
| `ADDR_CALC` | 14 / 7 | Yes | No |
| `BITFIELD_EXTRACT` | 542 / 40 | Yes | Yes |
| `ZERO_EXT_ELIDE` | 0 / 0 | Yes | No |
| `ENDIAN_FUSION` | 1386 / 50 | Yes | No |
| `BRANCH_FLIP` | 2264 / 24 | Yes | No |

### 4.1 `COND_SELECT`

Pattern recognized:

- A 2-insn guarded update: `jcc +1; mov`
- A 3-insn compact select: `mov default; jcc +1; mov override`
- A 4-insn diamond: `jcc +2; mov false; ja +1; mov true`

The validator insists on simple moves, a common destination register, consistent width, and a legal conditional jump opcode. It fills:

- `DST_REG`
- `COND_OP`
- `COND_A`
- `COND_B`
- `TRUE_VAL`
- `FALSE_VAL`
- `WIDTH`

Emitter behavior:

- x86 emits compare plus `cmovcc`. If an immediate must feed `cmovcc`, it first materializes that value in `AUX_REG`. If the true branch is a no-op, it may invert the condition and seed the destination with the false value first.
- arm64 emits compare plus `CSEL`, with boolean special cases lowered to `CSET` or `CSETM`.

Site count in corpus:

- 7689 raw candidate sites across 129 corpus objects

### 4.2 `WIDE_MEM`

Pattern recognized:

- A byte-load reconstruction sequence beginning with `ldxb`
- Optional shifts on each contributing byte
- Chained ORs that assemble a 2- to 8-byte value
- Contiguous offsets, unique offsets, and either little-endian or big-endian shift layout

The validator requires `site_len == 3 * width - 2` and fills:

- `DST_REG`
- `BASE_REG`
- `BASE_OFF`
- `WIDTH`, with a bit encoding big-endian layout

Emitter behavior:

- x86 emits a direct 2-, 4-, or 8-byte load when possible, followed by byte swap if required. Odd widths are rebuilt from 4/2/1-byte chunks with shifts and ORs.
- arm64 does the same structurally: direct load for natural widths, optional byte reversal, or chunked loads plus `LSL` and `ORR` for odd widths.

Site count in corpus:

- 2832 raw candidate sites across 32 corpus objects

### 4.3 `ROTATE`

Pattern recognized:

- Synthetic rotate-right or rotate-left expressed as copies, shifts, and ORs
- The validator accepts the supported 32-bit and 64-bit in-place and two-copy shapes, including masked 32-bit high-mask variants
- It rejects the low-mask 32-bit form

The validator fills:

- `DST_REG`
- `SRC_REG`
- `AMOUNT`
- `WIDTH`

Emitter behavior:

- x86 emits either `ROR` or BMI2 `RORX` according to `native_choice`, copying the source first when the destination differs.
- arm64 accepts both rotate choices at the shared API level but lowers both to the same immediate `ROR` encoding (`EXTR` alias).

Site count in corpus:

- 0 raw candidate sites across 0 corpus objects

Note:

- The same local census found rotate sites only in the microbench side of the corpus, not in the main corpus object set. The implementation and selftests are therefore ahead of observed corpus demand.

### 4.4 `ADDR_CALC`

Pattern recognized:

- Exact 3-insn address calculation:
  - `mov64 dst, idx`
  - `lsh64 dst, scale`
  - `add64 dst, base`

The validator requires scale in `{1, 2, 3}` and fills:

- `DST_REG`
- `BASE_REG`
- `INDEX_REG`
- `SCALE`

Emitter behavior:

- x86 emits one `LEA dst, [base + index * scale]`.
- arm64 does not implement this form. The shared validator rejects it up front through `bpf_jit_arch_form_supported()`.

Site count in corpus:

- 14 raw candidate sites across 7 corpus objects

### 4.5 `BITFIELD_EXTRACT`

Pattern recognized:

- `rsh; and` or `and; rsh`, optionally preceded by a copy
- Site length 2 or 3
- Width derived from ALU versus ALU64 class

The validator normalizes all accepted forms into a low-mask-after-shift contract and fills:

- `DST_REG`
- `SRC_REG`
- `SHIFT`
- `MASK`
- `WIDTH`
- `ORDER`, always `SHIFT_MASK`

Emitter behavior:

- x86 emits `BEXTR`, loading the control word into `AUX_REG`. If the extract is semantically trivial, it may collapse to a move.
- arm64 emits `UBFX`.

Site count in corpus:

- 542 raw candidate sites across 40 corpus objects

### 4.6 `ZERO_EXT_ELIDE`

Pattern recognized:

- A linearizable ALU32 instruction followed by a redundant zero-extension tail
- The tail may be the canonical zext pseudo-insn, `mov64 dst, dst`, or `and64 dst, -1`

The validator fills:

- `DST_REG`
- `CODE`
- `SRC_REG`
- `OFF`
- `IMM`

Emitter behavior:

- x86 reconstructs the original ALU32 instruction from the stored fields, reuses the ordinary ALU32 emitter, and drops the explicit zext tail.
- arm64 does not support this form in the current tree.

Site count in corpus:

- 0 raw candidate sites across 0 corpus objects

### 4.7 `ENDIAN_FUSION`

Pattern recognized:

- Load-plus-swap:
  - `ldx mem {h,w,dw}` then endian swap
- Swap-plus-store:
  - endian swap then `stx mem {h,w,dw}`

This is the only canonical form whose metadata explicitly allows side effects, because the swap-store variant includes a store. The validator fills:

- `DATA_REG`
- `BASE_REG`
- `OFFSET`
- `WIDTH` in bits
- `DIRECTION`

Emitter behavior:

- x86 emits `MOVBE` load or store sequences.
- arm64 does not support the form in the current tree, even though the ISA has byte-reversal instructions.

Site count in corpus:

- 1386 raw candidate sites across 50 corpus objects

### 4.8 `BRANCH_FLIP`

Pattern recognized:

- A local if/else diamond
- The entry instruction is a conditional jump, including `JSET`
- Body A and body B are both short, linear regions
- The diamond rejoins exactly at `site_start + site_len`

The validator requires body lengths in `[1, 16]`, rejects non-linear bodies, and heap-copies both bodies into canonical parameters. It fills:

- `COND_CODE`
- `COND_DST_REG`
- `COND_SRC`
- `BODY_A_LEN`
- `BODY_A_PTR`
- `BODY_B_LEN`
- `BODY_B_PTR`

`bpf_jit_rule_release()` later frees those copied instruction arrays.

Emitter behavior:

- x86 emits compare, inverts the branch, lays out the opposite body first, emits a local jump over the second body, then emits the original first body. This is a control-flow relayout, not a peephole instruction substitution.
- arm64 does not support the form in the current tree.

Site count in corpus:

- 2264 raw candidate sites across 24 corpus objects

## 5. File layout and responsibilities

### 5.1 Per-file responsibilities

| File | Lines | Role | Key functions or symbols |
| --- | ---: | --- | --- |
| `vendor/linux-framework/include/uapi/linux/bpf.h` | 7797 | UAPI surface for the syscall and policy blob format | `BPF_PROG_JIT_RECOMPILE`, `BPF_JIT_POLICY_MAGIC`, `struct bpf_jit_policy_hdr`, `struct bpf_jit_rewrite_rule_v2` |
| `vendor/linux-framework/include/linux/bpf_jit_directives.h` | 272 | Shared internal enums, policy/rule structs, canonical params, staging helpers | `struct bpf_jit_rule`, `struct bpf_jit_policy`, `bpf_jit_validate_rule()`, `bpf_jit_arch_form_supported()` |
| `vendor/linux-framework/kernel/bpf/jit_policy.c` | 441 | Parse sealed memfd policy blobs and activate validated rules | `bpf_jit_parse_policy()`, `bpf_jit_parse_policy_format_v2()`, `bpf_jit_policy_validate_disjoint()`, `bpf_jit_rule_lookup()` |
| `vendor/linux-framework/kernel/bpf/jit_validators.c` | 1732 | Canonical recognizers and sole safety gate | `bpf_jit_validate_rule()`, `bpf_jit_validate_canonical_site()`, per-form parsers such as `bpf_jit_parse_wide_mem_shape()` and `bpf_jit_parse_branch_flip_shape()` |
| `vendor/linux-framework/kernel/bpf/jit_directives.c` | 741 | Syscall, logging, snapshot, staged-image orchestration, commit/abort lifecycle | `bpf_prog_jit_recompile()`, `bpf_jit_recompile_snapshot()`, `bpf_jit_recompile_prog_images()`, `bpf_jit_rule_release()` |
| `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` | 5860 | x86 rule emitters, rule lookup integration, convergence loop, staged commit/abort | `emit_canonical_*()`, `bpf_jit_apply_prog_rule()`, `do_jit()`, `bpf_jit_recompile_commit()`, `bpf_jit_arch_form_supported()` |
| `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c` | 3992 | arm64 rule emitters, rule lookup integration, staged compile, staged commit/abort | `emit_canonical_*_arm64()`, `build_body()`, `build_insn()`, `bpf_jit_recompile_commit()`, `bpf_jit_arch_form_supported()` |
| `vendor/linux-framework/arch/arm64/net/bpf_jit.h` | 342 | arm64 helper macros used by new emitters | `A64_ROR_I`, `A64_UBFX`, related instruction encoders |
| `vendor/linux-framework/include/linux/bpf.h` | 4072 | Shared core state in `bpf_prog_aux` and prototypes for recompile/trampoline helpers | `jit_recompile_*` aux fields, `bpf_jit_recompile_clear_stage()`, `bpf_prog_regenerate_trampolines()` |
| `vendor/linux-framework/kernel/bpf/trampoline.c` | 1627 | Retarget attached trampolines after a successful recompile | `bpf_prog_regenerate_trampolines()` |
| `docs/kernel-jit-optimization-plan.md` | 899 | Existing architecture notes and design constraints used by this implementation | section 1.4 constraints, section 4 architecture notes |
| `tests/kernel/test_recompile.c` | 3164 | Selftest harness for UAPI, parser rejection, semantic preservation, and lifecycle behavior | `sys_prog_jit_recompile()`, 27 `test_*` cases |

### 5.2 Dependency graph

```text
userspace
  -> include/uapi/linux/bpf.h
      -> kernel/bpf/jit_policy.c
          -> kernel/bpf/jit_validators.c
              -> arch/*/net/bpf_jit_comp.c:bpf_jit_arch_form_supported()

kernel/bpf/jit_directives.c
  -> kernel/bpf/jit_policy.c
  -> include/linux/bpf_jit_directives.h
  -> include/linux/bpf.h
  -> arch/*/net/bpf_jit_comp.c:bpf_int_jit_compile()
  -> arch/*/net/bpf_jit_comp.c:bpf_jit_recompile_commit()/abort()
  -> kernel/bpf/trampoline.c:bpf_prog_regenerate_trampolines()

arch/*/net/bpf_jit_comp.c
  -> include/linux/bpf_jit_directives.h
  -> include/linux/bpf.h
```

### 5.3 Arch-neutral versus arch-specific

Arch-neutral pieces:

- UAPI definitions in `include/uapi/linux/bpf.h`
- shared rule and parameter types in `include/linux/bpf_jit_directives.h`
- policy parsing in `kernel/bpf/jit_policy.c`
- canonical validation in `kernel/bpf/jit_validators.c`
- lifecycle orchestration in `kernel/bpf/jit_directives.c`
- `bpf_prog_aux` storage and helper declarations in `include/linux/bpf.h`
- trampoline regeneration in `kernel/bpf/trampoline.c`
- selftests and design notes

Arch-specific pieces:

- `arch/x86/net/bpf_jit_comp.c`
- `arch/arm64/net/bpf_jit_comp.c`
- `arch/arm64/net/bpf_jit.h`

The validator, policy parser, and orchestration are shared. Only the final lowering and compile/commit details vary by architecture.

## 6. Known limitations and design tensions

### 6.1 Emission is interleaved with the JIT, not separable

The rewrite emitters are embedded in `do_jit()` and `build_body()`. That gives good reuse of existing backend bookkeeping, but it means BpfReJIT is not a clean standalone pass that can be run, tested, or reasoned about independently from the architecture JIT. Address maps, exception-table positions, and jump-size convergence all stay entangled with the main backend.

### 6.2 The validator/emitter contract is implicit

The contract is carried by a shared parameter vector plus enum indices, not by a typed per-form structure. The code is disciplined about this, but the API boundary is still manual:

- validator writes indexed parameters
- emitter reads the same indices
- no type system proves the x86 and arm64 interpretations stay aligned

This is the single biggest maintainability cost in the design.

### 6.3 Constant blinding drops recompile support

The design notes already call out blinding as a problem because it can disturb instruction offsets. The implemented behavior is conservative: `bpf_prog_jit_recompile()` rejects already blinded programs with `-EOPNOTSUPP`. That is safe, but it means a legitimate JIT feature can silently become unavailable once blinding is in play. There is no attempt to restate rules against a blinded instruction stream.

### 6.4 JIT convergence has no rule-specific proof

x86 reuses its normal whole-image convergence loop and only checks `proglen == oldproglen`. That is probably sufficient in practice because the rule application is deterministic, but the recompile feature adds new size-changing lowerings without introducing a rule-specific convergence argument or explicit fixed-point test. arm64 avoids the shrink loop entirely, so the cross-arch reasoning model is not uniform.

### 6.5 `struct_ops` needs a broader trampoline model

The syscall explicitly rejects live `struct_ops` programs because the current `bpf_prog_regenerate_trampolines()` path covers generic attached-program and target-program trampolines, not the map-owned/member trampolines used by `struct_ops`. This is a real subsystem boundary, not a temporary TODO inside the emitter.

### 6.6 Cross-arch safety still depends on manual review

The shared validator is a strong anchor, but there is no shared contract test suite that proves:

- x86 and arm64 consume the same canonical parameters the same way
- unsupported forms always fail closed
- native-choice behavior stays semantically equivalent across architectures

Today that assurance comes from code review, architecture-specific tests, and the fact that unsupported forms are rejected early.

### 6.7 Validated rules may still fall back at emission time

Both backends log `emitter fallback` and quietly use the stock lowering if a validated rule still fails during emission. That is the correct safety choice, but it does create a liveness ambiguity: validation success does not guarantee application success. The user-visible contract is therefore "safe best effort", not "validated implies applied".

## 7. Selftest coverage

`tests/kernel/test_recompile.c` contains 27 tests.

### 7.1 What is covered

The suite covers four broad areas.

UAPI and parser rejection:

- wrong magic
- wrong program tag
- wrong instruction count
- wrong architecture id
- non-sealed memfd
- truncated header
- zero-length blob
- out-of-bounds site start

Positive semantic-preservation tests:

- one positive semantic test for each canonical form on x86
- a subprogram-specific rotate case
- bitfield boundary preservation
- stock re-JIT result preservation for the wide-load program

Behavioral and lifecycle tests:

- zero-rule policy blob no-op behavior
- repeated recompiles
- concurrent recompile returns `-EBUSY`
- recompile after attach works

Byte-difference sanity:

- one test (`Wide Site-Only JIT Diff`) checks that the JIT image actually changes at the targeted site without changing program behavior

### 7.2 What is not tested

The suite does not directly exercise several important boundaries:

- overlapping-rule rejection after sort/disjoint validation
- cross-subprogram rule rejection
- invalid `native_choice` or explicit arch-form gate rejection
- interior-edge rejection
- side-effect rejection outside `ENDIAN_FUSION`
- blinded-program rejection
- `struct_ops` rejection path
- rollback after a mid-flight staging failure
- shadow kallsyms add/delete behavior
- keep-old-images behavior after trampoline regeneration failure

### 7.3 Cross-arch test asymmetry

arm64 only implements four forms, and the tests reflect that asymmetry. Several tests accept `-EINVAL` or `-EOPNOTSUPP` as success on arm64 for forms that are x86-only. That means the suite is strong on shared parser behavior and x86 semantic preservation, but it is not a positive contract suite for arm64 lowerings beyond:

- `COND_SELECT`
- `WIDE_MEM`
- `ROTATE`
- `BITFIELD_EXTRACT`

### 7.4 Gap analysis

The current tests are good at proving:

- the UAPI is wired correctly
- the parser rejects malformed blobs
- the x86 backend preserves behavior on the supported forms
- the lifecycle can survive repetition, contention, and at least one attached-program scenario

The biggest gaps are:

1. No direct tests for the validator's control-flow and side-effect boundaries.
2. No forced-failure tests for rollback and staged-image cleanup.
3. No shared cross-arch contract tests for canonical parameter interpretation.
4. Almost no machine-code inspection beyond one wide-load diff case.

In other words, the suite currently proves semantic preservation much better than it proves boundary integrity.

## 8. Comparison with kernel conventions

### 8.1 Relation to other JIT modifications

BpfReJIT is closer to normal kernel JIT evolution than to runtime binary patching.

Compared with constant blinding:

- constant blinding rewrites BPF instructions before normal lowering
- BpfReJIT does not mutate semantics or inject new BPF instructions; it chooses an alternate native lowering for a validated canonical site

Compared with tail-call patching and text poking:

- tail-call patching updates already-emitted native code at known patch points
- BpfReJIT does not poke the old image in place; it stages a full new image and swaps it in through the normal JIT lifecycle

The feature therefore fits existing kernel habits: extend the existing backend and lifecycle machinery rather than bolt on an external optimizer.

### 8.2 UAPI surface analysis

The UAPI surface is relatively small for what the feature does:

- one new BPF command: `BPF_PROG_JIT_RECOMPILE`
- one policy header
- one rule record format
- canonical-form and native-choice enums
- optional verifier-style log buffer fields

That is a restrained surface area. The risk is not UAPI sprawl; the risk is that the policy blob is expressive enough to demand long-term validator and backend maintenance. The implementation counters that by keeping the policy declarative, architecture-scoped, program-tag-bound, and sealed in a memfd.

### 8.3 Is a 6327-line delta reasonable?

Taking the stated 6327-line feature delta at face value, the size is substantial but not obviously excessive for a cross-cutting BPF/JIT subsystem feature. The change spans:

- UAPI definitions
- shared internal types
- a 1732-line validator
- syscall and rollback orchestration
- two architecture backends
- trampoline retargeting
- a 3164-line selftest file

That is exactly where the complexity lives. The feature is not small because it touches all three layers of a kernel code-generation stack.

The stronger criticism is not "too many lines" but "where the lines are." The highest-risk area is the implicit validator/emitter contract spread across shared enums and two backends. If future work adds:

- typed per-form contracts
- contract tests shared across architectures
- more explicit rollback/failure tests

then this size is reasonable for a serious BPF subsystem feature. Without that follow-up, the LOC count is acceptable but the review burden stays high.

## Conclusion

BpfReJIT is best understood as a narrow, policy-driven extension of the existing BPF verifier and JIT model, not as a general optimizer. Its safety argument depends on one strong fact: `jit_validators.c` is the only semantic gate, and the arch emitters only encode validator-normalized sites. The lifecycle machinery in `jit_directives.c` is correspondingly conservative, using staged images, rollback snapshots, trampoline regeneration, and RCU before retiring old text.

The design is coherent and kernel-shaped. Its main technical debt is not the idea itself but the manual contract between the shared validator and the per-arch emitters, plus the relatively thin negative and cross-arch test coverage around that contract.
