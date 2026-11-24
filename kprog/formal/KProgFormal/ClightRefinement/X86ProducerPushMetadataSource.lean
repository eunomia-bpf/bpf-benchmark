import KProgFormal.ClightRefinement.X86ProducerPushStackSource

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataSource

private structure Part where
  stage : CC.Stmt
  body : CC.Stmt
  clear : CC.Stmt
  flag : CC.Ident
private def parts : List Part := by
  run_tac do
    let norm (e : Lean.Expr) := Lean.Meta.withTransparency .all (Lean.Meta.whnf e)
    let mut rest ← Lean.Elab.Term.elabTerm (← `(X86ProducerPushStackSource.stages)) none
    let mut rows : Array Lean.Expr := #[]
    for i in [0:6] do
      let node ← norm rest
      let stage ← if i < 5 then do
        unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH metadata sequence changed"
        rest := node.getAppArgs[1]!
        pure node.getAppArgs[0]!
      else pure node
      let loop ← norm stage
      unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original PUSH metadata loop changed"
      let body ← norm loop.getAppArgs[0]!
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH metadata start/selector changed"
      let following ← norm body.getAppArgs[1]!
      unless following.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH metadata selector/arm changed"
      let branch ← norm following.getAppArgs[1]!
      unless branch.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original PUSH metadata flag branch changed"
      let condition ← norm branch.getAppArgs[0]!
      unless condition.isAppOfArity ``CC.Expr.Etempvar 2 do throwError "original PUSH metadata flag read changed"
      rows := rows.push (← Lean.Meta.mkAppM ``Part.mk #[stage, loop.getAppArgs[0]!, branch.getAppArgs[1]!,condition.getAppArgs[0]!])
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_metadata_stages
      (← Lean.Meta.mkListLit (Lean.mkConst ``Part) rows.toList)
private theorem six : parts.length = 6 := rfl
private def part (i : Fin 6) : Part := parts[i.val]'(by rw [six]; exact i.isLt)

def stage (i : Fin 6) : CC.Stmt := (part i).stage
def body (i : Fin 6) : CC.Stmt := (part i).body
def clear (i : Fin 6) : CC.Stmt := (part i).clear
def flag (i : Fin 6) : CC.Ident := (part i).flag

theorem source : X86ProducerPushStackSource.stages = .Ssequence (stage 0) (.Ssequence (stage 1)
    (.Ssequence (stage 2) (.Ssequence (stage 3) (.Ssequence (stage 4) (stage 5))))) := rfl

def continuation (i : Fin 6) (k : CC.Cont) : CC.Cont := .Kloop1 (body i) .Sbreak k

theorem stage_source : ∀ i : Fin 6, stage i = .Sloop (body i) .Sbreak := by
  intro i
  have cases : ∀ i : Fin 6, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 := by decide +kernel
  rcases cases i with rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

theorem flag_names : flag 0 = X86_program_profile_bpf._t'12 ∧ flag 1 = X86_program_profile_bpf._t'13 ∧
    flag 2 = X86_program_profile_bpf._t'14 ∧ flag 3 = X86_program_profile_bpf._t'15 ∧
    flag 4 = X86_program_profile_bpf._t'16 ∧ flag 5 = X86_program_profile_bpf._t'17 := ⟨rfl,rfl,rfl,rfl,rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushMetadataSource
