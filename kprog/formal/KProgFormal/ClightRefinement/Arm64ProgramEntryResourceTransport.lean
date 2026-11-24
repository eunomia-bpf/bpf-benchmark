import KProgFormal.ClightRefinement.Arm64MemsetHeaderView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryResourceTransport

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

private def composite : CC.Composite :=
  (Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout : Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry = some composite := by decide +kernel

/-- The real field-address algorithm only loads the same header block; the
source header frame therefore transports every field observation. -/
theorem field {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (frame : Arm64ProducerTailFrame.Frame initial entry before after)
    (frontier : CC.Block) (chunk : CC.Chunk) (name : CC.Ident) :
    Arm64EntryMemory.field frontier chunk after (.Vptr entry.block 0) name =
      Arm64EntryMemory.field frontier chunk before (.Vptr entry.block 0) name := by
  simp only [Arm64EntryMemory.field,Arm64EntryMemory.fieldAddress,layout]
  change ((match CC.fieldOffset Arm64EntryMemory.composites name composite.co_members with
    | .OK (delta,.Full) => some (CC.Val.offsetPtr (.Vptr entry.block 0) (CC.Integers.Ptrofs.repr delta))
    | _ => none).bind (fun address => Arm64EntryMemory.load frontier chunk after address)) =
    ((match CC.fieldOffset Arm64EntryMemory.composites name composite.co_members with
    | .OK (delta,.Full) => some (CC.Val.offsetPtr (.Vptr entry.block 0) (CC.Integers.Ptrofs.repr delta))
    | _ => none).bind (fun address => Arm64EntryMemory.load frontier chunk before address))
  cases offset : CC.fieldOffset Arm64EntryMemory.composites name composite.co_members with
  | Error msg => rfl
  | OK pair =>
    rcases pair with ⟨delta,bf⟩
    cases bf with
    | Bits sz sg pos width => rfl
    | Full =>
      simp only [offset,Option.bind_some,CC.Val.offsetPtr,Arm64EntryMemory.load]
      split
      · exact frame.header chunk _
      · rfl

/-- Actual producer-block access and header frames transport ALL original
freeable locals and both borrowed-cache resources at the same current heap.
An advancing current frontier adds no equality assumption on entire heaps. -/
theorem resources {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (prior : Arm64ProgramEntryResources.Resources initial before entry)
    (header : Arm64ProducerTailFrame.Frame initial entry before after)
    (access : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block after.access = CC.PMap.get block before.access) :
    Arm64ProgramEntryResources.Resources initial after entry := by
  refine ⟨?_,?_⟩
  · intro id value binding
    have owned := ((allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64ProgramEntryAllocation.allocation initial)).symm)).1 id value binding).2.1
    have canonical : value.1.toNat < (allocation initial).2.nextblock.toNat := by
      simpa only [(Arm64ProgramEntryAllocation.allocation_corresponds initial).1] using owned
    exact (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
      (fun ofs => by simp only [CC.Mem.perm,access value.1 canonical])).trans (prior.freeable id value binding)
  · intro returns
    obtain ⟨cache⟩ := prior.caches returns
    have baseOwned : cache.baseBlock.toNat < (allocation initial).2.nextblock.toNat := by
      simpa only [(Arm64ProgramEntryAllocation.allocation_corresponds initial).1] using cache.baseOwned
    have validOwned : cache.validBlock.toNat < (allocation initial).2.nextblock.toNat := by
      simpa only [(Arm64ProgramEntryAllocation.allocation_corresponds initial).1] using cache.validOwned
    exact ⟨{cache with
      validHeader := (field header _ _ _).trans cache.validHeader
      baseHeader := (field header _ _ _).trans cache.baseHeader
      baseWritable := (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
        (fun ofs => by simp only [CC.Mem.perm,access cache.baseBlock baseOwned])).trans cache.baseWritable
      validWritable := (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
        (fun ofs => by simp only [CC.Mem.perm,access cache.validBlock validOwned])).trans cache.validWritable}⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryResourceTransport
