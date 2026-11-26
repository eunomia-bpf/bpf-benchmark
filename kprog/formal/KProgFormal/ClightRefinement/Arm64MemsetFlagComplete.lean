import KProgFormal.ClightRefinement.Arm64MemsetFlagClobber

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetFlagComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- One actual original memset call retains its initialized flag across the
real read/data/tag execution, all helper providers/stores, helper return and
eight-local free. The same current provider maps and trace survive. -/
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
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue constantAfter)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe)
    (flagInputs : ∀ outerLe gprs, Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe gprs)
    (vectorInputs : ∀ outerLe gprs flags,
      Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell flagValue outerLe gprs flags)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written, ∃ outerLe helperLe : CC.TempEnv, ∃ gprs flags values trace,
      ∃ _current : Arm64ClobberResult.Packet view abi (Arm64MemsetLossSetup.byte mark)
        (-32#64) 0 gprs flags values cell flagValue after,
      CC.Star (CC.Step2 world) (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter) trace
        (.Returnstate .Vundef k after) ∧
      Arm64MemsetReturn.FreeResult constantAfter written after ∧
      FrameBelow initial.nextblock constantAfter after ∧
      after.nextblock = (Arm64MemsetSource.allocation constantAfter).2.nextblock := by
  obtain ⟨middle,outerLe,packet,readAndWrite,_reads,frame,access,nextBlock,outside⟩ :=
    Arm64MemsetTagTransferComplete.original mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes k
  have finalBound := Arm64MemsetInputs.bound_after second (Arm64MemsetInputs.bound_after first bound)
  have allocatedFlag := flag.frame constantAfter.nextblock finalBound (Arm64MemsetSource.entry_frame constantAfter)
  have separated := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have currentFlag : Arm64MemcpyReadCurrent.Flag entry cell flagValue middle := ⟨
    (outside CC.Mptr entry.block 696
      (separated _ _ _ _ entry.binding view.tags.binding (by decide +kernel))
      (separated _ _ _ _ entry.binding view.stack.binding (by decide +kernel))).trans allocatedFlag.header,
    (outside .Mint8unsigned cell.block 0
      (separated _ _ _ _ cell.binding view.tags.binding (by decide +kernel))
      (separated _ _ _ _ cell.binding view.stack.binding (by decide +kernel))).trans allocatedFlag.byte⟩
  obtain ⟨written,helperLe,gprs,flags,values,trace,current,clobber,clobberFrame,clobberAccess,clobberNext⟩ :=
    Arm64MemsetFlagClobber.execute packet currentFlag access (byteInputs outerLe) (registerInputs outerLe)
      (flagInputs outerLe) (vectorInputs outerLe) (Arm64MemsetSource.continuation k)
  obtain ⟨after,freed,leave⟩ := Arm64MemsetReturn.exit constantAfter written outerLe k hk (clobberAccess.trans access)
  let post := Arm64ClobberResult.retained constantAfter.nextblock finalBound freed.caller
    (Arm64ClobberResult.of_complete current)
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

end KProgFormal.ClightRefinement.Arm64MemsetFlagComplete
