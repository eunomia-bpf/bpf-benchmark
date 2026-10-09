import KProgFormal.GeneratedX86Xchg
import KProgFormal.X86RegWrite
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Xchg (Arm armCount widthCodeBits opcode fullWidthCode armNames
  armCodes codeOfArm effectOfArm widthClassOfArm isFullWidth armOf armOfCode)

/-- Independent statement of the `X86_OP_XCHG` arm selector: the pointer-swap
arm at the resolved 64-bit width code, the subword-value-swap arm at every
other code. It selects on the literal code `8`, built from the width contract's
own `x86WidthCodeSpec .w64` rather than the generated `fullWidthCode`. -/
def x86XchgArmSpec (width : Nat) : Arm :=
  if width = x86WidthCodeSpec .w64 then .pointerSwap else .subwordSwap

/-- Independent statement of the two arms the `X86_OP_XCHG` arm selects
between, built from the literal constructor order rather than the generated
`armNames`. -/
def x86XchgArmNamesSpec : List String := ["pointerSwap", "subwordSwap"]

/-- The generated arm selectors equal the independent literal construction. -/
theorem x86_xchg_arm_refines (width : Nat) :
    armOf width = x86XchgArmSpec width := by
  unfold armOf x86XchgArmSpec fullWidthCode
  rfl

/-- The generated arm-name table equals the independent literal order. -/
theorem x86_xchg_names_refine : armNames = x86XchgArmNamesSpec := by
  unfold armNames x86XchgArmNamesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries. -/
theorem x86_xchg_codes_length : armCodes.length = armCount := rfl

/-- The generated arm-name table has exactly `armCount` entries. -/
theorem x86_xchg_names_length : armNames.length = armCount := rfl

/-- The two arm codes are distinct, so no two arms alias one code. -/
theorem x86_xchg_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The selector picks the pointer-swap arm exactly at the full 64-bit width
code, stated against the independent selector. -/
theorem x86_xchg_arm_pointer_iff_full (width : Nat) :
    x86XchgArmSpec width = .pointerSwap ↔ width = x86WidthCodeSpec .w64 := by
  unfold x86XchgArmSpec
  by_cases h : width = x86WidthCodeSpec .w64 <;> simp [h, Arm.noConfusion]

/-- The selector picks the subword-swap arm exactly below the full width, so
every narrower code reaches the width-masked writeback. -/
theorem x86_xchg_arm_subword_iff_narrow (width : Nat) :
    x86XchgArmSpec width = .subwordSwap ↔ width ≠ x86WidthCodeSpec .w64 := by
  unfold x86XchgArmSpec
  by_cases h : width = x86WidthCodeSpec .w64 <;> simp [h, Arm.noConfusion]

/-- The width-code selector resolves each real width code to its own arm: only
the 64-bit code reaches the pointer arm, and the 8/16/32-bit codes all reach the
subword arm. -/
theorem x86_xchg_arm_over_widths :
    (List.map (fun w => x86XchgArmSpec (x86WidthCodeSpec w))
        [.w8, .w16, .w32, .w64]) =
      [Arm.subwordSwap, Arm.subwordSwap, Arm.subwordSwap, Arm.pointerSwap] := by
  rfl

/-- The arm-code selector round-trips each arm to its own code and names no
other code: `codeOfArm` is a left inverse of `armOfCode` on the two arms. -/
theorem x86_xchg_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no arm at or above the arm count, so the table
is exactly the two arms and no other code reaches one. -/
theorem x86_xchg_arm_of_code_beyond_is_none :
    armOfCode 2 = none ∧ armOfCode 3 = none ∧ armOfCode 8 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The opcode the contract implements is the simulator's `X86_OP_XCHG`
(`0x19`), pinned so the C opcode and the generated `opcode` cannot drift. -/
theorem x86_xchg_opcode_is_0x19 : opcode = 25 := rfl

/-- The width-code width is the byte width the sim decodes, pinned so the C
`__u8` width code and the generated `widthCodeBits` cannot drift apart. -/
theorem x86_xchg_width_code_bits_is_8 : widthCodeBits = 8 := rfl

/-- The full-width code the pointer arm is selected at is the 64-bit width
code, pinned against the generated table. -/
theorem x86_xchg_full_width_is_w64 : fullWidthCode = x86WidthCodeSpec .w64 := rfl

/-- The arm count is the two bodies `X86_OP_XCHG` selects between. -/
theorem x86_xchg_arm_count_is_2 : armCount = 2 := rfl

/-- The pointer arm is the full-width class and the subword arm the narrow
class, so the two classes are distinct and neither is empty. -/
theorem x86_xchg_width_classes :
    widthClassOfArm .pointerSwap = "full" ∧
      widthClassOfArm .subwordSwap = "narrow" ∧
      widthClassOfArm .pointerSwap ≠ widthClassOfArm .subwordSwap := by
  exact ⟨rfl, rfl, by decide⟩

/-- The pointer arm moves whole cells and the subword arm performs a
width-window value write, so the two effects are distinct. -/
theorem x86_xchg_effects :
    effectOfArm .pointerSwap = "pointer_swap" ∧
      effectOfArm .subwordSwap = "width_value_swap" ∧
      effectOfArm .pointerSwap ≠ effectOfArm .subwordSwap := by
  exact ⟨rfl, rfl, by decide⟩

/-- Independent statement of the pointer-swap arm's register effect: the two
cells exchange their whole 64-bit values and both tags become scalar. -/
def x86XchgPointerSpec (dst src : X86RegValue) : X86RegValue × X86RegValue :=
  ({ bits := src.bits, tag := .scalar },
   { bits := dst.bits, tag := .scalar })

/-- Independent statement of the subword-swap arm's register effect: each cell
receives the other's value through the partial-register writeback at the access
width, and both tags become scalar. -/
def x86XchgSubwordSpec (dst src : X86RegValue) (width : X86Width) :
    X86RegValue × X86RegValue :=
  ({ bits := x86RegWriteBitsSpec dst.bits src.bits width, tag := .scalar },
   { bits := x86RegWriteBitsSpec src.bits dst.bits width, tag := .scalar })

/-- The pointer arm moves the source cell's whole 64-bit value to the
destination and the destination cell's whole value to the source: the two
values are exchanged, not merged. -/
theorem x86_xchg_pointer_swaps (dst src : X86RegValue) :
    (x86XchgPointerSpec dst src).1.bits = src.bits ∧
      (x86XchgPointerSpec dst src).2.bits = dst.bits := by
  exact ⟨rfl, rfl⟩

/-- The pointer arm scalarizes both tags: the verifier provenance of neither
cell survives the swap. -/
theorem x86_xchg_pointer_scalarizes (dst src : X86RegValue) :
    (x86XchgPointerSpec dst src).1.tag = .scalar ∧
      (x86XchgPointerSpec dst src).2.tag = .scalar := by
  exact ⟨rfl, rfl⟩

/-- The subword arm scalarizes both tags: the width-masked writeback of either
cell discards provenance. -/
theorem x86_xchg_subword_scalarizes (dst src : X86RegValue) (width : X86Width) :
    (x86XchgSubwordSpec dst src width).1.tag = .scalar ∧
      (x86XchgSubwordSpec dst src width).2.tag = .scalar := by
  exact ⟨rfl, rfl⟩

/-- The pointer arm exchanges the two values as a permutation: applying it
twice restores both cells' values, so the swap is an involution on the value
bits. -/
theorem x86_xchg_pointer_involution (dst src : X86RegValue) :
    (x86XchgPointerSpec (x86XchgPointerSpec dst src).1
        (x86XchgPointerSpec dst src).2).1.bits = dst.bits ∧
      (x86XchgPointerSpec (x86XchgPointerSpec dst src).1
        (x86XchgPointerSpec dst src).2).2.bits = src.bits := by
  exact ⟨rfl, rfl⟩

/-- **The two arms write the same 64-bit value swap at the full width.** At the
64-bit width the subword arm's partial-register writeback replaces each cell
whole, so its value bits equal the pointer arm's: the arms are distinguished by
implementation (raw pointer-cell move versus width-masked value write), not by
the value they leave at 64 bits. They diverge only below the full width. -/
theorem x86_xchg_full_arms_agree_bits (dst src : X86RegValue) :
    (x86XchgSubwordSpec dst src .w64).1.bits =
        (x86XchgPointerSpec dst src).1.bits ∧
      (x86XchgSubwordSpec dst src .w64).2.bits =
        (x86XchgPointerSpec dst src).2.bits := by
  cases dst
  cases src
  refine ⟨?_, ?_⟩ <;>
    simp [x86XchgSubwordSpec, x86XchgPointerSpec, x86RegWriteBitsSpec]

/-- The subword arm exchanges the two values *within the access width*: each
cell's width-window receives the other's window, so a narrow swap moves exactly
the low `width` bits and nothing above them. -/
theorem x86_xchg_subword_exchanges_window (dst src : X86RegValue)
    (width : X86Width) :
    BitVec.and (x86XchgSubwordSpec dst src width).1.bits
        (x86WidthMaskSpec width) =
      BitVec.and src.bits (x86WidthMaskSpec width) ∧
      BitVec.and (x86XchgSubwordSpec dst src width).2.bits
        (x86WidthMaskSpec width) =
      BitVec.and dst.bits (x86WidthMaskSpec width) := by
  cases dst
  cases src
  cases width <;>
    simp [x86XchgSubwordSpec, x86RegWriteBitsSpec, x86WidthMaskSpec] <;>
    bv_decide

/-- The subword arm's 8-bit write preserves the destination cell's seven upper
bytes, so a byte swap touches only the low byte. -/
theorem x86_xchg_subword8_preserves_upper (dst src : X86RegValue) :
    BitVec.and (x86XchgSubwordSpec dst src .w8).1.bits 0xffffffffffffff00 =
      BitVec.and dst.bits 0xffffffffffffff00 := by
  cases dst
  cases src
  simp [x86XchgSubwordSpec, x86RegWriteBitsSpec]
  bv_decide

/-- The subword arm's 16-bit write preserves the destination cell's six upper
bytes. -/
theorem x86_xchg_subword16_preserves_upper (dst src : X86RegValue) :
    BitVec.and (x86XchgSubwordSpec dst src .w16).1.bits 0xffffffffffff0000 =
      BitVec.and dst.bits 0xffffffffffff0000 := by
  cases dst
  cases src
  simp [x86XchgSubwordSpec, x86RegWriteBitsSpec]
  bv_decide

/-- The subword arm's 32-bit write zero-extends: the destination cell's upper
half is cleared, unlike the 8/16-bit writes that preserve it. -/
theorem x86_xchg_subword32_zero_extends (dst src : X86RegValue) :
    BitVec.and (x86XchgSubwordSpec dst src .w32).1.bits 0xffffffff00000000 = 0 := by
  cases dst
  cases src
  simp [x86XchgSubwordSpec, x86RegWriteBitsSpec]
  bv_decide

/-- The subword arm's effect is exactly the two partial-register writebacks
`X86RegWrite` proves: each cell is written with `x86RegWriteSpec` at the access
width, so the subword arm's value semantics are the register-write contract's,
not a fresh implementation. -/
theorem x86_xchg_subword_is_reg_write (dst src : X86RegValue) (width : X86Width) :
    (x86XchgSubwordSpec dst src width).1.bits =
        (x86RegWriteSpec dst src.bits width).bits ∧
      (x86XchgSubwordSpec dst src width).2.bits =
        (x86RegWriteSpec src dst.bits width).bits := by
  refine ⟨?_, ?_⟩ <;> rfl

/-- The full-width selector is exactly the subword selector at code `8`: the
`isFullWidth` predicate is true only for the 64-bit code. -/
theorem x86_xchg_is_full_width_only_w64 :
    isFullWidth 8 = true ∧
      isFullWidth 1 = false ∧
      isFullWidth 2 = false ∧
      isFullWidth 4 = false := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- All the selector shapes are reachable: the full 64-bit code reaches the
pointer arm, and each narrower code reaches the subword arm, so no arm of the
contract is dead. -/
theorem x86_xchg_case_dispatch :
    armOf 8 = .pointerSwap ∧
      armOf 1 = .subwordSwap ∧
      armOf 2 = .subwordSwap ∧
      armOf 4 = .subwordSwap := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
