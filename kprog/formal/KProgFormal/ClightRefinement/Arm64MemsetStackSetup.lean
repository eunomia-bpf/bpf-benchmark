import KProgFormal.ClightRefinement.Arm64MemsetStackWrite
import KProgFormal.ClightRefinement.Arm64MemsetStart
import KProgFormal.ClightRefinement.Arm64MemsetStackInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetStackSetup

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  offsetLoop : CC.Stmt
  offsetBody : CC.Stmt
  address : CC.Stmt
  body : CC.Stmt
  afterChoice : CC.Stmt
  mathRest : CC.Stmt
  mathHas : CC.Stmt
  mathTail : CC.Stmt
  prepost : CC.Stmt
  hasIndex : CC.Stmt
  writeLoop : CC.Stmt
  writeBody : CC.Stmt
  tagLoop : CC.Stmt
  tagBody : CC.Stmt
  tagRoute : CC.Stmt
  tagCopy : CC.Stmt
  firstChoice : CC.Stmt
  copyImm : CC.Stmt
  copyIndex : CC.Stmt
  firstIf : CC.Stmt
  firstNo : CC.Stmt
  firstHas : CC.Stmt
  indexPair : CC.Stmt
  indexIf : CC.Stmt
  indexNo : CC.Stmt
  indexIsrc : CC.Stmt
  afterIndex : CC.Stmt
  immSet : CC.Stmt
  afterImm : CC.Stmt
  indexSet : CC.Stmt
  afterIndexZero : CC.Stmt
  readGuard : CC.Stmt
  afterGuard : CC.Stmt
  basePart : CC.Stmt
  baseIf : CC.Stmt
  baseNo : CC.Stmt
  baseCopy : CC.Stmt
  resultPart : CC.Stmt
  resultCopy : CC.Stmt
  resultEnd : CC.Stmt
  optionalAdd : CC.Stmt
  finalCopy : CC.Stmt
  addOffset : CC.Stmt
  copyOffset : CC.Stmt
  writeRest : CC.Stmt
  tagSet : CC.Stmt
  tagEnd : CC.Stmt
  addValue : CC.Expr

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do
        throwError "original memset offset setup changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetLoop.write)) none) ``CC.Stmt.Sloop
    let body ← peel loop[0]! ``CC.Stmt.Ssequence
    let offset ← peel body[0]! ``CC.Stmt.Sloop
    let offsetParts ← peel offset[0]! ``CC.Stmt.Ssequence
    let math0 ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memset_8)) none) ``CC.Stmt.Ssequence
    let math1 ← peel math0[1]! ``CC.Stmt.Ssequence
    let math2 ← peel math1[1]! ``CC.Stmt.Ssequence
    let math3 ← peel math2[1]! ``CC.Stmt.Ssequence
    let address ← peel body[1]! ``CC.Stmt.Ssequence
    let write ← peel address[1]! ``CC.Stmt.Sloop
    let writeBody ← peel write[0]! ``CC.Stmt.Ssequence
    let writeRest ← peel writeBody[1]! ``CC.Stmt.Ssequence
    let tag ← peel writeRest[0]! ``CC.Stmt.Sloop
    let tagBody ← peel tag[0]! ``CC.Stmt.Ssequence
    let tagEnd ← peel tagBody[1]! ``CC.Stmt.Ssequence
    let add ← Lean.Meta.withTransparency .all (Lean.Meta.whnf address[0]!)
    let first ← peel offsetParts[0]! ``CC.Stmt.Ssequence
    let firstIf ← Lean.Meta.withTransparency .all (Lean.Meta.whnf first[0]!)
    let afterChoice ← peel offsetParts[1]! ``CC.Stmt.Ssequence
    let indexPair ← peel afterChoice[0]! ``CC.Stmt.Ssequence
    let indexIf ← Lean.Meta.withTransparency .all (Lean.Meta.whnf indexPair[0]!)
    let afterIndex ← peel afterChoice[1]! ``CC.Stmt.Ssequence
    let afterImm ← peel afterIndex[1]! ``CC.Stmt.Ssequence
    let afterZero ← peel afterImm[1]! ``CC.Stmt.Ssequence
    let tail ← peel math3[1]! ``CC.Stmt.Ssequence
    let base ← peel tail[0]! ``CC.Stmt.Ssequence
    let baseIf ← Lean.Meta.withTransparency .all (Lean.Meta.whnf base[0]!)
    let result ← peel tail[1]! ``CC.Stmt.Ssequence
    let final ← peel result[1]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memset_stack_setup
      (← Lean.Meta.mkAppM ``Parts.mk #[body[0]!,offset[0]!,body[1]!,loop[0]!,offsetParts[1]!,math1[1]!,math2[1]!,math3[1]!,
        math2[0]!,math3[0]!,address[1]!,write[0]!,writeRest[0]!,tag[0]!,writeRest[1]!,tagEnd[1]!,offsetParts[0]!,math0[0]!,math1[0]!,first[0]!,firstIf.getAppArgs[2]!,first[1]!,
        afterChoice[0]!,indexPair[0]!,indexIf.getAppArgs[2]!,indexPair[1]!,afterChoice[1]!,afterIndex[0]!,
        afterIndex[1]!,afterImm[0]!,afterImm[1]!,afterZero[0]!,afterZero[1]!,tail[0]!,base[0]!,
        baseIf.getAppArgs[2]!,base[1]!,tail[1]!,result[0]!,result[1]!,final[0]!,final[1]!,address[0]!,writeBody[0]!,writeBody[1]!,tagBody[0]!,tagBody[1]!,add.getAppArgs[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_stack_setup_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def offsetLoop : CC.Stmt := by run_tac cachePart (← `(parts.offsetLoop))
private def offsetBody : CC.Stmt := by run_tac cachePart (← `(parts.offsetBody))
def address : CC.Stmt := by run_tac cachePart (← `(parts.address))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def afterChoice : CC.Stmt := by run_tac cachePart (← `(parts.afterChoice))
private def mathRest : CC.Stmt := by run_tac cachePart (← `(parts.mathRest))
private def mathHas : CC.Stmt := by run_tac cachePart (← `(parts.mathHas))
private def mathTail : CC.Stmt := by run_tac cachePart (← `(parts.mathTail))
private def prepost : CC.Stmt := by run_tac cachePart (← `(parts.prepost))
private def hasIndex : CC.Stmt := by run_tac cachePart (← `(parts.hasIndex))
private def writeLoop : CC.Stmt := by run_tac cachePart (← `(parts.writeLoop))
private def writeBody : CC.Stmt := by run_tac cachePart (← `(parts.writeBody))
private def tagLoop : CC.Stmt := by run_tac cachePart (← `(parts.tagLoop))
private def tagBody : CC.Stmt := by run_tac cachePart (← `(parts.tagBody))
private def tagRoute : CC.Stmt := by run_tac cachePart (← `(parts.tagRoute))
private def tagCopy : CC.Stmt := by run_tac cachePart (← `(parts.tagCopy))
private def firstChoice : CC.Stmt := by run_tac cachePart (← `(parts.firstChoice))
private def copyImm : CC.Stmt := by run_tac cachePart (← `(parts.copyImm))
private def copyIndex : CC.Stmt := by run_tac cachePart (← `(parts.copyIndex))
private def firstIf : CC.Stmt := by run_tac cachePart (← `(parts.firstIf))
private def firstNo : CC.Stmt := by run_tac cachePart (← `(parts.firstNo))
private def firstHas : CC.Stmt := by run_tac cachePart (← `(parts.firstHas))
private def indexPair : CC.Stmt := by run_tac cachePart (← `(parts.indexPair))
private def indexIf : CC.Stmt := by run_tac cachePart (← `(parts.indexIf))
private def indexNo : CC.Stmt := by run_tac cachePart (← `(parts.indexNo))
private def indexIsrc : CC.Stmt := by run_tac cachePart (← `(parts.indexIsrc))
private def afterIndex : CC.Stmt := by run_tac cachePart (← `(parts.afterIndex))
private def immSet : CC.Stmt := by run_tac cachePart (← `(parts.immSet))
private def afterImm : CC.Stmt := by run_tac cachePart (← `(parts.afterImm))
private def indexSet : CC.Stmt := by run_tac cachePart (← `(parts.indexSet))
private def afterIndexZero : CC.Stmt := by run_tac cachePart (← `(parts.afterIndexZero))
private def readGuard : CC.Stmt := by run_tac cachePart (← `(parts.readGuard))
private def afterGuard : CC.Stmt := by run_tac cachePart (← `(parts.afterGuard))
private def basePart : CC.Stmt := by run_tac cachePart (← `(parts.basePart))
private def baseIf : CC.Stmt := by run_tac cachePart (← `(parts.baseIf))
private def baseNo : CC.Stmt := by run_tac cachePart (← `(parts.baseNo))
private def baseCopy : CC.Stmt := by run_tac cachePart (← `(parts.baseCopy))
private def resultPart : CC.Stmt := by run_tac cachePart (← `(parts.resultPart))
private def resultCopy : CC.Stmt := by run_tac cachePart (← `(parts.resultCopy))
private def resultEnd : CC.Stmt := by run_tac cachePart (← `(parts.resultEnd))
private def optionalAdd : CC.Stmt := by run_tac cachePart (← `(parts.optionalAdd))
private def finalCopy : CC.Stmt := by run_tac cachePart (← `(parts.finalCopy))
private def addOffset : CC.Stmt := by run_tac cachePart (← `(parts.addOffset))
private def copyOffset : CC.Stmt := by run_tac cachePart (← `(parts.copyOffset))
private def writeRest : CC.Stmt := by run_tac cachePart (← `(parts.writeRest))
private def tagSet : CC.Stmt := by run_tac cachePart (← `(parts.tagSet))
private def tagEnd : CC.Stmt := by run_tac cachePart (← `(parts.tagEnd))
private def addValue : CC.Expr := by run_tac cachePart (← `(parts.addValue))
private theorem add_source : addOffset = .Sset Arm64Program.___a64_mws_off addValue := rfl
private def mathLoop : CC.Stmt := .Sloop Arm64Program.s_kprog_arm64_program_memset_8 Arm64Program.s_kprog_arm64_program_memset_9
private def mathAfter : CC.Stmt := Arm64Program.s_kprog_arm64_program_memset_10
private theorem write_source : Arm64MemsetLoop.write = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence offsetLoop address := rfl
private theorem offset_source : offsetLoop = .Sloop offsetBody .Sbreak := rfl

private theorem offsetBody_source : offsetBody = .Ssequence firstChoice afterChoice := rfl
private theorem mathBody_source : Arm64Program.s_kprog_arm64_program_memset_8 =
    .Ssequence copyImm (.Ssequence copyIndex mathRest) := rfl
private theorem mathRest_source : mathRest = .Ssequence prepost mathHas := rfl
private theorem mathHas_source : mathHas = .Ssequence hasIndex mathTail := rfl

private theorem firstChoice_source : firstChoice = .Ssequence firstIf firstHas := rfl
private theorem afterChoice_source : afterChoice = .Ssequence indexPair afterIndex := rfl
private theorem indexPair_source : indexPair = .Ssequence indexIf indexIsrc := rfl
private theorem afterIndex_source : afterIndex = .Ssequence immSet afterImm := rfl
private theorem afterImm_source : afterImm = .Ssequence indexSet afterIndexZero := rfl
private theorem afterIndexZero_source : afterIndexZero = .Ssequence readGuard afterGuard := rfl
private theorem afterGuard_source : afterGuard = .Ssequence mathLoop mathAfter := rfl
private theorem mathTail_source : mathTail = .Ssequence basePart resultPart := rfl
private theorem basePart_source : basePart = .Ssequence baseIf baseCopy := rfl
private theorem resultPart_source : resultPart = .Ssequence resultCopy resultEnd := rfl
private theorem resultEnd_source : resultEnd = .Ssequence optionalAdd finalCopy := rfl

private theorem address_source : address = .Ssequence addOffset writeLoop := rfl
private theorem writeLoop_source : writeLoop = .Sloop writeBody .Sbreak := rfl
private theorem writeBody_source : writeBody = .Ssequence copyOffset writeRest := rfl
private theorem writeRest_source : writeRest = .Ssequence tagLoop tagRoute := rfl
private theorem tagLoop_source : tagLoop = .Sloop tagBody .Sbreak := rfl
private theorem tagBody_source : tagBody = .Ssequence tagSet tagEnd := rfl
private theorem tagEnd_source : tagEnd = .Ssequence Arm64Program.s_kprog_arm64_program_memset_11 tagCopy := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def mathCont (k : CC.Cont) : CC.Cont := .Kseq mathAfter (.Kloop1 offsetBody .Sbreak (.Kseq address (continuation k)))

private def metadataTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((((le.set Arm64Program._t'3 (.Vint 0)).set Arm64Program.___a64_mbo_has_index (.Vint 0)).set
    Arm64Program._t'4 (.Vint 1)).set Arm64Program.___a64_mbo_isrc (.Vint 1)).set
    Arm64Program.___a64_mbo_imm (.Vlong 0)).set Arm64Program.___a64_mbo_index (.Vlong 0))


private def firstTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'3 (.Vint 0)).set Arm64Program.___a64_mbo_has_index (.Vint 0)
private def copiedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program.___kprog_a64_mbo_imm (.Vlong 0)).set Arm64Program.___kprog_a64_mbo_index (.Vlong 0)
private def prepostTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((le.set Arm64Program._t'13 (.Vint 0)).set Arm64Program._t'14 (.Vint 0)).set
    Arm64Program.___kprog_a64_mbo_prepost (.Vint 0)
private def hasTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'15 (.Vint 0)).set Arm64Program.___kprog_a64_mbo_has_index (.Vint 0)
private def resultTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((le.set Arm64Program._t'16 (.Vlong 0)).set Arm64Program.___kprog_a64_mbo_base (.Vlong 0)).set
    Arm64Program.___kprog_a64_mbo_result (.Vlong 0)).set Arm64Program.___a64_mbo_result (.Vlong 0))
private def offsetTemps (le : CC.TempEnv) : CC.TempEnv :=
  (resultTemps (hasTemps (prepostTemps (copiedTemps (metadataTemps le))))).set Arm64Program.___a64_mws_off (.Vlong 0)

def temps (le : CC.TempEnv) (i : BitVec 64) : CC.TempEnv :=
  (((offsetTemps le).set Arm64Program.___a64_mws_off (.Vlong i)).set
    Arm64Program.___a64_mwr_off (.Vlong i)).set Arm64Program.___a64_l_reg__2 (.Vlong 0)
private def offsetCont (k : CC.Cont) : CC.Cont := .Kloop1 offsetBody .Sbreak (.Kseq address (continuation k))
private def mathLoopCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 Arm64Program.s_kprog_arm64_program_memset_8 Arm64Program.s_kprog_arm64_program_memset_9 (mathCont k)
def tagCont (k : CC.Cont) : CC.Cont := .Kseq tagCopy
  (.Kloop1 tagBody .Sbreak (.Kseq tagRoute (.Kloop1 writeBody .Sbreak (continuation k))))

private theorem metadata_first (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 10 (.State handler Arm64MemsetLoop.write k e le m)
      (.State handler afterChoice (offsetCont k) e (firstTemps le) m) := by
  rw [write_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [offset_source,offsetBody_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [firstChoice_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler firstNo (.Kseq firstHas (.Kseq afterChoice (offsetCont k))) e le m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq firstHas (.Kseq afterChoice (offsetCont k))) e
    (le.set Arm64Program._t'3 (.Vint 0)) m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq afterChoice (offsetCont k)) e (firstTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [firstHas,CC.doStep,CC.doEvalExpr,CC.PTree.gss]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem metadata_last (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 17 (.State handler afterChoice (offsetCont k) e (firstTemps le) m)
      (.State handler mathLoop (mathCont k) e (metadataTemps le) m) := by
  rw [afterChoice_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [indexPair_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  let lc := (firstTemps le).set Arm64Program._t'4 (.Vint 1)
  let li := lc.set Arm64Program.___a64_mbo_isrc (.Vint 1)
  let lm := li.set Arm64Program.___a64_mbo_imm (.Vlong 0)
  refine .step (mid := .State handler indexNo (.Kseq indexIsrc (.Kseq afterIndex (offsetCont k))) e
    (firstTemps le) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [indexIf,CC.doStep,CC.doEvalExpr,firstTemps,CC.PTree.gss]
    rfl
  refine .step (mid := .State handler .Sskip (.Kseq indexIsrc (.Kseq afterIndex (offsetCont k))) e lc m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq afterIndex (offsetCont k)) e li m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [indexIsrc,CC.doStep,CC.doEvalExpr,lc,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterIndex_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq afterImm (offsetCont k)) e lm m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterImm_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq afterIndexZero (offsetCont k)) e (metadataTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterIndexZero_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq afterGuard (offsetCont k)) e (metadataTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp +decide only [readGuard,CC.doStep,CC.doEvalExpr,metadataTemps,CC.PTree.gso,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterGuard_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem math_copy (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)  :
    InternalRun world 7 (.State handler mathLoop (mathCont k) e (metadataTemps le) m)
      (.State handler mathRest (mathLoopCont k) e (copiedTemps (metadataTemps le)) m) := by
  apply internalRun_of_steps
  · simp +decide only [mathLoop,mathBody_source,copyImm,copyIndex,metadataTemps,copiedTemps,steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
      CC.Cop.semShl,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
      CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tuchar,CC.tint,CC.tbool,
      CC.Archi.ptr64,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int.unsigned,CC.Integers.Int.signed,CC.Integers.MI.unsigned,CC.Integers.MI.signed,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
      CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.eq,CC.Integers.MI.eq,
      CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int.and,CC.Integers.MI.and,CC.Integers.Int.or,CC.Integers.MI.or,
      CC.Integers.Int.shru,CC.Integers.MI.shru,CC.Integers.Int.shl,CC.Integers.MI.shl,
      CC.Integers.Int.iwordsize,CC.Integers.MI.iwordsize,CC.Val.ofBool,ite_true,ite_false,CC.PTree.gss,CC.PTree.gso]
  · simp +decide only [mathLoop,mathBody_source,copyImm,copyIndex,metadataTemps,copiedTemps,steps,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
      CC.Cop.semShl,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
      CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tuchar,CC.tint,CC.tbool,
      CC.Archi.ptr64,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int.unsigned,CC.Integers.Int.signed,CC.Integers.MI.unsigned,CC.Integers.MI.signed,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
      CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.eq,CC.Integers.MI.eq,
      CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int.and,CC.Integers.MI.and,CC.Integers.Int.or,CC.Integers.MI.or,
      CC.Integers.Int.shru,CC.Integers.MI.shru,CC.Integers.Int.shl,CC.Integers.MI.shl,
      CC.Integers.Int.iwordsize,CC.Integers.MI.iwordsize,CC.Val.ofBool,ite_true,ite_false,CC.PTree.gss,CC.PTree.gso,CC.E0,CC.Eapp,List.nil_append]
    all_goals rfl

private theorem math_prepost (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)  :
    InternalRun world 11 (.State handler mathRest (mathLoopCont k) e (copiedTemps (metadataTemps le)) m)
      (.State handler mathHas (mathLoopCont k) e (prepostTemps (copiedTemps (metadataTemps le))) m) := by
  apply internalRun_of_steps
  · simp +decide only [mathRest_source,prepost,metadataTemps,copiedTemps,prepostTemps,steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
      CC.Cop.semShl,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
      CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tuchar,CC.tint,CC.tbool,
      CC.Archi.ptr64,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int.unsigned,CC.Integers.Int.signed,CC.Integers.MI.unsigned,CC.Integers.MI.signed,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
      CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.eq,CC.Integers.MI.eq,
      CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int.and,CC.Integers.MI.and,CC.Integers.Int.or,CC.Integers.MI.or,
      CC.Integers.Int.shru,CC.Integers.MI.shru,CC.Integers.Int.shl,CC.Integers.MI.shl,
      CC.Integers.Int.iwordsize,CC.Integers.MI.iwordsize,CC.Val.ofBool,ite_true,ite_false,CC.PTree.gss,CC.PTree.gso]
  · simp +decide only [mathRest_source,prepost,metadataTemps,copiedTemps,prepostTemps,steps,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
      CC.Cop.semShl,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
      CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tuchar,CC.tint,CC.tbool,
      CC.Archi.ptr64,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int.unsigned,CC.Integers.Int.signed,CC.Integers.MI.unsigned,CC.Integers.MI.signed,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
      CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.eq,CC.Integers.MI.eq,
      CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int.and,CC.Integers.MI.and,CC.Integers.Int.or,CC.Integers.MI.or,
      CC.Integers.Int.shru,CC.Integers.MI.shru,CC.Integers.Int.shl,CC.Integers.MI.shl,
      CC.Integers.Int.iwordsize,CC.Integers.MI.iwordsize,CC.Val.ofBool,ite_true,ite_false,CC.PTree.gss,CC.PTree.gso,CC.E0,CC.Eapp,List.nil_append]
    all_goals rfl

private theorem math_has (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)  :
    InternalRun world 7 (.State handler mathHas (mathLoopCont k) e (prepostTemps (copiedTemps (metadataTemps le))) m)
      (.State handler mathTail (mathLoopCont k) e (hasTemps (prepostTemps (copiedTemps (metadataTemps le)))) m) := by
  apply internalRun_of_steps
  · simp +decide only [mathHas_source,hasIndex,metadataTemps,copiedTemps,prepostTemps,hasTemps,steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
      CC.Cop.semShl,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
      CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tuchar,CC.tint,CC.tbool,
      CC.Archi.ptr64,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int.unsigned,CC.Integers.Int.signed,CC.Integers.MI.unsigned,CC.Integers.MI.signed,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
      CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.eq,CC.Integers.MI.eq,
      CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int.and,CC.Integers.MI.and,CC.Integers.Int.or,CC.Integers.MI.or,
      CC.Integers.Int.shru,CC.Integers.MI.shru,CC.Integers.Int.shl,CC.Integers.MI.shl,
      CC.Integers.Int.iwordsize,CC.Integers.MI.iwordsize,CC.Val.ofBool,ite_true,ite_false,CC.PTree.gss,CC.PTree.gso]
  · simp +decide only [mathHas_source,hasIndex,metadataTemps,copiedTemps,prepostTemps,hasTemps,steps,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
      CC.Cop.semShl,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
      CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tuchar,CC.tint,CC.tbool,
      CC.Archi.ptr64,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int.unsigned,CC.Integers.Int.signed,CC.Integers.MI.unsigned,CC.Integers.MI.signed,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
      CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.eq,CC.Integers.MI.eq,
      CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int.and,CC.Integers.MI.and,CC.Integers.Int.or,CC.Integers.MI.or,
      CC.Integers.Int.shru,CC.Integers.MI.shru,CC.Integers.Int.shl,CC.Integers.MI.shl,
      CC.Integers.Int.iwordsize,CC.Integers.MI.iwordsize,CC.Val.ofBool,ite_true,ite_false,CC.PTree.gss,CC.PTree.gso,CC.E0,CC.Eapp,List.nil_append]
    all_goals rfl

private theorem math_result (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 14 (.State handler mathTail (mathLoopCont k) e
      (hasTemps (prepostTemps (copiedTemps (metadataTemps le)))) m)
      (.State handler .Sskip (mathLoopCont k) e
        (resultTemps (hasTemps (prepostTemps (copiedTemps (metadataTemps le))))) m) := by
  let l0 := hasTemps (prepostTemps (copiedTemps (metadataTemps le)))
  let l1 := l0.set Arm64Program._t'16 (.Vlong 0)
  let l2 := l1.set Arm64Program.___kprog_a64_mbo_base (.Vlong 0)
  let l3 := l2.set Arm64Program.___kprog_a64_mbo_result (.Vlong 0)
  have pre : l0.get Arm64Program.___kprog_a64_mbo_prepost = some (.Vint 0) := by
    have other0 : Arm64Program.___kprog_a64_mbo_has_index ≠ Arm64Program.___kprog_a64_mbo_prepost := by decide +kernel
    have other1 : Arm64Program._t'15 ≠ Arm64Program.___kprog_a64_mbo_prepost := by decide +kernel
    simp only [l0,hasTemps,prepostTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gss]
  have imm : l0.get Arm64Program.___kprog_a64_mbo_imm = some (.Vlong 0) := by
    have other0 : Arm64Program.___kprog_a64_mbo_has_index ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other1 : Arm64Program._t'15 ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other2 : Arm64Program.___kprog_a64_mbo_prepost ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other3 : Arm64Program._t'14 ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other4 : Arm64Program._t'13 ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other5 : Arm64Program.___kprog_a64_mbo_index ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    simp only [l0,hasTemps,prepostTemps,copiedTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5,CC.PTree.gss]
  have has : l3.get Arm64Program.___kprog_a64_mbo_has_index = some (.Vint 0) := by
    have other0 : Arm64Program.___kprog_a64_mbo_result ≠ Arm64Program.___kprog_a64_mbo_has_index := by decide +kernel
    have other1 : Arm64Program.___kprog_a64_mbo_base ≠ Arm64Program.___kprog_a64_mbo_has_index := by decide +kernel
    have other2 : Arm64Program._t'16 ≠ Arm64Program.___kprog_a64_mbo_has_index := by decide +kernel
    simp only [l3,l2,l1,l0,hasTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gss]
  dsimp only [l0] at pre
  rw [mathTail_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [basePart_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler baseNo (.Kseq baseCopy (.Kseq resultPart (mathLoopCont k))) e l0 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [baseIf,CC.doStep,CC.doEvalExpr,pre]
    rfl
  refine .step (mid := .State handler .Sskip (.Kseq baseCopy (.Kseq resultPart (mathLoopCont k))) e l1 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [baseNo,CC.doStep,CC.doEvalExpr,imm]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq resultPart (mathLoopCont k)) e l2 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [baseCopy,CC.doStep,CC.doEvalExpr,l1,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [resultPart_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq resultEnd (mathLoopCont k)) e l3 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [resultCopy,CC.doStep,CC.doEvalExpr,l2,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [resultEnd_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq finalCopy (mathLoopCont k)) e l3 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [optionalAdd,CC.doStep,CC.doEvalExpr,has]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [finalCopy,CC.doStep,CC.doEvalExpr,l3,CC.PTree.gss]
  rfl

/-- Execute the real constant metadata offset route to its original address
body. Every original branch and both real loop exits retain their source. -/
theorem to_address (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 73 (.State handler Arm64MemsetLoop.write k e le m)
      (.State handler address (continuation k) e (offsetTemps le) m) := by
  have leave : InternalRun world 7
      (.State handler .Sskip (mathLoopCont k) e
        (resultTemps (hasTemps (prepostTemps (copiedTemps (metadataTemps le))))) m)
      (.State handler address (continuation k) e (offsetTemps le) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step (mid := .State handler .Sskip (offsetCont k) e (offsetTemps le) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [mathAfter,Arm64Program.s_kprog_arm64_program_memset_10,CC.doStep,
        CC.doEvalExpr,resultTemps,CC.PTree.gss,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.typeof,CC.tulong,CC.tlong,CC.typeconv,CC.removeAttributes,CC.tattr]
      rfl
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl)
        (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  exact ((((((metadata_first e le m k).trans (metadata_last e le m k)).trans (math_copy e le m k)).trans
    (math_prepost e le m k)).trans (math_has e le m k)).trans (math_result e le m k)).trans leave


private theorem offset_index (le : CC.TempEnv) :
    (offsetTemps le).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i := by
  have other0 : Arm64Program._t'3 ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other1 : Arm64Program.___a64_mbo_has_index ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other2 : Arm64Program._t'4 ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other3 : Arm64Program.___a64_mbo_isrc ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other4 : Arm64Program.___a64_mbo_imm ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other5 : Arm64Program.___a64_mbo_index ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other6 : Arm64Program.___kprog_a64_mbo_imm ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other7 : Arm64Program.___kprog_a64_mbo_index ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other8 : Arm64Program._t'13 ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other9 : Arm64Program._t'14 ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other10 : Arm64Program.___kprog_a64_mbo_prepost ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other11 : Arm64Program._t'15 ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other12 : Arm64Program.___kprog_a64_mbo_has_index ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other13 : Arm64Program._t'16 ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other14 : Arm64Program.___kprog_a64_mbo_base ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other15 : Arm64Program.___kprog_a64_mbo_result ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other16 : Arm64Program.___a64_mbo_result ≠ Arm64Program.___a64_lib_i := by decide +kernel
  have other17 : Arm64Program.___a64_mws_off ≠ Arm64Program.___a64_lib_i := by decide +kernel
  simp only [offsetTemps,resultTemps,hasTemps,prepostTemps,copiedTemps,metadataTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5,CC.PTree.gso _ _ _ _ other6,CC.PTree.gso _ _ _ _ other7,CC.PTree.gso _ _ _ _ other8,CC.PTree.gso _ _ _ _ other9,CC.PTree.gso _ _ _ _ other10,CC.PTree.gso _ _ _ _ other11,CC.PTree.gso _ _ _ _ other12,CC.PTree.gso _ _ _ _ other13,CC.PTree.gso _ _ _ _ other14,CC.PTree.gso _ _ _ _ other15,CC.PTree.gso _ _ _ _ other16,CC.PTree.gso _ _ _ _ other17]

private theorem offset_entry (le : CC.TempEnv) :
    (offsetTemps le).get Arm64Program._entry = le.get Arm64Program._entry := by
  have other0 : Arm64Program._t'3 ≠ Arm64Program._entry := by decide +kernel
  have other1 : Arm64Program.___a64_mbo_has_index ≠ Arm64Program._entry := by decide +kernel
  have other2 : Arm64Program._t'4 ≠ Arm64Program._entry := by decide +kernel
  have other3 : Arm64Program.___a64_mbo_isrc ≠ Arm64Program._entry := by decide +kernel
  have other4 : Arm64Program.___a64_mbo_imm ≠ Arm64Program._entry := by decide +kernel
  have other5 : Arm64Program.___a64_mbo_index ≠ Arm64Program._entry := by decide +kernel
  have other6 : Arm64Program.___kprog_a64_mbo_imm ≠ Arm64Program._entry := by decide +kernel
  have other7 : Arm64Program.___kprog_a64_mbo_index ≠ Arm64Program._entry := by decide +kernel
  have other8 : Arm64Program._t'13 ≠ Arm64Program._entry := by decide +kernel
  have other9 : Arm64Program._t'14 ≠ Arm64Program._entry := by decide +kernel
  have other10 : Arm64Program.___kprog_a64_mbo_prepost ≠ Arm64Program._entry := by decide +kernel
  have other11 : Arm64Program._t'15 ≠ Arm64Program._entry := by decide +kernel
  have other12 : Arm64Program.___kprog_a64_mbo_has_index ≠ Arm64Program._entry := by decide +kernel
  have other13 : Arm64Program._t'16 ≠ Arm64Program._entry := by decide +kernel
  have other14 : Arm64Program.___kprog_a64_mbo_base ≠ Arm64Program._entry := by decide +kernel
  have other15 : Arm64Program.___kprog_a64_mbo_result ≠ Arm64Program._entry := by decide +kernel
  have other16 : Arm64Program.___a64_mbo_result ≠ Arm64Program._entry := by decide +kernel
  have other17 : Arm64Program.___a64_mws_off ≠ Arm64Program._entry := by decide +kernel
  simp only [offsetTemps,resultTemps,hasTemps,prepostTemps,copiedTemps,metadataTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5,CC.PTree.gso _ _ _ _ other6,CC.PTree.gso _ _ _ _ other7,CC.PTree.gso _ _ _ _ other8,CC.PTree.gso _ _ _ _ other9,CC.PTree.gso _ _ _ _ other10,CC.PTree.gso _ _ _ _ other11,CC.PTree.gso _ _ _ _ other12,CC.PTree.gso _ _ _ _ other13,CC.PTree.gso _ _ _ _ other14,CC.PTree.gso _ _ _ _ other15,CC.PTree.gso _ _ _ _ other16,CC.PTree.gso _ _ _ _ other17]

/-- The original setup preserves its entry pointer and selects exactly R0. -/
theorem selection (le : CC.TempEnv) (i : BitVec 64) :
    (temps le i).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le i).get Arm64Program.___a64_l_reg__2 = some (.Vlong 0) := by
  have regOther : Arm64Program.___a64_l_reg__2 ≠ Arm64Program._entry := by decide +kernel
  have offOther : Arm64Program.___a64_mwr_off ≠ Arm64Program._entry := by decide +kernel
  have baseOther : Arm64Program.___a64_mws_off ≠ Arm64Program._entry := by decide +kernel
  constructor
  · simp only [temps,CC.PTree.gso _ _ _ _ regOther,CC.PTree.gso _ _ _ _ offOther,
      CC.PTree.gso _ _ _ _ baseOther,offset_entry]
  · simp only [temps,CC.PTree.gss]

private theorem address_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : BitVec 64)
    (index : le.get Arm64Program.___a64_lib_i = some (.Vlong i)) :
    InternalRun world 13 (.State handler address (continuation k) e (offsetTemps le) m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_11 (tagCont k) e (temps le i) m) := by
  let l1 := (offsetTemps le).set Arm64Program.___a64_mws_off (.Vlong i)
  let l2 := l1.set Arm64Program.___a64_mwr_off (.Vlong i)
  have carried : (offsetTemps le).get Arm64Program.___a64_lib_i = some (.Vlong i) :=
    (offset_index le).trans index
  have zero : (offsetTemps le).get Arm64Program.___a64_mws_off = some (.Vlong 0) := by
    simp only [offsetTemps,CC.PTree.gss]
  have calculated : CC.doEvalExpr world e (offsetTemps le) m addValue = some (.Vlong i) := by
    simp only [addValue,CC.doEvalExpr,zero,carried]
    change CC.Cop.semBinaryOperation world.genv_cenv .Oadd (.Vlong 0) CC.tlong (.Vlong i) CC.tulong m = some (.Vlong i)
    change some (CC.Val.Vlong ((0#64) + i)) = some (.Vlong i)
    rw [BitVec.zero_add]
  rw [address_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq writeLoop (continuation k)) e l1 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [add_source,CC.doStep,calculated]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [writeLoop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [writeBody_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip
    (.Kseq writeRest (.Kloop1 writeBody .Sbreak (continuation k))) e l2 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [copyOffset,CC.doStep,CC.doEvalExpr,l1,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [writeRest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [tagLoop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [tagBody_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip
    (.Kseq tagEnd (.Kloop1 tagBody .Sbreak (.Kseq tagRoute (.Kloop1 writeBody .Sbreak (continuation k))))) e
    (temps le i) m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [tagEnd_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- All original offset metadata, both loops, current iteration offset and
R0 selection reach the actual tag-reader source without memory effects. -/
theorem to_tag (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : BitVec 64)
    (index : le.get Arm64Program.___a64_lib_i = some (.Vlong i)) :
    InternalRun world 86 (.State handler Arm64MemsetLoop.write k e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_11 (tagCont k) e (temps le i) m) :=
  (to_address e le m k).trans (address_setup e le m k i index)


/-- Compose the same real pointer and two MOV effects with the actual memset
entry and all 86 offset/setup transitions. R0 and SP observations at the reached
source heap follow those same effects and the genuine callee allocation. -/
theorem original {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {raw : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {prior next : Reference.AArch64.State}
    {priorK nextK : CC.Cont} (mark : BitVec 32)
    (pointer : Arm64PointerWrite.Result storage 0 raw (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : Arm64MovImmediate.OrdinaryCall.Result pointer.storage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter) (k : CC.Cont) :
    InternalRun world 256
      (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_11
        (tagCont (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
        (Arm64MemsetSource.allocation constantAfter).1
        (temps (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64)) 0)
        (Arm64MemsetSource.allocation constantAfter).2) ∧
    Arm64EntryMemory.gpr constantAfter.nextblock (Arm64MemsetSource.allocation constantAfter).2
      (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint ((4#8).setWidth 32)) ∧
    CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 40 = some (.Vptr storage.sp.block 0) ∧
    CC.Mem.load .Mint64 (Arm64MemsetSource.allocation constantAfter).2 storage.sp.block 0 = some (.Vlong storage.spValue) := by
  have prefixRun := Arm64MemsetStart.original mark first bound second k
  have setup := to_tag (Arm64MemsetSource.allocation constantAfter).1
    (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64))
    (Arm64MemsetSource.allocation constantAfter).2
    (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))) 0
    (by simp only [Arm64MemsetLoop.initializedTemps,CC.PTree.gss])
  exact ⟨prefixRun.trans setup,Arm64MemsetStackInputs.gpr pointer bound first second,
    Arm64MemsetStackInputs.sp pointer bound first second⟩

end KProgFormal.ClightRefinement.Arm64MemsetStackSetup
