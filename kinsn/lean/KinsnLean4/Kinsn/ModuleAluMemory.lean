import KinsnLean4.Kinsn.ModuleWideAlu

namespace Kinsn.ModuleAluMemory
open ModuleWideAlu (Kind width bits value)

/-- The lowest writable register excluding destination and address inputs is a
    declared data output. Its final value is the zero-extended loaded operand. -/
def bpf (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg) (scale : Nat)
    (off : BitVec 64) : List BPF.MInsn :=
  (ModuleWideAlu.address indexed t b i scale).map BPF.MInsn.core ++
    [.load (if w32 then 4 else 8) t t off,
      .core (.alu kind.bpf (width w32) d (.reg t))]

/-- One operand load into the declared data output, then register arithmetic. -/
def native (m : X86RegMap) (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg)
    (scale : Nat) (off : BitVec 64) : List X86.MInsn :=
  [if indexed then .loadIndex (if w32 then 4 else 8) (m.map t) (m.map b)
      (m.map i) scale off false else .load (if w32 then 4 else 8) (m.map t) (m.map b) off,
    .aluNarrow kind.native (bits w32) (m.map d) (m.map t)]

def spec (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (s : Outcome) : Outcome :=
  let a := s.regs b + (if indexed then s.regs i <<< scale else 0) + off
  let n := if w32 then 4 else 8
  let v := Machine.loadLE s.mem a n
  { regs := (s.regs.set t v).set d (value kind w32 (s.regs d) v)
    mem := s.mem
    trace := s.trace ++ [.read a n v] }

theorem bpf_correct (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg)
    (scale : Nat) (off : BitVec 64) (hs : scale ≤ 3) (ht : t ≠ d)
    (hi : t ≠ i) (hf : t ≠ .r10) (hd : d ≠ .r10) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf kind w32 indexed d b i t scale off) s) =
      spec kind w32 indexed d b i t scale off (observeBpf s) := by
  simp only [bpf]
  rw [ModuleDispatch.exec_core_tail, ModuleWideAlu.address_exec indexed t b i scale hi hs]
  cases w32 <;>
    simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval,
      width, value, spec, observeBpf, Machine.State.read,
      Machine.State.write, Machine.State.set, BPF.RegFile.set, ht, hi, hf, hd,
      Ne.symm ht, Ne.symm hf, Ne.symm hd, List.append_assoc]
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set]

theorem native_correct (m : X86RegMap) (kind : Kind) (w32 indexed : Bool)
    (d b i t : BPF.Reg) (scale : Nat) (off : BitVec 64) (ht : t ≠ d)
    (s : X86.State) :
    observeX86 m (X86.mexec (native m kind w32 indexed d b i t scale off) s) =
      spec kind w32 indexed d b i t scale off (observeX86 m s) := by
  cases indexed <;> cases w32 <;>
    simp [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, spec,
      observeX86, Machine.State.read, Machine.State.write,
      Machine.State.set, ModuleWideAlu.value_native, bits, X86.writeWidth,
      m.inj.eq_iff, BPF.RegFile.set, ht, Ne.symm ht, List.append_assoc]
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set, m.inj.eq_iff]

theorem address_writes (indexed : Bool) (t b i r : BPF.Reg) (scale : Nat)
    (h : r ∈ BPF.writes (ModuleWideAlu.address indexed t b i scale)) : r = t := by
  cases indexed <;>
    simpa [ModuleWideAlu.address, BPF.writes, BPF.Insn.dstReg,
      List.mem_replicate] using h

def certificate (m : X86RegMap) (kind : Kind) (w32 indexed : Bool)
    (d b i t : BPF.Reg) (scale : Nat) (off : BitVec 64) (hs : scale ≤ 3)
    (ht : t ≠ d) (hi : t ≠ i) (hf : t ≠ .r10) (hd : d ≠ .r10) : X86StateEquiv m where
  spec := spec kind w32 indexed d b i t scale off
  bpf := bpf kind w32 indexed d b i t scale off
  native := native m kind w32 indexed d b i t scale off
  writeSet := [d, t]
  bpfCorrect := bpf_correct kind w32 indexed d b i t scale off hs ht hi hf hd
  nativeCorrect := native_correct m kind w32 indexed d b i t scale off ht
  bpfWrites := by
    intro r hr
    simp only [bpf, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg, List.mem_append,
      List.mem_cons, List.mem_nil_iff, or_false, false_or] at hr
    rcases hr with hr | hr
    · have he := address_writes indexed t b i r scale
        (by simpa [BPF.writes, List.mem_flatMap, BPF.MInsn.writes, eq_comm] using hr)
      simp [he]
    · simpa [eq_comm, or_comm, or_left_comm] using hr
  nativeWrites := by
    cases indexed <;> simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleAluMemory
