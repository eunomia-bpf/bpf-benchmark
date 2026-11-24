import KProgFormal.ClightRefinement.X86StackCacheView

namespace KProgFormal.ClightRefinement.X86PushNativeBytes

private theorem selected (origin : BitVec 64) (byte : Fin 48) (lane : Nat) (bound : lane < 8) :
    (origin - (8#64) + BitVec.ofNat 64 lane == X86StackCacheView.address origin byte) =
      decide (byte.val = 40 + lane) := by
  apply Bool.eq_iff_iff.mpr
  simp only [beq_iff_eq,decide_eq_true_eq]
  constructor
  · intro same
    have offset := congrArg (fun address : BitVec 64 => address - (origin - (8#64))) same.symm
    have disp : X86StackCacheView.address origin byte - (origin - (8#64)) = BitVec.ofInt 64 ((byte.val : Int) - 40) := X86StackCacheView.displacement origin byte
    rw [disp] at offset
    have right : (origin - (8#64) + BitVec.ofNat 64 lane) - (origin - (8#64)) = BitVec.ofNat 64 lane := by
      rw [BitVec.add_comm (origin - (8#64))]
      exact BitVec.add_sub_cancel _ _
    rw [right] at offset
    have encoded := congrArg BitVec.toNat offset
    simp only [BitVec.toNat_ofInt,BitVec.toNat_ofNat] at encoded
    have b := byte.isLt
    have l := bound
    omega
  · intro same
    have offset : X86StackCacheView.address origin byte - (origin - (8#64)) = BitVec.ofInt 64 ((byte.val : Int) - 40) := X86StackCacheView.displacement origin byte
    have diff : BitVec.ofInt 64 ((byte.val : Int) - 40) = BitVec.ofNat 64 lane := by
      rw [same]
      apply BitVec.eq_of_toNat_eq
      simp only [BitVec.toNat_ofInt,BitVec.toNat_ofNat]
      have l := bound
      omega
    symm
    apply (BitVec.sub_left_inj (origin - (8#64))).mp
    rw [offset,diff,BitVec.add_comm (origin - (8#64)),BitVec.add_sub_cancel]

/-- Actual external qword-store bytes in the48-byte source cache window,
including wrapping native addresses and preservation of all40 lower bytes.
This unfolds the pinned external Mem.writeN, not a copied memory rule. -/
theorem table (memory : X86.Mem) (origin value : BitVec 64) (byte : Fin 48) :
    (memory.writeSize .q (origin - (8#64)) value).read (X86StackCacheView.address origin byte) =
      if byte.val < 40 then memory.read (X86StackCacheView.address origin byte)
      else (value >>> (8 * (byte.val - 40))).setWidth 8 := by
  have eq0 : (origin - (8#64) == X86StackCacheView.address origin byte) = decide (byte.val = 40) := by
    simpa using selected origin byte 0 (by decide)
  have eq1 : (origin - (8#64) + (1#64) == X86StackCacheView.address origin byte) = decide (byte.val = 41) := by
    simpa using selected origin byte 1 (by decide)
  have eq2 : (origin - (8#64) + (2#64) == X86StackCacheView.address origin byte) = decide (byte.val = 42) := by
    simpa using selected origin byte 2 (by decide)
  have eq3 : (origin - (8#64) + (3#64) == X86StackCacheView.address origin byte) = decide (byte.val = 43) := by
    simpa using selected origin byte 3 (by decide)
  have eq4 : (origin - (8#64) + (4#64) == X86StackCacheView.address origin byte) = decide (byte.val = 44) := by
    simpa using selected origin byte 4 (by decide)
  have eq5 : (origin - (8#64) + (5#64) == X86StackCacheView.address origin byte) = decide (byte.val = 45) := by
    simpa using selected origin byte 5 (by decide)
  have eq6 : (origin - (8#64) + (6#64) == X86StackCacheView.address origin byte) = decide (byte.val = 46) := by
    simpa using selected origin byte 6 (by decide)
  have eq7 : (origin - (8#64) + (7#64) == X86StackCacheView.address origin byte) = decide (byte.val = 47) := by
    simpa using selected origin byte 7 (by decide)
  have cases : byte.val < 40 ∨ byte.val = 40 ∨ byte.val = 41 ∨ byte.val = 42 ∨ byte.val = 43 ∨ byte.val = 44 ∨ byte.val = 45 ∨ byte.val = 46 ∨ byte.val = 47 := by
    have bound := byte.isLt
    omega
  rcases cases with lower | same | same | same | same | same | same | same | same
  · have n0 : byte.val ≠ 40 := by omega
    have n1 : byte.val ≠ 41 := by omega
    have n2 : byte.val ≠ 42 := by omega
    have n3 : byte.val ≠ 43 := by omega
    have n4 : byte.val ≠ 44 := by omega
    have n5 : byte.val ≠ 45 := by omega
    have n6 : byte.val ≠ 46 := by omega
    have n7 : byte.val ≠ 47 := by omega
    simp +decide [X86.Mem.writeSize,X86.Size.bytes,X86.Mem.writeN,X86.Mem.read,X86.Mem.write,
      List.find?,BitVec.add_assoc,eq0,eq1,eq2,eq3,eq4,eq5,eq6,eq7,lower,n0,n1,n2,n3,n4,n5,n6,n7]
  all_goals simp +decide [X86.Mem.writeSize,X86.Size.bytes,X86.Mem.writeN,X86.Mem.read,X86.Mem.write,
    List.find?,BitVec.add_assoc,eq0,eq1,eq2,eq3,eq4,eq5,eq6,eq7, *]

end KProgFormal.ClightRefinement.X86PushNativeBytes
