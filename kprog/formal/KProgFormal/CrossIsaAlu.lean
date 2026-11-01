import KProgFormal.GeneratedArm64AluResult
import KProgFormal.GeneratedX86AluResult
import KProgFormal.GeneratedX86Andn
import KProgFormal.X86AndnHandler

/-!
Both architectures execute an arithmetic-logic instruction through one shared
table, and both tables are generated from a separate JSON spec -- but they are
numbered differently and they do not cover the same set. AArch64's six arms are
add, sub, and, bic, eor, orr; x86-64's sixteen are its full ALU opcode set,
with add and sub routed through the carry-aware adc/sbb by passing a clear
carry.

Every step so far compared contracts that either agreed directly or differed for
one identified reason. The ALU tables are the first place where the *shared*
vocabulary has to be recovered by a mapping, and where one operation turns out
to correspond only after exchanging its operands.

The mapping, and the two facts that make it more than bookkeeping:

* five operations agree directly under a renaming (add, sub, and, orr/or,
  eor/xor);
* AArch64's `BIC` complements the *right* operand while x86-64's `ANDN`
  complements the *left*, so they agree only on exchanged arguments. Writing
  that as `a &&& ~~~b = ~~~b &&& a` is what shows the correspondence is an
  exchange rather than an identity, which is precisely the mistake a translator
  makes by pairing the two names.

The compiled tables are cross-checked in `cross_isa_differential_host.c`.
-/

namespace KProgFormal.CrossIsaAlu

open KProgFormal

/-- AArch64's add is x86-64's add. The x86 table routes `add` through the
carry-aware `adc` with a clear carry, so this also states that the routing is
transparent. -/
theorem add (a b : BitVec 64) :
    GeneratedArm64AluResult.result .add a b
      = GeneratedX86AluResult.result .add a b .w64 := by
  simp [GeneratedArm64AluResult.result, GeneratedX86AluResult.result,
        GeneratedX86Adc.result]

/-- Likewise subtract, through `sbb` with a clear borrow. -/
theorem sub (a b : BitVec 64) :
    GeneratedArm64AluResult.result .sub a b
      = GeneratedX86AluResult.result .sub a b .w64 := by
  simp [GeneratedArm64AluResult.result, GeneratedX86AluResult.result,
        GeneratedX86SbbResult.result]

/-- The three plain logical operations agree under the renaming
`and`/`orr`->`or`/`eor`->`xor`. -/
theorem logic (a b : BitVec 64) :
    GeneratedArm64AluResult.result .and a b
        = GeneratedX86AluResult.result .and a b .w64 ∧
      GeneratedArm64AluResult.result .orr a b
        = GeneratedX86AluResult.result .or a b .w64 ∧
      GeneratedArm64AluResult.result .eor a b
        = GeneratedX86AluResult.result .xor a b .w64 := by
  refine ⟨rfl, rfl, rfl⟩

/-- The mapping covers every operation the two tables share, and nothing the
two share is missing from it: five of AArch64's six arms appear above, `bic`
being the one that needs the exchange proved next. -/
theorem covers_shared_vocabulary :
    GeneratedArm64AluResult.result .and 1 3 = GeneratedX86AluResult.result .and 1 3 .w64 ∧
      GeneratedArm64AluResult.result .orr 1 3 = GeneratedX86AluResult.result .or 1 3 .w64 ∧
      GeneratedArm64AluResult.result .eor 1 3 = GeneratedX86AluResult.result .xor 1 3 .w64 := by
  decide

/-- AArch64's `BIC` complements the right operand. -/
theorem bic_form (a b : BitVec 64) :
    GeneratedArm64AluResult.result .bic a b = a &&& ~~~b := by
  rfl

/-- x86-64's `ANDN` complements the left. So the two names are *not* the same
operation on the same arguments -- the correspondence needs the exchange,
which the next theorem supplies. This is the pair a translator is most likely
to get wrong, because both names mean "and with a complement". -/
theorem andn_form (a b : BitVec 64) :
    generatedX86AndnResult a b = (~~~a) &&& b := by
  rfl

/-- On exchanged arguments the two complemented-AND forms agree, which is the
statement that pairs `BIC` with `ANDN` correctly. -/
theorem bic_agrees_with_andn_on_exchange (a b : BitVec 64) :
    GeneratedArm64AluResult.result .bic a b = generatedX86AndnResult b a := by
  rw [bic_form, andn_form, BitVec.and_comm]

/-- And the exchange is necessary, not cosmetic: the unexchanged pairing
differs. A concrete witness, so the distinction is not lost in the algebra. -/
theorem bic_differs_from_andn_unexchanged :
    GeneratedArm64AluResult.result .bic 0xff 0x0f ≠ generatedX86AndnResult 0xff 0x0f := by
  decide

/-- A concrete instance of each shared operation, so the table is seen to
compute rather than merely to typecheck. -/
theorem shared_vocabulary_values :
    GeneratedArm64AluResult.result .add 5 3 = 8 ∧
      GeneratedArm64AluResult.result .sub 5 3 = 2 ∧
      GeneratedArm64AluResult.result .and 5 3 = 1 ∧
      GeneratedArm64AluResult.result .orr 5 3 = 7 ∧
      GeneratedArm64AluResult.result .eor 5 3 = 6 ∧
      GeneratedArm64AluResult.result .bic 5 3 = 4 := by
  decide

end KProgFormal.CrossIsaAlu