import KProgFormal.X86AluWriteback
import KProgFormal.X86MemAccess

namespace KProgFormal

/-- Arithmetic operations whose memory-source handlers have dedicated
carry/borrow-correct result and flag contracts. -/
inductive X86MemArithOp
  | add
  | adc
  | sub
  | sbb
  deriving DecidableEq, Repr

/-- Composition used by the x86 `ALU reg, [mem]` handler after address-space
selection has supplied the little-endian bytes at a valid effective address.
The destination is the low register lane, exactly as in
`X86_SIM_L_EXEC_ALU_MEM`. -/
def generatedX86MemArithHandler (op : X86MemArithOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (width : X86Width) : X86RegAluState :=
  let rhs := GeneratedX86MemAccess.load byte width
  match op with
  | .add => generatedX86AddHandler state rhs width
  | .adc => generatedX86AdcHandler state rhs width
  | .sub => generatedX86SubHandler state rhs width
  | .sbb => generatedX86SbbHandler state rhs width

/-- Independent statement of the same bounded handler: load the source through
the byte-sum memory specification, then apply the independently stated
arithmetic, flags, and low-lane writeback specification. -/
def x86MemArithHandlerSpec (op : X86MemArithOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (width : X86Width) : X86RegAluState :=
  let rhs := x86MemLoadSpec byte width
  match op with
  | .add => x86AddHandlerSpec state rhs width
  | .adc => x86AdcHandlerSpec state rhs width
  | .sub => x86SubHandlerSpec state rhs width
  | .sbb => x86SbbHandlerSpec state rhs width

/-- The memory-source ADD/ADC/SUB/SBB handler composition refines the
independent load/arithmetic/flags/writeback statement for arbitrary memory
bytes, register state, flags, and legal operand width. -/
theorem x86_mem_arith_handler_refines (op : X86MemArithOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (width : X86Width) :
    generatedX86MemArithHandler op state byte width =
      x86MemArithHandlerSpec op state byte width := by
  cases op <;>
    simp only [generatedX86MemArithHandler, x86MemArithHandlerSpec] <;>
    rw [x86_mem_load_refines]
  · exact x86_add_handler_refines state (x86MemLoadSpec byte width) width
  · exact x86_adc_handler_refines state (x86MemLoadSpec byte width) width
  · exact x86_sub_handler_refines state (x86MemLoadSpec byte width) width
  · exact x86_sbb_handler_refines state (x86MemLoadSpec byte width) width

/-- A 16-bit ADC reads `0xffff` in little-endian order, consumes the incoming
carry once, preserves the register's upper bits, scalarizes its provenance,
and produces carry plus zero. -/
theorem x86_mem_adc_w16_carry_example :
    generatedX86MemArithHandler .adc
      { dst := { bits := 0x1122334455660000, tag := .packet },
        flags := { cf := true, zf := false, sf := true, of := true } }
      (fun i => if i = 0 then 0xff else if i = 1 then 0xff else 0) .w16 =
      { dst := { bits := 0x1122334455660000, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := false } } := by
  native_decide

/-- A 32-bit subtract of the loaded value one from zero demonstrates both
borrow/sign flags and architectural zero-extension of the destination. -/
theorem x86_mem_sub_w32_borrow_example :
    generatedX86MemArithHandler .sub
      { dst := { bits := 0xffff000000000000, tag := .mapValue },
        flags := { cf := false, zf := true, sf := false, of := true } }
      (fun i => if i = 0 then 1 else 0) .w32 =
      { dst := { bits := 0xffffffff, tag := .scalar },
        flags := { cf := true, zf := false, sf := true, of := false } } := by
  native_decide

end KProgFormal
