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

end KProgFormal.Refinement.X86Arithmetic
