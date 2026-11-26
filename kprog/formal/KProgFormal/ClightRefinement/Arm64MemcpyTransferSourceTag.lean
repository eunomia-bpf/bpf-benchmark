import KProgFormal.ClightRefinement.Arm64MemcpyTransferSourcePrefix
import KProgFormal.ClightRefinement.Arm64MemsetTagWords

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceTag

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  body : CC.Stmt
  indexSet : CC.Stmt
  indexValue : CC.Expr
  rest : CC.Stmt
  loadPair : CC.Stmt
  header : CC.Stmt
  load : CC.Stmt
  loadArgs : List CC.Expr
  tagSet : CC.Stmt
  tagValue : CC.Expr
  selector : CC.Stmt
  selectorTest : CC.Expr
  selectorYes : CC.Stmt
  selectorNo : CC.Stmt
  selectorValue : CC.Expr
  payloadGuard : CC.Stmt
  payloadYes : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy source-tag route changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferSourceAddress.tagLoop)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let index ← peel body[0]! ``CC.Stmt.Sset 2
    let rest ← peel body[1]! ``CC.Stmt.Ssequence 2
    let pair ← peel rest[0]! ``CC.Stmt.Ssequence 2
    let load ← peel pair[1]! ``CC.Stmt.Sbuiltin 4
    let tag ← peel rest[1]! ``CC.Stmt.Sset 2
    let payload ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferSourceAddress.payload)) none) ``CC.Stmt.Ssequence 2
    let selector ← peel payload[0]! ``CC.Stmt.Sifthenelse 3
    let setter ← peel selector[2]! ``CC.Stmt.Sset 2
    let guard ← peel payload[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_source_tag
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,body[0]!,index[1]!,body[1]!,rest[0]!,pair[0]!,pair[1]!,
        load[3]!,rest[1]!,tag[1]!,payload[0]!,selector[0]!,selector[1]!,selector[2]!,setter[1]!,payload[1]!,guard[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_source_tag_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def indexSet : CC.Stmt := by run_tac cachePart (← `(parts.indexSet))
private def indexValue : CC.Expr := by run_tac cachePart (← `(parts.indexValue))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def loadPair : CC.Stmt := by run_tac cachePart (← `(parts.loadPair))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def load : CC.Stmt := by run_tac cachePart (← `(parts.load))
private def loadArgs : List CC.Expr := by run_tac cachePart (← `(parts.loadArgs))
private def tagSet : CC.Stmt := by run_tac cachePart (← `(parts.tagSet))
private def tagValue : CC.Expr := by run_tac cachePart (← `(parts.tagValue))
private def selector : CC.Stmt := by run_tac cachePart (← `(parts.selector))
private def selectorTest : CC.Expr := by run_tac cachePart (← `(parts.selectorTest))
private def selectorYes : CC.Stmt := by run_tac cachePart (← `(parts.selectorYes))
private def selectorNo : CC.Stmt := by run_tac cachePart (← `(parts.selectorNo))
private def selectorValue : CC.Expr := by run_tac cachePart (← `(parts.selectorValue))
private def payloadGuard : CC.Stmt := by run_tac cachePart (← `(parts.payloadGuard))
private def payloadYes : CC.Stmt := by run_tac cachePart (← `(parts.payloadYes))
private theorem source : Arm64MemcpyTransferSourceAddress.tagLoop = .Sloop body .Sbreak ∧
    body = .Ssequence indexSet rest ∧ rest = .Ssequence loadPair tagSet ∧
    loadPair = .Ssequence header load ∧ indexSet = .Sset Arm64Program.___ti__6 indexValue ∧
    tagSet = .Sset Arm64Program.___a64_mt_tag tagValue ∧
    load = .Sbuiltin (some Arm64Program._t'74) (.EF_vload .Mint64)
      [CC.tptr (CC.tvolatile CC.tulong)] loadArgs := ⟨rfl,rfl,rfl,rfl,rfl,rfl,rfl⟩
private theorem payload_source : Arm64MemcpyTransferSourceAddress.payload = .Ssequence selector payloadGuard ∧
    selector = .Sifthenelse selectorTest selectorYes selectorNo ∧
    selectorNo = .Sset Arm64Program._t'76 selectorValue ∧
    payloadGuard = .Sifthenelse (.Etempvar Arm64Program._t'76 CC.tint) payloadYes .Sskip := ⟨rfl,rfl,rfl,rfl⟩

private def index (i : Fin 16) : BitVec 64 := Arm64MemcpyTransferSourceAddress.position i >>> 3
private def shift (i : Fin 16) : BitVec 64 := (index i &&& (7#64))*(8#64)
private theorem mask_data : ∀ i : Fin 16, index i &&& ~~~(7#64) = (8#64) := by decide +kernel
private theorem shift_data : ∀ i : Fin 16, CC.Integers.MI.ltu (shift i) (64#64) = true := by decide +kernel
private def indexTemps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv := le.set Arm64Program.___ti__6 (.Vlong (index i))
private def headerTemps (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) : CC.TempEnv :=
  (indexTemps le i).set Arm64Program._t'93 (.Vptr tags 0)
private def wordTemps (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) : CC.TempEnv :=
  (headerTemps le i tags).set Arm64Program._t'74 (.Vlong 0)
private def tagTemps (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) : CC.TempEnv :=
  (wordTemps le i tags).set Arm64Program.___a64_mt_tag (.Vint 0)
def temps (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) : CC.TempEnv :=
  (tagTemps le i tags).set Arm64Program._t'76 (.Vint 0)
private def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

private theorem index_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hsource : le.get Arm64Program.___a64_mt_src = some (.Vlong (Arm64MemcpyTransferSourceAddress.position i))) :
    CC.doStep world (.State handler indexSet k e le m) =
      some (CC.E0,.State handler .Sskip k e (indexTemps le i) m) := by
  rw [source.2.2.2.2.1]
  simp +decide [CC.doStep,indexValue,CC.doEvalExpr,hsource,indexTemps,index,
    CC.Cop.semBinaryOperation,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tint,CC.Archi.ptr64,
    CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
    CC.Integers.Int64.shru,CC.Integers.MI.shru,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned]

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._stack_tags entryComposite.co_members = .OK (648,.Full) := by
  constructor <;> decide +kernel
private theorem header_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    CC.doStep world (.State handler header k e (indexTemps le i) m) =
      some (CC.E0,.State handler .Sskip k e (headerTemps le i tags) m) := by
  have carried : (indexTemps le i).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [indexTemps,CC.PTree.gso] using hentry
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,carried,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,CC.accessMode,
    CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,headerTemps,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 648).toNat) : Nat) : Int) = 648 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 648 = some (.Vptr tags 0) from read]

private theorem load_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block) (i : Fin 16) :
    CC.doEvalExprlist world e (headerTemps le i tags) m loadArgs [CC.tptr (CC.tvolatile CC.tulong)] =
      some [.Vptr tags 8] := by
  have pointer : (headerTemps le i tags).get Arm64Program._t'93 = some (.Vptr tags 0) := CC.PTree.gss _ _ _
  have slot : (headerTemps le i tags).get Arm64Program.___ti__6 = some (.Vlong (index i)) := by
    simp only [headerTemps,indexTemps,
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'93 ≠ Arm64Program.___ti__6),CC.PTree.gss]
  have masked := mask_data i
  have complement : (~~~(7#64)) = (18446744073709551608#64) := by decide +kernel
  rw [complement] at masked
  simp +decide [loadArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,slot,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrLong,
    CC.Cop.semUnaryOperation,CC.Cop.semNotint,CC.Cop.classifyNotint,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tvolatile,CC.tulong,CC.tuchar,
    CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,CC.Integers.Int64.not,CC.Integers.MI.not,
    CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
    CC.Integers.Ptrofs.repr,CC.Integers.Ptrofs.of_int64,CC.Integers.MI.add,CC.Integers.MI.mul,
    BitVec.ofInt_natCast,masked]

private theorem load_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (tags : CC.Block) (i : Fin 16)
    (read : CC.Mem.load .Mint64 m tags 8 = some (.Vlong 0)) :
    CC.Step2 world (.State handler load k e (headerTemps le i tags) m) CC.E0
      (.State handler .Sskip k e (wordTemps le i tags) m) := by
  rw [source.2.2.2.2.2.2]
  apply CC.Step.builtin (vargs := [.Vptr tags 8]) (vres := .Vlong 0)
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (load_arguments e le m tags i)
  · exact CC.VolatileLoadSem.intro _ _ _ _ _ _
      (.nonvol _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags) read)

private theorem tag_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block) (i : Fin 16) :
    CC.doEvalExpr world e (wordTemps le i tags) m tagValue = some (.Vint 0) := by
  have word : (wordTemps le i tags).get Arm64Program._t'74 = some (.Vlong 0) := CC.PTree.gss _ _ _
  have slot : (wordTemps le i tags).get Arm64Program.___ti__6 = some (.Vlong (index i)) := by
    simp only [wordTemps,headerTemps,indexTemps,
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'74 ≠ Arm64Program.___ti__6),
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'93 ≠ Arm64Program.___ti__6),CC.PTree.gss]
  have checked := shift_data i
  unfold shift at checked
  simp +decide [tagValue,CC.doEvalExpr,word,slot,CC.Cop.semBinaryOperation,
    CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,CC.Cop.semAnd,CC.Cop.semMul,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tvolatile,CC.tulong,CC.tuint,CC.tuchar,
    CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int64.shru,CC.Integers.MI.shru,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.Integers.Int64.mul,CC.Integers.MI.mul,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int64.ltu,CC.Integers.Int64.iwordsize,CC.Integers.MI.iwordsize,checked]
private theorem tag_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (tags : CC.Block) (i : Fin 16) :
    CC.doStep world (.State handler tagSet k e (wordTemps le i tags) m) =
      some (CC.E0,.State handler .Sskip k e (tagTemps le i tags) m) := by
  rw [source.2.2.2.2.2.1]
  simp only [CC.doStep,tag_eval e le m tags i,tagTemps]

/-- The actual source-tag loop retains its genuine volatile word load,
original shifts and byte casts, and both real loop exits. Internal source
segments flank the actual builtin in the unchanged imported Step2 relation. -/
theorem read (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry tags : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hsource : le.get Arm64Program.___a64_mt_src = some (.Vlong (Arm64MemcpyTransferSourceAddress.position i)))
    (headerRead : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0))
    (wordRead : CC.Mem.load .Mint64 m tags 8 = some (.Vlong 0)) :
    CC.Star (CC.Step2 world)
      (.State handler Arm64MemcpyTransferSourceAddress.tagLoop k e le m) CC.E0
      (.State handler .Sskip k e (tagTemps le i tags) m) := by
  let readCont := CC.Cont.Kseq tagSet (loopCont k)
  have prefixRun : InternalRun world 8
      (.State handler Arm64MemcpyTransferSourceAddress.tagLoop k e le m)
      (.State handler load readCont e (headerTemps le i tags) m) := by
    rw [source.1]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [source.2.1]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (index_step e le m _ i hsource)) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [source.2.2.1]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [source.2.2.2.1]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e le m _ entry tags i hentry headerRead)) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have oneRead : CC.Star (CC.Step2 world)
      (.State handler load readCont e (headerTemps le i tags) m) CC.E0
      (.State handler .Sskip readCont e (wordTemps le i tags) m) :=
    .step _ _ _ _ _ _ (load_step e le m readCont tags i wordRead) (.refl _) rfl
  have finish : InternalRun world 4
      (.State handler .Sskip readCont e (wordTemps le i tags) m)
      (.State handler .Sskip k e (tagTemps le i tags) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (tag_step e le m _ tags i)) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans prefixRun.sound oneRead) finish.sound

private theorem selector_test (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0)) :
    CC.doEvalExpr world e le m selectorTest = some (.Vint 0) := by
  simp +decide [selectorTest,CC.doEvalExpr,tag,CC.Cop.semBinaryOperation,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeof,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tuchar,CC.tuint,CC.tint,CC.Integers.Int.repr,CC.Integers.MI.repr,
    CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Val.ofBool]
private theorem selector_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0)) :
    CC.doStep world (.State handler selector k e le m) =
      some (CC.E0,.State handler selectorNo k e le m) := by
  rw [payload_source.2.1]
  simp only [CC.doStep,selector_test e le m tag]
  rfl
private theorem selector_no_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0)) :
    CC.doStep world (.State handler selectorNo k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'76 (.Vint 0)) m) := by
  rw [payload_source.2.2.1]
  simp +decide [CC.doStep,selectorValue,CC.doEvalExpr,tag,CC.Cop.semBinaryOperation,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.boolVal,CC.Cop.classifyBool,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuchar,CC.tuint,CC.tint,CC.tbool,
    CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
    CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse]
private theorem leave (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (tags : CC.Block) (i : Fin 16) :
    InternalRun world 7
      (.State handler .Sskip (Arm64MemcpyTransferSourceAddress.continuation k) e (tagTemps le i tags) m)
      (.State handler Arm64MemcpyTransferCopyTag.tagStore k e (temps le i tags) m) := by
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [payload_source.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (selector_step e _ m _ (CC.PTree.gss _ _ _))) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (selector_no_step e _ m _ (CC.PTree.gss _ _ _))) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [payload_source.2.2.2]
  refine .step (mid := .State handler .Sskip (Arm64MemcpyTransferCopyGates.continuation k) e (temps le i tags) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Real source-tag word0 makes both original tag4/tag10 payload tests
false and reaches the genuine destination-tag store loop. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry tags : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hsource : le.get Arm64Program.___a64_mt_src = some (.Vlong (Arm64MemcpyTransferSourceAddress.position i)))
    (headerRead : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0))
    (wordRead : CC.Mem.load .Mint64 m tags 8 = some (.Vlong 0)) :
    CC.Star (CC.Step2 world)
      (.State handler Arm64MemcpyTransferSourceAddress.tagLoop (Arm64MemcpyTransferSourceAddress.continuation k) e le m) CC.E0
      (.State handler Arm64MemcpyTransferCopyTag.tagStore k e (temps le i tags) m) := by
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans
    (read e le m (Arm64MemcpyTransferSourceAddress.continuation k) entry tags i hentry hsource headerRead wordRead)
    (leave e le m k tags i).sound

private def changed : List CC.Ident := [Arm64Program._t'76,Arm64Program.___a64_mt_tag,
  Arm64Program._t'74,Arm64Program._t'93,Arm64Program.___ti__6]
theorem kept (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) (id : CC.Ident) (other : id ∉ changed) :
    (temps le i tags).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  simp only [temps,tagTemps,wordTemps,headerTemps,indexTemps,
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'76 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___a64_mt_tag (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'74 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'93 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___ti__6 (by decide +kernel))]
theorem observations (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) :
    (temps le i tags).get Arm64Program.___a64_mt_tag = some (.Vint 0) ∧
    (temps le i tags).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le i tags).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le i tags).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
    (temps le i tags).get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at := by
  refine ⟨?_,kept le i tags _ (by decide +kernel),kept le i tags _ (by decide +kernel),
    kept le i tags _ (by decide +kernel),kept le i tags _ (by decide +kernel)⟩
  simp only [temps,tagTemps,
    CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'76 ≠ Arm64Program.___a64_mt_tag),CC.PTree.gss]

/-- The same actual packet's24 byte-zero observations derive the real
word load. The current theorem introduces no later successful-load premise. -/
theorem current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le)
    (hsource : le.get Arm64Program.___a64_mt_src = some (.Vlong (Arm64MemcpyTransferSourceAddress.position i))) :
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m (temps le i base.tags.block),
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyTransferSourceAddress.tagLoop (Arm64MemcpyTransferSourceAddress.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 le m) CC.E0
        (.State handler Arm64MemcpyTransferCopyTag.tagStore k (Arm64MemcpySource.allocation calleeBefore).1
          (temps le i base.tags.block) m) := by
  have headerRead := prior.packet.view.tagPointer
  rw [prior.packet.tagsSame] at headerRead
  have wordRead := Arm64MemsetTagWords.original m base.tags.block prior.packet.tagBytes (1 : Fin 3)
  refine ⟨⟨prior.packet,prior.callee,?_,?_,?_,?_,prior.copied⟩,
    execute _ le m k entry.block base.tags.block i prior.entryRead hsource headerRead wordRead⟩
  · exact (kept le i _ Arm64Program._entry (by decide +kernel)).trans prior.entryRead
  · exact (kept le i _ Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length
  · exact (kept le i _ Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter
  · exact (kept le i _ Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag

end KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceTag
