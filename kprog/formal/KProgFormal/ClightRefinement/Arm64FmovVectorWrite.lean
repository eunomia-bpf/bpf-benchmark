import KProgFormal.ClightRefinement.Arm64FmovStoreEntry
import KProgFormal.ClightRefinement.Arm64FmovVectorMemory

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Fmov.VectorWrite

private structure Pieces where
  choice : CC.Stmt
  full : CC.Stmt
  lowPointer : CC.Stmt
  lowStore : CC.Stmt
  highPointer : CC.Stmt
  highStore : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original FMOV vector-store constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(DestinationSite.vectorStores)) none) ``CC.Stmt.Ssequence 2
    let low ← peel root[0]! ``CC.Stmt.Ssequence 2
    let choose ← peel low[0]! ``CC.Stmt.Sifthenelse 3
    let lowStore ← peel low[1]! ``CC.Stmt.Ssequence 2
    let highStore ← peel root[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_fmov_vector_stores
      (← Lean.Meta.mkAppM ``Pieces.mk #[low[0]!,choose[2]!,lowStore[0]!,lowStore[1]!,highStore[0]!,highStore[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_fmov_vector_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def choice : CC.Stmt := by run_tac cachePart (← `(pieces.choice))
private def full : CC.Stmt := by run_tac cachePart (← `(pieces.full))
private def lowPointer : CC.Stmt := by run_tac cachePart (← `(pieces.lowPointer))
private def lowStore : CC.Stmt := by run_tac cachePart (← `(pieces.lowStore))
private def highPointer : CC.Stmt := by run_tac cachePart (← `(pieces.highPointer))
private def highStore : CC.Stmt := by run_tac cachePart (← `(pieces.highStore))

theorem source : DestinationSite.vectorStores =
    .Ssequence (.Ssequence choice (.Ssequence lowPointer lowStore)) (.Ssequence highPointer highStore) := rfl

private def pointerKey (high : Bool) : CC.Ident := if high then Arm64Program._t'2838 else Arm64Program._t'2839
private def pointer (high : Bool) : CC.Stmt := if high then highPointer else lowPointer
private def field (high : Bool) : CC.Ident := if high then Arm64Program._vector_hi else Arm64Program._vector_lo
private def fieldOffset (high : Bool) : Int := if high then 352 else 96
private def slotOffset (high : Bool) : Int := if high then 376 else 120
private theorem pointer_source (high : Bool) : pointer high = .Sset (pointerKey high)
    (.Ederef (.Ebinop .Oadd
      (.Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
        (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) (field high) (CC.tarray (CC.tptr CC.tulong) 32))
      (.Etempvar Arm64Program.___a64_fmov_index CC.tuint) (CC.tptr (CC.tptr CC.tulong))) (CC.tptr CC.tulong)) := by
  cases high
  all_goals run_tac Arm64ProgramEntryLinked.sourceEquality

private def entryComposite : CC.Composite :=
  (Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layouts :
    Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    (∀ high, CC.fieldOffset Arm64ProgramEntryLinked.ge.genv_cenv (field high) entryComposite.co_members =
      .OK (fieldOffset high,.Full)) ∧
    CC.sizeof Arm64ProgramEntryLinked.ge.genv_cenv (CC.tptr CC.tulong) = 8 := by
  constructor
  · decide +kernel
  constructor
  · intro high; cases high <;> decide +kernel
  · decide +kernel
private theorem pointer_offset (high : Bool) :
    (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (fieldOffset high) +
      CC.Integers.Ptrofs.repr 8 * BitVec.zeroExtend CC.Archi.ptrWordsize (3#32) =
      CC.Integers.Ptrofs.repr (slotOffset high) := by cases high <;> decide +kernel

private theorem pointer_step (high : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (index : le.get Arm64Program.___a64_fmov_index = some (.Vint (3#32)))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr (slotOffset high))) = some (.Vptr vb vo)) :
    CC.Step2 Arm64ProgramEntryLinked.ge (.State Arm64Nop.handler (pointer high) k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set (pointerKey high) (.Vptr vb vo)) m) := by
  apply CC.doStep_sound
  simp +decide only [pointer_source,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfField,CC.typeof,
    entry,index,CC.doDerefLoc,CC.accessMode,CC.Cop.semBinaryOperation,CC.Cop.semAdd,
    CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong,CC.tptr,CC.tarray,CC.Archi.ptr64,CC.Archi.ptrWordsize,
    CC.sizeof,ite_true,ite_false,layouts.1,layouts.2.1 high,layouts.2.2,CC.Val.offsetPtr,CC.Cop.ptrofsOfInt,
    CC.Integers.Ptrofs.of_intu,CC.Integers.Ptrofs.of_int,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
    CC.Integers.MI.add,CC.Integers.MI.mul] <;> try rfl
  change (match CC.Mem.loadv CC.Mptr m (.Vptr b
      ((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (fieldOffset high) +
        CC.Integers.Ptrofs.repr 8 * BitVec.zeroExtend CC.Archi.ptrWordsize (3#32))) with
    | some value => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e (le.set (pointerKey high) value) m)
    | none => none) = _
  rw [pointer_offset,slot]

private theorem low_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (before after : CC.Mem)
    (k : CC.Cont) (vb : CC.Block) (value : BitVec 64)
    (ptr : le.get Arm64Program._t'2839 = some (.Vptr vb (CC.Integers.Ptrofs.repr 48)))
    (word : le.get Arm64Program._t'2788 = some (.Vlong value))
    (written : CC.Mem.store .Mint64 before vb 48 (.Vlong value) = some after) :
    CC.Step2 world (.State Arm64Nop.handler lowStore k e le before) CC.E0
      (.State Arm64Nop.handler .Sskip k e le after) := by
  apply CC.doStep_sound
  simp +decide only [lowStore,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.typeof,ptr,word,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
    CC.doAssignLoc,CC.accessMode,CC.Mem.storev,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Archi.ptr64,ite_true,ite_false]
  change (match CC.Mem.store .Mint64 before vb 48 (.Vlong value) with
    | some m => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e le m)
    | none => none) = _
  rw [written]

private theorem high_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (before after : CC.Mem)
    (k : CC.Cont) (vb : CC.Block)
    (ptr : le.get Arm64Program._t'2838 = some (.Vptr vb (CC.Integers.Ptrofs.repr 56)))
    (written : CC.Mem.store .Mint64 before vb 56 (.Vlong 0) = some after) :
    CC.Step2 world (.State Arm64Nop.handler highStore k e le before) CC.E0
      (.State Arm64Nop.handler .Sskip k e le after) := by
  apply CC.doStep_sound
  simp +decide only [highStore,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.typeof,ptr,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,CC.tulong,
    CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.Int64.repr,CC.Integers.Int.repr,CC.Integers.MI.repr,
    CC.doAssignLoc,CC.accessMode,CC.Mem.storev,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Archi.ptr64,ite_true,ite_false]
  change (match CC.Mem.store .Mint64 before vb 56 (.Vlong 0) with
    | some m => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e le m)
    | none => none) = _
  rw [written]

def temps (le : CC.TempEnv) (vb : CC.Block) (value : BitVec 64) : CC.TempEnv :=
  ((le.set Arm64Program._t'2788 (.Vlong value)).set Arm64Program._t'2839 (.Vptr vb (CC.Integers.Ptrofs.repr 48))).set
    Arm64Program._t'2838 (.Vptr vb (CC.Integers.Ptrofs.repr 56))

set_option hygiene false in
/-- Execute the original choice, both real pointer loads and both assignments
in order, with their actual store effect and original continuation. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (before after : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (value : BitVec 64)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (index : le.get Arm64Program.___a64_fmov_index = some (.Vint (3#32)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (result : le.get Arm64Program.___a64_fmov_result = some (.Vlong value))
    (low : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.repr 120)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 48)))
    (high : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.repr 376)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 56)))
    (separate : b ≠ vb) (effect : VectorMemory.Effect before after vb value) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler DestinationSite.vectorStores k e le before)
      (.State Arm64Nop.handler .Sskip k e (temps le vb value) after) := by
  obtain ⟨middle,lowStoreDone,highStoreDone⟩ := effect
  have highMiddle : CC.Mem.loadv CC.Mptr middle (.Vptr b (CC.Integers.Ptrofs.repr 376)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 56)) := by
    change CC.Mem.load CC.Mptr middle b _ = _
    rw [CC.Mem.load_store_other lowStoreDone CC.Mptr b _ (.inl separate)]
    exact high
  rw [source]
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:60] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``CC.Stmt.Sskip &&
          state.getAppArgs[2]! == (← Lean.Elab.Term.elabTerm (← `(k)) none) then
        Lean.Elab.Tactic.evalTactic (← `(tactic| try simp only [pointerKey,Bool.false_eq_true,ite_false,ite_true]))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual FMOV vector stores transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt := state.getAppArgs[1]!
        if stmt.isConstOf ``lowPointer || stmt.isConstOf ``highPointer then
          let high := stmt.isConstOf ``highPointer
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          if high then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply pointer_step true (b := b) (vb := vb) (vo := CC.Integers.Ptrofs.repr 56)))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply pointer_step false (b := b) (vb := vb) (vo := CC.Integers.Ptrofs.repr 48)))
          Lean.Elab.Tactic.evalTactic (← `(tactic| try simp only [pointerKey,Bool.false_eq_true,ite_false,ite_true]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact entry))
          Lean.Elab.Tactic.evalTactic (← `(tactic| try simp only [pointerKey,Bool.false_eq_true,ite_false,ite_true]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact index))
          if high then Lean.Elab.Tactic.evalTactic (← `(tactic| exact highMiddle))
          else Lean.Elab.Tactic.evalTactic (← `(tactic| exact low))
          continue
        if stmt.isConstOf ``lowStore || stmt.isConstOf ``highStore then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          if stmt.isConstOf ``highStore then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply high_step (vb := vb)))
            Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [pointerKey,Bool.false_eq_true,ite_false,ite_true,CC.PTree.gss]))
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact highStoreDone))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply low_step (vb := vb) (value := value)))
            Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [pointerKey,Bool.false_eq_true,ite_false,ite_true,CC.PTree.gss]))
            Lean.Elab.Tactic.evalTactic (← `(tactic| try simp only [pointerKey,Bool.false_eq_true,ite_false,ite_true]; rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]; exact CC.PTree.gss _ _ _))
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact lowStoreDone))
          continue
        if let .const name _ := stmt then
          if let .defnInfo _ ← Lean.getConstInfo name then
            let alias := Lean.mkIdent name
            Lean.Elab.Tactic.evalTactic (← `(tactic| unfold $alias:ident))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,full,CC.doEvalExpr,aux,result,CC.typeof,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,
        CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.boolVal,CC.Cop.classifyBool,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tint,CC.tulong,
        CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.eq,CC.Integers.MI.eq,
        CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
        CC.Archi.ptr64,ite_true,ite_false,CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
    unless finished do throwError "original FMOV vector stores still have transitions"

/-- Three real temporary assignments retain the original inputs and result. -/
theorem retained (le : CC.TempEnv) (vb : CC.Block) (value : BitVec 64) :
    ∀ id ∈ Arm64Fmov.Numeric.retained ++ [Arm64Program.___a64_fmov_result],
      (temps le vb value).get id = le.get id := by
  intro id inside
  have distinct : ∀ key ∈ [Arm64Program._t'2788,Arm64Program._t'2839,Arm64Program._t'2838], key ≠ id := by
    have outside : ∀ key ∈ [Arm64Program._t'2788,Arm64Program._t'2839,Arm64Program._t'2838],
        key ∉ Arm64Fmov.Numeric.retained ++ [Arm64Program.___a64_fmov_result] := by decide +kernel
    intro key member same
    exact (outside key member) (same.symm ▸ inside)
  unfold temps
  rw [CC.PTree.gso _ _ _ _ (distinct _ (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (distinct _ (by decide +kernel)),CC.PTree.gso _ _ _ _ (distinct _ (by decide +kernel))]

end KProgFormal.ClightRefinement.Arm64Fmov.VectorWrite
