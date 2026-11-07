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
