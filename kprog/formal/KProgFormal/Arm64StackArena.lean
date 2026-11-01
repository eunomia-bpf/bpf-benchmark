import KProgFormal.GeneratedArm64StackArena
import KProgFormal.GeneratedArm64ByteLane
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64StackArena (wordIndex wordAligned words windowEnd windowFits
  tagSlotFits)
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
theorem arm64_stack_arena_words_160 : words 160 = 20 := by native_decide

/-- Canonical example: the disabled 1-byte arena still needs a word slot. -/
theorem arm64_stack_arena_words_1 : words 1 = 1 := by native_decide

/-- Canonical example: a non-multiple capacity rounds up. -/
theorem arm64_stack_arena_words_161 : words 161 = 21 := by native_decide

/-- Canonical example: the frame-base byte index, 0, is word-aligned and slot 0. -/
theorem arm64_stack_arena_index_zero :
    arm64StackArenaWordAlignedSpec 0 = true ∧
      arm64StackArenaWordIndexSpec 0 = 0 := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Canonical example: byte index 96 is word-aligned and lands at slot 12. -/
theorem arm64_stack_arena_index_96 :
    arm64StackArenaWordAlignedSpec 96 = true ∧
      arm64StackArenaWordIndexSpec 96 = 12 := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Canonical example: byte index 1 is not word-aligned and rounds to slot 0. -/
theorem arm64_stack_arena_index_1 :
    arm64StackArenaWordAlignedSpec 1 = false ∧
      arm64StackArenaWordIndexSpec 1 = 0 := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Canonical example: the top of the enabled arena, byte 159, is not aligned
and indexes the last word slot, 19. -/
theorem arm64_stack_arena_index_159 :
    arm64StackArenaWordAlignedSpec 159 = false ∧
      arm64StackArenaWordIndexSpec 159 = 19 := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Canonical example: a word-aligned store's slot ties back to its byte. -/
theorem arm64_stack_arena_roundtrip_example :
    arm64StackArenaWordAlignedSpec 160 = true ∧
      arm64StackArenaWordIndexSpec 160 * 8 = 160 := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Independent statement of the access window's end: the first index past a
`width`-byte access, stated as a subtraction from the 64-bit top rather than a
sum. -/
def arm64StackArenaWindowEndSpec (index width : BitVec 32) : Nat :=
  2 ^ 32 - (2 ^ 32 - index.toNat - width.toNat)

/-- Independent statement of the fit test: the window start is inside the arena
and the bytes remaining from it cover the width, `index <= capacity` and
`capacity - index >= width`. Both conjuncts are needed because `Nat`
subtraction truncates, so the remainder alone would accept an index past the
arena. -/
def arm64StackArenaWindowFitsSpec (index width capacity : BitVec 32) : Bool :=
  decide (index.toNat ≤ capacity.toNat ∧ width.toNat ≤ capacity.toNat - index.toNat)

/-- The generated window end equals the independent restatement on every window
whose end stays inside the index space. -/
theorem arm64_stack_arena_window_end_refines (index width : BitVec 32)
    (hnoWrap : index.toNat + width.toNat ≤ 2 ^ 32) :
    windowEnd index width = arm64StackArenaWindowEndSpec index width := by
  simp only [windowEnd, arm64StackArenaWindowEndSpec]
  omega

/-- The generated fit test agrees with the independent subtraction form. -/
theorem arm64_stack_arena_window_fits_refines (index width capacity : BitVec 32) :
    windowFits index width capacity =
      arm64StackArenaWindowFitsSpec index width capacity := by
  simp only [windowFits, arm64StackArenaWindowFitsSpec, windowEnd,
    decide_eq_decide]
  omega

/-- The fit test is the byte-arena bound: when it holds and the width is
nonzero, the last byte the window touches, `index + width - 1`, is inside the
arena, `index + width - 1 < capacity`. -/
theorem arm64_stack_arena_window_last_byte_inside (index width capacity : BitVec 32)
    (hwidth : 0 < width) (hfit : windowFits index width capacity = true) :
    index.toNat + width.toNat - 1 < capacity.toNat := by
  simp only [windowFits, windowEnd, decide_eq_true_eq] at hfit
  have hw : 0 < width.toNat := hwidth
  simp only [BitVec.toNat_eq] at hw
  omega

/-- A window that starts inside the arena but runs past it is exactly what the
guard rejects: an 8-byte access at the arena's final byte does not fit an arena
of at least eight bytes. -/
theorem arm64_stack_arena_window_at_last_byte_does_not_fit (capacity : BitVec 32)
    (hcap : 8 ≤ capacity) :
    windowFits (capacity - 1) 8 capacity = false := by
  simp only [windowFits, windowEnd, decide_eq_false_iff_not]
  have hcapN : 8 ≤ capacity.toNat := hcap
  have hnz : capacity.toNat ≠ 0 := by omega
  have h1 : BitVec.toNat (1 : BitVec 32) = 1 := rfl
  have h2 : (2 : Nat) ^ 32 % 2 ^ 32 = 0 := Nat.mod_self _
  have hcaplt : capacity.toNat < 2 ^ 32 := by
    have : 8 ≤ capacity.toNat := hcap
    omega
  have hsub : (capacity - 1).toNat = capacity.toNat - 1 := by
    have h1 : BitVec.toNat (1 : BitVec 32) = 1 := rfl
    rw [BitVec.toNat_sub, h1]
    have hlt : capacity.toNat - 1 < 2 ^ 32 := by omega
    generalize hX : capacity.toNat - 1 = X at hlt
    have hexp : 2 ^ 32 - 1 + capacity.toNat = X + 2 ^ 32 := by omega
    rw [hexp, Nat.add_mod_right, Nat.mod_eq_of_lt hlt]
  have h8 : BitVec.toNat (8 : BitVec 32) = 8 := rfl
  rw [hsub, h8]
  omega

/-- The subtraction restatement is equivalent to the sum form, so the two ways
of stating the bound cannot drift. -/
theorem arm64_stack_arena_window_end_spec_eq_sum (index width : BitVec 32)
    (hnoWrap : index.toNat + width.toNat ≤ 2 ^ 32) :
    arm64StackArenaWindowEndSpec index width = index.toNat + width.toNat := by
  simp only [arm64StackArenaWindowEndSpec]
  omega

/-- The threshold this gap was reported at, machine-checked: on the enabled
160-byte arena an 8-byte access at index 152 fits and one at 153 does not,
i.e. frame offset 56 (`152 - 96`) fits and 57 does not. -/
theorem arm64_stack_arena_window_threshold :
    windowFits 152 8 160 = true ∧ windowFits 153 8 160 = false := by
  refine ⟨?_, ?_⟩ <;> (simp only [windowFits, windowEnd]; native_decide)

/-- Independent statement of tag-slot addressability: the slot is below the
count, stated through the byte index instead of the slot, `index < slots * 8`
with the slot count a whole number of words. -/
def arm64StackArenaTagSlotFitsSpec (index slots : BitVec 32) : Bool :=
  decide (index.toNat < slots.toNat * 8)

/-- The shift form and the multiply form of the same bound agree, so the
generated `WORD_INDEX < TAG_SLOTS` and the independent `index < slots * 8` are
one statement. -/
theorem arm64_stack_arena_tag_shift_lt_mul (a b : Nat) :
    (a >>> 3 < b) = (a < b * 8) := by
  rw [Nat.shiftRight_eq_div_pow]
  have h : (2 : Nat) ^ 3 = 8 := rfl
  rw [h]
  by_cases hb : b = 0
  · subst hb
    simp
  · rw [Nat.div_lt_iff_lt_mul (by omega : 0 < (2 : Nat) ^ 3)]

/-- The generated tag-slot test agrees with the independent statement. -/
theorem arm64_stack_arena_tag_slot_fits_refines (index slots : BitVec 32) :
    tagSlotFits index slots = arm64StackArenaTagSlotFitsSpec index slots := by
  simp only [tagSlotFits, arm64StackArenaTagSlotFitsSpec, wordIndex,
    BitVec.lt_def, BitVec.toNat_ushiftRight]
  have h := arm64_stack_arena_tag_shift_lt_mul index.toNat slots.toNat
  simp only [h]

/-- The round-up's floor identity: rounding a capacity up to a whole number of
words and stepping back one lands on the last word that is fully inside it,
`(capacity - 1) / 8`. -/
theorem arm64_stack_arena_round_up_floor (q r : Nat) (hr : r < 8)
    (h : 0 < q * 8 + r) :
    (q * 8 + r + 7) / 8 - 1 = (q * 8 + r - 1) / 8 := by
  rcases Nat.eq_zero_or_pos q with hq0 | hq0
  · subst hq0
    simp only [Nat.zero_mul, Nat.zero_add] at h ⊢
    omega
  · rcases Nat.eq_zero_or_pos r with hr0 | hr0
    · subst hr0
      simp only [Nat.add_zero]
      have h1 : (q * 8 + 7) / 8 = q := by omega
      have h2 : (q * 8 - 1) / 8 = q - 1 := by omega
      rw [h1, h2]
    · have e1 : (q * 8 + r + 7) / 8 = q + 1 := by omega
      have e2 : (q * 8 + r - 1) / 8 = q := by omega
      rw [e1, e2]
      omega

/-- The tag array is exactly as large as the word view, so a tag access and a
64-bit word access admit the same slots: the largest addressable tag slot,
`words - 1`, is the word holding the arena's final byte, `(capacity - 1) >>> 3`.
Proved by reducing both sides to `Nat` and applying the round-up floor
identity. -/
theorem arm64_stack_arena_last_tag_slot_is_last_word (capacity : BitVec 32)
    (hcap : 0 < capacity.toNat) (hnoWrap : capacity.toNat + 7 < 2 ^ 32) :
    words capacity - 1 = (capacity - 1) >>> 3 := by
  have h1v : (1 : BitVec 32).toNat = 1 := by decide
  have h7 : (7 : BitVec 32).toNat = 7 := by decide
  have h8v : (8 : BitVec 32).toNat = 8 := by decide
  have ncap : (capacity - 1).toNat = capacity.toNat - 1 := by
    rw [BitVec.toNat_sub, h1v]
    rw [show (2 ^ 32 - 1 + capacity.toNat) % 2 ^ 32 = capacity.toNat - 1 by
          rw [show 2 ^ 32 - 1 + capacity.toNat = (capacity.toNat - 1) + 2 ^ 32 by omega]
          rw [Nat.add_mod_right, Nat.mod_eq_of_lt (by omega)]]
  have e1 : (capacity + 7).toNat = capacity.toNat + 7 := by
    rw [BitVec.toNat_add, h7, Nat.mod_eq_of_lt (by omega)]
  have e2 : ((capacity + 7) / 8).toNat = (capacity.toNat + 7) / 8 := by
    rw [BitVec.toNat_udiv, e1, h8v]
  have e3 : ((capacity - 1) >>> 3).toNat = (capacity.toNat - 1) / 8 := by
    rw [BitVec.toNat_ushiftRight, ncap, Nat.shiftRight_eq_div_pow]
  have hlt8 : capacity.toNat % 8 < 8 := Nat.mod_lt _ (by decide)
  have hd : capacity.toNat = (capacity.toNat / 8) * 8 + capacity.toNat % 8 := by
    have := Nat.div_add_mod capacity.toNat 8
    omega
  have hnat : (capacity.toNat + 7) / 8 - 1 = (capacity.toNat - 1) / 8 := by
    rw [hd]
    exact arm64_stack_arena_round_up_floor (capacity.toNat / 8)
      (capacity.toNat % 8) hlt8 (by omega)
  simp only [words]
  apply BitVec.eq_of_toNat_eq
  rw [BitVec.toNat_sub, e2, e3]
  show (2 ^ 32 - 1 + (capacity.toNat + 7) / 8) % 2 ^ 32 = (capacity.toNat - 1) / 8
  omega

/-- The tag guard and the window guard at a one-byte width agree on an arena
whose capacity is a whole number of words (both the enabled 160-byte and the
disabled 1-byte arena are). This ties the tag array's bound to the proved
window bound instead of leaving a second, independent inequality in the
simulator: a slot is addressable exactly when one byte at that index fits. -/
theorem arm64_stack_arena_tag_guard_is_window_guard (index capacity : BitVec 32)
    (hm : capacity.toNat % 8 = 0) :
    tagSlotFits index (words capacity) = windowFits index 1 capacity := by
  simp only [tagSlotFits, windowFits, windowEnd, wordIndex, words,
    decide_eq_decide, BitVec.lt_def, BitVec.toNat_ushiftRight,
    BitVec.toNat_udiv, BitVec.toNat_add]
  have h7 : (7 : BitVec 32).toNat = 7 := by decide
  have h8 : (8 : BitVec 32).toNat = 8 := by decide
  have h1 : (1 : BitVec 32).toNat = 1 := by decide
  rw [h7, h8, h1]
  have hsum : (capacity.toNat + 7) % 2 ^ 32 = capacity.toNat + 7 := by omega
  rw [hsum]
  have hq : (capacity.toNat + 7) / 8 = capacity.toNat / 8 := by omega
  rw [hq]
  have := Nat.div_add_mod capacity.toNat 8
  omega

/-- The tag-array boundary this closes: on the enabled 160-byte arena the tag
array has 20 slots, so byte index 159 (slot 19) is addressable and index 160
(slot 20) is not -- the access that read past `__a64_stack_tag`. -/
theorem arm64_stack_arena_tag_slot_threshold :
    tagSlotFits 159 20 = true ∧ tagSlotFits 160 20 = false := by
  refine ⟨?_, ?_⟩ <;> (simp only [tagSlotFits, wordIndex]; native_decide)

end KProgFormal
