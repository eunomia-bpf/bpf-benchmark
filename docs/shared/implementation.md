# Implementation state — BPF benchmark framework

This file is the current handoff pointer for the duty chain. The authoritative,
continuously updated research log is
[`docs/archive/shared/20260906-bpf-development-todo.md`](../archive/shared/20260906-bpf-development-todo.md),
which supersedes stale execution boundaries without deleting them.

## Active line: kprog / kprog semantic-refinement proof

The NativeBPF stock-kernel simulator line
(`kprog/`, `kprog/formal/`) is in its per-step semantic-refinement
phase, driven by the user instruction "做一步 commit push 一步" (each proven
increment is committed and pushed immediately). Current state:

- Both x86-64 and AArch64 implement and build the instruction subsets emitted
  by the 29 workload-derived micro kernels; x86-64 KVM and AArch64 full-system
  QEMU both pass the 29-case functional smoke (`make selftest`).
- `kprog/formal` is a Lean 4 model checked with
  `make -C kprog/formal check`. It machine-checks the generated
  JSON/C/Lean contracts: width narrowing, entry ABI loads, pointer add,
  x86/AArch64 condition tables, x86/AArch64 ALU decode tables, logical/
  ADD/SUB/ADC/SBB/INC/DEC/NEG/NOT flag and result production, shift results
  and flags, register-lane AUX layout, register-destination immediate handler
  compositions for ADD/ADC/SUB/SBB/CMP/TEST/AND/OR/XOR/SHL/SHR/SAR/ROL,
  register-register AND/OR/XOR/SHL/SHR/SAR/ROL/ROR handler compositions, the
  BSWAP/MOVBE byte-reversal contract, the sign-extension and width-magnitude
  contract, the POPCNT population-count contract, the BT/BZHI bit-manipulation
  contract, the SHLD/SHRD double-shift contract, the carry-sensitive handler
  classification (SBB/ADC routing through generated C predicates), the AArch64
  NZCV flag and decode-table contracts, the
  eight-operation AArch64 multiply-family value contract, the six-operation
  AArch64 extract/reverse/extend (EXTR/REV/REV16/SXTH/SXTW/SXTB) value
  contract, the eight-operation AArch64 conditional-select family
  (CSEL/CINC/CSET/CSETM/CINV/CSINV/CSINC/CSNEG) value contract composed with
  the condition table, the four-kind AArch64 compare-and-branch
  (CBZ/CBNZ/TBZ/TBNZ) predicate contract that completes the
  condition-to-next-PC relation, the four-column AArch64 move-wide
  (MOVK) insertion contract, the four-kind AArch64 shift
  (LSL/LSR/ASR/ROR) value contract shared with the decode table, the
  two-kind AArch64 byte-lane reduction (CNT/UADDLV) contract, the
  four-form AArch64 load/store address-offset contract, the four-direction
  AArch64 FMOV move contract, the four-width AArch64 little-endian
  byte-ladder load contract, the eight-lane AArch64 byte-lane scatter
  contract (proved inverse to the load ladder), the four-space AArch64
  memory tag-dispatch contract, and the two-condition AArch64 stack slot-tag
  contract. The generic AArch64 ALU handler additionally composes all six ALU
  results with width-aware GPR/SP/XZR/NONE writeback and the
  provenance-preserving pointer-ADD path. The operand-handler theorem composes
  immediate selection or all eleven register source modifiers into that full
  state transition. The arithmetic flag-handler theorem
  composes ADDS/SUBS result writeback with NZCV and proves that CMN/CMP replace
  NZCV without changing modeled register/SP state. The logical flag-handler
  theorem similarly composes the AND/BIC result and logical-NZCV primitives:
  ANDS/BICS perform scalarizing width-aware writeback, while TST/TST-BIC
  preserve modeled register/SP state. The CCMP theorem composes the incoming
  condition decision with SUB-NZCV or immediate fallback NZCV and proves that
  both paths preserve modeled register/SP state.
- The x86 memory-source arithmetic handler theorem composes the generated
  little-endian load with ADD/ADC/SUB/SBB result and flag transitions plus
  low-lane register writeback for all legal widths. Its independent 22,048-case
  C oracle also caught and now pins a real SBB overflow bug: OF must compare the
  original `b` with the final result, not the width-wrapped `b+borrow`.
- The complementary x86 memory-destination theorem composes the old-value load,
  ADD/ADC/SUB/SBB transition, and little-endian store. It proves replacement of
  exactly the selected width's bytes, preservation of every other byte, and
  equality of all modeled flags; a separate 22,048-case C oracle checks the
  generated load/store macros against independent byte and 128-bit arithmetic.
- The x86 memory-unary theorem composes the real `X86_OP_ALU_MEM_UNARY`
  `INC/DEC/NEG/NOT` load, result/flag transition, and width-confined store. It
  proves equality of every modeled flag and memory byte; an independent
  22,048-case oracle exhausts all 16 incoming flag combinations over its
  boundary vectors and checks 20,000 fixed-seed cases.
- The x86 memory-destination logic theorem similarly composes `AND/OR/XOR`
  through load, replacement flags, and confined store. Its independent
  21,536-case oracle checks every incoming flag combination in the boundary
  vectors and confirms that logical CF/OF are cleared while ZF/SF are replaced.
- The immediate-opcode handler composition pattern is: select the typed lane
  and raw immediate field, decode with the generated immediate contract,
  compute the generated result, write back the selected lane with tag
  scalarization, and take flags from the generated flag contract; each
  generated handler refines an independently stated spec.

### Current boundary and open work

- Open x86 proof surface: the memory-source shift/rotate handlers
  `SHLX/SHRX/SARX/RORX [mem]` are composed by
  `x86_mem_shift_step_refines`/`x86_mem_rorx_step_refines`, the
  `BT [mem], imm8`/`BZHI dst, [mem], count` handlers by
  `x86_mem_bit_step_refines`, the `IMUL reg, [mem], imm` handler by
  `x86_mem_imul_step_refines`, the `IMUL reg, imm` handler by
  `x86_imul_reg_imm_step_refines`, the four `CMP/TEST [mem], rhs` forms and
  `CMP reg, [mem]` by `x86_mem_compare_step_refines`/
  `x86_cmp_reg_mem_step_refines`, and the two-destination `MULX` by
  `x86_mulx_step_refines`, each over the generated
  load/shift-result/bit-helper/immediate/sign-extend/multiply-flag/
  four-limb-product/sub-flag/logic-flag/writeback contracts. The
  effective-address/LEA handler `X86_SIM_L_EXEC_LEA` is composed by
  `x86_lea_step_refines` over the generated `KPROG_X86_MEM_OFFSET` contract
  (`x86_mem_offset_refines`), covering the RODATA fast path, the abstract
  stack-base path, the provenance-carrying 64-bit pointer path, and the
  scalarizing narrow-width exits. The register-writing MOV handlers
  `X86_SIM_L_EXEC_MOV_IMM` and `X86_SIM_L_EXEC_MOV_REG` are composed by
  `x86_mov_imm_step_refines` (partial-register writeback over the raw
  immediate) and `x86_mov_reg_step_refines` (64-bit provenance-copying and
  abstract stack-base arms, scalarizing narrow arms). The width-converting
  register-source MOV handlers `X86_OP_MOVZX_REG` and `X86_OP_MOVSX_REG`
  (shared body `X86_SIM_L_EXEC_MOVX_REG`, also carrying `cdqe` and `movsxd`)
  are composed by `x86_movx_reg_step_refines`: the source register's raw
  64-bit value is narrowed or sign-extended at the decoded *source* width and
  written back through the partial-register writeback at the decoded
  *destination* width, with no byte lane. The shared memory read body
  `X86_SIM_L_READ_MEM_VALUE` — the value-source selection behind the plain
  load and store families — is classified by `x86_mem_dispatch_src_refines`
  over the generated `KPROG_X86_MEM_READ_SRC` contract: whether the base
  register is the stack pointer (register identity, tested first), whether its
  tag is ABI, and whether the effective width is 64 bits. It carries no reloc
  arm and no per-arm result tag; the ABI packet tag refinement lives in
  `X86_SIM_L_EXEC_MOV_LOAD`, whose handler composition (the shared body of
  `X86_OP_MOV_LOAD`, `X86_OP_MOV_LOAD_SCALAR`, and `X86_OP_MOVSX_LOAD`) is
  composed by `x86_mov_load_step_refines` over the generated width-resolution
  and arm contracts: the write width defaults to 64 bits and the memory width
  falls back to it, the arm table selects the stack read (register identity,
  tested first, ignoring `_MOVSX_LOAD` sign extension), the ABI pointer arm
  (gated on the plain `_MOV_LOAD` opcode and both resolved widths at 64 bits,
  writing the generated `KPROG_ABI_LOAD_TAG` provenance), or the ordinary
  byte-ladder load with `_MOVSX_LOAD` sign extension, then the partial-register
  writeback. The shared store body `X86_SIM_L_EXEC_STORE` — the single body
  behind `X86_OP_MOV_STORE_IMM` and `X86_OP_MOV_STORE_REG` — is composed by
  `x86_store_step_refines` over the generated width-resolution, displacement,
  value-source, AUX-shift-source, and arm contracts: it resolves one width used
  for both the immediate value and the write, takes `(s32)(IMM >> 32)` on the
  immediate form and `(s64)IMM` on the register form, reads the AUX source
  shift only on the register form (after the register read, so the immediate
  form ignores it, and modulo 64, matching the C `>>=` truncation), and writes
  through the stack helper when the destination is the stack pointer and the
  ordinary little-endian store otherwise.
  The `SETCC` handler `X86_SIM_L_EXEC_SETCC` (`X86_OP_SETCC`, `0x16`) is
  composed by `x86_setcc_step_refines` over the generated condition-decode,
  lane-decode, and 8-bit-writeback contracts: the condition is resolved from
  the AUX payload byte with the flags used as given (no flag production), the
  generated `KPROG_X86_EVAL_CC` expression table is pinned to the architectural
  condition table by `x86_setcc_eval_cond_sound` (a 14-case proof, so a
  transposition of any two arms fails), codes outside the accepted subset
  evaluate to false, the write width is fixed at 8 regardless of the AUX
  source-shift byte, the destination byte lane is selected by an *equality*
  test on the destination shift (so 9 selects the low byte), and the
  destination tag is scalarized unconditionally.
  The `SETCC_MEM` handler `X86_SIM_L_EXEC_SETCC_MEM` (`X86_OP_SETCC_MEM`,
  `0x3e`) is composed by `x86_setcc_mem_step_refines` over the generated
  source-shift condition decode, the null-base and stack-arm selectors, the
  generated effective-address offset, and the one-byte memory/stack write: the
  condition is the AUX source-shift byte at bits 24..31 (so the same AUX word
  names a different condition here than for `SETCC`), the displacement is the
  whole immediate (unlike the immediate store's high-half slice), the write
  width is the opcode's constant 8-bit code regardless of any AUX memory-width
  byte or FLAGS code, and the destination register number drives both the
  null-base test (`X86_REG_NONE` forms process null, which is not the stack
  pointer and so always takes the memory arm) and the `X86_RSP` arm test.
  The `CMOV` / `CMOV_MEM` handlers `X86_SIM_L_EXEC_CMOV`
  (`X86_OP_CMOV`, `0x15`) and `X86_SIM_L_EXEC_CMOV_MEM`
  (`X86_OP_CMOV_MEM`, `0x40`) are composed by
  `x86_cmov_step_refines` over the generated condition, width, access-width,
  displacement, and writeback contracts: the register form's condition is
  the whole AUX word against the generated `KPROG_X86_EVAL_CC` expression
  table, the memory form's is the AUX source-shift byte at bits 24..31
  (so one AUX word names two different conditions,
  `x86_cmov_condition_sources_differ`), the write width is the FLAGS code
  with a 64-bit fallback, the memory form's access width a two-level
  fallback through the AUX memory-width byte
  (`x86_cmov_mem_width_two_level_fallback`), the memory form's
  displacement is the high half of the instruction artifact, the
  immediate store's slice
  (`x86_cmov_mem_disp_differs_from_setcc_mem`), and the writeback is a
  width-keyed table, pointer-preserving at 64 bits, scalarizing below.
  Both forms are conditional — the whole body, value production included,
  is inside the condition test, so a false condition leaves the
  destination untouched (`x86_cmov_false_condition_no_write`). The
  register form's 64-bit arm preserves the source's provenance tag, every
  narrower arm scalarizes
  (`x86_cmov_w64_arm_preserves_source_tag`,
  `x86_cmov_narrow_arm_scalarizes`); the memory form writes through the
  scalarizing partial-register write at every width, including the
  64-bit one, and so never preserves a tag.
  Open: the index register decode and packed AUX layout, the mapping from the simulator's stack region
  to the abstract frame base, address-space, register and immediate/RHS
  objdump/parser-to-AUX selection relation, C-to-Lean
  unsigned-semantics correspondence, compiler/native-byte correspondence,
  multi-step control-flow traces, and specialization preservation. All x86 value
  helpers (`x86_bswap`, `x86_popcount64`, `x86_sign_extend`,
  `x86_signed_abs_width`, `x86_shld`/`x86_shrd`, `x86_ror`, the BT/BZHI
  predicates) now delegate to generated contracts with proven refinements.
  The register-number -> dispatch-cell binding inside the composed bodies is no
  longer open: for AArch64 (Step 0108) and x86-64 (Step 0112) the decoded
  register number is bound, by a generated machine-checked contract, to the
  state cell the writeback and read bodies select, leaving the width handling
  and the value computation in the composed body.
  The helper-id -> helper-body binding inside the composed call ladder is
  likewise no longer open for x86-64 (Step 0113): the decoded 64-bit helper id
  is bound, by a generated machine-checked contract, to the helper body
  `X86_SIM_BPF_CALL_ID` runs (and, through it, `X86_SIM_BPF_CALL_REG` and the
  chain's `X86_OP_CALL_REG` arm), leaving the per-helper value computation in
  the composed body; the AArch64 simulator has no helper ladder, so there is no
  mirror.
  The `XCHG` arm's choice of body on its resolved operand width is likewise no
  longer open for x86-64 (Step 0114): the arm now routes its body through a
  generated machine-checked full-width selector, so the pointer-cell swap and
  the width-masked value swap are selected by a proved table rather than a
  restated width test, leaving the register reads, writes, and the value
  computation in the composed arm body.
  The `DIV` arm's choice of quotient/remainder body on its resolved operand
  width is likewise no longer open for x86-64 (Step 0115): the arm now routes
  its four bodies through a generated machine-checked width-keyed selector, so
  the byte/word/dword/qword cases (and the qword case's architectural
  high-half overflow gate) are selected by a proved table rather than a
  restated width ladder, leaving the register reads, writes, and the
  quotient/remainder computation in the composed arm bodies; the AArch64
  simulator's `DIV`-analogue is not a width-keyed four-body split, so there is
  no mirror.
  The `SHLD`/`SHRD` immediate arm's choice of body and flag family on the opcode
  is likewise no longer open for x86-64 (Step 0116): the arm now routes both its
  body and its shift-flag family through generated machine-checked opcode-keyed
  selectors (the left double shift and the SHL family at `X86_OP_SHLD_IMM`, the
  right double shift and the SHR family elsewhere), behind the count-zero step
  gate, so the case choice is a proved table rather than a restated opcode test,
  leaving the register reads, writes, and the double-shift value computation in
  the composed arm bodies; the AArch64 simulator's double-shift analogue is not
  an opcode-keyed two-body split, so there is no mirror.
  The `POPCNT` arm's arithmetic flag block is likewise no longer open for
  x86-64 (Step 0117): the arm now routes its flag block through a generated
  machine-checked transition that clears `CF`/`SF`/`OF` and sets `ZF` from the
  width-narrowed source being zero, so the flag consequence is a proved
  contract rather than a restated clear/set sequence, leaving the register read,
  the population count, and the destination writeback in the composed arm body.
  Unlike the logical shape, `SF` is cleared rather than derived from the
  result's sign, so a logic-flag reuse would be wrong; the AArch64 simulator has
  no flags-setting population-count instruction, so there is no mirror.
  The `MOVZX`/`MOVSX` register arm's choice of *which* extension function
  widens the raw source register is likewise no longer open for x86-64
  (Step 0118): the arm now routes both its standalone `X86_SIM_L_EXEC_MOVX_REG`
  body and its inline opcode arm through a generated machine-checked
  opcode-keyed selector, which names the sign extension at `X86_OP_MOVSX_REG`
  and the zero extension at every other opcode, so the extension choice is a
  proved table rather than a restated `SIGN_EXTEND ? sign : zero` branch,
  leaving the source-width fallback, the register read, and the destination
  writeback in the composed arm bodies; the AArch64 simulator has no
  opcode-keyed MOVX extension split, so there is no mirror.
  The `MOV_REG` register arm's choice of *which* body a `mov` runs is likewise
  no longer open for x86-64 (Step 0119): the arm now routes both its standalone
  `X86_SIM_L_EXEC_MOV_REG_AUX`
  body and its inline opcode arm through a generated machine-checked selector,
  which names the stack-base write at the full 64-bit width when the source is
  the stack pointer, the provenance-preserving pointer write at the full width
  for every other source, and the narrow scalarizing lane write at every
  narrower width whatever the source, so the body choice is a proved table
  rather than a restated `width == 64 && src == rsp` ladder, leaving the
  register reads, the stack-base addition, and the destination writeback in the
  composed arm bodies; the AArch64 simulator has no width/register-keyed
  `MOV_REG` body split, so there is no mirror.
  The stack helper's choice of *which* body moves a word through the frame is
  likewise no longer open for x86-64 (Step 0120): both
  `X86_SIM_L_STACK_WRITE` and `X86_SIM_L_STACK_READ` now route through a
  generated machine-checked two-fact selector, which names the word-arena
  access at the full 64-bit width when the resolved index is qword-aligned and
  the little-endian byte ladder at every other width and every unaligned index,
  so the body choice is a proved table rather than a restated
  `width == 64 && aligned` test, leaving the byte-window arithmetic, the
  narrow-value masking, and the little-endian assembly in the composed
  bodies; the AArch64 stack *read* helper's body choice is now closed too
  (Step 0121): `ARM64_SIM_L_STACK_READ` routes through a generated
  machine-checked two-fact selector, naming the word-arena access at the full
  64-bit width when the resolved index is qword-aligned and the little-endian
  byte ladder at every other width and every unaligned index, so the body
  choice is a proved table rather than the restated
  `width == 64 && aligned` test, leaving the byte-window arithmetic and the
  little-endian assembly in the composed bodies; the AArch64 stack *write*
  helper already routed its slot-tag gate through `KPROG_ARM64_STACK_TAG`, so
  only the read body choice was open.
  The AArch64 little-endian *store* ladder is likewise no longer open
  (Step 0122): `ARM64_SIM_L_STORE_ADDR` routes through the generated
  `KPROG_ARM64_STORE_BYTES` contract, which writes the width's low bytes of
  the value through a byte pointer with the width-gated ladder and leaves every
  higher byte untouched, so the store image is a proved table rather than a
  hand-written lane sequence; `Arm64StoreBytes.lean` equals the generated
  masked store image to an independent lane-by-lane write-then-read statement
  and ties it to the load contract (`arm64_store_bytes_load_agree`), leaving
  the address arithmetic and the destination selection in the composed bodies.
  The AArch64 store helper's choice of *which* body writes the resolved
  access is likewise no longer open (Step 0123): `ARM64_SIM_L_MEM_WRITE` now
  routes through a generated machine-checked two-fact selector, naming the
  stack arena write when the base register is the stack pointer or its resolved
  tag names a stack slot and the plain little-endian byte store at every other
  base, so the destination is a proved table rather than the restated
  `BASE == ARM64_SP || tag == TAG_STACK` test. The selector's stack test is
  character-identical to the load dispatch's own space test, and
  `Arm64MemWriteArmShape.lean` ties the generated store classification to the
  load path's space/source table so the two cannot drift
  (`arm64_mem_write_arm_matches_read_src`), leaving the address arithmetic and
  the composed bodies.
  The AArch64 stack *write* byte ladder's per-lane width gates are likewise no
  longer open (Step 0124): `ARM64_SIM_L_STACK_WRITE_TAG` now gates each of its
  eight byte-arena writes through the generated activation predicate
  `KPROG_ARM64_STACK_WRITE_LANE_ACTIVE`, backed by the width's active-lane mask
  (`w8`→`0x01`, `w16`→`0x03`, `w32`→`0x0f`, `w64`→`0xff`, the low `n` bits set
  for an `n`-byte access), so the byte ladder's activation is a proved monotone
  table rather than the four restated `>= ARM64_WIDTH_16`/`>= ARM64_WIDTH_32`/
  `== ARM64_WIDTH_64` gate blocks, leaving the byte-window arithmetic and the
  little-endian value composition in the composed bodies. The contract is the
  write-side counterpart of the read body selection (`KPROG_ARM64_STACK_ARM`,
  Step 0121) and of the memory-side store ladder (`KPROG_ARM64_STORE_BYTES`,
  Step 0122): `Arm64StackWriteLanesShape.lean` proves the generated
  mask-bit activation equal to an independent literal construction and ties it
  to the `Arm64ByteLane` extraction, the `Arm64Width` codes and the store-bytes
  contract (`arm64_stack_write_lanes_matches_store_bytes`), so the stack and
  memory byte ladders activate the same lanes at every width.
  The AArch64 dispatcher's eight immediate/register opcode-family gates are
  likewise no longer open (Step 0125): `ARM64_SIM_L_EXEC` now selects the ALU,
  SHIFT, SUBS, ADDS, CMP, TST, ANDS and CCMP arms through the generated
  membership predicates `KPROG_ARM64_<F>_HANDLED(OP)`, each a plain-expression
  disjunction over its two member opcodes and each bound by `_Static_assert` to
  the `ARM64_OP_*` numbers of `arm64_sim.h`, so the arm selection is a proved
  table rather than the eight restated `(OP) == ARM64_OP_*_IMM || ...` pairs,
  leaving the per-arm operand selection and the composed handler bodies.
  `Arm64DispatchFamily.lean` proves every generated membership equal to an
  independent named-list statement over the sixteen opcodes
  (`arm64_dispatch_<F>_refines`), that the eight families are pairwise disjoint
  so the ordered chain takes at most one gate per opcode, and that the generated
  opcode table matches the `ARM64_OP_*` numbers
  (`arm64_dispatch_code_dispatch`), so a member reaches its arm and a
  non-member reaches the caller's unsupported arm.
  The dispatcher's remaining sixteen individually-gated singleton opcodes are
  likewise no longer open (Step 0126): the NOP, MOVK, BITFIELD, CMN_IMM,
  CMN_REG, TST_BIC_REG, BICS_REG, LOAD, STORE, LDP, STP, LOAD_D0, STORE_D0,
  LOAD_Q0, STORE_Q0 and FMOV gates in `ARM64_SIM_L_EXEC` now route through the
  generated one-member membership macros `KPROG_ARM64_DISP_<NAME>_HANDLED(OP)`,
  each a plain `((OP) == ARM64_OP_X)` expression usable inside `_Static_assert`
  and each bound to its `ARM64_OP_*` number by a code-drift assert and to itself
  by a coverage assert, so a singleton gate is a proved contract rather than a
  hand-rolled raw comparison. `Arm64DispatchSingleton.lean` proves each
  generated membership equal to an independent named singleton list
  (`arm64_disp_<name>_refines`), that a non-member reaches the caller's
  unsupported arm (`arm64_singleton_nonmember_unhandled`), that all sixteen
  opcodes lie in the C opcode-byte range (`arm64_singleton_code_in_range`), and
  — as the cross-contract to Step 0125 — that the combined singleton and
  dispatch-family opcode numbers are pairwise distinct
  (`arm64_dispatch_chain_codes_nodup`), so the ordered chain selects exactly one
  arm per opcode. The two remaining operand-source selections in
  `ARM64_SIM_L_EXEC` are likewise no longer open (Step 0127): the move arm's
  value source and the shift arm's amount source now route through the
  generated `KPROG_ARM64_IMM_RHS(OP, IMM, REG)`, whose statement expression
  selects the decoded immediate exactly on the two `_IMM` opcodes and the
  caller-supplied register expression otherwise, so the move reads the source
  register and the shift the second source. `Arm64ImmOperand.lean` proves the
  generated `immediate` predicate equal to an independent named-list membership
  (`arm64_imm_operand_refines`), that exactly the `_IMM` member of each pair is
  immediate (`arm64_imm_operand_pairs_exclusive`), that the two families are
  disjoint, and that all four opcodes lie in the C opcode-byte range.
  The sign-extending load arm is likewise no longer open (Step 0128): the LDRSB,
  LDRSW, and LDRSH arms of `ARM64_SIM_L_EXEC` no longer derive the sign-extending
  opcode for the shared extract/reverse/extend contract by a raw opcode ternary,
  but route through the generated `KPROG_ARM64_LDRSX_SXOP(OP, UNSUPPORTED)`
  statement expression, which selects SXTB for a byte load, SXTW for a word
  load, and SXTH for a halfword load and forwards any opcode outside the family
  to the caller-supplied unsupported arm. `Arm64LdrsxOp.lean` proves the
  generated `sxCode` equal to an independent code-keyed statement
  (`arm64_ldrsx_op_refines`), that the derived opcode is determined by the load
  opcode alone (`arm64_ldrsx_op_code_determined`), that each derived opcode is a
  member of the independent sign-opcode table (`arm64_ldrsx_op_selects_member`)
  and is never itself a load opcode (`arm64_ldrsx_op_sx_not_load`), that the
  three load opcodes and the three sign opcodes are each pairwise distinct, that
  the sign position pinned by `signBits` matches the well-tested load-width
  contract (`arm64_ldrsx_op_signbits_match_width`), and that every load opcode
  lies in the numeric case-label range the shared C macro addresses.
  The ALU arm's operand *source* selection is likewise no longer open (Step
  0129): the generic ALU arm no longer decides the right-hand operand source by
  a raw `(OP) == ARM64_OP_ALU_IMM` test, but routes the 0/1 decision through the
  generated `KPROG_ARM64_ALU_OPERAND_SELECT(OP)` statement expression, which
  returns 1 exactly on the `ARM64_OP_ALU_IMM` code and 0 (the register form) for
  every other code, feeding the existing `KPROG_ARM64_ALU_RHS` value contract.
  `Arm64AluOperandSelect.lean` proves the generated `immediate` predicate equal
  to an independent named-list membership (`arm64_alu_operand_select_refines`),
  that no register-form opcode selects the immediate
  (`arm64_alu_operand_select_reg_never_immediate`), that the two opcode lists
  are disjoint (`arm64_alu_operand_select_lists_disjoint`), the exact 6/7 code
  dispatch and case-label range, and composes the decision into the existing
  `arm64_alu_operand_handler_refines` theorem.
  The `MULX` arm's choice of body on its resolved operand width is likewise no
  longer open for x86-64 (Step 0130): `X86_SIM_L_EXEC_MULX` now routes through
  the generated machine-checked selector `KPROG_X86_MULX_ARM(WIDTH)`, which
  names the 32x32 single-product split exactly at the 4 (32-bit) width code and
  the four-limb radix-`2^32` ladder at every other code, so the band choice is a
  proved table rather than a restated `__x86_l_width == X86_WIDTH_32` test,
  leaving the register reads, the low/high split, and the two destination
  writes in the composed arm body. `X86MulxArmHandler.lean` proves the generated
  `armOf` equal to an independent literal statement built from the width
  contract's own `x86WidthCodeSpec .w32` (`x86_mulx_arm_refines`), that the
  single-product arm is selected exactly at the 32-bit width code and the ladder
  arm at every other code (`x86_mulx_arm_single_iff_w32`,
  `x86_mulx_arm_ladder_iff_not_w32`, `x86_mulx_arm_over_widths`), that the
  generated code tables have exactly the declared arm count and no duplicates,
  and composes the selection into the existing
  `X86MulxHandler.lean` width-discrimination theorem
  (`x86_mulx_arm_single_iff_handler_w32`); it does not re-prove the multiply
  arithmetic, which `X86MulxHandler.lean` already covers. The generated C
  header additionally pins the generated table's special-width code and the
  numeric arm codes to the hand-written decodes by `_Static_assert`, and the
  AArch64 simulator's multiply-into-two-registers analogue is not a width-keyed
  two-body split, so there is no mirror.
  The `BZHI`/`BZHI_MEM` arms' flag block is likewise no longer open for x86-64
  (Step 0131): both arms compose one `X86_SIM_L_EXEC_BZHI_STEP` that routes its
  flag block through a generated machine-checked transition
  (`KPROG_X86_SET_BZHI_FLAGS`) which clears `SF`/`OF`, sets `CF` from the
  byte-masked count reaching the width's bit count, and sets `ZF` from the
  width-narrowed result being zero, so the flag consequence - including its
  *two* independent inputs - is a proved contract rather than a restated
  comparison sequence, leaving the register/memory reads, the masked-count
  bit clear, and the destination writeback in the composed step body.
  `X86BzhiFlags.lean` proves the generated `eval` equal to an independent
  literal statement built from its two predicate inputs
  (`x86_bzhi_set_flags_refines`), that the generated flag sources match the
  spec (`x86_bzhi_set_flags_cf_source_refines`,
  `x86_bzhi_set_flags_zf_source_refines`,
  `x86_bzhi_set_flags_clears_sf_of`), and that the two inputs are ordered
  count-then-result; unlike `POPCNT` this contract takes two flag inputs, so a
  single-input logic-flag reuse would be wrong; the AArch64 simulator has no
  bit-clear-with-flags instruction, so there is no mirror. The routed flag
  block is cross-checked by `test_x86_bzhi_flags_route_host.c`, which sweeps
  the count across every width's bit count and drives the result to zero, so
  both the `CF` (`count >= bits`) and `ZF` (`result == 0`) boundaries are
  numerically exercised.
  The x86-64 helper-call ladder is likewise no longer open as a restated
  comparison sequence (Step 0132): the runtime `X86_SIM_BPF_CALL_ID` now
  switches on the generated, static-asserted, machine-checked
  `KPROG_X86_HELPER_SLOT` selector instead of an inline
  `__x86_helper_id == X86_SIM_HELPER_bpf_*` ladder, so the helper-id -> body
  binding the routed register form (`X86_SIM_BPF_CALL_REG`, the chain's
  `X86_OP_CALL_REG` arm) relies on is a proved contract rather than a
  hand-written chain; each arm keeps its own body macro, and the default arm
  keeps the RAX zero-write. `X86HelperDispatch.lean` now also proves the
  routed body `x86HelperDispatchRoutedBodySpec` runs the table body at each
  armed id (`x86_helper_dispatch_route_body_refines`), that the selector's
  slots over the armed ids are distinct and exactly `0 .. 6`
  (`x86_helper_dispatch_route_labels_distinct`), and that the routed table
  names the lookup and ktime bodies at the ends
  (`x86_helper_dispatch_route_body_is_table`); the generator rejects a ladder
  that does not switch on the selector or that restates an inline id
  comparison. There is no AArch64 mirror, as the AArch64 call ladder is not
  id-keyed.
  The MOVX source width is likewise no longer open for x86-64 (Step 0133):
  both live `MOVZX`/`MOVSX` bodies (the standalone shared macro
  `X86_SIM_L_EXEC_MOVX_REG` and the routed `X86_OP_MOVZX_REG`/`X86_OP_MOVSX_REG`
  arm) now resolve the width they widen at through the generated,
  static-asserted, machine-checked `KPROG_X86_MOVX_SRC_WIDTH` selector instead
  of an inline `(AUX) ? (AUX) : __x86_l_width` fallback, so the source-width
  resolution the bodies rely on is a proved contract rather than a restated
  ternary. The resolution reads the decoded `aux` field and falls back to the
  body's effective (FLAGS-resolved) width only when that field is absent
  (`0`), re-deriving the four width codes from the public `x86_width_spec.json`
  kernel so the contract is stated against the width names the rest of the
  simulator uses; `X86MovxShape.lean` proves it refines the independent
  `x86MovxSrcWidthSpec` (`x86_movx_src_width_refines`), is the identity on
  every real width (`x86_movx_src_width_identity_on_width`), resolves an absent
  field to the effective width (`x86_movx_src_width_absent_refines`,
  `..._field_is_aux`), covers exactly the four width codes
  (`x86_movx_src_width_codes_refine`), and composes with the width kernel so a
  resolved source width is never the absent code
  (`x86_movx_src_width_composed_is_width`, `..._matches_handler`); the selector
  is a plain ternary so it is usable from a `_Static_assert`, and the generator
  rejects a body that does not route through it or that restates the inline
  fallback. There is no AArch64 mirror, as the AArch64 register-MOV selects its
  width by typed operand rather than a decoded fallback code.
  The x86-64 condition-mnemonic decode is likewise no longer wholly open
  (Step 0134): the artifact encoder's 36 `jcc`/`cmovcc`/`setcc` condition
  mnemonics were a literal `CC_AUX` dict restating each mnemonic's
  `X86_CC_*` token; they are now generated from `x86_cc_decode_spec.json` into
  the encoder mapping, the C `generated/x86_cc_decode.h`, and Lean. The
  generator re-reads `x86_cond_spec.json` on every `--check` and rejects a
  suffix that names no condition, so the encoder's 12 suffixes are exactly the
  condition contract's names minus the parity pair `o`/`no`. `X86CcDecode.lean`
  proves the generated `(mnemonic, token, code)` projection equal to an
  independent enumeration (`x86_cc_decode_refines`), each code equal to the
  condition contract's code (`x86_cc_decode_code_matches_cond`), the reached
  suffixes exactly the non-parity names (`x86_cc_decode_suffixes_exact`), and
  the mnemonic = family + suffix composition
  (`x86_cc_decode_mnemonic_composition`); the generated C selector is a plain
  ternary so it is `_Static_assert`-usable, and the host oracle drives it over
  every suffix code, an out-of-range slice, and the parity absence. The operand
  text and the rest of the parser remain boundaries.
- Open on the AArch64 side: parser/register-number and packed-AUX field
  selection beyond typed operands, including CCMP condition/fallback decoding.
  The generic immediate/register
  ALU handler is now composed by `arm64_alu_handler_refines`: it covers the
  pointer-preserving 64-bit ADD path, scalarized arithmetic writeback, width
  narrowing, and GPR/SP/XZR/NONE destinations after typed operands are supplied;
  `arm64_alu_operand_handler_refines` further composes immediate/register mode
  selection and all eleven source modifiers into that theorem.
  The ALU flag op-step half is separately proved by `arm64_add_step_refines`,
  `arm64_sub_step_refines`, and `arm64_logic_step_refines`; the arithmetic
  handler theorem composes ADDS/SUBS writeback and CMN/CMP no-write behavior;
  `arm64_logic_flag_handler_refines` separately composes ANDS/BICS writeback
  and TST/TST-BIC no-write behavior over the AND/BIC families, and
  `arm64_ccmp_handler_refines` composes all supported conditions with the
  compare/fallback flag paths while preserving register/SP state.
  The AArch64 condition-mnemonic decode is likewise no longer wholly open
  (Step 0135): the artifact encoder's 17 condition mnemonics were a literal
  `COND` dict restating each mnemonic's `ARM64_COND_*` token; they are now
  generated from `arm64_cc_decode_spec.json` into the encoder mapping, the C
  `generated/arm64_cc_decode.h`, and Lean. The generator re-reads
  `arm64_cond_spec.json` on every `--check` and rejects a mnemonic that names
  no condition; the 15 canonical mnemonics name every condition exactly once
  and the aliases `hs`/`lo` name the same conditions as `cs`/`cc`, so 17
  mnemonics cover 15 distinct codes. `Arm64CcDecode.lean` proves the generated
  `(mnemonic, token, code)` projection equal to an independent enumeration
  (`arm64_cc_decode_refines`), each code equal to the condition contract's code
  (`arm64_cc_decode_code_matches_cond`), the reached conditions exactly the
  contract's fifteen (`arm64_cc_decode_conds_exact`), the canonical mnemonics
  covering each condition once (`arm64_cc_decode_canonical_covers`), and the
  alias set and alias-equal-code facts; the generated C selector is a plain
  ternary so it is `_Static_assert`-usable, and the host oracle drives it over
  every mnemonic code, an out-of-range slice, and the alias facts. Assembly
  parsing and the rest of the textual mnemonic remain boundaries.
  The AArch64 BPF helper-ident contract is likewise no longer wholly open
  (Step 0136): the artifact encoder's 61 BPF helper-ident rows were a
  literal `HELPER_IDENTS` dict restating each kernel id's helper name, with
  no shared contract binding that table to the simulator's
  `ARM64_SIM_BPF_CALL_*` bodies or the per-program compact helper table the
  encoder emits (which renumbers a program's called helpers to their
  1-based lexicographic rank over the used names); the five sim-header
  forwarding macros additionally pin that rank for their targets. A drift
  in any artifact was not observable. This step generates the table from
  `arm64_helper_idents_spec.json` into the encoder's Python
  `generated_arm64_helper_idents.py`, the C `generated/arm64_helper_idents.h`
  (`KPROG_ARM64_HELPER_ROW` by-id selector, the out-of-range default, and the
  five `KPROG_ARM64_HELPER_DELEGATE_*` compact-slot pins), and
  `KProgFormal/GeneratedArm64HelperIdents.lean`. The generator re-reads the
  simulator header on every `--check` and rejects a row whose name is not a
  sim-header body macro, a duplicate id or name, and a forwarding target that
  names no source or target macro. `Arm64HelperIdents.lean` proves the
  generated `(id, name)` projection equal to an independent enumeration
  (`helper_idents_refines`), the names pairwise distinct
  (`helper_idents_names_nodup`), the ids strictly increasing
  (`helper_idents_ids_strictly_increasing`), each forwarding target's pinned
  compact slot equal to its 1-based lexicographic rank over the full
  61-name table (`helper_delegate_ranks`), and every name's own slot equal
  to its rank (`helper_slot_ranks`); the 69-case host oracle drives the
  generated row selector over every kernel id, the out-of-range default, the
  two counts, and the five forwarding slots against an independent
  restatement, and the encoder now imports the generated table instead of
  the deleted literal dict. 29 binding mutations---five spec distortions,
  two simulator-body macro add/remove and a retargeted forwarding macro, two
  generator-table changes, five generated-C header distortions, two
  generated-Lean changes, four hand-refinement changes, three encoder-table
  changes, an encoder-import rename, two regenerated generator/render
  drifts, and two genuine-equivalence rewrites---each of the first 27
  changes the oracle, the generator check, or a refinement theorem, while
  the last two are equivalences the proof correctly does not flag. The
  `KPROG_ARM64_HELPER_ROW` out-of-range default and the sim-header body
  macros remain boundaries.
  The AArch64 stack *write* slot-tag action selection is likewise no longer
  open (Step 0137): the simulator's `ARM64_SIM_L_STACK_WRITE_TAG` write
  helper selected between three slot-tag actions from a closed pair of
  facts --- the qword write and tag store exactly when the access is
  64-bit and the slot is 8-aligned, the aligned tag clear and byte-ladder
  write at every aligned sub-qword access, and the plain byte write
  otherwise --- with the hand `KPROG_ARM64_STACK_TAG(` gate and the
  three-arm selection living only in the write-helper body. A drift in
  the action selection was not observable. This step generates the 3-way
  selector from `arm64_stack_write_tag_action_spec.json` into the C
  `generated/arm64_stack_write_tag_action.h` (the
  `KPROG_ARM64_STACK_WRITE_TAG_ACTION` plain-ternary selector, the
  action-code defines, and the count, distinctness, and selection
  `_Static_assert`s) and `KProgFormal/GeneratedArm64StackWriteTagAction.lean`,
  and routes the live write helper through the generated selector,
  removing the hand gate from the write path (Step 0137 delta from 0124,
  which kept a hand gate plus a parallel contract); the read-side
  slot-tag helper still uses the hand gate. `Arm64StackWriteTagActionShape.lean`
  proves the generated selector equal to an independent literal over
  every fact pair (`arm64_stack_write_tag_action_refines`), the name and
  code tables against independent enumerations, the code round-trip and
  out-of-range facts, the three distinct storage effects, the four-case
  dispatch, the write word/tag arm equal to the read-side
  `KPROG_ARM64_STACK_TAG` predicate over the same fact pair
  (`arm64_stack_write_tag_action_matches_read_tag`), the word arm's qword
  write equal to the 0124 width-64 active-lane footprint
  (`arm64_stack_write_tag_action_word_writes_full_qword`), and both byte
  actions' footprint equal to the width's active byte lanes
  (`arm64_stack_write_tag_action_byte_footprint`); the 15-case host oracle
  drives the generated selector against an independent 3-way restatement,
  and the route oracle drives the real write through the generated
  selector against an independent byte-image and slot-tag model over a
  20000-iteration sweep with the read-back through the real read helper
  (9084766 cases). 30 binding mutations --- five specification
  distortions, four generator-table changes, a sim-header
  selector-to-hand-gate revert, five generated-C header distortions
  (including the regenerated generator/render drift), six generated-Lean
  changes (including the regenerated generator/render drift), five
  hand-refinement changes, and two sim-header write inversions --- each
  of the first 28 changes the oracle, the generator check, or a
  refinement theorem, while the last two genuine-equivalence rewrites are
  the two the proof correctly does not flag. The out-of-range width codes
  and the byte-ladder lanes remain boundaries.
  The AArch64 stack slot tag read source is likewise no longer open
  (Step 0138): the simulator's `ARM64_SIM_L_STACK_READ_TAG` read helper
  returned the tag of a stack slot read from a closed pair of facts ---
  the slot's word in the per-slot tag array when the read is 64-bit and
  the slot is 8-aligned, the scalar marker otherwise --- with the
  read-side `KPROG_ARM64_STACK_TAG(` slot-tag predicate as the inline
  gate and the 2-way source selection living only in the read-helper
  body. A drift in the source selection was not observable. This step
  generates the 2-way source selector from
  `arm64_stack_read_tag_source_spec.json` into the C
  `generated/arm64_stack_read_tag_source.h` (the
  `KPROG_ARM64_STACK_READ_TAG_SOURCE` plain-ternary selector, the
  source-code defines, and the count, distinctness, and selection
  `_Static_assert`s) and `KProgFormal/GeneratedArm64StackReadTagSource.lean`,
  and routes the live read helper through the generated selector,
  removing the hand gate from the read path; the write-side routing of
  Step 0137 is unchanged. `Arm64StackReadTagSourceShape.lean` proves the
  generated selector equal to an independent literal over every fact
  pair (`arm64_stack_read_tag_source_refines`), the name and code tables
  against independent enumerations, the code round-trip and out-of-range
  facts, the two distinct storage effects, the four-case dispatch, the
  read stack-tag-array source equal to the read-side
  `KPROG_ARM64_STACK_TAG` predicate over the same fact pair
  (`arm64_stack_read_tag_source_matches_read_tag`), and the read
  stack-tag-array source firing exactly where the Step 0137 write
  helper's word-and-tag action fires
  (`arm64_stack_read_tag_source_matches_write_word_arm`); the 15-case
  host oracle drives the generated selector against an independent
  2-way restatement, and the route oracle drives the real read through
  the generated selector against an independent slot-tag-array and
  byte-image model over a 20000-iteration sweep with each write commit
  mirrored into the model (60142 cases). 33 binding mutations --- five
  specification distortions, four generator-table changes, a
  sim-header selector-to-hand-gate revert, seven generated-C header
  distortions (including the regenerated generator/render drift), seven
  generated-Lean changes (including the regenerated generator/render
  drift), five hand-refinement changes, and two sim-header read
  inversions --- each of the first 31 changes the oracle, the
  generator check, or a refinement theorem, while the last two
  genuine-equivalence rewrites are the two the proof correctly does not
  flag. The out-of-range source codes remain boundaries.
  The AArch64 BPF helper-argument pointer source is likewise no longer open
  (Step 0139): the simulator's `ARM64_SIM_L_HELPER_ARG_PTR` helper resolved
  the pointer a BPF helper call receives in a register argument from a single
  closed fact --- whether the argument register's provenance tag is the stack
  tag: the stack arena pointer at the register pointer's biased arena index
  when the register is stack tagged, the register's raw pointer otherwise ---
  with the `ARM64_SIM_L_REG_TAG(REG) == ARM64_SIM_TAG_STACK ?` hand ternary
  as the inline gate and the 2-way source selection living only in the helper
  body. A drift in the source selection was not observable. This step
  generates the 2-way source selector from `arm64_helper_arg_ptr_spec.json`
  into the C `generated/arm64_helper_arg_ptr.h` (the
  `KPROG_ARM64_HELPER_ARG_PTR_BODY` plain-ternary selector, the source-code
  defines, and the count, distinctness, exact-code, and selection
  `_Static_assert`s) and `KProgFormal/GeneratedArm64HelperArgPtr.lean`, and
  routes the live helper through the generated selector, removing the hand
  gate from the helper path; the stack-read and stack-write routings of Steps
  0138/0137 are unchanged. `Arm64HelperArgPtrShape.lean` proves the generated
  selector equal to an independent literal over every fact value
  (`arm64_helper_arg_ptr_refines`), the name and code tables against
  independent enumerations, the code round-trip and out-of-range facts, the
  two distinct storage effects, the two-case dispatch, the
  stack-arena-pointer arm firing exactly on the stack-tag fact
  (`arm64_helper_arg_ptr_source_selects_stack`), and the arena byte the
  stack-arena-pointer arm addresses equal to the 0112 stack index contract
  (`arm64_helper_arg_ptr_stack_index`, tying `index 96 off` to
  `(ptrIndex 96 off).truncate 32`); the 14-case host oracle drives the
  generated selector against an independent 2-way restatement, and the route
  oracle declares the full register file and stack, plants each register's
  pointer and provenance tag, and drives the real helper over every
  general-purpose register and every provenance class plus the stack pointer
  against an independent model of the selection (786 cases). 36 binding
  mutations --- six specification distortions, four generator-table changes,
  two sim-header selector reverts, six generated-C header distortions
  (including the regenerated generator/render drift), six generated-Lean
  changes (including the regenerated generator/render drift), five
  hand-refinement changes, and two sim-header helper inversions --- each of
  the first 33 changes the oracle, the generator check, or a refinement
  theorem, while the last three genuine-equivalence rewrites are the three
  the proof correctly does not flag. The out-of-range source codes remain
  boundaries.
  The AArch64 memory base-address source is likewise no longer open
  (Step 0140): the simulator's scalar memory access helpers
  `ARM64_SIM_L_MEM_READ`, `ARM64_SIM_L_MEM_READ_TAG`, and
  `ARM64_SIM_L_MEM_WRITE` each resolved the arena base address of a
  stack-arena access from a single closed fact --- whether the base register
  is the stack pointer: the stack pointer register when the base is the
  stack pointer, the base register's own arena pointer otherwise --- with the
  `(BASE) == ARM64_SP ? __a64_sp` hand ternary as the inline gate repeated
  verbatim at three body sites, so a drift in any one of them was not
  observable. This step generates the 2-way source selector from
  `arm64_mem_base_src_spec.json` into the C
  `generated/arm64_mem_base_src.h` (the `KPROG_ARM64_MEM_BASE_SRC`
  plain-ternary selector, the source-code defines, and the count,
  distinctness, exact-code, and selection `_Static_assert`s) and
  `KProgFormal/GeneratedArm64MemBaseSrc.lean`, and routes all three bodies
  through the generated selector, removing the hand gate from the helper
  path; the offset contract, the arm/source selection of Step 0123, and the
  stack-read/stack-write routings of Steps 0138/0137 are unchanged.
  `Arm64MemBaseSrcShape.lean` proves the generated selector equal to an
  independent literal over every fact value
  (`arm64_mem_base_src_refines`), the name and code tables against
  independent enumerations, the code round-trip and out-of-range facts, the
  two distinct storage effects, the two-case dispatch, the stack-pointer arm
  firing exactly on the base-is-SP fact
  (`arm64_mem_base_src_selects_sp`), and the two cross-contracts tying the
  source to the 0123 store-body selection
  (`arm64_mem_base_src_matches_write_arm`) and to the 0121 read value source
  (`arm64_mem_base_src_matches_read_src`); the 15-case host oracle drives the
  generated selector against an independent 2-way restatement over the real
  computed register-is-32 fact, and the route oracle declares the full
  register file and stack, plants the stack pointer and a stack-tagged
  register's pointer at distinct arena indices, and drives the real read,
  read-tag, and write helpers at both base-address sources over every width
  and several value patterns against an independent base-address model
  (205324 cases). 36 binding mutations --- six specification distortions,
  four generator-table changes, two sim-header selector reverts, six
  generated-C header distortions (including the regenerated
  generator/render drift), six generated-Lean changes (including the
  regenerated generator/render drift), five hand-refinement changes, and two
  sim-header helper inversions --- each of the first 33 changes the oracle,
  the generator check, or a refinement theorem, while the last three
  genuine-equivalence rewrites are the three the proof correctly does not
  flag. The out-of-range source codes remain boundaries.
  The AArch64 vector memory step's per-lane extra offset is likewise no
  longer open (Step 0141): the shared step `ARM64_SIM_L_DQ_MEM_STEP` moves
  the SIMD register's halves to or from memory one lane at a time and
  computed each moved lane's *extra* byte offset by hand through a nested
  ternary on `__a64_vreg_p == 0U` (is this the first plan position) and
  `__a64_dq_lanes > 1U` (does the transfer have a high lane at all),
  yielding `0 / 8 / 0` --- the first-lane offset zero, one 64-bit lane
  stride for the `.Q0` transfer's second position, and the base offset zero
  when the plan has a single position. This step generates the 3-way offset
  selector from `arm64_dq_mem_extra_spec.json` into the C
  `generated/arm64_dq_mem_extra.h` (the `KPROG_ARM64_DQ_MEM_EXTRA`
  plain-ternary selector, the outcome-code and byte-offset defines, and the
  count, distinctness, exact-code, high-lane-stride, base-offset, and
  fact-pair selection `_Static_assert`s) and
  `KProgFormal/GeneratedArm64DqMemExtra.lean`, and routes the step through
  the generated selector, removing the hand nested ternary from the step;
  the DQ lane plan, the vector half plan of Step 0143, the offset contract,
  and the base-address source of Step 0140 are unchanged.
  `Arm64DqMemExtraShape.lean` proves the generated selector equal to an
  independent 3-way literal over every fact pair
  (`arm64_dq_mem_extra_refines`), the name and code tables against
  independent enumerations, the code round-trip and out-of-range facts, the
  three distinct plan effects, the four-case dispatch, the high-lane arm
  firing exactly on the closed ordered fact pair
  (`arm64_dq_mem_extra_selects_high_lane`), the three offsets' distinctness,
  and the two cross-contracts tying the high-lane offset to the 0141 DQ lane
  stride (`arm64_dq_mem_extra_matches_dq_stride`, `GeneratedArm64DqMem.transfer`
  at lane 1 for both the `.Q0` load and store) and to the 0143 vector half
  offset (`arm64_dq_mem_extra_matches_vreg_half`,
  `GeneratedArm64Vreg.halfOffset`) with the two contracts agreeing on the
  half plan for all four opcodes; the 21-case host oracle drives the
  generated selector against an independent 3-way restatement over both
  facts and the four opcode lanes, and the route oracle declares the full
  register file and stack, plants the base registers' pointers and
  provenance tags, and drives the real step in both directions over every
  opcode, base class, pre/post flag combination, index mode, and several
  immediates against an independent model that walks the lane plan
  position-by-position and recomputes each position's extra offset from its
  own fact pair (62424 cases), so a dropped or added high-lane offset is
  numerically distinguishable. 48 binding mutations --- six specification
  distortions, eleven generator-table changes, sixteen generated-C header
  distortions (including the two regenerated generator/render drifts),
  thirteen generated-Lean changes (including the regenerated
  generator/render drift), six hand-refinement changes, and three
  sim-header selector reverts --- each of the first 45 changes the oracle,
  the generator check, or a refinement theorem, while the last three
  genuine-equivalence rewrites are the three the proof correctly does not
  flag.
  The AArch64 memory address offset's index-value source is likewise no
  longer open (Step 0142): the offset `ARM64_SIM_L_MEM_BASE_OFF` computes
  the byte displacement a load/store adds to its base register, and while
  its index *presence* was already generated (Step 0102) it still picked
  the *value* the present index register contributes by hand through a
  ternary on the computed `__a64_mbo_has_index` fact --- the
  source-modified index register value when the addressing mode carries an
  index register, a literal zero when it does not (the sentinel index
  operand `ARM64_REG_NONE`). This step generates the 2-way index-value
  source selector from `arm64_mem_index_value_spec.json` into the C
  `generated/arm64_mem_index_value.h` (the `KPROG_ARM64_MEM_INDEX_VALUE`
  plain-ternary selector, the `…_REGISTER` / `…_ZERO` source codes, and the
  count, distinctness, exact-code, and fact/value selection
  `_Static_assert`s) and `KProgFormal/GeneratedArm64MemIndexValue.lean`, and
  routes the offset body through the generated selector while still calling
  `ARM64_SIM_L_MOD_VALUE((INDEX), …)` as the register source's argument, so
  the hand ternary is out of the body; the index-presence contract of Step
  0102, the writeback-suppress decode, the offset contract, the
  base-address source of Step 0140, and the pre/post step are unchanged.
  `Arm64MemIndexValueShape.lean` proves the generated selector equal to an
  independent 2-way literal over the one fact
  (`arm64_mem_index_value_refines`), the name and code tables against
  independent enumerations, the code round-trip and out-of-range facts, the
  two distinct effects, the two-case dispatch, the register source firing
  exactly on the has-index fact (`arm64_mem_index_value_selects_register`),
  the agreement with the 0102 presence fact on the same byte fact
  (`arm64_mem_index_value_matches_present`, `GeneratedArm64MemIndex.present`),
  and the two cross-contracts tying the register source to the index
  register *value* the offset consumes
  (`arm64_mem_index_value_register_is_index`) and tying the selected source
  to `GeneratedArm64MemOffset.value`'s index argument for both the pre/post
  and the plain offset forms (`arm64_mem_index_value_matches_offset`); the
  17-case host oracle drives the compiled selector over both raw presence
  facts and the sentinel's neighbours against an independent 2-way
  restatement, and the 3015-case route oracle declares the full register
  file and stack, seeds every general register with a distinct
  per-register pattern, plants a nonzero value at each candidate index
  register, and drives the real offset over every index operand, AUX index
  lane, flag byte, register value and immediate against an independent
  model that restates the presence fact, the index-value source selection,
  and the immediate suppression from the raw `AUX` word, so a collapsed
  selection or a swapped pair of arms is numerically distinguishable. 42
  binding mutations --- six specification distortions, four
  generator-table changes, twelve generated-C header distortions
  (including the two regenerated generator/render drifts), twelve
  generated-Lean changes (including the regenerated generator/render
  drift), seven hand-refinement changes, and three sim-header selector
  reverts/swaps --- each of the first 39 changes the oracle, the generator
  check, or a refinement theorem, while the last three genuine-equivalence
  rewrites are the three the proof correctly does not flag.
  The AArch64 vector memory step's half state-field selection is likewise no
  longer open (Step 0143): the shared step `ARM64_SIM_L_DQ_MEM_STEP` moves
  each moved lane into or out of one of the SIMD register's two half state
  fields (`__a64_v0` / `__a64_v0_hi`), and while the lane's *offset* was
  already generated (Step 0141) it still picked the *field* that offset lands
  in by hand on both the load and the store arm through
  `if (__a64_vreg_off == (__s64) KPROG_ARM64_VREG_HIGH_OFFSET)`. This step
  generates the 2-way field selector from `arm64_vreg_field_spec.json` into
  the C `generated/arm64_vreg_field.h` (the `KPROG_ARM64_VREG_FIELD`
  plain-ternary selector, the `…_LOW_FIELD` / `…_HIGH_FIELD` field codes, and
  the count, distinctness, exact-code, and half-offset/fact selection
  `_Static_assert`s) and `KProgFormal/GeneratedArm64VregField.lean`, and
  routes the step through the generated selector on both arms, so the two
  hand offset tests are out of the body; the DQ lane plan of Step 0141, the
  per-lane extra offset, the offset contract, the base-address source of Step
  0140, and the pre/post step are unchanged.
  `Arm64VregFieldShape.lean` proves the generated selector equal to an
  independent 2-way literal over the one fact
  (`arm64_vreg_field_refines`), the field-name and field-code tables against
  independent enumerations, the code round-trip and out-of-range facts, both
  distinct effects, the two-case dispatch, that the high field is named
  exactly on the fact (`arm64_vreg_field_selects_high_field`), and the
  cross-contracts tying the selection to the 0054 vector half plan for every
  half (`arm64_vreg_field_matches_vreg_half`,
  `arm64_vreg_field_matches_vreg_plan`,
  `arm64_vreg_field_offsets_are_half_offsets`), so the field selection and
  the half plan cannot disagree about which state field a lane lands in; the
  7-case host oracle drives the compiled selector over the raw computed
  offset against an independent 2-way restatement, and the 62427-case route
  oracle declares the full register file and stack, plants the base
  registers' pointers and provenance tags, and drives the real step in both
  directions over every opcode, base class, pre/post flag combination, index
  mode, and several immediates against an independent model that restates
  the half-field selection from the raw offset, so a body that always wrote
  one field, or swapped the two fields, is numerically distinguishable. 44
  binding mutations --- six specification distortions, five generator-table
  changes, nine generated-C header distortions (including the two
  regenerated generator/render drifts), five generated-Lean changes, seven
  hand-refinement changes, and six sim-header selector
  reverts/swaps/neutralizations --- each of the first 41 changes the oracle,
  the generator check, or a refinement theorem, while the last three
  genuine-equivalence rewrites are the three the proof correctly does not
  flag.

  The AArch64 write-register width body-selection is likewise no longer open
  (Step 0144): the writeback body `ARM64_SIM_L_WRITE_REG_WIDTH` --- the body
  every GPR write routes through --- first masks the value to the access width
  through `KPROG_ARM64_APPLY_WIDTH` (the Step-0075 `arm64_width.h` contract) and
  then picked, by hand from the single closed fact of whether the width code is
  the 32-bit code, the narrow truncating body
  (`ARM64_SIM_L_WRITE_REG32_CASE`, storing `(__u32)__a64_l_next`) vs the
  full-value body (`ARM64_SIM_L_WRITE_REG64_CASE`, storing `__a64_l_next`)
  through `if ((WIDTH) == ARM64_WIDTH_32)`. This step generates the 2-way
  selector from `arm64_write_arm_spec.json` into the C
  `generated/arm64_write_arm.h` (the `KPROG_ARM64_WRITE_ARM` plain-ternary
  selector, the `…_FULL` / `…_NARROW` arm codes, and the count, distinctness,
  exact-code, and per-width selection `_Static_assert`s) and
  `KProgFormal/GeneratedArm64WriteArm.lean`, and routes the body through the
  generated selector, so the hand width test is out of the body; the `SP`
  branch, the destination-presence guard, the pre-truncation step, and the
  pointer-writeback helper `ARM64_SIM_L_WRITE_REG_PTR` are unchanged. Because
  the value is masked to the width before the body choice, the two bodies are
  observationally equal for every width the simulator reaches, so the split is
  a genuine no-op on state and only a wrong selector code or a swapped body
  assignment is observable. `Arm64WriteArmShape.lean` proves the generated
  selector equal to an independent 2-way literal over the width fact
  (`arm64_write_arm_refines`), the arm-name and arm-code tables, the code
  round-trip and out-of-range facts, both bodies, the 32-bit literal's binding
  to the width contract's own code (`arm64_write_arm_w32_spec_bound`), the
  per-width map of `[w8, w16, w32, w64]` to `[full, full, narrow, full]`
  (`arm64_write_arm_over_widths`), the two-case dispatch, and that the narrow
  body is selected exactly at the width the pre-truncation step masks to 32 bits
  (`arm64_write_arm_narrow_matches_pre_truncation`), so the body choice and the
  pre-truncation cannot disagree about which width truncates; the 260-case host
  oracle drives the compiled selector over the raw width fact against an
  independent 2-way restatement, and the 6401-case route oracle seeds every GPR
  and drives the real writeback body over the full register-number range, all
  four width codes, and several values against an independent model that masks
  first and then truncates exactly when the width code is the 32-bit code, so a
  wrong selector code or a swapped body assignment is numerically
  distinguishable. 42 binding mutations --- six specification distortions, six
  generator-table changes, nine generated-C header distortions (including the
  two regenerated generator/render drifts), seven generated-Lean changes, seven
  hand-refinement changes, and three sim-header selector
  reverts/swaps/neutralizations --- each of the first 38 changes the oracle, the
  generator check, or a refinement theorem, while the last four
  genuine-equivalence rewrites are the four the proof correctly does not flag.

  The x86-64 write-register width body-selection is now likewise closed
  (Step 0145): the writeback body `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` --- the body
  every GPR write routes through --- first resolves the decoded operand width
  through the Step-0075 `x86_width_effective` bridge and then picked the
  writeback body by hand from a ladder over the resolved width code: one byte
  lane at the 8-bit code (`X86_SIM_L_WRITE_REG8_VALUE_CASE`), the low word at
  the 16-bit code (`X86_SIM_L_WRITE_REG16_VALUE_CASE`), the low dword at the
  32-bit code (`X86_SIM_L_WRITE_REG32_VALUE_CASE`), and the full qword at every
  other code (`X86_SIM_L_WRITE_REG64_VALUE_CASE`). This step generates the
  4-way width-code selector from `x86_write_width_arm_spec.json` into the C
  `generated/x86_write_width_arm.h` (the `KPROG_X86_WRITE_WIDTH_ARM`
  nested-ternary selector, the four `…_B8`/`…_B16`/`…_B32`/`…_B64` arm codes,
  and the count, distinctness, per-width selection, and absent-code
  `_Static_assert`s) and `KProgFormal/GeneratedX86WriteWidthArm.lean`, and
  routes the body through the generated selector, so the hand width ladder is
  out of the body; the effective-width bridge `X86_SIM_L_EFFECTIVE_WIDTH`, the
  delegating wrapper `X86_SIM_L_WRITE_REG_WIDTH`, and the pointer-writeback
  helpers are unchanged. Unlike Step 0144, the width is applied *inside* each
  body's write macro and `__x86_wr_next` is not pre-masked, so the four bodies
  write the destination register genuinely differently and a wrong selector
  code or a swapped body is observable in the route oracle.
  `X86WriteWidthArmShape.lean` proves the generated selector equal to an
  independent 4-way width-code ladder built on the width contract's own
  `x86WidthCodeSpec` literals (`x86_write_width_arm_refines`), the arm-name and
  arm-code tables, the code round-trip and out-of-range facts, the per-width map
  of `[w8, w16, w32, w64]` to `[b8, b16, b32, b64]`
  (`x86_write_width_arm_over_widths`), each body's width code bound to the width
  contract's own code for that size (`x86_write_width_arm_width_codes`), the
  four distinct bodies and case macros, the width classes, the ladder's
  totality, and that an absent width reaches the default qword body
  (`x86_write_width_arm_default_is_qword`), so the body choice and the resolved
  width cannot disagree; the 258-case host oracle drives the compiled selector
  over the raw resolved width code against an independent 4-way restatement, and
  the 30726-case route oracle declares the full register file and drives the
  real `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` over every GPR, the widths
  `{0, 8, 16, 32, 64, 3}`, the destination shifts `{0, 8}`, and several values
  against an independent model that applies the width inside each body (byte
  lane per shift, word-preserving, zero-extending dword, full qword), so a wrong
  selector code or a swapped body assignment is numerically distinguishable. 37
  binding mutations --- eight specification distortions, six generator-table
  changes, two sim-header selector reverts, five generated-C header
  distortions, five generated-Lean changes, six hand-refinement changes, and one
  sim-header width-test swap --- each change the oracle, the generator check, or
  a refinement theorem, while the last four genuine-equivalence rewrites (two
  generator docstrings, an added hand-module namespace comment, and a no-op
  `(__u64)` cast on the written value) are the four the proof correctly does not
  flag.
  The x86-64 stack byte-ladder per-lane activation is likewise no longer open
  (Step 0146): the simulator's stack write helper `X86_SIM_L_STACK_WRITE` and
  its stack read helper `X86_SIM_L_STACK_READ` narrow a resolved access to the
  byte arena `__x86_stack_mem.b[]` through a little-endian byte ladder whose
  eight lane writes (and eight lane assemblies) were gated by hand-written
  `__x86_stw_width`/`__x86_str_width` `>= X86_WIDTH_16` / `>= X86_WIDTH_32` /
  `== X86_WIDTH_64` tests restated at each lane. This step generates the
  activation from `x86_stack_write_lanes_spec.json` into the C
  `generated/x86_stack_write_lanes.h` (the width's active-lane mask,
  `w8`→`0x01`, `w16`→`0x03`, `w32`→`0x0f`, `w64`→`0xff`, the eight lane-number
  defines, the lane count and slot count, the plain-expression predicate
  `KPROG_X86_STACK_WRITE_LANE_ACTIVE(WIDTH, LANE) =
  ((__u8)((MASK(WIDTH) >> (LANE)) & 1U))`, and the width-code, mask, count and
  per-lane activation `_Static_assert`s) and `KProgFormal/GeneratedX86StackWriteLanes.lean`,
  and routes *both* helpers' ladders through the one generated predicate, so
  the four restated gate blocks are out of both bodies. Unlike the AArch64
  Step 0124 (one write helper), the x86-64 read helper is itself a hand-written
  eight-lane assemble ladder, so the single contract covers both the write and
  the read byte arena access; the resolved width (`__x86_stw_width` /
  `__x86_str_width`, post the `X86_SIM_L_EFFECTIVE_WIDTH` bridge) is the
  predicate's argument, and the byte-window arithmetic and the little-endian
  value composition stay in the bodies.
  `X86StackWriteLanesShape.lean` proves the generated mask-bit activation equal
  to an independent literal construction (`x86_stack_write_lanes_refines`), the
  mask/byte-count/lane-number refinements, the activation's monotonicity
  (`x86_stack_write_lanes_monotone`, an active lane stays active at every wider
  access, exactly the nested `>= 16`/`>= 32`/`== 64` gate structure) and its
  above-width falsehood, and ties the lane set to the `GeneratedX86StackArena`
  byte extraction (`x86_stack_write_lanes_lane_is_byte_lane`), the width codes
  to the `X86Width` contract (`x86_stack_write_lanes_codes_match_width`) and the
  byte counts and codes to the memory-access contract
  (`x86_stack_write_lanes_matches_store_bytes`, the stack and memory byte
  ladders activate the same lanes at every width). The 291-case host oracle
  drives the compiled generated header against an independent literal oracle,
  and the 1401654-case route oracle declares the stack arena and drives the
  real `X86_SIM_L_STACK_WRITE` then `X86_SIM_L_STACK_READ` at every width and
  many arena offsets against independent models of the activation and of the
  little-endian assembly, so a wrong width code, a swapped lane, a dropped gate
  or an ungated lane is numerically distinguishable. 63 binding mutations ---
  eight specification distortions, thirteen generator-anchor changes, ten
  generated-C header distortions, eight generated-Lean changes, nine
  hand-refinement changes, seven sim-header routed-ladder revert/drop/widen
  mutations (both ladders, including a dropped lane-3 gate and an assemble-lane
  swap), and three generator+artifact pair defects regenerated so the
  `--check` stays green --- each change the oracle, the generator check, or a
  refinement theorem, while the five genuine-equivalence rewrites (an added
  include-side comment, an added hand-module comment, a resolved-but-equal
  generator root path, an added generated-Lean import comment, and
  equal-whitespace spec text) are the five the proof correctly does not flag.
  The x86-64 ALU-token flag-body selection is likewise no longer open
  (Step 0147): the simulator's flag-setting entry `X86_SIM_L_SET_ALU_FLAGS`
  picked the flag body by hand from a chain over the sixteen `X86_ALU_*`
  operation codes, whose token→body map is not injective (the ADD and ADC codes
  both reach the add body, the SHL/SHR/SAR/ROL codes all reach the shift body,
  and the INC/DEC families reach the add/sub bodies but then restore the
  incoming carry). This step generates the token→body selection from
  `x86_alu_flag_arm_spec.json` into the C `generated/x86_alu_flag_arm.h` (the
  `KPROG_X86_ALU_FLAG_ARM(ALU)` nested-ternary selector, the ten
  `KPROG_X86_ALU_FLAG_ARM_*` arm codes, the count, the sixteen token-code drift
  checks, distinctness, per-token selection, default and unknown-token
  `_Static_assert`s) and `KProgFormal/GeneratedX86AluFlagArm.lean`, and routes
  the body through the generated selector with the logic body as the default,
  so the hand token ladder is out of the body. The generator cross-checks each
  arm's token defines against the ALU-decode contract (the mnemonic lower-cased
  → `X86_ALU_` + upper), asserts the two collapses and the total coverage of all
  sixteen codes, and re-reads the sim header to require the routed selector, the
  `__x86_l_old_cf` save/restore, the INC/DEC carry restores and the default
  logic body while dropping the hand ladder. `X86AluFlagArmShape.lean` proves
  the generated `armOf` equal to an independent token ladder built on the ALU
  contract's own codes (`x86_alu_flag_arm_refines`), the ten arm-name/flag-body/
  case-macro/effect refinements, the two token collapses (`_collapses`), that
  the carry-restoring arms are exactly the increment/decrement families
  (`_cf_restores`), the token-ladder totality and default, and the code
  round-trip and out-of-range falsehood. The 259-case host oracle drives the
  compiled generated header against an independent per-token oracle, and the
  776162-case route oracle declares the full register file and drives the real
  flag-setting entry over all sixteen tokens, every modeled width and several
  operand triples against an independent per-token model (including the INC/DEC
  carry-preserve behaviour), so a wrong selector code, a swapped body, a dropped
  carry-restore or a dropped token is numerically distinguishable. 36 binding
  mutations --- eight specification distortions, four generator-anchor changes,
  one sim-header selector revert, five generated-C header distortions, five
  generated-Lean changes, six hand-refinement changes, and four sim-header
  routed body/token/operand/carry-restore mutations --- each change the oracle,
  the generator check, or a refinement theorem, while the three
  genuine-equivalence rewrites (a generator docstring, an added hand-module
  comment, and a C case-label space) are the three the proof correctly does not
  flag.

  The x86-64 shift-flag route path is now also machine-checked (Step 0151,
  commit 589f0296b): kprog/formal/test_x86_shift_flags_route_host.c drives
  the real X86_SIM_L_SET_SHIFT_FLAGS wrapper (routed through
  case KPROG_X86_ALU_FLAG_ARM_SHIFT) over 6,504,961 wrapper cases
  (4 shift tokens x 5 widths x 8 lhs x 11 rhs x 7 result values) against an
  independent walk from the generated Lean semantics, pinning count-zero
  preservation, the count-one OF boundary, and the 31/32/63/64 mask-count
  boundaries; the 72-mutation harness catches 69 (gen 22 / lean_chain 30 /
  host 13 / route 4) with 3 equivalence survivors, including the
  count-guard mutant that survives the host grid (no rhs=0 case) and is
  caught by the route grid.

  Remaining work also includes the load/store address and tag paths, with
  the stack slot tag write action and read source and the BPF helper-argument
  pointer source now closed (Steps 0137, 0138, and 0139), the memory
  base-address source now closed (Step 0140), the vector memory step's
  per-lane extra offset now closed (Step 0141), and the memory address
  offset's index-value source now closed (Step 0142), and the vector memory
  step's half state-field selection now closed (Step 0143), and the
  write-register width body-selection now closed (Step 0144), the x86-64
  write-register width body-selection now closed (Step 0145), the x86-64
  stack byte-ladder per-lane activation now closed (Step 0146), the
  x86-64 ALU-token flag-body selection now closed (Step 0147), the
  x86-64 dispatch-family token-membership now closed (Step 0148), and the
  x86-64 dispatch-singleton opcode-membership now closed (Step 0149), and
  x86-64 SHL/SHR/SAR/ROL flag routing now closed (Step 0151), the x86-64
  ALU op-step result composition now closed (Step 0153), and the x86-64
  ALU op-step result route through the real `X86_SIM_L_EXEC_ALU_IMM`/`_REG`
  arm bodies now closed (Step 0154, 760,337 routed cases; the 87-mutation
  harness adds the five body-macro mutants to the Step 0153 count, split
  gen 41 / lean_chain 30 / host 7 / route 5), and the x86-64 ALU op-step
  result route through the routed memory-operand
  `X86_SIM_L_EXEC_ALU_MEM`/`_UNARY`/`_IMM`/`_REG` arm bodies now closed
  (Step 0155, 261,137 routed cases; the 92-mutation harness adds five
  MEM-body mutants to the Step 0154 count, split gen 41 / lean_chain 30 /
  host 7 / route 5 / route_mem 5), and the x86-64 SHIFTX/RORX variable
  shift/rotate op-step bodies route through the real inline SHIFTX/RORX
  dispatcher arm bodies now closed (Step 0156, 5,760 routed cases /
  195,841 comparison points; the 96-mutation harness adds four
  SHIFTX/RORX-body mutants to the Step 0155 count, split gen 41 /
  lean_chain 30 / host 7 / route 5 / route_mem 5 / route_shiftx 4),
  and the x86-64 MOVX move-with-extension op-step body routes through the
  real inline MOVX dispatcher arm bodies now closed (Step 0157, 720 routed
  cases / 23,761 comparison points; the 100-mutation harness adds four
  MOVX-body mutants to the Step 0156 count, split gen 41 / lean_chain 30 /
  host 7 / route 5 / route_mem 5 / route_shiftx 4 / route_movx 4),
  and the x86-64 multiply op-step bodies route through the real inline
  IMUL immediate and memory-immediate dispatcher arm bodies now closed
  (Step 0158, 7,680 routed cases / 261,121 comparison points; the
  104-mutation harness adds four IMUL-body mutants to the Step 0157 count,
  split gen 41 / lean_chain 30 / host 7 / route 5 / route_mem 5 /
  route_shiftx 4 / route_movx 4 / route_imul 4),
  and the x86-64 effective-address op-step body routes through the real
  inline LEA dispatcher arm body now closed (Step 0159, 960 routed
  cases / 32,641 comparison points; the 108-mutation harness adds
  four LEA-body mutants to the Step 0158 count, split gen 41 /
  lean_chain 30 / host 7 / route 5 / route_mem 5 / route_shiftx 4 /
  route_movx 4 / route_imul 4 / route_lea 4),
  and the x86-64 MOV immediate/register op-step bodies route through the
  real MOV dispatcher singleton arm bodies now closed (Step 0160, 640
  routed cases / 21,764 comparison points; the 112-mutation harness adds
  four MOV-body mutants to the Step 0159 count, split gen 41 /
  lean_chain 30 / host 7 / route 5 / route_mem 5 / route_shiftx 4 /
  route_movx 4 / route_imul 4 / route_lea 4 / route_mov 4),
  and the x86-64 BSWAP op-step body routes through the real inline BSWAP
  dispatcher arm body now closed (Step 0161, 200 routed cases / 6,802
  comparison points; the 116-mutation harness adds four BSWAP-body
  mutants to the Step 0160 count, split gen 41 / lean_chain 30 / host 7 /
  route 5 / route_mem 5 / route_shiftx 4 / route_movx 4 / route_imul 4 /
  route_lea 4 / route_mov 4 / route_bswap 4),
  and the x86-64 PUSH/POP stack-transfer op-step body routes through the
  real inline PUSH/POP stack-transfer dispatcher arm bodies now closed
  (Step 0162, 900 routed cases / 31,504 comparison points; the
  46-mutation harness adds the PUSHPOP family across all four detectors
  with 13 sim-header step-macro mutants (11 route-caught plus the
  Step 0120 hand stack-write-guard reintroduction and the unchanged-step
  restatement that survive as genuine route-equivalents), split
  gen 19 / lean_chain 9 / host 3 / route 11 with four genuine
  equivalences surviving),
  and the x86-64 XCHG width-keyed arm-selection op-step body routes
  through the real generated-arm dispatcher arm body now closed
  (Step 0163, 1,280 routed cases / 62,725 comparison points; the
  69-mutation harness adds the XCHG family across three detectors
  with 10 sim-header arm-body mutants, all 10 route-caught -- the
  pointer-arm `READ_REG_PTR`-to-`READ_REG` drop was reclassified a
  genuine route-equivalent because the two macros expand identically,
  and the two read-drift rows now read the neighbouring register
  cell -- and the two generator macro-name drops were retargeted from
  `--check` to the routed grid since the generated macros are
  whitespace-collapsed in the sim-header arm region, split
  gen 38 / lean_chain 14 / route 13 with four genuine equivalences
  surviving: the pointer-macro argument parenthesis, the
  selector-line whitespace repaint absorbed by the generator's
  arm-region collapse, a hand-Lean comment, and the generator `ROOT`
  spelling),
  the vector/`.D0`/`.Q0` paths,
  and the x86-64 `DIV` resolved-width case-dispatch arm family routes
  through the real generated-arm dispatcher body now closed (Step 0164,
  1,470 routed cases / 48,515 comparison points; the 90-mutation harness
  adds the four quotient/remainder arms across three detectors with 12
  sim-header arm-body mutants, all 12 route-caught --- the three operand
  reads drifted to neighbouring cells, the byte pack-order/target/width
  drifts, the word pair write-target, the dword window/truncation/width
  drifts, the qword gate flip and tautology gate, and the overflow-default
  drifts --- and one generator constant row retargeted from `--check` to
  the Lean chain because a renamed effect string is invisible to the
  routed grid until it breaks `x86_div_effects`, split
  gen 41 / lean_chain 27 / route 18 with four genuine equivalences
  surviving: a register-read argument parenthesis, a default-arm
  whitespace repaint absorbed by the generator's arm-region collapse, a
  hand-Lean comment, and the generator `ROOT` spelling),
  and the AArch64 `CNT`/`UADDLV` byte-lane reduction value family
  routes through the real generated-reduction macro now closed
  (Step 0165, 20,017-case generated-header oracle; the 61-mutation
  harness adds the two reduction opcodes across three detectors with
  2 sim-header opcode-source mutants, both gen-caught --- the two
  `ARM64_OP_{CNT,UADDLV}` define-line drifts plus the reduced
  lane-mask, lane-shift, and case-label drifts and the switch/default
  runes --- and four genuine equivalences surviving: the generator
  comment, the sim-header define spacing, a hand-Lean comment, and
  the generator `ROOT` spelling),
  and the AArch64 `MVN`/`NEG` unary value family got the same
  mutation build-out against the host 40,081-case generated-header oracle
  (Step 0166; three detectors, no route detector because the family has no
  route test --- the wrapper body `ARM64_SIM_L_UNARY_VALUE` is reached only
  through the host test; the 59-mutation harness mutates the two unary
  opcodes across the spec, generator, generated C and Lean, hand
  refinement, and the `ARM64_OP_{MVN,NEG}` sim-header define lines with 2
  sim-header opcode-source mutants both gen-caught, plus the arm-body,
  case-label, handled-disjunct, width-mask-call, switch/default, and seed
  drifts --- and four genuine equivalences surviving: the generator
  comment, a hand-Lean comment, the generator `ROOT` spelling, and the
  spec-whitespace repaint; the result-seed row retargeted from the host
  oracle to the generator comparator because the seed is absorbed by the
  unconditional arm assign, split
  gen 27 / lean_chain 15 / host 13),
  and the AArch64 `EXTR`/`REV`/`REV16`/`SXTH`/`SXTW`/`SXTB` value family
  got the six-opcode mutation build-out against the host 120,145-case
  generated-header oracle (Step 0167; three detectors, no route detector
  because the family has no route test --- the wrapper body
  `ARM64_SIM_L_EXTREV_VALUE` is reached only through the host test; the
  132-mutation harness mutates the six opcodes across the spec, generator,
  flags spec, generated C and Lean, hand refinement, and the
  `ARM64_OP_*` sim-header define lines with 2 flag-family rejections and
  6 sim-header opcode-source mutants both gen-caught, plus the arm-body,
  case-label, handled-disjunct, width-mask-call, switch/default, and
  sign-extension drifts --- split
  gen 62 / lean_chain 30 / host 32 with four genuine equivalences
  surviving (the generator comment, a hand-Lean comment, the generator
  `ROOT` spelling, and the spec-whitespace repaint) plus four
  detector-invisible rows kept as survivors: the generated-C `REV32`
  result seed absorbed by every arm's unconditional assign, both
  generated-Lean mnemonic rows with no chain consumer, and one hand-Lean
  case-split row whose mutated mask still proves the unchanged theorem),
  and the AArch64 `CNEG`/`ORN_REG` pair got a combined two-family
  mutation harness against both the 40,097- and the 40,401-case host
  oracles (Step 0168; three detectors across ten files --- the gen
  detector runs both generator `--check` rows, the Lean chain both
  family pairs, the host compiles/runs both oracles, and there is no
  route detector; the 78-mutation harness mutates both shared specs,
  both generators, both generated C and Lean tables, both hand
  refinements, and both `ARM64_OP_*` sim-header define lines --- split
  gen 26 / lean_chain 25 / host 19 with three genuine equivalences
  surviving (the generator `ROOT` spelling, a hand-Lean comment, and
  the spec-whitespace repaint) plus five detector-invisible rows kept
  as survivors: the generated-C result seed absorbed by every arm's
  unconditional assign, both generated-Lean mnemonic rows with no
  chain consumer, and both hand-Lean flags-unchanged proof repaints
  (the `rfl` rewrite still proves the unchanged theorem),
  and the AArch64 LSL/LSR/ASR/ROR shift-value family got its own
  single-family harness against the 20,513-case host oracle (Step 0169;
  same three detectors --- the gen detector runs the generator `--check`
  row, the Lean chain the generated + hand Lean pair, the host compiles
  and runs the oracle; five contract files: the shared spec, the
  generator, the generated C table, the generated Lean module, and the
  hand refinement --- split gen 31 / lean_chain 23 / host 24 with three
  genuine equivalences surviving (the generator `ROOT` spelling, a
  hand-Lean comment, and the spec-whitespace repaint) plus four
  detector-invisible rows kept as survivors: the generated-C result seed
  absorbed by the arm assigns, both the generated-Lean LSL inner-narrow
  drop and the hand-Lean LSL pre-mask drop (width-mask subsumption the
  prover confirms), and the rename of the caller-free
  `arm64_shift_amount_masked` theorem; the generator's never-interpolated
  `ctors` string retargeted the ctor row onto the codes-range check),
  and the AArch64 UBFX/SBFX/UBFIZ/BFXIL/BFI bitfield-composition family
  got its own single-family harness against the 126,246-case host
  oracle (Step 0170; boundary sweep of 16 sources x 8 destinations x
  (20 in-domain fields + 21 guard-exercising field pairs) x 5 kinds,
  a 20,000-iteration fixed-seed sweep and the handled-gate probe; same
  three detectors and no regen stage --- split gen 33 / lean_chain 30 /
  host 31 with the two live-probed equivalences (the default-label
  rename silenced as an unused-label warning, the hand-Lean
  packet-guard repaint) joining the seven proven-redundant survivors:
  the dead result-seed literal, the spec-name regex, the
  conditional-subsumption guard repaints, the triple-concat
  SASS-layout comment, the unreachable-default UNSUPPORTED-arm name,
  the reach-only proof-support lemma, and the duplicate-case recast;
  the UBFX-coverage-assert re-assert row was retargeted onto a
  `BFI + 1U` assert the compiler rejects),
  and the AArch64 shared six-operation ALU op-step result contract
  (ADD/SUB/AND/BIC/EOR/ORR, codes 0..5) got its own single-family harness
  against the 120,073-case host oracle (Step 0171; boundary vectors plus a
  20,000-iteration fixed-seed sweep over all six ops plus the unsupported-arm
  abort probe; same three detectors and no regen or sim-header stage --- the
  simulator header only `#include`s the generated `KPROG_ALU64_RESULT` macro
  and inline-expands it, so a generated-header drift shows only through the
  host oracle --- split gen 16 / lean_chain 20 / host 11 with the
  dead-result-seed row the only detector-invisible survivor, joining the
  three documented equivalences: the generator `ROOT` spelling, the
  generated-Lean doc-comment typo, and the hand-Lean EOR counterexample
  restatement; no shakedown retargets were needed --- all draft anchors were
  caught on the first full run),
  and the AArch64 ADRP relocation-tag contract (ADRP GOT/RODATA, codes
  38/39, tags `ARM64_SIM_TAG_RELOC_ADDR`/`ARM64_SIM_TAG_RODATA_ADDR`)
  got its own single-family harness against the 257-case full opcode-byte
  oracle (Step 0172; every one of the 256 opcode bytes forked, each known
  kind returning the independent classification's tag and each unknown byte
  aborting through the generated unsupported arm; same three detectors and
  no regen or sim-header stage --- there is no ADRP route test, and the
  simulator header only `#include`s the generated `KPROG_ARM64_ADRP_TAG`
  macro and inline-expands it, so a generated-header drift shows only
  through the host oracle --- split gen 26 / lean_chain 11 / host 8 with two
  detector-invisible survivors, joining the three documented equivalences:
  the generator `ROOT` spelling, the spec-whitespace repaint, and the
  generated-Lean `.rodata` `isGot`-false arm --- the generated-C tag seed
  every case arm overwrites and the generated-Lean `.got` mnemonic row no
  chain consumer reads; one shakedown retarget was needed, the
  goal-side flip of `arm64_adrp_tag_refines` being `Eq`-symmetric under
  `rfl`, retargeted onto an independent-`isGot`-index drift),
  and the AArch64 condition-code contract (eq/ne/cs/cc/mi/pl/vs/vc/hi/ls/
  ge/lt/gt/le/al, codes 0..14) got its own single-family harness over the
  240-case full NZCV-grid oracle plus the forked 241 out-of-range sweep
  (Step 0173; every one of the 4 flag-states crossed with all 15 codes so
  each condition's truth table is checked in full, then every condition
  number 15..255 forked through the unsupported arm; same three detectors
  and no regen or sim-header stage --- the simulator header re-declares the
  fifteen `ARM64_COND_*` numbers and its `ARM64_SIM_L_EVAL_COND` wrapper
  only threads the live flag variables, so a generated-header drift shows
  only through the host oracle --- split gen 38 / lean_chain 22 / host 9
  with the generator `ROOT` spelling repaint the only documented survivor;
  two shakedown retargets were needed, the weakened-canonicalization-gate
  row being silent on a canonical spec until retargeted onto a two-field
  spec drift and the `rfl` -> `trivial` tactic repaint being
  propositionally sound until retargeted onto a `decide` repaint the free
  flag variables reject),
 `MADD`/`MSUB`/`UMULH` flag consequences if any
  (the multiply family writes no NZCV, matching the absence of
  MADD/MSUB-with-flags opcodes). Both halves of the
  condition-to-next-PC relation (flag-based `arm64_conditional_branch_refines`
  and compare-and-branch `arm64_branch_next_pc_refines`) are proved against
  independent statements over the emitted domain, and the bridge from those
  predicates to the generator's actual `goto`/label emission is now also proved
  (`GeneratedArm64BranchEmit.shape`/`nextPc` with `arm64_branch_emit_refines`),
  so the predicate-to-emitted-code chain is closed. The AArch64 condition table,
  width/NZCV flag contract, decode tables, and bitfield/multiply/extract/
  reverse/extend/conditional-select/branch/branch-emission/move-wide/shift/
  reduction/address-offset/FMOV/load-bytes/store-bytes/
  sign-extending-load-opcode/ALU-arm-operand-source contracts, and
  pointer-add/ABI-load
  contracts are already shared. The `arm64_umulh`,
  `arm64_reverse_bytes`, `arm64_reverse_bytes16`, `arm64_width_mask`,
  `arm64_width_bits`, `arm64_sign_bit`, `arm64_sign_extend`,
  `arm64_bits_mask`, the `arm64_apply_width` indirection, the shift helpers
  (`arm64_lsl`/`arm64_lsr`/`arm64_asr`/`arm64_ror`/`arm64_ror32`/
  `arm64_ror64`) and the byte-lane helpers
  (`arm64_replicate_byte_popcounts`/`arm64_horizontal_add_u8`) were removed once
  `kprog/arm64/arm64_sim_local_bpf.h` delegated to the generated contracts.
- The generation binding (verifier-accepted proof + native bytes bound to one
  immutable load generation) and the functional smokes establish different
  properties from these refinement theorems; none of them claims
  complete native-byte semantic equivalence.

### Working rules for this line

- Each increment: shared JSON spec -> generated Lean + C -> Lean refine
  theorem against an independent spec -> full `make -C kprog/formal
  check` -> (when C changed) the affected architecture's
  `make -C kprog/<arch> micro-proofs-build`
  (negative artifact + 29 workload-derived artifacts) -> commit + push +
  record evidence in the research log.
- No new measurement-validity gates; no program filtering; keep all failures
  and raw results. Performance claims come only from public Make-backed runs
  (`make micro`, `make corpus`, `make selftest`).

### Runtime status (2026-09-15/16)

- The KVM runtime path is operational in this Workspace: writable `/dev/kvm`,
  running `dockerd`, `virtme-ng` 1.41, `qemu-system-{x86_64,aarch64}`, the
  framework x86 `bzImage`, and both runner image tars. `make micro BENCH="simple"
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` passes (result `12345678` on the native/
  kernel/llvmbpf runtimes; `micro/results/x86_kvm_micro_20260915_194201_705027/`).
- `make corpus` completes a full two-start load-time comparison with a policy
  that avoids the currently failing optimizer passes:
  `BPFREJIT_CORPUS_APPS="katran" BPFREJIT_BENCH_PASSES="noop" SAMPLES=1
  WORKLOAD_DURATION=10 make corpus` exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260916_031856_977978/` with suite
  `status: "completed"` and app `status: "ok"`. Baseline and post-ReJIT both ran
  the upstream Katran under KVM with a 10-second pktgen workload (raw thread pps
  858–879k baseline, 876–887k post). Single sample, one app, one pass: provenance,
  not a paper-grade speedup.
- `make corpus` now also completes a two-start load-time comparison where a real
  optimizer pass applies:
  `BPFREJIT_CORPUS_APPS="katran" BPFREJIT_BENCH_PASSES="noop,map_inline"
  SAMPLES=1 WORKLOAD_DURATION=10 JOBS=8 IMAGE_BUILD_JOBS=8
  VMLINUX_BTF="$(pwd)/vendor/build/x86/linux/vmlinux" make corpus` exits 0 and
  writes `corpus/results/x86_kvm_corpus_20260916_131646_375109/` with suite
  `status: "completed"`, app `status: "ok"`, and `map_inline` applying 16/16
  sites on the `balancer_ingres` XDP program. Raw `balancer_ingres` counters:
  168.98 ns/run baseline (4,437,801,179 ns / 26,261,979 runs) → 147.00 ns/run
  post-ReJIT (4,136,441,567 ns / 28,139,200 runs), ratio 0.870; pktgen thread
  throughput 2,632,791 → 2,819,605 pps, sum ratio 1.071. Single sample, one app,
  one pass: provenance plus a consistent direction, not paper-grade.
- The `VMLINUX_BTF` override is required in this workspace because the host
  kernel changed to `7.3.0-070300rc3-generic`, whose BTF has no
  `struct mm_struct::user_ns`; the regenerated x86 `vmlinux.h` therefore breaks
  upstream tetragon. The framework kernel BTF (`7.0.0-rc2+`) has it. Note the
  repo asymmetry worth a follow-up: `host-native-bpf-x86` passes no
  `VMLINUX_BTF` (defaults to the host BTF), while `host-native-bpf-arm64` passes
  the framework kernel's vmlinux; the native objects run under the framework
  kernel, so x86 should match arm64. `runner/mk/build.mk` is frozen, so the fix
  is not applied and the command-line override is used instead.
- With the default policy, `make corpus` previously aborted in the load-time
  shim because the `kinsn` pass could not run: `bpfopt` linked the system LLVM-18,
  which lacks the `-bpf-enable-kinsn-select`/`-bpf-kinsn-mode` options carried by
  the `llvm-backend/llvm` fork's `lib/Target/BPF/BPFKinsnSelect.cpp`. That
  prerequisite is now satisfied in this workspace: `ninja -C
  llvm-backend/build-bpf-kinsn -j12` completed the fork LLVM build (2116/2116,
  124 static libs, `libLLVMBPFCodeGen.a`, `lib/cmake/llvm/LLVMConfig.cmake`),
  and `cmake -S bpfopt/llvm -B <build> -DLLVM_DIR=<fork>/lib/cmake/llvm` builds
  a `bpfopt` that recognizes `-bpf-enable-kinsn-select` (the LLVM-18 build reports
  `Unknown command line argument`). `runner/mk/build.mk` already routes
  `BPFOPT_LLVM_BUILD_X86` to `bpfopt/llvm/build-kinsn` and honors
  `LLVM_DIR`/`RUN_LLVM_DIR`, so no repository change is needed; exercising the
  default corpus policy still requires rebuilding the runtime image with the
  fork-LLVM `bpfopt`. `bcc/set` and `cilium/agent` additionally fail at
  application startup (BCC `capable` skeleton load `-22`; Cilium XDP compile
  canceled); those remain raw failures.
- With the fork-LLVM `bpfopt` in the runtime image, the default `full-x86`
  prefix through `kinsn` now completes a two-start load-time comparison:
  `BPFREJIT_BENCH_PASSES=noop,map_inline,const_prop,dce,kinsn` exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260916_172134_395628/` with suite
  `status: "completed"` and app `status: "ok"`. Applied sites: `noop: 3`,
  `map_inline: 16`, `const_prop: 1`, `dce: 1`, `kinsn: 71`. Raw
  `balancer_ingres`: 169.00 ns/run -> 146.01 ns/run (ratio 0.864); pktgen
  throughput 2,620,975 -> 2,799,206 pps (ratio 1.068). Single sample, one app:
  provenance plus a consistent direction, not paper-grade.
- The entire default `full-x86` group completes once `kinsn` is ordered after the
  LLVM-roundtrip passes:
  `BPFREJIT_BENCH_PASSES=noop,map_inline,const_prop,dce,wide_mem,
  bounds_check_merge,skb_load_bytes_spec,noop,const_prop,dce,kinsn` exits 0 and
  writes `corpus/results/x86_kvm_corpus_20260916_184607_120414/` with suite
  `status: "completed"` and app `status: "ok"`. Applied sites: `noop: 4`,
  `map_inline: 16`, `const_prop: 2`, `dce: 2`, `wide_mem: 1`,
  `bounds_check_merge: 1`, `skb_load_bytes_spec: 1`, `kinsn: 71`. Raw
  `balancer_ingres`: 175.79 -> 146.95 ns/run (ratio 0.836), `bytes_xlated`
  23,840 -> 19,016, `bytes_jited` 13,641 -> 11,545; pktgen throughput
  2,586,855 -> 2,838,183 pps (ratio 1.097). The original order in
  `corpus/config/benchmark_config.yaml` (`kinsn` before `wide_mem`) cannot work:
  the `kinsn` pass emits kinsn payload pairs (a `BPF_MOV64_IMM` carrying the
  encoded payload followed by `BPF_CALL`), and every other LLVM-roundtrip pass
  feeds those words to the `llvmbpf` compiler, which misreads the payload word
  as `movsx` and fails (`Invalid offset -32623 for movsx at pc 7`, confirmed from
  the retained `KEEP_WORKDIRS=1` workdir). The `kinsn` pass itself bypasses the
  roundtrip for kinsn-bearing input; the pure-bytecode passes do not.
- The `full-x86` ordering fix is committed (`557a5af54`, `kinsn` moved after the
  LLVM-roundtrip passes), so the repository default policy now completes with no
  `BPFREJIT_BENCH_PASSES` override:
  `BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10` exits 0 and
  writes `corpus/results/x86_kvm_corpus_20260916_192529_199370/` with suite
  `status: "completed"` and app `status: "ok"` over all eleven passes. Raw
  `balancer_ingres`: 170.86 -> 148.00 ns/run (ratio 0.866); pktgen throughput
  2,626,908 -> 2,798,385 pps (ratio 1.065); `bytes_jited` 13,641 -> 11,545.
- The default policy across all six apps
  (`corpus/results/x86_kvm_corpus_20260916_214505_768159/`, `CORPUS_EXIT 0`)
  leaves two apps `status: "ok"`: `katran` (`balancer_ingres` 169.58 -> 146.87
  ns/run, `kinsn: 71` sites) and `bcc/set` (thirteen tracing programs, 342 applied
  sites total: `map_inline: 60`, `kinsn: 72`, `noop: 55`, `const_prop: 28`,
  `dce: 26`, `wide_mem: 13`, `bounds_check_merge: 13`,
  `skb_load_bytes_spec: 13`). The remaining four (`cilium/agent`,
  `otelcol-ebpf-profiler/profiling`, `tetragon/observer`, `tracee/monitor`) fail
  at their own application startup before the shim tracks programs; those are
  pre-existing app-startup failures, not measurement-validity gates.
- The katran `map_inline` step previously failed for a separate, fixable reason:
  `runner/config/passes/map_inline/katran.yaml` hardcoded an overlay directory
  under `/home/yunwei37/...` that does not exist here, so the step's `jq`
  overlay construction failed before `bpfopt` ran. It now resolves the path from
  the injected `BPFREJIT_REPO_ROOT`. The same stale prefix also remained in the two
  non-default `const_mod_reduce*` policies (recorded as follow-up). Closed
  2026-09-30: both policies now resolve the host-prepared `.bin` artifact
  path from the injected `BPFREJIT_REPO_ROOT` (same fix as `map_inline`);
  verified by executing the fixed pass command on the host against a
  captured katran input blob (`docs/archive/shared/20260906-bpf-development-todo.md`,
  step 0065).
- Run one corpus invocation at a time; runs share
  `.cache/container-images/*.image.tar` and the framework kernel build. Under
  host memory pressure, pass `JOBS=8 IMAGE_BUILD_JOBS=8` to `make corpus` so the
  kernel `modules` build does not exhaust memory.

## Speculative-optimization line (paper B)

The stock-kernel speculative-optimization experiment line and its retained
evidence (experiment 093, the corrected-protocol Tracee/BCC cross-check, the
single-pass breadth queue) are recorded in the same research log. Its
outstanding items are Make-backed KVM runs with `KEEP_WORKDIRS=1` artifact
capture and the Katran `map_inline` confirmation; the pass policy
(`runner/config/passes/`) may change freely, frozen workloads and benchmark
launchers may not.

The September 19 single-pass Cilium artifact now has a separate, valid
opportunity-source audit: all 3,787 reported applied entries across 122 changed
load instances join to workdir-local metadata for a frozen `.rodata.config`
array.  Its overwritten before images still make the rewrite claim
invalid/inconclusive.  A new KVM artifact remains pending because the AE
supervisor owns an uncommitted generic LLVM-roundtrip change in
`bpfopt/llvm/src/llvm_mapinline.hpp`; the current x86 runtime image contains a
binary built from that dirty source and must not be used for speculative paper
evidence.

## Toolchain note

The duty OMP binary is pinned at
`/workspaces/.agent-state/bpf-benchmark-supervisor/bin/omp` with model
`litellm/local-small` via the internal gateway
(`http://llm-gateway.llm-gateway.svc.cluster.local:4000/v1`). If OMP reports
"model not found" at startup, the gateway's `/v1/models` listing and
`$LITELLM_API_KEY` should be verified; a working previous session proves the
route was functional, so transient discovery failure does not mean the model
is gone.
