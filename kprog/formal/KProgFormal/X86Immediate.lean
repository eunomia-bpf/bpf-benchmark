import KProgFormal.GeneratedX86Immediate
import KProgFormal.X86Width

namespace KProgFormal

/-- Independent statement of the simulator's arithmetic-immediate rule:
instruction immediates are carried in a 64-bit artifact field, but only their
low 32 bits are consumed and 64-bit operations sign-extend those bits. -/
def x86ImmediateValueSpec (raw : BitVec 64) (width : X86Width) : BitVec 64 :=
  let imm32 := raw.setWidth 32
  match width with
  | .w64 => imm32.signExtend 64
  | _ => imm32.setWidth 64

theorem x86_immediate_value_refines (raw : BitVec 64) (width : X86Width) :
    GeneratedX86Immediate.value raw width =
      x86ImmediateValueSpec raw width := by
  cases width <;>
    simp [GeneratedX86Immediate.value, x86ImmediateValueSpec] <;> bv_decide

theorem x86_immediate_64_sign_extends_bit31 :
    GeneratedX86Immediate.value 0x0000000080000001 .w64 =
      0xffffffff80000001 := by
  native_decide

theorem x86_immediate_narrow_width_does_not_sign_extend :
    GeneratedX86Immediate.value 0x0000000080000001 .w32 =
      0x0000000080000001 := by
  native_decide

end KProgFormal
