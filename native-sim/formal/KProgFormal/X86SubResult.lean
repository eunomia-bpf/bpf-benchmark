import KProgFormal.GeneratedX86SbbResult
import KProgFormal.X86SubFlags
import KProgFormal.X86Width

namespace KProgFormal

def x86SubResultSpec (a b : BitVec 64) : BitVec 64 := a - b

theorem x86_sub_result_refines (a b : BitVec 64) :
    GeneratedX86SbbResult.result a b false = x86SubResultSpec a b := by
  simp [GeneratedX86SbbResult.result, x86SubResultSpec]

theorem x86_sub_step_refines (a b : BitVec 64) (width : X86Width) :
    generatedX86SubFlags (GeneratedX86Width.narrow a width)
      (GeneratedX86Width.narrow b width)
      (GeneratedX86Width.narrow (GeneratedX86SbbResult.result a b false) width)
      (GeneratedX86Width.signMask width) =
    x86SubFlagsSpec (x86NarrowSpec a width) (x86NarrowSpec b width)
      (x86NarrowSpec (x86SubResultSpec a b) width)
      (x86WidthSignMaskSpec width) := by
  rw [x86_sub_flags_refine, x86_sub_result_refines,
    x86_width_sign_mask_refines]
  repeat rw [x86_narrow_refines]

theorem x86_cmp_branch_refines (a b : BitVec 64) (width : X86Width)
    (cond : X86Cond) (fallthrough target : Nat) :
    branchPc (generatedX86Cond
      (generatedX86SubFlags (GeneratedX86Width.narrow a width)
        (GeneratedX86Width.narrow b width)
        (GeneratedX86Width.narrow (GeneratedX86SbbResult.result a b false) width)
        (GeneratedX86Width.signMask width)) cond) fallthrough target =
    branchPc (x86CondSpec
      (x86SubFlagsSpec (x86NarrowSpec a width) (x86NarrowSpec b width)
        (x86NarrowSpec (x86SubResultSpec a b) width)
        (x86WidthSignMaskSpec width)) cond) fallthrough target := by
  rw [x86_sub_step_refines, x86_condition_sound]

end KProgFormal
