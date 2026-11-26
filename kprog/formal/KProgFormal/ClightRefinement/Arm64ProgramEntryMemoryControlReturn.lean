import KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryBranchSites
import KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryCalls

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryControlReturn
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- Both complete original memory calls supply their actual provider arrays,
current Packet and original source trace. THAT witness determines the CMP view
and chosen genuine B.GT successor code, then the complete source return/free.
Actual physical native/helper execution and full program/output correspondence
retain their explicit separate domains. -/
theorem compose {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {oldStorage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result oldStorage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (view : Arm64MemsetHeaderView.View initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (abi : TailLocal initial 6)
    (resources : Arm64ProgramEntryResources.Resources initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (spAtBase : storage.spValue = (-32#64))
    (gpr : Arm64EntryMemory.gpr (Arm64MemsetSource.allocation constantAfter).2.nextblock
      (Arm64MemsetSource.allocation constantAfter).2 (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2
      view.tags.block (j.val : Int) = some (.Vint 0))
    (cell : TailLocal initial 5) (ready : CC.Mem)
    (readyPacket : Arm64MemsetHeaderView.Ready initial ready entry)
    (retained : Arm64ProducerTailFrame.Frame initial entry ready constantAfter)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe)
    (registerInputs : ∀ outerLe, Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe)
    (flagInputs : ∀ outerLe gprs, Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe gprs)
    (vectorInputs : ∀ outerLe gprs flags,
      Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe gprs flags)
    (copyByteInputs : ∀ copyBefore outerLe,
      Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe)
    (copyRegisterInputs : ∀ copyBefore outerLe,
      Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe)
    (copyFlagInputs : ∀ copyBefore outerLe gprs,
      Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe gprs)
    (copyVectorInputs : ∀ copyBefore outerLe gprs flags,
      Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe gprs flags)
    (le : CC.TempEnv) (k : CC.Cont) (ctx : CC.Val) (prefixTrace : CC.Trace)
    (prefixRun : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial) prefixTrace
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
        (Arm64ProgramEntryAllocation.allocation initial).1 le constantAfter))
    (prefixCaller : FrameBelow initial.nextblock initial constantAfter)
    (hk : CC.isCallCont k = true) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (context : ctx = .Vptr ctxBlock ctxOffset) (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctxRead : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (saved : BitVec 64) (savedRead : le.get Arm64ProgramFixture._result = some (.Vlong saved))
    (sourceState : Reference.AArch64.State)
    (noError : read_err sourceState.machine = .None)
    (cmpFetched : fetch_inst (read_pc sourceState.machine) sourceState.machine = some Arm64ProgramEntryCmpNative.instruction.encoding)
    (branch : Reference.AArch64.Instruction) (conditionOffset : BitVec 19)
    (branchDecoded : branch.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) conditionOffset)))
    (branchFetched : fetch_inst (read_pc sourceState.machine + 4#64) sourceState.machine = some branch.encoding)
    (sites : Arm64ProgramEntryPostMemoryBranchSites.Sites sourceState conditionOffset) :
    ∃ gprs flags vectors trace live, ∃ lr : HeaderSourceLocal initial 4, ∃ stored after,
      Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial) trace
        (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord saved mark sourceState gprs flags vectors
          (Arm64MemsetLossSetup.byte mark))) k after) ∧
      FrameBelow initial.nextblock initial after ∧
      Arm64ProgramEntrySourceReturnNative.Facts (Arm64ProgramEntryPostMemoryCmpView.native sourceState gprs flags)
        conditionOffset (Arm64ProgramEntryPostMemoryBranchSites.chosenOffset sourceState gprs flags conditionOffset sites)
        (Arm64ProgramEntryPostMemoryBranchSites.admission sourceState gprs flags conditionOffset sites)
        live (.Vptr entry.block 0) lr.block := by
  subst ctx
  obtain ⟨m,written,copyBefore,gprs,flags,vectors,trace,current,memoryRun,copyFree,memoryCaller,finalBound⟩ :=
    Arm64ProgramEntryMemoryCalls.compose mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes
      cell ready readyPacket retained byteInputs registerInputs flagInputs vectorInputs
      copyByteInputs copyRegisterInputs copyFlagInputs copyVectorInputs le k (.Vptr ctxBlock ctxOffset) prefixTrace prefixRun prefixCaller
  obtain ⟨live,lr,stored,after,freed,fullRun,caller,facts⟩ := Arm64ProgramEntryPostMemoryBranchSites.execute
    current memoryCaller le k hk ctxBlock ctxOffset mark ctxBelow ctxRead originalMark saved savedRead sourceState noError cmpFetched
    branch conditionOffset branchDecoded branchFetched sites trace memoryRun
  exact ⟨gprs,flags,vectors,trace,live,lr,stored,after,freed,fullRun,caller,facts⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryControlReturn
