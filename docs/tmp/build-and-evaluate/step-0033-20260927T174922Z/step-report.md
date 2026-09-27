# Step 0033 — x86 register-writing `MOV` handler composition

Date: 2026-09-27 UTC

## Scope

Close the register-writing half of the `MOV` matrix on the open x86 proof
surface: `X86_SIM_L_EXEC_MOV_IMM` (`mov r, imm`, imm32/imm64) with its `_AUX`
form, and `X86_SIM_L_EXEC_MOV_REG` (`mov r, r`) with its `_AUX` form. These are
the two most-emitted x86 dispatches in the workload-derived instruction subsets.
The memory-touching half (`_MOV_LOAD`, `_MOVX_REG`, `_MOVBE_*`) stays open
because it still needs the memory load/store models, not a new register
contract.

Target C path (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h`
  `X86_SIM_L_EXEC_MOV_IMM_AUX` / `X86_SIM_L_EXEC_MOV_IMM` (1399-1408),
  `X86_SIM_L_EXEC_MOV_REG_AUX` / `X86_SIM_L_EXEC_MOV_REG` (1410-1432).
- Dispatch `X86_OP_MOV_IMM` / `X86_OP_MOV_REG` in `X86_SIM_L_EXEC`
  (1583-1601), whose inline forms are textually identical to the macros.

## Changes

- New `native-sim/formal/KProgFormal/X86MovHandler.lean` (236 lines):
  - `structure X86MovState {dst : X86RegValue}` — MOV defines no flags, so the
    state carries only the destination register, matching the C handlers
    verbatim.
  - `structure X86MovSrc {bits, tag, isRsp}` — no `isNone` field: the live
    `MOV_REG` handler never tests `SRC == X86_REG_NONE`, and the generator only
    emits `X86_OP_MOV_REG` for register-register `mov` where both operands are
    real registers (`generate_micro_sim_proofs.py:566-570`).
  - `generatedX86MovPointerWrite` / `x86MovPointerWriteSpec` /
    `x86_mov_pointer_write_refines`: the 64-bit write path over
    `GeneratedPtrAdd.bits`/`.tag` with a zero right-hand side, i.e. the LEA
    pointer-write shape.
  - `generatedX86MovImmStep` / `x86MovImmStepSpec` / `x86_mov_imm_step_refines`:
    the immediate handler over `GeneratedX86RegWrite.writeAt` (destination width
    and explicit byte lane). No sign extension or truncation before the write, so
    `mov r64, imm` and `mov ah, imm8` are the same contract with a different lane.
  - `x86_mov_imm_low_lane_is_plain`: the non-`AUX` zero-aux form degenerates to
    the plain partial-register writeback with no byte selection.
  - `generatedX86MovRegStep` / `x86MovRegStepSpec` / `x86_mov_reg_step_refines`:
    the register-source handler — w64 stack-pointer arm through the abstract
    frame base tagged `.stack`, w64 general arm copying bits and provenance, and
    the narrow arm reading the source through its decoded lane and writing
    through the destination lane.
  - `x86_mov_reg_copies_provenance`, `x86_mov_reg_rsp_uses_stack_base`,
    `x86_mov_reg_narrow_ignores_rsp`, `x86_mov_reg_narrow_scalarizes`: the four
    structural consequences, including that every narrow `mov` scalarizes.
  - Five `native_decide` examples (`0x4000`, `0x112233445566aa88`, `0x7000`,
    `0x1234`, `0xffffffffffffffaa`), each re-derived with an independent Python
    simulation of the read/write/lane model before the commit. No `sorry` or
    `admit`.
- New `native-sim/formal/test_x86_mov_handler_host.c` (320 lines): independent
  oracle. One part checks the MOV-immediate composition against an explicit
  lane-selecting partial-writeback model; the other checks the MOV-register
  composition — RSP arm, general pointer arm, narrow arm with both decoded lanes
  — against an independent lane-read and writeback model. Boundary vectors plus
  a fixed-seed LCG sweep: **100,448 cases**, zero warnings.
- Wiring: `KProgFormal.lean` import (1 line after `X86LeaHandler`); `Makefile`
  (Lean-module + oracle block after the step-0032 `./build/test_x86_lea_handler_host`
  line, before `Arm64Flags.lean`); `README.md` register-writing MOV paragraph
  plus the TCB binding sentence; `docs/implementation.md` open-surface bullet.

## Verification

- `lake build` — `Build completed successfully`.
- `lake env lean KProgFormal/X86MovHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_mov_handler_host.c ... &&
  ./build/test_x86_mov_handler_host` — zero warnings,
  `x86 MOV host cross-check: OK (100448 cases)`.
- Full `make -C native-sim/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-mov.log`, 160 s, **42** host cross-checks
  (was 41), **53** generator `--check` runs, 94 Lean module checks (was 93),
  1,975,148 oracle cases (was 1,874,700), all green.

## Modeling notes

- **No new generated contract.** `MOV_IMM` and `MOV_REG` are fully expressible
  over the existing contracts: `GeneratedX86RegWrite.writeAt` (destination width
  + explicit byte lane), `GeneratedX86RegRead.readAt` (source width + lane),
  and `GeneratedPtrAdd.bits`/`.tag` (pointer writeback). The `_AUX` forms reuse
  `GeneratedX86RegLaneAux.pack`/`dstShift`/`srcShift` at the oracle level, which
  the sim's own `KPROG_X86_REG_LANE_AUX_*` decoders already bind.
- **The w64 arms reuse the LEA pointer-write shape with RHS 0** rather than
  importing `X86LeaHandler`'s `X86LeaState`. MOV's state has no flags either,
  but a local `X86MovState`/`X86MovSrc` avoids cross-module coupling and mirrors
  how `X86ImulRegImmHandler` declares its own composition over
  `X86RegAluState`.
- **The narrow arm scalarizes through the writeback, not by construction.** The
  theorem threads through `x86RegWriteAtSpec`, whose tag is always
  `Tag.scalar`; `x86_mov_reg_narrow_scalarizes` exposes that consequence without
  re-deriving the write. `KPROG_X86_WRITE_REG32` writes
  `(void *)(long)(__u32)(VALUE)`, which is why the w32 example zeroes the upper
  half in the 64-bit `bits` view via `.ptr`/`.q` union aliasing — reproduced by
  the oracle's `union reg_storage`.
- **The offset contract was not touched.** `MOV` does not form an
  effective address; the base-plus-scaled-index term proved in step 0032 remains
  the shared input for the memory-touching `MOV_LOAD`/`STORE` family still open.
- **The oracle's first draft warned on an unused `old_tag`** in
  `oracle_mov_imm` (the independent immediate model derives the tag from the
  writeback, not from the input). Fixed with a `(void)old_tag;` cast, matching
  the `test_x86_lea_handler_host.c` `oracle_lea` precedent. `(__u64)(long)`
  casts around every `KPROG_PTR_ADD64_BITS` result avoid
  `-Wint-conversion`-class warnings.

## Remaining open x86 surface

Still open on x86: the memory-touching `MOV` forms (`_MOV_LOAD`, `_MOVX_REG`,
`_MOVBE_LOAD`/`_MOVBE_STORE`), `_CMOV`/`_CMOV_MEM`, `_SETCC`/`_SETCC_MEM`,
`_STORE`/`_STORE_XMM`/`_LOAD_XMM`, `_CALL_MEMCPY{,_REG}`/`_CALL_MEMSET{,_REG}`,
`_PUSH`/`_POP`, `_REP_MOVS`, `_ANDN{,_MEM}`, `_BZHI{,_MEM}`,
`_CMP_IMM_OP`/`_CMP_REG_OP` and the `_AUX` variants; plus the index register
decode and packed-AUX layout, the mapping from the simulator's stack region to
the abstract frame base, the objdump/parser-to-AUX selection relation, C-to-Lean
unsigned-semantics correspondence, compiler/native-byte correspondence,
multi-step control-flow traces, and specialization preservation.

## Commit

`21f6aae0f` — code increment, 6 files, pushed to `origin/master`. Step report
and research log: `650e28d1e`. Both commits pushed in one push
(`0bb45cc7d..650e28d1e`).

## Evidence pair regeneration

The retained receipt and log were regenerated at `650e28d1e`
(`make -C native-sim/formal check`, exit 0): 53 generator `--check` runs, 94
Lean module checks, 42 host cross-checks over 1,975,148 oracle cases; log bytes
14583, sha256
`126c2c2f4b6db2e14ce472246d9d2992784e017ae111759e1bf9c142671750940`.

`render_claim_table.formal_evidence(Path('.'))` returns `PASS` (receipt counts
agree with both the retained log and the `native-sim/formal/Makefile` at this
commit, receipt commit equals the log commit, log hash valid). Evidence refresh
committed and pushed as `03b685164` (4 files: receipt, log, AE guide paragraph,
CHANGELOG).

## Archival ZIP

`docs/artifacts/package-atc26.sh` rebuilt `docs/artifacts/dist/atc26-ae-2.zip`
at `03b685164`: sha256
`d1c27e80b249d66a3191dda46cb2f86e4dfb126c1e61d69a55e47181f625d333`,
933,784,490 bytes, `ARTIFACT_MANIFEST.json.superprojectCommit` =
`03b68516456cb488f8a053cc89651a6ebd4acc4f` (matches HEAD), `self-test: OK
(13 evidence classes)`, `clean-extraction verification OK`. The ZIP is
untracked by design; its publication to Zenodo stays blocked on a credential.
