import KProgFormal.ClightRefinement.Arm64MemcpyAbiRead

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyStackRoute

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  selected : CC.Stmt
  bsrcSetup : CC.Stmt
  bsrcChoice : CC.Stmt
  bsrcCopy : CC.Stmt
  spRest : CC.Stmt
  spSetup : CC.Stmt
  spRoot : CC.Stmt
  spRead : CC.Stmt
  afterSp : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do
        throwError "original memcpy arm0/SP route changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memcpy_108)) none) ``CC.Stmt.Sifthenelse 3
    let selected ← peel root[1]! ``CC.Stmt.Ssequence 2
    let setup ← peel selected[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel selected[1]! ``CC.Stmt.Ssequence 2
    let sp ← peel rest[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_stack_route
      (← Lean.Meta.mkAppM ``Parts.mk #[root[1]!,selected[0]!,setup[0]!,setup[1]!,selected[1]!,rest[0]!,sp[0]!,sp[1]!,rest[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_stack_route_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private def bsrcSetup : CC.Stmt := by run_tac cachePart (← `(parts.bsrcSetup))
private def bsrcChoice : CC.Stmt := by run_tac cachePart (← `(parts.bsrcChoice))
private def bsrcCopy : CC.Stmt := by run_tac cachePart (← `(parts.bsrcCopy))
private def spRest : CC.Stmt := by run_tac cachePart (← `(parts.spRest))
private def spSetup : CC.Stmt := by run_tac cachePart (← `(parts.spSetup))
private def spRoot : CC.Stmt := by run_tac cachePart (← `(parts.spRoot))
private def spRead : CC.Stmt := by run_tac cachePart (← `(parts.spRead))
def afterSp : CC.Stmt := by run_tac cachePart (← `(parts.afterSp))

private def armTest : CC.Expr := .Ebinop .Oeq (.Etempvar Arm64Program.___a64_mwr_arm CC.tuchar)
  (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint
private def otherArm : CC.Stmt := by
  run_tac do
    let root ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memcpy_108)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_other_arm root.getAppArgs[2]!

private theorem source : Arm64Program.s_kprog_arm64_program_memcpy_108 = .Sifthenelse armTest selected otherArm := rfl
private theorem selected_source : selected = .Ssequence bsrcSetup spRest := rfl
private theorem bsrc_source : bsrcSetup = .Ssequence bsrcChoice bsrcCopy := rfl
private theorem rest_source : spRest = .Ssequence spSetup afterSp := rfl
private theorem sp_source : spSetup = .Ssequence spRoot spRead := rfl

def selectedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'27 (.Vint 1)).set Arm64Program.___a64_mwr_bsrc (.Vint 1)

def temps (le : CC.TempEnv) (sp : CC.Block) (value : BitVec 64) : CC.TempEnv :=
  ((selectedTemps le).set Arm64Program._t'164 (.Vptr sp 0)).set Arm64Program.___a64_mwr_base (.Vlong value)

/-- Execute the actual arm0 test, the constant32 comparison and both bsrc
assignments, reaching the original SP setup with its saved continuation. -/
theorem select (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (arm : le.get Arm64Program.___a64_mwr_arm = some (.Vint 0)) :
    InternalRun world 9 (.State handler Arm64Program.s_kprog_arm64_program_memcpy_108 k e le m)
      (.State handler spSetup (.Kseq afterSp k) e (selectedTemps le) m) := by
  apply internalRun_of_steps
  · simp +decide [source,selected_source,bsrc_source,rest_source,bsrcChoice,bsrcCopy,
      InternalPath,InternalState,steps,CC.doStep,CC.doEvalExpr,arm,armTest,
      CC.PTree.gss,CC.PTree.gso,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,
      CC.Cop.classifyCmp,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,
      CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.classifyBool,CC.typeof,CC.typeconv,
      CC.removeAttributes,CC.tuchar,CC.tuint,CC.tint,CC.tattr,CC.Archi.ptr64,
      CC.Cop.boolVal,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
      CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
      CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext]
  · simp +decide [source,selected_source,bsrc_source,rest_source,bsrcChoice,bsrcCopy,
      steps,CC.doStep,CC.doEvalExpr,arm,armTest,selectedTemps,
      CC.PTree.gss,CC.PTree.gso,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,
      CC.Cop.classifyCmp,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,
      CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.classifyBool,CC.typeof,CC.typeconv,
      CC.removeAttributes,CC.tuchar,CC.tuint,CC.tint,CC.tattr,CC.Archi.ptr64,
      CC.Cop.boolVal,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
      CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
      CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.E0,CC.Eapp]

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40,.Full) := by
  constructor <;> decide +kernel

private theorem root_step {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0)) :
    CC.doStep world (.State handler spRoot k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'164 (CC.Val.Vptr storage.sp.block 0)) m) := by
  simp only [spRoot,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 40).toNat) : Nat) : Int) = 40 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry.block 40 = some (.Vptr storage.sp.block 0) from storage.spPointer]

private theorem read_step {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) :
    CC.doStep world (.State handler spRead k e (le.set Arm64Program._t'164 (CC.Val.Vptr storage.sp.block 0)) m) =
      some (CC.E0,.State handler .Sskip k e
        ((le.set Arm64Program._t'164 (CC.Val.Vptr storage.sp.block 0)).set Arm64Program.___a64_mwr_base (.Vlong storage.spValue)) m) := by
  simp only [spRead,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.PTree.gss,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tlong,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint64 m storage.sp.block 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e
        ((le.set Arm64Program._t'164 (CC.Val.Vptr storage.sp.block 0)).set Arm64Program.___a64_mwr_base value) m)
    | none => none) = _
  rw [storage.spRead]

/-- The real header/SP loads use the current source Storage, preserving the
same heap and the actual SP bits while retaining the original continuation. -/
theorem sp {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0)) :
    InternalRun world 5 (.State handler spSetup (.Kseq afterSp k) e le m)
      (.State handler afterSp k e
        ((le.set Arm64Program._t'164 (CC.Val.Vptr storage.sp.block 0)).set Arm64Program.___a64_mwr_base (.Vlong storage.spValue)) m) := by
  rw [sp_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (root_step storage e le _ hentry)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (read_step storage e le _)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Select arm0 and execute both real SP reads from the reached storage. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (arm : le.get Arm64Program.___a64_mwr_arm = some (.Vint 0)) :
    InternalRun world 14 (.State handler Arm64Program.s_kprog_arm64_program_memcpy_108 k e le m)
      (.State handler afterSp k e (temps le storage.sp.block storage.spValue) m) := by
  have carried : (selectedTemps le).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simpa +decide only [selectedTemps,CC.PTree.gso] using hentry
  exact (select e le m k arm).trans (sp storage e (selectedTemps le) k carried)

/-- All unrelated source temporaries survive the genuine SP route. -/
theorem kept (le : CC.TempEnv) (sp : CC.Block) (value : BitVec 64) (key : CC.Ident)
    (baseOther : Arm64Program.___a64_mwr_base ≠ key)
    (ptrOther : Arm64Program._t'164 ≠ key)
    (srcOther : Arm64Program.___a64_mwr_bsrc ≠ key)
    (choiceOther : Arm64Program._t'27 ≠ key) :
    (temps le sp value).get key = le.get key := by
  simp only [temps,selectedTemps,CC.PTree.gso _ _ _ _ baseOther,
    CC.PTree.gso _ _ _ _ ptrOther,CC.PTree.gso _ _ _ _ srcOther,
    CC.PTree.gso _ _ _ _ choiceOther]

/-- Actual setters retain the loaded SP word and source-selector value. -/
theorem outputs (le : CC.TempEnv) (sp : CC.Block) (value : BitVec 64) :
    (temps le sp value).get Arm64Program.___a64_mwr_base = some (.Vlong value) ∧
    (temps le sp value).get Arm64Program.___a64_mwr_bsrc = some (.Vint 1) := by
  constructor
  · simp only [temps,CC.PTree.gss]
  · simp +decide only [temps,selectedTemps,CC.PTree.gso,CC.PTree.gss]

end KProgFormal.ClightRefinement.Arm64MemcpyStackRoute
