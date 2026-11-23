import KProgFormal.ClightRefinement.Arm64FmovDestinationSite
import KProgFormal.ClightRefinement.Arm64MovKeepLinked

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Fmov.ReadEntry

private structure Pieces where
  indexPrefix : CC.Stmt
  guard : CC.Expr
  badIndex : CC.Stmt
  dirSet : CC.Stmt
  pointerSet : CC.Stmt
  vectorSet : CC.Stmt
  readCall : CC.Stmt
  srcSet : CC.Stmt
  tail : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original FMOV read constructor changed"
      pure actual.getAppArgs
    let branch ← peel (← Lean.Elab.Term.elabTerm (← `(DestinationSite.branch)) none) ``CC.Stmt.Ssequence 2
    let guard ← peel branch[1]! ``CC.Stmt.Sifthenelse 3
    let body ← peel (← Lean.Elab.Term.elabTerm (← `(DestinationSite.body)) none) ``CC.Stmt.Ssequence 2
    let reads ← peel body[1]! ``CC.Stmt.Ssequence 2
    let vector ← peel reads[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel reads[1]! ``CC.Stmt.Ssequence 2
    let scalar ← peel rest[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_fmov_reads (← Lean.Meta.mkAppM ``Pieces.mk
      #[branch[0]!,guard[0]!,guard[1]!,body[0]!,vector[0]!,vector[1]!,scalar[0]!,scalar[1]!,rest[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_fmov_read_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def indexPrefix : CC.Stmt := by run_tac cachePart (← `(pieces.indexPrefix))
private def guard : CC.Expr := by run_tac cachePart (← `(pieces.guard))
private def badIndex : CC.Stmt := by run_tac cachePart (← `(pieces.badIndex))
private def dirSet : CC.Stmt := by run_tac cachePart (← `(pieces.dirSet))
private def pointerSet : CC.Stmt := by run_tac cachePart (← `(pieces.pointerSet))
private def vectorSet : CC.Stmt := by run_tac cachePart (← `(pieces.vectorSet))
private def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.readCall))
private def srcSet : CC.Stmt := by run_tac cachePart (← `(pieces.srcSet))
def tail : CC.Stmt := by run_tac cachePart (← `(pieces.tail))

theorem branch_source : DestinationSite.branch = .Ssequence indexPrefix
    (.Sifthenelse guard badIndex (.Ssequence (.Sloop DestinationSite.body .Sbreak) DestinationSite.site)) := rfl

theorem body_source : DestinationSite.body = .Ssequence dirSet
    (.Ssequence (.Ssequence pointerSet vectorSet) (.Ssequence (.Ssequence readCall srcSet) tail)) := rfl

private def entryComposite : CC.Composite :=
  (Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layouts :
    Arm64ProgramEntryLinked.ge.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset Arm64ProgramEntryLinked.ge.genv_cenv Arm64Program._vector_lo entryComposite.co_members = .OK (96,.Full) ∧
    CC.sizeof Arm64ProgramEntryLinked.ge.genv_cenv (CC.tptr CC.tulong) = 8 := by
  constructor
  · decide +kernel
  constructor <;> decide +kernel

private theorem pointer_offset :
    (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 96 +
      CC.Integers.Ptrofs.repr 8 * BitVec.zeroExtend CC.Archi.ptrWordsize (3#32) =
      CC.Integers.Ptrofs.repr 120 := by decide +kernel

private theorem pointer_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (index : le.get Arm64Program.___a64_fmov_index = some (.Vint (3#32)))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr 120)) = some (.Vptr vb vo)) :
    CC.Step2 Arm64ProgramEntryLinked.ge (.State Arm64Nop.handler pointerSet k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program._t'2840 (.Vptr vb vo)) m) := by
  apply CC.doStep_sound
  simp +decide only [pointerSet,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfField,CC.typeof,
    entry,index,CC.doDerefLoc,CC.accessMode,CC.Cop.semBinaryOperation,CC.Cop.semAdd,
    CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong,CC.tptr,CC.tarray,CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,ite_true,ite_false,
    layouts.1,layouts.2.1,layouts.2.2,CC.Val.offsetPtr,CC.Cop.ptrofsOfInt,CC.Integers.Ptrofs.of_intu,
    CC.Integers.Ptrofs.of_int,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
    CC.Integers.MI.add,CC.Integers.MI.mul,slot] <;> try rfl
  change (match CC.Mem.loadv CC.Mptr m (.Vptr b
      ((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 96 +
        CC.Integers.Ptrofs.repr 8 * BitVec.zeroExtend CC.Archi.ptrWordsize (3#32))) with
    | some value => some (CC.E0,CC.State.State Arm64Nop.handler .Sskip k e (le.set Arm64Program._t'2840 value) m)
    | none => none) = _
  rw [pointer_offset,slot]


private theorem vector_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow : BitVec 64)
    (pointer : le.get Arm64Program._t'2840 = some (.Vptr vb vo))
    (word : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong oldLow)) :
    CC.Step2 world (.State Arm64Nop.handler vectorSet k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program.___kprog_a64_fmov_v0 (.Vlong oldLow)) m) := by
  apply CC.doStep_sound
  simp only [vectorSet,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,
    CC.accessMode,CC.typeof,pointer,word,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong] <;> rfl

private theorem dir_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (aux : le.get Arm64Program._aux = some (.Vint 0)) :
    CC.Step2 world (.State Arm64Nop.handler dirSet k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program.___kprog_a64_fmov_dir (.Vlong 0)) m) := by
  apply CC.doStep_sound
  simp only [dirSet,CC.doStep,CC.doEvalExpr,aux,CC.typeof,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong]
  rfl

private def indexTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'2786 (.Vlong (3#64))).set Arm64Program.___a64_fmov_index (.Vint (3#32))
private def baseTemps (le : CC.TempEnv) : CC.TempEnv :=
  (indexTemps le).set Arm64Program.___kprog_a64_fmov_dir (.Vlong 0)
private theorem base_entry (le : CC.TempEnv) (b : CC.Block)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0)) :
    (baseTemps le).get Arm64Program._entry = some (.Vptr b 0) := by
  unfold baseTemps indexTemps
  rw [CC.PTree.gso _ _ _ _ (by decide +kernel),CC.PTree.gso _ _ _ _ (by decide +kernel),
    CC.PTree.gso _ _ _ _ (by decide +kernel)]
  exact entry
private theorem base_index (le : CC.TempEnv) :
    (baseTemps le).get Arm64Program.___a64_fmov_index = some (.Vint (3#32)) :=
  (CC.PTree.gso _ _ _ _ (by decide +kernel :
    Arm64Program.___kprog_a64_fmov_dir ≠ Arm64Program.___a64_fmov_index)).trans (CC.PTree.gss _ _ _)

def preparedTemps (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow : BitVec 64) : CC.TempEnv :=
  ((baseTemps le).set Arm64Program._t'2840 (.Vptr vb vo)).set Arm64Program.___kprog_a64_fmov_v0 (.Vlong oldLow)

def innerCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 DestinationSite.body .Sbreak (.Kseq DestinationSite.site k)
def readCont (k : CC.Cont) : CC.Cont := .Kseq srcSet (.Kseq tail (innerCont k))
def callCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'2787) Arm64Nop.handler e le (readCont k)

set_option hygiene false in
/-- Real index selection, range guard, direction and two old-vector loads,
up to the original scalar-read call. Pre-memory observations determine temps. -/
theorem prepare (b vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow : BitVec 64)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (index : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr 120)) = some (.Vptr vb vo))
    (word : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong oldLow)) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler DestinationSite.branch k e le m)
      (.State Arm64Nop.handler readCall (readCont k) e (preparedTemps le vb vo oldLow) m) := by
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:80] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``readCall then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual FMOV read preparation transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``dirSet then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply dir_step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]; exact aux))
        continue
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``pointerSet then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply pointer_step (b := b) (vb := vb) (vo := vo)))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact base_entry le b entry))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact base_index le))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact slot))
        continue
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``vectorSet then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply vector_step (vb := vb) (vo := vo) (oldLow := oldLow)))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact CC.PTree.gss _ _ _))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact word))
        continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,branch_source,body_source,
        indexPrefix,guard,dirSet,preparedTemps,baseTemps,indexTemps,innerCont,readCont,index,aux,
        CC.PTree.gss,CC.PTree.gso,CC.doEvalExpr,CC.typeof,CC.Cop.semBinaryOperation,
        CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.Cop.castIntInt,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tint,CC.tulong,
        CC.Integers.Int64.repr,CC.Integers.Int.repr,CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,
        CC.Integers.Int64.cmpu,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.MI.unsigned,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Integers.Int64.eq,CC.Integers.Int.eq,CC.Integers.MI.eq,
        CC.Integers.Int64.zero,CC.Integers.Int.zero,CC.Integers.MI.zero,CC.Integers.MI.repr,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false] <;> try rfl))
    unless finished do throwError "FMOV prefix has further steps before scalar call"

private theorem read_source : readCall = .Scall (some Arm64Program._t'2787)
    (.Evar Arm64Program._kprog_arm64_program_read
      (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong] CC.tulong CC.cc_default))
    [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
     .Etempvar Arm64Program._src CC.tulong] := rfl

private theorem read_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (reg : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (source : le.get Arm64Program._src = some (.Vlong reg)) :
    CC.Step2 Arm64ProgramEntryLinked.ge (.State Arm64Nop.handler readCall (readCont k) e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b 0,.Vlong reg] (callCont k e le) m) := by
  rw [read_source]
  have binding := Arm64MovKeep.Linked.reader_binding
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 66) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,CC.accessMode,
      CC.typeof,unshadowed,binding.1,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    simp +decide [CC.doEvalExprlist,CC.doEvalExpr,entry,source,CC.typeof,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tulong]
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

def valueTemps (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow value : BitVec 64) : CC.TempEnv :=
  ((preparedTemps le vb vo oldLow).set Arm64Program._t'2787 (.Vlong value)).set
    Arm64Program.___kprog_a64_fmov_src (.Vlong value)

set_option hygiene false in
theorem returned (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow value : BitVec 64) :
    InternalRun world 4 (.Returnstate (.Vlong value) (callCont k e (preparedTemps le vb vo oldLow)) m)
      (.State Arm64Nop.handler tail (innerCont k) e (valueTemps le vb vo oldLow value) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,callCont,readCont,srcSet,valueTemps,
        CC.setOpttemp,CC.PTree.gss,CC.doEvalExpr,CC.typeof,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Actual old-vector pre-loads and original scalar word/tag storage derive
both operands and the real helper return, preserving the complete heap. -/
theorem scalar {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (i : Fin 31)
    (vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow value : BitVec 64)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr entry.block (CC.Integers.Ptrofs.repr 120)) = some (.Vptr vb vo))
    (oldVector : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler DestinationSite.branch k e le m)
      (.State Arm64Nop.handler tail (innerCont k) e (valueTemps le vb vo oldLow value) m) := by
  obtain ⟨count,prefixRun⟩ := prepare entry.block vb vo oldLow e le m k entryRead index aux slot oldVector
  have pEntry : (preparedTemps le vb vo oldLow).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    unfold preparedTemps baseTemps indexTemps
    repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact entryRead
  have pSource : (preparedTemps le vb vo oldLow).get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    unfold preparedTemps baseTemps indexTemps
    repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact source
  have call : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler readCall (readCont k) e (preparedTemps le vb vo oldLow) m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr entry.block 0,.Vlong (BitVec.ofNat 64 i.val)]
        (callCont k e (preparedTemps le vb vo oldLow)) m) :=
    .step trivial (read_step e _ m k entry.block _ unshadowed pEntry pSource) (.refl _)
  have read := Arm64MovKeep.Linked.read_scalar storage (fun _ => none) i value
    (callCont k e (preparedTemps le vb vo oldLow)) word tag
  have last := returned Arm64ProgramEntryLinked.ge e le m k vb vo oldLow value
  exact ⟨_,by simpa only [CC.callCont,callCont] using ((prefixRun.trans call).trans read).trans last⟩

end KProgFormal.ClightRefinement.Arm64Fmov.ReadEntry
