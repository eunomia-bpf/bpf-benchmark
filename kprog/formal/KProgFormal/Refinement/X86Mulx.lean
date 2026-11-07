import KProgFormal.X86MulxHandler
import KProgFormal.Refinement.X86Bzhi

namespace KProgFormal.Refinement.X86Mulx
open Reference
open Reference.X86 (BzhiWidth Register)

/-- The production single-product and four-limb arms, after native values
have been materialized. Both operands are captured before either write. -/
def parts (width : BzhiWidth) (left right : Reference.Word) : Reference.Word × Reference.Word :=
  match width with
  | .w32 =>
      let product := (left &&& 0xffffffff) * (right &&& 0xffffffff)
      ((product.setWidth 32).setWidth 64, ((product >>> 32).setWidth 32).setWidth 64)
  | .w64 => (left * right, x86MulxHighLadder left right)

theorem parts_refine (width : BzhiWidth) (left right : Reference.Word) :
    parts width left right = Reference.X86.mulxParts width left right := by
  cases width with
  | w32 => simp only [parts, Reference.X86.mulxParts, x86MulxMask32EqSetWidth]
  | w64 =>
      apply Prod.ext
      · change left * right = (left.setWidth 128 * right.setWidth 128).setWidth 64
        rw [BitVec.setWidth_mul _ _ (by decide)]
        simp
      · exact x86MulxHighLadderEqHighWord left right

def write (width : BzhiWidth) (old value : Reference.Word) : Reference.Word :=
  GeneratedX86RegWrite.bits old value (X86Bzhi.handlerWidth width)

theorem write_32 (old value : Reference.Word) :
    write .w32 old ((value.setWidth 32).setWidth 64) = (value.setWidth 32).setWidth 64 := by
  simp only [write, X86Bzhi.handlerWidth, GeneratedX86RegWrite.bits, Reference.Word]
  bv_decide

theorem write_64 (old value : Reference.Word) : write .w64 old value = value := rfl

theorem writes_parts (width : BzhiWidth) (old left right : Reference.Word) :
    write width old (Reference.X86.mulxParts width left right).1 = (Reference.X86.mulxParts width left right).1 ∧
    write width old (Reference.X86.mulxParts width left right).2 = (Reference.X86.mulxParts width left right).2 := by
  cases width <;> simp only [Reference.X86.mulxParts, write_32, write_64, and_self]

/-- The existing C opcode has an explicit register source and two present
register destinations. Its second assignment sees the first assignment's state,
so HI=LO leaves the high half, including when either aliases implicit RDX. -/
def handlerStep (width : BzhiWidth) (high low source : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  let product := parts width (s.gpr 2) (s.gpr source)
  let first := { s with gpr := fun r => if r = low then write width (s.gpr r) product.1 else s.gpr r }
  let second := { first with gpr := fun r => if r = high then write width (first.gpr r) product.2 else first.gpr r }
  ⟨{ second with pc := nextPc }, [], none⟩

theorem step_refines (width : BzhiWidth) (high low source : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    handlerStep width high low source nextPc s =
      Reference.X86.step (.mulx width high low (.register source) nextPc) s := by
  simp only [handlerStep, parts_refine, Reference.X86.step, Reference.X86.mulxStep,
    Reference.X86.readSource]
  simp only [(writes_parts width _ _ _).1, (writes_parts width _ _ _).2]

theorem handler_refines (width : BzhiWidth) (high low source : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.mulx width high low (.register source) nextPc) s
      (handlerStep width high low source nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
end KProgFormal.Refinement.X86Mulx
