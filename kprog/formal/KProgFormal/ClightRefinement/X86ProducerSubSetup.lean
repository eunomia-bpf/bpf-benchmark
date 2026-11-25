import KProgFormal.ClightRefinement.X86ProducerSubBody
import KProgFormal.ClightRefinement.InternalPrefixBuilder
import KProgFormal.ClightRefinement.X86ProducerPushWidth
import KProgFormal.ClightRefinement.X86ProducerSubTemporaries

namespace KProgFormal.ClightRefinement.X86ProducerSubSetup
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation initialTemps)

private def findCall (callee : Lean.Name) : Lean.Elab.Tactic.TacticM Unit := do
  let mut todo := #[← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none]
  while !todo.isEmpty do
    let item := todo.back!
    todo := todo.pop
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf item)
    if stmt.isAppOfArity ``CC.Stmt.Scall 3 then
      let expression ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
      if expression.isAppOfArity ``CC.Expr.Evar 2 && expression.getAppArgs[0]!.isConstOf callee then
        Lean.Elab.Tactic.closeMainGoal `actual_sub_call_site stmt
        return
    else if stmt.isAppOfArity ``CC.Stmt.Ssequence 2 || stmt.isAppOfArity ``CC.Stmt.Sloop 2 then
      todo := todo.push stmt.getAppArgs[1]!
      todo := todo.push stmt.getAppArgs[0]!
    else if stmt.isAppOfArity ``CC.Stmt.Sifthenelse 3 then
      todo := todo.push stmt.getAppArgs[2]!
      todo := todo.push stmt.getAppArgs[1]!
  throwError "actual ALU_IMM call site missing"

def widthCall : CC.Stmt := by run_tac findCall ``X86_program_profile_bpf._x86_width_effective
def readCall : CC.Stmt := by run_tac findCall ``X86_program_profile_bpf._x86_sim_inline_read_reg

def widthResult : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(widthCall)) none))
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[0]!)
    unless result.isAppOfArity ``Option.some 2 do throwError "actual width return temporary missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_width_result result.getAppArgs[1]!

def widthExpression : CC.Expr := .Evar X86_program_profile_bpf._x86_width_effective
  (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default)
def widthArguments : List CC.Expr := [.Etempvar X86_program_profile_bpf._flags CC.tuchar]

theorem width_source : widthCall = .Scall (some widthResult) widthExpression widthArguments := by rfl

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler handler.fn_body k (allocation memory).1 (initialTemps binding) (allocation memory).2

def cachedStart (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler handler.fn_body k (allocation memory).1 (X86ProducerSubTemporaries.cached binding) (allocation memory).2

theorem exact_start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    start binding k memory = cachedStart binding k memory := by
  unfold start cachedStart
  rw [X86ProducerSubTemporaries.exact_initial]

theorem original_run {binding : CC.Block} {k : CC.Cont} {memory : CC.Mem} {count : Nat} {last : CC.State}
    (run : InternalRun ge count (cachedStart binding k memory) last) : InternalRun ge count (start binding k memory) last := by
  rw [exact_start]
  exact run

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory)
    (.State handler widthCall continuation (allocation memory).1 output (allocation memory).2)

/-- Original ALU_IMM outer/inner loops and width setup execute to the first
real effective-width call. Every original statement and memory is retained. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : Certificate binding k memory := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``cachedStart #[parameters[0]!,parameters[1]!,parameters[2]!]
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let memory ← Lean.Meta.mkAppM ``Prod.snd #[allocated]
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(widthCall)) none
    let built ← InternalPrefixBuilder.build world initial original target env memory
    let proof ← Lean.Meta.mkAppM ``original_run #[built.proof]
    Lean.Elab.Tactic.closeMainGoal `actual_sub_width_prefix
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge (certificate binding k memory).count (start binding k memory)
      (.State handler widthCall (certificate binding k memory).continuation (allocation memory).1
        (certificate binding k memory).output (allocation memory).2) := (certificate binding k memory).run

theorem arguments (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    CC.doEvalExprlist ge (allocation memory).1 (certificate binding k memory).output (allocation memory).2
      widthArguments [CC.tuchar] = some [.Vint (8#32)] := by rfl

def continuation (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.Cont :=
  .Kcall (some widthResult) handler (allocation memory).1 (certificate binding k memory).output
    (certificate binding k memory).continuation

def temps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.TempEnv :=
  (certificate binding k memory).output.set widthResult (.Vint (8#32))

/-- Actual call target, complete width helper and true caller return retain
the current allocated heap and update only the real return temporary. -/
theorem invoke (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 8
      (.State handler widthCall (certificate binding k memory).continuation (allocation memory).1
        (certificate binding k memory).output (allocation memory).2)
      (.State handler .Sskip (certificate binding k memory).continuation (allocation memory).1
        (temps binding k memory) (allocation memory).2) := by
  have absent : (allocation memory).1.get X86_program_profile_bpf._x86_width_effective = none := rfl
  have function : CC.doEvalExpr ge (allocation memory).1 (certificate binding k memory).output (allocation memory).2 widthExpression =
      some (.Vptr X86ProducerPushWidth.widthBlock 0) := by
    simp only [widthExpression,CC.doEvalExpr,CC.lvalOfVar,absent,X86ProducerPushWidth.width_binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  have called : InternalRun ge 1
      (.State handler widthCall (certificate binding k memory).continuation (allocation memory).1
        (certificate binding k memory).output (allocation memory).2)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (continuation binding k memory) (allocation memory).2) := by
    rw [width_source]
    refine .step trivial ?_ (.refl _)
    apply CC.Step.call (tyargs := [CC.tuchar]) (tyres := CC.tuchar) (cconv := CC.cc_default)
      (vf := .Vptr X86ProducerPushWidth.widthBlock 0)
    · rfl
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (arguments binding k memory)
    · have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
      simpa only [CC.Genv.findFunct,zero,ite_true] using X86ProducerPushWidth.width_binding.2
    · rfl
  have helper : InternalRun ge 6
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (continuation binding k memory) (allocation memory).2)
      (.Returnstate (.Vint (8#32)) (continuation binding k memory) (allocation memory).2) :=
    X86Width.internal ge (8#8) (continuation binding k memory) (allocation memory).2
  have returned : InternalRun ge 1
      (.Returnstate (.Vint (8#32)) (continuation binding k memory) (allocation memory).2)
      (.State handler .Sskip (certificate binding k memory).continuation (allocation memory).1
        (temps binding k memory) (allocation memory).2) :=
    .step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (called.trans helper).trans returned

end KProgFormal.ClightRefinement.X86ProducerSubSetup
