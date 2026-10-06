/-
  `dst[lsb+width-1 : lsb] := src[width-1 : 0]`.

  This kinsn reads its destination, so its specification is binary and it does
  not instantiate the unary `KinsnEquiv` record; the equivalences are stated
  directly.  ARM64 does it in one `BFM`, x86 has no single-instruction form.
-/
import KinsnLean4.Kinsn.Defs

namespace Kinsn.Insert

def spec (lsb width : Nat) (dst src : BitVec 64) : BitVec 64 :=
  (dst &&& ~~~(Bits.lowMask 64 width <<< lsb)) ||| ((src &&& Bits.lowMask 64 width) <<< lsb)

def bpfInsns (dst src t₀ t₁ : BPF.Reg) (lsb width : Nat) : List BPF.Insn :=
  [ BPF.Insn.ldImm64 t₁ (Bits.lowMask 64 width),
    BPF.mov64 t₀ (.reg src),
    BPF.and64 t₀ (.reg t₁),
    BPF.lsh64 t₀ (BPF.immN lsb),
    BPF.Insn.ldImm64 t₁ (~~~(Bits.lowMask 64 width <<< lsb)),
    BPF.and64 dst (.reg t₁),
    BPF.or64 dst (.reg t₀) ]

def armInsns (dst src : ARM64.GPReg) (lsb width : Nat) : List ARM64.Insn :=
  [ ARM64.bfi dst src lsb width ]

def x86Insns (dst src t₀ t₁ : X86.GPReg) (lsb width : Nat) : List X86.Insn :=
  [ X86.Insn.movabs t₁ (Bits.lowMask 64 width),
    X86.Insn.movRR t₀ src,
    X86.Insn.aluRR .and t₀ t₁,
    X86.Insn.shiftI .shl t₀ (BitVec.ofNat 8 lsb),
    X86.Insn.movabs t₁ (~~~(Bits.lowMask 64 width <<< lsb)),
    X86.Insn.aluRR .and dst t₁,
    X86.Insn.aluRR .or dst t₀ ]

theorem bpf_correct (rf : BPF.RegFile) (dst src t₀ t₁ : BPF.Reg) (lsb width : Nat)
    (hlsb : lsb < 64) (_h0s : t₀ ≠ src) (h0d : t₀ ≠ dst) (h1s : t₁ ≠ src)
    (h1d : t₁ ≠ dst) (h01 : t₀ ≠ t₁) :
    BPF.exec (bpfInsns dst src t₀ t₁ lsb width) rf dst = spec lsb width (rf dst) (rf src) := by
  simp [bpfInsns, spec, BPF.mov64, BPF.and64, BPF.lsh64, BPF.or64, BPF.AluOp.eval,
    BPF.immN, h0d, h01, Ne.symm h0d, Ne.symm h1s,
    Ne.symm h1d, Ne.symm h01, Nat.mod_eq_of_lt hlsb]

theorem bpf_writes (dst src t₀ t₁ : BPF.Reg) (lsb width : Nat) (r : BPF.Reg) :
    r ∈ BPF.writes (bpfInsns dst src t₀ t₁ lsb width) → r = dst ∨ r = t₀ ∨ r = t₁ := by
  simp [bpfInsns, BPF.writes, BPF.mov64, BPF.and64, BPF.lsh64, BPF.or64, BPF.Insn.dstReg]
  tauto

theorem arm_correct (rf : ARM64.RegFile) (dst src : ARM64.GPReg) (lsb width : Nat)
    (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) (hxzr : dst ≠ .xzr) :
    (ARM64.exec (armInsns dst src lsb width) rf).get dst =
      spec lsb width (rf.get dst) (rf.get src) := by
  simp [armInsns, ARM64.step_bfi dst src lsb width h1 h2, spec, hxzr]

theorem arm_writes (dst src : ARM64.GPReg) (lsb width : Nat) (r : ARM64.GPReg) :
    r ∈ ARM64.writes (armInsns dst src lsb width) → r = dst := by
  simp [armInsns, ARM64.writes, ARM64.bfi, ARM64.Insn.dstReg]

theorem x86_correct (rf : X86.RegFile) (dst src t₀ t₁ : X86.GPReg) (lsb width : Nat)
    (hlsb : lsb < 64) (_h0s : t₀ ≠ src) (h0d : t₀ ≠ dst) (h1s : t₁ ≠ src)
    (h1d : t₁ ≠ dst) (h01 : t₀ ≠ t₁) :
    X86.exec (x86Insns dst src t₀ t₁ lsb width) rf dst = spec lsb width (rf dst) (rf src) := by
  simp [x86Insns, spec, X86.AluOp.eval, X86.ShiftOp.eval, h0d, h01,
    Ne.symm h0d, Ne.symm h1s, Ne.symm h1d, Ne.symm h01,
    Nat.mod_eq_of_lt hlsb, Nat.mod_eq_of_lt (show lsb < 256 by omega)]

theorem x86_writes (dst src t₀ t₁ : X86.GPReg) (lsb width : Nat) (r : X86.GPReg) :
    r ∈ X86.writes (x86Insns dst src t₀ t₁ lsb width) → r = dst ∨ r = t₀ ∨ r = t₁ := by
  simp [x86Insns, X86.writes, X86.Insn.dstReg]
  tauto


theorem three_way_equiv (lsb width : Nat) (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64)
    (dstVal srcVal : BitVec 64)
    (brf : BPF.RegFile) (bd bs b₀ b₁ : BPF.Reg)
    (hb : b₀ ≠ bs ∧ b₀ ≠ bd ∧ b₁ ≠ bs ∧ b₁ ≠ bd ∧ b₀ ≠ b₁)
    (hbd : brf bd = dstVal) (hbs : brf bs = srcVal)
    (arf : ARM64.RegFile) (ad as' : ARM64.GPReg) (haz : ad ≠ .xzr)
    (had : arf.get ad = dstVal) (has : arf.get as' = srcVal)
    (xrf : X86.RegFile) (xd xs x₀ x₁ : X86.GPReg)
    (hx : x₀ ≠ xs ∧ x₀ ≠ xd ∧ x₁ ≠ xs ∧ x₁ ≠ xd ∧ x₀ ≠ x₁)
    (hxd : xrf xd = dstVal) (hxs : xrf xs = srcVal) :
    BPF.exec (bpfInsns bd bs b₀ b₁ lsb width) brf bd =
      (ARM64.exec (armInsns ad as' lsb width) arf).get ad ∧
    BPF.exec (bpfInsns bd bs b₀ b₁ lsb width) brf bd =
      X86.exec (x86Insns xd xs x₀ x₁ lsb width) xrf xd := by
  obtain ⟨p1, p2, p3, p4, p5⟩ := hb
  obtain ⟨q1, q2, q3, q4, q5⟩ := hx
  rw [bpf_correct brf bd bs b₀ b₁ lsb width (by omega) p1 p2 p3 p4 p5,
      arm_correct arf ad as' lsb width h1 h2 haz,
      x86_correct xrf xd xs x₀ x₁ lsb width (by omega) q1 q2 q3 q4 q5,
      hbd, hbs, had, has, hxd, hxs]
  exact ⟨rfl, rfl⟩

end Kinsn.Insert
