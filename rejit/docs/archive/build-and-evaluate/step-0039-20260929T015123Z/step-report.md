# Step 0039 — x86 `SETCC_MEM` handler composition

Date: 2026-09-29 UTC

## Scope

Continue the x86 one-instruction handler line after steps 0036 (`MOV_LOAD`),
0037 (shared `MOV_STORE`) and 0038 (`SETCC`) with the memory-writing form of the
same condition: `X86_SIM_L_EXEC_SETCC_MEM`, the body behind `X86_OP_SETCC_MEM`
(`0x3e`).

`SETCC_MEM` was chosen over `CMOV`/`CMOV_MEM` because it reuses both halves of
the dependency chain the previous two steps composed — step 0038's condition
decode and step 0037's memory-write arm (`x86_mem_offset_refines`,
`x86_mem_store_byte_refines`, `x86StoreByteUpdate`/`x86StoreByteUpdateSpec`,
`x86_store_byte_update_refines`, `x86_store_bytes_above_width_unchanged`) — so
the *new* obligation is exactly the one asymmetry the register form could not
have: a condition decoded from a different AUX byte composed onto the register
form's condition table.

Target C path (read-only reference):

- `kprog/x86/x86_sim_local_bpf.h:1526-1543` — the macro form; the inlined
  dispatch at `1686-1691` is identical text:
  ```c
  __u8 __x86_l_cc = X86_REG_AUX_GET_SRC_SHIFT(AUX);
  __u64 __x86_l_value = X86_SIM_L_EVAL_CC(__x86_l_cc);
  __s64 __x86_l_disp = X86_SIM_L_MEM_OFFSET((AUX), x86_simm(IMM));
  void *__x86_l_base_ptr = (DST) == X86_REG_NONE ? (void *)0
                                                 : X86_SIM_L_READ_REG_PTR(DST);
  if ((DST) == X86_RSP) X86_SIM_L_STACK_WRITE(..., X86_WIDTH_8, value);
  else X86_SIM_L_STORE_ADDR((__u8 *)__x86_l_base_ptr + __x86_l_disp,
                            X86_WIDTH_8, value);
  ```
- Three asymmetries against `SETCC` (`0x16`) that this step exists to pin:
  1. The condition byte is the AUX **source-shift** byte at bits 24..31
     (`X86_REG_AUX_GET_SRC_SHIFT`, `x86_sim.h:151`), **not** the payload byte at
     bits 0..7 that `SETCC` reads. The same AUX word therefore names different
     conditions for the two opcodes.
  2. The displacement is the **whole artifact** (`x86_simm(IMM) = (__s64)IMM`,
     `x86_sim.h:265`), unlike `_MOV_STORE_IMM`'s high-half slice
     (`x86_store_imm_disp(v) = (__s32)(v >> 32)`, `:275`).
  3. The destination register number is also the memory base:
     `(DST) == X86_REG_NONE` forms a **null base pointer** *before* the
     `X86_RSP` arm test, so the null base always takes the memory arm with
     process null as the base. `SETCC` has no analogue.
  The width is the opcode's constant `X86_WIDTH_8` — neither a FLAGS code nor
  the AUX `X86_MEM_AUX_MEM_WIDTH` byte can move it.

## Changes

- New `kprog/formal/generate_x86_setcc_mem_spec.py` (58th generator),
  emitting `x86_setcc_mem_spec.json`, `KProgFormal/GeneratedX86SetccMem.lean`
  and `generated/x86_setcc_mem.h`:
  - Lean: `conditionCode (aux : BitVec 32) := (aux >>> 24).setWidth 8`,
    `condOf aux := GeneratedX86Setcc.condOf (conditionCode aux)`, `evalRaw`
    composing it onto `GeneratedX86Setcc.evalCond`, `noneReg`/`rspReg` and the
    two equality tests, the `Base`/`Arm` tables over the decoded `Bool`
    predicates, and `width := .w8`.
  - C: `_Static_assert` drift checks against `X86_REG_NONE`/`X86_RSP`/
    `X86_WIDTH_8`/`X86_OP_SETCC_MEM`, `KPROG_X86_SETCC_MEM_CONDITION(AUX)`
    (the `>> 24` decode), the base and arm statement-expression selectors, and
    the constant width code. Defines no `X86_WIDTH_*` and includes nothing, so
    the oracle declares those itself.
- New `kprog/formal/KProgFormal/X86SetccMemHandler.lean`:
  - `abbrev X86SetccMemEffect := X86StoreEffect` — the two handlers have the
    same five fields, so the store's byte-update lemmas apply unchanged.
  - Three `rfl` refinements bridging the raw register-number tests to the
    generated predicates (`x86_setcc_mem_is_none_refines`,
    `…_is_rsp_refines`, `…_condition_code_refines`), plus
    `…_base_refines`, `…_arm_refines`, `…_base_ptr_refines`, `…_width_refines`.
  - `x86_setcc_mem_raw_cond_sound` / `…_raw_unsupported` lifting the shared
    expression table through the new decode, and `x86_setcc_mem_value_refines`.
  - `x86_setcc_mem_step_fields_refines`, `…_bytes_refines`,
    `…_step_refines` (13-argument independent spec) and
    `…_step_aux_refines` (the packed-AUX form the dispatch has).
  - Asymmetry theorems: `x86_setcc_mem_condition_source_differs` (bits 24..31
    vs. 0..7), `x86_setcc_mem_disp_differs_from_imm_store` (whole artifact vs.
    high-half slice), `x86_setcc_mem_width_ignores_inputs` /
    `x86_setcc_mem_both_arms_use_one_width` (constant width under a nonzero AUX
    memory-width byte and a nonzero FLAGS code),
    `x86_setcc_mem_null_base_ignores_dst` (the null base always takes the
    memory arm), `x86_setcc_mem_arm_stack_iff`,
    `x86_setcc_mem_step_writes_one_byte`, and seven `native_decide` examples.
  No `sorry` or `admit`.
- New `kprog/formal/test_x86_setcc_mem_host.c` — the independent oracle.
  - Part 1 sweeps the whole 256-value source-shift byte space through the
    generated decoder into the real `KPROG_X86_EVAL_CC`, over all 16 raw flag
    nibbles, against a restated 14-arm expression table, with every unsupported
    code pinned to 0.
  - Part 2/3 sweep all 256 register numbers through the generated base table
    and both truth values through the arm table.
  - Part 4 drives the whole handler over a deterministic register/memory/stack
    model (16 dst × 256 conditions × 16 flag nibbles × 2 address modes × 2
    memory-width bytes × 4 immediates = 1,048,576 cases plus the smaller
    sweeps), comparing arm, width, value, address and every byte of both the
    memory and the stack buffer.
  - Part 5 pins the asymmetries: the source-shift decode (vs. the register
    form's payload byte), the whole-artifact displacement, the constant width
    under a nonzero memory-width byte and a 64-bit FLAGS code, the null-base
    memory arm, the unsupported parity codes 10/11, and the scaled-index
    offset on both arms.
  **1,053,191 cases**, zero non-macro `-Wall -Wextra` warnings.
- Wiring: `import KProgFormal.GeneratedX86SetccMem` and `import
  KProgFormal.X86SetccMemHandler` in `kprog/formal/KProgFormal.lean`
  (60-61); Makefile `--check` line after the setcc generator (62) and the
  Lean+oracle triple after the setcc triple (171-174); README paragraph after
  the `SETCC` paragraph plus the extended binding list; `docs/shared/implementation.md`
  open-surface paragraph extended with the `SETCC_MEM` composition.

## Design notes

- **The new obligation is the source-shift decode, and that is what the
  generator asserts.** `GeneratedX86SetccMem` deliberately does *not* re-emit
  the `condOf`/`evalCond` two-table split; it imports `GeneratedX86Setcc` and
  composes `conditionCode` onto it. Because the two opcodes share one table but
  read different bytes, the counterexample pin
  (`x86_setcc_mem_condition_source_differs`) is real content: it exhibits one
  AUX word whose two byte fields name two different conditions.
- **The base and arm tables are stated over decoded `Bool` predicates.** The
  handler module supplies the three `rfl` refinements from the raw register
  tests, which keeps the generated `base`/`arm` functions free of register
  numbers and makes the null-base pin (`x86_setcc_mem_null_base_ignores_dst`)
  expressible without unfolding a comparison.
- **The width is modeled as a function of the inputs it could have consulted.**
  `x86SetccMemWidthSpec (_aux) (_flags) := .w8` takes both, so the came-head
  deriver can instantiate or specialize it freely, and
  `x86_setcc_mem_width_ignores_inputs` pins that a nonzero
  `X86_MEM_AUX_MEM_WIDTH` byte (`0x00400000`) *and* a nonzero FLAGS code both
  leave it at `.w8`. `generatedX86SetccMemWidth` is an alias for
  `GeneratedX86SetccMem.width` — a `def`, not an `abbrev`, so
  `simp only [x86_setcc_mem_width_refines, x86SetccMemWidthSpec]` can unfold it.
- **The step relation is stated over the store's effect structure.** Because
  `X86SetccMemEffect` is an `abbrev` for `X86StoreEffect`, the proof of the
  5-conjunction uses `X86StoreEffect.mk.injEq` to turn the structure equality
  into its projections, and the byte component is discharged by the store's own
  `x86_store_byte_update_refines` at `.w8`. No new memory-write lemma was
  needed.
- **The conformance obligation is split deliberately.** The raw-byte→condition
  sweep is done exhaustively in C against the real `KPROG_X86_EVAL_CC` (oracle
  parts 1 and 5); the expression table and the unsupported default are proved
  in Lean.
- **The generated contract is not wired into the live sim** — `x86_setcc_mem.h`
  joins the `used=0` set of proof-only generated headers. Wiring
  `X86_SIM_L_EXEC_SETCC_MEM` is a separate, riskier edit; same decision as the
  previous six increments.

## Verification

- `lake build` then `lake env lean KProgFormal/X86SetccMemHandler.lean`:
  passes, 0 `error:` lines, 0 `sorry`.
- `python3 generate_x86_setcc_mem_spec.py && python3
  generate_x86_setcc_mem_spec.py --check`: passes (`IDEMPOTENT`).
- Standalone oracle: `cc -Wall -Wextra -O2 -I. test_x86_setcc_mem_host.c
  -o build/test_x86_setcc_mem_host && ./build/test_x86_setcc_mem_host`
  → `x86 setcc_mem handler host cross-check: OK (1053191 cases)`.
- **Non-vacuity probes.** Nine mutations of the real generated header each make
  the oracle exit 1: the `>> 24` decode changed to `>> 16`; the
  `BASE_NULL`/`BASE_REGISTER` codes swapped; `BASE_REGISTER` set to 0; the
  `ARM_STACK`/`ARM_MEMORY` codes swapped; the base selector's `==` inverted;
  the arm selector's `if` inverted; and each of `WIDTH_CODE 1U→8U`,
  `NONE_REG 0xffU→0xfeU`, `RSP_REG 4U→5U` (the last three trip the generated
  `_Static_assert` drift checks). Separately, mutating the opcode in
  `x86_setcc_mem_spec.json` from `0x3e` to `0x3f` makes `--check` exit 1.
- Full `make -C kprog/formal check`: RC=0, 0 `error:` lines, **58
  generators / 105 Lean module checks / 48 host cross-checks over 3,819,598
  cases**.
- Commit `33acdf189` (code increment, 9 files).

## Open after this step

`X86_OP_CMOV`/`X86_OP_CMOV_MEM` (`0x15`/`0x40`) have their full bodies read and
share the pieces this step composed: `CMOV` reads the **whole AUX word** as the
condition (`X86_SIM_L_EVAL_CC(AUX)`, not a byte field) and at `w64` preserves
the **source's pointer tag** through `X86_SIM_L_WRITE_REG_PTR_TAG`, which is the
asymmetry against `SETCC`'s unconditional scalarization; `CMOV_MEM` reads the
source-shift byte *and* has a two-level width fallback
(`X86_MEM_AUX_MEM_WIDTH(AUX) ?: effective(FLAGS)`) with `STORE_DISP = 1`, so it
takes the high-half displacement slice. `_MOVBE_LOAD`/`_MOVBE_STORE`,
`_MOV_LOAD_MAP_PTR`, then the rest of the x86 surface (`_STORE_XMM0`/
`_LOAD_XMM0`, `_CALL_MEMCPY_{,REG}`/`_CALL_MEMSET_{,REG}`, `_PUSH`/`_POP`,
`_REP_MOVS`, `_ANDN{,_MEM}`, `_BZHI{,_MEM}`, `_CMP_IMM_OP`/`_CMP_REG_OP`), the
index register decode and packed-AUX layout, the
simulator-stack-to-abstract-frame-base mapping, compiler/native bytes,
multi-step traces, and specialization preservation remain open.
