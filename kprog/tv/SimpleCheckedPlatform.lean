import BPFPlatform
import SimpleChecked
import SimplePlatform

set_option maxRecDepth 4096
set_option maxHeartbeats 1000000

namespace KProgTV.SimpleCheckedPlatform
open KProgFormal.Reference

/-- Physical conversion of only the two context loads, captured on both
kernels for this same XDP type/attach/flags contract. The expanded EXIT
rewrite is retained byte for byte. -/
def physical : Array Byte :=
  (SimpleChecked.program.set! 0 0x79 |>.set! 16 0x79 |>.set! 18 8)

def externals : BPF.Environment where
  immediate := fun _ _ _ => .error "no immediate in captured simple artifact"
  helperCall := fun _ _ => .error "no helper in captured simple artifact"
  helper := fun _ _ _ => .error "no helper in captured simple artifact"

def first : BPFPlatform.Expansion where
  original := ⟨0x61, 2, 1, 0, 0⟩
  bytes := SimplePlatform.physical.extract 0 8
  positions := fun _ => [0]

def second : BPFPlatform.Expansion where
  original := ⟨0x61, 1, 1, 4, 0⟩
  bytes := SimplePlatform.physical.extract 16 24
  positions := fun _ => [0]

def environment : BPFPlatform.Environment where
  bpf := externals
  access := fun pc _ => .ok (if pc = 0 then some first else if pc = 2 then some second else none)

theorem first_virtual : BPF.decode SimpleChecked.program 0 = .ok first.original := rfl
theorem second_virtual : BPF.decode SimpleChecked.program 2 = .ok second.original := rfl
theorem first_physical : BPF.decode physical 0 = .ok ⟨0x79,2,1,0,0⟩ := rfl
theorem second_physical : BPF.decode physical 2 = .ok ⟨0x79,1,1,8,0⟩ := rfl

theorem ordinary_decode : ∀ pc : Fin 29, pc.val ≠ 0 → pc.val ≠ 2 →
    BPF.decode physical pc.val = BPF.decode SimpleChecked.program pc.val := by
  simp only [Fin.forall_fin_succ]
  repeat' (first | exact fun h => False.elim (h rfl) |
    exact fun _ h => False.elim (h rfl) | exact fun _ _ => rfl | constructor)
  all_goals (intro i; exact Fin.elim0 i)

theorem first_expansion : BPF.decode first.bytes 0 = .ok ⟨0x79,2,1,0,0⟩ := rfl
theorem second_expansion : BPF.decode second.bytes 0 = .ok ⟨0x79,1,1,8,0⟩ := rfl

theorem first_step (s : BPF.State) (pc : s.pc = 0) (active : s.halted = false) :
    BPFPlatform.step environment SimpleChecked.program s = BPF.step externals physical s := by
  have size : SimplePlatform.physical.size = 224 := rfl
  have decoded : BPF.decode (SimplePlatform.physical.extract 0 8) 0 = .ok ⟨0x79,2,1,0,0⟩ := rfl
  cases read : readMemory s.memory (s.regs 1) 8 with
  | error fault =>
    simp +decide [BPFPlatform.step, BPF.step, environment, pc, active, first_virtual,
      first_physical, BPFPlatform.expand, first, BPFPath.evaluate, decoded, size,
      BPF.execute, BPF.load, read, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
    cases s
    simp_all
  | ok pair =>
    rcases pair with ⟨value, event⟩
    simp +decide [BPFPlatform.step, BPF.step, environment, pc, active, first_virtual,
      first_physical, BPFPlatform.expand, first, BPFPath.evaluate, decoded, size,
      BPF.execute, BPF.load, read, BPF.setReg, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem second_step (s : BPF.State) (pc : s.pc = 2) (active : s.halted = false) :
    BPFPlatform.step environment SimpleChecked.program s = BPF.step externals physical s := by
  have size : SimplePlatform.physical.size = 224 := rfl
  have decoded : BPF.decode (SimplePlatform.physical.extract 16 24) 0 = .ok ⟨0x79,1,1,8,0⟩ := rfl
  cases read : readMemory s.memory (s.regs 1 + (8#64)) 8 with
  | error fault =>
    simp +decide [BPFPlatform.step, BPF.step, environment, pc, active, second_virtual,
      second_physical, BPFPlatform.expand, second, BPFPath.evaluate, decoded, size,
      BPF.execute, BPF.load, read, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
    cases s
    simp_all
  | ok pair =>
    rcases pair with ⟨value, event⟩
    simp +decide [BPFPlatform.step, BPF.step, environment, pc, active, second_virtual,
      second_physical, BPFPlatform.expand, second, BPFPath.evaluate, decoded, size,
      BPF.execute, BPF.load, read, BPF.setReg, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem ordinary_instruction : ∀ pc : Fin 29, pc.val ≠ 0 → pc.val ≠ 2 →
    ∃ i : BPF.Instruction,
      BPF.decode physical pc.val = .ok i ∧
      BPF.decode SimpleChecked.program pc.val = .ok i ∧ i.code ≠ 0x18 := by
  have noWide : ∀ pc : Fin 29, (match BPF.decode physical pc.val with
      | .error _ => false
      | .ok i => i.code != 0x18) = true := by decide
  intro pc notFirst notSecond
  have same := ordinary_decode pc notFirst notSecond
  cases decoded : BPF.decode physical pc.val with
  | error error => simpa [decoded] using noWide pc
  | ok i => exact ⟨i, rfl, same.symm.trans decoded, by simpa [decoded] using noWide pc⟩

/-- Context conversion and every ordinary instruction agree with the full
physical artifact. This includes the real redirected EXIT and stub EXIT. -/
theorem ordinary_step (s : BPF.State) (pc : Fin 29)
    (position : s.pc = pc.val) (active : s.halted = false)
    (notFirst : pc.val ≠ 0) (notSecond : pc.val ≠ 2) :
    BPFPlatform.step environment SimpleChecked.program s = BPF.step externals physical s := by
  obtain ⟨i, physicalDecode, virtualDecode, notWide⟩ := ordinary_instruction pc notFirst notSecond
  have same := BPF.execute_program_congr_if_wide externals SimpleChecked.program physical s i
    (fun wide => False.elim (notWide wide))
  have nonnegative : ¬ (pc.val : Int) < 0 := by omega
  have first : (pc.val : Int) ≠ 0 := by omega
  have second : (pc.val : Int) ≠ 2 := by omega
  simpa [BPFPlatform.step, BPF.step, active, position, environment,
    first, second, nonnegative, virtualDecode, physicalDecode,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad] using same


theorem step_equal (s : BPF.State) (pc : Fin 29)
    (position : s.pc = pc.val) (active : s.halted = false) :
    BPFPlatform.step environment SimpleChecked.program s = BPF.step externals physical s := by
  by_cases first : pc.val = 0
  · exact first_step s (by omega) active
  · by_cases second : pc.val = 2
    · exact second_step s (by omega) active
    · exact ordinary_step s pc position active first second

/-- Successful physical steps necessarily lie in this exact artifact. No
caller-provided PC bounds or memory-safety premise is needed for transport. -/
theorem accepted_step (s : BPF.State) (result : Transition BPF.State)
    (accepted : BPF.step externals physical s = .ok result) :
    BPFPlatform.step environment SimpleChecked.program s = .ok result := by
  have active : s.halted = false := by
    cases h : s.halted <;> simp_all [BPF.step]
  have nonnegative : ¬ s.pc < 0 := by
    intro h
    simp [BPF.step, active, h] at accepted
  have inside : s.pc.toNat < 29 := by
    by_cases h : s.pc.toNat < 29
    · exact h
    have outside : 8 * s.pc.toNat + 8 > physical.size := by
      have extent : physical.size = 232 := rfl
      omega
    simp [BPF.step, active, nonnegative, BPF.decode, outside,
      Except.bind, Bind.bind, Except.instMonad] at accepted
  rw [step_equal s ⟨s.pc.toNat, inside⟩ (by change s.pc = (s.pc.toNat : Int); omega) active]
  exact accepted

def instructionStep : BlockStep BPF.State := fun before events after =>
  ∃ result, BPFPlatform.step environment SimpleChecked.program before = .ok result ∧
    result.events = events ∧ result.state = after

/-- A complete actual physical execution, including faults, transports to the
verifier-visible virtual stream with identical states and ordered events. -/
theorem execution_transport {s t : BPF.State} {events : List Event}
    (run : Execution (BPFPath.instructionStep externals physical) s events t) :
    Execution instructionStep s events t := by
  induction run with
  | refl => exact Execution.refl _
  | next head tail ih =>
    obtain ⟨result, accepted, trace, state⟩ := head
    exact Execution.next ⟨result, accepted_step _ _ accepted, trace, state⟩ ih

end KProgTV.SimpleCheckedPlatform
#print axioms KProgTV.SimpleCheckedPlatform.first_step

#print axioms KProgTV.SimpleCheckedPlatform.second_step

#print axioms KProgTV.SimpleCheckedPlatform.step_equal

#print axioms KProgTV.SimpleCheckedPlatform.execution_transport
