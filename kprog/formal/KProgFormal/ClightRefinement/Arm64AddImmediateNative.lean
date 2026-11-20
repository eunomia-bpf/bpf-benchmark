import KProgFormal.ClightRefinement.Arm64AddImmediate

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.Native

/-- Mature decoded ADD-immediate fields with SP source, no flag write and an
ordinary destination. Fetch and the external decoder certificate bind the word. -/
def fields (i : Fin 31) (imm : BitVec 12) (shifted : Bool) : Add_sub_imm_cls :=
  { sf := 1, op := 0, S := 0, sh := if shifted then 1 else 0,
    imm12 := imm, Rn := 31, Rd := BitVec.ofNat 5 i.val }

/-- Immediate-operand metadata from the decoded instruction; no ISA result. -/
def operand (imm : BitVec 12) (shifted : Bool) : BitVec 64 :=
  if shifted then imm.setWidth 64 <<< 12 else imm.setWidth 64

private theorem ordinary (i : Fin 31) : BitVec.ofNat 5 i.val ≠ 31#5 := by
  intro equal
  have bits := congrArg BitVec.toNat equal
  change i.val % 32 = 31 at bits
  have bound := i.isLt
  omega

private theorem extend_imm (imm : BitVec 12) : (0#52 ++ imm) = imm.setWidth 64 := by
  symm
  exact BitVec.setWidth_eq_append (by decide)

/-- Evaluate LNSym's actual ADD body, reusing its carry-zero addition theorem. -/
theorem execute (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 12) (shifted : Bool) :
    DPI.exec_add_sub_imm (fields i imm shifted) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i
          (Reference.AArch64.sp s + operand imm shifted) false)).machine := by
  cases shifted <;>
    simp +decide [fields, operand, DPI.exec_add_sub_imm, fst_AddWithCarry_eq_add, extend_imm,
      read_gpr, write_gpr_zr, write_gpr, ordinary i, Arm64Nop.atCursor,
      Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written, Reference.AArch64.sp,
      write_pc, w, write_base_pc, write_base_gpr]

/-- Execute the fetched word through LNSym's checked step. Its own decoder
certificate is required; the proof supplies no local instruction classifier. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 12) (shifted : Bool)
    (decoded : instruction.decoded = .DPI (.Add_sub_imm (fields i imm shifted)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (Reference.AArch64.sp s + operand imm shifted) false)).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPI (.Add_sub_imm (fields i imm shifted))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using execute s i imm shifted

/-- Preserve existing native histories and all frame fields while reporting
exactly the new empty event/fault delta and actual PC+4 update. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 12) (shifted : Bool)
    (decoded : instruction.decoded = .DPI (.Add_sub_imm (fields i imm shifted)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (Reference.AArch64.sp s + operand imm shifted) false), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (Reference.AArch64.sp s + operand imm shifted) false)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses, write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (Reference.AArch64.sp s + operand imm shifted) false)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different] using noError
  simp only [Reference.AArch64.step, native_step s instruction i imm shifted decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl


/-- Join the relative STACK payload update to the actual physical SP operand.
This is wrapped representation algebra, independent of instruction semantics. -/
theorem pointer_update (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 12) (shifted : Bool)
    (origins : Reference.Provenance.AArch64.Origins) (offset : BitVec 64)
    (sp : Reference.AArch64.sp s = offset + origins.stack) :
    Arm64RegisterWrite.nativeUpdate s i (Reference.AArch64.sp s + operand imm shifted) false =
      Arm64PointerWrite.nativeUpdate origins s i (offset + operand imm shifted) (4#8) := by
  unfold Arm64PointerWrite.nativeUpdate
  congr 1
  rw [sp]
  simp +decide only [Reference.Provenance.AArch64.materialize, eq_self, ite_true]
  rw [BitVec.add_assoc, BitVec.add_comm origins.stack (operand imm shifted), ← BitVec.add_assoc]

end KProgFormal.ClightRefinement.Arm64AddImmediate.Native
