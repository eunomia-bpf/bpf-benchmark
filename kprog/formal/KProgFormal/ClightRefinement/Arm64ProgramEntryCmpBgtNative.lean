import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryJccNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpBgtNative
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The actual B.GT consumes the same fetched SUBS state and its true PC+4. -/
def after (s : Reference.AArch64.State) (offset : BitVec 19) : Reference.AArch64.State :=
  Arm64ProgramEntryJccNative.after (Arm64ProgramEntryCmpNative.after s) (12#4) offset

theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (offset : BitVec 19)
    (decoded : instruction.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc (Arm64ProgramEntryCmpNative.after s).machine)
      (Arm64ProgramEntryCmpNative.after s).machine = some instruction.encoding) :
    Reference.AArch64.step (Arm64ProgramEntryCmpNative.after s) = ⟨after s offset,[],none⟩ := by
  apply Arm64ProgramEntryJccNative.reference_step _ instruction _ offset decoded
  · exact (Arm64ProgramEntryCmpNative.error s).trans noError
  · exact fetched

/-- The actual branch preserves the reached source-to-native flag relation. -/
theorem flags_after (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val)
    (s : Reference.AArch64.State) (offset : BitVec 19)
    (represented : Arm64Nop.FlagsRepresent frontier m entry (Arm64ProgramEntryCmpNative.after s)) :
    Arm64Nop.FlagsRepresent frontier m entry (after s offset) := by
  have same (flag : PFlag) : read_flag flag (after s offset).machine =
      read_flag flag (Arm64ProgramEntryCmpNative.after s).machine := by
    exact Arm64ProgramEntryJccNative.field _ (12#4) offset (.FLAG flag) (by intro impossible; cases impossible)
  unfold Arm64Nop.FlagsRepresent at represented ⊢
  simpa only [same] using represented

/-- Both native successors use the same actual compare flags and real B.GT
immediate; its base cursor is the genuine SUBS successor, not a source label. -/
theorem pc (s : Reference.AArch64.State) (offset : BitVec 19) :
    read_pc (after s offset).machine =
      if ConditionHolds (12#4) (Arm64ProgramEntryCmpNative.after s).machine then
        BR.Cond_branch_imm_inst.branch_taken_pc (Arm64ProgramEntryJccNative.fields (12#4) offset)
          (read_pc s.machine + 4#64)
      else read_pc s.machine + 4#64 + 4#64 := by
  rw [after,Arm64ProgramEntryJccNative.pc,Arm64ProgramEntryCmpNative.pc]

/-- The SAME full original CMP caller, four real flag stores and updated
packet connect to BOTH genuine fetched native instructions in order. Source
GT/XOR8, ctx/result and caller frame remain exact. Current native register/code
admissions are explicit; a native source-label map is the continuing route. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) (s : Reference.AArch64.State)
    (left : Reference.AArch64.gpr s 3 = gprs 2) (right : Reference.AArch64.gpr s 4 = gprs 3)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some Arm64ProgramEntryCmpNative.instruction.encoding)
    (branch : Reference.AArch64.Instruction) (offset : BitVec 19)
    (decoded : branch.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) offset)))
    (branchFetched : fetch_inst (read_pc (Arm64ProgramEntryCmpNative.after s).machine)
      (Arm64ProgramEntryCmpNative.after s).machine = some branch.encoding) :
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
      Reference.AArch64.step s = ⟨Arm64ProgramEntryCmpNative.after s,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryCmpNative.after s) = ⟨after s offset,[],none⟩ ∧
      Arm64Nop.FlagsRepresent reached.nextblock reached (.Vptr entry.block 0) (after s offset) ∧
      (Arm64ProgramEntryCmpComplete.temps le before (gprs 2) (gprs 3) s).get Arm64ProgramFixture._result =
        some (.Vlong (if ConditionHolds (12#4) (Arm64ProgramEntryCmpNative.after s).machine then before else before ^^^ 8#64)) ∧
      (Arm64ProgramEntryCmpComplete.temps le before (gprs 2) (gprs 3) s).get Arm64ProgramFixture._ctx =
        le.get Arm64ProgramFixture._ctx := by
  obtain ⟨reached,updated,effect,count,run,cmp,represented,result,ctx⟩ :=
    Arm64ProgramEntryCmpNative.complete packet le k hk before prior s left right noError fetched
  exact ⟨reached,updated,effect,count,run,cmp,
    reference_step s branch offset decoded noError branchFetched,
    flags_after reached.nextblock reached (.Vptr entry.block 0) s offset represented,result,ctx⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpBgtNative
