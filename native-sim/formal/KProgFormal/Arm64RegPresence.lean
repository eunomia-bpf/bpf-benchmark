import KProgFormal.GeneratedArm64RegPresence
import KProgFormal.GeneratedArm64MemIndex
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64RegPresence (Class classify writable xzrNumber noneNumber)
open GeneratedArm64MemIndex (indexSentinel)

/-- Independent statement of the destination class a decoded register number
names, written against the literal numbers `31` (`XZR`) and `0xff`
(`ARM64_REG_NONE`) rather than the generated constants. -/
def arm64RegClassSpec (reg : BitVec 8) : Class :=
  if reg = (31 : BitVec 8) then .zero
  else if reg = (0xff : BitVec 8) then .none
  else .gpr

/-- Independent statement of write-register presence: a write lands in a
destination exactly when the register number is neither the zero register `31`
nor the no-register sentinel `0xff`. -/
def arm64RegWritableSpec (reg : BitVec 8) : Bool :=
  decide (reg ≠ (31 : BitVec 8)) && decide (reg ≠ (0xff : BitVec 8))

/-- The generated class selector equals the independent literal-number table for
every register number, both boundaries included. -/
theorem arm64_reg_presence_class_refines (reg : BitVec 8) :
    classify reg = arm64RegClassSpec reg := by
  unfold classify arm64RegClassSpec xzrNumber noneNumber
  by_cases h : reg = (31 : BitVec 8) <;> simp [h]

/-- The generated write-register presence predicate equals the independent
conjunction of the two literal-number inequalities, so the guard the three
writeback bodies share is a generated fact rather than a restated pair of
comparisons. -/
theorem arm64_reg_presence_writable_refines (reg : BitVec 8) :
    writable reg = arm64RegWritableSpec reg := by
  unfold writable classify arm64RegWritableSpec xzrNumber noneNumber
  by_cases h : reg = (31 : BitVec 8)
  · subst h; rfl
  · by_cases h2 : reg = (0xff : BitVec 8)
    · subst h2; simp [h]
    · simp_all

/-- The zero-register number is `31` (`ARM64_XZR`), pinned so the C
`KPROG_ARM64_REG_XZR` value and the generated `xzrNumber` cannot drift apart. -/
theorem arm64_reg_presence_xzr_is_31 : xzrNumber = 31 := rfl

/-- The no-register number is the all-ones byte `0xff` (`ARM64_REG_NONE`),
pinned so the C `KPROG_ARM64_REG_NONE` value cannot drift from the generated
`noneNumber`. -/
theorem arm64_reg_presence_none_is_0xff : noneNumber = 0xff := rfl

/-- The write-register sentinel is the memory-index sentinel: both are the
all-ones byte, so the destination-presence decoder and the memory-index presence
decoder cannot disagree about "no register". -/
theorem arm64_reg_presence_none_is_index_sentinel :
    noneNumber = indexSentinel := rfl

/-- A write to the zero register is discarded. -/
theorem arm64_reg_presence_zero_discards : writable xzrNumber = false := rfl

/-- A write to the no-register sentinel is discarded. -/
theorem arm64_reg_presence_none_discards : writable noneNumber = false := rfl

/-- A write to an ordinary register number lands in a destination. -/
theorem arm64_reg_presence_gpr_receives :
    writable (0x00 : BitVec 8) = true := rfl

/-- All three classes are reachable: the two discard arms on the zero register
and the sentinel, and the receiving arm on an ordinary number and its
neighbour, so no arm of the contract is dead. -/
theorem arm64_reg_presence_case_dispatch :
    writable (0x1f : BitVec 8) = false ∧
      writable (0xff : BitVec 8) = false ∧
      writable (0x00 : BitVec 8) = true ∧
      writable (0x1e : BitVec 8) = true := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;>
    unfold writable classify xzrNumber noneNumber <;> native_decide

/-- Canonical examples: the class selector and the presence predicate on the two
boundaries and on plain register numbers, pinning the boundary against concrete
values. -/
theorem arm64_reg_presence_examples :
    classify (0x1f : BitVec 8) = .zero ∧
      classify (0xff : BitVec 8) = .none ∧
      classify (0x00 : BitVec 8) = .gpr ∧
      classify (0x1e : BitVec 8) = .gpr ∧
      writable (0x1f : BitVec 8) = false ∧
      writable (0xff : BitVec 8) = false ∧
      writable (0x07 : BitVec 8) = true := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
