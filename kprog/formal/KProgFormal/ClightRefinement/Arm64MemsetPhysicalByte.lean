import KProgFormal.ClightRefinement.Arm64MemsetByteWrite
import KProgFormal.Reference.AArch64
import Arm.Memory.Access

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetPhysicalByte

/-- The real source bias is96 and its actual stack capacity is160. -/
def address (origin : BitVec 64) (i : Fin 160) : BitVec 64 :=
  origin + (BitVec.ofNat 64 i.val - 96#64)

theorem address_injective (origin : BitVec 64) : Function.Injective (address origin) := by
  intro i j same
  have words : BitVec.ofNat 64 i.val = BitVec.ofNat 64 j.val := by
    simpa only [address,BitVec.add_right_inj,BitVec.sub_left_inj] using same
  have numbers := congrArg BitVec.toNat words
  have ib : i.val < 2^64 := by have := i.isLt; omega
  have jb : j.val < 2^64 := by have := j.isLt; omega
  simp only [BitVec.toNat_ofNat,Nat.mod_eq_of_lt ib,Nat.mod_eq_of_lt jb] at numbers
  exact Fin.ext numbers

/-- A source byte is defined exactly when the mapped readable native byte is
initialized. Native contents outside initialized bytes remain arbitrary. -/
structure Represents (m : CC.Mem) (stack : CC.Block) (origin : BitVec 64)
    (profile : MemoryProfile) (native : ArmState) : Prop where
  profileRead : read_memory_profile native = some profile
  readable : ∀ i : Fin 160, profile.readable (address origin i) = CC.Mem.perm m stack (i.val : Int) .Cur .Readable
  writable : ∀ i : Fin 160, profile.writable (address origin i) = CC.Mem.perm m stack (i.val : Int) .Cur .Writable
  bytes : ∀ i : Fin 160, profile.readable (address origin i) = true →
    CC.Mem.load .Mint8unsigned m stack (i.val : Int) =
      some (if profile.initialized (address origin i) then .Vint ((read_mem (address origin i) native).setWidth 32) else .Vundef)

private theorem delta_one {a b : BitVec 64} (different : a ≠ b) : ¬ (a-b).toNat < 1 := by
  intro small
  have zero : a-b = 0#64 := BitVec.eq_of_toNat_eq (by change (a-b).toNat = 0; omega)
  apply different
  calc a = (a-b)+b := (BitVec.sub_add_cancel a b).symm
       _ = b := by rw [zero,BitVec.zero_add]

private theorem byte_normalized (value : BitVec 8) :
    CC.Val.loadResult .Mint8unsigned (.Vint (value.setWidth 32)) = .Vint (value.setWidth 32) := by
  change CC.Val.Vint (value.setWidth 32 &&& (255#32)) = _
  congr 1
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [← BitVec.setWidth_and,BitVec.and_allOnes]

/-- Consume the actual source Mint8 store and the mature native checked write.
All other byte observations, permissions and architectural fields survive;
only the actual destination initialization and ordered write event advance. -/
theorem store {m after : CC.Mem} {stack : CC.Block} {origin : BitVec 64}
    {profile : MemoryProfile} {native : ArmState}
    (represented : Represents m stack origin profile native) (i : Fin 160) (value : BitVec 8)
    (stored : CC.Mem.store .Mint8unsigned m stack (i.val : Int) (.Vint (value.setWidth 32)) = some after)
    (permitted : profile.writable (address origin i) = true) :
    ∃ nativeAfter profileAfter,
      MemoryMode.write .checked 1 (address origin i) value native = .ok nativeAfter ∧
      Represents after stack origin profileAfter nativeAfter ∧
      profileAfter.readable = profile.readable ∧ profileAfter.writable = profile.writable ∧
      profileAfter.initialized (address origin i) = true ∧
      (∀ j : Fin 160, j ≠ i → profileAfter.initialized (address origin j) = profile.initialized (address origin j)) ∧
      (∀ a : BitVec 64, a ≠ address origin i → read_mem a nativeAfter = read_mem a native) ∧
      read_memory_accesses nativeAfter = read_memory_accesses native ++ [.memory .write (address origin i) [value] true] ∧
      nativeAfter.program = native.program ∧ nativeAfter.exclusive = native.exclusive ∧
      nativeAfter.atomicAccesses = native.atomicAccesses ∧ nativeAfter.threadPointerInputs = native.threadPointerInputs ∧
      (∀ field : StateField, r field nativeAfter = r field native) := by
  let profileAfter : MemoryProfile := { profile with initialized := fun a =>
    if (a-address origin i).toNat < 1 then true else profile.initialized a }
  let nativeAfter := record_memory_access (.memory .write (address origin i) [value] true)
    (write_memory_profile (some profileAfter) (write_mem_bytes 1 (address origin i) value native))
  have executed : MemoryMode.write .checked 1 (address origin i) value native = .ok nativeAfter := by
    simp [MemoryMode.write,represented.profileRead,MemoryMode.permitted,permitted,profileAfter,nativeAfter]
  have byte_same : read_mem (address origin i) nativeAfter = value := by
    simp [nativeAfter,record_memory_access,write_memory_profile,write_mem_bytes,read_mem,write_mem,read_store,write_store]
  have byte_other (j : Fin 160) (other : j ≠ i) :
      read_mem (address origin j) nativeAfter = read_mem (address origin j) native := by
    have different : address origin j ≠ address origin i := fun same => other (address_injective origin same)
    simp [nativeAfter,record_memory_access,write_memory_profile,write_mem_bytes,read_mem,write_mem,read_store,write_store,different]
  have init_same : profileAfter.initialized (address origin i) = true := by simp [profileAfter]
  have init_other (j : Fin 160) (other : j ≠ i) :
      profileAfter.initialized (address origin j) = profile.initialized (address origin j) := by
    have different : address origin j ≠ address origin i := fun same => other (address_injective origin same)
    simp only [profileAfter,if_neg (delta_one different)]
  have relation : Represents after stack origin profileAfter nativeAfter := by
    refine ⟨?_,?_,?_,?_⟩
    · rfl
    · intro j; exact (represented.readable j).trans (CC.Mem.perm_store stored stack (j.val : Int) .Cur .Readable).symm
    · intro j; exact (represented.writable j).trans (CC.Mem.perm_store stored stack (j.val : Int) .Cur .Writable).symm
    · intro j readable
      by_cases same : j = i
      · subst j
        rw [init_same,if_pos rfl,byte_same]
        simpa only [byte_normalized] using CC.Mem.load_store_same stored
      · rw [init_other j same,byte_other j same]
        have other : CC.Mem.load .Mint8unsigned after stack (j.val : Int) = CC.Mem.load .Mint8unsigned m stack (j.val : Int) := by
          have distinct : (j.val : Int) ≠ (i.val : Int) := by
            intro equal
            exact same (Fin.ext (by omega))
          have disjoint : (j.val : Int)+1 ≤ (i.val : Int) ∨ (i.val : Int)+1 ≤ (j.val : Int) := by omega
          exact CC.Mem.load_store_other stored .Mint8unsigned stack (j.val : Int)
            (.inr (by simpa only [CC.sizeChunk] using disjoint))
        exact other.trans (represented.bytes j readable)
  refine ⟨nativeAfter,profileAfter,executed,relation,rfl,rfl,init_same,init_other,?_,?_,?_,?_,?_,?_,?_⟩
  · intro a different
    simp [nativeAfter,record_memory_access,write_memory_profile,write_mem_bytes,read_mem,write_mem,read_store,write_store,different]
  · rfl
  · rfl
  · rfl
  · rfl
  · rfl
  · intro field
    cases field <;> simp [nativeAfter,record_memory_access,write_memory_profile,write_mem_bytes,r,write_mem,read_base_gpr,read_base_sfp,read_base_pc,read_base_flag,read_base_error]

end KProgFormal.ClightRefinement.Arm64MemsetPhysicalByte
