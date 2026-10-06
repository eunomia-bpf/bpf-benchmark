import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleNot

/-- x86/bpf_x86_not.c:instantiate_not_narrow/instantiate_notl_r/instantiate_notq_r.
NOT8/16 flips only the positive low mask; NOT32 zero-extends; NOT64 flips all bits.
Ordinary and ARCH forms both use the decoded live register without scratch. -/
def bpf (bits : Nat) (d : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .xor (if bits = 32 then .w32 else .w64) d
    (.imm (if bits = 32 ∨ bits = 64 then -1 else BitVec.ofNat 64 (2 ^ bits - 1))))]

/-- x86/bpf_x86_not.c:emit_not_r_x86: width prefixes select NOT r8/r16/r32/r64. -/
def native (bits : Nat) (d : X86.GPReg) : List X86.MInsn := [.not bits d]

def value (bits : Nat) (v : BitVec 64) : BitVec 64 := X86.writeWidth bits v (~~~v)

theorem narrow_value (bits : Nat) (h : bits = 8 ∨ bits = 16) (v : BitVec 64) :
    v ^^^ BitVec.ofNat 64 (2 ^ bits - 1) = value bits v := by
  rcases h with h | h <;> subst bits <;>
    simp only [value, X86.writeWidth]
  all_goals apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi; interval_cases i <;> simp [Bits.lowMask]

theorem bpf_correct (bits : Nat) (h : bits = 8 ∨ bits = 16 ∨ bits = 32 ∨ bits = 64)
    (d : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf bits d) s) =
      ModuleRegister.unarySpec d d (value bits) (observeBpf s) := by
  rcases h with h | h | h | h <;> subst bits <;>
    simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      observeBpf, ModuleRegister.unarySpec]
  · exact congrArg (BPF.RegFile.set s.regs d) (by simpa using narrow_value 8 (by simp) (s.regs d))
  · exact congrArg (BPF.RegFile.set s.regs d) (by simpa using narrow_value 16 (by simp) (s.regs d))
  · congr 1
    simp only [value, X86.writeWidth]
    apply BitVec.eq_of_getLsbD_eq
    intro i hi
    interval_cases i <;> simp
  · congr 1
    simp only [value, X86.writeWidth]
    apply BitVec.eq_of_getLsbD_eq
    intro i hi
    interval_cases i <;> simp

theorem native_correct (m : X86RegMap) (bits : Nat) (d : BPF.Reg) (s : X86.State) :
    observeX86 m (X86.mexec (native bits (m.map d)) s) =
      ModuleRegister.unarySpec d d (value bits) (observeX86 m s) := by
  simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, x86_observe_set]
  rfl

def cert (m : X86RegMap) (bits : Nat)
    (h : bits = 8 ∨ bits = 16 ∨ bits = 32 ∨ bits = 64) (d : BPF.Reg) :
    X86StateEquiv m where
  spec := ModuleRegister.unarySpec d d (value bits)
  bpf := bpf bits d
  native := native bits (m.map d)
  writeSet := [d]
  bpfCorrect := bpf_correct bits h d
  nativeCorrect := native_correct m bits d
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_not.c:instantiate_notb_r/emit_notb_r_x86. -/
def bpf_x86_notb (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m 8 (by simp) d

/-- x86/bpf_x86_not.c:instantiate_notw_r/emit_notw_r_x86. -/
def bpf_x86_notw (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m 16 (by simp) d

/-- x86/bpf_x86_not.c:instantiate_notl_r/emit_notl_r_x86. -/
def bpf_x86_notl (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m 32 (by simp) d

/-- x86/bpf_x86_not.c:instantiate_notq_r/emit_notq_r_x86. -/
def bpf_x86_notq (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m 64 (by simp) d

end Kinsn.ModuleNot
