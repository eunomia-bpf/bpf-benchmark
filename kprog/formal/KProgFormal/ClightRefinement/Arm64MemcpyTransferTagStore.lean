import KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceTag
import KProgFormal.ClightRefinement.Arm64MemcpyTagFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferTagStore

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  tagBody : CC.Stmt
  tiSet : CC.Stmt
  shiftRest : CC.Stmt
  shiftSet : CC.Stmt
  address : CC.Stmt
  header : CC.Stmt
  pointer : CC.Stmt
  statement : CC.Stmt
  load : CC.Stmt
  copy : CC.Stmt
  store : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy destination tag store changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferCopyTag.tagStore)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let shift ← peel body[1]! ``CC.Stmt.Ssequence 2
    let address ← peel shift[1]! ``CC.Stmt.Ssequence 2
    let pointer ← peel address[0]! ``CC.Stmt.Ssequence 2
    let statement ← peel address[1]! ``CC.Stmt.Ssequence 2
    let read ← peel statement[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_destination_tag_store
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,body[0]!,body[1]!,shift[0]!,shift[1]!,
        pointer[0]!,pointer[1]!,address[1]!,read[0]!,read[1]!,statement[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_destination_tag_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def tagBody : CC.Stmt := by run_tac cachePart (← `(parts.tagBody))
private def tiSet : CC.Stmt := by run_tac cachePart (← `(parts.tiSet))
private def shiftRest : CC.Stmt := by run_tac cachePart (← `(parts.shiftRest))
private def shiftSet : CC.Stmt := by run_tac cachePart (← `(parts.shiftSet))
private def address : CC.Stmt := by run_tac cachePart (← `(parts.address))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def pointer : CC.Stmt := by run_tac cachePart (← `(parts.pointer))
private def statement : CC.Stmt := by run_tac cachePart (← `(parts.statement))
private def load : CC.Stmt := by run_tac cachePart (← `(parts.load))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
private def store : CC.Stmt := by run_tac cachePart (← `(parts.store))
private theorem tag_loop_source : Arm64MemcpyTransferCopyTag.tagStore = .Sloop tagBody .Sbreak := rfl
private theorem tag_body_source : tagBody = .Ssequence tiSet shiftRest := rfl
private theorem shift_source : shiftRest = .Ssequence shiftSet address := rfl
private theorem address_source : address = .Ssequence (.Ssequence header pointer) statement := rfl
private theorem statement_source : statement = .Ssequence (.Ssequence load copy) store := rfl

def position (high : Bool) : BitVec 64 := if high then 88 else 80
private def tagIndex (high : Bool) : BitVec 64 := if high then 11 else 10
private def tagShift (high : Bool) : BitVec 32 := if high then 24 else 16
private def mathTemps (le : CC.TempEnv) (high : Bool) : CC.TempEnv :=
  (le.set Arm64Program.___ti__7 (.Vlong (tagIndex high))).set Arm64Program.___ts__6 (.Vint (tagShift high))
def preparedTemps (le : CC.TempEnv) (high : Bool) (tags : CC.Block) : CC.TempEnv :=
  ((mathTemps le high).set Arm64Program._t'88 (.Vptr tags 0)).set Arm64Program.___tp__6 (.Vptr tags 8)
private def tagCont (k : CC.Cont) : CC.Cont := .Kloop1 tagBody .Sbreak k

private theorem math_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (high : Bool)
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position high))) :
    InternalRun world 7 (.State handler Arm64MemcpyTransferCopyTag.tagStore k e le m)
      (.State handler address (tagCont k) e (mathTemps le high) m) := by
  cases high <;> apply internalRun_of_steps
  all_goals simp +decide [steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,hat,
    tag_loop_source,tag_body_source,shift_source,tiSet,shiftSet,mathTemps,tagCont,tagIndex,tagShift,position,
    CC.PTree.gss,CC.PTree.gso,CC.Cop.semBinaryOperation,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
    CC.Cop.semAnd,CC.Cop.semMul,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.Cop.castIntInt,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tint,CC.Archi.ptr64,
    CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.shru,CC.Integers.MI.shru,
    CC.Integers.Int.ltu,CC.Integers.MI.ltu,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.Integers.Int64.mul,CC.Integers.MI.mul,CC.Integers.Int64.unsigned,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.E0,CC.Eapp]

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._stack_tags entryComposite.co_members = .OK (648,.Full) := by
  constructor <;> decide +kernel

private theorem header_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry tags : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    CC.doStep world (.State handler header k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'88 (.Vptr tags 0)) m) := by
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tulong,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 648).toNat) : Nat) : Int) = 648 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 648 = some (.Vptr tags 0) from read]

private theorem address_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (high : Bool)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 6 (.State handler address (tagCont k) e (mathTemps le high) m)
      (.State handler statement (tagCont k) e (preparedTemps le high tags) m) := by
  have carried : (mathTemps le high).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [mathTemps,CC.PTree.gso] using hentry
  rw [address_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e _ m _ entry tags carried read)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq statement (tagCont k)) e (preparedTemps le high tags) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · cases high <;> simp +decide [pointer,CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,mathTemps,
      preparedTemps,tagIndex,tagShift,CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semAdd,CC.Cop.classifyAdd,
      CC.Cop.semAddPtrLong,CC.Cop.semUnaryOperation,CC.Cop.semNotint,CC.Cop.classifyNotint,
      CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tvolatile,CC.tulong,CC.tuchar,
      CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,CC.Integers.Int64.not,CC.Integers.MI.not,
      CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
      CC.Integers.Ptrofs.repr,CC.Integers.Ptrofs.of_int64,CC.Integers.MI.add,CC.Integers.MI.mul,BitVec.ofInt_natCast]
    all_goals rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The two selected original transfer positions calculate their real shift,
read the original tag header and reach this source's own volatile statement. -/
theorem to_statement (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (high : Bool)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position high)))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 13 (.State handler Arm64MemcpyTransferCopyTag.tagStore k e le m)
      (.State handler statement (tagCont k) e (preparedTemps le high tags) m) :=
  (math_setup e le m k high hat).trans (address_setup e le m k entry tags high hentry read)

private def builtinArgs (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  unless actual.isAppOfArity ``CC.Stmt.Sbuiltin 4 do throwError "original transfer tag builtin changed"
  Lean.Elab.Tactic.closeMainGoal `actual_transfer_builtin_arguments actual.getAppArgs[3]!
private def loadArgs : List CC.Expr := by run_tac builtinArgs (← `(load))
private def storeArgs : List CC.Expr := by run_tac builtinArgs (← `(store))
private theorem load_source : load = .Sbuiltin (some Arm64Program._t'85) (.EF_vload .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong)] loadArgs := rfl
private theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] storeArgs := rfl
private def rmwTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'85 (.Vlong 0)).set Arm64Program.___tv__6 (.Vlong 0)

private theorem load_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block)
    (pointer : le.get Arm64Program.___tp__6 = some (.Vptr tags 8)) :
    CC.doEvalExprlist world e le m loadArgs [CC.tptr (CC.tvolatile CC.tulong)] = some [.Vptr tags 8] := by
  simp only [loadArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,CC.typeof,CC.Cop.semCast,
    CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tptr,CC.tvolatile,CC.tulong,CC.tattr,CC.Archi.ptr64]

private theorem store_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block) (high : Bool)
    (pointer : le.get Arm64Program.___tp__6 = some (.Vptr tags 8))
    (shift : le.get Arm64Program.___ts__6 = some (.Vint (tagShift high)))
    (word : le.get Arm64Program.___tv__6 = some (.Vlong 0))
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0)) :
    CC.doEvalExprlist world e le m storeArgs
      [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] = some [.Vptr tags 8,.Vlong 0] := by
  cases high <;> simp only [storeArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,shift,word,tag,
    tagShift,CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semOr,CC.Cop.semShl,CC.Cop.semShift,
    CC.Cop.classifyShift,CC.Cop.semUnaryOperation,CC.Cop.semNotint,CC.Cop.classifyNotint,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tptr,CC.tvolatile,CC.tulong,CC.tuint,CC.tuchar,CC.Archi.ptr64,CC.Integers.Int.repr,
    CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.shl,CC.Integers.MI.shl,
    CC.Integers.Int64.not,CC.Integers.MI.not,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.Integers.Int64.or,CC.Integers.MI.or,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.ltu,CC.Integers.MI.ltu]
  all_goals rfl

private theorem read_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (tags : CC.Block)
    (pointer : le.get Arm64Program.___tp__6 = some (.Vptr tags 8))
    (observed : CC.Mem.load .Mint64 m tags 8 = some (.Vlong 0)) :
    CC.Step2 world (.State handler load k e le m) CC.E0
      (.State handler .Sskip k e (le.set Arm64Program._t'85 (.Vlong 0)) m) := by
  rw [load_source]
  apply CC.Step.builtin (vargs := [.Vptr tags 8]) (vres := .Vlong 0)
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (load_arguments e le m tags pointer)
  · exact CC.VolatileLoadSem.intro _ _ _ _ _ _
      (.nonvol _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags) observed)

private theorem write_step (e : CC.Env) (le : CC.TempEnv) (m after : CC.Mem) (k : CC.Cont) (tags : CC.Block) (high : Bool)
    (pointer : le.get Arm64Program.___tp__6 = some (.Vptr tags 8))
    (shift : le.get Arm64Program.___ts__6 = some (.Vint (tagShift high)))
    (word : le.get Arm64Program.___tv__6 = some (.Vlong 0))
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0))
    (stored : CC.Mem.store .Mint64 m tags 8 (.Vlong 0) = some after) :
    CC.Step2 world (.State handler store k e le m) CC.E0 (.State handler .Sskip k e le after) := by
  rw [store_source]
  apply CC.Step.builtin (vargs := [.Vptr tags 8,.Vlong 0]) (vres := .Vundef)
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (store_arguments e le m tags high pointer shift word tag)
  · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
      (.nonvol _ _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags) stored)

/-- This source's own volatile load, copy and original clear expression
perform the real zero-word store, at either actual selected shift. -/
theorem statement_execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (tags : CC.Block) (high : Bool)
    (pointer : le.get Arm64Program.___tp__6 = some (.Vptr tags 8))
    (shift : le.get Arm64Program.___ts__6 = some (.Vint (tagShift high)))
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0))
    (observed : CC.Mem.load .Mint64 m tags 8 = some (.Vlong 0))
    (range : CC.Mem.rangePerm m tags 0 24 .Cur .Writable = true) :
    ∃ after,
      CC.Star (CC.Step2 world) (.State handler statement k e le m) CC.E0
        (.State handler .Sskip k e (rmwTemps le) after) ∧
      CC.Mem.store .Mint64 m tags 8 (.Vlong 0) = some after ∧
      CC.Mem.load .Mint64 after tags 8 = some (.Vlong 0) ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have valid : CC.Mem.validAccess m .Mint64 tags 8 .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro pos low high
      exact CC.Mem.rangePerm_perm m tags 0 24 .Cur .Writable range pos (by omega)
        (by change pos < (8 : Int) + 8 at high; omega)
    · decide +kernel
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint64 m tags 8 (.Vlong 0) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  let readCont := CC.Cont.Kseq copy (.Kseq store k)
  have enter : InternalRun world 2 (.State handler statement k e le m) (.State handler load readCont e le m) := by
    rw [statement_source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have first := read_step e le m readCont tags pointer observed
  have middle : InternalRun world 3
      (.State handler .Sskip readCont e (le.set Arm64Program._t'85 (.Vlong 0)) m)
      (.State handler store k e (rmwTemps le) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step (mid := .State handler .Sskip (.Kseq store k) e (rmwTemps le) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [copy,CC.doStep,CC.doEvalExpr,CC.PTree.gss,rmwTemps]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have last := write_step e (rmwTemps le) m after k tags high
    (by simpa +decide only [rmwTemps,CC.PTree.gso] using pointer)
    (by simpa +decide only [rmwTemps,CC.PTree.gso] using shift)
    (by simp only [rmwTemps,CC.PTree.gss])
    (by simpa +decide only [rmwTemps,CC.PTree.gso] using tag) stored
  have oneRead : CC.Star (CC.Step2 world) (.State handler load readCont e le m) CC.E0
      (.State handler .Sskip readCont e (le.set Arm64Program._t'85 (.Vlong 0)) m) :=
    .step _ _ _ _ _ _ first (.refl _) rfl
  have oneWrite : CC.Star (CC.Step2 world) (.State handler store k e (rmwTemps le) m) CC.E0
      (.State handler .Sskip k e (rmwTemps le) after) := .step _ _ _ _ _ _ last (.refl _) rfl
  refine ⟨after,?_,stored,?_,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using
      star_trans (star_trans (star_trans enter.sound oneRead) middle.sound) oneWrite
  · exact CC.Mem.load_store_same stored

private theorem exit_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.State handler .Sskip (tagCont k) e le m) (.State handler .Sskip k e le m) := by
  apply internalRun_of_steps
  · simp [steps,InternalPath,InternalState,CC.doStep,tagCont]
  · rfl

def temps (le : CC.TempEnv) (high : Bool) (tags : CC.Block) : CC.TempEnv :=
  rmwTemps (preparedTemps le high tags)

/-- The original destination loop retains its true address setup, volatile
load and store, original mask expression, and both actual loop exits. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags : CC.Block) (high : Bool)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position high)))
    (headerRead : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0))
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0))
    (range : CC.Mem.rangePerm m tags 0 24 .Cur .Writable = true)
    (zero : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m tags (j.val : Int) = some (.Vint 0)) :
    ∃ after, CC.Star (CC.Step2 world)
      (.State handler Arm64MemcpyTransferCopyTag.tagStore k e le m) CC.E0
      (.State handler .Sskip k e (temps le high tags) after) ∧
      CC.Mem.store .Mint64 m tags 8 (.Vlong 0) = some after ∧
      CC.Mem.load .Mint64 after tags 8 = some (.Vlong 0) ∧
      FrameBelow m.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have prefixRun := to_statement e le m k entry tags high hentry hat headerRead
  have pointer : (preparedTemps le high tags).get Arm64Program.___tp__6 = some (.Vptr tags 8) := CC.PTree.gss _ _ _
  have shift : (preparedTemps le high tags).get Arm64Program.___ts__6 = some (.Vint (tagShift high)) := by
    simp only [preparedTemps,mathTemps,
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program.___tp__6 ≠ Arm64Program.___ts__6),
      CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'88 ≠ Arm64Program.___ts__6),CC.PTree.gss]
  have scalar : (preparedTemps le high tags).get Arm64Program.___a64_mt_tag = some (.Vint 0) := by
    simpa +decide only [preparedTemps,mathTemps,CC.PTree.gso] using tag
  have word := Arm64MemsetTagWords.original m tags zero (1 : Fin 3)
  obtain ⟨after,run,stored,read,access,next⟩ := statement_execute e (preparedTemps le high tags) m
    (tagCont k) tags high pointer shift scalar word range
  refine ⟨after,?_,stored,read,Arm64MemcpyTagFrame.word_store stored zero m.nextblock,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using
    star_trans (star_trans prefixRun.sound run) (exit_loop e (temps le high tags) after k).sound

private def changed : List CC.Ident := [Arm64Program.___tv__6,Arm64Program._t'85,Arm64Program.___tp__6,
  Arm64Program._t'88,Arm64Program.___ts__6,Arm64Program.___ti__7]
theorem kept (le : CC.TempEnv) (high : Bool) (tags : CC.Block) (id : CC.Ident) (other : id ∉ changed) :
    (temps le high tags).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  simp only [temps,rmwTemps,preparedTemps,mathTemps,
    CC.PTree.gso _ _ _ _ (different Arm64Program.___tv__6 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'85 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___tp__6 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'88 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___ts__6 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program.___ti__7 (by decide +kernel))]

theorem observations (le : CC.TempEnv) (high : Bool) (tags : CC.Block) :
    (temps le high tags).get Arm64Program.___a64_mt_tag = le.get Arm64Program.___a64_mt_tag ∧
    (temps le high tags).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le high tags).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le high tags).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
    (temps le high tags).get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at :=
  ⟨kept le high tags _ (by decide +kernel),kept le high tags _ (by decide +kernel),
    kept le high tags _ (by decide +kernel),kept le high tags _ (by decide +kernel),kept le high tags _ (by decide +kernel)⟩

/-- Actual current Freeable rights derive the original destination store.
The whole packet, copied bytes, caller locals and typed flag survive it. -/
theorem current {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (high : Bool)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position high)))
    (tag : le.get Arm64Program.___a64_mt_tag = some (.Vint 0))
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 after
      (temps le high base.tags.block), CC.Star (CC.Step2 world)
      (.State handler Arm64MemcpyTransferCopyTag.tagStore k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
      (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 (temps le high base.tags.block) after) ∧
      CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some after ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      after.nextblock = before.nextblock := by
  have rights := prior.packet.resources.freeable _ _ (Arm64ProgramEntryRawSetup.tag_binding initial base.tags)
  change CC.Mem.rangePerm before base.tags.block 0 24 .Cur .Freeable = true at rights
  have range := CC.Mem.rangePerm_implies rights (by decide : CC.permOrder .Freeable .Writable = true)
  have headerRead := prior.packet.view.tagPointer
  rw [prior.packet.tagsSame] at headerRead
  obtain ⟨after,run,stored,_read,frame,_access,next⟩ := execute _ le before k entry.block base.tags.block high
    prior.entryRead hat headerRead tag range prior.packet.tagBytes
  let current := Arm64MemcpyTagFrame.current prior producerBound callerBound stored
  have retained : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 after
      (temps le high base.tags.block) := by
    refine ⟨current.packet,current.callee,?_,?_,?_,?_,current.copied⟩
    · exact (kept le high _ Arm64Program._entry (by decide +kernel)).trans current.entryRead
    · exact (kept le high _ Arm64Program.___a64_lib_len (by decide +kernel)).trans current.length
    · exact (kept le high _ Arm64Program.___a64_lib_i (by decide +kernel)).trans current.counter
    · exact (kept le high _ Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans current.sourceTag
  exact ⟨after,retained,run,stored,frame,flag.frame before.nextblock producerBound frame,next⟩

end KProgFormal.ClightRefinement.Arm64MemcpyTransferTagStore
