import KProgFormal.GeneratedArm64Csel
import KProgFormal.GeneratedArm64Cond
import KProgFormal.GeneratedArm64Flags

namespace KProgFormal

open KProgFormal.GeneratedArm64Csel (Csel value)

/-- Independent statement of the AArch64 conditional-select value as a bit-mask
mux: the all-ones mask when the condition holds, the all-zeros mask otherwise,
selecting `first` or `second` respectively. This is structurally separate from
the generated C ternary, so the refinement relates two different formulations of
the selection. -/
def arm64CselMux (taken : Bool) (first second : BitVec 64) : BitVec 64 :=
  let m : BitVec 64 := if taken then ~~~(0 : BitVec 64) else 0
  (first &&& m) ||| (second &&& ~~~m)

/-- Independent statement of the eight AArch64 conditional-select formulas. Each
arm names its two candidate values; CSET/CSETM have constant candidates, CINC/
CSINC and CSNEG have arithmetic candidates, and CINV/CSINV have complemented
candidates. -/
def arm64CselValueSpec (op : Csel) (taken : Bool) (src src2 : BitVec 64) :
    BitVec 64 :=
  match op with
  | .csel => arm64CselMux taken src src2
  | .cinc => arm64CselMux taken (src + 1) src
  | .cset => arm64CselMux taken 1 0
  | .csetm => arm64CselMux taken (~~~(0 : BitVec 64)) 0
  | .cinv => arm64CselMux taken (~~~src) src
  | .csinv => arm64CselMux taken src (~~~src2)
  | .csinc => arm64CselMux taken src (src2 + 1)
  | .csneg => arm64CselMux taken src (-src2)

/-- The generated conditional-select contract agrees with the independent
bit-mask mux statement for all eight operations and both condition outcomes. -/
theorem arm64_csel_refines (op : Csel) (taken : Bool) (src src2 : BitVec 64) :
    value op taken src src2 = arm64CselValueSpec op taken src src2 := by
  cases op <;>
    simp only [value, arm64CselValueSpec, arm64CselMux] <;>
    (cases taken <;> bv_decide)

/-- Every conditional-select opcode of the generated table is inside the numeric
label range spanned by the shared C macro: the eight opcodes are all at or below
`69U`, so a valid `Csel` always reaches its own case arm and only a code outside
the table reaches the unsupported arm. -/
theorem arm64_csel_code_in_range (op : Csel) :
    GeneratedArm64Csel.code op < 70 := by
  cases op <;> decide

/-- The generated code dispatch: the eight mnemonics map onto the eight
ARM64_OP_* opcode numbers the C macro switches on. -/
theorem arm64_csel_code_dispatch :
    GeneratedArm64Csel.code .csel = 28 ∧
    GeneratedArm64Csel.code .cinc = 29 ∧
    GeneratedArm64Csel.code .cset = 30 ∧
    GeneratedArm64Csel.code .cinv = 52 ∧
    GeneratedArm64Csel.code .csinv = 61 ∧
    GeneratedArm64Csel.code .csinc = 62 ∧
    GeneratedArm64Csel.code .csetm = 68 ∧
    GeneratedArm64Csel.code .csneg = 69 := by
  decide

/-- The NZCV transition of a conditional-select op: the identity. The family
reads flags but writes none, so the C handler threads the incoming flag state
through unchanged. -/
def arm64CselFlagsSpec (op : Csel) (_taken : Bool) (_src _src2 : BitVec 64)
    (nzcv : GeneratedArm64Flags.Flags) : GeneratedArm64Flags.Flags :=
  match op with
  | .csel => nzcv
  | .cinc => nzcv
  | .cset => nzcv
  | .csetm => nzcv
  | .cinv => nzcv
  | .csinv => nzcv
  | .csinc => nzcv
  | .csneg => nzcv

/-- Every conditional-select op leaves NZCV untouched. -/
theorem arm64_csel_flags_unchanged (op : Csel) (taken : Bool)
    (src src2 : BitVec 64) (nzcv : GeneratedArm64Flags.Flags) :
    arm64CselFlagsSpec op taken src src2 nzcv = nzcv := by
  cases op <;> rfl

/-- The composition the C handler uses: taking the condition result from the
generated condition contract (the `KPROG_ARM64_EVAL_COND` predicate) selects the
same value as taking it from the independent architectural condition semantics.
This ties the conditional-select refinement to the already-proven condition
contract rather than restating it. -/
theorem arm64_csel_cond_refines (op : Csel) (n z c v : Bool)
    (cond : GeneratedArm64Cond.Cond) (src src2 : BitVec 64) :
    value op (GeneratedArm64Cond.eval n z c v cond) src src2 =
      arm64CselValueSpec op (GeneratedArm64Cond.eval n z c v cond) src src2 := by
  rw [arm64_csel_refines]

/-- Canonical example: CSEL on a taken condition picks the first source. -/
theorem arm64_csel_taken_example :
    arm64CselValueSpec .csel true 0x11 0x22 = 0x11 := by
  native_decide

/-- Canonical example: CSEL on an untaken condition picks the second source. -/
theorem arm64_csel_untaken_example :
    arm64CselValueSpec .csel false 0x11 0x22 = 0x22 := by
  native_decide

/-- Canonical example: CINC on a taken condition increments the source. -/
theorem arm64_cinc_example :
    arm64CselValueSpec .cinc true 0x41 0x0 = 0x42 := by
  native_decide

/-- Canonical example: CSET yields one on a taken condition. -/
theorem arm64_cset_example :
    arm64CselValueSpec .cset true 0x0 0x0 = 0x1 := by
  native_decide

/-- Canonical example: CSETM yields all ones on a taken condition. -/
theorem arm64_csetm_example :
    arm64CselValueSpec .csetm true 0x0 0x0 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: CINV complements the source on a taken condition. -/
theorem arm64_cinv_example :
    arm64CselValueSpec .cinv true 0x0 0x0 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: CSINV complements the second source on an untaken
condition. -/
theorem arm64_csinv_example :
    arm64CselValueSpec .csinv false 0x0 0x0 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: CSNEG negates the second source on an untaken
condition. -/
theorem arm64_csneg_example :
    arm64CselValueSpec .csneg false 0x0 0x2 = 0xfffffffffffffffe := by
  native_decide

end KProgFormal
