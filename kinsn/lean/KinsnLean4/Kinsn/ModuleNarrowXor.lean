import KinsnLean4.Kinsn.ModuleAluMemory
import KinsnLean4.Kinsn.ModuleByteAlu

namespace Kinsn.ModuleNarrowXor

/-- The memory forms expose a second output holding the loaded byte/word. -/
def memoryBpf (n : Nat) (indexed : Bool) (d b i t : BPF.Reg) (scale : Nat)
    (off : BitVec 64) : List BPF.MInsn :=
  (ModuleWideAlu.address indexed t b i scale).map BPF.MInsn.core ++
    [.load n t t off, .core (.alu .xor .w64 d (.reg t))]

def memoryNative (m : X86RegMap) (n : Nat) (indexed : Bool) (d b i t : BPF.Reg)
    (scale : Nat) (off : BitVec 64) : List X86.MInsn :=
  [if indexed then .loadIndex n (m.map t) (m.map b) (m.map i) scale off false
      else .load n (m.map t) (m.map b) off,
    .aluNarrow .xor 64 (m.map d) (m.map t)]

def memorySpec (n : Nat) (indexed : Bool) (d b i t : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (s : Outcome) : Outcome :=
  let a := s.regs b + (if indexed then s.regs i <<< scale else 0) + off
  let v := Machine.loadLE s.mem a n
  { regs := (s.regs.set t v).set d (s.regs d ^^^ v)
    mem := s.mem
    trace := s.trace ++ [.read a n v] }

theorem memory_bpf_correct (n : Nat) (indexed : Bool) (d b i t : BPF.Reg)
    (scale : Nat) (off : BitVec 64) (hs : scale ≤ 3) (ht : t ≠ d)
    (hi : t ≠ i) (hf : t ≠ .r10) (hd : d ≠ .r10) (s : BPF.State) :
    observeBpf (BPF.mexec (memoryBpf n indexed d b i t scale off) s) =
      memorySpec n indexed d b i t scale off (observeBpf s) := by
  simp only [memoryBpf]
  rw [ModuleDispatch.exec_core_tail, ModuleWideAlu.address_exec indexed t b i scale hi hs]
  simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval,
    memorySpec, observeBpf, Machine.State.read,
    Machine.State.write, Machine.State.set, BPF.RegFile.set, Ne.symm ht,
    Ne.symm hf, Ne.symm hd, List.append_assoc]
  funext q
  by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set]

theorem memory_native_correct (m : X86RegMap) (n : Nat)
    (indexed : Bool) (d b i t : BPF.Reg) (scale : Nat) (off : BitVec 64)
    (ht : t ≠ d) (s : X86.State) :
    observeX86 m (X86.mexec (memoryNative m n indexed d b i t scale off) s) =
      memorySpec n indexed d b i t scale off (observeX86 m s) := by
  cases indexed <;>
    simp [memoryNative, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, memorySpec,
      observeX86, Machine.State.read, Machine.State.write,
      Machine.State.set, X86.AluOp.eval, X86.writeWidth,
      m.inj.eq_iff, BPF.RegFile.set, ht, Ne.symm ht, List.append_assoc]
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set]

def memoryCert (m : X86RegMap) (n : Nat) (hn : n = 1 ∨ n = 2) (indexed : Bool)
    (d b i t : BPF.Reg) (scale : Nat) (off : BitVec 64) (hs : scale ≤ 3)
    (ht : t ≠ d) (hi : t ≠ i) (hf : t ≠ .r10) (hd : d ≠ .r10) : X86StateEquiv m where
  spec := memorySpec n indexed d b i t scale off
  bpf := memoryBpf n indexed d b i t scale off
  native := memoryNative m n indexed d b i t scale off
  writeSet := [d, t]
  bpfCorrect := memory_bpf_correct n indexed d b i t scale off hs ht hi hf hd
  nativeCorrect := memory_native_correct m n indexed d b i t scale off ht
  bpfWrites := by
    intro r hr
    simp only [memoryBpf, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg, List.mem_append,
      List.mem_cons, List.mem_nil_iff, or_false, false_or] at hr
    rcases hr with hr | hr
    · have he := ModuleAluMemory.address_writes indexed t b i r scale
        (by simpa [BPF.writes, List.mem_flatMap, BPF.MInsn.writes, eq_comm] using hr)
      simp [he]
    · simpa [eq_comm, or_comm, or_left_comm] using hr
  nativeWrites := by
    cases indexed <;> simp [memoryNative, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

inductive ByteOperand where
  | scalar (t : BPF.Reg) (src : ModuleMovStore.Source)
  | indexed (b i t : BPF.Reg) (scale : Nat) (off : BitVec 16)

def ByteOperand.Valid (d : BPF.Reg) : ByteOperand → Prop
  | .scalar t src => d ≠ .r10 ∧ t ≠ d ∧ t ≠ .r10 ∧ ModuleByteAlu.sourceTempValid src t
  | .indexed _ i t scale _ => d ≠ .r10 ∧ scale ≤ 3 ∧ t ≠ d ∧ t ≠ i ∧ t ≠ .r10

/-- x86/bpf_x86_alu.c:instantiate_xorb/emit_xorb_x86: all scalar and indexed
    tags, including ARCH. The scalar cert is stronger than the imm8 range. -/
def bpf_x86_xorb (m : X86RegMap) (d : BPF.Reg) (operand : ByteOperand)
    (h : operand.Valid d) : X86StateEquiv m :=
  match operand with
  | .scalar t src => ModuleByteAlu.arithmeticCert m .xor d t src h.2.1 h.2.2.1 h.1 h.2.2.2
  | .indexed b i t scale off => memoryCert m 1 (by simp) true d b i t scale
      (BitVec.signExtend 64 off) h.2.1 h.2.2.1 h.2.2.2.1 h.2.2.2.2 h.1

/-- x86/bpf_x86_alu.c:instantiate_xorw/emit_xorw_x86: MEM/ARCH_MEM. -/
def bpf_x86_xorw (m : X86RegMap) (d b t : BPF.Reg) (off : BitVec 16)
    (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10) : X86StateEquiv m :=
  memoryCert m 2 (by simp) false d b .r10 t 0 (BitVec.signExtend 64 off)
    (by decide) ht hf hf hd

end Kinsn.ModuleNarrowXor
