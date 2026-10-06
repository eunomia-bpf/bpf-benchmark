import KinsnLean4.Kinsn.ModuleBmiShift

namespace Kinsn.ModuleBzhi
open ModuleBmiShift (bits width)

def depth (is64 : Bool) : Nat := if is64 then 6 else 5
def highMask (is64 : Bool) : BitVec 64 := if is64 then 192#64 else 224#64
def count (v : BitVec 64) : Nat := (BitVec.setWidth 8 v).toNat

def value (is64 : Bool) (v : BitVec 64) (n : Nat) : BitVec 64 :=
  BitVec.setWidth 64 (BitVec.setWidth (bits is64) v &&& Bits.lowMask (bits is64) n)

/-- x86/bpf_x86_bmi2_shift.c:instantiate_bzhi_dispatch: count zero clears dst;
    a positive low count uses MOV64 then width-correct LSH/RSH. -/
def leaf (is64 : Bool) (d r : BPF.Reg) (n : Nat) : List BPF.Insn :=
  if n = 0 then [.alu .mov (width is64) d (.imm 0)] else
    [.alu .mov .w64 d (.reg r), .alu .lsh (width is64) d (BPF.immN (bits is64 - n)),
      .alu .rsh (width is64) d (BPF.immN (bits is64 - n))]

/-- x86/bpf_x86_bmi2_shift.c:instantiate_bzhi: JSET the high bits of count[7:0],
    then dispatch only the remaining five/six bits. No temporary register or spill. -/
def bpf (is64 : Bool) (d r c : BPF.Reg) : List BPF.MInsn :=
  let low := ModuleDispatch.tree c (leaf is64 d r) (depth is64) 0
  [.branch .bitSet .w64 c (.imm (highMask is64)) (low.length + 1)] ++
    low ++ [.ja 1, .core (.alu .mov (width is64) d (.reg r))]

/-- x86/bpf_x86_bmi2_shift.c:emit_bzhi_x86/emit_bzhi_rrr: BZHI reads count[7:0]
    before its destination write; indices at least width leave the source unchanged. -/
def native (is64 : Bool) (d r c : X86.GPReg) : List X86.MInsn :=
  [.bzhi (bits is64) d r c]

def spec (is64 : Bool) (d r c : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (value is64 (s.regs r) (count (s.regs c))) }

theorem keep_low (w : Nat) (v : BitVec w) (n : Nat) (hw : n < w) :
    (v <<< (w - n)) >>> (w - n) = v &&& Bits.lowMask w n := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_ushiftRight, BitVec.getLsbD_shiftLeft,
    BitVec.getLsbD_and, Bits.getLsbD_lowMask, decide_eq_true hi, Bool.true_and]
  by_cases h : i < n
  · simp [show w - n + i < w by omega,
      show w - n + i - (w - n) = i by omega, h]
  · simp [show ¬w - n + i < w by omega, h]

theorem leaf_exec (is64 : Bool) (d r : BPF.Reg) (n : Nat) (hn : n < bits is64)
    (rf : BPF.RegFile) :
    BPF.exec (leaf is64 d r n) rf = rf.set d (value is64 (rf r) n) := by
  by_cases hz : n = 0
  · subst n; cases is64 <;>
      simp [leaf, width, bits, value, BPF.exec, BPF.Insn.step, BPF.AluOp.eval]
  · have hm : (bits is64 - n) % bits is64 = bits is64 - n :=
      Nat.mod_eq_of_lt (by omega)
    have hk := keep_low (bits is64) (BitVec.setWidth (bits is64) (rf r)) n
      hn
    cases is64 <;>
      simp only [bits, Bool.false_eq_true, ↓reduceIte] at hm hk
    all_goals
      simp [leaf, hz, value, width, bits, BPF.exec, BPF.Insn.step, BPF.AluOp.eval,
        BPF.immN, hm,
        BPF.RegFile.set_set_same]
    all_goals
      exact congrArg (BPF.RegFile.set rf d) (by simpa using congrArg (BitVec.setWidth 64) hk)

theorem high_mask (is64 : Bool) (v : BitVec 64) :
    v &&& highMask is64 =
      (BitVec.setWidth 64 (BitVec.setWidth 8 v) >>> depth is64) <<< depth is64 := by
  cases is64 <;> apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi; interval_cases i <;> simp [highMask, depth]

def highTest (is64 : Bool) (v : BitVec 64) : Bool :=
  BPF.Cond.test .bitSet .w64 v (highMask is64)

theorem highTest_eq (is64 : Bool) (v : BitVec 64) :
    highTest is64 v = decide (bits is64 ≤ count v) := by
  have hn : count v < 256 := (BitVec.setWidth 8 v).isLt
  have he : (v &&& highMask is64).toNat = count v / bits is64 * bits is64 := by
    rw [high_mask]
    cases is64 <;>
      simp only [depth, bits, Bool.false_eq_true, ↓reduceIte, BitVec.toNat_shiftLeft,
        BitVec.toNat_ushiftRight, BitVec.toNat_setWidth, Nat.shiftRight_eq_div_pow,
        Nat.shiftLeft_eq, count] at *
    all_goals omega
  have hz : v &&& highMask is64 = 0#64 ↔ count v < bits is64 := by
    rw [← BitVec.toNat_inj, he]
    cases is64 <;> simp [bits]
  by_cases h : bits is64 ≤ count v
  · have hn : ¬ count v < bits is64 := by omega
    simp [highTest, BPF.Cond.test, BPF.Cond.eval, hz, h, hn]
  · have hn : count v < bits is64 := by omega
    simp [highTest, BPF.Cond.test, BPF.Cond.eval, hz, h, hn]

theorem value_ge (is64 : Bool) (v : BitVec 64) (n : Nat) (hn : bits is64 ≤ n) :
    value is64 v n = BitVec.setWidth 64 (BitVec.setWidth (bits is64) v) := by
  simp [value, Bits.lowMask_of_le _ _ hn]

theorem count_low (is64 : Bool) (v : BitVec 64) (hn : count v < bits is64) :
    v.toNat % bits is64 = count v := by
  have he : count v % bits is64 = v.toNat % bits is64 := by
    cases is64 <;> simp [count, bits, BitVec.toNat_setWidth, Nat.mod_mod_of_dvd]
  rw [Nat.mod_eq_of_lt hn] at he
  exact he.symm

theorem bpf_correct (is64 : Bool) (d r c : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf is64 d r c) s) = spec is64 d r c (observeBpf s) := by
  simp only [bpf, List.cons_append, List.nil_append]
  rw [BPF.mexec]
  change observeBpf (if highTest is64 (s.regs c) then _ else _) = _
  by_cases h : bits is64 ≤ count (s.regs c)
  · have ht : highTest is64 (s.regs c) = true := by simp [highTest_eq, h]
    simp only [ht, ↓reduceIte, List.drop_append,
      List.drop_eq_nil_of_le (by omega :
        (ModuleDispatch.tree c (leaf is64 d r) (depth is64) 0).length ≤
          (ModuleDispatch.tree c (leaf is64 d r) (depth is64) 0).length + 1),
      Nat.add_sub_cancel_left, List.drop_succ_cons, List.drop_zero, List.nil_append]
    cases is64 <;>
      simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
        width, bits, spec, observeBpf, value_ge _ _ _ h]
  · have hn : count (s.regs c) < bits is64 := by omega
    have ht : highTest is64 (s.regs c) = false := by simp [highTest_eq, h]
    simp only [ht]
    rw [ModuleDispatch.exec_tree, ModuleDispatch.selected_eq _ _ _
      (by cases is64 <;> decide)]
    have hb : 2 ^ depth is64 = bits is64 := by cases is64 <;> rfl
    rw [hb, Nat.zero_add, count_low _ _ hn, leaf_exec _ _ _ _ hn]
    simp [BPF.mexec, observeBpf, spec]

def cert (m : X86RegMap) (is64 : Bool) (d r c : BPF.Reg) : X86StateEquiv m where
  spec := spec is64 d r c
  bpf := bpf is64 d r c
  native := native is64 (m.map d) (m.map r) (m.map c)
  writeSet := [d]
  bpfCorrect := bpf_correct is64 d r c
  nativeCorrect := by
    intro s
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, x86_observe_set]
    rfl
  bpfWrites := by
    intro t ht
    simp only [bpf, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg, List.nil_append,
      List.mem_append, List.mem_cons, List.mem_nil_iff, or_false] at ht
    rcases ht with ht | ht
    · exact List.mem_singleton.mpr (ModuleDispatch.writes_tree _ _ _ _ d
        (by intro n; by_cases hz : n = 0 <;>
          simp [leaf, hz, BPF.writes, BPF.Insn.dstReg]) t ht)
    · exact List.mem_singleton.mpr ht
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_bmi2_shift.c:instantiate_bzhil/emit_bzhil_x86. -/
def bpf_x86_bzhil (m : X86RegMap) (d r c : BPF.Reg) : X86StateEquiv m := cert m false d r c
/-- x86/bpf_x86_bmi2_shift.c:instantiate_bzhiq/emit_bzhiq_x86. -/
def bpf_x86_bzhiq (m : X86RegMap) (d r c : BPF.Reg) : X86StateEquiv m := cert m true d r c

end Kinsn.ModuleBzhi
