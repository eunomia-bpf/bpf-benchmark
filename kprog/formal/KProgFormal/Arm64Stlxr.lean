import KProgFormal.Generated.GeneratedArm64Stlxr
import KProgFormal.Generated.GeneratedArm64Width
import KProgFormal.Refinement.Arm64Exclusive

namespace KProgFormal

open GeneratedArm64Stlxr (Stlxr value)
open GeneratedArm64Width (Width narrow)

/-- Explicit outcome encoding; this does not choose a monitor outcome. -/
def arm64StlxrSpec (_op : Stlxr) (width : Width) (failure : Bool) : BitVec 64 :=
  narrow (BitVec.ofNat 64 failure.toNat) width

theorem arm64_stlxr_refines (op : Stlxr) (width : Width) (failure : Bool) :
    value op width failure = arm64StlxrSpec op width failure := by
  cases op <;> cases width <;> cases failure <;> decide

theorem arm64_stlxr_success_zero (op : Stlxr) (width : Width) :
    value op width false = 0 := by
  cases op <;> cases width <;> decide

theorem arm64_stlxr_failure_one (op : Stlxr) (width : Width) :
    value op width true = 1 := by
  cases op <;> cases width <;> decide

/-- Select from the authoritative physical-monitor/environment model. -/
theorem arm64_stlxr_canonical_status (s : Reference.AArch64.State) (bytes : Nat) :
    value .stlxr .w32 (!Reference.AArch64.exclusiveStorePass s bytes) =
      (if Reference.AArch64.exclusiveStorePass s bytes then 0 else 1) := by
  cases h : Reference.AArch64.exclusiveStorePass s bytes <;> decide

theorem arm64_stlxr_empty_monitor_status (s : Reference.AArch64.State) (bytes : Nat)
    (h : s.exclusiveMonitor = none) :
    value .stlxr .w32 (!Reference.AArch64.exclusiveStorePass s bytes) = 1 := by
  rw [Refinement.Arm64Exclusive.empty_monitor_fails s bytes h]
  decide

theorem arm64_stlxr_code_in_range (op : Stlxr) :
    56 ≤ GeneratedArm64Stlxr.code op ∧ GeneratedArm64Stlxr.code op ≤ 56 := by
  cases op <;> decide

theorem arm64_stlxr_code_dispatch : GeneratedArm64Stlxr.code .stlxr = 56 := by decide

theorem arm64_stlxr_flags_unchanged (op : Stlxr) :
    GeneratedArm64Stlxr.flagsUnchanged op = true := by
  cases op <;> rfl

theorem arm64_stlxr_w32_bound (op : Stlxr) (failure : Bool) :
    value op .w32 failure >>> 32 = 0 := by
  cases op <;> cases failure <;> decide

theorem arm64_stlxr_example : arm64StlxrSpec .stlxr .w64 false = 0 := by decide
theorem arm64_stlxr_w32_example : arm64StlxrSpec .stlxr .w32 true = 1 := by decide

end KProgFormal
