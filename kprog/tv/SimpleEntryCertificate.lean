import ARM64Path
import BPFPath
import SimpleCompiled
import SimplePlatform
import PrivateSpills

set_option maxRecDepth 4096
set_option maxHeartbeats 300000

namespace KProgTV.SimpleEntryCertificate
open KProgFormal.Reference KProgTV.SimpleCompiled

@[simp] theorem native_size : native.size = 84 := rfl
set_option pp.maxSteps 1000

-- Cortex-A72's pair consists of two ordered physical 64-bit loads.
def pair : AArch64.PairMemoryInstruction :=
  ⟨.w64, true, 8, 9, 0, 0, by decide⟩

theorem decode0 : AArch64.decode (native.extract 0 4) = .ok (.pairMemory pair) := by rfl

def before (n : AArch64.State) (context : Word) : AArch64.State :=
  { n with
    gpr := fun r => if r.val = 0 then context else n.gpr r
    pc := 0
    pairSingleAccess := false }

/-- Full architectural output, including faults before either load commits
registers. The second fault retains the first ordered read event. -/
def result (n : AArch64.State) (context : Word) : Transition AArch64.State :=
  let s := before n context
  match readMemory n.memory context 8 with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (pointer, first) =>
    match readMemory n.memory (context + (8#64)) 8 with
    | .error fault => ⟨s, [first, .fault fault], some fault⟩
    | .ok (limit, second) =>
      ⟨{ AArch64.writeReg (AArch64.writeReg s 8 pointer) 9 limit with pc := 4 },
        [first, second], none⟩

theorem native_full_state (n : AArch64.State) (context : Word) :
    ARM64Path.evaluate 0 native [0] (before n context) = .ok (result n context) := by
  cases first : readMemory n.memory context 8 with
  | error fault =>
      simp +decide [ARM64Path.evaluate, ARM64Path.step, decode0, before, result,
        AArch64.step, AArch64.pairMemoryStep, AArch64.pairRegisters, pair,
        AArch64.spAlignmentFault, AArch64.memoryBase, AArch64.readReg,
        AArch64.Width.bytes, AArch64.Width.bits, AArch64.narrow, first,
        Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  | ok firstValue =>
      rcases firstValue with ⟨pointer, firstEvent⟩
      cases second : readMemory n.memory (context + (8#64)) 8 <;>
        simp +decide [ARM64Path.evaluate, ARM64Path.step, decode0, before, result,
          AArch64.step, AArch64.pairMemoryStep, AArch64.pairRegisters, pair,
          AArch64.spAlignmentFault, AArch64.memoryBase, AArch64.readReg,
          AArch64.Width.bytes, AArch64.Width.bits, AArch64.narrow, first, second,
          Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

/-- The captured complete physical program has the same extent. Only the
actual kernel's two XDP pointer conversions differ from the clang bytes. -/
theorem physical_extent : SimplePlatform.physical.size = proof.size := by rfl

theorem physicalDecode0 : BPF.decode SimplePlatform.physical 0 = .ok ⟨0x79,2,1,0,0⟩ := by rfl
theorem physicalDecode1 : BPF.decode SimplePlatform.physical 1 = .ok ⟨0x7b,10,2,0xfff8,0⟩ := by rfl
theorem physicalDecode2 : BPF.decode SimplePlatform.physical 2 = .ok ⟨0x79,1,1,8,0⟩ := by rfl
theorem physicalDecode3 : BPF.decode SimplePlatform.physical 3 = .ok ⟨0x7b,10,1,0xfff0,0⟩ := by rfl


@[simp] theorem add_neg8 (value : Word) : value + (18446744073709551608#64) = value - (8#64) := by
  change value + -(8#64) = value - (8#64)
  exact BitVec.add_neg_eq_sub

@[simp] theorem add_neg16 (value : Word) : value + (18446744073709551600#64) = value - (16#64) := by
  change value + -(16#64) = value - (16#64)
  exact BitVec.add_neg_eq_sub


def proofBefore (p : BPF.State) (context : Word) (pc : Int) : BPF.State :=
  { p with
    regs := fun r => if r = 1 then context else p.regs r
    pc := pc
    halted := false }

def firstFinal (p : BPF.State) (context pointer : Word) : BPF.State :=
  { BPF.setReg (proofBefore p context 0) 2 pointer with
    pc := 2
    memory := storeMemory p.memory (p.regs 10 - (8#64)) pointer 8 }

/-- Actual context read followed by its actual compiler spill. The write is
retained in the full trace until the private-memory projection is justified. -/
theorem proof_first_load_spill (env : BPF.Environment) (p : BPF.State) (context pointer : Word) (event : Event)
    (read : readMemory p.memory context 8 = .ok (pointer, event))
    (write : permitted p.memory.writable (p.regs 10 - (8#64)) 8 = true) :
    BPFPath.evaluate env SimplePlatform.physical [0,1] (proofBefore p context 0) =
      .ok ⟨firstFinal p context pointer,
        [event, .memory .write (p.regs 10 - (8#64)) (valueBytes pointer 8) true], none⟩ := by
  simp +decide [BPFPath.evaluate, physicalDecode0, physicalDecode1,
    proofBefore, firstFinal, BPF.execute, BPF.load, BPF.store, BPF.setReg,
    read, writeMemory, write, BitVec.add_neg_eq_sub,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

def secondFinal (p : BPF.State) (context limit : Word) : BPF.State :=
  { BPF.setReg (proofBefore p context 2) 1 limit with
    pc := 4
    memory := storeMemory p.memory (p.regs 10 - (16#64)) limit 8 }

theorem proof_second_load_spill (env : BPF.Environment) (p : BPF.State) (context limit : Word) (event : Event)
    (read : readMemory p.memory (context + (8#64)) 8 = .ok (limit, event))
    (write : permitted p.memory.writable (p.regs 10 - (16#64)) 8 = true) :
    BPFPath.evaluate env SimplePlatform.physical [2,3] (proofBefore p context 2) =
      .ok ⟨secondFinal p context limit,
        [event, .memory .write (p.regs 10 - (16#64)) (valueBytes limit 8) true], none⟩ := by
  simp +decide [BPFPath.evaluate, physicalDecode2, physicalDecode3,
    proofBefore, secondFinal, BPF.execute, BPF.load, BPF.store, BPF.setReg,
    read, writeMemory, write, BitVec.add_neg_eq_sub,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]


theorem physicalDecode4 : BPF.decode SimplePlatform.physical 4 = .ok ⟨0xb7,0,0,0,0⟩ := by rfl
theorem physicalDecode5 : BPF.decode SimplePlatform.physical 5 = .ok ⟨0x79,1,10,0xfff8,0⟩ := by rfl
theorem physicalDecode6 : BPF.decode SimplePlatform.physical 6 = .ok ⟨0x79,2,10,0xfff0,0⟩ := by rfl

def spilled (memory : Memory) (frame pointer limit : Word) : Memory :=
  storeMemory (storeMemory memory (frame - (8#64)) pointer 8) (frame - (16#64)) limit 8

def prefixFinal (p : BPF.State) (pointer limit : Word) : BPF.State :=
  { p with
    regs := fun r => if r = 0 then 0 else if r = 1 then pointer else if r = 2 then limit else p.regs r
    memory := spilled p.memory (p.regs 10) pointer limit
    pc := 7
    halted := false }

def prefixEvents (frame pointer limit : Word) (first second : Event) : List Event :=
  [first, .memory .write (frame - (8#64)) (valueBytes pointer 8) true,
   second, .memory .write (frame - (16#64)) (valueBytes limit 8) true,
   .memory .read (frame - (8#64)) (valueBytes pointer 8) true,
   .memory .read (frame - (16#64)) (valueBytes limit 8) true]

/-- The entire actual compiler entry prefix. Permissions/disjointness are
platform memory facts; no executable guard or invented zero initialization is
inserted. Reloads are proved from the stores, not assumed as input values. -/
theorem proof_prefix_full_state (env : BPF.Environment) (p : BPF.State) (context pointer limit : Word)
    (first second : Event)
    (read0 : readMemory p.memory context 8 = .ok (pointer, first))
    (read1 : readMemory p.memory (context + (8#64)) 8 = .ok (limit, second))
    (write8 : permitted p.memory.writable (p.regs 10 - (8#64)) 8 = true)
    (write16 : permitted p.memory.writable (p.regs 10 - (16#64)) 8 = true)
    (read8 : permitted p.memory.readable (p.regs 10 - (8#64)) 8 = true)
    (read16 : permitted p.memory.readable (p.regs 10 - (16#64)) 8 = true)
    (guest : ∀ i < 8, ¬ PrivateSpills.privateByte (p.regs 10)
      (context + (8#64) + BitVec.ofNat 64 i)) :
    BPFPath.evaluate env SimplePlatform.physical [0,1,2,3,4,5,6] (proofBefore p context 0) =
      .ok ⟨prefixFinal p pointer limit, prefixEvents (p.regs 10) pointer limit first second, none⟩ := by
  have same := PrivateSpills.upper_spill_preserves_guest p.memory (p.regs 10) pointer
  have read1' : readMemory (storeMemory p.memory (p.regs 10 - (8#64)) pointer 8)
      (context + (8#64)) 8 = .ok (limit, second) := by
    rw [← PrivateSpills.guest_reads_preserved _ _ _ _ _ same guest]
    exact read1
  have upper := PrivateSpills.upper_spill_reload p.memory (p.regs 10) pointer limit read8
  have lower := PrivateSpills.spill_read
    (storeMemory p.memory (p.regs 10 - (8#64)) pointer 8) (p.regs 10 - (16#64)) limit read16
  simp +decide [BPFPath.evaluate, physicalDecode0, physicalDecode1, physicalDecode2,
    physicalDecode3, physicalDecode4, physicalDecode5, physicalDecode6,
    proofBefore, prefixFinal, prefixEvents, spilled, BPF.execute, BPF.load, BPF.store,
    BPF.source, BPF.alu, BPF.setReg, read0, read1', upper, lower, writeMemory, write8, write16,
    Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  funext r
  by_cases h0 : r = 0 <;> by_cases h1 : r = 1 <;> by_cases h2 : r = 2 <;> simp_all


/-- The private-effect projection preserves the order and exact payload of
both guest reads. No native/helper/fault/atomic event can be erased by it. -/
theorem entry_guest_trace (frame pointer limit : Word) (first second : Event)
    (keepFirst : PrivateSpills.projectEvent frame first = some first)
    (keepSecond : PrivateSpills.projectEvent frame second = some second) :
    (prefixEvents frame pointer limit first second).filterMap (PrivateSpills.projectEvent frame) =
      [first, second] := by
  simp only [prefixEvents, List.filterMap_cons, keepFirst, keepSecond]
  simp [PrivateSpills.projectEvent, valueBytes]


def loaded (n : AArch64.State) (context pointer limit : Word) : AArch64.State :=
  { AArch64.writeReg (AArch64.writeReg (before n context) 8 pointer) 9 limit with pc := 4 }

/-- The native entry instruction and the complete compiled entry prefix are
real executions with identical guest reads and full, explicitly related states.
The private trace projection is justified by `erased_event_private` and the
spill-memory/reload lemmas, including wraparound, rather than a hidden filter. -/
theorem entry_translation (env : BPF.Environment) (n : AArch64.State) (p : BPF.State)
    (context pointer limit : Word) (first second : Event)
    (memory : n.memory = p.memory)
    (read0 : readMemory p.memory context 8 = .ok (pointer, first))
    (read1 : readMemory p.memory (context + (8#64)) 8 = .ok (limit, second))
    (write8 : permitted p.memory.writable (p.regs 10 - (8#64)) 8 = true)
    (write16 : permitted p.memory.writable (p.regs 10 - (16#64)) 8 = true)
    (read8 : permitted p.memory.readable (p.regs 10 - (8#64)) 8 = true)
    (read16 : permitted p.memory.readable (p.regs 10 - (16#64)) 8 = true)
    (guest0 : ¬ PrivateSpills.privateByte (p.regs 10) context)
    (guest1 : ∀ i < 8, ¬ PrivateSpills.privateByte (p.regs 10)
      (context + (8#64) + BitVec.ofNat 64 i)) :
    Execution (ARM64Path.instructionStep 0 native) (before n context) [first, second]
      (loaded n context pointer limit) ∧
    Execution (BPFPath.instructionStep env SimplePlatform.physical) (proofBefore p context 0)
      (prefixEvents (p.regs 10) pointer limit first second) (prefixFinal p pointer limit) ∧
    PrivateSpills.AgreesOutside (p.regs 10) (loaded n context pointer limit).memory
      (prefixFinal p pointer limit).memory ∧
    (prefixEvents (p.regs 10) pointer limit first second).filterMap
      (PrivateSpills.projectEvent (p.regs 10)) = [first, second] ∧
    ∀ event ∈ prefixEvents (p.regs 10) pointer limit first second,
      PrivateSpills.projectEvent (p.regs 10) event = none →
      ∃ kind address bytes initialized,
        event = .memory kind address bytes initialized ∧ bytes.length = 8 ∧
        ∀ i < 8, PrivateSpills.privateByte (p.regs 10) (address + BitVec.ofNat 64 i) := by
  have nativeRun : ARM64Path.evaluate 0 native [0] (before n context) =
      .ok ⟨loaded n context pointer limit, [first, second], none⟩ := by
    simpa only [result, loaded, memory, read0, read1] using native_full_state n context
  have proofRun := proof_prefix_full_state env p context pointer limit first second
    read0 read1 write8 write16 read8 read16 guest1
  refine ⟨ARM64Path.evaluate_sound _ _ _ _ _ nativeRun,
    BPFPath.evaluate_sound _ _ _ _ _ proofRun, ?_, ?_, ?_⟩
  · simpa only [loaded, before, AArch64.writeReg, prefixFinal, spilled, memory] using
      PrivateSpills.two_spills_preserve_guest p.memory (p.regs 10) pointer limit
  · apply entry_guest_trace
    · exact PrivateSpills.read_event_retained p.memory (p.regs 10) context pointer 8 first read0 guest0
    · exact PrivateSpills.read_event_retained p.memory (p.regs 10) (context + (8#64)) limit 8 second read1
        (by simpa using guest1 0 (by decide))
  · intro event _ gone
    exact PrivateSpills.erased_event_private (p.regs 10) event gone

end KProgTV.SimpleEntryCertificate
#print axioms KProgTV.SimpleEntryCertificate.native_full_state

#print axioms KProgTV.SimpleEntryCertificate.proof_first_load_spill
#print axioms KProgTV.SimpleEntryCertificate.proof_second_load_spill

#print axioms KProgTV.SimpleEntryCertificate.proof_prefix_full_state

#print axioms KProgTV.SimpleEntryCertificate.entry_guest_trace

#print axioms KProgTV.SimpleEntryCertificate.entry_translation
