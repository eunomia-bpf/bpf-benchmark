import KProgFormal.ClightRefinement.Arm64MemsetTagWords

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagByteTransport

private theorem encoding : CC.encodeVal .Mint64 (.Vlong 0) = List.replicate 8 (.Byte 0) := by decide +kernel

/-- A real zero-word store at tag offset8 retains ALL24 actual zero byte
observations, using imported store/byte encoding and current readable access. -/
theorem word_store {before after : CC.Mem} {tags : CC.Block}
    (stored : CC.Mem.store .Mint64 before tags 8 (.Vlong 0) = some after)
    (prior : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before tags (j.val : Int) = some (.Vint 0)) :
    ∀ j : Fin 24, CC.Mem.load .Mint8unsigned after tags (j.val : Int) = some (.Vint 0) := by
  intro j
  by_cases below : (j.val : Int) < 8
  · exact (CC.Mem.load_store_other stored .Mint8unsigned tags (j.val : Int)
      (.inr (.inl (by simp only [CC.sizeChunk]; omega)))).trans (prior j)
  by_cases above : 16 ≤ (j.val : Int)
  · exact (CC.Mem.load_store_other stored .Mint8unsigned tags (j.val : Int)
      (.inr (.inr (by change (16 : Int) ≤ (j.val : Int); exact above)))).trans (prior j)
  have readable := (Arm64MemsetTagWords.byte_zero before tags (j.val : Int) (prior j)).1
  have afterReadable : CC.Mem.validAccess after .Mint8unsigned tags (j.val : Int) .Readable = true :=
    (CC.Mem.validAccess_store_eq stored .Mint8unsigned tags (j.val : Int) .Readable).trans readable
  let index : Nat := j.val - 8
  have bounded : index < 8 := by dsimp [index]; omega
  have actual : 8 + (index : Int) = (j.val : Int) := by dsimp [index]; omega
  have raw := CC.Mem.setN_inside (List.replicate 8 (CC.MemVal.Byte (0#8))) 8
    (CC.PMap.get tags before.contents) index (by simpa using bounded)
  have cell : CC.ZMap.get (j.val : Int) (CC.PMap.get tags after.contents) = .Byte 0 := by
    rw [CC.Mem.store_contents stored,CC.PMap.gss,encoding,←actual]
    have item : (List.replicate 8 (CC.MemVal.Byte (0#8)))[index]! = .Byte 0 := by
      rw [getElem!_pos _ _ (by simpa only [List.length_replicate] using bounded)]
      exact List.getElem_replicate _
    exact raw.trans item
  rw [CC.Mem.load,afterReadable]
  change some (CC.decodeVal .Mint8unsigned [CC.ZMap.get (j.val : Int) (CC.PMap.get tags after.contents)]) = some (.Vint 0)
  rw [cell]
  decide +kernel

/-- The genuine following stack-byte store retains the full tag-byte
invariant by actual allocation separation, ready for the next iteration. -/
theorem both_stores {before tagged after : CC.Mem} {tags stack : CC.Block} {offset : Int} {byte : BitVec 8}
    (tagStore : CC.Mem.store .Mint64 before tags 8 (.Vlong 0) = some tagged)
    (byteStore : CC.Mem.store .Mint8unsigned tagged stack offset (.Vint (byte.setWidth 32)) = some after)
    (separate : tags ≠ stack)
    (prior : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before tags (j.val : Int) = some (.Vint 0)) :
    ∀ j : Fin 24, CC.Mem.load .Mint8unsigned after tags (j.val : Int) = some (.Vint 0) := by
  intro j
  exact (CC.Mem.load_store_other byteStore .Mint8unsigned tags (j.val : Int) (.inl separate)).trans
    (word_store tagStore prior j)

end KProgFormal.ClightRefinement.Arm64MemsetTagByteTransport
