import KProgFormal.GeneratedX86Adc
import KProgFormal.X86Width
import KProgFormal.X86ControlFlow
namespace KProgFormal
def x86AdcResultSpec (a b : BitVec 64) (carry : Bool) : BitVec 64 :=
  a + b + (if carry then 1 else 0)
def x86AdcFlagsSpec (a b r sign : BitVec 64) (carry : Bool) : X86Flags :=
  { cf := BitVec.ult r a || (carry && r == a), zf := r == 0,
    sf := BitVec.and r sign != 0,
    of := BitVec.and (BitVec.not (BitVec.xor a b)) (BitVec.and (BitVec.xor a r) sign) != 0 }
def generatedX86AdcFlags (a b r sign : BitVec 64) (carry : Bool) : X86Flags :=
  let f := GeneratedX86Adc.flags a b r sign carry
  { cf:=f.cf,zf:=f.zf,sf:=f.sf,of:=f.of }
theorem x86_adc_result_refines (a b : BitVec 64) (carry : Bool) :
    GeneratedX86Adc.result a b carry = x86AdcResultSpec a b carry := by rfl
theorem x86_adc_flags_refine (a b r sign : BitVec 64) (carry : Bool) :
    generatedX86AdcFlags a b r sign carry = x86AdcFlagsSpec a b r sign carry := by rfl
theorem x86_adc_step_refines (a b sign : BitVec 64) (carry : Bool) (width:X86Width) :
    generatedX86AdcFlags (GeneratedX86Width.narrow a width)
      (GeneratedX86Width.narrow b width)
      (GeneratedX86Width.narrow (GeneratedX86Adc.result a b carry) width) sign carry =
    x86AdcFlagsSpec (x86NarrowSpec a width) (x86NarrowSpec b width)
      (x86NarrowSpec (x86AdcResultSpec a b carry) width) sign carry := by
  rw [x86_adc_flags_refine, x86_adc_result_refines]
  repeat rw [x86_narrow_refines]
theorem x86_adc_branch_refines (a b r sign : BitVec 64) (carry : Bool)
    (cond:X86Cond) (fallthrough target:Nat) :
    branchPc (generatedX86Cond (generatedX86AdcFlags a b r sign carry) cond) fallthrough target =
      branchPc (x86CondSpec (x86AdcFlagsSpec a b r sign carry) cond) fallthrough target := by
  rw [x86_adc_flags_refine, x86_condition_sound]
end KProgFormal
