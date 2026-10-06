import KProgFormal.GeneratedX86AddFlags
import KProgFormal.X86ControlFlow
namespace KProgFormal
def x86AddFlagsSpec (a b r sign : BitVec 64) : X86Flags :=
  { cf := BitVec.ult r a, zf := r == 0, sf := BitVec.and r sign != 0,
    of := BitVec.and (BitVec.not (BitVec.xor a b)) (BitVec.and (BitVec.xor a r) sign) != 0 }
def generatedX86AddFlags (a b r sign : BitVec 64) : X86Flags :=
  let f := GeneratedX86AddFlags.eval a b r sign
  { cf:=f.cf, zf:=f.zf, sf:=f.sf, of:=f.of }
theorem x86_add_flags_refine (a b r sign : BitVec 64) : generatedX86AddFlags a b r sign=x86AddFlagsSpec a b r sign := by rfl
theorem x86_add_branch_refines (a b r sign : BitVec 64) (cond:X86Cond) (fallthrough target:Nat) :
    branchPc (generatedX86Cond (generatedX86AddFlags a b r sign) cond) fallthrough target =
      branchPc (x86CondSpec (x86AddFlagsSpec a b r sign) cond) fallthrough target := by
  rw [x86_add_flags_refine, x86_condition_sound]
end KProgFormal
