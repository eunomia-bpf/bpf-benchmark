import PacketGuardCertificate
import SimpleBlocks
set_option maxRecDepth 4096
set_option maxHeartbeats 1000000
namespace KProgTV.PacketEntryCertificate
open KProgFormal.Reference KProgTV.PacketCompiled

def physical : Array Byte := (program.set! 0 0x79 |>.set! 16 0x79 |>.set! 18 8)

theorem decode0 : AArch64.decode (native.extract 0 4) =
    .ok (.pairMemory SimpleEntryCertificate.pair) := rfl

/-- Both byte-decoded native entries execute the same canonical instruction,
including both first-fault possibilities in the stated split-pair profile. -/
theorem native_entry_equal (n : AArch64.State) (context : Word) :
    ARM64Path.evaluate 0 native [0] (SimpleEntryCertificate.before n context) =
      ARM64Path.evaluate 0 SimpleCompiled.native [0] (SimpleEntryCertificate.before n context) := by
  simp +decide [ARM64Path.evaluate, ARM64Path.step, SimpleEntryCertificate.before,
    decode0, SimpleEntryCertificate.decode0, native_size, SimpleEntryCertificate.native_size,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem native_full_state (n : AArch64.State) (context : Word) :
    ARM64Path.evaluate 0 native [0] (SimpleEntryCertificate.before n context) =
      .ok (SimpleEntryCertificate.result n context) :=
  (native_entry_equal n context).trans (SimpleEntryCertificate.native_full_state n context)

theorem prefix_instruction : ∀ pc : Fin 7, ∃ i,
    BPF.decode physical pc.val = .ok i ∧ BPF.decode SimplePlatform.physical pc.val = .ok i ∧
      i.code ≠ 0x18 := by
  have same : ∀ pc : Fin 7, (match BPF.decode physical pc.val, BPF.decode SimplePlatform.physical pc.val with
      | .ok a, .ok b => decide (a = b ∧ a.code ≠ 0x18)
      | _, _ => false) = true := by native_decide
  intro pc
  have known := same pc
  cases a : BPF.decode physical pc.val with
  | error error => simp [a] at known
  | ok left =>
    cases b : BPF.decode SimplePlatform.physical pc.val with
    | error error => simp [a, b] at known
    | ok right =>
      have relation : left = right ∧ left.code ≠ 0x18 := by simpa [a, b] using known
      exact ⟨left, rfl, congrArg Except.ok relation.1.symm, relation.2⟩

theorem prefix_evaluate (env : BPF.Environment) (s : BPF.State) :
    BPFPath.evaluate env physical [0,1,2,3,4,5,6] s =
      BPFPath.evaluate env SimplePlatform.physical [0,1,2,3,4,5,6] s := by
  apply BPFPath.evaluate_program_congr_if_wide
  intro pc member
  have inside : pc < 7 := by simp at member; omega
  obtain ⟨i, left, right, noWide⟩ := prefix_instruction ⟨pc, inside⟩
  exact ⟨i, left, right, fun wide => False.elim (noWide wide)⟩

/-- Reuse the proved private-frame relation and event erasure for this exact
compiled entry prefix. Transport to the virtual XDP proof remains separate. -/
theorem entry_translation (env : BPF.Environment) (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second) :
    Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context) [first, second]
      (SimpleEntryCertificate.loaded n context pointer limit) ∧
    Execution (BPFPath.instructionStep env physical) (SimpleEntryCertificate.proofBefore p context 0)
      (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second)
      (SimpleEntryCertificate.prefixFinal p pointer limit) ∧
    PrivateSpills.AgreesOutside (p.regs 10) (SimpleEntryCertificate.loaded n context pointer limit).memory
      (SimpleEntryCertificate.prefixFinal p pointer limit).memory ∧
    (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second).filterMap
      (PrivateSpills.projectEvent (p.regs 10)) = [first, second] ∧
    ∀ event ∈ SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second,
      PrivateSpills.projectEvent (p.regs 10) event = none →
      ∃ kind address bytes initialized, event = .memory kind address bytes initialized ∧ bytes.length = 8 ∧
        ∀ i < 8, PrivateSpills.privateByte (p.regs 10) (address + BitVec.ofNat 64 i) := by
  have original := SimpleEntryCertificate.entry_translation env n p context pointer limit first second
    entry.memory entry.read0 entry.read1 entry.write8 entry.write16 entry.read8 entry.read16 entry.guest0 entry.guest1
  have nativeRun : ARM64Path.evaluate 0 native [0] (SimpleEntryCertificate.before n context) =
      .ok ⟨SimpleEntryCertificate.loaded n context pointer limit, [first, second], none⟩ := by
    simpa only [SimpleEntryCertificate.result, SimpleEntryCertificate.loaded, entry.memory, entry.read0, entry.read1]
      using native_full_state n context
  have proofRun := (prefix_evaluate env (SimpleEntryCertificate.proofBefore p context 0)).trans
    (SimpleEntryCertificate.proof_prefix_full_state env p context pointer limit first second
      entry.read0 entry.read1 entry.write8 entry.write16 entry.read8 entry.read16 entry.guest1)
  exact ⟨ARM64Path.evaluate_sound _ _ _ _ _ nativeRun, BPFPath.evaluate_sound _ _ _ _ _ proofRun,
    original.2.2⟩
end KProgTV.PacketEntryCertificate
#print axioms KProgTV.PacketEntryCertificate.native_full_state
#print axioms KProgTV.PacketEntryCertificate.entry_translation
