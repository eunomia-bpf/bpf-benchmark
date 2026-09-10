import KProgFormal.GeneratedX86SubFlags
import KProgFormal.X86ControlFlow
namespace KProgFormal
def x86SubFlagsSpec (a b r sign : BitVec 64) : X86Flags :=
  { cf := BitVec.ult a b, zf := a == b, sf := BitVec.and r sign != 0,
    of := BitVec.and (BitVec.xor a b) (BitVec.and (BitVec.xor a r) sign) != 0 }
def generatedX86SubFlags (a b r sign : BitVec 64) : X86Flags :=
  let f := GeneratedX86SubFlags.eval a b r sign
  { cf:=f.cf, zf:=f.zf, sf:=f.sf, of:=f.of }
theorem x86_sub_flags_refine (a b r sign : BitVec 64) : generatedX86SubFlags a b r sign=x86SubFlagsSpec a b r sign := by rfl
theorem x86_sub_branch_refines (a b r sign : BitVec 64) (cond:X86Cond) (fallthrough target:Nat) :
    branchPc (generatedX86Cond (generatedX86SubFlags a b r sign) cond) fallthrough target =
      branchPc (x86CondSpec (x86SubFlagsSpec a b r sign) cond) fallthrough target := by
  rw [x86_sub_flags_refine, x86_condition_sound]
end KProgFormal
