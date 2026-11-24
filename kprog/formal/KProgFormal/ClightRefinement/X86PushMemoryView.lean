import KProgFormal.ClightRefinement.X86PushNativeBytes

namespace KProgFormal.ClightRefinement.X86PushMemoryView

/-- Projection of the existing external memory/profile, without a second
memory interpreter or any change to the reference ISA. -/
def view (memory : X86.Mem) (profile : X86.MemoryProfile) : Reference.Memory :=
  ⟨memory.read,profile.readable,profile.writable,profile.initialized⟩

private theorem ranges : ∀ byte : Fin 48,
    (byte.val < 40 → ¬ (BitVec.ofInt 64 ((byte.val : Int) - 40)).toNat < 8) ∧
    (¬ byte.val < 40 → (BitVec.ofInt 64 ((byte.val : Int) - 40)).toNat = byte.val - 40) := by decide +kernel

/-- The original external qword-store bytes agree with the common native
memory update at every actual cache coordinate. -/
theorem values (memory : X86.Mem) (profile : X86.MemoryProfile) (origin value : BitVec 64) (byte : Fin 48) :
    (memory.writeSize .q (origin - 8) value).read (X86StackCacheView.address origin byte) =
      (Reference.storeMemory (view memory profile) (origin - 8) value 8).value (X86StackCacheView.address origin byte) := by
  calc
    _ = (if byte.val < 40 then memory.read (X86StackCacheView.address origin byte)
      else (value >>> (8 * (byte.val - 40))).setWidth 8) := X86PushNativeBytes.table memory origin value byte
    _ = _ := by
      simp only [Reference.storeMemory,X86StackCacheView.displacement,view]
      by_cases lower : byte.val < 40
      · simp only [if_pos lower,if_neg ((ranges byte).1 lower)]
      · have inside : byte.val - 40 < 8 := by have bound := byte.isLt; omega
        simp only [(ranges byte).2 lower,if_neg lower,if_pos inside]

/-- Actual source byte observations represent the actual external qword
memory after its real write. Initialized-byte/profile transport uses the
same shared native-memory update and keeps arbitrary uninitialized values. -/
theorem represented (source after : CC.Mem) (block : CC.Block) (memory : X86.Mem) (profile : X86.MemoryProfile)
    (origin value : BitVec 64)
    (initial : X86StackCacheView.Represents source block (view memory profile) origin)
    (table : ∀ byte : Fin 48, CC.Mem.load .Mint8unsigned after block byte.val =
      if byte.val < 40 then CC.Mem.load .Mint8unsigned source block byte.val
      else some (.Vint (((value >>> (8 * (byte.val - 40))).setWidth 8).setWidth 32))) :
    X86StackCacheView.Represents after block
      (view (memory.writeSize .q (origin - 8) value) {profile with initialized := fun address =>
        if (address - (origin - 8)).toNat < 8 then true else profile.initialized address}) origin := by
  intro byte initialized
  have sameInitialized : (Reference.storeMemory (view memory profile) (origin - 8) value 8).initialized
      (X86StackCacheView.address origin byte) = true := initialized
  have source := X86StackCacheView.store source after block (view memory profile) origin value initial table byte sameInitialized
  change CC.Mem.load .Mint8unsigned after block byte.val = some (.Vint
    (((memory.writeSize .q (origin - 8) value).read (X86StackCacheView.address origin byte)).setWidth 32))
  rw [values memory profile origin value byte]
  exact source

end KProgFormal.ClightRefinement.X86PushMemoryView
