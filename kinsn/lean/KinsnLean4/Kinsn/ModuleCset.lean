import KinsnLean4.Kinsn.ModuleFlags

namespace Kinsn.ModuleCset

/-- arm64/bpf_arm64_ccmp.c:instantiate_cset: failure skips the remaining terms
and MOV 1. decode_cset_payload excludes dst from every term. -/
def terms (w failNE : Bool) (dst : BPF.Reg) : List BPF.Reg → List BPF.MInsn
  | [] => [.core (BPF.mov64 dst (.imm 1))]
  | r :: rs => .branch (if failNE then .ne else .eq)
      (if w then .w32 else .w64) r (.imm 0) (rs.length + 1) :: terms w failNE dst rs

def bpf (w f : Bool) (d : BPF.Reg) (rs : List BPF.Reg) : List BPF.MInsn :=
  .core (BPF.mov64 d (.imm 0)) :: terms w f d rs

/-- arm64/bpf_arm64_ccmp.c:emit_cset_arm64: CMP first,#0; CCMP subsequent
terms,#0,poison,continue; CSET dst,continue. No incoming NZCV premise. -/
def arm (m : ARMRegMap) (w f : Bool) (d first : BPF.Reg)
    (rest : List BPF.Reg) : List ARM64.MInsn :=
  .cmpZero w (m.map first) ::
    rest.map (fun r => ARM64.MInsn.ccmpZero w f (m.map r)) ++
    [.cset (m.map d) (!f)]

def succeeds (w f : Bool) (v : BitVec 64) : Bool :=
  if f then ModuleFlags.zeroTest w v else !ModuleFlags.zeroTest w v

def predicate (w f : Bool) (rs : List BPF.Reg) (rf : BPF.RegFile) : Bool :=
  rs.all (fun r => succeeds w f (rf r))

def spec (w f : Bool) (d : BPF.Reg) (rs : List BPF.Reg) (s : Outcome) : Outcome :=
  { s with regs := s.regs.set d (if predicate w f rs s.regs then 1 else 0) }

private theorem terms_length (w f : Bool) (d : BPF.Reg) (rs : List BPF.Reg) :
    (terms w f d rs).length = rs.length + 1 := by
  induction rs <;> simp_all [terms]

private theorem terms_drop (w f : Bool) (d : BPF.Reg) (rs : List BPF.Reg) :
    (terms w f d rs).drop (rs.length + 1) = [] := by
  rw [← terms_length w f d rs, List.drop_length]

private theorem branch_failure (w f : Bool) (v : BitVec 64) :
    BPF.Cond.test (if f then .ne else .eq) (if w then .w32 else .w64) v
      ((BPF.Src.imm 0).eval (fun _ => v)) = !succeeds w f v := by
  cases w <;> cases f <;>
    simp [BPF.Cond.test, BPF.Cond.eval, BPF.Src.eval, succeeds, ModuleFlags.zeroTest]

private theorem terms_correct (w f : Bool) (d : BPF.Reg) (rs : List BPF.Reg)
    (s : BPF.State) :
    BPF.mexec (terms w f d rs) s =
      if predicate w f rs s.regs then s.set d 1 else s := by
  induction rs with
  | nil =>
    simp [terms, predicate, BPF.mexec, BPF.MInsn.step, BPF.mov64,
      BPF.Insn.step, BPF.AluOp.eval, BPF.Src.eval, Machine.State.set]
    rfl
  | cons r rs ih =>
    simp only [terms, BPF.mexec]
    have hb : BPF.Cond.test (if f then .ne else .eq) (if w then .w32 else .w64)
        (s.regs r) ((BPF.Src.imm 0).eval s.regs) = !succeeds w f (s.regs r) :=
      branch_failure w f (s.regs r)
    rw [hb, terms_drop, BPF.mexec, ih]
    cases h : succeeds w f (s.regs r) <;> simp [predicate, h]

theorem bpf_correct (w f : Bool) (d : BPF.Reg) (rs : List BPF.Reg)
    (hd : d ∉ rs) (s : BPF.State) :
    observeBpf (BPF.mexec (bpf w f d rs) s) = spec w f d rs (observeBpf s) := by
  have hp : predicate w f rs ((s.set d 0).regs) = predicate w f rs s.regs := by
    induction rs with
    | nil => rfl
    | cons r rs ih =>
      have hn : r ≠ d := by intro he; subst r; exact hd (by simp)
      have ht : d ∉ rs := by intro he; exact hd (by simp [he])
      simp only [predicate] at ih
      simp only [predicate, List.all_cons]
      rw [Machine.set_other s d r 0 hn, ih ht]
  simp only [bpf, BPF.mexec, BPF.MInsn.step, BPF.mov64, BPF.Insn.step,
    BPF.AluOp.eval, BPF.Src.eval]
  change observeBpf (BPF.mexec (terms w f d rs) (s.set d 0)) = _
  rw [terms_correct, hp]
  cases h : predicate w f rs s.regs <;>
    simp only [h, Bool.false_eq_true, ↓reduceIte, spec, observeBpf,
      Machine.State.set]
  all_goals congr 1 <;> funext q <;> by_cases hq : q = d <;>
    simp [BPF.RegFile.set, hq]

private def proceed (f : Bool) (s : ARM64.State) : Bool :=
  if f then s.flags.z else !s.flags.z

private theorem chain_correct (m : ARMRegMap) (w f : Bool) (d : BPF.Reg)
    (rs : List BPF.Reg) (s : ARM64.State) :
    observeArm m (ARM64.mexec
      (rs.map (fun r => ARM64.MInsn.ccmpZero w f (m.map r)) ++
        [.cset (m.map d) (!f)]) s) =
    { observeArm m s with
      regs := (observeArm m s).regs.set d
        (if proceed f s && predicate w f rs (observeArm m s).regs then 1 else 0) } := by
  induction rs generalizing s with
  | nil =>
    simp only [List.map_nil, List.nil_append, ARM64.mexec_cons, ARM64.mexec_nil,
      ARM64.MInsn.step, arm_observe_set]
    cases f <;> simp [proceed, predicate]
  | cons r rs ih =>
    simp only [List.map_cons, List.cons_append, ARM64.mexec_cons]
    rw [ih]
    have ho : observeArm m ((ARM64.MInsn.ccmpZero w f (m.map r)).step s) =
        observeArm m s := rfl
    rw [ho]
    have hp : proceed f ((ARM64.MInsn.ccmpZero w f (m.map r)).step s) =
        (proceed f s && succeeds w f ((observeArm m s).regs r)) := by
      cases w <;> cases f <;> cases hz : s.flags.z <;>
        simp [proceed, succeeds, ARM64.MInsn.step, Machine.subFlags,
          ModuleFlags.zeroTest, observeArm, hz]
    rw [hp]
    simp [predicate, Bool.and_assoc]

theorem arm_correct (m : ARMRegMap) (w f : Bool) (d first : BPF.Reg)
    (rest : List BPF.Reg) (s : ARM64.State) :
    observeArm m (ARM64.mexec (arm m w f d first rest) s) =
      spec w f d (first :: rest) (observeArm m s) := by
  simp only [arm, List.cons_append, ARM64.mexec_cons]
  rw [chain_correct]
  have ho : observeArm m ((ARM64.MInsn.cmpZero w (m.map first)).step s) =
      observeArm m s := rfl
  rw [ho]
  have hp : proceed f ((ARM64.MInsn.cmpZero w (m.map first)).step s) =
      succeeds w f ((observeArm m s).regs first) := by
    cases w <;> cases f <;>
      simp [proceed, succeeds, ARM64.MInsn.step, Machine.subFlags,
        ModuleFlags.zeroTest, observeArm]
  rw [hp]
  rfl

private theorem terms_writes (w f : Bool) (d : BPF.Reg) (rs : List BPF.Reg) :
    BPF.mwrites (terms w f d rs) = [d] := by
  induction rs <;> simp_all [terms, BPF.mwrites, BPF.MInsn.writes,
    BPF.mov64, BPF.Insn.dstReg]

def cert (m : ARMRegMap) (w f : Bool) (d first : BPF.Reg) (rest : List BPF.Reg)
    (hd : d ∉ first :: rest) : ArmStateEquiv m where
  spec := spec w f d (first :: rest)
  bpf := bpf w f d (first :: rest)
  native := arm m w f d first rest
  writeSet := [d]
  bpfCorrect := bpf_correct w f d (first :: rest) hd
  nativeCorrect := arm_correct m w f d first rest
  bpfWrites := by
    intro r hr
    change r ∈ BPF.mwrites (.core (BPF.mov64 d (.imm 0)) :: terms w f d (first :: rest)) at hr
    rw [show BPF.mwrites (.core (BPF.mov64 d (.imm 0)) :: terms w f d (first :: rest)) = [d, d] by
      change [d] ++ BPF.mwrites (terms w f d (first :: rest)) = _
      rw [terms_writes]
      rfl] at hr
    simpa using hr
  nativeWrites := by
    intro r hr
    simpa [arm, ARM64.mwrites, List.flatMap_append, List.flatMap_map,
      ARM64.MInsn.writes, m.inj.eq_iff] using hr

theorem bpf_arm64_cset_x_cond_refines (m : ARMRegMap) (w f : Bool)
    (d first : BPF.Reg) (rest : List BPF.Reg) (hd : d ∉ first :: rest)
    (b : BPF.State) (a : ARM64.State) (h : observeBpf b = observeArm m a) :
    observeBpf (BPF.mexec (bpf w f d (first :: rest)) b) =
      observeArm m (ARM64.mexec (arm m w f d first rest) a) :=
  (cert m w f d first rest hd).arm_refines b a h

end Kinsn.ModuleCset
