/-
  BPF has no rotate instruction, so a rotate costs a copy plus four ALU
  instructions; both back-ends do it in one.
-/
import KinsnLean4.Kinsn.Defs

namespace Kinsn.Rotate

/-! ## Rotate right -/

def rorSpec (n : Nat) (src : BitVec 64) : BitVec 64 := src.rotateRight n

def rorBpf (dst src t₀ : BPF.Reg) (n : Nat) : List BPF.Insn :=
  [ BPF.mov64 t₀ (.reg src),
    BPF.lsh64 t₀ (BPF.immN (64 - n)),
    BPF.mov64 dst (.reg src),
    BPF.rsh64 dst (BPF.immN n),
    BPF.or64 dst (.reg t₀) ]

def rorArm (dst src : ARM64.GPReg) (n : Nat) : List ARM64.Insn :=
  [ ARM64.ror dst src n ]

def rorX86 (dst src : X86.GPReg) (n : Nat) : List X86.Insn :=
  [ X86.Insn.movRR dst src, X86.Insn.shiftI .ror dst (BitVec.ofNat 8 n) ]

theorem ror_bpf_correct (rf : BPF.RegFile) (dst src t₀ : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hn' : n < 64) (hts : t₀ ≠ src) (htd : t₀ ≠ dst) :
    BPF.exec (rorBpf dst src t₀ n) rf dst = rorSpec n (rf src) := by
  simp [rorBpf, rorSpec, BPF.mov64, BPF.lsh64, BPF.rsh64, BPF.or64, BPF.AluOp.eval,
    BPF.immN, htd, Ne.symm hts, Bits.rotateRight_eq _ n hn',
    Nat.mod_eq_of_lt hn', Nat.mod_eq_of_lt (show 64 - n < 64 by omega)]

theorem ror_bpf_writes (dst src t₀ : BPF.Reg) (n : Nat) (r : BPF.Reg) :
    r ∈ BPF.writes (rorBpf dst src t₀ n) → r = dst ∨ r = t₀ := by
  simp [rorBpf, BPF.writes, BPF.mov64, BPF.lsh64, BPF.rsh64, BPF.or64, BPF.Insn.dstReg]
  tauto

theorem ror_arm_correct (rf : ARM64.RegFile) (dst src : ARM64.GPReg) (n : Nat)
    (hn : n < 64) (hxzr : dst ≠ .xzr) :
    (ARM64.exec (rorArm dst src n) rf).get dst = rorSpec n (rf.get src) := by
  simp [rorArm, ARM64.step_ror dst src n hn, rorSpec, hxzr]

theorem ror_arm_writes (dst src : ARM64.GPReg) (n : Nat) (r : ARM64.GPReg) :
    r ∈ ARM64.writes (rorArm dst src n) → r = dst := by
  simp [rorArm, ARM64.writes, ARM64.ror, ARM64.Insn.dstReg]

theorem ror_x86_correct (rf : X86.RegFile) (dst src : X86.GPReg) (n : Nat)
    (hn : n < 64) :
    X86.exec (rorX86 dst src n) rf dst = rorSpec n (rf src) := by
  simp [rorX86, rorSpec, X86.ShiftOp.eval, BitVec.toNat_ofNat,
    Nat.mod_eq_of_lt hn, Nat.mod_eq_of_lt (show n < 256 by omega)]

theorem ror_x86_writes (dst src : X86.GPReg) (n : Nat) (r : X86.GPReg) :
    r ∈ X86.writes (rorX86 dst src n) → r = dst := by
  simp [rorX86, X86.writes, X86.Insn.dstReg]

def rorKinsn (n : Nat) (hn : 0 < n) (hn' : n < 64) : KinsnEquiv where
  name := s!"ror{n}"
  spec := rorSpec n
  bpfInsns dst src t₀ _ := rorBpf dst src t₀ n
  bpfCorrect rf dst src t₀ _ hts htd _ _ _ := ror_bpf_correct rf dst src t₀ n hn hn' hts htd
  bpfWrites dst src t₀ _ r h := Or.imp id Or.inl (ror_bpf_writes dst src t₀ n r h)
  armInsns dst src _ _ := rorArm dst src n
  armCorrect rf dst src _ _ _ _ _ _ _ hxzr _ _ := ror_arm_correct rf dst src n hn' hxzr
  armWrites dst src _ _ r h := Or.inl (ror_arm_writes dst src n r h)
  x86Insns dst src _ _ := rorX86 dst src n
  x86Correct rf dst src _ _ _ _ _ _ _ := ror_x86_correct rf dst src n hn'
  x86Writes dst src _ _ r h := Or.inl (ror_x86_writes dst src n r h)

/-! ## Rotate left -/

def rolSpec (n : Nat) (src : BitVec 64) : BitVec 64 := src.rotateLeft n

def rolBpf (dst src t₀ : BPF.Reg) (n : Nat) : List BPF.Insn :=
  [ BPF.mov64 t₀ (.reg src),
    BPF.rsh64 t₀ (BPF.immN (64 - n)),
    BPF.mov64 dst (.reg src),
    BPF.lsh64 dst (BPF.immN n),
    BPF.or64 dst (.reg t₀) ]

/-- ARM64 has no `ROL`: rotate right by `64 - n`. -/
def rolArm (dst src : ARM64.GPReg) (n : Nat) : List ARM64.Insn :=
  [ ARM64.ror dst src (64 - n) ]

def rolX86 (dst src : X86.GPReg) (n : Nat) : List X86.Insn :=
  [ X86.Insn.movRR dst src, X86.Insn.shiftI .rol dst (BitVec.ofNat 8 n) ]

theorem rol_bpf_correct (rf : BPF.RegFile) (dst src t₀ : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hn' : n < 64) (hts : t₀ ≠ src) (htd : t₀ ≠ dst) :
    BPF.exec (rolBpf dst src t₀ n) rf dst = rolSpec n (rf src) := by
  simp [rolBpf, rolSpec, BPF.mov64, BPF.lsh64, BPF.rsh64, BPF.or64, BPF.AluOp.eval,
    BPF.immN, htd, Ne.symm hts, Bits.rotateLeft_eq _ n hn',
    Nat.mod_eq_of_lt hn', Nat.mod_eq_of_lt (show 64 - n < 64 by omega)]

theorem rol_bpf_writes (dst src t₀ : BPF.Reg) (n : Nat) (r : BPF.Reg) :
    r ∈ BPF.writes (rolBpf dst src t₀ n) → r = dst ∨ r = t₀ := by
  simp [rolBpf, BPF.writes, BPF.mov64, BPF.lsh64, BPF.rsh64, BPF.or64, BPF.Insn.dstReg]
  tauto

theorem rol_arm_correct (rf : ARM64.RegFile) (dst src : ARM64.GPReg) (n : Nat)
    (hn : 0 < n) (hn' : n < 64) (hxzr : dst ≠ .xzr) :
    (ARM64.exec (rolArm dst src n) rf).get dst = rolSpec n (rf.get src) := by
  simp [rolArm, ARM64.step_ror dst src (64 - n) (by omega), rolSpec, hxzr,
    Bits.rotateLeft_eq_rotateRight _ n hn' hn]

theorem rol_arm_writes (dst src : ARM64.GPReg) (n : Nat) (r : ARM64.GPReg) :
    r ∈ ARM64.writes (rolArm dst src n) → r = dst := by
  simp [rolArm, ARM64.writes, ARM64.ror, ARM64.Insn.dstReg]

theorem rol_x86_correct (rf : X86.RegFile) (dst src : X86.GPReg) (n : Nat)
    (hn : n < 64) :
    X86.exec (rolX86 dst src n) rf dst = rolSpec n (rf src) := by
  simp [rolX86, rolSpec, X86.ShiftOp.eval, BitVec.toNat_ofNat,
    Nat.mod_eq_of_lt hn, Nat.mod_eq_of_lt (show n < 256 by omega)]

theorem rol_x86_writes (dst src : X86.GPReg) (n : Nat) (r : X86.GPReg) :
    r ∈ X86.writes (rolX86 dst src n) → r = dst := by
  simp [rolX86, X86.writes, X86.Insn.dstReg]

def rolKinsn (n : Nat) (hn : 0 < n) (hn' : n < 64) : KinsnEquiv where
  name := s!"rol{n}"
  spec := rolSpec n
  bpfInsns dst src t₀ _ := rolBpf dst src t₀ n
  bpfCorrect rf dst src t₀ _ hts htd _ _ _ := rol_bpf_correct rf dst src t₀ n hn hn' hts htd
  bpfWrites dst src t₀ _ r h := Or.imp id Or.inl (rol_bpf_writes dst src t₀ n r h)
  armInsns dst src _ _ := rolArm dst src n
  armCorrect rf dst src _ _ _ _ _ _ _ hxzr _ _ := rol_arm_correct rf dst src n hn hn' hxzr
  armWrites dst src _ _ r h := Or.inl (rol_arm_writes dst src n r h)
  x86Insns dst src _ _ := rolX86 dst src n
  x86Correct rf dst src _ _ _ _ _ _ _ := rol_x86_correct rf dst src n hn'
  x86Writes dst src _ _ r h := Or.inl (rol_x86_writes dst src n r h)

end Kinsn.Rotate
