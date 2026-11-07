import TrustedSimpleX86

/-! The actual82-byte fresh jit-invocation capture. This certificate covers its
entry wrapper independently of the unvalidated current B30. Stack writes are
retained host-ABI effects, not erased guest operations. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleJIT
open KProgFormal.Reference
open TrustedSimpleX86

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
