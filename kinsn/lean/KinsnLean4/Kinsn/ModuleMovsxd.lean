import KinsnLean4.Kinsn.ModuleMovzx
import KinsnLean4.Kinsn.SignExtend

namespace Kinsn.ModuleMovsxd

inductive Operand where
  | reg (r : BPF.Reg)
  | indexed (base index : BPF.Reg) (scale : Nat) (off : BitVec 64)

def Operand.Valid : Operand → Prop
  | .reg _ => True | .indexed _ _ scale _ => scale ≤ 3

def value (v : BitVec 64) : BitVec 64 := SignExtend.spec 32 v

/-- x86/bpf_x86_mov.c:instantiate_movsxd's final 64-bit shift pair. -/
def extend (d : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .lsh .w64 d (BPF.immN 32)),
   .core (.alu .arsh .w64 d (BPF.immN 32))]

/-- x86/bpf_x86_mov.c:instantiate_movsxd: RR and ARCH_RR copy the live
    source; SIB and ARCH_SIB load a word using instantiate_mov_sib, then all
    forms sign-extend the destination's low 32 bits. -/
def bpf (d : BPF.Reg) (operand : Operand) : List BPF.MInsn :=
  (match operand with
   | .reg r => [.core (.alu .mov .w64 d (.reg r))]
   | .indexed b i scale off =>
       (ModuleMovbeWide.address d b i scale).map BPF.MInsn.core ++
         [.load 4 d d off]) ++ extend d

/-- x86/bpf_x86_mov.c:emit_movsxd_x86, REX.W 63 /r for RR or SIB memory.
    loadIndexSx32 represents the single memory-source instruction, including
    its raw word read and sign-extended 64-bit result. -/
def native (m : X86RegMap) (d : BPF.Reg) (operand : Operand) : List X86.MInsn :=
  match operand with
  | .reg r => [.core (.movsx 32 (m.map d) (m.map r))]
  | .indexed b i scale off => [.loadIndexSx32 (m.map d) (m.map b) (m.map i) scale off]

def spec (d : BPF.Reg) (operand : Operand) (s : Outcome) : Outcome :=
  match operand with
  | .reg r => ModuleRegister.unarySpec d r value s
  | .indexed b i scale off =>
      let a := s.regs b + (s.regs i <<< scale) + off
      let v := Machine.loadLE s.mem a 4
      { regs := s.regs.set d (value v), mem := s.mem, trace := s.trace ++ [.read a 4 v] }

theorem extend_exec (d : BPF.Reg) (s : BPF.State) :
    BPF.mexec (extend d) s = { s with regs := (BPF.RegFile.set s.regs d (value (s.regs d))) } := by
  simp [extend, value, SignExtend.spec, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.immN, BPF.RegFile.set_set_same,
    Bits.shiftLeft_sshiftRight_eq_signExtend _ 32 (by decide) (by decide)]

theorem bpf_correct (d : BPF.Reg) (operand : Operand) (hv : operand.Valid) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf d operand) s) = spec d operand (observeBpf s) := by
  cases operand with
  | reg r =>
    simp only [bpf, List.cons_append, List.nil_append, BPF.mexec, BPF.MInsn.step,
      BPF.Insn.step, BPF.AluOp.eval, extend_exec]
    simp [spec, ModuleRegister.unarySpec, observeBpf, BPF.RegFile.set_set_same]
  | indexed b i scale off =>
    simp only [bpf, List.append_assoc, ModuleDispatch.exec_core_tail]
    rw [ModuleMovbeWide.address_exec d b i scale hv]
    simp only [List.cons_append, List.nil_append, BPF.mexec, BPF.MInsn.step, extend_exec]
    simp [spec, observeBpf, Machine.State.set, Machine.State.read, BPF.RegFile.set_same]
    funext q; by_cases h : q = d <;> simp [BPF.RegFile.set, h]

theorem native_correct (m : X86RegMap) (d : BPF.Reg) (operand : Operand) (s : X86.State) :
    observeX86 m (X86.mexec (native m d operand) s) = spec d operand (observeX86 m s) := by
  cases operand with
  | reg r =>
    change observeX86 m (s.set (m.map d) (value (s.regs (m.map r)))) = _
    rw [x86_observe_set]
    rfl
  | indexed b i scale off =>
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
    rw [x86_observe_set]
    simp [spec, value, SignExtend.spec, observeX86, Machine.State.read]

def bpf_x86_movsxd (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) : X86StateEquiv m where
  spec := spec d operand
  bpf := bpf d operand
  native := native m d operand
  writeSet := [d]
  bpfCorrect := bpf_correct d operand hv
  nativeCorrect := native_correct m d operand
  bpfWrites := by
    intro t ht
    cases operand with
    | reg r => simpa [bpf, extend, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
    | indexed b i scale off =>
      simp only [bpf, List.append_assoc, BPF.mwrites, List.flatMap_append,
        List.mem_append] at ht
      rcases ht with ht | ht
      · exact List.mem_singleton.mpr (ModuleMovbeWide.address_writes d b i t scale
          (by simpa [BPF.writes, List.flatMap_map, BPF.MInsn.writes,
            List.mem_flatMap, eq_comm] using ht))
      · simpa [extend, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
  nativeWrites := by
    cases operand <;> simp [native, X86.mwrites, X86.MInsn.writes,
      X86.Insn.dstReg, m.inj.eq_iff]

end Kinsn.ModuleMovsxd
