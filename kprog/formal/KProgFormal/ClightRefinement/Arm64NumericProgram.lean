import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame
import KProgFormal.Clight.Arm64Numeric
import CCLib.Linking

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProgram

/-- Data-only source-row references cached from the imported linker. No C body
is copied or synthesized; linked_source kernel-checks the complete result. -/
private def definitions : List (CC.Ident × CC.GlobDef CC.FunDef CC.Ty) :=
  (Arm64Producer.Binding.program.prog_defs.drop 0).take 66 ++
  (Arm64Numeric.global_definitions.drop 57).take 3 ++
  [Arm64Numeric.global_definitions[63]] ++
  [Arm64Numeric.global_definitions[62]] ++
  [Arm64Numeric.global_definitions[73]] ++
  (Arm64Producer.Binding.program.prog_defs.drop 72).take 116 ++
  [Arm64Numeric.global_definitions[56]] ++
  (Arm64Numeric.global_definitions.drop 60).take 2 ++
  (Arm64Numeric.global_definitions.drop 64).take 9 ++
  [Arm64Numeric.global_definitions[74]] ++
  (Arm64Numeric.global_definitions.drop 76).take 2

/-- Whole source units are linked, retaining source body references. -/
def program : CC.Program := CC.mkprogram Arm64Producer.Binding.program.prog_types definitions
  (Arm64Producer.Binding.program.prog_public ++ Arm64Numeric.prog.prog_public.filter
    (fun id => !Arm64Producer.Binding.program.prog_public.contains id))
  Arm64Producer.Binding.program.prog_main

def ge : CC.CGenv := program.globalenv

/-- Closed source equalities are checked by the kernel, without repeatedly
normalizing the large existing handler in tactic unification. -/
private def sourceEquality : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "expected source equality"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

theorem linked_source : CC.Link.linkProgram Arm64Producer.Binding.program Arm64Numeric.prog =
    some program := by run_tac sourceEquality

theorem composites_same : ge.genv_cenv = Arm64Producer.ge.genv_cenv := by run_tac sourceEquality

theorem old_names : (program.prog_defs.take 188).map Prod.fst =
    Arm64Producer.Binding.program.prog_defs.map Prod.fst := by decide +kernel

theorem definition_count : program.prog_defs.length = 203 := by decide +kernel

end KProgFormal.ClightRefinement.Arm64NumericProgram
