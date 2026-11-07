import KProgFormal.Generated.GeneratedArm64StackArena
import KProgFormal.Generated.GeneratedX86StackArena

/-!
The two ISAs render independent stack-arena contracts from independent
specifications, and twelve of the resulting theorems share a concept name
(`stack_arena_window_fits_refines`, `stack_arena_pointer_one_past_end`, and so
on). That sharing was structural, not proved: nothing showed the two generated
contracts compute the same arithmetic.

Unlike the width vocabulary, the two stack contracts are *not* textually
identical -- x86 carries `byteAt`/`assembleByte` for its little-endian byte
ladder, and arm64 carries `tagSlotFits` for the tag array it has and x86 does
not. But the six definitions both sides share do agree, and this module proves
it, so a drift in either spec breaks the build here.

The per-ISA theorems are already proved against each contract separately; this
adds only the relation between them.
-/

namespace KProgFormal.CrossIsaStackArena

open KProgFormal

private theorem nativeWidth_restricts (v : BitVec 32) :
    v.toNat % 18446744073709551616 = v.toNat := by
  apply Nat.mod_eq_of_lt
  have := v.isLt
  omega

/-- The word-slot shift agrees: both index the word view by the byte index
shifted right three. -/
theorem wordIndex_agrees (index : BitVec 32) :
    GeneratedArm64StackArena.wordIndex index =
      (GeneratedX86StackArena.wordIndex (index.zeroExtend 64)).truncate 32 := by
  unfold GeneratedArm64StackArena.wordIndex GeneratedX86StackArena.wordIndex
  bv_decide

/-- The alignment guard agrees, so the 64-bit fast path is selected at the same
indices on both ISAs for capacities whose low-width rounding does not wrap. -/
theorem wordAligned_agrees (index : BitVec 32) :
    GeneratedArm64StackArena.wordAligned index =
      GeneratedX86StackArena.wordAligned (index.zeroExtend 64) := by
  unfold GeneratedArm64StackArena.wordAligned GeneratedX86StackArena.wordAligned
  bv_decide

/-- The word-slot count agrees, so a capacity needs the same number of qwords
on both ISAs. -/
theorem words_agrees (capacity : BitVec 32)
    (h : capacity <= 4294967288) :
    GeneratedArm64StackArena.words capacity =
      (GeneratedX86StackArena.words (capacity.zeroExtend 64)).truncate 32 := by
  unfold GeneratedArm64StackArena.words GeneratedX86StackArena.words
  bv_decide

/-- The access-window end agrees: the first index past a `width`-byte access
is the same `Nat` on both. -/
theorem windowEnd_agrees (index width : BitVec 32) :
    GeneratedArm64StackArena.windowEnd index width =
      GeneratedX86StackArena.windowEnd (index.zeroExtend 64) (width.zeroExtend 64) := by
  simp [nativeWidth_restricts, GeneratedArm64StackArena.windowEnd, GeneratedX86StackArena.windowEnd]

/-- The window bound agrees, so a fitting access is the same set of
`(index, width, capacity)` triples on both ISAs. -/
theorem windowFits_agrees (index width capacity : BitVec 32) :
    GeneratedArm64StackArena.windowFits index width capacity =
      GeneratedX86StackArena.windowFits (index.zeroExtend 64) (width.zeroExtend 64) (capacity.zeroExtend 64) := by
  simp [nativeWidth_restricts, GeneratedArm64StackArena.windowFits, GeneratedArm64StackArena.windowEnd,
    GeneratedX86StackArena.windowFits, GeneratedX86StackArena.windowEnd]

/-- The pointer bound agrees, so the one-past-end rule is the same on
both. -/
theorem pointerFits_agrees (index capacity : BitVec 32) :
    GeneratedArm64StackArena.pointerFits index capacity =
      GeneratedX86StackArena.pointerFits (index.zeroExtend 64) (capacity.zeroExtend 64) := by
  simp [nativeWidth_restricts, GeneratedArm64StackArena.pointerFits, GeneratedX86StackArena.pointerFits]

/-- Concrete witness at each ISA's default frame: the two agree on which
8-byte accesses fit, checked through the shared `windowFits` rather than by
unfolding either contract. -/
theorem windowFits_agrees_example :
    GeneratedArm64StackArena.windowFits 152 8 160 =
        GeneratedX86StackArena.windowFits 152 8 160 ∧
      GeneratedArm64StackArena.windowFits 153 8 160 =
        GeneratedX86StackArena.windowFits 153 8 160 := by
  exact ⟨rfl, rfl⟩

end KProgFormal.CrossIsaStackArena