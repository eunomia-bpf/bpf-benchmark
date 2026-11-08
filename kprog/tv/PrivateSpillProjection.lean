import BPFPlatform
import Composition
import PrivateSpills
import BPFPath

/-! Universal verifier-visible projection for compiler-private spill bytes.
Ownership is supplied by the generic compiler/layout relation. Physical
executions and canonical event values remain the source of every observation. -/
namespace KProgTV.PrivateSpillProjection
open KProgFormal.Reference

/-- A complete ordinary access belongs to the compiler-private region. -/
def privateAccess (privateByte : Word → Bool) (address : Word) (bytes : List Byte) : Bool :=
  (!bytes.isEmpty) && (List.range bytes.length).all (fun i => privateByte (address+BitVec.ofNat 64 i))

/-- Projection retains every helper, atomic, exclusive and fault effect.
Ordinary reads/writes use the ownership of every addressed byte. -/
def project (privateByte : Word → Bool) : Event → Option Event
  | event@(.memory .read address bytes _) =>
      if privateAccess privateByte address bytes then none else some event
  | event@(.memory .write address bytes _) =>
      if privateAccess privateByte address bytes then none else some event
  | event => some event

/-- A retained event has its original address, size, kind, values and flags. -/
theorem kept_event_original (privateByte : Word → Bool) (before after : Event)
    (kept : project privateByte before=some after) : before=after := by
  cases before with
  | memory kind address bytes initialized =>
    cases kind with
    | read =>
      simp only [project] at kept
      split at kept
      · contradiction
      · exact Option.some.inj kept
    | write =>
      simp only [project] at kept
      split at kept
      · contradiction
      · exact Option.some.inj kept
    | atomic => exact Option.some.inj kept
  | helper => exact Option.some.inj kept
  | fault => exact Option.some.inj kept
  | exclusive => exact Option.some.inj kept

/-- Every erased effect is an ordinary access fully owned by the compiler's
private region and carries a positive byte count. Other canonical event
constructors and empty access events remain observable. -/
theorem erased_access_owned (privateByte : Word → Bool) (event : Event)
    (erased : project privateByte event=none) :
    ∃ kind address bytes initialized, event=.memory kind address bytes initialized ∧
      (kind=.read ∨ kind=.write) ∧ 0<bytes.length ∧
      ∀ i<bytes.length, privateByte (address+BitVec.ofNat 64 i)=true := by
  cases event with
  | memory kind address bytes initialized =>
    cases kind with
    | read =>
      simp only [project] at erased
      split at erased
      · rename_i owned
        have positive : 0<bytes.length := by cases bytes <;> simp_all [privateAccess]
        exact ⟨.read,address,bytes,initialized,rfl,Or.inl rfl,positive,
          fun i small => (List.all_eq_true.mp (Bool.and_eq_true_iff.mp owned).2) i (List.mem_range.mpr small)⟩
      · contradiction
    | write =>
      simp only [project] at erased
      split at erased
      · rename_i owned
        have positive : 0<bytes.length := by cases bytes <;> simp_all [privateAccess]
        exact ⟨.write,address,bytes,initialized,rfl,Or.inr rfl,positive,
          fun i small => (List.all_eq_true.mp (Bool.and_eq_true_iff.mp owned).2) i (List.mem_range.mpr small)⟩
      · contradiction
    | atomic => contradiction
  | helper => contradiction
  | fault => contradiction
  | exclusive => contradiction

/-- Raw verifier-checked effects imply checked projected effects. -/
theorem projected_trace_checked (privateByte : Word → Bool) (checked : Event → Prop)
    (events : List Event) (sound : ∀ event∈events, checked event) :
    ∀ event∈events.filterMap (project privateByte), checked event := by
  intro event member
  obtain ⟨original,inside,kept⟩ := List.mem_filterMap.mp member
  rw [← kept_event_original privateByte original event kept]
  exact sound original inside

/-- A projected block contains a real instruction execution and its physical
endpoints. It can group any finite number of actual B steps. -/
def projectedBlock {State : Type} (privateByte : Word → Bool) (raw : BlockStep State) : BlockStep State :=
  fun before events after => ∃ rawEvents, Execution raw before rawEvents after ∧
    rawEvents.filterMap (project privateByte)=events

/-- Every projected execution lifts to a physical execution with the same
endpoints and exact ordered projection of its raw trace. -/
theorem projected_execution_lifts {State : Type} (privateByte : Word → Bool)
    (raw : BlockStep State) {before after : State} {events : List Event}
    (run : Execution (projectedBlock privateByte raw) before events after) :
    ∃ rawEvents, Execution raw before rawEvents after ∧
      rawEvents.filterMap (project privateByte)=events := by
  induction run with
  | refl => exact ⟨[],Execution.refl _,rfl⟩
  | next head tail ih =>
    obtain ⟨headEvents,headRun,headProjection⟩ := head
    obtain ⟨tailEvents,tailRun,tailProjection⟩ := ih
    exact ⟨headEvents++tailEvents,headRun.append tailRun,by
      simp only [List.filterMap_append,headProjection,tailProjection]⟩

/-- Actual accepted-B soundness transfers through the generic ownership
projection, using the actual B trace and retained-event identity. -/
theorem projected_execution_checked {State : Type} (privateByte : Word → Bool)
    (raw : BlockStep State) (before : State) (checked : Event → Prop)
    (sound : ∀ rawEvents last, Execution raw before rawEvents last →
      ∀ event∈rawEvents, checked event)
    {after : State} {events : List Event}
    (run : Execution (projectedBlock privateByte raw) before events after) :
    ∀ event∈events, checked event := by
  obtain ⟨rawEvents,rawRun,projection⟩ := projected_execution_lifts privateByte raw run
  rw [← projection]
  exact projected_trace_checked privateByte checked rawEvents (sound rawEvents after rawRun)

/-- Universal artifact composition with compiler-private spill projection.
The validation law ranges over all artifacts; verifier soundness refers to
their actual physical proof executions. Binding includes layout metadata. -/
theorem generic_artifact_effects_checked {Native Proof : Type}
    (native : Artifact → BlockStep Native) (rawProof : Artifact → BlockStep Proof)
    (privateByte : Artifact → Word → Bool) (related : Artifact → Native → Proof → Prop)
    (validation : ∀ a, TranslationValidation (native a)
      (projectedBlock (privateByte a) (rawProof a)) (related a))
    (accepted : Artifact → Prop) (proofEntry : Artifact → Proof → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ a, accepted a → ∀ p trace p', proofEntry a p →
      Execution (rawProof a) p trace p' → ∀ event∈trace, checked a event)
    (validated executed : Artifact) (binding : executed=validated) (acceptance : accepted validated)
    {n p trace n'} (entry : related validated n p) (admitted : proofEntry validated p)
    (run : Execution (native executed) n trace n') :
    ∀ event∈trace, checked validated event := by
  apply native_effects_checked native (fun a => projectedBlock (privateByte a) (rawProof a)) related
    accepted proofEntry checked ?_ validated executed binding acceptance (validation validated) entry admitted run
  intro a acceptedA p events last entryA projectedRun
  exact projected_execution_checked (privateByte a) (rawProof a) p (checked a)
    (fun rawEvents rawLast rawRun => verifierSound a acceptedA p rawEvents rawLast entryA rawRun) projectedRun

/-- A clang STXDW spill and LDXDW reload, using the BPF frame register. -/
def spillInstruction (saved : BPF.Register) (offset : BitVec 16) : BPF.Instruction :=
  ⟨0x7b, 10, saved.val, offset, 0⟩

def reloadInstruction (saved : BPF.Register) (offset : BitVec 16) : BPF.Instruction :=
  ⟨0x79, saved, 10, offset, 0⟩

def spillAddress (s : BPF.State) (offset : BitVec 16) : Word :=
  s.regs 10 + offset.signExtend 64

def spilled (s : BPF.State) (saved : BPF.Register) (offset : BitVec 16) : BPF.State :=
  { s with
    memory := storeMemory s.memory (spillAddress s offset) (s.regs saved) 8
    pc := s.pc + 1 }

def restored (s : BPF.State) (saved : BPF.Register) (offset : BitVec 16) : BPF.State :=
  { spilled s saved offset with pc := s.pc + 2 }

def spillTrace (s : BPF.State) (saved : BPF.Register) (offset : BitVec 16) : List Event :=
  [.memory .write (spillAddress s offset) (valueBytes (s.regs saved) 8) true,
   .memory .read (spillAddress s offset) (valueBytes (s.regs saved) 8) true]

/-- Actual store execution writes precisely the captured register word. -/
theorem spill_instruction_matches (env : BPF.Environment) (program : Array Byte)
    (s : BPF.State) (saved : BPF.Register) (offset : BitVec 16)
    (writable : permitted s.memory.writable (spillAddress s offset) 8 = true) :
    BPF.execute env program s (spillInstruction saved offset) = .ok
      ⟨spilled s saved offset,
        [.memory .write (spillAddress s offset) (valueBytes (s.regs saved) 8) true], none⟩ := by
  unfold spillAddress at writable
  simp [BPF.execute, spillInstruction, BPF.store, writeMemory, spillAddress, spilled,
    saved.isLt, writable, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- The reload recovers the original word and every BPF register; PC advances
through both actual instructions and both ghost visit indices are preserved. -/
theorem reload_spilled_matches (env : BPF.Environment) (program : Array Byte)
    (s : BPF.State) (saved : BPF.Register) (offset : BitVec 16) (general : saved ≠ 10)
    (readable : permitted s.memory.readable (spillAddress s offset) 8 = true) :
    BPF.execute env program (spilled s saved offset) (reloadInstruction saved offset) = .ok
      ⟨restored s saved offset,
        [.memory .read (spillAddress s offset) (valueBytes (s.regs saved) 8) true], none⟩ := by
  have read := PrivateSpills.spill_read s.memory (spillAddress s offset) (s.regs saved) readable
  unfold spillAddress at read
  have regs : (fun index : BPF.Register => if index = saved then s.regs saved else s.regs index) = s.regs := by
    funext index
    split <;> simp_all
  simp [BPF.execute, reloadInstruction, BPF.load, read, spilled, spillAddress,
    general, restored, BPF.setReg, regs, Int.add_assoc,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- A byte-decoded two-instruction execution, independent of program identity
and instruction position. Permissions are supplied by the physical frame. -/
theorem spill_reload_execution (env : BPF.Environment) (program : Array Byte)
    (s : BPF.State) (saved : BPF.Register) (offset : BitVec 16) (pc : Nat)
    (general : saved ≠ 10) (active : s.halted = false) (position : s.pc = pc)
    (storeDecoded : BPF.decode program pc = .ok (spillInstruction saved offset))
    (loadDecoded : BPF.decode program (pc+1) = .ok (reloadInstruction saved offset))
    (writable : permitted s.memory.writable (spillAddress s offset) 8 = true)
    (readable : permitted s.memory.readable (spillAddress s offset) 8 = true) :
    Execution (BPFPath.instructionStep env program) s (spillTrace s saved offset)
      (restored s saved offset) := by
  have first : BPFPath.instructionStep env program s
      [.memory .write (spillAddress s offset) (valueBytes (s.regs saved) 8) true]
      (spilled s saved offset) := by
    refine ⟨⟨spilled s saved offset, _, none⟩, ?_, rfl, rfl⟩
    simp [BPF.step, active, position, storeDecoded,
      spill_instruction_matches env program s saved offset writable]
  have secondActive : (spilled s saved offset).halted = false := active
  have secondPosition : (spilled s saved offset).pc = (pc + 1 : Nat) := by
    simp [spilled, position, Int.natCast_add]
  have second : BPFPath.instructionStep env program (spilled s saved offset)
      [.memory .read (spillAddress s offset) (valueBytes (s.regs saved) 8) true]
      (restored s saved offset) := by
    refine ⟨⟨restored s saved offset, _, none⟩, ?_, rfl, rfl⟩
    have nonnegative : ¬ (spilled s saved offset).pc < 0 := by rw [secondPosition]; omega
    simp [BPF.step, secondActive, nonnegative, secondPosition, loadDecoded,
      reload_spilled_matches env program s saved offset general readable] <;> omega
  exact Execution.next first (Execution.next second (Execution.refl _))

/-- The same wrapping-byte ownership used by projection erases exactly the
ordinary spill/reload effects, carrying their actual source bytes. -/
theorem spill_reload_projected (privateByte : Word → Bool) (s : BPF.State)
    (saved : BPF.Register) (offset : BitVec 16)
    (owned : ∀ i < 8, privateByte (spillAddress s offset + BitVec.ofNat 64 i) = true) :
    (spillTrace s saved offset).filterMap (project privateByte) = [] := by
  have access : privateAccess privateByte (spillAddress s offset)
      (valueBytes (s.regs saved) 8) = true := by
    simpa [privateAccess, valueBytes, List.all_eq_true] using owned

  simp [spillTrace, project, access]

/-- All public bytes and initialization bits survive an owned spill; the
architectural register map, ghost inputs and halt state retain exact values. -/
theorem spill_public_memory (privateByte : Word → Bool) (s : BPF.State)
    (saved : BPF.Register) (offset : BitVec 16)
    (owned : ∀ i < 8, privateByte (spillAddress s offset + BitVec.ofNat 64 i) = true)
    (address : Word) (public : privateByte address = false) :
    (restored s saved offset).memory.value address = s.memory.value address ∧
    (restored s saved offset).memory.initialized address = s.memory.initialized address := by
  have apart : ¬ (address - spillAddress s offset).toNat < 8 := by
    intro inside
    have ownership := owned _ inside
    have same : spillAddress s offset + BitVec.ofNat 64 (address-spillAddress s offset).toNat = address := by
      simp only [BitVec.ofNat_toNat]
      bv_decide
    rw [same, public] at ownership
    contradiction
  change (storeMemory s.memory (spillAddress s offset) (s.regs saved) 8).value address = _ ∧
    (storeMemory s.memory (spillAddress s offset) (s.regs saved) 8).initialized address = _
  simp only [storeMemory, apart, ite_false]
  trivial

/-- The inserted pair itself supplies the raw-execution witness required by
private spill erasure, for every decoded site and every signed16-bit offset. -/
theorem spill_reload_projected_block (env : BPF.Environment) (program : Array Byte)
    (privateByte : Word → Bool) (s : BPF.State) (saved : BPF.Register)
    (offset : BitVec 16) (pc : Nat) (general : saved ≠ 10)
    (active : s.halted = false) (position : s.pc = pc)
    (storeDecoded : BPF.decode program pc = .ok (spillInstruction saved offset))
    (loadDecoded : BPF.decode program (pc+1) = .ok (reloadInstruction saved offset))
    (writable : permitted s.memory.writable (spillAddress s offset) 8 = true)
    (readable : permitted s.memory.readable (spillAddress s offset) 8 = true)
    (owned : ∀ i < 8, privateByte (spillAddress s offset + BitVec.ofNat 64 i) = true) :
    projectedBlock privateByte (BPFPath.instructionStep env program) s []
      (restored s saved offset) :=
  ⟨spillTrace s saved offset,
    spill_reload_execution env program s saved offset pc general active position
      storeDecoded loadDecoded writable readable,
    spill_reload_projected privateByte s saved offset owned⟩


end KProgTV.PrivateSpillProjection
#print axioms KProgTV.PrivateSpillProjection.kept_event_original
#print axioms KProgTV.PrivateSpillProjection.erased_access_owned
#print axioms KProgTV.PrivateSpillProjection.projected_trace_checked
#print axioms KProgTV.PrivateSpillProjection.projected_execution_lifts
#print axioms KProgTV.PrivateSpillProjection.projected_execution_checked
#print axioms KProgTV.PrivateSpillProjection.generic_artifact_effects_checked


#print axioms KProgTV.PrivateSpillProjection.spill_instruction_matches
#print axioms KProgTV.PrivateSpillProjection.reload_spilled_matches
#print axioms KProgTV.PrivateSpillProjection.spill_reload_execution
#print axioms KProgTV.PrivateSpillProjection.spill_reload_projected
#print axioms KProgTV.PrivateSpillProjection.spill_public_memory

#print axioms KProgTV.PrivateSpillProjection.spill_reload_projected_block

namespace KProgTV.PrivateSpillProjection
open KProgFormal.Reference

/-- The reload after an intervening body restores the original saved word,
without replacing any of the body's memory, other registers or ghost state. -/
def reloadedAfter (original body : BPF.State) (saved : BPF.Register) : BPF.State :=
  BPF.setReg { body with pc := body.pc + 1 } saved (original.regs saved)

theorem reload_after_body_matches (env : BPF.Environment) (program : Array Byte)
    (original body : BPF.State) (saved : BPF.Register) (offset : BitVec 16)
    (general : saved ≠ 10) (frame : body.regs 10 = original.regs 10)
    (readable : permitted original.memory.readable (spillAddress original offset) 8 = true)
    (slot : readMemory body.memory (spillAddress original offset) 8 =
      readMemory (spilled original saved offset).memory (spillAddress original offset) 8) :
    BPF.execute env program body (reloadInstruction saved offset) = .ok
      ⟨reloadedAfter original body saved,
        [Event.memory .read (spillAddress original offset) (valueBytes (original.regs saved) 8) true], none⟩ := by
  have read := slot.trans (PrivateSpills.spill_read original.memory
    (spillAddress original offset) (original.regs saved) readable)
  have base : body.regs 10 + offset.signExtend 64 = spillAddress original offset := by
    rw [frame]
    rfl
  simp [BPF.execute, reloadInstruction, BPF.load, base, read, general, reloadedAfter, BPF.setReg,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- The complete inserted prefix/body/suffix consists of actual decoded BPF
steps at their real PCs. The body can have arbitrary finite control flow and
observable effects; only the live spill read and frame address must survive. -/
theorem spill_body_reload_execution (env : BPF.Environment) (program : Array Byte)
    (original body : BPF.State) (saved : BPF.Register) (offset : BitVec 16)
    (start finish : Nat) (events : List Event)
    (general : saved ≠ 10) (active : original.halted = false) (position : original.pc = start)
    (storeDecoded : BPF.decode program start = .ok (spillInstruction saved offset))
    (loadDecoded : BPF.decode program finish = .ok (reloadInstruction saved offset))
    (writable : permitted original.memory.writable (spillAddress original offset) 8 = true)
    (readable : permitted original.memory.readable (spillAddress original offset) 8 = true)
    (middle : Execution (BPFPath.instructionStep env program)
      (spilled original saved offset) events body)
    (bodyActive : body.halted = false) (bodyPosition : body.pc = finish)
    (frame : body.regs 10 = original.regs 10)
    (slot : readMemory body.memory (spillAddress original offset) 8 =
      readMemory (spilled original saved offset).memory (spillAddress original offset) 8) :
    Execution (BPFPath.instructionStep env program) original
      ([Event.memory .write (spillAddress original offset) (valueBytes (original.regs saved) 8) true] ++
        events ++ [Event.memory .read (spillAddress original offset) (valueBytes (original.regs saved) 8) true])
      (reloadedAfter original body saved) := by
  have first : BPFPath.instructionStep env program original
      [Event.memory .write (spillAddress original offset) (valueBytes (original.regs saved) 8) true]
      (spilled original saved offset) := by
    refine ⟨⟨spilled original saved offset, _, none⟩, ?_, rfl, rfl⟩
    simp [BPF.step, active, position, storeDecoded,
      spill_instruction_matches env program original saved offset writable]
  have last : BPFPath.instructionStep env program body
      [Event.memory .read (spillAddress original offset) (valueBytes (original.regs saved) 8) true]
      (reloadedAfter original body saved) := by
    refine ⟨⟨reloadedAfter original body saved, _, none⟩, ?_, rfl, rfl⟩
    have nonnegative : ¬body.pc < 0 := by rw [bodyPosition]; omega
    simp [BPF.step, bodyActive, nonnegative, bodyPosition, loadDecoded,
      reload_after_body_matches env program original body saved offset general frame readable slot]
  have tail := middle.append (by
    simpa only [List.append_nil] using Execution.next last (Execution.refl _))
  have entire := Execution.next first tail
  simpa only [List.append_assoc] using entire

/-- Private spill/reload projection preserves the entire intervening trace
in order, apart from the same separately owned ordinary-access projection. -/
theorem spill_body_reload_projected (privateByte : Word → Bool) (original : BPF.State)
    (saved : BPF.Register) (offset : BitVec 16) (events : List Event)
    (owned : ∀ index < 8, privateByte (spillAddress original offset + BitVec.ofNat 64 index) = true) :
    ([Event.memory .write (spillAddress original offset) (valueBytes (original.regs saved) 8) true] ++
      events ++ [Event.memory .read (spillAddress original offset) (valueBytes (original.regs saved) 8) true]).filterMap
        (project privateByte) = events.filterMap (project privateByte) := by
  have access : privateAccess privateByte (spillAddress original offset)
      (valueBytes (original.regs saved) 8) = true := by
    simpa [privateAccess, valueBytes, List.all_eq_true] using owned
  simp [List.filterMap_append, project, access]

theorem reloaded_after_frame (original body : BPF.State) (saved : BPF.Register) :
    (reloadedAfter original body saved).regs saved = original.regs saved ∧
    (reloadedAfter original body saved).memory = body.memory ∧
    (reloadedAfter original body saved).pc = body.pc + 1 ∧
    (reloadedAfter original body saved).unspecifiedVisit = body.unspecifiedVisit ∧
    (reloadedAfter original body saved).exclusiveVisit = body.exclusiveVisit ∧
    (reloadedAfter original body saved).halted = body.halted ∧
    ∀ register, register ≠ saved →
      (reloadedAfter original body saved).regs register = body.regs register := by
  refine ⟨by simp [reloadedAfter, BPF.setReg], rfl, rfl, rfl, rfl, rfl, ?_⟩
  intro register different
  simp [reloadedAfter, BPF.setReg, different]
/-- The real wrapper supplies the projected-block witness around any finite
body. This discharges insertion/control composition once the compiler supplies
private ownership, frame/slot liveness and the body's actual execution. -/
theorem spill_body_reload_projected_block (env : BPF.Environment) (program : Array Byte)
    (privateByte : Word → Bool) (original body : BPF.State)
    (saved : BPF.Register) (offset : BitVec 16) (start finish : Nat) (events : List Event)
    (general : saved ≠ 10) (active : original.halted = false) (position : original.pc = start)
    (storeDecoded : BPF.decode program start = .ok (spillInstruction saved offset))
    (loadDecoded : BPF.decode program finish = .ok (reloadInstruction saved offset))
    (writable : permitted original.memory.writable (spillAddress original offset) 8 = true)
    (readable : permitted original.memory.readable (spillAddress original offset) 8 = true)
    (middle : Execution (BPFPath.instructionStep env program)
      (spilled original saved offset) events body)
    (bodyActive : body.halted = false) (bodyPosition : body.pc = finish)
    (frame : body.regs 10 = original.regs 10)
    (slot : readMemory body.memory (spillAddress original offset) 8 =
      readMemory (spilled original saved offset).memory (spillAddress original offset) 8)
    (owned : ∀ index < 8, privateByte (spillAddress original offset + BitVec.ofNat 64 index) = true) :
    projectedBlock privateByte (BPFPath.instructionStep env program) original
      (events.filterMap (project privateByte)) (reloadedAfter original body saved) :=
  ⟨_, spill_body_reload_execution env program original body saved offset start finish events
    general active position storeDecoded loadDecoded writable readable middle bodyActive bodyPosition frame slot,
    spill_body_reload_projected privateByte original saved offset events owned⟩

end KProgTV.PrivateSpillProjection
#print axioms KProgTV.PrivateSpillProjection.reload_after_body_matches
#print axioms KProgTV.PrivateSpillProjection.spill_body_reload_execution
#print axioms KProgTV.PrivateSpillProjection.spill_body_reload_projected
#print axioms KProgTV.PrivateSpillProjection.reloaded_after_frame

#print axioms KProgTV.PrivateSpillProjection.spill_body_reload_projected_block

namespace KProgTV.PrivateSpillProjection
open KProgFormal.Reference

/-- Actual returning CALL retains a caller-owned read under the helper's
local memory footprint. Map/helper effects, result and clobbers remain real;
physical/native ABI and proof of that footprint are explicit premises. -/
theorem returning_helper_owned_read
    (environment : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (instruction : BPF.Instruction) (call : BPF.HelperCall) (effect : BPF.HelperResult)
    (opcode : instruction.code = 0x85) (source : instruction.src = 0 ∨ instruction.src = 2)
    (resolved : environment.helperCall instruction state = .ok call)
    (returned : environment.helper call (BPF.helperArguments call state) state.memory = .ok effect)
    (actual : Transition BPF.State)
    (observed : BPF.execute environment program state instruction = .ok actual)
    (owned : Word → Bool) (frame : PrivateSpills.FrameOn owned state.memory effect.memory)
    (address : Word) (count : Nat)
    (inside : ∀ index < count, owned (address + BitVec.ofNat 64 index) = true) :
    readMemory actual.state.memory address count = readMemory state.memory address count := by
  have frameState := BPFPlatform.returning_helper_frame environment program state instruction call effect
    opcode source resolved returned actual observed
  rw [frameState.2.1]
  exact PrivateSpills.frame_on_read owned state.memory effect.memory frame address count inside

/-- A real LDXDW after the helper reloads the saved word from the preserved
bytes. The address uses a callee-preserved BPF register, and all helper memory
outside the caller-owned region may change. -/
theorem returning_helper_owned_reload
    (environment : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (instruction : BPF.Instruction) (call : BPF.HelperCall) (effect : BPF.HelperResult)
    (opcode : instruction.code = 0x85) (source : instruction.src = 0 ∨ instruction.src = 2)
    (resolved : environment.helperCall instruction state = .ok call)
    (returned : environment.helper call (BPF.helperArguments call state) state.memory = .ok effect)
    (actual : Transition BPF.State)
    (observed : BPF.execute environment program state instruction = .ok actual)
    (owned : Word → Bool) (frame : PrivateSpills.FrameOn owned state.memory effect.memory)
    (address saved : Word) (event : Event)
    (inside : ∀ index < 8, owned (address + BitVec.ofNat 64 index) = true)
    (read : readMemory state.memory address 8 = .ok (saved,event))
    (load : BPF.Instruction) (loadCode : load.code = 0x79)
    (base : BPF.Register) (preserved : 6 ≤ base.val)
    (loadBase : load.src = base.val) (destination : load.dst ≠ 10)
    (atAddress : state.regs base + load.offset.signExtend 64 = address) :
    BPF.execute environment program actual.state load = .ok
      ⟨BPF.setReg { actual.state with pc := actual.state.pc+1 } load.dst saved,[event],none⟩ := by
  have frameState := BPFPlatform.returning_helper_frame environment program state instruction call effect
    opcode source resolved returned actual observed
  have memoryRead := (returning_helper_owned_read environment program state instruction call effect
    opcode source resolved returned actual observed owned frame address 8 inside).trans read
  have sameBase : actual.state.regs base = state.regs base := frameState.2.2.2.2.2.2.2.2.1 base preserved
  have afterAddress : actual.state.regs base + load.offset.signExtend 64 = address := by
    rw [sameBase]
    exact atAddress
  simp [BPF.execute,loadCode,loadBase,destination,base.isLt,BPF.load,BPF.setReg,
    afterAddress,memoryRead,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
end KProgTV.PrivateSpillProjection
#print axioms KProgTV.PrivateSpillProjection.returning_helper_owned_read
#print axioms KProgTV.PrivateSpillProjection.returning_helper_owned_reload

namespace KProgTV.PrivateSpillProjection
open KProgFormal.Reference

/-- The decoded final program really executes the helper followed by the
owned reload. Complete ordered helper effects and the actual read remain. -/
theorem returning_helper_owned_reload_execution
    (environment : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (instruction : BPF.Instruction) (call : BPF.HelperCall) (effect : BPF.HelperResult)
    (opcode : instruction.code = 0x85) (source : instruction.src = 0 ∨ instruction.src = 2)
    (resolved : environment.helperCall instruction state = .ok call)
    (returned : environment.helper call (BPF.helperArguments call state) state.memory = .ok effect)
    (actual : Transition BPF.State)
    (observed : BPF.execute environment program state instruction = .ok actual)
    (owned : Word → Bool) (frame : PrivateSpills.FrameOn owned state.memory effect.memory)
    (address saved : Word) (event : Event)
    (inside : ∀ index < 8, owned (address + BitVec.ofNat 64 index) = true)
    (read : readMemory state.memory address 8 = .ok (saved,event))
    (load : BPF.Instruction) (loadCode : load.code = 0x79)
    (base : BPF.Register) (preserved : 6 ≤ base.val)
    (loadBase : load.src = base.val) (destination : load.dst ≠ 10)
    (atAddress : state.regs base + load.offset.signExtend 64 = address)
    (active : state.halted = false) (position : 0 ≤ state.pc)
    (callDecoded : BPF.decode program state.pc.toNat = .ok instruction)
    (loadDecoded : BPF.decode program actual.state.pc.toNat = .ok load) :
    Execution (BPFPath.instructionStep environment program) state (actual.events ++ [event])
      (BPF.setReg { actual.state with pc := actual.state.pc+1 } load.dst saved) := by
  have frameState := BPFPlatform.returning_helper_frame environment program state instruction call effect
    opcode source resolved returned actual observed
  have afterActive : actual.state.halted = false := frameState.2.2.2.1.trans active
  have afterPosition : 0 ≤ actual.state.pc := by
    rw [frameState.2.2.1]
    omega
  have firstStep : BPF.step environment program state = .ok actual := by
    simp [BPF.step,active,Int.not_lt.mpr position,callDecoded,observed]
  have first : BPFPath.instructionStep environment program state actual.events actual.state :=
    ⟨actual,firstStep,rfl,rfl⟩
  have loaded := returning_helper_owned_reload environment program state instruction call effect
    opcode source resolved returned actual observed owned frame address saved event inside read
    load loadCode base preserved loadBase destination atAddress
  have secondStep : BPF.step environment program actual.state = .ok
      ⟨BPF.setReg { actual.state with pc := actual.state.pc+1 } load.dst saved,[event],none⟩ := by
    simp [BPF.step,afterActive,Int.not_lt.mpr afterPosition,loadDecoded,loaded]
  have second : BPFPath.instructionStep environment program actual.state [event]
      (BPF.setReg { actual.state with pc := actual.state.pc+1 } load.dst saved) :=
    ⟨_,secondStep,rfl,rfl⟩
  simpa only [List.append_nil] using Execution.next first (Execution.next second (Execution.refl _))

end KProgTV.PrivateSpillProjection
#print axioms KProgTV.PrivateSpillProjection.returning_helper_owned_reload_execution
