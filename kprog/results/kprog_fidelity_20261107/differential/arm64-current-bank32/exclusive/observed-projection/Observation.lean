import KProgFormal.Reference.AArch64

/- Observation of the existing CPU harness: all GPR/SP/flags/vectors/memory/PC,
plus canonical events and faults. Only unobserved reservation/environment fields
are erased. This is not an invocation/platform or ordering refinement. -/
namespace KProgFormal.Reference.AArch64.ExclusiveObservation
open KProgFormal.Reference

def visible (s : State) : State :=
  { s with exclusiveMonitor := none, exclusiveInputs := emptyExclusiveInputs }

def observation (t : Transition State) : Transition State :=
  { t with state := visible t.state }

/-- A load's visible transition is independent of every platform/environment
field, including the physical translation/reservation. API admissibility
(coverage of the reservation) is still separately required for wire inputs. -/
theorem load_independent (s : State) (a b : ExclusiveInputs)
    (w : Width) (acquire : Bool) (dst base : Register) :
    observation (exclusiveStep (.load w acquire dst base) { s with exclusiveInputs := a }) =
    observation (exclusiveStep (.load w acquire dst base) { s with exclusiveInputs := b }) := by
  have sa : spAlignmentFault { s with exclusiveInputs := a } base = spAlignmentFault s base := rfl
  have sb : spAlignmentFault { s with exclusiveInputs := b } base = spAlignmentFault s base := rfl
  have ba : memoryBase { s with exclusiveInputs := a } base = memoryBase s base := rfl
  have bb : memoryBase { s with exclusiveInputs := b } base = memoryBase s base := rfl
  cases hs : spAlignmentFault s base with
  | some f => simp only [exclusiveStep, sa, sb, hs]; rfl
  | none =>
    cases hn : exclusiveNaturalFault (memoryBase s base) w.bytes with
    | some f => simp only [exclusiveStep, sa, sb, ba, bb, hs, hn]; rfl
    | none =>
      cases hm : readMemory s.memory (memoryBase s base) w.bytes with
      | error f => simp only [exclusiveStep, sa, sb, ba, bb, hs, hn, hm]; rfl
      | ok value => simp only [exclusiveStep, sa, sb, ba, bb, hs, hn, hm]; rfl

/-- Empty initial monitor and mapped/aligned writable memory make the observed
failed-store transition independent of all environment choices. No address is
identified with a physical address, and neither successful stores nor a paired
attempt may use this theorem. -/
theorem empty_store_independent (s : State) (a b : ExclusiveInputs)
    (w : Width) (release : Bool) (status src base : Register)
    (hsp : spAlignmentFault s base = none)
    (halign : exclusiveNaturalFault (memoryBase s base) w.bytes = none)
    (hwrite : permitted s.memory.writable (memoryBase s base) w.bytes = true) :
    observation (exclusiveStep (.store w release status src base)
      { s with exclusiveMonitor := none, exclusiveInputs := a }) =
    observation (exclusiveStep (.store w release status src base)
      { s with exclusiveMonitor := none, exclusiveInputs := b }) := by
  have sa : spAlignmentFault { s with exclusiveMonitor := none, exclusiveInputs := a } base = none := hsp
  have sb : spAlignmentFault { s with exclusiveMonitor := none, exclusiveInputs := b } base = none := hsp
  have ba : memoryBase { s with exclusiveMonitor := none, exclusiveInputs := a } base = memoryBase s base := rfl
  have bb : memoryBase { s with exclusiveMonitor := none, exclusiveInputs := b } base = memoryBase s base := rfl
  simp [exclusiveStep, exclusiveMonitorPass, exclusiveStorePass,
    sa, sb, ba, bb, halign, hwrite, observation, visible, writeReg, exclusiveFailure]

def representative : ExclusiveInputs :=
  ⟨0, ⟨0, 8⟩, false, true, false, false, true⟩

theorem representative_admissible (w : Width) :
    exclusiveCovers representative.reservation representative.physicalAddress w.bytes = true ∧
    representative.reservation.bytes ≤ 2^64 := by
  cases w <;> decide

#print axioms representative_admissible

#print axioms load_independent
#print axioms empty_store_independent
end KProgFormal.Reference.AArch64.ExclusiveObservation
