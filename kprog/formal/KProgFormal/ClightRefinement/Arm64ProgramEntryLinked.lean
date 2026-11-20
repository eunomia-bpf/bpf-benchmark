import KProgFormal.Clight.Arm64ProgramFixture
import KProgFormal.Clight.Arm64Program
import CCLib.Linking
import Lean

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinked

private def types : List CC.CompositeDef :=
  (CC.Link.mergeComposites Arm64ProgramFixture.composites Arm64Program.composites).get
    (by decide +kernel)

/-- Source-row references cache the imported linker's ordered result. No C body
or declaration is synthesized; linked_source checks the complete merge. -/
private def definitions : List (CC.Ident × CC.GlobDef CC.FunDef CC.Ty) :=
  (Arm64ProgramFixture.global_definitions.drop 0).take 63 ++
  (Arm64Program.global_definitions.drop 72).take 1 ++
  (Arm64Program.global_definitions.drop 74).take 2 ++
  (Arm64Program.global_definitions.drop 79).take 2 ++
  (Arm64Program.global_definitions.drop 82).take 1 ++
  (Arm64Program.global_definitions.drop 85).take 1 ++
  (Arm64Program.global_definitions.drop 87).take 1 ++
  (Arm64Program.global_definitions.drop 84).take 1 ++
  (Arm64Program.global_definitions.drop 120).take 1 ++
  (Arm64Program.global_definitions.drop 124).take 1 ++
  (Arm64Program.global_definitions.drop 126).take 1 ++
  (Arm64Program.global_definitions.drop 149).take 2 ++
  (Arm64Program.global_definitions.drop 181).take 2 ++
  (Arm64ProgramFixture.global_definitions.drop 79).take 11 ++
  (Arm64Program.global_definitions.drop 19).take 1 ++
  (Arm64Program.global_definitions.drop 59).take 4 ++
  (Arm64Program.global_definitions.drop 64).take 8 ++
  (Arm64Program.global_definitions.drop 73).take 1 ++
  (Arm64Program.global_definitions.drop 76).take 3 ++
  (Arm64Program.global_definitions.drop 81).take 1 ++
  (Arm64Program.global_definitions.drop 83).take 1 ++
  (Arm64Program.global_definitions.drop 88).take 32 ++
  (Arm64Program.global_definitions.drop 121).take 3 ++
  (Arm64Program.global_definitions.drop 125).take 1 ++
  (Arm64Program.global_definitions.drop 127).take 22 ++
  (Arm64Program.global_definitions.drop 151).take 30

def program : CC.Program := CC.mkprogram types definitions
  (Arm64ProgramFixture.prog.prog_public ++ Arm64Program.prog.prog_public.filter
    (fun id => !Arm64ProgramFixture.prog.prog_public.contains id)) Arm64ProgramFixture.prog.prog_main

def ge : CC.CGenv := program.globalenv

/-- Construct closed reflexivity directly for the kernel to check, avoiding
repeated deep meta-level normalization of source/program environments. -/
def sourceEquality : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "expected closed source equality"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

/-- The complete actual fixture and complete handler export link through
Clean's imported linker, retaining original source definitions. -/
theorem linked_source : CC.Link.linkProgram Arm64ProgramFixture.prog Arm64Program.prog =
    some program := by
  run_tac sourceEquality

theorem linked_wellformed : CC.compositesWellFormed program = true := by decide +kernel

theorem definition_count : program.prog_defs.length = 197 := by decide +kernel

theorem composite_count : program.prog_types.length = 14 := by decide +kernel

/-- The imported linker retains every original fixture identifier in order,
while replacing matching external declarations with real definitions. -/
theorem original_names : (program.prog_defs.take 90).map Prod.fst =
    Arm64ProgramFixture.global_definitions.map Prod.fst := by decide +kernel

/-- This is the global-environment frontier; initial-memory allocation is a
separate fact, not inferred from the older source program's count. -/
theorem global_frontier : ge.genv_genv.genv_next = CC.Positive.ofNat 198 := by run_tac sourceEquality

/-- Every composite already present in the actual fixture retains its complete
computed layout. The linked environment may contain additional composites. -/
theorem fixture_composites_preserved : ∀ i : Fin Arm64ProgramFixture.composites.length,
    ge.genv_cenv.get Arm64ProgramFixture.composites[i].name =
      Arm64ProgramFixture.prog.globalenv.genv_cenv.get Arm64ProgramFixture.composites[i].name := by
  decide +kernel

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinked
