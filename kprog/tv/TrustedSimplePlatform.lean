import TrustedSimpleSafety

set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimplePlatform
open KProgFormal.Reference KProgTV.TrustedSimpleX86 KProgTV.TrustedSimpleSafety

/-- Whole physical interpretation of the two existing declared XDP context
expansions. This is derived metadata, not a newly captured kernel artifact.
The other35 instructions retain their exact accepted bytes and positions. -/
def physicalProof : Array Byte :=
  physical0 ++ proof.extract 8 16 ++ physical2 ++ proof.extract 24 proof.size

theorem physical_proof_size : physicalProof.size=296 := by decide

/-- Byte identity for the whole declared physical interpretation. -/
theorem physical_proof_literal : physicalProof = #[0x79,0x12,0x0,0x0,0x0,0x0,0x0,0x0,0x7b,0x2a,0xd8,0xff,0x0,0x0,0x0,0x0,0x79,0x11,0x8,0x0,0x0,0x0,0x0,0x0,0x7b,0x1a,0xe0,0xff,0x0,0x0,0x0,0x0,0xb4,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x7a,0xa,0xe8,0xff,0x0,0x0,0x0,0x0,0x7a,0xa,0xf0,0xff,0x0,0x0,0x0,0x0,0x62,0xa,0xf8,0xff,0x0,0x0,0x0,0x0,0xb7,0x90,0x1,0x0,0x2,0x0,0x0,0x0,0x79,0xa2,0xd8,0xff,0x0,0x0,0x0,0x0,0x79,0xa3,0xe0,0xff,0x0,0x0,0x0,0x0,0x2d,0x32,0x16,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0x8,0x0,0x0,0x0,0xbf,0x25,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x5,0x0,0x0,0x48,0x0,0x0,0x0,0x2d,0x35,0x12,0x0,0x0,0x0,0x0,0x0,0xf,0x24,0x0,0x0,0x0,0x0,0x0,0x0,0x2d,0x34,0x10,0x0,0x0,0x0,0x0,0x0,0xb7,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0x4e,0x61,0x0,0x0,0x6b,0x43,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x2,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0xbc,0x0,0x0,0x0,0x73,0x43,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x3,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x63,0x13,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x7,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x73,0x13,0x0,0x0,0x0,0x0,0x0,0x0,0xb4,0x1,0x0,0x0,0x2,0x0,0x0,0x0,0xbc,0x10,0x0,0x0,0x0,0x0,0x0,0x0,0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x95,0x0,0x0,0x0,0x0,0x0,0x0,0x0] := by decide

theorem physical_decode0 : BPF.decode physicalProof 0=.ok ⟨0x79,2,1,0,0⟩ := by
  rw [physical_proof_literal]
  rfl

theorem physical_decode2 : BPF.decode physicalProof 2=.ok ⟨0x79,1,1,8,0⟩ := by
  rw [physical_proof_literal]
  rfl

theorem virtual_decode2 : BPF.decode proof 2=.ok ⟨0x61,1,1,4,0⟩ := rfl

/-- Entire physical operation of the declared conversion, including faults. -/
theorem physical_context_step_0 (env : BPF.Environment) (s : BPF.State) (position : s.pc=0) :
    BPFPlatform.step (initializedPlatform env) proof s=BPF.step env physicalProof s := by
  cases active : s.halted with
  | true =>
    simp [BPFPlatform.step,BPF.step,active,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  | false =>
    have sourceStep : BPFPlatform.step (initializedPlatform env) proof s=BPFPlatform.expand env expansion0 s := by
      simp +decide [BPFPlatform.step,initializedPlatform,platform,active,position,virtual_decode0,
        expansion0,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    have physicalStep : BPF.step env physicalProof s=BPF.execute env physicalProof s ⟨0x79,2,1,0,0⟩ := by
      simp [BPF.step,active,position,physical_decode0]
    rw [sourceStep,physicalStep]
    cases read : readMemory s.memory (s.regs 1) 8 with
    | error fault =>
      simp +decide [BPFPlatform.expand,expansion0,physical0,physical2,BPFPath.evaluate,
        BPF.step,BPF.decode,BPF.execute,BPF.load,BPF.setReg,read,active,position,littleEndian,
        Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
      all_goals cases s <;> simp_all
    | ok pair =>
      rcases pair with ⟨value,event⟩
      simp +decide [BPFPlatform.expand,expansion0,physical0,physical2,BPFPath.evaluate,
        BPF.step,BPF.decode,BPF.execute,BPF.load,BPF.setReg,read,active,position,littleEndian,
        Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Entire physical operation of the declared conversion, including faults. -/
theorem physical_context_step_2 (env : BPF.Environment) (s : BPF.State) (position : s.pc=2) :
    BPFPlatform.step (initializedPlatform env) proof s=BPF.step env physicalProof s := by
  cases active : s.halted with
  | true =>
    simp [BPFPlatform.step,BPF.step,active,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  | false =>
    have sourceStep : BPFPlatform.step (initializedPlatform env) proof s=BPFPlatform.expand env expansion2 s := by
      simp +decide [BPFPlatform.step,initializedPlatform,platform,active,position,virtual_decode2,
        expansion2,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    have physicalStep : BPF.step env physicalProof s=BPF.execute env physicalProof s ⟨0x79,1,1,8,0⟩ := by
      simp [BPF.step,active,position,physical_decode2]
    rw [sourceStep,physicalStep]
    cases read : readMemory s.memory (s.regs 1+(8#64)) 8 with
    | error fault =>
      simp +decide [BPFPlatform.expand,expansion2,physical0,physical2,BPFPath.evaluate,
        BPF.step,BPF.decode,BPF.execute,BPF.load,BPF.setReg,read,active,position,littleEndian,
        Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
      all_goals cases s <;> simp_all
    | ok pair =>
      rcases pair with ⟨value,event⟩
      simp +decide [BPFPlatform.expand,expansion2,physical0,physical2,BPFPath.evaluate,
        BPF.step,BPF.decode,BPF.execute,BPF.load,BPF.setReg,read,active,position,littleEndian,
        Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]


/-- Ordinary unchanged instructions use exactly the same physical BPF
transition, including environment choices and every error/fault result. -/
theorem ordinary_physical_step (env : BPF.Environment) (s : BPF.State) (instruction : BPF.Instruction)
    (not0 : s.pc≠0) (not2 : s.pc≠2)
    (virtual : BPF.decode proof s.pc.toNat=.ok instruction)
    (physical : BPF.decode physicalProof s.pc.toNat=.ok instruction) (notWide : instruction.code≠0x18) :
    BPFPlatform.step (initializedPlatform env) proof s=BPF.step env physicalProof s := by
  have execute := BPF.execute_program_congr_if_wide env proof physicalProof s instruction
    (fun impossible => False.elim (notWide impossible))
  cases active : s.halted <;> by_cases negative : s.pc<0 <;>
    simp [BPFPlatform.step,initializedPlatform,platform,BPF.step,active,negative,not0,not2,
      virtual,physical,execute,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- These are wire-decoding certificates for the actual unchanged35BPF
positions, not a new instruction interpreter. -/
theorem unchanged_physical_decodes (pc : Nat) (inside : pc<37) (not0 : pc≠0) (not2 : pc≠2) :
    ∃ instruction, BPF.decode proof pc=.ok instruction ∧
      BPF.decode physicalProof pc=.ok instruction ∧ instruction.code≠0x18 := by
  have choices : pc=1 ∨ pc=3 ∨ pc=4 ∨ pc=5 ∨ pc=6 ∨ pc=7 ∨ pc=8 ∨ pc=9 ∨ pc=10 ∨ pc=11 ∨ pc=12 ∨ pc=13 ∨ pc=14 ∨ pc=15 ∨ pc=16 ∨ pc=17 ∨ pc=18 ∨ pc=19 ∨ pc=20 ∨ pc=21 ∨ pc=22 ∨ pc=23 ∨ pc=24 ∨ pc=25 ∨ pc=26 ∨ pc=27 ∨ pc=28 ∨ pc=29 ∨ pc=30 ∨ pc=31 ∨ pc=32 ∨ pc=33 ∨ pc=34 ∨ pc=35 ∨ pc=36 := by omega
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · refine ⟨⟨0x7b,10,2,0xffd8,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x7b,10,1,0xffe0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb4,1,0,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x7a,10,0,0xffe8,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x7a,10,0,0xfff0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x62,10,0,0xfff8,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,0,9,0x1,0x2⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x79,2,10,0xffd8,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x79,3,10,0xffe0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x2d,2,3,0x16,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,4,0,0x0,0x8⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xbf,5,2,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x7,5,0,0x0,0x48⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x2d,5,3,0x12,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xf,4,2,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x2d,4,3,0x10,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,1,0,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,3,0,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xf,3,2,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,4,0,0x0,0x614e⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x6b,3,4,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,3,0,0x0,0x2⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xf,3,2,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,4,0,0x0,0xbc⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x73,3,4,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,3,0,0x0,0x3⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xf,3,2,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x63,3,1,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb7,3,0,0x0,0x7⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xf,3,2,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x73,3,1,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xb4,1,0,0x0,0x2⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0xbc,0,1,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x5,0,0,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl
  · refine ⟨⟨0x95,0,0,0x0,0x0⟩,rfl,?_,by decide⟩
    rw [physical_proof_literal]
    rfl

/-- Pointwise equality for EVERY full proof state, including halted,
negative/out-of-range PC and every guest read/write fault. -/
theorem physical_step_eq (env : BPF.Environment) (s : BPF.State) :
    BPFPlatform.step (initializedPlatform env) proof s=BPF.step env physicalProof s := by
  cases active : s.halted with
  | true =>
    simp [BPFPlatform.step,BPF.step,active,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  | false =>
    by_cases negative : s.pc<0
    · simp [BPFPlatform.step,BPF.step,active,negative,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    · by_cases zero : s.pc=0
      · exact physical_context_step_0 env s zero
      · by_cases two : s.pc=2
        · exact physical_context_step_2 env s two
        · by_cases inside : s.pc.toNat<37
          · have not0 : s.pc.toNat≠0 := by omega
            have not2 : s.pc.toNat≠2 := by omega
            obtain ⟨instruction,virtual,physical,notWide⟩ := unchanged_physical_decodes s.pc.toNat inside not0 not2
            exact ordinary_physical_step env s instruction zero two virtual physical notWide
          · have outside : 296<8*s.pc.toNat+8 := by omega
            have virtual : BPF.decode proof s.pc.toNat=.error "BPF instruction outside artifact" := by
              simp [BPF.decode,proof_size,outside,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
            have physical : BPF.decode physicalProof s.pc.toNat=.error "BPF instruction outside artifact" := by
              simp [BPF.decode,physical_proof_size,outside,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
            simp [BPFPlatform.step,BPF.step,active,negative,virtual,physical,
              Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Whole-program relation equality preserves complete states and ordered
traces at every finite prefix; no selected path or evaluator bound is used. -/
theorem physical_instruction_relation_eq (env : BPF.Environment) :
    initializedInstructionStep env=BPFPath.instructionStep env physicalProof := by
  funext before events after
  unfold initializedInstructionStep BPFPath.instructionStep
  rw [physical_step_eq]

theorem physical_execution_iff (env : BPF.Environment) (first last : BPF.State) (trace : List Event) :
    Execution (initializedInstructionStep env) first trace last ↔
      Execution (BPFPath.instructionStep env physicalProof) first trace last := by
  rw [physical_instruction_relation_eq]


/-- Exact bound virtual proof bytes have the ordinary physical relation
proved above; no proof bytes or surviving event are substituted. -/
theorem bound_physical_instruction_relation_eq (env : BPF.Environment) (artifact : Artifact)
    (proofImage : artifact.proofBytes=proof.toList) :
    boundCapturedProofStep env artifact=BPFPath.instructionStep env physicalProof := by
  have virtual : boundCapturedProofStep env artifact=initializedInstructionStep env := by
    funext before events after
    unfold boundCapturedProofStep initializedInstructionStep
    rw [proofImage]
  exact virtual.trans (physical_instruction_relation_eq env)

theorem bound_physical_execution_iff (env : BPF.Environment) (artifact : Artifact)
    (proofImage : artifact.proofBytes=proof.toList) (first last : BPF.State) (trace : List Event) :
    Execution (boundCapturedProofStep env artifact) first trace last ↔
      Execution (BPFPath.instructionStep env physicalProof) first trace last := by
  rw [bound_physical_instruction_relation_eq env artifact proofImage]

/-- The actual-base native result follows from ordinary physical-B semantics
and explicit verifier soundness for that declared context interpretation.
This does not assert historical kernel image identity or physical ABI facts. -/
theorem bound_native_effects_checked_from_physical_B (env : BPF.Environment) (n : X86.State) (p : BPF.State) (codeBase : Word)
    (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : accepted validated → proofEntry validated p →
      ∀ trace last, Execution (BPFPath.instructionStep env physicalProof) p trace last →
        ∀ event ∈ trace, checked validated event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    {trace : List Event} {last : X86.State}
    (run : Execution (relationalNativeInstructionStep (codeBase+BitVec.ofNat 64 executed.entry)
      executed.nativeBytes.toArray) n trace last)
    (stack : Word) (nativePC : n.pc=codeBase) (proofPC : p.pc=0) (active : p.halted=false)
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
  let onlyAccepted : Artifact → Prop := fun artifact => artifact=validated ∧ accepted artifact
  have acceptedHere : onlyAccepted validated := ⟨rfl,acceptance⟩
  have soundHere : ∀ artifact, onlyAccepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (boundCapturedProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event := by
    intro artifact selected entry trace last execution
    obtain ⟨same,acceptedArtifact⟩ := selected
    subst artifact
    have physicalRun := (bound_physical_execution_iff env validated proofImage p last trace).mp execution
    exact verifierSound acceptedArtifact entry trace last physicalRun
  exact bound_captured_based_native_prefix_effects_checked env n p codeBase validated executed binding
    nativeImage proofImage entryImage onlyAccepted proofEntry checked soundHere acceptedHere admitted
    run stack nativePC proofPC active context memory nativeStack
    write40 write32 write24 write16 write8 read40 read32 guest0 guest1

end KProgTV.TrustedSimplePlatform

#print axioms KProgTV.TrustedSimplePlatform.physical_proof_size

#print axioms KProgTV.TrustedSimplePlatform.physical_proof_literal

#print axioms KProgTV.TrustedSimplePlatform.physical_decode0

#print axioms KProgTV.TrustedSimplePlatform.physical_decode2

#print axioms KProgTV.TrustedSimplePlatform.virtual_decode2

#print axioms KProgTV.TrustedSimplePlatform.physical_context_step_0

#print axioms KProgTV.TrustedSimplePlatform.physical_context_step_2

#print axioms KProgTV.TrustedSimplePlatform.ordinary_physical_step

#print axioms KProgTV.TrustedSimplePlatform.unchanged_physical_decodes

#print axioms KProgTV.TrustedSimplePlatform.physical_step_eq

#print axioms KProgTV.TrustedSimplePlatform.physical_instruction_relation_eq

#print axioms KProgTV.TrustedSimplePlatform.physical_execution_iff

#print axioms KProgTV.TrustedSimplePlatform.bound_physical_instruction_relation_eq

#print axioms KProgTV.TrustedSimplePlatform.bound_physical_execution_iff

#print axioms KProgTV.TrustedSimplePlatform.bound_native_effects_checked_from_physical_B
