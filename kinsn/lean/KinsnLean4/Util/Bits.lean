/-
  Pure `BitVec` facts shared by the three instruction-set models: low masks,
  rotations, sign extension and byte reversal.
-/
import Mathlib.Data.BitVec
import Mathlib.Tactic.IntervalCases

namespace Bits

/-! ## Low masks -/

/-- The `(1 << n) - 1` idiom, as both the kernel C code and ARM's
    `DecodeBitMasks` write it.  Saturates correctly: for `n ≥ w` the shift
    gives `0` and `0 - 1` is `allOnes`. -/
def lowMask (w n : Nat) : BitVec w := ((1 : BitVec w) <<< n) - 1

theorem lowMask_toNat (w n : Nat) : (lowMask w n).toNat = (2 ^ n - 1) % 2 ^ w := by
  rcases Nat.eq_zero_or_pos w with rfl | hw
  · have h := (lowMask 0 n).isLt
    simp only [Nat.pow_zero, Nat.lt_one_iff] at h
    simp [h, Nat.mod_one]
  · have h2 : ((1 : BitVec w)).toNat = 1 := BitVec.toNat_one hw
    have h1 : ((1 : BitVec w) <<< n).toNat = 2 ^ n % 2 ^ w := by
      rw [BitVec.toNat_shiftLeft, h2, Nat.shiftLeft_eq, Nat.one_mul]
    have hpn : 1 ≤ 2 ^ n := Nat.one_le_two_pow
    rw [lowMask, BitVec.toNat_sub, h1, h2, Nat.add_mod_mod,
      show 2 ^ w - 1 + 2 ^ n = 2 ^ w + (2 ^ n - 1) by omega, Nat.add_mod_left]

theorem lowMask_eq_ofNat (w n : Nat) : lowMask w n = BitVec.ofNat w (2 ^ n - 1) := by
  apply BitVec.eq_of_toNat_eq
  rw [lowMask_toNat, BitVec.toNat_ofNat]

@[simp]
theorem getLsbD_lowMask (w n i : Nat) :
    (lowMask w n).getLsbD i = (decide (i < w) && decide (i < n)) := by
  rw [lowMask_eq_ofNat, BitVec.getLsbD_ofNat, Nat.testBit_two_pow_sub_one]

@[simp]
theorem getElem_lowMask (w n i : Nat) (h : i < w) :
    (lowMask w n)[i] = decide (i < n) := by
  rw [← BitVec.getLsbD_eq_getElem h, getLsbD_lowMask]
  simp [h]

theorem lowMask_of_le (w n : Nat) (h : w ≤ n) : lowMask w n = BitVec.allOnes w := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [getLsbD_lowMask, BitVec.getLsbD_allOnes]
  simp [hi, Nat.lt_of_lt_of_le hi h]

@[simp]
theorem lowMask_zero (w : Nat) : lowMask w 0 = 0 := by
  apply BitVec.eq_of_getLsbD_eq; intro i hi; simp

theorem and_lowMask_eq_setWidth (x : BitVec w) (n : Nat) :
    x &&& lowMask w n = BitVec.setWidth w (BitVec.setWidth n x) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_and, getLsbD_lowMask, BitVec.getLsbD_setWidth]
  simp [hi, Bool.and_comm]

/-- `Replicate` of a single bit, from the ARM bitfield pseudocode. -/
def replicate (b : Bool) (w : Nat) : BitVec w := if b then BitVec.allOnes w else 0

@[simp]
theorem getLsbD_replicate (b : Bool) (w i : Nat) :
    (replicate b w).getLsbD i = (b && decide (i < w)) := by
  cases b <;> simp [replicate]

@[simp]
theorem getElem_replicate (b : Bool) (w i : Nat) (h : i < w) :
    (replicate b w)[i] = b := by
  rw [← BitVec.getLsbD_eq_getElem h, getLsbD_replicate]
  simp [h]

/-! ## Rotations

  BPF has no rotate instruction, so a rotate expands to `shift ; shift ; or`. -/

theorem rotateRight_eq (x : BitVec w) (n : Nat) (h : n < w) :
    x.rotateRight n = (x >>> n) ||| (x <<< (w - n)) := by
  simp [BitVec.rotateRight, BitVec.rotateRightAux, Nat.mod_eq_of_lt h]

theorem rotateLeft_eq (x : BitVec w) (n : Nat) (h : n < w) :
    x.rotateLeft n = (x <<< n) ||| (x >>> (w - n)) := by
  simp [BitVec.rotateLeft, BitVec.rotateLeftAux, Nat.mod_eq_of_lt h]

/-- The expansion computes the shifted-up part in a scratch register and
    `or`s it in second, so the disjunction comes out reversed. -/
theorem shiftLeft_or_shiftRight_eq_rotateRight (x : BitVec w) (n : Nat) (h : n < w) :
    (x <<< (w - n)) ||| (x >>> n) = x.rotateRight n := by
  rw [rotateRight_eq x n h, BitVec.or_comm]

theorem rotateLeft_eq_rotateRight (x : BitVec w) (n : Nat) (h : n < w) (hn : 0 < n) :
    x.rotateLeft n = x.rotateRight (w - n) := by
  rw [rotateLeft_eq x n h, rotateRight_eq x (w - n) (by omega), BitVec.or_comm]
  congr 2
  omega

/-! ## Sign extension -/

/-- Shift up and back down arithmetically — the only way BPF can sign-extend
    without `BPF_MOVSX`. -/
theorem shiftLeft_sshiftRight_eq_signExtend (x : BitVec 64) (w : Nat)
    (h1 : 1 ≤ w) (h2 : w ≤ 64) :
    (x <<< (64 - w)).sshiftRight (64 - w) = BitVec.signExtend 64 (BitVec.setWidth w x) := by
  have hmsb : (BitVec.setWidth w x).msb = x.getLsbD (w - 1) := by
    rw [BitVec.msb_eq_getLsbD_last]
    simp [BitVec.getLsbD_setWidth]
    omega
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_sshiftRight, BitVec.getLsbD_shiftLeft, BitVec.msb_eq_getLsbD_last,
    BitVec.getLsbD_signExtend, BitVec.getLsbD_setWidth]
  by_cases hiw : i < w
  · have e1 : 64 - w + i < 64 := by omega
    have e2 : ¬ (64 - w + i < 64 - w) := by omega
    simp [hi, hiw, e1, e2]
  · have e1 : ¬ (64 - w + i < 64) := by omega
    have e2 : ¬ (63 < 64 - w) := by omega
    simp only [show ¬(64 ≤ i) from by omega, decide_false, Bool.not_false, e1, reduceIte,
      Nat.add_one_sub_one, Nat.lt_add_one, decide_true, e2, Bool.and_self,
      show 63 - (64 - w) = w - 1 from by omega, Bool.true_and, hiw, tsub_lt_self_iff,
      zero_lt_one, and_true, hi, show (0 : Nat) < w from h1]

/-! ## Byte reversal

  Defined with shifts and masks rather than `BitVec.append`: `getLsbD` lemmas
  fire on the former, which keeps the byte-swap proofs kernel-checkable
  instead of needing a SAT certificate. -/

/-- ARM64 `REV`, x86 `BSWAP`. -/
def bswap64 (x : BitVec 64) : BitVec 64 :=
  ((x &&& lowMask 64 8) <<< 56) |||
  (((x >>> 8) &&& lowMask 64 8) <<< 48) |||
  (((x >>> 16) &&& lowMask 64 8) <<< 40) |||
  (((x >>> 24) &&& lowMask 64 8) <<< 32) |||
  (((x >>> 32) &&& lowMask 64 8) <<< 24) |||
  (((x >>> 40) &&& lowMask 64 8) <<< 16) |||
  (((x >>> 48) &&& lowMask 64 8) <<< 8) |||
  ((x >>> 56) &&& lowMask 64 8)

/-- ARM64 `REV32`, x86 `BSWAP r32`. -/
def bswap32 (x : BitVec 32) : BitVec 32 :=
  ((x &&& lowMask 32 8) <<< 24) |||
  (((x >>> 8) &&& lowMask 32 8) <<< 16) |||
  (((x >>> 16) &&& lowMask 32 8) <<< 8) |||
  ((x >>> 24) &&& lowMask 32 8)

/-- ARM64 `REV16`, x86 `ROL r16, 8`. -/
def bswap16 (x : BitVec 16) : BitVec 16 :=
  ((x &&& lowMask 16 8) <<< 8) ||| ((x >>> 8) &&& lowMask 16 8)

theorem getLsbD_bswap64 (x : BitVec 64) (i : Nat) (hi : i < 64) :
    (bswap64 x).getLsbD i = x.getLsbD (8 * (7 - i / 8) + i % 8) := by
  simp only [bswap64]
  interval_cases i <;> simp

@[simp]
theorem bswap64_bswap64 (x : BitVec 64) : bswap64 (bswap64 x) = x := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [getLsbD_bswap64 _ i hi]
  rw [getLsbD_bswap64 _ _ (by omega)]
  congr 1
  omega

@[simp]
theorem bswap32_bswap32 (x : BitVec 32) : bswap32 (bswap32 x) = x := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [bswap32]
  interval_cases i <;> simp

@[simp]
theorem bswap16_bswap16 (x : BitVec 16) : bswap16 (bswap16 x) = x := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [bswap16]
  interval_cases i <;> simp

end Bits
