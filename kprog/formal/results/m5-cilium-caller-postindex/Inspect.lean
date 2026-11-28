import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTail
set_option Elab.async false
open Lean Meta Elab Term in
run_elab do
  let rec shape (x : Expr) (depth : Nat) : MetaM String := do
    let v ← withTransparency .all (whnf x)
    let name := v.getAppFn.constName?.getD .anonymous
    if depth == 0 then return toString name
    let mut result := toString name
    for a in v.getAppArgs do
      let ty ← whnf (← inferType a)
      if ty.isConstOf ``CC.Stmt then
        result := result ++ " (" ++ (← shape a (depth-1)) ++ ")"
      else if ty.isConstOf ``CC.Ident then
        result := result ++ " id=" ++ toString (← ppExpr a)
    return result
  let term ← elabTerm (← `(KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPrefix.rest)) none
  logInfo (← shape term 4)
open Lean Meta Elab Term in
run_elab do
  let term ← elabTerm (← `(KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPrefix.rest)) none
  let v ← withTransparency .all (whnf term)
  let body ← withTransparency .all (whnf v.getAppArgs[0]!)
  logInfo (← ppExpr body)
  for a in body.getAppArgs do
    logInfo (← ppExpr (← withTransparency .all (whnf a)))
