import KinsnLean4.Kinsn.ModuleRotate

namespace Kinsn.ModuleArmRotate

def temporary (w : BPF.Width) (n : Nat) (v : BitVec 64) : BitVec 64 :=
  match w with
  | .w32 => BitVec.setWidth 64 ((BitVec.setWidth 32 v) >>> (32 - n))
  | .w64 => v >>> (64 - n)

/-- arm64/bpf_arm64_extr.c:emit_rotate_arm64 now reproduces the proof's
    decoded temporary with LSR W/X before EXTR, except on the zero-shift path. -/
def native (w : BPF.Width) (d src t : ARM64.GPReg) (n : Nat) : List ARM64.MInsn :=
  if n = 0 then ModuleRotate.arm w d src n
  else match w with
    | .w32 => .lsrW t src (BitVec.ofNat 5 (32-n)) :: ModuleRotate.arm w d src n
    | .w64 => .core (ARM64.lsr t src (64-n)) :: ModuleRotate.arm w d src n

def spec (w : BPF.Width) (d src t : BPF.Reg) (n : Nat) (s : Outcome) : Outcome :=
  let rf := if n = 0 then s.regs else s.regs.set t (temporary w n (s.regs src))
  { s with regs := rf.set d (ModuleRotate.spec w n (s.regs src)) }

theorem temp_bpf (w : BPF.Width) (d src t : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) (hts : t ≠ src) (htd : t ≠ d)
    (hz : n ≠ 0) (s : BPF.State) :
    (BPF.mexec (ModuleRotate.bpf w d src t n) s).regs t = temporary w n (s.regs src) := by
  have hc : (if w = .w64 then 64 else 32) - n < (if w = .w64 then 64 else 32) := by omega
  cases w <;> by_cases hd : d = src <;>
    simp [ModuleRotate.bpf, temporary, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
      BPF.AluOp.eval, BPF.Src.eval, BPF.immN, BPF.RegFile.set, hz, hd,
      hts, htd, Ne.symm hts, Ne.symm htd] at hn hc ⊢
  all_goals rw [Nat.mod_eq_of_lt (by omega)]

theorem bpf_correct (w : BPF.Width) (d src t : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) (hts : t ≠ src) (htd : t ≠ d)
    (s : BPF.State) :
    observeBpf (BPF.mexec (ModuleRotate.bpf w d src t n) s) = spec w d src t n (observeBpf s) := by
  have hd : (BPF.mexec (ModuleRotate.bpf w d src t n) s).regs d =
      ModuleRotate.spec w n (s.regs src) := by
    cases w
    · exact ModuleRotate.bpf_correct32 d src t n hn hts htd s
    · exact ModuleRotate.bpf_correct64 d src t n hn hts htd s
  have hm : (BPF.mexec (ModuleRotate.bpf w d src t n) s).mem = s.mem := by
    cases w <;> by_cases hz : n = 0 <;> by_cases he : d = src <;>
      simp [ModuleRotate.bpf, hz, he, BPF.mexec, BPF.MInsn.step]
  have htrace : (BPF.mexec (ModuleRotate.bpf w d src t n) s).trace = s.trace := by
    cases w <;> by_cases hz : n = 0 <;> by_cases he : d = src <;>
      simp [ModuleRotate.bpf, hz, he, BPF.mexec, BPF.MInsn.step]
  by_cases hz : n = 0
  · subst n
    cases w <;> simp [ModuleRotate.bpf, spec, ModuleRotate.spec, BPF.mexec,
      BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval, observeBpf]
  · have ht := temp_bpf w d src t n hn hts htd hz s
    simp only [observeBpf, spec, hz, ↓reduceIte, hm, htrace]
    congr 1
    funext q
    by_cases hqd : q = d
    · subst q; simpa [BPF.RegFile.set] using hd
    · by_cases hqt : q = t
      · subst q; simpa [BPF.RegFile.set, htd] using ht
      · have hf := BPF.mexec_frame (ModuleRotate.bpf w d src t n) s q (by
          intro hh
          exact (ModuleRotate.bpf_writes w d src t q n hh).elim hqd hqt)
        simpa [BPF.RegFile.set, hqd, hqt] using hf

/-- Retained EXTR-leaf proofs lift to a full-register leaf specification. -/
theorem leaf_correct (m : ARMRegMap) (w : BPF.Width) (d src : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) (s : ARM64.State) :
    observeArm m (ARM64.mexec (ModuleRotate.arm w (m.map d) (m.map src) n) s) =
      { regs := BPF.RegFile.set (observeArm m s).regs d
          (ModuleRotate.spec w n (s.armGet (m.map src)))
        mem := s.mem, trace := s.trace } := by
  have hd : (ARM64.mexec (ModuleRotate.arm w (m.map d) (m.map src) n) s).armGet (m.map d) =
      ModuleRotate.spec w n (s.armGet (m.map src)) := by
    cases w
    · exact ModuleRotate.arm_correct32 _ _ n hn (m.ne_xzr _) s
    · exact ModuleRotate.arm_correct64 _ _ n hn (m.ne_xzr _) s
  have hm : (ARM64.mexec (ModuleRotate.arm w (m.map d) (m.map src) n) s).mem = s.mem := by
    cases w <;> rfl
  have ht : (ARM64.mexec (ModuleRotate.arm w (m.map d) (m.map src) n) s).trace = s.trace := by
    cases w <;> rfl
  simp only [observeArm, hm, ht]
  congr 1
  funext q
  by_cases he : q = d
  · subst q; simpa [BPF.RegFile.set] using hd
  · have hf := ARM64.mexec_frame (ModuleRotate.arm w (m.map d) (m.map src) n) s (m.map q)
      (by intro hh; exact he (m.inj (ModuleRotate.arm_writes w _ _ _ n hh)))
    simpa [BPF.RegFile.set, he] using hf

theorem native_correct (m : ARMRegMap) (w : BPF.Width) (d src t : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) (hts : t ≠ src) (s : ARM64.State) :
    observeArm m (ARM64.mexec (native w (m.map d) (m.map src) (m.map t) n) s) =
      spec w d src t n (observeArm m s) := by
  by_cases hz : n = 0
  · simpa [native, spec, hz] using leaf_correct m w d src n hn s
  · have hc : (if w = .w64 then 64 else 32) - n < (if w = .w64 then 64 else 32) := by omega
    cases w
    all_goals simp only [reduceCtorEq, ↓reduceIte] at hn hc
    · have he : (BitVec.ofNat 5 (32-n)).toNat = 32-n := by
        simp only [BitVec.toNat_ofNat]; exact Nat.mod_eq_of_lt hc
      simp only [native, hz, ↓reduceIte, ARM64.mexec_cons, ARM64.MInsn.step, he]
      rw [leaf_correct m .w32 d src n hn, arm_observe_set]
      simp [spec, hz, temporary, observeArm, Machine.State.armGet, ARM64.RegFile.get,
        Machine.State.set, m.ne_xzr, m.inj.eq_iff, Ne.symm hts]
    · simp only [native, hz, ↓reduceIte, ARM64.mexec_cons, ARM64.MInsn.step]
      rw [ARM64.step_lsr _ _ _ hc]
      change observeArm m (ARM64.mexec (ModuleRotate.arm .w64 (m.map d) (m.map src) n)
        (s.set (m.map t) (s.armGet (m.map src) >>> (64-n)))) = _
      rw [leaf_correct m .w64 d src n hn, arm_observe_set]
      simp [spec, hz, temporary, observeArm, Machine.State.armGet, ARM64.RegFile.get,
        Machine.State.set, m.ne_xzr, m.inj.eq_iff, Ne.symm hts]

def cert (m : ARMRegMap) (w : BPF.Width) (d src t : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) (hts : t ≠ src) (htd : t ≠ d) :
    ArmStateEquiv m where
  spec := spec w d src t n
  bpf := ModuleRotate.bpf w d src t n
  native := native w (m.map d) (m.map src) (m.map t) n
  writeSet := [d, t]
  bpfCorrect := bpf_correct w d src t n hn hts htd
  nativeCorrect := native_correct m w d src t n hn hts
  bpfWrites := by
    intro r h
    simpa using ModuleRotate.bpf_writes w d src t r n h
  nativeWrites := by
    cases w <;> by_cases hz : n = 0 <;>
      simp [native, ModuleRotate.arm, hz, ARM64.mwrites, ARM64.MInsn.writes,
        ARM64.Insn.dstReg, ARM64.lsr, m.inj.eq_iff, or_comm]

/-- Full mapped RF, all memory and trace; no temporary is excluded. -/
def bpf_arm64_extr_w (m : ARMRegMap) (d src t : BPF.Reg) (n : Nat) (hn : n < 32)
    (hts : t ≠ src) (htd : t ≠ d) : ArmStateEquiv m := cert m .w32 d src t n hn hts htd
/-- Full mapped RF, all memory and trace; no temporary is excluded. -/
def bpf_arm64_extr_x (m : ARMRegMap) (d src t : BPF.Reg) (n : Nat) (hn : n < 64)
    (hts : t ≠ src) (htd : t ≠ d) : ArmStateEquiv m := cert m .w64 d src t n hn hts htd

end Kinsn.ModuleArmRotate
