import KinsnLean4.Kinsn.ModuleRotateOne
import KinsnLean4.Kinsn.ModuleControlDispatch
import KinsnLean4.Kinsn.Rotate

namespace Kinsn.ModuleX86Rotate
open ModuleRotateOne (bits width repeated iterateValue)

inductive Kind where
  | roll | rolq | rorxl
  deriving DecidableEq, Repr

def Kind.is64 (kind : Kind) : Bool := decide (kind = .rolq)

def depth (kind : Kind) : Nat := if kind.is64 then 6 else 5

inductive Operand where
  | imm (src : BPF.Reg) (n : Nat)
  | cl

def Operand.Valid (kind : Kind) (d : BPF.Reg) : Operand → Prop
  | .imm r n => n < bits kind.is64 ∧ (kind = .rorxl ∨ (r = d ∧ 0 < n))
  | .cl => kind ≠ .rorxl

def Operand.src (d : BPF.Reg) : Operand → BPF.Reg
  | .imm r _ => r | .cl => d

def Operand.number (kind : Kind) (rf : BPF.RegFile) : Operand → Nat
  | .imm _ n => n | .cl => (rf .r4).toNat % bits kind.is64

def value (is64 : Bool) (v : BitVec 64) (n : Nat) : BitVec 64 :=
  BitVec.setWidth 64 ((BitVec.setWidth (bits is64) v).rotateLeft n)

/-- x86/bpf_x86_rotate.c:instantiate_rotate_leaf, a width-correct initial
    copy followed by n copies of the local, branch-based one-bit rotate. -/
def leaf (is64 : Bool) (d r : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  [.core (.alu .mov (width is64) d (.reg r))] ++ repeated is64 d n

def effect (is64 : Bool) (d r : BPF.Reg) (n : Nat) (s : BPF.State) : BPF.State :=
  { s with regs := (BPF.RegFile.set s.regs d
    (iterateValue is64 (BitVec.setWidth 64 (BitVec.setWidth (bits is64) (s.regs r))) n)) }

theorem leaf_exec (is64 : Bool) (d r : BPF.Reg) (n : Nat) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (leaf is64 d r n ++ tail) s = BPF.mexec tail (effect is64 d r n s) := by
  simp only [leaf, List.cons_append, List.nil_append,
    BPF.mexec, BPF.MInsn.step]
  rw [ModuleRotateOne.repeated_exec]
  cases is64 <;>
    simp [effect, BPF.Insn.step, BPF.AluOp.eval, width, bits,
      BPF.RegFile.set_set_same]

theorem leaf_writes (is64 : Bool) (d r t : BPF.Reg) (n : Nat) :
    t ∈ BPF.mwrites (leaf is64 d r n) → t = d := by
  simp only [leaf, BPF.mwrites, List.flatMap_append, List.mem_append]
  intro ht
  rcases ht with ht | ht
  · simpa [BPF.MInsn.writes, BPF.Insn.dstReg] using ht
  · exact ModuleRotateOne.repeated_writes is64 d t n ht

/-- x86/bpf_x86_rotate.c:instantiate_rol/instantiate_rotate32. CL's balanced
    JSET tree completes its decisions before the selected leaf writes dst. -/
def bpf (kind : Kind) (d : BPF.Reg) (operand : Operand) : List BPF.MInsn :=
  match operand with
  | .imm r n => leaf kind.is64 d r n
  | .cl => ModuleControlDispatch.tree .r4 (leaf kind.is64 d d) (depth kind) 0

/-- x86/bpf_x86_rotate.c:emit_rol_imm_x86/emit_rol_cl_x86 and
    emit_rotate32_x86. RORXL emits RORX by (-n)&31, exactly ROL by n. -/
def native (m : X86RegMap) (kind : Kind) (d : BPF.Reg) (operand : Operand) :
    List X86.MInsn :=
  match operand with
  | .imm r n => if kind = .rorxl then
      [.rorx32 (m.map d) (m.map r) (BitVec.ofNat 8 ((32-n)%32)).toNat]
      else [.shiftImmWidth (bits kind.is64) .rol (m.map d) (BitVec.ofNat 8 n).toNat]
  | .cl => [.rolCL (bits kind.is64) (m.map d)]

def spec (kind : Kind) (d : BPF.Reg) (operand : Operand) (s : Outcome) : Outcome :=
  { s with regs := (BPF.RegFile.set s.regs d
    (value kind.is64 (s.regs (operand.src d)) (operand.number kind s.regs))) }

theorem bpf_correct (kind : Kind) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid kind d) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf kind d operand) s) = spec kind d operand (observeBpf s) := by
  cases operand with
  | imm r n =>
    have h := leaf_exec kind.is64 d r n s []
    simp only [List.append_nil, BPF.mexec] at h
    rw [bpf, h]
    simp [effect, ModuleRotateOne.iterate_rotate _ _ n hv.1, spec, value,
      Operand.src, Operand.number, observeBpf]
  | cl =>
    have h := ModuleControlDispatch.exec_tree .r4 (leaf kind.is64 d d)
      (effect kind.is64 d d) (leaf_exec kind.is64 d d) (depth kind) 0 s []
    simp only [List.append_nil, BPF.mexec] at h
    rw [bpf, h, ModuleDispatch.selected_eq _ _ _ (by cases kind <;> decide)]
    have hn : (s.regs .r4).toNat % 2^depth kind < bits kind.is64 := by
      cases kind <;> exact Nat.mod_lt _ (by decide)
    have he : 2^depth kind = bits kind.is64 := by cases kind <;> decide
    rw [he] at hn
    simp [effect, ModuleRotateOne.iterate_rotate _ _ _ hn, he,
      spec, value, Operand.src, Operand.number, observeBpf]

theorem encoded_count (kind : Kind) (n : Nat) (hn : n < bits kind.is64) :
    (BitVec.ofNat 8 n).toNat = n := by
  simp only [BitVec.toNat_ofNat]
  apply Nat.mod_eq_of_lt
  cases kind <;> simp [Kind.is64, bits] at hn <;> omega

theorem rorx_value (v : BitVec 64) (n : Nat) (hn : n < 32) :
    BitVec.setWidth 64 ((BitVec.setWidth 32 v).rotateRight
      ((BitVec.ofNat 8 ((32-n)%32)).toNat % 32)) = value false v n := by
  have hc : (BitVec.ofNat 8 ((32-n)%32)).toNat = (32-n)%32 := by
    simp only [BitVec.toNat_ofNat]
    apply Nat.mod_eq_of_lt
    have h := Nat.mod_lt (32-n) (by decide : 0 < 32)
    omega
  rw [hc, BitVec.rotateRight_mod_eq_rotateRight]
  by_cases hz : n = 0
  · subst n
    simp [value, bits, BitVec.rotateLeft, BitVec.rotateLeftAux,
      BitVec.rotateRight, BitVec.rotateRightAux,
      BitVec.ushiftRight_eq_zero (Nat.le_refl 32)]
  · rw [BitVec.rotateRight_mod_eq_rotateRight]
    change BitVec.setWidth 64 ((BitVec.setWidth 32 v).rotateRight (32-n)) =
      BitVec.setWidth 64 ((BitVec.setWidth 32 v).rotateLeft n)
    rw [← Bits.rotateLeft_eq_rotateRight _ n hn (by omega)]

theorem native_correct (m : X86RegMap) (hc : m.map .r4 = .rcx) (kind : Kind)
    (d : BPF.Reg) (operand : Operand) (hv : operand.Valid kind d) (s : X86.State) :
    observeX86 m (X86.mexec (native m kind d operand) s) =
      spec kind d operand (observeX86 m s) := by
  cases operand with
  | imm r n =>
    by_cases hr : kind = .rorxl
    · subst kind
      simp only [native, ↓reduceIte, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
      rw [x86_observe_set, rorx_value _ _ hv.1]
      rfl
    · obtain ⟨hn, hform⟩ := hv
      obtain ⟨hd, _⟩ := hform.resolve_left hr
      subst r
      simp only [native, if_neg hr, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step,
        encoded_count kind n hn]
      rw [x86_observe_set]
      cases kind <;>
        simp_all [spec, value, Kind.is64, bits, Operand.src, Operand.number, X86.writeWidth,
          observeX86, BitVec.setWidth_setWidth_of_le]
  | cl =>
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
    rw [x86_observe_set]
    cases kind <;>
      simp_all [spec, value, Kind.is64, bits, Operand.src, Operand.number,
        X86.writeWidth, observeX86, BitVec.setWidth_setWidth_of_le]

def cert (m : X86RegMap) (hc : m.map .r4 = .rcx) (kind : Kind) (d : BPF.Reg)
    (operand : Operand) (hv : operand.Valid kind d) : X86StateEquiv m where
  spec := spec kind d operand
  bpf := bpf kind d operand
  native := native m kind d operand
  writeSet := [d]
  bpfCorrect := bpf_correct kind d operand hv
  nativeCorrect := native_correct m hc kind d operand hv
  bpfWrites := by
    intro t ht
    cases operand with
    | imm r n => exact List.mem_singleton.mpr (leaf_writes kind.is64 d r t n ht)
    | cl => exact List.mem_singleton.mpr (ModuleControlDispatch.writes_tree .r4
        (leaf kind.is64 d d) (depth kind) 0 d (fun n t h => leaf_writes kind.is64 d d t n h) t ht)
  nativeWrites := by
    cases operand with
    | imm r n => by_cases h : kind = .rorxl <;>
        simp [native, h, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]
    | cl => simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_rotate.c:instantiate_roll/emit_roll_x86. -/
def bpf_x86_roll (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (o : Operand)
    (hv : o.Valid .roll d) : X86StateEquiv m := cert m hc .roll d o hv
/-- x86/bpf_x86_rotate.c:instantiate_rolq/emit_rolq_x86. -/
def bpf_x86_rolq (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (o : Operand)
    (hv : o.Valid .rolq d) : X86StateEquiv m := cert m hc .rolq d o hv
/-- x86/bpf_x86_rotate.c:instantiate_rotate32/emit_rotate32_x86. -/
def bpf_x86_rorxl (m : X86RegMap) (hc : m.map .r4 = .rcx) (d r : BPF.Reg)
    (n : Nat) (hn : n < 32) : X86StateEquiv m := cert m hc .rorxl d (.imm r n) ⟨hn, Or.inl rfl⟩

end Kinsn.ModuleX86Rotate
