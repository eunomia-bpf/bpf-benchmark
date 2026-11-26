import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkNative
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- Real BL fields retain the genuine signed immediate from native code. -/
def fields (offset : BitVec 26) : Uncond_branch_imm_cls := {op := 1,imm26 := offset}

def after (s : Reference.AArch64.State) (offset : BitVec 26) : Reference.AArch64.State :=
  let target := BR.Uncond_branch_imm_inst.branch_taken_pc (fields offset) (read_pc s.machine)
  {s with machine := write_pc target (write_gpr 64 (30#5) (read_pc s.machine + 4#64) s.machine)}

/-- Execute the mature BL body and its original PC-derived link writer. -/
theorem execute (s : Reference.AArch64.State) (offset : BitVec 26) :
    BR.exec_uncond_branch_imm (fields offset) s.machine = (after s offset).machine := by
  simp [BR.exec_uncond_branch_imm,fields,after]

theorem native_step (s : Reference.AArch64.State) (offset : BitVec 26)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .BR (.Uncond_branch_imm (fields offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s offset).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.BR (.Uncond_branch_imm (fields offset))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s offset

theorem reference_step (s : Reference.AArch64.State) (offset : BitVec 26)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .BR (.Uncond_branch_imm (fields offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s offset,[],none⟩ := by
  have history : read_memory_accesses (after s offset).machine = read_memory_accesses s.machine := by
    simp [after,read_memory_accesses,write_pc,write_gpr,w,write_base_pc,write_base_gpr]
  have error : read_err (after s offset).machine = .None := by
    simpa [after,read_err,write_pc,write_gpr,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s offset instruction decoded noError fetched,
    history,List.drop_length,error,noError]
  rfl

theorem pc (s : Reference.AArch64.State) (offset : BitVec 26) :
    read_pc (after s offset).machine =
      BR.Uncond_branch_imm_inst.branch_taken_pc (fields offset) (read_pc s.machine) := by
  simp [after,write_pc,read_pc,r_of_w_same]

theorem link (s : Reference.AArch64.State) (offset : BitVec 26) :
    Reference.AArch64.gpr (after s offset) 30 = read_pc s.machine + 4#64 := by
  change r (.GPR (30#5)) (after s offset).machine = read_pc s.machine + 4#64
  simp [after,write_pc,write_gpr,r_of_w_same,r_of_w_different]

theorem field (s : Reference.AArch64.State) (offset : BitVec 26) (name : StateField)
    (otherPC : name ≠ .PC) (otherLR : name ≠ .GPR (30#5)) :
    r name (after s offset).machine = r name s.machine := by
  simp [after,write_pc,write_gpr,r_of_w_different otherPC,r_of_w_different otherLR]

theorem error (s : Reference.AArch64.State) (offset : BitVec 26) :
    read_err (after s offset).machine = read_err s.machine := by
  simp [after,write_pc,write_gpr,read_err,r_of_w_different]

theorem resources (s : Reference.AArch64.State) (offset : BitVec 26) :
    (after s offset).machine.mem = s.machine.mem ∧
    (after s offset).machine.program = s.machine.program ∧
    (after s offset).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s offset).machine.memoryAccesses = s.machine.memoryAccesses ∧
    (after s offset).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s offset).machine.exclusive = s.machine.exclusive ∧
    (after s offset).machine.threadPointerInputs = s.machine.threadPointerInputs ∧
    (after s offset).extraFlags = s.extraFlags := by
  simp [after,write_pc,write_gpr,w,write_base_pc,write_base_gpr]

/-- The SAME original 68-step CALL retains all three source stores and their
packet/frame. Native BL writes its true PC+4 link. Source token64/tag9 remains
an explicit source observation, for subsequent fetched-code label admission. -/
theorem complete {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (s : Reference.AArch64.State) (offset : BitVec 26) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .BR (.Uncond_branch_imm (fields offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ reached, ∃ result : Arm64ProgramEntryLinkComplete.Result prior lr reached,
      InternalRun world 68
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
          (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k
          (allocation initial).1 (Arm64ProgramEntryLinkCall.temps le) reached) ∧
      Reference.AArch64.step s = ⟨after s offset,[],none⟩ ∧
      Arm64EntryMemory.gpr reached.nextblock reached (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)) ∧
      CC.Mem.load .Mint64 reached lr.block 0 = some (.Vlong 64) ∧
      Reference.AArch64.gpr (after s offset) 30 = read_pc s.machine + 4#64 ∧
      FrameBelow initial.nextblock before reached ∧
      (Arm64ProgramEntryLinkCall.temps le).get Arm64ProgramFixture._result = le.get Arm64ProgramFixture._result ∧
      (Arm64ProgramEntryLinkCall.temps le).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  obtain ⟨reached,result,run⟩ := Arm64ProgramEntryLinkComplete.execute prior lr le k hk
  exact ⟨reached,result,run,reference_step s offset instruction decoded noError fetched,
    result.link,result.lr_readback,link s offset,result.caller,
    Arm64ProgramEntryLinkComplete.result_readback le,Arm64ProgramEntryLinkComplete.ctx_preserved le⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkNative
