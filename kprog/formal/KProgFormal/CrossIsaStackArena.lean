import KProgFormal.GeneratedArm64StackArena
import KProgFormal.GeneratedX86StackArena

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

/-- The word-slot shift agrees: both index the word view by the byte index
shifted right three. -/
theorem wordIndex_agrees (index : BitVec 32) :
    GeneratedArm64StackArena.wordIndex index =
      GeneratedX86StackArena.wordIndex index := rfl

/-- The alignment guard agrees, so the 64-bit fast path is selected at the same
indices on both ISAs. -/
theorem wordAligned_agrees (index : BitVec 32) :
    GeneratedArm64StackArena.wordAligned index =
      GeneratedX86StackArena.wordAligned index := rfl

/-- The word-slot count agrees, so a capacity needs the same number of qwords
on both ISAs. -/
theorem words_agrees (capacity : BitVec 32) :
    GeneratedArm64StackArena.words capacity =
      GeneratedX86StackArena.words capacity := rfl

/-- The access-window end agrees: the first index past a `width`-byte access
is the same `Nat` on both. -/
theorem windowEnd_agrees (index width : BitVec 32) :
    GeneratedArm64StackArena.windowEnd index width =
      GeneratedX86StackArena.windowEnd index width := rfl

/-- The window bound agrees, so a fitting access is the same set of
`(index, width, capacity)` triples on both ISAs. -/
theorem windowFits_agrees (index width capacity : BitVec 32) :
    GeneratedArm64StackArena.windowFits index width capacity =
      GeneratedX86StackArena.windowFits index width capacity := rfl

/-- The pointer bound agrees, so the one-past-end rule is the same on
both. -/
theorem pointerFits_agrees (index capacity : BitVec 32) :
    GeneratedArm64StackArena.pointerFits index capacity =
      GeneratedX86StackArena.pointerFits index capacity := rfl

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