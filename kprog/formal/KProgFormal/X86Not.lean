import KProgFormal.GeneratedX86Not
import KProgFormal.X86Width
import KProgFormal.X86ControlFlow

namespace KProgFormal

def x86NotWidthResultSpec (value : BitVec 64) (width : X86Width) : BitVec 64 :=
  BitVec.xor (x86NarrowSpec value width) (x86WidthMaskSpec width)

def generatedX86NotFlags (flags : X86Flags) : X86Flags :=
  let generated := GeneratedX86Not.flags flags.cf flags.zf flags.sf flags.of
  { cf := generated.cf, zf := generated.zf, sf := generated.sf, of := generated.of }

def x86NotFlagsSpec (flags : X86Flags) : X86Flags := flags

theorem x86_not_narrowed_result_refines (value : BitVec 64) (width : X86Width) :
    GeneratedX86Width.narrow (GeneratedX86Not.result value) width =
      x86NotWidthResultSpec value width := by
  cases width <;> simp [GeneratedX86Width.narrow, GeneratedX86Width.mask,
    GeneratedX86Not.result, x86NotWidthResultSpec, x86NarrowSpec,
    x86WidthMaskSpec] <;> bv_decide

theorem x86_not_flags_refine (flags : X86Flags) :
    generatedX86NotFlags flags = x86NotFlagsSpec flags := by
  cases flags
  rfl

theorem x86_not_branch_refines (flags : X86Flags) (cond : X86Cond)
    (fallthrough target : Nat) :
    branchPc (generatedX86Cond (generatedX86NotFlags flags) cond)
        fallthrough target =
      branchPc (x86CondSpec (x86NotFlagsSpec flags) cond) fallthrough target := by
  rw [x86_not_flags_refine, x86_condition_sound]

end KProgFormal
