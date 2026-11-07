import PacketExecutionRelocation
import SimpleInvocationABI
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.PacketInvocationABI
open KProgFormal.Reference KProgTV.PacketCompiled KProgTV.PacketPCRelocation

abbrev preservesABI := KProgTV.SimpleInvocationABI.preservesABI

def instructionABI (s : AArch64.State) (position : Nat) : Prop :=
  match AArch64.decode (native.extract position (position+4)) with
  | .error _ => False
  | .ok instruction => preservesABI s (AArch64.step instruction s).state

theorem all_instructions_preserve (s : AArch64.State) :
    ∀ position : Fin 17, instructionABI s (position.val*4) := by
  simp only [Fin.forall_fin_succ]
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals first
    | (intro impossible; exact Fin.elim0 impossible)
    | skip
  all_goals simp only [Fin.val_zero, Fin.val_succ, Fin.ofNat', Fin.instOfNat]
  all_goals unfold instructionABI
  all_goals first
    | rw [PacketEntryCertificate.decode0]
    | rw [PacketGuardCertificate.decode4]
    | rw [PacketGuardCertificate.decode8]
    | rw [PacketGuardCertificate.decode12]
    | rw [PacketGuardCertificate.decode16]
    | rw [PacketGuardCertificate.decode20]
    | rw [PacketCheckedBlocks.native_decode24]
    | rw [PacketCheckedBlocks.native_decode28]
    | rw [PacketStoreTransport.packet_decode32]
    | rw [PacketStoreTransport.packet_decode36]
    | rw [PacketStoreTransport.packet_decode40]
    | rw [PacketStoreTransport.packet_decode44]
    | rw [PacketStoreTransport.packet_decode48]
    | rw [PacketStoreTransport.packet_decode52]
    | rw [PacketStoreTransport.packet_decode56]
    | rw [PacketStoreTransport.packet_decode60]
    | rw [PacketCheckedBlocks.native_decode64]
  all_goals simp +decide [Fin.ofNat', Fin.instOfNat, preservesABI, KProgTV.SimpleInvocationABI.preservesABI, AArch64.step,
    AArch64.pairMemoryStep, SimpleEntryCertificate.pair, AArch64.pairRegisters,
    AArch64.spAlignmentFault, AArch64.memoryBase, AArch64.readReg, AArch64.writeReg,
    AArch64.moveRegStep, AArch64.readData, AArch64.writeData, AArch64.compareStep,
    AArch64.compareOperand, AArch64.arithmeticImmediateStep, AArch64.arithmeticRegisterStep,
    AArch64.arithmeticShift, AArch64.shiftValue, AArch64.branchStep,
    AArch64.memoryStep, AArch64.MemoryWidth.bytes, BitVec.add_assoc]
  all_goals repeat' first
    | rfl
    | (split <;> simp_all [BitVec.add_assoc])
  all_goals
    cases first : readMemory s.memory (s.gpr 0) AArch64.Width.w64.bytes with
    | error fault =>
        try simp_all [Fin.ofNat', Fin.instOfNat]
        all_goals
          intro r large
          have reg0 : (0 : AArch64.Register).val = 0 := rfl
          have reg7 : (7 : AArch64.Register).val = 7 := rfl
          have reg8 : (8 : AArch64.Register).val = 8 := rfl
          have reg9 : (9 : AArch64.Register).val = 9 := rfl
          have reg10 : (10 : AArch64.Register).val = 10 := rfl
          have reg11 : (11 : AArch64.Register).val = 11 := rfl
          have gpr0 : (0 : AArch64.Gpr).val = 0 := rfl
          have gpr7 : (7 : AArch64.Gpr).val = 7 := rfl
          have gpr8 : (8 : AArch64.Gpr).val = 8 := rfl
          have gpr9 : (9 : AArch64.Gpr).val = 9 := rfl
          have gpr10 : (10 : AArch64.Gpr).val = 10 := rfl
          have gpr11 : (11 : AArch64.Gpr).val = 11 := rfl
          have h0 : r.val ≠ 0 := by omega
          have h7 : r.val ≠ 7 := by omega
          have h8 : r.val ≠ 8 := by omega
          have h9 : r.val ≠ 9 := by omega
          have h10 : r.val ≠ 10 := by omega
          have h11 : r.val ≠ 11 := by omega
          simp_all [reg0, reg7, reg8, reg9, reg10, reg11, gpr0, gpr7, gpr8, gpr9, gpr10, gpr11]
    | ok pair =>
        rcases pair with ⟨value, event⟩
        cases second : readMemory s.memory (s.gpr 0 + BitVec.ofNat 64 AArch64.Width.w64.bytes)
            AArch64.Width.w64.bytes with
        | error fault =>
            try simp_all [Fin.ofNat', Fin.instOfNat]
            all_goals
              intro r large
              have reg0 : (0 : AArch64.Register).val = 0 := rfl
              have reg7 : (7 : AArch64.Register).val = 7 := rfl
              have reg8 : (8 : AArch64.Register).val = 8 := rfl
              have reg9 : (9 : AArch64.Register).val = 9 := rfl
              have reg10 : (10 : AArch64.Register).val = 10 := rfl
              have reg11 : (11 : AArch64.Register).val = 11 := rfl
              have gpr0 : (0 : AArch64.Gpr).val = 0 := rfl
              have gpr7 : (7 : AArch64.Gpr).val = 7 := rfl
              have gpr8 : (8 : AArch64.Gpr).val = 8 := rfl
              have gpr9 : (9 : AArch64.Gpr).val = 9 := rfl
              have gpr10 : (10 : AArch64.Gpr).val = 10 := rfl
              have gpr11 : (11 : AArch64.Gpr).val = 11 := rfl
              have h0 : r.val ≠ 0 := by omega
              have h7 : r.val ≠ 7 := by omega
              have h8 : r.val ≠ 8 := by omega
              have h9 : r.val ≠ 9 := by omega
              have h10 : r.val ≠ 10 := by omega
              have h11 : r.val ≠ 11 := by omega
              simp_all [reg0, reg7, reg8, reg9, reg10, reg11, gpr0, gpr7, gpr8, gpr9, gpr10, gpr11]
        | ok pair =>
            rcases pair with ⟨value2, event2⟩
            try simp_all [Fin.ofNat', Fin.instOfNat]
            all_goals
              intro r large
              have reg0 : (0 : AArch64.Register).val = 0 := rfl
              have reg7 : (7 : AArch64.Register).val = 7 := rfl
              have reg8 : (8 : AArch64.Register).val = 8 := rfl
              have reg9 : (9 : AArch64.Register).val = 9 := rfl
              have reg10 : (10 : AArch64.Register).val = 10 := rfl
              have reg11 : (11 : AArch64.Register).val = 11 := rfl
              have gpr0 : (0 : AArch64.Gpr).val = 0 := rfl
              have gpr7 : (7 : AArch64.Gpr).val = 7 := rfl
              have gpr8 : (8 : AArch64.Gpr).val = 8 := rfl
              have gpr9 : (9 : AArch64.Gpr).val = 9 := rfl
              have gpr10 : (10 : AArch64.Gpr).val = 10 := rfl
              have gpr11 : (11 : AArch64.Gpr).val = 11 := rfl
              have h0 : r.val ≠ 0 := by omega
              have h7 : r.val ≠ 7 := by omega
              have h8 : r.val ≠ 8 := by omega
              have h9 : r.val ≠ 9 := by omega
              have h10 : r.val ≠ 10 := by omega
              have h11 : r.val ≠ 11 := by omega
              simp_all [reg0, reg7, reg8, reg9, reg10, reg11, gpr0, gpr7, gpr8, gpr9, gpr10, gpr11]

open KProgTV.PacketExecutionRelocation

theorem preservesABI_refl (s : AArch64.State) : preservesABI s s :=
  ⟨rfl, rfl, rfl, fun _ _ => rfl⟩

theorem preservesABI_trans {a b c : AArch64.State}
    (ab : preservesABI a b) (bc : preservesABI b c) : preservesABI a c :=
  ⟨bc.1.trans ab.1, bc.2.1.trans ab.2.1, bc.2.2.1.trans ab.2.2.1,
    fun r large => (bc.2.2.2 r large).trans (ab.2.2.2 r large)⟩

theorem instruction_preserves (s : AArch64.State) (valid : closedPC s.pc)
    {events : List Event} {next : AArch64.State}
    (head : ARM64Path.instructionStep 0 native s events next) : preservesABI s next := by
  obtain ⟨result, run, _, state⟩ := head
  by_cases atEnd : s.pc.toNat = 68
  · exact False.elim (end_has_no_step s atEnd run)
  · obtain ⟨position, atPosition⟩ := pc_index s.pc valid atEnd
    have zero (value : Word) : value - (0 : Word) = value := BitVec.sub_zero value
    have bound : position.val*4 < 2^64 := by omega
    have unwrap : s.pc.toNat = position.val*4 := by
      rw [atPosition]
      simp [BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound]
    have abi := all_instructions_preserve s position
    unfold instructionABI at abi
    cases decoded : AArch64.decode (native.extract (position.val*4) (position.val*4+4)) with
    | error error => simp [decoded] at abi
    | ok instruction =>
        rw [decoded] at abi
        have executed : ARM64Path.step 0 native s = .ok (AArch64.step instruction s) := by
          simp +decide [ARM64Path.step, native_size, zero, unwrap, decoded, Except.bind, Except.map,
            Except.pure, Bind.bind, Pure.pure, Except.instMonad] <;> omega
        have same := Except.ok.inj (executed.symm.trans run)
        simpa only [← state, ← same] using abi

theorem execution_preserves {s last : AArch64.State} {trace : List Event}
    (run : Execution (ARM64Path.instructionStep 0 native) s trace last)
    (valid : closedPC s.pc) : preservesABI s last := by
  revert valid
  induction run with
  | refl s => intro _; exact preservesABI_refl s
  | next head tail ih =>
      intro valid
      exact preservesABI_trans (instruction_preserves _ valid head) (ih (step_closed _ valid head))

/-- Invert actual byte execution at the captured RX base. All non-PC state and
all ordered effects are retained; this does not substitute a chosen native path. -/
theorem instruction_unbase (base : Word) (s : AArch64.State) (valid : closedPC s.pc)
    {events : List Event} {next : AArch64.State}
    (head : ARM64Path.instructionStep base native (shiftPC base s) events next) :
    ∃ relative, ARM64Path.instructionStep 0 native s events relative ∧
      next = shiftPC base relative ∧ closedPC relative.pc := by
  obtain ⟨result, run, effects, state⟩ := head
  rw [step_shift base s valid] at run
  cases original : ARM64Path.step 0 native s with
  | error error =>
      rw [original] at run
      cases run
  | ok before =>
      simp only [original, Except.map] at run
      have same := Except.ok.inj run
      cases same
      have relative : ARM64Path.instructionStep 0 native s events before.state :=
        ⟨before, original, effects, rfl⟩
      exact ⟨before.state, relative, state.symm, step_closed s valid relative⟩

theorem execution_unbase (base : Word) {actual last : AArch64.State} {trace : List Event}
    (run : Execution (ARM64Path.instructionStep base native) actual trace last)
    (s : AArch64.State) (starts : actual = shiftPC base s) (valid : closedPC s.pc) :
    ∃ relative, Execution (ARM64Path.instructionStep 0 native) s trace relative ∧
      last = shiftPC base relative := by
  induction run generalizing s with
  | refl actual => exact ⟨s, Execution.refl s, starts⟩
  | next head tail ih =>
      rw [starts] at head
      obtain ⟨middle, first, next, closed⟩ := instruction_unbase base s valid head
      obtain ⟨relative, rest, ending⟩ := ih middle next closed
      exact ⟨relative, Execution.next first rest, ending⟩

/-- Every prefix of actual native execution preserves the supported host ABI.
No verifier acceptance, memory permissions or favorable branch is assumed. -/
theorem every_RX_prefix_preserves (base : Word) (n : AArch64.State) (context : Word)
    {trace : List Event} {last : AArch64.State}
    (run : Execution (ARM64Path.instructionStep base native)
      (shiftPC base (SimpleEntryCertificate.before n context)) trace last) :
    preservesABI n last := by
  have valid : closedPC (SimpleEntryCertificate.before n context).pc := by
    simp [closedPC, SimpleEntryCertificate.before]
  obtain ⟨relative, executed, ending⟩ := execution_unbase base run _ rfl valid
  have kept := execution_preserves executed valid
  have initial : preservesABI n (SimpleEntryCertificate.before n context) := by
    refine ⟨rfl, rfl, rfl, ?_⟩
    intro r large
    have nonzero : r.val ≠ 0 := by omega
    simp only [SimpleEntryCertificate.before, nonzero, ↓reduceIte]
  have complete := preservesABI_trans initial kept
  rw [ending]
  exact complete


/-- Explicit supported entry contract, supplied by the paired kernel/JIT and
Cortex-A72 platform. It is a premise, not established by resetting a state. -/
abbrev EntryState := KProgTV.SimpleInvocationABI.EntryState

theorem entry_is_model (base context : Word) (actual : AArch64.State)
    (entry : EntryState base context actual) :
    shiftPC base (SimpleEntryCertificate.before actual context) = actual := by
  simpa only [PacketPCRelocation.shiftPC, SimplePCRelocation.shiftPC] using
    KProgTV.SimpleInvocationABI.entry_is_model base context actual entry

theorem actual_entry_prefix_checked (base context : Word) (actual : AArch64.State)
    (entryState : EntryState base context actual) (p : BPF.State)
    (pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions actual p context pointer limit first second)
    (checked : Event → Prop)
    (verifierSound : ∀ trace last,
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0) trace last →
      ∀ event ∈ trace, checked event)
    {trace : List Event} {last : AArch64.State}
    (run : Execution (ARM64Path.instructionStep base native) actual trace last) :
    (∀ event ∈ trace, checked event) ∧ preservesABI actual last := by
  have modeled : Execution (ARM64Path.instructionStep base native)
      (shiftPC base (SimpleEntryCertificate.before actual context)) trace last := by
    rw [entry_is_model base context actual entryState]
    exact run
  exact ⟨every_RX_prefix_checked base actual p context pointer limit first second entry checked verifierSound modeled,
    every_RX_prefix_preserves base actual context modeled⟩

end KProgTV.PacketInvocationABI
#print axioms KProgTV.PacketInvocationABI.all_instructions_preserve

#print axioms KProgTV.PacketInvocationABI.every_RX_prefix_preserves

#print axioms KProgTV.PacketInvocationABI.entry_is_model
#print axioms KProgTV.PacketInvocationABI.actual_entry_prefix_checked
