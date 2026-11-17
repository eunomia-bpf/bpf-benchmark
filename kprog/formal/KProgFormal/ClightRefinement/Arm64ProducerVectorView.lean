import KProgFormal.ClightRefinement.Arm64ProducerGprView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerVectorView

open Arm64Producer
open Arm64ProducerEntryView

private def arrayField (high : Bool) : CC.Ident :=
  if high then Arm64Program._vector_hi else Arm64Program._vector_lo

private def consumerComposite : CC.Composite :=
  (Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)

private theorem array_layout :
    Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry = some consumerComposite ∧
    ∀ high : Bool, CC.fieldOffset Arm64EntryMemory.composites (arrayField high)
      consumerComposite.co_members = .OK ((if high then 352 else 96), .Full) := by
  exact ⟨by decide +kernel, by decide +kernel⟩

private theorem array_address (entry : CC.Block) (high : Bool) :
    Arm64EntryMemory.fieldAddress (.Vptr entry 0) (arrayField high) =
      some (.Vptr entry (CC.Integers.Ptrofs.repr (if high then 352 else 96))) := by
  simp [Arm64EntryMemory.fieldAddress, array_layout.1, array_layout.2 high,
    CC.Val.offsetPtr, CC.Integers.Ptrofs.add, CC.Integers.MI.add]
  apply congrArg (CC.Val.Vptr entry)
  exact BitVec.zero_add _

private theorem slot_offsets : ∀ high : Bool, ∀ i : Fin 32,
    CC.Integers.Ptrofs.add (CC.Integers.Ptrofs.repr (if high then 352 else 96))
      (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) = vectorLoopHeaderOffset high i := by
  decide +kernel

private theorem slot_readback (memory : CC.Mem) (entry : CC.Block) (high : Bool)
    (i : Fin 32) (value : CC.Val)
    (read : CC.Mem.load CC.Mptr memory entry ((if high then 352 else 96) + 8 * (i.val : Int)) = some value) :
    Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry (CC.Integers.Ptrofs.repr (if high then 352 else 96)))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * i.val))) =
      some value := by
  change Arm64EntryMemory.load memory.nextblock CC.Mptr memory
    (.Vptr entry (CC.Integers.Ptrofs.add (CC.Integers.Ptrofs.repr (if high then 352 else 96))
      (CC.Integers.Ptrofs.repr (8 * (i.val : Int))))) = some value
  rw [slot_offsets high i]
  apply checked_load
  simpa only [(vector_loop_offsets high i).1] using read

/-- The existing embedded-array reader follows actual pointer slots and both
pointee loads. Values and independently supplied pointer offsets are retained;
every traversed block bound follows from successful imported memory access. -/
theorem vector_readback (memory : CC.Mem) (entry lowBlock highBlock : CC.Block)
    (i : Fin 32) (lowOfs highOfs : CC.Integers.Ptrofs) (low high : CC.Val)
    (lowPointer : CC.Mem.load CC.Mptr memory entry (96 + 8 * (i.val : Int)) = some (.Vptr lowBlock lowOfs))
    (highPointer : CC.Mem.load CC.Mptr memory entry (352 + 8 * (i.val : Int)) = some (.Vptr highBlock highOfs))
    (lowRead : CC.Mem.load .Mint64 memory lowBlock (CC.Integers.Ptrofs.unsigned lowOfs) = some low)
    (highRead : CC.Mem.load .Mint64 memory highBlock (CC.Integers.Ptrofs.unsigned highOfs) = some high) :
    Arm64EntryMemory.vector memory.nextblock memory (.Vptr entry 0) i = some (low, high) := by
  simp only [Arm64EntryMemory.vector, bind, pure, Option.bind_eq_some_iff]
  refine ⟨.Vptr entry (CC.Integers.Ptrofs.repr 96), array_address entry false,
    .Vptr entry (CC.Integers.Ptrofs.repr 352), array_address entry true,
    .Vptr lowBlock lowOfs, ?_, .Vptr highBlock highOfs, ?_,
    low, checked_load .Mint64 memory lowBlock lowOfs low lowRead,
    high, checked_load .Mint64 memory highBlock highOfs high highRead, rfl⟩
  · exact slot_readback memory entry false i _ lowPointer
  · exact slot_readback memory entry true i _ highPointer

/-- Actual VectorLocal storage and the two initialized pointer arrays expose
all32 pairs. Low/high data are kept separately, without a fabricated decoder. -/
theorem vector_readbacks (m memory : CC.Mem) (entry : HeaderLocal m) (vectors : VectorLocal m)
    (values : Bool → Fin 32 → CC.Val)
    (pointers : ∀ high i, CC.Mem.load CC.Mptr memory entry.block
      ((if high then 352 else 96) + 8 * (i.val : Int)) =
      some (.Vptr vectors.block (vectorLoopSourceOffset high i)))
    (data : ∀ high i, CC.Mem.load .Mint64 memory vectors.block
      (16 * (i.val : Int) + (if high then 8 else 0)) = some (values high i)) :
    ∀ i, Arm64EntryMemory.vector memory.nextblock memory (.Vptr entry.block 0) i =
      some (values false i, values true i) := by
  intro i
  apply vector_readback memory entry.block vectors.block vectors.block i
    (vectorLoopSourceOffset false i) (vectorLoopSourceOffset true i)
    (values false i) (values true i) (pointers false i) (pointers true i)
  · simpa only [(vector_loop_offsets false i).2] using data false i
  · simpa only [(vector_loop_offsets true i).2] using data true i

/-- The native vector relation's actual low/high64 views. -/
def vectorHalf (s : Reference.AArch64.State) (high : Bool) (i : Fin 32) : BitVec 64 :=
  if high then ((Reference.AArch64.readVector s i) >>> 64).setWidth 64
  else (Reference.AArch64.readVector s i).setWidth 64

/-- The real 638-transition producer header/loop establishes all native vector
readbacks from precise pre-header data at its actual vector-array binding.
Provider input correspondence remains explicit, with caller framing retained. -/
theorem producer_vectors_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (s : Reference.AArch64.State) (access : before.access = (allocation m).2.access)
    (vectorsBefore : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 before block
        (16 * (i.val : Int) + (if high then 8 else 0)) = some (.Vlong (vectorHalf s high i))) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 32, Arm64EntryMemory.vector after.nextblock after (.Vptr entry.block 0) i =
        some (.Vlong ((Reference.AArch64.readVector s i).setWidth 64),
          .Vlong (((Reference.AArch64.readVector s i) >>> 64).setWidth 64))) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, _, _, vectors, after, finalLe, run, _, _, _, pointers, _, locals, frame, accessAfter, next⟩ :=
    header_initialized_before_consumer m before le k access
  refine ⟨entry, after, finalLe, run, ?_, frame, accessAfter, next⟩
  apply vector_readbacks m after entry vectors (fun high i => .Vlong (vectorHalf s high i)) pointers
  intro high i
  have different : Arm64Entry.___a64_vectors ≠ Arm64Entry._entry := by decide +kernel
  rw [locals _ _ _ vectors.binding different .Mint64 (16 * (i.val : Int) + (if high then 8 else 0))]
  exact vectorsBefore vectors.block vectors.binding high i

end KProgFormal.ClightRefinement.Arm64ProducerVectorView
