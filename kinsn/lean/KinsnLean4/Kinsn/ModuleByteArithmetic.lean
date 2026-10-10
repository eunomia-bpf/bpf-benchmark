import KinsnLean4.Kinsn.ModuleWideAlu
import KinsnLean4.Kinsn.ModuleNarrowLogic
import KinsnLean4.Kinsn.ModuleControlDispatch
import KinsnLean4.Kinsn.ModuleRotateOne

namespace Kinsn.ModuleByteArithmetic
open ModuleMovStore (Source)

def value (sub : Bool) (v c : BitVec 64) : BitVec 64 :=
  X86.writeWidth 8 v (if sub then v-c else v+c)

def step (sub : Bool) (d : BPF.Reg) (k : Nat) : List BPF.MInsn :=
  let bit := BitVec.ofNat 64 (2^k)
  let mask := BitVec.ofNat 64 (256-2^k)
  if sub then
    [.branch .bitSet .w64 d (.imm mask) 1,
     .core (.alu .add .w64 d (.imm 256)),
     .core (.alu .add .w64 d (.imm (-bit)))]
  else
    [.core (.alu .add .w64 d (.imm bit)),
     .branch .bitSet .w64 d (.imm mask) 1,
     .core (.alu .add .w64 d (.imm 18446744073709551360))]

theorem write_decompose (v z : BitVec 64) :
    X86.writeWidth 8 v z = (BitVec.extractLsb' 8 56 v) ++ (BitVec.setWidth 8 z) := by
  unfold X86.writeWidth
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [BitVec.getLsbD_append]
  interval_cases i <;> simp [Bits.lowMask]

theorem write_low (v z : BitVec 64) :
    BitVec.setWidth 8 (X86.writeWidth 8 v z) = BitVec.setWidth 8 z := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  interval_cases i <;> simp [X86.writeWidth, Bits.lowMask]

theorem write_high (v z : BitVec 64) :
    BitVec.extractLsb' 8 56 (X86.writeWidth 8 v z) = BitVec.extractLsb' 8 56 v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  interval_cases i <;> simp [X86.writeWidth, Bits.lowMask]

theorem write_nat (v z : BitVec 64) :
    (X86.writeWidth 8 v z).toNat = v.toNat / 256 * 256 + z.toNat % 256 := by
  rw [write_decompose, BitVec.toNat_append]
  have hv := v.isLt
  simp only [BitVec.extractLsb'_toNat, BitVec.toNat_setWidth,
    Nat.shiftRight_eq_div_pow, Nat.shiftLeft_eq]
  norm_num at hv ⊢
  rw [Nat.mul_comm _ 256]
  have hor := Nat.two_pow_add_eq_or_of_lt (i := 8)
    (a := v.toNat / 256 % 72057594037927936) (b := z.toNat % 256) (by omega)
  norm_num at hor
  rw [← hor]
  omega

theorem mask_bits (k : Nat) (hk : k < 8) (v : BitVec 64) :
    v &&& BitVec.ofNat 64 (256-2^k) =
      (BitVec.setWidth 64 (BitVec.setWidth 8 v) >>> k) <<< k := by
  interval_cases k
  all_goals apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi
  all_goals interval_cases i <;> simp

theorem mask_nat (k : Nat) (hk : k < 8) (v : BitVec 64) :
    (v &&& BitVec.ofNat 64 (256-2^k)).toNat = v.toNat % 256 / 2^k * 2^k := by
  rw [mask_bits k hk]
  interval_cases k <;>
    simp [BitVec.toNat_shiftLeft, BitVec.toNat_ushiftRight, BitVec.toNat_setWidth]
  all_goals omega

theorem zero_nat (a : BitVec 64) : a = 0 ↔ a.toNat = 0 := by
  constructor
  · intro he; subst a; rfl
  · intro he; apply BitVec.eq_of_toNat_eq; simpa using he

theorem mask_zero (k : Nat) (hk : k < 8) (v : BitVec 64) :
    v &&& BitVec.ofNat 64 (256-2^k) = 0 ↔ v.toNat % 256 < 2^k := by
  rw [zero_nat, mask_nat k hk, Nat.mul_eq_zero]
  have hp : 0 < 2^k := Nat.two_pow_pos k
  simp [Nat.ne_of_gt hp, Nat.div_eq_zero_iff]

private theorem add_arith (n p : Nat) (hn : n < 2^64)
    (hp : 0 < p ∧ p ≤ 128) :
    (if (n+p)%2^64%256 < p then
      ((n+p)%2^64+18446744073709551360)%2^64
     else (n+p)%2^64) =
      n/256*256+(n+p)%2^64%256 := by
  norm_num at hn ⊢
  split_ifs <;> omega

private theorem sub_arith (n p : Nat) (hn : n < 18446744073709551616)
    (hp : 0 < p ∧ p ≤ 128) :
    ((if n%256 < p then (n+256)%18446744073709551616 else n) +
      (18446744073709551616-p))%18446744073709551616 =
      n/256*256+(n+18446744073709551616-p)%18446744073709551616%256 := by
  split_ifs <;> omega

theorem power_bounds (k : Nat) (hk : k < 8) : 0 < 2^k ∧ 2^k ≤ 128 := by
  interval_cases k <;> norm_num

theorem bit_nat (k : Nat) (hk : k < 8) : (BitVec.ofNat 64 (2^k)).toNat = 2^k := by
  have hp := power_bounds k hk
  simp [BitVec.toNat_ofNat]
  omega

theorem correction_nat : (18446744073709551360 : BitVec 64).toNat =
    18446744073709551360 := by decide +kernel

theorem twof_nat : (256 : BitVec 64).toNat = 256 := by decide +kernel

theorem add_value_general (v c t : BitVec 64)
    (ht : t.toNat = 18446744073709551360)
    (hp : 0 < c.toNat ∧ c.toNat ≤ 128) :
    (if (v+c).toNat%256 < c.toNat then v+c+t else v+c) =
      X86.writeWidth 8 v (v+c) := by
  apply BitVec.eq_of_toNat_eq
  rw [write_nat]
  simp only [apply_ite, BitVec.toNat_add, ht]
  exact add_arith v.toNat c.toNat v.isLt hp

theorem add_value (v c : BitVec 64) (hp : 0 < c.toNat ∧ c.toNat ≤ 128) :
    (if (v+c).toNat%256 < c.toNat then v+c+18446744073709551360 else v+c) =
      X86.writeWidth 8 v (v+c) :=
  add_value_general v c _ correction_nat hp

theorem sub_value (v c : BitVec 64) (hp : 0 < c.toNat ∧ c.toNat ≤ 128) :
    (if v.toNat%256 < c.toNat then v+256 else v) + (-c) =
      X86.writeWidth 8 v (v-c) := by
  have hn : (-c).toNat = 2^64-c.toNat := by
    simpa [BitVec.toNat_neg] using hp.1
  apply BitVec.eq_of_toNat_eq
  rw [write_nat]
  simp only [BitVec.toNat_add, apply_ite, hn, BitVec.toNat_sub, twof_nat]
  conv_rhs =>
    rw [Nat.add_comm (2^64-c.toNat) v.toNat,
      ← Nat.add_sub_assoc (by have hc := c.isLt; omega : c.toNat ≤ 2^64)]
  exact sub_arith v.toNat c.toNat v.isLt hp

theorem step_value (sub : Bool) (k : Nat) (hk : k < 8) (v : BitVec 64) :
    (if sub then (if v &&& BitVec.ofNat 64 (256-2^k) ≠ 0 then v
      else v+256) + (-BitVec.ofNat 64 (2^k))
     else if (v + BitVec.ofNat 64 (2^k)) &&& BitVec.ofNat 64 (256-2^k) ≠ 0
       then v + BitVec.ofNat 64 (2^k) else v + BitVec.ofNat 64 (2^k) + 18446744073709551360) =
    value sub v (BitVec.ofNat 64 (2^k)) := by
  have hp : 0 < (BitVec.ofNat 64 (2^k)).toNat ∧
      (BitVec.ofNat 64 (2^k)).toNat ≤ 128 := by
    rw [bit_nat k hk]
    exact power_bounds k hk
  cases sub
  · simp only [Bool.false_eq_true, ↓reduceIte, value, ne_eq, mask_zero k hk, ite_not]
    simpa only [bit_nat k hk] using add_value v (BitVec.ofNat 64 (2^k)) hp
  · simp only [↓reduceIte, value, ne_eq, mask_zero k hk, ite_not]
    simpa only [bit_nat k hk] using sub_value v (BitVec.ofNat 64 (2^k)) hp

def effect (d : BPF.Reg) (v : BitVec 64) (s : BPF.State) : BPF.State :=
  { s with regs := BPF.RegFile.set s.regs d v }

theorem step_exec (sub : Bool) (d : BPF.Reg) (k : Nat) (hk : k < 8)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (step sub d k ++ tail) s =
      BPF.mexec tail (effect d (value sub (s.regs d) (BitVec.ofNat 64 (2^k))) s) := by
  have hv := step_value sub k hk (s.regs d)
  cases sub
  · by_cases hz : (s.regs d + BitVec.ofNat 64 (2^k)) &&& BitVec.ofNat 64 (256-2^k) = 0#64
    all_goals simp [step, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      BPF.Src.eval, BPF.Cond.test, BPF.Cond.eval, hz, Machine.State.set,
      BPF.RegFile.set_same, BPF.RegFile.set_set_same, effect] at hv ⊢
    all_goals rw [← hv]
  · by_cases hz : s.regs d &&& BitVec.ofNat 64 (256-2^k) = 0#64
    all_goals simp [step, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
      BPF.Src.eval, BPF.Cond.test, BPF.Cond.eval, hz, Machine.State.set,
      BPF.RegFile.set_same, BPF.RegFile.set_set_same, effect] at hv ⊢
    all_goals rw [← hv]

def loop (sub : Bool) (d : BPF.Reg) (c : BitVec 8) : Nat → List BPF.MInsn
  | 0 => []
  | k+1 => (if c.getLsbD k then step sub d k else []) ++ loop sub d c k

def loopValue (sub : Bool) (c : BitVec 8) : Nat → BitVec 64 → BitVec 64
  | 0, v => v
  | k+1, v => loopValue sub c k
      (if c.getLsbD k then value sub v (BitVec.ofNat 64 (2^k)) else v)

theorem loop_exec (sub : Bool) (d : BPF.Reg) (c : BitVec 8) (k : Nat) (hk : k ≤ 8)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (loop sub d c k ++ tail) s =
      BPF.mexec tail (effect d (loopValue sub c k (s.regs d)) s) := by
  induction k generalizing s with
  | zero => simp [loop, loopValue, effect, ModuleRotateOne.set_self]
  | succ k ih =>
    simp only [loop, List.append_assoc, loopValue]
    split_ifs with h
    · rw [step_exec sub d k (by omega), ih (by omega)]
      simp [effect, BPF.RegFile.set_same, BPF.RegFile.set_set_same, h]
    · simpa [effect] using ih (by omega) s

theorem low_sub (a b : BitVec 64) :
    BitVec.setWidth 8 (a-b) = BitVec.setWidth 8 a - BitVec.setWidth 8 b := by
  apply BitVec.eq_of_toNat_eq
  have ha := a.isLt
  have hb := b.isLt
  simp [BitVec.toNat_sub, BitVec.toNat_setWidth]
  omega

theorem value_comp (sub : Bool) (v a b : BitVec 64) :
    value sub (value sub v a) b = value sub v (a+b) := by
  cases sub <;> simp only [value, Bool.false_eq_true, ↓reduceIte]
  all_goals rw [write_decompose, write_high]
  · rw [write_decompose v (v+(a+b))]
    congr 1
    simp [BitVec.setWidth_add _ _ (by decide : 8 ≤ 64), write_low, BitVec.add_assoc]
  · rw [write_decompose v (v-(a+b))]
    congr 1
    simp [low_sub, BitVec.setWidth_add _ _ (by decide : 8 ≤ 64), write_low, BitVec.sub_sub]
def amount (c : BitVec 8) : Nat → BitVec 64
  | 0 => 0
  | k+1 => (if c.getLsbD k then BitVec.ofNat 64 (2^k) else 0) + amount c k

theorem loop_value_general (sub : Bool) (c : BitVec 8) (k : Nat) (v : BitVec 64) :
    loopValue sub c k v = value sub v (amount c k) := by
  induction k generalizing v with
  | zero =>
    simp [loopValue, amount, value, X86.writeWidth]
    apply BitVec.eq_of_getLsbD_eq
    intro i hi
    interval_cases i <;> cases sub <;> simp [Bits.lowMask]
  | succ k ih =>
    simp only [loopValue, amount]
    split_ifs with h
    · rw [ih, value_comp]
    · simpa using ih v

-- The complete operand domain is eight bits; this closed finite identity is
-- checked in the kernel, independently of destination arithmetic.
set_option maxHeartbeats 0 in
theorem amount_byte (c : BitVec 8) : amount c 8 = BitVec.setWidth 64 c := by
  have hc := c.isLt
  generalize he : c.toNat = n at hc
  have hv : c = BitVec.ofNat 8 n := by
    apply BitVec.eq_of_toNat_eq
    simp [he, BitVec.toNat_ofNat, Nat.mod_eq_of_lt hc]
  rw [hv]
  interval_cases n <;> decide +kernel

theorem loop_value (sub : Bool) (c : BitVec 8) (v : BitVec 64) :
    loopValue sub c 8 v = value sub v (BitVec.setWidth 64 c) := by
  rw [loop_value_general, amount_byte]

def leaf (kind : ModuleWideAlu.Kind) (d : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  if n % 256 = 0 then [.ja 0] else if kind = .xor then
    [.core (.alu .xor .w64 d (.imm (BitVec.ofNat 64 (n%256))))]
  else loop (kind = .sub) d (BitVec.ofNat 8 n) 8

def leafValue (kind : ModuleWideAlu.Kind) (v : BitVec 64) (n : Nat) : BitVec 64 :=
  X86.writeWidth 8 v (kind.native.eval v (BitVec.ofNat 64 (n%256)))

theorem xor_byte (v : BitVec 64) (c : BitVec 8) :
    v ^^^ BitVec.setWidth 64 c = X86.writeWidth 8 v (v ^^^ BitVec.setWidth 64 c) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  interval_cases i <;> simp [X86.writeWidth, Bits.lowMask]

theorem byte_zero (kind : ModuleWideAlu.Kind) (hk : kind = .add ∨ kind = .sub ∨ kind = .xor)
    (v : BitVec 64) : leafValue kind v 0 = v := by
  rcases hk with rfl | rfl | rfl <;>
    simp [leafValue, ModuleWideAlu.Kind.native, X86.AluOp.eval, X86.writeWidth]
  all_goals apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi
  all_goals interval_cases i <;> simp [Bits.lowMask]

theorem byte_cast (n : Nat) : BitVec.setWidth 64 (BitVec.ofNat 8 n) =
    BitVec.ofNat 64 (n%256) := by
  apply BitVec.eq_of_toNat_eq
  simp [BitVec.toNat_setWidth, BitVec.toNat_ofNat, Nat.mod_eq_of_lt (Nat.mod_lt n (by decide : 0<256))]

theorem leaf_exec (kind : ModuleWideAlu.Kind)
    (hk : kind = .add ∨ kind = .sub ∨ kind = .xor) (d : BPF.Reg) (n : Nat)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (leaf kind d n ++ tail) s =
      BPF.mexec tail (effect d (leafValue kind (s.regs d) n) s) := by
  by_cases hz : n%256 = 0
  · simp [leaf, hz, BPF.mexec, leafValue, byte_zero kind hk, effect,
      ModuleRotateOne.set_self]
    have he : X86.writeWidth 8 (s.regs d) (kind.native.eval (s.regs d) 0#64) = s.regs d :=
      by simpa [leafValue] using byte_zero kind hk (s.regs d)
    rw [he]
    simp [ModuleRotateOne.set_self]
  · rcases hk with rfl | rfl | rfl
    · simp only [leaf, if_neg hz, reduceCtorEq, ↓reduceIte, decide_true, decide_false]
      rw [loop_exec false d _ 8 (by decide), loop_value]
      simp [effect, value, leafValue, byte_cast, ModuleWideAlu.Kind.native, X86.AluOp.eval]
    · simp only [leaf, if_neg hz, reduceCtorEq, ↓reduceIte, decide_true, decide_false]
      rw [loop_exec true d _ 8 (by decide), loop_value]
      simp [effect, value, leafValue, byte_cast, ModuleWideAlu.Kind.native, X86.AluOp.eval]
    · simp [leaf, hz, BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval,
        BPF.Src.eval, leafValue, effect, ModuleWideAlu.Kind.native, X86.AluOp.eval,
        ← byte_cast, ← xor_byte]

def sourceValid : Source → Prop
  | .reg _ => True
  | .imm v => v.toNat < 256

def bpf (kind : ModuleWideAlu.Kind) (d : BPF.Reg) : Source → List BPF.MInsn
  | .reg r => ModuleControlDispatch.tree r (leaf kind d) 8 0
  | .imm v => leaf kind d v.toNat

def native (m : X86RegMap) (kind : ModuleWideAlu.Kind) (d : BPF.Reg) :
    Source → List X86.MInsn
  | .reg r => [.aluNarrow kind.native 8 (m.map d) (m.map r)]
  | .imm v => [.aluImmNarrow kind.native 8 (m.map d) (BitVec.signExtend 64 v)]

def spec (kind : ModuleWideAlu.Kind) (d : BPF.Reg) (src : Source) (s : Outcome) : Outcome :=
  { s with regs := (BPF.RegFile.set s.regs d
    (X86.writeWidth 8 (s.regs d) (kind.native.eval (s.regs d) (src.word s.regs)))) }

theorem leaf_value_native (kind : ModuleWideAlu.Kind)
    (hk : kind = .add ∨ kind = .sub ∨ kind = .xor) (v c : BitVec 64) :
    leafValue kind v c.toNat = X86.writeWidth 8 v (kind.native.eval v c) := by
  have hc : BitVec.ofNat 64 (c.toNat%256) = BitVec.setWidth 64 (BitVec.setWidth 8 c) := by
    apply BitVec.eq_of_toNat_eq
    simp [BitVec.toNat_ofNat, BitVec.toNat_setWidth]
  rcases hk with rfl | rfl | rfl
  all_goals simp only [leafValue, hc, ModuleWideAlu.Kind.native, X86.AluOp.eval]
  all_goals rw [write_decompose, write_decompose]
  all_goals congr 1
  all_goals simp [BitVec.setWidth_add _ _ (by decide : 8 ≤ 64),
    low_sub]

theorem immediate_word (v : BitVec 32) (hv : v.toNat < 256) :
    (BitVec.signExtend 64 v).toNat = v.toNat := by
  have hs : v.msb = false := by
    rw [BitVec.msb_eq_false_iff_two_mul_lt]
    omega
  simp [BitVec.toNat_signExtend, hs]
  omega

theorem bpf_correct (kind : ModuleWideAlu.Kind)
    (hk : kind = .add ∨ kind = .sub ∨ kind = .xor) (d : BPF.Reg) (src : Source)
    (hv : sourceValid src) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf kind d src) s) = spec kind d src (observeBpf s) := by
  cases src with
  | reg r =>
    simp only [bpf]
    rw [← List.append_nil (ModuleControlDispatch.tree r (leaf kind d) 8 0),
      ModuleControlDispatch.exec_tree r (leaf kind d)
        (fun n s => effect d (leafValue kind (s.regs d) n) s) (leaf_exec kind hk d)
        8 0 s [], ModuleDispatch.selected_eq _ _ _ (by decide : 8 ≤ 64)]
    simpa [BPF.mexec, effect, spec, observeBpf, Source.word, leafValue,
      Nat.mod_mod] using congrArg (BPF.RegFile.set s.regs d)
        (leaf_value_native kind hk (s.regs d) (s.regs r))
  | imm v =>
    rw [bpf, ← List.append_nil (leaf kind d v.toNat), leaf_exec kind hk d v.toNat]
    have he := leaf_value_native kind hk (s.regs d) (BitVec.signExtend 64 v)
    rw [immediate_word v hv] at he
    simpa [BPF.mexec, effect, spec, observeBpf, Source.word] using
      congrArg (BPF.RegFile.set s.regs d) he

theorem loop_writes (sub : Bool) (d : BPF.Reg) (c : BitVec 8) (k : Nat) :
    ∀ r, r ∈ BPF.mwrites (loop sub d c k) → r = d := by
  induction k with
  | zero => simp [loop, BPF.mwrites]
  | succ k ih =>
    intro r hr
    simp only [loop, BPF.mwrites, List.flatMap_append, List.mem_append] at hr
    rcases hr with hr | hr
    · split_ifs at hr <;> cases sub <;>
        simpa [step, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using hr
    · exact ih r hr

theorem leaf_writes (kind : ModuleWideAlu.Kind) (d : BPF.Reg) (n : Nat) :
    ∀ r, r ∈ BPF.mwrites (leaf kind d n) → r = d := by
  intro r hr
  simp only [leaf] at hr
  split_ifs at hr
  · simpa [BPF.mwrites, BPF.MInsn.writes] using hr
  · simpa [BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using hr
  · exact loop_writes _ d _ _ r hr

def certificate (m : X86RegMap) (kind : ModuleWideAlu.Kind)
    (hk : kind = .add ∨ kind = .sub ∨ kind = .xor) (d : BPF.Reg) (src : Source)
    (hv : sourceValid src) : X86StateEquiv m where
  bpf := bpf kind d src
  native := native m kind d src
  spec := spec kind d src
  writeSet := [d]
  bpfCorrect := bpf_correct kind hk d src hv
  nativeCorrect := by
    intro s
    cases src <;> simp [native, spec, X86.mexec_cons, X86.mexec_nil,
      X86.MInsn.step, observeX86, Source.word, Machine.State.set, BPF.RegFile.set, m.inj.eq_iff]
    all_goals rfl
  bpfWrites := by
    intro r hr
    cases src with
    | reg c => exact List.mem_singleton.mpr (ModuleControlDispatch.writes_tree c
        (leaf kind d) 8 0 d (leaf_writes kind d) r hr)
    | imm v => exact List.mem_singleton.mpr (leaf_writes kind d v.toNat r hr)
  nativeWrites := by
    cases src <;> simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleByteArithmetic
