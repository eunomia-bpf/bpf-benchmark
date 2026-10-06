import KProgFormal.GeneratedArm64StackArena
import KProgFormal.GeneratedArm64ByteLane
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64StackArena (wordIndex wordAligned words)
open GeneratedArm64ByteLane (ByteLane)

/-- Independent statement of the word-arena slot: the byte index divided by the
word size, matching the union's `b`/`q` aliasing where `q[i]` occupies bytes
`8i..8i+8`. A different expression tree (`udiv`) than the generated shift. -/
def arm64StackArenaWordIndexSpec (index : BitVec 32) : BitVec 32 :=
  index / 8

/-- Independent statement of the fast-path guard: the index is word-aligned,
stated as `index % 8 == 0` against the generated low-bit mask. -/
def arm64StackArenaWordAlignedSpec (index : BitVec 32) : Bool :=
  index % 8 == 0

/-- Independent statement of the word-slot count: the capacity rounded up to a
whole number of words, stated as `cap/8` plus a remainder term without the
generator's `+7` fold. -/
def arm64StackArenaWordsSpec (capacity : BitVec 32) : BitVec 32 :=
  capacity >>> 3 + (if capacity &&& 7 == 0 then 0 else 1)

/-- The generated slot arithmetic equals the independent division. -/
theorem arm64_stack_arena_word_index_refines (index : BitVec 32) :
    wordIndex index = arm64StackArenaWordIndexSpec index := by
  simp only [wordIndex, arm64StackArenaWordIndexSpec]
  bv_decide

/-- The generated guard agrees with the independent remainder test. -/
theorem arm64_stack_arena_word_aligned_refines (index : BitVec 32) :
    wordAligned index = arm64StackArenaWordAlignedSpec index := by
  simp only [wordAligned, arm64StackArenaWordAlignedSpec]
  bv_decide

/-- The generated slot count equals the independent round-up on every capacity
whose `+7` does not overflow the 32-bit index type. -/
theorem arm64_stack_arena_words_refines (capacity : BitVec 32)
    (h : capacity ≤ BitVec.ofNat 32 (2 ^ 32 - 8)) :
    words capacity = arm64StackArenaWordsSpec capacity := by
  simp only [words, arm64StackArenaWordsSpec]
  bv_decide

/-- The two views cover the same storage: on a word-aligned index the byte the
word arena addresses is the byte the byte arena addresses, `q[i]` and `b[8i]`
coincide, so the 64-bit fast path skips no byte. -/
theorem arm64_stack_arena_views_coincide (index : BitVec 32)
    (h : index % 8 = 0) :
    wordIndex index * 8 = index := by
  simp only [wordIndex]
  bv_decide

/-- The byte ladder's lane 0 is the low byte of the word the word arena holds:
a 64-bit stack store under the fast path writes `q[slot]`, whose own byte 0 is
the value's byte 0, so the word and byte paths agree on the first byte. -/
theorem arm64_stack_arena_lane0_agrees (value : BitVec 64) :
    GeneratedArm64ByteLane.byteAt .lane0 value = value.truncate 8 := by
  simp only [GeneratedArm64ByteLane.byteAt, GeneratedArm64ByteLane.shift,
    GeneratedArm64ByteLane.index]
  bv_decide

/-- Canonical example: the enabled 160-byte arena needs exactly 20 word slots. -/
theorem arm64_stack_arena_words_160 : words 160 = 20 := by decide

/-- Canonical example: the disabled 1-byte arena still needs a word slot. -/
theorem arm64_stack_arena_words_1 : words 1 = 1 := by decide

/-- Canonical example: a non-multiple capacity rounds up. -/
theorem arm64_stack_arena_words_161 : words 161 = 21 := by decide

/-- Canonical example: the frame-base byte index, 0, is word-aligned and slot 0. -/
theorem arm64_stack_arena_index_zero :
    arm64StackArenaWordAlignedSpec 0 = true ∧
      arm64StackArenaWordIndexSpec 0 = 0 := by
  refine ⟨?_, ?_⟩ <;> decide

/-- Canonical example: byte index 96 is word-aligned and lands at slot 12. -/
theorem arm64_stack_arena_index_96 :
    arm64StackArenaWordAlignedSpec 96 = true ∧
      arm64StackArenaWordIndexSpec 96 = 12 := by
  refine ⟨?_, ?_⟩ <;> decide

/-- Canonical example: byte index 1 is not word-aligned and rounds to slot 0. -/
theorem arm64_stack_arena_index_1 :
    arm64StackArenaWordAlignedSpec 1 = false ∧
      arm64StackArenaWordIndexSpec 1 = 0 := by
  refine ⟨?_, ?_⟩ <;> decide

/-- Canonical example: the top of the enabled arena, byte 159, is not aligned
and indexes the last word slot, 19. -/
theorem arm64_stack_arena_index_159 :
    arm64StackArenaWordAlignedSpec 159 = false ∧
      arm64StackArenaWordIndexSpec 159 = 19 := by
  refine ⟨?_, ?_⟩ <;> decide

/-- Canonical example: a word-aligned store's slot ties back to its byte. -/
theorem arm64_stack_arena_roundtrip_example :
    arm64StackArenaWordAlignedSpec 160 = true ∧
      arm64StackArenaWordIndexSpec 160 * 8 = 160 := by
  refine ⟨?_, ?_⟩ <;> decide

end KProgFormal
