import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpNative

/-- Actual mature decoded CMP X3,X4 alias: SUBS XZR,X3,X4,LSL0. -/
def fields : Add_sub_shifted_reg_cls :=
  {sf := 1, op := 1, S := 1, shift := 0, Rm := 4, imm6 := 0, Rn := 3, Rd := 31}

/-- Genuine decode of the actual wide CMP source operand pair. -/
def instruction : Reference.AArch64.Instruction :=
  ⟨0xeb04007f#32,.DPR (.Add_sub_shifted_reg fields),by decide +kernel⟩

/-- Bind the external arithmetic and state writers; there is no local ISA
arithmetic or replacement decoder. -/
def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  let flags := AddWithCarry (Reference.AArch64.gpr s 3) (~~~Reference.AArch64.gpr s 4) (1#1)
  {s with machine := write_pstate flags.snd (write_pc (read_pc s.machine + 4#64) s.machine)}


/-- The real imported instruction performs exactly the external carry/flag
update, advances PC and discards the zero-register destination. -/
theorem execute (s : Reference.AArch64.State) :
    DPR.exec_add_sub_shifted_reg fields s.machine = (after s).machine := by
  simp +decide [DPR.exec_add_sub_shifted_reg,fields,after,read_gpr_zr,read_gpr,
    write_gpr_zr,decode_shift,shift_reg,Reference.AArch64.gpr]
  change write_pstate (AddWithCarry (Reference.AArch64.gpr s 3)
    (~~~(Reference.AArch64.gpr s 4 <<< (0 : Nat))) (1#1)).snd
    (write_pc (read_pc s.machine + 4#64) s.machine) = (after s).machine
  rw [BitVec.shiftLeft_zero]
  rfl

/-- Bind the same external operation to the genuine fetched/decoded word. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPR (.Add_sub_shifted_reg fields)) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s

/-- Complete native histories are retained, with no new event or fault. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ := by
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp [after,read_memory_accesses,write_pstate,write_pc,w,write_base_pc,write_base_flag]
  have afterError : read_err (after s).machine = .None := by
    simpa [after,write_pstate,read_err,write_pc,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s instruction decoded noError fetched,
    history,List.drop_length,afterError,noError]
  rfl

/-- CMP does not write any general-purpose register or the stack pointer. -/
theorem registers (s : Reference.AArch64.State) :
    (∀ i, Reference.AArch64.gpr (after s) i = Reference.AArch64.gpr s i) ∧
    Reference.AArch64.sp (after s) = Reference.AArch64.sp s ∧
    (∀ i, Reference.AArch64.readVector (after s) i = Reference.AArch64.readVector s i) ∧
    (after s).extraFlags = s.extraFlags := by
  simp [after,Reference.AArch64.gpr,Reference.AArch64.sp,Reference.AArch64.readVector,
    write_pstate,write_pc,r_of_w_different]



theorem pc (s : Reference.AArch64.State) : read_pc (after s).machine = read_pc s.machine + 4#64 := by
  simp [after,write_pstate,write_pc,read_pc,r_of_w_same,r_of_w_different]

theorem error (s : Reference.AArch64.State) : read_err (after s).machine = read_err s.machine := by
  simp [after,write_pstate,write_pc,read_err,r_of_w_different]

theorem resources (s : Reference.AArch64.State) :
    (after s).machine.mem = s.machine.mem ∧ (after s).machine.program = s.machine.program ∧
    (after s).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s).machine.memoryAccesses = s.machine.memoryAccesses ∧
    (after s).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s).machine.exclusive = s.machine.exclusive ∧
    (after s).machine.threadPointerInputs = s.machine.threadPointerInputs := by
  simp [after,write_pstate,write_pc,w,write_base_pc,write_base_flag]

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The actual next-PC flags state uses the SAME arbitrary full64 operands. -/
theorem source_flags (s : Reference.AArch64.State) (lhs rhs : BitVec 64)
    (left : Reference.AArch64.gpr s 3 = lhs) (right : Reference.AArch64.gpr s 4 = rhs) :
    after s = Arm64ProgramEntryCmpFlags.native
      (Arm64Nop.atCursor (read_pc s.machine + 4#64) s) lhs rhs := by
  simp only [after,Arm64ProgramEntryCmpFlags.native,Arm64Nop.atCursor,left,right]

/-- The actual source GT choice observes the very flags produced by fetched
SUBS, retaining the imported condition predicate and every source flag store. -/
theorem condition (s : Reference.AArch64.State) (lhs rhs : BitVec 64)
    (left : Reference.AArch64.gpr s 3 = lhs) (right : Reference.AArch64.gpr s 4 = rhs) :
    ConditionHolds (12#4) (after s).machine = Arm64ProgramEntryCmpGt.taken s lhs rhs := by
  simp +decide [after,Arm64ProgramEntryCmpGt.taken,Arm64ProgramEntryCmpFlags.native,
    ConditionHolds,write_pstate,read_flag,write_pc,r_of_w_same,r_of_w_different,left,right]

/-- This complete source execution supplies the actual updated packet and all
FOUR original stores. Its native CMP is the real fetched instruction; the
following original GT choice uses exactly its imported flags and retains both
source exits, XOR8, context, caller and reached heap. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) (s : Reference.AArch64.State)
    (left : Reference.AArch64.gpr s 3 = gprs 2) (right : Reference.AArch64.gpr s 4 = gprs 3)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ reached, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue reached,
      Arm64Compare.Stores.Effect packet.memory.storage
        (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
        (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.sign false) reached ∧
      ∃ count, InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
          (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
          (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1
          (Arm64ProgramEntryCmpComplete.temps le before (gprs 2) (gprs 3) s) reached) ∧
      Reference.AArch64.step s = ⟨after s,[],none⟩ ∧
      Arm64Nop.FlagsRepresent reached.nextblock reached (.Vptr entry.block 0) (after s) ∧
      (Arm64ProgramEntryCmpComplete.temps le before (gprs 2) (gprs 3) s).get Arm64ProgramFixture._result =
        some (.Vlong (if ConditionHolds (12#4) (after s).machine then before else before ^^^ 8#64)) ∧
      (Arm64ProgramEntryCmpComplete.temps le before (gprs 2) (gprs 3) s).get Arm64ProgramFixture._ctx =
        le.get Arm64ProgramFixture._ctx := by
  obtain ⟨reached,updated,effect,count,run⟩ := Arm64ProgramEntryCmpComplete.execute packet le k hk before prior s
  refine ⟨reached,updated,effect,count,run,reference_step s instruction rfl noError fetched,?_,?_,
    Arm64ProgramEntryCmpComplete.ctx_preserved _ _ _ _ _⟩
  · rw [source_flags s (gprs 2) (gprs 3) left right]
    exact Arm64ProgramEntryCmpFlags.represented (gprs 2) (gprs 3) updated _
  · rw [Arm64ProgramEntryCmpComplete.result_readback le before (gprs 2) (gprs 3) s prior,
      condition s (gprs 2) (gprs 3) left right]
    rfl

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpNative
