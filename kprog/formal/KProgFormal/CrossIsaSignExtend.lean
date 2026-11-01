import KProgFormal.GeneratedArm64Extrev
import KProgFormal.GeneratedX86Signed

/-!
Both architectures sign-extend a narrow value into a 64-bit register, and they
do it with entirely different code. AArch64's generated contract states it as a
generic "extend the low `nb` bits" procedure parameterised by a bit count, and
the simulator's C inlines it as the mask-flip-subtract idiom. x86-64's states
each width as its own arm with the constants written out.

Two spellings of one function, then, and nothing related them. That is the
shape a signedness fault takes: an extension that masks before flipping the
sign bit, or flips the wrong one, still produces a plausible register value and
still round-trips for positive inputs, so boundary cases are where it shows.
This module proves the two agree at all three widths AArch64's contract
parameterises and x86-64's names.

The C layer is checked exhaustively rather than by sampling, in
`cross_isa_differential_host.c`: every 16-bit pattern through both the byte and
halfword paths, and a strided sweep of the 32-bit space.
-/

namespace KProgFormal.CrossIsaSignExtend

open KProgFormal

/-- AArch64's generic extension at eight bits is x86-64's byte extension. -/
theorem byte (v : BitVec 64) :
    GeneratedArm64Extrev.signExtend v 8 = GeneratedX86Signed.signExtend v .w8 := by
  simp only [GeneratedArm64Extrev.signExtend, GeneratedX86Signed.signExtend]
  rw [show BitVec.ofNat 64 (2 ^ 8 - 1) = (255 : BitVec 64) from by decide,
      show BitVec.ofNat 64 (2 ^ (8 - 1)) = (128 : BitVec 64) from by decide]

/-- At sixteen bits. -/
theorem halfword (v : BitVec 64) :
    GeneratedArm64Extrev.signExtend v 16 = GeneratedX86Signed.signExtend v .w16 := by
  simp only [GeneratedArm64Extrev.signExtend, GeneratedX86Signed.signExtend]
  rw [show BitVec.ofNat 64 (2 ^ 16 - 1) = (65535 : BitVec 64) from by decide,
      show BitVec.ofNat 64 (2 ^ (16 - 1)) = (32768 : BitVec 64) from by decide]

/-- At thirty-two bits. -/
theorem word (v : BitVec 64) :
    GeneratedArm64Extrev.signExtend v 32 = GeneratedX86Signed.signExtend v .w32 := by
  simp only [GeneratedArm64Extrev.signExtend, GeneratedX86Signed.signExtend]
  rw [show BitVec.ofNat 64 (2 ^ 32 - 1) = (4294967295 : BitVec 64) from by decide,
      show BitVec.ofNat 64 (2 ^ (32 - 1)) = (2147483648 : BitVec 64) from by decide]

/-- And the boundary that a masking fault would break: `0x7f` stays positive,
`0x80` becomes the most negative byte. -/
theorem byte_boundaries :
    GeneratedX86Signed.signExtend 0x7f .w8 = 0x7f ∧
      GeneratedX86Signed.signExtend 0x80 .w8 = (BitVec.ofInt 64 (-128)) ∧
      GeneratedArm64Extrev.signExtend 0x80 8 = BitVec.ofInt 64 (-128) := by
  refine ⟨?_, ?_, ?_⟩ <;> decide

/-- The 64-bit case is the identity on the x86 side and has no AArch64
counterpart to relate, since AArch64's contract is parameterised only up to 32
bits -- `SXTX` is not in the extend family. Recorded so the three-width
statement is not mistaken for a four-width one. -/
theorem word_is_narrowest_unrelated (v : BitVec 64) :
    GeneratedX86Signed.signExtend v .w64 = v := by rfl

end KProgFormal.CrossIsaSignExtend