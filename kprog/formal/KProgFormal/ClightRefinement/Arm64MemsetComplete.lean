import KProgFormal.ClightRefinement.Arm64MemsetFreeState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- The same original memset Callstate executes its actual read prefix,
data/tag loops, all clobbers, real helper return and eight-local free/return.
Every provider word and current retained resource belongs to that execution. -/
theorem original {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
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
    (byteInputs : ∀ outerLe, Arm64MemsetReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe)
    (registerInputs : ∀ outerLe, Arm64MemsetClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe)
    (flagInputs : ∀ outerLe gprs, Arm64MemsetClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe gprs)
    (vectorInputs : ∀ outerLe gprs flags,
      Arm64MemsetClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe gprs flags)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written outerLe helperLe gprs flags values trace,
      ∃ _current : Arm64MemsetClobberVectorsComplete.Invariant view abi (Arm64MemsetLossSetup.byte mark)
        outerLe gprs flags 64 values after helperLe,
      CC.Star (CC.Step2 world) (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter) trace
        (.Returnstate .Vundef k after) ∧
      Arm64MemsetReturn.FreeResult constantAfter written after ∧
      FrameBelow initial.nextblock constantAfter after ∧
      after.nextblock = (Arm64MemsetSource.allocation constantAfter).2.nextblock := by
  obtain ⟨middle,outerLe,packet,readAndWrite,_reads,frame,access,nextBlock,_outside⟩ :=
    Arm64MemsetTagTransferComplete.original mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes k
  obtain ⟨written,helperLe,gprs,flags,values,trace,current,clobber,clobberFrame,clobberAccess,clobberNext⟩ :=
    Arm64MemsetClobberReturn.original packet (byteInputs outerLe) (registerInputs outerLe)
      (flagInputs outerLe) (vectorInputs outerLe) constantAfter (Arm64MemsetSource.continuation k)
  have currentAccess := clobberAccess.trans access
  obtain ⟨after,freed,leave⟩ := Arm64MemsetReturn.exit constantAfter written outerLe k hk currentAccess
  have finalBound := Arm64MemsetInputs.bound_after second (Arm64MemsetInputs.bound_after first bound)
  let post := Arm64MemsetFreeState.complete constantAfter.nextblock finalBound freed.caller current
  have initialBound : initial.nextblock.toNat ≤ (allocation initial).2.nextblock.toNat :=
    (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
  have callerBound := Nat.le_trans initialBound finalBound
  have allocationFrame : FrameBelow initial.nextblock constantAfter (Arm64MemsetSource.allocation constantAfter).2 :=
    fun block owned => (Arm64MemsetSource.entry_frame constantAfter) block (Nat.lt_of_lt_of_le owned callerBound)
  have freeFrame : FrameBelow initial.nextblock written after :=
    fun block owned => freed.caller block (Nat.lt_of_lt_of_le owned callerBound)
  refine ⟨after,written,outerLe,helperLe,gprs,flags,values,trace,post,?_,freed,
    ((allocationFrame.trans frame).trans clobberFrame).trans freeFrame,
    freed.nextblock.trans (clobberNext.trans nextBlock)⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (star_trans readAndWrite clobber) leave.sound

end KProgFormal.ClightRefinement.Arm64MemsetComplete
