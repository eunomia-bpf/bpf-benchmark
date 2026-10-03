import KProgFormal.GeneratedArm64Aux
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Aux (pack b0 b1 b2 b3 regNone)

/-- Independent statement of the packed AArch64 AUX layout, written as an
explicit little-endian byte concatenation rather than the generated masked-or
expression: each lane dominates only its own byte, the memory-flag byte is most
significant, then the shift/width/column byte, then the modifier/LSB/NZCV byte,
then the ALU-opcode/index/bitfield-kind byte least significant, so lane `k`
occupies bits `8k`-`8k+7`. -/
def arm64AuxSpec (opcodeLane modLane shiftLane flagLane : BitVec 32) :
    BitVec 32 :=
  flagLane.setWidth 8 ++ shiftLane.setWidth 8 ++
    modLane.setWidth 8 ++ opcodeLane.setWidth 8

/-- The generated C-shaped packer equals the independent byte concatenation for
all four lane values: a masked-or of shifted bytes and a little-endian
concatenation of each lane's low byte produce the same 32-bit word. -/
theorem arm64_aux_pack_refines (opcodeLane modLane shiftLane flagLane :
    BitVec 32) :
    pack opcodeLane modLane shiftLane flagLane =
      arm64AuxSpec opcodeLane modLane shiftLane flagLane := by
  unfold pack arm64AuxSpec
  bv_decide

/-- Lane 0 (`ARM64_SIM_L_MEM_INDEX`, and the ALU opcode / bitfield kind byte)
decodes the low byte: its roundtrip, and the fact it depends only on lane 0's
argument (no other lane bleeds into bits 0-7). -/
theorem arm64_aux_b0_roundtrip (opcodeLane modLane shiftLane flagLane :
    BitVec 32) :
    b0 (pack opcodeLane modLane shiftLane flagLane) =
      BitVec.and opcodeLane 0xff := by
  unfold pack b0
  bv_decide

/-- Lane 1 (`ARM64_SIM_L_MOD`, `ARM64_SIM_L_BITFIELD_LSB`,
`ARM64_SIM_L_CCMP_NZCV`) decodes the byte at bits 8-15 regardless of the other
three lanes. -/
theorem arm64_aux_b1_roundtrip (opcodeLane modLane shiftLane flagLane :
    BitVec 32) :
    b1 (pack opcodeLane modLane shiftLane flagLane) =
      BitVec.and modLane 0xff := by
  unfold pack b1
  bv_decide

/-- Lane 2 (`ARM64_SIM_L_SHIFT`, `ARM64_SIM_L_BITFIELD_WIDTH`, and the MOVK
column) decodes the byte at bits 16-23 regardless of the other three lanes. -/
theorem arm64_aux_b2_roundtrip (opcodeLane modLane shiftLane flagLane :
    BitVec 32) :
    b2 (pack opcodeLane modLane shiftLane flagLane) =
      BitVec.and shiftLane 0xff := by
  unfold pack b2
  bv_decide

/-- Lane 3 (`ARM64_SIM_L_MEM_FLAGS`) decodes the high byte at bits 24-31
regardless of the other three lanes. -/
theorem arm64_aux_b3_roundtrip (opcodeLane modLane shiftLane flagLane :
    BitVec 32) :
    b3 (pack opcodeLane modLane shiftLane flagLane) =
      BitVec.and flagLane 0xff := by
  unfold pack b3
  bv_decide

/-- The four lanes are pairwise non-interfering: each decoder's result is a
function of its own argument only, so no lane's byte overwrites another's. This
is the conjunction of the four roundtrips stated as independence. -/
theorem arm64_aux_lanes_non_interfering
    (opcodeLane modLane shiftLane flagLane : BitVec 32) :
    b0 (pack opcodeLane modLane shiftLane flagLane) =
        BitVec.and opcodeLane 0xff ∧
      b1 (pack opcodeLane modLane shiftLane flagLane) =
        BitVec.and modLane 0xff ∧
      b2 (pack opcodeLane modLane shiftLane flagLane) =
        BitVec.and shiftLane 0xff ∧
      b3 (pack opcodeLane modLane shiftLane flagLane) =
        BitVec.and flagLane 0xff := by
  refine ⟨?_, ?_, ?_, ?_⟩
  · unfold pack b0; bv_decide
  · unfold pack b1; bv_decide
  · unfold pack b2; bv_decide
  · unfold pack b3; bv_decide

/-- The `ARM64_REG_NONE` sentinel survives a pack/unpack cycle: a memory operand
with no index register packs its `0xff` index byte and the index decoder reads
`0xff` back, at any modifier, shift, and flag byte. -/
theorem arm64_aux_reg_none_roundtrip (modLane shiftLane flagLane : BitVec 32) :
    b0 (pack regNone modLane shiftLane flagLane) = regNone := by
  unfold pack b0 regNone
  bv_decide

/-- The sentinel is the all-ones byte, pinned so the C `ARM64_REG_NONE` value
and the generated `regNone` cannot drift apart. -/
theorem arm64_aux_reg_none_is_0xff : regNone = 0xff := rfl

/-- Canonical layout example: lane 0 `1`, lane 1 `2`, lane 2 `3`, lane 3 `4`
pack to the little-endian word `0x04030201`, pinning the byte order against a
concrete value. -/
theorem arm64_aux_example :
    pack 1 2 3 4 = 0x04030201 := by
  native_decide
/-- The lane-0 interpretation is shared: the ALU opcode, the memory index
register, the bitfield kind and the shift kind all decode bits 0-7, and the
`ARM64_REG_NONE` "no index" sentinel is a lane-0 byte. Naming the four aliases
and proving them equal pins the sharing, so pointing any one at a different lane
is a compile error rather than a silent misread. -/
def simAluOpcode (aux : BitVec 32) : BitVec 32 := b0 aux

def simMemIndex (aux : BitVec 32) : BitVec 32 := b0 aux

def simBitfieldKind (aux : BitVec 32) : BitVec 32 := b0 aux

def simShiftKind (aux : BitVec 32) : BitVec 32 := b0 aux

theorem arm64_aux_lane0_shared :
    simAluOpcode = simMemIndex ∧ simMemIndex = simBitfieldKind ∧
      simBitfieldKind = simShiftKind :=
  ⟨rfl, rfl, rfl⟩


/-- The lane-1 interpretation is shared: the source modifier, the bitfield LSB
and the CCMP NZCV all decode bits 8-15. Naming the three aliases and proving
them equal pins the sharing, so pointing any one at a different lane is a
compile error rather than a silent misread. -/
def simMod (aux : BitVec 32) : BitVec 32 := b1 aux

def simBitfieldLsb (aux : BitVec 32) : BitVec 32 := b1 aux

def simCcmpNzcv (aux : BitVec 32) : BitVec 32 := b1 aux

theorem arm64_aux_lane1_shared :
    simMod = simBitfieldLsb ∧ simBitfieldLsb = simCcmpNzcv :=
  ⟨rfl, rfl⟩

/-- The lane-2 interpretation is shared: the ALU modifier's shift *amount*, the
bitfield width and the MOVK column all decode bits 16-23. (The shift *kind* of
`ARM64_OP_SHIFT_*` is a lane-0 byte, see `arm64_aux_lane0_shared`.) -/
def simModShiftAmount (aux : BitVec 32) : BitVec 32 := b2 aux

def simBitfieldWidth (aux : BitVec 32) : BitVec 32 := b2 aux

def simMovkColumn (aux : BitVec 32) : BitVec 32 := b2 aux

theorem arm64_aux_lane2_shared :
    simModShiftAmount = simBitfieldWidth ∧ simBitfieldWidth = simMovkColumn :=
  ⟨rfl, rfl⟩

/-- The lane-1 and lane-2 interpretations read disjoint bytes: an ALU operand
with modifier `0x11` and modifier shift amount `0x22` decodes to `0x11` in the
modifier lane and `0x22` in the shift-amount lane, so per-opcode reuse never
aliases the two. -/
theorem arm64_aux_lane1_lane2_disjoint :
    b1 (pack 0 0x11 0x22 0) = 0x11 ∧ b2 (pack 0 0x11 0x22 0) = 0x22 := by
  native_decide

end KProgFormal
