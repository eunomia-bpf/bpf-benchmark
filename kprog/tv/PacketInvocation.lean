import PacketCheckedBlocks
import PacketStoreTransport
import SimpleCheckedBlocks
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.PacketInvocation
open KProgFormal.Reference KProgTV.PacketCompiled KProgTV.PacketCheckedBlocks KProgTV.PacketStoreTransport

theorem native_store_fixed (n : AArch64.State) (pointer : Word)
    (pc : n.pc = 32) (r8 : n.gpr 8 = pointer) :
    transferPC (SimpleStoreCertificate.nativeInitial n pointer) = n := by
  have registers : (fun r : AArch64.Gpr => if r.val = 8 then pointer else n.gpr r) = n.gpr := by
    funext r
    by_cases eight : r.val = 8
    · have same : r = 8 := Fin.ext (by simpa using eight)
      simp [same, r8]
    · simp [eight]
  simp +decide [SimpleStoreCertificate.nativeInitial, registers, transferPC]
  have normalized : (32#64) = n.pc := by simpa +decide using pc.symm
  change { n with pc := (32#64) } = n
  rw [normalized]

theorem proof_store_fixed (n : AArch64.State) (p : BPF.State) (pointer : Word)
    (pc : p.pc = 11) (r1 : p.regs 1 = pointer) (active : p.halted = false) :
    proofTransfer (SimpleStoreCertificate.proofInitial { n with memory := p.memory } p pointer) = p := by
  have registers : (fun r : BPF.Register => if r.val = 1 then pointer else p.regs r) = p.regs := by
    funext r
    by_cases one : r.val = 1
    · have same : r = 1 := Fin.ext (by simpa using one)
      simp [same, r1]
    · simp [one]
  simp [SimpleStoreCertificate.proofInitial, registers, proofTransfer, ← pc, ← active]

theorem passed_guards_store (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second)
    (pass : pointer ≤ limit ∧ pointer + (8#64) ≤ limit) :
    let n1 := firstNativeFinal n context pointer limit
    let p1 := firstProofFinal p pointer limit
    ∃ (nr : Transition AArch64.State) (pr : Transition BPF.State),
      transferPC nr.state = transferPC (SimpleStoreCertificate.nativeStoreShape n1 pointer nr.state) ∧
      proofTransfer pr.state = proofTransfer (SimpleStoreCertificate.proofStoreShape p1 pointer pr.state) ∧
      PrivateSpills.AgreesOutside (p.regs 10) (transferPC nr.state).memory (proofTransfer pr.state).memory ∧
      nr.events = pr.events ∧ nr.fault = pr.fault ∧
      (transferPC nr.state).pc = PacketStoreTransport.proofNativePC (proofTransfer pr.state).pc ∧
      (nr.fault = none ↔ (proofTransfer pr.state).pc = 24) ∧
      Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context)
        ([first, second] ++ nr.events) (transferPC nr.state) ∧
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0)
        (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second ++ pr.events) (proofTransfer pr.state) ∧
      (SimpleEntryCertificate.prefixEvents (p.regs 10) pointer limit first second ++ pr.events).filterMap
        (PrivateSpills.projectEvent (p.regs 10)) = [first, second] ++ nr.events ∧
      (∀ reason, nr.fault = some reason →
        ARM64Path.step 0 native (transferPC nr.state) =
          .ok ⟨transferPC nr.state, [.fault reason], some reason⟩ ∧ Event.fault reason ∈ nr.events) := by
  let n1 := firstNativeFinal n context pointer limit
  let p1 := firstProofFinal p pointer limit
  have firstRun := first_block n p context pointer limit first second entry
  have memory : PrivateSpills.AgreesOutside (p.regs 10) n1.memory p1.memory := firstRun.2.2.1
  have npc : n1.pc = 32 := by simp [n1, firstNativeFinal, PacketGuardCertificate.final, pass]
  have ppc : p1.pc = 11 := by simp [p1, firstProofFinal, PacketGuardCertificate.proofFinal, pass]
  have r8 : n1.gpr 8 = pointer := by
    simp +decide [n1, firstNativeFinal, PacketGuardCertificate.final, PacketGuardCertificate.before,
      SimpleGuardCertificate.before, SimpleEntryCertificate.loaded, SimpleEntryCertificate.before,
      AArch64.writeReg, Fin.ofNat', Fin.instOfNat]
  have r1 : p1.regs 1 = pointer := by
    by_cases large : pointer > limit <;>
      simp +decide [p1, firstProofFinal, PacketGuardCertificate.proofFinal, PacketGuardCertificate.proofBefore,
        SimpleGuardCertificate.proofBefore, SimpleEntryCertificate.prefixFinal, BPF.setReg, large,
        Fin.ofNat', Fin.instOfNat]
  obtain ⟨nr, pr, ne, pe, ns, ps, mem, events, fault, pc, short, complete, terminal⟩ :=
    store_execution_witnesses (PrivateSpills.AgreesOutside (p.regs 10))
      (by intro a b same address value count; exact PrivateSpills.store_agrees same address value count)
      n1 p1 pointer memory.2.1 memory
  rw [native_store_fixed n1 pointer npc r8] at ne
  rw [proof_store_fixed n1 p1 pointer ppc r1 rfl] at pe
  have projected : pr.events.filterMap (PrivateSpills.projectEvent (p.regs 10)) = nr.events := by
    simpa only [← events] using SimpleCheckedBlocks.short_write_trace_retained (p.regs 10) nr.events short
  refine ⟨nr, pr, ns, ps, mem, events, fault, pc, complete, ?_, ?_, ?_, terminal⟩
  · exact firstRun.1.append ne
  · exact firstRun.2.1.append pe
  · rw [List.filterMap_append, firstRun.2.2.2.1, projected]

theorem native_fault_terminal (n : AArch64.State) (reason : Fault) (trace : List Event)
    (repeats : ARM64Path.step 0 native n = .ok ⟨n, [.fault reason], some reason⟩)
    (member : Event.fault reason ∈ trace) :
    ∀ events next, ARM64Path.instructionStep 0 native n events next →
      next = n ∧ ∀ event ∈ events, event ∈ trace := by
  intro events next head
  obtain ⟨result, actual, effects, state⟩ := head
  have same := Except.ok.inj (repeats.symm.trans actual)
  cases same
  refine ⟨state.symm, ?_⟩
  intro event inside
  rw [← effects] at inside
  simp only [List.mem_singleton] at inside
  simpa only [inside] using member

theorem passed_guards_complete (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second)
    (pass : pointer ≤ limit ∧ pointer + (8#64) ≤ limit) :
    ∃ (ns : AArch64.State) (ps : BPF.State) (nativeTrace proofTrace : List Event),
      Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context) nativeTrace ns ∧
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0) proofTrace ps ∧
      PrivateSpills.AgreesOutside (p.regs 10) ns.memory ps.memory ∧
      proofTrace.filterMap (PrivateSpills.projectEvent (p.regs 10)) = nativeTrace ∧
      (∀ events next, ARM64Path.instructionStep 0 native ns events next →
        next = ns ∧ ∀ event ∈ events, event ∈ nativeTrace) := by
  obtain ⟨nr, pr, ns, ps, memory, events, fault, pc, complete, ne, pe, projected, terminal⟩ :=
    passed_guards_store n p context pointer limit first second entry pass
  let nn := transferPC nr.state
  let pp := proofTransfer pr.state
  by_cases normal : nr.fault = none
  · have ppc : pp.pc = 24 := complete.mp normal
    have sourcePPC : pr.state.pc = 27 := by
      change pr.state.pc - 3 = 24 at ppc
      omega
    have npc : nn.pc = 64 := by
      simpa +decide [nn, proofTransfer, sourcePPC, PacketStoreTransport.proofNativePC,
        SimpleStoreCertificate.proofNativePC] using pc
    have nvalue : nn.gpr 0 = 2 := by
      have shape := congrArg (fun s : AArch64.State => s.gpr 0) ns
      simpa +decide [nn, transferPC, SimpleStoreCertificate.nativeStoreShape, Fin.ofNat', Fin.instOfNat] using shape
    have pvalue : pp.regs 0 = 2 := by
      have shape := congrArg (fun s : BPF.State => s.regs 0) ps
      simpa +decide [pp, proofTransfer, SimpleStoreCertificate.proofStoreShape, sourcePPC,
        Fin.ofNat', Fin.instOfNat] using shape
    have active : pp.halted = false := by
      have shape := congrArg BPF.State.halted ps
      simpa only [proofTransfer, SimpleStoreCertificate.proofStoreShape] using shape
    have last := return_executions nn pp 2
    rw [native_return_fixed nn 2 npc nvalue, proof_return_fixed pp 2 ppc pvalue active] at last
    refine ⟨nativeReturnFinal nn 2, proofReturnFinal pp 2, _, _, ?_, ?_, ?_, projected, ?_⟩
    · simpa only [List.append_nil] using ne.append last.1
    · simpa only [List.append_nil] using pe.append last.2.1
    · simpa only [nativeReturnFinal, nativeReturnBefore, proofReturnFinal, proofReturnBefore] using memory
    · intro effects next executed
      exact False.elim (native_return_terminal _ rfl effects next executed)
  · refine ⟨nn, pp, _, _, ne, pe, memory, projected, ?_⟩
    cases found : nr.fault with
    | none => exact False.elim (normal found)
    | some reason =>
      have repeats := terminal reason found
      exact native_fault_terminal nn reason _ repeats.1 (List.mem_append_right _ repeats.2)

theorem matched_invocation (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second) :
    ∃ (ns : AArch64.State) (ps : BPF.State) (nativeTrace proofTrace : List Event),
      Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context) nativeTrace ns ∧
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0) proofTrace ps ∧
      PrivateSpills.AgreesOutside (p.regs 10) ns.memory ps.memory ∧
      proofTrace.filterMap (PrivateSpills.projectEvent (p.regs 10)) = nativeTrace ∧
      (∀ events next, ARM64Path.instructionStep 0 native ns events next →
        next = ns ∧ ∀ event ∈ events, event ∈ nativeTrace) := by
  by_cases pass : pointer ≤ limit ∧ pointer + (8#64) ≤ limit
  · exact passed_guards_complete n p context pointer limit first second entry pass
  · have result := guard_rejection n p context pointer limit first second entry pass
    refine ⟨_, _, _, _, result.1, result.2.1, result.2.2.1, result.2.2.2, ?_⟩
    intro effects next executed
    exact False.elim (native_return_terminal _ rfl effects next executed)

theorem every_native_prefix_checked (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second)
    (checked : Event → Prop)
    (verifierSound : ∀ trace last,
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0) trace last →
      ∀ event ∈ trace, checked event)
    {trace : List Event} {last : AArch64.State}
    (run : Execution (ARM64Path.instructionStep 0 native) (SimpleEntryCertificate.before n context) trace last) :
    ∀ event ∈ trace, checked event := by
  obtain ⟨ns, ps, nativeTrace, proofTrace, nr, pr, _, projection, quiet⟩ :=
    matched_invocation n p context pointer limit first second entry
  have proofChecked := verifierSound proofTrace ps pr
  have allowed : ∀ event ∈ nativeTrace, checked event := by
    intro event inside
    rw [← projection] at inside
    obtain ⟨original, member, kept⟩ := List.mem_filterMap.mp inside
    have same := PacketCheckedBlocks.projection_retains_identity (p.regs 10) original event kept
    simpa only [same] using proofChecked original member
  exact execution_checked_of_complete (step := ARM64Path.instructionStep 0 native)
    (fun left right => PacketCheckedBlocks.native_deterministic left right) checked nr allowed
    (fun effects next head => ⟨(quiet effects next head).1,
      fun event inside => allowed event ((quiet effects next head).2 event inside)⟩) run
theorem bound_native_prefix_checked (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (entry : SimpleBlocks.EntryConditions n p context pointer limit first second)
    (accepted : Artifact → Prop) (checked : Artifact → Event → Prop)
    (proofEntry : Artifact → BPF.State → Prop)
    (verifierSound : ∀ a, accepted a → a.proofBytes = PacketCompiled.program.toList →
      proofEntry a (SimpleEntryCertificate.proofBefore p context 0) → ∀ trace last,
      Execution PacketCheckedPlatform.instructionStep (SimpleEntryCertificate.proofBefore p context 0) trace last →
      ∀ event ∈ trace, checked a event)
    (validated executed : Artifact) (binding : executed = validated)
    (nativeBytes : validated.nativeBytes = native.toList) (entryPoint : validated.entry = 0)
    (proofBytes : validated.proofBytes = PacketCompiled.program.toList)
    (acceptance : accepted validated)
    (admittedEntry : proofEntry validated (SimpleEntryCertificate.proofBefore p context 0))
    {trace : List Event} {last : AArch64.State}
    (run : Execution
      (ARM64Path.instructionStep (BitVec.ofNat 64 executed.entry) executed.nativeBytes.toArray)
      (SimpleEntryCertificate.before n context) trace last) :
    ∀ event ∈ trace, checked validated event := by
  subst executed
  have actual : Execution (ARM64Path.instructionStep 0 native)
      (SimpleEntryCertificate.before n context) trace last := by
    simpa only [nativeBytes, entryPoint, Array.toArray_toList] using run
  exact every_native_prefix_checked n p context pointer limit first second entry
    (checked validated) (verifierSound validated acceptance proofBytes admittedEntry) actual


end KProgTV.PacketInvocation
#print axioms KProgTV.PacketInvocation.passed_guards_store
#print axioms KProgTV.PacketInvocation.matched_invocation
#print axioms KProgTV.PacketInvocation.every_native_prefix_checked

#print axioms KProgTV.PacketInvocation.bound_native_prefix_checked
