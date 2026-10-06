import KinsnLean4.Kinsn.StateEquiv

namespace Kinsn.ModuleMemory

/-- arm64/bpf_arm64_ldr.c:instantiate_ldr/emit_ldr_arm64: ordinary load specification. -/
def loadSpec (n : Nat) (dst base : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  let a := s.regs base + off
  { regs := s.regs.set dst (Machine.loadLE s.mem a n), mem := s.mem,
    trace := s.trace ++ [.read a n (Machine.loadLE s.mem a n)] }

/-- arm64/bpf_arm64_str.c:instantiate_store_reg/emit_store_reg_arm64: ordinary store specification. -/
def storeSpec (n : Nat) (src base : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  let a := s.regs base + off
  { regs := s.regs, mem := Machine.storeLE s.mem a n (s.regs src),
    trace := s.trace ++ [.write a n (BitVec.setWidth 64
      (BitVec.setWidth (n * 8) (s.regs src)))] }

/-- arm64/bpf_arm64_ldr.c:instantiate_ldr and emit_ldr_arm64 (LDUR or
    scaled LDR, no writeback). `off` is the sign-extended decoded s16. -/
def loadBpf (n : Nat) (dst base : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  [.load n dst base off]

/-- arm64/bpf_arm64_ldr.c:emit_ldr_arm64, a64_ldrb/a64_ldrh/a64_ldr_w/a64_ldr_x. -/
def loadArm (m : ARMRegMap) (n : Nat) (dst base : BPF.Reg) (off : BitVec 64) :
    List ARM64.MInsn := [.load n (m.map dst) (m.map base) off]

theorem load_bpf_correct (n : Nat) (dst base : BPF.Reg) (off : BitVec 64) (s : BPF.State) :
    observeBpf (BPF.mexec (loadBpf n dst base off) s) = loadSpec n dst base off (observeBpf s) := by
  simp [loadBpf, BPF.mexec, BPF.MInsn.step, loadSpec, observeBpf,
    Machine.State.set, Machine.State.read, BPF.RegFile.set]
  rfl

theorem load_arm_correct (m : ARMRegMap) (n : Nat) (dst base : BPF.Reg)
    (off : BitVec 64) (s : ARM64.State) :
    observeArm m (ARM64.mexec (loadArm m n dst base off) s) =
      loadSpec n dst base off (observeArm m s) := by
  simp only [loadArm, ARM64.mexec_cons, ARM64.mexec_nil, ARM64.MInsn.step]
  rw [arm_observe_set]
  rfl

/-- arm64/bpf_arm64_ldr.c:instantiate_ldr/emit_ldr_arm64. -/
def loadCert (m : ARMRegMap) (n : Nat) (dst base : BPF.Reg) (off : BitVec 64) :
    ArmStateEquiv m where
  spec := loadSpec n dst base off
  bpf := loadBpf n dst base off
  native := loadArm m n dst base off
  writeSet := [dst]
  bpfCorrect := load_bpf_correct n dst base off
  nativeCorrect := load_arm_correct m n dst base off
  bpfWrites := by simp [loadBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [loadArm, ARM64.mwrites, ARM64.MInsn.writes, m.inj.eq_iff]

/-- arm64/bpf_arm64_str.c:instantiate_store_reg/emit_store_reg_arm64;
    x86/bpf_x86_mov.c:instantiate_store_reg/emit_store_reg_x86, ordinary
    non-arch-base, low-byte-lane form without helper spills. -/
def storeBpf (n : Nat) (src base : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  [.store n base (.reg src) off]

/-- arm64/bpf_arm64_str.c:emit_store_reg_arm64; STR/STUR, no writeback. -/
def storeArm (m : ARMRegMap) (n : Nat) (src base : BPF.Reg) (off : BitVec 64) :
    List ARM64.MInsn := [.store n (m.map src) (m.map base) off]

theorem store_bpf_correct (n : Nat) (src base : BPF.Reg) (off : BitVec 64) (s : BPF.State) :
    observeBpf (BPF.mexec (storeBpf n src base off) s) =
      storeSpec n src base off (observeBpf s) := by
  simp [storeBpf, BPF.mexec, BPF.MInsn.step, storeSpec, observeBpf, Machine.State.write]

theorem store_arm_correct (m : ARMRegMap) (n : Nat) (src base : BPF.Reg)
    (off : BitVec 64) (s : ARM64.State) :
    observeArm m (ARM64.mexec (storeArm m n src base off) s) =
      storeSpec n src base off (observeArm m s) := rfl

/-- arm64/bpf_arm64_str.c:instantiate_store_reg/emit_store_reg_arm64. -/
def storeCert (m : ARMRegMap) (n : Nat) (src base : BPF.Reg) (off : BitVec 64) :
    ArmStateEquiv m where
  spec := storeSpec n src base off
  bpf := storeBpf n src base off
  native := storeArm m n src base off
  writeSet := []
  bpfCorrect := store_bpf_correct n src base off
  nativeCorrect := store_arm_correct m n src base off
  bpfWrites := by simp [storeBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [storeArm, ARM64.mwrites, ARM64.MInsn.writes]

/-- arm64/bpf_arm64_str.c:instantiate_strb_zero_mem / emit_strb_fixed_arm64. -/
def zeroBpf (base : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  [.store 1 base (.imm 0) off]

/-- arm64/bpf_arm64_str.c:emit_strb_fixed_arm64, Rt = WZR. -/
def zeroArm (m : ARMRegMap) (base : BPF.Reg) (off : BitVec 64) : List ARM64.MInsn :=
  [.store 1 .xzr (m.map base) off]

/-- arm64/bpf_arm64_str.c:instantiate_strb_zero_mem/emit_strb_fixed_arm64. -/
def zeroSpec (base : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  { s with
    mem := Machine.storeLE s.mem (s.regs base + off) 1 0
    trace := s.trace ++ [.write (s.regs base + off) 1 0] }

/-- arm64/bpf_arm64_str.c:instantiate_strb_zero_mem/emit_strb_fixed_arm64. -/
def zeroCert (m : ARMRegMap) (base : BPF.Reg) (off : BitVec 64) : ArmStateEquiv m where
  spec := zeroSpec base off
  bpf := zeroBpf base off
  native := zeroArm m base off
  writeSet := []
  bpfCorrect := by
    intro s
    simp [zeroBpf, BPF.mexec, BPF.MInsn.step, zeroSpec, observeBpf, Machine.State.write]
  nativeCorrect := by
    intro s
    simp [zeroArm, zeroSpec, observeArm, ARM64.MInsn.step, Machine.State.write,
      Machine.State.armGet, ARM64.RegFile.get]
  bpfWrites := by simp [zeroBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [zeroArm, ARM64.mwrites, ARM64.MInsn.writes]

/-- arm64/bpf_arm64_ldp.c:instantiate_ldp/emit_ldp_arm64: ordered pair-load specification. -/
def pairLoadSpec (lo hi base : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  let a := s.regs base + off
  { regs := BPF.RegFile.set (BPF.RegFile.set s.regs lo (Machine.loadLE s.mem a 8)) hi (Machine.loadLE s.mem (a + 8) 8),
    mem := s.mem,
    trace := (s.trace ++ [.read a 8 (Machine.loadLE s.mem a 8)]) ++
      [.read (a + 8) 8 (Machine.loadLE s.mem (a + 8) 8)] }

/-- arm64/bpf_arm64_ldp.c:instantiate_ldp. Decoder rejects base=lo/base=hi
    and lo=hi, and restricts signed byte offset to [-512,504], a multiple of 8. -/
def pairLoadBpf (lo hi base : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  [.load 8 lo base off, .load 8 hi base (off + 8)]

/-- arm64/bpf_arm64_ldp.c:emit_ldp_arm64 / a64_ldp_x (offset, no writeback). -/
def pairLoadArm (m : ARMRegMap) (lo hi base : BPF.Reg) (off : BitVec 64) :
    List ARM64.MInsn := [.ldp (m.map lo) (m.map hi) (m.map base) off]

theorem pair_load_bpf_correct (lo hi base : BPF.Reg) (off : BitVec 64)
    (h : base ≠ lo) (s : BPF.State) :
    observeBpf (BPF.mexec (pairLoadBpf lo hi base off) s) =
      pairLoadSpec lo hi base off (observeBpf s) := by
  simp [pairLoadBpf, pairLoadSpec, BPF.mexec, BPF.MInsn.step, observeBpf,
    Machine.State.set, Machine.State.read, BPF.RegFile.set, h, BitVec.add_assoc]
  rfl

theorem pair_load_arm_correct (m : ARMRegMap) (lo hi base : BPF.Reg)
    (off : BitVec 64) (s : ARM64.State) :
    observeArm m (ARM64.mexec (pairLoadArm m lo hi base off) s) =
      pairLoadSpec lo hi base off (observeArm m s) := by
  simp only [pairLoadArm, ARM64.mexec_cons, ARM64.mexec_nil, ARM64.MInsn.step]
  rw [arm_observe_set, arm_observe_set]
  rfl

/-- arm64/bpf_arm64_ldp.c:instantiate_ldp/emit_ldp_arm64. -/
def pairLoadCert (m : ARMRegMap) (lo hi base : BPF.Reg) (off : BitVec 64)
    (h : base ≠ lo) : ArmStateEquiv m where
  spec := pairLoadSpec lo hi base off
  bpf := pairLoadBpf lo hi base off
  native := pairLoadArm m lo hi base off
  writeSet := [lo, hi]
  bpfCorrect := pair_load_bpf_correct lo hi base off h
  nativeCorrect := pair_load_arm_correct m lo hi base off
  bpfWrites := by simp [pairLoadBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [pairLoadArm, ARM64.mwrites, ARM64.MInsn.writes, m.inj.eq_iff]

/-- arm64/bpf_arm64_ldp.c:instantiate_stp/emit_stp_arm64: ordered pair-store specification. -/
def pairStoreSpec (lo hi base : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  storeSpec 8 hi base (off + 8) (storeSpec 8 lo base off s)

/-- arm64/bpf_arm64_ldp.c:instantiate_stp. -/
def pairStoreBpf (lo hi base : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  [.store 8 base (.reg lo) off, .store 8 base (.reg hi) (off + 8)]

/-- arm64/bpf_arm64_ldp.c:emit_stp_arm64 / a64_stp_x, first low then high lane. -/
def pairStoreArm (m : ARMRegMap) (lo hi base : BPF.Reg) (off : BitVec 64) :
    List ARM64.MInsn := [.stp (m.map lo) (m.map hi) (m.map base) off]

/-- arm64/bpf_arm64_ldp.c:instantiate_stp/emit_stp_arm64. -/
def pairStoreCert (m : ARMRegMap) (lo hi base : BPF.Reg) (off : BitVec 64) :
    ArmStateEquiv m where
  spec := pairStoreSpec lo hi base off
  bpf := pairStoreBpf lo hi base off
  native := pairStoreArm m lo hi base off
  writeSet := []
  bpfCorrect := by
    intro s
    simp [pairStoreBpf, pairStoreSpec, storeSpec, BPF.mexec, BPF.MInsn.step,
      observeBpf, Machine.State.write]
  nativeCorrect := by
    intro s
    simp [pairStoreArm, pairStoreSpec, storeSpec, observeArm, ARM64.MInsn.step,
      Machine.State.write, Machine.State.armGet, BitVec.add_assoc]
  bpfWrites := by simp [pairStoreBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [pairStoreArm, ARM64.mwrites, ARM64.MInsn.writes]

/-- x86/bpf_x86_mov.c:emit_store_reg_x86, low-byte-lane ordinary store. -/
def storeX86 (m : X86RegMap) (n : Nat) (src base : BPF.Reg) (off : BitVec 64) :
    List X86.MInsn := [.store n (m.map src) (m.map base) off]

/-- x86/bpf_x86_mov.c:instantiate_store_reg/emit_store_reg_x86, ordinary no-helper path. -/
def storeX86Cert (m : X86RegMap) (n : Nat) (src base : BPF.Reg) (off : BitVec 64) :
    X86StateEquiv m where
  spec := storeSpec n src base off
  bpf := storeBpf n src base off
  native := storeX86 m n src base off
  writeSet := []
  bpfCorrect := store_bpf_correct n src base off
  nativeCorrect := by intro s; rfl
  bpfWrites := by simp [storeBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [storeX86, X86.mwrites, X86.MInsn.writes]

/-- x86/bpf_x86_mov.c:instantiate_mov_mem, direct non-arch-base path. -/
def loadX86 (m : X86RegMap) (n : Nat) (dst base : BPF.Reg) (off : BitVec 64) :
    List X86.MInsn := [.load n (m.map dst) (m.map base) off]

/-- x86/bpf_x86_mov.c:instantiate_mov_mem/emit_mov_mem_x86, ordinary no-helper path. -/
def loadX86Cert (m : X86RegMap) (n : Nat) (dst base : BPF.Reg) (off : BitVec 64) :
    X86StateEquiv m where
  spec := loadSpec n dst base off
  bpf := loadBpf n dst base off
  native := loadX86 m n dst base off
  writeSet := [dst]
  bpfCorrect := load_bpf_correct n dst base off
  nativeCorrect := by
    intro s
    simp only [loadX86, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
    rw [x86_observe_set]
    rfl
  bpfWrites := by simp [loadBpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by simp [loadX86, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleMemory
