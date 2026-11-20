import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64RegisterStorageFrontier

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

/-- An owned address has the same observation at the supplied frontier and
at the memory frontier, including undefined values and refused loads. -/
theorem load_eq (memory : CC.Mem) (frontier block : CC.Block)
    (owned : block.toNat < frontier.toNat) (chunk : CC.Chunk) (offset : CC.Integers.Ptrofs) :
    Arm64EntryMemory.load frontier chunk memory (.Vptr block offset) =
      Arm64EntryMemory.load memory.nextblock chunk memory (.Vptr block offset) := by
  rw [Arm64RegisterWrite.checked_load_eq]
  simp only [Arm64EntryMemory.load, ite_eq_left owned]

/-- Field addressing retains the entry block; no successful field lookup or
raw load is assumed. Missing fields and bitfields retain their original result. -/
theorem field_eq (memory : CC.Mem) (frontier block : CC.Block)
    (owned : block.toNat < frontier.toNat) (offset : CC.Integers.Ptrofs)
    (chunk : CC.Chunk) (name : CC.Ident) :
    Arm64EntryMemory.field frontier chunk memory (.Vptr block offset) name =
      Arm64EntryMemory.field memory.nextblock chunk memory (.Vptr block offset) name := by
  unfold Arm64EntryMemory.field Arm64EntryMemory.fieldAddress
  generalize Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry = composite
  cases composite with
  | none => rfl
  | some composite =>
    simp only [bind, Option.bind_some]
    generalize CC.fieldOffset Arm64EntryMemory.composites name composite.co_members = result
    cases result with
    | Error _ => rfl
    | OK pair =>
      obtain ⟨ofs, bits⟩ := pair
      cases bits with
      | Bits _ _ _ _ => rfl
      | Full => exact load_eq memory frontier block owned chunk _

/-- Typed allocation bindings supply the bound for every canonical local. -/
theorem local_owned (initial : CC.Mem) (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block, ty)) :
    block.toNat < (allocation initial).2.nextblock.toNat :=
  ((allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).1 id (block, ty) binding).2.1

/-- A typed header slot and owned pointee also transport cache observations. -/
theorem borrowed_eq (memory : CC.Mem) (frontier block : CC.Block)
    (entryOwned : block.toNat < frontier.toNat) (i : Fin 12)
    (point : CC.Block) (offset : CC.Integers.Ptrofs)
    (pointOwned : point.toNat < frontier.toNat) (chunk : CC.Chunk)
    (pointer : CC.Mem.load CC.Mptr memory block (8 * (i.val : Int)) = some (.Vptr point offset)) :
    Arm64EntryMemory.borrowed frontier chunk memory (.Vptr block 0) (headerField i) =
      Arm64EntryMemory.borrowed memory.nextblock chunk memory (.Vptr block 0) (headerField i) := by
  simp only [Arm64EntryMemory.borrowed, field_eq memory frontier block entryOwned 0 CC.Mptr _,
    header_field_readback memory block i _ pointer, bind, Option.bind_some]
  exact load_eq memory frontier point pointOwned chunk offset

/-- Freeing a separate callee frame may lower permissions above the producer
frontier. The same producer Storage survives under exactly its owned frame. -/
def storage_frame {initial memory after : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier memory after) : Storage initial after entry := by
  have keep (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
      (binding : (allocation initial).1.get id = some (block, ty))
      (chunk : CC.Chunk) (offset : Int) :
      CC.Mem.load chunk after block offset = CC.Mem.load chunk memory block offset :=
    frame.load chunk block offset (Nat.lt_of_lt_of_le (local_owned initial id ty block binding) bound)
  refine { storage with
    roots := fun tags => (keep _ _ _ entry.binding CC.Mptr _).trans (storage.roots tags)
    slots := fun tags i => (keep _ _ _ (storage.tables tags).binding CC.Mptr _).trans (storage.slots tags i)
    writable := ?_
    spPointer := (keep _ _ _ entry.binding CC.Mptr _).trans storage.spPointer
    spRead := (keep _ _ _ storage.sp.binding .Mint64 _).trans storage.spRead
    flagPointers := fun i => (keep _ _ _ entry.binding CC.Mptr _).trans (storage.flagPointers i)
    vectorPointers := fun high i => (keep _ _ _ entry.binding CC.Mptr _).trans (storage.vectorPointers high i) }
  intro tags i
  have owned := Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables tags).cellBinding i)) bound
  exact (CC.Mem.validAccess_congr (m1 := after) (m2 := memory)
    (chunk := cellChunk tags) (b := (storage.tables tags).cellBlock i) (ofs := 0) (p := .Writable)
    (fun offset => by simp only [CC.Mem.perm, (frame _ owned).2])).trans (storage.writable tags i)

private theorem slot_unsigned : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      8 * (i.val : Int) := by decide +kernel

/-- Canonical table and cell ownership fixes every traversed address, without
assuming that either final cell load succeeds. -/
theorem gpr_eq {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat) (i : Fin 31) :
    Arm64EntryMemory.gpr frontier memory (.Vptr entry.block 0) i.val =
      Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val := by
  have entryOwned := Nat.lt_of_lt_of_le entry.owned bound
  have wordField := (field_eq memory frontier entry.block entryOwned 0 CC.Mptr Arm64Program._cells).trans
    (header_field_readback memory entry.block 0 _ (storage.roots false))
  have tagField := (field_eq memory frontier entry.block entryOwned 0 CC.Mptr Arm64Program._tag_cells).trans
    (header_field_readback memory entry.block 1 _ (storage.roots true))
  have slot (tags : Bool) : Arm64EntryMemory.load frontier CC.Mptr memory
      (.Vptr (storage.tables tags).tableBlock (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) =
      some (.Vptr ((storage.tables tags).cellBlock i) 0) := by
    rw [load_eq memory frontier _ (Nat.lt_of_lt_of_le (local_owned initial _ _ _ (storage.tables tags).binding) bound)]
    apply checked_load
    simpa only [slot_unsigned i] using storage.slots tags i
  rw [Arm64RegisterWrite.storage_gpr storage i]
  simp only [Arm64EntryMemory.gpr, wordField, tagField, bind, Option.bind_some]
  change (do
    let cell ← Arm64EntryMemory.load frontier CC.Mptr memory
      (.Vptr (storage.tables false).tableBlock (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))))
    let tag ← Arm64EntryMemory.load frontier CC.Mptr memory
      (.Vptr (storage.tables true).tableBlock (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))))
    let word ← Arm64EntryMemory.load frontier .Mint64 memory cell
    let kind ← Arm64EntryMemory.load frontier .Mint8unsigned memory tag
    pure (word, kind)) = _
  have offset : CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      CC.Integers.Ptrofs.repr (8 * (i.val : Int)) := BitVec.zero_add _
  simp only [offset, slot, bind, pure, Option.bind_some,
    load_eq memory frontier _ (Nat.lt_of_lt_of_le
      (local_owned initial _ _ _ ((storage.tables false).cellBinding i)) bound),
    load_eq memory frontier _ (Nat.lt_of_lt_of_le
      (local_owned initial _ _ _ ((storage.tables true).cellBinding i)) bound),
    Arm64RegisterWrite.checked_load_eq]
  rfl

/-- Follow the existing SP pointer at either frontier with the same raw load. -/
theorem sp_eq {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat) :
    Arm64EntryMemory.borrowed frontier .Mint64 memory (.Vptr entry.block 0) Arm64Program._sp =
      Arm64EntryMemory.borrowed memory.nextblock .Mint64 memory (.Vptr entry.block 0) Arm64Program._sp := by
  have pointer : Arm64EntryMemory.field memory.nextblock CC.Mptr memory (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vptr storage.sp.block 0) :=
    header_field_readback memory entry.block 5 _ storage.spPointer
  simp only [Arm64EntryMemory.borrowed,
    field_eq memory frontier entry.block (Nat.lt_of_lt_of_le entry.owned bound) 0 CC.Mptr _,
    pointer, bind, Option.bind_some]
  exact load_eq memory frontier storage.sp.block (Nat.lt_of_lt_of_le storage.sp.owned bound) .Mint64 0

theorem flag_eq {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat) (i : Fin 4) :
    Arm64EntryMemory.borrowed frontier .Mint8unsigned memory (.Vptr entry.block 0) (headerField (flagIndex i)) =
      Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry.block 0) (headerField (flagIndex i)) := by
  have pointer := header_field_readback memory entry.block (flagIndex i) _ (storage.flagPointers i)
  simp only [Arm64EntryMemory.borrowed,
    field_eq memory frontier entry.block (Nat.lt_of_lt_of_le entry.owned bound) 0 CC.Mptr _,
    pointer, bind, Option.bind_some]
  exact load_eq memory frontier (storage.flags i).block
    (Nat.lt_of_lt_of_le (storage.flags i).owned bound) .Mint8unsigned 0

theorem flags_eq {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat) :
    Arm64EntryMemory.flags frontier memory (.Vptr entry.block 0) =
      Arm64EntryMemory.flags memory.nextblock memory (.Vptr entry.block 0) := by
  have n := flag_eq storage frontier bound 0
  have z := flag_eq storage frontier bound 1
  have c := flag_eq storage frontier bound 2
  have v := flag_eq storage frontier bound 3
  change Arm64EntryMemory.borrowed frontier .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._n =
    Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._n at n
  change Arm64EntryMemory.borrowed frontier .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._z =
    Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._z at z
  change Arm64EntryMemory.borrowed frontier .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._c =
    Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._c at c
  change Arm64EntryMemory.borrowed frontier .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._v =
    Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry.block 0) Arm64Program._v at v
  simp only [Arm64EntryMemory.flags, n, z, c, v]

/-- Both embedded pointer arrays and their canonical vector local stay below
the supplied frontier, including either raw word's unsuccessful observations. -/
theorem vector_eq {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat) (j : Fin 32) :
    Arm64EntryMemory.vector frontier memory (.Vptr entry.block 0) j =
      Arm64EntryMemory.vector memory.nextblock memory (.Vptr entry.block 0) j := by
  have loAddress : Arm64EntryMemory.fieldAddress (.Vptr entry.block 0) Arm64Program._vector_lo =
      some (.Vptr entry.block (CC.Integers.Ptrofs.repr 96)) :=
    Arm64ProducerVectorView.array_address entry.block false
  have hiAddress : Arm64EntryMemory.fieldAddress (.Vptr entry.block 0) Arm64Program._vector_hi =
      some (.Vptr entry.block (CC.Integers.Ptrofs.repr 352)) :=
    Arm64ProducerVectorView.array_address entry.block true
  have slot (high : Bool) : Arm64EntryMemory.load frontier CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr (if high then 352 else 96)))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val))) =
      some (.Vptr storage.vectors.block (vectorLoopSourceOffset high j)) :=
    (load_eq memory frontier entry.block (Nat.lt_of_lt_of_le entry.owned bound) CC.Mptr _).trans
      (Arm64ProducerVectorView.slot_readback memory entry.block high j _ (storage.vectorPointers high j))
  have loSlot := slot false
  have hiSlot := slot true
  change Arm64EntryMemory.load frontier CC.Mptr memory
    (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 96))
      (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val))) =
    some (.Vptr storage.vectors.block (vectorLoopSourceOffset false j)) at loSlot
  change Arm64EntryMemory.load frontier CC.Mptr memory
    (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 352))
      (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val))) =
    some (.Vptr storage.vectors.block (vectorLoopSourceOffset true j)) at hiSlot
  rw [Arm64RegisterWrite.storage_vector storage j]
  simp only [Arm64EntryMemory.vector, loAddress, hiAddress, bind, Option.bind_some]
  change (do
    let loPointer ← Arm64EntryMemory.load frontier CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 96))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val)))
    let hiPointer ← Arm64EntryMemory.load frontier CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 352))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val)))
    let lo ← Arm64EntryMemory.load frontier .Mint64 memory loPointer
    let hi ← Arm64EntryMemory.load frontier .Mint64 memory hiPointer
    pure (lo, hi)) = _
  simp only [loSlot, hiSlot, bind, pure, Option.bind_some,
    load_eq memory frontier storage.vectors.block
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ storage.vectors.binding) bound),
    Arm64RegisterWrite.checked_load_eq]

/-- The complete architectural register relation can change its proof-side
frontier using actual allocation ownership, with the same memory and state. -/
theorem represents_iff {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) :
    Arm64Registers.Represents addresses origins (fun r => r.val) frontier memory (.Vptr entry.block 0) s ↔
      Arm64Registers.Represents addresses origins (fun r => r.val) memory.nextblock memory (.Vptr entry.block 0) s := by
  constructor <;> intro rep
  all_goals
    refine ⟨?_, ?_, ?_, ?_⟩
    · simpa only [gpr_eq storage frontier bound] using rep.gpr
    · simpa only [sp_eq storage frontier bound] using rep.sp
    · simpa only [vector_eq storage frontier bound] using rep.vectors
    · simpa only [Arm64Nop.FlagsRepresent, flags_eq storage frontier bound] using rep.flags

end KProgFormal.ClightRefinement.Arm64RegisterStorageFrontier
