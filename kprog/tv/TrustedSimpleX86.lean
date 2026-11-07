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


/-- Exactly the 36 initialized bytes of the captured 40-byte stack layout.
The untouched four bytes immediately below r10 are not hidden. -/
def initializationPrivateByte (frame address : Word) : Prop :=
  (address - (frame-(40#64))).toNat < 36

/-- Only the actual complete compiler slots, with their actual access sizes. -/
def initializationSlot (frame address : Word) (count : Nat) : Prop :=
  (address = frame-(40#64) ∧ count = 8) ∨
  (address = frame-(32#64) ∧ count = 8) ∨
  (address = frame-(24#64) ∧ count = 8) ∨
  (address = frame-(16#64) ∧ count = 8) ∨
  (address = frame-(8#64) ∧ count = 4)

theorem initialization_slot_covers (frame base address : Word) (count : Nat)
    (slot : initializationSlot frame base count)
    (inside : (address-base).toNat < count) : initializationPrivateByte frame address := by
  rcases slot with h | h | h | h | h
  all_goals
    rcases h with ⟨rfl,rfl⟩
    first
    | change address-(frame-_) < (8#64) at inside
    | change address-(frame-_) < (4#64) at inside
    change address-(frame-(40#64)) < (36#64)
    unfold Word at *
    bv_decide

theorem initialization_slot_bytes (frame base : Word) (count : Nat)
    (slot : initializationSlot frame base count) (i : Nat) (small : i < count) :
    initializationPrivateByte frame (base+BitVec.ofNat 64 i) := by
  apply initialization_slot_covers frame base _ count slot
  have bounded : count ≤ 8 := by rcases slot with h | h | h | h | h <;> omega
  have fits : i < 2^64 := by omega
  simpa only [PrivateSpills.plus_index_sub, BitVec.toNat_ofNat, Nat.mod_eq_of_lt fits] using small

def initializationAgreesOutside (frame : Word) (first second : Memory) : Prop :=
  first.readable = second.readable ∧ first.writable = second.writable ∧
    ∀ address, ¬ initializationPrivateByte frame address →
      first.value address = second.value address ∧
      first.initialized address = second.initialized address

/-- Actual stores preserve permissions, values and initialization outside the
precise footprint, even when the stack layout wraps around address zero. -/
theorem initialization_memory_agrees (p : BPF.State) (pointer limit stack : Word) :
    initializationAgreesOutside (p.regs 10) p.memory
      (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack).memory := by
  refine ⟨rfl,rfl,?_⟩
  intro address outside
  have apart (base : Word) (count : Nat) (slot : initializationSlot (p.regs 10) base count) :
      ¬ (address-base).toNat < count :=
    fun inside => outside (initialization_slot_covers _ _ _ _ slot inside)
  have a40 := apart (p.regs 10-(40#64)) 8 (Or.inl ⟨rfl,rfl⟩)
  have a32 := apart (p.regs 10-(32#64)) 8 (Or.inr (Or.inl ⟨rfl,rfl⟩))
  have a24 := apart (p.regs 10-(24#64)) 8 (Or.inr (Or.inr (Or.inl ⟨rfl,rfl⟩)))
  have a16 := apart (p.regs 10-(16#64)) 8 (Or.inr (Or.inr (Or.inr (Or.inl ⟨rfl,rfl⟩))))
  have a8 := apart (p.regs 10-(8#64)) 4 (Or.inr (Or.inr (Or.inr (Or.inr ⟨rfl,rfl⟩))))
  simp +decide only [initializationFinal,initializedMemory,valueMemory,proofPrefixFinal,
    afterSpill,BPF.setReg,ite_false]
  simp only [storeMemory,a40,a32,a24,a16,a8,ite_false]
  trivial

instance (frame address : Word) (count : Nat) : Decidable (initializationSlot frame address count) :=
  inferInstanceAs (Decidable ((_ ∧ _) ∨ (_ ∧ _) ∨ (_ ∧ _) ∨ (_ ∧ _) ∨ (_ ∧ _)))

def initializationProjectEvent (frame : Word) : Event → Option Event
  | event@(.memory .read address bytes _) =>
      if initializationSlot frame address bytes.length then none else some event
  | event@(.memory .write address bytes _) =>
      if initializationSlot frame address bytes.length then none else some event
  | event => some event

theorem initialization_erased_private (frame : Word) (event : Event)
    (gone : initializationProjectEvent frame event = none) :
    ∃ kind address bytes initialized,
      event = .memory kind address bytes initialized ∧
      initializationSlot frame address bytes.length ∧
      ∀ i < bytes.length, initializationPrivateByte frame (address+BitVec.ofNat 64 i) := by
  cases event with
  | memory kind address bytes initialized =>
      cases kind with
      | read =>
          simp only [initializationProjectEvent] at gone
          split at gone
          · rename_i slot
            exact ⟨.read,address,bytes,initialized,rfl,slot,
              fun i small => initialization_slot_bytes frame address bytes.length slot i small⟩
          · simp at gone
      | write =>
          simp only [initializationProjectEvent] at gone
          split at gone
          · rename_i slot
            exact ⟨.write,address,bytes,initialized,rfl,slot,
              fun i small => initialization_slot_bytes frame address bytes.length slot i small⟩
          · simp at gone
      | atomic => simp [initializationProjectEvent] at gone
  | helper => simp [initializationProjectEvent] at gone
  | fault => simp [initializationProjectEvent] at gone
  | exclusive => simp [initializationProjectEvent] at gone

theorem initialization_guest_event_retained (frame address : Word) (kind : AccessKind)
    (bytes : List Byte) (initialized : Bool) (guest : ¬ initializationPrivateByte frame address) :
    initializationProjectEvent frame (.memory kind address bytes initialized) =
      some (.memory kind address bytes initialized) := by
  have noSlot : ¬ initializationSlot frame address bytes.length := by
    intro slot
    have positive : 0 < bytes.length := by rcases slot with h | h | h | h | h <;> omega
    exact guest (by simpa using initialization_slot_bytes frame address bytes.length slot 0 positive)
  cases kind <;> simp [initializationProjectEvent,noSlot]

theorem initialization_read_retained (m : Memory) (frame address value : Word) (count : Nat) (event : Event)
    (read : readMemory m address count = .ok (value,event))
    (guest : ¬ initializationPrivateByte frame address) :
    initializationProjectEvent frame event = some event := by
  by_cases permission : permitted m.readable address count = true
  · simp only [readMemory,permission,ite_true,Except.ok.injEq,Prod.mk.injEq] at read
    rw [← read.2]
    exact initialization_guest_event_retained frame address .read _ _ guest
  · simp [readMemory,permission] at read

/-- Both actual guest reads survive; the seven real private accesses alone
are erased. Atomic/helper/fault/exclusive effects cannot be erased. -/
theorem initialization_event_projection (p : BPF.State) (pointer limit : Word) (first second : Event)
    (read0 : readMemory p.memory (p.regs 1) 8 = .ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8 = .ok (limit,second))
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1+(8#64))) :
    (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)) = [first,second] := by
  have firstKept := initialization_read_retained p.memory (p.regs 10) _ _ _ first read0 guest0
  have secondKept := initialization_read_retained p.memory (p.regs 10) _ _ _ second read1 guest1
  simp only [prefixEvents,initializationEvents,List.filterMap_append,List.filterMap_cons,List.filterMap_nil,
    firstKept,secondKept]
  simp [initializationProjectEvent,initializationSlot,valueBytes]


theorem initialization_spill_private (frame address : Word)
    (inside : PrivateSpills.privateByte (frame-(24#64)) address) :
    initializationPrivateByte frame address := by
  change address-((frame-(24#64))-(16#64)) < (16#64) at inside
  change address-(frame-(40#64)) < (36#64)
  unfold Word at *
  bv_decide

theorem initialization_untouched_top (frame offset : Word) (small : offset < (4#64)) :
    ¬ initializationPrivateByte frame (frame-(4#64)+offset) := by
  change ¬ (frame-(4#64)+offset)-(frame-(40#64)) < (36#64)
  unfold Word at *
  bv_decide

/-- Actual native bytes0..7 and actual accepted Bpc0..10, with one explicit
B environment. Every private event erased by the equality below is certified
by initialization_erased_private; resulting guest memory is derived from all
five actual stores. No later native branch, fault or whole-program TV claim. -/
theorem initialized_prefix_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
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
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ∀ i < 8, ¬ initializationPrivateByte (p.regs 10)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    X86Path.Execution 0 native n [first,second] (nativePrefixFinal n pointer limit) ∧
    Execution (initializedInstructionStep env) p
      (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit)
      (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack) ∧
    (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)) = [first,second] ∧
    (nativePrefixFinal n pointer limit).gpr 1 =
      (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack).regs 2 ∧
    (nativePrefixFinal n pointer limit).gpr 2 =
      (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack).regs 3 ∧
    initializationAgreesOutside (p.regs 10) (nativePrefixFinal n pointer limit).memory
      (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack).memory := by
  have nativeRead0 : readMemory n.memory (n.gpr 7) 8 = .ok (pointer,first) := by
    simpa [memory,context] using read0
  have nativeRead1 : readMemory n.memory (n.gpr 7+(8#64)) 8 = .ok (limit,second) := by
    simpa [memory,context] using read1
  have oldGuest : ∀ i < 8, ¬ PrivateSpills.privateByte (spillFrame p)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i) := by
    intro i small inside
    exact guest1 i small (initialization_spill_private _ _ inside)
  have guest1Base : ¬ initializationPrivateByte (p.regs 10) (p.regs 1+(8#64)) := by
    simpa using guest1 0 (by decide)
  refine ⟨native_two_loads n pointer limit first second nativePC nativeRead0 nativeRead1,
    initialized_complete_prefix env p pointer limit stack first second proofPC active nativeStack
      read0 read1 write40 write32 write24 write16 write8 read40 read32 oldGuest,
    initialization_event_projection p pointer limit first second read0 read1 guest0 guest1Base,?_,?_,?_⟩
  · simp +decide [nativePrefixFinal,nativeAfterSecond,nativeAfter,initializationFinal,BPF.setReg]
  · simp +decide [nativePrefixFinal,nativeAfterSecond,nativeAfter,initializationFinal,BPF.setReg]
  · change initializationAgreesOutside (p.regs 10) n.memory _
    rw [memory]
    exact initialization_memory_agrees p pointer limit stack


theorem native_decode7 (s : X86.State) :
    X86.decode (native.extract 7 10) s = .ok
      (.move .w64 (.register (.low 6)) (.register (.low 1)) (s.pc+3)) := by rfl

theorem native_decode10 (s : X86.State) :
    X86.decode (native.extract 10 12) s = .ok
      (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) (s.pc+2)) := by rfl

theorem native_decode12 (s : X86.State) :
    X86.decode (native.extract 12 15) s = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) (s.pc+3)) := by rfl

theorem native_decode15 (s : X86.State) :
    X86.decode (native.extract 15 17) s = .ok
      (.branch (some 7) ((s.pc+2)+(43#64)) (s.pc+2)) := by
  have bytes : native.extract 15 17 = #[0x77,0x2b] := by decide
  rw [bytes]
  exact X86.decode_ja_rel8 s (0x2b#8)


/-- The actual unsigned JA predicate following a 64-bit CMP. No assumption
about the incoming flags, including XOR's undefined AF, is required. -/
theorem compare_ja_predicate (left right old : Word) :
    X86.condition (X86.arithmeticFlags .w64 true false left right old) 7 = (left > right) := by
  simp only [X86.condition,X86.arithmeticFlags,X86.ScalarWidth.bits,X86.ScalarWidth.bytes]
  unfold Word at *
  bv_decide

/-- CMP overwrites XOR's undefined AF. Every allowed incoming AF choice
produces the same complete post-CMP flags; no undefined value is constrained. -/
theorem xor_compare_flags_choice (left right value old actualFlags : Word)
    (allowed : actualFlags &&& (0xffffffffffffffef#64) =
      X86.logicalFlags .w32 .xor value value old &&& (0xffffffffffffffef#64)) :
    X86.arithmeticFlags .w64 true false left right actualFlags =
      X86.arithmeticFlags .w64 true false left right old := by
  have preserved : actualFlags &&& (0xfffffffffffff72a : Word) = old &&& (0xfffffffffffff72a : Word) := by
    simp only [X86.logicalFlags] at allowed
    unfold Word at *
    bv_decide
  simp only [X86.arithmeticFlags,preserved]


def guardMove (s : X86.State) : X86.State :=
  { s with gpr := fun r => if r=6 then s.gpr 1 else s.gpr r, pc := 10 }

def guardZeroFlags (flags : Word) : Word := X86.logicalFlags .w32 .xor (0#64) (0#64) flags

def guardZero (s : X86.State) : X86.State :=
  { guardMove s with
    gpr := fun r => if r=0 then (0#64) else (guardMove s).gpr r
    rflags := guardZeroFlags s.rflags
    pc := 12 }

def guardCompare (s : X86.State) : X86.State :=
  { guardZero s with
    rflags := X86.arithmeticFlags .w64 true false (s.gpr 1) (s.gpr 2) (guardZeroFlags s.rflags)
    pc := 15 }

def guardFinal (s : X86.State) : X86.State :=
  { guardCompare s with pc := if s.gpr 1 > s.gpr 2 then 60 else 17 }

theorem guard_move_step (s : X86.State) (position : s.pc=7) :
    X86.step (.move .w64 (.register (.low 6)) (.register (.low 1)) 10) s =
      ⟨guardMove s,[],none⟩ := by
  simp +decide [X86.step,X86.moveStep,X86.scalarRead,X86.scalarRegisterValue,X86.scalarWrite,X86.scalarWriteValue,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
    guardMove,position]

theorem guard_zero_step (s : X86.State) :
    X86.step (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12) (guardMove s) =
      ⟨guardZero s,[],none⟩ := by
  simp +decide [X86.step,X86.logicalStep,X86.scalarRead,X86.scalarRegisterValue,X86.scalarWrite,X86.scalarWriteValue,
    X86.ScalarDestination.source,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
    X86.ScalarWidth.bits,X86.ScalarWidth.bytes,X86.logicalFlags,X86.logicalValue,X86.evenParity,
    guardZero,guardZeroFlags,guardMove]

theorem guard_compare_step (s : X86.State) :
    X86.step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) (guardZero s) =
      ⟨guardCompare s,[],none⟩ := by
  have nocarry (f : Word) : X86.ArithmeticKind.compare.carry f = false := by rfl
  simp +decide [X86.step,X86.arithmeticStep,X86.scalarRead,X86.scalarRegisterValue,X86.ScalarDestination.source,
    X86.ArithmeticKind.subtract,nocarry,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
    guardCompare,guardZero,guardMove]

theorem guard_branch_step (s : X86.State) :
    X86.step (.branch (some 7) 60 17) (guardCompare s) = ⟨guardFinal s,[],none⟩ := by
  simp only [X86.step,guardCompare,guardFinal,compare_ja_predicate]

/-- The byte-decoded first native guard, with both actual successors and all
state fields fixed. The evaluator stops after JA without forcing its target. -/
theorem native_first_guard (s : X86.State) (position : s.pc=7) :
    X86Path.Execution 0 native s [] (guardFinal s) := by
  have d0 : X86Path.decodeAt 0 native ⟨7,3⟩ s = .ok
      (.move .w64 (.register (.low 6)) (.register (.low 1)) 10) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode7,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have pc1 : (guardMove s).pc=10 := rfl
  have pc2 : (guardZero s).pc=12 := rfl
  have pc3 : (guardCompare s).pc=15 := rfl
  have d1 : X86Path.decodeAt 0 native ⟨10,2⟩ (guardMove s) = .ok
      (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode10,pc1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt 0 native ⟨12,3⟩ (guardZero s) = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode12,pc2,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d3 : X86Path.decodeAt 0 native ⟨15,2⟩ (guardCompare s) = .ok
      (.branch (some 7) 60 17) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode15,pc3,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have evaluated : X86Path.evaluate 0 native [⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] s =
      .ok ⟨⟨guardFinal s,[],none⟩,(0xffffffffffffffef#64)⟩ := by
    simp only [X86Path.evaluate,d0,d1,d2,d3,guard_move_step s position,
      guard_zero_step,guard_compare_step,guard_branch_step,X86.definedFlags,
      Option.isSome, Bool.false_eq_true, List.isEmpty_cons, List.isEmpty_nil,
      List.nil_append, ite_false]
    rfl
  exact X86Path.evaluate_sound _ _ _ _ _ evaluated

theorem virtual_decode11 : BPF.decode proof 11 = .ok ⟨0x2d,2,3,22,0⟩ := rfl

def proofGuardFinal (p : BPF.State) : BPF.State :=
  { p with pc := if p.regs 2 > p.regs 3 then 34 else 12 }

theorem proof_first_guard (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=11) (active : p.halted=false) :
    BPFPlatform.step (initializedPlatform env) proof p = .ok ⟨proofGuardFinal p,[],none⟩ := by
  rw [initialized_ordinary_step env p (by omega) (by omega)]
  simp +decide [BPF.step,position,active,virtual_decode11,BPF.execute,BPF.source,BPF.comparison,
    proofGuardFinal,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]


theorem guard_final_flags (s : X86.State) :
    (guardFinal s).rflags = X86.arithmeticFlags .w64 true false (s.gpr 1) (s.gpr 2) s.rflags := by
  exact xor_compare_flags_choice (s.gpr 1) (s.gpr 2) (0#64) s.rflags (guardZeroFlags s.rflags) rfl

/-- Both first-guard executions and the matching actual conditional
successors. State/flags come from the decoded instructions, not from a path
annotation; no data access or helper event occurs in either guard. -/
theorem first_guard_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=7) (proofPC : p.pc=11) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (limit : n.gpr 2=p.regs 3) :
    X86Path.Execution 0 native n [] (guardFinal n) ∧
    Execution (initializedInstructionStep env) p [] (proofGuardFinal p) ∧
    (guardFinal n).pc = (if p.regs 2 > p.regs 3 then 60 else 17) ∧
    (proofGuardFinal p).pc = (if p.regs 2 > p.regs 3 then 34 else 12) ∧
    (guardFinal n).rflags = X86.arithmeticFlags .w64 true false (p.regs 2) (p.regs 3) n.rflags := by
  have proofStep : initializedInstructionStep env p [] (proofGuardFinal p) :=
    ⟨⟨proofGuardFinal p,[],none⟩,proof_first_guard env p proofPC active,rfl,rfl⟩
  refine ⟨native_first_guard n nativePC,?_,?_,rfl,?_⟩
  · simpa using Execution.next proofStep (Execution.refl _)
  · simp only [guardFinal,pointer,limit]
  · simpa only [pointer,limit] using guard_final_flags n


/-- Concatenate actual canonical byte-decoded executions. This changes no
instruction or successor and adds no bound to a native execution. -/
theorem native_execution_append {base : Word} {bytes : Array Byte}
    {before middle after : X86.State} {first second : List Event}
    (run : X86Path.Execution base bytes before first middle)
    (rest : X86Path.Execution base bytes middle second after) :
    X86Path.Execution base bytes before (first++second) after := by
  induction run with
  | refl => exact rest
  | next entry instruction decoded tail ih =>
      simpa only [List.append_assoc] using X86Path.Execution.next entry instruction decoded (ih rest)

/-- One entry-to-first-guard correspondence for the actual captured artifacts.
Both complete states and all nine B events are retained; projection is only
the proved-private observer, and neither branch outcome is assumed. -/
theorem entry_first_guard_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
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
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ∀ i < 8, ¬ initializationPrivateByte (p.regs 10)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    X86Path.Execution 0 native n [first,second] (guardFinal (nativePrefixFinal n pointer limit)) ∧
    Execution (initializedInstructionStep env) p
      (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit)
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)) ∧
    (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)) = [first,second] ∧
    (guardFinal (nativePrefixFinal n pointer limit)).pc = (if pointer > limit then 60 else 17) ∧
    (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).pc =
      (if pointer > limit then 34 else 12) ∧
    initializationAgreesOutside (p.regs 10) (guardFinal (nativePrefixFinal n pointer limit)).memory
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).memory ∧
    (guardFinal (nativePrefixFinal n pointer limit)).gpr 0 =
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).regs 1 ∧
    (guardFinal (nativePrefixFinal n pointer limit)).gpr 6 =
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).regs 2 ∧
    (guardFinal (nativePrefixFinal n pointer limit)).rflags =
      X86.arithmeticFlags .w64 true false pointer limit n.rflags := by
  obtain ⟨nrun,prun,trace,pointerMatch,limitMatch,memoryMatch⟩ :=
    initialized_prefix_correspondence env n p pointer limit stack first second nativePC proofPC active
      context memory nativeStack read0 read1 write40 write32 write24 write16 write8 read40 read32 guest0 guest1
  obtain ⟨nguard,pguard,npc,ppc,flags⟩ := first_guard_correspondence env
    (nativePrefixFinal n pointer limit)
    (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)
    (by simp [nativePrefixFinal,nativeAfterSecond,nativeAfter,nativePC]) rfl
    (by simpa [initializationFinal,proofPrefixFinal,afterSpill,BPF.setReg] using active)
    pointerMatch limitMatch
  refine ⟨?_,?_,trace,?_,?_,memoryMatch,?_,?_,?_⟩
  · simpa only [List.append_nil] using native_execution_append nrun nguard
  · simpa only [List.append_nil] using prun.append pguard
  · simpa +decide [initializationFinal,BPF.setReg] using npc
  · simpa +decide [initializationFinal,BPF.setReg] using ppc
  · simp +decide [guardFinal,guardCompare,guardZero,proofGuardFinal,initializationFinal,BPF.setReg]
  · simp +decide [guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter,
      proofGuardFinal,initializationFinal,BPF.setReg]
  · simpa +decide [initializationFinal,BPF.setReg,nativePrefixFinal,nativeAfterSecond,nativeAfter] using flags


/-- A universal canonical relational-step fact, not just the executable XOR
representative. Every allowed XOR transition has exactly the actual empty
trace/no fault, and the next CMP reaches the same complete architectural state. -/
theorem compare_after_relational_xor (s : X86.State) (actual : Transition X86.State)
    (run : X86.Step (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12)
      (guardMove s) actual) :
    actual.events = [] ∧ actual.fault = none ∧ actual.state.pc = 12 ∧
    X86.step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) actual.state =
      ⟨guardCompare s,[],none⟩ := by
  change X86.matchesTransition _ (X86.step _ (guardMove s)) actual at run
  rw [guard_zero_step] at run
  simp only [X86.matchesTransition,X86.definedFlags,X86.observedRegisters,
    Option.isSome,Bool.false_eq_true,ite_false] at run
  obtain ⟨events,fault,states⟩ := run
  change { guardZero s with rflags := (guardZero s).rflags &&& (0xffffffffffffffef : Word) } =
    { actual.state with rflags := actual.state.rflags &&& (0xffffffffffffffef : Word) } at states
  have shape : actual.state = { guardZero s with rflags := actual.state.rflags } := by
    exact (congrArg (fun t : X86.State => {t with rflags := actual.state.rflags}) states).symm
  have allowed : actual.state.rflags &&& (0xffffffffffffffef#64) =
      X86.logicalFlags .w32 .xor (0#64) (0#64) s.rflags &&& (0xffffffffffffffef#64) := by
    simpa +decide [guardZero,guardZeroFlags] using (congrArg X86.State.rflags states).symm
  have sameFlags : X86.arithmeticFlags .w64 true false (s.gpr 1) (s.gpr 2) actual.state.rflags =
      X86.arithmeticFlags .w64 true false (s.gpr 1) (s.gpr 2) (guardZeroFlags s.rflags) :=
    (xor_compare_flags_choice _ _ (0#64) _ _ allowed).trans
      (xor_compare_flags_choice (s.gpr 1) (s.gpr 2) (0#64) s.rflags (guardZeroFlags s.rflags) rfl).symm
  refine ⟨events.symm,fault.symm,(congrArg X86.State.pc states).symm,?_⟩
  rw [shape]
  have nocarry (f : Word) : X86.ArithmeticKind.compare.carry f = false := by rfl
  simp +decide [X86.step,X86.arithmeticStep,X86.scalarRead,X86.scalarRegisterValue,
    X86.ScalarDestination.source,X86.ArithmeticKind.subtract,nocarry,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
    guardCompare,guardZero,guardMove,sameFlags]


/-- A fully observed reference step determines its entire transition. The
register observation premise excludes instructions with undefined GPR bits. -/
theorem fully_observed_step_unique (instruction : X86.Instruction) (s : X86.State)
    (actual : Transition X86.State)
    (flags : X86.definedFlags instruction = (0xffffffffffffffff#64))
    (registers : ∀ state, X86.observedRegisters instruction state = state.gpr)
    (run : X86.Step instruction s actual) : actual = X86.step instruction s := by
  have maskAll (word : Word) : word &&& (0xffffffffffffffff#64) = word := by
    unfold Word at *
    bv_decide
  change X86.matchesTransition instruction (X86.step instruction s) actual at run
  obtain ⟨events,fault,states⟩ := run
  have stateExact : (X86.step instruction s).state = actual.state := by
    cases beforeState : (X86.step instruction s).state
    cases afterState : actual.state
    cases h : (X86.step instruction s).fault <;>
      simpa [beforeState,afterState,h,flags,registers,maskAll] using states
  cases actual
  cases expected : X86.step instruction s
  simp only [expected] at events fault stateExact
  cases stateExact
  cases events
  cases fault
  rfl

/-- Universal local guard transport for canonical relational steps. Each
supplied step is proved to be the actual byte-decoded instruction at its
actual pre-state; arbitrary XOR AF choices are admitted. All other state,
ordered effects, faults and the actual branch successor are determined. -/
theorem native_guard_relational_block (s : X86.State) (position : s.pc=7)
    (moved zeroed compared branched : Transition X86.State)
    (moveRun : X86.Step (.move .w64 (.register (.low 6)) (.register (.low 1)) 10) s moved)
    (xorRun : X86.Step (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12) moved.state zeroed)
    (compareRun : X86.Step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15)
      zeroed.state compared)
    (branchRun : X86.Step (.branch (some 7) 60 17) compared.state branched) :
    moved = ⟨guardMove s,[],none⟩ ∧
    zeroed.events = [] ∧ zeroed.fault = none ∧ zeroed.state.pc = 12 ∧
    compared = ⟨guardCompare s,[],none⟩ ∧ branched = ⟨guardFinal s,[],none⟩ ∧
    X86Path.decodeAt 0 native ⟨7,3⟩ s = .ok
      (.move .w64 (.register (.low 6)) (.register (.low 1)) 10) ∧
    X86Path.decodeAt 0 native ⟨10,2⟩ moved.state = .ok
      (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12) ∧
    X86Path.decodeAt 0 native ⟨12,3⟩ zeroed.state = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) ∧
    X86Path.decodeAt 0 native ⟨15,2⟩ compared.state = .ok (.branch (some 7) 60 17) := by
  have moveExact := fully_observed_step_unique _ _ moved rfl (fun _ => rfl) moveRun
  rw [guard_move_step s position] at moveExact
  have actualXor : X86.Step (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12)
      (guardMove s) zeroed := by simpa only [moveExact] using xorRun
  obtain ⟨zeroEvents,zeroFault,zeroPC,nextCompare⟩ := compare_after_relational_xor s zeroed actualXor
  have compareExact := fully_observed_step_unique _ _ compared rfl (fun _ => rfl) compareRun
  rw [nextCompare] at compareExact
  have actualBranch : X86.Step (.branch (some 7) 60 17) (guardCompare s) branched := by
    simpa only [compareExact] using branchRun
  have branchExact := fully_observed_step_unique _ _ branched rfl (fun _ => rfl) actualBranch
  rw [guard_branch_step] at branchExact
  refine ⟨moveExact,zeroEvents,zeroFault,zeroPC,compareExact,branchExact,?_,?_,?_,?_⟩
  · simp +decide [X86Path.decodeAt,native_size,native_decode7,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  · have pc : moved.state.pc=10 := by rw [moveExact]; rfl
    simp +decide [X86Path.decodeAt,native_size,native_decode10,pc,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  · simp +decide [X86Path.decodeAt,native_size,native_decode12,zeroPC,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  · have pc : compared.state.pc=15 := by rw [compareExact]; rfl
    simp +decide [X86Path.decodeAt,native_size,native_decode15,pc,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]


/-- Unknown decoded instructions and arbitrary relational transitions for
these actual artifact extents. Decoding determines the operations; the
complete final transition and all ordered effects follow without selecting
an XOR AF value or a branch outcome. -/
theorem native_guard_decoded_relational_block (s : X86.State) (position : s.pc=7)
    (moved zeroed compared branched : Transition X86.State)
    (i0 i1 i2 i3 : X86.Instruction)
    (decode0 : X86Path.decodeAt 0 native ⟨7,3⟩ s = .ok i0) (moveRun : X86.Step i0 s moved)
    (decode1 : X86Path.decodeAt 0 native ⟨10,2⟩ moved.state = .ok i1) (xorRun : X86.Step i1 moved.state zeroed)
    (decode2 : X86Path.decodeAt 0 native ⟨12,3⟩ zeroed.state = .ok i2) (compareRun : X86.Step i2 zeroed.state compared)
    (decode3 : X86Path.decodeAt 0 native ⟨15,2⟩ compared.state = .ok i3) (branchRun : X86.Step i3 compared.state branched) :
    moved.events ++ zeroed.events ++ compared.events ++ branched.events = [] ∧
    moved.fault = none ∧ zeroed.fault = none ∧ compared.fault = none ∧
    branched = ⟨guardFinal s,[],none⟩ := by
  have d0 : X86Path.decodeAt 0 native ⟨7,3⟩ s = .ok
      (.move .w64 (.register (.low 6)) (.register (.low 1)) 10) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode7,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have same0 := Except.ok.inj (decode0.symm.trans d0)
  subst i0
  have moveExact := fully_observed_step_unique _ _ moved rfl (fun _ => rfl) moveRun
  rw [guard_move_step s position] at moveExact
  have pc1 : moved.state.pc=10 := by rw [moveExact]; rfl
  have d1 : X86Path.decodeAt 0 native ⟨10,2⟩ moved.state = .ok
      (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode10,pc1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have same1 := Except.ok.inj (decode1.symm.trans d1)
  subst i1
  have actualXor : X86.Step (.logic .w32 .xor (.register (.low 0)) (.register (.low 0)) 12)
      (guardMove s) zeroed := by simpa only [moveExact] using xorRun
  obtain ⟨_,_,zeroPC,nextCompare⟩ := compare_after_relational_xor s zeroed actualXor
  have d2 : X86Path.decodeAt 0 native ⟨12,3⟩ zeroed.state = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 15) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode12,zeroPC,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have same2 := Except.ok.inj (decode2.symm.trans d2)
  subst i2
  have compareExact := fully_observed_step_unique _ _ compared rfl (fun _ => rfl) compareRun
  rw [nextCompare] at compareExact
  have pc3 : compared.state.pc=15 := by rw [compareExact]; rfl
  have d3 : X86Path.decodeAt 0 native ⟨15,2⟩ compared.state = .ok (.branch (some 7) 60 17) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode15,pc3,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have same3 := Except.ok.inj (decode3.symm.trans d3)
  subst i3
  obtain ⟨movedEq,zeroEvents,zeroFault,_,comparedEq,branchedEq,_,_,_,_⟩ :=
    native_guard_relational_block s position moved zeroed compared branched moveRun xorRun compareRun branchRun
  refine ⟨?_,?_,zeroFault,?_,branchedEq⟩
  · simp only [movedEq,comparedEq,branchedEq,zeroEvents,List.nil_append]
  · exact congrArg Transition.fault movedEq
  · exact congrArg Transition.fault comparedEq


/-- The actual verifier-facing B guard checks every canonical relational
execution of the decoded native guard, not only the executable representative. -/
theorem relational_first_guard_correspondence (env : BPF.Environment) (p : BPF.State) (s : X86.State) (position : s.pc=7)
    (moved zeroed compared branched : Transition X86.State)
    (i0 i1 i2 i3 : X86.Instruction)
    (decode0 : X86Path.decodeAt 0 native ⟨7,3⟩ s = .ok i0) (moveRun : X86.Step i0 s moved)
    (decode1 : X86Path.decodeAt 0 native ⟨10,2⟩ moved.state = .ok i1) (xorRun : X86.Step i1 moved.state zeroed)
    (decode2 : X86Path.decodeAt 0 native ⟨12,3⟩ zeroed.state = .ok i2) (compareRun : X86.Step i2 zeroed.state compared)
    (decode3 : X86Path.decodeAt 0 native ⟨15,2⟩ compared.state = .ok i3) (branchRun : X86.Step i3 compared.state branched)
    (proofPC : p.pc=11) (active : p.halted=false)
    (pointer : s.gpr 1=p.regs 2) (limit : s.gpr 2=p.regs 3) :
    moved.events ++ zeroed.events ++ compared.events ++ branched.events = [] ∧
    Execution (initializedInstructionStep env) p
      (moved.events ++ zeroed.events ++ compared.events ++ branched.events) (proofGuardFinal p) ∧
    branched = ⟨guardFinal s,[],none⟩ ∧
    branched.state.pc = (if p.regs 2 > p.regs 3 then 60 else 17) ∧
    (proofGuardFinal p).pc = (if p.regs 2 > p.regs 3 then 34 else 12) := by
  obtain ⟨trace,_,_,_,branchedEq⟩ := native_guard_decoded_relational_block s position
    moved zeroed compared branched i0 i1 i2 i3 decode0 moveRun decode1 xorRun decode2 compareRun decode3 branchRun
  obtain ⟨_,proofRun,npc,ppc,_⟩ := first_guard_correspondence env s p position proofPC active pointer limit
  refine ⟨trace,?_,branchedEq,?_,ppc⟩
  · rw [trace]
    exact proofRun
  · simpa only [branchedEq] using npc


theorem virtual_decode12 : BPF.decode proof 12 = .ok ⟨0xb7,4,0,0,8⟩ := rfl
theorem virtual_decode13 : BPF.decode proof 13 = .ok ⟨0xbf,5,2,0,0⟩ := rfl
theorem virtual_decode14 : BPF.decode proof 14 = .ok ⟨0x07,5,0,0,72⟩ := rfl
theorem virtual_decode15 : BPF.decode proof 15 = .ok ⟨0x2d,5,3,18,0⟩ := rfl
theorem virtual_decode16 : BPF.decode proof 16 = .ok ⟨0x0f,4,2,0,0⟩ := rfl
theorem virtual_decode17 : BPF.decode proof 17 = .ok ⟨0x2d,4,3,16,0⟩ := rfl

/-- Reuse the existing evaluator transport for any actual ordinary B path.
The witness must check every PC and real successor; no PC is changed here. -/
theorem ordinary_path_execution (env : BPF.Environment) (positions : List Nat)
    (p : BPF.State) (result : Transition BPF.State)
    (ordinary : ∀ pc ∈ positions, pc ≠ 0 ∧ pc ≠ 2)
    (accepted : BPFPath.evaluate env proof positions p = .ok result) :
    Execution (initializedInstructionStep env) p result.events result.state := by
  exact BPFPath.evaluate_execution_transport env proof id (initializedInstructionStep env)
    (fun pc => pc ≠ 0 ∧ pc ≠ 2)
    (by
      intro s pc bound atPosition result actual
      refine ⟨result,?_,rfl,rfl⟩
      change BPFPlatform.step (initializedPlatform env) proof s = .ok result
      rw [initialized_ordinary_step env s (by omega) (by omega)]
      exact actual)
    positions ordinary p result accepted

def remainingProof72 (p : BPF.State) : BPF.State :=
  { BPF.setReg (BPF.setReg p 4 (8#64)) 5 (p.regs 2+(72#64)) with
    pc := if p.regs 2+(72#64) > p.regs 3 then 34 else 16 }

def remainingProof8 (p : BPF.State) : BPF.State :=
  { BPF.setReg p 4 (p.regs 4+p.regs 2) with
    pc := if p.regs 4+p.regs 2 > p.regs 3 then 34 else 18 }

def remainingProofFinal (p : BPF.State) : BPF.State :=
  if p.regs 2+(72#64) > p.regs 3 then remainingProof72 p
    else remainingProof8 (remainingProof72 p)

theorem remaining_proof72_block (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=12) (active : p.halted=false) :
    BPFPath.evaluate env proof [12,13,14,15] p = .ok ⟨remainingProof72 p,[],none⟩ := by
  simp +decide [BPFPath.evaluate,virtual_decode12,virtual_decode13,virtual_decode14,virtual_decode15,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,position,active,remainingProof72,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  funext index
  by_cases h : index=5 <;> simp [h]

theorem remaining_proof8_block (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=16) (active : p.halted=false) :
    BPFPath.evaluate env proof [16,17] p = .ok ⟨remainingProof8 p,[],none⟩ := by
  simp +decide [BPFPath.evaluate,virtual_decode16,virtual_decode17,
    BPF.execute,BPF.source,BPF.alu,BPF.comparison,BPF.setReg,position,active,remainingProof8,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Actual accepted Bpc12..17, including either early exit or fall-through.
No branch outcome, non-wrapping arithmetic or environment input is assumed. -/
theorem remaining_proof_guards (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=12) (active : p.halted=false) :
    Execution (initializedInstructionStep env) p [] (remainingProofFinal p) := by
  have headRun := ordinary_path_execution env [12,13,14,15] p ⟨remainingProof72 p,[],none⟩
    (by intro pc inside; simp at inside; omega) (remaining_proof72_block env p position active)
  by_cases reject72 : p.regs 2+(72#64) > p.regs 3
  · simpa only [remainingProofFinal,reject72,ite_true] using headRun
  · have at16 : (remainingProof72 p).pc=16 := by simp [remainingProof72,reject72]
    have stillActive : (remainingProof72 p).halted=false := by
      simpa [remainingProof72,BPF.setReg] using active
    have suffix := ordinary_path_execution env [16,17] (remainingProof72 p)
      ⟨remainingProof8 (remainingProof72 p),[],none⟩
      (by intro pc inside; simp at inside; omega)
      (remaining_proof8_block env _ at16 stillActive)
    simpa only [remainingProofFinal,reject72,ite_false,List.nil_append] using headRun.append suffix

/-- The actual exit decision, with architectural 64-bit wraparound retained.
Only the order of the two pure comparisons differs from the native program. -/
theorem remaining_proof_successor (p : BPF.State) :
    (remainingProofFinal p).pc =
      (if p.regs 2+(8#64) > p.regs 3 ∨ p.regs 2+(72#64) > p.regs 3 then 34 else 18) := by
  have add8 : (8#64)+p.regs 2 = p.regs 2+(8#64) := BitVec.add_comm _ _
  by_cases reject72 : p.regs 2+(72#64) > p.regs 3 <;>
    by_cases reject8 : p.regs 2+(8#64) > p.regs 3 <;>
    simp +decide [remainingProofFinal,remainingProof72,remainingProof8,BPF.setReg,
      add8,reject72,reject8]


theorem native_decode17 (s : X86.State) :
    X86.decode (native.extract 17 21) s = .ok (.lea .w64 7 (s.gpr 6+8) (s.pc+4)) := by
  have bytes : native.extract 17 21 = #[0x48,0x8d,0x7e,0x08] := by decide
  rw [bytes]
  exact X86.decode_lea_rdi_rsi8 s

theorem native_decode21 (s : X86.State) :
    X86.decode (native.extract 21 24) s = .ok
      (.arithmetic .w64 .compare (.register (.low 7)) (.register (.low 2)) (s.pc+3)) := by rfl

theorem native_decode24 (s : X86.State) :
    X86.decode (native.extract 24 26) s = .ok (.branch (some 7) ((s.pc+2)+(34#64)) (s.pc+2)) := by
  have bytes : native.extract 24 26 = #[0x77,0x22] := by decide
  rw [bytes]
  exact X86.decode_ja_rel8 s (0x22#8)

theorem native_decode26 (s : X86.State) :
    X86.decode (native.extract 26 30) s = .ok
      (.arithmetic .w64 .add (.register (.low 6)) (.immediate 72) (s.pc+4)) := by
  have bytes : native.extract 26 30 = #[0x48,0x83,0xc6,0x48] := by decide
  rw [bytes]
  exact X86.decode_add_rsi72 s

theorem native_decode30 (s : X86.State) :
    X86.decode (native.extract 30 33) s = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) (s.pc+3)) := by rfl

theorem native_decode33 (s : X86.State) :
    X86.decode (native.extract 33 35) s = .ok (.branch (some 7) ((s.pc+2)+(25#64)) (s.pc+2)) := by
  have bytes : native.extract 33 35 = #[0x77,0x19] := by decide
  rw [bytes]
  exact X86.decode_ja_rel8 s (0x19#8)

def remainingNativeLea (s : X86.State) : X86.State :=
  { s with gpr := fun r => if r=7 then s.gpr 6+(8#64) else s.gpr r, pc := 21 }

def remainingNativeCmp8 (s : X86.State) : X86.State :=
  { remainingNativeLea s with
    rflags := X86.arithmeticFlags .w64 true false (s.gpr 6+(8#64)) (s.gpr 2) s.rflags
    pc := 24 }

def remainingNative8 (s : X86.State) : X86.State :=
  { remainingNativeCmp8 s with pc := if s.gpr 6+(8#64) > s.gpr 2 then 60 else 26 }

def remainingNativeAdd (s : X86.State) : X86.State :=
  { s with
    gpr := fun r => if r=6 then s.gpr 6+(72#64) else s.gpr r
    rflags := X86.arithmeticFlags .w64 false false (s.gpr 6) (72#64) s.rflags
    pc := 30 }

def remainingNativeCmp72 (s : X86.State) : X86.State :=
  { remainingNativeAdd s with
    rflags := X86.arithmeticFlags .w64 true false (s.gpr 6+(72#64)) (s.gpr 2) (remainingNativeAdd s).rflags
    pc := 33 }

def remainingNative72 (s : X86.State) : X86.State :=
  { remainingNativeCmp72 s with pc := if s.gpr 6+(72#64) > s.gpr 2 then 60 else 35 }

def remainingNativeFinal (s : X86.State) : X86.State :=
  if s.gpr 6+(8#64) > s.gpr 2 then remainingNative8 s else remainingNative72 (remainingNative8 s)

theorem remaining_native_lea_step (s : X86.State) :
    X86.step (.lea .w64 7 (s.gpr 6+(8#64)) 21) s = ⟨remainingNativeLea s,[],none⟩ := by
  rfl

theorem remaining_native_cmp8_step (s : X86.State) :
    X86.step (.arithmetic .w64 .compare (.register (.low 7)) (.register (.low 2)) 24) (remainingNativeLea s) =
      ⟨remainingNativeCmp8 s,[],none⟩ := by
  have nocarry (f : Word) : X86.ArithmeticKind.compare.carry f = false := by rfl
  simp +decide [X86.step,X86.arithmeticStep,X86.scalarRead,X86.scalarRegisterValue,
    X86.ScalarDestination.source,X86.ArithmeticKind.subtract,nocarry,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
    remainingNativeCmp8,remainingNativeLea]

theorem remaining_native_branch8_step (s : X86.State) :
    X86.step (.branch (some 7) 60 26) (remainingNativeCmp8 s) = ⟨remainingNative8 s,[],none⟩ := by
  simp only [X86.step,remainingNative8,remainingNativeCmp8,compare_ja_predicate]

theorem add72_value (value : Word) :
    X86.arithmeticValue .w64 false false value (72#64) = value+(72#64) := by
  simp only [X86.arithmeticValue,X86.ScalarWidth.bits,X86.ScalarWidth.bytes]
  unfold Word at *
  bv_decide

theorem remaining_native_add72_step (s : X86.State) :
    X86.step (.arithmetic .w64 .add (.register (.low 6)) (.immediate (72#64)) 30) s =
      ⟨remainingNativeAdd s,[],none⟩ := by
  have nocarry (f : Word) : X86.ArithmeticKind.add.carry f = false := by rfl
  simp +decide [X86.step,X86.arithmeticStep,X86.scalarRead,X86.scalarRegisterValue,
    X86.scalarWrite,X86.scalarWriteValue,X86.ScalarDestination.source,
    X86.ArithmeticKind.subtract,nocarry,add72_value,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
    remainingNativeAdd]

theorem remaining_native_cmp72_step (s : X86.State) :
    X86.step (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 33) (remainingNativeAdd s) =
      ⟨remainingNativeCmp72 s,[],none⟩ := by
  have nocarry (f : Word) : X86.ArithmeticKind.compare.carry f = false := by rfl
  simp +decide [X86.step,X86.arithmeticStep,X86.scalarRead,X86.scalarRegisterValue,
    X86.ScalarDestination.source,X86.ArithmeticKind.subtract,nocarry,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
    remainingNativeCmp72,remainingNativeAdd]

theorem remaining_native_branch72_step (s : X86.State) :
    X86.step (.branch (some 7) 60 35) (remainingNativeCmp72 s) = ⟨remainingNative72 s,[],none⟩ := by
  simp only [X86.step,remainingNative72,remainingNativeCmp72,compare_ja_predicate]


theorem remaining_native8_block (s : X86.State) (position : s.pc=17) :
    X86Path.Execution 0 native s [] (remainingNative8 s) := by
  have d0 : X86Path.decodeAt 0 native ⟨17,4⟩ s = .ok (.lea .w64 7 (s.gpr 6+(8#64)) 21) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode17,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have pc1 : (remainingNativeLea s).pc=21 := rfl
  have pc2 : (remainingNativeCmp8 s).pc=24 := rfl
  have d1 : X86Path.decodeAt 0 native ⟨21,3⟩ (remainingNativeLea s) = .ok
      (.arithmetic .w64 .compare (.register (.low 7)) (.register (.low 2)) 24) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode21,pc1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt 0 native ⟨24,2⟩ (remainingNativeCmp8 s) = .ok (.branch (some 7) 60 26) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode24,pc2,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have evaluated : X86Path.evaluate 0 native [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩] s =
      .ok ⟨⟨remainingNative8 s,[],none⟩,(0xffffffffffffffff#64)⟩ := by
    simp only [X86Path.evaluate,d0,d1,d2,remaining_native_lea_step,
      remaining_native_cmp8_step,remaining_native_branch8_step,X86.definedFlags,
      Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,List.nil_append,ite_false]
    rfl
  exact X86Path.evaluate_sound _ _ _ _ _ evaluated

theorem remaining_native72_block (s : X86.State) (position : s.pc=26) :
    X86Path.Execution 0 native s [] (remainingNative72 s) := by
  have d0 : X86Path.decodeAt 0 native ⟨26,4⟩ s = .ok
      (.arithmetic .w64 .add (.register (.low 6)) (.immediate (72#64)) 30) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode26,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have pc1 : (remainingNativeAdd s).pc=30 := rfl
  have pc2 : (remainingNativeCmp72 s).pc=33 := rfl
  have d1 : X86Path.decodeAt 0 native ⟨30,3⟩ (remainingNativeAdd s) = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 33) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode30,pc1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt 0 native ⟨33,2⟩ (remainingNativeCmp72 s) = .ok (.branch (some 7) 60 35) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode33,pc2,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have evaluated : X86Path.evaluate 0 native [⟨26,4⟩,⟨30,3⟩,⟨33,2⟩] s =
      .ok ⟨⟨remainingNative72 s,[],none⟩,(0xffffffffffffffff#64)⟩ := by
    simp only [X86Path.evaluate,d0,d1,d2,remaining_native_add72_step,
      remaining_native_cmp72_step,remaining_native_branch72_step,X86.definedFlags,
      Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,List.nil_append,ite_false]
    rfl
  exact X86Path.evaluate_sound _ _ _ _ _ evaluated

/-- The native order is +8 then +72. Actual byte-decoded successors choose
which segment executes; neither a branch nor non-wrapping addition is assumed. -/
theorem remaining_native_guards (s : X86.State) (position : s.pc=17) :
    X86Path.Execution 0 native s [] (remainingNativeFinal s) := by
  have headRun := remaining_native8_block s position
  by_cases reject8 : s.gpr 6+(8#64) > s.gpr 2
  · simpa only [remainingNativeFinal,reject8,ite_true] using headRun
  · have at26 : (remainingNative8 s).pc=26 := by simp [remainingNative8,reject8]
    have tailRun := remaining_native72_block (remainingNative8 s) at26
    simpa only [remainingNativeFinal,reject8,ite_false,List.nil_append] using
      native_execution_append headRun tailRun

theorem remaining_native_successor (s : X86.State) :
    (remainingNativeFinal s).pc =
      (if s.gpr 6+(8#64) > s.gpr 2 ∨ s.gpr 6+(72#64) > s.gpr 2 then 60 else 35) := by
  by_cases reject8 : s.gpr 6+(8#64) > s.gpr 2 <;>
    by_cases reject72 : s.gpr 6+(72#64) > s.gpr 2 <;>
    simp +decide [remainingNativeFinal,remainingNative72,remainingNative8,
      remainingNativeCmp8,remainingNativeLea,reject8,reject72]

/-- Both actual guard regions, including their different evaluation orders,
complete successor states, identical empty effects and corresponding exits.
All arithmetic is modular; no monotonicity or non-overflow premise is used. -/
theorem remaining_guard_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=17) (proofPC : p.pc=12) (active : p.halted=false)
    (pointer : n.gpr 6=p.regs 2) (limit : n.gpr 2=p.regs 3) :
    X86Path.Execution 0 native n [] (remainingNativeFinal n) ∧
    Execution (initializedInstructionStep env) p [] (remainingProofFinal p) ∧
    (remainingNativeFinal n).pc =
      (if p.regs 2+(8#64) > p.regs 3 ∨ p.regs 2+(72#64) > p.regs 3 then 60 else 35) ∧
    (remainingProofFinal p).pc =
      (if p.regs 2+(8#64) > p.regs 3 ∨ p.regs 2+(72#64) > p.regs 3 then 34 else 18) ∧
    (remainingNativeFinal n).memory = n.memory ∧ (remainingProofFinal p).memory = p.memory := by
  refine ⟨remaining_native_guards n nativePC,remaining_proof_guards env p proofPC active,
    ?_,remaining_proof_successor p,?_,?_⟩
  · simpa only [pointer,limit] using remaining_native_successor n
  · by_cases reject8 : n.gpr 6+(8#64) > n.gpr 2 <;>
      simp [remainingNativeFinal,reject8,remainingNative8,remainingNativeCmp8,remainingNativeLea,
        remainingNative72,remainingNativeCmp72,remainingNativeAdd]
  · by_cases reject72 : p.regs 2+(72#64) > p.regs 3 <;>
      simp [remainingProofFinal,reject72,remainingProof72,remainingProof8,BPF.setReg]


def guardedNativeFinal (n : X86.State) (pointer limit : Word) : X86.State :=
  let first := guardFinal (nativePrefixFinal n pointer limit)
  if pointer > limit then first else remainingNativeFinal first

def guardedProofFinal (p : BPF.State) (pointer limit stack : Word) : BPF.State :=
  let first := proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)
  if pointer > limit then first else remainingProofFinal first

/-- Only RSI/RDI are modified by the later native guard region. -/
theorem remaining_native_frame (s : X86.State) (r : X86.Register) (not6 : r≠6) (not7 : r≠7) :
    (remainingNativeFinal s).gpr r = s.gpr r := by
  by_cases reject8 : s.gpr 6+(8#64) > s.gpr 2 <;>
    simp +decide [remainingNativeFinal,remainingNative8,remainingNativeCmp8,remainingNativeLea,
      remainingNative72,remainingNativeCmp72,remainingNativeAdd,reject8,not6,not7]

/-- The captured later B guards modify only their actual r4/r5 temporaries. -/
theorem remaining_proof_frame (p : BPF.State) (r : BPF.Register) (not4 : r≠4) (not5 : r≠5) :
    (remainingProofFinal p).regs r = p.regs r := by
  by_cases reject72 : p.regs 2+(72#64) > p.regs 3 <;>
    simp +decide [remainingProofFinal,remainingProof72,remainingProof8,BPF.setReg,reject72,not4,not5]

/-- Actual entry through all three bounds guards. All B events remain in
one execution; only proved-private events are projected. The loaded values
choose every actual successor, including wrapping arithmetic. -/
theorem entry_all_guards_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
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
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ∀ i < 8, ¬ initializationPrivateByte (p.regs 10)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    X86Path.Execution 0 native n [first,second] (guardedNativeFinal n pointer limit) ∧
    Execution (initializedInstructionStep env) p
      (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit)
      (guardedProofFinal p pointer limit stack) ∧
    (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)) = [first,second] ∧
    (guardedNativeFinal n pointer limit).pc =
      (if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then 60 else 35) ∧
    (guardedProofFinal p pointer limit stack).pc =
      (if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then 34 else 18) ∧
    initializationAgreesOutside (p.regs 10) (guardedNativeFinal n pointer limit).memory
      (guardedProofFinal p pointer limit stack).memory ∧
    (guardedNativeFinal n pointer limit).gpr 1 = pointer ∧
    (guardedNativeFinal n pointer limit).gpr 0 = (0#64) ∧
    (guardedProofFinal p pointer limit stack).regs 2 = pointer ∧
    (guardedProofFinal p pointer limit stack).regs 1 = (0#64) := by
  obtain ⟨nrun,prun,trace,npc,ppc,memoryMatch,zeroMatch,pointerMatch,flags⟩ :=
    entry_first_guard_correspondence env n p pointer limit stack first second nativePC proofPC active
      context memory nativeStack read0 read1 write40 write32 write24 write16 write8 read40 read32 guest0 guest1
  let n1 := guardFinal (nativePrefixFinal n pointer limit)
  let p1 := proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)
  have p2 : p1.regs 2=pointer := by simp +decide [p1,proofGuardFinal,initializationFinal,BPF.setReg]
  have p3 : p1.regs 3=limit := by simp +decide [p1,proofGuardFinal,initializationFinal,BPF.setReg]
  have p0 : p1.regs 1=(0#64) := by simp +decide [p1,proofGuardFinal,initializationFinal,BPF.setReg]
  have n2 : n1.gpr 1=pointer := by
    simp +decide [n1,guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter]
  have n0 : n1.gpr 0=(0#64) := by simp +decide [n1,guardFinal,guardCompare,guardZero]
  have core :
      X86Path.Execution 0 native n [first,second] (guardedNativeFinal n pointer limit) ∧
      Execution (initializedInstructionStep env) p
        (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit)
        (guardedProofFinal p pointer limit stack) ∧
      (guardedNativeFinal n pointer limit).pc =
        (if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then 60 else 35) ∧
      (guardedProofFinal p pointer limit stack).pc =
        (if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then 34 else 18) ∧
      initializationAgreesOutside (p.regs 10) (guardedNativeFinal n pointer limit).memory
        (guardedProofFinal p pointer limit stack).memory := by
    by_cases reject : pointer > limit
    · refine ⟨?_,?_,?_,?_,?_⟩
      · simpa only [guardedNativeFinal,reject,ite_true] using nrun
      · simpa only [guardedProofFinal,reject,ite_true] using prun
      · simpa only [guardedNativeFinal,reject,ite_true,true_or] using npc
      · simpa only [guardedProofFinal,reject,ite_true,true_or] using ppc
      · simpa only [guardedNativeFinal,guardedProofFinal,reject,ite_true] using memoryMatch
    · have at17 : n1.pc=17 := by simpa only [reject,ite_false] using npc
      have at12 : p1.pc=12 := by simpa only [reject,ite_false] using ppc
      have stillActive : p1.halted=false := by
        simpa [p1,proofGuardFinal,initializationFinal,proofPrefixFinal,afterSpill,BPF.setReg] using active
      have limitMatch : n1.gpr 2=p1.regs 3 := by
        simp +decide [n1,p1,guardFinal,guardCompare,guardZero,guardMove,nativePrefixFinal,nativeAfterSecond,nativeAfter,
          proofGuardFinal,initializationFinal,BPF.setReg]
      obtain ⟨ntail,ptail,ntarget,ptarget,nmemory,pmemory⟩ :=
        remaining_guard_correspondence env n1 p1 at17 at12 stillActive pointerMatch limitMatch
      refine ⟨?_,?_,?_,?_,?_⟩
      · simpa only [guardedNativeFinal,reject,ite_false,List.append_nil] using native_execution_append nrun ntail
      · simpa only [guardedProofFinal,reject,ite_false,List.append_nil] using prun.append ptail
      · simpa only [guardedNativeFinal,reject,ite_false,false_or,p2,p3] using ntarget
      · simpa only [guardedProofFinal,reject,ite_false,false_or,p2,p3] using ptarget
      · simp only [guardedNativeFinal,guardedProofFinal,reject,ite_false]
        change initializationAgreesOutside (p.regs 10) (remainingNativeFinal n1).memory (remainingProofFinal p1).memory
        rw [nmemory,pmemory]
        exact memoryMatch
  refine ⟨core.1,core.2.1,trace,core.2.2.1,core.2.2.2.1,core.2.2.2.2,?_,?_,?_,?_⟩
  · by_cases reject : pointer > limit
    · simpa only [guardedNativeFinal,reject,ite_true] using n2
    · simp only [guardedNativeFinal,reject,ite_false]
      change (remainingNativeFinal n1).gpr 1=pointer
      exact (remaining_native_frame n1 1 (by decide) (by decide)).trans n2
  · by_cases reject : pointer > limit
    · simpa only [guardedNativeFinal,reject,ite_true] using n0
    · simp only [guardedNativeFinal,reject,ite_false]
      change (remainingNativeFinal n1).gpr 0=(0#64)
      exact (remaining_native_frame n1 0 (by decide) (by decide)).trans n0
  · by_cases reject : pointer > limit
    · simpa only [guardedProofFinal,reject,ite_true] using p2
    · simp only [guardedProofFinal,reject,ite_false]
      change (remainingProofFinal p1).regs 2=pointer
      exact (remaining_proof_frame p1 2 (by decide) (by decide)).trans p2
  · by_cases reject : pointer > limit
    · simpa only [guardedProofFinal,reject,ite_true] using p0
    · simp only [guardedProofFinal,reject,ite_false]
      change (remainingProofFinal p1).regs 1=(0#64)
      exact (remaining_proof_frame p1 1 (by decide) (by decide)).trans p0


theorem virtual_decode18 : BPF.decode proof 18 = .ok ⟨0xb7,1,0,0,0⟩ := rfl
theorem virtual_decode19 : BPF.decode proof 19 = .ok ⟨0xb7,3,0,0,0⟩ := rfl
theorem virtual_decode20 : BPF.decode proof 20 = .ok ⟨0x0f,3,2,0,0⟩ := rfl
theorem virtual_decode21 : BPF.decode proof 21 = .ok ⟨0xb7,4,0,0,24910⟩ := rfl
theorem virtual_decode22 : BPF.decode proof 22 = .ok ⟨0x6b,3,4,0,0⟩ := rfl
theorem virtual_decode23 : BPF.decode proof 23 = .ok ⟨0xb7,3,0,0,2⟩ := rfl
theorem virtual_decode24 : BPF.decode proof 24 = .ok ⟨0x0f,3,2,0,0⟩ := rfl
theorem virtual_decode25 : BPF.decode proof 25 = .ok ⟨0xb7,4,0,0,188⟩ := rfl
theorem virtual_decode26 : BPF.decode proof 26 = .ok ⟨0x73,3,4,0,0⟩ := rfl
theorem virtual_decode27 : BPF.decode proof 27 = .ok ⟨0xb7,3,0,0,3⟩ := rfl
theorem virtual_decode28 : BPF.decode proof 28 = .ok ⟨0x0f,3,2,0,0⟩ := rfl
theorem virtual_decode29 : BPF.decode proof 29 = .ok ⟨0x63,3,1,0,0⟩ := rfl
theorem virtual_decode30 : BPF.decode proof 30 = .ok ⟨0xb7,3,0,0,7⟩ := rfl
theorem virtual_decode31 : BPF.decode proof 31 = .ok ⟨0x0f,3,2,0,0⟩ := rfl
theorem virtual_decode32 : BPF.decode proof 32 = .ok ⟨0x73,3,1,0,0⟩ := rfl
theorem virtual_decode33 : BPF.decode proof 33 = .ok ⟨0xb4,1,0,0,2⟩ := rfl

def packetWriteMemory (memory : Memory) (pointer : Word) : Memory :=
  storeMemory (storeMemory (storeMemory (storeMemory memory pointer (24910#64) 2)
    (pointer+(2#64)) (188#64) 1) (pointer+(3#64)) (0#64) 4) (pointer+(7#64)) (0#64) 1

def packetWriteEvents (pointer : Word) : List Event :=
  [.memory .write pointer (valueBytes (24910#64) 2) true,
   .memory .write (pointer+(2#64)) (valueBytes (188#64) 1) true,
   .memory .write (pointer+(3#64)) (valueBytes (0#64) 4) true,
   .memory .write (pointer+(7#64)) (valueBytes (0#64) 1) true]

def packetProofFinal (p : BPF.State) : BPF.State :=
  { BPF.setReg (BPF.setReg (BPF.setReg p 1 (2#64)) 3 (p.regs 2+(7#64))) 4 (188#64) with
    memory := packetWriteMemory p.memory (p.regs 2)
    pc := 34 }

/-- Actual four guest writes, in their actual order and widths. Permission
premises describe successful stores; the trace is neither hidden nor replaced. -/
theorem packet_proof_block (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=18) (active : p.halted=false)
    (write0 : permitted p.memory.writable (p.regs 2) 2 = true)
    (write2 : permitted p.memory.writable (p.regs 2+(2#64)) 1 = true)
    (write3 : permitted p.memory.writable (p.regs 2+(3#64)) 4 = true)
    (write7 : permitted p.memory.writable (p.regs 2+(7#64)) 1 = true) :
    BPFPath.evaluate env proof [18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33] p =
      .ok ⟨packetProofFinal p,packetWriteEvents (p.regs 2),none⟩ := by
  have plus2 : (2#64)+p.regs 2 = p.regs 2+(2#64) := BitVec.add_comm _ _
  have plus3 : (3#64)+p.regs 2 = p.regs 2+(3#64) := BitVec.add_comm _ _
  have plus7 : (7#64)+p.regs 2 = p.regs 2+(7#64) := BitVec.add_comm _ _
  simp +decide [BPFPath.evaluate,virtual_decode18,virtual_decode19,virtual_decode20,virtual_decode21,
    virtual_decode22,virtual_decode23,virtual_decode24,virtual_decode25,virtual_decode26,virtual_decode27,
    virtual_decode28,virtual_decode29,virtual_decode30,virtual_decode31,virtual_decode32,virtual_decode33,
    BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,writeMemory,position,active,
    packetProofFinal,packetWriteMemory,packetWriteEvents,storeMemory,
    plus2,plus3,plus7,write0,write2,write3,write7,
    Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  funext index
  by_cases one : index=1 <;> by_cases three : index=3 <;> by_cases four : index=4 <;>
    simp [one,three,four]


theorem packet_proof_execution (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=18) (active : p.halted=false)
    (write0 : permitted p.memory.writable (p.regs 2) 2 = true)
    (write2 : permitted p.memory.writable (p.regs 2+(2#64)) 1 = true)
    (write3 : permitted p.memory.writable (p.regs 2+(3#64)) 4 = true)
    (write7 : permitted p.memory.writable (p.regs 2+(7#64)) 1 = true) :
    Execution (initializedInstructionStep env) p (packetWriteEvents (p.regs 2)) (packetProofFinal p) := by
  exact ordinary_path_execution env [18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33] p
    ⟨packetProofFinal p,packetWriteEvents (p.regs 2),none⟩
    (by intro pc inside; simp at inside; omega)
    (packet_proof_block env p position active write0 write2 write3 write7)

theorem virtual_decode34 : BPF.decode proof 34 = .ok ⟨0xbc,0,1,0,0⟩ := rfl
theorem virtual_decode35 : BPF.decode proof 35 = .ok ⟨0x05,0,0,0,0⟩ := rfl
theorem virtual_decode36 : BPF.decode proof 36 = .ok ⟨0x95,0,0,0,0⟩ := rfl

def proofExitFinal (p : BPF.State) : BPF.State :=
  { BPF.setReg p 0 ((p.regs 1).setWidth 32 |>.setWidth 64) with pc := 37, halted := true }

/-- The accepted artifact's actual MOV32/JA/EXIT tail, including the appended
EXIT stub. The complete final state records the architectural return width. -/
theorem proof_exit_block (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=34) (active : p.halted=false) :
    BPFPath.evaluate env proof [34,35,36] p = .ok ⟨proofExitFinal p,[],none⟩ := by
  simp +decide [BPFPath.evaluate,virtual_decode34,virtual_decode35,virtual_decode36,
    BPF.execute,BPF.source,BPF.alu,BPF.setReg,position,active,proofExitFinal,
    Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

theorem proof_exit_execution (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=34) (active : p.halted=false) :
    Execution (initializedInstructionStep env) p [] (proofExitFinal p) := by
  exact ordinary_path_execution env [34,35,36] p ⟨proofExitFinal p,[],none⟩
    (by intro pc inside; simp at inside; omega) (proof_exit_block env p position active)

/-- Successful actual guest stores through the real accepted EXIT, retaining
all four memory events in order and deriving the returned value two. -/
theorem packet_proof_return (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=18) (active : p.halted=false)
    (write0 : permitted p.memory.writable (p.regs 2) 2 = true)
    (write2 : permitted p.memory.writable (p.regs 2+(2#64)) 1 = true)
    (write3 : permitted p.memory.writable (p.regs 2+(3#64)) 4 = true)
    (write7 : permitted p.memory.writable (p.regs 2+(7#64)) 1 = true) :
    Execution (initializedInstructionStep env) p (packetWriteEvents (p.regs 2))
      (proofExitFinal (packetProofFinal p)) ∧
    (proofExitFinal (packetProofFinal p)).halted = true ∧
    (proofExitFinal (packetProofFinal p)).regs 0 = (2#64) := by
  have body := packet_proof_execution env p position active write0 write2 write3 write7
  have tailRun := proof_exit_execution env (packetProofFinal p) rfl
    (by simpa [packetProofFinal,BPF.setReg] using active)
  refine ⟨?_,rfl,?_⟩
  · simpa only [List.append_nil] using body.append tailRun
  · simp +decide [proofExitFinal,packetProofFinal,BPF.setReg]


theorem native_decode35 (s : X86.State) :
    X86.decode (native.extract 35 40) s = .ok
      (.move .w16 (.memory (s.gpr 1)) (.immediate 24910) (s.pc+5)) := by
  have bytes : native.extract 35 40 = #[0x66,0xc7,0x01,0x4e,0x61] := by decide
  rw [bytes]
  exact (X86.decode_simple_packet_tail s).1

theorem native_decode40 (s : X86.State) :
    X86.decode (native.extract 40 44) s = .ok
      (.move .w8 (.memory (s.gpr 1+2)) (.immediate ((188#8).signExtend 64)) (s.pc+4)) := by
  have bytes : native.extract 40 44 = #[0xc6,0x41,0x02,0xbc] := by decide
  rw [bytes]
  exact (X86.decode_simple_packet_tail s).2.1

theorem native_decode44 (s : X86.State) :
    X86.decode (native.extract 44 51) s = .ok
      (.move .w32 (.memory (s.gpr 1+3)) (.immediate 0) (s.pc+7)) := by
  have bytes : native.extract 44 51 = #[0xc7,0x41,0x03,0x00,0x00,0x00,0x00] := by decide
  rw [bytes]
  exact (X86.decode_simple_packet_tail s).2.2.1

theorem native_decode51 (s : X86.State) :
    X86.decode (native.extract 51 55) s = .ok
      (.move .w8 (.memory (s.gpr 1+7)) (.immediate 0) (s.pc+4)) := by
  have bytes : native.extract 51 55 = #[0xc6,0x41,0x07,0x00] := by decide
  rw [bytes]
  exact (X86.decode_simple_packet_tail s).2.2.2.1

theorem native_decode55 (s : X86.State) :
    X86.decode (native.extract 55 60) s = .ok
      (.move .w32 (.register (.low 0)) (.immediate 2) (s.pc+5)) := by
  have bytes : native.extract 55 60 = #[0xb8,0x02,0x00,0x00,0x00] := by decide
  rw [bytes]
  exact (X86.decode_simple_packet_tail s).2.2.2.2

/-- A one-byte memory store observes exactly the low byte, including wrap.
This is equality in the existing reference memory model, not a new ISA rule. -/
theorem store_byte_value_congr (m : Memory) (base first second : Word)
    (same : first.setWidth 8=second.setWidth 8) :
    storeMemory m base first 1 = storeMemory m base second 1 := by
  unfold storeMemory
  congr 1
  funext address
  by_cases inside : (address-base).toNat < 1
  · have zero : (address-base).toNat=0 := by omega
    simpa [inside,zero] using same
  · simp only [inside,ite_false]

theorem native_immediate_store_step (s : X86.State) (width : X86.ScalarWidth)
    (address value nextPC : Word)
    (permission : permitted s.memory.writable address width.bytes=true) :
    X86.step (.move width (.memory address) (.immediate value) nextPC) s =
      ⟨{s with memory := storeMemory s.memory address value width.bytes, pc := nextPC},
        [.memory .write address (valueBytes value width.bytes) true],none⟩ := by
  simp only [X86.step,X86.moveStep,X86.scalarRead,X86.scalarWrite,writeMemory,
    permission,ite_true,List.nil_append]

def packetNativeFirst (s : X86.State) : X86.State :=
  {s with memory := storeMemory s.memory (s.gpr 1) (24910#64) 2, pc := 40}

def packetNativeSecond (s : X86.State) : X86.State :=
  {packetNativeFirst s with
    memory := storeMemory (packetNativeFirst s).memory (s.gpr 1+(2#64)) (188#64) 1
    pc := 44}

def packetNativeThird (s : X86.State) : X86.State :=
  {packetNativeSecond s with
    memory := storeMemory (packetNativeSecond s).memory (s.gpr 1+(3#64)) (0#64) 4
    pc := 51}

def packetNativeFourth (s : X86.State) : X86.State :=
  {packetNativeThird s with
    memory := storeMemory (packetNativeThird s).memory (s.gpr 1+(7#64)) (0#64) 1
    pc := 55}

def packetNativeFinal (s : X86.State) : X86.State :=
  {packetNativeFourth s with gpr := fun r => if r=0 then (2#64) else s.gpr r, pc := 60}

theorem packet_native_first_step (s : X86.State)
    (permission : permitted s.memory.writable (s.gpr 1) 2=true) :
    X86.step (.move .w16 (.memory (s.gpr 1)) (.immediate (24910#64)) 40) s =
      ⟨packetNativeFirst s,[.memory .write (s.gpr 1) (valueBytes (24910#64) 2) true],none⟩ := by
  exact native_immediate_store_step s .w16 (s.gpr 1) (24910#64) 40 permission

theorem packet_native_second_step (s : X86.State)
    (permission : permitted s.memory.writable (s.gpr 1+(2#64)) 1=true) :
    X86.step (.move .w8 (.memory (s.gpr 1+(2#64))) (.immediate ((188#8).signExtend 64)) 44)
      (packetNativeFirst s) =
      ⟨packetNativeSecond s,[.memory .write (s.gpr 1+(2#64)) (valueBytes (188#64) 1) true],none⟩ := by
  have allowed : permitted (packetNativeFirst s).memory.writable (s.gpr 1+(2#64)) 1=true := permission
  have normalized : storeMemory (packetNativeFirst s).memory (s.gpr 1+(2#64)) ((188#8).signExtend 64) 1 =
      storeMemory (packetNativeFirst s).memory (s.gpr 1+(2#64)) (188#64) 1 :=
    store_byte_value_congr _ _ _ _ (by decide)
  have event : valueBytes ((188#8).signExtend 64) 1=valueBytes (188#64) 1 := by decide
  simpa only [X86.ScalarWidth.bytes,normalized,event,packetNativeSecond] using
    native_immediate_store_step (packetNativeFirst s) .w8 (s.gpr 1+(2#64)) ((188#8).signExtend 64) 44 allowed

theorem packet_native_third_step (s : X86.State)
    (permission : permitted s.memory.writable (s.gpr 1+(3#64)) 4=true) :
    X86.step (.move .w32 (.memory (s.gpr 1+(3#64))) (.immediate (0#64)) 51) (packetNativeSecond s) =
      ⟨packetNativeThird s,[.memory .write (s.gpr 1+(3#64)) (valueBytes (0#64) 4) true],none⟩ := by
  exact native_immediate_store_step (packetNativeSecond s) .w32 (s.gpr 1+(3#64)) (0#64) 51 permission

theorem packet_native_fourth_step (s : X86.State)
    (permission : permitted s.memory.writable (s.gpr 1+(7#64)) 1=true) :
    X86.step (.move .w8 (.memory (s.gpr 1+(7#64))) (.immediate (0#64)) 55) (packetNativeThird s) =
      ⟨packetNativeFourth s,[.memory .write (s.gpr 1+(7#64)) (valueBytes (0#64) 1) true],none⟩ := by
  exact native_immediate_store_step (packetNativeThird s) .w8 (s.gpr 1+(7#64)) (0#64) 55 permission

theorem packet_native_result_step (s : X86.State) :
    X86.step (.move .w32 (.register (.low 0)) (.immediate (2#64)) 60) (packetNativeFourth s) =
      ⟨packetNativeFinal s,[],none⟩ := by
  simp +decide [X86.step,X86.moveStep,X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes,
    packetNativeFinal,packetNativeFourth,packetNativeThird,packetNativeSecond,packetNativeFirst]


/-- All five actual tail instructions, including the four ordered guest
writes and the EAX write. Each extent and successor is checked by the decoder. -/
theorem native_packet_execution (s : X86.State) (position : s.pc=35)
    (write0 : permitted s.memory.writable (s.gpr 1) 2=true)
    (write2 : permitted s.memory.writable (s.gpr 1+(2#64)) 1=true)
    (write3 : permitted s.memory.writable (s.gpr 1+(3#64)) 4=true)
    (write7 : permitted s.memory.writable (s.gpr 1+(7#64)) 1=true) :
    X86Path.Execution 0 native s (packetWriteEvents (s.gpr 1)) (packetNativeFinal s) := by
  have d0 : X86Path.decodeAt 0 native ⟨35,5⟩ s = .ok
      (.move .w16 (.memory (s.gpr 1)) (.immediate (24910#64)) 40) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode35,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have pc1 : (packetNativeFirst s).pc=40 := rfl
  have pc2 : (packetNativeSecond s).pc=44 := rfl
  have pc3 : (packetNativeThird s).pc=51 := rfl
  have pc4 : (packetNativeFourth s).pc=55 := rfl
  have ptr1 : (packetNativeFirst s).gpr 1=s.gpr 1 := rfl
  have ptr2 : (packetNativeSecond s).gpr 1=s.gpr 1 := rfl
  have ptr3 : (packetNativeThird s).gpr 1=s.gpr 1 := rfl
  have d1 : X86Path.decodeAt 0 native ⟨40,4⟩ (packetNativeFirst s) = .ok
      (.move .w8 (.memory (s.gpr 1+(2#64))) (.immediate ((188#8).signExtend 64)) 44) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode40,pc1,ptr1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt 0 native ⟨44,7⟩ (packetNativeSecond s) = .ok
      (.move .w32 (.memory (s.gpr 1+(3#64))) (.immediate (0#64)) 51) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode44,pc2,ptr2,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d3 : X86Path.decodeAt 0 native ⟨51,4⟩ (packetNativeThird s) = .ok
      (.move .w8 (.memory (s.gpr 1+(7#64))) (.immediate (0#64)) 55) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode51,pc3,ptr3,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d4 : X86Path.decodeAt 0 native ⟨55,5⟩ (packetNativeFourth s) = .ok
      (.move .w32 (.register (.low 0)) (.immediate (2#64)) 60) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode55,pc4,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have evaluated : X86Path.evaluate 0 native [⟨35,5⟩,⟨40,4⟩,⟨44,7⟩,⟨51,4⟩,⟨55,5⟩] s =
      .ok ⟨⟨packetNativeFinal s,packetWriteEvents (s.gpr 1),none⟩,(0xffffffffffffffff#64)⟩ := by
    simp only [X86Path.evaluate,d0,d1,d2,d3,d4,packet_native_first_step s write0,
      packet_native_second_step s write2,packet_native_third_step s write3,
      packet_native_fourth_step s write7,packet_native_result_step,X86.definedFlags,
      Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,
      List.nil_append,List.cons_append,List.append_nil,ite_false,packetWriteEvents]
    rfl
  exact X86Path.evaluate_sound _ _ _ _ _ evaluated

/-- Equal actual writes preserve the previously proved private-footprint
relation. Guest values, initialization and global permissions all remain related. -/
theorem initialization_store_agrees {frame : Word} {first second : Memory}
    (same : initializationAgreesOutside frame first second) (base value : Word) (count : Nat) :
    initializationAgreesOutside frame (storeMemory first base value count) (storeMemory second base value count) := by
  refine ⟨same.1,same.2.1,?_⟩
  intro address outside
  by_cases inside : (address-base).toNat < count
  · simp only [storeMemory,inside,ite_true]
    trivial
  · simpa only [storeMemory,inside,ite_false] using same.2.2 address outside

theorem packet_memory_agrees (frame : Word) (first second : Memory) (pointer : Word)
    (same : initializationAgreesOutside frame first second) :
    initializationAgreesOutside frame (packetWriteMemory first pointer) (packetWriteMemory second pointer) := by
  unfold packetWriteMemory
  apply initialization_store_agrees
  apply initialization_store_agrees
  apply initialization_store_agrees
  apply initialization_store_agrees
  exact same

/-- The actual native tail and the actual accepted B tail through EXIT,
including identical ordered guest effects, related memories and return value.
Writable premises describe successful stores; no guest event is projected away. -/
theorem packet_body_correspondence (env : BPF.Environment) (frame : Word) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=35) (proofPC : p.pc=18) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2)
    (same : initializationAgreesOutside frame n.memory p.memory)
    (write0 : permitted p.memory.writable (p.regs 2) 2=true)
    (write2 : permitted p.memory.writable (p.regs 2+(2#64)) 1=true)
    (write3 : permitted p.memory.writable (p.regs 2+(3#64)) 4=true)
    (write7 : permitted p.memory.writable (p.regs 2+(7#64)) 1=true) :
    X86Path.Execution 0 native n (packetWriteEvents (p.regs 2)) (packetNativeFinal n) ∧
    Execution (initializedInstructionStep env) p (packetWriteEvents (p.regs 2))
      (proofExitFinal (packetProofFinal p)) ∧
    initializationAgreesOutside frame (packetNativeFinal n).memory
      (proofExitFinal (packetProofFinal p)).memory ∧
    (packetNativeFinal n).gpr 0 = (proofExitFinal (packetProofFinal p)).regs 0 ∧
    (packetNativeFinal n).pc=60 ∧ (proofExitFinal (packetProofFinal p)).halted=true := by
  have nwrite0 : permitted n.memory.writable (n.gpr 1) 2=true := by
    simpa only [same.2.1,pointer] using write0
  have nwrite2 : permitted n.memory.writable (n.gpr 1+(2#64)) 1=true := by
    simpa only [same.2.1,pointer] using write2
  have nwrite3 : permitted n.memory.writable (n.gpr 1+(3#64)) 4=true := by
    simpa only [same.2.1,pointer] using write3
  have nwrite7 : permitted n.memory.writable (n.gpr 1+(7#64)) 1=true := by
    simpa only [same.2.1,pointer] using write7
  obtain ⟨prun,halted,result⟩ := packet_proof_return env p proofPC active write0 write2 write3 write7
  refine ⟨?_,prun,?_,?_,rfl,halted⟩
  · simpa only [pointer] using native_packet_execution n nativePC nwrite0 nwrite2 nwrite3 nwrite7
  · change initializationAgreesOutside frame (packetWriteMemory n.memory (n.gpr 1))
      (packetWriteMemory p.memory (p.regs 2))
    rw [pointer]
    exact packet_memory_agrees frame n.memory p.memory (p.regs 2) same
  · rw [result]
    simp +decide [packetNativeFinal]


def conditionalNativeFinal (n : X86.State) (pointer limit : Word) : X86.State :=
  if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit
    then guardedNativeFinal n pointer limit else packetNativeFinal (guardedNativeFinal n pointer limit)

def conditionalProofFinal (p : BPF.State) (pointer limit stack : Word) : BPF.State :=
  if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit
    then proofExitFinal (guardedProofFinal p pointer limit stack)
    else proofExitFinal (packetProofFinal (guardedProofFinal p pointer limit stack))

def conditionalGuestSuffix (pointer limit : Word) : List Event :=
  if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit
    then [] else packetWriteEvents pointer

/-- Complete captured payload/proof executions for successful context and
private-stack accesses, with writable premises only when the write path is
taken. Private projection applies to the initializer prefix alone; every
packet event is retained, including possible address aliases. -/
theorem conditional_complete_payload_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
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
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ∀ i < 8, ¬ initializationPrivateByte (p.regs 10)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i))
    (writeBody : ¬ (pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit) →
      permitted p.memory.writable pointer 2=true ∧
      permitted p.memory.writable (pointer+(2#64)) 1=true ∧
      permitted p.memory.writable (pointer+(3#64)) 4=true ∧
      permitted p.memory.writable (pointer+(7#64)) 1=true) :
    X86Path.Execution 0 native n ([first,second]++conditionalGuestSuffix pointer limit)
      (conditionalNativeFinal n pointer limit) ∧
    Execution (initializedInstructionStep env) p
      ((prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit) ++
        conditionalGuestSuffix pointer limit) (conditionalProofFinal p pointer limit stack) ∧
    ((prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10))) ++ conditionalGuestSuffix pointer limit =
      [first,second]++conditionalGuestSuffix pointer limit ∧
    initializationAgreesOutside (p.regs 10) (conditionalNativeFinal n pointer limit).memory
      (conditionalProofFinal p pointer limit stack).memory ∧
    (conditionalNativeFinal n pointer limit).gpr 0=(conditionalProofFinal p pointer limit stack).regs 0 ∧
    (conditionalNativeFinal n pointer limit).pc=60 ∧
    (conditionalProofFinal p pointer limit stack).halted=true := by
  obtain ⟨nrun,prun,trace,npc,ppc,memoryMatch,npointer,nzero,ppointer,pzero⟩ :=
    entry_all_guards_correspondence env n p pointer limit stack first second nativePC proofPC active
      context memory nativeStack read0 read1 write40 write32 write24 write16 write8 read40 read32 guest0 guest1
  let n1 := guardedNativeFinal n pointer limit
  let p1 := guardedProofFinal p pointer limit stack
  change n1.gpr 0=(0#64) at nzero
  change p1.regs 2=pointer at ppointer
  change p1.regs 1=(0#64) at pzero
  have writable : p1.memory.writable=p.memory.writable := by
    dsimp only [p1,guardedProofFinal,remainingProofFinal]
    split
    · rfl
    · split <;> rfl
  have sameHalted : p1.halted=p.halted := by
    dsimp only [p1,guardedProofFinal,remainingProofFinal]
    split
    · rfl
    · split <;> rfl
  have stillActive : p1.halted=false := sameHalted.trans active
  have projection := congrArg (fun events => events++conditionalGuestSuffix pointer limit) trace
  by_cases reject : pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit
  · have at34 : p1.pc=34 := by simpa only [reject,ite_true] using ppc
    have exitRun := proof_exit_execution env p1 at34 stillActive
    refine ⟨?_,?_,projection,?_,?_,?_,?_⟩
    · simpa only [conditionalNativeFinal,conditionalGuestSuffix,reject,ite_true,List.append_nil] using nrun
    · simpa only [conditionalProofFinal,conditionalGuestSuffix,reject,ite_true,List.append_nil] using prun.append exitRun
    · simpa only [conditionalNativeFinal,conditionalProofFinal,reject,ite_true,proofExitFinal,BPF.setReg] using memoryMatch
    · simp only [conditionalNativeFinal,conditionalProofFinal,reject,ite_true]
      change n1.gpr 0=(proofExitFinal p1).regs 0
      simpa +decide [proofExitFinal,BPF.setReg,pzero] using nzero
    · simpa only [conditionalNativeFinal,reject,ite_true] using npc
    · simp only [conditionalProofFinal,reject,ite_true,proofExitFinal]
  · have at35 : n1.pc=35 := by simpa only [reject,ite_false] using npc
    have at18 : p1.pc=18 := by simpa only [reject,ite_false] using ppc
    have storePointer : n1.gpr 1=p1.regs 2 := npointer.trans ppointer.symm
    obtain ⟨w0,w2,w3,w7⟩ := writeBody reject
    have pw0 : permitted p1.memory.writable (p1.regs 2) 2=true := by
      simpa only [writable,ppointer] using w0
    have pw2 : permitted p1.memory.writable (p1.regs 2+(2#64)) 1=true := by
      simpa only [writable,ppointer] using w2
    have pw3 : permitted p1.memory.writable (p1.regs 2+(3#64)) 4=true := by
      simpa only [writable,ppointer] using w3
    have pw7 : permitted p1.memory.writable (p1.regs 2+(7#64)) 1=true := by
      simpa only [writable,ppointer] using w7
    obtain ⟨nbody,pbody,finalMemory,returnMatch,donePC,doneHalted⟩ :=
      packet_body_correspondence env (p.regs 10) n1 p1 at35 at18 stillActive storePointer memoryMatch pw0 pw2 pw3 pw7
    refine ⟨?_,?_,projection,?_,?_,?_,?_⟩
    · simpa only [conditionalNativeFinal,conditionalGuestSuffix,reject,ite_false,ppointer] using
        native_execution_append nrun nbody
    · simpa only [conditionalProofFinal,conditionalGuestSuffix,reject,ite_false,ppointer] using prun.append pbody
    · simpa only [conditionalNativeFinal,conditionalProofFinal,reject,ite_false] using finalMemory
    · simpa only [conditionalNativeFinal,conditionalProofFinal,reject,ite_false] using returnMatch
    · simpa only [conditionalNativeFinal,reject,ite_false] using donePC
    · simpa only [conditionalProofFinal,reject,ite_false] using doneHalted


theorem native_immediate_store_fault (s : X86.State) (width : X86.ScalarWidth)
    (address value nextPC : Word)
    (permission : permitted s.memory.writable address width.bytes=false) :
    X86.step (.move width (.memory address) (.immediate value) nextPC) s =
      ⟨s,[.fault (.write address width.bytes)],some (.write address width.bytes)⟩ := by
  simp only [X86.step,X86.moveStep,X86.scalarRead,X86.scalarWrite,writeMemory,
    permission,Bool.false_eq_true,ite_false,List.nil_append]

def packetProofBeforeFirst (p : BPF.State) : BPF.State :=
  {BPF.setReg (BPF.setReg (BPF.setReg p 1 (0#64)) 3 (p.regs 2)) 4 (24910#64) with pc := 22}

/-- The failed first guest store produces the actual fault, with no write,
no PC advancement and no later instruction in the checked path. -/
theorem packet_proof_first_fault_block (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=18) (active : p.halted=false)
    (bad : permitted p.memory.writable (p.regs 2) 2=false) :
    BPFPath.evaluate env proof [18,19,20,21,22] p =
      .ok ⟨packetProofBeforeFirst p,[.fault (.write (p.regs 2) 2)],some (.write (p.regs 2) 2)⟩ := by
  simp +decide [BPFPath.evaluate,virtual_decode18,virtual_decode19,virtual_decode20,
    virtual_decode21,virtual_decode22,BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,
    writeMemory,position,active,bad,packetProofBeforeFirst,
    Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  funext index
  by_cases one : index=1 <;> by_cases three : index=3 <;> by_cases four : index=4 <;>
    simp [one,three,four]

theorem packet_proof_first_fault (env : BPF.Environment) (p : BPF.State)
    (position : p.pc=18) (active : p.halted=false)
    (bad : permitted p.memory.writable (p.regs 2) 2=false) :
    Execution (initializedInstructionStep env) p [.fault (.write (p.regs 2) 2)] (packetProofBeforeFirst p) := by
  exact ordinary_path_execution env [18,19,20,21,22] p
    ⟨packetProofBeforeFirst p,[.fault (.write (p.regs 2) 2)],some (.write (p.regs 2) 2)⟩
    (by intro pc inside; simp at inside; omega) (packet_proof_first_fault_block env p position active bad)

theorem packet_native_first_fault (s : X86.State) (position : s.pc=35)
    (bad : permitted s.memory.writable (s.gpr 1) 2=false) :
    X86Path.Execution 0 native s [.fault (.write (s.gpr 1) 2)] s := by
  have decoded : X86Path.decodeAt 0 native ⟨35,5⟩ s = .ok
      (.move .w16 (.memory (s.gpr 1)) (.immediate (24910#64)) 40) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode35,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have step := native_immediate_store_fault s .w16 (s.gpr 1) (24910#64) 40 bad
  have run := X86Path.Execution.next ⟨35,5⟩ _ decoded
    (X86Path.Execution.refl (X86.step (.move .w16 (.memory (s.gpr 1)) (.immediate (24910#64)) 40) s).state)
  rw [step] at run
  simpa only [List.append_nil] using run

/-- Model-only failed-access correspondence; no unsafe native execution is
run. The actual first fault is retained and both memories stay related. -/
theorem first_store_fault_correspondence (env : BPF.Environment) (frame : Word) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=35) (proofPC : p.pc=18) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (same : initializationAgreesOutside frame n.memory p.memory)
    (bad : permitted p.memory.writable (p.regs 2) 2=false) :
    X86Path.Execution 0 native n [.fault (.write (p.regs 2) 2)] n ∧
    Execution (initializedInstructionStep env) p [.fault (.write (p.regs 2) 2)] (packetProofBeforeFirst p) ∧
    initializationAgreesOutside frame n.memory (packetProofBeforeFirst p).memory := by
  have nbad : permitted n.memory.writable (n.gpr 1) 2=false := by
    simpa only [same.2.1,pointer] using bad
  refine ⟨?_,packet_proof_first_fault env p proofPC active bad,same⟩
  simpa only [pointer] using packet_native_first_fault n nativePC nbad


/-- Concrete captured store descriptors; permissions are those of the same
canonical memory, not checks inserted into either artifact. -/
def packetStorePermission (m : Memory) (pointer : Word) : Nat → Bool
  | 0 => permitted m.writable pointer 2
  | 1 => permitted m.writable (pointer+(2#64)) 1
  | 2 => permitted m.writable (pointer+(3#64)) 4
  | _ => permitted m.writable (pointer+(7#64)) 1

def packetStoreFault (pointer : Word) : Nat → Fault
  | 0 => .write pointer 2
  | 1 => .write (pointer+(2#64)) 1
  | 2 => .write (pointer+(3#64)) 4
  | _ => .write (pointer+(7#64)) 1

def packetStoredPrefix (m : Memory) (pointer : Word) : Nat → Memory
  | 0 => m
  | 1 => storeMemory m pointer (24910#64) 2
  | 2 => storeMemory (storeMemory m pointer (24910#64) 2) (pointer+(2#64)) (188#64) 1
  | _ => storeMemory (storeMemory (storeMemory m pointer (24910#64) 2)
      (pointer+(2#64)) (188#64) 1) (pointer+(3#64)) (0#64) 4

def packetFaultEvents (pointer : Word) (index : Nat) : List Event :=
  (packetWriteEvents pointer).take index ++ [.fault (packetStoreFault pointer index)]

def packetProofFaultState (p : BPF.State) : Nat → BPF.State
  | 0 => packetProofBeforeFirst p
  | 1 => {BPF.setReg (BPF.setReg (BPF.setReg p 1 (0#64)) 3 (p.regs 2+(2#64))) 4 (188#64) with
      memory := packetStoredPrefix p.memory (p.regs 2) 1, pc := 26}
  | 2 => {BPF.setReg (BPF.setReg (BPF.setReg p 1 (0#64)) 3 (p.regs 2+(3#64))) 4 (188#64) with
      memory := packetStoredPrefix p.memory (p.regs 2) 2, pc := 29}
  | _ => {BPF.setReg (BPF.setReg (BPF.setReg p 1 (0#64)) 3 (p.regs 2+(7#64))) 4 (188#64) with
      memory := packetStoredPrefix p.memory (p.regs 2) 3, pc := 32}

def packetNativeFaultState (s : X86.State) : Nat → X86.State
  | 0 => s
  | 1 => packetNativeFirst s
  | 2 => packetNativeSecond s
  | _ => packetNativeThird s

def packetProofFaultPath : Nat → List Nat
  | 0 => [18,19,20,21,22]
  | 1 => [18,19,20,21,22,23,24,25,26]
  | 2 => [18,19,20,21,22,23,24,25,26,27,28,29]
  | _ => [18,19,20,21,22,23,24,25,26,27,28,29,30,31,32]

def packetNativeFaultPath : Nat → List X86Path.Entry
  | 0 => [⟨35,5⟩]
  | 1 => [⟨35,5⟩,⟨40,4⟩]
  | 2 => [⟨35,5⟩,⟨40,4⟩,⟨44,7⟩]
  | _ => [⟨35,5⟩,⟨40,4⟩,⟨44,7⟩,⟨51,4⟩]

/-- Every possible first failing packet store stops the actual B path at its
faulting instruction; all successful earlier writes and values are retained. -/
theorem packet_all_store_fault_blocks (env : BPF.Environment) (p : BPF.State) (index : Nat)
    (bounded : index<4) (position : p.pc=18) (active : p.halted=false)
    (prior : ∀ i<index, packetStorePermission p.memory (p.regs 2) i=true)
    (bad : packetStorePermission p.memory (p.regs 2) index=false) :
    BPFPath.evaluate env proof (packetProofFaultPath index) p =
      .ok ⟨packetProofFaultState p index,packetFaultEvents (p.regs 2) index,
        some (packetStoreFault (p.regs 2) index)⟩ := by
  have plus2 : (2#64)+p.regs 2=p.regs 2+(2#64) := BitVec.add_comm _ _
  have plus3 : (3#64)+p.regs 2=p.regs 2+(3#64) := BitVec.add_comm _ _
  have plus7 : (7#64)+p.regs 2=p.regs 2+(7#64) := BitVec.add_comm _ _
  have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
  rcases choices with rfl | rfl | rfl | rfl
  · simpa only [packetProofFaultPath,packetProofFaultState,packetFaultEvents,
      packetWriteEvents,packetStoreFault,List.take_zero,List.nil_append] using
      packet_proof_first_fault_block env p position active bad
  · have w0 := prior 0 (by omega)
    simp only [packetStorePermission] at w0 bad
    simp +decide [BPFPath.evaluate,virtual_decode18,virtual_decode19,virtual_decode20,
      virtual_decode21,virtual_decode22,virtual_decode23,virtual_decode24,virtual_decode25,
      virtual_decode26,virtual_decode27,virtual_decode28,virtual_decode29,virtual_decode30,
      virtual_decode31,virtual_decode32,BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,
      writeMemory,position,active,packetProofFaultPath,packetProofFaultState,packetStoredPrefix,
      packetFaultEvents,packetStoreFault,packetWriteEvents,storeMemory,
      plus2,plus3,plus7,w0,bad,
      Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    funext r
    by_cases one : r=1 <;> by_cases three : r=3 <;> by_cases four : r=4 <;>
      simp [one,three,four]
  · have w0 := prior 0 (by omega)
    have w1 := prior 1 (by omega)
    simp only [packetStorePermission] at w0 w1 bad
    simp +decide [BPFPath.evaluate,virtual_decode18,virtual_decode19,virtual_decode20,
      virtual_decode21,virtual_decode22,virtual_decode23,virtual_decode24,virtual_decode25,
      virtual_decode26,virtual_decode27,virtual_decode28,virtual_decode29,virtual_decode30,
      virtual_decode31,virtual_decode32,BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,
      writeMemory,position,active,packetProofFaultPath,packetProofFaultState,packetStoredPrefix,
      packetFaultEvents,packetStoreFault,packetWriteEvents,storeMemory,
      plus2,plus3,plus7,w0,w1,bad,
      Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    funext r
    by_cases one : r=1 <;> by_cases three : r=3 <;> by_cases four : r=4 <;>
      simp [one,three,four]
  · have w0 := prior 0 (by omega)
    have w1 := prior 1 (by omega)
    have w2 := prior 2 (by omega)
    simp only [packetStorePermission] at w0 w1 w2 bad
    simp +decide [BPFPath.evaluate,virtual_decode18,virtual_decode19,virtual_decode20,
      virtual_decode21,virtual_decode22,virtual_decode23,virtual_decode24,virtual_decode25,
      virtual_decode26,virtual_decode27,virtual_decode28,virtual_decode29,virtual_decode30,
      virtual_decode31,virtual_decode32,BPF.execute,BPF.source,BPF.alu,BPF.setReg,BPF.store,
      writeMemory,position,active,packetProofFaultPath,packetProofFaultState,packetStoredPrefix,
      packetFaultEvents,packetStoreFault,packetWriteEvents,storeMemory,
      plus2,plus3,plus7,w0,w1,w2,bad,
      Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    funext r
    by_cases one : r=1 <;> by_cases three : r=3 <;> by_cases four : r=4 <;>
      simp [one,three,four]

/-- All four actual native store instruction extents, each decoded from the
same captured artifact and the full partial state after preceding stores. -/
theorem packet_native_store_decodes (s : X86.State) (position : s.pc=35) :
    X86Path.decodeAt 0 native ⟨35,5⟩ s = .ok
      (.move .w16 (.memory (s.gpr 1)) (.immediate (24910#64)) 40) ∧
    X86Path.decodeAt 0 native ⟨40,4⟩ (packetNativeFirst s) = .ok
      (.move .w8 (.memory (s.gpr 1+(2#64))) (.immediate ((188#8).signExtend 64)) 44) ∧
    X86Path.decodeAt 0 native ⟨44,7⟩ (packetNativeSecond s) = .ok
      (.move .w32 (.memory (s.gpr 1+(3#64))) (.immediate (0#64)) 51) ∧
    X86Path.decodeAt 0 native ⟨51,4⟩ (packetNativeThird s) = .ok
      (.move .w8 (.memory (s.gpr 1+(7#64))) (.immediate (0#64)) 55) := by
  refine ⟨?_,?_,?_,?_⟩
  all_goals simp +decide [X86Path.decodeAt,native_size,native_decode35,native_decode40,
    native_decode44,native_decode51,position,packetNativeFirst,packetNativeSecond,packetNativeThird,
    X86Path.fallthrough,X86.Instruction.fallthrough,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Native first-fault evaluation, including exact writes before the failure.
No byte store occurs at or after the failed access. -/
theorem packet_all_native_store_faults (s : X86.State) (index : Nat)
    (bounded : index<4) (position : s.pc=35)
    (prior : ∀ i<index, packetStorePermission s.memory (s.gpr 1) i=true)
    (bad : packetStorePermission s.memory (s.gpr 1) index=false) :
    X86Path.evaluate 0 native (packetNativeFaultPath index) s =
      .ok ⟨⟨packetNativeFaultState s index,packetFaultEvents (s.gpr 1) index,
        some (packetStoreFault (s.gpr 1) index)⟩,(0xffffffffffffffff#64)⟩ := by
  obtain ⟨d0,d1,d2,d3⟩ := packet_native_store_decodes s position
  have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
  rcases choices with rfl | rfl | rfl | rfl
  · have fault := native_immediate_store_fault s .w16 (s.gpr 1) (24910#64) 40 bad
    simp only [packetNativeFaultPath,packetNativeFaultState,packetFaultEvents,packetWriteEvents,
      packetStoreFault,X86Path.evaluate,d0,d1,d2,d3,fault,X86.definedFlags,
      Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,
      List.nil_append,List.cons_append,List.append_nil,ite_false,ite_true]
    rfl
  · have w0 := prior 0 (by omega)
    have fault := native_immediate_store_fault (packetNativeFirst s) .w8 (s.gpr 1+(2#64)) ((188#8).signExtend 64) 44 bad
    simp only [packetNativeFaultPath,packetNativeFaultState,packetFaultEvents,packetWriteEvents,
      packetStoreFault,X86Path.evaluate,d0,d1,d2,d3,packet_native_first_step s w0,fault,X86.definedFlags,
      Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,
      List.nil_append,List.cons_append,List.append_nil,ite_false,ite_true]
    rfl
  · have w0 := prior 0 (by omega)
    have w1 := prior 1 (by omega)
    have fault := native_immediate_store_fault (packetNativeSecond s) .w32 (s.gpr 1+(3#64)) (0#64) 51 bad
    simp only [packetNativeFaultPath,packetNativeFaultState,packetFaultEvents,packetWriteEvents,
      packetStoreFault,X86Path.evaluate,d0,d1,d2,d3,packet_native_first_step s w0,packet_native_second_step s w1,fault,X86.definedFlags,
      Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,
      List.nil_append,List.cons_append,List.append_nil,ite_false,ite_true]
    rfl
  · have w0 := prior 0 (by omega)
    have w1 := prior 1 (by omega)
    have w2 := prior 2 (by omega)
    have fault := native_immediate_store_fault (packetNativeThird s) .w8 (s.gpr 1+(7#64)) (0#64) 55 bad
    simp only [packetNativeFaultPath,packetNativeFaultState,packetFaultEvents,packetWriteEvents,
      packetStoreFault,X86Path.evaluate,d0,d1,d2,d3,packet_native_first_step s w0,packet_native_second_step s w1,packet_native_third_step s w2,fault,X86.definedFlags,
      Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,
      List.nil_append,List.cons_append,List.append_nil,ite_false,ite_true]
    rfl

/-- Native and B stop at the same first failed store with identical ordered
write/fault events and full partial memories, including initialization bits. -/
theorem all_store_fault_correspondence (env : BPF.Environment) (frame : Word)
    (n : X86.State) (p : BPF.State) (index : Nat)
    (bounded : index<4) (nativePC : n.pc=35) (proofPC : p.pc=18) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (same : initializationAgreesOutside frame n.memory p.memory)
    (prior : ∀ i<index, packetStorePermission p.memory (p.regs 2) i=true)
    (bad : packetStorePermission p.memory (p.regs 2) index=false) :
    X86Path.Execution 0 native n (packetFaultEvents (p.regs 2) index) (packetNativeFaultState n index) ∧
    Execution (initializedInstructionStep env) p (packetFaultEvents (p.regs 2) index) (packetProofFaultState p index) ∧
    initializationAgreesOutside frame (packetNativeFaultState n index).memory
      (packetProofFaultState p index).memory := by
  have permission : ∀ i, packetStorePermission n.memory (n.gpr 1) i =
      packetStorePermission p.memory (p.regs 2) i := by
    intro i
    simp only [packetStorePermission,same.2.1,pointer]
  have nativeEval := packet_all_native_store_faults n index bounded nativePC
    (by intro i lt; rw [permission]; exact prior i lt)
    (by rw [permission]; exact bad)
  have proofEval := packet_all_store_fault_blocks env p index bounded proofPC active prior bad
  refine ⟨?_,?_,?_⟩
  · simpa only [pointer] using X86Path.evaluate_sound _ _ _ _ _ nativeEval
  · apply ordinary_path_execution env (packetProofFaultPath index) p
      ⟨packetProofFaultState p index,packetFaultEvents (p.regs 2) index,
        some (packetStoreFault (p.regs 2) index)⟩ _ proofEval
    intro pc inside
    have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
    rcases choices with rfl | rfl | rfl | rfl <;> simp [packetProofFaultPath] at inside <;> omega
  · have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
    rcases choices with rfl | rfl | rfl | rfl
    · exact same
    · simpa only [packetNativeFaultState,packetProofFaultState,packetStoredPrefix,
        packetNativeFirst,pointer,BPF.setReg] using initialization_store_agrees same (p.regs 2) (24910#64) 2
    · simpa only [packetNativeFaultState,packetProofFaultState,packetStoredPrefix,
        packetNativeSecond,packetNativeFirst,pointer,BPF.setReg] using
        initialization_store_agrees (initialization_store_agrees same (p.regs 2) (24910#64) 2)
          (p.regs 2+(2#64)) (188#64) 1
    · simpa only [packetNativeFaultState,packetProofFaultState,packetStoredPrefix,
        packetNativeThird,packetNativeSecond,packetNativeFirst,pointer,BPF.setReg] using
        initialization_store_agrees (initialization_store_agrees
          (initialization_store_agrees same (p.regs 2) (24910#64) 2)
          (p.regs 2+(2#64)) (188#64) 1) (p.regs 2+(3#64)) (0#64) 4


/-- Proof-only description of the first failed actual store, or4 when all
four writes succeed. Neither artifact gains a runtime test. -/
def packetFirstFailure (m : Memory) (pointer : Word) : Nat :=
  if packetStorePermission m pointer 0 then
    if packetStorePermission m pointer 1 then
      if packetStorePermission m pointer 2 then
        if packetStorePermission m pointer 3 then 4 else 3
      else 2
    else 1
  else 0

/-- The actual canonical permissions determine one outcome; earlier writes
are successful and no permission is assumed for any later access. -/
theorem packet_first_failure_spec (m : Memory) (pointer : Word) :
    let index := packetFirstFailure m pointer
    index≤4 ∧
    (index<4 → (∀ i<index, packetStorePermission m pointer i=true) ∧
      packetStorePermission m pointer index=false) ∧
    (index=4 → ∀ i<4, packetStorePermission m pointer i=true) := by
  by_cases w0 : packetStorePermission m pointer 0=true <;>
    by_cases w1 : packetStorePermission m pointer 1=true <;>
    by_cases w2 : packetStorePermission m pointer 2=true <;>
    by_cases w3 : packetStorePermission m pointer 3=true
  all_goals simp_all [packetFirstFailure]
  all_goals
    intro i hi
    have choices : i=0 ∨ i=1 ∨ i=2 ∨ i=3 := by omega
    rcases choices with rfl | rfl | rfl | rfl <;> simp_all

theorem packet_failure_index_agrees {frame : Word} {n : X86.State} {p : BPF.State}
    (same : initializationAgreesOutside frame n.memory p.memory) (pointer : n.gpr 1=p.regs 2) :
    packetFirstFailure n.memory (n.gpr 1)=packetFirstFailure p.memory (p.regs 2) := by
  simp only [packetFirstFailure,packetStorePermission,same.2.1,pointer]

def packetNativeOutcome (n : X86.State) (index : Nat) : X86.State :=
  if index=4 then packetNativeFinal n else packetNativeFaultState n index

def packetProofOutcome (p : BPF.State) (index : Nat) : BPF.State :=
  if index=4 then proofExitFinal (packetProofFinal p) else packetProofFaultState p index

def packetOutcomeEvents (pointer : Word) (index : Nat) : List Event :=
  if index=4 then packetWriteEvents pointer else packetFaultEvents pointer index

/-- Total packet-body correspondence for every permission assignment. The
selection equation is computed from the existing canonical memory; it is not
a branch outcome premise or an added check in B/native execution. -/
theorem packet_body_any_permissions (env : BPF.Environment) (frame : Word)
    (n : X86.State) (p : BPF.State) (index : Nat)
    (nativePC : n.pc=35) (proofPC : p.pc=18) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (same : initializationAgreesOutside frame n.memory p.memory)
    (selected : index=packetFirstFailure p.memory (p.regs 2)) :
    index≤4 ∧
    X86Path.Execution 0 native n (packetOutcomeEvents (p.regs 2) index) (packetNativeOutcome n index) ∧
    Execution (initializedInstructionStep env) p (packetOutcomeEvents (p.regs 2) index) (packetProofOutcome p index) ∧
    initializationAgreesOutside frame (packetNativeOutcome n index).memory (packetProofOutcome p index).memory ∧
    (index=4 → (packetNativeOutcome n index).pc=60 ∧
      (packetProofOutcome p index).halted=true ∧
      (packetNativeOutcome n index).gpr 0=(packetProofOutcome p index).regs 0 ∧
      (packetNativeOutcome n index).gpr 0=(2#64)) := by
  have spec := packet_first_failure_spec p.memory (p.regs 2)
  change packetFirstFailure p.memory (p.regs 2)≤4 ∧ _ at spec
  rw [← selected] at spec
  by_cases success : index=4
  · have permissions := spec.2.2 success
    obtain ⟨nrun,prun,memory,returns,npc,halted⟩ :=
      packet_body_correspondence env frame n p nativePC proofPC active pointer same
        (permissions 0 (by omega)) (permissions 1 (by omega))
        (permissions 2 (by omega)) (permissions 3 (by omega))
    refine ⟨spec.1,?_,?_,?_,?_⟩
    · simpa only [packetOutcomeEvents,packetNativeOutcome,success,ite_true] using nrun
    · simpa only [packetOutcomeEvents,packetProofOutcome,success,ite_true] using prun
    · simpa only [packetNativeOutcome,packetProofOutcome,success,ite_true] using memory
    · intro _
      simp only [packetNativeOutcome,packetProofOutcome,success,ite_true]
      refine ⟨npc,halted,returns,?_⟩
      simp only [packetNativeFinal,packetNativeFourth,packetNativeThird,packetNativeSecond,packetNativeFirst,ite_true]
  · have failed : index<4 := by omega
    obtain ⟨prior,bad⟩ := spec.2.1 failed
    obtain ⟨nrun,prun,memory⟩ :=
      all_store_fault_correspondence env frame n p index failed nativePC proofPC active pointer same prior bad
    refine ⟨spec.1,?_,?_,?_,?_⟩
    · simpa only [packetOutcomeEvents,packetNativeOutcome,success,ite_false] using nrun
    · simpa only [packetOutcomeEvents,packetProofOutcome,success,ite_false] using prun
    · simpa only [packetNativeOutcome,packetProofOutcome,success,ite_false] using memory
    · intro wrong
      exact (success wrong).elim


/-- Concrete completed outcome, including a first guest-store fault. -/
def completeNativeFinal (n : X86.State) (pointer limit : Word) : X86.State :=
  if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then
    guardedNativeFinal n pointer limit
  else packetNativeOutcome (guardedNativeFinal n pointer limit) (packetFirstFailure n.memory pointer)

def completeProofFinal (p : BPF.State) (pointer limit stack : Word) : BPF.State :=
  if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then
    proofExitFinal (guardedProofFinal p pointer limit stack)
  else packetProofOutcome (guardedProofFinal p pointer limit stack) (packetFirstFailure p.memory pointer)

def completeGuestSuffix (m : Memory) (pointer limit : Word) : List Event :=
  if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then []
  else packetOutcomeEvents pointer (packetFirstFailure m pointer)

/-- One actual execution from entry through guard return, successful writes
and EXIT, or any of the four first store faults. No packet-write permission or
branch outcome premise is required. Entry/platform/private-frame premises are
explicit; this is not yet an unconditional artifact TranslationValidation. -/
theorem complete_all_store_outcomes_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (context : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second))
    (write40 : permitted p.memory.writable (p.regs 10-(40#64)) 8=true)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8=true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8=true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8=true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4=true)
    (read40 : permitted p.memory.readable (p.regs 10-(40#64)) 8=true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8=true)
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ∀ i<8, ¬ initializationPrivateByte (p.regs 10) (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    X86Path.Execution 0 native n ([first,second]++completeGuestSuffix p.memory pointer limit)
      (completeNativeFinal n pointer limit) ∧
    Execution (initializedInstructionStep env) p
      ((prefixEvents p pointer first second++initializationEvents (p.regs 10) pointer limit)++
        completeGuestSuffix p.memory pointer limit) (completeProofFinal p pointer limit stack) ∧
    ((prefixEvents p pointer first second++initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)))++completeGuestSuffix p.memory pointer limit =
      [first,second]++completeGuestSuffix p.memory pointer limit ∧
    initializationAgreesOutside (p.regs 10) (completeNativeFinal n pointer limit).memory
      (completeProofFinal p pointer limit stack).memory ∧
    ((pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit) ∨
      packetFirstFailure p.memory pointer=4 →
      (completeNativeFinal n pointer limit).pc=60 ∧
      (completeProofFinal p pointer limit stack).halted=true ∧
      (completeNativeFinal n pointer limit).gpr 0=(completeProofFinal p pointer limit stack).regs 0) := by
  obtain ⟨nrun,prun,trace,npc,ppc,memoryMatch,npointer,nzero,ppointer,pzero⟩ :=
    entry_all_guards_correspondence env n p pointer limit stack first second nativePC proofPC active
      context memory nativeStack read0 read1 write40 write32 write24 write16 write8 read40 read32 guest0 guest1
  let n1 := guardedNativeFinal n pointer limit
  let p1 := guardedProofFinal p pointer limit stack
  change n1.gpr 0=(0#64) at nzero
  change p1.regs 2=pointer at ppointer
  change p1.regs 1=(0#64) at pzero
  have writable : p1.memory.writable=p.memory.writable := by
    dsimp only [p1,guardedProofFinal,remainingProofFinal]
    split
    · rfl
    · split <;> rfl
  have sameHalted : p1.halted=p.halted := by
    dsimp only [p1,guardedProofFinal,remainingProofFinal]
    split
    · rfl
    · split <;> rfl
  have stillActive : p1.halted=false := sameHalted.trans active
  have nativeIndex : packetFirstFailure n.memory pointer=packetFirstFailure p.memory pointer := by
    rw [memory]
  have selected : packetFirstFailure p.memory pointer=packetFirstFailure p1.memory (p1.regs 2) := by
    simp only [packetFirstFailure,packetStorePermission,writable,ppointer]
  have projection := congrArg (fun events => events++completeGuestSuffix p.memory pointer limit) trace
  by_cases reject : pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit
  · have at34 : p1.pc=34 := by simpa only [reject,ite_true] using ppc
    have exitRun := proof_exit_execution env p1 at34 stillActive
    refine ⟨?_,?_,projection,?_,?_⟩
    · simpa only [completeNativeFinal,completeGuestSuffix,reject,ite_true,List.append_nil] using nrun
    · simpa only [completeProofFinal,completeGuestSuffix,reject,ite_true,List.append_nil] using prun.append exitRun
    · simpa only [completeNativeFinal,completeProofFinal,reject,ite_true,proofExitFinal,BPF.setReg] using memoryMatch
    · intro _
      simp only [completeNativeFinal,completeProofFinal,reject,ite_true]
      refine ⟨?_,rfl,?_⟩
      · simpa only [reject,ite_true] using npc
      · change n1.gpr 0=(proofExitFinal p1).regs 0
        simpa +decide [proofExitFinal,BPF.setReg,pzero] using nzero
  · have at35 : n1.pc=35 := by simpa only [reject,ite_false] using npc
    have at18 : p1.pc=18 := by simpa only [reject,ite_false] using ppc
    have storePointer : n1.gpr 1=p1.regs 2 := npointer.trans ppointer.symm
    obtain ⟨bounded,nbody,pbody,finalMemory,returned⟩ :=
      packet_body_any_permissions env (p.regs 10) n1 p1 (packetFirstFailure p.memory pointer)
        at35 at18 stillActive storePointer memoryMatch selected
    refine ⟨?_,?_,projection,?_,?_⟩
    · simpa only [completeNativeFinal,completeGuestSuffix,reject,ite_false,nativeIndex,ppointer] using
        native_execution_append nrun nbody
    · simpa only [completeProofFinal,completeGuestSuffix,reject,ite_false,ppointer] using prun.append pbody
    · simpa only [completeNativeFinal,completeProofFinal,reject,ite_false,nativeIndex] using finalMemory
    · intro finished
      have success : packetFirstFailure p.memory pointer=4 := finished.resolve_left reject
      obtain ⟨donePC,doneHalted,returnMatch,_⟩ := returned success
      simpa only [completeNativeFinal,completeProofFinal,reject,ite_false,nativeIndex] using
        And.intro donePC (And.intro doneHalted returnMatch)


/-- A failed canonical source read commits no destination or PC change. -/
theorem native_memory_source_fault (s : X86.State) (destination : X86.ScalarDestination)
    (address nextPC : Word) (bad : permitted s.memory.readable address 8=false) :
    X86.step (.move .w64 destination (.memory address) nextPC) s =
      ⟨s,[.fault (.read address 8)],some (.read address 8)⟩ := by
  simp only [X86.step,X86.moveStep,X86.scalarRead,X86.readSource,X86.ScalarWidth.bytes,
    readMemory,bad,Bool.false_eq_true,ite_false]

/-- Actual captured context conversions preserve a first or second read fault
at the virtual PC. Arbitrary B environments cannot supply an invented value. -/
theorem initialized_context_load_fault (env : BPF.Environment) (p : BPF.State) (address : Word)
    (position : (p.pc=0 ∧ address=p.regs 1) ∨ (p.pc=2 ∧ address=p.regs 1+(8#64)))
    (active : p.halted=false) (bad : permitted p.memory.readable address 8=false) :
    BPFPlatform.step (initializedPlatform env) proof p =
      .ok ⟨p,[.fault (.read address 8)],some (.read address 8)⟩ := by
  have entry : p.pc=0 ∨ p.pc=1 ∨ p.pc=2 := by rcases position with h | h; exact Or.inl h.1; exact Or.inr (Or.inr h.1)
  rw [entry_environment_independent env p entry]
  rcases position with ⟨position,rfl⟩ | ⟨position,rfl⟩
  all_goals simp +decide [BPFPlatform.step,platform,active,position,virtual_decode0,
    BPFPlatform.expand,expansion0,expansion2,BPFPath.evaluate,physical0,physical2,
    BPF.decode,proof,BPF.execute,BPF.load,BPF.setReg,readMemory,bad,littleEndian,
    Except.bind,Except.map,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  all_goals cases p <;> simp_all

theorem native_first_context_fault (s : X86.State) (position : s.pc=0)
    (bad : permitted s.memory.readable (s.gpr 7) 8=false) :
    X86Path.Execution 0 native s [.fault (.read (s.gpr 7) 8)] s := by
  have decoded : X86Path.decodeAt 0 native ⟨0,3⟩ s = .ok
      (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc+(3#64))) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode0,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have step := native_memory_source_fault s (.register (.low 1)) (s.gpr 7) (s.pc+(3#64)) bad
  have run := X86Path.Execution.next ⟨0,3⟩ _ decoded
    (X86Path.Execution.refl (X86.step
      (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc+(3#64))) s).state)
  rw [step] at run
  simpa only [List.append_nil] using run

theorem native_second_context_fault (s : X86.State) (position : s.pc=3)
    (bad : permitted s.memory.readable (s.gpr 7+(8#64)) 8=false) :
    X86Path.Execution 0 native s [.fault (.read (s.gpr 7+(8#64)) 8)] s := by
  have decoded : X86Path.decodeAt 0 native ⟨3,4⟩ s = .ok
      (.move .w64 (.register (.low 2)) (.memory (s.gpr 7+(8#64))) (s.pc+(4#64))) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode3,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have step := native_memory_source_fault s (.register (.low 2)) (s.gpr 7+(8#64)) (s.pc+(4#64)) bad
  have run := X86Path.Execution.next ⟨3,4⟩ _ decoded
    (X86Path.Execution.refl (X86.step
      (.move .w64 (.register (.low 2)) (.memory (s.gpr 7+(8#64))) (s.pc+(4#64))) s).state)
  rw [step] at run
  simpa only [List.append_nil] using run

/-- First entry read fails in both actual artifacts before any spill. -/
theorem first_context_fault_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (context : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (bad : permitted p.memory.readable (p.regs 1) 8=false) :
    X86Path.Execution 0 native n [.fault (.read (p.regs 1) 8)] n ∧
    Execution (initializedInstructionStep env) p [.fault (.read (p.regs 1) 8)] p ∧
    n.memory=p.memory := by
  have nbad : permitted n.memory.readable (n.gpr 7) 8=false := by simpa only [memory,context] using bad
  have step : initializedInstructionStep env p [.fault (.read (p.regs 1) 8)] p :=
    ⟨⟨p,[.fault (.read (p.regs 1) 8)],some (.read (p.regs 1) 8)⟩,
      initialized_context_load_fault env p (p.regs 1) (Or.inl ⟨proofPC,rfl⟩) active bad,rfl,rfl⟩
  refine ⟨?_,?_,memory⟩
  · simpa only [context] using native_first_context_fault n nativePC nbad
  · simpa only [List.append_nil] using Execution.next step (Execution.refl p)

/-- Second read failure retains the first actual read and B's first spill;
only that certified private spill is erased, never the read or fault. -/
theorem second_context_fault_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer : Word) (first : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (context : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (write40 : permitted p.memory.writable (p.regs 10-(40#64)) 8=true)
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (bad : permitted p.memory.readable (p.regs 1+(8#64)) 8=false) :
    X86Path.Execution 0 native n [first,.fault (.read (p.regs 1+(8#64)) 8)] (nativeAfter n pointer) ∧
    Execution (initializedInstructionStep env) p
      [first,.memory .write (p.regs 10-(40#64)) (valueBytes pointer 8) true,
        .fault (.read (p.regs 1+(8#64)) 8)] (afterSpill p pointer) ∧
    ([first,.memory .write (p.regs 10-(40#64)) (valueBytes pointer 8) true,
        .fault (.read (p.regs 1+(8#64)) 8)].filterMap (initializationProjectEvent (p.regs 10))) =
      [first,.fault (.read (p.regs 1+(8#64)) 8)] ∧
    initializationAgreesOutside (p.regs 10) (nativeAfter n pointer).memory (afterSpill p pointer).memory := by
  have nativeRead : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by simpa only [memory,context] using read0
  have nread := native_entry_execution n pointer first nativePC nativeRead
  have at3 : (nativeAfter n pointer).pc=3 := by simp only [nativeAfter,nativePC]; rfl
  have nativeBad : permitted (nativeAfter n pointer).memory.readable ((nativeAfter n pointer).gpr 7+(8#64)) 8=false := by
    simpa +decide [nativeAfter,memory,context] using bad
  have nfault := native_second_context_fault (nativeAfter n pointer) at3 nativeBad
  have step0 : initializedInstructionStep env p [first] {BPF.setReg p 2 pointer with pc := 1} := by
    refine ⟨⟨{BPF.setReg p 2 pointer with pc := 1},[first],none⟩,?_,rfl,rfl⟩
    rw [entry_environment_independent env p (Or.inl proofPC)]
    exact platform_load p pointer first active proofPC read0
  have step1 : initializedInstructionStep env {BPF.setReg p 2 pointer with pc := 1}
      [.memory .write (p.regs 10-(40#64)) (valueBytes pointer 8) true] (afterSpill p pointer) := by
    refine ⟨⟨afterSpill p pointer,[.memory .write (p.regs 10-(40#64)) (valueBytes pointer 8) true],none⟩,?_,rfl,rfl⟩
    rw [entry_environment_independent env _ (Or.inr (Or.inl rfl))]
    exact platform_spill p pointer active proofPC write40
  have qBad : permitted (afterSpill p pointer).memory.readable ((afterSpill p pointer).regs 1+(8#64)) 8=false := by
    simpa +decide [afterSpill,BPF.setReg,storeMemory] using bad
  have qActive : (afterSpill p pointer).halted=false := active
  have step2 : initializedInstructionStep env (afterSpill p pointer)
      [.fault (.read (p.regs 1+(8#64)) 8)] (afterSpill p pointer) := by
    refine ⟨⟨afterSpill p pointer,[.fault (.read (p.regs 1+(8#64)) 8)],some (.read (p.regs 1+(8#64)) 8)⟩,?_,rfl,rfl⟩
    simpa +decide [afterSpill,BPF.setReg] using initialized_context_load_fault env (afterSpill p pointer)
      ((afterSpill p pointer).regs 1+(8#64)) (Or.inr ⟨rfl,rfl⟩) qActive qBad
  refine ⟨?_,?_,?_,?_⟩
  · simpa +decide [nativeAfter,context] using native_execution_append nread nfault
  · simpa only [List.append_nil,List.cons_append,List.nil_append] using
      Execution.next step0 (Execution.next step1 (Execution.next step2 (Execution.refl _)))
  · have kept := initialization_read_retained p.memory (p.regs 10) _ _ _ first read0 guest0
    simp only [List.filterMap_cons,List.filterMap_nil,kept]
    simp [initializationProjectEvent,initializationSlot,valueBytes]
  · change initializationAgreesOutside (p.regs 10) n.memory (afterSpill p pointer).memory
    rw [memory]
    refine ⟨rfl,rfl,?_⟩
    intro address outside
    exact (spill_preserves_guest p pointer).2.2 address
      (fun inside => outside (initialization_spill_private _ _ inside))


/-- An error from the existing canonical scalar read is precisely its access
fault and failed permission, never an invented result or different fault. -/
theorem canonical_read_error {m : Memory} {address : Word} {count : Nat} {fault : Fault}
    (failed : readMemory m address count=.error fault) :
    permitted m.readable address count=false ∧ fault=.read address count := by
  cases permission : permitted m.readable address count with
  | false =>
    have same : (.read address count : Fault)=fault := by simpa [readMemory,permission] using failed
    exact ⟨rfl,same.symm⟩
  | true => simp [readMemory,permission] at failed

/-- These descriptions use only actual canonical context reads and the
already certified captured paths; they add no checks to either artifact. -/
def allReadSetupTrace (p : BPF.State) : List Event :=
  match readMemory p.memory (p.regs 1) 8 with
  | .error _ => []
  | .ok (pointer,first) =>
    match readMemory p.memory (p.regs 1+(8#64)) 8 with
    | .error _ => [first,.memory .write (p.regs 10-(40#64)) (valueBytes pointer 8) true]
    | .ok (limit,second) => prefixEvents p pointer first second++initializationEvents (p.regs 10) pointer limit

def allReadGuestTrace (p : BPF.State) : List Event :=
  match readMemory p.memory (p.regs 1) 8 with
  | .error fault => [.fault fault]
  | .ok (pointer,_) =>
    match readMemory p.memory (p.regs 1+(8#64)) 8 with
    | .error fault => [.fault fault]
    | .ok (limit,_) => completeGuestSuffix p.memory pointer limit

def allReadNativeTrace (p : BPF.State) : List Event :=
  match readMemory p.memory (p.regs 1) 8 with
  | .error fault => [.fault fault]
  | .ok (pointer,first) =>
    match readMemory p.memory (p.regs 1+(8#64)) 8 with
    | .error fault => [first,.fault fault]
    | .ok (limit,second) => [first,second]++completeGuestSuffix p.memory pointer limit

def allReadNativeFinal (n : X86.State) (p : BPF.State) : X86.State :=
  match readMemory p.memory (p.regs 1) 8 with
  | .error _ => n
  | .ok (pointer,_) =>
    match readMemory p.memory (p.regs 1+(8#64)) 8 with
    | .error _ => nativeAfter n pointer
    | .ok (limit,_) => completeNativeFinal n pointer limit

def allReadProofFinal (p : BPF.State) (stack : Word) : BPF.State :=
  match readMemory p.memory (p.regs 1) 8 with
  | .error _ => p
  | .ok (pointer,_) =>
    match readMemory p.memory (p.regs 1+(8#64)) 8 with
    | .error _ => afterSpill p pointer
    | .ok (limit,_) => completeProofFinal p pointer limit stack

/-- Captured complete executions for every canonical context-read and packet-
write outcome, from entry to actual EXIT or first guest fault. Private frame,
platform and entry-ABI premises remain explicit. This existence theorem does
not yet cover every canonical relational native execution or materialization. -/
theorem captured_all_read_write_outcomes (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack : Word) (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (context : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack)
    (write40 : permitted p.memory.writable (p.regs 10-(40#64)) 8=true)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8=true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8=true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8=true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4=true)
    (read40 : permitted p.memory.readable (p.regs 10-(40#64)) 8=true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8=true)
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (guest1 : ∀ i<8, ¬ initializationPrivateByte (p.regs 10) (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    X86Path.Execution 0 native n (allReadNativeTrace p) (allReadNativeFinal n p) ∧
    Execution (initializedInstructionStep env) p (allReadSetupTrace p++allReadGuestTrace p) (allReadProofFinal p stack) ∧
    (allReadSetupTrace p).filterMap (initializationProjectEvent (p.regs 10))++allReadGuestTrace p = allReadNativeTrace p ∧
    initializationAgreesOutside (p.regs 10) (allReadNativeFinal n p).memory (allReadProofFinal p stack).memory := by
  cases read0 : readMemory p.memory (p.regs 1) 8 with
  | error fault =>
    obtain ⟨bad,rfl⟩ := canonical_read_error read0
    obtain ⟨nrun,prun,mem⟩ := first_context_fault_correspondence env n p nativePC proofPC active context memory bad
    refine ⟨?_,?_,?_,?_⟩
    · simpa only [allReadNativeTrace,allReadNativeFinal,read0] using nrun
    · simpa only [allReadSetupTrace,allReadGuestTrace,allReadProofFinal,read0,List.nil_append] using prun
    · simp only [allReadSetupTrace,allReadGuestTrace,allReadNativeTrace,read0,List.filterMap_nil,List.nil_append]
    · simp only [allReadNativeFinal,allReadProofFinal,read0]
      rw [mem]
      exact ⟨rfl,rfl,fun _ _ => ⟨rfl,rfl⟩⟩
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    cases read1 : readMemory p.memory (p.regs 1+(8#64)) 8 with
    | error fault =>
      obtain ⟨bad,rfl⟩ := canonical_read_error read1
      obtain ⟨nrun,prun,projection,mem⟩ := second_context_fault_correspondence env n p pointer first
        nativePC proofPC active context memory read0 write40 guest0 bad
      refine ⟨?_,?_,?_,?_⟩
      · simpa only [allReadNativeTrace,allReadNativeFinal,read0,read1] using nrun
      · simpa only [allReadSetupTrace,allReadGuestTrace,allReadProofFinal,read0,read1,List.cons_append,List.nil_append] using prun
      · have kept := initialization_read_retained p.memory (p.regs 10) _ _ _ first read0 guest0
        simp only [allReadSetupTrace,allReadGuestTrace,allReadNativeTrace,read0,read1,
          List.filterMap_cons,List.filterMap_nil,kept]
        simp [initializationProjectEvent,initializationSlot,valueBytes]
      · simpa only [allReadNativeFinal,allReadProofFinal,read0,read1] using mem
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      obtain ⟨nrun,prun,projection,mem,_⟩ := complete_all_store_outcomes_correspondence env n p pointer limit stack first second
        nativePC proofPC active context memory nativeStack read0 read1 write40 write32 write24 write16 write8 read40 read32 guest0 guest1
      refine ⟨?_,?_,?_,?_⟩
      · simpa only [allReadNativeTrace,allReadNativeFinal,read0,read1] using nrun
      · simpa only [allReadSetupTrace,allReadGuestTrace,allReadProofFinal,read0,read1] using prun
      · simpa only [allReadSetupTrace,allReadGuestTrace,allReadNativeTrace,read0,read1] using projection
      · simpa only [allReadNativeFinal,allReadProofFinal,read0,read1] using mem


/-- Recover the raw canonical decoder equation from a checked extent, without
changing its PC, selected instruction length, or decoded successor. -/
theorem decode_extent_reflects_raw (base : Word) (bytes : Array Byte) (entry : X86Path.Entry)
    (s : X86.State) (instruction : X86.Instruction)
    (accepted : X86Path.decodeAt base bytes entry s=.ok instruction) :
    X86.decode (bytes.extract entry.offset (entry.offset+entry.length)) s=.ok instruction := by
  unfold X86Path.decodeAt at accepted
  simp only [Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad] at accepted
  split at accepted
  · simp at accepted
  · split at accepted
    · simp at accepted
    · split at accepted
      · simp at accepted
      · cases raw : X86.decode (bytes.extract entry.offset (entry.offset+entry.length)) s with
        | error reason => simp [raw,Except.bind,Bind.bind,Except.instMonad] at accepted
        | ok decoded =>
          simp only [raw,Except.bind,Bind.bind,Except.instMonad] at accepted
          split at accepted
          · simp at accepted
          · have same : decoded=instruction := by simpa using accepted
            cases same
            rfl

/-- Actual captured extents with fully defined flags/register outputs. The
XOR atPC10 is deliberately handled by the prior relational guard proof,
which admits every undefined AF value before the subsequent CMP. -/
def simpleDefinedExtents : List X86Path.Entry :=
  [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨12,3⟩,⟨15,2⟩,⟨17,4⟩,⟨21,3⟩,⟨24,2⟩,
   ⟨26,4⟩,⟨30,3⟩,⟨33,2⟩,⟨35,5⟩,⟨40,4⟩,⟨44,7⟩,⟨51,4⟩,⟨55,5⟩]

/-- Byte-decoding determines full observation at every listed actual extent;
no caller supplies the opcode, operands or observation mask. -/
theorem simple_defined_decode_observed (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (member : entry ∈ simpleDefinedExtents)
    (decoded : X86Path.decodeAt 0 native entry s=.ok instruction) :
    X86.definedFlags instruction=(0xffffffffffffffff#64) ∧
    ∀ state, X86.observedRegisters instruction state=state.gpr := by
  have raw := decode_extent_reflects_raw 0 native entry s instruction decoded
  simp only [simpleDefinedExtents,List.mem_cons,List.mem_singleton,List.not_mem_nil,or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · change X86.decode (native.extract 0 3) s=.ok instruction at raw
    rw [native_decode0] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 3 7) s=.ok instruction at raw
    rw [native_decode3] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 7 10) s=.ok instruction at raw
    rw [native_decode7] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 12 15) s=.ok instruction at raw
    rw [native_decode12] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 15 17) s=.ok instruction at raw
    rw [native_decode15] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 17 21) s=.ok instruction at raw
    rw [native_decode17] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 21 24) s=.ok instruction at raw
    rw [native_decode21] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 24 26) s=.ok instruction at raw
    rw [native_decode24] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 26 30) s=.ok instruction at raw
    rw [native_decode26] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 30 33) s=.ok instruction at raw
    rw [native_decode30] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 33 35) s=.ok instruction at raw
    rw [native_decode33] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 35 40) s=.ok instruction at raw
    rw [native_decode35] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 40 44) s=.ok instruction at raw
    rw [native_decode40] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 44 51) s=.ok instruction at raw
    rw [native_decode44] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 51 55) s=.ok instruction at raw
    rw [native_decode51] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩
  · change X86.decode (native.extract 55 60) s=.ok instruction at raw
    rw [native_decode55] at raw
    cases Except.ok.inj raw
    exact ⟨rfl,fun _ => rfl⟩

/-- Every canonical relational execution of a listed captured instruction has
exactly the representative's full state, ordered effects and fault, including
all memory-permission outcomes. XOR's undefined AF is not constrained here. -/
theorem simple_defined_decoded_step_unique (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (actual : Transition X86.State)
    (member : entry ∈ simpleDefinedExtents)
    (decoded : X86Path.decodeAt 0 native entry s=.ok instruction)
    (run : X86.Step instruction s actual) : actual=X86.step instruction s := by
  obtain ⟨flags,registers⟩ := simple_defined_decode_observed s entry instruction member decoded
  exact fully_observed_step_unique instruction s actual flags registers run


/-- A finite path made only of canonical relational ISA steps. Each extent
is decoded at the actual PC. A fault is terminal, never skipped or continued.
This is execution composition, not an alternative instruction semantics. -/
inductive CanonicalRelationalPath (base : Word) (bytes : Array Byte) :
    List X86Path.Entry → X86.State → Transition X86.State → Prop
  | nil (state) : CanonicalRelationalPath base bytes [] state ⟨state,[],none⟩
  | fault {before effect} (entry instruction)
      (decoded : X86Path.decodeAt base bytes entry before=.ok instruction)
      (step : X86.Step instruction before effect) (failed : effect.fault.isSome=true) :
      CanonicalRelationalPath base bytes [entry] before effect
  | next {before first rest tail} (entry instruction)
      (decoded : X86Path.decodeAt base bytes entry before=.ok instruction)
      (step : X86.Step instruction before first) (continued : first.fault=none)
      (suffix : CanonicalRelationalPath base bytes rest first.state tail) :
      CanonicalRelationalPath base bytes (entry::rest) before
        ⟨tail.state,first.events++tail.events,tail.fault⟩

/-- Fully observed captured instructions lift the actual path evaluator to
EVERY canonical relational path result, including a terminal fault. -/
theorem defined_relational_path_evaluation {entries : List X86Path.Entry} {s : X86.State}
    {actual : Transition X86.State}
    (run : CanonicalRelationalPath 0 native entries s actual)
    (members : ∀ entry ∈ entries, entry ∈ simpleDefinedExtents) :
    X86Path.evaluate 0 native entries s=.ok ⟨actual,(0xffffffffffffffff#64)⟩ := by
  induction run with
  | nil state => rfl
  | @fault before effect entry instruction decoded step failed =>
    have exactStep := simple_defined_decoded_step_unique before entry instruction effect
      (members entry (by simp)) decoded step
    simp only [X86Path.evaluate,decoded,← exactStep,failed,ite_true,List.isEmpty_nil]
    rfl
  | @next before first rest tail entry instruction decoded step continued suffix ih =>
    have exactStep := simple_defined_decoded_step_unique before entry instruction first
      (members entry (by simp)) decoded step
    have flags := (simple_defined_decode_observed before entry instruction
      (members entry (by simp)) decoded).1
    have tailCertificate := ih (fun e inside => members e (by simp [inside]))
    simp only [X86Path.evaluate,decoded,← exactStep,continued,Option.isSome,Bool.false_eq_true,
      ite_false,tailCertificate,flags]
    rfl

/-- A byte-decoded fully observed relational path cannot choose a different
complete state, memory/helper event sequence, or fault than its certificate. -/
theorem defined_relational_result_unique {entries : List X86Path.Entry} {s : X86.State}
    {actual : Transition X86.State} {expected : X86Path.Result}
    (run : CanonicalRelationalPath 0 native entries s actual)
    (members : ∀ entry ∈ entries, entry ∈ simpleDefinedExtents)
    (evaluated : X86Path.evaluate 0 native entries s=.ok expected) :
    actual=expected.effect ∧ expected.definedFlags=(0xffffffffffffffff#64) := by
  have certificate := defined_relational_path_evaluation run members
  have same : (⟨actual,(0xffffffffffffffff#64)⟩ : X86Path.Result)=expected :=
    Except.ok.inj (certificate.symm.trans evaluated)
  exact ⟨congrArg X86Path.Result.effect same,(congrArg X86Path.Result.definedFlags same).symm⟩

theorem packet_fault_path_defined (index : Nat) (bounded : index<4) :
    ∀ entry ∈ packetNativeFaultPath index, entry ∈ simpleDefinedExtents := by
  have choices : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
  rcases choices with rfl | rfl | rfl | rfl
  all_goals simp [packetNativeFaultPath,simpleDefinedExtents]

/-- Every canonical relational execution of any actual first-store-fault
path has the same full partial state and ordered guest trace checked in B. -/
theorem all_store_fault_relational_correspondence (env : BPF.Environment) (frame : Word)
    (n : X86.State) (p : BPF.State) (index : Nat) (actual : Transition X86.State)
    (bounded : index<4) (nativePC : n.pc=35) (proofPC : p.pc=18) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (same : initializationAgreesOutside frame n.memory p.memory)
    (prior : ∀ i<index, packetStorePermission p.memory (p.regs 2) i=true)
    (bad : packetStorePermission p.memory (p.regs 2) index=false)
    (run : CanonicalRelationalPath 0 native (packetNativeFaultPath index) n actual) :
    actual=⟨packetNativeFaultState n index,packetFaultEvents (p.regs 2) index,
      some (packetStoreFault (p.regs 2) index)⟩ ∧
    Execution (initializedInstructionStep env) p actual.events (packetProofFaultState p index) ∧
    initializationAgreesOutside frame actual.state.memory (packetProofFaultState p index).memory := by
  have permission : ∀ i, packetStorePermission n.memory (n.gpr 1) i=
      packetStorePermission p.memory (p.regs 2) i := by
    intro i
    simp only [packetStorePermission,same.2.1,pointer]
  have evaluated := packet_all_native_store_faults n index bounded nativePC
    (by intro i lt; rw [permission]; exact prior i lt) (by rw [permission]; exact bad)
  obtain ⟨unique,_⟩ := defined_relational_result_unique run (packet_fault_path_defined index bounded) evaluated
  have exactResult : actual=⟨packetNativeFaultState n index,packetFaultEvents (p.regs 2) index,
      some (packetStoreFault (p.regs 2) index)⟩ := by simpa only [pointer] using unique
  obtain ⟨_,proofRun,memory⟩ := all_store_fault_correspondence env frame n p index bounded
    nativePC proofPC active pointer same prior bad
  refine ⟨exactResult,?_,?_⟩
  · simpa only [exactResult] using proofRun
  · simpa only [exactResult] using memory


/-- Expose the already checked actual successful five-instruction evaluation
so arbitrary canonical relational path results can be compared to it. -/
theorem packet_native_evaluation (s : X86.State) (position : s.pc=35)
    (write0 : permitted s.memory.writable (s.gpr 1) 2=true)
    (write2 : permitted s.memory.writable (s.gpr 1+(2#64)) 1=true)
    (write3 : permitted s.memory.writable (s.gpr 1+(3#64)) 4=true)
    (write7 : permitted s.memory.writable (s.gpr 1+(7#64)) 1=true) :
    X86Path.evaluate 0 native [⟨35,5⟩,⟨40,4⟩,⟨44,7⟩,⟨51,4⟩,⟨55,5⟩] s =
      .ok ⟨⟨packetNativeFinal s,packetWriteEvents (s.gpr 1),none⟩,(0xffffffffffffffff#64)⟩ := by
  obtain ⟨d0,d1,d2,d3⟩ := packet_native_store_decodes s position
  have pc4 : (packetNativeFourth s).pc=55 := rfl
  have d4 : X86Path.decodeAt 0 native ⟨55,5⟩ (packetNativeFourth s)=.ok
      (.move .w32 (.register (.low 0)) (.immediate (2#64)) 60) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode55,pc4,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  simp only [X86Path.evaluate,d0,d1,d2,d3,d4,packet_native_first_step s write0,
    packet_native_second_step s write2,packet_native_third_step s write3,
    packet_native_fourth_step s write7,packet_native_result_step,X86.definedFlags,
    Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,
    List.nil_append,List.cons_append,List.append_nil,ite_false,packetWriteEvents]
  rfl

/-- The extent list is the actual first-fault prefix or successful write body.
Selection uses canonical permissions and never adds an artifact check. -/
def packetNativeOutcomePath (index : Nat) : List X86Path.Entry :=
  if index=4 then [⟨35,5⟩,⟨40,4⟩,⟨44,7⟩,⟨51,4⟩,⟨55,5⟩] else packetNativeFaultPath index

theorem packet_outcome_path_defined (index : Nat) (bounded : index≤4) :
    ∀ entry ∈ packetNativeOutcomePath index, entry ∈ simpleDefinedExtents := by
  by_cases success : index=4
  · simp [packetNativeOutcomePath,success,simpleDefinedExtents]
  · simpa only [packetNativeOutcomePath,success,ite_false] using
      packet_fault_path_defined index (by omega)

/-- One actual canonical evaluation for every packet-write permission
assignment, including its precise terminal fault field and full state. -/
theorem packet_native_any_evaluation (s : X86.State) (index : Nat) (position : s.pc=35)
    (selected : index=packetFirstFailure s.memory (s.gpr 1)) :
    X86Path.evaluate 0 native (packetNativeOutcomePath index) s =
      .ok ⟨⟨packetNativeOutcome s index,packetOutcomeEvents (s.gpr 1) index,
        if index=4 then none else some (packetStoreFault (s.gpr 1) index)⟩,(0xffffffffffffffff#64)⟩ := by
  have spec := packet_first_failure_spec s.memory (s.gpr 1)
  change packetFirstFailure s.memory (s.gpr 1)≤4 ∧ _ at spec
  rw [← selected] at spec
  by_cases success : index=4
  · have permissions := spec.2.2 success
    have evaluated := packet_native_evaluation s position
      (permissions 0 (by omega)) (permissions 1 (by omega))
      (permissions 2 (by omega)) (permissions 3 (by omega))
    simpa only [packetNativeOutcomePath,packetNativeOutcome,packetOutcomeEvents,success,ite_true] using evaluated
  · have failed : index<4 := by omega
    obtain ⟨prior,bad⟩ := spec.2.1 failed
    simpa only [packetNativeOutcomePath,packetNativeOutcome,packetOutcomeEvents,success,ite_false] using
      packet_all_native_store_faults s index failed position prior bad

/-- Every canonical relational execution of the actual complete packet-body
path, for every permission assignment, has the state/effects/fault checked by B.
No caller supplies successful stores, a branch outcome, or observation masks. -/
theorem packet_body_relational_correspondence (env : BPF.Environment) (frame : Word)
    (n : X86.State) (p : BPF.State) (index : Nat) (actual : Transition X86.State)
    (nativePC : n.pc=35) (proofPC : p.pc=18) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (same : initializationAgreesOutside frame n.memory p.memory)
    (selected : index=packetFirstFailure p.memory (p.regs 2))
    (run : CanonicalRelationalPath 0 native (packetNativeOutcomePath index) n actual) :
    actual=⟨packetNativeOutcome n index,packetOutcomeEvents (p.regs 2) index,
      if index=4 then none else some (packetStoreFault (p.regs 2) index)⟩ ∧
    Execution (initializedInstructionStep env) p actual.events (packetProofOutcome p index) ∧
    initializationAgreesOutside frame actual.state.memory (packetProofOutcome p index).memory ∧
    (index=4 → actual.state.pc=60 ∧ (packetProofOutcome p index).halted=true ∧
      actual.state.gpr 0=(packetProofOutcome p index).regs 0 ∧ actual.state.gpr 0=(2#64)) := by
  obtain ⟨bounded,_,proofRun,memory,returned⟩ :=
    packet_body_any_permissions env frame n p index nativePC proofPC active pointer same selected
  have nativeSelected : index=packetFirstFailure n.memory (n.gpr 1) :=
    selected.trans (packet_failure_index_agrees same pointer).symm
  have evaluated := packet_native_any_evaluation n index nativePC nativeSelected
  obtain ⟨unique,_⟩ := defined_relational_result_unique run (packet_outcome_path_defined index bounded) evaluated
  have exactResult : actual=⟨packetNativeOutcome n index,packetOutcomeEvents (p.regs 2) index,
      if index=4 then none else some (packetStoreFault (p.regs 2) index)⟩ := by
    simpa only [pointer] using unique
  refine ⟨exactResult,?_,?_,?_⟩
  · simpa only [exactResult] using proofRun
  · simpa only [exactResult] using memory
  · simpa only [exactResult] using returned


/-- A one-instruction canonical path contains exactly that relational step,
including its actual fault field. No representative is substituted here. -/
theorem relational_single_step {entry : X86Path.Entry} {s : X86.State}
    {actual : Transition X86.State} (run : CanonicalRelationalPath 0 native [entry] s actual) :
    ∃ instruction, X86Path.decodeAt 0 native entry s=.ok instruction ∧ X86.Step instruction s actual := by
  cases run with
  | fault entry instruction decoded step failed => exact ⟨instruction,decoded,step⟩
  | next entry instruction decoded step continued suffix =>
    cases suffix with
    | nil =>
      refine ⟨instruction,decoded,?_⟩
      simpa only [List.append_nil,← continued] using step

/-- A nonterminal instruction of a multi-instruction path cannot fault. -/
theorem relational_cons_split {entry second : X86Path.Entry} {rest : List X86Path.Entry}
    {s : X86.State} {actual : Transition X86.State}
    (run : CanonicalRelationalPath 0 native (entry::second::rest) s actual) :
    ∃ instruction head tail,
      X86Path.decodeAt 0 native entry s=.ok instruction ∧ X86.Step instruction s head ∧
      head.fault=none ∧ CanonicalRelationalPath 0 native (second::rest) head.state tail ∧
      actual=⟨tail.state,head.events++tail.events,tail.fault⟩ := by
  cases run with
  | next entry instruction decoded step continued suffix =>
    exact ⟨instruction,_,_,decoded,step,continued,suffix,rfl⟩

/-- Every actual canonical relational path through the first guard has the
same complete boundary result, while XOR's undefined AF remains unrestricted. -/
theorem first_guard_relational_path_result (s : X86.State) (actual : Transition X86.State)
    (position : s.pc=7)
    (run : CanonicalRelationalPath 0 native [⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] s actual) :
    actual=⟨guardFinal s,[],none⟩ := by
  obtain ⟨i0,t0,u0,d0,r0,_,tail0,e0⟩ := relational_cons_split run
  obtain ⟨i1,t1,u1,d1,r1,_,tail1,e1⟩ := relational_cons_split tail0
  obtain ⟨i2,t2,u2,d2,r2,_,tail2,e2⟩ := relational_cons_split tail1
  obtain ⟨i3,d3,r3⟩ := relational_single_step tail2
  obtain ⟨trace,_,_,_,branch⟩ := native_guard_decoded_relational_block s position
    t0 t1 t2 u2 i0 i1 i2 i3 d0 r0 d1 r1 d2 r2 d3 r3
  calc
    actual=⟨u2.state,t0.events++t1.events++t2.events++u2.events,u2.fault⟩ := by
      rw [e0,e1,e2]
      simp only [List.append_assoc]
    _=⟨guardFinal s,[],none⟩ := by rw [trace,branch]

/-- The actual B first guard checks every canonical relational native guard
path, including every undefined-AF choice and either derived successor. -/
theorem first_guard_path_relational_correspondence (env : BPF.Environment)
    (n : X86.State) (p : BPF.State) (actual : Transition X86.State)
    (nativePC : n.pc=7) (proofPC : p.pc=11) (active : p.halted=false)
    (pointer : n.gpr 1=p.regs 2) (limit : n.gpr 2=p.regs 3)
    (run : CanonicalRelationalPath 0 native [⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] n actual) :
    actual=⟨guardFinal n,[],none⟩ ∧
    Execution (initializedInstructionStep env) p actual.events (proofGuardFinal p) ∧
    actual.state.pc=(if p.regs 2 > p.regs 3 then 60 else 17) ∧
    (proofGuardFinal p).pc=(if p.regs 2 > p.regs 3 then 34 else 12) := by
  have exactResult := first_guard_relational_path_result n actual nativePC run
  obtain ⟨_,proofRun,npc,ppc,_⟩ := first_guard_correspondence env n p nativePC proofPC active pointer limit
  refine ⟨exactResult,?_,?_,ppc⟩
  · simpa only [exactResult] using proofRun
  · simpa only [exactResult] using npc


/-- Successful canonical representative evaluation is one valid relational
path. This supplies a witness, never uniqueness for undefined outputs. -/
theorem canonical_evaluation_relational_sound (base : Word) (bytes : Array Byte)
    (entries : List X86Path.Entry) (state : X86.State) (result : X86Path.Result)
    (accepted : X86Path.evaluate base bytes entries state=.ok result) :
    CanonicalRelationalPath base bytes entries state result.effect := by
  induction entries generalizing state result with
  | nil =>
    simp [X86Path.evaluate] at accepted
    cases accepted
    exact CanonicalRelationalPath.nil state
  | cons entry rest ih =>
    cases decoded : X86Path.decodeAt base bytes entry state with
    | error reason => simp [X86Path.evaluate,decoded] at accepted
    | ok instruction =>
      have semantic : X86.Step instruction state (X86.step instruction state) := ⟨rfl,rfl,rfl⟩
      cases fault : (X86.step instruction state).fault with
      | some reason =>
        cases rest with
        | nil =>
          simp [X86Path.evaluate,decoded,fault] at accepted
          cases accepted
          exact CanonicalRelationalPath.fault entry instruction decoded semantic (by simp [fault])
        | cons next tail => simp [X86Path.evaluate,decoded,fault] at accepted
      | none =>
        cases evaluated : X86Path.evaluate base bytes rest (X86.step instruction state).state with
        | error reason => simp [X86Path.evaluate,decoded,fault,evaluated] at accepted
        | ok tail =>
          simp [X86Path.evaluate,decoded,fault,evaluated] at accepted
          cases accepted
          exact CanonicalRelationalPath.next entry instruction decoded semantic fault
            (ih _ tail evaluated)

/-- Append only after a nonfaulting prefix, preserving all actual transitions
and ordered effects. This also admits arbitrary undefined-output choices. -/
theorem relational_path_append {base : Word} {bytes : Array Byte}
    {firstEntries lastEntries : List X86Path.Entry} {start : X86.State}
    {middle last : Transition X86.State}
    (head : CanonicalRelationalPath base bytes firstEntries start middle)
    (normal : middle.fault=none)
    (tail : CanonicalRelationalPath base bytes lastEntries middle.state last) :
    CanonicalRelationalPath base bytes (firstEntries++lastEntries) start
      ⟨last.state,middle.events++last.events,last.fault⟩ := by
  revert normal tail
  induction head with
  | nil state =>
    intro normal tail
    simpa only [List.nil_append] using tail
  | fault entry instruction decoded step failed =>
    intro normal tail
    simp [normal] at failed
  | @next before first rest remaining entry instruction decoded step continued suffix ih =>
    intro normal tail
    have combined := ih normal tail
    have whole := CanonicalRelationalPath.next entry instruction decoded step continued combined
    simpa only [List.cons_append,List.append_assoc] using whole

theorem remaining_native8_evaluation (s : X86.State) (position : s.pc=17) :
    X86Path.evaluate 0 native [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩] s =
      .ok ⟨⟨remainingNative8 s,[],none⟩,(0xffffffffffffffff#64)⟩ := by
  have d0 : X86Path.decodeAt 0 native ⟨17,4⟩ s = .ok (.lea .w64 7 (s.gpr 6+(8#64)) 21) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode17,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have pc1 : (remainingNativeLea s).pc=21 := rfl
  have pc2 : (remainingNativeCmp8 s).pc=24 := rfl
  have d1 : X86Path.decodeAt 0 native ⟨21,3⟩ (remainingNativeLea s) = .ok
      (.arithmetic .w64 .compare (.register (.low 7)) (.register (.low 2)) 24) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode21,pc1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt 0 native ⟨24,2⟩ (remainingNativeCmp8 s) = .ok (.branch (some 7) 60 26) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode24,pc2,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  simp only [X86Path.evaluate,d0,d1,d2,remaining_native_lea_step,
    remaining_native_cmp8_step,remaining_native_branch8_step,X86.definedFlags,
    Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,List.nil_append,ite_false]
  rfl

theorem remaining_native72_evaluation (s : X86.State) (position : s.pc=26) :
    X86Path.evaluate 0 native [⟨26,4⟩,⟨30,3⟩,⟨33,2⟩] s =
      .ok ⟨⟨remainingNative72 s,[],none⟩,(0xffffffffffffffff#64)⟩ := by
  have d0 : X86Path.decodeAt 0 native ⟨26,4⟩ s = .ok
      (.arithmetic .w64 .add (.register (.low 6)) (.immediate (72#64)) 30) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode26,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have pc1 : (remainingNativeAdd s).pc=30 := rfl
  have pc2 : (remainingNativeCmp72 s).pc=33 := rfl
  have d1 : X86Path.decodeAt 0 native ⟨30,3⟩ (remainingNativeAdd s) = .ok
      (.arithmetic .w64 .compare (.register (.low 6)) (.register (.low 2)) 33) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode30,pc1,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt 0 native ⟨33,2⟩ (remainingNativeCmp72 s) = .ok (.branch (some 7) 60 35) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode33,pc2,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  simp only [X86Path.evaluate,d0,d1,d2,remaining_native_add72_step,
    remaining_native_cmp72_step,remaining_native_branch72_step,X86.definedFlags,
    Option.isSome,Bool.false_eq_true,List.isEmpty_cons,List.isEmpty_nil,List.nil_append,ite_false]
  rfl


def remainingNativePath (s : X86.State) : List X86Path.Entry :=
  if s.gpr 6+(8#64)>s.gpr 2 then [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩]
  else [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩,⟨26,4⟩,⟨30,3⟩,⟨33,2⟩]

theorem remaining_native_path_defined (s : X86.State) :
    ∀ entry ∈ remainingNativePath s, entry ∈ simpleDefinedExtents := by
  by_cases reject8 : s.gpr 6+(8#64)>s.gpr 2 <;>
    simp [remainingNativePath,reject8,simpleDefinedExtents]

/-- Both remaining native guards evaluated in their actual order. All
successors are derived by canonical arithmetic/branch semantics, including wrap. -/
theorem remaining_native_path_evaluation (s : X86.State) (position : s.pc=17) :
    X86Path.evaluate 0 native (remainingNativePath s) s =
      .ok ⟨⟨remainingNativeFinal s,[],none⟩,(0xffffffffffffffff#64)⟩ := by
  have head := remaining_native8_evaluation s position
  by_cases reject8 : s.gpr 6+(8#64)>s.gpr 2
  · simpa only [remainingNativePath,remainingNativeFinal,reject8,ite_true] using head
  · have at26 : (remainingNative8 s).pc=26 := by simp [remainingNative8,reject8]
    have tail := remaining_native72_evaluation (remainingNative8 s) at26
    have headPath := canonical_evaluation_relational_sound _ _ _ _ _ head
    have tailPath := canonical_evaluation_relational_sound _ _ _ _ _ tail
    have combined := relational_path_append headPath rfl tailPath
    have defined : ∀ entry ∈ [⟨17,4⟩,⟨21,3⟩,⟨24,2⟩]++[⟨26,4⟩,⟨30,3⟩,⟨33,2⟩],
        entry ∈ simpleDefinedExtents := by simp [simpleDefinedExtents]
    have evaluated := defined_relational_path_evaluation combined defined
    simpa only [remainingNativePath,remainingNativeFinal,reject8,ite_false,List.nil_append] using evaluated

/-- Every canonical relational remaining-guard path matches the actual B
region, despite clang's opposite scheduling of its two side-effect-free tests. -/
theorem remaining_guard_path_relational_correspondence (env : BPF.Environment)
    (n : X86.State) (p : BPF.State) (actual : Transition X86.State)
    (nativePC : n.pc=17) (proofPC : p.pc=12) (active : p.halted=false)
    (pointer : n.gpr 6=p.regs 2) (limit : n.gpr 2=p.regs 3)
    (run : CanonicalRelationalPath 0 native (remainingNativePath n) n actual) :
    actual=⟨remainingNativeFinal n,[],none⟩ ∧
    Execution (initializedInstructionStep env) p actual.events (remainingProofFinal p) ∧
    actual.state.pc=(if p.regs 2+(8#64)>p.regs 3 ∨ p.regs 2+(72#64)>p.regs 3 then 60 else 35) ∧
    (remainingProofFinal p).pc=(if p.regs 2+(8#64)>p.regs 3 ∨ p.regs 2+(72#64)>p.regs 3 then 34 else 18) ∧
    actual.state.memory=n.memory ∧ (remainingProofFinal p).memory=p.memory := by
  have evaluated := remaining_native_path_evaluation n nativePC
  obtain ⟨unique,_⟩ := defined_relational_result_unique run (remaining_native_path_defined n) evaluated
  obtain ⟨_,proofRun,npc,ppc,nmemory,pmemory⟩ := remaining_guard_correspondence env n p nativePC proofPC active pointer limit
  refine ⟨unique,?_,?_,ppc,?_,pmemory⟩
  · simpa only [unique] using proofRun
  · simpa only [unique] using npc
  · simpa only [unique] using nmemory


/-- Entry read certificates use the existing scalar read and canonical step,
including a precise read fault. No permission outcome is assumed. -/
theorem native_first_read_evaluation (s : X86.State) (position : s.pc=0) :
    X86Path.evaluate 0 native [⟨0,3⟩] s = .ok ⟨
      (match readMemory s.memory (s.gpr 7) 8 with
       | .error fault => ⟨s,[.fault fault],some fault⟩
       | .ok (value,event) => ⟨nativeAfter s value,[event],none⟩),
      (0xffffffffffffffff#64)⟩ := by
  have decoded : X86Path.decodeAt 0 native ⟨0,3⟩ s = .ok
      (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc+3)) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode0,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  cases read : readMemory s.memory (s.gpr 7) 8 with
  | error fault =>
    obtain ⟨bad,rfl⟩ := canonical_read_error read
    simp only [X86Path.evaluate,decoded,native_memory_source_fault s _ _ _ bad,
      read,Option.isSome,ite_true,List.isEmpty_nil]
    rfl
  | ok pair =>
    rcases pair with ⟨value,event⟩
    simp only [X86Path.evaluate,decoded,native_load s value event read,read,
      Option.isSome,Bool.false_eq_true,ite_false,X86.definedFlags]
    rfl

theorem native_second_read_evaluation (s : X86.State) (position : s.pc=3) :
    X86Path.evaluate 0 native [⟨3,4⟩] s = .ok ⟨
      (match readMemory s.memory (s.gpr 7+(8#64)) 8 with
       | .error fault => ⟨s,[.fault fault],some fault⟩
       | .ok (value,event) => ⟨nativeAfterSecond s value,[event],none⟩),
      (0xffffffffffffffff#64)⟩ := by
  have decoded : X86Path.decodeAt 0 native ⟨3,4⟩ s = .ok
      (.move .w64 (.register (.low 2)) (.memory (s.gpr 7+(8#64))) (s.pc+4)) := by
    simp +decide [X86Path.decodeAt,native_size,native_decode3,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  cases read : readMemory s.memory (s.gpr 7+(8#64)) 8 with
  | error fault =>
    obtain ⟨bad,rfl⟩ := canonical_read_error read
    simp only [X86Path.evaluate,decoded,native_memory_source_fault s _ _ _ bad,
      read,Option.isSome,ite_true,List.isEmpty_nil]
    rfl
  | ok pair =>
    rcases pair with ⟨value,event⟩
    simp only [X86Path.evaluate,decoded,native_second_load s value event read,read,
      Option.isSome,Bool.false_eq_true,ite_false,X86.definedFlags]
    rfl

def contextNativePath (n : X86.State) : List X86Path.Entry :=
  match readMemory n.memory (n.gpr 7) 8 with
  | .error _ => [⟨0,3⟩]
  | .ok _ => [⟨0,3⟩,⟨3,4⟩]

def contextNativeResult (n : X86.State) : Transition X86.State :=
  match readMemory n.memory (n.gpr 7) 8 with
  | .error fault => ⟨n,[.fault fault],some fault⟩
  | .ok (pointer,first) =>
    match readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | .error fault => ⟨nativeAfter n pointer,[first,.fault fault],some fault⟩
    | .ok (limit,second) => ⟨nativePrefixFinal n pointer limit,[first,second],none⟩

theorem context_native_path_defined (n : X86.State) :
    ∀ entry ∈ contextNativePath n, entry ∈ simpleDefinedExtents := by
  cases read : readMemory n.memory (n.gpr 7) 8 <;>
    simp [contextNativePath,read,simpleDefinedExtents]

theorem context_native_path_evaluation (n : X86.State) (position : n.pc=0) :
    X86Path.evaluate 0 native (contextNativePath n) n =
      .ok ⟨contextNativeResult n,(0xffffffffffffffff#64)⟩ := by
  have firstCertificate := native_first_read_evaluation n position
  cases read0 : readMemory n.memory (n.gpr 7) 8 with
  | error fault =>
    simpa only [contextNativePath,contextNativeResult,read0] using firstCertificate
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    have head := canonical_evaluation_relational_sound _ _ _ _ _ firstCertificate
    simp only [read0] at head
    have at3 : (nativeAfter n pointer).pc=3 := by simp [nativeAfter,position]
    have tailCertificate := native_second_read_evaluation (nativeAfter n pointer) at3
    have tail := canonical_evaluation_relational_sound _ _ _ _ _ tailCertificate
    have combined := relational_path_append head rfl tail
    have defined : ∀ entry ∈ [⟨0,3⟩]++[⟨3,4⟩], entry ∈ simpleDefinedExtents := by
      simp [simpleDefinedExtents]
    have evaluated := defined_relational_path_evaluation combined defined
    cases read1 : readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | error fault =>
      simpa +decide [contextNativePath,contextNativeResult,read0,read1,nativeAfter] using evaluated
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      simpa +decide [contextNativePath,contextNativeResult,read0,read1,nativePrefixFinal,nativeAfter] using evaluated

/-- Every relational context prefix, including either first read fault,
retains its exact full state, event order and fault. -/
theorem context_native_relational_result (n : X86.State) (actual : Transition X86.State)
    (position : n.pc=0)
    (run : CanonicalRelationalPath 0 native (contextNativePath n) n actual) :
    actual=contextNativeResult n := by
  exact (defined_relational_result_unique run (context_native_path_defined n)
    (context_native_path_evaluation n position)).1

/-- Split before a nonempty suffix. Every earlier transition must be
nonfaulting; the decomposition preserves all effects and undefined choices. -/
theorem relational_path_split_nonempty {firstEntries lastEntries : List X86Path.Entry}
    {start : X86.State} {actual : Transition X86.State}
    (nonempty : lastEntries≠[])
    (run : CanonicalRelationalPath 0 native (firstEntries++lastEntries) start actual) :
    ∃ middle tail, CanonicalRelationalPath 0 native firstEntries start middle ∧
      middle.fault=none ∧ CanonicalRelationalPath 0 native lastEntries middle.state tail ∧
      actual=⟨tail.state,middle.events++tail.events,tail.fault⟩ := by
  induction firstEntries generalizing start actual with
  | nil => exact ⟨⟨start,[],none⟩,actual,CanonicalRelationalPath.nil start,rfl,run,rfl⟩
  | cons entry rest ih =>
    have tailNonempty : rest++lastEntries≠[] := by
      intro empty
      exact nonempty (List.append_eq_nil.mp empty).2
    cases shape : rest++lastEntries with
    | nil => exact False.elim (tailNonempty shape)
    | cons second remaining =>
      have expanded : CanonicalRelationalPath 0 native (entry::second::remaining) start actual := by
        simpa only [List.cons_append,shape] using run
      obtain ⟨instruction,head,tail,decoded,step,normal,suffix,same⟩ := relational_cons_split expanded
      have unsplit : CanonicalRelationalPath 0 native (rest++lastEntries) head.state tail := by
        simpa only [shape] using suffix
      obtain ⟨middle,last,headRun,nonfault,lastRun,assembled⟩ := ih unsplit
      refine ⟨⟨middle.state,head.events++middle.events,middle.fault⟩,last,
        CanonicalRelationalPath.next entry instruction decoded step normal headRun,nonfault,lastRun,?_⟩
      rw [same,assembled]
      simp only [List.append_assoc]

/-- The first complete region from entry through the XOR/CMP guard has one
boundary transition for every undefined AF choice. Successful reads are
assumed only in this region theorem; context_native_relational_result covers
both fault paths without such an assumption. -/
theorem entry_first_guard_relational_result (n : X86.State) (pointer limit : Word)
    (first second : Event) (actual : Transition X86.State) (position : n.pc=0)
    (read0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first))
    (read1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second))
    (run : CanonicalRelationalPath 0 native
      [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] n actual) :
    actual=⟨guardFinal (nativePrefixFinal n pointer limit),[first,second],none⟩ := by
  have splitRun : CanonicalRelationalPath 0 native
      ([⟨0,3⟩,⟨3,4⟩]++[⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩]) n actual := run
  obtain ⟨middle,tail,headRun,_,tailRun,same⟩ := relational_path_split_nonempty (by simp) splitRun
  have contextRun : CanonicalRelationalPath 0 native (contextNativePath n) n middle := by
    simpa only [contextNativePath,read0] using headRun
  have middleResult := context_native_relational_result n middle position contextRun
  simp only [contextNativeResult,read0,read1] at middleResult
  rw [middleResult] at tailRun same
  have at7 : (nativePrefixFinal n pointer limit).pc=7 := by
    simp [nativePrefixFinal,nativeAfterSecond,nativeAfter,position]
  have tailResult := first_guard_relational_path_result _ tail at7 tailRun
  rw [same,tailResult]
  rfl


theorem entry_first_guard_path_relational_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
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
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (actual : Transition X86.State)
    (run : CanonicalRelationalPath 0 native
      [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] n actual)
    (guest1 : ∀ i < 8, ¬ initializationPrivateByte (p.regs 10)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    actual=⟨guardFinal (nativePrefixFinal n pointer limit),[first,second],none⟩ ∧
    Execution (initializedInstructionStep env) p
      (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit)
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)) ∧
    (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)) = [first,second] ∧
    (guardFinal (nativePrefixFinal n pointer limit)).pc = (if pointer > limit then 60 else 17) ∧
    (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).pc =
      (if pointer > limit then 34 else 12) ∧
    initializationAgreesOutside (p.regs 10) (guardFinal (nativePrefixFinal n pointer limit)).memory
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).memory ∧
    (guardFinal (nativePrefixFinal n pointer limit)).gpr 0 =
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).regs 1 ∧
    (guardFinal (nativePrefixFinal n pointer limit)).gpr 6 =
      (proofGuardFinal (initializationFinal (proofPrefixFinal p pointer limit) pointer limit stack)).regs 2 ∧
    (guardFinal (nativePrefixFinal n pointer limit)).rflags =
      X86.arithmeticFlags .w64 true false pointer limit n.rflags := by
  have nativeRead0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by
    simpa only [memory,context] using read0
  have nativeRead1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second) := by
    simpa only [memory,context] using read1
  have unique := entry_first_guard_relational_result n pointer limit first second actual
    nativePC nativeRead0 nativeRead1 run
  have old := entry_first_guard_correspondence env n p pointer limit stack first second
    nativePC proofPC active context memory nativeStack read0 read1 write40 write32 write24
    write16 write8 read40 read32 guest0 guest1
  exact ⟨unique,old.2⟩


/-- Actual native path from entry through all guards; only canonical values
choose whether the later region occurs. Both entry reads are assumed here. -/
def guardedNativePath (n : X86.State) (pointer limit : Word) : List X86Path.Entry :=
  [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩]++
    if pointer>limit then [] else remainingNativePath (guardFinal (nativePrefixFinal n pointer limit))

theorem guarded_native_relational_result (n : X86.State) (pointer limit : Word)
    (first second : Event) (actual : Transition X86.State) (position : n.pc=0)
    (read0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first))
    (read1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second))
    (run : CanonicalRelationalPath 0 native (guardedNativePath n pointer limit) n actual) :
    actual=⟨guardedNativeFinal n pointer limit,[first,second],none⟩ := by
  by_cases reject : pointer>limit
  · have firstRun : CanonicalRelationalPath 0 native
        [⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩] n actual := by
      simpa only [guardedNativePath,reject,ite_true,List.append_nil] using run
    simpa only [guardedNativeFinal,reject,ite_true] using
      entry_first_guard_relational_result n pointer limit first second actual position read0 read1 firstRun
  · have combined : CanonicalRelationalPath 0 native
        ([⟨0,3⟩,⟨3,4⟩,⟨7,3⟩,⟨10,2⟩,⟨12,3⟩,⟨15,2⟩]++
        remainingNativePath (guardFinal (nativePrefixFinal n pointer limit))) n actual := by
      simpa only [guardedNativePath,reject,ite_false] using run
    have nonempty : remainingNativePath (guardFinal (nativePrefixFinal n pointer limit))≠[] := by
      unfold remainingNativePath
      split <;> simp
    obtain ⟨middle,tail,headRun,_,tailRun,same⟩ := relational_path_split_nonempty nonempty combined
    have middleResult := entry_first_guard_relational_result n pointer limit first second middle
      position read0 read1 headRun
    rw [middleResult] at tailRun same
    have at17 : (guardFinal (nativePrefixFinal n pointer limit)).pc=17 := by
      simp +decide [guardFinal,nativePrefixFinal,nativeAfterSecond,nativeAfter,reject]
    have tailResult := (defined_relational_result_unique tailRun
      (remaining_native_path_defined _) (remaining_native_path_evaluation _ at17)).1
    rw [same,tailResult]
    simp only [guardedNativeFinal,reject,ite_false,List.append_nil]


theorem entry_all_guards_path_relational_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc = 0) (proofPC : p.pc = 0) (active : p.halted = false)
    (context : n.gpr 7 = p.regs 1) (memory : n.memory = p.memory)
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
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (actual : Transition X86.State)
    (run : CanonicalRelationalPath 0 native (guardedNativePath n pointer limit) n actual)
    (guest1 : ∀ i < 8, ¬ initializationPrivateByte (p.regs 10)
      (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    actual=⟨guardedNativeFinal n pointer limit,[first,second],none⟩ ∧
    Execution (initializedInstructionStep env) p
      (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit)
      (guardedProofFinal p pointer limit stack) ∧
    (prefixEvents p pointer first second ++ initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)) = [first,second] ∧
    (guardedNativeFinal n pointer limit).pc =
      (if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then 60 else 35) ∧
    (guardedProofFinal p pointer limit stack).pc =
      (if pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit then 34 else 18) ∧
    initializationAgreesOutside (p.regs 10) (guardedNativeFinal n pointer limit).memory
      (guardedProofFinal p pointer limit stack).memory ∧
    (guardedNativeFinal n pointer limit).gpr 1 = pointer ∧
    (guardedNativeFinal n pointer limit).gpr 0 = (0#64) ∧
    (guardedProofFinal p pointer limit stack).regs 2 = pointer ∧
    (guardedProofFinal p pointer limit stack).regs 1 = (0#64) := by
  have nativeRead0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by
    simpa only [memory,context] using read0
  have nativeRead1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second) := by
    simpa only [memory,context] using read1
  have unique := guarded_native_relational_result n pointer limit first second actual
    nativePC nativeRead0 nativeRead1 run
  have old := entry_all_guards_correspondence env n p pointer limit stack first second
    nativePC proofPC active context memory nativeStack read0 read1 write40 write32 write24
    write16 write8 read40 read32 guest0 guest1
  exact ⟨unique,old.2⟩


/-- The body entry facts are consequences of the actual guard state. No
packet permission, non-wrapping arithmetic or branch result is assumed. -/
theorem guarded_native_body_boundary (n : X86.State) (pointer limit : Word)
    (allowed : ¬ (pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit)) :
    (guardedNativeFinal n pointer limit).pc=35 ∧
    (guardedNativeFinal n pointer limit).gpr 1=pointer ∧
    (guardedNativeFinal n pointer limit).memory=n.memory := by
  have first : ¬pointer>limit := fun h => allowed (Or.inl h)
  have second : ¬pointer+(8#64)>limit := fun h => allowed (Or.inr (Or.inl h))
  have third : ¬pointer+(72#64)>limit := fun h => allowed (Or.inr (Or.inr h))
  simp +decide [guardedNativeFinal,guardFinal,guardCompare,guardZero,guardMove,
    nativePrefixFinal,nativeAfterSecond,nativeAfter,remainingNativeFinal,
    remainingNative8,remainingNativeCmp8,remainingNativeLea,
    remainingNative72,remainingNativeCmp72,remainingNativeAdd,first,second,third]

def completeNativePath (n : X86.State) (pointer limit : Word) : List X86Path.Entry :=
  guardedNativePath n pointer limit++
    if pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit then []
    else packetNativeOutcomePath (packetFirstFailure n.memory pointer)

def completeNativeFault (m : Memory) (pointer limit : Word) : Option Fault :=
  if pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit then none
  else if packetFirstFailure m pointer=4 then none
  else some (packetStoreFault pointer (packetFirstFailure m pointer))

def completeNativeResult (n : X86.State) (pointer limit : Word)
    (first second : Event) : Transition X86.State :=
  ⟨completeNativeFinal n pointer limit,
    [first,second]++completeGuestSuffix n.memory pointer limit,
    completeNativeFault n.memory pointer limit⟩

theorem packet_native_outcome_path_nonempty (index : Nat) (bounded : index≤4) :
    packetNativeOutcomePath index≠[] := by
  have cases : index=0 ∨ index=1 ∨ index=2 ∨ index=3 ∨ index=4 := by omega
  rcases cases with rfl | rfl | rfl | rfl | rfl <;>
    simp [packetNativeOutcomePath,packetNativeFaultPath]

/-- Every canonical relational result of the actual complete native path,
for arbitrary write permissions and all undefined AF choices. -/
theorem complete_native_relational_result (n : X86.State) (pointer limit : Word)
    (first second : Event) (actual : Transition X86.State) (position : n.pc=0)
    (read0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first))
    (read1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second))
    (run : CanonicalRelationalPath 0 native (completeNativePath n pointer limit) n actual) :
    actual=completeNativeResult n pointer limit first second := by
  by_cases reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit
  · have guards : CanonicalRelationalPath 0 native (guardedNativePath n pointer limit) n actual := by
      simpa only [completeNativePath,reject,ite_true,List.append_nil] using run
    have unique := guarded_native_relational_result n pointer limit first second actual position read0 read1 guards
    simpa only [completeNativeResult,completeNativeFinal,completeGuestSuffix,
      completeNativeFault,reject,ite_true,List.append_nil] using unique
  · have bound := (packet_first_failure_spec n.memory pointer).1
    have combined : CanonicalRelationalPath 0 native
        (guardedNativePath n pointer limit++packetNativeOutcomePath (packetFirstFailure n.memory pointer)) n actual := by
      simpa only [completeNativePath,reject,ite_false] using run
    obtain ⟨middle,tail,headRun,_,tailRun,same⟩ := relational_path_split_nonempty
      (packet_native_outcome_path_nonempty _ bound) combined
    have middleResult := guarded_native_relational_result n pointer limit first second middle position read0 read1 headRun
    rw [middleResult] at tailRun same
    obtain ⟨pc,pointerMatch,memoryMatch⟩ := guarded_native_body_boundary n pointer limit reject
    have selected : packetFirstFailure n.memory pointer =
        packetFirstFailure (guardedNativeFinal n pointer limit).memory
          ((guardedNativeFinal n pointer limit).gpr 1) := by rw [pointerMatch,memoryMatch]
    have evaluated := packet_native_any_evaluation (guardedNativeFinal n pointer limit)
      (packetFirstFailure n.memory pointer) pc selected
    have tailResult := (defined_relational_result_unique tailRun
      (packet_outcome_path_defined _ bound) evaluated).1
    rw [same,tailResult]
    simp only [completeNativeResult,completeNativeFinal,completeGuestSuffix,completeNativeFault,
      reject,ite_false,pointerMatch]


theorem complete_path_relational_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (pointer limit stack : Word) (first second : Event)
    (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (context : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack)
    (read0 : readMemory p.memory (p.regs 1) 8=.ok (pointer,first))
    (read1 : readMemory p.memory (p.regs 1+(8#64)) 8=.ok (limit,second))
    (write40 : permitted p.memory.writable (p.regs 10-(40#64)) 8=true)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8=true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8=true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8=true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4=true)
    (read40 : permitted p.memory.readable (p.regs 10-(40#64)) 8=true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8=true)
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (actual : Transition X86.State)
    (run : CanonicalRelationalPath 0 native (completeNativePath n pointer limit) n actual)
    (guest1 : ∀ i<8, ¬ initializationPrivateByte (p.regs 10) (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    actual=completeNativeResult n pointer limit first second ∧
    Execution (initializedInstructionStep env) p
      ((prefixEvents p pointer first second++initializationEvents (p.regs 10) pointer limit)++
        completeGuestSuffix p.memory pointer limit) (completeProofFinal p pointer limit stack) ∧
    ((prefixEvents p pointer first second++initializationEvents (p.regs 10) pointer limit).filterMap
      (initializationProjectEvent (p.regs 10)))++completeGuestSuffix p.memory pointer limit =
      [first,second]++completeGuestSuffix p.memory pointer limit ∧
    initializationAgreesOutside (p.regs 10) (completeNativeFinal n pointer limit).memory
      (completeProofFinal p pointer limit stack).memory ∧
    ((pointer > limit ∨ pointer+(8#64) > limit ∨ pointer+(72#64) > limit) ∨
      packetFirstFailure p.memory pointer=4 →
      (completeNativeFinal n pointer limit).pc=60 ∧
      (completeProofFinal p pointer limit stack).halted=true ∧
      (completeNativeFinal n pointer limit).gpr 0=(completeProofFinal p pointer limit stack).regs 0) := by
  have nativeRead0 : readMemory n.memory (n.gpr 7) 8=.ok (pointer,first) := by
    simpa only [memory,context] using read0
  have nativeRead1 : readMemory n.memory (n.gpr 7+(8#64)) 8=.ok (limit,second) := by
    simpa only [memory,context] using read1
  have unique := complete_native_relational_result n pointer limit first second actual
    nativePC nativeRead0 nativeRead1 run
  have old := complete_all_store_outcomes_correspondence env n p pointer limit stack first second
    nativePC proofPC active context memory nativeStack read0 read1 write40 write32 write24
    write16 write8 read40 read32 guest0 guest1
  exact ⟨unique,old.2⟩


/-- The complete captured path is selected only by canonical reads, actual
native comparisons and the first canonical store failure. -/
def allReadNativePath (n : X86.State) : List X86Path.Entry :=
  match readMemory n.memory (n.gpr 7) 8 with
  | .error _ => [⟨0,3⟩]
  | .ok (pointer,_) =>
    match readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | .error _ => [⟨0,3⟩,⟨3,4⟩]
    | .ok (limit,_) => completeNativePath n pointer limit

def allReadNativeResult (n : X86.State) : Transition X86.State :=
  match readMemory n.memory (n.gpr 7) 8 with
  | .error fault => ⟨n,[.fault fault],some fault⟩
  | .ok (pointer,first) =>
    match readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | .error fault => ⟨nativeAfter n pointer,[first,.fault fault],some fault⟩
    | .ok (limit,second) => completeNativeResult n pointer limit first second

/-- Every relational result on the actual selected complete captured path,
with no guest read/write success, failure or branch outcome premise. -/
theorem all_read_native_relational_result (n : X86.State) (actual : Transition X86.State)
    (position : n.pc=0)
    (run : CanonicalRelationalPath 0 native (allReadNativePath n) n actual) :
    actual=allReadNativeResult n := by
  cases read0 : readMemory n.memory (n.gpr 7) 8 with
  | error fault =>
    have contextRun : CanonicalRelationalPath 0 native (contextNativePath n) n actual := by
      simpa only [contextNativePath,allReadNativePath,read0] using run
    simpa only [contextNativeResult,allReadNativeResult,read0] using
      context_native_relational_result n actual position contextRun
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    cases read1 : readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | error fault =>
      have contextRun : CanonicalRelationalPath 0 native (contextNativePath n) n actual := by
        simpa only [contextNativePath,allReadNativePath,read0,read1] using run
      simpa only [contextNativeResult,allReadNativeResult,read0,read1] using
        context_native_relational_result n actual position contextRun
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      have completeRun : CanonicalRelationalPath 0 native (completeNativePath n pointer limit) n actual := by
        simpa only [allReadNativePath,read0,read1] using run
      simpa only [allReadNativeResult,read0,read1] using
        complete_native_relational_result n pointer limit first second actual position read0 read1 completeRun


theorem captured_all_permissions_relational_correspondence (env : BPF.Environment) (n : X86.State) (p : BPF.State)
    (stack : Word) (nativePC : n.pc=0) (proofPC : p.pc=0) (active : p.halted=false)
    (context : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack)
    (write40 : permitted p.memory.writable (p.regs 10-(40#64)) 8=true)
    (write32 : permitted p.memory.writable (p.regs 10-(32#64)) 8=true)
    (write24 : permitted p.memory.writable (p.regs 10-(24#64)) 8=true)
    (write16 : permitted p.memory.writable (p.regs 10-(16#64)) 8=true)
    (write8 : permitted p.memory.writable (p.regs 10-(8#64)) 4=true)
    (read40 : permitted p.memory.readable (p.regs 10-(40#64)) 8=true)
    (read32 : permitted p.memory.readable (p.regs 10-(32#64)) 8=true)
    (guest0 : ¬ initializationPrivateByte (p.regs 10) (p.regs 1))
    (actual : Transition X86.State)
    (run : CanonicalRelationalPath 0 native (allReadNativePath n) n actual)
    (guest1 : ∀ i<8, ¬ initializationPrivateByte (p.regs 10) (p.regs 1+(8#64)+BitVec.ofNat 64 i)) :
    actual=allReadNativeResult n ∧
    actual.state=allReadNativeFinal n p ∧ actual.events=allReadNativeTrace p ∧
    Execution (initializedInstructionStep env) p (allReadSetupTrace p++allReadGuestTrace p) (allReadProofFinal p stack) ∧
    (allReadSetupTrace p).filterMap (initializationProjectEvent (p.regs 10))++allReadGuestTrace p = allReadNativeTrace p ∧
    initializationAgreesOutside (p.regs 10) (allReadNativeFinal n p).memory (allReadProofFinal p stack).memory := by
  have unique := all_read_native_relational_result n actual nativePC run
  have stateTrace : (allReadNativeResult n).state=allReadNativeFinal n p ∧
      (allReadNativeResult n).events=allReadNativeTrace p := by
    unfold allReadNativeResult allReadNativeFinal allReadNativeTrace
    simp only [memory,context]
    cases read0 : readMemory p.memory (p.regs 1) 8 with
    | error fault => exact ⟨rfl,rfl⟩
    | ok pair =>
      rcases pair with ⟨pointer,first⟩
      cases read1 : readMemory p.memory (p.regs 1+(8#64)) 8 with
      | error fault => exact ⟨rfl,rfl⟩
      | ok pair =>
        rcases pair with ⟨limit,second⟩
        exact ⟨rfl,by simp only [completeNativeResult,memory]⟩
  have old := captured_all_read_write_outcomes env n p stack nativePC proofPC active context memory
    nativeStack write40 write32 write24 write16 write8 read40 read32 guest0 guest1
  exact ⟨unique,by simpa only [unique] using stateTrace.1,
    by simpa only [unique] using stateTrace.2,old.2⟩

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

#print axioms KProgTV.TrustedSimpleX86.initialization_slot_covers

#print axioms KProgTV.TrustedSimpleX86.initialization_slot_bytes

#print axioms KProgTV.TrustedSimpleX86.initialization_memory_agrees

#print axioms KProgTV.TrustedSimpleX86.initialization_erased_private

#print axioms KProgTV.TrustedSimpleX86.initialization_guest_event_retained

#print axioms KProgTV.TrustedSimpleX86.initialization_event_projection

#print axioms KProgTV.TrustedSimpleX86.initialization_spill_private

#print axioms KProgTV.TrustedSimpleX86.initialization_untouched_top

#print axioms KProgTV.TrustedSimpleX86.initialized_prefix_correspondence

#print axioms KProgTV.TrustedSimpleX86.native_decode7

#print axioms KProgTV.TrustedSimpleX86.native_decode10

#print axioms KProgTV.TrustedSimpleX86.native_decode12

#print axioms KProgTV.TrustedSimpleX86.native_decode15

#print axioms KProgTV.TrustedSimpleX86.compare_ja_predicate

#print axioms KProgTV.TrustedSimpleX86.xor_compare_flags_choice

#print axioms KProgTV.TrustedSimpleX86.guard_move_step

#print axioms KProgTV.TrustedSimpleX86.guard_zero_step

#print axioms KProgTV.TrustedSimpleX86.guard_compare_step

#print axioms KProgTV.TrustedSimpleX86.guard_branch_step

#print axioms KProgTV.TrustedSimpleX86.native_first_guard

#print axioms KProgTV.TrustedSimpleX86.proof_first_guard

#print axioms KProgTV.TrustedSimpleX86.guard_final_flags

#print axioms KProgTV.TrustedSimpleX86.first_guard_correspondence

#print axioms KProgFormal.Reference.X86.decode_ja_rel8

#print axioms KProgTV.TrustedSimpleX86.native_execution_append

#print axioms KProgTV.TrustedSimpleX86.entry_first_guard_correspondence

#print axioms KProgTV.TrustedSimpleX86.compare_after_relational_xor

#print axioms KProgTV.TrustedSimpleX86.fully_observed_step_unique

#print axioms KProgTV.TrustedSimpleX86.native_guard_relational_block

#print axioms KProgTV.TrustedSimpleX86.native_guard_decoded_relational_block

#print axioms KProgTV.TrustedSimpleX86.relational_first_guard_correspondence

#print axioms KProgTV.TrustedSimpleX86.ordinary_path_execution

#print axioms KProgTV.TrustedSimpleX86.remaining_proof72_block

#print axioms KProgTV.TrustedSimpleX86.remaining_proof8_block

#print axioms KProgTV.TrustedSimpleX86.remaining_proof_guards

#print axioms KProgTV.TrustedSimpleX86.remaining_proof_successor

#print axioms KProgTV.TrustedSimpleX86.native_decode17

#print axioms KProgTV.TrustedSimpleX86.native_decode21

#print axioms KProgTV.TrustedSimpleX86.native_decode24

#print axioms KProgTV.TrustedSimpleX86.native_decode26

#print axioms KProgTV.TrustedSimpleX86.native_decode30

#print axioms KProgTV.TrustedSimpleX86.native_decode33

#print axioms KProgTV.TrustedSimpleX86.remaining_native_lea_step

#print axioms KProgTV.TrustedSimpleX86.remaining_native_cmp8_step

#print axioms KProgTV.TrustedSimpleX86.remaining_native_branch8_step

#print axioms KProgTV.TrustedSimpleX86.add72_value

#print axioms KProgTV.TrustedSimpleX86.remaining_native_add72_step

#print axioms KProgTV.TrustedSimpleX86.remaining_native_cmp72_step

#print axioms KProgTV.TrustedSimpleX86.remaining_native_branch72_step

#print axioms KProgFormal.Reference.X86.decode_lea_rdi_rsi8
#print axioms KProgFormal.Reference.X86.decode_add_rsi72

#print axioms KProgTV.TrustedSimpleX86.remaining_native8_block

#print axioms KProgTV.TrustedSimpleX86.remaining_native72_block

#print axioms KProgTV.TrustedSimpleX86.remaining_native_guards

#print axioms KProgTV.TrustedSimpleX86.remaining_native_successor

#print axioms KProgTV.TrustedSimpleX86.remaining_guard_correspondence

#print axioms KProgTV.TrustedSimpleX86.remaining_native_frame

#print axioms KProgTV.TrustedSimpleX86.remaining_proof_frame

#print axioms KProgTV.TrustedSimpleX86.entry_all_guards_correspondence

#print axioms KProgTV.TrustedSimpleX86.packet_proof_block

#print axioms KProgTV.TrustedSimpleX86.packet_proof_execution

#print axioms KProgTV.TrustedSimpleX86.proof_exit_block

#print axioms KProgTV.TrustedSimpleX86.proof_exit_execution

#print axioms KProgTV.TrustedSimpleX86.packet_proof_return

#print axioms KProgTV.TrustedSimpleX86.native_decode35

#print axioms KProgTV.TrustedSimpleX86.native_decode40

#print axioms KProgTV.TrustedSimpleX86.native_decode44

#print axioms KProgTV.TrustedSimpleX86.native_decode51

#print axioms KProgTV.TrustedSimpleX86.native_decode55

#print axioms KProgTV.TrustedSimpleX86.store_byte_value_congr

#print axioms KProgTV.TrustedSimpleX86.native_immediate_store_step

#print axioms KProgTV.TrustedSimpleX86.packet_native_first_step

#print axioms KProgTV.TrustedSimpleX86.packet_native_second_step

#print axioms KProgTV.TrustedSimpleX86.packet_native_third_step

#print axioms KProgTV.TrustedSimpleX86.packet_native_fourth_step

#print axioms KProgTV.TrustedSimpleX86.packet_native_result_step

#print axioms KProgFormal.Reference.X86.decode_simple_packet_tail

#print axioms KProgTV.TrustedSimpleX86.native_packet_execution

#print axioms KProgTV.TrustedSimpleX86.initialization_store_agrees

#print axioms KProgTV.TrustedSimpleX86.packet_memory_agrees

#print axioms KProgTV.TrustedSimpleX86.packet_body_correspondence

#print axioms KProgTV.TrustedSimpleX86.conditional_complete_payload_correspondence

#print axioms KProgTV.TrustedSimpleX86.native_immediate_store_fault

#print axioms KProgTV.TrustedSimpleX86.packet_proof_first_fault_block

#print axioms KProgTV.TrustedSimpleX86.packet_proof_first_fault

#print axioms KProgTV.TrustedSimpleX86.packet_native_first_fault

#print axioms KProgTV.TrustedSimpleX86.first_store_fault_correspondence

#print axioms KProgTV.TrustedSimpleX86.packet_all_store_fault_blocks

#print axioms KProgTV.TrustedSimpleX86.packet_native_store_decodes

#print axioms KProgTV.TrustedSimpleX86.packet_all_native_store_faults

#print axioms KProgTV.TrustedSimpleX86.all_store_fault_correspondence

#print axioms KProgTV.TrustedSimpleX86.packet_first_failure_spec

#print axioms KProgTV.TrustedSimpleX86.packet_failure_index_agrees

#print axioms KProgTV.TrustedSimpleX86.packet_body_any_permissions

#print axioms KProgTV.TrustedSimpleX86.complete_all_store_outcomes_correspondence

#print axioms KProgTV.TrustedSimpleX86.native_memory_source_fault

#print axioms KProgTV.TrustedSimpleX86.initialized_context_load_fault

#print axioms KProgTV.TrustedSimpleX86.native_first_context_fault

#print axioms KProgTV.TrustedSimpleX86.native_second_context_fault

#print axioms KProgTV.TrustedSimpleX86.first_context_fault_correspondence

#print axioms KProgTV.TrustedSimpleX86.second_context_fault_correspondence

#print axioms KProgTV.TrustedSimpleX86.canonical_read_error

#print axioms KProgTV.TrustedSimpleX86.captured_all_read_write_outcomes

#print axioms KProgTV.TrustedSimpleX86.decode_extent_reflects_raw

#print axioms KProgTV.TrustedSimpleX86.simple_defined_decode_observed

#print axioms KProgTV.TrustedSimpleX86.simple_defined_decoded_step_unique

#print axioms KProgTV.TrustedSimpleX86.defined_relational_path_evaluation

#print axioms KProgTV.TrustedSimpleX86.defined_relational_result_unique

#print axioms KProgTV.TrustedSimpleX86.packet_fault_path_defined

#print axioms KProgTV.TrustedSimpleX86.all_store_fault_relational_correspondence

#print axioms KProgTV.TrustedSimpleX86.packet_native_evaluation

#print axioms KProgTV.TrustedSimpleX86.packet_outcome_path_defined

#print axioms KProgTV.TrustedSimpleX86.packet_native_any_evaluation

#print axioms KProgTV.TrustedSimpleX86.packet_body_relational_correspondence

#print axioms KProgTV.TrustedSimpleX86.relational_single_step

#print axioms KProgTV.TrustedSimpleX86.relational_cons_split

#print axioms KProgTV.TrustedSimpleX86.first_guard_relational_path_result

#print axioms KProgTV.TrustedSimpleX86.first_guard_path_relational_correspondence

#print axioms KProgTV.TrustedSimpleX86.canonical_evaluation_relational_sound

#print axioms KProgTV.TrustedSimpleX86.relational_path_append

#print axioms KProgTV.TrustedSimpleX86.remaining_native8_evaluation

#print axioms KProgTV.TrustedSimpleX86.remaining_native72_evaluation

#print axioms KProgTV.TrustedSimpleX86.remaining_native_path_defined

#print axioms KProgTV.TrustedSimpleX86.remaining_native_path_evaluation

#print axioms KProgTV.TrustedSimpleX86.remaining_guard_path_relational_correspondence


#print axioms KProgTV.TrustedSimpleX86.native_first_read_evaluation

#print axioms KProgTV.TrustedSimpleX86.native_second_read_evaluation

#print axioms KProgTV.TrustedSimpleX86.context_native_path_defined

#print axioms KProgTV.TrustedSimpleX86.context_native_path_evaluation

#print axioms KProgTV.TrustedSimpleX86.context_native_relational_result

#print axioms KProgTV.TrustedSimpleX86.relational_path_split_nonempty

#print axioms KProgTV.TrustedSimpleX86.entry_first_guard_relational_result

#print axioms KProgTV.TrustedSimpleX86.entry_first_guard_path_relational_correspondence


#print axioms KProgTV.TrustedSimpleX86.guarded_native_relational_result

#print axioms KProgTV.TrustedSimpleX86.entry_all_guards_path_relational_correspondence


#print axioms KProgTV.TrustedSimpleX86.guarded_native_body_boundary

#print axioms KProgTV.TrustedSimpleX86.packet_native_outcome_path_nonempty

#print axioms KProgTV.TrustedSimpleX86.complete_native_relational_result

#print axioms KProgTV.TrustedSimpleX86.complete_path_relational_correspondence

#print axioms KProgTV.TrustedSimpleX86.all_read_native_relational_result

#print axioms KProgTV.TrustedSimpleX86.captured_all_permissions_relational_correspondence
