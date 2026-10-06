import KinsnLean4.Kinsn.ModuleMovbeWide

namespace Kinsn.ModuleMovbe16

/-- x86/bpf_x86_movbe.c:instantiate_movbe_wide/instantiate_movbe16_indexed:
    live address formation, one LDX_H, and zero-extending BSWAP16. -/
def bpf (indexed : Bool) (d b i : BPF.Reg) (scale : Nat) (off : BitVec 64) :
    List BPF.MInsn :=
  (if indexed then (ModuleMovbeWide.address d b i scale).map BPF.MInsn.core else []) ++
    [.load 2 d (if indexed then d else b) off, .core (.bswap .b16 d)]

/-- x86/bpf_x86_movbe.c:emit_movbe_indexed_x86: MOVBE dst16,[address]
    followed by MOVZX dst32,dst16. No additional memory access. -/
def native (m : X86RegMap) (indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) : List X86.MInsn :=
  [if indexed then .loadIndex 2 (m.map d) (m.map b) (m.map i) scale off true
   else .load 2 (m.map d) (m.map b) off true, .movzx 16 (m.map d) (m.map d)]

def spec (indexed : Bool) (d b i : BPF.Reg) (scale : Nat) (off : BitVec 64)
    (s : Outcome) : Outcome :=
  let a := s.regs b + (if indexed then s.regs i <<< scale else 0) + off
  let v := Machine.loadLE s.mem a 2
  { regs := s.regs.set d (BPF.Insn.evalBswap .b16 v), mem := s.mem,
    trace := s.trace ++ [.read a 2 v] }

theorem narrow_value (old v : BitVec 64) :
    BitVec.setWidth 64 (BitVec.setWidth 16
      (X86.writeWidth 16 old (X86.reverseLoad 2 v))) = BPF.Insn.evalBswap .b16 v := by
  apply BitVec.eq_of_getLsbD_eq
  intro j hj
  interval_cases j <;>
    simp [X86.writeWidth, X86.reverseLoad, BPF.Insn.evalBswap, Bits.bswap16]

theorem bpf_correct (indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (hs : scale ≤ 3) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf indexed d b i scale off) s) =
      spec indexed d b i scale off (observeBpf s) := by
  cases indexed
  · simp [bpf, spec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, observeBpf,
      Machine.State.read, Machine.State.set]
    funext q; by_cases h : q = d <;> simp [BPF.RegFile.set, h]
  · simp only [bpf, ↓reduceIte, ModuleDispatch.exec_core_tail]
    rw [ModuleMovbeWide.address_exec d b i scale hs]
    simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, spec, observeBpf,
      Machine.State.read, Machine.State.set]
    funext q; by_cases h : q = d <;> simp [BPF.RegFile.set, h]

theorem native_correct (m : X86RegMap) (indexed : Bool) (d b i : BPF.Reg)
    (scale : Nat) (off : BitVec 64) (s : X86.State) :
    observeX86 m (X86.mexec (native m indexed d b i scale off) s) =
      spec indexed d b i scale off (observeX86 m s) := by
  cases indexed <;>
    simp only [native, Bool.false_eq_true, ↓reduceIte,
      X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  all_goals rw [Machine.set_same, narrow_value, x86_observe_set, x86_observe_set]
  all_goals simp [spec, observeX86, Machine.State.read]
  all_goals funext q; by_cases h : q = d <;> simp [BPF.RegFile.set, h]

def bpf_x86_movbe16 (m : X86RegMap) (indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (hs : scale ≤ 3) : X86StateEquiv m where
  spec := spec indexed d b i scale off
  bpf := bpf indexed d b i scale off
  native := native m indexed d b i scale off
  writeSet := [d]
  bpfCorrect := bpf_correct indexed d b i scale off hs
  nativeCorrect := native_correct m indexed d b i scale off
  bpfWrites := by
    intro t ht
    cases indexed <;>
      simp only [bpf, ↓reduceIte, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
        List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg, List.mem_append,
        List.mem_cons, List.mem_nil_iff, or_false] at ht
    · simpa using ht
    · rcases ht with ht | ht
      · exact List.mem_singleton.mpr (ModuleMovbeWide.address_writes d b i t scale
          (by simpa [BPF.writes, List.mem_flatMap, BPF.MInsn.writes, eq_comm] using ht))
      · simpa using ht
  nativeWrites := by
    cases indexed <;> simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleMovbe16
