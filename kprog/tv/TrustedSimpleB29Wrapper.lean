import TrustedSimpleB29Embedding
import TrustedSimpleJIT

/-! Wrapper semantics for the SAME fresh image as the B29 physical payload.
Reuse the prior wrapper's pure frame constructors and canonical ISA. Actual
code slices and the new return displacement are checked from this image;
no old-session return PC is used. Caller permissions remain premises. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleB29Wrapper
open KProgFormal.Reference TrustedSimpleX86 TrustedSimpleSafety TrustedSimpleJIT

abbrev image := TrustedSimpleB29Embedding.image
theorem image_size : image.size=82 := rfl

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

theorem decode74 (s : X86.State) : X86.decode (image.extract 74 76) s = .ok
    (.pop .w64 15 (s.pc+(2#64))) := by
  have bytes : image.extract 74 76 = #[0x41,0x5f] := by decide
  rw [bytes]; canonical_x86_decode

theorem decode76 (s : X86.State) : X86.decode (image.extract 76 77) s = .ok
    (.leave64 (s.pc+(1#64))) := by
  have bytes : image.extract 76 77 = #[0xc9] := by decide
  rw [bytes]
  exact X86.leave64_decode s

private theorem sub8twice (sp : Word) : sp - (8#64) - (8#64) = sp - (16#64) := by
  unfold Word at *; bv_decide

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

private theorem move_frame (base : Word) (n : X86.State) :
    X86.step (.move .w64 (.register (.low 5)) (.register (.low 4)) (base + (12#64))) (afterBP base n) =
      ⟨afterFrame base n,[],none⟩ := by
  simp +decide [X86.step,X86.moveStep,X86.scalarRead,X86.scalarRegisterValue,
    X86.scalarWrite,X86.scalarWriteValue,X86.RegisterSlice.reg,X86.RegisterSlice.shift,
    X86.ScalarWidth.bits,X86.ScalarWidth.bytes,afterBP,afterFrame]

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

def returnDisplacement : Word := (0xdfc12fbe#32).signExtend 64
def returnTarget (base : Word) : Word := base+(82#64)+returnDisplacement

theorem decode77 (s : X86.State) : X86.decode (image.extract 77 82) s = .ok
    (.branch none (s.pc+(5#64)+returnDisplacement) (s.pc+(5#64))) := by
  have bytes : image.extract 77 82 = #[0xe9,0xbe,0x2f,0xc1,0xdf] := by decide
  rw [bytes]
  unfold returnDisplacement
  canonical_x86_decode

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

theorem captured_return_symbol : returnTarget (18446744072640010384#64)=
    (18446744072099023008#64) := by decide

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

theorem actual_leave_step (base : Word) (s : X86.State) (value : Word) (event : Event)
    (position : s.pc=base+(76#64))
    (canonicalFrame : X86.leave64FrameCanonical s=true)
    (read : readMemory s.memory (s.gpr 5) 8 = .ok (value,event)) :
    X86Path.decodeAt base image ⟨76,1⟩ s = .ok (.leave64 (base+(77#64))) ∧
    X86.step (.leave64 (base+(77#64))) s = ⟨afterLeave base s value,[event],none⟩ := by
  constructor
  · simp +decide [X86Path.decodeAt,image_size,decode76,position,
      X86Path.fallthrough,X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  · exact X86.leave64_read_success _ value event s canonicalFrame read

theorem actual_leave_fault (base : Word) (s : X86.State) (fault : Fault)
    (canonicalFrame : X86.leave64FrameCanonical s=true)
    (read : readMemory s.memory (s.gpr 5) 8 = .error fault) :
    X86.step (.leave64 (base+(77#64))) s = ⟨s,[.fault fault],some fault⟩ :=
  X86.leave64_read_fault _ fault s canonicalFrame read

theorem actual_pop_fault (base : Word) (s : X86.State) (fault : Fault)
    (read : readMemory s.memory (s.gpr 4) 8 = .error fault) :
    X86.step (.pop .w64 15 (base+(76#64))) s = ⟨s,[.fault fault],some fault⟩ := by
  simp only [X86.step,X86.readSource,X86.StackWidth.bytes,read]

theorem actual_epilogue_path (base : Word) (s : X86.State)
    (saved15 savedBP : Word) (event15 eventBP : Event)
    (position : s.pc=base+(74#64))
    (canonicalFrame : X86.leave64FrameCanonical s=true)
    (read15 : readMemory s.memory (s.gpr 4) 8 = .ok (saved15,event15))
    (readBP : readMemory s.memory (s.gpr 5) 8 = .ok (savedBP,eventBP)) :
    X86Path.Execution base image s [event15,eventBP]
      {afterLeave base (afterPop base s saved15) savedBP with pc := returnTarget base} := by
  have pop := actual_pop_step base s saved15 event15 position read15
  have frameRead : readMemory (afterPop base s saved15).memory
      ((afterPop base s saved15).gpr 5) 8 = .ok (savedBP,eventBP) := by
    simpa +decide [afterPop] using readBP
  have frameOK : X86.leave64FrameCanonical (afterPop base s saved15)=true := by
    simpa +decide [X86.leave64FrameCanonical,afterPop] using canonicalFrame
  have leave := actual_leave_step base (afterPop base s saved15) savedBP eventBP rfl frameOK frameRead
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
    (canonicalFrame : X86.leave64FrameCanonical s=true)
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
  have frameOK : X86.leave64FrameCanonical (afterPop base s value)=true := by
    simpa +decide [X86.leave64FrameCanonical,afterPop] using canonicalFrame
  have failed := actual_leave_fault base (afterPop base s value) fault frameOK frameRead
  have tail := X86Path.Execution.next ⟨76,1⟩ _ decoded
    (X86Path.Execution.refl (X86.step (.leave64 (base+(77#64))) (afterPop base s value)).state)
  rw [failed] at tail
  have path := X86Path.Execution.next ⟨74,2⟩ _ pop.1 (by rw [pop.2]; exact tail)
  rw [pop.2] at path
  simpa using path

theorem actual_return_thunk_success (base : Word) (s : X86.State) (target : Word) (event : Event)
    (position : s.pc=returnTarget base)
    (read : readMemory s.memory (s.gpr 4) 8 = .ok (target,event))
    (canonical : X86.canonicalTarget s.addressWidth target=true) :
    X86Path.decodeAt (returnTarget base) returnThunk ⟨0,1⟩ s =
      .ok (.returnNear (0#16) (returnTarget base+(1#64))) ∧
    X86.step (.returnNear (0#16) (returnTarget base+(1#64))) s =
      ⟨afterOuterReturn s target,[event],none⟩ := by
  constructor
  · simp +decide [X86Path.decodeAt,returnThunk,position,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    canonical_x86_decode
    all_goals simp +decide [position,X86Path.fallthrough,X86.Instruction.fallthrough]
  · simp +decide [X86.step,X86.returnStep,read,canonical,afterOuterReturn]

theorem actual_return_thunk_read_fault (base : Word) (s : X86.State) (fault : Fault)
    (read : readMemory s.memory (s.gpr 4) 8 = .error fault) :
    X86.step (.returnNear (0#16) (returnTarget base+(1#64))) s =
      ⟨s,[.fault fault],some fault⟩ := by
  simp only [X86.step,X86.returnStep,read]

theorem actual_return_thunk_target_fault (base : Word) (s : X86.State) (target : Word) (event : Event)
    (read : readMemory s.memory (s.gpr 4) 8 = .ok (target,event))
    (noncanonical : X86.canonicalTarget s.addressWidth target=false) :
    X86.step (.returnNear (0#16) (returnTarget base+(1#64))) s =
      ⟨s,[event,.fault (.nonCanonical target)],some (.nonCanonical target)⟩ := by
  simp only [X86.step,X86.returnStep,read,noncanonical,Bool.false_eq_true,ite_false]

theorem actual_epilogue_and_return (base : Word) (caller s : X86.State)
    (target : Word) (event15 eventBP outerEvent : Event)
    (position : s.pc=base+(74#64))
    (canonicalFrame : X86.leave64FrameCanonical s=true)
    (stack : s.gpr 4=caller.gpr 4-(16#64))
    (frame : s.gpr 5=caller.gpr 4-(8#64))
    (read15 : readMemory s.memory (caller.gpr 4-(16#64)) 8 = .ok
      (caller.gpr 15,event15))
    (readBP : readMemory s.memory (caller.gpr 4-(8#64)) 8 = .ok
      (caller.gpr 5,eventBP))
    (outerRead : readMemory s.memory (caller.gpr 4) 8 = .ok (target,outerEvent))
    (canonical : X86.canonicalTarget s.addressWidth target=true) :
    ∃ middle,
      X86Path.Execution base image s [event15,eventBP] middle ∧
      X86Path.Execution (returnTarget base) returnThunk middle [outerEvent]
        (afterOuterReturn
          {s with
            gpr := fun r => if r=4 then caller.gpr 4 else if r=5 then caller.gpr 5
              else if r=15 then caller.gpr 15 else s.gpr r
            pc := returnTarget base} target) := by
  have lower : readMemory s.memory (s.gpr 4) 8 = .ok (caller.gpr 15,event15) := by
    rw [stack]; exact read15
  have upper : readMemory s.memory (s.gpr 5) 8 = .ok (caller.gpr 5,eventBP) := by
    rw [frame]; exact readBP
  let middle := {afterLeave base (afterPop base s (caller.gpr 15)) (caller.gpr 5)
    with pc := returnTarget base}
  have epilogue : X86Path.Execution base image s [event15,eventBP] middle :=
    actual_epilogue_path base s _ _ _ _ position canonicalFrame lower upper
  have restored := epilogue_restores_caller_frame base caller s frame
  have middleSP : middle.gpr 4=caller.gpr 4 := by
    simp +decide [middle,afterLeave,afterPop,frame,BitVec.sub_add_cancel]
  have read : readMemory middle.memory (middle.gpr 4) 8 = .ok (target,outerEvent) := by
    rw [middleSP]
    exact outerRead
  have good : X86.canonicalTarget middle.addressWidth target=true := canonical
  have returned := actual_return_thunk_success base middle target outerEvent rfl read good
  have path := X86Path.Execution.next ⟨0,1⟩ _ returned.1
    (X86Path.Execution.refl (X86.step (.returnNear (0#16) (returnTarget base+(1#64))) middle).state)
  rw [returned.2] at path
  refine ⟨middle,epilogue,?_⟩
  have endpoint := congrArg (fun state => afterOuterReturn state target) restored
  change afterOuterReturn middle target = _ at endpoint
  rw [endpoint] at path
  simpa only [List.append_nil] using path

theorem actual_leave_address_fault (base : Word) (s : X86.State)
    (badFrame : X86.leave64FrameCanonical s=false) :
    X86.step (.leave64 (base+(77#64))) s =
      ⟨s,[.fault (.nonCanonical (s.gpr 5))],some (.nonCanonical (s.gpr 5))⟩ :=
  X86.leave64_noncanonical _ s badFrame

theorem actual_epilogue_address_fault_path (base : Word) (s : X86.State) (value : Word) (event : Event)
    (position : s.pc=base+(74#64))
    (read15 : readMemory s.memory (s.gpr 4) 8 = .ok (value,event))
    (badFrame : X86.leave64FrameCanonical s=false) :
    X86Path.Execution base image s [event,.fault (.nonCanonical (s.gpr 5))] (afterPop base s value) := by
  have pop := actual_pop_step base s value event position read15
  have bad : X86.leave64FrameCanonical (afterPop base s value)=false := by
    simpa +decide [X86.leave64FrameCanonical,afterPop] using badFrame
  have address : (afterPop base s value).gpr 5=s.gpr 5 := by simp +decide [afterPop]
  have decoded : X86Path.decodeAt base image ⟨76,1⟩ (afterPop base s value) =
      .ok (.leave64 (base+(77#64))) := by
    simp +decide [X86Path.decodeAt,image_size,decode76,afterPop,
      X86Path.fallthrough,X86.Instruction.fallthrough,BitVec.add_assoc,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have failed := actual_leave_address_fault base (afterPop base s value) bad
  have tail := X86Path.Execution.next ⟨76,1⟩ _ decoded
    (X86Path.Execution.refl (X86.step (.leave64 (base+(77#64))) (afterPop base s value)).state)
  rw [failed] at tail
  have path := X86Path.Execution.next ⟨74,2⟩ _ pop.1 (by rw [pop.2]; exact tail)
  rw [pop.2] at path
  simpa only [address,List.cons_append,List.nil_append,List.append_nil] using path

/-- The real current-image prologue keeps its two stack writes, then the
actual P60 body has only verifier-checked guest effects. Same-context and
post-prologue memory/ABI premises are explicit; caller state is not reset. -/
theorem actual_entry_and_checked_body (env : BPF.Environment) (base : Word)
    (caller : X86.State) (p : BPF.State)
    (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=TrustedSimpleB29.proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ artifact, accepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (TrustedSimpleB29.boundProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    {events : List Event} {last : X86.State}
    (run : Execution (TrustedSimpleB29Embedding.payloadInstructionStep base image)
      (bodyEntry base caller) events last)
    (callerPC : caller.pc=base)
    (saveBP : permitted caller.memory.writable (caller.gpr 4-(8#64)) 8=true)
    (saveR15 : permitted caller.memory.writable (caller.gpr 4-(16#64)) 8=true)
    (proofPC : p.pc=0) (active : p.halted=false) (argument : caller.gpr 7=p.regs 1)
    (memory : (bodyEntry base caller).memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok (caller.gpr 4-(16#64))) :
    X86Path.Execution base image caller (saves caller) (bodyEntry base caller) ∧
      ∀ event ∈ events, checked validated event := by
  refine ⟨actual_entry_path base caller callerPC saveBP saveR15,?_⟩
  apply TrustedSimpleB29Embedding.bound_physical_payload_prefix_effects_checked env base image rfl
    (bodyEntry base caller) p validated executed binding nativeImage proofImage entryImage
    accepted proofEntry checked verifierSound acceptance admitted run
    (caller.gpr 4-(16#64)) rfl proofPC active
  · simpa +decide [bodyEntry,afterFrame,afterBP] using argument
  · exact memory
  · exact nativeStack

/-- ABI preservation follows from the actual physical payload execution,
including fault prefixes. Its registers/configuration are not reset or
assumed equal to the caller at the final state. -/
theorem physical_body_abi_frame (base : Word) (caller last : X86.State) (events : List Event)
    (run : Execution (TrustedSimpleB29Embedding.payloadInstructionStep base image)
      (bodyEntry base caller) events last) :
    simpleABIFrame last=simpleABIFrame (bodyEntry base caller) := by
  let logical : X86.State := {bodyEntry base caller with pc:=0}
  have valid : simpleClosedPC logical.pc := by simp [logical,simpleClosedPC,simpleNativeOffsets]
  have starts : shiftNativeState (base+(14#64)) logical=bodyEntry base caller := by
    simp +decide [logical,shiftNativeState,bodyEntry]
  obtain ⟨logicalLast,logicalRun,lastEq⟩ :=
    TrustedSimpleB29Embedding.physical_payload_execution_reflects base run logical valid starts
  have frame := captured_native_prefix_abi_frame logicalRun valid
  rw [← lastEq]
  exact frame

theorem physical_body_stack_frame (base : Word) (caller last : X86.State) (events : List Event)
    (run : Execution (TrustedSimpleB29Embedding.payloadInstructionStep base image)
      (bodyEntry base caller) events last) :
    last.gpr 4=caller.gpr 4-(16#64) ∧ last.gpr 5=caller.gpr 4-(8#64) ∧
      last.gpr 15=caller.gpr 15 := by
  have frame := physical_body_abi_frame base caller last events run
  have sp := congrArg (fun saved => saved.2.1) frame
  have bp := congrArg (fun saved => saved.2.2.1) frame
  have r15 := congrArg (fun saved => saved.2.2.2.2.2.2.1) frame
  exact ⟨sp,bp,r15⟩

/-- The actual body establishes SP/BP for the real current epilogue. The
remaining saved-word/outer-return reads and canonical ABI stack premise are
explicit physical-layout obligations, not simulator checks or assumptions
about which payload branch or data writes occurred. -/
theorem actual_body_to_caller_return (base : Word) (caller s : X86.State) (events : List Event)
    (body : Execution (TrustedSimpleB29Embedding.payloadInstructionStep base image)
      (bodyEntry base caller) events s)
    (position : s.pc=base+(74#64)) (canonicalFrame : X86.leave64FrameCanonical s=true)
    (target : Word) (event15 eventBP outerEvent : Event)
    (read15 : readMemory s.memory (caller.gpr 4-(16#64)) 8=.ok (caller.gpr 15,event15))
    (readBP : readMemory s.memory (caller.gpr 4-(8#64)) 8=.ok (caller.gpr 5,eventBP))
    (outerRead : readMemory s.memory (caller.gpr 4) 8=.ok (target,outerEvent))
    (canonical : X86.canonicalTarget s.addressWidth target=true) :
    ∃ middle, X86Path.Execution base image s [event15,eventBP] middle ∧
      X86Path.Execution (returnTarget base) returnThunk middle [outerEvent]
        (afterOuterReturn {s with
          gpr:=fun r => if r=4 then caller.gpr 4 else if r=5 then caller.gpr 5
            else if r=15 then caller.gpr 15 else s.gpr r
          pc:=returnTarget base} target) := by
  obtain ⟨stack,frame,_⟩ := physical_body_stack_frame base caller s events body
  exact actual_epilogue_and_return base caller s target event15 eventBP outerEvent
    position canonicalFrame stack frame read15 readBP outerRead canonical

end KProgTV.TrustedSimpleB29Wrapper

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_entry_path

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_return_edge

#print axioms KProgTV.TrustedSimpleB29Wrapper.captured_return_symbol

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_pop_step

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_leave_step

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_leave_fault

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_pop_fault

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_epilogue_path

#print axioms KProgTV.TrustedSimpleB29Wrapper.epilogue_restores_caller_frame

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_epilogue_pop_fault_path

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_epilogue_leave_fault_path

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_return_thunk_success

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_return_thunk_read_fault

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_return_thunk_target_fault

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_epilogue_and_return

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_leave_address_fault

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_epilogue_address_fault_path

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_entry_and_checked_body

#print axioms KProgTV.TrustedSimpleB29Wrapper.physical_body_abi_frame

#print axioms KProgTV.TrustedSimpleB29Wrapper.physical_body_stack_frame

#print axioms KProgTV.TrustedSimpleB29Wrapper.actual_body_to_caller_return
