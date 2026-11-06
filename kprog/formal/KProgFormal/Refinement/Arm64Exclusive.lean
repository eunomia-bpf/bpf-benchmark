import KProgFormal.Reference.AArch64

namespace KProgFormal.Refinement.Arm64Exclusive
open Reference
open Reference.AArch64

/-- No monitor can never be turned into a successful store by an external
choice. A platform witness cannot manufacture a local reservation. -/
theorem empty_monitor_fails (s : State) (bytes : Nat)
    (h : s.exclusiveMonitor = none) : exclusiveStorePass s bytes = false := by
  simp [exclusiveStorePass, exclusiveMonitorPass, h]

theorem interference_fails (s : State) (bytes : Nat)
    (h : s.exclusiveInputs.retainLocal = false) : exclusiveStorePass s bytes = false := by
  simp [exclusiveStorePass, exclusiveMonitorPass, h]

/-- A matching load is insufficient when the global monitor or atomic commit
fails; the failure branch remains architectural, not an omitted path. -/
theorem global_failure (s : State) (bytes : Nat)
    (h : s.exclusiveInputs.globalPass = false) : exclusiveStorePass s bytes = false := by
  simp [exclusiveStorePass, exclusiveMonitorPass, h]

theorem commit_failure (s : State) (bytes : Nat)
    (h : s.exclusiveInputs.commitPass = false) : exclusiveStorePass s bytes = false := by
  simp [exclusiveStorePass, h]

theorem clear_step (s : State) :
    step (.exclusive .clear) s =
      ⟨{ s with exclusiveMonitor := none, pc := s.pc + 4 },
        [.exclusive .clear 0 0 false false true], none⟩ := rfl

/-- An unsuccessful monitor check with fault-before-check disabled cannot
write any byte or change NZCV, vector, SP, or any register except status. -/
theorem failed_store (s : State) (width : Width) (release : Bool) (status src base : Register)
    (hm : exclusiveMonitorPass s width.bytes = false)
    (ha : s.exclusiveInputs.abortOnFailure = false)
    (hsp : spAlignmentFault s base = none) :
    exclusiveStep (.store width release status src base) s =
      ⟨{ writeReg (if !s.exclusiveInputs.retainLocal || s.exclusiveInputs.virtualPass then
              { s with exclusiveMonitor := none } else s) status 1 with pc := s.pc + 4 },
        [.exclusive .attempt (memoryBase s base) width.bytes false release false], none⟩ := by
  simp [exclusiveStep, exclusiveStorePass, hm, ha, hsp]

/-- Different virtual addresses can share a physical reservation; the
monitor is checked in physical coordinates supplied by address translation. -/
theorem physical_alias_pass (s : State) (bytes : Nat) (monitor : ExclusiveMonitor)
    (hm : s.exclusiveMonitor = some monitor)
    (hr : s.exclusiveInputs.retainLocal = true)
    (hv : s.exclusiveInputs.virtualPass = true)
    (hg : s.exclusiveInputs.globalPass = true)
    (hc : s.exclusiveInputs.commitPass = true)
    (covers : exclusiveCovers monitor s.exclusiveInputs.physicalAddress bytes = true) :
    exclusiveStorePass s bytes = true := by
  simp [exclusiveStorePass, exclusiveMonitorPass, hm, hr, hv, hg, hc, covers]

end KProgFormal.Refinement.Arm64Exclusive
