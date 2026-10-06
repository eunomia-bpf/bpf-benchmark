/-
  Reverse the eight bytes of a register: 19 BPF instructions against one
  native instruction on either back-end.

  The expansion is the classical three-stage swap.  Its masks do not fit BPF's
  sign-extended 32-bit immediate field, so each stage materialises its mask
  with `LD_IMM64` — this is the kinsn that forces the framework's second
  scratch register.
-/
import KinsnLean4.Kinsn.Defs

namespace Kinsn.Bswap

/-- `0x00FF00FF00FF00FF` -/
def mask8 : BitVec 64 := 0x00FF00FF00FF00FF
/-- `0x0000FFFF0000FFFF` -/
def mask16 : BitVec 64 := 0x0000FFFF0000FFFF

def bpfInsns (dst src t₀ t₁ : BPF.Reg) : List BPF.Insn :=
  [ BPF.mov64 dst (.reg src),
    -- swap the bytes inside each halfword
    BPF.Insn.ldImm64 t₁ mask8,
    BPF.mov64 t₀ (.reg dst),
    BPF.rsh64 t₀ (BPF.immN 8),
    BPF.and64 t₀ (.reg t₁),
    BPF.and64 dst (.reg t₁),
    BPF.lsh64 dst (BPF.immN 8),
    BPF.or64 dst (.reg t₀),
    -- swap the halfwords inside each word
    BPF.Insn.ldImm64 t₁ mask16,
    BPF.mov64 t₀ (.reg dst),
    BPF.rsh64 t₀ (BPF.immN 16),
    BPF.and64 t₀ (.reg t₁),
    BPF.and64 dst (.reg t₁),
    BPF.lsh64 dst (BPF.immN 16),
    BPF.or64 dst (.reg t₀),
    -- swap the two words
    BPF.mov64 t₀ (.reg dst),
    BPF.rsh64 t₀ (BPF.immN 32),
    BPF.lsh64 dst (BPF.immN 32),
    BPF.or64 dst (.reg t₀) ]

/-- Available since `BPF_BSWAP`. -/
def bpfInsnsEnd (dst src : BPF.Reg) : List BPF.Insn :=
  [ BPF.mov64 dst (.reg src), BPF.Insn.bswap .b64 dst ]

def armInsns (dst src : ARM64.GPReg) : List ARM64.Insn :=
  [ ARM64.Insn.rev64 dst src ]

def x86Insns (dst src : X86.GPReg) : List X86.Insn :=
  [ X86.Insn.movRR dst src, X86.Insn.bswap dst ]

theorem bpf_correct (rf : BPF.RegFile) (dst src t₀ t₁ : BPF.Reg)
    (h0d : t₀ ≠ dst) (h1d : t₁ ≠ dst) (h01 : t₀ ≠ t₁) :
    BPF.exec (bpfInsns dst src t₀ t₁) rf dst = Bits.bswap64 (rf src) := by
  simp only [bpfInsns, BPF.exec_cons, BPF.exec_nil, BPF.mov64, BPF.rsh64, BPF.lsh64,
    BPF.and64, BPF.or64, BPF.step_alu64, BPF.step_ldImm64, BPF.AluOp.eval,
    BPF.Src.eval_reg, BPF.Src.eval_imm, BPF.immN, BPF.RegFile.set_same,
    BPF.RegFile.set_other _ _ _ _ h0d, BPF.RegFile.set_other _ _ _ _ (Ne.symm h0d),
    BPF.RegFile.set_other _ _ _ _ (Ne.symm h1d),
    BPF.RegFile.set_other _ _ _ _ (Ne.symm h01),
    BitVec.toNat_ofNat, Bits.bswap64, mask8, mask16]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  interval_cases i <;> simp

theorem bpf_correct_end (rf : BPF.RegFile) (dst src : BPF.Reg) :
    BPF.exec (bpfInsnsEnd dst src) rf dst = Bits.bswap64 (rf src) := by
  simp [bpfInsnsEnd, BPF.mov64, BPF.AluOp.eval, BPF.Insn.evalBswap]

theorem bpf_writes (dst src t₀ t₁ r : BPF.Reg) :
    r ∈ BPF.writes (bpfInsns dst src t₀ t₁) → r = dst ∨ r = t₀ ∨ r = t₁ := by
  simp [bpfInsns, BPF.writes, BPF.mov64, BPF.rsh64, BPF.lsh64, BPF.and64, BPF.or64,
    BPF.Insn.dstReg]
  tauto

theorem arm_correct (rf : ARM64.RegFile) (dst src : ARM64.GPReg) (hxzr : dst ≠ .xzr) :
    (ARM64.exec (armInsns dst src) rf).get dst = Bits.bswap64 (rf.get src) := by
  simp [armInsns, hxzr]

theorem arm_writes (dst src r : ARM64.GPReg) :
    r ∈ ARM64.writes (armInsns dst src) → r = dst := by
  simp [armInsns, ARM64.writes, ARM64.Insn.dstReg]

theorem x86_correct (rf : X86.RegFile) (dst src : X86.GPReg) :
    X86.exec (x86Insns dst src) rf dst = Bits.bswap64 (rf src) := by
  simp [x86Insns]

theorem x86_writes (dst src r : X86.GPReg) :
    r ∈ X86.writes (x86Insns dst src) → r = dst := by
  simp [x86Insns, X86.writes, X86.Insn.dstReg]

def kinsn : KinsnEquiv where
  name := "bswap64"
  spec := Bits.bswap64
  bpfInsns := bpfInsns
  bpfCorrect rf dst src t₀ t₁ _ h0d _ h1d h01 := bpf_correct rf dst src t₀ t₁ h0d h1d h01
  bpfWrites := bpf_writes
  armInsns dst src _ _ := armInsns dst src
  armCorrect rf dst src _ _ _ _ _ _ _ hxzr _ _ := arm_correct rf dst src hxzr
  armWrites dst src _ _ r h := Or.inl (arm_writes dst src r h)
  x86Insns dst src _ _ := x86Insns dst src
  x86Correct rf dst src _ _ _ _ _ _ _ := x86_correct rf dst src
  x86Writes dst src _ _ r h := Or.inl (x86_writes dst src r h)

/-- The three-stage expansion and `BPF_BSWAP` agree. -/
theorem bpf_expansions_agree (rf : BPF.RegFile) (dst src t₀ t₁ : BPF.Reg)
    (h0d : t₀ ≠ dst) (h1d : t₁ ≠ dst) (h01 : t₀ ≠ t₁) :
    BPF.exec (bpfInsns dst src t₀ t₁) rf dst = BPF.exec (bpfInsnsEnd dst src) rf dst := by
  rw [bpf_correct rf dst src t₀ t₁ h0d h1d h01, bpf_correct_end rf dst src]

end Kinsn.Bswap
