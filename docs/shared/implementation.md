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
  The `CALL_MEMCPY` / `CALL_MEMSET` handlers `X86_SIM_L_EXEC_CALL_MEMCPY`
  (`X86_OP_CALL_MEMCPY`, `0x3f`), `X86_SIM_L_EXEC_CALL_MEMCPY_REG`
  (`X86_OP_CALL_MEMCPY_REG`, `0x46`), `X86_SIM_L_EXEC_CALL_MEMSET`
  (`X86_OP_CALL_MEMSET`, `0x3c`), and `X86_SIM_L_EXEC_CALL_MEMSET_REG`
  (`X86_OP_CALL_MEMSET_REG`, `0x45`) are composed by
  `x86_call_mem_step_refines` over the generated kind, count-source, and
  bound-form tables: the kind table picks the byte-by-byte copy body for the
  two `MEMCPY` opcodes and the masked-byte fill body for the two `MEMSET`
  opcodes, the count source is the instruction immediate for the plain
  opcodes and `RDX` for the `_REG` opcodes, and the bound form is the
  hardcoded literal `1024` for the plain opcodes and the immediate for the
  `_REG` opcodes — the generator pins the bound/count independence
  (`bound_is_imm` iff `count_source_is_reg`) and the hand module proves it
  (`x86_call_mem_bound_and_count_are_independent`). Per byte `i < min(bound,
  count)` the copy transfers `dst[i] := src[i]` and the fill stores the
  value's low byte (`x86_call_mem_fill_byte_is_low_byte`); every byte at or
  past the count is left untouched
  (`x86_call_mem_beyond_bound_unchanged`), and the effect writes the
  selected destination register once through the pointer-tagged cell with
  the source byte's replacement tag on copy and the scalar tag on fill.
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
  and the AArch64 conditional-select pointer-path contract (which register
  write carries the selected source's provenance tag across the
  csel/cinc/cset/cinv/csinv/csinc/csetm/csneg family --- only plain `csel`
  at doubleword width writes through `ARM64_SIM_L_WRITE_REG_PTR_TAG`, every
  other member and sub-word width writes a width-narrowed scalar that
  drops it; the `ARM64_SIM_L_CSEL` wrapper threads the live width through
  `KPROG_ARM64_CSEL_PTR_TAG_PATH` at its single call site and branches the
  two write paths off the result) got its own single-family harness over
  six contract files including the cross-linked family spec the ptr
  generator re-reads (Step 0174), with the host detector sweeping the
  opcode over all 256 byte values crossed with all 4 widths in forked
  children (1024 cases; non-family opcodes asserted to abort through the
  generated unsupported arm; same three detectors and no route stage ---
  the wrapper's single call site has no route macro to repaint, the
  observable write-path behavior is reached only through the macro. The
  oracle is an independent opcode-class switch structurally different from
  the generated switch). Split gen 30 / lean_chain 17 / host 12 with two
  documented survivors: the generator `ROOT` spelling repaint and the
  macro's dead path-seed initialization (every reachable case arm assigns
  before any read; out-of-family opcodes abort first). Shakedown
  retargets: four generator message repaints whose firing branches are
  unreachable on a green `--check` (family-order repaint -> the
  order-comparison repaint, pointer-uniqueness and opcode-table guards ->
  check inversions, stale comparison -> its own inversion, each
  live-probed); the refinement theorem (rename and `Bool`-ascription goal
  paint survive, nothing downstream binds the theorem and the ascription
  is propositional -> goal with the `op`/`width` operands swapped, which
  the elaborator rejects); the soundness tactic (`trivial` discharges the
  post-`cases` goals propositionally -> `simp_all`, which makes no
  progress) and the iff tactic (`cases <;> decide` and decide-only both
  close it -> decide-only whose free `width` variable `decide` cannot
  close); the in-range pin (upper-bound repaints stay provable since
  `csel` is 28 -> lower-bound 28 -> 29, which `decide` refutes).
  and the AArch64 store-exclusive status contract (Step 0175, the one
  value the `STLXR` handler writes back to the status register --- the
  store-exclusive succeeds unconditionally, so the status is the success
  code `0` narrowed to the destination width, written through
  `ARM64_SIM_L_WRITE_REG_WIDTH` at the fixed `ARM64_WIDTH_32` in the
  `ARM64_SIM_L_EXEC` dispatch; the generated macro derives it as the
  width mask subtracting itself and the hand Lean statement does the
  same, so the refinement is not a bare literal restatement). A
  53-mutation single-family harness over five files (spec, generator
  including the order/macros/no-opcodes/opcode-drift guards and the
  stale-output comparison, generated C switch with the code pin and the
  `KPROG_ARM64_STLXR_HANDLED` guard + coverage assertion, generated Lean
  table, hand refinement), no regen or sim-header stage --- the wrapper
  threads the fixed width 32 through one `ARM64_SIM_L_STLXR_VALUE` call,
  so the host oracle reaches the macro through the generated header
  alone. The host detector is the 1028-case sweep: known opcode at all
  four widths against an independent shift-of-one masking oracle, plus
  the opcode byte over all 256 values at every width with non-family
  bytes asserted to abort through the unsupported arm. Split gen 26 /
  lean_chain 15 / host 8 (one host catch through a compile failure) with
  four documented survivors: the generator `ROOT` spelling repaint, the
  generated and hand mnemonic repaints kept behind trailing comments,
  and the macro's width-seed initialization (dead: the status arm is the
  mask subtracting itself, so any width repaint still observes
  `0 - 0`). Shakedown retargets: the `HANDLED` guard repaint (a
  coverage-assertion message repaint is unobservable by a green
  `--check` and to the host compile alike -> the guard itself inverted
  `==` -> `!=`, rejected by the `_Static_assert` coverage check at
  compile time); the generated value arm (`narrow 0 (Width.w32)` equals
  `narrow 0 width` at every width since zero is zero at any width ->
  `narrow 1 width`, rejected by the refinement and the oracle); the
  refinement tactic (`bv_decide` -> `native_decide` stays sound ->
  dropping the independent-spec unfold from the `simp only` set,
  refuted by `bv_decide` with an opaque `arm64StlxrSpec`
  counterexample),
  and the AArch64 MOVK move-wide insertion contract (the low 16
  bits of the immediate inserted at one of the four architectural
  columns 0/16/32/48, keeping every other destination bit, through
  `KPROG_ARM64_MOVK_INSERT` from `generated/arm64_movk.h`; the column is
  the AUX lane-2 shift field, which `ARM64_SIM_L_MOVK_VALUE` threads
  from the `ARM64_SIM_L_SHIFT(AUX)` alias re-checked by the generator's
  `ARM64_AUX_MOVK` regex) got its own single-family harness against the
  20,145-case host oracle (Step 0176; 24 boundary vectors over all four
  columns, a 20,000-iteration fixed-seed sweep and the forked
  unsupported-column abort probe whose oracle writes the destination
  into a byte array and overwrites the target halfword's two bytes ---
  structurally separate from the macro's shift/mask pair; same three
  detectors and no regen or sim-header stage --- the wrapper threads the
  column through one `ARM64_SIM_L_MOVK_VALUE` call, so a generated-header
  drift shows only through the host oracle or a stale `--check`, split
  gen 30 / lean_chain 19 / host 18 with 6 documented equivalences: the
  generated-Lean `|||`/`&&&` precedence repaint right-assoc equal, the
  hand-Lean `column .col16` repaint the generated dispatch disagrees
  with, the generator comment probe, the hand dispatch doc-comment, a
  spec JSON spacing paint, and the macro's default-arm mask seed (only
  the abort arm sets it and then discards it) — the hand column repaint
  equal until retargeted onto the dispatch `= 15` repaint `decide`
  rejects). Shakedown retargets: the bare `dst` repaint in the
  generated-Lean value row is not a Lean identifier (elaborator fails
  before semantics; retargeted onto `imm >>> s`, rejected by the
  refinement), and the hand Lean column-value repaint is dead (the hand
  theories re-read the generated column; retargeted onto the dispatch theorem row).
  and the AArch64 packed-AUX layout contract (the 32-bit operand word
    shared by the ALU, shift, MOVK, memory, bitfield and CCMP handlers:
    four byte lanes packed little-endian through one machine-checked
    packer, the six simulator packers and seven simulator decoders thin
    aliases of that one layout, the `ARM64_REG_NONE` sentinel
    round-tripping through lane 0) got its own single-family harness
    against the 586,829-case host oracle and the 1,115,374-case route
    oracle (Step 0177; 92 single-anchor rows over nine files --- the
    shared spec, its generator, the generated C header, the generated Lean
    module, the hand refinement, both alias sheets, and both oracles; 5
    detectors across 7 staged files plus the movk generator's
    `ARM64_AUX_MOVK` sim-header regex as a fifth detector --- a stale aux
    `--check`, a Lean chain over generated and hand modules, and two live
    C oracles recompiled per row; split gen 21 / movk_gen 1 / lean_chain
    27 / host 9 / route 30 with 4 equivalences: the alias-sheet
    doc-comment repaint, the host oracle's redundant `AUX` vs `AUX_ALU`
    equality repaint recomputing the same equality, and the two
    summary-line repaints carrying no result bit --- every `ARM64_SIM_L_*`
    decoder-alias repaint catches through the route oracle, and the MOVK
    packer-alias repaint catches only through the movk generator's regex
    because the aux generator never reads the sim header; same
    one-regen-stage shape, no forked-child stage --- the layout is total
    over all 2^32 words, every lane swept exhaustively over 256 values
    in-process). Shakedown retargets: the hand-Lean lane-1 shared-theorem
    row first mirrored the conjunction order (a pure `rfl` reordering
    survives, so it was retargeted to drop the first conjunct, which the
    two-conjunct `rfl` constructor rejects on arity), and the decoder
    anchors first sat on the shift-zero branch text the shifted branches
    share, retargeted onto the `aux >>>`/`>> {shift}` expressions unique
    to the shifted arms).
  and the AArch64 conditional-select value contract (the eight-member
    CSEL/CINC/CSET/CINV/CSINV/CSINC/CSETM/CSNEG value arms the
    simulator's non-pointer path resolves: select first or second source
    (or their increments, complements, or the negated second source)
    under the already-proven condition, composed through the generated
    bit-mask mux) got its own single-family harness against the
    160,161-case host mux oracle and the 337-case width-effective route
    scanner (Step 0178; 112 single-anchor rows over nine files --- the
    shared spec, its generator, the generated C header, the generated
    Lean module, the hand refinement, both host oracles, and the sim-local
    sim wrapper; 4 detectors across 7 staged files --- a re-rendering
    `--check`, a Lean chain over generated and hand modules, the host
    mux oracle recompiled per row with a forked child for the
    non-family abort, and the route scanner driving the whole dispatch
    through `ARM64_SIM_L_CSEL_VALUE` in-process --- split gen 43 /
    lean_chain 31 / host 26 / route 5 with 7 equivalences: the
    every-arm-overwritten result-seed line, the wrapper second-source
    repaint both oracle exercises keep invisible (the scanner's zeroed
    flags never select the second source and the host oracle passes
    explicit sources), three summary-line repaints carrying no result
    bit, the generator's comment-only appendix, the `trivial` proof
    repaint of the flag-identity theorem, and the hand doc-comment
    line). Shakedown retargets: two sim-local repaints were invisible
    to the width-self-pair scanner because both legs of every
    (w, effective(w)) pair re-derive the same dispatch --- a forced-take
    keyed on the effective width and an inverted pointer-path gate ---
    and were retargeted onto raw-width drifts the absent-to-doubleword
    escalation exposes (condition interception keyed on the raw absent
    width code, pointer-path gate routed through the raw width word);
    the flags-spec check row, codes-assert repaint and coverage-gate
    constant (three NOOPs) were retargeted onto the live comparisons
    they guard; the family-order guard needs comma-joined adjacency
    because the emitted JSON members carry trailing commas verbatim).
  and the AArch64 compare-and-branch predicate contract (the four-member
    CBZ/CBNZ/TBZ/TBNZ predicate family the simulator's compare-and-branch
    dispatch resolves: taken-ness from the register read directly --- zero,
    nonzero, or masked bit at the AUX bit index --- forwarded to the target
    label by the sim-local goto steering) got its own single-family harness
    against the 80,256-case host oracle (Step 0179; 101 single-anchor rows
    over six files --- the predicate spec, its generator, the generated C
    switch macro, the generated Lean table, the hand refinement, and the
    host oracle; 3 detectors --- `--check` re-render, Lean chain, host
    recompiled per row --- split gen 46 / lean_chain 27 / host 28 with 8
    equivalences: the spec-file stale-mirror guard disarmed (inert because
    the spec rows trip the same data path), the every-arm-overwritten
    result seed, the duplicated kinds[] entry dropping TBNZ gen-side-pinned
    coverage, the fixed-seed sweep reseed, two boundary-list repaints, and
    two summary-line repaints carrying no result bit; shakedown retargets:
    the four identical `break;` lines retargeted to the tbz-arm-plus-break
    pair, the shared `decide_eq_decide`/`arm64BranchBitOf` rewrite lines
    context-qualified through their per-arm `BitVec.toNat` simp calls, and
    the sim-local CBZ/CBNZ/TBZ/TBNZ macros (43 kernel-side consumers)
    left to the kernel-side micro-sim suite because a kind-argument swap
    is invisible to a compile-only checker).
  The AArch64 branch-emission shape contract (the only emission-level bridge in the formal tree: two code shapes the generator emits for every branch --- a backward edge as an inverted conditional jump to a local fall-through label followed by an unconditional jump, and a forward edge as a plain conditional jump with a fall-through, both shapes selecting the same shared next-PC, with the direction bit carried by `KPROG_ARM64_BRANCH_BACKWARD(CURRENT, TARGET)` as `((__u8)(((TARGET) <= (CURRENT)) ? 1 : 0))) got its own single-family harness against the 64-case host oracle (Step 0180; 71 single-anchor rows over six files --- the shape spec, its generator, the generated C direction directive, the generated Lean table, the hand refinement, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 29 / lean_chain 26 / host 16 with 14 equivalences: the spec-file stale-mirror guard disarmed (inert because the shape rows trip the same data path), the generator message repaint and the comment-only import repaint (both keyed to guard paths a green run never enters), three consumers-free theorem renames (the emitted-side `arm64_branch_emit_taken`/`_not_taken` theorems plus the `arm64_branch_emit_shape_refines` declaration line, whose statement the file re-proves independently of the name), the `split`-chain tail repaint that re-proves the same fully-split conjunction, the directive irrelevance `arm64_branch_emit_shape_irrelevant` states outright (both shapes pick the same next PC), the 0x1000/0x2000 lattice fall-through-constant repaint (pure sample repaint the proved contract makes invisible), and two summary-line repaints carrying no result bit; shakedown retargets: the drafted `hand_branchpc_two_valued_drift` self-referential goal anchor did not match (the refinement's RHS is `branchPc`, retargeted to drop `GeneratedArm64BranchEmit.shape` from the unfold line --- still provable because split's auto-unfolding closes it, so the row became the `equivalent_refines_tac_extra_split_survives` equivalence), the drafted address-lattice rewrite survives (any sample of plain addresses keeps the lattice closed because oracle and directive compute the same function), a comment repaint of the re-rendered C header's top comment is catchable by the `--check` mirror even though the byte-probe itself is inert, and the single-line JSON inclusion swap anchors directly on the reordered shapes rather than through a placeholder).
  The AArch64 byte-lane extraction contract (the inverse half of the generated load contract: eight lanes whose byte the stack byte scatter takes from a 64-bit word, byte `i` recovered as `(value >> 8*i) & 0xff`, the generated `KPROG_ARM64_BYTE_AT(LANE, VALUE, UNSUPPORTED)` macro a total eight-way switch whose default reaches the caller-supplied unsupported hook, SIGABRT-enforced) got its own single-family harness against the 20,057-case host byte-pointer oracle (Step 0181; 62 single-anchor rows over six files --- the lane spec, its generator, the generated C switch, the generated Lean table, the hand refinement, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 30 / lean_chain 9 / host 6 with 17 equivalences: the spec-file stale-mirror guard disarmed (inert because the spec rows trip the same data path), the generator message repaint and the comment-only import repaint (green-run-invisible guard paths), the narrowing `__u16` repaint (a two-step narrowing store keeps the same low byte), the stale index-definition repaint (the definition is unfolded away but never load-bearing), the `0xffff` mask repaint (any aligned mask of at least eight bits narrows to the same lane byte), three consumers-free theorem renames and simp-set shrinks `bv_decide` closes without, the boundary lane-sweep shrink the 20,000-iteration random sweep already covers at every lane, the fixed-seed reseed and value-grid resamples (pure workload-sample repaints the proved contract makes invisible), a no-op self-assignment insertion, and two summary-line repaints carrying no result bit; every drafted anchor landed byte-exact, and the eight survivor rows relabeled `equivalent_*` after the first run confirmed each repaint semantics-preserving).
  The AArch64 little-endian load contract (the load value ladder: four architectural widths whose bytes the stack reads from memory and assembles at their own lanes (`__kprog_a64_lb_value |= addr[i] << 8*i`, gated by the `>= ARM64_WIDTH_16/32` and `== ARM64_WIDTH_64` comparison chain), every byte above the width cleared, proved equal to an independent masked truncation `arm64LoadBytesSpec` over `GeneratedArm64Width.mask`) got its own single-family harness against the 20,024-case host byte-pointer oracle (Step 0182; 63 single-anchor rows over six files --- the width spec, its generator, the generated C ladder, the generated Lean tables, the hand refinement, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 29 / lean_chain 16 / host 5 with 13 equivalences: the spec-file stale-mirror guard disarmed, the generator message repaint and the comment-only import repaint (green-run-invisible guard paths), three consumers-free theorem renames and simp-set changes `bv_decide` closes through, the high-byte mask repaint biased one lane high (the cleared ladder already zeroed that bit), the weakened w8 upper-byte claim (`>>> 16 = 0` still implied by the single cleared lane), the boundary pattern repaint, the fixed-seed reseed and sweep-width rotation (pure workload-sample repaints the proved contract makes invisible), and two summary-line repaints carrying no result bit; one drafted row was relabeled `equivalent_*` after the first run confirmed the weakened claim remains a theorem, and one drafted equivalence --- the refinement simp-set shrink dropping the masked-truncation unfolding --- was retained as a catch because the proof genuinely needs that unfolding).
  The AArch64 ALU handler path contract (the provenance dispatch of the generic ALU handler: `KPROG_ARM64_ALU_USE_POINTER(WIDTH, OP, DST_IS_SP, SRC_IS_SCALAR)` true only for a 64-bit ADD whose destination is not SP and whose source provenance is non-scalar; the generated Lean predicate is a flat conjunction over `Width`/`Alu` and the hand Lean side independently enumerates the same condition as a four-key match `arm64AluUsePointerSpec` that deliberately does not reuse the generated form, with scalar/pointer writeback refinements and the composed handler theorem citing the path proof by name) got its own single-family harness against the 168-case host grid (Step 0183; 45 single-anchor rows over six files --- the path spec, its generator, the generated C conjunction, the generated Lean predicate, the hand enumeration, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 18 / lean_chain 12 / host 3 with 12 equivalences: the spec-file stale-mirror guard disarmed, the generator message repaint and the comment-only import repaint (green-run-invisible guard paths), a generated-Lean tail comment and a hand namespace comment repaint, the main-refinement `rw` list repaint with a trailing comma (Lean accepts the syntax), the scalar-writeback tactic shrink (`cases width <;> rfl` closes every branch definitionally), two consumers-free example-theorem renames, the host ops-grid drift (oracle and macro repaint together so the handshake stays consistent), a host widths-grid shrink recorded as a coverage caveat, and two summary-line repaints carrying no result bit; the path-theorem rename was retained as a catch, not an equivalence, because the composed handler theorem `rw`s it by name, and the match-arm repaints that flip the SP/scalar enumeration arms are catches through the Lean chain).
  The AArch64 CCMP handler contract (the conditional-compare flag transition: `KPROG_ARM64_EXEC_CCMP` evaluates the condition on the incoming NZCV, takes `KPROG_ARM64_SET_SUB_FLAGS` on the true path, and loads the four NZCV bits from the fallback immediate's shifts 3/2/1/0 on the false path, preserving all register state; the hand Lean side states the fallback independently with `getLsbD` and refines fallback/condition/step/handler in a chain where the step theorem `rw`s the fallback lemma by name) got its own single-family harness against the 122,880-case host grid (Step 0184; 57 single-anchor rows over six files --- the CCMP spec, its generator (which cross-checks the canonical condition-table codes 0..14 in `arm64_cond_spec.json`), the generated C do-while macro, the generated Lean fallback/apply, the hand refinement chain, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 17 / lean_chain 17 / host 10 with 13 equivalences: the spec-file stale-mirror guard disarmed, the generator message repaint and the comment-only import repaint (green-run-invisible guard paths), the guarded cond-table message repaint, a generated-Lean comment and a hand namespace comment repaint, three consumers-free example-theorem renames, the host loop-start shrinks (incoming/condition/fallback starting at 1 keep the grid consistent), and two summary-line repaints carrying no result bit; two drafted equivalences were retained as catches after the first run: the fallback-lemma rename (the step theorem's else branch `rw`s it by name) and the fallback simp-set shrink (the proof needs the independent-spec unfolding).
  The AArch64 ALU operand contract (the RHS selection the generic ALU handler consumes: immediate mode bypasses the source modifier entirely while register mode applies the shared modifier semantics `KPROG_ARM64_MOD_VALUE` / `GeneratedArm64Mod.value`, so the operand composition closes the free-RHS premise of the ALU-path theorem without re-proving the modifier) got its own single-family harness against the 5,632-case host grid (Step 0185; 42 single-anchor rows over six files --- the mode/mode-modifier-usage spec, its generator (which cross-checks the eleven-code modifier table in `arm64_mod_spec.json`), the generated C ternary macro, the generated Lean mode dispatch, the hand `arm64AluRhsSpec`/composition chain, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 14 / lean_chain 9 / host 8 with 11 equivalences: the spec-file stale-mirror guard disarmed, the generator message repaint and comment-only import repaint plus the modifier-table message repaint (green-run-invisible guard paths), three consumers-free example-theorem renames, the `arm64_alu_handler_refines`/`arm64_alu_rhs_refines` `rw`-order repaint (disjoint subterms close in either order), the host mode-loop shrink (register-half grid coverage caveat), the mirrored host vector walk (`vectors[i]` / `vectors[7-i]` keeps check-pair coverage identical), and two summary-line repaints carrying no result bit; the VALUE/SHIFT argument transposes in both the generator recipe and the host oracle are catches (they flip which operand receives the shift amount), and both operand-order mirrors in generated and hand Lean are catches as well).
  The AArch64 CNEG contract (the condition-gated negation value: a taken condition negates the source through the two's-complement identity --- generated form `0 - src`, hand form `~~~src + 1` --- an untaken condition passes it through, both arms narrow with the shared width mask, opcode 65 `ARM64_OP_CNEG`, and no NZCV bit is written; the generator re-parses the opcode define from `kprog/arm64/arm64_sim.h` on every run and the host oracle re-derives the width mask from a shift of one, cross-checks the invert-and-add-one identity, and asserts an out-of-family opcode aborts) got its own single-family harness against the 40,097-case host sweep (Step 0186; 46 single-anchor rows over six files --- the opcode spec, its generator, the generated C do-while macro, the generated Lean dispatch, the hand refinement chain, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 15 / lean_chain 7 / host 9 with 15 equivalences: the spec-file stale-mirror guard disarmed, four guarded error-message repaints (spec/order/macros/opcode/drift text) plus the comment-only import repaint (green-run-invisible guard paths), five consumers-free theorem renames (flags-unchanged/taken-cancel/untaken-identity/two-example), the code-range bound relaxation (65 ≤ 65 ∧ 65 ≤ 66 stays proved), and two summary-line repaints carrying no result bit; the taken-arm swap in the generated Lean value arm, the `decide` for `bv_decide` downgrade, and the out-of-family abort disarm are catches).
  The AArch64 logic-flag handler contract (the AND/BIC result-plus-NZCV step: value = shared ALU result with families cross-checked against the decode table, flags = the shared logic policy with C=V=0, ANDS/BICS write back the narrowed scalar while TST/TST-BIC preserve register/SP state; the hand Lean side restates the result and policy independently `arm64AluResultSpec` / `arm64LogicNzc` and refines through the already-proven ALU/flag/scalar-write theorems) got its own single-family harness against the 64-case host grid (Step 0187; 49 single-anchor rows over six files --- the family/mode spec, its generator (which cross-checks the family codes in `arm64_decode_spec.json`), the generated C do-while macro with the `KPROG_ARM64_SET_LOGIC_FLAGS` tail, the generated Lean family/apply forms, the hand refinement chain, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 16 / lean_chain 13 / host 8 with 12 equivalences: the spec-file stale-mirror guard disarmed, the generator message repaints and comment-only import repaint (green-run-invisible guard paths), the generated family-constant and code-arm value repaints (consumers bind names, so value repaints never rebind), four consumers-free example-theorem renames, and two summary-line repaints carrying no result bit; the ALU-arm drift, the result-recipe operand swap, the logic-to-SUB policy repaint, both hand family-arm drifts, the writeback/test mode exchanges, and the BIC-mask `lhs | ~rhs` / negative-shift / zero-flip oracle repaints are all catches).
  The AArch64 memory address-offset contract (the load/store offset accumulator: an offset access contributes the immediate, a pre/post-indexed access contributes no immediate here, an indexed access additionally adds the already source-modified index register, and the accumulation is 64-bit two's-complement wrapping stated two ways --- signed `__s64` addition in the C macro, `BitVec 64` addition in the Lean contract, with that bit-pattern equivalence as the refinement statement; the generated Lean side carries both a let/if form and an independent four-case `valueSpec` table) got its own single-family harness against the 20,168-case host sweep (Step 0188; 45 single-anchor rows over six files --- the offset/prepost spec, its generator, the generated statement-expression macro with evaluate-once locals, the generated Lean let/if + table forms, the hand refinement chain (refinement, four-case dispatch, prepost-immediate-independence, three canonical examples), and the host oracle whose `__int128` signed accumulator reconstructs the offset through a different expression tree; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 15 / lean_chain 13 / host 5 with 12 equivalences: the spec-file mirror-guard disarm, the guarded spec/order message repaints plus comment-only import repaint (green-run-invisible guard paths), the evaluate-once assignment comment repaints (C locals carry no observer), four consumers-free theorem/example renames, and two summary-line repaints carrying no result bit; the base-reciprocal drift, the four-case table swaps in both backends, the acc-gate flip, the index-negation drift, and the truncation-mask repaint are all catches).
  The AArch64 ADD/SUB flag-handler contract (the arithmetic result-plus-NZCV step: value = shared ALU result with families cross-checked against the decode table, flags = `applyAdd`/`applySub` on the same operands, ADDS/SUBS write back the narrowed scalar while CMP/CMN preserve register/SP state; the generated C emits writeback and compare macros, the hand Lean side restates the step independently `arm64AluResultSpec` + `arm64AddNzc`/`arm64SubNzc` with four `native_decide` examples) got its own single-family harness against the 64-case host grid whose oracle re-derives flags through a signed `__int128` comparison (Step 0189; 47 single-anchor rows over six files --- the family/mode spec, its generator (which cross-checks the family codes in `arm64_decode_spec.json`), the generated C writeback/compare macros, the generated Lean result/flags/apply dispatch, the hand refinement chain, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 16 / lean_chain 13 / host 7 with 11 equivalences: the spec-file mirror-guard disarm, the guarded message and import repaints, the generated Lean code-arm value repaint (consumers bind names), the ADD-operand swap in the generated result assignment (commutative at every masked width), four consumers-free example-theorem renames, and two summary-line repaints carrying no result bit; the family-constant repaint is a catch here --- the host threads raw literals 0/1 through the macro switch, unlike the logic-flag handler whose driver re-uses the generated macros --- and the want-operand swap, carry-arms transpose, overflow-polarity flip, and zero-bit gate repaint are all catches).
  The AArch64 stack-index contract (the frame-offset -> arena-byte map: index = the low 32 bits of the wrapping 64-bit bias-plus-offset sum — the frame-base offset lands at index 0, offset 0 at byte bias — with `ptrIndex` keeping the full 64-bit sum for the stack-pointer helper; the hand Lean side restates the map `BitVec.setWidth 32` independently and proves the refinement plus frame-base / base-is-bias / affine / `2^32`-aliasing / ptr-truncation laws over two concrete bias-96 examples) got its own single-family harness against the 536-case host oracle (Step 0190; 41 single-anchor rows over six files — the bias/step/accumulation/mask spec, its generator (whose template repaints re-render to different generated bytes and fail the staleness check), the generated C `KPROG_ARM64_STACK_INDEX`/`_PTR_INDEX` macros, the generated Lean index/ptrIndex, the hand refinement module, and the host oracle's unsigned restatement with alias launches; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 14 / lean_chain 9 / host 3 with 15 equivalences: the mirror-guard disarm, guarded message and module-docstring repaints (non-emitted bytes), plus-zero summand and restatement-sumand-swap repaints (setWidth-32 distributes over summand order), three consumers-free theorem renames, an alias probe repainted to another 2^32 multiple, the u32-bias cast and unsigned-u64 pointer repaints, the summary-line repaint, the native_decide pairing repaint (each goal closed before the vacuous second tactic), and the host bias-constant repaint (bias is a parameter both sides re-derive); the sum-to-difference flip, the low-32 mask repaint, the alias-law shift-count change, the affine off-by-one, the ptr-truncation width change, and the macro-name repaint are all catches).
  The AArch64 stack slot-tag contract (the slot-tag selection: only a 64-bit access at a qword-aligned slot carries the slot's stored tag, `(isW64 && isAligned)`, routed through a total four-case classifier and tagged table restated independently; twin shape contracts bind `tagged(classify ...)` as the read/write slot-tag firing predicate) got its own single-family harness against the 36-case host oracle (Step 0191; 39 single-anchor rows over six files --- the case spec, its generator (with the generator-side `taggedSpec` statement and the C ternary body), the generated C predicate, the generated Lean classifier/table, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 10 / lean_chain 10 / host 5 with 14 equivalences: the unreachable order/table error-message repaints and mirror-guard disarm (green-run-invisible), classifier-arm repaints renaming an emitted case label within the same tagged class (every consumer binds `tagged(classify ...)`, never the case identity), the `rfl`-to-`decide` tactic repaint, three consumers-free theorem renames, the `simp` lemma-list reorder, and host grid repaints that mislabel which concrete offset/width carries each boolean class while still injecting both classes; the table-tag flips, the classifier-routing repaint, the conjunction-to-disjunction and polarity repaints, and the totality `simp` citation drift are all catches).
  The AArch64 memory-index presence contract (the sentinel-based index-arm selection: `AUX` lane byte `0xff` is the absent arm, every other byte the present arm, restated independently in the hand module against the literal `0xff` with the sentinel pinned to `0xff`/`.absent`/`regNone`, the two arms proven complementary and consumed by the offset contract's `hasIndex` cases) got its own single-family harness against the 512-case host oracle sweeping all 256 index bytes over both macros (Step 0192; 45 single-anchor rows over six files --- the two-arm case spec, its generator (with the rendered Lean `if` selector and both rendered C macros), the generated C header, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 14 / lean_chain 11 / host 8 with 12 equivalences: four unreachable error-message repaints and the mirror-guard disarm (green-run-invisible), five consumers-free theorem renames, the arm-constant repaint whose every use-site re-derives from the identifier, and the summary-line repaint; the sentinel renumber, absent-flag repaints, selector-arm repaints, table-row flips, complement inversion, and oracle-arm swaps are all catches).
  The AArch64 register-presence contract (the writeback destination selection: a decoded register number receives a write unless it is the zero register `31` or the no-register sentinel `0xff`, both discard arms proven and the sentinel linked to the memory-index sentinel; the class table and presence test restated independently against the literal numbers) got its own single-family harness against the 512-case host oracle sweeping all 256 register bytes over both macros (Step 0193; 56 single-anchor rows over six files --- the three-class case spec, its generator (with the rendered Lean classifier and both rendered C macros), the generated C header, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 18 / lean_chain 16 / host 9 with 13 equivalences: five unreachable error-message repaints and the mirror-guard disarm (green-run-invisible), five consumers-free theorem renames, the GPR class-constant repaint whose every use-site re-derives from the identifier, the decimal-to-hex literal repaint (`31U` == `0x1fU`), and the summary-line repaint; the register-number renumbering, classifier and class-assignment swaps, table-row flips, `&&`-to-`||` and polarity repaints, number-pin drifts, and both discard flips are all catches).
  The AArch64 plain-load provenance contract (the plain-load routing decision: destination written through the tag-copy register write exactly when the access width is doubleword and the memory-read tag is not the bare scalar tag, any other opcode reaching the caller-supplied unsupported arm; the generated switch case label static-asserted and cross-checked against `kprog/arm64/arm64_sim.h` at `--check` time; the hand module restates the rule against the bit count) got its own single-family harness against a 2048-case fork-per-case host oracle sweeping all 256 opcodes x 4 widths x 2 tag classes with SIGABRT required off-family (Step 0194; 49 single-anchor rows over six files --- the opcode+preserve-rule case spec, its generator, the generated C switch macro, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 14 / lean_chain 13 / host 10 with 12 equivalences: six unreachable error-message repaints (green-run-invisible), four consumers-free theorem renames, a true weaker range-pin repaint with the exact opcode pin remaining, and the non-scalar tag-value grid repaint keeping both tag classes injected; the case-label renumber, width-code repaint, tag-equality flips, conjunction-to-disjunction repaints, drop-law flips, exit-bit shift, SIGFPE repaint, and want-sign inversion are all catches).
  The AArch64 FMOV destination-routing contract (the moved-value destination selection: a direction code writes `v0` exactly when it is one of the four in-range direction codes with an even parity, register-half directions take the width-narrowed register write, any other code the caller-supplied unsupported arm; the generated case labels static-asserted and re-checked against `kprog/arm64/arm64_sim.h` at `--check` time; the hand module restates the rule arithmetically on the direction code) got its own single-family harness against a 256-case fork-per-direction host oracle with SIGABRT required out-of-range (Step 0195; 51 single-anchor rows over six files --- the opcode+direction-table case spec, its generator, the generated C switch macro, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 16 / lean_chain 11 / host 11 with 13 equivalences: eight unreachable error-message repaints (green-run-invisible), two consumers-free theorem renames, a true weaker range-pin repaint with the exact opcode pin remaining, and both harness-grid bound repaints keeping both routing classes exercised; the direction-table flips, assignment-polarity repaint, match-arm and wildcard flips, parity repaints, tuple flip, out-of-range loosening, exit-bit shift, SIGFPE repaint, and want-sign inversions are all catches).
  The AArch64 MOV provenance contract (the shared move routing decision: the immediate move always writes a width-narrowed value because an immediate carries no provenance, the register-source move copies the source register's tag exactly at doubleword width, any other opcode the caller-supplied unsupported arm behind the `HANDLED` coverage macro; both opcodes re-checked against `kprog/arm64/arm64_sim.h` at `--check` time; the hand module restates `op = movReg && width = w64`) got its own single-family harness against a 1024-case fork-per-case host oracle sweeping all 256 opcodes x 4 widths with SIGABRT required off-family (Step 0196; 50 single-anchor rows over six files --- the two-opcode case spec, its generator, the generated C switch macro, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 15 / lean_chain 10 / host 12 with 13 equivalences: six unreachable error-message repaints (green-run-invisible), three consumers-free theorem renames, a true weaker range-pin repaint with the exact opcode pin remaining, and the width-grid permutation keeping all four width classes injected; the case-1 sets-path injection, the polarity flip, the handled `&&` repaint, the tag-path arm flip, the conjunction repaint, the bound repaint, the exit-bit shift, the SIGFPE repaint, and want-sign inversions are all catches).
  The AArch64 sign-extending-load width contract (a byte for `LDRSB`, a word for `LDRSW`, a halfword for `LDRSH` --- fixed by the opcode and independent of the destination access width, so a mislabeled load reads the wrong number of bytes before the shared sign-extension step; an off-family opcode the caller-supplied unsupported arm behind the `HANDLED` coverage macro; both codes re-checked against `kprog/arm64/arm64_sim.h` at `--check` time) got its own single-family harness against a 256-case fork-per-case host oracle sweeping all opcodes with SIGABRT required off-family (Step 0197; 58 single-anchor rows over six files --- the three-opcode case spec, its generator, the generated C switch macro, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 19 / lean_chain 14 / host 14 with 11 equivalences: seven unreachable error-message repaints (green-run-invisible), two consumers-free theorem renames, a true weaker range-pin repaint with the exact opcode pin remaining, and the generated mnemonic repaint that no downstream proof derives; the load-width arm repaints, the wildcard flip, the code-keyed repaint, the bytes-match repaint, the sub-64 bound repaint, the flags flip, all oracle repaints, the exit-mask shift, the SIGFPE repaint, and both status-branch swaps are all catches).
  The AArch64 width/narrowing contract (the four-element width table --- codes 1/2/4/8, masks 0xff/0xffff/0xffffffff/0xffffffffffffffff, sign masks per bit count, bit counts 8/16/32/64 --- `narrow` as the mask conjunction, `zero`/`sign` as the narrow-zero and narrow-top-lsb tests, and the effective-width resolution sending absent code 0 to the default doubleword code while leaving every real code untouched; the hand module bridges the mask sign test to the shift test with `bv_decide`) got its own single-family harness against a 40080-case host oracle (18 boundary vectors per width plus a 20000-iteration fixed-seed LCG sweep over all four widths) checking bits/mask/sign-mask against a bit-count-keyed oracle (Step 0198; 87 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 30 / lean_chain 23 / host 12 with 22 equivalences: ten unreachable error-message repaints (green-run-invisible), six consumers-free theorem renames, and six value/unused-path repaints that keep every protocol invariant intact; the per-row table drifts, the xor/!=/Lsb-0 repaints, the effective fallthrough swap, the apply `|`-for-`&` repaint, the modulo tails, the low-mask and sign-bit calculation repaints, and the check-polarity swaps are all catches).
  The AArch64 pair-load provenance-tag contract (the two-slot LDP routing: the outer pair gate — doubleword width with at least one non-scalar tag — guarding two per-slot tag-class decisions, the two-bit mask whose bit 0 routes the low slot and bit 1 the high slot to the tag-copy register write, and the generated unsupported arm for opcodes outside the family; the hand module keys the routing on each slot's bit-count class, proving the gate redundant with the per-slot rule) got its own single-family harness against a 4096-case fork-per-case host oracle sweeping all 256 opcodes crossed with four widths and four tag-class pairs — a known pair load must match the independent per-slot oracle, an unknown opcode must abort through the generated unsupported arm (Step 0199; 75 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row with compile/link failures counted as catches --- split gen 18 / lean_chain 19 / host 26 with 12 equivalences: five unreachable error-message repaints, five consumers-free theorem renames, and two value repaints (opcode loop window, exit message); the gate `&&`/`||` repaints, the bit-set and accessor swaps, the default-arm repaint, the unsupported-arm undeclared repaint, and the static-assert/case drifts are all catches).
  The AArch64 memory-space dispatch contract (the closed four-space classification of every load base register — stack/stack-pointer reads through the stack helper keeping the stack tag, ABI and reloc-address bases at width 64 escalate to pointer load/map-pointer tag, everything else is the ordinary load with a scalar tag, and no widening off width 64 changes the selection; the hand module restates both dimensions as predicate nestings and proves the refinements, no-widening, stack width-independence, and the reloc behaviors) got its own single-family harness against a 72-case host oracle sweeping is_sp × 9 tags × 4 widths as an independent nesting that also checks the src/tag family split (Step 0200; 64 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand refinement module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 11 / lean_chain 12 / host 20 with 21 equivalences: three unreachable error-message repaints, five consumers-free theorem renames, eight coherent define renumberings the reflected oracle consumes as-is, the swapped src/tag macro reads whose code families coincide, and sweep-shape repaints an all-equal oracle cannot distinguish; the ordering inversion, the ABI-w64 clearance drop, all chain and Peano-row repaints are catches).
  The AArch64 stack-arena contract (the two overlapping views over one union storage — the byte arena indexed by the 32-bit stack byte index, the word arena indexed by that index shifted right 3 under the low-three-bits alignment guard so the 64-bit fast path skips no byte, and the capacity round-up that keeps the word view covering the byte view, 20 slots for the enabled 160-byte arena and one slot even disabled; the hand module restates the generated expressions independently, division/remainder/shift-plus-carry round-up rather than the +7 fold, and proves the refinements, the views-coincide property, the byte lane-0 agreement, and six canonical examples) got its own single-family harness against a 70558-case host oracle that grid-sweeps indices and capacities against independent division/remainder/round-up restatements, bounds coverage and tightness, round-trips a word through the byte-lane contract, and exhaustively sweeps 256x256 index-capacity-word values (Step 0201; 62 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 16 / lean_chain 17 / host 15 with 14 equivalences: two unreachable error-message repaints, four consumers-free theorem renames, the doc-comment shift, the header-guard repaint, sweep-shape grid repaints the all-equal oracle cannot distinguish, and the OK-line message; every spec-field drift, generator template expression, generated macro body, Lean definition, canonical example value, and per-case host check is a catch).
  The AArch64 flag-operand contract (the right-hand-operand selection shared by the six NZCV-producing arm pairs `SUBS`/`ADDS`/`CMP`/`TST`/`ANDS`/`CCMP` — the `_IMM` member of each pair selects the decoded immediate, every other opcode selects the caller-supplied register expression; the generated side carries the twelve-constructor `FlagOp` enum, its opcode `code` table, the `immediate` selection match, a twelve-entry `_Static_assert` block, and the six-case `KPROG_ARM64_FLAG_RHS` statement-expression switch; the hand module restates the selection independently as a membership test over named immediate and register lists and proves the refinement on all twelve opcodes, the immediate iff-membership biconditional, the register-only rule, list disjointness, per-family exclusivity, the full code dispatch, the 66-bounded range, and three canonical examples) got its own single-family harness against a 256-opcode 5120-case host oracle that sweeps distinct immediate and register constants over every opcode byte value (Step 0202; 69 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 19 / lean_chain 22 / host 8 with 20 equivalences: five unreachable generator error-message repaints, ten consumers-free hand theorem/example renames (no module imports the hand module), the header-guard repaint, the host sweep-value repaints (immediate/register tables and a shrunken range yielding already-equal verdicts), and the OK-line message; every spec opcode drift, generator template row, generated Lean code/selection row, hand restatement value, and host case label is a catch).
  The AArch64 FMOV direction contract (the value routing between the vector register `v0` and a general-purpose register across the four directions `D_FROM_X`/`X_FROM_D`/`S_FROM_W`/`W_FROM_S` codes 0..3 — the vector-destination directions select the source register, the register-destination directions keep `v0`, a code outside the four reaches the caller-supplied unsupported arm, and the caller applies the width via `writesReg` selecting the caller's `narrow`; the generated side carries the four-constructor `Fmov` enum with its `code`, `mnemonic`, and `writesReg` tables and the `value` selection match, two `_Static_assert` rosters (drift and coverage), the `KPROG_ARM64_FMOV_HANDLED` macro, and the four-case `KPROG_ARM64_FMOV_VALUE` statement-expression switch with the unsupported default; the hand module restates the routing independently as a two-destination disjunction that narrows through an explicit `narrow` and proves the refinement over all four directions and widths, the code range, the per-arm code/write dispatch, the vector- and register-destination value identities, and two round-trip/narrowing examples) got its own single-family harness against a four-direction plus 20000-case host oracle covering the value-table grid, the fixed-seed random sweep, and the unsupported-arm abort (Step 0203; 70 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 21 / lean_chain 18 / host 11 with 20 equivalences: six unreachable generator error-message repaints, the header-guard repaint, the two generated-mnemonic string repaints consumed by no Lean module and no C path, seven consumers-free hand theorem renames (no module imports the hand module), the host sweep repaints (a remapped direction call, a remapped grid call, and a swapped value-table entry yielding already-equal verdicts), and the OK-line message; every spec drift, generator template row, generated Lean table row, hand theorem body, and host macro/table call is a catch).
  The AArch64 NZCV flags contract (the flag transitions shared by the three families --- ADD `KPROG_ARM64_SET_ADD_FLAGS` (C is the unsigned carry-out, V the signed overflow), SUB `SET_SUB_FLAGS` (C is NOT borrow, i.e. lhs >= rhs, V the signed overflow), and logical `SET_LOGIC_FLAGS` (C and V cleared) --- over the four widths, all computed from width-narrowed operands; the spec is an exact-match dict (families table, width_rule, overflow doc) verified by the generator's `load()`, the generator re-renders the whole generated module and header with byte-for-byte `--check`, the generated Lean module exposes `addCarry`/`addOverflow`/`applyAdd`/`subCarry`/`subOverflow`/`applySub`/`applyLogic`, the hand module restates the same NZCV statement independently as the `Arm64NzcSpec` record plus the `arm64{Add,Sub,Logic}Nzc` constructions and proves the three refinements by `cases width <;> rfl` then five canonical examples by `native_decide`) got its own single-family harness against an independent `__int128` host oracle over 12 boundary vectors across 4 widths plus a 20000-case fixed-seed random sweep (60144 cases) (Step 0204; 65 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 9 / lean_chain 22 / host 22 with 12 equivalences: two unreachable generator error-message repaints, the header-guard repaint, three consumers-free hand renames (no module imports the hand module), the `native_decide` -> `decide` tactic swap, the host add-carry `!= 0` -> `== 1` narrowing (the shifted sum is 0 or 1), the width-sequence remap and widths-table swap (verdicts re-derived identically), and the OK/FAILED message repaints; every spec family-field drift, expected-dict value drift, generated/hand definition rename, generated/hand masked-equality condition flip, macro-name repaint (too-strict generator next-check and downstream C compile), per-family mismatch-condition repaint, mismatch-table remap, and widths-table swap is a catch).
  The AArch64 ORN contract (the single complemented logical OR arm `orn_reg`, opcode 53 aka `ARM64_OP_ORN_REG` 0x35U: the value is the OR of the first source with the bitwise complement of the already source-modified second source, narrowed to the destination width, the complement inlined; an opcode outside the family reaches the caller-supplied unsupported arm and no arm writes NZCV; the spec is an exact-match dict verified byte-for-byte plus an opcode drift cross-check against `kprog/arm64/arm64_sim.h`, the generator re-renders the whole generated Lean module and C header with byte-for-byte `--check`, the generated side carries the one-constructor `Orn` enum (`code` 53, `mnemonic` "ORN", `value` the `narrow (lhs ||| ~~~rhs)` match, `flagsUnchanged` true) and the `KPROG_ARM64_ORN_VALUE` macro (the `case 53U` arm over the width mask with the outer `UNSUPPORTED` arm), the hand module restates the arm independently in its De Morgan complement form `narrow (~~~((~~~lhs) &&& rhs))` and proves the refinement by `cases op <;> cases width <;> bv_decide` plus the code-range/dispatch, flags-unchanged, zero-operand, w32-bound, and two canonical `native_decide` examples) got its own single-family harness against an independent `(1 << bits) - 1` mask host oracle that cross-checks both operand forms over the 10x10 boundary grid across every modifier code (11 mods, composed through `KPROG_ARM64_MOD_VALUE`) across 4 widths plus a 40000-case fixed-seed random sweep plus the unsupported-abort check (40401 cases) (Step 0205; 50 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 11 / lean_chain 8 / host 10 with 21 equivalences: six unreachable generator error-message repaints, the generated-mnemonic string repaint no consumer reads, the header-guard repaint, nine consumers-free hand renames (no module imports the hand module), the code-range 53-to-52 weaken (still a true, decide-provable statement), the canonical 0x0f-to-0x1f repaint (0xf0 complemented with 0x1f is still 0xfffffffffffffff0), and the OK/FAILED message repaints; every spec-field or expected-dict drift, rendered-template drift, generated/hand definition rename or arm-body repaint consumed downstream, static-assert or case-label or macro-body repaint, include repaint, oracle-condition repaint, and direct-vs-De-Morgan repaint is a catch).
  The AArch64 pre/post-indexed writeback contract (the decode of the packed memory-flag byte of an `ARM64_AUX_MEM` operand into the address-writeback form: the flag byte is the aux word's top byte (`>> 24`, mask 255), `MEM_PRE` (bit 1) applies the immediate before the access and `MEM_POST` (bit 2) after it as independent facts (both set applies the same immediate twice), an offset access contributes the immediate in the address offset so the offset suppresses the immediate exactly when either bit is set, each macro evaluates the flag byte once and writes no NZCV, and the caller supplies the base-register writeback; the spec is an exact-match dict verified byte-for-byte plus an `ARM64_MEM_PRE`/`MEM_POST` drift cross-check against `kprog/arm64/arm64_sim.h`, the generator re-renders the whole generated Lean module and C header with byte-for-byte `--check`, the generated side carries the top-byte `flags` decode, the `preWriteback`/`postWriteback` gates, `suppressOffset`, `preDelta`/`postDelta`, the independent raw-flag statements `preDeltaSpec`/`postDeltaSpec`/`suppressOffsetSpec`/`writebackFormSpec`, and the four `KPROG_ARM64_MEM_PREPOST_*` C macros with their PRE/POST static asserts; the hand module restates the flag byte as the `(aux.toNat >>> 24) &&& 255` decode and proves the gate equalities by `rfl`/`simp`, the delta refinements by `exact ⟨rfl, rfl⟩`, the form-ordinal sum by `rfl`, its bound by `split <;> split <;> omega`, and three canonical examples (offset 0, post 2, both 3) by `decide`) got its own single-family harness against an independent top-byte host oracle in two parts (constants vs literals and named bits vs `arm64_sim.h`, then the full decode/select sweep over every flag byte 0-255, three low-byte noise words, and six immediates --- 4608 cases) (Step 0206; 59 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 21 / lean_chain 20 / host 5 with 13 equivalences: five unreachable generator error-message repaints, the header-guard repaint, two consumers-free renames (the unread `suppressOffsetSpec` and the hand `flags_refines` theorem), the weaker form-bound `≤ 2` to `≤ 3` repaint (weaker statement stays omega-provable), the interchangeable low-byte-noise 0x5a-to-0x5b and immediate 0x1000-to-0x1001 vector drifts (verdicts re-derived identically from repainted inputs), and the OK/FAILED message repaints; every spec field or expected-dict drift, rendered gate/delta/suppress template drift, generated/hand definition or goal repaint consumed downstream, C-macro or static-assert repaint, include repaint, independent-model decode and gate repaint, and oracle-message repaint is a catch).
  The AArch64 register dispatch contract (the register-number -> dispatch-cell binding: the 31 general-purpose registers are the register numbers `0 .. 30` in `x0 .. x30` order, so the `ARM64_SIM_L_FOR_EACH_GPR` dispatch cell index equals the register number, and the zero register 31, the stack pointer 32, and the no-register sentinel `0xff` are not dispatch cells; the spec is an exact-match dict verified byte-for-byte --- schema, operation, `reg_bits`, `gpr_count`, and the 31 `x{n}` -> `n` cells --- re-checked for cell order, cell numbers, and cell-count/`gpr_count` agreement, the generator re-renders the generated Lean module and C header with byte-for-byte `--check`, the generated side carries `gprCount`/`regBits`, the `cellNumbers`/`cellNames` tables, the `cellOf` selector, the inverse `numberOfName`/`nameOfNumber` lookups, and the C macros `KPROG_ARM64_GPR_COUNT`/`KPROG_ARM64_GPR_CELL` with 31 `ARM64_X<n>` static-assert drift checks; the hand module restates the tables against independent `List.finRange` constructions and proves the lengths, `Nodup`, the `cellOf` literal-bound equivalence, the x0/x30/zero/stack-pointer/sentinel boundary examples, the full-range round trip, the name<->number round trips, and the cross-contract agreements with the register-presence and memory-index contracts (`gprCount = xzrNumber`, dispatch none ⇔ presence discard, sentinel bytes coincide), plus the dispatch-subset-of-writable classification proofs; the host oracle recompiles with the macros and compares `KPROG_ARM64_GPR_CELL` against the identity binding over the full byte range --- 257 cases) got its own single-family harness (Step 0207; 71 single-anchor rows over six files --- the case spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 21 / lean_chain 30 / host 5 with 15 equivalences: five unreachable generator error-message repaints, the header-guard repaint, six consumers-free hand theorem renames, an `Eq.refl _` proof-term swap that keeps the sentinel theorem discharged, and the OK/FAIL message repaints; every expected-dict or re-check drift, rendered table/macro repaint, generated or consumed hand repaint, boundary or round-trip goal repaint, cross-contract statement repaint, and oracle model/message repaint is a catch).
  The AArch64 source-modifier contract (the eleven-arm modifier value applied through `ARM64_SIM_L_MOD_VALUE` before an ALU step: the identity arm plus shift (LSL/LSR/ASR), rotate (ROR), and extend (UXTW/SXTW/UXTH/SXTH/UXTB/SXTB) arms, with the shift amount `k` masked to the width (`& 31` on `w32`, `& 63` otherwise) and the extend arms applying the raw shift field exactly like the C macro; the spec is an exact-match dict verified byte-for-byte --- schema, operation, and the eleven operations in `none/lsl/lsr/asr/ror/uxtw/sxtw/uxth/sxth/uxtb/sxtb` order with codes 0..10 and per-arm `lean`/`c` expression strings --- re-checked for order, codes, and code drift against the `mod` table of `arm64_decode_spec.json`, the generator re-renders the generated Lean match and the C `switch` macro with byte-for-byte `--check`; the generated Lean module defines `value` over the `GeneratedArm64ModDecode (Mod)` codes, the generated C header pins the 11 `ARM64_MOD_*` codes with static asserts and defines the total `KPROG_ARM64_MOD_HANDLED` cover and the eleven-arm `KPROG_ARM64_MOD_VALUE` statement expression; the hand module restates all eleven arms independently (`arm64ModValueSpec`: narrow/shift/rotate, masked complement-and-subtract sign extension, truncation shift pairs) and proves the refinement by `cases <;> bv_decide`, the code-range theorem (`code mod < 11` by `decide`), the code dispatch equalities, the `__u8` shift-vector magnitude lemma, the `shift &&& 0x3f` amount-masking quartet, the extend-shift refinement over the `arm64ModShiftOfByte` image, the fed-ALU composition through `GeneratedArm64AluResult.result .add` and `arm64_alu_result_refines`, and six canonical examples (UXTB/SXTB/SXTW boundary values, the LSL w32/w64 shift masking, the ROR byte rotation, the identity arm) by `native_decide`; the host oracle drives `KPROG_ARM64_MOD_VALUE` against an independent plain-C oracle over the 15 boundary vectors x 11 modifiers x 8 shifts x 4 widths plus a 20000-iteration fixed-seed LCG sweep (extends restricted to shift < 64) and the HANDLED membership checks --- 225292 cases) got its own single-family harness (Step 0208; 60 single-anchor rows over six files --- the spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 8 / lean_chain 24 / host 11 with 17 equivalences: six unreachable generator error-message repaints, the header-guard repaint, five consumers-free hand theorem renames (code-in-range, code dispatch, masked quartet, extend refinement, fed-ALU), and five all-equal-oracle input-side repaints (the shift classifier and LCG seed/stream change inputs fed symmetrically to macro and oracle, and the OK/FAIL message repaints); every spec-row/expected-dict/re-check drift, rendered-arm or separator repaint, modifier-arm or code-assert repaint, consumed-definition rename, boundary-goal repaint, and oracle model repaint is a catch).
  The AArch64 vector-register contract (how the four vector memory-transfer opcodes `ARM64_OP_LOAD_D0` 0x28, `LOAD_Q0` 0x2a, `STORE_D0` 0x29, `STORE_Q0` 0x2b map onto the two 64-bit vector-register state fields: `__a64_v0` is the low half at slot offset 0 and `__a64_v0_hi` is the high half at slot offset 8, a `.D0` transfer touches the low half only, a `.Q0` transfer touches the low half and then the high half, and the two halves are distinct slots; the spec is an exact-match dict re-checked per column, for duplicate defines, offset agreement, half-aliasing, and the state-field names against `../arm64/arm64_sim_local_bpf.h`, the generator re-renders the generated Lean module and C header with byte-for-byte `--check`; the generated Lean module spans the four `Op` constructors plus the `Access`/`Half`/`Halves` codomain types and the per-opcode `access`/`halves`/`armIndex` selectors, `halfCount`, `halfOffset`, and the per-opcode ordered `plan`; the generated C header pins each opcode code with a static assert, the `HANDLED` cover, the slot offsets plus the alias assert, the `HALF_LOW`/`HALF_HIGH`/`ACCESS_*` codes, the half-offset macro, per-opcode `ACCESS`/`HALVES`/`INDEX`/`SELECT(N)` macros, and the four-way `INDEX` chain; the hand module restates the four ordered half plans independently (`arm64VregPlanSpec`) and proves the plan and half-count refinements by `cases <;> rfl`, the access dispatch, the half plans, the distinct-slot and `.Q0`-distinct-halves facts, the arm-index dispatch, and the low and high half slot-offset examples; the host oracle drives the `SELECT`/`HALF_OFFSET`/`INDEX`/`ACCESS`/`HALVES` selectors against a full reimplementation of all four transfer bodies over a pristine state ---- 9216 cases) got its own single-family harness (Step 0209; 57 single-anchor rows over six files --- the spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 6 / lean_chain 26 / host 15 with 10 equivalences: seven unreachable generator error-message repaints, the internally-consistent `HALF_LOW` index repaint, and the two host OK/FAIL message repaints; the consumed generated defs (`halfOffset`, plan lengths) repaints on the generated Lean side are catches through `Arm64DqMemExtraShape`).
  The AArch64 multiply-family contract (the eight arms the simulator's multiply handler applies before the width-narrowing register write: `ARM64_OP_MADD` 0x0a, `MSUB` 0x0b, `MUL` 0x0c, `UMULL` 0x0d, `UDIV` 0x0e, `UMULH` 0x2e, `UMADDL` 0x3b, `SMADDL` 0x40 --- the opcodes are non-contiguous so `load()` parses `kprog/arm64/arm64_sim.h` and exits 1 on any drift, cross-checks `arm64_flags_spec.json` so no multiply mnemonic is declared a flag family, and the emitted static asserts pin the same values at compile time; each spec row carries name/code/macro plus per-arm `lean`/`c` strings, UMULH's C arm is the hoisted four-partial-product radix-`2^32` ladder rather than an expression string and its Lean arm is the same ladder as a `let` chain; the hand module restates the radix decomposition and carry lemmas, the algebraic `arm64MulUmulhNatAlg`, the ladder identity against the `Nat` high word (also consumed by `X86MulxHandler`), the sign extension helper, and an independent `arm64MulValueSpec`, and proves the refinement per arm (`simp`/`bv_decide`/ladder lemma), the width and NZCV compositions, the code range and dispatch, and eight canonical `native_decide` examples; the host oracle drives the macro over 20 boundary vectors x 8 ops plus a 20000-iteration fixed-seed LCG sweep --- 160160 value cases --- against an architectural `unsigned __int128` UMULH oracle and forks the `default` arm to prove unsupported opcodes abort) got its own single-family harness (Step 0210; 72 single-anchor rows over six files --- the compact one-line spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 4 / lean_chain 34 / host 15 with 19 equivalences: ten unreachable generator error-message repaints, the unused `mnemonic` string repaint, a whitespace-only generated arm edit, the coverage assert repainted onto another family opcode, the unused `flags_unchanged`/`code_in_range` renames, the unsupported-probe code repaint, the two OK/FAIL message repaints, and the randomized-sweep LCG seed).
  The x86 memory-unary handler-composition contract (the `INC/DEC/NEG/NOT [mem]` composition every unary-memory-op handler shares --- the hand Lean module `X86MemUnaryHandler.lean` IS the contract (no dedicated spec/generator exists for this family): `generatedX86MemUnaryStep` loads via `GeneratedX86MemAccess.load byte width`, forms `{ dst := { bits := lhs, tag := .scalar }, flags := flags }`, and dispatches `op` to the `generatedX86{Inc,Dec,Neg,Not}LaneHandler` from `X86UnaryWriteback.lean` at the `.low` lane; `generatedX86MemUnaryByte` writes `GeneratedX86MemAccess.store out.dst.bits width i` for `i < GeneratedX86MemAccess.byteCount width` and fetch-through `byte i` else; `x86_mem_unary_step_refines` (`cases op <;> simp only [...] <;> rw [x86_mem_load_refines]` then one `exact x86_{inc,dec,neg,not}_lane_handler_refines` per op), `x86_mem_unary_byte_refines` (`rw [x86_mem_unary_step_refines, x86_mem_byte_count]` + `by_cases` + `rw [x86_mem_store_byte_refines]` in the in-bound arm), and `x86_mem_unary_handler_refines` (flags and per-byte conjunction) close the composition, and a `native_decide` example pins the w8 `NEG 0x80` minimum (`cf := false, zf := true, sf := false, of := false` in, byte 0 stays `0x80` after negation of the signed minimum, byte 1 unchanged at `0xa5`, flags out `{ cf, !zf, sf, of }`), the dedicated host `test_x86_mem_unary_handler_host.c` Makefile-wires the two detectors (`lake build KProgFormal.X86MemUnaryHandler` olean refresh then `lake env lean`, then direct `cc -Wall -Wextra -O1 -I.` recompile+run --- the Makefile binary is cache-mtime-stale, so the detector must compile its own binary) and drives `generated_run` --- the real macro chain `KPROG_X86_MEM_LOAD` & width mask, per-op `KPROG_X86_ADC_RESULT` / `KPROG_X86_SBB_RESULT` / `KPROG_X86_NOT_RESULT` plus `KPROG_X86_SET_{ADD,SUB}_FLAGS` / `KPROG_X86_PRESERVE_FLAGS`, `KPROG_X86_MEM_STORE` --- against an independent modular-`__int128`/`signed_value` oracle (2^width wrapping +1 / -1 / 0-a / ~a, signed-overflow bounds `out.of = sr < lo || sr > hi`, per-byte store-back) over 4 ops x 4 widths x 8 lhs vectors x 16 flag tuples = 2,048 boundary cases plus a 20,000-iterate LCG sweep = 22,048 cases comparing `memcmp(got_mem, want_mem, 16)` + four flag fields, `build/mut_x86_mem_unary.py` (untracked) runs 83 single-anchor rows over the two files with the two detectors: 63 caught (26 host / 37 lean) and 20 pinned equivalents (the MEM_LOAD `& m` drop the read macro's internal width masking absorbs --- live-probed rc 0 OK 22048, the uniform mem-fill `0xa0+i` seed repaint the 22,048-case membership preserves, the f-bit decode repaint `{ f&1, f&1, ... }` whose boundary sweep re-derives the same flag set, the `- 1` memcmp-length repaint the byte-exact image keeps because lane bytes beyond the width coincide, six banner/mismatch repaints no oracle validates, the acceptance-preserving vector/width-table/loop-bound/LCG keep-alives (constant +1, LCG bound -1, `v[1] 1->3`, `w[2] 4->8`, `a<7`, `f<15`, `i&3`->`i&2` op spread, `(i>>2)`->`(i>>1)` width spread), the `rw`-lemma reorder proving the same goal, and two zero-external-consumer theorem renames (`x86_mem_unary_handler_refines`, `x86_mem_unary_neg_w8_min_example` --- the step/byte refine-theorem renames ARE caught at `lake build` because the handler conjunction consumes the byte lemma and the example consumes the step theorem), greens `TOTAL 83 mutations, 0 failures, 83 equivalences survived` / `ALL AS EXPECTED` rc 0, sorted-SURVIVED md5 `ddf6b4e59372e7e9e149975244faaaeb`, pins `ef930c35189855f121015b5c4be1cc1b` (host) + `fbf485f0c3106b91da3d975d4d49c0d1` (hand module) verified after every batch, `make check` stayed at 210 `: OK`), 0250 notes: the `let out :=` per side and the four `exact`-arm bullets needed statement-context anchors, and shake 1's single UOS row (`host_load`) was live-probed rc 0 OK 22048 and reclassified equivalent before the greens.
  The x86 memory-store ALU handler-composition contract (the `ADD/ADC/SUB/SBB [mem], rhs` composition every register-destination-memory arithmetic handler shares --- the hand Lean module `X86MemStoreAluHandler.lean` IS the contract (no dedicated spec/generator exists for this family): `generatedX86MemDestArithStep` loads via `GeneratedX86MemAccess.load byte width`, forms `{ dst := { bits := lhs, tag := .scalar }, flags := flags }`, and dispatches `op` to the `generatedX86{Add,Adc,Sub,Sbb}Handler` from `X86MemAluHandler.lean`; `generatedX86MemDestArithByte` writes `GeneratedX86MemAccess.store out.dst.bits width i` for `i < GeneratedX86MemAccess.byteCount width` and fetch-through `byte i` else; `x86_mem_dest_arith_step_refines` (`cases op <;> simp only [...] <;> rw [x86_mem_load_refines]` then one `exact x86_{add,adc,sub,sbb}_handler_refines` per op), `x86_mem_dest_arith_byte_refines` (`rw [x86_mem_dest_arith_step_refines, x86_mem_byte_count]` + `by_cases` + `rw [x86_mem_store_byte_refines]` in the in-bound arm), and `x86_mem_dest_arith_handler_refines` (flags and per-byte conjunction) close the composition, and a `native_decide` example pins the w16 `ADC 0xffff` (`cf := true, zf := false, sf := true, of := true` in, zero-with-carry out, byte 2 unchanged at `0xa5`), the dedicated host `test_x86_mem_store_alu_handler_host.c` Makefile-wires the two detectors (`lake build KProgFormal.X86MemStoreAluHandler` olean refresh then `lake env lean`, then direct `cc -Wall -Wextra -O1 -I.` recompile+run --- the Makefile binary is cache-mtime-stale, so the detector must compile its own binary) and drives `generated_run` --- the real macro chain `KPROG_X86_MEM_LOAD` & width mask, per-op `KPROG_X86_ADC_RESULT` + `KPROG_X86_SET_{ADD,ADC,SUB,SBB}_FLAGS`, `KPROG_X86_MEM_STORE` --- against an independent modular-`__int128`/`signed_value` oracle (2^width wrapping add-with-carry / sub-with-borrow, `out.cf = wide >= mod` vs `a < b + carry`, `out.of = sr < lo || sr > hi`, per-byte store-back) over 4 ops x 4 widths x 8 lhs vectors x 8 rhs vectors x 2 carry tuples = 2,048 boundary cases plus a 20,000-iterate LCG sweep = 22,048 cases comparing `memcmp(got_mem, want_mem, 16)` + four flag fields, `build/mut_x86_store_alu.py` (untracked) runs 65 single-anchor rows over the two files with the two detectors: 48 caught (34 host / 14 lean) and 17 pinned equivalents (the MEM_LOAD `& m` drop the read macro's internal width masking absorbs --- live-probed rc 0 OK 22048, the uniform-alias `got_mem`/`want_mem` swap the equal-fill equalizes, six banner/mismatch repaints no oracle validates, the acceptance-preserving vector/width-table/loop-bound/LCG keep-alives the 22,048-case membership preserves, the `rw`-lemma reorder proving the same goal, and four zero-external-consumer theorem renames the hand module's own proof chain closes over --- the two byte/step refine-theorem renames ARE caught at `lake build` because the handler conjunction consumes the byte lemma and the example consumes the step theorem), greens `TOTAL 65 mutations, 0 failures, 65 equivalences survived` / `ALL AS EXPECTED` rc 0, sorted-SURVIVED md5 `0c3a6bcfd54537feb48c6b4bee77dc5b`, pins `e830477045b30bb73282c6c8bb1d252e` (host) + `b0c6d5d4449d89bb3a49e0f76839f52d` (hand module) verified after every batch, `make check` stayed at 210 `: OK`), 0249 notes: four anchors needed statement-context (the two `let lhs :=` per side and the two `exact`-arm bullet rows) and the first shake's five UOS rows were live-probed and reclassified (3 caught, 2 equivalent) before the greens.
  The x86 BMI2 memory-source shift handler-composition contract (the `SHLX/SHRX/SARX dst, [mem], count` + `RORX dst, [mem], imm8` composition the four flagless opcodes share --- the hand Lean module `X86MemShiftHandler.lean` IS the contract (no dedicated spec/generator exists for this family): `generatedX86MemShiftStep` loads via `GeneratedX86MemAccess.load byte width` and dispatches `op` to the `GeneratedX86ShiftResult.{shl,shr,sar} lhs count width` kernels, `generatedX86MemRorxStep` rotates via `GeneratedX86ShiftResult.ror`, both write back through `generatedX86RegWrite state.dst result width` and thread the incoming flags through unchanged (`x86_mem_shift_preserves_flags`, `x86_mem_rorx_preserves_flags` --- the property separating the BMI2 forms from their flag-writing legacy counterparts); `x86_mem_shift_step_refines` closes `generatedX86MemShiftStep` against the independently stated `x86MemShiftStepSpec` (`cases op <;> simp only [generatedX86MemShiftStep, x86MemShiftStepSpec, x86_mem_load_refines, x86_reg_write_refines, x86_shl/shr/sar_result_refines]`) and `x86_mem_rorx_step_refines` the rotate against `x86MemRorxStepSpec` through the complementary-count `x86_ror_result_refines`; three `native_decide` examples pin the 32-bit `SHLX` zero-extension (`0xffffffffffffffff` -> `0x0000000000000002`, scalar tag), the 8-bit `SARX` sign-fill (`0x80` -> `0xc0`, upper bytes preserved), and the 8-bit `RORX` low-bit-to-top (`0x81` -> `0xc0`), the dedicated host `test_x86_mem_shift_handler_host.c` Makefile-wires the two detectors (`lake build KProgFormal.X86MemShiftHandler` olean refresh then `lake env lean KProgFormal/X86MemShiftHandler.lean`, then direct `cc -Wall -Wextra -O2 -I.` recompile+run --- the Makefile binary is cache-mtime-stale, so the detector must compile its own binary) and drives `generated_run` --- the real macro chain `KPROG_X86_MEM_LOAD` / `kprog_x86_{shl,shr,sar,ror}_result` / `KPROG_X86_WRITE_REG{8,16,32,64}` --- against an independent byte-loop oracle (per-byte little-endian `oracle_load`, width-masked shift/rotate under the 63/31 `KPROG_X86_SHIFT_COUNT` BMI2 mask, w8/w16 byte-merge vs w32 zero-extension `oracle_write`) over 4 ops x 4 widths x 8 mem vectors x 8 count vectors = 1,024 boundary cases plus a 20,000-iterate LCG sweep = 21,024 cases, `build/mut_x86_mem_shift.py` (untracked) runs 70 single-anchor rows over the two files with the two detectors: 42 caught (18 host / 24 lean), 28 pinned equivalents (scalar-tag repaint the `(void)tag` discards, oracle `0xfffff`-mask / byte-shifted fill / buffer-alias repaints the uniform mem bytes equalize, the vector/width-table/loop-bound/LCG-member keep-alives the 21,024-case membership preserves, six banner/mismatch repaints no oracle validates, zero-external-consumer theorem renames, the `rw`-lemma-line reorder that proves the same goal, the `x86MemRorxStepSpec` flags-restatement the value-equality `::= rfl` proves), greens `TOTAL 70 mutations, 0 failures, 70 equivalences survived` / `ALL AS EXPECTED` rc 0, sorted-SURVIVED md5 `874c6236fca2efc2296b1e6863aff9f5`, pins `abca7add007000c8ceb4a364f5d90628` (host) + `0b9743de9df880b877e8ff2081ad48ed` (hand module) verified after every batch, `make check` stayed at 210 `: OK`), 0248 notes: the four anchors needing statement-context (the two `let lhs :=` per side, the sar-arm writeback, the RORX-field needle), and the four live-probe reclassifications (`lean_step_rw_sar` caught at the `lake build` stage, `host_gen_write_w8` scalar-tag repaint acceptance-equal, `lean_rorx_flags_body`, `lean_ex_rorx_value`).
  The x86 memory-logic handler-composition contract (the `AND/OR/XOR [mem], rhs` composition every one of the three ops shares — the hand Lean module `X86MemLogicHandler.lean` IS the contract (no dedicated spec/generator exists for this family): `generatedX86MemLogicStep` loads via `GeneratedX86MemAccess.load byte width`, forms `{ dst := { bits := lhs, tag := .scalar }, flags := flags }`, and dispatches `op` to the `generatedX86{And,Or,Xor}RegLaneHandler` from `X86AluWriteback.lean` at `.low .low` lanes; `generatedX86MemLogicByte` writes `GeneratedX86MemAccess.store out.dst.bits width i` for `i < GeneratedX86MemAccess.byteCount width` and fetch-through `byte i` else; the three refine theorems close the step through `x86_mem_load_refines` plus one `exact x86_{and,or,xor}_reg_lane_handler_refines` per op, the byte through `rw [x86_mem_logic_step_refines, x86_mem_byte_count]` + `by_cases` + `rw [x86_mem_store_byte_refines]`, and the handler conjunction through both), the dedicated host `test_x86_mem_logic_handler_host.c` drives the real macro set — `KPROG_X86_MEM_LOAD … & KPROG_X86_WIDTH_MASK`, `KPROG_X86_SET_LOGIC_FLAGS(…, r == 0, !!(r & KPROG_X86_WIDTH_SIGN_MASK(w)))`, `KPROG_X86_MEM_STORE` — through the `generated_run` composition against an independent 128-bit-mod `oracle_run` (the byte-exact `memcmp` + four-flag comparison validates the oracle side too: any accept-side oracle repaint diverges from the generated composition on one of the 21,536 cases) (Step 0247; 66 single-anchor rows over the two files — the hand module and the host — with two detectors, the `lake build KProgFormal.X86MemLogicHandler` olean-refresh + `lake env lean` Lean chain and the direct `cc -Wall -Wextra -O2 -I.` compile+run of the host (the Makefile-built binary is cache-mtime-stale when only the source changes, so the detector must compile into `build/` itself), 44 caught (30 host, 18 lean) and 22 pinned equivalents (theorem renames with zero external consumers — the hand module's own proof chain closes over its own defs; same-file renames `lake env lean` cannot flag because the stale olean consumed is the file's own; the acceptance-preserving vector-table/loop-bound/LCG-reshape repaints the 21,536-case membership keeps live; and the banner/mismatch-format repaints no oracle validates). Two consecutive green shakes `TOTAL 66 mutations, 0 failures, 66 equivalences survived` sorted-SURVIVED md5 `360c4ac749510e6de799a72611eb92b9`; the Makefile target stayed wired (the detector duplicate-compiles the host source into `build/` only), Pins: `test_x86_mem_logic_handler_host.c` `e42979cff26b879f423641b4db334924`, `KProgFormal/X86MemLogicHandler.lean` `83e6ed88a052c52f91bba3481850da95`.
  The x86 logic-flags contract (the two-input logical-result flag transition every ALU results step writes through — `KPROG_X86_SET_LOGIC_FLAGS(C_CF, C_ZF, C_SF, C_OF, ZERO, SIGN)` sets `CF = 0`, `ZF = ZERO`, `SF = SIGN`, `OF = 0` and the generated Lean `GeneratedX86LogicFlags.eval` restates the same four arms; the hand module `X86LogicFlags.lean` states the independent spec `x86LogicFlagsSpec`, proves `x86_logic_flags_refine` by `rfl`, and bridges through the condition-to-next-PC decision with `x86_logic_branch_refines`; `X86AluWriteback.lean` consumes both sides at sixteen sites and `X86_SIM_L_SET_LOGIC_FLAGS` (the ALU-flag dispatch default arm, the ANDN body, the CMP/TEST logic arm) is the macro's only C consumer), the single-line spec pins the schema/operation metadata and the four flag expressions (`cf`/`of` const-false, `zf` input `zero`, `sf` input `sign`), and the generator re-checks the whole expected dictionary (shape gate, canonical `["cf","zf","sf","of"]` order, three-arm expression whitelist) exactly and re-renders the Lean module and C header byte-for-byte. `build/mut_x86_logic_flags.py` (untracked): 82 rows over the five contract files with two detectors (`gen` byte-exact check; `lean_chain` = `lake build KProgFormal.X86LogicFlags` olean refresh then `lake env lean` — no dedicated host, the reg-read precedent). 71 rows catch (58 at the generator stage, 13 through the Lean chain) and 11 survive as documented equivalents (the four failure-path-only generator message repaints, the two value-identical `expr()` literal-token repaints, the `is_file`-check elimination and newline-appending write repaints into the regenerate-only branch, the `#endif` comment repaint, the consumer-free `x86_logic_branch_refines` rename, and the `rw` lemma-list reorder proving the same goal).
  The x86 branch-emit emission-shape contract (the emitted shape behind the simulator's `X86_SIM_X86_JCC` conditional-branch emission — the generated macro `KPROG_X86_BRANCH_BACKWARD(CURRENT, TARGET)` is the bare address-ordering test `TARGET <= CURRENT` where the equality boundary is the backward shape, and the generated Lean defs `GeneratedX86BranchEmit.shape`/`nextPc` carry the two one-armed constructor shapes whose next PC is `target` exactly when the predicate holds and falls through otherwise), the consumers of the routed macro (`x86_sim_local_bpf.h` `X86_SIM_X86_JCC_IMPL` and the micro-prog bpftrace user) and of the generated `nextPc` (`GeneratedControlFlowTrace.emittedStep`, folded over whole traces so the bridge feeds the trace-level refinement too); the hand module (`X86BranchEmit.lean`) states the independent spec `x86BranchEmitShapeSpec` as `decide (target ≤ current)` and proves the emission bridge `x86_branch_emit_refines` (`nextPc (shape current target) taken fallthrough target = branchPc taken fallthrough target` by `split <;> split <;> rfl` on the direction and then the predicate), plus the shape-irrelevance pair and the per-shape direction facts — the direction decides only how the jump is written, never whether it is taken. Got its own single-family harness (Step 0245; 110 single-anchor rows over seven files --- the `x86_branch_emit_spec.json` spec, its generator, the generated C macro header, the generated Lean shape module, the hand refinement module, the contract host, and the route host; 4 detectors --- gen `--check` re-render, lean\_chain olean-then-`lake env lean`, contract host recompiled per row, route host recompiled with the simulator include set --- split gen 53 (10 spec + 32 generator + 6 stale-C + 5 stale-Lean) / lean\_chain 25 / host 16 / route 44, 32 equivalences: the cc-code set and unsupported-code repaints are sweep-membership-preserving (the model never distinguishes 11 vs 12), the contract-host 9-entry address sample resample keeps the equal/strictly-greater boundary probes live, banner/fail-return/mismatch-format repaints have no validating consumer, and the `nextPc` unfold-drop plus the consumer-free hand renames (`x86_branch_emit_refines`, `x86_branch_emit_shape_irrelevant`, `x86_branch_emit_taken`, `x86_branch_emit_not_taken`) survive because the shape-irrelevance goal closes by `rfl` without the unfold and every one-consumer external caller sees only `GeneratedX86BranchEmit.nextPc`).
  The x86 doubleshift handler-composition contract (the two `X86_OP_SHLD`/`X86_OP_SHRD` simulator bodies sharing one composed double-precision shift step (the pair registers `pairDS` puts `(dst,src)` into one 128-bit doubled word and `pairSD` the reverse, SHLD shifts `dst` left filling from the top of `src` and SHRD shifts `dst` right filling from the bottom, the count comes from the simulator's `KPROG_X86_SHIFT_COUNT` (63 for the 64-bit width, 31 otherwise), so at narrow widths the count exceeds the width and the `k >= bits` arm is live (the whole result from `src` shifted by the excess), both bodies are total over the four `X86_WIDTH_*` codes and write no flags — the handlers set them separately), the direct consumer of the `X86DoubleShiftArmHandler` count-zero gate and canonical-example theorems; the hand module restates the count-masked pair composition independently (`x86ShldSpec`/`x86ShrdSpec` over `pairDS`/`pairSD`) and proves `x86_shld_refines`/`x86_shrd_refines` by `bv_decide` per width, the zero-count identity `x86_doubleshift_zero_count`, and the two canonical examples, and the 32544-case host sweeps a boundary vector set, an `s < 64` count sweep, and a 20000-iteration LCG random sweep over both directions against internal oracles. Got its own single-family harness (Step 0244; 112 single-anchor rows over six files --- the `x86_doubleshift_spec.json` spec, its generator, the generated C double-precision shift header, the generated Lean width-table module, the hand refinement module, and the host oracle; 3 detectors --- the `--check` re-render, Lean chain, host recompiled per row --- split gen 55 (5 spec + 26 generator + 12 stale-C + 12 stale-Lean) / lean_chain 20 / host 13, 24 equivalences: four failure-path generator message repaints; four consumer-free renames confirmed by the zero-consumer scan (`x86_shld_refines`, `x86_shrd_refines`, `x86_shld_w64_example`, `x86_shrd_w8_example` — the count-zero theorem and both examples keep exactly one external consumer each, `X86DoubleShiftArmHandler.lean`); five measured survivors — the `x86Doubleshift`-lowercase-`S`, `shld`-direction-flip, and whitespace spec repaints that still satisfy the parsed-dict `--check`, banner/mismatch-format and sweep-bound repaints no oracle validates, and the `pairDS` bits-guard repaint the sweep never reaches).
  The x86 CMOV handler-composition contract (the two `X86_OP_CMOV` 0x15 / `X86_OP_CMOV_MEM` 0x40 simulator bodies sharing one composed conditional-move step (the condition sources `wholeWord` (`KPROG_X86_CMOV_CONDITION(AUX) (AUX)`, the whole AUX word — not the SETcc family's low byte) vs `sourceShift` (`KPROG_X86_CMOV_MEM_CONDITION(AUX) ((__u8)(((AUX) >> 24) & 0xffU))`, the AUX high half), the 14 accepted condition codes (o no b ae e ne be a s ns l ge le g at 0-9 then 12-15, rejecting the parity pair 10/11), the width chain `KPROG_X86_CMOV_WIDTH(FLAGS) ((FLAGS) ? (FLAGS) : X86_WIDTH_64)` with `X86_WIDTH_64 == 8U`, the memory form's two-level width fallback `KPROG_X86_CMOV_MEM_WIDTH(AUX, FLAGS)` — the AUX `mem_width` byte when it names one, the resolved-FLAGS fallback the `X86_MEM_AUX_MEM_WIDTH` decoder feeds with `flags_width` when it does not — a second width independent of the write width, the sign-extended high-half displacement `KPROG_X86_CMOV_MEM_DISP(IMM) ((__s64)(__s32)((IMM) >> 32))`, and the writeback selection `IS_64 ? KPROG_X86_CMOV_WRITEBACK_POINTER_TAG (0U) : KPROG_X86_CMOV_WRITEBACK_SCALARIZE (1U)` — only the 64-bit width can preserve the source's provenance tag through the 0235 pointer-write kernel, every narrower resolution scalarizes through `generatedX86RegWrite`), the direct consumer of the 0235 byte-reversal-side helpers and the shared `GeneratedX86MemDispatch.valueSrc` selector. Spec pins the two opcode rows (op/define/code/condition source), both condition-source rows (define/code/decoder/lean alias), the two writeback rows (is64/writeback/define/code), the width row (`X86_WIDTH_64` code 8 over `flags`), the memory-width row (`aux_mem_width` shift 16 mask 0xff with `X86_MEM_AUX_MEM_WIDTH` decoder and `flags_width` fallback), the disp row (`imm_high_half` shift 32 `dispSpec`), and the 14 condition-code rows; the generator re-checks the whole expected dictionary exact plus per-row order/code checks and renders the Lean module and C header byte-for-byte) consumed by the real `X86_SIM_L_EXEC_CMOV`/`X86_SIM_L_EXEC_CMOV_MEM` bodies in `x86_sim_local_bpf.h` through the `KPROG_X86_CMOV_*` selectors — no direct Lean downstream consumer (the hand module restates every table independently and its proofs close over its own defs) — and by two dedicated hosts; the 162-row mutation census catches 128 mutations (88 at the generator stage covering the spec fields, the opcode/condition/writeback/width/disp tables, byte-exact renders, header bytes, and generated arms, 40 through the Lean chain — both independent source tables, the whole-word vs high-half condition decoders, the condition-source and writeback selections, both step bodies, and the step refinement chain, 0 in the two host sweeps) with 34 documented equivalences (5 failure-path-only generator message repaints, 26 consumer-free hand-theorem renames — the hand module restates every table independently and its proofs close over its own defs — and the three banners across the contract and route hosts).
  The x86 CALLMEM handler-composition contract (the four `X86_OP_CALL_MEMCPY` 0x3f / `X86_OP_CALL_MEMCPY_REG` 0x46 / `X86_OP_CALL_MEMSET` 0x3c / `X86_OP_CALL_MEMSET_REG` 0x45 simulator bodies sharing one composed block-copy/block-fill step (the kind table `KPROG_X86_CALLMEM_KIND(OP_IS_COPY)` picks the byte-by-byte copy body for the two `MEMCPY` opcodes and the masked-byte fill body for the two `MEMSET` opcodes, the count source `KPROG_X86_CALLMEM_COUNT_SOURCE(OP_IS_REG)` reads the length from the instruction immediate for the plain opcodes and from `RDX` for the `_REG` opcodes, and the bound form `KPROG_X86_CALLMEM_BOUND_FORM(OP_IS_REG)` is the hardcoded literal `KPROG_X86_CALLMEM_FIXED_BOUND` `1024` for the plain opcodes and the immediate for the `_REG` opcodes, with the generator pinning their independence — `bound_is_imm` iff `count_source_is_reg` — and rejecting duplicate opcodes and any collapse), the direct consumer of the `GeneratedX86MemAccess.storeByte` masked-byte store; the hand module `X86CallMemHandler.lean` restates every table independently and proves both step bodies define identical effects, the bound/count independence, the fill byte is the value's low byte, and the beyond-bound bytes untouched. Got its own single-family harness (Step 0243; 153 single-anchor rows over seven files --- x86_callmem_spec.json, generate_x86_callmem_spec.py, generated/x86_callmem.h, KProgFormal/GeneratedX86CallMem.lean, KProgFormal/X86CallMemHandler.lean, test_x86_callmem_host.c (875-case host oracle), test_x86_callmem_route_host.c (52-case route host over the real `X86_SIM_L_EXEC_CALL_MEM*` bodies) --- split gen 80 (13 spec + 47 generator + 12 stale-C + 8 stale-Lean) / lean_chain 45 / host 0 / route 11, 17 equivalences: the four failure-path generator message repaints, ten consumer-free handler renames, the consistent-pair boundary repaint, and three banners no consumer validates).
  The x86 MOVBE handler-composition contract (the two `X86_OP_MOVBE_LOAD`/`X86_OP_MOVBE_STORE` simulator bodies sharing one composed byte-reversal step (the movbeLoad body reads the byte-length `GeneratedX86MemAccess.load` at the resolved width through the shared `GeneratedX86MemDispatch.valueSrc` arms (stackRead/abiPtrLoad/ordinary per the width's 64-ness) and applies the `bswap∘load` funnel through `generatedX86RegWrite`, the movbeStore body `GeneratedX86Bswap.value`-reverses its scalar source and writes it at the same resolved width through either the stack helper (`KPROG_X86_MOVBE_ARM_STACK`) or the ordinary little-endian store (`KPROG_X86_MOVBE_ARM_MEMORY`), both driven by `KPROG_X86_MOVBE_WIDTH(FLAGS_WIDTH)` (`FLAGS ? FLAGS : 64`, `KPROG_X86_MOVBE_WIDTH_ABSENT` for the opcode-without-FLAGS row) so one width rides the reversal, the access, and the written size — `x86_movbe_store_both_arms_use_one_width`/`x86_movbe_one_width_rides_all`; `KPROG_X86_MOVBE_DISP` takes the whole field sign-extended, never the imm-store high-half slice (`x86_movbe_disp_differs_from_imm_store`); `x86_movbe_store_load_round_trip`; the always-scalarizing `generatedX86RegWrite` and the shared arms stay in the load step, and the hand module restates every table independently and proves the load/store step refinements and the seven canonical examples); the single-line spec pins the two opcode rows (op/define/code/arm family), the five width rows (flags-width/width/define with the absent row's `KPROG_X86_MOVBE_WIDTH_ABSENT`), both disp rows (`signedImm`), and the two arm rows (`is_rsp` → `stackWrite`/`memoryStore` defines and codes); the generator re-checks the whole expected dictionary exact plus the per-row order/code checks and renders the Lean module and C header byte-for-byte) consumed by the real `X86_SIM_L_EXEC_MOVBE_LOAD`/`X86_SIM_L_EXEC_MOVBE_STORE` bodies in `x86_sim_local_bpf.h` through the `KPROG_X86_MOVBE_*` selectors — no direct Lean downstream consumer (the handler module rewrites with `x86_bswap_refines` from its own `X86Bswap` import) — and by two dedicated hosts; the 114-row mutation census catches 84 mutations (48 at the generator stage covering the spec fields, the per-row checks, byte-exact renders, header bytes, and generated-Lean arms, 36 through the Lean chain — both independent source tables, the imm32-independent width resolution, both step bodies, the stack-vs-memory arm table, the load/store step refinements, and the six broken-joint canonical-example repaints, 0 in the two host sweeps) with 30 documented equivalences (14 failure-path-only generator message repaints, 13 consumer-free hand-theorem renames — the handler's proofs are self-contained over its own defs — and the three banners across the contract and route hosts).
  The x86 bitops contract (the two bit-indexed kernels the BT and BZHI handler families apply through the generated-width path — `bt` reads the carry as the indexed bit of the narrowed base (`kprog_x86_bt_value`, `GeneratedX86Bitops.bt`) with the index hardware-masked to `width == 64-bit ? 63 : 31`, deliberately *not* the width's bit count for narrow widths (an 8-bit `bt` with offset 8 tests a bit the byte does not have, always clear), and `bzhi` clears every bit at or above the byte-masked index (`kprog_x86_bzhi_value`, `GeneratedX86Bitops.bzhi`), keeping the whole narrowed base when the index reaches the width; the generated Lean module carries `widthMask` as a four-arm code match, `bt` as shift-and-extract, `bzhi` as the `(1 <<< c) - 1` kept mask; the hand module restates the independent width mask from the `2^(8*code)` exponent (`x86BitopsMaskCode`) and proves `x86_bt_refines`/`x86_bzhi_refines` per width code by `bv_decide`, the closed width-code case set, the width-indexed `x86_bt_refines_width`/`x86_bzhi_refines_width` bridges, the bzhi within-width and max-index-keeps bounds, and four canonical examples); the single-line spec pins the schema/operation metadata and the four width rows (code/bits/index_mask 1/8/31, 2/16/31, 4/32/31, 8/64/63); the generator re-checks the whole expected dictionary exact plus the per-row bit-count mask-list checks and renders the Lean module and C header byte-for-byte) consumed inside `X86_SIM_L_EXEC_BZHI*`/`X86_SIM_L_EXEC_BT*` in `x86_sim_local_bpf.h`, on the Lean side by `X86BtHandler` (`x86_bt_refines_width` rewrites), `X86BzhiHandler` (`x86_bzhi_refines_width` rewrites, `x86BitopsMaskCode` at the spec simp), and `X86MemBitHandler` (both width bridges), and by one dedicated contract host sweeping both macros against independent bit-mask oracles; the 59-row mutation census catches 47 mutations (36 at the generator stage covering the spec fields, byte-exact renders, header bytes, and generated-Lean arms, 9 through the Lean chain — both independent spec defs, the `x86BitopsMaskCode` body, the two per-code refines renames, the closed-case rename, and both width-bridge renames, 2 in the contract-host oracle sweep) with 12 documented equivalences (the four failure-path-only generator message repaints, five consumer-free hand-theorem renames, two host banner repaints).
  The x86 popcount contract (the 64-bit population count the simulator's POPCNT handler applies to the narrowed source operand — `kprog_x86_popcount_value` and `GeneratedX86Popcount.value` are the standard SWAR reduction (pairwise `v1`/`v2`/`v3` masking steps, then the byte-gather multiply `* 0x0101...0101` shifted right by 56; the operand is evaluated once and no flags written at this layer); the hand module (`X86Popcount.lean`) states the independent claim as eight byte lanes (`laneByte` extracts `x >>> 8*i` masked to `0xff`, `bytePop` walks the eight bits explicitly with no shared SWAR constant) whose per-lane counts sum via `setWidth 64` (`x86PopcountSpec`), proving `x86_popcount_refines` by `bv_decide` over the two unrelated encodings plus the ≤64 bound and the zero/one-bit/all-bits/alternating canonical theorems) consumed in `x86_sim.h`'s `x86_popcount64` (applied by the `KPROG_X86_DISP_POPCNT_HANDLED` arm of the local-BPF dispatch), by the dispatch-singleton route host, and by a dedicated contract host sweeping a boundary vector set and a 20000-iteration LCG sweep against a one-bit-at-a-time oracle with an additive split-consistency check; the 45-row mutation census catches 35 mutations (25 at the generator stage covering the spec fields, byte-exact renders, header bytes, and SWAR bit-mask arms, 8 through the Lean chain — the `laneByte`/`bytePop` helpers, the per-lane sum, and the `x86_popcount_refines` rename, 2 in the contract-host oracle sweep) with 10 documented equivalences (the two failure-path-only generator message repaints, the bytePop lane-0-swap and lane-7-drop same-sum mutations, five consumer-free hand-theorem renames, two host banner repaints).
  The x86 BZHI handler-composition contract (the two `X86_OP_BZHI`/`X86_OP_BZHI_MEM` simulator bodies sharing one composed step — resolve one width `FLAGS ? FLAGS : 64` through `KPROG_X86_BZHI_WRITE_WIDTH` and use it for *both* the value read and the destination write (no second AUX memory width, unlike `ANDN_MEM`), select the value source from a per-opcode register/memory table through `KPROG_X86_BZHI_VALUE_SOURCE`, select the bit count from a per-opcode register/AUX-shift table through `KPROG_X86_BZHI_COUNT_SOURCE` with the count byte-masked (`KPROG_X86_BZHI_COUNT_MASK 0xff`), clear every bit at or above the count, and derive the flags by hand — `OF=SF=0` outright, `ZF` the real zero test of the cleared value, `CF` the comparison of the byte-masked count against the resolved width — with `GeneratedX86Bitops.bzhi` the shared per-width consumer from the 0236 bitops contract; the hand module restates the tables independently and proves the refinements plus the differ/masks-to-byte/clears-SF-OF/count-vs-width laws); the single-line spec pins the two opcode rows (define/code/value/count), the 64-bit width default, and the 0xff count mask; the generator re-checks the whole expected dictionary exact and renders the Lean module and C header byte-for-byte; consumed by the real `X86_SIM_L_EXEC_BZHI*` bodies in `x86_sim_local_bpf.h` through the `KPROG_X86_BZHI_*` selectors — no direct Lean downstream consumer (the handler module rewrites with `x86_bzhi_refines_width` from its own import of `X86Bitops`) — and by two dedicated hosts; the 90-row mutation census catches 58 mutations (37 at the generator stage covering the spec fields, the render constants, byte-exact renders, header bytes, and generated-Lean arms, 21 through the Lean chain — both source tables, the width chain, the value/count read arms, the mask spec, the result/flags/step composition, 0 in the two host sweeps) with 32 documented equivalences (the ten failure-path-only generator message repaints, 19 self-proof renames of unconsumed hand theorems, and the three banners across the contract and route hosts).
  The x86 BT handler-composition contract (the three `X86_OP_BT`/`X86_OP_BT_IMM`/`X86_OP_BT_MEM_IMM` simulator bodies sharing one composed step — resolve one width `FLAGS ? FLAGS : 64` through `KPROG_X86_BT_WRITE_WIDTH`, select the tested base from a per-opcode register/memory table through `KPROG_X86_BT_BASE_SOURCE`, select the bit index from a per-opcode register/raw-immediate/32-bit-widened-immediate table through `KPROG_X86_BT_INDEX_SOURCE` (the memory form reads its index at 32 bits, not the raw 64-bit field), test the indexed bit of the narrowed base, and write only `CF` — riding `GeneratedX86Bitops.bt` as the shared per-width consumer from the 0236 bitops contract; the hand module restates all four tables and proves the refinements plus the base-source split, index-source-differ, imm32-drops-high-bits, dst-preserving and only-CF laws and three canonical examples); the spec pins three opcode rows (define/code/base/index) plus the width default; the generator re-checks the whole expected dictionary exact and renders `GeneratedX86Bt.lean` and `generated/x86_bt.h` byte-for-byte; consumed by the three real bodies in `x86_sim_local_bpf.h` through the `KPROG_X86_BT_*` selectors — no direct Lean downstream consumer (the handler module rewrites with `x86_bt_refines_width` from its own import of `X86Bitops`) — and by two dedicated hosts; the 75-row mutation census catches 46 mutations (35 at the generator stage covering the spec fields, the render constants, byte-exact renders, header bytes, and generated-Lean arms, 11 through the Lean chain — both independent source tables, the imm32 widening arm, and the step refinements, 0 in the two host sweeps) with 29 documented equivalences (the nine failure-path-only generator message repaints and `INDEX_ORDER` permutation, 16 self-proof-renames of unconsumed hand theorems, and the three banners across the contract and route hosts).
  The x86 signed-value contract (the two width-parameterised signed operations the IMUL handlers rely on — `kprog_x86_sign_extend_value`/`GeneratedX86Signed.signExtend` widen the narrowed operand from the access width's sign bit, the generated complement-and-subtract form `((v & mask) ^ sign) - sign` with the 64-bit width the identity, and `kprog_x86_abs_width_value`/`GeneratedX86Signed.absWidth` compute the width-domain magnitude (narrow, negate when the width's sign bit is set, re-narrow); the hand module restates the extension independently via `BitVec.signExtend` over `setWidth` (`x86SignExtendSpec`), mirrors the magnitude with `mask`/`signMask` (`x86AbsWidthSpec`), and proves both refinements by case-bash `bv_decide` plus the idempotent-magnitude, magnitude-bounded-by-the-sign-mask, two canonical examples, and the cross-contract `x86_abs_width_agrees_imul` agreement with the independently generated `GeneratedX86ImulFlags.signedAbs`); the single-line spec pins the schema/operation metadata and the four width rows (mask/sign/bits); the generator re-checks the whole expected dictionary exact plus the per-row bit-count check and renders the Lean module and C header byte-for-byte) consumed in `x86_sim.h`'s `x86_sign_extend64`/`x86_abs_width64` wrappers, the IMUL-reg-imm/mem-imul/mov-load/movx Lean handlers rewriting with `x86_sign_extend_refines`, the route dispatch host, and a dedicated contract host sweeping both helpers over a boundary vector set plus a 20000-iteration LCG sweep against oracle re-implementations; the 48-row mutation census catches 37 mutations (29 at the generator stage covering the spec fields, byte-exact renders, header bytes, and the sign-extension/abs arms, 6 through the Lean chain — both independent spec defs, the w8 sign-extension arm, the w8 abs condition flip, and the `x86_sign_extend_refines` rename, 2 in the contract-host oracle sweep) with 11 documented equivalences (the three failure-path-only generator message repaints, seven consumer-free hand-theorem renames, two host banner repaints).
  The x86 bswap/movbe contract (the shared byte-reversal kernel behind the `BSWAP`, `MOVBE_LOAD`, and `MOVBE_STORE` handlers — `kprog_x86_bswap_value(value, width)` and `GeneratedX86Bswap.value` reverse the access width's byte order and clear the bytes above it: w8 masked identity, w16 two-lane swap, w32 half-reversal of the swapped word (`swapped >> 32`), w64 eight-lane reversal, with a closed width set so there is no unsupported arm; the generated Lean module replaces the w16 fold with a `narrow`-masked two-lane assembly and the w32 arm as `r >>> 32` over an eight-lane build; the hand module restates the reversal independently as `x86BswapSpec` (per-byte `lane8` extractions re-assembled in reverse) and proves `x86_bswap_refines` by `bv_decide`, the involution `x86_bswap_involutive`, the w32 high-word clearing, and three canonical byte-order examples); the single-line spec pins the schema/operation metadata and the four width rows (name/bytes/code 1/1, 2/2, 4/4, 8/8); the generator re-checks the whole expected dictionary exact plus the per-row byte-count and code-list checks and renders the Lean module and C header byte-for-byte) consumed in `x86_sim.h`'s byte-reversal step, in `X86MovbeHandler.lean` (`x86_bswap_refines` rewrites; `exact x86_bswap_involutive value width` closes the movbe-elimination proof), and by two dedicated hosts — the contract host sweeps the macro against a byte-array reversal oracle, the route host drives the real BSWAP/MOVBE simulator bodies; the 54-row mutation census catches 43 mutations (37 at the generator stage across the five generated/hand files, 5 through the Lean chain — the `lane8` helper, the `x86BswapSpec` w64 arm, and the `refines`/`involutive` renames the movbe handler consumes, 1 in the contract-host oracle sweep, 0 in the route-host sweep) with 11 documented equivalences (three failure-path-only generator message repaints, four consumer-free hand-theorem renames, four host banner/stderr repaints).
  The x86 not contract (the one-opcode unary complement kernel — the result arm is the bytewise `KPROG_X86_NOT_RESULT(VALUE)` = `~(VALUE)` expression and the flag arm is the identity preservation `KPROG_X86_PRESERVE_FLAGS()` = `do{(void)0;}while(0)` of CF/ZF/SF/OF that the ALU flag-dispatch step calls in the NOT arm; the generated Lean module carries the `Flags` structure, the `BitVec.not`-based result, and the pass-through `flags` builder; the hand module adds the width-aware `x86NotWidthResultSpec` (narrow to the write width, then complement over the width mask) and proves the result/flag/branch refinements); the single-line spec pins the schema/operation metadata, the `bit_not`/`value` result row, and the `preserve` row listing the four flag inputs; the generator re-checks the whole expected dictionary exactly and renders the Lean module and C header byte-for-byte) consumed inside `X86_SIM_L_EXEC_ALU_FLAG_STEP` (arm NOT) by the ALU flag dispatcher, by `test_x86_mem_unary_handler_host.c` via `KPROG_X86_NOT_RESULT` — no dedicated host — and on the Lean side via `GeneratedX86AluResult` (ALU op `.not`) and `X86UnaryWriteback` (whose `x86_not_lane_handler_refines` rewrites with `x86_not_flags_refine` and `x86_not_narrowed_result_refines`, making those theorem renames catches while the consumer-free `x86_not_branch_refines` rename is an equivalence); the 52-row mutation census catches 49 mutations (44 at the generator stage covering the spec fields, byte-exact renders, header bytes, and generated-Lean arms, 5 through the Lean chain — `lake build` olean refresh in front of a downstream `X86UnaryWriteback` compile) with 3 documented equivalences (the two failure-path-only generator message repaints and the consumer-free `x86_not_branch_refines` rename).
  The x86 register-writeback contract (the scalar-tagged partial-register write kernel every composed simulator body writes its destination through — `KPROG_X86_WRITE_REG8(STORAGE, TAG, VALUE, BYTE_SHIFT, SCALAR_TAG)` takes its byte lane from the selected shift (`BYTE_SHIFT == 8U` writes `b[1]`, otherwise `b[0]`), `KPROG_X86_WRITE_REG16` stores `w`, `KPROG_X86_WRITE_REG32`/`REG64` store the respectively zero-extended and full value through the pointer-tagged union cell, and every form stamps the scalar tag; the generated Lean table is `bits` (w8/w16 preserve upper bits, w32 zero-extends, w64 replaces) with the lane-aware `bitsAt`/`writeAt` and tag-stamping `write` over a `Result{bits, scalarizes}`, the hand module restates the tables as `x86ByteShiftSpec`/`x86RegWriteBitsAtSpec`/`x86RegWriteBitsSpec` — written as XOR-masked updates rather than the generated or-masks — and proves fourteen refinements from `x86_reg_write_at_refines` to the upper-preservation, high-lane, counterexample, zero-extension, replacement, and scalarization facts); the single-line spec pins the schema/operation/tag metadata, the two byte lanes with their shifts (low 0, high 8), and the four widths with their bits and `preserve_upper` flags; the generator re-checks the whole expected dictionary exactly and renders the Lean module and C header byte-for-byte) consumed through the writeback macros by every composed simulator body in `x86_sim_local_bpf.h` and through the Lean primitives by every handler chain; no dedicated host — the macros' C consumers are exercised through the other families' route hosts; the 78-row mutation census catches 72 mutations (56 spec pins, byte-exact renders, header bytes, and generated-Lean arms at the generator stage, 16 hand-module breaks through the Lean chain — `lake build` olean refresh in front of a downstream `X86RegLaneAux` compile) with 6 documented equivalences (the two failure-path-only generator message repaints and four refinement-theorem renames with no post-definition consumer).
  The x86 andn contract (the two-opcode complement-and handler kernel the simulator consumes through `KPROG_X86_ANDN_WRITE_WIDTH(FLAGS)` / `KPROG_X86_ANDN_SOURCE(OP_IS_MEMORY)` / `KPROG_X86_ANDN_MEM_WIDTH_ARM(AUX_WIDTH_IS_ABSENT)` / `KPROG_X86_ANDN_MEM_WIDTH(AUX_WIDTH_CODE, FLAGS)` — `X86_OP_ANDN` 0x3d reads its second operand from a register, `X86_OP_ANDN_MEM` 0x44 from memory; both bodies compute `(~src1) & src2`, take CF=OF=0, derive ZF/SF from the result at the `FLAGS`-resolved write width (64 bits when the opcode carries no width code), and write the destination through the partial-register primitive; the memory form's access width is *independently selected*: the `X86_MEM_AUX_MEM_WIDTH(AUX)` field when it names one, the resolved-FLAGS fallback when the field is absent (zero) — a second width that is not the destination write width); the single-line spec pins the schema/selector metadata, both opcode rows with their sources, both mem-width arms with their defines and absence bits, and the 64-bit write-width default; the generator re-checks the whole expected dictionary exactly (op order/defines/codes/sources, arm order/defines/absence, duplicate-opcode and duplicate-arm predicates, the default) and renders the Lean `GeneratedX86Andn` module and C header byte-for-byte; the header pins both opcodes and the 64-bit width code with static asserts and emits the four selector macros; the hand module (`KProgFormal/X86AndnHandler.lean`) restates each table and proves the twenty refinements, including `x86_andn_step_refines`) consumed through the four selector macros inside `X86_SIM_L_EXEC_ANDN_STEP` by the two ANDN simulator bodies and the Lean handler; two dedicated hosts sweep the contract — the contract host drives the generated selector macros against a raw-opcode-bit restatement (1849 cases), the route host drives the real `ANDN`/`ANDN_MEM` simulator bodies (356404 cases); the 98-row mutation census catches 79 mutations (72 at the generator stage across the five generated/hand files, 7 through the Lean chain) with 19 documented equivalences (eleven failure-path-only generator message repaints, four consumer-free Lean theorem renames, and four host banner/stderr repaints).
  The x86 register-read contract (the byte-lane/width operand-observation kernel every composed simulator body reads its register operands through — `KPROG_X86_READ_REG_AT(VALUE, WIDTH, BYTE_SHIFT)`: byte-width reads take the lane byte at the selected shift and every wider width always observes the low lane, the single C consumer being `X86_SIM_L_READ_REG_WIDTH_SHIFT`; the generated Lean table is `w8`/`low` = `value & 0xff`, `w8`/`high` = `(value >>> 8) & 0xff`, `w16` = `value & 0xffff`, `w32` = `value & 0xffffffff`, `w64` = identity, the hand module restates it as `x86RegReadAtSpec`, and the header emits the single selector macro with the `WIDTH == X86_WIDTH_8 ? BYTE_SHIFT : 0U` lane gate behind `KPROG_X86_APPLY_WIDTH`); the single-line spec pins the schema, the operation name, the two byte lanes with their shifts, and the four widths with their bits; the generator re-checks the whole expected dictionary exactly and renders the Lean module and C header byte-for-byte) consumed through `X86_SIM_L_READ_REG_WIDTH_SHIFT` by every register-operand read in the composed simulator bodies and the Lean refinement (`x86_reg_read_at_refines` plus the `low8`/`high8` underline lemmas and the high-byte counterexample); no dedicated host — the selector's only consumer is exercised through the other families' hosts; the 64-row mutation census catches 61 mutations (17 at the spec file, 32 at the generator stage covering the header and generated-Lean pins, 8 through the Lean chain — which needs a `lake build` olean refresh in front of `lake env lean`, because `lake env lean` alone reads a stale `X86RegRead.olean` and silently passes every hand-module mutation) with 3 documented equivalences.
  The x86 callmem contract (the four-opcode block-copy/block-fill handler-composition kernel the simulator consumes through `KPROG_X86_CALLMEM_KIND(OP_IS_COPY)` / `COUNT_SOURCE(OP_IS_REG)` / `BOUND_FORM(OP_IS_REG)` / `FIXED_BOUND` — `X86_OP_CALL_MEMCPY` 0x3f, `X86_OP_CALL_MEMCPY_REG` 0x46, `X86_OP_CALL_MEMSET` 0x3c, `X86_OP_CALL_MEMSET_REG` 0x45; the kind table selects the byte-by-byte copy arm for the two `MEMCPY` opcodes and the masked-byte fill arm for the two `MEMSET` opcodes, the count-source table reads the length from the instruction-immediate artifact for the plain opcodes and from the `RDX` register for the `_REG` opcodes, and the bound-form table independently takes the hardcoded literal 1024 bound for every immediate-count opcode and the immediate bound for every register-count opcode, per iteration storing one byte at byte-addressed `dst[i]`/`src[i]` (copy) or the masked low byte (fill) and writing the `RAX`/`RDI` pointer tag from the destination pointer); the single-line spec pins the schema/selector metadata, the literal bound, all four opcode rows, the kind/count-source/bound-form rows with their defines, and the duplicate-opcode and bound/count-collapse predicates; the generator re-checks the whole expected dictionary exactly and renders the Lean module and C header byte-for-byte; the generated header adds the static-assert opcode pins plus the three selector macros; the hand module (`KProgFormal/X86CallMemHandler.lean`) restates each table and proves the fifteen refinements, including `x86_call_mem_bound_and_count_are_independent`); consumed through the three selector macros inside `X86_SIM_L_EXEC_CALL_MEM_STEP` by the four block-copy/block-fill simulator bodies and the Lean handler; two dedicated hosts sweep the contract — the contract host sweeps the kind/count/bound selector spaces plus the byte contracts (875 cases), the route host drives the real CALL_MEMCPY/CALL_MEMSET simulator bodies (52 cases); the 154-row mutation census catches 104 mutations (22 at the spec file, 31 at the generator, 7 at the generated header, 34 through the Lean modules, 11 by the contract host, 9 by the route host) with 50 documented equivalences.
  The x86 conditional-move contract (the two-form cmov kernel the simulator consumes through `KPROG_X86_CMOV_WIDTH` / `CONDITION` / `CONDITION_BYTE` / `MEM_CONDITION` / `MEM_WIDTH` / `MEM_DISP` / `WRITEBACK` — `X86_OP_CMOV` 0x15, `X86_OP_CMOV_MEM` 0x40; the register form reads its condition from the whole `AUX` word (`KPROG_X86_CMOV_CONDITION`) and writes the tagged pointer cell at 64-bit widths and the scalarizing partial-register cell otherwise; the memory form decodes its condition from the AUX high-byte shift (`KPROG_X86_CMOV_MEM_CONDITION`), resolves its access width through the two-level fallback from the AUX memory-width byte (`KPROG_X86_CMOV_MEM_WIDTH`) to the write width, and takes its displacement from the sign-extended artifact high half (`KPROG_X86_CMOV_MEM_DISP`), writing through the partial-register path at every width; the single-line spec pins the schema metadata, both opcode rows, both source-byte definitions, the fourteen condition codes, and the width/memory-width/displacement/write-back rows; the generator re-checks the whole expected dictionary exactly and renders the Lean module and C header byte-for-byte; the generated header adds the static-assert opcode/width pins plus the seven selectors; the hand module (`KProgFormal/X86CmovHandler.lean`) restates each table and proves the refinements, with `x86CmovByteConditionTable` sharing the x86-setcc condition table); consumed through the selector macros inside `X86_SIM_L_EXEC_CMOV_STEP` by the two conditional-move simulator bodies and the Lean handler; two dedicated hosts sweep the contract — the contract host sweeps the whole-word and byte condition spaces plus the writeback contracts (484369 cases), the route host drives the real CMOV/CMOV_MEM simulator bodies (26526735 cases); the 170-row mutation census catches 141 mutations (41 at the spec file, 48 at the generator, 14 at the generated header, 33 through the Lean modules, 5 by the two hosts) with 29 documented equivalences.
  The x86 condition-code contract (the sixteen-entry table the simulator consumes through `KPROG_X86_EVAL_CC` — codes `X86_CC_O` 0 through `X86_CC_G` 15 with flag predicates over CF/ZF/SF/OF (of, !of, cf, !cf, zf, !zf, cf||zf, !cf&&!zf, sf, !sf, sf!=of, sf==of, zf||(sf!=of), !zf&&(sf==of), 0, 0); the single-line spec pins every condition row and the generator re-checks the expected table and renders the Lean module and C header byte-for-byte; the header adds the static-assert code pins plus the `KPROG_X86_EVAL_CC` predicate ladder; the hand module defines `x86CondSpec` and proves `x86_condition_sound`, with generated setcc/cmov modules restating `evalCond`/`condOf`); consumed through the selector macro inside `X86_SIM_L_EVAL_CC` by the branch, cmov, setcc, and condition-mnemonic bodies; six hosts sweep the contract — the cmov and setcc contract hosts (484369 and 590726 cases), the cc-decode contract host (152 cases), and the cmov, setcc, and setcc-mem route hosts driving the real simulator bodies (26526735, 2433038, and 8958727 cases); the 114-row mutation census catches 103 mutations (24 at the spec file, 22 at the generator, 57 through the Lean chain) with 11 documented equivalents.
  The x86 compare-op contract (the shared CMP/TEST opcode kernel eight bodies route through — `KPROG_X86_CMPOP_RHS_SOURCE` / `FLAG_KIND` / `LHS_SOURCE` / `DISP_KIND` / `WRITE_WIDTH` selectors over the eight opcodes 0x0c/0x0d/0x0e/0x0f/0x1d/0x1e/0x1f/0x3b, immediate rhs for the `_IMM` forms and register otherwise, sub flags for CMP and logic flags for TEST, memory lhs and store/simm displacement for memory forms, 64-bit default write width for width-less opcodes; the single-line spec pins all eight rows and the generator re-checks the expected table and renders the Lean module and C header byte-for-byte; the header adds the static-assert opcode pins plus the per-opcode table and selectors; the hand module restates each table and proves the 18 refinements; consumed through the selector macros by the CMP/TEST simulator bodies and Lean handlers; two dedicated hosts sweep the contract — the contract host drives the 8-opcode table against an independent decode/flags model (2913 cases), the route host drives the real simulator bodies across five width codes, both displacement lanes, flag dispatch and direct execution (47529 cases); the 123-row mutation census catches 93 mutations (32 at the generator, 30 through the Lean chain, 9 on the contract host, 23 on the route host) with 30 documented equivalences).
  The x86 width-table contract (the operand-width kernel every simulator body and Lean handler composition routes through — `KPROG_X86_WIDTH_MASK(WIDTH)` / `GeneratedX86Width.mask`: four widths (8/16/32/64-bit with codes 1/2/4/8) each pin a mask, sign mask, and bit count, and a decoded width code of 0 (an absent width field) resolves to the 64-bit width — `KPROG_X86_WIDTH_EFFECTIVE` with the absent-code pin and the 64-bit default; the single-line spec pins the schema/operation metadata, the four width rows with their mask/sign-mask/bits fields, and the effective entry; the generator re-checks the whole expected table exactly (length, per-row keys, absent code not colliding with a width code, default) and renders the Lean `Width` module and the C header byte-for-byte; the hand module restates code/mask/signMask/bits plus `narrow`/`zero`/`sign` and proves the eight refinements, the effective-resolution laws (absent names no width, default is the 64-bit code, identity on real widths), and the sign-mask observability law; consumed through `X86_SIM_L_EFFECTIVE_WIDTH` by every routed body and 47 Lean modules; two dedicated hosts sweep the contract — the effective host drives the EFFECTIVE macro against an independent `code ? code : 64` model over the full decoded byte range (1280 cases), the route host drives the simulator's routed register/stack/memory/LEA/move/ALU/IMUL/flag bodies against the same model (518 cases); the 168-row mutation census catches 119 mutations (43 at the generator, 40 through the Lean chain, 11 on the effective host, 25 on the route host) with 49 documented equivalences).
  The x86 arithmetic-immediate contract (the shared widening rule consumed by every handler taking an instruction immediate — `KPROG_X86_IMMEDIATE_VALUE(VALUE, WIDTH)` / `GeneratedX86Immediate.value`: the 64-bit artifact field carries the immediate, the low 32 bits are the encoded value with exactly one sign-extend flag (`sign_extend_width: w64`) — 64-bit readers sign-extend the low word (`bit 31` test then recombination with `0xffffffff00000000`), narrower readers consume the zero-extended low word; the single-line spec pins the five metadata fields, the generator re-checks the whole expected dictionary exactly on every `--check` and renders the Lean combinator and the C macro byte-for-byte, the hand module restates the rule independently (`raw.setWidth 32`, `.w64` sign-extend 64, else `setWidth 64`) and proves `x86_immediate_value_refines` plus two `native_decide` sign-choose examples; consumed by the ALU writeback, bit-test, compare-op, imul-reg-imm, mem-compare, mem-imul, and store handlers and their host oracles, whose 4883-case bit-test and 2913-case compare-op drives exercise the zero-extend arm at a site-fixed `X86_WIDTH_32` and the sign-extend arm through a four-value immediate sweep; the 67-row mutation census catches 50 mutations (20 at the generator, 13 through the Lean chain, 9 on the bit-test host, 8 on the compare-op host) with 17 documented equivalences).
  The x86 MOV_STORE handler-composition contract (the single body `X86_SIM_L_EXEC_STORE` shared by `X86_OP_MOV_STORE_IMM` 0x07 and `X86_OP_MOV_STORE_REG` 0x08: the opcode's `FLAGS` code resolves the single write width — 64 bits when the opcode carries none, the same width for the immediate value and the memory write, and the stack arm re-derives the same `FLAGS ? FLAGS : 64` expression, unlike the read body's second, AUX-sourced memory width; the displacement form splits the instruction-immediate artifact — the immediate store takes `(s32)(IMM >> 32)`, the register store the whole artifact; the value source is the width-aware immediate rule or the full-64-bit register read; the AUX source shift is read only on the register form and taken modulo 64; the one-fact arm chain sends a stack-pointer destination through the stack helper and every other destination through the ordinary little-endian store; emitted as the C expression macros `KPROG_X86_STORE_WIDTH(FLAGS_WIDTH)`, `KPROG_X86_STORE_DISP(IS_STORE_IMM, IMM)`, `KPROG_X86_STORE_VALUE(IS_STORE_IMM, IMM, WIDTH, SRC_VALUE)`, `KPROG_X86_STORE_SRC_SHIFT(IS_STORE_IMM, AUX)`, `KPROG_X86_STORE_SHIFTED_VALUE(VALUE, SHIFT)`, and `KPROG_X86_STORE_ARM(BASE_IS_RSP)` with the `KPROG_X86_STORE_ARM_STACK`=0U/`ARM_MEMORY`=1U defines and the Lean `Code`/`resolveWidth`/`DispForm`/`ValueSource`/`ShiftSource`/`Arm` module; the spec JSON pins the whole metadata template byte-for-byte (selector wording `opcode_operand_then_register_identity_arm`, operation tag `x86StoreHandler`, and the five width, two displacement, two value, two shift, and two arm rows), and the generator re-checks every row order and resolution on every `--check`; the hand module `X86StoreHandler.lean` restates all five selectors independently and proves the refinements, the not-absent totality law, the stack-arm identity law, the two modulo-64 shift laws, the width-narrowed byte-update bridge shared with the movbe/push-pop/setcc-memory handlers, the full step composition, and the two-forms-differ examples, `build/mut_x86_store.py` (untracked) shakes all six files with 73 mutations, and the host `test_x86_store_host.c` verifies the width macro over the five codes and the arm macro over both selector values, then drives the whole handler against a hand-written body model over 48013 cases)
  The x86 MOV_LOAD handler-composition contract (the single body `X86_SIM_L_EXEC_MOV_LOAD` shared by `X86_OP_MOV_LOAD`, `X86_OP_MOV_LOAD_SCALAR`, and `X86_OP_MOVSX_LOAD`: the write width defaults to 64 bits when the opcode carries none; the memory width falls back to the resolved write width when the addressing mode carries none; the arm chain tests register identity first — a stack-pointer base always reads the stack at the resolved memory width, at any width and for any opcode — then the ABI pointer arm, gated on the plain `_MOV_LOAD` opcode, both resolved widths being 64 bits, and an ABI-tagged non-stack base; every other access takes the ordinary scalar load at the memory width, sign-extended for `_MOVSX_LOAD` and confined to the write width by the partial-register writeback; emitted as the C expression macros `KPROG_X86_MOV_LOAD_WRITE_WIDTH(FLAGS_WIDTH)`, `KPROG_X86_MOV_LOAD_MEM_WIDTH(FLAGS_WIDTH, AUX)`, and `KPROG_X86_MOV_LOAD_ARM(BASE_IS_RSP, IS_MOV_LOAD, MEM_WIDTH, WRITE_WIDTH, BASE_TAG)` with the `KPROG_X86_MOV_LOAD_ARM_STACK`=0U/`ARM_ABI_PTR`=1U/`ARM_ORDINARY`=2U defines and the Lean `Code`/`resolveWidth`/`Arm`/`arm` module; the spec JSON pins the whole metadata template byte-for-byte (selector wording `width_resolution_then_op_and_abi_tag_arm`, operation tag `x86MovLoadHandler`, the 25-code width-resolution table, and the 32-row arm table over the `is_rsp`/`is_mov_load`/`mem_is_64`/`write_is_64`/`base_is_abi` facts), and the generator re-checks both row orders and every row's resolution against `WIDTH_ORDER` and `ARM_ORDER` on every `--check`; the hand module `X86MovLoadHandler.lean` restates both width fallbacks and the arm predicate nesting independently and proves the two refinements, the not-absent totality law, the stack-arm register-identity law, the ABI conjunction law, the all-arms-reachable theorem, and the full step composition against the byte-ladder, sign-extend, writeback, and ABI-tag contracts, plus seven `native_decide` examples, `build/mut_x86_mov_load.py` (untracked) shakes all six files with 87 mutations, and the host `test_x86_mov_load_host.c` verifies both width macros over all 25 code pairs and the arm macro over all 32 selector combinations, then drives the whole handler against a hand-written body model over 86461 cases)
  The x86 memory read-dispatch contract (the value-source selector the shared read body applies before offset and load run: a stack-pointer base reads through the stack helper at any width and whatever its tag — register identity first, the x86 asymmetry against AArch64's tag-first dispatch; an ABI-tagged base reaches the 64-bit pointer load only at width 64; every other access takes the ordinary byte-ladder load; emitted as the C expression macro `KPROG_X86_MEM_READ_SRC(BASE_IS_RSP, BASE_TAG, WIDTH)` with the `KPROG_X86_MEM_SRC_STACK`=0U/`KPROG_X86_MEM_SRC_ABI_PTR_LOAD`=1U/`KPROG_X86_MEM_SRC_NORMAL_LOAD`=2U defines and the Lean `ValueSrc`/`valueSrc` 8-row table; the spec JSON pins selector wording, operation tag `x86MemReadDispatch`, and the eight `is_rsp`/`is_abi`/`w64` rows with their `src` defines, and the generator validates row order against the pinned `ORDER` tuple and each row's source against `SRC_DEFINES` on every `--check`; the hand module restates the dispatch as the C-shaped predicate nesting and proves the refinement plus `stack_overrides_tag`, `abi_requires_width64`, `no_tag_widening`, and `all_arms_reachable`; X86CmovHandler and X86MovbeHandler consume the generated `valueSrc` and `rw` the refinement, `build/mut_x86_mem_dispatch.py` (untracked) shakes all six files with 56 mutations, and the host `test_x86_mem_read_dispatch_host.c` drives the macro against an independent identity-before-tag oracle plus dispatch+offset+load composition over 3650 cases)
  The x86 little-endian memory-access contract (load assembles the access width's bytes --- byte `i` contributes bits `8i..8i+8` --- then narrows with the width mask; store masks the value then writes the width's bytes in little-endian order, leaving bytes at or above the width untouched; emitted as the C expression-statement macro `KPROG_X86_MEM_LOAD(ADDR, WIDTH)` and `do/while` macro `KPROG_X86_MEM_STORE(ADDR, WIDTH, VALUE)` and the Lean `byteCount`/`assemble`/`load`/`storeByte`/`store` module; the spec JSON pins the whole metadata template byte-for-byte (little endianness, `zero_is_64` width rule, load/store/byte_rule wordings, the four width rows); the hand module restates assemble/load/storeByte through the width bridge and proves the three refinements, the byte-count law, and two `native_decide` examples (0x12345678 w32 load, 0xaabb w16 store bytes); the host side (`test_mem_access_host.c`) compares both macros against an independent byte-level oracle over 5 fixed vectors across all four widths plus a 20000-iteration LCG sweep; own single-family harness (Step 0221; 49 single-anchor rows over six files --- x86_mem_access_spec.json, generate_x86_mem_access_spec.py, generated/x86_mem_access.h, KProgFormal/GeneratedX86MemAccess.lean, KProgFormal/X86MemAccess.lean, test_mem_access_host.c --- split gen 17 / lean_chain 16 / host 7 catch with 9 equivalences: the two unreachable generator error-message repaints, the generated Lean header-comment repaint, and the host mismatch/OK/FAILED banner, LCG-seed, and case-counter repaints))
  The x86 IMUL-flags contract (the multiply overflow rule: CF and OF are set together iff the width-narrowed signed product leaves the signed width range, i.e. `aAbs != 0 && bAbs > limit / aAbs` over `signedAbs` magnitudes with the limit the sign mask minus one for same-sign products and the full sign mask for mixed-sign products; ZF/SF preserved; emitted as the C macro `KPROG_X86_SET_IMUL_FLAGS(C_CF,C_OF,A_ABS,B_ABS,LIMIT)` with the overflow shared variable and the Lean `signedAbs`/`mixedSign`/`apply` module; the spec JSON pins the whole metadata template byte-for-byte (inputs, `zero_is_64` width rule, `signed_abs`/`limit`/`overflow` wordings, per-field overflow/preserve actions); the hand module restates the rule through the width bridge and proves the defined law, the apply refinement, and two `native_decide` boundary theorems (w16 overflow edge, w8 in-range minimum); the host side (`test_imul_flags_host.c`) compares the macro against an independent `__int128` signed-product oracle over 15 fixed vectors (including the `0x0164`/`0xfe3c` w16 spurious-conjunct discriminator) plus a 20000-iteration LCG sweep; own single-family harness (Step 0220; 48 single-anchor rows over six files --- x86_imul_flags_spec.json, generate_x86_imul_flags_spec.py, generated/x86_imul_flags.h, KProgFormal/GeneratedX86ImulFlags.lean, KProgFormal/X86ImulFlags.lean, test_imul_flags_host.c --- split gen 19 / lean_chain 11 / host 9 catch with 9 equivalences: the two unreachable generator error-message repaints, the generated Lean header-comment repaint, the hand doc-comment repaint, the two in-module-only hand theorem renames, and the host mismatch/OK banner and LCG-seed repaints))
  The x86 SBB-flags contract (the four subtract-with-borrow flag transitions shared by the simulator, Lean model, and memory-ALU handler: CF is the borrow chain `((A < B) || ((!!(BORROW)) && (A == B)))`, ZF is `(R == 0)`, SF is `((R & SIGN) != 0)`, OF is `((A ^ B) & ((A ^ R) & SIGN)) != 0`, emitted as the C `do/while` macro `KPROG_X86_SET_SBB_FLAGS(C_CF,C_ZF,C_SF,C_OF,A,B,R,SIGN,BORROW)` and the Lean `eval` over BitVec combinators (`lor`/`land` render as `||`/`&&`, `band` as a BitVec AND); the spec is a typed expression tree over the `a`/`b`/`r`/`sign` atoms plus the `borrow`/`zero` atoms with `load()` pinning the schema, operation tag, and flag order; the hand module `X86SbbFlags.lean` restates all four flags independently and proves the flags refinement, the width-narrowed step composition, the branch-PC composition, and two `native_decide` boundary theorems pinning signed overflow at the `-1 - 127 - 1` edge; the host side drives the memory-ALU handler's SBB arm against the 128-bit borrow oracle (22048 width/op/carry cases); own single-family harness (Step 0219; 58 single-anchor rows over six files --- x86_sbb_flags_spec.json, generate_x86_sbb_flags_spec.py, generated/x86_sbb_flags.h, KProgFormal/GeneratedX86SbbFlags.lean, KProgFormal/X86SbbFlags.lean, test_x86_mem_alu_handler_host.c --- split gen 19 / lean_chain 13 / host 9 catch with 17 equivalences: the eight unreachable generator error-message repaints, the generated Lean header-comment repaint, the bare hand theorem rename, both `native_decide` boundary-constant repaints (inside the pinned-OF plateau), and the host boundary-table and banner repaints))
  The x86 SBB-result contract (the subtract-with-borrow word value shared by the simulator, Lean model, and memory-ALU handler: the result expression is `(a - b) - borrow`, emitted as the C macro `KPROG_X86_SBB_RESULT(A,B,BORROW) ((A - B) - (!!(BORROW)))` and the Lean `result := ((a - b) - (if borrow then 1 else 0))` over BitVec subtraction; the spec is a typed expression tree over the `a`/`b` atoms and the `borrow` atom with `load()` pinning the schema, operation tag, and the single `result` expression name; the hand module `X86SbbResult.lean` restates the result independently and proves the outright refinement and the width-narrowed composition (`x86_narrow_refines`), and eight Lean modules (ALU-result, writeback, cmpop, inc/dec, mem-compare, SBB-flags, sub-result, unary) import the generated or hand module, so renames break the chain; the host side drives the memory-ALU handler's SUB and SBB arms against the 128-bit borrow oracle (22048 width/op/carry cases); own single-family harness (Step 0218; 40 single-anchor rows over six files --- x86_sbb_result_spec.json, generate_x86_sbb_result_spec.py, generated/x86_sbb_result.h, KProgFormal/GeneratedX86SbbResult.lean, KProgFormal/X86SbbResult.lean, test_x86_mem_alu_handler_host.c --- split gen 13 / lean_chain 6 / host 5 catch with 16 equivalences: the seven unreachable generator error-message repaints, the generated Lean header-comment repaint, the bare hand theorem rename, the `!!(BORROW)` -> `(BORROW)` value-preserving macro repaint, and the host boundary-table and banner repaints))
  The x86 SUB-flag contract (the four subtraction flag transitions shared by the simulator, Lean model, and memory-ALU handler composition: CF is unsigned borrow `A < B`, ZF is `A == B`, SF is `(R & SIGN) != 0`, OF is `((A ^ B) & ((A ^ R) & SIGN)) != 0`, emitted as the C `do/while` macro `KPROG_X86_SET_SUB_FLAGS(C_CF,C_ZF,C_SF,C_OF,A,B,R,SIGN)` and the Lean `eval` over BitVec combinators; the spec is a typed expression tree over the `a`/`b`/`r`/`sign` atoms with `load()` pinning the schema, operation tag, and flag order; the hand module `X86SubFlags.lean` restates all four flags independently and proves the flags refinement and the branch-PC composition, and seven Lean modules (compare, cmpop, sbb-result, sub-result, unary, inc/dec, writeback) import the hand module, so hand renames break the chain; the host side drives the memory-ALU handler's SUB arm against the 128-bit borrow oracle (22048 width/op/carry cases); own single-family harness (Step 0217; 53 single-anchor rows over six files --- x86_sub_flags_spec.json, generate_x86_sub_flags_spec.py, generated/x86_sub_flags.h, KProgFormal/GeneratedX86SubFlags.lean, KProgFormal/X86SubFlags.lean, test_x86_mem_alu_handler_host.c --- split gen 18 / lean_chain 11 / host 9 catch with 15 equivalences: the seven unreachable generator error-message repaints, the generated Lean header-comment repaint, the bare hand theorem rename, and the host boundary-table and banner repaints))
  The x86 ADD-flag contract (the four addition flag transitions shared by the simulator, Lean model, and memory-ALU handler composition: CF is unsigned carry-out `R < A`, ZF is `R == 0`, SF is `(R & SIGN) != 0`, OF is `((~(A ^ B)) & ((A ^ R) & SIGN)) != 0`, emitted as the C `do/while` macro `KPROG_X86_SET_ADD_FLAGS(C_CF,C_ZF,C_SF,C_OF,A,B,R,SIGN)` and the Lean `eval` over BitVec combinators; the spec is a typed expression tree over the `a`/`b`/`r`/`sign` atoms with `load()` pinning the schema, operation tag, and flag order; the hand module `X86AddFlags.lean` restates all four flags independently and proves the flags refinement and the branch-PC composition, and `X86AddResult`/`X86AluWriteback`/`X86IncDec` import the hand module, so hand renames break the chain; the host side drives the memory-ALU handler's ADD arm against the 128-bit oracle (22048 width/op/carry cases); own single-family harness (Step 0216; 57 single-anchor rows over six files --- x86_add_flags_spec.json, generate_x86_add_flags_spec.py, generated/x86_add_flags.h, KProgFormal/GeneratedX86AddFlags.lean, KProgFormal/X86AddFlags.lean, test_x86_mem_alu_handler_host.c --- split gen 21 / lean_chain 11 / host 9 catch with 16 equivalences: the eight unreachable generator error-message repaints, the generated Lean header-comment repaint, the bare hand theorem rename, the host boundary-table repaints as valid decimal literals, and the mismatch/OK/FAILED banner repaints))
  The x86 ALU decode contract (the parsed-mnemonic code table shared by the simulator, Lean model, and artifact encoder: sixteen operations --- add, sub, xor, or, and, shl, shr, sar, rol, imul, inc, not, sbb, dec, neg, adc --- with mnemonic = name, codes 0-15, and the handler split (sbb -> the borrow-sensitive handler, adc -> the carry-sensitive handler, everything else generic); the spec loader rejects any wrong column and any unknown key; the generator renders the Lean inductive plus `code`/`mnemonic`/`handlerForCode`, the C header's sixteen `X86_ALU_*` defines and two handler-selector macros, and the app-side `ALU_AUX` python mapping byte-for-byte; the hand module restates all three columns independently and proves the code/mnemonic/handler refinements plus the packed-AUX round-trip, and `X86AluResultSpec`/`GeneratedX86AluResult` import the generated module, so generated renames break the chain; the host side compares every generated constant with an independent mnemonic table, drives the real `x86_alu_result` dispatcher against arithmetic-identity recomputations over a 16x6x8x4 operand/width spread, and binds both selector macros plus their mutual exclusion to the dispatcher's own identity checks (3256 cases); own single-family harness (Step 0215; 48 single-anchor rows over seven files --- the six contract files plus `x86/micro-prog/generated_x86_alu_decode.py` --- split gen 15 / lean_chain 13 / host 13 catch with 7 equivalences: the four unreachable generator error-message repaints, the self-contained AUX-theorem rename, and the mismatch/OK banner repaints))
  The x86 ADC contract (the carry-propagating 64-bit add and the four flag expressions shared by the simulator, Lean model, and memory-ALU handler: the generated word macro `KPROG_X86_ADC_RESULT(A,B,CARRY)` is `(A + B) + (!!(CARRY))` and the flag macro `KPROG_X86_SET_ADC_FLAGS` assigns CF = unsigned carry-out `(R < A) || ((!!(CARRY)) && (R == A))`, ZF = `R == 0`, SF = `(R & SIGN) != 0`, OF = `((~(A ^ B)) & ((A ^ R) & SIGN)) != 0`; the spec is a typed expression tree over word/bool atoms with `validate()` rejecting any ill-typed node and `load()` pinning the four flag names in order; the generator renders the Lean module (BitVec combinators, carry-in as `if carry then 1 else 0`) and C header byte-for-byte; the hand module `X86Adc.lean` restates the result and flags independently and proves the result/flags refinements plus the width-narrowed step refinement and the branch-PC composition, and five Lean modules (`GeneratedX86AluResult`, `X86AddResult`, `X86AluWriteback`, `X86IncDec`, `X86UnaryWriteback`) import the generated module, so generated renames break the compile chain; the host side composes the ADC arm of `test_x86_mem_alu_handler_host.c` against a 128-bit oracle over 22048 width/op/carry cases; the ADD result arm reuses `KPROG_X86_ADC_RESULT` with carry 0; got its own single-family harness (Step 0214; 71 single-anchor rows over six files --- x86_adc_spec.json, generate_x86_adc_spec.py, generated/x86_adc.h, KProgFormal/GeneratedX86Adc.lean, KProgFormal/X86Adc.lean, test_x86_mem_alu_handler_host.c --- split gen 23 / lean_chain 13 / host 15 with 20 equivalences: the eleven unreachable generator error-message repaints, the value-preserving carry-normalization drop, the bare self-contained hand renames, and the mismatch/OK/FAILED banner repaints))
  The AArch64 vector-lane contract (the four vector memory-transfer opcodes `ARM64_OP_LOAD_D0` 0x28, `LOAD_Q0` 0x2a, `STORE_D0` 0x29, `STORE_Q0` 0x2b, which move the SIMD register's low 64-bit lane or both 64-bit lanes to or from memory: `LDR .D0` loads the low lane, `LDR .Q0` loads low then high, and the two `STR` forms store one or both lanes back out in the same order; `load()` compares the whole spec against the exact-match EXPECTED dict, re-checks each name/define/code/codeIndex/access/lanes column, exits 1 on a duplicate define, and pins `lane_stride` = `ARM64_WIDTH_64` and `high_lane_stride` = 8; the generator re-renders the generated Lean module and C header byte-for-byte, and the header re-pins the opcodes with static asserts, the access codes, per-opcode ACCESS/LANES/INDEX macros, and the four-way `KPROG_ARM64_DQ_MEM_INDEX` chain whose `else` makes the selector total off the opcode set; the contract does not restate the address offset or pre/post base adjustment, which live in the memory-offset and writeback macro contracts --- it fixes only which lanes each opcode transfers and in which order, each a full 64-bit scalar access; the hand module restates the ordered lane plan (`[0]` for `.D0`, `[0, 8]` for `.Q0`) independently of the generated index arithmetic and proves the transfer-list and lane-count refinements, the access dispatch, the lane plan, the stride, the distinct-lane property, the arm-index dispatch, and the low/high lane examples; no external Lean module imports either dq-mem module, so the Lean-chain detector rebuilds the generated olean before the hand check and hand-internal renames stay compile-green equivalences; the host oracle part 1 checks the lane-stride, access-code, lane-count, access-direction, and index constants plus the four `INDEX(ops)` selections and the total default arm, and part 2 drives the full composition of both bodies over 4*32*3*4*6 = 9216 grid cases (route recheck 62418 cases); the dq-move family got its own single-family harness (Step 0213; 83 single-anchor rows over seven files --- arm64_dq_mem_spec.json, generate_arm64_dq_mem_spec.py, generated/arm64_dq_mem.h, KProgFormal/GeneratedArm64DqMem.lean, KProgFormal/Arm64DqMemHandler.lean, test_arm64_dq_mem_host.c, test_arm64_dq_mem_route_host.c --- split gen 17 / lean_chain 19 / host 18 with 29 equivalences: the six unreachable generator error-message repaints, the bare self-contained hand renames, the literal-8 lane-stride argument, a contract-step comment repaint, and the eleven message/probe repaints))
  The AArch64 decode-table contract (the four mnemonic-to-code tables shared by the encoder, the C simulator constants, the Lean model, and the artifact-encoder Python module: ALU add/sub/and/bic/eor/orr to `ARM64_ALU_*` 0..5, SHIFT lsl/lsr/asr/ror to `ARM64_SHIFT_*` 0..3, MOD ""/lsl/lsr/asr/ror plus the six extend forms to `ARM64_MOD_*` 0..10 with the empty mnemonic mapped to the `none` constructor, BITFIELD ubfx/sbfx/ubfiz/bfxil/bfi to `ARM64_BITFIELD_*` 0..4; `load()` checks the key set, table set, lengths, canonical row keys, and each mnemonic/macro/code triplet against the exact-match EXPECTED dict; the generator re-renders three outputs byte-for-byte, the C header being the sole source of the `ARM64_*` codes; the hand module restates all four tables independently, proves each projection refinement and per-table code-distinctness with `native_decide`; fourteen Lean modules consume the generated decode types so generated and hand renames both break the compile; the host oracle part 1 checks every macro against an independent table with duplicate detection and part 2 round-trips every generated code through the real AUX codec (ALU/mod/shift field, bitfield code/lsb/width, MEM index/modifier/shift/flags, MOVK shift byte, 0/255 boundaries) against independent byte extractors) got its own single-family harness (Step 0212; 78 single-anchor rows over seven files --- the one-line spec, its generator, the generated C header, the generated Lean module, the hand module, the host oracle, and the encoder output `kprog/arm64/micro-prog/generated_arm64_decode.py`; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 15 / lean_chain 24 / host 22 with 17 equivalences: five unreachable generator error-message repaints, four bare hand-theorem renames, four table-call label repaints, the duplicate-detection message, the OK banner, and the probe-line label and loop-bound repaints).
  The AArch64 pair-move contract (what `ARM64_OP_LDP` 0x21 and `ARM64_OP_STP` 0x22 do before the address macros take over --- LDP loads two 64-bit slots into a register pair, low slot into DST and high slot one 64-bit stride higher into SRC, STP stores the pair back out in the same order; `load()` re-checks the exact-match dict per column, exits 1 on duplicate defines, pins the non-contiguous codes against `kprog/arm64/arm64_sim.h` at generation time, and the generated header re-pins them with static asserts plus the slot/high-slot strides, access codes, per-opcode ACCESS/INDEX macros, and the two-way `KPROG_ARM64_PAIR_MEM_INDEX` chain whose `else` makes the selector total off the opcode set; the contract does not restate the address offset or pre/post writeback, which live in the macro contracts with their own proved steps, it fixes only which two slots each opcode transfers and in which order; the hand module restates the ordered slot plan `[0, 8]` independently and proves refinement, count refinement, access dispatch, plan/count facts, the distinct-slot property, stride, arm-index dispatch, and the slot examples; the host oracle checks every constant and selector in part 1 including the total default arm, and part 2 drives the full composition of both bodies over 7x7x2x33x3x4x6 grid + fixed-seed randomized = 465696 cases, with `test_arm64_pair_mem_route_host.c` re-deriving the same plan through the simulator macro) got its own single-family harness (Step 0211; 90 single-anchor rows over six files --- the one-line spec, its generator, the generated C header, the generated Lean module, the hand module, and the host oracle; 3 detectors --- `--check` re-render, Lean chain, host recompiled per row --- split gen 10 / lean_chain 17 / host 32 with 31 equivalences: seven unreachable generator error-message repaints, a whitespace-only generated offset-arm edit, the slot-stride assert message, the eleven self-contained hand renames (nothing imports the hand module), and the eleven message/probe repaints --- nine part-one failure messages, OK/FAIL banners, randomized-sweep seed).
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
