import KinsnLean4.Kinsn.ModuleFlags

namespace Kinsn.ModuleCsel

/-- arm64/bpf_arm64_csel.c:emit_csel_ne_arm64: TST Xcond,Xcond; CSEL Xdst,Xyes,Xno,NE.
The payload and instantiate_csel_ne are unchanged. -/
def arm (m : ARMRegMap) (dst yes no cond : BPF.Reg) : List ARM64.MInsn :=
  ModuleFlags.tstArm (m.map cond) ++ ModuleFlags.cselArm m dst yes no

/-- Self-contained certificate, with no premise on incoming NZCV.
Decoder allows aliases among all four operands; the theorem does too. -/
def cert (m : ARMRegMap) (dst yes no cond : BPF.Reg) : ArmStateEquiv m where
  spec := ModuleFlags.cselSpec dst yes no cond
  bpf := ModuleFlags.cselBpf dst yes no cond
  native := arm m dst yes no cond
  writeSet := [dst]
  bpfCorrect := ModuleFlags.csel_bpf_correct dst yes no cond
  nativeCorrect := ModuleFlags.tst_csel_arm_correct m dst yes no cond
  bpfWrites := by
    simp [ModuleFlags.cselBpf, BPF.mwrites, BPF.MInsn.writes,
      BPF.mov64, BPF.Insn.dstReg]
  nativeWrites := by
    simp [arm, ModuleFlags.tstArm, ModuleFlags.cselArm,
      ARM64.mwrites, ARM64.MInsn.writes, m.inj.eq_iff]

theorem bpf_arm64_csel_ne_refines (m : ARMRegMap) (dst yes no cond : BPF.Reg)
    (b : BPF.State) (a : ARM64.State) (h : observeBpf b = observeArm m a) :
    observeBpf (BPF.mexec (ModuleFlags.cselBpf dst yes no cond) b) =
      observeArm m (ARM64.mexec (arm m dst yes no cond) a) :=
  (cert m dst yes no cond).arm_refines b a h

end Kinsn.ModuleCsel
