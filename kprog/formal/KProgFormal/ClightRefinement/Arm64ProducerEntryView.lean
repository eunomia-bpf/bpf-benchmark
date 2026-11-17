import KProgFormal.ClightRefinement.Arm64ProducerVectorLoop
import KProgFormal.ClightRefinement.Arm64LinkedNop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerEntryView

open Arm64Producer

private theorem load_live (chunk : CC.Chunk) (m : CC.Mem) (b : CC.Block)
    (ofs : Int) (value : CC.Val) (read : CC.Mem.load chunk m b ofs = some value) :
    b.toNat < m.nextblock.toNat := by
  unfold CC.Mem.load at read
  split at read
  · rename_i valid
    have range : CC.Mem.rangePerm m b ofs (ofs + CC.sizeChunk chunk) .Cur .Readable = true :=
      by
        simp only [CC.Mem.validAccess, Bool.and_eq_true] at valid
        exact valid.1
    have positive : (0 : Int) < CC.sizeChunk chunk := by cases chunk <;> decide
    exact CC.Mem.perm_valid_block m b ofs .Cur .Readable
      (CC.Mem.rangePerm_perm m b ofs (ofs + CC.sizeChunk chunk) .Cur .Readable range ofs
        (Int.le_refl _) (by omega))
  · simp at read

/-- Real C load success supplies the existing reader's frontier check. -/
theorem checked_load (chunk : CC.Chunk) (m : CC.Mem) (b : CC.Block)
    (ofs : CC.Integers.Ptrofs) (value : CC.Val)
    (read : CC.Mem.load chunk m b (CC.Integers.Ptrofs.unsigned ofs) = some value) :
    Arm64EntryMemory.load m.nextblock chunk m (.Vptr b ofs) = some value := by
  simp only [Arm64EntryMemory.load, ite_eq_left (load_live chunk m b _ value read)]
  exact read

private def consumerComposite : CC.Composite :=
  (Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)

private theorem consumer_layout :
    Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry = some consumerComposite ∧
    ∀ i : Fin 12, CC.fieldOffset Arm64EntryMemory.composites (headerField i)
      consumerComposite.co_members = .OK (8 * (i.val : Int), .Full) := by
  exact ⟨by decide +kernel, by decide +kernel⟩

private theorem header_address (b : CC.Block) (i : Fin 12) :
    Arm64EntryMemory.fieldAddress (.Vptr b 0) (headerField i) =
      some (.Vptr b (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) := by
  simp [Arm64EntryMemory.fieldAddress, consumer_layout.1, consumer_layout.2 i,
    CC.Val.offsetPtr, CC.Integers.Ptrofs.add, CC.Integers.MI.add]
  apply congrArg (CC.Val.Vptr b)
  exact BitVec.zero_add _

/-- Every actual scalar pointer-slot readback feeds the imported C-layout
field reader, with the caller frontier derived from successful memory access. -/
theorem header_field_readback (memory : CC.Mem) (entry : CC.Block) (i : Fin 12) (value : CC.Val)
    (read : CC.Mem.load CC.Mptr memory entry (8 * (i.val : Int)) = some value) :
    Arm64EntryMemory.field memory.nextblock CC.Mptr memory (.Vptr entry 0) (headerField i) = some value := by
  simp only [Arm64EntryMemory.field, header_address]
  apply checked_load
  simpa only [header_offsets i] using read

/-- The actual pointer-slot and pointee loads establish a borrowed read;
no successful-reader or frontier premise is supplied by the caller. -/
theorem header_borrowed_readback (memory : CC.Mem) (entry : CC.Block) (i : Fin 12)
    (chunk : CC.Chunk) (block : CC.Block) (ofs : CC.Integers.Ptrofs) (value : CC.Val)
    (pointer : CC.Mem.load CC.Mptr memory entry (8 * (i.val : Int)) = some (.Vptr block ofs))
    (read : CC.Mem.load chunk memory block (CC.Integers.Ptrofs.unsigned ofs) = some value) :
    Arm64EntryMemory.borrowed memory.nextblock chunk memory (.Vptr entry 0) (headerField i) = some value := by
  simp only [Arm64EntryMemory.borrowed, header_field_readback memory entry i _ pointer]
  exact checked_load chunk memory block ofs value read

/-- n/z/c/v are the last four of the twelve actual scalar pointer fields. -/
def flagIndex (i : Fin 4) : Fin 12 := ⟨8 + i.val, by have := i.isLt; omega⟩

/-- The consumer flag reader follows the real producer pointers and bytes. -/
theorem flags_readback (memory : CC.Mem) (entry : CC.Block) (cells : Fin 12 → CC.Block)
    (values : Fin 4 → CC.Val)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry (8 * (i.val : Int)) = some (.Vptr (cells i) 0))
    (bytes : ∀ i, CC.Mem.load .Mint8unsigned memory (cells (flagIndex i)) 0 = some (values i)) :
    Arm64EntryMemory.flags memory.nextblock memory (.Vptr entry 0) =
      some (values 0, values 1, values 2, values 3) := by
  have borrowed (i : Fin 4) := header_borrowed_readback memory entry (flagIndex i)
    .Mint8unsigned (cells (flagIndex i)) 0 (values i) (pointers _) (bytes i)
  have n : Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry 0)
      Arm64Program._n = some (values 0) := by exact borrowed 0
  have z : Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry 0)
      Arm64Program._z = some (values 1) := by exact borrowed 1
  have c : Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry 0)
      Arm64Program._c = some (values 2) := by exact borrowed 2
  have v : Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry 0)
      Arm64Program._v = some (values 3) := by exact borrowed 3
  unfold Arm64EntryMemory.flags
  rw [n, z, c, v]
  rfl

/-- Defined one-bit native flags, with the same unsigned C scalar view as the
existing concrete flag relation. Arbitrary input bytes need not satisfy it. -/
def flagValues (s : Reference.AArch64.State) (i : Fin 4) : CC.Val :=
  [.Vint ((read_flag .N s.machine).setWidth 32), .Vint ((read_flag .Z s.machine).setWidth 32),
   .Vint ((read_flag .C s.machine).setWidth 32), .Vint ((read_flag .V s.machine).setWidth 32)][i]

theorem header_flags_represent (memory : CC.Mem) (entry : CC.Block) (cells : Fin 12 → CC.Block)
    (s : Reference.AArch64.State)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry (8 * (i.val : Int)) = some (.Vptr (cells i) 0))
    (bytes : ∀ i, CC.Mem.load .Mint8unsigned memory (cells (flagIndex i)) 0 = some (flagValues s i)) :
    Arm64Nop.FlagsRepresent memory.nextblock memory (.Vptr entry 0) s := by
  exact flags_readback memory entry cells (flagValues s) pointers bytes

/-- The actual 638-transition header/loop execution establishes the native
flag relation from precise pre-header local readbacks. Provider outcomes and
the native starting flag values stay explicit, while all reader bounds and
pointer-field bindings are derived from the real reached memory. -/
theorem producer_flags_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (s : Reference.AArch64.State) (access : before.access = (allocation m).2.access)
    (flagsBefore : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (flagIndex i)) =
        some (block, headerSourceType (flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (flagValues s i)) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Nop.FlagsRepresent after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, _, _, after, finalLe, run, _, _, pointers, _, _, locals, frame, accessAfter, next⟩ :=
    header_initialized_before_consumer m before le k access
  refine ⟨entry, after, finalLe, run, ?_, frame, accessAfter, next⟩
  apply header_flags_represent after entry.block (fun i => (cells i).block) s pointers
  intro i
  have different : ∀ i : Fin 4, headerSourceName (flagIndex i) ≠ Arm64Entry._entry := by decide +kernel
  rw [locals _ _ _ (cells (flagIndex i)).binding (different i) .Mint8unsigned 0]
  exact flagsBefore i _ (cells (flagIndex i)).binding

end KProgFormal.ClightRefinement.Arm64ProducerEntryView
