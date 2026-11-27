import KProgFormal.ClightRefinement.Arm64KernelMemcpyCode

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPrologue
open Arm64KernelMemcpyCode (Code instruction)

def sourceEndFields : Add_sub_shifted_reg_cls :=
  {sf := 1,op := 0,S := 0,shift := 0,Rm := 2,imm6 := 0,Rn := 1,Rd := 4}
def destinationEndFields : Add_sub_shifted_reg_cls :=
  {sf := 1,op := 0,S := 0,shift := 0,Rm := 2,imm6 := 0,Rn := 0,Rd := 5}

theorem decoded :
    (instruction 1).decoded = .DPR (.Add_sub_shifted_reg sourceEndFields) ∧
    (instruction 2).decoded = .DPR (.Add_sub_shifted_reg destinationEndFields) := by decide +kernel

/-- Both actual states execute the imported instruction bodies themselves. -/
def first (s : Reference.AArch64.State) : Reference.AArch64.State :=
  {s with machine := DPR.exec_add_sub_shifted_reg sourceEndFields s.machine}
def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  {s with machine := DPR.exec_add_sub_shifted_reg destinationEndFields (first s).machine}

private theorem shift_zero {n : Nat} (x : BitVec n) : shift_reg x .LSL (0#6) = x := by
  change x <<< (0 : Nat) = x
  exact BitVec.shiftLeft_zero x

private theorem first_shape (s : Reference.AArch64.State) :
    (first s).machine = write_gpr 64 (4#5) (Reference.AArch64.gpr s 1+Reference.AArch64.gpr s 2)
      (write_pc (read_pc s.machine+4#64) s.machine) := by
  simp +decide [first,sourceEndFields,DPR.exec_add_sub_shifted_reg,fst_AddWithCarry_eq_add,
    read_gpr_zr,read_gpr,write_gpr_zr,shift_zero,decode_shift,Reference.AArch64.gpr]

private theorem after_shape (s : Reference.AArch64.State) :
    (after s).machine = write_gpr 64 (5#5) (Reference.AArch64.gpr s 0+Reference.AArch64.gpr s 2)
      (write_pc (read_pc s.machine+8#64) (first s).machine) := by
  simp +decide [after,destinationEndFields,DPR.exec_add_sub_shifted_reg,fst_AddWithCarry_eq_add,
    read_gpr_zr,read_gpr,write_gpr_zr,shift_zero,decode_shift,Reference.AArch64.gpr,
    first_shape,read_pc,write_gpr,write_pc,r_of_w_different,r_of_w_same,BitVec.add_assoc]

/-- The real two-word prologue starts AFTER the actual BTI landing pad.
Code comes from the sole-kernel artifact; no native byte-loop code is invented.
Arbitrary count and wrapped physical addresses retain their actual sum. -/
theorem execute (s : Reference.AArch64.State) (origin : BitVec 64)
    (code : Code origin s.machine) (pc : read_pc s.machine = origin+4#64)
    (noError : read_err s.machine = .None) :
    Reference.AArch64.step s = ⟨first s,[],none⟩ ∧
    Reference.AArch64.step (first s) = ⟨after s,[],none⟩ ∧
    Reference.AArch64.gpr (after s) 4 = Reference.AArch64.gpr s 1+Reference.AArch64.gpr s 2 ∧
    Reference.AArch64.gpr (after s) 5 = Reference.AArch64.gpr s 0+Reference.AArch64.gpr s 2 ∧
    read_pc (after s).machine = origin+12#64 ∧ read_err (after s).machine = .None ∧
    (∀ field : StateField, field ≠ .PC → field ≠ .GPR (4#5) → field ≠ .GPR (5#5) →
      r field (after s).machine = r field s.machine) ∧
    (after s).machine.mem = s.machine.mem ∧
    (after s).machine.memoryProfile = s.machine.memoryProfile ∧
    read_memory_accesses (after s).machine = read_memory_accesses s.machine ∧
    (after s).machine.program = s.machine.program ∧
    (after s).machine.exclusive = s.machine.exclusive ∧
    (after s).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s).machine.threadPointerInputs = s.machine.threadPointerInputs ∧
    (after s).extraFlags = s.extraFlags := by
  have basePC : r .PC s.machine = origin+4#64 := pc
  have firstFetch : fetch_inst (read_pc s.machine) s.machine = some (instruction 1).encoding := by
    rw [pc]
    exact code 1
  have firstStep : stepi_checked s.machine = (first s).machine := by
    have actual := (instruction 1).valid.trans (congrArg some decoded.1)
    simp only [stepi_checked,stepi,noError,firstFetch,actual,exec_inst]
    rfl
  have firstError : read_err (first s).machine = .None := by
    simpa [first_shape,read_err,write_gpr,write_pc,r_of_w_different] using noError
  have firstHistory : read_memory_accesses (first s).machine = read_memory_accesses s.machine := by
    simp [first_shape,read_memory_accesses,write_gpr,write_pc,w,write_base_gpr,write_base_pc]
  have secondCode : Code origin (first s).machine := Arm64KernelMemcpyCode.transport code (by
    simp [first_shape,write_gpr,write_pc,w,write_base_gpr,write_base_pc])
  have secondFetch : fetch_inst (read_pc (first s).machine) (first s).machine = some (instruction 2).encoding := by
    have cursor : read_pc (first s).machine = origin+8#64 := by
      simp [first_shape,read_pc,write_gpr,write_pc,r_of_w_different,r_of_w_same,basePC,BitVec.add_assoc,show (4#64)+(4#64) = 8#64 by decide,show (4#64)+(8#64) = 12#64 by decide]
    rw [cursor]
    exact secondCode 2
  have secondStep : stepi_checked (first s).machine = (after s).machine := by
    have actual := (instruction 2).valid.trans (congrArg some decoded.2)
    simp only [stepi_checked,stepi,firstError,secondFetch,actual,exec_inst]
    rfl
  have finalError : read_err (after s).machine = .None := by
    simpa [after_shape,first_shape,read_err,write_gpr,write_pc,r_of_w_different] using noError
  have finalHistory : read_memory_accesses (after s).machine = read_memory_accesses (first s).machine := by
    simp [after_shape,read_memory_accesses,write_gpr,write_pc,w,write_base_gpr,write_base_pc]
  refine ⟨?_,?_,?_,?_,?_,finalError,?_,?_,?_,finalHistory.trans firstHistory,?_,?_,?_,?_,rfl⟩
  · simp only [Reference.AArch64.step,firstStep,firstHistory,List.drop_length,firstError,noError]
    rfl
  · simp only [Reference.AArch64.step,secondStep,finalHistory,List.drop_length,finalError,firstError]
    rfl
  · change r (.GPR (4#5)) (after s).machine = r (.GPR (1#5)) s.machine+r (.GPR (2#5)) s.machine
    simp [after_shape,first_shape,Reference.AArch64.gpr,write_gpr,write_pc,r_of_w_same,r_of_w_different]
  · change r (.GPR (5#5)) (after s).machine = r (.GPR (0#5)) s.machine+r (.GPR (2#5)) s.machine
    simp [after_shape,Reference.AArch64.gpr,write_gpr,r_of_w_same]
  · simp [after_shape,first_shape,read_pc,write_gpr,write_pc,r_of_w_different,r_of_w_same,basePC,BitVec.add_assoc,show (4#64)+(4#64) = 8#64 by decide,show (4#64)+(8#64) = 12#64 by decide]
  · intro field otherPC otherFour otherFive
    simp only [after_shape,first_shape,write_gpr,write_pc,r_of_w_different otherPC,
      r_of_w_different otherFour,r_of_w_different otherFive]
  all_goals simp [after_shape,first_shape,write_gpr,write_pc,w,write_base_gpr,write_base_pc]

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPrologue
