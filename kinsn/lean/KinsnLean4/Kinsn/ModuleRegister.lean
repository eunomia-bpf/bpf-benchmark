import KinsnLean4.Kinsn.StateEquiv
import KinsnLean4.Kinsn.Extract

namespace Kinsn.ModuleRegister

theorem bpf_core_exec (p : List BPF.Insn) (s : BPF.State) :
    BPF.mexec (p.map BPF.MInsn.core) s = { s with regs := BPF.exec p s.regs } := by
  induction p generalizing s with
  | nil => simp [BPF.mexec]
  | cons i p ih => simp [BPF.mexec, BPF.MInsn.step, ih]

theorem arm_core_exec (p : List ARM64.Insn) (s : ARM64.State) :
    ARM64.mexec (p.map ARM64.MInsn.core) s = { s with regs := ARM64.exec p s.regs } := by
  induction p generalizing s with
  | nil => rfl
  | cons i p ih => simpa [ARM64.MInsn.step] using ih ((ARM64.MInsn.core i).step s)

def unarySpec (dst src : BPF.Reg) (f : BitVec 64 → BitVec 64) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set dst (f (s.regs src)) }

/-- Lift a register-only, single-destination proof into the full memory-aware
    catalogue. Source independence and frame bounds come from the supplied
    instruction proofs, not an assumed equality of the instruction streams. -/
def armCoreCert (m : ARMRegMap) (dst src : BPF.Reg) (f : BitVec 64 → BitVec 64)
    (bp : List BPF.Insn) (ap : List ARM64.Insn)
    (bc : ∀ rf, BPF.exec bp rf dst = f (rf src))
    (ac : ∀ rf, (ARM64.exec ap rf).get (m.map dst) = f (rf.get (m.map src)))
    (bw : ∀ r, r ∈ BPF.writes bp → r = dst)
    (aw : ∀ r, r ∈ ARM64.writes ap → r = m.map dst) : ArmStateEquiv m where
  spec := unarySpec dst src f
  bpf := bp.map BPF.MInsn.core
  native := ap.map ARM64.MInsn.core
  writeSet := [dst]
  bpfCorrect := by
    intro s
    rw [bpf_core_exec]
    simp only [observeBpf, unarySpec]
    congr 1
    funext r
    by_cases h : r = dst
    · subst r; simp [bc]
    · rw [BPF.exec_of_not_mem_writes _ _ _ (fun hr => h (bw r hr))]
      exact (BPF.RegFile.set_other _ _ _ _ h).symm
  nativeCorrect := by
    intro s
    rw [arm_core_exec]
    simp only [observeArm, unarySpec]
    congr 1
    funext r
    by_cases h : r = dst
    · subst r
      simpa [Machine.State.armGet] using ac s.regs
    · change (ARM64.exec ap s.regs).get (m.map r) =
        BPF.RegFile.set (fun r => s.armGet (m.map r)) dst (f (s.armGet (m.map src))) r
      rw [ARM64.exec_of_not_mem_writes _ _ _ (fun hr => h (m.inj (aw _ hr)))]
      simpa only [Machine.State.armGet] using
        (BPF.RegFile.set_other (fun r => s.armGet (m.map r)) dst r
          (f (s.armGet (m.map src))) h).symm
  bpfWrites := by
    intro r hr
    simp only [BPF.mwrites, List.flatMap_map, BPF.MInsn.writes,
      List.flatMap_singleton] at hr
    exact List.mem_singleton.mpr (bw r (by simpa [BPF.writes, List.mem_flatMap, eq_comm] using hr))
  nativeWrites := by
    intro r hr
    simp only [ARM64.mwrites, List.flatMap_map, ARM64.MInsn.writes,
      List.flatMap_singleton] at hr
    exact List.mem_singleton.mpr (m.inj (aw _ (by simpa [ARM64.writes, List.mem_flatMap, eq_comm] using hr)))

/-- arm64/bpf_arm64_mov.c:instantiate_mov_x. -/
def movBpf (dst src : BPF.Reg) : List BPF.Insn := [BPF.mov64 dst (.reg src)]

/-- arm64/bpf_arm64_mov.c:emit_mov_x_arm64/a64_mov_x, ORR Xd,XZR,Xm. -/
def movArm (dst src : ARM64.GPReg) : List ARM64.Insn :=
  [.logicalReg .orr dst .xzr src .LSL 0]

/-- arm64/bpf_arm64_mov.c:instantiate_mov_x/emit_mov_x_arm64. -/
def movCert (m : ARMRegMap) (dst src : BPF.Reg) : ArmStateEquiv m :=
  armCoreCert m dst src id (movBpf dst src) (movArm (m.map dst) (m.map src))
    (by intro rf; simp [movBpf, BPF.mov64, BPF.AluOp.eval])
    (by intro rf; simp [movArm, ARM64.Insn.step, ARM64.LogicOp.eval, m.ne_xzr])
    (by simp [movBpf, BPF.writes, BPF.mov64, BPF.Insn.dstReg])
    (by simp [movArm, ARM64.writes, ARM64.Insn.dstReg])

/-- arm64/bpf_arm64_rev.c:instantiate_rev_w/instantiate_rev_x. -/
def revBpf (sz : BPF.EndSize) (dst : BPF.Reg) : List BPF.Insn := [.bswap sz dst]

/-- arm64/bpf_arm64_rev.c:emit_rev_w_arm64/emit_rev_x_arm64. -/
def revArm (w32 : Bool) (dst : ARM64.GPReg) : List ARM64.Insn :=
  [if w32 then .rev32w dst dst else .rev64 dst dst]

/-- arm64/bpf_arm64_rev.c:instantiate_rev_w/instantiate_rev_x/emit_rev_arm64. -/
def revCert (m : ARMRegMap) (w32 : Bool) (dst : BPF.Reg) : ArmStateEquiv m :=
  armCoreCert m dst dst (BPF.Insn.evalBswap (if w32 then .b32 else .b64))
    (revBpf (if w32 then .b32 else .b64) dst) (revArm w32 (m.map dst))
    (by intro rf; cases w32 <;> simp [revBpf, BPF.Insn.step])
    (by intro rf; cases w32 <;> simp [revArm, ARM64.Insn.step, BPF.Insn.evalBswap,
      ARM64.execREV32W, ARM64.execREV64, m.ne_xzr])
    (by cases w32 <;> simp [revBpf, BPF.writes, BPF.Insn.dstReg])
    (by cases w32 <;> simp [revArm, ARM64.writes, ARM64.Insn.dstReg])

/-- arm64/bpf_arm64_ubfm.c:instantiate_extract. For width<32, the positive
    signed immediate fits, established by Extract.mask_imm32_ok; width=32
    uses ALU32 AND -1, rather than sign-extending 0xffffffff into ALU64. -/
def extractBpf (dst : BPF.Reg) (start width : Nat) : List BPF.Insn :=
  (if start = 0 then [] else [BPF.rsh64 dst (BPF.immN start)]) ++
  [if width = 32 then .alu .and .w32 dst (.imm (BitVec.signExtend 64 (-1 : BitVec 32)))
   else BPF.and64 dst (.imm (BitVec.signExtend 64 (BitVec.setWidth 32 (Bits.lowMask 64 width))))]

/-- arm64/bpf_arm64_ubfm.c:emit_ubfm_x_arm64/a64_ubfm_x:
    immr=start, imms=start+width-1 (the non-wrapping UBFX alias). -/
def extractArm (dst : ARM64.GPReg) (start width : Nat) : List ARM64.Insn :=
  [ARM64.ubfx dst dst start width]

theorem extract_bpf_correct (dst : BPF.Reg) (start width : Nat)
    (hs : start < 64) (hw : 1 ≤ width) (hw' : width ≤ 32) (rf : BPF.RegFile) :
    BPF.exec (extractBpf dst start width) rf dst = Extract.spec start width (rf dst) := by
  by_cases he : width = 32
  · subst width
    by_cases hz : start = 0 <;>
      simp [extractBpf, Extract.spec, BPF.rsh64, BPF.AluOp.eval, BPF.immN,
        hs, Nat.mod_eq_of_lt hs, hz, Bits.and_lowMask_eq_setWidth]
    all_goals apply BitVec.eq_of_getLsbD_eq; intro i hi; interval_cases i <;> simp
  · have hm := Extract.mask_imm32_ok width (by omega)
    by_cases hz : start = 0 <;>
      simp [extractBpf, Extract.spec, BPF.rsh64, BPF.and64, BPF.AluOp.eval,
        BPF.immN, Nat.mod_eq_of_lt hs, hz, he, hm]

/-- arm64/bpf_arm64_ubfm.c:instantiate_extract/emit_ubfm_x_arm64. -/
def extractCert (m : ARMRegMap) (dst : BPF.Reg) (start width : Nat)
    (hw : 1 ≤ width) (hw' : width ≤ 32) (hsw : start + width ≤ 64) : ArmStateEquiv m :=
  armCoreCert m dst dst (Extract.spec start width) (extractBpf dst start width)
    (extractArm (m.map dst) start width)
    (extract_bpf_correct dst start width (by omega) hw hw')
    (by intro rf; exact Extract.arm_correct rf _ _ start width hw hsw (m.ne_xzr dst))
    (by
      intro r hr
      by_cases hz : start = 0 <;> by_cases he : width = 32 <;>
        simp_all [extractBpf, hz, he, BPF.writes, BPF.rsh64,
          BPF.and64, BPF.Insn.dstReg])
    (by simp [extractArm, ARM64.writes, ARM64.ubfx, ARM64.Insn.dstReg])

end Kinsn.ModuleRegister
