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
