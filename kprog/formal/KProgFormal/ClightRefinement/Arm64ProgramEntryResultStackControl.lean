import KProgFormal.ClightRefinement.Arm64ProgramEntryCompleteControl
import KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackRights

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackControl
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryComplete (sourceTemps sourceResult)

/-- Consume the original prefix's actual Reached and pointer/MOV witnesses.
The SAME derived view/resources/SP/ABI/tag bytes supply the actual source
helpers and native-control return, retaining the original caller and trace. -/
theorem compose {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont}
    (fields : Fin 3 → BitVec 32) (native : Reference.AArch64.State)
    (pointer : Arm64PointerWrite.Result storage 0 (-32#64) (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : Arm64MovImmediate.OrdinaryCall.Result pointer.storage 1 ((fields 0).setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (abi : Arm64Producer.TailLocal initial 6)
    (reached : Arm64ProgramEntryResultStackRights.Reached storage abi)
    (cell : Arm64Producer.TailLocal initial 5) (ready : CC.Mem)
    (readyPacket : Arm64MemsetHeaderView.Ready initial ready entry)
    (retained : Arm64ProducerTailFrame.Frame initial entry ready constantAfter)
    (providers : Arm64ProgramEntryMemoryPacket.Providers
      (Arm64ProgramEntryMemoryPacket.prepare pointer bound first second reached.view reached.resources reached.spAtBase abi reached.abiHeader reached.abiKind reached.tagBytes).view
      abi (fields 0) constantAfter cell)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (ctxRead : (Arm64ProgramEntryBody.setupTemps le fields).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr (Arm64ProgramEntryBody.contextOffset i)))) = some (.Vint (fields i)))
    (prefixTrace : CC.Trace)
    (prefixRun : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) prefixTrace
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
        (allocation initial).1 (sourceTemps le fields native) constantAfter))
    (prefixCaller : FrameBelow initial.nextblock initial constantAfter) (sourceState : Reference.AArch64.State)
    (noError : read_err sourceState.machine = .None)
    (cmpFetched : fetch_inst (read_pc sourceState.machine) sourceState.machine = some Arm64ProgramEntryCmpNative.instruction.encoding)
    (branch : Reference.AArch64.Instruction) (conditionOffset : BitVec 19)
    (branchDecoded : branch.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) conditionOffset)))
    (branchFetched : fetch_inst (read_pc sourceState.machine + 4#64) sourceState.machine = some branch.encoding)
    (sites : Arm64ProgramEntryPostMemoryBranchSites.Sites sourceState conditionOffset) :
    ∃ gprs flags vectors trace live, ∃ lr : HeaderSourceLocal initial 4, ∃ stored after,
      Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) trace
        (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord (sourceResult fields native) (fields 0)
          sourceState gprs flags vectors (Arm64MemsetLossSetup.byte (fields 0)))) k after) ∧
      FrameBelow initial.nextblock initial after ∧
      Arm64ProgramEntrySourceReturnNative.Facts (Arm64ProgramEntryPostMemoryCmpView.native sourceState gprs flags)
        conditionOffset (Arm64ProgramEntryPostMemoryBranchSites.chosenOffset sourceState gprs flags conditionOffset sites)
        (Arm64ProgramEntryPostMemoryBranchSites.admission sourceState gprs flags conditionOffset sites)
        live (.Vptr entry.block 0) lr.block := by
  exact Arm64ProgramEntryCompleteControl.compose fields native pointer bound first second
    reached.view reached.resources reached.spAtBase abi reached.abiHeader reached.abiKind reached.tagBytes
    cell ready readyPacket retained providers le k hk ctxBlock ctxOffset old ctxRead reads prefixTrace prefixRun prefixCaller
    sourceState noError cmpFetched branch conditionOffset branchDecoded branchFetched sites

end KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackControl
