/-
  The certified kinsn catalogue at the register allocations the Linux BPF JITs
  actually use, plus executable sanity checks.
-/
import KinsnLean4.Kinsn.Extract
import KinsnLean4.Kinsn.Rotate
import KinsnLean4.Kinsn.SignExtend
import KinsnLean4.Kinsn.Bswap
import KinsnLean4.Kinsn.LoadImm
import KinsnLean4.Kinsn.Insert

set_option linter.hashCommand false

namespace Kinsn.Catalog

/-! ## Register allocation

  `bpf2a64` from `arch/arm64/net/bpf_jit_comp.c` and `reg2hex` from
  `arch/x86/net/bpf_jit_comp.c`. -/

def armReg : BPF.Reg → ARM64.GPReg
  | .r0 => .x7
  | .r1 => .x0
  | .r2 => .x1
  | .r3 => .x2
  | .r4 => .x3
  | .r5 => .x4
  | .r6 => .x19
  | .r7 => .x20
  | .r8 => .x21
  | .r9 => .x22
  | .r10 => .x25

def armMap : ARMRegMap where
  map := armReg
  inj := by intro a b h; cases a <;> cases b <;> simp_all [armReg]
  ne_xzr := by intro r; cases r <;> simp [armReg]

def x86Reg : BPF.Reg → X86.GPReg
  | .r0 => .rax
  | .r1 => .rdi
  | .r2 => .rsi
  | .r3 => .rdx
  | .r4 => .rcx
  | .r5 => .r8
  | .r6 => .rbx
  | .r7 => .r13
  | .r8 => .r14
  | .r9 => .r15
  | .r10 => .rbp

def x86Map : X86RegMap where
  map := x86Reg
  inj := by intro a b h; cases a <;> cases b <;> simp_all [x86Reg]

/-! ## Certified kinsns -/

/-- `dst = (src >> 8) & 0xffff` -/
def extract16at8 : KinsnEquiv := Extract.kinsn 8 16 (by norm_num) (by norm_num)
/-- `dst = ror(src, 7)` -/
def ror7 : KinsnEquiv := Rotate.rorKinsn 7 (by norm_num) (by norm_num)
/-- `dst = rol(src, 13)` -/
def rol13 : KinsnEquiv := Rotate.rolKinsn 13 (by norm_num) (by norm_num)
/-- `dst = (s32)src` -/
def sxt32 : KinsnEquiv := SignExtend.kinsn 32 (by norm_num) (by norm_num) (by norm_num)
/-- `dst = bswap64(src)` -/
def bswap64 : KinsnEquiv := Bswap.kinsn
/-- `dst = 0xdeadbeefcafebabe` -/
def ldimm : KinsnEquiv := LoadImm.kinsn 0xdeadbeefcafebabe

def catalog : List KinsnEquiv :=
  [extract16at8, ror7, rol13, sxt32, bswap64, ldimm]

/-! ## Rewrite soundness at the real register allocations -/

/-- Replacing any kinsn's BPF expansion by its ARM64 emission preserves the
    machine state outside the two scratch registers. -/
theorem arm_jit_sound (k : KinsnEquiv) (brf : BPF.RegFile) (arf : ARM64.RegFile)
    (dst src t₀ t₁ : BPF.Reg)
    (h1 : t₀ ≠ src) (h2 : t₀ ≠ dst) (h3 : t₁ ≠ src) (h4 : t₁ ≠ dst) (h5 : t₀ ≠ t₁)
    (hsim : ARMSimExcept armMap [] brf arf) :
    ARMSimExcept armMap [t₀, t₁]
      (BPF.exec (k.bpfInsns dst src t₀ t₁) brf)
      (ARM64.exec (k.armInsns (armReg dst) (armReg src) (armReg t₀) (armReg t₁)) arf) :=
  k.arm_refines armMap brf arf dst src t₀ t₁ h1 h2 h3 h4 h5 hsim

/-- Replacing any kinsn's BPF expansion by its x86-64 emission preserves the
    machine state outside the two scratch registers. -/
theorem x86_jit_sound (k : KinsnEquiv) (brf : BPF.RegFile) (xrf : X86.RegFile)
    (dst src t₀ t₁ : BPF.Reg)
    (h1 : t₀ ≠ src) (h2 : t₀ ≠ dst) (h3 : t₁ ≠ src) (h4 : t₁ ≠ dst) (h5 : t₀ ≠ t₁)
    (hsim : X86SimExcept x86Map [] brf xrf) :
    X86SimExcept x86Map [t₀, t₁]
      (BPF.exec (k.bpfInsns dst src t₀ t₁) brf)
      (X86.exec (k.x86Insns (x86Reg dst) (x86Reg src) (x86Reg t₀) (x86Reg t₁)) xrf) :=
  k.x86_refines x86Map brf xrf dst src t₀ t₁ h1 h2 h3 h4 h5 hsim

/-! ## Executable checks

  The proofs above are parametric; these evaluate all three models on a
  concrete input. -/

def probe : BitVec 64 := 0x0123456789ABCDEF

def bpfState : BPF.RegFile := fun r => if r = .r1 then probe else 0
def armState : ARM64.RegFile := fun r => if r = .x0 then probe else 0
def x86State : X86.RegFile := fun r => if r = .rdi then probe else 0

/-- Run a kinsn on `probe` held in `BPF.r1` and its images. -/
def runBpf (k : KinsnEquiv) : BitVec 64 :=
  BPF.exec (k.bpfInsns .r0 .r1 .r2 .r3) bpfState .r0
def runArm (k : KinsnEquiv) : BitVec 64 :=
  (ARM64.exec (k.armInsns (armReg .r0) (armReg .r1) (armReg .r2) (armReg .r3)) armState).get
    (armReg .r0)
def runX86 (k : KinsnEquiv) : BitVec 64 :=
  X86.exec (k.x86Insns (x86Reg .r0) (x86Reg .r1) (x86Reg .r2) (x86Reg .r3)) x86State (x86Reg .r0)

#guard runBpf extract16at8 == 0xABCD
#guard runArm extract16at8 == 0xABCD
#guard runX86 extract16at8 == 0xABCD

#guard runBpf ror7 == probe.rotateRight 7
#guard runArm ror7 == probe.rotateRight 7
#guard runX86 ror7 == probe.rotateRight 7

#guard runBpf rol13 == probe.rotateLeft 13
#guard runArm rol13 == probe.rotateLeft 13
#guard runX86 rol13 == probe.rotateLeft 13

#guard runBpf sxt32 == 0xFFFFFFFF89ABCDEF
#guard runArm sxt32 == 0xFFFFFFFF89ABCDEF
#guard runX86 sxt32 == 0xFFFFFFFF89ABCDEF

#guard runBpf bswap64 == 0xEFCDAB8967452301
#guard runArm bswap64 == 0xEFCDAB8967452301
#guard runX86 bswap64 == 0xEFCDAB8967452301

#guard runBpf ldimm == 0xdeadbeefcafebabe
#guard runArm ldimm == 0xdeadbeefcafebabe
#guard runX86 ldimm == 0xdeadbeefcafebabe

-- All three models agree on the whole catalogue for this input.
#guard catalog.all (fun k => runBpf k == runArm k && runBpf k == runX86 k)

-- Instruction counts: BPF expansion, ARM64 emission, x86 emission.
#eval catalog.map (fun k =>
  (k.name,
   (k.bpfInsns .r0 .r1 .r2 .r3).length,
   (k.armInsns (armReg .r0) (armReg .r1) (armReg .r2) (armReg .r3)).length,
   (k.x86Insns (x86Reg .r0) (x86Reg .r1) (x86Reg .r2) (x86Reg .r3)).length))

end Kinsn.Catalog
