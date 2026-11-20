import KProgFormal.ClightRefinement.Arm64ProgramEntryResources

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCall

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntrySource (initializationTemps temporaryName sourceType)

def initialTemps (ctx : CC.Val) : CC.TempEnv :=
  (CC.createUndefTemps Arm64ProgramFixture.f_arm64_execute_compile.fn_temps).set
    Arm64ProgramFixture._ctx ctx

/-- The actual wrapper has one context pointer and a signed32 result. This
is its emitted signature, distinct from the borrowed uint32 continuation. -/
theorem signature :
    CC.typeOfFundef (.Internal Arm64ProgramFixture.f_arm64_execute_compile) =
      .Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture.___sk_buff CC.noattr)] CC.tint CC.cc_default := by
  rfl

theorem not_consumer :
    CC.typeOfFundef (.Internal Arm64ProgramFixture.f_arm64_execute_compile) ≠
      Arm64Producer.consumerType := by decide +kernel

private theorem names :
    CC.listNorepet (CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars) ∧
    CC.listNorepet (CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_params) ∧
    CC.listDisjoint (CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_params)
      (CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_temps) := by decide +kernel

private theorem allocation_valid (initial : CC.Mem) :
    CC.AllocVariables world.genv_cenv CC.emptyEnv initial
      Arm64ProgramFixture.f_arm64_execute_compile.fn_vars (allocation initial).1 (allocation initial).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm

/-- Real one-argument function entry, with no manufactured continuation. -/
theorem entry_valid (initial : CC.Mem) (ctx : CC.Val) :
    CC.FunctionEntry2 world Arm64ProgramFixture.f_arm64_execute_compile [ctx] initial
      (allocation initial).1 (initialTemps ctx) (allocation initial).2 :=
  .intro names.1 names.2.1 names.2.2 (allocation_valid initial) rfl

theorem entry_internal (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    InternalRun world 1
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramFixture.f_arm64_execute_compile.fn_body
        k (allocation initial).1 (initialTemps ctx) (allocation initial).2) :=
  .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid initial ctx)) (.refl _)

/-- Entry allocation preserves all original caller observations. -/
theorem entry_frame (initial : CC.Mem) : FrameBelow initial.nextblock initial (allocation initial).2 :=
  (FrameBelow.allocVariables (allocation_valid initial) initial.nextblock (Nat.le_refl _)).2

theorem entry_freeable (initial : CC.Mem) :
    ∀ id value, (allocation initial).1.get id = some value →
      CC.Mem.rangePerm (allocation initial).2 value.1 0 (CC.sizeof world.genv_cenv value.2)
        .Cur .Freeable = true := by
  apply Arm64ProgramEntryResources.locals_freeable initial (allocation initial).2
  exact congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm

theorem initial_context (ctx : CC.Val) :
    (initialTemps ctx).get Arm64ProgramFixture._ctx = some ctx := CC.PTree.gss _ _ _

/-- Every declared temporary is initially undefined; duplicate names would
still agree on this value. This is the imported initialization operation. -/
theorem undefined_temp (rows : List (CC.Ident × CC.Ty)) (row : CC.Ident × CC.Ty)
    (present : row ∈ rows) : (CC.createUndefTemps rows).get row.1 = some .Vundef := by
  induction rows with
  | nil => cases present
  | cons head tail ih =>
    rcases List.mem_cons.mp present with same | member
    · subst head
      exact CC.PTree.gss _ _ _
    · by_cases equal : head.1 = row.1
      · simp only [CC.createUndefTemps, equal, CC.PTree.gss]
      · rw [CC.createUndefTemps, CC.PTree.gso _ _ _ _ equal]
        exact ih member

private theorem undefined_name (rows : List (CC.Ident × CC.Ty)) (id : CC.Ident)
    (present : ∃ ty, (id, ty) ∈ rows) : (CC.createUndefTemps rows).get id = some .Vundef := by
  obtain ⟨ty, member⟩ := present
  exact undefined_temp rows (id, ty) member

private theorem set_undefined (rows : List (CC.Ident × CC.Ty)) (id setter : CC.Ident)
    (value : CC.Val) (present : ∃ ty, (id, ty) ∈ rows) (different : setter ≠ id) :
    ((CC.createUndefTemps rows).set setter value).get id = some .Vundef :=
  (CC.PTree.gso setter id value (CC.createUndefTemps rows) different).trans
    (undefined_name rows id present)

private theorem temporary_names : ∀ i : Fin initializationTemps.length,
    initializationTemps[i].1 ≠ Arm64Entry._ctx ∧
    initializationTemps[i].1 ≠ Arm64Entry._continuation ∧
    temporaryName initializationTemps[i].1 ≠ Arm64ProgramFixture._ctx := by decide +kernel

private theorem context_name : temporaryName Arm64Entry._ctx = Arm64ProgramFixture._ctx := by decide +kernel
private theorem context_not_continuation : Arm64Entry._continuation ≠ Arm64Entry._ctx := by decide +kernel

/-- Context lookup agrees at the actual single-argument entry and the source
producer entry, for every context and unused source continuation value. -/
theorem context_corresponds (ctx continuation : CC.Val) :
    (initialTemps ctx).get (temporaryName Arm64Entry._ctx) =
      (Arm64Producer.initialTemps ctx continuation).get Arm64Entry._ctx := by
  rw [context_name, initial_context]
  simp only [Arm64Producer.initialTemps, CC.PTree.gso _ _ _ _ context_not_continuation, CC.PTree.gss]

/-- All named and generated initialization temporaries use their actual
export-unit identifiers and agree at function entry. The consumer-only t131
and continuation parameter are outside this checked initialization domain. -/
theorem temporaries_correspond (ctx continuation : CC.Val) (i : Fin initializationTemps.length) :
    (initialTemps ctx).get (temporaryName initializationTemps[i].1) =
      (Arm64Producer.initialTemps ctx continuation).get initializationTemps[i].1 := by
  have member : initializationTemps[i] ∈ initializationTemps := List.getElem_mem i.isLt
  have sourceMember : initializationTemps[i] ∈ Arm64Producer.producer.fn_temps :=
    (List.mem_filter.mp member).1
  have actualInitial : (initialTemps ctx).get (temporaryName initializationTemps[i].1) = some .Vundef :=
    set_undefined Arm64ProgramFixture.f_arm64_execute_compile.fn_temps
      (temporaryName initializationTemps[i].1) Arm64ProgramFixture._ctx ctx
      ⟨sourceType initializationTemps[i].2, Arm64ProgramEntrySource.temporary_types i⟩
      (Ne.symm (temporary_names i).2.2)
  have sourceBase := set_undefined Arm64Producer.producer.fn_temps initializationTemps[i].1
    Arm64Entry._ctx ctx ⟨initializationTemps[i].2, sourceMember⟩ (Ne.symm (temporary_names i).1)
  have sourceInitial : (Arm64Producer.initialTemps ctx continuation).get initializationTemps[i].1 =
      some .Vundef :=
    (CC.PTree.gso Arm64Entry._continuation initializationTemps[i].1 continuation
      ((CC.createUndefTemps Arm64Producer.producer.fn_temps).set Arm64Entry._ctx ctx)
      (Ne.symm (temporary_names i).2.1)).trans sourceBase
  exact actualInitial.trans sourceInitial.symm

def functionBlock : CC.Block := CC.Positive.ofNat 88
def inputBlock : CC.Block := CC.Positive.ofNat 59

/-- Bind the actual callable definition in the production global table. -/
theorem function_binding :
    CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._arm64_execute_compile = some functionBlock ∧
    CC.Genv.findFunctPtr world.genv_genv functionBlock =
      some (.Internal Arm64ProgramFixture.f_arm64_execute_compile) :=
  Arm64ProgramEntryLinked.wrapper_binding

/-- The external extraction boundary has its real production block and full
imported signature. The old producer's hard-coded64 is not assumed. -/
theorem input_binding :
    CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input = some inputBlock ∧
    CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction :=
  Arm64ProgramEntryLinked.input_binding

theorem input_unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64Entry._native_lab_entry_input = none := by
  have absent : Arm64Entry._native_lab_entry_input ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
    (allocation_valid initial) absent

private theorem pointer_call (environment : CC.CGenv) (block : CC.Block) (callee : CC.FunDef)
    (bound : CC.Genv.findFunctPtr environment.genv_genv block = some callee) :
    CC.Genv.findFunct environment.genv_genv (.Vptr block 0) = some callee := by
  exact bound

/-- Global resolution and the actual one-step entry hold together. This
reaches the function's real start; no pre-header statement is skipped. -/
theorem entry_at_symbol (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._arm64_execute_compile = some functionBlock ∧
    CC.Genv.findFunct world.genv_genv (.Vptr functionBlock 0) =
      some (.Internal Arm64ProgramFixture.f_arm64_execute_compile) ∧
    InternalRun world 1
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramFixture.f_arm64_execute_compile.fn_body
        k (allocation initial).1 (initialTemps ctx) (allocation initial).2) := by
  refine ⟨function_binding.1, ?_, entry_internal initial ctx k⟩
  exact pointer_call world functionBlock (.Internal Arm64ProgramFixture.f_arm64_execute_compile)
    function_binding.2

end KProgFormal.ClightRefinement.Arm64ProgramEntryCall
