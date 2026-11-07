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

end KProgTV.TrustedSimplePlatform

#print axioms KProgTV.TrustedSimplePlatform.physical_proof_size

#print axioms KProgTV.TrustedSimplePlatform.physical_proof_literal

#print axioms KProgTV.TrustedSimplePlatform.physical_decode0

#print axioms KProgTV.TrustedSimplePlatform.physical_decode2

#print axioms KProgTV.TrustedSimplePlatform.virtual_decode2

#print axioms KProgTV.TrustedSimplePlatform.physical_context_step_0

#print axioms KProgTV.TrustedSimplePlatform.physical_context_step_2
