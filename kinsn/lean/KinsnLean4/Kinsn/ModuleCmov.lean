import KinsnLean4.Kinsn.ModuleFlags
import KinsnLean4.Kinsn.Catalog

namespace Kinsn.ModuleCmov

/-- x86/bpf_x86_cmov.c:emit_cmp_cmov_rr_x86. Value32 uses
MOV R11D,src32 (which preserves CMP flags), then CMOVcc dst64,R11.
R11 is outside both ordinary and private-stack Linux BPF register maps. -/
def native (m : X86RegMap) (c : X86.CC) (cmp32 value32 : Bool)
    (l r dst src : BPF.Reg) : List X86.MInsn :=
  [.cmp cmp32 (m.map l) (m.map r)] ++
    (if value32 then [.mov32 .r11 (m.map src)] else []) ++
    [.cmov c false (m.map dst) (if value32 then .r11 else m.map src)]

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmov_rr: false leaves dst unchanged;
true MOV32 zero-extends the source, including when src=dst. -/
def spec (c : X86.CC) (cmp32 value32 : Bool) (l r dst src : BPF.Reg)
    (s : Outcome) : Outcome :=
  { s with
    regs := s.regs.set dst
      (if ModuleFlags.cmpPredicate c cmp32 (s.regs l) (s.regs r) then
        if value32 then BitVec.setWidth 64 (BitVec.setWidth 32 (s.regs src))
        else s.regs src
       else s.regs dst) }

theorem bpf_correct (c : X86.CC) (cmp32 value32 : Bool)
    (l r dst src : BPF.Reg) (s : BPF.State) :
    observeBpf (BPF.mexec (ModuleFlags.cmovBpf c cmp32 value32 l r dst src) s) =
      spec c cmp32 value32 l r dst src (observeBpf s) := by
  cases c <;> cases cmp32 <;> cases value32 <;>
    simp [ModuleFlags.cmovBpf, spec, ModuleFlags.cmpPredicate, ModuleFlags.cmpVal,
      BPF.mexec, BPF.MInsn.step, BPF.Cond.test, BPF.Cond.eval,
      BPF.mov32, BPF.mov64, BPF.Insn.step, BPF.AluOp.eval, observeBpf]
  all_goals split <;> simp_all
  all_goals funext q; by_cases h : q = dst <;> simp [BPF.RegFile.set, h]
  all_goals intro hi; omega

private theorem scratch_observe (m : X86RegMap) (h : ∀ r, m.map r ≠ .r11)
    (s : X86.State) (v : BitVec 64) : observeX86 m (s.set .r11 v) =
      observeX86 m s := by
  unfold observeX86
  congr 1
  funext r
  exact Machine.set_other s .r11 (m.map r) v (h r)

theorem native_correct (m : X86RegMap) (h : ∀ r, m.map r ≠ .r11)
    (c : X86.CC) (cmp32 value32 : Bool) (l r dst src : BPF.Reg) (s : X86.State) :
    observeX86 m (X86.mexec (native m c cmp32 value32 l r dst src) s) =
      spec c cmp32 value32 l r dst src (observeX86 m s) := by
  cases value32 with
  | false =>
    simpa [native, ModuleFlags.cmovX86, spec, ModuleFlags.cmovSpec] using
      ModuleFlags.cmov_x86_correct64 m c cmp32 l r dst src s
  | true =>
    let t := (X86.MInsn.cmp cmp32 (m.map l) (m.map r)).step s
    change observeX86 m ((t.set .r11
      (BitVec.setWidth 64 (BitVec.setWidth 32 (s.regs (m.map src))))).set
      (m.map dst) (if c.test t.flags then
        (t.set .r11 (BitVec.setWidth 64 (BitVec.setWidth 32
          (s.regs (m.map src))))).regs .r11
        else (t.set .r11 (BitVec.setWidth 64 (BitVec.setWidth 32
          (s.regs (m.map src))))).regs (m.map dst))) = _
    rw [x86_observe_set, scratch_observe m h, Machine.set_same,
      Machine.set_other _ _ _ _ (h dst)]
    dsimp only [t]
    rw [ModuleFlags.cmp_flags_condition]
    rfl

/-- Full-state certificate for every accepted width and operand alias. -/
def cert (m : X86RegMap) (h : ∀ r, m.map r ≠ .r11)
    (c : X86.CC) (cmp32 value32 : Bool) (l r dst src : BPF.Reg) : X86StateEquiv m where
  spec := spec c cmp32 value32 l r dst src
  bpf := ModuleFlags.cmovBpf c cmp32 value32 l r dst src
  native := native m c cmp32 value32 l r dst src
  writeSet := [dst]
  bpfCorrect := bpf_correct c cmp32 value32 l r dst src
  nativeCorrect := native_correct m h c cmp32 value32 l r dst src
  bpfWrites := by
    cases value32 <;> simp [ModuleFlags.cmovBpf, BPF.mwrites, BPF.MInsn.writes,
      BPF.mov32, BPF.mov64, BPF.Insn.dstReg]
  nativeWrites := by
    cases value32 <;> simp [native, X86.mwrites, X86.MInsn.writes,
      m.inj.eq_iff, h]

private theorem jit_no_r11 (r : BPF.Reg) : Catalog.x86Map.map r ≠ .r11 := by
  cases r <;> decide

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmove/emit_cmp_cmove_x86. -/
def bpf_x86_cmp_cmove (cmp32 value32 : Bool) (l r dst src : BPF.Reg) :
    X86StateEquiv Catalog.x86Map := cert Catalog.x86Map jit_no_r11 .e cmp32 value32 l r dst src

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmovne/emit_cmp_cmovne_x86. -/
def bpf_x86_cmp_cmovne (cmp32 value32 : Bool) (l r dst src : BPF.Reg) :
    X86StateEquiv Catalog.x86Map := cert Catalog.x86Map jit_no_r11 .ne cmp32 value32 l r dst src

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmovb/emit_cmp_cmovb_x86. -/
def bpf_x86_cmp_cmovb (cmp32 value32 : Bool) (l r dst src : BPF.Reg) :
    X86StateEquiv Catalog.x86Map := cert Catalog.x86Map jit_no_r11 .b cmp32 value32 l r dst src

end Kinsn.ModuleCmov
