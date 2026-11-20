import KProgFormal.ClightRefinement.Arm64ProgramEntryMovNative
import KProgFormal.ClightRefinement.Arm64MovImmediateWide

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovPairNative

/-- These are native state-update identities, with the imported machine's
PC and register fields kept distinct. No instruction is synthesized. -/
theorem update_cursor (s : Reference.AArch64.State) (pc : BitVec 64)
    (i : Fin 31) (value : BitVec 64) (narrow : Bool) :
    Arm64RegisterWrite.nativeUpdate (Arm64Nop.atCursor pc s) i value narrow =
      Arm64Nop.atCursor pc (Arm64RegisterWrite.nativeUpdate s i value narrow) := by
  simp [Arm64RegisterWrite.nativeUpdate, Arm64Nop.atCursor, write_pc, w,
    write_base_pc, write_base_gpr]

theorem cursor_cursor (s : Reference.AArch64.State) (pc oldPc : BitVec 64) :
    Arm64Nop.atCursor pc (Arm64Nop.atCursor oldPc s) = Arm64Nop.atCursor pc s := by
  simp [Arm64Nop.atCursor, write_pc, w, write_base_pc]

/-- One actual MOVZ/MOVN-normalized source operand followed by MOVK. Each
fetched instruction has its own mature decoder certificate. The first source
literal binds to the live emitter's full normalized operand, without a numeric
mark bound or collapsing two native instructions into one source call. -/
theorem steps (s : Reference.AArch64.State)
    (first keep : Reference.AArch64.Instruction) (mark priority : BitVec 32)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false), [], none⟩ ∧
    Reference.AArch64.step (Reference.AArch64.step s).state =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 8#64)
        (Arm64RegisterWrite.nativeUpdate
          (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)
          1 (Arm64MovKeep.mergeWord (mark.setWidth 64) (priority.setWidth 64) 1) false), [], none⟩ := by
  have firstStep := Arm64MovImmediate.Wide.reference_step s first 1 imm column false negate
    (by intro impossible; cases impossible) firstDecoded noError firstFetched
  rw [← literal] at firstStep
  let middle := Arm64Nop.atCursor (read_pc s.machine + 4#64)
    (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)
  have middlePc : read_pc middle.machine = read_pc s.machine + 4#64 := by
    simp [middle, Arm64Nop.atCursor, read_pc, write_pc, r_of_w_same]
  have middleWord : Reference.AArch64.gpr middle 1 = mark.setWidth 64 := by
    simp [middle, Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written,
      Reference.AArch64.gpr, read_gpr, write_pc, r_of_w_different, r_of_w_same]
  have middleError : read_err middle.machine = .None := by
    simpa [middle, Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different] using noError
  have middleFetch : fetch_inst (read_pc middle.machine) middle.machine = some keep.encoding := by
    rw [middlePc]
    simpa [middle, fetch_inst, Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate,
      write_pc, w, write_base_pc, write_base_gpr] using keepFetched
  have secondStep := Arm64MovKeep.Native.reference_word_step middle keep 1 (priority.setWidth 64) 1 false
    (by decide) keepDecoded middleError middleFetch
  have sum : (read_pc s.machine + 4#64) + 4#64 = read_pc s.machine + 8#64 := by
    rw [BitVec.add_assoc]; rfl
  refine ⟨firstStep, ?_⟩
  rw [firstStep]
  rw [middlePc, middleWord, sum] at secondStep
  simpa only [middle, update_cursor, cursor_cursor] using secondStep

end KProgFormal.ClightRefinement.Arm64MovPairNative
