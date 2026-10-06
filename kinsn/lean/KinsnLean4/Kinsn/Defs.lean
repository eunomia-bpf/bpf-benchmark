/-
  The kinsn equivalence framework.

  A `KinsnEquiv` bundles a unary specification with a BPF expansion and both
  native emissions, each certified against it; the cross-ISA equivalences are
  then corollaries.

  Expansions get a destination, a source and *two* scratch registers.  Two are
  needed because BPF immediates are sign-extended 32-bit fields, so a general
  64-bit mask must be materialised with `LD_IMM64` into a register of its own
  on top of the one holding the partial result.

  The `*Writes` fields give the frame condition, which is what upgrades "the
  destination matches" into "splicing the native block in place of the BPF
  block preserves the machine state".
-/
import KinsnLean4.BPF.Semantics
import KinsnLean4.ARM64.Semantics
import KinsnLean4.X86.Semantics

namespace Kinsn

/-- A kinsn certified on all three instruction sets. -/
structure KinsnEquiv where
  name : String
  spec : BitVec 64 → BitVec 64

  bpfInsns : BPF.Reg → BPF.Reg → BPF.Reg → BPF.Reg → List BPF.Insn
  bpfCorrect : ∀ (rf : BPF.RegFile) (dst src t₀ t₁ : BPF.Reg),
    t₀ ≠ src → t₀ ≠ dst → t₁ ≠ src → t₁ ≠ dst → t₀ ≠ t₁ →
    BPF.exec (bpfInsns dst src t₀ t₁) rf dst = spec (rf src)
  bpfWrites : ∀ (dst src t₀ t₁ r : BPF.Reg),
    r ∈ BPF.writes (bpfInsns dst src t₀ t₁) → r = dst ∨ r = t₀ ∨ r = t₁

  armInsns : ARM64.GPReg → ARM64.GPReg → ARM64.GPReg → ARM64.GPReg → List ARM64.Insn
  armCorrect : ∀ (rf : ARM64.RegFile) (dst src t₀ t₁ : ARM64.GPReg),
    t₀ ≠ src → t₀ ≠ dst → t₁ ≠ src → t₁ ≠ dst → t₀ ≠ t₁ →
    dst ≠ .xzr → t₀ ≠ .xzr → t₁ ≠ .xzr →
    (ARM64.exec (armInsns dst src t₀ t₁) rf).get dst = spec (rf.get src)
  armWrites : ∀ (dst src t₀ t₁ r : ARM64.GPReg),
    r ∈ ARM64.writes (armInsns dst src t₀ t₁) → r = dst ∨ r = t₀ ∨ r = t₁

  x86Insns : X86.GPReg → X86.GPReg → X86.GPReg → X86.GPReg → List X86.Insn
  x86Correct : ∀ (rf : X86.RegFile) (dst src t₀ t₁ : X86.GPReg),
    t₀ ≠ src → t₀ ≠ dst → t₁ ≠ src → t₁ ≠ dst → t₀ ≠ t₁ →
    X86.exec (x86Insns dst src t₀ t₁) rf dst = spec (rf src)
  x86Writes : ∀ (dst src t₀ t₁ r : X86.GPReg),
    r ∈ X86.writes (x86Insns dst src t₀ t₁) → r = dst ∨ r = t₀ ∨ r = t₁

namespace KinsnEquiv

variable (k : KinsnEquiv)

/-- BPF expansion ≡ ARM64 emission. -/
theorem bpf_arm_equiv (brf : BPF.RegFile) (arf : ARM64.RegFile)
    (bd bs b₀ b₁ : BPF.Reg) (ad as' a₀ a₁ : ARM64.GPReg)
    (hb : b₀ ≠ bs ∧ b₀ ≠ bd ∧ b₁ ≠ bs ∧ b₁ ≠ bd ∧ b₀ ≠ b₁)
    (ha : a₀ ≠ as' ∧ a₀ ≠ ad ∧ a₁ ≠ as' ∧ a₁ ≠ ad ∧ a₀ ≠ a₁)
    (hz : ad ≠ .xzr ∧ a₀ ≠ .xzr ∧ a₁ ≠ .xzr)
    (hval : brf bs = arf.get as') :
    BPF.exec (k.bpfInsns bd bs b₀ b₁) brf bd =
      (ARM64.exec (k.armInsns ad as' a₀ a₁) arf).get ad := by
  obtain ⟨h1, h2, h3, h4, h5⟩ := hb
  obtain ⟨g1, g2, g3, g4, g5⟩ := ha
  obtain ⟨z1, z2, z3⟩ := hz
  rw [k.bpfCorrect brf bd bs b₀ b₁ h1 h2 h3 h4 h5,
      k.armCorrect arf ad as' a₀ a₁ g1 g2 g3 g4 g5 z1 z2 z3, hval]

/-- BPF expansion ≡ x86-64 emission. -/
theorem bpf_x86_equiv (brf : BPF.RegFile) (xrf : X86.RegFile)
    (bd bs b₀ b₁ : BPF.Reg) (xd xs x₀ x₁ : X86.GPReg)
    (hb : b₀ ≠ bs ∧ b₀ ≠ bd ∧ b₁ ≠ bs ∧ b₁ ≠ bd ∧ b₀ ≠ b₁)
    (hx : x₀ ≠ xs ∧ x₀ ≠ xd ∧ x₁ ≠ xs ∧ x₁ ≠ xd ∧ x₀ ≠ x₁)
    (hval : brf bs = xrf xs) :
    BPF.exec (k.bpfInsns bd bs b₀ b₁) brf bd =
      X86.exec (k.x86Insns xd xs x₀ x₁) xrf xd := by
  obtain ⟨h1, h2, h3, h4, h5⟩ := hb
  obtain ⟨g1, g2, g3, g4, g5⟩ := hx
  rw [k.bpfCorrect brf bd bs b₀ b₁ h1 h2 h3 h4 h5,
      k.x86Correct xrf xd xs x₀ x₁ g1 g2 g3 g4 g5, hval]

/-- ARM64 emission ≡ x86-64 emission. -/
theorem arm_x86_equiv (arf : ARM64.RegFile) (xrf : X86.RegFile)
    (ad as' a₀ a₁ : ARM64.GPReg) (xd xs x₀ x₁ : X86.GPReg)
    (ha : a₀ ≠ as' ∧ a₀ ≠ ad ∧ a₁ ≠ as' ∧ a₁ ≠ ad ∧ a₀ ≠ a₁)
    (hz : ad ≠ .xzr ∧ a₀ ≠ .xzr ∧ a₁ ≠ .xzr)
    (hx : x₀ ≠ xs ∧ x₀ ≠ xd ∧ x₁ ≠ xs ∧ x₁ ≠ xd ∧ x₀ ≠ x₁)
    (hval : arf.get as' = xrf xs) :
    (ARM64.exec (k.armInsns ad as' a₀ a₁) arf).get ad =
      X86.exec (k.x86Insns xd xs x₀ x₁) xrf xd := by
  obtain ⟨g1, g2, g3, g4, g5⟩ := ha
  obtain ⟨z1, z2, z3⟩ := hz
  obtain ⟨f1, f2, f3, f4, f5⟩ := hx
  rw [k.armCorrect arf ad as' a₀ a₁ g1 g2 g3 g4 g5 z1 z2 z3,
      k.x86Correct xrf xd xs x₀ x₁ f1 f2 f3 f4 f5, hval]

end KinsnEquiv

/-! ## Register maps and simulation -/

/-- A BPF-to-ARM64 register allocation. -/
structure ARMRegMap where
  map : BPF.Reg → ARM64.GPReg
  inj : Function.Injective map
  ne_xzr : ∀ r, map r ≠ .xzr

/-- A BPF-to-x86-64 register allocation. -/
structure X86RegMap where
  map : BPF.Reg → X86.GPReg
  inj : Function.Injective map

/-- The two machines agree on every BPF register outside `S`. -/
def ARMSimExcept (m : ARMRegMap) (S : List BPF.Reg)
    (brf : BPF.RegFile) (arf : ARM64.RegFile) : Prop :=
  ∀ r, r ∉ S → brf r = arf.get (m.map r)

/-- The two machines agree on every BPF register outside `S`. -/
def X86SimExcept (m : X86RegMap) (S : List BPF.Reg)
    (brf : BPF.RegFile) (xrf : X86.RegFile) : Prop :=
  ∀ r, r ∉ S → brf r = xrf (m.map r)

namespace KinsnEquiv

variable (k : KinsnEquiv)

/-- Rewrite soundness: if the machines agree before the block, they still
    agree after running the BPF expansion on one and the ARM64 emission on the
    other, except on the scratch registers the kinsn may clobber. -/
theorem arm_refines (m : ARMRegMap) (brf : BPF.RegFile) (arf : ARM64.RegFile)
    (dst src t₀ t₁ : BPF.Reg)
    (h1 : t₀ ≠ src) (h2 : t₀ ≠ dst) (h3 : t₁ ≠ src) (h4 : t₁ ≠ dst) (h5 : t₀ ≠ t₁)
    (hsim : ARMSimExcept m [] brf arf) :
    ARMSimExcept m [t₀, t₁]
      (BPF.exec (k.bpfInsns dst src t₀ t₁) brf)
      (ARM64.exec (k.armInsns (m.map dst) (m.map src) (m.map t₀) (m.map t₁)) arf) := by
  intro r hr
  simp only [List.mem_cons, List.not_mem_nil, or_false, not_or] at hr
  by_cases hrd : r = dst
  · subst hrd
    exact k.bpf_arm_equiv brf arf r src t₀ t₁ (m.map r) (m.map src) (m.map t₀) (m.map t₁)
      ⟨h1, h2, h3, h4, h5⟩
      ⟨fun h => h1 (m.inj h), fun h => h2 (m.inj h), fun h => h3 (m.inj h),
       fun h => h4 (m.inj h), fun h => h5 (m.inj h)⟩
      ⟨m.ne_xzr _, m.ne_xzr _, m.ne_xzr _⟩ (hsim src (by simp))
  · rw [BPF.exec_of_not_mem_writes _ _ _ (fun hmem => by
        rcases k.bpfWrites dst src t₀ t₁ r hmem with h | h | h <;> simp_all)]
    rw [ARM64.exec_of_not_mem_writes _ _ _ (fun hmem => by
        rcases k.armWrites (m.map dst) (m.map src) (m.map t₀) (m.map t₁) (m.map r) hmem
          with h | h | h <;> simp_all [m.inj h])]
    exact hsim r (by simp)

/-- Rewrite soundness, x86-64 side. -/
theorem x86_refines (m : X86RegMap) (brf : BPF.RegFile) (xrf : X86.RegFile)
    (dst src t₀ t₁ : BPF.Reg)
    (h1 : t₀ ≠ src) (h2 : t₀ ≠ dst) (h3 : t₁ ≠ src) (h4 : t₁ ≠ dst) (h5 : t₀ ≠ t₁)
    (hsim : X86SimExcept m [] brf xrf) :
    X86SimExcept m [t₀, t₁]
      (BPF.exec (k.bpfInsns dst src t₀ t₁) brf)
      (X86.exec (k.x86Insns (m.map dst) (m.map src) (m.map t₀) (m.map t₁)) xrf) := by
  intro r hr
  simp only [List.mem_cons, List.not_mem_nil, or_false, not_or] at hr
  by_cases hrd : r = dst
  · subst hrd
    exact k.bpf_x86_equiv brf xrf r src t₀ t₁ (m.map r) (m.map src) (m.map t₀) (m.map t₁)
      ⟨h1, h2, h3, h4, h5⟩
      ⟨fun h => h1 (m.inj h), fun h => h2 (m.inj h), fun h => h3 (m.inj h),
       fun h => h4 (m.inj h), fun h => h5 (m.inj h)⟩
      (hsim src (by simp))
  · rw [BPF.exec_of_not_mem_writes _ _ _ (fun hmem => by
        rcases k.bpfWrites dst src t₀ t₁ r hmem with h | h | h <;> simp_all)]
    rw [X86.exec_of_not_mem_writes _ _ _ (fun hmem => by
        rcases k.x86Writes (m.map dst) (m.map src) (m.map t₀) (m.map t₁) (m.map r) hmem
          with h | h | h <;> simp_all [m.inj h])]
    exact hsim r (by simp)

end KinsnEquiv

end Kinsn
