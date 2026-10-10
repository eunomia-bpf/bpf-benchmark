import KinsnLean4.Kinsn.ModuleRotate
import KinsnLean4.Kinsn.ModuleX86Rotate

namespace Kinsn.ModuleArmRotate

/-- The payload's legacy temporary field is not an output. The expansion
    writes only d, holding each carry bit in control flow. -/
def bpf (w : BPF.Width) (d src : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  ModuleX86Rotate.leaf (w = .w64) d src n

def native (w : BPF.Width) (d src : ARM64.GPReg) (n : Nat) : List ARM64.MInsn :=
  ModuleRotate.arm w d src n

def spec (w : BPF.Width) (d src : BPF.Reg) (n : Nat) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (ModuleRotate.spec w n (s.regs src)) }

theorem bpf_correct (w : BPF.Width) (d src : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf w d src n) s) = spec w d src n (observeBpf s) := by
  have h := ModuleX86Rotate.leaf_exec (w = .w64) d src n s []
  simp only [List.append_nil, BPF.mexec] at h
  rw [bpf, h]
  have hi := ModuleRotateOne.iterate_rotate (w = .w64)
    (BitVec.setWidth (ModuleRotateOne.bits (w = .w64)) (s.regs src)) n (by cases w <;> simpa [ModuleRotateOne.bits] using hn)
  cases w <;> simpa [ModuleX86Rotate.effect, spec, ModuleRotate.spec,
    ModuleRotateOne.bits, observeBpf] using congrArg
      (fun v => ({ regs := BPF.RegFile.set s.regs d v, mem := s.mem, trace := s.trace } : Outcome)) hi

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

theorem native_correct (m : ARMRegMap) (w : BPF.Width) (d src : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) (s : ARM64.State) :
    observeArm m (ARM64.mexec (native w (m.map d) (m.map src) n) s) =
      spec w d src n (observeArm m s) :=
  leaf_correct m w d src n hn s

def cert (m : ARMRegMap) (w : BPF.Width) (d src : BPF.Reg) (n : Nat)
    (hn : n < (if w = .w64 then 64 else 32)) : ArmStateEquiv m where
  spec := spec w d src n
  bpf := bpf w d src n
  native := native w (m.map d) (m.map src) n
  writeSet := [d]
  bpfCorrect := bpf_correct w d src n hn
  nativeCorrect := native_correct m w d src n hn
  bpfWrites := by
    intro r h
    exact List.mem_singleton.mpr (ModuleX86Rotate.leaf_writes (w = .w64) d src r n h)
  nativeWrites := by
    intro r h
    exact List.mem_singleton.mpr (m.inj (ModuleRotate.arm_writes w _ _ _ n h))

/-- Full mapped RF, all memory and ordered accesses; destination is the only output. -/
def bpf_arm64_extr_w (m : ARMRegMap) (d src : BPF.Reg) (n : Nat) (hn : n < 32) :
    ArmStateEquiv m := cert m .w32 d src n hn
/-- Full mapped RF, all memory and ordered accesses; destination is the only output. -/
def bpf_arm64_extr_x (m : ARMRegMap) (d src : BPF.Reg) (n : Nat) (hn : n < 64) :
    ArmStateEquiv m := cert m .w64 d src n hn

end Kinsn.ModuleArmRotate
