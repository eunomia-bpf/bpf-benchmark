import KProgFormal.ClightRefinement.Arm64SelectReads
import KProgFormal.ClightRefinement.Arm64PointerWriteLinked

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select.Native

/-- Bind the external decoder fields of plain CSEL64, without replacing its semantics. -/
def fields (dst lhs rhs : Fin 31) (condition : BitVec 4) : Conditional_select_cls :=
  { sf := 1, op := 0, S := 0, Rm := BitVec.ofNat 5 rhs.val, cond := condition,
    op2 := 0, Rn := BitVec.ofNat 5 lhs.val, Rd := BitVec.ofNat 5 dst.val }

def selected (s : Reference.AArch64.State) (lhs rhs : Fin 31) (condition : BitVec 4) : BitVec 64 :=
  if ConditionHolds condition s.machine then Reference.AArch64.gpr s lhs else Reference.AArch64.gpr s rhs

private theorem ordinary (i : Fin 31) : BitVec.ofNat 5 i.val ≠ 31#5 := by
  intro equal
  have bits := congrArg BitVec.toNat equal
  change i.val % 32 = 31 at bits
  have bound := i.isLt
  omega

/-- LNSym chooses the source using its own condition semantics and retains every
other machine component through the actual ordinary-register and PC writes. -/
theorem execute (s : Reference.AArch64.State) (dst lhs rhs : Fin 31) (condition : BitVec 4) :
    DPR.exec_conditional_select (fields dst lhs rhs condition) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s dst (selected s lhs rhs condition) false)).machine := by
  by_cases taken : ConditionHolds condition s.machine
  all_goals
    simp +decide [fields, selected, DPR.exec_conditional_select, taken, ordinary,
      read_gpr_zr, read_gpr, write_gpr_zr, write_gpr, Reference.AArch64.gpr,
      Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written,
      write_pc, w, write_base_pc, write_base_gpr]

/-- Only the original fetched word, its mature decoder certificate and incoming
error state admit this native step. No local opcode classifier is introduced. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (dst lhs rhs : Fin 31) (condition : BitVec 4)
    (decoded : instruction.decoded = .DPR (.Conditional_select (fields dst lhs rhs condition)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s dst (selected s lhs rhs condition) false)).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPR (.Conditional_select (fields dst lhs rhs condition))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using execute s dst lhs rhs condition

/-- The full reference step includes the unchanged history, empty event delta,
PC advancement and no fault, not just the selected register value. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (dst lhs rhs : Fin 31) (condition : BitVec 4)
    (decoded : instruction.decoded = .DPR (.Conditional_select (fields dst lhs rhs condition)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s dst (selected s lhs rhs condition) false), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s dst (selected s lhs rhs condition) false)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses, write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s dst (selected s lhs rhs condition) false)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different] using noError
  simp only [Reference.AArch64.step, native_step s instruction dst lhs rhs condition decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

/-- Identify the same selected source's physical word with the existing raw/tag
representation before applying the fetched CSEL step. Writer execution remains
an independent source obligation; this law does not assume its post-memory. -/
theorem pointer_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (dst lhs rhs : Fin 31) (condition : BitVec 4)
    (origins : Reference.Provenance.AArch64.Origins) (raw : BitVec 64) (tag : BitVec 8)
    (selectedWord : Reference.AArch64.gpr s
      (if ConditionHolds condition s.machine then lhs else rhs) =
        Reference.Provenance.AArch64.materialize origins raw tag)
    (decoded : instruction.decoded = .DPR (.Conditional_select (fields dst lhs rhs condition)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64PointerWrite.nativeUpdate origins s dst raw tag), [], none⟩ := by
  have chosen : selected s lhs rhs condition = Reference.Provenance.AArch64.materialize origins raw tag := by
    by_cases taken : ConditionHolds condition s.machine
    all_goals simpa only [selected,taken,ite_true,ite_false,Bool.false_eq_true] using selectedWord
  rw [reference_step s instruction dst lhs rhs condition decoded noError fetched,chosen]
  rfl

end KProgFormal.ClightRefinement.Arm64Select.Native
