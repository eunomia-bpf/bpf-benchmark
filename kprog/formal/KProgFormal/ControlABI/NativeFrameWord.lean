import KProgFormal.ControlABI.NativeWrapper
import X86.Program

/-! Saved-frame word effects over the mature x86 memory and unwind operations.
The statements quantify every machine state and replacement word. Physical
permissions, emitted wrapper correspondence and native/B address projection
retain their current platform interfaces. -/
namespace KProgFormal.ControlABI.NativeWrapper
open X86

/-- A qword store retains the adjacent qword, including wrapping addresses. -/
theorem next_word_preserved (memory : Mem) (address replacement : Val) :
    (memory.writeSize .q address replacement).readSize .q (address+8) =
      memory.readSize .q (address+8) := by
  have framed : AgreeOutside (Region address 8) memory
      (memory.writeSize .q address replacement) :=
    agreeOutside_writeSize (agreeOutside_rfl _ _) .q address replacement
      (by intro i hi; exact ⟨i, hi, rfl⟩)
  have separated : ∀ a, Region (address+8) 8 a → ¬ Region address 8 a := by
    rintro _ ⟨i, hi, rfl⟩ ⟨j, hj, equal⟩
    have hi64 : (BitVec.ofNat 64 i).toNat = i := by
      rw [BitVec.toNat_ofNat, Nat.mod_eq_of_lt (by omega)]
    have hj64 : (BitVec.ofNat 64 j).toNat = j := by
      rw [BitVec.toNat_ofNat, Nat.mod_eq_of_lt (by omega)]
    bv_omega
  exact (readSize_of_agreeOutside_disjoint framed separated .q (address+8)
    (by intro i hi; exact ⟨i, hi, rfl⟩)).symm

/-- LEAVE/RET restores the value actually stored in the frame word while
retaining the adjacent return address and the complete remaining state. -/
theorem frame_store_unwind (state : Cpu) (replacement returnAddress : Val)
    (live : state.ms = none)
    (savedReturn : state.readMem .q (state.regs.get .rbp+8) = returnAddress)
    (canonicalReturn : canonical returnAddress = true) :
    step {op := .ret 0, len := 1}
        (step {op := .leave, len := 1}
          (state.writeMem .q (state.regs.get .rbp) replacement)) =
      { ((state.writeMem .q (state.regs.get .rbp) replacement).setReg .q .rsp
          (state.regs.get .rbp+16)).setReg .q .rbp replacement with rip := returnAddress } := by
  let written := state.writeMem .q (state.regs.get .rbp) replacement
  have savedFrame : written.readMem .q (written.regs.get .rbp) = replacement := by
    simpa [written, Cpu.readMem, Cpu.writeMem] using
      word_store_load state.mem (state.regs.get .rbp) replacement
  have retainedReturn : written.readMem .q (written.regs.get .rbp+8) = returnAddress := by
    change (state.mem.writeSize .q (state.regs.get .rbp) replacement).readSize .q
      (state.regs.get .rbp+8) = returnAddress
    rw [next_word_preserved]
    exact savedReturn
  simpa [written, Cpu.writeMem] using
    leave_return written replacement returnAddress (by simpa [written] using live)
      savedFrame retainedReturn canonicalReturn

/-- Preserving the saved caller frame is exactly preserving its stored word
for this architectural unwind, with arbitrary surrounding machine state. -/
theorem saved_frame_preserved_iff (state : Cpu) (replacement returnAddress : Val)
    (live : state.ms = none)
    (savedReturn : state.readMem .q (state.regs.get .rbp+8) = returnAddress)
    (canonicalReturn : canonical returnAddress = true) :
    (step {op := .ret 0, len := 1}
      (step {op := .leave, len := 1}
        (state.writeMem .q (state.regs.get .rbp) replacement))).regs.get .rbp =
          state.readMem .q (state.regs.get .rbp) ↔
      replacement = state.readMem .q (state.regs.get .rbp) := by
  rw [frame_store_unwind state replacement returnAddress live savedReturn canonicalReturn]
  simp [Cpu.setReg, Value.writeView, Regs.get_set_same]

/-- The zero-depth entry relation identifies the RSP-addressed store with the
same saved-frame effect; source/JIT establishment of the relation stays explicit. -/
theorem entry_stack_store (state : Cpu) (replacement returnAddress : Val)
    (entry : state.regs.get .rsp = state.regs.get .rbp)
    (live : state.ms = none)
    (savedReturn : state.readMem .q (state.regs.get .rbp+8) = returnAddress)
    (canonicalReturn : canonical returnAddress = true) :
    (step {op := .ret 0, len := 1}
      (step {op := .leave, len := 1}
        (state.writeMem .q (state.regs.get .rsp) replacement))).regs.get .rbp = replacement := by
  rw [entry, frame_store_unwind state replacement returnAddress live savedReturn canonicalReturn]
  simp [Cpu.setReg, Value.writeView, Regs.get_set_same]

end KProgFormal.ControlABI.NativeWrapper
