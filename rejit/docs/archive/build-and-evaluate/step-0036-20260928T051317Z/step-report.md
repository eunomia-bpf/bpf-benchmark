# Step 0036 — shared x86 `MOV_LOAD` handler composition

Date: 2026-09-28 UTC

## Scope

Continue the x86 memory-load family opened by step 0035 by proving the handler
composition of the one body the three plain load opcodes share:
`X86_SIM_L_EXEC_MOV_LOAD`. Step 0035 classified the *value source* of the read
body; this step composes that read with the two things the read body does not
cover — the resolution of the write and memory widths, and the ABI-provenance
arm — into a single refine theorem over an independent statement.

Target C path (read-only reference):
- `kprog/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_MOV_LOAD(OP, DST, SRC,
  FLAGS, AUX, IMM)` (669-711). Its chain is: resolve `__x86_l_mem_width` from
  `X86_MEM_AUX_MEM_WIDTH(AUX)` with a fallback to `__x86_l_write_width`, itself
  `(FLAGS) ? (FLAGS) : X86_WIDTH_64`; form the effective address from the base
  pointer and `X86_SIM_L_MEM_OFFSET`; then `(SRC) == X86_RSP` →
  `X86_SIM_L_STACK_READ` + `X86_SIM_L_WRITE_REG_WIDTH`;
  `(OP) == X86_OP_MOV_LOAD && mem_width == 64 && write_width == 64 &&
  base_tag == ABI` → `KPROG_ABI_LOAD_TAG` + `X86_SIM_L_WRITE_REG_PTR_TAG`; else
  `X86_SIM_L_LOAD_ADDR`, `x86_sign_extend` for `_MOVSX_LOAD`, and
  `X86_SIM_L_WRITE_REG_WIDTH`.
- Callers (`x86_sim_local_bpf.h:1616-1619`): `X86_OP_MOV_LOAD`,
  `X86_OP_MOV_LOAD_SCALAR`, `X86_OP_MOVSX_LOAD`.

## Changes

- New `kprog/formal/generate_x86_mov_load_spec.py` (55th generator),
  emitting `kprog/formal/x86_mov_load_spec.json`,
  `kprog/formal/KProgFormal/GeneratedX86MovLoad.lean` and
  `kprog/formal/generated/x86_mov_load.h`. Two closed tables:
  - `resolveWidth : Code -> Code -> Code × Code` over the five width codes
    (`absent`/`b8`/`b16`/`b32`/`b64`, 25 rows), the generated form of
    `KPROG_X86_MOV_LOAD_WRITE_WIDTH` + `KPROG_X86_MOV_LOAD_MEM_WIDTH`;
  - `arm : Bool -> Bool -> Bool -> Bool -> Bool -> Arm` over the five selector
    facts (32 rows), the generated form of `KPROG_X86_MOV_LOAD_ARM`, with
    `Arm` = `stackRead`/`abiPtrWrite`/`ordinary`.
- New `kprog/formal/KProgFormal/X86MovLoadHandler.lean`:
  - `x86MovLoadResolveWidthSpec` — the two fallbacks stated independently from
    the raw codes, and `x86_mov_load_resolve_width_refines` equating the
    generated table to it for all 25 pairs.
  - `x86MovLoadArmSpec` — the arm as a predicate *nesting*
    (`if isRsp then .stackRead else if isMovLoad && mem64 && write64 && abi
    then .abiPtrWrite else .ordinary`), not a copy of the generated table, and
    `x86_mov_load_arm_refines` equating the table to it for all 32 combinations.
  - `generatedX86MovLoadStep`/`x86MovLoadStepSpec` and
    `x86_mov_load_step_refines` — the whole handler, composing the width
    resolution, the arm, the memory-access byte ladder
    (`x86_mem_load_refines`), the sign extension (`x86_sign_extend_refines`),
    the ABI tag (`generated_abi_load_tag_refines`) and the partial-register
    writeback (`x86_reg_write_refines`).
  - Asymmetry theorems: `x86_mov_load_arm_stack_ignores_op_and_tag`,
    `x86_mov_load_arm_abi_iff`,
    `x86_mov_load_stack_arm_ignores_sign_extension`,
    `x86_mov_load_ordinary_scalarizes`, `x86_mov_load_ordinary_w64_masks_mem`,
    `x86_mov_load_abi_arm_tag`, `x86_mov_load_abi_arm_tag_at_end`,
    `x86_mov_load_resolved_not_absent`, `x86_mov_load_absent_defaults`,
    `x86_mov_load_stack_read_width` (the stack helper's effective width equals
    the resolved memory width), and `x86_mov_load_arm_all_reachable`.
  - Six `native_decide` examples over the canonical arms.
  No `sorry` or `admit`.
- New `kprog/formal/test_x86_mov_load_host.c` — the independent oracle:
  part 1 sweeps the generated width resolution over the 25 code pairs; part 2
  the generated arm table over its 32 selector combinations; part 3 the whole
  handler over a deterministic memory/register/stack model (16 base registers ×
  4 base tags × 3 opcodes × 5 AUX codes × 5 FLAGS codes × 3 displacement
  classes × 2 ABI kinds × 3 destination values) against an explicit handler
  model that restates the arms from the raw fields; part 4 pins the ABI-arm
  provenance. **86,461 cases**, zero warnings.
- Wiring: `import KProgFormal.GeneratedX86MovLoad` and
  `import KProgFormal.X86MovLoadHandler` in `kprog/formal/KProgFormal.lean`
  (54-55); Makefile `--check` line after the mem-dispatch generator (59) and the
  Lean+oracle triple after the read-dispatch triple (156-159); README paragraph
  after the read-dispatch paragraph and an extended binding list;
  `docs/shared/implementation.md` open-surface bullet extended.

## Design notes

- **Two x86-specific asymmetries.** The first arm test is register *identity*
  (`is_rsp`), so the stack arm overrides the ABI arm; and a stack-based
  `_MOVSX_LOAD` does not sign-extend, because the register-identity test
  precedes the opcode test. The ABI pointer arm is gated on the plain
  `_MOV_LOAD` opcode *and* on both resolved widths being 64 bits, so an
  ABI-tagged base reached by a narrow opcode falls through to the ordinary
  scalar load and is scalarized. All four are stated in the generator
  docstring, the generated C header, the Lean doc comments and the oracle
  header.
- **The generated contract is closed over an explicit `Code` inductive, not
  `Nat`.** A partial `Nat` table would let `resolveWidth` be partial
  (`missing cases`); the five codes include the 0 "absent" code the wide form
  actually carries.
- **`x86WidthIs64` is a local matcher, not `==`.** Lean has no usable
  `BEq X86Width` for `native_decide` evaluation of the abbrev; `==` produced
  `unknown constant 'KProgFormal.X86Width.w64'` errors.
- **The generated contract is not wired into the live sim.** Most x86 generated
  contracts are proof-only (audit: `used=0` for `x86_mem_offset.h`,
  `x86_bitops.h`, `x86_width.h`, `x86_mem_dispatch.h`, `x86_signed.h`, …);
  `x86_mov_load.h` joins that set. Wiring `X86_SIM_L_EXEC_MOV_LOAD` is a
  separate, riskier edit; same decision as the MOVX and read-dispatch
  increments.

## Verification

- `lake build` then `lake env lean KProgFormal/GeneratedX86MovLoad.lean` and
  `lake env lean KProgFormal/X86MovLoadHandler.lean`: both pass.
- `python3 generate_x86_mov_load_spec.py && python3 generate_x86_mov_load_spec.py
  --check`: passes (no stale output).
- Standalone oracle: `cc -Wall -Wextra -O2 -I. test_x86_mov_load_host.c
  -o build/test_x86_mov_load_host && ./build/test_x86_mov_load_host`
  → `x86 mov-load handler host cross-check: OK (86461 cases)`.
- Full `make -C kprog/formal check`: RC=0, 0 `error:` lines, **55
  generators / 99 Lean module checks / 45 host cross-checks over 2,127,668
  cases**.
- Commit `5d7b435c2` (code increment, 10 files).

## Open after this step

The register-source narrow/wide forms and the remaining memory forms
(`_MOVBE_LOAD`/`_MOVBE_STORE`), the store body (`X86_SIM_L_EXEC_STORE` over
`_MOV_STORE_IMM`/`_MOV_STORE_REG`), and `_MOV_LOAD_MAP_PTR` (a
pointer-immediate write, not a memory read) remain open, along with the
remaining x86 surface (`_CMOV`/`_CMOV_MEM`, `_SETCC`/`_SETCC_MEM`,
`_STORE_XMM0`/`_LOAD_XMM0`, `_CALL_MEMCPY_{,REG}`/`_CALL_MEMSET_{,REG}`,
`_PUSH`/`_POP`, `_REP_MOVS`, `_ANDN{,_MEM}`, `_BZHI{,_MEM}`,
`_CMP_IMM_OP`/`_CMP_REG_OP`), the index register decode and packed-AUX layout,
the simulator-stack-to-abstract-frame-base mapping, compiler/native bytes,
multi-step traces, and specialization preservation.
