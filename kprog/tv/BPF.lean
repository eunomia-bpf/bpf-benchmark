import KProgFormal.Reference.Memory

/- Byte semantics of little-endian eBPF, using the kernel's versioned primary
   specification: Documentation/bpf/standardization/instruction-set.rst.
   Native ISA semantics are imported only from lane V's reference. -/
namespace KProgTV.BPF
open KProgFormal.Reference

abbrev Register := Fin 11

structure Instruction where
  code : Nat
  dst : Register
  src : Nat
  offset : BitVec 16
  imm : BitVec 32
  deriving Repr, DecidableEq

def decode (bytes : Array Byte) (pc : Nat) : Except String Instruction := do
  let position := 8 * pc
  if position + 8 > bytes.size then throw "BPF instruction outside artifact"
  let get := fun i => bytes[position + i]!
  let dst := (get 1).toNat % 16
  if h : dst < 11 then
    pure ⟨(get 0).toNat, ⟨dst, h⟩, (get 1).toNat / 16,
      littleEndian 16 [get 2, get 3], littleEndian 32 [get 4, get 5, get 6, get 7]⟩
  else throw "BPF destination register outside r0-r10"

structure State where
  regs : Register → Word
  memory : Memory
  pc : Int
  halted : Bool := false
  /-- Ghost index for fresh environment choices, including loop retries. -/
  exclusiveVisit : Nat := 0

/-- Helper results and memory effects are supplied by the matched platform
contract, never replaced with zero. Registers r1-r5 become arbitrary after a
call; certificates quantify over the supplied clobbers. -/
structure HelperResult where
  result : Word
  memory : Memory
  events : List Event
  clobbers : Fin 5 → Word

structure HelperCall where
  identity : Word
  argumentCount : Fin 6

def helperArguments (call : HelperCall) (s : State) : List Word :=
  (List.finRange call.argumentCount.val).map fun r =>
    s.regs ⟨r.val + 1, by have := r.isLt; have := call.argumentCount.isLt; omega⟩

/-- Values from the same native invocation, after its host JIT prologue.
    A program certificate must prove the source/body ABI relation separately. -/
inductive NativeInput where
  | stackPointer | codeBase | returnAddress
  deriving Repr, DecidableEq

structure Environment where
  nativeInput : NativeInput → Except String Word := fun _ => .error "unbound native proof input"
  exclusiveFailure : BitVec 32 → Nat → Except String Bool :=
    fun _ _ => .error "unbound exclusive environment choice"
  immediate : Instruction → BitVec 32 → State → Except String Word
  helperCall : Instruction → State → Except String HelperCall
  helper : HelperCall → List Word → Memory → Except String HelperResult

def setReg (s : State) (r : Register) (value : Word) : State :=
  { s with regs := fun index => if index = r then value else s.regs index }

def source (i : Instruction) (s : State) : Except String Word :=
  if i.code / 8 % 2 = 0 then .ok (i.imm.signExtend 64)
  else if h : i.src < 11 then .ok (s.regs ⟨i.src, h⟩)
  else .error "BPF source register outside r0-r10"

def alu (width : Nat) (operation : Nat) (offset : BitVec 16)
    (dst src : BitVec width) : Except String (BitVec width) := do
  let shift := src.toNat % width
  match operation with
  | 0 => pure (dst + src)
  | 1 => pure (dst - src)
  | 2 => pure (dst * src)
  | 3 =>
      if offset = 0 then pure (if src = 0 then 0 else dst / src)
      else if offset = 1 then pure (if src = 0 then 0 else dst.sdiv src)
      else throw "invalid BPF division offset"
  | 4 => pure (dst ||| src)
  | 5 => pure (dst &&& src)
  | 6 => pure (dst <<< shift)
  | 7 => pure (dst >>> shift)
  | 8 => pure (-dst)
  | 9 =>
      if offset = 0 then pure (if src = 0 then dst else dst % src)
      else if offset = 1 then pure (if src = 0 then dst else dst.srem src)
      else throw "invalid BPF modulo offset"
  | 10 => pure (dst ^^^ src)
  | 11 =>
      if offset = 0 then pure src
      else if offset = 8 then pure ((src.setWidth 8).signExtend width)
      else if offset = 16 then pure ((src.setWidth 16).signExtend width)
      else if offset = 32 ∧ width = 64 then pure ((src.setWidth 32).signExtend width)
      else throw "invalid BPF MOVSX offset"
  | 12 => pure (dst.sshiftRight shift)
  | _ => throw "invalid BPF arithmetic operation"

def comparison (width : Nat) (operation : Nat) (a b : BitVec width) : Except String Bool :=
  match operation with
  | 1 => .ok (a == b)
  | 2 => .ok (a > b)
  | 3 => .ok (a ≥ b)
  | 4 => .ok ((a &&& b) != 0)
  | 5 => .ok (a != b)
  | 6 => .ok (a.toInt > b.toInt)
  | 7 => .ok (a.toInt ≥ b.toInt)
  | 10 => .ok (a < b)
  | 11 => .ok (a ≤ b)
  | 12 => .ok (a.toInt < b.toInt)
  | 13 => .ok (a.toInt ≤ b.toInt)
  | _ => .error "invalid BPF comparison"

def writeBytes (m : Memory) (address : Word) (bytes : List Byte) : Memory :=
  match bytes with
  | [] => m
  | byte :: rest =>
      writeBytes { m with
          value := fun a => if a = address then byte else m.value a
          initialized := fun a => if a = address then true else m.initialized a }
        (address + 1) rest

def valueBytes (value : Word) (count : Nat) : List Byte :=
  (List.range count).map (fun n => value.extractLsb' (8 * n) 8)

@[simp] theorem valueBytes_length (value : Word) (count : Nat) :
    (valueBytes value count).length = count := by simp [valueBytes]

def store (s : State) (address value : Word) (count : Nat) : Transition State :=
  match writeMemory s.memory address value count with
  | .ok (memory, event) => ⟨{ s with memory }, [event], none⟩
  | .error fault => ⟨s, [.fault fault], some fault⟩

def load (s : State) (dst : Register) (address : Word) (count : Nat)
    (signed : Bool) : Transition State :=
  match readMemory s.memory address count with
  | .error reason => ⟨s, [.fault reason], some reason⟩
  | .ok (value, event) =>
      let result := if signed then (value.setWidth (8 * count)).signExtend 64 else value
      ⟨setReg s dst result, [event], none⟩

def atomicValue (width : Nat) (operation : Nat) (old src expected : BitVec width) :
    Except String (BitVec width × Bool) :=
  match operation with
  | 0 | 1 => .ok (old + src, true)
  | 0x40 | 0x41 => .ok (old ||| src, true)
  | 0x50 | 0x51 => .ok (old &&& src, true)
  | 0xa0 | 0xa1 => .ok (old ^^^ src, true)
  | 0xe1 => .ok (src, true)
  | 0xf1 => .ok (src, old == expected)
  | _ => .error "invalid BPF atomic read-modify-write operation"

/-- One indivisible read-modify-write event records its pre-access bytes.
The full post-state records the replacement bytes. A failed compare exchanges
no memory and cannot initialize previously unwritten bytes. -/
def atomic (s : State) (dst src : Register) (offset : BitVec 16)
    (count operation : Nat) : Except String (Transition State) := do
  if count ≠ 4 ∧ count ≠ 8 then throw "invalid BPF atomic read-modify-write width"
  let address := s.regs dst + offset.signExtend 64
  let old := wordAt s.memory address count
  let (value, written) ← if count = 4 then
      (atomicValue 32 operation (old.setWidth 32) ((s.regs src).setWidth 32)
        ((s.regs 0).setWidth 32)).map fun (value, written) => (value.setWidth 64, written)
    else atomicValue 64 operation old (s.regs src) (s.regs 0)
  if operation % 2 = 1 ∧ operation ≠ 0xf1 ∧ src = 10 then
    throw "BPF atomic fetch overwrites frame pointer"
  if !permitted s.memory.readable address count then
    return ⟨s, [.fault (.read address count)], some (.read address count)⟩
  if !permitted s.memory.writable address count then
    return ⟨s, [.fault (.write address count)], some (.write address count)⟩
  let memory := if written then writeBytes s.memory address (valueBytes value count) else s.memory
  let next := { s with memory }
  let next := if operation = 0xf1 then setReg next 0 old
    else if operation % 2 = 1 then setReg next src old else next
  pure ⟨next, [.memory .atomic address (bytesAt s.memory address count)
    (initializedAt s.memory address count)], none⟩

def execute (env : Environment) (program : Array Byte) (s : State) (i : Instruction) :
    Except String (Transition State) := do
  let cls := i.code % 8
  let operation := i.code / 16
  let next := { s with pc := s.pc + 1 }
  if i.code = 0xb7 ∧ i.src = 9 then
    if i.dst ≠ 0 then throw "invalid native proof input ABI/kind/register"
    if i.offset = 5 then
      let failure ← env.exclusiveFailure i.imm s.exclusiveVisit
      return ⟨setReg { next with exclusiveVisit := s.exclusiveVisit + 1 } 0
        (if failure then 1 else 0), [], none⟩
    if i.imm ≠ 2 then throw "invalid native proof input ABI/kind/register"
    let value ← match i.offset.toNat with
      | 1 => env.nativeInput .stackPointer
      | 2 => env.nativeInput .codeBase
      | 3 => env.nativeInput .returnAddress
      | 4 => pure (s.regs 1)
      | _ => throw "invalid native proof input ABI/kind/register"
    pure ⟨setReg next 0 value, [], none⟩
  else if cls = 4 ∨ cls = 7 then
    if i.dst = 10 then throw "BPF arithmetic overwrites frame pointer"
    if operation = 13 then
      let count := i.imm.toNat / 8
      if i.imm.toNat ∉ [16, 32, 64] then throw "invalid BPF byte-swap width"
      let bytes := valueBytes (s.regs i.dst) count
      let value := littleEndian 64 (if cls = 7 ∨ i.code / 8 % 2 = 1 then bytes.reverse else bytes)
      pure ⟨setReg next i.dst value, [], none⟩
    else
      let rhs ← source i s
      let result ← if cls = 4 then
          (alu 32 operation i.offset ((s.regs i.dst).setWidth 32) (rhs.setWidth 32)).map (·.setWidth 64)
        else alu 64 operation i.offset (s.regs i.dst) rhs
      pure ⟨setReg next i.dst result, [], none⟩
  else if cls = 5 ∨ cls = 6 then
    if operation = 0 then
      let displacement := if cls = 6 then i.imm.toInt else i.offset.toInt
      pure ⟨{ next with pc := next.pc + displacement }, [], none⟩
    else if operation = 9 ∧ cls = 5 then
      pure ⟨{ next with halted := true }, [], none⟩
    else if operation = 8 ∧ cls = 5 then
      if i.src ≠ 0 ∧ i.src ≠ 2 then throw "BPF local call needs a call-frame rule"
      let call ← env.helperCall i s
      let arguments := helperArguments call s
      let effect ← env.helper call arguments s.memory
      let regs := fun r : Register =>
        if r.val = 0 then effect.result
        else if h : r.val - 1 < 5 then effect.clobbers ⟨r.val - 1, h⟩ else s.regs r
      pure ⟨{ next with regs, memory := effect.memory },
        effect.events ++ [.helper call.identity arguments effect.result], none⟩
    else
      let rhs ← source i s
      let taken ← if cls = 6 then comparison 32 operation ((s.regs i.dst).setWidth 32) (rhs.setWidth 32)
        else comparison 64 operation (s.regs i.dst) rhs
      pure ⟨{ next with pc := if taken then next.pc + i.offset.toInt else next.pc }, [], none⟩
  else if cls = 0 ∧ i.code = 0x18 then
    if i.dst = 10 then throw "BPF immediate overwrites frame pointer"
    let high ← decode program (s.pc.toNat + 1)
    if high.code ≠ 0 ∨ high.dst.val ≠ 0 ∨ high.src ≠ 0 ∨ high.offset ≠ 0 then
      throw "malformed BPF wide-immediate continuation"
    let value ← if i.src = 0 then pure (i.imm.setWidth 64 ||| (high.imm.setWidth 64 <<< 32))
      else env.immediate i high.imm s
    pure ⟨setReg { next with pc := s.pc + 2 } i.dst value, [], none⟩
  else if cls = 1 ∨ cls = 2 ∨ cls = 3 then
    let mode := i.code / 32
    let count := match i.code / 8 % 4 with | 0 => 4 | 1 => 2 | 2 => 1 | _ => 8
    if cls = 3 ∧ mode = 6 then
      if h : i.src < 11 then
        let effect ← atomic s i.dst ⟨i.src, h⟩ i.offset count i.imm.toNat
        pure { effect with state := if effect.fault.isSome then effect.state else { effect.state with pc := next.pc } }
      else throw "BPF atomic source outside r0-r10"
    else if cls = 1 ∧ (mode = 3 ∨ mode = 4) then
      if i.dst = 10 then throw "BPF load overwrites frame pointer"
      if h : i.src < 11 then
        let address := s.regs ⟨i.src, h⟩ + i.offset.signExtend 64
        let effect := load s i.dst address count (mode == 4)
        pure { effect with state := if effect.fault.isSome then effect.state else { effect.state with pc := next.pc } }
      else throw "BPF load base register outside r0-r10"
    else if (cls = 2 ∨ cls = 3) ∧ mode = 3 then
      let value ← if cls = 2 then pure (i.imm.signExtend 64)
        else if h : i.src < 11 then pure (s.regs ⟨i.src, h⟩)
        else throw "BPF store source outside r0-r10"
      let effect := store s (s.regs i.dst + i.offset.signExtend 64) value count
      pure { effect with state := if effect.fault.isSome then effect.state else { effect.state with pc := next.pc } }
    else throw "BPF memory mode needs an explicit instruction rule"
  else throw "BPF opcode needs an explicit instruction rule"


/-- Program bytes outside the current instruction affect execution only at
an LDDW continuation. This is equality of the existing byte semantics. -/
theorem execute_program_congr (env : Environment) (first second : Array Byte)
    (s : State) (i : Instruction)
    (high : decode first (s.pc.toNat + 1) = decode second (s.pc.toNat + 1)) :
    execute env first s i = execute env second s i := by
  simp only [execute, high]

/-- Non-wide instructions cannot observe any other program bytes. -/
theorem execute_program_congr_if_wide (env : Environment) (first second : Array Byte)
    (s : State) (i : Instruction)
    (high : i.code = 0x18 → decode first (s.pc.toNat + 1) = decode second (s.pc.toNat + 1)) :
    execute env first s i = execute env second s i := by
  by_cases wide : i.code = 0x18
  · exact execute_program_congr env first second s i (high wide)
  · simp only [execute, wide, and_false, ↓reduceIte]

def step (env : Environment) (program : Array Byte) (s : State) :
    Except String (Transition State) :=
  if s.halted then .error "BPF execution already returned"
  else if s.pc < 0 then .error "BPF PC before artifact"
  else match decode program s.pc.toNat with
    | .error error => .error error
    | .ok instruction => execute env program s instruction

/-- A bounded evaluator for an individual certificate, not a native execution
fuel guard. Exhaustion is an error. Block composition has no execution bound. -/
def run (env : Environment) (program : Array Byte) : Nat → State → Except String (Transition State)
  | 0, _ => .error "BPF certificate evaluation exhausted before its boundary"
  | n + 1, state =>
      match step env program state with
      | .error error => .error error
      | .ok first =>
          if first.state.halted || first.fault.isSome then .ok first
          else match run env program n first.state with
            | .error error => .error error
            | .ok rest => .ok { rest with events := first.events ++ rest.events }

end KProgTV.BPF
