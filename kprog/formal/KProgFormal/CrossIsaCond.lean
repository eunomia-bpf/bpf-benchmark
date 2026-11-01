import KProgFormal.GeneratedArm64Cond
import KProgFormal.GeneratedX86Cond

/-!
The two architectures name their branch conditions differently and derive them
from differently-named flags. Step 0490 proved the one place the flags
themselves differ in meaning: AArch64's subtract carry is *not-borrow* while
x86-64's is *borrow*, exact complements on the same operands. This module
proves what follows for the conditions -- that under the flag correspondence

  AArch64 `N Z C V`  =  `SF ZF (!CF) OF`

the two evaluators agree condition for condition, so a branch written in one
ISA's vocabulary decides exactly as the equivalent branch in the other's.

That is the property a cross-ISA translation depends on, and it is not obvious
from the names: `CS` maps to `AE` (not to `B`), `CC` to `B`, `MI` to `S`, `HI`
to `A`, `LS` to `BE`. Getting any one of them backwards is the classic
condition-inversion bug, and it would typecheck.

Both evaluators are already proved against their own generated contracts and
checked at the C layer; what was missing is the relation between them.
-/

namespace KProgFormal.CrossIsaCond

open KProgFormal

/-- The flag correspondence, stated once. AArch64's carry is the negation of
x86-64's, which is the only difference at the flag level. -/
abbrev arm64Flags (cf zf sf of_ : Bool) : Bool × Bool × Bool × Bool :=
  (sf, zf, !cf, of_)

/-- The condition correspondence as a function, so the theorem below can be
stated over it and a wrong entry shows up as a failing case rather than being
hidden in a hand-written conjunction. -/
def toX86 : GeneratedArm64Cond.Cond → GeneratedX86Cond.Cond
  | .eq => .e
  | .ne => .ne
  | .cs => .ae
  | .cc => .b
  | .mi => .s
  | .pl => .ns
  | .vs => .o
  | .vc => .no
  | .hi => .a
  | .ls => .be
  | .ge => .ge
  | .lt => .l
  | .gt => .g
  | .le => .le
  | .al => .a

/-- Every condition except `AL` decides identically under the flag
correspondence. `AL` is excluded because AArch64's `AL` is unconditional
(`true`) while x86-64 has no such condition -- the compiler simply omits the
branch -- so it is a statement about lowering rather than about flags. -/
theorem agrees (cf zf sf of_ : Bool) (c : GeneratedArm64Cond.Cond)
    (h : c ≠ .al) :
    GeneratedArm64Cond.eval sf zf (!cf) of_ c =
      GeneratedX86Cond.eval cf zf sf of_ (toX86 c) := by
  cases c <;>
    (first | cases cf <;> cases zf <;> cases sf <;> cases of_ <;> rfl | exact absurd rfl h)

/-- The mapping is not free: `CS` must go to `AE`. Sending it to `B` -- the
condition whose *name* suggests the same thing, since AArch64's carry-set
condition follows a compare that produced a borrow -- is wrong, and here is the
concrete disagreement. This is the condition-inversion bug the theorem rules
out. -/
theorem cs_is_ae_not_b :
    GeneratedArm64Cond.eval false false true false .cs ≠
      GeneratedX86Cond.eval false false true false .b := by
  decide

/-- The same for the sign conditions, which map by name rather than by carry:
AArch64's `MI` (minus) is x86-64's `S` (sign), and AArch64's `VS` (overflow
set) is x86-64's `O`. -/
theorem mi_is_s_and_vs_is_o :
    toX86 .mi = .s ∧ toX86 .vs = .o ∧ toX86 .cs = .ae ∧ toX86 .cc = .b := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- And the mapping is injective on the 14 comparable conditions, so the
correspondence loses nothing: two distinct AArch64 conditions never collapse
onto one x86 condition, which would make one of them unreachable in a
translation. -/
theorem toX86_injective (a b : GeneratedArm64Cond.Cond) (ha : a ≠ .al)
    (hb : b ≠ .al) (h : toX86 a = toX86 b) : a = b := by
  cases a <;> cases b <;> simp_all [toX86]

end KProgFormal.CrossIsaCond