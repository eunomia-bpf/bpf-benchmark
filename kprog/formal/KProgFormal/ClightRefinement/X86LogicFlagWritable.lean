import KProgFormal.ClightRefinement.X86LogicFlagMemory

namespace KProgFormal.ClightRefinement.X86LogicFlagWritable
open X86LogicFlagOrder X86LogicFlagMemory

/-- Initial source permissions for the five actual flag-byte locations. -/
structure Writable (memory : CC.Mem) (places : Locations) : Prop where
  cf : CC.Mem.validAccess memory .Mint8unsigned places.cf.1
    (CC.Integers.Ptrofs.unsigned places.cf.2) .Writable = true
  zf : CC.Mem.validAccess memory .Mint8unsigned places.zf.1
    (CC.Integers.Ptrofs.unsigned places.zf.2) .Writable = true
  sf : CC.Mem.validAccess memory .Mint8unsigned places.sf.1
    (CC.Integers.Ptrofs.unsigned places.sf.2) .Writable = true
  overflow : CC.Mem.validAccess memory .Mint8unsigned places.overflow.1
    (CC.Integers.Ptrofs.unsigned places.overflow.2) .Writable = true
  pf : CC.Mem.validAccess memory .Mint8unsigned places.pf.1
    (CC.Integers.Ptrofs.unsigned places.pf.2) .Writable = true

/-- Actual allocation/caller framing carries the initial writable locations. -/
theorem frame {frontier : CC.Block} {before after : CC.Mem}
    (kept : FrameBelow frontier before after) (places : Locations)
    (old : places.cf.1.toNat < frontier.toNat ∧ places.zf.1.toNat < frontier.toNat ∧
      places.sf.1.toNat < frontier.toNat ∧ places.overflow.1.toNat < frontier.toNat ∧
      places.pf.1.toNat < frontier.toNat)
    (permissions : Writable before places) : Writable after places := by
  have access (address : Address) (bound : address.1.toNat < frontier.toNat) :
      CC.Mem.validAccess after .Mint8unsigned address.1 (CC.Integers.Ptrofs.unsigned address.2)
        .Writable =
      CC.Mem.validAccess before .Mint8unsigned address.1 (CC.Integers.Ptrofs.unsigned address.2)
        .Writable := CC.Mem.validAccess_congr
          (fun _ => by simp only [CC.Mem.perm, (kept address.1 bound).2])
  exact ⟨(access _ old.1).trans permissions.cf, (access _ old.2.1).trans permissions.zf,
    (access _ old.2.2.1).trans permissions.sf, (access _ old.2.2.2.1).trans permissions.overflow,
    (access _ old.2.2.2.2).trans permissions.pf⟩

/-- A real byte store preserves all initial flag permissions. -/
theorem Writable.store {before after : CC.Mem} {places : Locations}
    (permissions : Writable before places) (address : Address) (value : CC.Val)
    (stored : CC.Mem.store .Mint8unsigned before address.1
      (CC.Integers.Ptrofs.unsigned address.2) value = some after) : Writable after places := by
  exact ⟨(CC.Mem.validAccess_store_eq stored .Mint8unsigned places.cf.1
      (CC.Integers.Ptrofs.unsigned places.cf.2) .Writable).trans permissions.cf,
    (CC.Mem.validAccess_store_eq stored .Mint8unsigned places.zf.1
      (CC.Integers.Ptrofs.unsigned places.zf.2) .Writable).trans permissions.zf,
    (CC.Mem.validAccess_store_eq stored .Mint8unsigned places.sf.1
      (CC.Integers.Ptrofs.unsigned places.sf.2) .Writable).trans permissions.sf,
    (CC.Mem.validAccess_store_eq stored .Mint8unsigned places.overflow.1
      (CC.Integers.Ptrofs.unsigned places.overflow.2) .Writable).trans permissions.overflow,
    (CC.Mem.validAccess_store_eq stored .Mint8unsigned places.pf.1
      (CC.Integers.Ptrofs.unsigned places.pf.2) .Writable).trans permissions.pf⟩

private theorem store_exists (memory : CC.Mem) (address : Address) (value : CC.Val)
    (writable : CC.Mem.validAccess memory .Mint8unsigned address.1
      (CC.Integers.Ptrofs.unsigned address.2) .Writable = true) :
    ∃ after, CC.Mem.store .Mint8unsigned memory address.1
      (CC.Integers.Ptrofs.unsigned address.2) value = some after := by
  simp only [CC.Mem.store, writable, ite_true]
  exact ⟨_, rfl⟩

/-- Initial permissions construct the complete original five-store chain.
Every intermediate heap is produced by the preceding actual store. -/
theorem stores (memory : CC.Mem) (places : Locations) (permissions : Writable memory places)
    (cfByte zfByte sfByte ofByte pfByte : CC.Val) :
    ∃ cfHeap zfHeap sfHeap ofHeap after,
      CC.Mem.store .Mint8unsigned memory places.cf.1
        (CC.Integers.Ptrofs.unsigned places.cf.2) cfByte = some cfHeap ∧
      CC.Mem.store .Mint8unsigned cfHeap places.zf.1
        (CC.Integers.Ptrofs.unsigned places.zf.2) zfByte = some zfHeap ∧
      CC.Mem.store .Mint8unsigned zfHeap places.sf.1
        (CC.Integers.Ptrofs.unsigned places.sf.2) sfByte = some sfHeap ∧
      CC.Mem.store .Mint8unsigned sfHeap places.overflow.1
        (CC.Integers.Ptrofs.unsigned places.overflow.2) ofByte = some ofHeap ∧
      CC.Mem.store .Mint8unsigned ofHeap places.pf.1
        (CC.Integers.Ptrofs.unsigned places.pf.2) pfByte = some after := by
  obtain ⟨cfHeap, cfStored⟩ := store_exists memory places.cf cfByte permissions.cf
  have cfPermissions := permissions.store places.cf cfByte cfStored
  obtain ⟨zfHeap, zfStored⟩ := store_exists cfHeap places.zf zfByte cfPermissions.zf
  have zfPermissions := cfPermissions.store places.zf zfByte zfStored
  obtain ⟨sfHeap, sfStored⟩ := store_exists zfHeap places.sf sfByte zfPermissions.sf
  have sfPermissions := zfPermissions.store places.sf sfByte sfStored
  obtain ⟨ofHeap, overflowStored⟩ := store_exists sfHeap places.overflow ofByte sfPermissions.overflow
  have overflowPermissions := sfPermissions.store places.overflow ofByte overflowStored
  obtain ⟨after, pfStored⟩ := store_exists ofHeap places.pf pfByte overflowPermissions.pf
  exact ⟨cfHeap, zfHeap, sfHeap, ofHeap, after, cfStored, zfStored, sfStored, overflowStored, pfStored⟩

end KProgFormal.ClightRefinement.X86LogicFlagWritable
