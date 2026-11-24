import KProgFormal.ClightRefinement.X86LogicReference

namespace KProgFormal.ClightRefinement.X86LogicReferenceView

private def reduceFlags : Lean.Elab.Tactic.TacticM Unit := do
  let imported (name : Lean.Name) := Lean.mkIdent
    (Lean.mkPrivateNameCore `KProgFormal.Reference.X86 name)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp +decide [X86LogicReference.input, X86LogicReference.flagsWord,
      $(imported `KProgFormal.Reference.X86.externalCpu):term,
      $(imported `KProgFormal.Reference.X86.externalFlags):term,
      $(imported `KProgFormal.Reference.X86.externalRflags):term,
      List.foldl_cons, List.foldl_nil, apply_ite, BitVec.getLsbD_or,
      BitVec.getLsbD_and, BitVec.getLsbD_not]))

/-- The existing canonical RFLAGS packing and input projection round-trip
all modeled flags, including the oracle-selected AF and preserved DF. -/
theorem flags (state : Reference.X86.State) (old : BitVec 64) (bits : X86.Flags)
    (encoded : state.rflags = X86LogicReference.flagsWord old bits) :
    (X86LogicReference.input state).flags = bits := by
  change X86.Flags.mk (state.rflags.getLsbD 0) (state.rflags.getLsbD 2)
    (state.rflags.getLsbD 4) (state.rflags.getLsbD 6) (state.rflags.getLsbD 7)
    (state.rflags.getLsbD 11) (state.rflags.getLsbD 10) = bits
  rw [encoded]
  rcases bits with ⟨cf, pf, af, zf, sf, overflow, df⟩
  cases cf <;> cases pf <;> cases af <;> cases zf <;> cases sf <;>
    cases overflow <;> cases df <;> run_tac reduceFlags

/-- Source GPR and five-flag views transport to the SAME canonical state
through its existing projections. All other canonical fields are unrestricted
here; the instruction theorem establishes their complete state equality. -/
theorem represented (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (places : X86LogicFlagOrder.Locations)
    (cpu : X86.Cpu) (state : Reference.X86.State) (old : BitVec 64)
    (registers : X86RegisterView.RegistersRepresent addresses origins memory block base cpu)
    (flagBytes : X86LogicFlagMemory.FlagsRepresent memory places cpu.flags)
    (gprs : ∀ index : Fin 16, state.gpr index = cpu.regs.get (X86.GPR.ofIndex index))
    (rflags : state.rflags = X86LogicReference.flagsWord old cpu.flags) :
    X86RegisterView.RegistersRepresent addresses origins memory block base
      (X86LogicReference.input state) ∧
    X86LogicFlagMemory.FlagsRepresent memory places (X86LogicReference.input state).flags := by
  refine ⟨?_, ?_⟩
  · intro index
    obtain ⟨value, raw, tag, wordRead, tagRead, valueRep, native⟩ := registers index
    refine ⟨value, raw, tag, wordRead, tagRead, valueRep, ?_⟩
    rw [X86LogicReference.input_register, X86.GPR.index_ofIndex, gprs]
    exact native
  · rw [flags state old cpu.flags rflags]
    exact flagBytes

end KProgFormal.ClightRefinement.X86LogicReferenceView
