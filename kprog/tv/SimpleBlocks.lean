import SimpleEntryCertificate
import SimpleGuardCertificate

namespace KProgTV.SimpleBlocks
open KProgFormal.Reference KProgTV.SimpleCompiled

structure EntryConditions (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event) : Prop where
  memory : n.memory = p.memory
  read0 : readMemory p.memory context 8 = .ok (pointer, first)
  read1 : readMemory p.memory (context + (8#64)) 8 = .ok (limit, second)
  write8 : permitted p.memory.writable (p.regs 10 - (8#64)) 8 = true
  write16 : permitted p.memory.writable (p.regs 10 - (16#64)) 8 = true
  read8 : permitted p.memory.readable (p.regs 10 - (8#64)) 8 = true
  read16 : permitted p.memory.readable (p.regs 10 - (16#64)) 8 = true
  guest0 : ¬ PrivateSpills.privateByte (p.regs 10) context
  guest1 : ∀ i < 8, ¬ PrivateSpills.privateByte (p.regs 10)
    (context + (8#64) + BitVec.ofNat 64 i)

theorem native_at_guard (n : AArch64.State) (context pointer limit : Word) :
    SimpleGuardCertificate.before (SimpleEntryCertificate.loaded n context pointer limit) pointer limit = SimpleEntryCertificate.loaded n context pointer limit := by
  simp +decide [SimpleGuardCertificate.before, SimpleEntryCertificate.loaded, SimpleEntryCertificate.before, AArch64.writeReg]
  funext r
  have r8 : (8 : AArch64.Register).val = 8 := rfl
  have r9 : (9 : AArch64.Register).val = 9 := rfl
  by_cases h8 : r.val = 8 <;> by_cases h9 : r.val = 9 <;> simp_all

theorem proof_at_guard (p : BPF.State) (pointer limit : Word) :
    SimpleGuardCertificate.proofBefore (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit = SimpleEntryCertificate.prefixFinal p pointer limit := by
  simp +decide [SimpleGuardCertificate.proofBefore, SimpleEntryCertificate.prefixFinal]
  funext r
  by_cases h1 : r = 1 <;> by_cases h2 : r = 2 <;> simp_all [Fin.ext_iff]

def firstNativeFinal (n : AArch64.State) (context pointer limit : Word) : AArch64.State :=
  SimpleGuardCertificate.final (SimpleEntryCertificate.loaded n context pointer limit) pointer limit

def firstProofFinal (p : BPF.State) (pointer limit : Word) : BPF.State :=
  { SimpleEntryCertificate.prefixFinal p pointer limit with pc := if pointer > limit then 27 else 8 }

/-- Complete native BB0 (LDP/MOV/CMP/BHI), matched to all actual physical
BPF entry/spill/guard instructions, retaining the real branch successor. -/
theorem first_block (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : EntryConditions n p context pointer limit first second) :
    Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context) [first, second]
      (firstNativeFinal n context pointer limit) ∧
    Execution (BPFPath.instructionStep SimpleGuardCertificate.noExternals SimplePlatform.physical) (SimpleEntryCertificate.proofBefore p context 0)
      (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second) (firstProofFinal p pointer limit) ∧
    PrivateSpills.AgreesOutside (p.regs 10) (firstNativeFinal n context pointer limit).memory
      (firstProofFinal p pointer limit).memory ∧
    (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second).filterMap
      (PrivateSpills.projectEvent (p.regs 10)) = [first, second] ∧
    (firstNativeFinal n context pointer limit).pc = (if pointer > limit then 36 else 16) ∧
    (firstProofFinal p pointer limit).pc = (if pointer > limit then 27 else 8) ∧
    ∀ event ∈ SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second,
      PrivateSpills.projectEvent (p.regs 10) event = none →
      ∃ kind address bytes initialized,
        event = .memory kind address bytes initialized ∧ bytes.length = 8 ∧
        ∀ i < 8, PrivateSpills.privateByte (p.regs 10) (address + BitVec.ofNat 64 i) := by
  have entryRun := SimpleEntryCertificate.entry_translation SimpleGuardCertificate.noExternals n p context pointer limit first second
    entry.memory entry.read0 entry.read1 entry.write8 entry.write16 entry.read8 entry.read16 entry.guest0 entry.guest1
  have nativeGuard := SimpleGuardCertificate.native_first_block (SimpleEntryCertificate.loaded n context pointer limit) pointer limit
  rw [native_at_guard] at nativeGuard
  have same : ∀ pc ∈ [7], BPF.decode SimplePlatform.physical pc = BPF.decode proof pc ∧
      BPF.decode SimplePlatform.physical (pc + 1) = BPF.decode proof (pc + 1) := by
    intro pc inside
    simp only [List.mem_singleton] at inside
    subst pc
    simpa only [SimplePlatform.raw_is_exact_clang] using SimplePlatform.body_decode ⟨3, by decide⟩
  have proofGuard := (BPFPath.evaluate_program_congr SimpleGuardCertificate.noExternals SimplePlatform.physical proof [7]
    same (SimpleGuardCertificate.proofBefore (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit)).trans
      (SimpleGuardCertificate.proof_first_block (SimpleEntryCertificate.prefixFinal p pointer limit) pointer limit)
  rw [proof_at_guard] at proofGuard
  refine ⟨?_, ?_, ?_, entryRun.2.2.2.1, ?_, rfl, entryRun.2.2.2.2⟩
  · simpa only [List.append_nil, firstNativeFinal] using
      entryRun.1.append (ARM64Path.evaluate_sound _ _ _ _ _ nativeGuard)
  · simpa only [List.append_nil, firstProofFinal] using
      entryRun.2.1.append (BPFPath.evaluate_sound _ _ _ _ _ proofGuard)
  · simpa only [firstNativeFinal, SimpleGuardCertificate.final, SimpleGuardCertificate.before, AArch64.writeReg, firstProofFinal] using entryRun.2.2.1
  · rfl

end KProgTV.SimpleBlocks
#print axioms KProgTV.SimpleBlocks.first_block
