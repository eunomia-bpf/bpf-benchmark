import KProgFormal.ClightRefinement.X86ProducerPushMetadataSource

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource

private structure Parts where
  body : CC.Stmt
  tagRead : CC.Stmt
  tagStore : CC.Stmt
  pointerRead : CC.Stmt
  pointerStore : CC.Stmt
  tagExpression : CC.Expr
  pointerExpression : CC.Expr
private def parts : Parts := by
  run_tac do
    let norm (e : Lean.Expr) := Lean.Meta.withTransparency .all (Lean.Meta.whnf e)
    let loop ← norm (← Lean.Elab.Term.elabTerm (← `(X86ProducerPushMetadataSource.clear 5)) none)
    unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original PUSH selected clearing loop changed"
    let body ← norm loop.getAppArgs[0]!
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH clearing body changed"
    let tag ← norm body.getAppArgs[0]!
    let pointer ← norm body.getAppArgs[1]!
    unless tag.isAppOfArity ``CC.Stmt.Ssequence 2 && pointer.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "original PUSH clearing read/store pair changed"
    let tagRead ← norm tag.getAppArgs[0]!
    let pointerRead ← norm pointer.getAppArgs[0]!
    unless tagRead.isAppOfArity ``CC.Stmt.Sset 2 && pointerRead.isAppOfArity ``CC.Stmt.Sset 2 do
      throwError "original PUSH clearing pointer load changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_clear_body
      (← Lean.Meta.mkAppM ``Parts.mk #[loop.getAppArgs[0]!,tag.getAppArgs[0]!,tag.getAppArgs[1]!,
        pointer.getAppArgs[0]!,pointer.getAppArgs[1]!,tagRead.getAppArgs[1]!,pointerRead.getAppArgs[1]!])

def body : CC.Stmt := parts.body
def tagRead : CC.Stmt := parts.tagRead
def tagStore : CC.Stmt := parts.tagStore
def pointerRead : CC.Stmt := parts.pointerRead
def pointerStore : CC.Stmt := parts.pointerStore
def tagExpression : CC.Expr := parts.tagExpression
def pointerExpression : CC.Expr := parts.pointerExpression

def headerType : CC.Ty := X86ProducerHeaderSource.headerType
def valueType : CC.Ty := .Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr
def field (name : CC.Ident) (ty : CC.Ty) : CC.Expr := .Efield (.Ederef
  (.Ebinop .Oadd (.Efield (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr headerType)) headerType)
      X86_program_profile_bpf._values (CC.tarray valueType 6))
    (.Econst_int (CC.Integers.Int.repr 5) CC.tint) (CC.tptr valueType)) valueType) name ty

theorem source : X86ProducerPushMetadataSource.clear 5 = .Sloop body .Sbreak ∧
    body = .Ssequence (.Ssequence tagRead tagStore) (.Ssequence pointerRead pointerStore) := ⟨rfl,rfl⟩
theorem reads : tagRead = .Sset X86_program_profile_bpf._t'215 tagExpression ∧
    pointerRead = .Sset X86_program_profile_bpf._t'214 pointerExpression ∧
    tagExpression = field X86_program_profile_bpf._tag (CC.tptr CC.tuchar) ∧
    pointerExpression = field X86_program_profile_bpf._pointer (CC.tptr (CC.tptr CC.tvoid)) := ⟨rfl,rfl,rfl,rfl⟩
theorem stores : tagStore = .Sassign (.Ederef (.Etempvar X86_program_profile_bpf._t'215 (CC.tptr CC.tuchar)) CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) ∧
    pointerStore = .Sassign (.Ederef (.Etempvar X86_program_profile_bpf._t'214 (CC.tptr (CC.tptr CC.tvoid))) (CC.tptr CC.tvoid))
      (.Econst_int (CC.Integers.Int.repr 0) CC.tint) := ⟨rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource
