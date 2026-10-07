import KProgFormal.GeneratedX86ImulFlags
import KProgFormal.X86Width
import KProgFormal.X86ControlFlow

namespace KProgFormal

/-- Magnitude of a width-narrowed signed value, stated from the width bridge
contract (mirrors the C x86_signed_abs_width helper). -/
def x86SignedAbsSpec (value : BitVec 64) (width : X86Width) : BitVec 64 :=
  let v := x86NarrowSpec value width
  if x86SignSpec v width then BitVec.and (BitVec.not v + 1) (x86WidthMaskSpec width) else v

/-- Independent statement of the simulator's IMUL overflow rule: CF/OF are set
together when the width-narrowed signed product does not fit the signed width
(mixed-sign products have one extra bit of headroom); ZF/SF are preserved. -/
def x86ImulOverflowSpec (lhs rhs : BitVec 64) (width : X86Width) : Bool :=
  let aAbs := x86SignedAbsSpec lhs width
  let bAbs := x86SignedAbsSpec rhs width
  let sign := x86WidthSignMaskSpec width
  let limit := if x86SignSpec lhs width != x86SignSpec rhs width
    then sign else sign - 1
  aAbs != 0 && bAbs > limit / aAbs

def x86ImulFlagsApplied (lhs rhs : BitVec 64) (width : X86Width)
    (old : X86Flags) : X86Flags :=
  let overflow := x86ImulOverflowSpec lhs rhs width
  { cf := overflow, zf := old.zf, sf := old.sf, of := overflow }

def generatedX86ImulFlags (lhs rhs : BitVec 64) (width : X86Width)
    (old : X86Flags) : X86Flags :=
  let f := GeneratedX86ImulFlags.apply lhs rhs width
    { cf := old.cf, zf := old.zf, sf := old.sf, of := old.of }
  { cf := f.cf, zf := f.zf, sf := f.sf, of := f.of }

/-- The generated transition satisfies the flag contract. -/
theorem x86_imul_flags_defined (lhs rhs : BitVec 64) (width : X86Width) :
    x86ImulOverflowSpec lhs rhs width =
      (let aAbs := GeneratedX86ImulFlags.signedAbs lhs width
       let bAbs := GeneratedX86ImulFlags.signedAbs rhs width
       let sign := GeneratedX86Width.signMask width
       let limit := if GeneratedX86ImulFlags.mixedSign lhs rhs width
         then sign else sign - 1
       aAbs != 0 && bAbs > limit / aAbs) := by
  cases width <;>
    simp only [x86ImulOverflowSpec, x86SignedAbsSpec, x86NarrowSpec,
      x86SignSpec, x86WidthMaskSpec, x86WidthSignMaskSpec, x86WidthBitsSpec,
      x86WidthCodeSpec, GeneratedX86ImulFlags.signedAbs,
      GeneratedX86ImulFlags.mixedSign,
      GeneratedX86Width.narrow, GeneratedX86Width.sign,
      GeneratedX86Width.mask, GeneratedX86Width.signMask,
      GeneratedX86Width.bits, BitVec.and, BitVec.not] <;>
    simp

theorem x86_imul_flags_apply_refines (lhs rhs : BitVec 64) (width : X86Width)
    (old : X86Flags) :
    generatedX86ImulFlags lhs rhs width old =
      x86ImulFlagsApplied lhs rhs width old := by
  cases width <;>
    simp only [generatedX86ImulFlags, x86ImulFlagsApplied,
      GeneratedX86ImulFlags.apply, x86ImulOverflowSpec,
      GeneratedX86ImulFlags.signedAbs, GeneratedX86ImulFlags.mixedSign,
      x86SignedAbsSpec, x86NarrowSpec, x86SignSpec, x86WidthMaskSpec,
      x86WidthSignMaskSpec, x86WidthBitsSpec, x86WidthCodeSpec,
      GeneratedX86Width.narrow,
      GeneratedX86Width.sign, GeneratedX86Width.mask,
      GeneratedX86Width.signMask, GeneratedX86Width.bits] <;>
    simp

theorem x86_imul_w16_boundary_overflow :
    x86ImulOverflowSpec 0x7fff 2 .w16 = true := by
  native_decide

theorem x86_imul_w8_min_boundary_no_overflow :
    x86ImulOverflowSpec 0x80 1 .w8 = false := by
  native_decide

end KProgFormal
