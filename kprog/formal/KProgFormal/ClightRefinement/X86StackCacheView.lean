import KProgFormal.ClightRefinement.X86ProducerPushCacheBytes

namespace KProgFormal.ClightRefinement.X86StackCacheView

/-- Representation coordinates of the actual48-byte source stack cache.
Instruction semantics remain in the shared reference and external ISA. -/
def address (origin : BitVec 64) (byte : Fin 48) : BitVec 64 :=
  origin - 48 + BitVec.ofNat 64 byte.val

/-- Initialized native bytes have actual typed source observations.
Uninitialized bytes retain arbitrary native values and are never fabricated
as source zeros. Establishing this initial relation is a platform obligation. -/
def Represents (source : CC.Mem) (block : CC.Block) (native : Reference.Memory) (origin : BitVec 64) : Prop :=
  ∀ byte : Fin 48, native.initialized (address origin byte) = true →
    CC.Mem.load .Mint8unsigned source block byte.val = some (.Vint ((native.value (address origin byte)).setWidth 32))

theorem displacement (origin : BitVec 64) (byte : Fin 48) :
    address origin byte - (origin - 8) = BitVec.ofInt 64 ((byte.val : Int) - 40) := by
  apply BitVec.eq_of_toNat_eq
  simp only [address,BitVec.toNat_sub,BitVec.toNat_add,BitVec.toNat_ofNat,BitVec.toNat_ofInt]
  simp only [show (48 : BitVec 64).toNat = 48 from rfl,show (8 : BitVec 64).toNat = 8 from rfl] at *
  have a := origin.isLt
  have b := byte.isLt
  omega

private theorem ranges : ∀ byte : Fin 48,
    (byte.val < 40 → ¬ (BitVec.ofInt 64 ((byte.val : Int) - 40)).toNat < 8) ∧
    (¬ byte.val < 40 → (BitVec.ofInt 64 ((byte.val : Int) - 40)).toNat = byte.val - 40) := by decide +kernel

/-- The existing shared native scalar store and actual source byte image
preserve the cache representation. Native permissions/canonicality/faults
are not inferred from the source's private-cache access. -/
theorem store (source after : CC.Mem) (block : CC.Block) (native : Reference.Memory) (origin value : BitVec 64)
    (represented : Represents source block native origin)
    (table : ∀ byte : Fin 48, CC.Mem.load .Mint8unsigned after block byte.val =
      if byte.val < 40 then CC.Mem.load .Mint8unsigned source block byte.val
      else some (.Vint (((value >>> (8 * (byte.val - 40))).setWidth 8).setWidth 32))) :
    Represents after block (Reference.storeMemory native (origin - 8) value 8) origin := by
  intro byte initialized
  have offset := displacement origin byte
  by_cases lower : byte.val < 40
  · have outside := (ranges byte).1 lower
    simp only [Reference.storeMemory,offset,if_neg outside] at initialized ⊢
    rw [table byte,if_pos lower]
    exact represented byte initialized
  · have inside : (BitVec.ofInt 64 ((byte.val : Int) - 40)).toNat < 8 := by
      rw [(ranges byte).2 lower]
      have bound := byte.isLt
      omega
    simp only [Reference.storeMemory,offset,if_pos inside,(ranges byte).2 lower]
    have bound : byte.val - 40 < 8 := by have bound := byte.isLt; omega
    simpa only [if_neg lower,if_pos bound] using table byte

end KProgFormal.ClightRefinement.X86StackCacheView
