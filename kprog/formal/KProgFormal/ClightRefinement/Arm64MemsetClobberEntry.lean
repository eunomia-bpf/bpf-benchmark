import KProgFormal.ClightRefinement.Arm64MemsetTagTransferComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberEntry

open Arm64ProgramEntryAllocation (world)

def helper : CC.Function := Arm64Program.f_kprog_arm64_program_clobbers

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_clobber_source_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private structure Parts where
  body : CC.Stmt
  release : CC.Stmt
  rest : CC.Stmt
  releaseBody : CC.Stmt
  oldSetup : CC.Stmt
  afterOld : CC.Stmt
  readBias : CC.Stmt
  setOld : CC.Stmt
  newSetup : CC.Stmt
  test : CC.Stmt
  readPointer : CC.Stmt
  setNew : CC.Stmt
  condition : CC.Expr
  selected : CC.Stmt
  bytes : CC.Stmt
  tags : CC.Stmt
  init : CC.Stmt
  loop : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original clobber entry changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(helper.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let release ← peel body[0]! ``CC.Stmt.Sloop 2
    let releaseBody ← peel release[0]! ``CC.Stmt.Ssequence 2
    let old ← peel releaseBody[0]! ``CC.Stmt.Ssequence 2
    let afterOld ← peel releaseBody[1]! ``CC.Stmt.Ssequence 2
    let new ← peel afterOld[0]! ``CC.Stmt.Ssequence 2
    let test ← peel afterOld[1]! ``CC.Stmt.Sifthenelse 3
    let selected ← peel test[1]! ``CC.Stmt.Ssequence 2
    let bytes ← peel selected[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_clobber_entry_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,body[0]!,body[1]!,release[0]!,releaseBody[0]!,releaseBody[1]!,
        old[0]!,old[1]!,afterOld[0]!,afterOld[1]!,new[0]!,new[1]!,test[0]!,test[1]!,
        selected[0]!,selected[1]!,bytes[0]!,bytes[1]!])

private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def release : CC.Stmt := by run_tac cachePart (← `(parts.release))
def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def releaseBody : CC.Stmt := by run_tac cachePart (← `(parts.releaseBody))
private def oldSetup : CC.Stmt := by run_tac cachePart (← `(parts.oldSetup))
private def afterOld : CC.Stmt := by run_tac cachePart (← `(parts.afterOld))
private def readBias : CC.Stmt := by run_tac cachePart (← `(parts.readBias))
private def setOld : CC.Stmt := by run_tac cachePart (← `(parts.setOld))
private def newSetup : CC.Stmt := by run_tac cachePart (← `(parts.newSetup))
private def test : CC.Stmt := by run_tac cachePart (← `(parts.test))
private def readPointer : CC.Stmt := by run_tac cachePart (← `(parts.readPointer))
private def setNew : CC.Stmt := by run_tac cachePart (← `(parts.setNew))
private def condition : CC.Expr := by run_tac cachePart (← `(parts.condition))
private def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private def bytes : CC.Stmt := by run_tac cachePart (← `(parts.bytes))
def tags : CC.Stmt := by run_tac cachePart (← `(parts.tags))
private def init : CC.Stmt := by run_tac cachePart (← `(parts.init))
def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))

private theorem helper_source : helper.fn_body = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence release rest := rfl
private theorem release_source : release = .Sloop releaseBody .Sbreak := rfl
private theorem release_body_source : releaseBody = .Ssequence oldSetup afterOld := rfl
private theorem old_source : oldSetup = .Ssequence readBias setOld := rfl
private theorem after_old_source : afterOld = .Ssequence newSetup test := rfl
private theorem new_source : newSetup = .Ssequence readPointer setNew := rfl
private theorem test_source : test = .Sifthenelse condition selected .Sskip := rfl
private theorem selected_source : selected = .Ssequence bytes tags := rfl
private theorem bytes_source : bytes = .Ssequence init loop := rfl

private def tempList : List (CC.Ident × CC.Ty) := by run_tac cachePart (← `(helper.fn_temps))
private def undefTemps : CC.TempEnv := CC.createUndefTemps tempList
def initialTemps (entry : CC.Block) : CC.TempEnv := undefTemps.set Arm64Program._entry (.Vptr entry 0)

/-- The actual clobber helper has no local allocations. Its real parameter and
two undef-temporary declaration chunks enter on exactly the caller's heap. -/
theorem entry_valid (m : CC.Mem) (entry : CC.Block) :
    CC.FunctionEntry2 world helper [.Vptr entry 0] m CC.emptyEnv (initialTemps entry) m := by
  apply CC.FunctionEntry2.intro
  · decide +kernel
  · decide +kernel
  · change CC.listDisjoint [Arm64Program._entry] _
    intro id present other
    have eq : id = Arm64Program._entry := by simpa only [List.mem_singleton] using present
    subst id
    have chunks :
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_clobbers_temps_0 ∧
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_clobbers_temps_1 := by
      constructor <;> decide +kernel
    change Arm64Program._entry ∈ CC.varNames
      (Arm64Program.l_kprog_arm64_program_clobbers_temps_0 ++ Arm64Program.l_kprog_arm64_program_clobbers_temps_1) at other
    simp only [CC.varNames,List.map_append,List.mem_append] at other
    exact other.elim chunks.1 chunks.2
  · exact .nil _ _
  · rfl

/-- Actual linked row108 (one-based symbol109), checked against both imported
symbol and function lookup below. -/
private def symbol : CC.Block := CC.Positive.ofNat 109

private theorem binding :
    CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_clobbers = some symbol ∧
    CC.Genv.findFunctPtr world.genv_genv symbol = some (.Internal helper) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem call_source : Arm64MemsetTagTransfer.clobbers = .Scall none
    (.Evar Arm64Program._kprog_arm64_program_clobbers
      (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)] CC.tvoid CC.cc_default))
    [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr))] := rfl

def callCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none Arm64MemsetSource.handler (Arm64MemsetSource.allocation before).1 le k

/-- The original memset continuation calls the actual linked C helper, keeping
its own locals and exact return continuation live. -/
theorem call_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
      (Arm64MemsetSource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal helper) [.Vptr entry 0] (callCont before le k) m) := by
  have unshadowed : (Arm64MemsetSource.allocation before).1.get Arm64Program._kprog_arm64_program_clobbers = none := by
    have outside : Arm64Program._kprog_arm64_program_clobbers ∉ CC.varNames Arm64MemsetSource.handler.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (Arm64MemsetSource.allocated before) outside
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)])
    (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr symbol 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,hentry]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) ∧
    CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40,.Full) := by
  constructor
  · decide +kernel
  constructor <;> decide +kernel

private theorem bias_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doEvalExpr world e le m
      (.Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
        (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) Arm64Program._bias CC.tlong) = some (.Vlong 96) := by
  simp only [CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2.1,
    CC.typeof,CC.tlong,CC.tattr,CC.typeconv,CC.removeAttributes,CC.doDerefLoc,CC.accessMode,
    CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [offset,bias]

private theorem pointer_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (entry sp : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0)) :
    CC.doEvalExpr world e le m
      (.Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
        (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) Arm64Program._sp (CC.tptr CC.tlong)) = some (.Vptr sp 0) := by
  simp only [CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2.2,
    CC.typeof,CC.tattr,CC.typeconv,CC.removeAttributes,CC.doDerefLoc,CC.accessMode,
    CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 40).toNat) : Nat) : Int) = 40 := by decide +kernel
  change CC.Mem.load CC.Mptr m entry _ = _
  rw [offset,pointer]

def releaseTemps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv :=
  (((le.set Arm64Program._t'239 (.Vlong 96)).set Arm64Program.___a64_release_old (.Vlong (-96#64))).set
    Arm64Program._t'238 (.Vptr sp 0)).set Arm64Program.___a64_release_new (.Vlong (-32#64))

private theorem condition_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (sp : CC.Block) :
    CC.doEvalExpr world e (releaseTemps le sp) m condition = some (.Vint 1) := by
  simp +decide only [condition,releaseTemps,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,
    CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tlong,CC.tint,CC.tattr,
    CC.Integers.Int64.cmp,CC.Integers.MI.cmp,CC.Integers.MI.lt,CC.Integers.Int64.signed,CC.Integers.MI.signed,
    CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Integers.Int.one,CC.Integers.Int.zero,CC.Integers.MI.one,CC.Integers.MI.zero]

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq tags (.Kloop1 releaseBody .Sbreak (.Kseq rest (.Kloop1 body .Sbreak k)))
def temps (entry sp : CC.Block) : CC.TempEnv :=
  (releaseTemps (initialTemps entry) sp).set Arm64Program.___a64_release_i (.Vint 0)

/-- The reached original loop has the actual independent counter and signed
release bounds, with the genuine helper parameter still bound. -/
theorem inputs (entry sp : CC.Block) :
    (temps entry sp).get Arm64Program._entry = some (.Vptr entry 0) ∧
    (temps entry sp).get Arm64Program.___a64_release_old = some (.Vlong (-96#64)) ∧
    (temps entry sp).get Arm64Program.___a64_release_new = some (.Vlong (-32#64)) ∧
    (temps entry sp).get Arm64Program.___a64_release_i = some (.Vint 0) := by
  refine ⟨?_,?_,?_,?_⟩ <;> simp +decide only [temps,releaseTemps,initialTemps,CC.PTree.gss,CC.PTree.gso]

private theorem bias_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State helper readBias k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program._t'239 (.Vlong 96)) m) := by
  simp only [readBias,CC.doStep]
  rw [bias_eval e le m entry hentry bias]

private theorem pointer_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry sp : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0)) :
    CC.doStep world (.State helper readPointer k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program._t'238 (.Vptr sp 0)) m) := by
  simp only [readPointer,CC.doStep]
  rw [pointer_eval e le m entry sp hentry pointer]

private theorem old_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (observed : le.get Arm64Program._t'239 = some (.Vlong 96)) :
    CC.doStep world (.State helper setOld k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program.___a64_release_old (.Vlong (-96#64))) m) := by
  simp only [setOld,CC.doStep,CC.doEvalExpr,observed,CC.Cop.semUnaryOperation,CC.Cop.semNeg,
    CC.Cop.classifyNeg,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tlong,CC.tattr,CC.Integers.Int64.neg,CC.Integers.MI.neg]
  rfl

private theorem new_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sp : CC.Block)
    (pointer : le.get Arm64Program._t'238 = some (.Vptr sp 0))
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    CC.doStep world (.State helper setNew k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program.___a64_release_new (.Vlong (-32#64))) m) := by
  simp only [setNew,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,pointer,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tlong,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint64 m sp 0 with
    | some value => some (CC.E0,CC.State.State helper .Sskip k e
        (le.set Arm64Program.___a64_release_new value) m)
    | none => none) = _
  rw [observed]

private theorem select_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sp : CC.Block) :
    CC.doStep world (.State helper test k e (releaseTemps le sp) m) =
      some (CC.E0,.State helper selected k e (releaseTemps le sp) m) := by
  rw [test_source]
  simp only [CC.doStep]
  rw [condition_eval]
  rfl

/-- Enter the genuine release branch at current SP=-32, initialize its actual
byte counter and reach the original loop on the SAME heap. -/
theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry sp : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0))
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    InternalRun world 20 (.State helper helper.fn_body k e le m)
      (.State helper loop (continuation k) e
        ((releaseTemps le sp).set Arm64Program.___a64_release_i (.Vint 0)) m) := by
  let le1 := le.set Arm64Program._t'239 (.Vlong 96)
  let le2 := le1.set Arm64Program.___a64_release_old (.Vlong (-96#64))
  let le3 := le2.set Arm64Program._t'238 (.Vptr sp 0)
  have entry2 : le2.get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [le2,le1,CC.PTree.gso] using hentry
  rw [helper_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [release_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [release_body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [old_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip _ e le1 m) trivial
    (CC.doStep_sound _ _ _ _ (bias_step e le m _ entry hentry bias)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip _ e le2 m) trivial
    (CC.doStep_sound _ _ _ _ (old_step e le1 m _ (CC.PTree.gss ..))) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [after_old_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [new_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip _ e le3 m) trivial
    (CC.doStep_sound _ _ _ _ (pointer_step e le2 m _ entry sp entry2 pointer)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip _ e (releaseTemps le sp) m) trivial
    (CC.doStep_sound _ _ _ _ (new_step e le3 m _ sp (CC.PTree.gss ..) observed)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (select_step e le m _ sp)) ?_
  rw [selected_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [bytes_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip _ e
    ((releaseTemps le sp).set Arm64Program.___a64_release_i (.Vint 0)) m) trivial
    (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The same completed tag-transfer packet supplies actual header/SP reads;
the original helper call and real allocation-free entry reach its release loop. -/
theorem execute {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6}
    {byte : BitVec 8} {le : CC.TempEnv}
    (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 m le) (before : CC.Mem) (k : CC.Cont) :
    InternalRun world 22 (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
      (Arm64MemsetSource.allocation before).1 le m)
      (.State helper loop (continuation (callCont before le k)) CC.emptyEnv
        (temps entry.block current.ready.storage.sp.block) m) := by
  have first : InternalRun world 1
      (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k (Arm64MemsetSource.allocation before).1 le m)
      (.Callstate (.Internal helper) [.Vptr entry.block 0] (callCont before le k) m) :=
    .step trivial (call_step before m entry.block le k current.ready.entryRead) (.refl _)
  have opened : InternalRun world 1
      (.Callstate (.Internal helper) [.Vptr entry.block 0] (callCont before le k) m)
      (.State helper helper.fn_body (callCont before le k) CC.emptyEnv (initialTemps entry.block) m) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid m entry.block)) (.refl _)
  have bodyRun := enter CC.emptyEnv (initialTemps entry.block) m (callCont before le k) entry.block current.ready.storage.sp.block
    (by simp only [initialTemps,CC.PTree.gss]) current.ready.view.bias current.ready.storage.spPointer
    (by simpa only [current.ready.spAtBase] using current.ready.storage.spRead)
  exact first.trans (opened.trans bodyRun)

end KProgFormal.ClightRefinement.Arm64MemsetClobberEntry
