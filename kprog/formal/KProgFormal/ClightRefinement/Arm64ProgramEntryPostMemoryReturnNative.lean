import KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryControlNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryReturnNative
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

def scalar (sourceState cmpState : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64)
    (flags : Fin 4 → BitVec 64) (vectors : Fin 64 → BitVec 64) (saved : BitVec 64) (mark : BitVec 32) : BitVec 64 :=
  let observed := Arm64ProgramEntryPostMemoryControlNative.prefixValue sourceState gprs flags vectors saved mark
  if ConditionHolds (12#4) (Arm64ProgramEntryCmpNative.after cmpState).machine then observed else observed ^^^ 8#64

def resultWord (sourceState cmpState : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64)
    (flags : Fin 4 → BitVec 64) (vectors : Fin 64 → BitVec 64) (saved : BitVec 64) (mark : BitVec 32)
    (byte : BitVec 8) : BitVec 32 :=
  (Arm64ProgramEntryContinuationByte.value (scalar sourceState cmpState gprs flags vectors saved mark) byte).setWidth 32

/-- The actual same-packet post-memory source/control witness supplies the
real copied-byte observer, terminal X0/tag/SP stores, original read0/caller
and complete return/freeList. Native four-step/control observations retain
their live pre-terminal scope; caller memory is retained through actual free. -/
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
        (Arm64ProgramEntryContinuationByte.value (scalar sourceState cmpState gprs flags vectors saved mark) byte) stored,
      ∃ after, ∃ freed : Arm64ProgramEntryTerminalFree.FreeResult initial stored after, ∃ count,
      InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
        (.Returnstate (.Vint (resultWord sourceState cmpState gprs flags vectors saved mark byte)) k after) ∧
      Reference.AArch64.step cmpState = ⟨Arm64ProgramEntryCmpNative.after cmpState,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryCmpNative.after cmpState) = ⟨callState,[],none⟩ ∧
      Reference.AArch64.step callState = ⟨Arm64ProgramEntryLinkNative.after callState callOffset,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryLinkNative.after callState callOffset) = ⟨finalNative,[],none⟩ ∧
      Arm64ProgramEntryLinkReturnNative.Observation reached (.Vptr entry.block 0) lr.block callState finalNative admitted.continuation ∧
      Arm64Nop.FlagsRepresent reached.nextblock reached (.Vptr entry.block 0) finalNative ∧
      FrameBelow initial.nextblock initial after ∧
      finalLe.get Arm64ProgramFixture._result = some (.Vlong (scalar sourceState cmpState gprs flags vectors saved mark)) ∧
      finalLe.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset) := by
  dsimp only
  obtain ⟨cmpHeap,updated,cmpEffect,linked,result,reached,effect,current,finalLe,count,run,
      cmpNative,bgtNative,callNative,returnNative,observation,represented,caller,resultTemp,ctxTemp⟩ :=
    Arm64ProgramEntryPostMemoryControlNative.complete prior lr frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark
      saved savedResult sourceState cmpState left right noError cmpFetched branch conditionOffset branchDecoded branchFetched
      callOffset admitted
  change finalLe.get Arm64ProgramFixture._result = some (.Vlong (scalar sourceState cmpState gprs flags vectors saved mark)) at resultTemp
  have call : CC.callCont k = k := by cases k <;> simp_all [CC.isCallCont,CC.callCont]
  obtain ⟨stored,stores,after,freed,terminal,terminalCaller⟩ := Arm64ProgramEntryTerminalComplete.from_continuation current finalLe k
    (scalar sourceState cmpState gprs flags vectors saved mark) resultTemp
  simp only [Arm64ProgramEntryReturnTarget.targetCont,call] at run
  have joined := run.trans terminal
  refine ⟨cmpHeap,updated,cmpEffect,linked,result,reached,effect,current,finalLe,stored,stores,after,freed,count+100,?_,
    cmpNative,bgtNative,callNative,returnNative,observation,represented,caller.trans terminalCaller,resultTemp,ctxTemp⟩
  simpa only [resultWord,call] using joined

end KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryReturnNative
