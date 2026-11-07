import PacketCompiled
import SimpleGuardCertificate
set_option maxRecDepth 4096
set_option maxHeartbeats 500000
namespace KProgTV.PacketGuardCertificate
open KProgFormal.Reference KProgTV.PacketCompiled

theorem decode4 : AArch64.decode (native.extract 4 8) =
    .ok (.moveRegister .w64 (.general 10) (.general 8)) := rfl
theorem decode8 : AArch64.decode (native.extract 8 12) =
    .ok (.arithmeticImmediate .w64 false false (.general 11) (.general 10) 8) := rfl
theorem decode12 : AArch64.decode (native.extract 12 16) =
    .ok (.arithmeticRegister .w64 true true .zero (.general 10) 9 0 ⟨0, by decide⟩) := rfl
theorem decode16 : AArch64.decode (native.extract 16 20) =
    .ok (.compare .w64 11 (.register 9) 9 2) := rfl
theorem decode20 : AArch64.decode (native.extract 20 24) =
    .ok (.branchConditional 9 12) := rfl

def before (n : AArch64.State) (pointer limit : Word) : AArch64.State :=
  SimpleGuardCertificate.before n pointer limit

def final (n : AArch64.State) (pointer limit : Word) : AArch64.State :=
  let flags := AArch64.arithmeticFlags .w64 true pointer limit n.flags
  { AArch64.writeReg (AArch64.writeReg (before n pointer limit) 10 pointer) 11 (pointer + (8#64)) with
    flags := if pointer ≤ limit then AArch64.arithmeticFlags .w64 true (pointer + (8#64)) limit flags
      else AArch64.compareFallback flags (2#4)
    pc := if pointer ≤ limit ∧ pointer + (8#64) ≤ limit then 32 else 24 }

theorem native_guard (n : AArch64.State) (pointer limit : Word) :
    ARM64Path.evaluate 0 native [4,8,12,16,20] (before n pointer limit) =
      .ok ⟨final n pointer limit, [], none⟩ := by
  by_cases hp : pointer ≤ limit <;> by_cases h8 : pointer + (8#64) ≤ limit <;>
    simp +decide [ARM64Path.evaluate, ARM64Path.step, decode4, decode8, decode12, decode16, decode20,
      before, SimpleGuardCertificate.before, final, AArch64.step, AArch64.moveRegStep,
      AArch64.readData, AArch64.writeData, AArch64.writeReg, AArch64.readReg, AArch64.narrow,
      AArch64.Width.bits, AArch64.arithmeticRegisterStep, AArch64.arithmeticImmediateStep,
      AArch64.shiftValue, AArch64.arithmeticShift, AArch64.compareStep, AArch64.compareOperand,
      AArch64.branchStep, SimpleGuardCertificate.cmp_ls, SimpleGuardCertificate.fallback_rejects,
      hp, h8, Fin.ofNat', Fin.instOfNat, Except.bind, Except.map, Except.pure,
      Bind.bind, Pure.pure, Except.instMonad]
  all_goals funext r
  all_goals have r10 : (10 : AArch64.Register).val = 10 := rfl
  all_goals have g10 : (10 : AArch64.Gpr).val = 10 := rfl
  all_goals have r11 : (11 : AArch64.Register).val = 11 := rfl
  all_goals have g11 : (11 : AArch64.Gpr).val = 11 := rfl
  all_goals simp [r10, g10, r11, g11]

theorem proofDecode7 : BPF.decode program 7 = .ok ⟨45,1,2,16,0⟩ := rfl
theorem proofDecode8 : BPF.decode program 8 = .ok ⟨191,3,1,0,0⟩ := rfl
theorem proofDecode9 : BPF.decode program 9 = .ok ⟨7,3,0,0,8⟩ := rfl
theorem proofDecode10 : BPF.decode program 10 = .ok ⟨45,3,2,13,0⟩ := rfl

def proofBefore (p : BPF.State) (pointer limit : Word) : BPF.State :=
  SimpleGuardCertificate.proofBefore p pointer limit

def proofPositions (pointer limit : Word) : List Nat :=
  if pointer > limit then [7] else [7,8,9,10]

def proofFinal (p : BPF.State) (pointer limit : Word) : BPF.State :=
  { proofBefore p pointer limit with
    regs := if pointer > limit then (proofBefore p pointer limit).regs
      else (BPF.setReg (proofBefore p pointer limit) 3 (pointer + (8#64))).regs
    pc := if pointer ≤ limit ∧ pointer + (8#64) ≤ limit then 11 else 24 }

theorem checked_guard (p : BPF.State) (pointer limit : Word) (env : BPF.Environment) :
    BPFPath.evaluate env program (proofPositions pointer limit) (proofBefore p pointer limit) =
      .ok ⟨proofFinal p pointer limit, [], none⟩ := by
  by_cases hp : pointer > limit <;> by_cases h8 : pointer + (8#64) > limit <;>
    simp +decide [BPFPath.evaluate, proofDecode7, proofDecode8, proofDecode9, proofDecode10,
      proofPositions, proofBefore, SimpleGuardCertificate.proofBefore, proofFinal, BPF.execute,
      BPF.source, BPF.alu, BPF.comparison, BPF.setReg, hp, h8,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  all_goals first
    | (funext r; by_cases h : r = 3 <;> simp_all)
    | (simp_all [BitVec.le_def, BitVec.lt_def])
  all_goals split <;> omega

theorem actual_guard_executions (n : AArch64.State) (p : BPF.State)
    (pointer limit : Word) (env : BPF.Environment) :
    Execution (ARM64Path.instructionStep 0 native) (before n pointer limit) [] (final n pointer limit) ∧
    Execution (BPFPath.instructionStep env program) (proofBefore p pointer limit) [] (proofFinal p pointer limit) :=
  ⟨ARM64Path.evaluate_sound _ _ _ _ _ (native_guard n pointer limit),
    BPFPath.evaluate_sound _ _ _ _ _ (checked_guard p pointer limit env)⟩

theorem corresponding_successors (n : AArch64.State) (p : BPF.State) (pointer limit : Word) :
    ((final n pointer limit).pc = 32 ↔ (proofFinal p pointer limit).pc = 11) ∧
    ((final n pointer limit).pc = 24 ↔ (proofFinal p pointer limit).pc = 24) := by
  by_cases pass : pointer ≤ limit ∧ pointer + (8#64) ≤ limit <;> simp [final, proofFinal, pass]
end KProgTV.PacketGuardCertificate
#print axioms KProgTV.PacketGuardCertificate.native_guard
#print axioms KProgTV.PacketGuardCertificate.checked_guard
#print axioms KProgTV.PacketGuardCertificate.actual_guard_executions

#print axioms KProgTV.PacketGuardCertificate.corresponding_successors
