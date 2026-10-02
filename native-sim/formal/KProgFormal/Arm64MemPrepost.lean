import KProgFormal.GeneratedArm64MemPrepost
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64MemPrepost (flags)

/-- The generated flag byte equals the independent top-byte decode `aux >>> 24`
masked to 8 bits. -/
theorem arm64_mem_prepost_flags_refines (aux : BitVec 32) :
    (flags aux).toNat = (aux.toNat >>> 24) &&& 255 := by
  unfold flags
  simp only [BitVec.toNat_ofNat]
  have h : (255 : Nat) = 2 ^ 8 - 1 := by decide
  rw [h, Nat.and_two_pow_sub_one_eq_mod]
/-- **The pre bit is the pre-indexed writeback gate**: a pre-indexed access
applies the immediate exactly when `MEM_PRE` is set in the flag byte. -/
theorem arm64_mem_prepost_pre_writeback (aux : BitVec 32) :
    GeneratedArm64MemPrepost.preWriteback aux =
      ((flags aux).toNat &&& 1 != 0) := by
  rfl

/-- **The post bit is the post-indexed writeback gate**, independent of the pre
bit. -/
theorem arm64_mem_prepost_post_writeback (aux : BitVec 32) :
    GeneratedArm64MemPrepost.postWriteback aux =
      ((flags aux).toNat &&& 2 != 0) := by
  rfl

/-- **The offset suppresses the immediate exactly when the flag byte requests an
independent writeback**: the union of the pre and post bits, so an offset access
(`0`) keeps the immediate and any pre/post access drops it. -/
theorem arm64_mem_prepost_suppress_offset (aux : BitVec 32) :
    GeneratedArm64MemPrepost.suppressOffset aux = true ↔
      ((flags aux).toNat &&& 1 != 0 ∨ (flags aux).toNat &&& 2 != 0) := by
  unfold GeneratedArm64MemPrepost.suppressOffset
    GeneratedArm64MemPrepost.preWriteback
    GeneratedArm64MemPrepost.postWriteback
  simp

/-- The generated pre/post deltas equal the independent raw-flag statements. -/
theorem arm64_mem_prepost_delta_refines (aux : BitVec 32) (imm : BitVec 64) :
    GeneratedArm64MemPrepost.preDelta aux imm =
        GeneratedArm64MemPrepost.preDeltaSpec (flags aux).toNat imm ∧
      GeneratedArm64MemPrepost.postDelta aux imm =
        GeneratedArm64MemPrepost.postDeltaSpec (flags aux).toNat imm := by
  unfold GeneratedArm64MemPrepost.preDelta
    GeneratedArm64MemPrepost.postDelta
    GeneratedArm64MemPrepost.preDeltaSpec
    GeneratedArm64MemPrepost.postDeltaSpec
    GeneratedArm64MemPrepost.preWriteback
    GeneratedArm64MemPrepost.postWriteback
    flags
  exact ⟨rfl, rfl⟩

/-- **The two writebacks are independent**: for every flag byte the writeback-form
ordinal is the sum of the two gates, so `MEM_PRE` alone and `MEM_POST` alone each
give one writeback, `MEM_PRE | MEM_POST` gives two, and `0` gives none. -/
theorem arm64_mem_prepost_form_is_sum (aux : BitVec 32) :
    GeneratedArm64MemPrepost.writebackFormSpec (flags aux).toNat =
      (if GeneratedArm64MemPrepost.preWriteback aux then 1 else 0) +
      (if GeneratedArm64MemPrepost.postWriteback aux then 1 else 0) := by
  unfold GeneratedArm64MemPrepost.writebackFormSpec
    GeneratedArm64MemPrepost.preWriteback
    GeneratedArm64MemPrepost.postWriteback
    flags
  rfl

/-- The form ordinal is bounded by the two bits: never more than two writebacks,
so no flag byte yields a third writeback the macros do not implement. -/
theorem arm64_mem_prepost_form_bounded (flags8 : BitVec 8) :
    GeneratedArm64MemPrepost.writebackFormSpec flags8.toNat ≤ 2 := by
  unfold GeneratedArm64MemPrepost.writebackFormSpec
  split <;> split <;> omega

/-- Canonical example: a plain offset access (flag byte `0`) suppresses nothing,
so it keeps the immediate and requests zero writebacks. -/
theorem arm64_mem_prepost_offset_example :
    GeneratedArm64MemPrepost.suppressOffset
        (BitVec.ofNat 32 (0 <<< 24)) = false ∧
      GeneratedArm64MemPrepost.writebackFormSpec 0 = 0 ∧
      GeneratedArm64MemPrepost.preDeltaSpec 0 0x40 = 0 := by
  refine ⟨by decide, by decide, by decide⟩

/-- Canonical example: a post-indexed access (flag byte `2`) keeps the offset
immediate suppressed and requests one writeback, applied after the access. -/
theorem arm64_mem_prepost_post_example :
    GeneratedArm64MemPrepost.suppressOffset
        (BitVec.ofNat 32 (2 <<< 24)) = true ∧
      GeneratedArm64MemPrepost.writebackFormSpec 2 = 1 ∧
      GeneratedArm64MemPrepost.postDeltaSpec 2 0x40 = 0x40 ∧
      GeneratedArm64MemPrepost.preDeltaSpec 2 0x40 = 0 := by
  refine ⟨by decide, by decide, by decide, by decide⟩

/-- Canonical example: `MEM_PRE | MEM_POST` (flag byte `3`) applies the same
immediate twice, once before and once after the access. -/
theorem arm64_mem_prepost_both_example :
    GeneratedArm64MemPrepost.writebackFormSpec 3 = 2 ∧
      GeneratedArm64MemPrepost.preDeltaSpec 3 0x40 = 0x40 ∧
      GeneratedArm64MemPrepost.postDeltaSpec 3 0x40 = 0x40 := by
  refine ⟨by decide, by decide, by decide⟩

end KProgFormal
