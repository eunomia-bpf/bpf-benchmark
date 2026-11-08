import KProgFormal.Generated.GeneratedX86StackIndex
namespace KProgFormal
open GeneratedX86StackIndex (index)
/-- Native addresses wrap only at 64 bits, independently stated with commuted operands. -/
def x86StackIndexSpec (capacity off : BitVec 64) : BitVec 64 := off + capacity
theorem x86_stack_index_refines (capacity off : BitVec 64) :
    index capacity off = x86StackIndexSpec capacity off := by
  unfold index x86StackIndexSpec
  bv_decide
theorem x86_stack_index_frame_base_is_zero (capacity : BitVec 64) :
    index capacity (-capacity) = 0 := by
  unfold index
  bv_decide
theorem x86_stack_index_top_is_capacity (capacity : BitVec 64) :
    index capacity 0 = capacity := by
  unfold index
  bv_decide
/-- Adding a nonzero high word cannot alias a distinct native address. -/
theorem x86_stack_index_high_bits_distinct (capacity off delta : BitVec 64)
    (h : delta ≠ 0) : index capacity (off + delta) ≠ index capacity off := by
  unfold index
  bv_decide
/-- The old high32 alias input remains, with its corrected native64 result. -/
theorem x86_stack_index_example :
    index 64 (-56) = 8 ∧ index 64 (-8) = 56 ∧ index 64 0 = 64 ∧
    index 64 ((-56) + 0x100000000) = 0x100000008 := by
  decide
end KProgFormal

namespace KProgFormal.X86StackCallFrame

/-- C's slot counter is unsigned32; capacity and byte coordinates retain all
64 bits. Frame ownership supplies the existing allocated interval. -/
def slotStart (slot : BitVec 32) : BitVec 64 := slot.setWidth 64 * 8

def slotOffset (capacity : BitVec 64) (slot : BitVec 32) : BitVec 64 :=
  slotStart slot - capacity

theorem slot_index_inverse (capacity : BitVec 64) (slot : BitVec 32) :
    GeneratedX86StackIndex.index capacity (slotOffset capacity slot) = slotStart slot := by
  unfold GeneratedX86StackIndex.index slotOffset
  bv_decide

theorem slot_address (arena capacity : BitVec 64) (slot : BitVec 32) :
    (arena + capacity) + slotOffset capacity slot = arena + slotStart slot := by
  unfold slotOffset
  bv_decide

/-- Sign extension commutes with the existing C signed subtraction, proving
its absence of signed overflow for a nonnegative capacity and a uint32 slot. -/
theorem signed_offset_exact (capacity : BitVec 64) (slot : BitVec 32)
    (capacityPositive : capacity.msb = false) :
    (slotOffset capacity slot).signExtend 65 =
      (slotStart slot).signExtend 65 - capacity.signExtend 65 := by
  unfold slotOffset slotStart at *
  bv_decide

/-- Signed native offsets and unsigned byte indices classify exactly the same
below-SP slots, throughout the existing allocated interval. -/
theorem below_sp_index (capacity spIndex : BitVec 64) (slot : BitVec 32)
    (capacityPositive : capacity.msb = false)
    (slotInFrame : slotStart slot ≤ capacity) (spInFrame : spIndex ≤ capacity) :
    (slotOffset capacity slot).slt (spIndex-capacity) = (slotStart slot).ult spIndex := by
  unfold slotOffset slotStart at *
  bv_decide

def generatedTag (capacity sp : BitVec 64) (tags : BitVec 32 → BitVec 8)
    (slot : BitVec 32) : BitVec 8 :=
  if (slotOffset capacity slot).slt sp then 0 else tags slot

def allocatedTag (spIndex : BitVec 64) (tags : BitVec 32 → BitVec 8)
    (slot : BitVec 32) : BitVec 8 :=
  if (slotStart slot).ult spIndex then 0 else tags slot

/-- Exact correspondence with the signed comparison written in C. -/
theorem generated_tag_signed (capacity sp : BitVec 64) (tags : BitVec 32 → BitVec 8)
    (slot : BitVec 32) :
    generatedTag capacity sp tags slot =
      if (slotOffset capacity slot).toInt < sp.toInt then 0 else tags slot := by
  simp only [generatedTag, BitVec.slt_eq_decide, decide_eq_true_eq]

/-- Deallocated slots lose their ghost tags, while the tag at SP and every
later allocated slot retain their incoming value. -/
theorem call_frame_tag (capacity spIndex : BitVec 64) (slot : BitVec 32)
    (tags : BitVec 32 → BitVec 8) (capacityPositive : capacity.msb = false)
    (slotInFrame : slotStart slot ≤ capacity) (spInFrame : spIndex ≤ capacity) :
    generatedTag capacity (spIndex-capacity) tags slot = allocatedTag spIndex tags slot := by
  simp only [generatedTag, allocatedTag,
    below_sp_index capacity spIndex slot capacityPositive slotInFrame spInFrame]

/-- The existing generated stack index supplies SP's coordinate with the
same origin, including arbitrary wrapping physical arena bases. -/
theorem call_frame_tag_raw_sp (capacity sp : BitVec 64) (slot : BitVec 32)
    (tags : BitVec 32 → BitVec 8) (capacityPositive : capacity.msb = false)
    (slotInFrame : slotStart slot ≤ capacity)
    (spInFrame : GeneratedX86StackIndex.index capacity sp ≤ capacity) :
    generatedTag capacity sp tags slot =
      allocatedTag (GeneratedX86StackIndex.index capacity sp) tags slot := by
  have origin : GeneratedX86StackIndex.index capacity sp-capacity=sp := by
    unfold GeneratedX86StackIndex.index
    bv_decide
  simpa only [origin] using call_frame_tag capacity
    (GeneratedX86StackIndex.index capacity sp) slot tags capacityPositive slotInFrame spInFrame

theorem at_sp_preserved (capacity : BitVec 64) (slot : BitVec 32)
    (tags : BitVec 32 → BitVec 8) :
    generatedTag capacity (slotOffset capacity slot) tags slot = tags slot := by
  simp [generatedTag, BitVec.slt]

end KProgFormal.X86StackCallFrame
#print axioms KProgFormal.X86StackCallFrame.signed_offset_exact
#print axioms KProgFormal.X86StackCallFrame.below_sp_index
#print axioms KProgFormal.X86StackCallFrame.call_frame_tag_raw_sp

namespace KProgFormal.X86StackGhost
open X86StackCallFrame
abbrev Address := BitVec 64
abbrev Slot := BitVec 32

/-- Private metadata from x86_sim_stack_value. Raw guest bytes and their
initialization/permissions are separate from this table. Only tag4 permits
reading the private STACK pointer representative; all other tags ignore it. -/
structure Cell where
  tag : BitVec 8
  pointer : Address
  deriving DecidableEq

def Equivalent (a b : Cell) : Prop :=
  a.tag = b.tag ∧ (a.tag = 4 → a.pointer = b.pointer)

/-- Exact output of SV_READ_ONE for one slot. Width is the existing effective
byte width, not a new admission predicate. A non-STACK result has pointer0. -/
def readCell (index width : Address) (slot : Slot) (c : Cell) : Cell :=
  if width = 8 ∧ index = slotStart slot ∧ c.tag ≠ 0 then
    ⟨c.tag, if c.tag = 4 then c.pointer else 0⟩
  else ⟨0, 0⟩

/-- SV_SAVE_ONE writes the representative only for STACK, and writes the tag
for every non-scalar full-width save at the slot's byte coordinate. -/
def saveCell (index width pointer : Address) (tag : BitVec 8) (slot : Slot) (c : Cell) : Cell :=
  if width = 8 ∧ tag ≠ 0 ∧ index = slotStart slot then
    ⟨tag, if tag = 4 then pointer else c.pointer⟩
  else c

def clearCell (condition : Bool) (c : Cell) : Cell :=
  if condition then { c with tag := 0 } else c

/-- The existing wrapping byte-overlap policy is copied without strengthening
its domain. This theorem concerns metadata erasure, not guest permissions. -/
def eraseCell (index width : Address) (slot : Slot) (c : Cell) : Cell :=
  clearCell ((index - slotStart slot).ult 8 || (slotStart slot - index).ult width) c

def frameCell (capacity sp : Address) (slot : Slot) (c : Cell) : Cell :=
  clearCell ((slotOffset capacity slot).slt sp) c

theorem read_equivalent (a b : Cell) (same : Equivalent a b)
    (index width : Address) (slot : Slot) :
    readCell index width slot a = readCell index width slot b := by
  rcases same with ⟨tags, pointers⟩
  unfold readCell
  by_cases stack : a.tag = 4
  · have ptr := pointers stack
    simp only [← tags, stack, ptr]
  · simp only [← tags, stack, ↓reduceIte]

theorem save_equivalent (a b : Cell) (same : Equivalent a b)
    (index width pointer : Address) (tag : BitVec 8) (slot : Slot) :
    Equivalent (saveCell index width pointer tag slot a)
      (saveCell index width pointer tag slot b) := by
  unfold saveCell
  split
  · constructor
    · rfl
    · intro stack
      simp_all
  · exact same

theorem clear_equivalent (a b : Cell) (same : Equivalent a b) (condition : Bool) :
    Equivalent (clearCell condition a) (clearCell condition b) := by
  cases condition <;> simp [clearCell, Equivalent] at *
  exact same

theorem erase_equivalent (a b : Cell) (same : Equivalent a b)
    (index width : Address) (slot : Slot) :
    Equivalent (eraseCell index width slot a) (eraseCell index width slot b) :=
  clear_equivalent a b same _

theorem frame_equivalent (a b : Cell) (same : Equivalent a b)
    (capacity sp : Address) (slot : Slot) :
    Equivalent (frameCell capacity sp slot a) (frameCell capacity sp slot b) :=
  clear_equivalent a b same _

abbrev Table := Slot → Cell

def TablesEquivalent (a b : Table) : Prop := ∀ slot, Equivalent (a slot) (b slot)

inductive Action where
  | save (index width pointer : Address) (tag : BitVec 8)
  | erase (index width : Address)
  | frame (capacity sp : Address)
  | clear

def applyAction (action : Action) (table : Table) : Table := fun slot =>
  match action with
  | .save index width pointer tag => saveCell index width pointer tag slot (table slot)
  | .erase index width => eraseCell index width slot (table slot)
  | .frame capacity sp => frameCell capacity sp slot (table slot)
  | .clear => clearCell true (table slot)

def run : List Action → Table → Table
  | [], table => table
  | action :: rest, table => run rest (applyAction action table)

theorem action_preserves (a b : Table) (same : TablesEquivalent a b) (action : Action) :
    TablesEquivalent (applyAction action a) (applyAction action b) := by
  intro slot
  cases action with
  | save index width pointer tag => exact save_equivalent _ _ (same slot) index width pointer tag slot
  | erase index width => exact erase_equivalent _ _ (same slot) index width slot
  | frame capacity sp => exact frame_equivalent _ _ (same slot) capacity sp slot
  | clear => exact clear_equivalent _ _ (same slot) true

theorem run_preserves (a b : Table) (same : TablesEquivalent a b) (actions : List Action) :
    TablesEquivalent (run actions a) (run actions b) := by
  induction actions generalizing a b with
  | nil => exact same
  | cons action rest ih => exact ih _ _ (action_preserves a b same action)

/-- Arbitrary symbolic inactive payloads and defined zero-initialized payloads
have identical metadata observations after every finite sequence of the actual
save/invalidate/frame/clear policies. This is a C-model erasure law; it does not
claim that an uninitialized C read is defined or that clang preserves a path. -/
theorem initialized_payloads_unobservable (arbitrary : Slot → Address) (actions : List Action)
    (index width : Address) (slot : Slot) :
    readCell index width slot (run actions (fun i => ⟨0, arbitrary i⟩) slot) =
      readCell index width slot (run actions (fun _ => ⟨0, 0⟩) slot) := by
  apply read_equivalent
  apply run_preserves
  intro i
  simp [Equivalent]

/-- More generally, every non-STACK payload can be replaced independently.
All tag values, including non-scalar origins, remain unchanged. -/
theorem inactive_payloads_unobservable (table : Table) (replacements : Slot → Address)
    (actions : List Action) (index width : Address) (slot : Slot) :
    readCell index width slot (run actions table slot) =
      readCell index width slot
        (run actions (fun i => if (table i).tag = 4 then table i
          else { table i with pointer := replacements i }) slot) := by
  apply read_equivalent
  apply run_preserves
  intro i
  change Equivalent (table i) (if (table i).tag = (4 : BitVec 8) then table i
    else { table i with pointer := replacements i })
  split
  · exact ⟨rfl, fun _ => rfl⟩
  · rename_i inactive
    exact ⟨rfl, fun active => False.elim (inactive active)⟩

/-- The current read policy observes the complete pointer exactly when STACK
is active, so active representatives cannot be erased by the relation. -/
theorem active_pointer_retained (slot : Slot) (pointer : Address) :
    readCell (slotStart slot) 8 slot ⟨4, pointer⟩ = ⟨4, pointer⟩ := by
  simp [readCell]


/-- Exact SV_READ_ONE accumulator update, including its retention of the
previous pointer for a non-STACK tag. No uniqueness premise is needed. -/
def readInto (index width : Address) (slot : Slot) (c result : Cell) : Cell :=
  if width = 8 ∧ index = slotStart slot ∧ c.tag ≠ 0 then
    ⟨c.tag, if c.tag = 4 then c.pointer else result.pointer⟩
  else result

theorem read_into_equivalent (a b : Cell) (same : Equivalent a b)
    (index width : Address) (slot : Slot) (result : Cell) :
    readInto index width slot a result = readInto index width slot b result := by
  rcases same with ⟨tags, pointers⟩
  unfold readInto
  by_cases stack : a.tag = 4
  · have ptr := pointers stack
    simp only [← tags, stack, ptr]
  · simp only [← tags, stack, ↓reduceIte]

def readTable : List Slot → Address → Address → Table → Cell → Cell
  | [], _, _, _, result => result
  | slot :: rest, index, width, table, result =>
      readTable rest index width table (readInto index width slot (table slot) result)

/-- Every finite generated slot enumeration has the same whole lookup result.
The proof permits arbitrary order and duplicate entries, so both array and
named-cell unrolling instances are covered without a side condition. -/
theorem read_table_equivalent (a b : Table) (same : TablesEquivalent a b)
    (slots : List Slot) (index width : Address) (result : Cell) :
    readTable slots index width a result = readTable slots index width b result := by
  induction slots generalizing result with
  | nil => rfl
  | cons slot rest ih =>
    simp only [readTable, read_into_equivalent (a slot) (b slot) (same slot)]
    exact ih _

theorem initialized_table_read_unobservable (arbitrary : Slot → Address)
    (actions : List Action) (slots : List Slot) (index width : Address) :
    readTable slots index width (run actions (fun i => ⟨0, arbitrary i⟩)) ⟨0, 0⟩ =
      readTable slots index width (run actions (fun _ => ⟨0, 0⟩)) ⟨0, 0⟩ := by
  apply read_table_equivalent
  apply run_preserves
  intro slot
  simp [Equivalent]

theorem inactive_table_read_unobservable (table : Table) (replacements : Slot → Address)
    (actions : List Action) (slots : List Slot) (index width : Address) :
    readTable slots index width (run actions table) ⟨0, 0⟩ =
      readTable slots index width
        (run actions (fun i => if (table i).tag = 4 then table i
          else { table i with pointer := replacements i })) ⟨0, 0⟩ := by
  apply read_table_equivalent
  apply run_preserves
  intro i
  change Equivalent (table i) (if (table i).tag = (4 : BitVec 8) then table i
    else { table i with pointer := replacements i })
  split
  · exact ⟨rfl, fun _ => rfl⟩
  · rename_i inactive
    exact ⟨rfl, fun active => False.elim (inactive active)⟩

end KProgFormal.X86StackGhost
#print axioms KProgFormal.X86StackGhost.run_preserves
#print axioms KProgFormal.X86StackGhost.initialized_payloads_unobservable
#print axioms KProgFormal.X86StackGhost.inactive_payloads_unobservable
#print axioms KProgFormal.X86StackGhost.active_pointer_retained

#print axioms KProgFormal.X86StackGhost.read_table_equivalent
#print axioms KProgFormal.X86StackGhost.initialized_table_read_unobservable
#print axioms KProgFormal.X86StackGhost.inactive_table_read_unobservable
