import KProgFormal.ClightRefinement.Arm64MemsetMemcpyProgram
import KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackPrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryCalls

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

/-- The actual initialized packet and its proved original prefix tail frame
derive the is_xdp0 input on that same reached heap. Compose both complete
memory calls with the supplied actual native/source prefix witness, retaining
its real trace, ordinary-MOV Results, copied bytes and caller frame. -/
theorem compose {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {oldStorage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result oldStorage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
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
    (prefixCaller : FrameBelow initial.nextblock initial constantAfter) :
    ∃ after written copyBefore gprs flags values trace,
      ∃ _current : Arm64ClobberResult.Packet view abi (Arm64MemsetLossSetup.byte mark) (-16#64) 16
        gprs flags values cell (0#8) after,
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult copyBefore written after ∧
      FrameBelow initial.nextblock initial after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨actualCell,pointer,zero⟩ := readyPacket.isXdp
  have same : actualCell.block = cell.block :=
    congrArg Prod.fst (Option.some.inj (actualCell.binding.symm.trans cell.binding))
  have initialized : Arm64MemcpyReadCurrent.Flag entry cell (0#8) ready := by
    refine ⟨?_,?_⟩
    · simpa only [same] using pointer
    · have normalized : CC.Val.Vint ((0#8).setWidth 32) = CC.Val.Vint 0 := by decide +kernel
      change CC.Mem.load .Mint8unsigned ready cell.block 0 = some (.Vint ((0#8).setWidth 32))
      rw [normalized]
      simpa only [same] using zero
  have flag := initialized.tail_frame retained
  obtain ⟨after,written,copyBefore,gprs,flags,values,trace,current,run,freed,frame,finalBound⟩ :=
    Arm64MemsetMemcpyProgram.execute mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes
      cell (0#8) flag byteInputs registerInputs flagInputs vectorInputs
      copyByteInputs copyRegisterInputs copyFlagInputs copyVectorInputs le k
  exact ⟨after,written,copyBefore,gprs,flags,values,CC.Eapp prefixTrace trace,current,
    star_trans prefixRun run,freed,prefixCaller.trans frame,finalBound⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryCalls
