import KinsnLean4.Kinsn.ModuleByteAlu

namespace Kinsn.ModuleDivl

def low (v : BitVec 64) : BitVec 64 := BitVec.setWidth 64 (BitVec.setWidth 32 v)
def numerator (hi lo : BitVec 64) : BitVec 64 := (low hi <<< 32) ||| low lo
def quotient (n v : BitVec 64) : BitVec 64 := if v = 0 then 0 else BitVec.udiv n v
def remainder (n v : BitVec 64) : BitVec 64 := if v = 0 then n else BitVec.umod n v

structure Temps (n v : BPF.Reg) : Prop where
  n0 : n ≠ .r0
  n3 : n ≠ .r3
  nf : n ≠ .r10
  v0 : v ≠ .r0
  v3 : v ≠ .r3
  vf : v ≠ .r10
  vn : v ≠ n

def lhsSlot : BitVec 64 := -16
def rhsSlot : BitVec 64 := -8

/-- x86/bpf_x86_alu.c:instantiate_divl captures the divisor first and
    assembles EDX:EAX without clobbering either live input prematurely. -/
def prepareBpf (n v src : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .mov .w32 v (.reg src)), .core (.alu .mov .w32 n (.reg .r3)),
    .core (.alu .lsh .w64 n (BPF.immN 32)), .core (.alu .mov .w32 .r0 (.reg .r0)),
    .core (.alu .or .w64 n (.reg .r0))]

def preparedBpf (n v src : BPF.Reg) (s : BPF.State) : BPF.State :=
  { s with regs := ((BPF.RegFile.set s.regs v (low (s.regs src))).set n
    (numerator (s.regs .r3) (s.regs .r0))).set .r0 (low (s.regs .r0)) }

theorem prepare_bpf (n v src : BPF.Reg) (h : Temps n v) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (prepareBpf n v src ++ tail) s = BPF.mexec tail (preparedBpf n v src s) := by
  rcases h with ⟨hn0, hn3, hnf, hv0, hv3, hvf, hvn⟩
  simp [prepareBpf, preparedBpf, numerator, low, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval, BPF.immN, BPF.RegFile.set,
    hn0, hn3, hv0, hv3, hvn, Ne.symm hvn]
  apply congrArg (BPF.mexec tail)
  congr 1
  funext q
  by_cases hq0 : q = .r0 <;> by_cases hqn : q = n <;> by_cases hqv : q = v <;>
    simp_all [BPF.RegFile.set, Ne.symm]

/-- x86/bpf_x86_alu.c:instantiate_divl's complete 15-instruction proof. -/
def bpf (n v src : BPF.Reg) : List BPF.MInsn :=
  [.store 8 .r10 (.reg n) lhsSlot, .store 8 .r10 (.reg v) rhsSlot] ++
    prepareBpf n v src ++
    [.core (.alu .mov .w64 .r0 (.reg n)), .core (.alu .mov .w64 .r3 (.reg n)),
      .divide true .r3 v, .divide false .r0 v,
      .core (.alu .mov .w32 .r0 (.reg .r0)), .core (.alu .mov .w32 .r3 (.reg .r3)),
      .load 8 v .r10 rhsSlot, .load 8 n .r10 lhsSlot]

def saved (n v : BPF.Reg) (s : Outcome) : Outcome :=
  ModuleMemory.storeSpec 8 v .r10 rhsSlot (ModuleMemory.storeSpec 8 n .r10 lhsSlot s)

/-- The restored values are loads from the actual saved memory. -/
def finish (n v : BPF.Reg) (q r : BitVec 64) (s : Outcome) : Outcome :=
  let a := s.regs .r10
  let rv := Machine.loadLE s.mem (a + rhsSlot) 8
  let rn := Machine.loadLE s.mem (a + lhsSlot) 8
  { regs := (((s.regs.set .r0 (low q)).set .r3 (low r)).set v rv).set n rn
    mem := s.mem
    trace := s.trace ++ [.read (a + rhsSlot) 8 rv, .read (a + lhsSlot) 8 rn] }

def spec (n v src : BPF.Reg) (s : Outcome) : Outcome :=
  let num := numerator (s.regs .r3) (s.regs .r0)
  let divisor := low (s.regs src)
  finish n v (quotient num divisor) (remainder num divisor) (saved n v s)

theorem bpf_tail (n v src : BPF.Reg) (h : Temps n v) (s : BPF.State) :
    observeBpf (BPF.mexec
      [.core (.alu .mov .w64 .r0 (.reg n)), .core (.alu .mov .w64 .r3 (.reg n)),
        .divide true .r3 v, .divide false .r0 v,
        .core (.alu .mov .w32 .r0 (.reg .r0)), .core (.alu .mov .w32 .r3 (.reg .r3)),
        .load 8 v .r10 rhsSlot, .load 8 n .r10 lhsSlot] (preparedBpf n v src s)) =
      finish n v (quotient (numerator (s.regs .r3) (s.regs .r0)) (low (s.regs src)))
        (remainder (numerator (s.regs .r3) (s.regs .r0)) (low (s.regs src)))
        (observeBpf s) := by
  rcases h with ⟨hn0, hn3, hnf, hv0, hv3, hvf, hvn⟩
  simp [preparedBpf, finish, quotient, remainder, low, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval, observeBpf, Machine.State.read,
    Machine.State.set, BPF.RegFile.set, hn0, hn3, hnf, hv0, hv3, hvf, hvn,
    Ne.symm hn0, Ne.symm hn3, Ne.symm hnf, Ne.symm hv0, Ne.symm hv3,
    Ne.symm hvf, Ne.symm hvn, List.append_assoc]
  funext q
  by_cases hqn : q = n <;> by_cases hqv : q = v <;> by_cases hq0 : q = .r0 <;>
    by_cases hq3 : q = .r3 <;> simp_all [BPF.RegFile.set, Ne.symm]

theorem bpf_correct (n v src : BPF.Reg) (h : Temps n v) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf n v src) s) = spec n v src (observeBpf s) := by
  simp only [bpf, List.append_assoc, List.cons_append, List.nil_append, BPF.mexec,
    BPF.MInsn.step, BPF.Src.eval]
  rw [prepare_bpf n v src h, bpf_tail n v src h]
  rfl

/-- x86/bpf_x86_alu.c:emit_divl_x86: native preparation, explicit guarded
    DIV64 block, 32-bit result truncation, and identical spills/restores. -/
def prepareNative (m : X86RegMap) (n v src : BPF.Reg) : List X86.MInsn :=
  [.mov32 (m.map v) (m.map src), .mov32 (m.map n) (m.map .r3),
    .core (.shiftI .shl (m.map n) 32), .mov32 (m.map .r0) (m.map .r0),
    .core (.aluRR .or (m.map n) (m.map .r0))]

def preparedNative (m : X86RegMap) (n v src : BPF.Reg) (s : X86.State) : X86.State :=
  ((s.set (m.map v) (low (s.regs (m.map src)))).set (m.map n)
    (numerator (s.regs (m.map .r3)) (s.regs (m.map .r0)))).set (m.map .r0)
    (low (s.regs (m.map .r0)))

theorem prepare_native (m : X86RegMap) (n v src : BPF.Reg) (h : Temps n v)
    (s : X86.State) (tail : List X86.MInsn) :
    X86.mexec (prepareNative m n v src ++ tail) s =
      X86.mexec tail (preparedNative m n v src s) := by
  rcases h with ⟨hn0, hn3, hnf, hv0, hv3, hvf, hvn⟩
  simp [prepareNative, preparedNative, numerator, low, X86.mexec_cons,
    X86.mexec_nil, X86.MInsn.step, X86.Insn.step, X86.AluOp.eval, X86.ShiftOp.eval,
    Machine.State.set, m.inj.eq_iff, hn0, hn3, hv0, hv3, hvn, Ne.symm hvn]
  apply congrArg (X86.mexec tail)
  congr 1
  funext q
  by_cases hq0 : q = m.map .r0 <;> by_cases hqn : q = m.map n <;>
    by_cases hqv : q = m.map v <;> simp_all [X86.RegFile.set, m.inj.eq_iff, Ne.symm]

def native (m : X86RegMap) (n v src : BPF.Reg) : List X86.MInsn :=
  [.store 8 (m.map n) (m.map .r10) lhsSlot, .store 8 (m.map v) (m.map .r10) rhsSlot] ++
    prepareNative m n v src ++
    [.core (.movRR (m.map .r0) (m.map n)), .guardedDiv64 (m.map v),
      .mov32 (m.map .r0) (m.map .r0), .mov32 (m.map .r3) (m.map .r3),
      .load 8 (m.map v) (m.map .r10) rhsSlot, .load 8 (m.map n) (m.map .r10) lhsSlot]

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

theorem native_tail (m : X86RegMap) (ha : m.map .r0 = .rax) (hd : m.map .r3 = .rdx)
    (n v src : BPF.Reg) (h : Temps n v) (s : X86.State) :
    observeX86 m (X86.mexec
      [.core (.movRR (m.map .r0) (m.map n)), .guardedDiv64 (m.map v),
        .mov32 (m.map .r0) (m.map .r0), .mov32 (m.map .r3) (m.map .r3),
        .load 8 (m.map v) (m.map .r10) rhsSlot, .load 8 (m.map n) (m.map .r10) lhsSlot]
        (preparedNative m n v src s)) =
      finish n v (quotient (numerator (s.regs (m.map .r3)) (s.regs (m.map .r0)))
        (low (s.regs (m.map src))))
        (remainder (numerator (s.regs (m.map .r3)) (s.regs (m.map .r0)))
        (low (s.regs (m.map src)))) (observeX86 m s) := by
  rcases h with ⟨hn0, hn3, hnf, hv0, hv3, hvf, hvn⟩
  have ax (r : BPF.Reg) : m.map r = .rax ↔ r = .r0 := by rw [← ha, m.inj.eq_iff]
  have dx (r : BPF.Reg) : m.map r = .rdx ↔ r = .r3 := by rw [← hd, m.inj.eq_iff]
  simp [preparedNative, finish, quotient, remainder, low, X86.mexec_cons,
    X86.mexec_nil, X86.MInsn.step, X86.Insn.step, observeX86, Machine.State.read,
    Machine.State.set, m.inj.eq_iff, ax, dx, ha, hd, hn0, hn3, hnf, hv0, hv3, hvf,
    hvn, Ne.symm hn0, Ne.symm hn3, Ne.symm hnf, Ne.symm hv0, Ne.symm hv3,
    Ne.symm hvf, Ne.symm hvn, List.append_assoc]
  funext q
  by_cases hqn : q = n <;> by_cases hqv : q = v <;> by_cases hq0 : q = .r0 <;>
    by_cases hq3 : q = .r3 <;> simp_all [BPF.RegFile.set, m.inj.eq_iff, ax, dx, ha, hd, Ne.symm]

theorem native_correct (m : X86RegMap) (ha : m.map .r0 = .rax) (hd : m.map .r3 = .rdx)
    (n v src : BPF.Reg) (h : Temps n v) (s : X86.State) :
    observeX86 m (X86.mexec (native m n v src) s) = spec n v src (observeX86 m s) := by
  simp only [native, List.cons_append, List.nil_append, X86.mexec_cons, X86.MInsn.step]
  rw [prepare_native m n v src h, native_tail m ha hd n v src h]
  rfl

/-- x86/bpf_x86_alu.c:instantiate_divl/emit_divl_x86, both payload tags and
    every divisor alias, including R0, R3, and read-only R10. -/
def bpf_x86_divl (m : X86RegMap) (ha : m.map .r0 = .rax) (hd : m.map .r3 = .rdx)
    (n v src : BPF.Reg) (h : Temps n v) : X86StateEquiv m where
  spec := spec n v src
  bpf := bpf n v src
  native := native m n v src
  writeSet := [.r0, .r3, n, v]
  bpfCorrect := bpf_correct n v src h
  nativeCorrect := native_correct m ha hd n v src h
  bpfWrites := by
    simp [bpf, prepareBpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg,
      or_comm, or_left_comm, or_assoc]
  nativeWrites := by
    simp [native, prepareNative, X86.mwrites, X86.MInsn.writes, X86.Insn.dstReg,
      m.inj.eq_iff, ← ha, ← hd, or_comm, or_left_comm, or_assoc]

end Kinsn.ModuleDivl
