/-
  Execution lemmas for straight-line x86-64 blocks.
-/
import KinsnLean4.X86.Defs

namespace X86

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

@[simp] theorem writes_nil : writes [] = [] := rfl

@[simp] theorem writes_cons (i : Insn) (is : List Insn) :
    writes (i :: is) = i.dstReg :: writes is := rfl

@[simp] theorem writes_append (is₁ is₂ : List Insn) :
    writes (is₁ ++ is₂) = writes is₁ ++ writes is₂ := List.map_append ..

/-- Frame condition: a block leaves every register outside its write set
    untouched. -/
theorem exec_of_not_mem_writes (is : List Insn) (rf : RegFile) (r : GPReg)
    (h : r ∉ writes is) : exec is rf r = rf r := by
  induction is generalizing rf with
  | nil => rfl
  | cons i is ih =>
    simp only [writes_cons, List.mem_cons, not_or] at h
    rw [exec_cons, ih _ h.2, Insn.step_other i rf r h.1]

@[simp] theorem step_movRR (dst src : GPReg) (rf : RegFile) :
    (Insn.movRR dst src).step rf = rf.set dst (rf src) := rfl

@[simp] theorem step_movabs (dst : GPReg) (imm : BitVec 64) (rf : RegFile) :
    (Insn.movabs dst imm).step rf = rf.set dst imm := rfl

@[simp] theorem step_aluRR (op : AluOp) (dst src : GPReg) (rf : RegFile) :
    (Insn.aluRR op dst src).step rf = rf.set dst (op.eval (rf dst) (rf src)) := rfl

@[simp] theorem step_shiftI (op : ShiftOp) (dst : GPReg) (count : BitVec 8) (rf : RegFile) :
    (Insn.shiftI op dst count).step rf = rf.set dst (op.eval (rf dst) count.toNat) := rfl

@[simp] theorem step_bswap (dst : GPReg) (rf : RegFile) :
    (Insn.bswap dst).step rf = rf.set dst (Bits.bswap64 (rf dst)) := rfl

@[simp] theorem step_bextr (dst src ctrl : GPReg) (rf : RegFile) :
    (Insn.bextr dst src ctrl).step rf = rf.set dst (X86.bextr (rf src) (rf ctrl)) := rfl

@[simp] theorem step_movsx (bits : Nat) (dst src : GPReg) (rf : RegFile) :
    (Insn.movsx bits dst src).step rf =
      rf.set dst (BitVec.signExtend 64 (BitVec.setWidth bits (rf src))) := rfl

/-- `BEXTR` with a `bextrCtrl` control word is a bitfield extract. -/
theorem bextr_bextrCtrl (src : BitVec 64) (start len : Nat)
    (hs : start < 256) (hl : len < 256) :
    bextr src (bextrCtrl start len) = (src >>> start) &&& Bits.lowMask 64 len := by
  have hstart : (BitVec.setWidth 8 (bextrCtrl start len)).toNat = start := by
    simp [bextrCtrl, BitVec.toNat_ofNat]
    omega
  have hlen : (BitVec.setWidth 8 (bextrCtrl start len >>> 8)).toNat = len := by
    simp [bextrCtrl, BitVec.toNat_setWidth, BitVec.toNat_ushiftRight, BitVec.toNat_ofNat,
      Nat.shiftRight_eq_div_pow]
    omega
  simp only [bextr, hstart, hlen]

end X86
