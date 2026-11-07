import KProgFormal.Reference.X86Path
import BPFPlatform
import PrivateSpills

set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleX86
open KProgFormal.Reference
-- Exact native and accepted virtual B bytes from the b61f291a8 service capture.
def native : Array Byte := #[0x48,0x8b,0xf,0x48,0x8b,0x57,0x8,0x48,0x89,0xce,0x31,0xc0,0x48,0x39,0xd6,0x77,0x2b,0x48,0x8d,0x7e,0x8,0x48,0x39,0xd7,0x77,0x22,0x48,0x83,0xc6,0x48,0x48,0x39,0xd6,0x77,0x19,0x66,0xc7,0x1,0x4e,0x61,0xc6,0x41,0x2,0xbc,0xc7,0x41,0x3,0x0,0x0,0x0,0x0,0xc6,0x41,0x7,0x0,0xb8,0x2,0x0,0x0,0x0]
def proof : Array Byte := #[0x61,0x12,0x0,0x0,0x0,0x0,0x0,0x0,0x7b,0x2a,0xd8,0xff,0x0,0x0,0x0,0x0,0x61,0x11,0x4,0x0,0x0,0x0,0x0,0x0,0x7b,0x1a,0xe0,0xff,0x0,0x0,0x0,0x0,0xb4,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x7a,0xa,0xe8,0xff,0x0,0x0,0x0,0x0,0x7a,0xa,0xf0,0xff,0x0,0x0,0x0,0x0,0x62,0xa,0xf8,0xff,0x0,0x0,0x0,0x0,0xb7,0x90,0x1,0x0,0x2,0x0,0x0,0x0,0x79,0xa2,0xd8,0xff,0x0,0x0,0x0,0x0,0x79,0xa3,0xe0,0xff,0x0,0x0,0x0,0x0,0x2d,0x32,0x16,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0x8,0x0,0x0,0x0,0xbf,0x25,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0x5,0x0,0x0,0x48,0x0,0x0,0x0,0x2d,0x35,0x12,0x0,0x0,0x0,0x0,0x0,0xf,0x24,0x0,0x0,0x0,0x0,0x0,0x0,0x2d,0x34,0x10,0x0,0x0,0x0,0x0,0x0,0xb7,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0x4e,0x61,0x0,0x0,0x6b,0x43,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x2,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x4,0x0,0x0,0xbc,0x0,0x0,0x0,0x73,0x43,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x3,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x63,0x13,0x0,0x0,0x0,0x0,0x0,0x0,0xb7,0x3,0x0,0x0,0x7,0x0,0x0,0x0,0xf,0x23,0x0,0x0,0x0,0x0,0x0,0x0,0x73,0x13,0x0,0x0,0x0,0x0,0x0,0x0,0xb4,0x1,0x0,0x0,0x2,0x0,0x0,0x0,0xbc,0x10,0x0,0x0,0x0,0x0,0x0,0x0,0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x95,0x0,0x0,0x0,0x0,0x0,0x0,0x0]

theorem native_size : native.size = 60 := rfl
theorem proof_size : proof.size = 296 := rfl

theorem native_decode0 (s : X86.State) :
    X86.decode (native.extract 0 3) s = .ok
      (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc + 3)) := by
  have bytes : native.extract 0 3 = #[0x48,0x8b,0x0f] := by decide
  rw [bytes]
  exact X86.decode_mov_rcx_rdi s

theorem virtual_decode0 : BPF.decode proof 0 = .ok ⟨0x61,2,1,0,0⟩ := rfl

-- Kernel XDP conversion is explicit platform metadata, not an ISA rewrite.
-- Its actual runtime correspondence remains a kernel/platform trust obligation.
def physical0 : Array Byte := #[0x79,0x12,0,0,0,0,0,0]
def externals : BPF.Environment where
  immediate := fun _ _ _ => .error "no immediate in entry load"
  helperCall := fun _ _ => .error "no helper in entry load"
  helper := fun _ _ _ => .error "no helper in entry load"

def nativeAfter (s : X86.State) (value : Word) : X86.State :=
  { s with gpr := fun r => if r = 1 then value else s.gpr r, pc := s.pc + 3 }

theorem native_load (s : X86.State) (value : Word) (event : Event)
    (read : readMemory s.memory (s.gpr 7) 8 = .ok (value,event)) :
    X86.step (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc+3)) s =
      ⟨nativeAfter s value, [event], none⟩ := by
  simp +decide [X86.step, X86.moveStep, X86.scalarRead, X86.readSource, read,
    X86.scalarWrite, X86.scalarWriteValue, X86.RegisterSlice.reg,
    X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes, nativeAfter]

theorem proof_load (s : BPF.State) (value : Word) (event : Event)
    (active : s.halted = false) (position : s.pc = 0)
    (read : readMemory s.memory (s.regs 1) 8 = .ok (value,event)) :
    BPF.step externals physical0 s =
      .ok ⟨{ BPF.setReg s 2 value with pc := 1 }, [event], none⟩ := by
  simp +decide [BPF.step, active, position, physical0, BPF.decode,
    BPF.execute, BPF.load, read, BPF.setReg, littleEndian,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]


def expansion0 : BPFPlatform.Expansion where
  original := ⟨0x61,2,1,0,0⟩
  bytes := physical0
  positions := fun _ => [0]

def physical2 : Array Byte := #[0x79,0x11,8,0,0,0,0,0]
def expansion2 : BPFPlatform.Expansion where
  original := ⟨0x61,1,1,4,0⟩
  bytes := physical2
  positions := fun _ => [0]

def platform : BPFPlatform.Environment where
  bpf := externals
  access := fun pc _ => .ok (if pc = 0 then some expansion0 else if pc = 2 then some expansion2 else none)

theorem platform_load (s : BPF.State) (value : Word) (event : Event)
    (active : s.halted = false) (position : s.pc = 0)
    (read : readMemory s.memory (s.regs 1) 8 = .ok (value,event)) :
    BPFPlatform.step platform proof s =
      .ok ⟨{ BPF.setReg s 2 value with pc := 1 }, [event], none⟩ := by
  simp +decide [BPFPlatform.step, platform, active, position, virtual_decode0,
    BPFPlatform.expand, expansion0, BPFPath.evaluate, physical0, BPF.decode, proof,
    BPF.execute, BPF.load, BPF.setReg, read, littleEndian,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]


/-- Real byte-decoded native execution, not an assumed instruction slice. -/
theorem native_entry_execution (s : X86.State) (value : Word) (event : Event)
    (position : s.pc = 0)
    (read : readMemory s.memory (s.gpr 7) 8 = .ok (value,event)) :
    X86Path.Execution 0 native s [event] (nativeAfter s value) := by
  have decoded : X86Path.decodeAt 0 native ⟨0,3⟩ s = .ok
      (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc+3)) := by
    simp +decide [X86Path.decodeAt, position, native_size, native_decode0,
      X86Path.fallthrough, X86.Instruction.fallthrough,
      Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  have actual := X86Path.Execution.next ⟨0,3⟩ _ decoded
    (X86Path.Execution.refl (X86.step
      (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc+3)) s).state)
  rw [native_load s value event read] at actual
  simpa using actual

/-- First captured instruction: both complete successor states and exactly
one identical memory event. Context conversion is an explicit platform input;
this theorem does not erase a spill or assume a later branch/return. -/
theorem entry_load_correspondence (n : X86.State) (p : BPF.State)
    (value : Word) (event : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
    (read : readMemory p.memory (p.regs 1) 8 = .ok (value,event)) :
    X86Path.Execution 0 native n [event] (nativeAfter n value) ∧
    BPFPlatform.step platform proof p =
      .ok ⟨{ BPF.setReg p 2 value with pc := 1 }, [event], none⟩ ∧
    (nativeAfter n value).gpr 1 = ({ BPF.setReg p 2 value with pc := 1 } : BPF.State).regs 2 ∧
    (nativeAfter n value).memory = ({ BPF.setReg p 2 value with pc := 1 } : BPF.State).memory := by
  have nativeRead : readMemory n.memory (n.gpr 7) 8 = .ok (value,event) := by
    simpa [memory, context] using read
  exact ⟨native_entry_execution n value event nativePC nativeRead,
    platform_load p value event active proofPC read,
    by simp [nativeAfter, BPF.setReg], by simpa [nativeAfter, BPF.setReg] using memory⟩


theorem native_decode3 (s : X86.State) :
    X86.decode (native.extract 3 7) s = .ok
      (.move .w64 (.register (.low 2)) (.memory (s.gpr 7 + (8#64))) (s.pc + 4)) := by
  have bytes : native.extract 3 7 = #[0x48,0x8b,0x57,0x08] := by decide
  rw [bytes]
  exact X86.decode_mov_rdx_rdi8 s

def nativeAfterSecond (s : X86.State) (value : Word) : X86.State :=
  { s with gpr := fun r => if r = 2 then value else s.gpr r, pc := s.pc + 4 }

theorem native_second_load (s : X86.State) (value : Word) (event : Event)
    (read : readMemory s.memory (s.gpr 7 + (8#64)) 8 = .ok (value,event)) :
    X86.step (.move .w64 (.register (.low 2)) (.memory (s.gpr 7+ (8#64))) (s.pc+4)) s =
      ⟨nativeAfterSecond s value, [event], none⟩ := by
  simp +decide [X86.step, X86.moveStep, X86.scalarRead, X86.readSource, read,
    X86.scalarWrite, X86.scalarWriteValue, X86.RegisterSlice.reg,
    X86.RegisterSlice.shift, X86.ScalarWidth.bits, X86.ScalarWidth.bytes, nativeAfterSecond]

theorem platform_second_load (s : BPF.State) (value : Word) (event : Event)
    (active : s.halted = false) (position : s.pc = 2)
    (read : readMemory s.memory (s.regs 1 + (8#64)) 8 = .ok (value,event)) :
    BPFPlatform.step platform proof s =
      .ok ⟨{ BPF.setReg s 1 value with pc := 3 }, [event], none⟩ := by
  simp +decide [BPFPlatform.step, platform, active, position,
    BPFPlatform.expand, expansion2, BPFPath.evaluate, physical2, BPF.decode, proof,
    BPF.execute, BPF.load, BPF.setReg, read, littleEndian,
    Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

-- Existing two-slot private-memory model shifted to this compiler's slots.
def spillFrame (p : BPF.State) : Word := p.regs 10 - (24#64)

theorem spill_address (frame : Word) :
    frame - (40#64) = (frame - (24#64)) - (16#64) := by
  unfold Word at *
  bv_decide

def afterSpill (p : BPF.State) (pointer : Word) : BPF.State :=
  { BPF.setReg p 2 pointer with
    pc := 2
    memory := storeMemory p.memory (p.regs 10 - (40#64)) pointer 8 }

theorem platform_spill (p : BPF.State) (pointer : Word)
    (active : p.halted = false) (position : p.pc = 0)
    (write : permitted p.memory.writable (p.regs 10 - (40#64)) 8 = true) :
    BPFPlatform.step platform proof { BPF.setReg p 2 pointer with pc := 1 } =
      .ok ⟨afterSpill p pointer,
        [.memory .write (p.regs 10 - (40#64)) (valueBytes pointer 8) true], none⟩ := by
  have neg40 (v : Word) : v + (18446744073709551576#64) = v - (40#64) := by
    change v + -(40#64) = v - (40#64)
    exact BitVec.add_neg_eq_sub
  simp +decide [BPFPlatform.step, platform, active, position, proof, BPF.decode,
    BPF.execute, BPF.store, BPF.setReg, afterSpill, neg40, writeMemory, write,
    littleEndian, Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem spill_preserves_guest (p : BPF.State) (pointer : Word) :
    PrivateSpills.AgreesOutside (spillFrame p) p.memory (afterSpill p pointer).memory := by
  refine ⟨rfl,rfl,?_⟩
  intro address outside
  have untouched : ¬ (address - (p.regs 10 - (40#64))).toNat < 8 := by
    rw [spill_address]
    simp only [PrivateSpills.privateByte, spillFrame] at outside
    omega
  simp only [afterSpill, storeMemory, untouched, ite_false]
  trivial

-- Second guest read is derived from the actual spill, not supplied as a
-- post-spill value premise. Disjointness covers every byte, including wrap.
theorem second_read_after_spill (p : BPF.State) (pointer limit : Word) (event : Event)
    (read : readMemory p.memory (p.regs 1 + (8#64)) 8 = .ok (limit,event))
    (guest : ∀ i < 8, ¬ PrivateSpills.privateByte (spillFrame p)
      (p.regs 1 + (8#64) + BitVec.ofNat 64 i)) :
    readMemory (afterSpill p pointer).memory ((afterSpill p pointer).regs 1 + (8#64)) 8 =
      .ok (limit,event) := by
  have same := PrivateSpills.guest_reads_preserved (spillFrame p) (p.regs 1+ (8#64)) 8
    p.memory (afterSpill p pointer).memory (spill_preserves_guest p pointer) guest
  simpa [afterSpill, BPF.setReg] using same.symm.trans read


def nativePrefixFinal (n : X86.State) (pointer limit : Word) : X86.State :=
  nativeAfterSecond (nativeAfter n pointer) limit

theorem native_two_loads (n : X86.State) (pointer limit : Word) (first second : Event)
    (position : n.pc = 0)
    (read0 : readMemory n.memory (n.gpr 7) 8 = .ok (pointer,first))
    (read1 : readMemory n.memory (n.gpr 7 + (8#64)) 8 = .ok (limit,second)) :
    X86Path.Execution 0 native n [first,second] (nativePrefixFinal n pointer limit) := by
  let middle := nativeAfter n pointer
  have firstDecoded : X86Path.decodeAt 0 native ⟨0,3⟩ n = .ok
      (.move .w64 (.register (.low 1)) (.memory (n.gpr 7)) (n.pc+3)) := by
    simp +decide [X86Path.decodeAt, position, native_size, native_decode0,
      X86Path.fallthrough, X86.Instruction.fallthrough,
      Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  have secondDecoded : X86Path.decodeAt 0 native ⟨3,4⟩ middle = .ok
      (.move .w64 (.register (.low 2)) (.memory (middle.gpr 7 + (8#64))) (middle.pc+4)) := by
    simp +decide [X86Path.decodeAt, middle, nativeAfter, position, native_size,
      native_decode3, X86Path.fallthrough, X86.Instruction.fallthrough,
      Except.bind, Except.pure, Bind.bind, Pure.pure, Except.instMonad]
  have readMiddle : readMemory middle.memory (middle.gpr 7 + (8#64)) 8 = .ok (limit,second) := by
    simpa +decide [middle, nativeAfter] using read1
  have suffix := X86Path.Execution.next ⟨3,4⟩ _ secondDecoded
    (X86Path.Execution.refl (X86.step
      (.move .w64 (.register (.low 2)) (.memory (middle.gpr 7 + (8#64))) (middle.pc+4)) middle).state)
  rw [native_second_load middle limit second readMiddle] at suffix
  have tail : X86Path.Execution 0 native
      (X86.step (.move .w64 (.register (.low 1)) (.memory (n.gpr 7)) (n.pc+3)) n).state
      [second] (nativePrefixFinal n pointer limit) := by
    rw [native_load n pointer first read0]
    simpa [nativePrefixFinal, middle] using suffix
  have complete := X86Path.Execution.next ⟨0,3⟩ _ firstDecoded tail
  rw [native_load n pointer first read0] at complete
  simpa using complete

def platformInstructionStep : BlockStep BPF.State := fun before events after =>
  ∃ result, BPFPlatform.step platform proof before = .ok result ∧
    result.events = events ∧ result.state = after

def proofPrefixFinal (p : BPF.State) (pointer limit : Word) : BPF.State :=
  { BPF.setReg (afterSpill p pointer) 1 limit with pc := 3 }

def prefixEvents (p : BPF.State) (pointer : Word) (first second : Event) : List Event :=
  [first, .memory .write (p.regs 10 - (40#64)) (valueBytes pointer 8) true, second]

theorem proof_two_loads_spill (p : BPF.State) (pointer limit : Word) (first second : Event)
    (position : p.pc = 0) (active : p.halted = false)
    (read0 : readMemory p.memory (p.regs 1) 8 = .ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1 + (8#64)) 8 = .ok (limit,second))
    (write : permitted p.memory.writable (p.regs 10 - (40#64)) 8 = true)
    (guest : ∀ i < 8, ¬ PrivateSpills.privateByte (spillFrame p)
      (p.regs 1 + (8#64) + BitVec.ofNat 64 i)) :
    Execution platformInstructionStep p (prefixEvents p pointer first second)
      (proofPrefixFinal p pointer limit) := by
  have thirdRead := second_read_after_spill p pointer limit second read1 guest
  have third := platform_second_load (afterSpill p pointer) limit second
    (by simpa [afterSpill, BPF.setReg] using active) rfl thirdRead
  have step0 : platformInstructionStep p [first] { BPF.setReg p 2 pointer with pc := 1 } :=
    ⟨_, platform_load p pointer first active position read0, rfl, rfl⟩
  have step1 : platformInstructionStep { BPF.setReg p 2 pointer with pc := 1 }
      [.memory .write (p.regs 10 - (40#64)) (valueBytes pointer 8) true] (afterSpill p pointer) :=
    ⟨_, platform_spill p pointer active position write, rfl, rfl⟩
  have step2 : platformInstructionStep (afterSpill p pointer) [second] (proofPrefixFinal p pointer limit) :=
    ⟨_,third,rfl,rfl⟩
  simpa [prefixEvents] using Execution.next step0
    (Execution.next step1 (Execution.next step2 (Execution.refl _)))

theorem prefix_event_projection (p : BPF.State) (pointer limit : Word) (first second : Event)
    (read0 : readMemory p.memory (p.regs 1) 8 = .ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1 + (8#64)) 8 = .ok (limit,second))
    (guest0 : ¬ PrivateSpills.privateByte (spillFrame p) (p.regs 1))
    (guest1 : ¬ PrivateSpills.privateByte (spillFrame p) (p.regs 1 + (8#64))) :
    (prefixEvents p pointer first second).filterMap (PrivateSpills.projectEvent (spillFrame p)) = [first,second] := by
  have firstKept := PrivateSpills.read_event_retained p.memory (spillFrame p) _ _ _ first read0 guest0
  have secondKept := PrivateSpills.read_event_retained p.memory (spillFrame p) _ _ _ second read1 guest1
  have slot : p.regs 10 - (40#64) = spillFrame p - (16#64) := by
    exact spill_address _
  have gone : PrivateSpills.projectEvent (spillFrame p)
      (.memory .write (p.regs 10 - (40#64)) (valueBytes pointer 8) true) = none := by
    simp [PrivateSpills.projectEvent, slot, valueBytes]
  simp [prefixEvents, List.filterMap_cons, List.filterMap_nil, firstKept, secondKept, gone]


/-- Actual two-native-load / three-BPF-step prefix, including the real spill.
The only erased event is proved private; all resulting fields are fixed by
complete states, and guest memory agreement is established, not assumed. -/
theorem two_load_prefix_correspondence (n : X86.State) (p : BPF.State)
    (pointer limit : Word) (first second : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
    (read0 : readMemory p.memory (p.regs 1) 8 = .ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1 + (8#64)) 8 = .ok (limit,second))
    (write : permitted p.memory.writable (p.regs 10 - (40#64)) 8 = true)
    (guest0 : ¬ PrivateSpills.privateByte (spillFrame p) (p.regs 1))
    (guest1 : ∀ i < 8, ¬ PrivateSpills.privateByte (spillFrame p)
      (p.regs 1 + (8#64) + BitVec.ofNat 64 i)) :
    X86Path.Execution 0 native n [first,second] (nativePrefixFinal n pointer limit) ∧
    Execution platformInstructionStep p (prefixEvents p pointer first second)
      (proofPrefixFinal p pointer limit) ∧
    (prefixEvents p pointer first second).filterMap (PrivateSpills.projectEvent (spillFrame p)) = [first,second] ∧
    (nativePrefixFinal n pointer limit).gpr 1 = (proofPrefixFinal p pointer limit).regs 2 ∧
    (nativePrefixFinal n pointer limit).gpr 2 = (proofPrefixFinal p pointer limit).regs 1 ∧
    PrivateSpills.AgreesOutside (spillFrame p) (nativePrefixFinal n pointer limit).memory
      (proofPrefixFinal p pointer limit).memory := by
  have nativeRead0 : readMemory n.memory (n.gpr 7) 8 = .ok (pointer,first) := by
    simpa [memory,context] using read0
  have nativeRead1 : readMemory n.memory (n.gpr 7+(8#64)) 8 = .ok (limit,second) := by
    simpa [memory,context] using read1
  have guest1Base : ¬ PrivateSpills.privateByte (spillFrame p) (p.regs 1+(8#64)) := by
    simpa using guest1 0 (by decide)
  refine ⟨native_two_loads n pointer limit first second nativePC nativeRead0 nativeRead1,
    proof_two_loads_spill p pointer limit first second proofPC active read0 read1 write guest1,
    prefix_event_projection p pointer limit first second read0 read1 guest0 guest1Base, ?_, ?_, ?_⟩
  · simp +decide [nativePrefixFinal, nativeAfterSecond, nativeAfter, proofPrefixFinal, afterSpill, BPF.setReg]
  · simp +decide [nativePrefixFinal, nativeAfterSecond, nativeAfter, proofPrefixFinal, afterSpill, BPF.setReg]
  · simpa [nativePrefixFinal, nativeAfterSecond, nativeAfter, proofPrefixFinal, BPF.setReg, memory]
      using spill_preserves_guest p pointer


/-- The actual earlier 8B stack slot is disjoint from any later slot8..40
bytes above it, even if the architectural addresses wrap at zero. -/
theorem earlier_slot_apart (frame earlier later index : Word)
    (small : index < (8#64)) (distance : (8#64) ≤ earlier-later)
    (bounded : earlier-later ≤ (40#64)) :
    ¬ ((frame-earlier+index)-(frame-later)) < (8#64) := by
  unfold Word at *
  bv_decide

theorem earlier_read_preserved (m : Memory) (frame earlier later value : Word)
    (written : Nat) (width : written ≤ 8)
    (distance : (8#64) ≤ earlier-later) (bounded : earlier-later ≤ (40#64)) :
    readMemory (storeMemory m (frame-later) value written) (frame-earlier) 8 =
      readMemory m (frame-earlier) 8 := by
  apply PrivateSpills.read_disjoint_store
  intro i small
  have fits : i < 2^64 := by omega
  have smallWord : BitVec.ofNat 64 i < (8#64) := by
    simp only [BitVec.lt_def, BitVec.toNat_ofNat, Nat.mod_eq_of_lt fits]
    exact small
  have outside := earlier_slot_apart frame earlier later (BitVec.ofNat 64 i) smallWord distance bounded
  change ¬ ((frame-earlier+BitVec.ofNat 64 i)-(frame-later)).toNat < 8 at outside
  omega

def valueMemory (m : Memory) (frame limit : Word) : Memory :=
  storeMemory m (frame-(32#64)) limit 8

def initializedMemory (m : Memory) (frame limit : Word) : Memory :=
  storeMemory (storeMemory (storeMemory (valueMemory m frame limit)
    (frame-(24#64)) (0#64) 8) (frame-(16#64)) (0#64) 8) (frame-(8#64)) (0#64) 4

theorem initialized_pointer_read (m : Memory) (frame pointer limit : Word) (event : Event)
    (read : readMemory m (frame-(40#64)) 8 = .ok (pointer,event)) :
    readMemory (initializedMemory m frame limit) (frame-(40#64)) 8 = .ok (pointer,event) := by
  unfold initializedMemory valueMemory
  rw [earlier_read_preserved _ frame (40#64) (8#64) (0#64) 4 (by decide) (by decide) (by decide)]
  rw [earlier_read_preserved _ frame (40#64) (16#64) (0#64) 8 (by decide) (by decide) (by decide)]
  rw [earlier_read_preserved _ frame (40#64) (24#64) (0#64) 8 (by decide) (by decide) (by decide)]
  rw [earlier_read_preserved _ frame (40#64) (32#64) limit 8 (by decide) (by decide) (by decide)]
  exact read

theorem initialized_limit_read (m : Memory) (frame limit : Word)
    (permission : permitted m.readable (frame-(32#64)) 8 = true) :
    readMemory (initializedMemory m frame limit) (frame-(32#64)) 8 =
      .ok (limit,.memory .read (frame-(32#64)) (valueBytes limit 8) true) := by
  unfold initializedMemory valueMemory
  rw [earlier_read_preserved _ frame (32#64) (8#64) (0#64) 4 (by decide) (by decide) (by decide)]
  rw [earlier_read_preserved _ frame (32#64) (16#64) (0#64) 8 (by decide) (by decide) (by decide)]
  rw [earlier_read_preserved _ frame (32#64) (24#64) (0#64) 8 (by decide) (by decide) (by decide)]
  exact PrivateSpills.spill_read m (frame-(32#64)) limit permission

def initializationFinal (p : BPF.State) (pointer limit stack : Word) : BPF.State :=
  { BPF.setReg (BPF.setReg (BPF.setReg (BPF.setReg p 1 (0#64)) 0 stack) 2 pointer) 3 limit with
    memory := initializedMemory p.memory (p.regs 10) limit
    pc := 11 }

def initializationEvents (frame pointer limit : Word) : List Event :=
  [.memory .write (frame-(32#64)) (valueBytes limit 8) true,
   .memory .write (frame-(24#64)) (valueBytes (0#64) 8) true,
   .memory .write (frame-(16#64)) (valueBytes (0#64) 8) true,
   .memory .write (frame-(8#64)) (valueBytes (0#64) 4) true,
   .memory .read (frame-(40#64)) (valueBytes pointer 8) true,
   .memory .read (frame-(32#64)) (valueBytes limit 8) true]

theorem virtual_decode3 : BPF.decode proof 3 = .ok ⟨0x7b,10,1,0xffe0,0⟩ := rfl
theorem virtual_decode4 : BPF.decode proof 4 = .ok ⟨0xb4,1,0,0,0⟩ := rfl
theorem virtual_decode5 : BPF.decode proof 5 = .ok ⟨0x7a,10,0,0xffe8,0⟩ := rfl
theorem virtual_decode6 : BPF.decode proof 6 = .ok ⟨0x7a,10,0,0xfff0,0⟩ := rfl
theorem virtual_decode7 : BPF.decode proof 7 = .ok ⟨0x62,10,0,0xfff8,0⟩ := rfl
theorem virtual_decode8 : BPF.decode proof 8 = .ok ⟨0xb7,0,9,1,2⟩ := rfl
theorem virtual_decode9 : BPF.decode proof 9 = .ok ⟨0x79,2,10,0xffd8,0⟩ := rfl
theorem virtual_decode10 : BPF.decode proof 10 = .ok ⟨0x79,3,10,0xffe0,0⟩ := rfl

/-- Exact captured B steps3..10, retaining every initializer/reload event.
The native stack value is a bound environment input, never invented zero. -/
theorem initialization_block (env : BPF.Environment) (p : BPF.State) (pointer limit stack : Word)
    (position : p.pc = 3) (active : p.halted = false) (savedLimit : p.regs 1 = limit)
    (nativeStack : env.nativeInput .stackPointer = .ok stack)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8 = true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8 = true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8 = true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4 = true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8 = true)
    (pointerRead : readMemory p.memory (p.regs 10-(40#64)) 8 =
      .ok (pointer,.memory .read (p.regs 10-(40#64)) (valueBytes pointer 8) true)) :
    BPFPath.evaluate env proof [3,4,5,6,7,8,9,10] p =
      .ok ⟨initializationFinal p pointer limit stack,
        initializationEvents (p.regs 10) pointer limit, none⟩ := by
  have pointerAfter := initialized_pointer_read p.memory (p.regs 10) pointer limit _ pointerRead
  have limitAfter := initialized_limit_read p.memory (p.regs 10) limit read32
  simp only [initializedMemory, valueMemory] at pointerAfter limitAfter
  have neg8 (v : Word) : v + (18446744073709551608#64) = v - (8#64) := by
    change v + -(8#64) = v - (8#64)
    exact BitVec.add_neg_eq_sub
  have neg16 (v : Word) : v + (18446744073709551600#64) = v - (16#64) := by
    change v + -(16#64) = v - (16#64)
    exact BitVec.add_neg_eq_sub
  have neg24 (v : Word) : v + (18446744073709551592#64) = v - (24#64) := by
    change v + -(24#64) = v - (24#64)
    exact BitVec.add_neg_eq_sub
  have neg32 (v : Word) : v + (18446744073709551584#64) = v - (32#64) := by
    change v + -(32#64) = v - (32#64)
    exact BitVec.add_neg_eq_sub
  have neg40 (v : Word) : v + (18446744073709551576#64) = v - (40#64) := by
    change v + -(40#64) = v - (40#64)
    exact BitVec.add_neg_eq_sub
  simp +decide [BPFPath.evaluate, virtual_decode3, virtual_decode4, virtual_decode5,
    virtual_decode6, virtual_decode7, virtual_decode8, virtual_decode9, virtual_decode10,
    BPF.execute, BPF.store, BPF.load,
    BPF.source, BPF.alu, BPF.setReg, position, active, savedLimit, nativeStack,
    initializedMemory, valueMemory, initializationFinal, initializationEvents,
    writeMemory, write32, write24, write16, write8, pointerAfter, limitAfter,
    neg8, neg16, neg24, neg32, neg40, littleEndian, Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]


/-- The pointer reload premise of the generic initializer is obtained from
this captured prefix's real first spill. No post-spill word is assumed. -/
theorem initialization_after_context_prefix (env : BPF.Environment) (p : BPF.State)
    (pointer limit stack : Word) (active : p.halted = false)
    (nativeStack : env.nativeInput .stackPointer = .ok stack)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8 = true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8 = true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8 = true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4 = true)
    (read40 : permitted p.memory.readable (p.regs 10-(40#64)) 8 = true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8 = true) :
    Execution (BPFPath.instructionStep env proof) (proofPrefixFinal p pointer limit)
      (initializationEvents (p.regs 10) pointer limit)
      (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack) := by
  let q := proofPrefixFinal p pointer limit
  have pointerRead : readMemory q.memory (q.regs 10-(40#64)) 8 =
      .ok (pointer,.memory .read (q.regs 10-(40#64)) (valueBytes pointer 8) true) := by
    simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using
      PrivateSpills.spill_read p.memory (p.regs 10-(40#64)) pointer read40
  have block := initialization_block env q pointer limit stack rfl
    (by simpa [q,proofPrefixFinal,afterSpill,BPF.setReg] using active)
    (by simp +decide [q,proofPrefixFinal,BPF.setReg]) nativeStack
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write32)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write24)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write16)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write8)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using read32) pointerRead
  have run := BPFPath.evaluate_sound env proof [3,4,5,6,7,8,9,10] q _ block
  simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using run


/-- Explicit environment for the initialized proof. The previous fail-closed
platform/externals and every earlier theorem retain their original contract. -/
def initializedPlatform (env : BPF.Environment) : BPFPlatform.Environment :=
  { platform with bpf := env }

def initializedInstructionStep (env : BPF.Environment) : BlockStep BPF.State :=
  fun before events after => ∃ result,
    BPFPlatform.step (initializedPlatform env) proof before = .ok result ∧
      result.events = events ∧ result.state = after

/-- These actual entry instructions observe no environment inputs, including
on a fault. This is equality of full transitions for arbitrary states. -/
theorem entry_environment_independent (env : BPF.Environment) (s : BPF.State)
    (entry : s.pc = 0 ∨ s.pc = 1 ∨ s.pc = 2) :
    BPFPlatform.step (initializedPlatform env) proof s = BPFPlatform.step platform proof s := by
  rcases entry with first | spill | second
  all_goals
    simp +decide [initializedPlatform, BPFPlatform.step, platform, *,
      BPFPlatform.expand, expansion0, expansion2, BPFPath.evaluate,
      physical0, physical2, BPF.decode, proof, BPF.execute,
      littleEndian, Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem initialized_ordinary_step (env : BPF.Environment) (s : BPF.State)
    (notFirst : s.pc ≠ 0) (notSecond : s.pc ≠ 2) :
    BPFPlatform.step (initializedPlatform env) proof s = BPF.step env proof s := by
  cases active : s.halted <;> by_cases negative : s.pc < 0 <;>
    cases decoded : BPF.decode proof s.pc.toNat <;>
    simp [initializedPlatform, BPFPlatform.step, platform, BPF.step,
      notFirst, notSecond, active, negative, decoded,
      Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad]

theorem initialized_context_prefix (env : BPF.Environment) (p : BPF.State)
    (pointer limit : Word) (first second : Event)
    (position : p.pc = 0) (active : p.halted = false)
    (read0 : readMemory p.memory (p.regs 1) 8 = .ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1 + (8#64)) 8 = .ok (limit,second))
    (write : permitted p.memory.writable (p.regs 10-(40#64)) 8 = true)
    (guest : ∀ i < 8, ¬ PrivateSpills.privateByte (spillFrame p)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    Execution (initializedInstructionStep env) p (prefixEvents p pointer first second)
      (proofPrefixFinal p pointer limit) := by
  have thirdRead := second_read_after_spill p pointer limit second read1 guest
  have step0 : initializedInstructionStep env p [first] { BPF.setReg p 2 pointer with pc := 1 } := by
    refine ⟨⟨{ BPF.setReg p 2 pointer with pc := 1 },[first],none⟩,?_,rfl,rfl⟩
    rw [entry_environment_independent env p (Or.inl position)]
    exact platform_load p pointer first active position read0
  have step1 : initializedInstructionStep env { BPF.setReg p 2 pointer with pc := 1 }
      [.memory .write (p.regs 10-(40#64)) (valueBytes pointer 8) true] (afterSpill p pointer) := by
    refine ⟨⟨afterSpill p pointer,
      [.memory .write (p.regs 10-(40#64)) (valueBytes pointer 8) true],none⟩,?_,rfl,rfl⟩
    rw [entry_environment_independent env _ (Or.inr (Or.inl rfl))]
    exact platform_spill p pointer active position write
  have step2 : initializedInstructionStep env (afterSpill p pointer) [second]
      (proofPrefixFinal p pointer limit) := by
    refine ⟨⟨proofPrefixFinal p pointer limit,[second],none⟩,?_,rfl,rfl⟩
    rw [entry_environment_independent env _ (Or.inr (Or.inr rfl))]
    exact platform_second_load (afterSpill p pointer) limit second
      (by simpa [afterSpill,BPF.setReg] using active) rfl thirdRead
  simpa [prefixEvents] using Execution.next step0
    (Execution.next step1 (Execution.next step2 (Execution.refl _)))

/-- Lift the exact initializer witness to the same platform used at entry;
no path position is changed or branch successor supplied. -/
theorem initialized_body (env : BPF.Environment) (p : BPF.State) (pointer limit stack : Word)
    (position : p.pc = 3) (active : p.halted = false) (savedLimit : p.regs 1 = limit)
    (nativeStack : env.nativeInput .stackPointer = .ok stack)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8 = true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8 = true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8 = true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4 = true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8 = true)
    (pointerRead : readMemory p.memory (p.regs 10-(40#64)) 8 =
      .ok (pointer,.memory .read (p.regs 10-(40#64)) (valueBytes pointer 8) true)) :
    Execution (initializedInstructionStep env) p (initializationEvents (p.regs 10) pointer limit)
      (initializationFinal p pointer limit stack) := by
  have block := initialization_block env p pointer limit stack position active savedLimit nativeStack
    write32 write24 write16 write8 read32 pointerRead
  exact BPFPath.evaluate_execution_transport env proof id (initializedInstructionStep env)
    (fun pc => 3 ≤ pc ∧ pc ≤ 10)
    (by
      intro s pc bound atPosition result actual
      refine ⟨result,?_,rfl,rfl⟩
      change BPFPlatform.step (initializedPlatform env) proof s = .ok result
      rw [initialized_ordinary_step env s (by omega) (by omega)]
      exact actual)
    [3,4,5,6,7,8,9,10] (by intro pc inside; simp at inside; omega) p _ block

/-- One environment, one platform and one actual execution from entry to
pc11. Every initializer/spill/reload access remains in the ordered trace. -/
theorem initialized_complete_prefix (env : BPF.Environment) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (position : p.pc = 0) (active : p.halted = false)
    (nativeStack : env.nativeInput .stackPointer = .ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8 = .ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8 = .ok (limit,second))
    (write40 : permitted p.memory.writable (p.regs 10-(40#64)) 8 = true)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8 = true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8 = true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8 = true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4 = true)
    (read40 : permitted p.memory.readable (p.regs 10-(40#64)) 8 = true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8 = true)
    (guest : ∀ i < 8, ¬ PrivateSpills.privateByte (spillFrame p)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    Execution (initializedInstructionStep env) p
      (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit)
      (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack) := by
  have entry := initialized_context_prefix env p pointer limit first second
    position active read0 read1 write40 guest
  let q := proofPrefixFinal p pointer limit
  have pointerRead : readMemory q.memory (q.regs 10-(40#64)) 8 =
      .ok (pointer,.memory .read (q.regs 10-(40#64)) (valueBytes pointer 8) true) := by
    simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using
      PrivateSpills.spill_read p.memory (p.regs 10-(40#64)) pointer read40
  have body := initialized_body env q pointer limit stack rfl
    (by simpa [q,proofPrefixFinal,afterSpill,BPF.setReg] using active)
    (by simp +decide [q,proofPrefixFinal,BPF.setReg]) nativeStack
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write32)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write24)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write16)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using write8)
    (by simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using read32) pointerRead
  simpa +decide [q,proofPrefixFinal,afterSpill,BPF.setReg] using entry.append body

end KProgTV.TrustedSimpleX86
#print axioms KProgTV.TrustedSimpleX86.native_decode0
#print axioms KProgTV.TrustedSimpleX86.native_load
#print axioms KProgTV.TrustedSimpleX86.proof_load

#print axioms KProgTV.TrustedSimpleX86.platform_load

#print axioms KProgTV.TrustedSimpleX86.entry_load_correspondence

#print axioms KProgTV.TrustedSimpleX86.native_decode3
#print axioms KProgTV.TrustedSimpleX86.native_second_load
#print axioms KProgTV.TrustedSimpleX86.platform_second_load
#print axioms KProgTV.TrustedSimpleX86.platform_spill
#print axioms KProgTV.TrustedSimpleX86.second_read_after_spill

#print axioms KProgTV.TrustedSimpleX86.native_two_loads
#print axioms KProgTV.TrustedSimpleX86.proof_two_loads_spill
#print axioms KProgTV.TrustedSimpleX86.prefix_event_projection

#print axioms KProgTV.TrustedSimpleX86.two_load_prefix_correspondence

#print axioms KProgTV.TrustedSimpleX86.initialized_pointer_read
#print axioms KProgTV.TrustedSimpleX86.initialized_limit_read
#print axioms KProgTV.TrustedSimpleX86.initialization_block

#print axioms KProgTV.TrustedSimpleX86.initialization_after_context_prefix

#print axioms KProgTV.TrustedSimpleX86.entry_environment_independent
#print axioms KProgTV.TrustedSimpleX86.initialized_body
#print axioms KProgTV.TrustedSimpleX86.initialized_complete_prefix

#print axioms KProgTV.TrustedSimpleX86.initialized_ordinary_step
#print axioms KProgTV.TrustedSimpleX86.initialized_context_prefix
