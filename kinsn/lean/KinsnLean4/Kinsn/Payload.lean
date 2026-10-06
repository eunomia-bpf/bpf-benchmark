import KinsnLean4.Kinsn.Catalog

namespace Kinsn.Payload

/-- include/kinsn_common.h:kinsn_payload_wire_escaped. -/
def escaped (p : BitVec 64) : Bool :=
  (p &&& 15) == 10 && decide (11 ≤ ((p >>> 4) &&& 15).toNat) &&
    decide (((p >>> 4) &&& 15).toNat ≤ 15)

/-- include/kinsn_common.h:kinsn_payload_decode; remove the escape nibble only
    when both marker and original-low-nibble satisfy the C predicate. -/
def decode (p : BitVec 64) : BitVec 64 :=
  if escaped p then ((p >>> 8) <<< 4) ||| ((p >>> 4) &&& 15) else p

/-- include/kinsn_common.h:kinsn_payload_reg; the helper itself decodes. -/
def regField (p : BitVec 64) (shift : Nat) : Nat :=
  ((decode p >>> shift) &&& 15).toNat

/-- include/kinsn_common.h:kinsn_payload_u8; the helper itself decodes. -/
def byteField (p : BitVec 64) (shift : Nat) : BitVec 8 :=
  BitVec.setWidth 8 (decode p >>> shift)

/-- include/kinsn_common.h:kinsn_payload_s16, followed by BPF/native effective
    address sign extension. Keeping the intermediate 16-bit field is essential. -/
def offset (p : BitVec 64) (shift : Nat) : BitVec 64 :=
  BitVec.signExtend 64 (BitVec.setWidth 16 (decode p >>> shift))

/-- x86/bpf_x86_lea.c:decode_lea_payload, signed 32-bit displacement. -/
def displacement (p : BitVec 64) : BitVec 32 :=
  BitVec.setWidth 32 (decode p >>> 20)

/-- Validated BPF operand, without a default register for invalid nibbles.
    include/kinsn_x86_emit.h:kinsn_x86_operand_valid and ARM decoders' ≤R10 checks. -/
def reg (n : Nat) (h : n ≤ 10) : BPF.Reg :=
  #[.r0,.r1,.r2,.r3,.r4,.r5,.r6,.r7,.r8,.r9,.r10][n]'(by change n < 11; omega)

/-- include/kinsn_common.h:kinsn_arm64_reg; physical numbers, not BPF indices. -/
def armNumber : BPF.Reg → Nat
  | .r0 => 7 | .r1 => 0 | .r2 => 1 | .r3 => 2 | .r4 => 3 | .r5 => 4
  | .r6 => 19 | .r7 => 20 | .r8 => 21 | .r9 => 22 | .r10 => 25

def armGPNumber : ARM64.GPReg → Nat
  | .x0 => 0 | .x1 => 1 | .x2 => 2 | .x3 => 3 | .x4 => 4 | .x5 => 5
  | .x6 => 6 | .x7 => 7 | .x8 => 8 | .x9 => 9 | .x10 => 10 | .x11 => 11
  | .x12 => 12 | .x13 => 13 | .x14 => 14 | .x15 => 15 | .x16 => 16 | .x17 => 17
  | .x18 => 18 | .x19 => 19 | .x20 => 20 | .x21 => 21 | .x22 => 22 | .x23 => 23
  | .x24 => 24 | .x25 => 25 | .x26 => 26 | .x27 => 27 | .x28 => 28 | .x29 => 29
  | .x30 => 30 | .xzr => 31

theorem arm_register_encoding (r : BPF.Reg) :
    armGPNumber (Catalog.armReg r) = armNumber r := by cases r <;> rfl

/-- include/kinsn_common.h:kinsn_x86_reg_code/kinsn_x86_reg_ext, combined
    three-bit ModRM field and extension bit. Standard non-private-stack map. -/
def x86Number : BPF.Reg → Nat
  | .r0 => 0 | .r1 => 7 | .r2 => 6 | .r3 => 2 | .r4 => 1 | .r5 => 8
  | .r6 => 3 | .r7 => 13 | .r8 => 14 | .r9 => 15 | .r10 => 5

def x86GPNumber : X86.GPReg → Nat
  | .rax => 0 | .rcx => 1 | .rdx => 2 | .rbx => 3 | .rsp => 4 | .rbp => 5
  | .rsi => 6 | .rdi => 7 | .r8 => 8 | .r9 => 9 | .r10 => 10 | .r11 => 11
  | .r12 => 12 | .r13 => 13 | .r14 => 14 | .r15 => 15

theorem x86_register_encoding (r : BPF.Reg) :
    x86GPNumber (Catalog.x86Reg r) = x86Number r := by cases r <;> rfl

-- Serialization regressions: an escape marker without an escaped form is
-- ordinary payload, and signed offsets must not become unsigned addresses.
theorem escaped_form_decoded : decode 0x180da = 0x180d := by decide +kernel
theorem ordinary_r10_not_escape : decode 0x10a = 0x10a := by decide +kernel
theorem negative_offset : offset 0xffff10 8 = (-1 : BitVec 64) := by decide +kernel
theorem negative_displacement : displacement 0xffffffff00001 = (-1 : BitVec 32) :=
  by decide +kernel

end Kinsn.Payload
