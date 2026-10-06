import KProgFormal.GeneratedX86LogicFlags
import KProgFormal.X86ControlFlow
namespace KProgFormal
def x86LogicFlagsSpec (zero sign : Bool) : X86Flags :=
  { cf := false, zf := zero, sf := sign, of := false }
def generatedX86LogicFlags (zero sign : Bool) : X86Flags :=
  let f := GeneratedX86LogicFlags.eval zero sign
  { cf := f.cf, zf := f.zf, sf := f.sf, of := f.of }
theorem x86_logic_flags_refine (zero sign : Bool) :
    generatedX86LogicFlags zero sign = x86LogicFlagsSpec zero sign := by rfl
theorem x86_logic_branch_refines
    (zero sign : Bool) (cond : X86Cond) (fallthrough target : Nat) :
    branchPc (generatedX86Cond (generatedX86LogicFlags zero sign) cond) fallthrough target =
      branchPc (x86CondSpec (x86LogicFlagsSpec zero sign) cond) fallthrough target := by
  rw [x86_logic_flags_refine, x86_condition_sound]
end KProgFormal
