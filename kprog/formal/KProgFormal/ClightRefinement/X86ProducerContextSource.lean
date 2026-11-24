import KProgFormal.ClightRefinement.X86ProducerHeaderViews

namespace KProgFormal.ClightRefinement.X86ProducerContextSource
open X86ProducerHeaderSource

def fieldName (i : Fin 5) : CC.Ident :=
  [X86_program_profile_bpf._sim_helper_ctx, X86_program_profile_bpf._sim_helper_abi_base,
   X86_program_profile_bpf._sim_skb_ctx, X86_program_profile_bpf._sim_is_xdp,
   X86_program_profile_bpf._sim_abi_kind][i]
def tempName (i : Fin 5) : CC.Ident :=
  [X86_program_profile_bpf.___x86_sim_helper_ctx, X86_program_profile_bpf.___x86_sim_helper_abi_base,
   X86_program_profile_bpf.___x86_sim_skb_ctx, X86_program_profile_bpf.___x86_sim_is_xdp,
   X86_program_profile_bpf.___x86_sim_abi_kind][i]
def fieldType (i : Fin 5) : CC.Ty :=
  if i.val < 2 then CC.tptr CC.tvoid
  else if i.val = 2 then CC.tptr (.Tstruct X86_program_profile_bpf.___sk_buff CC.noattr)
  else CC.tuchar
def offset (i : Fin 5) : Int := if i.val < 3 then 192 + 8 * (i.val : Int) else 213 + (i.val : Int)
def chunk (i : Fin 5) : CC.Chunk := if i.val < 3 then CC.Mptr else .Mint8unsigned
def target (i : Fin 5) : CC.Expr :=
  .Efield (.Evar X86_program_profile_bpf.___x86_inline_bindings headerType) (fieldName i) (fieldType i)
def rhs (i : Fin 5) : CC.Expr := .Etempvar (tempName i) (fieldType i)
def assignment (i : Fin 5) : CC.Stmt := .Sassign (target i) (rhs i)

/-- Source domains admit real pointer values, including numerical/null pointers,
and canonical unsigned-byte temporary values. No cast or store is assumed. -/
def Typed (values : Fin 5 → CC.Val) : Prop := ∀ i,
  if i.val < 3 then (∃ b ofs, values i = .Vptr b ofs) ∨ ∃ n, values i = .Vlong n
  else ∃ byte : BitVec 8, values i = .Vint (byte.setWidth 32)

private def suffix : CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterHeader)) none
    for _ in [:5] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original context header suffix changed"
      body := body.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_x86_context_suffix body

def afterContext : CC.Stmt := suffix

def bindLoop : CC.Stmt := .Sloop .Sskip .Sbreak

def firstLabel : CC.Stmt := by
  run_tac do
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(afterContext)) none))
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original bind loop changed"
    let next ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[1]!)
    unless next.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original first call sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_x86_first_label next.getAppArgs[0]!

def followingCalls : CC.Stmt := by
  run_tac do
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(afterContext)) none))
    let next ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[1]!)
    unless next.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original first call sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_x86_following_calls next.getAppArgs[1]!

/-- These are exactly the five original context assignments after the pointer header. -/
theorem source_context : afterHeader = (List.ofFn assignment).foldr CC.Stmt.Ssequence afterContext := by rfl

/-- The actual successor retains the bind loop, first original label and subsequent calls. -/
theorem source_loop : afterContext = .Ssequence bindLoop (.Ssequence firstLabel followingCalls) := by rfl

end KProgFormal.ClightRefinement.X86ProducerContextSource
