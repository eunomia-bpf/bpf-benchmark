# Step 0038 — x86 `SETCC` handler composition

Date: 2026-09-28 UTC

## Scope

Continue the x86 one-instruction handler line after steps 0036 (`MOV_LOAD`) and
0037 (shared `MOV_STORE`) with the first handler whose whole dependency chain is
already proved: `X86_SIM_L_EXEC_SETCC`, the body behind `X86_OP_SETCC` (`0x16`).
The condition semantics (`x86_condition_sound`), the register-byte writeback
(`x86_reg_write_at_refines`), and the packed register-lane AUX decode
(`x86_reg_lane_aux_*_roundtrip`) all existed before this step; what was missing
was the composition of the generated condition table and the lane table into a
single step relation, plus the contract that makes the generated tables
statements rather than restatements.

`SETCC` was chosen over the alternate `MOVBE_LOAD` for three reasons: its whole
chain is already proved; it has real callers in the corpus
(`bcc_tcpconnect_ipv4_tuple_filter.bpf.c:187` emits `SETCC(X86_R8, X86_CC_GE)`,
`cilium_socket_lb_service_select.bpf.c:121,127` emit `SETCC(X86_RCX/RDX,
X86_CC_NE)`); and `MOVBE_LOAD` reads through `X86_SIM_L_READ_MEM_VALUE(SRC, AUX,
IMM, width, 0)` without resolving its width inside the body, so it composes two
already-modeled pieces and would have been a thinner increment.

Target C path (read-only reference):
- `native-sim/x86/x86_sim_local_bpf.h:1520-1523` — the macro form and the
  inlined dispatch at 1686-1691 are identical text:
  `X86_SIM_L_WRITE_REG_WIDTH_SHIFT((DST), X86_SIM_L_EVAL_CC(
  KPROG_X86_REG_LANE_AUX_PAYLOAD(AUX)), X86_WIDTH_8,
  KPROG_X86_REG_LANE_AUX_DST_SHIFT(AUX))`. The chain is: the *payload* byte of
  the packed AUX word indexes the condition table and the *destination-shift*
  byte indexes the byte lane; the width is the constant `X86_WIDTH_8`; the write
  scalarizes the tag.
- `X86_SIM_L_EVAL_CC(CC)` (`:635-636`) expands to `KPROG_X86_EVAL_CC((CC),
  __x86_cf, __x86_zf, __x86_sf, __x86_of)` — the current flags are read, never
  computed.
- `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` (`:374-405`) resolves `WIDTH ? WIDTH :
  X86_WIDTH_64` and dispatches to `X86_SIM_L_WRITE_REG8_VALUE_CASE` →
  `KPROG_X86_WRITE_REG8(…, X86_SIM_TAG_SCALAR)`.
- `KPROG_X86_WRITE_REG8` (`generated/x86_reg_write.h`) writes `(STORAGE).b[1]`
  when `BYTE_SHIFT == 8U` and `(STORAGE).b[0]` otherwise, then sets `(TAG) =
  (SCALAR_TAG)`.

## Changes

- New `native-sim/formal/generate_x86_setcc_spec.py` (57th generator), emitting
  `native-sim/formal/x86_setcc_spec.json`,
  `native-sim/formal/KProgFormal/GeneratedX86Setcc.lean` and
  `native-sim/formal/generated/x86_setcc.h`:
  - `condOf : BitVec 8 -> Option Cond` from the 14 raw `X86_CC_*` codes
    (order `o no b ae e ne be a s ns l ge le g`), with the parity codes 10/11
    and everything ≥ 16 unsupported;
  - `evalCond (cf zf sf of) : Cond -> Bool` from the 14 boolean expressions,
    and `evalRaw` composing them (`match condOf cc with | some cond =>
    evalCond … | none => false`), which is the generated form of
    `KPROG_X86_EVAL_CC` including its `: 0` default;
  - `lane : Bool -> Lane` (`high`/`low`) and `toRegLane` onto the register
    write-at byte lane;
  - C side: the 14 `_Static_assert(X86_CC_* == code)` lines,
    `KPROG_X86_SETCC_COND_MATCHED(CC)` (a fold returning the matched raw code or
    `KPROG_X86_SETCC_COND_NONE`), `KPROG_X86_SETCC_LANE_LOW/_HIGH`,
    `KPROG_X86_SETCC_LANE(DST_SHIFT)` (the `== 8U` equality branch), and
    `KPROG_X86_SETCC_UNSUPPORTED_CC_CODES "10, 11"`.
- New `native-sim/formal/KProgFormal/X86SetccHandler.lean`:
  - `x86BoolValue`, `generatedX86SetccRaw`, `generatedX86SetccLane`,
    `generatedX86SetccWrite`, `generatedX86SetccStepAt` (over the two decoded
    bytes) and `generatedX86SetccStep` (over the packed AUX word, decoded with
    `GeneratedX86RegLaneAux.payload`/`.dstShift`), and the independent
    `x86SetccCondition`/`x86SetccStepSpec`.
  - `x86_setcc_eval_cond_sound` — the generated expression table equals the
    architectural `x86CondSpec`, proved by 14 constructor cases. This is the
    content that makes the generated table a statement: a transposition of any
    two arms fails it.
  - `x86_setcc_raw_cond_sound` (lift through `condOf`),
    `x86_setcc_raw_unsupported` (the `none` arm is `false`, matching the C
    default), `x86_setcc_lane_not_eight` and `x86_setcc_lane_high_iff` (the
    equality test, not truthiness), `x86_setcc_aux_fields` (the packed-word
    decode is the direct decode).
  - `x86_setcc_step_at_refines` (the handler composition: condition decode +
    lane decode + 8-bit writeback, inheriting `x86_reg_write_at_refines`) and
    `x86_setcc_step_refines` (the packed-AUX form the dispatch actually has).
  - Asymmetry theorems: `x86_setcc_step_preserves_upper_bytes`,
    `x86_setcc_step_scalarizes` (unconditional scalarizing, unlike `CMOV`),
    `x86_setcc_step_low_lane_writes_condition`,
    `x86_setcc_step_high_lane_writes_condition`.
  - Eleven `example`s with `simp`: the four lane-selection pins (8 high, 0/1/9
    low), two unsupported-code pins (10 and 16), `condOf 13 = some .ge`, and
    three condition-value pins.
  No `sorry` or `admit`.
- New `native-sim/formal/test_x86_setcc_host.c` — the independent oracle.
  - Part 1 sweeps the whole 256-value raw condition byte space against the
    generated `KPROG_X86_SETCC_COND_MATCHED` fold, pinning each of the 14
    accepted codes to itself and every other byte to
    `KPROG_X86_SETCC_COND_NONE`.
  - Part 2 sweeps the whole 256-value destination-shift space against the
    generated lane macro.
  - Part 3 drives the whole handler over a deterministic 16-register model
    (16 regs × 256 payloads × 8 shifts × 16 flag nibbles = 524,288 cases),
    comparing everything byte for byte and tag included.
  - Part 4 sweeps the destination shift 0..255 for a subset of payloads
    (16 × 16 × 256 = 65,536 cases).
  - Part 5 pins seven asymmetries: 8 vs. 9 lane selection, tag scalarization
    from a map-pointer tag, the fixed 8-bit write width under a nonzero
    source-shift byte, the payload-byte-as-condition decode (`e` vs. `ne`), the
    unsupported parity code writing 0, every accepted code reproducing the raw
    `KPROG_X86_EVAL_CC` expression over all 16 flag combinations, and `set ne`
    against a set and a clear zero flag.
  - Part 6 sweeps the generated `KPROG_X86_WRITE_REG8` helper over every byte
    shift 0..255 against an explicit equality-test model.
  **590,726 cases**, zero `-Wall -Wextra` warnings.
- Wiring: `import KProgFormal.GeneratedX86Setcc` and `import
  KProgFormal.X86SetccHandler` in `native-sim/formal/KProgFormal.lean` (58-59);
  Makefile `--check` line after the store generator (61) and the Lean+oracle
  triple after the store triple (166-169); README paragraph after the
  `MOV_STORE` paragraph plus the extended binding list; `docs/implementation.md`
  open-surface paragraph extended with the `SETCC` composition.

## Design notes

- **The generated contract carries a real proof obligation.** The first two
  generator revisions were rejected: v1 typed `condIndex` as `Option Nat` but
  returned `some .o`, and v2 built `evalRaw` directly from the boolean
  expressions, which left the `none`/unsupported case needing an unprovable
  256-way `BitVec 8` exhaustion. The shipped shape splits the raw-code→condition
  map (`condOf`, an `Option`) from the condition→boolean map (`evalCond`, total
  over the 14 constructors), so `evalRaw` composes them and the `none` arm is a
  defined `false` with no exhaustion. `x86_setcc_eval_cond_sound` is then real
  content, not a restatement.
- **The conformance obligation is split.** The raw-byte→condition mapping is
  swept exhaustively in C against the real `KPROG_X86_EVAL_CC` (oracle parts 1
  and 5); the expression table and the unsupported default are proved in Lean.
  Stated in the `x86_setcc_step_at_refines` docstring and in the oracle header.
- **`BitVec.ofBool` is 1-bit.** `BitVec.ofBool : Bool -> BitVec 1` in this
  toolchain, so the 64-bit boolean widening is the local `x86BoolValue b := if b
  then 1 else 0`, which is also what the C writes (a `_Bool` widened to
  `__u64`).
- **The lane test is an equality, not truthiness.** `KPROG_X86_WRITE_REG8`
  compares `BYTE_SHIFT == 8U`, so a destination shift of 9 selects `.b[0]`, not
  `.b[1]`. The Lean table mirrors this and `x86_setcc_step_preserves_upper_bytes`
  is stated as the mask `0xffffffffffff0000` — the strong
  `0xffffffffffffff00` form is false, because the high lane writes the *second*
  byte.
- **`SETCC` is the scalarizing counterpoint to `CMOV`.** `CMOV` at `w64`
  preserves the source's pointer tag through `X86_SIM_L_WRITE_REG_PTR_TAG`;
  `SETCC` always goes through the 8-bit write case, which always writes
  `X86_SIM_TAG_SCALAR`. The two handlers also disagree on condition input:
  `SETCC` reads the AUX *payload* byte, `CMOV` reads the whole AUX word.
- **The generated header defines no widths.** `generated/x86_setcc.h` defines no
  `X86_WIDTH_*` and includes nothing, so the oracle `#define`s the four codes at
  the top, as the store oracle does.
- **The generated contract is not wired into the live sim** — `x86_setcc.h`
  joins the `used=0` set of proof-only generated headers. Wiring
  `X86_SIM_L_EXEC_SETCC` is a separate, riskier edit; same decision as the
  previous five increments.

## Verification

- `lake build` then `lake env lean KProgFormal/X86SetccHandler.lean`: passes, 0
  `error:` lines, 0 warnings, 0 `sorry`.
- `python3 generate_x86_setcc_spec.py && python3 generate_x86_setcc_spec.py
  --check`: passes (`IDEMPOTENT`).
- Standalone oracle: `cc -Wall -Wextra -O2 -I. test_x86_setcc_host.c
  -o build/test_x86_setcc_host && ./build/test_x86_setcc_host`
  → `x86 setcc handler host cross-check: OK (590726 cases)`, zero warnings.
- **Non-vacuity probes.** Eight separate mutations of the oracle's model — the
  `e`/`ne` condition arms transposed, the payload and destination-shift decoders
  swapped, the unsupported-code default set to true, the modeled write widened
  to 16 bits, the written byte AND-ed instead of assigned, the destination tag
  set to `PACKET`, the unsupported-code fold result hard-set to 0, and a
  truthiness lane test — plus two mutations of the *real generated headers*
  (`KPROG_X86_WRITE_REG8` and `KPROG_X86_SETCC_LANE` made truthiness tests) each
  make the oracle (or part 6) exit 1.
- Full `make -C native-sim/formal check`: RC=0, 0 `error:` lines, **57
  generators / 103 Lean module checks / 47 host cross-checks over 2,766,407
  cases**.

## Open after this step

`X86_OP_SETCC_MEM` (`0x3e`) and `X86_OP_CMOV`/`X86_OP_CMOV_MEM` (`0x15`/`0x40`)
have their full bodies read and share the pieces this step composed — `SETCC_MEM`
takes the condition from the AUX *source-shift* byte (not the payload) and
writes memory instead of a register lane, and `CMOV` reads the whole AUX word and
preserves the pointer tag at `w64`. `_MOVBE_LOAD`/`_MOVBE_STORE`, then the rest
of the x86 surface (`_MOV_LOAD_MAP_PTR`, `_STORE_XMM0`/`_LOAD_XMM0`,
`_CALL_MEMCPY_{,REG}`/`_CALL_MEMSET_{,REG}`, `_PUSH`/`_POP`, `_REP_MOVS`,
`_ANDN{,_MEM}`, `_BZHI{,_MEM}`, `_CMP_IMM_OP`/`_CMP_REG_OP`), the index register
decode and packed-AUX layout, the simulator-stack-to-abstract-frame-base
mapping, compiler/native bytes, multi-step traces, and specialization
preservation remain open.
