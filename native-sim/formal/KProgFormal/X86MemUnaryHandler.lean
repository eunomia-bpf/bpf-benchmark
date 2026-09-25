import KProgFormal.X86MemAccess
import KProgFormal.X86UnaryWriteback

namespace KProgFormal

/-- Unary operations implemented by `X86_OP_ALU_MEM_UNARY`. -/
inductive X86MemUnaryOp
  | inc
  | dec
  | neg
  | not
  deriving DecidableEq, Repr

/-- Value/flag transition for `ALU [mem]` after a valid effective address,
width, and unary operation have been selected. The temporary low register lane
reuses the proved unary transition; only its width-local value and flags feed
the memory store. -/
def generatedX86MemUnaryStep (op : X86MemUnaryOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (width : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte width
  let state : X86RegAluState :=
    { dst := { bits := lhs, tag := .scalar }, flags := flags }
  match op with
  | .inc => generatedX86IncLaneHandler state width .low
  | .dec => generatedX86DecLaneHandler state width .low
  | .neg => generatedX86NegLaneHandler state width .low
  | .not => generatedX86NotLaneHandler state width .low

/-- Independent load plus unary-transition statement. -/
def x86MemUnaryStepSpec (op : X86MemUnaryOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (width : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte width
  let state : X86RegAluState :=
    { dst := { bits := lhs, tag := .scalar }, flags := flags }
  match op with
  | .inc => x86IncLaneHandlerSpec state width .low
  | .dec => x86DecLaneHandlerSpec state width .low
  | .neg => x86NegLaneHandlerSpec state width .low
  | .not => x86NotLaneHandlerSpec state width .low

theorem x86_mem_unary_step_refines (op : X86MemUnaryOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (width : X86Width) :
    generatedX86MemUnaryStep op flags byte width =
      x86MemUnaryStepSpec op flags byte width := by
  cases op <;>
    simp only [generatedX86MemUnaryStep, x86MemUnaryStepSpec] <;>
    rw [x86_mem_load_refines]
  · exact x86_inc_lane_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } width .low
  · exact x86_dec_lane_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } width .low
  · exact x86_neg_lane_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } width .low
  · exact x86_not_lane_handler_refines
      { dst := { bits := x86MemLoadSpec byte width, tag := .scalar },
        flags := flags } width .low

/-- Byte observed after the generated memory-unary handler. -/
def generatedX86MemUnaryByte (op : X86MemUnaryOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (width : X86Width) (i : Nat) : X86MemByte :=
  let out := generatedX86MemUnaryStep op flags byte width
  if i < GeneratedX86MemAccess.byteCount width then
    GeneratedX86MemAccess.store out.dst.bits width i
  else byte i

/-- Independent statement of the width-confined little-endian store. -/
def x86MemUnaryByteSpec (op : X86MemUnaryOp) (flags : X86Flags)
    (byte : Nat -> X86MemByte) (width : X86Width) (i : Nat) : X86MemByte :=
  let out := x86MemUnaryStepSpec op flags byte width
  if i < x86WidthBitsSpec width / 8 then
    x86MemStoreByteSpec out.dst.bits width i
  else byte i

theorem x86_mem_unary_byte_refines (op : X86MemUnaryOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (width : X86Width)
    (i : Nat) :
    generatedX86MemUnaryByte op flags byte width i =
      x86MemUnaryByteSpec op flags byte width i := by
  simp only [generatedX86MemUnaryByte, x86MemUnaryByteSpec]
  rw [x86_mem_unary_step_refines, x86_mem_byte_count]
  by_cases h : i < x86WidthBitsSpec width / 8
  · simp only [h, ↓reduceIte]
    simp only [GeneratedX86MemAccess.store]
    rw [x86_mem_store_byte_refines]
  · simp only [h, ↓reduceIte]

/-- Full bounded observation: flags and every memory byte refine the
independent load/unary/store statement. -/
theorem x86_mem_unary_handler_refines (op : X86MemUnaryOp)
    (flags : X86Flags) (byte : Nat -> X86MemByte) (width : X86Width) :
    (generatedX86MemUnaryStep op flags byte width).flags =
        (x86MemUnaryStepSpec op flags byte width).flags ∧
      ∀ i, generatedX86MemUnaryByte op flags byte width i =
        x86MemUnaryByteSpec op flags byte width i := by
  constructor
  · rw [x86_mem_unary_step_refines]
  · intro i
    exact x86_mem_unary_byte_refines op flags byte width i

theorem x86_mem_unary_neg_w8_min_example :
    let old : Nat -> X86MemByte := fun i => if i = 0 then 0x80 else 0xa5
    generatedX86MemUnaryByte .neg
        { cf := false, zf := true, sf := false, of := false }
        old .w8 0 = 0x80 ∧
      generatedX86MemUnaryByte .neg
        { cf := false, zf := true, sf := false, of := false }
        old .w8 1 = 0xa5 ∧
      (generatedX86MemUnaryStep .neg
        { cf := false, zf := true, sf := false, of := false }
        old .w8).flags =
        { cf := true, zf := false, sf := true, of := true } := by
  native_decide

end KProgFormal
