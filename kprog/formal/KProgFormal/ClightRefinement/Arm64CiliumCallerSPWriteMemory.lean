import KProgFormal.ClightRefinement.Arm64CiliumCallerResourceView
import KProgFormal.ClightRefinement.Arm64CiliumCallerSPPreindex

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriteMemory
open Arm64CiliumCallerLink (allocation)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)

private theorem scalar_source :
    (Arm64CiliumCallerHeaderSource.declaration 5).sourceName =
      Arm64CiliumCallerEntryScalars.name 0 := by decide +kernel
private theorem scalar_field :
    (Arm64CiliumCallerHeaderSource.declaration 5).field = Arm64Program._sp := by decide +kernel

/-- The actual header SP source and actual scalar local are the same allocated cell. -/
theorem sp_cell {m : CC.Mem} (sources : Sources m) (scalars : Locals m) :
    sources.block 5 = scalars.block 0 := by
  have binding := scalars.binding 0
  rw [← scalar_source] at binding
  exact congrArg Prod.fst (Option.some.inj ((sources.binding 5).symm.trans binding))

private theorem header_separate {m : CC.Mem} (header : Header m) (scalars : Locals m) :
    header.block ≠ scalars.block 0 := by
  have different : Arm64CiliumCallerUnit.___a64_entry ≠ Arm64CiliumCallerEntryScalars.name 0 := by
    decide +kernel
  exact (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ header.binding (scalars.binding 0) different

/-- The retained original header pointer reaches precisely that actual SP scalar cell. -/
theorem header_pointer {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12) :
    CC.Mem.load .Mint64 before header.block 40 = some (.Vptr (scalars.block 0) 0) := by
  have pointer := pointers 5 (by decide)
  rw [sp_cell sources scalars] at pointer
  exact pointer

structure Store {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 before (scalars.block 0) 0
    (.Vlong Arm64CiliumCallerSPPreindex.delta) = some after
  read : CC.Mem.load .Mint64 after (scalars.block 0) 0 = some (.Vlong Arm64CiliumCallerSPPreindex.delta)
  pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources after 12
  otherBlocks : ∀ b,b ≠ scalars.block 0 → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o
  caller : FrameBelow m.nextblock before after
  access : after.access = before.access
  frontier : after.nextblock = before.nextblock

/-- Construct the original signed64 SP write from actual current allocation rights. -/
theorem write {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12) :
    Nonempty (Store (before := before) header sources scalars) := by
  have valid : CC.Mem.validAccess before .Mint64 (scalars.block 0) 0 .Writable = true :=
    Arm64CiliumCallerEntryScalars.writable scalars 0 access
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 before (scalars.block 0) 0
      (.Vlong Arm64CiliumCallerSPPreindex.delta) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have read : CC.Mem.load .Mint64 after (scalars.block 0) 0 =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := CC.Mem.load_store_same stored
  have fresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (scalars.binding 0)).1
  refine ⟨⟨after,stored,read,?_,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩
  intro i below
  exact (CC.Mem.load_store_other stored .Mint64 header.block _
    (.inl (header_separate header scalars))).trans (pointers i below)

/-- The same real store supplies the generic borrowed SP readback, preserving the actual header. -/
theorem borrowed_after {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (result : Store (before := before) header sources scalars) :
    Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
      Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  have binding := scalars.binding 0
  rw [← scalar_source] at binding
  have read := Arm64CiliumCallerResourceView.source_readback header sources 5 .Mint64
    (.Vlong Arm64CiliumCallerSPPreindex.delta) binding result.pointers result.read
  rw [scalar_field] at read
  exact read

end KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriteMemory
