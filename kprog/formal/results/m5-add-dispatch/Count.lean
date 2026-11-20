import KProgFormal.ClightRefinement.Arm64AddImmediate
open KProgFormal.ClightRefinement

def countDispatch (narrow : Bool) : Nat := Id.run do
  let le := ((CC.PTree.empty : CC.TempEnv).set Arm64Program._op (.Vint (3#32))).set
    Arm64Program._flags (Arm64Width.argument (if narrow then (4#8) else (8#8)))
  let mut state := CC.State.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop CC.PTree.empty le CC.Mem.empty
  for n in [:120] do
    if let .State _ (.Sloop (.Ssequence (.Sset name _) _) _) _ _ _ _ := state then
      if name == Arm64Program.___a64_alu_width then return n
    match CC.doStep Arm64ProgramEntryLinked.ge state with
    | some (_, next) => state := next
    | none => return 1000+n
  return 2000
#eval countDispatch false
#eval countDispatch true
