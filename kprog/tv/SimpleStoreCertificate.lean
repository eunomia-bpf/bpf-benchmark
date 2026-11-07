import ARM64Path
import BPFPath
import SimpleCompiled

set_option maxRecDepth 4096
set_option maxHeartbeats 2000000

namespace KProgTV.SimpleStoreCertificate
open KProgFormal.Reference KProgTV.SimpleCompiled

@[simp] theorem native_size : native.size = 84 := rfl

@[simp] theorem writable_after_store (m : Memory) (a v : Word) (n : Nat) :
    (storeMemory m a v n).writable = m.writable := rfl

-- These are decoder certificates for the actual frozen native bytes.
theorem decode44 : AArch64.decode (native.extract 44 48) =
    .ok (.moveImmediate .w32 9 0x614e) := by rfl
theorem decode48 : AArch64.decode (native.extract 48 52) =
    .ok (.moveImmediate .w32 0 2) := by rfl
theorem decode52 : AArch64.decode (native.extract 52 56) =
    .ok (.memory ⟨.word, .store 31, 8, 3⟩) := by rfl
theorem decode56 : AArch64.decode (native.extract 56 60) =
    .ok (.memory ⟨.byte, .store 31, 8, 7⟩) := by rfl
theorem decode60 : AArch64.decode (native.extract 60 64) =
    .ok (.memory ⟨.half, .store 9, 8, 0⟩) := by rfl
theorem decode64 : AArch64.decode (native.extract 64 68) =
    .ok (.moveImmediate .w32 9 0xbc) := by rfl
theorem decode68 : AArch64.decode (native.extract 68 72) =
    .ok (.memory ⟨.byte, .store 9, 8, 2⟩) := by rfl
theorem decode72 : AArch64.decode (native.extract 72 76) = .ok (.branch 8) := by rfl

def nativeInitial (n : AArch64.State) (pointer : Word) : AArch64.State :=
  { n with gpr := fun r => if r.val = 8 then pointer else n.gpr r, pc := 44 }

def written (memory : Memory) (pointer : Word) : Memory :=
  storeMemory (storeMemory (storeMemory (storeMemory memory (pointer + (3#64)) 0 4)
    (pointer + (7#64)) 0 1) pointer 0x614e 2) (pointer + (2#64)) 0xbc 1

def effects (pointer : Word) : List Event :=
  [.memory .write (pointer + (3#64)) [0,0,0,0] true,
   .memory .write (pointer + (7#64)) [0] true,
   .memory .write pointer [0x4e,0x61] true,
   .memory .write (pointer + (2#64)) [0xbc] true]

def nativeFinal (n : AArch64.State) (pointer : Word) : AArch64.State :=
  { nativeInitial n pointer with
    gpr := fun r => if r.val = 9 then 0xbc else if r.val = 0 then 2
      else (nativeInitial n pointer).gpr r
    memory := written n.memory pointer
    pc := 80 }

def nativeBlock (n : AArch64.State) (pointer : Word) :=
  ARM64Path.evaluate 0 native [44,48,52,56,60,64,68,72] (nativeInitial n pointer)

-- The hypotheses describe exactly the four native store permissions. No
-- extra guard, alignment restriction or initialized-value premise is added.
theorem native_full_state (n : AArch64.State) (pointer : Word)
    (p4 : permitted n.memory.writable (pointer + (3#64)) 4 = true)
    (p1 : permitted n.memory.writable (pointer + (7#64)) 1 = true)
    (p2 : permitted n.memory.writable pointer 2 = true)
    (p0 : permitted n.memory.writable (pointer + (2#64)) 1 = true) :
    nativeBlock n pointer = .ok ⟨nativeFinal n pointer, effects pointer, none⟩ := by
  simp +decide [nativeBlock, ARM64Path.evaluate, ARM64Path.step,
    decode44, decode48, decode52, decode56, decode60, decode64, decode68, decode72,
    nativeInitial, nativeFinal, effects, written,
    Fin.ofNat', Fin.instOfNat, AArch64.step, AArch64.narrow, AArch64.Width.bits, AArch64.writeReg,
    AArch64.memoryStep, AArch64.memoryBase, AArch64.readReg,
    AArch64.spAlignmentFault, AArch64.MemoryWidth.bytes, AArch64.branchStep,
    writeMemory, p4, p1, p2, p0, valueBytes,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  funext r
  have reg9 : (9 : AArch64.Register).val = 9 := rfl
  by_cases h9 : r.val = 9 <;> simp [reg9, h9]

theorem proofDecode14 : BPF.decode proof 14 = .ok ⟨191, 2, 1, 0, 0⟩ := rfl
theorem proofDecode15 : BPF.decode proof 15 = .ok ⟨7, 2, 0, 0, 3⟩ := rfl
theorem proofDecode16 : BPF.decode proof 16 = .ok ⟨183, 3, 0, 0, 0⟩ := rfl
theorem proofDecode17 : BPF.decode proof 17 = .ok ⟨99, 2, 3, 0, 0⟩ := rfl
theorem proofDecode18 : BPF.decode proof 18 = .ok ⟨191, 2, 1, 0, 0⟩ := rfl
theorem proofDecode19 : BPF.decode proof 19 = .ok ⟨7, 2, 0, 0, 7⟩ := rfl
theorem proofDecode20 : BPF.decode proof 20 = .ok ⟨115, 2, 3, 0, 0⟩ := rfl
theorem proofDecode21 : BPF.decode proof 21 = .ok ⟨183, 2, 0, 0, 24910⟩ := rfl
theorem proofDecode22 : BPF.decode proof 22 = .ok ⟨107, 1, 2, 0, 0⟩ := rfl
theorem proofDecode23 : BPF.decode proof 23 = .ok ⟨7, 1, 0, 0, 2⟩ := rfl
theorem proofDecode24 : BPF.decode proof 24 = .ok ⟨183, 2, 0, 0, 188⟩ := rfl
theorem proofDecode25 : BPF.decode proof 25 = .ok ⟨115, 1, 2, 0, 0⟩ := rfl
theorem proofDecode26 : BPF.decode proof 26 = .ok ⟨183, 0, 0, 0, 2⟩ := rfl


def noExternals : BPF.Environment where
  immediate := fun _ _ _ => .error "no external immediate in success block"
  helperCall := fun _ _ => .error "no helper in success block"
  helper := fun _ _ _ => .error "no helper effect in success block"

def proofInitial (n : AArch64.State) (p : BPF.State) (pointer : Word) : BPF.State :=
  { p with
    regs := fun r => if r.val = 1 then pointer else p.regs r
    memory := n.memory
    pc := 14
    halted := false }

def proofFinal (n : AArch64.State) (p : BPF.State) (pointer : Word) : BPF.State :=
  { p with
    regs := fun r => if r.val = 0 then 2 else if r.val = 1 then pointer + (2#64)
      else if r.val = 2 then 0xbc else if r.val = 3 then 0 else p.regs r
    memory := written n.memory pointer
    pc := 27, halted := false }

def proofBlock (n : AArch64.State) (p : BPF.State) (pointer : Word) :=
  BPFPath.evaluate noExternals proof [14,15,16,17,18,19,20,21,22,23,24,25,26] (proofInitial n p pointer)

theorem proof_full_state (n : AArch64.State) (p : BPF.State) (pointer : Word)
    (p4 : permitted n.memory.writable (pointer + (3#64)) 4 = true)
    (p1 : permitted n.memory.writable (pointer + (7#64)) 1 = true)
    (p2 : permitted n.memory.writable pointer 2 = true)
    (p0 : permitted n.memory.writable (pointer + (2#64)) 1 = true) :
    proofBlock n p pointer = .ok ⟨proofFinal n p pointer, effects pointer, none⟩ := by
  simp +decide [proofBlock, BPFPath.evaluate,
    proofDecode14, proofDecode15, proofDecode16, proofDecode17, proofDecode18, proofDecode19, proofDecode20, proofDecode21, proofDecode22, proofDecode23, proofDecode24, proofDecode25, proofDecode26,
    BPF.execute, BPF.alu, BPF.source, BPF.setReg, BPF.store,
    proofInitial, proofFinal, written, effects,
    writeMemory, p4, p1, p2, p0, valueBytes,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  funext r
  have reg0 : (0 : BPF.Register).val = 0 := rfl
  have reg1 : (1 : BPF.Register).val = 1 := rfl
  have reg2 : (2 : BPF.Register).val = 2 := rfl
  have reg3 : (3 : BPF.Register).val = 3 := rfl
  by_cases h0 : r.val = 0 <;> by_cases h1 : r.val = 1 <;>
    by_cases h2 : r.val = 2 <;> by_cases h3 : r.val = 3 <;>
    simp +decide [Fin.ext_iff, Fin.ofNat', Fin.instOfNat, reg0, reg1, reg2, reg3, h0, h1, h2, h3]


/-- Exact complete post-states, ordered guest effects, and actual CFG exits
for every pointer and complete architectural/memory input satisfying precisely
these four stores' permissions. There are no private spills in this block. -/
theorem matching_executions (n : AArch64.State) (p : BPF.State) (pointer : Word)
    (p4 : permitted n.memory.writable (pointer + (3#64)) 4 = true)
    (p1 : permitted n.memory.writable (pointer + (7#64)) 1 = true)
    (p2 : permitted n.memory.writable pointer 2 = true)
    (p0 : permitted n.memory.writable (pointer + (2#64)) 1 = true) :
    Execution (ARM64Path.instructionStep 0 native) (nativeInitial n pointer)
      (effects pointer) (nativeFinal n pointer) ∧
    Execution (BPFPath.instructionStep noExternals proof) (proofInitial n p pointer)
      (effects pointer) (proofFinal n p pointer) ∧
    (nativeFinal n pointer).memory = (proofFinal n p pointer).memory := by
  exact ⟨ARM64Path.evaluate_sound _ _ _ _ _ (native_full_state n pointer p4 p1 p2 p0),
    BPFPath.evaluate_sound _ _ _ _ _ (proof_full_state n p pointer p4 p1 p2 p0), rfl⟩


-- Choose only a certificate prefix ending at the real fault, if any. These
-- predicates do not appear as new checks in either executable artifact.
def nativePositions (memory : Memory) (pointer : Word) : List Nat :=
  if !permitted memory.writable (pointer + (3#64)) 4 then [44,48,52]
  else if !permitted memory.writable (pointer + (7#64)) 1 then [44,48,52,56]
  else if !permitted memory.writable pointer 2 then [44,48,52,56,60]
  else if !permitted memory.writable (pointer + (2#64)) 1 then [44,48,52,56,60,64,68]
  else [44,48,52,56,60,64,68,72]

def proofPositions (memory : Memory) (pointer : Word) : List Nat :=
  if !permitted memory.writable (pointer + (3#64)) 4 then [14,15,16,17]
  else if !permitted memory.writable (pointer + (7#64)) 1 then [14,15,16,17,18,19,20]
  else if !permitted memory.writable pointer 2 then [14,15,16,17,18,19,20,21,22]
  else if !permitted memory.writable (pointer + (2#64)) 1 then [14,15,16,17,18,19,20,21,22,23,24,25]
  else [14,15,16,17,18,19,20,21,22,23,24,25,26]

-- The corresponding exact native instruction on fault, or successor on success.
def proofNativePC (pc : Int) : Word :=
  if pc = 17 then 52 else if pc = 20 then 56 else if pc = 22 then 60
    else if pc = 25 then 68 else if pc = 27 then 80 else 0xffff

def nativeObserved (n : AArch64.State) (pointer : Word) :=
  (ARM64Path.evaluate 0 native (nativePositions n.memory pointer) (nativeInitial n pointer)).map
    fun result => (result.state.memory, result.events, result.fault, result.state.pc)

def proofObserved (n : AArch64.State) (p : BPF.State) (pointer : Word)
    (env : BPF.Environment := noExternals) :=
  (BPFPath.evaluate env proof (proofPositions n.memory pointer) (proofInitial n p pointer)).map
    fun result => (result.state.memory, result.events, result.fault, proofNativePC result.state.pc)

/-- Complete architectural post-state shape at each actual store exit. -/
def nativeStoreShape (n : AArch64.State) (pointer : Word) (after : AArch64.State) : AArch64.State :=
  { nativeInitial n pointer with
    gpr := fun r => if r.val = 9 then
        (if after.pc = 52 ∨ after.pc = 56 ∨ after.pc = 60 then 0x614e else 0xbc)
      else if r.val = 0 then 2 else (nativeInitial n pointer).gpr r
    memory := after.memory
    pc := after.pc }

def proofStoreShape (p : BPF.State) (pointer : Word) (after : BPF.State) : BPF.State :=
  { p with
    regs := fun r => if r.val = 0 ∧ after.pc = 27 then 2
      else if r.val = 1 then (if after.pc = 25 ∨ after.pc = 27 then pointer + (2#64) else pointer)
      else if r.val = 2 then (if after.pc = 17 then pointer + (3#64)
        else if after.pc = 20 then pointer + (7#64) else if after.pc = 22 then 0x614e else 0xbc)
      else if r.val = 3 then 0 else p.regs r
    memory := after.memory
    pc := after.pc
    halted := false }

/-- The same real store block runs on two memories with equal permissions.
A relation preserved by actual canonical writes holds after success or any
first fault. Complete transition witnesses retain all architectural fields. -/
theorem store_transition_relation (related : Memory → Memory → Prop)
    (storeRelated : ∀ {first second}, related first second → ∀ address value count,
      related (storeMemory first address value count) (storeMemory second address value count))
    (n : AArch64.State) (p : BPF.State) (pointer : Word) (env : BPF.Environment)
    (permissions : n.memory.writable = p.memory.writable)
    (initial : related n.memory p.memory) :
    ∃ nr pr,
      ARM64Path.evaluate 0 native (nativePositions n.memory pointer) (nativeInitial n pointer) = .ok nr ∧
      BPFPath.evaluate env proof (proofPositions p.memory pointer)
        (proofInitial { n with memory := p.memory } p pointer) = .ok pr ∧
      nr.state = nativeStoreShape n pointer nr.state ∧
      pr.state = proofStoreShape p pointer pr.state ∧
      related nr.state.memory pr.state.memory ∧ nr.events = pr.events ∧
      nr.fault = pr.fault ∧ nr.state.pc = proofNativePC pr.state.pc ∧
      (∀ event ∈ nr.events, match event with
        | .memory .write _ bytes _ => bytes.length < 8
        | .fault _ => True
        | _ => False) ∧
      (nr.fault = none ↔ pr.state.pc = 27) ∧
      (∀ reason, nr.fault = some reason →
        ARM64Path.step 0 native nr.state = .ok ⟨nr.state, [.fault reason], some reason⟩ ∧
        Event.fault reason ∈ nr.events) := by
  have related1 := storeRelated initial (pointer + (3#64)) 0 4
  have related2 := storeRelated related1 (pointer + (7#64)) 0 1
  have related3 := storeRelated related2 pointer 0x614e 2
  have related4 := storeRelated related3 (pointer + (2#64)) 0xbc 1
  cases p4 : permitted n.memory.writable (pointer + (3#64)) 4 <;>
    cases p1 : permitted n.memory.writable (pointer + (7#64)) 1 <;>
    cases p2 : permitted n.memory.writable pointer 2 <;>
    cases p0 : permitted n.memory.writable (pointer + (2#64)) 1 <;>
    simp +decide [nativePositions, proofPositions, proofNativePC, nativeStoreShape, proofStoreShape,
      ARM64Path.evaluate, ARM64Path.step, BPFPath.evaluate,
      decode44, decode48, decode52, decode56, decode60, decode64, decode68, decode72,
      proofDecode14, proofDecode15, proofDecode16, proofDecode17, proofDecode18, proofDecode19,
      proofDecode20, proofDecode21, proofDecode22, proofDecode23, proofDecode24, proofDecode25, proofDecode26,
      BPF.execute, BPF.alu, BPF.source, BPF.setReg, BPF.store, nativeInitial, proofInitial,
      Fin.ofNat', Fin.instOfNat, AArch64.step, AArch64.narrow, AArch64.Width.bits,
      AArch64.writeReg, AArch64.memoryStep, AArch64.memoryBase, AArch64.readReg,
      AArch64.spAlignmentFault, AArch64.MemoryWidth.bytes, AArch64.branchStep,
      writeMemory, ← permissions, p4, p1, p2, p0, valueBytes,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  all_goals repeat' constructor
  all_goals try assumption
  all_goals
    funext r
    have reg0 : (0 : AArch64.Register).val = 0 := rfl
    have reg9 : (9 : AArch64.Register).val = 9 := rfl
    have bpf0 : (0 : BPF.Register).val = 0 := rfl
    have bpf1 : (1 : BPF.Register).val = 1 := rfl
    have bpf2 : (2 : BPF.Register).val = 2 := rfl
    have bpf3 : (3 : BPF.Register).val = 3 := rfl
    by_cases h0 : r.val = 0 <;> by_cases h1 : r.val = 1 <;>
      by_cases h2 : r.val = 2 <;> by_cases h3 : r.val = 3 <;>
      by_cases h9 : r.val = 9 <;>
      simp_all [reg0, reg9, bpf0, bpf1, bpf2, bpf3, Fin.ext_iff, Fin.ofNat', Fin.instOfNat]

/-- No store-permission precondition: either execution faults at the same
access, with the same earlier writes, or both reach their corresponding exits.
Arbitrary unreadable/uninitialized bytes and wraparound pointers are included. -/
theorem including_faults (n : AArch64.State) (p : BPF.State) (pointer : Word)
    (env : BPF.Environment := noExternals) :
    ∃ result, nativeObserved n pointer = .ok result ∧ proofObserved n p pointer env = .ok result := by
  obtain ⟨nr, pr, nativeRun, proofRun, _, _, memory, events, fault, pc, _, _, _⟩ :=
    store_transition_relation (fun first second => first = second)
      (by
        intro first second same address value count
        cases same
        rfl)
      n { p with memory := n.memory } pointer env rfl rfl
  have actualProof : BPFPath.evaluate env proof (proofPositions n.memory pointer)
      (proofInitial n p pointer) = .ok pr := by
    simpa only [proofInitial] using proofRun
  refine ⟨(pr.state.memory, pr.events, pr.fault, proofNativePC pr.state.pc), ?_, ?_⟩
  · simp only [nativeObserved, nativeRun, Except.map, memory, events, fault, pc]
  · simp only [proofObserved, actualProof, Except.map]

end KProgTV.SimpleStoreCertificate
#print axioms KProgTV.SimpleStoreCertificate.native_full_state

#print axioms KProgTV.SimpleStoreCertificate.proof_full_state

#print axioms KProgTV.SimpleStoreCertificate.matching_executions

#print axioms KProgTV.SimpleStoreCertificate.including_faults

#print axioms KProgTV.SimpleStoreCertificate.store_transition_relation
