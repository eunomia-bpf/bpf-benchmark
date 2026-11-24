import KProgFormal.ClightRefinement.Arm64CntReadReduction
import KProgFormal.ClightRefinement.Arm64CntVectorMemory

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cnt.VectorWrite

private structure Pieces where
  lowPath : CC.Stmt
  lowWrites : CC.Stmt
  highChoice : CC.Stmt
  highOther : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original CNT vector-store constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let mut rest := body[1]!
    let mut branch := rest
    for _ in [:38] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      if node.isAppOfArity ``CC.Stmt.Ssequence 2 then
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original CNT dispatch changed"
      branch := node.getAppArgs[1]!
      rest := node.getAppArgs[2]!
    let selected ← peel branch ``CC.Stmt.Ssequence 2
    let low ← peel selected[1]! ``CC.Stmt.Ssequence 2
    let readWrite ← peel low[0]! ``CC.Stmt.Ssequence 2
    let high ← peel low[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_cnt_vector_store_parts
      (← Lean.Meta.mkAppM ``Pieces.mk #[selected[1]!,readWrite[1]!,low[1]!,high[2]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cnt_vector_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def lowPath : CC.Stmt := by run_tac cachePart (← `(pieces.lowPath))
def lowWrites : CC.Stmt := by run_tac cachePart (← `(pieces.lowWrites))
def highChoice : CC.Stmt := by run_tac cachePart (← `(pieces.highChoice))
private def highOther : CC.Stmt := by run_tac cachePart (← `(pieces.highOther))

private def pointerKey (upper : Bool) : CC.Ident := if upper then Arm64Program._t'2832 else Arm64Program._t'2833
private def field (upper : Bool) : CC.Ident := if upper then Arm64Program._vector_hi else Arm64Program._vector_lo
private def fieldOffset (upper : Bool) : Int := if upper then 352 else 96
private def valueKey (upper : Bool) : CC.Ident := if upper then Arm64Program.___a64_red_hi else Arm64Program._t'2792
private def pointer (upper : Bool) : CC.Stmt :=
  .Sset (pointerKey upper)
    (.Ederef (.Ebinop .Oadd
      (.Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
        (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) (field upper) (CC.tarray (CC.tptr CC.tulong) 32))
      (.Econst_int (CC.Integers.Int.repr 0) CC.tint) (CC.tptr (CC.tptr CC.tulong))) (CC.tptr CC.tulong))
private def store (upper : Bool) : CC.Stmt :=
  .Sassign (.Ederef (.Etempvar (pointerKey upper) (CC.tptr CC.tulong)) CC.tulong)
    (.Etempvar (valueKey upper) CC.tulong)
private def condition : CC.Expr :=
  .Ebinop .Oeq (.Etempvar Arm64Program._op CC.tuint) (.Econst_int (CC.Integers.Int.repr 36) CC.tuint) CC.tint

theorem source : lowPath = .Ssequence (.Ssequence (ReductionSite.readPrefix false) lowWrites) highChoice ∧
    lowWrites = .Ssequence (pointer false) (store false) ∧
    highChoice = .Sifthenelse condition (.Ssequence (pointer true) (store true)) highOther := by
  constructor
  · run_tac Arm64ProgramEntryLinked.sourceEquality
  constructor
  · run_tac Arm64ProgramEntryLinked.sourceEquality
  · run_tac Arm64ProgramEntryLinked.sourceEquality

private def entryComposite : CC.Composite :=
  (Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layouts :
    Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    (∀ upper, CC.fieldOffset Arm64ProgramEntryLinked.ge.genv_cenv (field upper) entryComposite.co_members =
      .OK (fieldOffset upper,.Full)) ∧
    CC.sizeof Arm64ProgramEntryLinked.ge.genv_cenv (CC.tptr CC.tulong) = 8 := by
  constructor
  · decide +kernel
  constructor
  · intro upper; cases upper <;> decide +kernel
  · decide +kernel

private theorem pointer_step (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr (fieldOffset upper))) = some (.Vptr vb vo)) :
    CC.Step2 Arm64ProgramEntryLinked.ge (.State Arm64Nop.handler (pointer upper) k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set (pointerKey upper) (.Vptr vb vo)) m) := by
  apply CC.doStep_sound
  simp +decide only [pointer,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfField,CC.typeof,entry,
    CC.doDerefLoc,CC.accessMode,CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,CC.tulong,
    CC.tptr,CC.tarray,CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,ite_true,ite_false,
    layouts.1,layouts.2.1 upper,layouts.2.2,CC.Val.offsetPtr,CC.Cop.ptrofsOfInt,
    CC.Integers.Ptrofs.of_intu,CC.Integers.Ptrofs.of_int,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
    CC.Integers.MI.add,CC.Integers.MI.mul] <;> try rfl
  change (match CC.Mem.loadv CC.Mptr m (.Vptr b
      ((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (fieldOffset upper) +
        CC.Integers.Ptrofs.repr 8 * BitVec.signExtend CC.Archi.ptrWordsize (0#32))) with
    | some value => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e (le.set (pointerKey upper) value) m)
    | none => none) = _
  have offset : (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (fieldOffset upper) +
      CC.Integers.Ptrofs.repr 8 * BitVec.signExtend CC.Archi.ptrWordsize (0#32) =
      CC.Integers.Ptrofs.repr (fieldOffset upper) := by cases upper <;> decide +kernel
  rw [offset,slot]

private theorem store_step (upper : Bool) (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (before after : CC.Mem) (k : CC.Cont) (vb : CC.Block) (value : BitVec 64)
    (ptr : le.get (pointerKey upper) = some (.Vptr vb (CC.Integers.Ptrofs.repr (if upper then 8 else 0))))
    (word : le.get (valueKey upper) = some (.Vlong value))
    (written : CC.Mem.store .Mint64 before vb (if upper then 8 else 0) (.Vlong value) = some after) :
    CC.Step2 world (.State Arm64Nop.handler (store upper) k e le before) CC.E0
      (.State Arm64Nop.handler .Sskip k e le after) := by
  apply CC.doStep_sound
  simp +decide only [store,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.typeof,ptr,word,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
    CC.doAssignLoc,CC.accessMode,CC.Mem.storev,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,
    CC.Archi.ptr64,ite_true,ite_false]
  change (match CC.Mem.store .Mint64 before vb
      (CC.Integers.Ptrofs.repr (if upper then 8 else 0)).toNat (.Vlong value) with
    | some m => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e le m)
    | none => none) = _
  have offset : ((CC.Integers.Ptrofs.repr (if upper then 8 else 0)).toNat : Int) =
      (if upper then 8 else 0) := by cases upper <;> decide +kernel
  rw [offset,written]

def temps (le : CC.TempEnv) (vb : CC.Block) : CC.TempEnv :=
  (le.set Arm64Program._t'2833 (.Vptr vb (CC.Integers.Ptrofs.repr 0))).set
    Arm64Program._t'2832 (.Vptr vb (CC.Integers.Ptrofs.repr 8))

set_option hygiene false in
/-- The original low pointer/store and high choice/pointer/store execute
in their actual caller continuation, using the same two-store memory effect. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (before after : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (lowValue highValue : BitVec 64)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (op : le.get Arm64Program._op = some (.Vint (36#32)))
    (lowResult : le.get Arm64Program._t'2792 = some (.Vlong lowValue))
    (highResult : le.get Arm64Program.___a64_red_hi = some (.Vlong highValue))
    (low : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.repr 96)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 0)))
    (high : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.repr 352)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 8)))
    (separate : b ≠ vb) (effect : VectorMemory.Effect before after vb lowValue highValue) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler lowWrites (.Kseq highChoice k) e le before)
      (.State Arm64Nop.handler .Sskip k e (temps le vb) after) := by
  obtain ⟨middle,lowStoreDone,highStoreDone⟩ := effect
  have highMiddle : CC.Mem.loadv CC.Mptr middle (.Vptr b (CC.Integers.Ptrofs.repr 352)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 8)) := by
    change CC.Mem.load CC.Mptr middle b _ = _
    rw [CC.Mem.load_store_other lowStoreDone CC.Mptr b _ (.inl separate)]
    exact high
  rw [source.2.1]
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:16] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``CC.Stmt.Sskip &&
          state.getAppArgs[2]! == (← Lean.Elab.Term.elabTerm (← `(k)) none) then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual CNT vector writes transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt := state.getAppArgs[1]!
        if stmt.isAppOfArity ``pointer 1 then
          let upper := stmt.getAppArgs[0]!.isConstOf ``Bool.true
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          if upper then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply pointer_step true (b := b) (vb := vb) (vo := CC.Integers.Ptrofs.repr 8)))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply pointer_step false (b := b) (vb := vb) (vo := CC.Integers.Ptrofs.repr 0)))
          Lean.Elab.Tactic.evalTactic (← `(tactic| repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact entry))
          if upper then Lean.Elab.Tactic.evalTactic (← `(tactic| exact highMiddle))
          else Lean.Elab.Tactic.evalTactic (← `(tactic| exact low))
          continue
        if stmt.isAppOfArity ``store 1 then
          let upper := stmt.getAppArgs[0]!.isConstOf ``Bool.true
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          if upper then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply store_step true (vb := vb) (value := highValue)))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply store_step false (vb := vb) (value := lowValue)))
          Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [pointerKey,ite_true,ite_false,Bool.false_eq_true,CC.PTree.gss]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [valueKey,ite_true,ite_false,Bool.false_eq_true]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]))
          if upper then
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact highResult))
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact highStoreDone))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact lowResult))
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact lowStoreDone))
          continue
        if stmt.isConstOf ``highChoice then
          Lean.Elab.Tactic.evalTactic (← `(tactic| rw [source.2.2]))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,condition,CC.doEvalExpr,
        pointerKey,Bool.false_eq_true,
        CC.PTree.gso Arm64Program._t'2833 Arm64Program._op _ _ (by decide +kernel),op,CC.typeof,
        CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
        CC.Cop.semCast,CC.Cop.classifyCast,
        CC.Cop.binarithType,CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,
        CC.tattr,CC.tuint,CC.tint,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
        CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.repr,CC.Integers.MI.repr,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Archi.ptr64,ite_true,ite_false] <;> try rfl))
    unless finished do throwError "original CNT vector writes still have transitions"

theorem retained (le : CC.TempEnv) (vb : CC.Block) (id : CC.Ident)
    (lowOther : id ≠ Arm64Program._t'2833) (highOther : id ≠ Arm64Program._t'2832) :
    (temps le vb).get id = le.get id :=
  (CC.PTree.gso _ _ _ _ (Ne.symm highOther)).trans (CC.PTree.gso _ _ _ _ (Ne.symm lowOther))

end KProgFormal.ClightRefinement.Arm64Cnt.VectorWrite
