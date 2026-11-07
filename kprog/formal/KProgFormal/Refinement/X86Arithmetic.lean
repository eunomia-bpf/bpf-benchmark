import KProgFormal.Generated.GeneratedX86Signed
import KProgFormal.Refinement.X86Scalar
import KProgFormal.Refinement.X86AuxFlags
import KProgFormal.Generated.GeneratedX86Adc
import KProgFormal.Generated.GeneratedX86AddFlags
import KProgFormal.Generated.GeneratedX86SubFlags
import KProgFormal.Generated.GeneratedX86SbbFlags
import KProgFormal.Generated.GeneratedX86SbbResult

namespace KProgFormal.Refinement.X86Arithmetic
open Reference
open Reference.X86 (ScalarWidth ArithmeticKind ScalarDestination ScalarSource)
open X86Scalar (handlerWidth)

def narrow (width : ScalarWidth) (value : Reference.Word) : Reference.Word :=
  GeneratedX86Width.narrow value (handlerWidth width)

def value (width : ScalarWidth) (subtract carry : Bool) (left right : Reference.Word) : Reference.Word :=
  let a := narrow width left
  let b := narrow width right
  narrow width (if subtract then GeneratedX86SbbResult.result a b carry else GeneratedX86Adc.result a b carry)

theorem value_refines (width : ScalarWidth) (subtract carry : Bool) (left right : Reference.Word) :
    value width subtract carry left right = Reference.X86.arithmeticValue width subtract carry left right := by
  cases width <;> cases subtract <;>
    simp only [value, narrow, handlerWidth, GeneratedX86Width.narrow, GeneratedX86Width.mask,
      GeneratedX86SbbResult.result, GeneratedX86Adc.result, Reference.X86.arithmeticValue,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, Reference.Word,
      Nat.reduceMul, Bool.false_eq_true, if_false, if_true] <;> bv_decide

/-- The original four-flag contracts stay intact. PF/AF extend their result
using the two auxiliary helpers now invoked by the production macros. -/
def flagsWord (old : Reference.Word) (flags : GeneratedX86LogicFlags.Flags) (pf af : Bool) : Reference.Word :=
  (old &&& 0xfffffffffffff72a) ||| (if flags.cf then 1 else 0) ||| (if pf then 4 else 0) |||
    (if af then 16 else 0) ||| (if flags.zf then 64 else 0) |||
    (if flags.sf then 128 else 0) ||| (if flags.of then 2048 else 0)

def flags (width : ScalarWidth) (kind : ArithmeticKind) (left right old : Reference.Word) : Reference.Word :=
  let carry := kind.carry old
  let a := narrow width left
  let b := narrow width right
  let result := value width kind.subtract carry left right
  let sign : Reference.Word := 1 <<< (width.bits - 1)
  let firstFour := match kind with
    | .add => GeneratedX86AddFlags.eval a b result sign
    | .adc => GeneratedX86Adc.flags a b result sign carry
    | .sub | .compare => GeneratedX86SubFlags.eval a b result sign
    | .sbb => GeneratedX86SbbFlags.eval a b result sign carry
  flagsWord old firstFour (GeneratedX86AuxFlags.parity result) (GeneratedX86AuxFlags.auxiliary a b result)

set_option maxRecDepth 4096 in
set_option maxHeartbeats 8000000 in
theorem flags_refine (width : ScalarWidth) (kind : ArithmeticKind) (left right old : Reference.Word) :
    flags width kind left right old =
      Reference.X86.arithmeticFlags width kind.subtract (kind.carry old) left right old := by
  cases width <;> cases kind <;>
    simp [flags, flagsWord, narrow, value_refines, X86AuxFlags.parity_refines,
      Reference.X86.arithmeticFlags, Reference.X86.arithmeticValue, Reference.X86.auxiliaryCarry,
      Reference.X86.ArithmeticKind.carry, Reference.X86.ArithmeticKind.subtract,
      GeneratedX86SbbFlags.eval, GeneratedX86SubFlags.eval, GeneratedX86Adc.flags,
      GeneratedX86AddFlags.eval, GeneratedX86AuxFlags.auxiliary,
      handlerWidth, GeneratedX86Width.narrow, GeneratedX86Width.mask,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, Reference.Word,
      Nat.reduceMul, Bool.false_eq_true, if_false, if_true] <;>
    bv_decide (config := { timeout := 120 })

/-- Carry is sampled before the flag writes, and only ADC/SBB consume it.
CMP reads and replaces flags without invoking a data write. -/
def handlerStep (width : ScalarWidth) (kind : ArithmeticKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (left, firstReads) =>
      match X86Scalar.read s width src with
      | .error fault => ⟨s, firstReads ++ [.fault fault], some fault⟩
      | .ok (right, secondReads) =>
          let carry := kind.carry s.rflags
          let resultFlags := flags width kind left right s.rflags
          let reads := firstReads ++ secondReads
          if kind = .compare then ⟨{ s with rflags := resultFlags, pc := nextPc }, reads, none⟩
          else
            match X86Scalar.write s width dst (value width kind.subtract carry left right) with
            | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
            | .ok (result, writes) => ⟨{ result with rflags := resultFlags, pc := nextPc }, reads ++ writes, none⟩

theorem step_refines (width : ScalarWidth) (kind : ArithmeticKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width kind dst src nextPc s = Reference.X86.step (.arithmetic width kind dst src nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.arithmeticStep,
    X86Scalar.read_refines, X86Scalar.write_refines, flags_refine, value_refines]
  rfl

theorem handler_refines (width : ScalarWidth) (kind : ArithmeticKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.arithmetic width kind dst src nextPc) s (handlerStep width kind dst src nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩


set_option maxRecDepth 4096 in
set_option maxHeartbeats 4000000 in
/-- Canonical CMP identity independently assessed by T (b0ad7c7cf): only
actual zero-borrow subtraction, with SF/OF from that same operation. -/
theorem compare_overflow_identity (width : ScalarWidth) (left right old : Reference.Word) :
    (Reference.X86.arithmeticFlags width true false left right old).getLsbD 11 =
      Bool.xor ((Reference.X86.arithmeticFlags width true false left right old).getLsbD 7)
        (((left.setWidth width.bits).signExtend 64).slt ((right.setWidth width.bits).signExtend 64)) := by
  cases width <;> simp only [Reference.X86.arithmeticFlags, Reference.X86.ScalarWidth.bits,
    Reference.X86.ScalarWidth.bytes, Reference.X86.evenParity, Reference.X86.auxiliaryCarry]
  all_goals unfold Reference.Word at *
  all_goals bv_decide

theorem compare_signed_operand (width : ScalarWidth) (value : Reference.Word) :
    GeneratedX86Signed.signExtend value (handlerWidth width) =
      (value.setWidth width.bits).signExtend 64 := by
  cases width <;> simp only [GeneratedX86Signed.signExtend, handlerWidth,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, GeneratedX86Width.signMask,
    GeneratedX86Width.bits, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
    Nat.reduceMul, reduceCtorEq, ↓reduceIte] <;> bv_decide

/-- The current production CMP body first computes the existing SUB flags,
then assigns OF = SF xor signedLT using the generated width sign extension. -/
def compareFlags (width : ScalarWidth) (left right old : Reference.Word) : Reference.Word :=
  let original := flags width .compare left right old
  let less := (GeneratedX86Signed.signExtend left (handlerWidth width)).slt
    (GeneratedX86Signed.signExtend right (handlerWidth width))
  Reference.X86.setFlag original 11 (Bool.xor (original.getLsbD 7) less)

/-- No arbitrary result/SF/borrow premise: the assignment is derived from
the exact preceding CMP. All flag bits, including PF/AF, remain identical. -/
theorem compare_flags_eq (width : ScalarWidth) (left right old : Reference.Word) :
    compareFlags width left right old = flags width .compare left right old := by
  have base : flags width .compare left right old =
      Reference.X86.arithmeticFlags width true false left right old := by
    simpa [Reference.X86.ArithmeticKind.subtract, Reference.X86.ArithmeticKind.carry] using
      flags_refine width .compare left right old
  have restore (word : Reference.Word) : Reference.X86.setFlag word 11 (word.getLsbD 11) = word := by
    clear base width left right old
    unfold Reference.X86.setFlag
    bv_decide
  have identity := compare_overflow_identity width left right old
  simpa only [compareFlags, base, compare_signed_operand, ← identity] using
    restore (Reference.X86.arithmeticFlags width true false left right old)

end KProgFormal.Refinement.X86Arithmetic
