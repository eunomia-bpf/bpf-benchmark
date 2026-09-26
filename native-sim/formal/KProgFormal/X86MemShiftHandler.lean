import KProgFormal.X86MemAccess
import KProgFormal.X86ShiftResult
import KProgFormal.X86AluWriteback

namespace KProgFormal

/-- Flagless BMI2 memory-source shift operations: `SHLX/SHRX/SARX dst, [mem],
count`. These are the variable-count forms whose count arrives in a register
instead of an immediate byte. -/
inductive X86MemShiftOp
  | shl
  | shr
  | sar
  deriving DecidableEq, Repr

/-- Composition used by the x86 `SHLX/SHRX/SARX dst, [mem], count` handler
after address-space selection has supplied the little-endian bytes at a valid
effective address and the count register has been read. The destination is the
width's register lane, exactly as in `X86_SIM_L_EXEC_SHIFTX_MEM`. Unlike the
legacy `SHL/SHR/SAR [mem]` forms, BMI2 shifts leave CF/ZF/SF/OF untouched, so
the incoming flags are threaded through unchanged. -/
def generatedX86MemShiftStep (op : X86MemShiftOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (count : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte width
  let result := match op with
    | .shl => GeneratedX86ShiftResult.shl lhs count width
    | .shr => GeneratedX86ShiftResult.shr lhs count width
    | .sar => GeneratedX86ShiftResult.sar lhs count width
  { dst := generatedX86RegWrite state.dst result width, flags := state.flags }

/-- Independent statement of the same bounded handler: load the source through
the byte-sum memory specification, then apply the independently stated shift
result and width-confined register writeback. -/
def x86MemShiftStepSpec (op : X86MemShiftOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (count : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte width
  let result := match op with
    | .shl => x86ShlResultSpec lhs count width
    | .shr => x86ShrResultSpec lhs count width
    | .sar => x86SarResultSpec lhs count width
  { dst := x86RegWriteSpec state.dst result width, flags := state.flags }

/-- The memory-source shift handler composition refines the independent
load/shift/writeback statement for arbitrary memory bytes, register state,
incoming flags, count, and legal operand width. -/
theorem x86_mem_shift_step_refines (op : X86MemShiftOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte) (count : BitVec 64)
    (width : X86Width) :
    generatedX86MemShiftStep op state byte count width =
      x86MemShiftStepSpec op state byte count width := by
  cases op <;>
    simp only [generatedX86MemShiftStep, x86MemShiftStepSpec,
      x86_mem_load_refines, x86_reg_write_refines,
      x86_shl_result_refines, x86_shr_result_refines,
      x86_sar_result_refines]

/-- BMI2 memory-source shifts preserve every modeled flag: the handler
replaces only the destination register. This is the architectural property
that separates `SHLX/SHRX/SARX` from their flag-writing legacy counterparts. -/
theorem x86_mem_shift_preserves_flags (op : X86MemShiftOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte) (count : BitVec 64)
    (width : X86Width) :
    (generatedX86MemShiftStep op state byte count width).flags = state.flags := by
  cases op <;> rfl

/-- Composition used by the x86 `RORX dst, [mem], imm8` handler: the same
memory load and flagless register writeback, with the rotate count supplied by
the immediate byte rather than a register. `X86_SIM_L_EXEC_RORX_MEM` masks the
low immediate byte into the generated rotate. -/
def generatedX86MemRorxStep (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (count : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte width
  let result := GeneratedX86ShiftResult.ror lhs count width
  { dst := generatedX86RegWrite state.dst result width, flags := state.flags }

/-- Independent statement of the memory-source `RORX`: the rotate reaches its
result through the complementary-count rotate-left specification, matching the
register-source `x86_ror_result_refines` contract. -/
def x86MemRorxStepSpec (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (count : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte width
  let result := x86RorResultSpec lhs count width
  { dst := x86RegWriteSpec state.dst result width, flags := state.flags }

/-- The memory-source `RORX` handler composition refines the independent
load/complementary-rotate/writeback statement. -/
theorem x86_mem_rorx_step_refines (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (count : BitVec 64) (width : X86Width) :
    generatedX86MemRorxStep state byte count width =
      x86MemRorxStepSpec state byte count width := by
  simp only [generatedX86MemRorxStep, x86MemRorxStepSpec,
    x86_mem_load_refines, x86_reg_write_refines, x86_ror_result_refines]

/-- `RORX [mem]` is flagless as well: only the destination register changes. -/
theorem x86_mem_rorx_preserves_flags (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (count : BitVec 64) (width : X86Width) :
    (generatedX86MemRorxStep state byte count width).flags = state.flags := rfl

/-- A 32-bit `SHLX` reads `0x80000001` from memory, shifts it left by one,
zero-extends into the 64-bit destination lane, and leaves the flags exactly as
the incoming four. -/
theorem x86_mem_shl_w32_example :
    generatedX86MemShiftStep .shl
      { dst := { bits := 0xffffffffffffffff, tag := .packet },
        flags := { cf := true, zf := true, sf := true, of := true } }
      (fun i => if i = 0 then 1 else if i = 3 then 0x80 else 0)
      1 .w32 =
      { dst := { bits := 0x0000000000000002, tag := .scalar },
        flags := { cf := true, zf := true, sf := true, of := true } } := by
  native_decide

/-- An 8-bit `SARX` reads `0x80` from the low byte, shifts it arithmetically
right by one, and sign-fills to `0xc0` while preserving the destination's upper
bytes and the incoming flags. -/
theorem x86_mem_sar_w8_example :
    generatedX86MemShiftStep .sar
      { dst := { bits := 0x1122334455660000, tag := .mapValue },
        flags := { cf := false, zf := false, sf := false, of := false } }
      (fun i => if i = 0 then 0x80 else 0xa5)
      1 .w8 =
      { dst := { bits := 0x11223344556600c0, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  native_decide

/-- An 8-bit `RORX` by one moves the low bit to the top: `0x81` becomes
`0xc0`, and the destination's other seven bytes survive. -/
theorem x86_mem_rorx_w8_example :
    generatedX86MemRorxStep
      { dst := { bits := 0x1122334455660000, tag := .scalar },
        flags := { cf := false, zf := true, sf := true, of := false } }
      (fun i => if i = 0 then 0x81 else 0xa5)
      1 .w8 =
      { dst := { bits := 0x11223344556600c0, tag := .scalar },
        flags := { cf := false, zf := true, sf := true, of := false } } := by
  native_decide

end KProgFormal
