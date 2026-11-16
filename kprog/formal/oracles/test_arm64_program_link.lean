import CCLib.Linking
import KProgFormal.Clight.Arm64Program
import KProgFormal.Clight.Arm64ProgramFixture
import KProgFormal.Clight.Arm64ProgramContext
import KProgFormal.Clight.Arm64Numeric

-- Check actual exported definitions and declared signatures with the mature
-- library linker. This is computation, not a handler refinement theorem.
private def internalIds (p : CC.Program) : List CC.Ident :=
  p.prog_defs.filterMap fun (name, gd) =>
    match gd with
    | .Gfun (.Internal _) => some name
    | _ => none

private def checkLinked (name : String) (p : CC.Program) : IO Unit := do
  match CC.Link.linkProgramsRenaming
      [p, Arm64Program.prog, Arm64Numeric.prog] with
  | none => throw (IO.userError s!"ARM {name}: incompatible exported modules")
  | some linked =>
    let ids := internalIds Arm64Program.prog ++ internalIds Arm64Numeric.prog ++ internalIds p
    unless ids.all (CC.Link.hasInternal linked) do
      throw (IO.userError s!"ARM {name}: canonical C body did not resolve")
    IO.println s!"ARM {name}: {ids.length} actual Clight definitions linked"

#eval checkLinked "CALL/RET fixture" Arm64ProgramFixture.prog
#eval checkLinked "XDP/SKB fixture" Arm64ProgramContext.prog
