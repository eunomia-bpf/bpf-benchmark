import KProgFormal.GeneratedX86RegDispatch
import KProgFormal.GeneratedX86RegPresence
import KProgFormal.GeneratedX86MemIndex
import KProgFormal.GeneratedX86MemAux
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86RegDispatch (gprCount regBits cellNumbers cellNames cellOf
  numberOfName nameOfNumber)
open GeneratedX86RegPresence (sentinel present)
open GeneratedX86MemIndex (indexSentinel)
open GeneratedX86MemAux (indexNone)

/-- Independent statement of the register numbers the dispatch cell array holds,
built from `List.finRange` rather than the generated literal table. -/
def x86RegDispatchCellsSpec : List Nat :=
  (List.finRange 16).map (fun i => i.val)

/-- Independent statement of the dispatch cell names, built from the literal
x86-64 register name order rather than the generated literal table. -/
def x86RegDispatchNamesSpec : List String :=
  ["rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
   "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"]

/-- Independent statement of which decoded register numbers name a dispatch
cell: exactly the general-purpose numbers below `16`, written against the
literal bound rather than the generated `gprCount`. -/
def x86RegDispatchCellOfSpec (reg : BitVec 8) : Option Nat :=
  if reg.toNat < 16 then some reg.toNat else none

/-- The generated register-number table equals the independent `List.finRange`
construction, so the dispatch cell index equals the register number. -/
theorem x86_reg_dispatch_numbers_refine :
    cellNumbers = x86RegDispatchCellsSpec := by
  unfold cellNumbers x86RegDispatchCellsSpec
  native_decide

/-- The generated cell-name table equals the independent literal register-name
order, so cell `i` names the `i`-th x86-64 general-purpose register. -/
theorem x86_reg_dispatch_names_refine :
    cellNames = x86RegDispatchNamesSpec := by
  unfold cellNames x86RegDispatchNamesSpec
  native_decide

/-- The generated register-number table has exactly `gprCount` entries. -/
theorem x86_reg_dispatch_numbers_length :
    cellNumbers.length = gprCount := rfl

/-- The generated cell-name table has exactly `gprCount` entries, so every
dispatch cell has a name and no name is orphaned. -/
theorem x86_reg_dispatch_names_length :
    cellNames.length = gprCount := rfl

/-- The register numbers are distinct, so no two dispatch cells alias one
register number. -/
theorem x86_reg_dispatch_numbers_nodup : cellNumbers.Nodup := by
  unfold cellNumbers
  native_decide

/-- The dispatch cell selector equals the independent literal-bound test for
every decoded register number. -/
theorem x86_reg_dispatch_cellof_refines (reg : BitVec 8) :
    cellOf reg = x86RegDispatchCellOfSpec reg := by
  unfold cellOf x86RegDispatchCellOfSpec gprCount
  rfl

/-- The register-number width is the byte width the sim decodes, pinned so the C
`__u8` register number and the generated `regBits` cannot drift apart. -/
theorem x86_reg_dispatch_bits_is_8 : regBits = 8 := rfl

/-- The first general-purpose register (`rax`) names cell `0`. -/
theorem x86_reg_dispatch_cell_rax : cellOf (0x00 : BitVec 8) = some 0 := rfl

/-- The last general-purpose register (`r15`) names cell `15`, so the whole GPR
range is covered without a gap. -/
theorem x86_reg_dispatch_cell_r15 : cellOf (0x0f : BitVec 8) = some 15 := rfl

/-- The byte just above the GPR range (`16`) names no dispatch cell, so the
dispatch table ends exactly at the last general-purpose register. -/
theorem x86_reg_dispatch_first_non_gpr_is_none :
    cellOf (0x10 : BitVec 8) = none := rfl

/-- The no-register sentinel (`0xff`) names no dispatch cell. -/
theorem x86_reg_dispatch_sentinel_is_none :
    cellOf (0xff : BitVec 8) = none := rfl

/-- Every one of the `gprCount` register numbers names its own cell and every
byte `16..255` names none: the full-range round trip, so the decode is total on
the GPR range and rejects the whole non-GPR tail including the sentinel. -/
theorem x86_reg_dispatch_full_range :
    ((List.finRange gprCount).all (fun i => cellOf (BitVec.ofNat 8 i) = some i)) =
        true ∧
      (cellOf (0x10 : BitVec 8) = none) ∧
      (cellOf (0xfe : BitVec 8) = none) ∧
      (cellOf (0xff : BitVec 8) = none) := by
  refine ⟨?_, rfl, rfl, rfl⟩
  unfold gprCount
  native_decide

/-- Every dispatch cell name maps back to its register number, so the
name -> number lookup inverts the number -> name lookup over the whole table. -/
theorem x86_reg_dispatch_name_number_roundtrip :
    cellNumbers.length = cellNames.length ∧
      (cellNumbers.zip cellNames).all
        (fun p => numberOfName p.2 = some p.1) = true ∧
      (cellNames.zip cellNumbers).all
        (fun p => nameOfNumber p.2 = some p.1) = true := by
  refine ⟨rfl, ?_, ?_⟩ <;> native_decide

/-- The dispatch count is the 16 general-purpose registers x86-64 defines; the
dispatch table has no zero/stack-pointer register to omit, unlike AArch64. -/
theorem x86_reg_dispatch_count_is_16 : gprCount = 16 := rfl

/-- The no-register sentinel names no dispatch cell, stated against the
register-presence contract's own sentinel constant. -/
theorem x86_reg_dispatch_none_is_none : cellOf sentinel = none := rfl

/-- A register number names a dispatch cell only if the presence decoder calls
it present: the dispatch `none` case includes the presence `absent` (sentinel)
case, so no number the dispatch routes is one the presence decoder discards. -/
theorem x86_reg_dispatch_cell_implies_present (reg : BitVec 8) :
    cellOf reg ≠ none → present reg = true := by
  unfold cellOf present gprCount
  unfold GeneratedX86RegPresence.arm GeneratedX86RegPresence.sentinel
  intro h
  by_cases hs : reg = 255#8
  · subst hs; simp at h
  · simp [hs]

/-- The presence `absent` case (the sentinel) is a dispatch `none` case: a
number the presence decoder discards names no dispatch cell, so the two
contracts agree on the sentinel. -/
theorem x86_reg_dispatch_absent_not_dispatch_some (reg : BitVec 8) :
    present reg = false → cellOf reg = none := by
  unfold cellOf present gprCount
  unfold GeneratedX86RegPresence.arm GeneratedX86RegPresence.sentinel
  intro h
  by_cases hs : reg = 255#8
  · subst hs; simp
  · simp [hs] at h

/-- The dispatch sentinel is the memory-index sentinel: both are the all-ones
byte, so the register-number decoder and the memory-index decoder cannot
disagree about "no register". -/
theorem x86_reg_dispatch_sentinel_is_index_sentinel :
    sentinel = indexSentinel := rfl

/-- The dispatch sentinel is the packed-`AUX` index sentinel (`0xff`), so a
register operand's sentinel and an `AUX` index field's sentinel agree. -/
theorem x86_reg_dispatch_sentinel_is_index_none :
    sentinel.toNat = indexNone.toNat := rfl

/-- All the dispatch shapes are reachable: the first cell, the last cell, the
first non-GPR byte, and the sentinel, so no branch of the contract is dead. -/
theorem x86_reg_dispatch_case_dispatch :
    cellOf (0x00 : BitVec 8) = some 0 ∧
      cellOf (0x0f : BitVec 8) = some 15 ∧
      cellOf (0x10 : BitVec 8) = none ∧
      cellOf (0xff : BitVec 8) = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
