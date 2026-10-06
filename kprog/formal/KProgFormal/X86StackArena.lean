import KProgFormal.GeneratedX86StackArena

namespace KProgFormal

open GeneratedX86StackArena (wordIndex wordAligned byteAt assembleByte words)

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
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_⟩ <;> decide

end KProgFormal
