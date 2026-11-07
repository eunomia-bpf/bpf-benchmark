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


/-- The existing representative first-guard evaluator certificate, exposed
for canonical path existence without constraining undefined AF choices. -/
theorem first_guard_path_evaluation (s : X86.State) (position : s.pc=7) :
    X86Path.evaluate 0 native [⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] s =
      .ok ⟨⟨guardFinal s,[],none⟩,(0xffffffffffffffef#64)⟩ := by
  have d0 : X86Path.decodeAt 0 native ⟨7,3⟩ s = .ok
      (.move .w64 (.register (.low 6)) (.register (.low 1)) 10) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode7,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have pc1 : (guardMove s).pc=10 := rfl
  have pc2 : (guardZero s).pc=12 := rfl
  have pc3 : (guardCompare s).pc=15 := rfl
  have d1 : X86Path.decodeAt 0 native ⟨10,2⟩ (guardMove s) = .ok
      (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode10,pc1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt 0 native ⟨12,3⟩ (guardZero s) = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode12,pc2,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d3 : X86Path.decodeAt 0 native ⟨15,2⟩ (guardCompare s) = .ok
      (.branch (some 7) 60 17) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode15,pc3,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  simp only [X86Path.evaluate,d0,d1,d2,d3,guard_move_step s position,
    guard_zero_step,guard_compare_step,guard_branch_step,X86.definedFlags,
    Option.isSome, Bool.false_eq_true, List.isEmpty_cons, List.isEmpty_nil,
    List.nil_append, ite_false]
  rfl


theorem guarded_native_path_exists (n : X86.State) (pointer limit : Word)
    (first second : Event) (position : n.pc=0)
    (read0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first))
    (read1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second)) :
    CanonicalRelationalPath 0 native (guardedNativePath n pointer limit) n
      ⟨guardedNativeFinal n pointer limit,[first,second],none⟩ := by
  have contextCertificate := context_native_path_evaluation n position
  have contextRun := canonical_evaluation_relational_sound _ _ _ _ _ contextCertificate
  simp only [contextNativePath,contextNativeResult,read0,read1] at contextRun
  have at7 : (nativePrefixFinal n pointer limit).pc=7 := by
    simp [nativePrefixFinal,nativeAfterSecond,nativeAfter,position]
  have firstCertificate := first_guard_path_evaluation (nativePrefixFinal n pointer limit) at7
  have firstRun := canonical_evaluation_relational_sound _ _ _ _ _ firstCertificate
  have combined := relational_path_append contextRun rfl firstRun
  have prefixRun : CanonicalRelationalPath 0 native
      [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] n
      ⟨guardFinal (nativePrefixFinal n pointer limit),[first,second],none⟩ := by
    simpa only [List.append_nil] using combined
  by_cases reject : pointer>limit
  · simpa only [guardedNativePath,guardedNativeFinal,reject,ite_true,List.append_nil] using prefixRun
  · have at17 : (guardFinal (nativePrefixFinal n pointer limit)).pc=17 := by
      simp +decide [guardFinal,nativePrefixFinal,nativeAfterSecond,nativeAfter,reject]
    have remainingCertificate := remaining_native_path_evaluation (guardFinal (nativePrefixFinal n pointer limit)) at17
    have remainingRun := canonical_evaluation_relational_sound _ _ _ _ _ remainingCertificate
    have whole := relational_path_append prefixRun rfl remainingRun
    simpa only [guardedNativePath,guardedNativeFinal,reject,ite_false,List.append_nil] using whole

theorem complete_native_path_exists (n : X86.State) (pointer limit : Word)
    (first second : Event) (position : n.pc=0)
    (read0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first))
    (read1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second)) :
    CanonicalRelationalPath 0 native (completeNativePath n pointer limit) n
      (completeNativeResult n pointer limit first second) := by
  have guards := guarded_native_path_exists n pointer limit first second position read0 read1
  by_cases reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit
  · simpa only [completeNativePath,completeNativeResult,completeNativeFinal,completeGuestSuffix,
      completeNativeFault,reject,ite_true,List.append_nil] using guards
  · obtain ⟨pc,pointerMatch,memoryMatch⟩ := guarded_native_body_boundary n pointer limit reject
    have selected : packetFirstFailure n.memory pointer =
        packetFirstFailure (guardedNativeFinal n pointer limit).memory
          ((guardedNativeFinal n pointer limit).gpr 1) := by rw [pointerMatch,memoryMatch]
    have bodyCertificate := packet_native_any_evaluation (guardedNativeFinal n pointer limit)
      (packetFirstFailure n.memory pointer) pc selected
    have bodyRun := canonical_evaluation_relational_sound _ _ _ _ _ bodyCertificate
    have whole := relational_path_append guards rfl bodyRun
    simpa only [completeNativePath,completeNativeResult,completeNativeFinal,completeGuestSuffix,
      completeNativeFault,reject,ite_false,pointerMatch] using whole

/-- A complete actual canonical relational path exists for every permission
assignment. Faults terminate, and no guest-access outcome is assumed. -/
theorem all_read_native_path_exists (n : X86.State) (position : n.pc=0) :
    CanonicalRelationalPath 0 native (allReadNativePath n) n (allReadNativeResult n) := by
  cases read0 : readMemory n.memory (n.gpr 7) 8 with
  | error fault =>
    have certificate := context_native_path_evaluation n position
    have contextRun := canonical_evaluation_relational_sound _ _ _ _ _ certificate
    simpa only [contextNativePath,contextNativeResult,allReadNativePath,allReadNativeResult,read0] using contextRun
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    cases read1 : readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | error fault =>
      have certificate := context_native_path_evaluation n position
      have contextRun := canonical_evaluation_relational_sound _ _ _ _ _ certificate
      simpa only [contextNativePath,contextNativeResult,allReadNativePath,allReadNativeResult,read0,read1] using contextRun
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      simpa only [allReadNativePath,allReadNativeResult,read0,read1] using
        complete_native_path_exists n pointer limit first second position read0 read1

theorem all_read_native_complete_execution (n : X86.State) (position : n.pc=0) :
    Execution (relationalNativeInstructionStep 0 native) n
      (allReadNativeResult n).events (allReadNativeResult n).state :=
  canonical_relational_path_execution (all_read_native_path_exists n position)


/-- Canonical MOV access faults preserve the entire input state. This is a
property of the existing reference transition, not an added native check. -/
theorem canonical_move_fault_stutters (s : X86.State) (width : X86.ScalarWidth)
    (destination : X86.ScalarDestination) (source : X86.ScalarSource) (next : Word) (fault : Fault)
    (bad : (X86.step (.move width destination source next) s).fault=some fault) :
    (X86.step (.move width destination source next) s).state=s := by
  change (X86.moveStep width destination source next s).fault=some fault at bad
  change (X86.moveStep width destination source next s).state=s
  cases read : X86.scalarRead s width source with
  | error reason => simp only [X86.moveStep,read]
  | ok pair =>
    rcases pair with ⟨value,events⟩
    cases write : X86.scalarWrite s width destination value with
    | error reason => simp only [X86.moveStep,read,write]
    | ok pair =>
      simp only [X86.moveStep,read,write] at bad
      cases bad

/-- A faulting actual instruction in this captured CFG stutters on full
architectural state, including every undefined-output observation. -/
theorem simple_native_fault_stutters (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (actual : Transition X86.State) (fault : Fault)
    (valid : simpleClosedPC s.pc) (decoded : X86Path.decodeAt 0 native entry s=.ok instruction)
    (run : X86.Step instruction s actual) (bad : actual.fault=some fault) : actual.state=s := by
  rcases closed_decoded_extent_classification s entry instruction valid decoded with defined | xor
  · have exactResult := simple_defined_decoded_step_unique s entry instruction actual defined decoded run
    rw [exactResult] at bad ⊢
    have raw := decode_extent_reflects_raw 0 native entry s instruction decoded
    simp only [simpleDefinedExtents,List.mem_cons,List.mem_singleton,List.not_mem_nil,or_false] at defined
    rcases defined with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
      rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
    · change X86.decode (native.extract 0 3) s=.ok instruction at raw
      rw [native_decode0] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 3 7) s=.ok instruction at raw
      rw [native_decode3] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 7 10) s=.ok instruction at raw
      rw [native_decode7] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 12 15) s=.ok instruction at raw
      rw [native_decode12] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 15 17) s=.ok instruction at raw
      rw [native_decode15] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 17 21) s=.ok instruction at raw
      rw [native_decode17] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 21 24) s=.ok instruction at raw
      rw [native_decode21] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 24 26) s=.ok instruction at raw
      rw [native_decode24] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 26 30) s=.ok instruction at raw
      rw [native_decode26] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 30 33) s=.ok instruction at raw
      rw [native_decode30] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 33 35) s=.ok instruction at raw
      rw [native_decode33] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 35 40) s=.ok instruction at raw
      rw [native_decode35] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 40 44) s=.ok instruction at raw
      rw [native_decode40] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 44 51) s=.ok instruction at raw
      rw [native_decode44] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 51 55) s=.ok instruction at raw
      rw [native_decode51] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)
    · change X86.decode (native.extract 55 60) s=.ok instruction at raw
      rw [native_decode55] at raw
      cases Except.ok.inj raw
      first
        | exact canonical_move_fault_stutters _ _ _ _ _ _ bad
        | (change none=some fault at bad; cases bad)

  · subst entry
    have instructionEq := (xor10_decoded_instruction s instruction decoded).2
    have observed := (canonical_relational_observed_fields instruction s actual run).2.2.2
    rw [instructionEq] at observed
    have normal : (X86.step (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12) s).fault=none := rfl
    rw [normal] at observed
    rw [observed] at bad
    cases bad

/-- A terminal fault in any actual canonical path supplies a real self-loop
step at that terminal state. Its loop events already occurred in the path. -/
theorem canonical_relational_terminal_fault_loop {entries : List X86Path.Entry}
    {s : X86.State} {actual : Transition X86.State}
    (run : CanonicalRelationalPath 0 native entries s actual)
    (valid : simpleClosedPC s.pc) (bad : actual.fault.isSome=true) :
    ∃ events, relationalNativeInstructionStep 0 native actual.state events actual.state ∧
      ∀ event ∈ events, event ∈ actual.events := by
  revert valid bad
  induction run with
  | nil state => intro _ bad; simp at bad
  | @fault before effect entry instruction decoded step failed =>
    intro valid bad
    cases fault : effect.fault with
    | none => simp only [fault,Option.isSome,Bool.false_eq_true] at failed
    | some reason =>
      have stutter := simple_native_fault_stutters before entry instruction effect reason valid decoded step fault
      refine ⟨effect.events,?_,fun _ inside => inside⟩
      rw [stutter]
      exact ⟨entry,instruction,effect,decoded,step,rfl,stutter⟩
  | @next before first rest tail entry instruction decoded step continued suffix ih =>
    intro valid bad
    have nextValid := simple_native_relational_step_closed before entry instruction first valid decoded step
    obtain ⟨events,loop,subset⟩ := ih nextValid bad
    exact ⟨events,loop,fun event inside => List.mem_append_right _ (subset event inside)⟩

theorem related_terminal_quiet_from_loop (checked : Event → Prop) (terminal : X86.State)
    (loopEvents : List Event)
    (loop : relationalNativeInstructionStep 0 native terminal loopEvents terminal)
    (allowed : ∀ event ∈ loopEvents, checked event) :
    ∀ {s events next}, nativeStatesRelated terminal s →
      relationalNativeInstructionStep 0 native s events next →
      nativeStatesRelated terminal next ∧ ∀ event ∈ events, checked event := by
  intro s events next relation actualStep
  obtain ⟨sameEvents,nextRelation⟩ := related_native_instruction_steps_match relation loop actualStep
  exact ⟨nextRelation,by simpa only [sameEvents] using allowed⟩

theorem related_terminal_quiet_from_fault_path (checked : Event → Prop)
    {entries : List X86Path.Entry} {s : X86.State} {actual : Transition X86.State}
    (run : CanonicalRelationalPath 0 native entries s actual)
    (valid : simpleClosedPC s.pc) (bad : actual.fault.isSome=true)
    (allowed : ∀ event ∈ actual.events, checked event) :
    ∀ {state events next}, nativeStatesRelated actual.state state →
      relationalNativeInstructionStep 0 native state events next →
      nativeStatesRelated actual.state next ∧ ∀ event ∈ events, checked event := by
  obtain ⟨events,loop,subset⟩ := canonical_relational_terminal_fault_loop run valid bad
  exact related_terminal_quiet_from_loop checked actual.state events loop
    (fun event inside => allowed event (subset event inside))

theorem related_payload_end_quiet (checked : Event → Prop) (terminal : X86.State)
    (atEnd : terminal.pc=60) :
    ∀ {state events next}, nativeStatesRelated terminal state →
      relationalNativeInstructionStep 0 native state events next →
      nativeStatesRelated terminal next ∧ ∀ event ∈ events, checked event := by
  intro state events next relation step
  have not12 : terminal.pc≠12 := by rw [atEnd]; decide
  have same : terminal=state := by
    have branch := relation.2
    rw [if_neg not12] at branch
    exact branch
  obtain ⟨entry,instruction,effect,decoded,_,_,_⟩ := step
  rw [← same] at decoded
  exact False.elim (simple_native_end_no_decode terminal entry instruction atEnd decoded)


/-- A successful captured guard return reaches the actual payload end. -/
theorem guarded_native_reject_end (n : X86.State) (pointer limit : Word)
    (reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit) :
    (guardedNativeFinal n pointer limit).pc=60 := by
  by_cases first : pointer>limit
  · simp only [guardedNativeFinal,first,ite_true]
    change (if pointer>limit then (60 : Word) else 17)=60
    exact if_pos first
  · simp only [guardedNativeFinal,first,ite_false]
    rw [remaining_native_successor]
    have reg6 : (guardFinal (nativePrefixFinal n pointer limit)).gpr 6=pointer := by
      simp +decide [guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,
        nativeAfterSecond,nativeAfter]
    have reg2 : (guardFinal (nativePrefixFinal n pointer limit)).gpr 2=limit := by
      simp +decide [guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,
        nativeAfterSecond,nativeAfter]
    rw [reg6,reg2,if_pos (reject.resolve_left first)]

/-- No-fault completion derives either a guard return or four successful
stores; it does not assume a packet-access outcome. -/
theorem complete_native_no_fault_end (n : X86.State) (pointer limit : Word)
    (first second : Event) (clean : (completeNativeResult n pointer limit first second).fault=none) :
    (completeNativeResult n pointer limit first second).state.pc=60 := by
  by_cases reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit
  · simpa only [completeNativeResult,completeNativeFinal,reject,ite_true] using
      guarded_native_reject_end n pointer limit reject
  · have success : packetFirstFailure n.memory pointer=4 := by
      by_cases success : packetFirstFailure n.memory pointer=4
      · exact success
      · simp only [completeNativeResult,completeNativeFault,reject,ite_false,success] at clean
        cases clean
    simp only [completeNativeResult,completeNativeFinal,reject,ite_false,packetNativeOutcome,
      success,ite_true,packetNativeFinal]

/-- Every complete no-fault outcome of the actual byte-decoded payload ends
at PC60, including both possible context read failures by contradiction. -/
theorem all_read_native_no_fault_end (n : X86.State)
    (clean : (allReadNativeResult n).fault=none) : (allReadNativeResult n).state.pc=60 := by
  cases read0 : readMemory n.memory (n.gpr 7) 8 with
  | error fault =>
    simp only [allReadNativeResult,read0] at clean
    cases clean
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    cases read1 : readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | error fault =>
      simp only [allReadNativeResult,read0,read1] at clean
      cases clean
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      simp only [allReadNativeResult,read0,read1] at clean ⊢
      exact complete_native_no_fault_end n pointer limit first second clean

/-- All finite decoded native executions, with arbitrary extents, permission
outcomes and undefined-output observations, inherit the checked complete
trace. Fault repeats allowed by the wrapper are covered as well. -/
theorem captured_native_prefix_effects_checked (checked : Event → Prop)
    (n : X86.State) (position : n.pc=0)
    (allowed : ∀ event ∈ (allReadNativeResult n).events, checked event)
    {trace : List Event} {last : X86.State}
    (run : Execution (relationalNativeInstructionStep 0 native) n trace last) :
    ∀ event ∈ trace, checked event := by
  have valid : simpleClosedPC n.pc := by simp [simpleClosedPC,simpleNativeOffsets,position]
  have complete := all_read_native_complete_execution n position
  have quiet : ∀ {state events next}, nativeStatesRelated (allReadNativeResult n).state state →
      relationalNativeInstructionStep 0 native state events next →
      nativeStatesRelated (allReadNativeResult n).state next ∧ ∀ event ∈ events, checked event := by
    intro state events next relation step
    cases outcome : (allReadNativeResult n).fault with
    | none => exact related_payload_end_quiet checked _ (all_read_native_no_fault_end n outcome) relation step
    | some fault =>
      have bad : (allReadNativeResult n).fault.isSome=true := by rw [outcome]; rfl
      exact related_terminal_quiet_from_fault_path checked (all_read_native_path_exists n position)
        valid bad allowed relation step
  exact execution_checked_of_related_complete nativeStatesRelated
    related_native_instruction_steps_match checked complete allowed quiet
    (native_states_related_refl n valid) run


/-- Verifier soundness for the exact bound compiled B image, the established
native-to-B correspondence, and full artifact binding imply checked events
for EVERY finite decoded native execution of the captured payload. Native
extent, access outcome, branch choice and undefined AF observations are not
caller supplied restrictions. Entry/ABI/platform transport remains explicit. -/
theorem bound_captured_native_prefix_effects_checked (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ artifact, accepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (boundCapturedProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    {trace : List Event} {last : X86.State}
    (run : Execution (relationalNativeInstructionStep (BitVec.ofNat 64 executed.entry)
      executed.nativeBytes.toArray) n trace last)
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
    ∀ event ∈ trace, checked validated event := by
  subst executed
  have canonicalRun : Execution (relationalNativeInstructionStep 0 native) n trace last := by
    simpa only [nativeImage,entryImage,Array.toArray_toList] using run
  have canonicalComplete := all_read_native_path_exists n nativePC
  have boundComplete : CanonicalRelationalPath (BitVec.ofNat 64 validated.entry)
      validated.nativeBytes.toArray (allReadNativePath n) n (allReadNativeResult n) := by
    simpa only [nativeImage,entryImage,Array.toArray_toList] using canonicalComplete
  have completeChecked := bound_captured_selected_path_effects_checked env n p validated validated rfl
    nativeImage proofImage entryImage accepted proofEntry checked verifierSound acceptance admitted
    (allReadNativeResult n) boundComplete stack nativePC proofPC active context memory nativeStack
    write40 write32 write24 write16 write8 read40 read32 guest0 guest1
  exact captured_native_prefix_effects_checked (checked validated) n nativePC completeChecked canonicalRun


/-- The supported SysV callee-saved GPRs and native SP, plus every modeled
vector/segment/address-width field used by invocation transport. Memory and
RFLAGS deliberately remain outside this ABI-frame projection. -/
def simpleABIFrame (s : X86.State) :=
  (s.gpr 3,s.gpr 4,s.gpr 5,s.gpr 12,s.gpr 13,s.gpr 14,s.gpr 15,
    s.xmm0,s.fsBase,s.gsBase,s.addressWidth)

/-- This projection ignores only the AF freedom already justified by the
captured native step relation; it does not erase any register value. -/
theorem native_related_same_abi_frame {first second : X86.State}
    (related : nativeStatesRelated first second) : simpleABIFrame second=simpleABIFrame first := by
  by_cases at12 : first.pc=12
  · have masked : afEquivalent first second := by
      have branch := related.2
      rw [if_pos at12] at branch
      exact branch
    obtain ⟨shape,_⟩ := af_equivalent_shape first second masked
    have projected := congrArg simpleABIFrame shape
    exact projected
  · have same : first=second := by
      have branch := related.2
      rw [if_neg at12] at branch
      exact branch
    exact congrArg simpleABIFrame same.symm

/-- The actual canonical decode and transition preserve the supported ABI
frame for every captured instruction, including all read/write fault outcomes. -/
theorem simple_native_canonical_abi_frame (s : X86.State) (offset : Nat)
    (member : offset ∈ simpleNativeOffsets) :
    match X86.decode (native.extract offset (offset+simpleNativeLength offset)) s with
    | .error _ => False
    | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s := by
  have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · change (match X86.decode (native.extract 0 3) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode0]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 3 7) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode3]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 7 10) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode7]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 10 12) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode10]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 12 15) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode12]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 15 17) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode15]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 17 21) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode17]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 21 24) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode21]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 24 26) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode24]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 26 30) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode26]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 30 33) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode30]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 33 35) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode33]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 35 40) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode35]
    cases permission : permitted s.memory.writable (s.gpr 1) 2
    all_goals simp +decide [permission,simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 40 44) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode40]
    cases permission : permitted s.memory.writable (s.gpr 1+(2#64)) 1
    all_goals simp +decide [permission,simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 44 51) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode44]
    cases permission : permitted s.memory.writable (s.gpr 1+(3#64)) 4
    all_goals simp +decide [permission,simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 51 55) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode51]
    cases permission : permitted s.memory.writable (s.gpr 1+(7#64)) 1
    all_goals simp +decide [permission,simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])
  · change (match X86.decode (native.extract 55 60) s with
      | .error _ => False
      | .ok instruction => simpleABIFrame (X86.step instruction s).state=simpleABIFrame s)
    rw [native_decode55]
    simp +decide [simpleABIFrame,X86.step,X86.moveStep,X86.arithmeticStep,X86.logicalStep,
      X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,X86.scalarRegisterValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
      X86.readSource,X86.ScalarDestination.source,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [simpleABIFrame,X86.scalarWriteValue,
      X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits])

/-- Actual undefined-output observations and arbitrary accepted extents
preserve exactly the same callee-save/SP/platform frame. -/
theorem simple_native_relational_abi_frame (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (actual : Transition X86.State)
    (valid : simpleClosedPC s.pc) (decoded : X86Path.decodeAt 0 native entry s=.ok instruction)
    (run : X86.Step instruction s actual) : simpleABIFrame actual.state=simpleABIFrame s := by
  obtain ⟨member,entryEq⟩ := closed_decoded_extent s entry instruction valid decoded
  have raw := decode_extent_reflects_raw 0 native entry s instruction decoded
  rw [entryEq] at raw
  have canonical := simple_native_canonical_abi_frame s s.pc.toNat member
  rw [raw] at canonical
  have representative : X86.Step instruction s (X86.step instruction s) := ⟨rfl,rfl,rfl⟩
  have related := (same_input_native_steps_couple s valid entry entry instruction instruction
    (X86.step instruction s) actual decoded decoded representative run).2
  exact (native_related_same_abi_frame related).trans canonical

/-- Every finite actual native prefix preserves the supported SysV GPR/SP
frame and modeled invocation configuration, including a faulting prefix. -/
theorem captured_native_prefix_abi_frame {n last : X86.State} {trace : List Event}
    (run : Execution (relationalNativeInstructionStep 0 native) n trace last)
    (valid : simpleClosedPC n.pc) : simpleABIFrame last=simpleABIFrame n := by
  revert valid
  induction run with
  | refl => intro _; rfl
  | @next s t u head tail step suffix ih =>
    intro valid
    obtain ⟨entry,instruction,actual,decoded,actualRun,_,stateEq⟩ := step
    have nextValid := simple_native_relational_step_closed s entry instruction actual valid decoded actualRun
    have frame := simple_native_relational_abi_frame s entry instruction actual valid decoded actualRun
    rw [stateEq] at nextValid frame
    exact (ih nextValid).trans frame


/-- An entry/invocation memory-layout obligation, with wrapping addresses.
This is not a new native or proof runtime check. -/
def packetReturnSlotApart (pointer stack : Word) : Prop :=
  ∀ i<8, ¬ ((stack+BitVec.ofNat 64 i)-pointer).toNat<8

/-- The four actual writes occupy byte subranges of the packet's first8B. -/
theorem packet_return_slot_subranges (pointer stack : Word)
    (apart : packetReturnSlotApart pointer stack) :
    (∀ i<8, ¬ ((stack+BitVec.ofNat 64 i)-pointer).toNat<2) ∧
    (∀ i<8, ¬ ((stack+BitVec.ofNat 64 i)-(pointer+(2#64))).toNat<1) ∧
    (∀ i<8, ¬ ((stack+BitVec.ofNat 64 i)-(pointer+(3#64))).toNat<4) ∧
    (∀ i<8, ¬ ((stack+BitVec.ofNat 64 i)-(pointer+(7#64))).toNat<1) := by
  have sub2 (a p : Word) (inside : (a-(p+(2#64))).toNat<1) : (a-p).toNat<8 := by
    have lower : a-(p+(2#64)) < (1#64) := by simpa only [BitVec.lt_def] using inside
    have upper : a-p < (8#64) := by
      unfold Word at *
      bv_decide
    simpa only [BitVec.lt_def] using upper
  have sub3 (a p : Word) (inside : (a-(p+(3#64))).toNat<4) : (a-p).toNat<8 := by
    have lower : a-(p+(3#64)) < (4#64) := by simpa only [BitVec.lt_def] using inside
    have upper : a-p < (8#64) := by
      unfold Word at *
      bv_decide
    simpa only [BitVec.lt_def] using upper
  have sub7 (a p : Word) (inside : (a-(p+(7#64))).toNat<1) : (a-p).toNat<8 := by
    have lower : a-(p+(7#64)) < (1#64) := by simpa only [BitVec.lt_def] using inside
    have upper : a-p < (8#64) := by
      unfold Word at *
      bv_decide
    simpa only [BitVec.lt_def] using upper
  refine ⟨?_,?_,?_,?_⟩
  · intro i small inside
    exact apart i small (by omega)
  · intro i small inside
    exact apart i small (sub2 _ _ inside)
  · intro i small inside
    exact apart i small (sub3 _ _ inside)
  · intro i small inside
    exact apart i small (sub7 _ _ inside)

/-- Every successful or first-fault packet-write outcome preserves the
entire return-slot read, including permissions, bytes and initialization. -/
theorem packet_native_outcome_return_slot (s : X86.State) (index : Nat) (stack : Word)
    (apart : packetReturnSlotApart (s.gpr 1) stack) :
    readMemory (packetNativeOutcome s index).memory stack 8=readMemory s.memory stack 8 := by
  obtain ⟨apart0,apart2,apart3,apart7⟩ := packet_return_slot_subranges (s.gpr 1) stack apart
  have one : readMemory (packetNativeFirst s).memory stack 8=readMemory s.memory stack 8 :=
    PrivateSpills.read_disjoint_store s.memory (s.gpr 1) (24910#64) stack 2 8 apart0
  have two : readMemory (packetNativeSecond s).memory stack 8=readMemory s.memory stack 8 :=
    (PrivateSpills.read_disjoint_store (packetNativeFirst s).memory (s.gpr 1+(2#64))
      (188#64) stack 1 8 apart2).trans one
  have three : readMemory (packetNativeThird s).memory stack 8=readMemory s.memory stack 8 :=
    (PrivateSpills.read_disjoint_store (packetNativeSecond s).memory (s.gpr 1+(3#64))
      (0#64) stack 4 8 apart3).trans two
  have four : readMemory (packetNativeFourth s).memory stack 8=readMemory s.memory stack 8 :=
    (PrivateSpills.read_disjoint_store (packetNativeThird s).memory (s.gpr 1+(7#64))
      (0#64) stack 1 8 apart7).trans three
  by_cases success : index=4
  · simpa only [packetNativeOutcome,success,ite_true,packetNativeFinal] using four
  · simp only [packetNativeOutcome,success,ite_false]
    cases index with
    | zero => rfl
    | succ index =>
      cases index with
      | zero => exact one
      | succ index =>
        cases index with
        | zero => exact two
        | succ index => exact three

/-- The guard region never changes memory, its packet pointer or native SP.
These are consequences of the concrete captured operations. -/
theorem guarded_native_return_slot_frame (n : X86.State) (pointer limit : Word) :
    (guardedNativeFinal n pointer limit).gpr 1=pointer ∧
    (guardedNativeFinal n pointer limit).gpr 4=n.gpr 4 ∧
    (guardedNativeFinal n pointer limit).memory=n.memory := by
  by_cases first : pointer>limit
  · simp +decide [guardedNativeFinal,first,guardFinal,guardCompare,guardZero,guardMove,
      nativePrefixFinal,nativeAfterSecond,nativeAfter]
  · by_cases second : pointer+(8#64)>limit <;>
      simp +decide [guardedNativeFinal,first,second,guardFinal,guardCompare,guardZero,guardMove,
        nativePrefixFinal,nativeAfterSecond,nativeAfter,remainingNativeFinal,
        remainingNative8,remainingNativeCmp8,remainingNativeLea,
        remainingNative72,remainingNativeCmp72,remainingNativeAdd]

theorem complete_native_return_slot (n : X86.State) (pointer limit : Word)
    (first second : Event) (apart : packetReturnSlotApart pointer (n.gpr 4)) :
    readMemory (completeNativeResult n pointer limit first second).state.memory (n.gpr 4) 8=
      readMemory n.memory (n.gpr 4) 8 := by
  obtain ⟨pointerMatch,_,memoryMatch⟩ := guarded_native_return_slot_frame n pointer limit
  by_cases reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit
  · simp only [completeNativeResult,completeNativeFinal,reject,ite_true,memoryMatch]
  · have guardedApart : packetReturnSlotApart ((guardedNativeFinal n pointer limit).gpr 1) (n.gpr 4) := by
      rw [pointerMatch]
      exact apart
    have unchanged := packet_native_outcome_return_slot (guardedNativeFinal n pointer limit)
      (packetFirstFailure n.memory pointer) (n.gpr 4) guardedApart
    simpa only [completeNativeResult,completeNativeFinal,reject,ite_false,memoryMatch] using unchanged

/-- The actual context read determines the packet pointer in the entry-layout
premise. No read success or write outcome is assumed by this total theorem. -/
theorem all_read_native_return_slot (n : X86.State)
    (apart : ∀ pointer event, readMemory n.memory (n.gpr 7) 8=.ok (pointer,event) →
      packetReturnSlotApart pointer (n.gpr 4)) :
    readMemory (allReadNativeResult n).state.memory (n.gpr 4) 8=readMemory n.memory (n.gpr 4) 8 := by
  cases read0 : readMemory n.memory (n.gpr 7) 8 with
  | error fault => simp only [allReadNativeResult,read0]
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    cases read1 : readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | error fault => simp only [allReadNativeResult,read0,read1,nativeAfter]
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      simp only [allReadNativeResult,read0,read1]
      exact complete_native_return_slot n pointer limit first second (apart pointer first read0)

/-- Every full canonical relational outcome has the same native return-slot
read as entry; the callee-save certificate derives SP identity as well. -/
theorem captured_native_return_slot_read (n : X86.State) (actual : Transition X86.State)
    (position : n.pc=0)
    (run : CanonicalRelationalPath 0 native (allReadNativePath n) n actual)
    (apart : ∀ pointer event, readMemory n.memory (n.gpr 7) 8=.ok (pointer,event) →
      packetReturnSlotApart pointer (n.gpr 4)) :
    readMemory actual.state.memory (actual.state.gpr 4) 8=readMemory n.memory (n.gpr 4) 8 := by
  have valid : simpleClosedPC n.pc := by simp [simpleClosedPC,simpleNativeOffsets,position]
  have saved := captured_native_prefix_abi_frame (canonical_relational_path_execution run) valid
  have stack := congrArg (fun frame => frame.2.1) saved
  change actual.state.gpr 4=n.gpr 4 at stack
  have exactResult := all_read_native_relational_result n actual position run
  rw [stack,exactResult]
  exact all_read_native_return_slot n apart


/-- Original immutable ELF entry certified by check_trusted_capture.py:
exact captured payload plus the terminal RET byte, not a new emitted program. -/
def originalNative : Array Byte := native ++ #[0xc3]

theorem original_native_size : originalNative.size=61 := rfl

/-- Appending the original RET cannot change any accepted payload extent. -/
theorem original_native_payload_extract (entry : X86Path.Entry)
    (inside : entry.offset+entry.length≤native.size) :
    originalNative.extract entry.offset (entry.offset+entry.length)=
      native.extract entry.offset (entry.offset+entry.length) := by
  have low : entry.offset-native.size=0 := by omega
  have high : entry.offset+entry.length-native.size=0 := by omega
  unfold originalNative
  rw [Array.extract_append]
  simp [low,high]

/-- Exact instruction/PC/extent transport into the original ELF entry. -/
theorem original_native_payload_decode (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (decoded : X86Path.decodeAt 0 native entry s=.ok instruction) :
    X86Path.decodeAt 0 originalNative entry s=.ok instruction := by
  have inside := (decode_extent_constraints 0 native entry s instruction decoded).2.2.2.1
  have same := original_native_payload_extract entry inside
  have before : ¬ native.size<entry.offset+entry.length := by omega
  have after : ¬ originalNative.size<entry.offset+entry.length := by
    change ¬ 61<entry.offset+entry.length
    change entry.offset+entry.length≤60 at inside
    omega
  unfold X86Path.decodeAt at decoded ⊢
  rw [same]
  simpa only [before,after,ite_false] using decoded

/-- Every canonical relational payload path has identical state, effects and
fault in the original ELF, with the same actual instruction extent list. -/
theorem original_native_payload_path {entries : List X86Path.Entry} {s : X86.State}
    {actual : Transition X86.State} (run : CanonicalRelationalPath 0 native entries s actual) :
    CanonicalRelationalPath 0 originalNative entries s actual := by
  induction run with
  | nil state => exact .nil state
  | fault entry instruction decoded step failed =>
    exact .fault entry instruction (original_native_payload_decode _ _ _ decoded) step failed
  | next entry instruction decoded step continued suffix ih =>
    exact .next entry instruction (original_native_payload_decode _ _ _ decoded) step continued ih

/-- The real terminal byte is decoded by the single canonical x86 decoder. -/
theorem original_native_ret_decode (s : X86.State) :
    X86.decode (originalNative.extract 60 61) s=.ok (.returnNear (0#16) (s.pc+1)) := by
  have bytes : originalNative.extract 60 61=#[0xc3] := by decide
  rw [bytes]
  canonical_x86_decode

theorem original_native_ret_at (s : X86.State) (position : s.pc=60) :
    X86Path.decodeAt 0 originalNative ⟨60,1⟩ s=.ok (.returnNear (0#16) 61) := by
  simp +decide [X86Path.decodeAt,original_native_size,original_native_ret_decode,position,
    X86Path.fallthrough,X86.Instruction.fallthrough,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Compose existing reference transitions, retaining RET's read and faults.
A fault in the body stops before RET, as required by canonical execution. -/
def originalNativePath (n : X86.State) : List X86Path.Entry :=
  allReadNativePath n ++ if (allReadNativeResult n).fault.isSome then [] else [⟨60,1⟩]

def originalNativeResult (n : X86.State) : Transition X86.State :=
  let body := allReadNativeResult n
  if body.fault.isSome then body
  else let ret := X86.step (.returnNear (0#16) 61) body.state
       ⟨ret.state,body.events++ret.events,ret.fault⟩

/-- The original immutable61B entry has an actual complete relational path
for EVERY guest permission outcome, including terminal RET read/canonicality
faults. No successful-return, packet-separation or valid-stack premise. -/
theorem original_native_complete_path_exists (n : X86.State) (position : n.pc=0) :
    CanonicalRelationalPath 0 originalNative (originalNativePath n) n (originalNativeResult n) := by
  have body := original_native_payload_path (all_read_native_path_exists n position)
  cases outcome : (allReadNativeResult n).fault with
  | some fault =>
    simpa only [originalNativePath,originalNativeResult,outcome,Option.isSome,ite_true,
      List.append_nil] using body
  | none =>
    have atEnd := all_read_native_no_fault_end n outcome
    have decoded := original_native_ret_at (allReadNativeResult n).state atEnd
    let instruction : X86.Instruction := .returnNear (0#16) 61
    let effect := X86.step instruction (allReadNativeResult n).state
    have step : X86.Step instruction (allReadNativeResult n).state effect := ⟨rfl,rfl,rfl⟩
    have terminal : CanonicalRelationalPath 0 originalNative [⟨60,1⟩]
        (allReadNativeResult n).state effect := by
      cases retFault : effect.fault with
      | some fault =>
        exact .fault ⟨60,1⟩ instruction decoded step (by rw [retFault]; rfl)
      | none =>
        have one := CanonicalRelationalPath.next ⟨60,1⟩ instruction decoded step retFault
          (CanonicalRelationalPath.nil effect.state)
        have effectEq : (⟨effect.state,effect.events,none⟩ : Transition X86.State)=effect := by
          calc
            _ = ⟨effect.state,effect.events,effect.fault⟩ := by rw [retFault]
            _ = effect := rfl
        simpa only [List.append_nil,effectEq] using one
    have combined := relational_path_append body outcome terminal
    simpa only [originalNativePath,originalNativeResult,outcome,Option.isSome,ite_false,
      instruction,effect] using combined


/-- A valid invocation's original return target and exact read survive the
body. The extra RET read is retained, not reclassified as an erased B spill.
Body faults still terminate before RET. -/
theorem original_native_invocation_return (n : X86.State) (position : n.pc=0)
    (target : Word) (event : Event)
    (entryRead : readMemory n.memory (n.gpr 4) 8=.ok (target,event))
    (canonical : X86.canonicalTarget n.addressWidth target=true)
    (apart : ∀ pointer read, readMemory n.memory (n.gpr 7) 8=.ok (pointer,read) →
      packetReturnSlotApart pointer (n.gpr 4)) :
    originalNativeResult n =
      if (allReadNativeResult n).fault.isSome then allReadNativeResult n
      else ⟨{ (allReadNativeResult n).state with
        gpr := fun r => if r=4 then n.gpr 4+(8#64) else (allReadNativeResult n).state.gpr r,
        pc := target },(allReadNativeResult n).events++[event],none⟩ := by
  have body := all_read_native_path_exists n position
  have valid : simpleClosedPC n.pc := by simp [simpleClosedPC,simpleNativeOffsets,position]
  have frame := captured_native_prefix_abi_frame (canonical_relational_path_execution body) valid
  have stack := congrArg (fun saved => saved.2.1) frame
  change (allReadNativeResult n).state.gpr 4=n.gpr 4 at stack
  have width := congrArg (fun saved => saved.2.2.2.2.2.2.2.2.2.2) frame
  change (allReadNativeResult n).state.addressWidth=n.addressWidth at width
  have unchanged := captured_native_return_slot_read n (allReadNativeResult n) position body apart
  have retained : readMemory (allReadNativeResult n).state.memory
      ((allReadNativeResult n).state.gpr 4) 8=.ok (target,event) := unchanged.trans entryRead
  have retainedEntry : readMemory (allReadNativeResult n).state.memory
      (n.gpr 4) 8=.ok (target,event) := by simpa only [stack] using retained
  by_cases failed : (allReadNativeResult n).fault.isSome=true
  · simp only [originalNativeResult,failed,ite_true]
  · simp [originalNativeResult,failed,X86.step,X86.returnStep,stack,width,retainedEntry,canonical]


/-- A change of code-address origin only. No register or memory address is
translated, and architectural PC addition retains64-bit wrapping semantics. -/
def shiftNativeState (base : Word) (s : X86.State) : X86.State := {s with pc := base+s.pc}

def shiftNativeTransition (base : Word) (effect : Transition X86.State) : Transition X86.State :=
  {effect with state := shiftNativeState base effect.state}

/-- Every actual captured instruction commutes with a code-origin shift.
Both instructions are decoded from the same immutable bytes by the canonical
ISA, rather than selected by a separate instruction semantics. Full states,
ordered events and faults agree after shifting only the resulting PC. -/
theorem simple_native_canonical_code_shift (base : Word) (s : X86.State) (offset : Nat)
    (member : offset ∈ simpleNativeOffsets) :
    match X86.decode (native.extract offset (offset+simpleNativeLength offset)) s,
        X86.decode (native.extract offset (offset+simpleNativeLength offset)) (shiftNativeState base s) with
    | .ok instruction,.ok shifted =>
        X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
    | _,_ => False := by
  have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · change (match X86.decode (native.extract 0 3) s,
        X86.decode (native.extract 0 3) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode0,native_decode0]
    cases read : readMemory s.memory (s.gpr 7) 8
    all_goals simp +decide [read,shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 3 7) s,
        X86.decode (native.extract 3 7) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode3,native_decode3]
    cases read : readMemory s.memory (s.gpr 7+(8#64)) 8
    all_goals simp +decide [read,shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 7 10) s,
        X86.decode (native.extract 7 10) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode7,native_decode7]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 10 12) s,
        X86.decode (native.extract 10 12) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode10,native_decode10]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 12 15) s,
        X86.decode (native.extract 12 15) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode12,native_decode12]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 15 17) s,
        X86.decode (native.extract 15 17) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode15,native_decode15]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 17 21) s,
        X86.decode (native.extract 17 21) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode17,native_decode17]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 21 24) s,
        X86.decode (native.extract 21 24) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode21,native_decode21]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 24 26) s,
        X86.decode (native.extract 24 26) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode24,native_decode24]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 26 30) s,
        X86.decode (native.extract 26 30) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode26,native_decode26]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 30 33) s,
        X86.decode (native.extract 30 33) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode30,native_decode30]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 33 35) s,
        X86.decode (native.extract 33 35) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode33,native_decode33]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 35 40) s,
        X86.decode (native.extract 35 40) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode35,native_decode35]
    cases permission : permitted s.memory.writable (s.gpr 1) 2
    all_goals simp +decide [permission,shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 40 44) s,
        X86.decode (native.extract 40 44) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode40,native_decode40]
    cases permission : permitted s.memory.writable (s.gpr 1+(2#64)) 1
    all_goals simp +decide [permission,shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 44 51) s,
        X86.decode (native.extract 44 51) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode44,native_decode44]
    cases permission : permitted s.memory.writable (s.gpr 1+(3#64)) 4
    all_goals simp +decide [permission,shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 51 55) s,
        X86.decode (native.extract 51 55) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode51,native_decode51]
    cases permission : permitted s.memory.writable (s.gpr 1+(7#64)) 1
    all_goals simp +decide [permission,shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])
  · change (match X86.decode (native.extract 55 60) s,
        X86.decode (native.extract 55 60) (shiftNativeState base s) with
      | .ok instruction,.ok shifted =>
          X86.step shifted (shiftNativeState base s)=shiftNativeTransition base (X86.step instruction s)
      | _,_ => False)
    rw [native_decode55,native_decode55]
    all_goals simp +decide [shiftNativeState,shiftNativeTransition,X86.step,
      X86.moveStep,X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,
      X86.scalarWriteValue,X86.scalarRegisterValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
      X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.readSource,X86.ScalarDestination.source,
      writeMemory,BitVec.add_assoc,Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all +decide [shiftNativeState,shiftNativeTransition,
      X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,
      BitVec.add_assoc])


/-- Arbitrary real code bases cannot authorize another payload start/length.
Extent uniqueness uses canonical consumption and bounded native byte offsets,
including any wrapping code-address arithmetic. -/
theorem simple_native_based_extent_unique (base : Word) (s : X86.State) (offset : Nat)
    (entry : X86Path.Entry) (instruction : X86.Instruction)
    (member : offset ∈ simpleNativeOffsets) (position : s.pc=base+BitVec.ofNat 64 offset)
    (accepted : X86Path.decodeAt base native entry s=.ok instruction) :
    entry.offset=offset ∧ entry.length=simpleNativeLength offset := by
  obtain ⟨pc,positive,bounded,inside,fall⟩ := decode_extent_constraints base native entry s instruction accepted
  obtain ⟨offsetBound,_,lengthBound⟩ := simple_native_metadata_bounds offset member
  have starts : base+BitVec.ofNat 64 entry.offset=base+BitVec.ofNat 64 offset := pc.symm.trans position
  have words : BitVec.ofNat 64 entry.offset=BitVec.ofNat 64 offset :=
    (BitVec.add_right_inj base).mp starts
  have nats := congrArg BitVec.toNat words
  change entry.offset % 18446744073709551616=offset % 18446744073709551616 at nats
  have codeBound : entry.offset+entry.length≤60 := inside
  have start : entry.offset=offset := by omega
  have raw := decode_extent_reflects_raw base native entry s instruction accepted
  have projected : decodedNativeFallthrough s (native.extract offset (offset+entry.length))=
      some (X86.Instruction.fallthrough instruction) := by
    rw [← start]
    unfold decodedNativeFallthrough
    rw [raw]
  have shape := simple_native_decode_length_shape s offset entry.length member bounded
  rw [projected] at shape
  by_cases truncated : entry.length<simpleNativeLength offset
  · simp only [truncated,ite_true] at shape
    cases shape
  · simp only [truncated,ite_false] at shape
    have sameFall := Option.some.inj shape
    have sameSum : s.pc+BitVec.ofNat 64 entry.length=s.pc+BitVec.ofNat 64 (simpleNativeLength offset) :=
      fall.symm.trans sameFall
    have lengths : BitVec.ofNat 64 entry.length=BitVec.ofNat 64 (simpleNativeLength offset) :=
      (BitVec.add_right_inj s.pc).mp sameSum
    have sizes := congrArg BitVec.toNat lengths
    change entry.length % 18446744073709551616=(simpleNativeLength offset) % 18446744073709551616 at sizes
    exact ⟨start,by omega⟩

/-- The payload end has no accepted instruction extent at any real base. -/
theorem simple_native_based_end_no_decode (base : Word) (s : X86.State)
    (entry : X86Path.Entry) (instruction : X86.Instruction) (position : s.pc=base+(60#64))
    (accepted : X86Path.decodeAt base native entry s=.ok instruction) : False := by
  obtain ⟨pc,positive,_,inside,_⟩ := decode_extent_constraints base native entry s instruction accepted
  have starts : base+BitVec.ofNat 64 entry.offset=base+(60#64) := pc.symm.trans position
  have words : BitVec.ofNat 64 entry.offset=(60#64) := (BitVec.add_right_inj base).mp starts
  have nats := congrArg BitVec.toNat words
  change entry.offset % 18446744073709551616=60 at nats
  have codeBound : entry.offset+entry.length≤60 := inside
  omega

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


#print axioms KProgTV.TrustedSimpleSafety.first_guard_path_evaluation

#print axioms KProgTV.TrustedSimpleSafety.guarded_native_path_exists

#print axioms KProgTV.TrustedSimpleSafety.complete_native_path_exists

#print axioms KProgTV.TrustedSimpleSafety.all_read_native_path_exists

#print axioms KProgTV.TrustedSimpleSafety.all_read_native_complete_execution


#print axioms KProgTV.TrustedSimpleSafety.canonical_move_fault_stutters

#print axioms KProgTV.TrustedSimpleSafety.simple_native_fault_stutters

#print axioms KProgTV.TrustedSimpleSafety.canonical_relational_terminal_fault_loop

#print axioms KProgTV.TrustedSimpleSafety.related_terminal_quiet_from_loop

#print axioms KProgTV.TrustedSimpleSafety.related_terminal_quiet_from_fault_path

#print axioms KProgTV.TrustedSimpleSafety.related_payload_end_quiet

#print axioms KProgTV.TrustedSimpleSafety.guarded_native_reject_end

#print axioms KProgTV.TrustedSimpleSafety.complete_native_no_fault_end

#print axioms KProgTV.TrustedSimpleSafety.all_read_native_no_fault_end

#print axioms KProgTV.TrustedSimpleSafety.captured_native_prefix_effects_checked

#print axioms KProgTV.TrustedSimpleSafety.bound_captured_native_prefix_effects_checked

#print axioms KProgTV.TrustedSimpleSafety.native_related_same_abi_frame

#print axioms KProgTV.TrustedSimpleSafety.simple_native_canonical_abi_frame

#print axioms KProgTV.TrustedSimpleSafety.simple_native_relational_abi_frame

#print axioms KProgTV.TrustedSimpleSafety.captured_native_prefix_abi_frame

#print axioms KProgTV.TrustedSimpleSafety.packet_return_slot_subranges

#print axioms KProgTV.TrustedSimpleSafety.packet_native_outcome_return_slot

#print axioms KProgTV.TrustedSimpleSafety.guarded_native_return_slot_frame

#print axioms KProgTV.TrustedSimpleSafety.complete_native_return_slot

#print axioms KProgTV.TrustedSimpleSafety.all_read_native_return_slot

#print axioms KProgTV.TrustedSimpleSafety.captured_native_return_slot_read

#print axioms KProgTV.TrustedSimpleSafety.original_native_payload_extract

#print axioms KProgTV.TrustedSimpleSafety.original_native_payload_decode

#print axioms KProgTV.TrustedSimpleSafety.original_native_payload_path

#print axioms KProgTV.TrustedSimpleSafety.original_native_ret_decode

#print axioms KProgTV.TrustedSimpleSafety.original_native_ret_at

#print axioms KProgTV.TrustedSimpleSafety.original_native_complete_path_exists

#print axioms KProgTV.TrustedSimpleSafety.original_native_invocation_return

#print axioms KProgTV.TrustedSimpleSafety.simple_native_canonical_code_shift

#print axioms KProgTV.TrustedSimpleSafety.simple_native_based_extent_unique

#print axioms KProgTV.TrustedSimpleSafety.simple_native_based_end_no_decode
