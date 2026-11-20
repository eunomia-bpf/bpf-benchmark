import KProgFormal.ClightRefinement.Arm64MovImmediateLinkedRead

open KProgFormal.ClightRefinement

#check Arm64MovImmediate.Suffix.read_call_bound
#print axioms Arm64MovImmediate.Suffix.read_call_bound

#check Arm64MovImmediate.Suffix.after_read_bound
#print axioms Arm64MovImmediate.Suffix.after_read_bound

#check Arm64MovImmediate.Suffix.writer_call_register
#print axioms Arm64MovImmediate.Suffix.writer_call_register

#check Arm64MovImmediate.Suffix.writer_call
#print axioms Arm64MovImmediate.Suffix.writer_call

#check Arm64MovImmediate.Suffix.scalar_write
#print axioms Arm64MovImmediate.Suffix.scalar_write

#check Arm64MovImmediate.LinkedRead.scalar_write
#print axioms Arm64MovImmediate.LinkedRead.scalar_write

/-- The existing actual link declares this support selector externally.
Do not instantiate the Numeric-world internal-dispatch theorem here. -/
example :
    CC.Genv.findSymbol Arm64ProgramEntryAllocation.world.genv_genv Arm64Program._kprog_arm64_mov_path =
      some (CC.Positive.ofNat 98) ∧
    CC.Genv.findFunctPtr Arm64ProgramEntryAllocation.world.genv_genv (CC.Positive.ofNat 98) =
      some (.External (.EF_external "kprog_arm64_mov_path"
        (CC.mksignature [.Xlong, .Xlong] .Xlong CC.cc_default))
        [CC.tulong, CC.tulong] CC.tulong CC.cc_default) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
