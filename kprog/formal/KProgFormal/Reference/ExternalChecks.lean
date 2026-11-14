import KProgFormal.Reference.X86

/-! Functional native memory must survive the finite external representation.
Literal observations catch zero-filled materialization, lost frame bytes,
wrong register views, dropped read prefixes and stale data-dependent targets. -/
namespace KProgFormal.Reference.ExternalChecks
open KProgFormal.Reference

private def input : X86.State :=
  { gpr := fun r => if r == 0 then 0x1122334455667788 else if r == 4 then 0x3000 else 0x1000+BitVec.ofNat 64 r.val
    rflags := 0xdeadbeefcafebabe
    xmm0 := 0x112233445566778899aabbccddeeff00
    memory := {
      value := fun a => (a-0x1000).setWidth 8
      readable := fun _ => true
      writable := fun _ => true
      initialized := fun _ => false }
    pc := 0x4000
    fsBase := 0x5000
    gsBase := 0x6000 }

private def same (a b : X86.State) : Bool :=
  (List.finRange 16).all (fun r => a.gpr r == b.gpr r) &&
  a.rflags == b.rflags && a.xmm0 == b.xmm0 && a.pc == b.pc &&
  a.fsBase == b.fsBase && a.gsBase == b.gsBase &&
  a.addressWidth == b.addressWidth && a.oracle.cursor == b.oracle.cursor &&
  a.modelError.isNone && b.modelError.isNone

-- Encoded fall-through wraps at64 bits; unrelated RFLAGS/XMM/GPRs survive.
example : ([0x4001,0,0xffffffffffffffff] : List Word).all (fun next =>
    let t := X86.step (.nop next) input
    same t.state { input with pc := next } && t.events.isEmpty && t.fault.isNone &&
    t.state.memory.value 0x12ff == 0xff) = true := by decide

-- Low/high byte, word, zero-extending dword and fullword register writes.
example : ([X86.ScalarWidth.w8,.w16,.w32,.w64].zip
    [0x11223344556677aa,0x112233445566aaaa,0xaaaaaaaa,0xaaaaaaaaaaaaaaaa]).all (fun (width,want) =>
      let t := X86.step (.move width (.register (.low 0)) (.immediate 0xaaaaaaaaaaaaaaaa) 0x4003) input
      t.state.gpr 0 == want && t.state.rflags == input.rflags && t.events.isEmpty &&
      t.fault.isNone && t.state.modelError.isNone) = true := by decide
example : let t := X86.step (.move .w8 (.register (.high 0)) (.immediate 0xaa) 0x4003) input
    t.state.gpr 0 == 0x112233445566aa88 && t.state.gpr 1 == input.gpr 1 &&
    t.state.rflags == input.rflags && t.fault.isNone && t.state.modelError.isNone := by decide

example : ([X86.ScalarWidth.w8,.w16,.w32,.w64].zip
    [0x1122334455667700,0x1122334455660100,0x03020100,0x0706050403020100]).all (fun (width,want) =>
      let t := X86.step (.move width (.register (.low 0)) (.memory 0x1000) 0x4003) input
      t.state.gpr 0 == want && t.state.rflags == input.rflags && t.fault.isNone &&
      t.state.modelError.isNone && t.events == [.memory .read 0x1000 (bytesAt input.memory 0x1000 width.bytes) false] &&
      t.state.memory.value 0x10ff == 0xff && !t.state.memory.initialized 0x1000) = true := by decide

example : let t := X86.step (.move .w64 (.memory 0x2000) (.register (.low 0)) 0x4003) input
    same t.state { input with pc := 0x4003 } && t.fault.isNone &&
    t.events == [.memory .write 0x2000 [0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11] true] &&
    wordAt t.state.memory 0x2000 8 == 0x1122334455667788 &&
    (List.range 8).all (fun n => t.state.memory.initialized (0x2000+BitVec.ofNat 64 n)) &&
    t.state.memory.value 0x1fff == 0xff && t.state.memory.value 0x2008 == 8 &&
    !t.state.memory.initialized 0x1fff && !t.state.memory.initialized 0x2008 := by decide

example : ([0x1000,0x1007] : List Word).all (fun bad =>
    let s := { input with memory := { input.memory with readable := fun a => a != bad } }
    let t := X86.step (.move .w64 (.register (.low 0)) (.memory 0x1000) 0x4003) s
    same t.state s && t.fault == some (.read 0x1000 8) &&
    t.events == [.fault (.read 0x1000 8)] && t.state.memory.value bad == s.memory.value bad) = true := by decide
example : ([0x2000,0x2007] : List Word).all (fun bad =>
    let s := { input with memory := { input.memory with writable := fun a => a != bad } }
    let t := X86.step (.move .w64 (.memory 0x2000) (.register (.low 0)) 0x4003) s
    same t.state s && t.fault == some (.write 0x2000 8) &&
    t.events == [.fault (.write 0x2000 8)] && t.state.memory.value bad == s.memory.value bad &&
    !t.state.memory.initialized bad) = true := by decide

-- Original fork RMW numeric result, with independent value/fault/frame goldens.
example : ([(_root_.X86.Size.b,1,0),(.w,2,0x0100),(.d,4,0x03020100),(.q,8,0x0706050403020100)] :
    List (_root_.X86.Size × Nat × Word)).all (fun (size,n,old) =>
      [false,true].all (fun deny =>
        let s := { input with memory := { input.memory with writable := fun _ => !deny } }
        let t := X86.nativeStep (.bin .add size (.mem { disp := 0x1000 }) (.imm 1)) 0x4003 s
        let read : Event := .memory .read 0x1000 (bytesAt input.memory 0x1000 n) false
        t.state.modelError.isNone &&
        if deny then same t.state s && t.fault == some (.write 0x1000 n) &&
          t.events == [read,.fault (.write 0x1000 n)] && wordAt t.state.memory 0x1000 n == old
        else t.fault.isNone && t.state.pc == 0x4003 && wordAt t.state.memory 0x1000 n == old+1 &&
          t.events == [read,.memory .write 0x1000 (valueBytes (old+1) n) true] &&
          t.state.memory.value 0x12ff == 0xff && !t.state.memory.initialized 0x12ff)) = true := by decide

-- The read plan sees an empty cache initially; RET must resolve its target
-- again after arbitrary functional stack bytes have been materialized.
example : [false,true].all (fun badTarget =>
    let target : Word := if badTarget then 0x800000000000 else 0x5000
    let s := { input with memory := { input.memory with
      value := fun a => if (a-0x3000).toNat < 8 then
        (target >>> (8*(a-0x3000).toNat)).setWidth 8 else input.memory.value a } }
    let t := X86.nativeStep .ret 0x4001 s
    let read : Event := .memory .read 0x3000 (valueBytes target 8) false
    if badTarget then same t.state s && t.fault == some (.nonCanonical target) &&
      t.events == [read,.fault (.nonCanonical target)]
    else t.state.pc == 0x5000 && t.state.gpr 4 == 0x3008 && t.fault.isNone &&
      t.state.modelError.isNone && t.events == [read] &&
      t.state.memory.value 0x12ff == 0xff && !t.state.memory.initialized 0x3000) = true := by decide

-- Canonical decoded families use the external step, including flag transport.
example : ([(0x7fffffffffffffff, X86.ArithmeticKind.add, 1, 2, 0x8000000000000000, 0x896),
    (0, .sub, 1, 2, 0xffffffffffffffff, 0x97),
    (0xffffffffffffffff, .adc, 0, 3, 0, 0x57)] :
    List (Word × X86.ArithmeticKind × Word × Word × Word × Word)).all
    (fun (left,kind,right,flags,value,wantFlags) =>
      let s := { input with gpr := fun r => if r == 0 then left else input.gpr r, rflags := flags }
      let t := X86.step (.arithmetic .w64 kind (.register (.low 0)) (.immediate right) 0x4003) s
      t.state.gpr 0 == value && t.state.rflags == wantFlags && t.state.pc == 0x4003 &&
      t.state.modelError.isNone && t.fault.isNone && t.events.isEmpty) = true := by decide
example : let t := X86.step (.logic .w64 .or (.register (.low 0)) (.immediate 0) 0x4003) ({ input with gpr := fun _ => 0x8000000000000000, rflags := 2 })
    t.state.gpr 0 == 0x8000000000000000 && t.state.rflags &&& 0x8c5 == 0x84 &&
    t.state.modelError.isNone && t.fault.isNone := by decide
example : let t := X86.step (.unary .w64 .not (.register (.low 0)) 0x4003) input
    t.state.gpr 0 == 0xeeddccbbaa998877 && t.state.rflags == input.rflags &&
    t.state.modelError.isNone && t.fault.isNone := by decide
example : let t := X86.step (.lea .w32 0 0xabcdef0012345678 0x4003) input
    t.state.gpr 0 == 0x12345678 && t.state.rflags == input.rflags &&
    t.state.modelError.isNone && t.fault.isNone && t.events.isEmpty := by decide
example : let t := X86.step (.byteSwap .w64 0 0x4003) input
    t.state.gpr 0 == 0x8877665544332211 && t.state.rflags == input.rflags &&
    t.state.modelError.isNone && t.fault.isNone && t.events.isEmpty := by decide
example : let t := X86.step (.movbeLoad .w32 0 0x1000 0x4003) input
    t.state.gpr 0 == 0x00010203 && t.state.rflags == input.rflags &&
    t.state.modelError.isNone && t.fault.isNone &&
    t.events == [.memory .read 0x1000 [0,1,2,3] false] := by decide

-- Unified fork RMWs retain both values in the existing atomic native view.
example : [false,true].all (fun deny =>
    let s := { input with
      gpr := fun r => if r == 0 then 0x1000 else input.gpr r
      memory := { input.memory with writable := fun _ => !deny } }
    let t := X86.nativeStep (.xchg .q (.reg .rax) (.mem { base := some .rax })) 0x4003 s
    let old : List Byte := [0,1,2,3,4,5,6,7]
    t.state.modelError.isNone &&
    if deny then same t.state s && t.fault == some (.write 0x1000 8) &&
      t.events == [.memory .read 0x1000 old false,.fault (.write 0x1000 8)]
    else t.fault.isNone && t.state.gpr 0 == 0x0706050403020100 &&
      wordAt t.state.memory 0x1000 8 == 0x1000 &&
      t.events == [.memory .atomic 0x1000 old false,.memory .write 0x1000 [0,0x10,0,0,0,0,0,0] true] &&
      t.state.memory.value 0x0706050403020101 == 1) = true := by decide

-- Invalid post-decode ASTs are model refusals, with no fabricated fault or
-- fallback execution of the former total local interpreter.
example : let t := X86.nativeStep (.mov .q (.mem { disp := 0x1000 }) (.mem { disp := 0x2000 })) 0x4003 input
    t.state.modelError.isSome && t.fault.isNone && t.events.isEmpty &&
    t.state.pc == input.pc && t.state.gpr 0 == input.gpr 0 &&
    t.state.memory.value 0x12ff == 0xff := by decide

end KProgFormal.Reference.ExternalChecks
