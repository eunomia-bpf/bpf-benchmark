import KProgFormal.ClightRefinement.Arm64CiliumCallerLink

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerWriter
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

/-- Alias the actual inline writer exposed by the checked complete-site equation. -/
noncomputable def writer : CC.Stmt := by
  run_tac do
    let info ← Lean.getConstInfo ``Arm64CiliumCallerLink.site_source
    let outer := info.type.getAppArgs[2]!
    unless outer.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original outer loop changed"
    let body := outer.getAppArgs[0]!
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original LR sequence changed"
    Lean.Elab.Tactic.closeMainGoal `original_inline_writer body.getAppArgs[1]!

noncomputable def rest : CC.Stmt := by
  run_tac do
    let value ← Lean.Elab.Term.elabTerm (← `(writer)) none
    let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf value)
    unless outer.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original writer loop changed"
    let body := outer.getAppArgs[0]!
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original SP sequence changed"
    Lean.Elab.Tactic.closeMainGoal `original_after_sp body.getAppArgs[1]!

noncomputable def oldSP : CC.Stmt :=
  .Sset ___a64_write_old_sp (.Evar ___a64_sp CC.tlong)

theorem writer_source : writer = .Sloop (.Ssequence oldSP rest) .Sbreak := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

noncomputable def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 (.Ssequence oldSP rest) .Sbreak k

/-- Real full-caller metadata and allocator supply SP's original local block. -/
theorem sp_local (m : CC.Mem) :
    ∃ block, (allocation m).1.get ___a64_sp = some (block,CC.tlong) ∧
      CC.Mem.rangePerm (allocation m).2 block 0 8 .Cur .Freeable = true := by
  have nr : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn hp hd ha hb => exact hn
  have member : (___a64_sp,CC.tlong) ∈ procedure.fn_vars := by decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) nr member
  have resource := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  exact ⟨block,binding,resource.2.2⟩

/-- The same LR store preserves SP's successful read,derived from its allocated
permission. No SP value or successful-reader premise is supplied. -/
theorem sp_after_lr {m after : CC.Mem} (lr : Arm64CiliumCallerLink.LRLocal m)
    (stored : CC.Mem.store .Mint64 (allocation m).2 lr.block 0
      (.Vlong Arm64CiliumCallerLink.token) = some after) :
    ∃ block value, (allocation m).1.get ___a64_sp = some (block,CC.tlong) ∧
      CC.Mem.load .Mint64 after block 0 = some value := by
  obtain ⟨block,binding,live⟩ := sp_local m
  have range := CC.Mem.rangePerm_implies live
    (by decide : CC.permOrder .Freeable .Readable = true)
  have readable : CC.Mem.validAccess (allocation m).2 .Mint64 block 0 .Readable = true := by
    change (CC.Mem.rangePerm (allocation m).2 block 0 8 .Cur .Readable && true) = true
    rw [range]
    rfl
  obtain ⟨value,read⟩ : ∃ value,CC.Mem.load .Mint64 (allocation m).2 block 0 = some value := by
    simp only [CC.Mem.load,readable,ite_true]
    exact ⟨_,rfl⟩
  refine ⟨block,value,binding,?_⟩
  rw [Arm64CiliumCallerLink.preserves_other_locals lr stored ___a64_sp CC.tlong block
    binding (by decide +kernel) .Mint64 0]
  exact read

/-- Four actual writer steps eagerly read SP and set the original temporary;
the memory,environment and original writer loop continuation stay exact. -/
theorem read_sp {m current : CC.Mem} (block : CC.Block) (value : CC.Val)
    (binding : (allocation m).1.get ___a64_sp = some (block,CC.tlong))
    (read : CC.Mem.load .Mint64 current block 0 = some value)
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 4
      (.State procedure writer k (allocation m).1 le current)
      (.State procedure rest (continuation k) (allocation m).1
        (le.set ___a64_write_old_sp value) current) := by
  have loaded : CC.doEvalExpr ge (allocation m).1 le current
      (.Evar ___a64_sp CC.tlong) = some value := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,binding]
    change CC.Mem.load .Mint64 current block 0 = some value
    exact read
  have step : CC.Step2 ge
      (.State procedure oldSP (.Kseq rest (continuation k)) (allocation m).1 le current) CC.E0
      (.State procedure .Sskip (.Kseq rest (continuation k)) (allocation m).1
        (le.set ___a64_write_old_sp value) current) := by
    apply CC.doStep_sound
    simp only [oldSP,CC.doStep,loaded]
  rw [writer_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))))

noncomputable def outerContinuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 (.Ssequence Arm64CiliumCallerLink.lrStatement writer) .Sbreak k

/-- One original LR store followed by the real eager SP read:8 source steps.
Allocator permissions derive both successful operations;the same after-memory
and exact two original loop continuations are retained. This starts at the
actual site,not at a claimed reached prefix. SP's value is not prescribed. -/
theorem begin_allocated (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ lr : Arm64CiliumCallerLink.LRLocal m, ∃ after block value,
      InternalRun ge 8
        (.State procedure Arm64CiliumCallerLink.site k (allocation m).1 le (allocation m).2)
        (.State procedure rest (continuation (outerContinuation k)) (allocation m).1
          (le.set ___a64_write_old_sp value) after) ∧
      CC.Mem.store .Mint64 (allocation m).2 lr.block 0
        (.Vlong Arm64CiliumCallerLink.token) = some after ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong Arm64CiliumCallerLink.token) ∧
      CC.Mem.load .Mint64 after block 0 = some value ∧
      FrameBelow m.nextblock (allocation m).2 after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨lr⟩ := Arm64CiliumCallerLink.lr_local m
  obtain ⟨after,first,stored,lrread,frame,access,next⟩ :=
    Arm64CiliumCallerLink.begin_link lr le k lr.live
  obtain ⟨block,value,binding,read⟩ := sp_after_lr lr stored
  have middle : InternalRun ge 4
      (.State procedure Arm64CiliumCallerLink.site k (allocation m).1 le (allocation m).2)
      (.State procedure writer (outerContinuation k) (allocation m).1 le after) := first
  have second := read_sp block value binding read le (outerContinuation k)
  exact ⟨lr,after,block,value,middle.trans second,stored,lrread,read,frame,access,next⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerWriter
