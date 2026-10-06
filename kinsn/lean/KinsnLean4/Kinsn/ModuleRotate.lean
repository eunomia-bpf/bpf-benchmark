import KinsnLean4.Kinsn.StateEquiv

namespace Kinsn.ModuleRotate

@[simp] theorem rotateLeft_zero {w : Nat} (v : BitVec w) : v.rotateLeft 0 = v := by
  simp [BitVec.rotateLeft, BitVec.rotateLeftAux, BitVec.ushiftRight_eq_zero (Nat.le_refl w)]

/-- arm64/bpf_arm64_extr.c:instantiate_rotate32/instantiate_rotate64: width-aware rotation specification. -/
def spec (w : BPF.Width) (n : Nat) (v : BitVec 64) : BitVec 64 :=
  match w with
  | .w64 => v.rotateLeft n
  | .w32 => BitVec.setWidth 64 ((BitVec.setWidth 32 v).rotateLeft n)

/-- arm64/bpf_arm64_extr.c:instantiate_rotate64/instantiate_rotate32,
    including the zero-shift path and omitted destination copy for dst=src. -/
def bpf (w : BPF.Width) (dst src tmp : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  let width := if w = .w64 then 64 else 32
  let mov d s := BPF.MInsn.core (.alu .mov w d (.reg s))
  if n = 0 then [mov dst src]
  else [mov tmp src] ++ (if dst = src then [] else [mov dst src]) ++
    [.core (.alu .lsh w dst (BPF.immN n)),
     .core (.alu .rsh w tmp (BPF.immN (width - n))),
     .core (.alu .or w dst (.reg tmp))]

/-- The EXTR leaf of arm64/bpf_arm64_extr.c:emit_rotate_arm64, with Rn=Rm=src,
    lsb=(-shift)&(width-1), including zero. The complete emitted block, including
    the temporary update, is certified in ModuleArmRotate. -/
def arm (w : BPF.Width) (dst src : ARM64.GPReg) (n : Nat) : List ARM64.MInsn :=
  match w with
  | .w64 => [.core (.extr dst src src (BitVec.ofNat 6 ((64 - n) % 64)))]
  | .w32 => [.extrW dst src (BitVec.ofNat 5 ((32 - n) % 32))]

theorem bpf_correct64 (dst src tmp : BPF.Reg) (n : Nat) (hn : n < 64)
    (hts : tmp ≠ src) (htd : tmp ≠ dst) (s : BPF.State) :
    (BPF.mexec (bpf .w64 dst src tmp n) s).regs dst = spec .w64 n (s.regs src) := by
  by_cases hz : n = 0
  · subst n; simp [bpf, spec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval]
  · have hc : 64 - n < 64 := by omega
    by_cases hd : dst = src <;>
      simp [bpf, spec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
        BPF.immN, BPF.RegFile.set, hz, hd, htd, hts, Ne.symm htd, Ne.symm hts,
        Nat.mod_eq_of_lt hn, Nat.mod_eq_of_lt hc, Bits.rotateLeft_eq _ n hn]

theorem bpf_correct32 (dst src tmp : BPF.Reg) (n : Nat) (hn : n < 32)
    (hts : tmp ≠ src) (htd : tmp ≠ dst) (s : BPF.State) :
    (BPF.mexec (bpf .w32 dst src tmp n) s).regs dst = spec .w32 n (s.regs src) := by
  by_cases hz : n = 0
  · subst n; simp [bpf, spec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval]
  · have hc : 32 - n < 32 := by omega
    by_cases hd : dst = src <;>
      simp [bpf, spec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
        BPF.immN, BPF.RegFile.set, hz, hd, htd, hts, Ne.symm htd, Ne.symm hts,
        Nat.mod_eq_of_lt hn, Nat.mod_eq_of_lt hc, Bits.rotateLeft_eq _ n hn]
    all_goals congr 1
    all_goals apply BitVec.eq_of_getLsbD_eq; intro i hi
    all_goals simp only [BitVec.getLsbD_setWidth, BitVec.getLsbD_ushiftRight]
    all_goals by_cases h : i < 32 <;> simp [h]
    all_goals omega

theorem arm_correct64 (dst src : ARM64.GPReg) (n : Nat) (hn : n < 64)
    (hz : dst ≠ .xzr) (s : ARM64.State) :
    (ARM64.mexec (arm .w64 dst src n) s).armGet dst = spec .w64 n (s.armGet src) := by
  by_cases h : n = 0
  · subst n
    simp [arm, spec, ARM64.MInsn.step, ARM64.Insn.step, ARM64.execEXTR,
      Machine.State.armGet, ARM64.RegFile.get, ARM64.RegFile.set, hz]
  · have hc : 64 - n < 64 := by omega
    simp [arm, spec, ARM64.MInsn.step, ARM64.Insn.step,
      ARM64.execEXTR_self, BitVec.toNat_ofNat, Nat.mod_eq_of_lt hc,
      Machine.State.armGet, ARM64.RegFile.get, ARM64.RegFile.set, hz,
      ← Bits.rotateLeft_eq_rotateRight _ n hn (by omega)]

theorem arm_correct32 (dst src : ARM64.GPReg) (n : Nat) (hn : n < 32)
    (hz : dst ≠ .xzr) (s : ARM64.State) :
    (ARM64.mexec (arm .w32 dst src n) s).armGet dst = spec .w32 n (s.armGet src) := by
  by_cases h : n = 0
  · subst n; simp [arm, spec, ARM64.MInsn.step, hz]
  · have hc : 32 - n < 32 := by omega
    simp [arm, spec, ARM64.MInsn.step, hz, BitVec.toNat_ofNat,
      Nat.mod_eq_of_lt hc, ← Bits.rotateLeft_eq_rotateRight _ n hn (by omega)]

theorem bpf_writes (w : BPF.Width) (dst src tmp r : BPF.Reg) (n : Nat) :
    r ∈ BPF.mwrites (bpf w dst src tmp n) → r = dst ∨ r = tmp := by
  by_cases hz : n = 0 <;> by_cases hd : dst = src <;>
    simp [bpf, hz, hd, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] <;> tauto

theorem arm_writes (w : BPF.Width) (dst src r : ARM64.GPReg) (n : Nat) :
    r ∈ ARM64.mwrites (arm w dst src n) → r = dst := by
  cases w <;> simp [arm, ARM64.mwrites, ARM64.MInsn.writes, ARM64.Insn.dstReg]

/-- arm64/bpf_arm64_extr.c:instantiate_rotate32/64 and emit_rotate32/64_arm64.
    Retained abstract EXTR-leaf proof: the temporary is excluded from register
    observation. ModuleArmRotate certifies the complete module block. Every memory
    byte and the entire ordered access trace are equal. -/
theorem arm_refines (m : ARMRegMap) (w : BPF.Width) (dst src tmp : BPF.Reg)
    (n : Nat) (hn : n < (if w = .w64 then 64 else 32))
    (hts : tmp ≠ src) (htd : tmp ≠ dst) (b : BPF.State) (a : ARM64.State)
    (hinit : observeBpf b = observeArm m a) :
    Machine.Sim m.map Machine.State.armGet [tmp]
      (BPF.mexec (bpf w dst src tmp n) b)
      (ARM64.mexec (arm w (m.map dst) (m.map src) n) a) := by
  apply arm_refines_of_results m _ _ dst [tmp] b a hinit
  · have hi : b.regs src = a.armGet (m.map src) :=
      congrFun (congrArg Outcome.regs hinit) src
    cases w
    · rw [bpf_correct32 _ _ _ _ hn hts htd, arm_correct32 _ _ _ hn (m.ne_xzr _)]; rw [hi]
    · rw [bpf_correct64 _ _ _ _ hn hts htd, arm_correct64 _ _ _ hn (m.ne_xzr _)]; rw [hi]
  · intro r hr
    simpa using bpf_writes w dst src tmp r n hr
  · intro r hr
    exact Or.inl (m.inj (arm_writes _ _ _ _ _ hr))
  · have hi := congrArg Outcome.mem hinit
    cases w <;> by_cases hz : n = 0 <;> by_cases hd : dst = src <;>
      simpa [bpf, arm, hz, hd, BPF.mexec, BPF.MInsn.step, ARM64.MInsn.step] using hi
  · have hi := congrArg Outcome.trace hinit
    cases w <;> by_cases hz : n = 0 <;> by_cases hd : dst = src <;>
      simpa [bpf, arm, hz, hd, BPF.mexec, BPF.MInsn.step, ARM64.MInsn.step] using hi

end Kinsn.ModuleRotate
