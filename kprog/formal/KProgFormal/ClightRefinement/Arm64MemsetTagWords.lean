import CCLib.HoareLong
import KProgFormal.ClightRefinement.Arm64MemsetAbiOriginal

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagWords

private theorem decode_byte (byte : CC.Byte) :
    CC.decodeVal .Mint8unsigned [.Byte byte] = .Vint (byte.setWidth 32) := by
  change CC.Val.Vint (CC.Integers.Int.zero_ext 8 (CC.Integers.Int.repr (byte.toNat : Int))) = _
  rw [CC.zero_ext8_repr byte.toNat byte.isLt]
  congr 1
  apply BitVec.eq_of_toNat_eq
  simp [CC.Integers.Int.repr,CC.Integers.MI.repr,BitVec.toNat_setWidth,BitVec.toNat_ofInt]

/-- A real unsigned-byte zero load exposes its actual source byte and access. -/
theorem byte_zero (m : CC.Mem) (block : CC.Block) (offset : Int)
    (read : CC.Mem.load .Mint8unsigned m block offset = some (.Vint 0)) :
    CC.Mem.validAccess m .Mint8unsigned block offset .Readable = true ∧
    CC.ZMap.get offset (CC.PMap.get block m.contents) = .Byte 0 := by
  unfold CC.Mem.load at read
  split at read
  · rename_i valid
    refine ⟨valid,?_⟩
    change some (CC.decodeVal .Mint8unsigned [CC.ZMap.get offset (CC.PMap.get block m.contents)]) = some (.Vint 0) at read
    cases cell : CC.ZMap.get offset (CC.PMap.get block m.contents) with
    | Undef => simp [cell,CC.decodeVal,CC.projBytes] at read
    | Fragment v q i => simp [cell,CC.decodeVal,CC.projBytes] at read
    | Byte b =>
      rw [cell,decode_byte] at read
      have word : b.setWidth 32 = (0#32) := CC.Val.Vint.inj (Option.some.inj read)
      have byte : b = (0#8) := by
        have same := congrArg (BitVec.setWidth 8) word
        simpa using same
      exact congrArg CC.MemVal.Byte byte
  · simp at read

/-- Eight observed byte zeros yield the real imported64-bit load at the
same aligned address; no word-load success is introduced as a premise. -/
theorem zero_word (m : CC.Mem) (block : CC.Block) (base : Int)
    (aligned : base % CC.alignChunk .Mint64 = 0)
    (read : ∀ i : Fin 8, CC.Mem.load .Mint8unsigned m block (base + (i.val : Int)) = some (.Vint 0)) :
    CC.Mem.load .Mint64 m block base = some (.Vlong 0) := by
  have observed (i : Fin 8) := byte_zero m block (base + (i.val : Int)) (read i)
  have readable : CC.Mem.rangePerm m block base (base + 8) .Cur .Readable = true := by
    apply CC.Mem.rangePerm_intro
    intro offset lower upper
    have range : 0 ≤ offset - base ∧ offset - base < 8 := by omega
    let i : Fin 8 := ⟨(offset-base).toNat,by omega⟩
    have same : base + (i.val : Int) = offset := by dsimp [i]; omega
    have valid := (observed i).1
    simp only [CC.Mem.validAccess,Bool.and_eq_true] at valid
    have perm := CC.Mem.rangePerm_perm m block (base + (i.val : Int))
      (base + (i.val : Int) + CC.sizeChunk .Mint8unsigned) .Cur .Readable valid.1
      offset (by omega) (by simp only [CC.sizeChunk]; omega)
    exact perm
  have valid : CC.Mem.validAccess m .Mint64 block base .Readable = true := by
    simp only [CC.Mem.validAccess,CC.sizeChunk,readable,aligned,beq_self_eq_true,Bool.and_self]
  have c0 : CC.ZMap.get base (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨0,by decide⟩).2
  have c1 : CC.ZMap.get (base + 1) (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨1,by decide⟩).2
  have c2 : CC.ZMap.get (base + 2) (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨2,by decide⟩).2
  have c3 : CC.ZMap.get (base + 3) (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨3,by decide⟩).2
  have c4 : CC.ZMap.get (base + 4) (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨4,by decide⟩).2
  have c5 : CC.ZMap.get (base + 5) (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨5,by decide⟩).2
  have c6 : CC.ZMap.get (base + 6) (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨6,by decide⟩).2
  have c7 : CC.ZMap.get (base + 7) (CC.PMap.get block m.contents) = .Byte 0 := by
    simpa using (observed ⟨7,by decide⟩).2
  have contents : CC.Mem.getN 8 base (CC.PMap.get block m.contents) = List.replicate 8 (.Byte 0) := by
    simp [CC.Mem.getN,Int.add_assoc,c0,c1,c2,c3,c4,c5,c6,c7]
  have decoding : CC.decodeVal .Mint64 (List.replicate 8 (.Byte 0)) = .Vlong 0 := by decide +kernel
  rw [CC.Mem.load,valid]
  change some (CC.decodeVal .Mint64 (CC.Mem.getN 8 base (CC.PMap.get block m.contents))) = _
  rw [contents,decoding]

/-- The original24 zero tag byte observations supply all3 real aligned words. -/
theorem original (m : CC.Mem) (tags : CC.Block)
    (read : ∀ i : Fin 24, CC.Mem.load .Mint8unsigned m tags (i.val : Int) = some (.Vint 0))
    (word : Fin 3) :
    CC.Mem.load .Mint64 m tags (8 * (word.val : Int)) = some (.Vlong 0) := by
  apply zero_word m tags (8 * (word.val : Int))
  · simp only [CC.alignChunk]; omega
  · intro i
    let index : Fin 24 := ⟨8 * word.val + i.val,by omega⟩
    have offset : 8 * (word.val : Int) + (i.val : Int) = (index.val : Int) := by
      dsimp [index]
    rw [offset]
    exact read index

end KProgFormal.ClightRefinement.Arm64MemsetTagWords
