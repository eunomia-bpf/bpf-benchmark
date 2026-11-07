import NativeLinkChunkLayout

/-! Ordered encoded pieces derive global field positions and separation.
Byte slices use canonical Memory; instruction consumption uses canonical X86. -/
namespace KProgTV.NativeLinkByteLayout
open KProgFormal.Reference NativeLinkPatchTable

structure Field where
  offset : Nat
  target : Word
  isCall : Bool

structure Piece where
  bytes : List Byte
  field : Option Field

def fieldSpan (field : Field) : Nat := if field.isCall then 5 else 8

def Fits (piece : Piece) : Prop :=
  ∀ field, piece.field=some field → field.offset+fieldSpan field≤piece.bytes.length

def byteLength (pieces : List Piece) : Nat := (pieces.map (fun piece => piece.bytes.length)).sum

def byteImage (pieces : List Piece) : List Byte := pieces.flatMap (fun piece => piece.bytes)

def fieldRecord (cursor : Nat) (field : Field) : Record :=
  ⟨BitVec.ofNat 32 (cursor+field.offset),field.target,field.isCall⟩

def pieceRecords (cursor : Nat) (piece : Piece) : List Record :=
  match piece.field with
  | none => []
  | some field => [fieldRecord cursor field]

def records : Nat → List Piece → List Record
  | _,[] => []
  | cursor,piece::rest => pieceRecords cursor piece ++ records (cursor+piece.bytes.length) rest

theorem image_length (pieces : List Piece) : (byteImage pieces).length=byteLength pieces := by
  induction pieces with
  | nil => rfl
  | cons piece rest ih => simpa only [byteImage,List.flatMap_cons,List.length_append,
      byteLength,List.map_cons,List.sum_cons] using congrArg (piece.bytes.length+·) ih

theorem length_append (first second : List Piece) :
    byteLength (first++second)=byteLength first+byteLength second := by
  induction first with
  | nil => simp only [List.nil_append,byteLength,List.map_nil,List.sum_nil,Nat.zero_add]
  | cons piece rest ih =>
      simpa only [List.cons_append,byteLength,List.map_cons,List.sum_cons,Nat.add_assoc] using congrArg (piece.bytes.length+·) ih

/-- The cursor follows the actual append lengths of encoded byte pieces. -/
theorem records_append (cursor : Nat) (first second : List Piece) :
    records cursor (first++second)=records cursor first++records (cursor+byteLength first) second := by
  induction first generalizing cursor with
  | nil => simp only [records,List.nil_append,byteLength,List.map_nil,List.sum_nil,Nat.add_zero]
  | cons piece rest ih =>
      simp only [List.cons_append,records,ih,List.append_assoc,byteLength,List.map_cons,List.sum_cons,Nat.add_assoc]

theorem field_record_position (cursor : Nat) (piece : Piece) (field : Field)
    (fits : Fits piece) (selected : piece.field=some field)
    (bound : cursor+piece.bytes.length≤2^32) :
    (fieldRecord cursor field).offset.toNat=cursor+field.offset ∧
      cursor≤(fieldRecord cursor field).offset.toNat ∧
      (fieldRecord cursor field).offset.toNat+recordSpan (fieldRecord cursor field)≤cursor+piece.bytes.length := by
  have inside := fits field selected
  have positive : 0<fieldSpan field := by unfold fieldSpan; split <;> omega
  have exactOffset : (fieldRecord cursor field).offset.toNat=cursor+field.offset := by
    simp only [fieldRecord,BitVec.toNat_ofNat]
    omega
  rw [exactOffset]
  change _ ∧ _ ∧ cursor+field.offset+fieldSpan field≤_
  omega

/-- Every generated field lies inside the exact encoded image interval. -/
theorem records_bounds (cursor : Nat) (pieces : List Piece)
    (fits : ∀ piece∈pieces, Fits piece) (bound : cursor+byteLength pieces≤2^32) :
    ∀ record∈records cursor pieces,
      cursor≤record.offset.toNat ∧ record.offset.toNat+recordSpan record≤cursor+byteLength pieces := by
  induction pieces generalizing cursor with
  | nil => intro record member; simp only [records,List.not_mem_nil] at member
  | cons piece rest ih =>
      intro record member
      have totalLength : byteLength (piece::rest)=piece.bytes.length+byteLength rest := rfl
      rw [records] at member
      rcases List.mem_append.mp member with head | tail
      · cases selected : piece.field with
        | none => simp only [pieceRecords,selected,List.not_mem_nil] at head
        | some field =>
            simp only [pieceRecords,selected,List.mem_singleton] at head
            subst record
            have position := field_record_position cursor piece field (fits piece List.mem_cons_self) selected
              (by rw [totalLength] at bound; omega)
            exact ⟨position.2.1,by rw [totalLength]; omega⟩
      · have result := ih (cursor+piece.bytes.length)
          (fun p member => fits p (List.mem_cons_of_mem piece member))
          (by rw [totalLength] at bound; omega) record tail
        exact ⟨by omega,by rw [totalLength]; omega⟩

/-- Each piece has one selected field. Its containment and the append cursor
therefore derive pairwise complete-span separation for the global records. -/
theorem records_separated (cursor : Nat) (pieces : List Piece)
    (fits : ∀ piece∈pieces, Fits piece) (bound : cursor+byteLength pieces≤2^32) :
    (records cursor pieces).Pairwise RecordSeparated := by
  induction pieces generalizing cursor with
  | nil => exact List.Pairwise.nil
  | cons piece rest ih =>
      have totalLength : byteLength (piece::rest)=piece.bytes.length+byteLength rest := rfl
      have tailFits : ∀ p∈rest, Fits p := fun p member => fits p (List.mem_cons_of_mem piece member)
      have tailBound : cursor+piece.bytes.length+byteLength rest≤2^32 := by rw [totalLength] at bound; omega
      have tailApart := ih (cursor+piece.bytes.length) tailFits tailBound
      unfold records
      apply List.pairwise_append.mpr
      refine ⟨?_,tailApart,?_⟩
      · cases selected : piece.field <;> simp [pieceRecords,selected]
      · intro left leftMember right rightMember
        cases selected : piece.field with
        | none => simp only [pieceRecords,selected,List.not_mem_nil] at leftMember
        | some field =>
            simp only [pieceRecords,selected,List.mem_singleton] at leftMember
            subst left
            have position := field_record_position cursor piece field (fits piece List.mem_cons_self) selected
              (by rw [totalLength] at bound; omega)
            have lower := (records_bounds (cursor+piece.bytes.length) rest tailFits tailBound right rightMember).1
            exact Or.inl (by omega)

/-- Canonical memory slices follow the same append offset, including wrapping
architectural addresses. -/
theorem bytes_at_append (code : Memory) (base : Word) (first second : Nat) :
    bytesAt code base (first+second)=bytesAt code base first++
      bytesAt code (base+BitVec.ofNat 64 first) second := by
  simp only [bytesAt,List.range_add,List.map_append,List.map_map]
  congr 1
  apply List.map_congr_left
  intro i member
  simp only [Function.comp_apply,BitVec.ofNat_add,BitVec.add_assoc]

theorem bytes_at_length (code : Memory) (base : Word) (count : Nat) :
    (bytesAt code base count).length=count := by simp only [bytesAt,List.length_map,List.length_range]

/-- An exact full-image equality supplies every original piece's template
bytes at its actual prefix offset. -/
theorem image_slice (code : Memory) (base : Word) (before body after : List Byte)
    (image : bytesAt code base (before.length+body.length+after.length)=before++body++after) :
    bytesAt code (base+BitVec.ofNat 64 before.length) body.length=body := by
  rw [Nat.add_assoc,bytes_at_append] at image
  have tailImage := congrArg (List.drop before.length) image
  rw [List.drop_left' (bytes_at_length code base before.length),List.append_assoc,List.drop_left] at tailImage
  rw [bytes_at_append] at tailImage
  have bodyImage := congrArg (List.take body.length) tailImage
  rw [List.take_left' (bytes_at_length code (base+BitVec.ofNat 64 before.length) body.length),
    List.take_left] at bodyImage
  exact bodyImage

/-- Local construction derives the exact physical mixed-table separation at
every final base; the source image provides actual original opcode facts. -/
theorem layout_table_preservation (pieces : List Piece)
    (fits : ∀ piece∈pieces, Fits piece) (bound : byteLength pieces≤2^32)
    (base : Word) (code : Memory)
    (valid : ∀ record∈records 0 pieces, OriginalValid code (materialize base record))
    (accepted : ∀ record∈records 0 pieces, AcceptedRecord base record) :
    TranslationValidation (intendedCalls ((records 0 pieces).map (materialize base)))
      (emittedCalls ((records 0 pieces).map (materialize base))
        (applyTable ((records 0 pieces).map (materialize base)) code)) Eq :=
  record_table_preservation base _ code (records_separated 0 pieces fits (by simpa using bound)) valid accepted


/-- The fixed10B builder selects its8B immediate at the actual offset2. -/
def movabsPiece (dst : X86.Register) (target : Word) : Piece :=
  ⟨(NativeLinkMovabs.movabsBytes dst 0).toList,some ⟨2,target,false⟩⟩

theorem movabs_piece_fits (dst : X86.Register) (target : Word) : Fits (movabsPiece dst target) := by
  intro field selected
  have same : field=⟨2,target,false⟩ := (Option.some.inj selected).symm
  subst field
  simp +decide [movabsPiece,fieldSpan,NativeLinkMovabs.movabsBytes]

/-- Original full-image equality supplies the actual fixed template at its
append cursor, so template location follows from the encoded byte layout. -/
theorem movabs_template (code : Memory) (base : Word) (before after : List Piece)
    (dst : X86.Register) (target : Word)
    (image : bytesAt code base (byteLength (before++movabsPiece dst target::after))=
      byteImage (before++movabsPiece dst target::after)) :
    (bytesAt code (base+BitVec.ofNat 64 (byteLength before)) 10).toArray=
      NativeLinkMovabs.movabsBytes dst 0 := by
  have shape : byteImage (before++movabsPiece dst target::after)=
      byteImage before++(NativeLinkMovabs.movabsBytes dst 0).toList++byteImage after := by
    simp only [byteImage,List.flatMap_append,List.flatMap_cons,movabsPiece,List.append_assoc]
  have length := image_length (before++movabsPiece dst target::after)
  rw [shape,List.length_append,List.length_append] at length
  rw [←length,shape] at image
  have body := image_slice code base (byteImage before) (NativeLinkMovabs.movabsBytes dst 0).toList
    (byteImage after) image
  rw [image_length] at body
  have result := congrArg List.toArray body
  simpa +decide [NativeLinkMovabs.movabsBytes] using result

/-- The actual prefix length plus immediate offset2 supplies the table member
at PC+2, with its full bound64-bit target. -/
theorem movabs_field_member (base : Word) (before after : List Piece) (dst : X86.Register) (target : Word)
    (bound : byteLength (before++movabsPiece dst target::after)≤2^32) :
    Patch.literal (base+BitVec.ofNat 64 (byteLength before)+(2#64)) target∈
      (records 0 (before++movabsPiece dst target::after)).map (materialize base) := by
  have room : byteLength before+10≤2^32 := by
    rw [length_append] at bound
    simp +decide [byteLength,movabsPiece,NativeLinkMovabs.movabsBytes] at bound
    unfold byteLength
    omega
  have member : fieldRecord (byteLength before) ⟨2,target,false⟩∈
      records 0 (before++movabsPiece dst target::after) := by
    rw [records_append]
    apply List.mem_append.mpr
    right
    simp only [Nat.zero_add,records,pieceRecords,movabsPiece,List.mem_append,List.mem_singleton]
    exact Or.inl trivial
  have wide : (BitVec.ofNat 32 (byteLength before+2)).zeroExtend 64=
      BitVec.ofNat 64 (byteLength before)+(2#64) := by
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_setWidth,BitVec.toNat_ofNat,BitVec.toNat_add]
    omega
  have mapped : materialize base (fieldRecord (byteLength before) ⟨2,target,false⟩)∈
      (records 0 (before++movabsPiece dst target::after)).map (materialize base) :=
    List.mem_map.mpr ⟨_,member,rfl⟩
  simpa only [materialize,fieldRecord,Bool.false_eq_true,ite_false,wide,BitVec.add_assoc] using mapped

/-- Encoded-image identity and local construction now derive field membership,
template location and mixed separation in the complete MOVABS TV instance. -/
theorem layout_movabs_preservation (code : Memory) (base : Word) (before after : List Piece)
    (dst : X86.Register) (target : Word)
    (fits : ∀ piece∈before++movabsPiece dst target::after, Fits piece)
    (bound : byteLength (before++movabsPiece dst target::after)≤2^32)
    (image : bytesAt code base (byteLength (before++movabsPiece dst target::after))=
      byteImage (before++movabsPiece dst target::after))
    (accepted : NativeLinkGuardedEmission.CheckedTable code code
      ((records 0 (before++movabsPiece dst target::after)).map (materialize base)))
    (valid : ∀ record∈records 0 (before++movabsPiece dst target::after), OriginalValid code (materialize base record)) :
    TranslationValidation (NativeLinkMovabs.intended (base+BitVec.ofNat 64 (byteLength before)) dst target)
      (NativeLinkMovabs.emitted
        (applyTable ((records 0 (before++movabsPiece dst target::after)).map (materialize base)) code)
        (base+BitVec.ofNat 64 (byteLength before))) Eq := by
  apply NativeLinkGuardedEmission.checked_movabs_preservation code _ accepted
    (materialized_table_separated base _ (records_separated 0 _ fits (by simpa using bound)))
  · intro patch member
    obtain ⟨record,inside,rfl⟩ := List.mem_map.mp member
    exact valid record inside
  · exact movabs_field_member base before after dst target bound
  · exact movabs_template code base before after dst target image


/-- The loader's complete-span selection is an order-preserving filter,
followed by its existing local offset subtraction. -/
def selectedRecords (chunk : NativeLinkChunkLayout.Chunk) (global : List Record) : List Record :=
  (global.filter (fun record => chunk.offset.toNat≤record.offset.toNat &&
    record.offset.toNat+recordSpan record≤chunk.offset.toNat+chunk.size.toNat)).map
      (NativeLinkChunkLayout.localize chunk)

theorem localized_position (chunk : NativeLinkChunkLayout.Chunk) (record : Record)
    (selected : NativeLinkChunkLayout.Selected chunk record) :
    (NativeLinkChunkLayout.localize chunk record).offset.toNat=record.offset.toNat-chunk.offset.toNat := by
  have firstBound := record.offset.isLt
  have secondBound := chunk.offset.isLt
  change (record.offset-chunk.offset).toNat=_
  simp only [BitVec.toNat_sub]
  unfold NativeLinkChunkLayout.Selected at selected
  omega

theorem selected_records_fit (chunk : NativeLinkChunkLayout.Chunk) (global : List Record) :
    ∀ record∈selectedRecords chunk global, NativeLinkChunkLayout.Fits chunk record := by
  intro record member
  obtain ⟨original,inside,rfl⟩ := List.mem_map.mp member
  have selected := (List.mem_filter.mp inside).2
  simp only [Bool.and_eq_true,decide_eq_true_eq] at selected
  exact NativeLinkChunkLayout.selected_local_fits chunk original selected

/-- Whole-image record separation survives the exact per-chunk filter and
subtraction, supplying the prior chunk theorem's within-chunk premise. -/
theorem selected_records_separated (chunk : NativeLinkChunkLayout.Chunk) (global : List Record)
    (apart : global.Pairwise RecordSeparated) :
    (selectedRecords chunk global).Pairwise RecordSeparated := by
  unfold selectedRecords
  apply List.pairwise_map.mpr
  apply List.Pairwise.imp_of_mem _ (apart.filter _)
  intro first second firstMember secondMember separated
  have firstSelected := (List.mem_filter.mp firstMember).2
  have secondSelected := (List.mem_filter.mp secondMember).2
  simp only [Bool.and_eq_true,decide_eq_true_eq] at firstSelected secondSelected
  have firstPosition := localized_position chunk first firstSelected
  have secondPosition := localized_position chunk second secondSelected
  have firstLower := firstSelected.1
  have secondLower := secondSelected.1
  unfold RecordSeparated at *
  rw [firstPosition,secondPosition]
  change _+recordSpan first≤_ ∨ _+recordSpan second≤_
  rcases separated with forward | backward
  · exact Or.inl (by omega)
  · exact Or.inr (by omega)

/-- Encoded piece containment derives both local fits and local separation;
accepted chunk guards then compose the serialized canonical CALL table. -/
theorem layout_chunk_table_preservation (total : BitVec 32) (chunks : List NativeLinkChunkLayout.Chunk)
    (checked : NativeLinkChunkLayout.CheckedGroup total 0 chunks)
    (pieces : List Piece) (fits : ∀ piece∈pieces, Fits piece) (bound : byteLength pieces≤2^32)
    (base : Word) (code : Memory)
    (valid : ∀ record∈NativeLinkChunkLayout.globalRecords chunks (fun c => selectedRecords c (records 0 pieces)),
      OriginalValid code (materialize base record))
    (accepted : ∀ record∈NativeLinkChunkLayout.globalRecords chunks (fun c => selectedRecords c (records 0 pieces)),
      AcceptedRecord base record) :
    TranslationValidation
      (intendedCalls ((NativeLinkChunkLayout.globalRecords chunks (fun c => selectedRecords c (records 0 pieces))).map (materialize base)))
      (emittedCalls ((NativeLinkChunkLayout.globalRecords chunks (fun c => selectedRecords c (records 0 pieces))).map (materialize base))
        (applyTable ((NativeLinkChunkLayout.globalRecords chunks (fun c => selectedRecords c (records 0 pieces))).map (materialize base)) code)) Eq := by
  apply NativeLinkChunkLayout.chunk_table_preservation total chunks checked _
    (fun chunk member => selected_records_fit chunk (records 0 pieces))
    (fun chunk member => selected_records_separated chunk (records 0 pieces)
      (records_separated 0 pieces fits (by simpa using bound))) base code valid accepted


/-- Metadata production may emit the same records in another order. Complete
span separation is symmetric and therefore follows every such permutation. -/
theorem wire_records_separated (pieces : List Piece)
    (fits : ∀ piece∈pieces, Fits piece) (bound : byteLength pieces≤2^32)
    (wire : List Record) (permutation : (records 0 pieces).Perm wire) :
    wire.Pairwise RecordSeparated := by
  apply (records_separated 0 pieces fits (by simpa using bound)).perm permutation
  intro first second apart
  exact apart.symm

/-- The actual wire order uses the same canonical table law once its records
are connected to the encoded-piece layout, preserving exact CALL effects. -/
theorem wire_table_preservation (pieces : List Piece)
    (fits : ∀ piece∈pieces, Fits piece) (bound : byteLength pieces≤2^32)
    (wire : List Record) (permutation : (records 0 pieces).Perm wire) (base : Word) (code : Memory)
    (valid : ∀ record∈wire, OriginalValid code (materialize base record))
    (accepted : ∀ record∈wire, AcceptedRecord base record) :
    TranslationValidation (intendedCalls (wire.map (materialize base)))
      (emittedCalls (wire.map (materialize base)) (applyTable (wire.map (materialize base)) code)) Eq :=
  record_table_preservation base wire code (wire_records_separated pieces fits bound wire permutation) valid accepted

/-- The complete MOVABS consumer also follows arbitrary production wire
order, while its PC and template come from the original encoded image. -/
theorem wire_movabs_preservation (code : Memory) (base : Word) (before after : List Piece)
    (dst : X86.Register) (target : Word)
    (fits : ∀ piece∈before++movabsPiece dst target::after, Fits piece)
    (bound : byteLength (before++movabsPiece dst target::after)≤2^32)
    (image : bytesAt code base (byteLength (before++movabsPiece dst target::after))=
      byteImage (before++movabsPiece dst target::after))
    (wire : List Record) (permutation : (records 0 (before++movabsPiece dst target::after)).Perm wire)
    (accepted : NativeLinkGuardedEmission.CheckedTable code code (wire.map (materialize base)))
    (valid : ∀ record∈wire, OriginalValid code (materialize base record)) :
    TranslationValidation (NativeLinkMovabs.intended (base+BitVec.ofNat 64 (byteLength before)) dst target)
      (NativeLinkMovabs.emitted (applyTable (wire.map (materialize base)) code)
        (base+BitVec.ofNat 64 (byteLength before))) Eq := by
  apply NativeLinkGuardedEmission.checked_movabs_preservation code _ accepted
    (materialized_table_separated base wire (wire_records_separated _ fits bound wire permutation))
  · intro patch member
    obtain ⟨record,inside,rfl⟩ := List.mem_map.mp member
    exact valid record inside
  · have member := movabs_field_member base before after dst target bound
    exact ((permutation.map (materialize base)).mem_iff).mp member
  · exact movabs_template code base before after dst target image

end KProgTV.NativeLinkByteLayout

#print axioms KProgTV.NativeLinkByteLayout.image_length
#print axioms KProgTV.NativeLinkByteLayout.length_append
#print axioms KProgTV.NativeLinkByteLayout.records_append
#print axioms KProgTV.NativeLinkByteLayout.field_record_position
#print axioms KProgTV.NativeLinkByteLayout.records_bounds
#print axioms KProgTV.NativeLinkByteLayout.records_separated
#print axioms KProgTV.NativeLinkByteLayout.bytes_at_append
#print axioms KProgTV.NativeLinkByteLayout.bytes_at_length
#print axioms KProgTV.NativeLinkByteLayout.image_slice
#print axioms KProgTV.NativeLinkByteLayout.layout_table_preservation

#print axioms KProgTV.NativeLinkByteLayout.movabs_piece_fits

#print axioms KProgTV.NativeLinkByteLayout.movabs_template

#print axioms KProgTV.NativeLinkByteLayout.movabs_field_member

#print axioms KProgTV.NativeLinkByteLayout.layout_movabs_preservation

#print axioms KProgTV.NativeLinkByteLayout.localized_position

#print axioms KProgTV.NativeLinkByteLayout.selected_records_fit

#print axioms KProgTV.NativeLinkByteLayout.selected_records_separated

#print axioms KProgTV.NativeLinkByteLayout.layout_chunk_table_preservation

#print axioms KProgTV.NativeLinkByteLayout.wire_records_separated

#print axioms KProgTV.NativeLinkByteLayout.wire_table_preservation

#print axioms KProgTV.NativeLinkByteLayout.wire_movabs_preservation
