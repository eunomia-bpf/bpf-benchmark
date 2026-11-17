-- Metadata only: source references for the imported linker cache.
import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame
import KProgFormal.Clight.Arm64Numeric
import CCLib.Linking
open KProgFormal.ClightRefinement
def sourceRows : Option (List (Bool × Nat)) := do
  let linked ← CC.Link.linkProgram Arm64Producer.Binding.program Arm64Numeric.prog
  linked.prog_defs.mapM fun row => do
    let numeric := Arm64Numeric.global_definitions.zipIdx.find? fun item =>
      item.1.1 == row.1 && match item.1.2 with | .Gfun (.Internal _) => true | _ => false
    match numeric with
    | some item => pure (true, item.2)
    | none =>
      let item ← Arm64Producer.Binding.program.prog_defs.zipIdx.find? (fun item => item.1.1 == row.1)
      pure (false, item.2)

#eval match sourceRows with
  | none => throw (IO.userError "actual Numeric link has an unbound source row")
  | some rows => IO.println (Lean.Json.compress (Lean.Json.arr (rows.toArray.map fun (row : Bool × Nat) =>
      Lean.Json.arr #[Lean.Json.bool row.1, Lean.toJson row.2])))
