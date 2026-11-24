import KProgFormal.ClightRefinement.X86ProducerAbiInitialize

namespace KProgFormal.ClightRefinement.X86ProducerGhostSource
open X86ProducerHeaderSource (producer)

def row (i : Fin 12) : Fin 24 := ⟨i.val + 2, by omega⟩
def assignment (i : Fin 12) : CC.Stmt := .Sassign
  (.Evar (X86ProducerHeaderSource.localName (row i)) (X86ProducerHeaderSource.localType (row i)))
  (.Econst_int (CC.Integers.Int.repr 0) CC.tint)
def chunk (i : Fin 12) : CC.Chunk := if i.val % 2 = 0 then .Mint8unsigned else CC.Mptr
def value (i : Fin 12) : CC.Val := if i.val % 2 = 0 then .Vint 0 else .Vlong 0

private def suffix (source : Lean.Syntax) (count : Nat) : Lean.Elab.Tactic.TacticM Unit := do
  let mut body ← Lean.Elab.Term.elabTerm source none
  for _ in [:count] do
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original ghost/context setup suffix changed"
    body := body.getAppArgs[1]!
  Lean.Elab.Tactic.closeMainGoal `original_x86_ghost_suffix body

def ghostStart : CC.Stmt := by
  run_tac suffix (← `(X86ProducerAbiSource.afterAbi)) 2

def afterGhosts : CC.Stmt := by
  run_tac suffix (← `(ghostStart)) 12

def beforeProvider : CC.Stmt := by
  run_tac suffix (← `(afterGhosts)) 3

def contextTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf.___x86_sim_skb_ctx (.Vlong 0)).set
    X86_program_profile_bpf.___x86_sim_abi_kind (.Vint (2#32))
def finalTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((le.set X86_program_profile_bpf.___x86_sim_is_xdp (.Vint 0)).set
    X86_program_profile_bpf.___x86_sim_helper_ctx (.Vlong 0)).set
    X86_program_profile_bpf.___x86_sim_helper_abi_base (.Vlong 0)

/-- All twelve ghost initializations retain their original typed local targets. -/
theorem source_ghosts : ghostStart = (List.ofFn assignment).foldr CC.Stmt.Ssequence afterGhosts := by rfl

/-- The genuine two context-temporary assignments precede the ghost writes. -/
theorem to_ghosts (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 6 (.State producer X86ProducerAbiSource.afterAbi k e le memory)
      (.State producer ghostStart k e (contextTemps le) memory) := by
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl)
          (.step trivial (CC.doStep_sound ge _ _ _ rfl)
            (.step trivial (CC.doStep_sound ge _ _ _ rfl)
              (.refl _))))))

/-- The original XDP/helper temporary setup then reaches the untouched provider suffix. -/
theorem after_ghosts (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 9 (.State producer afterGhosts k e le memory)
      (.State producer beforeProvider k e (finalTemps le) memory) := by
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl)
        (.step trivial (CC.doStep_sound ge _ _ _ rfl)
          (.step trivial (CC.doStep_sound ge _ _ _ rfl)
            (.step trivial (CC.doStep_sound ge _ _ _ rfl)
              (.step trivial (CC.doStep_sound ge _ _ _ rfl)
                (.step trivial (CC.doStep_sound ge _ _ _ rfl)
                  (.step trivial (CC.doStep_sound ge _ _ _ rfl)
                    (.refl _)))))))))

end KProgFormal.ClightRefinement.X86ProducerGhostSource
