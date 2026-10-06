import KinsnLean4.Kinsn.StateEquiv

namespace Kinsn.ModulePrefetch

/-- x86/bpf_x86_prefetch.c:instantiate_prefetcht0;
    arm64/bpf_arm64_prfm.c:instantiate_prfm_pldl1keep.
    Both modules explicitly use BPF_JMP_A(0), not a dummy memory load. -/
def bpf : List BPF.MInsn := [.ja 0]

/-- x86/bpf_x86_prefetch.c:emit_prefetcht0_x86 / emit_prefetcht0_mem. -/
def x86 (base : X86.GPReg) : List X86.MInsn := [.prefetch base]

/-- arm64/bpf_arm64_prfm.c:emit_prfm_pldl1keep_arm64 / a64_prfm_pldl1keep. -/
def arm (base : ARM64.GPReg) : List ARM64.MInsn := [.prfm base]

theorem bpf_correct (s : BPF.State) : BPF.mexec bpf s = s := by simp [bpf, BPF.mexec]
theorem arm_correct (base : ARM64.GPReg) (s : ARM64.State) : ARM64.mexec (arm base) s = s := rfl
theorem x86_correct (base : X86.GPReg) (s : X86.State) : X86.mexec (x86 base) s = s := rfl

/-- arm64/bpf_arm64_prfm.c:instantiate_prfm_pldl1keep/emit_prfm_pldl1keep_arm64. -/
def armCert (m : ARMRegMap) (base : BPF.Reg) : ArmStateEquiv m where
  spec := id
  bpf := bpf
  native := arm (m.map base)
  writeSet := []
  bpfCorrect := by intro s; rw [bpf_correct]; rfl
  nativeCorrect := by intro s; rfl
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [arm, ARM64.mwrites, ARM64.MInsn.writes]

/-- x86/bpf_x86_prefetch.c:instantiate_prefetcht0/emit_prefetcht0_x86. -/
def x86Cert (m : X86RegMap) (base : BPF.Reg) : X86StateEquiv m where
  spec := id
  bpf := bpf
  native := x86 (m.map base)
  writeSet := []
  bpfCorrect := by intro s; rw [bpf_correct]; rfl
  nativeCorrect := by intro s; rfl
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [x86, X86.mwrites, X86.MInsn.writes]

end Kinsn.ModulePrefetch
