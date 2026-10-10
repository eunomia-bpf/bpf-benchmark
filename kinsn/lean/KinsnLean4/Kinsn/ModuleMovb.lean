import KinsnLean4.Kinsn.ModuleByteAlu
import KinsnLean4.Kinsn.ModuleNarrowLogic
import KinsnLean4.Kinsn.ModuleShiftedDispatch

namespace Kinsn.ModuleMovb

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

/-- Source bits 15:8 are dispatched before the sole observable byte write. -/
def highLeaf (b : BPF.Reg) (off : BitVec 64) (n : Nat) : List BPF.MInsn :=
  [.store 1 b (.imm (BitVec.ofNat 64 n)) off]

def highBpf (r b : BPF.Reg) (off : BitVec 64) : List BPF.MInsn :=
  ModuleShiftedDispatch.tree r 8 (highLeaf b off) 8 0

def directHigh (r b : X86.GPReg) : Bool :=
  [.rax, .rcx, .rdx, .rbx].contains r &&
    [.rax, .rcx, .rdx, .rbx, .rsp, .rbp, .rsi, .rdi].contains b

/-- June's AH/CH/DH/BH store when encodable; otherwise use the unmapped
    JIT AX register R11, whose value no BPF register can observe. -/
def highNative (m : X86RegMap) (r b : BPF.Reg) (off : BitVec 64) : List X86.MInsn :=
  if directHigh (m.map r) (m.map b) then [.storeHigh8 (m.map r) (m.map b) off]
  else [.core (.movRR .r11 (m.map r)), .core (.shiftI .shr .r11 8),
    .store 1 .r11 (m.map b) off]

def highSpec (r b : BPF.Reg) (off : BitVec 64) (s : Outcome) : Outcome :=
  let a := s.regs b + off
  let v := s.regs r >>> 8
  { s with
    mem := Machine.storeLE s.mem a 1 v
    trace := s.trace ++ [.write a 1 (BitVec.setWidth 64 (BitVec.setWidth 8 v))] }

theorem high_leaf_exec (b : BPF.Reg) (off : BitVec 64) (n : Nat)
    (s : BPF.State) (tail : List BPF.MInsn) :
    BPF.mexec (highLeaf b off n ++ tail) s =
      BPF.mexec tail (s.write (s.regs b + off) 1 (BitVec.ofNat 64 n)) := by
  simp [highLeaf, BPF.mexec, BPF.MInsn.step, BPF.Src.eval]

theorem high_bpf_correct (r b : BPF.Reg) (off : BitVec 64) (s : BPF.State) :
    observeBpf (BPF.mexec (highBpf r b off) s) = highSpec r b off (observeBpf s) := by
  rw [highBpf, ← List.append_nil (ModuleShiftedDispatch.tree r 8 (highLeaf b off) 8 0),
    ModuleShiftedDispatch.exec_tree r 8 (highLeaf b off)
      (fun n s => s.write (s.regs b + off) 1 (BitVec.ofNat 64 n)) (high_leaf_exec b off)
      8 0 (by decide) s [], ModuleDispatch.selected_eq _ _ _ (by decide : 8 ≤ 64)]
  have he : BitVec.ofNat 8 ((s.regs r).toNat >>> 8 % 256) =
      BitVec.setWidth 8 (s.regs r >>> 8) := by
    apply BitVec.eq_of_toNat_eq
    simp [BitVec.toNat_setWidth, BitVec.toNat_ofNat, BitVec.toNat_ushiftRight]
  simp [BPF.mexec, Machine.State.write, Machine.storeLE, highSpec, observeBpf, he]

theorem high_native_correct (m : X86RegMap) (r b : BPF.Reg) (off : BitVec 64)
    (hs : ∀ q, m.map q ≠ .r11) (s : X86.State) :
    observeX86 m (X86.mexec (highNative m r b off) s) =
      highSpec r b off (observeX86 m s) := by
  simp only [highNative]
  split_ifs
  · rfl
  · simp [X86.mexec_cons, X86.mexec_nil, X86.MInsn.step, X86.Insn.step,
      X86.ShiftOp.eval, highSpec, observeX86, Machine.State.set, Machine.State.write,
      X86.RegFile.set, hs]

theorem high_tree_writes (r b : BPF.Reg) (off : BitVec 64) (depth base : Nat) :
    BPF.mwrites (ModuleShiftedDispatch.tree r 8 (highLeaf b off) depth base) = [] := by
  induction depth generalizing base with
  | zero => simp [ModuleShiftedDispatch.tree, highLeaf, BPF.mwrites, BPF.MInsn.writes]
  | succ k ih =>
    simp only [ModuleShiftedDispatch.tree, BPF.mwrites, List.flatMap_append,
      List.flatMap_cons, List.flatMap_nil, BPF.MInsn.writes, List.nil_append, List.append_nil]
    change BPF.mwrites (ModuleShiftedDispatch.tree r 8 (highLeaf b off) k base) ++
      BPF.mwrites (ModuleShiftedDispatch.tree r 8 (highLeaf b off) k (base+2^k)) = []
    rw [ih, ih]
    rfl

def highCert (m : X86RegMap) (r b : BPF.Reg) (off : BitVec 64)
    (hs : ∀ q, m.map q ≠ .r11) : X86StateEquiv m where
  spec := highSpec r b off
  bpf := highBpf r b off
  native := highNative m r b off
  writeSet := []
  bpfCorrect := high_bpf_correct r b off
  nativeCorrect := high_native_correct m r b off hs
  bpfWrites := by simp [highBpf, high_tree_writes]
  nativeWrites := by
    intro r hr
    simp only [highNative] at hr
    split_ifs at hr
    · simpa [X86.mwrites, X86.MInsn.writes] using hr
    · simpa [X86.mwrites, X86.MInsn.writes, X86.Insn.dstReg, hs] using hr

inductive Operand where
  | imm (d : BPF.Reg) (v : BitVec 8)
  | store (b : BPF.Reg) (off : BitVec 16) (src : ModuleMovStore.Source)
  | high (r b : BPF.Reg) (off : BitVec 16)

def Operand.Valid (m : X86RegMap) : Operand → Prop
  | .imm d _ => d ≠ .r10
  | .store _ _ _ => True
  | .high _ _ _ => ∀ q, m.map q ≠ .r11

/-- x86/bpf_x86_mov.c:instantiate_movb/emit_movb_x86: every IMM, STORE,
    STORE_IMM and ARCH counterpart, including both byte lanes. The store
    certificate covers all imm32 values, stronger than the decoder's imm8 range. -/
def bpf_x86_movb (m : X86RegMap) (operand : Operand) (h : operand.Valid m) : X86StateEquiv m :=
  match operand with
  | .imm d v => immediateCert m d v
  | .store b off src => ModuleMovStore.cert m 1 b (BitVec.signExtend 64 off) src
  | .high r b off => highCert m r b (BitVec.signExtend 64 off) h

end Kinsn.ModuleMovb
