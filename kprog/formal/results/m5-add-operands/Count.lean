import KProgFormal.ClightRefinement.Arm64PointerWriteLinked
open KProgFormal.ClightRefinement

def countZero : Nat := Id.run do
  let mut state := CC.State.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
    [.Vundef, .Vlong (255#64)] .Kstop CC.Mem.empty
  for n in [:100] do
    if let .Returnstate _ _ _ := state then return n
    match CC.doStep Arm64ProgramEntryLinked.ge state with
    | some (_, next) => state := next
    | none => return 1000 + n
  return 2000
#eval countZero


def countSelector : Nat := Id.run do
  let mut state := CC.State.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source)
    [.Vlong (3#64)] .Kstop CC.Mem.empty
  for n in [:100] do
    if let .Returnstate _ _ _ := state then return n
    match CC.doStep Arm64ProgramEntryLinked.ge state with
    | some (_, next) => state := next
    | none => return 1000 + n
  return 2000
#eval countSelector
