import KProgFormal.ClightRefinement.Arm64CompareFlagArithmetic
import KProgFormal.ClightRefinement.Arm64CompareCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.FlagBytes

/-- Project imported native flags in the actual source store order Z,N,C,V. -/
def bits (x y : BitVec 64) (i : Fin 4) : BitVec 1 :=
  let p := (AddWithCarry x (~~~y) (1#1)).snd
  [p.z,p.n,p.c,p.v][i]
def flag (i : Fin 4) : PFlag := [.Z,.N,.C,.V][i]
private theorem four_cases : ∀ i : Fin 4, i=0 ∨ i=1 ∨ i=2 ∨ i=3 := by decide +kernel

private theorem normalized (x y : BitVec 64) (i : Fin 4) :
    Call.flagValue x y i = Stores.value x y (x-y) (9223372036854775808#64) i := by
  have mask : Arm64Modified.Modifier.mask false = BitVec.allOnes 64 := by decide +kernel
  simp only [Call.flagValue,Math.left,Math.right,Math.result,Math.mask,Body.rhsValue,
    Arm64Modified.Modifier.result,mask,BitVec.and_allOnes,Math.sign,Bool.false_eq_true,ite_false]
  rfl

private theorem eq_byte (x y : BitVec 64) :
    CC.Val.ofBool (CC.Integers.Int64.cmpu .Ceq x y) =
      .Vint ((if x=y then 1#1 else 0#1).setWidth 32) := by
  change CC.Val.ofBool (x == y) = _
  by_cases same : x=y <;>
    simp [same,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
      CC.Integers.Int.one,CC.Integers.Int.zero,CC.Integers.MI.one,CC.Integers.MI.zero]

private theorem ne_byte (x : BitVec 64) :
    CC.Val.ofBool (CC.Integers.Int64.cmpu .Cne x 0) =
      .Vint ((if x ≠ 0 then 1#1 else 0#1).setWidth 32) := by
  change CC.Val.ofBool (!(x == 0)) = _
  by_cases same : x=0#64 <;>
    simp [same,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
      CC.Integers.Int.one,CC.Integers.Int.zero,CC.Integers.MI.one,CC.Integers.MI.zero]

private theorem ge_byte (x y : BitVec 64) :
    CC.Val.ofBool (CC.Integers.Int64.cmpu .Cge x y) =
      .Vint ((if x.toNat < y.toNat then 0#1 else 1#1).setWidth 32) := by
  change CC.Val.ofBool (!decide (x.toNat < y.toNat)) = _
  by_cases less : x.toNat < y.toNat <;>
    simp [less,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
      CC.Integers.Int.one,CC.Integers.Int.zero,CC.Integers.MI.one,CC.Integers.MI.zero]

/-- Every actual source flag-byte value equals the imported native one-bit
flag zero-extended to the same unsigned scalar view. No flag/readback premise. -/
theorem source_value (x y : BitVec 64) (i : Fin 4) :
    Call.flagValue x y i = .Vint ((bits x y i).setWidth 32) := by
  rw [normalized]
  rcases four_cases i with rfl|rfl|rfl|rfl
  · change CC.Val.ofBool (CC.Integers.Int64.cmpu .Ceq x y) =
      .Vint (((AddWithCarry x (~~~y) (1#1)).snd.z).setWidth 32)
    rw [FlagArithmetic.zero]
    exact eq_byte x y
  · change CC.Val.ofBool (CC.Integers.Int64.cmpu .Cne ((x-y) &&& (9223372036854775808#64)) 0) =
      .Vint (((AddWithCarry x (~~~y) (1#1)).snd.n).setWidth 32)
    rw [FlagArithmetic.negative_mask]
    exact ne_byte _
  · change CC.Val.ofBool (CC.Integers.Int64.cmpu .Cge x y) =
      .Vint (((AddWithCarry x (~~~y) (1#1)).snd.c).setWidth 32)
    rw [FlagArithmetic.carry]
    exact ge_byte x y
  · change CC.Val.ofBool (CC.Integers.Int64.cmpu .Cne
      (((x ^^^ y) &&& (x ^^^ (x-y))) &&& (9223372036854775808#64)) 0) =
      .Vint (((AddWithCarry x (~~~y) (1#1)).snd.v).setWidth 32)
    rw [FlagArithmetic.overflow_mask]
    exact ne_byte _

/-- The flag bits read from the proven native update are exactly those used
above, with the source Z,N,C,V permutation retained. -/
theorem native_bits (s : Reference.AArch64.State) (i : Fin 4) :
    read_flag (flag i) (Native.after s).machine =
      bits (Reference.AArch64.gpr s 4) (Reference.AArch64.gpr s 1) i := by
  rcases four_cases i with rfl|rfl|rfl|rfl
  · change read_flag .Z (Native.after s).machine =
      (AddWithCarry (Reference.AArch64.gpr s 4) (~~~Reference.AArch64.gpr s 1) (1#1)).snd.z
    simp [Native.after,write_pstate,read_flag,write_pc,r_of_w_same,r_of_w_different]
  · change read_flag .N (Native.after s).machine =
      (AddWithCarry (Reference.AArch64.gpr s 4) (~~~Reference.AArch64.gpr s 1) (1#1)).snd.n
    simp [Native.after,write_pstate,read_flag,write_pc,r_of_w_same,r_of_w_different]
  · change read_flag .C (Native.after s).machine =
      (AddWithCarry (Reference.AArch64.gpr s 4) (~~~Reference.AArch64.gpr s 1) (1#1)).snd.c
    simp [Native.after,write_pstate,read_flag,write_pc,r_of_w_same,r_of_w_different]
  · change read_flag .V (Native.after s).machine =
      (AddWithCarry (Reference.AArch64.gpr s 4) (~~~Reference.AArch64.gpr s 1) (1#1)).snd.v
    simp [Native.after,write_pstate,read_flag,write_pc,r_of_w_same,r_of_w_different]

/-- The actual C flag values match the actual mature CMP update. -/
theorem native_value (s : Reference.AArch64.State) (i : Fin 4) :
    Call.flagValue (Reference.AArch64.gpr s 4) (Reference.AArch64.gpr s 1) i =
      .Vint ((read_flag (flag i) (Native.after s).machine).setWidth 32) := by
  rw [source_value,native_bits]

end KProgFormal.ClightRefinement.Arm64Compare.FlagBytes
