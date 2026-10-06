import KProgFormal.GeneratedX86Cond
import KProgFormal.Arm64ControlFlow

namespace KProgFormal

structure X86Flags where
  cf : Bool
  zf : Bool
  sf : Bool
  of : Bool
  deriving DecidableEq, Repr

abbrev X86Cond := GeneratedX86Cond.Cond

/-- Independent architectural statement of every x86 condition supported by
the native simulator. Parity conditions are outside the accepted subset. -/
def x86CondSpec (flags : X86Flags) : X86Cond -> Bool
  | .o => flags.of
  | .no => !flags.of
  | .b => flags.cf
  | .ae => !flags.cf
  | .e => flags.zf
  | .ne => !flags.zf
  | .be => flags.cf || flags.zf
  | .a => !flags.cf && !flags.zf
  | .s => flags.sf
  | .ns => !flags.sf
  | .l => flags.sf != flags.of
  | .ge => flags.sf == flags.of
  | .le => flags.zf || (flags.sf != flags.of)
  | .g => !flags.zf && (flags.sf == flags.of)

def generatedX86Cond (flags : X86Flags) (cond : X86Cond) : Bool :=
  GeneratedX86Cond.eval flags.cf flags.zf flags.sf flags.of cond

theorem x86_condition_sound (flags : X86Flags) (cond : X86Cond) :
    generatedX86Cond flags cond = x86CondSpec flags cond := by
  cases flags
  cases cond <;> rfl

theorem x86_conditional_branch_refines
    (flags : X86Flags) (cond : X86Cond) (fallthrough target : Nat) :
    branchPc (generatedX86Cond flags cond) fallthrough target =
      branchPc (x86CondSpec flags cond) fallthrough target := by
  rw [x86_condition_sound]

end KProgFormal
