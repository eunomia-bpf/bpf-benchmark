# Step 0026 — x86 memory-source shift/rotate handler composition

Date: 2026-09-26 UTC

## Scope

Close the x86 memory-operand *shift* handler item on the open proof surface by
composing the flagless BMI2 memory-source forms `SHLX/SHRX/SARX dst, [mem],
count` and `RORX dst, [mem], imm8`.

Target C paths (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_SHIFTX_MEM` (line 1714)
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_RORX_MEM` (line 1729)

## Changes

- New `native-sim/formal/KProgFormal/X86MemShiftHandler.lean`:
  - `inductive X86MemShiftOp | shl | shr | sar`.
  - `generatedX86MemShiftStep` / `x86MemShiftStepSpec` and
    `x86_mem_shift_step_refines`: byte load -> width-local shift result ->
    width-confined register writeback, composing `x86_mem_load_refines`,
    `x86_{shl,shr,sar}_result_refines`, and `x86_reg_write_refines`.
  - `x86_mem_shift_preserves_flags`: BMI2 shifts leave CF/ZF/SF/OF untouched —
    the handler replaces only the destination register.
  - `generatedX86MemRorxStep` / `x86MemRorxStepSpec` and
    `x86_mem_rorx_step_refines` (rotate through the complementary-count
    rotate-left contract `x86_ror_result_refines`), plus
    `x86_mem_rorx_preserves_flags`.
  - Three concrete examples proved by `native_decide` (32-bit SHLX,
    8-bit SARX sign-fill, 8-bit RORX). No `sorry` or `admit`.
- New `native-sim/formal/test_x86_mem_shift_handler_host.c`: independent
  byte-loop oracle against the real generated macros
  (`KPROG_X86_MEM_LOAD`, `kprog_x86_{shl,shr,sar,ror}_result`, and the
  `KPROG_X86_WRITE_REG*` writeback), 4 ops x 4 widths x 8 x 8 boundary cases
  plus 20000 fixed-seed random cases.
- Wiring: `KProgFormal.lean` import; `Makefile` check-target block;
  `README.md` memory-source shift paragraph and TCB binding sentence;
  `docs/implementation.md` open-surface bullet narrowed to
  bit/compare/multiply memory handlers.

## Verification

- `lake env lean KProgFormal/X86MemShiftHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_mem_shift_handler_host.c ... &&
  ./build/test_x86_mem_shift_handler_host` —
  `x86 memory-shift host cross-check: OK (21024 cases)`.
- Full `make -C native-sim/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-new.log`, 115 build steps, ends at
  `lake env lean KProgFormal/Arm64Decode.lean`.

## Modeling notes

- The op byte packed into `IMM` selects SHL/SHR/SAR via
  `X86_ALU_{SHL,SHR,SAR}`; those bodies write only the destination and never
  call `X86_SIM_L_SET_SHIFT_FLAGS`, so threading `flags := state.flags`
  unchanged is architecturally faithful and is itself a proved theorem.
- The independent oracle initially modeled the 32-bit writeback as a 4-byte
  merge; the generated contract zero-extends into the 64-bit register. The
  oracle was corrected (the generated side is the shared artifact).
- 8-bit register writeback scalarizes the tag, observed via `#eval` on the leaf
  modules and reflected in the SARX example expectation.

## Remaining open x86 surface

Bit (`BT_MEM_IMM` / `BZHI_MEM`), compare (`X86_SIM_L_EXEC_CMP_MEM`,
`X86_SIM_L_EXEC_CMP_REG_MEM`), and multiply (`X86_SIM_L_EXEC_IMUL_MEM_IMM`)
memory-operand handler composition; then effective-address/address-space and
immediate/register-RHS selection, objdump/parser-to-AUX selection relation,
C-to-Lean unsigned-semantics correspondence, compiler/native-byte
correspondence, multi-step control-flow traces, specialization preservation.
