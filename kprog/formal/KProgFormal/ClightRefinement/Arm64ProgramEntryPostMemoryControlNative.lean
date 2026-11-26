import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpCallReturnNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryControlNative
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The original source observer after real V31.hi/JCC/CBZ/TBNZ calls. All
branch predicates and source results are the existing imported bindings. -/
def prefixValue (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64)
    (flags : Fin 4 → BitVec 64) (vectors : Fin 64 → BitVec 64) (saved : BitVec 64) (mark : BitVec 32) : BitVec 64 :=
  let flagsState := Arm64ClobberNativeFlags.native s flags
  let compareState := Arm64ProgramEntryCbzCall.native flagsState (gprs 2)
  let cbz := Arm64ProgramEntryCbzExit.result
    (Arm64ProgramEntryJccExit.result (saved ^^^ vectors 63) mark flagsState) compareState
  Arm64ProgramEntryTbnzExit.result cbz (Arm64ProgramEntryTbnzCall.native compareState (gprs 3))

/-- Execute the complete original post-memcpy prefix once. Its actual reached
heap/temp/caller observations feed actual CMP/CALL/RET_TO, with no second
provider invocation or fresh reached resource/readback witness. Native suffix
register/code/fetch admissions keep their original explicit current domain. -/
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
    let scalar := if ConditionHolds (12#4) (Arm64ProgramEntryCmpNative.after cmpState).machine
      then prefixValue sourceState gprs flags vectors saved mark
      else prefixValue sourceState gprs flags vectors saved mark ^^^ 8#64
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
      ∃ finalLe count, InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
          (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1 finalLe reached) ∧
      Reference.AArch64.step cmpState = ⟨Arm64ProgramEntryCmpNative.after cmpState,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryCmpNative.after cmpState) = ⟨callState,[],none⟩ ∧
      Reference.AArch64.step callState = ⟨Arm64ProgramEntryLinkNative.after callState callOffset,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryLinkNative.after callState callOffset) = ⟨finalNative,[],none⟩ ∧
      Arm64ProgramEntryLinkReturnNative.Observation reached (.Vptr entry.block 0) lr.block callState finalNative admitted.continuation ∧
      Arm64Nop.FlagsRepresent reached.nextblock reached (.Vptr entry.block 0) finalNative ∧
      FrameBelow initial.nextblock initial reached ∧
      finalLe.get Arm64ProgramFixture._result = some (.Vlong scalar) ∧
      finalLe.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset) := by
  dsimp only
  obtain ⟨prefixLe,prefixCount,prefixRun,ctxEq,resultEq⟩ := Arm64ProgramEntryTbnzComplete.from_memcpy prior frame le k hk
    ctxBlock ctxOffset mark ctxBelow ctx originalMark saved savedResult sourceState
  change prefixLe.get Arm64ProgramFixture._result =
    some (.Vlong (prefixValue sourceState gprs flags vectors saved mark)) at resultEq
  obtain ⟨cmpHeap,updated,cmpEffect,linked,result,reached,effect,current,count,run,
      cmpNative,bgtNative,callNative,returnNative,observation,represented,caller,resultTemp,ctxTemp⟩ :=
    Arm64ProgramEntryCmpCallReturnNative.complete prior lr prefixLe k hk
      (prefixValue sourceState gprs flags vectors saved mark) resultEq cmpState left right noError cmpFetched
      branch conditionOffset branchDecoded branchFetched callOffset admitted
  exact ⟨cmpHeap,updated,cmpEffect,linked,result,reached,effect,current,_,_,prefixRun.trans run,
    cmpNative,bgtNative,callNative,returnNative,observation,represented,frame.trans caller,
    resultTemp,(ctxTemp.trans ctxEq).trans ctx⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryControlNative
