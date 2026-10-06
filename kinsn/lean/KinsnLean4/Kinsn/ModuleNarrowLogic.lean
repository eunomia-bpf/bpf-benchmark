import KinsnLean4.Kinsn.ModuleDispatch

namespace Kinsn.ModuleNarrowLogic

def mask (k : Nat) : BitVec 64 := BitVec.ofNat 64 (2^k)

/-- C's signed imm32 complement of one low source-bit mask has exactly the
    same 64-bit mask used by the executable model. -/
theorem signed_mask (k : Nat) (hk : k < 16) :
    BitVec.signExtend 64 (~~~BitVec.ofNat 32 (2^k)) = ~~~mask k := by
  interval_cases k <;> decide

/-- C's AND immediate sets every high bit while retaining the decoded low
    immediate. The decoder/emitter restricts this immediate to 8/16 bits. -/
theorem signed_immediate (bits : Nat) (hb : bits = 8 ∨ bits = 16) (imm : BitVec bits) :
    BitVec.signExtend 64 (BitVec.setWidth 32 imm ||| ~~~Bits.lowMask 32 bits) =
      BitVec.setWidth 64 imm ||| ~~~Bits.lowMask 64 bits := by
  rcases hb with hb | hb <;> subst bits <;> apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi
  all_goals simp only [BitVec.getLsbD_signExtend, BitVec.getLsbD_or, BitVec.getLsbD_not,
    BitVec.getLsbD_setWidth, Bits.getLsbD_lowMask, BitVec.msb_eq_getLsbD_last]
  all_goals interval_cases i <;> simp

theorem positive_immediate (bits : Nat) (hb : bits = 8 ∨ bits = 16) (imm : BitVec bits) :
    BitVec.signExtend 64 (BitVec.setWidth 32 imm) = BitVec.setWidth 64 imm := by
  rcases hb with hb | hb <;> subst bits <;> apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi
  all_goals simp only [BitVec.getLsbD_signExtend, BitVec.getLsbD_setWidth,
    BitVec.msb_eq_getLsbD_last]
  all_goals interval_cases i <;> simp

def gateValue (isAnd : Bool) (k : Nat) (v src : BitVec 64) : BitVec 64 :=
  if isAnd then
    if ModuleDispatch.bitTest src k then v else v &&& ~~~mask k
  else if ModuleDispatch.bitTest src k then v ||| mask k else v

/-- x86/bpf_x86_alu.c:instantiate_x86_logic_narrow: each source bit controls
    exactly one AND of its complement or OR of its positive mask. -/
def gate (isAnd : Bool) (d r : BPF.Reg) (k : Nat) : List BPF.MInsn :=
  if isAnd then [.branch .bitSet .w64 r (.imm (mask k)) 1,
    .core (.alu .and .w64 d (.imm (BitVec.signExtend 64 (~~~BitVec.ofNat 32 (2^k)))))] else
    [.branch .bitSet .w64 r (.imm (mask k)) 1, .ja 1,
      .core (.alu .or .w64 d (.imm (mask k)))]

theorem set_self (rf : BPF.RegFile) (d : BPF.Reg) : rf.set d (rf d) = rf := by
  funext r; by_cases h : r = d <;> simp [BPF.RegFile.set, h]

theorem gate_exec (isAnd : Bool) (d r : BPF.Reg) (k : Nat) (hk : k < 16) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (gate isAnd d r k ++ tail) s =
      BPF.mexec tail { s with regs := (BPF.RegFile.set s.regs d
        (gateValue isAnd k (s.regs d) (s.regs r))) } := by
  cases isAnd <;>
    simp [gate, signed_mask k hk, gateValue, ModuleDispatch.bitTest, mask, BPF.mexec, BPF.Cond.test,
      BPF.Cond.eval, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval]
  all_goals split <;> simp_all [set_self]

theorem gate_bit (isAnd : Bool) (k : Nat) (hk : k < 64) (v src : BitVec 64)
    (i : Nat) (hi : i < 64) :
    (gateValue isAnd k v src).getLsbD i =
      if i = k then (if isAnd then v.getLsbD i && src.getLsbD i
        else v.getLsbD i || src.getLsbD i) else v.getLsbD i := by
  have hm : (mask k).getLsbD i = decide (k = i) := by
    simp only [mask, BitVec.getLsbD_ofNat, Nat.testBit_two_pow,
      decide_eq_true hi, Bool.true_and]
  cases isAnd <;> by_cases he : i = k <;> by_cases hb : src.getLsbD k = true <;>
    simp_all [gateValue, ModuleDispatch.bitTest_eq src k hk, Ne.symm]

theorem gate_self (isAnd : Bool) (k : Nat) (hk : k < 64) (v : BitVec 64) :
    gateValue isAnd k v v = v := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [gate_bit isAnd k hk v v i hi]
  split <;> cases isAnd <;> simp

/-- x86/bpf_x86_alu.c:instantiate_x86_logic_narrow's ascending bit loop. -/
def program (isAnd : Bool) (d r : BPF.Reg) (ks : List Nat) : List BPF.MInsn :=
  ks.flatMap (gate isAnd d r)

def folded (isAnd : Bool) (src v : BitVec 64) (ks : List Nat) : BitVec 64 :=
  ks.foldl (fun v k => gateValue isAnd k v src) v

theorem program_exec (isAnd : Bool) (d r : BPF.Reg) (ks : List Nat)
    (hk : ∀ k ∈ ks, k < 16) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (program isAnd d r ks ++ tail) s =
      BPF.mexec tail { s with regs := (BPF.RegFile.set s.regs d
        (folded isAnd (s.regs r) (s.regs d) ks)) } := by
  induction ks generalizing s with
  | nil => simp [program, folded, set_self]
  | cons k ks ih =>
    simp only [program, List.flatMap_cons, List.append_assoc]
    rw [gate_exec _ _ _ _ (hk k (by simp))]
    have hr : BPF.RegFile.set s.regs d
        (gateValue isAnd k (s.regs d) (s.regs r)) r = s.regs r := by
      by_cases h : r = d
      · subst r; simp [gate_self isAnd k (by have h := hk k (by simp); omega)]
      · simp [BPF.RegFile.set, h]
    have ht : ∀ j ∈ ks, j < 16 := by intro j hj; exact hk j (by simp [hj])
    simp only [program] at ih
    rw [ih ht]
    simp [folded, hr, BPF.RegFile.set_set_same]

theorem folded_bit (isAnd : Bool) (src v : BitVec 64) (ks : List Nat)
    (hk : ∀ k ∈ ks, k < 64) (i : Nat) (hi : i < 64) :
    (folded isAnd src v ks).getLsbD i = if i ∈ ks then
      (if isAnd then v.getLsbD i && src.getLsbD i else v.getLsbD i || src.getLsbD i)
      else v.getLsbD i := by
  induction ks generalizing v with
  | nil => simp [folded]
  | cons k ks ih =>
    have ht : ∀ j ∈ ks, j < 64 := by intro j hj; exact hk j (by simp [hj])
    simp only [folded, List.foldl_cons]
    rw [← folded, ih _ ht, gate_bit isAnd k (hk k (by simp)) v src i hi]
    by_cases he : i = k <;> by_cases hm : i ∈ ks <;> cases isAnd <;>
      simp [he, hm]

inductive Operand (bits : Nat) where
  | reg (r : BPF.Reg)
  | imm (v : BitVec bits)

def Operand.word {bits : Nat} (operand : Operand bits) (rf : BPF.RegFile) : BitVec 64 :=
  match operand with
  | .reg r => rf r | .imm v => BitVec.setWidth 64 v

def operation (isAnd : Bool) : X86.AluOp := if isAnd then .and else .or

def value (bits : Nat) (isAnd : Bool) (v src : BitVec 64) : BitVec 64 :=
  X86.writeWidth bits v ((operation isAnd).eval v src)

def bpf (bits : Nat) (isAnd : Bool) (d : BPF.Reg) (operand : Operand bits) :
    List BPF.MInsn :=
  match operand with
  | .reg r => program isAnd d r (List.range bits)
  | .imm v => [.core (.alu (if isAnd then .and else .or) .w64 d
      (.imm (if isAnd then BitVec.signExtend 64 (BitVec.setWidth 32 v ||| ~~~Bits.lowMask 32 bits)
        else BitVec.signExtend 64 (BitVec.setWidth 32 v))))]

/-- x86/bpf_x86_alu.c:emit_x86_alu_narrow: 8/16-bit RR or immediate logic;
    every decoded immediate is nonnegative and fits the selected width. -/
def native (m : X86RegMap) (bits : Nat) (isAnd : Bool) (d : BPF.Reg)
    (operand : Operand bits) : List X86.MInsn :=
  match operand with
  | .reg r => [.aluNarrow (operation isAnd) bits (m.map d) (m.map r)]
  | .imm v => [.aluImmNarrow (operation isAnd) bits (m.map d) (BitVec.setWidth 64 v)]

def spec (bits : Nat) (isAnd : Bool) (d : BPF.Reg) (operand : Operand bits)
    (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (value bits isAnd (s.regs d) (operand.word s.regs)) }

theorem folded_value (bits : Nat) (hb : bits = 8 ∨ bits = 16) (isAnd : Bool)
    (src v : BitVec 64) : folded isAnd src v (List.range bits) = value bits isAnd v src := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [folded_bit isAnd src v _ (by
    intro k hk; have h := List.mem_range.mp hk; rcases hb with hb | hb <;> omega) i hi]
  by_cases h : i < bits
  all_goals rcases hb with hb | hb <;> subst bits <;> cases isAnd
  all_goals simp [value, operation, X86.AluOp.eval, X86.writeWidth, hi, h]

theorem immediate_value (bits : Nat) (hb : bits = 8 ∨ bits = 16) (isAnd : Bool)
    (v : BitVec 64) (imm : BitVec bits) :
    (if isAnd then v &&& (BitVec.setWidth 64 imm ||| ~~~Bits.lowMask 64 bits)
      else v ||| BitVec.setWidth 64 imm) = value bits isAnd v (BitVec.setWidth 64 imm) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rcases hb with hb | hb <;> subst bits <;> cases isAnd
  all_goals interval_cases i <;>
    simp [value, operation, X86.AluOp.eval, X86.writeWidth]

theorem bpf_correct (bits : Nat) (hb : bits = 8 ∨ bits = 16) (isAnd : Bool)
    (d : BPF.Reg) (operand : Operand bits) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf bits isAnd d operand) s) =
      spec bits isAnd d operand (observeBpf s) := by
  cases operand with
  | reg r =>
    have he := program_exec isAnd d r (List.range bits) (by
      intro k hk; have h := List.mem_range.mp hk; rcases hb with hb | hb <;> omega) s []
    simp only [List.append_nil, BPF.mexec] at he
    rw [bpf, he, folded_value bits hb]
    rfl
  | imm v =>
    have hm := immediate_value bits hb isAnd (s.regs d) v
    cases isAnd <;>
      simp [bpf, spec, Operand.word, observeBpf, BPF.mexec, BPF.MInsn.step,
        BPF.Insn.step, BPF.AluOp.eval, signed_immediate bits hb, positive_immediate bits hb] at hm ⊢
    all_goals exact congrArg (BPF.RegFile.set s.regs d) hm

theorem native_correct (m : X86RegMap) (bits : Nat) (isAnd : Bool) (d : BPF.Reg)
    (operand : Operand bits) (s : X86.State) :
    observeX86 m (X86.mexec (native m bits isAnd d operand) s) =
      spec bits isAnd d operand (observeX86 m s) := by
  cases operand <;>
    simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  all_goals rw [x86_observe_set]
  all_goals rfl

theorem program_writes (isAnd : Bool) (d r t : BPF.Reg) (ks : List Nat) :
    t ∈ BPF.mwrites (program isAnd d r ks) → t = d := by
  intro ht
  simp only [program, BPF.mwrites, List.flatMap_assoc, List.mem_flatMap] at ht
  obtain ⟨k, _, ht⟩ := ht
  cases isAnd <;>
    simpa [gate, BPF.MInsn.writes, BPF.Insn.dstReg] using ht

def cert (m : X86RegMap) (bits : Nat) (hb : bits = 8 ∨ bits = 16) (isAnd : Bool)
    (d : BPF.Reg) (operand : Operand bits) : X86StateEquiv m where
  spec := spec bits isAnd d operand
  bpf := bpf bits isAnd d operand
  native := native m bits isAnd d operand
  writeSet := [d]
  bpfCorrect := bpf_correct bits hb isAnd d operand
  nativeCorrect := native_correct m bits isAnd d operand
  bpfWrites := by
    intro t ht
    cases operand with
    | reg r => exact List.mem_singleton.mpr (program_writes isAnd d r t _ ht)
    | imm v => simpa [bpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
  nativeWrites := by
    cases operand <;> simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_alu.c:instantiate_andb/emit_andb_x86. -/
def bpf_x86_andb (m : X86RegMap) (d : BPF.Reg) (operand : Operand 8) : X86StateEquiv m :=
  cert m 8 (by simp) true d operand
/-- x86/bpf_x86_alu.c:instantiate_orb/emit_orb_x86. -/
def bpf_x86_orb (m : X86RegMap) (d : BPF.Reg) (operand : Operand 8) : X86StateEquiv m :=
  cert m 8 (by simp) false d operand
/-- x86/bpf_x86_alu.c:instantiate_orw/emit_orw_x86. -/
def bpf_x86_orw (m : X86RegMap) (d : BPF.Reg) (operand : Operand 16) : X86StateEquiv m :=
  cert m 16 (by simp) false d operand

end Kinsn.ModuleNarrowLogic
