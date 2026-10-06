import KinsnLean4.Kinsn.ModuleShiftedDispatch
import KinsnLean4.Kinsn.ModuleBzhi

namespace Kinsn.ModuleBextr

def value (start length : Nat) (v : BitVec 64) : BitVec 64 :=
  (v >>> start) &&& Bits.lowMask 64 length

/-- x86/bpf_x86_bmi1.c:instantiate_bextr_leaf, length 0..63. -/
def leaf (d r : BPF.Reg) (start length : Nat) : List BPF.Insn :=
  if length = 0 then [.alu .mov .w64 d (.imm 0)] else
    [.alu .mov .w64 d (.reg r), .alu .rsh .w64 d (BPF.immN start),
      .alu .lsh .w64 d (BPF.immN (64 - length)),
      .alu .rsh .w64 d (BPF.immN (64 - length))]

def wide (d r : BPF.Reg) (start : Nat) : List BPF.Insn :=
  [.alu .mov .w64 d (.reg r), .alu .rsh .w64 d (BPF.immN start)]

theorem leaf_exec (d r : BPF.Reg) (start length : Nat) (hs : start < 64)
    (hl : length < 64) (rf : BPF.RegFile) :
    BPF.exec (leaf d r start length) rf = rf.set d (value start length (rf r)) := by
  by_cases hz : length = 0
  · simp [leaf, hz, value, BPF.exec, BPF.Insn.step, BPF.AluOp.eval, Bits.lowMask_zero]
  · have hm : (64 - length) % 64 = 64 - length := Nat.mod_eq_of_lt (by omega)
    have he : (BitVec.ofNat 64 (64 - length)).toNat = 64 - length := by
      simp only [BitVec.toNat_ofNat]; apply Nat.mod_eq_of_lt; omega
    have hc := ModuleBzhi.keep_low 64 (rf r >>> start) length hl
    simpa [leaf, hz, value, BPF.exec, BPF.Insn.step, BPF.AluOp.eval,
      BPF.immN, Nat.mod_eq_of_lt hs, he, hm, BPF.RegFile.set_set_same] using
      congrArg (BPF.RegFile.set rf d) hc

theorem wide_exec (d r : BPF.Reg) (start : Nat) (hs : start < 64) (rf : BPF.RegFile) :
    BPF.exec (wide d r start) rf = rf.set d (rf r >>> start) := by
  simp [wide, BPF.exec, BPF.Insn.step, BPF.AluOp.eval, BPF.immN,
    Nat.mod_eq_of_lt hs, BPF.RegFile.set_set_same]

def joinProgram (c : BPF.Reg) (mask : BitVec 64) (low high : List BPF.MInsn) :
    List BPF.MInsn :=
  [.branch .bitSet .w64 c (.imm mask) (low.length + 1)] ++
    low ++ [.ja high.length] ++ high

/-- x86/bpf_x86_bmi1.c:instantiate_bextr_length. JSET ctrl[15:14]
    handles 64..255; the lower six length bits select a masked leaf. -/
def lengthProgram (d r c : BPF.Reg) (start : Nat) : List BPF.MInsn :=
  let low := ModuleShiftedDispatch.tree c 8 (fun n => (leaf d r start n).map BPF.MInsn.core) 6 0
  let high := (wide d r start).map BPF.MInsn.core
  joinProgram c 49152#64 low high

def effect (d r c : BPF.Reg) (start : Nat) (s : BPF.State) : BPF.State :=
  { s with regs := (BPF.RegFile.set s.regs d
      (value start (ModuleBzhi.count (s.regs c >>> 8)) (s.regs r))) }

theorem high_gate (v : BitVec 64) :
    BPF.Cond.test .bitSet .w64 v 49152#64 = ModuleBzhi.highTest true (v >>> 8) := by
  have hu : (v &&& 49152#64) >>> 8 = (v >>> 8) &&& 192#64 := by
    rw [BitVec.ushiftRight_and_distrib]
    rfl
  have hd : ((v >>> 8) &&& 192#64) <<< 8 = v &&& 49152#64 := by
    apply BitVec.eq_of_getLsbD_eq
    intro i hi
    interval_cases i <;> simp
  have hz : v &&& 49152#64 = 0#64 ↔ (v >>> 8) &&& 192#64 = 0#64 := by
    constructor
    · intro h; rw [← hu, h]; simp
    · intro h; rw [← hd, h]; simp
  simp [ModuleBzhi.highTest, ModuleBzhi.highMask, BPF.Cond.test, BPF.Cond.eval, hz]

theorem length_exec (d r c : BPF.Reg) (start : Nat) (hs : start < 64)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (lengthProgram d r c start ++ tail) s =
      BPF.mexec tail (effect d r c start s) := by
  simp only [lengthProgram, joinProgram, List.append_assoc, List.cons_append, List.nil_append]
  rw [BPF.mexec]
  simp only [BPF.Src.eval, high_gate, ModuleBzhi.highTest_eq]
  by_cases hg : 64 ≤ ModuleBzhi.count (s.regs c >>> 8)
  · simp only [ModuleBmiShift.bits, ↓reduceIte, decide_eq_true hg,
      List.drop_append, List.drop_eq_nil_of_le (by omega :
        (ModuleShiftedDispatch.tree c 8
          (fun n => (leaf d r start n).map BPF.MInsn.core) 6 0).length ≤
        (ModuleShiftedDispatch.tree c 8
          (fun n => (leaf d r start n).map BPF.MInsn.core) 6 0).length + 1),
      Nat.add_sub_cancel_left, List.drop_succ_cons, List.drop_zero, List.nil_append]
    rw [ModuleDispatch.exec_core_tail, wide_exec d r start hs]
    have ha (v : BitVec 64) : v &&& 18446744073709551615#64 = v := by
      change v &&& BitVec.allOnes 64 = v
      exact BitVec.and_allOnes
    simp [effect, value, Bits.lowMask_of_le 64 _ hg, ha]
  · have hl : ModuleBzhi.count (s.regs c >>> 8) < 64 := by omega
    simp only [ModuleBmiShift.bits, ↓reduceIte, decide_eq_false hg]
    rw [ModuleShiftedDispatch.exec_tree c 8
      (fun n => (leaf d r start n).map BPF.MInsn.core)
      (fun n s => { s with regs := BPF.exec (leaf d r start n) s.regs })
      (fun n s tail => ModuleDispatch.exec_core_tail (leaf d r start n) tail s)
      6 0 (by decide), ModuleDispatch.selected_eq _ _ _ (by decide)]
    have hc := ModuleBzhi.count_low true (s.regs c >>> 8) hl
    simp only [ModuleBmiShift.bits, ↓reduceIte] at hc
    rw [show 2^6=64 by decide, Nat.zero_add, hc, leaf_exec d r start _ hs hl]
    simp [BPF.mexec, effect]


/-- x86/bpf_x86_bmi1.c:instantiate_bextr_start_tree. All eight start bits
    are read before lengthProgram starts and before any register writes. -/
def startLeaf (d r c : BPF.Reg) (start : Nat) : List BPF.MInsn :=
  if start < 64 then lengthProgram d r c start else [.core (.alu .mov .w64 d (.imm 0))]

def bpf (d r c : BPF.Reg) : List BPF.MInsn :=
  ModuleControlDispatch.tree c (startLeaf d r c) 8 0

def spec (d r c : BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (X86.bextr (s.regs r) (s.regs c)) }

def startEffect (d r c : BPF.Reg) (start : Nat) (s : BPF.State) : BPF.State :=
  { s with regs := (BPF.RegFile.set s.regs d
      (value start (ModuleBzhi.count (s.regs c >>> 8)) (s.regs r))) }

theorem start_exec (d r c : BPF.Reg) (start : Nat) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (startLeaf d r c start ++ tail) s =
      BPF.mexec tail (startEffect d r c start s) := by
  by_cases hs : start < 64
  · simp only [startLeaf, if_pos hs]
    exact length_exec d r c start hs s tail
  · have he : (s.regs r) >>> start = 0#64 :=
      BitVec.ushiftRight_eq_zero (by omega)
    simp [startLeaf, hs, startEffect, value, he,
      BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval]

theorem bpf_correct (d r c : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf d r c) s) = spec d r c (observeBpf s) := by
  have he := ModuleControlDispatch.exec_tree c (startLeaf d r c)
    (startEffect d r c) (start_exec d r c) 8 0 s []
  simp only [List.append_nil] at he
  rw [bpf, he, ModuleDispatch.selected_eq _ _ _ (by decide)]
  simp [BPF.mexec, startEffect, value, spec, X86.bextr, ModuleBzhi.count, observeBpf,
    BitVec.toNat_setWidth]

/-- x86/bpf_x86_bmi1.c:emit_bextrq_x86, unchanged BMI1 BEXTR. -/
def native (m : X86RegMap) (d r c : BPF.Reg) : List X86.MInsn :=
  [.core (.bextr (m.map d) (m.map r) (m.map c))]

theorem native_correct (m : X86RegMap) (d r c : BPF.Reg) (s : X86.State) :
    observeX86 m (X86.mexec (native m d r c) s) = spec d r c (observeX86 m s) := by
  simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, X86.step_bextr]
  simp only [observeX86, spec]
  congr 1
  funext t
  simp [X86.RegFile.set, BPF.RegFile.set, m.inj.eq_iff]

theorem leaf_writes (d r t : BPF.Reg) (start length : Nat) :
    t ∈ BPF.writes (leaf d r start length) → t = d := by
  by_cases hz : length = 0 <;> simp [leaf, hz, BPF.writes, BPF.Insn.dstReg]

theorem join_writes (c d t : BPF.Reg) (mask : BitVec 64) (low high : List BPF.MInsn)
    (hl : t ∈ BPF.mwrites low → t = d) (hh : t ∈ BPF.mwrites high → t = d) :
    t ∈ BPF.mwrites (joinProgram c mask low high) → t = d := by
  intro ht
  simp only [joinProgram, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
    List.flatMap_nil, BPF.MInsn.writes, List.nil_append,
    List.mem_append, List.mem_nil_iff, or_false] at ht
  exact ht.elim hl hh

theorem length_writes (d r c t : BPF.Reg) (start : Nat) :
    t ∈ BPF.mwrites (lengthProgram d r c start) → t = d :=
  join_writes c d t 49152#64 _ _
    (ModuleShiftedDispatch.writes_tree c 8
      (fun n => (leaf d r start n).map BPF.MInsn.core) 6 0 d
      (fun n t h => leaf_writes d r t start n
        (by simpa [BPF.mwrites, BPF.writes, List.mem_flatMap,
          BPF.MInsn.writes, eq_comm] using h)) t)
    (by simp [wide, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg])

theorem conditional_writes (d t : BPF.Reg) (p : List BPF.MInsn)
    (hflag : Prop) [Decidable hflag] (hp : t ∈ BPF.mwrites p → t = d) :
    t ∈ BPF.mwrites (if hflag then p else [.core (.alu .mov .w64 d (.imm 0))]) →
      t = d := by
  intro ht
  by_cases hs : hflag
  · simp only [if_pos hs] at ht
    exact hp ht
  · simp only [if_neg hs] at ht
    simpa [BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht

theorem start_writes (d r c t : BPF.Reg) (start : Nat) :
    t ∈ BPF.mwrites (startLeaf d r c start) → t = d :=
  conditional_writes d t (lengthProgram d r c start) (start < 64)
    (length_writes d r c t start)

def bpf_x86_bextrq (m : X86RegMap) (d r c : BPF.Reg) : X86StateEquiv m where
  spec := spec d r c
  bpf := bpf d r c
  native := native m d r c
  writeSet := [d]
  bpfCorrect := bpf_correct d r c
  nativeCorrect := native_correct m d r c
  bpfWrites := by
    intro t ht
    exact List.mem_singleton.mpr (ModuleControlDispatch.writes_tree c (startLeaf d r c)
      8 0 d (fun n t h => start_writes d r c t n h) t ht)
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, X86.Insn.dstReg, m.inj.eq_iff]

end Kinsn.ModuleBextr
