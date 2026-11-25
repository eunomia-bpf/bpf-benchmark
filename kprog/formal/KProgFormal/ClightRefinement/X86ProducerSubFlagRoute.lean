import KProgFormal.ClightRefinement.X86ProducerSubCfPrefix

namespace KProgFormal.ClightRefinement.X86ProducerSubFlagRoute
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) : CC.State :=
  .State handler .Sskip (X86ProducerSubOldCf.following binding k memory lhs) (allocation memory).1
    (X86ProducerSubOldCf.temps binding k memory lhs cfBlock (X86ProducerScalarValue.value 0 word)) (allocation memory).2

/-- Locate the next genuine source call using EXISTING Clight doStep. The
certificate below independently checks the generic actual path in the kernel;
this extraction adds no interpreter or trusted numerical semantics. -/
def widthCall : CC.Stmt := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(start CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64))) none
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    while true do
      let state ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless state.isAppOfArity ``CC.State.State 6 do throwError "original flag selector left statement state"
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
      if stmt.isAppOfArity ``CC.Stmt.Scall 3 then
        let callee ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
        unless callee.isAppOfArity ``CC.Expr.Evar 2 && callee.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_width_effective do
          throwError "actual SUB flag selector reached another call"
        Lean.Elab.Tactic.closeMainGoal `actual_sub_flag_width_call stmt
        return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let next ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless next.isAppOfArity ``Option.some 2 do throwError "original flag selector has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf next.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

def resultName : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(widthCall)) none))
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[0]!)
    unless result.isAppOfArity ``Option.some 2 do throwError "actual SUB width result missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_flag_width_result result.getAppArgs[1]!

def expression : CC.Expr := .Evar X86_program_profile_bpf._x86_width_effective
  (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default)
def argumentExpressions : List CC.Expr := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(widthCall)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_sub_flag_width_arguments stmt.getAppArgs[2]!

theorem source_call : widthCall = .Scall (some resultName) expression argumentExpressions := by rfl

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory lhs cfBlock word)
    (.State handler widthCall continuation (allocation memory).1 output (allocation memory).2)

/-- Original conditional flag-arm ladder, switch and selected SUB loop
execute to their actual width call with all source state retained. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) : Certificate binding k memory lhs cfBlock word := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start parameters
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let memory ← Lean.Meta.mkAppM ``Prod.snd #[allocated]
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(widthCall)) none
    let built ← InternalPrefixBuilder.build world initial original target env memory
    Lean.Elab.Tactic.closeMainGoal `actual_sub_flag_route
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    InternalRun ge (certificate binding k memory lhs cfBlock word).count (start binding k memory lhs cfBlock word)
      (.State handler widthCall (certificate binding k memory lhs cfBlock word).continuation (allocation memory).1
        (certificate binding k memory lhs cfBlock word).output (allocation memory).2) :=
  (certificate binding k memory lhs cfBlock word).run

theorem arguments (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    CC.doEvalExprlist ge (allocation memory).1 (certificate binding k memory lhs cfBlock word).output (allocation memory).2
      argumentExpressions [CC.tuchar] = some [.Vint (8#32)] := by rfl

end KProgFormal.ClightRefinement.X86ProducerSubFlagRoute
