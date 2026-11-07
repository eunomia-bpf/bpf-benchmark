import TrustedSimpleCFG

set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleSafety
open KProgFormal.Reference KProgTV.TrustedSimpleX86

-- Concrete selected-path composition. Arbitrary CFG/prefix coverage and
-- entry/ABI/RET/platform semantic transport remain separate obligations.


/-- Private setup projection only erases events; a surviving event is the
original event with exactly the same address, kind, size, bytes and flags. -/
theorem initialization_projection_never_invents (frame : Word) (before after : Event)
    (kept : initializationProjectEvent frame before=some after) : before=after := by
  cases before with
  | memory kind address bytes initialized =>
    cases kind with
    | read =>
      simp only [initializationProjectEvent] at kept
      split at kept
      · simp at kept
      · exact Option.some.inj kept
    | write =>
      simp only [initializationProjectEvent] at kept
      split at kept
      · simp at kept
      · exact Option.some.inj kept
    | atomic => exact Option.some.inj kept
  | helper => exact Option.some.inj kept
  | fault => exact Option.some.inj kept
  | exclusive => exact Option.some.inj kept

theorem initialization_projected_events_checked (frame : Word) (checked : Event → Prop)
    (trace : List Event) (allChecked : ∀ event ∈ trace, checked event) :
    ∀ event ∈ trace.filterMap (initializationProjectEvent frame), checked event := by
  intro event inside
  obtain ⟨before,member,kept⟩ := List.mem_filterMap.mp inside
  rw [← initialization_projection_never_invents frame before event kept]
  exact allChecked before member

/-- The verifier-facing instruction relation is parameterized by the exact
proof image in the full bound artifact, with no proof-byte substitution. -/
def boundCapturedProofStep (env : BPF.Environment) (artifact : Artifact) : BlockStep BPF.State :=
  fun before events after => ∃ result,
    BPFPlatform.step (initializedPlatform env) artifact.proofBytes.toArray before=.ok result ∧
      result.events=events ∧ result.state=after


theorem bound_captured_selected_path_effects_checked (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ artifact, accepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (boundCapturedProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    (actual : Transition X86.State)
    (run : CanonicalRelationalPath (BitVec.ofNat 64 executed.entry) executed.nativeBytes.toArray
      (allReadNativePath n) n actual)
    (stack : Word) (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (context : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack)
    (write40 : permitted p.memory.writable (p.regs 10-(40#64)) 8=true)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8=true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8=true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8=true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4=true)
    (read40 : permitted p.memory.readable (p.regs 10-(40#64)) 8=true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8=true)
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ∀ i<8, ¬ initializationPrivateByte (p.regs 10) (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    ∀ event ∈ actual.events, checked validated event := by
  subst executed
  have actualRun : CanonicalRelationalPath 0 native (allReadNativePath n) n actual := by
    simpa only [nativeImage,entryImage,Array.toArray_toList] using run
  obtain ⟨_,_,events,proofRun,projection,_⟩ := captured_all_permissions_relational_correspondence
    env n p stack nativePC proofPC active context memory nativeStack write40 write32 write24
    write16 write8 read40 read32 guest0 actual actualRun guest1
  have stepEq : boundCapturedProofStep env validated=initializedInstructionStep env := by
    funext before events after
    unfold boundCapturedProofStep initializedInstructionStep
    rw [proofImage]
  have boundRun : Execution (boundCapturedProofStep env validated) p
      (allReadSetupTrace p++allReadGuestTrace p) (allReadProofFinal p stack) := by
    rw [stepEq]
    exact proofRun
  have checkedRaw := verifierSound validated acceptance admitted _ _ boundRun
  have checkedSetup : ∀ event ∈ (allReadSetupTrace p).filterMap
      (initializationProjectEvent (p.regs 10)), checked validated event :=
    initialization_projected_events_checked _ _ _ (fun event member =>
      checkedRaw event (List.mem_append_left _ member))
  have checkedGuest : ∀ event ∈ allReadGuestTrace p, checked validated event :=
    fun event member => checkedRaw event (List.mem_append_right _ member)
  intro event member
  rw [events,← projection] at member
  rcases List.mem_append.mp member with setup | guest
  · exact checkedSetup event setup
  · exact checkedGuest event guest


/-- A checked terminal region may vary only within a proved state relation;
all steps remain in that region and emit only already checked events. -/
theorem execution_checked_related_terminal {State : Type} {step : BlockStep State}
    (related : State → State → Prop) (checked : Event → Prop) (terminal : State)
    (quiet : ∀ {s events next}, related terminal s → step s events next →
      related terminal next ∧ ∀ event ∈ events, checked event)
    {s last : State} {trace : List Event} (run : Execution step s trace last)
    (initial : related terminal s) : ∀ event ∈ trace, checked event := by
  induction run with
  | refl => intro event inside; simp at inside
  | next head tail ih =>
    obtain ⟨nextRelation,allowed⟩ := quiet initial head
    have checkedTail := ih nextRelation
    intro event inside
    rcases List.mem_append.mp inside with first | second
    · exact allowed event first
    · exact checkedTail event second

/-- One checked complete execution covers every finite execution from a
related entry when each actual step has the same events and a related next
state. The relation may retain precisely the ISA's undefined-output freedom;
full-state determinism is not assumed. No fuel or termination assumption is
placed on the arbitrary execution. -/
theorem execution_checked_of_related_complete {State : Type} {step : BlockStep State}
    (related : State → State → Prop)
    (matched : ∀ {first second firstEvents firstNext secondEvents secondNext},
      related first second → step first firstEvents firstNext →
      step second secondEvents secondNext → firstEvents=secondEvents ∧ related firstNext secondNext)
    (checked : Event → Prop) {s terminal : State} {expected : List Event}
    (complete : Execution step s expected terminal)
    (allowed : ∀ event ∈ expected, checked event)
    (quiet : ∀ {state events next}, related terminal state → step state events next →
      related terminal next ∧ ∀ event ∈ events, checked event)
    {actualStart last : State} {trace : List Event}
    (initial : related s actualStart) (run : Execution step actualStart trace last) :
    ∀ event ∈ trace, checked event := by
  induction complete generalizing actualStart trace last with
  | refl => exact execution_checked_related_terminal related checked _ quiet run initial
  | next head suffix ih =>
    cases run with
    | refl => intro event inside; simp at inside
    | next actualHead actualTail =>
      obtain ⟨sameEvents,nextRelation⟩ := matched initial head actualHead
      cases sameEvents
      have checkedTail := ih (fun event inside => allowed event (List.mem_append_right _ inside))
        quiet nextRelation actualTail
      intro event inside
      rcases List.mem_append.mp inside with first | second
      · exact allowed event (List.mem_append_left _ first)
      · exact checkedTail event second


/-- Equal complete architectural state except for AF, the only undefined
output bit of the captured XOR. Every other field remains exact. -/
def afEquivalent (first second : X86.State) : Prop :=
  {first with rflags := first.rflags &&& (0xffffffffffffffef#64)} =
    {second with rflags := second.rflags &&& (0xffffffffffffffef#64)}

theorem af_equivalent_shape (first second : X86.State) (same : afEquivalent first second) :
    second={first with rflags := second.rflags} ∧
    first.rflags &&& (0xffffffffffffffef#64)=second.rflags &&& (0xffffffffffffffef#64) := by
  exact ⟨(congrArg (fun s : X86.State => {s with rflags := second.rflags}) same).symm,
    congrArg X86.State.rflags same⟩

/-- Canonical CMP overwrites AF; all flags it preserves agree without any
choice of a representative for the undefined XOR bit. -/
theorem compare_flags_ignore_AF (left right first second : Word)
    (same : first &&& (0xffffffffffffffef#64)=second &&& (0xffffffffffffffef#64)) :
    X86.arithmeticFlags .w64 true false left right first =
      X86.arithmeticFlags .w64 true false left right second := by
  have preserved : first &&& (0xfffffffffffff72a : Word)=second &&& (0xfffffffffffff72a : Word) := by
    unfold Word at *
    bv_decide
  simp only [X86.arithmeticFlags,preserved]

/-- The actual canonical register CMP operation at capturedPC12 has exactly
one complete output transition for any AF-equivalent input states. -/
theorem canonical_cmp12_af_equivalent (first second : X86.State)
    (same : afEquivalent first second) :
    X86.step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) first =
      X86.step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) second := by
  obtain ⟨shape,masked⟩ := af_equivalent_shape first second same
  have flags := compare_flags_ignore_AF (first.gpr 6) (first.gpr 2) first.rflags second.rflags masked
  have nocarry (flags : Word) : X86.ArithmeticKind.compare.carry flags=false := rfl
  rw [shape]
  simp +decide [X86.step,X86.arithmeticStep,X86.scalarRead,X86.scalarRegisterValue,
    X86.ScalarDestination.source,X86.ArithmeticKind.subtract,nocarry,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,flags]

/-- Every canonical relational CMP result agrees completely, including all
registers/flags/memory/events/faults, for these AF-equivalent inputs. -/
theorem canonical_cmp12_relational_af_equivalent (first second : X86.State)
    (actualFirst actualSecond : Transition X86.State) (same : afEquivalent first second)
    (firstRun : X86.Step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15)
      first actualFirst)
    (secondRun : X86.Step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15)
      second actualSecond) : actualFirst=actualSecond := by
  have firstExact := fully_observed_step_unique _ first actualFirst rfl (fun _ => rfl) firstRun
  have secondExact := fully_observed_step_unique _ second actualSecond rfl (fun _ => rfl) secondRun
  rw [firstExact,secondExact]
  exact canonical_cmp12_af_equivalent first second same


/-- Canonical decoded relational instructions composed as a BlockStep.
The wrapper adds no opcode semantics, input test, successor or fuel guard.
It permits fault repeats, an overapproximation handled by terminal closure. -/
def relationalNativeInstructionStep (base : Word) (bytes : Array Byte) : BlockStep X86.State :=
  fun before events after => ∃ entry instruction effect,
    X86Path.decodeAt base bytes entry before=.ok instruction ∧ X86.Step instruction before effect ∧
      effect.events=events ∧ effect.state=after

theorem canonical_execution_relational {base : Word} {bytes : Array Byte}
    {s last : X86.State} {trace : List Event}
    (run : X86Path.Execution base bytes s trace last) :
    Execution (relationalNativeInstructionStep base bytes) s trace last := by
  induction run with
  | refl state => exact Execution.refl state
  | @next before after events entry instruction decoded tail ih =>
    exact Execution.next ⟨entry,instruction,X86.step instruction before,decoded,⟨rfl,rfl,rfl⟩,rfl,rfl⟩ ih

theorem canonical_relational_path_execution {base : Word} {bytes : Array Byte}
    {entries : List X86Path.Entry} {s : X86.State} {actual : Transition X86.State}
    (run : CanonicalRelationalPath base bytes entries s actual) :
    Execution (relationalNativeInstructionStep base bytes) s actual.events actual.state := by
  induction run with
  | nil state => exact Execution.refl state
  | @fault before effect entry instruction decoded step failed =>
    have head : relationalNativeInstructionStep base bytes before effect.events effect.state :=
      ⟨entry,instruction,effect,decoded,step,rfl,rfl⟩
    simpa only [List.append_nil] using Execution.next head (Execution.refl effect.state)
  | @next before first rest tail entry instruction decoded step continued suffix ih =>
    exact Execution.next ⟨entry,instruction,first,decoded,step,rfl,rfl⟩ ih


/-- Actual closed native states agree completely except that the real XOR
may choose AF freely until its subsequent CMP atPC12. -/
def nativeStatesRelated (first second : X86.State) : Prop :=
  simpleClosedPC first.pc ∧ if first.pc=12 then afEquivalent first second else first=second

theorem native_states_related_refl (s : X86.State) (valid : simpleClosedPC s.pc) :
    nativeStatesRelated s s := by
  refine ⟨valid,?_⟩
  split <;> rfl

/-- The closed CFG and actual decoder determine an arbitrary supplied
extent. An end-PC witness cannot authorize an instruction. -/
theorem closed_decoded_extent (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (valid : simpleClosedPC s.pc)
    (decoded : X86Path.decodeAt 0 native entry s=.ok instruction) :
    s.pc.toNat ∈ simpleNativeOffsets ∧
      entry=⟨s.pc.toNat,simpleNativeLength s.pc.toNat⟩ := by
  rcases List.mem_append.mp valid with member | atEnd
  · have position : s.pc=BitVec.ofNat 64 s.pc.toNat := by simp
    obtain ⟨offsetEq,lengthEq⟩ := simple_native_extent_unique s s.pc.toNat entry instruction member position decoded
    refine ⟨member,?_⟩
    cases entry with
    | mk offset length =>
      cases offsetEq
      cases lengthEq
      rfl
  · have position : s.pc=60 := by
      apply BitVec.eq_of_toNat_eq
      simpa only [List.mem_singleton] using atEnd
    exact False.elim (simple_native_end_no_decode s entry instruction position decoded)

theorem closed_decoded_extent_classification (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (valid : simpleClosedPC s.pc)
    (decoded : X86Path.decodeAt 0 native entry s=.ok instruction) :
    entry ∈ simpleDefinedExtents ∨ entry=⟨10,2⟩ := by
  obtain ⟨member,same⟩ := closed_decoded_extent s entry instruction valid decoded
  rw [same]
  have choices : s.pc.toNat=0 ∨ s.pc.toNat=3 ∨ s.pc.toNat=7 ∨ s.pc.toNat=10 ∨
      s.pc.toNat=12 ∨ s.pc.toNat=15 ∨ s.pc.toNat=17 ∨ s.pc.toNat=21 ∨
      s.pc.toNat=24 ∨ s.pc.toNat=26 ∨ s.pc.toNat=30 ∨ s.pc.toNat=33 ∨
      s.pc.toNat=35 ∨ s.pc.toNat=40 ∨ s.pc.toNat=44 ∨ s.pc.toNat=51 ∨ s.pc.toNat=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with h | h | h | h | h | h | h | h | h | h | h | h | h | h | h | h | h
  all_goals simp [h,simpleNativeLength,simpleDefinedExtents]

theorem closed_decodes_agree (s : X86.State) (first second : X86Path.Entry)
    (firstInstruction secondInstruction : X86.Instruction) (valid : simpleClosedPC s.pc)
    (firstDecoded : X86Path.decodeAt 0 native first s=.ok firstInstruction)
    (secondDecoded : X86Path.decodeAt 0 native second s=.ok secondInstruction) :
    first=second ∧ firstInstruction=secondInstruction := by
  have firstEq := (closed_decoded_extent s first firstInstruction valid firstDecoded).2
  have secondEq := (closed_decoded_extent s second secondInstruction valid secondDecoded).2
  have same := firstEq.trans secondEq.symm
  rw [← same] at secondDecoded
  exact ⟨same,Except.ok.inj (firstDecoded.symm.trans secondDecoded)⟩

theorem xor10_decoded_instruction (s : X86.State) (instruction : X86.Instruction)
    (decoded : X86Path.decodeAt 0 native ⟨10,2⟩ s=.ok instruction) :
    s.pc=10 ∧ instruction=.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12 := by
  have guarded := (decode_extent_constraints 0 native ⟨10,2⟩ s instruction decoded).1
  have position : s.pc=10 := by simpa using guarded
  have raw := decode_extent_reflects_raw 0 native ⟨10,2⟩ s instruction decoded
  change X86.decode (native.extract 10 12) s=.ok instruction at raw
  rw [native_decode10] at raw
  have next : s.pc+2=(12 : Word) := by rw [position]; rfl
  exact ⟨position,by simpa only [next] using (Except.ok.inj raw).symm⟩

theorem cmp12_decoded_instruction (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (position : s.pc=12)
    (decoded : X86Path.decodeAt 0 native entry s=.ok instruction) :
    instruction=.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15 := by
  obtain ⟨offsetEq,lengthEq⟩ := simple_native_extent_unique s 12 entry instruction (by decide) position decoded
  have same : entry=⟨12,3⟩ := by
    cases entry with
    | mk offset length => cases offsetEq; cases lengthEq; rfl
  have raw := decode_extent_reflects_raw 0 native entry s instruction decoded
  rw [same] at raw
  change X86.decode (native.extract 12 15) s=.ok instruction at raw
  rw [native_decode12] at raw
  have next : s.pc+3=(15 : Word) := by rw [position]; rfl
  simpa only [next] using (Except.ok.inj raw).symm

/-- All same-input native steps agree on events and related next states.
The actual XOR case retains every AF choice instead of forcing determinism. -/
theorem same_input_native_steps_couple (s : X86.State) (valid : simpleClosedPC s.pc)
    (firstEntry secondEntry : X86Path.Entry) (firstInstruction secondInstruction : X86.Instruction)
    (first second : Transition X86.State)
    (firstDecoded : X86Path.decodeAt 0 native firstEntry s=.ok firstInstruction)
    (secondDecoded : X86Path.decodeAt 0 native secondEntry s=.ok secondInstruction)
    (firstRun : X86.Step firstInstruction s first) (secondRun : X86.Step secondInstruction s second) :
    first.events=second.events ∧ nativeStatesRelated first.state second.state := by
  have closed := simple_native_relational_step_closed s firstEntry firstInstruction first valid firstDecoded firstRun
  obtain ⟨sameEntry,sameInstruction⟩ := closed_decodes_agree s firstEntry secondEntry
    firstInstruction secondInstruction valid firstDecoded secondDecoded
  subst secondEntry
  subst secondInstruction
  rcases closed_decoded_extent_classification s firstEntry firstInstruction valid firstDecoded with defined | xor
  · have firstExact := simple_defined_decoded_step_unique s firstEntry firstInstruction first defined firstDecoded firstRun
    have secondExact := simple_defined_decoded_step_unique s firstEntry firstInstruction second defined firstDecoded secondRun
    have same : first=second := firstExact.trans secondExact.symm
    refine ⟨congrArg Transition.events same,?_⟩
    rw [← same]
    exact native_states_related_refl first.state closed
  · subst firstEntry
    obtain ⟨_,instructionEq⟩ := xor10_decoded_instruction s firstInstruction firstDecoded
    rw [instructionEq] at firstRun secondRun
    let instruction : X86.Instruction := .logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12
    have normal : (X86.step instruction s).fault=none := rfl
    change X86.matchesTransition instruction (X86.step instruction s) first at firstRun
    change X86.matchesTransition instruction (X86.step instruction s) second at secondRun
    simp only [X86.matchesTransition,normal,Option.isSome,Bool.false_eq_true,ite_false,
      instruction,X86.definedFlags,X86.observedRegisters] at firstRun secondRun
    obtain ⟨firstEvents,_,firstState⟩ := firstRun
    obtain ⟨secondEvents,_,secondState⟩ := secondRun
    change afEquivalent (X86.step instruction s).state first.state at firstState
    change afEquivalent (X86.step instruction s).state second.state at secondState
    have sameMasked : afEquivalent first.state second.state := Eq.trans (Eq.symm firstState) secondState
    have at12 : first.state.pc=12 := (congrArg X86.State.pc firstState).symm
    refine ⟨firstEvents.symm.trans secondEvents,closed,?_⟩
    simpa [at12] using sameMasked

/-- Every actual step from related states has the same events and related
successors, including arbitrary accepted extents and all undefined AF values. -/
theorem related_native_steps_couple (firstState secondState : X86.State)
    (related : nativeStatesRelated firstState secondState)
    (firstEntry secondEntry : X86Path.Entry) (firstInstruction secondInstruction : X86.Instruction)
    (first second : Transition X86.State)
    (firstDecoded : X86Path.decodeAt 0 native firstEntry firstState=.ok firstInstruction)
    (secondDecoded : X86Path.decodeAt 0 native secondEntry secondState=.ok secondInstruction)
    (firstRun : X86.Step firstInstruction firstState first)
    (secondRun : X86.Step secondInstruction secondState second) :
    first.events=second.events ∧ nativeStatesRelated first.state second.state := by
  have valid := related.1
  by_cases at12 : firstState.pc=12
  · have masked : afEquivalent firstState secondState := by
      have branch := related.2
      rw [if_pos at12] at branch
      exact branch
    have shape := (af_equivalent_shape firstState secondState masked).1
    have samePC := congrArg X86.State.pc shape
    change secondState.pc=firstState.pc at samePC
    have secondPC : secondState.pc=12 := samePC.trans at12
    have firstInstructionEq := cmp12_decoded_instruction firstState firstEntry firstInstruction at12 firstDecoded
    have secondInstructionEq := cmp12_decoded_instruction secondState secondEntry secondInstruction secondPC secondDecoded
    rw [firstInstructionEq] at firstRun
    rw [secondInstructionEq] at secondRun
    have same := canonical_cmp12_relational_af_equivalent firstState secondState first second masked firstRun secondRun
    have closed := simple_native_relational_step_closed firstState firstEntry firstInstruction first valid firstDecoded
      (by simpa only [firstInstructionEq] using firstRun)
    refine ⟨congrArg Transition.events same,?_⟩
    rw [← same]
    exact native_states_related_refl first.state closed
  · have same : firstState=secondState := by
      have branch := related.2
      rw [if_neg at12] at branch
      exact branch
    subst secondState
    exact same_input_native_steps_couple firstState valid firstEntry secondEntry
      firstInstruction secondInstruction first second firstDecoded secondDecoded firstRun secondRun

theorem related_native_instruction_steps_match
    {firstState secondState firstNext secondNext : X86.State} {firstEvents secondEvents : List Event}
    (related : nativeStatesRelated firstState secondState)
    (firstStep : relationalNativeInstructionStep 0 native firstState firstEvents firstNext)
    (secondStep : relationalNativeInstructionStep 0 native secondState secondEvents secondNext) :
    firstEvents=secondEvents ∧ nativeStatesRelated firstNext secondNext := by
  obtain ⟨firstEntry,firstInstruction,first,firstDecoded,firstRun,firstTrace,firstStateEq⟩ := firstStep
  obtain ⟨secondEntry,secondInstruction,second,secondDecoded,secondRun,secondTrace,secondStateEq⟩ := secondStep
  obtain ⟨sameEvents,sameStates⟩ := related_native_steps_couple firstState secondState related
    firstEntry secondEntry firstInstruction secondInstruction first second firstDecoded secondDecoded firstRun secondRun
  refine ⟨firstTrace.symm.trans (sameEvents.trans secondTrace),?_⟩
  simpa only [firstStateEq,secondStateEq] using sameStates

end KProgTV.TrustedSimpleSafety

#print axioms KProgTV.TrustedSimpleSafety.initialization_projection_never_invents

#print axioms KProgTV.TrustedSimpleSafety.initialization_projected_events_checked

#print axioms KProgTV.TrustedSimpleSafety.bound_captured_selected_path_effects_checked

#print axioms KProgTV.TrustedSimpleSafety.execution_checked_related_terminal

#print axioms KProgTV.TrustedSimpleSafety.execution_checked_of_related_complete


#print axioms KProgTV.TrustedSimpleSafety.af_equivalent_shape

#print axioms KProgTV.TrustedSimpleSafety.compare_flags_ignore_AF

#print axioms KProgTV.TrustedSimpleSafety.canonical_cmp12_af_equivalent

#print axioms KProgTV.TrustedSimpleSafety.canonical_cmp12_relational_af_equivalent

#print axioms KProgTV.TrustedSimpleSafety.canonical_execution_relational

#print axioms KProgTV.TrustedSimpleSafety.canonical_relational_path_execution


#print axioms KProgTV.TrustedSimpleSafety.native_states_related_refl

#print axioms KProgTV.TrustedSimpleSafety.closed_decoded_extent

#print axioms KProgTV.TrustedSimpleSafety.closed_decoded_extent_classification

#print axioms KProgTV.TrustedSimpleSafety.closed_decodes_agree

#print axioms KProgTV.TrustedSimpleSafety.xor10_decoded_instruction

#print axioms KProgTV.TrustedSimpleSafety.cmp12_decoded_instruction

#print axioms KProgTV.TrustedSimpleSafety.same_input_native_steps_couple

#print axioms KProgTV.TrustedSimpleSafety.related_native_steps_couple

#print axioms KProgTV.TrustedSimpleSafety.related_native_instruction_steps_match
