import SimpleCheckedPlatform
import SimpleBlocks
import SimpleStoreCertificate

set_option maxRecDepth 4096
set_option maxHeartbeats 1000000

namespace KProgTV.SimpleCheckedBlocks
open KProgFormal.Reference KProgTV.SimpleCompiled

/-- Every actual instruction before the rewritten EXIT is unchanged. -/
theorem prefix_decode : ∀ pc : Fin 27,
    BPF.decode SimpleCheckedPlatform.physical pc.val = BPF.decode SimplePlatform.physical pc.val := by
  have checked : ∀ pc : Fin 27,
      (match BPF.decode SimpleCheckedPlatform.physical pc.val,
          BPF.decode SimplePlatform.physical pc.val with
        | .ok first, .ok second => decide (first = second)
        | _, _ => false) = true := by native_decide
  intro pc
  have same := checked pc
  cases first : BPF.decode SimpleCheckedPlatform.physical pc.val <;>
    cases second : BPF.decode SimplePlatform.physical pc.val <;> simp_all

theorem prefix_instruction : ∀ pc : Fin 27, ∃ i,
    BPF.decode SimpleCheckedPlatform.physical pc.val = .ok i ∧
    BPF.decode SimplePlatform.physical pc.val = .ok i ∧ i.code ≠ 0x18 := by
  have noWide : ∀ pc : Fin 27, (match BPF.decode SimpleCheckedPlatform.physical pc.val with
      | .error _ => false
      | .ok i => i.code != 0x18) = true := by decide
  intro pc
  have same := prefix_decode pc
  cases decoded : BPF.decode SimpleCheckedPlatform.physical pc.val with
  | error error => simpa [decoded] using noWide pc
  | ok i => exact ⟨i, rfl, same.symm.trans decoded, by simpa [decoded] using noWide pc⟩

theorem prefix_evaluate (env : BPF.Environment) (positions : List Nat)
    (inside : ∀ pc ∈ positions, pc < 27) (s : BPF.State) :
    BPFPath.evaluate env SimpleCheckedPlatform.physical positions s =
      BPFPath.evaluate env SimplePlatform.physical positions s := by
  apply BPFPath.evaluate_program_congr_if_wide
  intro pc member
  obtain ⟨i, first, second, noWide⟩ := prefix_instruction ⟨pc, inside pc member⟩
  exact ⟨i, first, second, fun wide => False.elim (noWide wide)⟩

/-- BB0 now runs in the exact accepted expanded virtual program, with both
native successors and exactly the justified private-spill event erasure. -/
theorem first_block (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second) :
    Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context)
      [first, second] (SimpleBlocks.firstNativeFinal n context pointer limit) ∧
    Execution SimpleCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0)
      (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second)
      (SimpleBlocks.firstProofFinal p pointer limit) ∧
    PrivateSpills.AgreesOutside (p.regs 10) (SimpleBlocks.firstNativeFinal n context pointer limit).memory
      (SimpleBlocks.firstProofFinal p pointer limit).memory ∧
    (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second).filterMap
      (PrivateSpills.projectEvent (p.regs 10)) = [first, second] ∧
    (SimpleBlocks.firstNativeFinal n context pointer limit).pc = (if pointer > limit then 36 else 16) ∧
    (SimpleBlocks.firstProofFinal p pointer limit).pc = (if pointer > limit then 27 else 8) ∧
    ∀ event ∈ SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second,
      PrivateSpills.projectEvent (p.regs 10) event = none →
      ∃ kind address bytes initialized,
        event = .memory kind address bytes initialized ∧ bytes.length = 8 ∧
        ∀ i < 8, PrivateSpills.privateByte (p.regs 10) (address + BitVec.ofNat 64 i) := by
  have original := SimpleBlocks.first_block n p context pointer limit first second entry
  have prefixRun := (prefix_evaluate SimpleCheckedPlatform.externals [0,1,2,3,4,5,6]
    (by intro pc inside; simp at inside; omega)
    (SimpleEntryCertificate.proofBefore p context 0)).trans
    (SimpleEntryCertificate.proof_prefix_full_state SimpleCheckedPlatform.externals p context pointer limit first second
      entry.read0 entry.read1 entry.write8 entry.write16 entry.read8 entry.read16 entry.guest1)
  have guardSame : ∀ pc ∈ [7], BPF.decode SimplePlatform.physical pc = BPF.decode proof pc ∧
      BPF.decode SimplePlatform.physical (pc+1) = BPF.decode proof (pc+1) := by
    intro pc inside
    simp only [List.mem_singleton] at inside
    subst pc
    simpa only [SimplePlatform.raw_is_exact_clang] using SimplePlatform.body_decode ⟨3, by decide⟩
  have guardRun := (prefix_evaluate SimpleCheckedPlatform.externals [7]
    (by intro pc inside; simp only [List.mem_singleton] at inside; omega)
    (SimpleGuardCertificate.proofBefore (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit)).trans
    ((BPFPath.evaluate_program_congr SimpleCheckedPlatform.externals SimplePlatform.physical proof [7] guardSame
      (SimpleGuardCertificate.proofBefore (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit)).trans
        (SimpleGuardCertificate.proof_first_block (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit
          (env := SimpleCheckedPlatform.externals)))
  rw [SimpleBlocks.proof_at_guard] at guardRun
  have physicalRun := (BPFPath.evaluate_sound _ _ _ _ _ prefixRun).append
    (BPFPath.evaluate_sound _ _ _ _ _ guardRun)
  refine ⟨original.1, ?_, original.2.2⟩
  apply SimpleCheckedPlatform.execution_transport
  simpa only [List.append_nil, SimpleBlocks.firstProofFinal] using physicalRun

theorem body_evaluate (env : BPF.Environment) (positions : List Nat)
    (inside : ∀ pc ∈ positions, 4 ≤ pc ∧ pc < 27) (s : BPF.State) :
    BPFPath.evaluate env SimpleCheckedPlatform.physical positions s =
      BPFPath.evaluate env proof positions s := by
  rw [prefix_evaluate env positions (fun pc member => (inside pc member).2)]
  apply BPFPath.evaluate_program_congr
  intro pc member
  have bounds := inside pc member
  have same := SimplePlatform.body_decode ⟨pc-4, by omega⟩
  have start : pc-4+4 = pc := by omega
  have next : pc-4+5 = pc+1 := by omega
  simpa only [SimplePlatform.raw_is_exact_clang, start, next] using same

/-- Actual second native block, including the CCMP fallback, against the
accepted expanded artifact. Both success and failure successors are retained. -/
theorem second_block (n : AArch64.State) (p : BPF.State) (pointer limit : Word) :
    Execution (ARM64Path.instructionStep 0 native) (SimpleGuardCertificate.secondBefore n pointer limit)
      [] (SimpleGuardCertificate.secondFinal n pointer limit) ∧
    Execution SimpleCheckedPlatform.instructionStep (SimpleGuardCertificate.proofSecondBefore p pointer limit)
      [] (SimpleGuardCertificate.proofSecondFinal p pointer limit) ∧
    (SimpleGuardCertificate.secondFinal n pointer limit).pc =
      (if pointer + (8#64) ≤ limit ∧ pointer + (72#64) ≤ limit then 44 else 36) ∧
    (SimpleGuardCertificate.proofSecondFinal p pointer limit).pc =
      (if pointer + (8#64) ≤ limit ∧ pointer + (72#64) ≤ limit then 14 else 27) := by
  have bounds : ∀ pc ∈ SimpleGuardCertificate.proofSecondPositions pointer limit, 4 ≤ pc ∧ pc < 27 := by
    intro pc inside
    unfold SimpleGuardCertificate.proofSecondPositions at inside
    split at inside <;> simp at inside <;> omega
  have actual := (body_evaluate SimpleCheckedPlatform.externals
    (SimpleGuardCertificate.proofSecondPositions pointer limit) bounds
    (SimpleGuardCertificate.proofSecondBefore p pointer limit)).trans
    (SimpleGuardCertificate.proof_second_block p pointer limit (env := SimpleCheckedPlatform.externals))
  exact ⟨ARM64Path.evaluate_sound _ _ _ _ _ (SimpleGuardCertificate.native_second_block n pointer limit),
    SimpleCheckedPlatform.execution_transport (BPFPath.evaluate_sound _ _ _ _ _ actual), rfl, rfl⟩

theorem native_decode80 : AArch64.decode (native.extract 80 84) =
    .ok (.moveRegister .w64 (.general 7) (.general 0)) := rfl

def nativeReturnBefore (n : AArch64.State) (value : Word) : AArch64.State :=
  { n with gpr := fun r => if r.val = 0 then value else n.gpr r, pc := 80 }

def nativeReturnFinal (n : AArch64.State) (value : Word) : AArch64.State :=
  { nativeReturnBefore n value with
    gpr := fun r => if r.val = 7 then value else (nativeReturnBefore n value).gpr r
    pc := 84 }

theorem native_return (n : AArch64.State) (value : Word) :
    ARM64Path.evaluate 0 native [80] (nativeReturnBefore n value) =
      .ok ⟨nativeReturnFinal n value, [], none⟩ := by
  simp +decide [ARM64Path.evaluate, ARM64Path.step, native_decode80,
    nativeReturnBefore, nativeReturnFinal, AArch64.step, AArch64.moveRegStep,
    AArch64.readData, AArch64.writeData, AArch64.readReg, AArch64.writeReg,
    AArch64.narrow, AArch64.Width.bits, Fin.ofNat', Fin.instOfNat,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  all_goals
    funext r
    have register7 : (7 : AArch64.Register).val = 7 := rfl
    have gpr7 : (7 : AArch64.Gpr).val = 7 := rfl
    have gpr0 : (0 : AArch64.Gpr).val = 0 := rfl
    by_cases h : r.val = 7 <;> simp_all [register7, gpr7, gpr0]

def proofReturnBefore (p : BPF.State) (value : Word) : BPF.State :=
  { p with regs := fun r => if r.val = 0 then value else p.regs r, pc := 27, halted := false }

def proofReturnFinal (p : BPF.State) (value : Word) : BPF.State :=
  { proofReturnBefore p value with pc := 29, halted := true }

theorem proof_decode27 : BPF.decode SimpleCheckedPlatform.physical 27 = .ok ⟨5,0,0,0,0⟩ := rfl
theorem proof_decode28 : BPF.decode SimpleCheckedPlatform.physical 28 = .ok ⟨149,0,0,0,0⟩ := rfl

theorem proof_return (p : BPF.State) (value : Word) :
    BPFPath.evaluate SimpleCheckedPlatform.externals SimpleCheckedPlatform.physical [27,28]
      (proofReturnBefore p value) = .ok ⟨proofReturnFinal p value, [], none⟩ := by
  simp +decide [BPFPath.evaluate, proof_decode27, proof_decode28,
    proofReturnBefore, proofReturnFinal, BPF.execute,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- The actual linked native trampoline and rewritten proof return preserve
all memory and produce the same ABI return value for every 64-bit input. -/
theorem return_executions (n : AArch64.State) (p : BPF.State) (value : Word) :
    Execution (ARM64Path.instructionStep 0 native) (nativeReturnBefore n value)
      [] (nativeReturnFinal n value) ∧
    Execution SimpleCheckedPlatform.instructionStep (proofReturnBefore p value)
      [] (proofReturnFinal p value) ∧
    (nativeReturnFinal n value).gpr 7 = value ∧
    (proofReturnFinal p value).regs 0 = value ∧
    (nativeReturnFinal n value).memory = n.memory ∧
    (proofReturnFinal p value).memory = p.memory := by
  exact ⟨ARM64Path.evaluate_sound _ _ _ _ _ (native_return n value),
    SimpleCheckedPlatform.execution_transport (BPFPath.evaluate_sound _ _ _ _ _ (proof_return p value)),
    by
      have gpr7 : (7 : AArch64.Gpr).val = 7 := rfl
      simp [nativeReturnFinal, gpr7],
    by simp [proofReturnFinal, proofReturnBefore], rfl, rfl⟩

/-- Every store witness stops at its first real fault or actual successor;
the witness contributes no executable permission test or artificial bound. -/
theorem store_positions (memory : Memory) (pointer : Word) :
    ∀ pc ∈ SimpleStoreCertificate.proofPositions memory pointer, 4 ≤ pc ∧ pc < 27 := by
  intro pc inside
  unfold SimpleStoreCertificate.proofPositions at inside
  split at inside
  · simp at inside; omega
  · split at inside
    · simp at inside; omega
    · split at inside
      · simp at inside; omega
      · split at inside <;> simp at inside <;> omega

/-- Exact memory, ordered writes/fault, fault identity and corresponding PC
against the accepted expanded B, without a store-permission assumption. This
reuses the existing canonical native/BPF store certificate. -/
theorem store_including_faults (n : AArch64.State) (p : BPF.State) (pointer : Word) :
    ∃ observed, SimpleStoreCertificate.nativeObserved n pointer = .ok observed ∧
      (BPFPath.evaluate SimpleCheckedPlatform.externals SimpleCheckedPlatform.physical
        (SimpleStoreCertificate.proofPositions n.memory pointer)
        (SimpleStoreCertificate.proofInitial n p pointer)).map
          (fun result => (result.state.memory, result.events, result.fault,
            SimpleStoreCertificate.proofNativePC result.state.pc)) = .ok observed := by
  have actual := body_evaluate SimpleCheckedPlatform.externals
    (SimpleStoreCertificate.proofPositions n.memory pointer) (store_positions n.memory pointer)
    (SimpleStoreCertificate.proofInitial n p pointer)
  rw [actual]
  simpa only [SimpleStoreCertificate.proofObserved] using
    SimpleStoreCertificate.including_faults n p pointer (env := SimpleCheckedPlatform.externals)

end KProgTV.SimpleCheckedBlocks
#print axioms KProgTV.SimpleCheckedBlocks.first_block

#print axioms KProgTV.SimpleCheckedBlocks.second_block
#print axioms KProgTV.SimpleCheckedBlocks.return_executions

#print axioms KProgTV.SimpleCheckedBlocks.store_including_faults
