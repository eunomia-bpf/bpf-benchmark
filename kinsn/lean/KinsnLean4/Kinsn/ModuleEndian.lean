import KinsnLean4.Kinsn.ModuleMemory
import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleEndian

/-- x86/bpf_x86_movbe.c:instantiate_movbe_indexed; arm64/bpf_arm64_rev.c:instantiate_rev: byte-order specification. -/
def swap (w32 : Bool) : BitVec 64 → BitVec 64 :=
  BPF.Insn.evalBswap (if w32 then .b32 else .b64)

/-- x86/bpf_x86_movbe.c:instantiate_movbe_indexed/emit_movbe_indexed_x86: direct big-endian load specification. -/
def spec (w32 : Bool) (dst base : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  ModuleRegister.unarySpec dst dst (swap w32)
    (ModuleMemory.loadSpec (if w32 then 4 else 8) dst base off s)

/-- x86/bpf_x86_movbe.c:instantiate_movbe_indexed, direct BPF_W/BPF_DW
    path: LDX_MEM then BPF_BSWAP. ARM64 big endian form is the corresponding
    bpf_arm64_ldr.c:instantiate_ldr followed by bpf_arm64_rev.c:instantiate_rev. -/
def bpf (w32 : Bool) (dst base : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  [.load (if w32 then 4 else 8) dst base off,
   .core (.bswap (if w32 then .b32 else .b64) dst)]

/-- arm64/bpf_arm64_ldr.c:emit_ldr_arm64 followed by
    arm64/bpf_arm64_rev.c:emit_rev_arm64, W or X form. -/
def arm (m : ARMRegMap) (w32 : Bool) (dst base : BPF.Reg) (off : BitVec 64) :
    List ARM64.MInsn :=
  [.load (if w32 then 4 else 8) (m.map dst) (m.map base) off,
   .core (if w32 then .rev32w (m.map dst) (m.map dst) else .rev64 (m.map dst) (m.map dst))]

/-- x86/bpf_x86_movbe.c:emit_movbe_indexed_x86, direct MOVBE r32/r64,[base+off]. -/
def x86 (m : X86RegMap) (w32 : Bool) (dst base : BPF.Reg) (off : BitVec 64) :
    List X86.MInsn := [.load (if w32 then 4 else 8) (m.map dst) (m.map base) off true]

theorem bpf_correct (w32 : Bool) (dst base : BPF.Reg) (off : BitVec 64) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf w32 dst base off) s) = spec w32 dst base off (observeBpf s) := by
  cases w32 <;> simp [bpf, spec, swap, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
    ModuleMemory.loadSpec, ModuleRegister.unarySpec, observeBpf,
    Machine.State.read, Machine.State.set, BPF.RegFile.set]
  all_goals rfl

theorem arm_correct (m : ARMRegMap) (w32 : Bool) (dst base : BPF.Reg)
    (off : BitVec 64) (s : ARM64.State) :
    observeArm m (ARM64.mexec (arm m w32 dst base off) s) =
      spec w32 dst base off (observeArm m s) := by
  have h := (ModuleRegister.revCert m w32 dst).nativeCorrect
    ((ARM64.MInsn.load (if w32 then 4 else 8) (m.map dst) (m.map base) off).step s)
  change observeArm m (ARM64.mexec (arm m w32 dst base off) s) =
    ModuleRegister.unarySpec dst dst (swap w32)
      (ModuleMemory.loadSpec (if w32 then 4 else 8) dst base off (observeArm m s))
  rw [← ModuleMemory.load_arm_correct m (if w32 then 4 else 8) dst base off s]
  exact h

/-- arm64/bpf_arm64_ldr.c:instantiate_ldr/emit_ldr_arm64 composed with bpf_arm64_rev.c:instantiate_rev/emit_rev_arm64. -/
def armCert (m : ARMRegMap) (w32 : Bool) (dst base : BPF.Reg) (off : BitVec 64) :
    ArmStateEquiv m where
  spec := spec w32 dst base off
  bpf := bpf w32 dst base off
  native := arm m w32 dst base off
  writeSet := [dst]
  bpfCorrect := bpf_correct w32 dst base off
  nativeCorrect := arm_correct m w32 dst base off
  bpfWrites := by cases w32 <;> simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by
    cases w32 <;> simp [arm, ARM64.mwrites, ARM64.MInsn.writes,
      ARM64.Insn.dstReg, m.inj.eq_iff]

theorem x86_correct (m : X86RegMap) (w32 : Bool) (dst base : BPF.Reg)
    (off : BitVec 64) (s : X86.State) :
    observeX86 m (X86.mexec (x86 m w32 dst base off) s) =
      spec w32 dst base off (observeX86 m s) := by
  simp only [x86, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  rw [x86_observe_set]
  cases w32 <;>
    simp [spec, swap, ModuleRegister.unarySpec, ModuleMemory.loadSpec,
      X86.writeWidth, X86.reverseLoad, BPF.Insn.evalBswap, observeX86,
      Machine.State.read, BPF.RegFile.set, BPF.RegFile.set_set_same]

/-- x86/bpf_x86_movbe.c:instantiate_movbe_indexed/emit_movbe_indexed_x86, direct 32/64-bit path. -/
def x86Cert (m : X86RegMap) (w32 : Bool) (dst base : BPF.Reg) (off : BitVec 64) :
    X86StateEquiv m where
  spec := spec w32 dst base off
  bpf := bpf w32 dst base off
  native := x86 m w32 dst base off
  writeSet := [dst]
  bpfCorrect := bpf_correct w32 dst base off
  nativeCorrect := x86_correct m w32 dst base off
  bpfWrites := by cases w32 <;> simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by
    cases w32 <;> simp [x86, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleEndian
