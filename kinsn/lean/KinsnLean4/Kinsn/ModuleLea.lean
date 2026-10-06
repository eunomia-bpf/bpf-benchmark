import KinsnLean4.Kinsn.ModuleRegister
import Mathlib.Tactic.Ring

namespace Kinsn.ModuleLea

@[simp] theorem narrow_add (a b : BitVec 64) :
    BitVec.setWidth 32 (a + b) = BitVec.setWidth 32 a + BitVec.setWidth 32 b :=
  BitVec.setWidth_add a b (by decide)

theorem shl_mul {w : Nat} (v : BitVec w) (n : Nat) :
    v <<< n = v * BitVec.ofNat w (2 ^ n) := by
  apply BitVec.eq_of_toNat_eq
  simp [BitVec.toNat_shiftLeft, Nat.shiftLeft_eq, Nat.mul_mod_mod]

/-- x86/bpf_x86_lea.c:instantiate_lea_bpf_reg/emit_lea: effective-address value. -/
def value (w : BPF.Width) (base index disp : BitVec 64) (scale : Nat) : BitVec 64 :=
  match w with
  | .w64 => base + (index <<< scale) + disp
  | .w32 => BitVec.setWidth 64
      (BitVec.setWidth 32 base + (BitVec.setWidth 32 index <<< scale) + BitVec.setWidth 32 disp)

/-- x86/bpf_x86_lea.c:instantiate_lea_bpf_reg, including repeated additions,
    the no-base immediate path, omitted zero displacement, and self-move when
    otherwise empty. The C alias rejection is the theorem's `halias`. -/
def bpf (w : BPF.Width) (dst base index : BPF.Reg) (scale : Nat)
    (hasBase hasIndex : Bool) (disp : BitVec 32) : List BPF.Insn :=
  let di := BitVec.signExtend 64 disp
  let mov d s := BPF.Insn.alu .mov w d (.reg s)
  let p := if hasBase then
      (if dst = base then [] else [mov dst base]) ++
      (if hasIndex then List.replicate (2 ^ scale) (.alu .add w dst (.reg index)) else [])
    else if hasIndex then
      (if dst = index then [] else [mov dst index]) ++
      (if scale = 0 then [] else [.alu .lsh w dst (BPF.immN scale)])
    else [.alu .mov w dst (.imm di)]
  let p := p ++ (if di = 0 ∨ (!hasBase && !hasIndex) then [] else [.alu .add w dst (.imm di)])
  if p = [] then [mov dst dst] else p

/-- x86/bpf_x86_lea.c:instantiate_lea_bpf_reg/emit_lea: architectural specification. -/
def spec (w : BPF.Width) (dst base index : BPF.Reg) (scale : Nat)
    (hasBase hasIndex : Bool) (disp : BitVec 32) (s : Outcome) : Outcome :=
  { s with
    regs := s.regs.set dst
      (value w (if hasBase then s.regs base else 0) (if hasIndex then s.regs index else 0)
        (BitVec.signExtend 64 disp) scale) }

/-- x86/bpf_x86_lea.c:emit_lea_x86/emit_lea. SIB and displacement encodings
    have 64-bit address size; LEAL narrows only the result (no 0x67 prefix). -/
def x86 (m : X86RegMap) (w : BPF.Width) (dst base index : BPF.Reg) (scale : Nat)
    (hasBase hasIndex : Bool) (disp : BitVec 32) : List X86.MInsn :=
  [.lea (w = .w32) (m.map dst) (if hasBase then some (m.map base) else none)
    (if hasIndex then some (m.map index) else none) scale (BitVec.signExtend 64 disp)]

set_option maxHeartbeats 0 in
theorem bpf_correct (w : BPF.Width) (dst base index : BPF.Reg) (scale : Nat)
    (hasBase hasIndex : Bool) (disp : BitVec 32) (hs : scale ≤ 3)
    (halias : hasBase = true → hasIndex = true → dst = index → dst = base ∧ scale = 0)
    (rf : BPF.RegFile) :
    BPF.exec (bpf w dst base index scale hasBase hasIndex disp) rf dst =
      value w (if hasBase then rf base else 0) (if hasIndex then rf index else 0)
        (BitVec.signExtend 64 disp) scale := by
  cases w <;> cases hasBase <;> cases hasIndex <;>
    by_cases hd : dst = base <;> by_cases hi : dst = index <;>
    by_cases hz : BitVec.signExtend 64 disp = 0#64
  all_goals interval_cases scale
  all_goals simp_all [bpf, value, BPF.exec, BPF.Insn.step, BPF.AluOp.eval,
    BPF.immN, BPF.RegFile.set, shl_mul, Ne.symm,
    BitVec.setWidth_shiftLeft_of_le, narrow_add]
  all_goals try ring_nf
  all_goals rfl

theorem bpf_writes (w : BPF.Width) (dst base index r : BPF.Reg) (scale : Nat)
    (hasBase hasIndex : Bool) (disp : BitVec 32) :
    r ∈ BPF.writes (bpf w dst base index scale hasBase hasIndex disp) → r = dst := by
  cases hasBase <;> cases hasIndex <;>
    by_cases hd : dst = base <;> by_cases hi : dst = index <;>
    by_cases hz : scale = 0 <;> by_cases he : BitVec.signExtend 64 disp = 0#64 <;>
    simp_all [bpf, BPF.writes, BPF.Insn.dstReg, List.mem_replicate,
      Nat.ne_of_gt (Nat.two_pow_pos scale)]

theorem x86_correct (m : X86RegMap) (w : BPF.Width) (dst base index : BPF.Reg)
    (scale : Nat) (hasBase hasIndex : Bool) (disp : BitVec 32) (s : X86.State) :
    observeX86 m (X86.mexec (x86 m w dst base index scale hasBase hasIndex disp) s) =
      spec w dst base index scale hasBase hasIndex disp (observeX86 m s) := by
  simp only [x86, X86.mexec_cons, X86.mexec_nil, X86.MInsn.step]
  rw [x86_observe_set]
  cases w <;> cases hasBase <;> cases hasIndex <;>
    simp [spec, value, observeX86, BitVec.setWidth_shiftLeft_of_le, narrow_add]

/-- x86/bpf_x86_lea.c:instantiate_lea32/instantiate_lea64 and
    emit_lea32_x86/emit_lea64_x86, at any injective JIT register map. -/
def cert (m : X86RegMap) (w : BPF.Width) (dst base index : BPF.Reg)
    (scale : Nat) (hasBase hasIndex : Bool) (disp : BitVec 32) (hs : scale ≤ 3)
    (halias : hasBase = true → hasIndex = true → dst = index → dst = base ∧ scale = 0) :
    X86StateEquiv m where
  spec := spec w dst base index scale hasBase hasIndex disp
  bpf := (bpf w dst base index scale hasBase hasIndex disp).map BPF.MInsn.core
  native := x86 m w dst base index scale hasBase hasIndex disp
  writeSet := [dst]
  bpfCorrect := by
    intro s
    rw [ModuleRegister.bpf_core_exec]
    simp only [observeBpf, spec]
    congr 1; funext r
    by_cases h : r = dst
    · subst r; simp [bpf_correct w dst base index scale hasBase hasIndex disp hs halias]
    · rw [BPF.exec_of_not_mem_writes _ _ _ (fun hr => h (bpf_writes w dst base index r scale hasBase hasIndex disp hr))]
      exact (BPF.RegFile.set_other _ _ _ _ h).symm
  nativeCorrect := x86_correct m w dst base index scale hasBase hasIndex disp
  bpfWrites := by
    intro r hr
    simp only [BPF.mwrites, List.flatMap_map, BPF.MInsn.writes] at hr
    exact List.mem_singleton.mpr (bpf_writes w dst base index r scale hasBase hasIndex disp
      (by simpa [BPF.writes, List.mem_flatMap, eq_comm] using hr))
  nativeWrites := by
    intro r hr
    simp [x86, X86.mwrites, X86.MInsn.writes, m.inj.eq_iff] at hr
    exact List.mem_singleton.mpr hr

end Kinsn.ModuleLea
