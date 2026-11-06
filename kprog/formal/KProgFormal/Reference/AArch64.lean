import KProgFormal.Reference.Memory

/-!
AArch64 reference semantics, from Arm DDI0602 A64 Base Instructions
(MADD, MSUB, UMADDL, SMADDL, UMULH, UDIV) and shared X[] register access:
https://documentation-service.arm.com/static/67e40f3398aa3c3b6eea6a85
This module imports no simulator or generated implementation contract.
-/
namespace KProgFormal.Reference.AArch64

abbrev Register := Fin 32
abbrev Gpr := Fin 31

inductive Width | w32 | w64
  deriving DecidableEq, Repr

def Width.bits : Width → Nat | .w32 => 32 | .w64 => 64

def Width.bytes : Width → Nat | .w32 => 4 | .w64 => 8

def narrow (value : Word) (width : Width) : Word :=
  (value.setWidth width.bits).setWidth 64

structure State where
  gpr : Gpr → Word
  sp : Word
  flags : Word
  vector0 : BitVec 128
  memory : Memory
  pc : Word

/-- Arm ConditionHolds for all sixteen raw encoding values. AL and NV both
hold; inversion is suppressed for NV in the architectural pseudocode. -/
def condition (flags : Word) (cc : Fin 16) : Bool :=
  let n := flags.getLsbD 31
  let z := flags.getLsbD 30
  let c := flags.getLsbD 29
  let v := flags.getLsbD 28
  match cc.val with
  | 0 => z | 1 => !z | 2 => c | 3 => !c
  | 4 => n | 5 => !n | 6 => v | 7 => !v
  | 8 => c && !z | 9 => !c || z
  | 10 => n == v | 11 => n != v
  | 12 => !z && (n == v) | 13 => z || (n != v)
  | _ => true

/-- In arithmetic register encodings, field31 is ZR, never SP. -/
def readReg (s : State) (r : Register) : Word :=
  if h : r.val < 31 then s.gpr ⟨r.val, h⟩ else 0

/-- W writes zero-extend; writing ZR discards the result and leaves SP alone. -/
def writeReg (s : State) (r : Register) (value : Word) : State :=
  { s with gpr := fun i => if i.val = r.val then value else s.gpr i }

/-- Shared scalar primitives. Long multiply widens each 32-bit source before
multiplying; unsigned high multiply selects the high half of the full product.
MUL and UMULL are aliases with a zero-register accumulator. -/
inductive MulOp | madd | msub | mul | umull | udiv | umulh | umaddl | smaddl
  deriving DecidableEq, Repr

def mulValue (op : MulOp) (lhs rhs addend : Word) : Word :=
  match op with
  | .madd => lhs * rhs + addend
  | .msub => addend + ~~~(lhs * rhs) + 1
  | .mul => lhs * rhs
  | .umull => (lhs.setWidth 32).setWidth 64 * (rhs.setWidth 32).setWidth 64
  | .udiv => if rhs = 0 then 0 else lhs / rhs
  | .umulh => (((lhs.setWidth 128) * (rhs.setWidth 128)) >>> 64).setWidth 64
  | .umaddl => (lhs.setWidth 32).setWidth 64 * (rhs.setWidth 32).setWidth 64 + addend
  | .smaddl => (lhs.setWidth 32).signExtend 64 * (rhs.setWidth 32).signExtend 64 + addend

inductive MulInstruction
  | multiply (width : Width) (subtract : Bool) (dst lhs rhs addend : Register)
  | longMultiply (signed : Bool) (dst lhs rhs addend : Register)
  | unsignedHigh (dst lhs rhs : Register)
  | unsignedDivide (width : Width) (dst lhs rhs : Register)
  deriving DecidableEq, Repr

def mulResult (i : MulInstruction) (s : State) : Register × Word :=
  match i with
  | .multiply width subtract dst lhs rhs addend =>
      let op := if subtract then MulOp.msub else .madd
      (dst, narrow (mulValue op (narrow (readReg s lhs) width)
        (narrow (readReg s rhs) width) (narrow (readReg s addend) width)) width)
  | .longMultiply signed dst lhs rhs addend =>
      let op := if signed then MulOp.smaddl else .umaddl
      (dst, mulValue op (readReg s lhs) (readReg s rhs) (readReg s addend))
  | .unsignedHigh dst lhs rhs =>
      (dst, mulValue .umulh (readReg s lhs) (readReg s rhs) 0)
  | .unsignedDivide width dst lhs rhs =>
      (dst, narrow (mulValue .udiv (narrow (readReg s lhs) width)
        (narrow (readReg s rhs) width) 0) width)

def mulStep (i : MulInstruction) (s : State) : Transition State :=
  let (dst, value) := mulResult i s
  ⟨{ writeReg s dst value with pc := s.pc + 4 }, [], none⟩

inductive SelectElse | keep | increment | invert | negate
  deriving DecidableEq, Repr

/-- A64 conditional-select sources are read at the operand size, with the
false-path operation applied before the zero-extending destination write. -/
def selectValue (width : Width) (alternative : SelectElse) (taken : Bool)
    (lhs rhs : Word) : Word :=
  let lhs := narrow lhs width
  let rhs := narrow rhs width
  narrow (if taken then lhs else match alternative with
    | .keep => rhs | .increment => rhs + 1 | .invert => ~~~rhs | .negate => -rhs) width

/-- Architectural byte permutations, stated as byte lists rather than the
implementation's shift-and-mask ladders. -/
def reverseBytes (value : Word) (bytes : Nat) : Word :=
  littleEndian 64 (valueBytes value bytes).reverse

def reverseHalfwordBytes (value : Word) (bytes : Nat) : Word :=
  littleEndian 64 ((List.range bytes).map (fun i => (value >>> (8 * (i ^^^ 1))).setWidth 8))

def signExtendValue (value : Word) (sourceBits : Nat) : Word :=
  (value.setWidth sourceBits).signExtend 64

/-- Extract a width-sized window from the concatenated, width-sized sources.
The instruction carries a legal immediate; the generalized primitive also
serves the old bounded contracts, including their masked-count domains. -/
def extractRawWindow (sourceBits : Nat) (lhs rhs shift : Word) : Word :=
  let amount := shift &&& BitVec.ofNat 64 (sourceBits - 1)
  let pair := (lhs.setWidth 128 <<< sourceBits) ||| rhs.setWidth 128
  (pair >>> amount.setWidth 128).setWidth 64 &&& BitVec.ofNat 64 (2^sourceBits - 1)

def extractValue (sourceBits : Nat) (lhs rhs shift : Word) : Word :=
  extractRawWindow sourceBits ((lhs.setWidth sourceBits).setWidth 64)
    ((rhs.setWidth sourceBits).setWidth 64) shift

inductive ExtendBits | byte | half | word
  deriving DecidableEq, Repr

def ExtendBits.bits : ExtendBits → Nat | .byte => 8 | .half => 16 | .word => 32

inductive ExtrevInstruction
  | extract (width : Width) (amount : Fin width.bits) (dst lhs rhs : Register)
  | reverse (width : Width) (halfwords : Bool) (dst src : Register)
  | extend (width : Width) (source : ExtendBits) (dst src : Register)
  deriving DecidableEq, Repr

def extrevResult (i : ExtrevInstruction) (s : State) : Register × Word :=
  match i with
  | .extract width amount dst lhs rhs =>
      (dst, extractValue width.bits (readReg s lhs) (readReg s rhs) (BitVec.ofNat 64 amount.val))
  | .reverse width halfwords dst src =>
      (dst, if halfwords then reverseHalfwordBytes (readReg s src) width.bytes
        else reverseBytes (readReg s src) width.bytes)
  | .extend width source dst src =>
      (dst, narrow (signExtendValue (readReg s src) source.bits) width)

def extrevStep (i : ExtrevInstruction) (s : State) : Transition State :=
  let (dst, value) := extrevResult i s
  ⟨{ writeReg s dst value with pc := s.pc + 4 }, [], none⟩

inductive Instruction
  | mul (instruction : MulInstruction)
  | extrev (instruction : ExtrevInstruction)
  | select (width : Width) (alternative : SelectElse) (dst lhs rhs : Register) (predicate : Fin 16)
  deriving DecidableEq, Repr

def step (i : Instruction) (s : State) : Transition State :=
  match i with
  | .mul instruction => mulStep instruction s
  | .extrev instruction => extrevStep instruction s
  | .select width alternative dst lhs rhs predicate =>
      let value := selectValue width alternative (condition s.flags predicate) (readReg s lhs) (readReg s rhs)
      ⟨{ writeReg s dst value with pc := s.pc + 4 }, [], none⟩

def Step (i : Instruction) (before : State) (after : Transition State) : Prop :=
  step i before = after

private def register (n : Nat) : Register := ⟨n % 32, Nat.mod_lt _ (by decide)⟩

/-- Decode an actual little-endian A64 instruction word. The opcode masks
include fixed and reserved bits, and long/high multiplies require their X form. -/
def decode (bytes : Array Byte) : Except String Instruction := do
  if bytes.size ≠ 4 then throw "AArch64 instruction must contain exactly four native bytes"
  let word := (littleEndian 32 bytes.toList).toNat
  let width := if word / 2^31 = 0 then Width.w32 else .w64
  let dst := register word
  let lhs := register (word / 2^5)
  let rhs := register (word / 2^16)
  let addend := register (word / 2^10)
  if word &&& 0xffe00000 = 0x13800000 ∨ word &&& 0xffe00000 = 0x93c00000 then
    let amount := (word / 2^10) % 64
    if h : amount < width.bits then return .extrev (.extract width ⟨amount, h⟩ dst lhs rhs)
    else throw "reserved EXTR immediate"
  let unary := word &&& 0xfffffc00
  if unary = 0x5ac00800 ∨ unary = 0xdac00c00 then
    return .extrev (.reverse width false dst lhs)
  if unary = 0x5ac00400 ∨ unary = 0xdac00400 then
    return .extrev (.reverse width true dst lhs)
  if word &&& 0xffc00000 = 0x13000000 ∨ word &&& 0xffc00000 = 0x93400000 then
    if (word / 2^16) % 64 = 0 then
      let sourceBits := (word / 2^10) % 64 + 1
      if sourceBits = 8 then return .extrev (.extend width .byte dst lhs)
      if sourceBits = 16 then return .extrev (.extend width .half dst lhs)
      if sourceBits = 32 then return .extrev (.extend width .word dst lhs)
  if word &&& 0x3fe00800 = 0x1a800000 then
    let alternative := if (word / 2^30) % 2 = 0 then
      (if (word / 2^10) % 2 = 0 then SelectElse.keep else .increment)
      else (if (word / 2^10) % 2 = 0 then .invert else .negate)
    let predicate : Fin 16 := ⟨(word / 2^12) % 16, Nat.mod_lt _ (by decide)⟩
    return .select width alternative dst lhs rhs predicate
  if word &&& 0x7fe00000 = 0x1b000000 then
    return .mul (.multiply width ((word / 2^15) % 2 == 1) dst lhs rhs addend)
  if word &&& 0xffe08000 = 0x9ba00000 then
    return .mul (.longMultiply false dst lhs rhs addend)
  if word &&& 0xffe08000 = 0x9b200000 then
    return .mul (.longMultiply true dst lhs rhs addend)
  if word &&& 0xffe0fc00 = 0x9bc07c00 then return .mul (.unsignedHigh dst lhs rhs)
  if word &&& 0x7fe0fc00 = 0x1ac00800 then return .mul (.unsignedDivide width dst lhs rhs)
  throw "unrecognized AArch64 native opcode"

end KProgFormal.Reference.AArch64
