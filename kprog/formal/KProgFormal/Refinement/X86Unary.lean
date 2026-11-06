import KProgFormal.Refinement.X86Arithmetic
import KProgFormal.Generated.GeneratedX86AluResult

namespace KProgFormal.Refinement.X86Unary
open Reference
open Reference.X86 (ScalarWidth UnaryKind)
def alu : UnaryKind → GeneratedX86AluDecode.Alu
  | .inc => .inc | .dec => .dec | .neg => .neg | .not => .not

def value (width : ScalarWidth) (kind : UnaryKind) (source : Reference.Word) : Reference.Word :=
  X86Arithmetic.narrow width (GeneratedX86AluResult.result (alu kind)
    (X86Arithmetic.narrow width source) 0 (X86Scalar.handlerWidth width))

theorem value_refines (width : ScalarWidth) (kind : UnaryKind) (source : Reference.Word) :
    value width kind source = Reference.X86.unaryValue width kind source := by
  cases width <;> cases kind <;>
    simp [value, alu, X86Arithmetic.narrow, X86Scalar.handlerWidth, GeneratedX86AluResult.result,
      GeneratedX86Width.narrow, GeneratedX86Width.mask, GeneratedX86Adc.result,
      GeneratedX86SbbResult.result, GeneratedX86Not.result, Reference.X86.unaryValue,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes] <;> bv_decide

def flags (width : ScalarWidth) (kind : UnaryKind) (source old : Reference.Word) : Reference.Word :=
  match kind with
  | .inc => Reference.X86.setFlag (X86Arithmetic.flags width .add source 1 old) 0 (old.getLsbD 0)
  | .dec => Reference.X86.setFlag (X86Arithmetic.flags width .sub source 1 old) 0 (old.getLsbD 0)
  | .neg => X86Arithmetic.flags width .sub 0 source old
  | .not => old

theorem flags_refine (width : ScalarWidth) (kind : UnaryKind) (source old : Reference.Word) :
    flags width kind source old = Reference.X86.unaryFlags width kind source old := by
  cases kind <;> simp [flags, Reference.X86.unaryFlags, X86Arithmetic.flags_refine,
    Reference.X86.ArithmeticKind.subtract, Reference.X86.ArithmeticKind.carry] <;> rfl


def handlerStep (width : ScalarWidth) (kind : UnaryKind) (dst : Reference.X86.ScalarDestination)
    (nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (source, reads) =>
      match X86Scalar.write s width dst (value width kind source) with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) =>
          ⟨{ result with rflags := flags width kind source s.rflags, pc := nextPc }, reads ++ writes, none⟩

theorem step_refines (width : ScalarWidth) (kind : UnaryKind) (dst : Reference.X86.ScalarDestination)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width kind dst nextPc s = Reference.X86.step (.unary width kind dst nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.unaryStep,
    X86Scalar.read_refines, X86Scalar.write_refines, flags_refine, value_refines]
  rfl

theorem handler_refines (width : ScalarWidth) (kind : UnaryKind) (dst : Reference.X86.ScalarDestination)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.unary width kind dst nextPc) s (handlerStep width kind dst nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Unary
