import KinsnLean4.Kinsn.ModuleMovbeWide
import KinsnLean4.Kinsn.ModuleMovStore

namespace Kinsn.ModuleWideAlu

inductive Kind where
  | add | sub | and | or | xor
  deriving DecidableEq, Repr

def Kind.bpf : Kind → BPF.AluOp
  | .add => .add | .sub => .sub | .and => .and | .or => .or | .xor => .xor

def Kind.native : Kind → X86.AluOp
  | .add => .add | .sub => .sub | .and => .and | .or => .or | .xor => .xor

def width (w32 : Bool) : BPF.Width := if w32 then .w32 else .w64

def bits (w32 : Bool) : Nat := if w32 then 32 else 64

def value (kind : Kind) (w32 : Bool) (a b : BitVec 64) : BitVec 64 :=
  if w32 then BitVec.setWidth 64
    (kind.bpf.eval (BitVec.setWidth 32 a) (BitVec.setWidth 32 b)) else kind.bpf.eval a b

theorem value_native (kind : Kind) (w32 : Bool) (a b : BitVec 64) :
    value kind w32 a b = X86.writeWidth (bits w32) a (kind.native.eval a b) := by
  cases kind <;> cases w32 <;>
    simp [value, bits, Kind.bpf, Kind.native, BPF.AluOp.eval, X86.AluOp.eval,
      X86.writeWidth]
  have he : BitVec.setWidth 32 a - BitVec.setWidth 32 b = BitVec.setWidth 32 (a-b) := by
    apply BitVec.eq_of_toNat_eq
    have ha := a.isLt
    have hb := b.isLt
    simp [BitVec.toNat_sub, BitVec.toNat_setWidth]
    omega
  rw [he]

/-- x86/bpf_x86_alu.c:instantiate_x86_alu_mem: live temporary forms base
    plus 2^scale copies of index. The chosen temporary excludes all operands. -/
def address (indexed : Bool) (t b i : BPF.Reg) (scale : Nat) : List BPF.Insn :=
  [.alu .mov .w64 t (.reg b)] ++
    (if indexed then List.replicate (2^scale) (.alu .add .w64 t (.reg i)) else [])

theorem address_exec (indexed : Bool) (t b i : BPF.Reg) (scale : Nat)
    (hi : t ≠ i) (hs : scale ≤ 3) (rf : BPF.RegFile) :
    BPF.exec (address indexed t b i scale) rf =
      rf.set t (rf b + if indexed then rf i <<< scale else 0) := by
  cases indexed
  · simp [address, BPF.exec, BPF.Insn.step, BPF.AluOp.eval]
  · interval_cases scale <;>
      simp [address, BPF.exec, BPF.Insn.step, BPF.AluOp.eval, BPF.RegFile.set,
        Ne.symm hi]
    all_goals funext r
    all_goals by_cases ht : r = t
    all_goals simp [ht, ModuleLea.shl_mul]
    all_goals apply BitVec.eq_of_toNat_eq
    all_goals simp [BitVec.toNat_mul, BitVec.toNat_add, Nat.add_mod_mod,
      Nat.mod_add_mod, BitVec.toNat_ofNat]
    all_goals omega

end Kinsn.ModuleWideAlu
