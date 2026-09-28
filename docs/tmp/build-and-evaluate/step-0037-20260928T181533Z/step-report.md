# Step 0037 — shared x86 `MOV_STORE` handler composition

Date: 2026-09-28 UTC

## Scope

Continue the x86 memory family opened by steps 0035 (read-value source) and 0036
(`MOV_LOAD` handler) by proving the handler composition of the one body the two
plain store opcodes share: `X86_SIM_L_EXEC_STORE`. Step 0036 composed the read
side with the width resolution and the ABI-provenance arm; this step composes
the write side, which shares the address computation but has a different set of
asymmetries — one resolved width used for both the value and the write, two
different displacement slices out of the same artifact field, an AUX
source-shift consulted only on the register form, and a stack arm that reuses
the same width expression rather than deriving a second memory width.

Target C path (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_STORE(OP, DST, SRC,
  FLAGS, AUX, IMM)` (713-740). Its chain is: `__x86_l_width = (FLAGS) ? (FLAGS)
  : X86_WIDTH_64`; `__x86_l_disp = (OP) == X86_OP_MOV_STORE_IMM ?
  x86_store_imm_disp(IMM) : x86_simm(IMM)`; `__x86_l_value = (OP) ==
  X86_OP_MOV_STORE_IMM ? x86_store_imm_value(IMM, __x86_l_width) :
  X86_SIM_L_READ_REG(SRC)`; if the opcode is the register form *and*
  `X86_REG_AUX_GET_SRC_SHIFT(AUX) != 0` then `__x86_l_value >>=
  X86_REG_AUX_GET_SRC_SHIFT(AUX)`; `__x86_l_disp = X86_SIM_L_MEM_OFFSET(AUX,
  __x86_l_disp)`; then `(DST) == X86_RSP` → `X86_SIM_L_STACK_WRITE((s64)base +
  disp, X86_SIM_L_EFFECTIVE_WIDTH(FLAGS), value)`, else `X86_SIM_L_STORE_ADDR`
  on `base + disp` at `__x86_l_width`.
- Callers (`x86_sim_local_bpf.h:1624-1627`): `X86_OP_MOV_STORE_IMM` (`0x07`),
  `X86_OP_MOV_STORE_REG` (`0x08`).

## Changes

- New `native-sim/formal/generate_x86_store_spec.py` (56th generator), emitting
  `native-sim/formal/x86_store_spec.json`,
  `native-sim/formal/KProgFormal/GeneratedX86Store.lean` and
  `native-sim/formal/generated/x86_store.h`. Four closed unary tables of
  selectors, plus the width resolution:
  - `resolveWidth : Code -> Code` over the five width codes
    (`absent`/`b8`/`b16`/`b32`/`b64`), with the 64-bit fallback for `absent`
    (the generated form of `KPROG_X86_STORE_WIDTH` and the body's
    `X86_SIM_L_EFFECTIVE_WIDTH(FLAGS)`);
  - `dispForm : Bool -> DispForm` (`immHighHalf`/`signedImm`), `valueSource :
    Bool -> ValueSource` (`immediateWidth`/`registerRead`), `shiftSource :
    Bool -> ShiftSource` (`auxSrcShift`/`zero`) — the three `(OP) ==
    X86_OP_MOV_STORE_IMM` selections, each as its own table so the two
    displacement arms cannot be conflated;
  - `arm : Bool -> Arm` (`stackWrite`/`memoryStore`), the generated form of
    `KPROG_X86_STORE_ARM`.
- New `native-sim/formal/KProgFormal/X86StoreHandler.lean`:
  - `x86StoreWidthSpec` — the fallback stated independently from the raw code,
    and `x86_store_width_refines`; plus `x86_store_width_not_absent` (total,
    never the absent code) and `x86_store_width_absent_defaults`.
  - `x86StoreDispFormSpec`/`x86_store_disp_form_refines`,
    `x86StoreValueSourceSpec`/`x86_store_value_source_refines`,
    `x86StoreShiftSourceSpec`/`x86_store_shift_source_refines`.
  - `x86StoreArmSpec (isRsp : Bool) : Arm := if isRsp then .stackWrite else
    .memoryStore` and `x86_store_arm_refines`; `x86_store_arm_stack_iff`.
  - `x86StoreDispSpec (isImm) (imm) := if isImm then ((imm >>> 32).setWidth
    32).signExtend 64 else imm`; `generatedX86StoreDisp` (the `match dispForm
    isImm` form) and `generated_x86_store_disp_refines`.
  - `x86StoreValueSpec (isImm) (imm srcValue) (width) := if isImm then
    x86ImmediateValueSpec imm width else srcValue`; `generatedX86StoreValue`
    and `generated_x86_store_value_refines`.
  - `x86StoreShiftSpec (isImm) (srcShift) : Nat := if isImm then 0 else
    x86ShiftCountSpec srcShift .w64`; `generatedX86StoreShift` and
    `generated_x86_store_shift_refines`; plus `x86_store_imm_shift_is_zero`
    and `x86_store_reg_shift_is_mod64`.
  - `x86StoreByteUpdate`/`x86StoreByteUpdateSpec` (the `x86WidthBitsSpec width
    / 8` form) and `x86_store_byte_update_refines` — the byte update reused
    from `x86_mem_store_byte_refines` but stated over the store's
    `bytes : Nat -> X86MemByte` carrier.
  - `generatedX86StoreStep`/`x86StoreStepSpec` and `x86_store_step_refines`
    (exported as a five-conjunct: the four field equalities plus
    `∀ i, bytes i = …`), with `x86_store_step_fields_refines` and
    `x86_store_step_bytes_refines` as reusable pieces.
  - Asymmetry theorems: `x86_store_both_arms_use_one_width` (the stack arm's
    effective width equals the resolved width — no second, AUX-sourced memory
    width as in the read body) and `x86_store_bytes_above_width_unchanged`.
  - Six `native_decide` examples over the canonical arms:
    `x86_store_disp_forms_differ`, `x86_store_value_sources_differ`,
    `x86_store_imm_w16_example`, `x86_store_reg_shift_example`,
    `x86_store_stack_arm_example`.
  No `sorry` or `admit`.
- New `native-sim/formal/test_x86_store_host.c` — the independent oracle.
  Part 1 sweeps the generated width resolution over the five width codes; part
  2 the generated arm contract; part 3 the whole handler over a deterministic
  memory/register/stack model (16 base registers × 2 opcodes × 5 index codes ×
  5 shift codes × 5 FLAGS codes × 4 displacement classes × 3 index values =
  19,200 cases) against an explicit store-body model, snapshotting and
  restoring the pristine buffers around each pair and comparing **every**
  resulting memory and stack byte; part 4 pins six asymmetries (the two
  displacement slices, the register-only AUX shift read plus its modulo-64
  truncation, the stack arm writing only the frame, the narrow store leaving
  the byte past the width untouched, the eight little-endian bytes of the
  wide store, and the scaled index contribution). **48,013 cases**, zero
  warnings.
- Wiring: `import KProgFormal.GeneratedX86Store` and `import
  KProgFormal.X86StoreHandler` in `native-sim/formal/KProgFormal.lean` (56-57);
  Makefile `--check` line after the mov-load generator (60) and the Lean+oracle
  triple after the mov-load triple (161-164); README paragraph after the
  `MOV_LOAD` paragraph and an extended binding list;
  `docs/implementation.md` open-surface paragraph extended with the store
  composition.

## Design notes

- **The observable state is memory only.** The store body writes no flags, no
  register, and no ABI tag; `X86StoreEffect` therefore carries only
  `arm`/`width`/`value`/`addr`/`bytes`, and `X86MovLoadState` is deliberately
  not reused. The destination is an address, not a register file slot.
- **One resolved width, both uses.** The body computes `__x86_l_width` once and
  feeds it to both `x86_store_imm_value` and `X86_SIM_L_STORE_ADDR`; the stack
  arm then re-derives `X86_SIM_L_EFFECTIVE_WIDTH(FLAGS)`, which is the *same*
  expression. This differs from the read body, whose memory width falls back to
  the write width from a separate AUX byte. The Lean model indexes the byte
  update by the single `width`, so the equality is the statement
  `x86_store_both_arms_use_one_width`; the C helper's re-derivation is carried
  by the prose.
- **The two displacement arms are not unified.** `x86_store_imm_disp(IMM) =
  (s32)(IMM >> 32)` reads bits 32..63 of the 64-bit artifact field, truncates
  to 32 bits, and sign-extends; `x86_simm(IMM) = (s64)IMM` sign-extends the
  whole field. The generated `DispForm` table keeps the two apart and the
  oracle's part 4 Pin 1 pins that the same artifact yields different addresses.
- **The register shift amount is modulo 64.** The C `>>=` on a `__u64` uses the
  x86 count truncation, while Lean's `>>>` on `BitVec 64` saturates to zero
  above the word width. The modeled shift is therefore
  `(srcShift &&& 63).toNat`, routed through `GeneratedX86ShiftCount.count srcShift
  .w64` and `x86_shift_count_refines` (which uses the same
  `Nat.and_two_pow_sub_one_eq_mod` argument with exponent 6). Stated in the
  `x86StoreShiftSpec` docstring and in the oracle's `model_step` comment.
- **The generated contract is not wired into the live sim** — `x86_store.h`
  joins the `used=0` set of proof-only generated headers
  (`x86_mem_offset.h`, `x86_width.h`, `x86_mem_dispatch.h`, `x86_mov_load.h`,
  …). Wiring `X86_SIM_L_EXEC_STORE` is a separate, riskier edit; same decision
  as the previous four increments.
- **The explicit generated-selector helper defs**
  (`generatedX86StoreDisp`/`Value`/`Shift`) are the shape that made this proof
  tractable: each is the `match <generated selector> isImm with …` form, has a
  `.refines` lemma reducing it to the independent spec, and the step proof is
  then `cases op <;> cases isRsp <;> simp only [generatedX86StoreStep,
  x86StoreStepSpec, …, generated_x86_store_*_refines, GeneratedX86Store.arm,
  reduceCtorEq, ↓reduceIte, true_and]`. This is the pattern to copy for the next
  handler.
- **The oracle must snapshot/restore** the pristine buffers around each
  `contract_step`/`model_step` pair because the store mutates memory, unlike
  `MOV_LOAD`. Part 3 restores before *each* call and `memcpy`s both buffers out
  after `contract_step` so the two runs are compared from identical starting
  state.

## Verification

- `lake build` then `lake env lean KProgFormal/GeneratedX86Store.lean` and
  `lake env lean KProgFormal/X86StoreHandler.lean`: both pass, 0 `sorry`.
- `python3 generate_x86_store_spec.py && python3 generate_x86_store_spec.py
  --check`: passes (no stale output; `IDEMPOTENT`).
- Standalone oracle: `cc -Wall -Wextra -O2 -I. test_x86_store_host.c
  -o build/test_x86_store_host && ./build/test_x86_store_host`
  → `x86 store handler host cross-check: OK (48013 cases)`.
- **Non-vacuity probes.** Five separate mutations of the oracle's model — the
  displacement form, the modulo-64 shift, the stack-arm width, the store width
  argument, and the immediate-value rule — each make the oracle exit 1, so the
  19,200-case sweep is sensitive to every asymmetry it claims to pin.
- Full `make -C native-sim/formal check`: RC=0, 0 `error:` lines, **56
  generators / 101 Lean module checks / 46 host cross-checks over 2,175,681
  cases**.
- Commit `ff267c8b5` (code increment, 10 files).

## Open after this step

The remaining memory forms (`_MOVBE_LOAD`/`_MOVBE_STORE`, which compose the
load/store with the already-proved `x86_bswap`) and `_MOV_LOAD_MAP_PTR` (a
pointer-immediate write, not a memory read) remain open, along with the
remaining x86 surface (`_CMOV`/`_CMOV_MEM`, `_SETCC`/`_SETCC_MEM`,
`_STORE_XMM0`/`_LOAD_XMM0`, `_CALL_MEMCPY_{,REG}`/`_CALL_MEMSET_{,REG}`,
`_PUSH`/`_POP`, `_REP_MOVS`, `_ANDN{,_MEM}`, `_BZHI{,_MEM}`,
`_CMP_IMM_OP`/`_CMP_REG_OP`), the index register decode and packed-AUX layout,
the simulator-stack-to-abstract-frame-base mapping, compiler/native bytes,
multi-step traces, and specialization preservation.
