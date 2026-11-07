import TrustedSimpleSafety

/-! The actual82-byte fresh jit-invocation capture. This certificate covers its
entry wrapper independently of the unvalidated current B30. Stack writes are
retained host-ABI effects, not erased guest operations. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleJIT
open KProgFormal.Reference
open TrustedSimpleX86 TrustedSimpleSafety

def image : Array Byte := #[0xf,0x1f,0x44,0x0,0x0,0xf,0x1f,0x0,0x55,0x48,0x89,0xe5,0x41,0x57,0x48,0x8b,0xf,0x48,0x8b,0x57,0x8,0x48,0x89,0xce,0x31,0xc0,0x48,0x39,0xd6,0x77,0x2b,0x48,0x8d,0x7e,0x8,0x48,0x39,0xd7,0x77,0x22,0x48,0x83,0xc6,0x48,0x48,0x39,0xd6,0x77,0x19,0x66,0xc7,0x1,0x4e,0x61,0xc6,0x41,0x2,0xbc,0xc7,0x41,0x3,0x0,0x0,0x0,0x0,0xc6,0x41,0x7,0x0,0xb8,0x2,0x0,0x0,0x0,0x41,0x5f,0xc9,0xe9,0xba,0x2f,0xc1,0xcb]
theorem image_size : image.size = 82 := rfl
theorem emitted_payload : image.extract 14 74 = native := by decide

theorem decode0 (s : X86.State) : X86.decode (image.extract 0 5) s = .ok (.nop (s.pc + (5#64))) := by
  have bytes : image.extract 0 5 = #[0x0f,0x1f,0x44,0,0] := by decide
  rw [bytes]; canonical_x86_decode

theorem decode5 (s : X86.State) : X86.decode (image.extract 5 8) s = .ok (.nop (s.pc + (3#64))) := by
  have bytes : image.extract 5 8 = #[0x0f,0x1f,0] := by decide
  rw [bytes]; canonical_x86_decode

theorem decode8 (s : X86.State) : X86.decode (image.extract 8 9) s = .ok (.push .w64 5 (s.pc + (1#64))) := by
  have bytes : image.extract 8 9 = #[0x55] := by decide
  rw [bytes]; canonical_x86_decode

theorem decode9 (s : X86.State) : X86.decode (image.extract 9 12) s = .ok
    (.move .w64 (.register (.low 5)) (.register (.low 4)) (s.pc + (3#64))) := by
  have bytes : image.extract 9 12 = #[0x48,0x89,0xe5] := by decide
  rw [bytes]; canonical_x86_decode

theorem decode12 (s : X86.State) : X86.decode (image.extract 12 14) s = .ok (.push .w64 15 (s.pc + (2#64))) := by
  have bytes : image.extract 12 14 = #[0x41,0x57] := by decide
  rw [bytes]; canonical_x86_decode

-- Full expected states, without assuming guest registers/flags are zero.
def afterNops (base : Word) (n : X86.State) : X86.State := {n with pc := base + (8#64)}
def afterBP (base : Word) (n : X86.State) : X86.State :=
  {n with
    gpr := fun r => if r=4 then n.gpr 4 - (8#64) else n.gpr r
    memory := storeMemory n.memory (n.gpr 4 - (8#64)) (n.gpr 5) 8
    pc := base + (9#64)}
def afterFrame (base : Word) (n : X86.State) : X86.State :=
  {afterBP base n with
    gpr := fun r => if r=5 then n.gpr 4 - (8#64) else (afterBP base n).gpr r
    pc := base + (12#64)}
def bodyEntry (base : Word) (n : X86.State) : X86.State :=
  {afterFrame base n with
    gpr := fun r => if r=4 then n.gpr 4 - (16#64) else (afterFrame base n).gpr r
    memory := storeMemory (afterFrame base n).memory (n.gpr 4 - (16#64)) (n.gpr 15) 8
    pc := base + (14#64)}

def saves (n : X86.State) : List Event :=
  [.memory .write (n.gpr 4 - (8#64)) (valueBytes (n.gpr 5) 8) true,
   .memory .write (n.gpr 4 - (16#64)) (valueBytes (n.gpr 15) 8) true]

private theorem sub8twice (sp : Word) : sp - (8#64) - (8#64) = sp - (16#64) := by
  unfold Word at *; bv_decide

private theorem move_frame (base : Word) (n : X86.State) :
    X86.step (.move .w64 (.register (.low 5)) (.register (.low 4)) (base + (12#64))) (afterBP base n) =
      ⟨afterFrame base n,[],none⟩ := by
  simp +decide [X86.step,X86.moveStep,X86.scalarRead,X86.scalarRegisterValue,
    X86.scalarWrite,X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
    X86.ScalarWidth.bits,X86.ScalarWidth.bytes,afterBP,afterFrame]

private theorem push_bp (base : Word) (n : X86.State)
    (permission : permitted n.memory.writable (n.gpr 4 - (8#64)) 8 = true) :
    X86.step (.push .w64 5 (base + (9#64))) (afterNops base n) =
      ⟨afterBP base n,[.memory .write (n.gpr 4 - (8#64)) (valueBytes (n.gpr 5) 8) true],none⟩ := by
  have write : writeMemory n.memory (n.gpr 4 - (8#64)) (n.gpr 5) 8 = .ok
      (storeMemory n.memory (n.gpr 4 - (8#64)) (n.gpr 5) 8,
       .memory .write (n.gpr 4 - (8#64)) (valueBytes (n.gpr 5) 8) true) := by
    simp only [writeMemory,permission,ite_true]
  simp only [X86.step,X86.pushTransfer,X86.StackWidth.bytes,afterNops]
  rw [write]
  rfl

private theorem push_r15 (base : Word) (n : X86.State)
    (permission : permitted n.memory.writable (n.gpr 4 - (16#64)) 8 = true) :
    X86.step (.push .w64 15 (base + (14#64))) (afterFrame base n) =
      ⟨bodyEntry base n,[.memory .write (n.gpr 4 - (16#64)) (valueBytes (n.gpr 15) 8) true],none⟩ := by
  have sp : (afterFrame base n).gpr 4 = n.gpr 4 - (8#64) := rfl
  have r15 : (afterFrame base n).gpr 15 = n.gpr 15 := rfl
  have write : writeMemory (afterFrame base n).memory (n.gpr 4 - (16#64)) (n.gpr 15) 8 = .ok
      (storeMemory (afterFrame base n).memory (n.gpr 4 - (16#64)) (n.gpr 15) 8,
       .memory .write (n.gpr 4 - (16#64)) (valueBytes (n.gpr 15) 8) true) := by
    change (if permitted n.memory.writable (n.gpr 4 - (16#64)) 8 then _ else _) = _
    rw [permission]
    rfl
  simp only [X86.step,X86.pushTransfer,X86.StackWidth.bytes]
  rw [sp,r15,sub8twice,write]
  rfl

/-- Whole actual wrapper path: NOPs perform no effective-address read. Both
PUSH writes remain in the ordered trace and preserve all unmentioned state. -/
theorem actual_entry_path (base : Word) (n : X86.State) (entry : n.pc=base)
    (saveBP : permitted n.memory.writable (n.gpr 4 - (8#64)) 8 = true)
    (saveR15 : permitted n.memory.writable (n.gpr 4 - (16#64)) 8 = true) :
    X86Path.Execution base image n (saves n) (bodyEntry base n) := by
  have d0 : X86Path.decodeAt base image ⟨0,5⟩ n = .ok (.nop (base + (5#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode0,entry,X86Path.fallthrough,
      X86.Instruction.fallthrough,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d1 : X86Path.decodeAt base image ⟨5,3⟩ {n with pc := base + (5#64)} = .ok (.nop (base + (8#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode5,X86Path.fallthrough,
      X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d2 : X86Path.decodeAt base image ⟨8,1⟩ (afterNops base n) = .ok (.push .w64 5 (base + (9#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode8,afterNops,X86Path.fallthrough,
      X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d3 : X86Path.decodeAt base image ⟨9,3⟩ (afterBP base n) = .ok
      (.move .w64 (.register (.low 5)) (.register (.low 4)) (base + (12#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode9,afterBP,X86Path.fallthrough,
      X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have d4 : X86Path.decodeAt base image ⟨12,2⟩ (afterFrame base n) = .ok (.push .w64 15 (base + (14#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode12,afterFrame,X86Path.fallthrough,
      X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have suffix := X86Path.Execution.next ⟨12,2⟩ _ d4
    (X86Path.Execution.refl (X86.step (.push .w64 15 (base + (14#64))) (afterFrame base n)).state)
  rw [push_r15 base n saveR15] at suffix
  have frame := X86Path.Execution.next ⟨9,3⟩ _ d3 (by rw [move_frame]; exact suffix)
  rw [move_frame] at frame
  have save := X86Path.Execution.next ⟨8,1⟩ _ d2 (by rw [push_bp base n saveBP]; exact frame)
  rw [push_bp base n saveBP] at save
  have second := X86Path.Execution.next ⟨5,3⟩ _ d1 (by simpa [X86.step,afterNops] using save)
  have first := X86Path.Execution.next ⟨0,5⟩ _ d0 (by simpa [X86.step] using second)
  have nop0 : X86.step (.nop (base + (5#64))) n = ⟨{n with pc := base + (5#64)},[],none⟩ := rfl
  have nop1 : X86.step (.nop (base + (8#64))) {n with pc := base + (5#64)} = ⟨afterNops base n,[],none⟩ := rfl
  simpa only [nop0,nop1,push_bp base n saveBP,move_frame,saves,
    List.nil_append,List.cons_append] using first

/-- Exact physical frame bias and unchanged incoming context. No reset of
registers, flags, SIMD state or memory to a convenient entry is performed. -/
theorem actual_entry_registers (base : Word) (n : X86.State) :
    (bodyEntry base n).pc = base + (14#64) ∧
    (bodyEntry base n).gpr 4 = n.gpr 4 - (16#64) ∧
    (bodyEntry base n).gpr 5 = n.gpr 4 - (8#64) ∧
    (bodyEntry base n).gpr 7 = n.gpr 7 ∧
    (bodyEntry base n).rflags = n.rflags ∧
    (bodyEntry base n).xmm0 = n.xmm0 ∧
    (bodyEntry base n).fsBase = n.fsBase ∧
    (bodyEntry base n).gsBase = n.gsBase ∧
    (bodyEntry base n).addressWidth = n.addressWidth := by
  simp +decide [bodyEntry,afterFrame,afterBP]


/-- The16-byte save frame is the only changed memory. This reuses the existing
canonical-memory algebra; the PUSH events above are still retained. -/
theorem actual_entry_memory (base : Word) (n : X86.State) :
    PrivateSpills.AgreesOutside (n.gpr 4) n.memory (bodyEntry base n).memory := by
  exact PrivateSpills.two_spills_preserve_guest n.memory (n.gpr 4) (n.gpr 5) (n.gpr 15)

/-- The original caller's saved return slot is above both PUSH writes. Its
complete read result, initialization, permissions and any fault stay exact. -/
theorem actual_outer_return_slot (base : Word) (n : X86.State) :
    readMemory (bodyEntry base n).memory (n.gpr 4) 8 = readMemory n.memory (n.gpr 4) 8 := by
  apply (PrivateSpills.guest_reads_preserved (n.gpr 4) (n.gpr 4) 8
    n.memory (bodyEntry base n).memory (actual_entry_memory base n) ?_).symm
  intro i small
  apply PrivateSpills.above_frame_guest
  have bound : i < 2^64 := by omega
  change i % 2^64 < 8
  simpa only [Nat.mod_eq_of_lt bound] using small

/-- Values restored later must be the actual incoming callee-save words, not
values assumed after the native body. -/
theorem actual_saved_r15 (base : Word) (n : X86.State)
    (permission : permitted n.memory.readable (n.gpr 4-(16#64)) 8 = true) :
    readMemory (bodyEntry base n).memory (n.gpr 4-(16#64)) 8 = .ok
      (n.gpr 15,.memory .read (n.gpr 4-(16#64)) (valueBytes (n.gpr 15) 8) true) := by
  exact PrivateSpills.spill_read _ _ _ permission

theorem actual_saved_bp (base : Word) (n : X86.State)
    (permission : permitted n.memory.readable (n.gpr 4-(8#64)) 8 = true) :
    readMemory (bodyEntry base n).memory (n.gpr 4-(8#64)) 8 = .ok
      (n.gpr 5,.memory .read (n.gpr 4-(8#64)) (valueBytes (n.gpr 5) 8) true) := by
  exact PrivateSpills.upper_spill_reload n.memory (n.gpr 4) (n.gpr 5) (n.gpr 15) permission


-- Relocation identity from the new capture's live kernel symbol receipt.
def returnDisplacement : Word := (0xcbc12fba#32).signExtend 64
def returnTarget (base : Word) : Word := base + (82#64) + returnDisplacement

theorem decode77 (s : X86.State) : X86.decode (image.extract 77 82) s = .ok
    (.branch none (s.pc+(5#64)+returnDisplacement) (s.pc+(5#64))) := by
  have bytes : image.extract 77 82 = #[0xe9,0xba,0x2f,0xc1,0xcb] := by decide
  rw [bytes]
  unfold returnDisplacement
  canonical_x86_decode

/-- The final byte-decoded JMP preserves every component except PC and has
no memory/helper effects. The missing LEAVE boundary is not skipped. -/
theorem actual_return_edge (base : Word) (s : X86.State) (position : s.pc=base+(77#64)) :
    X86Path.decodeAt base image ⟨77,5⟩ s = .ok
      (.branch none (returnTarget base) (base+(82#64))) ∧
    X86.step (.branch none (returnTarget base) (base+(82#64))) s =
      ⟨{s with pc := returnTarget base},[],none⟩ := by
  constructor
  · simp +decide [X86Path.decodeAt,image_size,decode77,position,returnTarget,
      X86Path.fallthrough,X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  · rfl

theorem captured_return_symbol : returnTarget (18446744072640010388#64) = (18446744071763478688#64) := by decide


/-- Generalize the existing return-slot lemma to either save slot or the
outer return slot. Every packet-store success/fault outcome remains covered. -/
theorem complete_body_preserves_slot (n : X86.State) (pointer limit slot : Word)
    (first second : Event) (apart : packetReturnSlotApart pointer slot) :
    readMemory (completeNativeResult n pointer limit first second).state.memory slot 8 =
      readMemory n.memory slot 8 := by
  obtain ⟨pointerMatch,_,memoryMatch⟩ := guarded_native_return_slot_frame n pointer limit
  by_cases reject : pointer>limit ∨ pointer+(8#64)>limit ∨ pointer+(72#64)>limit
  · simp only [completeNativeResult,completeNativeFinal,reject,ite_true,memoryMatch]
  · have guardedApart : packetReturnSlotApart ((guardedNativeFinal n pointer limit).gpr 1) slot := by
      rw [pointerMatch]; exact apart
    have unchanged := packet_native_outcome_return_slot (guardedNativeFinal n pointer limit)
      (packetFirstFailure n.memory pointer) slot guardedApart
    simpa only [completeNativeResult,completeNativeFinal,reject,ite_false,memoryMatch] using unchanged

theorem total_body_preserves_slot (n : X86.State) (slot : Word)
    (apart : ∀ pointer event, readMemory n.memory (n.gpr 7) 8 = .ok (pointer,event) →
      packetReturnSlotApart pointer slot) :
    readMemory (allReadNativeResult n).state.memory slot 8 = readMemory n.memory slot 8 := by
  cases read0 : readMemory n.memory (n.gpr 7) 8 with
  | error fault => simp only [allReadNativeResult,read0]
  | ok pair =>
    rcases pair with ⟨pointer,first⟩
    cases read1 : readMemory n.memory (n.gpr 7+(8#64)) 8 with
    | error fault => simp only [allReadNativeResult,read0,read1,nativeAfter]
    | ok pair =>
      rcases pair with ⟨limit,second⟩
      simp only [allReadNativeResult,read0,read1]
      exact complete_body_preserves_slot n pointer limit slot first second (apart pointer first read0)

/-- The slot is chosen independently of RSP. This applies to actual complete
canonical paths, with arbitrary extents, AF observations and access outcomes. -/
theorem actual_body_preserves_slot (n : X86.State) (actual : Transition X86.State) (slot : Word)
    (position : n.pc=0)
    (run : CanonicalRelationalPath 0 native (allReadNativePath n) n actual)
    (apart : ∀ pointer event, readMemory n.memory (n.gpr 7) 8 = .ok (pointer,event) →
      packetReturnSlotApart pointer slot) :
    readMemory actual.state.memory slot 8 = readMemory n.memory slot 8 := by
  rw [all_read_native_relational_result n actual position run]
  exact total_body_preserves_slot n slot apart

theorem decode74 (s : X86.State) : X86.decode (image.extract 74 76) s = .ok
    (.pop .w64 15 (s.pc+(2#64))) := by
  have bytes : image.extract 74 76 = #[0x41,0x5f] := by decide
  rw [bytes]; canonical_x86_decode

def afterPop (base : Word) (s : X86.State) (value : Word) : X86.State :=
  {s with
    gpr := fun r => if r=15 then value else if r=4 then s.gpr 4+(8#64) else s.gpr r
    pc := base+(76#64)}

/-- The actual tail POP restores its value from memory, advances SP and
retains the read event; the subsequent LEAVE is still a separate instruction. -/
theorem actual_pop_step (base : Word) (s : X86.State) (value : Word) (event : Event)
    (position : s.pc=base+(74#64))
    (read : readMemory s.memory (s.gpr 4) 8 = .ok (value,event)) :
    X86Path.decodeAt base image ⟨74,2⟩ s = .ok (.pop .w64 15 (base+(76#64))) ∧
    X86.step (.pop .w64 15 (base+(76#64))) s = ⟨afterPop base s value,[event],none⟩ := by
  constructor
  · simp +decide [X86Path.decodeAt,image_size,decode74,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  · simp +decide [X86.step,X86.readSource,X86.StackWidth.bytes,X86.StackWidth.registerWidth,
      X86.cmovValue,read,afterPop]


/-- Connect actual wrapper stores to arbitrary canonical body outcomes. The
three separation facts are kernel invocation-layout obligations, not runtime
checks or assumptions of successful guest accesses. -/
theorem actual_body_saved_words (base : Word) (caller n : X86.State)
    (actual : Transition X86.State)
    (entry : n={bodyEntry base caller with pc := 0})
    (run : CanonicalRelationalPath 0 native (allReadNativePath n) n actual)
    (apart : ∀ pointer event, readMemory n.memory (n.gpr 7) 8 = .ok (pointer,event) →
      packetReturnSlotApart pointer (caller.gpr 4-(16#64)) ∧
      packetReturnSlotApart pointer (caller.gpr 4-(8#64)) ∧
      packetReturnSlotApart pointer (caller.gpr 4))
    (readR15 : permitted caller.memory.readable (caller.gpr 4-(16#64)) 8 = true)
    (readBP : permitted caller.memory.readable (caller.gpr 4-(8#64)) 8 = true) :
    readMemory actual.state.memory (caller.gpr 4-(16#64)) 8 = .ok
      (caller.gpr 15,.memory .read (caller.gpr 4-(16#64)) (valueBytes (caller.gpr 15) 8) true) ∧
    readMemory actual.state.memory (caller.gpr 4-(8#64)) 8 = .ok
      (caller.gpr 5,.memory .read (caller.gpr 4-(8#64)) (valueBytes (caller.gpr 5) 8) true) ∧
    readMemory actual.state.memory (caller.gpr 4) 8 = readMemory caller.memory (caller.gpr 4) 8 := by
  have position : n.pc=0 := by rw [entry]
  have lower := actual_body_preserves_slot n actual (caller.gpr 4-(16#64)) position run
    (fun pointer event read => (apart pointer event read).1)
  have upper := actual_body_preserves_slot n actual (caller.gpr 4-(8#64)) position run
    (fun pointer event read => (apart pointer event read).2.1)
  have outer := actual_body_preserves_slot n actual (caller.gpr 4) position run
    (fun pointer event read => (apart pointer event read).2.2)
  refine ⟨?_,?_,?_⟩
  · rw [lower,entry]
    exact actual_saved_r15 base caller readR15
  · rw [upper,entry]
    exact actual_saved_bp base caller readBP
  · rw [outer,entry]
    exact actual_outer_return_slot base caller


/-- The actual C9 byte, interpreted only by V's canonical LEAVE rule. -/
theorem decode76 (s : X86.State) : X86.decode (image.extract 76 77) s = .ok
    (.leave64 (s.pc+(1#64))) := by
  have bytes : image.extract 76 77 = #[0xc9] := by decide
  rw [bytes]
  exact X86.leave64_decode s

def afterLeave (base : Word) (s : X86.State) (value : Word) : X86.State :=
  {s with
    gpr := fun r => if r=4 then s.gpr 5+(8#64) else if r=5 then value else s.gpr r
    pc := base+(77#64)}

theorem actual_leave_step (base : Word) (s : X86.State) (value : Word) (event : Event)
    (position : s.pc=base+(76#64))
    (read : readMemory s.memory (s.gpr 5) 8 = .ok (value,event)) :
    X86Path.decodeAt base image ⟨76,1⟩ s = .ok (.leave64 (base+(77#64))) ∧
    X86.step (.leave64 (base+(77#64))) s = ⟨afterLeave base s value,[event],none⟩ := by
  constructor
  · simp +decide [X86Path.decodeAt,image_size,decode76,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  · exact X86.leave64_read_success _ value event s read

/-- The two real failure boundaries retain the complete incoming state.
In particular a failed LEAVE never commits an intermediate RSP=RBP. -/
theorem actual_leave_fault (base : Word) (s : X86.State) (fault : Fault)
    (read : readMemory s.memory (s.gpr 5) 8 = .error fault) :
    X86.step (.leave64 (base+(77#64))) s = ⟨s,[.fault fault],some fault⟩ :=
  X86.leave64_read_fault _ fault s read

theorem actual_pop_fault (base : Word) (s : X86.State) (fault : Fault)
    (read : readMemory s.memory (s.gpr 4) 8 = .error fault) :
    X86.step (.pop .w64 15 (base+(76#64))) s = ⟨s,[.fault fault],some fault⟩ := by
  simp only [X86.step,X86.readSource,X86.StackWidth.bytes,read]

/-- A real complete POP/LEAVE/JMP path through the captured image. Both
reads remain ordered; no return-slot access or host effect is erased. -/
theorem actual_epilogue_path (base : Word) (s : X86.State)
    (saved15 savedBP : Word) (event15 eventBP : Event)
    (position : s.pc=base+(74#64))
    (read15 : readMemory s.memory (s.gpr 4) 8 = .ok (saved15,event15))
    (readBP : readMemory s.memory (s.gpr 5) 8 = .ok (savedBP,eventBP)) :
    X86Path.Execution base image s [event15,eventBP]
      {afterLeave base (afterPop base s saved15) savedBP with pc := returnTarget base} := by
  have pop := actual_pop_step base s saved15 event15 position read15
  have frameRead : readMemory (afterPop base s saved15).memory
      ((afterPop base s saved15).gpr 5) 8 = .ok (savedBP,eventBP) := by
    simpa +decide [afterPop] using readBP
  have leave := actual_leave_step base (afterPop base s saved15) savedBP eventBP rfl frameRead
  have jump := actual_return_edge base (afterLeave base (afterPop base s saved15) savedBP) rfl
  have tail := X86Path.Execution.next ⟨77,5⟩ _ jump.1
    (X86Path.Execution.refl (X86.step (.branch none (returnTarget base) (base+(82#64)))
      (afterLeave base (afterPop base s saved15) savedBP)).state)
  rw [jump.2] at tail
  have middle := X86Path.Execution.next ⟨76,1⟩ _ leave.1
    (by rw [leave.2]; exact tail)
  rw [leave.2] at middle
  have full := X86Path.Execution.next ⟨74,2⟩ _ pop.1
    (by rw [pop.2]; exact middle)
  rw [pop.2] at full
  simpa using full

/-- Exact full-state endpoint: only the three saved registers and PC change
from the body exit. RAX/result, flags, SIMD, memory and all other GPRs remain. -/
theorem epilogue_restores_caller_frame (base : Word) (caller s : X86.State)
    (frame : s.gpr 5=caller.gpr 4-(8#64)) :
    {afterLeave base (afterPop base s (caller.gpr 15)) (caller.gpr 5) with pc := returnTarget base} =
    {s with
      gpr := fun r => if r=4 then caller.gpr 4 else if r=5 then caller.gpr 5
        else if r=15 then caller.gpr 15 else s.gpr r
      pc := returnTarget base} := by
  have cancel : caller.gpr 4-(8#64)+(8#64)=caller.gpr 4 := BitVec.sub_add_cancel _ _
  simp only [afterLeave,afterPop]
  congr 1
  funext r
  by_cases sp : r=4
  · subst r; simp +decide [frame,cancel]
  · by_cases bp : r=5
    · subst r; simp +decide
    · by_cases saved : r=15
      · subst r; simp +decide
      · simp only [sp,bp,saved,ite_false]


theorem actual_epilogue_pop_fault_path (base : Word) (s : X86.State) (fault : Fault)
    (position : s.pc=base+(74#64))
    (read : readMemory s.memory (s.gpr 4) 8 = .error fault) :
    X86Path.Execution base image s [.fault fault] s := by
  have decoded : X86Path.decodeAt base image ⟨74,2⟩ s = .ok (.pop .w64 15 (base+(76#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode74,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have path := X86Path.Execution.next ⟨74,2⟩ _ decoded
    (X86Path.Execution.refl (X86.step (.pop .w64 15 (base+(76#64))) s).state)
  rw [actual_pop_fault base s fault read] at path
  simpa using path

theorem actual_epilogue_leave_fault_path (base : Word) (s : X86.State)
    (value : Word) (event : Event) (fault : Fault)
    (position : s.pc=base+(74#64))
    (read15 : readMemory s.memory (s.gpr 4) 8 = .ok (value,event))
    (readBP : readMemory s.memory (s.gpr 5) 8 = .error fault) :
    X86Path.Execution base image s [event,.fault fault] (afterPop base s value) := by
  have pop := actual_pop_step base s value event position read15
  have frameRead : readMemory (afterPop base s value).memory
      ((afterPop base s value).gpr 5) 8 = .error fault := by
    simpa +decide [afterPop] using readBP
  have decoded : X86Path.decodeAt base image ⟨76,1⟩ (afterPop base s value) =
      .ok (.leave64 (base+(77#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode76,afterPop,
      X86Path.fallthrough,X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have failed := actual_leave_fault base (afterPop base s value) fault frameRead
  have tail := X86Path.Execution.next ⟨76,1⟩ _ decoded
    (X86Path.Execution.refl (X86.step (.leave64 (base+(77#64))) (afterPop base s value)).state)
  rw [failed] at tail
  have path := X86Path.Execution.next ⟨74,2⟩ _ pop.1 (by rw [pop.2]; exact tail)
  rw [pop.2] at path
  simpa using path

/-- The successful wrapper never changes the native result or any memory,
flags, SIMD, segment base or address-width state. -/
theorem epilogue_preserves_result (base : Word) (s : X86.State) (saved15 savedBP : Word) :
    let last := {afterLeave base (afterPop base s saved15) savedBP with pc := returnTarget base}
    last.gpr 0=s.gpr 0 ∧ last.memory=s.memory ∧ last.rflags=s.rflags ∧
      last.xmm0=s.xmm0 ∧ last.fsBase=s.fsBase ∧ last.gsBase=s.gsBase ∧
      last.addressWidth=s.addressWidth := by
  simp +decide [afterLeave,afterPop]

end KProgTV.TrustedSimpleJIT
#print axioms KProgTV.TrustedSimpleJIT.emitted_payload
#print axioms KProgTV.TrustedSimpleJIT.actual_entry_path
#print axioms KProgTV.TrustedSimpleJIT.actual_entry_registers
#print axioms KProgTV.TrustedSimpleJIT.actual_entry_memory
#print axioms KProgTV.TrustedSimpleJIT.actual_outer_return_slot
#print axioms KProgTV.TrustedSimpleJIT.actual_saved_r15
#print axioms KProgTV.TrustedSimpleJIT.actual_saved_bp
#print axioms KProgTV.TrustedSimpleJIT.actual_return_edge
#print axioms KProgTV.TrustedSimpleJIT.captured_return_symbol
#print axioms KProgTV.TrustedSimpleJIT.complete_body_preserves_slot
#print axioms KProgTV.TrustedSimpleJIT.total_body_preserves_slot
#print axioms KProgTV.TrustedSimpleJIT.actual_body_preserves_slot
#print axioms KProgTV.TrustedSimpleJIT.actual_pop_step

#print axioms KProgTV.TrustedSimpleJIT.actual_body_saved_words
#print axioms KProgTV.TrustedSimpleJIT.actual_leave_step
#print axioms KProgTV.TrustedSimpleJIT.actual_leave_fault
#print axioms KProgTV.TrustedSimpleJIT.actual_pop_fault
#print axioms KProgTV.TrustedSimpleJIT.actual_epilogue_path
#print axioms KProgTV.TrustedSimpleJIT.epilogue_restores_caller_frame
#print axioms KProgTV.TrustedSimpleJIT.actual_epilogue_pop_fault_path
#print axioms KProgTV.TrustedSimpleJIT.actual_epilogue_leave_fault_path
#print axioms KProgTV.TrustedSimpleJIT.epilogue_preserves_result
