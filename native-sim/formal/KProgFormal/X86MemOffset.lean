import KProgFormal.GeneratedX86MemOffset
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86MemOffset (value valueSpec)

/-- The generated effective-address offset equals the independent two-case
table. The index contribution is a left shift by the scale exponent, matching
the C macro's `__u64 << __u8` (whose amount is taken modulo the word width,
exactly as `BitVec`'s shift is). -/
theorem x86_mem_offset_refines (hasIndex : Bool) (scale disp index : BitVec 64) :
    value hasIndex scale disp index = valueSpec hasIndex scale disp index := by
  unfold value valueSpec
  cases hasIndex <;> bv_decide

/-- The two `hasIndex` cases of the independent table are the two
architectural addressing forms: a displacement-only access and an indexed
access. Every case is reachable, so no arm of the contract is dead. -/
theorem x86_mem_offset_case_dispatch (scale disp index : BitVec 64) :
    valueSpec true scale disp index = disp + (index <<< scale) ∧
      valueSpec false scale disp index = disp := by
  refine ⟨rfl, rfl⟩

/-- A displacement-only access ignores the index value and the scale: its
result is the displacement regardless of either. -/
theorem x86_mem_offset_plain_ignores_index (scale scale' disp index index' :
    BitVec 64) :
    value false scale disp index = value false scale' disp index' := by
  unfold value
  bv_decide

/-- Scale exponents are base-2 logarithms, so an index that is one contributes
two to the offset for scale exponent one, four for exponent two, and eight for
exponent three — the arch's encoded scale factors 2, 4, and 8. -/
theorem x86_mem_offset_scale_is_power_of_two (disp index : BitVec 64) :
    valueSpec true 1 disp index = disp + index * 2 ∧
      valueSpec true 2 disp index = disp + index * 4 ∧
      valueSpec true 3 disp index = disp + index * 8 := by
  unfold valueSpec
  refine ⟨?_, ?_, ?_⟩ <;> bv_decide

/-- Canonical example: an indexed access with a negative displacement adds the
scaled index in the 64-bit wrap-around domain. -/
theorem x86_mem_offset_indexed_example :
    valueSpec true 2 (-8) 5 = 12 := by
  native_decide

/-- Canonical example: an indexed access whose scaled index wraps past 2^64. -/
theorem x86_mem_offset_indexed_wrap_example :
    valueSpec true 3 0 0xf000000000000000 = 0x8000000000000000 := by
  native_decide

/-- Canonical example: a displacement-only access with a negative displacement
is the sign-extended displacement, unaffected by the (unused) index. -/
theorem x86_mem_offset_plain_example :
    valueSpec false 3 0xfffffffffffffff8 123 = 0xfffffffffffffff8 := by
  native_decide

end KProgFormal
