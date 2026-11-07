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
operands cannot be encoded. An active REX.W overrides the operand-size prefix. -/
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

inductive BmiShift | left | right | arithmetic | rotate
  deriving DecidableEq, Repr

inductive ShiftCount
  | register (reg : Register)
  | immediate (value : BitVec 8)
  deriving DecidableEq, Repr

def countValue (s : State) : ShiftCount → Word
  | .register r => s.gpr r | .immediate value => value.setWidth 64

/-- MULX returns the exact unsigned product as two operand-sized halves.
The 32-bit form fits in 64 bits; the 64-bit form uses 128 bits. No flags change. -/
def mulxParts (width : BzhiWidth) (left right : Word) : Word × Word :=
  match width with
  | .w32 =>
      let product := (left.setWidth 32).setWidth 64 * (right.setWidth 32).setWidth 64
      ((product.setWidth 32).setWidth 64, ((product >>> 32).setWidth 32).setWidth 64)
  | .w64 =>
      let product := left.setWidth 128 * right.setWidth 128
      (product.setWidth 64, (product >>> 64).setWidth 64)

/-- Read the explicit operand and the incoming implicit RDX before either
write. When the two destinations alias, the high half is the final value. -/
def mulxStep (width : BzhiWidth) (high low : Register) (source : Source)
    (nextPc : Word) (s : State) : Transition State :=
  match readSource s source width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (right, reads) =>
      let parts := mulxParts width (s.gpr 2) right
      ⟨{ s with gpr := fun r => if r = high then parts.2 else if r = low then parts.1 else s.gpr r, pc := nextPc }, reads, none⟩

/-- BMI2 shifts read width-sized operands, mask counts to five/six bits,
and leave every flag unchanged. Rotate selects a window in a doubled source. -/
def bmiShiftValue (width : BzhiWidth) (kind : BmiShift) (value amount : Word) : Word :=
  let source := value.setWidth width.bits
  let count := amount &&& BitVec.ofNat 64 (width.bits - 1)
  match kind with
  | .left => (source <<< count).setWidth 64
  | .right => (source >>> count).setWidth 64
  | .arithmetic => (source.sshiftRight' count).setWidth 64
  | .rotate =>
      let pair := (source.setWidth 128 <<< width.bits) ||| source.setWidth 128
      ((pair >>> count.setWidth 128).setWidth width.bits).setWidth 64

def bmiShiftStep (width : BzhiWidth) (kind : BmiShift) (dst : Register) (source : Source)
    (count : ShiftCount) (nextPc : Word) (s : State) : Transition State :=
  match readSource s source width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      let result := bmiShiftValue width kind value (countValue s count)
      ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), pc := nextPc }, events, none⟩

/-- Reverse only the architectural operand bytes, stated by a byte-list
permutation rather than the implementation's mask-and-shift ladder. -/
def reverseBytes (value : Word) (bytes : Nat) : Word :=
  littleEndian 64 (valueBytes value bytes).reverse

def writeValue (width : CmovWidth) (old value : Word) : Word :=
  match width with
  | .w16 => (old &&& 0xffffffffffff0000) ||| (value &&& 0xffff)
  | .w32 => (value.setWidth 32).setWidth 64
  | .w64 => value

def swapStep (width : BzhiWidth) (dst : Register) (nextPc : Word) (s : State) : Transition State :=
  let value := reverseBytes (s.gpr dst) width.bytes
  ⟨{ s with gpr := fun r => if r = dst then value else s.gpr r, pc := nextPc }, [], none⟩

def movbeLoadStep (width : CmovWidth) (dst : Register) (address nextPc : Word) (s : State) : Transition State :=
  match readSource s (.memory address) width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (source, events) =>
      let value := writeValue width (s.gpr dst) (reverseBytes source width.bytes)
      ⟨{ s with gpr := fun r => if r = dst then value else s.gpr r, pc := nextPc }, events, none⟩

def movbeStoreStep (width : CmovWidth) (src : Register) (address nextPc : Word) (s : State) : Transition State :=
  let value := reverseBytes (s.gpr src) width.bytes
  match writeMemory s.memory address value width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (memory, event) => ⟨{ s with memory := memory, pc := nextPc }, [event], none⟩

/-- Commit a PUSH transfer only after its read (if any) and whole-width
write permission check. Memory faults preserve every architectural component;
ordered reads preceding a write fault remain observable events. -/
def pushTransfer (width : StackWidth) (value : Word) (reads : List Event)
    (nextPc : Word) (s : State) : Transition State :=
  let address := s.gpr 4 - BitVec.ofNat 64 width.bytes
  match writeMemory s.memory address value width.bytes with
  | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
  | .ok (memory, event) =>
      ⟨{ s with gpr := (fun r => if r = 4 then address else s.gpr r), memory := memory, pc := nextPc },
        reads ++ [event], none⟩

/-- Scalar integer sizes, including byte-register lanes absent from CMOV. -/
inductive ScalarWidth | w8 | w16 | w32 | w64
  deriving DecidableEq, Repr

def ScalarWidth.bytes : ScalarWidth → Nat
  | .w8 => 1 | .w16 => 2 | .w32 => 4 | .w64 => 8

def ScalarWidth.bits (width : ScalarWidth) : Nat := width.bytes * 8

/-- PF is even parity of the low byte, stated as a bit walk rather than the
implementation's four-bit lookup table. -/
def evenParity (value : Word) : Bool :=
  !((List.range 8).foldl (fun parity bit => parity != value.getLsbD bit) false)

/-- AF is carry/borrow across the low nibble. Widening to five bits retains
both a right nibble of15 plus incoming carry and the outgoing addition bit. -/
def auxiliaryCarry (subtract carry : Bool) (left right : Word) : Bool :=
  let a := (left.setWidth 4).setWidth 5
  let b := (right.setWidth 4).setWidth 5 + (if carry then (1 : BitVec 5) else 0)
  if subtract then BitVec.ult a b else (a + b).getLsbD 4

inductive ArithmeticKind | add | adc | sub | sbb | compare
  deriving DecidableEq, Repr

def ArithmeticKind.subtract : ArithmeticKind → Bool
  | .sub | .sbb | .compare => true | _ => false

def ArithmeticKind.carry (kind : ArithmeticKind) (flags : Word) : Bool :=
  (kind == .adc || kind == .sbb) && flags.getLsbD 0

/-- Extra unsigned precision supplies carry/borrow; independent signed
precision supplies overflow. Inputs are narrowed before either widening. -/
def arithmeticValue (width : ScalarWidth) (subtract carry : Bool) (left right : Word) : Word :=
  let a := (left.setWidth width.bits).setWidth 128
  let b := (right.setWidth width.bits).setWidth 128
  let incoming : BitVec 128 := if carry then 1 else 0
  let result := if subtract then a - b - incoming else a + b + incoming
  (result.setWidth width.bits).setWidth 64

def arithmeticFlags (width : ScalarWidth) (subtract carry : Bool) (left right old : Word) : Word :=
  let a := left.setWidth width.bits
  let b := right.setWidth width.bits
  let incoming : BitVec 128 := if carry then 1 else 0
  let unsignedResult := if subtract then a.setWidth 128 - b.setWidth 128 - incoming
    else a.setWidth 128 + b.setWidth 128 + incoming
  let signedResult := if subtract then a.signExtend 128 - b.signExtend 128 - incoming
    else a.signExtend 128 + b.signExtend 128 + incoming
  let result := unsignedResult.setWidth width.bits
  let cf := if subtract then BitVec.ult (a.setWidth 128) (b.setWidth 128 + incoming)
    else unsignedResult.getLsbD width.bits
  let pf := evenParity (result.setWidth 64)
  let af := auxiliaryCarry subtract carry left right
  let zf := result.setWidth 64 == (0 : Word)
  let sf := result.getLsbD (width.bits - 1)
  let of := signedResult != result.signExtend 128
  (old &&& 0xfffffffffffff72a) ||| (if cf then 1 else 0) ||| (if pf then 4 else 0) |||
    (if af then 16 else 0) ||| (if zf then 64 else 0) ||| (if sf then 128 else 0) ||| (if of then 2048 else 0)

inductive LogicKind | and | or | xor | test
  deriving DecidableEq, Repr

def logicalValue (width : ScalarWidth) (kind : LogicKind) (left right : Reference.Word) : Reference.Word :=
  let a := left.setWidth width.bits
  let b := right.setWidth width.bits
  ((match kind with | .and | .test => a &&& b | .or => a ||| b | .xor => a ^^^ b).setWidth 64)

def logicalFlags (width : ScalarWidth) (kind : LogicKind) (left right old : Reference.Word) : Reference.Word :=
  let result := logicalValue width kind left right
  (old &&& 0xfffffffffffff73a) ||| (if evenParity result then 4 else 0) |||
    (if result = 0 then 64 else 0) ||| (if result.getLsbD (width.bits - 1) then 128 else 0)

/-- Legacy shifts mask the count before use; rotates additionally reduce the
result count modulo operand size, while flag rules use the masked count. -/
inductive LegacyShift | left | right | arithmetic | rotateLeft
  deriving DecidableEq, Repr

def legacyCount (width : ScalarWidth) (count : Word) : Word :=
  count &&& (if width = .w64 then 63 else 31)

def legacyShiftValue (width : ScalarWidth) (kind : LegacyShift) (value count : Word) : Word :=
  let a := (value.setWidth width.bits).setWidth 64
  let n := legacyCount width count
  let rotated := n &&& BitVec.ofNat 64 (width.bits - 1)
  let shifted := match kind with
    | .left => a <<< n
    | .right => a >>> n
    | .arithmetic => ((value.setWidth width.bits).signExtend 64).sshiftRight' n
    | .rotateLeft => (a <<< rotated) ||| (a >>> (BitVec.ofNat 64 width.bits - rotated))
  (shifted.setWidth width.bits).setWidth 64

/-- Flags unaffected by the ISA are preserved. AF, OF at counts beyond one,
and logical-shift CF at counts at least the width use stable representatives;
legacyDefinedFlags below removes those bits from the architectural relation. -/
def legacyShiftFlags (width : ScalarWidth) (kind : LegacyShift) (value count old : Word) : Word :=
  let n := (legacyCount width count).toNat
  let bits := width.bits
  let a := (value.setWidth bits).setWidth 64
  let result := legacyShiftValue width kind value count
  let sign := result.getLsbD (bits - 1)
  let cf := match kind with
    | .left => if n ≤ bits then a.getLsbD (bits - n) else false
    | .right => if n ≤ bits then a.getLsbD (n - 1) else false
    | .arithmetic => if n ≤ bits then a.getLsbD (n - 1) else a.getLsbD (bits - 1)
    | .rotateLeft => result.getLsbD 0
  let of := match kind with
    | .left | .rotateLeft => sign != cf
    | .right => a.getLsbD (bits - 1)
    | .arithmetic => false
  if n = 0 then old else
    let carryFlags := setFlag (setFlag old 0 cf) 11 (if n = 1 then of else old.getLsbD 11)
    if kind = .rotateLeft then carryFlags else
      setFlag (setFlag (setFlag carryFlags 2 (evenParity result)) 6 (result == 0)) 7 sign

/-- ROR selects the low operand-width bits of a shifted double-width pair.
Unlike the implementation's two-shift OR, this uses one concatenated source. -/
def rotateRightValue (width : ScalarWidth) (value count : Word) : Word :=
  let source := (value.setWidth width.bits).setWidth 128
  let pair := (source <<< width.bits) ||| source
  let amount := (legacyCount width count &&& BitVec.ofNat 64 (width.bits - 1)).setWidth 128
  ((pair >>> amount).setWidth width.bits).setWidth 64

def rotateRightFlags (width : ScalarWidth) (value count old : Word) : Word :=
  let n := (legacyCount width count).toNat
  let result := rotateRightValue width value count
  let cf := result.getLsbD (width.bits - 1)
  let of := cf != result.getLsbD (width.bits - 2)
  if n = 0 then old else setFlag (setFlag old 0 cf) 11 (if n = 1 then of else old.getLsbD 11)

def legacyDefinedFlags (width : ScalarWidth) (kind : LegacyShift) (count : Word) : Word :=
  let n := (legacyCount width count).toNat
  if n = 0 then 0xffffffffffffffff else
    let mask : Word := if kind = .rotateLeft then 0xffffffffffffffff else 0xffffffffffffffef
    let mask := if n = 1 then mask else mask &&& 0xfffffffffffff7ff
    if (kind = .left ∨ kind = .right) ∧ width.bits ≤ n then mask &&& 0xfffffffffffffffe else mask

inductive UnaryKind | inc | dec | neg | not
  deriving DecidableEq, Repr

def unaryValue (width : ScalarWidth) (kind : UnaryKind) (source : Reference.Word) : Reference.Word :=
  let value := source.setWidth width.bits
  ((match kind with | .inc => value + 1 | .dec => value - 1 | .neg => -value | .not => ~~~value).setWidth 64)

def unaryFlags (width : ScalarWidth) (kind : UnaryKind) (value old : Reference.Word) : Reference.Word :=
  match kind with
  | .inc => setFlag (arithmeticFlags width false false value 1 old) 0 (old.getLsbD 0)
  | .dec => setFlag (arithmeticFlags width true false value 1 old) 0 (old.getLsbD 0)
  | .neg => arithmeticFlags width true false 0 value old
  | .not => old

private def populationLane (x : BitVec 64) (i : Nat) : BitVec 8 :=
  ((x >>> (8 * i)) &&& 0xff).setWidth 8

/-- Independent per-byte population count: an explicit eight-bit walk, sharing no
constant with the generated SWAR reduction. -/
private def populationByte (b : BitVec 8) : BitVec 8 :=
  (b.extractLsb' 0 1).setWidth 8 + (b.extractLsb' 1 1).setWidth 8 +
  (b.extractLsb' 2 1).setWidth 8 + (b.extractLsb' 3 1).setWidth 8 +
  (b.extractLsb' 4 1).setWidth 8 + (b.extractLsb' 5 1).setWidth 8 +
  (b.extractLsb' 6 1).setWidth 8 + (b.extractLsb' 7 1).setWidth 8

/-- Independent statement of the 64-bit population count: the sum of the eight
byte lanes' bit walks, each lane narrowed before counting. -/
def populationCount (x : BitVec 64) : BitVec 64 :=
  (populationByte (populationLane x 0)).setWidth 64 + (populationByte (populationLane x 1)).setWidth 64 +
  (populationByte (populationLane x 2)).setWidth 64 + (populationByte (populationLane x 3)).setWidth 64 +
  (populationByte (populationLane x 4)).setWidth 64 + (populationByte (populationLane x 5)).setWidth 64 +
  (populationByte (populationLane x 6)).setWidth 64 + (populationByte (populationLane x 7)).setWidth 64


def popcountValue (width : CmovWidth) (source : Reference.Word) : Reference.Word :=
  populationCount ((source.setWidth (width.bytes * 8)).setWidth 64)

def popcountFlags (width : CmovWidth) (source old : Reference.Word) : Reference.Word :=
  (old &&& 0xfffffffffffff72a) ||| (if source.setWidth (width.bytes * 8) = 0 then 64 else 0)

inductive RegisterSlice
  | low (reg : Register)
  | high (reg : Fin 4)
  deriving DecidableEq, Repr

def RegisterSlice.reg : RegisterSlice → Register
  | .low reg => reg
  | .high reg => ⟨reg.val, by omega⟩

def RegisterSlice.shift (slice : RegisterSlice) (width : ScalarWidth) : Nat :=
  match slice with
  | .high _ => if width = .w8 then 8 else 0
  | .low _ => 0

inductive ScalarSource
  | register (slice : RegisterSlice)
  | memory (address : Word)
  | immediate (value : Word)
  deriving DecidableEq, Repr

inductive ScalarDestination
  | register (slice : RegisterSlice)
  | memory (address : Word)
  deriving DecidableEq, Repr

def scalarRegisterValue (s : State) (width : ScalarWidth) (slice : RegisterSlice) : Word :=
  (((s.gpr slice.reg) >>> slice.shift width).setWidth width.bits).setWidth 64

def scalarWriteValue (old value : Word) (width : ScalarWidth) (slice : RegisterSlice) : Word :=
  if width = .w32 then (value.setWidth 32).setWidth 64
  else
    let shift := slice.shift width
    let mask := BitVec.ofNat 64 (2^width.bits - 1) <<< shift
    (old &&& ~~~mask) ||| (((value.setWidth width.bits).setWidth 64) <<< shift)

def scalarRead (s : State) (width : ScalarWidth) : ScalarSource → Except Fault (Word × List Event)
  | .register slice => .ok (scalarRegisterValue s width slice, [])
  | .immediate value => .ok (value, [])
  | .memory address => readSource s (.memory address) width.bytes

def scalarWrite (s : State) (width : ScalarWidth) (destination : ScalarDestination) (value : Word) :
    Except Fault (State × List Event) :=
  match destination with
  | .register slice =>
      .ok ({ s with gpr := fun r => if r = slice.reg then
        scalarWriteValue (s.gpr r) value width slice else s.gpr r }, [])
  | .memory address =>
      match writeMemory s.memory address value width.bytes with
      | .error fault => .error fault
      | .ok (memory, event) => .ok ({ s with memory := memory }, [event])

def ScalarDestination.source : ScalarDestination → ScalarSource
  | .register slice => .register slice | .memory address => .memory address

/-- ADD/ADC/SUB/SBB/CMP replace all six arithmetic status flags, preserving
all other RFLAGS bits. A write fault commits neither data nor flags. -/
def arithmeticStep (width : ScalarWidth) (kind : ArithmeticKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Word) (s : State) : Transition State :=
  match scalarRead s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (left, firstReads) =>
      match scalarRead s width src with
      | .error fault => ⟨s, firstReads ++ [.fault fault], some fault⟩
      | .ok (right, secondReads) =>
          let carry := kind.carry s.rflags
          let flags := arithmeticFlags width kind.subtract carry left right s.rflags
          let reads := firstReads ++ secondReads
          if kind = .compare then ⟨{ s with rflags := flags, pc := nextPc }, reads, none⟩
          else
            match scalarWrite s width dst (arithmeticValue width kind.subtract carry left right) with
            | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
            | .ok (result, writes) => ⟨{ result with rflags := flags, pc := nextPc }, reads ++ writes, none⟩

/-- Ordinary MOV reads its source before changing an aliased destination or
address register. Byte/word writes preserve other bits, E writes zero-extend,
and every flag and vector is preserved, including on a memory fault. -/
def moveStep (width : ScalarWidth) (dst : ScalarDestination) (src : ScalarSource)
    (nextPc : Word) (s : State) : Transition State :=
  match scalarRead s width src with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      match scalarWrite s width dst value with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) => ⟨{ result with pc := nextPc }, reads ++ writes, none⟩


def logicalStep (width : ScalarWidth) (kind : LogicKind) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Reference.Word) (s : State) : Transition State :=
  match scalarRead s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (left, firstReads) =>
      match scalarRead s width src with
      | .error fault => ⟨s, firstReads ++ [.fault fault], some fault⟩
      | .ok (right, secondReads) =>
          let flags := logicalFlags width kind left right s.rflags
          let reads := firstReads ++ secondReads
          if kind = .test then ⟨{ s with rflags := flags, pc := nextPc }, reads, none⟩
          else
            match scalarWrite s width dst (logicalValue width kind left right) with
            | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
            | .ok (result, writes) => ⟨{ result with rflags := flags, pc := nextPc }, reads ++ writes, none⟩


def unaryStep (width : ScalarWidth) (kind : UnaryKind) (dst : ScalarDestination)
    (nextPc : Word) (s : State) : Transition State :=
  match scalarRead s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      match scalarWrite s width dst (unaryValue width kind value) with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) =>
          ⟨{ result with rflags := unaryFlags width kind value s.rflags, pc := nextPc }, reads ++ writes, none⟩

/-- Register XCHG samples both lanes before either write. Sequential lane
merges retain both changes when AL/AH (or another byte pair) share one GPR. -/
def exchangeStep (width : ScalarWidth) (left right : RegisterSlice) (nextPc : Word)
    (s : State) : Transition State :=
  let a := scalarRegisterValue s width left
  let b := scalarRegisterValue s width right
  let first := { s with gpr := fun r => if r = left.reg then scalarWriteValue (s.gpr r) b width left else s.gpr r }
  let second := { first with gpr := fun r => if r = right.reg then scalarWriteValue (first.gpr r) a width right else first.gpr r }
  ⟨{ second with pc := nextPc }, [], none⟩

/-- A legacy memory operand is a read-modify-write access even at count zero.
Read or write faults commit neither flags nor data; a successful read precedes
a write fault. Count/source aliases are sampled from the incoming state. -/
def legacyShiftStep (width : ScalarWidth) (kind : LegacyShift) (dst : ScalarDestination)
    (count nextPc : Word) (s : State) : Transition State :=
  match scalarRead s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      match scalarWrite s width dst (legacyShiftValue width kind value count) with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) =>
          ⟨{ result with rflags := legacyShiftFlags width kind value count s.rflags, pc := nextPc }, reads ++ writes, none⟩

/-- Register or memory ROR, retaining the completed read on a write fault. -/
def rotateRightStep (width : ScalarWidth) (dst : ScalarDestination) (count nextPc : Word)
    (s : State) : Transition State :=
  match scalarRead s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      match scalarWrite s width dst (rotateRightValue width value count) with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) =>
          ⟨{ result with rflags := rotateRightFlags width value count s.rflags, pc := nextPc }, reads ++ writes, none⟩

/-- Low-width product bits are independent of signed/unsigned interpretation.
The signed magnitude product below separately decides representability. -/
def multiplyValue (width : CmovWidth) (left right : Word) : Word :=
  ((left.setWidth width.bits) * (right.setWidth width.bits)).setWidth 64

def multiplyMagnitude (width : CmovWidth) (value : Word) : Word :=
  let narrowed := value.setWidth width.bits
  (if narrowed.getLsbD (width.bits - 1) then -narrowed else narrowed).setWidth 64

def multiplyMixedSign (width : CmovWidth) (left right : Word) : Bool :=
  left.getLsbD (width.bits - 1) != right.getLsbD (width.bits - 1)

/-- A negative signed product may have magnitude2^(n-1), while a nonnegative
one is bounded by2^(n-1)-1. Nat multiplication retains all128 product bits. -/
def multiplyOverflow (width : CmovWidth) (left right : Word) : Bool :=
  let limit := 2^(width.bits - 1) - (if multiplyMixedSign width left right then 0 else 1)
  decide (limit < (multiplyMagnitude width left).toNat * (multiplyMagnitude width right).toNat)

def multiplyFlags (width : CmovWidth) (left right old : Word) : Word :=
  let overflow := multiplyOverflow width left right
  setFlag (setFlag old 0 overflow) 11 overflow

/-- The immediate container holds encoded operand bits. 6B sign-extends its
byte on decoding;69 supplies16 or32 bits. REX.W still encodes only imm32. -/
def multiplyImmediate (width : CmovWidth) (raw : BitVec 32) : Word :=
  (raw.setWidth (if width = .w16 then 16 else 32)).signExtend 64

def multiplyStep (width : CmovWidth) (dst : Register) (source : Source)
    (immediate : Option (BitVec 32)) (nextPc : Word) (s : State) : Transition State :=
  match readSource s source width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      let operands := match immediate with
        | none => (s.gpr dst, value)
        | some raw => (value, multiplyImmediate width raw)
      let result := writeValue width (s.gpr dst) (multiplyValue width operands.1 operands.2)
      ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), rflags := multiplyFlags width operands.1 operands.2 s.rflags, pc := nextPc }, events, none⟩

/-- Widen the operand from its access width, independently of generated masks. -/
def extendValue (sourceWidth : ScalarWidth) (signed : Bool) (source : Word) : Word :=
  if signed then (source.setWidth sourceWidth.bits).signExtend 64
  else (source.setWidth sourceWidth.bits).setWidth 64

/-- DIV's dividend is AX at byte width and the complete DX:AX/EDX:EAX/
RDX:RAX pair otherwise. Natural numbers avoid truncating the 128-bit case. -/
def divideDividend (width : ScalarWidth) (s : State) : Nat :=
  if width = .w8 then (s.gpr 0).toNat % 65536
  else (s.gpr 2).toNat % (2 ^ width.bits) * (2 ^ width.bits) +
    (s.gpr 0).toNat % (2 ^ width.bits)

/-- Both zero divisor and an unrepresentable quotient raise #DE before any
register/flag/PC write. A completed memory operand read remains observable. -/
def divideStep (width : ScalarWidth) (source : ScalarSource) (nextPc : Word)
    (s : State) : Transition State :=
  match scalarRead s width source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (operand, reads) =>
      let divisor := operand.toNat % (2 ^ width.bits)
      let dividend := divideDividend width s
      let quotient := dividend / divisor
      if divisor = 0 ∨ 2 ^ width.bits ≤ quotient then
        ⟨s, reads ++ [.fault .divide], some .divide⟩
      else
        let remainder := dividend % divisor
        if width = .w8 then
          let result := scalarWriteValue (s.gpr 0) (BitVec.ofNat 64 (256 * remainder + quotient)) .w16 (.low 0)
          ⟨{ s with gpr := (fun r => if r = 0 then result else s.gpr r), pc := nextPc }, reads, none⟩
        else
          let low := scalarWriteValue (s.gpr 0) (BitVec.ofNat 64 quotient) width (.low 0)
          let high := scalarWriteValue (s.gpr 2) (BitVec.ofNat 64 remainder) width (.low 2)
          ⟨{ s with gpr := (fun r => if r = 0 then low else if r = 2 then high else s.gpr r), pc := nextPc }, reads, none⟩

/-- CWD/CDQ/CQO take the upper half of a signed double-width accumulator.
The low accumulator and all flags are preserved. -/
def signHighValue (width : CmovWidth) (source : Word) : Word :=
  if (source.setWidth width.bits).msb then BitVec.ofNat 64 (2 ^ width.bits - 1) else 0

/-- One architectural instruction with its decoded fall-through address.
Effective-address decoding supplies the memory source address; reads remain
part of this step, so a false-condition CMOV cannot suppress an access fault. -/
inductive Instruction
  | mulx (width : BzhiWidth) (high low : Register) (source : Source) (nextPc : Word)
  | multiply (width : CmovWidth) (dst : Register) (source : Source) (immediate : Option (BitVec 32)) (nextPc : Word)
  | rotateRight (width : ScalarWidth) (dst : ScalarDestination) (count nextPc : Word)
  | exchange (width : ScalarWidth) (left right : RegisterSlice) (nextPc : Word)
  | legacyShift (width : ScalarWidth) (kind : LegacyShift) (dst : ScalarDestination) (count nextPc : Word)
  | lea (width : CmovWidth) (dst : Register) (address nextPc : Word)
  | divide (width : ScalarWidth) (source : ScalarSource) (nextPc : Word)
  | signHigh (width : CmovWidth) (nextPc : Word)
  | extend (sourceWidth targetWidth : ScalarWidth) (signed : Bool) (dst : Register) (source : ScalarSource) (nextPc : Word)
  | popcount (width : CmovWidth) (dst : Register) (source : Source) (nextPc : Word)
  | unary (width : ScalarWidth) (kind : UnaryKind) (dst : ScalarDestination) (nextPc : Word)
  | logic (width : ScalarWidth) (kind : LogicKind) (dst : ScalarDestination) (src : ScalarSource) (nextPc : Word)
  | nop (nextPc : Word)
  | branch (condition : Option (Fin 16)) (target nextPc : Word)
  | setcc (condition : Fin 16) (dst : ScalarDestination) (nextPc : Word)
  | arithmetic (width : ScalarWidth) (kind : ArithmeticKind) (dst : ScalarDestination)
      (src : ScalarSource) (nextPc : Word)
  | move (width : ScalarWidth) (dst : ScalarDestination) (src : ScalarSource) (nextPc : Word)
  | push (width : StackWidth) (src : Register) (nextPc : Word)
  | pushImmediate (width : StackWidth) (value nextPc : Word)
  | pushMemory (width : StackWidth) (address nextPc : Word)
  | popMemory (width : StackWidth) (address nextPc : Word)
  | pop (width : StackWidth) (dst : Register) (nextPc : Word)
  | cmov (width : CmovWidth) (cc : Fin 16) (dst : Register)
      (source : Source) (nextPc : Word)
  | andn (width : BzhiWidth) (dst first : Register) (second : Source) (nextPc : Word)
  | byteSwap (width : BzhiWidth) (dst : Register) (nextPc : Word)
  | movbeLoad (width : CmovWidth) (dst : Register) (address nextPc : Word)
  | movbeStore (width : CmovWidth) (src : Register) (address nextPc : Word)
  | bmiShift (width : BzhiWidth) (kind : BmiShift) (dst : Register) (source : Source)
      (count : ShiftCount) (nextPc : Word)
  | bzhi (width : BzhiWidth) (dst : Register) (source : Source)
      (count : Register) (nextPc : Word)
  | bt (width : CmovWidth) (source : Source) (index : BitIndex) (nextPc : Word)
  deriving DecidableEq, Repr

/-- The encoded instruction's fall-through, independently of its chosen
successor. Path certificates use this to check the consumed byte extent. -/
def Instruction.fallthrough : Instruction → Word
  | .mulx _ _ _ _ next | .multiply _ _ _ _ next | .rotateRight _ _ _ next | .exchange _ _ _ next | .legacyShift _ _ _ _ next | .lea _ _ _ next | .divide _ _ next | .signHigh _ next | .extend _ _ _ _ _ next | .popcount _ _ _ next | .unary _ _ _ next | .logic _ _ _ _ next | .nop next
  | .branch _ _ next | .setcc _ _ next | .arithmetic _ _ _ _ next
  | .move _ _ _ next | .push _ _ next | .pushImmediate _ _ next
  | .pushMemory _ _ next | .popMemory _ _ next | .pop _ _ next
  | .cmov _ _ _ _ next | .andn _ _ _ _ next | .byteSwap _ _ next
  | .movbeLoad _ _ _ next | .movbeStore _ _ _ next
  | .bmiShift _ _ _ _ _ next | .bzhi _ _ _ _ next | .bt _ _ _ next => next

def step (instruction : Instruction) (s : State) : Transition State :=
  match instruction with
  | .mulx width high low source nextPc => mulxStep width high low source nextPc s
  | .multiply width dst source immediate nextPc => multiplyStep width dst source immediate nextPc s
  | .rotateRight width dst count nextPc => rotateRightStep width dst count nextPc s
  | .exchange width left right nextPc => exchangeStep width left right nextPc s
  | .legacyShift width kind dst count nextPc => legacyShiftStep width kind dst count nextPc s
  | .lea width dst address nextPc =>
      let result := writeValue width (s.gpr dst) address
      ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), pc := nextPc }, [], none⟩
  | .divide width source nextPc => divideStep width source nextPc s
  | .signHigh width nextPc =>
      let result := writeValue width (s.gpr 2) (signHighValue width (s.gpr 0))
      ⟨{ s with gpr := (fun r => if r = 2 then result else s.gpr r), pc := nextPc }, [], none⟩
  | .extend sourceWidth targetWidth signed dst source nextPc =>
      match scalarRead s sourceWidth source with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          let result := scalarWriteValue (s.gpr dst) (extendValue sourceWidth signed value) targetWidth (.low dst)
          ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), pc := nextPc }, events, none⟩
  | .popcount width dst source nextPc =>
      match readSource s source width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          let result := cmovValue width true (s.gpr dst) (popcountValue width value)
          ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), rflags := popcountFlags width value s.rflags, pc := nextPc }, events, none⟩
  | .unary width kind dst nextPc => unaryStep width kind dst nextPc s
  | .logic width kind dst src nextPc => logicalStep width kind dst src nextPc s
  | .nop nextPc => ⟨{ s with pc := nextPc }, [], none⟩
  | .branch cc target nextPc =>
      let taken := match cc with | none => true | some code => condition s.rflags code
      ⟨{ s with pc := if taken then target else nextPc }, [], none⟩
  | .setcc cc dst nextPc =>
      match scalarWrite s .w8 dst (if condition s.rflags cc then 1 else 0) with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (result, events) => ⟨{ result with pc := nextPc }, events, none⟩
  | .arithmetic width kind dst src nextPc => arithmeticStep width kind dst src nextPc s
  | .move width dst src nextPc => moveStep width dst src nextPc s
  | .byteSwap width dst nextPc => swapStep width dst nextPc s
  | .movbeLoad width dst address nextPc => movbeLoadStep width dst address nextPc s
  | .movbeStore width src address nextPc => movbeStoreStep width src address nextPc s
  | .bmiShift width kind dst source count nextPc => bmiShiftStep width kind dst source count nextPc s
  | .push width src nextPc => pushTransfer width (s.gpr src) [] nextPc s
  | .pushImmediate width value nextPc => pushTransfer width value [] nextPc s
  | .pushMemory width address nextPc =>
      match readSource s (.memory address) width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) => pushTransfer width value events nextPc s
  | .popMemory width address nextPc =>
      match readSource s (.memory (s.gpr 4)) width.bytes with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, events) =>
          match writeMemory s.memory address value width.bytes with
          | .error fault => ⟨s, events ++ [.fault fault], some fault⟩
          | .ok (memory, event) =>
              let advanced := s.gpr 4 + BitVec.ofNat 64 width.bytes
              ⟨{ s with gpr := (fun r => if r = 4 then advanced else s.gpr r), memory := memory, pc := nextPc },
                events ++ [event], none⟩
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
  | .mulx .. => 0xffffffffffffffff
  | .multiply .. => 0xffffffffffffff2b
  | .rotateRight width _ count _ => legacyDefinedFlags width .rotateLeft count
  | .exchange .. => 0xffffffffffffffff
  | .legacyShift width kind _ count _ => legacyDefinedFlags width kind count
  | .lea .. => 0xffffffffffffffff
  | .divide .. => 0xfffffffffffff72a
  | .signHigh .. => 0xffffffffffffffff
  | .extend .. => 0xffffffffffffffff
  | .popcount .. => 0xffffffffffffffff
  | .unary .. => 0xffffffffffffffff
  | .logic .. => 0xffffffffffffffef
  | .nop .. | .branch .. | .setcc .. => 0xffffffffffffffff
  | .arithmetic .. => 0xffffffffffffffff
  | .move .. => 0xffffffffffffffff
  | .push .. | .pushImmediate .. | .pushMemory .. | .popMemory .. => 0xffffffffffffffff
  | .byteSwap .. | .movbeLoad .. | .movbeStore .. => 0xffffffffffffffff
  | .bmiShift .. => 0xffffffffffffffff
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
  rexPresent : Bool := false
  segment : Nat := 0
  vexInvalid : Bool := false
  mandatoryPrefix : Nat := 0

private def stackWidth (p : Prefix) : StackWidth :=
  if p.rex / 8 = 1 then .w64 else if p.operand16 then .w16 else .w64

private def prefixes : List Byte → Prefix → Nat → Prefix × List Byte × Nat
  | [], p, n => (p, [], n)
  | b :: rest, p, n =>
      let v := b.toNat
      if v = 0x66 then prefixes rest { p with operand16 := true, rex := 0, rexPresent := false, vexInvalid := true } (n + 1)
      else if v = 0x67 then prefixes rest { p with address32 := true, rex := 0, rexPresent := false } (n + 1)
      else if v = 0x64 ∨ v = 0x65 then
        prefixes rest { p with segment := v, rex := 0, rexPresent := false } (n + 1)
      else if v = 0x26 ∨ v = 0x2e ∨ v = 0x36 ∨ v = 0x3e then
        prefixes rest { p with segment := 0, rex := 0, rexPresent := false } (n + 1)
      else if v = 0xf2 ∨ v = 0xf3 then prefixes rest { p with rex := 0, rexPresent := false, vexInvalid := true, mandatoryPrefix := v } (n + 1)
      else if 0x40 ≤ v ∧ v ≤ 0x4f then prefixes rest { p with rex := v - 0x40, rexPresent := true, vexInvalid := true } (n + 1)
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

private def scalarWidth (p : Prefix) (byte : Bool) : ScalarWidth :=
  if byte then .w8 else if p.rex / 8 = 1 then .w64 else if p.operand16 then .w16 else .w32

private def scalarSlice (p : Prefix) (width : ScalarWidth) (code : Nat) : RegisterSlice :=
  if h : width = .w8 ∧ p.rexPresent = false ∧ 4 ≤ code ∧ code < 8 then
    .high ⟨code - 4, by omega⟩
  else .low (registerCode code)

/-- The native integer opcode group, shared by direct and immediate forms. -/
private def integerBinary (group : Nat) (width : ScalarWidth) (dst : ScalarDestination)
    (src : ScalarSource) (nextPc : Word) : Except String Instruction :=
  match group with
  | 0 => .ok (.arithmetic width .add dst src nextPc)
  | 1 => .ok (.logic width .or dst src nextPc)
  | 2 => .ok (.arithmetic width .adc dst src nextPc)
  | 3 => .ok (.arithmetic width .sbb dst src nextPc)
  | 4 => .ok (.logic width .and dst src nextPc)
  | 5 => .ok (.arithmetic width .sub dst src nextPc)
  | 6 => .ok (.logic width .xor dst src nextPc)
  | 7 => .ok (.arithmetic width .compare dst src nextPc)
  | _ => .error "invalid native integer group"

private def scalarSource (p : Prefix) (width : ScalarWidth) : Source → ScalarSource
  | .register reg => .register (scalarSlice p width reg.val)
  | .memory address => .memory address

private def scalarDestination (p : Prefix) (width : ScalarWidth) : Source → ScalarDestination
  | .register reg => .register (scalarSlice p width reg.val)
  | .memory address => .memory address

private def fallthrough (s : State) (length : Nat) : Except String Word :=
  if length ≤ 15 then .ok (s.pc + BitVec.ofNat 64 length)
  else .error "native encoding exceeds the architectural 15-byte limit"

/-- Decode a native instruction. Operands, effective addresses and fall-through
PC are obtained from bytes, including REX, operand/address size, segment bases,
ModRM, SIB and signed displacement. No caller-supplied decode is trusted. -/
def decode (bytes : Array Byte) (s : State) : Except String Instruction := do
  let (p, _, count) := prefixes bytes.toList {} 0
  let first ← byteAt bytes count
  if first = 0x90 ∧ p.rex % 2 = 0 then
    return .nop (← fallthrough s (count + 1))
  if 0x90 ≤ first ∧ first ≤ 0x97 then
    let width := scalarWidth p false
    return .exchange width (.low 0) (.low (registerCode (first % 8 + 8 * (p.rex % 2))))
      (← fallthrough s (count + 1))
  if first = 0x86 ∨ first = 0x87 then
    let modrm ← byteAt bytes (count + 1)
    if modrm / 64 ≠ 3 then throw "register XCHG requires two register operands"
    let width := scalarWidth p (first == 0x86)
    let reg := scalarSlice p width ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    let rm := scalarSlice p width (modrm % 8 + 8 * (p.rex % 2))
    return .exchange width reg rm (← fallthrough s (count + 2))
  if first = 0xeb ∨ first = 0xe9 ∨ (0x70 ≤ first ∧ first ≤ 0x7f) then
    let size := if first = 0xe9 then 4 else 1
    let offset ← signedDisplacement bytes (count + 1) size
    let nextPc ← fallthrough s (count + 1 + size)
    let cc := if first = 0xeb ∨ first = 0xe9 then none
      else some (⟨first % 16, Nat.mod_lt _ (by decide)⟩ : Fin 16)
    return .branch cc (nextPc + offset) nextPc
  if first = 0x0f then
    let opcode ← byteAt bytes (count + 1)
    if opcode = 0xaf then
      let width := if p.rex / 8 = 1 then CmovWidth.w64 else if p.operand16 then .w16 else .w32
      let modrm ← byteAt bytes (count + 2)
      let dst := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
      let (source, nextPc, _) ← operand bytes s p modrm (count + 3) 0
      return .multiply width dst source none nextPc
    if opcode = 0x1f then
      let modrm ← byteAt bytes (count + 2)
      if (modrm / 8) % 8 != 0 then throw "reserved native NOP extension"
      let (_, nextPc, _) ← operand bytes s p modrm (count + 3) 0
      return .nop nextPc
    if 0x80 ≤ opcode ∧ opcode ≤ 0x8f then
      let offset ← signedDisplacement bytes (count + 2) 4
      let nextPc ← fallthrough s (count + 6)
      return .branch (some ⟨opcode % 16, Nat.mod_lt _ (by decide)⟩) (nextPc + offset) nextPc
    if 0x90 ≤ opcode ∧ opcode ≤ 0x9f then
      let modrm ← byteAt bytes (count + 2)
      let (destination, nextPc, _) ← operand bytes s p modrm (count + 3) 0
      return .setcc ⟨opcode % 16, Nat.mod_lt _ (by decide)⟩ (scalarDestination p .w8 destination) nextPc
  if first < 0x40 ∧ first % 8 < 6 then
    let form := first % 8
    let width := scalarWidth p (form % 2 == 0)
    if form < 4 then
      let modrm ← byteAt bytes (count + 1)
      let reg := scalarSlice p width ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
      let (rm, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      if form < 2 then return ← integerBinary (first / 8) width (scalarDestination p width rm) (.register reg) nextPc
      else return ← integerBinary (first / 8) width (.register reg) (scalarSource p width rm) nextPc
    else
      let size := if width = .w64 then 4 else width.bytes
      let immediate ← signedDisplacement bytes (count + 1) size
      let nextPc ← fallthrough s (count + 1 + size)
      return ← integerBinary (first / 8) width (.register (.low 0)) (.immediate immediate) nextPc
  if first = 0x80 ∨ first = 0x81 ∨ first = 0x83 then
    let modrm ← byteAt bytes (count + 1)
    let width := scalarWidth p (first == 0x80)
    let size := if first = 0x83 then 1 else if width = .w64 then 4 else width.bytes
    let (rm, nextPc, cursor) ← operand bytes s p modrm (count + 2) size
    let immediate ← signedDisplacement bytes cursor size
    return ← integerBinary ((modrm / 8) % 8) width (scalarDestination p width rm) (.immediate immediate) nextPc
  if first = 0xc0 ∨ first = 0xc1 ∨ first = 0xd0 ∨ first = 0xd1 ∨ first = 0xd2 ∨ first = 0xd3 then
    let modrm ← byteAt bytes (count + 1)
    let width := scalarWidth p (first % 2 == 0)
    let immediate := first = 0xc0 ∨ first = 0xc1
    let (rm, nextPc, cursor) ← operand bytes s p modrm (count + 2) (if immediate then 1 else 0)
    let amount ← if immediate then pure (BitVec.ofNat 64 (← byteAt bytes cursor))
      else if first = 0xd0 ∨ first = 0xd1 then pure 1 else pure (s.gpr 1 &&& 0xff)
    if (modrm / 8) % 8 = 1 then
      return .rotateRight width (scalarDestination p width rm) amount nextPc
    let kind ← match (modrm / 8) % 8 with
      | 0 => pure LegacyShift.rotateLeft
      | 4 | 6 => pure LegacyShift.left
      | 5 => pure LegacyShift.right
      | 7 => pure LegacyShift.arithmetic
      | _ => throw "unsupported native rotate-through-carry group"
    return .legacyShift width kind (scalarDestination p width rm) amount nextPc
  if first = 0x69 ∨ first = 0x6b then
    let width := if p.rex / 8 = 1 then CmovWidth.w64 else if p.operand16 then .w16 else .w32
    let size := if first = 0x6b then 1 else if width = .w16 then 2 else 4
    let modrm ← byteAt bytes (count + 1)
    let dst := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    let (source, nextPc, cursor) ← operand bytes s p modrm (count + 2) size
    let immediate ← signedDisplacement bytes cursor size
    return .multiply width dst source (some (immediate.setWidth 32)) nextPc
  if first = 0x84 ∨ first = 0x85 then
    let width := scalarWidth p (first == 0x84)
    let modrm ← byteAt bytes (count + 1)
    let reg := scalarSlice p width ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    let (rm, nextPc, _) ← operand bytes s p modrm (count + 2) 0
    return .logic width .test (scalarDestination p width rm) (.register reg) nextPc
  if first = 0xa8 ∨ first = 0xa9 then
    let width := scalarWidth p (first == 0xa8)
    let size := if width = .w64 then 4 else width.bytes
    let immediate ← signedDisplacement bytes (count + 1) size
    let nextPc ← fallthrough s (count + 1 + size)
    return .logic width .test (.register (.low 0)) (.immediate immediate) nextPc
  if first = 0xf6 ∨ first = 0xf7 then
    let modrm ← byteAt bytes (count + 1)
    let group := (modrm / 8) % 8
    if group = 6 then
      let width := scalarWidth p (first == 0xf6)
      let (source, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      return .divide width (scalarSource p width source) nextPc
    if group = 2 ∨ group = 3 then
      let width := scalarWidth p (first == 0xf6)
      let (rm, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      return .unary width (if group = 2 then .not else .neg) (scalarDestination p width rm) nextPc
    if group = 0 then
      let width := scalarWidth p (first == 0xf6)
      let size := if width = .w64 then 4 else width.bytes
      let (rm, nextPc, cursor) ← operand bytes s p modrm (count + 2) size
      let immediate ← signedDisplacement bytes cursor size
      return .logic width .test (scalarDestination p width rm) (.immediate immediate) nextPc
  if first = 0x8d then
    let modrm ← byteAt bytes (count + 1)
    if modrm / 64 = 3 then throw "LEA requires a memory-address encoding"
    let width := if p.rex / 8 = 1 then CmovWidth.w64 else if p.operand16 then .w16 else .w32
    let dst := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    -- LEA computes an offset: segment overrides contribute no FS/GS base.
    let (source, nextPc, _) ← operand bytes s { p with segment := 0 } modrm (count + 2) 0
    match source with
    | .memory address => return .lea width dst address nextPc
    | .register _ => throw "LEA requires a memory-address encoding"
  if first = 0x63 then
    let modrm ← byteAt bytes (count + 1)
    let targetWidth := scalarWidth p false
    let sourceWidth := if p.rex / 8 = 1 then ScalarWidth.w32 else targetWidth
    let dst := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    let (source, nextPc, _) ← operand bytes s p modrm (count + 2) 0
    return .extend sourceWidth targetWidth true dst (scalarSource p sourceWidth source) nextPc
  if first = 0x99 then
    let width := if p.rex / 8 = 1 then CmovWidth.w64 else if p.operand16 then .w16 else .w32
    return .signHigh width (← fallthrough s (count + 1))
  if first = 0x98 then
    let targetWidth := scalarWidth p false
    let sourceWidth := if targetWidth = .w64 then ScalarWidth.w32
      else if targetWidth = .w32 then .w16 else .w8
    return .extend sourceWidth targetWidth true 0 (.register (.low 0)) (← fallthrough s (count + 1))
  if first = 0xfe ∨ first = 0xff then
    let modrm ← byteAt bytes (count + 1)
    let group := (modrm / 8) % 8
    if group = 0 ∨ group = 1 then
      let width := scalarWidth p (first == 0xfe)
      let (rm, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      return .unary width (if group = 0 then .inc else .dec) (scalarDestination p width rm) nextPc
  if 0xb0 ≤ first ∧ first ≤ 0xbf then
    let width := scalarWidth p (decide (first < 0xb8))
    let size := width.bytes
    let immediate ← signedDisplacement bytes (count + 1) size
    let nextPc ← fallthrough s (count + 1 + size)
    let dst := scalarSlice p width (first % 8 + 8 * (p.rex % 2))
    return .move width (.register dst) (.immediate immediate) nextPc
  if 0x88 ≤ first ∧ first ≤ 0x8b then
    let width := scalarWidth p (first % 2 == 0)
    let modrm ← byteAt bytes (count + 1)
    let reg := scalarSlice p width ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    let (rm, nextPc, _) ← operand bytes s p modrm (count + 2) 0
    if first < 0x8a then
      return .move width (scalarDestination p width rm) (.register reg) nextPc
    else return .move width (.register reg) (scalarSource p width rm) nextPc
  if first = 0xc6 ∨ first = 0xc7 then
    let width := scalarWidth p (first == 0xc6)
    let modrm ← byteAt bytes (count + 1)
    if (modrm / 8) % 8 ≠ 0 then throw "invalid MOV immediate opcode extension"
    let size := if width = .w64 then 4 else width.bytes
    let (rm, nextPc, cursor) ← operand bytes s p modrm (count + 2) size
    let immediate ← signedDisplacement bytes cursor size
    return .move width (scalarDestination p width rm) (.immediate immediate) nextPc
  if 0xa0 ≤ first ∧ first ≤ 0xa3 then
    let width := scalarWidth p (first % 2 == 0)
    let size := if p.address32 then 4 else 8
    let raw ← signedDisplacement bytes (count + 1) size
    let offset := if p.address32 then (raw.setWidth 32).setWidth 64 else raw
    let segment := if p.segment = 0x64 then s.fsBase else if p.segment = 0x65 then s.gsBase else 0
    let nextPc ← fallthrough s (count + 1 + size)
    if first < 0xa2 then return .move width (.register (.low 0)) (.memory (segment + offset)) nextPc
    else return .move width (.memory (segment + offset)) (.register (.low 0)) nextPc
  if 0x50 ≤ first ∧ first ≤ 0x57 then
    let length := count + 1
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    let src := registerCode (first % 8 + 8 * (p.rex % 2))
    let width := stackWidth p
    return .push width src (s.pc + BitVec.ofNat 64 length)
  if 0x58 ≤ first ∧ first ≤ 0x5f then
    let length := count + 1
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    let dst := registerCode (first % 8 + 8 * (p.rex % 2))
    let width := stackWidth p
    return .pop width dst (s.pc + BitVec.ofNat 64 length)
  if first = 0x68 ∨ first = 0x6a then
    let width := stackWidth p
    let immediateBytes := if first = 0x6a then 1 else if width = .w16 then 2 else 4
    let value ← signedDisplacement bytes (count + 1) immediateBytes
    let length := count + 1 + immediateBytes
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    return .pushImmediate width value (s.pc + BitVec.ofNat 64 length)
  if first = 0xff then
    let modrm ← byteAt bytes (count + 1)
    if (modrm / 8) % 8 = 6 then
      let (source, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      match source with
      | .register src => return .push (stackWidth p) src nextPc
      | .memory address => return .pushMemory (stackWidth p) address nextPc
  if first = 0x8f then
    let modrm ← byteAt bytes (count + 1)
    if (modrm / 8) % 8 ≠ 0 then throw "invalid POP opcode extension"
    let width := stackWidth p
    let advanced := s.gpr 4 + BitVec.ofNat 64 width.bytes
    let updated := { s with gpr := fun r => if r = 4 then advanced else s.gpr r }
    let (destination, nextPc, _) ← operand bytes updated p modrm (count + 2) 0
    match destination with
    | .register dst => return .pop width dst nextPc
    | .memory address => return .popMemory width address nextPc
  if first = 0xc4 then
    let vex1 ← byteAt bytes (count + 1)
    let vex2 ← byteAt bytes (count + 2)
    let opcode ← byteAt bytes (count + 3)
    let map := vex1 % 32
    let vexPrefix := vex2 % 8
    let isBit := map == 2 && vexPrefix == 0 && (opcode == 0xf5 || opcode == 0xf2)
    let isShift := map == 2 && opcode == 0xf7 && (vexPrefix == 1 || vexPrefix == 2 || vexPrefix == 3)
    let isMulx := map == 2 && opcode == 0xf6 && vexPrefix == 3
    let isRotate := map == 3 && opcode == 0xf0 && vexPrefix == 3 && (vex2 / 8) % 16 == 15
    if p.vexInvalid || !(isBit || isShift || isRotate || isMulx) then
      throw "invalid BMI VEX encoding"
    let rex := (if vex1 / 128 = 0 then 4 else 0) +
      (if (vex1 / 64) % 2 = 0 then 2 else 0) +
      (if (vex1 / 32) % 2 = 0 then 1 else 0)
    let p := { p with rex := rex }
    let modrm ← byteAt bytes (count + 4)
    let dst := registerCode ((modrm / 8) % 8 + 8 * ((rex / 4) % 2))
    let index := registerCode (15 - (vex2 / 8) % 16)
    let width := if vex2 / 128 = 0 then BzhiWidth.w32 else .w64
    let (source, nextPc, cursor) ← operand bytes s p modrm (count + 5) (if isRotate then 1 else 0)
    if isMulx then return .mulx width dst index source nextPc
    if isRotate then
      let immediate ← byteAt bytes cursor
      return .bmiShift width .rotate dst source (.immediate (BitVec.ofNat 8 immediate)) nextPc
    if isShift then
      let kind := if vexPrefix = 1 then BmiShift.left else if vexPrefix = 2 then .arithmetic else .right
      return .bmiShift width kind dst source (.register index) nextPc
    if opcode = 0xf2 then return .andn width dst index source nextPc
    return .bzhi width dst source index nextPc
  let opcode ← byteAt bytes (count + 1)
  if first ≠ 0x0f then throw "expected two-byte native opcode"
  if 0xc8 ≤ opcode ∧ opcode ≤ 0xcf then
    let length := count + 2
    if length > 15 then throw "native encoding exceeds the architectural 15-byte limit"
    if p.operand16 ∧ p.rex / 8 = 0 then throw "BSWAP has no defined 16-bit result"
    let dst := registerCode (opcode % 8 + 8 * (p.rex % 2))
    return .byteSwap (if p.rex / 8 = 1 then .w64 else .w32) dst (s.pc + BitVec.ofNat 64 length)
  if opcode = 0x38 then
    let third ← byteAt bytes (count + 2)
    if p.mandatoryPrefix = 0xf2 ∨ (third ≠ 0xf0 ∧ third ≠ 0xf1) then
      throw "unrecognized three-byte native opcode"
    let modrm ← byteAt bytes (count + 3)
    if modrm / 64 = 3 then throw "MOVBE requires a memory operand"
    let reg := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    let width := if p.rex / 8 = 1 then CmovWidth.w64 else if p.operand16 then .w16 else .w32
    let (source, nextPc, _) ← operand bytes s p modrm (count + 4) 0
    match source with
    | .register _ => throw "MOVBE requires a memory operand"
    | .memory address =>
        if third = 0xf0 then return .movbeLoad width reg address nextPc
        else return .movbeStore width reg address nextPc
  let modrm ← byteAt bytes (count + 2)
  let reg := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
  let width := if p.rex / 8 = 1 then CmovWidth.w64
    else if p.operand16 then .w16 else .w32
  if opcode = 0xb6 ∨ opcode = 0xb7 ∨ opcode = 0xbe ∨ opcode = 0xbf then
    let sourceWidth := if opcode % 2 = 0 then ScalarWidth.w8 else .w16
    let targetWidth := scalarWidth p false
    let (source, nextPc, _) ← operand bytes s p modrm (count + 3) 0
    return .extend sourceWidth targetWidth (decide (opcode ≥ 0xbe)) reg
      (scalarSource p sourceWidth source) nextPc
  if opcode = 0xb8 ∧ p.mandatoryPrefix = 0xf3 then
    let (source, nextPc, _) ← operand bytes s p modrm (count + 3) 0
    return .popcount width reg source nextPc
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
