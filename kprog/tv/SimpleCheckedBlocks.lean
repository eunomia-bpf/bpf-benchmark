import SimpleCheckedPlatform
import SimpleBlocks

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

end KProgTV.SimpleCheckedBlocks
#print axioms KProgTV.SimpleCheckedBlocks.first_block
