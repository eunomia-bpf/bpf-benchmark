import KProgFormal.ClightRefinement.Arm64MemsetLossSetup
import KProgFormal.ClightRefinement.Arm64MemsetHeaderView
import KProgFormal.ClightRefinement.Arm64MemsetStackAction

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetStoreRoute

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  body : CC.Stmt
  indexSetup : CC.Stmt
  biasRead : CC.Stmt
  indexSet : CC.Stmt
  rest : CC.Stmt
  widthCopy : CC.Stmt
  valueAction : CC.Stmt
  maskSetup : CC.Stmt
  maskChoice : CC.Stmt
  valueSet : CC.Stmt
  actionRest : CC.Stmt
  actionSetup : CC.Stmt
  copyAction : CC.Stmt
  guard : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memset store preparation changed"
      pure actual.getAppArgs
    let loop ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetLossSetup.store)) none))
    unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original memset store loop changed"
    let body ← peel loop.getAppArgs[0]!
    let index ← peel body[0]!
    let rest ← peel body[1]!
    let valueAction ← peel rest[1]!
    let mask ← peel valueAction[0]!
    let actionRest ← peel valueAction[1]!
    let action ← peel actionRest[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_memset_store_route
      (← Lean.Meta.mkAppM ``Parts.mk #[loop.getAppArgs[0]!,body[0]!,index[0]!,index[1]!,body[1]!,rest[0]!,rest[1]!,valueAction[0]!,mask[0]!,mask[1]!,valueAction[1]!,actionRest[0]!,action[1]!,actionRest[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def indexSetup : CC.Stmt := by run_tac cachePart (← `(parts.indexSetup))
private def biasRead : CC.Stmt := by run_tac cachePart (← `(parts.biasRead))
private def indexSet : CC.Stmt := by run_tac cachePart (← `(parts.indexSet))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def widthCopy : CC.Stmt := by run_tac cachePart (← `(parts.widthCopy))
private def valueAction : CC.Stmt := by run_tac cachePart (← `(parts.valueAction))
private def maskSetup : CC.Stmt := by run_tac cachePart (← `(parts.maskSetup))
private def maskChoice : CC.Stmt := by run_tac cachePart (← `(parts.maskChoice))
private def valueSet : CC.Stmt := by run_tac cachePart (← `(parts.valueSet))
private def actionRest : CC.Stmt := by run_tac cachePart (← `(parts.actionRest))
private def actionSetup : CC.Stmt := by run_tac cachePart (← `(parts.actionSetup))
private def copyAction : CC.Stmt := by run_tac cachePart (← `(parts.copyAction))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))

private theorem source : Arm64MemsetLossSetup.store = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence indexSetup rest := rfl
private theorem index_source : indexSetup = .Ssequence biasRead indexSet := rfl
private theorem rest_source : rest = .Ssequence widthCopy valueAction := rfl
private theorem value_action_source : valueAction = .Ssequence maskSetup actionRest := rfl
private theorem mask_source : maskSetup = .Ssequence maskChoice valueSet := rfl
private theorem action_rest_source : actionRest = .Ssequence actionSetup guard := rfl
private theorem action_source : actionSetup = .Ssequence Arm64Program.s_kprog_arm64_program_memset_29 copyAction := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def actionCont (k : CC.Cont) : CC.Cont := .Kseq copyAction (.Kseq guard (continuation k))

def lossOffset (i : Fin 16) : BitVec 64 := (-32#64) + BitVec.ofNat 64 i.val
private theorem index_add : ∀ i : Fin 16, (96#64) + lossOffset i = Arm64MemsetStackAction.index i := by decide +kernel
private theorem value_mask (byte : BitVec 8) : byte.setWidth 64 &&& (255#64) = byte.setWidth 64 := by
  change byte.setWidth 64 &&& (BitVec.allOnes 8).setWidth 64 = byte.setWidth 64
  rw [←BitVec.setWidth_and,BitVec.and_allOnes]

private def biasTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'151 (.Vlong 96)
private def tailTemps (le : CC.TempEnv) (i : Fin 16) (byte : BitVec 8) : CC.TempEnv :=
  (((le.set Arm64Program.___a64_stw_index (.Vlong (Arm64MemsetStackAction.index i))).set
    Arm64Program.___a64_stw_width (.Vint 1)).set Arm64Program._t'27 (.Vlong 255)).set
    Arm64Program.___a64_stw_value (.Vlong (byte.setWidth 64))

def preparedTemps (le : CC.TempEnv) (i : Fin 16) (byte : BitVec 8) : CC.TempEnv := tailTemps (biasTemps le) i byte

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) := by
  constructor <;> decide +kernel

private theorem bias_step {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0)) :
    CC.doStep world (.State handler biasRead k e le m) =
      some (CC.E0,.State handler .Sskip k e (biasTemps le) m) := by
  simp only [biasRead,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tlong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,CC.accessMode,CC.Archi.ptr64,
    CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [offset,view.bias]
  rfl

private theorem tail (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16) (byte : BitVec 8)
    (hbias : le.get Arm64Program._t'151 = some (.Vlong 96))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64))) :
    InternalRun world 14 (.State handler indexSet (.Kseq rest (continuation k)) e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_29 (actionCont k) e (tailTemps le i byte) m) := by
  apply internalRun_of_steps
  · simp +decide [InternalPath,InternalState,steps,indexSet,rest_source,value_action_source,mask_source,action_rest_source,action_source,widthCopy,
      maskChoice,valueSet,Arm64Program.s_kprog_arm64_program_memset_27,
      CC.doStep,CC.doEvalExpr,hbias,hoff,hwidth,hvalue,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semAnd,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,
      CC.tlong,CC.tulong,CC.tuchar,CC.tuint,CC.tint,CC.tattr,CC.Archi.ptr64,
      CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int64.and,CC.Integers.MI.and,index_add,value_mask,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int.zero_ext,
      CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned]
  · simp +decide [steps,tailTemps,actionCont,continuation,CC.E0,CC.Eapp,indexSet,rest_source,value_action_source,mask_source,action_rest_source,action_source,widthCopy,
      maskChoice,valueSet,Arm64Program.s_kprog_arm64_program_memset_27,
      CC.doStep,CC.doEvalExpr,hbias,hoff,hwidth,hvalue,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semAnd,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,
      CC.tlong,CC.tulong,CC.tuchar,CC.tuint,CC.tint,CC.tattr,CC.Archi.ptr64,
      CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int64.and,CC.Integers.MI.and,index_add,value_mask,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int.zero_ext,
      CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned]
    all_goals repeat constructor <;> rfl

/-- Read the actual initialized bias field and execute all real index,
width and byte-mask assignments into the original action selector. -/
theorem prepare {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (i : Fin 16) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64))) :
    InternalRun world 19 (.State handler Arm64MemsetLossSetup.store k e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_29 (actionCont k) e (preparedTemps le i byte) m) := by
  have off : (biasTemps le).get Arm64Program.___a64_loss_off = some (.Vlong (lossOffset i)) := by
    simpa +decide only [biasTemps,CC.PTree.gso] using hoff
  have width : (biasTemps le).get Arm64Program.___a64_loss_width = some (.Vint 1) := by
    simpa +decide only [biasTemps,CC.PTree.gso] using hwidth
  have value : (biasTemps le).get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)) := by
    simpa +decide only [biasTemps,CC.PTree.gso] using hvalue
  have later := tail e (biasTemps le) m k i byte (by simp only [biasTemps,CC.PTree.gss]) off width value
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [index_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (bias_step view e le _ hentry)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) later

private theorem finish (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hresult : le.get Arm64Program._t'29 = some (.Vint (Arm64MemsetStackAction.action i))) :
    InternalRun world 4 (.State handler .Sskip (actionCont k) e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_77 (continuation k) e
        (le.set Arm64Program.___a64_stw_action (.Vint (Arm64MemsetStackAction.action i))) m) := by
  by_cases aligned : i = 0 ∨ i.val = 8
  all_goals
    apply internalRun_of_steps
    · simp +decide [InternalPath,InternalState,steps,actionCont,continuation,copyAction,guard,CC.doStep,CC.doEvalExpr,
        hresult,Arm64MemsetStackAction.action,aligned,CC.PTree.gss,
        CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.classifyCmp,CC.Cop.classifyBinarith,
        CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.boolVal,CC.Cop.classifyBool,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuchar,CC.tuint,CC.tint,
        CC.tattr,CC.Archi.ptr64,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.repr,
        CC.Integers.MI.repr,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
        CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.one,CC.Integers.Int.zero,CC.Integers.MI.one,CC.Integers.MI.zero]
    · simp +decide [steps,actionCont,continuation,copyAction,guard,CC.doStep,CC.doEvalExpr,
        hresult,Arm64MemsetStackAction.action,aligned,CC.PTree.gss,CC.E0,CC.Eapp,
        CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.classifyCmp,CC.Cop.classifyBinarith,
        CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.boolVal,CC.Cop.classifyBool,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuchar,CC.tuint,CC.tint,
        CC.tattr,CC.Archi.ptr64,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.repr,
        CC.Integers.MI.repr,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
        CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.one,CC.Integers.Int.zero,CC.Integers.MI.one,CC.Integers.MI.zero]

def temps (le : CC.TempEnv) (i : Fin 16) (byte : BitVec 8) : CC.TempEnv :=
  (Arm64MemsetStackAction.temps (preparedTemps le i byte) i).set Arm64Program.___a64_stw_action
    (.Vint (Arm64MemsetStackAction.action i))

/-- The actual bias/action/cast setters retain the source entry and
loss offset for the post-store continuation. -/
theorem temps_inputs (le : CC.TempEnv) (i : Fin 16) (byte : BitVec 8) :
    (temps le i byte).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le i byte).get Arm64Program.___a64_loss_off = le.get Arm64Program.___a64_loss_off := by
  constructor <;> simp +decide only [temps,Arm64MemsetStackAction.temps,preparedTemps,tailTemps,biasTemps,
    CC.PTree.gso]

/-- The original store loop reaches the real tag-word/byte store body in37
transitions at every original offset, retaining its genuine bias read,
index/value assignments, action selector/cast/guard and saved continuation. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (i : Fin 16) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64))) :
    InternalRun world 37 (.State handler Arm64MemsetLossSetup.store k e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_77 (continuation k) e (temps le i byte) m) := by
  have prepared := prepare view e le k i byte hentry hoff hwidth hvalue
  have width : (preparedTemps le i byte).get Arm64Program.___a64_stw_width = some (.Vint 1) := by
    simp +decide only [preparedTemps,tailTemps,CC.PTree.gso,CC.PTree.gss]
  have index : (preparedTemps le i byte).get Arm64Program.___a64_stw_index = some (.Vlong (Arm64MemsetStackAction.index i)) := by
    simp +decide only [preparedTemps,tailTemps,CC.PTree.gso,CC.PTree.gss]
  have selected := Arm64MemsetStackAction.execute e (preparedTemps le i byte) m (actionCont k) i width index
  exact (prepared.trans selected).trans (finish e _ m k i (Arm64MemsetStackAction.result _ i))

/-- Read back the actual source keys consumed by the original two-store body. -/
theorem observations (le : CC.TempEnv) (i : Fin 16) (byte : BitVec 8) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    (temps le i byte).get Arm64Program._entry = some (.Vptr entry 0) ∧
    (temps le i byte).get Arm64Program.___a64_stw_index = some (.Vlong (Arm64MemsetStackAction.index i)) ∧
    (temps le i byte).get Arm64Program.___a64_stw_width = some (.Vint 1) ∧
    (temps le i byte).get Arm64Program.___a64_stw_value = some (.Vlong (byte.setWidth 64)) := by
  simp +decide only [temps,Arm64MemsetStackAction.temps,preparedTemps,tailTemps,biasTemps,
    CC.PTree.gso,CC.PTree.gss,hentry]

end KProgFormal.ClightRefinement.Arm64MemsetStoreRoute
