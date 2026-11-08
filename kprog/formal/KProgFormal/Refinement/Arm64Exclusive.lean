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

/-- A sequence of dynamic exclusive visits, preserving every read/attempt event
and ending at the first architectural fault. The list describes an observed
finite prefix; each visit carries its own platform inputs. -/
def retryFailurePrefix (cycle : State → Transition State) :
    List ExclusiveInputs → State → Transition State
  | [], s => ⟨s, [], none⟩
  | input :: rest, s =>
      continueWith (cycle { s with exclusiveInputs := input })
        (retryFailurePrefix cycle rest)

/-- Architectural frame shared by all failed visits. Environment inputs,
reservation, data/status GPRs and PC retain their explicit threaded values. -/
def RetryFrame (initial final : State) : Prop :=
  final = { initial with gpr := final.gpr, pc := final.pc, exclusiveMonitor := final.exclusiveMonitor, exclusiveInputs := final.exclusiveInputs }

theorem retry_frame_trans (s t u : State) (first : RetryFrame s t)
    (second : RetryFrame t u) : RetryFrame s u := by
  unfold RetryFrame at *
  rw [first] at second
  exact second

/-- Every finite failed prefix preserves memory, flags, vector bank, SP,
alignment profile and thread-pointer inputs, across arbitrary dynamic inputs. -/
theorem retry_failure_prefix_frame (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word)
    (inputs : List ExclusiveInputs) (s : State) :
    RetryFrame s (retryFailurePrefix
      (retryCycleCore width acquire release true sourceScalar sourceStack
        status value base increment displacement) inputs s).state := by
  induction inputs generalizing s with
  | nil => rfl
  | cons input rest ih =>
      let start := { s with exclusiveInputs := input }
      let first := retryCycleCore width acquire release true sourceScalar sourceStack
        status value base increment displacement start
      have one : RetryFrame start first.state := by
        unfold RetryFrame
        rw [retry_cycle_failed_frame width acquire release sourceScalar sourceStack
          status value base increment displacement start]
      have entry : RetryFrame s start := rfl
      have framed := retry_frame_trans s start first.state entry one
      change RetryFrame s (continueWith first _).state
      cases h : first.fault with
      | some fault => simpa only [continueWith, h] using framed
      | none =>
          simpa only [continueWith, h] using
            retry_frame_trans s first.state _ framed (ih first.state)

/-- Data/status are the complete GPR write set for every failed prefix. -/
theorem retry_failure_prefix_other_gpr (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value other : Gpr)
    (base : Register) (increment displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (outsideValue : other.val ≠ value.val) (outsideStatus : other.val ≠ status.val) :
    (retryFailurePrefix (retryCycleCore width acquire release true sourceScalar sourceStack
      status value base increment displacement) inputs s).state.gpr other = s.gpr other := by
  induction inputs generalizing s with
  | nil => rfl
  | cons input rest ih =>
      let start := { s with exclusiveInputs := input }
      let first := retryCycleCore width acquire release true sourceScalar sourceStack
        status value base increment displacement start
      have one : first.state.gpr other = s.gpr other :=
        retry_cycle_failed_other_gpr width acquire release sourceScalar sourceStack
          status value other base increment displacement start outsideValue outsideStatus
      change (continueWith first _).state.gpr other = s.gpr other
      cases h : first.fault with
      | some fault => simpa only [continueWith, h] using one
      | none => simpa only [continueWith, h] using (ih first.state).trans one

/-- Every disjoint ordinary/SP retry base retains its complete address. -/
theorem retry_failure_prefix_base (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (outsideValue : base.val ≠ value.val) (outsideStatus : base.val ≠ status.val) :
    memoryBase (retryFailurePrefix
      (retryCycleCore width acquire release true sourceScalar sourceStack
        status value base increment displacement) inputs s).state base = memoryBase s base := by
  by_cases general : base.val < 31
  · simpa only [memoryBase, general, ↓reduceDIte] using
      retry_failure_prefix_other_gpr width acquire release sourceScalar sourceStack
        status value ⟨base.val, general⟩ base increment displacement inputs s
        outsideValue outsideStatus
  · have frame := retry_failure_prefix_frame width acquire release sourceScalar sourceStack
      status value base increment displacement inputs s
    have sp := congrArg State.sp frame
    simpa only [memoryBase, general, ↓reduceDIte] using sp

/-- Exact existing canonical platform/memory premises for a failed visit. -/
structure RetryFailureDomain (width : Width) (acquire : Bool) (value : Gpr)
    (base : Register) (increment : Word) (s : State) : Prop where
  loadSp : spAlignmentFault s base = none
  loadAligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none
  failed : exclusiveStorePass (retryPrefix width acquire value base increment s).state
    width.bytes = false
  storeSp : spAlignmentFault (retryPrefix width acquire value base increment s).state base = none
  storeAligned : exclusiveNaturalFault
    (memoryBase (retryPrefix width acquire value base increment s).state base) width.bytes = none
  preflight :
    (exclusiveMonitorPass (retryPrefix width acquire value base increment s).state width.bytes ||
      (retryPrefix width acquire value base increment s).state.exclusiveInputs.abortOnFailure) = true →
    permitted (retryPrefix width acquire value base increment s).state.memory.writable
      (memoryBase (retryPrefix width acquire value base increment s).state base) width.bytes = true

/-- Per-visit premises follow the actual canonical path and its first fault. -/
def RetryFailurePrefixDomain (width : Width) (acquire release : Bool)
    (status value : Gpr) (base : Register) (increment displacement : Word) :
    List ExclusiveInputs → State → Prop
  | [], _ => True
  | input :: rest, s =>
      let start := { s with exclusiveInputs := input }
      let first := retryCycle width acquire release status value base increment displacement start
      RetryFailureDomain width acquire value base increment start ∧
        (first.fault = none → RetryFailurePrefixDomain width acquire release
          status value base increment displacement rest first.state)

/-- Every observed finite prefix has the exact canonical state, ordered events
and first fault, with independently supplied dynamic exclusive outcomes. -/
theorem retry_failure_prefix_refines (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (admitted : RetryFailurePrefixDomain width acquire release status value
      base increment displacement inputs s) :
    retryFailurePrefix (retryCycleCore width acquire release true sourceScalar sourceStack
      status value base increment displacement) inputs s =
    retryFailurePrefix (retryCycle width acquire release
      status value base increment displacement) inputs s := by
  induction inputs generalizing s with
  | nil => rfl
  | cons input rest ih =>
      let start := { s with exclusiveInputs := input }
      let first := retryCycle width acquire release status value base increment displacement start
      change RetryFailureDomain width acquire value base increment start ∧
        (first.fault = none → RetryFailurePrefixDomain width acquire release
          status value base increment displacement rest first.state) at admitted
      have one := retry_cycle_refines width acquire release true sourceScalar sourceStack
        status value base increment displacement start admitted.1.loadSp admitted.1.loadAligned
        (by simp only [admitted.1.failed]; rfl) admitted.1.storeSp
        admitted.1.storeAligned admitted.1.preflight
      change continueWith (retryCycleCore width acquire release true sourceScalar sourceStack
        status value base increment displacement start) _ = continueWith first _
      rw [one]
      change continueWith first _ = continueWith first _
      cases h : first.fault with
      | some fault => simp only [continueWith, h]
      | none =>
          simp only [continueWith, h]
          rw [ih first.state (admitted.2 h)]

/-- The canonical failed prefix inherits the complete architectural frame. -/
theorem retry_failure_prefix_canonical_frame (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (admitted : RetryFailurePrefixDomain width acquire release status value
      base increment displacement inputs s) :
    RetryFrame s (retryFailurePrefix (retryCycle width acquire release
      status value base increment displacement) inputs s).state := by
  rw [← retry_failure_prefix_refines width acquire release sourceScalar sourceStack
    status value base increment displacement inputs s admitted]
  exact retry_failure_prefix_frame width acquire release sourceScalar sourceStack
    status value base increment displacement inputs s

/-- The original first-fault transition contains the complete prefix effects. -/
theorem retry_failure_prefix_fault (cycle : State → Transition State)
    (input : ExclusiveInputs) (rest : List ExclusiveInputs) (s : State) (fault : Fault)
    (failed : (cycle { s with exclusiveInputs := input }).fault = some fault) :
    retryFailurePrefix cycle (input :: rest) s = cycle { s with exclusiveInputs := input } := by
  simp only [retryFailurePrefix, continueWith, failed]

/-- The real W-status branch selects the incoming native displacement on
failure and advances by one instruction on success. -/
theorem retry_suffix_core_pc (width : Width) (release failure : Bool)
    (status : Gpr) (src base : Register) (displacement : Word) (s : State) :
    (retrySuffixCore width release failure status src base displacement s).state.pc =
      s.pc + 4 + (if failure then displacement else 4) := by
  have statusValue := retry_status_refines width release failure status src base s
  have faultNone : (storeCore width release failure status.castSucc src base s).fault = none := rfl
  unfold retrySuffixCore
  simp only [continueWith, faultNone, step, branchStep, statusValue, zeroBranch]
  cases failure <;> simp [storeCore, narrow, Width.bits]

/-- A successful load and the actual non-flag ADD advance by two instructions. -/
theorem retry_prefix_core_pc (width : Width) (acquire sourceScalar sourceStack : Bool)
    (value : Gpr) (base : Register) (increment : Word) (s : State)
    (loadedValue : Word) (event : Event)
    (loaded : Arm64Memory.read (accessWidth width) s.memory
      (Arm64Memory.baseValue s base) = .ok (loadedValue, event)) :
    (retryPrefixCore width acquire sourceScalar sourceStack value base increment s).fault = none ∧
      (retryPrefixCore width acquire sourceScalar sourceStack value base increment s).state.pc =
        s.pc + 4 + 4 := by
  simp [retryPrefixCore, loadCore, loaded, continueWith,
    Arm64Arithmetic.AluDispatch.raw_step_refines, arithmeticImmediateStep, writeData,
    Arm64Register.write_refines]

/-- The encoded four-instruction retry displacement returns a failed visit
to its exact original PC, including64-bit wrapping addresses. -/
theorem retry_cycle_failed_backedge (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment : Word) (s : State)
    (loadedValue : Word) (event : Event)
    (loaded : Arm64Memory.read (accessWidth width) s.memory
      (Arm64Memory.baseValue s base) = .ok (loadedValue, event)) :
    (retryCycleCore width acquire release true sourceScalar sourceStack status value
      base increment (0xfffffffffffffff4 : Word) s).state.pc = s.pc := by
  have prefixFacts := retry_prefix_core_pc width acquire sourceScalar sourceStack
    value base increment s loadedValue event loaded
  unfold retryCycleCore
  simp only [continueWith, prefixFacts.1]
  rw [retry_suffix_core_pc, prefixFacts.2]
  simp only [if_true]
  cases width <;> bv_decide

/-- Existing per-visit platform witnesses transfer the exact backedge PC
equality to the canonical load/ADD/store/W-status branch sequence. -/
theorem retry_cycle_canonical_failed_backedge (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base : Register) (increment : Word) (s : State)
    (loadedValue : Word) (event : Event)
    (loaded : Arm64Memory.read (accessWidth width) s.memory
      (Arm64Memory.baseValue s base) = .ok (loadedValue, event))
    (admitted : RetryFailureDomain width acquire value base increment s) :
    (retryCycle width acquire release status value base increment
      (0xfffffffffffffff4 : Word) s).state.pc = s.pc := by
  have refined := retry_cycle_refines width acquire release true sourceScalar sourceStack
    status value base increment (0xfffffffffffffff4 : Word) s
    admitted.loadSp admitted.loadAligned (by simp only [admitted.failed]; rfl)
    admitted.storeSp admitted.storeAligned admitted.preflight
  rw [← refined]
  exact retry_cycle_failed_backedge width acquire release sourceScalar sourceStack
    status value base increment s loadedValue event loaded

/-- Exclusive load followed by the actual non-flag register ADD, retaining
its encoded source register, shift kind and width-specific shift amount. -/
def retryRegisterPrefix (width : Width) (acquire : Bool) (value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : State) : Transition State :=
  continueWith (step (.exclusive (.load width acquire value.castSucc base)) s)
    (step (.arithmeticRegister width false false (.general value) (.general value) rhs kind amount))

def retryRegisterPrefixCore (width : Width) (acquire sourceScalar sourceStack : Bool)
    (value : Gpr) (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : State) : Transition State :=
  continueWith (loadCore width acquire value.castSucc base s)
    (Arm64Arithmetic.AluDispatch.rawStep false false sourceScalar sourceStack
      (Arm64Arithmetic.AluDispatch.packedAux false
        (Arm64Arithmetic.registerModifier width kind amount)
        (BitVec.ofNat 8 amount.val) 0) width (.general value) (.general value) rhs 0)

theorem retry_register_prefix_refines (width : Width)
    (acquire sourceScalar sourceStack : Bool) (value : Gpr) (base rhs : Register)
    (kind : Fin 3) (amount : Fin width.bits) (s : State)
    (spAligned : spAlignmentFault s base = none)
    (aligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none) :
    retryRegisterPrefixCore width acquire sourceScalar sourceStack value base rhs kind amount s =
      retryRegisterPrefix width acquire value base rhs kind amount s := by
  unfold retryRegisterPrefixCore retryRegisterPrefix
  rw [load_core_refines width acquire value.castSucc base s spAligned aligned]
  congr 1
  funext loaded
  have arithmetic := Arm64Arithmetic.AluDispatch.dispatch_register_refines false
    sourceScalar sourceStack width (.general value) (.general value) rhs kind amount 0 0 loaded
  simp only [Arm64Arithmetic.AluDispatch.dispatch, Arm64Arithmetic.AluDispatch.decode_code,
    Arm64Arithmetic.AluDispatch.packed_operation, Arm64Arithmetic.AluDispatch.decode_arithmetic] at arithmetic
  change some (Arm64Arithmetic.AluDispatch.rawStep false false sourceScalar sourceStack
    (Arm64Arithmetic.AluDispatch.packedAux false
      (Arm64Arithmetic.registerModifier width kind amount)
      (BitVec.ofNat 8 amount.val) 0) width (.general value) (.general value) rhs 0 loaded) = _ at arithmetic
  exact Option.some.inj arithmetic

/-- Complete register-ADD retry visit with the same canonical store/status branch. -/
def retryRegisterCycle (width : Width) (acquire release : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word) (s : State) : Transition State :=
  continueWith (retryRegisterPrefix width acquire value base rhs kind amount s)
    (retrySuffix width release status value.castSucc base displacement)

def retryRegisterCycleCore (width : Width)
    (acquire release failure sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word) (s : State) : Transition State :=
  continueWith (retryRegisterPrefixCore width acquire sourceScalar sourceStack
    value base rhs kind amount s)
    (retrySuffixCore width release failure status value.castSucc base displacement)

theorem retry_register_cycle_refines (width : Width)
    (acquire release failure sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word) (s : State)
    (loadSp : spAlignmentFault s base = none)
    (loadAligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none)
    (outcome : failure = !exclusiveStorePass
      (retryRegisterPrefix width acquire value base rhs kind amount s).state width.bytes)
    (storeSp : spAlignmentFault
      (retryRegisterPrefix width acquire value base rhs kind amount s).state base = none)
    (storeAligned : exclusiveNaturalFault
      (memoryBase (retryRegisterPrefix width acquire value base rhs kind amount s).state base)
      width.bytes = none)
    (preflight :
      (exclusiveMonitorPass (retryRegisterPrefix width acquire value base rhs kind amount s).state width.bytes ||
        (retryRegisterPrefix width acquire value base rhs kind amount s).state.exclusiveInputs.abortOnFailure) = true →
      permitted (retryRegisterPrefix width acquire value base rhs kind amount s).state.memory.writable
        (memoryBase (retryRegisterPrefix width acquire value base rhs kind amount s).state base)
        width.bytes = true) :
    retryRegisterCycleCore width acquire release failure sourceScalar sourceStack
      status value base rhs kind amount displacement s =
    retryRegisterCycle width acquire release status value base rhs kind amount displacement s := by
  unfold retryRegisterCycleCore retryRegisterCycle
  rw [retry_register_prefix_refines width acquire sourceScalar sourceStack value base rhs kind amount s
    loadSp loadAligned]
  have suffix := retry_suffix_core_refines width release failure status value.castSucc base displacement
    (retryRegisterPrefix width acquire value base rhs kind amount s).state outcome storeSp storeAligned preflight
  cases h : (retryRegisterPrefix width acquire value base rhs kind amount s).fault with
  | none => simp only [continueWith, h, suffix]
  | some fault => simp only [continueWith, h]

/-- Failed register-ADD visits preserve the complete architecture outside
their value/status GPRs, reservation and PC, including arbitrary operand aliases. -/
theorem retry_register_cycle_failed_frame (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word) (s : State) :
    let result := retryRegisterCycleCore width acquire release true sourceScalar sourceStack
      status value base rhs kind amount displacement s
    result.state = { s with gpr := result.state.gpr, exclusiveMonitor := result.state.exclusiveMonitor, pc := result.state.pc } := by
  dsimp only
  unfold retryRegisterCycleCore retryRegisterPrefixCore loadCore
  cases loaded : Arm64Memory.read (accessWidth width) s.memory (Arm64Memory.baseValue s base) with
  | error fault => simp [loaded, continueWith]
  | ok pair =>
      rcases pair with ⟨word, event⟩
      by_cases monitor : (!s.exclusiveInputs.retainLocal || s.exclusiveInputs.virtualPass) = true
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines,
          retrySuffixCore, storeCore, checkedState, Arm64Register.write_refines,
          arithmeticImmediateStep, writeData, step, branchStep, monitor, writeReg]
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines,
          retrySuffixCore, storeCore, checkedState, Arm64Register.write_refines,
          arithmeticImmediateStep, writeData, step, branchStep, monitor, writeReg]

theorem retry_register_cycle_failed_other_gpr (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value other : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word) (s : State)
    (outsideValue : other.val ≠ value.val) (outsideStatus : other.val ≠ status.val) :
    (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
      status value base rhs kind amount displacement s).state.gpr other = s.gpr other := by
  unfold retryRegisterCycleCore retryRegisterPrefixCore loadCore
  cases loaded : Arm64Memory.read (accessWidth width) s.memory (Arm64Memory.baseValue s base) with
  | error fault => simp [loaded, continueWith]
  | ok pair =>
      rcases pair with ⟨word, event⟩
      by_cases monitor : (!s.exclusiveInputs.retainLocal || s.exclusiveInputs.virtualPass) = true
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines,
          retrySuffixCore, storeCore, checkedState, Arm64Register.write_refines,
          arithmeticImmediateStep, writeData, step, branchStep, monitor, writeReg,
          outsideValue, outsideStatus]
      · simp [loaded, continueWith, Arm64Arithmetic.AluDispatch.raw_step_refines,
          retrySuffixCore, storeCore, checkedState, Arm64Register.write_refines,
          arithmeticImmediateStep, writeData, step, branchStep, monitor, writeReg,
          outsideValue, outsideStatus]

theorem retry_register_cycle_failed_base (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word) (s : State)
    (outsideValue : base.val ≠ value.val) (outsideStatus : base.val ≠ status.val) :
    memoryBase (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
      status value base rhs kind amount displacement s).state base = memoryBase s base := by
  by_cases general : base.val < 31
  · simpa only [memoryBase, general, ↓reduceDIte] using
      retry_register_cycle_failed_other_gpr width acquire release sourceScalar sourceStack
        status value ⟨base.val, general⟩ base rhs kind amount displacement s outsideValue outsideStatus
  · have preserved := congrArg State.sp
      (retry_register_cycle_failed_frame width acquire release sourceScalar sourceStack
        status value base rhs kind amount displacement s)
    simpa only [memoryBase, general, ↓reduceDIte] using preserved

/-- Successful load/register-ADD prefixes advance the native PC by eight bytes. -/
theorem retry_register_prefix_core_pc (width : Width)
    (acquire sourceScalar sourceStack : Bool) (value : Gpr) (base rhs : Register)
    (kind : Fin 3) (amount : Fin width.bits) (s : State) (loadedValue : Word) (event : Event)
    (loaded : Arm64Memory.read (accessWidth width) s.memory (Arm64Memory.baseValue s base) =
      .ok (loadedValue, event)) :
    (retryRegisterPrefixCore width acquire sourceScalar sourceStack value base rhs kind amount s).fault = none ∧
      (retryRegisterPrefixCore width acquire sourceScalar sourceStack value base rhs kind amount s).state.pc =
        s.pc + 4 + 4 := by
  simp [retryRegisterPrefixCore, loadCore, loaded, continueWith,
    Arm64Arithmetic.AluDispatch.raw_step_refines, arithmeticImmediateStep, writeData,
    Arm64Register.write_refines]

/-- The actual four-instruction register-ADD failure branch re-enters its incoming PC. -/
theorem retry_register_cycle_failed_backedge (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : State) (loadedValue : Word) (event : Event)
    (loaded : Arm64Memory.read (accessWidth width) s.memory (Arm64Memory.baseValue s base) =
      .ok (loadedValue, event)) :
    (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
      status value base rhs kind amount (0xfffffffffffffff4 : Word) s).state.pc = s.pc := by
  have facts := retry_register_prefix_core_pc width acquire sourceScalar sourceStack
    value base rhs kind amount s loadedValue event loaded
  unfold retryRegisterCycleCore
  simp only [continueWith, facts.1]
  rw [retry_suffix_core_pc, facts.2]
  simp only [if_true, BitVec.add_assoc]
  exact BitVec.add_zero s.pc

/-- Every finite register-ADD failed prefix preserves memory, flags, vector bank, SP,
alignment profile and thread-pointer inputs, across arbitrary dynamic inputs. -/
theorem retry_register_failure_prefix_frame (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word)
    (inputs : List ExclusiveInputs) (s : State) :
    RetryFrame s (retryFailurePrefix
      (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
        status value base rhs kind amount displacement) inputs s).state := by
  induction inputs generalizing s with
  | nil => rfl
  | cons input rest ih =>
      let start := { s with exclusiveInputs := input }
      let first := retryRegisterCycleCore width acquire release true sourceScalar sourceStack
        status value base rhs kind amount displacement start
      have one : RetryFrame start first.state := by
        unfold RetryFrame
        rw [retry_register_cycle_failed_frame width acquire release sourceScalar sourceStack
          status value base rhs kind amount displacement start]
      have entry : RetryFrame s start := rfl
      have framed := retry_frame_trans s start first.state entry one
      change RetryFrame s (continueWith first _).state
      cases h : first.fault with
      | some fault => simpa only [continueWith, h] using framed
      | none =>
          simpa only [continueWith, h] using
            retry_frame_trans s first.state _ framed (ih first.state)

/-- Data/status are the complete GPR write set for every failed prefix. -/
theorem retry_register_failure_prefix_other_gpr (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value other : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (outsideValue : other.val ≠ value.val) (outsideStatus : other.val ≠ status.val) :
    (retryFailurePrefix (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
      status value base rhs kind amount displacement) inputs s).state.gpr other = s.gpr other := by
  induction inputs generalizing s with
  | nil => rfl
  | cons input rest ih =>
      let start := { s with exclusiveInputs := input }
      let first := retryRegisterCycleCore width acquire release true sourceScalar sourceStack
        status value base rhs kind amount displacement start
      have one : first.state.gpr other = s.gpr other :=
        retry_register_cycle_failed_other_gpr width acquire release sourceScalar sourceStack
          status value other base rhs kind amount displacement start outsideValue outsideStatus
      change (continueWith first _).state.gpr other = s.gpr other
      cases h : first.fault with
      | some fault => simpa only [continueWith, h] using one
      | none => simpa only [continueWith, h] using (ih first.state).trans one

/-- Every disjoint ordinary/SP retry base retains its complete address. -/
theorem retry_register_failure_prefix_base (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (outsideValue : base.val ≠ value.val) (outsideStatus : base.val ≠ status.val) :
    memoryBase (retryFailurePrefix
      (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
        status value base rhs kind amount displacement) inputs s).state base = memoryBase s base := by
  by_cases general : base.val < 31
  · simpa only [memoryBase, general, ↓reduceDIte] using
      retry_register_failure_prefix_other_gpr width acquire release sourceScalar sourceStack
        status value ⟨base.val, general⟩ base rhs kind amount displacement inputs s
        outsideValue outsideStatus
  · have frame := retry_register_failure_prefix_frame width acquire release sourceScalar sourceStack
      status value base rhs kind amount displacement inputs s
    have sp := congrArg State.sp frame
    simpa only [memoryBase, general, ↓reduceDIte] using sp

/-- Exact existing canonical platform/memory premises for a failed visit. -/
structure RetryRegisterFailureDomain (width : Width) (acquire : Bool) (value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits) (s : State) : Prop where
  loadSp : spAlignmentFault s base = none
  loadAligned : exclusiveNaturalFault (memoryBase s base) width.bytes = none
  failed : exclusiveStorePass (retryRegisterPrefix width acquire value base rhs kind amount s).state
    width.bytes = false
  storeSp : spAlignmentFault (retryRegisterPrefix width acquire value base rhs kind amount s).state base = none
  storeAligned : exclusiveNaturalFault
    (memoryBase (retryRegisterPrefix width acquire value base rhs kind amount s).state base) width.bytes = none
  preflight :
    (exclusiveMonitorPass (retryRegisterPrefix width acquire value base rhs kind amount s).state width.bytes ||
      (retryRegisterPrefix width acquire value base rhs kind amount s).state.exclusiveInputs.abortOnFailure) = true →
    permitted (retryRegisterPrefix width acquire value base rhs kind amount s).state.memory.writable
      (memoryBase (retryRegisterPrefix width acquire value base rhs kind amount s).state base) width.bytes = true

/-- Per-visit premises follow the actual canonical path and its first fault. -/
def RetryRegisterFailurePrefixDomain (width : Width) (acquire release : Bool)
    (status value : Gpr) (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word) :
    List ExclusiveInputs → State → Prop
  | [], _ => True
  | input :: rest, s =>
      let start := { s with exclusiveInputs := input }
      let first := retryRegisterCycle width acquire release status value base rhs kind amount displacement start
      RetryRegisterFailureDomain width acquire value base rhs kind amount start ∧
        (first.fault = none → RetryRegisterFailurePrefixDomain width acquire release
          status value base rhs kind amount displacement rest first.state)

/-- Every observed register-ADD finite prefix has the exact canonical state, ordered events
and first fault, with independently supplied dynamic exclusive outcomes. -/
theorem retry_register_failure_prefix_refines (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (admitted : RetryRegisterFailurePrefixDomain width acquire release status value
      base rhs kind amount displacement inputs s) :
    retryFailurePrefix (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
      status value base rhs kind amount displacement) inputs s =
    retryFailurePrefix (retryRegisterCycle width acquire release
      status value base rhs kind amount displacement) inputs s := by
  induction inputs generalizing s with
  | nil => rfl
  | cons input rest ih =>
      let start := { s with exclusiveInputs := input }
      let first := retryRegisterCycle width acquire release status value base rhs kind amount displacement start
      change RetryRegisterFailureDomain width acquire value base rhs kind amount start ∧
        (first.fault = none → RetryRegisterFailurePrefixDomain width acquire release
          status value base rhs kind amount displacement rest first.state) at admitted
      have one := retry_register_cycle_refines width acquire release true sourceScalar sourceStack
        status value base rhs kind amount displacement start admitted.1.loadSp admitted.1.loadAligned
        (by simp only [admitted.1.failed]; rfl) admitted.1.storeSp
        admitted.1.storeAligned admitted.1.preflight
      change continueWith (retryRegisterCycleCore width acquire release true sourceScalar sourceStack
        status value base rhs kind amount displacement start) _ = continueWith first _
      rw [one]
      change continueWith first _ = continueWith first _
      cases h : first.fault with
      | some fault => simp only [continueWith, h]
      | none =>
          simp only [continueWith, h]
          rw [ih first.state (admitted.2 h)]

/-- The canonical failed prefix inherits the complete architectural frame. -/
theorem retry_register_failure_prefix_canonical_frame (width : Width)
    (acquire release sourceScalar sourceStack : Bool) (status value : Gpr)
    (base rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (displacement : Word)
    (inputs : List ExclusiveInputs) (s : State)
    (admitted : RetryRegisterFailurePrefixDomain width acquire release status value
      base rhs kind amount displacement inputs s) :
    RetryFrame s (retryFailurePrefix (retryRegisterCycle width acquire release
      status value base rhs kind amount displacement) inputs s).state := by
  rw [← retry_register_failure_prefix_refines width acquire release sourceScalar sourceStack
    status value base rhs kind amount displacement inputs s admitted]
  exact retry_register_failure_prefix_frame width acquire release sourceScalar sourceStack
    status value base rhs kind amount displacement inputs s

end KProgFormal.Refinement.Arm64Exclusive
