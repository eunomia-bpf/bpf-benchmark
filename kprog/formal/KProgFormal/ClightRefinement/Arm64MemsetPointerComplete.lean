import KProgFormal.ClightRefinement.Arm64MemsetPointerState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetPointerComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

/-- The same original memset call, actual free and program return execute both
following pointer sites with their full current result and original trace. -/
theorem original {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {oldStorage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior nextState : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result oldStorage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins nextState nextK constantWritten constantAfter)
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
    (byteInputs : ∀ outerLe, Arm64MemsetReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe)
    (registerInputs : ∀ outerLe, Arm64MemsetClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe)
    (flagInputs : ∀ outerLe gprs, Arm64MemsetClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe gprs)
    (vectorInputs : ∀ outerLe gprs flags,
      Arm64MemsetClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe gprs flags)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ memsetAfter written pointerMiddle finalMem outerLe helperLe gprs flags values trace,
      ∃ prior : Arm64MemsetClobberVectorsComplete.Invariant view abi (Arm64MemsetLossSetup.byte mark)
          outerLe gprs flags 64 values memsetAfter helperLe,
      ∃ _effect : Arm64MemsetPointerContinuation.Effect prior.flagsPacket.registers.ready.storage pointerMiddle finalMem,
      ∃ _current : Arm64MemsetPointerState.Packet view abi (Arm64MemsetLossSetup.byte mark) gprs flags values finalMem,
      CC.Star (CC.Step2 world) (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond
          k (Arm64ProgramEntryAllocation.allocation initial).1 le constantAfter) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) ∧
      Arm64MemsetReturn.FreeResult constantAfter written memsetAfter ∧
      FrameBelow initial.nextblock constantAfter finalMem ∧
      finalMem.nextblock = (Arm64MemsetSource.allocation constantAfter).2.nextblock := by
  obtain ⟨memsetAfter,written,outerLe,helperLe,gprs,flags,values,trace,prior,procedure,freed,frame,nextBlock⟩ :=
    Arm64MemsetProgramCaller.original mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes
      byteInputs registerInputs flagInputs vectorInputs le k
  obtain ⟨pointerMiddle,finalMem,effect,current,pointers⟩ := Arm64MemsetPointerState.execute prior le k
  refine ⟨memsetAfter,written,pointerMiddle,finalMem,outerLe,helperLe,gprs,flags,values,trace,prior,effect,current,?_,
    freed,frame.trans effect.caller,effect.nextblock.trans nextBlock⟩
  simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans procedure pointers.sound

end KProgFormal.ClightRefinement.Arm64MemsetPointerComplete
