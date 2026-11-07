import SimpleStoreCertificate
import PacketCheckedPlatform
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.PacketStoreTransport
open KProgFormal.Reference KProgTV.PacketCompiled


/-- The two store bodies have different byte locations and final branch span.
Only PC is transported. All canonical memory/fault/register effects are kept. -/
def transferPC (s : AArch64.State) : AArch64.State :=
  { s with pc := if s.pc = (80#64) then (64#64) else s.pc - (12#64) }
def transferTransition (t : Transition AArch64.State) : Transition AArch64.State :=
  { t with state := transferPC t.state }
def sourceAt (s : AArch64.State) (offset : Nat) : AArch64.State :=
  { s with pc := BitVec.ofNat 64 (44 + offset) }

theorem packet_decode32 : AArch64.decode (native.extract 32 36) =
    .ok (.moveImmediate .w32 9 0x614e) := by rfl
theorem packet_decode36 : AArch64.decode (native.extract 36 40) =
    .ok (.moveImmediate .w32 0 2) := by rfl
theorem packet_decode40 : AArch64.decode (native.extract 40 44) =
    .ok (.memory ⟨.word, .store 31, 8, 3⟩) := by rfl
theorem packet_decode44 : AArch64.decode (native.extract 44 48) =
    .ok (.memory ⟨.byte, .store 31, 8, 7⟩) := by rfl
theorem packet_decode48 : AArch64.decode (native.extract 48 52) =
    .ok (.memory ⟨.half, .store 9, 8, 0⟩) := by rfl
theorem packet_decode52 : AArch64.decode (native.extract 52 56) =
    .ok (.moveImmediate .w32 9 0xbc) := by rfl
theorem packet_decode56 : AArch64.decode (native.extract 56 60) =
    .ok (.memory ⟨.byte, .store 9, 8, 2⟩) := by rfl
theorem packet_decode60 : AArch64.decode (native.extract 60 64) = .ok (.branch 4) := by rfl


def stepCommutes (s : AArch64.State) (offset : Nat) : Prop :=
  ARM64Path.step 0 native (transferPC (sourceAt s offset)) =
    (ARM64Path.step 0 SimpleCompiled.native (sourceAt s offset)).map transferTransition

theorem all_store_steps (s : AArch64.State) : ∀ position : Fin 8, stepCommutes s (position.val*4) := by
  simp only [Fin.forall_fin_succ]
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals first | (intro impossible; exact Fin.elim0 impossible) | skip
  all_goals simp only [Fin.val_zero, Fin.val_succ, Fin.ofNat', Fin.instOfNat]
  all_goals simp +decide [stepCommutes, sourceAt, transferPC, transferTransition,
    ARM64Path.step, native_size, SimpleStoreCertificate.native_size,
    Fin.val_zero, Fin.val_succ, Fin.ofNat', Fin.instOfNat,
    packet_decode32, packet_decode36, packet_decode40, packet_decode44,
    packet_decode48, packet_decode52, packet_decode56, packet_decode60,
    SimpleStoreCertificate.decode44, SimpleStoreCertificate.decode48,
    SimpleStoreCertificate.decode52, SimpleStoreCertificate.decode56,
    SimpleStoreCertificate.decode60, SimpleStoreCertificate.decode64,
    SimpleStoreCertificate.decode68, SimpleStoreCertificate.decode72,
    AArch64.step, AArch64.memoryStep, AArch64.memoryBase, AArch64.readReg,
    AArch64.spAlignmentFault, AArch64.MemoryWidth.bytes, AArch64.branchStep,
    AArch64.writeReg, AArch64.narrow, AArch64.Width.bits, writeMemory,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  all_goals repeat' first | rfl | (split <;> simp_all)

def allowed (position : Nat) : Prop := ∃ index : Fin 8, position = 44 + index.val*4

theorem native_evaluation_execution (positions : List Nat)
    (inside : ∀ position ∈ positions, allowed position)
    (s : AArch64.State) (result : Transition AArch64.State)
    (accepted : ARM64Path.evaluate 0 SimpleCompiled.native positions s = .ok result) :
    Execution (ARM64Path.instructionStep 0 native) (transferPC s) result.events (transferPC result.state) := by
  apply ARM64Path.evaluate_execution_transport 0 0 SimpleCompiled.native native transferPC allowed
    ?_ positions inside s result accepted
  intro before position valid pc effect executed
  obtain ⟨index, equal⟩ := valid
  have actualPosition : before.pc = BitVec.ofNat 64 (44 + index.val*4) := by
    simpa +decide [equal] using pc
  have fixed : sourceAt before (index.val*4) = before := by
    unfold sourceAt
    rw [← actualPosition]
  have same := all_store_steps before index
  unfold stepCommutes at same
  rw [fixed] at same
  refine ⟨transferTransition effect, ?_, rfl, rfl⟩
  simpa only [executed, Except.map] using same


def faultStays (s : AArch64.State) (offset : Nat) : Prop :=
  ∀ result, ARM64Path.step 0 SimpleCompiled.native (sourceAt s offset) = .ok result →
    ∀ reason, result.fault = some reason → result.state.pc = (sourceAt s offset).pc

theorem all_source_fault_steps (s : AArch64.State) :
    ∀ position : Fin 8, faultStays s (position.val*4) := by
  simp only [Fin.forall_fin_succ]
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals first | (intro impossible; exact Fin.elim0 impossible) | skip
  all_goals simp only [Fin.val_zero, Fin.val_succ, Fin.ofNat', Fin.instOfNat]
  all_goals simp +decide [faultStays, sourceAt, ARM64Path.step, SimpleStoreCertificate.native_size,
    SimpleStoreCertificate.decode44, SimpleStoreCertificate.decode48,
    SimpleStoreCertificate.decode52, SimpleStoreCertificate.decode56,
    SimpleStoreCertificate.decode60, SimpleStoreCertificate.decode64,
    SimpleStoreCertificate.decode68, SimpleStoreCertificate.decode72,
    AArch64.step, AArch64.memoryStep, AArch64.memoryBase, AArch64.readReg,
    AArch64.spAlignmentFault, AArch64.MemoryWidth.bytes, AArch64.branchStep,
    AArch64.writeReg, AArch64.narrow, AArch64.Width.bits, writeMemory,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  all_goals repeat' first | rfl | (split <;> simp_all)

theorem fault_step_pc (s : AArch64.State) (index : Fin 8)
    (pc : s.pc = BitVec.ofNat 64 (44+index.val*4)) (result : Transition AArch64.State)
    (executed : ARM64Path.step 0 SimpleCompiled.native s = .ok result)
    (reason : Fault) (fault : result.fault = some reason) : result.state.pc = s.pc := by
  have fixed : sourceAt s (index.val*4) = s := by unfold sourceAt; rw [← pc]
  have stays := all_source_fault_steps s index
  unfold faultStays at stays
  rw [fixed] at stays
  exact stays result executed reason fault

theorem evaluation_fault_position (positions : List Nat)
    (inside : ∀ position ∈ positions, allowed position)
    (s : AArch64.State) (result : Transition AArch64.State)
    (accepted : ARM64Path.evaluate 0 SimpleCompiled.native positions s = .ok result)
    (reason : Fault) (fault : result.fault = some reason) :
    ∃ index : Fin 8, result.state.pc = BitVec.ofNat 64 (44+index.val*4) := by
  induction positions generalizing s result with
  | nil => simp [ARM64Path.evaluate] at accepted; cases accepted; cases fault
  | cons position rest ih =>
    simp only [ARM64Path.evaluate] at accepted
    split at accepted
    · simp at accepted
    · rename_i matching
      obtain ⟨index, equal⟩ := inside position (by simp)
      have pc : s.pc = BitVec.ofNat 64 (44+index.val*4) := by simpa +decide [equal] using matching
      cases executed : ARM64Path.step 0 SimpleCompiled.native s with
      | error error => rw [executed] at accepted; cases accepted
      | ok first =>
        rw [executed] at accepted
        cases firstFault : first.fault with
        | some why =>
          have unchanged := fault_step_pc s index pc first executed why firstFault
          cases rest with
          | nil =>
            simp [executed, firstFault] at accepted
            cases accepted
            exact ⟨index, unchanged.trans pc⟩
          | cons next tail => simp [executed, firstFault] at accepted
        | none =>
          simp only [firstFault, Option.isSome, ↓reduceIte] at accepted
          cases continued : ARM64Path.evaluate 0 SimpleCompiled.native rest first.state with
          | error error => rw [continued] at accepted; simp [firstFault] at accepted
          | ok tail =>
            rw [continued] at accepted
            simp [firstFault] at accepted
            cases accepted
            exact ih (fun pos member => inside pos (List.mem_cons_of_mem _ member)) first.state tail continued fault


def proofTransfer (s : BPF.State) : BPF.State := { s with pc := s.pc - 3 }
def proofTransferTransition (t : Transition BPF.State) : Transition BPF.State :=
  { t with state := proofTransfer t.state }
def proofSourceAt (s : BPF.State) (offset : Nat) : BPF.State :=
  { s with pc := Int.ofNat (14+offset) }

theorem packet_proofDecode11 : BPF.decode PacketCheckedPlatform.physical 11 = .ok ⟨191, 2, 1, 0, 0⟩ := rfl
theorem packet_proofDecode12 : BPF.decode PacketCheckedPlatform.physical 12 = .ok ⟨7, 2, 0, 0, 3⟩ := rfl
theorem packet_proofDecode13 : BPF.decode PacketCheckedPlatform.physical 13 = .ok ⟨183, 3, 0, 0, 0⟩ := rfl
theorem packet_proofDecode14 : BPF.decode PacketCheckedPlatform.physical 14 = .ok ⟨99, 2, 3, 0, 0⟩ := rfl
theorem packet_proofDecode15 : BPF.decode PacketCheckedPlatform.physical 15 = .ok ⟨191, 2, 1, 0, 0⟩ := rfl
theorem packet_proofDecode16 : BPF.decode PacketCheckedPlatform.physical 16 = .ok ⟨7, 2, 0, 0, 7⟩ := rfl
theorem packet_proofDecode17 : BPF.decode PacketCheckedPlatform.physical 17 = .ok ⟨115, 2, 3, 0, 0⟩ := rfl
theorem packet_proofDecode18 : BPF.decode PacketCheckedPlatform.physical 18 = .ok ⟨183, 2, 0, 0, 24910⟩ := rfl
theorem packet_proofDecode19 : BPF.decode PacketCheckedPlatform.physical 19 = .ok ⟨107, 1, 2, 0, 0⟩ := rfl
theorem packet_proofDecode20 : BPF.decode PacketCheckedPlatform.physical 20 = .ok ⟨7, 1, 0, 0, 2⟩ := rfl
theorem packet_proofDecode21 : BPF.decode PacketCheckedPlatform.physical 21 = .ok ⟨183, 2, 0, 0, 188⟩ := rfl
theorem packet_proofDecode22 : BPF.decode PacketCheckedPlatform.physical 22 = .ok ⟨115, 1, 2, 0, 0⟩ := rfl
theorem packet_proofDecode23 : BPF.decode PacketCheckedPlatform.physical 23 = .ok ⟨183, 0, 0, 0, 2⟩ := rfl



def proofStepCommutes (env : BPF.Environment) (s : BPF.State) (offset : Nat) : Prop :=
  BPF.step env PacketCheckedPlatform.physical (proofTransfer (proofSourceAt s offset)) =
    (BPF.step env SimpleCompiled.proof (proofSourceAt s offset)).map proofTransferTransition

theorem all_proof_store_steps (env : BPF.Environment) (s : BPF.State) :
    ∀ position : Fin 13, proofStepCommutes env s position.val := by
  simp only [Fin.forall_fin_succ]
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals first | (intro impossible; exact Fin.elim0 impossible) | skip
  all_goals simp only [Fin.val_zero, Fin.val_succ, Fin.ofNat', Fin.instOfNat]
  all_goals simp +decide [proofStepCommutes, proofSourceAt, proofTransfer, proofTransferTransition,
    BPF.step, BPF.execute, BPF.source, BPF.alu, BPF.setReg, BPF.store, writeMemory,
    packet_proofDecode11, packet_proofDecode12, packet_proofDecode13,
    packet_proofDecode14, packet_proofDecode15, packet_proofDecode16,
    packet_proofDecode17, packet_proofDecode18, packet_proofDecode19,
    packet_proofDecode20, packet_proofDecode21, packet_proofDecode22, packet_proofDecode23,
    SimpleStoreCertificate.proofDecode14, SimpleStoreCertificate.proofDecode15,
    SimpleStoreCertificate.proofDecode16, SimpleStoreCertificate.proofDecode17,
    SimpleStoreCertificate.proofDecode18, SimpleStoreCertificate.proofDecode19,
    SimpleStoreCertificate.proofDecode20, SimpleStoreCertificate.proofDecode21,
    SimpleStoreCertificate.proofDecode22, SimpleStoreCertificate.proofDecode23,
    SimpleStoreCertificate.proofDecode24, SimpleStoreCertificate.proofDecode25,
    SimpleStoreCertificate.proofDecode26,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  all_goals repeat' first | rfl | (split <;> simp_all)

def proofAllowed (position : Nat) : Prop := ∃ index : Fin 13, position = 14 + index.val

theorem proof_evaluation_execution (positions : List Nat)
    (inside : ∀ position ∈ positions, proofAllowed position)
    (s : BPF.State) (result : Transition BPF.State)
    (accepted : BPFPath.evaluate PacketCheckedPlatform.externals SimpleCompiled.proof positions s = .ok result) :
    Execution PacketCheckedPlatform.instructionStep (proofTransfer s) result.events (proofTransfer result.state) := by
  apply BPFPath.evaluate_execution_transport PacketCheckedPlatform.externals SimpleCompiled.proof
    proofTransfer PacketCheckedPlatform.instructionStep proofAllowed ?_ positions inside s result accepted
  intro before position valid pc effect executed
  obtain ⟨index, equal⟩ := valid
  have actualPosition : before.pc = Int.ofNat (14+index.val) := by simpa only [equal] using pc
  have fixed : proofSourceAt before index.val = before := by
    unfold proofSourceAt
    rw [← actualPosition]
  have same := all_proof_store_steps PacketCheckedPlatform.externals before index
  unfold proofStepCommutes at same
  rw [fixed] at same
  have physical : BPF.step PacketCheckedPlatform.externals PacketCheckedPlatform.physical (proofTransfer before) =
      .ok (proofTransferTransition effect) := by simpa only [executed, Except.map] using same
  exact ⟨proofTransferTransition effect, PacketCheckedPlatform.accepted_step _ _ physical, rfl, rfl⟩

theorem native_positions_inside (memory : Memory) (pointer : Word) :
    ∀ pc ∈ SimpleStoreCertificate.nativePositions memory pointer, allowed pc := by
  intro pc member
  have bounds : 44 ≤ pc ∧ pc ≤ 72 ∧ pc % 4 = 0 := by
    unfold SimpleStoreCertificate.nativePositions at member
    repeat' first | (split at member) | (simp at member; omega)
  refine ⟨⟨(pc-44)/4, by omega⟩, ?_⟩
  change pc = 44 + (pc-44)/4*4
  omega

theorem proof_positions_inside (memory : Memory) (pointer : Word) :
    ∀ pc ∈ SimpleStoreCertificate.proofPositions memory pointer, proofAllowed pc := by
  intro pc member
  have bounds : 14 ≤ pc ∧ pc ≤ 26 := by
    unfold SimpleStoreCertificate.proofPositions at member
    repeat' first | (split at member) | (simp at member; omega)
  refine ⟨⟨pc-14, by omega⟩, ?_⟩
  change pc = 14 + (pc-14)
  omega

/-- Exact compiled-PC correspondence; this is not an instruction semantics. -/
def proofNativePC (pc : Int) : Word :=
  let source := SimpleStoreCertificate.proofNativePC (pc+3)
  if source = (80#64) then (64#64) else source - (12#64)

/-- Both actual store executions retain complete mapped states, exact ordered
writes and first faults. No permission check is added to either artifact. -/
theorem store_execution_witnesses (related : Memory → Memory → Prop)
    (storeRelated : ∀ {first second}, related first second → ∀ address value count,
      related (storeMemory first address value count) (storeMemory second address value count))
    (n : AArch64.State) (p : BPF.State) (pointer : Word)
    (permissions : n.memory.writable = p.memory.writable) (initial : related n.memory p.memory) :
    ∃ (nr : Transition AArch64.State) (pr : Transition BPF.State),
      Execution (ARM64Path.instructionStep 0 native)
        (transferPC (SimpleStoreCertificate.nativeInitial n pointer)) nr.events (transferPC nr.state) ∧
      Execution PacketCheckedPlatform.instructionStep
        (proofTransfer (SimpleStoreCertificate.proofInitial { n with memory := p.memory } p pointer))
        pr.events (proofTransfer pr.state) ∧
      transferPC nr.state = transferPC (SimpleStoreCertificate.nativeStoreShape n pointer nr.state) ∧
      proofTransfer pr.state = proofTransfer (SimpleStoreCertificate.proofStoreShape p pointer pr.state) ∧
      related (transferPC nr.state).memory (proofTransfer pr.state).memory ∧
      nr.events = pr.events ∧ nr.fault = pr.fault ∧
      (transferPC nr.state).pc = proofNativePC (proofTransfer pr.state).pc ∧
      (∀ event ∈ nr.events, match event with
        | .memory .write _ bytes _ => bytes.length < 8 | .fault _ => True | _ => False) ∧
      (nr.fault = none ↔ (proofTransfer pr.state).pc = 24) ∧
      (∀ reason, nr.fault = some reason →
        ARM64Path.step 0 native (transferPC nr.state) =
          .ok ⟨transferPC nr.state, [.fault reason], some reason⟩ ∧ Event.fault reason ∈ nr.events) := by
  obtain ⟨nr, pr, nativeRun, proofRun, nativeShape, proofShape, memory, events, fault, pc, short, noFault, closed⟩ :=
    SimpleStoreCertificate.store_transition_relation related storeRelated n p pointer
      PacketCheckedPlatform.externals permissions initial
  have nativeExecution := native_evaluation_execution _ (native_positions_inside n.memory pointer) _ nr nativeRun
  have proofExecution := proof_evaluation_execution _ (proof_positions_inside p.memory pointer) _ pr proofRun
  have corresponding : (transferPC nr.state).pc = proofNativePC (proofTransfer pr.state).pc := by
    have cancel : pr.state.pc - 3 + 3 = pr.state.pc := by omega
    simp only [transferPC, proofTransfer, proofNativePC, cancel, pc]
  have returned : nr.fault = none ↔ (proofTransfer pr.state).pc = 24 := by
    rw [noFault]
    change pr.state.pc = 27 ↔ pr.state.pc - 3 = 24
    omega
  have faultClosed : ∀ reason, nr.fault = some reason →
      ARM64Path.step 0 native (transferPC nr.state) =
        .ok ⟨transferPC nr.state, [.fault reason], some reason⟩ ∧ Event.fault reason ∈ nr.events := by
    intro reason hasFault
    obtain ⟨index, position⟩ := evaluation_fault_position _ (native_positions_inside n.memory pointer)
      _ nr nativeRun reason hasFault
    have fixed : sourceAt nr.state (index.val*4) = nr.state := by
      unfold sourceAt
      rw [← position]
    have same := all_store_steps nr.state index
    unfold stepCommutes at same
    rw [fixed, (closed reason hasFault).1] at same
    exact ⟨by simpa only [Except.map, transferTransition] using same, (closed reason hasFault).2⟩
  exact ⟨nr, pr, nativeExecution, proofExecution, congrArg transferPC nativeShape,
    congrArg proofTransfer proofShape, memory, events, fault, corresponding, short, returned, faultClosed⟩
end KProgTV.PacketStoreTransport
#print axioms KProgTV.PacketStoreTransport.all_store_steps
#print axioms KProgTV.PacketStoreTransport.all_proof_store_steps
#print axioms KProgTV.PacketStoreTransport.store_execution_witnesses
