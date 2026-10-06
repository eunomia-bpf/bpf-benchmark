import KinsnLean4.Kinsn.Defs
import KinsnLean4.BPF.Machine
import KinsnLean4.ARM64.Machine
import KinsnLean4.X86.Machine

namespace Kinsn

/-- The architectural BPF observation, including every memory byte and access.
    Flags are observed separately by the flags-channel theorems. -/
structure Outcome where
  regs : BPF.RegFile
  mem : Machine.Memory
  trace : List Machine.Access

def observeBpf (s : BPF.State) : Outcome := ⟨s.regs, s.mem, s.trace⟩
def observeArm (m : ARMRegMap) (s : ARM64.State) : Outcome :=
  ⟨fun r => s.armGet (m.map r), s.mem, s.trace⟩
def observeX86 (m : X86RegMap) (s : X86.State) : Outcome :=
  ⟨fun r => s.regs (m.map r), s.mem, s.trace⟩

theorem arm_observe_set (m : ARMRegMap) (s : ARM64.State) (d : BPF.Reg) (v : BitVec 64) :
    observeArm m (s.set (m.map d) v) =
      { observeArm m s with regs := (observeArm m s).regs.set d v } := by
  simp only [observeArm, Machine.State.set]
  congr 1
  funext r
  by_cases h : r = d
  · subst r; simp [Machine.State.armGet, ARM64.RegFile.get, BPF.RegFile.set, m.ne_xzr]
  · simp [Machine.State.armGet, ARM64.RegFile.get, m.ne_xzr,
      m.inj.eq_iff, BPF.RegFile.set, h]

theorem x86_observe_set (m : X86RegMap) (s : X86.State) (d : BPF.Reg) (v : BitVec 64) :
    observeX86 m (s.set (m.map d) v) =
      { observeX86 m s with regs := (observeX86 m s).regs.set d v } := by
  simp only [observeX86, Machine.State.set]
  congr 1
  funext r
  simp [observeX86, Machine.State.set, BPF.RegFile.set, m.inj.eq_iff]

/-- Spec-mediated certification for stateful module operations with no exposed
    scratch registers. It supplements, rather than replaces, `KinsnEquiv`. -/
structure ArmStateEquiv (m : ARMRegMap) where
  spec : Outcome → Outcome
  bpf : List BPF.MInsn
  native : List ARM64.MInsn
  writeSet : List BPF.Reg
  bpfCorrect : ∀ s, observeBpf (BPF.mexec bpf s) = spec (observeBpf s)
  nativeCorrect : ∀ s, observeArm m (ARM64.mexec native s) = spec (observeArm m s)
  bpfWrites : ∀ r, r ∈ BPF.mwrites bpf → r ∈ writeSet
  nativeWrites : ∀ r, m.map r ∈ ARM64.mwrites native → r ∈ writeSet

structure X86StateEquiv (m : X86RegMap) where
  spec : Outcome → Outcome
  bpf : List BPF.MInsn
  native : List X86.MInsn
  writeSet : List BPF.Reg
  bpfCorrect : ∀ s, observeBpf (BPF.mexec bpf s) = spec (observeBpf s)
  nativeCorrect : ∀ s, observeX86 m (X86.mexec native s) = spec (observeX86 m s)
  bpfWrites : ∀ r, r ∈ BPF.mwrites bpf → r ∈ writeSet
  nativeWrites : ∀ r, m.map r ∈ X86.mwrites native → r ∈ writeSet

theorem ArmStateEquiv.arm_refines {m : ARMRegMap} (k : ArmStateEquiv m)
    (b : BPF.State) (a : ARM64.State)
    (h : observeBpf b = observeArm m a) :
    observeBpf (BPF.mexec k.bpf b) = observeArm m (ARM64.mexec k.native a) := by
  rw [k.bpfCorrect, k.nativeCorrect, h]

theorem X86StateEquiv.x86_refines {m : X86RegMap} (k : X86StateEquiv m)
    (b : BPF.State) (a : X86.State)
    (h : observeBpf b = observeX86 m a) :
    observeBpf (BPF.mexec k.bpf b) = observeX86 m (X86.mexec k.native a) := by
  rw [k.bpfCorrect, k.nativeCorrect, h]

theorem ArmStateEquiv.bpf_frame {m : ARMRegMap} (k : ArmStateEquiv m)
    (s : BPF.State) (r : BPF.Reg) (h : r ∉ k.writeSet) :
    (BPF.mexec k.bpf s).regs r = s.regs r :=
  BPF.mexec_frame _ _ _ (fun hr => h (k.bpfWrites _ hr))

theorem ArmStateEquiv.native_frame {m : ARMRegMap} (k : ArmStateEquiv m)
    (s : ARM64.State) (r : BPF.Reg) (h : r ∉ k.writeSet) :
    (ARM64.mexec k.native s).armGet (m.map r) = s.armGet (m.map r) :=
  ARM64.mexec_frame _ _ _ (fun hr => h (k.nativeWrites _ hr))

theorem X86StateEquiv.bpf_frame {m : X86RegMap} (k : X86StateEquiv m)
    (s : BPF.State) (r : BPF.Reg) (h : r ∉ k.writeSet) :
    (BPF.mexec k.bpf s).regs r = s.regs r :=
  BPF.mexec_frame _ _ _ (fun hr => h (k.bpfWrites _ hr))

theorem X86StateEquiv.native_frame {m : X86RegMap} (k : X86StateEquiv m)
    (s : X86.State) (r : BPF.Reg) (h : r ∉ k.writeSet) :
    (X86.mexec k.native s).regs (m.map r) = s.regs (m.map r) :=
  X86.mexec_frame _ _ _ (fun hr => h (k.nativeWrites _ hr))

/-- The scratch-register extension of the same spec/frame argument. -/
theorem arm_refines_of_results (m : ARMRegMap) (p : List BPF.MInsn)
    (q : List ARM64.MInsn) (dst : BPF.Reg) (scratch : List BPF.Reg)
    (b : BPF.State) (a : ARM64.State)
    (hinit : observeBpf b = observeArm m a)
    (hresult : (BPF.mexec p b).regs dst = (ARM64.mexec q a).armGet (m.map dst))
    (hb : ∀ r, r ∈ BPF.mwrites p → r = dst ∨ r ∈ scratch)
    (ha : ∀ r, m.map r ∈ ARM64.mwrites q → r = dst ∨ r ∈ scratch)
    (hm : (BPF.mexec p b).mem = (ARM64.mexec q a).mem)
    (ht : (BPF.mexec p b).trace = (ARM64.mexec q a).trace) :
    Machine.Sim m.map Machine.State.armGet scratch (BPF.mexec p b) (ARM64.mexec q a) := by
  refine ⟨?_, hm, ht⟩
  intro r hr
  by_cases hd : r = dst
  · subst r; exact hresult
  · rw [BPF.mexec_frame _ _ _ (fun h => (hb r h).elim hd hr),
      ARM64.mexec_frame _ _ _ (fun h => (ha r h).elim hd hr)]
    exact congrFun (congrArg Outcome.regs hinit) r

theorem x86_refines_of_results (m : X86RegMap) (p : List BPF.MInsn)
    (q : List X86.MInsn) (dst : BPF.Reg) (scratch : List BPF.Reg)
    (b : BPF.State) (a : X86.State)
    (hinit : observeBpf b = observeX86 m a)
    (hresult : (BPF.mexec p b).regs dst = (X86.mexec q a).regs (m.map dst))
    (hb : ∀ r, r ∈ BPF.mwrites p → r = dst ∨ r ∈ scratch)
    (ha : ∀ r, m.map r ∈ X86.mwrites q → r = dst ∨ r ∈ scratch)
    (hm : (BPF.mexec p b).mem = (X86.mexec q a).mem)
    (ht : (BPF.mexec p b).trace = (X86.mexec q a).trace) :
    Machine.Sim m.map (fun s => s.regs) scratch (BPF.mexec p b) (X86.mexec q a) := by
  refine ⟨?_, hm, ht⟩
  intro r hr
  change (BPF.mexec p b).regs r = (X86.mexec q a).regs (m.map r)
  by_cases hd : r = dst
  · subst r; exact hresult
  · rw [BPF.mexec_frame _ _ _ (fun h => (hb r h).elim hd hr),
      X86.mexec_frame _ _ _ (fun h => (ha r h).elim hd hr)]
    exact congrFun (congrArg Outcome.regs hinit) r

end Kinsn
