/-
  Execution lemmas for straight-line ARM64 blocks, and derivation of the
  assembler aliases (`LSR`, `LSL`, `UBFX`, `UXT*`, `SXT*`, `ROR`, `BFI`,
  `AND #mask`) from the `UBFM`/`SBFM`/`BFM`/`EXTR` encodings.
-/
import KinsnLean4.ARM64.Defs

namespace ARM64

/-! ## Block execution -/

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
    (h : r ∉ writes is) : (exec is rf).get r = rf.get r := by
  induction is generalizing rf with
  | nil => rfl
  | cons i is ih =>
    simp only [writes_cons, List.mem_cons, not_or] at h
    rw [exec_cons, ih _ h.2, Insn.step_other i rf r h.1]

/-! ## Step equations -/

@[simp] theorem step_ubfm (dst src : GPReg) (immr imms : BitVec 6) (rf : RegFile) :
    (Insn.ubfm dst src immr imms).step rf = rf.set dst (execUBFM (rf.get src) immr imms) := rfl

@[simp] theorem step_sbfm (dst src : GPReg) (immr imms : BitVec 6) (rf : RegFile) :
    (Insn.sbfm dst src immr imms).step rf = rf.set dst (execSBFM (rf.get src) immr imms) := rfl

@[simp] theorem step_bfm (dst src : GPReg) (immr imms : BitVec 6) (rf : RegFile) :
    (Insn.bfm dst src immr imms).step rf =
      rf.set dst (execBFM (rf.get dst) (rf.get src) immr imms) := rfl

@[simp] theorem step_extr (dst rn rm : GPReg) (lsb : BitVec 6) (rf : RegFile) :
    (Insn.extr dst rn rm lsb).step rf = rf.set dst (execEXTR (rf.get rn) (rf.get rm) lsb) := rfl

@[simp] theorem step_movz (dst : GPReg) (imm16 : BitVec 16) (hw : Nat) (rf : RegFile) :
    (Insn.movz dst imm16 hw).step rf = rf.set dst (BitVec.setWidth 64 imm16 <<< (16 * hw)) := rfl

@[simp] theorem step_movk (dst : GPReg) (imm16 : BitVec 16) (hw : Nat) (rf : RegFile) :
    (Insn.movk dst imm16 hw).step rf =
      rf.set dst ((rf.get dst &&& ~~~(Bits.lowMask 64 16 <<< (16 * hw))) |||
        (BitVec.setWidth 64 imm16 <<< (16 * hw))) := rfl

@[simp] theorem step_rev64 (dst src : GPReg) (rf : RegFile) :
    (Insn.rev64 dst src).step rf = rf.set dst (Bits.bswap64 (rf.get src)) := rfl

@[simp] theorem step_rev32w (dst src : GPReg) (rf : RegFile) :
    (Insn.rev32w dst src).step rf = rf.set dst (execREV32W (rf.get src)) := rfl

@[simp] theorem step_rev16w (dst src : GPReg) (rf : RegFile) :
    (Insn.rev16w dst src).step rf = rf.set dst (execREV16W (rf.get src)) := rfl

@[simp] theorem step_logicalReg (op : LogicOp) (dst rn rm : GPReg) (st : ShiftType)
    (amount : Nat) (rf : RegFile) :
    (Insn.logicalReg op dst rn rm st amount).step rf =
      rf.set dst (op.eval (rf.get rn) (shiftReg (rf.get rm) st amount)) := rfl

@[simp] theorem step_logicalImm (op : LogicOp) (dst rn : GPReg) (immr imms : BitVec 6)
    (rf : RegFile) :
    (Insn.logicalImm op dst rn immr imms).step rf =
      rf.set dst (op.eval (rf.get rn) (bitmaskImm immr imms)) := rfl

/-! ## Bitfield-mask decoding -/

theorem toNat_sub_of_le {n : Nat} (x y : BitVec n) (h : y.toNat ≤ x.toNat) :
    (x - y).toNat = x.toNat - y.toNat := by
  have hx := x.isLt
  have hy := y.isLt
  rw [BitVec.toNat_sub, show 2 ^ n - y.toNat + x.toNat = 2 ^ n + (x.toNat - y.toNat) by omega,
    Nat.add_mod_left, Nat.mod_eq_of_lt (by omega)]

@[simp]
theorem rotateRight_zero (x : BitVec w) : x.rotateRight 0 = x := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp [hi]

/-- `(immr = 0, imms = w - 1)` denotes `2^w - 1` — how a JIT encodes
    `AND Xd, Xn, #mask`. -/
theorem bitmaskImm_lowMask (w : Nat) (h1 : 1 ≤ w) (h2 : w ≤ 64) :
    bitmaskImm 0 (BitVec.ofNat 6 (w - 1)) = Bits.lowMask 64 w := by
  have hS : (BitVec.ofNat 6 (w - 1)).toNat = w - 1 := by
    simp [BitVec.toNat_ofNat]; omega
  have h0 : (0 : BitVec 6).toNat = 0 := rfl
  simp only [bitmaskImm, decodeBitMasks64, hS, h0, rotateRight_zero]
  congr 1
  omega

/-! ## UBFM -/

/-- `imms ≥ immr` is the bitfield extract `UBFX`. -/
theorem execUBFM_eq_ubfx (src : BitVec 64) (immr imms : BitVec 6)
    (h : immr.toNat ≤ imms.toNat) :
    execUBFM src immr imms =
      (src >>> immr.toNat) &&& Bits.lowMask 64 (imms.toNat - immr.toNat + 1) := by
  have hR : immr.toNat < 64 := immr.isLt
  have hS : imms.toNat < 64 := imms.isLt
  have hd : (imms - immr).toNat = imms.toNat - immr.toNat := toNat_sub_of_le _ _ h
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [execUBFM, decodeBitMasks64, BitVec.getLsbD_and, BitVec.getLsbD_ushiftRight,
    BitVec.getLsbD_rotateRight, Bits.getLsbD_lowMask, hd, Nat.mod_eq_of_lt hR]
  by_cases hik : i < imms.toNat - immr.toNat + 1
  · have h1 : i < 64 - immr.toNat := by omega
    simp only [h1, hik, hi, decide_true, cond_true, Bool.and_true, Bool.true_and]
    have : immr.toNat + i < 64 := by omega
    have : immr.toNat + i < imms.toNat + 1 := by omega
    simp_all
  · simp [hik]

/-- `UBFM Xd, Xn, #n, #63` is `LSR Xd, Xn, #n`. -/
theorem execUBFM_eq_lsr (src : BitVec 64) (immr : BitVec 6) :
    execUBFM src immr 63 = src >>> immr.toNat := by
  have hR : immr.toNat < 64 := immr.isLt
  have hS : (63 : BitVec 6).toNat = 63 := rfl
  rw [execUBFM_eq_ubfx src immr 63 (by rw [hS]; omega), hS]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_and, BitVec.getLsbD_ushiftRight, Bits.getLsbD_lowMask]
  by_cases h : i < 63 - immr.toNat + 1
  · simp [h, hi]
  · rw [BitVec.getLsbD_of_ge _ _ (by omega : 64 ≤ immr.toNat + i)]
    simp

/-- `UBFM Xd, Xn, #(-n mod 64), #(63-n)` is `LSL Xd, Xn, #n`.  This is the
    `imms < immr` branch, which `execUBFM_eq_ubfx` does not cover. -/
theorem execUBFM_eq_lsl (src : BitVec 64) (n : Nat) (hn : n < 64) :
    execUBFM src (BitVec.ofNat 6 ((64 - n) % 64)) (BitVec.ofNat 6 (63 - n)) = src <<< n := by
  have hR : (BitVec.ofNat 6 ((64 - n) % 64)).toNat = (64 - n) % 64 := by
    simp [BitVec.toNat_ofNat]
  have hS : (BitVec.ofNat 6 (63 - n)).toNat = 63 - n := by
    simp [BitVec.toNat_ofNat]; omega
  have hd : (BitVec.ofNat 6 (63 - n) - BitVec.ofNat 6 ((64 - n) % 64)).toNat = 63 := by
    rw [BitVec.toNat_sub, hR, hS]
    norm_num
    omega
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [execUBFM, decodeBitMasks64, BitVec.getLsbD_and, BitVec.getLsbD_shiftLeft,
    BitVec.getLsbD_rotateRight, Bits.getLsbD_lowMask, hd, hR, hS,
    Nat.mod_eq_of_lt (show (64 - n) % 64 < 64 by omega)]
  rcases Nat.eq_zero_or_pos n with rfl | hpos
  · simp [hi]
  · have hmod : (64 - n) % 64 = 64 - n := Nat.mod_eq_of_lt (by omega)
    rw [hmod, show 64 - (64 - n) = n by omega]
    by_cases hin : i < n
    · have e1 : ¬ (64 - n + i < 63 - n + 1) := by omega
      simp [hin, hi, e1]
    · have e2 : i - n < 63 - n + 1 := by omega
      have e3 : i - n < 64 := by omega
      simp [hin, hi, e2, e3]

/-- `UBFM Xd, Xn, #0, #(w-1)` is the zero-extension `UXTB`/`UXTH`/`UXTW`. -/
theorem execUBFM_eq_uxt (src : BitVec 64) (w : Nat) (h1 : 1 ≤ w) (h2 : w ≤ 64) :
    execUBFM src 0 (BitVec.ofNat 6 (w - 1)) = BitVec.setWidth 64 (BitVec.setWidth w src) := by
  have hS : (BitVec.ofNat 6 (w - 1)).toNat = w - 1 := by
    simp [BitVec.toNat_ofNat]; omega
  have h0 : (0 : BitVec 6).toNat = 0 := rfl
  rw [execUBFM_eq_ubfx src 0 _ (by simp), ← Bits.and_lowMask_eq_setWidth, hS, h0]
  congr 2
  omega

/-! ## SBFM -/

/-- `SBFM Xd, Xn, #0, #(w-1)` is the sign-extension `SXTB`/`SXTH`/`SXTW`. -/
theorem execSBFM_eq_sxt (src : BitVec 64) (w : Nat) (h1 : 1 ≤ w) (h2 : w ≤ 64) :
    execSBFM src 0 (BitVec.ofNat 6 (w - 1)) =
      BitVec.signExtend 64 (BitVec.setWidth w src) := by
  have hS : (BitVec.ofNat 6 (w - 1)).toNat = w - 1 := by
    simp [BitVec.toNat_ofNat]; omega
  have hd : (BitVec.ofNat 6 (w - 1) - 0).toNat = w - 1 := by simp [hS]
  have h0 : (0 : BitVec 6).toNat = 0 := rfl
  have hw1 : w - 1 + 1 = w := by omega
  have hmsb : (BitVec.setWidth w src).msb = src.getLsbD (w - 1) := by
    rw [BitVec.msb_eq_getLsbD_last]
    simp [BitVec.getLsbD_setWidth]
    omega
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [execSBFM, decodeBitMasks64, BitVec.getLsbD_and, BitVec.getLsbD_or,
    BitVec.getLsbD_not, Bits.getLsbD_lowMask, hd, hS, h0, hw1,
    BitVec.getLsbD_signExtend, BitVec.getLsbD_setWidth, hmsb, rotateRight_zero,
    Bits.getLsbD_replicate]
  by_cases hiw : i < w
  · simp [hiw, hi]
  · by_cases hb : src.getLsbD (w - 1) <;> simp [hiw, hi, hb]

/-- `SBFM Xd, Xn, #n, #63` is `ASR Xd, Xn, #n`. -/
theorem execSBFM_eq_asr (src : BitVec 64) (immr : BitVec 6) :
    execSBFM src immr 63 = src.sshiftRight immr.toNat := by
  have hR : immr.toNat < 64 := immr.isLt
  have hS : (63 : BitVec 6).toNat = 63 := rfl
  have hd : ((63 : BitVec 6) - immr).toNat = 63 - immr.toNat :=
    toNat_sub_of_le _ _ (by rw [hS]; omega)
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [execSBFM, decodeBitMasks64, BitVec.getLsbD_and, BitVec.getLsbD_or,
    BitVec.getLsbD_not, BitVec.getLsbD_rotateRight, Bits.getLsbD_lowMask,
    Bits.getLsbD_replicate, BitVec.getLsbD_sshiftRight, BitVec.msb_eq_getLsbD_last,
    hd, hS, Nat.mod_eq_of_lt hR]
  by_cases hc : i < 64 - immr.toNat
  · have e1 : immr.toNat + i < 64 := by omega
    have e2 : i < 63 - immr.toNat + 1 := by omega
    simp [hc, hi, e1, e2]
  · have e1 : ¬ (immr.toNat + i < 64) := by omega
    have e2 : ¬ (i < 63 - immr.toNat + 1) := by omega
    simp [hc, hi, e1, e2]

/-- `SBFM Xd, Xn, #lsb, #(lsb+width-1)` is the signed extract `SBFX`. -/
theorem execSBFM_eq_sbfx (src : BitVec 64) (lsb width : Nat)
    (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) :
    execSBFM src (BitVec.ofNat 6 lsb) (BitVec.ofNat 6 (lsb + width - 1)) =
      BitVec.signExtend 64 (BitVec.setWidth width (src >>> lsb)) := by
  have hR : (BitVec.ofNat 6 lsb).toNat = lsb := by simp [BitVec.toNat_ofNat]; omega
  have hS : (BitVec.ofNat 6 (lsb + width - 1)).toNat = lsb + width - 1 := by
    simp [BitVec.toNat_ofNat]; omega
  have hd : (BitVec.ofNat 6 (lsb + width - 1) - BitVec.ofNat 6 lsb).toNat = width - 1 := by
    rw [toNat_sub_of_le _ _ (by rw [hR, hS]; omega), hR, hS]; omega
  have hmsb : (BitVec.setWidth width (src >>> lsb)).msb = src.getLsbD (lsb + width - 1) := by
    rw [BitVec.msb_eq_getLsbD_last]
    simp only [BitVec.getLsbD_setWidth, BitVec.getLsbD_ushiftRight]
    simp [show width - 1 < width from by omega,
      show lsb + (width - 1) = lsb + width - 1 from by omega]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [execSBFM, decodeBitMasks64, BitVec.getLsbD_and, BitVec.getLsbD_or,
    BitVec.getLsbD_not, BitVec.getLsbD_rotateRight, Bits.getLsbD_lowMask,
    Bits.getLsbD_replicate, BitVec.getLsbD_signExtend, BitVec.getLsbD_setWidth,
    BitVec.getLsbD_ushiftRight, hmsb, hd, hR, hS, Nat.mod_eq_of_lt (show lsb < 64 by omega),
    show width - 1 + 1 = width from by omega]
  by_cases hc : i < width
  · have e1 : i < 64 - lsb := by omega
    have e2 : lsb + i < 64 := by omega
    have e3 : lsb + i < lsb + width - 1 + 1 := by omega
    simp [hc, hi, e1, e2, e3]
  · simp [hc, hi]

/-! ## BFM -/

/-- `BFM Xd, Xn, #(-lsb mod 64), #(width-1)` is the bitfield insert `BFI`. -/
theorem execBFM_eq_bfi (dst src : BitVec 64) (lsb width : Nat)
    (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) :
    execBFM dst src (BitVec.ofNat 6 ((64 - lsb) % 64)) (BitVec.ofNat 6 (width - 1)) =
      (dst &&& ~~~(Bits.lowMask 64 width <<< lsb)) |||
        ((src &&& Bits.lowMask 64 width) <<< lsb) := by
  have hR : (BitVec.ofNat 6 ((64 - lsb) % 64)).toNat = (64 - lsb) % 64 := by
    simp [BitVec.toNat_ofNat]
  have hS : (BitVec.ofNat 6 (width - 1)).toNat = width - 1 := by
    simp [BitVec.toNat_ofNat]; omega
  have hd : (BitVec.ofNat 6 (width - 1) - BitVec.ofNat 6 ((64 - lsb) % 64)).toNat
      = lsb + width - 1 := by
    rw [BitVec.toNat_sub, hR, hS]; norm_num; omega
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [execBFM, decodeBitMasks64, BitVec.getLsbD_and, BitVec.getLsbD_or,
    BitVec.getLsbD_not, BitVec.getLsbD_shiftLeft, BitVec.getLsbD_rotateRight,
    Bits.getLsbD_lowMask, hd, hR, hS,
    Nat.mod_eq_of_lt (show (64 - lsb) % 64 < 64 by omega),
    show width - 1 + 1 = width from by omega,
    show lsb + width - 1 + 1 = lsb + width from by omega]
  by_cases hlsb : lsb = 0
  · subst hlsb
    by_cases hiw : i < width
    · simp_all
    · simp [hi, hiw]
  · have hmod : (64 - lsb) % 64 = 64 - lsb := Nat.mod_eq_of_lt (by omega)
    rw [hmod, show 64 - (64 - lsb) = lsb from by omega]
    by_cases ha : i < lsb
    · have e : ¬ (64 - lsb + i < width) := by omega
      have e2 : i < lsb + width := by omega
      simp [ha, hi, e, e2]
    · by_cases hb : i < lsb + width
      · have e : i - lsb < width := by omega
        have e2 : i - lsb < 64 := by omega
        simp [ha, hb, hi, e, e2]
      · have e : ¬ (i - lsb < width) := by omega
        simp [ha, hb, hi, e]

/-! ## EXTR -/

/-- `EXTR Xd, Xn, Xn, #n` is `ROR Xd, Xn, #n`. -/
theorem execEXTR_self (v : BitVec 64) (lsb : BitVec 6) :
    execEXTR v v lsb = v.rotateRight lsb.toNat := by
  have hl : lsb.toNat < 64 := lsb.isLt
  unfold execEXTR
  split
  · rename_i h; subst h; simp
  · exact Bits.shiftLeft_or_shiftRight_eq_rotateRight v lsb.toNat hl

/-! ## Alias step equations -/

@[simp]
theorem step_mov (dst src : GPReg) (rf : RegFile) :
    (mov dst src).step rf = rf.set dst (rf.get src) := by
  simp [mov, LogicOp.eval]

theorem step_lsr (dst src : GPReg) (n : Nat) (hn : n < 64) (rf : RegFile) :
    (lsr dst src n).step rf = rf.set dst (rf.get src >>> n) := by
  have h : (BitVec.ofNat 6 n).toNat = n := by simp [BitVec.toNat_ofNat]; omega
  simp only [lsr, step_ubfm, execUBFM_eq_lsr, h]

theorem step_lsl (dst src : GPReg) (n : Nat) (hn : n < 64) (rf : RegFile) :
    (lsl dst src n).step rf = rf.set dst (rf.get src <<< n) := by
  simp only [lsl, step_ubfm, execUBFM_eq_lsl _ n hn]

theorem step_ubfx (dst src : GPReg) (lsb width : Nat)
    (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) (rf : RegFile) :
    (ubfx dst src lsb width).step rf =
      rf.set dst ((rf.get src >>> lsb) &&& Bits.lowMask 64 width) := by
  have hlsb : (BitVec.ofNat 6 lsb).toNat = lsb := by simp [BitVec.toNat_ofNat]; omega
  have himms : (BitVec.ofNat 6 (lsb + width - 1)).toNat = lsb + width - 1 := by
    simp [BitVec.toNat_ofNat]; omega
  have hle : (BitVec.ofNat 6 lsb).toNat ≤ (BitVec.ofNat 6 (lsb + width - 1)).toNat := by
    rw [hlsb, himms]; omega
  simp only [ubfx, step_ubfm, execUBFM_eq_ubfx _ _ _ hle, hlsb, himms,
    show lsb + width - 1 - lsb + 1 = width from by omega]

theorem step_uxt (dst src : GPReg) (w : Nat) (h1 : 1 ≤ w) (h2 : w ≤ 64) (rf : RegFile) :
    (uxt dst src w).step rf =
      rf.set dst (BitVec.setWidth 64 (BitVec.setWidth w (rf.get src))) := by
  simp only [uxt, step_ubfm, execUBFM_eq_uxt _ w h1 h2]

theorem step_sxt (dst src : GPReg) (w : Nat) (h1 : 1 ≤ w) (h2 : w ≤ 64) (rf : RegFile) :
    (sxt dst src w).step rf =
      rf.set dst (BitVec.signExtend 64 (BitVec.setWidth w (rf.get src))) := by
  simp only [sxt, step_sbfm, execSBFM_eq_sxt _ w h1 h2]

theorem step_ror (dst src : GPReg) (n : Nat) (hn : n < 64) (rf : RegFile) :
    (ror dst src n).step rf = rf.set dst ((rf.get src).rotateRight n) := by
  have h : (BitVec.ofNat 6 n).toNat = n := by simp [BitVec.toNat_ofNat]; omega
  simp only [ror, step_extr, execEXTR_self, h]

theorem step_asr (dst src : GPReg) (n : Nat) (hn : n < 64) (rf : RegFile) :
    (asr dst src n).step rf = rf.set dst ((rf.get src).sshiftRight n) := by
  have h : (BitVec.ofNat 6 n).toNat = n := by simp [BitVec.toNat_ofNat]; omega
  simp only [asr, step_sbfm, execSBFM_eq_asr, h]

theorem step_sbfx (dst src : GPReg) (lsb width : Nat)
    (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) (rf : RegFile) :
    (sbfx dst src lsb width).step rf =
      rf.set dst (BitVec.signExtend 64 (BitVec.setWidth width (rf.get src >>> lsb))) := by
  simp only [sbfx, step_sbfm, execSBFM_eq_sbfx _ lsb width h1 h2]

theorem step_bfi (dst src : GPReg) (lsb width : Nat)
    (h1 : 1 ≤ width) (h2 : lsb + width ≤ 64) (rf : RegFile) :
    (bfi dst src lsb width).step rf =
      rf.set dst ((rf.get dst &&& ~~~(Bits.lowMask 64 width <<< lsb)) |||
        ((rf.get src &&& Bits.lowMask 64 width) <<< lsb)) := by
  simp only [bfi, step_bfm, execBFM_eq_bfi _ _ lsb width h1 h2]

theorem step_andLowMask (dst src : GPReg) (w : Nat) (h1 : 1 ≤ w) (h2 : w ≤ 64)
    (rf : RegFile) :
    (andLowMask dst src w).step rf = rf.set dst (rf.get src &&& Bits.lowMask 64 w) := by
  simp only [andLowMask, step_logicalImm, LogicOp.eval, bitmaskImm_lowMask w h1 h2]

@[simp]
theorem step_orr (dst rn rm : GPReg) (rf : RegFile) :
    (orr dst rn rm).step rf = rf.set dst (rf.get rn ||| rf.get rm) := by
  simp [orr, LogicOp.eval]

end ARM64
