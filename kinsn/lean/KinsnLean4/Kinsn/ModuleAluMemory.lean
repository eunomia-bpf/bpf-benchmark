import KinsnLean4.Kinsn.ModuleWideAlu

namespace Kinsn.ModuleAluMemory
open ModuleWideAlu (Kind width bits value)

def slot : BitVec 64 := -8

/-- x86/bpf_x86_alu.c:instantiate_x86_alu_mem, identical native/proof
    spill accesses bracket one ordinary-width operand read. -/
def bpf (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg) (scale : Nat)
    (off : BitVec 64) : List BPF.MInsn :=
  [.store 8 .r10 (.reg t) slot] ++
    (ModuleWideAlu.address indexed t b i scale).map BPF.MInsn.core ++
    [.load (if w32 then 4 else 8) t t off,
      .core (.alu kind.bpf (width w32) d (.reg t)), .load 8 t .r10 slot]

/-- x86/bpf_x86_alu.c:emit_alu_mem_x86/emit_alu_sib_x86/emit_alu_temp_slot:
    save the chosen live temporary, retain the optimized ALU memory instruction,
    then restore through the same program-specific frame register. -/
def native (m : X86RegMap) (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg)
    (scale : Nat) (off : BitVec 64) : List X86.MInsn :=
  [.store 8 (m.map t) (m.map .r10) slot,
    if indexed then .aluMem kind.native w32 (m.map d) (m.map b) (m.map i) scale off
      else .aluMemNarrow kind.native (bits w32) (m.map d) (m.map b) off,
    .load 8 (m.map t) (m.map .r10) slot]

def spec (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg) (scale : Nat)
    (off : BitVec 64) (s : Outcome) : Outcome :=
  let saved := ModuleMemory.storeSpec 8 t .r10 slot s
  let a := saved.regs b + (if indexed then saved.regs i <<< scale else 0) + off
  let n := if w32 then 4 else 8
  let v := Machine.loadLE saved.mem a n
  let aSlot := saved.regs .r10 + slot
  let restored := Machine.loadLE saved.mem aSlot 8
  { regs := (saved.regs.set d (value kind w32 (saved.regs d) v)).set t restored
    mem := saved.mem
    trace := (saved.trace ++ [.read a n v]) ++ [.read aSlot 8 restored] }

theorem bpf_correct (kind : Kind) (w32 indexed : Bool) (d b i t : BPF.Reg)
    (scale : Nat) (off : BitVec 64) (hs : scale ≤ 3) (ht : t ≠ d)
    (hi : t ≠ i) (hf : t ≠ .r10) (hd : d ≠ .r10) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf kind w32 indexed d b i t scale off) s) =
      spec kind w32 indexed d b i t scale off (observeBpf s) := by
  simp only [bpf, List.cons_append, List.nil_append, List.append_assoc, BPF.mexec]
  rw [ModuleDispatch.exec_core_tail, ModuleWideAlu.address_exec indexed t b i scale hi hs]
  cases w32 <;>
    simp [BPF.mexec, BPF.MInsn.step, BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval,
      width, value, spec, ModuleMemory.storeSpec, observeBpf, Machine.State.read,
      Machine.State.write, Machine.State.set, BPF.RegFile.set, ht, hi, hf, hd,
      Ne.symm ht, Ne.symm hf, Ne.symm hd, List.append_assoc]
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set]

theorem native_correct (m : X86RegMap) (kind : Kind) (w32 indexed : Bool)
    (d b i t : BPF.Reg) (scale : Nat) (off : BitVec 64) (hd : d ≠ .r10)
    (s : X86.State) :
    observeX86 m (X86.mexec (native m kind w32 indexed d b i t scale off) s) =
      spec kind w32 indexed d b i t scale off (observeX86 m s) := by
  cases indexed <;> cases w32 <;>
    simp [native, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, spec,
      ModuleMemory.storeSpec, observeX86, Machine.State.read, Machine.State.write,
      Machine.State.set, ModuleWideAlu.value_native, bits, X86.writeWidth,
      m.inj.eq_iff, Ne.symm hd, List.append_assoc]
  all_goals funext q
  all_goals by_cases hqt : q = t <;> by_cases hqd : q = d
  all_goals simp_all [BPF.RegFile.set, m.inj.eq_iff]

theorem address_writes (indexed : Bool) (t b i r : BPF.Reg) (scale : Nat)
    (h : r ∈ BPF.writes (ModuleWideAlu.address indexed t b i scale)) : r = t := by
  cases indexed <;>
    simpa [ModuleWideAlu.address, BPF.writes, BPF.Insn.dstReg,
      List.mem_replicate] using h

def certificate (m : X86RegMap) (kind : Kind) (w32 indexed : Bool)
    (d b i t : BPF.Reg) (scale : Nat) (off : BitVec 64) (hs : scale ≤ 3)
    (ht : t ≠ d) (hi : t ≠ i) (hf : t ≠ .r10) (hd : d ≠ .r10) : X86StateEquiv m where
  spec := spec kind w32 indexed d b i t scale off
  bpf := bpf kind w32 indexed d b i t scale off
  native := native m kind w32 indexed d b i t scale off
  writeSet := [d, t]
  bpfCorrect := bpf_correct kind w32 indexed d b i t scale off hs ht hi hf hd
  nativeCorrect := native_correct m kind w32 indexed d b i t scale off hd
  bpfWrites := by
    intro r hr
    simp only [bpf, BPF.mwrites, List.flatMap_append, List.flatMap_cons,
      List.flatMap_nil, BPF.MInsn.writes, BPF.Insn.dstReg, List.mem_append,
      List.mem_cons, List.mem_nil_iff, or_false, false_or] at hr
    rcases hr with hr | hr
    · have he := address_writes indexed t b i r scale
        (by simpa [BPF.writes, List.mem_flatMap, BPF.MInsn.writes, eq_comm] using hr)
      simp [he]
    · simpa [eq_comm, or_comm, or_left_comm] using hr
  nativeWrites := by
    cases indexed <;> simp [native, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

end Kinsn.ModuleAluMemory
