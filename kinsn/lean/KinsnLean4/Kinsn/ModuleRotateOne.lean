import KinsnLean4.Kinsn.ModuleDispatch

namespace Kinsn.ModuleRotateOne

def bits (is64 : Bool) : Nat := if is64 then 64 else 32
def width (is64 : Bool) : BPF.Width := if is64 then .w64 else .w32

def carry (is64 : Bool) (v : BitVec 64) : Bool :=
  BPF.Cond.test .signedLt (width is64) v 0

theorem negative (v : BitVec w) : decide (v.toInt < 0) = v.msb := by
  cases h : v.msb
  · simp [not_lt.mpr (BitVec.toInt_nonneg_of_msb_false h), h]
  · simp [BitVec.toInt_neg_of_msb_true h, h]

theorem carry_eq (is64 : Bool) (v : BitVec 64) :
    carry is64 v = (BitVec.setWidth (bits is64) v).msb := by
  cases is64
  · change decide ((BitVec.setWidth 32 v).toInt < 0) = (BitVec.setWidth 32 v).msb
    exact negative _
  · change decide (v.toInt < 0) = v.msb
    exact negative _

def oneValue (is64 : Bool) (v : BitVec 64) : BitVec 64 :=
  let x := BitVec.setWidth (bits is64) v
  BitVec.setWidth 64 ((x <<< 1) ||| (if x.msb then 1 else 0))

/-- x86/bpf_x86_rotate.c:instantiate_rotate_leaf's five-instruction
    one-bit rotate: JS(L)T tests carry before a shift, then reinserts it. -/
def one (is64 : Bool) (d : BPF.Reg) : List BPF.MInsn :=
  [.branch .signedLt (width is64) d (.imm 0) 2,
   .core (.alu .lsh (width is64) d (BPF.immN 1)), .ja 2,
   .core (.alu .lsh (width is64) d (BPF.immN 1)),
   .core (.alu .or (width is64) d (BPF.immN 1))]

theorem one_word (w : Nat) (hw : w = 32 ∨ w = 64) (v : BitVec w) :
    (v <<< 1) ||| (if v.msb then 1 else 0) = v.rotateLeft 1 := by
  rcases hw with hw | hw <;> subst w
  all_goals by_cases hm : v.msb = true
  all_goals apply BitVec.eq_of_getLsbD_eq; intro i hi
  all_goals simp only [BitVec.rotateLeft_def, hm,
    BitVec.getLsbD_or, BitVec.getLsbD_shiftLeft, BitVec.getLsbD_ushiftRight]
  all_goals interval_cases i <;> simp_all [BitVec.msb_eq_getLsbD_last]


set_option maxHeartbeats 0 in
theorem rotate_succ (w : Nat) (hw : w = 32 ∨ w = 64) (v : BitVec w)
    (n : Nat) (hn : n+1 < w) :
    (v.rotateLeft 1).rotateLeft n = v.rotateLeft (n+1) := by
  rcases hw with hw | hw <;> subst w
  all_goals have h : n < 63 := by omega
  all_goals interval_cases n
  all_goals apply BitVec.eq_of_getLsbD_eq; intro i hi
  all_goals interval_cases i <;> simp

theorem one_rotate (is64 : Bool) (v : BitVec 64) :
    oneValue is64 v = BitVec.setWidth 64 ((BitVec.setWidth (bits is64) v).rotateLeft 1) := by
  exact congrArg (BitVec.setWidth 64) (one_word (bits is64)
    (by cases is64 <;> simp [bits]) (BitVec.setWidth (bits is64) v))

theorem one_exec (is64 : Bool) (d : BPF.Reg) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (one is64 d ++ tail) s =
      BPF.mexec tail { s with regs := (BPF.RegFile.set s.regs d (oneValue is64 (s.regs d))) } := by
  simp only [one, List.cons_append, List.nil_append, BPF.mexec, BPF.Src.eval]
  rw [show BPF.Cond.test .signedLt (width is64) (s.regs d) 0 =
      (BitVec.setWidth (bits is64) (s.regs d)).msb from carry_eq is64 (s.regs d)]
  split <;> cases is64 <;>
    simp_all [oneValue, bits, width, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
      BPF.AluOp.eval, BPF.immN, BPF.RegFile.set_set_same,
      BitVec.setWidth_setWidth_of_le]

theorem set_self (rf : BPF.RegFile) (d : BPF.Reg) : BPF.RegFile.set rf d (rf d) = rf := by
  funext r; by_cases h : r = d <;> simp [BPF.RegFile.set, h]

def repeated (is64 : Bool) (d : BPF.Reg) : Nat → List BPF.MInsn
  | 0 => [] | n+1 => one is64 d ++ repeated is64 d n

def iterateValue (is64 : Bool) (v : BitVec 64) : Nat → BitVec 64
  | 0 => v | n+1 => iterateValue is64 (oneValue is64 v) n


theorem roundtrip (is64 : Bool) (v : BitVec (bits is64)) :
    BitVec.setWidth (bits is64) (BitVec.setWidth 64 v) = v := by
  cases is64 <;> simp [bits, BitVec.setWidth_setWidth_of_le]

theorem iterate_rotate (is64 : Bool) (v : BitVec (bits is64)) (n : Nat)
    (hn : n < bits is64) :
    iterateValue is64 (BitVec.setWidth 64 v) n = BitVec.setWidth 64 (v.rotateLeft n) := by
  induction n generalizing v with
  | zero =>
    have hz : v.rotateLeft 0 = v := by
      rw [BitVec.rotateLeft_def]
      simp only [Nat.zero_mod, BitVec.shiftLeft_zero, Nat.sub_zero,
        BitVec.ushiftRight_eq_zero (Nat.le_refl _), BitVec.or_zero]
    simp only [iterateValue, hz]
  | succ n ih =>
    simp only [iterateValue, one_rotate, roundtrip]
    rw [ih _ (by omega), rotate_succ (bits is64) (by cases is64 <;> simp [bits]) v n hn]

theorem repeated_exec (is64 : Bool) (d : BPF.Reg) (n : Nat) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (repeated is64 d n ++ tail) s =
      BPF.mexec tail { s with regs := (BPF.RegFile.set s.regs d (iterateValue is64 (s.regs d) n)) } := by
  induction n generalizing s with
  | zero => simp [repeated, iterateValue, set_self]
  | succ n ih =>
    simp only [repeated, List.append_assoc]
    rw [one_exec, ih]
    simp [iterateValue, BPF.RegFile.set_set_same]

theorem repeated_writes (is64 : Bool) (d t : BPF.Reg) (n : Nat) :
    t ∈ BPF.mwrites (repeated is64 d n) → t = d := by
  induction n with
  | zero => simp [repeated, BPF.mwrites]
  | succ n ih =>
    simp only [repeated, BPF.mwrites, List.flatMap_append, List.mem_append]
    intro ht
    rcases ht with ht | ht
    · simpa [one, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
    · exact ih ht

end Kinsn.ModuleRotateOne
