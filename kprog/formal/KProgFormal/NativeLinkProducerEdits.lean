import KProgFormal.NativeLinkProducerImage

/-!
Post-encoding vector edits in the native-link producer.

The current x86 producer appends iced code buffers, overwrites fixed-size
CALL/JMP/ELF displacement fields, appends object/literal bytes, and optionally
truncates the final five-byte JmpEnd. This module proves exact finite-vector
and image correspondence for every ordered sequence of those edit operations.
Writes may overlap and their final values follow source order. Fields and
immutable object ranges obtain their image from the final edited vector.
Separate range-frame laws identify the unchanged headers or object bytes.

`Sized` records successful source slice/index bounds as mathematical premises.
`Keeps` records which source edits preserve a chosen range. Both are proof
predicates. Rust/iced execution must still be related to this edit trace; C ABI,
physical kernel copy/embedding, map/helper identity, and object lifetime retain
their implementation interfaces. The existing source-field extractor expects
retired HelperPointer/HelperDispatch arms; its historical grammar and the
current MapImmediate/HelperCallRel32 producer remain distinct source epochs.
-/
namespace KProgFormal.NativeLinkProducerEdits
open Reference NativeLinkProducer NativeLinkProducerImage

inductive Edit where
  | append (bytes : List Byte)
  | write (offset : Nat) (bytes : List Byte)
  | truncate (size : Nat)

def editBytes : Edit → List Byte → List Byte
  | .append added, before => before ++ added
  | .write offset added, before => before.take offset ++ added ++ before.drop (offset+added.length)
  | .truncate size, before => before.take size

def nextSize : Edit → Nat → Nat
  | .append added, size => size+added.length
  | .write _ _, size => size
  | .truncate size, _ => size

def Sized : Edit → Nat → Prop
  | .append _, _ => True
  | .write offset added, size => offset+added.length ≤ size
  | .truncate kept, size => kept ≤ size

def editImage : Edit → Nat → Image → Image
  | .append added, size, image => copy image size (fromList added) 0 added.length
  | .write offset added, _, image => copy image offset (fromList added) 0 added.length
  | .truncate _, _, image => image

theorem edit_length (before : List Byte) (edit : Edit) (sized : Sized edit before.length) :
    (editBytes edit before).length = nextSize edit before.length := by
  cases edit with
  | append added => simp [editBytes, nextSize]
  | write offset added =>
      simp only [Sized] at sized
      simp only [editBytes, List.length_append, List.length_take, List.length_drop, nextSize]
      omega
  | truncate size =>
      exact List.length_take_of_le sized

/-- A successful overwrite retains the prefix and suffix, including arbitrary
out-of-range observations, and replaces exactly its own source byte interval. -/
theorem write_lookup (before added : List Byte) (offset i : Nat)
    (sized : offset+added.length ≤ before.length) :
    (editBytes (.write offset added) before)[i]? =
      if offset ≤ i ∧ i < offset+added.length then added[i-offset]? else before[i]? := by
  have prefixLength : (before.take offset).length=offset := List.length_take_of_le (by omega)
  simp only [editBytes, List.append_assoc, List.getElem?_append, prefixLength]
  by_cases first : i < offset
  · simp only [ite_eq_left first, List.getElem?_take_of_lt first,
      ite_eq_right (by omega : ¬(offset ≤ i ∧ i < offset+added.length))]
  · simp only [ite_eq_right first]
    by_cases middle : i-offset < added.length
    · simp only [ite_eq_left middle, ite_eq_left (by omega : offset ≤ i ∧ i < offset+added.length)]
    · simp only [ite_eq_right middle,
        ite_eq_right (by omega : ¬(offset ≤ i ∧ i < offset+added.length)), List.getElem?_drop]
      congr 1
      omega

/-- Each successful finite-vector edit implements the operational byte image,
starting from any image that already agrees on the live input vector. -/
theorem edit_refines (before : List Byte) (image : Image) (edit : Edit)
    (sized : Sized edit before.length)
    (agree : Agree image (fromList before) 0 before.length) :
    Agree (editImage edit before.length image) (fromList (editBytes edit before))
      0 (editBytes edit before).length := by
  intro i inside
  simp only [Nat.zero_add] at *
  simp only [Agree, Nat.zero_add] at agree
  cases edit with
  | append added =>
      change copy image before.length (fromList added) 0 added.length i =
        fromList (before++added) i
      have bound : i < before.length+added.length := by simpa [editBytes] using inside
      by_cases old : i < before.length
      · rw [copy_frame _ _ _ _ _ _ (Or.inl old)]
        simpa only [fromList, List.getElem?_append_left old] using agree i old
      · have replace : before.length ≤ i ∧ i < before.length+added.length := by omega
        simp only [copy, ite_eq_left replace, Nat.zero_add, fromList,
          List.getElem?_append_right (by omega : before.length ≤ i)]
  | write offset added =>
      change copy image offset (fromList added) 0 added.length i =
        fromList (editBytes (.write offset added) before) i
      rw [show fromList (editBytes (.write offset added) before) i =
        ((editBytes (.write offset added) before)[i]?).getD 0 from rfl,
        write_lookup before added offset i sized]
      simp only [copy]
      split
      · simp only [Nat.zero_add, fromList]
      · have bound : i < before.length := by
          rw [edit_length before (.write offset added) sized] at inside
          exact inside
        exact agree i bound
  | truncate size =>
      have bound : i < size := by
        have := List.length_take_le size before
        change i < (before.take size).length at inside
        omega
      have old : i < before.length := by
        have := List.length_take_le' size before
        change i < (before.take size).length at inside
        omega
      simpa only [editImage, editBytes, fromList, List.getElem?_take_of_lt bound] using agree i old

def runBytes : List Edit → List Byte → List Byte
  | [], before => before
  | edit::rest, before => runBytes rest (editBytes edit before)

def runSize : List Edit → Nat → Nat
  | [], size => size
  | edit::rest, size => runSize rest (nextSize edit size)

def runImage : List Edit → Nat → Image → Image
  | [], _, image => image
  | edit::rest, size, image => runImage rest (nextSize edit size) (editImage edit size image)

def SizedTrace : List Edit → Nat → Prop
  | [], _ => True
  | edit::rest, size => Sized edit size ∧ SizedTrace rest (nextSize edit size)

theorem run_length (edits : List Edit) (before : List Byte)
    (sized : SizedTrace edits before.length) :
    (runBytes edits before).length = runSize edits before.length := by
  induction edits generalizing before with
  | nil => rfl
  | cons edit rest ih =>
      have tail : SizedTrace rest (editBytes edit before).length := by
        rw [edit_length before edit sized.1]
        exact sized.2
      simpa only [runBytes, runSize, edit_length before edit sized.1] using
        ih (editBytes edit before) tail

/-- Complete edit histories, including overlapping writes and final truncation,
produce precisely the final finite vector on every live byte. -/
theorem run_refines (edits : List Edit) (before : List Byte) (image : Image)
    (sized : SizedTrace edits before.length)
    (agree : Agree image (fromList before) 0 before.length) :
    Agree (runImage edits before.length image) (fromList (runBytes edits before))
      0 (runBytes edits before).length := by
  induction edits generalizing before image with
  | nil => exact agree
  | cons edit rest ih =>
      have tail : SizedTrace rest (editBytes edit before).length := by
        rw [edit_length before edit sized.1]
        exact sized.2
      simpa only [runImage, runBytes, edit_length before edit sized.1] using
        ih (editBytes edit before) (editImage edit before.length image) tail
          (edit_refines before image edit sized.1 agree)

/-- These are the source conditions for preserving an existing instruction
header, relocation consumer or immutable object range across later edits. -/
def Keeps (start count : Nat) : Edit → Prop
  | .append _ => True
  | .write offset bytes => start+count ≤ offset ∨ offset+bytes.length ≤ start
  | .truncate size => start+count ≤ size

theorem keeps_fits (edit : Edit) (size start count : Nat)
    (fits : start+count ≤ size) (kept : Keeps start count edit) :
    start+count ≤ nextSize edit size := by
  cases edit <;> simp only [nextSize, Keeps] at * <;> omega

theorem edit_frame (edit : Edit) (size start count : Nat) (image : Image)
    (fits : start+count ≤ size) (kept : Keeps start count edit) :
    Agree (editImage edit size image) image start count := by
  intro i inside
  cases edit with
  | append added =>
      exact copy_frame _ _ size 0 added.length (start+i) (Or.inl (by omega))
  | write offset bytes =>
      apply copy_frame
      simp only [Keeps] at kept
      rcases kept with before | after
      · exact Or.inl (by omega)
      · exact Or.inr (by omega)
  | truncate size => rfl

/-- A header/object byte range survives every preserving producer edit. Its
fit in each intermediate size is derived from the same edit sequence. -/
theorem run_frame (edits : List Edit) (size start count : Nat) (image : Image)
    (fits : start+count ≤ size) (kept : ∀ edit∈edits, Keeps start count edit) :
    Agree (runImage edits size image) image start count ∧
      start+count ≤ runSize edits size := by
  induction edits generalizing size image with
  | nil => exact ⟨fun _ _ => rfl, fits⟩
  | cons edit rest ih =>
      have first := kept edit List.mem_cons_self
      have tail := ih (nextSize edit size) (editImage edit size image)
        (keeps_fits edit size start count fits first)
        (fun e member => kept e (List.mem_cons_of_mem edit member))
      refine ⟨?_, tail.2⟩
      intro i inside
      exact (tail.1 i inside).trans (edit_frame edit size start count image fits first i inside)

/-- Every retained relocation field obtains its bytes from the final vector,
including deliberate changes inside its own field by earlier ELF edits. -/
theorem final_field_bytes (edits : List Edit) (before : List Byte) (record : Record)
    (sized : SizedTrace edits before.length)
    (fits : record.offset.toNat+patchSize record.kind ≤ (runBytes edits before).length) :
    ∀ i<patchSize record.kind,
      runImage edits before.length (fromList before) (record.offset.toNat+i) =
        fromList (runBytes edits before) (record.offset.toNat+i) := by
  intro i inside
  have all := run_refines edits before (fromList before) sized (fun _ _ => rfl)
  simpa only [Nat.zero_add] using all (record.offset.toNat+i) (by omega)

/-- The final edited vector supplies the stored kernel size for every chunk. -/
theorem final_snapshot_size (edits : List Edit) (before : List Byte) (chunk : Chunk)
    (records : List Record) (cursor : Nat)
    (fits : chunk.start+chunk.size ≤ (runBytes edits before).length) :
    sizePass (storeChunk (runBytes edits before) chunk records) cursor = cursor+chunk.size := by
  simp only [sizePass, stored_chunk_size _ _ _ fits]

/-- The canonical final image consumes the final producer vector. Both edit
history and kernel link stages range over arbitrary programs; source execution,
field selection, final layout/embedding and live resource meaning are explicit
interfaces, while every intervening finite byte edit and copy is derived. -/
theorem edited_producer_to_final_bytes (resolve : Resolution) (edits : List Edit)
    (before : List Byte) (sized : SizedTrace edits before.length)
    (scratch writable final : Image) (chunk : Chunk) (records : List Record)
    (selected : ∀ record∈records, Selected chunk record)
    (fits : chunk.start+chunk.size ≤ (runBytes edits before).length)
    (regions : List Region) (native : Placed)
    (member : native∈place 0 regions) (kind : native.native=true)
    (size : native.size=chunk.size) (writes : List Fixup)
    (owners : ∀ write∈writes, ∃ owner∈place 0 regions,
      owner.native=false ∧ fixupFits owner write)
    (memory : Memory) (base : Word)
    (embedded : Embeds memory base
      (applyFixups (copy final 0
        (copy writable native.start
          (applyRecords resolve
            (copy scratch 0 (runImage edits before.length (fromList before)) chunk.start chunk.size)
            (records.map (localize chunk))) 0 chunk.size)
        0 (extent regions)) writes) (extent regions)) :
    ∀ i<chunk.size,
      memory.value (base+BitVec.ofNat 64 (native.start+i)) =
        applyRecords resolve (fromList (runBytes edits before)) records (chunk.start+i) := by
  intro i inside
  have linked := producer_to_final_bytes resolve
    (runImage edits before.length (fromList before)) scratch writable final
    chunk records selected regions native member kind size writes owners memory base embedded i inside
  have images := run_refines edits before (fromList before) sized (fun _ _ => rfl)
  have patches := records_agree resolve _ _ 0 (runBytes edits before).length records images
  exact linked.trans (by simpa only [Nat.zero_add] using patches (chunk.start+i) (by omega))

end KProgFormal.NativeLinkProducerEdits
