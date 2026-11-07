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
    pc := if p.pc=27 ∨ p.pc=28 ∨ p.pc=29 then 60 else 17}

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
    pc := if p.pc=27 ∨ p.pc=28 ∨ p.pc=29 then 60 else 26}

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
    pc := if p.pc=27 ∨ p.pc=28 ∨ p.pc=29 then 60 else 35}

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


theorem third_guard_temporary (p : BPF.State) :
    (guard72After p).regs 3=(guard72After p).regs 2+(72#64) := by
  simp +decide [guard72After,guard72Add,guard72Move,BPF.setReg]

/-- The context end value is snapped from actual B r1 at store-block entry,
where it was established by the real context load. B subsequently kills r1;
this ghost value preserves native RDX and CMP flags, without another read. -/
def storeView (entry : X86.State) (limit : Word) (p : BPF.State) : X86.State :=
  {entry with
    gpr := fun r => if r=0 then p.regs 0 else if r=1 then p.regs 2
      else if r=2 then limit else if r=6 then p.regs 2+(72#64)
      else if r=7 then p.regs 2+(8#64) else entry.gpr r
    rflags := X86.arithmeticFlags .w64 true false (p.regs 2+(72#64)) limit
      (X86.arithmeticFlags .w64 false false (p.regs 2) (72#64)
        (X86.arithmeticFlags .w64 true false (p.regs 2+(8#64)) limit
          (X86.arithmeticFlags .w64 true false (p.regs 2) limit entry.rflags)))
    memory := p.memory
    pc := if p.pc=15 then 35 else if p.pc=19 then 40
      else if p.pc=22 then 44 else if p.pc=25 then 51 else 60}

theorem successful_store_architecture (entry : X86.State) (p : BPF.State)
    (temporary : p.regs 3=p.regs 2+(72#64)) :
    packetNativeFinal (thirdGuardView entry p)=storeView entry (p.regs 1) (storesAfter p) := by
  simp +decide [packetNativeFinal,packetNativeFourth,packetNativeThird,packetNativeSecond,packetNativeFirst,
    thirdGuardView,storeView,storesAfter,packetWriteMemory,BPF.setReg,temporary]
  funext r
  by_cases zero : r=0 <;> by_cases one : r=1 <;> by_cases two : r=2 <;>
    by_cases six : r=6 <;> by_cases seven : r=7 <;> simp_all +decide

theorem faulting_store_architecture (entry : X86.State) (p : BPF.State) (index : Nat)
    (bounded : index<4) (position : p.pc=11) (temporary : p.regs 3=p.regs 2+(72#64)) :
    packetNativeFaultState (thirdGuardView entry p) index=
      storeView entry (p.regs 1) (storesFaultState p index) := by
  have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
  rcases choices with rfl | rfl | rfl | rfl
  all_goals simp +decide [packetNativeFaultState,packetNativeFirst,packetNativeSecond,packetNativeThird,
    thirdGuardView,storeView,storesFaultState,packetProofFaultState,packetProofBeforeFirst,
    packetStoredPrefix,BPF.setReg,position,temporary]
  all_goals funext r
  all_goals by_cases zero : r=0
  all_goals by_cases one : r=1
  all_goals by_cases two : r=2
  all_goals by_cases six : r=6
  all_goals by_cases seven : r=7
  all_goals simp_all +decide

/-- All permission outcomes of the actual store block preserve the complete
native state, including dead RDX and flags via the actual entry-r1 snapshot.
Neither successful stores nor a computed native result is a premise. -/
theorem store_block_relational_architecture (env : BPF.Environment) (entry n : X86.State)
    (p : BPF.State) (index : Nat) (actual : Transition X86.State)
    (related : n=thirdGuardView entry p) (position : p.pc=11) (active : p.halted=false)
    (temporary : p.regs 3=p.regs 2+(72#64))
    (selected : index=packetFirstFailure p.memory (p.regs 2))
    (run : CanonicalRelationalPath 0 native (packetNativeOutcomePath index) n actual) :
    actual.state=storeView entry (p.regs 1) (storesOutcome p index) ∧
    actual.events=packetOutcomeEvents (p.regs 2) index ∧
    actual.fault=(if index=4 then none else some (packetStoreFault (p.regs 2) index)) ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (storesOutcome p index) := by
  subst n
  have nativePC : (thirdGuardView entry p).pc=35 := by simp [thirdGuardView,position]
  obtain ⟨endpoint,proofRun,_⟩ := stores_relational_component env (thirdGuardView entry p) p index actual
    nativePC position active rfl rfl selected run
  have bounded := (packet_first_failure_spec p.memory (p.regs 2)).1
  change packetFirstFailure p.memory (p.regs 2)≤4 at bounded
  rw [← selected] at bounded
  refine ⟨?_,?_,?_,proofRun⟩
  · by_cases success : index=4
    · simpa only [endpoint,packetNativeOutcome,storesOutcome,success,ite_true] using successful_store_architecture entry p temporary
    · simpa only [endpoint,packetNativeOutcome,storesOutcome,success,ite_false] using faulting_store_architecture entry p index (by omega) position temporary
  · simp only [endpoint]
  · simp only [endpoint]

/-- Actual JA/EXIT moves B through PCs27,28,29 without changing the native
payload-end architecture. Guard-exit views preserve their path history. -/
theorem exit_architectures (entry : X86.State) (p : BPF.State) (limit : Word)
    (position : p.pc=27) :
    firstGuardView entry (exitAfter p)=firstGuardView entry p ∧
    secondGuardView entry (exitAfter p)=secondGuardView entry p ∧
    thirdGuardView entry (exitAfter p)=thirdGuardView entry p ∧
    storeView entry limit (exitAfter p)=storeView entry limit p := by
  simp +decide [firstGuardView,secondGuardView,thirdGuardView,storeView,exitAfter,position]


/-- Select reconstruction from the actual B branch-boundary history. The
history consists of real B states, not native outcomes or replayed ISA steps. -/
def observedGuardView (entry : X86.State) (initial : BPF.State)
    (stack pointer limit : Word) (current : BPF.State) : X86.State :=
  let first := guardAfter (contextAfter initial stack pointer limit)
  if first.pc=27 then firstGuardView entry current
  else if (guard8After first).pc=27 then secondGuardView entry current
  else thirdGuardView entry current

/-- Connect the full state relations of all three guard blocks, preserving
which B branch reached the shared exit. All pointer bits and wrap are free. -/
theorem guard_region_architecture (entry : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (memory : entry.memory=p.memory) :
    guardedNativeFinal entry pointer limit=
      observedGuardView entry p stack pointer limit (guardsAfter p stack pointer limit) := by
  have first := first_guard_architecture entry p stack pointer limit memory
  have second := second_guard_architecture entry (guardAfter (contextAfter p stack pointer limit))
  rw [← first] at second
  have third := third_guard_architecture entry (guard8After (guardAfter (contextAfter p stack pointer limit)))
    (second_guard_temporary (guardAfter (contextAfter p stack pointer limit)))
  rw [← second] at third
  have nativePointer : (guardFinal (nativePrefixFinal entry pointer limit)).gpr 6=pointer := by
    simp +decide [guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter]
  have nativeLimit : (guardFinal (nativePrefixFinal entry pointer limit)).gpr 2=limit := by
    simp +decide [guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter]
  have proofPointer : (guardAfter (contextAfter p stack pointer limit)).regs 2=pointer := by
    simp +decide [guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg]
  have proofLimit : (guardAfter (contextAfter p stack pointer limit)).regs 1=limit := by
    simp +decide [guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg]
  have firstPC : (guardAfter (contextAfter p stack pointer limit)).pc=(if pointer>limit then 27 else 5) := by
    simp +decide [guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg]
  have secondPC : (guard8After (guardAfter (contextAfter p stack pointer limit))).pc=
      (if pointer+(8#64)>limit then 27 else 8) := by
    simp only [guard8After,proofPointer,proofLimit]
  by_cases reject : pointer>limit
  · simpa +decide [guardedNativeFinal,guardsAfter,observedGuardView,firstPC,reject] using first
  · by_cases reject8 : pointer+(8#64)>limit
    · simpa +decide [guardedNativeFinal,guardsAfter,observedGuardView,remainingNativeFinal,remainingAfter,
        nativePointer,nativeLimit,proofPointer,proofLimit,firstPC,secondPC,reject,reject8] using second
    · simpa +decide [guardedNativeFinal,guardsAfter,observedGuardView,remainingNativeFinal,remainingAfter,
        nativePointer,nativeLimit,proofPointer,proofLimit,firstPC,secondPC,reject,reject8] using third

/-- The architectural history above is connected to actual executions of the
accepted B29 and universal decoded native guard region, with ordered reads. -/
theorem guard_region_relational_architecture (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event) (actual : Transition X86.State)
    (nativePC : entry.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : entry.gpr 7=p.regs 1) (memory : entry.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second))
    (run : CanonicalRelationalPath 0 native (guardedNativePath entry pointer limit) entry actual) :
    actual.state=observedGuardView entry p stack pointer limit (guardsAfter p stack pointer limit) ∧
    actual.events=[first,second] ∧ actual.fault=none ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (guardsAfter p stack pointer limit) := by
  have nr0 : readMemory entry.memory (entry.gpr 7) 8=.ok (pointer,first) := by simpa only [memory,argument] using read0
  have nr1 : readMemory entry.memory (entry.gpr 7+(8#64)) 8=.ok (limit,second) := by simpa only [memory,argument] using read1
  have endpoint := guarded_native_relational_result entry pointer limit first second actual nativePC nr0 nr1 run
  obtain ⟨_,proofRun⟩ := entry_guards_execution env entry p stack pointer limit first second
    nativePC proofPC active argument memory input read0 read1
  refine ⟨?_,?_,?_,?_⟩
  · simpa only [endpoint] using guard_region_architecture entry p stack pointer limit memory
  · simp only [endpoint]
  · simp only [endpoint]
  · simpa only [endpoint] using proofRun


/-- End survives in the actual guard-region B r1 until store entry. -/
theorem guards_end_snapshot (p : BPF.State) (stack pointer limit : Word) :
    (guardsAfter p stack pointer limit).regs 1=limit := by
  by_cases first : pointer>limit
  all_goals by_cases second : pointer+(8#64)>limit
  all_goals simp +decide [guardsAfter,remainingAfter,guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,
    guard8After,guard8Add,guard8Move,guard72After,guard72Add,guard72Move,BPF.setReg,first,second]

/-- The final projection uses actual B guard PCs and the real store-entry r1
snapshot. It neither reruns native instructions nor rereads overwritten memory. -/
def observedCompleteView (entry : X86.State) (initial : BPF.State)
    (stack pointer limit : Word) (current : BPF.State) : X86.State :=
  let guarded := guardsAfter initial stack pointer limit
  if guarded.pc=27 then observedGuardView entry initial stack pointer limit current
  else storeView entry (guarded.regs 1) current

theorem complete_region_architecture (entry : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (memory : entry.memory=p.memory) (active : p.halted=false) :
    completeNativeFinal entry pointer limit=
      observedCompleteView entry p stack pointer limit (completedAfter p stack pointer limit) := by
  have guardEq := guard_region_architecture entry p stack pointer limit memory
  obtain ⟨_,guardPC,_,pointerEq,_,_,_,guardMemory,guardActive⟩ := guards_boundary entry p stack pointer limit memory active
  by_cases reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit
  · have at27 : (guardsAfter p stack pointer limit).pc=27 := by simpa [reject] using guardPC
    obtain ⟨exitFirst,exitSecond,exitThird,_⟩ := exit_architectures entry (guardsAfter p stack pointer limit) limit at27
    have exitObserved : observedGuardView entry p stack pointer limit (exitAfter (guardsAfter p stack pointer limit))=
        observedGuardView entry p stack pointer limit (guardsAfter p stack pointer limit) := by
      simp only [observedGuardView,exitFirst,exitSecond,exitThird]
    simpa +decide [completeNativeFinal,completedAfter,observedCompleteView,reject,at27,exitObserved] using guardEq
  · have notFirst : ¬pointer>limit := fun h => reject (Or.inl h)
    have notSecond : ¬pointer+(8#64)>limit := fun h => reject (Or.inr (Or.inl h))
    have at11 : (guardsAfter p stack pointer limit).pc=11 := by simpa [reject] using guardPC
    have storeEntry : guardedNativeFinal entry pointer limit=thirdGuardView entry (guardsAfter p stack pointer limit) := by
      simpa +decide [observedGuardView,guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,
        guard8After,guard8Add,guard8Move,BPF.setReg,notFirst,notSecond] using guardEq
    have temporary : (guardsAfter p stack pointer limit).regs 3=
        (guardsAfter p stack pointer limit).regs 2+(72#64) := by
      simp +decide [guardsAfter,remainingAfter,guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,
        guard8After,guard8Add,guard8Move,guard72After,guard72Add,guard72Move,BPF.setReg,notFirst,notSecond]
    have endEq := guards_end_snapshot p stack pointer limit
    have originalIndex : packetFirstFailure entry.memory pointer=packetFirstFailure p.memory pointer := by rw [memory]
    by_cases success : packetFirstFailure p.memory pointer=4
    · have storedPC : (storesAfter (guardsAfter p stack pointer limit)).pc=27 := rfl
      have exitStore := (exit_architectures entry (storesAfter (guardsAfter p stack pointer limit)) limit storedPC).2.2.2
      have stored := successful_store_architecture entry (guardsAfter p stack pointer limit) temporary
      rw [← storeEntry] at stored
      simpa +decide [completeNativeFinal,completedAfter,observedCompleteView,packetNativeOutcome,storesOutcome,
        reject,at11,originalIndex,success,endEq,exitStore] using stored
    · have bounded := (packet_first_failure_spec p.memory pointer).1
      have failed : packetFirstFailure p.memory pointer<4 := by omega
      have stored := faulting_store_architecture entry (guardsAfter p stack pointer limit)
        (packetFirstFailure p.memory pointer) failed at11 temporary
      rw [← storeEntry] at stored
      simpa +decide [completeNativeFinal,completedAfter,observedCompleteView,packetNativeOutcome,storesOutcome,
        reject,at11,originalIndex,success,endEq] using stored

theorem complete_region_relational_architecture (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event) (actual : Transition X86.State)
    (nativePC : entry.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : entry.gpr 7=p.regs 1) (memory : entry.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second))
    (run : CanonicalRelationalPath 0 native (completeNativePath entry pointer limit) entry actual) :
    actual.state=observedCompleteView entry p stack pointer limit (completedAfter p stack pointer limit) ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (completedAfter p stack pointer limit) := by
  obtain ⟨endpoint,proofRun,_⟩ := completed_relational_correspondence env entry p stack pointer limit first second actual
    nativePC proofPC active argument memory input read0 read1 run
  refine ⟨?_,proofRun⟩
  simpa only [endpoint,completeNativeResult] using complete_region_architecture entry p stack pointer limit memory active


/-- Initial context-read results are the same actual B read operands already
validated by the prefix certificates; this is a logical snapshot selection,
not another program access. Guard history and store-end snapshot follow B. -/
def observedAllView (entry : X86.State) (initial : BPF.State) (stack : Word)
    (current : BPF.State) : X86.State :=
  match readMemory initial.memory (initial.regs 1) 8 with
  | .error _ => firstReadFaultView entry current
  | .ok (pointer,_) =>
    match readMemory initial.memory (initial.regs 1+(8#64)) 8 with
    | .error _ => secondReadFaultView entry current
    | .ok (limit,_) => observedCompleteView entry initial stack pointer limit current

/-- Complete full architecture reconstruction for all context, branch and
store outcomes, using only B values/history and immutable invocation fields. -/
theorem all_inputs_architecture (entry : X86.State) (p : BPF.State) (stack : Word)
    (argument : entry.gpr 7=p.regs 1) (memory : entry.memory=p.memory) (active : p.halted=false) :
    (allReadNativeResult entry).state=observedAllView entry p stack (allInputsAfter p stack) := by
  cases read0 : readMemory p.memory (p.regs 1) 8 with
  | error fault =>
    have nr0 : readMemory entry.memory (entry.gpr 7) 8=.error fault := by simpa only [memory,argument] using read0
    simp only [allReadNativeResult,nr0,observedAllView,read0,allInputsAfter,firstReadFaultView,stackAfter,BPF.setReg]
    rw [← memory]
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    have nr0 : readMemory entry.memory (entry.gpr 7) 8=.ok (pointer,first) := by simpa only [memory,argument] using read0
    cases read1 : readMemory p.memory (p.regs 1+(8#64)) 8 with
    | error fault =>
      have nr1 : readMemory entry.memory (entry.gpr 7+(8#64)) 8=.error fault := by simpa only [memory,argument] using read1
      simp only [allReadNativeResult,nr0,nr1,observedAllView,read0,read1,allInputsAfter]
      simp +decide [secondReadFaultView,dataAfter,stackAfter,BPF.setReg,nativeAfter,memory]
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      have nr1 : readMemory entry.memory (entry.gpr 7+(8#64)) 8=.ok (limit,second) := by simpa only [memory,argument] using read1
      simpa only [allReadNativeResult,nr0,nr1,observedAllView,read0,read1,allInputsAfter,completeNativeResult] using
        complete_region_architecture entry p stack pointer limit memory active

/-- Every selected complete canonical native path now has the full
architecture reconstructed from actual accepted B29 execution and real-load
snapshot lineage, not only equal guest effects/final memory. -/
theorem all_inputs_relational_architecture (env : BPF.Environment) (entry : X86.State) (p : BPF.State)
    (stack : Word) (actual : Transition X86.State)
    (nativePC : entry.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : entry.gpr 7=p.regs 1) (memory : entry.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (run : CanonicalRelationalPath 0 native (allReadNativePath entry) entry actual) :
    actual.state=observedAllView entry p stack (allInputsAfter p stack) ∧
    actual.fault=(allReadNativeResult entry).fault ∧
    Execution (TrustedSimpleB29.instructionStep env) p actual.events (allInputsAfter p stack) := by
  have endpoint := all_read_native_relational_result entry actual nativePC run
  obtain ⟨proofRun,_⟩ := all_inputs_execution env entry p stack nativePC proofPC active argument memory input
  refine ⟨?_,?_,?_⟩
  · simpa only [endpoint] using all_inputs_architecture entry p stack argument memory active
  · simp only [endpoint]
  · simpa only [endpoint] using proofRun

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

#print axioms KProgTV.TrustedSimpleB29State.third_guard_temporary
#print axioms KProgTV.TrustedSimpleB29State.successful_store_architecture
#print axioms KProgTV.TrustedSimpleB29State.faulting_store_architecture
#print axioms KProgTV.TrustedSimpleB29State.store_block_relational_architecture
#print axioms KProgTV.TrustedSimpleB29State.exit_architectures

#print axioms KProgTV.TrustedSimpleB29State.guard_region_architecture
#print axioms KProgTV.TrustedSimpleB29State.guard_region_relational_architecture

#print axioms KProgTV.TrustedSimpleB29State.guards_end_snapshot
#print axioms KProgTV.TrustedSimpleB29State.complete_region_architecture
#print axioms KProgTV.TrustedSimpleB29State.complete_region_relational_architecture

#print axioms KProgTV.TrustedSimpleB29State.all_inputs_architecture
#print axioms KProgTV.TrustedSimpleB29State.all_inputs_relational_architecture
