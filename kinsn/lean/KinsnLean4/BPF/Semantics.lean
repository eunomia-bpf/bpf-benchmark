/-
  Execution lemmas for straight-line BPF blocks.
-/
import KinsnLean4.BPF.Defs

namespace BPF

@[simp]
theorem exec_nil (rf : RegFile) : exec [] rf = rf := rfl

@[simp]
theorem exec_cons (i : Insn) (is : List Insn) (rf : RegFile) :
    exec (i :: is) rf = exec is (i.step rf) := rfl

theorem exec_append (is₁ is₂ : List Insn) (rf : RegFile) :
    exec (is₁ ++ is₂) rf = exec is₂ (exec is₁ rf) := by
  induction is₁ generalizing rf with
  | nil => simp
  | cons i is₁ ih => simp [ih]

@[simp]
theorem writes_nil : writes [] = [] := rfl

@[simp]
theorem writes_cons (i : Insn) (is : List Insn) :
    writes (i :: is) = i.dstReg :: writes is := rfl

@[simp]
theorem writes_append (is₁ is₂ : List Insn) :
    writes (is₁ ++ is₂) = writes is₁ ++ writes is₂ := List.map_append ..

/-- Frame condition: a block leaves every register outside its write set
    untouched.  This is what lets a JIT splice a native block in place of a
    BPF block. -/
theorem exec_of_not_mem_writes (is : List Insn) (rf : RegFile) (r : Reg)
    (h : r ∉ writes is) : exec is rf r = rf r := by
  induction is generalizing rf with
  | nil => rfl
  | cons i is ih =>
    simp only [writes_cons, List.mem_cons, not_or] at h
    rw [exec_cons, ih _ h.2, Insn.step_other i rf r h.1]

theorem exec_append_of_not_mem_writes (is₁ is₂ : List Insn) (rf : RegFile) (r : Reg)
    (h : r ∉ writes is₂) : exec (is₁ ++ is₂) rf r = exec is₁ rf r := by
  rw [exec_append, exec_of_not_mem_writes _ _ _ h]

/-! ## Step equations -/

@[simp]
theorem step_alu64 (op : AluOp) (dst : Reg) (src : Src) (rf : RegFile) :
    (Insn.alu op .w64 dst src).step rf = rf.set dst (op.eval (rf dst) (src.eval rf)) := rfl

@[simp]
theorem step_alu32 (op : AluOp) (dst : Reg) (src : Src) (rf : RegFile) :
    (Insn.alu op .w32 dst src).step rf =
      rf.set dst (BitVec.setWidth 64
        (op.eval (BitVec.setWidth 32 (rf dst)) (BitVec.setWidth 32 (src.eval rf)))) := rfl

@[simp]
theorem step_movsx (bits : Nat) (dst : Reg) (src : Src) (rf : RegFile) :
    (Insn.movsx bits dst src).step rf =
      rf.set dst (BitVec.signExtend 64 (BitVec.setWidth bits (src.eval rf))) := rfl

@[simp]
theorem step_ldImm64 (dst : Reg) (imm : BitVec 64) (rf : RegFile) :
    (Insn.ldImm64 dst imm).step rf = rf.set dst imm := rfl

@[simp]
theorem step_bswap (sz : EndSize) (dst : Reg) (rf : RegFile) :
    (Insn.bswap sz dst).step rf = rf.set dst (Insn.evalBswap sz (rf dst)) := rfl

@[simp]
theorem toNat_immN (rf : RegFile) (n : Nat) : ((immN n : Src).eval rf).toNat = n % 2 ^ 64 := by
  simp [immN, Src.eval]

theorem immN_shift_amount (rf : RegFile) (n : Nat) (h : n < 64) :
    (((immN n : Src).eval rf).toNat) % 64 = n := by
  rw [toNat_immN, Nat.mod_eq_of_lt (by omega : n < 2 ^ 64), Nat.mod_eq_of_lt h]

end BPF
