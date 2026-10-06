import KinsnLean4.Kinsn.ModuleByteAlu
namespace Kinsn.ModulePopcnt

def ones : Nat → BitVec 64 → Nat
  | 0, _ => 0
  | n+1, v => ones n (v >>> 1) + if v.getLsbD 0 then 1 else 0

def zeros : Nat → BitVec 64 → Nat
  | 0, _ => 0
  | n+1, v => zeros n (v >>> 1) + if v.getLsbD 0 then 0 else 1

theorem partition (n : Nat) (v : BitVec 64) : ones n v + zeros n v = n := by
  induction n generalizing v with
  | zero => rfl
  | succ n ih =>
    have h := ih (v >>> 1)
    cases he : v.getLsbD 0 <;>
      simp only [ones, zeros, he, Bool.false_eq_true, ↓reduceIte] <;> omega

theorem ones_filter (n : Nat) (v : BitVec 64) :
    ones n v = ((List.range n).filter (fun i => v.getLsbD i)).length := by
  induction n generalizing v with
  | zero => rfl
  | succ n ih =>
    simp only [ones, List.range_succ_eq_map, List.filter_cons, List.filter_map,
      ih, Function.comp_def, Nat.succ_eq_add_one,
      BitVec.getLsbD_ushiftRight, Nat.add_comm]
    split <;> simp_all [Nat.add_comm]

/-- x86/bpf_x86_popcnt.c:instantiate_popcntq's one-bit countdown iteration. -/
def iteration (d t : BPF.Reg) : List BPF.MInsn :=
  [.branch .bitSet .w64 t (.imm (1#64)) 1,
    .core (.alu .add .w64 d (.imm (BitVec.signExtend 64 (-1 : BitVec 32)))),
    .core (.alu .rsh .w64 t (BPF.immN 1))]

def iterationEffect (d t : BPF.Reg) (s : BPF.State) : BPF.State :=
  { s with regs := (BPF.RegFile.set s.regs d
    (s.regs d - if (s.regs t).getLsbD 0 then 0 else 1)).set t (s.regs t >>> 1) }

theorem minus_one : BitVec.signExtend 64 (-1 : BitVec 32) = -(1#64) := by decide +kernel

theorem reg_set_current (rf : BPF.RegFile) (d : BPF.Reg) :
    BPF.RegFile.set rf d (rf d) = rf := by
  funext q
  by_cases h : q = d <;> simp [BPF.RegFile.set, h]

theorem iteration_exec (d t : BPF.Reg) (ht : t ≠ d) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (iteration d t ++ tail) s = BPF.mexec tail (iterationEffect d t s) := by
  have hb : BPF.Cond.test .bitSet .w64 (s.regs t) (1#64) = (s.regs t).getLsbD 0 := by
    exact ModuleDispatch.bitTest_eq (s.regs t) 0 (by decide)
  simp only [iteration, List.cons_append, List.nil_append, BPF.mexec, BPF.Src.eval, minus_one]
  rw [hb]
  cases he : (s.regs t).getLsbD 0 <;>
    simp only [iterationEffect, he, Bool.false_eq_true, ↓reduceIte]
  all_goals simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
    BPF.Src.eval, BPF.immN, BPF.RegFile.set_other _ _ _ _ ht,
     BitVec.sub_eq_add_neg]

  apply congrArg (BPF.mexec tail)
  rw [reg_set_current]

/-- x86/bpf_x86_popcnt.c:instantiate_popcntq's unrolled 64-bit loop. -/
def loop (d t : BPF.Reg) : Nat → List BPF.MInsn
  | 0 => []
  | n+1 => iteration d t ++ loop d t n

def loopEffect (d t : BPF.Reg) (n : Nat) (s : BPF.State) : BPF.State :=
  { s with regs := (BPF.RegFile.set s.regs d
    (s.regs d - BitVec.ofNat 64 (zeros n (s.regs t)))).set t (s.regs t >>> n) }

theorem effect_succ (d t : BPF.Reg) (n : Nat) (s : BPF.State) :
    loopEffect d t n (iterationEffect d t s) = loopEffect d t (n+1) s := by
  cases he : (s.regs t).getLsbD 0 <;>
    simp only [loopEffect, iterationEffect, zeros, he, Bool.false_eq_true, ↓reduceIte]
  all_goals congr 1
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set, ← BitVec.shiftRight_add, Nat.add_comm,
    BitVec.ofNat_add, BitVec.sub_sub]

theorem loop_exec (d t : BPF.Reg) (ht : t ≠ d) (n : Nat) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (loop d t n ++ tail) s = BPF.mexec tail (loopEffect d t n s) := by
  induction n generalizing s with
  | zero =>
    simp [loop, loopEffect, zeros, reg_set_current]
  | succ n ih =>
    rw [loop, List.append_assoc, iteration_exec d t ht, ih, effect_succ d t]

theorem count_value (v : BitVec 64) :
    (64#64) - BitVec.ofNat 64 (zeros 64 v) = BitVec.ofNat 64 (ones 64 v) := by
  have hp := congrArg (BitVec.ofNat 64) (partition 64 v)
  rw [BitVec.ofNat_add] at hp
  rw [← hp, BitVec.add_sub_cancel]

/-- x86/bpf_x86_popcnt.c:instantiate_popcntq, for both RR payload tags. -/
def bpf (d src t : BPF.Reg) : List BPF.MInsn :=
  [.store 8 .r10 (.reg t) ModuleByteAlu.slot,
    .core (.alu .mov .w64 t (.reg src)), .core (.alu .mov .w64 d (.imm 64))] ++
    loop d t 64 ++ ModuleByteAlu.suffix t

/-- x86/bpf_x86_popcnt.c:emit_popcntq_x86: matching spill; POPCNT; restore. -/
def native (m : X86RegMap) (d src t : BPF.Reg) : List X86.MInsn :=
  [.store 8 (m.map t) (m.map .r10) ModuleByteAlu.slot,
    .popcnt (m.map d) (m.map src), .load 8 (m.map t) (m.map .r10) ModuleByteAlu.slot]

def spec (d src t : BPF.Reg) (s : Outcome) : Outcome :=
  ModuleByteAlu.finish d t (BitVec.ofNat 64 (ones 64 (s.regs src))) s

theorem bpf_correct (d src t : BPF.Reg) (ht : t ≠ d) (hf : t ≠ .r10)
    (hd : d ≠ .r10) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf d src t) s) = spec d src t (observeBpf s) := by
  simp only [bpf, List.cons_append, List.nil_append,
    BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval]
  rw [loop_exec d t ht]
  simp [ModuleByteAlu.suffix, loopEffect, spec, ModuleByteAlu.finish,
    ModuleMemory.storeSpec, ModuleByteAlu.slot, BPF.mexec, BPF.MInsn.step,
    observeBpf, Machine.State.read, Machine.State.write, Machine.State.set,
    BPF.RegFile.set, ht, Ne.symm hf, Ne.symm hd, count_value]
  funext q
  by_cases hqt : q = t <;> by_cases hqd : q = d <;>
    simp_all [BPF.RegFile.set]

theorem native_correct (m : X86RegMap) (d src t : BPF.Reg) (hd : d ≠ .r10)
    (s : X86.State) :
    observeX86 m (X86.mexec (native m d src t) s) = spec d src t (observeX86 m s) := by
  simp [native, spec, ModuleByteAlu.finish, ModuleMemory.storeSpec, ones_filter,
    X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, observeX86,
    Machine.State.read, Machine.State.write, Machine.State.set,
    m.inj.eq_iff, Ne.symm hd]
  funext q
  by_cases hqt : q = t <;> by_cases hqd : q = d <;> simp_all [BPF.RegFile.set]

theorem loop_writes (d t r : BPF.Reg) (n : Nat)
    (h : r ∈ BPF.mwrites (loop d t n)) : r = d ∨ r = t := by
  induction n with
  | zero => simp [loop, BPF.mwrites] at h
  | succ n ih =>
    simp only [loop, BPF.mwrites, List.flatMap_append, List.mem_append] at h
    rcases h with h | h
    · simpa [iteration, BPF.MInsn.writes, BPF.Insn.dstReg] using h
    · exact ih h

/-- x86/bpf_x86_popcnt.c:instantiate_popcntq/emit_popcntq_x86. The
    full mapped register file, memory, and ordered spill trace are observed. -/
def bpf_x86_popcntq (m : X86RegMap) (d src t : BPF.Reg) (ht : t ≠ d)
    (hf : t ≠ .r10) (hd : d ≠ .r10) : X86StateEquiv m where
  spec := spec d src t
  bpf := bpf d src t
  native := native m d src t
  writeSet := [d, t]
  bpfCorrect := bpf_correct d src t ht hf hd
  nativeCorrect := native_correct m d src t hd
  bpfWrites := by
    intro r h
    simp only [bpf, BPF.mwrites, List.flatMap_append, List.mem_append] at h
    rcases h with (h | h) | h
    · simpa [BPF.MInsn.writes, BPF.Insn.dstReg, or_comm] using h
    · simpa using loop_writes d t r 64 h
    · have he : r = t := by simpa [ModuleByteAlu.suffix, BPF.MInsn.writes] using h
      simp [he]
  nativeWrites := by
    simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff, or_comm]

end Kinsn.ModulePopcnt
