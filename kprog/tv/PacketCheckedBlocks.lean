import PacketCheckedPlatform
set_option maxRecDepth 4096
set_option maxHeartbeats 1000000
namespace KProgTV.PacketCheckedBlocks
open KProgFormal.Reference KProgTV.PacketCompiled

def firstNativeFinal (n : AArch64.State) (context pointer limit : Word) :=
  PacketGuardCertificate.final (SimpleEntryCertificate.loaded n context pointer limit) pointer limit

def firstProofFinal (p : BPF.State) (pointer limit : Word) :=
  PacketGuardCertificate.proofFinal (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit

/-- Original entry through the complete guard against the actual expanded B.
The context conversion is explicit and only proved-private spills disappear. -/
theorem first_block (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second) :
    Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context)
      [first, second] (firstNativeFinal n context pointer limit) ∧
    Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0)
      (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second)
      (firstProofFinal p pointer limit) ∧
    PrivateSpills.AgreesOutside (p.regs 10) (firstNativeFinal n context pointer limit).memory
      (firstProofFinal p pointer limit).memory ∧
    (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second).filterMap
      (PrivateSpills.projectEvent (p.regs 10)) = [first, second] ∧
    ((firstNativeFinal n context pointer limit).pc = 32 ↔ (firstProofFinal p pointer limit).pc = 11) ∧
    ((firstNativeFinal n context pointer limit).pc = 24 ↔ (firstProofFinal p pointer limit).pc = 24) ∧
    ∀ event ∈ SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second,
      PrivateSpills.projectEvent (p.regs 10) event = none →
      ∃ kind address bytes initialized, event = .memory kind address bytes initialized ∧ bytes.length = 8 ∧
        ∀ i < 8, PrivateSpills.privateByte (p.regs 10) (address + BitVec.ofNat 64 i) := by
  have prefixRun := PacketEntryCertificate.entry_translation PacketCheckedPlatform.externals
    n p context pointer limit first second entry
  have guardRun := PacketGuardCertificate.native_guard
    (SimpleEntryCertificate.loaded n context pointer limit) pointer limit
  rw [PacketGuardCertificate.before, SimpleBlocks.native_at_guard] at guardRun
  have bounds : ∀ pc ∈ PacketGuardCertificate.proofPositions pointer limit, 4 ≤ pc ∧ pc < 26 := by
    intro pc member
    unfold PacketGuardCertificate.proofPositions at member
    split at member <;> simp at member <;> omega
  have proofGuard := (PacketCheckedPlatform.body_evaluate
    (PacketGuardCertificate.proofPositions pointer limit) bounds
    (PacketGuardCertificate.proofBefore (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit)).trans
    (PacketGuardCertificate.checked_guard (SimpleEntryCertificate.prefixFinal p pointer limit)
      pointer limit PacketCheckedPlatform.externals)
  rw [PacketGuardCertificate.proofBefore, SimpleBlocks.proof_at_guard] at proofGuard
  have corresponding := PacketGuardCertificate.corresponding_successors
    (SimpleEntryCertificate.loaded n context pointer limit)
    (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit
  refine ⟨?_, ?_, ?_, prefixRun.2.2.2.1, corresponding.1, corresponding.2, prefixRun.2.2.2.2⟩
  · simpa only [List.append_nil, firstNativeFinal] using
      prefixRun.1.append (ARM64Path.evaluate_sound _ _ _ _ _ guardRun)
  · apply PacketCheckedPlatform.execution_transport
    simpa only [List.append_nil, firstProofFinal] using
      prefixRun.2.1.append (BPFPath.evaluate_sound _ _ _ _ _ proofGuard)
  · exact prefixRun.2.2.1
end KProgTV.PacketCheckedBlocks
#print axioms KProgTV.PacketCheckedBlocks.first_block
