import KProgFormal.ClightRefinement.Arm64KernelMemcpyPrologue

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpySmallGates
open Arm64KernelMemcpyCode (instruction)

def amount (i : Fin 3) : BitVec 12 := #[128#12,32#12,16#12][i.val]'(by simpa using i.isLt)
def compareFields (i : Fin 3) : Add_sub_imm_cls :=
  {sf := 1,op := 1,S := 1,sh := 0,imm12 := amount i,Rn := 2,Rd := 31}
def branchFields (i : Fin 3) : Cond_branch_imm_cls :=
  {imm19 := #[60#19,30#19,6#19][i.val]'(by simpa using i.isLt),o0 := 0,
   cond := #[8#4,8#4,3#4][i.val]'(by simpa using i.isLt)}
def compareIndex (i : Fin 3) : Fin 14 := ⟨3+2*i.val,by omega⟩
def branchIndex (i : Fin 3) : Fin 14 := ⟨4+2*i.val,by omega⟩

theorem decoded : ∀ i : Fin 3,
    (instruction (compareIndex i)).decoded = .DPI (.Add_sub_imm (compareFields i)) ∧
    (instruction (branchIndex i)).decoded = .BR (.Cond_branch_imm (branchFields i)) := by decide +kernel

def first (s : Reference.AArch64.State) (i : Fin 3) : Reference.AArch64.State :=
  {s with machine := DPI.exec_add_sub_imm (compareFields i) s.machine}
def after (s : Reference.AArch64.State) (i : Fin 3) : Reference.AArch64.State :=
  {s with machine := BR.exec_cond_branch_imm (branchFields i) (first s i).machine}
def flags (i : Fin 3) : PState := (AddWithCarry (16#64) (~~~(0#52 ++ amount i)) (1#1)).snd

private theorem first_shape (s : Reference.AArch64.State) (i : Fin 3)
    (count : Reference.AArch64.gpr s 2 = 16#64) :
    (first s i).machine = write_pstate (flags i) (write_pc (read_pc s.machine+4#64) s.machine) := by
  have actual : r (.GPR (2#5)) s.machine = 16#64 := count
  simp +decide [first,compareFields,DPI.exec_add_sub_imm,read_gpr,actual,flags,write_gpr_zr]

private theorem not_taken (s : ArmState) (i : Fin 3) :
    BR.Cond_branch_imm_inst.condition_holds (branchFields i) (write_pstate (flags i) s) = false := by
  have cases : ∀ i : Fin 3, i = 0 ∨ i = 1 ∨ i = 2 := by decide +kernel
  rcases cases i with rfl | rfl | rfl <;>
    simp +decide [BR.Cond_branch_imm_inst.condition_holds,branchFields,flags,amount,
      read_flag,write_pstate,r_of_w_same,r_of_w_different]

private theorem after_shape (s : Reference.AArch64.State) (i : Fin 3)
    (count : Reference.AArch64.gpr s 2 = 16#64) :
    (after s i).machine = write_pc (read_pc s.machine+8#64) (first s i).machine := by
  have branchFalse : BR.Cond_branch_imm_inst.condition_holds (branchFields i) (first s i).machine = false := by
    rw [first_shape s i count]
    exact not_taken _ i
  simp only [after,BR.exec_cond_branch_imm,branchFalse,ite_false]
  congr 1
  simp [first_shape s i count,read_pc,write_pstate,write_pc,r_of_w_different,r_of_w_same,BitVec.add_assoc]

/-- All three actual count16 gates execute their real CMP and branch.
The 128/32 B.HI and16 B.LO each fall through, with their genuine flags,
complete register/memory/environment frame and actual empty event delta. -/
theorem execute (s : Reference.AArch64.State) (i : Fin 3)
    (count : Reference.AArch64.gpr s 2 = 16#64) (noError : read_err s.machine = .None)
    (fetchedCompare : fetch_inst (read_pc s.machine) s.machine = some (instruction (compareIndex i)).encoding)
    (fetchedBranch : fetch_inst (read_pc s.machine+4#64) s.machine = some (instruction (branchIndex i)).encoding) :
    Reference.AArch64.step s = ⟨first s i,[],none⟩ ∧
    Reference.AArch64.step (first s i) = ⟨after s i,[],none⟩ ∧
    read_pc (after s i).machine = read_pc s.machine+8#64 ∧
    read_err (after s i).machine = .None ∧
    (∀ field : StateField, field ≠ .PC → (∀ flag, field ≠ .FLAG flag) → r field (after s i).machine = r field s.machine) ∧
    read_pstate (after s i).machine = flags i ∧
    (after s i).machine.mem = s.machine.mem ∧
    (after s i).machine.memoryProfile = s.machine.memoryProfile ∧
    read_memory_accesses (after s i).machine = read_memory_accesses s.machine ∧
    (after s i).machine.program = s.machine.program ∧
    (after s i).machine.exclusive = s.machine.exclusive ∧
    (after s i).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s i).machine.threadPointerInputs = s.machine.threadPointerInputs ∧
    (after s i).extraFlags = s.extraFlags := by
  have firstStep : stepi_checked s.machine = (first s i).machine := by
    have actual := (instruction (compareIndex i)).valid.trans (congrArg some (decoded i).1)
    simp only [stepi_checked,stepi,noError,fetchedCompare,actual,exec_inst]
    rfl
  have firstError : read_err (first s i).machine = .None := by
    simpa [first_shape s i count,read_err,write_pstate,write_pc,r_of_w_different] using noError
  have firstHistory : read_memory_accesses (first s i).machine = read_memory_accesses s.machine := by
    simp [first_shape s i count,read_memory_accesses,write_pstate,write_pc,w,write_base_flag,write_base_pc]
  have firstPC : read_pc (first s i).machine = read_pc s.machine+4#64 := by
    simp [first_shape s i count,read_pc,write_pstate,write_pc,r_of_w_different,r_of_w_same]
  have firstProgram : (first s i).machine.program = s.machine.program := by
    simp [first_shape s i count,write_pstate,write_pc,w,write_base_flag,write_base_pc]
  have branchCode : fetch_inst (read_pc (first s i).machine) (first s i).machine = some (instruction (branchIndex i)).encoding := by
    rw [firstPC]
    simpa only [fetch_inst,firstProgram] using fetchedBranch
  have secondStep : stepi_checked (first s i).machine = (after s i).machine := by
    have actual := (instruction (branchIndex i)).valid.trans (congrArg some (decoded i).2)
    simp only [stepi_checked,stepi,firstError,branchCode,actual,exec_inst]
    rfl
  have finalError : read_err (after s i).machine = .None := by
    simpa [after_shape s i count,read_err,write_pc,r_of_w_different] using firstError
  have finalHistory : read_memory_accesses (after s i).machine = read_memory_accesses (first s i).machine := by
    simp [after_shape s i count,read_memory_accesses,write_pc,w,write_base_pc]
  refine ⟨?_,?_,?_,finalError,?_,?_,?_,?_,finalHistory.trans firstHistory,?_,?_,?_,?_,rfl⟩
  · simp only [Reference.AArch64.step,firstStep,firstHistory,List.drop_length,firstError,noError]
    rfl
  · simp only [Reference.AArch64.step,secondStep,finalHistory,List.drop_length,finalError,firstError]
    rfl
  · simp [after_shape s i count,read_pc,write_pc,r_of_w_same]
  · intro field notPC notFlag
    simp only [after_shape s i count,first_shape s i count,write_pc,write_pstate,
      r_of_w_different notPC,r_of_w_different (notFlag .N),r_of_w_different (notFlag .Z),
      r_of_w_different (notFlag .C),r_of_w_different (notFlag .V)]
  all_goals simp [after_shape s i count,first_shape s i count,read_pstate,read_flag,
    write_pstate,write_pc,w,write_base_flag,write_base_pc,r_of_w_different,r_of_w_same]

end KProgFormal.ClightRefinement.Arm64KernelMemcpySmallGates
