import KProgFormal.ClightRefinement.X86RegisterWriteRspRelease

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseLoop

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_release_loop_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Parts where
  initial : CC.Stmt
  body : CC.Stmt
  advance : CC.Stmt
  frame : CC.Stmt

private def parts : Parts :=
  match X86RegisterWriteRspRelease.increasing with
  | .Ssequence (.Ssequence initial (.Sloop body advance)) frame =>
      ⟨initial, body, advance, frame⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip⟩

private def initial : CC.Stmt := by run_tac cachePart (← `(parts.initial))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def advance : CC.Stmt := by run_tac cachePart (← `(parts.advance))
private def frame : CC.Stmt := by run_tac cachePart (← `(parts.frame))
private def guard : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence guard _ => guard | _ => .Sskip))
private def offset : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence offset _) => offset | _ => .Sskip))
def iteration : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence _ iteration) => iteration | _ => .Sskip))

/-- The original loop, all word/byte arms and frame-value call are retained. -/
theorem source : X86RegisterWriteRspRelease.increasing =
    .Ssequence (.Ssequence initial (.Sloop body advance)) frame := rfl

private theorem body_source : body = .Ssequence guard (.Ssequence offset iteration) := rfl

def loopContinuation (k : CC.Cont) : CC.Cont := .Kloop1 body advance (.Kseq frame k)

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf.___x86_release_i__5 (.Vint (0#32))).set
    X86_program_profile_bpf.___x86_release_off__5 (.Vlong (0#64 - 48#64))

/-- Actual initialization, unsigned0<48 guard and signed offset calculation
reach the first unchanged word/byte release decision in11 source transitions.
No memory operation, provider call or final loop result is assumed. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 11
      (.State function X86RegisterWriteRspRelease.increasing k e le memory)
      (.State function iteration (loopContinuation k) e (temps le) memory) := by
  rw [source]
  apply internalRun_of_steps
  all_goals simp +decide only [steps, InternalPath, InternalState, initial, body_source,
    guard, offset, temps, loopContinuation, CC.doStep, CC.doEvalExpr, CC.typeof,
    CC.PTree.gss, CC.PTree.gso, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
    CC.Cop.classifyCmp, CC.Cop.semSub, CC.Cop.classifySub, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv,
    CC.removeAttributes, CC.tattr, CC.tint, CC.tuint, CC.tlong,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.ltu, CC.Integers.MI.ltu,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.sub, CC.Integers.MI.sub, CC.Integers.Int.unsigned,
    CC.Integers.MI.unsigned, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0,
    List.nil_append, true_and, ite_true]
  all_goals rfl

/-- From the exact original table-write frontier, genuine raw-SP reads and
positive signed comparison compose with the real first-loop entry. The
48-byte export's first decision retains both actual release routes and the
following frame-value call; loop completion remains a separate obligation. -/
theorem from_table (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs)
    (old next : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (newSp : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some (.Vlong next))
    (increasingOffset : CC.Integers.Int64.cmp .Cgt next old = true) :
    InternalRun ge 29
      (.State function .Sskip (X86ShiftWriteback.tableCont k) e le memory)
      (.State function iteration (loopContinuation (X86RegisterWriteRspRelease.releaseContinuation k)) e
        (temps (X86RegisterWriteRspRelease.temps le cellsBlock cellsOffset old next)) memory) := by
  exact (X86RegisterWriteRspRelease.increasing_enter ge layout function e le k memory
    bindingBlock cellsBlock cellsOffset old next binding destination oldSp cells newSp increasingOffset).trans
    (enter ge function e (X86RegisterWriteRspRelease.temps le cellsBlock cellsOffset old next)
      (X86RegisterWriteRspRelease.releaseContinuation k) memory)

end KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseLoop
