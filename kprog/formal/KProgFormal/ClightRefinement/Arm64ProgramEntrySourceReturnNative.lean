import KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryObserver

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntrySourceReturnNative
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- Concrete true native steps and original live source/code observations.
The source heap is the actual pre-terminal witness, before local deallocation. -/
structure Facts (cmpState : Reference.AArch64.State) (conditionOffset : BitVec 19) (callOffset : BitVec 26)
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset)
    (m : CC.Mem) (entry : CC.Val) (lr : CC.Block) : Prop where
  compare : Reference.AArch64.step cmpState = ⟨Arm64ProgramEntryCmpNative.after cmpState,[],none⟩
  branch : Reference.AArch64.step (Arm64ProgramEntryCmpNative.after cmpState) =
    ⟨Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset,[],none⟩
  call : Reference.AArch64.step (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) =
    ⟨Arm64ProgramEntryLinkNative.after (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset,[],none⟩
  ret : Reference.AArch64.step (Arm64ProgramEntryLinkNative.after
      (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset) =
    ⟨Arm64ProgramEntryLinkReturnNative.after (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset,[],none⟩
  observation : Arm64ProgramEntryLinkReturnNative.Observation m entry lr
    (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset)
    (Arm64ProgramEntryLinkReturnNative.after (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset)
    admitted.continuation
  represented : Arm64Nop.FlagsRepresent m.nextblock m entry
    (Arm64ProgramEntryLinkReturnNative.after (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset)

/-- The actual original Callstate-to-Returnstate source execution keeps its
exact supplied provider prefix trace. All post-memory source transitions are
E0, including actual terminal stores, read0/caller and return/freeList. Its
native facts retain current code/register and live-heap admission scope. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (frame : FrameBelow initial.nextblock initial m)
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
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission (Arm64ProgramEntryCmpBgtNative.after cmpState conditionOffset) callOffset)
    (prefixTrace : CC.Trace)
    (prefixRun : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) prefixTrace
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)) :
    ∃ live, ∃ lr : HeaderSourceLocal initial 4, ∃ stored after,
      Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) prefixTrace
        (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord saved mark sourceState gprs flags vectors byte)) k after) ∧
      FrameBelow initial.nextblock initial after ∧
      Facts cmpState conditionOffset callOffset admitted live (.Vptr entry.block 0) lr.block := by
  obtain ⟨lr⟩ := Arm64Producer.header_source_local initial (4 : Fin 12)
  obtain ⟨cmpHeap,updated,cmpEffect,linked,result,reached,effect,current,finalLe,stored,stores,after,freed,count,run,
      cmpNative,bgtNative,callNative,returnNative,observation,represented,caller,_,_⟩ :=
    Arm64ProgramEntryPostMemoryObserver.complete prior lr frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark
      saved savedResult sourceState cmpState left right noError cmpFetched branch conditionOffset branchDecoded branchFetched
      callOffset admitted
  refine ⟨reached,lr,stored,after,freed,?_,caller,
    ⟨cmpNative,bgtNative,callNative,returnNative,observation,represented⟩⟩
  simpa only [CC.Eapp,CC.E0,List.append_nil] using star_trans prefixRun run.sound

end KProgFormal.ClightRefinement.Arm64ProgramEntrySourceReturnNative
