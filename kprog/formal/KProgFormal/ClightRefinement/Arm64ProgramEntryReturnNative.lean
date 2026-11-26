import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryReturnNative
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The actual plain RET X30 form from the mature decoder. -/
def fields : Uncond_branch_reg_cls := {opc := 2,op2 := 31,op3 := 0,Rn := 30,op4 := 0}
def instruction : Reference.AArch64.Instruction := ⟨0xd65f03c0#32,.BR (.Uncond_branch_reg fields),by decide +kernel⟩
def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (Reference.AArch64.gpr s 30) s

/-- Mature RET captures X30 as the actual target and preserves the link. -/
theorem execute (s : Reference.AArch64.State) :
    BR.exec_uncond_branch_reg fields s.machine = (after s).machine := by
  simp +decide [BR.exec_uncond_branch_reg,fields,Uncond_branch_reg_cls.isSupported,
    read_gpr_zr,read_gpr,after,Arm64Nop.atCursor,Reference.AArch64.gpr]
  rfl

theorem native_step (s : Reference.AArch64.State)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.BR (.Uncond_branch_reg fields)) := instruction.valid
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s

theorem reference_step (s : Reference.AArch64.State)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ := by
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp [after,Arm64Nop.atCursor,read_memory_accesses,write_pc,w,write_base_pc]
  have error : read_err (after s).machine = .None := by
    simpa [after,Arm64Nop.atCursor,write_pc,read_err,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s noError fetched,history,List.drop_length,error,noError]
  rfl

theorem pc (s : Reference.AArch64.State) : read_pc (after s).machine = Reference.AArch64.gpr s 30 := by
  simp [after,Arm64Nop.atCursor,write_pc,read_pc,r_of_w_same]

theorem field (s : Reference.AArch64.State) (name : StateField) (other : name ≠ .PC) :
    r name (after s).machine = r name s.machine := by
  simp only [after,Arm64Nop.atCursor,write_pc,r_of_w_different other]

theorem link (s : Reference.AArch64.State) : Reference.AArch64.gpr (after s) 30 = Reference.AArch64.gpr s 30 :=
  field s (.GPR (30#5)) (by decide)

theorem error (s : Reference.AArch64.State) : read_err (after s).machine = read_err s.machine :=
  field s .ERR (by decide)

theorem resources (s : Reference.AArch64.State) :
    (after s).machine.mem = s.machine.mem ∧ (after s).machine.program = s.machine.program ∧
    (after s).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s).machine.memoryAccesses = s.machine.memoryAccesses ∧
    (after s).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s).machine.exclusive = s.machine.exclusive ∧
    (after s).machine.threadPointerInputs = s.machine.threadPointerInputs ∧ (after s).extraFlags = s.extraFlags := by
  simp [after,Arm64Nop.atCursor,write_pc,w,write_base_pc]

/-- The original full RET_TO executes its raw/tag helpers, real repeated LR
store, guard, switch64 and label search on the SAME current packet. The native
instruction consumes its true LR. Actual fetched-code admission supplies the
subsequent connection between source token64 and this physical target. -/
theorem complete {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)))
    (s : Reference.AArch64.State) (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ reached, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr before reached,
      InternalRun world 84
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
          (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1
          (Arm64ProgramEntryReturnComplete.temps le) reached) ∧
      Reference.AArch64.step s = ⟨after s,[],none⟩ ∧
      Arm64EntryMemory.gpr reached.nextblock reached (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)) ∧
      CC.Mem.load .Mint64 reached lr.block 0 = some (.Vlong 64) ∧
      read_pc (after s).machine = Reference.AArch64.gpr s 30 ∧
      Reference.AArch64.gpr (after s) 30 = Reference.AArch64.gpr s 30 ∧
      FrameBelow initial.nextblock before reached ∧
      (Arm64ProgramEntryReturnComplete.temps le).get Arm64ProgramFixture._result = le.get Arm64ProgramFixture._result ∧
      (Arm64ProgramEntryReturnComplete.temps le).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  obtain ⟨reached,effect,run,word,localRead⟩ := Arm64ProgramEntryReturnComplete.execute current lr le k observed
  exact ⟨reached,effect,run,reference_step s noError fetched,word,localRead,pc s,link s,effect.caller,
    Arm64ProgramEntryReturnComplete.result_readback le,Arm64ProgramEntryReturnComplete.ctx_preserved le⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryReturnNative
