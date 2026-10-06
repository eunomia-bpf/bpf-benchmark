import KProgFormal.GeneratedX86Bt
import KProgFormal.X86Bitops
import KProgFormal.X86Immediate
import KProgFormal.X86MemAccess
import KProgFormal.X86RegWrite
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Bt (Op BaseSource IndexSource baseSource indexSource
  resolveWidth writeWidthDefault)
open GeneratedX86Store (Code)

/-- The three `BT` opcodes this contract spans: `X86_OP_BT` (`0x37`) reads its
base and index from registers, `X86_OP_BT_IMM` (`0x42`) reads its base from a
register and its index from the immediate, `X86_OP_BT_MEM_IMM` (`0x43`) reads
its base from memory and its index from the immediate widened to 32 bits. -/
inductive X86BtOp
  | bt
  | btImm
  | btMemImm
  deriving DecidableEq, Repr

/-- Bridge to the generated opcode table. -/
def x86BtToOp : X86BtOp -> GeneratedX86Bt.Op
  | .bt => .bt
  | .btImm => .btImm
  | .btMemImm => .btMemImm

/-- Independent statement of where each opcode reads the tested base. -/
def x86BtBaseSourceSpec : X86BtOp -> BaseSource
  | .bt => .registerRead
  | .btImm => .registerRead
  | .btMemImm => .memoryRead

/-- Independent statement of where each opcode reads the bit index. -/
def x86BtIndexSourceSpec : X86BtOp -> IndexSource
  | .bt => .register
  | .btImm => .immediate
  | .btMemImm => .imm32

/-- The generated base-source table agrees with the independent statement. -/
theorem x86_bt_base_source_refines (op : X86BtOp) :
    baseSource (x86BtToOp op) = x86BtBaseSourceSpec op := by
  cases op <;> rfl

/-- The generated index-source table agrees with the independent statement. -/
theorem x86_bt_index_source_refines (op : X86BtOp) :
    indexSource (x86BtToOp op) = x86BtIndexSourceSpec op := by
  cases op <;> rfl

/-- Only the memory form reads its base from memory: the two register forms
share the register-read base source. -/
theorem x86_bt_base_sources (op : X86BtOp) :
    x86BtBaseSourceSpec op = BaseSource.memoryRead ↔ op = .btMemImm := by
  cases op <;> simp [x86BtBaseSourceSpec]

/-- The three opcodes read their bit index from three *different* places: a
register, the raw immediate, and the 32-bit immediate — so no row is dead. -/
theorem x86_bt_index_sources_differ :
    x86BtIndexSourceSpec .bt = IndexSource.register ∧
      x86BtIndexSourceSpec .btImm = IndexSource.immediate ∧
      x86BtIndexSourceSpec .btMemImm = IndexSource.imm32 ∧
      x86BtIndexSourceSpec .bt ≠ x86BtIndexSourceSpec .btImm ∧
      x86BtIndexSourceSpec .btImm ≠ x86BtIndexSourceSpec .btMemImm := by
  refine ⟨rfl, rfl, rfl, ?_, ?_⟩
  · intro h; cases h
  · intro h; cases h

/-- The width a `FLAGS` code names, restated independently: the code itself,
with the absent code resolving to the 64-bit width. -/
def x86BtCodeWidthSpec : Code -> X86Width
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The width every body narrows the tested base to: the opcode's `FLAGS` code
itself, or 64 bits when it carries none. -/
def x86BtWriteWidthSpec : Code -> X86Width := x86BtCodeWidthSpec

/-- The width the generated `resolveWidth` table selects, restated. -/
def generatedX86BtWriteWidth (flags : Code) : X86Width :=
  match resolveWidth flags with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated width equals the independent statement, for every `FLAGS`
code. -/
theorem x86_bt_write_width_refines (flags : Code) :
    generatedX86BtWriteWidth flags = x86BtWriteWidthSpec flags := by
  cases flags <;> rfl

/-- An absent `FLAGS` code resolves the width to 64 bits. -/
theorem x86_bt_write_width_default_refines :
    generatedX86BtWriteWidth .absent = .w64 := by
  rfl

/-- Independent statement of the tested base: the register read for the two
register forms, the memory load at the resolved width for the memory form. -/
def x86BtBaseSpec (op : X86BtOp) (baseReg : BitVec 64)
    (byte : Nat -> X86MemByte) (width : X86Width) : BitVec 64 :=
  match x86BtBaseSourceSpec op with
  | .registerRead => baseReg
  | .memoryRead => x86MemLoadSpec byte width

/-- The tested base the generated body reads, restated. -/
def generatedX86BtBase (op : X86BtOp) (baseReg : BitVec 64)
    (byte : Nat -> X86MemByte) (width : X86Width) : BitVec 64 :=
  match baseSource (x86BtToOp op) with
  | .registerRead => baseReg
  | .memoryRead => GeneratedX86MemAccess.load byte width

/-- The generated base equals the independent statement, for every opcode,
register value, byte function, and width. -/
theorem x86_bt_base_refines (op : X86BtOp) (baseReg : BitVec 64)
    (byte : Nat -> X86MemByte) (width : X86Width) :
    generatedX86BtBase op baseReg byte width =
      x86BtBaseSpec op baseReg byte width := by
  cases op <;>
    simp only [generatedX86BtBase, x86BtBaseSpec, baseSource, x86BtToOp,
      x86BtBaseSourceSpec] <;>
    rw [x86_mem_load_refines]

/-- Independent statement of the bit index: the register read for `BT`, the raw
64-bit immediate for `BT_IMM`, and the 32-bit-widened immediate for
`BT_MEM_IMM`. -/
def x86BtIndexSpec (op : X86BtOp) (indexReg rawImm : BitVec 64) : BitVec 64 :=
  match x86BtIndexSourceSpec op with
  | .register => indexReg
  | .immediate => rawImm
  | .imm32 => x86ImmediateValueSpec rawImm .w32

/-- The bit index the generated body reads, restated. -/
def generatedX86BtIndex (op : X86BtOp) (indexReg rawImm : BitVec 64) :
    BitVec 64 :=
  match indexSource (x86BtToOp op) with
  | .register => indexReg
  | .immediate => rawImm
  | .imm32 => GeneratedX86Immediate.value rawImm .w32

/-- The generated index equals the independent statement, for every opcode,
register index, and raw immediate. -/
theorem x86_bt_index_refines (op : X86BtOp) (indexReg rawImm : BitVec 64) :
    generatedX86BtIndex op indexReg rawImm =
      x86BtIndexSpec op indexReg rawImm := by
  cases op <;>
    simp only [generatedX86BtIndex, x86BtIndexSpec, indexSource, x86BtToOp,
      x86BtIndexSourceSpec] <;>
    rw [x86_immediate_value_refines]

/-- **The binding index-width asymmetry.** `BT_MEM_IMM` widens its immediate to
32 bits, while `BT`/`BT_IMM` consume the raw 64-bit field: an immediate with a
high bit set selects a different bit through the two paths — the memory form
drops the high bits, the immediate form does not. -/
theorem x86_bt_imm32_drops_high_bits :
    x86BtIndexSpec .btMemImm 0 0x100000001 = 1 ∧
      x86BtIndexSpec .btImm 0 0x100000001 = 0x100000001 ∧
      x86BtIndexSpec .btImm 0 0x100000001 ≠
        x86BtIndexSpec .btMemImm 0 0x100000001 := by
  refine ⟨?_, ?_, ?_⟩ <;> decide

/-- The tested bit the generated body computes, restated through the independent
`bt` contract at the resolved width. -/
def x86BtCfSpec (base index : BitVec 64) (width : X86Width) : Bool :=
  x86BtSpec base index (x86WidthCodeSpec width)

/-- The tested bit the generated body computes, restated. -/
def generatedX86BtCf (base index : BitVec 64) (width : X86Width) : Bool :=
  GeneratedX86Bitops.bt base index (GeneratedX86Width.code width)

/-- The generated carry equals the independent statement, for every base, index,
and width. -/
theorem x86_bt_cf_refines (base index : BitVec 64) (width : X86Width) :
    generatedX86BtCf base index width = x86BtCfSpec base index width := by
  simp only [generatedX86BtCf, x86BtCfSpec]
  rw [x86_bt_refines_width]

/-- The effect of one `BT`/`BT_IMM`/`BT_MEM_IMM` body. `baseSource` records
where the tested base came from, `indexSource` where the bit index came from,
`width` the narrowing width, `base`/`index` the resolved operands, `cf` the
indexed bit, `dst` the (unchanged) destination register, and `zf`/`sf`/`of` the
incoming flags the body leaves alone. -/
structure X86BtEffect where
  baseSource : BaseSource
  indexSource : IndexSource
  width : X86Width
  base : BitVec 64
  index : BitVec 64
  cf : Bool
  dst : X86RegValue
  zf : Bool
  sf : Bool
  of : Bool
  deriving DecidableEq, Repr

/-- The composed handler transition used by all three bodies: the generated
tables select the base source, the index source, and the `FLAGS`-resolved width;
the tested bit is the generated `bt` at that width; the destination register is
unchanged and only `CF` is written. -/
def generatedX86BtStep (op : X86BtOp) (flagsCode : Code)
    (baseReg indexReg rawImm : BitVec 64) (byte : Nat -> X86MemByte)
    (dstOld : X86RegValue) (zfOld sfOld ofOld : Bool) : X86BtEffect :=
  let width := generatedX86BtWriteWidth flagsCode
  let base := generatedX86BtBase op baseReg byte width
  let index := generatedX86BtIndex op indexReg rawImm
  let cf := generatedX86BtCf base index width
  { baseSource := baseSource (x86BtToOp op),
    indexSource := indexSource (x86BtToOp op),
    width := width, base := base, index := index, cf := cf,
    dst := dstOld, zf := zfOld, sf := sfOld, of := ofOld }

/-- Independent statement of the same handler, reading the base, the index, the
width, the tested bit, the flags, and the destination from the independent
statements. -/
def x86BtStepSpec (op : X86BtOp) (flagsCode : Code)
    (baseReg indexReg rawImm : BitVec 64) (byte : Nat -> X86MemByte)
    (dstOld : X86RegValue) (zfOld sfOld ofOld : Bool) : X86BtEffect :=
  let width := x86BtWriteWidthSpec flagsCode
  let base := x86BtBaseSpec op baseReg byte width
  let index := x86BtIndexSpec op indexReg rawImm
  let cf := x86BtCfSpec base index width
  { baseSource := x86BtBaseSourceSpec op,
    indexSource := x86BtIndexSourceSpec op,
    width := width, base := base, index := index, cf := cf,
    dst := dstOld, zf := zfOld, sf := sfOld, of := ofOld }

/-- The `BT` / `BT_IMM` / `BT_MEM_IMM` handler composition refines the
independent base/index/width/test/writeback statement for every opcode, `FLAGS`
code, register operands, raw immediate, byte function, destination register, and
incoming flags. -/
theorem x86_bt_step_refines (op : X86BtOp) (flagsCode : Code)
    (baseReg indexReg rawImm : BitVec 64) (byte : Nat -> X86MemByte)
    (dstOld : X86RegValue) (zfOld sfOld ofOld : Bool) :
    generatedX86BtStep op flagsCode baseReg indexReg rawImm byte dstOld
        zfOld sfOld ofOld =
      x86BtStepSpec op flagsCode baseReg indexReg rawImm byte dstOld
        zfOld sfOld ofOld := by
  cases op <;> cases flagsCode <;>
    simp only [generatedX86BtStep, x86BtStepSpec, baseSource, indexSource,
      x86BtToOp, x86BtBaseSourceSpec, x86BtIndexSourceSpec, resolveWidth,
      generatedX86BtWriteWidth, x86BtWriteWidthSpec, x86BtCodeWidthSpec,
      generatedX86BtBase, x86BtBaseSpec, generatedX86BtIndex, x86BtIndexSpec,
      generatedX86BtCf, x86BtCfSpec, x86_mem_load_refines,
      x86_immediate_value_refines, x86_bt_refines_width]

/-- Every `BT` body writes no register: the destination passes through
unchanged. -/
theorem x86_bt_preserves_dst (op : X86BtOp) (flagsCode : Code)
    (baseReg indexReg rawImm : BitVec 64) (byte : Nat -> X86MemByte)
    (dstOld : X86RegValue) (zfOld sfOld ofOld : Bool) :
    (x86BtStepSpec op flagsCode baseReg indexReg rawImm byte dstOld
      zfOld sfOld ofOld).dst = dstOld := by
  cases op <;> rfl

/-- Every `BT` body writes only `CF`: `ZF`/`SF`/`OF` keep their incoming
values. -/
theorem x86_bt_only_cf (op : X86BtOp) (flagsCode : Code)
    (baseReg indexReg rawImm : BitVec 64) (byte : Nat -> X86MemByte)
    (dstOld : X86RegValue) (zfOld sfOld ofOld : Bool) :
    (x86BtStepSpec op flagsCode baseReg indexReg rawImm byte dstOld
        zfOld sfOld ofOld).zf = zfOld ∧
      (x86BtStepSpec op flagsCode baseReg indexReg rawImm byte dstOld
        zfOld sfOld ofOld).sf = sfOld ∧
      (x86BtStepSpec op flagsCode baseReg indexReg rawImm byte dstOld
        zfOld sfOld ofOld).of = ofOld := by
  cases op <;> exact ⟨rfl, rfl, rfl⟩

/-- Only the memory form reads its base from memory; the two register forms
read a register, so the memory width only ever applies to `BT_MEM_IMM`. -/
theorem x86_bt_base_source_effects (op : X86BtOp) :
    (x86BtStepSpec op .absent 0 0 0 (fun _ => 0)
      ⟨0, .scalar⟩ false false false).baseSource =
      (match op with | .btMemImm => BaseSource.memoryRead
                     | _ => BaseSource.registerRead) := by
  cases op <;> rfl

/-- An 8-bit `BT` with register index 3 tests bit 3 of `0x08` and carries,
writing no register. -/
theorem x86_bt_w8_example :
    (x86BtStepSpec .bt .b8 0x08 3 0 (fun _ => 0)
      ⟨0xdead, .scalar⟩ false false false).cf = true ∧
      (x86BtStepSpec .bt .b8 0x08 3 0 (fun _ => 0)
        ⟨0xdead, .scalar⟩ false false false).dst = ⟨0xdead, .scalar⟩ := by
  refine ⟨?_, ?_⟩ <;> decide

/-- An 8-bit `BT` with an index at or above the width tests a bit the byte does
not have and never carries. -/
theorem x86_bt_handler_wide_index_false :
    (x86BtStepSpec .bt .b8 0xff 8 0 (fun _ => 0)
      ⟨0, .scalar⟩ false false false).cf = false := by
  decide

/-- The memory form narrows its loaded base to the resolved width before the
test: a byte whose bit 8 is set does not carry a 32-bit `BT_MEM_IMM`, because
the index 8 selects a bit the loaded word does not have under a 1-byte width. -/
theorem x86_bt_mem_imm_w8_example :
    (x86BtStepSpec .btMemImm .b8 0 0 8 (fun _ => 0xff)
      ⟨0, .scalar⟩ false false false).cf = false := by
  decide
end KProgFormal
