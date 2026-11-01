import KProgFormal.GeneratedX86StackArena

namespace KProgFormal

open GeneratedX86StackArena (wordIndex wordAligned byteAt assembleByte words windowEnd windowFits
  pointerFits)

/-- Independent statement of the word-arena slot: a byte index divided by 8,
i.e. the integer quotient rounded down, the C `INDEX >> 3`. Stated with
`BitVec` division (not `Nat` division on `.toNat`), which `bv_decide` handles
natively. -/
def x86StackArenaWordIndexSpec (index : BitVec 32) : BitVec 32 := index / 8

/-- Independent statement of the word-arena slot count: the capacity rounded
up to a multiple of 8. -/
def x86StackArenaWordsSpec (capacity : BitVec 32) : BitVec 32 :=
  capacity >>> 3 + (if capacity &&& 7 == 0 then 0 else 1)

/-- Independent statement of the fast-path alignment guard: the index is a
whole number of 8-byte words, the C `(INDEX & 7U) == 0U`. -/
def x86StackArenaWordAlignedSpec (index : BitVec 32) : Prop := index % 8 = 0

/-- Independent statement of the byte-arena bytes a slot's word is split into:
the 64-bit word is the little-endian concatenation of its eight bytes. -/
def x86StackArenaSplitSpec (b0 b1 b2 b3 b4 b5 b6 b7 : BitVec 8) : BitVec 64 :=
  b0.setWidth 64 ||| (b1.setWidth 64 <<< 8) ||| (b2.setWidth 64 <<< 16) |||
  (b3.setWidth 64 <<< 24) ||| (b4.setWidth 64 <<< 32) ||| (b5.setWidth 64 <<< 40) |||
  (b6.setWidth 64 <<< 48) ||| (b7.setWidth 64 <<< 56)

/-- Independent statement of the byte-arena read path: byte 0 contributes
directly, bytes 1..7 are assembled by `assembleByte` at their little-endian
shift, i.e. the C `b[i] | (WORD << 8) | ...`. -/
def x86StackArenaReadSpec (b0 b1 b2 b3 b4 b5 b6 b7 : BitVec 8) : BitVec 64 :=
  b0.setWidth 64 ||| assembleByte b1 1 ||| assembleByte b2 2 |||
  assembleByte b3 3 ||| assembleByte b4 4 ||| assembleByte b5 5 |||
  assembleByte b6 6 ||| assembleByte b7 7

/-- The read path is the split path: the bytes the byte-arena read macro
assembles are exactly the bytes the split places, so the two spellings of the
little-endian reconstruction agree. -/
theorem x86_stack_arena_read_eq_split (b0 b1 b2 b3 b4 b5 b6 b7 : BitVec 8) :
    x86StackArenaReadSpec b0 b1 b2 b3 b4 b5 b6 b7 =
      x86StackArenaSplitSpec b0 b1 b2 b3 b4 b5 b6 b7 := by
  unfold x86StackArenaReadSpec x86StackArenaSplitSpec assembleByte
  bv_decide

/-- The generated word-slot shift equals the independent quotient for every
byte index. -/
theorem x86_stack_arena_word_index_refines (index : BitVec 32) :
    wordIndex index = x86StackArenaWordIndexSpec index := by
  unfold wordIndex x86StackArenaWordIndexSpec
  bv_decide

/-- The generated word count equals the independent round-up statement for
every capacity whose `+ 7` does not wrap (all capacities below `2^32 - 7`). -/
theorem x86_stack_arena_words_refines (capacity : BitVec 32)
    (h : BitVec.ule capacity (capacity + 7)) :
    words capacity = x86StackArenaWordsSpec capacity := by
  unfold words x86StackArenaWordsSpec
  bv_decide

/-- The generated alignment guard agrees with the independent modulus
statement: the low three bits are clear exactly when the index is a multiple
of 8. -/
theorem x86_stack_arena_word_aligned_refines (index : BitVec 32) :
    wordAligned index = true ↔ x86StackArenaWordAlignedSpec index := by
  unfold wordAligned x86StackArenaWordAlignedSpec
  bv_decide

/-- The AArch64 and x86 statements of the same capacity restriction are
worded differently -- a numeric bound `capacity <= 2^32 - 8` there, the no-wrap
predicate `capacity <= capacity + 7` here -- and they are the same restriction,
so a reader comparing the two files is not looking at a divergence. It is also
exactly tight: the equality holds at `2^32 - 8` and fails from `2^32 - 7`
upward, because the rounding wraps. -/
theorem x86_stack_arena_words_bound_is_tight :
    x86StackArenaWordsSpec (BitVec.ofNat 32 (2 ^ 32 - 8)) =
        words (BitVec.ofNat 32 (2 ^ 32 - 8)) ∧
      x86StackArenaWordsSpec (BitVec.ofNat 32 (2 ^ 32 - 7)) ≠
        words (BitVec.ofNat 32 (2 ^ 32 - 7)) ∧
      ¬ BitVec.ule (BitVec.ofNat 32 (2 ^ 32 - 7))
          (BitVec.ofNat 32 (2 ^ 32 - 7) + 7) := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- Word slots cover the whole byte arena: the capacity never exceeds the
byte count of the rounded-up word array. -/
theorem x86_stack_arena_words_cover_capacity (capacity : BitVec 32)
    (h : BitVec.ule capacity (capacity + 7)) :
    BitVec.ule capacity (words capacity * 8) := by
  unfold words
  bv_decide

/-- No whole word slot is wasted: for any non-empty arena the last slot always
holds at least one live byte, so the round-up never adds a full unused slot. -/
theorem x86_stack_arena_words_tight (capacity : BitVec 32)
    (h1 : BitVec.ule 1 capacity) (h : BitVec.ule capacity (capacity + 7)) :
    BitVec.ule ((words capacity - 1) * 8) (capacity - 1) := by
  unfold words
  bv_decide

/-- Alignment roundtrip: an 8-aligned byte index is exactly its word slot
shifted back, so the 64-bit fast path touches the byte-arena window
`[index, index + 8)` and skips nothing. -/
theorem x86_stack_arena_alignment_roundtrip (index : BitVec 32)
    (ha : wordAligned index = true) :
    (wordIndex index) <<< 3 = index := by
  unfold wordIndex wordAligned at *
  bv_decide

/-- Every 8-aligned byte index maps into the word arena: the slot is a valid
index below the array's slot count. -/
theorem x86_stack_arena_word_slot_in_range (capacity index : BitVec 32)
    (hc : index ≤ capacity) (hno : BitVec.ule capacity 4294967288) :
    wordIndex index ≤ words capacity := by
  unfold wordIndex words
  bv_decide

/-- Union aliasing: the little-endian split of a slot-`j` word reassembles to
the word itself, so the word arena and the byte arena address the same
storage — a fast-path 64-bit read of slot `j` yields exactly the bytes the
byte path would have placed at `b[8j .. 8j+7)`. -/
theorem x86_stack_arena_word_byte_split (word : BitVec 64) :
    x86StackArenaSplitSpec (byteAt word 0) (byteAt word 1) (byteAt word 2)
      (byteAt word 3) (byteAt word 4) (byteAt word 5) (byteAt word 6)
      (byteAt word 7) = word := by
  unfold x86StackArenaSplitSpec byteAt
  bv_decide

/-- The byte path reading `b[8j + k]` and the word path reading slot `j` are
the same bytes: byte `k` of the fast-path word equals the corresponding
split byte. -/
theorem x86_stack_arena_word_byte_agrees (word : BitVec 64) (k : Nat) :
    byteAt word k =
      byteAt (x86StackArenaSplitSpec (byteAt word 0) (byteAt word 1)
        (byteAt word 2) (byteAt word 3) (byteAt word 4) (byteAt word 5)
        (byteAt word 6) (byteAt word 7)) k := by
  rw [x86_stack_arena_word_byte_split]

/-- Concrete slots: capacity 128 needs 16 word slots, capacity 64 needs 8,
capacity 1 needs 1; the frame base (byte index 0) is the first word, and the
aligned byte index 56 is word slot 7. -/
theorem x86_stack_arena_example :
    words 128 = 16 ∧ words 64 = 8 ∧ words 1 = 1 ∧
      wordIndex 0 = 0 ∧ wordIndex 56 = 7 ∧
      wordAligned 56 = true ∧ wordAligned 60 = false := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

/-- Independent statement of the access window's end: the first index past a
`width`-byte access, stated as a subtraction from the 64-bit top rather than a
sum. -/
def x86StackArenaWindowEndSpec (index width : BitVec 32) : Nat :=
  2 ^ 32 - (2 ^ 32 - index.toNat - width.toNat)

/-- Independent statement of the fit test: the window start is inside the arena
and the bytes remaining from it cover the width. Both conjuncts are needed
because `Nat` subtraction truncates, so the remainder alone would accept an
index past the arena. -/
def x86StackArenaWindowFitsSpec (index width capacity : BitVec 32) : Bool :=
  decide (index.toNat ≤ capacity.toNat ∧ width.toNat ≤ capacity.toNat - index.toNat)

/-- The generated window end equals the independent restatement on every window
whose end stays inside the index space. -/
theorem x86_stack_arena_window_end_refines (index width : BitVec 32)
    (hnoWrap : index.toNat + width.toNat ≤ 2 ^ 32) :
    windowEnd index width = x86StackArenaWindowEndSpec index width := by
  simp only [windowEnd, x86StackArenaWindowEndSpec]
  omega

/-- The generated fit test agrees with the independent subtraction form. -/
theorem x86_stack_arena_window_fits_refines (index width capacity : BitVec 32) :
    windowFits index width capacity =
      x86StackArenaWindowFitsSpec index width capacity := by
  simp only [windowFits, x86StackArenaWindowFitsSpec, windowEnd,
    decide_eq_decide]
  omega

/-- The fit test is the byte-arena bound: when it holds and the width is
nonzero, the last byte the window touches, `index + width - 1`, is inside the
arena, `index + width - 1 < capacity`. -/
theorem x86_stack_arena_window_last_byte_inside (index width capacity : BitVec 32)
    (hwidth : 0 < width) (hfit : windowFits index width capacity = true) :
    index.toNat + width.toNat - 1 < capacity.toNat := by
  simp only [windowFits, windowEnd, decide_eq_true_eq] at hfit
  have hw : 0 < width.toNat := hwidth
  simp only [BitVec.toNat_eq] at hw
  omega

/-- A window that starts inside the arena but runs past it is exactly what the
guard rejects: an 8-byte access at the arena's final byte does not fit. No
capacity restriction is needed, for the same reason as on AArch64: the case the
earlier `8 <= capacity` hypothesis excluded, a zero arena where `capacity - 1`
wraps, also fails. -/
theorem x86_stack_arena_window_at_last_byte_does_not_fit (capacity : BitVec 32) :
    windowFits (capacity - 1) 8 capacity = false := by
  simp only [windowFits, windowEnd, decide_eq_false_iff_not]
  have h8 : BitVec.toNat (8 : BitVec 32) = 8 := rfl
  rw [h8]
  by_cases hz : capacity = 0
  · subst hz
    decide
  · have hpos : 0 < capacity.toNat := by
      rcases Nat.eq_zero_or_pos capacity.toNat with h0 | hp
      · exact absurd (BitVec.eq_of_toNat_eq (by rw [h0]; rfl)) hz
      · exact hp
    have hsub : (capacity - 1).toNat = capacity.toNat - 1 := by
      have h1 : BitVec.toNat (1 : BitVec 32) = 1 := rfl
      rw [BitVec.toNat_sub, h1]
      have hlt : capacity.toNat - 1 < 2 ^ 32 := by
        have : capacity.toNat < 2 ^ 32 := capacity.isLt
        omega
      generalize hX : capacity.toNat - 1 = X at hlt
      have hexp : 2 ^ 32 - 1 + capacity.toNat = X + 2 ^ 32 := by omega
      rw [hexp, Nat.add_mod_right, Nat.mod_eq_of_lt hlt]
    rw [hsub]
    omega

/-- Independent statement of the pointer bound: `&b[index]` names an arena
address when the index is at most the capacity. -/
def x86StackArenaPointerFitsSpec (index capacity : BitVec 32) : Bool :=
  decide (index.toNat ≤ capacity.toNat)

/-- The generated pointer bound agrees with the independent statement. -/
theorem x86_stack_arena_pointer_fits_refines (index capacity : BitVec 32) :
    pointerFits index capacity = x86StackArenaPointerFitsSpec index capacity :=
  rfl

/-- The pointer bound is the one-past-end rule: the final arena index is
addressable and the next one is not, for a capacity whose successor does not
wrap. -/
theorem x86_stack_arena_pointer_one_past_end (capacity : BitVec 32)
    (hnoWrap : capacity.toNat + 1 < 2 ^ 32) :
    pointerFits capacity capacity = true ∧
      pointerFits (capacity + 1) capacity = false := by
  constructor
  · simp only [pointerFits]
    exact decide_eq_true (by simp)
  · simp only [pointerFits]
    have h1 : (1 : BitVec 32).toNat = 1 := by decide
    rw [BitVec.toNat_add, h1, Nat.mod_eq_of_lt hnoWrap]
    simp only [decide_eq_false_iff_not]
    omega

/-- The pointer bound is weaker than the window bound: a window that fits
names a valid arena pointer, for any width -- no nonempty-width condition is
needed, since `index + width <= capacity` already gives `index <= capacity`. -/
theorem x86_stack_arena_pointer_weaker_than_window (index capacity width : BitVec 32)
    (hfit : windowFits index width capacity = true) :
    pointerFits index capacity = true := by
  simp only [windowFits, windowEnd, decide_eq_true_eq] at hfit
  simp only [pointerFits, decide_eq_true_eq]
  omega

/-- The weakness is strict, which is why the stack-pointer helper needs its
own check: the one-past-end index is a valid pointer but not the start of any
nonempty window, so a pointer that passes the pointer bound can still be
dereferenced out of the arena. -/
theorem x86_stack_arena_pointer_weaker_than_window_strict (capacity : BitVec 32)
    (hnoWrap : capacity.toNat + 1 < 2 ^ 32) :
    pointerFits capacity capacity = true ∧
      windowFits capacity 1 capacity = false := by
  constructor
  · simp only [pointerFits]
    exact decide_eq_true (by simp)
  · simp only [windowFits, windowEnd]
    have hv : (1 : BitVec 32).toNat = 1 := by decide
    have hcapLt : capacity.toNat < 2 ^ 32 := by omega
    show decide (capacity.toNat + 1 ≤ capacity.toNat) = false
    rw [decide_eq_false_iff_not]
    omega

/-- Concrete witness of the strictness on the default frame: index 64 is a
valid pointer and not the start of a one-byte window, so a stack-pointer
register can be dereferenced one byte past the frame. -/
theorem x86_stack_arena_pointer_strict_at_default_frame :
    pointerFits 64 64 = true ∧ windowFits 64 1 64 = false := by
  refine ⟨?_, ?_⟩ <;> (simp only [pointerFits, windowFits, windowEnd]; native_decide)

/-- The threshold on both arena sizes the simulator uses, machine-checked: the
default 64-byte frame fits an 8-byte access at index 56 and not at 57, and the
128-byte deep frame fits one at 120 and not at 121. -/
theorem x86_stack_arena_window_threshold :
    windowFits 56 8 64 = true ∧ windowFits 57 8 64 = false ∧
      windowFits 120 8 128 = true ∧ windowFits 121 8 128 = false := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> (simp only [windowFits, windowEnd]; native_decide)

end KProgFormal
