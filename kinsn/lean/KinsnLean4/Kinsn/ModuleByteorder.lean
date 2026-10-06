import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleByteorder

/-- x86/bpf_x86_byteorder.c:instantiate_rolw_imm/instantiate_bswap.
Both ordinary and ARCH payloads operate directly on the decoded live register. -/
def bpf (sz : BPF.EndSize) (d : BPF.Reg) : List BPF.MInsn :=
  [.core (.bswap sz d)]

/-- x86/bpf_x86_byteorder.c:emit_rolw_imm_x86/emit_bswap_x86.
ROLW 8 is followed by MOVZX dst32,dst16 to match BPF_BSWAP16. -/
def native (sz : BPF.EndSize) (d : X86.GPReg) : List X86.MInsn :=
  match sz with
  | .b16 => [.rolW d 8, .movzx 16 d d]
  | .b32 => [.bswap32 d]
  | .b64 => [.core (.bswap d)]

theorem rolw_value (v : BitVec 64) :
    BitVec.setWidth 64 (BitVec.setWidth 16
      (X86.writeWidth 16 v (BitVec.setWidth 64
        ((BitVec.setWidth 16 v).rotateLeft (8 % 16))))) =
      BPF.Insn.evalBswap .b16 v := by
  simp only [X86.writeWidth, BPF.Insn.evalBswap, Bits.bswap16]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  interval_cases i <;> simp [Bits.lowMask]

theorem bpf_correct (sz : BPF.EndSize) (d : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf sz d) s) =
      ModuleRegister.unarySpec d d (BPF.Insn.evalBswap sz) (observeBpf s) := by
  simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
    ModuleRegister.unarySpec, observeBpf]

theorem native_correct (m : X86RegMap) (sz : BPF.EndSize) (d : BPF.Reg)
    (s : X86.State) :
    observeX86 m (X86.mexec (native sz (m.map d)) s) =
      ModuleRegister.unarySpec d d (BPF.Insn.evalBswap sz) (observeX86 m s) := by
  cases sz with
  | b16 =>
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
    rw [Machine.set_same, rolw_value, x86_observe_set, x86_observe_set]
    simp [ModuleRegister.unarySpec, observeX86, BPF.RegFile.set_set_same]
  | b32 =>
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step,
      x86_observe_set]
    rfl
  | b64 =>
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step,
      X86.Insn.step, observeX86, ModuleRegister.unarySpec, BPF.Insn.evalBswap]
    congr 1
    funext q
    simp [X86.RegFile.set, BPF.RegFile.set, m.inj.eq_iff]

def cert (m : X86RegMap) (sz : BPF.EndSize) (d : BPF.Reg) : X86StateEquiv m where
  spec := ModuleRegister.unarySpec d d (BPF.Insn.evalBswap sz)
  bpf := bpf sz d
  native := native sz (m.map d)
  writeSet := [d]
  bpfCorrect := bpf_correct sz d
  nativeCorrect := native_correct m sz d
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by
    cases sz <;> simp [native, X86.mwrites, X86.MInsn.writes,
      X86.Insn.dstReg, m.inj.eq_iff]

/-- x86/bpf_x86_byteorder.c:instantiate_rolw_imm/emit_rolw_imm_x86, imm=8. -/
def bpf_x86_rolw (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m .b16 d

/-- x86/bpf_x86_byteorder.c:instantiate_bswapl/emit_bswapl_x86. -/
def bpf_x86_bswapl (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m .b32 d

/-- x86/bpf_x86_byteorder.c:instantiate_bswapq/emit_bswapq_x86. -/
def bpf_x86_bswapq (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m .b64 d

end Kinsn.ModuleByteorder
