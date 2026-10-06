import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleRev16

/-- arm64/bpf_arm64_rev.c:instantiate_rev16_w (unchanged BPF_BSWAP16). -/
def bpf (dst : BPF.Reg) : List BPF.MInsn := [.core (.bswap .b16 dst)]

/-- arm64/bpf_arm64_rev.c:emit_rev_arm64, bits=16: REV16 Wd,Wd; UXTH Wd,Wd.
The UXTH W and X encodings have the same 64-bit result. -/
def arm (dst : ARM64.GPReg) : List ARM64.MInsn :=
  [.rev16W dst dst, .core (ARM64.uxt dst dst 16)]

theorem swap_value (v : BitVec 64) :
    BitVec.setWidth 64 (BitVec.setWidth 16 (BitVec.setWidth 64
      (((BitVec.setWidth 32 v &&& 0x00ff00ff) <<< 8) |||
       ((BitVec.setWidth 32 v &&& 0xff00ff00) >>> 8)))) =
    BPF.Insn.evalBswap .b16 v := by
  simp only [BPF.Insn.evalBswap, Bits.bswap16]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  interval_cases i <;> simp

/-- Full registers, memory and access-trace certificate for every accepted dst. -/
def cert (m : ARMRegMap) (dst : BPF.Reg) : ArmStateEquiv m where
  spec := ModuleRegister.unarySpec dst dst (BPF.Insn.evalBswap .b16)
  bpf := bpf dst
  native := arm (m.map dst)
  writeSet := [dst]
  bpfCorrect := by
    intro s
    simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
      observeBpf, ModuleRegister.unarySpec]
  nativeCorrect := by
    intro s
    simp only [arm, ARM64.mexec_cons, ARM64.mexec_nil, ARM64.MInsn.step,
      ARM64.step_uxt _ _ 16 (by decide) (by decide)]
    let v := BitVec.setWidth 64
      (((BitVec.setWidth 32 (s.armGet (m.map dst)) &&& 0x00ff00ff) <<< 8) |||
       ((BitVec.setWidth 32 (s.armGet (m.map dst)) &&& 0xff00ff00) >>> 8))
    change observeArm m ((s.set (m.map dst) v).set (m.map dst)
      (BitVec.setWidth 64 (BitVec.setWidth 16 ((s.set (m.map dst) v).armGet
        (m.map dst))))) = _
    rw [ARM64.get_set _ _ _ (m.ne_xzr dst)]
    dsimp only [v]
    rw [swap_value, arm_observe_set, arm_observe_set]
    simp [ModuleRegister.unarySpec, observeArm, BPF.RegFile.set_set_same]
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by
    simp [arm, ARM64.mwrites, ARM64.MInsn.writes, ARM64.Insn.dstReg,
      ARM64.uxt, m.inj.eq_iff]

theorem bpf_arm64_rev16_w_refines (m : ARMRegMap) (dst : BPF.Reg)
    (b : BPF.State) (a : ARM64.State) (h : observeBpf b = observeArm m a) :
    observeBpf (BPF.mexec (bpf dst) b) =
      observeArm m (ARM64.mexec (arm (m.map dst)) a) :=
  (cert m dst).arm_refines b a h

end Kinsn.ModuleRev16
