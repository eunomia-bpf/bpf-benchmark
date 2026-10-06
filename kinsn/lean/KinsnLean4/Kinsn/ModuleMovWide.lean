import KinsnLean4.Kinsn.ModuleMovzx
import KinsnLean4.Kinsn.ModuleMovStore

namespace Kinsn.ModuleMovWide

inductive Operand where
  | reg (r : BPF.Reg)
  | imm (v : BitVec 32)
  | mem (indexed : Bool) (base index : BPF.Reg) (scale : Nat) (off : BitVec 64)
  | store (base : BPF.Reg) (off : BitVec 64) (src : ModuleMovStore.Source)

def Operand.Valid : Operand → Prop
  | .mem indexed _ _ scale _ => indexed = true → scale ≤ 3
  | _ => True

def bytes (is64 : Bool) : Nat := if is64 then 8 else 4
def width (is64 : Bool) : BPF.Width := if is64 then .w64 else .w32
def value (is64 : Bool) (v : BitVec 64) : BitVec 64 :=
  if is64 then v else BitVec.setWidth 64 (BitVec.setWidth 32 v)

/-- x86/bpf_x86_mov.c:instantiate_movl/instantiate_movq: register/immediate
    moves, direct/indexed replacing loads, and low-lane stores. Removed frame
    form 8 had no BPF-register representation of RSP and is rejected. -/
def bpf (is64 : Bool) (d : BPF.Reg) (operand : Operand) : List BPF.MInsn :=
  match operand with
  | .reg r => [.core (.alu .mov (width is64) d (.reg r))]
  | .imm v => [.core (.alu .mov (width is64) d (.imm (BitVec.signExtend 64 v)))]
  | .mem indexed b i scale off =>
      (if indexed then (ModuleMovbeWide.address d b i scale).map BPF.MInsn.core else []) ++
      [.load (bytes is64) d (if indexed then d else b) off]
  | .store b off src => ModuleMovStore.bpf (bytes is64) b off src

/-- x86/bpf_x86_mov.c:emit_movl_x86/emit_movq_x86 and their shared RR,
    immediate, MEM, SIB and STORE helpers. MOVL imm32 is zero-extended;
    MOVQ's C7 imm32 is sign-extended. -/
def native (m : X86RegMap) (is64 : Bool) (d : BPF.Reg) (operand : Operand) :
    List X86.MInsn :=
  match operand with
  | .reg r => if is64 then [.core (.movRR (m.map d) (m.map r))]
      else [.mov32 (m.map d) (m.map r)]
  | .imm v => if is64 then [.core (.movImm32 (m.map d) v)] else [.movImm32Z (m.map d) v]
  | .mem indexed b i scale off => if indexed then
      [.loadIndex (bytes is64) (m.map d) (m.map b) (m.map i) scale off false]
      else [.load (bytes is64) (m.map d) (m.map b) off]
  | .store b off src => ModuleMovStore.native m (bytes is64) b off src

def spec (is64 : Bool) (d : BPF.Reg) (operand : Operand) (s : Outcome) : Outcome :=
  match operand with
  | .reg r => ModuleRegister.unarySpec d r (value is64) s
  | .imm v => { s with regs := (BPF.RegFile.set s.regs d (value is64 (BitVec.signExtend 64 v))) }
  | .mem indexed b i scale off =>
      let a := s.regs b + (if indexed then s.regs i <<< scale else 0) + off
      let n := bytes is64
      let v := Machine.loadLE s.mem a n
      { regs := s.regs.set d v, mem := s.mem, trace := s.trace ++ [.read a n v] }
  | .store b off src => ModuleMovStore.spec (bytes is64) b off src s

theorem immediate32 (v : BitVec 32) :
    BitVec.setWidth 32 (BitVec.signExtend 64 v) = v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_setWidth, BitVec.getLsbD_signExtend]
  simp [hi, show i < 64 by omega]

theorem bpf_correct (is64 : Bool) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf is64 d operand) s) = spec is64 d operand (observeBpf s) := by
  cases operand with
  | reg r => cases is64 <;>
      simp [bpf, spec, width, value, ModuleRegister.unarySpec, observeBpf,
        BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval]
  | imm v => cases is64 <;>
      simp [bpf, spec, width, value, observeBpf,
        BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval]
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
  | store b off src => exact ModuleMovStore.bpf_correct (bytes is64) b off src s

theorem native_correct (m : X86RegMap) (is64 : Bool) (d : BPF.Reg) (operand : Operand)
    (s : X86.State) :
    observeX86 m (X86.mexec (native m is64 d operand) s) =
      spec is64 d operand (observeX86 m s) := by
  cases operand with
  | reg r =>
    cases is64
    · simp only [native, Bool.false_eq_true, ↓reduceIte, X86.mexec_cons,
        X86.mexec_nil, X86.MInsn.step]
      rw [x86_observe_set]
      rfl
    · change observeX86 m (s.set (m.map d) (s.regs (m.map r))) = _
      rw [x86_observe_set]
      rfl
  | imm v =>
    cases is64
    · simp only [native, Bool.false_eq_true, ↓reduceIte, X86.mexec_cons,
        X86.mexec_nil, X86.MInsn.step]
      rw [x86_observe_set]
      simp [spec, value, immediate32]
    · change observeX86 m (s.set (m.map d) (BitVec.signExtend 64 v)) = _
      rw [x86_observe_set]
      rfl
  | mem indexed b i scale off =>
    cases indexed <;>
      simp only [native, Bool.false_eq_true, ↓reduceIte, X86.mexec_cons,
        X86.mexec_nil, X86.MInsn.step]
    all_goals rw [x86_observe_set]
    all_goals simp [spec, observeX86, Machine.State.read]
  | store b off src => exact ModuleMovStore.native_correct m (bytes is64) b off src s

def writes (d : BPF.Reg) : Operand → List BPF.Reg
  | .store .. => [] | _ => [d]

def cert (m : X86RegMap) (is64 : Bool) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) : X86StateEquiv m where
  spec := spec is64 d operand
  bpf := bpf is64 d operand
  native := native m is64 d operand
  writeSet := writes d operand
  bpfCorrect := bpf_correct is64 d operand hv
  nativeCorrect := native_correct m is64 d operand
  bpfWrites := by
    intro t ht
    cases operand with
    | reg r => simpa [bpf, writes, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
    | imm v => simpa [bpf, writes, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
    | mem indexed b i scale off =>
      cases indexed
      · simpa [bpf, writes, BPF.mwrites, BPF.MInsn.writes] using ht
      · simp only [bpf, ↓reduceIte, BPF.mwrites, List.flatMap_append, List.mem_append] at ht
        rcases ht with ht | ht
        · exact List.mem_singleton.mpr (ModuleMovbeWide.address_writes d b i t scale
            (by simpa [BPF.writes, List.flatMap_map, BPF.MInsn.writes,
              List.mem_flatMap, eq_comm] using ht))
        · simpa [writes, BPF.MInsn.writes] using ht
    | store b off src => simp [bpf, ModuleMovStore.bpf, BPF.mwrites, BPF.MInsn.writes] at ht
  nativeWrites := by
    cases operand with
    | reg r => cases is64 <;>
        simp [native, writes, X86.mwrites, X86.MInsn.writes, X86.Insn.dstReg, m.inj.eq_iff]
    | imm v => cases is64 <;>
        simp [native, writes, X86.mwrites, X86.MInsn.writes, X86.Insn.dstReg, m.inj.eq_iff]
    | mem indexed b i scale off => cases indexed <;>
        simp [native, writes, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]
    | store b off src => cases src <;>
        simp [native, writes, ModuleMovStore.native, X86.mwrites, X86.MInsn.writes]

/-- x86/bpf_x86_mov.c:instantiate_movl/emit_movl_x86, every accepted tag. -/
def bpf_x86_movl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) : X86StateEquiv m := cert m false d operand hv
/-- x86/bpf_x86_mov.c:instantiate_movq/emit_movq_x86, every accepted tag. -/
def bpf_x86_movq (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (hv : operand.Valid) : X86StateEquiv m := cert m true d operand hv

end Kinsn.ModuleMovWide
