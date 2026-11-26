import KProgFormal.ClightRefinement.Arm64MemsetFlagProgram

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetMemcpyProgram

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

/-- One original program execution composes actual memset, following pointer
calls and MOV, then actual memcpy. Both helpers consume their own real
provider outcomes once; the same initialized is_xdp byte and current heaps
thread through both actual eight-local entries, frees and caller returns. -/
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
    (copyByteInputs : ∀ copyBefore outerLe,
      Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell flagValue outerLe)
    (copyRegisterInputs : ∀ copyBefore outerLe,
      Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell flagValue outerLe)
    (copyFlagInputs : ∀ copyBefore outerLe gprs,
      Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell flagValue outerLe gprs)
    (copyVectorInputs : ∀ copyBefore outerLe gprs flags,
      Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell flagValue outerLe gprs flags)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after written copyBefore gprs flags values trace,
      ∃ _current : Arm64ClobberResult.Packet view abi (Arm64MemsetLossSetup.byte mark) (-16#64) 16
        gprs flags values cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
          (Arm64ProgramEntryAllocation.allocation initial).1 le constantAfter) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult copyBefore written after ∧
      FrameBelow initial.nextblock constantAfter after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨_memsetAfter,_memsetWritten,_pointerMiddle,_pointerAfter,_lengthWritten,copyBefore,
      priorGprs,priorFlags,priorVectors,firstTrace,packet,headRun,_freed,copyFlag,firstFrame,copyBound⟩ :=
    Arm64MemsetFlagProgram.execute mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes
      cell flagValue flag byteInputs registerInputs flagInputs vectorInputs le k
  obtain ⟨after,written,gprs,flags,values,secondTrace,current,copyRun,freed,secondFrame,finalBound⟩ :=
    Arm64MemcpyCompleteProgram.execute packet copyBound le k addresses cell flagValue copyFlag
      (copyByteInputs copyBefore) (copyRegisterInputs copyBefore) (copyFlagInputs copyBefore) (copyVectorInputs copyBefore)
  exact ⟨after,written,copyBefore,gprs,flags,values,CC.Eapp firstTrace secondTrace,current,
    star_trans headRun copyRun,freed,firstFrame.trans secondFrame,finalBound⟩

end KProgFormal.ClightRefinement.Arm64MemsetMemcpyProgram
