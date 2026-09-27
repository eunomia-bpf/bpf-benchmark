# Step 0034 — x86 width-converting register `MOV` (`MOVZX`/`MOVSX`/`cdqe`) handler composition

Date: 2026-09-27 UTC

## Scope

Close the width-converting register-source half of the `MOV` matrix on the open
x86 proof surface: `X86_SIM_L_EXEC_MOVX_REG`, the single body shared by
`X86_OP_MOVZX_REG` and `X86_OP_MOVSX_REG` (and therefore by the bare `cdqe` and
by `movsxd`, which the generator encodes as `X86_OP_MOVSX_REG` with a 32-bit
source width). This is the one remaining `MOV`-class form with **no memory
model at all**: it composes exactly two already-proved contracts — the
narrowing/sign-extension value contract and the partial-register writeback — so
it needs no new generated spec, unlike the memory-touching `MOV` forms that
remain open.

Target C path (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h`
  `X86_SIM_L_EXEC_MOVX_REG(OP, DST, SRC, FLAGS, AUX)` (1434-1444) and its
  inline `X86_SIM_L_EXEC` arm (1607-1615), whose bodies are textually
  identical.
- `x86_apply_width` (`x86_sim.h:180-183`) delegating to `KPROG_X86_APPLY_WIDTH`
  (`generated/x86_width.h`), and `x86_sign_extend` (`x86_sim.h:185-188`)
  delegating to `kprog_x86_sign_extend_value` (`generated/x86_signed.h`).
- `X86_SIM_L_WRITE_REG_WIDTH` (374-406): `FLAGS` resolves with a 64-bit
  fallback and the write always uses lane shift 0.

Generator encoding: `native-sim/x86/micro-prog/generate_micro_sim_proofs.py`
615-638 — `movzx`/`movsx`/`movsxd` emit `X86_OP_MOVSX_REG`/`X86_OP_MOVZX_REG`
with `flags = WIDTH_CONST[destination width]` and `aux = WIDTH_CONST[source
width]` when the source operand is a register; `cdqe` emits
`X86_OP_MOVSX_REG RAX,RAX,flags=X86_WIDTH_64,aux=X86_WIDTH_32`.

## Changes

- New `native-sim/formal/KProgFormal/X86MovxRegHandler.lean`:
  - `structure X86MovxState {dst : X86RegValue}` — MOVZX/MOVSX define no flags,
    so the state carries only the destination register.
  - `inductive X86MovxOp | movzx | movsx` — the two opcodes the shared body
    implements.
  - `generatedX86MovxRegStep` / `x86MovxRegStepSpec` /
    `x86_movx_reg_step_refines`: the composition reads the source register's
    raw 64-bit value (no byte lane), narrows it (`GeneratedX86Width.narrow`) or
    sign-extends it (`GeneratedX86Signed.signExtend`) at the *source* width,
    then writes it back through `generatedX86RegWrite` at the *destination*
    width. Proved by `cases op <;> simp only [... x86_narrow_refines,
    x86_sign_extend_refines, x86_reg_write_refines]`.
  - `x86_movzx_is_narrow` / `x86_movsx_is_sign_extend`: the two opcode arms are
    exactly the corresponding value contract followed by the writeback.
  - `x86_cdqe_is_movsx_w32_w64`: `cdqe` is the 32-bit-source, 64-bit-destination
    instance, so the whole register receives the sign extension and the
    provenance scalarizes.
  - `x86_movzx_same_width_idempotent`: narrowing is idempotent, so a MOVZX whose
    two widths coincide is not a silent double truncation.
  - `x86_movzx_ignores_upper_source_bits`: two source values with the same
    narrowed lane produce the same destination.
  - `x86_movx_reg_tag_scalar`: every writeback scalarizes.
  - `x86_movx_reg_narrow_preserves_upper`: a sub-64-bit destination width
    preserves the destination's bytes above that width.
  - Six `native_decide` examples (`cdqe` of `0x1122334480000001`, positive
    `movsxd` of `0x7fffffff`, `movzx r32,r8` of `0xff`, `movsx r32,r8` of
    `0x80`, same-width `movzx r16,r16`), each re-derived with an independent
    Python simulation before the commit. No `sorry` or `admit`.
- New `native-sim/formal/test_x86_movx_reg_host.c`: independent oracle. The
  generated side calls `KPROG_X86_APPLY_WIDTH` / `kprog_x86_sign_extend_value`
  and the `KPROG_X86_WRITE_REG*` macros exactly as the C handler orders them
  (`FLAGS` fallback, then `AUX` fallback, then the raw 64-bit source); the
  oracle side restates the widening with explicit sign-bit arithmetic and the
  writeback by mask-and-merge. Boundary grid over all 25
  `(flags, aux)` width-code pairs × 12 sources × 4 destinations × 2 opcodes,
  plus a `cdqe`-decoding block, an LCG sweep, and a `movsxd`-identity block:
  **62,409 cases**, zero warnings under `-Wall -Wextra -O2`.
- Wiring: `KProgFormal.lean` import (1 line after `X86MovHandler`);
  `Makefile` Lean-module + oracle block after the step-0033
  `./build/test_x86_mov_handler_host` line, before `Arm64Flags.lean`; `README.md`
  width-converting MOV paragraph plus the TCB binding sentence;
  `docs/implementation.md` open-surface bullet.

## Verification

- `lake build` — `Build completed successfully`.
- `lake env lean KProgFormal/X86MovxRegHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_movx_reg_host.c ... &&
  ./build/test_x86_movx_reg_host` — zero warnings,
  `x86 movx reg host cross-check: OK (62409 cases)`.
- Full `make -C native-sim/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-movx.log`, 155 s, **53** generator `--check`
  runs (unchanged), **95** Lean module checks (was 94), **43** host cross-checks
  (was 42), **2,037,557** oracle cases (was 1,975,148), all green. The deltas
  are exactly the one new Lean module, one new oracle, and that oracle's 62,409
  cases.

## Modeling notes

- **No new generated contract.** `KPROG_X86_APPLY_WIDTH` (`GeneratedX86Width.mask`,
  an AND with the width's bit mask) and `GeneratedX86Signed.signExtend` are both
  already generated and already proved (`x86_narrow_refines`,
  `x86_sign_extend_refines`), so the generator count stays 53. This is the first
  proof in the tree to compose *both* value contracts inside one handler and the
  first to carry a source width distinct from the destination width — the
  two-width pattern the memory-load family will reuse.
- **No byte lane anywhere in MOVX.** Unlike `X86_SIM_L_EXEC_MOV_REG`, which
  takes a packed lane-aux and reads the source through its decoded lane, the
  MOVX body calls `X86_SIM_L_READ_REG(SRC)` for the whole 64-bit register and
  `X86_SIM_L_WRITE_REG_WIDTH` with lane shift 0. The `AUX` argument is a *width
  code*, not a lane aux. A `grep` over the whole
  `native-sim/x86/micro-prog/*.bpf.c` corpus (252 `movzx|movsx|movsxd|cdqe`
  occurrences) finds no high-byte (`%ah`) MOVX source, so the register-source
  form needs no byte-lane handling.
- **`FLAGS` fallback and `AUX` fallback are outside the theorem.** The C body
  resolves `width = FLAGS ? FLAGS : X86_WIDTH_64` and
  `srcWidth = AUX ? AUX : width`; the Lean step takes both widths already
  resolved, with the resolution recorded in the oracle. The register decode
  that supplies the source value and the width-code selection relation likewise
  stay outside.
- **The `cdqe`/`movsxd` identity is a consequence, not an assumption.** The
  generator recognises bare `cdqe` by opcode, not by operand shape; the theorem
  shows the resulting body is exactly the `movsx .w32 .w64` instance, and the
  oracle additionally checks that a `movsxd`-shaped extension is the identity on
  values that are already sign-extended 32-bit quantities.
- **The memory family is next.** `X86_SIM_L_READ_MEM_VALUE` (638-667) is the
  shared load path for `_MOVBE_LOAD`, `_SHIFTX_MEM`, `_RORX_MEM`, `_BZHI_MEM`,
  and `_ANDN_MEM`; it has no existing contract and will need one new generated
  spec (generator count 53 → 54), which is why it is a separate increment.

## Remaining open x86 surface

Still open on x86: the memory-touching `MOV` forms (`_MOV_LOAD`,
`_MOVSX_LOAD`, `_MOV_LOAD_SCALAR`, `_MOV_LOAD_MAP_PTR`, `_MOVBE_LOAD`/
`_MOVBE_STORE`, `_MOV_STORE_IMM`/`_MOV_STORE_REG`), `_CMOV`/`_CMOV_MEM`,
`_SETCC`/`_SETCC_MEM`, `_STORE_XMM0`/`_LOAD_XMM0`,
`_CALL_MEMCPY{,_REG}`/`_CALL_MEMSET{,_REG}`, `_PUSH`/`_POP`, `_REP_MOVS`,
`_ANDN{,_MEM}`, `_BZHI{,_MEM}`, `_CMP_IMM_OP`/`_CMP_REG_OP` and the `_AUX`
variants; plus the index register decode and packed-AUX layout, the mapping from
the simulator's stack region to the abstract frame base, the objdump/parser-to-AUX
selection relation, C-to-Lean unsigned-semantics correspondence,
compiler/native-byte correspondence, multi-step control-flow traces, and
specialization preservation.

## Commit

`e861cf838` — code increment, 6 files, pushed to `origin/master`.
Step report and research log: pending.
