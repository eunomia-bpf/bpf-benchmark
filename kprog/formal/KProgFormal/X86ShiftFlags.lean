import KProgFormal.GeneratedX86ShiftFlags
import KProgFormal.X86ShiftResult
import KProgFormal.X86ControlFlow

namespace KProgFormal

abbrev X86ShiftOp := GeneratedX86ShiftFlags.Op

def generatedX86ShiftFlags (op : X86ShiftOp) (value rhs result : BitVec 64)
    (width : X86Width) (old : X86Flags) : X86Flags :=
  let flags := GeneratedX86ShiftFlags.apply op value rhs result width
    { cf := old.cf, zf := old.zf, sf := old.sf, of := old.of }
  { cf := flags.cf, zf := flags.zf, sf := flags.sf, of := flags.of }

/-- The architecturally observable shift-flag contract. Undefined CF/OF cases
are intentionally unconstrained; the generated implementation makes a stable
choice for them without promoting that choice to an ISA guarantee. -/
def x86ShiftFlagsDefinedSpec (op : X86ShiftOp) (value rhs : BitVec 64)
    (result : BitVec 64) (width : X86Width) (old out : X86Flags) : Bool :=
  let count := x86ShiftCountSpec rhs width
  let bits := x86WidthBitsSpec width
  let a := x86NarrowSpec value width
  let r := x86NarrowSpec result width
  let resultZero := r == 0
  let resultSign := x86SignSpec r width
  if count = 0 then out == old
  else match op with
    | .rol =>
        out.cf == r.getLsbD 0 && out.zf == old.zf && out.sf == old.sf &&
          (if count = 1 then out.of == (resultSign != out.cf) else true)
    | .shl =>
        out.zf == resultZero && out.sf == resultSign &&
          (if count < bits then out.cf == a.getLsbD (bits - count) else true) &&
          (if count = 1 then out.of == (resultSign != out.cf) else true)
    | .shr =>
        out.zf == resultZero && out.sf == resultSign &&
          (if count < bits then out.cf == a.getLsbD (count - 1) else true) &&
          (if count = 1 then out.of == x86SignSpec a width else true)
    | .sar =>
        out.zf == resultZero && out.sf == resultSign &&
          out.cf == (if count <= bits then a.getLsbD (count - 1)
            else a.getLsbD (bits - 1)) &&
          (if count = 1 then out.of == false else true)

theorem x86_shl_flags_defined (value rhs : BitVec 64) (width : X86Width)
    (result : BitVec 64) (old : X86Flags) :
    x86ShiftFlagsDefinedSpec .shl value rhs result width old
      (generatedX86ShiftFlags .shl value rhs result width old) = true := by
  simp only [x86ShiftFlagsDefinedSpec]
  rw [← x86_shift_count_refines rhs width]
  cases width <;> cases old <;>
    simp only [generatedX86ShiftFlags, x86WidthBitsSpec,
      x86NarrowSpec, x86WidthMaskSpec, x86SignSpec,
      GeneratedX86ShiftFlags.apply, GeneratedX86ShiftFlags.shlCf,
      GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
      GeneratedX86Width.bits, GeneratedX86Width.mask,
      GeneratedX86Width.narrow, GeneratedX86Width.sign] <;>
    split <;> simp_all <;> omega

theorem x86_shr_flags_defined (value rhs : BitVec 64) (width : X86Width)
    (result : BitVec 64) (old : X86Flags) :
    x86ShiftFlagsDefinedSpec .shr value rhs result width old
      (generatedX86ShiftFlags .shr value rhs result width old) = true := by
  simp only [x86ShiftFlagsDefinedSpec]
  rw [← x86_shift_count_refines rhs width]
  cases width <;> cases old <;>
    simp only [generatedX86ShiftFlags, x86WidthBitsSpec,
      x86NarrowSpec, x86WidthMaskSpec, x86SignSpec,
      GeneratedX86ShiftFlags.apply, GeneratedX86ShiftFlags.rightCf,
      GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
      GeneratedX86Width.bits, GeneratedX86Width.mask,
      GeneratedX86Width.narrow, GeneratedX86Width.sign] <;>
    split <;> simp_all <;> omega

theorem x86_sar_flags_defined (value rhs : BitVec 64) (width : X86Width)
    (result : BitVec 64) (old : X86Flags) :
    x86ShiftFlagsDefinedSpec .sar value rhs result width old
      (generatedX86ShiftFlags .sar value rhs result width old) = true := by
  simp only [x86ShiftFlagsDefinedSpec]
  rw [← x86_shift_count_refines rhs width]
  cases width <;> cases old <;>
    simp only [generatedX86ShiftFlags, x86WidthBitsSpec,
      x86NarrowSpec, x86WidthMaskSpec, x86WidthSignMaskSpec, x86SignSpec,
      GeneratedX86ShiftFlags.apply, GeneratedX86ShiftFlags.rightCf,
      GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
      GeneratedX86Width.bits, GeneratedX86Width.mask,
      GeneratedX86Width.signMask, GeneratedX86Width.narrow,
      GeneratedX86Width.sign] <;>
    split <;> simp_all

theorem x86_rol_flags_defined (value rhs : BitVec 64) (width : X86Width)
    (result : BitVec 64) (old : X86Flags) :
    x86ShiftFlagsDefinedSpec .rol value rhs result width old
      (generatedX86ShiftFlags .rol value rhs result width old) = true := by
  simp only [x86ShiftFlagsDefinedSpec]
  rw [← x86_shift_count_refines rhs width]
  cases width <;> cases old <;>
    simp only [generatedX86ShiftFlags, x86WidthBitsSpec,
      x86NarrowSpec, x86WidthMaskSpec, x86SignSpec,
      GeneratedX86ShiftFlags.apply, GeneratedX86ShiftCount.count,
      GeneratedX86ShiftCount.mask, GeneratedX86Width.bits,
      GeneratedX86Width.mask, GeneratedX86Width.narrow,
      GeneratedX86Width.sign] <;>
    split <;> simp_all

theorem x86_shl_step_refines (value rhs : BitVec 64) (width : X86Width)
    (old : X86Flags) :
    GeneratedX86ShiftResult.shl value rhs width = x86ShlResultSpec value rhs width ∧
    x86ShiftFlagsDefinedSpec .shl value rhs
      (GeneratedX86ShiftResult.shl value rhs width) width old
      (generatedX86ShiftFlags .shl value rhs
        (GeneratedX86ShiftResult.shl value rhs width) width old) = true :=
  ⟨x86_shl_result_refines value rhs width,
    x86_shl_flags_defined value rhs width _ old⟩

theorem x86_shr_step_refines (value rhs : BitVec 64) (width : X86Width)
    (old : X86Flags) :
    GeneratedX86ShiftResult.shr value rhs width = x86ShrResultSpec value rhs width ∧
    x86ShiftFlagsDefinedSpec .shr value rhs
      (GeneratedX86ShiftResult.shr value rhs width) width old
      (generatedX86ShiftFlags .shr value rhs
        (GeneratedX86ShiftResult.shr value rhs width) width old) = true :=
  ⟨x86_shr_result_refines value rhs width,
    x86_shr_flags_defined value rhs width _ old⟩

theorem x86_sar_step_refines (value rhs : BitVec 64) (width : X86Width)
    (old : X86Flags) :
    GeneratedX86ShiftResult.sar value rhs width = x86SarResultSpec value rhs width ∧
    x86ShiftFlagsDefinedSpec .sar value rhs
      (GeneratedX86ShiftResult.sar value rhs width) width old
      (generatedX86ShiftFlags .sar value rhs
        (GeneratedX86ShiftResult.sar value rhs width) width old) = true :=
  ⟨x86_sar_result_refines value rhs width,
    x86_sar_flags_defined value rhs width _ old⟩

theorem x86_rol_step_refines (value rhs : BitVec 64) (width : X86Width)
    (old : X86Flags) :
    GeneratedX86ShiftResult.rol value rhs width = x86RolResultSpec value rhs width ∧
    x86ShiftFlagsDefinedSpec .rol value rhs
      (GeneratedX86ShiftResult.rol value rhs width) width old
      (generatedX86ShiftFlags .rol value rhs
        (GeneratedX86ShiftResult.rol value rhs width) width old) = true :=
  ⟨x86_rol_result_refines value rhs width,
    x86_rol_flags_defined value rhs width _ old⟩

theorem x86_rol_w8_count8_updates_cf :
    let old : X86Flags := { cf := false, zf := true, sf := true, of := false }
    (generatedX86ShiftFlags .rol 1 8
      (GeneratedX86ShiftResult.rol 1 8 .w8) .w8 old).cf = true := by
  native_decide

end KProgFormal
