import TrustedSimpleX86

/-! Exact B29 accepted in the private forward-candidate native-only capture
26d51b0b9. These are certificate components, not a whole-program TV claim. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleB29
open KProgFormal.Reference
open TrustedSimpleX86

def proof : Array Byte := #[0xb7,0x90,0x1,0x0,0x2,0x0,0x0,0x0,0x61,0x12,0x0,0x0,0x0,0x0,0x0,0x0,0x61,0x11,0x4,0x0,0x0,0x0,0x0,0x0,0xb4,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2d,0x12,0x16,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x8,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x2d,0x13,0x13,0x0,0x0,0x0,0x0,0x0,0xbf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x3,0x0,0x0,0x48,0x0,0x0,0x0,0x2d,0x13,0x10,0x0,0x0,0x0,0x0,0x0,0xb7,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0x4e,0x61,0x0,0x0,0x6b,0x43,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x2,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0xbc,0x0,0x0,0x0,0x73,0x43,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x3,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x63,0x13,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x7,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x73,0x13,0x0,0x0,0x0,0x0,0x0,0x0,0xb4,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x95,0x0,0x0,0x0,0x0,0x0,0x0,0x0]
theorem proof_size : proof.size=232 := rfl
theorem decode0 : BPF.decode proof 0 = .ok ⟨0xb7,0,9,1,2⟩ := rfl
theorem decode1 : BPF.decode proof 1 = .ok ⟨0x61,2,1,0,0⟩ := rfl
theorem decode2 : BPF.decode proof 2 = .ok ⟨0x61,1,1,4,0⟩ := rfl

-- SAME published kernel XDP expansion bytes, at this artifact's actual PCs.
def environment (env : BPF.Environment) : BPFPlatform.Environment where
  bpf := env
  access := fun pc _ => .ok (if pc=1 then some expansion0 else if pc=2 then some expansion2 else none)

def stackAfter (p : BPF.State) (stack : Word) : BPF.State :=
  {BPF.setReg p 0 stack with pc := 1}
def dataAfter (p : BPF.State) (stack pointer : Word) : BPF.State :=
  {BPF.setReg (stackAfter p stack) 2 pointer with pc := 2}
def contextAfter (p : BPF.State) (stack pointer limit : Word) : BPF.State :=
  {BPF.setReg (dataAfter p stack pointer) 1 limit with pc := 3}

/-- Offset1 selects the actual native SP; imm2 is its ABI version. The
instruction contributes no memory/helper effect or value-dependent check. -/
theorem stack_step (env : BPF.Environment) (p : BPF.State) (stack : Word)
    (position : p.pc=0) (active : p.halted=false)
    (input : env.nativeInput .stackPointer=.ok stack) :
    BPFPlatform.step (environment env) proof p = .ok ⟨stackAfter p stack,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode0,
    BPF.execute,BPF.setReg,stackAfter,input,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

theorem data_step (env : BPF.Environment) (p : BPF.State) (value : Word) (event : Event)
    (position : p.pc=1) (active : p.halted=false)
    (read : readMemory p.memory (p.regs 1) 8 = .ok (value,event)) :
    BPFPlatform.step (environment env) proof p =
      .ok ⟨{BPF.setReg p 2 value with pc := 2},[event],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode1,
    BPFPlatform.expand,expansion0,BPFPath.evaluate,physical0,BPF.decode,
    BPF.execute,BPF.load,BPF.setReg,read,littleEndian,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  all_goals rfl

theorem end_step (env : BPF.Environment) (p : BPF.State) (value : Word) (event : Event)
    (position : p.pc=2) (active : p.halted=false)
    (read : readMemory p.memory (p.regs 1+(8#64)) 8 = .ok (value,event)) :
    BPFPlatform.step (environment env) proof p =
      .ok ⟨{BPF.setReg p 1 value with pc := 3},[event],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode2,
    BPFPlatform.expand,expansion2,BPFPath.evaluate,physical2,BPF.decode,
    BPF.execute,BPF.load,BPF.setReg,read,littleEndian,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  all_goals rfl

/-- Actual native byte decoding and the actual B29 operations produce the
same ordered context reads, full explicit endpoints and input words. There
are no simulator spills. Read success is explicit in this component only. -/
theorem entry_context_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second)) :
    X86Path.Execution 0 native n [first,second] (nativePrefixFinal n pointer limit) ∧
    BPFPlatform.step (environment env) proof p = .ok ⟨stackAfter p stack,[],none⟩ ∧
    BPFPlatform.step (environment env) proof (stackAfter p stack) =
      .ok ⟨dataAfter p stack pointer,[first],none⟩ ∧
    BPFPlatform.step (environment env) proof (dataAfter p stack pointer) =
      .ok ⟨contextAfter p stack pointer limit,[second],none⟩ ∧
    (nativePrefixFinal n pointer limit).gpr 1=(contextAfter p stack pointer limit).regs 2 ∧
    (nativePrefixFinal n pointer limit).gpr 2=(contextAfter p stack pointer limit).regs 1 ∧
    (nativePrefixFinal n pointer limit).memory=(contextAfter p stack pointer limit).memory := by
  have native0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by
    simpa only [memory,argument] using read0
  have native1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second) := by
    simpa only [memory,argument] using read1
  have dataRead : readMemory (stackAfter p stack).memory ((stackAfter p stack).regs 1) 8=
      .ok (pointer,first) := by simpa +decide [stackAfter,BPF.setReg] using read0
  have endRead : readMemory (dataAfter p stack pointer).memory
      ((dataAfter p stack pointer).regs 1+(8#64)) 8=.ok (limit,second) := by
    simpa +decide [dataAfter,stackAfter,BPF.setReg] using read1
  refine ⟨native_two_loads n pointer limit first second nativePC native0 native1,
    stack_step env p stack proofPC active input,
    data_step env (stackAfter p stack) pointer first rfl (by simpa [stackAfter] using active) dataRead,
    end_step env (dataAfter p stack pointer) limit second rfl (by simpa [dataAfter,stackAfter] using active) endRead,
    ?_,?_,?_⟩
  all_goals simp +decide [nativePrefixFinal,nativeAfterSecond,nativeAfter,contextAfter,dataAfter,stackAfter,BPF.setReg,memory]


/-- Both context accesses stop on the same denied byte permission, with the
entire input state retained. The SP input preceding them is effect-free. -/
theorem context_fault_step (env : BPF.Environment) (p : BPF.State) (address : Word)
    (position : (p.pc=1 ∧ address=p.regs 1) ∨ (p.pc=2 ∧ address=p.regs 1+(8#64)))
    (active : p.halted=false) (bad : permitted p.memory.readable address 8=false) :
    BPFPlatform.step (environment env) proof p =
      .ok ⟨p,[.fault (.read address 8)],some (.read address 8)⟩ := by
  rcases position with ⟨position,rfl⟩ | ⟨position,rfl⟩
  all_goals simp +decide [BPFPlatform.step,environment,active,position,decode1,decode2,
    BPFPlatform.expand,expansion0,expansion2,BPFPath.evaluate,physical0,physical2,
    BPF.decode,BPF.execute,BPF.load,BPF.setReg,readMemory,bad,littleEndian,
    Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  all_goals cases p <;> simp_all +decide [proof]
  all_goals exact position.symm

def instructionStep (env : BPF.Environment) : BlockStep BPF.State :=
  fun before events after => ∃ effect,
    BPFPlatform.step (environment env) proof before=.ok effect ∧
    effect.events=events ∧ effect.state=after

theorem first_context_fault (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack : Word) (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (bad : permitted p.memory.readable (p.regs 1) 8=false) :
    X86Path.Execution 0 native n [.fault (.read (p.regs 1) 8)] n ∧
    Execution (instructionStep env) p [.fault (.read (p.regs 1) 8)] (stackAfter p stack) := by
  have nativeRun := native_first_context_fault n nativePC (by simpa only [memory,argument] using bad)
  have badAfter : permitted (stackAfter p stack).memory.readable ((stackAfter p stack).regs 1) 8=false := by
    simpa +decide [stackAfter,BPF.setReg] using bad
  have fault := context_fault_step env (stackAfter p stack) ((stackAfter p stack).regs 1)
    (Or.inl ⟨rfl,rfl⟩) (by simpa [stackAfter] using active) badAfter
  have head : instructionStep env p [] (stackAfter p stack) :=
    ⟨_,stack_step env p stack proofPC active input,rfl,rfl⟩
  have tail : instructionStep env (stackAfter p stack) [.fault (.read (p.regs 1) 8)] (stackAfter p stack) := by
    refine ⟨⟨stackAfter p stack,[.fault (.read (p.regs 1) 8)],some (.read (p.regs 1) 8)⟩,?_,rfl,rfl⟩
    simpa +decide [stackAfter,BPF.setReg] using fault
  exact ⟨by simpa only [argument] using nativeRun,
    by simpa using Execution.next head (Execution.next tail (Execution.refl _))⟩

theorem second_context_fault (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer : Word) (first : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (bad : permitted p.memory.readable (p.regs 1+(8#64)) 8=false) :
    X86Path.Execution 0 native n [first,.fault (.read (p.regs 1+(8#64)) 8)] (nativeAfter n pointer) ∧
    Execution (instructionStep env) p [first,.fault (.read (p.regs 1+(8#64)) 8)] (dataAfter p stack pointer) := by
  have entry := native_entry_execution n pointer first nativePC (by simpa only [memory,argument] using read)
  have fault := native_second_context_fault (nativeAfter n pointer)
    (by simp [nativeAfter,nativePC]) (by simpa +decide [nativeAfter,memory,argument] using bad)
  have nativeRun := native_execution_append entry fault
  have dataRead : readMemory (stackAfter p stack).memory ((stackAfter p stack).regs 1) 8=.ok (pointer,first) := by
    simpa +decide [stackAfter,BPF.setReg] using read
  have badAfter : permitted (dataAfter p stack pointer).memory.readable
      ((dataAfter p stack pointer).regs 1+(8#64)) 8=false := by
    simpa +decide [dataAfter,stackAfter,BPF.setReg] using bad
  have proofFault := context_fault_step env (dataAfter p stack pointer)
    ((dataAfter p stack pointer).regs 1+(8#64)) (Or.inr ⟨rfl,rfl⟩)
    (by simpa [dataAfter,stackAfter] using active) badAfter
  have head : instructionStep env p [] (stackAfter p stack) :=
    ⟨_,stack_step env p stack proofPC active input,rfl,rfl⟩
  have middle : instructionStep env (stackAfter p stack) [first] (dataAfter p stack pointer) :=
    ⟨_,data_step env _ pointer first rfl (by simpa [stackAfter] using active) dataRead,rfl,rfl⟩
  have tail : instructionStep env (dataAfter p stack pointer)
      [.fault (.read (p.regs 1+(8#64)) 8)] (dataAfter p stack pointer) := by
    refine ⟨⟨dataAfter p stack pointer,[.fault (.read (p.regs 1+(8#64)) 8)],some (.read (p.regs 1+(8#64)) 8)⟩,?_,rfl,rfl⟩
    simpa +decide [dataAfter,stackAfter,BPF.setReg] using proofFault
  refine ⟨?_,?_⟩
  · simpa +decide [nativeAfter,argument] using nativeRun
  · simpa using Execution.next head (Execution.next middle (Execution.next tail (Execution.refl _)))

theorem decode3 : BPF.decode proof 3 = .ok ⟨0xb4,0,0,0,0⟩ := rfl
theorem decode4 : BPF.decode proof 4 = .ok ⟨0x2d,2,1,22,0⟩ := rfl

def zeroAfter (p : BPF.State) : BPF.State := {BPF.setReg p 0 0 with pc:=4}
def guardAfter (p : BPF.State) : BPF.State :=
  {zeroAfter p with pc:=if p.regs 2 > p.regs 1 then 27 else 5}

theorem zero_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=3) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof p=.ok ⟨zeroAfter p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode3,
    BPF.execute,BPF.source,BPF.alu,BPF.setReg,zeroAfter,Except.map,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

theorem guard_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=3) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof (zeroAfter p)=.ok ⟨guardAfter p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode4,
    BPF.execute,BPF.source,BPF.comparison,BPF.setReg,zeroAfter,guardAfter,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Native MOV/XOR/CMP/JA and the actual B29 zero/JGT64 instructions have
matching branch predicates and effects, including wrap-free comparison of
all 64 pointer bits. Both endpoints are exact complete states, without a
chosen branch outcome. The imported decoded relational block theorem also
covers every allowed value of XOR's undefined AF before CMP overwrites it. -/
theorem first_guard_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=7) (proofPC : p.pc=3) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (limit : n.gpr 2=p.regs 1) :
    X86Path.Execution 0 native n [] (guardFinal n) ∧
    Execution (instructionStep env) p [] (guardAfter p) ∧
    ((guardFinal n).pc=60 ↔ (guardAfter p).pc=27) ∧
    ((guardFinal n).pc=17 ↔ (guardAfter p).pc=5) ∧
    (guardFinal n).gpr 0=(guardAfter p).regs 0 ∧
    (guardFinal n).gpr 6=(guardAfter p).regs 2 ∧
    (guardFinal n).memory=(n.memory) ∧
    (guardAfter p).memory=p.memory ∧
    (guardFinal n).rflags=X86.arithmeticFlags .w64 true false (n.gpr 1) (n.gpr 2) n.rflags := by
  have head : instructionStep env p [] (zeroAfter p) :=
    ⟨_,zero_step env p proofPC active,rfl,rfl⟩
  have tail : instructionStep env (zeroAfter p) [] (guardAfter p) :=
    ⟨_,guard_step env p proofPC active,rfl,rfl⟩
  refine ⟨native_first_guard n nativePC,by simpa using Execution.next head (Execution.next tail (Execution.refl _)),
    ?_,?_,?_,?_,rfl,rfl,guard_final_flags n⟩
  all_goals simp +decide [guardFinal,guardCompare,guardZero,guardMove,guardAfter,zeroAfter,BPF.setReg,pointer,limit]


/-- Universal native semantics at this actual first branch: arbitrary
byte-decoded relational steps, including every allowed XOR AF choice, end
in the exact state paired with B29. No next state or branch choice is assumed. -/
theorem first_guard_relational_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=7) (proofPC : p.pc=3) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (limit : n.gpr 2=p.regs 1)
    (moved zeroed compared branched : Transition X86.State)
    (i0 i1 i2 i3 : X86.Instruction)
    (d0 : X86Path.decodeAt 0 native ⟨7,3⟩ n=.ok i0) (r0 : X86.Step i0 n moved)
    (d1 : X86Path.decodeAt 0 native ⟨10,2⟩ moved.state=.ok i1) (r1 : X86.Step i1 moved.state zeroed)
    (d2 : X86Path.decodeAt 0 native ⟨12,3⟩ zeroed.state=.ok i2) (r2 : X86.Step i2 zeroed.state compared)
    (d3 : X86Path.decodeAt 0 native ⟨15,2⟩ compared.state=.ok i3) (r3 : X86.Step i3 compared.state branched) :
    moved.events++zeroed.events++compared.events++branched.events=[] ∧
    moved.fault=none ∧ zeroed.fault=none ∧ compared.fault=none ∧
    branched=⟨guardFinal n,[],none⟩ ∧
    Execution (instructionStep env) p [] (guardAfter p) ∧
    (branched.state.pc=60 ↔ (guardAfter p).pc=27) ∧
    (branched.state.pc=17 ↔ (guardAfter p).pc=5) := by
  obtain ⟨events,mf,zf,cf,endpoint⟩ := native_guard_decoded_relational_block n nativePC
    moved zeroed compared branched i0 i1 i2 i3 d0 r0 d1 r1 d2 r2 d3 r3
  obtain ⟨_,proofRun,exit,fallthrough,_,_,_,_,_⟩ := first_guard_component env n p nativePC proofPC active pointer limit
  refine ⟨events,mf,zf,cf,endpoint,proofRun,?_,?_⟩
  · simpa only [endpoint] using exit
  · simpa only [endpoint] using fallthrough

/-- First complete successful-read basic block, entry through the actual
conditional exit. Every full endpoint is fixed by the canonical semantics;
all untouched native/BPF registers and memory remain in these explicit states.
The two read-fault certificates above cover the earlier stopping points. -/
theorem entry_first_guard_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second)) :
    X86Path.Execution 0 native n [first,second] (guardFinal (nativePrefixFinal n pointer limit)) ∧
    Execution (instructionStep env) p [first,second] (guardAfter (contextAfter p stack pointer limit)) ∧
    (guardFinal (nativePrefixFinal n pointer limit)).pc=(if pointer > limit then 60 else 17) ∧
    (guardAfter (contextAfter p stack pointer limit)).pc=(if pointer > limit then 27 else 5) ∧
    (guardFinal (nativePrefixFinal n pointer limit)).gpr 0=(guardAfter (contextAfter p stack pointer limit)).regs 0 ∧
    (guardFinal (nativePrefixFinal n pointer limit)).memory=(guardAfter (contextAfter p stack pointer limit)).memory := by
  obtain ⟨nativeContextRun,s0,s1,s2,pointerEq,limitEq,memoryEq⟩ := entry_context_component env n p
    stack pointer limit first second nativePC proofPC active argument memory input read0 read1
  have at7 : (nativePrefixFinal n pointer limit).pc=7 := by
    simp +decide [nativePrefixFinal,nativeAfterSecond,nativeAfter,nativePC]
  have stillActive : (contextAfter p stack pointer limit).halted=false := by
    simpa [contextAfter,dataAfter,stackAfter] using active
  obtain ⟨nativeGuard,proofGuard,_,_,resultEq,_,_,_,_⟩ := first_guard_component env
    (nativePrefixFinal n pointer limit) (contextAfter p stack pointer limit)
    at7 rfl stillActive pointerEq limitEq
  have head : instructionStep env p [] (stackAfter p stack) := ⟨_,s0,rfl,rfl⟩
  have middle : instructionStep env (stackAfter p stack) [first] (dataAfter p stack pointer) := ⟨_,s1,rfl,rfl⟩
  have tail : instructionStep env (dataAfter p stack pointer) [second] (contextAfter p stack pointer limit) := ⟨_,s2,rfl,rfl⟩
  have proofPrefix := Execution.next head (Execution.next middle (Execution.next tail (Execution.refl _)))
  refine ⟨?_,?_,?_,?_,resultEq,?_⟩
  · simpa only [List.append_nil] using native_execution_append nativeContextRun nativeGuard
  · simpa using proofPrefix.append proofGuard
  · simp +decide [guardFinal,nativePrefixFinal,nativeAfterSecond,nativeAfter]
  · simp +decide [guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg]
  · simpa only [guardFinal,guardCompare,guardZero,guardMove,guardAfter,zeroAfter,BPF.setReg] using memoryEq


-- Exact next two basic blocks of the accepted artifact, in native order.
def guard8Move (p : BPF.State) : BPF.State := {BPF.setReg p 3 8 with pc:=6}
def guard8Add (p : BPF.State) : BPF.State :=
  {BPF.setReg (guard8Move p) 3 (p.regs 2+(8#64)) with pc:=7}
def guard8After (p : BPF.State) : BPF.State :=
  {guard8Add p with pc:=if p.regs 2+(8#64)>p.regs 1 then 27 else 8}
def guard72Move (p : BPF.State) : BPF.State := {BPF.setReg p 3 (p.regs 2) with pc:=9}
def guard72Add (p : BPF.State) : BPF.State :=
  {BPF.setReg (guard72Move p) 3 (p.regs 2+(72#64)) with pc:=10}
def guard72After (p : BPF.State) : BPF.State :=
  {guard72Add p with pc:=if p.regs 2+(72#64)>p.regs 1 then 27 else 11}
def remainingAfter (p : BPF.State) : BPF.State :=
  if p.regs 2+(8#64)>p.regs 1 then guard8After p else guard72After (guard8After p)

theorem decode5 : BPF.decode proof 5=.ok ⟨183,3,0,0,8⟩ := rfl

theorem decode6 : BPF.decode proof 6=.ok ⟨15,3,2,0,0⟩ := rfl

theorem decode7 : BPF.decode proof 7=.ok ⟨45,3,1,19,0⟩ := rfl

theorem decode8 : BPF.decode proof 8=.ok ⟨191,3,2,0,0⟩ := rfl

theorem decode9 : BPF.decode proof 9=.ok ⟨7,3,0,0,72⟩ := rfl

theorem decode10 : BPF.decode proof 10=.ok ⟨45,3,1,16,0⟩ := rfl

theorem guard8_move_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=5) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof (p)=.ok ⟨guard8Move p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode5,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,Except.map,
    guard8Move,guard8Add,guard8After,guard72Move,guard72Add,guard72After,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad,BitVec.add_comm]

theorem guard8_add_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=5) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof (guard8Move p)=.ok ⟨guard8Add p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode6,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,Except.map,
    guard8Move,guard8Add,guard8After,guard72Move,guard72Add,guard72After,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad,BitVec.add_comm]

theorem guard8_branch_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=5) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof (guard8Add p)=.ok ⟨guard8After p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode7,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,Except.map,
    guard8Move,guard8Add,guard8After,guard72Move,guard72Add,guard72After,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad,BitVec.add_comm]

theorem guard72_move_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=8) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof (p)=.ok ⟨guard72Move p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode8,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,Except.map,
    guard8Move,guard8Add,guard8After,guard72Move,guard72Add,guard72After,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad,BitVec.add_comm]

theorem guard72_add_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=8) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof (guard72Move p)=.ok ⟨guard72Add p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode9,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,Except.map,
    guard8Move,guard8Add,guard8After,guard72Move,guard72Add,guard72After,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad,BitVec.add_comm]

theorem guard72_branch_step (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=8) (active : p.halted=false) :
    BPFPlatform.step (environment env) proof (guard72Add p)=.ok ⟨guard72After p,[],none⟩ := by
  simp +decide [BPFPlatform.step,environment,position,active,decode10,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,Except.map,
    guard8Move,guard8Add,guard8After,guard72Move,guard72Add,guard72After,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad,BitVec.add_comm]

theorem guard8_execution (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=5) (active : p.halted=false) :
    Execution (instructionStep env) p [] (guard8After p) := by
  have a : instructionStep env p [] (guard8Move p) := ⟨_,guard8_move_step env p position active,rfl,rfl⟩
  have b : instructionStep env (guard8Move p) [] (guard8Add p) := ⟨_,guard8_add_step env p position active,rfl,rfl⟩
  have c : instructionStep env (guard8Add p) [] (guard8After p) := ⟨_,guard8_branch_step env p position active,rfl,rfl⟩
  simpa using Execution.next a (Execution.next b (Execution.next c (Execution.refl _)))

theorem guard72_execution (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=8) (active : p.halted=false) :
    Execution (instructionStep env) p [] (guard72After p) := by
  have a : instructionStep env p [] (guard72Move p) := ⟨_,guard72_move_step env p position active,rfl,rfl⟩
  have b : instructionStep env (guard72Move p) [] (guard72Add p) := ⟨_,guard72_add_step env p position active,rfl,rfl⟩
  have c : instructionStep env (guard72Add p) [] (guard72After p) := ⟨_,guard72_branch_step env p position active,rfl,rfl⟩
  simpa using Execution.next a (Execution.next b (Execution.next c (Execution.refl _)))

/-- B29 follows +8 then +72, using actual checked successors. Arithmetic is
64-bit modular addition in both streams, with no non-wrapping premise. -/
theorem remaining_execution (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=5) (active : p.halted=false) :
    Execution (instructionStep env) p [] (remainingAfter p) := by
  have headRun := guard8_execution env p position active
  by_cases reject8 : p.regs 2+(8#64)>p.regs 1
  · simpa only [remainingAfter,reject8,ite_true] using headRun
  · have at8 : (guard8After p).pc=8 := by simp [guard8After,reject8]
    have tailRun := guard72_execution env (guard8After p) at8 (by simpa [guard8After,guard8Add,guard8Move] using active)
    simpa only [remainingAfter,reject8,ite_false,List.nil_append] using headRun.append tailRun

theorem remaining_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=17) (proofPC : p.pc=5) (active : p.halted=false)
    (pointer : n.gpr 6=p.regs 2) (limit : n.gpr 2=p.regs 1) :
    X86Path.Execution 0 native n [] (remainingNativeFinal n) ∧
    Execution (instructionStep env) p [] (remainingAfter p) ∧
    (remainingNativeFinal n).pc=(if p.regs 2+(8#64)>p.regs 1 ∨ p.regs 2+(72#64)>p.regs 1 then 60 else 35) ∧
    (remainingAfter p).pc=(if p.regs 2+(8#64)>p.regs 1 ∨ p.regs 2+(72#64)>p.regs 1 then 27 else 11) ∧
    (remainingNativeFinal n).memory=n.memory ∧ (remainingAfter p).memory=p.memory := by
  refine ⟨remaining_native_guards n nativePC,remaining_execution env p proofPC active,?_,?_,?_,?_⟩
  · simpa only [pointer,limit] using remaining_native_successor n
  all_goals by_cases reject8 : p.regs 2+(8#64)>p.regs 1
  all_goals by_cases reject72 : p.regs 2+(72#64)>p.regs 1
  all_goals simp +decide [remainingNativeFinal,remainingNative72,remainingNativeCmp72,remainingNativeAdd,
      remainingNative8,remainingNativeCmp8,remainingNativeLea,remainingAfter,
      guard8After,guard8Add,guard8Move,guard72After,guard72Add,guard72Move,
      BPF.setReg,pointer,limit,reject8,reject72]

/-- Every canonical relational execution of these native byte extents has
this same exact endpoint and empty effects; the paired B29 follows the same
branch order. The only path witness is computed from actual input values. -/
theorem remaining_relational_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (actual : Transition X86.State)
    (nativePC : n.pc=17) (proofPC : p.pc=5) (active : p.halted=false)
    (pointer : n.gpr 6=p.regs 2) (limit : n.gpr 2=p.regs 1)
    (run : CanonicalRelationalPath 0 native (remainingNativePath n) n actual) :
    actual=⟨remainingNativeFinal n,[],none⟩ ∧
    Execution (instructionStep env) p actual.events (remainingAfter p) ∧
    actual.state.pc=(if p.regs 2+(8#64)>p.regs 1 ∨ p.regs 2+(72#64)>p.regs 1 then 60 else 35) ∧
    (remainingAfter p).pc=(if p.regs 2+(8#64)>p.regs 1 ∨ p.regs 2+(72#64)>p.regs 1 then 27 else 11) := by
  obtain ⟨unique,_⟩ := defined_relational_result_unique run (remaining_native_path_defined n)
    (remaining_native_path_evaluation n nativePC)
  obtain ⟨_,proofRun,npc,ppc,_,_⟩ := remaining_component env n p nativePC proofPC active pointer limit
  exact ⟨unique,by simpa only [unique] using proofRun,by simpa only [unique] using npc,ppc⟩

end KProgTV.TrustedSimpleB29
#print axioms KProgTV.TrustedSimpleB29.stack_step
#print axioms KProgTV.TrustedSimpleB29.data_step
#print axioms KProgTV.TrustedSimpleB29.end_step
#print axioms KProgTV.TrustedSimpleB29.entry_context_component

#print axioms KProgTV.TrustedSimpleB29.context_fault_step
#print axioms KProgTV.TrustedSimpleB29.first_context_fault
#print axioms KProgTV.TrustedSimpleB29.second_context_fault
#print axioms KProgTV.TrustedSimpleB29.zero_step
#print axioms KProgTV.TrustedSimpleB29.guard_step
#print axioms KProgTV.TrustedSimpleB29.first_guard_component

#print axioms KProgTV.TrustedSimpleB29.first_guard_relational_component
#print axioms KProgTV.TrustedSimpleB29.entry_first_guard_component

#print axioms KProgTV.TrustedSimpleB29.guard8_move_step
#print axioms KProgTV.TrustedSimpleB29.guard8_add_step
#print axioms KProgTV.TrustedSimpleB29.guard8_branch_step
#print axioms KProgTV.TrustedSimpleB29.guard72_move_step
#print axioms KProgTV.TrustedSimpleB29.guard72_add_step
#print axioms KProgTV.TrustedSimpleB29.guard72_branch_step
#print axioms KProgTV.TrustedSimpleB29.guard8_execution
#print axioms KProgTV.TrustedSimpleB29.guard72_execution
#print axioms KProgTV.TrustedSimpleB29.remaining_execution
#print axioms KProgTV.TrustedSimpleB29.remaining_component
#print axioms KProgTV.TrustedSimpleB29.remaining_relational_component
