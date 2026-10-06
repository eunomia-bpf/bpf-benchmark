/-
  Sign-extend the low `w` bits.  Pre-`BPF_MOVSX` BPF needs a shift pair; ARM64
  uses `SBFM` and x86 `MOVSX`.
-/
import KinsnLean4.Kinsn.Defs

namespace Kinsn.SignExtend

def spec (w : Nat) (src : BitVec 64) : BitVec 64 :=
  BitVec.signExtend 64 (BitVec.setWidth w src)

def bpfInsns (dst src : BPF.Reg) (w : Nat) : List BPF.Insn :=
  [ BPF.mov64 dst (.reg src),
    BPF.lsh64 dst (BPF.immN (64 - w)),
    BPF.arsh64 dst (BPF.immN (64 - w)) ]

/-- Available since `BPF_MOVSX`. -/
def bpfInsnsMovsx (dst src : BPF.Reg) (w : Nat) : List BPF.Insn :=
  [ BPF.Insn.movsx w dst (.reg src) ]

def armInsns (dst src : ARM64.GPReg) (w : Nat) : List ARM64.Insn :=
  [ ARM64.sxt dst src w ]

def x86Insns (dst src : X86.GPReg) (w : Nat) : List X86.Insn :=
  [ X86.Insn.movsx w dst src ]

theorem bpf_correct (rf : BPF.RegFile) (dst src : BPF.Reg) (w : Nat)
    (h1 : 1 ≤ w) (h2 : w ≤ 64) :
    BPF.exec (bpfInsns dst src w) rf dst = spec w (rf src) := by
  simp [bpfInsns, spec, BPF.mov64, BPF.lsh64, BPF.arsh64, BPF.AluOp.eval, BPF.immN,
    Nat.mod_eq_of_lt (show 64 - w < 64 by omega),
    Bits.shiftLeft_sshiftRight_eq_signExtend _ w h1 h2]

theorem bpf_correct_movsx (rf : BPF.RegFile) (dst src : BPF.Reg) (w : Nat) :
    BPF.exec (bpfInsnsMovsx dst src w) rf dst = spec w (rf src) := by
  simp [bpfInsnsMovsx, spec]

theorem bpf_writes (dst src : BPF.Reg) (w : Nat) (r : BPF.Reg) :
    r ∈ BPF.writes (bpfInsns dst src w) → r = dst := by
  simp [bpfInsns, BPF.writes, BPF.mov64, BPF.lsh64, BPF.arsh64, BPF.Insn.dstReg]

theorem arm_correct (rf : ARM64.RegFile) (dst src : ARM64.GPReg) (w : Nat)
    (h1 : 1 ≤ w) (h2 : w ≤ 64) (hxzr : dst ≠ .xzr) :
    (ARM64.exec (armInsns dst src w) rf).get dst = spec w (rf.get src) := by
  simp [armInsns, ARM64.step_sxt dst src w h1 h2, spec, hxzr]

theorem arm_writes (dst src : ARM64.GPReg) (w : Nat) (r : ARM64.GPReg) :
    r ∈ ARM64.writes (armInsns dst src w) → r = dst := by
  simp [armInsns, ARM64.writes, ARM64.sxt, ARM64.Insn.dstReg]

theorem x86_correct (rf : X86.RegFile) (dst src : X86.GPReg) (w : Nat) :
    X86.exec (x86Insns dst src w) rf dst = spec w (rf src) := by
  simp [x86Insns, spec]

theorem x86_writes (dst src : X86.GPReg) (w : Nat) (r : X86.GPReg) :
    r ∈ X86.writes (x86Insns dst src w) → r = dst := by
  simp [x86Insns, X86.writes, X86.Insn.dstReg]

/-- `_henc` records that x86 `MOVSX` only encodes byte, word and doubleword
    source widths. -/
def kinsn (w : Nat) (h1 : 1 ≤ w) (h2 : w ≤ 64)
    (_henc : w = 8 ∨ w = 16 ∨ w = 32) : KinsnEquiv where
  name := s!"sxt{w}"
  spec := spec w
  bpfInsns dst src _ _ := bpfInsns dst src w
  bpfCorrect rf dst src _ _ _ _ _ _ _ := bpf_correct rf dst src w h1 h2
  bpfWrites dst src _ _ r h := Or.inl (bpf_writes dst src w r h)
  armInsns dst src _ _ := armInsns dst src w
  armCorrect rf dst src _ _ _ _ _ _ _ hxzr _ _ := arm_correct rf dst src w h1 h2 hxzr
  armWrites dst src _ _ r h := Or.inl (arm_writes dst src w r h)
  x86Insns dst src _ _ := x86Insns dst src w
  x86Correct rf dst src _ _ _ _ _ _ _ := x86_correct rf dst src w
  x86Writes dst src _ _ r h := Or.inl (x86_writes dst src w r h)

/-- The shift pair and `BPF_MOVSX` agree. -/
theorem bpf_expansions_agree (rf : BPF.RegFile) (dst src : BPF.Reg) (w : Nat)
    (h1 : 1 ≤ w) (h2 : w ≤ 64) :
    BPF.exec (bpfInsns dst src w) rf dst = BPF.exec (bpfInsnsMovsx dst src w) rf dst := by
  rw [bpf_correct rf dst src w h1 h2, bpf_correct_movsx rf dst src w]

end Kinsn.SignExtend
