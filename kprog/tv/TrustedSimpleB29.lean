import TrustedSimpleX86
import TrustedSimpleSafety

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


/-- Outside the two bound context PCs, use the same ordinary BPF rule. -/
theorem ordinary_step (env : BPF.Environment) (p : BPF.State)
    (outside1 : p.pc≠1) (outside2 : p.pc≠2) :
    BPFPlatform.step (environment env) proof p=BPF.step env proof p := by
  cases active : p.halted <;> by_cases negative : p.pc<0 <;>
    simp [BPFPlatform.step,environment,BPF.step,outside1,outside2,active,negative,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  cases BPF.decode proof p.pc.toNat <;> rfl

theorem ordinary_execution (env : BPF.Environment) (positions : List Nat)
    (p : BPF.State) (result : Transition BPF.State)
    (outside : ∀ pc ∈ positions, pc≠1 ∧ pc≠2)
    (accepted : BPFPath.evaluate env proof positions p=.ok result) :
    Execution (instructionStep env) p result.events result.state := by
  exact BPFPath.evaluate_execution_transport env proof id (instructionStep env)
    (fun pc => pc≠1 ∧ pc≠2)
    (by
      intro state pc allowed position effect actual
      have one : state.pc≠1 := by omega
      have two : state.pc≠2 := by omega
      exact ⟨effect,(ordinary_step env state one two).trans actual,rfl,rfl⟩)
    positions outside p result accepted

theorem decode11 : BPF.decode proof 11=.ok ⟨183,1,0,0,0⟩ := rfl

theorem decode12 : BPF.decode proof 12=.ok ⟨183,3,0,0,0⟩ := rfl

theorem decode13 : BPF.decode proof 13=.ok ⟨15,3,2,0,0⟩ := rfl

theorem decode14 : BPF.decode proof 14=.ok ⟨183,4,0,0,24910⟩ := rfl

theorem decode15 : BPF.decode proof 15=.ok ⟨107,3,4,0,0⟩ := rfl

theorem decode16 : BPF.decode proof 16=.ok ⟨183,3,0,0,2⟩ := rfl

theorem decode17 : BPF.decode proof 17=.ok ⟨15,3,2,0,0⟩ := rfl

theorem decode18 : BPF.decode proof 18=.ok ⟨183,4,0,0,188⟩ := rfl

theorem decode19 : BPF.decode proof 19=.ok ⟨115,3,4,0,0⟩ := rfl

theorem decode20 : BPF.decode proof 20=.ok ⟨183,3,0,0,3⟩ := rfl

theorem decode21 : BPF.decode proof 21=.ok ⟨15,3,2,0,0⟩ := rfl

theorem decode22 : BPF.decode proof 22=.ok ⟨99,3,1,0,0⟩ := rfl

theorem decode23 : BPF.decode proof 23=.ok ⟨183,3,0,0,7⟩ := rfl

theorem decode24 : BPF.decode proof 24=.ok ⟨15,3,2,0,0⟩ := rfl

theorem decode25 : BPF.decode proof 25=.ok ⟨115,3,1,0,0⟩ := rfl

theorem decode26 : BPF.decode proof 26=.ok ⟨180,0,0,0,2⟩ := rfl

theorem decode27 : BPF.decode proof 27=.ok ⟨5,0,0,0,0⟩ := rfl

theorem decode28 : BPF.decode proof 28=.ok ⟨149,0,0,0,0⟩ := rfl

def storesAfter (p : BPF.State) : BPF.State :=
  {BPF.setReg (BPF.setReg (BPF.setReg (BPF.setReg p 1 0) 3 (p.regs 2+(7#64))) 4 188) 0 2 with
    memory := packetWriteMemory p.memory (p.regs 2)
    pc := 27}

/-- Exact successful store block and result MOV of B29. No permission test is
inserted into either program: these premises describe the successful cases. -/
theorem stores_evaluation (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=11) (active : p.halted=false)
    (write0 : permitted p.memory.writable (p.regs 2) 2=true)
    (write2 : permitted p.memory.writable (p.regs 2+(2#64)) 1=true)
    (write3 : permitted p.memory.writable (p.regs 2+(3#64)) 4=true)
    (write7 : permitted p.memory.writable (p.regs 2+(7#64)) 1=true) :
    BPFPath.evaluate env proof [11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26] p=
      .ok ⟨storesAfter p,packetWriteEvents (p.regs 2),none⟩ := by
  have plus2 : (2#64)+p.regs 2=p.regs 2+(2#64) := BitVec.add_comm _ _
  have plus3 : (3#64)+p.regs 2=p.regs 2+(3#64) := BitVec.add_comm _ _
  have plus7 : (7#64)+p.regs 2=p.regs 2+(7#64) := BitVec.add_comm _ _
  simp +decide [BPFPath.evaluate,decode11,decode12,decode13,decode14,decode15,decode16,
    decode17,decode18,decode19,decode20,decode21,decode22,decode23,decode24,decode25,decode26,
    BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,writeMemory,position,active,
    storesAfter,packetWriteMemory,packetWriteEvents,storeMemory,
    plus2,plus3,plus7,write0,write2,write3,write7,
    Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  funext index
  by_cases zero : index=0 <;> by_cases one : index=1 <;>
    by_cases three : index=3 <;> by_cases four : index=4 <;> simp [zero,one,three,four]

theorem stores_execution (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=11) (active : p.halted=false)
    (write0 : permitted p.memory.writable (p.regs 2) 2=true)
    (write2 : permitted p.memory.writable (p.regs 2+(2#64)) 1=true)
    (write3 : permitted p.memory.writable (p.regs 2+(3#64)) 4=true)
    (write7 : permitted p.memory.writable (p.regs 2+(7#64)) 1=true) :
    Execution (instructionStep env) p (packetWriteEvents (p.regs 2)) (storesAfter p) := by
  exact ordinary_execution env [11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26] p
    ⟨storesAfter p,packetWriteEvents (p.regs 2),none⟩
    (by intro pc inside; simp at inside; omega)
    (stores_evaluation env p position active write0 write2 write3 write7)

theorem stores_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=35) (proofPC : p.pc=11) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (memory : n.memory=p.memory)
    (write0 : permitted p.memory.writable (p.regs 2) 2=true)
    (write2 : permitted p.memory.writable (p.regs 2+(2#64)) 1=true)
    (write3 : permitted p.memory.writable (p.regs 2+(3#64)) 4=true)
    (write7 : permitted p.memory.writable (p.regs 2+(7#64)) 1=true) :
    X86Path.Execution 0 native n (packetWriteEvents (p.regs 2)) (packetNativeFinal n) ∧
    Execution (instructionStep env) p (packetWriteEvents (p.regs 2)) (storesAfter p) ∧
    (packetNativeFinal n).memory=(storesAfter p).memory ∧
    (packetNativeFinal n).gpr 0=(storesAfter p).regs 0 ∧
    (packetNativeFinal n).pc=60 ∧ (storesAfter p).pc=27 := by
  refine ⟨?_,stores_execution env p proofPC active write0 write2 write3 write7,?_,?_,rfl,rfl⟩
  · simpa only [pointer] using native_packet_execution n nativePC
      (by simpa only [memory,pointer] using write0) (by simpa only [memory,pointer] using write2)
      (by simpa only [memory,pointer] using write3) (by simpa only [memory,pointer] using write7)
  all_goals simp +decide [packetNativeFinal,packetNativeFourth,packetNativeThird,packetNativeSecond,packetNativeFirst,
    storesAfter,packetWriteMemory,BPF.setReg,memory,pointer]


-- Full partial state before the same faulting store, with actual B29 PCs.
def storesFaultState (p : BPF.State) (index : Nat) : BPF.State :=
  {packetProofFaultState p index with pc:=(packetProofFaultState p index).pc-7}
def storesFaultPath : Nat → List Nat
  | 0 => [11,12,13,14,15]
  | 1 => [11,12,13,14,15,16,17,18,19]
  | 2 => [11,12,13,14,15,16,17,18,19,20,21,22]
  | _ => [11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]

/-- Every first failing store of actual B29. Only successful earlier writes
occur, and the failing operation preserves the complete incoming fault state. -/
theorem stores_fault_evaluation (env : BPF.Environment) (p : BPF.State) (index : Nat)
    (bounded : index<4) (position : p.pc=11) (active : p.halted=false)
    (prior : ∀ i<index, packetStorePermission p.memory (p.regs 2) i=true)
    (bad : packetStorePermission p.memory (p.regs 2) index=false) :
    BPFPath.evaluate env proof (storesFaultPath index) p=
      .ok ⟨storesFaultState p index,packetFaultEvents (p.regs 2) index,
        some (packetStoreFault (p.regs 2) index)⟩ := by
  have plus2 : (2#64)+p.regs 2=p.regs 2+(2#64) := BitVec.add_comm _ _
  have plus3 : (3#64)+p.regs 2=p.regs 2+(3#64) := BitVec.add_comm _ _
  have plus7 : (7#64)+p.regs 2=p.regs 2+(7#64) := BitVec.add_comm _ _
  have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
  rcases choices with rfl | rfl | rfl | rfl
  · simp only [packetStorePermission] at bad
    simp +decide [BPFPath.evaluate,decode11,decode12,decode13,decode14,decode15,decode16,
      decode17,decode18,decode19,decode20,decode21,decode22,decode23,decode24,decode25,
      BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,writeMemory,position,active,
      storesFaultPath,storesFaultState,packetProofFaultState,packetProofBeforeFirst,packetStoredPrefix,
      packetFaultEvents,packetStoreFault,packetWriteEvents,storeMemory,plus2,plus3,plus7,bad,
      Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    funext r
    by_cases one : r=1 <;> by_cases three : r=3 <;> by_cases four : r=4 <;> simp [one,three,four]
  · have w0 := prior 0 (by omega)
    simp only [packetStorePermission] at w0 bad
    simp +decide [BPFPath.evaluate,decode11,decode12,decode13,decode14,decode15,decode16,
      decode17,decode18,decode19,decode20,decode21,decode22,decode23,decode24,decode25,
      BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,writeMemory,position,active,
      storesFaultPath,storesFaultState,packetProofFaultState,packetProofBeforeFirst,packetStoredPrefix,
      packetFaultEvents,packetStoreFault,packetWriteEvents,storeMemory,plus2,plus3,plus7,w0,bad,
      Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    funext r
    by_cases one : r=1 <;> by_cases three : r=3 <;> by_cases four : r=4 <;> simp [one,three,four]
  · have w0 := prior 0 (by omega)
    have w1 := prior 1 (by omega)
    simp only [packetStorePermission] at w0 w1 bad
    simp +decide [BPFPath.evaluate,decode11,decode12,decode13,decode14,decode15,decode16,
      decode17,decode18,decode19,decode20,decode21,decode22,decode23,decode24,decode25,
      BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,writeMemory,position,active,
      storesFaultPath,storesFaultState,packetProofFaultState,packetProofBeforeFirst,packetStoredPrefix,
      packetFaultEvents,packetStoreFault,packetWriteEvents,storeMemory,plus2,plus3,plus7,w0,w1,bad,
      Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    funext r
    by_cases one : r=1 <;> by_cases three : r=3 <;> by_cases four : r=4 <;> simp [one,three,four]
  · have w0 := prior 0 (by omega)
    have w1 := prior 1 (by omega)
    have w2 := prior 2 (by omega)
    simp only [packetStorePermission] at w0 w1 w2 bad
    simp +decide [BPFPath.evaluate,decode11,decode12,decode13,decode14,decode15,decode16,
      decode17,decode18,decode19,decode20,decode21,decode22,decode23,decode24,decode25,
      BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,writeMemory,position,active,
      storesFaultPath,storesFaultState,packetProofFaultState,packetProofBeforeFirst,packetStoredPrefix,
      packetFaultEvents,packetStoreFault,packetWriteEvents,storeMemory,plus2,plus3,plus7,w0,w1,w2,bad,
      Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    funext r
    by_cases one : r=1 <;> by_cases three : r=3 <;> by_cases four : r=4 <;> simp [one,three,four]

theorem stores_fault_execution (env : BPF.Environment) (p : BPF.State) (index : Nat)
    (bounded : index<4) (position : p.pc=11) (active : p.halted=false)
    (prior : ∀ i<index, packetStorePermission p.memory (p.regs 2) i=true)
    (bad : packetStorePermission p.memory (p.regs 2) index=false) :
    Execution (instructionStep env) p (packetFaultEvents (p.regs 2) index) (storesFaultState p index) := by
  have outside : ∀ pc ∈ storesFaultPath index, pc≠1 ∧ pc≠2 := by
    intro pc inside
    unfold storesFaultPath at inside
    split at inside <;> simp_all <;> omega
  exact ordinary_execution env (storesFaultPath index) p
    ⟨storesFaultState p index,packetFaultEvents (p.regs 2) index,some (packetStoreFault (p.regs 2) index)⟩
    outside (stores_fault_evaluation env p index bounded position active prior bad)

theorem stores_fault_component (env : BPF.Environment) (n : X86.State) (p : BPF.State) (index : Nat)
    (bounded : index<4) (nativePC : n.pc=35) (proofPC : p.pc=11) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (memory : n.memory=p.memory)
    (prior : ∀ i<index, packetStorePermission p.memory (p.regs 2) i=true)
    (bad : packetStorePermission p.memory (p.regs 2) index=false) :
    X86Path.Execution 0 native n (packetFaultEvents (p.regs 2) index) (packetNativeFaultState n index) ∧
    Execution (instructionStep env) p (packetFaultEvents (p.regs 2) index) (storesFaultState p index) ∧
    (packetNativeFaultState n index).memory=(storesFaultState p index).memory := by
  have evaluated := packet_all_native_store_faults n index bounded nativePC
    (by simpa only [memory,pointer] using prior) (by simpa only [memory,pointer] using bad)
  refine ⟨?_,stores_fault_execution env p index bounded proofPC active prior bad,?_⟩
  · simpa only [pointer] using X86Path.evaluate_sound _ _ _ _ _ evaluated
  · have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
    rcases choices with rfl | rfl | rfl | rfl
    all_goals simp only [storesFaultState,packetProofFaultState,packetProofBeforeFirst,
      packetNativeFaultState,packetNativeFirst,packetNativeSecond,packetNativeThird,
      packetStoredPrefix,BPF.setReg,memory,pointer]


def exitAfter (p : BPF.State) : BPF.State := {p with pc:=29,halted:=true}

/-- Actual JA/EXIT trailer. It retains every register, memory and effect;
the native body's corresponding boundary is PC60 before the JIT epilogue. -/
theorem exit_evaluation (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=27) (active : p.halted=false) :
    BPFPath.evaluate env proof [27,28] p=.ok ⟨exitAfter p,[],none⟩ := by
  simp +decide [BPFPath.evaluate,decode27,decode28,BPF.execute,position,active,exitAfter,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

theorem exit_execution (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=27) (active : p.halted=false) :
    Execution (instructionStep env) p [] (exitAfter p) := by
  exact ordinary_execution env [27,28] p ⟨exitAfter p,[],none⟩
    (by intro pc inside; simp at inside; omega) (exit_evaluation env p position active)


def storesOutcome (p : BPF.State) (index : Nat) : BPF.State :=
  if index=4 then storesAfter p else storesFaultState p index

/-- Total packet block for every canonical byte-permission assignment.
Selection is a certificate computation, not an inserted native/BPF check. -/
theorem stores_any_permissions (env : BPF.Environment) (n : X86.State) (p : BPF.State) (index : Nat)
    (nativePC : n.pc=35) (proofPC : p.pc=11) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (memory : n.memory=p.memory)
    (selected : index=packetFirstFailure p.memory (p.regs 2)) :
    index≤4 ∧
    X86Path.Execution 0 native n (packetOutcomeEvents (p.regs 2) index) (packetNativeOutcome n index) ∧
    Execution (instructionStep env) p (packetOutcomeEvents (p.regs 2) index) (storesOutcome p index) ∧
    (packetNativeOutcome n index).memory=(storesOutcome p index).memory := by
  have spec := packet_first_failure_spec p.memory (p.regs 2)
  change packetFirstFailure p.memory (p.regs 2)≤4 ∧ _ at spec
  rw [← selected] at spec
  by_cases success : index=4
  · have permissions := spec.2.2 success
    obtain ⟨nativeRun,proofRun,same,_,_,_⟩ := stores_component env n p nativePC proofPC active pointer memory
      (permissions 0 (by omega)) (permissions 1 (by omega))
      (permissions 2 (by omega)) (permissions 3 (by omega))
    refine ⟨spec.1,?_,?_,?_⟩
    · simpa only [packetOutcomeEvents,packetNativeOutcome,success,ite_true] using nativeRun
    · simpa only [packetOutcomeEvents,storesOutcome,success,ite_true] using proofRun
    · simpa only [packetNativeOutcome,storesOutcome,success,ite_true] using same
  · have failed : index<4 := by omega
    obtain ⟨prior,bad⟩ := spec.2.1 failed
    obtain ⟨nativeRun,proofRun,same⟩ := stores_fault_component env n p index failed
      nativePC proofPC active pointer memory prior bad
    refine ⟨spec.1,?_,?_,?_⟩
    · simpa only [packetOutcomeEvents,packetNativeOutcome,success,ite_false] using nativeRun
    · simpa only [packetOutcomeEvents,storesOutcome,success,ite_false] using proofRun
    · simpa only [packetNativeOutcome,storesOutcome,success,ite_false] using same

/-- Every canonical relational native execution of the actual selected store
path is paired with B29, including the precise first fault and partial memory.
No successful permission, branch value, or native next-state premise is used. -/
theorem stores_relational_component (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (index : Nat) (actual : Transition X86.State)
    (nativePC : n.pc=35) (proofPC : p.pc=11) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (memory : n.memory=p.memory)
    (selected : index=packetFirstFailure p.memory (p.regs 2))
    (run : CanonicalRelationalPath 0 native (packetNativeOutcomePath index) n actual) :
    actual=⟨packetNativeOutcome n index,packetOutcomeEvents (p.regs 2) index,
      if index=4 then none else some (packetStoreFault (p.regs 2) index)⟩ ∧
    Execution (instructionStep env) p actual.events (storesOutcome p index) ∧
    actual.state.memory=(storesOutcome p index).memory := by
  obtain ⟨bounded,_,proofRun,same⟩ := stores_any_permissions env n p index nativePC proofPC active pointer memory selected
  have nativeSelected : index=packetFirstFailure n.memory (n.gpr 1) := by simpa only [memory,pointer] using selected
  obtain ⟨unique,_⟩ := defined_relational_result_unique run (packet_outcome_path_defined index bounded)
    (packet_native_any_evaluation n index nativePC nativeSelected)
  have endpoint : actual=⟨packetNativeOutcome n index,packetOutcomeEvents (p.regs 2) index,
      if index=4 then none else some (packetStoreFault (p.regs 2) index)⟩ := by simpa only [pointer] using unique
  exact ⟨endpoint,by simpa only [endpoint] using proofRun,by simpa only [endpoint] using same⟩


def guardsAfter (p : BPF.State) (stack pointer limit : Word) : BPF.State :=
  let first := guardAfter (contextAfter p stack pointer limit)
  if pointer>limit then first else remainingAfter first

/-- Connect the actual entry and all three conditional blocks, in their
native order. No branch outcome or non-wrapping pointer arithmetic is assumed. -/
theorem entry_guards_execution (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second)) :
    X86Path.Execution 0 native n [first,second] (guardedNativeFinal n pointer limit) ∧
    Execution (instructionStep env) p [first,second] (guardsAfter p stack pointer limit) := by
  obtain ⟨nativeHead,proofHead,npc,ppc,_,_⟩ := entry_first_guard_component env n p stack pointer limit
    first second nativePC proofPC active argument memory input read0 read1
  by_cases reject : pointer>limit
  · exact ⟨by simpa only [guardedNativeFinal,reject,ite_true] using nativeHead,
      by simpa only [guardsAfter,reject,ite_true] using proofHead⟩
  · have at17 : (guardFinal (nativePrefixFinal n pointer limit)).pc=17 := by simpa [reject] using npc
    have at5 : (guardAfter (contextAfter p stack pointer limit)).pc=5 := by simpa [reject] using ppc
    have stillActive : (guardAfter (contextAfter p stack pointer limit)).halted=false := by
      simpa [guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter] using active
    have ptr : (guardFinal (nativePrefixFinal n pointer limit)).gpr 6=
        (guardAfter (contextAfter p stack pointer limit)).regs 2 := by
      simp +decide [guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter,
        guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg]
    have lim : (guardFinal (nativePrefixFinal n pointer limit)).gpr 2=
        (guardAfter (contextAfter p stack pointer limit)).regs 1 := by
      simp +decide [guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter,
        guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg]
    obtain ⟨nativeTail,proofTail,_,_,_,_⟩ := remaining_component env
      (guardFinal (nativePrefixFinal n pointer limit)) (guardAfter (contextAfter p stack pointer limit))
      at17 at5 stillActive ptr lim
    exact ⟨by simpa only [guardedNativeFinal,reject,ite_false,List.append_nil] using native_execution_append nativeHead nativeTail,
      by simpa only [guardsAfter,reject,ite_false,List.append_nil] using proofHead.append proofTail⟩

/-- Exact boundary facts derived from full states, including data pointer,
zero result, memory and the actual exit/store successors. -/
theorem guards_boundary (n : X86.State) (p : BPF.State) (stack pointer limit : Word)
    (memory : n.memory=p.memory) (active : p.halted=false) :
    (guardedNativeFinal n pointer limit).pc=
      (if pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit then 60 else 35) ∧
    (guardsAfter p stack pointer limit).pc=
      (if pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit then 27 else 11) ∧
    (guardedNativeFinal n pointer limit).gpr 1=pointer ∧
    (guardsAfter p stack pointer limit).regs 2=pointer ∧
    (guardedNativeFinal n pointer limit).gpr 0=(0#64) ∧
    (guardsAfter p stack pointer limit).regs 0=(0#64) ∧
    (guardedNativeFinal n pointer limit).memory=(guardsAfter p stack pointer limit).memory ∧
    (guardsAfter p stack pointer limit).memory=p.memory ∧
    (guardsAfter p stack pointer limit).halted=false := by
  by_cases reject : pointer>limit
  all_goals by_cases reject8 : pointer+(8#64)>limit
  all_goals by_cases reject72 : pointer+(72#64)>limit
  all_goals simp +decide [guardedNativeFinal,guardsAfter,remainingNativeFinal,
    remainingNative72,remainingNativeCmp72,remainingNativeAdd,remainingNative8,remainingNativeCmp8,remainingNativeLea,
    guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter,
    remainingAfter,guard72After,guard72Add,guard72Move,guard8After,guard8Add,guard8Move,
    guardAfter,zeroAfter,contextAfter,dataAfter,stackAfter,BPF.setReg,memory,active,reject,reject8,reject72]


def completedAfter (p : BPF.State) (stack pointer limit : Word) : BPF.State :=
  let guarded := guardsAfter p stack pointer limit
  if pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit then exitAfter guarded
  else
    let index := packetFirstFailure p.memory pointer
    let stored := storesOutcome guarded index
    if index=4 then exitAfter stored else stored

/-- Connect all actual B29 blocks after the two successful context reads.
Every store permission assignment and every guard outcome is covered. -/
theorem completed_proof_execution (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second)) :
    Execution (instructionStep env) p ([first,second]++completeGuestSuffix p.memory pointer limit)
      (completedAfter p stack pointer limit) ∧
    (completeNativeFinal n pointer limit).memory=(completedAfter p stack pointer limit).memory := by
  obtain ⟨_,guardRun⟩ := entry_guards_execution env n p stack pointer limit first second
    nativePC proofPC active argument memory input read0 read1
  obtain ⟨npc,ppc,np,pp,nzero,pzero,same,pmemory,pactive⟩ := guards_boundary n p stack pointer limit memory active
  by_cases reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit
  · have at27 : (guardsAfter p stack pointer limit).pc=27 := by simpa [reject] using ppc
    have exited := exit_execution env (guardsAfter p stack pointer limit) at27 pactive
    refine ⟨?_,?_⟩
    · simpa only [completedAfter,completeGuestSuffix,reject,ite_true,List.append_nil] using guardRun.append exited
    · simpa only [completeNativeFinal,completedAfter,reject,ite_true,exitAfter] using same
  · have at35 : (guardedNativeFinal n pointer limit).pc=35 := by simpa [reject] using npc
    have at11 : (guardsAfter p stack pointer limit).pc=11 := by simpa [reject] using ppc
    have ptr : (guardedNativeFinal n pointer limit).gpr 1=(guardsAfter p stack pointer limit).regs 2 := np.trans pp.symm
    have selected : packetFirstFailure p.memory pointer=
        packetFirstFailure (guardsAfter p stack pointer limit).memory ((guardsAfter p stack pointer limit).regs 2) := by rw [pmemory,pp]
    obtain ⟨_,_,stored,storeMemory⟩ := stores_any_permissions env
      (guardedNativeFinal n pointer limit) (guardsAfter p stack pointer limit)
      (packetFirstFailure p.memory pointer) at35 at11 pactive ptr same selected
    have originalIndex : packetFirstFailure n.memory pointer=packetFirstFailure p.memory pointer := by rw [memory]
    by_cases success : packetFirstFailure p.memory pointer=4
    · have storedPC : (storesOutcome (guardsAfter p stack pointer limit) (packetFirstFailure p.memory pointer)).pc=27 := by
        simp only [storesOutcome,success,ite_true,storesAfter]
      have storedActive : (storesOutcome (guardsAfter p stack pointer limit) (packetFirstFailure p.memory pointer)).halted=false := by
        simpa only [storesOutcome,success,ite_true,storesAfter,BPF.setReg] using pactive
      have exited := exit_execution env _ storedPC storedActive
      have total := guardRun.append (stored.append exited)
      refine ⟨?_,?_⟩
      · simpa only [completedAfter,completeGuestSuffix,reject,ite_false,success,ite_true,
          pp,List.append_nil] using total
      · simpa only [completeNativeFinal,completedAfter,reject,ite_false,success,ite_true,
          originalIndex,exitAfter] using storeMemory
    · refine ⟨?_,?_⟩
      · simpa only [completedAfter,completeGuestSuffix,reject,ite_false,success,pp] using guardRun.append stored
      · simpa only [completeNativeFinal,completedAfter,reject,ite_false,success,originalIndex] using storeMemory

/-- Pair every canonical relational complete native path with actual B29.
The native endpoint/fault is derived by the single reference semantics; B's
exact execution has the same ordered guest effects and final memory. -/
theorem completed_relational_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack pointer limit : Word) (first second : Event) (actual : Transition X86.State)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second))
    (run : CanonicalRelationalPath 0 native (completeNativePath n pointer limit) n actual) :
    actual=completeNativeResult n pointer limit first second ∧
    Execution (instructionStep env) p actual.events (completedAfter p stack pointer limit) ∧
    actual.state.memory=(completedAfter p stack pointer limit).memory := by
  have nativeRead0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by simpa only [memory,argument] using read0
  have nativeRead1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second) := by simpa only [memory,argument] using read1
  have endpoint := complete_native_relational_result n pointer limit first second actual nativePC nativeRead0 nativeRead1 run
  obtain ⟨proofRun,same⟩ := completed_proof_execution env n p stack pointer limit first second
    nativePC proofPC active argument memory input read0 read1
  exact ⟨endpoint,by simpa only [endpoint,completeNativeResult,memory] using proofRun,
    by simpa only [endpoint,completeNativeResult] using same⟩


def allInputsAfter (p : BPF.State) (stack : Word) : BPF.State :=
  match readMemory p.memory (p.regs 1) 8 with
  | .error _ => stackAfter p stack
  | .ok (pointer,_) =>
    match readMemory p.memory (p.regs 1+(8#64)) 8 with
    | .error _ => dataAfter p stack pointer
    | .ok (limit,_) => completedAfter p stack pointer limit

/-- One actual B29 execution for every context read, guard and store outcome.
No guest permission, branch result or native successor is an input premise. -/
theorem all_inputs_execution (env : BPF.Environment) (n : X86.State) (p : BPF.State) (stack : Word)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack) :
    Execution (instructionStep env) p (allReadNativeResult n).events (allInputsAfter p stack) ∧
    (allReadNativeResult n).state.memory=(allInputsAfter p stack).memory := by
  cases read0 : readMemory p.memory (p.regs 1) 8 with
  | error fault =>
    obtain ⟨bad,rfl⟩ := canonical_read_error read0
    obtain ⟨_,run⟩ := first_context_fault env n p stack nativePC proofPC active argument memory input bad
    refine ⟨?_,?_⟩
    · simpa only [allReadNativeResult,allInputsAfter,memory,argument,read0] using run
    · simp only [allReadNativeResult,allInputsAfter,memory,argument,read0,stackAfter,BPF.setReg]
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    cases read1 : readMemory p.memory (p.regs 1+(8#64)) 8 with
    | error fault =>
      obtain ⟨bad,rfl⟩ := canonical_read_error read1
      obtain ⟨_,run⟩ := second_context_fault env n p stack pointer first nativePC proofPC active argument memory input read0 bad
      refine ⟨?_,?_⟩
      · simpa only [allReadNativeResult,allInputsAfter,memory,argument,read0,read1] using run
      · simp only [allReadNativeResult,allInputsAfter,memory,argument,read0,read1,
          nativeAfter,dataAfter,stackAfter,BPF.setReg]
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      obtain ⟨run,same⟩ := completed_proof_execution env n p stack pointer limit first second
        nativePC proofPC active argument memory input read0 read1
      refine ⟨?_,?_⟩
      · simpa only [allReadNativeResult,allInputsAfter,completeNativeResult,memory,argument,read0,read1] using run
      · simpa only [allReadNativeResult,allInputsAfter,completeNativeResult,memory,argument,read0,read1] using same

/-- Every canonical relational result on the actual selected native path is
paired with the actual accepted B29, for all input read/write permissions and
all allowed undefined-AF choices. This is execution/effect composition; the
full architectural reconstruction and arbitrary-prefix TV remain separate. -/
theorem all_inputs_relational_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack : Word) (actual : Transition X86.State)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (input : env.nativeInput .stackPointer=.ok stack)
    (run : CanonicalRelationalPath 0 native (allReadNativePath n) n actual) :
    actual=allReadNativeResult n ∧
    Execution (instructionStep env) p actual.events (allInputsAfter p stack) ∧
    actual.state.memory=(allInputsAfter p stack).memory := by
  have endpoint := all_read_native_relational_result n actual nativePC run
  obtain ⟨proofRun,same⟩ := all_inputs_execution env n p stack nativePC proofPC active argument memory input
  exact ⟨endpoint,by simpa only [endpoint] using proofRun,by simpa only [endpoint] using same⟩


/-- The exact accepted B image with its bound context-conversion map. -/
def boundProofStep (env : BPF.Environment) (artifact : Artifact) : BlockStep BPF.State :=
  fun before events after => ∃ result,
    BPFPlatform.step (environment env) artifact.proofBytes.toArray before=.ok result ∧
    result.events=events ∧ result.state=after

/-- Actual B29 execution/effect validation, verifier soundness for the admitted
B state (assumed), and equality of the complete bound artifact imply checked
effects for EVERY finite native prefix. Native extents, all context/store
permissions, branch choices and undefined AF outputs are unrestricted.

Full Artifact equality includes bytes/entry/ABI/metadata. Kernel enforcement
of that equality and XDP conversion, reference ISA hardware fidelity, and
verifier soundness remain trusted. Physical JIT/caller transport and the full
architectural reconstruction relation are not asserted by this theorem. -/
theorem bound_native_prefix_effects_checked (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ artifact, accepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (boundProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    {trace : List Event} {last : X86.State}
    (run : Execution (TrustedSimpleSafety.relationalNativeInstructionStep
      (BitVec.ofNat 64 executed.entry) executed.nativeBytes.toArray) n trace last)
    (stack : Word) (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack) :
    ∀ event ∈ trace, checked validated event := by
  subst executed
  have canonicalRun : Execution (TrustedSimpleSafety.relationalNativeInstructionStep 0 native) n trace last := by
    simpa only [nativeImage,entryImage,Array.toArray_toList] using run
  obtain ⟨proofRun,_⟩ := all_inputs_execution env n p stack nativePC proofPC active argument memory nativeStack
  have stepEq : boundProofStep env validated=instructionStep env := by
    funext before events after
    unfold boundProofStep instructionStep
    rw [proofImage]
  have boundRun : Execution (boundProofStep env validated) p (allReadNativeResult n).events (allInputsAfter p stack) := by
    rw [stepEq]
    exact proofRun
  have completeChecked := verifierSound validated acceptance admitted _ _ boundRun
  exact TrustedSimpleSafety.captured_native_prefix_effects_checked (checked validated) n nativePC completeChecked canonicalRun


/-- Transport the exact B29 checked-effects theorem to an emitted native
payload base. Only PC changes in the logical transport; all invocation
registers, flags and memory are retained. Full JIT-image embedding is separate. -/
theorem bound_based_native_prefix_effects_checked (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (codeBase : Word) (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ artifact, accepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (boundProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    {trace : List Event} {last : X86.State}
    (run : Execution (TrustedSimpleSafety.relationalNativeInstructionStep
      (codeBase+BitVec.ofNat 64 executed.entry) executed.nativeBytes.toArray) n trace last)
    (stack : Word) (nativePC : n.pc=codeBase) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack) :
    ∀ event ∈ trace, checked validated event := by
  subst executed
  have canonicalRun : Execution (TrustedSimpleSafety.relationalNativeInstructionStep codeBase native) n trace last := by
    simpa only [nativeImage,entryImage,Array.toArray_toList,BitVec.add_zero] using run
  let logical := TrustedSimpleSafety.shiftNativeState (-codeBase) n
  have logicalPC : logical.pc=0 := by
    dsimp only [logical,TrustedSimpleSafety.shiftNativeState]
    rw [nativePC]
    unfold Word at *
    bv_decide
  have starts : TrustedSimpleSafety.shiftNativeState codeBase logical=n := by
    simpa only [logical,BitVec.neg_neg] using TrustedSimpleSafety.shift_native_state_inverse (-codeBase) n
  have valid : TrustedSimpleX86.simpleClosedPC logical.pc := by
    simp [TrustedSimpleX86.simpleClosedPC,TrustedSimpleX86.simpleNativeOffsets,logicalPC]
  obtain ⟨logicalLast,logicalRun,_⟩ := TrustedSimpleSafety.simple_native_based_execution_reflects codeBase
    canonicalRun logical valid starts
  have boundLogical : Execution (TrustedSimpleSafety.relationalNativeInstructionStep
      (BitVec.ofNat 64 validated.entry) validated.nativeBytes.toArray) logical trace logicalLast := by
    simpa only [nativeImage,entryImage,Array.toArray_toList] using logicalRun
  exact bound_native_prefix_effects_checked env logical p validated validated rfl nativeImage proofImage entryImage
    accepted proofEntry checked verifierSound acceptance admitted boundLogical stack logicalPC proofPC active argument memory nativeStack

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

#print axioms KProgTV.TrustedSimpleB29.ordinary_step
#print axioms KProgTV.TrustedSimpleB29.ordinary_execution
#print axioms KProgTV.TrustedSimpleB29.stores_evaluation
#print axioms KProgTV.TrustedSimpleB29.stores_execution
#print axioms KProgTV.TrustedSimpleB29.stores_component

#print axioms KProgTV.TrustedSimpleB29.stores_fault_evaluation
#print axioms KProgTV.TrustedSimpleB29.stores_fault_execution
#print axioms KProgTV.TrustedSimpleB29.stores_fault_component

#print axioms KProgTV.TrustedSimpleB29.exit_evaluation
#print axioms KProgTV.TrustedSimpleB29.exit_execution

#print axioms KProgTV.TrustedSimpleB29.stores_any_permissions
#print axioms KProgTV.TrustedSimpleB29.stores_relational_component

#print axioms KProgTV.TrustedSimpleB29.entry_guards_execution
#print axioms KProgTV.TrustedSimpleB29.guards_boundary

#print axioms KProgTV.TrustedSimpleB29.completed_proof_execution
#print axioms KProgTV.TrustedSimpleB29.completed_relational_correspondence

#print axioms KProgTV.TrustedSimpleB29.all_inputs_execution
#print axioms KProgTV.TrustedSimpleB29.all_inputs_relational_correspondence

#print axioms KProgTV.TrustedSimpleB29.bound_native_prefix_effects_checked

#print axioms KProgTV.TrustedSimpleB29.bound_based_native_prefix_effects_checked
