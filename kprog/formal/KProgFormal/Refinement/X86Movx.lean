import KProgFormal.Refinement.X86Scalar
import KProgFormal.X86MovxRegHandler
import KProgFormal.Generated.GeneratedX86MovxShape
namespace KProgFormal.Refinement.X86Movx
open Reference
open Reference.X86 (ScalarWidth)

def op (signed : Bool) : X86MovxOp := if signed then .movsx else .movzx

def value (sourceWidth : ScalarWidth) (signed : Bool) (source : Reference.Word) : Reference.Word :=
  if signed then GeneratedX86Signed.signExtend source (X86Scalar.handlerWidth sourceWidth)
  else GeneratedX86Width.narrow source (X86Scalar.handlerWidth sourceWidth)

theorem value_refines (sourceWidth : ScalarWidth) (signed : Bool) (source : Reference.Word) :
    value sourceWidth signed source = Reference.X86.extendValue sourceWidth signed source := by
  cases signed
  · cases sourceWidth <;> simp [value, Reference.X86.extendValue, X86Scalar.handlerWidth,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
      GeneratedX86Width.narrow, GeneratedX86Width.mask] <;> bv_decide
  · simp only [value, Bool.true_eq, ↓reduceIte, x86_sign_extend_refines]
    cases sourceWidth <;> simp [Reference.X86.extendValue, X86Scalar.handlerWidth, x86SignExtendSpec,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes] <;> bv_decide

theorem write_refines (sourceWidth targetWidth : ScalarWidth) (signed : Bool)
    (old : X86RegValue) (source : Reference.Word) :
    (generatedX86MovxRegStep ⟨old⟩ source (op signed) (X86Scalar.handlerWidth sourceWidth)
      (X86Scalar.handlerWidth targetWidth)).dst.bits =
      Reference.X86.scalarWriteValue old.bits (Reference.X86.extendValue sourceWidth signed source)
        targetWidth (.low 0) := by
  have hw := X86Scalar.register_write_refines targetWidth (.low 0) old.bits (value sourceWidth signed source)
  rw [← value_refines sourceWidth signed source]
  cases targetWidth <;> cases signed <;> simpa only [generatedX86MovxRegStep, op, value, Bool.false_eq_true, Bool.true_eq,
    ↓reduceIte, generatedX86RegWrite, GeneratedX86RegWrite.write,
    GeneratedX86RegWrite.byteShift, X86Scalar.lane, X86Scalar.handlerWidth,
    GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits] using hw
/-- Reading a low register lane before widening equals the actual raw-register
MOVX body: discarded upper source bits cannot affect either extension. -/
theorem register_source_narrowing (sourceWidth targetWidth : ScalarWidth) (signed : Bool)
    (old : X86RegValue) (source : Reference.Word) :
    (generatedX86MovxRegStep ⟨old⟩ ((source.setWidth sourceWidth.bits).setWidth 64)
      (op signed) (X86Scalar.handlerWidth sourceWidth) (X86Scalar.handlerWidth targetWidth)).dst.bits =
    (generatedX86MovxRegStep ⟨old⟩ source (op signed) (X86Scalar.handlerWidth sourceWidth)
      (X86Scalar.handlerWidth targetWidth)).dst.bits := by
  simp only [write_refines]
  congr 1
  cases sourceWidth <;> cases signed <;>
    simp [Reference.X86.extendValue, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes] <;> bv_decide

def sourceCode : Reference.X86.RegisterSlice → Nat
  | .low reg => reg.val
  | .high reg => GeneratedX86MovxShape.sourceHighBase + reg.val

theorem source_code_fits_byte (slice : Reference.X86.RegisterSlice) : sourceCode slice < 256 := by
  cases slice <;> simp [sourceCode, GeneratedX86MovxShape.sourceHighBase] <;> omega

theorem source_register_refines (slice : Reference.X86.RegisterSlice) :
    GeneratedX86MovxShape.sourceRegister (sourceCode slice) = slice.reg.val := by
  cases slice with
  | low reg =>
      have h : ¬128 ≤ reg.val := by have := reg.isLt; omega
      simp [sourceCode, GeneratedX86MovxShape.sourceRegister, GeneratedX86MovxShape.sourceHigh,
        GeneratedX86MovxShape.sourceHighBase, GeneratedX86MovxShape.sourceHighCount, h,
        Reference.X86.RegisterSlice.reg] <;> omega
  | high reg =>
      have h : 128 ≤ 128 + reg.val ∧ 128 + reg.val < 132 := by have := reg.isLt; omega
      simp [sourceCode, GeneratedX86MovxShape.sourceRegister, GeneratedX86MovxShape.sourceHigh,
        GeneratedX86MovxShape.sourceHighBase, GeneratedX86MovxShape.sourceHighCount, h,
        Reference.X86.RegisterSlice.reg] <;> omega

theorem source_lane_refines (slice : Reference.X86.RegisterSlice) :
    (if GeneratedX86MovxShape.sourceShift (sourceCode slice) = 8 then
      GeneratedX86RegWrite.ByteLane.high else .low) = X86Scalar.lane slice := by
  cases slice with
  | low reg =>
      have h : ¬128 ≤ reg.val := by have := reg.isLt; omega
      simp [sourceCode, GeneratedX86MovxShape.sourceShift, GeneratedX86MovxShape.sourceHigh,
        GeneratedX86MovxShape.sourceHighBase, GeneratedX86MovxShape.sourceHighCount,
        GeneratedX86MovxShape.sourceHighShift, X86Scalar.lane, h]
  | high reg =>
      have h : 128 ≤ 128 + reg.val ∧ 128 + reg.val < 132 := by have := reg.isLt; omega
      simp [sourceCode, GeneratedX86MovxShape.sourceShift, GeneratedX86MovxShape.sourceHigh,
        GeneratedX86MovxShape.sourceHighBase, GeneratedX86MovxShape.sourceHighCount,
        GeneratedX86MovxShape.sourceHighShift, X86Scalar.lane, h]

theorem encoded_register_read_refines (width : ScalarWidth) (slice : Reference.X86.RegisterSlice)
    (value : Reference.Word) :
    GeneratedX86RegRead.readAt value (X86Scalar.handlerWidth width)
      (if GeneratedX86MovxShape.sourceShift (sourceCode slice) = 8 then .high else .low) =
      ((value >>> slice.shift width).setWidth width.bits).setWidth 64 := by
  rw [source_lane_refines]
  exact X86Scalar.register_read_refines width slice value

def handlerStep (sourceWidth targetWidth : ScalarWidth) (signed : Bool)
    (dst : Reference.X86.Register) (source : Reference.X86.ScalarSource) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s sourceWidth source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      let result := (generatedX86MovxRegStep ⟨⟨s.gpr dst, .scalar⟩⟩ value (op signed)
        (X86Scalar.handlerWidth sourceWidth) (X86Scalar.handlerWidth targetWidth)).dst.bits
      ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), pc := nextPc }, events, none⟩

theorem step_refines (sourceWidth targetWidth : ScalarWidth) (signed : Bool)
    (dst : Reference.X86.Register) (source : Reference.X86.ScalarSource) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    handlerStep sourceWidth targetWidth signed dst source nextPc s =
      Reference.X86.step (.extend sourceWidth targetWidth signed dst source nextPc) s := by
  simp only [handlerStep, Reference.X86.step, X86Scalar.read_refines]
  cases h : Reference.X86.scalarRead s sourceWidth source with
  | error fault => simp only [h]
  | ok pair => simp [h, write_refines]; rfl

theorem handler_refines (sourceWidth targetWidth : ScalarWidth) (signed : Bool)
    (dst : Reference.X86.Register) (source : Reference.X86.ScalarSource) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.extend sourceWidth targetWidth signed dst source nextPc) s
      (handlerStep sourceWidth targetWidth signed dst source nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Movx
