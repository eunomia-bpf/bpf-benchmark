import KProgFormal.GeneratedX86ShiftCount
import KProgFormal.X86Width

namespace KProgFormal

def x86ShiftCountSpec (rhs : BitVec 64) (width : X86Width) : Nat :=
  rhs.toNat % (if width = .w64 then 64 else 32)

theorem x86_shift_count_refines (rhs : BitVec 64) (width : X86Width) :
    (GeneratedX86ShiftCount.count rhs width).toNat =
      x86ShiftCountSpec rhs width := by
  cases width <;> simp [GeneratedX86ShiftCount.count,
    GeneratedX86ShiftCount.mask, x86ShiftCountSpec,
    BitVec.toNat_and]
  case w8 => simpa using Nat.and_two_pow_sub_one_eq_mod rhs.toNat 5
  case w16 => simpa using Nat.and_two_pow_sub_one_eq_mod rhs.toNat 5
  case w32 => simpa using Nat.and_two_pow_sub_one_eq_mod rhs.toNat 5
  case w64 => simpa using Nat.and_two_pow_sub_one_eq_mod rhs.toNat 6

theorem x86_shift_count_bound (rhs : BitVec 64) (width : X86Width) :
    x86ShiftCountSpec rhs width < (if width = .w64 then 64 else 32) := by
  cases width <;> simp [x86ShiftCountSpec, Nat.mod_lt]

end KProgFormal
