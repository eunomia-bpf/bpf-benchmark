import KProgFormal.ClightRefinement.Arm64OriginCache
import KProgFormal.Clight.Arm64Entry
import KProgFormal.Clight.Arm64Program
import CCLib.Linking

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer.Binding

private def types : List CC.CompositeDef :=
  (CC.Link.mergeComposites Arm64Program.composites Arm64Entry.composites).get (by decide +kernel)

/-- The cached, source-preserving result of linking both complete exports.
Its defining equation is checked against the imported linker below. -/
def program : CC.Program := CC.mkprogram types
  (Arm64Program.global_definitions ++ Arm64Entry.global_definitions.drop 58)
  (Arm64Program.prog.prog_public ++ Arm64Entry.prog.prog_public.filter
    (fun id => !Arm64Program.prog.prog_public.contains id)) Arm64Program.prog.prog_main

def ge : CC.CGenv := program.globalenv

/-- Closed reflexivity is checked by the kernel itself.  This avoids repeatedly
expanding the indexed merge in meta-level definitional-equality search. -/
theorem linked_source : CC.Link.linkProgram Arm64Program.prog Arm64Entry.prog = some program := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected complete program equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem linked_wellformed : CC.compositesWellFormed program = true := by decide +kernel

/-- Every existing handler/global stays in order; the five actual entry-unit
function definitions are appended.  No body or declaration is fabricated. -/
theorem linked_definitions : program.prog_defs =
    Arm64Program.global_definitions ++ Arm64Entry.global_definitions.drop 58 := rfl

theorem entry_definitions : Arm64Entry.global_definitions.drop 58 =
    [(Arm64Entry._kprog_arm64_payload_load, .Gfun (.Internal Arm64Entry.f_kprog_arm64_payload_load)),
     (Arm64Entry._kprog_arm64_payload_store, .Gfun (.Internal Arm64Entry.f_kprog_arm64_payload_store)),
     (Arm64Entry._kprog_arm64_entry_raw, .Gfun (.Internal Arm64Entry.f_kprog_arm64_entry_raw)),
     (Arm64Entry._kprog_arm64_entry_xdp, .Gfun (.Internal Arm64Entry.f_kprog_arm64_entry_xdp)),
     (Arm64Entry._kprog_arm64_entry_skb, .Gfun (.Internal Arm64Entry.f_kprog_arm64_entry_skb))] := rfl


private theorem addGlobals_public {F V : Type} (original : CC.Genv F V)
    (publics : List CC.Ident) (defs : List (CC.Ident × CC.GlobDef F V)) :
    CC.Genv.addGlobals { original with genv_public := publics } defs =
      { CC.Genv.addGlobals original defs with genv_public := publics } := by
  induction defs generalizing original with
  | nil => rfl
  | cons head rest ih => exact ih (CC.Genv.addGlobal original head)

private def baseEnv : CC.Genv CC.FunDef CC.Ty :=
  { Arm64Program.prog.globalenv.genv_genv with genv_public := program.prog_public }

private theorem global_source : ge.genv_genv =
    CC.Genv.addGlobals baseEnv (Arm64Entry.global_definitions.drop 58) := by
  change CC.Genv.addGlobals (CC.Genv.emptyGenv program.prog_public) program.prog_defs = _
  rw [linked_definitions, addGlobals_append]
  have publicsEq := addGlobals_public (CC.Genv.emptyGenv Arm64Program.prog.prog_public)
    program.prog_public Arm64Program.global_definitions
  change CC.Genv.addGlobals (CC.Genv.emptyGenv program.prog_public) Arm64Program.global_definitions =
    baseEnv at publicsEq
  rw [publicsEq]

private theorem base_next : baseEnv.genv_next = CC.Positive.ofNat 184 := by decide +kernel

/-- The original 183 global definitions, including every handler body, retain
their actual blocks in the linked environment. -/
theorem existing_globals (block : CC.Block) (below : block.toNat < 184) :
    CC.Genv.findDef ge.genv_genv block =
      CC.Genv.findDef Arm64Program.prog.globalenv.genv_genv block := by
  rw [global_source, findDef_before_next baseEnv _ block (by rw [base_next]; exact below)]
  simp only [baseEnv, CC.Genv.findDef]

theorem existing_functions (block : CC.Block) (below : block.toNat < 184) :
    CC.Genv.findFunctPtr ge.genv_genv block =
      CC.Genv.findFunctPtr Arm64Program.prog.globalenv.genv_genv block := by
  simp only [CC.Genv.findFunctPtr, existing_globals block below]

private theorem appended_symbols_fresh : ∀ row ∈ Arm64Entry.global_definitions.drop 58,
    CC.Genv.findSymbol Arm64Program.prog.globalenv.genv_genv row.1 = none := by decide +kernel

private theorem symbols_append {F V : Type} (original : CC.Genv F V)
    (defs : List (CC.Ident × CC.GlobDef F V)) (id : CC.Ident)
    (fresh : ∀ row ∈ defs, id ≠ row.1) :
    CC.Genv.findSymbol (CC.Genv.addGlobals original defs) id = CC.Genv.findSymbol original id := by
  induction defs generalizing original with
  | nil => rfl
  | cons head rest ih =>
    rw [addGlobals_cons, ih _ (fun row member => fresh row (List.mem_cons_of_mem _ member))]
    exact CC.PTree.gso _ _ _ _ (Ne.symm (fresh head List.mem_cons_self))

/-- Symbol lookup for every pre-existing program symbol remains exact, despite
the linked public-symbol list and the five appended entry definitions. -/
theorem existing_symbols (id : CC.Ident) (block : CC.Block)
    (found : CC.Genv.findSymbol Arm64Program.prog.globalenv.genv_genv id = some block) :
    CC.Genv.findSymbol ge.genv_genv id = some block := by
  rw [global_source, symbols_append]
  · simpa only [baseEnv, CC.Genv.findSymbol] using found
  · intro row member same
    rw [same, appended_symbols_fresh row member] at found
    cases found

def functionName (i : Fin 5) : CC.Ident :=
  [Arm64Entry._kprog_arm64_payload_load, Arm64Entry._kprog_arm64_payload_store,
   Arm64Entry._kprog_arm64_entry_raw, Arm64Entry._kprog_arm64_entry_xdp, Arm64Entry._kprog_arm64_entry_skb][i]
def functionBody (i : Fin 5) : CC.Function :=
  [Arm64Entry.f_kprog_arm64_payload_load, Arm64Entry.f_kprog_arm64_payload_store,
   Arm64Entry.f_kprog_arm64_entry_raw, Arm64Entry.f_kprog_arm64_entry_xdp, Arm64Entry.f_kprog_arm64_entry_skb][i]
def functionBlock (i : Fin 5) : CC.Block := CC.Positive.ofNat (184 + i.val)

private theorem appended_symbols : ∀ i : Fin 5,
    CC.Genv.findSymbol ge.genv_genv (functionName i) = some (functionBlock i) := by
  rw [global_source]
  decide +kernel

private theorem appended_pointers : ∀ i : Fin 5,
    CC.Genv.findFunctPtr ge.genv_genv (functionBlock i) = some (.Internal (functionBody i)) := by
  intro i
  have cases5 : ∀ j : Fin 5, j=⟨0, by decide⟩ ∨ j=⟨1, by decide⟩ ∨ j=⟨2, by decide⟩ ∨
      j=⟨3, by decide⟩ ∨ j=⟨4, by decide⟩ := by decide +kernel
  rcases cases5 i with rfl | rfl | rfl | rfl | rfl
  all_goals
    run_tac do
      let goal ← Lean.Elab.Tactic.getMainGoal
      let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
      unless target.isAppOfArity ``Eq 3 do throwError "expected actual function binding, got {target}"
      goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
      Lean.Elab.Tactic.replaceMainGoal []

/-- Actual payload callbacks occupy184/185 and raw/XDP/SKB producers186/187/188.
Each symbol resolves to the corresponding unchanged exported function body. -/
theorem appended_functions (i : Fin 5) :
    CC.Genv.findSymbol ge.genv_genv (functionName i) = some (functionBlock i) ∧
    CC.Genv.findFunctPtr ge.genv_genv (functionBlock i) = some (.Internal (functionBody i)) :=
  ⟨appended_symbols i, appended_pointers i⟩

private def inputBefore := Arm64Program.global_definitions.take 63
private def inputAfter := Arm64Program.global_definitions.drop 64
private def inputBeforeEnv : CC.Genv CC.FunDef CC.Ty :=
  CC.Genv.addGlobals (CC.Genv.emptyGenv Arm64Program.prog.prog_public) inputBefore
private theorem input_next : inputBeforeEnv.genv_next = CC.Positive.ofNat 64 := rfl
private theorem input_source : Arm64Program.global_definitions = inputBefore ++
    (Arm64Program._native_lab_entry_input, .Gfun Arm64OriginCache.inputFunction) :: inputAfter := rfl
private theorem program_input : CC.Genv.findFunctPtr Arm64Program.prog.globalenv.genv_genv
    (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction := by
  change CC.Genv.findFunctPtr
    (CC.Genv.addGlobals (CC.Genv.emptyGenv Arm64Program.prog.prog_public) Arm64Program.global_definitions) _ = _
  rw [input_source, addGlobals_append, addGlobals_cons, ← input_next]
  exact findFunctPtr_next inputBeforeEnv _ Arm64OriginCache.inputFunction inputAfter

theorem linked_input : CC.Genv.findSymbol ge.genv_genv Arm64Entry._native_lab_entry_input =
      some (CC.Positive.ofNat 64) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction := by
  constructor
  · apply existing_symbols
    decide +kernel
  · rw [existing_functions _ (by decide +kernel)]
    exact program_input

private theorem cenv_source : ge.genv_cenv =
    (CC.buildCompositeEnv types).toOption.getD CC.PTree.empty := by
  simp only [ge, CC.Program.globalenv, program, CC.mkprogram]

/-- All nine original program composites retain their full imported layouts. -/
theorem program_layouts : ∀ i : Fin 9,
    ge.genv_cenv.get (Arm64Program.composites[i.val]'(by change i.val < 9; exact i.isLt)).name =
    Arm64Program.prog.globalenv.genv_cenv.get
      (Arm64Program.composites[i.val]'(by change i.val < 9; exact i.isLt)).name := by
  rw [cenv_source]
  decide +kernel

/-- All fourteen entry-unit composites, including anonymous vector/stack types,
retain their full layouts in the linker's rebuilt environment. -/
theorem entry_layouts : ∀ i : Fin 14,
    ge.genv_cenv.get (Arm64Entry.composites[i.val]'(by change i.val < 14; exact i.isLt)).name =
    Arm64Entry.prog.globalenv.genv_cenv.get
      (Arm64Entry.composites[i.val]'(by change i.val < 14; exact i.isLt)).name := by
  rw [cenv_source]
  decide +kernel

/-- Allocation-relevant layout for every actual producer variable is retained. -/
theorem local_layouts : ∀ row ∈ Arm64Entry.f_kprog_arm64_entry_raw.fn_vars,
    CC.sizeof ge.genv_cenv row.2 = CC.sizeof Arm64Entry.prog.globalenv.genv_cenv row.2 ∧
    CC.alignof ge.genv_cenv row.2 = CC.alignof Arm64Entry.prog.globalenv.genv_cenv row.2 := by
  rw [cenv_source]
  decide +kernel

private theorem allocate_sizes (first second : CC.CompositeEnv) (vars : List (CC.Ident × CC.Ty))
    (sizes : ∀ row ∈ vars, CC.sizeof first row.2 = CC.sizeof second row.2)
    (env : CC.Env) (memory : CC.Mem) :
    CC.doAllocVariables first env memory vars = CC.doAllocVariables second env memory vars := by
  induction vars generalizing env memory with
  | nil => rfl
  | cons head rest ih =>
    simp only [CC.doAllocVariables]
    rw [sizes head List.mem_cons_self]
    apply ih
    intro row member
    exact sizes row (List.mem_cons_of_mem _ member)

/-- The linked producer allocates precisely the same local blocks and memory;
no assumed successful allocation or copied register bank is introduced. -/
theorem linked_allocation (m : CC.Mem) :
    CC.doAllocVariables ge.genv_cenv CC.emptyEnv m Arm64Entry.f_kprog_arm64_entry_raw.fn_vars =
      CC.doAllocVariables Arm64Entry.prog.globalenv.genv_cenv CC.emptyEnv m
        Arm64Entry.f_kprog_arm64_entry_raw.fn_vars :=
  allocate_sizes _ _ _ (fun row member => (local_layouts row member).1) _ _

end KProgFormal.ClightRefinement.Arm64Producer.Binding
