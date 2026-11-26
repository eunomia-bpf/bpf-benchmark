import KProgFormal.ClightRefinement.Arm64MemsetClobberReturn

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetReturn

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler allocation)

theorem locals_source : handler.fn_vars =
    [(Arm64Program.___kprog_c_store_value,CC.tulong),
     (Arm64Program.___kprog_c_store_value__1,CC.tuint),
     (Arm64Program.___kprog_c_store_value__2,CC.tushort),
     (Arm64Program.___kprog_c_store_value__3,CC.tuchar),
     (Arm64Program.___kprog_c_store_value__4,CC.tulong),
     (Arm64Program.___kprog_c_store_value__5,CC.tuint),
     (Arm64Program.___kprog_c_store_value__6,CC.tushort),
     (Arm64Program.___kprog_c_store_value__7,CC.tuchar)] := rfl

private def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless actual.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original memset loop changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memset_return_body actual.getAppArgs[0]!

theorem continuation_source (k : CC.Cont) : Arm64MemsetSource.continuation k = .Kloop1 body .Sbreak k := rfl

/-- These are the real PTree-enumerated eight local ranges consumed by the
original return. Free changes their permissions and retains older blocks. -/
structure FreeResult (before current after : CC.Mem) : Prop where
  freed : CC.Mem.freeList current (CC.blocksOfEnv world.genv_cenv (allocation before).1) = some after
  caller : FrameBelow before.nextblock current after
  contents : after.contents = current.contents
  nextblock : after.nextblock = current.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (allocation before).1, ∀ ofs,
    row.2.1 ≤ ofs → ofs < row.2.2 → ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false

/-- The same actual allocation and current access map derive all live
Freeable ranges. Imported local deallocation constructs the real output. -/
theorem free (before current : CC.Mem)
    (access : current.access = (allocation before).2.access) :
    ∃ after, FreeResult before current after := by
  have owned (id : CC.Ident) (value : CC.Block × CC.Ty)
      (binding : (allocation before).1.get id = some value) :
      CC.Mem.rangePerm current value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true :=
    (CC.Mem.rangePerm_congr (m1 := current) (m2 := (allocation before).2)
      (fun ofs => by simp only [CC.Mem.perm,access])).trans
        (((allocated_local_storage (Arm64MemsetSource.allocated before)).1 id value binding).2.2)
  obtain ⟨after,freed,frame,contents,next,released⟩ := deallocate_live_locals (Arm64MemsetSource.allocated before) owned
  exact ⟨after,freed,frame,contents,next,released⟩

/-- Follow the original do/while exit and break, then the genuine skip_call
with its derived eight-local freeList, reaching the actual Returnstate. -/
theorem exit (before current : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (access : current.access = (allocation before).2.access) :
    ∃ after, FreeResult before current after ∧ InternalRun world 3
      (.State handler .Sskip (Arm64MemsetSource.continuation k) (allocation before).1 le current)
      (.Returnstate .Vundef k after) := by
  obtain ⟨after,result⟩ := free before current access
  refine ⟨after,result,?_⟩
  rw [continuation_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (.skip_call _ _ _ _ _ _ hk result.freed) (.refl _)

end KProgFormal.ClightRefinement.Arm64MemsetReturn
