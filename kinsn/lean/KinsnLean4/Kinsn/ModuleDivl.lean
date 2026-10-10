import KinsnLean4.Kinsn.ModuleAluWide

namespace Kinsn.ModuleDivl

def low (v : BitVec 64) : BitVec 64 := BitVec.setWidth 64 (BitVec.setWidth 32 v)
def numerator (hi lo : BitVec 64) : BitVec 64 := low lo ||| (low hi <<< 32)
def quotient (n v : BitVec 64) : BitVec 64 := if v = 0 then 0 else BitVec.udiv n v
def remainder (n v : BitVec 64) : BitVec 64 := if v = 0 then n else BitVec.umod n v

/-- The divisor register is a declared output, not a saved temporary. -/
structure Output (v : BPF.Reg) : Prop where
  v0 : v ≠ .r0
  v3 : v ≠ .r3
  vf : v ≠ .r10

def prepareBpf (v src : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .mov .w32 v (.reg src)), .core (.alu .mov .w32 .r3 (.reg .r3)),
    .core (.alu .lsh .w64 .r3 (BPF.immN 32)), .core (.alu .mov .w32 .r0 (.reg .r0)),
    .core (.alu .or .w64 .r0 (.reg .r3))]

def preparedBpf (v src : BPF.Reg) (s : BPF.State) : BPF.State :=
  { s with regs := ((BPF.RegFile.set s.regs v (low (s.regs src))).set .r3
    (low (s.regs .r3) <<< 32)).set .r0 (numerator (s.regs .r3) (s.regs .r0)) }

theorem prepare_bpf (v src : BPF.Reg) (h : Output v) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (prepareBpf v src ++ tail) s = BPF.mexec tail (preparedBpf v src s) := by
  rcases h with ⟨hv0, hv3, hvf⟩
  simp [prepareBpf, preparedBpf, numerator, low, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval, BPF.immN, BPF.RegFile.set,
    hv0, hv3, Ne.symm hv0, Ne.symm hv3]
  apply congrArg (BPF.mexec tail)
  congr 1
  funext q
  by_cases hq0 : q = .r0 <;> by_cases hq3 : q = .r3 <;> by_cases hqv : q = v <;>
    simp_all [BPF.RegFile.set, Ne.symm]

/-- Ten instructions, writing only quotient, remainder, and divisor output. -/
def bpf (v src : BPF.Reg) : List BPF.MInsn :=
  prepareBpf v src ++
    [.core (.alu .mov .w64 .r3 (.reg .r0)), .divide true .r3 v, .divide false .r0 v,
      .core (.alu .mov .w32 .r0 (.reg .r0)), .core (.alu .mov .w32 .r3 (.reg .r3))]

def spec (v src : BPF.Reg) (s : Outcome) : Outcome :=
  let n := numerator (s.regs .r3) (s.regs .r0)
  let divisor := low (s.regs src)
  { s with regs := (((s.regs.set v divisor).set .r0 (low (quotient n divisor))).set .r3
      (low (remainder n divisor))) }

theorem bpf_correct (v src : BPF.Reg) (h : Output v) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf v src) s) = spec v src (observeBpf s) := by
  rw [bpf, prepare_bpf v src h]
  rcases h with ⟨hv0, hv3, hvf⟩
  simp [preparedBpf, spec, quotient, remainder, low, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval, observeBpf, Machine.State.set,
    BPF.RegFile.set, hv0, hv3, Ne.symm hv0, Ne.symm hv3]
  funext q
  by_cases hqv : q = v <;> by_cases hq0 : q = .r0 <;>
    by_cases hq3 : q = .r3 <;> simp_all [BPF.RegFile.set, Ne.symm]

def prepareNative (m : X86RegMap) (v src : BPF.Reg) : List X86.MInsn :=
  [.mov32 (m.map v) (m.map src), .mov32 (m.map .r3) (m.map .r3),
    .core (.shiftI .shl (m.map .r3) 32), .mov32 (m.map .r0) (m.map .r0),
    .core (.aluRR .or (m.map .r0) (m.map .r3))]

def preparedNative (m : X86RegMap) (v src : BPF.Reg) (s : X86.State) : X86.State :=
  ((s.set (m.map v) (low (s.regs (m.map src)))).set (m.map .r3)
    (low (s.regs (m.map .r3)) <<< 32)).set (m.map .r0)
    (numerator (s.regs (m.map .r3)) (s.regs (m.map .r0)))

theorem prepare_native (m : X86RegMap) (v src : BPF.Reg) (h : Output v)
    (s : X86.State) (tail : List X86.MInsn) :
    X86.mexec (prepareNative m v src ++ tail) s =
      X86.mexec tail (preparedNative m v src s) := by
  rcases h with ⟨hv0, hv3, hvf⟩
  simp [prepareNative, preparedNative, numerator, low, X86.mexec_cons,
    X86.mexec_nil, X86.MInsn.step, X86.Insn.step, X86.AluOp.eval, X86.ShiftOp.eval,
    Machine.State.set, m.inj.eq_iff, hv0, hv3, Ne.symm hv0, Ne.symm hv3]
  apply congrArg (X86.mexec tail)
  congr 1
  funext q
  by_cases hq0 : q = m.map .r0 <;> by_cases hq3 : q = m.map .r3 <;>
    by_cases hqv : q = m.map v <;> simp_all [X86.RegFile.set, m.inj.eq_iff, Ne.symm]

def native (m : X86RegMap) (v src : BPF.Reg) : List X86.MInsn :=
  prepareNative m v src ++ [.guardedDiv64 (m.map v),
    .mov32 (m.map .r0) (m.map .r0), .mov32 (m.map .r3) (m.map .r3)]

/-- The taken DIV64 path has a nonzero divisor and its quotient fits the
    hardware result width: its implicit high half was explicitly cleared.
    This holds for every incoming RDX, not only BPF-visible test inputs. -/
theorem guarded_no_divide_error (src : X86.GPReg) (s : X86.State)
    (hv : ((s.set .rdx 0).regs src) ≠ 0) :
    0 < ((s.set .rdx 0).regs src).toNat ∧
    (0 * 2^64 + (s.regs .rax).toNat) / ((s.set .rdx 0).regs src).toNat < 2^64 := by
  have hp : 0 < ((s.set .rdx 0).regs src).toNat := by
    have hn : ((s.set .rdx 0).regs src).toNat ≠ 0 := by
      intro he
      apply hv
      apply BitVec.eq_of_toNat_eq
      simpa using he
    omega
  constructor
  · exact hp
  · simp only [Nat.zero_mul, Nat.zero_add]
    exact lt_of_le_of_lt (Nat.div_le_self _ _) (s.regs .rax).isLt

theorem native_correct (m : X86RegMap) (ha : m.map .r0 = .rax) (hd : m.map .r3 = .rdx)
    (v src : BPF.Reg) (h : Output v) (s : X86.State) :
    observeX86 m (X86.mexec (native m v src) s) = spec v src (observeX86 m s) := by
  rw [native, prepare_native m v src h]
  rcases h with ⟨hv0, hv3, hvf⟩
  have ax (r : BPF.Reg) : m.map r = .rax ↔ r = .r0 := by rw [← ha, m.inj.eq_iff]
  have dx (r : BPF.Reg) : m.map r = .rdx ↔ r = .r3 := by rw [← hd, m.inj.eq_iff]
  simp [preparedNative, spec, quotient, remainder, low, X86.mexec_cons,
    X86.mexec_nil, X86.MInsn.step, X86.Insn.step, observeX86, Machine.State.set,
    m.inj.eq_iff, ax, dx, ha, hd, hv0, hv3, Ne.symm hv0, Ne.symm hv3]
  funext q
  by_cases hqv : q = v <;> by_cases hq0 : q = .r0 <;>
    by_cases hq3 : q = .r3 <;> simp_all [BPF.RegFile.set, m.inj.eq_iff, ax, dx, ha, hd, Ne.symm]

/-- Every divisor alias, including R0, R3, and read-only R10. The lowest
    writable register excluding R0/R3/source holds the zero-extended divisor. -/
def bpf_x86_divl (m : X86RegMap) (ha : m.map .r0 = .rax) (hd : m.map .r3 = .rdx)
    (v src : BPF.Reg) (h : Output v) : X86StateEquiv m where
  spec := spec v src
  bpf := bpf v src
  native := native m v src
  writeSet := [.r0, .r3, v]
  bpfCorrect := bpf_correct v src h
  nativeCorrect := native_correct m ha hd v src h
  bpfWrites := by
    simp [bpf, prepareBpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg,
      or_comm, or_left_comm, or_assoc]
  nativeWrites := by
    simp [native, prepareNative, X86.mwrites, X86.MInsn.writes, X86.Insn.dstReg,
      m.inj.eq_iff, ← ha, ← hd, or_comm, or_left_comm, or_assoc]

end Kinsn.ModuleDivl
