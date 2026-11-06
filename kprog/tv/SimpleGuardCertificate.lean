import ARM64Path
import BPFPath
import SimpleCompiled
import Std.Tactic.BVDecide

set_option maxRecDepth 4096
set_option maxHeartbeats 300000

namespace KProgTV.SimpleGuardCertificate
open KProgFormal.Reference KProgTV.SimpleCompiled

@[simp] theorem native_size : native.size = 84 := rfl

-- The actual native opcodes, not a second decoder or assumed CFG.
theorem decode4 : AArch64.decode (native.extract 4 8) =
    .ok (.moveRegister .w64 (.general 10) (.general 8)) := rfl
theorem decode8 : AArch64.decode (native.extract 8 12) =
    .ok (.arithmeticRegister .w64 true true .zero (.general 10) 9 0 ⟨0, by decide⟩) := rfl
theorem decode12 : AArch64.decode (native.extract 12 16) =
    .ok (.branchConditional 8 24) := rfl
theorem decode16 : AArch64.decode (native.extract 16 20) =
    .ok (.arithmeticImmediate .w64 false false (.general 11) (.general 10) 8) := rfl
theorem decode20 : AArch64.decode (native.extract 20 24) =
    .ok (.arithmeticImmediate .w64 false false (.general 10) (.general 10) 72) := rfl
theorem decode24 : AArch64.decode (native.extract 24 28) =
    .ok (.arithmeticRegister .w64 true true .zero (.general 11) 9 0 ⟨0, by decide⟩) := rfl
theorem decode28 : AArch64.decode (native.extract 28 32) =
    .ok (.compare .w64 10 (.register 9) 9 2) := rfl
theorem decode32 : AArch64.decode (native.extract 32 36) =
    .ok (.branchConditional 9 12) := rfl

set_option pp.maxSteps 3000

theorem cmp_hi (left right flags : Word) :
    AArch64.condition (AArch64.arithmeticFlags .w64 true left right flags) 8 = (left > right) := by
  simp only [AArch64.condition, AArch64.arithmeticFlags, AArch64.Width.bits]
  bv_decide

theorem cmp_ls (left right flags : Word) :
    AArch64.condition (AArch64.arithmeticFlags .w64 true left right flags) 9 = (left ≤ right) := by
  simp only [AArch64.condition, AArch64.arithmeticFlags, AArch64.Width.bits]
  bv_decide

theorem fallback_rejects (flags : Word) :
    AArch64.condition (AArch64.compareFallback flags (2#4)) 9 = false := by
  simp only [AArch64.condition, AArch64.compareFallback]
  bv_decide

def before (n : AArch64.State) (pointer limit : Word) : AArch64.State :=
  { n with
    gpr := fun r => if r.val = 8 then pointer else if r.val = 9 then limit else n.gpr r
    pc := 4 }


def final (n : AArch64.State) (pointer limit : Word) : AArch64.State :=
  { AArch64.writeReg (before n pointer limit) 10 pointer with
    flags := AArch64.arithmeticFlags .w64 true pointer limit n.flags
    pc := if pointer > limit then 36 else 16 }

/-- The actual first native basic block, with every architectural field. -/
theorem native_first_block (n : AArch64.State) (pointer limit : Word) :
    ARM64Path.evaluate 0 native [4,8,12] (before n pointer limit) =
      .ok ⟨final n pointer limit, [], none⟩ := by
  simp +decide [ARM64Path.evaluate, ARM64Path.step, decode4, decode8, decode12,
    before, final, AArch64.step, AArch64.moveRegStep, AArch64.readData, AArch64.writeData,
    AArch64.writeReg, AArch64.readReg, AArch64.narrow, AArch64.Width.bits,
    AArch64.arithmeticRegisterStep, AArch64.arithmeticImmediateStep,
    AArch64.shiftValue, AArch64.arithmeticShift, AArch64.branchStep, cmp_hi,
    Fin.ofNat', Fin.instOfNat, Except.bind, Except.map, Except.pure,
    Bind.bind, Pure.pure, Except.instMonad]
  funext r
  have v32 : (10 : AArch64.Register).val = 10 := rfl
  have v31 : (10 : AArch64.Gpr).val = 10 := rfl
  simp [v32, v31]

theorem proofDecode7 : BPF.decode proof 7 = .ok ⟨45, 1, 2, 19, 0⟩ := rfl

def noExternals : BPF.Environment where
  immediate := fun _ _ _ => .error "no external immediate in guard block"
  helperCall := fun _ _ => .error "no helper in guard block"
  helper := fun _ _ _ => .error "no helper effect in guard block"

def proofBefore (p : BPF.State) (pointer limit : Word) : BPF.State :=
  { p with
    regs := fun r => if r.val = 1 then pointer else if r.val = 2 then limit else p.regs r
    pc := 7
    halted := false }

theorem proof_first_block (p : BPF.State) (pointer limit : Word) :
    BPFPath.evaluate noExternals proof [7] (proofBefore p pointer limit) =
      .ok ⟨{ proofBefore p pointer limit with pc := if pointer > limit then 27 else 8 }, [], none⟩ := by
  simp +decide [BPFPath.evaluate, proofDecode7, proofBefore, BPF.execute, BPF.source,
    BPF.comparison, Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]


def secondBefore (n : AArch64.State) (pointer limit : Word) : AArch64.State :=
  { n with
    gpr := fun r => if r.val = 10 then pointer else if r.val = 9 then limit else n.gpr r
    pc := 16 }

def secondFinal (n : AArch64.State) (pointer limit : Word) : AArch64.State :=
  let flags8 := AArch64.arithmeticFlags .w64 true (pointer + (8#64)) limit n.flags
  { AArch64.writeReg (AArch64.writeReg (secondBefore n pointer limit) 11 (pointer + (8#64)))
        10 (pointer + (72#64)) with
    flags := if pointer + (8#64) ≤ limit then
        AArch64.arithmeticFlags .w64 true (pointer + (72#64)) limit flags8
      else AArch64.compareFallback flags8 (2#4)
    pc := if pointer + (8#64) ≤ limit ∧ pointer + (72#64) ≤ limit then 44 else 36 }

theorem native_second_block (n : AArch64.State) (pointer limit : Word) :
    ARM64Path.evaluate 0 native [16,20,24,28,32] (secondBefore n pointer limit) =
      .ok ⟨secondFinal n pointer limit, [], none⟩ := by
  by_cases h8 : pointer + (8#64) ≤ limit <;>
    by_cases h72 : pointer + (72#64) ≤ limit <;>
    simp +decide [ARM64Path.evaluate, ARM64Path.step, decode16, decode20, decode24, decode28, decode32,
      secondBefore, secondFinal, AArch64.step, AArch64.readData, AArch64.writeData,
      AArch64.writeReg, AArch64.readReg, AArch64.narrow, AArch64.Width.bits,
      AArch64.arithmeticRegisterStep, AArch64.arithmeticImmediateStep,
      AArch64.shiftValue, AArch64.arithmeticShift, AArch64.compareStep, AArch64.compareOperand,
      AArch64.branchStep, cmp_hi, cmp_ls, fallback_rejects, h8, h72,
      Fin.ofNat', Fin.instOfNat, Except.bind, Except.map, Except.pure,
      Bind.bind, Pure.pure, Except.instMonad]
  all_goals funext r
  all_goals have r10 : (10 : AArch64.Register).val = 10 := rfl
  all_goals have g10 : (10 : AArch64.Gpr).val = 10 := rfl
  all_goals have r11 : (11 : AArch64.Register).val = 11 := rfl
  all_goals have g11 : (11 : AArch64.Gpr).val = 11 := rfl
  all_goals simp [r10, g10, r11, g11]

theorem proofDecode8 : BPF.decode proof 8 = .ok ⟨191, 3, 1, 0, 0⟩ := rfl
theorem proofDecode9 : BPF.decode proof 9 = .ok ⟨7, 3, 0, 0, 8⟩ := rfl
theorem proofDecode10 : BPF.decode proof 10 = .ok ⟨45, 3, 2, 16, 0⟩ := rfl
theorem proofDecode11 : BPF.decode proof 11 = .ok ⟨191, 3, 1, 0, 0⟩ := rfl
theorem proofDecode12 : BPF.decode proof 12 = .ok ⟨7, 3, 0, 0, 72⟩ := rfl
theorem proofDecode13 : BPF.decode proof 13 = .ok ⟨45, 3, 2, 13, 0⟩ := rfl



def proofSecondBefore (p : BPF.State) (pointer limit : Word) : BPF.State :=
  { proofBefore p pointer limit with pc := 8 }

def proofSecondPositions (pointer limit : Word) : List Nat :=
  if pointer + (8#64) > limit then [8,9,10] else [8,9,10,11,12,13]

def proofSecondFinal (p : BPF.State) (pointer limit : Word) : BPF.State :=
  { BPF.setReg (proofSecondBefore p pointer limit) 3
      (if pointer + (8#64) > limit then pointer + (8#64) else pointer + (72#64)) with
    pc := if pointer + (8#64) ≤ limit ∧ pointer + (72#64) ≤ limit then 14 else 27 }

theorem proof_second_block (p : BPF.State) (pointer limit : Word) :
    BPFPath.evaluate noExternals proof (proofSecondPositions pointer limit) (proofSecondBefore p pointer limit) =
      .ok ⟨proofSecondFinal p pointer limit, [], none⟩ := by
  by_cases h8 : pointer + (8#64) > limit <;>
    by_cases h72 : pointer + (72#64) > limit <;>
    simp +decide [BPFPath.evaluate, proofDecode8, proofDecode9, proofDecode10,
      proofDecode11, proofDecode12, proofDecode13, proofBefore,
      proofSecondBefore, proofSecondPositions, proofSecondFinal,
      BPF.execute, BPF.source, BPF.alu, BPF.comparison, BPF.setReg,
      h8, h72, Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  all_goals first
    | (funext r; by_cases h : r = 3 <;> simp_all)
    | (simp_all [BitVec.le_def, BitVec.lt_def])
  all_goals split <;> omega

/-- Each successful witness is a real execution, including both branch
outcomes. Complete post-states above retain all architectural/BPF fields. -/
theorem actual_block_executions (n : AArch64.State) (p : BPF.State) (pointer limit : Word) :
    Execution (ARM64Path.instructionStep 0 native) (before n pointer limit) [] (final n pointer limit) ∧
    Execution (BPFPath.instructionStep noExternals proof) (proofBefore p pointer limit) []
      { proofBefore p pointer limit with pc := if pointer > limit then 27 else 8 } ∧
    Execution (ARM64Path.instructionStep 0 native) (secondBefore n pointer limit) [] (secondFinal n pointer limit) ∧
    Execution (BPFPath.instructionStep noExternals proof) (proofSecondBefore p pointer limit) []
      (proofSecondFinal p pointer limit) := by
  exact ⟨ARM64Path.evaluate_sound _ _ _ _ _ (native_first_block n pointer limit),
    BPFPath.evaluate_sound _ _ _ _ _ (proof_first_block p pointer limit),
    ARM64Path.evaluate_sound _ _ _ _ _ (native_second_block n pointer limit),
    BPFPath.evaluate_sound _ _ _ _ _ (proof_second_block p pointer limit)⟩

end KProgTV.SimpleGuardCertificate
#print axioms KProgTV.SimpleGuardCertificate.native_first_block
#print axioms KProgTV.SimpleGuardCertificate.proof_first_block

#print axioms KProgTV.SimpleGuardCertificate.native_second_block

#print axioms KProgTV.SimpleGuardCertificate.proof_second_block
#print axioms KProgTV.SimpleGuardCertificate.actual_block_executions
