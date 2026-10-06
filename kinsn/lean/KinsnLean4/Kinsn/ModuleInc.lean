import KinsnLean4.Kinsn.ModuleRegister

namespace Kinsn.ModuleInc

/-- x86/bpf_x86_alu.c:instantiate_inc: ADD1; INC8 corrects the byte carry
without a temporary. ARCH and ordinary forms both use the live destination. -/
def bpf (bits : Nat) (d : BPF.Reg) : List BPF.MInsn :=
  [.core (.alu .add (if bits = 32 then .w32 else .w64) d (.imm 1))] ++
    if bits = 8 then
      [.branch .bitSet .w64 d (.imm 0xff) 1, .core (BPF.add64 d (.imm (BitVec.signExtend 64 (-256 : BitVec 32))))]
    else []

/-- x86/bpf_x86_alu.c:emit_inc_x86: INC dst8/dst32/dst64. -/
def native (bits : Nat) (d : X86.GPReg) : List X86.MInsn := [.inc bits d]

def value (bits : Nat) (v : BitVec 64) : BitVec 64 := X86.writeWidth bits v (v + 1)

private theorem byte_decompose (v : BitVec 64) :
    value 8 v = (BitVec.extractLsb' 8 56 v) ++ (BitVec.setWidth 8 (v + 1)) := by
  unfold value X86.writeWidth
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [BitVec.getLsbD_append]
  interval_cases i <;> simp [Bits.lowMask]

private theorem byte_nat (v : BitVec 64) :
    (value 8 v).toNat = v.toNat / 256 * 256 + (v.toNat + 1) % 256 := by
  rw [byte_decompose, BitVec.toNat_append]
  have hv := v.isLt
  simp only [BitVec.extractLsb'_toNat, BitVec.toNat_setWidth, BitVec.toNat_add,
    show (1 : BitVec 64).toNat = 1 from rfl, Nat.shiftRight_eq_div_pow, Nat.shiftLeft_eq]
  norm_num at hv ⊢
  rw [Nat.mul_comm _ 256]
  have hor := Nat.two_pow_add_eq_or_of_lt (i := 8)
    (a := v.toNat / 256 % 72057594037927936) (b := (v.toNat + 1) % 256) (by omega)
  norm_num at hor
  rw [← hor]
  omega

private theorem byte_mask_nat (v : BitVec 64) :
    ((v + 1) &&& 255).toNat = (v.toNat + 1) % 256 := by
  change ((v + 1) &&& (BitVec.ofNat 64 (2^8 - 1))).toNat = _
  simp only [BitVec.toNat_and, BitVec.toNat_ofNat, BitVec.toNat_add,
    show (1 : BitVec 64).toNat = 1 from rfl]
  norm_num
  rw [show 255 = 2^8 - 1 by decide, Nat.and_two_pow_sub_one_eq_mod]
  omega

/-- instantiate_inc's -256 immediate after sign extension from its raw imm32. -/
theorem carry_immediate : BitVec.signExtend 64 (-256 : BitVec 32) =
    (18446744073709551360 : BitVec 64) := by decide +kernel

private theorem correction_nat : (18446744073709551360 : BitVec 64).toNat =
    18446744073709551360 := by decide +kernel

private theorem wrap_arith (n : Nat) (hn : n < 18446744073709551616)
    (hz : (n + 1) % 256 = 0) :
    ((n + 1) % 18446744073709551616 + 18446744073709551360) % 18446744073709551616 =
      n / 256 * 256 + (n + 1) % 256 := by omega

private theorem nowrap_arith (n : Nat) (hn : n < 18446744073709551616)
    (hz : (n + 1) % 256 ≠ 0) :
    (n + 1) % 18446744073709551616 =
      n / 256 * 256 + (n + 1) % 256 := by omega

private theorem byte_nowrap (v : BitVec 64) (h : (v + 1) &&& 255 ≠ 0) :
    v + 1 = value 8 v := by
  apply BitVec.eq_of_toNat_eq
  rw [byte_nat]
  have hz : (v.toNat + 1) % 256 ≠ 0 := by
    intro he
    exact h (BitVec.eq_of_toNat_eq (by rw [byte_mask_nat, he]; rfl))
  simp only [BitVec.toNat_add, show (1 : BitVec 64).toNat = 1 from rfl]
  exact nowrap_arith v.toNat v.isLt hz

private theorem byte_wrap (v : BitVec 64) (h : (v + 1) &&& 255 = 0) :
    v + 1 + 18446744073709551360 = value 8 v := by
  have hz : (v.toNat + 1) % 256 = 0 := by rw [← byte_mask_nat, h]; rfl
  apply BitVec.eq_of_toNat_eq
  calc
    (v + 1 + 18446744073709551360).toNat =
        ((v + 1).toNat + (18446744073709551360 : BitVec 64).toNat) % 2^64 :=
      BitVec.toNat_add _ _
    _ = ((v.toNat + 1) % 18446744073709551616 +
        18446744073709551360) % 18446744073709551616 := by
      rw [correction_nat, BitVec.toNat_add]
      rfl
    _ = v.toNat / 256 * 256 + (v.toNat + 1) % 256 := wrap_arith v.toNat v.isLt hz
    _ = (value 8 v).toNat := (byte_nat v).symm

theorem byte_value (v : BitVec 64) :
    (if (v + 1) &&& 255 ≠ 0 then v + 1 else v + 1 + 18446744073709551360) = value 8 v := by
  split_ifs with h
  · exact byte_nowrap v h
  · exact byte_wrap v (not_ne_iff.mp h)

-- Sign-extended 64-bit immediates need deeper definitional reduction here.
set_option maxRecDepth 4096 in
theorem bpf_correct (bits : Nat) (h : bits = 8 ∨ bits = 32 ∨ bits = 64)
    (d : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf bits d) s) =
      ModuleRegister.unarySpec d d (value bits) (observeBpf s) := by
  rcases h with h | h | h <;> subst bits
  · by_cases hz : (s.regs d + 1#64) &&& 255#64 = 0#64
    · have hv := byte_wrap (s.regs d) hz
      simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
        BPF.Src.eval, BPF.add64, BPF.Cond.test, BPF.Cond.eval,
        carry_immediate, hz, observeBpf, ModuleRegister.unarySpec]
      simpa [BPF.RegFile.set_set_same] using congrArg (BPF.RegFile.set s.regs d) hv
    · have hv := byte_nowrap (s.regs d) hz
      simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
        BPF.Src.eval, BPF.add64, BPF.Cond.test, BPF.Cond.eval,
        carry_immediate, hz, observeBpf, ModuleRegister.unarySpec]
      exact congrArg (BPF.RegFile.set s.regs d) hv
  · simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      BPF.Src.eval, observeBpf, ModuleRegister.unarySpec, value, X86.writeWidth,
      BitVec.setWidth_add _ _ (by decide : 32 ≤ 64)]
  · simp [bpf, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      BPF.Src.eval, observeBpf, ModuleRegister.unarySpec, value, X86.writeWidth]

def cert (m : X86RegMap) (bits : Nat) (h : bits = 8 ∨ bits = 32 ∨ bits = 64)
    (d : BPF.Reg) : X86StateEquiv m where
  spec := ModuleRegister.unarySpec d d (value bits)
  bpf := bpf bits d
  native := native bits (m.map d)
  writeSet := [d]
  bpfCorrect := bpf_correct bits h d
  nativeCorrect := by
    intro s
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, x86_observe_set]
    rfl
  bpfWrites := by
    rcases h with h | h | h <;> subst bits <;>
      simp [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.add64, BPF.Insn.dstReg]
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_alu.c:instantiate_incb/emit_incb_x86, including byte wrap. -/
def bpf_x86_incb (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m 8 (by simp) d

/-- x86/bpf_x86_alu.c:instantiate_incl/emit_incl_x86. -/
def bpf_x86_incl (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m 32 (by simp) d

/-- x86/bpf_x86_alu.c:instantiate_incq/emit_incq_x86. -/
def bpf_x86_incq (m : X86RegMap) (d : BPF.Reg) : X86StateEquiv m := cert m 64 (by simp) d

end Kinsn.ModuleInc
