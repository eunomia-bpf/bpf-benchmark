import KProgFormal.ClightRefinement.X86LogicFlagOrder

namespace KProgFormal.ClightRefinement.X86LogicFlagMemory
open X86LogicFlagOrder

abbrev Address := CC.Block × CC.Integers.Ptrofs

def flag (bit : Bool) : CC.Val := .Vint (if bit then 1 else 0)

/-- Byte separation permits every flag to inhabit the same allocation,
provided its actual byte address differs from the others. -/
structure Distinct (places : Locations) : Prop where
  cf_zf : places.cf ≠ places.zf
  cf_sf : places.cf ≠ places.sf
  cf_overflow : places.cf ≠ places.overflow
  cf_pf : places.cf ≠ places.pf
  zf_sf : places.zf ≠ places.sf
  zf_overflow : places.zf ≠ places.overflow
  zf_pf : places.zf ≠ places.pf
  sf_overflow : places.sf ≠ places.overflow
  sf_pf : places.sf ≠ places.pf
  overflow_pf : places.overflow ≠ places.pf

/-- A byte store preserves every distinct byte address, including a different
offset of the same block. This follows from actual unsigned pointer offsets. -/
theorem byte_store_other {m after : CC.Mem} (written read : Address) (byte : CC.Val)
    (stored : CC.Mem.store .Mint8unsigned m written.1 (CC.Integers.Ptrofs.unsigned written.2)
      byte = some after) (distinct : read ≠ written) :
    CC.Mem.load .Mint8unsigned after read.1 (CC.Integers.Ptrofs.unsigned read.2) =
      CC.Mem.load .Mint8unsigned m read.1 (CC.Integers.Ptrofs.unsigned read.2) := by
  by_cases blocks : read.1 = written.1
  · have offsets : read.2 ≠ written.2 := by
      intro equal
      exact distinct (Prod.ext blocks equal)
    have unequal : CC.Integers.Ptrofs.unsigned read.2 ≠ CC.Integers.Ptrofs.unsigned written.2 := by
      intro equal
      apply offsets
      apply BitVec.eq_of_toNat_eq
      change (read.2.toNat : Int) = (written.2.toNat : Int) at equal
      omega
    have ranges : CC.Integers.Ptrofs.unsigned read.2 + 1 ≤ CC.Integers.Ptrofs.unsigned written.2 ∨
        CC.Integers.Ptrofs.unsigned written.2 + 1 ≤ CC.Integers.Ptrofs.unsigned read.2 := by
      rcases Int.lt_or_gt_of_ne unequal with lower | higher
      · exact .inl (Int.add_one_le_of_lt lower)
      · exact .inr (Int.add_one_le_of_lt higher)
    exact CC.Mem.load_store_other stored .Mint8unsigned read.1
      (CC.Integers.Ptrofs.unsigned read.2) (.inr ranges)
  · exact CC.Mem.load_store_other stored .Mint8unsigned read.1
      (CC.Integers.Ptrofs.unsigned read.2) (.inl blocks)

private theorem read_flag {m after : CC.Mem} (address : Address) (bit : Bool)
    (stored : CC.Mem.store .Mint8unsigned m address.1 (CC.Integers.Ptrofs.unsigned address.2)
      (flag bit) = some after) :
    CC.Mem.load .Mint8unsigned after address.1 (CC.Integers.Ptrofs.unsigned address.2) =
      some (flag bit) := by
  have loaded := CC.Mem.load_store_same stored
  have normalized : CC.Val.loadResult .Mint8unsigned (flag bit) = flag bit := by cases bit <;> rfl
  exact loaded.trans (congrArg some normalized)

/-- The five flag bytes represented in the actual source binding ABI. -/
structure FlagsRepresent (m : CC.Mem) (places : Locations) (flags : X86.Flags) : Prop where
  cf : CC.Mem.load .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2) =
    some (flag flags.cf)
  zf : CC.Mem.load .Mint8unsigned m places.zf.1 (CC.Integers.Ptrofs.unsigned places.zf.2) =
    some (flag flags.zf)
  sf : CC.Mem.load .Mint8unsigned m places.sf.1 (CC.Integers.Ptrofs.unsigned places.sf.2) =
    some (flag flags.sf)
  overflow : CC.Mem.load .Mint8unsigned m places.overflow.1 (CC.Integers.Ptrofs.unsigned places.overflow.2) =
    some (flag flags.of)
  pf : CC.Mem.load .Mint8unsigned m places.pf.1 (CC.Integers.Ptrofs.unsigned places.pf.2) =
    some (flag flags.pf)

/-- All five ordered byte stores yield the represented native flag values.
Every earlier byte readback is preserved through the later real stores;
flags may share an allocation at distinct byte offsets. -/
theorem stores (m cfHeap zfHeap sfHeap ofHeap after : CC.Mem)
    (places : Locations) (flags : X86.Flags) (different : Distinct places)
    (cfStored : CC.Mem.store .Mint8unsigned m places.cf.1
      (CC.Integers.Ptrofs.unsigned places.cf.2) (flag flags.cf) = some cfHeap)
    (zfStored : CC.Mem.store .Mint8unsigned cfHeap places.zf.1
      (CC.Integers.Ptrofs.unsigned places.zf.2) (flag flags.zf) = some zfHeap)
    (sfStored : CC.Mem.store .Mint8unsigned zfHeap places.sf.1
      (CC.Integers.Ptrofs.unsigned places.sf.2) (flag flags.sf) = some sfHeap)
    (overflowStored : CC.Mem.store .Mint8unsigned sfHeap places.overflow.1
      (CC.Integers.Ptrofs.unsigned places.overflow.2) (flag flags.of) = some ofHeap)
    (pfStored : CC.Mem.store .Mint8unsigned ofHeap places.pf.1
      (CC.Integers.Ptrofs.unsigned places.pf.2) (flag flags.pf) = some after)
    : FlagsRepresent after places flags := by
  have cfRead0 := read_flag places.cf flags.cf cfStored
  have cfRead1 := (byte_store_other places.zf places.cf (flag flags.zf)
    zfStored different.cf_zf).trans cfRead0
  have cfRead2 := (byte_store_other places.sf places.cf (flag flags.sf)
    sfStored different.cf_sf).trans cfRead1
  have cfRead3 := (byte_store_other places.overflow places.cf (flag flags.of)
    overflowStored different.cf_overflow).trans cfRead2
  have cfRead4 := (byte_store_other places.pf places.cf (flag flags.pf)
    pfStored different.cf_pf).trans cfRead3
  have zfRead0 := read_flag places.zf flags.zf zfStored
  have zfRead1 := (byte_store_other places.sf places.zf (flag flags.sf)
    sfStored different.zf_sf).trans zfRead0
  have zfRead2 := (byte_store_other places.overflow places.zf (flag flags.of)
    overflowStored different.zf_overflow).trans zfRead1
  have zfRead3 := (byte_store_other places.pf places.zf (flag flags.pf)
    pfStored different.zf_pf).trans zfRead2
  have sfRead0 := read_flag places.sf flags.sf sfStored
  have sfRead1 := (byte_store_other places.overflow places.sf (flag flags.of)
    overflowStored different.sf_overflow).trans sfRead0
  have sfRead2 := (byte_store_other places.pf places.sf (flag flags.pf)
    pfStored different.sf_pf).trans sfRead1
  have overflowRead0 := read_flag places.overflow flags.of overflowStored
  have overflowRead1 := (byte_store_other places.pf places.overflow (flag flags.pf)
    pfStored different.overflow_pf).trans overflowRead0
  have pfRead0 := read_flag places.pf flags.pf pfStored
  exact ⟨cfRead4, zfRead3, sfRead2, overflowRead1, pfRead0⟩

end KProgFormal.ClightRefinement.X86LogicFlagMemory
