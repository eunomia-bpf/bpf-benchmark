import KinsnLean4.Kinsn.ModuleAluWide
import KinsnLean4.Kinsn.ModuleControlDispatch
import KinsnLean4.Kinsn.ModuleAluShift

namespace Kinsn.ModuleByteAlu
open ModuleMovStore (Source)
open ModuleAluShift (Count)

def slot : BitVec 64 := -8

theorem high_immediate : BitVec.signExtend 64 (-256 : BitVec 32) = ~~~(255#64) := by
  decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_x86_alu_narrow: save one chosen temporary
    and preserve the destination's upper lane in it. -/
def prologue (d t : BPF.Reg) : List BPF.MInsn :=
  [.store 8 .r10 (.reg t) slot, .core (.alu .mov .w64 t (.reg d)),
    .core (.alu .and .w64 t (.imm (BitVec.signExtend 64 (-256 : BitVec 32))))]

def prepared (d t : BPF.Reg) (s : BPF.State) : BPF.State :=
  (s.write (s.regs .r10 + slot) 8 (s.regs t)).set t (s.regs d &&& ~~~255)

theorem prologue_exec (d t : BPF.Reg) (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (prologue d t ++ tail) s = BPF.mexec tail (prepared d t s) := by
  simp [prologue, prepared, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
    BPF.AluOp.eval, BPF.Src.eval, high_immediate, Machine.State.set,
    Machine.State.write]
  rw [BPF.RegFile.set_set_same]
  rfl

def suffix (t : BPF.Reg) : List BPF.MInsn := [.load 8 t .r10 slot]

/-- The actual restore value is observed, without assuming spill memory private. -/
def finish (d t : BPF.Reg) (v : BitVec 64) (s : Outcome) : Outcome :=
  let saved := ModuleMemory.storeSpec 8 t .r10 slot s
  let a := saved.regs .r10 + slot
  let restored := Machine.loadLE saved.mem a 8
  { regs := (saved.regs.set d v).set t restored
    mem := saved.mem
    trace := saved.trace ++ [.read a 8 restored] }

/-- x86/bpf_x86_alu.c:instantiate_x86_alu_narrow's ADD/SUB body. The low
    mask is applied after the full operation, so src=dst remains correct. -/
def arithmeticBody (kind : ModuleWideAlu.Kind) (d t : BPF.Reg) (src : Source) :
    List BPF.MInsn :=
  [.core (.alu kind.bpf .w64 d src.bpf), .core (.alu .and .w64 d (.imm 255)),
    .core (.alu .or .w64 d (.reg t))]

def arithmeticBpf (kind : ModuleWideAlu.Kind) (d t : BPF.Reg) (src : Source) :
    List BPF.MInsn := prologue d t ++ arithmeticBody kind d t src ++ suffix t

def arithmeticNative (m : X86RegMap) (kind : ModuleWideAlu.Kind) (d t : BPF.Reg)
    (src : Source) : List X86.MInsn :=
  [.store 8 (m.map t) (m.map .r10) slot] ++
    (match src with
    | .reg r => [.aluNarrow kind.native 8 (m.map d) (m.map r)]
    | .imm v => [.aluImmNarrow kind.native 8 (m.map d) (BitVec.signExtend 64 v)]) ++
    [.load 8 (m.map t) (m.map .r10) slot]

def arithmeticSpec (kind : ModuleWideAlu.Kind) (d t : BPF.Reg) (src : Source)
    (s : Outcome) : Outcome :=
  finish d t (X86.writeWidth 8 (s.regs d) (kind.native.eval (s.regs d) (src.word s.regs))) s

def sourceTempValid (src : Source) (t : BPF.Reg) : Prop :=
  match src with | .reg r => t ≠ r | .imm _ => True

theorem arithmetic_bpf_correct (kind : ModuleWideAlu.Kind) (d t : BPF.Reg)
    (src : Source) (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10)
    (hr : sourceTempValid src t) (s : BPF.State) :
    observeBpf (BPF.mexec (arithmeticBpf kind d t src) s) =
      arithmeticSpec kind d t src (observeBpf s) := by
  simp only [arithmeticBpf, List.append_assoc, prologue_exec]
  cases src <;> cases kind <;>
    simp [arithmeticBody, suffix, prepared, arithmeticSpec, finish,
      ModuleMemory.storeSpec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
      BPF.AluOp.eval, BPF.Src.eval, Source.bpf, Source.word, sourceTempValid,
      ModuleWideAlu.Kind.bpf, ModuleWideAlu.Kind.native, X86.AluOp.eval, observeBpf, Machine.State.read, Machine.State.write,
      Machine.State.set, BPF.RegFile.set, ht, Ne.symm ht, hf, Ne.symm hf,
      hd, Ne.symm hd, X86.writeWidth, Bits.lowMask, BitVec.or_comm] at hr ⊢
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set, BitVec.or_comm, Ne.symm]

theorem arithmetic_native_correct (m : X86RegMap) (kind : ModuleWideAlu.Kind)
    (d t : BPF.Reg) (src : Source) (hd : d ≠ .r10) (s : X86.State) :
    observeX86 m (X86.mexec (arithmeticNative m kind d t src) s) =
      arithmeticSpec kind d t src (observeX86 m s) := by
  cases src <;>
    simp [arithmeticNative, arithmeticSpec, finish, ModuleMemory.storeSpec,
      X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, Source.word, observeX86,
      Machine.State.read, Machine.State.write, Machine.State.set,
      m.inj.eq_iff, Ne.symm hd]
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set]

def shiftLow (left : Bool) (v : BitVec 64) (n : Nat) : BitVec 64 :=
  (if left then (v &&& (255#64)) <<< (n % 64) else (v &&& (255#64)) >>> (n % 64)) &&& (255#64)

/-- x86/bpf_x86_alu.c:instantiate_narrow_shift_leaf. -/
def shiftLeaf (left : Bool) (d t : BPF.Reg) (n : Nat) : List BPF.MInsn :=
  [.core (.alu .and .w64 d (.imm 255)),
    .core (.alu (if left then .lsh else .rsh) .w64 d (BPF.immN n)),
    .core (.alu .and .w64 d (.imm 255)), .core (.alu .or .w64 d (.reg t))]

def shiftEffect (left : Bool) (d t : BPF.Reg) (n : Nat) (s : BPF.State) : BPF.State :=
  { s with regs := BPF.RegFile.set s.regs d (shiftLow left (s.regs d) n ||| s.regs t) }

theorem shift_leaf_exec (left : Bool) (d t : BPF.Reg) (ht : t ≠ d) (n : Nat)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (shiftLeaf left d t n ++ tail) s = BPF.mexec tail (shiftEffect left d t n s) := by
  cases left <;>
    simp [shiftLeaf, shiftEffect, shiftLow, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
      BPF.AluOp.eval, BPF.Src.eval, BPF.immN, Nat.mod_mod_of_dvd,
      BPF.RegFile.set_set_same, BPF.RegFile.set_other _ _ _ _ ht]

/-- The masked 64-bit computation equals the zero-extended byte shift,
    including zero counts and all counts ≥8. -/
theorem shift_low_value (left : Bool) (v : BitVec 64) (n : Nat) (hn : n < 32) :
    shiftLow left v n = BitVec.setWidth 64
      (if left then (BitVec.setWidth 8 v) <<< n else (BitVec.setWidth 8 v) >>> n) := by
  have hn64 : n % 64 = n := Nat.mod_eq_of_lt (by omega)
  have hm : (255#64) = Bits.lowMask 64 8 := by decide +kernel
  cases left
  · simp only [shiftLow, Bool.false_eq_true, ↓reduceIte, hn64, hm,
      Bits.and_lowMask_eq_setWidth]
    rw [← BitVec.setWidth_ushiftRight (x := BitVec.setWidth 8 v) (y := n)
      (by decide : 8 ≤ 64)]
    rw [BitVec.setWidth_setWidth_of_le _ (by decide : 8 ≤ 64)]
    rfl
  · simp only [shiftLow, ↓reduceIte, hn64, hm, Bits.and_lowMask_eq_setWidth]
    rw [BitVec.setWidth_shiftLeft_of_le (by decide : 8 ≤ 64)]
    simp

theorem masked_byte (v : BitVec 8) :
    BitVec.setWidth 64 v &&& (255#64) = BitVec.setWidth 64 v := by
  change BitVec.setWidth 64 v &&& Bits.lowMask 64 8 = _
  rw [Bits.and_lowMask_eq_setWidth,
    BitVec.setWidth_setWidth_of_le _ (by decide : 8 ≤ 64)]
  rfl

def shiftBpf (left : Bool) (d t : BPF.Reg) (count : Count) : List BPF.MInsn :=
  prologue d t ++
    (match count with
    | .cl => ModuleControlDispatch.tree .r4 (shiftLeaf left d t) 5 0
    | .imm n => shiftLeaf left d t n) ++ suffix t

def shiftNative (m : X86RegMap) (left : Bool) (d t : BPF.Reg) (count : Count) :
    List X86.MInsn :=
  [.store 8 (m.map t) (m.map .r10) slot] ++
    (match count with
    | .cl => [.shiftCLWidth 8 (if left then .shl else .shr) (m.map d)]
    | .imm n => [.shiftImmWidth 8 (if left then .shl else .shr) (m.map d)
        (BitVec.ofNat 8 n).toNat]) ++ [.load 8 (m.map t) (m.map .r10) slot]

def shiftValue (left : Bool) (v : BitVec 64) (n : Nat) : BitVec 64 :=
  X86.writeWidth 8 v (BitVec.setWidth 64
    (if left then (BitVec.setWidth 8 v) <<< n else (BitVec.setWidth 8 v) >>> n))

def shiftSpec (left : Bool) (d t : BPF.Reg) (count : Count) (s : Outcome) : Outcome :=
  finish d t (shiftValue left (s.regs d) (count.number s.regs % 32)) s

theorem shift_bpf_correct (left : Bool) (d t : BPF.Reg) (count : Count)
    (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10) (hc : t ≠ .r4)
    (hv : count.Valid false) (s : BPF.State) :
    observeBpf (BPF.mexec (shiftBpf left d t count) s) =
      shiftSpec left d t count (observeBpf s) := by
  simp only [shiftBpf, List.append_assoc, prologue_exec]
  cases count
  all_goals first
  | (rw [ModuleControlDispatch.exec_tree .r4 (shiftLeaf left d t)
      (shiftEffect left d t) (shift_leaf_exec left d t ht)]
     rw [ModuleDispatch.selected_eq _ _ _ (by decide : 5 ≤ 64)]
     simp only [show 2^5 = 32 from rfl, Nat.zero_add])
  | rw [shift_leaf_exec left d t ht]
  all_goals simp [suffix, shiftEffect, prepared, shiftSpec, shiftValue, finish,
    ModuleMemory.storeSpec, Count.number, Count.Valid, ModuleBmiShift.bits,
    BPF.mexec, BPF.MInsn.step, observeBpf, Machine.State.read, Machine.State.write,
    Machine.State.set, BPF.RegFile.set, ht, Ne.symm ht, hf, Ne.symm hf,
    hd, Ne.symm hd, hc, Ne.symm hc, X86.writeWidth, Bits.lowMask, BitVec.or_comm] at hv ⊢
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals have hcount (n : Nat) : n % 32 < 32 := Nat.mod_lt _ (by decide)
  all_goals simp_all [BPF.RegFile.set, Ne.symm, shift_low_value, Nat.mod_eq_of_lt,
    masked_byte]

theorem shift_native_correct (m : X86RegMap) (hc : m.map .r4 = .rcx)
    (left : Bool) (d t : BPF.Reg) (count : Count) (hd : d ≠ .r10)
    (hv : count.Valid false) (s : X86.State) :
    observeX86 m (X86.mexec (shiftNative m left d t count) s) =
      shiftSpec left d t count (observeX86 m s) := by
  have he (n : Nat) (hn : count = .imm n) : (BitVec.ofNat 8 n).toNat = n := by
    subst count
    exact ModuleAluShift.encoded_count false n hv
  cases count <;> cases left <;>
    simp [shiftNative, shiftSpec, shiftValue, finish, ModuleMemory.storeSpec,
      X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, Count.number, observeX86,
      Machine.State.read, Machine.State.write, Machine.State.set,
      m.inj.eq_iff, Ne.symm hd, hc, he]
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set]

def arithmeticCert (m : X86RegMap) (kind : ModuleWideAlu.Kind) (d t : BPF.Reg)
    (src : Source) (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10)
    (hr : sourceTempValid src t) : X86StateEquiv m where
  spec := arithmeticSpec kind d t src
  bpf := arithmeticBpf kind d t src
  native := arithmeticNative m kind d t src
  writeSet := [d, t]
  bpfCorrect := arithmetic_bpf_correct kind d t src ht hf hd hr
  nativeCorrect := arithmetic_native_correct m kind d t src hd
  bpfWrites := by
    simp [arithmeticBpf, prologue, arithmeticBody, suffix, BPF.mwrites,
      BPF.MInsn.writes, BPF.Insn.dstReg, or_comm, or_left_comm]
  nativeWrites := by
    cases src <;> simp [arithmeticNative, X86.mwrites, X86.MInsn.writes,
      m.inj.eq_iff, or_comm]

theorem shift_leaf_writes (left : Bool) (d t r : BPF.Reg) (n : Nat)
    (h : r ∈ BPF.mwrites (shiftLeaf left d t n)) : r = d := by
  simpa [shiftLeaf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg] using h

def shiftCert (m : X86RegMap) (hc : m.map .r4 = .rcx) (left : Bool)
    (d t : BPF.Reg) (count : Count) (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10)
    (hr : t ≠ .r4) (hv : count.Valid false) : X86StateEquiv m where
  spec := shiftSpec left d t count
  bpf := shiftBpf left d t count
  native := shiftNative m left d t count
  writeSet := [d, t]
  bpfCorrect := shift_bpf_correct left d t count ht hf hd hr hv
  nativeCorrect := shift_native_correct m hc left d t count hd hv
  bpfWrites := by
    intro r h
    cases count <;>
      simp only [shiftBpf, BPF.mwrites, List.flatMap_append, List.mem_append] at h
    all_goals rcases h with (h | h) | h
    all_goals first
    | (have he := ModuleControlDispatch.writes_tree .r4 (shiftLeaf left d t) 5 0 d
        (fun n r => shift_leaf_writes left d t r n) r h
       simp [he])
    | (have he := shift_leaf_writes left d t r _ h; simp [he])
    | (have he : r = t := by
        simpa [prologue, suffix, BPF.MInsn.writes, BPF.Insn.dstReg, eq_comm] using h
       simp [he])
  nativeWrites := by
    cases count <;> simp [shiftNative, X86.mwrites, X86.MInsn.writes,
      m.inj.eq_iff, or_comm]

/-- x86/bpf_x86_alu.c:instantiate_addb/emit_addb_x86: ordinary and ARCH tags. -/
def bpf_x86_addb (m : X86RegMap) (d t : BPF.Reg) (src : Source)
    (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10) (hr : sourceTempValid src t) :
    X86StateEquiv m := arithmeticCert m .add d t src ht hf hd hr
/-- x86/bpf_x86_alu.c:instantiate_subb/emit_subb_x86: ordinary and ARCH tags. -/
def bpf_x86_subb (m : X86RegMap) (d t : BPF.Reg) (src : Source)
    (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10) (hr : sourceTempValid src t) :
    X86StateEquiv m := arithmeticCert m .sub d t src ht hf hd hr
/-- x86/bpf_x86_alu.c:instantiate_shlb/emit_shlb_x86: immediate and CL tags. -/
def bpf_x86_shlb (m : X86RegMap) (hc : m.map .r4 = .rcx) (d t : BPF.Reg) (c : Count)
    (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10) (hr : t ≠ .r4) (hv : c.Valid false) :
    X86StateEquiv m := shiftCert m hc true d t c ht hf hd hr hv
/-- x86/bpf_x86_alu.c:instantiate_shrb/emit_shrb_x86: immediate and CL tags. -/
def bpf_x86_shrb (m : X86RegMap) (hc : m.map .r4 = .rcx) (d t : BPF.Reg) (c : Count)
    (ht : t ≠ d) (hf : t ≠ .r10) (hd : d ≠ .r10) (hr : t ≠ .r4) (hv : c.Valid false) :
    X86StateEquiv m := shiftCert m hc false d t c ht hf hd hr hv

end Kinsn.ModuleByteAlu
