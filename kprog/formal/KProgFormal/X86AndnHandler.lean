import KProgFormal.GeneratedX86Andn
import KProgFormal.TagErasure
import KProgFormal.X86LogicFlags
import KProgFormal.X86MemAccess
import KProgFormal.X86RegWrite
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Andn (Op Source source resolveWidth writeWidthDefault
  MemWidthArm memWidthArm)
open GeneratedX86Store (Code)

/-- The two `ANDN` opcodes this contract spans: `X86_OP_ANDN` (`0x3d`) reads its
second operand from a register, `X86_OP_ANDN_MEM` (`0x44`) reads it from memory. -/
inductive X86AndnOp
  | andn
  | andnMem
  deriving DecidableEq, Repr

/-- Bridge to the generated opcode table. -/
def x86AndnToOp : X86AndnOp -> GeneratedX86Andn.Op
  | .andn => .andn
  | .andnMem => .andnMem

/-- Independent statement of where each opcode reads its second operand. -/
def x86AndnSourceSpec : X86AndnOp -> Source
  | .andn => .registerRead
  | .andnMem => .memoryRead

/-- The generated source table agrees with the independent statement. -/
theorem x86_andn_source_refines (op : X86AndnOp) :
    source (x86AndnToOp op) = x86AndnSourceSpec op := by
  cases op <;> rfl

/-- The two opcodes read their second operand from *different* places: one a
register read, one a memory read, so neither row is dead and the memory width
only ever applies to the memory form. -/
theorem x86_andn_sources_differ :
    x86AndnSourceSpec .andn = Source.registerRead ∧
      x86AndnSourceSpec .andnMem = Source.memoryRead ∧
      x86AndnSourceSpec .andn ≠ x86AndnSourceSpec .andnMem := by
  exact ⟨rfl, rfl, fun h => by cases h⟩

/-- The width a `FLAGS` code names, restated independently: the code itself,
with the absent code resolving to the 64-bit width. Both the destination write
width and the memory-width fallback use this one mapping. -/
def x86AndnCodeWidthSpec : Code -> X86Width
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The destination *write* width both bodies use: the opcode's `FLAGS` code
itself, or 64 bits when it carries none. -/
def x86AndnWriteWidthSpec : Code -> X86Width := x86AndnCodeWidthSpec

/-- The write width the generated `resolveWidth` table selects, restated. -/
def generatedX86AndnWriteWidth (flags : Code) : X86Width :=
  match resolveWidth flags with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated write width equals the independent statement, for every
`FLAGS` code. -/
theorem x86_andn_write_width_refines (flags : Code) :
    generatedX86AndnWriteWidth flags = x86AndnWriteWidthSpec flags := by
  cases flags <;> rfl

/-- An absent `FLAGS` code resolves the write width to 64 bits. -/
theorem x86_andn_write_width_default_refines :
    generatedX86AndnWriteWidth .absent = .w64 := by
  rfl

/-- **The independently selected memory-read width.** The memory form reads its
second operand at `X86_MEM_AUX_MEM_WIDTH(AUX)`: the field's own width when the
AUX code names one (the `auxField` arm), and the *resolved `FLAGS` write width*
— not the raw `FLAGS` code — when the field is absent (the `flagsFallback`
arm). -/
def x86AndnMemWidthSpec (auxCode flagsCode : Code) : X86Width :=
  match memWidthArm auxCode with
  | .auxField => x86AndnCodeWidthSpec auxCode
  | .flagsFallback => x86AndnWriteWidthSpec flagsCode

/-- The AUX code's own width: the code itself, or 64 bits when it carries
none — the same mapping the write width uses, restated for the AUX field. -/
def generatedX86AndnCodeWidth (auxCode : Code) : X86Width :=
  match resolveWidth auxCode with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated AUX width equals the independent code-width statement. -/
theorem x86_andn_code_width_refines (auxCode : Code) :
    generatedX86AndnCodeWidth auxCode = x86AndnCodeWidthSpec auxCode := by
  cases auxCode <;> rfl

/-- The memory-read width the generated tables select, restated. -/
def generatedX86AndnMemWidth (auxCode flagsCode : Code) : X86Width :=
  match memWidthArm auxCode with
  | .auxField => generatedX86AndnCodeWidth auxCode
  | .flagsFallback => generatedX86AndnWriteWidth flagsCode

/-- The generated memory width equals the independent statement, for every AUX
field code and `FLAGS` code. -/
theorem x86_andn_mem_width_refines (auxCode flagsCode : Code) :
    generatedX86AndnMemWidth auxCode flagsCode =
      x86AndnMemWidthSpec auxCode flagsCode := by
  cases auxCode <;> cases flagsCode <;> rfl

/-- The memory-width arm is chosen by the AUX code alone, not by any opcode
fact: the absent code takes the `FLAGS` fallback, every width code takes its own
width. -/
theorem x86_andn_mem_width_arm_refines (auxCode : Code) :
    memWidthArm auxCode =
      (match auxCode with
       | .absent => MemWidthArm.flagsFallback
       | _ => MemWidthArm.auxField) := by
  cases auxCode <;> rfl

/-- **The headline asymmetry.** The memory-read width is *not* the destination
write width: a body whose `FLAGS` code names a 16-bit write but whose AUX field
names a 64-bit read reads eight bytes while writing two. Reading the write width
as the memory width (or vice versa) is the confusion this contract pins away. -/
theorem x86_andn_mem_width_differs_from_write_width :
    x86AndnWriteWidthSpec .b16 = .w16 ∧
      x86AndnMemWidthSpec .b64 .b16 = .w64 ∧
      x86AndnMemWidthSpec .b64 .b16 ≠ x86AndnWriteWidthSpec .b16 := by
  exact ⟨rfl, rfl, fun h => by cases h⟩

/-- When the AUX field is absent, the memory read *does* fall back to the
resolved `FLAGS` write width — and the fallback is the resolved width, so an
absent `FLAGS` code falls back to the 64-bit default. -/
theorem x86_andn_mem_width_fallback_is_resolved_write_width :
    x86AndnMemWidthSpec .absent .absent = .w64 ∧
      x86AndnMemWidthSpec .absent .b32 = .w32 := by
  exact ⟨rfl, rfl⟩

/-- Independent statement of the `ANDN` result: the bitwise complement of the
first operand, and-ed with the second operand. -/
def x86AndnResultSpec (src1 src2 : BitVec 64) : BitVec 64 :=
  BitVec.and (BitVec.not src1) src2

/-- The result the generated body computes, restated. -/
def generatedX86AndnResult (src1 src2 : BitVec 64) : BitVec 64 :=
  BitVec.and (BitVec.not src1) src2

/-- The generated result equals the independent statement. -/
theorem x86_andn_result_refines (src1 src2 : BitVec 64) :
    generatedX86AndnResult src1 src2 = x86AndnResultSpec src1 src2 := by
  rfl

/-- Independent statement of the second operand: the register read for `ANDN`,
the memory load at the memory width for `ANDN_MEM`. -/
def x86AndnSecondSpec (op : X86AndnOp) (src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (memWidth : X86Width) : BitVec 64 :=
  match x86AndnSourceSpec op with
  | .registerRead => src2reg
  | .memoryRead => x86MemLoadSpec byte memWidth

/-- The second operand the generated body reads, restated. -/
def generatedX86AndnSecond (op : X86AndnOp) (src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (memWidth : X86Width) : BitVec 64 :=
  match source (x86AndnToOp op) with
  | .registerRead => src2reg
  | .memoryRead => GeneratedX86MemAccess.load byte memWidth

/-- The generated second operand equals the independent statement, for every
opcode, register value, byte function, and memory width. -/
theorem x86_andn_second_refines (op : X86AndnOp) (src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (memWidth : X86Width) :
    generatedX86AndnSecond op src2reg byte memWidth =
      x86AndnSecondSpec op src2reg byte memWidth := by
  cases op <;>
    simp only [generatedX86AndnSecond, x86AndnSecondSpec, source, x86AndnToOp,
      x86AndnSourceSpec] <;>
    rw [x86_mem_load_refines]

/-- The two opcodes read their second operand from different places. -/
theorem x86_andn_second_sources (src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (memWidth : X86Width) :
    x86AndnSecondSpec .andn src2reg byte memWidth = src2reg ∧
      x86AndnSecondSpec .andnMem src2reg byte memWidth =
        x86MemLoadSpec byte memWidth := by
  exact ⟨rfl, rfl⟩

/-- The logic flags an `ANDN` body produces: `CF = OF = 0`, `ZF` the
width-narrowed result's zero test, `SF` its top-bit test — the shared logic-flag
production, applied at the write width. -/
def x86AndnFlagsSpec (result : BitVec 64) (width : X86Width) : X86Flags :=
  x86LogicFlagsSpec (x86ZeroSpec result width) (x86SignSpec result width)

/-- The flags the generated body produces, restated. -/
def generatedX86AndnFlags (result : BitVec 64) (width : X86Width) : X86Flags :=
  generatedX86LogicFlags (GeneratedX86Width.zero result width)
    (GeneratedX86Width.sign result width)

/-- The generated flags equal the independent statement, for every result and
write width. -/
theorem x86_andn_flags_refines (result : BitVec 64) (width : X86Width) :
    generatedX86AndnFlags result width = x86AndnFlagsSpec result width := by
  simp only [generatedX86AndnFlags, x86AndnFlagsSpec]
  rw [x86_logic_flags_refine, x86_zero_refines, x86_sign_refines]

/-- `ANDN` clears `CF` and `OF` outright, whatever the result and width. -/
theorem x86_andn_clears_cf_of (result : BitVec 64) (width : X86Width) :
    (x86AndnFlagsSpec result width).cf = false ∧
      (x86AndnFlagsSpec result width).of = false := by
  exact ⟨rfl, rfl⟩

/-- The effect of one `ANDN`/`ANDN_MEM` body. `source` records where the second
operand came from, `writeWidth` the destination write width, `memWidth` the
memory-read width the memory form uses (`none` for the register form), `src1`
the first operand, `result` the `(~src1) & src2` value, `flags` the logic flags,
and `dst` the destination register the body writes. -/
structure X86AndnEffect where
  source : Source
  writeWidth : X86Width
  memWidth : Option X86Width
  src1 : BitVec 64
  result : BitVec 64
  flags : X86Flags
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- The composed handler transition used by both bodies: the generated tables
select the second-operand source, the `FLAGS`-resolved write width, and the
independently selected memory width; the result is `(~src1) & src2`; the flags
are the shared logic-flag production at the write width; the destination is
written through the partial-register primitive at the write width. -/
def generatedX86AndnStep (op : X86AndnOp) (flagsCode auxCode : Code)
    (src1 src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) : X86AndnEffect :=
  let writeWidth := generatedX86AndnWriteWidth flagsCode
  let memWidth := generatedX86AndnMemWidth auxCode flagsCode
  let src2 := generatedX86AndnSecond op src2reg byte memWidth
  let result := generatedX86AndnResult src1 src2
  { source := source (x86AndnToOp op),
    writeWidth := writeWidth,
    memWidth := match source (x86AndnToOp op) with
      | .registerRead => none
      | .memoryRead => some memWidth,
    src1 := src1, result := result,
    flags := generatedX86AndnFlags result writeWidth,
    dst := generatedX86RegWrite dstOld result writeWidth }

/-- Independent statement of the same handler, reading the source, the write
width, the memory width, the second operand, the result, the flags, and the
destination write from the independent statements. -/
def x86AndnStepSpec (op : X86AndnOp) (flagsCode auxCode : Code)
    (src1 src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) : X86AndnEffect :=
  let writeWidth := x86AndnWriteWidthSpec flagsCode
  let memWidth := x86AndnMemWidthSpec auxCode flagsCode
  let src2 := x86AndnSecondSpec op src2reg byte memWidth
  let result := x86AndnResultSpec src1 src2
  { source := x86AndnSourceSpec op,
    writeWidth := writeWidth,
    memWidth := match x86AndnSourceSpec op with
      | .registerRead => none
      | .memoryRead => some memWidth,
    src1 := src1, result := result,
    flags := x86AndnFlagsSpec result writeWidth,
    dst := x86RegWriteSpec dstOld result writeWidth }

/-- The `ANDN` / `ANDN_MEM` handler composition refines the independent source /
width / result / flags / writeback statement for every opcode, `FLAGS` and AUX
codes, AUX presence, first operand, register second operand, byte function, and
destination register. -/
theorem x86_andn_step_refines (op : X86AndnOp) (flagsCode auxCode : Code)
    (src1 src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) :
    generatedX86AndnStep op flagsCode auxCode src1 src2reg byte dstOld =
      x86AndnStepSpec op flagsCode auxCode src1 src2reg byte dstOld := by
  cases op <;> cases flagsCode <;> cases auxCode <;>
    simp only [generatedX86AndnStep, x86AndnStepSpec, source, x86AndnToOp,
      x86AndnSourceSpec, generatedX86AndnWriteWidth, resolveWidth,
      x86AndnWriteWidthSpec, x86AndnCodeWidthSpec, generatedX86AndnCodeWidth,
      generatedX86AndnMemWidth, memWidthArm, x86AndnMemWidthSpec,
      generatedX86AndnSecond, x86AndnSecondSpec, generatedX86AndnResult,
      x86AndnResultSpec, generatedX86AndnFlags, x86AndnFlagsSpec,
      x86_mem_load_refines, x86_logic_flags_refine, x86_zero_refines,
      x86_sign_refines, x86_reg_write_refines]

/-- The destination write width is the `FLAGS`-resolved width, for both bodies. -/
theorem x86_andn_write_width_is_flags_resolved (op : X86AndnOp)
    (flagsCode auxCode : Code) (src1 src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) :
    (x86AndnStepSpec op flagsCode auxCode src1 src2reg byte dstOld).writeWidth =
      x86AndnWriteWidthSpec flagsCode := by
  rfl

/-- The register form carries no memory width, and the memory form carries the
independently selected one. -/
theorem x86_andn_mem_width_presence (flagsCode auxCode : Code)
    (src1 src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) :
    (x86AndnStepSpec .andn flagsCode auxCode src1 src2reg byte dstOld).memWidth =
        none ∧
      (x86AndnStepSpec .andnMem flagsCode auxCode src1 src2reg byte
        dstOld).memWidth = some (x86AndnMemWidthSpec auxCode flagsCode) := by
  exact ⟨rfl, rfl⟩

/-- Neither body writes a memory byte: the memory form only reads, and both
write their destination register. -/
theorem x86_andn_writes_no_memory (flagsCode auxCode : Code)
    (src1 src2reg : BitVec 64)
    (byte : Nat -> X86MemByte) (dstOld : X86RegValue) :
    (x86AndnStepSpec .andnMem flagsCode auxCode src1 src2reg byte
      dstOld).result =
        BitVec.and (BitVec.not src1)
          (x86MemLoadSpec byte (x86AndnMemWidthSpec auxCode flagsCode)) := by
  rfl

/-- Canonical example: the register form computes the complement-and at the
resolved width, clears `CF`/`OF`, and writes the destination. -/
theorem x86_andn_example :
    (x86AndnStepSpec .andn .b64 .b64 0xff00 0x0ff0
      (fun _ => 0) ⟨0, .scalar⟩).result = 0x00f0 ∧
      (x86AndnStepSpec .andn .b64 .b64 0xff00 0x0ff0
        (fun _ => 0) ⟨0, .scalar⟩).writeWidth = .w64 ∧
      (x86AndnStepSpec .andn .b64 .b64 0xff00 0x0ff0
        (fun _ => 0) ⟨0, .scalar⟩).flags =
        { cf := false, zf := false, sf := false, of := false } ∧
      (x86AndnStepSpec .andn .b64 .b64 0xff00 0x0ff0
        (fun _ => 0) ⟨0, .scalar⟩).memWidth = none := by
  refine ⟨?_, rfl, ?_, rfl⟩
  · simp only [x86AndnStepSpec, x86AndnSourceSpec, x86AndnSecondSpec,
      x86AndnWriteWidthSpec, x86AndnCodeWidthSpec, x86AndnResultSpec]
    decide
  · simp only [x86AndnStepSpec, x86AndnSourceSpec, x86AndnSecondSpec,
      x86AndnWriteWidthSpec, x86AndnCodeWidthSpec, x86AndnResultSpec,
      x86AndnFlagsSpec, x86LogicFlagsSpec, x86ZeroSpec, x86SignSpec,
      x86NarrowSpec, x86WidthMaskSpec, x86WidthBitsSpec]
    decide

/-- Canonical example: the memory form reads at its own width and writes at the
`FLAGS` width, and the two widths can be different. -/
theorem x86_andn_mem_asymmetry_example :
    (x86AndnStepSpec .andnMem .b16 .b64 0xffff 0xdead
      (fun _ => 0) ⟨0, .scalar⟩).writeWidth = .w16 ∧
      (x86AndnStepSpec .andnMem .b16 .b64 0xffff 0xdead
        (fun _ => 0) ⟨0, .scalar⟩).memWidth = some .w64 := by
  refine ⟨rfl, ?_⟩
  simp only [x86AndnStepSpec, x86AndnSourceSpec, x86AndnMemWidthSpec,
    memWidthArm, x86AndnWriteWidthSpec, x86AndnCodeWidthSpec]

end KProgFormal
