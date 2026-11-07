import KProgFormal.Refinement.X86Logic
import KProgFormal.X86ShiftFlags

namespace KProgFormal.Refinement.X86LegacyShift
open Reference
open Reference.X86 (ScalarWidth LegacyShift ScalarDestination)

def operation : LegacyShift → GeneratedX86ShiftFlags.Op
  | .left => .shl | .right => .shr | .arithmetic => .sar | .rotateLeft => .rol

def value (width : ScalarWidth) (kind : LegacyShift) (source count : Reference.Word) : Reference.Word :=
  let w := X86Scalar.handlerWidth width
  match kind with
  | .left => GeneratedX86ShiftResult.shl source count w
  | .right => GeneratedX86ShiftResult.shr source count w
  | .arithmetic => GeneratedX86ShiftResult.sar source count w
  | .rotateLeft => GeneratedX86ShiftResult.rol source count w

theorem value_refines (width : ScalarWidth) (kind : LegacyShift) (source count : Reference.Word) :
    value width kind source count = Reference.X86.legacyShiftValue width kind source count := by
  cases width <;> cases kind <;>
    simp only [value, X86Scalar.handlerWidth, Reference.X86.legacyShiftValue,
      Reference.X86.legacyCount, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
      GeneratedX86ShiftResult.shl, GeneratedX86ShiftResult.shr, GeneratedX86ShiftResult.sar,
      GeneratedX86ShiftResult.rol, GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
      GeneratedX86Width.narrow, GeneratedX86Width.mask, GeneratedX86Width.signMask,
      GeneratedX86Width.bits, reduceCtorEq, ↓reduceIte, Nat.reduceMul, Nat.reduceSub, Reference.Word] <;> bv_decide

/-- The production macro invokes generated four-flag updates and adds parity
for nonzero shifts. Rotate leaves PF and AF unchanged; shifts retain AF as an
allowed undefined representative. -/
def flags (width : ScalarWidth) (kind : LegacyShift) (source count old : Reference.Word) : Reference.Word :=
  let result := value width kind source count
  let firstFour := GeneratedX86ShiftFlags.apply (operation kind) source count result
    (X86Scalar.handlerWidth width)
    ⟨old.getLsbD 0, old.getLsbD 6, old.getLsbD 7, old.getLsbD 11⟩
  let pf := if Reference.X86.legacyCount width count = 0 ∨ kind = .rotateLeft
    then old.getLsbD 2 else GeneratedX86AuxFlags.parity result
  X86Arithmetic.flagsWord old ⟨firstFour.cf, firstFour.zf, firstFour.sf, firstFour.of⟩ pf (old.getLsbD 4)

theorem narrow (width : ScalarWidth) (x : Reference.Word) :
    GeneratedX86Width.narrow x (X86Scalar.handlerWidth width) = (x.setWidth width.bits).setWidth 64 := by
  cases width <;> simp only [X86Scalar.handlerWidth, Reference.X86.ScalarWidth.bits,
    Reference.X86.ScalarWidth.bytes, GeneratedX86Width.narrow, GeneratedX86Width.mask,
    Nat.reduceMul] <;> bv_decide

theorem sign (width : ScalarWidth) (x : Reference.Word) :
    GeneratedX86Width.sign x (X86Scalar.handlerWidth width) = x.getLsbD (width.bits - 1) := by
  cases width <;> simp only [X86Scalar.handlerWidth, Reference.X86.ScalarWidth.bits,
    Reference.X86.ScalarWidth.bytes, GeneratedX86Width.sign, GeneratedX86Width.signMask,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, GeneratedX86Width.bits, Nat.reduceMul, Nat.reduceSub, Reference.Word] <;> bv_decide

theorem pack (old : Reference.Word) (cf zf sf of pf : Bool) :
    X86Arithmetic.flagsWord old ⟨cf,zf,sf,of⟩ pf (old.getLsbD 4) =
    Reference.X86.setFlag (Reference.X86.setFlag (Reference.X86.setFlag
      (Reference.X86.setFlag (Reference.X86.setFlag old 0 cf) 11 of) 2 pf) 6 zf) 7 sf := by
  simp only [X86Arithmetic.flagsWord, Reference.X86.setFlag]
  bv_decide

theorem pack_rotate (old : Reference.Word) (cf of : Bool) :
    X86Arithmetic.flagsWord old ⟨cf,old.getLsbD 6,old.getLsbD 7,of⟩ (old.getLsbD 2) (old.getLsbD 4) =
    Reference.X86.setFlag (Reference.X86.setFlag old 0 cf) 11 of := by
  simp only [X86Arithmetic.flagsWord, Reference.X86.setFlag]
  bv_decide

theorem pack_old (old : Reference.Word) :
    X86Arithmetic.flagsWord old ⟨old.getLsbD 0,old.getLsbD 6,old.getLsbD 7,old.getLsbD 11⟩ (old.getLsbD 2) (old.getLsbD 4) = old := by
  simp only [X86Arithmetic.flagsWord]
  bv_decide
theorem count_refines (width : ScalarWidth) (x : Reference.Word) :
    GeneratedX86ShiftCount.count x (X86Scalar.handlerWidth width) = Reference.X86.legacyCount width x := by
  cases width <;> rfl

theorem bits_refines (width : ScalarWidth) :
    GeneratedX86Width.bits (X86Scalar.handlerWidth width) = width.bits := by
  cases width <;> rfl

theorem count_zero (x : Reference.Word) : x = 0 ↔ x.toNat = 0 := BitVec.toNat_eq

theorem narrow_result (width : ScalarWidth) (kind : LegacyShift) (source count : Reference.Word) :
    GeneratedX86Width.narrow (Reference.X86.legacyShiftValue width kind source count)
      (X86Scalar.handlerWidth width) = Reference.X86.legacyShiftValue width kind source count := by
  cases width <;> cases kind <;>
    simp only [X86Scalar.handlerWidth, GeneratedX86Width.narrow, GeneratedX86Width.mask,
      Reference.X86.legacyShiftValue, Reference.X86.legacyCount,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
      reduceCtorEq, ↓reduceIte, Nat.reduceMul, Nat.reduceSub, Reference.Word] <;> bv_decide

set_option maxHeartbeats 2000000 in
theorem flags_refine (width : ScalarWidth) (kind : LegacyShift) (source count old : Reference.Word) :
    flags width kind source count old = Reference.X86.legacyShiftFlags width kind source count old := by
  cases kind <;> by_cases hn : (Reference.X86.legacyCount width count).toNat = 0 <;>
    simp only [flags, value_refines, GeneratedX86ShiftFlags.apply, operation,
      count_refines, bits_refines, Reference.X86.legacyShiftFlags,
      count_zero, hn, reduceCtorEq, ↓reduceIte, or_true, or_false,
      GeneratedX86ShiftFlags.shlCf, GeneratedX86ShiftFlags.rightCf,
      X86AuxFlags.parity_refines] <;>
    (try simp only [narrow_result, sign]) <;>
    (try simp only [narrow])
  · exact pack_old old
  · rw [pack]
  · exact pack_old old
  · rw [pack]
  · exact pack_old old
  · rw [pack]
  · exact pack_old old
  · exact pack_rotate old _ _

def handlerStep (width : ScalarWidth) (kind : LegacyShift) (dst : ScalarDestination)
    (count nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (source, reads) =>
      match X86Scalar.write s width dst (value width kind source count) with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) =>
          ⟨{ result with rflags := flags width kind source count s.rflags, pc := nextPc }, reads ++ writes, none⟩

theorem step_refines (width : ScalarWidth) (kind : LegacyShift) (dst : ScalarDestination)
    (count nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width kind dst count nextPc s =
      Reference.X86.step (.legacyShift width kind dst count nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.legacyShiftStep,
    X86Scalar.read_refines, X86Scalar.write_refines, value_refines, flags_refine]
  rfl

theorem handler_refines (width : ScalarWidth) (kind : LegacyShift) (dst : ScalarDestination)
    (count nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.legacyShift width kind dst count nextPc) s
      (handlerStep width kind dst count nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
end KProgFormal.Refinement.X86LegacyShift
