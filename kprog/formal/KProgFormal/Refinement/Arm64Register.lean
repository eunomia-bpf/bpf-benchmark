import KProgFormal.Reference.AArch64
import KProgFormal.Arm64RegDispatch
import KProgFormal.Arm64WriteArmShape
import KProgFormal.Generated.GeneratedArm64Width

namespace KProgFormal.Refinement.Arm64Register

open Reference
open Reference.AArch64 (Width Register Gpr)

def handlerWidth : Width → GeneratedArm64Width.Width
  | .w32 => .w32 | .w64 => .w64

def registerCode (r : Register) : BitVec 8 := BitVec.ofNat 8 r.val

theorem cell_refines (r : Register) :
    GeneratedArm64RegDispatch.cellOf (registerCode r) =
      (if r.val < 31 then some r.val else none) := by
  simp only [GeneratedArm64RegDispatch.cellOf, GeneratedArm64RegDispatch.gprCount,
    registerCode, BitVec.toNat_ofNat]
  rw [Nat.mod_eq_of_lt (by omega)]

/-- The cell array contains X0..X30; every arithmetic source field31 reads ZR. -/
def readReg (s : Reference.AArch64.State) (r : Register) : Reference.Word :=
  match GeneratedArm64RegDispatch.cellOf (registerCode r) with
  | some index => s.gpr ⟨index % 31, Nat.mod_lt _ (by decide)⟩
  | none => 0

theorem read_refines (s : Reference.AArch64.State) (r : Register) :
    readReg s r = Reference.AArch64.readReg s r := by
  by_cases h : r.val < 31 <;>
    simp [readReg, cell_refines, Reference.AArch64.readReg, h, Nat.mod_eq_of_lt]

/-- Actual write-arm selection follows the generated width mask and the
32-bit store through the GPR cell's integer member. -/
def writeValue (width : Width) (value : Reference.Word) : Reference.Word :=
  let value := GeneratedArm64Width.narrow value (handlerWidth width)
  match GeneratedArm64WriteArm.armOf (decide (width = .w32)) with
  | .narrow => (value.setWidth 32).setWidth 64
  | .full => value

theorem write_value_refines (width : Width) (value : Reference.Word) :
    writeValue width value = Reference.AArch64.narrow value width := by
  cases width <;>
    simp only [writeValue, handlerWidth, GeneratedArm64Width.narrow,
      GeneratedArm64Width.mask, GeneratedArm64WriteArm.armOf,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.Word, beq_self_eq_true, Bool.false_eq_true, reduceCtorEq, ↓reduceIte] <;> bv_decide

/-- Generated destination presence/cell dispatch discards ZR, for all32 native
register fields, with no assumption about the previous value or tag. -/
theorem write_selection : ∀ (dst : Register) (i : Gpr),
    (GeneratedArm64RegPresence.writable (registerCode dst) &&
      (GeneratedArm64RegDispatch.cellOf (registerCode dst) == some i.val)) =
      (i.val == dst.val) := by native_decide

def writeReg (s : Reference.AArch64.State) (dst : Register) (value : Reference.Word)
    (width : Width) : Reference.AArch64.State :=
  { s with gpr := fun i =>
      if GeneratedArm64RegPresence.writable (registerCode dst) &&
          (GeneratedArm64RegDispatch.cellOf (registerCode dst) == some i.val)
      then writeValue width value else s.gpr i }

theorem write_refines (s : Reference.AArch64.State) (dst : Register)
    (value : Reference.Word) (width : Width) :
    writeReg s dst value width =
      Reference.AArch64.writeReg s dst (Reference.AArch64.narrow value width) := by
  simp only [writeReg, Reference.AArch64.writeReg, write_selection,
    write_value_refines, beq_iff_eq]

end KProgFormal.Refinement.Arm64Register
