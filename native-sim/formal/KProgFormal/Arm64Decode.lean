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

/-- The generated ALU table's codes and mnemonics equal the independent list. -/
theorem arm64_alu_decode_refines :
    GeneratedArm64AluDecode.code .add = 0 ∧
    GeneratedArm64AluDecode.code .sub = 1 ∧
    GeneratedArm64AluDecode.code .and = 2 ∧
    GeneratedArm64AluDecode.code .bic = 3 ∧
    GeneratedArm64AluDecode.code .eor = 4 ∧
    GeneratedArm64AluDecode.code .orr = 5 ∧
    GeneratedArm64AluDecode.mnemonic .add = "add" ∧
    GeneratedArm64AluDecode.mnemonic .orr = "orr" := by
  native_decide

/-- The generated shift table refines the independent enumeration. -/
theorem arm64_shift_decode_refines :
    GeneratedArm64ShiftDecode.code .lsl = 0 ∧
    GeneratedArm64ShiftDecode.code .lsr = 1 ∧
    GeneratedArm64ShiftDecode.code .asr = 2 ∧
    GeneratedArm64ShiftDecode.code .ror = 3 ∧
    GeneratedArm64ShiftDecode.mnemonic .ror = "ror" := by
  native_decide

/-- The generated modifier table refines the independent enumeration, including
the empty (no-modifier) entry mapping to code zero. -/
theorem arm64_mod_decode_refines :
    GeneratedArm64ModDecode.code .none = 0 ∧
    GeneratedArm64ModDecode.code .lsl = 1 ∧
    GeneratedArm64ModDecode.code .uxtw = 5 ∧
    GeneratedArm64ModDecode.code .sxtw = 6 ∧
    GeneratedArm64ModDecode.code .sxtb = 10 ∧
    GeneratedArm64ModDecode.mnemonic .none = "" := by
  native_decide

/-- The generated bitfield table refines the independent enumeration. -/
theorem arm64_bitfield_decode_refines :
    GeneratedArm64BitfieldDecode.code .ubfx = 0 ∧
    GeneratedArm64BitfieldDecode.code .sbfx = 1 ∧
    GeneratedArm64BitfieldDecode.code .ubfiz = 2 ∧
    GeneratedArm64BitfieldDecode.code .bfxil = 3 ∧
    GeneratedArm64BitfieldDecode.code .bfi = 4 := by
  native_decide

/-- Every generated ALU code is distinct, so dispatch on the numeric code
selects exactly one operation. -/
theorem arm64_alu_codes_distinct :
    GeneratedArm64AluDecode.code .add ≠ GeneratedArm64AluDecode.code .sub ∧
    GeneratedArm64AluDecode.code .and ≠ GeneratedArm64AluDecode.code .bic ∧
    GeneratedArm64AluDecode.code .eor ≠ GeneratedArm64AluDecode.code .orr := by
  native_decide

end KProgFormal
