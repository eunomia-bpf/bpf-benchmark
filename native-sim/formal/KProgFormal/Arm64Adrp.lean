import KProgFormal.GeneratedArm64Adrp

namespace KProgFormal

open GeneratedArm64Adrp (Op tag isGot code)

/-- Independent statement of the two ADRP relocation tags, indexed by a Boolean
rather than by the opcode: the GOT form is the relocation-address tag and the
RODATA form is one higher. The generated `tag` match is therefore not a
restatement of this expression. -/
def arm64AdrpTagSpec (isGotKind : Bool) : Nat :=
  7 + (if isGotKind then 0 else 1)

/-- The generated tag table agrees with the independent Boolean-indexed
selection for both relocation kinds. -/
theorem arm64_adrp_tag_refines (op : Op) :
    tag op = arm64AdrpTagSpec (isGot op) := by
  cases op <;> rfl

/-- The GOT/RODATA classification matches the opcode itself: only the GOT
opcode is the GOT kind. -/
theorem arm64_adrp_isgot_refines (op : Op) :
    isGot op = (op == Op.got) := by
  cases op <;> decide

/-- The two opcodes are pinned to the ARM64_OP_ADRP_* numbers the C macro
switches on. -/
theorem arm64_adrp_code_dispatch :
    code .got = 38 ∧ code .rodata = 39 := by
  decide

/-- The two relocation kinds carry distinct provenance tags, so a mislabeled
GOT/RODATA split changes the observable tag. -/
theorem arm64_adrp_tags_distinct :
    tag .got ≠ tag .rodata := by
  decide

/-- The tags lie inside the ARM64_SIM_TAG_* range the simulator defines, so the
selection never returns a tag outside the register-file tag table. -/
theorem arm64_adrp_tag_in_range (op : Op) :
    7 ≤ tag op ∧ tag op ≤ 8 := by
  cases op <;> decide

end KProgFormal
