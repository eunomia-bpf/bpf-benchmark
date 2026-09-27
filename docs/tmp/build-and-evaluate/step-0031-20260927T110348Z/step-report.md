# Step 0031 — x86 register-source `IMUL reg, imm` handler composition

Date: 2026-09-27 UTC

## Scope

Close the next item on the open x86 proof surface: the register-source
`IMUL reg, imm` handler (`X86_SIM_L_EXEC_IMUL_IMM`), chosen as the sibling of
the already-proved `IMUL reg, [mem], imm` handler minus the memory load and the
memory-operand width — a genuinely distinct left-operand rule (raw 64-bit
register value, never sign-extended) that the memory-source theorem does not
cover.

Target C path (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_IMUL_IMM` (line 1166),
  dispatched for `X86_OP_IMUL_IMM` (0x38) at line 1746.

## Changes

- New `native-sim/formal/KProgFormal/X86ImulRegImmHandler.lean` (127 lines):
  - `generatedX86ImulRegImmStep` / `x86ImulRegImmStepSpec` /
    `x86_imul_reg_imm_step_refines`: the generated composition is the decoded
    immediate sign-extended at the destination width, multiplied by the raw
    64-bit source register, with the divide-based IMUL flag construction
    (`GeneratedX86ImulFlags.signExtend`/`generatedX86ImulFlags`) and a
    width-confined writeback; a single `simp only` over the four `*_refines`
    lemmas (`x86_immediate_value_refines`, `x86_sign_extend_refines`,
    `x86_reg_write_refines`, `x86_imul_flags_apply_refines`) closes the
    structure equality for arbitrary state, source, immediate and width.
  - `x86_imul_reg_imm_preserves_zf_sf` (`rfl`): IMUL defines only CF/OF.
  - `x86_imul_reg_imm_cf_eq_of` (`rfl`): CF and OF report the same condition.
  - `x86_imul_reg_imm_tag_scalar` (`rfl`): the writeback scalarizes provenance.
  - `x86_imul_reg_imm_source_not_extended` (`rfl`): the register source is
    never sign-extended — an all-ones 64-bit source multiplies as `2^64 - 1`,
    not as a width-narrowed `-1`; this is the property that distinguishes the
    register-source form from the memory-source form.
  - Four `native_decide` examples: a 16-bit overflow (`0x7fff * 2`), a 64-bit
    sign-extending immediate whose product still fits (`1 * 0xffffffff80000001`,
    CF/OF clear), an 8-bit mixed-sign overflow (`-127 * 2`), and an in-range
    8-bit product. Each expected value was re-derived with an independent Python
    simulation of the immediate decode, sign extension, width-confined product
    and `a_abs`/`b_abs`/`limit` overflow rule before the module was committed;
    all four matched. No `sorry` or `admit`.
- New `native-sim/formal/test_x86_imul_reg_imm_handler_host.c`: independent
  oracle that sign-extends the narrowed source and computes an exact `__int128`
  product, against the real generated macros
  (`KPROG_X86_IMMEDIATE_VALUE`, `kprog_x86_sign_extend_value`,
  `kprog_x86_abs_width_value`, `KPROG_X86_SET_IMUL_FLAGS`,
  `KPROG_X86_WRITE_REG8/16/32/64`). 4 widths x 18 x 18 boundary vectors plus a
  40000-iteration fixed-seed LCG sweep: **41,296 cases**, zero warnings.
- Wiring: `KProgFormal.lean` import (after `X86MulxHandler`);
  `Makefile` check-target block (after the MULX block);
  `README.md` register-source multiply paragraph and TCB binding sentence;
  `docs/implementation.md` open-surface bullet.

## Verification

- `lake env lean KProgFormal/X86ImulRegImmHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_imul_reg_imm_handler_host.c ... &&
  ./build/test_x86_imul_reg_imm_handler_host` — zero warnings,
  `x86 IMUL-immediate register-source host cross-check: OK (41296 cases)`.
- Full `make -C native-sim/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-imulregimm.log`, 194 s, **40** host
  cross-checks (was 39), 1,813,260 oracle cases.
- The four Lean `native_decide` example values were cross-checked against a
  standalone Python simulation of the same step before the commit.

## Modeling notes

- **No memory operand, no `memWidth`.** Unlike the memory-source form, the left
  operand is the source register's raw 64-bit value
  (`X86_SIM_L_READ_REG(SRC)`, which reads at `X86_WIDTH_64`), so only the
  immediate is sign-extended, and at the *destination* width. The theorem takes
  an already-selected `lhs : BitVec 64`; the decoded immediate is
  `GeneratedX86Immediate.value rawImm width` then
  `GeneratedX86Signed.signExtend ... width`.
- **The `w32` special case of MULX does not recur.** MULX's width branch is a
  MULX-specific property of its low/high split; the register-source IMUL has a
  single uniform composition at every width, which is why the refines proof is
  one `simp only` with no `cases width`.
- **The oracle bug was the whole delay.** The first oracle draft computed its
  overflow comparison from `lhs & width_mask(width)`, which *masks* rather than
  *sign-extends*, so it disagreed with the generated side on CF/OF whenever the
  narrowed lhs had its sign bit set (294 mismatches, all CF/OF-only, `dst`
  always matching). The fix sign-extends the narrowed lhs in the oracle; the
  generated macro was never touched.
- The register *selection* (which register is the source) and effective-address
  derivation are supplied as already-selected operands, keeping this a bounded
  single-step refinement.

## Remaining open x86 surface

The AUX-payload `X86_SIM_L_EXEC_ALU_REG` IMUL path
(`native-sim/x86/x86_sim_local_bpf.h:908-953`, IMUL dispatch inside
`x86_alu_result` reached at line 943), then effective-address/address-space and
immediate/register-RHS selection, objdump/parser-to-AUX selection relation,
C-to-Lean unsigned-semantics correspondence, compiler/native-byte
correspondence, multi-step control-flow traces, specialization preservation.

## Commit

`011e3a80e` — code increment, 6 files, pushed to `origin/master`. Step report
and research log: `12475532c`.

## Evidence pair regeneration

Committed and pushed first: `011e3a80e` (code increment, 6 files), `12475532c`
(step report + research log). The retained receipt and log were regenerated at
`12475532c` (`make -C native-sim/formal check`, exit 0): 52 generator `--check`
runs, 90 Lean module checks, 40 host cross-checks over 1,813,260 oracle cases;
log bytes 14017, sha256
`ec7ff06322afff5330200c13d73e4f7102aa791fc275eab2367aa1a542d5209e`.

`render_claim_table.formal_evidence(Path('.'))` returns `PASS` (receipt counts
agree with both the retained log and the `native-sim/formal/Makefile` at this
commit, receipt commit equals the log commit, log hash valid). Evidence refresh
committed and pushed as `a14f9fdfd` (4 files: receipt, log, AE guide paragraph,
CHANGELOG).

## Archival ZIP

`docs/artifacts/package-atc26.sh` rebuilt `docs/artifacts/dist/atc26-ae-2.zip`
at `a14f9fdfd`: sha256
`f14b3b27caf6ba1d479a3b7c108050489f8e4b9db0d7b61e16c0c2db52407b7e`,
933,764,362 bytes, `ARTIFACT_MANIFEST.json.superprojectCommit` =
`a14f9fdfdd90ffa245e7645c1a4e99e606a9e78f` (matches HEAD), `self-test: OK
(13 evidence classes)`, `clean-extraction verification OK`. The ZIP is
untracked by design.
