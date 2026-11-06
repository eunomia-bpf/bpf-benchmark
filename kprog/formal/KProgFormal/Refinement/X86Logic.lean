import KProgFormal.Refinement.X86Arithmetic
import KProgFormal.Generated.GeneratedX86AluResult

namespace KProgFormal.Refinement.X86Logic
open Reference
open Reference.X86 (ScalarWidth LogicKind)

def alu : LogicKind → GeneratedX86AluDecode.Alu
  | .and | .test => .and | .or => .or | .xor => .xor

def value (width : ScalarWidth) (kind : LogicKind) (left right : Reference.Word) : Reference.Word :=
  X86Arithmetic.narrow width (GeneratedX86AluResult.result (alu kind)
    (X86Arithmetic.narrow width left) (X86Arithmetic.narrow width right) (X86Scalar.handlerWidth width))

theorem value_refines (width : ScalarWidth) (kind : LogicKind) (left right : Reference.Word) :
    value width kind left right = Reference.X86.logicalValue width kind left right := by
  cases width <;> cases kind <;>
    simp [value, alu, X86Arithmetic.narrow, X86Scalar.handlerWidth, GeneratedX86AluResult.result,
      GeneratedX86Width.narrow, GeneratedX86Width.mask, Reference.X86.logicalValue,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes] <;> bv_decide

def flags (width : ScalarWidth) (kind : LogicKind) (left right old : Reference.Word) : Reference.Word :=
  let result := value width kind left right
  let firstFour := GeneratedX86LogicFlags.eval (result == 0) ((result &&& (1 <<< (width.bits - 1))) != 0)
  X86Arithmetic.flagsWord old firstFour (GeneratedX86AuxFlags.parity result) (old.getLsbD 4)

theorem flags_refine (width : ScalarWidth) (kind : LogicKind) (left right old : Reference.Word) :
    flags width kind left right old = Reference.X86.logicalFlags width kind left right old := by
  cases width <;>
    simp [flags, value_refines, X86AuxFlags.parity_refines, Reference.X86.logicalFlags, Reference.X86.logicalValue, Reference.X86.evenParity,
      X86Arithmetic.flagsWord, GeneratedX86LogicFlags.eval, Reference.X86.ScalarWidth.bits,
      Reference.X86.ScalarWidth.bytes, Nat.reduceMul] <;> bv_decide

open Reference
open Reference.X86 (ScalarWidth LogicKind ScalarSource ScalarDestination)
def handlerStep (width : ScalarWidth) (kind : LogicKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (left, firstReads) =>
      match X86Scalar.read s width src with
      | .error fault => ⟨s, firstReads ++ [.fault fault], some fault⟩
      | .ok (right, secondReads) =>
          let resultFlags := flags width kind left right s.rflags
          let reads := firstReads ++ secondReads
          if kind = .test then ⟨{ s with rflags := resultFlags, pc := nextPc }, reads, none⟩
          else
            match X86Scalar.write s width dst (value width kind left right) with
            | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
            | .ok (result, writes) => ⟨{ result with rflags := resultFlags, pc := nextPc }, reads ++ writes, none⟩

theorem step_refines (width : ScalarWidth) (kind : LogicKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width kind dst src nextPc s = Reference.X86.step (.logic width kind dst src nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.logicalStep, X86Scalar.read_refines,
    X86Scalar.write_refines, flags_refine, value_refines]
  rfl

theorem handler_refines (width : ScalarWidth) (kind : LogicKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.logic width kind dst src nextPc) s (handlerStep width kind dst src nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Logic
