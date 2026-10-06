import KinsnLean4.Kinsn.ModuleDispatch

namespace Kinsn.ModuleBmiShift

def width (is64 : Bool) : BPF.Width := if is64 then .w64 else .w32
def bits (is64 : Bool) : Nat := if is64 then 64 else 32
def op (left : Bool) : BPF.AluOp := if left then .lsh else .rsh

def value (is64 left : Bool) (v c : BitVec 64) : BitVec 64 :=
  let n := c.toNat % bits is64
  let v := BitVec.setWidth (bits is64) v
  BitVec.setWidth 64 (if left then v <<< n else v >>> n)

/-- x86/bpf_x86_bmi2_shift.c:instantiate_shift_dispatch leaf: read the source
    only after testing the original count, then use the selected immediate. -/
def leaf (is64 left : Bool) (d r : BPF.Reg) (n : Nat) : List BPF.Insn :=
  [.alu .mov .w64 d (.reg r), .alu (op left) (width is64) d (BPF.immN n)]

/-- x86/bpf_x86_bmi2_shift.c:instantiate_bmi2_shift: destination/count aliases
    dispatch on the low five/six bits; other forms copy then shift directly. -/
def bpf (is64 left : Bool) (d r c : BPF.Reg) : List BPF.MInsn :=
  if d = c ∧ d ≠ r then
    ModuleDispatch.tree c (leaf is64 left d r) (if is64 then 6 else 5) 0
  else [.core (.alu .mov .w64 d (.reg r)),
    .core (.alu (op left) (width is64) d (.reg c))]

/-- x86/bpf_x86_bmi2_shift.c:emit_bmi2_shift_x86/emit_bmi2_shift_rrr:
    SHLX/SHRX read all three operands before the destination write. -/
def native (is64 left : Bool) (d r c : X86.GPReg) : List X86.MInsn :=
  [.shift (bits is64) left d r c]

def spec (is64 left : Bool) (d r c : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (value is64 left (s.regs r) (s.regs c)) }

theorem leaf_exec (is64 left : Bool) (d r : BPF.Reg) (n : Nat)
    (rf : BPF.RegFile) :
    BPF.exec (leaf is64 left d r n) rf =
      rf.set d (value is64 left (rf r) (BitVec.ofNat 64 n)) := by
  cases is64 <;> cases left <;>
    simp [leaf, op, width, value, bits, BPF.exec, BPF.Insn.step, BPF.AluOp.eval,
      BPF.immN, BPF.RegFile.set_set_same]

theorem bpf_correct (is64 left : Bool) (d r c : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf is64 left d r c) s) =
      spec is64 left d r c (observeBpf s) := by
  by_cases h : d = c ∧ d ≠ r
  · rw [bpf, if_pos h]
    have he := ModuleDispatch.exec_tree c (leaf is64 left d r)
      (if is64 then 6 else 5) 0 s []
    simp only [List.append_nil, BPF.mexec] at he
    rw [he, ModuleDispatch.selected_eq _ _ _ (by cases is64 <;> decide)]
    simp only [Nat.zero_add]
    have hb : 2 ^ (if is64 then 6 else 5) = bits is64 := by cases is64 <;> rfl
    rw [hb, leaf_exec]
    simp only [observeBpf, spec]
    congr 1
    congr 1
    cases is64 <;> cases left <;>
      simp [value, bits, BitVec.toNat_ofNat, Nat.mod_mod_of_dvd]
  · have hc : (BPF.RegFile.set s.regs d (s.regs r)) c = s.regs c := by
      by_cases hd : c = d
      · subst c
        have hr : d = r := by by_contra hr; exact h ⟨rfl, hr⟩
        subst r; simp
      · simp [BPF.RegFile.set, hd]
    rw [bpf, if_neg h]
    cases is64 <;> cases left <;>
      simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
        op, width, observeBpf, spec, value, bits, hc,
        BPF.RegFile.set_set_same]

def cert (m : X86RegMap) (is64 left : Bool) (d r c : BPF.Reg) : X86StateEquiv m where
  spec := spec is64 left d r c
  bpf := bpf is64 left d r c
  native := native is64 left (m.map d) (m.map r) (m.map c)
  writeSet := [d]
  bpfCorrect := bpf_correct is64 left d r c
  nativeCorrect := by
    intro s
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, x86_observe_set]
    rfl
  bpfWrites := by
    intro t ht
    by_cases h : d = c ∧ d ≠ r
    · rw [bpf, if_pos h] at ht
      exact List.mem_singleton.mpr (ModuleDispatch.writes_tree _ _ _ _ d
        (by simp [leaf, BPF.writes, BPF.Insn.dstReg]) t ht)
    · simpa [bpf, h, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_bmi2_shift.c:instantiate_shlxl/emit_shlxl_x86. -/
def bpf_x86_shlxl (m : X86RegMap) (d r c : BPF.Reg) : X86StateEquiv m := cert m false true d r c
/-- x86/bpf_x86_bmi2_shift.c:instantiate_shlxq/emit_shlxq_x86. -/
def bpf_x86_shlxq (m : X86RegMap) (d r c : BPF.Reg) : X86StateEquiv m := cert m true true d r c
/-- x86/bpf_x86_bmi2_shift.c:instantiate_shrxl/emit_shrxl_x86. -/
def bpf_x86_shrxl (m : X86RegMap) (d r c : BPF.Reg) : X86StateEquiv m := cert m false false d r c
/-- x86/bpf_x86_bmi2_shift.c:instantiate_shrxq/emit_shrxq_x86. -/
def bpf_x86_shrxq (m : X86RegMap) (d r c : BPF.Reg) : X86StateEquiv m := cert m true false d r c

end Kinsn.ModuleBmiShift
