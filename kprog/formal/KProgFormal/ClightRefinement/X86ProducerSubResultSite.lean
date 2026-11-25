import KProgFormal.ClightRefinement.X86ProducerSubOperands
import KProgFormal.ClightRefinement.X86SubtractAlu

namespace KProgFormal.ClightRefinement.X86ProducerSubResultSite
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)

def helper : CC.Function := X86_program_profile_bpf.f_x86_alu_result

def targetCall : CC.Stmt := by
  run_tac do
    let mut todo := #[← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none]
    while !todo.isEmpty do
      let item := todo.back!
      todo := todo.pop
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf item)
      if stmt.isAppOfArity ``CC.Stmt.Scall 3 then
        let expression ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
        if expression.isAppOfArity ``CC.Expr.Evar 2 &&
            expression.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_alu_result then
          Lean.Elab.Tactic.closeMainGoal `original_sub_immediate_call stmt
          return
      else if stmt.isAppOfArity ``CC.Stmt.Ssequence 2 || stmt.isAppOfArity ``CC.Stmt.Sloop 2 then
        todo := todo.push stmt.getAppArgs[1]!
        todo := todo.push stmt.getAppArgs[0]!
      else if stmt.isAppOfArity ``CC.Stmt.Sifthenelse 3 then
        todo := todo.push stmt.getAppArgs[2]!
        todo := todo.push stmt.getAppArgs[1]!
    throwError "original SUB arithmetic-result call missing"

def resultName : CC.Ident := by
  run_tac do
    let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(targetCall)) none))
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf call.getAppArgs[0]!)
    unless result.isAppOfArity ``Option.some 2 do throwError "original rhs return temporary missing"
    Lean.Elab.Tactic.closeMainGoal `original_sub_rhs_result result.getAppArgs[1]!

def argumentTypes : List CC.Ty := [CC.tulong,CC.tulong,CC.tuint,CC.tuchar]
def expression : CC.Expr := .Evar X86_program_profile_bpf._x86_alu_result
  (.Tfunction argumentTypes CC.tulong CC.cc_default)
def argumentExpressions : List CC.Expr := by
  run_tac do
    let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(targetCall)) none))
    Lean.Elab.Tactic.closeMainGoal `original_sub_rhs_arguments call.getAppArgs[2]!

theorem source_call : targetCall = .Scall (some resultName) expression argumentExpressions := by rfl

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.State :=
  .State handler .Sskip (X86ProducerSubOperands.following binding k memory lhs) (allocation memory).1
    (X86ProducerSubOperands.temps binding k memory lhs) (allocation memory).2

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory lhs)
    (.State handler targetCall continuation (allocation memory).1 output (allocation memory).2)

/-- Every original post-rhs sequence reaches its genuine arithmetic helper
call, preserving the actual source temporaries, full memory and continuation. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : Certificate binding k memory lhs := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start #[parameters[0]!,parameters[1]!,parameters[2]!,parameters[3]!]
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let memory ← Lean.Meta.mkAppM ``Prod.snd #[allocated]
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(targetCall)) none
    let built ← InternalPrefixBuilder.build world initial original target env memory
    Lean.Elab.Tactic.closeMainGoal `original_sub_rhs_prefix
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge (certificate binding k memory lhs).count (start binding k memory lhs)
      (.State handler targetCall (certificate binding k memory lhs).continuation (allocation memory).1
        (certificate binding k memory lhs).output (allocation memory).2) := (certificate binding k memory lhs).run

theorem arguments (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    CC.doEvalExprlist ge (allocation memory).1 (certificate binding k memory lhs).output (allocation memory).2
      argumentExpressions argumentTypes = some [.Vlong lhs,.Vlong (32#64),.Vint (1#32),.Vint (8#32)] := by rfl

theorem lhs_kept (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (certificate binding k memory lhs).output.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs) := by rfl

private def helperIndex : Nat := by
  run_tac do
    let mut rows ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.global_definitions)) none
    let mut index := 0
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
      unless node.isAppOfArity ``List.cons 3 do throwError "actual arithmetic helper global missing"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``Prod.mk 4 do throwError "actual arithmetic helper global row changed"
      if row.getAppArgs[2]!.isConstOf ``X86_program_profile_bpf._x86_alu_result then
        Lean.Elab.Tactic.closeMainGoal `actual_immediate_helper_index (Lean.mkNatLit index)
        return
      rows := node.getAppArgs[2]!
      index := index+1

def helperBlock : CC.Block := CC.Positive.ofNat (helperIndex+1)

theorem helper_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some helperBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv helperBlock = some (.Internal helper) := by
  constructor <;> run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "actual arithmetic helper binding equality changed"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

def continuation (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.Cont :=
  .Kcall (some resultName) handler (allocation memory).1 (certificate binding k memory lhs).output
    (certificate binding k memory lhs).continuation

theorem call (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge 1
      (.State handler targetCall (certificate binding k memory lhs).continuation (allocation memory).1
        (certificate binding k memory lhs).output (allocation memory).2)
      (.Callstate (.Internal helper) [.Vlong lhs,.Vlong (32#64),.Vint (1#32),.Vint (8#32)]
        (continuation binding k memory lhs) (allocation memory).2) := by
  have absent : (allocation memory).1.get X86_program_profile_bpf._x86_alu_result = none := rfl
  have function : CC.doEvalExpr ge (allocation memory).1 (certificate binding k memory lhs).output (allocation memory).2 expression =
      some (.Vptr helperBlock 0) := by
    simp only [expression,CC.doEvalExpr,CC.lvalOfVar,absent,helper_binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  rw [source_call]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := argumentTypes) (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr helperBlock 0)
  · rfl
  · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (arguments binding k memory lhs)
  · have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
    simpa only [CC.Genv.findFunct,zero,ite_true] using helper_binding.2
  · rfl

/-- Genuine immediate call and all20 original helper transitions retain the
allocated heap and existing lhs. The returned lhs-minus32 is derived from C. -/
theorem from_operands (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge ((certificate binding k memory lhs).count+1+20) (start binding k memory lhs)
      (.Returnstate (.Vlong (lhs-(32#64))) (CC.callCont (continuation binding k memory lhs)) (allocation memory).2) :=
  ((executes binding k memory lhs).trans (call binding k memory lhs)).trans
    (X86SubtractAlu.internal ge lhs (32#64) (8#8) (continuation binding k memory lhs) (allocation memory).2)

end KProgFormal.ClightRefinement.X86ProducerSubResultSite
