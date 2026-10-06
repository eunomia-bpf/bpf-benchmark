import KinsnLean4.Kinsn.StateEquiv

namespace Kinsn.ModuleFlags

/-- arm64/bpf_arm64_csel.c:instantiate_tst;
    arm64/bpf_arm64_ccmp.c:instantiate_cmp / instantiate_ccmp. -/
def flagBpf : List BPF.MInsn := [.ja 0]

/-- arm64/bpf_arm64_csel.c:emit_tst_arm64 / a64_tst; ANDS XZR,Xn,Xn. -/
def tstArm (r : ARM64.GPReg) : List ARM64.MInsn := [.tst r]

/-- arm64/bpf_arm64_ccmp.c:emit_cmp_arm64 / a64_cmp_imm; SUBS ZR,Rn,#0. -/
def cmpArm (w : Bool) (r : ARM64.GPReg) : List ARM64.MInsn := [.cmpZero w r]

/-- arm64/bpf_arm64_ccmp.c:emit_ccmp_arm64 / ccmp_mode_fields.
    failNE=false is FAIL_EQ: continue on NE, poison NZCV=4. -/
def ccmpArm (w failNE : Bool) (r : ARM64.GPReg) : List ARM64.MInsn :=
  [.ccmpZero w failNE r]

/-- arm64/bpf_arm64_csel.c:instantiate_tst/emit_tst_arm64. -/
def tstCert (m : ARMRegMap) (r : BPF.Reg) : ArmStateEquiv m where
  spec := id
  bpf := flagBpf
  native := tstArm (m.map r)
  writeSet := []
  bpfCorrect := by intro s; simp [flagBpf, BPF.mexec]
  nativeCorrect := by intro s; rfl
  bpfWrites := by simp [flagBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [tstArm, ARM64.mwrites, ARM64.MInsn.writes]

/-- arm64/bpf_arm64_ccmp.c:instantiate_cmp/emit_cmp_arm64. -/
def cmpCert (m : ARMRegMap) (w : Bool) (r : BPF.Reg) : ArmStateEquiv m where
  spec := id
  bpf := flagBpf
  native := cmpArm w (m.map r)
  writeSet := []
  bpfCorrect := by intro s; simp [flagBpf, BPF.mexec]
  nativeCorrect := by intro s; rfl
  bpfWrites := by simp [flagBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [cmpArm, ARM64.mwrites, ARM64.MInsn.writes]

/-- arm64/bpf_arm64_ccmp.c:instantiate_ccmp/emit_ccmp_arm64. -/
def ccmpCert (m : ARMRegMap) (w failNE : Bool) (r : BPF.Reg) : ArmStateEquiv m where
  spec := id
  bpf := flagBpf
  native := ccmpArm w failNE (m.map r)
  writeSet := []
  bpfCorrect := by intro s; simp [flagBpf, BPF.mexec]
  nativeCorrect := by intro s; rfl
  bpfWrites := by simp [flagBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [ccmpArm, ARM64.mwrites, ARM64.MInsn.writes]

theorem tst_flags (r : ARM64.GPReg) (s : ARM64.State) :
    (ARM64.mexec (tstArm r) s).flags = Machine.tstFlags (s.armGet r) := rfl

/-- arm64/bpf_arm64_ccmp.c:emit_cmp_arm64: zero predicate at decoded width. -/
def zeroTest (w : Bool) (v : BitVec 64) : Bool :=
  if w then BitVec.setWidth 32 v == 0 else v == 0

theorem cmp_zero_flag (w : Bool) (r : ARM64.GPReg) (s : ARM64.State) :
    (ARM64.mexec (cmpArm w r) s).flags.z = zeroTest w (s.armGet r) := by
  cases w <;> simp [cmpArm, ARM64.MInsn.step, Machine.subFlags, zeroTest]

theorem ccmp_zero_flag (w failNE : Bool) (r : ARM64.GPReg) (s : ARM64.State) :
    (ARM64.mexec (ccmpArm w failNE r) s).flags.z =
      if (if failNE then s.flags.z else !s.flags.z) then zeroTest w (s.armGet r)
      else !failNE := by
  cases w <;> cases failNE <;> cases hz : s.flags.z <;>
    simp [ccmpArm, ARM64.MInsn.step, Machine.subFlags, zeroTest, hz]

/-- arm64/bpf_arm64_csel.c:instantiate_csel_ne, offsets 2 and 1. -/
def cselBpf (dst yes no cond : BPF.Reg) : List BPF.MInsn :=
  [.branch .eq .w64 cond (.imm 0) 2, .core (BPF.mov64 dst (.reg yes)),
   .ja 1, .core (BPF.mov64 dst (.reg no))]

/-- Raw CSEL instruction used by the pre-fix emit_csel_ne_arm64 at 69f9a30f6.
    The current complete emitter is ModuleCsel.arm (TST followed by CSEL). -/
def cselArm (m : ARMRegMap) (dst yes no : BPF.Reg) : List ARM64.MInsn :=
  [.cselNE (m.map dst) (m.map yes) (m.map no)]

/-- arm64/bpf_arm64_csel.c:instantiate_csel_ne: condition-register specification. -/
def cselSpec (dst yes no cond : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set dst (if s.regs cond = 0 then s.regs no else s.regs yes) }

theorem csel_bpf_correct (dst yes no cond : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (cselBpf dst yes no cond) s) =
      cselSpec dst yes no cond (observeBpf s) := by
  by_cases h : s.regs cond = 0#64 <;>
    simp [cselBpf, cselSpec, BPF.mexec, BPF.Cond.test, BPF.Cond.eval, BPF.MInsn.step,
      BPF.mov64, BPF.Insn.step, BPF.AluOp.eval, observeBpf, h]

/-- A compositional flags-channel proof: a preceding TST establishes exactly
    the predicate that CSEL needs. This does not certify standalone CSEL. -/
theorem tst_csel_arm_correct (m : ARMRegMap) (dst yes no cond : BPF.Reg)
    (s : ARM64.State) :
    observeArm m (ARM64.mexec (tstArm (m.map cond) ++ cselArm m dst yes no) s) =
      cselSpec dst yes no cond (observeArm m s) := by
  simp only [tstArm, cselArm, List.singleton_append, ARM64.mexec_cons,
    ARM64.mexec_nil, ARM64.MInsn.step]
  rw [arm_observe_set]
  by_cases h : s.armGet (m.map cond) = 0#64 <;>
    simp_all [cselSpec, observeArm, Machine.tstFlags, Machine.State.armGet,
      ARM64.RegFile.get, m.ne_xzr]

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmov_rr, JEQ/JNE/JGE skips MOV. -/
def cmovBpf (c : X86.CC) (cmp32 value32 : Bool) (l r dst src : BPF.Reg) :
    List BPF.MInsn :=
  [.branch (match c with | .e => .ne | .ne => .eq | .b => .ge)
    (if cmp32 then .w32 else .w64) l (.reg r) 1,
   .core (if value32 then BPF.mov32 dst (.reg src) else BPF.mov64 dst (.reg src))]

/-- x86/bpf_x86_cmov.c:emit_cmp_cmov_rr_x86, CMP then CMOVcc with the
    two independent REX.W fields decoded from cmp32/value32. -/
def cmovX86 (m : X86RegMap) (c : X86.CC) (cmp32 value32 : Bool)
    (l r dst src : BPF.Reg) : List X86.MInsn :=
  [.cmp cmp32 (m.map l) (m.map r), .cmov c value32 (m.map dst) (m.map src)]

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmov_rr: comparison predicate. -/
def cmpVal {w : Nat} (c : X86.CC) (a b : BitVec w) : Bool :=
  match c with
  | .e => a == b
  | .ne => !(a == b)
  | .b => decide (a.toNat < b.toNat)

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmov_rr: comparison-width selection. -/
def cmpPredicate (c : X86.CC) (w : Bool) (a b : BitVec 64) : Bool :=
  if w then cmpVal c (BitVec.setWidth 32 a) (BitVec.setWidth 32 b)
  else cmpVal c a b

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmov_rr: 64-bit destination specification. -/
def cmovSpec (c : X86.CC) (w : Bool) (l r dst src : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set dst (if cmpPredicate c w (s.regs l) (s.regs r) then s.regs src else s.regs dst) }

theorem cmp_flags_condition (c : X86.CC) (w : Bool) (l r : X86.GPReg) (s : X86.State) :
    c.test ((X86.MInsn.cmp w l r).step s).flags = cmpPredicate c w (s.regs l) (s.regs r) := by
  cases c <;> cases w <;>
    simp [X86.CC.test, X86.MInsn.step, Machine.subFlags, cmpPredicate, cmpVal,
      BitVec.sub_eq_iff_eq_add, BitVec.toNat_setWidth]
  all_goals apply Bool.eq_iff_iff.mpr <;> simp <;> omega

theorem cmov_bpf_correct64 (c : X86.CC) (w : Bool) (l r dst src : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (cmovBpf c w false l r dst src) s) =
      cmovSpec c w l r dst src (observeBpf s) := by
  cases c <;> cases w <;>
    simp [cmovBpf, cmovSpec, cmpPredicate, cmpVal, BPF.mexec, BPF.MInsn.step,
      BPF.Cond.test, BPF.Cond.eval, BPF.mov64, BPF.Insn.step, BPF.AluOp.eval, observeBpf]
  all_goals split <;> simp_all [BPF.RegFile.set]
  all_goals funext q; by_cases h : q = dst <;> simp [BPF.RegFile.set, h]
  all_goals intro hi; omega

theorem cmov_x86_correct64 (m : X86RegMap) (c : X86.CC) (w : Bool)
    (l r dst src : BPF.Reg) (s : X86.State) :
    observeX86 m (X86.mexec (cmovX86 m c w false l r dst src) s) =
      cmovSpec c w l r dst src (observeX86 m s) := by
  change observeX86 m (((X86.MInsn.cmp w (m.map l) (m.map r)).step s).set
    (m.map dst) (if c.test ((X86.MInsn.cmp w (m.map l) (m.map r)).step s).flags
      then s.regs (m.map src) else s.regs (m.map dst))) = _
  rw [x86_observe_set, cmp_flags_condition]
  rfl

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmov_rr/emit_cmp_cmov_rr_x86,
    restricted to the genuinely equivalent 64-bit destination form. -/
def cmov64Cert (m : X86RegMap) (c : X86.CC) (w : Bool) (l r dst src : BPF.Reg) :
    X86StateEquiv m where
  spec := cmovSpec c w l r dst src
  bpf := cmovBpf c w false l r dst src
  native := cmovX86 m c w false l r dst src
  writeSet := [dst]
  bpfCorrect := cmov_bpf_correct64 c w l r dst src
  nativeCorrect := cmov_x86_correct64 m c w l r dst src
  bpfWrites := by simp [cmovBpf, BPF.mwrites, BPF.MInsn.writes, BPF.mov64, BPF.Insn.dstReg]
  nativeWrites := by simp [cmovX86, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- arm64/bpf_arm64_csel.c:instantiate_tst/instantiate_csel_ne and
    emit_tst_arm64/emit_csel_ne_arm64. Certifies the explicit two-op composition. -/
def tstCselCert (m : ARMRegMap) (dst yes no cond : BPF.Reg) : ArmStateEquiv m where
  spec := cselSpec dst yes no cond
  bpf := flagBpf ++ cselBpf dst yes no cond
  native := tstArm (m.map cond) ++ cselArm m dst yes no
  writeSet := [dst]
  bpfCorrect := by intro s; simpa [flagBpf, BPF.mexec] using csel_bpf_correct dst yes no cond s
  nativeCorrect := tst_csel_arm_correct m dst yes no cond
  bpfWrites := by simp [flagBpf, cselBpf, BPF.mwrites, BPF.MInsn.writes,
    BPF.mov64, BPF.Insn.dstReg]
  nativeWrites := by simp [tstArm, cselArm, ARM64.mwrites, ARM64.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleFlags
