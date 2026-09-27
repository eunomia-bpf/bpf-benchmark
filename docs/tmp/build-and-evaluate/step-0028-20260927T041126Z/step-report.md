# Step 0028 — x86 memory-source multiply handler composition

Date: 2026-09-27 UTC

## Scope

Close the x86 memory-operand *multiply* handler item on the open proof surface
by composing the legacy `IMUL reg, [mem], imm` handler.

Target C path (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_IMUL_MEM_IMM` (line 1178)

## Changes

- New `native-sim/formal/KProgFormal/X86MemImulHandler.lean`:
  - `generatedX86MemImulStep` / `x86MemImulStepSpec` and
    `x86_mem_imul_step_refines`: byte load at the memory operand's width ->
    arithmetic-immediate rule at the destination width -> sign extension of both
    operands -> signed product -> generated IMUL flag construction ->
    width-confined register writeback, composing `x86_mem_load_refines`,
    `x86_immediate_value_refines`, `x86_sign_extend_refines`,
    `x86_imul_flags_apply_refines`, and `x86_reg_write_refines` in a single
    `simp only` under the two record constructors.
  - `x86_mem_imul_preserves_zf_sf` / `x86_mem_imul_cf_eq_of`: IMUL leaves ZF/SF
    untouched and defines CF/OF as the same value.
  - `x86_mem_imul_tag_scalar`: the destination's tag is scalarized.
  - `x86_mem_imul_bytes_congruent`: the load reads only the bytes the memory
    operand's width covers.
  - `x86_mem_imul_rhs_narrow_reads_low_bits` (`bv_decide`): the
    immediate-sign-extension step depends only on the raw immediate's low bits.
  - Four concrete `native_decide` examples: a 16-bit overflow, an 8-bit memory
    read sign-extended into a 64-bit multiply, an 8-bit mixed-sign overflow, and
    an 8-bit in-range product. No `sorry` or `admit`.
- New `native-sim/formal/test_x86_mem_imul_handler_host.c`: independent oracle
  against the real generated macros (`KPROG_X86_MEM_LOAD`,
  `KPROG_X86_IMMEDIATE_VALUE`, `kprog_x86_sign_extend_value`,
  `KPROG_X86_SET_IMUL_FLAGS` with `kprog_x86_abs_width_value`, and
  `KPROG_X86_WRITE_REG*`). 4 destination widths x 4 memory widths x 14 x 14
  boundary vectors plus 40000 fixed-seed LCG cases.
- Wiring: `KProgFormal.lean` import; `Makefile` check-target block;
  `README.md` memory-source multiply paragraph, TCB binding sentence, and the
  three stale "compare/multiply memory handlers" tails narrowed to compare;
  `docs/implementation.md` open-surface bullet narrowed to the register-source
  multiply handler.

## Verification

- `lake env lean KProgFormal/X86MemImulHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_mem_imul_handler_host.c ... &&
  ./build/test_x86_mem_imul_handler_host` — zero warnings,
  `x86 memory-imul host cross-check: OK (43136 cases)`.
- Full `make -C native-sim/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-imul.log`, 120.94 s, 37 host cross-checks,
  ends at `lake env lean KProgFormal/Arm64Decode.lean`.

## Modeling notes

- `memWidth` is an explicit parameter of the step and its spec, modelling the
  `X86_MEM_AUX_MEM_WIDTH(AUX)` value *after* the `if (!memWidth) memWidth =
  width` default resolution. That default is an auxiliary-decode concern shared
  with the other memory-source handlers, not part of this bounded step.
- The result sign-extends the *memory* operand from `memWidth` before the
  multiply (the register-source handler does not), which is what makes a narrow
  memory read signed. The flags receive the un-extended loaded value and the
  width-extended immediate, in the C handler's own order, so
  `x86_imul_flags_apply_refines` applies verbatim.
- The host oracle decides CF/OF from whether the 128-bit mathematical signed
  product fits the destination's signed width, deliberately *not* from the
  generated abs-value division; that is the independent axis for the flag half
  of the contract. Modelling the signed operand in the 128-bit domain required
  extending through a 64-bit signed cast (`(__int128)(__s64)`) — a plain
  `(__int128)` cast of a sign-filled `__u64` is *positive*, and the first oracle
  run failed exactly there (11,198 flag mismatches, destination always equal).
  The generated side was correct throughout; the oracle was fixed, not the
  generated macro.
- The host oracle models the architectural 32-bit zero-extension of
  `KPROG_X86_WRITE_REG32` (upper half cleared, not merged).

## Remaining open x86 surface

Register-source multiply handler composition (`X86_SIM_L_EXEC_IMUL_REG_*`); then
the compare memory handlers (`X86_SIM_L_EXEC_CMP_MEM`,
`X86_SIM_L_EXEC_CMP_REG_MEM`), effective-address/address-space and
immediate/register-RHS selection, objdump/parser-to-AUX selection relation,
C-to-Lean unsigned-semantics correspondence, compiler/native-byte
correspondence, multi-step control-flow traces, specialization preservation.
