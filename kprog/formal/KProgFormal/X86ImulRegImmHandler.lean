import KProgFormal.X86AluWriteback
import KProgFormal.X86Signed
import KProgFormal.X86Immediate

namespace KProgFormal

/-- Composition used by the x86 register-source `IMUL reg, imm` handler
(`X86_SIM_L_EXEC_IMUL_IMM`) after operand selection has supplied the source
register's 64-bit value. Unlike the memory-source form, the left operand is the
register's raw 64-bit value — the simulator reads it with
`X86_SIM_L_READ_REG(SRC)` and does not sign-extend it — so only the immediate is
sign-extended, at the destination width. The destination width also governs the
IMUL flag computation and confines the writeback. -/
def generatedX86ImulRegImmStep (state : X86RegAluState) (lhs : BitVec 64)
    (rawImm : BitVec 64) (width : X86Width) : X86RegAluState :=
  let rhs := GeneratedX86Signed.signExtend
    (GeneratedX86Immediate.value rawImm width) width
  { dst := generatedX86RegWrite state.dst (lhs * rhs) width
    flags := generatedX86ImulFlags lhs rhs width state.flags }

/-- Independent statement of the same handler: sign-extend the decoded
immediate at the destination width, multiply in the 64-bit wrap-around
arithmetic, and confine the writeback to the destination width. -/
def x86ImulRegImmStepSpec (state : X86RegAluState) (lhs : BitVec 64)
    (rawImm : BitVec 64) (width : X86Width) : X86RegAluState :=
  let rhs := x86SignExtendSpec (x86ImmediateValueSpec rawImm width) width
  { dst := x86RegWriteSpec state.dst (lhs * rhs) width
    flags := x86ImulFlagsApplied lhs rhs width state.flags }

/-- The register-source IMUL-immediate handler composition refines the
independent sign-extend/multiply/flags/writeback statement for arbitrary
register state, source value, decoded immediate, and destination width. -/
theorem x86_imul_reg_imm_step_refines (state : X86RegAluState) (lhs : BitVec 64)
    (rawImm : BitVec 64) (width : X86Width) :
    generatedX86ImulRegImmStep state lhs rawImm width =
      x86ImulRegImmStepSpec state lhs rawImm width := by
  simp only [generatedX86ImulRegImmStep, x86ImulRegImmStepSpec,
    x86_immediate_value_refines, x86_sign_extend_refines, x86_reg_write_refines,
    x86_imul_flags_apply_refines]

/-- IMUL defines only CF and OF: the incoming ZF and SF survive the handler. -/
theorem x86_imul_reg_imm_preserves_zf_sf (state : X86RegAluState)
    (lhs : BitVec 64) (rawImm : BitVec 64) (width : X86Width) :
    (x86ImulRegImmStepSpec state lhs rawImm width).flags.zf = state.flags.zf ∧
      (x86ImulRegImmStepSpec state lhs rawImm width).flags.sf =
        state.flags.sf := by
  exact ⟨rfl, rfl⟩

/-- IMUL sets CF and OF together: they report the same overflow condition. -/
theorem x86_imul_reg_imm_cf_eq_of (state : X86RegAluState) (lhs : BitVec 64)
    (rawImm : BitVec 64) (width : X86Width) :
    (x86ImulRegImmStepSpec state lhs rawImm width).flags.cf =
      (x86ImulRegImmStepSpec state lhs rawImm width).flags.of := by
  rfl

/-- The writeback scalarizes the destination's provenance regardless of the
incoming tag. -/
theorem x86_imul_reg_imm_tag_scalar (state : X86RegAluState) (lhs : BitVec 64)
    (rawImm : BitVec 64) (width : X86Width) :
    (x86ImulRegImmStepSpec state lhs rawImm width).dst.tag = .scalar := by
  rfl
/-- The register source is *not* sign-extended: a source value whose high bit is
set enters the product as its full 64-bit value, so a 64-bit `IMUL` of a source
holding `0xffff...ffff` multiplies by the true 64-bit quantity rather than by a
width-narrowed `-1`. The immediate, by contrast, is sign-extended at the
destination width. The 64-bit writeback is the identity, so the product lands
in the destination unchanged. -/
theorem x86_imul_reg_imm_source_not_extended (state : X86RegAluState)
    (rawImm : BitVec 64) :
    (x86ImulRegImmStepSpec state 0xffffffffffffffff rawImm .w64).dst.bits =
      (0xffffffffffffffff : BitVec 64) *
        x86SignExtendSpec (x86ImmediateValueSpec rawImm .w64) .w64 := by
  rfl

/-- A 16-bit `IMUL` of a source register holding `0x7fff` by the immediate two:
the width-narrowed signed product overflows, so CF and OF are set together, the
low 16 bits `0xfffe` are written back, and the incoming ZF/SF survive. -/
theorem x86_imul_reg_imm_w16_overflow_example :
    generatedX86ImulRegImmStep
      { dst := { bits := 0x0000000000000080, tag := .packet },
        flags := { cf := false, zf := false, sf := false, of := false } }
      0x0000000000007fff 2 .w16 =
      { dst := { bits := 0x000000000000fffe, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := true } } := by
  decide

/-- A 64-bit `IMUL` of the low immediate `0x7fffffff` sign-extends bit 31, so the
product with one is the sign-extended `0xffffffff80000001` and no overflow is
reported because that product already fits the 64-bit signed range. -/
theorem x86_imul_reg_imm_w64_sign_extends_example :
    generatedX86ImulRegImmStep
      { dst := { bits := 0x1111111111111111, tag := .mapValue },
        flags := { cf := true, zf := true, sf := true, of := true } }
      1 0x0000000080000001 .w64 =
      { dst := { bits := 0xffffffff80000001, tag := .scalar },
        flags := { cf := false, zf := true, sf := true, of := false } } := by
  decide

/-- An 8-bit `IMUL` whose operands have opposite signs gets one extra bit of
headroom: the source `0xff...81` narrows to `-127` and the immediate `2` gives
`-254`, which still overflows the 8-bit signed range, so CF/OF are set and the
low byte `0x02` is written back while the upper seven bytes survive. -/
theorem x86_imul_reg_imm_w8_mixed_sign_overflow_example :
    generatedX86ImulRegImmStep
      { dst := { bits := 0x1122334455660000, tag := .stack },
        flags := { cf := false, zf := true, sf := true, of := false } }
      0xffffffffffffff81 2 .w8 =
      { dst := { bits := 0x1122334455660002, tag := .scalar },
        flags := { cf := true, zf := true, sf := true, of := true } } := by
  decide

/-- An in-range 8-bit `IMUL` with an all-zero flag word stays entirely clear and
merges the product into the destination's low byte. -/
theorem x86_imul_reg_imm_w8_in_range_example :
    generatedX86ImulRegImmStep
      { dst := { bits := 0x1122334455660000, tag := .mapValue },
        flags := { cf := false, zf := false, sf := false, of := false } }
      0x10 2 .w8 =
      { dst := { bits := 0x1122334455660020, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  decide

end KProgFormal
