import TrustedSimpleB29

/-! Architectural reconstruction for actual B29 basic-block boundaries.
Changed registers are taken from real BPF values; untouched native fields are
immutable invocation parameters. Flags use the single canonical CMP rule. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleB29State
open KProgFormal.Reference
open TrustedSimpleX86 TrustedSimpleB29

/-- First JA boundary: all changed GPRs are represented by actual B values.
The reference CMP rematerializes flags which clang does not keep in BPF.
No execution, memory permission test or native successor is supplied here. -/
def firstGuardView (entry : X86.State) (p : BPF.State) : X86.State :=
  {entry with
    gpr := fun r => if r=0 then p.regs 0 else if r=1 then p.regs 2
      else if r=2 then p.regs 1 else if r=6 then p.regs 2 else entry.gpr r
    rflags := X86.arithmeticFlags .w64 true false (p.regs 2) (p.regs 1) entry.rflags
    memory := p.memory
    pc := if p.pc=27 then 60 else 17}

/-- Equality of the whole native architecture, not only live results or
memory: all16GPRs, all flags, XMM0, memory, PC, segments and address width. -/
theorem first_guard_architecture (n : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (memory : n.memory=p.memory) :
    guardFinal (nativePrefixFinal n pointer limit)=
      firstGuardView n (guardAfter (contextAfter p stack pointer limit)) := by
  have flagsEq : X86.arithmeticFlags .w64 true false pointer limit (guardZeroFlags n.rflags)=
      X86.arithmeticFlags .w64 true false pointer limit n.rflags :=
    xor_compare_flags_choice pointer limit (0#64) n.rflags (guardZeroFlags n.rflags) rfl
  by_cases reject : pointer>limit
  all_goals simp +decide [firstGuardView,guardFinal,guardCompare,guardZero,guardMove,
    nativePrefixFinal,nativeAfterSecond,nativeAfter,guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,
    BPF.setReg,memory,flagsEq,reject]
  all_goals funext r
  all_goals by_cases zero : r=0
  all_goals by_cases one : r=1
  all_goals by_cases two : r=2
  all_goals by_cases six : r=6
  all_goals simp_all +decide

/-- Actual byte-decoded first native block, for every canonical XOR AF
choice, equals the architectural view reconstructed from the actual B29 end
state. The same two ordered reads are retained in both executions. -/
theorem first_block_relational_architecture (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event) (actual : Transition X86.State)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second))
    (run : CanonicalRelationalPath 0 native
      [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] n actual) :
    actual.state=firstGuardView n (guardAfter (contextAfter p stack pointer limit)) ∧
    actual.events=[first,second] ∧ actual.fault=none ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events
      (guardAfter (contextAfter p stack pointer limit)) := by
  have nr0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by
    simpa only [memory,argument] using read0
  have nr1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second) := by
    simpa only [memory,argument] using read1
  have endpoint := entry_first_guard_relational_result n pointer limit first second actual nativePC nr0 nr1 run
  obtain ⟨_,proofRun,_,_,_,_⟩ := entry_first_guard_component env n p stack pointer limit first second
    nativePC proofPC active argument memory input read0 read1
  refine ⟨?_,?_,?_,?_⟩
  · simpa only [endpoint] using first_guard_architecture n p stack pointer limit memory
  · simp only [endpoint]
  · simp only [endpoint]
  · simpa only [endpoint] using proofRun


/-- The failed first load has not changed any native register or flag. -/
def firstReadFaultView (entry : X86.State) (p : BPF.State) : X86.State :=
  {entry with memory:=p.memory}

/-- After the first load, native RCX is the actual B data value; all other
invocation fields persist when the second context load fails. -/
def secondReadFaultView (entry : X86.State) (p : BPF.State) : X86.State :=
  {entry with
    gpr:=fun r => if r=1 then p.regs 2 else entry.gpr r
    memory:=p.memory
    pc:=entry.pc+3}

theorem first_read_fault_architecture (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack : Word) (actual : Transition X86.State)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (bad : permitted p.memory.readable (p.regs 1) 8=false)
    (run : CanonicalRelationalPath 0 native [⟨0,3⟩] n actual) :
    actual.state=firstReadFaultView n (stackAfter p stack) ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (stackAfter p stack) ∧
    actual.fault=some (.read (p.regs 1) 8) := by
  have read : readMemory n.memory (n.gpr 7) 8=.error (.read (p.regs 1) 8) := by
    simp only [readMemory,memory,argument,bad,Bool.false_eq_true,ite_false]
  have selected : CanonicalRelationalPath 0 native (allReadNativePath n) n actual := by
    simpa only [allReadNativePath,read] using run
  have endpoint := all_read_native_relational_result n actual nativePC selected
  have exactEndpoint : actual=⟨n,[.fault (.read (p.regs 1) 8)],some (.read (p.regs 1) 8)⟩ := by
    simpa only [allReadNativeResult,read] using endpoint
  obtain ⟨_,proofRun⟩ := first_context_fault env n p stack nativePC proofPC active argument memory input bad
  refine ⟨?_,?_,?_⟩
  · simp only [exactEndpoint,firstReadFaultView,stackAfter,BPF.setReg]
    rw [← memory]
  · simpa only [exactEndpoint] using proofRun
  · simp only [exactEndpoint]

theorem second_read_fault_architecture (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer : Word) (first : Event) (actual : Transition X86.State)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (bad : permitted p.memory.readable (p.regs 1+(8#64)) 8=false)
    (run : CanonicalRelationalPath 0 native [⟨0,3⟩,⟨3,4⟩] n actual) :
    actual.state=secondReadFaultView n (dataAfter p stack pointer) ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (dataAfter p stack pointer) ∧
    actual.fault=some (.read (p.regs 1+(8#64)) 8) := by
  have nr0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by simpa only [memory,argument] using read0
  have nr1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.error (.read (p.regs 1+(8#64)) 8) := by
    simp only [readMemory,memory,argument,bad,Bool.false_eq_true,ite_false]
  have selected : CanonicalRelationalPath 0 native (allReadNativePath n) n actual := by
    simpa only [allReadNativePath,nr0,nr1] using run
  have endpoint := all_read_native_relational_result n actual nativePC selected
  have exactEndpoint : actual=⟨nativeAfter n pointer,[first,.fault (.read (p.regs 1+(8#64)) 8)],some (.read (p.regs 1+(8#64)) 8)⟩ := by
    simpa only [allReadNativeResult,nr0,nr1] using endpoint
  obtain ⟨_,proofRun⟩ := second_context_fault env n p stack pointer first nativePC proofPC active argument memory input read0 bad
  refine ⟨?_,?_,?_⟩
  · simp +decide [exactEndpoint,secondReadFaultView,dataAfter,stackAfter,BPF.setReg,nativeAfter,memory]
  · simpa only [exactEndpoint] using proofRun
  · simp only [exactEndpoint]


/-- +8 JA boundary: native RDI is now the actual B temporary r3. The earlier
CMP flags are rematerialized from the still represented data/end values. -/
def secondGuardView (entry : X86.State) (p : BPF.State) : X86.State :=
  {entry with
    gpr := fun r => if r=0 then p.regs 0 else if r=1 then p.regs 2
      else if r=2 then p.regs 1 else if r=6 then p.regs 2 else if r=7 then p.regs 3 else entry.gpr r
    rflags := X86.arithmeticFlags .w64 true false (p.regs 3) (p.regs 1)
      (X86.arithmeticFlags .w64 true false (p.regs 2) (p.regs 1) entry.rflags)
    memory := p.memory
    pc := if p.pc=27 then 60 else 26}

theorem second_guard_architecture (entry : X86.State) (p : BPF.State) :
    remainingNative8 (firstGuardView entry p)=secondGuardView entry (guard8After p) := by
  by_cases reject : p.regs 2+(8#64)>p.regs 1
  all_goals simp +decide [secondGuardView,firstGuardView,remainingNative8,remainingNativeCmp8,remainingNativeLea,
    guard8After,guard8Add,guard8Move,BPF.setReg,reject]
  all_goals funext r
  all_goals by_cases zero : r=0
  all_goals by_cases one : r=1
  all_goals by_cases two : r=2
  all_goals by_cases six : r=6
  all_goals by_cases seven : r=7
  all_goals simp_all +decide

/-- Arbitrary decoded native execution of the second block, given the
architectural relation established by the first block, has the reconstructed
whole B end state and identical empty effects. No successor is assumed. -/
theorem second_block_relational_architecture (env : BPF.Environment) (entry n : X86.State)
    (p : BPF.State) (actual : Transition X86.State)
    (related : n=firstGuardView entry p) (position : p.pc=5) (active : p.halted=false)
    (run : CanonicalRelationalPath 0 native [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩] n actual) :
    actual.state=secondGuardView entry (guard8After p) ∧ actual.events=[] ∧ actual.fault=none ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (guard8After p) := by
  subst n
  have nativePC : (firstGuardView entry p).pc=17 := by simp [firstGuardView,position]
  have members : ∀ extent ∈ [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩], extent ∈ simpleDefinedExtents := by simp [simpleDefinedExtents]
  obtain ⟨endpoint,_⟩ := defined_relational_result_unique run members
    (remaining_native8_evaluation (firstGuardView entry p) nativePC)
  refine ⟨?_,?_,?_,?_⟩
  · simpa only [endpoint] using second_guard_architecture entry p
  · simp only [endpoint]
  · simp only [endpoint]
  · simpa only [endpoint] using guard8_execution env p position active


/-- This invariant is produced by the actual previous BPF ADD, not supplied
as a new execution guard or a restriction on pointer inputs. -/
theorem second_guard_temporary (p : BPF.State) :
    (guard8After p).regs 3=(guard8After p).regs 2+(8#64) := by
  simp +decide [guard8After,guard8Add,guard8Move,BPF.setReg]

/-- +72 JA boundary. B no longer retains the +8 temporary, so native RDI is
reconstructed from the still represented original pointer. All flag stages
reuse the canonical operations; all other invocation fields stay immutable. -/
def thirdGuardView (entry : X86.State) (p : BPF.State) : X86.State :=
  {entry with
    gpr := fun r => if r=0 then p.regs 0 else if r=1 then p.regs 2
      else if r=2 then p.regs 1 else if r=6 then p.regs 3
      else if r=7 then p.regs 2+(8#64) else entry.gpr r
    rflags := X86.arithmeticFlags .w64 true false (p.regs 3) (p.regs 1)
      (X86.arithmeticFlags .w64 false false (p.regs 2) (72#64)
        (X86.arithmeticFlags .w64 true false (p.regs 2+(8#64)) (p.regs 1)
          (X86.arithmeticFlags .w64 true false (p.regs 2) (p.regs 1) entry.rflags)))
    memory := p.memory
    pc := if p.pc=27 then 60 else 35}

theorem third_guard_architecture (entry : X86.State) (p : BPF.State)
    (temporary : p.regs 3=p.regs 2+(8#64)) :
    remainingNative72 (secondGuardView entry p)=thirdGuardView entry (guard72After p) := by
  by_cases reject : p.regs 2+(72#64)>p.regs 1
  all_goals simp +decide [thirdGuardView,secondGuardView,remainingNative72,remainingNativeCmp72,remainingNativeAdd,
    guard72After,guard72Add,guard72Move,BPF.setReg,temporary,reject]
  all_goals funext r
  all_goals by_cases zero : r=0
  all_goals by_cases one : r=1
  all_goals by_cases two : r=2
  all_goals by_cases six : r=6
  all_goals by_cases seven : r=7
  all_goals simp_all +decide

/-- Every decoded +72 native execution preserves the full architectural
relation. The temporary invariant was established by the previous B block;
no branch result, memory permission, or native next state is assumed. -/
theorem third_block_relational_architecture (env : BPF.Environment) (entry n : X86.State)
    (p : BPF.State) (actual : Transition X86.State)
    (related : n=secondGuardView entry p) (position : p.pc=8) (active : p.halted=false)
    (temporary : p.regs 3=p.regs 2+(8#64))
    (run : CanonicalRelationalPath 0 native [⟨26,4⟩,⟨30,3⟩,⟨33,2⟩] n actual) :
    actual.state=thirdGuardView entry (guard72After p) ∧ actual.events=[] ∧ actual.fault=none ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (guard72After p) := by
  subst n
  have nativePC : (secondGuardView entry p).pc=26 := by simp [secondGuardView,position]
  have members : ∀ extent ∈ [⟨26,4⟩,⟨30,3⟩,⟨33,2⟩], extent ∈ simpleDefinedExtents := by simp [simpleDefinedExtents]
  obtain ⟨endpoint,_⟩ := defined_relational_result_unique run members
    (remaining_native72_evaluation (secondGuardView entry p) nativePC)
  refine ⟨?_,?_,?_,?_⟩
  · simpa only [endpoint] using third_guard_architecture entry p temporary
  · simp only [endpoint]
  · simp only [endpoint]
  · simpa only [endpoint] using guard72_execution env p position active

end KProgTV.TrustedSimpleB29State
#print axioms KProgTV.TrustedSimpleB29State.first_guard_architecture
#print axioms KProgTV.TrustedSimpleB29State.first_block_relational_architecture

#print axioms KProgTV.TrustedSimpleB29State.first_read_fault_architecture
#print axioms KProgTV.TrustedSimpleB29State.second_read_fault_architecture

#print axioms KProgTV.TrustedSimpleB29State.second_guard_architecture
#print axioms KProgTV.TrustedSimpleB29State.second_block_relational_architecture

#print axioms KProgTV.TrustedSimpleB29State.second_guard_temporary
#print axioms KProgTV.TrustedSimpleB29State.third_guard_architecture
#print axioms KProgTV.TrustedSimpleB29State.third_block_relational_architecture
