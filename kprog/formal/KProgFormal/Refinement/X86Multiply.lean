import KProgFormal.Refinement.X86Bt
import KProgFormal.Generated.GeneratedX86AluResult
import KProgFormal.Generated.GeneratedX86ImulFlags
import KProgFormal.Generated.GeneratedX86Signed

namespace KProgFormal.Refinement.X86Multiply
open Reference
open Reference.X86 (CmovWidth Register Source)
open X86Cmov (handlerWidth)

/-- Dividing a signed-magnitude bound is equivalent to comparing the complete
unsigned magnitude product. This theorem has no fixed product-width limit. -/
theorem overflow_bridge (a b limit : BitVec 64) :
    (a != 0 && b > limit / a) = decide (limit.toNat < a.toNat * b.toNat) := by
  by_cases ha : a = 0
  · subst a; simp
  · have hn : 0 < a.toNat := by
      have hz : a.toNat ≠ 0 := by
        intro h; apply ha; exact BitVec.toNat_eq.mpr h
      omega
    apply Bool.eq_iff_iff.mpr
    simp [ha, BitVec.lt_def, BitVec.toNat_udiv, Nat.div_lt_iff_lt_mul hn, Nat.mul_comm]
    exact fun _ => ha

theorem magnitude_refines (width : CmovWidth) (value : Reference.Word) :
    GeneratedX86ImulFlags.signedAbs value (handlerWidth width) =
      Reference.X86.multiplyMagnitude width value := by
  cases width <;> simp only [GeneratedX86ImulFlags.signedAbs, handlerWidth,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, GeneratedX86Width.sign,
    GeneratedX86Width.signMask, GeneratedX86Width.bits, Reference.X86.multiplyMagnitude,
    Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes,
    Nat.reduceMul, Nat.reduceSub, Reference.Word] <;> bv_decide

theorem mixed_refines (width : CmovWidth) (left right : Reference.Word) :
    GeneratedX86ImulFlags.mixedSign left right (handlerWidth width) =
      Reference.X86.multiplyMixedSign width left right := by
  cases width <;> simp only [GeneratedX86ImulFlags.mixedSign, handlerWidth,
    GeneratedX86Width.sign, GeneratedX86Width.narrow, GeneratedX86Width.mask, GeneratedX86Width.signMask, GeneratedX86Width.bits,
    Reference.X86.multiplyMixedSign, Reference.X86.CmovWidth.bits,
    Reference.X86.CmovWidth.bytes, Nat.reduceMul, Nat.reduceSub, Reference.Word] <;> bv_decide

theorem limit_refines (width : CmovWidth) (negative : Bool) :
    (if negative then GeneratedX86Width.signMask (handlerWidth width)
      else GeneratedX86Width.signMask (handlerWidth width) - 1).toNat =
      2^(width.bits - 1) - (if negative then 0 else 1) := by
  cases width <;> cases negative <;> decide

def overflow (width : CmovWidth) (left right : Reference.Word) : Bool :=
  (GeneratedX86ImulFlags.apply left right (handlerWidth width) ⟨false,false,false,false⟩).cf

theorem overflow_refines (width : CmovWidth) (left right : Reference.Word) :
    overflow width left right = Reference.X86.multiplyOverflow width left right := by
  simp only [overflow, GeneratedX86ImulFlags.apply, overflow_bridge, magnitude_refines,
    mixed_refines, limit_refines, Reference.X86.multiplyOverflow]

def value (width : CmovWidth) (left right : Reference.Word) : Reference.Word :=
  GeneratedX86Width.narrow (GeneratedX86AluResult.result .imul left right (handlerWidth width)) (handlerWidth width)

theorem value_refines (width : CmovWidth) (left right : Reference.Word) :
    value width left right = Reference.X86.multiplyValue width left right := by
  cases width <;> simp only [value, GeneratedX86AluResult.result, handlerWidth,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, Reference.X86.multiplyValue,
    Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes, Nat.reduceMul, Reference.Word] <;> bv_decide

def immediate (width : CmovWidth) (raw : BitVec 32) : Reference.Word :=
  GeneratedX86Signed.signExtend (raw.signExtend 64) (handlerWidth width)

theorem immediate_refines (width : CmovWidth) (raw : BitVec 32) :
    immediate width raw = Reference.X86.multiplyImmediate width raw := by
  cases width <;> simp only [immediate, handlerWidth, GeneratedX86Signed.signExtend,
    GeneratedX86Width.narrow, GeneratedX86Width.mask,
    GeneratedX86Width.signMask, GeneratedX86Width.bits, Reference.X86.multiplyImmediate,
    reduceCtorEq, ↓reduceIte, Reference.Word] <;> bv_decide

def flags (width : CmovWidth) (left right old : Reference.Word) : Reference.Word :=
  let result := GeneratedX86ImulFlags.apply left right (handlerWidth width)
    ⟨old.getLsbD 0,old.getLsbD 6,old.getLsbD 7,old.getLsbD 11⟩
  Reference.X86.setFlag (Reference.X86.setFlag old 0 result.cf) 11 result.of

theorem flags_refine (width : CmovWidth) (left right old : Reference.Word) :
    flags width left right old = Reference.X86.multiplyFlags width left right old := by
  change Reference.X86.setFlag (Reference.X86.setFlag old 0 (overflow width left right)) 11
    (overflow width left right) = _
  simp only [overflow_refines, Reference.X86.multiplyFlags]

theorem writeback_refines (width : CmovWidth) (old result : Reference.Word) :
    (generatedX86RegWrite ⟨old,.scalar⟩ result (handlerWidth width)).bits =
      Reference.X86.writeValue width old result := by
  cases width <;> simp only [generatedX86RegWrite, GeneratedX86RegWrite.write,
    GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits,
    GeneratedX86RegWrite.byteShift, handlerWidth, Reference.X86.writeValue,
    reduceCtorEq, ↓reduceIte, Reference.Word] <;> bv_decide

theorem signed_lane_refines (width : CmovWidth) (source : Reference.Word) :
    (GeneratedX86Signed.signExtend source (handlerWidth width)).setWidth width.bits =
      source.setWidth width.bits := by
  cases width <;> simp only [GeneratedX86Signed.signExtend, handlerWidth,
    Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes, Nat.reduceMul,
    Reference.Word] <;> bv_decide

/-- The selected operands are native values after the register/memory routes;
all width-sensitive product/flags computations and destination writes use the
shared generated helpers. Source reads precede an aliased destination write. -/
def handlerStep (width : CmovWidth) (dst : Register) (source : Source)
    (rawImmediate : Option (BitVec 32)) (nextPc : Reference.Word) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  match X86Bt.readOperand width source s with
  | .error fault => ⟨s,[.fault fault],some fault⟩
  | .ok (sourceValue,events) =>
      let operands := match rawImmediate with
        | none => (s.gpr dst,sourceValue)
        | some raw => (sourceValue,immediate width raw)
      let product := match rawImmediate, source with
        | some _, .memory _ => value width (GeneratedX86Signed.signExtend sourceValue (handlerWidth width)) operands.2
        | _, _ => value width operands.1 operands.2
      let result := generatedX86RegWrite ⟨s.gpr dst,.scalar⟩ product (handlerWidth width)
      ⟨{ s with gpr := (fun r => if r = dst then result.bits else s.gpr r), rflags := flags width operands.1 operands.2 s.rflags, pc := nextPc },events,none⟩

theorem step_refines (width : CmovWidth) (dst : Register) (source : Source)
    (rawImmediate : Option (BitVec 32)) (nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width dst source rawImmediate nextPc s =
      Reference.X86.step (.multiply width dst source rawImmediate nextPc) s := by
  cases rawImmediate <;> cases source <;>
    simp only [handlerStep, Reference.X86.step, Reference.X86.multiplyStep, X86Bt.read_refines,
      immediate_refines, value_refines, flags_refine, writeback_refines,
      Reference.X86.multiplyValue, signed_lane_refines] <;> rfl

theorem handler_refines (width : CmovWidth) (dst : Register) (source : Source)
    (rawImmediate : Option (BitVec 32)) (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.multiply width dst source rawImmediate nextPc) s
      (handlerStep width dst source rawImmediate nextPc s) := by
  rw [step_refines]; exact ⟨rfl,rfl,rfl⟩
end KProgFormal.Refinement.X86Multiply
