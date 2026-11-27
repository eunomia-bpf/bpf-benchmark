import KProgFormal.Reference.AArch64

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyCode

/-- Exact first14 words from the sole linked kernel generic memcpy symbol.
The committed artifact receipt binds these bytes to memcpy.o and vmlinux. -/
def words : Array (BitVec 32) := #[
  0xd503245f#32,
  0x8b020024#32,
  0x8b020005#32,
  0xf102005f#32,
  0x54000788#32,
  0xf100805f#32,
  0x540003c8#32,
  0xf100405f#32,
  0x540000c3#32,
  0xa9401c26#32,
  0xa97f348c#32,
  0xa9001c06#32,
  0xa93f34ac#32,
  0xd65f03c0#32]

def word (i : Fin 14) : BitVec 32 := words[i.val]'(by simpa [words] using i.isLt)

theorem decodable : ∀ i : Fin 14, (decode_raw_inst (word i)).isSome = true := by decide +kernel

def instruction (i : Fin 14) : Reference.AArch64.Instruction where
  encoding := word i
  decoded := (decode_raw_inst (word i)).get (decodable i)
  valid := (Option.some_get (decodable i)).symm

/-- Runtime relocation binds these actual bytes at the physical code origin.
Live alternatives/landing-pad execution are retained as their own domain. -/
def Code (origin : BitVec 64) (machine : ArmState) : Prop :=
  ∀ i : Fin 14, fetch_inst (origin+BitVec.ofNat 64 (4*i.val)) machine = some (word i)

/-- The real landing pad decodes in the external model. -/
theorem landing : (instruction 0).decoded = .BR (.Hints {CRm := 4,op2 := 2}) := by decide +kernel

/-- The real16-byte path uses its actual two repeated pair loads and stores,
with real register assignments and signed-minus16 tail offsets. -/
theorem pairs :
    (instruction 9).decoded = .LDST (.Reg_pair_signed_offset {opc := 2,V := 0,L := 1,imm7 := 0,Rt2 := 7,Rn := 1,Rt := 6}) ∧
    (instruction 10).decoded = .LDST (.Reg_pair_signed_offset {opc := 2,V := 0,L := 1,imm7 := 126,Rt2 := 13,Rn := 4,Rt := 12}) ∧
    (instruction 11).decoded = .LDST (.Reg_pair_signed_offset {opc := 2,V := 0,L := 0,imm7 := 0,Rt2 := 7,Rn := 0,Rt := 6}) ∧
    (instruction 12).decoded = .LDST (.Reg_pair_signed_offset {opc := 2,V := 0,L := 0,imm7 := 126,Rt2 := 13,Rn := 5,Rt := 12}) := by decide +kernel

/-- Code certificates move only between the SAME complete physical program. -/
theorem transport {origin : BitVec 64} {before after : ArmState}
    (code : Code origin before) (program : after.program = before.program) : Code origin after := by
  intro i
  simpa only [fetch_inst,program] using code i

end KProgFormal.ClightRefinement.Arm64KernelMemcpyCode
