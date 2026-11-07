import PacketPCRelocation
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.PacketExecutionRelocation
open KProgFormal.Reference KProgTV.PacketCompiled KProgTV.PacketPCRelocation

def closedPC (pc : Word) : Prop := pc.toNat ≤ 68 ∧ pc.toNat % 4 = 0

def instructionPC (s : AArch64.State) (position : Nat) : Prop :=
  match AArch64.decode (native.extract position (position+4)) with
  | .error _ => False
  | .ok instruction => closedPC (AArch64.step instruction
      { s with pc := BitVec.ofNat 64 position }).state.pc

theorem all_successors (s : AArch64.State) :
    ∀ position : Fin 17, instructionPC s (position.val*4) := by
  simp only [Fin.forall_fin_succ]
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals first
    | (intro impossible; exact Fin.elim0 impossible)
    | skip
  all_goals simp only [Fin.val_zero, Fin.val_succ, Fin.ofNat', Fin.instOfNat]
  all_goals unfold instructionPC
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
  all_goals simp +decide [Fin.ofNat', Fin.instOfNat, closedPC, AArch64.step,
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
    | error fault => simp_all
    | ok pair =>
        rcases pair with ⟨value, event⟩
        cases second : readMemory s.memory (s.gpr 0 + BitVec.ofNat 64 AArch64.Width.w64.bytes)
            AArch64.Width.w64.bytes with
        | error fault => simp_all
        | ok pair =>
            rcases pair with ⟨value2, event2⟩
            simp_all [BitVec.add_assoc]


theorem pc_index (pc : Word) (valid : closedPC pc) (notEnd : pc.toNat ≠ 68) :
    ∃ position : Fin 17, pc = BitVec.ofNat 64 (position.val*4) := by
  have range := valid.1
  have aligned := valid.2
  refine ⟨⟨pc.toNat/4, by omega⟩, ?_⟩
  have offset : pc.toNat/4*4 = pc.toNat := by omega
  simp only [offset]
  simp

theorem step_at_closed (s : AArch64.State) (position : Fin 17)
    (atPosition : s.pc = BitVec.ofNat 64 (position.val*4))
    {result : Transition AArch64.State}
    (run : ARM64Path.step 0 native s = .ok result) : closedPC result.state.pc := by
  have zero (value : Word) : value - (0 : Word) = value := BitVec.sub_zero value
  have bound : position.val*4 < 2^64 := by omega
  have unwrap : s.pc.toNat = position.val*4 := by
    rw [atPosition]
    simp [BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound]
  have valid := all_successors s position
  unfold instructionPC at valid
  cases decoded : AArch64.decode (native.extract (position.val*4) (position.val*4+4)) with
  | error error => simp [decoded] at valid
  | ok instruction =>
      have fixed : { s with pc := BitVec.ofNat 64 (position.val*4) } = s := by rw [← atPosition]
      rw [decoded, fixed] at valid
      have executed : ARM64Path.step 0 native s = .ok (AArch64.step instruction s) := by
        simp +decide [ARM64Path.step, native_size, zero, unwrap, decoded, Except.bind, Except.map,
          Except.pure, Bind.bind, Pure.pure, Except.instMonad] <;> omega
      have same := Except.ok.inj (executed.symm.trans run)
      simpa only [← same] using valid

theorem end_has_no_step (s : AArch64.State) (atEnd : s.pc.toNat = 68)
    {result : Transition AArch64.State} (run : ARM64Path.step 0 native s = .ok result) : False := by
  have zero (value : Word) : value - (0 : Word) = value := BitVec.sub_zero value
  simp +decide [ARM64Path.step, native_size, zero, atEnd, Except.bind, Except.map,
    Except.pure, Bind.bind, Pure.pure, Except.instMonad] at run

theorem step_closed (s : AArch64.State) (valid : closedPC s.pc)
    {events : List Event} {next : AArch64.State}
    (head : ARM64Path.instructionStep 0 native s events next) : closedPC next.pc := by
  obtain ⟨result, run, _, state⟩ := head
  by_cases atEnd : s.pc.toNat = 68
  · exact False.elim (end_has_no_step s atEnd run)
  · obtain ⟨position, atPosition⟩ := pc_index s.pc valid atEnd
    simpa only [state] using step_at_closed s position atPosition run

theorem step_shift (base : Word) (s : AArch64.State) (valid : closedPC s.pc) :
    ARM64Path.step base native (shiftPC base s) =
      (ARM64Path.step 0 native s).map (shiftTransition base) := by
  by_cases atEnd : s.pc.toNat = 68
  · have zero (value : Word) : value - (0 : Word) = value := BitVec.sub_zero value
    have cancel (value : Word) : base + value - base = value := by
      rw [BitVec.add_comm base value]
      exact BitVec.add_sub_cancel value base
    simp +decide [ARM64Path.step, native_size, shiftPC, cancel, zero, atEnd, Except.bind,
      Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  · obtain ⟨position, atPosition⟩ := pc_index s.pc valid atEnd
    exact PacketPCRelocation.step_at base s position atPosition

theorem instruction_rebase (base : Word) (s : AArch64.State) (valid : closedPC s.pc)
    {events : List Event} {next : AArch64.State}
    (head : ARM64Path.instructionStep 0 native s events next) :
    ARM64Path.instructionStep base native (shiftPC base s) events (shiftPC base next) := by
  obtain ⟨result, run, effects, state⟩ := head
  refine ⟨shiftTransition base result, ?_, effects, ?_⟩
  · simpa only [run, Except.map] using step_shift base s valid
  · simp only [shiftTransition, state]

theorem execution_rebase (base : Word) {s last : AArch64.State} {trace : List Event}
    (run : Execution (ARM64Path.instructionStep 0 native) s trace last)
    (valid : closedPC s.pc) :
    Execution (ARM64Path.instructionStep base native) (shiftPC base s) trace (shiftPC base last) ∧
      closedPC last.pc := by
  revert valid
  induction run with
  | refl s => intro valid; exact ⟨Execution.refl _, valid⟩
  | next head tail ih =>
      intro valid
      have nextValid := step_closed _ valid head
      have rest := ih nextValid
      exact ⟨Execution.next (instruction_rebase base _ valid head) rest.1, rest.2⟩


/-- A closed native return/fault remains closed at the actual RX base. -/
theorem terminal_rebase (base : Word) (s : AArch64.State) (valid : closedPC s.pc)
    (trace : List Event)
    (quiet : ∀ events next, ARM64Path.instructionStep 0 native s events next →
      next = s ∧ ∀ event ∈ events, event ∈ trace) :
    ∀ events next, ARM64Path.instructionStep base native (shiftPC base s) events next →
      next = shiftPC base s ∧ ∀ event ∈ events, event ∈ trace := by
  intro events next head
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
      have relation := quiet events before.state ⟨before, original, effects, rfl⟩
      exact ⟨state.symm.trans (congrArg (shiftPC base) relation.1), relation.2⟩

theorem native_deterministic (base : Word) {s t u : AArch64.State} {first second : List Event}
    (left : ARM64Path.instructionStep base native s first t)
    (right : ARM64Path.instructionStep base native s second u) : first = second ∧ t = u := by
  obtain ⟨a, runA, effectA, stateA⟩ := left
  obtain ⟨b, runB, effectB, stateB⟩ := right
  have same := Except.ok.inj (runA.symm.trans runB)
  cases same
  exact ⟨effectA.symm.trans effectB, stateA.symm.trans stateB⟩

/-- Concrete safety for every native prefix at an arbitrary actual RX base.
The program's memory/helper/fault effects and entire non-PC state are unchanged;
all guards, private spills and real return/fault paths come from the same TV. -/
theorem every_RX_prefix_checked (base : Word) (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second)
    (checked : Event → Prop)
    (verifierSound : ∀ trace last,
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0) trace last →
      ∀ event ∈ trace, checked event)
    {trace : List Event} {last : AArch64.State}
    (run : Execution (ARM64Path.instructionStep base native)
      (shiftPC base (SimpleEntryCertificate.before n context)) trace last) :
    ∀ event ∈ trace, checked event := by
  obtain ⟨ns, ps, expected, proofTrace, complete, _, _, _, quiet⟩ :=
    PacketInvocation.matched_invocation n p context pointer limit first second entry
  have initial : closedPC (SimpleEntryCertificate.before n context).pc := by
    simp [closedPC, SimpleEntryCertificate.before]
  have actual := execution_rebase base complete initial
  have allowed := PacketInvocation.every_native_prefix_checked n p context pointer limit first second
    entry checked verifierSound complete
  have ending := terminal_rebase base ns actual.2 expected quiet
  exact execution_checked_of_complete (step := ARM64Path.instructionStep base native)
    (fun left right => native_deterministic base left right) checked actual.1 allowed
    (fun effects next head => ⟨(ending effects next head).1,
      fun event inside => allowed event ((ending effects next head).2 event inside)⟩) run

end KProgTV.PacketExecutionRelocation
#print axioms KProgTV.PacketExecutionRelocation.all_successors

#print axioms KProgTV.PacketExecutionRelocation.execution_rebase

#print axioms KProgTV.PacketExecutionRelocation.every_RX_prefix_checked
