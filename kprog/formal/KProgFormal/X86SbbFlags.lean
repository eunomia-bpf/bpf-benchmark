import KProgFormal.GeneratedX86SbbFlags
import KProgFormal.X86SbbResult
import KProgFormal.X86ControlFlow
namespace KProgFormal
def x86SbbFlagsSpec (a b r sign : BitVec 64) (borrow : Bool) : X86Flags :=
  { cf := BitVec.ult a b || (borrow && a == b), zf := r == 0,
    sf := BitVec.and r sign != 0,
    of := BitVec.and (BitVec.xor a b) (BitVec.and (BitVec.xor a r) sign) != 0 }
def generatedX86SbbFlags (a b r sign : BitVec 64) (borrow : Bool) : X86Flags :=
  let f := GeneratedX86SbbFlags.eval a b r sign borrow
  { cf:=f.cf,zf:=f.zf,sf:=f.sf,of:=f.of }
theorem x86_sbb_flags_refine (a b r sign : BitVec 64) (borrow : Bool) :
    generatedX86SbbFlags a b r sign borrow = x86SbbFlagsSpec a b r sign borrow := by rfl
theorem x86_sbb_step_refines (a b : BitVec 64) (borrow : Bool) (width:X86Width) :
    generatedX86SbbFlags (GeneratedX86Width.narrow a width) (GeneratedX86Width.narrow b width)
      (GeneratedX86Width.narrow (GeneratedX86SbbResult.result a b borrow) width)
      (GeneratedX86Width.signMask width) borrow =
    x86SbbFlagsSpec (x86NarrowSpec a width) (x86NarrowSpec b width)
      (x86NarrowSpec (x86SbbResultSpec a b borrow) width)
      (x86WidthSignMaskSpec width) borrow := by
  rw [x86_sbb_flags_refine, x86_sbb_result_refines,
    x86_width_sign_mask_refines]
  repeat rw [x86_narrow_refines]
theorem x86_sbb_branch_refines (a b r sign : BitVec 64) (borrow : Bool)
    (cond:X86Cond) (fallthrough target:Nat) :
    branchPc (generatedX86Cond (generatedX86SbbFlags a b r sign borrow) cond) fallthrough target =
      branchPc (x86CondSpec (x86SbbFlagsSpec a b r sign borrow) cond) fallthrough target := by
  rw [x86_sbb_flags_refine, x86_condition_sound]

/-- Borrowing from the largest positive byte reaches exactly `-128`, so it is
not a signed overflow even though `b + borrow` wraps into the sign bit. -/
theorem x86_sbb_no_false_overflow_at_positive_boundary :
    (generatedX86SbbFlags 0 0x7f 0x80 0x80 true).of = false := by
  native_decide

/-- The dual boundary really does overflow: `-1 - 127 - 1 = -129`. -/
theorem x86_sbb_detects_negative_boundary_overflow :
    (generatedX86SbbFlags 0xff 0x7f 0x7f 0x80 true).of = true := by
  native_decide
end KProgFormal
