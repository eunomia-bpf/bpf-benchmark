import KProgFormal.Clight.Arm64ProgramFixture
import KProgFormal.Clight.Arm64Program
import CCLib.Linking


#eval (CC.Link.mergeComposites Arm64ProgramFixture.composites Arm64Program.composites).map List.length
#eval (CC.Link.mergeDefs Arm64ProgramFixture.global_definitions Arm64Program.global_definitions).map List.length
#eval (CC.Link.linkProgram Arm64ProgramFixture.prog Arm64Program.prog).isSome

private def rowSources : Option (List (Nat × Option Nat × Option Nat × Bool)) := do
  let linked ← CC.Link.linkProgram Arm64ProgramFixture.prog Arm64Program.prog
  return linked.prog_defs.mapIdx fun index row =>
    (index, Arm64ProgramFixture.global_definitions.findIdx? (fun old => old.1 == row.1),
      Arm64Program.global_definitions.findIdx? (fun old => old.1 == row.1),
      match row.2 with | .Gfun (.Internal _) => true | _ => false)

#eval rowSources

#eval (CC.Link.linkProgram Arm64ProgramFixture.prog Arm64Program.prog).map fun p =>
  [Arm64ProgramFixture._kprog_arm64_program_execute, Arm64ProgramFixture._native_lab_entry_input,
   Arm64ProgramFixture._kprog_arm64_payload_load, Arm64ProgramFixture._kprog_arm64_payload_store,
   Arm64ProgramFixture._arm64_execute_compile].map fun id => p.prog_defs.findIdx? (fun row => row.1 == id)
