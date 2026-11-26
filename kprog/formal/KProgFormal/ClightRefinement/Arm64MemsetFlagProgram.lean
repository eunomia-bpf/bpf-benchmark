import KProgFormal.ClightRefinement.Arm64MemsetFlagPointer

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetFlagProgram

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

/-- One actual program-call witness executes full memset, real return/free,
both following pointer calls and the original length MOV. The same
initialized flag and retained provider values reach the actual memcpy call. -/
theorem execute {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
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
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue constantAfter)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe)
    (flagInputs : ∀ outerLe gprs, Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe gprs)
    (vectorInputs : ∀ outerLe gprs flags,
      Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe gprs flags)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ memsetAfter written pointerMiddle pointerAfter lengthWritten finalMem : CC.Mem, ∃ gprs flags values trace,
      ∃ _current : Arm64MemsetPointerState.Packet view abi (Arm64MemsetLossSetup.byte mark)
        (Arm64MemcpyLengthState.words gprs) flags values finalMem,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
          (Arm64ProgramEntryAllocation.allocation initial).1 le constantAfter) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) ∧
      Arm64MemsetReturn.FreeResult constantAfter written memsetAfter ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue finalMem ∧
      FrameBelow initial.nextblock constantAfter finalMem ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ finalMem.nextblock.toNat := by
  have enter := Arm64MemsetProgramCaller.ready entry le constantAfter k
  obtain ⟨memsetAfter,written,outerLe,helperLe,gprs,flags,values,trace,packet,procedure,freed,frame,next⟩ :=
    Arm64MemsetFlagComplete.original mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes
      cell flagValue flag byteInputs registerInputs flagInputs vectorInputs (Arm64MemsetProgramCaller.callCont initial le k) rfl
  have returned := Arm64MemsetProgramCaller.returned initial le memsetAfter k
  obtain ⟨pointerMiddle,pointerAfter,effect,pointerPacket,pointers,pointerFlag⟩ := Arm64MemsetFlagPointer.execute packet le k
  have constantBound := Arm64MemsetInputs.bound_after second (Arm64MemsetInputs.bound_after first bound)
  have pointerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerAfter.nextblock.toNat := by
    rw [effect.nextblock,next]
    exact Nat.le_trans constantBound (FrameBelow.allocVariables (Arm64MemsetSource.allocated constantAfter)
      constantAfter.nextblock (Nat.le_refl _)).1
  obtain ⟨lengthWritten,finalMem,lengthResult,current,lengthRun⟩ := Arm64MemcpyLengthState.execute pointerPacket pointerBound le k
  have finalFlag := pointerFlag.tail_frame ⟨Arm64MemcpyLengthState.header lengthResult,Arm64MemcpyLengthState.tail lengthResult⟩
  refine ⟨memsetAfter,written,pointerMiddle,pointerAfter,lengthWritten,finalMem,gprs,flags,values,trace,current,?_,freed,
    finalFlag,(frame.trans effect.caller).trans lengthResult.caller,Arm64MemcpyLengthState.bound_after lengthResult pointerBound⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (star_trans (star_trans (star_trans enter.sound procedure) returned.sound) pointers.sound) lengthRun.sound

end KProgFormal.ClightRefinement.Arm64MemsetFlagProgram
