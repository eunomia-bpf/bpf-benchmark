# Step 0029 — x86 memory-source compare/test handler composition

Date: 2026-09-27 UTC

## Scope

Close the x86 memory-operand *compare* handler item on the open proof surface by
composing the four `CMP/TEST [mem], rhs` forms and `CMP reg, [mem]`.

Target C paths (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_CMP_MEM` (line 1369)
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_CMP_REG_MEM` (line 1388)

## Changes

- New `native-sim/formal/KProgFormal/X86MemCompareHandler.lean`:
  - `inductive X86MemCompareOp` (`cmpImm`/`testImm`/`cmpReg`/`testReg`) and
    `generatedX86MemCompareStep`: byte load as the left-hand side -> for the
    compare forms the generated zero-borrow subtraction flags, for the test forms
    the generated logical flags; `dst := state.dst` in every branch.
  - `x86MemCompareStepSpec` and `x86_mem_compare_step_refines`: a single
    `simp only` over the four `cases op` bullets, composing
    `x86_mem_load_refines`, `x86_sub_step_refines`, and
    `x86_zero_refines`/`x86_sign_refines`/`x86_logic_flags_refine` under the two
    record constructors.
  - `x86_mem_compare_preserves_dst` (`cases op <;> rfl`) and
    `x86_mem_compare_cmp_flags`/`x86_mem_compare_test_flags` pinning the flag
    half per family.
  - `generatedX86CmpRegMemStep` / `x86CmpRegMemStepSpec` /
    `x86_cmp_reg_mem_step_refines` / `x86_cmp_reg_mem_preserves_dst` for the
    register-left, memory-right form, which always takes the subtraction path.
  - `x86_mem_compare_handler_refines`: the conjunction of destination
    preservation and the register/memory compare step.
  - Four concrete `native_decide` examples: an equal 32-bit compare, an 8-bit
    borrow, a 16-bit test of a zero difference, and the register/memory 64-bit
    borrow. The last pins `{ cf := true, zf := false, sf := true, of := false }`
    for `3` compared against a loaded `5`, and was corrected from a first draft
    that left SF false — `native_decide` caught it. No `sorry` or `admit`.
- New `native-sim/formal/test_x86_mem_compare_handler_host.c`: independent oracle
  against the real generated macros (`KPROG_X86_MEM_LOAD`,
  `KPROG_X86_IMMEDIATE_VALUE`, `KPROG_X86_SBB_RESULT`,
  `KPROG_X86_SET_SUB_FLAGS`, `KPROG_X86_SET_LOGIC_FLAGS`). 4 widths x 14 x 14
  boundary vectors plus 40000 fixed-seed LCG cases.
- Wiring: `KProgFormal.lean` import; `Makefile` check-target block;
  `README.md` memory-source compare paragraph, TCB binding sentence, and the
  stale "compare and multiply memory handlers" tails narrowed to multiply;
  `docs/implementation.md` open-surface bullet.

## Verification

- `lake env lean KProgFormal/X86MemCompareHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_mem_compare_handler_host.c ... &&
  ./build/test_x86_mem_compare_handler_host` — zero warnings,
  `x86 memory-compare host cross-check: OK (40784 cases)`.
- Full `make -C native-sim/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-compare.log`, 150 s, 38 host cross-checks.

## Modeling notes

- Both handlers write no register, so `dst := state.dst` in every branch and
  both preservation theorems are `rfl`. The memory operand is the left-hand side
  in every case; the right-hand side is an already-decoded 64-bit value, which
  keeps register reads and immediate decode out of this bounded step.
- `X86_SIM_L_READ_MEM_VALUE` loads at the *destination* width
  (`X86_SIM_L_EFFECTIVE_WIDTH(WIDTH)`), so unlike IMUL there is no separate
  `memWidth` parameter. The fifth `READ_MEM_VALUE` argument `STORE_DISP`
  (choosing `x86_store_imm_disp` vs `x86_simm`) is an address-decoding concern.
- The generated contract must be evaluated with simulator-level masking.
  `KPROG_X86_SET_SUB_FLAGS` compares *raw* operands; all masking lives in the
  `X86_SIM_L_*` wrappers, and the generated macro's last argument is the width's
  sign *mask*, not the width itself. The first oracle run passed the width there
  and used unmasked operands, producing 39,262 mismatches on exactly the mask
  boundaries (e.g. `w=1 mem=0 reg=0x8000000000000000`: raw `0 < 2^63` is true
  while both masked operands are `0`). Naming the boundary argument and
  masking both operands and the result in a `generated_sub_flags` helper that
  mirrors `X86_SIM_L_SET_SUB_FLAGS` made the oracle green. The generated side
  was correct throughout; the oracle was fixed, never the macro.
- `generated_logic_flags` already masked, mirroring `X86_SIM_L_SET_LOGIC_FLAGS`'s
  `x86_apply_width`; the test forms needed no change.

## Remaining open x86 surface

Register-source multiply handler composition (`X86_SIM_L_EXEC_IMUL_REG_*`), then
effective-address/address-space and immediate/register-RHS selection,
objdump/parser-to-AUX selection relation, C-to-Lean unsigned-semantics
correspondence, compiler/native-byte correspondence, multi-step control-flow
traces, specialization preservation.

## Evidence pair regeneration

Committed and pushed first: `947efed1a` (code increment, 8 files), `a56243dae`
(evidence refresh, 4 files). The retained receipt and log were regenerated at
`947efed1a` (`make -C native-sim/formal check`, exit 0): 52 generator `--check`
runs, 88 Lean module checks, 38 host cross-checks over 1,730,668 oracle cases;
log bytes 13531, sha256
`513080d5cb6592c872a95477409a4df445288c9e43a2d220128867f3209b4610`.

`render_claim_table.formal_evidence(Path('.'))` returns `PASS` (receipt counts
agree with both the retained log and the `native-sim/formal/Makefile` at this
commit, receipt commit equals the log commit, log hash valid).

## Archival ZIP

`docs/artifacts/package-atc26.sh` rebuilt `docs/artifacts/dist/atc26-ae-2.zip`
at `a56243dae`: sha256
`ddbb147e3a69e0a11fcb13f7b81a83d1574b1504f8a4c8789d36778c5427b382`,
933,751,981 bytes, `ARTIFACT_MANIFEST.json.superprojectCommit` =
`a56243dae73eacca939fa6d866c1a7f14f9b128f` (matches HEAD), `self-test: OK
(13 evidence classes)`, `clean-extraction verification OK`. The ZIP is
untracked by design.
