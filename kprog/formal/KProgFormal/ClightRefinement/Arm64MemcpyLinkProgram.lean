import KProgFormal.Clight.Arm64Addressing
import KProgFormal.Clight.Arm64Address
import CCLib.Linking
import Lean.Elab.Tactic

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLinkProgram

/-- The original source units link with the mature private-symbol renaming. -/
theorem linkable :
    (CC.Link.linkProgramRenaming Arm64Addressing.prog Arm64Address.prog).isSome = true := by
  decide +kernel

def program : CC.Program :=
  (CC.Link.linkProgramRenaming Arm64Addressing.prog Arm64Address.prog).get linkable

def ge : CC.CGenv := program.globalenv
abbrev entry := Arm64Addressing.f_kprog_arm64_link

/-- The real callee retains the source linker's private-symbol renaming. -/
def writer : CC.Function := CC.Link.renameFunction
  (CC.Link.privateRenaming Arm64Addressing.prog Arm64Address.prog)
  Arm64Address.f_kprog_arm64_write_ptr

def resolved (name : CC.Ident) : Option CC.FunDef :=
  (CC.Genv.findSymbol ge.genv_genv name).bind (CC.Genv.findFunctPtr ge.genv_genv)

private def sourceEquality : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "expected an actual source-link equality"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

theorem linked_source :
    CC.Link.linkProgramRenaming Arm64Addressing.prog Arm64Address.prog = some program := by
  run_tac sourceEquality

/-- The exported LINK name resolves to its original complete C function. -/
theorem entry_binding : resolved Arm64Addressing._kprog_arm64_link = some (.Internal entry) := by
  run_tac sourceEquality

/-- The ten-argument call resolves to the actual imported C writer body. -/
theorem writer_binding : resolved Arm64Addressing._kprog_arm64_write_ptr = some (.Internal writer) := by
  run_tac sourceEquality

/-- Check the actual ABI, including the signed bias and pointer-valued input. -/
theorem abi :
    entry.fn_params.map Prod.snd =
      [CC.tptr (.Tstruct Arm64Addressing._kprog_arm64_addressing CC.noattr), CC.tulong] ∧
    entry.fn_return = CC.tulong ∧
    writer.fn_params.map Prod.snd =
      [CC.tptr (.Tstruct Arm64Address._kprog_arm64_coordinates CC.noattr),
       CC.tptr (.Tunion Arm64Address._arm64_sim_gpr CC.noattr), CC.tptr CC.tuchar,
       CC.tptr (CC.tvolatile CC.tuchar), CC.tptr CC.tuchar, CC.tuint, CC.tlong,
       CC.tulong, CC.tptr CC.tvoid, CC.tuchar] ∧
    writer.fn_return = CC.tvoid ∧ writer.fn_callconv = CC.cc_default ∧
    writer.fn_vars.length = 3 := by
  exact ⟨rfl, rfl, rfl, rfl, rfl, rfl⟩

end KProgFormal.ClightRefinement.Arm64MemcpyLinkProgram
