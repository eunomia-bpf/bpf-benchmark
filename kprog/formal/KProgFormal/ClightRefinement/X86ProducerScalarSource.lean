import KProgFormal.ClightRefinement.X86ProducerGprPrefix

namespace KProgFormal.ClightRefinement.X86ProducerScalarSource
open X86ProducerHeaderSource (localName localType)

def start : CC.Stmt := X86_program_profile_bpf.s_x86_program_profile_x86_sim_xdp_30
def initialBaseZero : CC.Stmt := X86_program_profile_bpf.s_x86_program_profile_x86_sim_xdp_19

structure Site where
  whole : CC.Stmt
  call : CC.Stmt
  assignment : CC.Stmt
  following : CC.Stmt
  resultName : CC.Ident

private def sites : List Site := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(start)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:8] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original scalar initialization sequence changed"
      let setup ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      unless setup.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original scalar input/assignment changed"
      let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf setup.getAppArgs[0]!)
      unless call.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original scalar provider call changed"
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf call.getAppArgs[0]!)
      unless result.isAppOfArity ``Option.some 2 do throwError "original scalar result missing"
      rows := rows.push (← Lean.Meta.mkAppM ``Site.mk #[body,setup.getAppArgs[0]!,setup.getAppArgs[1]!,
        body.getAppArgs[1]!,result.getAppArgs[1]!])
      body := body.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_x86_scalar_sites
      (← Lean.Meta.mkListLit (Lean.mkConst ``Site) rows.toList)

def site (i : Fin 8) : Site := sites[i.val]'(by have size : sites.length = 8 := rfl; rw [size]; exact i.isLt)
def row (i : Fin 8) : Fin 24 := ⟨15 + i.val, by omega⟩
def chunk (i : Fin 8) : CC.Chunk := if i.val < 6 then .Mint8unsigned else .Mint64
def rhs (i : Fin 8) : CC.Expr := if i.val < 6 then
  .Ebinop .Oand (.Etempvar (site i).resultName CC.tulong) (.Econst_int (CC.Integers.Int.repr 1) CC.tint) CC.tulong
  else .Etempvar (site i).resultName CC.tulong

def following : CC.Stmt := (site 7).following
def cursor (count : Nat) : CC.Stmt := if h : count < 8 then (site ⟨count,h⟩).whole else following

private theorem cases8 : ∀ i : Fin 8, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 := by decide +kernel

/-- The original GPR chain retains its actual native-base zero assignment
before the genuine flag/XMM setup. -/
theorem source_begin : X86ProducerGprChain.following = .Ssequence initialBaseZero start ∧
    start = (site 0).whole := by constructor <;> rfl

/-- Every source sequence and successor is retained, including all six flags. -/
theorem source_route (i : Fin 8) : (site i).whole = .Ssequence (.Ssequence (site i).call (site i).assignment) (site i).following := by
  rcases cases8 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

theorem source_call (i : Fin 8) : (site i).call = .Scall (some (site i).resultName)
    (.Evar X86_program_profile_bpf._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 6) CC.tint] := by
  rcases cases8 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

/-- CF/ZF/SF/OF/PF/AF store input&1; both XMM halves store the full word. -/
theorem source_assignment (i : Fin 8) : (site i).assignment =
    .Sassign (.Evar (localName (row i)) (localType (row i))) (rhs i) := by
  rcases cases8 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

theorem cursor_at (i : Fin 8) : cursor i.val = (site i).whole := by simp only [cursor, dite_eq_left i.isLt]
theorem cursor_next (i : Fin 8) : cursor (i.val + 1) = (site i).following := by
  rcases cases8 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

end KProgFormal.ClightRefinement.X86ProducerScalarSource
