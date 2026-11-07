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
theorem native_decode64 : AArch64.decode (native.extract 64 68) =
    .ok (.moveRegister .w64 (.general 7) (.general 0)) := rfl

def nativeReturnBefore (n : AArch64.State) (value : Word) : AArch64.State :=
  { n with gpr := fun r => if r.val = 0 then value else n.gpr r, pc := 64 }

def nativeReturnFinal (n : AArch64.State) (value : Word) : AArch64.State :=
  { nativeReturnBefore n value with
    gpr := fun r => if r.val = 7 then value else (nativeReturnBefore n value).gpr r
    pc := 68 }

theorem native_return (n : AArch64.State) (value : Word) :
    ARM64Path.evaluate 0 native [64] (nativeReturnBefore n value) =
      .ok ⟨nativeReturnFinal n value, [], none⟩ := by
  simp +decide [ARM64Path.evaluate, ARM64Path.step, native_decode64,
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
  { p with regs := fun r => if r.val = 0 then value else p.regs r, pc := 24, halted := false }

def proofReturnFinal (p : BPF.State) (value : Word) : BPF.State :=
  { proofReturnBefore p value with pc := 26, halted := true }

theorem proof_decode24 : BPF.decode PacketCheckedPlatform.physical 24 = .ok ⟨5,0,0,0,0⟩ := rfl
theorem proof_decode25 : BPF.decode PacketCheckedPlatform.physical 25 = .ok ⟨149,0,0,0,0⟩ := rfl

theorem proof_return (p : BPF.State) (value : Word) :
    BPFPath.evaluate PacketCheckedPlatform.externals PacketCheckedPlatform.physical [24,25]
      (proofReturnBefore p value) = .ok ⟨proofReturnFinal p value, [], none⟩ := by
  simp +decide [BPFPath.evaluate, proof_decode24, proof_decode25,
    proofReturnBefore, proofReturnFinal, BPF.execute,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- The actual linked native trampoline and rewritten proof return preserve
all memory and produce the same ABI return value for every 64-bit input. -/
theorem return_executions (n : AArch64.State) (p : BPF.State) (value : Word) :
    Execution (ARM64Path.instructionStep 0 native) (nativeReturnBefore n value)
      [] (nativeReturnFinal n value) ∧
    Execution PacketCheckedPlatform.instructionStep (proofReturnBefore p value)
      [] (proofReturnFinal p value) ∧
    (nativeReturnFinal n value).gpr 7 = value ∧
    (proofReturnFinal p value).regs 0 = value ∧
    (nativeReturnFinal n value).memory = n.memory ∧
    (proofReturnFinal p value).memory = p.memory := by
  exact ⟨ARM64Path.evaluate_sound _ _ _ _ _ (native_return n value),
    PacketCheckedPlatform.execution_transport (BPFPath.evaluate_sound _ _ _ _ _ (proof_return p value)),
    by
      have gpr7 : (7 : AArch64.Gpr).val = 7 := rfl
      simp [nativeReturnFinal, gpr7],
    by simp [proofReturnFinal, proofReturnBefore], rfl, rfl⟩

/-- Every store witness stops at its first real fault or actual successor;
the witness contributes no executable permission test or artificial bound. -/

theorem native_decode24 : AArch64.decode (native.extract 24 28) =
    .ok (.moveRegister .w32 (.general 0) .zero) := rfl

theorem native_decode28 : AArch64.decode (native.extract 28 32) = .ok (.branch 36) := rfl

def rejectBefore (n : AArch64.State) : AArch64.State := { n with pc := 24 }
def rejectFinal (n : AArch64.State) : AArch64.State :=
  { AArch64.writeReg (rejectBefore n) 0 0 with pc := 64 }

theorem native_reject (n : AArch64.State) :
    ARM64Path.evaluate 0 native [24,28] (rejectBefore n) = .ok ⟨rejectFinal n, [], none⟩ := by
  simp +decide [ARM64Path.evaluate, ARM64Path.step, native_decode24, native_decode28,
    rejectBefore, rejectFinal, AArch64.step, AArch64.moveRegStep, AArch64.branchStep,
    AArch64.readData, AArch64.writeData, AArch64.readReg, AArch64.writeReg,
    AArch64.narrow, AArch64.Width.bits, Fin.ofNat', Fin.instOfNat,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem native_return_fixed (n : AArch64.State) (value : Word)
    (pc : n.pc = 64) (r0 : n.gpr 0 = value) : nativeReturnBefore n value = n := by
  have registers : (fun r : AArch64.Gpr => if r.val = 0 then value else n.gpr r) = n.gpr := by
    funext r
    by_cases zero : r.val = 0
    · have same : r = 0 := Fin.ext (by simpa using zero)
      simp [same, r0]
    · simp [zero]
  simp only [nativeReturnBefore, registers, ← pc]

theorem proof_return_fixed (p : BPF.State) (value : Word)
    (pc : p.pc = 24) (r0 : p.regs 0 = value) (active : p.halted = false) :
    proofReturnBefore p value = p := by
  have registers : (fun r : BPF.Register => if r.val = 0 then value else p.regs r) = p.regs := by
    funext r
    by_cases zero : r.val = 0
    · have same : r = 0 := Fin.ext (by simpa using zero)
      simp [same, r0]
    · simp [zero]
  simp only [proofReturnBefore, registers, ← pc, ← active]

theorem reject_execution (n : AArch64.State) (pc : n.pc = 24) :
    Execution (ARM64Path.instructionStep 0 native) n [] (nativeReturnFinal (rejectFinal n) 0) := by
  have atReject : rejectBefore n = n := by simp only [rejectBefore, ← pc]
  have first := native_reject n
  rw [atReject] at first
  have zero : (rejectFinal n).gpr 0 = 0 := by
    simp +decide [rejectFinal, AArch64.writeReg, Fin.ofNat', Fin.instOfNat]
  have last := native_return (rejectFinal n) 0
  rw [native_return_fixed (rejectFinal n) 0 rfl zero] at last
  simpa using (ARM64Path.evaluate_sound _ _ _ _ _ first).append
    (ARM64Path.evaluate_sound _ _ _ _ _ last)

theorem proof_exit_execution (p : BPF.State) (value : Word)
    (pc : p.pc = 24) (r0 : p.regs 0 = value) (active : p.halted = false) :
    Execution PacketCheckedPlatform.instructionStep p [] (proofReturnFinal p value) := by
  have actual := PacketCheckedPlatform.execution_transport
    (BPFPath.evaluate_sound _ _ _ _ _ (proof_return p value))
  rw [proof_return_fixed p value pc r0 active] at actual
  exact actual

/-- Complete guard rejection, through both real returns, with full
post-states and exactly the justified guest-effect projection. -/
theorem guard_rejection (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second)
    (reject : ¬ (pointer ≤ limit ∧ pointer + (8#64) ≤ limit)) :
    Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context)
      [first, second] (nativeReturnFinal (rejectFinal (firstNativeFinal n context pointer limit)) 0) ∧
    Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0)
      (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second)
      (proofReturnFinal (firstProofFinal p pointer limit) 0) ∧
    PrivateSpills.AgreesOutside (p.regs 10)
      (nativeReturnFinal (rejectFinal (firstNativeFinal n context pointer limit)) 0).memory
      (proofReturnFinal (firstProofFinal p pointer limit) 0).memory ∧
    (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second).filterMap
      (PrivateSpills.projectEvent (p.regs 10)) = [first, second] := by
  have firstRun := first_block n p context pointer limit first second entry
  have nativePC : (firstNativeFinal n context pointer limit).pc = 24 := by
    simp [firstNativeFinal, PacketGuardCertificate.final, reject]
  have proofPC : (firstProofFinal p pointer limit).pc = 24 := by
    simp [firstProofFinal, PacketGuardCertificate.proofFinal, reject]
  have zero : (firstProofFinal p pointer limit).regs 0 = 0 := by
    by_cases large : pointer > limit <;>
      simp +decide [firstProofFinal, PacketGuardCertificate.proofFinal, PacketGuardCertificate.proofBefore,
        SimpleGuardCertificate.proofBefore, SimpleEntryCertificate.prefixFinal, BPF.setReg, large]
  refine ⟨?_, ?_, ?_, firstRun.2.2.2.1⟩
  · simpa only [List.append_nil] using firstRun.1.append
      (reject_execution (firstNativeFinal n context pointer limit) nativePC)
  · simpa only [List.append_nil] using firstRun.2.1.append
      (proof_exit_execution (firstProofFinal p pointer limit) 0 proofPC zero rfl)
  · simpa only [nativeReturnFinal, nativeReturnBefore, rejectFinal, rejectBefore,
      AArch64.writeReg, proofReturnFinal, proofReturnBefore] using firstRun.2.2.1


theorem native_return_terminal (n : AArch64.State) (pc : n.pc = 68)
    (events : List Event) (next : AArch64.State)
    (executed : ARM64Path.instructionStep 0 native n events next) : False := by
  obtain ⟨result, run, _, _⟩ := executed
  simp +decide [ARM64Path.step, pc, Except.bind, Except.map, Except.pure,
    Bind.bind, Pure.pure, Except.instMonad] at run

theorem native_deterministic {s t u : AArch64.State} {first second : List Event}
    (left : ARM64Path.instructionStep 0 native s first t)
    (right : ARM64Path.instructionStep 0 native s second u) : first = second ∧ t = u := by
  obtain ⟨a, runA, effectA, stateA⟩ := left
  obtain ⟨b, runB, effectB, stateB⟩ := right
  have same := Except.ok.inj (runA.symm.trans runB)
  cases same
  exact ⟨effectA.symm.trans effectB, stateA.symm.trans stateB⟩

theorem projection_retains_identity (frame : Word) (event result : Event)
    (kept : PrivateSpills.projectEvent frame event = some result) : event = result := by
  cases event with
  | memory kind address bytes initialized =>
      cases kind <;> simp only [PrivateSpills.projectEvent] at kept
      all_goals first
        | exact Option.some.inj kept
        | (split at kept <;> simp_all)
  | helper | fault | exclusive => exact Option.some.inj kept

/-- For every real native execution prefix on either rejection outcome,
all effects were checked for the same expanded proof, under its soundness. -/
theorem rejected_native_prefix_checked (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second)
    (reject : ¬ (pointer ≤ limit ∧ pointer + (8#64) ≤ limit))
    (checked : Event → Prop)
    (verifierSound : ∀ trace last,
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0) trace last →
      ∀ event ∈ trace, checked event)
    {trace : List Event} {last : AArch64.State}
    (run : Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context) trace last) :
    ∀ event ∈ trace, checked event := by
  obtain ⟨nr, pr, _, projection⟩ := guard_rejection n p context pointer limit first second entry reject
  have proofChecked := verifierSound _ _ pr
  have allowed : ∀ event ∈ [first, second], checked event := by
    intro event inside
    rw [← projection] at inside
    obtain ⟨original, member, kept⟩ := List.mem_filterMap.mp inside
    have same := projection_retains_identity (p.regs 10) original event kept
    simpa only [same] using proofChecked original member
  exact execution_checked_of_complete (step := ARM64Path.instructionStep 0 native)
    (fun left right => native_deterministic left right) checked nr allowed
    (fun events next head => False.elim (native_return_terminal _ rfl events next head)) run

end KProgTV.PacketCheckedBlocks
#print axioms KProgTV.PacketCheckedBlocks.first_block

#print axioms KProgTV.PacketCheckedBlocks.return_executions
#print axioms KProgTV.PacketCheckedBlocks.guard_rejection

#print axioms KProgTV.PacketCheckedBlocks.rejected_native_prefix_checked
