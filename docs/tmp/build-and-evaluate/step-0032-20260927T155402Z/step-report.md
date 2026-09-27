# Step 0032 — x86 effective-address offset + `LEA` handler composition

Date: 2026-09-27 UTC

## Scope

Close the effective-address item on the open x86 proof surface by proving the
`X86_SIM_L_EXEC_LEA` handler, together with the base-plus-scaled-index offset
that every remaining memory-source handler will need. `_MOV_LOAD`, `_STORE`,
`_CMP_MEM` and friends all share `X86_SIM_L_MEM_OFFSET`; proving it once, as a
generated contract, removes it from the boundary for all of them.

Target C path (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_MEM_OFFSET` (line 411).
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_LEA` (line 824),
  dispatched for `X86_OP_LEA` (0x23) at line 1454.

## Changes

- New generated contract:
  - `native-sim/formal/x86_mem_offset_spec.json` —
    `{"schema_version":1,"operation":"x86MemOffset","base":"disp",
    "indexed":"disp_plus_index_scaled","scale":"shift_log2",
    "accumulate":"wrapping64"}`.
  - `native-sim/formal/generate_x86_mem_offset_spec.py` (131 lines) — mirrors
    `generate_ptr_add_spec.py` (`load`/`render_lean`/`render_c`/`main --check`);
    an `EXPECTED` dict is validated by equality, so drift fails `--check`.
  - `native-sim/formal/KProgFormal/GeneratedX86MemOffset.lean` (17 lines) —
    `value hasIndex scale disp index` and `valueSpec`.
  - `native-sim/formal/generated/x86_mem_offset.h` (35 lines) —
    `KPROG_X86_MEM_OFFSET(AUX, DISP, INDEX_VALUE, HAS_INDEX)`.
- New `native-sim/formal/KProgFormal/X86MemOffset.lean` (60 lines):
  - `x86_mem_offset_refines` (`unfold value valueSpec; cases hasIndex <;>
    bv_decide`): the generated transition equals an independently written sum.
  - `x86_mem_offset_case_dispatch` (`⟨rfl, rfl⟩`), three
    `x86_mem_offset_scale_is_power_of_two` components (`bv_decide`), and
    `x86_mem_offset_plain_ignores_index` (`unfold value; bv_decide`).
  - Three `native_decide` examples (indexed → 12, indexed wrap →
    `0x8000000000000000`, plain → `0xfffffffffffffff8`), each re-derived with an
    independent Python simulation before the commit.
- New `native-sim/formal/KProgFormal/X86LeaHandler.lean` (204 lines):
  - `structure X86LeaState {dst : X86RegValue}` and
    `structure X86LeaSrc {bits, tag, isNone, isRsp}`.
  - `generatedX86LeaPointerWrite` / `x86LeaPointerWriteSpec` /
    `x86_lea_pointer_write_refines`, mirroring the
    `Arm64AluHandler.lean:88-100` pointer-write pair.
  - `generatedX86LeaStep` / `x86LeaStepSpec` / `x86_lea_step_refines`: one
    `unfold … ; cases width <;> cases src.isNone <;> cases isRodata <;>
    cases src.isRsp <;> simp only [...]` closing the structure equality for
    arbitrary state, source, immediate, rodata flag, width and
    effective-address terms.
  - `x86_lea_rodata_fast_path`, `x86_lea_rodata_needs_no_source`,
    `x86_lea_rsp_uses_stack_base`, `x86_lea_narrow_ignores_rsp`.
  - Four `native_decide` examples (rodata → `0x4000`, indexed → `0x1030`,
    stack → `0x7020`, w32 → `0x1010`), each re-derived with an independent
    Python simulation before the commit. No `sorry` or `admit`.
- New `native-sim/formal/test_x86_lea_handler_host.c` (372 lines): independent
  oracle. One part checks `KPROG_X86_MEM_OFFSET` against an `__int128`
  power-of-two multiply; the other checks the composed LEA step — RODATA fast
  path, stack path, general pointer path, narrow exits — against an explicit
  `stack_base + src_ptr + off` model and a partial-writeback model. Boundary
  vectors plus a fixed-seed LCG sweep: **61,440 cases**, zero warnings.
- Wiring: `KProgFormal.lean` imports (3 lines after `X86ImulRegImmHandler`);
  `Makefile` (`--check` line after the `generate_x86_reg_write_spec.py` line;
  Lean-module + oracle block after the IMUL block); `README.md`
  effective-address/LEA paragraph plus the TCB binding sentence;
  `docs/implementation.md` open-surface bullet.

## Verification

- `lake build` — `Build completed successfully`, zero warnings.
- `lake env lean KProgFormal/X86MemOffset.lean` and
  `lake env lean KProgFormal/X86LeaHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_lea_handler_host.c ... &&
  ./build/test_x86_lea_handler_host` — zero warnings,
  `x86 LEA host cross-check: OK (61440 cases)`.
- Full `make -C native-sim/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-lea.log`, 139 s, **41** host cross-checks
  (was 40), **53** generator `--check` runs (was 52), 93 Lean module checks
  (was 90), all oracle cases green.

## Modeling notes

- **The offset contract takes the raw scale byte; no `& 3` mask.** The C macro
  computes `(__s64)(index << scale)` and the Lean module computes
  `index <<< scale`; both reduce the shift amount modulo the word width, so
  they are bit-identical for every scale byte, which the `--check` grid
  confirms. The host oracle's own `offset_oracle` keeps a `& 63` only to make
  its explicit `1 << scale` well-defined for scale ≥ 64.
- **The macro is scoped to the decoder, not the register read.** The caller
  passes the already-read `INDEX_VALUE` (mirroring the arm64 contract), so no
  `X86_SIM_L_READ_REG` dependency leaks into `generated/`; the `HAS_INDEX`
  parameter carries the sim's `__x86_l_index != X86_REG_NONE` gate.
- **The `RODATA` fast path is a separate theorem, not a symbolic
  parameterization.** `_refines` is uniform (one `off`, the fast path an `if`
  arm); the fast-path equality is `x86_lea_rodata_fast_path`. `rawImm` doubles
  as the sign-extended displacement and the RODATA-written literal, which is
  sound because `x86_simm` is the identity on 64 bits (`x86_sim.h:265`).
- **The stack path needs an abstract frame base.** RSP is never initialized in
  this build (BSS zero ⇒ `__x86_rsp.ptr = NULL`) yet `X86_SIM_L_STACK_PTR(0) =
  &stack_mem.b[0] ≠ NULL`, so `generatedX86LeaStep` takes an abstract
  `stackBase` and adds the source value to it, tagging `.stack` to match
  `X86_SIM_L_STACK_PTR`/`X86_SIM_TAG_STACK`.
- **The five-oracle-case bug was in the oracle, not the model.** The first
  oracle draft's `generated_lea` computed the stack arm from `stack_base` alone
  (`KPROG_PTR_ADD64_BITS((void *)stack_base, off)`), omitting `src_ptr`, while
  the sim's `X86_SIM_L_STACK_PTR((__s64)__x86_l_src_ptr + __x86_l_off)` adds
  the raw RSP value to the offset before indexing. That produced 5,048
  mismatches, all on the 64-bit RSP arm and all short by exactly `src_ptr`. The
  fix sums the source pointer into the base on both sides; the generated macro
  and the Lean module were never touched.

## Remaining open x86 surface

The effective-address term is now proved once for the whole memory-source
family. Still open: the index register decode and packed-AUX layout, the
mapping from the simulator's stack region to the abstract frame base, the
`MOV` matrix (`_MOV_IMM`, `_MOV_REG`, `_MOV_LOAD`, `_MOVX_REG`,
`_MOV_IMM_AUX`, `_MOV_REG_AUX`), `_CMOV`/`_CMOV_MEM`,
`_SETCC`/`_SETCC_MEM`, `_STORE`/`_STORE_XMM`/`_LOAD_XMM`,
`_CALL_MEMCPY{,_REG}`/`_CALL_MEMSET{,_REG}`, `_PUSH`/`_POP`, `_REP_MOVS`,
`_ANDN{,_MEM}`, `_BZHI{,_MEM}`, `_MOVBE_LOAD`/`_MOVBE_STORE`,
`_CMP_IMM_OP`/`_CMP_REG_OP` and the `_AUX` variants, the objdump/parser-to-AUX
selection relation, C-to-Lean unsigned-semantics correspondence,
compiler/native-byte correspondence, multi-step control-flow traces, and
specialization preservation.

## Commit

`601c76544` — code increment, 11 files, pushed to `origin/master`. Step report
and research log: `98426b872`. (The step-0031 report's open-surface addendum was
committed with it.)

## Evidence pair regeneration

Committed and pushed first: `601c76544` (code increment, 11 files), `98426b872`
(step report + research log). The retained receipt and log were regenerated at
`98426b872` (`make -C native-sim/formal check`, exit 0): 53 generator `--check`
runs, 93 Lean module checks, 41 host cross-checks over 1,874,700 oracle cases;
log bytes 14372, sha256
`556cff4735181857819233c240dc9598debbb6a585ef5f47bc04eab17009e002`.

`render_claim_table.formal_evidence(Path('.'))` returns `PASS` (receipt counts
agree with both the retained log and the `native-sim/formal/Makefile` at this
commit, receipt commit equals the log commit, log hash valid). Evidence refresh
committed and pushed as `87d556b54` (4 files: receipt, log, AE guide paragraph,
CHANGELOG).

## Archival ZIP

`docs/artifacts/package-atc26.sh` rebuilt `docs/artifacts/dist/atc26-ae-2.zip`
at `87d556b54`: sha256
`498ad1c71b9a895936386bf0aff1525dbd6cdd73562cc216ab60045873addc82`,
933,777,671 bytes, `ARTIFACT_MANIFEST.json.superprojectCommit` =
`87d556b5410c9f24770205b8b0892809d3495320` (matches HEAD), `self-test: OK
(13 evidence classes)`, `clean-extraction verification OK`. The ZIP is
untracked by design.
