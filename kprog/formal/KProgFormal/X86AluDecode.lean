import KProgFormal.GeneratedX86AluDecode
import KProgFormal.X86RegLaneAux

namespace KProgFormal

abbrev X86Alu := GeneratedX86AluDecode.Alu
abbrev X86AluHandler := GeneratedX86AluDecode.Handler

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

def x86AluHandlerSpec : X86Alu -> X86AluHandler
  | .sbb => .sbb
  | .adc => .adc
  | _ => .generic

theorem x86_alu_code_refines (alu : X86Alu) :
    GeneratedX86AluDecode.code alu = x86AluCodeSpec alu := by
  cases alu <;> rfl

theorem x86_alu_mnemonic_refines (alu : X86Alu) :
    GeneratedX86AluDecode.mnemonic alu = x86AluMnemonicSpec alu := by
  cases alu <;> rfl

theorem x86_alu_handler_refines (alu : X86Alu) :
    GeneratedX86AluDecode.handler alu = x86AluHandlerSpec alu := by
  cases alu <;>
    native_decide

/-- Packing a typed ALU code into the register-lane AUX and extracting its
payload selects the same carry-sensitive handler as the independent mapping. -/
theorem x86_alu_aux_handler_refines (alu : X86Alu)
    (dstShift srcShift : BitVec 32) :
    GeneratedX86AluDecode.handlerForCode
      (GeneratedX86RegLaneAux.payload
        (GeneratedX86RegLaneAux.pack
          (BitVec.ofNat 32 (GeneratedX86AluDecode.code alu))
          dstShift srcShift)) = x86AluHandlerSpec alu := by
  rw [x86_reg_lane_aux_payload_roundtrip]
  cases alu <;> native_decide

end KProgFormal
