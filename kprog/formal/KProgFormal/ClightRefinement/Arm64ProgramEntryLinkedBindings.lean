import KProgFormal.ClightRefinement.Arm64ProgramEntryLinked

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinked

def executeBlock : CC.Block := CC.Positive.ofNat 72

/-- Actual call lookup now resolves to the unchanged generic C body, rather
than leaving the exported external declaration uninterpreted. -/
theorem execute_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64ProgramFixture._kprog_arm64_program_execute = some executeBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv executeBlock =
      some (.Internal Arm64Program.f_kprog_arm64_program_execute) := by
  constructor <;> run_tac sourceEquality

theorem execute_signature :
    CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_execute) =
      .Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),
        CC.tuint, CC.tulong, CC.tulong, CC.tulong, CC.tulong, CC.tuchar, CC.tuint, CC.tulong]
        CC.tvoid CC.cc_default := by rfl

/-- The actual MOV path selector resolves to its exported Numeric C body. -/
theorem mov_selector_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_mov_path = some (CC.Positive.ofNat 98) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 98) =
      some (.Internal Arm64Numeric.f_kprog_arm64_mov_path) := by
  constructor <;> run_tac sourceEquality

/-- Both actual payload callbacks retain their original positions and bodies. -/
theorem callback_binding (store : Bool) :
    CC.Genv.findSymbol ge.genv_genv
      (if store then Arm64ProgramFixture._kprog_arm64_payload_store else Arm64ProgramFixture._kprog_arm64_payload_load) =
      some (CC.Positive.ofNat (if store then 61 else 60)) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat (if store then 61 else 60)) =
      some (.Internal (if store then Arm64ProgramFixture.f_kprog_arm64_payload_store
        else Arm64ProgramFixture.f_kprog_arm64_payload_load)) := by
  cases store <;> constructor <;> run_tac sourceEquality

/-- The actual one-context wrapper is retained, not replaced by a synthetic
one-pointer/uint32 continuation. -/
theorem wrapper_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64ProgramFixture._arm64_execute_compile =
      some (CC.Positive.ofNat 88) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 88) =
      some (.Internal Arm64ProgramFixture.f_arm64_execute_compile) := by
  constructor <;> run_tac sourceEquality

/-- Native input keeps its symbol and original external declaration. The
provider contract is subsequently instantiated in this linked world. -/
theorem input_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64ProgramFixture._native_lab_entry_input =
      some (CC.Positive.ofNat 59) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 59) =
      some (.External (.EF_external "native_lab_entry_input"
        (CC.mksignature [.Xint] .Xlong CC.cc_default)) [CC.tuint] CC.tulong CC.cc_default) := by
  constructor <;> run_tac sourceEquality

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinked
