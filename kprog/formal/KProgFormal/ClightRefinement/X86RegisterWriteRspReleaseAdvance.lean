import KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseByteCall

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseAdvance

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_release_advance_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Parts where
  body : CC.Stmt
  increment : CC.Stmt
  frame : CC.Stmt
private def parts : Parts :=
  match X86RegisterWriteRspRelease.increasing with
  | .Ssequence (.Ssequence _ (.Sloop body increment)) frame => ⟨body, increment, frame⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip⟩

def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))
def frameCall : CC.Stmt := by run_tac cachePart (← `(parts.frame))
private def guard : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence guard _ => guard | _ => .Sskip))
private def offset : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence offset _) => offset | _ => .Sskip))

/-- Both backedges and final frame call are the original source continuation. -/
theorem source (k : CC.Cont) :
    X86RegisterWriteRspReleaseLoop.loopContinuation k = .Kloop1 body increment (.Kseq frameCall k) ∧
    body = .Ssequence guard (.Ssequence offset X86RegisterWriteRspReleaseLoop.iteration) := ⟨rfl, rfl⟩

def temps (le : CC.TempEnv) (slot : Fin 6) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___x86_release_off__5 (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot))

private theorem increased : ∀ slot : Fin 6,
    CC.Integers.Int.add (X86RegisterWriteRspReleaseSelect.index slot) (CC.Integers.Int.repr 8) =
      BitVec.ofNat 32 (8 * (slot.val + 1)) := by decide +kernel
private theorem fits : ∀ slot : Fin 6,
    CC.Integers.Int.cmpu .Clt (X86RegisterWriteRspReleaseSelect.index slot) (CC.Integers.Int.repr 48) = true := by
  decide +kernel
private theorem offset_cast : ∀ slot : Fin 6,
    CC.Integers.Int64.repr (CC.Integers.Int.unsigned (X86RegisterWriteRspReleaseSelect.index slot)) =
      (X86RegisterWriteRspReleaseSelect.index slot).setWidth 64 := by decide +kernel

/-- The real outer-loop backedge advances every slot, including40 to48. -/
theorem advance (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6)
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot))) :
    InternalRun ge 4
      (.State function .Sskip (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory)
      (.State function body (X86RegisterWriteRspReleaseLoop.loopContinuation k) e
        (le.set X86_program_profile_bpf.___x86_release_i__5 (.Vint (BitVec.ofNat 32 (8 * (slot.val + 1))))) memory) := by
  have add := increased slot
  dsimp only [CC.Integers.Int.add, CC.Integers.MI.add] at add
  rw [(source k).1]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, increment,
    CC.doStep, CC.doEvalExpr, CC.typeof, observedIndex, add,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint, CC.tuint,
    CC.Integers.Int.add, CC.Integers.MI.add, CC.E0, CC.Eapp]
  all_goals rfl

/-- The original unsigned guard and signed offset assignment prepare each
next word/byte decision without changing its heap or other temporaries. -/
theorem prepare (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6)
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot))) :
    InternalRun ge 6
      (.State function body (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory)
      (.State function X86RegisterWriteRspReleaseLoop.iteration
        (X86RegisterWriteRspReleaseLoop.loopContinuation k) e (temps le slot) memory) := by
  have fit := fits slot
  dsimp only [CC.Integers.Int.cmpu, CC.Integers.Int.repr, CC.Integers.MI.repr] at fit
  have cast := offset_cast slot
  rw [(source k).2]
  apply internalRun_of_steps
  all_goals simp +decide only [steps, InternalPath, InternalState, guard, offset, temps,
    CC.doStep, CC.doEvalExpr, CC.typeof, observedIndex, fit, cast, X86RegisterWriteRspReleaseSelect.offset,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semSub, CC.Cop.classifySub,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.tint, CC.tuint, CC.tlong, CC.Integers.Int.cmpu, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.sub, CC.Integers.MI.sub,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
    CC.Integers.Int.one, CC.Integers.MI.one, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.E0, CC.Eapp, List.nil_append, true_and, ite_true, ite_false]
  all_goals rfl

/-- Successive real slot executions are connected by the original10-step
increment/guard/offset source path, with the same whole-word/byte body. -/
theorem next_iteration (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 5)
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot.castSucc))) :
    InternalRun ge 10
      (.State function .Sskip (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory)
      (.State function X86RegisterWriteRspReleaseLoop.iteration
        (X86RegisterWriteRspReleaseLoop.loopContinuation k) e
        (temps (le.set X86_program_profile_bpf.___x86_release_i__5
          (.Vint (X86RegisterWriteRspReleaseSelect.index slot.succ))) slot.succ) memory) := by
  let ready := le.set X86_program_profile_bpf.___x86_release_i__5
    (.Vint (X86RegisterWriteRspReleaseSelect.index slot.succ))
  have observed : ready.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot.succ)) := CC.PTree.gss _ _ _
  exact (advance ge function e le k memory slot.castSucc observedIndex).trans
    (prepare ge function e ready k memory slot.succ observed)

/-- Actual index48 takes the original false guard, breaks out of the release
loop and reaches the existing frame-value clobber call. That call is retained. -/
theorem exit (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem)
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 = some (.Vint (48#32))) :
    InternalRun ge 5
      (.State function body (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory)
      (.State function frameCall k e le memory) := by
  rw [(source k).1, (source k).2]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, guard,
    CC.doStep, CC.doEvalExpr, CC.typeof, observedIndex,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.tint, CC.tuint, CC.E0, CC.Eapp]

/-- The endpoint is exactly the existing frame-value helper call, not skip. -/
theorem frame_source : frameCall = .Scall none
    (.Evar X86_program_profile_bpf._x86_sim_inline_call_frame_values
      (.Tfunction [CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)]
        CC.tvoid CC.cc_default))
    [.Etempvar X86_program_profile_bpf.___x86_bind
      (CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr))] := rfl

/-- The final original slot increment and false loop guard reach the real
frame-value helper call in9 transitions, retaining its full body and heap. -/
theorem after_last (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem)
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index (5 : Fin 6)))) :
    InternalRun ge 9
      (.State function .Sskip (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory)
      (.State function frameCall k e
        (le.set X86_program_profile_bpf.___x86_release_i__5 (.Vint (48#32))) memory) := by
  let ready := le.set X86_program_profile_bpf.___x86_release_i__5 (.Vint (48#32))
  have observed : ready.get X86_program_profile_bpf.___x86_release_i__5 = some (.Vint (48#32)) := CC.PTree.gss _ _ _
  exact (advance ge function e le k memory (5 : Fin 6) observedIndex).trans
    (exit ge function e ready k memory observed)

end KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseAdvance
