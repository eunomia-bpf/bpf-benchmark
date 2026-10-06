# Step 0027 — x86 memory-source bit-test/zero-high-bits handler composition

Date: 2026-09-27 UTC

## Scope

Close the x86 memory-operand *bit* handler item on the open proof surface by
composing the legacy `BT [mem], imm8` handler and the BMI2 `BZHI dst, [mem],
count` handler.

Target C paths (read-only reference):
- `kprog/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_BT_MEM_IMM` (line 1156)
- `kprog/x86/x86_sim_local_bpf.h` `X86_SIM_L_EXEC_BZHI_MEM` (line 1119)
- dispatch `kprog/x86/x86_sim_local_bpf.h:1738-1745`

## Changes

- New `kprog/formal/KProgFormal/X86MemBitHandler.lean`:
  - `inductive X86MemBitOp | bt | bzhi`.
  - `generatedX86MemBitStep` / `x86MemBitStepSpec` and
    `x86_mem_bit_step_refines`: byte load -> generated `bt`/`bzhi` bit helper ->
    register writeback, composing `x86_mem_load_refines`,
    `x86_bt_refines_width`/`x86_bzhi_refines_width`, `x86_width_bits_refines`,
    and `x86_reg_write_refines`. The second operand enters as an already-decoded
    64-bit value, matching the handler's register read for BZHI and the decoded
    32-bit immediate for BT.
  - `x86_mem_bt_preserves_dst` / `x86_mem_bt_only_cf`: `BT` writes no register
    and only assigns CF.
  - `x86_mem_bzhi_clears_sf_of`: `BZHI` defines SF/OF as zero.
  - Three concrete examples proved by `native_decide` (8-bit BT bit 3, 32-bit
    BZHI count 4, 8-bit BZHI count reaching the width). No `sorry` or `admit`.
- `kprog/formal/KProgFormal/X86Bitops.lean`: added the width-indexed
  bridges `x86_width_code_spec_cases`, `x86_bt_refines_width`, and
  `x86_bzhi_refines_width` so the generated width code and the independent width
  code are connected without duplicating the `bv_decide` proof.
- `kprog/formal/KProgFormal/X86Width.lean`: added the missing
  `x86_width_bits_refines` (BZHI's `CF := count >= bits` compares against the
  width's bit count).
- New `kprog/formal/test_x86_mem_bit_handler_host.c`: independent byte-loop
  oracle against the real generated macros (`KPROG_X86_MEM_LOAD`,
  `kprog_x86_bt_value`/`kprog_x86_bzhi_value`, and the `KPROG_X86_WRITE_REG*`
  writeback), 2 ops x 4 widths x 8 x 8 boundary cases plus 20000 fixed-seed
  random cases.
- Wiring: `KProgFormal.lean` import; `Makefile` check-target block;
  `README.md` memory-source bit-test paragraph and TCB binding sentence;
  `docs/shared/implementation.md` open-surface bullet narrowed to
  compare/multiply memory handlers.

## Verification

- `lake env lean KProgFormal/X86MemBitHandler.lean` — clean, no output.
- `cc -Wall -Wextra -O2 -I. test_x86_mem_bit_handler_host.c ... &&
  ./build/test_x86_mem_bit_handler_host` —
  `x86 memory-bit host cross-check: OK (20512 cases)`.
- Full `make -C kprog/formal check` — RC=0, 0 occurrences of `error`;
  log `/workspaces/formal-check-bit.log`, ends at
  `lake env lean KProgFormal/Arm64Decode.lean`.

## Modeling notes

- `BT [mem], imm8` reads its address base from the *destination* register
  (`DST`) and its displacement from `x86_store_imm_disp(IMM)`, while the bit
  index is the decoded 32-bit immediate (`x86_store_imm_value(IMM,
  X86_WIDTH_32)`); it touches no register and no flag other than CF. BZHI's count
  is `READ_REG(...) & 0xff`, modeled as `index &&& 0xff` at the handler boundary.
- The `bt` index is masked to 63 only for a 64-bit base and to 31 otherwise —
  *not* to the narrow width's bit count. An 8-bit `bt` at index 8 therefore
  always yields false; the oracle models this explicitly.
- `lake env lean <file>` type-checks a file without refreshing the `.olean`s of
  its imports; `lake build` is required before a new module's lemmas become
  visible to a downstream file.
- The host oracle models the architectural 32-bit zero-extension of
  `KPROG_X86_WRITE_REG32` (upper half cleared, not merged).

## Remaining open x86 surface

Compare (`X86_SIM_L_EXEC_CMP_MEM`, `X86_SIM_L_EXEC_CMP_REG_MEM`) and multiply
(`X86_SIM_L_EXEC_IMUL_MEM_IMM`) memory-operand handler composition; then
effective-address/address-space and immediate/register-RHS selection,
objdump/parser-to-AUX selection relation, C-to-Lean unsigned-semantics
correspondence, compiler/native-byte correspondence, multi-step control-flow
traces, specialization preservation.

## Evidence pair regeneration

Committed and pushed first: `40ca51e79` (code increment, 10 files),
`fc9f418b5` (evidence refresh, 4 files). The retained receipt and log were
regenerated at `40ca51e79` (`make -C kprog/formal check`, exit 0, 115 s):
52 generator `--check` runs, 86 Lean module checks, 36 host cross-checks over
1,646,748 oracle cases; log bytes 13042, sha256
`71f1a6fd65bdecfb6c4df13656f124c7ae1bdafcd2eb02abcb7d5cb77228d2b3`.

`render_claim_table.formal_evidence(Path('.'))` returns `PASS` (receipt counts
agree with both the retained log and the `kprog/formal/Makefile` at this
commit, receipt commit equals the log commit, log hash valid).

## Archival ZIP

`docs/artifacts/package-atc26.sh` rebuilt `docs/artifacts/dist/atc26-ae-2.zip`
at `fc9f418b5`: sha256
`accabefa267fc107787d628520e75c99fbe087935f38730aba8bbffdb3d61dbb`,
933,739,268 bytes, `ARTIFACT_MANIFEST.json.superprojectCommit` =
`fc9f418b54ac6c8d47ad3e8446d799070467d8d5` (matches HEAD), `self-test: OK
(13 evidence classes)`, `clean-extraction verification OK`. The ZIP is
untracked by design.
