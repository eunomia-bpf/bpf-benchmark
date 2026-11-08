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
