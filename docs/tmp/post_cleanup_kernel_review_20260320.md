# 2026-03-20 post-cleanup kernel review

## Scope

- Reviewed `git -C vendor/linux-framework diff HEAD~1..HEAD`.
- Actual kernel diff scope is one file only: `kernel/bpf/jit_validators.c`.
- `HEAD` is `fb0470be3` (`bpf: table-driven validators for ROTATE/WIDE_MEM, low-risk simplification`).
- Design baseline: `docs/kernel-jit-optimization-plan.md` §1.4 and §4.4.
- Extra checks run:
  - `make -C vendor/linux-framework -j$(nproc) kernel/bpf/jit_validators.o`
  - `git -C vendor/linux-framework diff --check HEAD~1..HEAD`

## Findings

- No blocking findings in `HEAD~1..HEAD`.
- This diff does not violate the requested design principles.

## Requested checklist

### 1. Table-driven generic validate path still fail-closed

- `bpf_jit_match_form_pattern()` / `bpf_jit_validate_form_patterns()` still return `false` on any pattern mismatch, extract failure, post-check failure, or bounds failure (`kernel/bpf/jit_validators.c:449-500`).
- New field selectors `CODE_CLASS` / `CODE_SRC` in `bpf_jit_pattern_field_value()` only add read paths; invalid field ids still return `false` (`kernel/bpf/jit_validators.c:332-359`).
- `ROTATE` stays fail-closed:
  - shift-op pairing mismatch returns `false`
  - `rot_amount + rsh_amount != width` returns `false`
  - masked form with non-canonical high mask returns `false`
  - see `kernel/bpf/jit_validators.c:978-1020`
- `WIDE_MEM` stays fail-closed:
  - head/body chunk pattern mismatch returns `NULL` -> validator `false`
  - bad chunk count, bad total `site_len`, duplicate offsets, non-contiguous offsets, or inconsistent endian shifts all return `false`
  - see `kernel/bpf/jit_validators.c:787-944`

Conclusion: pattern mismatch returns `false`; param synthesis failure also returns `false`.

### 2. Validator remains the only safety gate

- This diff does not modify x86 or arm64 emitters.
- x86 still consumes canonical params mechanically in:
  - `arch/x86/net/bpf_jit_comp.c:2146-2225`
  - `arch/x86/net/bpf_jit_comp.c:2478-2500`
  - `arch/x86/net/bpf_jit_comp.c:2989-3023`
- arm64 still consumes canonical params mechanically in:
  - `arch/arm64/net/bpf_jit_comp.c:638-731`
- Layer 0.5 arch gating is still enforced before Layer 1 validation in `bpf_jit_validate_rule()` (`kernel/bpf/jit_validators.c:1956-1971`), with arch declarations in:
  - `arch/x86/net/bpf_jit_comp.c:5734-5758`
  - `arch/arm64/net/bpf_jit_comp.c:3850-3864`
- The new declarative data still covers the safety checks that matter for these forms:
  - `ROTATE`: source shape, copy topology, shift immediate range, shift-op pairing, `rot+rsh==width`, canonical mask
  - `WIDE_MEM`: shared base register, non-aliasing with result register, per-chunk structure, contiguous offsets, endian normalization, width/count, total `site_len`

Conclusion: no new param validation moved into emitters, and the validator tables plus post-normalization still carry the safety burden.

### 3. Cross-arch shared helpers introducing arch-specific assumptions into arch-neutral code

- N/A for the actual diff: no arch file changed in `HEAD~1..HEAD`.
- The new helpers added to `jit_validators.c` are BPF-shape/pattern utilities, not arch-specific emit logic.
- Existing x86-specific `BRANCH_FLIP` byte-budget logic remains in `jit_validators.c`, but it predates this commit and is unchanged here.

Conclusion: no new arch-specific assumption was introduced by this diff.

### 4. `alu_insn_linearizable` merge equivalence

- N/A for this diff.
- `bpf_jit_alu_insn_linearizable()` in current `HEAD` matches `HEAD~1`; there is no semantic delta in this commit (`kernel/bpf/jit_validators.c:1055-1095`).

### 5. opcode switch -> table coverage

- N/A for this diff.
- `bpf_jit_form_meta[]` already existed and is unchanged (`kernel/bpf/jit_validators.c:1849-1887`).
- No new coverage hole was introduced in the form dispatch path.

### 6. Dead code / unreachable path

- The old bespoke `ROTATE` / `WIDE_MEM` parsing helpers were removed cleanly; no remaining references were found in the tree.
- New helpers introduced by this diff are all referenced from live validator paths.
- Focused compile check and `git diff --check` both passed.

Conclusion: no new dead code or unreachable path found.

## Notes on items listed in the task but not present in the actual diff

- `ADDR_CALC`, `BITFIELD_EXTRACT`, and `ENDIAN_FUSION` per-form validators are not materially changed in `HEAD~1..HEAD`; only the shared substrate around them is touched, and its control flow remains fail-closed.
- `a64_invert_cond`, cross-arch emitter helper sharing, and switch->table replacement are not part of the actual diff produced by `git -C vendor/linux-framework diff HEAD~1..HEAD`, so they cannot be reviewed as "today's changed code" from this commit.

## Verdict

- Static review result: no design-principle violation found in the actual `HEAD~1..HEAD` kernel diff.
- Runtime selftests / VM benchmark reruns were not executed for this review; the conclusion is based on code inspection plus focused compile hygiene checks.
