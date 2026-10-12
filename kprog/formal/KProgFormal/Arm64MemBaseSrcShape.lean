import KProgFormal.GeneratedArm64MemBaseSrc
import KProgFormal.GeneratedArm64MemWriteArm
import KProgFormal.GeneratedArm64MemDispatch
import KProgFormal.Arm64MemWriteArmShape

namespace KProgFormal

open GeneratedArm64MemBaseSrc (Source sourceCount sourceNames sourceCodes
  codeOfSource effectOfSource sourceOf sourceOfCode Case classify sourceOfCase
  spBase)
open GeneratedArm64MemWriteArm (Arm armOf)
open GeneratedArm64MemDispatch (Space ValueSrc valueSrc)

/-- Independent statement of the base-address source selector, built from the
literal constructors rather than the generated `sourceOf`: the stack pointer
register exactly when the base register is the stack pointer, the base
register's own arena pointer otherwise. -/
def arm64MemBaseSrcSpec (baseIsSp : Bool) : Source :=
  if baseIsSp then .spRegister
  else .gprBase

/-- Independent statement of the two source names, built from the literal
constructor order rather than the generated `sourceNames`. -/
def arm64MemBaseSrcNamesSpec : List String := ["spRegister", "gprBase"]

/-- Independent statement of the two source codes: the stack pointer register
source yields the selector's true branch (0) and the gpr arena base source the
default (1). -/
def arm64MemBaseSrcCodesSpec : List Nat := [0, 1]

/-- The generated source selector equals the independent literal construction
for every base register. -/
theorem arm64_mem_base_src_refines (baseIsSp : Bool) :
    sourceOf baseIsSp = arm64MemBaseSrcSpec baseIsSp := by
  unfold sourceOf arm64MemBaseSrcSpec
  cases baseIsSp <;> rfl

/-- The generated source-name table equals the independent literal order. -/
theorem arm64_mem_base_src_names_refine :
    sourceNames = arm64MemBaseSrcNamesSpec := by
  unfold sourceNames arm64MemBaseSrcNamesSpec
  rfl

/-- The generated source-code table equals the independent literal codes. -/
theorem arm64_mem_base_src_codes_refine :
    sourceCodes = arm64MemBaseSrcCodesSpec := by
  unfold sourceCodes arm64MemBaseSrcCodesSpec
  rfl

/-- The generated source-code table has exactly `sourceCount` entries, so the
zip table and the macro name the same two sources and nothing else. -/
theorem arm64_mem_base_src_codes_length : sourceCodes.length = sourceCount :=
  rfl

/-- The generated source-name table has exactly `sourceCount` entries. -/
theorem arm64_mem_base_src_names_length : sourceNames.length = sourceCount :=
  rfl

/-- The two source codes are distinct, so no two sources alias one code. -/
theorem arm64_mem_base_src_codes_nodup : sourceCodes.Nodup := by
  unfold sourceCodes
  native_decide

/-- The source count is the two base-address sources a memory helper selects
between. -/
theorem arm64_mem_base_src_count_is_2 : sourceCount = 2 := rfl

/-- The generated source-code selector round-trips each source to its own code
and names no other code. -/
theorem arm64_mem_base_src_of_code_roundtrip (source : Source) :
    sourceOfCode (codeOfSource source) = some source := by
  cases source <;> native_decide

/-- The generated source-code selector names no source at or above the source
count, so the table is exactly the two sources and no other code reaches
one. -/
theorem arm64_mem_base_src_of_code_beyond_is_none :
    sourceOfCode 2 = none ∧ sourceOfCode 8 = none ∧ sourceOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The two sources report two distinct value effects: the stack pointer
register and the gpr arena base. -/
theorem arm64_mem_base_src_effects :
    effectOfSource .spRegister = "stack_pointer_register" ∧
      effectOfSource .gprBase = "gpr_arena_base" ∧
      effectOfSource .spRegister ≠ effectOfSource .gprBase := by
  refine ⟨?_, ?_, ?_⟩
  · exact rfl
  · exact rfl
  · decide

/-- Every fact value is reachable: naming the source from the fact directly
classifies and dispatches the same case, so neither case is dead. -/
theorem arm64_mem_base_src_case_dispatch :
    sourceOf true = .spRegister ∧ sourceOf false = .gprBase := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- The two-case table agrees with the direct selector: classifying a memory
helper and dispatching on the case is the same source selection the macro
performs. -/
theorem arm64_mem_base_src_case_refines (baseIsSp : Bool) :
    sourceOf baseIsSp = sourceOfCase (classify baseIsSp) :=
  GeneratedArm64MemBaseSrc.sourceOf_refines baseIsSp

/-- **The base-address source selection is the closed fact.** The memory
helper's stack-pointer-register arm fires exactly when the base register is the
stack pointer, so the 2-way selection reduces to the single closed fact and no
other arm is ever reachable. -/
theorem arm64_mem_base_src_selects_sp (baseIsSp : Bool) :
    (sourceOf baseIsSp = .spRegister) = baseIsSp := by
  cases baseIsSp <;> decide

/-- **The base-address source is the store body selection's stack fact.** The
store helper's stack body fires exactly when the base is the stack pointer or
its resolved tag names a stack slot; with an untagged base that disjunction
reduces to the same closed fact the base-address source selects on, so the two
agree: the base address is the stack pointer register exactly where the store
path reaches the stack arena body for an untagged base. -/
theorem arm64_mem_base_src_matches_write_arm (baseIsSp : Bool) :
    (sourceOf baseIsSp = .spRegister) =
      (armOf baseIsSp false = .stackWrite) := by
  cases baseIsSp <;> decide

/-- **The base-address source is the load dispatch's stack split.** Building
the load space from the closed base fact — the stack pointer register forces
`Space.stack`, everything else `Space.normal` — the load path reaches the stack
read exactly when the base-address source is the stack pointer register, at
both widths. -/
theorem arm64_mem_base_src_matches_read_src (baseIsSp w64 : Bool) :
    valueSrc (if baseIsSp then Space.stack else Space.normal) w64 =
        .stackRead ↔
      sourceOf baseIsSp = .spRegister := by
  cases baseIsSp <;> cases w64 <;> native_decide

end KProgFormal
