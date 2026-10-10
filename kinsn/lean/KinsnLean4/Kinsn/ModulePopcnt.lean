import KinsnLean4.Kinsn.ModuleRotateOne
import KinsnLean4.Kinsn.ModuleControlDispatch
namespace Kinsn.ModulePopcnt

def ones : Nat → BitVec 64 → Nat
  | 0, _ => 0
  | n+1, v => ones n (v >>> 1) + if v.getLsbD 0 then 1 else 0

def zeros : Nat → BitVec 64 → Nat
  | 0, _ => 0
  | n+1, v => zeros n (v >>> 1) + if v.getLsbD 0 then 0 else 1

theorem partition (n : Nat) (v : BitVec 64) : ones n v + zeros n v = n := by
  induction n generalizing v with
  | zero => rfl
  | succ n ih =>
    have h := ih (v >>> 1)
    cases he : v.getLsbD 0 <;>
      simp only [ones, zeros, he, Bool.false_eq_true, ↓reduceIte] <;> omega

theorem ones_filter (n : Nat) (v : BitVec 64) :
    ones n v = ((List.range n).filter (fun i => v.getLsbD i)).length := by
  induction n generalizing v with
  | zero => rfl
  | succ n ih =>
    simp only [ones, List.range_succ_eq_map, List.filter_cons, List.filter_map,
      ih, Function.comp_def, Nat.succ_eq_add_one,
      BitVec.getLsbD_ushiftRight, Nat.add_comm]
    split <;> simp_all [Nat.add_comm]

theorem ones_le (n : Nat) (v : BitVec 64) : ones n v ≤ n := by
  have hp := partition n v
  omega

theorem ones_succ (n : Nat) (v : BitVec 64) :
    ones (n+1) v = ones n v + if v.getLsbD n then 1 else 0 := by
  rw [ones_filter, List.range_succ, List.filter_append, List.length_append]
  cases he : v.getLsbD n <;> simp [← ones_filter, he]

def rotate (d : BPF.Reg) (n : Nat) : List BPF.MInsn := ModuleRotateOne.repeated true d n

def set (d : BPF.Reg) (v : BitVec 64) (s : BPF.State) : BPF.State :=
  { s with regs := BPF.RegFile.set s.regs d v }

theorem rotate_exec (d : BPF.Reg) (n : Nat) (hn : n < 64)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (rotate d n ++ tail) s = BPF.mexec tail (set d ((s.regs d).rotateLeft n) s) := by
  rw [rotate, ModuleRotateOne.repeated_exec]
  have hr := ModuleRotateOne.iterate_rotate true (s.regs d) n hn
  simpa [ModuleRotateOne.bits, set] using congrArg
    (fun v => BPF.mexec tail {s with regs := BPF.RegFile.set s.regs d v}) hr

theorem rotate_bit (k : Nat) (hk : 0 < k ∧ k < 64) (v : BitVec 64) :
    (v.rotateLeft (64-k)).getLsbD 0 = v.getLsbD k := by
  rw [BitVec.getLsbD_rotateLeft_of_le (by omega : 64-k < 64)]
  simp [show 0 < 64-k by omega, show 64-(64-k)=k by omega]

theorem rotate_back (k : Nat) (hk : 0 < k ∧ k < 64) (v : BitVec 64) :
    (v.rotateLeft (64-k)).rotateLeft k = v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [BitVec.getLsbD_rotateLeft_of_le hk.2]
  by_cases hik : i < k
  · simp only [hik, ↓reduceIte]
    rw [BitVec.getLsbD_rotateLeft_of_le (by omega : 64-k < 64)]
    simp [show ¬64-k+i < 64-k by omega, show 64-k+i < 64 by omega,
      show 64-k+i-(64-k)=i by omega]
  · simp only [hik, ↓reduceIte, hi, decide_true, Bool.true_and]
    rw [BitVec.getLsbD_rotateLeft_of_le (by omega : 64-k < 64)]
    simp [Nat.mod_eq_of_lt (by omega : 64-k < 64), show i-k < 64-k by omega, show 64-(64-k)+(i-k)=i by omega]

theorem rotate_clear (k : Nat) (hk : 0 < k ∧ k < 64) (v : BitVec 64) :
    (v.rotateLeft (64-k) &&& ~~~(1#64)).rotateLeft k = v &&& ~~~(1#64 <<< k) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [BitVec.getLsbD_rotateLeft_of_le hk.2]
  by_cases hik : i < k
  · simp only [hik, ↓reduceIte]
    simp only [BitVec.getLsbD_and, BitVec.getLsbD_not]
    rw [BitVec.getLsbD_rotateLeft_of_le (by omega : 64-k < 64)]
    simp [show ¬64-k+i < 64-k by omega, show 64-k+i < 64 by omega,
      show 64-k+i-(64-k)=i by omega, BitVec.getLsbD_shiftLeft, hik, hi,
      show 64-k+i ≠ 0 by omega, show 64-k ≠ 0 by omega]
  · simp only [hik, ↓reduceIte, hi, decide_true, Bool.true_and]
    simp only [BitVec.getLsbD_and, BitVec.getLsbD_not]
    rw [BitVec.getLsbD_rotateLeft_of_le (by omega : 64-k < 64)]
    simp [Nat.mod_eq_of_lt (by omega : 64-k < 64), show i-k < 64-k by omega, show 64-(64-k)+(i-k)=i by omega,
      BitVec.getLsbD_shiftLeft, hik, hi, show i-k < 64 by omega]

def stepLeaf (d : BPF.Reg) (k n : Nat) : List BPF.MInsn :=
  if n = 0 then rotate d k else
    [.core (.alu .and .w64 d (.imm 18446744073709551614))] ++ rotate d k ++
      [.core (.alu .add .w64 d (.imm 1))]

def stepEffect (d : BPF.Reg) (k n : Nat) (s : BPF.State) : BPF.State :=
  set d (if n = 0 then (s.regs d).rotateLeft k else
    (s.regs d &&& ~~~(1#64)).rotateLeft k + 1) s

theorem step_leaf_exec (d : BPF.Reg) (k n : Nat) (hk : k < 64)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (stepLeaf d k n ++ tail) s = BPF.mexec tail (stepEffect d k n s) := by
  by_cases hn : n = 0
  · simpa [stepLeaf, hn, stepEffect] using rotate_exec d k hk s tail
  · simp only [stepLeaf, if_neg hn, List.append_assoc, List.cons_append, List.nil_append,
      BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval]
    rw [rotate_exec d k hk]
    simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      stepEffect, set, Machine.State.set, BPF.RegFile.set_same, BPF.RegFile.set_set_same, hn]

def iteration (d : BPF.Reg) (k : Nat) : List BPF.MInsn :=
  rotate d (64-k) ++ ModuleControlDispatch.tree d (stepLeaf d k) 1 0

def stepValue (k : Nat) (v : BitVec 64) : BitVec 64 :=
  if v.getLsbD k then (v &&& ~~~(1#64 <<< k)) + 1 else v

theorem iteration_exec (d : BPF.Reg) (k : Nat) (hk : 0 < k ∧ k < 64)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (iteration d k ++ tail) s =
      BPF.mexec tail (set d (stepValue k (s.regs d)) s) := by
  simp only [iteration, List.append_assoc]
  rw [rotate_exec d (64-k) (by omega), ModuleControlDispatch.exec_tree d
    (stepLeaf d k) (stepEffect d k) (fun n => step_leaf_exec d k n hk.2) 1 0]
  simp only [ModuleDispatch.selected, ModuleDispatch.bitTest_eq _ 0 (by decide)]
  simp only [set, BPF.RegFile.set_same, rotate_bit k hk]
  cases he : (s.regs d).getLsbD k <;>
    simp only [stepEffect, set, he, stepValue, ↓reduceIte, Bool.false_eq_true,
      Nat.zero_add, Nat.zero_eq, reduceCtorEq,
      show (18446744073709551614 : BitVec 64) = ~~~(1#64) by decide +kernel, BPF.RegFile.set_same,
      BPF.RegFile.set_set_same, rotate_back k hk, rotate_clear k hk] <;> simp


def keep (k : Nat) (v : BitVec 64) : BitVec 64 := (v >>> k) <<< k

def packed (k : Nat) (v : BitVec 64) (c : Nat) : BitVec 64 :=
  keep k v ||| BitVec.ofNat 64 c

theorem keep_bit (k i : Nat) (v : BitVec 64) :
    (keep k v).getLsbD i = (decide (k ≤ i) && v.getLsbD i) := by
  by_cases hi : i < 64
  · by_cases hk : k ≤ i
    · simp [keep, BitVec.getLsbD_shiftLeft, BitVec.getLsbD_ushiftRight, hi, hk,
        show ¬i < k by omega, show k+(i-k)=i by omega]
    · simp [keep, BitVec.getLsbD_shiftLeft, hi, hk, show i < k by omega]
  · rw [BitVec.getLsbD_of_ge v i (by omega : 64 ≤ i),
      BitVec.getLsbD_of_ge (keep k v) i (by omega : 64 ≤ i)]
    simp

theorem count_bit (c i : Nat) (hc : c < 128) (hi : 7 ≤ i) :
    (BitVec.ofNat 64 c).getLsbD i = false := by
  have hp : 128 ≤ 2^i := by
    have h := Nat.pow_le_pow_right (by decide : 1 ≤ 2) hi
    norm_num at h ⊢
    exact h
  have ht : c < 2^i := lt_of_lt_of_le hc hp
  rw [BitVec.getLsbD_ofNat]
  simp [Nat.testBit_eq_decide_div_mod_eq, Nat.div_eq_of_lt ht]

theorem packed_bit (k : Nat) (v : BitVec 64) (c : Nat)
    (hk : 7 ≤ k) (hc : c < 128) : (packed k v c).getLsbD k = v.getLsbD k := by
  simp only [packed, BitVec.getLsbD_or, keep_bit, count_bit c k hc hk,
    Nat.le_refl, decide_true, Bool.true_and, Bool.or_false]

theorem packed_clear (k : Nat) (v : BitVec 64) (c : Nat)
    (hk : 7 ≤ k) (hc : c < 128) :
    packed k v c &&& ~~~(1#64 <<< k) = packed (k+1) v c := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [packed, BitVec.getLsbD_or, BitVec.getLsbD_and, BitVec.getLsbD_not,
    keep_bit, BitVec.getLsbD_shiftLeft, BitVec.getLsbD_one]
  by_cases hik : i = k
  · subst i
    rw [count_bit c k hc hk]
    simp [hi]
  · by_cases hlo : i < k
    · simp [hi, hik, show ¬k ≤ i by omega, show ¬k+1 ≤ i by omega, hlo]
    · simp [hi, hik, show k ≤ i by omega, show k+1 ≤ i by omega,
        count_bit c i hc (by omega), show i-k ≠ 0 by omega]

theorem keep_skip (k : Nat) (v : BitVec 64) (h : v.getLsbD k = false) :
    keep k v = keep (k+1) v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  by_cases hik : i = k
  · subst i; simp [keep_bit, h]
  · have he : (k ≤ i) ↔ (k+1 ≤ i) := by omega
    simp [keep_bit, he]

theorem keep_nat (k : Nat) (v : BitVec 64) :
    (keep k v).toNat = v.toNat / 2^k * 2^k := by
  have h := Nat.div_mul_le_self v.toNat (2^k)
  have hv := v.isLt
  simp only [keep, BitVec.toNat_shiftLeft, BitVec.toNat_ushiftRight,
    Nat.shiftRight_eq_div_pow, Nat.shiftLeft_eq,
    Nat.mod_eq_of_lt (show v.toNat / 2^k * 2^k < 2^64 by omega)]

theorem packed_add (k : Nat) (v : BitVec 64) (c : Nat)
    (hk : 7 ≤ k) (hc : c < 128) : packed k v c = keep k v + BitVec.ofNat 64 c := by
  have hp : c < 2^k := by
    have h := Nat.pow_le_pow_right (by decide : 1 ≤ 2) hk
    norm_num at h
    omega
  apply BitVec.eq_of_toNat_eq
  rw [packed, BitVec.toNat_or, BitVec.toNat_add, keep_nat]
  have h64 : c < 2^64 := by omega
  rw [BitVec.toNat_ofNat, Nat.mod_eq_of_lt h64]
  have hor := Nat.two_pow_add_eq_or_of_lt (i := k) (a := v.toNat / 2^k) hp
  rw [Nat.mul_comm] at hor
  have ho := (keep k v ||| BitVec.ofNat 64 c).isLt
  rw [BitVec.toNat_or, keep_nat, BitVec.toNat_ofNat, Nat.mod_eq_of_lt h64, ← hor] at ho
  rw [← hor, Nat.mod_eq_of_lt ho]

theorem packed_increment (k : Nat) (v : BitVec 64) (c : Nat)
    (hk : 7 ≤ k) (hc : c+1 < 128) : packed k v c + 1 = packed k v (c+1) := by
  rw [packed_add k v c hk (by omega), packed_add k v (c+1) hk hc]
  rw [BitVec.ofNat_add]
  simp [BitVec.add_assoc]

theorem step_packed (k : Nat) (v : BitVec 64) (hk : 7 ≤ k ∧ k < 64) :
    stepValue k (packed k v (ones k v)) = packed (k+1) v (ones (k+1) v) := by
  have hc : ones k v + 1 < 128 := by have h := ones_le k v; omega
  rw [stepValue, packed_bit k v (ones k v) hk.1 (by omega), ones_succ]
  cases he : v.getLsbD k
  · simp [he, packed, keep_skip k v he]
  · simp only [he, ↓reduceIte]
    rw [packed_clear k v (ones k v) hk.1 (by omega),
      packed_increment (k+1) v (ones k v) (by omega) hc]


theorem ones_congr (n : Nat) (v w : BitVec 64)
    (h : ∀ i, i < n → v.getLsbD i = w.getLsbD i) : ones n v = ones n w := by
  rw [ones_filter, ones_filter]
  congr 1
  apply List.filter_congr
  intro i hi
  exact h i (List.mem_range.mp hi)

theorem ones_low (v : BitVec 64) :
    ones 7 (BitVec.ofNat 64 (v.toNat%128)) = ones 7 v := by
  apply ones_congr
  intro i hi
  change ((v.toNat%2^7)%2^64).testBit i = v.toNat.testBit i
  simp only [Nat.testBit_mod_two_pow, show i < 64 by omega, hi,
    decide_true, Bool.true_and]

def lowLeaf (d : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  [.core (.alu .and .w64 d (.imm 18446744073709551488)),
   .core (.alu .or .w64 d (.imm (BitVec.ofNat 64 (ones 7 (BitVec.ofNat 64 n)))))]

def lowEffect (d : BPF.Reg) (n : Nat) (s : BPF.State) : BPF.State :=
  set d (packed 7 (s.regs d) (ones 7 (BitVec.ofNat 64 n))) s

theorem keep_seven (v : BitVec 64) :
    v &&& (18446744073709551488#64) = keep 7 v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_and, keep_bit]
  interval_cases i <;> simp

theorem low_exec (d : BPF.Reg) (n : Nat) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (lowLeaf d n ++ tail) s = BPF.mexec tail (lowEffect d n s) := by
  simp [lowLeaf, lowEffect, set, packed, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
    BPF.AluOp.eval, BPF.RegFile.set_set_same, BPF.RegFile.set_same, keep_seven]

def initial (d : BPF.Reg) : List BPF.MInsn := ModuleControlDispatch.tree d (lowLeaf d) 7 0

theorem initial_exec (d : BPF.Reg) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (initial d ++ tail) s =
      BPF.mexec tail (set d (packed 7 (s.regs d) (ones 7 (s.regs d))) s) := by
  rw [initial, ModuleControlDispatch.exec_tree d (lowLeaf d) (lowEffect d)
    (low_exec d) 7 0, ModuleDispatch.selected_eq _ _ _ (by decide : 7 ≤ 64)]
  simp [lowEffect, ones_low]

def loop (d : BPF.Reg) : Nat → List BPF.MInsn
  | 0 => []
  | n+1 => loop d n ++ iteration d (7+n)

theorem loop_exec (d : BPF.Reg) (n : Nat) (hn : n ≤ 57) (v : BitVec 64)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (loop d n ++ tail) (set d (packed 7 v (ones 7 v)) s) =
      BPF.mexec tail (set d (packed (7+n) v (ones (7+n) v)) s) := by
  induction n generalizing tail with
  | zero => simp [loop, BPF.mexec]
  | succ n ih =>
    rw [loop, List.append_assoc, ih (by omega), iteration_exec d (7+n) (by omega)]
    simp only [set, BPF.RegFile.set_same, step_packed (7+n) v (by omega),
      BPF.RegFile.set_set_same]
    rfl

theorem packed_last (v : BitVec 64) :
    packed 64 v (ones 64 v) = BitVec.ofNat 64 (ones 64 v) := by
  simp [packed, keep, BitVec.ushiftRight_eq_zero]

def bpf (d src : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .mov .w64 d (.reg src))] ++ initial d ++ loop d 57

def native (m : X86RegMap) (d src : BPF.Reg) : List X86.MInsn :=
  [.popcnt (m.map d) (m.map src)]

def spec (d src : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (BitVec.ofNat 64 (ones 64 (s.regs src))) }

theorem bpf_correct (d src : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf d src) s) = spec d src (observeBpf s) := by
  rw [bpf, ← List.append_nil (loop d 57), List.append_assoc]
  simp only [List.cons_append, List.nil_append, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval]
  rw [initial_exec]
  simp only [Machine.State.set, BPF.RegFile.set_same]
  rw [loop_exec d 57 (by decide)]
  simp [packed_last, spec, set, observeBpf, BPF.mexec, BPF.RegFile.set_set_same]

theorem native_correct (m : X86RegMap) (d src : BPF.Reg) (s : X86.State) :
    observeX86 m (X86.mexec (native m d src) s) = spec d src (observeX86 m s) := by
  simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  rw [x86_observe_set]
  simp [spec, ones_filter, observeX86]

theorem iteration_writes (d r : BPF.Reg) (k : Nat)
    (h : r ∈ BPF.mwrites (iteration d k)) : r = d := by
  simp only [iteration, BPF.mwrites, List.flatMap_append, List.mem_append] at h
  rcases h with h | h
  · exact ModuleRotateOne.repeated_writes true d r (64-k) h
  · apply ModuleControlDispatch.writes_tree d (stepLeaf d k) 1 0 d _ r h
    intro n r hr
    by_cases hn : n = 0
    · simp only [stepLeaf, if_pos hn] at hr
      exact ModuleRotateOne.repeated_writes true d r k hr
    · simp only [stepLeaf, if_neg hn, BPF.mwrites, List.flatMap_append,
        List.flatMap_cons, List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg,
        List.mem_append, List.mem_cons, List.mem_nil_iff, or_false] at hr
      rcases hr with (hr | hr) | hr
      · exact hr
      · exact ModuleRotateOne.repeated_writes true d r k hr
      · exact hr

theorem loop_writes (d r : BPF.Reg) (n : Nat)
    (h : r ∈ BPF.mwrites (loop d n)) : r = d := by
  induction n with
  | zero => simp [loop, BPF.mwrites] at h
  | succ n ih =>
    simp only [loop, BPF.mwrites, List.flatMap_append, List.mem_append] at h
    exact h.elim ih (iteration_writes d r (7+n))

def bpf_x86_popcntq (m : X86RegMap) (d src : BPF.Reg) : X86StateEquiv m where
  spec := spec d src
  bpf := bpf d src
  native := native m d src
  writeSet := [d]
  bpfCorrect := bpf_correct d src
  nativeCorrect := native_correct m d src
  bpfWrites := by
    intro r h
    simp only [bpf, BPF.mwrites, List.flatMap_append, List.mem_append] at h
    rcases h with (h | h) | h
    · simpa [BPF.MInsn.writes, BPF.Insn.dstReg] using h
    · have he := ModuleControlDispatch.writes_tree d (lowLeaf d) 7 0 d
        (by intro n r hr; simpa [lowLeaf, BPF.mwrites, BPF.MInsn.writes,
          BPF.Insn.dstReg] using hr) r h
      simp [he]
    · simp [loop_writes d r 57 h]
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModulePopcnt
