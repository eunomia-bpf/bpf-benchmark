import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleMovswl

/-- x86/bpf_x86_mov.c:instantiate_movswl_rr, all four RR form tags. -/
def bpf (d r : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .mov .w32 d (.reg r)),
   .core (.alu .lsh .w32 d (BPF.immN 16)),
   .core (.alu .arsh .w32 d (BPF.immN 16))]

/-- x86/bpf_x86_mov.c:emit_movswl_x86/emit_movzx_rr_x86, 0F BF /r. -/
def native (m : X86RegMap) (d r : BPF.Reg) : List X86.MInsn :=
  [.movswl (m.map d) (m.map r)]

def value (v : BitVec 64) : BitVec 64 :=
  BitVec.setWidth 64 (BitVec.signExtend 32 (BitVec.setWidth 16 v))

def spec (d r : BPF.Reg) : Outcome → Outcome := ModuleRegister.unarySpec d r value

theorem shift_pair (v : BitVec 64) :
    BitVec.setWidth 64 (((BitVec.setWidth 32 v) <<< 16).sshiftRight 16) = value v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [value, BitVec.getLsbD_setWidth, BitVec.getLsbD_sshiftRight,
    BitVec.getLsbD_shiftLeft, BitVec.getLsbD_signExtend,
    BitVec.msb_eq_getLsbD_last]
  interval_cases i <;> simp

theorem bpf_correct (d r : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf d r) s) = spec d r (observeBpf s) := by
  simp [bpf, spec, ModuleRegister.unarySpec, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.immN, observeBpf, shift_pair,
    BitVec.setWidth_setWidth_of_le, BPF.RegFile.set_set_same]

theorem native_correct (m : X86RegMap) (d r : BPF.Reg) (s : X86.State) :
    observeX86 m (X86.mexec (native m d r) s) = spec d r (observeX86 m s) := by
  simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  rw [x86_observe_set]
  rfl

/-- The selected injective map is Linux's ordinary or ARCH map. Mixed RR
    forms restrict the raw BPF side to R0-R9, so any R10 belongs to the ARCH
    side and selects the frame register rather than the private-stack map. -/
def bpf_x86_movswl (m : X86RegMap) (d r : BPF.Reg) : X86StateEquiv m where
  spec := spec d r
  bpf := bpf d r
  native := native m d r
  writeSet := [d]
  bpfCorrect := bpf_correct d r
  nativeCorrect := native_correct m d r
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleMovswl
