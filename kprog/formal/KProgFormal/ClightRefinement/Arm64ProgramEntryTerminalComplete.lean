import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalFree

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalComplete
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The SAME copied bytes and current resources supply original byte80/XOR,
three real terminal stores, actual read0/caller and original return/freeList. -/
theorem from_continuation {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberResult.Packet base abi byte rawR0 16 gprs flags vectors cell flagValue before)
    (le : CC.TempEnv) (k : CC.Cont) (saved : BitVec 64)
    (read : le.get Arm64ProgramFixture._result = some (.Vlong saved)) :
    ∃ stored, ∃ stores : Arm64ProgramEntryTerminalStores.Effect current.memory.storage
        (Arm64ProgramEntryContinuationByte.value saved byte) stored,
      ∃ after, Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
        InternalRun world 100
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
            (.Kseq Arm64ProgramEntryReturnTarget.afterContinuation k) (allocation initial).1 le before)
          (.Returnstate (.Vint ((Arm64ProgramEntryContinuationByte.value saved byte).setWidth 32)) (CC.callCont k) after) ∧
        FrameBelow initial.nextblock before after := by
  have bytes := Arm64ProgramEntryContinuationByte.execute current le k saved read
  let reachedLe := Arm64ProgramEntryContinuationByte.temps le saved byte
  obtain ⟨stored,stores,assigned⟩ := Arm64ProgramEntryTerminalStores.execute current.memory.storage current.memory.resources
    reachedLe k (Arm64ProgramEntryContinuationByte.value saved byte) (Arm64ProgramEntryContinuationByte.result_value le saved byte)
  obtain ⟨after,freed,returned⟩ := Arm64ProgramEntryTerminalFree.execute entry current.memory.storage.sp
    (Arm64ProgramEntryTerminalState.resources current stores) reachedLe k (Arm64ProgramEntryContinuationByte.value saved byte)
    (Arm64ProgramEntryTerminalFrame.sp_readback stores) (Arm64ProgramEntryTerminalState.r0 current stores)
  exact ⟨stored,stores,after,freed,(bytes.trans assigned).trans returned,(Arm64ProgramEntryTerminalFrame.caller stores).trans freed.caller⟩

/-- Complete genuine callee/RET_TO plus byte80, three terminal stores and
original function return, on the SAME repeated-LR and terminal-store effects. -/
theorem from_callee {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberResult.Packet base abi byte rawR0 16 gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)))
    (saved : BitVec 64) (read : le.get Arm64ProgramFixture._result = some (.Vlong saved)) :
    ∃ lrWritten, ∃ lrEffect : Arm64ProgramEntryLinkCall.Effect lr before lrWritten,
      ∃ stored, ∃ stores : Arm64ProgramEntryTerminalStores.Effect (Arm64ProgramEntryLinkFrame.packet lrEffect current).memory.storage
        (Arm64ProgramEntryContinuationByte.value saved byte) stored,
      ∃ after, Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
        InternalRun world 184
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1 le before)
          (.Returnstate (.Vint ((Arm64ProgramEntryContinuationByte.value saved byte).setWidth 32)) k after) ∧
        FrameBelow initial.nextblock before after := by
  have call : CC.callCont k = k := by cases k <;> simp_all [CC.isCallCont,CC.callCont]
  obtain ⟨lrWritten,lrEffect,callee,_,_⟩ := Arm64ProgramEntryReturnComplete.execute current lr le k observed
  let reached := Arm64ProgramEntryLinkFrame.packet lrEffect current
  obtain ⟨stored,stores,after,freed,terminal,caller⟩ := from_continuation reached (Arm64ProgramEntryReturnComplete.temps le) k saved
    ((Arm64ProgramEntryReturnComplete.result_readback le).trans read)
  have callee' := callee
  simp only [Arm64ProgramEntryReturnTarget.targetCont,call] at callee'
  exact ⟨lrWritten,lrEffect,stored,stores,after,freed,by simpa only [call] using callee'.trans terminal,lrEffect.caller.trans caller⟩

/-- Every source operation after the original memcpy output reaches the real
uint32 function return and local release on one actual provider/memory witness. -/
theorem from_memcpy {initial seed m : CC.Mem} {entry : HeaderLocal initial}
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
    (before : BitVec 64) (saved : le.get Arm64ProgramFixture._result = some (.Vlong before))
    (s : Reference.AArch64.State) :
    let flagsState := Arm64ClobberNativeFlags.native s flags
    let compareState := Arm64ProgramEntryCbzCall.native flagsState (gprs 2)
    let cbzResult := Arm64ProgramEntryCbzExit.result
      (Arm64ProgramEntryJccExit.result (before ^^^ (vectors 63)) mark flagsState) compareState
    let tbnzState := Arm64ProgramEntryTbnzCall.native compareState (gprs 3)
    let tbnzResult := Arm64ProgramEntryTbnzExit.result cbzResult tbnzState
    let scalar := Arm64ProgramEntryCmpExit.result tbnzResult tbnzState (gprs 2) (gprs 3)
    ∃ cmpAfter, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue cmpAfter,
      ∃ cmpLe linked, ∃ linkedResult : Arm64ProgramEntryLinkComplete.Result updated lr linked,
      ∃ returned, ∃ lrEffect : Arm64ProgramEntryLinkCall.Effect lr linked returned,
      ∃ stored, ∃ stores : Arm64ProgramEntryTerminalStores.Effect
        (Arm64ProgramEntryLinkFrame.packet lrEffect linkedResult.packet).memory.storage
        (Arm64ProgramEntryContinuationByte.value scalar byte) stored,
      ∃ after, ∃ freed : Arm64ProgramEntryTerminalFree.FreeResult initial stored after, ∃ count,
        Arm64Compare.Stores.Effect prior.memory.storage
          (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
          (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
          (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
          (Arm64ProgramEntryCmpArithmetic.sign false) cmpAfter ∧
        InternalRun world count
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
          (.Returnstate (.Vint ((Arm64ProgramEntryContinuationByte.value scalar byte).setWidth 32)) k after) ∧
        (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps cmpLe)).get Arm64ProgramFixture._ctx =
          le.get Arm64ProgramFixture._ctx ∧ FrameBelow initial.nextblock initial after := by
  dsimp only
  have call : CC.callCont k = k := by cases k <;> simp_all [CC.isCallCont,CC.callCont]
  obtain ⟨cmpAfter,updated,cmpLe,linked,linkedResult,returned,lrEffect,count,cmpEffect,branches,ctxEq,resultEq,caller⟩ :=
    Arm64ProgramEntryReturnComplete.from_memcpy prior lr frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark before saved s
  let reached := Arm64ProgramEntryLinkFrame.packet lrEffect linkedResult.packet
  obtain ⟨stored,stores,after,freed,terminal,terminalCaller⟩ := from_continuation reached
    (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps cmpLe)) k _ resultEq
  have branches' := branches
  simp only [Arm64ProgramEntryReturnTarget.targetCont,call] at branches'
  exact ⟨cmpAfter,updated,cmpLe,linked,linkedResult,returned,lrEffect,stored,stores,after,freed,_,cmpEffect,
    by simpa only [call] using branches'.trans terminal,ctxEq,caller.trans terminalCaller⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalComplete
