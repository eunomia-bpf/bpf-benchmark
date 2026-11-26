import KProgFormal.ClightRefinement.Arm64ProgramEntryCbzComplete
import KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterBranchNative
open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)

namespace Cbz
/-- Kernel-checked decode of the real fixed register/width/bit/immediate form. -/
def instruction : Reference.AArch64.Instruction :=
  ⟨0x34000103#32,.BR (.Compare_branch Arm64BranchZero.instruction),by decide +kernel⟩

def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (if Arm64BranchZero.taken s then
    BR.Compare_branch_inst.branch_taken_pc Arm64BranchZero.instruction (read_pc s.machine) else read_pc s.machine + 4#64) s

theorem execute (s : Reference.AArch64.State) :
    BR.exec_compare_branch Arm64BranchZero.instruction s.machine = (after s).machine := by rfl

theorem native_step (s : Reference.AArch64.State)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.BR (.Compare_branch Arm64BranchZero.instruction)) := instruction.valid
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s

theorem reference_step (s : Reference.AArch64.State)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ := by
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp [after,Arm64Nop.atCursor,write_pc,read_memory_accesses,w,write_base_pc]
  have error : read_err (after s).machine = .None := by
    simpa [after,Arm64Nop.atCursor,write_pc,read_err,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s noError fetched,history,List.drop_length,error,noError]
  rfl

theorem pc (s : Reference.AArch64.State) :
    read_pc (after s).machine = if Arm64BranchZero.taken s then
      BR.Compare_branch_inst.branch_taken_pc Arm64BranchZero.instruction (read_pc s.machine) else read_pc s.machine + 4#64 := by
  simp [after,Arm64Nop.atCursor,write_pc,read_pc,r_of_w_same]

/-- The actual original immediate selects its concrete signed byte delta. -/
theorem pc_offset (s : Reference.AArch64.State) :
    read_pc (after s).machine = read_pc s.machine + (if Arm64BranchZero.taken s then 32#64 else 4#64) := by
  rw [pc]
  split <;> rfl

theorem field (s : Reference.AArch64.State) (name : StateField) (other : name ≠ .PC) :
    r name (after s).machine = r name s.machine := by
  simp only [after,Arm64Nop.atCursor,write_pc,r_of_w_different other]

theorem resources (s : Reference.AArch64.State) :
    (after s).machine.mem = s.machine.mem ∧ (after s).machine.program = s.machine.program ∧
    (after s).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s).machine.memoryAccesses = s.machine.memoryAccesses ∧
    (after s).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s).machine.exclusive = s.machine.exclusive ∧
    (after s).machine.threadPointerInputs = s.machine.threadPointerInputs ∧ (after s).extraFlags = s.extraFlags := by
  simp [after,Arm64Nop.atCursor,write_pc,w,write_base_pc]

/-- Actual provider/register representation discharges the earlier input-view
update: that update is the SAME native state, rather than an extra instruction. -/
theorem input_same (s : Reference.AArch64.State) (raw : BitVec 64)
    (word : Reference.AArch64.gpr s 3 = raw) : Arm64ProgramEntryCbzCall.native s raw = s := by
  unfold Arm64ProgramEntryCbzCall.native
  rw [←word]
  change {s with machine := w (.GPR 3#5) (r (.GPR 3#5) s.machine) s.machine} = s
  rw [w_irrelevant]

/-- Both complete actual source exits and the genuine fetched native step
share the original packet's real selected word and an admitted current native
register. The whole source segment retains its actual false-path XOR and common
label; native successors remain explicit for subsequent code/label binding. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) (s : Reference.AArch64.State)
    (word : Reference.AArch64.gpr s 3 = gprs 2)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryJccLabels.takenBody
        (.Kseq Arm64ProgramEntryJccLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCbzLabels.takenBody
        (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k) (allocation initial).1
        (Arm64ProgramEntryCbzComplete.temps le before (gprs 2) s) m) ∧
      Reference.AArch64.step s = ⟨after s,[],none⟩ ∧
      (Arm64ProgramEntryCbzComplete.temps le before (gprs 2) s).get Arm64ProgramFixture._result =
        some (.Vlong (Arm64ProgramEntryCbzExit.result before s)) ∧
      (Arm64ProgramEntryCbzComplete.temps le before (gprs 2) s).get Arm64ProgramFixture._ctx =
        le.get Arm64ProgramFixture._ctx := by
  obtain ⟨count,run⟩ := Arm64ProgramEntryCbzComplete.execute packet le k hk before prior s
  refine ⟨count,run,reference_step s noError fetched,?_,Arm64ProgramEntryCbzComplete.ctx_preserved _ _ _ _⟩
  have result := Arm64ProgramEntryCbzComplete.result_readback le before (gprs 2) s prior
  rw [input_same s (gprs 2) word] at result
  exact result
end Cbz

namespace Tbnz
/-- Kernel-checked decode of the real fixed register/width/bit/immediate form. -/
def instruction : Reference.AArch64.Instruction :=
  ⟨0xb7ffff04#32,.BR (.Test_branch Arm64BranchBit63.instruction),by decide +kernel⟩

def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (if Arm64BranchBit63.taken s then
    BR.Test_branch_inst.branch_taken_pc Arm64BranchBit63.instruction (read_pc s.machine) else read_pc s.machine + 4#64) s

theorem execute (s : Reference.AArch64.State) :
    BR.exec_test_branch Arm64BranchBit63.instruction s.machine = (after s).machine := by rfl

theorem native_step (s : Reference.AArch64.State)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.BR (.Test_branch Arm64BranchBit63.instruction)) := instruction.valid
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s

theorem reference_step (s : Reference.AArch64.State)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ := by
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp [after,Arm64Nop.atCursor,write_pc,read_memory_accesses,w,write_base_pc]
  have error : read_err (after s).machine = .None := by
    simpa [after,Arm64Nop.atCursor,write_pc,read_err,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s noError fetched,history,List.drop_length,error,noError]
  rfl

theorem pc (s : Reference.AArch64.State) :
    read_pc (after s).machine = if Arm64BranchBit63.taken s then
      BR.Test_branch_inst.branch_taken_pc Arm64BranchBit63.instruction (read_pc s.machine) else read_pc s.machine + 4#64 := by
  simp [after,Arm64Nop.atCursor,write_pc,read_pc,r_of_w_same]

/-- The actual original immediate selects its concrete signed byte delta. -/
theorem pc_offset (s : Reference.AArch64.State) :
    read_pc (after s).machine = read_pc s.machine + (if Arm64BranchBit63.taken s then (-32#64) else 4#64) := by
  rw [pc]
  split <;> rfl

theorem field (s : Reference.AArch64.State) (name : StateField) (other : name ≠ .PC) :
    r name (after s).machine = r name s.machine := by
  simp only [after,Arm64Nop.atCursor,write_pc,r_of_w_different other]

theorem resources (s : Reference.AArch64.State) :
    (after s).machine.mem = s.machine.mem ∧ (after s).machine.program = s.machine.program ∧
    (after s).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s).machine.memoryAccesses = s.machine.memoryAccesses ∧
    (after s).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s).machine.exclusive = s.machine.exclusive ∧
    (after s).machine.threadPointerInputs = s.machine.threadPointerInputs ∧ (after s).extraFlags = s.extraFlags := by
  simp [after,Arm64Nop.atCursor,write_pc,w,write_base_pc]

/-- Actual provider/register representation discharges the earlier input-view
update: that update is the SAME native state, rather than an extra instruction. -/
theorem input_same (s : Reference.AArch64.State) (raw : BitVec 64)
    (word : Reference.AArch64.gpr s 4 = raw) : Arm64ProgramEntryTbnzCall.native s raw = s := by
  unfold Arm64ProgramEntryTbnzCall.native
  rw [←word]
  change {s with machine := w (.GPR 4#5) (r (.GPR 4#5) s.machine) s.machine} = s
  rw [w_irrelevant]

/-- Both complete actual source exits and the genuine fetched native step
share the original packet's real selected word and an admitted current native
register. The whole source segment retains its actual false-path XOR and common
label; native successors remain explicit for subsequent code/label binding. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) (s : Reference.AArch64.State)
    (word : Reference.AArch64.gpr s 4 = gprs 3)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCbzLabels.takenBody
        (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
        (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1
        (Arm64ProgramEntryTbnzComplete.temps le before (gprs 3) s) m) ∧
      Reference.AArch64.step s = ⟨after s,[],none⟩ ∧
      (Arm64ProgramEntryTbnzComplete.temps le before (gprs 3) s).get Arm64ProgramFixture._result =
        some (.Vlong (Arm64ProgramEntryTbnzExit.result before s)) ∧
      (Arm64ProgramEntryTbnzComplete.temps le before (gprs 3) s).get Arm64ProgramFixture._ctx =
        le.get Arm64ProgramFixture._ctx := by
  obtain ⟨count,run⟩ := Arm64ProgramEntryTbnzComplete.execute packet le k hk before prior s
  refine ⟨count,run,reference_step s noError fetched,?_,Arm64ProgramEntryTbnzComplete.ctx_preserved _ _ _ _⟩
  have result := Arm64ProgramEntryTbnzComplete.result_readback le before (gprs 3) s prior
  rw [input_same s (gprs 3) word] at result
  exact result
end Tbnz

end KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterBranchNative
