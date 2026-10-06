import KinsnLean4.Kinsn.ModuleBmiShift

namespace Kinsn.ModuleAluShift
open ModuleBmiShift (bits width)

inductive Kind where
  | left | right | arithmetic
  deriving DecidableEq, Repr

inductive Count where
  | cl
  | imm (n : Nat)
  deriving Repr

def Kind.bpfOp : Kind → BPF.AluOp
  | .left => .lsh | .right => .rsh | .arithmetic => .arsh

def Kind.x86Op : Kind → X86.ShiftOp
  | .left => .shl | .right => .shr | .arithmetic => .sar

def Count.source : Count → BPF.Src
  | .cl => .reg .r4 | .imm n => BPF.immN n

def Count.number (count : Count) (rf : BPF.RegFile) : Nat :=
  match count with
  | .cl => (rf .r4).toNat | .imm n => n

def Count.Valid (count : Count) (is64 : Bool) : Prop :=
  match count with
  | .cl => True | .imm n => n < bits is64

def value (is64 : Bool) (kind : Kind) (v : BitVec 64) (count : Nat) : BitVec 64 :=
  let v := BitVec.setWidth (bits is64) v
  let n := count % bits is64
  BitVec.setWidth 64 (match kind with
    | .left => v <<< n | .right => v >>> n | .arithmetic => v.sshiftRight n)

/-- x86/bpf_x86_alu.c:instantiate_x86_shift: immediate and CL forms, ordinary
    and ARCH, directly shift the live destination. Memory-source shifts fail in
    both expansion and emission. -/
def bpf (is64 : Bool) (kind : Kind) (d : BPF.Reg) (count : Count) : List BPF.MInsn :=
  [.core (.alu kind.bpfOp (width is64) d count.source)]

/-- x86/bpf_x86_alu.c:emit_x86_alu: C1 /group imm8 or D3 /group CL,
    with the REX.W bit selecting 64 bits. Counts are hardware-masked by width. -/
def native (m : X86RegMap) (is64 : Bool) (kind : Kind) (d : BPF.Reg) (count : Count) :
    List X86.MInsn :=
  match count with
  | .cl => [.shiftCLWidth (bits is64) kind.x86Op (m.map d)]
  | .imm n => [.shiftImmWidth (bits is64) kind.x86Op (m.map d) (BitVec.ofNat 8 n).toNat]

def spec (is64 : Bool) (kind : Kind) (d : BPF.Reg) (count : Count) (s : Outcome) :
    Outcome :=
  { s with regs := s.regs.set d (value is64 kind (s.regs d) (count.number s.regs)) }

theorem bpf_correct (is64 : Bool) (kind : Kind) (d : BPF.Reg) (count : Count)
    (s : BPF.State) :
    observeBpf (BPF.mexec (bpf is64 kind d count) s) =
      spec is64 kind d count (observeBpf s) := by
  cases count <;> cases is64 <;> cases kind <;>
    simp [bpf, spec, value, Count.number, Count.source, Kind.bpfOp, width, bits,
      BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, BPF.immN, observeBpf,
      BitVec.toNat_setWidth, Nat.mod_mod_of_dvd]

theorem narrow_right (v : BitVec 32) (n : Nat) :
    BitVec.setWidth 64 (BitVec.setWidth 32 (BitVec.setWidth 64 v >>> n)) =
      BitVec.setWidth 64 v >>> n := by
  calc
    _ = BitVec.setWidth 64 (BitVec.setWidth 32 (BitVec.setWidth 64 (v >>> n))) := by
      rw [BitVec.setWidth_ushiftRight (by decide : 32 ≤ 64)]
    _ = BitVec.setWidth 64 (v >>> n) := by
      rw [BitVec.setWidth_setWidth_of_le _ (by decide : 32 ≤ 64), BitVec.setWidth_eq]
    _ = _ := BitVec.setWidth_ushiftRight (by decide : 32 ≤ 64)

theorem encoded_count (is64 : Bool) (n : Nat) (hn : n < bits is64) :
    (BitVec.ofNat 8 n).toNat = n := by
  have h256 : n < 256 := by cases is64 <;> simp [bits] at hn <;> omega
  exact Nat.mod_eq_of_lt h256

theorem native_correct (m : X86RegMap) (hc : m.map .r4 = .rcx) (is64 : Bool)
    (kind : Kind) (d : BPF.Reg) (count : Count) (h : count.Valid is64) (s : X86.State) :
    observeX86 m (X86.mexec (native m is64 kind d count) s) =
      spec is64 kind d count (observeX86 m s) := by
  have he (n : Nat) (hn : count = .imm n) : (BitVec.ofNat 8 n).toNat = n := by
    subst count
    exact encoded_count is64 n h
  cases count <;> simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  all_goals rw [x86_observe_set]
  all_goals cases is64 <;> cases kind <;>
    simp [spec, value, bits, Kind.x86Op, Count.number, observeX86, hc,
      X86.writeWidth, narrow_right, he]

def cert (m : X86RegMap) (hc : m.map .r4 = .rcx) (is64 : Bool) (kind : Kind)
    (d : BPF.Reg) (count : Count) (h : count.Valid is64) : X86StateEquiv m where
  spec := spec is64 kind d count
  bpf := bpf is64 kind d count
  native := native m is64 kind d count
  writeSet := [d]
  bpfCorrect := bpf_correct is64 kind d count
  nativeCorrect := native_correct m hc is64 kind d count h
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by
    cases count <;> simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_alu.c:instantiate_shll/emit_shll_x86. -/
def bpf_x86_shll (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (h : c.Valid false) : X86StateEquiv m := cert m hc false .left d c h
/-- x86/bpf_x86_alu.c:instantiate_shlq/emit_shlq_x86. -/
def bpf_x86_shlq (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (h : c.Valid true) : X86StateEquiv m := cert m hc true .left d c h
/-- x86/bpf_x86_alu.c:instantiate_shrl/emit_shrl_x86. -/
def bpf_x86_shrl (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (h : c.Valid false) : X86StateEquiv m := cert m hc false .right d c h
/-- x86/bpf_x86_alu.c:instantiate_shrq/emit_shrq_x86. -/
def bpf_x86_shrq (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (h : c.Valid true) : X86StateEquiv m := cert m hc true .right d c h
/-- x86/bpf_x86_alu.c:instantiate_sarl/emit_sarl_x86. -/
def bpf_x86_sarl (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (h : c.Valid false) : X86StateEquiv m := cert m hc false .arithmetic d c h
/-- x86/bpf_x86_alu.c:instantiate_sarq/emit_sarq_x86. -/
def bpf_x86_sarq (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (h : c.Valid true) : X86StateEquiv m := cert m hc true .arithmetic d c h

end Kinsn.ModuleAluShift
