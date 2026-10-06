/-
  The x86-64 subset a BPF JIT emits for kinsns.  Flags are not modelled.

  Fidelity points: shift and rotate counts are masked to 6 bits at 64-bit
  operand size, and `imm32` operands are sign-extended, so a 64-bit mask that
  does not fit a signed 32-bit field must be materialised with `MOVABS`.
-/
import KinsnLean4.Util.Bits

namespace X86

inductive GPReg where
  | rax | rcx | rdx | rbx | rsp | rbp | rsi | rdi
  | r8 | r9 | r10 | r11 | r12 | r13 | r14 | r15
  deriving DecidableEq, Repr, Inhabited

abbrev RegFile := GPReg → BitVec 64

def RegFile.set (rf : RegFile) (r : GPReg) (v : BitVec 64) : RegFile :=
  fun r' => if r' = r then v else rf r'

@[simp]
theorem RegFile.set_same (rf : RegFile) (r : GPReg) (v : BitVec 64) :
    rf.set r v r = v := by simp [RegFile.set]

@[simp]
theorem RegFile.set_other (rf : RegFile) (r r' : GPReg) (v : BitVec 64)
    (h : r' ≠ r) : rf.set r v r' = rf r' := by simp [RegFile.set, h]

inductive AluOp where
  | add | sub | or | and | xor
  deriving DecidableEq, Repr

def AluOp.eval : AluOp → BitVec 64 → BitVec 64 → BitVec 64
  | .add, a, b => a + b
  | .sub, a, b => a - b
  | .or, a, b => a ||| b
  | .and, a, b => a &&& b
  | .xor, a, b => a ^^^ b

inductive ShiftOp where
  | shl | shr | sar | rol | ror
  deriving DecidableEq, Repr

/-- Includes the hardware's `count & 0x3f` masking. -/
def ShiftOp.eval (op : ShiftOp) (v : BitVec 64) (count : Nat) : BitVec 64 :=
  let n := count % 64
  match op with
  | .shl => v <<< n
  | .shr => v >>> n
  | .sar => v.sshiftRight n
  | .rol => v.rotateLeft n
  | .ror => v.rotateRight n

/-- `BEXTR`: start index in `ctrl[7:0]`, field length in `ctrl[15:8]`. -/
def bextr (src ctrl : BitVec 64) : BitVec 64 :=
  let start := (BitVec.setWidth 8 ctrl).toNat
  let len := (BitVec.setWidth 8 (ctrl >>> 8)).toNat
  (src >>> start) &&& Bits.lowMask 64 len

/-- The `BEXTR` control word for extracting `len` bits at `start`. -/
def bextrCtrl (start len : Nat) : BitVec 64 :=
  BitVec.ofNat 64 (start % 256 + 256 * (len % 256))

inductive Insn where
  | movRR (dst src : GPReg)
  /-- `MOV r64, imm32` — the immediate is sign-extended. -/
  | movImm32 (dst : GPReg) (imm : BitVec 32)
  /-- `MOVABS r64, imm64`. -/
  | movabs (dst : GPReg) (imm : BitVec 64)
  | aluRR (op : AluOp) (dst src : GPReg)
  /-- `ALU r64, imm32` — the immediate is sign-extended. -/
  | aluRI (op : AluOp) (dst : GPReg) (imm : BitVec 32)
  /-- `SHL/SHR/SAR/ROL/ROR r64, imm8`. -/
  | shiftI (op : ShiftOp) (dst : GPReg) (count : BitVec 8)
  /-- `SHL/SHR/SAR/ROL/ROR r64, CL`. -/
  | shiftCL (op : ShiftOp) (dst : GPReg)
  /-- `BSWAP r64`. -/
  | bswap (dst : GPReg)
  /-- `BEXTR r64a, r64b, r64c` (BMI1). -/
  | bextr (dst src ctrl : GPReg)
  /-- `MOVSX r64, r/m{8,16,32}`. -/
  | movsx (bits : Nat) (dst src : GPReg)
  deriving Repr

namespace Insn

def dstReg : Insn → GPReg
  | .movRR dst _ => dst
  | .movImm32 dst _ => dst
  | .movabs dst _ => dst
  | .aluRR _ dst _ => dst
  | .aluRI _ dst _ => dst
  | .shiftI _ dst _ => dst
  | .shiftCL _ dst => dst
  | .bswap dst => dst
  | .bextr dst _ _ => dst
  | .movsx _ dst _ => dst

def step (insn : Insn) (rf : RegFile) : RegFile :=
  match insn with
  | .movRR dst src => rf.set dst (rf src)
  | .movImm32 dst imm => rf.set dst (BitVec.signExtend 64 imm)
  | .movabs dst imm => rf.set dst imm
  | .aluRR op dst src => rf.set dst (op.eval (rf dst) (rf src))
  | .aluRI op dst imm => rf.set dst (op.eval (rf dst) (BitVec.signExtend 64 imm))
  | .shiftI op dst count => rf.set dst (op.eval (rf dst) count.toNat)
  | .shiftCL op dst => rf.set dst (op.eval (rf dst) (BitVec.setWidth 8 (rf .rcx)).toNat)
  | .bswap dst => rf.set dst (Bits.bswap64 (rf dst))
  | .bextr dst src ctrl => rf.set dst (X86.bextr (rf src) (rf ctrl))
  | .movsx bits dst src =>
      rf.set dst (BitVec.signExtend 64 (BitVec.setWidth bits (rf src)))

theorem step_other (insn : Insn) (rf : RegFile) (r : GPReg) (h : r ≠ insn.dstReg) :
    insn.step rf r = rf r := by
  cases insn <;> simp_all [step, dstReg]

end Insn

def exec (insns : List Insn) (rf : RegFile) : RegFile :=
  insns.foldl (fun rf insn => insn.step rf) rf

def writes (insns : List Insn) : List GPReg := insns.map Insn.dstReg

end X86
