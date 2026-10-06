import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleDispatch

/-- A balanced JSET decision tree. Both children rejoin after the node; all
    tests precede the selected leaf's register writes. -/
def tree (count : BPF.Reg) (leaf : Nat → List BPF.Insn) : Nat → Nat → List BPF.MInsn
  | 0, base => (leaf base).map BPF.MInsn.core
  | k + 1, base =>
    let low := tree count leaf k base
    let high := tree count leaf k (base + 2^k)
    [.branch .bitSet .w64 count (.imm (BitVec.ofNat 64 (2^k))) (low.length + 1)] ++
      low ++ [.ja high.length] ++ high

/-- The branch result used by the concrete BPF JSET encoding. -/
def bitTest (v : BitVec 64) (k : Nat) : Bool :=
  BPF.Cond.test .bitSet .w64 v (BitVec.ofNat 64 (2^k))

def selected (v : BitVec 64) : Nat → Nat → Nat
  | 0, base => base
  | k + 1, base => selected v k (base + if bitTest v k then 2^k else 0)

theorem exec_core_tail (p : List BPF.Insn) (tail : List BPF.MInsn) (s : BPF.State) :
    BPF.mexec (p.map BPF.MInsn.core ++ tail) s =
      BPF.mexec tail { s with regs := BPF.exec p s.regs } := by
  induction p generalizing s with
  | nil => rfl
  | cons i p ih => simp [BPF.mexec, BPF.MInsn.step, ih]

theorem exec_tree (count : BPF.Reg) (leaf : Nat → List BPF.Insn)
    (depth base : Nat) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (tree count leaf depth base ++ tail) s =
      BPF.mexec tail
        { s with regs := BPF.exec (leaf (selected (s.regs count) depth base)) s.regs } := by
  induction depth generalizing base tail with
  | zero => exact exec_core_tail _ _ _
  | succ k ih =>
    simp only [tree, List.append_assoc, List.cons_append, List.nil_append]
    rw [BPF.mexec]
    change (if bitTest (s.regs count) k then _ else _) = _
    split
    · simp only [List.drop_append, List.drop_eq_nil_of_le (by omega :
          (tree count leaf k base).length ≤ (tree count leaf k base).length + 1),
        Nat.add_sub_cancel_left,
        List.drop_succ_cons, List.drop_zero, List.nil_append]
      simpa [selected, ‹bitTest (s.regs count) k = true›] using
        ih (base + 2^k) tail
    · rw [ih]
      have hf : bitTest (s.regs count) k = false := by
        simpa using ‹¬ bitTest (s.regs count) k = true›
      simp [BPF.mexec, selected, hf]

theorem bitTest_eq (v : BitVec 64) (k : Nat) (hk : k < 64) :
    bitTest v k = v.getLsbD k := by
  have hm (i : Nat) (hi : i < 64) :
      (BitVec.ofNat 64 (2^k)).getLsbD i = decide (k = i) := by
    simp only [BitVec.getLsbD_ofNat, Nat.testBit_two_pow, decide_eq_true hi, Bool.true_and]
  by_cases h : v.getLsbD k = true
  · have hn : v &&& BitVec.ofNat 64 (2^k) ≠ 0#64 := by
      intro hz
      have hb := congrArg (fun x : BitVec 64 => x.getLsbD k) hz
      simp [hm k hk, h] at hb
    simp [bitTest, BPF.Cond.test, BPF.Cond.eval, hn, h]
  · have hz : v &&& BitVec.ofNat 64 (2^k) = 0#64 := by
      apply BitVec.eq_of_getLsbD_eq
      intro i hi
      by_cases he : k = i
      · subst i; simp [hm k hk, h]
      · simp [hm i hi, he]
    simp [bitTest, BPF.Cond.test, BPF.Cond.eval, hz, h]

theorem selected_eq (v : BitVec 64) (depth base : Nat) (hd : depth ≤ 64) :
    selected v depth base = base + v.toNat % 2^depth := by
  induction depth generalizing base with
  | zero => simp [selected, Nat.mod_one]
  | succ k ih =>
    rw [selected, ih _ (by omega), bitTest_eq v k (by omega), Nat.mod_pow_succ]
    have hb : v.toNat / 2^k % 2 = (v.getLsbD k).toNat :=
      (Nat.toNat_testBit v.toNat k).symm
    rw [hb]
    cases v.getLsbD k <;> simp [Nat.add_assoc, Nat.add_comm]

theorem writes_tree (count : BPF.Reg) (leaf : Nat → List BPF.Insn)
    (depth base : Nat) (d : BPF.Reg)
    (hw : ∀ n r, r ∈ BPF.writes (leaf n) → r = d) :
    ∀ r, r ∈ BPF.mwrites (tree count leaf depth base) → r = d := by
  induction depth generalizing base with
  | zero =>
    intro r hr
    apply hw base r
    simpa [tree, BPF.mwrites, BPF.writes, List.mem_flatMap, BPF.MInsn.writes, eq_comm] using hr
  | succ k ih =>
    intro r hr
    simp only [tree, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, List.nil_append, List.mem_append,
      List.mem_nil_iff, or_false] at hr
    exact hr.elim (ih base r) (ih (base + 2^k) r)

end Kinsn.ModuleDispatch
