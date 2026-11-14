import KProgFormal.Reference.Memory
import X86.CheckedMemory

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

/-- Paging canonicality is an architectural input: CR4.LA57 selects57 bits,
otherwise long mode uses48. The control profile here has CET shadow stacks off. -/
inductive AddressWidth
  | w48 | w57
  deriving DecidableEq, Repr

def AddressWidth.bits : AddressWidth → Nat | .w48 => 48 | .w57 => 57

structure State where
  gpr : Register → Word
  rflags : Word
  xmm0 : BitVec 128
  memory : Memory
  pc : Word
  fsBase : Word
  gsBase : Word
  addressWidth : AddressWidth := .w48
  /-- Free undefined-bit input for the external ISA, never inferred from tags. -/
  oracle : _root_.X86.Oracle := default
  /-- Model refusal is separate from an architectural fault. -/
  modelError : Option _root_.X86.MsErr := none

/-- RFLAGS transport; unmodeled bits remain part of the native state. -/
private def externalFlags (flags : Word) : _root_.X86.Flags :=
  { cf := flags.getLsbD 0, pf := flags.getLsbD 2, af := flags.getLsbD 4,
    zf := flags.getLsbD 6, sf := flags.getLsbD 7, of := flags.getLsbD 11,
    df := flags.getLsbD 10 }

private def externalRflags (old : Word) (flags : _root_.X86.Flags) : Word :=
  let fields : List (Word × Bool) := [(1,flags.cf),(4,flags.pf),(16,flags.af),
    (64,flags.zf),(128,flags.sf),(2048,flags.of),(1024,flags.df)]
  fields.foldl (fun value (mask,bit) => if bit then value ||| mask else value &&& ~~~mask) old

private def externalCpu (s : State) : _root_.X86.Cpu :=
  { regs := _root_.X86.GPR.all.foldl (fun regs r => regs.set r (s.gpr r.index)) default
    rip := s.pc
    flags := externalFlags s.rflags
    xmm := { xmm0 := s.xmm0 }
    fsBase := s.fsBase
    gsBase := s.gsBase
    oracle := s.oracle
    ms := s.modelError }

private def externalFault : _root_.X86.ExecutionFault → Fault
  | .read a n => .read a n
  | .write a n => .write a n
  | .nonCanonical a => .nonCanonical a
  | .invalidOpcode => .invalidOpcode
  | .divideError => .divide
  | .misaligned a n => .alignment a n

private def storeBytes (memory : Memory) (address : Word) (bytes : List Byte) : Memory :=
  (bytes.foldl (fun (memory,address) byte =>
    (storeMemory memory address (byte.setWidth 64) 1, address+1)) (memory,address)).1

/-- Representation projection only. An RMW remains an adjacent atomic-read and
write pair in the existing native-event view, retaining both byte values. -/
private def externalEffects (memory : Memory) (events : List _root_.X86.MemoryAccessEvent) :
    Transition Memory :=
  events.foldl (fun result event => match event with
    | .memory kind address bytes initialized =>
      match kind with
      | .read => { result with events := result.events ++ [.memory .read address bytes initialized] }
      | .write => { result with
          state := storeBytes result.state address bytes
          events := result.events ++ [.memory .write address bytes initialized] }
    | .rmw address before after initialized =>
      { result with
        state := storeBytes result.state address after
        events := result.events ++ [.memory .atomic address before initialized, .memory .write address after true] }
    | .fault reason =>
      let fault := externalFault reason
      { result with events := result.events ++ [.fault fault], fault := some fault })
    ⟨memory, [], none⟩

/-- Execute the fork, with an explicit view of arbitrary native byte memory.
Potential reads come from the fork's own access plan; target values are
recomputed after materialization. Only actual write effects update the native
memory function, so untouched and uninitialized bytes keep their input values.
No local arithmetic, flag, effective-address or permission interpreter runs. -/
def nativeStep (op : _root_.X86.Op) (nextPc : Word) (s : State) : Transition State :=
  let i : _root_.X86.Instr := { op, len := (nextPc-s.pc).toNat }
  let cpu := externalCpu s
  match _root_.X86.plannedReadAddresses i cpu with
  | .error reason => ⟨{ s with modelError := some reason }, [], none⟩
  | .ok addresses =>
    let memory := addresses.foldl (fun memory address => memory.write address (s.memory.value address))
      _root_.X86.Mem.empty
    let input : _root_.X86.CheckedState :=
      { cpu := { cpu with mem := memory }
        profile := some {
          readable := s.memory.readable
          writable := s.memory.writable
          initialized := s.memory.initialized }
        addressWidth := match s.addressWidth with | .w48 => .la48 | .w57 => .la57 }
    let output := _root_.X86.stepChecked i input
    let effect := externalEffects s.memory output.events
    ⟨{ s with
        gpr := fun r => output.cpu.regs.get (_root_.X86.GPR.ofIndex r)
        rflags := externalRflags s.rflags output.cpu.flags
        xmm0 := output.cpu.getXmm .x0
        memory := effect.state
        pc := output.cpu.rip
        fsBase := output.cpu.fsBase
        gsBase := output.cpu.gsBase
        oracle := output.cpu.oracle
        modelError := output.cpu.ms }, effect.events, effect.fault⟩

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

def writeValue (width : CmovWidth) (old value : Word) : Word :=
  match width with
  | .w16 => (old &&& 0xffffffffffff0000) ||| (value &&& 0xffff)
  | .w32 => (value.setWidth 32).setWidth 64
  | .w64 => value

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

inductive ArithmeticKind | add | adc | sub | sbb | compare
  deriving DecidableEq, Repr

inductive LogicKind | and | or | xor | test
  deriving DecidableEq, Repr

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

private def externalSize : ScalarWidth → _root_.X86.Size
  | .w8 => .b | .w16 => .w | .w32 => .d | .w64 => .q

private def externalCmovSize : CmovWidth → _root_.X86.Size
  | .w16 => .w | .w32 => .d | .w64 => .q

private def externalBzhiSize : BzhiWidth → _root_.X86.Size
  | .w32 => .d | .w64 => .q

private def externalRegister (width : ScalarWidth) (slice : RegisterSlice) : _root_.X86.Operand :=
  .reg (_root_.X86.GPR.ofIndex slice.reg) (slice.shift width == 8)

private def externalSource (width : ScalarWidth) : ScalarSource → _root_.X86.Operand
  | .register slice => externalRegister width slice
  | .memory address => .mem { disp := address }
  | .immediate value => .imm value

private def externalDestination (width : ScalarWidth) : ScalarDestination → _root_.X86.Operand
  | .register slice => externalRegister width slice
  | .memory address => .mem { disp := address }

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

/-- Intel SDM IDIV (F6/F7 /7) interprets the complete double-width dividend
and width-sized divisor as signed integers. Its quotient truncates toward zero;
zero divisors and signed-range overflow raise #DE before any writeback.
The executable retains an undefined-flags representative, as for DIV. -/
def signedDivideStep (width : ScalarWidth) (source : ScalarSource) (nextPc : Word)
    (s : State) : Transition State :=
  match scalarRead s width source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (operand, reads) =>
      let dividend := (BitVec.ofNat (2 * width.bits) (divideDividend width s)).toInt
      let divisor := (operand.setWidth width.bits).toInt
      let quotient := dividend.tdiv divisor
      let limit : Int := 2 ^ (width.bits - 1)
      if divisor = 0 ∨ quotient < -limit ∨ limit ≤ quotient then
        ⟨s, reads ++ [.fault .divide], some .divide⟩
      else
        let remainder := dividend.tmod divisor
        if width = .w8 then
          let packed := (BitVec.ofInt 8 quotient).toNat + 256 * (BitVec.ofInt 8 remainder).toNat
          let result := scalarWriteValue (s.gpr 0) (BitVec.ofNat 64 packed) .w16 (.low 0)
          ⟨{ s with gpr := (fun r => if r = 0 then result else s.gpr r), pc := nextPc }, reads, none⟩
        else
          let low := scalarWriteValue (s.gpr 0) (BitVec.ofInt 64 quotient) width (.low 0)
          let high := scalarWriteValue (s.gpr 2) (BitVec.ofInt 64 remainder) width (.low 2)
          ⟨{ s with gpr := (fun r => if r = 0 then low else if r = 2 then high else s.gpr r), pc := nextPc }, reads, none⟩

/-- Double-shift status flags; the executable preserves undefined AF/OF
representatives. `definedFlags` below removes their architectural guarantees. -/
def doubleShiftFlags (width : CmovWidth) (left : Bool) (destination source count old : Word) : Word :=
  let amount := doubleShiftCount count width.bits
  let n := amount.toNat
  let result := doubleShiftValue left destination source count width.bits
  let a := (destination.setWidth width.bits).setWidth 64
  let cf := if left then (if n ≤ width.bits then a.getLsbD (width.bits - n) else false)
    else (if n ≤ width.bits then a.getLsbD (n - 1) else false)
  let of := doubleShiftOverflow destination result amount width.bits (old.getLsbD 11)
  if n = 0 then old else
    setFlag (setFlag (setFlag (setFlag (setFlag old 0 cf) 11 of)
      2 (evenParity result)) 6 (result == 0)) 7 (result.getLsbD (width.bits - 1))

def doubleShiftStep (width : CmovWidth) (left : Bool) (dst source : Register)
    (count nextPc : Word) (s : State) : Transition State :=
  let result := doubleShiftValue left (s.gpr dst) (s.gpr source) count width.bits
  ⟨{ s with gpr := fun r => if r = dst then writeValue width (s.gpr r) result else s.gpr r, rflags := doubleShiftFlags width left (s.gpr dst) (s.gpr source) count s.rflags, pc := nextPc }, [], none⟩

/-- CWD/CDQ/CQO take the upper half of a signed double-width accumulator.
The low accumulator and all flags are preserved. -/
def signHighValue (width : CmovWidth) (source : Word) : Word :=
  if (source.setWidth width.bits).msb then BitVec.ofNat 64 (2 ^ width.bits - 1) else 0

/-- Legacy128-bit SSE moves in the enabled-SSE profile. MOVAPS checks its
16-byte alignment before a mapped-memory access; MOVUPS has no such constraint.
The guest event is the complete architectural access, not private scalar lanes. -/
def xmm0Bytes (value : BitVec 128) : List Byte :=
  (List.range 16).map (fun i => (value >>> (8 * i)).setWidth 8)

def xmm0Store (m : Memory) (address : Word) (value : BitVec 128) : Memory :=
  { m with
    value := fun a => if (a - address).toNat < 16 then
      (value >>> (8 * (a - address).toNat)).setWidth 8 else m.value a
    initialized := fun a => if (a - address).toNat < 16 then true else m.initialized a }

def xmm0Step (store aligned : Bool) (address nextPc : Word) (s : State) : Transition State :=
  if aligned && address &&& 15 != 0 then
    ⟨s, [.fault (.alignment address 16)], some (.alignment address 16)⟩
  else if store then
    if permitted s.memory.writable address 16 then
      ⟨{ s with memory := xmm0Store s.memory address s.xmm0, pc := nextPc },
        [.memory .write address (xmm0Bytes s.xmm0) true], none⟩
    else ⟨s, [.fault (.write address 16)], some (.write address 16)⟩
  else
    if permitted s.memory.readable address 16 then
      ⟨{ s with xmm0 := littleEndian 128 (bytesAt s.memory address 16), pc := nextPc },
        [.memory .read address (bytesAt s.memory address 16) (initializedAt s.memory address 16)], none⟩
    else ⟨s, [.fault (.read address 16)], some (.read address 16)⟩

/-- REP uses the address size for all three implicit registers. In address32
mode even zero-count execution clears their high halves before checking memory. -/
def stringAddress (address32 : Bool) (value : Word) : Word :=
  if address32 then (value.setWidth 32).setWidth 64 else value

def stringStart (address32 : Bool) (s : State) : State :=
  { s with gpr := fun r => if r = 1 ∨ r = 6 ∨ r = 7 then stringAddress address32 (s.gpr r) else s.gpr r }

/-- One completed MOVS element changes the three implicit registers. Source
segment overrides affect only the read, never ES:RDI. DF selects the stride. -/
def stringAdvance (width : ScalarWidth) (address32 : Bool) (s : State) : State :=
  let stride := BitVec.ofNat 64 width.bytes
  let delta := if s.rflags.getLsbD 10 then -stride else stride
  { s with gpr := fun r =>
      if r = 1 then stringAddress address32 (s.gpr r - 1)
      else if r = 6 ∨ r = 7 then stringAddress address32 (s.gpr r + delta)
      else s.gpr r }

/-- Faults stop before completing this element. Earlier completed iterations
remain committed; a source read before a destination fault remains observable. -/
def repMovsElement (width : ScalarWidth) (address32 : Bool) (sourceBase : Word)
    (s : State) : Transition State :=
  let source := sourceBase + stringAddress address32 (s.gpr 6)
  let destination := stringAddress address32 (s.gpr 7)
  match readMemory s.memory source width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, read) =>
      match writeMemory s.memory destination value width.bytes with
      | .error fault => ⟨s, [read, .fault fault], some fault⟩
      | .ok (memory, write) =>
          ⟨{ stringAdvance width address32 s with memory := memory }, [read, write], none⟩

/-- The repetition count comes from RCX/ECX, with no simulator bound. The PC
advances only at completion; a fault retains the instruction PC for restart. -/
def repMovsLoop (width : ScalarWidth) (address32 : Bool) (sourceBase nextPc : Word) :
    Nat → State → Transition State
  | 0, s => ⟨{ s with pc := nextPc }, [], none⟩
  | n + 1, s =>
      let first := repMovsElement width address32 sourceBase s
      if first.fault.isSome then first else
        let rest := repMovsLoop width address32 sourceBase nextPc n first.state
        ⟨rest.state, first.events ++ rest.events, rest.fault⟩

def repMovsStep (width : ScalarWidth) (address32 : Bool) (sourceBase nextPc : Word)
    (s : State) : Transition State :=
  let start := stringStart address32 s
  repMovsLoop width address32 sourceBase nextPc (start.gpr 1).toNat start

/-- STOS has no source-memory access and never changes RSI. The accumulator
is truncated by the architectural store; DF selects the signed destination
stride. This reference covers the native64 address form emitted by P. -/
def stosAdvance (width : ScalarWidth) (s : State) : State :=
  let stride := BitVec.ofNat 64 width.bytes
  let delta := if s.rflags.getLsbD 10 then -stride else stride
  { s with gpr := fun r => if r = 1 then s.gpr r - 1
      else if r = 7 then s.gpr r + delta else s.gpr r }

def repStosElement (width : ScalarWidth) (s : State) : Transition State :=
  match writeMemory s.memory (s.gpr 7) (s.gpr 0) width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (memory, write) =>
      ⟨{ stosAdvance width s with memory := memory }, [write], none⟩

/-- Each completed store commits its RCX/RDI progress. A store fault retains
that element's incoming state and instruction PC; completion advances the PC.
There is no iteration bound besides the full64-bit architectural RCX value. -/
def repStosLoop (width : ScalarWidth) (nextPc : Word) :
    Nat → State → Transition State
  | 0, s => ⟨{ s with pc := nextPc }, [], none⟩
  | n + 1, s =>
      let first := repStosElement width s
      if first.fault.isSome then first else
        let rest := repStosLoop width nextPc n first.state
        ⟨rest.state, first.events ++ rest.events, rest.fault⟩

def repStosStep (width : ScalarWidth) (nextPc : Word) (s : State) : Transition State :=
  repStosLoop width nextPc (s.gpr 1).toNat s

def canonicalTarget (width : AddressWidth) (target : Word) : Bool :=
  (target.setWidth width.bits).signExtend 64 == target

/-- Near CALL samples its source, including an incoming-RSP memory address,
before pushing the fall-through. Stack access faults precede a noncanonical
target fault; neither failure commits the prepared return-address write. -/
def callStep (source : ScalarSource) (nextPc : Word) (s : State) : Transition State :=
  match scalarRead s .w64 source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (target, reads) =>
      let address := s.gpr 4 - 8
      if permitted s.memory.writable address 8 then
        if canonicalTarget s.addressWidth target then
          pushTransfer .w64 nextPc reads target s
        else ⟨s, reads ++ [.fault (.nonCanonical target)], some (.nonCanonical target)⟩
      else ⟨s, reads ++ [.fault (.write address 8)], some (.write address 8)⟩

/-- Near RET reads the complete64-bit target before either RSP or PC changes.
The optional unsigned imm16 releases arguments after a successful pop. -/
def returnStep (release : BitVec 16) (s : State) : Transition State :=
  match readMemory s.memory (s.gpr 4) 8 with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (target, read) =>
      if canonicalTarget s.addressWidth target then
        ⟨{ s with gpr := fun r => if r = 4 then s.gpr 4 + 8 + release.setWidth 64 else s.gpr r, pc := target }, [read], none⟩
      else ⟨s, [read, .fault (.nonCanonical target)], some (.nonCanonical target)⟩

/-- Flat long-mode stack profile, with LASS disabled (its user/supervisor
policy is not imported from the hardware replay host). Every byte of the
implicit frame read must have a canonical linear
address under the same48/57-bit paging profile as CALL/RET. Byte addresses
wrap at64 bits exactly as in the shared memory model. The incoming old RSP
is not an address operand of LEAVE. -/
def leave64FrameCanonical (s : State) : Bool :=
  canonicalTarget s.addressWidth (s.gpr 5) &&
  canonicalTarget s.addressWidth (s.gpr 5 + 7)

/-- Long-mode LEAVE64 (C9), Intel SDM Vol2A3-597/598:
https://cdrdv2-public.intel.com/812383/253666-sdm-vol-2a.pdf
A noncanonical stack operand faults before a memory read. Commit RSP/RBP
only after the incoming-RBP8 read succeeds. F's hardware receipt confirms
ALL-GPR rollback on faults, including old RSP/RBP. Delivery RF and concrete
OS trap metadata remain outside the architectural instruction transition. -/
def leave64Step (nextPc : Word) (s : State) : Transition State :=
  if leave64FrameCanonical s then
    match readMemory s.memory (s.gpr 5) 8 with
    | .error fault => ⟨s, [.fault fault], some fault⟩
    | .ok (value, event) =>
        ⟨{ s with gpr := (fun r => if r = 4 then s.gpr 5 + 8 else if r = 5 then value else s.gpr r), pc := nextPc }, [event], none⟩
  else ⟨s, [.fault (.nonCanonical (s.gpr 5))], some (.nonCanonical (s.gpr 5))⟩

/-- One architectural instruction with its decoded fall-through address.
Effective-address decoding supplies the memory source address; reads remain
part of this step, so a false-condition CMOV cannot suppress an access fault. -/
inductive Instruction
  | call (source : ScalarSource) (nextPc : Word)
  | returnNear (release : BitVec 16) (nextPc : Word)
  | repMovs (width : ScalarWidth) (address32 : Bool) (sourceBase nextPc : Word)
  | repStos (width : ScalarWidth) (nextPc : Word)
  | xmm0Move (store aligned : Bool) (address nextPc : Word)
  | doubleShift (width : CmovWidth) (left : Bool) (dst source : Register) (count nextPc : Word)
  | mulx (width : BzhiWidth) (high low : Register) (source : Source) (nextPc : Word)
  | multiply (width : CmovWidth) (dst : Register) (source : Source) (immediate : Option (BitVec 32)) (nextPc : Word)
  | rotateRight (width : ScalarWidth) (dst : ScalarDestination) (count nextPc : Word)
  | exchange (width : ScalarWidth) (left right : RegisterSlice) (nextPc : Word)
  | legacyShift (width : ScalarWidth) (kind : LegacyShift) (dst : ScalarDestination) (count nextPc : Word)
  | lea (width : CmovWidth) (dst : Register) (address nextPc : Word)
  | divide (width : ScalarWidth) (source : ScalarSource) (nextPc : Word)
  | signedDivide (width : ScalarWidth) (source : ScalarSource) (nextPc : Word)
  | signHigh (width : CmovWidth) (nextPc : Word)
  | extend (sourceWidth targetWidth : ScalarWidth) (signed : Bool) (dst : Register) (source : ScalarSource) (nextPc : Word)
  | popcount (width : CmovWidth) (dst : Register) (source : Source) (nextPc : Word)
  | unary (width : ScalarWidth) (kind : UnaryKind) (dst : ScalarDestination) (nextPc : Word)
  | logic (width : ScalarWidth) (kind : LogicKind) (dst : ScalarDestination) (src : ScalarSource) (nextPc : Word)
  | nop (nextPc : Word)
  | leave64 (nextPc : Word)
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
  | ud2 (nextPc : Word)
  deriving DecidableEq, Repr

/-- The encoded instruction's fall-through, independently of its chosen
successor. Path certificates use this to check the consumed byte extent. -/
def Instruction.fallthrough : Instruction → Word
  | .call _ next | .returnNear _ next | .repMovs _ _ _ next | .repStos _ next | .xmm0Move _ _ _ next | .doubleShift _ _ _ _ _ next | .mulx _ _ _ _ next | .multiply _ _ _ _ next | .rotateRight _ _ _ next | .exchange _ _ _ next | .legacyShift _ _ _ _ next | .lea _ _ _ next | .divide _ _ next | .signedDivide _ _ next | .signHigh _ next | .extend _ _ _ _ _ next | .popcount _ _ _ next | .unary _ _ _ next | .logic _ _ _ _ next | .nop next | .leave64 next
  | .branch _ _ next | .setcc _ _ next | .arithmetic _ _ _ _ next
  | .move _ _ _ next | .push _ _ next | .pushImmediate _ _ next
  | .pushMemory _ _ next | .popMemory _ _ next | .pop _ _ next
  | .cmov _ _ _ _ next | .andn _ _ _ _ next | .byteSwap _ _ next
  | .movbeLoad _ _ _ next | .movbeStore _ _ _ next
  | .bmiShift _ _ _ _ _ next | .bzhi _ _ _ _ next | .bt _ _ _ next | .ud2 next => next

def step (instruction : Instruction) (s : State) : Transition State :=
  match instruction with
  | .ud2 _ => ⟨s, [.fault .invalidOpcode], some .invalidOpcode⟩
  | .call source nextPc => callStep source nextPc s
  | .returnNear release _ => returnStep release s
  | .repMovs width address32 sourceBase nextPc => repMovsStep width address32 sourceBase nextPc s
  | .repStos width nextPc => repStosStep width nextPc s
  | .xmm0Move store aligned address nextPc => xmm0Step store aligned address nextPc s
  | .doubleShift width left dst source count nextPc => doubleShiftStep width left dst source count nextPc s
  | .mulx width high low source nextPc => mulxStep width high low source nextPc s
  | .multiply width dst source immediate nextPc => multiplyStep width dst source immediate nextPc s
  | .rotateRight width dst count nextPc => rotateRightStep width dst count nextPc s
  | .exchange width left right nextPc => exchangeStep width left right nextPc s
  | .legacyShift width kind dst count nextPc => legacyShiftStep width kind dst count nextPc s
  | .lea width dst address nextPc =>
      nativeStep (.lea (externalCmovSize width) (_root_.X86.GPR.ofIndex dst) { disp := address }) nextPc s
  | .divide width source nextPc => divideStep width source nextPc s
  | .signedDivide width source nextPc => signedDivideStep width source nextPc s
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
  | .unary width kind dst nextPc =>
      let kind := match kind with | .inc => .inc | .dec => .dec | .neg => .neg | .not => .not
      nativeStep (.un kind (externalSize width) (externalDestination width dst)) nextPc s
  | .logic width kind dst src nextPc =>
      let kind := match kind with | .and => .and | .or => .or | .xor => .xor | .test => .test
      nativeStep (.bin kind (externalSize width) (externalDestination width dst) (externalSource width src)) nextPc s
  | .nop nextPc => nativeStep (.nop none) nextPc s
  | .leave64 nextPc => leave64Step nextPc s
  | .branch cc target nextPc =>
      let taken := match cc with | none => true | some code => condition s.rflags code
      ⟨{ s with pc := if taken then target else nextPc }, [], none⟩
  | .setcc cc dst nextPc =>
      match scalarWrite s .w8 dst (if condition s.rflags cc then 1 else 0) with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (result, events) => ⟨{ result with pc := nextPc }, events, none⟩
  | .arithmetic width kind dst src nextPc =>
      let kind := match kind with | .add => .add | .adc => .adc | .sub => .sub | .sbb => .sbb | .compare => .cmp
      nativeStep (.bin kind (externalSize width) (externalDestination width dst) (externalSource width src)) nextPc s
  | .move width dst src nextPc =>
      nativeStep (.mov (externalSize width) (externalDestination width dst) (externalSource width src)) nextPc s
  | .byteSwap width dst nextPc =>
      nativeStep (.bswap (externalBzhiSize width) (_root_.X86.GPR.ofIndex dst)) nextPc s
  | .movbeLoad width dst address nextPc =>
      nativeStep (.movbe (externalCmovSize width) (.reg (_root_.X86.GPR.ofIndex dst)) (.mem { disp := address })) nextPc s
  | .movbeStore width src address nextPc =>
      nativeStep (.movbe (externalCmovSize width) (.mem { disp := address }) (.reg (_root_.X86.GPR.ofIndex src))) nextPc s
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
  | .ud2 .. => 0xffffffffffffffff
  | .call .. | .returnNear .. | .leave64 .. => 0xffffffffffffffff
  | .repMovs .. | .repStos .. => 0xffffffffffffffff
  | .xmm0Move .. => 0xffffffffffffffff
  | .doubleShift width _ _ _ count _ =>
      let n := (doubleShiftCount count width.bits).toNat
      if n = 0 then 0xffffffffffffffff else if width.bits < n then 0xfffffffffffff72a
      else if n = 1 then 0xffffffffffffffef else 0xfffffffffffff7ef
  | .mulx .. => 0xffffffffffffffff
  | .multiply .. => 0xffffffffffffff2b
  | .rotateRight width _ count _ => legacyDefinedFlags width .rotateLeft count
  | .exchange .. => 0xffffffffffffffff
  | .legacyShift width kind _ count _ => legacyDefinedFlags width kind count
  | .lea .. => 0xffffffffffffffff
  | .divide .. | .signedDivide .. => 0xfffffffffffff72a
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

/-- Counts exceeding a double-shift operand size leave that destination
lane undefined; all other register bits remain architectural obligations. -/
def definedRegister (i : Instruction) (r : Register) : Word :=
  match i with
  | .doubleShift width _ dst _ count _ =>
      if r = dst ∧ width.bits < (doubleShiftCount count width.bits).toNat
      then ~~~(BitVec.ofNat 64 (2^width.bits) - 1) else 0xffffffffffffffff
  | _ => 0xffffffffffffffff

def observedRegisters (i : Instruction) (s : State) : Register → Word :=
  match i with
  | .doubleShift .. => fun r => s.gpr r &&& definedRegister i r
  | _ => s.gpr

/-- The executable gives a representative for undefined flags. The relational
ISA semantics below admits every value for those bits, as required by the SDM. -/
def matchesTransition (i : Instruction) (expected actual : Transition State) : Prop :=
  expected.events = actual.events ∧ expected.fault = actual.fault ∧
    let mask := if expected.fault.isSome then 0xffffffffffffffff else definedFlags i
    -- The oracle implements undefined choices; it is not an architectural
    -- observation. Every original native field, memory/effect/fault channel
    -- and the distinct model-refusal outcome remain compared.
    { expected.state with oracle := default, rflags := expected.state.rflags &&& mask, gpr := if expected.fault.isSome then expected.state.gpr else observedRegisters i expected.state } =
      { actual.state with oracle := default, rflags := actual.state.rflags &&& mask, gpr := if expected.fault.isSome then actual.state.gpr else observedRegisters i actual.state }

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
  if first = 0xe8 then
    let displacement ← signedDisplacement bytes (count + 1) 4
    let nextPc ← fallthrough s (count + 5)
    return .call (.immediate (nextPc + displacement)) nextPc
  if first = 0xc3 ∨ first = 0xc2 then
    let size := if first = 0xc2 then 2 else 0
    let raw ← signedDisplacement bytes (count + 1) size
    return .returnNear (raw.setWidth 16) (← fallthrough s (count + 1 + size))
  if first = 0xc9 then
    if stackWidth p ≠ .w64 then throw "LEAVE reference requires the 64-bit operand form"
    return .leave64 (← fallthrough s (count + 1))
  if first = 0xa4 ∨ first = 0xa5 then
    if p.mandatoryPrefix ≠ 0xf3 then throw "MOVS reference requires the architectural REP prefix"
    let sourceBase := if p.segment = 0x64 then s.fsBase else if p.segment = 0x65 then s.gsBase else 0
    return .repMovs (scalarWidth p (first == 0xa4)) p.address32 sourceBase (← fallthrough s (count + 1))
  if first = 0xaa ∨ first = 0xab then
    if p.mandatoryPrefix ≠ 0xf3 then throw "STOS reference requires the architectural REP prefix"
    if p.address32 then throw "STOS reference covers the native64 address profile"
    return .repStos (scalarWidth p (first == 0xaa)) (← fallthrough s (count + 1))
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
    if opcode = 0x0b then return .ud2 (← fallthrough s (count + 2))
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
    if group = 6 ∨ group = 7 then
      let width := scalarWidth p (first == 0xf6)
      let (source, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      return if group = 7 then .signedDivide width (scalarSource p width source) nextPc
        else .divide width (scalarSource p width source) nextPc
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
    if (modrm / 8) % 8 = 2 then
      let (target, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      return .call (scalarSource p .w64 target) nextPc
    if (modrm / 8) % 8 = 4 then
      let (target, nextPc, _) ← operand bytes s p modrm (count + 2) 0
      match target with
      | .register src => return .branch none (s.gpr src) nextPc
      | .memory _ => throw "native indirect jump reference requires a register target"
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
  if opcode = 0x10 ∨ opcode = 0x11 ∨ opcode = 0x28 ∨ opcode = 0x29 then
    if p.operand16 ∨ p.mandatoryPrefix ≠ 0 then throw "XMM0 reference requires legacy MOVUPS/MOVAPS"
    let modrm ← byteAt bytes (count + 2)
    if (modrm / 8) % 8 + 8 * ((p.rex / 4) % 2) ≠ 0 then throw "move requires XMM0"
    let (source, nextPc, _) ← operand bytes s p modrm (count + 3) 0
    let address ← match source with
      | .memory a => pure a
      | .register _ => throw "XMM0 move requires a memory operand"
    return .xmm0Move (opcode == 0x11 || opcode == 0x29) (opcode == 0x28 || opcode == 0x29) address nextPc
  if opcode = 0xa4 ∨ opcode = 0xa5 ∨ opcode = 0xac ∨ opcode = 0xad then
    let modrm ← byteAt bytes (count + 2)
    if modrm / 64 ≠ 3 then throw "double-shift reference requires a register destination"
    let immediate := opcode == 0xa4 || opcode == 0xac
    let (source, nextPc, cursor) ← operand bytes s p modrm (count + 3) (if immediate then 1 else 0)
    let amount ← if immediate then pure (BitVec.ofNat 64 (← byteAt bytes cursor)) else pure (s.gpr 1)
    let src := registerCode ((modrm / 8) % 8 + 8 * ((p.rex / 4) % 2))
    let dst ← match source with | .register r => pure r | .memory _ => throw "double-shift destination is not a register"
    let width := if p.rex / 8 = 1 then CmovWidth.w64 else if p.operand16 then .w16 else .w32
    return .doubleShift width (opcode == 0xa4 || opcode == 0xa5) dst src amount nextPc
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

/-- Public symbolic byte-decoding interface for the captured simple entry.
No operand or successor is supplied by the consumer of this lemma. -/
theorem decode_mov_rcx_rdi (s : State) :
    decode #[0x48,0x8b,0x0f] s = .ok
      (.move .w64 (.register (.low 1)) (.memory (s.gpr 7)) (s.pc + 3)) := by
  simp +decide [decode, prefixes, byteAt, operand, addressParts,
    signedDisplacement, registerCode, scalarWidth, scalarSlice,
    scalarSource, scalarDestination, Except.bind, Except.pure,
    Bind.bind, Pure.pure, Except.instMonad]

/-- Second concrete simple-entry load, sharing the canonical decoder. -/
theorem decode_mov_rdx_rdi8 (s : State) :
    decode #[0x48,0x8b,0x57,0x08] s = .ok
      (.move .w64 (.register (.low 2)) (.memory (s.gpr 7 + 8)) (s.pc + 4)) := by
  simp +decide [decode, prefixes, byteAt, operand, addressParts,
    signedDisplacement, registerCode, scalarWidth, scalarSlice,
    scalarSource, scalarDestination, Except.bind, Except.pure,
    Bind.bind, Pure.pure, Except.instMonad]


/-- Public short unsigned-above branch decoding from the actual byte operand.
The signed relative displacement and fall-through remain decoder outputs. -/
theorem decode_ja_rel8 (s : State) (displacement : Byte) :
    decode #[0x77,displacement] s = .ok
      (.branch (some 7) ((s.pc+2)+displacement.signExtend 64) (s.pc+2)) := by
  simp +decide [decode,prefixes,byteAt,signedDisplacement,fallthrough,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]


/-- Captured simple bounds-check LEA decoded by the single native decoder. -/
theorem decode_lea_rdi_rsi8 (s : State) :
    decode #[0x48,0x8d,0x7e,0x08] s = .ok
      (.lea .w64 7 (s.gpr 6+8) (s.pc+4)) := by
  simp +decide [decode,prefixes,byteAt,operand,addressParts,signedDisplacement,registerCode,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Captured simple ADD uses its signed immediate and architectural width. -/
theorem decode_add_rsi72 (s : State) :
    decode #[0x48,0x83,0xc6,0x48] s = .ok
      (.arithmetic .w64 .add (.register (.low 6)) (.immediate 72) (s.pc+4)) := by
  simp +decide [decode,prefixes,byteAt,operand,addressParts,signedDisplacement,registerCode,
    scalarWidth,scalarSlice,scalarDestination,integerBinary,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]


/-- The five actual instructions of the captured simple packet-write tail.
Signed immediate decoding is retained even for the one-byte 0xbc store. -/
theorem decode_simple_packet_tail (s : State) :
    decode #[0x66,0xc7,0x01,0x4e,0x61] s = .ok
      (.move .w16 (.memory (s.gpr 1)) (.immediate 24910) (s.pc+5)) ∧
    decode #[0xc6,0x41,0x02,0xbc] s = .ok
      (.move .w8 (.memory (s.gpr 1+2)) (.immediate ((188#8).signExtend 64)) (s.pc+4)) ∧
    decode #[0xc7,0x41,0x03,0x00,0x00,0x00,0x00] s = .ok
      (.move .w32 (.memory (s.gpr 1+3)) (.immediate 0) (s.pc+7)) ∧
    decode #[0xc6,0x41,0x07,0x00] s = .ok
      (.move .w8 (.memory (s.gpr 1+7)) (.immediate 0) (s.pc+4)) ∧
    decode #[0xb8,0x02,0x00,0x00,0x00] s = .ok
      (.move .w32 (.register (.low 0)) (.immediate 2) (s.pc+5)) := by
  refine ⟨?_,?_,?_,?_,?_⟩
  all_goals
    simp +decide [decode,prefixes,byteAt,operand,addressParts,signedDisplacement,registerCode,
      scalarWidth,scalarSlice,scalarSource,scalarDestination,ScalarWidth.bytes,ScalarWidth.bits,fallthrough,
      List.range'_succ,
      Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]


/-- Proof-only symbolic reduction through the single canonical decoder.
The quotation retains access to its private implementation names, allowing
external byte/extent certificates to compute without copying ISA semantics. -/
macro "canonical_x86_decode" : tactic =>
  `(tactic| simp +decide [decode,prefixes,byteAt,operand,addressParts,
    signedDisplacement,registerCode,scalarWidth,scalarSlice,scalarSource,
    scalarDestination,ScalarWidth.bytes,ScalarWidth.bits,fallthrough,integerBinary,
    Instruction.fallthrough,List.range'_succ,Except.bind,Except.map,Except.pure,
    Bind.bind,Pure.pure,Except.instMonad])


/-- Concrete C9 decodes at any code origin without a supplied operand/step. -/
theorem leave64_decode (s : State) :
    decode #[(0xc9 : Byte)] s = .ok (.leave64 (s.pc + 1)) := by rfl

/-- Complete successful LEAVE result, retaining the original ordered read. -/
theorem leave64_read_success (nextPc value : Word) (event : Event) (s : State)
    (canonical : leave64FrameCanonical s = true)
    (read : readMemory s.memory (s.gpr 5) 8 = .ok (value, event)) :
    step (.leave64 nextPc) s =
      ⟨{ s with gpr := (fun r => if r = 4 then s.gpr 5 + 8 else if r = 5 then value else s.gpr r), pc := nextPc }, [event], none⟩ := by
  simp only [step, leave64Step, canonical, ↓reduceIte, read]

/-- A failed frame read changes no architectural state, including old RSP. -/
theorem leave64_read_fault (nextPc : Word) (fault : Fault) (s : State)
    (canonical : leave64FrameCanonical s = true)
    (read : readMemory s.memory (s.gpr 5) 8 = .error fault) :
    step (.leave64 nextPc) s = ⟨s, [.fault fault], some fault⟩ := by
  simp only [step, leave64Step, canonical, ↓reduceIte, read]

theorem leave64_unreadable (nextPc : Word) (s : State)
    (canonical : leave64FrameCanonical s = true)
    (denied : permitted s.memory.readable (s.gpr 5) 8 = false) :
    step (.leave64 nextPc) s = ⟨s, [.fault (.read (s.gpr 5) 8)], some (.read (s.gpr 5) 8)⟩ := by
  simp only [step, leave64Step, canonical, readMemory, denied, Bool.false_eq_true, ↓reduceIte]

/-- The stack-address fault has no read effect and changes no state. -/
theorem leave64_noncanonical (nextPc : Word) (s : State)
    (noncanonical : leave64FrameCanonical s = false) :
    step (.leave64 nextPc) s =
      ⟨s, [.fault (.nonCanonical (s.gpr 5))], some (.nonCanonical (s.gpr 5))⟩ := by
  simp only [step, leave64Step, noncanonical, Bool.false_eq_true, ↓reduceIte]

/-- Memory and all flags are preserved on every outcome; no delivery RF or
write effect is manufactured by the ISA step. -/
theorem leave64_memory_flags (nextPc : Word) (s : State) :
    (step (.leave64 nextPc) s).state.memory = s.memory ∧
      (step (.leave64 nextPc) s).state.rflags = s.rflags := by
  simp only [step, leave64Step]
  split
  · cases read : readMemory s.memory (s.gpr 5) 8 with
    | error fault => exact ⟨rfl, rfl⟩
    | ok pair => exact ⟨rfl, rfl⟩
  · exact ⟨rfl, rfl⟩

end KProgFormal.Reference.X86

namespace KProgFormal.Reference.X86
/-- UD2 is an unconditional invalid-opcode fault before exception delivery.
Its encoded extent is separate from the unchanged faulting PC/state. -/
theorem ud2_step (nextPc : Word) (state : State) :
    step (.ud2 nextPc) state = ⟨state, [.fault .invalidOpcode], some .invalidOpcode⟩ := rfl

theorem ud2_decodes (state : State) :
    decode #[0x0f, 0x0b] state = .ok (.ud2 (state.pc + 2)) := by rfl

theorem ud2_refines (nextPc : Word) (state : State) :
    Step (.ud2 nextPc) state ⟨state, [.fault .invalidOpcode], some .invalidOpcode⟩ := by
  exact ⟨rfl, rfl, rfl⟩
end KProgFormal.Reference.X86
#print axioms KProgFormal.Reference.X86.ud2_step
#print axioms KProgFormal.Reference.X86.ud2_decodes
#print axioms KProgFormal.Reference.X86.ud2_refines
