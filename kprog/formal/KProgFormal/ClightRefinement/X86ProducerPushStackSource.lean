import KProgFormal.ClightRefinement.X86ProducerPushRspPrefix

namespace KProgFormal.ClightRefinement.X86ProducerPushStackSource

private structure Parts where
  body : CC.Stmt
  prepare : CC.Stmt
  storage : CC.Stmt
  first : CC.Stmt
  second : CC.Stmt
  indexSet : CC.Stmt
  widthCall : CC.Stmt
  widthSave : CC.Stmt
  stages : CC.Stmt

private def shape (expression : Lean.Expr) (constructor : Lean.Name) (arity : Nat) : Lean.Meta.MetaM Lean.Expr := do
  let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf expression)
  unless result.isAppOfArity constructor arity do throwError "original PUSH stack preparation source changed"
  return result

private def parts : Parts := by
  run_tac do
    let loop ← shape (← Lean.Elab.Term.elabTerm (← `(X86ProducerPushRspSource.stackLoop)) none) ``CC.Stmt.Sloop 2
    let body ← shape loop.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let inner ← shape body.getAppArgs[0]! ``CC.Stmt.Sloop 2
    let prepare ← shape inner.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let setup ← shape prepare.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let pair ← shape setup.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    let following ← shape prepare.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    let width ← shape following.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_stack_source
      (← Lean.Meta.mkAppM ``Parts.mk #[loop.getAppArgs[0]!, inner.getAppArgs[0]!, body.getAppArgs[1]!,
        setup.getAppArgs[0]!, pair.getAppArgs[0]!, pair.getAppArgs[1]!,
        width.getAppArgs[0]!, width.getAppArgs[1]!, following.getAppArgs[1]!])

def body : CC.Stmt := parts.body
def prepare : CC.Stmt := parts.prepare
def storage : CC.Stmt := parts.storage
def first : CC.Stmt := parts.first
def second : CC.Stmt := parts.second
def indexSet : CC.Stmt := parts.indexSet
def widthCall : CC.Stmt := parts.widthCall
def widthSave : CC.Stmt := parts.widthSave
def stages : CC.Stmt := parts.stages

def indexExpression : CC.Expr := by
  run_tac do
    let statement ← shape (← Lean.Elab.Term.elabTerm (← `(indexSet)) none) ``CC.Stmt.Sset 2
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_stack_index statement.getAppArgs[1]!

def outerCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
def prepareCont (k : CC.Cont) : CC.Cont := .Kloop1 prepare .Sbreak (.Kseq storage (outerCont k))
def widthCont (k : CC.Cont) : CC.Cont := .Kseq widthSave (.Kseq stages (prepareCont k))

theorem loop_source : X86ProducerPushRspSource.stackLoop = .Sloop body .Sbreak := rfl
theorem body_source : body = .Ssequence (.Sloop prepare .Sbreak) storage := rfl
theorem prepare_source : prepare = .Ssequence (.Ssequence first (.Ssequence second indexSet))
    (.Ssequence (.Ssequence widthCall widthSave) stages) := rfl

theorem reads_source : first = .Sset X86_program_profile_bpf._t'226 X86ProducerPushRspSource.headerRead ∧
    second = .Sset X86_program_profile_bpf._t'227 (X86ProducerPushRspAddress.pointer X86_program_profile_bpf._t'226) ∧
    indexSet = .Sset X86_program_profile_bpf.___x86_sv_index indexExpression := ⟨rfl,rfl,rfl⟩

theorem width_source : widthCall = .Scall (some X86_program_profile_bpf._t'11)
    (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default))
    [.Etempvar X86_program_profile_bpf.___x86_l_pp_width CC.tuchar] ∧
    widthSave = .Sset X86_program_profile_bpf.___x86_sv_width
      (.Ecast (.Etempvar X86_program_profile_bpf._t'11 CC.tuchar) CC.tulong) := ⟨rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushStackSource
