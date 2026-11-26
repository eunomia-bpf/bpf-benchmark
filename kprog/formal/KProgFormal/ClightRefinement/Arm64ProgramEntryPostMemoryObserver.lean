import KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryReturnNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryReturn

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryObserver
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- Imported subtraction rewrites all four flags. Its original GT observation
therefore depends on the actual operands, retaining the same condition binding. -/
theorem condition_independent (first second : Reference.AArch64.State) (lhs rhs : BitVec 64) :
    Arm64ProgramEntryCmpGt.taken first lhs rhs = Arm64ProgramEntryCmpGt.taken second lhs rhs := by
  simp +decide [Arm64ProgramEntryCmpGt.taken,Arm64ProgramEntryCmpFlags.native,ConditionHolds,
    write_pstate,read_flag,r_of_w_same,r_of_w_different]

theorem scalar_matches (sourceState cmpState : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64)
    (flags : Fin 4 → BitVec 64) (vectors : Fin 64 → BitVec 64) (saved : BitVec 64) (mark : BitVec 32)
    (left : Reference.AArch64.gpr cmpState 3 = gprs 2) (right : Reference.AArch64.gpr cmpState 4 = gprs 3) :
    Arm64ProgramEntryPostMemoryReturnNative.scalar sourceState cmpState gprs flags vectors saved mark =
      Arm64ProgramEntryCmpExit.result (Arm64ProgramEntryPostMemoryControlNative.prefixValue sourceState gprs flags vectors saved mark)
        (Arm64ProgramEntryTbnzCall.native (Arm64ProgramEntryCbzCall.native
          (Arm64ClobberNativeFlags.native sourceState flags) (gprs 2)) (gprs 3)) (gprs 2) (gprs 3) := by
  unfold Arm64ProgramEntryPostMemoryReturnNative.scalar Arm64ProgramEntryCmpExit.result
  rw [Arm64ProgramEntryCmpNative.condition cmpState (gprs 2) (gprs 3) left right,
    condition_independent cmpState (Arm64ProgramEntryTbnzCall.native (Arm64ProgramEntryCbzCall.native
      (Arm64ClobberNativeFlags.native sourceState flags) (gprs 2)) (gprs 3)) (gprs 2) (gprs 3)]

/-- The new same-packet native/control execution has exactly the previously
proved original source resultWord. This identifies the source observer; the
independent native/global output-observer refinement remains its own domain. -/
theorem result_matches (sourceState cmpState : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64)
    (flags : Fin 4 → BitVec 64) (vectors : Fin 64 → BitVec 64) (saved : BitVec 64) (mark : BitVec 32) (byte : BitVec 8)
    (left : Reference.AArch64.gpr cmpState 3 = gprs 2) (right : Reference.AArch64.gpr cmpState 4 = gprs 3) :
    Arm64ProgramEntryPostMemoryReturnNative.resultWord sourceState cmpState gprs flags vectors saved mark byte =
      Arm64ProgramEntryMemoryReturn.resultWord saved mark sourceState gprs flags vectors byte := by
  unfold Arm64ProgramEntryPostMemoryReturnNative.resultWord
  rw [scalar_matches sourceState cmpState gprs flags vectors saved mark left right]
  rfl

/-- The SAME executed source return retains the original resultWord contract. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (lr : HeaderSourceLocal initial 4) (frame : FrameBelow initial.nextblock initial m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (saved : BitVec 64) (savedResult : le.get Arm64ProgramFixture._result = some (.Vlong saved))
    (sourceState cmpState : Reference.AArch64.State)
    (left : Reference.AArch64.gpr cmpState 3 = gprs 2) (right : Reference.AArch64.gpr cmpState 4 = gprs 3)
    (noError : read_err cmpState.machine = .None)
    (cmpFetched : fetch_inst (read_pc cmpState.machine) cmpState.machine = some Arm64ProgramEntryCmpNative.instruction.encoding)
    (branch : Reference.AArch64.Instruction) (conditionOffset : BitVec 19)
    (branchDecoded : branch.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) conditionOffset)))
    (branchFetched : fetch_inst (read_pc (Arm64ProgramEntryCmpNative.after cmpState).machine)
      (Arm64ProgramEntryCmpNative.after cmpState).machine = some branch.encoding)
    (callOffset : BitVec 26)
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset) :
    let callState := Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset
    let finalNative := Arm64ProgramEntryLinkReturnNative.after callState callOffset
    ∃ cmpHeap, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue cmpHeap,
      Arm64Compare.Stores.Effect prior.memory.storage
        (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
        (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.sign false) cmpHeap ∧
      ∃ linked, ∃ result : Arm64ProgramEntryLinkComplete.Result updated lr linked,
      ∃ reached, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr linked reached,
      ∃ current : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue reached,
      ∃ (finalLe : CC.TempEnv), ∃ stored, ∃ stores : Arm64ProgramEntryTerminalStores.Effect current.memory.storage
        (Arm64ProgramEntryContinuationByte.value (Arm64ProgramEntryPostMemoryReturnNative.scalar sourceState cmpState gprs flags vectors saved mark) byte) stored,
      ∃ after, ∃ freed : Arm64ProgramEntryTerminalFree.FreeResult initial stored after, ∃ count,
      InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
        (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord saved mark sourceState gprs flags vectors byte)) k after) ∧
      Reference.AArch64.step cmpState = ⟨Arm64ProgramEntryCmpNative.after cmpState,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryCmpNative.after cmpState) = ⟨callState,[],none⟩ ∧
      Reference.AArch64.step callState = ⟨Arm64ProgramEntryLinkNative.after callState callOffset,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryLinkNative.after callState callOffset) = ⟨finalNative,[],none⟩ ∧
      Arm64ProgramEntryLinkReturnNative.Observation reached (.Vptr entry.block 0) lr.block callState finalNative admitted.continuation ∧
      Arm64Nop.FlagsRepresent reached.nextblock reached (.Vptr entry.block 0) finalNative ∧
      FrameBelow initial.nextblock initial after ∧
      finalLe.get Arm64ProgramFixture._result = some (.Vlong (Arm64ProgramEntryPostMemoryReturnNative.scalar sourceState cmpState gprs flags vectors saved mark)) ∧
      finalLe.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset) := by
  simpa only [result_matches sourceState cmpState gprs flags vectors saved mark byte left right] using
    Arm64ProgramEntryPostMemoryReturnNative.complete prior lr frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark
      saved savedResult sourceState cmpState left right noError cmpFetched branch conditionOffset branchDecoded branchFetched
      callOffset admitted

end KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryObserver
