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
  Remaining work also includes the load/store address and tag paths,
  the vector/`.D0`/`.Q0` paths, `MADD`/`MSUB`/`UMULH` flag consequences if any
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
  reduction/address-offset/FMOV/load-bytes contracts, and pointer-add/ABI-load
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
