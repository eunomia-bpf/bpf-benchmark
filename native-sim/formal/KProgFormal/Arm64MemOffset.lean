import KProgFormal.GeneratedArm64MemOffset
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64MemOffset (value valueSpec)

/-- The generated address offset equals the independent four-case table. -/
theorem arm64_mem_offset_refines (prepost hasIndex : Bool)
    (imm index : BitVec 64) :
    value prepost hasIndex imm index =
      valueSpec prepost hasIndex imm index := by
  unfold value valueSpec
  cases prepost <;> cases hasIndex <;> bv_decide

/-- The four (prepost, hasIndex) cases of the independent table are the four
architectural load/store addressing forms. Every case is reachable, so no arm of
the contract is dead. -/
theorem arm64_mem_offset_case_dispatch (imm index : BitVec 64) :
    valueSpec false false imm index = imm ∧
    valueSpec false true imm index = imm + index ∧
    valueSpec true false imm index = 0 ∧
    valueSpec true true imm index = index := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- A pre/post-indexed access ignores the immediate in this offset, so its
result is the index (or zero) regardless of the immediate. -/
theorem arm64_mem_offset_prepost_ignores_immediate (imm imm' index : BitVec 64) :
    value true true imm index = value true true imm' index ∧
    value true false imm index = value true false imm' index := by
  unfold value
  refine ⟨?_, ?_⟩ <;> bv_decide

/-- Canonical example: an offset access with an index adds both. -/
theorem arm64_mem_offset_indexed_example :
    valueSpec false true 16 (-8) = 8 := by
  native_decide

/-- Canonical example: an offset access with no index is the immediate alone. -/
theorem arm64_mem_offset_plain_example :
    valueSpec false false 0xfffffffffffffff8 123 = 0xfffffffffffffff8 := by
  native_decide

/-- Canonical example: a pre/post-indexed access carries no immediate. -/
theorem arm64_mem_offset_prepost_example :
    valueSpec true false 64 0 = 0 ∧ valueSpec true true 64 32 = 32 := by
  native_decide

end KProgFormal
