import KProgFormal.GeneratedX86Adc
import KProgFormal.X86AddFlags
import KProgFormal.X86Width
namespace KProgFormal
def x86AddResultSpec (a b : BitVec 64) : BitVec 64 := a + b
theorem x86_add_result_refines (a b : BitVec 64) :
    GeneratedX86Adc.result a b false = x86AddResultSpec a b := by
  simp [GeneratedX86Adc.result, x86AddResultSpec]
theorem x86_add_step_refines (a b : BitVec 64) (width:X86Width) :
    generatedX86AddFlags (GeneratedX86Width.narrow a width)
      (GeneratedX86Width.narrow b width)
      (GeneratedX86Width.narrow (GeneratedX86Adc.result a b false) width)
      (GeneratedX86Width.signMask width) =
    x86AddFlagsSpec (x86NarrowSpec a width) (x86NarrowSpec b width)
      (x86NarrowSpec (x86AddResultSpec a b) width) (x86WidthSignMaskSpec width) := by
  rw [x86_add_flags_refine, x86_add_result_refines, x86_width_sign_mask_refines]
  repeat rw [x86_narrow_refines]
end KProgFormal
