import KProgFormal.ClightRefinement.X86PushNativePayload

namespace KProgFormal.ClightRefinement.X86NativeByteFold

/-- Alias of the exact original reference event-memory projection. -/
def storeBytes : Reference.Memory → BitVec 64 → List (BitVec 8) → Reference.Memory := by
  run_tac
    Lean.Elab.Tactic.closeMainGoal `original_reference_byte_store
      (Lean.mkConst (Lean.mkPrivateNameCore `KProgFormal.Reference.X86 `KProgFormal.Reference.X86.storeBytes))

private theorem one (target address : BitVec 64) : (target - address).toNat < 1 ↔ target = address := by
  constructor
  · intro small
    have zero : (target - address).toNat = 0 := by omega
    have same : target - address = 0 := BitVec.eq_of_toNat_eq zero
    have restored := congrArg (fun v => v + address) same
    simpa only [BitVec.sub_add_cancel,show (0 : BitVec 64) = (0#64) from rfl,BitVec.zero_add] using restored
  · intro same
    subst target
    simp

theorem byte_value (memory : Reference.Memory) (address value target : BitVec 64) :
    (Reference.storeMemory memory address value 1).value target =
      if target = address then value.setWidth 8 else memory.value target := by
  simp only [Reference.storeMemory,one]
  split
  · next same => simp only [same,BitVec.sub_self,BitVec.toNat_zero,Nat.mul_zero,BitVec.ushiftRight_zero]
  · rfl

theorem byte_initialized (memory : Reference.Memory) (address value target : BitVec 64) :
    (Reference.storeMemory memory address value 1).initialized target =
      if target = address then true else memory.initialized target := by
  simp only [Reference.storeMemory,one]

/-- Coordinates of each actual event byte within a wrapping scalar store. -/
theorem selected (address target : BitVec 64) (lane : Nat) (bound : lane < 8) :
    target = address + BitVec.ofNat 64 lane ↔ (target - address).toNat = lane := by
  constructor
  · intro same
    subst target
    rw [BitVec.add_comm address,BitVec.add_sub_cancel,BitVec.toNat_ofNat]
    have bound := bound
    omega
  · intro same
    have encoded : target - address = BitVec.ofNat 64 lane := by
      apply BitVec.eq_of_toNat_eq
      rw [same,BitVec.toNat_ofNat]
      have bound := bound
      omega
    have restored := congrArg (fun v => v + address) encoded
    simpa only [BitVec.sub_add_cancel] using (restored.trans (BitVec.add_comm _ _))

private def unfoldStore : Lean.Elab.Tactic.TacticM Unit := do
  let original := Lean.mkIdent (Lean.mkPrivateNameCore `KProgFormal.Reference.X86 `KProgFormal.Reference.X86.storeBytes)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp +decide [storeBytes,$original:term,Reference.valueBytes,List.range_succ,List.foldl_append,
      byte_value,byte_initialized,BitVec.add_assoc]))

/-- Pointwise values and initialization of the original event fold. -/
theorem observations (memory : Reference.Memory) (address value target : BitVec 64) :
    (storeBytes memory address (Reference.valueBytes value 8)).value target =
      (Reference.storeMemory memory address value 8).value target ∧
    (storeBytes memory address (Reference.valueBytes value 8)).initialized target =
      (Reference.storeMemory memory address value 8).initialized target := by
  have eq0 : (target = address) ↔ (target - address).toNat = 0 := by
    simpa using selected address target 0 (by decide)
  have eq1 : (target = address + (1#64)) ↔ (target - address).toNat = 1 := by
    simpa using selected address target 1 (by decide)
  have eq2 : (target = address + (2#64)) ↔ (target - address).toNat = 2 := by
    simpa using selected address target 2 (by decide)
  have eq3 : (target = address + (3#64)) ↔ (target - address).toNat = 3 := by
    simpa using selected address target 3 (by decide)
  have eq4 : (target = address + (4#64)) ↔ (target - address).toNat = 4 := by
    simpa using selected address target 4 (by decide)
  have eq5 : (target = address + (5#64)) ↔ (target - address).toNat = 5 := by
    simpa using selected address target 5 (by decide)
  have eq6 : (target = address + (6#64)) ↔ (target - address).toNat = 6 := by
    simpa using selected address target 6 (by decide)
  have eq7 : (target = address + (7#64)) ↔ (target - address).toNat = 7 := by
    simpa using selected address target 7 (by decide)
  by_cases inside : (target - address).toNat < 8
  · have cases : (target - address).toNat = 0 ∨ (target - address).toNat = 1 ∨ (target - address).toNat = 2 ∨ (target - address).toNat = 3 ∨ (target - address).toNat = 4 ∨ (target - address).toNat = 5 ∨ (target - address).toNat = 6 ∨ (target - address).toNat = 7 := by omega
    rcases cases with same | same | same | same | same | same | same | same
    all_goals constructor
    all_goals run_tac unfoldStore
    all_goals simp only [BitVec.toNat_sub] at eq0 eq1 eq2 eq3 eq4 eq5 eq6 eq7 inside same
    all_goals simp +decide [Reference.storeMemory,eq0,eq1,eq2,eq3,eq4,eq5,eq6,eq7,inside,same]
  · have ne0 : (target-address).toNat ≠ 0 := by omega
    have ne1 : (target-address).toNat ≠ 1 := by omega
    have ne2 : (target-address).toNat ≠ 2 := by omega
    have ne3 : (target-address).toNat ≠ 3 := by omega
    have ne4 : (target-address).toNat ≠ 4 := by omega
    have ne5 : (target-address).toNat ≠ 5 := by omega
    have ne6 : (target-address).toNat ≠ 6 := by omega
    have ne7 : (target-address).toNat ≠ 7 := by omega
    constructor
    all_goals run_tac unfoldStore
    all_goals simp only [BitVec.toNat_sub] at eq0 eq1 eq2 eq3 eq4 eq5 eq6 eq7 inside ne0 ne1 ne2 ne3 ne4 ne5 ne6 ne7
    all_goals simp +decide [Reference.storeMemory,eq0,eq1,eq2,eq3,eq4,eq5,eq6,eq7,inside,ne0,ne1,ne2,ne3,ne4,ne5,ne6,ne7]

/-- The original8-byte event fold equals the common scalar memory store,
including arbitrary old byte values, permissions and initialization. -/
theorem scalar (memory : Reference.Memory) (address value : BitVec 64) :
    storeBytes memory address (Reference.valueBytes value 8) = Reference.storeMemory memory address value 8 := by
  have veq := funext (fun target => (observations memory address value target).1)
  have ieq := funext (fun target => (observations memory address value target).2)
  have readable : (storeBytes memory address (Reference.valueBytes value 8)).readable = memory.readable := by
    run_tac unfoldStore
    rfl
  have writable : (storeBytes memory address (Reference.valueBytes value 8)).writable = memory.writable := by
    run_tac unfoldStore
    rfl
  cases left : storeBytes memory address (Reference.valueBytes value 8) with
  | mk lv lr lw li =>
    cases right : Reference.storeMemory memory address value 8 with
    | mk rv rr rw ri =>
      rw [left,right] at veq ieq
      rw [left] at readable writable
      cases veq
      cases ieq
      simp only [Reference.storeMemory] at right
      cases right
      simp_all

end KProgFormal.ClightRefinement.X86NativeByteFold
