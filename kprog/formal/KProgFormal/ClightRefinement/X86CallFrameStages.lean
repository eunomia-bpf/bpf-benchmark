import KProgFormal.ClightRefinement.X86CallFrameEntry

namespace KProgFormal.ClightRefinement.X86CallFrameStages

private structure Part where
  test : CC.Expr
  clear : CC.Stmt
private def parts : List Part := by
  run_tac do
    let norm (e : Lean.Expr) := Lean.Meta.withTransparency .all (Lean.Meta.whnf e)
    let mut rest ← Lean.Elab.Term.elabTerm (← `(X86CallFrameEntry.afterSp)) none
    let mut rows : Array Lean.Expr := #[]
    for i in [0:6] do
      let node ← norm rest
      let loop ← if i < 5 then do
        unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "expected original frame sequence"
        rest := node.getAppArgs[1]!
        pure node.getAppArgs[0]!
      else pure node
      let loop ← norm loop
      unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "expected original frame slot loop"
      let branch ← norm loop.getAppArgs[0]!
      unless branch.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "expected original frame slot guard"
      rows := rows.push (← Lean.Meta.mkAppM ``Part.mk #[branch.getAppArgs[0]!, branch.getAppArgs[1]!])
    Lean.Elab.Tactic.closeMainGoal `original_frame_stages (← Lean.Meta.mkListLit (Lean.mkConst ``Part) rows.toList)
private theorem six : parts.length = 6 := rfl
private def part (slot : Fin 6) : Part := parts[slot.val]'(by rw [six]; exact slot.isLt)

def clear (slot : Fin 6) : CC.Stmt := (part slot).clear
private def branch (slot : Fin 6) : CC.Stmt := .Sifthenelse (part slot).test (clear slot) .Sskip
def stage (slot : Fin 6) : CC.Stmt := .Sloop (branch slot) .Sbreak

def continuation (slot : Fin 6) (k : CC.Cont) : CC.Cont := .Kloop1 (branch slot) .Sbreak k

def selected (slot : Fin 6) (sp : BitVec 64) : Bool :=
  CC.Integers.Int64.cmp .Clt (X86RegisterWriteRspReleaseSelect.offset slot) sp

def arm (slot : Fin 6) (sp : BitVec 64) : CC.Stmt := if selected slot sp then clear slot else .Sskip

/-- The six original guarded slot loops, in exactly their exported order. -/
theorem source : X86CallFrameEntry.afterSp =
    .Ssequence (stage 0) (.Ssequence (stage 1) (.Ssequence (stage 2)
      (.Ssequence (stage 3) (.Ssequence (stage 4) (stage 5))))) := rfl

private theorem cases6 : ∀ i : Fin 6, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 := by decide +kernel

private def exposeTest : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← goal.getType
  let lhs := target.getAppArgs[1]!
  unless lhs.getAppFn.isConstOf ``CC.doEvalExpr && lhs.getAppArgs.size == 5 do
    throwError "expected original guard evaluation"
  let test ← Lean.Meta.withTransparency .all (Lean.Meta.whnf lhs.getAppArgs[4]!)
  let lhs := Lean.mkAppN lhs.getAppFn (lhs.getAppArgs.set! 4 test)
  let replacement ← goal.change (← Lean.Meta.mkEq lhs target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal [replacement]

private theorem test_type (slot : Fin 6) : CC.typeof (part slot).test = CC.tint := by
  rcases cases6 slot with rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

private theorem evaluated (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (slot : Fin 6) (sp : BitVec 64)
    (observedSp : le.get X86_program_profile_bpf.___x86_sv_sp = some (.Vlong sp)) :
    CC.doEvalExpr ge e le memory (part slot).test = some (CC.Val.ofBool (selected slot sp)) := by
  rcases cases6 slot with rfl | rfl | rfl | rfl | rfl | rfl
  all_goals run_tac exposeTest
  all_goals simp +decide [CC.doEvalExpr, CC.typeof, observedSp, selected,
    X86RegisterWriteRspReleaseSelect.offset, X86RegisterWriteRspReleaseSelect.index,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semMul, CC.Cop.semSub, CC.Cop.classifySub,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.sub, CC.Integers.MI.sub, CC.Integers.Int64.mul, CC.Integers.MI.mul,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse]
  all_goals rfl

/-- Each real guard handles arbitrary signed raw SP and selects the original
metadata-clearing or skip arm in2 transitions, with identical heap and temps. -/
theorem choose (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6) (sp : BitVec 64)
    (observedSp : le.get X86_program_profile_bpf.___x86_sv_sp = some (.Vlong sp)) :
    InternalRun ge 2 (.State function (stage slot) k e le memory)
      (.State function (arm slot sp) (continuation slot k) e le memory) := by
  have testValue := evaluated ge e le memory slot sp observedSp
  cases decision : selected slot sp <;> apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, stage, branch, arm, continuation,
    CC.doStep, testValue, test_type, decision, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.E0, CC.Eapp]

/-- The original slot-loop backedge/break completes the slot after either arm. -/
theorem finish (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6) :
    InternalRun ge 2 (.State function .Sskip (continuation slot k) e le memory)
      (.State function .Sskip k e le memory) := by
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, continuation, CC.doStep, CC.E0, CC.Eapp]

/-- A false slot condition performs no clearing and completes in4 real steps. -/
theorem skipped (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6) (sp : BitVec 64)
    (observedSp : le.get X86_program_profile_bpf.___x86_sv_sp = some (.Vlong sp))
    (decision : selected slot sp = false) :
    InternalRun ge 4 (.State function (stage slot) k e le memory)
      (.State function .Sskip k e le memory) := by
  have chosen := choose ge function e le k memory slot sp observedSp
  simp only [arm, decision, ite_false] at chosen
  exact chosen.trans (finish ge function e le k memory slot)

end KProgFormal.ClightRefinement.X86CallFrameStages
