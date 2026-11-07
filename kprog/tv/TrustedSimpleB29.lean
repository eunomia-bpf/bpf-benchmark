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

end KProgTV.TrustedSimpleB29
#print axioms KProgTV.TrustedSimpleB29.stack_step
#print axioms KProgTV.TrustedSimpleB29.data_step
#print axioms KProgTV.TrustedSimpleB29.end_step
#print axioms KProgTV.TrustedSimpleB29.entry_context_component
