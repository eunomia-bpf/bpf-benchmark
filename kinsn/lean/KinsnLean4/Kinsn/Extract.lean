/-
  `dst = (src >> lsb) & ((1 << width) - 1)`.

  BPF has no bitfield instruction; ARM64 does it with `UBFX` and x86 BMI1 with
  `BEXTR`.  The mask does not in general fit BPF's sign-extended 32-bit
  immediate field, so the expansion materialises it with `LD_IMM64`;
  `bpfInsnsShort` is the three-instruction form, legal only for `width ≤ 31`.
-/
import KinsnLean4.Kinsn.Defs

namespace Kinsn.Extract

/-- Bits `[lsb + width - 1 : lsb]`, zero-extended. -/
def spec (lsb width : Nat) (src : BitVec 64) : BitVec 64 :=
  (src >>> lsb) &&& Bits.lowMask 64 width

/-! ## BPF -/

def bpfInsns (dst src tmp : BPF.Reg) (lsb width : Nat) : List BPF.Insn :=
  [ BPF.mov64 dst (.reg src),
    BPF.rsh64 dst (BPF.immN lsb),
    BPF.Insn.ldImm64 tmp (Bits.lowMask 64 width),
    BPF.and64 dst (.reg tmp) ]

/-- Legal only when the mask fits a sign-extended 32-bit immediate. -/
def bpfInsnsShort (dst src : BPF.Reg) (lsb width : Nat) : List BPF.Insn :=
  [ BPF.mov64 dst (.reg src),
    BPF.rsh64 dst (BPF.immN lsb),
    BPF.and64 dst (.imm (Bits.lowMask 64 width)) ]

theorem bpf_correct (rf : BPF.RegFile) (dst src tmp : BPF.Reg) (lsb width : Nat)
    (hlsb : lsb < 64) (htd : tmp ≠ dst) :
    BPF.exec (bpfInsns dst src tmp lsb width) rf dst = spec lsb width (rf src) := by
  have hi : ((BPF.immN lsb).eval rf).toNat % 64 = lsb := BPF.immN_shift_amount rf lsb hlsb
  simp [bpfInsns, spec, BPF.mov64, BPF.rsh64, BPF.and64, BPF.AluOp.eval, BPF.immN,
    Ne.symm htd, Nat.mod_eq_of_lt hlsb]

theorem bpf_correct_short (rf : BPF.RegFile) (dst src : BPF.Reg) (lsb width : Nat)
    (hlsb : lsb < 64) :
    BPF.exec (bpfInsnsShort dst src lsb width) rf dst = spec lsb width (rf src) := by
  simp [bpfInsnsShort, spec, BPF.mov64, BPF.rsh64, BPF.and64, BPF.AluOp.eval, BPF.immN,
    Nat.mod_eq_of_lt hlsb]

/-- The side condition `bpfInsnsShort` needs. -/
theorem mask_imm32_ok (width : Nat) (h : width ≤ 31) :
    BitVec.signExtend 64 (BitVec.setWidth 32 (Bits.lowMask 64 width)) =
      Bits.lowMask 64 width := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  have hw : width < 32 := by omega
  simp only [BitVec.getLsbD_signExtend, BitVec.getLsbD_setWidth, Bits.getLsbD_lowMask,
    BitVec.msb_eq_getLsbD_last]
  by_cases h32 : i < 32
  · simp [h32, hi]
  · simp [h32, hi]
    omega

theorem bpf_writes (dst src tmp : BPF.Reg) (lsb width : Nat) (r : BPF.Reg) :
    r ∈ BPF.writes (bpfInsns dst src tmp lsb width) → r = dst ∨ r = tmp := by
  simp [bpfInsns, BPF.writes, BPF.mov64, BPF.rsh64, BPF.and64, BPF.Insn.dstReg]
  tauto

/-! ## ARM64 -/

def armInsns (dst src : ARM64.GPReg) (lsb width : Nat) : List ARM64.Insn :=
  [ ARM64.ubfx dst src lsb width ]

theorem arm_correct (rf : ARM64.RegFile) (dst src : ARM64.GPReg) (lsb width : Nat)
    (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) (hxzr : dst ≠ .xzr) :
    (ARM64.exec (armInsns dst src lsb width) rf).get dst = spec lsb width (rf.get src) := by
  simp [armInsns, ARM64.step_ubfx dst src lsb width h1 h2, spec, hxzr]

theorem arm_writes (dst src : ARM64.GPReg) (lsb width : Nat) (r : ARM64.GPReg) :
    r ∈ ARM64.writes (armInsns dst src lsb width) → r = dst := by
  simp [armInsns, ARM64.writes, ARM64.ubfx, ARM64.Insn.dstReg]

/-! ## x86-64 -/

def x86Insns (dst src tmp : X86.GPReg) (lsb width : Nat) : List X86.Insn :=
  [ X86.Insn.movRR dst src,
    X86.Insn.shiftI .shr dst (BitVec.ofNat 8 lsb),
    X86.Insn.movabs tmp (Bits.lowMask 64 width),
    X86.Insn.aluRR .and dst tmp ]

/-- The BMI1 form; the first instruction builds the `BEXTR` control word. -/
def x86InsnsBextr (dst src tmp : X86.GPReg) (lsb width : Nat) : List X86.Insn :=
  [ X86.Insn.movabs tmp (X86.bextrCtrl lsb width),
    X86.Insn.bextr dst src tmp ]

theorem x86_correct (rf : X86.RegFile) (dst src tmp : X86.GPReg) (lsb width : Nat)
    (hlsb : lsb < 64) (htd : tmp ≠ dst) :
    X86.exec (x86Insns dst src tmp lsb width) rf dst = spec lsb width (rf src) := by
  have hc : (BitVec.ofNat 8 lsb).toNat % 64 = lsb := by
    simp [BitVec.toNat_ofNat]; omega
  simp [x86Insns, spec, X86.ShiftOp.eval, X86.AluOp.eval, Ne.symm htd,
    Nat.mod_eq_of_lt hlsb, Nat.mod_eq_of_lt (show lsb < 256 by omega)]

theorem x86_correct_bextr (rf : X86.RegFile) (dst src tmp : X86.GPReg) (lsb width : Nat)
    (hlsb : lsb < 64) (hw : width < 256) (hts : tmp ≠ src) :
    X86.exec (x86InsnsBextr dst src tmp lsb width) rf dst = spec lsb width (rf src) := by
  simp only [x86InsnsBextr, X86.exec_cons, X86.exec_nil, X86.step_movabs, X86.step_bextr,
    X86.RegFile.set_same, X86.RegFile.set_other _ _ _ _ (Ne.symm hts)]
  rw [X86.bextr_bextrCtrl _ lsb width (by omega) hw]
  rfl

theorem x86_writes (dst src tmp : X86.GPReg) (lsb width : Nat) (r : X86.GPReg) :
    r ∈ X86.writes (x86Insns dst src tmp lsb width) → r = dst ∨ r = tmp := by
  simp [x86Insns, X86.writes, X86.Insn.dstReg]
  tauto

/-! ## Certified kinsn -/

def kinsn (lsb width : Nat) (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) : KinsnEquiv where
  name := s!"extract[{lsb + width - 1}:{lsb}]"
  spec := spec lsb width
  bpfInsns dst src t₀ _ := bpfInsns dst src t₀ lsb width
  bpfCorrect rf dst src t₀ _ _ htd _ _ _ :=
    bpf_correct rf dst src t₀ lsb width (by omega) htd
  bpfWrites dst src t₀ _ r h := Or.imp id Or.inl (bpf_writes dst src t₀ lsb width r h)
  armInsns dst src _ _ := armInsns dst src lsb width
  armCorrect rf dst src _ _ _ _ _ _ _ hxzr _ _ := arm_correct rf dst src lsb width h1 h2 hxzr
  armWrites dst src _ _ r h := Or.inl (arm_writes dst src lsb width r h)
  x86Insns dst src t₀ _ := x86Insns dst src t₀ lsb width
  x86Correct rf dst src t₀ _ _ htd _ _ _ := x86_correct rf dst src t₀ lsb width (by omega) htd
  x86Writes dst src t₀ _ r h := Or.imp id Or.inl (x86_writes dst src t₀ lsb width r h)

end Kinsn.Extract
