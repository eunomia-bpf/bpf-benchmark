import KProgFormal.ClightRefinement.Arm64MemcpyReadSource
set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadOffset
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  offsetBody : CC.Stmt
  firstChoice : CC.Stmt
  afterChoice : CC.Stmt
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
  mathLoop : CC.Stmt
  mathBody : CC.Stmt
  mathBreak : CC.Stmt
  mathAfter : CC.Stmt
  copyImm : CC.Stmt
  copyIndex : CC.Stmt
  mathRest : CC.Stmt
  prepost : CC.Stmt
  mathHas : CC.Stmt
  hasIndex : CC.Stmt
  mathTail : CC.Stmt
  basePart : CC.Stmt
  baseIf : CC.Stmt
  baseNo : CC.Stmt
  baseCopy : CC.Stmt
  resultPart : CC.Stmt
  resultCopy : CC.Stmt
  resultEnd : CC.Stmt
  optionalAdd : CC.Stmt
  finalCopy : CC.Stmt
  extraSet : CC.Stmt
  tagRest : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memory-reader offset changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadSource.offset)) none) ``CC.Stmt.Sloop
    let body ← peel loop[0]! ``CC.Stmt.Ssequence
    let first ← peel body[0]! ``CC.Stmt.Ssequence
    let firstIf ← Lean.Meta.withTransparency .all (Lean.Meta.whnf first[0]!)
    let afterChoice ← peel body[1]! ``CC.Stmt.Ssequence
    let indexPair ← peel afterChoice[0]! ``CC.Stmt.Ssequence
    let indexIf ← Lean.Meta.withTransparency .all (Lean.Meta.whnf indexPair[0]!)
    let afterIndex ← peel afterChoice[1]! ``CC.Stmt.Ssequence
    let afterImm ← peel afterIndex[1]! ``CC.Stmt.Ssequence
    let afterZero ← peel afterImm[1]! ``CC.Stmt.Ssequence
    let afterGuard ← peel afterZero[1]! ``CC.Stmt.Ssequence
    let mathLoop ← peel afterGuard[0]! ``CC.Stmt.Sloop
    let math0 ← peel mathLoop[0]! ``CC.Stmt.Ssequence
    let math1 ← peel math0[1]! ``CC.Stmt.Ssequence
    let math2 ← peel math1[1]! ``CC.Stmt.Ssequence
    let math3 ← peel math2[1]! ``CC.Stmt.Ssequence
    let tail ← peel math3[1]! ``CC.Stmt.Ssequence
    let base ← peel tail[0]! ``CC.Stmt.Ssequence
    let baseIf ← Lean.Meta.withTransparency .all (Lean.Meta.whnf base[0]!)
    let result ← peel tail[1]! ``CC.Stmt.Ssequence
    let resultEnd ← peel result[1]! ``CC.Stmt.Ssequence
    let address ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadSource.afterOffset)) none) ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_offset_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,body[0]!,body[1]!,first[0]!,firstIf.getAppArgs[2]!,first[1]!,
        afterChoice[0]!,indexPair[0]!,indexIf.getAppArgs[2]!,indexPair[1]!,afterChoice[1]!,afterIndex[0]!,afterIndex[1]!,
        afterImm[0]!,afterImm[1]!,afterZero[0]!,afterZero[1]!,afterGuard[0]!,mathLoop[0]!,mathLoop[1]!,afterGuard[1]!,
        math0[0]!,math1[0]!,math1[1]!,math2[0]!,math2[1]!,math3[0]!,math3[1]!,tail[0]!,base[0]!,
        baseIf.getAppArgs[2]!,base[1]!,tail[1]!,result[0]!,result[1]!,resultEnd[0]!,resultEnd[1]!,address[0]!,address[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_offset_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def offsetBody : CC.Stmt := by run_tac cachePart (← `(parts.offsetBody))
private def firstChoice : CC.Stmt := by run_tac cachePart (← `(parts.firstChoice))
private def afterChoice : CC.Stmt := by run_tac cachePart (← `(parts.afterChoice))
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
private def mathLoop : CC.Stmt := by run_tac cachePart (← `(parts.mathLoop))
private def mathBody : CC.Stmt := by run_tac cachePart (← `(parts.mathBody))
private def mathBreak : CC.Stmt := by run_tac cachePart (← `(parts.mathBreak))
private def mathAfter : CC.Stmt := by run_tac cachePart (← `(parts.mathAfter))
private def copyImm : CC.Stmt := by run_tac cachePart (← `(parts.copyImm))
private def copyIndex : CC.Stmt := by run_tac cachePart (← `(parts.copyIndex))
private def mathRest : CC.Stmt := by run_tac cachePart (← `(parts.mathRest))
private def prepost : CC.Stmt := by run_tac cachePart (← `(parts.prepost))
private def mathHas : CC.Stmt := by run_tac cachePart (← `(parts.mathHas))
private def hasIndex : CC.Stmt := by run_tac cachePart (← `(parts.hasIndex))
private def mathTail : CC.Stmt := by run_tac cachePart (← `(parts.mathTail))
private def basePart : CC.Stmt := by run_tac cachePart (← `(parts.basePart))
private def baseIf : CC.Stmt := by run_tac cachePart (← `(parts.baseIf))
private def baseNo : CC.Stmt := by run_tac cachePart (← `(parts.baseNo))
private def baseCopy : CC.Stmt := by run_tac cachePart (← `(parts.baseCopy))
private def resultPart : CC.Stmt := by run_tac cachePart (← `(parts.resultPart))
private def resultCopy : CC.Stmt := by run_tac cachePart (← `(parts.resultCopy))
private def resultEnd : CC.Stmt := by run_tac cachePart (← `(parts.resultEnd))
private def optionalAdd : CC.Stmt := by run_tac cachePart (← `(parts.optionalAdd))
private def finalCopy : CC.Stmt := by run_tac cachePart (← `(parts.finalCopy))
private def extraSet : CC.Stmt := by run_tac cachePart (← `(parts.extraSet))
def tagRest : CC.Stmt := by run_tac cachePart (← `(parts.tagRest))

private abbrev address := Arm64MemcpyReadSource.afterOffset
private theorem offset_source : Arm64MemcpyReadSource.offset = .Sloop offsetBody .Sbreak := rfl
private theorem offsetBody_source : offsetBody = .Ssequence firstChoice afterChoice := rfl
private theorem mathLoop_source : mathLoop = .Sloop mathBody mathBreak := rfl
private theorem mathBody_source : mathBody =
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


private def mathCont (k : CC.Cont) : CC.Cont := .Kseq mathAfter (.Kloop1 offsetBody .Sbreak (.Kseq address k))
private def offsetCont (k : CC.Cont) : CC.Cont := .Kloop1 offsetBody .Sbreak (.Kseq address k)
private def mathLoopCont (k : CC.Cont) : CC.Cont := .Kloop1 mathBody mathBreak (mathCont k)

private def metadataTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((((le.set Arm64Program._t'1 (.Vint 0)).set Arm64Program.___a64_mbo_has_index (.Vint 0)).set
    Arm64Program._t'2 (.Vint 1)).set Arm64Program.___a64_mbo_isrc (.Vint 1)).set
    Arm64Program.___a64_mbo_imm (.Vlong 0)).set Arm64Program.___a64_mbo_index (.Vlong 0))


private def firstTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'1 (.Vint 0)).set Arm64Program.___a64_mbo_has_index (.Vint 0)
private def copiedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program.___kprog_a64_mbo_imm (.Vlong 0)).set Arm64Program.___kprog_a64_mbo_index (.Vlong 0)
private def prepostTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((le.set Arm64Program._t'11 (.Vint 0)).set Arm64Program._t'12 (.Vint 0)).set
    Arm64Program.___kprog_a64_mbo_prepost (.Vint 0)
private def hasTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'13 (.Vint 0)).set Arm64Program.___kprog_a64_mbo_has_index (.Vint 0)
private def resultTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((le.set Arm64Program._t'14 (.Vlong 0)).set Arm64Program.___kprog_a64_mbo_base (.Vlong 0)).set
    Arm64Program.___kprog_a64_mbo_result (.Vlong 0)).set Arm64Program.___a64_mbo_result (.Vlong 0))
def offsetTemps (le : CC.TempEnv) : CC.TempEnv :=
  (resultTemps (hasTemps (prepostTemps (copiedTemps (metadataTemps le))))).set Arm64Program.___a64_memory_off (.Vlong 0)

private theorem metadata_first (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hindex : le.get Arm64Program._index = some (.Vlong 255)) :
    InternalRun world 8 (.State reader Arm64MemcpyReadSource.offset (.Kseq address k) e le m)
      (.State reader afterChoice (offsetCont k) e (firstTemps le) m) := by
  rw [offset_source,offsetBody_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [firstChoice_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader firstNo (.Kseq firstHas (.Kseq afterChoice (offsetCont k))) e le m)
    trivial (CC.doStep_sound _ _ _ _ (by simp only [firstIf,CC.doStep,CC.doEvalExpr,hindex]; rfl)) ?_
  refine .step (mid := .State reader .Sskip (.Kseq firstHas (.Kseq afterChoice (offsetCont k))) e
    (le.set Arm64Program._t'1 (.Vint 0)) m) trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq afterChoice (offsetCont k)) e (firstTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [firstHas,CC.doStep,CC.doEvalExpr,CC.PTree.gss]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem metadata_last (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (himm : le.get Arm64Program._imm = some (.Vlong 0)) :
    InternalRun world 17 (.State reader afterChoice (offsetCont k) e (firstTemps le) m)
      (.State reader mathLoop (mathCont k) e (metadataTemps le) m) := by
  rw [afterChoice_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [indexPair_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  let lc := (firstTemps le).set Arm64Program._t'2 (.Vint 1)
  let li := lc.set Arm64Program.___a64_mbo_isrc (.Vint 1)
  let lm := li.set Arm64Program.___a64_mbo_imm (.Vlong 0)
  have immRead : li.get Arm64Program._imm = some (.Vlong 0) := by
    simpa +decide only [li,lc,firstTemps,CC.PTree.gso] using himm
  refine .step (mid := .State reader indexNo (.Kseq indexIsrc (.Kseq afterIndex (offsetCont k))) e
    (firstTemps le) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [indexIf,CC.doStep,CC.doEvalExpr,firstTemps,CC.PTree.gss]
    rfl
  refine .step (mid := .State reader .Sskip (.Kseq indexIsrc (.Kseq afterIndex (offsetCont k))) e lc m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq afterIndex (offsetCont k)) e li m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [indexIsrc,CC.doStep,CC.doEvalExpr,lc,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterIndex_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq afterImm (offsetCont k)) e lm m)
    trivial (CC.doStep_sound _ _ _ _ (by simp only [immSet,CC.doStep,CC.doEvalExpr,immRead]; rfl)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterImm_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq afterIndexZero (offsetCont k)) e (metadataTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterIndexZero_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq afterGuard (offsetCont k)) e (metadataTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp +decide only [readGuard,CC.doStep,CC.doEvalExpr,metadataTemps,CC.PTree.gso,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [afterGuard_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem math_copy (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)  :
    InternalRun world 7 (.State reader mathLoop (mathCont k) e (metadataTemps le) m)
      (.State reader mathRest (mathLoopCont k) e (copiedTemps (metadataTemps le)) m) := by
  rw [mathLoop_source]
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

private theorem math_prepost (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (haux : le.get Arm64Program._aux = some (.Vint 255)) :
    InternalRun world 11 (.State reader mathRest (mathLoopCont k) e (copiedTemps (metadataTemps le)) m)
      (.State reader mathHas (mathLoopCont k) e (prepostTemps (copiedTemps (metadataTemps le))) m) := by
  apply internalRun_of_steps
  · simp +decide only [mathRest_source,prepost,Arm64Program.s_kprog_arm64_program_memory_read_8,Arm64Program.s_kprog_arm64_program_memory_read_9,Arm64Program.s_kprog_arm64_program_memory_read_10,haux,metadataTemps,copiedTemps,prepostTemps,steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
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
  · simp +decide only [mathRest_source,prepost,Arm64Program.s_kprog_arm64_program_memory_read_8,Arm64Program.s_kprog_arm64_program_memory_read_9,Arm64Program.s_kprog_arm64_program_memory_read_10,haux,metadataTemps,copiedTemps,prepostTemps,steps,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
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
    InternalRun world 7 (.State reader mathHas (mathLoopCont k) e (prepostTemps (copiedTemps (metadataTemps le))) m)
      (.State reader mathTail (mathLoopCont k) e (hasTemps (prepostTemps (copiedTemps (metadataTemps le)))) m) := by
  apply internalRun_of_steps
  · simp +decide only [mathHas_source,hasIndex,Arm64Program.s_kprog_arm64_program_memory_read_11,metadataTemps,copiedTemps,prepostTemps,hasTemps,steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
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
  · simp +decide only [mathHas_source,hasIndex,Arm64Program.s_kprog_arm64_program_memory_read_11,metadataTemps,copiedTemps,prepostTemps,hasTemps,steps,CC.doStep,CC.doEvalExpr,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semAnd,CC.Cop.semOr,
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
    InternalRun world 14 (.State reader mathTail (mathLoopCont k) e
      (hasTemps (prepostTemps (copiedTemps (metadataTemps le)))) m)
      (.State reader .Sskip (mathLoopCont k) e
        (resultTemps (hasTemps (prepostTemps (copiedTemps (metadataTemps le))))) m) := by
  let l0 := hasTemps (prepostTemps (copiedTemps (metadataTemps le)))
  let l1 := l0.set Arm64Program._t'14 (.Vlong 0)
  let l2 := l1.set Arm64Program.___kprog_a64_mbo_base (.Vlong 0)
  let l3 := l2.set Arm64Program.___kprog_a64_mbo_result (.Vlong 0)
  have pre : l0.get Arm64Program.___kprog_a64_mbo_prepost = some (.Vint 0) := by
    have other0 : Arm64Program.___kprog_a64_mbo_has_index ≠ Arm64Program.___kprog_a64_mbo_prepost := by decide +kernel
    have other1 : Arm64Program._t'13 ≠ Arm64Program.___kprog_a64_mbo_prepost := by decide +kernel
    simp only [l0,hasTemps,prepostTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gss]
  have imm : l0.get Arm64Program.___kprog_a64_mbo_imm = some (.Vlong 0) := by
    have other0 : Arm64Program.___kprog_a64_mbo_has_index ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other1 : Arm64Program._t'13 ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other2 : Arm64Program.___kprog_a64_mbo_prepost ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other3 : Arm64Program._t'12 ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other4 : Arm64Program._t'11 ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    have other5 : Arm64Program.___kprog_a64_mbo_index ≠ Arm64Program.___kprog_a64_mbo_imm := by decide +kernel
    simp only [l0,hasTemps,prepostTemps,copiedTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gso _ _ _ _ other5,CC.PTree.gss]
  have has : l3.get Arm64Program.___kprog_a64_mbo_has_index = some (.Vint 0) := by
    have other0 : Arm64Program.___kprog_a64_mbo_result ≠ Arm64Program.___kprog_a64_mbo_has_index := by decide +kernel
    have other1 : Arm64Program.___kprog_a64_mbo_base ≠ Arm64Program.___kprog_a64_mbo_has_index := by decide +kernel
    have other2 : Arm64Program._t'14 ≠ Arm64Program.___kprog_a64_mbo_has_index := by decide +kernel
    simp only [l3,l2,l1,l0,hasTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2,CC.PTree.gss]
  dsimp only [l0] at pre
  rw [mathTail_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [basePart_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader baseNo (.Kseq baseCopy (.Kseq resultPart (mathLoopCont k))) e l0 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [baseIf,CC.doStep,CC.doEvalExpr,pre]
    rfl
  refine .step (mid := .State reader .Sskip (.Kseq baseCopy (.Kseq resultPart (mathLoopCont k))) e l1 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [baseNo,CC.doStep,CC.doEvalExpr,imm]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq resultPart (mathLoopCont k)) e l2 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [baseCopy,CC.doStep,CC.doEvalExpr,l1,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [resultPart_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq resultEnd (mathLoopCont k)) e l3 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [resultCopy,CC.doStep,CC.doEvalExpr,l2,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [resultEnd_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq finalCopy (mathLoopCont k)) e l3 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [optionalAdd,CC.doStep,CC.doEvalExpr,has]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [finalCopy,CC.doStep,CC.doEvalExpr,l3,CC.PTree.gss]
  rfl

/-- Execute the real constant metadata offset route to its original address
body. Every original branch and both real loop exits retain their source. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hindex : le.get Arm64Program._index = some (.Vlong 255))
    (himm : le.get Arm64Program._imm = some (.Vlong 0))
    (haux : le.get Arm64Program._aux = some (.Vint 255)) :
    InternalRun world 71 (.State reader Arm64MemcpyReadSource.offset (.Kseq address k) e le m)
      (.State reader address k e (offsetTemps le) m) := by
  have leave : InternalRun world 7
      (.State reader .Sskip (mathLoopCont k) e
        (resultTemps (hasTemps (prepostTemps (copiedTemps (metadataTemps le))))) m)
      (.State reader address k e (offsetTemps le) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step (mid := .State reader .Sskip (offsetCont k) e (offsetTemps le) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [mathAfter,mathAfter,CC.doStep,
        CC.doEvalExpr,resultTemps,CC.PTree.gss,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.typeof,CC.tulong,CC.tlong,CC.typeconv,CC.removeAttributes,CC.tattr]
      rfl
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl)
        (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  exact ((((((metadata_first e le m k hindex).trans (metadata_last e le m k himm)).trans (math_copy e le m k)).trans
    (math_prepost e le m k haux)).trans (math_has e le m k)).trans (math_result e le m k)).trans leave


private def writtenKeys : List CC.Ident :=
  [Arm64Program._t'1, Arm64Program.___a64_mbo_has_index, Arm64Program._t'2, Arm64Program.___a64_mbo_isrc, Arm64Program.___a64_mbo_imm, Arm64Program.___a64_mbo_index, Arm64Program.___kprog_a64_mbo_imm, Arm64Program.___kprog_a64_mbo_index, Arm64Program._t'11, Arm64Program._t'12, Arm64Program.___kprog_a64_mbo_prepost, Arm64Program._t'13, Arm64Program.___kprog_a64_mbo_has_index, Arm64Program._t'14, Arm64Program.___kprog_a64_mbo_base, Arm64Program.___kprog_a64_mbo_result, Arm64Program.___a64_mbo_result, Arm64Program.___a64_memory_off]

/-- Every other parameter and temporary survives the actual pure offset path. -/
theorem kept (le : CC.TempEnv) (key : CC.Ident) (other : key ∉ writtenKeys) :
    (offsetTemps le).get key = le.get key := by
  have diff (id : CC.Ident) (member : id ∈ writtenKeys) : id ≠ key := by
    intro same
    exact other (same ▸ member)
  have other0 : Arm64Program._t'1 ≠ key := diff Arm64Program._t'1 (by decide +kernel)
  have other1 : Arm64Program.___a64_mbo_has_index ≠ key := diff Arm64Program.___a64_mbo_has_index (by decide +kernel)
  have other2 : Arm64Program._t'2 ≠ key := diff Arm64Program._t'2 (by decide +kernel)
  have other3 : Arm64Program.___a64_mbo_isrc ≠ key := diff Arm64Program.___a64_mbo_isrc (by decide +kernel)
  have other4 : Arm64Program.___a64_mbo_imm ≠ key := diff Arm64Program.___a64_mbo_imm (by decide +kernel)
  have other5 : Arm64Program.___a64_mbo_index ≠ key := diff Arm64Program.___a64_mbo_index (by decide +kernel)
  have other6 : Arm64Program.___kprog_a64_mbo_imm ≠ key := diff Arm64Program.___kprog_a64_mbo_imm (by decide +kernel)
  have other7 : Arm64Program.___kprog_a64_mbo_index ≠ key := diff Arm64Program.___kprog_a64_mbo_index (by decide +kernel)
  have other8 : Arm64Program._t'11 ≠ key := diff Arm64Program._t'11 (by decide +kernel)
  have other9 : Arm64Program._t'12 ≠ key := diff Arm64Program._t'12 (by decide +kernel)
  have other10 : Arm64Program.___kprog_a64_mbo_prepost ≠ key := diff Arm64Program.___kprog_a64_mbo_prepost (by decide +kernel)
  have other11 : Arm64Program._t'13 ≠ key := diff Arm64Program._t'13 (by decide +kernel)
  have other12 : Arm64Program.___kprog_a64_mbo_has_index ≠ key := diff Arm64Program.___kprog_a64_mbo_has_index (by decide +kernel)
  have other13 : Arm64Program._t'14 ≠ key := diff Arm64Program._t'14 (by decide +kernel)
  have other14 : Arm64Program.___kprog_a64_mbo_base ≠ key := diff Arm64Program.___kprog_a64_mbo_base (by decide +kernel)
  have other15 : Arm64Program.___kprog_a64_mbo_result ≠ key := diff Arm64Program.___kprog_a64_mbo_result (by decide +kernel)
  have other16 : Arm64Program.___a64_mbo_result ≠ key := diff Arm64Program.___a64_mbo_result (by decide +kernel)
  have other17 : Arm64Program.___a64_memory_off ≠ key := diff Arm64Program.___a64_memory_off (by decide +kernel)
  simp only [offsetTemps,resultTemps,hasTemps,prepostTemps,copiedTemps,metadataTemps,
    CC.PTree.gso _ _ _ _ other0,
    CC.PTree.gso _ _ _ _ other1,
    CC.PTree.gso _ _ _ _ other2,
    CC.PTree.gso _ _ _ _ other3,
    CC.PTree.gso _ _ _ _ other4,
    CC.PTree.gso _ _ _ _ other5,
    CC.PTree.gso _ _ _ _ other6,
    CC.PTree.gso _ _ _ _ other7,
    CC.PTree.gso _ _ _ _ other8,
    CC.PTree.gso _ _ _ _ other9,
    CC.PTree.gso _ _ _ _ other10,
    CC.PTree.gso _ _ _ _ other11,
    CC.PTree.gso _ _ _ _ other12,
    CC.PTree.gso _ _ _ _ other13,
    CC.PTree.gso _ _ _ _ other14,
    CC.PTree.gso _ _ _ _ other15,
    CC.PTree.gso _ _ _ _ other16,
    CC.PTree.gso _ _ _ _ other17]

/-- The real copy from the numerical offset result produces zero here. -/
theorem offset_zero (le : CC.TempEnv) :
    (offsetTemps le).get Arm64Program.___a64_memory_off = some (.Vlong 0) := CC.PTree.gss _ _ _

def temps (le : CC.TempEnv) (extra : BitVec 64) : CC.TempEnv :=
  (offsetTemps le).set Arm64Program.___a64_memory_off (.Vlong extra)

private theorem address_source : address = .Ssequence extraSet tagRest := rfl

/-- Execute the actual extra-offset addition before the real R1 tag path. -/
theorem add_extra (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (extra : BitVec 64)
    (hextra : le.get Arm64Program._extra = some (.Vlong extra)) :
    InternalRun world 3 (.State reader address k e (offsetTemps le) m)
      (.State reader tagRest k e (temps le extra) m) := by
  have actualExtra := (kept le Arm64Program._extra (by decide +kernel)).trans hextra
  rw [address_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq tagRest k) e (temps le extra) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [extraSet,CC.doStep,CC.doEvalExpr,offset_zero,actualExtra,CC.Cop.semBinaryOperation,
      CC.typeof,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
      CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,
      CC.tattr,CC.tlong,CC.Archi.ptr64,CC.Integers.Int64.add,CC.Integers.MI.add,BitVec.zero_add,ite_true,ite_false]
    exact congrArg (fun word : BitVec 64 => some (CC.E0,
      CC.State.State reader CC.Stmt.Sskip (CC.Cont.Kseq tagRest k) e
        ((offsetTemps le).set Arm64Program.___a64_memory_off (.Vlong word)) m))
      (BitVec.zero_add extra)
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The actual first offset loop and extra addition execute on the same heap. -/
theorem to_tag (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (extra : BitVec 64)
    (hindex : le.get Arm64Program._index = some (.Vlong 255))
    (himm : le.get Arm64Program._imm = some (.Vlong 0))
    (haux : le.get Arm64Program._aux = some (.Vint 255))
    (hextra : le.get Arm64Program._extra = some (.Vlong extra)) :
    InternalRun world 74 (.State reader Arm64MemcpyReadSource.offset (.Kseq address k) e le m)
      (.State reader tagRest k e (temps le extra) m) :=
  (execute e le m k hindex himm haux).trans (add_extra e le m k extra hextra)

/-- The genuine thirteen-local reader entry reaches its actual source-tag
continuation, with offset i derived from its seven real call arguments. -/
theorem original (before : CC.Mem) (entry : CC.Block) (extra : BitVec 64) (k : CC.Cont) :
    InternalRun world 78
      (.Callstate (.Internal reader) (Arm64MemcpyReadCall.arguments entry extra) k before)
      (.State reader tagRest (Arm64MemcpyReadSource.outerCont k) (Arm64MemcpyReadSource.allocation before).1
        (temps (Arm64MemcpyReadSource.initialTemps entry extra) extra) (Arm64MemcpyReadSource.allocation before).2) := by
  have indexRead : (Arm64MemcpyReadSource.initialTemps entry extra).get Arm64Program._index = some (.Vlong 255) := by
    simp +decide only [Arm64MemcpyReadSource.initialTemps,CC.PTree.gso,CC.PTree.gss]
  have immRead : (Arm64MemcpyReadSource.initialTemps entry extra).get Arm64Program._imm = some (.Vlong 0) := by
    simp +decide only [Arm64MemcpyReadSource.initialTemps,CC.PTree.gso,CC.PTree.gss]
  have auxRead : (Arm64MemcpyReadSource.initialTemps entry extra).get Arm64Program._aux = some (.Vint 255) := by
    simp +decide only [Arm64MemcpyReadSource.initialTemps,CC.PTree.gso,CC.PTree.gss]
  have extraRead : (Arm64MemcpyReadSource.initialTemps entry extra).get Arm64Program._extra = some (.Vlong extra) := by
    simp +decide only [Arm64MemcpyReadSource.initialTemps,CC.PTree.gso,CC.PTree.gss]
  exact (Arm64MemcpyReadSource.enter before entry extra k).trans
    (to_tag _ _ _ (Arm64MemcpyReadSource.outerCont k) extra indexRead immRead auxRead extraRead)

end KProgFormal.ClightRefinement.Arm64MemcpyReadOffset
