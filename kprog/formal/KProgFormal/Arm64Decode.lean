import KProgFormal.GeneratedArm64Decode

namespace KProgFormal

/-- Independent enumeration of the accepted AArch64 ALU operations, written as
explicit mnemonic/code pairs so it does not reuse the generated tables. -/
def arm64AluSpec : List (String × Nat) :=
  [("add", 0), ("sub", 1), ("and", 2), ("bic", 3), ("eor", 4), ("orr", 5)]

def arm64ShiftSpec : List (String × Nat) :=
  [("lsl", 0), ("lsr", 1), ("asr", 2), ("ror", 3)]

def arm64ModSpec : List (String × Nat) :=
  [("", 0), ("lsl", 1), ("lsr", 2), ("asr", 3), ("ror", 4), ("uxtw", 5),
   ("sxtw", 6), ("uxth", 7), ("sxth", 8), ("uxtb", 9), ("sxtb", 10)]

def arm64BitfieldSpec : List (String × Nat) :=
  [("ubfx", 0), ("sbfx", 1), ("ubfiz", 2), ("bfxil", 3), ("bfi", 4)]

/-- Constructor enumeration for the generated ALU table, in specification
order; the values themselves still come from the generated `code`/`mnemonic`
definitions. -/
def allAlu : List GeneratedArm64AluDecode.Alu := [.add, .sub, .and, .bic, .eor, .orr]

def allShift : List GeneratedArm64ShiftDecode.Shift := [.lsl, .lsr, .asr, .ror]

def allMod : List GeneratedArm64ModDecode.Mod :=
  [.none, .lsl, .lsr, .asr, .ror, .uxtw, .sxtw, .uxth, .sxth, .uxtb, .sxtb]

def allBitfield : List GeneratedArm64BitfieldDecode.Bitfield :=
  [.ubfx, .sbfx, .ubfiz, .bfxil, .bfi]

/-- The generated ALU table, projected to mnemonic/code pairs, equals the
independent specification list. A change to either a generated code or the
independent list breaks this equality. -/
theorem arm64_alu_decode_refines :
    arm64AluSpec =
      allAlu.map (fun op => (GeneratedArm64AluDecode.mnemonic op,
                             GeneratedArm64AluDecode.code op)) := by
    decide

/-- The generated shift table, projected to mnemonic/code pairs, equals the
independent specification list. -/
theorem arm64_shift_decode_refines :
    arm64ShiftSpec =
      allShift.map (fun op => (GeneratedArm64ShiftDecode.mnemonic op,
                               GeneratedArm64ShiftDecode.code op)) := by
    decide

/-- The generated modifier table, projected to mnemonic/code pairs, equals the
independent specification list, including the empty (no-modifier) mnemonic. -/
theorem arm64_mod_decode_refines :
    arm64ModSpec =
      allMod.map (fun op => (GeneratedArm64ModDecode.mnemonic op,
                             GeneratedArm64ModDecode.code op)) := by
    decide

/-- The generated bitfield table, projected to mnemonic/code pairs, equals the
independent specification list. -/
theorem arm64_bitfield_decode_refines :
    arm64BitfieldSpec =
      allBitfield.map (fun op => (GeneratedArm64BitfieldDecode.mnemonic op,
                                  GeneratedArm64BitfieldDecode.code op)) := by
    decide


/-- Every generated ALU code is distinct, so dispatch on the numeric code
selects exactly one operation. -/
theorem arm64_alu_codes_distinct :
    GeneratedArm64AluDecode.code .add ≠ GeneratedArm64AluDecode.code .sub ∧
    GeneratedArm64AluDecode.code .and ≠ GeneratedArm64AluDecode.code .bic ∧
    GeneratedArm64AluDecode.code .eor ≠ GeneratedArm64AluDecode.code .orr := by
  decide

/-- Every generated shift code is distinct, so dispatch on the numeric code
selects exactly one shift kind. -/
theorem arm64_shift_codes_distinct :
    GeneratedArm64ShiftDecode.code .lsl ≠ GeneratedArm64ShiftDecode.code .lsr ∧
    GeneratedArm64ShiftDecode.code .asr ≠ GeneratedArm64ShiftDecode.code .ror ∧
    GeneratedArm64ShiftDecode.code .lsl ≠ GeneratedArm64ShiftDecode.code .ror := by
  decide

/-- Every generated modifier code is distinct, so dispatch on the numeric code
selects exactly one extend/shift modifier. -/
theorem arm64_mod_codes_distinct :
    GeneratedArm64ModDecode.code .none ≠ GeneratedArm64ModDecode.code .lsl ∧
    GeneratedArm64ModDecode.code .uxtw ≠ GeneratedArm64ModDecode.code .sxtw ∧
    GeneratedArm64ModDecode.code .uxtb ≠ GeneratedArm64ModDecode.code .sxtb := by
  decide

/-- Every generated bitfield code is distinct, so dispatch on the numeric code
selects exactly one bitfield operation. -/
theorem arm64_bitfield_codes_distinct :
    GeneratedArm64BitfieldDecode.code .ubfx ≠ GeneratedArm64BitfieldDecode.code .sbfx ∧
    GeneratedArm64BitfieldDecode.code .ubfiz ≠ GeneratedArm64BitfieldDecode.code .bfxil ∧
    GeneratedArm64BitfieldDecode.code .bfxil ≠ GeneratedArm64BitfieldDecode.code .bfi := by
  decide

end KProgFormal
