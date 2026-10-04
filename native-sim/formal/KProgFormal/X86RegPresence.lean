import KProgFormal.GeneratedX86RegPresence
import KProgFormal.GeneratedX86MemIndex
import KProgFormal.GeneratedX86MemAux
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86RegPresence (Arm arm absent present sentinel)
open GeneratedX86MemIndex (indexSentinel)
open GeneratedX86MemAux (indexNone)

/-- Independent statement of the operand-register arm a decoded register number
names, written against the literal sentinel `0xff` rather than the generated
`sentinel` constant. -/
def x86RegArmSpec (regByte : BitVec 8) : Arm :=
  if regByte = (0xff : BitVec 8) then .absent else .present

/-- Independent statement of operand-register presence: a decoded register
number names an operand register exactly when it differs from the sentinel
`0xff`. -/
def x86RegPresentSpec (regByte : BitVec 8) : Bool :=
  decide (regByte ≠ (0xff : BitVec 8))

/-- Independent statement of operand-register absence: the complement of
presence, written as the literal-sentinel equality. -/
def x86RegAbsentSpec (regByte : BitVec 8) : Bool :=
  decide (regByte = (0xff : BitVec 8))

/-- The generated arm selector equals the independent literal-sentinel table for
every register number, including the sentinel boundary. -/
theorem x86_reg_presence_arm_refines (regByte : BitVec 8) :
    arm regByte = x86RegArmSpec regByte := by
  unfold arm x86RegArmSpec sentinel
  by_cases h : regByte = (0xff : BitVec 8) <;> simp [h]

/-- The generated presence predicate equals the independent literal-sentinel
inequality for every register number, so the operand-presence guards the memory
bodies share are a generated fact rather than a restated sentinel comparison. -/
theorem x86_reg_presence_present_refines (regByte : BitVec 8) :
    present regByte = x86RegPresentSpec regByte := by
  unfold present arm x86RegPresentSpec sentinel
  by_cases h : regByte = (0xff : BitVec 8) <;>
    simp_all [decide_eq_false_iff_not]

/-- The generated absence predicate equals the independent literal-sentinel
equality: the two predicates are the two sides of the one sentinel test. -/
theorem x86_reg_presence_absent_refines (regByte : BitVec 8) :
    absent (arm regByte) = x86RegAbsentSpec regByte := by
  unfold arm absent x86RegAbsentSpec sentinel
  by_cases h : regByte = (0xff : BitVec 8) <;>
    simp_all [decide_eq_true_iff]

/-- The sentinel is the all-ones byte, pinned so the C `KPROG_X86_REG_SENTINEL`
value and the generated `sentinel` cannot drift apart. -/
theorem x86_reg_presence_sentinel_is_0xff : sentinel = 0xff := rfl

/-- The sentinel byte names the absent arm, so an operand that carries no
register is exactly the one whose decoded register number is `0xff`. -/
theorem x86_reg_presence_sentinel_is_absent : arm sentinel = .absent := rfl

/-- The operand-presence sentinel is the memory-index sentinel: both are the
all-ones byte, so the operand-presence decoder and the memory-index presence
decoder cannot disagree about "no register". -/
theorem x86_reg_presence_sentinel_is_index_sentinel :
    sentinel = indexSentinel := rfl

/-- The operand-presence sentinel is the packed-`AUX` index sentinel (`0xff`),
so a register operand's sentinel and an `AUX` index field's sentinel agree. -/
theorem x86_reg_presence_sentinel_is_index_none :
    sentinel.toNat = indexNone.toNat := rfl

/-- Presence and absence are complementary and total: `absent` inverts
`present`, so no register number is neither and none is both. -/
theorem x86_reg_presence_absent_complement (regByte : BitVec 8) :
    absent (arm regByte) = !present regByte := by
  unfold present arm absent sentinel
  by_cases h : regByte = (0xff : BitVec 8) <;> simp_all

/-- Both arms are reachable: the sentinel byte selects the absent arm and its
two neighbours select the present arm, so neither arm of the contract is dead. -/
theorem x86_reg_presence_case_dispatch :
    present (0xff : BitVec 8) = false ∧
      present (0xfe : BitVec 8) = true ∧
      present (0x00 : BitVec 8) = true ∧
      absent (arm (0xff : BitVec 8)) = true ∧
      absent (arm (0x07 : BitVec 8)) = false := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

/-- Canonical examples: the arm selector and both predicates on the sentinel and
on plain register numbers, pinning the boundary against concrete values. -/
theorem x86_reg_presence_examples :
    arm (0xff : BitVec 8) = .absent ∧
      arm (0x00 : BitVec 8) = .present ∧
      arm (0x07 : BitVec 8) = .present ∧
      present (0xff : BitVec 8) = false ∧ present (0x07 : BitVec 8) = true ∧
      absent (arm (0xff : BitVec 8)) = true ∧
      absent (arm (0x07 : BitVec 8)) = false := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
