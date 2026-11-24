import KProgFormal.ClightRefinement.X86PushNativeBytes

namespace KProgFormal.ClightRefinement.X86PushNativePayload

/-- The source's selected last qword maps to the true native write span. -/
theorem coordinate (origin : BitVec 64) (lane : Fin 8) :
    X86StackCacheView.address origin ⟨40 + lane.val,by have bound := lane.isLt; omega⟩ =
      origin - (8#64) + BitVec.ofNat 64 lane.val := by
  apply BitVec.eq_of_toNat_eq
  simp only [X86StackCacheView.address,BitVec.toNat_add,BitVec.toNat_sub,BitVec.toNat_ofNat,
    show (48 : BitVec 64).toNat = 48 from rfl,show (8#64).toNat = 8 from rfl]
  have a := origin.isLt
  have b := lane.isLt
  omega

/-- Actual pinned external write bytes are precisely the common native
event payload. No independent serialization or guessed memory value occurs. -/
theorem bytes (memory : X86.Mem) (address value : BitVec 64) :
    (List.range 8).map (fun lane => (memory.writeSize .q address value).read (address + BitVec.ofNat 64 lane)) =
      Reference.valueBytes value 8 := by
  unfold Reference.valueBytes
  apply List.map_congr_left
  intro lane member
  have bound : lane < 8 := List.mem_range.mp member
  let origin := address + (8#64)
  have base : origin - (8#64) = address := BitVec.add_sub_cancel address (8#64)
  have selected := X86PushNativeBytes.table memory origin value ⟨40 + lane,by omega⟩
  have same := coordinate origin ⟨lane,bound⟩
  rw [same,base] at selected
  have lower : ¬ 40 + lane < 40 := by omega
  simpa [lower] using selected

end KProgFormal.ClightRefinement.X86PushNativePayload
