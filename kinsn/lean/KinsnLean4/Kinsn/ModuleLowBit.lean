import KinsnLean4.Kinsn.ModuleDispatch

namespace Kinsn.ModuleLowBit

def value (isolate : Bool) (v : BitVec 64) : BitVec 64 :=
  v &&& (if isolate then -v else ~~~(-v))

theorem value_bit (isolate : Bool) (v : BitVec 64) (i : Nat) (hi : i < 64) :
    (value isolate v).getLsbD i = (v.getLsbD i &&
      (if isolate then !decide (∃ j < i, v.getLsbD j = true)
       else decide (∃ j < i, v.getLsbD j = true))) := by
  cases isolate <;> simp only [value, Bool.false_eq_true, ↓reduceIte,
    BitVec.getLsbD_and, BitVec.getLsbD_not, BitVec.getLsbD_neg,
    decide_eq_true hi, Bool.true_and]
  all_goals cases v.getLsbD i <;> simp

theorem odd_value (isolate : Bool) (v : BitVec 64) (h : v.getLsbD 0 = true) :
    value isolate v = if isolate then 1 else v - 1 := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [value_bit isolate v i hi]
  cases isolate
  · change (v.getLsbD i && decide (∃ j < i, v.getLsbD j = true)) =
        (v - 1#64).getLsbD i
    rw [← BitVec.not_neg]
    simp only [BitVec.getLsbD_not, BitVec.getLsbD_neg,
      decide_eq_true hi, Bool.true_and]
    by_cases hz : i = 0
    · subst i; simp [h]
    · have he : ∃ j < i, v.getLsbD j = true := ⟨0, by omega, h⟩
      simp [he]
  · by_cases hz : i = 0
    · subst i; simp [h]
    · have he : ∃ j < i, v.getLsbD j = true := ⟨0, by omega, h⟩
      simp [he, hz, BitVec.getLsbD_one]

theorem even_value (isolate : Bool) (v : BitVec 64) (h : v.getLsbD 0 = false) :
    value isolate v = value isolate (v >>> 1) <<< 1 := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  by_cases hz : i = 0
  · subst i; rw [value_bit isolate v 0 (by decide), h]; simp
  · have hp : i - 1 < 64 := by omega
    have hindex : 1 + (i - 1) = i := by omega
    have he : (∃ j < i, v.getLsbD j = true) ↔
        (∃ j < i - 1, (v >>> 1).getLsbD j = true) := by
      constructor
      · rintro ⟨j, hj, hb⟩
        have hjz : 0 < j := by
          by_contra hn
          have hj0 : j = 0 := by omega
          rw [hj0, h] at hb
          contradiction
        refine ⟨j - 1, by omega, ?_⟩
        simpa [BitVec.getLsbD_ushiftRight, show 1 + (j - 1) = j by omega] using hb
      · rintro ⟨j, hj, hb⟩
        exact ⟨j + 1, by omega, by simpa [BitVec.getLsbD_ushiftRight, Nat.add_comm] using hb⟩
    rw [BitVec.getLsbD_shiftLeft, value_bit isolate v i hi,
      value_bit isolate (v >>> 1) (i - 1) hp]
    simp only [decide_eq_true hi, decide_eq_false (show ¬i < 1 by omega), Bool.not_false, Bool.true_and]
    have hx : (v >>> 1).getLsbD (i - 1) = v.getLsbD i := by
      simp only [BitVec.getLsbD_ushiftRight, hindex]
    rw [hx]
    have hd : decide (∃ j < i, v.getLsbD j = true) =
        decide (∃ j < i - 1, (v >>> 1).getLsbD j = true) := by
      simp only [he]
    simp only [← hd]

theorem zero_value (isolate : Bool) : value isolate 0 = 0 := by simp [value]

def bounded (v : BitVec 64) (n : Nat) : Prop := ∀ i, n ≤ i → v.getLsbD i = false

theorem bounded_shift (v : BitVec 64) (n : Nat) (h : bounded v (n + 1)) :
    bounded (v >>> 1) n := by
  intro i hi
  simpa [BitVec.getLsbD_ushiftRight] using h (1 + i) (by omega)

theorem bounded_zero (v : BitVec 64) (h : bounded v 0) : v = 0 := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simpa using h i (by omega)

/-- x86/bpf_x86_bmi1.c:instantiate_bls_scan, first-set-bit branch. -/
def found (isolate : Bool) (d : BPF.Reg) (k : Nat) : List BPF.MInsn :=
  [.core (if isolate then .alu .mov .w64 d (.imm 1)
    else .alu .add .w64 d (.imm (-1)))] ++
  (if k = 0 then [] else [.core (.alu .lsh .w64 d (BPF.immN k))])

theorem found_exec (isolate : Bool) (d : BPF.Reg) (k : Nat) (hk : k < 64)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (found isolate d k ++ tail) s = BPF.mexec tail
      { s with regs := (BPF.RegFile.set s.regs d
        ((if isolate then 1 else s.regs d - 1) <<< k)) } := by
  have hm : k % 64 = k := Nat.mod_eq_of_lt hk
  have he : (BitVec.ofNat 64 k).toNat = k := by
    simp only [BitVec.toNat_ofNat]
    apply Nat.mod_eq_of_lt
    omega
  have hm1 (v : BitVec 64) : v + 18446744073709551615#64 = v - 1 := by
    change v + -1#64 = v - 1#64
    exact BitVec.add_neg_eq_sub
  cases isolate <;> by_cases hz : k = 0 <;>
    simp [found, hz, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      BPF.immN, he, hm, hm1, BPF.RegFile.set_set_same]

/-- x86/bpf_x86_bmi1.c:instantiate_bls_scan. Each failed low-bit test
    shifts once before the recursive scan; the successful leaf shifts back. -/
def scan (isolate : Bool) (d : BPF.Reg) : Nat → Nat → List BPF.MInsn
  | 0, _ => [.core (.alu .mov .w64 d (.imm 0))]
  | n + 1, k =>
    let low := scan isolate d n (k + 1)
    let high := found isolate d k
    [.branch .bitSet .w64 d (.imm 1) (low.length + 2),
      .core (.alu .rsh .w64 d (BPF.immN 1))] ++
      low ++ [.ja high.length] ++ high

theorem scan_exec (isolate : Bool) (d : BPF.Reg) (n k : Nat)
    (hk : n + k ≤ 64) (s : BPF.State) (hb : bounded (s.regs d) n)
    (tail : List BPF.MInsn) :
    BPF.mexec (scan isolate d n k ++ tail) s = BPF.mexec tail
      { s with regs := (BPF.RegFile.set s.regs d (value isolate (s.regs d) <<< k)) } := by
  induction n generalizing k s tail with
  | zero =>
    have hz := bounded_zero (s.regs d) hb
    have hv : value isolate 0#64 = 0#64 := zero_value isolate
    simp [scan, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, hz, hv]
  | succ n ih =>
    simp only [scan, List.append_assoc, List.cons_append, List.nil_append]
    rw [BPF.mexec]
    change (if ModuleDispatch.bitTest (s.regs d) 0 then _ else _) = _
    split
    · simp only [List.drop_succ_cons, List.drop_append,
        List.drop_eq_nil_of_le (by omega :
          (scan isolate d n (k + 1)).length ≤ (scan isolate d n (k + 1)).length + 1),
        Nat.add_sub_cancel_left, List.drop_succ_cons, List.drop_zero, List.nil_append]
      rw [found_exec isolate d k (by omega)]
      have hodd : (s.regs d).getLsbD 0 = true := by
        simpa [ModuleDispatch.bitTest_eq _ 0 (by decide)] using
          ‹ModuleDispatch.bitTest (s.regs d) 0 = true›
      rw [odd_value isolate (s.regs d) hodd]
      simp
    · have heven : (s.regs d).getLsbD 0 = false := by
        simpa [ModuleDispatch.bitTest_eq _ 0 (by decide)] using
          ‹¬ModuleDispatch.bitTest (s.regs d) 0 = true›
      rw [BPF.mexec]
      have hs : (BPF.MInsn.core (.alu .rsh .w64 d (BPF.immN 1))).step s =
          { s with regs := (BPF.RegFile.set s.regs d (s.regs d >>> 1)) } := by
        rfl
      rw [hs, ih (k + 1) (by omega) _ (by
        simpa using bounded_shift (s.regs d) n hb)]
      simp only [BPF.mexec, List.drop_append, List.drop_eq_nil_of_le (Nat.le_refl _), Nat.sub_self,
        List.drop_zero, List.nil_append]
      rw [even_value isolate (s.regs d) heven]
      simp [BPF.RegFile.set_set_same, ← BitVec.shiftLeft_add, Nat.add_comm]

theorem found_writes (isolate : Bool) (d t : BPF.Reg) (k : Nat) :
    t ∈ BPF.mwrites (found isolate d k) → t = d := by
  cases isolate <;> by_cases hz : k = 0 <;>
    simp [found, hz, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]

theorem scan_writes (isolate : Bool) (d t : BPF.Reg) (n k : Nat) :
    t ∈ BPF.mwrites (scan isolate d n k) → t = d := by
  induction n generalizing k with
  | zero => simp [scan, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  | succ n ih =>
    intro ht
    simp only [scan, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg, List.nil_append,
      List.mem_append, List.mem_cons, List.mem_nil_iff, or_false] at ht
    rcases ht with ht | ht
    · exact ht.elim id (ih (k + 1))
    · exact found_writes isolate d t k ht

/-- x86/bpf_x86_bmi1.c:instantiate_bls/instantiate_blsiq/instantiate_blsrq. -/
def bpf (isolate : Bool) (d r : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .mov .w64 d (.reg r))] ++ scan isolate d 64 0

/-- x86/bpf_x86_bmi1.c:emit_bmi1_x86/emit_blsiq_x86/emit_blsrq_x86;
    unchanged single native BMI1 instruction. -/
def native (m : X86RegMap) (isolate : Bool) (d r : BPF.Reg) : List X86.MInsn :=
  [if isolate then .blsi (m.map d) (m.map r) else .blsr (m.map d) (m.map r)]

def spec (isolate : Bool) (d r : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (value isolate (s.regs r)) }

theorem bpf_correct (isolate : Bool) (d r : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf isolate d r) s) = spec isolate d r (observeBpf s) := by
  simp only [bpf, List.cons_append, List.nil_append, BPF.mexec]
  have hb : bounded
      (((BPF.MInsn.core (.alu .mov .w64 d (.reg r))).step s).regs d) 64 := by
    intro i hi
    exact BitVec.getLsbD_of_ge _ i hi
  have he := scan_exec isolate d 64 0 (by omega)
    ((BPF.MInsn.core (.alu .mov .w64 d (.reg r))).step s) hb []
  simp only [List.append_nil, BPF.mexec] at he
  rw [he]
  simp [spec, observeBpf, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
    BPF.RegFile.set_set_same]

theorem native_correct (m : X86RegMap) (isolate : Bool) (d r : BPF.Reg) (s : X86.State) :
    observeX86 m (X86.mexec (native m isolate d r) s) =
      spec isolate d r (observeX86 m s) := by
  cases isolate <;> simp only [native, Bool.false_eq_true, ↓reduceIte,
    X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  all_goals rw [x86_observe_set]
  · simp [spec, value, BitVec.not_neg, observeX86]
  · rfl

def cert (m : X86RegMap) (isolate : Bool) (d r : BPF.Reg) : X86StateEquiv m where
  spec := spec isolate d r
  bpf := bpf isolate d r
  native := native m isolate d r
  writeSet := [d]
  bpfCorrect := bpf_correct isolate d r
  nativeCorrect := native_correct m isolate d r
  bpfWrites := by
    intro t ht
    simp only [bpf, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg, List.mem_append,
      List.mem_cons, List.mem_nil_iff, or_false] at ht
    exact List.mem_singleton.mpr (ht.elim id (scan_writes isolate d t 64 0))
  nativeWrites := by
    cases isolate <;> simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_bmi1.c:instantiate_blsiq/emit_blsiq_x86. -/
def bpf_x86_blsiq (m : X86RegMap) (d r : BPF.Reg) : X86StateEquiv m := cert m true d r
/-- x86/bpf_x86_bmi1.c:instantiate_blsrq/emit_blsrq_x86. -/
def bpf_x86_blsrq (m : X86RegMap) (d r : BPF.Reg) : X86StateEquiv m := cert m false d r

end Kinsn.ModuleLowBit
