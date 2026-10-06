import KinsnLean4.Kinsn.ModuleMovbeWide

namespace Kinsn.ModuleMovzx

inductive Operand where
  | reg (r : BPF.Reg)
  | mem (indexed : Bool) (base index : BPF.Reg) (scale : Nat) (off : BitVec 64)

/-- The decoder restricts every SIB scale to 0..3. Direct loads ignore scale. -/
def Operand.Valid : Operand → Prop
  | .reg _ => True
  | .mem indexed _ _ scale _ => indexed = true → scale ≤ 3

def bits (word : Bool) : Nat := if word then 16 else 8
def bytes (word : Bool) : Nat := if word then 2 else 1

def value (word : Bool) (v : BitVec 64) : BitVec 64 :=
  BitVec.setWidth 64 (BitVec.setWidth (bits word) v)

/-- x86/bpf_x86_mov.c:instantiate_movzx_rr, instantiate_mov_mem and
    instantiate_mov_sib/instantiate_mov_address. Address construction matches
    the already proved alias-aware sequence in ModuleMovbeWide.address. -/
def bpf (word : Bool) (d : BPF.Reg) (operand : Operand) : List BPF.MInsn :=
  match operand with
  | .reg r => [.core (.alu .mov .w32 d (.reg r)),
      .core (.alu .and .w32 d (.imm (BitVec.signExtend 64 (Bits.lowMask 32 (bits word)))))]
  | .mem indexed b i scale off =>
      (if indexed then (ModuleMovbeWide.address d b i scale).map BPF.MInsn.core else []) ++
      [.load (bytes word) d (if indexed then d else b) off]

/-- x86/bpf_x86_mov.c:emit_movzx_rr_x86, emit_mov_mem_x86 and
    emit_mov_sib_x86: MOVZX r32,r8/r16 or the same memory-source opcode. -/
def native (m : X86RegMap) (word : Bool) (d : BPF.Reg) (operand : Operand) :
    List X86.MInsn :=
  match operand with
  | .reg r => [.movzx (bits word) (m.map d) (m.map r)]
  | .mem indexed b i scale off => if indexed then
      [.loadIndex (bytes word) (m.map d) (m.map b) (m.map i) scale off false]
      else [.load (bytes word) (m.map d) (m.map b) off]

def spec (word : Bool) (d : BPF.Reg) (operand : Operand) (s : Outcome) : Outcome :=
  match operand with
  | .reg r => ModuleRegister.unarySpec d r (value word) s
  | .mem indexed b i scale off =>
      let a := s.regs b + (if indexed then s.regs i <<< scale else 0) + off
      let n := bytes word
      let v := Machine.loadLE s.mem a n
      { regs := s.regs.set d v, mem := s.mem, trace := s.trace ++ [.read a n v] }

theorem mask_value (word : Bool) (v : BitVec 64) :
    BitVec.setWidth 64 (BitVec.setWidth 32 v) &&&
      BitVec.setWidth 64 (Bits.lowMask 32 (bits word)) = value word v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  cases word <;>
    simp only [value, bits, ↓reduceIte, BitVec.getLsbD_setWidth, BitVec.getLsbD_and,
      Bits.getLsbD_lowMask]
  all_goals interval_cases i <;> simp

theorem bpf_correct (word : Bool) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf word d operand) s) = spec word d operand (observeBpf s) := by
  cases operand with
  | reg r =>
    have hmask : BitVec.setWidth 32 (BitVec.signExtend 64 (Bits.lowMask 32 (bits word))) =
        Bits.lowMask 32 (bits word) := by cases word <;> decide
    simp [bpf, spec, ModuleRegister.unarySpec, observeBpf, BPF.mexec,
      BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, hmask,
      BitVec.setWidth_setWidth_of_le, mask_value, BPF.RegFile.set_set_same]
  | mem indexed b i scale off =>
    cases indexed
    · simp [bpf, spec, observeBpf, BPF.mexec, BPF.MInsn.step,
        Machine.State.set, Machine.State.read]
      rfl
    · have hs : scale ≤ 3 := hv rfl
      simp only [bpf, ↓reduceIte, ModuleDispatch.exec_core_tail]
      rw [ModuleMovbeWide.address_exec d b i scale hs]
      simp only [spec, observeBpf, BPF.mexec, BPF.MInsn.step,
        Machine.State.set, Machine.State.read, BPF.RegFile.set_same, ↓reduceIte]
      congr 1
      funext q; by_cases h : q = d <;> simp [BPF.RegFile.set, h]

theorem native_correct (m : X86RegMap) (word : Bool) (d : BPF.Reg) (operand : Operand)
    (s : X86.State) :
    observeX86 m (X86.mexec (native m word d operand) s) =
      spec word d operand (observeX86 m s) := by
  cases operand with
  | reg r =>
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
    rw [x86_observe_set]
    rfl
  | mem indexed b i scale off =>
    cases indexed <;>
      simp only [native, Bool.false_eq_true, ↓reduceIte, X86.mexec_cons, X86.mexec_nil,
        X86.MInsn.step]
    all_goals rw [x86_observe_set]
    all_goals simp [spec, observeX86, Machine.State.read]

def cert (m : X86RegMap) (word : Bool) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) : X86StateEquiv m where
  spec := spec word d operand
  bpf := bpf word d operand
  native := native m word d operand
  writeSet := [d]
  bpfCorrect := bpf_correct word d operand hv
  nativeCorrect := native_correct m word d operand
  bpfWrites := by
    intro t ht
    cases operand with
    | reg r => simpa [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
    | mem indexed b i scale off =>
      cases indexed
      · simpa [bpf, BPF.mwrites, BPF.MInsn.writes] using ht
      · simp only [bpf, ↓reduceIte, BPF.mwrites, List.flatMap_append,
          List.mem_append] at ht
        rcases ht with ht | ht
        · exact List.mem_singleton.mpr (ModuleMovbeWide.address_writes d b i t scale
            (by simpa [BPF.writes, BPF.mwrites, List.flatMap_map, BPF.MInsn.writes,
              List.mem_flatMap, eq_comm] using ht))
        · simpa [BPF.MInsn.writes] using ht
  nativeWrites := by
    cases operand with
    | reg r => simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]
    | mem indexed b i scale off => cases indexed <;>
        simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_mov.c:instantiate_movzbl/emit_movzbl_x86, all form tags. -/
def bpf_x86_movzbl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) : X86StateEquiv m := cert m false d operand hv
/-- x86/bpf_x86_mov.c:instantiate_movzwl/emit_movzwl_x86, all form tags. -/
def bpf_x86_movzwl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) : X86StateEquiv m := cert m true d operand hv

end Kinsn.ModuleMovzx
