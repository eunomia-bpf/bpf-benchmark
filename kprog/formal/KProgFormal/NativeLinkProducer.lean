import KProgFormal.Reference.Memory

/-!
Generic producer/wire/cursor laws for the relocation link steps.

Source interfaces:
* native_link/src/main.rs: RelocRecord and its offset/kind/target LE serializer;
* native_link/src/x86.rs: sym_base + new_instruction_offsets[i] + field offset;
* libnativeloader/src/native_loader.cpp: chunk_reloc_bytes, upload_native_chunks;
* bpf_x86_native_lab.c: native_size -> blob->len -> snapshot_len -> *off.

These definitions model successful source operations for arbitrary programs.
Rust/iced and C/compiler extraction, allocation success and physical object
lifetime are explicit implementation obligations. Bounds below describe the
existing successful conversions. The companion image module proves the
operational copy and patch correspondence.
-/
namespace KProgFormal.NativeLinkProducer
open Reference

structure Record where
  offset : BitVec 32
  kind : BitVec 32
  target : Word
  deriving DecidableEq, Repr

def le32 (value : BitVec 32) : List Byte :=
  [value.setWidth 8, (value >>> 8).setWidth 8,
   (value >>> 16).setWidth 8, (value >>> 24).setWidth 8]

def le64 (value : Word) : List Byte :=
  [value.setWidth 8, (value >>> 8).setWidth 8,
   (value >>> 16).setWidth 8, (value >>> 24).setWidth 8,
   (value >>> 32).setWidth 8, (value >>> 40).setWidth 8,
   (value >>> 48).setWidth 8, (value >>> 56).setWidth 8]

theorem le32_roundtrip (value : BitVec 32) : littleEndian 32 (le32 value) = value := by
  simp only [le32, littleEndian]
  bv_decide

theorem le64_roundtrip (value : Word) : littleEndian 64 (le64 value) = value := by
  simp +decide [le64, littleEndian]
  unfold Word at *
  bv_decide

def wire (record : Record) : List Byte :=
  le32 record.offset ++ le32 record.kind ++ le64 record.target

def readRecord : List Byte → Option Record
  | [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p] =>
      some ⟨littleEndian 32 [a,b,c,d], littleEndian 32 [e,f,g,h],
        littleEndian 64 [i,j,k,l,m,n,o,p]⟩
  | _ => none

theorem wire_size (record : Record) : (wire record).length = 16 := by
  simp [wire, le32, le64]

/-- All three fields, including the complete kind and target, survive the
actual 4+4+8-byte record serialization. -/
theorem wire_roundtrip (record : Record) : readRecord (wire record) = some record := by
  have a := le32_roundtrip record.offset
  have b := le32_roundtrip record.kind
  have c := le64_roundtrip record.target
  cases record
  simp only [wire, le32, le64, List.cons_append, List.nil_append, readRecord]
  simp only [le32, le64] at a b c
  rw [a,b,c]

def wireTable (records : List Record) : List Byte := records.flatMap wire

theorem wire_table_size (records : List Record) :
    (wireTable records).length = records.length * 16 := by
  induction records with
  | nil => rfl
  | cons record rest ih =>
      simp only [wireTable, List.flatMap_cons, List.length_append, wire_size,
        List.length_cons] at *
      omega

theorem wire_record_count (records : List Record) :
    (wireTable records).length / 16 = records.length := by
  rw [wire_table_size]
  omega

/-- The kernel reads exactly reloc_count consecutive native C records. -/
def readRecords : Nat → List Byte → Option (List Record)
  | 0, _ => some []
  | count+1, bytes =>
      match readRecord (bytes.take 16), readRecords count (bytes.drop 16) with
      | some record, some rest => some (record::rest)
      | _, _ => none

theorem wire_table_roundtrip (records : List Record) :
    readRecords records.length (wireTable records) = some records := by
  induction records with
  | nil => rfl
  | cons record rest ih =>
      change (match readRecord ((wire record ++ wireTable rest).take 16),
        readRecords rest.length ((wire record ++ wireTable rest).drop 16) with
        | some head, some tail => some (head::tail)
        | _, _ => none) = _
      rw [List.take_left' (wire_size record), List.drop_left' (wire_size record),
        wire_roundtrip, ih]

theorem kernel_record_copy (records : List Record) :
    readRecords ((wireTable records).length / 16) (wireTable records) = some records := by
  rw [wire_record_count, wire_table_roundtrip]

/-- Stable map ID in the low half; value/data offset in the high half. -/
def packTarget (identity offset : BitVec 32) : Word :=
  identity.zeroExtend 64 ||| (offset.zeroExtend 64 <<< 32)

theorem pack_target_identity (identity offset : BitVec 32) :
    (packTarget identity offset).setWidth 32 = identity := by
  unfold packTarget
  bv_decide

theorem pack_target_offset (identity offset : BitVec 32) :
    ((packTarget identity offset >>> 32).setWidth 32) = offset := by
  apply BitVec.eq_of_getLsbD_eq
  intro i bounded
  simp +decide [packTarget, BitVec.zeroExtend, bounded]
  simp [show 32+i<64 by omega, show ¬32+i<32 by omega,
    Nat.add_sub_cancel_left, show i<64 by omega, bounded]

/-- Placement and patch lengths have distinct source roles for kind 8.
These two functions describe the four kinds owned by this module. -/
def anchorSize (kind : BitVec 32) : Nat := if kind = 8 then 1 else 8

def patchSize (kind : BitVec 32) : Nat := if kind = 8 then 0 else 8

theorem selected_kind_sizes :
    (anchorSize 5, patchSize 5) = (8,8) ∧
    (anchorSize 6, patchSize 6) = (8,8) ∧
    (anchorSize 7, patchSize 7) = (8,8) ∧
    (anchorSize 8, patchSize 8) = (1,0) := by decide

structure Chunk where
  start : Nat
  size : Nat
  deriving DecidableEq, Repr

def Selected (chunk : Chunk) (record : Record) : Prop :=
  chunk.start ≤ record.offset.toNat ∧
    record.offset.toNat + anchorSize record.kind ≤ chunk.start + chunk.size

def localize (chunk : Chunk) (record : Record) : Record :=
  { record with offset := BitVec.ofNat 32 (record.offset.toNat - chunk.start) }

/-- The successful local u32 conversion retains the exact subtraction. -/
theorem local_offset (chunk : Chunk) (record : Record) :
    (localize chunk record).offset.toNat = record.offset.toNat - chunk.start := by
  simp only [localize, BitVec.toNat_ofNat]
  have bound := record.offset.isLt
  rw [Nat.mod_eq_of_lt (by omega)]

/-- Serialized local records reconstruct the producer's complete global
record and fit the copied chunk, with kind-8's placement anchor retained. -/
theorem local_record_correspondence (chunk : Chunk) (record : Record)
    (selected : Selected chunk record) :
    chunk.start + (localize chunk record).offset.toNat = record.offset.toNat ∧
    (localize chunk record).kind = record.kind ∧
    (localize chunk record).target = record.target ∧
    (localize chunk record).offset.toNat + anchorSize record.kind ≤ chunk.size ∧
    readRecord (wire (localize chunk record)) = some (localize chunk record) := by
  rw [local_offset chunk record]
  unfold Selected at selected
  exact ⟨by omega, rfl, rfl, by omega, wire_roundtrip _⟩

/-- Kind 8's zero-offset placement anchor belongs to the initial chunk;
its target retains both the stable map ID and global native data offset. -/
theorem readonly_anchor (chunk : Chunk) (identity dataOffset : BitVec 32)
    (selected : Selected chunk ⟨0,8,packTarget identity dataOffset⟩) :
    chunk.start=0 ∧
    (localize chunk ⟨0,8,packTarget identity dataOffset⟩).offset=0 ∧
    ((localize chunk ⟨0,8,packTarget identity dataOffset⟩).target >>> 32).setWidth 32=dataOffset := by
  have start : chunk.start=0 := by
    have first := selected.1
    change chunk.start ≤ 0 at first
    omega
  refine ⟨start, ?_, pack_target_offset identity dataOffset⟩
  simp only [localize, start]
  rfl

/-- The actual iced offset is a selected producer output, independently of
its branch-width choices and surrounding instruction encoding. -/
structure EncodedBlock where
  bytes : List Byte
  instructionOffsets : List (BitVec 32)

/-- Successful u32::try_from(sym_base + off_in_sym + field_offset). -/
def producerRecord (symbolBase : Nat) (instruction : BitVec 32) (field : Nat)
    (kind : BitVec 32) (target : Word) : Record :=
  ⟨BitVec.ofNat 32 (symbolBase + instruction.toNat + field), kind, target⟩

def selectedField (symbolBase : Nat) (block : EncodedBlock) (index field : Nat)
    (kind : BitVec 32) (target : Word) : Option Record :=
  block.instructionOffsets[index]?.map (fun instruction =>
    producerRecord symbolBase instruction field kind target)

theorem producer_field_position (symbolBase field : Nat) (instruction kind : BitVec 32)
    (target : Word) (conversion : symbolBase + instruction.toNat + field < 2^32) :
    (producerRecord symbolBase instruction field kind target).offset.toNat =
      symbolBase + instruction.toNat + field := by
  simp only [producerRecord, BitVec.toNat_ofNat, Nat.mod_eq_of_lt conversion]

/-- Selected iced offsets locate each byte inside the exact appended symbol
image. Its position follows from byte lengths and successful wire conversion. -/
theorem selected_field_image (before after : List Byte) (block : EncodedBlock)
    (index field : Nat) (instruction kind : BitVec 32) (target : Word)
    (selected : block.instructionOffsets[index]? = some instruction)
    (conversion : before.length + instruction.toNat + field < 2^32)
    (fits : instruction.toNat + field + patchSize kind ≤ block.bytes.length) :
    selectedField before.length block index field kind target =
      some (producerRecord before.length instruction field kind target) ∧
    ∀ i < patchSize kind,
      (before ++ block.bytes ++ after)[
        (producerRecord before.length instruction field kind target).offset.toNat+i]? =
      block.bytes[instruction.toNat+field+i]? := by
  constructor
  · simp only [selectedField, selected, Option.map_some]
    rfl
  · intro i inside
    rw [producer_field_position _ _ _ _ _ conversion, List.append_assoc,
      List.getElem?_append_right (by omega)]
    rw [show before.length+instruction.toNat+field+i-before.length =
      instruction.toNat+field+i by omega]
    exact List.getElem?_append_left (by omega)

/-- The final global field coordinate also follows from the localized
record retained by the kernel chunk. -/
theorem producer_chunk_field (symbolBase field : Nat) (instruction kind : BitVec 32)
    (target : Word) (chunk : Chunk)
    (conversion : symbolBase + instruction.toNat + field < 2^32)
    (selected : Selected chunk (producerRecord symbolBase instruction field kind target)) :
    chunk.start + (localize chunk (producerRecord symbolBase instruction field kind target)).offset.toNat =
      symbolBase + instruction.toNat + field := by
  exact (local_record_correspondence chunk _ selected).1.trans
    (producer_field_position symbolBase field instruction kind target conversion)

/-- Mathematical cursor arithmetic records successful source u32 conversion. -/
def advance32 (cursor size : BitVec 32) : BitVec 32 := cursor + size

theorem cursor_exact (cursor size : BitVec 32) (fits : cursor.toNat + size.toNat < 2^32) :
    (advance32 cursor size).toNat = cursor.toNat + size.toNat := by
  simp only [advance32, BitVec.toNat_add, Nat.mod_eq_of_lt fits]

end KProgFormal.NativeLinkProducer
