import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleImul

/-- x86/bpf_x86_imul.c:instantiate_imulq_rr: ordinary and ARCH both multiply
live decoded registers; no scratch or persistent shadow slots. -/
def bpf (d r : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .mul .w64 d (.reg r))]

/-- x86/bpf_x86_imul.c:emit_imulq_rr_x86: IMUL dst64,src64. The low 64
product bits agree for signed and unsigned multiplication. -/
def native (d r : X86.GPReg) : List X86.MInsn := [.imul d r]

def spec (d r : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (s.regs d * s.regs r) }

def cert (m : X86RegMap) (d r : BPF.Reg) : X86StateEquiv m where
  spec := spec d r
  bpf := bpf d r
  native := native (m.map d) (m.map r)
  writeSet := [d]
  bpfCorrect := by
    intro s
    simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      BPF.Src.eval, spec, observeBpf]
  nativeCorrect := by
    intro s
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, x86_observe_set]
    rfl
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_imul.c:instantiate_imulq_rr/emit_imulq_rr_x86; every operand alias. -/
theorem bpf_x86_imulq_refines (m : X86RegMap) (d r : BPF.Reg)
    (b : BPF.State) (a : X86.State) (h : observeBpf b = observeX86 m a) :
    observeBpf (BPF.mexec (bpf d r) b) =
      observeX86 m (X86.mexec (native (m.map d) (m.map r)) a) :=
  (cert m d r).x86_refines b a h

end Kinsn.ModuleImul
