import CCLib.Linking
import KProgFormal.Clight.X86Helpers
import KProgFormal.Clight.X86Pointer

-- Resolve actual helper-to-register-reader calls with the mature linker.
-- This is a composition check, not a migrated refinement theorem.
private def internalIds (p : CC.Program) : List CC.Ident :=
  p.prog_defs.filterMap fun (name, gd) =>
    match gd with
    | .Gfun (.Internal _) => some name
    | _ => none

private def checkLinked : IO Unit := do
  match CC.Link.linkProgramsRenaming [X86Helpers.prog, X86Pointer.prog] with
  | none => throw (IO.userError "x86 helper/read bindings do not link")
  | some linked =>
    let ids := internalIds X86Helpers.prog ++ internalIds X86Pointer.prog
    unless ids.all (CC.Link.hasInternal linked) &&
        (internalIds linked).length == ids.length do
      throw (IO.userError "x86 helper composition lost an actual C body")
    IO.println s!"x86 helper/read composition: {ids.length} actual internal bodies linked"

#eval checkLinked
