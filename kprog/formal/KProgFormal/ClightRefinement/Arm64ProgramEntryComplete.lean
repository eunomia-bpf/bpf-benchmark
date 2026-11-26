import KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryReturn
import KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryPacket

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryComplete
open Arm64ProgramEntryAllocation (world allocation)

def sourceTemps (le : CC.TempEnv) (fields : Fin 3 → BitVec 32) (native : Reference.AArch64.State) : CC.TempEnv :=
  Arm64ProgramEntryOrdinaryMoves.markTemps (Arm64ProgramEntryResultStackPrefix.resultTemps le fields native) (fields 0)

def sourceResult (fields : Fin 3 → BitVec 32) (native : Reference.AArch64.State) : BitVec 64 :=
  Arm64ProgramEntryResultCondition.result (Arm64ProgramEntryResultCondition.nativeResult native) (fields 1) native

/-- Read the actual result constructed by the original vector/read/condition
prefix and retained by the actual ordinary-MOV caller environment. -/
theorem result_readback (le : CC.TempEnv) (fields : Fin 3 → BitVec 32) (native : Reference.AArch64.State) :
    (sourceTemps le fields native).get Arm64ProgramFixture._result = some (.Vlong (sourceResult fields native)) := by
  simp only [sourceTemps,Arm64ProgramEntryOrdinaryMoves.markTemps,Arm64ProgramEntryResultStackPrefix.resultTemps,
    Arm64ProgramEntryResultCondition.resultTemps,sourceResult]
  rw [CC.PTree.gso _ _ _ _ (by decide +kernel),CC.PTree.gss]

/-- The SAME source updates retain the actual parameter of the original
setup environment, through all real temporary assignments. -/
theorem ctx_readback (le : CC.TempEnv) (fields : Fin 3 → BitVec 32) (native : Reference.AArch64.State) :
    (sourceTemps le fields native).get Arm64ProgramFixture._ctx =
      (Arm64ProgramEntryBody.setupTemps le fields).get Arm64ProgramFixture._ctx := by
  simp only [sourceTemps,Arm64ProgramEntryOrdinaryMoves.markTemps,Arm64ProgramEntryResultStackPrefix.resultTemps,
    Arm64ProgramEntryResultCondition.resultTemps,Arm64ProgramEntryResultCondition.conditionTemps,
    Arm64ProgramEntryResultCondition.priorityTemps,Arm64ProgramEntryResultVector.temps,Arm64ProgramEntryResultRead.readTemps,
    Arm64ProgramEntryMovCall.priorityTemps,Arm64ProgramEntryMovCall.markTemps]
  repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

/-- Complete the original source from its actual ResultStackPrefix-shaped
temporary environment and SAME pointer/MOV call witnesses. The true helper
allocation packet and final ctx/result observations are derived. Current
pre-pointer rights remain explicit for the continuing prefix-rights migration. -/
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
    (view : Arm64MemsetHeaderView.View initial before entry)
    (resources : Arm64ProgramEntryResources.Resources initial before entry)
    (spAtBase : storage.spValue = (-32#64)) (abi : Arm64Producer.TailLocal initial 6)
    (abiHeader : CC.Mem.load CC.Mptr before entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned before abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before view.tags.block (j.val : Int) = some (.Vint 0))
    (cell : Arm64Producer.TailLocal initial 5) (ready : CC.Mem)
    (readyPacket : Arm64MemsetHeaderView.Ready initial ready entry)
    (retained : Arm64ProducerTailFrame.Frame initial entry ready constantAfter)
    (providers : Arm64ProgramEntryMemoryPacket.Providers
      (Arm64ProgramEntryMemoryPacket.prepare pointer bound first second view resources spAtBase abi abiHeader abiKind tagBytes).view
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
    (prefixCaller : FrameBelow initial.nextblock initial constantAfter) (s : Reference.AArch64.State) :
    ∃ gprs flags vectors stored after trace,
      Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) trace
        (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord (sourceResult fields native) (fields 0)
          s gprs flags vectors (Arm64MemsetLossSetup.byte (fields 0)))) k after) ∧
      FrameBelow initial.nextblock initial after := by
  let prepared := Arm64ProgramEntryMemoryPacket.prepare pointer bound first second view resources spAtBase abi abiHeader abiKind tagBytes
  exact Arm64ProgramEntryMemoryReturn.compose (fields 0) first bound second prepared.view abi prepared.resources prepared.storage
    prepared.spAtBase prepared.r0 prepared.abiHeader prepared.abiKind prepared.tagBytes cell ready readyPacket retained
    providers.bytes providers.registers providers.flags providers.vectors providers.copyBytes providers.copyRegisters providers.copyFlags providers.copyVectors
    (sourceTemps le fields native) k (.Vptr ctxBlock ctxOffset) prefixTrace prefixRun prefixCaller hk ctxBlock ctxOffset rfl old
    ((ctx_readback le fields native).trans ctxRead) (reads 0) (sourceResult fields native) (result_readback le fields native) s

end KProgFormal.ClightRefinement.Arm64ProgramEntryComplete
