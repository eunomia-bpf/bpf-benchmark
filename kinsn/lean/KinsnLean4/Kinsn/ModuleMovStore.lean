import KinsnLean4.Kinsn.ModuleMemory

namespace Kinsn.ModuleMovStore

inductive Source where
  | reg (r : BPF.Reg)
  | imm (v : BitVec 32)

def Source.word (src : Source) (rf : BPF.RegFile) : BitVec 64 :=
  match src with
  | .reg r => rf r | .imm v => BitVec.signExtend 64 v

def Source.bpf : Source → BPF.Src
  | .reg r => .reg r | .imm v => .imm (BitVec.signExtend 64 v)

/-- x86/bpf_x86_mov.c:instantiate_store_reg's low-lane case and
    instantiate_mov_imm_store: one STX/ST, including ARCH forms. -/
def bpf (n : Nat) (b : BPF.Reg) (off : BitVec 64) (src : Source) : List BPF.MInsn :=
  [.store n b src.bpf off]

/-- x86/bpf_x86_mov.c:emit_store_reg_x86/emit_mov_imm_store_x86. For byte,
    word and doubleword stores only the encoded low n*8 bits are written;
    MOVQ's imm32 field sign-extends. The representative word is sign-extended
    decoded imm32 for every width; encoded_prefix checks the short fields. -/
def native (m : X86RegMap) (n : Nat) (b : BPF.Reg) (off : BitVec 64) (src : Source) :
    List X86.MInsn :=
  match src with
  | .reg r => [.store n (m.map r) (m.map b) off]
  | .imm v => [.storeImm n (m.map b) off (BitVec.signExtend 64 v)]

def spec (n : Nat) (b : BPF.Reg) (off : BitVec 64) (src : Source) (s : Outcome) : Outcome :=
  let a := s.regs b + off
  let v := src.word s.regs
  { s with
    mem := Machine.storeLE s.mem a n v
    trace := s.trace ++ [.write a n (BitVec.setWidth 64 (BitVec.setWidth (n*8) v))] }

/-- Byte/word/doubleword immediate encodings retain exactly the bits used by
    the store model, for positive and negative decoded imm32 values alike. -/
theorem encoded_prefix (n : Nat) (hn : n = 1 ∨ n = 2 ∨ n = 4) (imm : BitVec 32) :
    BitVec.setWidth (n*8) (BitVec.signExtend 64 imm) = BitVec.setWidth (n*8) imm := by
  rcases hn with hn | hn | hn <;> subst n <;> apply BitVec.eq_of_getLsbD_eq
  all_goals intro i hi
  all_goals simp only [BitVec.getLsbD_setWidth, BitVec.getLsbD_signExtend]
  all_goals interval_cases i <;> simp

theorem bpf_correct (n : Nat) (b : BPF.Reg) (off : BitVec 64) (src : Source) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf n b off src) s) = spec n b off src (observeBpf s) := by
  cases src <;>
    simp [bpf, Source.bpf, Source.word, spec, BPF.mexec, BPF.MInsn.step,
      observeBpf, Machine.State.write]

theorem native_correct (m : X86RegMap) (n : Nat) (b : BPF.Reg) (off : BitVec 64)
    (src : Source) (s : X86.State) :
    observeX86 m (X86.mexec (native m n b off src) s) =
      spec n b off src (observeX86 m s) := by
  cases src <;> rfl

def cert (m : X86RegMap) (n : Nat) (b : BPF.Reg) (off : BitVec 64) (src : Source) :
    X86StateEquiv m where
  spec := spec n b off src
  bpf := bpf n b off src
  native := native m n b off src
  writeSet := []
  bpfCorrect := bpf_correct n b off src
  nativeCorrect := native_correct m n b off src
  bpfWrites := by simp [bpf, BPF.mwrites, BPF.MInsn.writes]
  nativeWrites := by cases src <;> simp [native, X86.mwrites, X86.MInsn.writes]

/-- x86/bpf_x86_mov.c:instantiate_movw/emit_movw_x86: all four STORE tags.
    The decoder rejects a high-byte lane for words. Immediate range is
    [-32768,65535]; the stronger certificate covers every imm32 value. -/
def bpf_x86_movw (m : X86RegMap) (b : BPF.Reg) (off : BitVec 64) (src : Source) :
    X86StateEquiv m := cert m 2 b off src

/-- The named certificate's immediate writes have the emitter's exact imm16
    value in their normalized ordered access record. -/
theorem movw_immediate_trace (m : X86RegMap) (b : BPF.Reg) (off : BitVec 64)
    (imm : BitVec 32) (s : X86.State) :
    (X86.mexec (bpf_x86_movw m b off (.imm imm)).native s).trace =
      s.trace ++ [.write (s.regs (m.map b) + off) 2
        (BitVec.setWidth 64 (BitVec.setWidth 16 imm))] := by
  simp [bpf_x86_movw, cert, native, X86.mexec, X86.MInsn.step, Machine.State.write,
    encoded_prefix 2 (by simp)]

end Kinsn.ModuleMovStore
