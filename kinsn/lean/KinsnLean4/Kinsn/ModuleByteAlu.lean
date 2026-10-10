import KinsnLean4.Kinsn.ModuleAluWide
import KinsnLean4.Kinsn.ModuleControlDispatch
import KinsnLean4.Kinsn.ModuleAluShift
import KinsnLean4.Kinsn.ModuleNarrowLogic
import KinsnLean4.Kinsn.ModuleRotateOne
import KinsnLean4.Kinsn.ModuleByteArithmetic

namespace Kinsn.ModuleByteAlu
open ModuleMovStore (Source)
open ModuleAluShift (Count)

theorem high_immediate : BitVec.signExtend 64 (-256 : BitVec 32) = ~~~(255#64) := by
  decide +kernel

theorem masked_byte (v : BitVec 8) :
    BitVec.setWidth 64 v &&& (255#64) = BitVec.setWidth 64 v := by
  change BitVec.setWidth 64 v &&& Bits.lowMask 64 8 = _
  rw [Bits.and_lowMask_eq_setWidth,
    BitVec.setWidth_setWidth_of_le _ (by decide : 8 ≤ 64)]
  rfl

def shiftedByte (left : Bool) (n v : Nat) : BitVec 8 :=
  if left then BitVec.ofNat 8 v <<< n else BitVec.ofNat 8 v >>> n

def inputLeaf (left : Bool) (d : BPF.Reg) (n v : Nat) : List BPF.MInsn :=
  [.core (.alu .and .w64 d (.imm (BitVec.signExtend 64 (-256 : BitVec 32)))),
   .core (.alu .or .w64 d (.imm (BitVec.signExtend 64 (BitVec.setWidth 32 (shiftedByte left n v)))))]

def inputEffect (left : Bool) (d : BPF.Reg) (n v : Nat) (s : BPF.State) : BPF.State :=
  { s with regs := (BPF.RegFile.set s.regs d
    ((s.regs d &&& ~~~255) ||| BitVec.setWidth 64 (shiftedByte left n v))) }

theorem input_exec (left : Bool) (d : BPF.Reg) (n v : Nat) (s : BPF.State)
    (tail : List BPF.MInsn) :
    BPF.mexec (inputLeaf left d n v ++ tail) s = BPF.mexec tail (inputEffect left d n v s) := by
  simp [inputLeaf, inputEffect, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
    BPF.AluOp.eval, BPF.Src.eval, high_immediate,
    ModuleNarrowLogic.positive_immediate 8 (by simp), BPF.RegFile.set_set_same]

/-- x86/bpf_x86_alu.c:instantiate_narrow_shift_leaf: dispatch on all original
    low-byte bits before replacing the low byte. No other state is borrowed. -/
def shiftLeaf (left : Bool) (d : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  if n = 0 then [.ja 0] else if 8 ≤ n then
    [.core (.alu .and .w64 d (.imm (BitVec.signExtend 64 (-256 : BitVec 32))))]
  else ModuleControlDispatch.tree d (inputLeaf left d n) 8 0

def shiftValue (left : Bool) (v : BitVec 64) (n : Nat) : BitVec 64 :=
  X86.writeWidth 8 v (BitVec.setWidth 64
    (if left then (BitVec.setWidth 8 v) <<< n else (BitVec.setWidth 8 v) >>> n))

def shiftEffect (left : Bool) (d : BPF.Reg) (n : Nat) (s : BPF.State) : BPF.State :=
  { s with regs := BPF.RegFile.set s.regs d (shiftValue left (s.regs d) n) }

theorem low_roundtrip (v : BitVec 64) :
    BitVec.ofNat 8 (v.toNat % 256) = BitVec.setWidth 8 v := by
  apply BitVec.eq_of_toNat_eq
  simp [BitVec.toNat_ofNat, BitVec.toNat_setWidth]

theorem shift_zero (left : Bool) (v : BitVec 64) : shiftValue left v 0 = v := by
  cases left <;> simp only [shiftValue, ↓reduceIte, Bool.false_eq_true,
    BitVec.shiftLeft_zero, BitVec.ushiftRight_zero, X86.writeWidth]
  all_goals apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi
  all_goals interval_cases i <;> simp [Bits.lowMask]

theorem shift_large (left : Bool) (v : BitVec 64) (n : Nat) (hn : 8 ≤ n) :
    shiftValue left v n = v &&& ~~~255 := by
  cases left <;> simp [shiftValue, X86.writeWidth, Bits.lowMask,
    BitVec.shiftLeft_eq_zero, BitVec.ushiftRight_eq_zero, hn]

theorem shift_leaf_exec (left : Bool) (d : BPF.Reg) (n : Nat)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (shiftLeaf left d n ++ tail) s = BPF.mexec tail (shiftEffect left d n s) := by
  by_cases hz : n = 0
  · subst n
    simp [shiftLeaf, BPF.mexec, shiftEffect, shift_zero, ModuleRotateOne.set_self]
  · by_cases hn : 8 ≤ n
    · simp [shiftLeaf, hz, hn, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
        BPF.AluOp.eval, shiftEffect, high_immediate, shift_large left _ n hn]
    · simp only [shiftLeaf, if_neg hz, if_neg hn]
      rw [ModuleControlDispatch.exec_tree d (inputLeaf left d n)
        (inputEffect left d n) (input_exec left d n) 8 0 s tail,
        ModuleDispatch.selected_eq _ _ _ (by decide : 8 ≤ 64)]
      simp [inputEffect, shiftEffect, shiftValue, shiftedByte, low_roundtrip,
        X86.writeWidth, Bits.lowMask, masked_byte]

def shiftBpf (left : Bool) (d : BPF.Reg) (count : Count) : List BPF.MInsn :=
  match count with
  | .cl => ModuleControlDispatch.tree .r4 (shiftLeaf left d) 5 0
  | .imm n => shiftLeaf left d n

def shiftNative (m : X86RegMap) (left : Bool) (d : BPF.Reg) (count : Count) :
    List X86.MInsn :=
  match count with
  | .cl => [.shiftCLWidth 8 (if left then .shl else .shr) (m.map d)]
  | .imm n => [.shiftImmWidth 8 (if left then .shl else .shr) (m.map d)
      (BitVec.ofNat 8 n).toNat]

def shiftSpec (left : Bool) (d : BPF.Reg) (count : Count) (s : Outcome) : Outcome :=
  { s with regs := BPF.RegFile.set s.regs d (shiftValue left (s.regs d) (count.number s.regs % 32)) }

theorem shift_bpf_correct (left : Bool) (d : BPF.Reg) (count : Count)
    (hv : count.Valid false) (s : BPF.State) :
    observeBpf (BPF.mexec (shiftBpf left d count) s) =
      shiftSpec left d count (observeBpf s) := by
  cases count with
  | cl =>
    have h := ModuleControlDispatch.exec_tree .r4 (shiftLeaf left d)
      (shiftEffect left d) (shift_leaf_exec left d) 5 0 s []
    simp only [List.append_nil, BPF.mexec] at h
    rw [shiftBpf, h, ModuleDispatch.selected_eq _ _ _ (by decide : 5 ≤ 64)]
    simp [shiftEffect, shiftSpec, Count.number, observeBpf]
  | imm n =>
    have hn : n < 32 := hv
    have h := shift_leaf_exec left d n s []
    simp only [List.append_nil, BPF.mexec] at h
    rw [shiftBpf, h]
    simp [shiftEffect, shiftSpec, Count.number, observeBpf, Nat.mod_eq_of_lt hn]

theorem shift_native_correct (m : X86RegMap) (hc : m.map .r4 = .rcx)
    (left : Bool) (d : BPF.Reg) (count : Count) (hv : count.Valid false) (s : X86.State) :
    observeX86 m (X86.mexec (shiftNative m left d count) s) =
      shiftSpec left d count (observeX86 m s) := by
  have he (n : Nat) (hn : count = .imm n) : (BitVec.ofNat 8 n).toNat = n := by
    subst count
    exact ModuleAluShift.encoded_count false n hv
  cases count <;> cases left <;>
    simp only [shiftNative, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  all_goals rw [x86_observe_set]
  all_goals simp [shiftSpec, shiftValue, Count.number, hc, he, observeX86]

theorem input_writes (left : Bool) (d r : BPF.Reg) (n v : Nat)
    (h : r ∈ BPF.mwrites (inputLeaf left d n v)) : r = d := by
  simpa [inputLeaf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using h

theorem shift_leaf_writes (left : Bool) (d r : BPF.Reg) (n : Nat)
    (h : r ∈ BPF.mwrites (shiftLeaf left d n)) : r = d := by
  by_cases hz : n = 0
  · simp [shiftLeaf, hz, BPF.mwrites, BPF.MInsn.writes] at h
  · by_cases hn : 8 ≤ n
    · simpa [shiftLeaf, hz, hn, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using h
    · exact ModuleControlDispatch.writes_tree d (inputLeaf left d n) 8 0 d
        (fun v r h => input_writes left d r n v h) r (by simpa [shiftLeaf, hz, hn] using h)

def shiftCert (m : X86RegMap) (hc : m.map .r4 = .rcx) (left : Bool)
    (d : BPF.Reg) (count : Count) (hv : count.Valid false) : X86StateEquiv m where
  spec := shiftSpec left d count
  bpf := shiftBpf left d count
  native := shiftNative m left d count
  writeSet := [d]
  bpfCorrect := shift_bpf_correct left d count hv
  nativeCorrect := shift_native_correct m hc left d count hv
  bpfWrites := by
    intro r h
    cases count with
    | cl => exact List.mem_singleton.mpr (ModuleControlDispatch.writes_tree .r4
        (shiftLeaf left d) 5 0 d (fun n r h => shift_leaf_writes left d r n h) r h)
    | imm n => exact List.mem_singleton.mpr (shift_leaf_writes left d r n h)
  nativeWrites := by
    cases count <;> simp [shiftNative, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- Destination-only byte arithmetic, including src=dst and ARCH tags. -/
def bpf_x86_addb (m : X86RegMap) (d : BPF.Reg) (src : Source)
    (hv : ModuleByteArithmetic.sourceValid src) : X86StateEquiv m :=
  ModuleByteArithmetic.certificate m .add (by simp) d src hv

def bpf_x86_subb (m : X86RegMap) (d : BPF.Reg) (src : Source)
    (hv : ModuleByteArithmetic.sourceValid src) : X86StateEquiv m :=
  ModuleByteArithmetic.certificate m .sub (by simp) d src hv

/-- x86/bpf_x86_alu.c:instantiate_shlb/emit_shlb_x86: immediate and CL tags. -/
def bpf_x86_shlb (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (hv : c.Valid false) : X86StateEquiv m := shiftCert m hc true d c hv
/-- x86/bpf_x86_alu.c:instantiate_shrb/emit_shrb_x86: immediate and CL tags. -/
def bpf_x86_shrb (m : X86RegMap) (hc : m.map .r4 = .rcx) (d : BPF.Reg) (c : Count)
    (hv : c.Valid false) : X86StateEquiv m := shiftCert m hc false d c hv

end Kinsn.ModuleByteAlu
