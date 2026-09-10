import KProgFormal.GeneratedX86SbbResult
import KProgFormal.X86Width
import KProgFormal.X86SubFlags
namespace KProgFormal
def x86SbbResultSpec (a b : BitVec 64) (borrow : Bool) : BitVec 64 :=
  a - b - (if borrow then 1 else 0)
def x86SbbSubtrahendSpec (b mask : BitVec 64) (borrow : Bool) : BitVec 64 :=
  BitVec.and (b + (if borrow then 1 else 0)) mask
theorem x86_sbb_result_refines (a b : BitVec 64) (borrow : Bool) :
    GeneratedX86SbbResult.result a b borrow = x86SbbResultSpec a b borrow := by rfl
theorem x86_sbb_narrowed_result_refines (a b : BitVec 64) (borrow : Bool) (width:X86Width) :
    GeneratedX86Width.narrow (GeneratedX86SbbResult.result a b borrow) width =
      x86NarrowSpec (x86SbbResultSpec a b borrow) width := by
  rw [x86_sbb_result_refines, x86_narrow_refines]
theorem x86_sbb_subtrahend_refines (b mask : BitVec 64) (borrow : Bool) :
    GeneratedX86SbbResult.subtrahend b mask borrow =
      x86SbbSubtrahendSpec b mask borrow := by rfl
end KProgFormal
