import KProgFormal.ClightRefinement.Arm64MemcpyByteGates

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLaneGates

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Gate where
  tail : CC.Stmt
  selector : CC.Stmt
  test : CC.Expr
  other : CC.Stmt
  key : CC.Ident
  active : CC.Expr
  body : CC.Stmt
private def actual : List Gate := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy remaining byte gates changed"
      pure actual.getAppArgs
    let mut rest ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyByteGates.afterByte)) none
    let mut rows := #[]
    for n in [:7] do
      let tail := rest
      let unit ← if n < 6 then do
        let pair ← peel rest ``CC.Stmt.Ssequence 2
        rest := pair[1]!
        pure pair[0]!
      else pure rest
      let unit ← peel unit ``CC.Stmt.Ssequence 2
      let select ← peel unit[0]! ``CC.Stmt.Sifthenelse 3
      let selected ← peel select[1]! ``CC.Stmt.Sset 2
      let active ← peel unit[1]! ``CC.Stmt.Sifthenelse 3
      rows := rows.push (← Lean.Meta.mkAppM ``Gate.mk
        #[tail,unit[0]!,select[0]!,select[2]!,selected[0]!,active[0]!,active[1]!])
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_remaining_byte_gates
      (← Lean.Meta.mkListLit (Lean.mkConst ``Gate) rows.toList)
private def gate (i : Fin 7) : Gate := actual[i.val]'(by change i.val<7; exact i.isLt)
private def tail (i : Fin 7) : CC.Stmt := (gate i).tail
private def key (i : Fin 7) : CC.Ident := (gate i).key
private def test : CC.Expr := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `((gate 0).test)) none
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_remaining_byte_test
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def one : CC.Expr := .Ecast (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tuint
private def unit (i : Fin 7) : CC.Stmt := .Ssequence (gate i).selector
  (.Sifthenelse (gate i).active (gate i).body .Sskip)
private theorem cases7 : ∀ i : Fin 7, i=0 ∨ i=1 ∨ i=2 ∨ i=3 ∨ i=4 ∨ i=5 ∨ i=6 := by decide +kernel
private theorem cases6 : ∀ i : Fin 6, i=0 ∨ i=1 ∨ i=2 ∨ i=3 ∨ i=4 ∨ i=5 := by decide +kernel
private theorem selector_source : ∀ i : Fin 7,
    (gate i).selector = .Sifthenelse test (.Sset (key i) one) (gate i).other := by
  intro i
  rcases cases7 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl
private theorem active_source : ∀ i : Fin 7,
    (gate i).active = .Ecast
      (.Ebinop .Oand (.Ebinop .Oshr (.Etempvar (key i) CC.tuint)
        (.Econst_int (CC.Integers.Int.repr (i.val+1)) CC.tint) CC.tuint)
        (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tuint) CC.tuchar := by
  intro i
  rcases cases7 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl
private theorem keys : ∀ i : Fin 7, key i ≠ Arm64Program.___a64_stw_width := by decide +kernel
private theorem tails : ∀ i : Fin 6, tail i.castSucc = .Ssequence (unit i.castSucc) (tail i.succ) := by
  intro i
  rcases cases6 i with rfl | rfl | rfl | rfl | rfl | rfl <;> rfl
private theorem final_source : tail 6 = unit 6 := rfl
theorem source : Arm64MemcpyByteGates.afterByte = tail 0 := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (((((((le.set Arm64Program._t'41 (.Vint 1)).set Arm64Program._t'42 (.Vint 1)).set
    Arm64Program._t'43 (.Vint 1)).set Arm64Program._t'44 (.Vint 1)).set
    Arm64Program._t'45 (.Vint 1)).set Arm64Program._t'46 (.Vint 1)).set Arm64Program._t'47 (.Vint 1))

private theorem test_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1)) :
    CC.doEvalExpr world e le m test = some (.Vint 1) := by
  simp only [test,CC.doEvalExpr,hwidth,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuchar,CC.tuint,CC.tint,
    CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.MI.repr]
  rfl
private theorem active_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 7) :
    CC.doEvalExpr world e (le.set (key i) (.Vint 1)) m (gate i).active = some (.Vint 0) := by
  rw [active_source]
  have shift : ∀ j : Fin 7, CC.Integers.Int.shru 1 (CC.Integers.Int.repr (j.val+1)) = 0 := by decide +kernel
  have bound : ∀ j : Fin 7, CC.Integers.Int.ltu (CC.Integers.Int.repr (j.val+1)) 32 = true := by decide +kernel
  simp +decide only [CC.doEvalExpr,CC.PTree.gss,CC.Cop.semBinaryOperation,CC.Cop.semShr,CC.Cop.semShift,
    CC.Cop.classifyShift,CC.Cop.semAnd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tattr,CC.tuint,CC.tint,CC.tuchar,CC.Archi.ptr64,CC.Integers.Int.iwordsize,
    CC.Integers.MI.iwordsize,CC.Integers.MI.repr,bound,shift,ite_true,ite_false]
  rcases cases7 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

private theorem execute_one (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 7)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1)) :
    InternalRun world 5 (.State handler (unit i) k e le m)
      (.State handler .Sskip k e (le.set (key i) (.Vint 1)) m) := by
  unfold unit
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [selector_source]
  refine .step (mid := .State handler (.Sset (key i) one)
    (.Kseq (.Sifthenelse (gate i).active (gate i).body .Sskip) k) e le m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · have testType : CC.typeof test = CC.tint := rfl
    simp only [CC.doStep,test_eval e le m hwidth,testType]
    rfl
  refine .step (mid := .State handler .Sskip
    (.Kseq (.Sifthenelse (gate i).active (gate i).body .Sskip) k) e (le.set (key i) (.Vint 1)) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,one,CC.doEvalExpr,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.tuint,CC.typeconv,CC.removeAttributes,CC.tattr]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  have activeType : CC.typeof (gate i).active = CC.tuchar := by rw [active_source]; rfl
  simp only [CC.doStep,active_eval e le m i,activeType]
  rfl
private theorem next (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 6)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1)) :
    InternalRun world 7 (.State handler (tail i.castSucc) k e le m)
      (.State handler (tail i.succ) k e (le.set (key i.castSucc) (.Vint 1)) m) := by
  rw [tails]
  have enter : InternalRun world 1 (.State handler (.Ssequence (unit i.castSucc) (tail i.succ)) k e le m)
      (.State handler (unit i.castSucc) (.Kseq (tail i.succ) k) e le m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have leave : InternalRun world 1
      (.State handler .Sskip (.Kseq (tail i.succ) k) e (le.set (key i.castSucc) (.Vint 1)) m)
      (.State handler (tail i.succ) k e (le.set (key i.castSucc) (.Vint 1)) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (enter.trans (execute_one e le m (.Kseq (tail i.succ) k) i.castSucc hwidth)).trans leave

/-- Seven original selectors and false active-byte gates execute in their
real order, retaining all original wider byte-writing branches. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1)) :
    InternalRun world 47 (.State handler Arm64MemcpyByteGates.afterByte k e le m)
      (.State handler .Sskip k e (temps le) m) := by
  have carry (env : CC.TempEnv) (i : Fin 7) (old : env.get Arm64Program.___a64_stw_width = some (.Vint 1)) :
      (env.set (key i) (.Vint 1)).get Arm64Program.___a64_stw_width = some (.Vint 1) := by
    rw [CC.PTree.gso _ _ _ _ (keys i),old]
  let l1:=le.set (key 0) (.Vint 1)
  let l2:=l1.set (key 1) (.Vint 1)
  let l3:=l2.set (key 2) (.Vint 1)
  let l4:=l3.set (key 3) (.Vint 1)
  let l5:=l4.set (key 4) (.Vint 1)
  let l6:=l5.set (key 5) (.Vint 1)
  have h1:=carry le 0 hwidth
  have h2:=carry l1 1 h1
  have h3:=carry l2 2 h2
  have h4:=carry l3 3 h3
  have h5:=carry l4 4 h4
  have h6:=carry l5 5 h5
  have final:=execute_one e l6 m k 6 h6
  rw [←final_source] at final
  rw [source]
  exact ((((((next e le m k 0 hwidth).trans (next e l1 m k 1 h1)).trans
    (next e l2 m k 2 h2)).trans (next e l3 m k 3 h3)).trans
    (next e l4 m k 4 h4)).trans (next e l5 m k 5 h5)).trans final

end KProgFormal.ClightRefinement.Arm64MemcpyLaneGates
