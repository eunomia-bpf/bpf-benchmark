import KinsnLean4.Kinsn.ModuleX86Rotate
import KinsnLean4.Kinsn.ModuleByteAlu
namespace Kinsn.ModuleShd
open ModuleBmiShift (bits width)
 def pick (left : Bool) (a b : BitVec w) (n : Nat) : BitVec w :=
  (if left then ((a ^^^ b) <<< n) >>> n else ((a ^^^ b) >>> n) <<< n) ^^^ b
 theorem pick_rotate_left (a b : BitVec w) (n : Nat) (hb : n<w) :
    (pick true a b n).rotateLeft n = (a <<< n) ||| (b >>> (w-n)) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [pick, ↓reduceIte, BitVec.rotateLeft_def, Nat.mod_eq_of_lt hb,
    BitVec.getLsbD_or, BitVec.getLsbD_shiftLeft, BitVec.getLsbD_ushiftRight,
    BitVec.getLsbD_xor]
  have hlarge : ¬ n + (w - n + i) < w := by omega
  by_cases h : i < n
  · simp [hi, h, hlarge]
  · have hs : n + (i-n) = i := by omega
    have hz : b.getLsbD (w-n+i) = false := BitVec.getLsbD_of_ge b _ (by omega)
    simp [hi, h, hlarge, hs, hz]

 theorem pick_dual (a b : BitVec w) (n : Nat) (hb : n<w) :
    pick false a b n = pick true b a (w-n) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [pick, ↓reduceIte, BitVec.getLsbD_xor,
    BitVec.getLsbD_shiftLeft, BitVec.getLsbD_ushiftRight]
  have hs : w-n+i-(w-n) = i := by omega
  have hl : w-n+i<w ↔ i<n := by omega
  by_cases h : i<n
  · simp [hi, h, hs, hl, show ¬w-n+i<w-n by omega]
  · have ht : n+(i-n) = i := by omega
    simp [hi, h, hs, ht, hl, show ¬w-n+i<w-n by omega]
 theorem pick_rotate_right (a b : BitVec w) (n : Nat) (hn : 0<n) (hb : n<w) :
    (pick false a b n).rotateLeft (w-n) = (a >>> n) ||| (b <<< (w-n)) := by
  rw [pick_dual a b n hb, pick_rotate_left b a (w-n) (by omega)]
  simp [show w-(w-n)=n by omega, BitVec.or_comm]

/-- Lane selection followed by rotation is exactly the hardware double shift. -/
theorem pick_rotate (is64 left : Bool) (a b : BitVec (bits is64)) (n : Nat)
    (hn : 0 < n) (hb : n < bits is64) :
    (pick left a b n).rotateLeft (if left then n else bits is64 - n) =
      (if left then (a <<< n) ||| (b >>> (bits is64-n))
       else (a >>> n) ||| (b <<< (bits is64-n))) := by
  cases left
  · exact pick_rotate_right a b n hn hb
  · exact pick_rotate_left a b n hb

def selectLanes (is64 left : Bool) (d r : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  [.core (.alu .xor (width is64) d (.reg r)),
   .core (.alu (if left then .lsh else .rsh) (width is64) d (BPF.immN n)),
   .core (.alu (if left then .rsh else .lsh) (width is64) d (BPF.immN n)),
   .core (.alu .xor (width is64) d (.reg r))]

def picked (is64 left : Bool) (a b : BitVec 64) (n : Nat) : BitVec 64 :=
  BitVec.setWidth 64 (pick left (BitVec.setWidth (bits is64) a)
    (BitVec.setWidth (bits is64) b) n)

/-- A four-instruction XOR/mask/XOR selectLanes selects destination and source
    lanes. Self-source skips it. Conditional rotation writes only d. -/
def bpf (is64 left : Bool) (d r : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  (if d = r then [] else selectLanes is64 left d r n) ++
    ModuleX86Rotate.leaf is64 d d (if left then n else bits is64 - n)

def native (m : X86RegMap) (is64 left : Bool) (d r : BPF.Reg) (n : Nat) :
    List X86.MInsn :=
  [.shd (bits is64) left (m.map d) (m.map r) (BitVec.ofNat 8 n).toNat]

def value (is64 left : Bool) (a b : BitVec 64) (n : Nat) : BitVec 64 :=
  let a := BitVec.setWidth (bits is64) a
  let b := BitVec.setWidth (bits is64) b
  BitVec.setWidth 64 (if left then (a <<< n) ||| (b >>> (bits is64 - n))
    else (a >>> n) ||| (b <<< (bits is64 - n)))

def spec (is64 left : Bool) (d r : BPF.Reg) (n : Nat) (s : Outcome) : Outcome :=
  { s with regs := BPF.RegFile.set s.regs d (value is64 left (s.regs d) (s.regs r) n) }

theorem selectLanes_exec (is64 left : Bool) (d r : BPF.Reg) (n : Nat)
    (hb : n < bits is64) (hr : r ≠ d) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (selectLanes is64 left d r n ++ tail) s = BPF.mexec tail
      { s with regs := BPF.RegFile.set s.regs d (picked is64 left (s.regs d) (s.regs r) n) } := by
  cases is64 <;> cases left
  all_goals simp only [bits, Bool.false_eq_true, ↓reduceIte] at hb
  all_goals
    simp [selectLanes, picked, pick, width, bits, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
      BPF.AluOp.eval, BPF.Src.eval, BPF.immN, BPF.RegFile.set_other _ _ _ _ hr,
      BPF.RegFile.set_set_same, Nat.mod_eq_of_lt hb, ModuleAluShift.narrow_right]
  simp only [← BitVec.setWidth_xor, ← BitVec.setWidth_ushiftRight (by decide : 32 ≤ 64),
    BitVec.setWidth_setWidth_of_le _ (by decide : 32 ≤ 64), BitVec.setWidth_eq]

theorem leaf_correct (is64 left : Bool) (d r : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits is64) (s : BPF.State) :
    observeBpf (BPF.mexec (ModuleX86Rotate.leaf is64 d d
      (if left then n else bits is64 - n))
      { s with regs := BPF.RegFile.set s.regs d (picked is64 left (s.regs d) (s.regs r) n) }) =
      spec is64 left d r n (observeBpf s) := by
  have hc : (if left then n else bits is64 - n) < bits is64 := by
    cases left <;> simp_all <;> omega
  have h := ModuleX86Rotate.leaf_exec is64 d d (if left then n else bits is64 - n)
    { s with regs := BPF.RegFile.set s.regs d (picked is64 left (s.regs d) (s.regs r) n) } []
  simp only [List.append_nil, BPF.mexec] at h
  rw [h]
  simp only [ModuleX86Rotate.effect, BPF.RegFile.set_same]
  rw [ModuleRotateOne.iterate_rotate _ _ _ hc]
  have hr := pick_rotate is64 left (BitVec.setWidth (bits is64) (s.regs d))
    (BitVec.setWidth (bits is64) (s.regs r)) n hn hb
  have hround : BitVec.setWidth (bits is64)
      (picked is64 left (s.regs d) (s.regs r) n) =
      pick left (BitVec.setWidth (bits is64) (s.regs d))
        (BitVec.setWidth (bits is64) (s.regs r)) n :=
    ModuleRotateOne.roundtrip is64 _
  rw [show ModuleRotateOne.bits is64 = bits is64 from rfl, hround, hr]
  simp [spec, value, observeBpf, BPF.RegFile.set_set_same]

theorem bpf_correct (is64 left : Bool) (d r : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits is64) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf is64 left d r n) s) =
      spec is64 left d r n (observeBpf s) := by
  by_cases he : d = r
  · subst r
    have hc : (if left then n else bits is64 - n) < bits is64 := by
      cases left <;> simp_all <;> omega
    have he := ModuleX86Rotate.leaf_exec is64 d d (if left then n else bits is64 - n) s []
    simp only [List.append_nil, BPF.mexec] at he
    rw [bpf, if_pos rfl, List.nil_append, he]
    simp only [ModuleX86Rotate.effect]
    rw [ModuleRotateOne.iterate_rotate _ _ _ hc]
    have hp := pick_rotate is64 left (BitVec.setWidth (bits is64) (s.regs d))
      (BitVec.setWidth (bits is64) (s.regs d)) n hn hb
    simp only [pick, BitVec.xor_self, BitVec.zero_shiftLeft, BitVec.zero_ushiftRight,
      ite_self, BitVec.zero_xor] at hp
    rw [show ModuleRotateOne.bits is64 = bits is64 from rfl, hp]
    rfl
  · simp only [bpf, if_neg he]
    rw [selectLanes_exec is64 left d r n hb (Ne.symm he)]
    exact leaf_correct is64 left d r n hn hb s

theorem native_correct (m : X86RegMap) (is64 left : Bool) (d r : BPF.Reg)
    (n : Nat) (hn : 0 < n) (hb : n < bits is64) (s : X86.State) :
    observeX86 m (X86.mexec (native m is64 left d r n) s) =
      spec is64 left d r n (observeX86 m s) := by
  simp only [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step,
    ModuleAluShift.encoded_count is64 n hb, Nat.mod_eq_of_lt hb, Nat.ne_of_gt hn,
    ↓reduceIte]
  rw [x86_observe_set]
  cases is64 <;> cases left <;> simp [spec, value, bits, X86.writeWidth, observeX86]

def cert (m : X86RegMap) (is64 left : Bool) (d r : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits is64) : X86StateEquiv m where
  spec := spec is64 left d r n
  bpf := bpf is64 left d r n
  native := native m is64 left d r n
  writeSet := [d]
  bpfCorrect := bpf_correct is64 left d r n hn hb
  nativeCorrect := native_correct m is64 left d r n hn hb
  bpfWrites := by
    intro t ht
    simp only [bpf, BPF.mwrites, List.flatMap_append, List.mem_append] at ht
    rcases ht with ht | ht
    · by_cases he : d = r
      · simp [he, BPF.mwrites] at ht
      · simpa [he, selectLanes, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using ht
    · exact List.mem_singleton.mpr (ModuleX86Rotate.leaf_writes is64 d d t _ ht)
  nativeWrites := by simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

def bpf_x86_shldl (m : X86RegMap) (d r : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits false) : X86StateEquiv m := cert m false true d r n hn hb
def bpf_x86_shldq (m : X86RegMap) (d r : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits true) : X86StateEquiv m := cert m true true d r n hn hb
def bpf_x86_shrdl (m : X86RegMap) (d r : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits false) : X86StateEquiv m := cert m false false d r n hn hb
def bpf_x86_shrdq (m : X86RegMap) (d r : BPF.Reg) (n : Nat)
    (hn : 0 < n) (hb : n < bits true) : X86StateEquiv m := cert m true false d r n hn hb

end Kinsn.ModuleShd
