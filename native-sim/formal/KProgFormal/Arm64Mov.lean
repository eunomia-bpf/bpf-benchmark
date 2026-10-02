import KProgFormal.GeneratedArm64Mov
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Mov (Mov ptrTagPath code mnemonic)
open GeneratedArm64Width (Width)

/-- Independent statement of which move/width pairs preserve the source
provenance tag: exactly the register-source move at doubleword width. -/
def arm64MovSpec (op : Mov) (width : Width) : Bool :=
  op == .movReg && width == .w64
/-- The generated MOV provenance-path table agrees with the independent
statement on every (move, width) pair. -/
theorem arm64_mov_path_refines (op : Mov) (width : Width) :
    ptrTagPath op width = arm64MovSpec op width := by
  cases op <;> cases width <;> decide

/-- Only the register-source move can ever preserve provenance, at any width. -/
theorem arm64_mov_imm_never_ptr (width : Width) :
    ptrTagPath .movImm width = false := by
  cases width <;> rfl

/-- The register-source move preserves provenance exactly at doubleword width. -/
theorem arm64_mov_reg_ptr_iff_w64 (width : Width) :
    ptrTagPath .movReg width = true ↔ width = .w64 := by
  cases width <;> simp [ptrTagPath]

/-- The register-source move drops provenance at every sub-word width. -/
theorem arm64_mov_reg_sub_word_drops (width : Width) (h : width ≠ .w64) :
    ptrTagPath .movReg width = false := by
  cases width <;> simp_all [ptrTagPath]

/-- The two move opcodes are pinned to their numeric case-label codes. -/
theorem arm64_mov_code_dispatch :
    code .movImm = 1 ∧ code .movReg = 2 := by
  decide

/-- The MOV_IMM opcode lies inside the numeric case-label range used by the
shared C macro. -/
theorem arm64_mov_imm_code_in_range :
    1 ≤ code .movImm ∧ code .movImm ≤ 2 := by
  decide

/-- The MOV_REG opcode lies inside the numeric case-label range used by the
shared C macro. -/
theorem arm64_mov_reg_code_in_range :
    1 ≤ code .movReg ∧ code .movReg ≤ 2 := by
  decide

/-- Both moves preserve or drop provenance by the width of the access, never by
the mnemonic alone: for each move there is a width that drops the tag. -/
theorem arm64_mov_width_matters (op : Mov) :
    ∃ width, ptrTagPath op width = false := by
  cases op
  · exact ⟨.w64, rfl⟩
  · exact ⟨.w32, rfl⟩

/-- Canonical example: the doubleword register move is the tag-copy path. -/
theorem arm64_mov_reg_ptr_example :
    arm64MovSpec .movReg .w64 = true := by
  decide

/-- Canonical example: the immediate move drops provenance even at doubleword
width. -/
theorem arm64_mov_imm_drops_example :
    arm64MovSpec .movImm .w64 = false := by
  decide

end KProgFormal
