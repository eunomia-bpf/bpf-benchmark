import KProgFormal.Refinement.Arm64Memory
import KProgFormal.Refinement.Arm64Arithmetic
import KProgFormal.Generated.GeneratedArm64Stlxr

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

/-- The exclusive C arms use native W/X memory widths, never a byte ladder. -/
def accessWidth : Width → MemoryWidth
  | .w32 => .word | .w64 => .double

theorem access_width_refines (width : Width) : (accessWidth width).bytes = width.bytes := by
  cases width <;> rfl

/-- A monitor annotation belongs to the environment relation. The C simulator
has no local monitor cell; a certificate must justify this ghost state and the
acquire/release event, including atomicity and order on the target platform. -/
def checkedState (s : State) : State :=
  if !s.exclusiveInputs.retainLocal || s.exclusiveInputs.virtualPass then
    { s with exclusiveMonitor := none } else s

/-- LDAXR's generated load and GPR write, with the reservation annotation
supplied by the same explicit environment as the canonical step. -/
def loadCore (width : Width) (acquire : Bool) (dst base : Register) (s : State) :
    Transition State :=
  let address := Arm64Memory.baseValue s base
  match Arm64Memory.read (accessWidth width) s.memory address with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, event) =>
      ⟨{ Arm64Register.writeReg s dst value width with
          exclusiveMonitor := some s.exclusiveInputs.reservation, pc := s.pc + 4 },
       [event, .exclusive .reserve address width.bytes acquire false true], none⟩

theorem load_core_refines (width : Width) (acquire : Bool) (dst base : Register)
    (s : State) (spAligned : spAlignmentFault s base = none)
    (aligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none) :
    loadCore width acquire dst base s = step (.exclusive (.load width acquire dst base)) s := by
  simp only [loadCore, step, exclusiveStep, Arm64Memory.base_refines,
    Arm64Memory.read_refines, access_width_refines, spAligned, aligned]
  cases readMemory s.memory (memoryBase s base) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨value, event⟩
      simp only [Arm64Register.write_refines]

theorem status_value_refines (failure : Bool) :
    narrow (GeneratedArm64Stlxr.value .stlxr .w32 failure) .w32 =
      (if failure then 1 else 0) := by
  cases failure <;> decide

/-- STLXR tests the explicit outcome before accessing memory, then writes a
W status. The source is captured before the status write, including aliases.
Monitor and exclusive-event fields are ghost annotations, not extra C guards. -/
def storeCore (width : Width) (release failure : Bool) (status src base : Register)
    (s : State) : Transition State :=
  let address := Arm64Memory.baseValue s base
  let checked := checkedState s
  let stored := if failure then checked else
    { checked with memory := Arm64Memory.store (accessWidth width) s.memory address (Arm64Register.readReg s src) }
  let result := Arm64Register.writeReg stored status
    (GeneratedArm64Stlxr.value .stlxr .w32 failure) .w32
  ⟨{ result with pc := s.pc + 4 },
   [.exclusive .attempt address width.bytes false release (!failure)] ++
     (if failure then [] else
       [.memory .write address (valueBytes (Arm64Register.readReg s src) width.bytes) true]), none⟩

/-- The environment outcome must match the canonical monitor AND commit
result. Failure is included, not replaced with a chosen successful execution.
If the architecture checks memory on failure, that preflight must also pass;
when it does not check, inaccessible memory remains a permitted failure input. -/
theorem store_core_refines (width : Width) (release failure : Bool)
    (status src base : Register) (s : State)
    (outcome : failure = !exclusiveStorePass s width.bytes)
    (spAligned : spAlignmentFault s base = none)
    (aligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none)
    (preflight : (exclusiveMonitorPass s width.bytes || s.exclusiveInputs.abortOnFailure) = true →
      permitted s.memory.writable (memoryBase s base) width.bytes = true) :
    storeCore width release failure status src base s =
      step (.exclusive (.store width release status src base)) s := by
  subst failure
  simp only [storeCore, step, exclusiveStep, Arm64Memory.base_refines,
    Arm64Memory.store_refines, access_width_refines, Arm64Register.read_refines,
    Arm64Register.write_refines, status_value_refines, checkedState, spAligned]
  by_cases monitor : exclusiveMonitorPass s width.bytes = true
  · have writable := preflight (by simp [monitor])
    simp only [monitor, Bool.true_or, ↓reduceIte, aligned, Option.isSome_none,
      Bool.false_eq_true, writable, Bool.not_true, Bool.true_and]
    cases commit : s.exclusiveInputs.commitPass <;>
      simp [exclusiveStorePass, monitor, commit]
  · have monitorFalse : exclusiveMonitorPass s width.bytes = false := by
      cases h : exclusiveMonitorPass s width.bytes <;> simp_all
    have failed : exclusiveStorePass s width.bytes = false := by
      simp [exclusiveStorePass, monitorFalse]
    by_cases abort : s.exclusiveInputs.abortOnFailure = true
    · have writable := preflight (by simp [abort])
      simp [monitorFalse, failed, abort, aligned, writable]
    · have abortFalse : s.exclusiveInputs.abortOnFailure = false := by
        cases h : s.exclusiveInputs.abortOnFailure <;> simp_all
      simp [monitorFalse, failed, abortFalse]

/-- A real W status receives the exact outcome of the existing exclusive store
body for every incoming state and native data width. -/
theorem retry_status_refines (width : Width) (release failure : Bool)
    (status : Gpr) (src base : Register) (s : State) :
    readReg (storeCore width release failure status.castSucc src base s).state
      status.castSucc = (if failure then 1 else 0) := by
  cases failure <;>
    simp [storeCore, Arm64Register.write_refines, readReg, writeReg,
      status_value_refines, status.isLt]

/-- The canonical store and its actual W-status branch retain ordered effects
and any store fault. Displacement is a native branch operand. -/
def retrySuffix (width : Width) (release : Bool) (status : Gpr)
    (src base : Register) (displacement : Word) (s : State) : Transition State :=
  let attempt := step (.exclusive (.store width release status.castSucc src base)) s
  match attempt.fault with
  | some _ => attempt
  | none =>
      let branch := step (.branchZero .w32 true status.castSucc displacement) attempt.state
      ⟨branch.state, attempt.events ++ branch.events, branch.fault⟩

/-- The branch takes the supplied retry displacement exactly on the fresh
failure outcome. Success takes the architectural fallthrough; all other state
and exclusive/store events come from the existing canonical refinement. -/
theorem retry_suffix_refines (width : Width) (release failure : Bool)
    (status : Gpr) (src base : Register) (displacement : Word) (s : State)
    (outcome : failure = !exclusiveStorePass s width.bytes)
    (spAligned : spAlignmentFault s base = none)
    (aligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none)
    (preflight : (exclusiveMonitorPass s width.bytes || s.exclusiveInputs.abortOnFailure) = true →
      permitted s.memory.writable (memoryBase s base) width.bytes = true) :
    retrySuffix width release status src base displacement s =
      ⟨{ (storeCore width release failure status.castSucc src base s).state with
          pc := s.pc + 4 + (if failure then displacement else 4) },
        (storeCore width release failure status.castSucc src base s).events, none⟩ := by
  have refined := store_core_refines width release failure status.castSucc src base s
    outcome spAligned aligned preflight
  have statusValue := retry_status_refines width release failure status src base s
  unfold retrySuffix
  rw [← refined]
  have faultNone : (storeCore width release failure status.castSucc src base s).fault = none := rfl
  simp only [faultNone]
  simp only [step, branchStep, statusValue, zeroBranch, List.append_nil]
  cases failure <;> simp [storeCore, narrow, Width.bits]

/-- Any canonical store fault ends the suffix with the complete original fault
transition, retaining its state and events. -/
theorem retry_suffix_fault (width : Width) (release : Bool) (status : Gpr)
    (src base : Register) (displacement : Word) (s : State) (fault : Fault)
    (failed : (step (.exclusive (.store width release status.castSucc src base)) s).fault = some fault) :
    retrySuffix width release status src base displacement s =
      step (.exclusive (.store width release status.castSucc src base)) s := by
  simp [retrySuffix, failed]

/-- Sequential native steps stop at the first fault and retain ordered effects. -/
def continueWith (first : Transition State) (next : State → Transition State) : Transition State :=
  match first.fault with
  | some _ => first
  | none =>
      let second := next first.state
      ⟨second.state, first.events ++ second.events, second.fault⟩

/-- The canonical exclusive load and non-flag ADD prefix. -/
def retryPrefix (width : Width) (acquire : Bool) (value : Gpr) (base : Register)
    (increment : Word) (s : State) : Transition State :=
  continueWith (step (.exclusive (.load width acquire value.castSucc base)) s)
    (step (.arithmeticImmediate width false false (.general value) (.general value) increment))

/-- Existing C load and generated immediate/ALU bodies, with their original state domains. -/
def retryPrefixCore (width : Width) (acquire sourceScalar sourceStack : Bool)
    (value : Gpr) (base : Register) (increment : Word) (s : State) : Transition State :=
  continueWith (loadCore width acquire value.castSucc base s)
    (Arm64Arithmetic.AluDispatch.rawStep false true sourceScalar sourceStack
      (Arm64Arithmetic.AluDispatch.immediateAux false 0 0 0) width
      (.general value) (.general value) value.castSucc increment)

theorem retry_prefix_refines (width : Width) (acquire sourceScalar sourceStack : Bool)
    (value : Gpr) (base : Register) (increment : Word) (s : State)
    (spAligned : spAlignmentFault s base = none)
    (aligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none) :
    retryPrefixCore width acquire sourceScalar sourceStack value base increment s =
      retryPrefix width acquire value base increment s := by
  unfold retryPrefixCore retryPrefix
  rw [load_core_refines width acquire value.castSucc base s spAligned aligned]
  congr 1
  funext loaded
  simpa only [step, if_true] using
    Arm64Arithmetic.AluDispatch.raw_step_refines false true sourceScalar sourceStack
      (Arm64Arithmetic.AluDispatch.immediateAux false 0 0 0) width
      (.general value) (.general value) value.castSucc increment loaded

/-- The C exclusive-store body followed by its canonical status branch. -/
def retrySuffixCore (width : Width) (release failure : Bool) (status : Gpr)
    (src base : Register) (displacement : Word) (s : State) : Transition State :=
  continueWith (storeCore width release failure status.castSucc src base s)
    (step (.branchZero .w32 true status.castSucc displacement))

theorem retry_suffix_core_refines (width : Width) (release failure : Bool)
    (status : Gpr) (src base : Register) (displacement : Word) (s : State)
    (outcome : failure = !exclusiveStorePass s width.bytes)
    (spAligned : spAlignmentFault s base = none)
    (aligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none)
    (preflight : (exclusiveMonitorPass s width.bytes || s.exclusiveInputs.abortOnFailure) = true →
      permitted s.memory.writable (memoryBase s base) width.bytes = true) :
    retrySuffixCore width release failure status src base displacement s =
      retrySuffix width release status src base displacement s := by
  unfold retrySuffixCore
  rw [store_core_refines width release failure status.castSucc src base s
    outcome spAligned aligned preflight]
  rfl

/-- One complete native load/ADD/store/status-branch iteration. -/
def retryCycle (width : Width) (acquire release : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word) (s : State) : Transition State :=
  continueWith (retryPrefix width acquire value base increment s)
    (retrySuffix width release status value.castSucc base displacement)

def retryCycleCore (width : Width) (acquire release failure sourceScalar sourceStack : Bool)
    (status value : Gpr) (base : Register) (increment displacement : Word)
    (s : State) : Transition State :=
  continueWith (retryPrefixCore width acquire sourceScalar sourceStack value base increment s)
    (retrySuffixCore width release failure status value.castSucc base displacement)

/-- Both store outcomes compose with the load/add prefix and preserve the complete transition. -/
theorem retry_cycle_refines (width : Width) (acquire release failure sourceScalar sourceStack : Bool)
    (status value : Gpr) (base : Register) (increment displacement : Word) (s : State)
    (loadSp : spAlignmentFault s base = none)
    (loadAligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none)
    (outcome : failure = !exclusiveStorePass
      (retryPrefix width acquire value base increment s).state width.bytes)
    (storeSp : spAlignmentFault (retryPrefix width acquire value base increment s).state base = none)
    (storeAligned : exclusiveNaturalFault
      (memoryBase (retryPrefix width acquire value base increment s).state base) width.bytes = none)
    (preflight : (exclusiveMonitorPass (retryPrefix width acquire value base increment s).state width.bytes ||
      (retryPrefix width acquire value base increment s).state.exclusiveInputs.abortOnFailure) = true →
      permitted (retryPrefix width acquire value base increment s).state.memory.writable
        (memoryBase (retryPrefix width acquire value base increment s).state base) width.bytes = true) :
    retryCycleCore width acquire release failure sourceScalar sourceStack status value base increment displacement s =
      retryCycle width acquire release status value base increment displacement s := by
  unfold retryCycleCore retryCycle
  rw [retry_prefix_refines width acquire sourceScalar sourceStack value base increment s loadSp loadAligned]
  have suffix := retry_suffix_core_refines width release failure status value.castSucc base displacement
    (retryPrefix width acquire value base increment s).state outcome storeSp storeAligned preflight
  cases h : (retryPrefix width acquire value base increment s).fault with
  | none => simp only [continueWith, h, suffix]
  | some fault => simp only [continueWith, h]

/-- Prefix faults end the complete iteration with the original state and ordered events. -/
theorem retry_cycle_prefix_fault (width : Width) (acquire release : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word) (s : State) (fault : Fault)
    (failed : (retryPrefix width acquire value base increment s).fault = some fault) :
    retryCycle width acquire release status value base increment displacement s =
      retryPrefix width acquire value base increment s := by
  simp only [retryCycle, continueWith, failed]

/-- A failed C-model iteration preserves the complete architectural frame
outside its data/status registers, reservation and program counter. The cycle
refinement transfers this equality to the canonical ISA under its premises. -/
theorem retry_cycle_failed_frame (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word) (s : State) :
    let result := retryCycleCore width acquire release true sourceScalar sourceStack
      status value base increment displacement s
    result.state = { s with gpr := result.state.gpr, exclusiveMonitor := result.state.exclusiveMonitor, pc := result.state.pc } := by
  dsimp only
  unfold retryCycleCore retryPrefixCore
  unfold loadCore
  cases loaded : Arm64Memory.read (accessWidth width) s.memory
      (Arm64Memory.baseValue s base) with
  | error fault => simp [loaded, continueWith]
  | ok pair =>
      rcases pair with ⟨word, event⟩
      by_cases monitor : (!s.exclusiveInputs.retainLocal || s.exclusiveInputs.virtualPass) = true
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines, retrySuffixCore, storeCore, checkedState,
          Arm64Register.write_refines, arithmeticImmediateStep, writeData,
          step, branchStep, monitor, writeReg]
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines, retrySuffixCore, storeCore, checkedState,
          Arm64Register.write_refines, arithmeticImmediateStep, writeData,
          step, branchStep, monitor, writeReg]

/-- Only the native data/status registers participate in a failed iteration's
GPR updates, including aliases between those two registers. -/
theorem retry_cycle_failed_other_gpr (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value other : Gpr)
    (base : Register) (increment displacement : Word) (s : State)
    (outsideValue : other.val ≠ value.val) (outsideStatus : other.val ≠ status.val) :
    (retryCycleCore width acquire release true sourceScalar sourceStack
      status value base increment displacement s).state.gpr other = s.gpr other := by
  unfold retryCycleCore retryPrefixCore
  unfold loadCore
  cases loaded : Arm64Memory.read (accessWidth width) s.memory
      (Arm64Memory.baseValue s base) with
  | error fault => simp [loaded, continueWith]
  | ok pair =>
      rcases pair with ⟨word, event⟩
      by_cases monitor : (!s.exclusiveInputs.retainLocal || s.exclusiveInputs.virtualPass) = true
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines, retrySuffixCore, storeCore, checkedState,
          Arm64Register.write_refines, arithmeticImmediateStep, writeData,
          step, branchStep, monitor, writeReg, outsideValue, outsideStatus]
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines, retrySuffixCore, storeCore, checkedState,
          Arm64Register.write_refines, arithmeticImmediateStep, writeData,
          step, branchStep, monitor, writeReg, outsideValue, outsideStatus]

/-- A retry base distinct from data/status retains its complete address,
including an SP base and every ordinary GPR base. -/
theorem retry_cycle_failed_base (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word) (s : State)
    (outsideValue : base.val ≠ value.val) (outsideStatus : base.val ≠ status.val) :
    memoryBase (retryCycleCore width acquire release true sourceScalar sourceStack
      status value base increment displacement s).state base = memoryBase s base := by
  by_cases general : base.val < 31
  · simpa only [memoryBase, general, ↓reduceDIte] using
      retry_cycle_failed_other_gpr width acquire release sourceScalar sourceStack
        status value ⟨base.val, general⟩ base increment displacement s outsideValue outsideStatus
  · have preserved := congrArg State.sp
      (retry_cycle_failed_frame width acquire release sourceScalar sourceStack
        status value base increment displacement s)
    simpa only [memoryBase, general, ↓reduceDIte] using preserved

end KProgFormal.Refinement.Arm64Exclusive
