/-
  The BPF ALU fragment used by kinsn expansions.  No memory, no jumps: every
  expansion is straight-line ALU code.

  Fidelity points that the equivalence proofs actually depend on: shift counts
  are masked to the operand width (`dst <<= src & 63`), ALU32 zero-extends its
  result into the full 64-bit register, and immediates denote the value *after*
  the ISA's sign extension of the encoded 32-bit field.
-/
import KinsnLean4.Util.Bits

namespace BPF

/-! ## Registers -/

/-- R0-R10; R10 is the read-only frame pointer. -/
inductive Reg where
  | r0 | r1 | r2 | r3 | r4 | r5 | r6 | r7 | r8 | r9 | r10
  deriving DecidableEq, Repr, Inhabited

abbrev RegFile := Reg → BitVec 64

def RegFile.set (rf : RegFile) (r : Reg) (v : BitVec 64) : RegFile :=
  fun r' => if r' = r then v else rf r'

@[simp]
theorem RegFile.set_same (rf : RegFile) (r : Reg) (v : BitVec 64) :
    rf.set r v r = v := by
  simp [RegFile.set]

@[simp]
theorem RegFile.set_other (rf : RegFile) (r r' : Reg) (v : BitVec 64)
    (h : r' ≠ r) : rf.set r v r' = rf r' := by
  simp [RegFile.set, h]

theorem RegFile.set_set_same (rf : RegFile) (r : Reg) (v w : BitVec 64) :
    (rf.set r v).set r w = rf.set r w := by
  funext r'; by_cases h : r' = r <;> simp [RegFile.set, h]

/-! ## Operands -/

/-- `BPF_X` (register) or `BPF_K` (immediate). -/
inductive Src where
  | reg : Reg → Src
  | imm : BitVec 64 → Src
  deriving Repr, DecidableEq

def Src.eval (rf : RegFile) : Src → BitVec 64
  | .reg r => rf r
  | .imm i => i

@[simp] theorem Src.eval_reg (rf : RegFile) (r : Reg) : Src.eval rf (.reg r) = rf r := rfl
@[simp] theorem Src.eval_imm (rf : RegFile) (i : BitVec 64) : Src.eval rf (.imm i) = i := rfl

/-! ## ALU operations -/

/-- `BPF_ALU` (32-bit) or `BPF_ALU64`. -/
inductive Width where
  | w32 | w64
  deriving DecidableEq, Repr

/-- `BPF_END` / `BPF_BSWAP` widths. -/
inductive EndSize where
  | b16 | b32 | b64
  deriving DecidableEq, Repr

/-- Arithmetic/logic opcodes; no div/mod. -/
inductive AluOp where
  | mov | add | sub | mul | or | and | xor | lsh | rsh | arsh | neg
  deriving DecidableEq, Repr

/-- Shift counts are reduced modulo the operand width — the ISA's
    `src & (width - 1)` masking. -/
def AluOp.eval {w : Nat} (op : AluOp) (dst src : BitVec w) : BitVec w :=
  match op with
  | .mov  => src
  | .add  => dst + src
  | .sub  => dst - src
  | .mul  => dst * src
  | .or   => dst ||| src
  | .and  => dst &&& src
  | .xor  => dst ^^^ src
  | .lsh  => dst <<< (src.toNat % w)
  | .rsh  => dst >>> (src.toNat % w)
  | .arsh => dst.sshiftRight (src.toNat % w)
  | .neg  => -dst

/-! ## Instructions -/

/-- The instructions a kinsn expansion can use. -/
inductive Insn where
  /-- `BPF_ALU`/`BPF_ALU64` arithmetic and logic. -/
  | alu (op : AluOp) (w : Width) (dst : Reg) (src : Src)
  /-- `BPF_MOVSX`: move with sign extension from `bits ∈ {8, 16, 32}`. -/
  | movsx (bits : Nat) (dst : Reg) (src : Src)
  /-- `BPF_LD | BPF_IMM | BPF_DW`: load a 64-bit constant (two encoded slots). -/
  | ldImm64 (dst : Reg) (imm : BitVec 64)
  /-- `BPF_END`/`BPF_BSWAP`: reverse the bytes of `dst`. -/
  | bswap (sz : EndSize) (dst : Reg)
  deriving Repr

namespace Insn

def dstReg : Insn → Reg
  | .alu _ _ dst _ => dst
  | .movsx _ dst _ => dst
  | .ldImm64 dst _ => dst
  | .bswap _ dst   => dst

def evalBswap (sz : EndSize) (v : BitVec 64) : BitVec 64 :=
  match sz with
  | .b16 => BitVec.setWidth 64 (Bits.bswap16 (BitVec.setWidth 16 v))
  | .b32 => BitVec.setWidth 64 (Bits.bswap32 (BitVec.setWidth 32 v))
  | .b64 => Bits.bswap64 v

def step (insn : Insn) (rf : RegFile) : RegFile :=
  match insn with
  | .alu op .w64 dst src => rf.set dst (op.eval (rf dst) (src.eval rf))
  | .alu op .w32 dst src =>
      rf.set dst (BitVec.setWidth 64
        (op.eval (BitVec.setWidth 32 (rf dst)) (BitVec.setWidth 32 (src.eval rf))))
  | .movsx bits dst src =>
      rf.set dst (BitVec.signExtend 64 (BitVec.setWidth bits (src.eval rf)))
  | .ldImm64 dst imm => rf.set dst imm
  | .bswap sz dst => rf.set dst (evalBswap sz (rf dst))

theorem step_other (insn : Insn) (rf : RegFile) (r : Reg) (h : r ≠ insn.dstReg) :
    insn.step rf r = rf r := by
  cases insn with
  | alu op w dst src => cases w <;> simp_all [step, dstReg]
  | movsx bits dst src => simp_all [step, dstReg]
  | ldImm64 dst imm => simp_all [step, dstReg]
  | bswap sz dst => simp_all [step, dstReg]

end Insn

/-! ## Programs -/

def exec (insns : List Insn) (rf : RegFile) : RegFile :=
  insns.foldl (fun rf insn => insn.step rf) rf

/-- The registers a straight-line block may write. -/
def writes (insns : List Insn) : List Reg := insns.map Insn.dstReg

/-! ## Constructors matching the kernel's `BPF_*` macros -/

@[inline] def mov64 (dst : Reg) (src : Src) : Insn := .alu .mov .w64 dst src
@[inline] def add64 (dst : Reg) (src : Src) : Insn := .alu .add .w64 dst src
@[inline] def sub64 (dst : Reg) (src : Src) : Insn := .alu .sub .w64 dst src
@[inline] def or64 (dst : Reg) (src : Src) : Insn := .alu .or  .w64 dst src
@[inline] def and64 (dst : Reg) (src : Src) : Insn := .alu .and .w64 dst src
@[inline] def xor64 (dst : Reg) (src : Src) : Insn := .alu .xor .w64 dst src
@[inline] def lsh64 (dst : Reg) (src : Src) : Insn := .alu .lsh .w64 dst src
@[inline] def rsh64 (dst : Reg) (src : Src) : Insn := .alu .rsh .w64 dst src
@[inline] def arsh64 (dst : Reg) (src : Src) : Insn := .alu .arsh .w64 dst src
@[inline] def mov32 (dst : Reg) (src : Src) : Insn := .alu .mov .w32 dst src

@[inline] def immN (n : Nat) : Src := .imm (BitVec.ofNat 64 n)

end BPF
