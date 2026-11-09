import KProgFormal.NativeLinkSourceLayout
import KProgFormal.Generated.NativeLinkFields

/-!
The actual encoded-field constructors, lowered from the Rust source, instantiate
S5's universal producer/image theorems. The encoder's returned offsets, encoded
byte layout and later producer edits retain their Rust/iced/compiler contracts;
these theorems derive field coordinates and chunk/byte composition from that
interface for every symbol, field, table, program and encoded block.
-/
namespace KProgFormal.NativeLinkSourceProducer
open Reference NativeLinkProducer NativeLinkProducerImage NativeLinkFields

theorem source_field_record (before : List Byte) (instruction kind : BitVec 32)
    (field : Nat) (target : Word) :
    fieldRecord before instruction field kind target =
      producerRecord before.length instruction field kind target := rfl

theorem source_helper_coordinate (before : List Byte) (instruction : BitVec 32) (target : Word)
    (fits : before.length+instruction.toNat+helperField < 2^32) :
    (helperRecord before instruction target).offset.toNat = before.length+instruction.toNat+2 ∧
      (helperRecord before instruction target).kind = 7 ∧
      (helperRecord before instruction target).target = target := by
  exact ⟨producer_field_position _ _ _ _ _ fits, rfl, rfl⟩

theorem source_map_coordinate (before : List Byte) (instruction kind : BitVec 32)
    (field : Nat) (target : Word) (fits : before.length+instruction.toNat+field < 2^32) :
    (mapFieldRecord before instruction field kind target).offset.toNat =
      before.length+instruction.toNat+field :=
  producer_field_position _ _ _ _ _ fits

theorem source_helper_table (table identity : Nat) (target : Word)
    (fits : table+identity*helperTableStride < 2^32) :
    (helperTableRecord table identity target).offset.toNat = table+identity*8 ∧
      (helperTableRecord table identity target).kind = 7 ∧
      (helperTableRecord table identity target).target = target := by
  refine ⟨?_, rfl, rfl⟩
  exact Nat.mod_eq_of_lt fits

/-- Rust's encoded symbol append locates every selected field byte in the
complete appended symbol, using its actual returned instruction coordinate. -/
theorem source_encoded_field_bytes (before after : List Byte) (block : EncodedBlock)
    (index field : Nat) (instruction kind : BitVec 32) (target : Word)
    (selected : block.instructionOffsets[index]? = some instruction)
    (conversion : before.length+instruction.toNat+field < 2^32)
    (fits : instruction.toNat+field+patchSize kind ≤ block.bytes.length) :
    ∀ i < patchSize kind,
      (before++block.bytes++after)[(fieldRecord before instruction field kind target).offset.toNat+i]? =
      block.bytes[instruction.toNat+field+i]? :=
  (selected_field_image before after block index field instruction kind target selected conversion fits).2

/-- Chunk serialization retains the complete source field coordinate. -/
theorem source_chunk_field (before : List Byte) (field : Nat) (instruction kind : BitVec 32)
    (target : Word) (chunk : Chunk)
    (conversion : before.length+instruction.toNat+field < 2^32)
    (selected : Selected chunk (fieldRecord before instruction field kind target)) :
    chunk.start+(localize chunk (fieldRecord before instruction field kind target)).offset.toNat =
      before.length+instruction.toNat+field :=
  producer_chunk_field _ _ _ _ _ _ conversion selected

end KProgFormal.NativeLinkSourceProducer
