import KProgFormal.Refinement.X86Arithmetic
import KProgFormal.Refinement.X86Bt
import KProgFormal.X86Popcount
import KProgFormal.Generated.GeneratedX86PopcntFlags
namespace KProgFormal.Refinement.X86Popcount
open Reference
open Reference.X86 (CmovWidth)

theorem legacy_spec_is_canonical (value : Reference.Word) :
    x86PopcountSpec value = Reference.X86.populationCount value := rfl

def value (width : CmovWidth) (source : Reference.Word) : Reference.Word :=
  GeneratedX86Popcount.value (GeneratedX86Width.narrow source (X86Cmov.handlerWidth width))

theorem value_refines (width : CmovWidth) (source : Reference.Word) :
    value width source = Reference.X86.popcountValue width source := by
  unfold value
  rw [x86_popcount_refines, legacy_spec_is_canonical]
  congr 1
  cases width <;> simp [GeneratedX86Width.narrow, GeneratedX86Width.mask,
    X86Cmov.handlerWidth, Reference.X86.CmovWidth.bytes] <;> bv_decide

def flags (width : CmovWidth) (source old : Reference.Word) : Reference.Word :=
  let firstFour := GeneratedX86PopcntFlags.eval (GeneratedX86Width.narrow source (X86Cmov.handlerWidth width) == 0)
  X86Arithmetic.flagsWord old ⟨firstFour.cf, firstFour.zf, firstFour.sf, firstFour.of⟩ false false

theorem flags_refine (width : CmovWidth) (source old : Reference.Word) :
    flags width source old = Reference.X86.popcountFlags width source old := by
  cases width <;> simp [flags, Reference.X86.popcountFlags, GeneratedX86PopcntFlags.eval,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, X86Cmov.handlerWidth, X86Arithmetic.flagsWord,
    Reference.X86.CmovWidth.bytes] <;> bv_decide

def handlerStep (width : CmovWidth) (dst src : Reference.X86.Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  let result := X86Cmov.handlerValue width true ⟨s.gpr dst, .scalar⟩ ⟨value width (s.gpr src), .scalar⟩
  ⟨{ s with gpr := (fun r => if r = dst then result.bits else s.gpr r), rflags := flags width (s.gpr src) s.rflags, pc := nextPc }, [], none⟩

theorem step_refines (width : CmovWidth) (dst src : Reference.X86.Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    handlerStep width dst src nextPc s = Reference.X86.step (.popcount width dst (.register src) nextPc) s := by
  simp [handlerStep, Reference.X86.step, Reference.X86.readSource,
    value_refines, flags_refine, X86Cmov.value_refines]

theorem handler_refines (width : CmovWidth) (dst src : Reference.X86.Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.popcount width dst (.register src) nextPc) s (handlerStep width dst src nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
/-- The memory-source route uses the existing exact-width memory primitive. -/
def memoryHandlerStep (width : CmovWidth) (dst : Reference.X86.Register)
    (address nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Bt.readOperand width (.memory address) s with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (source, events) =>
      let result := X86Cmov.handlerValue width true ⟨s.gpr dst, .scalar⟩ ⟨value width source, .scalar⟩
      ⟨{ s with gpr := (fun r => if r = dst then result.bits else s.gpr r), rflags := flags width source s.rflags, pc := nextPc }, events, none⟩

theorem memory_step_refines (width : CmovWidth) (dst : Reference.X86.Register)
    (address nextPc : Reference.Word) (s : Reference.X86.State) :
    memoryHandlerStep width dst address nextPc s =
      Reference.X86.step (.popcount width dst (.memory address) nextPc) s := by
  simp only [memoryHandlerStep, X86Bt.read_refines, Reference.X86.step]
  cases h : Reference.X86.readSource s (.memory address) width.bytes with
  | error fault => simp only [h]
  | ok pair => simp [h, value_refines, flags_refine, X86Cmov.value_refines]

theorem memory_handler_refines (width : CmovWidth) (dst : Reference.X86.Register)
    (address nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.popcount width dst (.memory address) nextPc) s
      (memoryHandlerStep width dst address nextPc s) := by
  rw [memory_step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Popcount
