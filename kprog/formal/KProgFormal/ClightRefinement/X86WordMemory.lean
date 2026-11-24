import KProgFormal.ClightRefinement.X86ShiftWriteback

namespace KProgFormal.ClightRefinement.X86WordMemory

def lane (next : BitVec 64) : BitVec 32 := (next.setWidth 16).setWidth 32

def image (old next : BitVec 64) : List CC.Byte :=
  ((CC.encodeInt 8 (CC.Integers.Int64.unsigned old)).set 0
    (CC.Integers.Byte.repr (CC.Integers.Int.unsigned (lane next)))).set 1
    (CC.Integers.Byte.repr (CC.Integers.Int.unsigned (lane next) / 256))

def word (old next : BitVec 64) : BitVec 64 :=
  CC.Integers.Int64.repr (CC.decodeInt (image old next))

private theorem memory_image (contents : CC.ZMap CC.MemVal) (old next : BitVec 64) :
    CC.Mem.getN 8 0
      (CC.Mem.setN (CC.encodeVal .Mint16unsigned (.Vint (lane next))) 0
        (CC.Mem.setN (CC.encodeVal CC.Mptr (.Vlong old)) 0 contents)) =
      CC.injBytes (image old next) := by
  simp +decide [image, CC.Mptr, CC.encodeVal, CC.encodeInt, CC.revIfBe_id,
    CC.bytesOfInt, CC.injBytes, CC.Mem.getN, CC.Mem.setN, CC.ZMap.gss, CC.ZMap.gso]

/-- Actual local64-bit initialization followed by the original two-byte
store reads back the precise little-endian word and keeps its real copy cast. -/
theorem load (before copied after : CC.Mem) (block : CC.Block) (old next : BitVec 64)
    (initialized : CC.Mem.store CC.Mptr before block 0 (.Vlong old) = some copied)
    (stored : CC.Mem.store .Mint16unsigned copied block 0 (.Vint (lane next)) = some after) :
    CC.Mem.load CC.Mptr after block 0 = some (.Vlong (word old next)) ∧
    CC.Cop.semCast (.Vlong (word old next)) (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) after =
      some (.Vlong (word old next)) := by
  have readable : CC.Mem.validAccess before CC.Mptr block 0 .Readable = true :=
    CC.Mem.validAccess_implies (CC.Mem.store_valid_access initialized) (by decide)
  have permitted : CC.Mem.validAccess after CC.Mptr block 0 .Readable = true := by
    rw [CC.Mem.validAccess_store_eq stored, CC.Mem.validAccess_store_eq initialized]
    exact readable
  constructor
  · rw [CC.Mem.load, permitted, CC.Mem.store_contents stored, CC.PMap.gss,
      CC.Mem.store_contents initialized, CC.PMap.gss]
    change some (CC.decodeVal CC.Mptr
      (CC.Mem.getN 8 0 (CC.Mem.setN (CC.encodeVal .Mint16unsigned (.Vint (lane next))) 0
        (CC.Mem.setN (CC.encodeVal CC.Mptr (.Vlong old)) 0 (CC.PMap.get block before.contents))))) = _
    rw [memory_image]
    simp only [CC.decodeVal, CC.projBytes_injBytes, CC.Mptr, CC.Archi.ptr64_eq, ite_true, word]
  · rfl

private theorem lane_unsigned (next : BitVec 64) :
    CC.Integers.Int.unsigned (lane next) = ((next.setWidth 16).toNat : Int) := by
  simp only [lane, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
    BitVec.toNat_setWidth_of_le (by decide : 16 ≤ 32)]

private theorem cancel (a b c d z : _root_.Int) :
    (c + (d + z * 256) * 256) + (a + b * 256) =
      (a + (b + z * 256) * 256) + (c + d * 256) := by omega

private theorem decode_change (old next : BitVec 64) :
    CC.decodeInt (image old next) + CC.decodeInt (CC.encodeInt 2 (CC.Integers.Int64.unsigned old)) =
      CC.decodeInt (CC.encodeInt 8 (CC.Integers.Int64.unsigned old)) +
        CC.decodeInt (CC.encodeInt 2 (CC.Integers.Int.unsigned (lane next))) := by
  simp only [image, CC.decodeInt, CC.encodeInt, CC.revIfBe_id, CC.bytesOfInt,
    List.set, CC.intOfBytes, CC.byte_unsigned_repr, Int.zero_mul, Int.add_zero]
  exact cancel _ _ _ _ _

private theorem concat (old next : BitVec 64) :
    X86.Value.writeView .w old next = ((old >>> 16).setWidth 48 ++ next.setWidth 16) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [X86.Value.writeView_getLsbD_w, BitVec.getLsbD_append,
    BitVec.getLsbD_setWidth, BitVec.getLsbD_ushiftRight]
  by_cases small : i < 16
  · simp [small]
  · have upper : i - 16 < 48 := by omega
    have restored : 16 + (i - 16) = i := by omega
    simp [small, upper, restored]

private theorem reassemble (x b : Nat) (decoded : _root_.Int)
    (changed : decoded + (x : Int) % 65536 = (x : Int) + (b : Int)) :
    decoded = ((x / 65536 * 65536 + b : Nat) : Int) := by omega

/-- The actual partial-store word is exactly the imported ISA's low16-bit
writeView, including preservation of all48 untouched upper bits. -/
theorem native (old next : BitVec 64) : word old next = X86.Value.writeView .w old next := by
  have oldBounds : 0 ≤ CC.Integers.Int64.unsigned old ∧
      CC.Integers.Int64.unsigned old < 18446744073709551616 := by
    change 0 ≤ (old.toNat : Int) ∧ (old.toNat : Int) < 18446744073709551616
    have bound := old.isLt
    omega
  have small : (next.setWidth 16).toNat < 65536 := (next.setWidth 16).isLt
  have changed := decode_change old next
  rw [CC.decodeInt_encodeInt_2, CC.decodeInt_encodeInt_8, CC.decodeInt_encodeInt_2,
    Int.emod_eq_of_lt oldBounds.1 oldBounds.2, lane_unsigned] at changed
  have newMod : ((next.setWidth 16).toNat : Int) % 65536 = ((next.setWidth 16).toNat : Int) := by omega
  rw [newMod] at changed
  have restBound : old.toNat / 65536 < 281474976710656 := by
    have bound := old.isLt
    omega
  have concatNat : (((old >>> 16).setWidth 48) ++ next.setWidth 16).toNat =
      old.toNat / 65536 * 65536 + (next.setWidth 16).toNat := by
    rw [BitVec.toNat_append, ← Nat.shiftLeft_add_eq_or_of_lt small]
    simp only [BitVec.toNat_setWidth, BitVec.toNat_ushiftRight, Nat.shiftRight_eq_div_pow,
      Nat.shiftLeft_eq]
    simp only [show 2 ^ 16 = 65536 from by decide,
      show 2 ^ 48 = 281474976710656 from by decide, Nat.mod_eq_of_lt restBound]
  have decoded : CC.decodeInt (image old next) =
      (((((old >>> 16).setWidth 48) ++ next.setWidth 16).toNat) : Int) := by
    rw [concatNat]
    exact reassemble old.toNat (next.setWidth 16).toNat _ changed
  rw [concat]
  apply BitVec.eq_of_toNat_eq
  simp only [word, CC.Integers.Int64.repr, CC.Integers.MI.repr, decoded, BitVec.toNat_ofInt]
  have bound := ((((old >>> 16).setWidth 48) ++ next.setWidth 16)).isLt
  omega

/-- The concrete memory readback and imported width update agree. -/
theorem readback (before copied after : CC.Mem) (block : CC.Block) (old next : BitVec 64)
    (initialized : CC.Mem.store CC.Mptr before block 0 (.Vlong old) = some copied)
    (stored : CC.Mem.store .Mint16unsigned copied block 0 (.Vint (lane next)) = some after) :
    CC.Mem.load CC.Mptr after block 0 = some (.Vlong (X86.Value.writeView .w old next)) := by
  simpa only [native] using (load before copied after block old next initialized stored).1

end KProgFormal.ClightRefinement.X86WordMemory
