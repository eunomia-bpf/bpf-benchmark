import KinsnLean4.Kinsn.ModuleByteAlu
import KinsnLean4.Kinsn.ModuleNarrowLogic

namespace Kinsn.ModuleMovb

def slot : BitVec 64 := -8

/-- x86/bpf_x86_mov.c:instantiate_movb_imm: clear the live low byte and OR
    the positive decoded imm8. No scratch registers or unsaved ARCH slots. -/
def immediateBpf (d : BPF.Reg) (v : BitVec 8) : List BPF.MInsn :=
  [.core (.alu .and .w64 d (.imm (BitVec.signExtend 64 (-256 : BitVec 32)))),
    .core (.alu .or .w64 d (.imm (BitVec.signExtend 64 (BitVec.setWidth 32 v))))]

/-- x86/bpf_x86_mov.c:emit_movb_imm_x86: C6 /0 MOV dst8,imm8. -/
def immediateNative (m : X86RegMap) (d : BPF.Reg) (v : BitVec 8) : List X86.MInsn :=
  [.movImm8 (m.map d) v]

def immediateSpec (d : BPF.Reg) (v : BitVec 8) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (X86.writeWidth 8 (s.regs d) (BitVec.setWidth 64 v)) }

theorem immediate_bpf_correct (d : BPF.Reg) (v : BitVec 8) (s : BPF.State) :
    observeBpf (BPF.mexec (immediateBpf d v) s) = immediateSpec d v (observeBpf s) := by
  simp [immediateBpf, immediateSpec, BPF.mexec, BPF.MInsn.step, BPF.Insn.step,
    BPF.AluOp.eval, BPF.Src.eval, ModuleByteAlu.high_immediate,
    ModuleNarrowLogic.positive_immediate 8 (by simp), X86.writeWidth,
    ModuleByteAlu.masked_byte, Bits.lowMask, observeBpf, BPF.RegFile.set_set_same]

theorem immediate_native_correct (m : X86RegMap) (d : BPF.Reg) (v : BitVec 8)
    (s : X86.State) :
    observeX86 m (X86.mexec (immediateNative m d v) s) =
      immediateSpec d v (observeX86 m s) := by
  simp only [immediateNative, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  rw [x86_observe_set]
  rfl

def immediateCert (m : X86RegMap) (d : BPF.Reg) (v : BitVec 8) : X86StateEquiv m where
  spec := immediateSpec d v
  bpf := immediateBpf d v
  native := immediateNative m d v
  writeSet := [d]
  bpfCorrect := immediate_bpf_correct d v
  nativeCorrect := immediate_native_correct m d v
  bpfWrites := by simp [immediateBpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by simp [immediateNative, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff]

/-- x86/bpf_x86_mov.c:instantiate_store_reg's high-byte lane: five instructions,
    including matching spill memory before and after the byte store. -/
def highBpf (r b t : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  [.store 8 .r10 (.reg t) slot, .core (.alu .mov .w64 t (.reg r)),
    .core (.alu .rsh .w64 t (BPF.immN 8)), .store 1 b (.reg t) off, .load 8 t .r10 slot]

/-- x86/bpf_x86_mov.c:emit_store_reg_x86/emit_mov_store_slot: save; MOV64;
    SHR64 8; low-byte MOV store; restore. Unlike AH/CH/DH/BH, this sequence
    also encodes extended base/source registers and private-stack R10. -/
def highNative (m : X86RegMap) (r b t : BPF.Reg) (off : BitVec 64) : List X86.MInsn :=
  [.store 8 (m.map t) (m.map .r10) slot, .core (.movRR (m.map t) (m.map r)),
    .core (.shiftI .shr (m.map t) 8), .store 1 (m.map t) (m.map b) off,
    .load 8 (m.map t) (m.map .r10) slot]

def highSpec (r b t : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  let saved := ModuleMemory.storeSpec 8 t .r10 slot s
  let a := saved.regs b + off
  let v := saved.regs r >>> 8
  let mem := Machine.storeLE saved.mem a 1 v
  let aSlot := saved.regs .r10 + slot
  let restored := Machine.loadLE mem aSlot 8
  { regs := saved.regs.set t restored
    mem := mem
    trace := (saved.trace ++ [.write a 1 (BitVec.setWidth 64 (BitVec.setWidth 8 v))]) ++
      [.read aSlot 8 restored] }

theorem high_bpf_correct (r b t : BPF.Reg) (off : BitVec 64)
    (hb : t ≠ b) (hf : t ≠ .r10) (s : BPF.State) :
    observeBpf (BPF.mexec (highBpf r b t off) s) = highSpec r b t off (observeBpf s) := by
  simp [highBpf, highSpec, ModuleMemory.storeSpec, BPF.mexec, BPF.MInsn.step,
    BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval, BPF.immN, observeBpf,
    Machine.State.read, Machine.State.write, Machine.State.set, BPF.RegFile.set,
    Ne.symm hb, Ne.symm hf, List.append_assoc]
  funext q
  by_cases hqt : q = t <;> simp_all [BPF.RegFile.set]

theorem native_extract (r t : X86.GPReg) (s : X86.State) (tail : List X86.MInsn) :
    X86.mexec ([.core (.movRR t r), .core (.shiftI .shr t 8)] ++ tail) s =
      X86.mexec tail (s.set t (s.regs r >>> 8)) := by
  simp [X86.mexec_cons, X86.MInsn.step, X86.Insn.step, X86.ShiftOp.eval,
    X86.RegFile.set, Machine.State.set]
  apply congrArg (X86.mexec tail)
  congr 1
  funext q
  by_cases hq : q = t <;> simp [X86.RegFile.set, hq]

/-- Keeping the saved input state abstract avoids expanding an eight-byte
    spill twice inside the native core-register substitutions. -/
theorem native_store_restore (m : X86RegMap) (b t : BPF.Reg) (off v : BitVec 64)
    (hb : t ≠ b) (hf : t ≠ .r10) (s : X86.State) :
    observeX86 m (X86.mexec
      [.store 1 (m.map t) (m.map b) off, .load 8 (m.map t) (m.map .r10) slot]
      (s.set (m.map t) v)) =
    { regs := (observeX86 m s).regs.set t (Machine.loadLE
        (Machine.storeLE s.mem (s.regs (m.map b) + off) 1 v)
        (s.regs (m.map .r10) + slot) 8)
      mem := Machine.storeLE s.mem (s.regs (m.map b) + off) 1 v
      trace := (s.trace ++ [.write (s.regs (m.map b) + off) 1
        (BitVec.setWidth 64 (BitVec.setWidth 8 v))]) ++
        [.read (s.regs (m.map .r10) + slot) 8 (Machine.loadLE
          (Machine.storeLE s.mem (s.regs (m.map b) + off) 1 v)
          (s.regs (m.map .r10) + slot) 8)] } := by
  simp [X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, observeX86,
    Machine.State.read, Machine.State.write, Machine.State.set,
    m.inj.eq_iff, Ne.symm hb, Ne.symm hf]
  funext q
  by_cases hqt : q = t <;> simp_all [BPF.RegFile.set]

theorem high_native_correct (m : X86RegMap) (r b t : BPF.Reg) (off : BitVec 64)
    (hb : t ≠ b) (hf : t ≠ .r10) (s : X86.State) :
    observeX86 m (X86.mexec (highNative m r b t off) s) =
      highSpec r b t off (observeX86 m s) := by
  change observeX86 m (X86.mexec
    (.store 8 (m.map t) (m.map .r10) slot ::
      ([.core (.movRR (m.map t) (m.map r)), .core (.shiftI .shr (m.map t) 8)] ++
        [.store 1 (m.map t) (m.map b) off, .load 8 (m.map t) (m.map .r10) slot])) s) = _
  rw [X86.mexec_cons, native_extract, native_store_restore m b t off _ hb hf]
  rfl

def highCert (m : X86RegMap) (r b t : BPF.Reg) (off : BitVec 64)
    (hb : t ≠ b) (hf : t ≠ .r10) : X86StateEquiv m where
  spec := highSpec r b t off
  bpf := highBpf r b t off
  native := highNative m r b t off
  writeSet := [t]
  bpfCorrect := high_bpf_correct r b t off hb hf
  nativeCorrect := high_native_correct m r b t off hb hf
  bpfWrites := by simp [highBpf, BPF.mwrites, BPF.MInsn.writes, BPF.Insn.dstReg]
  nativeWrites := by
    simp [highNative, X86.mwrites, X86.MInsn.writes, X86.Insn.dstReg, m.inj.eq_iff]

inductive Operand where
  | imm (d : BPF.Reg) (v : BitVec 8)
  | store (b : BPF.Reg) (off : BitVec 16) (src : ModuleMovStore.Source)
  | high (r b t : BPF.Reg) (off : BitVec 16)

def Operand.Valid : Operand → Prop
  | .imm d _ => d ≠ .r10
  | .store _ _ _ => True
  | .high _ b t _ => t ≠ b ∧ t ≠ .r10

/-- x86/bpf_x86_mov.c:instantiate_movb/emit_movb_x86: every IMM, STORE,
    STORE_IMM and ARCH counterpart, including both byte lanes. The store
    certificate covers all imm32 values, stronger than the decoder's imm8 range. -/
def bpf_x86_movb (m : X86RegMap) (operand : Operand) (h : operand.Valid) : X86StateEquiv m :=
  match operand with
  | .imm d v => immediateCert m d v
  | .store b off src => ModuleMovStore.cert m 1 b (BitVec.signExtend 64 off) src
  | .high r b t off => highCert m r b t (BitVec.signExtend 64 off) h.1 h.2

end Kinsn.ModuleMovb
