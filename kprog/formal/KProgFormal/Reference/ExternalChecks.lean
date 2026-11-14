import KProgFormal.Reference.Provenance

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

-- All control families use the foreign checked executor, preserving every
-- original native field and arbitrary memory bytes even on faults.
example : ([0,0x202,0xdeadbeefcafebabe,0xffffffffffffffff] : List Word).all (fun flags =>
    [X86.AddressWidth.w48,.w57].all (fun width =>
      let s := { input with rflags := flags, addressWidth := width }
      let t := X86.step (.ud2 0x4002) s
      same t.state s && t.fault == some .invalidOpcode && t.events == [.fault .invalidOpcode] &&
      t.state.memory.value 0x12ff == 0xff && !t.state.memory.initialized 0x12ff)) = true := by decide

example : let s := { input with modelError := some (.unimplemented "prior model refusal") }
    let t := X86.step (.ud2 0x4002) s
    (match t.state.modelError with | some (.unimplemented text) => text == "prior model refusal" | _ => false) &&
    same { t.state with modelError := none } input && t.fault.isNone && t.events.isEmpty := by decide

example : ([0,8,65535] : List (BitVec 16)).all (fun release => [false,true].all (fun bad =>
    let target : Word := if bad then 0x800000000000 else 0x5000
    let s := { input with memory := { input.memory with value := fun a =>
      if (a-0x3000).toNat < 8 then (target >>> (8*(a-0x3000).toNat)).setWidth 8 else input.memory.value a } }
    let t := X86.step (.returnNear release 0x4003) s
    let read : Event := .memory .read 0x3000 (valueBytes target 8) false
    if bad then same t.state s && t.fault == some (.nonCanonical target) && t.events == [read,.fault (.nonCanonical target)]
    else same t.state { s with gpr := fun r => if r == 4 then 0x3008+release.setWidth 64 else s.gpr r, pc := 0x5000 } &&
      t.fault.isNone && t.events == [read] && t.state.memory.value 0x12ff == 0xff)) = true := by decide

example : ([(0x1000,true,true),(0x800000000000,false,true),(0xffffffffffffffff,true,true)] :
    List (Word × Bool × Bool)).all (fun (base,lo,hi) =>
      [(X86.AddressWidth.w48,lo),(.w57,hi)].all (fun (width,valid) => [false,true].all (fun deny =>
        let s := { input with
          gpr := fun r => if r == 5 then base else input.gpr r
          addressWidth := width
          memory := { input.memory with
            readable := fun _ => !deny
            value := fun a => if (a-base).toNat < 8 then (a-base).setWidth 8 else input.memory.value a } }
        let t := X86.step (.leave64 0x4001) s
        let fault := if !valid then some (Fault.nonCanonical base) else if deny then some (.read base 8) else none
        let expected := if fault.isSome then s else
          { s with gpr := fun r => if r == 4 then base+8 else if r == 5 then 0x0706050403020100 else s.gpr r, pc := 0x4001 }
        same t.state expected && t.fault == fault && t.events == (match fault with
          | some f => [.fault f]
          | none => [.memory .read base [0,1,2,3,4,5,6,7] false]) &&
        t.state.memory.value (base-1) == s.memory.value (base-1)))) = true := by decide


-- Provenance regression: all256 tag bytes, distinct origins, wrapping64-bit
-- values and RSP's unconditional offset rule. RETURN10 is not an x86 rebase.
private def tagProjections (start : Nat) : Bool :=
  (List.range 32).all (fun offset =>
    let n := start + offset
    let tag := BitVec.ofNat 8 n
    let raw : Word := 0xfffffffffffffffe
    let arm := Provenance.AArch64.materialize { stack := 7, returnAddress := 19 } raw tag
    let x86 := Provenance.X86.materialize { stack := 7, arena := 13 } 0 raw tag
    let rsp := Provenance.X86.materialize { stack := 7, arena := 13 } 4 raw tag
    arm == (if n == 4 then 5 else if n == 10 then 17 else raw) &&
    x86 == (if n == 4 then 0xfffffffffffffff8 else raw) && rsp == 5)

example : tagProjections 0 = true := by decide
example : tagProjections 32 = true := by decide
example : tagProjections 64 = true := by decide
example : tagProjections 96 = true := by decide
example : tagProjections 128 = true := by decide
example : tagProjections 160 = true := by decide
example : tagProjections 192 = true := by decide
example : tagProjections 224 = true := by decide

-- All16 cells participate. A materialized source becomes the real MOV input;
-- RSP's displacement and non-RSP arena pointers use different coordinates.
example : ([0,4,10,255] : List Byte).all (fun tag =>
    let state : Provenance.X86.State := { raw := input, tags := fun _ => tag }
    let origins : Provenance.X86.Origins := { stack := 0x7000, arena := 0x1000 }
    let image := Provenance.X86.image origins state
    let output := Provenance.X86.execute origins
      (.move .w64 (.register (.low 0)) (.register (.low 4)) 0x4003) state
    (List.finRange 16).all (fun r => image.gpr r ==
      (if r == 4 then input.gpr r + 0x7000 else
       if tag == 4 then input.gpr r - 0x1000 + 0x7000 else input.gpr r)) &&
    output.state.gpr 0 == 0xa000 && output.state.gpr 4 == 0xa000 &&
    (List.finRange 16).all (fun r => r == 0 || output.state.gpr r == image.gpr r) &&
    output.state.rflags == input.rflags && output.state.xmm0 == input.xmm0 &&
    output.state.memory.value 0x12ff == 0xff && output.state.fsBase == input.fsBase &&
    output.state.gsBase == input.gsBase && output.fault.isNone && output.events.isEmpty &&
    output.state.pc == 0x4003) = true := by decide

-- An offset/tag never supplies permission. Denied reads use the native image
-- address, retaining the full register frame and the exact typed fault prefix.
example : let raw := { input with memory := { input.memory with readable := fun _ => false } }
    let state : Provenance.X86.State := { raw, tags := fun _ => 4 }
    let out := Provenance.X86.execute { stack := 0x7000, arena := 0x1000 }
      (.move .w64 (.register (.low 1)) (.memory 0x8000) 0x4003) state
    let expected := Provenance.X86.observe { stack := 0x7000, arena := 0x1000 }
      { state, events := [.fault (.read 0x8000 8)], fault := some (.read 0x8000 8) }
    out.fault == expected.fault && out.events == expected.events &&
    same out.state expected.state := by decide

private def armProvenanceRaw : AArch64.State :=
  let machine := (List.finRange 32).foldl (fun machine r =>
    w (.GPR (BitVec.ofNat 5 r.val)) (0x100+BitVec.ofNat 64 r.val) machine) ArmState.default
  let machine := (List.finRange 32).foldl (fun machine r =>
    w (.SFP (BitVec.ofNat 5 r.val)) (0x123456789abcdef00000000000000000+BitVec.ofNat 128 r.val) machine) machine
  { machine := { set_program (write_pc 0x4000 machine) [(0x4000,0xd503201f)] with
      mem := fun a => a.setWidth 8
      memoryProfile := some {
        readable := fun a => a != 0x12ff
        writable := fun a => a != 0x1300
        initialized := fun a => a == 0x12fe
        pairSingleAccess := true
        lse2UnalignedWithin16 := true }
      memoryAccesses := [.memory .read 0x77 [0x88] false]
      exclusive := {
        monitor := some { physicalStart := 0x5670, bytes := 16 }
        accesses := [{
          action := .reserve
          address := 0x5678
          bytes := 8
          value := 9
          acquire := true
          release := false
          success := true }] }
      threadPointerInputs := some { el1 := some 0x1234, el2 := none } }
    extraFlags := 0xdeadbeef01234567 }

-- LNSym marks r/w/fetch_inst irreducible for symbolic simulation. The kernel
-- evaluator unfolds them for these literal full-machine checks, without an
-- unsafe reducibility override or a native-computation axiom.
section NativeArmProvenanceChecks

-- Full31GPR+SP and32SIMD projection; NOP must preserve all other machine
-- histories/profiles and not re-emit an old access as a fresh event.
example : ([0,4,10,255] : List Byte).all (fun tag =>
    let state : Provenance.AArch64.State := { raw := armProvenanceRaw, tags := fun _ => tag }
    let origins : Provenance.AArch64.Origins := { stack := 0x7000, returnAddress := 0x9000 }
    let output := Provenance.AArch64.execute origins state
    let s := output.state
    (List.finRange 31).all (fun r => AArch64.gpr s r ==
      0x100+BitVec.ofNat 64 r.val+(if tag == 4 then 0x7000 else if tag == 10 then 0x9000 else 0)) &&
    AArch64.sp s == 0x711f && AArch64.pc s == 0x4004 &&
    (List.finRange 32).all (fun r => AArch64.readVector s r ==
      0x123456789abcdef00000000000000000+BitVec.ofNat 128 r.val) &&
    s.extraFlags == armProvenanceRaw.extraFlags &&
    s.machine.exclusive == armProvenanceRaw.machine.exclusive &&
    s.machine.threadPointerInputs == armProvenanceRaw.machine.threadPointerInputs &&
    s.machine.program == armProvenanceRaw.machine.program &&
    s.machine.memoryAccesses == armProvenanceRaw.machine.memoryAccesses &&
    s.machine.atomicAccesses == armProvenanceRaw.machine.atomicAccesses &&
    s.machine.mem 0x12ff == 0xff &&
    (match s.machine.memoryProfile with
      | none => false
      | some p => !p.readable 0x12ff && !p.writable 0x1300 && p.initialized 0x12fe &&
        !p.initialized 0x12ff && p.pairSingleAccess && p.lse2UnalignedWithin16) &&
    (AArch64.modelError output).isNone && output.events.isEmpty && output.fault.isNone) = true := by
  decide +kernel

-- ADD reads the materialized X1. Other GPRs/SP/flags keep their full image.
example : ([0,4,10,255] : List Byte).all (fun tag =>
    let raw := { armProvenanceRaw with machine := set_program armProvenanceRaw.machine [(0x4000,0x91000420)] }
    let state : Provenance.AArch64.State := { raw, tags := fun _ => tag }
    let origins : Provenance.AArch64.Origins := { stack := 0x7000, returnAddress := 0x9000 }
    let before := Provenance.AArch64.image origins state
    let output := Provenance.AArch64.execute origins state
    AArch64.gpr output.state 0 == (if tag == 4 then 0x7102 else if tag == 10 then 0x9102 else 0x102) &&
    (List.finRange 31).all (fun r => r == 0 || AArch64.gpr output.state r == AArch64.gpr before r) &&
    AArch64.sp output.state == 0x711f && AArch64.flags output.state == AArch64.flags before &&
    AArch64.pc output.state == 0x4004 && output.events.isEmpty && output.fault.isNone &&
    (AArch64.modelError output).isNone) = true := by decide +kernel

-- LDR permission failure is checked at the native address after tag erasure.
-- The actual C-shaped unchanged raw frame projects with the exact fault trace.
example : ([0,4,10,255] : List Byte).all (fun tag =>
    let raw := { armProvenanceRaw with machine := {
      set_program armProvenanceRaw.machine [(0x4000,0xf9400020)] with
        memoryProfile := some { readable := fun _ => false } } }
    let state : Provenance.AArch64.State := { raw, tags := fun _ => tag }
    let origins : Provenance.AArch64.Origins := { stack := 0x7000, returnAddress := 0x9000 }
    let reason : Fault := .read (if tag == 4 then 0x7101 else if tag == 10 then 0x9101 else 0x101) 8
    let expected := Provenance.AArch64.observe origins
      { state, events := [.fault reason], fault := some reason }
    let output := Provenance.AArch64.execute origins state
    output.events == expected.events && output.fault == expected.fault &&
    (List.finRange 31).all (fun r => AArch64.gpr output.state r == AArch64.gpr expected.state r) &&
    (List.finRange 32).all (fun r => AArch64.readVector output.state r == AArch64.readVector expected.state r) &&
    AArch64.sp output.state == AArch64.sp expected.state &&
    AArch64.pc output.state == 0x4000 && output.state.machine.mem 0x12ff == 0xff &&
    output.state.machine.exclusive == raw.machine.exclusive &&
    output.state.machine.memoryAccesses == raw.machine.memoryAccesses ++
      [.fault (.read (if tag == 4 then 0x7101 else if tag == 10 then 0x9101 else 0x101) 8)] &&
    (AArch64.modelError output).isNone) = true := by decide +kernel

end NativeArmProvenanceChecks

end KProgFormal.Reference.ExternalChecks
