import KProgFormal.GeneratedX86AluDecode

namespace KProgFormal

abbrev X86Alu := GeneratedX86AluDecode.Alu

def x86AluCodeSpec : X86Alu -> Nat
  | .add => 0 | .sub => 1 | .xor => 2 | .or => 3
  | .and => 4 | .shl => 5 | .shr => 6 | .sar => 7
  | .rol => 8 | .imul => 9 | .inc => 10 | .not => 11
  | .sbb => 12 | .dec => 13 | .neg => 14 | .adc => 15

def x86AluMnemonicSpec : X86Alu -> String
  | .add => "add" | .sub => "sub" | .xor => "xor" | .or => "or"
  | .and => "and" | .shl => "shl" | .shr => "shr" | .sar => "sar"
  | .rol => "rol" | .imul => "imul" | .inc => "inc" | .not => "not"
  | .sbb => "sbb" | .dec => "dec" | .neg => "neg" | .adc => "adc"

theorem x86_alu_code_refines (alu : X86Alu) :
    GeneratedX86AluDecode.code alu = x86AluCodeSpec alu := by
  cases alu <;> rfl

theorem x86_alu_mnemonic_refines (alu : X86Alu) :
    GeneratedX86AluDecode.mnemonic alu = x86AluMnemonicSpec alu := by
  cases alu <;> rfl

end KProgFormal
