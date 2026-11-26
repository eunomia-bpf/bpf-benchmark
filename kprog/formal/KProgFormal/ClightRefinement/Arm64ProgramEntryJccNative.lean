import KProgFormal.ClightRefinement.Arm64ProgramEntryJcc

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryJccNative

/-- Actual mature B.cond fields, including its real immediate and condition. -/
def fields (condition : BitVec 4) (offset : BitVec 19) : Cond_branch_imm_cls :=
  {imm19 := offset, o0 := 0, cond := condition}

/-- Both imported condition definitions compute the SAME predicate. -/
theorem condition (inst : Cond_branch_imm_cls) (s : Reference.AArch64.State) :
    BR.Cond_branch_imm_inst.condition_holds inst s.machine = ConditionHolds inst.cond s.machine := by
  rfl

/-- Retain the full mature native state, changing its actual selected PC. -/
def after (s : Reference.AArch64.State) (code : BitVec 4) (offset : BitVec 19) : Reference.AArch64.State :=
  Arm64Nop.atCursor
    (if ConditionHolds code s.machine then BR.Cond_branch_imm_inst.branch_taken_pc (fields code offset) (read_pc s.machine)
     else read_pc s.machine + 4#64) s

/-- Execute the actual imported conditional-branch body with both paths. -/
theorem execute (s : Reference.AArch64.State) (code : BitVec 4) (offset : BitVec 19) :
    BR.exec_cond_branch_imm (fields code offset) s.machine = (after s code offset).machine := by
  simp only [BR.exec_cond_branch_imm,condition,fields,after,Arm64Nop.atCursor]
  split <;> rfl

/-- The real decoder certificate and current fetch bind the checked step. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (code : BitVec 4) (offset : BitVec 19)
    (decoded : instruction.decoded = .BR (.Cond_branch_imm (fields code offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s code offset).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.BR (.Cond_branch_imm (fields code offset))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s code offset

/-- Complete imported histories remain; the actual branch adds no event/fault. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (code : BitVec 4) (offset : BitVec 19)
    (decoded : instruction.decoded = .BR (.Cond_branch_imm (fields code offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s code offset,[],none⟩ := by
  have history : read_memory_accesses (after s code offset).machine = read_memory_accesses s.machine := by
    simp [after,Arm64Nop.atCursor,write_pc,read_memory_accesses,w,write_base_pc]
  have error : read_err (after s code offset).machine = .None := by
    simpa [after,Arm64Nop.atCursor,write_pc,read_err,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s instruction code offset decoded noError fetched,
    history,List.drop_length,error,noError]
  rfl

/-- The native PC is the imported taken target or the actual PC+4 successor. -/
theorem pc (s : Reference.AArch64.State) (code : BitVec 4) (offset : BitVec 19) :
    read_pc (after s code offset).machine =
      if ConditionHolds code s.machine then BR.Cond_branch_imm_inst.branch_taken_pc (fields code offset) (read_pc s.machine)
      else read_pc s.machine + 4#64 := by
  simp [after,Arm64Nop.atCursor,write_pc,read_pc,r_of_w_same]

/-- Every actual native field other than PC keeps its prior observation. -/
theorem field (s : Reference.AArch64.State) (code : BitVec 4) (offset : BitVec 19)
    (name : StateField) (other : name ≠ .PC) :
    r name (after s code offset).machine = r name s.machine := by
  simp only [after,Arm64Nop.atCursor,write_pc,r_of_w_different other]

/-- Memory, code, permission profile, histories and environment inputs survive. -/
theorem resources (s : Reference.AArch64.State) (code : BitVec 4) (offset : BitVec 19) :
    let changed := after s code offset
    changed.machine.mem = s.machine.mem ∧ changed.machine.program = s.machine.program ∧
    changed.machine.memoryProfile = s.machine.memoryProfile ∧ changed.machine.memoryAccesses = s.machine.memoryAccesses ∧
    changed.machine.atomicAccesses = s.machine.atomicAccesses ∧ changed.machine.exclusive = s.machine.exclusive ∧
    changed.machine.threadPointerInputs = s.machine.threadPointerInputs ∧ changed.extraFlags = s.extraFlags := by
  simp [after,Arm64Nop.atCursor,write_pc,w,write_base_pc]

/-- Bind the real C mark%15 condition result to that imported branch predicate. -/
theorem source_truth (s : Reference.AArch64.State) (mark : BitVec 32) (offset : BitVec 19) :
    Arm64ProgramEntryJcc.truth mark s =
      if BR.Cond_branch_imm_inst.condition_holds
        (fields (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) offset) s.machine then 1#32 else 0#32 := by
  rw [condition]
  rfl

end KProgFormal.ClightRefinement.Arm64ProgramEntryJccNative
