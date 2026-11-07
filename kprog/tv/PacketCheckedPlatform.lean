import PacketEntryCertificate
import SimpleCheckedPlatform
set_option maxRecDepth 4096
set_option maxHeartbeats 1000000
namespace KProgTV.PacketCheckedPlatform
open KProgFormal.Reference KProgTV.PacketCompiled
abbrev physical := PacketEntryCertificate.physical
abbrev externals := SimpleCheckedPlatform.externals
abbrev environment := SimpleCheckedPlatform.environment

theorem first_virtual : BPF.decode program 0 = .ok ⟨0x61,2,1,0,0⟩ := rfl
theorem second_virtual : BPF.decode program 2 = .ok ⟨0x61,1,1,4,0⟩ := rfl
theorem first_physical : BPF.decode physical 0 = .ok ⟨0x79,2,1,0,0⟩ := rfl
theorem second_physical : BPF.decode physical 2 = .ok ⟨0x79,1,1,8,0⟩ := rfl

theorem first_step (s : BPF.State) (pc : s.pc = 0) (active : s.halted = false) :
    BPFPlatform.step environment program s = BPF.step externals physical s := by
  have virtual := BPFPlatform.step_program_congr_if_wide environment program SimpleChecked.program s
    ⟨0x61,2,1,0,0⟩ (by simpa [pc] using first_virtual)
    (by simpa [pc] using SimpleCheckedPlatform.first_virtual)
    (by intro impossible; contradiction)
  have plain := BPFPlatform.physical_step_program_congr_if_wide externals SimpleCheckedPlatform.physical physical s
    ⟨0x79,2,1,0,0⟩ (by simpa [pc] using SimpleCheckedPlatform.first_physical)
    (by simpa [pc] using first_physical) (by intro impossible; contradiction)
  exact virtual.trans ((SimpleCheckedPlatform.first_step s pc active).trans plain)

theorem second_step (s : BPF.State) (pc : s.pc = 2) (active : s.halted = false) :
    BPFPlatform.step environment program s = BPF.step externals physical s := by
  have virtual := BPFPlatform.step_program_congr_if_wide environment program SimpleChecked.program s
    ⟨0x61,1,1,4,0⟩ (by simpa [pc] using second_virtual)
    (by simpa [pc] using SimpleCheckedPlatform.second_virtual)
    (by intro impossible; contradiction)
  have plain := BPFPlatform.physical_step_program_congr_if_wide externals SimpleCheckedPlatform.physical physical s
    ⟨0x79,1,1,8,0⟩ (by simpa [pc] using SimpleCheckedPlatform.second_physical)
    (by simpa [pc] using second_physical) (by intro impossible; contradiction)
  exact virtual.trans ((SimpleCheckedPlatform.second_step s pc active).trans plain)

theorem ordinary_decode : ∀ pc : Fin 26, pc.val ≠ 0 → pc.val ≠ 2 →
    BPF.decode physical pc.val = BPF.decode program pc.val := by
  have same : ∀ pc : Fin 26, pc.val ≠ 0 → pc.val ≠ 2 →
      (match BPF.decode physical pc.val, BPF.decode program pc.val with
        | .ok a, .ok b => decide (a = b) | _, _ => false) = true := by native_decide
  intro pc first second
  have known := same pc first second
  cases a : BPF.decode physical pc.val <;> cases b : BPF.decode program pc.val <;> simp_all

theorem ordinary_instruction : ∀ pc : Fin 26, pc.val ≠ 0 → pc.val ≠ 2 →
    ∃ i : BPF.Instruction, BPF.decode physical pc.val = .ok i ∧
      BPF.decode program pc.val = .ok i ∧ i.code ≠ 0x18 := by
  have noWide : ∀ pc : Fin 26, (match BPF.decode physical pc.val with
      | .error _ => false | .ok i => i.code != 0x18) = true := by native_decide
  intro pc first second
  have same := ordinary_decode pc first second
  cases decoded : BPF.decode physical pc.val with
  | error error => simpa [decoded] using noWide pc
  | ok i => exact ⟨i, rfl, same.symm.trans decoded, by simpa [decoded] using noWide pc⟩

theorem ordinary_step (s : BPF.State) (pc : Fin 26)
    (position : s.pc = pc.val) (active : s.halted = false)
    (notFirst : pc.val ≠ 0) (notSecond : pc.val ≠ 2) :
    BPFPlatform.step environment program s = BPF.step externals physical s := by
  obtain ⟨i, physicalDecode, virtualDecode, notWide⟩ := ordinary_instruction pc notFirst notSecond
  have same := BPF.execute_program_congr_if_wide externals program physical s i
    (fun wide => False.elim (notWide wide))
  have nonnegative : ¬ (pc.val : Int) < 0 := by omega
  have first : (pc.val : Int) ≠ 0 := by omega
  have second : (pc.val : Int) ≠ 2 := by omega
  simpa [BPFPlatform.step, BPF.step, active, position, environment, SimpleCheckedPlatform.environment,
    first, second, nonnegative, virtualDecode, physicalDecode,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad] using same

theorem step_equal (s : BPF.State) (pc : Fin 26)
    (position : s.pc = pc.val) (active : s.halted = false) :
    BPFPlatform.step environment program s = BPF.step externals physical s := by
  by_cases first : pc.val = 0
  · exact first_step s (by omega) active
  · by_cases second : pc.val = 2
    · exact second_step s (by omega) active
    · exact ordinary_step s pc position active first second

theorem accepted_step (s : BPF.State) (result : Transition BPF.State)
    (accepted : BPF.step externals physical s = .ok result) :
    BPFPlatform.step environment program s = .ok result := by
  have active : s.halted = false := by cases h : s.halted <;> simp_all [BPF.step]
  have nonnegative : ¬ s.pc < 0 := by
    intro h
    simp [BPF.step, active, h] at accepted
  have inside : s.pc.toNat < 26 := by
    by_cases h : s.pc.toNat < 26
    · exact h
    have outside : 8*s.pc.toNat+8 > physical.size := by
      have extent : physical.size = 208 := rfl
      omega
    simp [BPF.step, active, nonnegative, BPF.decode, outside,
      Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad] at accepted
  have position : s.pc = (s.pc.toNat : Int) := by omega
  rw [step_equal s ⟨s.pc.toNat, inside⟩ position active]
  exact accepted

def instructionStep : BlockStep BPF.State := fun before events after =>
  ∃ result, BPFPlatform.step environment program before = .ok result ∧
    result.events = events ∧ result.state = after

theorem execution_transport {s t : BPF.State} {events : List Event}
    (run : Execution (BPFPath.instructionStep externals physical) s events t) :
    Execution instructionStep s events t := by
  induction run with
  | refl => exact Execution.refl _
  | next head tail ih =>
    obtain ⟨result, accepted, trace, state⟩ := head
    exact Execution.next ⟨result, accepted_step _ _ accepted, trace, state⟩ ih

theorem body_evaluate (positions : List Nat) (inside : ∀ pc ∈ positions, 4 ≤ pc ∧ pc < 26)
    (s : BPF.State) : BPFPath.evaluate externals physical positions s =
      BPFPath.evaluate externals program positions s := by
  apply BPFPath.evaluate_program_congr_if_wide
  intro pc member
  have bounds := inside pc member
  obtain ⟨i, first, second, noWide⟩ := ordinary_instruction ⟨pc, bounds.2⟩ (by change pc ≠ 0; omega) (by change pc ≠ 2; omega)
  exact ⟨i, first, second, fun wide => False.elim (noWide wide)⟩
end KProgTV.PacketCheckedPlatform
#print axioms KProgTV.PacketCheckedPlatform.first_step
#print axioms KProgTV.PacketCheckedPlatform.second_step
#print axioms KProgTV.PacketCheckedPlatform.execution_transport
