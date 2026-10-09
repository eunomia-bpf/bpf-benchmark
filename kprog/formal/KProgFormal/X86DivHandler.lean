import KProgFormal.GeneratedX86Div
import KProgFormal.X86RegWrite
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Div (Arm armCount widthCodeBits opcode armNames armCodes
  codeOfArm widthCodeOfArm writeCountOfArm dividendHighOfArm highGateOfArm
  effectOfArm widthClassOfArm armOf armOfCode)

/-- Independent statement of the `X86_OP_DIV` case selector: the byte case at
the resolved 8-bit width code, the word case at the 16-bit code, the dword case
at the 32-bit code, and the qword case at every other code. It selects on the
width contract's own `x86WidthCodeSpec` literals rather than the generated
`widthCodeOfArm` table. -/
def x86DivArmSpec (width : Nat) : Arm :=
  if width = x86WidthCodeSpec .w8 then .b8
  else if width = x86WidthCodeSpec .w16 then .b16
  else if width = x86WidthCodeSpec .w32 then .b32
  else .b64

/-- Independent statement of the four cases the `X86_OP_DIV` arm selects
between, built from the literal constructor order rather than the generated
`armNames`. -/
def x86DivArmNamesSpec : List String := ["b8", "b16", "b32", "b64"]

/-- The generated case selector equals the independent width-code ladder. -/
theorem x86_div_arm_refines (width : Nat) :
    armOf width = x86DivArmSpec width := by
  unfold armOf x86DivArmSpec x86WidthCodeSpec
  rfl

/-- The generated case-name table equals the independent literal order. -/
theorem x86_div_names_refine : armNames = x86DivArmNamesSpec := by
  unfold armNames x86DivArmNamesSpec
  rfl

/-- The generated case-code table has exactly `armCount` entries. -/
theorem x86_div_codes_length : armCodes.length = armCount := rfl

/-- The generated case-name table has exactly `armCount` entries. -/
theorem x86_div_names_length : armNames.length = armCount := rfl

/-- The four case codes are distinct, so no two cases alias one code. -/
theorem x86_div_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- Every resolved width code reaches its own case: the byte code the byte
case, the 16-bit code the word case, the 32-bit code the dword case, and the
64-bit code the qword case. -/
theorem x86_div_arm_over_widths :
    (List.map (fun w => x86DivArmSpec (x86WidthCodeSpec w))
        [.w8, .w16, .w32, .w64]) =
      [Arm.b8, Arm.b16, Arm.b32, Arm.b64] := by
  rfl

/-- The case-code selector round-trips each case to its own code and names no
other code: `codeOfArm` is a left inverse of `armOfCode` on the four cases. -/
theorem x86_div_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The case-code selector names no case at or above the case count, so the
table is exactly the four cases and no other code reaches one. -/
theorem x86_div_arm_of_code_beyond_is_none :
    armOfCode 4 = none ∧ armOfCode 5 = none ∧ armOfCode 8 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The opcode the contract implements is the simulator's `X86_OP_DIV`
(`0x1a`), pinned so the C opcode and the generated `opcode` cannot drift. -/
theorem x86_div_opcode_is_0x1a : opcode = 26 := rfl

/-- The width-code width is the byte width the sim decodes, pinned so the C
`__u8` width code and the generated `widthCodeBits` cannot drift apart. -/
theorem x86_div_width_code_bits_is_8 : widthCodeBits = 8 := rfl

/-- The case count is the four quotient/remainder bodies `X86_OP_DIV` selects
between. -/
theorem x86_div_arm_count_is_4 : armCount = 4 := rfl

/-- Each case operates at the width code the width contract names for the
corresponding operand size: the byte case at the 8-bit code, the word case at
the 16-bit code, the dword case at the 32-bit code, and the qword case at the
64-bit code. -/
theorem x86_div_arm_width_codes :
    widthCodeOfArm .b8 = x86WidthCodeSpec .w8 ∧
      widthCodeOfArm .b16 = x86WidthCodeSpec .w16 ∧
      widthCodeOfArm .b32 = x86WidthCodeSpec .w32 ∧
      widthCodeOfArm .b64 = x86WidthCodeSpec .w64 := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> (unfold widthCodeOfArm x86WidthCodeSpec; rfl)

/-- The byte case divides a single register and packs the quotient and
remainder into it, so it makes exactly one register write; every wider case
divides the high:low pair and writes both the quotient and the remainder
registers, so it makes two. -/
theorem x86_div_write_counts :
    writeCountOfArm .b8 = 1 ∧
      writeCountOfArm .b16 = 2 ∧
      writeCountOfArm .b32 = 2 ∧
      writeCountOfArm .b64 = 2 := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> rfl

/-- The byte case divides a single register and so consumes no high-half
dividend register; every wider case divides `RDX:RAX` (or its subword windows)
and names `RDX` as its high-half dividend. -/
theorem x86_div_dividend_high :
    dividendHighOfArm .b8 = "none" ∧
      dividendHighOfArm .b16 = "rdx" ∧
      dividendHighOfArm .b32 = "rdx" ∧
      dividendHighOfArm .b64 = "rdx" := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> rfl

/-- Only the qword case gates its split on the high-half dividend being zero —
the architectural `DIV` overflow gate; the byte/word/dword cases do not. -/
theorem x86_div_only_qword_gated :
    highGateOfArm .b8 = false ∧
      highGateOfArm .b16 = false ∧
      highGateOfArm .b32 = false ∧
      highGateOfArm .b64 = true := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> rfl

/-- The qword case is the selector's default arm, so every resolved width code
that is not one of the byte/word/dword codes — including the absent code — is
high-gated and every real byte/word/dword code is not. -/
theorem x86_div_gated_only_default (width : Nat) (h1 : width ≠ 1)
    (h2 : width ≠ 2) (h3 : width ≠ 4) :
    highGateOfArm (armOf width) = true := by
  unfold armOf
  rw [if_neg h1, if_neg h2, if_neg h3]
  rfl

/-- The three non-default cases are not high-gated, so the gate is exclusive to
the qword case. -/
theorem x86_div_nondefault_not_gated :
    highGateOfArm (armOf 1) = false ∧
      highGateOfArm (armOf 2) = false ∧
      highGateOfArm (armOf 4) = false := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The ladder is total: every resolved width code reaches one of the four
cases, and the default qword case is what any other code reaches. -/
theorem x86_div_ladder_total (width : Nat) (h1 : width ≠ 1) (h2 : width ≠ 2)
    (h3 : width ≠ 4) :
    armOf width = .b64 := by
  unfold armOf
  rw [if_neg h1, if_neg h2, if_neg h3]

/-- All the selector shapes are reachable: each real byte/word/dword code
reaches its own case and the qword code reaches the default case, so no case of
the contract is dead. -/
theorem x86_div_case_dispatch :
    armOf 1 = .b8 ∧ armOf 2 = .b16 ∧ armOf 4 = .b32 ∧ armOf 8 = .b64 := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The byte/word/dword cases are the narrow width class and the qword case the
full class, so the classes are distinct and neither is empty. -/
theorem x86_div_width_classes :
    widthClassOfArm .b8 = "narrow" ∧
      widthClassOfArm .b16 = "narrow" ∧
      widthClassOfArm .b32 = "narrow" ∧
      widthClassOfArm .b64 = "full" ∧
      widthClassOfArm .b8 ≠ widthClassOfArm .b64 := by
  refine ⟨rfl, rfl, rfl, rfl, by decide⟩

/-- The four cases perform four distinct quotient/remainder effects: the byte
case packs both results into one register, the wider cases write the quotient
and remainder to separate registers at their own widths. -/
theorem x86_div_effects :
    effectOfArm .b8 = "byte_quotient_packed" ∧
      effectOfArm .b16 = "word_quotient_remainder" ∧
      effectOfArm .b32 = "dword_quotient_remainder" ∧
      effectOfArm .b64 = "qword_quotient_remainder" ∧
      effectOfArm .b8 ≠ effectOfArm .b16 ∧
      effectOfArm .b16 ≠ effectOfArm .b32 ∧
      effectOfArm .b32 ≠ effectOfArm .b64 := by
  refine ⟨rfl, rfl, rfl, rfl, by decide, by decide, by decide⟩

/-- Independent statement of the byte case's register effect: the quotient and
remainder are packed into one value and written to the low register as a single
16-bit partial-register write, scalarizing the cell. -/
def x86DivByteSpec (old : X86RegValue) (packed : BitVec 64) : X86RegValue :=
  x86RegWriteSpec old packed .w16

/-- Independent statement of a wider case's register effect: the quotient is
written to the low register and the remainder to the high-half register, both at
the access width, scalarizing both cells. -/
def x86DivWideSpec (low high : X86RegValue) (quot rem : BitVec 64)
    (width : X86Width) : X86RegValue × X86RegValue :=
  (x86RegWriteSpec low quot width, x86RegWriteSpec high rem width)

/-- The byte case is exactly one 16-bit partial-register write of the packed
quotient/remainder, so it touches only the low register. -/
theorem x86_div_byte_is_single_write (old : X86RegValue) (packed : BitVec 64) :
    x86DivByteSpec old packed = x86RegWriteSpec old packed .w16 := by
  rfl

/-- The byte case's single 16-bit write preserves the low register's six upper
bytes, so the packed quotient/remainder touches only the low word. -/
theorem x86_div_byte_preserves_upper (old : X86RegValue) (packed : BitVec 64) :
    BitVec.and (x86DivByteSpec old packed).bits 0xffffffffffff0000 =
      BitVec.and old.bits 0xffffffffffff0000 := by
  simp [x86DivByteSpec, x86RegWriteSpec, x86RegWriteBitsSpec]
  bv_decide

/-- The byte case scalarizes its single written cell. -/
theorem x86_div_byte_scalarizes (old : X86RegValue) (packed : BitVec 64) :
    (x86DivByteSpec old packed).tag = .scalar := by
  rfl

/-- A wider case writes the quotient to the low register and the remainder to
the high-half register: both registers are written, so the quotient and the
remainder both become observable. -/
theorem x86_div_wide_writes_both (low high : X86RegValue) (quot rem : BitVec 64)
    (width : X86Width) :
    (x86DivWideSpec low high quot rem width).1 = x86RegWriteSpec low quot width ∧
      (x86DivWideSpec low high quot rem width).2 =
        x86RegWriteSpec high rem width := by
  exact ⟨rfl, rfl⟩

/-- A wider case scalarizes both written cells. -/
theorem x86_div_wide_scalarizes (low high : X86RegValue) (quot rem : BitVec 64)
    (width : X86Width) :
    (x86DivWideSpec low high quot rem width).1.tag = .scalar ∧
      (x86DivWideSpec low high quot rem width).2.tag = .scalar := by
  exact ⟨rfl, rfl⟩

/-- The byte case touches exactly one cell while a wider case touches two, so
the number of registers the quotient/remainder effect writes matches the case's
declared write count. -/
theorem x86_div_write_count_matches_effect (low high : X86RegValue)
    (packed quot rem : BitVec 64) (width : X86Width) :
    writeCountOfArm .b8 = 1 ∧ writeCountOfArm .b64 = 2 ∧
      (x86DivByteSpec low packed).tag = .scalar ∧
      (x86DivWideSpec low high quot rem width).2.tag = .scalar := by
  exact ⟨rfl, rfl, rfl, rfl⟩

end KProgFormal
