import KinsnLean4.Kinsn.ModuleAluMemory

namespace Kinsn.ModuleAluWide
open ModuleWideAlu (Kind width bits value)
open ModuleMovStore (Source)

/-- The ordinary/ARCH RR and IMM tags share these live-register semantics.
    Memory tags use a writable temporary distinct from destination and index;
    x86_alu_mem_temp additionally excludes base and picks the lowest register. -/
inductive Operand where
  | scalar (src : Source)
  | memory (indexed : Bool) (base index temp : BPF.Reg) (scale : Nat) (off : BitVec 16)

def Operand.Valid (d : BPF.Reg) : Operand → Prop
  | .scalar _ => d ≠ .r10
  | .memory _ _ i t scale _ =>
      d ≠ .r10 ∧ scale ≤ 3 ∧ t ≠ d ∧ t ≠ i ∧ t ≠ .r10

/-- x86/bpf_x86_alu.c:instantiate_x86_alu: one live-register ALU32/ALU64
    instruction for RR/IMM (including ARCH), without scratch save/restore. -/
def scalarBpf (kind : Kind) (w32 : Bool) (d : BPF.Reg) (src : Source) : List BPF.MInsn :=
  [.core (.alu kind.bpf (width w32) d src.bpf)]

/-- x86/bpf_x86_alu.c:emit_x86_alu: optimized reg/reg or sign-extended imm32
    instruction, with program-specific mapping for every tag. -/
def scalarNative (m : X86RegMap) (kind : Kind) (w32 : Bool) (d : BPF.Reg)
    (src : Source) : List X86.MInsn :=
  match src with
  | .reg r => [.aluNarrow kind.native (bits w32) (m.map d) (m.map r)]
  | .imm v => [.aluImmNarrow kind.native (bits w32) (m.map d) (BitVec.signExtend 64 v)]

def scalarSpec (kind : Kind) (w32 : Bool) (d : BPF.Reg) (src : Source) (s : Outcome) :
    Outcome :=
  { s with regs := s.regs.set d (value kind w32 (s.regs d) (src.word s.regs)) }

theorem scalar_bpf_correct (kind : Kind) (w32 : Bool) (d : BPF.Reg)
    (src : Source) (s : BPF.State) :
    observeBpf (BPF.mexec (scalarBpf kind w32 d src) s) =
      scalarSpec kind w32 d src (observeBpf s) := by
  cases src <;> cases w32 <;>
    simp [scalarBpf, scalarSpec, value, Source.bpf, Source.word, width,
      BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.Src.eval, observeBpf]

theorem scalar_native_correct (m : X86RegMap) (kind : Kind) (w32 : Bool)
    (d : BPF.Reg) (src : Source) (s : X86.State) :
    observeX86 m (X86.mexec (scalarNative m kind w32 d src) s) =
      scalarSpec kind w32 d src (observeX86 m s) := by
  cases src <;>
    simp only [scalarNative, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  all_goals rw [x86_observe_set]
  all_goals simp [scalarSpec, Source.word, observeX86, ModuleWideAlu.value_native]

def scalarCert (m : X86RegMap) (kind : Kind) (w32 : Bool) (d : BPF.Reg)
    (src : Source) : X86StateEquiv m where
  spec := scalarSpec kind w32 d src
  bpf := scalarBpf kind w32 d src
  native := scalarNative m kind w32 d src
  writeSet := [d]
  bpfCorrect := scalar_bpf_correct kind w32 d src
  nativeCorrect := scalar_native_correct m kind w32 d src
  bpfWrites := by simp [scalarBpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by
    cases src <;> simp [scalarNative, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- All decoded scalar, direct-memory and SIB forms. The only rejected register
    numbers cannot be expressed as stock-verifier BPF operands: destinations
    R10 (read-only frame pointer) and register numbers above R10. -/
def cert (m : X86RegMap) (kind : Kind) (w32 : Bool) (d : BPF.Reg)
    (operand : Operand) (h : operand.Valid d) : X86StateEquiv m :=
  match operand with
  | .scalar src => scalarCert m kind w32 d src
  | .memory indexed b i t scale off =>
      ModuleAluMemory.certificate m kind w32 indexed d b i t scale
        (BitVec.signExtend 64 off) h.2.1 h.2.2.1 h.2.2.2.1 h.2.2.2.2 h.1

/-- x86/bpf_x86_alu.c:instantiate_addl/emit_addl_x86: all accepted tags. -/
def bpf_x86_addl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .add true d operand h
/-- x86/bpf_x86_alu.c:instantiate_addq/emit_addq_x86: all accepted tags. -/
def bpf_x86_addq (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .add false d operand h
/-- x86/bpf_x86_alu.c:instantiate_subl/emit_subl_x86: all accepted tags. -/
def bpf_x86_subl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .sub true d operand h
/-- x86/bpf_x86_alu.c:instantiate_subq/emit_subq_x86: all accepted tags. -/
def bpf_x86_subq (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .sub false d operand h
/-- x86/bpf_x86_alu.c:instantiate_andl/emit_andl_x86: all accepted tags. -/
def bpf_x86_andl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .and true d operand h
/-- x86/bpf_x86_alu.c:instantiate_andq/emit_andq_x86: all accepted tags. -/
def bpf_x86_andq (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .and false d operand h
/-- x86/bpf_x86_alu.c:instantiate_orl/emit_orl_x86: all accepted tags. -/
def bpf_x86_orl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .or true d operand h
/-- x86/bpf_x86_alu.c:instantiate_orq/emit_orq_x86: all accepted tags. -/
def bpf_x86_orq (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .or false d operand h
/-- x86/bpf_x86_alu.c:instantiate_xorl/emit_xorl_x86: all accepted tags. -/
def bpf_x86_xorl (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .xor true d operand h
/-- x86/bpf_x86_alu.c:instantiate_xorq/emit_xorq_x86: all accepted tags. -/
def bpf_x86_xorq (m : X86RegMap) (d : BPF.Reg) (operand : Operand)
    (h : operand.Valid d) : X86StateEquiv m := cert m .xor false d operand h

end Kinsn.ModuleAluWide
