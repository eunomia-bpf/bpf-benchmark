import KProgFormal.Refinement.X86Scalar
import KProgFormal.X86XchgHandler

namespace KProgFormal.Refinement.X86Exchange
open Reference
open Reference.X86 (ScalarWidth Register)

/-- The implemented register handler selects a full pointer-cell exchange at
64 bits and generated partial/zero-extending writes at other widths. Values
here are native bits supplied by the existing entry/address relation. -/
def write (width : ScalarWidth) (old source : Reference.Word) : Reference.Word :=
  match GeneratedX86Xchg.armOf width.bytes with
  | .pointerSwap => source
  | .subwordSwap => GeneratedX86RegWrite.bits old source (X86Scalar.handlerWidth width)

theorem write_refines (width : ScalarWidth) (reg : Register) (old source : Reference.Word) :
    write width old source = Reference.X86.scalarWriteValue old
      ((source.setWidth width.bits).setWidth 64) width (.low reg) := by
  cases width <;> simp [write, GeneratedX86Xchg.armOf, GeneratedX86Xchg.fullWidthCode,
    Reference.X86.ScalarWidth.bytes, Reference.X86.ScalarWidth.bits,
    Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift,
    X86Scalar.handlerWidth, GeneratedX86RegWrite.bits, reduceCtorEq, ↓reduceIte,
    Nat.reduceMul, Reference.Word] <;> bv_decide

theorem low_read (s : Reference.X86.State) (width : ScalarWidth) (r : Register) :
    Reference.X86.scalarRegisterValue s width (.low r) =
      ((s.gpr r).setWidth width.bits).setWidth 64 := by
  simp only [Reference.X86.scalarRegisterValue, Reference.X86.RegisterSlice.reg,
    Reference.X86.RegisterSlice.shift, Reference.Word]
  bv_decide

/-- Both raw values are captured before either assignment, including when
DST=SRC. The second write uses the state after the first assignment. -/
def handlerStep (width : ScalarWidth) (left right : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  let a := s.gpr left
  let b := s.gpr right
  let first := { s with gpr := fun r => if r = left then write width (s.gpr r) b else s.gpr r }
  let second := { first with gpr := fun r => if r = right then write width (first.gpr r) a else first.gpr r }
  ⟨{ second with pc := nextPc }, [], none⟩

theorem step_refines (width : ScalarWidth) (left right : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    handlerStep width left right nextPc s =
      Reference.X86.step (.exchange width (.low left) (.low right) nextPc) s := by
  simp only [handlerStep, write_refines width left, write_refines width right,
    Reference.X86.step, Reference.X86.exchangeStep, low_read, Reference.X86.RegisterSlice.reg]
  rfl

theorem handler_refines (width : ScalarWidth) (left right : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.exchange width (.low left) (.low right) nextPc) s
      (handlerStep width left right nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
end KProgFormal.Refinement.X86Exchange
