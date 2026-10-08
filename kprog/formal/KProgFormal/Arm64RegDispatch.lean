import KProgFormal.GeneratedArm64RegDispatch
import KProgFormal.GeneratedArm64RegPresence
import KProgFormal.GeneratedArm64MemIndex
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64RegDispatch (gprCount regBits cellNumbers cellNames cellOf
  numberOfName nameOfNumber)
open GeneratedArm64RegPresence (Class classify writable xzrNumber noneNumber)
open GeneratedArm64MemIndex (indexSentinel)
/-- Independent statement of the register numbers the dispatch cell array holds,
built from `List.finRange` rather than the generated literal table. -/
def arm64RegDispatchCellsSpec : List Nat :=
  (List.finRange 31).map (fun i => i.val)

/-- Independent statement of the dispatch cell names, built from `List.finRange`
rather than the generated literal table. -/
def arm64RegDispatchNamesSpec : List String :=
  (List.finRange 31).map (fun i => "x" ++ toString i.val)

/-- Independent statement of which decoded register numbers name a dispatch
cell: exactly the general-purpose numbers below `31`, written against the
literal bound rather than the generated `gprCount`. -/
def arm64RegDispatchCellOfSpec (reg : BitVec 8) : Option Nat :=
  if reg.toNat < 31 then some reg.toNat else none

/-- The generated register-number table equals the independent `List.finRange`
construction, so the dispatch cell index equals the register number. -/
theorem arm64_reg_dispatch_numbers_refine :
    cellNumbers = arm64RegDispatchCellsSpec := by
  unfold cellNumbers arm64RegDispatchCellsSpec
  native_decide

/-- The generated cell-name table equals the independent `List.finRange`
construction, so cell `i` names `x{i}`. -/
theorem arm64_reg_dispatch_names_refine :
    cellNames = arm64RegDispatchNamesSpec := by
  unfold cellNames arm64RegDispatchNamesSpec
  native_decide

/-- The generated register-number table has exactly `gprCount` entries. -/
theorem arm64_reg_dispatch_numbers_length :
    cellNumbers.length = gprCount := rfl

/-- The generated cell-name table has exactly `gprCount` entries, so every
dispatch cell has a name and no name is orphaned. -/
theorem arm64_reg_dispatch_names_length :
    cellNames.length = gprCount := rfl

/-- The register numbers are distinct, so no two dispatch cells alias one
register number. -/
theorem arm64_reg_dispatch_numbers_nodup : cellNumbers.Nodup := by
  unfold cellNumbers
  native_decide

/-- The dispatch cell selector equals the independent literal-bound test for
every decoded register number. -/
theorem arm64_reg_dispatch_cellof_refines (reg : BitVec 8) :
    cellOf reg = arm64RegDispatchCellOfSpec reg := by
  unfold cellOf arm64RegDispatchCellOfSpec gprCount
  rfl

/-- The register-number width is the byte width the sim decodes, pinned so the C
`__u8` register number and the generated `regBits` cannot drift apart. -/
theorem arm64_reg_dispatch_bits_is_8 : regBits = 8 := rfl

/-- The first general-purpose register names cell `0`. -/
theorem arm64_reg_dispatch_cell_x0 : cellOf (0x00 : BitVec 8) = some 0 := rfl

/-- The last general-purpose register names cell `30`, so the whole range is
covered without a gap. -/
theorem arm64_reg_dispatch_cell_x30 : cellOf (0x1e : BitVec 8) = some 30 := rfl

/-- The zero register (`31`) names no dispatch cell. -/
theorem arm64_reg_dispatch_zero_is_none :
    cellOf (0x1f : BitVec 8) = none := rfl

/-- The stack pointer (`32`) names no dispatch cell. -/
theorem arm64_reg_dispatch_sp_is_none :
    cellOf (0x20 : BitVec 8) = none := rfl

/-- The no-register sentinel (`0xff`) names no dispatch cell. -/
theorem arm64_reg_dispatch_sentinel_is_none :
    cellOf (0xff : BitVec 8) = none := rfl

/-- Every one of the `gprCount` register numbers names its own cell and every
other byte names none: the full-range round trip, so the decode is total on the
GPR range and rejects the zero register, the stack pointer and the sentinel. -/
theorem arm64_reg_dispatch_full_range :
    ((List.finRange gprCount).all (fun i => cellOf (BitVec.ofNat 8 i) = some i)) =
        true ∧
      (cellOf (0x1f : BitVec 8) = none) ∧
      (cellOf (0x20 : BitVec 8) = none) ∧
      (cellOf (0xff : BitVec 8) = none) := by
  refine ⟨?_, rfl, rfl, rfl⟩
  unfold gprCount
  native_decide

/-- Every dispatch cell name maps back to its register number, so the
name -> number lookup inverts the number -> name lookup over the whole table. -/
theorem arm64_reg_dispatch_name_number_roundtrip :
    cellNumbers.length = cellNames.length ∧
      (cellNumbers.zip cellNames).all
        (fun p => numberOfName p.2 = some p.1) = true ∧
      (cellNames.zip cellNumbers).all
        (fun p => nameOfNumber p.2 = some p.1) = true := by
  refine ⟨rfl, ?_, ?_⟩ <;> native_decide

/-- The dispatch count equals the zero-register number the register-presence
contract fixes, so the GPR table ends exactly where the write-presence decoder
starts discarding. -/
theorem arm64_reg_dispatch_count_is_xzr : gprCount = xzrNumber.toNat := rfl

/-- The zero register names no dispatch cell, stated against the presence
contract's own zero-register constant. -/
theorem arm64_reg_dispatch_xzr_is_none : cellOf xzrNumber = none := rfl

/-- The no-register sentinel names no dispatch cell, stated against the presence
contract's own sentinel constant. -/
theorem arm64_reg_dispatch_none_is_none : cellOf noneNumber = none := rfl

/-- A register number names a dispatch cell only if a write to it lands in a
destination: the dispatch `none` case is a subset of the presence `discard`
case, so no number the dispatch routes is one the presence decoder discards. -/
theorem arm64_reg_dispatch_cell_implies_writable (reg : BitVec 8) :
    cellOf reg ≠ none → writable reg = true := by
  unfold cellOf writable gprCount
  unfold classify xzrNumber noneNumber
  intro h
  by_cases hz : reg = 31#8
  · subst hz; simp at h
  · by_cases hn : reg = 255#8
    · subst hn; simp at h
    · simp [hz, hn]

/-- The presence `discard` case is exactly the dispatch `none` case: a write the
presence decoder discards names no dispatch cell, so the two contracts classify
the zero register, the sentinel and every GPR identically. -/
theorem arm64_reg_dispatch_writable_not_dispatch_none (reg : BitVec 8) :
    writable reg = false → cellOf reg = none := by
  unfold cellOf writable gprCount
  unfold classify xzrNumber noneNumber
  intro h
  by_cases hz : reg = 31#8
  · subst hz; simp
  · by_cases hn : reg = 255#8
    · subst hn; simp
    · simp [hz, hn] at h

/-- The dispatch sentinel is the memory-index sentinel: both are the all-ones
byte, so the register-number decoder and the memory-index decoder cannot
disagree about "no register". -/
theorem arm64_reg_dispatch_sentinel_is_index_sentinel :
    noneNumber = indexSentinel := rfl

/-- All the dispatch shapes are reachable: the first cell, the last cell, and the
three non-GPR numbers that name none, so no branch of the contract is dead. -/
theorem arm64_reg_dispatch_case_dispatch :
    cellOf (0x00 : BitVec 8) = some 0 ∧
      cellOf (0x1e : BitVec 8) = some 30 ∧
      cellOf (0x1f : BitVec 8) = none ∧
      cellOf (0x20 : BitVec 8) = none ∧
      cellOf (0xff : BitVec 8) = none := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
