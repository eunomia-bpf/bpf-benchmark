/-
  Load a 64-bit constant.  The asymmetry runs the other way here: BPF does it
  in one (two-slot) instruction, ARM64 needs `MOVZ` plus three `MOVK`s.
-/
import KinsnLean4.Kinsn.Defs

namespace Kinsn.LoadImm

/-- The chunk `MOVZ`/`MOVK` with `hw = i` writes. -/
def chunk (imm : BitVec 64) (i : Nat) : BitVec 16 := BitVec.setWidth 16 (imm >>> (16 * i))

def bpfInsns (dst : BPF.Reg) (imm : BitVec 64) : List BPF.Insn :=
  [ BPF.Insn.ldImm64 dst imm ]

def armInsns (dst : ARM64.GPReg) (imm : BitVec 64) : List ARM64.Insn :=
  [ ARM64.Insn.movz dst (chunk imm 0) 0,
    ARM64.Insn.movk dst (chunk imm 1) 1,
    ARM64.Insn.movk dst (chunk imm 2) 2,
    ARM64.Insn.movk dst (chunk imm 3) 3 ]

def x86Insns (dst : X86.GPReg) (imm : BitVec 64) : List X86.Insn :=
  [ X86.Insn.movabs dst imm ]

theorem bpf_correct (rf : BPF.RegFile) (dst : BPF.Reg) (imm : BitVec 64) :
    BPF.exec (bpfInsns dst imm) rf dst = imm := by
  simp [bpfInsns]

theorem bpf_writes (dst r : BPF.Reg) (imm : BitVec 64) :
    r ∈ BPF.writes (bpfInsns dst imm) → r = dst := by
  simp [bpfInsns, BPF.writes, BPF.Insn.dstReg]

/-- The `MOVZ`/`MOVK` chain reconstructs the constant. -/
theorem arm_correct (rf : ARM64.RegFile) (dst : ARM64.GPReg) (imm : BitVec 64)
    (hxzr : dst ≠ .xzr) :
    (ARM64.exec (armInsns dst imm) rf).get dst = imm := by
  simp only [armInsns, ARM64.exec_cons, ARM64.exec_nil, ARM64.step_movz, ARM64.step_movk,
    ARM64.RegFile.get_set_same _ _ _ hxzr, chunk]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  interval_cases i <;> simp

theorem arm_writes (dst r : ARM64.GPReg) (imm : BitVec 64) :
    r ∈ ARM64.writes (armInsns dst imm) → r = dst := by
  simp [armInsns, ARM64.writes, ARM64.Insn.dstReg]

theorem x86_correct (rf : X86.RegFile) (dst : X86.GPReg) (imm : BitVec 64) :
    X86.exec (x86Insns dst imm) rf dst = imm := by
  simp [x86Insns]

theorem x86_writes (dst r : X86.GPReg) (imm : BitVec 64) :
    r ∈ X86.writes (x86Insns dst imm) → r = dst := by
  simp [x86Insns, X86.writes, X86.Insn.dstReg]

/-- The specification ignores the source register. -/
def kinsn (imm : BitVec 64) : KinsnEquiv where
  name := s!"ldimm64 {imm.toNat}"
  spec _ := imm
  bpfInsns dst _ _ _ := bpfInsns dst imm
  bpfCorrect rf dst _ _ _ _ _ _ _ _ := bpf_correct rf dst imm
  bpfWrites dst _ _ _ r h := Or.inl (bpf_writes dst r imm h)
  armInsns dst _ _ _ := armInsns dst imm
  armCorrect rf dst _ _ _ _ _ _ _ _ hxzr _ _ := arm_correct rf dst imm hxzr
  armWrites dst _ _ _ r h := Or.inl (arm_writes dst r imm h)
  x86Insns dst _ _ _ := x86Insns dst imm
  x86Correct rf dst _ _ _ _ _ _ _ _ := x86_correct rf dst imm
  x86Writes dst _ _ _ r h := Or.inl (x86_writes dst r imm h)

end Kinsn.LoadImm
