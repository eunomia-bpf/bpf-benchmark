import KProgFormal.GeneratedX86Bzhi
import KProgFormal.X86LogicFlags
import KProgFormal.X86Bitops
import KProgFormal.TagErasure
import KProgFormal.X86MemAccess
import KProgFormal.X86RegWrite
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Bzhi (Op ValueSource CountSource valueSource countSource
  resolveWidth writeWidthDefault)
open GeneratedX86Store (Code)

/-- The two `BZHI` opcodes this contract spans: `X86_OP_BZHI` (`0x34`) reads its
value from `SRC` and its count from `COUNT`, `X86_OP_BZHI_MEM` (`0x35`) reads its
value from memory and its count from the register the AUX shift byte names. -/
inductive X86BzhiOp
  | bzhi
  | bzhiMem
  deriving DecidableEq, Repr

/-- Bridge to the generated opcode table. -/
def x86BzhiToOp : X86BzhiOp -> GeneratedX86Bzhi.Op
  | .bzhi => .bzhi
  | .bzhiMem => .bzhiMem

/-- Independent statement of where each opcode reads its value. -/
def x86BzhiValueSourceSpec : X86BzhiOp -> ValueSource
  | .bzhi => .registerRead
  | .bzhiMem => .memoryRead

/-- Independent statement of where each opcode reads its bit count. -/
def x86BzhiCountSourceSpec : X86BzhiOp -> CountSource
  | .bzhi => .register
  | .bzhiMem => .auxShift

/-- The generated value-source table agrees with the independent statement. -/
theorem x86_bzhi_value_source_refines (op : X86BzhiOp) :
    valueSource (x86BzhiToOp op) = x86BzhiValueSourceSpec op := by
  cases op <;> rfl

/-- The generated count-source table agrees with the independent statement. -/
theorem x86_bzhi_count_source_refines (op : X86BzhiOp) :
    countSource (x86BzhiToOp op) = x86BzhiCountSourceSpec op := by
  cases op <;> rfl

/-- The two opcodes read their value from *different* places: one a register
read, one a memory read, so neither value-source row is dead. -/
theorem x86_bzhi_value_sources_differ :
    x86BzhiValueSourceSpec .bzhi = ValueSource.registerRead ∧
      x86BzhiValueSourceSpec .bzhiMem = ValueSource.memoryRead ∧
      x86BzhiValueSourceSpec .bzhi ≠ x86BzhiValueSourceSpec .bzhiMem := by
  exact ⟨rfl, rfl, fun h => by cases h⟩

/-- The two opcodes read their count from *different* places: one the `COUNT`
register, one the register the AUX shift byte names, so neither count-source row
is dead. -/
theorem x86_bzhi_count_sources_differ :
    x86BzhiCountSourceSpec .bzhi = CountSource.register ∧
      x86BzhiCountSourceSpec .bzhiMem = CountSource.auxShift ∧
      x86BzhiCountSourceSpec .bzhi ≠ x86BzhiCountSourceSpec .bzhiMem := by
  exact ⟨rfl, rfl, fun h => by cases h⟩

/-- The width a `FLAGS` code names, restated independently: the code itself,
with the absent code resolving to the 64-bit width. -/
def x86BzhiCodeWidthSpec : Code -> X86Width
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The one width both BZHI bodies resolve: the opcode's `FLAGS` code itself, or
64 bits when it carries none. The *same* width serves the value read, the count
comparison, and the destination write - unlike `ANDN_MEM`, there is no second
independently selected memory width. -/
def x86BzhiWidthSpec : Code -> X86Width := x86BzhiCodeWidthSpec

/-- The width the generated `resolveWidth` table selects, restated. -/
def generatedX86BzhiWidth (flags : Code) : X86Width :=
  match resolveWidth flags with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated resolved width equals the independent statement, for every
`FLAGS` code. -/
theorem x86_bzhi_width_refines (flags : Code) :
    generatedX86BzhiWidth flags = x86BzhiWidthSpec flags := by
  cases flags <;> rfl

/-- An absent `FLAGS` code resolves the width to 64 bits. -/
theorem x86_bzhi_width_default_refines :
    generatedX86BzhiWidth .absent = .w64 := by
  rfl

/-- Independent statement of the value a body clears bits from: the `SRC`
register read for `BZHI`, the memory load *at the resolved width* for
`BZHI_MEM`. -/
def x86BzhiValueSpec (op : X86BzhiOp) (srcReg : BitVec 64)
    (byte : Nat -> X86MemByte) (width : X86Width) : BitVec 64 :=
  match x86BzhiValueSourceSpec op with
  | .registerRead => srcReg
  | .memoryRead => x86MemLoadSpec byte width

/-- The value the generated body reads, restated. -/
def generatedX86BzhiValue (op : X86BzhiOp) (srcReg : BitVec 64)
    (byte : Nat -> X86MemByte) (width : X86Width) : BitVec 64 :=
  match valueSource (x86BzhiToOp op) with
  | .registerRead => srcReg
  | .memoryRead => GeneratedX86MemAccess.load byte width

/-- The generated value equals the independent statement, for every opcode,
register value, byte function, and resolved width. -/
theorem x86_bzhi_value_refines (op : X86BzhiOp) (srcReg : BitVec 64)
    (byte : Nat -> X86MemByte) (width : X86Width) :
    generatedX86BzhiValue op srcReg byte width =
      x86BzhiValueSpec op srcReg byte width := by
  cases op <;>
    simp only [generatedX86BzhiValue, x86BzhiValueSpec, valueSource, x86BzhiToOp,
      x86BzhiValueSourceSpec] <;>
    rw [x86_mem_load_refines]

/-- The two opcodes read their value from different places. -/
theorem x86_bzhi_value_sources (srcReg : BitVec 64)
    (byte : Nat -> X86MemByte) (width : X86Width) :
    x86BzhiValueSpec .bzhi srcReg byte width = srcReg ∧
      x86BzhiValueSpec .bzhiMem srcReg byte width =
        x86MemLoadSpec byte width := by
  exact ⟨rfl, rfl⟩

/-- The byte-masked count, as both bodies compute it: the count register read
`& 0xff`. -/
def x86BzhiCountSpec (raw : BitVec 64) : BitVec 64 := raw &&& 0xff

/-- The byte mask the count is narrowed by. -/
def x86BzhiCountMaskSpec : BitVec 64 := 0xff

/-- The byte-masked count equals the independent mask statement. -/
theorem x86_bzhi_count_refines (raw : BitVec 64) :
    x86BzhiCountSpec raw = raw &&& x86BzhiCountMaskSpec := by
  rfl

/-- A count register holding a value above the byte range behaves as its low
byte: `0x1ff` masks to `0xff`. This is the byte truncation both bodies apply
before the width comparison. -/
theorem x86_bzhi_count_masks_to_byte :
    x86BzhiCountSpec 0x1ff = 0xff ∧
      x86BzhiCountSpec 0x100 = 0x00 ∧
      x86BzhiCountSpec 0x1ff ≠ 0x1ff := by
  refine ⟨?_, ?_, ?_⟩ <;> decide

/-- Independent statement of the bit count a body compares against the width:
the `COUNT` register read for `BZHI`, the AUX-shift-named register read for
`BZHI_MEM`, each masked to its low byte. -/
def x86BzhiCountReadSpec (op : X86BzhiOp) (countReg auxCountReg : BitVec 64) :
    BitVec 64 :=
  match x86BzhiCountSourceSpec op with
  | .register => x86BzhiCountSpec countReg
  | .auxShift => x86BzhiCountSpec auxCountReg

/-- The count the generated body reads, restated. -/
def generatedX86BzhiCount (op : X86BzhiOp) (countReg auxCountReg : BitVec 64) :
    BitVec 64 :=
  match countSource (x86BzhiToOp op) with
  | .register => countReg &&& 0xff
  | .auxShift => auxCountReg &&& 0xff

/-- The generated count equals the independent statement, for every opcode and
count register value. -/
theorem x86_bzhi_count_read_refines (op : X86BzhiOp)
    (countReg auxCountReg : BitVec 64) :
    generatedX86BzhiCount op countReg auxCountReg =
      x86BzhiCountReadSpec op countReg auxCountReg := by
  cases op <;>
    simp only [generatedX86BzhiCount, x86BzhiCountReadSpec, countSource,
      x86BzhiToOp, x86BzhiCountSourceSpec, x86BzhiCountSpec]

/-- The two opcodes read their count from different registers: `BZHI` from
`COUNT`, `BZHI_MEM` from the AUX-shift-named register. -/
theorem x86_bzhi_count_sources (countReg auxCountReg : BitVec 64) :
    x86BzhiCountReadSpec .bzhi countReg auxCountReg =
        x86BzhiCountSpec countReg ∧
      x86BzhiCountReadSpec .bzhiMem countReg auxCountReg =
        x86BzhiCountSpec auxCountReg := by
  exact ⟨rfl, rfl⟩

/-- Independent statement of the result: the resolved-width narrowing of the
source with the bits at or above the byte-masked count cleared. -/
def x86BzhiResultSpec (src count : BitVec 64) (width : X86Width) : BitVec 64 :=
  x86BzhiSpec src count (x86WidthCodeSpec width)

/-- The result the generated body computes, restated. -/
def generatedX86BzhiResult (src count : BitVec 64) (width : X86Width) :
    BitVec 64 :=
  GeneratedX86Bitops.bzhi src count (GeneratedX86Width.code width)

/-- The generated result equals the independent statement, for every source,
count, and resolved width. -/
theorem x86_bzhi_result_refines (src count : BitVec 64) (width : X86Width) :
    generatedX86BzhiResult src count width =
      x86BzhiResultSpec src count width := by
  simp only [generatedX86BzhiResult, x86BzhiResultSpec]
  rw [x86_bzhi_refines_width]

/-- **The headline flag asymmetry.** A BZHI body defines its flags by hand
rather than through the shared logic-flag production: `OF = 0`, `SF = 0`
*outright* even when the result's top bit is set, `ZF` the real zero test of the
result, and `CF` the comparison of the *byte-masked count* against the width's
bit count. SF is therefore *not* the sign of the result, and `CF` is derived
from the width rather than from the value written. -/
def x86BzhiFlagsSpec (count result : BitVec 64) (width : X86Width) : X86Flags :=
  { cf := BitVec.ule (BitVec.ofNat 64 (x86WidthBitsSpec width)) count,
    zf := result == 0,
    sf := false,
    of := false }

/-- The flags the generated body produces, restated. -/
def generatedX86BzhiFlags (count result : BitVec 64) (width : X86Width) :
    X86Flags :=
  { cf := BitVec.ule (BitVec.ofNat 64 (GeneratedX86Width.bits width)) count,
    zf := result == 0,
    sf := false,
    of := false }

/-- The generated flags equal the independent statement, for every count, result,
and resolved width. -/
theorem x86_bzhi_flags_refines (count result : BitVec 64) (width : X86Width) :
    generatedX86BzhiFlags count result width =
      x86BzhiFlagsSpec count result width := by
  simp only [generatedX86BzhiFlags, x86BzhiFlagsSpec]
  rw [x86_width_bits_refines]

/-- BZHI clears `SF` and `OF` outright, whatever the count, result, and width -
`SF` is *not* the sign of the result, unlike the shared logic-flag production. -/
theorem x86_bzhi_clears_sf_of (count result : BitVec 64) (width : X86Width) :
    (x86BzhiFlagsSpec count result width).sf = false ∧
      (x86BzhiFlagsSpec count result width).of = false := by
  exact ⟨rfl, rfl⟩

/-- `CF` is the byte-masked count reaching the *width's* bit count, not any
property of the result: an 8-bit BZHI reports CF at count 8, while a 64-bit one
does not. Same count, same source, different width - a different carry. -/
theorem x86_bzhi_cf_is_count_versus_width (result : BitVec 64) :
    (x86BzhiFlagsSpec 8 result .w8).cf = true ∧
      (x86BzhiFlagsSpec 8 result .w64).cf = false := by
  refine ⟨?_, ?_⟩ <;> simp only [x86BzhiFlagsSpec, x86WidthBitsSpec] <;> decide

/-- `ZF` is the real zero test of the cleared value; `SF` stays false even when
the result's top bit is set, so the two disagree. -/
theorem x86_bzhi_zf_real_sf_cleared :
    (x86BzhiFlagsSpec 4 0 .w8).zf = true ∧
      (x86BzhiFlagsSpec 4 0x80 .w8).sf = false ∧
      x86SignSpec 0x80 .w8 = true := by
  refine ⟨?_, ?_, ?_⟩ <;>
    simp only [x86BzhiFlagsSpec, x86SignSpec, x86NarrowSpec, x86WidthMaskSpec,
      x86WidthBitsSpec] <;> decide

/-- The effect of one `BZHI`/`BZHI_MEM` body. `valueSource` records where the
bit source came from, `countSource` where the count came from, `width` the one
resolved width, `count` the byte-masked count, `result` the cleared value,
`flags` the hand-defined flags, and `dst` the destination register the body
writes. -/
structure X86BzhiEffect where
  valueSource : ValueSource
  countSource : CountSource
  width : X86Width
  count : BitVec 64
  result : BitVec 64
  flags : X86Flags
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- The composed handler transition used by both bodies: the generated tables
select the value source, the count source, and the one `FLAGS`-resolved width;
the value is the register read or the memory load at that width; the count is
the selected register read masked to its low byte; the result is the generated
`bzhi` at the resolved width; the flags are hand-defined (CF from the count and
the width's bit count, SF=OF=0, ZF the zero test); the destination is written
through the partial-register primitive at the resolved width. -/
def generatedX86BzhiStep (op : X86BzhiOp) (flagsCode : Code)
    (srcReg countReg auxCountReg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) : X86BzhiEffect :=
  let width := generatedX86BzhiWidth flagsCode
  let value := generatedX86BzhiValue op srcReg byte width
  let count := generatedX86BzhiCount op countReg auxCountReg
  let result := generatedX86BzhiResult value count width
  { valueSource := valueSource (x86BzhiToOp op),
    countSource := countSource (x86BzhiToOp op),
    width := width, count := count, result := result,
    flags := generatedX86BzhiFlags count result width,
    dst := generatedX86RegWrite dstOld result width }

/-- Independent statement of the same handler, reading the value source, the
count source, the width, the value, the count, the result, the flags, and the
destination write from the independent statements. -/
def x86BzhiStepSpec (op : X86BzhiOp) (flagsCode : Code)
    (srcReg countReg auxCountReg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) : X86BzhiEffect :=
  let width := x86BzhiWidthSpec flagsCode
  let value := x86BzhiValueSpec op srcReg byte width
  let count := x86BzhiCountReadSpec op countReg auxCountReg
  let result := x86BzhiResultSpec value count width
  { valueSource := x86BzhiValueSourceSpec op,
    countSource := x86BzhiCountSourceSpec op,
    width := width, count := count, result := result,
    flags := x86BzhiFlagsSpec count result width,
    dst := x86RegWriteSpec dstOld result width }

/-- The `BZHI` / `BZHI_MEM` handler composition refines the independent value /
count / result / flags / writeback statement for every opcode, `FLAGS` code,
source register, count register, AUX count register, byte function, and
destination register. -/
theorem x86_bzhi_step_refines (op : X86BzhiOp) (flagsCode : Code)
    (srcReg countReg auxCountReg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) :
    generatedX86BzhiStep op flagsCode srcReg countReg auxCountReg byte dstOld =
      x86BzhiStepSpec op flagsCode srcReg countReg auxCountReg byte dstOld := by
  cases op <;> cases flagsCode <;>
    simp only [generatedX86BzhiStep, x86BzhiStepSpec, valueSource, countSource,
      x86BzhiToOp, x86BzhiValueSourceSpec, x86BzhiCountSourceSpec,
      generatedX86BzhiWidth, resolveWidth, x86BzhiWidthSpec, x86BzhiCodeWidthSpec,
      generatedX86BzhiValue, x86BzhiValueSpec, generatedX86BzhiCount,
      x86BzhiCountReadSpec, x86BzhiCountSpec, generatedX86BzhiResult,
      x86BzhiResultSpec, generatedX86BzhiFlags, x86BzhiFlagsSpec,
      x86_mem_load_refines, x86_bzhi_refines_width, x86_width_bits_refines,
      x86_reg_write_refines]

/-- The one resolved width serves both the value read and the destination write,
for both bodies - the same width, unlike `ANDN_MEM`'s separate memory width. -/
theorem x86_bzhi_width_is_both_widths (op : X86BzhiOp) (flagsCode : Code)
    (srcReg countReg auxCountReg : BitVec 64)
    (byte : Nat -> X86MemByte) : ∀ (dstOld : X86RegValue),
    (x86BzhiStepSpec op flagsCode srcReg countReg auxCountReg byte dstOld).width =
      x86BzhiWidthSpec flagsCode := by
  intro dstOld; rfl

/-- `BZHI_MEM` reads its value from memory at the resolved width, the same width
it writes. -/
theorem x86_bzhi_mem_reads_at_write_width (flagsCode : Code)
    (srcReg countReg auxCountReg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) :
    (x86BzhiStepSpec .bzhiMem flagsCode srcReg countReg auxCountReg byte
        dstOld).result =
      x86BzhiResultSpec (x86MemLoadSpec byte (x86BzhiWidthSpec flagsCode))
        (x86BzhiCountSpec auxCountReg) (x86BzhiWidthSpec flagsCode) := by
  rfl

/-- `BZHI` reads its count from `COUNT`; `BZHI_MEM` from the AUX-shift register.
The two effects record different count sources. -/
theorem x86_bzhi_count_source_effects (flagsCode : Code)
    (srcReg countReg auxCountReg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) :
    (x86BzhiStepSpec .bzhi flagsCode srcReg countReg auxCountReg byte
        dstOld).count = x86BzhiCountSpec countReg ∧
      (x86BzhiStepSpec .bzhiMem flagsCode srcReg countReg auxCountReg byte
        dstOld).count = x86BzhiCountSpec auxCountReg := by
  exact ⟨rfl, rfl⟩

/-- Canonical example: a `BZHI` whose count register holds `0x1ff` behaves as
`0xff`, keeping the whole source and reporting CF at any width. -/
theorem x86_bzhi_count_byte_truncation_example :
    (x86BzhiStepSpec .bzhi .b8 0xabcd 0x1ff 0  (fun _ => 0)
        { bits := 0, tag := .scalar }).result = 0xcd ∧
      (x86BzhiStepSpec .bzhi .b8 0xabcd 0x1ff 0 (fun _ => 0)
        { bits := 0, tag := .scalar }).flags.cf = true := by
  refine ⟨?_, ?_⟩ <;>
    simp only [x86BzhiStepSpec, x86BzhiWidthSpec, x86BzhiCodeWidthSpec,
      x86BzhiValueSpec, x86BzhiValueSourceSpec, x86BzhiCountReadSpec,
      x86BzhiCountSourceSpec, x86BzhiCountSpec, x86BzhiResultSpec, x86BzhiSpec,
      x86BitopsMaskCode, x86BzhiFlagsSpec, x86WidthBitsSpec,
      x86WidthCodeSpec] <;>
    decide

end KProgFormal
