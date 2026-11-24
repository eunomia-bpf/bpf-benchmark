import KProgFormal.ClightRefinement.Arm64MemsetAbiRead
import KProgFormal.ClightRefinement.Arm64ProducerTailFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetAbiOriginal

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- The actual temporary environment after the tag4 arm selection. -/
def beforeTemps (entry table cell : CC.Block) (mark : BitVec 32) : CC.TempEnv :=
  Arm64MemsetArmSelect.temps (Arm64MemsetTagRead.finalTemps (Arm64MemsetStackSetup.temps
    (Arm64MemsetLoop.initializedTemps entry (mark.setWidth 64) (16#64)) 0) table cell (4#8))

private theorem entry_get (entry table cell : CC.Block) (mark : BitVec 32) :
    (beforeTemps entry table cell mark).get Arm64Program._entry = some (.Vptr entry 0) := by
  simp +decide only [beforeTemps,Arm64MemsetArmSelect.temps,Arm64MemsetTagRead.finalTemps,
    Arm64MemsetTagRead.temps,CC.PTree.gso]
  rw [(Arm64MemsetStackSetup.selection _ 0).1]
  simp +decide only [Arm64MemsetLoop.initializedTemps,Arm64MemsetSource.readTemps,
    Arm64MemsetSource.byteTemps,Arm64MemsetSource.initialTemps,CC.PTree.gso,CC.PTree.gss]

private theorem tag_get (entry table cell : CC.Block) (mark : BitVec 32) :
    (beforeTemps entry table cell mark).get Arm64Program.___a64_mwr_tag = some (.Vint ((4#8).setWidth 32)) := by
  simp +decide only [beforeTemps,Arm64MemsetArmSelect.temps,CC.PTree.gso,
    Arm64MemsetTagRead.finalTemps,CC.PTree.gss]

/-- The same reached producer observations pass the real eight-local
allocation and all original read/setup/tag/ABI branches into the stack body.
The observations are supplied by the initialized fourteen-call prefix. -/
theorem original {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {raw : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {prior next : Reference.AArch64.State}
    {priorK nextK : CC.Cont} (mark : BitVec 32)
    (pointer : Arm64PointerWrite.Result storage 0 raw (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : Arm64MovImmediate.OrdinaryCall.Result pointer.storage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (abi : Arm64Producer.TailLocal initial 6)
    (header : CC.Mem.load CC.Mptr constantAfter entry.block 704 = some (.Vptr abi.block 0))
    (value : CC.Mem.load .Mint8unsigned constantAfter abi.block 0 = some (.Vint 2))
    (tags : ∀ (tagsLocal : Arm64Producer.StackTagLocal initial) (i : Fin 24),
      CC.Mem.load .Mint8unsigned constantAfter tagsLocal.block (i.val : Int) = some (.Vint 0))
    (k : CC.Cont) :
    ∃ current : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry,
      InternalRun world 298 (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter)
        (.State handler Arm64Program.s_kprog_arm64_program_memset_104
          (Arm64MemsetTagRead.continuation
            (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
          (Arm64MemsetSource.allocation constantAfter).1
          (Arm64MemsetAbiRead.temps
            (beforeTemps entry.block (current.tables true).tableBlock ((current.tables true).cellBlock 0) mark)
            abi.block (2#8))
          (Arm64MemsetSource.allocation constantAfter).2) ∧
      Arm64EntryMemory.gpr constantAfter.nextblock (Arm64MemsetSource.allocation constantAfter).2
        (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint ((4#8).setWidth 32)) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 40 = some (.Vptr storage.sp.block 0) ∧
      CC.Mem.load .Mint64 (Arm64MemsetSource.allocation constantAfter).2 storage.sp.block 0 = some (.Vlong storage.spValue) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0) ∧
      CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2) ∧
      ∀ (tagsLocal : Arm64Producer.StackTagLocal initial) (i : Fin 24),
        CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 tagsLocal.block (i.val : Int) = some (.Vint 0) := by
  obtain ⟨current,run,r0,spPointer,spValue⟩ := Arm64MemsetArmSelect.original mark pointer bound first second k
  have finalBound := Arm64MemsetInputs.bound_after second (Arm64MemsetInputs.bound_after first bound)
  have frame := Arm64ProducerTailFrame.of_frame entry constantAfter.nextblock finalBound
    (Arm64MemsetSource.entry_frame constantAfter)
  have abiObserved := frame.abi abi header value
  have finalTags (tagsLocal : Arm64Producer.StackTagLocal initial) (i : Fin 24) :=
    (frame.tail 2 ⟨tagsLocal.block,tagsLocal.binding⟩ .Mint8unsigned (i.val : Int)).trans (tags tagsLocal i)
  have abiRun := Arm64MemsetAbiRead.execute (Arm64MemsetSource.allocation constantAfter).1
    (beforeTemps entry.block (current.tables true).tableBlock ((current.tables true).cellBlock 0) mark)
    (Arm64MemsetSource.allocation constantAfter).2
    (Arm64MemsetTagRead.continuation
      (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
    entry.block abi.block (2#8) (entry_get _ _ _ _) (tag_get _ _ _ _) abiObserved.1 abiObserved.2
  exact ⟨current,run.trans abiRun,r0,spPointer,spValue,abiObserved.1,abiObserved.2,finalTags⟩

end KProgFormal.ClightRefinement.Arm64MemsetAbiOriginal
