import KProgFormal.GeneratedX86SbbFlags
import KProgFormal.X86SbbResult
import KProgFormal.X86ControlFlow
namespace KProgFormal
def x86SbbFlagsSpec (a b sub r sign : BitVec 64) (borrow : Bool) : X86Flags :=
  { cf := BitVec.ult a b || (borrow && a == b), zf := r == 0,
    sf := BitVec.and r sign != 0,
    of := BitVec.and (BitVec.xor a sub) (BitVec.and (BitVec.xor a r) sign) != 0 }
def generatedX86SbbFlags (a b sub r sign : BitVec 64) (borrow : Bool) : X86Flags :=
  let f := GeneratedX86SbbFlags.eval a b sub r sign borrow
  { cf:=f.cf,zf:=f.zf,sf:=f.sf,of:=f.of }
theorem x86_sbb_flags_refine (a b sub r sign : BitVec 64) (borrow : Bool) :
    generatedX86SbbFlags a b sub r sign borrow = x86SbbFlagsSpec a b sub r sign borrow := by rfl
theorem x86_sbb_step_refines (a b sign : BitVec 64) (borrow : Bool) (width:X86Width) :
    generatedX86SbbFlags (GeneratedX86Width.narrow a width) (GeneratedX86Width.narrow b width)
      (GeneratedX86SbbResult.subtrahend (GeneratedX86Width.narrow b width)
        (GeneratedX86Width.mask width) borrow)
      (GeneratedX86Width.narrow (GeneratedX86SbbResult.result a b borrow) width) sign borrow =
    x86SbbFlagsSpec (x86NarrowSpec a width) (x86NarrowSpec b width)
      (x86SbbSubtrahendSpec (x86NarrowSpec b width)
        (x86WidthMaskSpec width) borrow)
      (x86NarrowSpec (x86SbbResultSpec a b borrow) width) sign borrow := by
  rw [x86_sbb_flags_refine, x86_sbb_subtrahend_refines, x86_sbb_result_refines,
    x86_width_mask_refines]
  repeat rw [x86_narrow_refines]
theorem x86_sbb_branch_refines (a b sub r sign : BitVec 64) (borrow : Bool)
    (cond:X86Cond) (fallthrough target:Nat) :
    branchPc (generatedX86Cond (generatedX86SbbFlags a b sub r sign borrow) cond) fallthrough target =
      branchPc (x86CondSpec (x86SbbFlagsSpec a b sub r sign borrow) cond) fallthrough target := by
  rw [x86_sbb_flags_refine, x86_condition_sound]
end KProgFormal
