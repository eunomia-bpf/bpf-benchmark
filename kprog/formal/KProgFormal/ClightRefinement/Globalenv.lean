import KProgFormal.ClightRefinement.Execution

namespace KProgFormal.ClightRefinement

/-- Later global allocation cannot overwrite an earlier block. -/
theorem findDef_before_next {F V : Type} (ge : CC.Genv F V)
    (globals : List (CC.Ident × CC.GlobDef F V)) (block : CC.Block)
    (below : block.toNat < ge.genv_next.toNat) :
    CC.Genv.findDef (CC.Genv.addGlobals ge globals) block = CC.Genv.findDef ge block := by
  induction globals generalizing ge with
  | nil => rfl
  | cons entry rest ih =>
    change CC.Genv.findDef (CC.Genv.addGlobals (CC.Genv.addGlobal ge entry) rest) block = _
    rw [ih (CC.Genv.addGlobal ge entry) (by
      simp only [CC.Genv.addGlobal, CC.Positive.toNat_succ]
      omega)]
    simp only [CC.Genv.findDef, CC.Genv.addGlobal]
    apply CC.PTree.gso
    intro equal
    have same := congrArg CC.Positive.toNat equal
    omega

/-- A function occupies the next block; appending further globals preserves it. -/
theorem findFunctPtr_next (ge : CC.Genv CC.FunDef CC.Ty) (id : CC.Ident)
    (fd : CC.FunDef) (rest : List (CC.Ident × CC.GlobDef CC.FunDef CC.Ty)) :
    CC.Genv.findFunctPtr
      (CC.Genv.addGlobals (CC.Genv.addGlobal ge (id, .Gfun fd)) rest) ge.genv_next = some fd := by
  unfold CC.Genv.findFunctPtr
  rw [findDef_before_next _ rest _ (by simp [CC.Genv.addGlobal])]
  simp [CC.Genv.findDef, CC.Genv.addGlobal]

theorem addGlobals_append {F V : Type} (ge : CC.Genv F V)
    (left right : List (CC.Ident × CC.GlobDef F V)) :
    CC.Genv.addGlobals ge (left ++ right) =
      CC.Genv.addGlobals (CC.Genv.addGlobals ge left) right := by
  simp [CC.Genv.addGlobals, List.foldl_append]

theorem addGlobals_cons {F V : Type} (ge : CC.Genv F V)
    (entry : CC.Ident × CC.GlobDef F V) (rest : List (CC.Ident × CC.GlobDef F V)) :
    CC.Genv.addGlobals ge (entry :: rest) =
      CC.Genv.addGlobals (CC.Genv.addGlobal ge entry) rest := rfl

end KProgFormal.ClightRefinement
