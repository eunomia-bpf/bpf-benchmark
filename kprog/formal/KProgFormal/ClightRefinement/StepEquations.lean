import KProgFormal.ClightRefinement.Execution

namespace KProgFormal.ClightRefinement

/-- Constructor-specific definitional equations keep an unknown intermediate
state opaque instead of expanding every interpreter branch. -/
theorem step_seq (ge : CC.CGenv) (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Ssequence s1 s2) k e le m) =
      some (CC.E0, .State f s1 (.Kseq s2 k) e le m) := rfl

theorem step_loop (ge : CC.CGenv) (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sloop s1 s2) k e le m) =
      some (CC.E0, .State f s1 (.Kloop1 s1 s2 k) e le m) := rfl

theorem step_skip_seq (ge : CC.CGenv) (f : CC.Function) (s : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f .Sskip (.Kseq s k) e le m) =
      some (CC.E0, .State f s k e le m) := rfl

theorem step_skip_loop (ge : CC.CGenv) (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f .Sskip (.Kloop1 s1 s2 k) e le m) =
      some (CC.E0, .State f s2 (.Kloop2 s1 s2 k) e le m) := rfl

theorem step_break_loop (ge : CC.CGenv) (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f .Sbreak (.Kloop2 s1 s2 k) e le m) =
      some (CC.E0, .State f .Sskip k e le m) := rfl

theorem step_set (ge : CC.CGenv) (f : CC.Function) (id : CC.Ident) (a : CC.Expr) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sset id a) k e le m) =
      (CC.doEvalExpr ge e le m a).map (fun v =>
        (CC.E0, .State f .Sskip k e (le.set id v) m)) := by
  cases he : CC.doEvalExpr ge e le m a <;> simp [CC.doStep, he]

theorem step_if (ge : CC.CGenv) (f : CC.Function) (a : CC.Expr) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sifthenelse a s1 s2) k e le m) =
      (CC.doEvalExpr ge e le m a).bind (fun v =>
        (CC.Cop.boolVal v (CC.typeof a) m).map (fun cond =>
          (CC.E0, .State f (if cond then s1 else s2) k e le m))) := by
  cases he : CC.doEvalExpr ge e le m a with
  | none => simp [CC.doStep, he]
  | some v =>
    cases hb : CC.Cop.boolVal v (CC.typeof a) m <;> simp [CC.doStep, he, hb]

theorem step_return (ge : CC.CGenv) (f : CC.Function) (a : CC.Expr) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sreturn (some a)) k e le m) =
      (CC.doEvalExpr ge e le m a).bind (fun v =>
        (CC.Cop.semCast v (CC.typeof a) f.fn_return m).bind (fun result =>
          (CC.Mem.freeList m (CC.blocksOfEnv ge.genv_cenv e)).map (fun after =>
            (CC.E0, .Returnstate result (CC.callCont k) after)))) := by
  cases he : CC.doEvalExpr ge e le m a with
  | none => simp [CC.doStep, he]
  | some v =>
    cases hc : CC.Cop.semCast v (CC.typeof a) f.fn_return m with
    | none => simp [CC.doStep, he, hc]
    | some value =>
      cases hf : CC.Mem.freeList m (CC.blocksOfEnv ge.genv_cenv e) <;>
        simp [CC.doStep, he, hc, hf]


end KProgFormal.ClightRefinement
