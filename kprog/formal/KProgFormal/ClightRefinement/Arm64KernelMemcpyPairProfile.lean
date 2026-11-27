import KProgFormal.ClightRefinement.Arm64KernelMemcpyPairMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPairProfile
open Arm64KernelMemcpyWriteMemory (updated)

/-- The two actual wrapping8byte initialization updates equal the single
actual16byte update, for arbitrary original initialization. -/
theorem split_initialized (profile : MemoryProfile) (address other : BitVec 64) :
    (updated (updated profile 8 address) 8 (address+8#64)).initialized other =
      (updated profile 16 address).initialized other := by
  have delta : other-(address+8#64) = (other-address)-8#64 := by bv_omega
  by_cases lower : (other-address).toNat < 8
  · have full : (other-address).toNat < 16 := by omega
    simp only [updated,ite_eq_left lower,ite_eq_left full,ite_self]
  · have enough : (8#64) ≤ other-address := by change 8 ≤ (other-address).toNat; omega
    have upper : (other-(address+8#64)).toNat < 8 ↔ (other-address).toNat < 16 := by
      rw [delta,BitVec.toNat_sub_of_le enough]
      change (other-address).toNat-8 < 8 ↔ (other-address).toNat < 16
      omega
    simp only [updated,ite_eq_right lower,upper]

/-- Both true STP modes have the same complete initialized output profile. -/
theorem profile_eq (profile : MemoryProfile) (address : BitVec 64) :
    Arm64KernelMemcpyPairWrite.finalProfile profile address = updated profile 16 address := by
  cases mode : profile.pairSingleAccess with
  | false =>
    simp only [Arm64KernelMemcpyPairWrite.finalProfile,mode,Bool.false_eq_true,ite_false]
    have initialized : (fun other => (updated (updated profile 8 address) 8 (address+8#64)).initialized other) =
        (fun other => (updated profile 16 address).initialized other) := by
      funext other
      exact split_initialized profile address other
    simpa only [updated] using congrArg (fun initialized => {profile with initialized := initialized}) initialized
  | true => simp only [Arm64KernelMemcpyPairWrite.finalProfile,mode,ite_true]

/-- Every actual destination byte is initialized in either native mode. -/
theorem inside (profile : MemoryProfile) (address : BitVec 64) (j : Fin 16) :
    (Arm64KernelMemcpyPairWrite.finalProfile profile address).initialized (address+BitVec.ofNat 64 j.val) = true := by
  rw [profile_eq]
  exact Arm64KernelMemcpyWriteMemory.initialized_inside profile 16 address (by decide) j

/-- Initialization outside the real wrapping16byte destination is retained. -/
theorem outside (profile : MemoryProfile) (address other : BitVec 64) (notWritten : 16 ≤ (other-address).toNat) :
    (Arm64KernelMemcpyPairWrite.finalProfile profile address).initialized other = profile.initialized other := by
  rw [profile_eq]
  exact Arm64KernelMemcpyWriteMemory.initialized_outside profile 16 address other notWritten

/-- Repeating the same real initialized-range update is idempotent. -/
theorem idempotent (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64) :
    updated (updated profile bytes address) bytes address = updated profile bytes address := by
  simp only [updated]
  congr 1
  funext other
  split <;> simp_all

/-- Both repeated STPs together initialize exactly the original16byte range. -/
theorem repeated_profile_eq (profile : MemoryProfile) (address : BitVec 64) :
    Arm64KernelMemcpyPairWrite.finalProfile (Arm64KernelMemcpyPairWrite.finalProfile profile address) address =
      updated profile 16 address := by
  rw [profile_eq,profile_eq,idempotent]

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPairProfile
