import KinsnLean4.Kinsn.ModuleByteAlu

namespace Kinsn.ModuleShd
open ModuleBmiShift (bits width)

def slot : BitVec 64 := -8

/-- x86/bpf_x86_shd.c:instantiate_shd_imm: preserve one selected live temporary,
    copy src before dst changes (including src=dst), perform the two shifts and
    OR, then restore. Ordinary and ARCH forms use the same live BPF operands. -/
def bpf (is64 left : Bool) (d r t : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  [.store 8 .r10 (.reg t) slot, .core (.alu .mov (width is64) t (.reg r)),
    .core (.alu (if left then .lsh else .rsh) (width is64) d (BPF.immN n)),
    .core (.alu (if left then .rsh else .lsh) (width is64) t (BPF.immN (bits is64 - n))),
    .core (.alu .or (width is64) d (.reg t)), .load 8 t .r10 slot]

/-- x86/bpf_x86_shd.c:emit_shd_imm_x86: the optimized SHLD/SHRD instruction,
    bracketed by precisely the same mapped temporary save/restore. -/
def native (m : X86RegMap) (is64 left : Bool) (d r t : BPF.Reg) (n : Nat) :
    List X86.MInsn :=
  [.store 8 (m.map t) (m.map .r10) slot,
    .shd (bits is64) left (m.map d) (m.map r) (BitVec.ofNat 8 n).toNat,
    .load 8 (m.map t) (m.map .r10) slot]

def value (is64 left : Bool) (a b : BitVec 64) (n : Nat) : BitVec 64 :=
  let a := BitVec.setWidth (bits is64) a
  let b := BitVec.setWidth (bits is64) b
  BitVec.setWidth 64 (if left then (a <<< n) ||| (b >>> (bits is64 - n))
    else (a >>> n) ||| (b <<< (bits is64 - n)))

def spec (is64 left : Bool) (d r t : BPF.Reg) (n : Nat) (s : Outcome) : Outcome :=
  ModuleByteAlu.finish d t (value is64 left (s.regs d) (s.regs r) n) s

theorem bpf_correct (is64 left : Bool) (d r t : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits is64) (ht : t ≠ d) (hf : t ≠ .r10)
    (hd : d ≠ .r10) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf is64 left d r t n) s) =
      spec is64 left d r t n (observeBpf s) := by
  have hcomp : bits is64 - n < bits is64 := by omega
  cases is64 <;> cases left <;>
    simp [bpf, width, bits, value, spec, ModuleByteAlu.finish, ModuleByteAlu.slot,
      slot, ModuleMemory.storeSpec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
      BPF.AluOp.eval, BPF.Src.eval, BPF.immN,
      observeBpf, Machine.State.read, Machine.State.write, Machine.State.set,
      BPF.RegFile.set, ht, Ne.symm ht, hf, Ne.symm hf, hd, Ne.symm hd] at hb hcomp ⊢
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set, Ne.symm, Nat.mod_eq_of_lt,
    ModuleAluShift.narrow_right]

theorem native_correct (m : X86RegMap) (is64 left : Bool) (d r t : BPF.Reg)
    (n : Nat) (hn : 0 < n) (hb : n < bits is64) (hd : d ≠ .r10) (s : X86.State) :
    observeX86 m (X86.mexec (native m is64 left d r t n) s) =
      spec is64 left d r t n (observeX86 m s) := by
  have he := ModuleAluShift.encoded_count is64 n hb
  have hm := Nat.mod_eq_of_lt hb
  simp [native, spec, value, he, hm, Nat.ne_of_gt hn, ModuleByteAlu.finish,
    ModuleByteAlu.slot, slot, ModuleMemory.storeSpec, X86.mexec_cons,
    X86.mexec_nil, X86.MInsn.step, observeX86, Machine.State.read,
    Machine.State.write, Machine.State.set, m.inj.eq_iff, Ne.symm hd]
  funext q
  by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set]

def cert (m : X86RegMap) (is64 left : Bool) (d r t : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits is64) (ht : t ≠ d) (hf : t ≠ .r10)
    (hd : d ≠ .r10) : X86StateEquiv m where
  spec := spec is64 left d r t n
  bpf := bpf is64 left d r t n
  native := native m is64 left d r t n
  writeSet := [d, t]
  bpfCorrect := bpf_correct is64 left d r t n hn hb ht hf hd
  nativeCorrect := native_correct m is64 left d r t n hn hb hd
  bpfWrites := by
    simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg, or_comm, or_left_comm]
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff, or_comm]

/-- x86/bpf_x86_shd.c:instantiate_shldl_imm/emit_shldl_imm_x86. -/
def bpf_x86_shldl (m : X86RegMap) (d r t : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits false) (ht : t ≠ d) (hf : t ≠ .r10)
    (hd : d ≠ .r10) : X86StateEquiv m := cert m false true d r t n hn hb ht hf hd
/-- x86/bpf_x86_shd.c:instantiate_shldq_imm/emit_shldq_imm_x86. -/
def bpf_x86_shldq (m : X86RegMap) (d r t : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits true) (ht : t ≠ d) (hf : t ≠ .r10)
    (hd : d ≠ .r10) : X86StateEquiv m := cert m true true d r t n hn hb ht hf hd
/-- x86/bpf_x86_shd.c:instantiate_shrdl_imm/emit_shrdl_imm_x86. -/
def bpf_x86_shrdl (m : X86RegMap) (d r t : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits false) (ht : t ≠ d) (hf : t ≠ .r10)
    (hd : d ≠ .r10) : X86StateEquiv m := cert m false false d r t n hn hb ht hf hd
/-- x86/bpf_x86_shd.c:instantiate_shrdq_imm/emit_shrdq_imm_x86. -/
def bpf_x86_shrdq (m : X86RegMap) (d r t : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits true) (ht : t ≠ d) (hf : t ≠ .r10)
    (hd : d ≠ .r10) : X86StateEquiv m := cert m true false d r t n hn hb ht hf hd

end Kinsn.ModuleShd
