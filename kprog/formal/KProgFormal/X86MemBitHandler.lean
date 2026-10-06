import KProgFormal.X86MemAccess
import KProgFormal.X86Bitops
import KProgFormal.X86AluWriteback

namespace KProgFormal

/-- Legacy x86 `BT r/m, imm8` and BMI2 `BZHI r, r/m, reg` memory-source
handlers. `BT` reads a memory operand, assigns the indexed bit to CF, writes no
register, and leaves ZF/SF/OF untouched; `BZHI` reads a memory operand, writes a
width-confined register result holding the low `count` bits, and defines
CF/ZF/SF/OF itself. Both take the operand bytes through the little-endian
memory specification and the second operand (bit index or bit count) as an
already-decoded 64-bit value. -/
inductive X86MemBitOp
  | bt
  | bzhi
  deriving DecidableEq, Repr

/-- Composition used by the x86 `BT [mem], imm8` and `BZHI dst, [mem], count`
handlers after address-space selection has supplied the little-endian bytes at a
valid effective address. The count is masked into the low byte exactly as
`X86_SIM_L_EXEC_BZHI_MEM` reads it from the register. -/
def generatedX86MemBitStep (op : X86MemBitOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (index : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let base := GeneratedX86MemAccess.load byte width
  match op with
  | .bt =>
      { dst := state.dst
        flags := { state.flags with
          cf := GeneratedX86Bitops.bt base index
            (GeneratedX86Width.code width) } }
  | .bzhi =>
      let count := index &&& 0xff
      let result :=
        GeneratedX86Bitops.bzhi base count (GeneratedX86Width.code width)
      { dst := generatedX86RegWrite state.dst result width
        flags :=
          { cf := BitVec.ule (BitVec.ofNat 64 (GeneratedX86Width.bits width))
              count
            zf := result == 0
            sf := false
            of := false } }

/-- Independent statement of the same bit-test/zero-high-bits handlers: load
through the byte-sum memory specification, apply the independently stated
`bt`/`bzhi` contract, and confine the register writeback to the operand width. -/
def x86MemBitStepSpec (op : X86MemBitOp) (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (index : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let base := x86MemLoadSpec byte width
  match op with
  | .bt =>
      { dst := state.dst
        flags := { state.flags with
          cf := x86BtSpec base index (x86WidthCodeSpec width) } }
  | .bzhi =>
      let count := index &&& 0xff
      let result := x86BzhiSpec base count (x86WidthCodeSpec width)
      { dst := x86RegWriteSpec state.dst result width
        flags :=
          { cf := BitVec.ule (BitVec.ofNat 64 (x86WidthBitsSpec width)) count
            zf := result == 0
            sf := false
            of := false } }

/-- The memory-source bit-test/zero-high-bits composition refines the
independent load/`bt`/`bzhi`/writeback statement for arbitrary memory bytes,
register state, incoming flags, decoded second operand, and legal operand
width. -/
theorem x86_mem_bit_step_refines (op : X86MemBitOp)
    (state : X86RegAluState) (byte : Nat -> X86MemByte) (index : BitVec 64)
    (width : X86Width) :
    generatedX86MemBitStep op state byte index width =
      x86MemBitStepSpec op state byte index width := by
  cases op
  · simp only [generatedX86MemBitStep, x86MemBitStepSpec]
    rw [x86_mem_load_refines]
    simp only [x86_bt_refines_width]
  · simp only [generatedX86MemBitStep, x86MemBitStepSpec]
    rw [x86_mem_load_refines]
    simp only [x86_bzhi_refines_width]
    rw [x86_width_bits_refines, x86_reg_write_refines]

/-- `BT [mem], imm8` writes no register: the destination passes through
unchanged. -/
theorem x86_mem_bt_preserves_dst (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (index : BitVec 64) (width : X86Width) :
    (generatedX86MemBitStep .bt state byte index width).dst = state.dst := rfl

/-- `BT [mem], imm8` only writes CF: ZF/SF/OF keep their incoming values. -/
theorem x86_mem_bt_only_cf (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (index : BitVec 64) (width : X86Width) :
    (generatedX86MemBitStep .bt state byte index width).flags.zf =
        state.flags.zf ∧
      (generatedX86MemBitStep .bt state byte index width).flags.sf =
        state.flags.sf ∧
      (generatedX86MemBitStep .bt state byte index width).flags.of =
        state.flags.of := by
  exact ⟨rfl, rfl, rfl⟩

/-- `BZHI` defines SF and OF as zero, independent of the incoming flags. -/
theorem x86_mem_bzhi_clears_sf_of (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (index : BitVec 64) (width : X86Width) :
    (generatedX86MemBitStep .bzhi state byte index width).flags.sf = false ∧
      (generatedX86MemBitStep .bzhi state byte index width).flags.of =
        false := by
  exact ⟨rfl, rfl⟩

/-- An 8-bit `BT` with index 3 reads a memory byte whose bit 3 is set, so CF is
carried while the register and the other three flags are untouched. -/
theorem x86_mem_bt_w8_example :
    generatedX86MemBitStep .bt
      { dst := { bits := 0x1122334455667788, tag := .scalar },
        flags := { cf := false, zf := true, sf := false, of := true } }
      (fun i => if i = 0 then 0x08 else 0xa5)
      3 .w8 =
      { dst := { bits := 0x1122334455667788, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := true } } := by
  decide

/-- A 32-bit `BZHI` with count 4 keeps the low nibble of the loaded word and
zero-extends into the 64-bit destination, clearing CF/ZF/SF/OF. -/
theorem x86_mem_bzhi_w32_example :
    generatedX86MemBitStep .bzhi
      { dst := { bits := 0xffffffffffffffff, tag := .packet },
        flags := { cf := true, zf := false, sf := true, of := true } }
      (fun i => if i < 4 then 0xff else 0)
      4 .w32 =
      { dst := { bits := 0x000000000000000f, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  decide

/-- An 8-bit `BZHI` whose masked count reaches the width keeps the whole loaded
byte, merges it into the low destination byte, and reports CF. -/
theorem x86_mem_bzhi_count_reaches_width_example :
    generatedX86MemBitStep .bzhi
      { dst := { bits := 0x1122334455667700, tag := .mapValue },
        flags := { cf := false, zf := false, sf := false, of := false } }
      (fun i => if i = 0 then 0xab else 0)
      0xff .w8 =
      { dst := { bits := 0x11223344556677ab, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := false } } := by
  decide

end KProgFormal
