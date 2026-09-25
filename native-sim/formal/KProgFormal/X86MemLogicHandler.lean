import KProgFormal.X86MemAccess
import KProgFormal.X86AluWriteback

namespace KProgFormal

inductive X86MemLogicOp | and | or | xor deriving DecidableEq, Repr

/-- `AND/OR/XOR [mem], rhs` after valid-address, RHS, operation, and width
selection. -/
def generatedX86MemLogicStep (op : X86MemLogicOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte width
  let state : X86RegAluState :=
    { dst := { bits := lhs, tag := .scalar }, flags := flags }
  match op with
  | .and => generatedX86AndRegLaneHandler state rhs width .low .low
  | .or => generatedX86OrRegLaneHandler state rhs width .low .low
  | .xor => generatedX86XorRegLaneHandler state rhs width .low .low

def x86MemLogicStepSpec (op : X86MemLogicOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte width
  let state : X86RegAluState :=
    { dst := { bits := lhs, tag := .scalar }, flags := flags }
  match op with
  | .and => x86AndRegLaneHandlerSpec state rhs width .low .low
  | .or => x86OrRegLaneHandlerSpec state rhs width .low .low
  | .xor => x86XorRegLaneHandlerSpec state rhs width .low .low

theorem x86_mem_logic_step_refines (op : X86MemLogicOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) :
    generatedX86MemLogicStep op flags byte rhs width =
      x86MemLogicStepSpec op flags byte rhs width := by
  cases op <;>
    simp only [generatedX86MemLogicStep, x86MemLogicStepSpec] <;>
    rw [x86_mem_load_refines]
  · exact x86_and_reg_lane_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } rhs width .low .low
  · exact x86_or_reg_lane_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } rhs width .low .low
  · exact x86_xor_reg_lane_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } rhs width .low .low

def generatedX86MemLogicByte (op : X86MemLogicOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64) (width : X86Width)
    (i : Nat) : X86MemByte :=
  let out := generatedX86MemLogicStep op flags byte rhs width
  if i < GeneratedX86MemAccess.byteCount width then
    GeneratedX86MemAccess.store out.dst.bits width i
  else byte i

def x86MemLogicByteSpec (op : X86MemLogicOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (rhs : BitVec 64) (width : X86Width)
    (i : Nat) : X86MemByte :=
  let out := x86MemLogicStepSpec op flags byte rhs width
  if i < x86WidthBitsSpec width / 8 then
    x86MemStoreByteSpec out.dst.bits width i
  else byte i

theorem x86_mem_logic_byte_refines (op : X86MemLogicOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) (i : Nat) :
    generatedX86MemLogicByte op flags byte rhs width i =
      x86MemLogicByteSpec op flags byte rhs width i := by
  simp only [generatedX86MemLogicByte, x86MemLogicByteSpec]
  rw [x86_mem_logic_step_refines, x86_mem_byte_count]
  by_cases h : i < x86WidthBitsSpec width / 8
  · simp only [h, ↓reduceIte, GeneratedX86MemAccess.store]
    rw [x86_mem_store_byte_refines]
  · simp only [h, ↓reduceIte]

theorem x86_mem_logic_handler_refines (op : X86MemLogicOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (rhs : BitVec 64)
    (width : X86Width) :
    (generatedX86MemLogicStep op flags byte rhs width).flags =
        (x86MemLogicStepSpec op flags byte rhs width).flags ∧
      ∀ i, generatedX86MemLogicByte op flags byte rhs width i =
        x86MemLogicByteSpec op flags byte rhs width i := by
  constructor
  · rw [x86_mem_logic_step_refines]
  · exact x86_mem_logic_byte_refines op flags byte rhs width

theorem x86_mem_logic_xor_w16_example :
    let old : Nat -> X86MemByte := fun i => if i < 2 then 0xff else 0xa5
    generatedX86MemLogicByte .xor
        { cf := true, zf := false, sf := true, of := true }
        old 0xffff .w16 0 = 0 ∧
      generatedX86MemLogicByte .xor
        { cf := true, zf := false, sf := true, of := true }
        old 0xffff .w16 2 = 0xa5 ∧
      (generatedX86MemLogicStep .xor
        { cf := true, zf := false, sf := true, of := true }
        old 0xffff .w16).flags =
        { cf := false, zf := true, sf := false, of := false } := by
  native_decide

end KProgFormal
