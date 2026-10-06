import KinsnLean4.Kinsn.ModuleDispatch

namespace Kinsn.ModuleControlDispatch
open ModuleDispatch (bitTest selected)

/-- x86/bpf_x86_rotate.c:instantiate_rotate_tree. Leaves may contain local
    branches. Their supplied continuation theorem establishes that no path
    escapes the leaf into a different branch or bypasses its continuation. -/
def tree (count : BPF.Reg) (leaf : Nat → List BPF.MInsn) : Nat → Nat → List BPF.MInsn
  | 0, base => leaf base
  | k+1, base =>
    let low := tree count leaf k base
    let high := tree count leaf k (base + 2^k)
    [.branch .bitSet .w64 count (.imm (BitVec.ofNat 64 (2^k))) (low.length+1)] ++
      low ++ [.ja high.length] ++ high

theorem exec_tree (count : BPF.Reg) (leaf : Nat → List BPF.MInsn)
    (effect : Nat → BPF.State → BPF.State)
    (hf : ∀ n s tail, BPF.mexec (leaf n ++ tail) s = BPF.mexec tail (effect n s))
    (depth base : Nat) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (tree count leaf depth base ++ tail) s =
      BPF.mexec tail (effect (selected (s.regs count) depth base) s) := by
  induction depth generalizing base tail with
  | zero => exact hf base s tail
  | succ k ih =>
    simp only [tree, List.append_assoc, List.cons_append, List.nil_append]
    rw [BPF.mexec]
    change (if bitTest (s.regs count) k then _ else _) = _
    split
    · simp only [List.drop_append, List.drop_eq_nil_of_le (by omega :
          (tree count leaf k base).length ≤ (tree count leaf k base).length+1),
        Nat.add_sub_cancel_left, List.drop_succ_cons, List.drop_zero, List.nil_append]
      simpa [selected, ‹bitTest (s.regs count) k = true›] using ih (base + 2^k) tail
    · rw [ih]
      have h : bitTest (s.regs count) k = false := by
        simpa using ‹¬ bitTest (s.regs count) k = true›
      simp [BPF.mexec, selected, h]

theorem writes_tree (count : BPF.Reg) (leaf : Nat → List BPF.MInsn)
    (depth base : Nat) (d : BPF.Reg)
    (hw : ∀ n r, r ∈ BPF.mwrites (leaf n) → r = d) :
    ∀ r, r ∈ BPF.mwrites (tree count leaf depth base) → r = d := by
  induction depth generalizing base with
  | zero => exact hw base
  | succ k ih =>
    intro r hr
    simp only [tree, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, List.nil_append, List.mem_append,
      List.mem_nil_iff, or_false] at hr
    exact hr.elim (ih base r) (ih (base+2^k) r)

end Kinsn.ModuleControlDispatch
