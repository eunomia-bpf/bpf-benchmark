import KProgFormal.X86AddResult
import KProgFormal.X86SubResult

namespace KProgFormal

def x86IncResultSpec (a : BitVec 64) : BitVec 64 := a + 1
def x86DecResultSpec (a : BitVec 64) : BitVec 64 := a - 1

def generatedX86IncFlags (a r sign : BitVec 64) (oldCf : Bool) : X86Flags :=
  let flags := generatedX86AddFlags a 1 r sign
  { cf := oldCf, zf := flags.zf, sf := flags.sf, of := flags.of }

def x86IncFlagsSpec (a r sign : BitVec 64) (oldCf : Bool) : X86Flags :=
  { cf := oldCf, zf := r == 0, sf := BitVec.and r sign != 0,
    of := BitVec.and (BitVec.not (BitVec.xor a 1))
      (BitVec.and (BitVec.xor a r) sign) != 0 }

def generatedX86DecFlags (a r sign : BitVec 64) (oldCf : Bool) : X86Flags :=
  let flags := generatedX86SubFlags a 1 r sign
  { cf := oldCf, zf := flags.zf, sf := flags.sf, of := flags.of }

def x86DecFlagsSpec (a r sign : BitVec 64) (oldCf : Bool) : X86Flags :=
  { cf := oldCf, zf := a == 1, sf := BitVec.and r sign != 0,
    of := BitVec.and (BitVec.xor a 1)
      (BitVec.and (BitVec.xor a r) sign) != 0 }

theorem x86_inc_result_refines (a : BitVec 64) :
    GeneratedX86Adc.result a 1 false = x86IncResultSpec a := by
  simp [GeneratedX86Adc.result, x86IncResultSpec]

theorem x86_dec_result_refines (a : BitVec 64) :
    GeneratedX86SbbResult.result a 1 false = x86DecResultSpec a := by
  simp [GeneratedX86SbbResult.result, x86DecResultSpec]

theorem x86_inc_flags_refine (a r sign : BitVec 64) (oldCf : Bool) :
    generatedX86IncFlags a r sign oldCf = x86IncFlagsSpec a r sign oldCf := by
  simp [generatedX86IncFlags, generatedX86AddFlags, GeneratedX86AddFlags.eval,
    x86IncFlagsSpec]

theorem x86_dec_flags_refine (a r sign : BitVec 64) (oldCf : Bool) :
    generatedX86DecFlags a r sign oldCf = x86DecFlagsSpec a r sign oldCf := by
  simp [generatedX86DecFlags, generatedX86SubFlags, GeneratedX86SubFlags.eval,
    x86DecFlagsSpec]

theorem x86_inc_step_refines (a : BitVec 64) (oldCf : Bool) (width : X86Width) :
    generatedX86IncFlags (GeneratedX86Width.narrow a width)
      (GeneratedX86Width.narrow (GeneratedX86Adc.result a 1 false) width)
      (GeneratedX86Width.signMask width) oldCf =
    x86IncFlagsSpec (x86NarrowSpec a width)
      (x86NarrowSpec (x86IncResultSpec a) width)
      (x86WidthSignMaskSpec width) oldCf := by
  rw [x86_inc_flags_refine, x86_inc_result_refines,
    x86_width_sign_mask_refines]
  repeat rw [x86_narrow_refines]

theorem x86_dec_step_refines (a : BitVec 64) (oldCf : Bool) (width : X86Width) :
    generatedX86DecFlags (GeneratedX86Width.narrow a width)
      (GeneratedX86Width.narrow (GeneratedX86SbbResult.result a 1 false) width)
      (GeneratedX86Width.signMask width) oldCf =
    x86DecFlagsSpec (x86NarrowSpec a width)
      (x86NarrowSpec (x86DecResultSpec a) width)
      (x86WidthSignMaskSpec width) oldCf := by
  rw [x86_dec_flags_refine, x86_dec_result_refines,
    x86_width_sign_mask_refines]
  repeat rw [x86_narrow_refines]

theorem x86_inc_branch_refines (a : BitVec 64) (oldCf : Bool) (width : X86Width)
    (cond : X86Cond) (fallthrough target : Nat) :
    branchPc (generatedX86Cond
      (generatedX86IncFlags (GeneratedX86Width.narrow a width)
        (GeneratedX86Width.narrow (GeneratedX86Adc.result a 1 false) width)
        (GeneratedX86Width.signMask width) oldCf) cond) fallthrough target =
    branchPc (x86CondSpec
      (x86IncFlagsSpec (x86NarrowSpec a width)
        (x86NarrowSpec (x86IncResultSpec a) width)
        (x86WidthSignMaskSpec width) oldCf) cond) fallthrough target := by
  rw [x86_inc_step_refines, x86_condition_sound]

theorem x86_dec_branch_refines (a : BitVec 64) (oldCf : Bool) (width : X86Width)
    (cond : X86Cond) (fallthrough target : Nat) :
    branchPc (generatedX86Cond
      (generatedX86DecFlags (GeneratedX86Width.narrow a width)
        (GeneratedX86Width.narrow (GeneratedX86SbbResult.result a 1 false) width)
        (GeneratedX86Width.signMask width) oldCf) cond) fallthrough target =
    branchPc (x86CondSpec
      (x86DecFlagsSpec (x86NarrowSpec a width)
        (x86NarrowSpec (x86DecResultSpec a) width)
        (x86WidthSignMaskSpec width) oldCf) cond) fallthrough target := by
  rw [x86_dec_step_refines, x86_condition_sound]

def x86NegResultSpec (a : BitVec 64) : BitVec 64 := 0 - a

def x86NegFlagsSpec (a r sign : BitVec 64) : X86Flags :=
  { cf := a != 0, zf := r == 0, sf := BitVec.and r sign != 0,
    of := a == sign }

theorem x86_neg_result_refines (a : BitVec 64) :
    GeneratedX86SbbResult.result 0 a false = x86NegResultSpec a := by
  simp [GeneratedX86SbbResult.result, x86NegResultSpec]

theorem x86_neg_step_refines (a : BitVec 64) (width : X86Width) :
    generatedX86SubFlags 0 (GeneratedX86Width.narrow a width)
      (GeneratedX86Width.narrow (GeneratedX86SbbResult.result 0 a false) width)
      (GeneratedX86Width.signMask width) =
    x86NegFlagsSpec (x86NarrowSpec a width)
      (x86NarrowSpec (x86NegResultSpec a) width)
      (x86WidthSignMaskSpec width) := by
  cases width <;> simp [generatedX86SubFlags, GeneratedX86SubFlags.eval,
    GeneratedX86SbbResult.result, GeneratedX86Width.narrow,
    GeneratedX86Width.mask, GeneratedX86Width.signMask, x86NegFlagsSpec,
    x86NarrowSpec, x86NegResultSpec, x86WidthMaskSpec,
    x86WidthSignMaskSpec] <;> bv_decide

theorem x86_neg_branch_refines (a : BitVec 64) (width : X86Width)
    (cond : X86Cond) (fallthrough target : Nat) :
    branchPc (generatedX86Cond
      (generatedX86SubFlags 0 (GeneratedX86Width.narrow a width)
        (GeneratedX86Width.narrow (GeneratedX86SbbResult.result 0 a false) width)
        (GeneratedX86Width.signMask width)) cond) fallthrough target =
    branchPc (x86CondSpec
      (x86NegFlagsSpec (x86NarrowSpec a width)
        (x86NarrowSpec (x86NegResultSpec a) width)
        (x86WidthSignMaskSpec width)) cond) fallthrough target := by
  rw [x86_neg_step_refines, x86_condition_sound]

end KProgFormal
