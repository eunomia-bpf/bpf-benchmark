import KProgFormal.ClightRefinement.Arm64CiliumCallerR30Tag

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerReturnProvider
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)

private structure Parts where
  body : CC.Stmt
  spBranch : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual RETURN materialization changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerR30Tag.after)) none
    let loop ← peel original ``CC.Stmt.Sloop 2
    let value ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let tag ← peel value[1]! ``CC.Stmt.Ssequence 2
    let tail ← peel tag[1]! ``CC.Stmt.Ssequence 2
    let choose ← peel tail[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_return_materialization
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,choose[1]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerR30Tag.after
noncomputable def body : CC.Stmt := parts.body
noncomputable def calleeExpr : CC.Expr :=
  .Evar _native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default)
noncomputable def argumentExprs : List CC.Expr := [.Econst_int (CC.Integers.Int.repr 3) CC.tint]
noncomputable def call : CC.Stmt := .Scall (some _t'157) calleeExpr argumentExprs
noncomputable def assignReturn : CC.Stmt :=
  .Sassign (.Evar ___a64_numeric_return CC.tulong) (.Etempvar _t'157 CC.tulong)
noncomputable def assignValid : CC.Stmt :=
  .Sassign (.Evar ___a64_numeric_return_valid CC.tuchar) (.Econst_int (CC.Integers.Int.repr 1) CC.tint)
noncomputable def setBase : CC.Stmt :=
  .Sset ___a64_mat_base__3 (.Evar ___a64_numeric_return CC.tulong)
noncomputable def returnBody : CC.Stmt := .Ssequence
  (.Ssequence (.Sset _t'13881 (.Evar ___a64_numeric_return_valid CC.tuchar))
    (.Sifthenelse (.Eunop .Onotbool (.Etempvar _t'13881 CC.tuchar) CC.tint)
      (.Ssequence (.Ssequence call assignReturn) assignValid) .Sskip)) setBase
noncomputable def addValue : CC.Stmt := .Sset ___a64_mat_value__1
  (.Ebinop .Oadd (.Etempvar ___a64_mat_value__1 CC.tulong)
    (.Etempvar ___a64_mat_base__3 CC.tulong) CC.tulong)
noncomputable def storeValue : CC.Stmt :=
  .Sset ___a64_store_value (.Etempvar ___a64_mat_value__1 CC.tulong)

theorem source : stage = .Sloop body .Sbreak := rfl
theorem body_source : body = .Ssequence
    (.Sset ___a64_mat_value__1 (.Etempvar ___a64_read_value__1 CC.tulong))
    (.Ssequence
      (.Sset ___a64_mat_tag__1 (.Ecast (.Etempvar ___a64_read_tag__1 CC.tuchar) CC.tuchar))
      (.Ssequence
        (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_mat_tag__1 CC.tuchar)
            (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint)
          parts.spBranch
          (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_mat_tag__1 CC.tuchar)
              (.Econst_int (CC.Integers.Int.repr 10) CC.tuint) CC.tint)
            (.Ssequence (.Sloop returnBody .Sbreak) addValue) .Sskip))
        storeValue)) := rfl
theorem return_source : returnBody = s_trusted_arm64_arm64_sim_xdp_55 := rfl

noncomputable def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq assignReturn (.Kseq assignValid (.Kseq setBase
    (.Kloop1 returnBody .Sbreak (.Kseq addValue (.Kseq storeValue (.Kloop1 body .Sbreak k))))))
noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  CC.PTree.set _t'13881 (CC.Val.Vint (0#32))
    (CC.PTree.set ___a64_mat_tag__1 (CC.Val.Vint (10#32))
      (CC.PTree.set ___a64_mat_value__1 (CC.Val.Vlong (0#64)) le))

/-- The actual default RETURN-valid local is separate from the SP cell just written. -/
theorem valid_frame {m before : CC.Mem} {header : Header m} {sources : Sources m} {scalars : Locals m}
    (result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars)
    (locals : Arm64CiliumCallerDefaults.Locals m)
    (zero : CC.Mem.load .Mint8unsigned before (locals.block 5) 0 = some (.Vint (0#32))) :
    CC.Mem.load .Mint8unsigned result.after (locals.block 5) 0 = some (.Vint (0#32)) :=
  (Arm64CiliumCallerSPGPRFrame.bound_frame result (locals.binding 5)
    (by decide +kernel) .Mint8unsigned 0).trans zero

theorem valid_value {m memory : CC.Mem} (locals : Arm64CiliumCallerDefaults.Locals m)
    (zero : CC.Mem.load .Mint8unsigned memory (locals.block 5) 0 = some (.Vint (0#32)))
    (le : CC.TempEnv) :
    CC.doEvalExpr ge (allocation m).1 le memory (.Evar ___a64_numeric_return_valid CC.tuchar) =
      some (.Vint (0#32)) := by
  have binding : (allocation m).1.get ___a64_numeric_return_valid = some (locals.block 5,CC.tuchar) :=
    locals.binding 5
  simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
  change CC.Mem.load .Mint8unsigned memory (locals.block 5) 0 = _
  exact zero


private theorem temp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem tag_survives (le : CC.TempEnv) :
    (CC.PTree.set ___a64_mat_value__1 (CC.Val.Vlong (0#64)) le).get ___a64_read_tag__1 =
      le.get ___a64_read_tag__1 :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem tag_cast (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_read_tag__1 = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar ___a64_read_tag__1 CC.tuchar) CC.tuchar) =
      some (.Vint (10#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem eq_four (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_mat_tag__1 = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq (.Etempvar ___a64_mat_tag__1 CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem eq_ten (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_mat_tag__1 = some (.Vint (10#32))) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oeq (.Etempvar ___a64_mat_tag__1 CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 10) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem not_valid (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'13881 = some (.Vint (0#32))) :
    CC.doEvalExpr ge e le memory (.Eunop .Onotbool (.Etempvar _t'13881 CC.tuchar) CC.tint) =
      some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem binop_type (op : CC.Binop) (a b : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Ebinop op a b ty) = ty := rfl
private theorem unop_type (op : CC.Unop) (a : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Eunop op a ty) = ty := rfl
private theorem bools (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false ∧
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := ⟨rfl,rfl⟩

/-- Nineteen original internal steps read the actual valid0 and reach the actual callback statement. -/
theorem execute {m memory : CC.Mem} (locals : Arm64CiliumCallerDefaults.Locals m)
    (zero : CC.Mem.load .Mint8unsigned memory (locals.block 5) 0 = some (.Vint (0#32)))
    (le : CC.TempEnv)
    (word : le.get ___a64_read_value__1 = some (.Vlong (0#64)))
    (tag : le.get ___a64_read_tag__1 = some (.Vint (10#32))) (k : CC.Cont) :
    InternalRun ge 19 (.State procedure stage k (allocation m).1 le memory)
      (.State procedure call (continuation k) (allocation m).1 (resultEnv le) memory) := by
  have castRead := tag_cast (allocation m).1
    (CC.PTree.set ___a64_mat_value__1 (CC.Val.Vlong (0#64)) le) memory ((tag_survives le).trans tag)
  apply internalRun_of_steps
  all_goals
    simp only [source,body_source,returnBody,steps,InternalPath,InternalState,CC.doStep,
      temp_value,word,castRead,eq_four,eq_ten,not_valid,valid_value locals zero,
      CC.PTree.gss,binop_type,unop_type,(bools memory).1,(bools memory).2,
      continuation,resultEnv,ite_true,ite_false,Bool.false_eq_true,true_and,and_true,
      CC.E0,CC.Eapp,List.nil_append] <;> trivial

theorem temp_frame (le : CC.TempEnv) (id : CC.Ident)
    (h0 : id ≠ ___a64_mat_value__1) (h1 : id ≠ ___a64_mat_tag__1) (h2 : id ≠ _t'13881) :
    (resultEnv le).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso _t'13881 id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_mat_tag__1 id _ _ (Ne.symm h1),
    CC.PTree.gso ___a64_mat_value__1 id _ _ (Ne.symm h0)]

private theorem resolved :
    (CC.Genv.findSymbol ge.genv_genv _native_lab_entry_input).bind
      (CC.Genv.findFunctPtr ge.genv_genv) = some Arm64OriginCache.inputFunction := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem callee_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv _native_lab_entry_input = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b = some Arm64OriginCache.inputFunction :=
  (Option.bind_eq_some_iff (x := CC.Genv.findSymbol ge.genv_genv _native_lab_entry_input)
    (f := CC.Genv.findFunctPtr ge.genv_genv) (b := Arm64OriginCache.inputFunction)).mp resolved

private theorem unshadowed (m : CC.Mem) :
    (allocation m).1.get _native_lab_entry_input = none := by
  have absent : _native_lab_entry_input ∉ CC.varNames procedure.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) absent


private theorem callee_value {m : CC.Mem} (le : CC.TempEnv) (memory : CC.Mem) (b : CC.Block)
    (symbol : CC.Genv.findSymbol ge.genv_genv _native_lab_entry_input = some b) :
    CC.doEvalExpr ge (allocation m).1 le memory calleeExpr = some (.Vptr b 0) := by
  simp only [calleeExpr,CC.doEvalExpr,CC.lvalOfVar,unshadowed m,symbol]
  rfl
private theorem function_class :
    CC.Cop.classifyFun (CC.typeof calleeExpr) = .f [CC.tuint] CC.tulong CC.cc_default := rfl
private theorem callee_type :
    CC.typeOfFundef Arm64OriginCache.inputFunction = .Tfunction [CC.tuint] CC.tulong CC.cc_default := rfl

/-- The original kind3 argument is evaluated and cast to the real provider's uint parameter. -/
theorem arguments_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExprlist ge e le memory argumentExprs [CC.tuint] = some [.Vint (3#32)] := rfl

/-- Resolve the actual linked external; no provider execution or return is assumed. -/
theorem call_ready {m : CC.Mem} (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 1
      (.State procedure call k (allocation m).1 le memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (3#32)]
        (.Kcall (some _t'157) procedure (allocation m).1 le k) memory) := by
  obtain ⟨block,symbol,function⟩ := callee_lookup
  have callable : CC.Genv.findFunct ge.genv_genv (.Vptr block 0) = some Arm64OriginCache.inputFunction := by
    simpa [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using function
  have target := callee_value (m := m) le memory block symbol
  have actuals := arguments_value (allocation m).1 le memory
  apply internalRun_of_steps
  all_goals
    simp only [steps,InternalPath,InternalState,CC.doStep,call,function_class,target,
      actuals,callable,callee_type,ite_true,eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append]

/-- Compose the SAME derived SP store, R30 word/tag reads and original materialization to the actual linked provider boundary. -/
theorem advance {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (words : Table false m) (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (slots : ∀ i : Fin 31,CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (tagSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 before tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : Arm64CiliumCallerContextEntry.CurrentGPR m before ctx ctxOfs inputs)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (locals : Arm64CiliumCallerDefaults.Locals m)
    (zero : CC.Mem.load .Mint8unsigned before (locals.block 5) 0 = some (.Vint (0#32)))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun ge 202
        (.State procedure Arm64CiliumCallerSPAlignment.tail
          (.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak (.Kseq Arm64CiliumCallerMemOffsetPrefix.stage k))
          (allocation m).1 le before)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (3#32)]
          (.Kcall (some _t'157) procedure (allocation m).1
            (resultEnv (Arm64CiliumCallerR30Tag.resultEnv tagCells
              (Arm64CiliumCallerR30Word.resultEnv wordCells
                (Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le)))))
            (continuation (.Kloop1
              (.Ssequence Arm64CiliumCallerR30Word.reader Arm64CiliumCallerR30Word.afterWord)
              .Sbreak (.Kseq Arm64CiliumCallerR30Word.rest k)))) result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  obtain ⟨result,run,read⟩ := Arm64CiliumCallerR30Tag.advance header sources scalars words tags wordCells tagCells
    ctx ctxOfs inputs slots tagSlots current access pointers reads le k
  let temps := Arm64CiliumCallerR30Tag.resultEnv tagCells
    (Arm64CiliumCallerR30Word.resultEnv wordCells
      (Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le)))
  let groupCont := CC.Cont.Kloop1
    (.Ssequence Arm64CiliumCallerR30Word.reader Arm64CiliumCallerR30Word.afterWord)
    .Sbreak (.Kseq Arm64CiliumCallerR30Word.rest k)
  have values := Arm64CiliumCallerR30Tag.values wordCells tagCells
    (Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le))
  have materialize := execute locals (valid_frame result locals zero) temps values.1 values.2 groupCont
  have callRun := call_ready (m := m) (resultEnv temps) result.after (continuation groupCont)
  exact ⟨result,run.trans (materialize.trans callRun),read⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerReturnProvider
