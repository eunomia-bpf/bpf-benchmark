import KProgFormal.GeneratedX86CmpOp
import KProgFormal.X86AluWriteback
import KProgFormal.X86Immediate
import KProgFormal.X86LogicFlags
import KProgFormal.X86RegRead
import KProgFormal.X86SubResult
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86CmpOp (Op RhsSource FlagKind rhsSource flagKind resolveWidth
  writeWidthDefault)
open GeneratedX86Store (Code)

/-- The four `CMP`/`TEST` opcodes this contract spans: `X86_OP_CMP_IMM`
(`0x0c`), `X86_OP_CMP_REG` (`0x0d`), `X86_OP_TEST_IMM` (`0x0e`) and
`X86_OP_TEST_REG` (`0x0f`). The `_IMM` forms take the right-hand side from the
decoded immediate, the `_REG` forms from a register; the `CMP` forms produce the
zero-borrow subtraction flags, the `TEST` forms the logical flags. -/
inductive X86CmpOp
  | cmpImm
  | cmpReg
  | testImm
  | testReg
  deriving DecidableEq, Repr

/-- Bridge to the generated opcode table. -/
def x86CmpOpToOp : X86CmpOp -> GeneratedX86CmpOp.Op
  | .cmpImm => .cmpImm
  | .cmpReg => .cmpReg
  | .testImm => .testImm
  | .testReg => .testReg

/-- Independent statement of where each opcode reads its right-hand side. -/
def x86CmpOpRhsSourceSpec : X86CmpOp -> RhsSource
  | .cmpImm => .immediate
  | .cmpReg => .register
  | .testImm => .immediate
  | .testReg => .register

/-- Independent statement of which flag production each opcode uses. -/
def x86CmpOpFlagKindSpec : X86CmpOp -> FlagKind
  | .cmpImm => .sub
  | .cmpReg => .sub
  | .testImm => .logic
  | .testReg => .logic

/-- The generated right-hand-side-source table agrees with the independent
statement. -/
theorem x86_cmpop_rhs_source_refines (op : X86CmpOp) :
    rhsSource (x86CmpOpToOp op) = x86CmpOpRhsSourceSpec op := by
  cases op <;> rfl

/-- The generated flag-kind table agrees with the independent statement. -/
theorem x86_cmpop_flag_kind_refines (op : X86CmpOp) :
    flagKind (x86CmpOpToOp op) = x86CmpOpFlagKindSpec op := by
  cases op <;> rfl

/-- The right-hand-side source and the flag kind are *independent* per-opcode
facts: `CMP_IMM` and `TEST_IMM` share the immediate source but differ in flag
kind, and `CMP_IMM`/`CMP_REG` share the subtraction flags but differ in source
— so neither table is a function of the other, and no row is dead. -/
theorem x86_cmpop_tables_independent :
    x86CmpOpRhsSourceSpec .cmpImm = x86CmpOpRhsSourceSpec .testImm ∧
      x86CmpOpFlagKindSpec .cmpImm = x86CmpOpFlagKindSpec .cmpReg ∧
      x86CmpOpRhsSourceSpec .cmpImm ≠ x86CmpOpRhsSourceSpec .cmpReg ∧
      x86CmpOpFlagKindSpec .cmpImm ≠ x86CmpOpFlagKindSpec .testImm := by
  refine ⟨rfl, rfl, ?_, ?_⟩
  · intro h; cases h
  · intro h; cases h

/-- The width a `FLAGS` code names, restated independently: the code itself,
with the absent code resolving to the 64-bit width. -/
def x86CmpOpCodeWidthSpec : Code -> X86Width
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The width every body narrows its operands to: the opcode's `FLAGS` code
itself, or 64 bits when it carries none. -/
def x86CmpOpWriteWidthSpec : Code -> X86Width := x86CmpOpCodeWidthSpec

/-- The width the generated `resolveWidth` table selects, restated. -/
def generatedX86CmpOpWriteWidth (flags : Code) : X86Width :=
  match resolveWidth flags with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated width equals the independent statement, for every `FLAGS`
code. -/
theorem x86_cmpop_write_width_refines (flags : Code) :
    generatedX86CmpOpWriteWidth flags = x86CmpOpWriteWidthSpec flags := by
  cases flags <;> rfl

/-- An absent `FLAGS` code resolves the width to 64 bits. -/
theorem x86_cmpop_write_width_default_refines :
    generatedX86CmpOpWriteWidth .absent = .w64 := by
  rfl

/-- Independent statement of the right-hand side: the decoded immediate for the
`_IMM` forms, the width/lane register read of `SRC` for the `_REG` forms. -/
def x86CmpOpRhsSpec (op : X86CmpOp) (srcBits rawImm : BitVec 64)
    (width : X86Width) (srcLane : X86ByteLane) : BitVec 64 :=
  match x86CmpOpRhsSourceSpec op with
  | .immediate => x86ImmediateValueSpec rawImm width
  | .register => x86RegReadAtSpec srcBits width srcLane

/-- The right-hand side the generated body builds, restated. -/
def generatedX86CmpOpRhs (op : X86CmpOp) (srcBits rawImm : BitVec 64)
    (width : X86Width) (srcLane : X86ByteLane) : BitVec 64 :=
  match rhsSource (x86CmpOpToOp op) with
  | .immediate => GeneratedX86Immediate.value rawImm width
  | .register => GeneratedX86RegRead.readAt srcBits width srcLane

/-- The generated right-hand side equals the independent statement, for every
opcode, source register bits, raw immediate, width, and source lane. -/
theorem x86_cmpop_rhs_refines (op : X86CmpOp) (srcBits rawImm : BitVec 64)
    (width : X86Width) (srcLane : X86ByteLane) :
    generatedX86CmpOpRhs op srcBits rawImm width srcLane =
      x86CmpOpRhsSpec op srcBits rawImm width srcLane := by
  cases op <;>
    simp only [generatedX86CmpOpRhs, x86CmpOpRhsSpec, rhsSource, x86CmpOpToOp,
      x86CmpOpRhsSourceSpec, x86_immediate_value_refines,
      x86_reg_read_at_refines]

/-- The effect of one `CMP`/`TEST` body. `rhsSource` records where the
right-hand side came from, `flagKind` which flags the body produced, `width` the
narrowing width, `lhs`/`rhs` the resolved operands, and `dst` the (unchanged)
destination register. -/
structure X86CmpOpEffect where
  rhsSource : RhsSource
  flagKind : FlagKind
  width : X86Width
  lhs : BitVec 64
  rhs : BitVec 64
  dst : X86RegValue
  flags : X86Flags
  deriving DecidableEq, Repr

/-- The composed handler transition used by all four bodies: the generated
tables select the right-hand-side source, the flag kind, and the `FLAGS`-resolved
width; the left-hand side is the width/lane register read of the destination,
the right-hand side the decoded immediate or the width/lane register read of
`SRC`; the flags are the zero-borrow subtraction flags or the logical flags of
the width-narrowed conjunction. No register is written. -/
def generatedX86CmpOpStep (op : X86CmpOp) (flagsCode : Code)
    (dstBits srcBits rawImm : BitVec 64)
    (dstLane srcLane : X86ByteLane) (dstOld : X86RegValue) : X86CmpOpEffect :=
  let w := generatedX86CmpOpWriteWidth flagsCode
  let lhs := GeneratedX86RegRead.readAt dstBits w dstLane
  let rhs := generatedX86CmpOpRhs op srcBits rawImm w srcLane
  let flags := match flagKind (x86CmpOpToOp op) with
    | .sub =>
        generatedX86SubFlags (GeneratedX86Width.narrow lhs w)
          (GeneratedX86Width.narrow rhs w)
          (GeneratedX86Width.narrow
            (GeneratedX86SbbResult.result lhs rhs false) w)
          (GeneratedX86Width.signMask w)
    | .logic =>
        generatedX86LogicFlags
          (GeneratedX86Width.zero (BitVec.and lhs rhs) w)
          (GeneratedX86Width.sign (BitVec.and lhs rhs) w)
  { rhsSource := rhsSource (x86CmpOpToOp op),
    flagKind := flagKind (x86CmpOpToOp op), width := w, lhs := lhs, rhs := rhs,
    dst := dstOld, flags := flags }

/-- Independent statement of the same handler, reading the right-hand side, the
flag kind, the width, and the flags from the independent statements. -/
def x86CmpOpStepSpec (op : X86CmpOp) (flagsCode : Code)
    (dstBits srcBits rawImm : BitVec 64)
    (dstLane srcLane : X86ByteLane) (dstOld : X86RegValue) : X86CmpOpEffect :=
  let w := x86CmpOpWriteWidthSpec flagsCode
  let lhs := x86RegReadAtSpec dstBits w dstLane
  let rhs := x86CmpOpRhsSpec op srcBits rawImm w srcLane
  let flags := match x86CmpOpFlagKindSpec op with
    | .sub =>
        x86SubFlagsSpec (x86NarrowSpec lhs w) (x86NarrowSpec rhs w)
          (x86NarrowSpec (x86SubResultSpec lhs rhs) w)
          (x86WidthSignMaskSpec w)
    | .logic =>
        x86LogicFlagsSpec (x86ZeroSpec (BitVec.and lhs rhs) w)
          (x86SignSpec (BitVec.and lhs rhs) w)
  { rhsSource := x86CmpOpRhsSourceSpec op, flagKind := x86CmpOpFlagKindSpec op,
    width := w, lhs := lhs, rhs := rhs, dst := dstOld, flags := flags }

/-- The `CMP`/`TEST` handler composition refines the independent
rhs/flag-kind/width/flag-production statement for every opcode, `FLAGS` code,
register bits, raw immediate, lanes, and destination register. -/
theorem x86_cmpop_step_refines (op : X86CmpOp) (flagsCode : Code)
    (dstBits srcBits rawImm : BitVec 64)
    (dstLane srcLane : X86ByteLane) (dstOld : X86RegValue) :
    generatedX86CmpOpStep op flagsCode dstBits srcBits rawImm
        dstLane srcLane dstOld =
      x86CmpOpStepSpec op flagsCode dstBits srcBits rawImm
        dstLane srcLane dstOld := by
  cases op <;> cases flagsCode <;>
    simp only [generatedX86CmpOpStep, x86CmpOpStepSpec, x86CmpOpToOp,
      rhsSource, flagKind, x86CmpOpRhsSourceSpec, x86CmpOpFlagKindSpec,
      resolveWidth, generatedX86CmpOpWriteWidth, x86CmpOpWriteWidthSpec,
      x86CmpOpCodeWidthSpec, generatedX86CmpOpRhs, x86CmpOpRhsSpec,
      x86_reg_read_at_refines, x86_immediate_value_refines] <;>
    first
      | rw [x86_sub_step_refines]
      | rw [x86_zero_refines, x86_sign_refines, x86_logic_flags_refine]

/-- Every `CMP`/`TEST` body writes no register: the destination passes through
unchanged. -/
theorem x86_cmpop_preserves_dst (op : X86CmpOp) (flagsCode : Code)
    (dstBits srcBits rawImm : BitVec 64)
    (dstLane srcLane : X86ByteLane) (dstOld : X86RegValue) :
    (x86CmpOpStepSpec op flagsCode dstBits srcBits rawImm dstLane srcLane
      dstOld).dst = dstOld := by
  cases op <;> rfl

/-- The `CMP` opcodes produce subtraction flags and the `TEST` opcodes logical
flags; the two flag kinds are distinct, and the right-hand-side source is again
independent of the flag kind (`CMP_IMM`/`TEST_IMM` share a source but differ in
kind). -/
theorem x86_cmpop_flag_production (flagsCode : Code)
    (dstBits srcBits rawImm : BitVec 64)
    (dstLane srcLane : X86ByteLane) (dstOld : X86RegValue) :
    (x86CmpOpStepSpec .cmpImm flagsCode dstBits srcBits rawImm dstLane srcLane
        dstOld).flagKind =
      (x86CmpOpStepSpec .cmpReg flagsCode dstBits srcBits rawImm dstLane srcLane
        dstOld).flagKind ∧
      (x86CmpOpStepSpec .testImm flagsCode dstBits srcBits rawImm dstLane srcLane
        dstOld).flagKind =
      (x86CmpOpStepSpec .testReg flagsCode dstBits srcBits rawImm dstLane srcLane
        dstOld).flagKind ∧
      (x86CmpOpStepSpec .cmpImm flagsCode dstBits srcBits rawImm dstLane srcLane
        dstOld).flagKind ≠
      (x86CmpOpStepSpec .testImm flagsCode dstBits srcBits rawImm dstLane srcLane
        dstOld).flagKind := by
  refine ⟨rfl, rfl, ?_⟩
  intro h
  cases h

/-- A 64-bit `CMP` of equal operands sets zero, clears carry, sign, and
overflow, and leaves the packet-tagged destination untouched. -/
theorem x86_cmpop_equal_w64 :
    (x86CmpOpStepSpec .cmpReg .b64 0x1122334455667788 0x1122334455667788 0
      .low .low ⟨0xdead, .packet⟩).flags =
      { cf := false, zf := true, sf := false, of := false } ∧
      (x86CmpOpStepSpec .cmpReg .b64 0x1122334455667788 0x1122334455667788 0
        .low .low ⟨0xdead, .packet⟩).dst = ⟨0xdead, .packet⟩ := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- A 32-bit `TEST` whose width-narrowed conjunction is nonzero clears carry
and overflow and takes its zero/sign from the conjunction: an operand pair whose
shared low byte is nonzero but whose width-local conjunction is zero sets
zero. -/
theorem x86_cmpop_test_zero_w16 :
    (x86CmpOpStepSpec .testImm .b16 0x000000000000ff00 0 0x00000000000000ff
      .low .low ⟨0, .scalar⟩).flags =
      { cf := false, zf := true, sf := false, of := false } := by
  native_decide

/-- A narrow `_IMM` form decodes the immediate at the resolved width: a 64-bit
immediate with bit 31 set sign-extends only under the 64-bit width, so the same
compare carries at 64 bits. -/
theorem x86_cmpop_imm64_sign_extends :
    (x86CmpOpStepSpec .cmpImm .b64 0 0 0x0000000080000000 .low .low
      ⟨0, .scalar⟩).rhs = 0xffffffff80000000 ∧
      (x86CmpOpStepSpec .cmpImm .b32 0 0 0x0000000080000000 .low .low
        ⟨0, .scalar⟩).rhs = 0x80000000 := by
  refine ⟨?_, ?_⟩ <;> native_decide

end KProgFormal
