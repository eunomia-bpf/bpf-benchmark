import KinsnLean4.Kinsn.ModuleEndian
import KinsnLean4.Kinsn.ModuleLea
import KinsnLean4.Kinsn.ModuleDispatch

namespace Kinsn.ModuleMovbeWide

/-- x86/bpf_x86_movbe.c:instantiate_movbe_wide: destination becomes the
    effective address before the load overwrites it. Every alias has a path. -/
def address (d b i : BPF.Reg) (scale : Nat) : List BPF.Insn :=
  if d = b ∧ d = i then [.alu .mul .w64 d (BPF.immN (1 + 2^scale))]
  else if d = b then List.replicate (2^scale) (.alu .add .w64 d (.reg i))
  else [.alu .mov .w64 d (.reg i), .alu .mul .w64 d (BPF.immN (2^scale)),
    .alu .add .w64 d (.reg b)]

/-- x86/bpf_x86_movbe.c:instantiate_movbe_wide/instantiate_movbe_indexed:
    one ordinary-width load and one BSWAP after optional address formation. -/
def bpf (w32 indexed : Bool) (d b i : BPF.Reg) (scale : Nat) (off : BitVec 64) :
    List BPF.MInsn :=
  (if indexed then (address d b i scale).map BPF.MInsn.core else []) ++
    ModuleEndian.bpf w32 d (if indexed then d else b) off

/-- x86/bpf_x86_movbe.c:emit_movbe_indexed_x86: MOVBE r32/r64,[base+index*scale+off]
    or the ordinary base+offset encoding, with Linux's register map. -/
def native (m : X86RegMap) (w32 indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) : List X86.MInsn :=
  if indexed then [.loadIndex (if w32 then 4 else 8) (m.map d) (m.map b) (m.map i)
    scale off true] else ModuleEndian.x86 m w32 d b off

def spec (w32 indexed : Bool) (d b i : BPF.Reg) (scale : Nat) (off : BitVec 64)
    (s : Outcome) : Outcome :=
  let a := s.regs b + (if indexed then s.regs i <<< scale else 0) + off
  let n := if w32 then 4 else 8
  let v := Machine.loadLE s.mem a n
  { regs := s.regs.set d (ModuleEndian.swap w32 v), mem := s.mem,
    trace := s.trace ++ [.read a n v] }

set_option maxHeartbeats 0 in
theorem address_result (d b i : BPF.Reg) (scale : Nat) (hs : scale ≤ 3)
    (rf : BPF.RegFile) :
    BPF.exec (address d b i scale) rf d = rf b + (rf i <<< scale) := by
  by_cases hb : d = b <;> by_cases hi : d = i
  all_goals interval_cases scale
  all_goals simp_all [address, BPF.exec, BPF.Insn.step, BPF.AluOp.eval,
    BPF.immN, BPF.RegFile.set, ModuleLea.shl_mul, Ne.symm]
  all_goals apply BitVec.eq_of_toNat_eq
  all_goals simp [BitVec.toNat_mul, BitVec.toNat_add, Nat.add_mod_mod,
    Nat.mod_add_mod, BitVec.toNat_ofNat]
  all_goals omega

theorem address_writes (d b i t : BPF.Reg) (scale : Nat) :
    t ∈ BPF.writes (address d b i scale) → t = d := by
  by_cases hb : d = b <;> by_cases hi : d = i <;>
    simp_all [address, BPF.writes, BPF.Insn.dstReg, List.mem_replicate]

theorem address_exec (d b i : BPF.Reg) (scale : Nat) (hs : scale ≤ 3)
    (rf : BPF.RegFile) :
    BPF.exec (address d b i scale) rf = rf.set d (rf b + (rf i <<< scale)) := by
  funext t
  by_cases h : t = d
  · subst t; simpa using address_result d b i scale hs rf
  · rw [BPF.exec_of_not_mem_writes _ _ _
      (fun ht => h (address_writes d b i t scale ht))]
    exact (BPF.RegFile.set_other _ _ _ _ h).symm

theorem bpf_correct (w32 indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (hs : scale ≤ 3) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf w32 indexed d b i scale off) s) =
      spec w32 indexed d b i scale off (observeBpf s) := by
  cases indexed
  · simpa [bpf, spec, ModuleEndian.spec, ModuleMemory.loadSpec,
      ModuleRegister.unarySpec, BPF.RegFile.set_set_same] using
      ModuleEndian.bpf_correct w32 d b off s
  · simp only [bpf, ↓reduceIte, ModuleDispatch.exec_core_tail]
    rw [address_exec d b i scale hs]
    rw [ModuleEndian.bpf_correct]
    cases w32 <;>
      simp [ModuleEndian.spec, spec, observeBpf, ModuleMemory.loadSpec,
        ModuleRegister.unarySpec, BPF.RegFile.set_set_same]

theorem native_correct (m : X86RegMap) (w32 indexed : Bool) (d b i : BPF.Reg)
    (scale : Nat) (off : BitVec 64) (s : X86.State) :
    observeX86 m (X86.mexec (native m w32 indexed d b i scale off) s) =
      spec w32 indexed d b i scale off (observeX86 m s) := by
  cases indexed
  · simpa [native, spec, ModuleEndian.spec, ModuleMemory.loadSpec,
      ModuleRegister.unarySpec, BPF.RegFile.set_set_same] using
      ModuleEndian.x86_correct m w32 d b off s
  · simp only [native, ↓reduceIte, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
    rw [x86_observe_set]
    cases w32 <;>
      simp [spec, ModuleEndian.swap, BPF.Insn.evalBswap, observeX86,
        X86.writeWidth, X86.reverseLoad, Machine.State.read]

def cert (m : X86RegMap) (w32 indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (hs : scale ≤ 3) : X86StateEquiv m where
  spec := spec w32 indexed d b i scale off
  bpf := bpf w32 indexed d b i scale off
  native := native m w32 indexed d b i scale off
  writeSet := [d]
  bpfCorrect := bpf_correct w32 indexed d b i scale off hs
  nativeCorrect := native_correct m w32 indexed d b i scale off
  bpfWrites := by
    intro t ht
    cases indexed <;>
      simp only [bpf, ↓reduceIte, ModuleEndian.bpf,
        BPF.mwrites, List.flatMap_append, List.flatMap_cons, List.flatMap_nil,
        BPF.MInsn.writes, BPF.Insn.dstReg, List.mem_append,
        List.mem_cons, List.mem_nil_iff, or_false] at ht
    · simpa using ht
    · rcases ht with ht | ht
      · exact List.mem_singleton.mpr (address_writes d b i t scale
          (by simpa [BPF.writes, List.mem_flatMap, BPF.MInsn.writes, eq_comm] using ht))
      · simpa using ht
  nativeWrites := by
    cases indexed <;> simp [native, ModuleEndian.x86, X86.mwrites,
      X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_movbe.c:instantiate_movbe32_indexed/emit_movbe32_indexed_x86. -/
def bpf_x86_movbe32 (m : X86RegMap) (indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (hs : scale ≤ 3) : X86StateEquiv m := cert m true indexed d b i scale off hs
/-- x86/bpf_x86_movbe.c:instantiate_movbe64_indexed/emit_movbe64_indexed_x86. -/
def bpf_x86_movbe64 (m : X86RegMap) (indexed : Bool) (d b i : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (hs : scale ≤ 3) : X86StateEquiv m := cert m false indexed d b i scale off hs

end Kinsn.ModuleMovbeWide
