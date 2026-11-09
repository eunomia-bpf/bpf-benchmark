import KProgFormal.NativeLinkProducer

/-!
Operational byte-copy/patch and final-layout laws for every finite program.
Relative images expose successful C memcpy, the ordered literal-record loop,
and native_size/ilen/proglen arithmetic. Canonical Memory fetch uses an explicit
allocator/address-embedding premise. Rust/iced and C/compiler extraction and
physical executable/object lifetime remain source and platform interfaces.
The literal functions describe kinds 5, 6, 7 and metadata kind 8; other native
link transformations retain their own operation and source correspondence.

Remaining implementation goals, universally quantified over successful source
link/upload/JIT runs:
* Producer: connect actual iced instruction offsets and complete encoded bytes
  after ELF/table/code-address/return-branch edits to selectedField and source.
* Kernel: connect the C ABI fields at offsets 0/4/8 in each 16-byte record,
  vmemdup_user bytes/records and native_size/blob->len/snapshot_len to storeChunk;
  connect successful memcpy, sizing/emission integer conversions and final JIT
  placement to copy, emission_size, cursor_exact and place.
* Finalization: derive every later write's ordinary-region owner and full span
  for final_fixup_frame, plus final executable Memory Embeds and its lifetime.
* MAP_POINTER_KIND5: derive first matching retained-map ID and zero-offset
  pointer target from the same copied record; compose native/B consumer/ABI.
* MAP_VALUE_KIND6: derive the retained direct-value callback base and addition
  of its packed offset exactly once, plus value provenance/lifetime and ABI.
* HELPER_POINTER_KIND7: derive the full-width helper target from the same
  source binding and compose the pointer consumers and native/B helper ABI.
* READONLY_DATA_KIND8: derive native object bytes at the packed global data
  offset, service read-only-map/C-object identity and frozen physical image,
  permissions/lifetime and helper/platform effect correspondence.
* CHUNK_AND_CODE_LAYOUT: derive actual JIT pass placement/fixup ownership and
  compose the remaining relocation consumers and architecture-specific forms.

These goals identify source/compiler and platform correspondence; the proved
wire/copy/patch/layout laws apply uniformly to arbitrary programs and records.
-/
namespace KProgFormal.NativeLinkProducerImage
open Reference NativeLinkProducer

abbrev Image := Nat → Byte
abbrev Resolution := BitVec 32 → Word → Word

def fromList (bytes : List Byte) : Image := fun i => bytes[i]?.getD 0

def window (source : Image) (start : Nat) : Image := fun i => source (start + i)

/-- Value semantics of a successful finite memcpy into a distinct allocation. -/
def copy (destination : Image) (destinationAt : Nat) (source : Image) (start count : Nat) : Image :=
  fun i => if destinationAt ≤ i ∧ i < destinationAt + count then
    source (start + (i-destinationAt)) else destination i

theorem copy_byte (destination source : Image) (destinationAt start count i : Nat) (inside : i < count) :
    copy destination destinationAt source start count (destinationAt+i) = source (start+i) := by
  simp only [copy, if_pos (show destinationAt ≤ destinationAt+i ∧
    destinationAt+i < destinationAt+count by omega)]
  congr 1
  omega

theorem copy_frame (destination source : Image) (destinationAt start count i : Nat)
    (outside : i < destinationAt ∨ destinationAt+count ≤ i) :
    copy destination destinationAt source start count i = destination i := by
  simp only [copy, if_neg (by omega : ¬(destinationAt ≤ i ∧ i < destinationAt+count))]

/-- A literal resolves from its full kind/target fields. Metadata kind 8
retains the image exactly, including its placement-anchor byte. -/
def applyRecord (resolve : Resolution) (image : Image) (record : Record) : Image :=
  if record.kind = 8 then image else
    copy image record.offset.toNat (fromList (le64 (resolve record.kind record.target))) 0 8

def applyRecords (resolve : Resolution) : Image → List Record → Image
  | image, [] => image
  | image, record::rest => applyRecords resolve (applyRecord resolve image record) rest

theorem readonly_record_identity (resolve : Resolution) (image : Image)
    (record : Record) (kind : record.kind = 8) :
    applyRecord resolve image record = image := by simp only [applyRecord, kind, ite_true]

/-- Localization commutes with the actual ordered emitter operation. The
record's kind and full target bits retain their producer identities. -/
theorem record_window (resolve : Resolution) (image : Image) (chunk : Chunk)
    (record : Record) (selected : Selected chunk record) :
    window (applyRecord resolve image record) chunk.start =
      applyRecord resolve (window image chunk.start) (localize chunk record) := by
  funext i
  simp only [applyRecord, localize]
  split
  · rfl
  · change (if record.offset.toNat ≤ chunk.start+i ∧ chunk.start+i < record.offset.toNat+8 then _ else _) =
      (if (BitVec.ofNat 32 (record.offset.toNat-chunk.start)).toNat ≤ i ∧
        i < (BitVec.ofNat 32 (record.offset.toNat-chunk.start)).toNat+8 then _ else _)
    have exactOffset := local_offset chunk record
    change (BitVec.ofNat 32 (record.offset.toNat-chunk.start)).toNat = _ at exactOffset
    rw [exactOffset]
    have lower : chunk.start ≤ record.offset.toNat := selected.1
    have sameGuard : (record.offset.toNat ≤ chunk.start+i ∧ chunk.start+i < record.offset.toNat+8) ↔
        (record.offset.toNat-chunk.start ≤ i ∧ i < record.offset.toNat-chunk.start+8) := by omega
    simp only [sameGuard]
    split
    · congr 2
      omega
    · rfl

theorem records_window (resolve : Resolution) (image : Image) (chunk : Chunk)
    (records : List Record) (selected : ∀ record∈records, Selected chunk record) :
    window (applyRecords resolve image records) chunk.start =
      applyRecords resolve (window image chunk.start) (records.map (localize chunk)) := by
  induction records generalizing image with
  | nil => rfl
  | cons record rest ih =>
      simp only [applyRecords, List.map_cons]
      rw [ih _ (fun r member => selected r (List.mem_cons_of_mem record member)),
        record_window resolve image chunk record (selected record List.mem_cons_self)]

def Agree (first second : Image) (start count : Nat) : Prop :=
  ∀ i < count, first (start+i) = second (start+i)

theorem records_agree (resolve : Resolution) (first second : Image) (start count : Nat)
    (records : List Record) (agree : Agree first second start count) :
    Agree (applyRecords resolve first records) (applyRecords resolve second records) start count := by
  induction records generalizing first second with
  | nil => exact agree
  | cons record rest ih =>
      apply ih
      intro i inside
      simp only [applyRecord]
      split
      · exact agree i inside
      · simp only [copy]
        split
        · rfl
        · exact agree i inside

/-- Copying a chunk and processing its localized wire records yields every
byte of the globally patched source window. Record order and overlaps retain
the exact operational order of the source loop. -/
theorem kernel_chunk_image (resolve : Resolution) (source scratch : Image)
    (chunk : Chunk) (records : List Record)
    (selected : ∀ record∈records, Selected chunk record) :
    Agree
      (applyRecords resolve (copy scratch 0 source chunk.start chunk.size)
        (records.map (localize chunk)))
      (window (applyRecords resolve source records) chunk.start) 0 chunk.size := by
  rw [records_window resolve source chunk records selected]
  apply records_agree
  intro i inside
  simpa only [Nat.zero_add, window] using copy_byte scratch source 0 chunk.start chunk.size i inside

/-- The two emitter passes consume one snapshot length. The uploaded native
byte image and complete relocation records share this stored snapshot. -/
structure Snapshot where
  bytes : List Byte
  records : List Record

/-- Successful native_user/blob offset copying stores the exact chunk size;
metadata records retain their original order and their localized fields. -/
def storeChunk (bytes : List Byte) (chunk : Chunk) (records : List Record) : Snapshot :=
  ⟨(bytes.drop chunk.start).take chunk.size, records.map (localize chunk)⟩

theorem stored_chunk_size (bytes : List Byte) (chunk : Chunk) (records : List Record)
    (fits : chunk.start+chunk.size ≤ bytes.length) :
    (storeChunk bytes chunk records).bytes.length = chunk.size := by
  simp only [storeChunk, List.length_take, List.length_drop]
  omega

theorem stored_chunk_records (bytes : List Byte) (chunk : Chunk) (records : List Record) :
    readRecords ((wireTable (storeChunk bytes chunk records).records).length / 16)
      (wireTable (storeChunk bytes chunk records).records) =
      some (records.map (localize chunk)) := kernel_record_copy _

def sizePass (snapshot : Snapshot) (cursor : Nat) : Nat := cursor + snapshot.bytes.length

def emitPass (resolve : Resolution) (snapshot : Snapshot) (scratch : Image) (cursor : Nat) : Image × Nat :=
  (copy scratch cursor
    (applyRecords resolve (fromList snapshot.bytes) snapshot.records) 0 snapshot.bytes.length,
   cursor + snapshot.bytes.length)

/-- Relocation contents and resolutions affect values while the same native
byte length determines the emitted count and final cursor. -/
theorem emission_size (resolve : Resolution) (snapshot : Snapshot) (scratch : Image) (cursor : Nat) :
    (emitPass resolve snapshot scratch cursor).2 = sizePass snapshot cursor ∧
      (emitPass resolve snapshot scratch cursor).2 - cursor = snapshot.bytes.length := by
  exact ⟨rfl, by dsimp [emitPass]; omega⟩

/-- Concrete copies through scratch, instruction buffer, writable pack and
final executable pack derive the transfer relation used by final-image TV. -/
theorem copy_pipeline (source scratch instruction writable final : Image)
    (sourceAt scratchAt instructionAt cursor packSize count i : Nat)
    (inside : i < count) (fits : cursor+count ≤ packSize) :
    let a := copy scratch scratchAt source sourceAt count
    let b := copy instruction instructionAt a scratchAt count
    let c := copy writable cursor b instructionAt count
    let d := copy final 0 c 0 packSize
    d (cursor+i) = source (sourceAt+i) := by
  dsimp
  rw [show cursor+i = 0+(cursor+i) by omega, copy_byte _ _ 0 0 packSize (cursor+i) (by omega)]
  simp only [Nat.zero_add]
  rw [copy_byte _ _ cursor instructionAt count i inside,
    copy_byte _ _ instructionAt scratchAt count i inside,
    copy_byte _ _ scratchAt sourceAt count i inside]

/-- JIT regions occur in their final byte order. Their widths include the
ordinary instructions, padding and native chunks selected by the producer. -/
structure Region where
  size : Nat
  native : Bool
  deriving DecidableEq, Repr

structure Placed where
  start : Nat
  size : Nat
  native : Bool
  deriving DecidableEq, Repr

def extent (regions : List Region) : Nat := (regions.map Region.size).sum

def place : Nat → List Region → List Placed
  | _, [] => []
  | cursor, region::rest => ⟨cursor,region.size,region.native⟩ :: place (cursor+region.size) rest

def Separated (a b : Placed) : Prop := a.start+a.size ≤ b.start ∨ b.start+b.size ≤ a.start

theorem placement_bounds (cursor : Nat) (regions : List Region) :
    ∀ entry∈place cursor regions,
      cursor ≤ entry.start ∧ entry.start+entry.size ≤ cursor+extent regions := by
  induction regions generalizing cursor with
  | nil => intro entry member; simp [place] at member
  | cons region rest ih =>
      intro entry member
      rcases List.mem_cons.mp member with head | tail
      · subst entry
        simp only [extent, List.map_cons, List.sum_cons]
        exact ⟨Nat.le_refl _, by omega⟩
      · have bounds := ih (cursor+region.size) entry tail
        simp only [extent] at bounds
        simp only [extent, List.map_cons, List.sum_cons]
        exact ⟨by omega, by omega⟩

theorem placement_separated (cursor : Nat) (regions : List Region) :
    (place cursor regions).Pairwise Separated := by
  induction regions generalizing cursor with
  | nil => exact List.Pairwise.nil
  | cons region rest ih =>
      apply List.pairwise_cons.mpr
      refine ⟨?_, ih (cursor+region.size)⟩
      intro entry member
      exact Or.inl (placement_bounds (cursor+region.size) rest entry member).1

theorem placement_member_separated (cursor : Nat) (regions : List Region)
    (a b : Placed) (aMember : a∈place cursor regions) (bMember : b∈place cursor regions)
    (kinds : a.native = true ∧ b.native = false) : Separated a b := by
  have apart := placement_separated cursor regions
  have general : ∀ (entries : List Placed), entries.Pairwise Separated →
      ∀ a∈entries, ∀ b∈entries, a=b ∨ Separated a b := by
    intro entries checked
    induction entries with
    | nil => intro a member; simp at member
    | cons head rest ih =>
        obtain ⟨first,tail⟩ := List.pairwise_cons.mp checked
        intro a aMember b bMember
        rcases List.mem_cons.mp aMember with aHead | aRest
        · subst a
          rcases List.mem_cons.mp bMember with bHead | bRest
          · exact Or.inl bHead.symm
          · exact Or.inr (first b bRest)
        · rcases List.mem_cons.mp bMember with bHead | bRest
          · subst b
            have pair := first a aRest
            exact Or.inr (by rcases pair with left | right; exact Or.inr left; exact Or.inl right)
          · exact ih tail a aRest b bRest
  rcases general _ apart a aMember b bMember with same | separated
  · have := kinds.1
    rw [same, kinds.2] at this
    contradiction
  · exact separated

structure Fixup where
  start : Nat
  bytes : List Byte

def fixupFits (owner : Placed) (write : Fixup) : Prop :=
  owner.start ≤ write.start ∧ write.start+write.bytes.length ≤ owner.start+owner.size

def applyFixups : Image → List Fixup → Image
  | image, [] => image
  | image, write::rest =>
      applyFixups (copy image write.start (fromList write.bytes) 0 write.bytes.length) rest

/-- The source-specific fact is each final fixup's ordinary-region ownership.
Ordered layout then derives separation from every native byte. -/
theorem final_fixup_frame (image : Image) (regions : List Region) (native : Placed)
    (nativeMember : native∈place 0 regions) (nativeKind : native.native=true)
    (writes : List Fixup)
    (owners : ∀ write∈writes, ∃ owner∈place 0 regions,
      owner.native=false ∧ fixupFits owner write) :
    Agree (applyFixups image writes) image native.start native.size := by
  induction writes generalizing image with
  | nil => intro i inside; rfl
  | cons write rest ih =>
      intro i inside
      have later := ih (copy image write.start (fromList write.bytes) 0 write.bytes.length)
        (fun w member => owners w (List.mem_cons_of_mem write member)) i inside
      change applyFixups (copy image write.start (fromList write.bytes) 0 write.bytes.length) rest
        (native.start+i) = _
      rw [later]
      obtain ⟨owner,member,kind,bounds⟩ := owners write List.mem_cons_self
      have separated := placement_member_separated 0 regions native owner nativeMember member ⟨nativeKind,kind⟩
      apply copy_frame
      unfold fixupFits at bounds
      rcases separated with before | after
      · exact Or.inl (by omega)
      · exact Or.inr (by omega)

/-- Whole-pack copying followed by all ordinary-region fixups preserves a
native chunk's complete image. All cursor/size bounds come from layout. -/
theorem finalized_native_image (writable final : Image) (regions : List Region)
    (native : Placed) (member : native∈place 0 regions) (kind : native.native=true)
    (writes : List Fixup)
    (owners : ∀ write∈writes, ∃ owner∈place 0 regions,
      owner.native=false ∧ fixupFits owner write) :
    Agree (applyFixups (copy final 0 writable 0 (extent regions)) writes)
      writable native.start native.size := by
  intro i inside
  rw [final_fixup_frame _ regions native member kind writes owners i inside]
  have bound := (placement_bounds 0 regions native member).2
  simpa only [Nat.zero_add] using
    copy_byte final writable 0 0 (extent regions) (native.start+i) (by omega)

/-- Canonical memory contains the same byte image at the final executable
base. Allocator permissions and live executable storage remain platform facts. -/
def Embeds (memory : Memory) (base : Word) (image : Image) (size : Nat) : Prop :=
  ∀ i<size, memory.value (base+BitVec.ofNat 64 i) = image i

theorem canonical_fetch (memory : Memory) (base : Word) (image : Image)
    (size start count : Nat) (embedded : Embeds memory base image size)
    (fits : start+count ≤ size) :
    bytesAt memory (base+BitVec.ofNat 64 start) count =
      (List.range count).map (fun i => image (start+i)) := by
  apply List.map_congr_left
  intro i member
  have bounded := List.mem_range.mp member
  have same := embedded (start+i) (by omega)
  simpa only [BitVec.ofNat_add, BitVec.add_assoc] using same

/-- One generic composition from localized producer records, successful
chunk copying and ordered patching through the final pack and layout-owned
fixups, to canonical executable bytes. Source extraction supplies the declared
chunk/layout/record correspondence; byte-copy correctness is derived here. -/
theorem producer_to_final_bytes (resolve : Resolution) (source scratch writable final : Image)
    (chunk : Chunk) (records : List Record)
    (selected : ∀ record∈records, Selected chunk record)
    (regions : List Region) (native : Placed)
    (member : native∈place 0 regions) (kind : native.native=true)
    (size : native.size=chunk.size) (writes : List Fixup)
    (owners : ∀ write∈writes, ∃ owner∈place 0 regions,
      owner.native=false ∧ fixupFits owner write)
    (memory : Memory) (base : Word)
    (embedded : Embeds memory base
      (applyFixups (copy final 0
        (copy writable native.start
          (applyRecords resolve (copy scratch 0 source chunk.start chunk.size)
            (records.map (localize chunk))) 0 chunk.size)
        0 (extent regions)) writes) (extent regions)) :
    ∀ i<chunk.size,
      memory.value (base+BitVec.ofNat 64 (native.start+i)) =
        applyRecords resolve source records (chunk.start+i) := by
  intro i inside
  have range := (placement_bounds 0 regions native member).2
  have copied := finalized_native_image
    (copy writable native.start
      (applyRecords resolve (copy scratch 0 source chunk.start chunk.size)
        (records.map (localize chunk))) 0 chunk.size)
    final regions native member kind writes owners i (by omega)
  rw [embedded (native.start+i) (by omega), copied,
    copy_byte _ _ native.start 0 chunk.size i inside]
  simpa only [Agree, window, Nat.zero_add] using
    kernel_chunk_image resolve source scratch chunk records selected i inside

end KProgFormal.NativeLinkProducerImage
