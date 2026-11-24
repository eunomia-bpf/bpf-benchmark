import KProgFormal.ClightRefinement.Arm64CntVectorWrite
import KProgFormal.ClightRefinement.Arm64UaddlvVectorMemory

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.VectorWrite

abbrev lowPath := Arm64Cnt.VectorWrite.lowPath
abbrev lowWrites := Arm64Cnt.VectorWrite.lowWrites
abbrev highChoice := Arm64Cnt.VectorWrite.highChoice

private def field (upper : Bool) : CC.Ident := if upper then Arm64Program._vector_hi else Arm64Program._vector_lo
private def fieldOffset (upper : Bool) : Int := if upper then 352 else 96
private def valueKey (upper : Bool) : CC.Ident := if upper then Arm64Program.___a64_red_hi else Arm64Program._t'2792
private def pointer (key : CC.Ident) (upper : Bool) : CC.Stmt :=
  .Sset key
    (.Ederef (.Ebinop .Oadd
      (.Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
        (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) (field upper) (CC.tarray (CC.tptr CC.tulong) 32))
      (.Econst_int (CC.Integers.Int.repr 0) CC.tint) (CC.tptr (CC.tptr CC.tulong))) (CC.tptr CC.tulong))

private def word : CC.Stmt :=
  .Sset Arm64Program._t'2831 (.Ederef (.Etempvar Arm64Program._t'2830 (CC.tptr CC.tulong)) CC.tulong)
private def assign (key : CC.Ident) (rhs : CC.Expr) : CC.Stmt :=
  .Sassign (.Ederef (.Etempvar key (CC.tptr CC.tulong)) CC.tulong) rhs
private def lowValue : CC.Expr := .Etempvar Arm64Program._t'2792 CC.tulong
private def sumValue : CC.Expr :=
  .Ebinop .Oadd (.Etempvar Arm64Program._t'2831 CC.tulong)
    (.Etempvar Arm64Program.___a64_red_hi CC.tulong) CC.tulong
private def zeroValue : CC.Expr := .Econst_int (CC.Integers.Int.repr 0) CC.tint
private def condition : CC.Expr :=
  .Ebinop .Oeq (.Etempvar Arm64Program._op CC.tuint)
    (.Econst_int (CC.Integers.Int.repr 36) CC.tuint) CC.tint
private def sumWrites : CC.Stmt :=
  .Ssequence
    (.Ssequence (pointer Arm64Program._t'2829 false)
      (.Ssequence (pointer Arm64Program._t'2830 false)
        (.Ssequence word (assign Arm64Program._t'2829 sumValue))))
    (.Ssequence (pointer Arm64Program._t'2828 true) (assign Arm64Program._t'2828 zeroValue))

/-- The statements are the actual shared branch: partial low store, original
opcode choice, two low pointers, low reload, accumulation store, then high zero. -/
theorem source : lowPath = .Ssequence (.Ssequence (Arm64Cnt.ReductionSite.readPrefix false) lowWrites) highChoice ∧
    lowWrites = .Ssequence (pointer Arm64Program._t'2833 false) (assign Arm64Program._t'2833 lowValue) ∧
    highChoice = .Sifthenelse condition
      (.Ssequence (pointer Arm64Program._t'2832 true)
        (assign Arm64Program._t'2832 (.Etempvar Arm64Program.___a64_red_hi CC.tulong))) sumWrites := by
  constructor
  · run_tac Arm64ProgramEntryLinked.sourceEquality
  constructor
  · run_tac Arm64ProgramEntryLinked.sourceEquality
  run_tac Arm64ProgramEntryLinked.sourceEquality

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

private theorem pointer_step (key : CC.Ident) (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr (fieldOffset upper))) = some (.Vptr vb vo)) :
    CC.Step2 Arm64ProgramEntryLinked.ge (.State Arm64Nop.handler (pointer key upper) k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set key (.Vptr vb vo)) m) := by
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
    | some value => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e (le.set key value) m)
    | none => none) = _
  have offset : (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (fieldOffset upper) +
      CC.Integers.Ptrofs.repr 8 * BitVec.signExtend CC.Archi.ptrWordsize (0#32) =
      CC.Integers.Ptrofs.repr (fieldOffset upper) := by cases upper <;> decide +kernel
  rw [offset,slot]


private theorem word_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (vb : CC.Block) (value : BitVec 64)
    (ptr : le.get Arm64Program._t'2830 = some (.Vptr vb (CC.Integers.Ptrofs.repr 0)))
    (loaded : CC.Mem.load .Mint64 m vb 0 = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler word k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program._t'2831 (.Vlong value)) m) := by
  apply CC.doStep_sound
  simp only [word,CC.doStep,CC.doEvalExpr,ptr,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint64 m vb 0 with
    | some value => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e
        (le.set Arm64Program._t'2831 value) m)
    | none => none) = _
  rw [loaded]

private theorem assign_step (key : CC.Ident) (upper : Bool) (rhs : CC.Expr)
    (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (before after : CC.Mem) (k : CC.Cont)
    (vb : CC.Block) (value : BitVec 64) (input : CC.Val)
    (ptr : le.get key = some (.Vptr vb (CC.Integers.Ptrofs.repr (if upper then 8 else 0))))
    (evaluated : CC.doEvalExpr world e le before rhs = some input)
    (casted : CC.Cop.semCast input (CC.typeof rhs) CC.tulong before = some (.Vlong value))
    (written : CC.Mem.store .Mint64 before vb (if upper then 8 else 0) (.Vlong value) = some after) :
    CC.Step2 world (.State Arm64Nop.handler (assign key rhs) k e le before) CC.E0
      (.State Arm64Nop.handler .Sskip k e le after) := by
  apply CC.doStep_sound
  have lvalue : CC.doEvalLvalue world e le before
      (.Ederef (.Etempvar key (CC.tptr CC.tulong)) CC.tulong) =
      some (vb,CC.Integers.Ptrofs.repr (if upper then 8 else 0),CC.Bitfield.Full) := by
    simp only [CC.doEvalLvalue,CC.doEvalExpr,ptr]
  simp only [assign,CC.doStep,lvalue,evaluated]
  have targetType : CC.typeof (.Ederef (.Etempvar key (CC.tptr CC.tulong)) CC.tulong) = CC.tulong := rfl
  rw [targetType,casted]
  change (match CC.Mem.store .Mint64 before vb
      (CC.Integers.Ptrofs.repr (if upper then 8 else 0)).toNat (.Vlong value) with
    | some m => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e le m)
    | none => none) = _
  have offset : ((CC.Integers.Ptrofs.repr (if upper then 8 else 0)).toNat : Int) =
      (if upper then 8 else 0) := by cases upper <;> decide +kernel
  rw [offset,written]

def temps (le : CC.TempEnv) (vb : CC.Block) (low : BitVec 64) : CC.TempEnv :=
  ((((le.set Arm64Program._t'2833 (.Vptr vb (CC.Integers.Ptrofs.repr 0))).set
    Arm64Program._t'2829 (.Vptr vb (CC.Integers.Ptrofs.repr 0))).set
    Arm64Program._t'2830 (.Vptr vb (CC.Integers.Ptrofs.repr 0))).set
    Arm64Program._t'2831 (.Vlong low)).set
    Arm64Program._t'2828 (.Vptr vb (CC.Integers.Ptrofs.repr 8))

set_option hygiene false in
/-- Execute every original pointer, reload and all three real assignments,
in their actual continuation, with the exact three-store heap effect. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (before after : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (lowValue64 highValue64 : BitVec 64)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (op : le.get Arm64Program._op = some (.Vint (37#32)))
    (lowResult : le.get Arm64Program._t'2792 = some (.Vlong lowValue64))
    (highResult : le.get Arm64Program.___a64_red_hi = some (.Vlong highValue64))
    (low : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.repr 96)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 0)))
    (high : CC.Mem.loadv CC.Mptr before (.Vptr b (CC.Integers.Ptrofs.repr 352)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 8)))
    (separate : b ≠ vb) (effect : VectorMemory.Effect before after vb lowValue64 highValue64) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler lowWrites (.Kseq highChoice k) e le before)
      (.State Arm64Nop.handler .Sskip k e (temps le vb lowValue64) after) := by
  obtain ⟨first,middle,partialStore,sumStore,zeroStore⟩ := effect
  have lowFirst : CC.Mem.loadv CC.Mptr first (.Vptr b (CC.Integers.Ptrofs.repr 96)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 0)) := by
    change CC.Mem.load CC.Mptr first b _ = _
    rw [CC.Mem.load_store_other partialStore CC.Mptr b _ (.inl separate)]
    exact low
  have highMiddle : CC.Mem.loadv CC.Mptr middle (.Vptr b (CC.Integers.Ptrofs.repr 352)) =
      some (.Vptr vb (CC.Integers.Ptrofs.repr 8)) := by
    change CC.Mem.load CC.Mptr middle b _ = _
    rw [CC.Mem.load_store_other sumStore CC.Mptr b _ (.inl separate),
      CC.Mem.load_store_other partialStore CC.Mptr b _ (.inl separate)]
    exact high
  have reload := CC.Mem.load_store_same partialStore
  have choiceSource := source.2.2
  rw [source.2.1]
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:40] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``CC.Stmt.Sskip &&
          state.getAppArgs[2]! == (← Lean.Elab.Term.elabTerm (← `(k)) none) then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual UADDLV three-store transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt := state.getAppArgs[1]!
        Lean.logInfo m!"UADDLV store source stage {i}: {stmt.getAppFn.constName?}"
        if stmt.isAppOfArity ``pointer 2 then
          let key := stmt.getAppArgs[0]!
          let upper := stmt.getAppArgs[1]!.isConstOf ``Bool.true
          let original := key.isConstOf ``Arm64Program._t'2833
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          if upper then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply pointer_step _ true (b := b) (vb := vb) (vo := CC.Integers.Ptrofs.repr 8)))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply pointer_step _ false (b := b) (vb := vb) (vo := CC.Integers.Ptrofs.repr 0)))
          Lean.Elab.Tactic.evalTactic (← `(tactic| repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact entry))
          if upper then Lean.Elab.Tactic.evalTactic (← `(tactic| exact highMiddle))
          else if original then Lean.Elab.Tactic.evalTactic (← `(tactic| exact low))
          else Lean.Elab.Tactic.evalTactic (← `(tactic| exact lowFirst))
          continue
        if stmt.isConstOf ``word then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply word_step (vb := vb) (value := lowValue64)))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact CC.PTree.gss _ _ _))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact reload))
          continue
        if stmt.isAppOfArity ``assign 2 then
          let key := stmt.getAppArgs[0]!
          let isZero := key.isConstOf ``Arm64Program._t'2828
          let isLow := key.isConstOf ``Arm64Program._t'2833
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          if isZero then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply assign_step _ true _ (vb := vb) (value := 0#64) (input := .Vint (0#32))))
          else if isLow then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply assign_step _ false _ (vb := vb) (value := lowValue64) (input := .Vlong lowValue64)))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply assign_step _ false _ (vb := vb) (value := lowValue64+highValue64) (input := .Vlong (lowValue64+highValue64))))
          Lean.Elab.Tactic.evalTactic (← `(tactic| repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact CC.PTree.gss _ _ _))
          Lean.Elab.Tactic.evalTactic (← `(tactic| solve
            | simp only [lowValue,sumValue,zeroValue,CC.doEvalExpr,
                CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Val.addl,
                CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
                CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,
                CC.Cop.classifyCast,CC.PTree.gss]
              repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
              try simp only [CC.PTree.gss,lowResult,highResult]
              try rfl))
          Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
          if isZero then Lean.Elab.Tactic.evalTactic (← `(tactic| exact zeroStore))
          else if isLow then Lean.Elab.Tactic.evalTactic (← `(tactic| exact partialStore))
          else Lean.Elab.Tactic.evalTactic (← `(tactic| exact sumStore))
          continue
        if stmt.isConstOf ``highChoice || stmt.isConstOf ``Arm64Cnt.VectorWrite.highChoice then
          Lean.Elab.Tactic.evalTactic (← `(tactic| rw [choiceSource]))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,condition,CC.doEvalExpr,
        CC.PTree.gso Arm64Program._t'2833 Arm64Program._op _ _ (by decide +kernel),op,CC.typeof,
        CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
        CC.Cop.binarithType,CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,
        CC.tattr,CC.tuint,CC.tint,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
        CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.repr,CC.Integers.MI.repr,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Archi.ptr64,ite_true,ite_false]))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    unless finished do throwError "actual UADDLV store continuation did not finish"

theorem retained (le : CC.TempEnv) (vb : CC.Block) (low : BitVec 64) (id : CC.Ident)
    (a : id ≠ Arm64Program._t'2833) (b : id ≠ Arm64Program._t'2829)
    (c : id ≠ Arm64Program._t'2830) (d : id ≠ Arm64Program._t'2831) (e : id ≠ Arm64Program._t'2828) :
    (temps le vb low).get id = le.get id := by
  unfold temps
  rw [CC.PTree.gso _ _ _ _ e.symm,CC.PTree.gso _ _ _ _ d.symm,
    CC.PTree.gso _ _ _ _ c.symm,CC.PTree.gso _ _ _ _ b.symm,CC.PTree.gso _ _ _ _ a.symm]

end KProgFormal.ClightRefinement.Arm64Uaddlv.VectorWrite
