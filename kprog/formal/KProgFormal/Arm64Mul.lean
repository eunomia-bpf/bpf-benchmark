import Init.Data.BitVec
import KProgFormal.GeneratedArm64Mul
import KProgFormal.GeneratedArm64Flags
import KProgFormal.GeneratedArm64Width

namespace KProgFormal

open GeneratedArm64Mul (Mul)
open GeneratedArm64Width (Width narrow)

/-- The bitwise-and with the 32-bit mask is the remainder modulo `2^32`. This is
the step that turns C's `(__u64)(__u32)x` widening into the `Nat` decomposition
the UMULH identity is stated over. -/
theorem arm64MulNatAndLo32 (x : Nat) : x &&& 4294967295 = x % 2^32 := by
  have h : (4294967295:Nat) = 2^32 - 1 := by decide
  rw [h, Nat.and_two_pow_sub_one_eq_mod]

@[simp] theorem arm64MulToNatMask32 :
    BitVec.toNat (0xffffffff : BitVec 64) = 4294967295 := by decide

/-- The product of two 32-bit values fits in 64 bits, so its 64-bit wrap is the
plain product. -/
theorem arm64MulMul32Lt (x y : Nat) (hx : x < 2^32) (hy : y < 2^32) :
    x * y < 2^64 := by
  have h : (2:Nat)^32 * 2^32 = 2^64 := by omega
  calc x * y < 2^32 * 2^32 :=
        Nat.mul_lt_mul_of_le_of_lt (Nat.le_of_lt hx) hy (by decide)
    _ = 2^64 := h

theorem arm64MulPow2 : (2:Nat)^32 * 2^32 = 2^64 := by omega

/-- The 32-by-32 radix decomposition of a product: the high half contributes at
`2^64`, the two cross terms at `2^32` and the low halves below that. -/
theorem arm64MulExpandPq (a0 a1 b0 b1 : Nat) :
    (2^32*a1+a0)*(2^32*b1+b0)
      = a1*b1*2^64 + (a1*b0 + a0*b1)*2^32 + a0*b0 := by
  have hp : (2:Nat)^32 * 2^32 = 2^64 := arm64MulPow2
  simp only [Nat.mul_add, Nat.add_mul, Nat.mul_assoc, Nat.mul_left_comm,
    Nat.mul_comm, hp]
  omega

theorem arm64MulDiv64Add (X Z : Nat) : (X + 2^64 * Z) / 2^64 = X / 2^64 + Z := by
  have h : 0 < (2:Nat)^64 := by decide
  rw [Nat.add_mul_div_left X Z h]

/-- A multiple of `2^64` above the low part contributes its integer quotient
directly. -/
theorem arm64MulSplitHi (a1 b1 m1 m2 Lo : Nat) :
    (a1*b1*2^64 + (m1 + m2)*2^32 + Lo) / 2^64
      = a1*b1 + ((m1 + m2)*2^32 + Lo) / 2^64 := by
  rw [show a1*b1*2^64 + (m1 + m2)*2^32 + Lo
            = ((m1 + m2)*2^32 + Lo) + 2^64*(a1*b1) by omega]
  rw [arm64MulDiv64Add]
  omega

/-- The two cross terms of the radix decomposition contribute their own high
halves plus the carry they push into the next 32-bit column. -/
theorem arm64MulCrossTerm (m1 m2 Lo : Nat) :
    ((m1 + m2)*2^32 + Lo) / 2^64
      = m1/2^32 + m2/2^32 + (Lo/2^32 + m1%2^32 + m2%2^32)/2^32 := by
  omega

/-- The radix-`2^32` decomposition of an arbitrary product. Stated through
`congrArg` so the decomposition lemma never rewrites inside `a/2^32`/`a%2^32`,
which would recurse. -/
theorem arm64MulPq (a b : Nat) :
    a * b
      = (a/2^32)*(b/2^32)*2^64
        + ((a/2^32)*(b%2^32) + (a%2^32)*(b/2^32))*2^32
        + (a%2^32)*(b%2^32) := by
  have ha : a = 2^32*(a/2^32) + a%2^32 := (Nat.div_add_mod a (2^32)).symm
  have hb : b = 2^32*(b/2^32) + b%2^32 := (Nat.div_add_mod b (2^32)).symm
  have h1 : a * b = (2^32*(a/2^32) + a%2^32) * b := congrArg (· * b) ha
  have h2 : (2^32*(a/2^32) + a%2^32) * b
      = (2^32*(a/2^32) + a%2^32) * (2^32*(b/2^32) + b%2^32) :=
    congrArg ((2^32*(a/2^32) + a%2^32) * ·) hb
  exact h1.trans (h2.trans
    (arm64MulExpandPq (a%2^32) (a/2^32) (b%2^32) (b/2^32)))

/-- Arithmetic reading of the UMULH ladder: the four partial products of the
radix decomposition, the two cross-term high halves, and the carry out of the
`2^32` column. -/
theorem arm64MulUmulhNat (a b : Nat) (_ha : a < 2^64) (_hb : b < 2^64) :
    (a/2^32)*(b/2^32)
      + ((a/2^32)*(b%2^32))/2^32
      + ((a%2^32)*(b/2^32))/2^32
      + (((a%2^32)*(b%2^32))/2^32
          + ((a/2^32)*(b%2^32))%2^32
          + ((a%2^32)*(b/2^32))%2^32)/2^32
    = (a*b)/2^64 := by
  conv => rhs; rw [arm64MulPq]
  rw [arm64MulSplitHi]
  rw [arm64MulCrossTerm]
  omega

/-- Two 64-bit operands multiply to below `2^128`, so their product is exact in
128 bits. -/
theorem arm64MulProdBound (a b : Nat) (ha : a < 2^64) (hb : b < 2^64) :
    a * b < 2^128 := by
  have h : (2:Nat)^64 * 2^64 = 2^128 := by omega
  calc a * b < 2^64 * 2^64 :=
        Nat.mul_lt_mul_of_le_of_lt (Nat.le_of_lt ha) hb (by decide)
    _ = 2^128 := h

/-- The high word of the exact 128-bit product, read back through the modulo
`2^64` of the shifted 128-bit value. -/
theorem arm64MulNatShift (a b : Nat) (ha : a < 2^64) (hb : b < 2^64) :
    (a * b % 2^128) >>> 64 % 2^64 = a * b / 2^64 := by
  have hbnd : a * b < 2^128 := arm64MulProdBound a b ha hb
  rw [Nat.mod_eq_of_lt hbnd, Nat.shiftRight_eq_div_pow, Nat.mod_eq_of_lt]
  omega

def arm64MulUmulhNatAlg (a b : Nat) : Nat :=
  (a/2^32)*(b/2^32)
    + ((a/2^32)*(b%2^32))/2^32
    + ((a%2^32)*(b/2^32))/2^32
    + (((a%2^32)*(b%2^32))/2^32
        + ((a/2^32)*(b%2^32))%2^32
        + ((a%2^32)*(b/2^32))%2^32)/2^32

/-- Independent Lean reading of the simulator's UMULH ladder. Written as a
`let` chain over 32-bit halves so it is structurally separate from the generated
C arm and from the 128-bit product statement the refinement compares it to. -/
def arm64MulUmulhAlg (lhs rhs : BitVec 64) : BitVec 64 :=
  let lhsLo := lhs &&& 0xffffffff
  let lhsHi := lhs >>> 32
  let rhsLo := rhs &&& 0xffffffff
  let rhsHi := rhs >>> 32
  let lo := lhsLo * rhsLo
  let mid1 := lhsHi * rhsLo
  let mid2 := lhsLo * rhsHi
  let hi := lhsHi * rhsHi
  let carry := ((lo >>> 32) + (mid1 &&& 0xffffffff) + (mid2 &&& 0xffffffff)) >>> 32
  hi + (mid1 >>> 32) + (mid2 >>> 32) + carry

/-- Every BitVec `&&&`/`>>>` in the ladder is a `Nat` modulo/divide by `2^32`,
so the ladder's value is the arithmetic formula `arm64MulUmulhNatAlg`. The
residual `% 2^64` is removed one layer at a time; the outermost one is closed by
the bound transferred through the arithmetic identity. -/
theorem arm64MulUmulhAlgToNat (a b : Nat) (ha : a < 2^64) (hb : b < 2^64) :
    (arm64MulUmulhAlg (BitVec.ofNat 64 a) (BitVec.ofNat 64 b)).toNat
      = arm64MulUmulhNatAlg a b := by
  have hA : (BitVec.ofNat 64 a).toNat = a := by
    simp [BitVec.toNat_ofNat, Nat.mod_eq_of_lt ha]
  have hB : (BitVec.ofNat 64 b).toNat = b := by
    simp [BitVec.toNat_ofNat, Nat.mod_eq_of_lt hb]
  have hpa : a/2^32 < 2^32 := by omega
  have hpb : b/2^32 < 2^32 := by omega
  have hqa : a%2^32 < 2^32 := by omega
  have hqb : b%2^32 < 2^32 := by omega
  have p00 : a/2^32*(b/2^32) < 2^64 := arm64MulMul32Lt _ _ hpa hpb
  have p01 : a/2^32*(b%2^32) < 2^64 := arm64MulMul32Lt _ _ hpa hqb
  have p10 : a%2^32*(b/2^32) < 2^64 := arm64MulMul32Lt _ _ hqa hpb
  have p11 : a%2^32*(b%2^32) < 2^64 := arm64MulMul32Lt _ _ hqa hqb
  simp only [arm64MulUmulhAlg, arm64MulUmulhNatAlg, BitVec.toNat_add,
    BitVec.toNat_mul, BitVec.toNat_and, BitVec.toNat_ushiftRight,
    BitVec.toNat_ofNat, Nat.shiftRight_eq_div_pow, arm64MulToNatMask32,
    arm64MulNatAndLo32, hA, hB]
  simp only [Nat.mod_eq_of_lt p00, Nat.mod_eq_of_lt p01,
    Nat.mod_eq_of_lt p10, Nat.mod_eq_of_lt p11]
  have hid : (a/2^32)*(b/2^32) + (a/2^32)*(b%2^32)/2^32
      + (a%2^32)*(b/2^32)/2^32
      + ((a%2^32)*(b%2^32)/2^32 + (a/2^32)*(b%2^32)%2^32
          + (a%2^32)*(b/2^32)%2^32)/2^32
      = (a*b)/2^64 := arm64MulUmulhNat a b ha hb
  have hbnd : (a*b)/2^64 < 2^64 := by
    rw [Nat.div_lt_iff_lt_mul (by decide : 0 < (2:Nat)^64)]
    exact arm64MulProdBound a b ha hb
  have mb1 : (a%2^32*(b%2^32)/2^32 + (a/2^32)*(b%2^32)%2^32) % 2^64
      = a%2^32*(b%2^32)/2^32 + (a/2^32)*(b%2^32)%2^32 :=
    Nat.mod_eq_of_lt (by omega)
  have mb2 : (a%2^32*(b%2^32)/2^32 + (a/2^32)*(b%2^32)%2^32
      + (a%2^32)*(b/2^32)%2^32) % 2^64
      = a%2^32*(b%2^32)/2^32 + (a/2^32)*(b%2^32)%2^32
        + (a%2^32)*(b/2^32)%2^32 := Nat.mod_eq_of_lt (by omega)
  have ma1 : ((a/2^32)*(b/2^32) + (a/2^32)*(b%2^32)/2^32) % 2^64
      = (a/2^32)*(b/2^32) + (a/2^32)*(b%2^32)/2^32 :=
    Nat.mod_eq_of_lt (by omega)
  have ma2 : ((a/2^32)*(b/2^32) + (a/2^32)*(b%2^32)/2^32
      + (a%2^32)*(b/2^32)/2^32) % 2^64
      = (a/2^32)*(b/2^32) + (a/2^32)*(b%2^32)/2^32
        + (a%2^32)*(b/2^32)/2^32 := Nat.mod_eq_of_lt (by omega)
  have hbnd2 : (a/2^32)*(b/2^32) + (a/2^32)*(b%2^32)/2^32
      + (a%2^32)*(b/2^32)/2^32
      + (a%2^32*(b%2^32)/2^32 + (a/2^32)*(b%2^32)%2^32
          + (a%2^32)*(b/2^32)%2^32)/2^32 < 2^64 := by
    rw [hid]; exact hbnd
  simp only [ma1, ma2, mb1, mb2]
  exact Nat.mod_eq_of_lt hbnd2

/-- The architectural reading of UMULH: the high 64 bits of the exact 128-bit
product of the two register values. -/
theorem arm64MulUmulhHighWordToNat (lhs rhs : BitVec 64) :
    (BitVec.setWidth 64
        (((lhs.setWidth 128) * (rhs.setWidth 128)) >>> 64)).toNat
      = (lhs.toNat * rhs.toNat) / 2^64 := by
  have h1 : lhs.toNat % 2^128 = lhs.toNat :=
    Nat.mod_eq_of_lt (by have := lhs.isLt; omega)
  have h2 : rhs.toNat % 2^128 = rhs.toNat :=
    Nat.mod_eq_of_lt (by have := rhs.isLt; omega)
  simp only [BitVec.toNat_setWidth, BitVec.toNat_ushiftRight, BitVec.toNat_mul]
  rw [h1, h2]
  exact arm64MulNatShift lhs.toNat rhs.toNat lhs.isLt rhs.isLt

/-- The UMULH ladder equals the exact 128-bit product's high word. The two
readings are compared through their `Nat` values, so neither is defined in terms
of the other. -/
theorem arm64MulUmulhLadderEqHighWord (lhs rhs : BitVec 64) :
    arm64MulUmulhAlg lhs rhs =
      BitVec.setWidth 64 (((lhs.setWidth 128) * (rhs.setWidth 128)) >>> 64) := by
  have hlr : arm64MulUmulhAlg lhs rhs
      = arm64MulUmulhAlg (BitVec.ofNat 64 lhs.toNat) (BitVec.ofNat 64 rhs.toNat) := by
    rw [BitVec.ofNat_toNat, BitVec.setWidth_eq,
        BitVec.ofNat_toNat, BitVec.setWidth_eq]
  apply BitVec.eq_of_toNat_eq
  rw [hlr, arm64MulUmulhAlgToNat lhs.toNat rhs.toNat lhs.isLt rhs.isLt,
      arm64MulUmulhNatAlg,
      arm64MulUmulhNat lhs.toNat rhs.toNat lhs.isLt rhs.isLt,
      arm64MulUmulhHighWordToNat]

/-- Independent statement of the 32-bit sign extension `SMADDL` reads its
operands through: the low word masked out, with the sign bit replicated over the
upper half. -/
def arm64MulSignExt32Spec (v : BitVec 64) : BitVec 64 :=
  if v &&& 0x80000000 = 0 then v &&& 0xffffffff
  else (v &&& 0xffffffff) ||| 0xffffffff00000000

/-- The independent sign-extension statement is the library sign extension of
the low word. The case split is required: `bv_decide` alone does not discharge
the sign-replicating branch within budget. -/
theorem arm64MulSignExt32SpecEq (v : BitVec 64) :
    BitVec.signExtend 64 (v.setWidth 32) = arm64MulSignExt32Spec v := by
  unfold arm64MulSignExt32Spec
  by_cases h : v &&& 0x80000000 = 0 <;> bv_decide

/-- Independent statement of the eight AArch64 multiply-family value formulas.
The long arms widen the low 32 bits of both operands; UDIV states the
architectural divide-by-zero result; MSUB is the two's-complement addend plus
complement of the product; UMULH is the exact 128-bit product's high word. -/
def arm64MulValueSpec (op : Mul) (lhs rhs addend : BitVec 64) : BitVec 64 :=
  match op with
  | .madd => lhs * rhs + addend
  | .msub => addend + ~~~(lhs * rhs) + 1
  | .mul => lhs * rhs
  | .umull => (lhs.setWidth 32).setWidth 64 * (rhs.setWidth 32).setWidth 64
  | .udiv => if rhs = 0 then 0 else lhs / rhs
  | .umulh => BitVec.setWidth 64 (((lhs.setWidth 128) * (rhs.setWidth 128)) >>> 64)
  | .umaddl =>
      (lhs.setWidth 32).setWidth 64 * (rhs.setWidth 32).setWidth 64 + addend
  | .smaddl => arm64MulSignExt32Spec lhs * arm64MulSignExt32Spec rhs + addend

set_option maxHeartbeats 1000000 in
/-- The generated multiply contract agrees with the independent statement for all
eight operations and all operand values. -/
theorem arm64_mul_refines (op : Mul) (lhs rhs addend : BitVec 64) :
    GeneratedArm64Mul.value op lhs rhs addend =
      arm64MulValueSpec op lhs rhs addend := by
  cases op
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec]
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec]
    bv_decide
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec]
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec]
    bv_decide
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec]
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec, arm64MulUmulhAlg]
    exact arm64MulUmulhLadderEqHighWord lhs rhs
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec]
    bv_decide
  · simp only [GeneratedArm64Mul.value, arm64MulValueSpec,
      arm64MulSignExt32SpecEq]

/-- C hands the multiply result to the width-narrowing register write. Narrowing
commutes with the refinement, so the generated contract followed by the
generated width write is the independent statement followed by the same write. -/
theorem arm64_mul_width_refines (op : Mul) (lhs rhs addend : BitVec 64)
    (width : Width) :
    narrow (GeneratedArm64Mul.value op lhs rhs addend) width =
      narrow (arm64MulValueSpec op lhs rhs addend) width := by
  rw [arm64_mul_refines]

/-- The NZCV transition of a multiply op: the identity. The generated flag
contract models only the ADD, SUB and logical families, so the multiply handler
threads the incoming flag state through unchanged and the C macro that
implements this contract writes no flag register. -/
def arm64MulFlagsSpec (op : Mul) (_lhs _rhs _addend : BitVec 64) (_width : Width)
    (nzcv : GeneratedArm64Flags.Flags) : GeneratedArm64Flags.Flags :=
  match op with
  | .madd => nzcv
  | .msub => nzcv
  | .mul => nzcv
  | .umull => nzcv
  | .udiv => nzcv
  | .umulh => nzcv
  | .umaddl => nzcv
  | .smaddl => nzcv

/-- Every multiply op leaves NZCV untouched. -/
theorem arm64_mul_flags_unchanged (op : Mul) (lhs rhs addend : BitVec 64)
    (width : Width) (nzcv : GeneratedArm64Flags.Flags) :
    arm64MulFlagsSpec op lhs rhs addend width nzcv = nzcv := by
  cases op <;> rfl

/-- Every multiply opcode of the generated table is inside the numeric label
range `0U..64U` spanned by the shared C macro, so a valid `Mul` always reaches
its own case arm and only a code outside the table reaches the unsupported arm. -/
theorem arm64_mul_code_in_range (op : Mul) :
    GeneratedArm64Mul.code op < 65 := by
  cases op <;> decide

/-- The generated code dispatch: the eight multiply mnemonics map onto the eight
ARM64_OP_* opcode numbers the C macro switches on. -/
theorem arm64_mul_code_dispatch :
    GeneratedArm64Mul.code .madd = 10 ∧
    GeneratedArm64Mul.code .msub = 11 ∧
    GeneratedArm64Mul.code .mul = 12 ∧
    GeneratedArm64Mul.code .umull = 13 ∧
    GeneratedArm64Mul.code .udiv = 14 ∧
    GeneratedArm64Mul.code .umulh = 46 ∧
    GeneratedArm64Mul.code .umaddl = 59 ∧
    GeneratedArm64Mul.code .smaddl = 64 := by
  decide

/-- Canonical example: MADD multiplies and adds the accumulator. -/
theorem arm64_madd_example :
    arm64MulValueSpec .madd 3 4 5 = 17 := by
  native_decide

/-- Canonical example: MSUB subtracts the product from the accumulator. -/
theorem arm64_msub_example :
    arm64MulValueSpec .msub 3 4 5 = 0xfffffffffffffff9 := by
  native_decide

/-- Canonical example: UMULL keeps only the low 32 bits of each operand, so the
64-bit product of two all-ones words is `2^33 - 2`. -/
theorem arm64_umull_example :
    arm64MulValueSpec .umull 0xffffffffffffffff 2 0 = 0x1fffffffe := by
  native_decide

/-- Canonical example: UMADDL widens both low words and adds the accumulator. -/
theorem arm64_umaddl_example :
    arm64MulValueSpec .umaddl 0xffffffff 0xffffffff 1 =
      0xfffffffe00000002 := by
  native_decide

/-- Canonical example: SMADDL sign-extends both low words, so `0xffffffff` is
`-1` and the doubled product is `-2`. -/
theorem arm64_smaddl_example :
    arm64MulValueSpec .smaddl 0xffffffff 2 0 = 0xfffffffffffffffe := by
  native_decide

/-- Canonical example: dividing by zero yields zero rather than trapping. -/
theorem arm64_udiv_zero_example :
    arm64MulValueSpec .udiv 7 0 0 = 0 ∧
    arm64MulValueSpec .udiv 100 7 0 = 14 := by
  native_decide

/-- Canonical example: UMULH of two all-ones words is the high half of
`(2^64 - 1)^2`, i.e. `2^64 - 2`. -/
theorem arm64_umulh_example :
    arm64MulValueSpec .umulh 0xffffffffffffffff 0xffffffffffffffff 0 =
      0xfffffffffffffffe := by
  native_decide

/-- Canonical example: MUL writes the low half of the 64-bit product. -/
theorem arm64_mul_example :
    arm64MulValueSpec .mul 0x100000000 3 0 = 0x300000000 := by
  native_decide

end KProgFormal
