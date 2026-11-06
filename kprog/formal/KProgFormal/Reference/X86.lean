import KProgFormal.Reference.Memory

/-!
The x86-64 reference semantics. Architectural rules come from Intel SDM
Volume 2, instruction Operation/Flags Affected descriptions:
https://cdrdv2-public.intel.com/874240/325462-090-sdm-vol-1-2abcd-3abcd-4.pdf
No simulator or generated-contract module is imported here.
-/
namespace KProgFormal.Reference.X86

abbrev Register := Fin 16

/-- CMOV has no 8-bit encoding. Width is architectural operand size, not the
simulator's byte-count code or its absent-width sentinel. -/
inductive CmovWidth
  | w16 | w32 | w64
  deriving DecidableEq, Repr

def CmovWidth.bytes : CmovWidth → Nat
  | .w16 => 2
  | .w32 => 4
  | .w64 => 8

/-- Long-mode stack transfers have 16- or 64-bit operands; 32-bit stack
operands cannot be encoded. REX.W does not override the operand-size prefix. -/
inductive StackWidth
  | w16 | w64
  deriving DecidableEq, Repr

def StackWidth.bytes : StackWidth → Nat | .w16 => 2 | .w64 => 8

def StackWidth.registerWidth : StackWidth → CmovWidth
  | .w16 => .w16 | .w64 => .w64

structure State where
  gpr : Register → Word
  rflags : Word
  xmm0 : BitVec 128
  memory : Memory
  pc : Word
  fsBase : Word
  gsBase : Word

/-- All sixteen architectural condition codes, including parity. -/
def condition (flags : Word) (code : Fin 16) : Bool :=
  let cf := flags.getLsbD 0
  let pf := flags.getLsbD 2
  let zf := flags.getLsbD 6
  let sf := flags.getLsbD 7
  let of := flags.getLsbD 11
  match code.val with
  | 0 => of
  | 1 => !of
  | 2 => cf
  | 3 => !cf
  | 4 => zf
  | 5 => !zf
  | 6 => cf || zf
  | 7 => !cf && !zf
  | 8 => sf
  | 9 => !sf
  | 10 => pf
  | 11 => !pf
  | 12 => sf != of
  | 13 => sf == of
  | 14 => zf || (sf != of)
  | _ => !zf && (sf == of)

/-- The operand is read before the destination is changed, including aliasing
registers and a memory source addressed by the destination register. -/
inductive Source
  | register (reg : Register)
  | memory (address : Word)
  deriving DecidableEq, Repr

def readSource (s : State) (source : Source) (bytes : Nat) :
    Except Fault (Word × List Event) :=
  match source with
  | .register r => .ok (s.gpr r, [])
  | .memory address =>
      match readMemory s.memory address bytes with
      | .error fault => .error fault
      | .ok (value, event) => .ok (value, [event])

/-- Intel CMOVcc Operation: 32-bit writes zero-extend even when the condition
is false. The 16-bit untaken case preserves every destination bit. -/
def cmovValue (width : CmovWidth) (taken : Bool) (old source : Word) : Word :=
  match width with
  | .w16 => if taken then (old &&& 0xffffffffffff0000) ||| (source &&& 0xffff)
      else old
  | .w32 => (if taken then source else old) &&& 0xffffffff
  | .w64 => if taken then source else old

/-- Bit selection wraps modulo the operand size. The instruction layer only
supplies architectural widths; the generalized primitive also covers byte lanes. -/
def bitTest (base index : Word) (operandBits : Nat) : Bool :=
  (base &&& ((1 : Word) <<< (index &&& (BitVec.ofNat 64 operandBits - 1)))) != 0

def setFlag (flags : Word) (bit : Nat) (value : Bool) : Word :=
  let mask := (1 : Word) <<< bit
  if value then flags ||| mask else flags &&& ~~~mask

/-- BMI2 zero-high-bits takes an unsigned byte index. This generalized
primitive also serves narrower implementation contracts. -/
def zeroHighBits (source count : Word) (operandBits : Nat) : Word :=
  let index := count &&& 0xff
  let mask := BitVec.ofNat 64 (2 ^ operandBits) - 1
  let kept := if BitVec.ult index (BitVec.ofNat 64 operandBits)
    then ((1 : Word) <<< index) - 1 else mask
  source &&& kept &&& mask

def bzhiCarry (normalizedCount : Word) (operandBits : Nat) : Bool :=
  BitVec.ule (BitVec.ofNat 64 operandBits) normalizedCount

def resultZero (result : Word) : Bool := result == 0

def resultSign (result : Word) (operandBits : Nat) : Bool :=
  result.getLsbD (operandBits - 1)

/-- ZF/SF follow the result; CF reports an index at least the operand size,
OF is cleared. AF/PF are undefined and are handled by the step relation. -/
def bzhiFlags (flags normalizedCount result : Word) (operandBits : Nat) : Word :=
  setFlag (setFlag (setFlag (setFlag flags 0 (bzhiCarry normalizedCount operandBits))
    6 (resultZero result)) 7 (resultSign result operandBits)) 11 false

/-- BMI1 ANDN inverts its first source, not the memory/register second source. -/
def andNot (first second : Word) : Word := ~~~first &&& second

/-- CF/OF are zero and ZF/SF follow the operand-sized result. AF/PF are
undefined, represented by preservation and unconstrained in the step relation. -/
def andnFlags (flags result : Word) (operandBits : Nat) : Word :=
  setFlag (setFlag (setFlag (setFlag flags 0 false) 6 (resultZero result))
    7 (resultSign result operandBits)) 11 false

/-- Double shifts use five count bits, or six at operand size 64. -/
def doubleShiftCount (count : Word) (operandBits : Nat) : Word :=
  count &&& (if operandBits = 64 then 63 else 31)

/-- Form a double-width concatenation, shift it, and select the destination
half. For counts exceeding operand size the ISA permits any low-lane result;
this expression is an executable representative, not an extra defined result. -/
def doubleShiftValue (left : Bool) (destination source count : Word)
    (operandBits : Nat) : Word :=
  let mask := BitVec.ofNat 64 (2 ^ operandBits) - 1
  let dst := (destination &&& mask).setWidth 128
  let src := (source &&& mask).setWidth 128
  let amount := (doubleShiftCount count operandBits).setWidth 128
  let pair := if left then (dst <<< operandBits) ||| src else (src <<< operandBits) ||| dst
  let shifted := if left then (pair <<< amount) >>> BitVec.ofNat 128 operandBits
    else pair >>> amount
  (shifted.setWidth operandBits).setWidth 64

/-- OF at count one reports a sign change for both SHLD and SHRD. The
preserved representative at other counts imposes no ISA-defined flag value. -/
def doubleShiftOverflow (original result count : Word) (operandBits : Nat) (old : Bool) : Bool :=
  if count = 1 then resultSign original operandBits != resultSign result operandBits else old

/-- POP into SP/RSP increments the incoming stack pointer before writing
its destination. The16-bit write retains the incremented pointer's high bits. -/
def popRsp (rsp value : Word) (operandBits : Nat) : Word :=
  let advanced := rsp + BitVec.ofNat 64 (operandBits / 8)
  let mask := BitVec.ofNat 64 (2 ^ operandBits) - 1
  if operandBits = 32 then value &&& mask
  else (advanced &&& ~~~mask) ||| (value &&& mask)

inductive BzhiWidth
  | w32 | w64
  deriving DecidableEq, Repr

def BzhiWidth.bytes : BzhiWidth → Nat | .w32 => 4 | .w64 => 8

def BzhiWidth.bits (width : BzhiWidth) : Nat := width.bytes * 8

inductive BitIndex
  | register (reg : Register)
  | immediate (value : Byte)
  deriving DecidableEq, Repr

def CmovWidth.bits (width : CmovWidth) : Nat := width.bytes * 8

def bitIndexValue (s : State) : BitIndex → Word
  | .register r => s.gpr r
  | .immediate b => b.setWidth 64

/-- A memory bit string with a register index uses a signed word displacement;
immediate indices use the instruction's already encoded effective address. -/
def bitBaseSource (width : CmovWidth) (source : Source) (index : BitIndex)
    (s : State) : Source :=
  match source, index with
  | .memory address, .register r =>
      let value := match width with
        | .w16 => ((s.gpr r).setWidth 16).toInt
        | .w32 => ((s.gpr r).setWidth 32).toInt
        | .w64 => (s.gpr r).toInt
      .memory (address + BitVec.ofInt 64 (value / width.bits * width.bytes))
  | _, _ => source

/-- One architectural instruction with its decoded fall-through address.
Effective-address decoding supplies the memory source address; reads remain
part of this step, so a false-condition CMOV cannot suppress an access fault. -/
inductive Instruction
  | push (width : StackWidth) (src : Register) (nextPc : Word)
  | pop (width : StackWidth) (dst : Register) (nextPc : Word)
  | cmov (width : CmovWidth) (cc : Fin 16) (dst : Register)
      (source : Source) (nextPc : Word)
  | andn (width : BzhiWidth) (dst first : Register) (second : Source) (nextPc : Word)
  | bzhi (width : BzhiWidth) (dst : Register) (source : Source)
      (count : Register) (nextPc : Word)
  | bt (width : CmovWidth) (source : Source) (index : BitIndex) (nextPc : Word)
  deriving DecidableEq, Repr

def step (instruction : Instruction) (s : State) : Transition State :=
  match instruction with
  | .push width src nextPc =>
      let address := s.gpr 4 - BitVec.ofNat 64 width.bytes
      match writeMemory s.memory address (s.gpr src) width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (memory, event) =>
          ⟨{ s with gpr := (fun r => if r = 4 then address else s.gpr r), memory := memory, pc := nextPc }, [event], none⟩
  | .pop width dst nextPc =>
      match readSource s (.memory (s.gpr 4)) width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          let advanced := s.gpr 4 + BitVec.ofNat 64 width.bytes
          let afterStack := fun r => if r = 4 then advanced else s.gpr r
          let result := cmovValue width.registerWidth true (afterStack dst) value
          ⟨{ s with gpr := (fun r => if r = dst then result else afterStack r), pc := nextPc }, events, none⟩
  | .cmov width cc dst source nextPc =>
      match readSource s source width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          let result := cmovValue width (condition s.rflags cc) (s.gpr dst) value
          ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), pc := nextPc }, events, none⟩
  | .bt width source index nextPc =>
      match readSource s (bitBaseSource width source index s) width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          ⟨{ s with rflags := setFlag s.rflags 0 (bitTest value (bitIndexValue s index) width.bits), pc := nextPc },
            events, none⟩

  | .andn width dst first second nextPc =>
      match readSource s second width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          let mask := BitVec.ofNat 64 (2 ^ width.bits) - 1
          let result := andNot (s.gpr first) value &&& mask
          ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), rflags := andnFlags s.rflags result width.bits, pc := nextPc }, events, none⟩
  | .bzhi width dst source count nextPc =>
      match readSource s source width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          let count := s.gpr count &&& 0xff
          let result := zeroHighBits value count width.bits
          ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), rflags := bzhiFlags s.rflags count result width.bits, pc := nextPc }, events, none⟩

/-- Defined RFLAGS output bits. BT sets CF and preserves ZF; OF/SF/AF/PF
are undefined. BZHI leaves only AF/PF undefined. The mask is consumed by hardware
checks and the step relation, rather than imposing values on undefined bits. -/
def definedFlags : Instruction → Word
  | .push .. => 0xffffffffffffffff
  | .pop .. => 0xffffffffffffffff
  | .cmov .. => 0xffffffffffffffff
  | .bt .. => 0xfffffffffffff76b
  | .andn .. => 0xffffffffffffffeb
  | .bzhi .. => 0xffffffffffffffeb

/-- The executable gives a representative for undefined flags. The relational
ISA semantics below admits every value for those bits, as required by the SDM. -/
def matchesTransition (i : Instruction) (expected actual : Transition State) : Prop :=
  expected.events = actual.events ∧ expected.fault = actual.fault ∧
    let mask := if expected.fault.isSome then 0xffffffffffffffff else definedFlags i
    { expected.state with rflags := expected.state.rflags &&& mask } =
      { actual.state with rflags := actual.state.rflags &&& mask }

def Step (i : Instruction) (before : State) (after : Transition State) : Prop :=
  matchesTransition i (step i before) after

/-- Legacy prefix state for 64-bit decoding. A legacy prefix after a REX
invalidates that REX; a later REX supersedes earlier ones. -/
private structure Prefix where
  operand16 : Bool := false
  address32 : Bool := false
  rex : Nat := 0
  segment : Nat := 0
  vexInvalid : Bool := false

private def prefixes : List Byte → Prefix → Nat → Prefix × List Byte × Nat
  | [], p, n => (p, [], n)
  | b :: rest, p, n =>
      let v := b.toNat
      if v = 0x66 then prefixes rest { p with operand16 := true, rex := 0, vexInvalid := true } (n + 1)
      else if v = 0x67 then prefixes rest { p with address32 := true, rex := 0 } (n + 1)
      else if v = 0x64 ∨ v = 0x65 then
        prefixes rest { p with segment := v, rex := 0 } (n + 1)
      else if v = 0x26 ∨ v = 0x2e ∨ v = 0x36 ∨ v = 0x3e then
        prefixes rest { p with segment := 0, rex := 0 } (n + 1)
      else if v = 0xf2 ∨ v = 0xf3 then prefixes rest { p with rex := 0, vexInvalid := true } (n + 1)
      else if 0x40 ≤ v ∧ v ≤ 0x4f then prefixes rest { p with rex := v - 0x40, vexInvalid := true } (n + 1)
      else (p, b :: rest, n)

private def byteAt (bytes : Array Byte) (position : Nat) : Except String Nat :=
  match bytes[position]? with
  | some b => .ok b.toNat
  | none => .error "truncated native encoding"

private def signedDisplacement (bytes : Array Byte) (position size : Nat) :
    Except String Word := do
  let mut value := 0
  for i in [:size] do
    value := value + (← byteAt bytes (position + i)) * 256 ^ i
  if size = 0 then pure 0
  else pure ((BitVec.ofNat (size * 8) value).signExtend 64)

private def registerCode (code : Nat) : Register :=
  ⟨code % 16, Nat.mod_lt _ (by decide)⟩

private structure AddressParts where
  base : Word
  index : Word
  relative : Bool
  missingBase : Bool
  cursor : Nat

/-- Intel 64 ModRM/SIB addressing. RIP-relative and no-base SIB are distinct;
REX.X permits R12 as an index where the unextended index code means no index. -/
private def addressParts (s : State) (p : Prefix) (bytes : Array Byte)
    (mode rm cursor : Nat) : Except String AddressParts := do
  if rm = 4 then
    let sib ← byteAt bytes cursor
    let baseCode := sib % 8
    let indexCode := (sib / 8) % 8
    let scale := 2 ^ (sib / 64)
    let index := if indexCode = 4 ∧ (p.rex / 2) % 2 = 0 then 0
      else s.gpr (registerCode (indexCode + 8 * ((p.rex / 2) % 2))) * BitVec.ofNat 64 scale
    let missing : Bool := mode == 0 && baseCode == 5
    pure ⟨if missing then 0 else s.gpr (registerCode (baseCode + 8 * (p.rex % 2))),
      index, false, missing, cursor + 1⟩
  else
    let relative : Bool := mode == 0 && rm == 5
    pure ⟨if relative then 0 else s.gpr (registerCode (rm + 8 * (p.rex % 2))),
      0, relative, relative, cursor⟩

/-- Shared register/memory operand decoding. Trailing immediate bytes count
in RIP-relative addressing and in the architectural instruction-length limit. -/
private def operand (bytes : Array Byte) (s : State) (p : Prefix)
    (modrm cursor trailing : Nat) : Except String (Source × Word × Nat) := do
  let mode := modrm / 64
  let rm := modrm % 8
  if mode = 3 then
    let length := cursor + trailing
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    pure (.register (registerCode (rm + 8 * (p.rex % 2))),
      s.pc + BitVec.ofNat 64 length, cursor)
  else
    let parts ← addressParts s p bytes mode rm cursor
    let size := if mode = 1 then 1 else if mode = 2 ∨ parts.missingBase then 4 else 0
    let displacement ← signedDisplacement bytes parts.cursor size
    let afterDisp := parts.cursor + size
    let length := afterDisp + trailing
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    let nextPc := s.pc + BitVec.ofNat 64 length
    let base := if parts.relative then nextPc else parts.base
    let offset := base + parts.index + displacement
    let offset := if p.address32 then (offset.setWidth 32).setWidth 64 else offset
    let segment := if p.segment = 0x64 then s.fsBase else if p.segment = 0x65 then s.gsBase else 0
    pure (.memory (segment + offset), nextPc, afterDisp)

/-- Decode a native instruction. Operands, effective addresses and fall-through
PC are obtained from bytes, including REX, operand/address size, segment bases,
ModRM, SIB and signed displacement. No caller-supplied decode is trusted. -/
def decode (bytes : Array Byte) (s : State) : Except String Instruction := do
  let (p, _, count) := prefixes bytes.toList {} 0
  let first ← byteAt bytes count
  if 0x50 ≤ first ∧ first ≤ 0x57 then
    let length := count + 1
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    let src := registerCode (first % 8 + 8 * (p.rex % 2))
    let width := if p.operand16 then StackWidth.w16 else .w64
    return .push width src (s.pc + BitVec.ofNat 64 length)
  if 0x58 ≤ first ∧ first ≤ 0x5f then
    let length := count + 1
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    let dst := registerCode (first % 8 + 8 * (p.rex % 2))
    let width := if p.operand16 then StackWidth.w16 else .w64
    return .pop width dst (s.pc + BitVec.ofNat 64 length)
  if first = 0x8f then
    let modrm ← byteAt bytes (count + 1)
    if modrm / 64 ≠ 3 ∨ (modrm / 8) % 8 ≠ 0 then
      throw "expected POP register encoding"
    let length := count + 2
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    let dst := registerCode (modrm % 8 + 8 * (p.rex % 2))
    let width := if p.operand16 then StackWidth.w16 else .w64
    return .pop width dst (s.pc + BitVec.ofNat 64 length)
  if first = 0xc4 then
    let vex1 ← byteAt bytes (count + 1)
    let vex2 ← byteAt bytes (count + 2)
    let opcode ← byteAt bytes (count + 3)
    if p.vexInvalid ∨ vex1 % 32 ≠ 2 ∨ vex2 % 8 ≠ 0 ∨ (opcode ≠ 0xf5 ∧ opcode ≠ 0xf2) then
      throw "invalid BMI VEX encoding"
    let rex := (if vex1 / 128 = 0 then 4 else 0) +
      (if (vex1 / 64) % 2 = 0 then 2 else 0) +
      (if (vex1 / 32) % 2 = 0 then 1 else 0)
    let p := { p with rex := rex }
    let modrm ← byteAt bytes (count + 4)
    let dst := registerCode ((modrm / 8) % 8 + 8 * ((rex / 4) % 2))
    let index := registerCode (15 - (vex2 / 8) % 16)
    let width := if vex2 / 128 = 0 then BzhiWidth.w32 else .w64
    let (source, nextPc, _) ← operand bytes s p modrm (count + 5) 0
    if opcode = 0xf2 then return .andn width dst index source nextPc
    return .bzhi width dst source index nextPc
  let opcode ← byteAt bytes (count + 1)
  if first ≠ 0x0f then throw "expected two-byte native opcode"
  let modrm ← byteAt bytes (count + 2)
  let reg := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
  let width := if p.rex / 8 = 1 then CmovWidth.w64
    else if p.operand16 then .w16 else .w32
  if 0x40 ≤ opcode ∧ opcode ≤ 0x4f then
    let (source, nextPc, _) ← operand bytes s p modrm (count + 3) 0
    let cc : Fin 16 := ⟨opcode % 16, Nat.mod_lt _ (by decide)⟩
    pure (.cmov width cc reg source nextPc)
  else if opcode = 0xa3 then
    let (source, nextPc, _) ← operand bytes s p modrm (count + 3) 0
    pure (.bt width source (.register reg) nextPc)
  else if opcode = 0xba ∧ (modrm / 8) % 8 = 4 then
    let (source, nextPc, cursor) ← operand bytes s p modrm (count + 3) 1
    let immediate ← byteAt bytes cursor
    pure (.bt width source (.immediate (BitVec.ofNat 8 immediate)) nextPc)
  else throw "unrecognized native opcode"

end KProgFormal.Reference.X86
