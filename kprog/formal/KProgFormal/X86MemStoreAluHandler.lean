import KProgFormal.X86MemAluHandler

namespace KProgFormal

/-- The value/flag step used by `ALU [mem], rhs` after effective-address and
right-hand-operand selection. A temporary register value lets us reuse the
proved arithmetic handler; only its width-local result and flags are observed
by the following memory store. -/
def generatedX86MemDestArithStep (op : X86MemArithOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte width
  let state : X86RegAluState :=
    { dst := { bits := lhs, tag := .scalar }, flags := flags }
  match op with
  | .add => generatedX86AddHandler state rhs width
  | .adc => generatedX86AdcHandler state rhs width
  | .sub => generatedX86SubHandler state rhs width
  | .sbb => generatedX86SbbHandler state rhs width

def x86MemDestArithStepSpec (op : X86MemArithOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte width
  let state : X86RegAluState :=
    { dst := { bits := lhs, tag := .scalar }, flags := flags }
  match op with
  | .add => x86AddHandlerSpec state rhs width
  | .adc => x86AdcHandlerSpec state rhs width
  | .sub => x86SubHandlerSpec state rhs width
  | .sbb => x86SbbHandlerSpec state rhs width

theorem x86_mem_dest_arith_step_refines (op : X86MemArithOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) :
    generatedX86MemDestArithStep op flags byte rhs width =
      x86MemDestArithStepSpec op flags byte rhs width := by
  cases op <;>
    simp only [generatedX86MemDestArithStep, x86MemDestArithStepSpec] <;>
    rw [x86_mem_load_refines]
  · exact x86_add_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } rhs width
  · exact x86_adc_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } rhs width
  · exact x86_sub_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } rhs width
  · exact x86_sbb_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } rhs width

/-- Byte observed after the generated memory-destination handler. Bytes beyond
the selected access width are unchanged. -/
def generatedX86MemDestArithByte (op : X86MemArithOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64) (width : X86Width)
    (i : Nat) : X86MemByte :=
  let out := generatedX86MemDestArithStep op flags byte rhs width
  if i < GeneratedX86MemAccess.byteCount width then
    GeneratedX86MemAccess.store out.dst.bits width i
  else byte i

/-- Independent store statement: update exactly `width / 8` little-endian
bytes with the independently specified arithmetic result. -/
def x86MemDestArithByteSpec (op : X86MemArithOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64) (width : X86Width)
    (i : Nat) : X86MemByte :=
  let out := x86MemDestArithStepSpec op flags byte rhs width
  if i < x86WidthBitsSpec width / 8 then
    x86MemStoreByteSpec out.dst.bits width i
  else byte i

theorem x86_mem_dest_arith_byte_refines (op : X86MemArithOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) (i : Nat) :
    generatedX86MemDestArithByte op flags byte rhs width i =
      x86MemDestArithByteSpec op flags byte rhs width i := by
  simp only [generatedX86MemDestArithByte, x86MemDestArithByteSpec]
  rw [x86_mem_dest_arith_step_refines, x86_mem_byte_count]
  by_cases h : i < x86WidthBitsSpec width / 8
  · simp only [h, ↓reduceIte]
    simp only [GeneratedX86MemAccess.store]
    rw [x86_mem_store_byte_refines]
  · simp only [h, ↓reduceIte]

/-- Full bounded observation: the handler's flags and every memory byte refine
the independent arithmetic/store statement. -/
theorem x86_mem_dest_arith_handler_refines (op : X86MemArithOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) :
    (generatedX86MemDestArithStep op flags byte rhs width).flags =
        (x86MemDestArithStepSpec op flags byte rhs width).flags ∧
      ∀ i, generatedX86MemDestArithByte op flags byte rhs width i =
        x86MemDestArithByteSpec op flags byte rhs width i := by
  constructor
  · rw [x86_mem_dest_arith_step_refines]
  · intro i
    exact x86_mem_dest_arith_byte_refines op flags byte rhs width i

theorem x86_mem_dest_adc_w16_store_example :
    let old : Nat -> X86MemByte :=
      fun i => if i = 0 ∨ i = 1 then 0xff else 0xa5
    generatedX86MemDestArithByte .adc
        { cf := true, zf := false, sf := true, of := true }
        old 0 .w16 0 = 0 ∧
      generatedX86MemDestArithByte .adc
        { cf := true, zf := false, sf := true, of := true }
        old 0 .w16 1 = 0 ∧
      generatedX86MemDestArithByte .adc
        { cf := true, zf := false, sf := true, of := true }
        old 0 .w16 2 = 0xa5 ∧
      (generatedX86MemDestArithStep .adc
        { cf := true, zf := false, sf := true, of := true }
        old 0 .w16).flags =
        { cf := true, zf := true, sf := false, of := false } := by
  native_decide

end KProgFormal
