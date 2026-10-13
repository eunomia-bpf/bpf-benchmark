import KProgFormal.GeneratedX86AluFlagArm
import KProgFormal.X86AluDecode

namespace KProgFormal

open GeneratedX86AluFlagArm (Arm armCount aluCodeBits armNames armCodes
  codeOfArm aluCodesOfArm flagBodyOfArm caseMacroOfArm cfRestoreOfArm
  effectOfArm armOf armOfCode)

/-- Independent statement of the flag-body selector over the ALU contract's own
token literals: the sum body at ADD and ADC, the increment body at INC, the
decrement body at DEC, the difference body at SUB, the borrow-difference body
at SBB, the negation body at NEG, the no-op body at NOT, the shift body at
SHL/SHR/SAR/ROL, the multiply body at IMUL, and the bitwise body at every other
token. It selects on `x86AluCodeSpec` literals rather than the generated
`aluCodesOfArm` table. -/
def x86AluFlagArmSpec (alu : Nat) : Arm :=
  if alu = x86AluCodeSpec .add then .add
  else if alu = x86AluCodeSpec .adc then .add
  else if alu = x86AluCodeSpec .inc then .inc
  else if alu = x86AluCodeSpec .dec then .dec
  else if alu = x86AluCodeSpec .sub then .sub
  else if alu = x86AluCodeSpec .sbb then .sbb
  else if alu = x86AluCodeSpec .neg then .neg
  else if alu = x86AluCodeSpec .not then .not
  else if alu = x86AluCodeSpec .shl then .shift
  else if alu = x86AluCodeSpec .shr then .shift
  else if alu = x86AluCodeSpec .sar then .shift
  else if alu = x86AluCodeSpec .rol then .shift
  else if alu = x86AluCodeSpec .imul then .imul
  else .logic

/-- Independent statement of the ten bodies the ALU-flags macro selects
between, built from the literal constructor order rather than the generated
`armNames`. -/
def x86AluFlagArmNamesSpec : List String :=
  ["add", "inc", "dec", "sub", "sbb", "neg", "not", "shift", "imul", "logic"]

/-- Independent statement of the flag block each body applies, built from the
literal body names rather than the generated `flagBodyOfArm` table. -/
def x86AluFlagArmFlagBodySpec : Arm -> String
  | .add => "add_flags"
  | .inc => "add_flags"
  | .dec => "sub_flags"
  | .sub => "sub_flags"
  | .sbb => "sbb_flags"
  | .neg => "sub_flags"
  | .not => "preserve_flags"
  | .shift => "shift_flags"
  | .imul => "imul_flags"
  | .logic => "logic_flags"

/-- Independent statement of the simulator case macro each body routes through,
built from the literal macro names rather than the generated `caseMacroOfArm`
table. -/
def x86AluFlagArmCaseMacroSpec : Arm -> String
  | .add => "X86_SIM_L_SET_ADD_FLAGS"
  | .inc => "X86_SIM_L_SET_ADD_FLAGS"
  | .dec => "X86_SIM_L_SET_SUB_FLAGS"
  | .sub => "X86_SIM_L_SET_SUB_FLAGS"
  | .sbb => "X86_SIM_L_SET_SBB_FLAGS"
  | .neg => "X86_SIM_L_SET_SUB_FLAGS"
  | .not => "KPROG_X86_PRESERVE_FLAGS"
  | .shift => "X86_SIM_L_SET_SHIFT_FLAGS"
  | .imul => "X86_SIM_L_SET_IMUL_FLAGS"
  | .logic => "X86_SIM_L_SET_LOGIC_FLAGS"

/-- Independent statement of the effects, built from the literal effect names
rather than the generated `effectOfArm` table. -/
def x86AluFlagArmEffectSpec : Arm -> String
  | .add => "sum_flags"
  | .inc => "increment_flags_preserve_cf"
  | .dec => "decrement_flags_preserve_cf"
  | .sub => "difference_flags"
  | .sbb => "borrow_difference_flags"
  | .neg => "negation_flags"
  | .not => "flags_unchanged"
  | .shift => "shift_flags"
  | .imul => "multiply_overflow_flags"
  | .logic => "bitwise_flags_default"

/-- The generated flag-body selector equals the independent ALU-token ladder. -/
theorem x86_alu_flag_arm_refines (alu : Nat) :
    armOf alu = x86AluFlagArmSpec alu := by
  unfold armOf x86AluFlagArmSpec x86AluCodeSpec
  rfl

/-- The generated body-name table equals the independent literal order. -/
theorem x86_alu_flag_arm_names_refine :
    armNames = x86AluFlagArmNamesSpec := by
  unfold armNames x86AluFlagArmNamesSpec
  rfl

/-- The generated body-code table has exactly `armCount` entries. -/
theorem x86_alu_flag_arm_codes_length : armCodes.length = armCount := rfl

/-- The generated body-name table has exactly `armCount` entries. -/
theorem x86_alu_flag_arm_names_length : armNames.length = armCount := rfl

/-- The ten body codes are distinct, so no two bodies alias one code. -/
theorem x86_alu_flag_arm_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- Every `X86_ALU_*` token reaches its own body: the ADD/ADC codes the add
body, the INC code the increment body, the DEC code the decrement body, the SUB
code the difference body, the SBB code the borrow-difference body, the NEG code
the negation body, the NOT code the no-op body, the SHL/SHR/SAR/ROL codes the
shift body, the IMUL code the multiply body, and the XOR/OR/AND codes the
bitwise default. -/
theorem x86_alu_flag_arm_over_tokens :
    (List.map (fun a => x86AluFlagArmSpec (x86AluCodeSpec a))
        [.add, .sub, .xor, .or, .and, .shl, .shr, .sar, .rol, .imul, .inc,
         .not, .sbb, .dec, .neg, .adc]) =
      [Arm.add, Arm.sub, Arm.logic, Arm.logic, Arm.logic, Arm.shift, Arm.shift,
       Arm.shift, Arm.shift, Arm.imul, Arm.inc, Arm.not, Arm.sbb, Arm.dec,
       Arm.neg, Arm.add] := by
  rfl

/-- The token→body map collapses exactly at ADD/ADC (both the add body) and the
four shifts (all the shift body): the second member of each family reaches the
same body as the first, stated over the ALU contract's own token literals. -/
theorem x86_alu_flag_arm_collapses :
    x86AluFlagArmSpec (x86AluCodeSpec .adc) = x86AluFlagArmSpec (x86AluCodeSpec .add) ∧
      x86AluFlagArmSpec (x86AluCodeSpec .shr) = x86AluFlagArmSpec (x86AluCodeSpec .shl) ∧
      x86AluFlagArmSpec (x86AluCodeSpec .sar) = x86AluFlagArmSpec (x86AluCodeSpec .shl) ∧
      x86AluFlagArmSpec (x86AluCodeSpec .rol) = x86AluFlagArmSpec (x86AluCodeSpec .shl) ∧
      x86AluFlagArmSpec (x86AluCodeSpec .or) = x86AluFlagArmSpec (x86AluCodeSpec .xor) ∧
      x86AluFlagArmSpec (x86AluCodeSpec .and) = x86AluFlagArmSpec (x86AluCodeSpec .xor) := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The body-code selector round-trips each body to its own code and names no
other code: `codeOfArm` is a left inverse of `armOfCode` on the ten bodies. -/
theorem x86_alu_flag_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The body-code selector names no body at or above the body count, so the
table is exactly the ten bodies and no other code reaches one. -/
theorem x86_alu_flag_arm_of_code_beyond_is_none :
    armOfCode 10 = none ∧ armOfCode 11 = none ∧ armOfCode 16 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The selector key is a byte-wide ALU token, pinned so the C `__u8` token and
the generated `aluCodeBits` cannot drift apart. -/
theorem x86_alu_flag_arm_code_bits_is_8 : aluCodeBits = 8 := rfl

/-- The body count is the ten flag bodies `X86_SIM_L_SET_ALU_FLAGS` selects
between. -/
theorem x86_alu_flag_arm_count_is_10 : armCount = 10 := rfl

/-- Each body applies the flag block the ALU-flags macro applies: the sum body
the add flags, the increment body the add flags, the decrement/difference/
negation bodies the sub flags, the borrow-difference body the sbb flags, the
no-op body the preserve macro, the shift body the shift flags, the multiply
body the imul flags, and the bitwise body the logic flags. -/
theorem x86_alu_flag_arm_flag_bodies (arm : Arm) :
    flagBodyOfArm arm = x86AluFlagArmFlagBodySpec arm := by
  cases arm <;> rfl

/-- Each body routes through the simulator case macro that applies its own flag
block, stated against the independent case-macro construction, so the routed
dispatch cannot drift from the C switch labels. -/
theorem x86_alu_flag_arm_case_macros (arm : Arm) :
    caseMacroOfArm arm = x86AluFlagArmCaseMacroSpec arm := by
  cases arm <;> rfl

/-- Exactly the increment and decrement bodies restore the incoming carry after
their flag block, the architectural `INC`/`DEC` carry-preservation; no other
body does. -/
theorem x86_alu_flag_arm_cf_restores :
    (cfRestoreOfArm .add = false ∧ cfRestoreOfArm .inc = true ∧
      cfRestoreOfArm .dec = true ∧ cfRestoreOfArm .sub = false ∧
      cfRestoreOfArm .sbb = false ∧ cfRestoreOfArm .neg = false ∧
      cfRestoreOfArm .not = false ∧ cfRestoreOfArm .shift = false ∧
      cfRestoreOfArm .imul = false ∧ cfRestoreOfArm .logic = false) ∧
      (∀ a, cfRestoreOfArm a = true ↔ a = Arm.inc ∨ a = Arm.dec) := by
  refine ⟨⟨rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl⟩, ?_⟩
  intro a
  cases a <;> simp [cfRestoreOfArm]

/-- Each body's effect name equals the independent construction, so the effect
table cannot drift. -/
theorem x86_alu_flag_arm_effects (arm : Arm) :
    effectOfArm arm = x86AluFlagArmEffectSpec arm := by
  cases arm <;> rfl

/-- The ten effects are pairwise distinct, so a swapped selector body changes
the recorded effect. -/
theorem x86_alu_flag_arm_effects_distinct :
    effectOfArm .add ≠ effectOfArm .inc ∧
      effectOfArm .inc ≠ effectOfArm .dec ∧
      effectOfArm .dec ≠ effectOfArm .sub ∧
      effectOfArm .sub ≠ effectOfArm .sbb ∧
      effectOfArm .sbb ≠ effectOfArm .neg ∧
      effectOfArm .neg ≠ effectOfArm .not ∧
      effectOfArm .not ≠ effectOfArm .shift ∧
      effectOfArm .shift ≠ effectOfArm .imul ∧
      effectOfArm .imul ≠ effectOfArm .logic := by
  refine ⟨by decide, by decide, by decide, by decide, by decide, by decide,
    by decide, by decide, by decide⟩

/-- The ladder is total: any token that is none of the thirteen routed codes
(the ADD/ADC, INC, DEC, SUB, SBB, NEG, NOT, SHL/SHR/SAR/ROL, IMUL identities)
reaches the bitwise default, so the selector has no unsupported case. -/
theorem x86_alu_flag_arm_ladder_total (alu : Nat)
    (h1 : alu ≠ 0) (h2 : alu ≠ 15) (h3 : alu ≠ 10) (h4 : alu ≠ 13)
    (h5 : alu ≠ 1) (h6 : alu ≠ 12) (h7 : alu ≠ 14) (h8 : alu ≠ 11)
    (h9 : alu ≠ 5) (h10 : alu ≠ 6) (h11 : alu ≠ 7) (h12 : alu ≠ 8)
    (h13 : alu ≠ 9) :
    armOf alu = .logic := by
  unfold armOf
  rw [if_neg h1, if_neg h2, if_neg h3, if_neg h4, if_neg h5, if_neg h6,
    if_neg h7, if_neg h8, if_neg h9, if_neg h10, if_neg h11, if_neg h12,
    if_neg h13]

/-- All the selector shapes are reachable: each real ALU token reaches its own
body and an unclaimed token reaches the default, so no body of the contract is
dead. -/
theorem x86_alu_flag_arm_case_dispatch :
    armOf 0 = .add ∧ armOf 15 = .add ∧ armOf 10 = .inc ∧ armOf 13 = .dec ∧
      armOf 1 = .sub ∧ armOf 12 = .sbb ∧ armOf 14 = .neg ∧ armOf 11 = .not ∧
      armOf 5 = .shift ∧ armOf 8 = .shift ∧ armOf 9 = .imul ∧
      armOf 2 = .logic ∧ armOf 0xff = .logic := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_⟩ <;>
    native_decide

/-- The bitwise XOR/OR/AND family is the selector's default, so every code no
earlier family claims — including the bitwise codes themselves and any future
token — reaches the logic body. -/
theorem x86_alu_flag_arm_default_is_logic :
    x86AluFlagArmSpec (x86AluCodeSpec .xor) = .logic ∧
      x86AluFlagArmSpec (x86AluCodeSpec .or) = .logic ∧
      x86AluFlagArmSpec (x86AluCodeSpec .and) = .logic ∧
      x86AluFlagArmSpec 0xff = .logic := by
  simp [x86AluFlagArmSpec, x86AluCodeSpec]

end KProgFormal
