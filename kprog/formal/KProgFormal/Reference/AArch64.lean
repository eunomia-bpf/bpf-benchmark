import KProgFormal.Reference.Memory

/-!
AArch64 reference semantics, from Arm DDI0602 A64 Base Instructions
(scalar operations, FMOV bit transfers and byte-vector reductions)
and shared X[] register access:
https://documentation-service.arm.com/static/67e40f3398aa3c3b6eea6a85
Shifted MVN/NEG are also described by Arm 100076_0100 D2.114/D2.115:
https://documentation-service.arm.com/static/6245c734b059dc5ff9a8bdab
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
  /-- V1..V31, distinct from the retained V0 field. -/
  vectorTail : Fin 31 → BitVec 128 := fun _ => 0
  memory : Memory
  pc : Word
  /-- Effective SCTLR.SA/SA0 for the executing exception level. Linux enables it. -/
  spAlignmentCheck : Bool := true
  /-- FEAT_LSE2 makes a pair one architectural memory access. Cortex-A72 has none. -/
  pairSingleAccess : Bool := false

/-- Full architectural SIMD bank. The separate V0 field preserves the earlier
reference interface; index31 is V31, unrelated to integer ZR/SP. -/
def readVector (s : State) (index : Register) : BitVec 128 :=
  if h : index.val = 0 then s.vector0 else s.vectorTail ⟨index.val - 1, by omega⟩

def writeVector (s : State) (index : Register) (value : BitVec 128) : State :=
  if index.val = 0 then { s with vector0 := value }
  else { s with vectorTail := fun i => if i.val + 1 = index.val then value else s.vectorTail i }

@[simp] theorem readVector_zero (s : State) : readVector s 0 = s.vector0 := by
  simp [readVector]

@[simp] theorem writeVector_zero (s : State) (value : BitVec 128) :
    writeVector s 0 value = { s with vector0 := value } := by simp [writeVector]

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

inductive ShiftKind | lsl | lsr | asr | ror
  deriving DecidableEq, Repr

/-- Shift the architectural source size, then zero-extend the result. Register
counts are reduced modulo that size; immediate instructions carry a legal count.
Rotation selects a window from two copies of the operand. -/
def shiftValue (width : Width) (kind : ShiftKind) (value amount : Word) : Word :=
  let amount := amount &&& BitVec.ofNat 64 (width.bits - 1)
  let source := value.setWidth width.bits
  match kind with
  | .lsl => (source <<< amount).setWidth 64
  | .lsr => (source >>> amount).setWidth 64
  | .asr => (source.sshiftRight' amount).setWidth 64
  | .ror => extractValue width.bits value value amount

/-- NEG's register encoding admits LSL/LSR/ASR only. -/
def arithmeticShift (code : Fin 3) : ShiftKind :=
  match code.val with | 0 => .lsl | 1 => .lsr | _ => .asr

inductive ShiftInstruction
  | register (width : Width) (kind : ShiftKind) (dst src count : Register)
  | immediate (width : Width) (kind : ShiftKind) (amount : Fin width.bits) (dst src : Register)
  | invert (width : Width) (kind : ShiftKind) (amount : Fin width.bits) (dst src : Register)
  | negate (width : Width) (kind : Fin 3) (amount : Fin width.bits) (dst src : Register)
  deriving DecidableEq, Repr

def shiftResult (i : ShiftInstruction) (s : State) : Register × Word :=
  match i with
  | .register width kind dst src count =>
      (dst, shiftValue width kind (readReg s src) (readReg s count))
  | .immediate width kind amount dst src =>
      (dst, shiftValue width kind (readReg s src) (BitVec.ofNat 64 amount.val))
  | .invert width kind amount dst src =>
      (dst, narrow (~~~(shiftValue width kind (readReg s src) (BitVec.ofNat 64 amount.val))) width)
  | .negate width kind amount dst src =>
      (dst, narrow (-(shiftValue width (arithmeticShift kind) (readReg s src)
        (BitVec.ofNat 64 amount.val))) width)

def shiftStep (i : ShiftInstruction) (s : State) : Transition State :=
  let (dst, value) := shiftResult i s
  ⟨{ writeReg s dst value with pc := s.pc + 4 }, [], none⟩

inductive LogicOp
  | conjunction (invert setFlags : Bool)
  | disjunction (invert : Bool)
  | exclusive
  deriving DecidableEq, Repr

def LogicOp.setFlags : LogicOp → Bool
  | .conjunction _ flags => flags | _ => false

/-- Logical operands are architectural-width bit strings. Complement is
applied after the shift and before the logical operation. -/
def logicValue (width : Width) (op : LogicOp) (lhs rhs : Word) : Word :=
  let lhs := lhs.setWidth width.bits
  let rhs := rhs.setWidth width.bits
  (match op with
    | .conjunction invert _ => lhs &&& (if invert then ~~~rhs else rhs)
    | .disjunction invert => lhs ||| (if invert then ~~~rhs else rhs)
    | .exclusive => lhs ^^^ rhs).setWidth 64

/-- Logical flag writes replace NZCV only; C and V are zero. -/
def logicFlags (width : Width) (result old : Word) : Word :=
  (old &&& 0xffffffff0fffffff) |||
    (if result.getLsbD (width.bits - 1) then 0x80000000 else 0) |||
    (if narrow result width = 0 then 0x40000000 else 0)

structure LogicInstruction where
  width : Width
  op : LogicOp
  kind : ShiftKind
  amount : Fin width.bits
  dst : Register
  lhs : Register
  rhs : Register
  deriving DecidableEq, Repr

def logicStep (i : LogicInstruction) (s : State) : Transition State :=
  let rhs := shiftValue i.width i.kind (readReg s i.rhs) (BitVec.ofNat 64 i.amount.val)
  let result := logicValue i.width i.op (readReg s i.lhs) rhs
  let flags := if i.op.setFlags then logicFlags i.width result s.flags else s.flags
  ⟨{ writeReg s i.dst result with flags := flags, pc := s.pc + 4 }, [], none⟩

/-- Replace one halfword, using a library truncation for the immediate. This
raw primitive also gives the pre-existing wider-immediate contracts a common
specification; native decoding restricts both the column and immediate. -/
def moveKeepRaw (column : Nat) (dst immediate : Word) : Word :=
  let mask : Word := 0xffff <<< column
  (dst &&& ~~~mask) ||| ((immediate.setWidth 16).setWidth 64 <<< column)

structure KeepInstruction where
  width : Width
  column : Fin (width.bits / 16)
  immediate : BitVec 16
  dst : Register
  deriving DecidableEq, Repr

def keepStep (i : KeepInstruction) (s : State) : Transition State :=
  let result := moveKeepRaw (16 * i.column.val) (readReg s i.dst) (i.immediate.setWidth 64)
  ⟨{ writeReg s i.dst (narrow result i.width) with pc := s.pc + 4 }, [], none⟩

/-- Normalized operand identities: field31 is decoded as SP or ZR by its
instruction class; the two architectural registers are never conflated. -/
inductive RegisterRef
  | general (reg : Gpr)
  | zero
  | stack
  deriving DecidableEq, Repr

def readData (s : State) : RegisterRef → Word
  | .general r => s.gpr r | .zero => 0 | .stack => s.sp

def writeData (s : State) (dst : RegisterRef) (value : Word) (width : Width) : State :=
  let value := narrow value width
  match dst with
  | .general r => { s with gpr := fun i => if i.val = r.val then value else s.gpr i }
  | .zero => s
  | .stack => { s with sp := value }

def moveRegStep (width : Width) (dst src : RegisterRef) (s : State) : Transition State :=
  ⟨{ writeData s dst (readData s src) width with pc := s.pc + 4 }, [], none⟩

/-- FMOV general transfers bits without floating-point conversion. Vpart part0
writes zero-extend across all128 vector bits; W destinations zero-extend in X.
Arm DDI0602 FMOV (general) and shared Vpart/V register-access pseudocode. -/
inductive FmovInstruction
  | toVector (width : Width) (src : Register)
  | fromVector (width : Width) (dst : Register)
  deriving DecidableEq, Repr

def fmovBankStep (bank : Register) (i : FmovInstruction) (s : State) : Transition State :=
  let result := match i with
    | .toVector width src => writeVector s bank ((narrow (readReg s src) width).setWidth 128)
    | .fromVector width dst => writeReg s dst (narrow ((readVector s bank).setWidth 64) width)
  ⟨{ result with pc := s.pc + 4 }, [], none⟩

/-- The original V0 instruction interface is the bank-zero specialization. -/
def fmovStep (i : FmovInstruction) (s : State) : Transition State := fmovBankStep 0 i s

inductive ReductionOp | count | unsignedSum
  deriving DecidableEq, Repr

/-- Population count is a bit walk within each source byte; no generated
bit-extraction or byte-ladder contract is used by this reference. -/
def byteCount (value : Byte) : Byte :=
  (List.range 8).foldl (fun total index => total + if value.getLsbD index then 1 else 0) 0

def vectorBytes (value : BitVec 128) (wide : Bool) : List Byte :=
  (List.range (if wide then 16 else 8)).map (fun i => (value >>> (8 * i)).setWidth 8)

/-- CNT and UADDLV's 8B/16B variants. UADDLV widens unsigned bytes before
summing into H0; both operations clear every inactive upper vector bit. -/
def reductionValue (op : ReductionOp) (wide : Bool) (value : BitVec 128) : BitVec 128 :=
  let bytes := vectorBytes value wide
  match op with
  | .count => littleEndian 128 (bytes.map byteCount)
  | .unsignedSum => (bytes.foldl (fun (sum : BitVec 16) byte => sum + byte.setWidth 16) 0).setWidth 128

def reductionStep (op : ReductionOp) (wide : Bool) (s : State) : Transition State :=
  ⟨{ s with vector0 := reductionValue op wide s.vector0, pc := s.pc + 4 }, [], none⟩

/-- AddWithCarry's NZCV: operands are narrowed before unsigned/signed widening.
The extra precision distinguishes carry from signed overflow; subtraction is
addition of the complemented width-sized right operand and carry-in one. -/
def arithmeticFlags (width : Width) (subtract : Bool) (lhs rhs old : Reference.Word) : Reference.Word :=
  let left := lhs.setWidth width.bits
  let right := if subtract then ~~~(rhs.setWidth width.bits) else rhs.setWidth width.bits
  let carry : BitVec 128 := if subtract then 1 else 0
  let unsignedSum := left.setWidth 128 + right.setWidth 128 + carry
  let signedSum := left.signExtend 128 + right.signExtend 128 + carry
  let result := unsignedSum.setWidth width.bits
  let n := result.getLsbD (width.bits - 1)
  let z := result.setWidth 64 == (0 : Reference.Word)
  let c := unsignedSum.getLsbD width.bits
  let v := signedSum != result.signExtend 128
  (old &&& 0xffffffff0fffffff) ||| (if n then 0x80000000 else 0) |||
    (if z then 0x40000000 else 0) ||| (if c then 0x20000000 else 0) ||| (if v then 0x10000000 else 0)

inductive CompareOperand
  | register (src : Register)
  | immediate (value : BitVec 5)
  deriving DecidableEq, Repr

def compareOperand (s : State) : CompareOperand → Word
  | .register src => readReg s src
  | .immediate value => value.setWidth 64

def compareFallback (old : Word) (fallback : BitVec 4) : Word :=
  (old &&& 0xffffffff0fffffff) ||| (fallback.setWidth 64 <<< 28)

/-- CCMP reads the incoming condition before replacing NZCV. Its untaken
path uses the literal four-bit fallback, preserving all other state. -/
def compareStep (width : Width) (lhs : Register) (rhs : CompareOperand)
    (predicate : Fin 16) (fallback : BitVec 4) (s : State) : Transition State :=
  let flags := if condition s.flags predicate then
      arithmeticFlags width true (readReg s lhs) (compareOperand s rhs) s.flags
    else compareFallback s.flags fallback
  ⟨{ s with flags := flags, pc := s.pc + 4 }, [], none⟩

/-- ADD/SUB immediate, with flag-setting and CMP/CMN aliases. Native decode
selects SP or ZR for field31 before entering this normalized arithmetic step. -/
def arithmeticImmediateStep (width : Width) (subtract setFlags : Bool)
    (dst src : RegisterRef) (rhs : Word) (s : State) : Transition State :=
  let lhs := readData s src
  let value := if subtract then lhs - rhs else lhs + rhs
  let flags := if setFlags then arithmeticFlags width subtract lhs rhs s.flags else s.flags
  ⟨{ writeData s dst value width with flags := flags, pc := s.pc + 4 }, [], none⟩

/-- A64 ExtendReg first selects min(source-size, operand-size) bits, then
sign/zero extends to the operand size and shifts by a legal0..4 amount. -/
inductive RegisterExtend | uxtb | uxth | uxtw | uxtx | sxtb | sxth | sxtw | sxtx
  deriving DecidableEq, Repr

def RegisterExtend.bits : RegisterExtend → Nat
  | .uxtb | .sxtb => 8 | .uxth | .sxth => 16 | .uxtw | .sxtw => 32 | .uxtx | .sxtx => 64

def RegisterExtend.signed : RegisterExtend → Bool
  | .sxtb | .sxth | .sxtw | .sxtx => true | _ => false

def extendValue (width : Width) (kind : RegisterExtend) (value amount : Reference.Word) : Reference.Word :=
  let bits := min kind.bits width.bits
  let operand := if kind.signed then (value.setWidth bits).signExtend width.bits
    else (value.setWidth bits).setWidth width.bits
  (operand <<< amount).setWidth 64

def arithmeticRegisterStep (width : Width) (subtract setFlags : Bool)
    (dst src : RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
    (s : State) : Transition State :=
  arithmeticImmediateStep width subtract setFlags dst src
    (shiftValue width (arithmeticShift kind) (readReg s rhs) (BitVec.ofNat 64 amount.val)) s

def arithmeticExtendedStep (width : Width) (subtract setFlags : Bool)
    (dst src : RegisterRef) (rhs : Register) (kind : RegisterExtend) (amount : Fin 5)
    (s : State) : Transition State :=
  arithmeticImmediateStep width subtract setFlags dst src
    (extendValue width kind (readReg s rhs) (BitVec.ofNat 64 amount.val)) s

/-- Scalar memory access sizes. Integer register writes remain64 bits, with
load-width truncation and signed-load destination narrowing stated separately. -/
inductive MemoryWidth | byte | half | word | double
  deriving DecidableEq, Repr

def MemoryWidth.bytes : MemoryWidth → Nat
  | .byte => 1 | .half => 2 | .word => 4 | .double => 8

def MemoryWidth.bits (width : MemoryWidth) : Nat := width.bytes * 8

inductive MemoryTransfer
  | load (dst : Register) (signedTo : Option Width)
  | store (src : Register)
  deriving DecidableEq, Repr

structure MemoryInstruction where
  width : MemoryWidth
  transfer : MemoryTransfer
  base : Register
  offset : Word
  deriving DecidableEq, Repr

/-- Memory field31 is SP. This is distinct from a load/store data field31,
which denotes ZR. Address arithmetic wraps at64 bits. -/
def memoryBase (s : State) (base : Register) : Word :=
  if h : base.val < 31 then s.gpr ⟨base.val, h⟩ else s.sp

/-- CheckSPAlignment tests the incoming SP itself before offset addition or
any pre-index writeback, never an unaligned effective address through a GPR. -/
def spAlignmentFault (s : State) (base : Register) : Option Fault :=
  if s.spAlignmentCheck && (base.val == 31) && (s.sp &&& 15 != 0) then
    some (.spAlignment s.sp) else none

def memoryLoadValue (width : MemoryWidth) (signedTo : Option Width) (value : Word) : Word :=
  match signedTo with
  | none => (value.setWidth width.bits).setWidth 64
  | some destination => narrow ((value.setWidth width.bits).signExtend 64) destination

/-- Ordinary scalar memory transfer, including signed loads, exact byte
permissions/initialization and ordered fault effects. No source register or
memory value is synthesized on a fault. -/
def memoryStep (i : MemoryInstruction) (s : State) : Transition State :=
  match spAlignmentFault s i.base with
  | some fault => ⟨s, [.fault fault], some fault⟩
  | none =>
      let address := memoryBase s i.base + i.offset
      match i.transfer with
      | .load dst signedTo =>
          match readMemory s.memory address i.width.bytes with
          | .error fault => ⟨s, [.fault fault], some fault⟩
          | .ok (value, event) =>
              ⟨{ writeReg s dst (memoryLoadValue i.width signedTo value) with pc := s.pc + 4 }, [event], none⟩
      | .store src =>
          match writeMemory s.memory address (readReg s src) i.width.bytes with
          | .error fault => ⟨s, [.fault fault], some fault⟩
          | .ok (memory, event) => ⟨{ s with memory := memory, pc := s.pc + 4 }, [event], none⟩

/-- A pair load with duplicate destinations is constrained-unpredictable,
including permitted UNDEF/NOP outcomes. Defined native programs carry this
source-validity witness; stores may use the same source twice. -/
structure PairMemoryInstruction where
  width : Width
  load : Bool
  first : Register
  second : Register
  base : Register
  offset : Word
  distinct : load = true → first ≠ second
  deriving DecidableEq, Repr

def pairRegisters (i : PairMemoryInstruction) (s : State) (first second : Word) : State :=
  writeReg (writeReg s i.first (narrow first i.width)) i.second (narrow second i.width)

/-- LDP/STP signed-offset form. Values and base addresses are captured before
register writes. Without FEAT_LSE2 there are two ordered element accesses; a
second-store fault retains the first store. With FEAT_LSE2 the architecture
uses one double-sized access. The memory model is sequential and little-endian. -/
def pairMemoryStep (i : PairMemoryInstruction) (s : State) : Transition State :=
  match spAlignmentFault s i.base with
  | some fault => ⟨s, [.fault fault], some fault⟩
  | none =>
      let address := memoryBase s i.base + i.offset
      let secondAddress := address + BitVec.ofNat 64 i.width.bytes
      let finish := fun first second events =>
        (⟨{ pairRegisters i s first second with pc := s.pc + 4 }, events, none⟩ : Transition State)
      if i.load then
        if s.pairSingleAccess then
          if permitted s.memory.readable address (2 * i.width.bytes) then
            finish (wordAt s.memory address i.width.bytes) (wordAt s.memory secondAddress i.width.bytes)
              [.memory .read address (bytesAt s.memory address (2 * i.width.bytes))
                (initializedAt s.memory address (2 * i.width.bytes))]
          else
            let fault := Fault.read address (2 * i.width.bytes)
            ⟨s, [.fault fault], some fault⟩
        else
          match readMemory s.memory address i.width.bytes with
          | .error fault => ⟨s, [.fault fault], some fault⟩
          | .ok (first, event) =>
              match readMemory s.memory secondAddress i.width.bytes with
              | .error fault => ⟨s, [event, .fault fault], some fault⟩
              | .ok (second, secondEvent) => finish first second [event, secondEvent]
      else
        let first := readReg s i.first
        let second := readReg s i.second
        if s.pairSingleAccess then
          if permitted s.memory.writable address (2 * i.width.bytes) then
            let memory := storeMemory (storeMemory s.memory address first i.width.bytes)
              secondAddress second i.width.bytes
            ⟨{ s with memory := memory, pc := s.pc + 4 },
              [.memory .write address (valueBytes first i.width.bytes ++ valueBytes second i.width.bytes) true], none⟩
          else
            let fault := Fault.write address (2 * i.width.bytes)
            ⟨s, [.fault fault], some fault⟩
        else
          match writeMemory s.memory address first i.width.bytes with
          | .error fault => ⟨s, [.fault fault], some fault⟩
          | .ok (memory, event) =>
              match writeMemory memory secondAddress second i.width.bytes with
              | .error fault => ⟨{ s with memory := memory }, [event, .fault fault], some fault⟩
              | .ok (memory, secondEvent) =>
                  ⟨{ s with memory := memory, pc := s.pc + 4 }, [event, secondEvent], none⟩

/-- Branch offsets are signed native BYTE displacements relative to the
branch instruction, with wrapping64-bit PC arithmetic. -/
def branchStep (taken : Bool) (displacement : Word) (s : State) : Transition State :=
  ⟨{ s with pc := if taken then s.pc + displacement else s.pc + 4 }, [], none⟩

def zeroBranch (width : Width) (nonzero : Bool) (value : Word) : Bool :=
  if nonzero then narrow value width != 0 else narrow value width == 0

def bitBranch (nonzero : Bool) (value : Word) (bit : BitVec 6) : Bool :=
  let selected := (value >>> bit.setWidth 64).setWidth 1
  if nonzero then selected != 0 else selected == 0

inductive Instruction
  | memory (instruction : MemoryInstruction)
  | pairMemory (instruction : PairMemoryInstruction)
  | nop
  | branch (displacement : Word)
  | branchConditional (predicate : Fin 16) (displacement : Word)
  | branchZero (width : Width) (nonzero : Bool) (src : Register) (displacement : Word)
  | branchBit (nonzero : Bool) (src : Register) (bit : BitVec 6) (displacement : Word)
  | mul (instruction : MulInstruction)
  | fmov (instruction : FmovInstruction)
  | fmovBank (bank : Register) (instruction : FmovInstruction)
  | reduction (op : ReductionOp) (wide : Bool)
  | arithmeticExtended (width : Width) (subtract setFlags : Bool) (dst src : RegisterRef)
      (rhs : Register) (kind : RegisterExtend) (amount : Fin 5)
  | arithmeticRegister (width : Width) (subtract setFlags : Bool) (dst src : RegisterRef)
      (rhs : Register) (kind : Fin 3) (amount : Fin width.bits)
  | arithmeticImmediate (width : Width) (subtract setFlags : Bool) (dst src : RegisterRef) (rhs : Word)
  | compare (width : Width) (lhs : Register) (rhs : CompareOperand)
      (predicate : Fin 16) (fallback : BitVec 4)
  | shift (instruction : ShiftInstruction)
  | logic (instruction : LogicInstruction)
  | keep (instruction : KeepInstruction)
  | moveImmediate (width : Width) (dst : Register) (value : Word)
  | moveRegister (width : Width) (dst src : RegisterRef)
  | extrev (instruction : ExtrevInstruction)
  | select (width : Width) (alternative : SelectElse) (dst lhs rhs : Register) (predicate : Fin 16)
  deriving DecidableEq, Repr

def step (i : Instruction) (s : State) : Transition State :=
  match i with
  | .memory instruction => memoryStep instruction s
  | .pairMemory instruction => pairMemoryStep instruction s
  | .nop => ⟨{ s with pc := s.pc + 4 }, [], none⟩
  | .branch displacement => branchStep true displacement s
  | .branchConditional predicate displacement => branchStep (condition s.flags predicate) displacement s
  | .branchZero width nonzero src displacement => branchStep (zeroBranch width nonzero (readReg s src)) displacement s
  | .branchBit nonzero src bit displacement => branchStep (bitBranch nonzero (readReg s src) bit) displacement s
  | .mul instruction => mulStep instruction s
  | .fmov instruction => fmovStep instruction s
  | .fmovBank bank instruction => fmovBankStep bank instruction s
  | .reduction op wide => reductionStep op wide s
  | .arithmeticExtended width subtract setFlags dst src rhs kind amount =>
      arithmeticExtendedStep width subtract setFlags dst src rhs kind amount s
  | .arithmeticRegister width subtract setFlags dst src rhs kind amount =>
      arithmeticRegisterStep width subtract setFlags dst src rhs kind amount s
  | .arithmeticImmediate width subtract setFlags dst src rhs => arithmeticImmediateStep width subtract setFlags dst src rhs s
  | .compare width lhs rhs predicate fallback => compareStep width lhs rhs predicate fallback s
  | .shift instruction => shiftStep instruction s
  | .logic instruction => logicStep instruction s
  | .keep instruction => keepStep instruction s
  | .moveRegister width dst src => moveRegStep width dst src s
  | .moveImmediate width dst value =>
      ⟨{ writeReg s dst (narrow value width) with pc := s.pc + 4 }, [], none⟩
  | .extrev instruction => extrevStep instruction s
  | .select width alternative dst lhs rhs predicate =>
      let value := selectValue width alternative (condition s.flags predicate) (readReg s lhs) (readReg s rhs)
      ⟨{ writeReg s dst value with pc := s.pc + 4 }, [], none⟩

def Step (i : Instruction) (before : State) (after : Transition State) : Prop :=
  step i before = after

private def register (n : Nat) : Register := ⟨n % 32, Nat.mod_lt _ (by decide)⟩

private def dataRegister (r : Register) (sp : Bool) : RegisterRef :=
  if h : r.val < 31 then .general ⟨r.val, h⟩ else if sp then .stack else .zero

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
  -- Integer pair signed-offset encodings: opc00=W, opc10=X, V=0.
  if word &&& 0x7f800000 = 0x29000000 then
    let load := (word / 2^22) % 2 == 1
    let second : Register := ⟨(word / 2^10) % 32, Nat.mod_lt _ (by decide)⟩
    if distinct : load = true → dst ≠ second then
      let width := if word / 2^31 = 1 then Width.w64 else .w32
      return .pairMemory ⟨width, load, dst, second, lhs,
        (BitVec.ofNat 7 (word / 2^15)).signExtend 64 * BitVec.ofNat 64 width.bytes, distinct⟩
    else throw "constrained-unpredictable LDP duplicate destinations"
  -- Scalar unsigned-scaled and signed-unscaled immediate memory encodings.
  -- V=0 selects GPR transfers; pre/post/register modes have distinct classes.
  let scaled := word &&& 0x3f000000 == 0x39000000
  let unscaled := word &&& 0x3f200c00 == 0x38000000
  if scaled || unscaled then
    let size := word / 2^30
    let accessWidth := match size with | 0 => MemoryWidth.byte | 1 => .half | 2 => .word | _ => .double
    let opc := (word / 2^22) % 4
    let transfer ← match opc with
      | 0 => pure (MemoryTransfer.store dst)
      | 1 => pure (.load dst none)
      | 2 => if size < 3 then pure (.load dst (some .w64)) else throw "prefetch encoding is not a scalar load/store"
      | _ => if size < 2 then pure (.load dst (some .w32)) else throw "reserved signed-load size"
    let offset := if scaled then BitVec.ofNat 64 (((word / 2^10) % 2^12) * accessWidth.bytes)
      else (BitVec.ofNat 9 (word / 2^12)).signExtend 64
    return .memory ⟨accessWidth, transfer, lhs, offset⟩
  if word = 0xd503201f then return .nop
  if word &&& 0xfc000000 = 0x14000000 then
    return .branch ((BitVec.ofNat 26 word).signExtend 64 <<< 2)
  if word &&& 0xff000010 = 0x54000000 then
    return .branchConditional ⟨word % 16, Nat.mod_lt _ (by decide)⟩
      ((BitVec.ofNat 19 (word / 2^5)).signExtend 64 <<< 2)
  if word &&& 0x7e000000 = 0x34000000 then
    return .branchZero width ((word / 2^24) % 2 == 1) dst
      ((BitVec.ofNat 19 (word / 2^5)).signExtend 64 <<< 2)
  if word &&& 0x7e000000 = 0x36000000 then
    let bit := BitVec.ofNat 6 ((word / 2^31) * 32 + (word / 2^19) % 32)
    return .branchBit ((word / 2^24) % 2 == 1) dst bit
      ((BitVec.ofNat 14 (word / 2^5)).signExtend 64 <<< 2)
  let conditionalCompare := word &&& 0x7fe00c10
  if conditionalCompare = 0x7a400000 ∨ conditionalCompare = 0x7a400800 then
    let operand := if conditionalCompare = 0x7a400800 then
        CompareOperand.immediate (BitVec.ofNat 5 (word / 2^16))
      else .register rhs
    return .compare width lhs operand ⟨(word / 2^12) % 16, Nat.mod_lt _ (by decide)⟩ (BitVec.ofNat 4 word)
  let reduction := word &&& 0xbffffc00
  if reduction = 0x0e205800 ∨ reduction = 0x2e303800 then
    if dst.val ≠ 0 ∨ lhs.val ≠ 0 then throw "byte reduction vector register is not V0"
    return .reduction (if reduction = 0x0e205800 then .count else .unsignedSum) ((word / 2^30) % 2 == 1)
  -- FMOV's floating register field selects one of all32 architectural cells.
  let transfer := word &&& 0xfffffc00
  if transfer = 0x9e670000 ∨ transfer = 0x1e270000 then
    return .fmovBank dst (.toVector (if transfer = 0x9e670000 then .w64 else .w32) lhs)
  if transfer = 0x9e660000 ∨ transfer = 0x1e260000 then
    return .fmovBank lhs (.fromVector (if transfer = 0x9e660000 then .w64 else .w32) dst)
  -- MOV register is ORR with Rn=ZR and no shift. MOV involving SP is
  -- the ADD-immediate-zero alias, whose field31 denotes SP rather than ZR.
  if word &&& 0x7fe0ffe0 = 0x2a0003e0 then
    return .moveRegister width (dataRegister dst false) (dataRegister rhs false)
  if word &&& 0x7ffffc00 = 0x11000000 ∧ (dst.val = 31 ∨ lhs.val = 31) then
    return .moveRegister width (dataRegister dst true) (dataRegister lhs true)
  if word &&& 0x1f800000 = 0x11000000 then
    let setFlags := (word / 2^29) % 2 == 1
    let subtract := (word / 2^30) % 2 == 1
    let shift := if (word / 2^22) % 2 = 1 then 12 else 0
    return .arithmeticImmediate width subtract setFlags (dataRegister dst (!setFlags))
      (dataRegister lhs true) (BitVec.ofNat 64 ((word / 2^10) % 2^12) <<< shift)
  if word &&& 0x7f800000 = 0x72800000 then
    let column := (word / 2^21) % 4
    if h : column < width.bits / 16 then
      return .keep ⟨width, ⟨column, h⟩, BitVec.ofNat 16 (word / 2^5), dst⟩
    else throw "reserved MOVK halfword column"
  if word &&& 0x7f800000 = 0x12800000 ∨ word &&& 0x7f800000 = 0x52800000 then
    let column := (word / 2^21) % 4
    if column ≥ width.bits / 16 then throw "reserved move-wide halfword column"
    let field := BitVec.ofNat 64 ((word / 2^5) % 2^16) <<< (16 * column)
    let value := if (word / 2^30) % 2 = 0 then ~~~field else field
    return .moveImmediate width dst value
  let shiftKind := match (word / 2^22) % 4 with
    | 0 => ShiftKind.lsl | 1 => .lsr | 2 => .asr | _ => .ror
  let amount := (word / 2^10) % 64
  if word &&& 0x7fe0f000 = 0x1ac02000 then
    let kind := match (word / 2^10) % 4 with
      | 0 => ShiftKind.lsl | 1 => .lsr | 2 => .asr | _ => .ror
    return .shift (.register width kind dst lhs rhs)
  if word &&& 0x7f2003e0 = 0x2a2003e0 then
    if h : amount < width.bits then return .shift (.invert width shiftKind ⟨amount, h⟩ dst rhs)
    else throw "reserved MVN immediate"
  if word &&& 0x1f000000 = 0x0a000000 then
    let opcode := (word / 2^29) % 4
    let invert := (word / 2^21) % 2 == 1
    let op ← if opcode = 0 then pure (LogicOp.conjunction invert false)
      else if opcode = 1 then pure (.disjunction invert)
      else if opcode = 2 ∧ !invert then pure .exclusive
      else if opcode = 3 then pure (.conjunction invert true)
      else throw "unrecognized logical register opcode"
    if h : amount < width.bits then
      return .logic ⟨width, op, shiftKind, ⟨amount, h⟩, dst, lhs, rhs⟩
    else throw "reserved logical register shift immediate"
  if word &&& 0x7f2003e0 = 0x4b0003e0 then
    let kind := (word / 2^22) % 4
    if h : kind < 3 then
      if k : amount < width.bits then return .shift (.negate width ⟨kind, h⟩ ⟨amount, k⟩ dst rhs)
      else throw "reserved NEG immediate"
    else throw "reserved NEG shift kind"
  if word &&& 0x1fe00000 = 0x0b200000 then
    let amount := (word / 2^10) % 8
    if h : amount < 5 then
      let kind := match (word / 2^13) % 8 with
        | 0 => RegisterExtend.uxtb | 1 => .uxth | 2 => .uxtw | 3 => .uxtx
        | 4 => .sxtb | 5 => .sxth | 6 => .sxtw | _ => .sxtx
      let setFlags := (word / 2^29) % 2 == 1
      return .arithmeticExtended width ((word / 2^30) % 2 == 1) setFlags
        (dataRegister dst (!setFlags)) (dataRegister lhs true) rhs kind ⟨amount, h⟩
    else throw "reserved ADD/SUB register extend amount"
  if word &&& 0x1f200000 = 0x0b000000 then
    let kind := (word / 2^22) % 4
    if h : kind < 3 then
      if k : amount < width.bits then
        return .arithmeticRegister width ((word / 2^30) % 2 == 1) ((word / 2^29) % 2 == 1)
          (dataRegister dst false) (dataRegister lhs false) rhs ⟨kind, h⟩ ⟨amount, k⟩
      else throw "reserved ADD/SUB register shift immediate"
    else throw "reserved ADD/SUB register shift kind"
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
  -- Immediate shift aliases of UBFM/SBFM. Other bitfield encodings are
  -- decoded by their own family, not silently reduced to a shift.
  let unsignedBits := word &&& 0xffc00000 = 0x53000000 ∨ word &&& 0xffc00000 = 0xd3400000
  let signedBits := word &&& 0xffc00000 = 0x13000000 ∨ word &&& 0xffc00000 = 0x93400000
  if unsignedBits ∨ signedBits then
    let rotate := (word / 2^16) % 64
    let last := (word / 2^10) % 64
    if r : rotate < width.bits then
      if last + 1 = width.bits then
        return .shift (.immediate width (if unsignedBits then .lsr else .asr) ⟨rotate, r⟩ dst lhs)
      if unsignedBits ∧ last + 1 = rotate then
        let shift := width.bits - rotate
        if h : shift < width.bits then return .shift (.immediate width .lsl ⟨shift, h⟩ dst lhs)
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
