# Step 0040 — x86 `CMOV` / `CMOV_MEM` handler composition

Date: 2026-09-29 UTC

## Scope

Continue the x86 one-instruction handler line after steps 0036 (`MOV_LOAD`),
0037 (shared `MOV_STORE`), 0038 (`SETCC`) and 0039 (`SETCC_MEM`) with the two
conditional-move forms: `X86_SIM_L_EXEC_CMOV` (`X86_OP_CMOV`, `0x15`) and
`X86_SIM_L_EXEC_CMOV_MEM` (`X86_OP_CMOV_MEM`, `0x40`). Both are composed in one
module because they share the dependency chain the previous four steps proved
— step 0038's condition decode, step 0037's width/mem-offset pieces and the
register-write contract — and differ only in where the condition byte comes
from and whether the value crosses memory.

Target C path (read-only reference, `native-sim/x86/x86_sim_local_bpf.h`):

- `X86_SIM_L_EXEC_CMOV` (L1488-1503): the condition is the **whole AUX word**
  (`EVAL_CC(AUX)`), not a byte field; at `w64` the true arm preserves the
  source's pointer tag through `X86_SIM_L_WRITE_REG_PTR_TAG`, and every
  narrower arm (and the false arm) scalarizes through
  `X86_SIM_L_WRITE_REG_WIDTH`.
- `X86_SIM_L_EXEC_CMOV_MEM` (L1505-1518): the condition is the AUX
  **source-shift** byte (`X86_REG_AUX_GET_SRC_SHIFT`), the value is read
  through the `X86_SIM_L_MEM_READ` pieces with a two-level width fallback
  (`X86_MEM_AUX_MEM_WIDTH(AUX) ?: effective(FLAGS)`) and the high-half
  displacement slice (`STORE_DISP = 1`), and the writeback goes through
  `X86_SIM_L_WRITE_REG_WIDTH` at **every** width, including the 64-bit one —
  so the memory form never preserves a provenance tag, unlike the register
  form's `w64` arm.

## Changes

- New `native-sim/formal/generate_x86_cmov_spec.py` (59th generator),
  emitting `x86_cmov_spec.json`, `KProgFormal/GeneratedX86Cmov.lean` and
  `generated/x86_cmov.h`:
  - Lean: the `X86CmovOp`/`ConditionSource` op tables, the whole-word
    `condOf` / low-byte `condOfByte` / source-shift `condOfSrcShift`
    condition tables composed onto `GeneratedX86Setcc`'s expression table
    (`GeneratedX86Cmov.evalCond`), the width tables
    `resolveWidth`/`resolveMemWidth` over `Code`, and the is-64-keyed
    `writeBack` table (`Bool -> WriteBack`: `pointerTag` on the 64-bit
    test, `scalarize` below).
  - C: `_Static_assert` drift checks against `X86_OP_CMOV`/`X86_OP_CMOV_MEM`/
    `X86_WIDTH_64`, the condition macros (`KPROG_X86_CMOV_CONDITION` the
    whole word, `…_CONDITION_BYTE` the low byte,
    `KPROG_X86_CMOV_MEM_CONDITION` the `>> 24` decode), the width
    macros, and the writeback table.
- New `native-sim/formal/KProgFormal/X86CmovHandler.lean` (515 lines):
  - 12 refinement lemmas bridging the generated contracts to the C bodies:
    the per-contract refinements (condition byte/word, mem condition,
    width/mem-width/mem-disp, writeback, evalRaw) and the top-level
    `x86_cmov_step_refines` (detailed next).
  - `x86_cmov_step_refines` (9-argument): one step relation composing both
    handler bodies over the generated contracts;
    `generatedX86CmovStep` models the write as a 64-bit-test-keyed dispatch —
    `pointerTag` at 64 bits, `scalarize` below — with the destination
    left untouched when the condition is false.
  - Asymmetry theorems: `x86_cmov_false_condition_no_write`,
    `x86_cmov_w64_arm_preserves_source_tag`,
    `x86_cmov_narrow_arm_scalarizes`,
    `x86_cmov_condition_sources_differ` (one AUX word names two different
    conditions), `x86_cmov_whole_word_not_low_byte_equality`,
    `x86_cmov_mem_width_two_level_fallback`,
    `x86_cmov_mem_disp_differs_from_setcc_mem`,
    `x86_cmov_writeback_only_w64`,
    `x86_cmov_unsupported_example`. No `sorry` or `admit`.
- New `native-sim/formal/test_x86_cmov_host.c` — the independent oracle.
  - Part 1 sweeps the 14 × 16 condition expression table, the
    whole-word (256 × 256) and truncating byte (256 × 16) condition
    spaces through the generated macros into the real
    `KPROG_X86_EVAL_CC` (70,112 cases including the 256-case mem
    source-shift byte extraction).
  - Part 2 sweeps all 6 FLAGS codes through the width and writeback
    contracts.
  - Part 3 drives the register form over a deterministic register model
    (30,240 cases), comparing the w64 pointer-tag arm and the scalarizing
    narrow arms against a hand-written C model.
  - Part 4 drives the memory form (384,000 cases), with the model
    deliberately scalarizing at **every** width, including 64-bit.
  - Part 5 pins the asymmetries: false-condition no-write, the 64-bit
    tag preservation (reg form), the 64-bit scalarization (mem form), the
    whole-word-vs-low-byte inequality, the two-level width fallback, the
    high-half displacement.
  **484,369 cases**, zero non-macro `-Wall -Wextra` warnings.
- Wiring: `import KProgFormal.GeneratedX86Cmov` and `import
  KProgFormal.X86CmovHandler` in `native-sim/formal/KProgFormal.lean`;
  Makefile `--check` line after the setcc_mem generator and the
  Lean+oracle triple after the setcc_mem triple; README CMOV paragraph
  after the `SETCC_MEM` paragraph plus the extended binding list;
  `docs/implementation.md` open-surface list extended with the CMOV
  composition.

## Design notes

- **The two forms share one condition table but read different fields of the
  same AUX word.** `CMOV` reads the whole word; `CMOV_MEM` reads the
  source-shift byte at bits 24..31. The generator therefore composes both
  onto the one `GeneratedX86Setcc.evalCond` table, and the counterexample pin
  (`x86_cmov_condition_sources_differ`, `0x05000000` vs. `0x00000005`) is
  real content: one AUX word names two different conditions.
- **The writeback contract is keyed by the 64-bit test, not by opcode.** The
  generated `writeBack : Bool -> WriteBack` takes the width's is-64 test, and
  the handler's spec `x86CmovWriteBackSpec : X86Width -> WriteBack` keys it
  by width; `x86_cmov_writeback_refines` bridges the two. At 64 bits the
  register form preserves the source's pointer tag, and every narrower arm
  scalarizes; `x86_cmov_writeback_only_w64` pins that the `pointerTag` arm
  fires only at the 64-bit width. The memory form, by contrast, scalarizes at
  **every** width including 64-bit — pinned not by a dedicated Lean theorem
  (the arm lemmas `x86_cmov_w64_arm_preserves_source_tag` and
  `x86_cmov_narrow_arm_scalarizes` are `.cmov`-only) but by the oracle part 4
  model + Pin 4: the memory form writes through
  `KPROG_X86_WRITE_REG64(…, X86_SIM_TAG_SCALAR)` even at 64 bits, so the
  `pointerTag` arm is register-form-only.
- **The whole-word condition is an *equality*, not a decode.** The register
  form's condition is `EVAL_CC(AUX)` with `AUX` the whole word; the
  low-byte table is therefore *not* a faithful statement, and
  `x86_cmov_whole_word_not_low_byte_equality` (the `0x00000105` witness:
  whole word unsupported → C default false, low byte `0x05` → true) pins the
  distinction.
- **The memory form's displacement is the high half, unlike
  `SETCC_MEM`'s whole artifact.** The two memory forms differ only in that
  slice and in where the value crosses: `SETCC_MEM` writes memory,
  `CMOV_MEM` writes the destination register. The pin
  `x86_cmov_mem_disp_differs_from_setcc_mem` (the `0xdeadbeef00000008`
  witness) records that the immediate store's slice, not the whole artifact,
  is the memory form's displacement.

## Verification

- `lake build` then `lake env lean KProgFormal/X86CmovHandler.lean`:
  passes, 0 `error:` lines, 0 `sorry`.
- `python3 generate_x86_cmov_spec.py && python3
  generate_x86_cmov_spec.py --check`: passes (`IDEMPOTENT`).
- Standalone oracle: `cc -Wall -Wextra -O2 -I. test_x86_cmov_host.c
  -o build/test_x86_cmov_host && ./build/test_x86_cmov_host`
  → `x86 cmov handler host cross-check: OK (484369 cases)`, zero warnings.
- **Non-vacuity probes.** Six mutations of the real generated header/spec
  each make the oracle or the drift check exit 1, and each is then reverted:
  1. `KPROG_X86_CMOV_CONDITION(AUX)` from `(AUX)` to `((__u8)(AUX))`
     (low-byte) → part 1 whole-word rejected space now accepts words with
     bits 8..31 set that should pin to the C default 0 → oracle exit 1.
  2. `KPROG_X86_CMOV_MEM_CONDITION(AUX)` from the `>> 24` decode to
     `((__u8)(AUX))` → part 1 mem extraction / part 4 / Pin 6 → exit 1.
  3. The writeback branch selector's `if` inverted (the `POINTER_TAG` /
     `SCALARIZE` codes swapped) → part 2 writeback mismatch at the
     64-bit code → exit 1. (Relabeling the numeric codes alone does **not**
     trip the oracle — the codes are a label both sides of the check share,
     so only the branch-inversion is the meaningful mutation.)
  4. `KPROG_X86_CMOV_MEM_DISP(IMM)` from the high-half slice to the whole
     artifact → part 4 / Pin 8 → exit 1.
  5. `KPROG_X86_CMOV_MEM_WIDTH` shift `>> 16` → `>> 8` → part 4 → exit 1.
  6. Mutating the opcode in `x86_cmov_spec.json` from `0x15` to `0x25`
     makes `python3 generate_x86_cmov_spec.py --check` exit 1 (stale).
  All six are reverted; the regenerated header and the drift check are clean
  after restoration.
- Full `make -C native-sim/formal check`: RC=0, 0 `error:` lines, **59
  generators / 107 Lean module checks / 49 host cross-checks over
  4,303,967 cases**.
- Commit: prepared, not run (the three-commit sequence below is staged for
  the user's explicit scoped commit ask).

## Open after this step

`_MOVBE_LOAD`/`_MOVBE_STORE`, `_MOV_LOAD_MAP_PTR`, and the rest of the x86
surface (`_STORE_XMM0`/`_LOAD_XMM0`, `_CALL_MEMCPY_{,REG}`/
`_CALL_MEMSET_{,REG}`, `_PUSH`/`_POP`, `_REP_MOVS`, `_ANDN{,_MEM}`,
`_BZHI{,_MEM}`, `_CMP_IMM_OP`/`_CMP_REG_OP`), the index register decode and
packed-AUX layout, the simulator-stack-to-abstract-frame-base mapping,
compiler/native bytes, multi-step traces, and specialization preservation
remain open.
