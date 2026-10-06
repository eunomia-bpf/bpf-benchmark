/-
  The AArch64 subset a BPF JIT emits for kinsns.  Flags and memory are not
  modelled.

  The bitfield instructions follow the ARM ARM pseudocode rather than the
  "obvious" shift-and-mask reading, so the alias encodings the JIT actually
  emits (`LSR`, `LSL`, `UBFX`, `UXT*`, `SXT*`, `ROR`, `BFI`) are *derived* in
  `ARM64/Semantics.lean` rather than assumed:

  ```
    (wmask, tmask) = DecodeBitMasks(N, imms, immr, FALSE)
    UBFM: X[d] = (ROR(X[n], R) AND wmask) AND tmask
    SBFM: X[d] = (Replicate(X[n]<S>) AND NOT tmask) OR ((ROR(X[n], R) AND wmask) AND tmask)
  ```

  `DecodeBitMasks` is specialised to the 64-bit variant (`sf = 1`, `N = 1`),
  where `esize = 64` makes `Replicate` the identity; that is the only variant a
  64-bit JIT emits.  Cross-checked against LNSym's `Arm/Insts/DPI/Bitfield.lean`.
-/
import KinsnLean4.Util.Bits

namespace ARM64

/-! ## Registers -/

/-- `xzr` reads as zero and discards writes. -/
inductive GPReg where
  | x0 | x1 | x2 | x3 | x4 | x5 | x6 | x7
  | x8 | x9 | x10 | x11 | x12 | x13 | x14 | x15
  | x16 | x17 | x18 | x19 | x20 | x21 | x22 | x23
  | x24 | x25 | x26 | x27 | x28 | x29 | x30
  | xzr
  deriving DecidableEq, Repr, Inhabited

/-- Raw backing store; always go through `get`/`set`, which implement `xzr`. -/
abbrev RegFile := GPReg → BitVec 64

def RegFile.get (rf : RegFile) (r : GPReg) : BitVec 64 :=
  if r = .xzr then 0 else rf r

def RegFile.set (rf : RegFile) (r : GPReg) (v : BitVec 64) : RegFile :=
  fun r' => if r' = r then v else rf r'

@[simp]
theorem RegFile.get_xzr (rf : RegFile) : rf.get .xzr = 0 := by simp [RegFile.get]

@[simp]
theorem RegFile.get_set_same (rf : RegFile) (r : GPReg) (v : BitVec 64)
    (h : r ≠ .xzr) : (rf.set r v).get r = v := by
  simp [RegFile.get, RegFile.set, h]

@[simp]
theorem RegFile.get_set_other (rf : RegFile) (r r' : GPReg) (v : BitVec 64)
    (h : r' ≠ r) : (rf.set r v).get r' = rf.get r' := by
  simp [RegFile.get, RegFile.set, h]

/-! ## Shifted register operands -/

/-- The `shift` field of data-processing instructions. -/
inductive ShiftType where
  | LSL | LSR | ASR | ROR
  deriving Repr, DecidableEq, Inhabited

/-- `ShiftReg` from the shared pseudocode. -/
def shiftReg (v : BitVec 64) (st : ShiftType) (amount : Nat) : BitVec 64 :=
  match st with
  | .LSL => v <<< amount
  | .LSR => v >>> amount
  | .ASR => v.sshiftRight amount
  | .ROR => v.rotateRight amount

@[simp] theorem shiftReg_lsl_zero (v : BitVec 64) : shiftReg v .LSL 0 = v := by
  simp [shiftReg]

/-! ## DecodeBitMasks

  For `immN = 1` the pseudocode collapses to `len = 6`, `esize = 64` and

  ```
    wmask = ROR(Ones(S + 1), R)
    tmask = Ones(d + 1)          where d = (S - R) mod 64
  ```
-/

/-- `DecodeBitMasks(1, imms, immr, FALSE)`, returning `(wmask, tmask)`. -/
def decodeBitMasks64 (immr imms : BitVec 6) : BitVec 64 × BitVec 64 :=
  ((Bits.lowMask 64 (imms.toNat + 1)).rotateRight immr.toNat,
   Bits.lowMask 64 ((imms - immr).toNat + 1))

/-- The constant an `AND`/`ORR`/`EOR` bitmask immediate denotes. -/
def bitmaskImm (immr imms : BitVec 6) : BitVec 64 := (decodeBitMasks64 immr imms).1

/-- `UBFM Xd, Xn, #immr, #imms` (opc = 0b10), 64-bit form. -/
def execUBFM (src : BitVec 64) (immr imms : BitVec 6) : BitVec 64 :=
  let m := decodeBitMasks64 immr imms
  ((src.rotateRight immr.toNat) &&& m.1) &&& m.2

/-- `SBFM Xd, Xn, #immr, #imms` (opc = 0b00), 64-bit form. -/
def execSBFM (src : BitVec 64) (immr imms : BitVec 6) : BitVec 64 :=
  let m := decodeBitMasks64 immr imms
  let bot := (src.rotateRight immr.toNat) &&& m.1
  let top : BitVec 64 := Bits.replicate (src.getLsbD imms.toNat) 64
  (top &&& ~~~m.2) ||| (bot &&& m.2)

/-- `BFM Xd, Xn, #immr, #imms` (opc = 0b01), 64-bit form: insert into `dst`. -/
def execBFM (dst src : BitVec 64) (immr imms : BitVec 6) : BitVec 64 :=
  let m := decodeBitMasks64 immr imms
  let bot := (dst &&& ~~~m.1) ||| ((src.rotateRight immr.toNat) &&& m.1)
  (dst &&& ~~~m.2) ||| (bot &&& m.2)

/-- The 64 bits of `Xn:Xm` starting at bit `lsb`. -/
def execEXTR (rn rm : BitVec 64) (lsb : BitVec 6) : BitVec 64 :=
  if lsb = 0 then rm else (rn <<< (64 - lsb.toNat)) ||| (rm >>> lsb.toNat)

/-! ## Byte reversal -/

/-- `REV Xd, Xn`. -/
def execREV64 (v : BitVec 64) : BitVec 64 := Bits.bswap64 v

/-- `REV32 Xd, Xn`: reverse bytes within each 32-bit word. -/
def execREV32 (v : BitVec 64) : BitVec 64 :=
  BitVec.setWidth 64 (Bits.bswap32 (BitVec.setWidth 32 (v >>> 32))) <<< 32 |||
  BitVec.setWidth 64 (Bits.bswap32 (BitVec.setWidth 32 v))

/-- `REV16 Wd, Wn`: reverse bytes within each halfword of the low word. -/
def execREV16W (v : BitVec 64) : BitVec 64 :=
  BitVec.setWidth 64 (Bits.bswap16 (BitVec.setWidth 16 (v >>> 16))) <<< 16 |||
  BitVec.setWidth 64 (Bits.bswap16 (BitVec.setWidth 16 v))

/-- `REV Wd, Wn`. -/
def execREV32W (v : BitVec 64) : BitVec 64 :=
  BitVec.setWidth 64 (Bits.bswap32 (BitVec.setWidth 32 v))

/-! ## Instructions -/

/-- The `AND`/`ORR`/`EOR`/`BIC` family. -/
inductive LogicOp where
  | and | orr | eor | bic
  deriving DecidableEq, Repr

def LogicOp.eval : LogicOp → BitVec 64 → BitVec 64 → BitVec 64
  | .and, a, b => a &&& b
  | .orr, a, b => a ||| b
  | .eor, a, b => a ^^^ b
  | .bic, a, b => a &&& ~~~b


inductive Insn where
  /-- `UBFM Xd, Xn, #immr, #imms` -/
  | ubfm (dst src : GPReg) (immr imms : BitVec 6)
  /-- `SBFM Xd, Xn, #immr, #imms` -/
  | sbfm (dst src : GPReg) (immr imms : BitVec 6)
  /-- `BFM Xd, Xn, #immr, #imms` -/
  | bfm (dst src : GPReg) (immr imms : BitVec 6)
  /-- `EXTR Xd, Xn, Xm, #lsb` -/
  | extr (dst rn rm : GPReg) (lsb : BitVec 6)
  /-- `MOVZ Xd, #imm16, LSL #(16*hw)` -/
  | movz (dst : GPReg) (imm16 : BitVec 16) (hw : Nat)
  /-- `MOVK Xd, #imm16, LSL #(16*hw)` -/
  | movk (dst : GPReg) (imm16 : BitVec 16) (hw : Nat)
  /-- `REV Xd, Xn` -/
  | rev64 (dst src : GPReg)
  /-- `REV32 Xd, Xn` -/
  | rev32 (dst src : GPReg)
  /-- `REV Wd, Wn` -/
  | rev32w (dst src : GPReg)
  /-- `REV16 Wd, Wn` -/
  | rev16w (dst src : GPReg)
  /-- `AND/ORR/EOR/BIC Xd, Xn, Xm{, shift #amount}` -/
  | logicalReg (op : LogicOp) (dst rn rm : GPReg) (st : ShiftType) (amount : Nat)
  /-- `AND/ORR/EOR Xd, Xn, #bitmask` (bitmask immediate encoding) -/
  | logicalImm (op : LogicOp) (dst rn : GPReg) (immr imms : BitVec 6)
  /-- `ADD Xd, Xn, Xm{, shift #amount}` -/
  | addReg (dst rn rm : GPReg) (st : ShiftType) (amount : Nat)
  /-- `SUB Xd, Xn, Xm{, shift #amount}` -/
  | subReg (dst rn rm : GPReg) (st : ShiftType) (amount : Nat)
  /-- Register-controlled shift; the amount is taken modulo 64. -/
  | shiftV (st : ShiftType) (dst rn rm : GPReg)
  deriving Repr

namespace Insn

def dstReg : Insn → GPReg
  | .ubfm dst _ _ _ => dst
  | .sbfm dst _ _ _ => dst
  | .bfm dst _ _ _ => dst
  | .extr dst _ _ _ => dst
  | .movz dst _ _ => dst
  | .movk dst _ _ => dst
  | .rev64 dst _ => dst
  | .rev32 dst _ => dst
  | .rev32w dst _ => dst
  | .rev16w dst _ => dst
  | .logicalReg _ dst _ _ _ _ => dst
  | .logicalImm _ dst _ _ _ => dst
  | .addReg dst _ _ _ _ => dst
  | .subReg dst _ _ _ _ => dst
  | .shiftV _ dst _ _ => dst

def step (insn : Insn) (rf : RegFile) : RegFile :=
  match insn with
  | .ubfm dst src immr imms => rf.set dst (execUBFM (rf.get src) immr imms)
  | .sbfm dst src immr imms => rf.set dst (execSBFM (rf.get src) immr imms)
  | .bfm dst src immr imms => rf.set dst (execBFM (rf.get dst) (rf.get src) immr imms)
  | .extr dst rn rm lsb => rf.set dst (execEXTR (rf.get rn) (rf.get rm) lsb)
  | .movz dst imm16 hw => rf.set dst (BitVec.setWidth 64 imm16 <<< (16 * hw))
  | .movk dst imm16 hw =>
      rf.set dst ((rf.get dst &&& ~~~(Bits.lowMask 64 16 <<< (16 * hw))) |||
        (BitVec.setWidth 64 imm16 <<< (16 * hw)))
  | .rev64 dst src => rf.set dst (execREV64 (rf.get src))
  | .rev32 dst src => rf.set dst (execREV32 (rf.get src))
  | .rev32w dst src => rf.set dst (execREV32W (rf.get src))
  | .rev16w dst src => rf.set dst (execREV16W (rf.get src))
  | .logicalReg op dst rn rm st amount =>
      rf.set dst (op.eval (rf.get rn) (shiftReg (rf.get rm) st amount))
  | .logicalImm op dst rn immr imms =>
      rf.set dst (op.eval (rf.get rn) (bitmaskImm immr imms))
  | .addReg dst rn rm st amount =>
      rf.set dst (rf.get rn + shiftReg (rf.get rm) st amount)
  | .subReg dst rn rm st amount =>
      rf.set dst (rf.get rn - shiftReg (rf.get rm) st amount)
  | .shiftV st dst rn rm =>
      rf.set dst (shiftReg (rf.get rn) st ((rf.get rm).toNat % 64))

theorem step_other (insn : Insn) (rf : RegFile) (r : GPReg) (h : r ≠ insn.dstReg) :
    (insn.step rf).get r = rf.get r := by
  cases insn <;> simp_all [step, dstReg]

end Insn

def exec (insns : List Insn) (rf : RegFile) : RegFile :=
  insns.foldl (fun rf insn => insn.step rf) rf

/-- The registers a straight-line block may write. -/
def writes (insns : List Insn) : List GPReg := insns.map Insn.dstReg

/-! ## Assembler aliases

  Definitions in terms of the real encodings; `ARM64/Semantics.lean` proves
  each denotes what its mnemonic says. -/

/-- `MOV Xd, Xn` is `ORR Xd, XZR, Xn`. -/
@[inline] def mov (dst src : GPReg) : Insn := .logicalReg .orr dst .xzr src .LSL 0
/-- `LSR Xd, Xn, #n` is `UBFM Xd, Xn, #n, #63`. -/
@[inline] def lsr (dst src : GPReg) (n : Nat) : Insn :=
  .ubfm dst src (BitVec.ofNat 6 n) 63
/-- `LSL Xd, Xn, #n` is `UBFM Xd, Xn, #(-n mod 64), #(63-n)`. -/
@[inline] def lsl (dst src : GPReg) (n : Nat) : Insn :=
  .ubfm dst src (BitVec.ofNat 6 ((64 - n) % 64)) (BitVec.ofNat 6 (63 - n))
/-- `ASR Xd, Xn, #n` is `SBFM Xd, Xn, #n, #63`. -/
@[inline] def asr (dst src : GPReg) (n : Nat) : Insn :=
  .sbfm dst src (BitVec.ofNat 6 n) 63
/-- `UBFX Xd, Xn, #lsb, #width` is `UBFM Xd, Xn, #lsb, #(lsb+width-1)`. -/
@[inline] def ubfx (dst src : GPReg) (lsb width : Nat) : Insn :=
  .ubfm dst src (BitVec.ofNat 6 lsb) (BitVec.ofNat 6 (lsb + width - 1))
/-- `SBFX Xd, Xn, #lsb, #width` is `SBFM Xd, Xn, #lsb, #(lsb+width-1)`. -/
@[inline] def sbfx (dst src : GPReg) (lsb width : Nat) : Insn :=
  .sbfm dst src (BitVec.ofNat 6 lsb) (BitVec.ofNat 6 (lsb + width - 1))
/-- `ROR Xd, Xn, #n` is `EXTR Xd, Xn, Xn, #n`. -/
@[inline] def ror (dst src : GPReg) (n : Nat) : Insn :=
  .extr dst src src (BitVec.ofNat 6 n)
/-- `UXTB/UXTH/UXTW Xd, Wn` are `UBFM Xd, Xn, #0, #(w-1)`. -/
@[inline] def uxt (dst src : GPReg) (w : Nat) : Insn :=
  .ubfm dst src 0 (BitVec.ofNat 6 (w - 1))
/-- `SXTB/SXTH/SXTW Xd, Wn` are `SBFM Xd, Xn, #0, #(w-1)`. -/
@[inline] def sxt (dst src : GPReg) (w : Nat) : Insn :=
  .sbfm dst src 0 (BitVec.ofNat 6 (w - 1))
/-- `AND Xd, Xn, #(2^w - 1)` via the bitmask-immediate encoding. -/
@[inline] def andLowMask (dst src : GPReg) (w : Nat) : Insn :=
  .logicalImm .and dst src 0 (BitVec.ofNat 6 (w - 1))
/-- `BFI Xd, Xn, #lsb, #width` is `BFM Xd, Xn, #(-lsb mod 64), #(width-1)`. -/
@[inline] def bfi (dst src : GPReg) (lsb width : Nat) : Insn :=
  .bfm dst src (BitVec.ofNat 6 ((64 - lsb) % 64)) (BitVec.ofNat 6 (width - 1))
/-- `ORR Xd, Xn, Xm` -/
@[inline] def orr (dst rn rm : GPReg) : Insn := .logicalReg .orr dst rn rm .LSL 0

end ARM64
