import KProgFormal.ClightRefinement.X86ProducerPushCacheFrame
import KProgFormal.Reference.Memory

namespace KProgFormal.ClightRefinement.X86ScalarStoreBytes

private theorem encoding (value : BitVec 64) (lane : Fin 8) :
    (CC.encodeVal .Mint64 (.Vlong value))[lane.val]! =
      .Byte ((value >>> (8 * lane.val)).setWidth 8) := by
  have cases : lane.val = 0 ∨ lane.val = 1 ∨ lane.val = 2 ∨ lane.val = 3 ∨ lane.val = 4 ∨ lane.val = 5 ∨ lane.val = 6 ∨ lane.val = 7 := by have bound := lane.isLt; omega
  rcases cases with h | h | h | h | h | h | h | h
  all_goals rw [h]
  all_goals simp +decide [CC.encodeVal,CC.injBytes,CC.encodeInt,CC.revIfBe_id,CC.bytesOfInt]
  all_goals congr 1
  all_goals apply BitVec.eq_of_toNat_eq
  all_goals
    simp only [CC.Integers.Byte.repr,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.MI.repr,BitVec.toNat_ofInt,BitVec.toNat_setWidth,BitVec.toNat_ushiftRight,Nat.shiftRight_eq_div_pow]
    omega

private theorem decode_byte (byte : BitVec 8) :
    CC.decodeVal .Mint8unsigned [.Byte byte] = .Vint (byte.setWidth 32) := by
  simp only [CC.decodeVal,CC.projBytes,Option.map_some,CC.decodeInt,CC.revIfBe_id,CC.intOfBytes,Int.zero_mul,Int.add_zero]
  congr 1
  apply BitVec.eq_of_toNat_eq
  change (CC.Integers.MI.zero_ext 8 (CC.Integers.Int.repr (CC.Integers.Byte.unsigned byte))).toNat = _
  rw [CC.toNat_zero_ext_8]
  simp only [CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Byte.unsigned,CC.Integers.MI.unsigned,
    BitVec.toNat_ofInt,BitVec.toNat_setWidth]
  have bound := byte.isLt
  omega

/-- A genuine scalar qword store provides every little-endian byte load.
Permissions come from the actual successful store, including at nonzero
and negative source offsets; no byte readback is assumed. -/
theorem load {before after : CC.Mem} {block : CC.Block} {offset : Int} {value : BitVec 64}
    (stored : CC.Mem.store .Mint64 before block offset (.Vlong value) = some after) (lane : Fin 8) :
    CC.Mem.load .Mint8unsigned after block (offset + lane.val) =
      some (.Vint (((value >>> (8 * lane.val)).setWidth 8).setWidth 32)) := by
  have permitted := CC.Mem.validAccess_implies (CC.Mem.store_valid_access stored) (by decide : CC.permOrder .Writable .Readable = true)
  have word : CC.Mem.validAccess after .Mint64 block offset .Readable = true :=
    (CC.Mem.validAccess_store_eq stored _ _ _ _).trans permitted
  have range : CC.Mem.rangePerm after block offset (offset + 8) .Cur .Readable = true := by
    have parts := word
    simp only [CC.Mem.validAccess,Bool.and_eq_true] at parts
    exact parts.1
  have nonnegative : 0 ≤ (lane.val : Int) := Int.natCast_nonneg _
  have byte : CC.Mem.validAccess after .Mint8unsigned block (offset + lane.val) .Readable = true := by
    rw [CC.Mem.validAccess,Bool.and_eq_true]
    change CC.Mem.rangePerm after block (offset + lane.val) (offset + lane.val + 1) .Cur .Readable = true ∧ _
    refine ⟨CC.Mem.rangePerm_intro _ _ _ _ _ _ (fun point lo hi =>
      CC.Mem.rangePerm_perm _ _ _ _ _ _ range point (by omega) (by have bound := lane.isLt; omega)),?_⟩
    simp [CC.alignChunk]
  rw [CC.Mem.load,byte,CC.Mem.store_contents stored,CC.PMap.gss]
  have selected := CC.Mem.setN_inside (CC.encodeVal .Mint64 (.Vlong value)) offset (CC.PMap.get block before.contents) lane.val
    (by change lane.val < 8; exact lane.isLt)
  rw [encoding] at selected
  change some (CC.decodeVal .Mint8unsigned [CC.ZMap.get (offset + lane.val)
    (CC.Mem.setN (CC.encodeVal .Mint64 (.Vlong value)) offset (CC.PMap.get block before.contents))]) = _
  rw [selected]
  exact congrArg some (decode_byte _)


end KProgFormal.ClightRefinement.X86ScalarStoreBytes
