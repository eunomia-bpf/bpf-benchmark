import TrustedSimpleB29Observer

/-! Basic-block boundary packaging for the actual simple P60/B29 pair.
All instruction behavior is imported from the single canonical reference;
these definitions select captured CFG extents and retain ghost snapshots. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleB29Blocks
open KProgFormal.Reference TrustedSimpleX86 TrustedSimpleB29 TrustedSimpleB29State

structure NativeState where
  cpu : X86.State
  stopped : Bool

def nativeAfterBlock (actual : Transition X86.State) : NativeState :=
  ⟨actual.state,actual.fault.isSome⟩

/-- A first context fault ends the block at that actual failed instruction.
No new memory access is executed by this logical CFG selection. -/
def firstPath (s : X86.State) : List X86Path.Entry :=
  match readMemory s.memory (s.gpr 7) 8 with
  | .error _ => [⟨0,3⟩]
  | .ok _ => match readMemory s.memory (s.gpr 7+(8#64)) 8 with
    | .error _ => [⟨0,3⟩,⟨3,4⟩]
    | .ok _ => [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩]

/-- Actual byte-decoded native blocks, including a partial block ending at
its first fault. A real branch determines the next CPU PC; fault stops the
block CFG. Arbitrary instruction-prefix safety is proved separately. -/
def blockPath (s : X86.State) : List X86Path.Entry :=
  if s.pc=0 then firstPath s
  else if s.pc=17 then [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩]
  else if s.pc=26 then [⟨26,4⟩,⟨30,3⟩,⟨33,2⟩]
  else packetNativeOutcomePath (packetFirstFailure s.memory (s.gpr 1))

def nativeBlockImage (base : Word) (bytes : Array Byte) : BlockStep NativeState := fun before events after =>
  before.stopped=false ∧ before.cpu.pc ∈ [0,17,26,35] ∧
    ∃ actual, CanonicalRelationalPath base bytes (blockPath before.cpu) before.cpu actual ∧
      events=actual.events ∧ after=nativeAfterBlock actual

def nativeBlock : BlockStep NativeState := nativeBlockImage 0 native

def boundNativeBlock (artifact : Artifact) : BlockStep NativeState :=
  nativeBlockImage (BitVec.ofNat 64 artifact.entry) artifact.nativeBytes.toArray

/-- Boundary tags preserve branch history at shared B exits. The sole killed
value saved at store entry is the actual incoming B r1; all untouched native
fields are immutable invocation parameters, never a native successor oracle. -/
inductive ProofState where
  | initial (entry : X86.State) (cpu : BPF.State)
  | dataFault (entry : X86.State) (cpu : BPF.State)
  | endFault (entry : X86.State) (cpu : BPF.State)
  | first (entry : X86.State) (cpu : BPF.State)
  | second (entry : X86.State) (cpu : BPF.State)
  | third (entry : X86.State) (cpu : BPF.State)
  | stored (entry : X86.State) (limit : Word) (cpu : BPF.State)

def physical : ProofState → BPF.State
  | .initial _ p | .dataFault _ p | .endFault _ p | .first _ p | .second _ p |
      .third _ p | .stored _ _ p => p

def architecture : ProofState → X86.State
  | .initial entry _ => entry
  | .dataFault entry p => firstReadFaultView entry p
  | .endFault entry p => secondReadFaultView entry p
  | .first entry p => firstGuardView entry p
  | .second entry p => secondGuardView entry p
  | .third entry p => thirdGuardView entry p
  | .stored entry limit p => storeView entry limit p

def stopped : ProofState → Bool
  | .dataFault _ _ | .endFault _ _ => true
  | .stored _ _ p => p.pc != 27
  | _ => false

def invariant (env : BPF.Environment) : ProofState → Prop
  | .initial entry p => entry.pc=0 ∧ p.pc=0 ∧ p.halted=false ∧ entry.gpr 7=p.regs 1 ∧
      entry.memory=p.memory ∧ ∃ stack, env.nativeInput .stackPointer=.ok stack
  | .first _ p => (p.pc=5 ∨ p.pc=27) ∧ p.halted=false
  | .second _ p => (p.pc=8 ∨ p.pc=27) ∧ p.halted=false ∧ p.regs 3=p.regs 2+(8#64)
  | .third _ p => (p.pc=11 ∨ p.pc=27) ∧ p.halted=false ∧ p.regs 3=p.regs 2+(72#64)
  | .stored _ _ p => p.pc=27 ∨ p.pc=15 ∨ p.pc=19 ∨ p.pc=22 ∨ p.pc=25
  | _ => True

def related (env : BPF.Environment) (n : NativeState) (p : ProofState) : Prop :=
  n.cpu=architecture p ∧ n.stopped=stopped p ∧ invariant env p

/-- Every macro step contains a real accepted B29 execution. Tags merely
name native block boundaries; storing end copies only incoming actual r1. -/
inductive proofBlock (env : BPF.Environment) : BlockStep ProofState where
  | dataFault {entry p q events} : Execution (instructionStep env) p events q →
      proofBlock env (.initial entry p) events (.dataFault entry q)
  | endFault {entry p q events} : Execution (instructionStep env) p events q →
      proofBlock env (.initial entry p) events (.endFault entry q)
  | first {entry p q events} : Execution (instructionStep env) p events q →
      proofBlock env (.initial entry p) events (.first entry q)
  | second {entry p q events} : Execution (instructionStep env) p events q →
      proofBlock env (.first entry p) events (.second entry q)
  | third {entry p q events} : Execution (instructionStep env) p events q →
      proofBlock env (.second entry p) events (.third entry q)
  | stored {entry p q events} : Execution (instructionStep env) p events q →
      proofBlock env (.third entry p) events (.stored entry (p.regs 1) q)

theorem proof_block_erases (env : BPF.Environment) {before after : ProofState} {events : List Event}
    (step : proofBlock env before events after) :
    Execution (instructionStep env) (physical before) events (physical after) := by
  cases step <;> assumption

theorem proof_execution_erases (env : BPF.Environment) {before after : ProofState} {events : List Event}
    (run : Execution (proofBlock env) before events after) :
    Execution (instructionStep env) (physical before) events (physical after) := by
  induction run with
  | refl => exact Execution.refl _
  | next step rest ih => exact (proof_block_erases env step).append ih

/-- Fault boundaries retain the entire partial native architecture. Every
successful read and its order are from actual B/native instruction semantics. -/
theorem first_block_simulation (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (actual : Transition X86.State)
    (inv : invariant env (.initial entry p))
    (run : CanonicalRelationalPath 0 native (firstPath entry) entry actual) :
    ∃ after, proofBlock env (.initial entry p) actual.events after ∧
      related env (nativeAfterBlock actual) after := by
  obtain ⟨nativePC,proofPC,active,argument,memory,stack,input⟩ := inv
  cases read0 : readMemory p.memory (p.regs 1) 8 with
  | error fault =>
    obtain ⟨bad,rfl⟩ := canonical_read_error read0
    have nr0 : readMemory entry.memory (entry.gpr 7) 8=.error (.read (p.regs 1) 8) := by
      simpa only [memory,argument] using read0
    have selected : CanonicalRelationalPath 0 native [⟨0,3⟩] entry actual := by
      simpa only [firstPath,nr0] using run
    obtain ⟨arch,physicalRun,fault⟩ := first_read_fault_architecture env entry p stack actual
      nativePC proofPC active argument memory input bad selected
    exact ⟨.dataFault entry (stackAfter p stack),.dataFault physicalRun,
      arch,by simp only [nativeAfterBlock,stopped,fault,Option.isSome_some],trivial⟩
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    have nr0 : readMemory entry.memory (entry.gpr 7) 8=.ok (pointer,first) := by
      simpa only [memory,argument] using read0
    cases read1 : readMemory p.memory (p.regs 1+(8#64)) 8 with
    | error fault =>
      obtain ⟨bad,rfl⟩ := canonical_read_error read1
      have nr1 : readMemory entry.memory (entry.gpr 7+(8#64)) 8=
          .error (.read (p.regs 1+(8#64)) 8) := by simpa only [memory,argument] using read1
      have selected : CanonicalRelationalPath 0 native [⟨0,3⟩,⟨3,4⟩] entry actual := by
        simpa only [firstPath,nr0,nr1] using run
      obtain ⟨arch,physicalRun,fault⟩ := second_read_fault_architecture env entry p stack pointer first actual
        nativePC proofPC active argument memory input read0 bad selected
      exact ⟨.endFault entry (dataAfter p stack pointer),.endFault physicalRun,
        arch,by simp only [nativeAfterBlock,stopped,fault,Option.isSome_some],trivial⟩
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      have nr1 : readMemory entry.memory (entry.gpr 7+(8#64)) 8=.ok (limit,second) := by
        simpa only [memory,argument] using read1
      have selected : CanonicalRelationalPath 0 native
          [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] entry actual := by
        simpa only [firstPath,nr0,nr1] using run
      obtain ⟨arch,_,fault,physicalRun⟩ := first_block_relational_architecture env entry p stack pointer limit
        first second actual nativePC proofPC active argument memory input read0 read1 selected
      refine ⟨.first entry (guardAfter (contextAfter p stack pointer limit)),.first physicalRun,
        arch,by simp only [nativeAfterBlock,stopped,fault,Option.isSome_none],?_,?_⟩
      · simp only [guardAfter]; split <;> simp
      · simp only [guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg,active]

theorem second_block_simulation (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (actual : Transition X86.State) (position : p.pc=5) (active : p.halted=false)
    (run : CanonicalRelationalPath 0 native [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩]
      (firstGuardView entry p) actual) :
    ∃ after, proofBlock env (.first entry p) actual.events after ∧
      related env (nativeAfterBlock actual) after := by
  obtain ⟨arch,_,fault,physicalRun⟩ := second_block_relational_architecture env entry _ p actual
    rfl position active run
  refine ⟨.second entry (guard8After p),.second physicalRun,arch,
    by simp only [nativeAfterBlock,stopped,fault,Option.isSome_none],?_,?_,second_guard_temporary p⟩
  · simp only [guard8After]; split <;> simp
  · simp only [guard8After,guard8Add,guard8Move,BPF.setReg,active]

theorem third_block_simulation (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (actual : Transition X86.State) (position : p.pc=8) (active : p.halted=false)
    (temporary : p.regs 3=p.regs 2+(8#64))
    (run : CanonicalRelationalPath 0 native [⟨26,4⟩,⟨30,3⟩,⟨33,2⟩]
      (secondGuardView entry p) actual) :
    ∃ after, proofBlock env (.second entry p) actual.events after ∧
      related env (nativeAfterBlock actual) after := by
  obtain ⟨arch,_,fault,physicalRun⟩ := third_block_relational_architecture env entry _ p actual
    rfl position active temporary run
  refine ⟨.third entry (guard72After p),.third physicalRun,arch,
    by simp only [nativeAfterBlock,stopped,fault,Option.isSome_none],?_,?_,third_guard_temporary p⟩
  · simp only [guard72After]; split <;> simp
  · simp only [guard72After,guard72Add,guard72Move,BPF.setReg,active]

theorem store_outcome_boundary (p : BPF.State) (index : Nat) (bounded : index≤4) :
    invariant env (.stored entry limit (storesOutcome p index)) ∧
      stopped (.stored entry limit (storesOutcome p index))=
        (if index=4 then (none : Option Fault) else some (packetStoreFault (p.regs 2) index)).isSome := by
  have casesIndex : index=0 ∨ index=1 ∨ index=2 ∨ index=3 ∨ index=4 := by omega
  rcases casesIndex with rfl | rfl | rfl | rfl | rfl
  all_goals simp +decide [invariant,stopped,storesOutcome,storesAfter,storesFaultState,
    packetProofFaultState,packetProofBeforeFirst,packetStoredPrefix,BPF.setReg]

theorem store_block_simulation (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (actual : Transition X86.State) (position : p.pc=11) (active : p.halted=false)
    (temporary : p.regs 3=p.regs 2+(72#64))
    (run : CanonicalRelationalPath 0 native
      (packetNativeOutcomePath (packetFirstFailure p.memory (p.regs 2)))
      (thirdGuardView entry p) actual) :
    ∃ after, proofBlock env (.third entry p) actual.events after ∧
      related env (nativeAfterBlock actual) after := by
  let index := packetFirstFailure p.memory (p.regs 2)
  obtain ⟨arch,_,fault,physicalRun⟩ := store_block_relational_architecture env entry _ p index actual
    rfl position active temporary rfl run
  have bounded : index≤4 := (packet_first_failure_spec p.memory (p.regs 2)).1
  obtain ⟨inv,stop⟩ := store_outcome_boundary (env:=env) (entry:=entry) (limit:=p.regs 1) p index bounded
  exact ⟨.stored entry (p.regs 1) (storesOutcome p index),.stored physicalRun,arch,
    by simpa only [nativeAfterBlock,fault] using stop.symm,inv⟩

/-- Explicit generic TV instance: every actual native block from a related
boundary has a real accepted-B execution, the same ordered events and a
related whole architectural successor. No native successor is assumed. -/
theorem translation_validation (env : BPF.Environment) :
    TranslationValidation nativeBlock (proofBlock env) (related env) := by
  constructor
  intro n p trace n' relation run
  obtain ⟨cpuEq,stopEq,inv⟩ := relation
  obtain ⟨active,allowed,actual,path,traceEq,finish⟩ := run
  subst n'
  subst trace
  rw [cpuEq] at allowed path
  rw [stopEq] at active
  have matching : ∃ after, proofBlock env p actual.events after ∧
      related env (nativeAfterBlock actual) after := by
    cases p with
    | initial entry p =>
      have nativePC := inv.1
      exact first_block_simulation env entry p actual inv (by
        simpa only [architecture,blockPath,nativePC,ite_true] using path)
    | dataFault entry p => simp only [stopped,Bool.true_eq_false] at active
    | endFault entry p => simp only [stopped,Bool.true_eq_false] at active
    | first entry p =>
      obtain ⟨position,live⟩ := inv
      rcases position with position | position
      · exact second_block_simulation env entry p actual position live (by
          simpa +decide [architecture,blockPath,firstGuardView,position] using path)
      · simp +decide [architecture,firstGuardView,position] at allowed
    | second entry p =>
      obtain ⟨position,live,temporary⟩ := inv
      rcases position with position | position
      · exact third_block_simulation env entry p actual position live temporary (by
          simpa +decide [architecture,blockPath,secondGuardView,position] using path)
      · simp +decide [architecture,secondGuardView,position] at allowed
    | third entry p =>
      obtain ⟨position,live,temporary⟩ := inv
      rcases position with position | position
      · exact store_block_simulation env entry p actual position live temporary (by
          simpa +decide [architecture,blockPath,thirdGuardView,position] using path)
      · simp +decide [architecture,thirdGuardView,position] at allowed
    | stored entry limit p =>
      have position : p.pc=27 := by simpa only [stopped,bne_eq_false_iff_eq] using active
      simp +decide [architecture,storeView,position] at allowed
  obtain ⟨after,proofRun,finalRelation⟩ := matching
  exact ⟨after,by simpa only [List.append_nil] using Execution.next proofRun (Execution.refl after),finalRelation⟩

/-- Whole executions of the four-block CFG retain the complete native
architecture at every boundary and exactly the real B ordered effects. -/
theorem validated_architectural_execution (env : BPF.Environment)
    {before last : NativeState} {initial : ProofState} {events : List Event}
    (entry : related env before initial) (run : Execution nativeBlock before events last) :
    ∃ after, Execution (instructionStep env) (physical initial) events (physical after) ∧
      last.cpu=architecture after ∧ last.stopped=stopped after ∧ invariant env after := by
  obtain ⟨after,matching,finalRelation⟩ := validated_execution (translation_validation env) entry run
  exact ⟨after,proof_execution_erases env matching,finalRelation⟩

/-- Entry is exactly nativePC0/BPC0 with the supported bound SP input and
same context argument/memory. No permissions, branch, result or end state is
supplied by this relation. -/
theorem initial_related (env : BPF.Environment) (entry : X86.State) (p : BPF.State) (stack : Word)
    (nativePC : entry.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : entry.gpr 7=p.regs 1) (memory : entry.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack) :
    related env ⟨entry,false⟩ (.initial entry p) :=
  ⟨rfl,rfl,nativePC,proofPC,active,argument,memory,stack,input⟩

/-- Concrete composition of verifier acceptance/soundness, the explicit
per-block TV instance and complete Artifact binding. Both native and proof
relations read the executed/accepted artifact bytes. Artifact equality keeps
entry, supported ABI and specialization metadata bound along with both byte
images. Kernel enforcement, reference hardware fidelity and the declared XDP
conversion/physical entry provenance remain trusted, not theorem conclusions. -/
theorem bound_block_effects_checked (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=TrustedSimpleB29.proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ artifact, accepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (boundProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    {events : List Event} {last : NativeState}
    (run : Execution (boundNativeBlock executed) ⟨entry,false⟩ events last)
    (stack : Word) (nativePC : entry.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : entry.gpr 7=p.regs 1) (memory : entry.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack) :
    ∀ event ∈ events, checked validated event := by
  subst executed
  have canonicalRun : Execution nativeBlock ⟨entry,false⟩ events last := by
    simpa only [boundNativeBlock,nativeBlock,nativeImage,entryImage,Array.toArray_toList] using run
  obtain ⟨after,matching,_⟩ := validated_architectural_execution env
    (initial_related env entry p stack nativePC proofPC active argument memory nativeStack) canonicalRun
  have stepEq : boundProofStep env validated=instructionStep env := by
    funext before trace after
    unfold boundProofStep instructionStep
    rw [proofImage]
  have boundRun : Execution (boundProofStep env validated) p events (physical after) := by
    rw [stepEq]
    exact matching
  exact verifierSound validated acceptance admitted _ _ boundRun

end KProgTV.TrustedSimpleB29Blocks
#print axioms KProgTV.TrustedSimpleB29Blocks.proof_block_erases
#print axioms KProgTV.TrustedSimpleB29Blocks.proof_execution_erases
#print axioms KProgTV.TrustedSimpleB29Blocks.first_block_simulation

#print axioms KProgTV.TrustedSimpleB29Blocks.second_block_simulation
#print axioms KProgTV.TrustedSimpleB29Blocks.third_block_simulation
#print axioms KProgTV.TrustedSimpleB29Blocks.store_outcome_boundary
#print axioms KProgTV.TrustedSimpleB29Blocks.store_block_simulation
#print axioms KProgTV.TrustedSimpleB29Blocks.translation_validation

#print axioms KProgTV.TrustedSimpleB29Blocks.validated_architectural_execution
#print axioms KProgTV.TrustedSimpleB29Blocks.initial_related
#print axioms KProgTV.TrustedSimpleB29Blocks.bound_block_effects_checked
