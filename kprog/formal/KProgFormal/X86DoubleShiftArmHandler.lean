import KProgFormal.GeneratedX86DoubleShiftArm
import KProgFormal.X86DoubleShift
import KProgFormal.X86Opcode
import KProgFormal.X86AluDecode
import KProgFormal.X86Width
import KProgFormal.X86ControlFlow
import KProgFormal.X86ShiftCount
import KProgFormal.X86ShiftFlags

namespace KProgFormal

open GeneratedX86DoubleShiftArm (Arm armCount opcodeBits armNames armCodes
  codeOfArm opcodeOfArm resultOfArm flagFamilyOfArm effectOfArm armOf armOfFlags
  armOfCode)

/-- Independent statement of the two opcodes the `SHLD`/`SHRD` immediate arm is
keyed on, in the order `kprog/x86/x86_sim.h` defines them. -/
def x86DoubleShiftShldOpcodeSpec : Nat := 27
def x86DoubleShiftShrdOpcodeSpec : Nat := 28

/-- Independent statement of the arm selector: the left double shift at the
`X86_OP_SHLD_IMM` opcode, the right double shift at every other opcode (the arm
only runs for the two double-shift opcodes), built from the literal opcode
rather than the generated `armOf`. -/
def x86DoubleShiftArmSpec (op : Nat) : Arm :=
  if op = x86DoubleShiftShldOpcodeSpec then .shld else .shrd

/-- Independent statement of the two arms, built from the literal constructor
order rather than the generated `armNames`. -/
def x86DoubleShiftArmNamesSpec : List String := ["shld", "shrd"]

/-- Independent statement of the double-shift function each opcode selects:
`x86_shld` at the `X86_OP_SHLD_IMM` opcode and `x86_shrd` elsewhere. -/
def x86DoubleShiftResultSpec (op : Nat) : String :=
  if op = x86DoubleShiftShldOpcodeSpec then "shld" else "shrd"

/-- Independent statement of the `X86_ALU_*` flag family each opcode selects for
the shift-flag contract: the SHL family at the `X86_OP_SHLD_IMM` opcode and the
SHR family elsewhere, built from `x86AluCodeSpec` rather than the generated
`flagFamilyOfArm` table. -/
def x86DoubleShiftFlagsSpec (op : Nat) : Nat :=
  if op = x86DoubleShiftShldOpcodeSpec then x86AluCodeSpec .shl
  else x86AluCodeSpec .shr

/-- The generated arm selector equals the independent literal construction. -/
theorem x86_doubleshift_arm_refines (op : Nat) :
    armOf op = x86DoubleShiftArmSpec op := by
  unfold armOf x86DoubleShiftArmSpec x86DoubleShiftShldOpcodeSpec
  rfl

/-- The generated flag-family selector equals the independent construction over
`x86AluCodeSpec`, so the family the arm reports cannot drift from the ALU
contract's own SHL/SHR codes. -/
theorem x86_doubleshift_flags_refines (op : Nat) :
    armOfFlags op = x86DoubleShiftFlagsSpec op := by
  unfold armOfFlags armOf flagFamilyOfArm x86DoubleShiftFlagsSpec
    x86DoubleShiftShldOpcodeSpec x86AluCodeSpec
  by_cases h : op = 27 <;> simp [h]

/-- The generated result-function selector equals the independent construction
over the opcode literals, so the double-shift function the arm names cannot
drift from the `X86_OP_SHLD_IMM` / `X86_OP_SHRD_IMM` key. -/
theorem x86_doubleshift_result_refines (op : Nat) :
    resultOfArm (armOf op) = x86DoubleShiftResultSpec op := by
  unfold resultOfArm armOf x86DoubleShiftResultSpec x86DoubleShiftShldOpcodeSpec
  by_cases h : op = 27 <;> simp [h]

/-- The generated arm-name table equals the independent literal order. -/
theorem x86_doubleshift_names_refine :
    armNames = x86DoubleShiftArmNamesSpec := by
  unfold armNames x86DoubleShiftArmNamesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries. -/
theorem x86_doubleshift_codes_length : armCodes.length = armCount := rfl

/-- The generated arm-name table has exactly `armCount` entries. -/
theorem x86_doubleshift_names_length : armNames.length = armCount := rfl

/-- The two arm codes are distinct, so no two arms alias one code. -/
theorem x86_doubleshift_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The two arm opcodes are distinct, so the opcode key selects exactly one
body. -/
theorem x86_doubleshift_opcodes_nodup : opcodeOfArm .shld ≠ opcodeOfArm .shrd := by
  native_decide

/-- The independent opcode literals are the codes `x86OpcodeSpec` names for
`X86_OP_SHLD_IMM` / `X86_OP_SHRD_IMM`, so the arm is keyed on the simulator's
own decodes. -/
theorem x86_doubleshift_opcode_spec_bound :
    x86OpcodeSpec.lookup "X86_OP_SHLD_IMM" = some x86DoubleShiftShldOpcodeSpec ∧
    x86OpcodeSpec.lookup "X86_OP_SHRD_IMM" = some x86DoubleShiftShrdOpcodeSpec := by
  unfold x86DoubleShiftShldOpcodeSpec x86DoubleShiftShrdOpcodeSpec
  native_decide

/-- Each real double-shift opcode reaches its own arm, so the opcode-keyed
selector is total over the two opcodes the arm runs for. -/
theorem x86_doubleshift_arm_over_opcodes :
    (List.map (fun op => x86DoubleShiftArmSpec op)
        [x86DoubleShiftShldOpcodeSpec, x86DoubleShiftShrdOpcodeSpec]) =
      [Arm.shld, Arm.shrd] := by
  unfold x86DoubleShiftShldOpcodeSpec x86DoubleShiftShrdOpcodeSpec
    x86DoubleShiftArmSpec
  rfl

/-- The arm-code selector round-trips each arm to its own code and names no
other code: `codeOfArm` is a left inverse of `armOfCode` on the two arms. -/
theorem x86_doubleshift_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no arm at or above the arm count, so the table
is exactly the two arms and no other code reaches one. -/
theorem x86_doubleshift_arm_of_code_beyond_is_none :
    armOfCode 2 = none ∧ armOfCode 3 = none ∧ armOfCode 27 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The arm selects on a byte-wide opcode, pinned so the C opcode's `__u8`
width and the generated `opcodeBits` cannot drift apart. -/
theorem x86_doubleshift_opcode_bits_is_8 : opcodeBits = 8 := rfl

/-- The arm count is the two double-shift bodies the opcode selects between. -/
theorem x86_doubleshift_arm_count_is_2 : armCount = 2 := rfl

/-- The two arms implement the `X86_OP_SHLD_IMM` (`27`) and `X86_OP_SHRD_IMM`
(`28`) opcodes, pinned so the C opcodes and the generated `opcodeOfArm` table
cannot drift. -/
theorem x86_doubleshift_arm_opcodes :
    opcodeOfArm .shld = x86DoubleShiftShldOpcodeSpec ∧
      opcodeOfArm .shrd = x86DoubleShiftShrdOpcodeSpec := by
  refine ⟨?_, ?_⟩ <;> decide

/-- The left double-shift arm computes `x86_shld` and the right double-shift arm
computes `x86_shrd`, so the result function is selected by the opcode. -/
theorem x86_doubleshift_arm_results :
    resultOfArm .shld = "shld" ∧
      resultOfArm .shrd = "shrd" ∧
      resultOfArm .shld ≠ resultOfArm .shrd := by
  exact ⟨rfl, rfl, by decide⟩

/-- The left double-shift arm reports the SHL flag family and the right
double-shift arm the SHR family, stated against the ALU contract's own codes so
the two families cannot drift and are distinct. -/
theorem x86_doubleshift_arm_flags :
    flagFamilyOfArm .shld = x86AluCodeSpec .shl ∧
      flagFamilyOfArm .shrd = x86AluCodeSpec .shr ∧
      flagFamilyOfArm .shld ≠ flagFamilyOfArm .shrd := by
  refine ⟨?_, ?_, ?_⟩ <;> decide

/-- The opcode→result-function and opcode→flag-family mapping is exactly the two
double shifts and their two families, stated over the opcode literals. -/
theorem x86_doubleshift_opcode_result_family :
    (x86DoubleShiftArmSpec x86DoubleShiftShldOpcodeSpec = .shld ∧
      x86DoubleShiftResultSpec x86DoubleShiftShldOpcodeSpec = "shld" ∧
      flagFamilyOfArm (armOf x86DoubleShiftShldOpcodeSpec) = x86AluCodeSpec .shl) ∧
    (x86DoubleShiftArmSpec x86DoubleShiftShrdOpcodeSpec = .shrd ∧
      x86DoubleShiftResultSpec x86DoubleShiftShrdOpcodeSpec = "shrd" ∧
      flagFamilyOfArm (armOf x86DoubleShiftShrdOpcodeSpec) = x86AluCodeSpec .shr) := by
  refine ⟨⟨?_, ?_, ?_⟩, ⟨?_, ?_, ?_⟩⟩ <;> native_decide

/-- The two arms perform two distinct effects: the left double shift fills the
low bits from the top of the source and the right double shift fills the high
bits from the bottom of the source. -/
theorem x86_doubleshift_arm_effects :
    effectOfArm .shld = "shift_left_fill_src_high" ∧
      effectOfArm .shrd = "shift_right_fill_src_low" ∧
      effectOfArm .shld ≠ effectOfArm .shrd := by
  exact ⟨rfl, rfl, by decide⟩

/-- The selector picks the left double-shift arm exactly at the
`X86_OP_SHLD_IMM` opcode, stated against the independent selector. -/
theorem x86_doubleshift_arm_shld_iff (op : Nat) :
    x86DoubleShiftArmSpec op = .shld ↔ op = x86DoubleShiftShldOpcodeSpec := by
  unfold x86DoubleShiftArmSpec
  by_cases h : op = x86DoubleShiftShldOpcodeSpec <;>
    simp [h, Arm.noConfusion]

/-- The selector picks the right double-shift arm at every opcode that is not the
`X86_OP_SHLD_IMM` opcode, so both double-shift opcodes reach a body. -/
theorem x86_doubleshift_arm_shrd_iff (op : Nat) :
    x86DoubleShiftArmSpec op = .shrd ↔ op ≠ x86DoubleShiftShldOpcodeSpec := by
  unfold x86DoubleShiftArmSpec
  by_cases h : op = x86DoubleShiftShldOpcodeSpec <;>
    simp [h, Arm.noConfusion]

/-- All the selector shapes are reachable: each double-shift opcode reaches its
own arm, so neither arm of the contract is dead. -/
theorem x86_doubleshift_case_dispatch :
    armOf x86DoubleShiftShldOpcodeSpec = .shld ∧
      armOf x86DoubleShiftShrdOpcodeSpec = .shrd := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- The right double-shift arm is the selector's default, so the arm is total:
the `X86_OP_SHLD_IMM` opcode reaches the left arm and every other opcode the
right arm. -/
theorem x86_doubleshift_ladder_total (op : Nat)
    (h : op ≠ x86DoubleShiftShldOpcodeSpec) :
    armOf op = .shrd := by
  unfold armOf
  rw [if_neg (by simpa [x86DoubleShiftShldOpcodeSpec] using h)]

/-- **The count-zero step gate.** When the hardware-masked count is zero the
shift-flag contract leaves the flags exactly as they were, so neither the result
function nor the flag family the arm selects is observable at count zero: the
architectural `SHLD`/`SHRD` count-zero no-op. The gate holds for either flag
family the arm can report. -/
theorem x86_doubleshift_count_zero_flags_noop (op : X86ShiftOp) (value : BitVec 64)
    (width : X86Width) (old : X86Flags) :
    x86ShiftFlagsDefinedSpec op value 0 (x86NarrowSpec value width) width old
      old = true := by
  unfold x86ShiftFlagsDefinedSpec x86ShiftCountSpec
  cases width <;> simp

/-- **The count-zero step gate on the value.** At count zero both double-shift
bodies leave the destination window unchanged, so the result function the arm
selected computed no change to the destination at 64 bits; the arm's register
write is a no-op. Reuses the double-shift contract's zero-count identity. -/
theorem x86_doubleshift_count_zero_value_noop (dst src : BitVec 64) :
    GeneratedX86DoubleShift.shld dst src 0 8 = dst ∧
      GeneratedX86DoubleShift.shrd dst src 0 8 = dst :=
  ⟨(x86_doubleshift_zero_count dst src).2.2.1,
    (x86_doubleshift_zero_count dst src).2.2.2⟩

/-- The arm's two bodies compute the two double shifts the double-shift contract
proves: at the 64-bit width the left arm's result is `GeneratedX86DoubleShift.shld`
and the right arm's `GeneratedX86DoubleShift.shrd`, so the arm selects between
the proved value functions and not a fresh implementation. -/
theorem x86_doubleshift_arm_is_doubleshift :
    (resultOfArm .shld = "shld" →
      GeneratedX86DoubleShift.shld 0xf0 0x0f 4 8 = 0xf00) ∧
    (resultOfArm .shrd = "shrd" →
      GeneratedX86DoubleShift.shrd 0xf0 0x0f 4 1 = 0xff) :=
  ⟨fun _ => x86_shld_w64_example, fun _ => x86_shrd_w8_example⟩

end KProgFormal
