import KProgFormal.Arm64Mul
import KProgFormal.X86RegWrite
import KProgFormal.X86ControlFlow

namespace KProgFormal

/-- State threaded through the `MULX` handler. Unlike the single-destination
arithmetic handlers, `MULX` writes two registers: the low half of the product
into the destination operand and the high half into the auxiliary operand, and
it produces no flags at all. The auxiliary register is therefore carried beside
the destination so the conditional second writeback is observable. -/
structure X86MulxState where
  dst : X86RegValue
  aux : X86RegValue
  flags : X86Flags
  deriving DecidableEq, Repr

/-- Independent Lean reading of the `MULX` high half: the 64-bit ladder the
simulator's `else` branch computes. Written as a `let` chain over 32-bit halves,
structurally separate from both the generated C arm and the 128-bit product
statement the refinement compares it to. The limb names follow the C arm: `p0`
is the low-by-low product, `p1`/`p2` the cross terms, `p3` the high-by-high
product, and `mid` the carry accumulator of the `2^32` column. -/
def x86MulxHighLadder (lhs rhs : BitVec 64) : BitVec 64 :=
  let a0 := lhs &&& 0xffffffff
  let a1 := lhs >>> 32
  let b0 := rhs &&& 0xffffffff
  let b1 := rhs >>> 32
  let p0 := a0 * b0
  let p1 := a0 * b1
  let p2 := a1 * b0
  let p3 := a1 * b1
  let mid := (p0 >>> 32) + (p1 &&& 0xffffffff) + (p2 &&& 0xffffffff)
  p3 + (p1 >>> 32) + (p2 >>> 32) + (mid >>> 32)

/-- The `MULX` ladder is the AArch64 `UMULH` ladder up to the order of the two
cross terms, which addition commutes. This is the bridge that lets the existing
UMULH identity discharge the x86 high half. -/
theorem x86MulxHighLadderEqUmulhAlg (lhs rhs : BitVec 64) :
    x86MulxHighLadder lhs rhs = arm64MulUmulhAlg lhs rhs := by
  simp only [x86MulxHighLadder, arm64MulUmulhAlg]
  ac_rfl

/-- The `MULX` 64-bit ladder equals the high word of the exact 128-bit product,
by transfer to the AArch64 `UMULH` statement over the same radix-`2^32`
decomposition. -/
theorem x86MulxHighLadderEqHighWord (lhs rhs : BitVec 64) :
    x86MulxHighLadder lhs rhs =
      BitVec.setWidth 64 (((lhs.setWidth 128) * (rhs.setWidth 128)) >>> 64) := by
  rw [x86MulxHighLadderEqUmulhAlg]
  exact arm64MulUmulhLadderEqHighWord lhs rhs

/-- `MULX` after operand and width selection: the low half of the product
written into the destination and, when the instruction carries an auxiliary
destination, the high half written into it. The width discriminates as in
`X86_SIM_L_EXEC_MULX`: the 32-bit form multiplies the zero-extended low words
and splits that single 64-bit product, while every other width takes the 64-bit
limb ladder for the high half and the plain 64-bit product for the low half. The
writeback of each half is confined to the operand width by the generated
register write, and no flag register is touched. -/
def generatedX86MulxStep (state : X86MulxState) (lhs rhs : BitVec 64)
    (width : X86Width) (auxPresent : Bool) : X86MulxState :=
  match width with
  | .w32 =>
      let product := (lhs &&& 0xffffffff) * (rhs &&& 0xffffffff)
      { dst := generatedX86RegWrite state.dst product width
        aux := if auxPresent
          then generatedX86RegWrite state.aux (product >>> 32) width
          else state.aux
        flags := state.flags }
  | _ =>
      { dst := generatedX86RegWrite state.dst (lhs * rhs) width
        aux := if auxPresent
          then generatedX86RegWrite state.aux (x86MulxHighLadder lhs rhs) width
          else state.aux
        flags := state.flags }

/-- Independent statement of the same handler: the low half is the exact product
of the selected operand values, and the high half is the upper word of the exact
128-bit product (for the 32-bit form, of the zero-extended low-word product).
Both halves are written through the independently defined register-write
specification, and the flag word passes through unchanged. -/
def x86MulxStepSpec (state : X86MulxState) (lhs rhs : BitVec 64)
    (width : X86Width) (auxPresent : Bool) : X86MulxState :=
  match width with
  | .w32 =>
      let product := (lhs.setWidth 32).setWidth 64 * (rhs.setWidth 32).setWidth 64
      { dst := x86RegWriteSpec state.dst product width
        aux := if auxPresent
          then x86RegWriteSpec state.aux (product >>> 32) width
          else state.aux
        flags := state.flags }
  | _ =>
      { dst := x86RegWriteSpec state.dst (lhs * rhs) width
        aux := if auxPresent
          then x86RegWriteSpec state.aux
            (BitVec.setWidth 64 (((lhs.setWidth 128) * (rhs.setWidth 128)) >>> 64))
            width
          else state.aux
        flags := state.flags }

/-- The 32-bit `MULX` low half: masking the operands with the low-word mask is
the same selection as truncating them to 32 bits and zero-extending back. -/
theorem x86MulxMask32EqSetWidth (v : BitVec 64) :
    v &&& 0xffffffff = (v.setWidth 32).setWidth 64 := by
  bv_decide

/-- The `MULX` handler composition refines its independent statement for
arbitrary register state, operands, operand width, and auxiliary-destination
presence. -/
theorem x86_mulx_step_refines (state : X86MulxState) (lhs rhs : BitVec 64)
    (width : X86Width) (auxPresent : Bool) :
    generatedX86MulxStep state lhs rhs width auxPresent =
      x86MulxStepSpec state lhs rhs width auxPresent := by
  cases width <;>
    simp only [generatedX86MulxStep, x86MulxStepSpec]
  · rw [x86_reg_write_refines]
    by_cases h : auxPresent <;>
      simp only [h, if_true, if_false, x86_reg_write_refines,
        x86MulxHighLadderEqHighWord]
  · rw [x86_reg_write_refines]
    by_cases h : auxPresent <;>
      simp only [h, if_true, if_false, x86_reg_write_refines,
        x86MulxHighLadderEqHighWord]
  · rw [x86MulxMask32EqSetWidth, x86MulxMask32EqSetWidth]
    rw [x86_reg_write_refines]
    by_cases h : auxPresent <;>
      simp only [h, if_true, if_false, x86_reg_write_refines]
  · rw [x86_reg_write_refines]
    by_cases h : auxPresent <;>
      simp only [h, if_true, if_false, x86_reg_write_refines,
        x86MulxHighLadderEqHighWord]

/-- `MULX` produces no flags: the incoming flag word survives the handler
exactly, matching the C arm, which writes no flag register. -/
theorem x86_mulx_preserves_flags (state : X86MulxState) (lhs rhs : BitVec 64)
    (width : X86Width) (auxPresent : Bool) :
    (x86MulxStepSpec state lhs rhs width auxPresent).flags = state.flags := by
  cases width <;> rfl

/-- Without an auxiliary destination operand the auxiliary register is not
written at all: the `if ((AUX) != X86_REG_NONE)` guard in the C arm. -/
theorem x86_mulx_aux_absent_preserves_aux (state : X86MulxState)
    (lhs rhs : BitVec 64) (width : X86Width) :
    (x86MulxStepSpec state lhs rhs width false).aux = state.aux := by
  cases width <;> rfl

/-- The destination writeback scalarizes the destination's provenance tag
regardless of the incoming tag. -/
theorem x86_mulx_dst_tag_scalar (state : X86MulxState) (lhs rhs : BitVec 64)
    (width : X86Width) (auxPresent : Bool) :
    (x86MulxStepSpec state lhs rhs width auxPresent).dst.tag = .scalar := by
  cases width <;>
    simp only [x86MulxStepSpec, x86RegWriteSpec]

/-- A present auxiliary destination is likewise scalarized by its writeback. -/
theorem x86_mulx_aux_tag_scalar (state : X86MulxState) (lhs rhs : BitVec 64)
    (width : X86Width) :
    (x86MulxStepSpec state lhs rhs width true).aux.tag = .scalar := by
  cases width <;>
    simp only [x86MulxStepSpec, if_true, x86RegWriteSpec]

/-- The 64-bit `MULX` of two identical maximal operands: the exact product is
`2^128 - 2^65 + 1`, so the low word is one and the high word is
`0xfffffffffffffffe`. Both destination registers are scalarized. -/
theorem x86_mulx_w64_max_example :
    generatedX86MulxStep
      { dst := { bits := 0x1122334455667788, tag := .packet },
        aux := { bits := 0x99aabbccddeeff00, tag := .mapValue },
        flags := { cf := true, zf := true, sf := true, of := true } }
      0xffffffffffffffff 0xffffffffffffffff .w64 true =
      { dst := { bits := 0x0000000000000001, tag := .scalar },
        aux := { bits := 0xfffffffffffffffe, tag := .scalar },
        flags := { cf := true, zf := true, sf := true, of := true } } := by
  decide

/-- The 32-bit `MULX` of two maximal low words: the single product is
`0xfffffffe00000001`, so the low half is one and the high half is
`0xfffffffe`. The upper 32 bits of both destination registers are cleared by the
32-bit writeback. -/
theorem x86_mulx_w32_max_example :
    generatedX86MulxStep
      { dst := { bits := 0xdeadbeefcafef00d, tag := .stack },
        aux := { bits := 0x0011223344556677, tag := .rodataAddr },
        flags := { cf := false, zf := false, sf := false, of := false } }
      0xffffffffffffffff 0xffffffffffffffff .w32 true =
      { dst := { bits := 0x0000000000000001, tag := .scalar },
        aux := { bits := 0x00000000fffffffe, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  decide

/-- A `MULX` with no auxiliary destination leaves the auxiliary register
untouched, including its provenance tag, while still writing and scalarizing the
destination and leaving the flags alone. -/
theorem x86_mulx_aux_absent_example :
    generatedX86MulxStep
      { dst := { bits := 0x0000000000000003, tag := .abi },
        aux := { bits := 0x0000000000000005, tag := .helperId },
        flags := { cf := false, zf := true, sf := false, of := false } }
      0x0000000100000002 0x0000000300000004 .w64 false =
      { dst := { bits := 0x0000000a00000008, tag := .scalar },
        aux := { bits := 0x0000000000000005, tag := .helperId },
        flags := { cf := false, zf := true, sf := false, of := false } } := by
  decide

/-- A 16-bit `MULX` takes the 64-bit limb branch of the C arm, as the width
discriminates only on the 32-bit form: the high half comes from the ladder, not
from splitting a single 32-bit product, and the 16-bit writeback keeps only the
low word of each half. -/
theorem x86_mulx_w16_limb_branch_example :
    generatedX86MulxStep
      { dst := { bits := 0xaabbccddeeff0000, tag := .scalar },
        aux := { bits := 0x1122334455667788, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } }
      0x0000000200000003 0x0000000400000005 .w16 true =
      { dst := { bits := 0xaabbccddeeff000f, tag := .scalar },
        aux := { bits := 0x1122334455660008, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  decide

end KProgFormal
