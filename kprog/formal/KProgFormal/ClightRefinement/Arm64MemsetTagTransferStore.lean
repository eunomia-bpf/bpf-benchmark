import KProgFormal.ClightRefinement.Arm64MemsetTagTransferLoop

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagTransferStore

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  tagSet : CC.Stmt
  rest : CC.Stmt
  ladder : CC.Stmt
  tagLoop : CC.Stmt
  set72 : CC.Stmt
  if72 : CC.Stmt
  if73 : CC.Stmt
  if74 : CC.Stmt
  if76 : CC.Stmt
  if77 : CC.Stmt
  yes72 : CC.Stmt
  yes73 : CC.Stmt
  yes74 : CC.Stmt
  yes76 : CC.Stmt
  yes77 : CC.Stmt
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
      unless actual.isAppOfArity ctor arity do throwError "original memset transfer store changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memset_106)) none) ``CC.Stmt.Ssequence 2
    let rest ← peel root[1]! ``CC.Stmt.Ssequence 2
    let l4 ← peel rest[0]! ``CC.Stmt.Ssequence 2
    let l3 ← peel l4[0]! ``CC.Stmt.Ssequence 2
    let l2 ← peel l3[0]! ``CC.Stmt.Ssequence 2
    let l1 ← peel l2[0]! ``CC.Stmt.Ssequence 2
    let l0 ← peel l1[0]! ``CC.Stmt.Ssequence 2
    let yes72 ← peel l0[1]! ``CC.Stmt.Sifthenelse 3
    let yes73 ← peel l1[1]! ``CC.Stmt.Sifthenelse 3
    let yes74 ← peel l2[1]! ``CC.Stmt.Sifthenelse 3
    let yes76 ← peel l3[1]! ``CC.Stmt.Sifthenelse 3
    let yes77 ← peel l4[1]! ``CC.Stmt.Sifthenelse 3
    let loop ← peel rest[1]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let shift ← peel body[1]! ``CC.Stmt.Ssequence 2
    let address ← peel shift[1]! ``CC.Stmt.Ssequence 2
    let pointer ← peel address[0]! ``CC.Stmt.Ssequence 2
    let statement ← peel address[1]! ``CC.Stmt.Ssequence 2
    let read ← peel statement[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_transfer_store_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,rest[0]!,rest[1]!,l0[0]!,l0[1]!,l1[1]!,l2[1]!,l3[1]!,l4[1]!,
        yes72[1]!,yes73[1]!,yes74[1]!,yes76[1]!,yes77[1]!,loop[0]!,body[0]!,body[1]!,shift[0]!,shift[1]!,
        pointer[0]!,pointer[1]!,address[1]!,read[0]!,read[1]!,statement[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_transfer_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def tagSet : CC.Stmt := by run_tac cachePart (← `(parts.tagSet))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def ladder : CC.Stmt := by run_tac cachePart (← `(parts.ladder))
private def tagLoop : CC.Stmt := by run_tac cachePart (← `(parts.tagLoop))
private def set72 : CC.Stmt := by run_tac cachePart (← `(parts.set72))
private def if72 : CC.Stmt := by run_tac cachePart (← `(parts.if72))
private def if73 : CC.Stmt := by run_tac cachePart (← `(parts.if73))
private def if74 : CC.Stmt := by run_tac cachePart (← `(parts.if74))
private def if76 : CC.Stmt := by run_tac cachePart (← `(parts.if76))
private def if77 : CC.Stmt := by run_tac cachePart (← `(parts.if77))
private def yes72 : CC.Stmt := by run_tac cachePart (← `(parts.yes72))
private def yes73 : CC.Stmt := by run_tac cachePart (← `(parts.yes73))
private def yes74 : CC.Stmt := by run_tac cachePart (← `(parts.yes74))
private def yes76 : CC.Stmt := by run_tac cachePart (← `(parts.yes76))
private def yes77 : CC.Stmt := by run_tac cachePart (← `(parts.yes77))
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

private def zeroSet (id : CC.Ident) : CC.Stmt := .Sset id (.Econst_int (CC.Integers.Int.repr 0) CC.tint)
private def zeroTest (id : CC.Ident) : CC.Expr := .Etempvar id CC.tint
private theorem root_source : Arm64Program.s_kprog_arm64_program_memset_106 = .Ssequence tagSet rest := rfl
private theorem rest_source : rest = .Ssequence ladder tagLoop := rfl
private theorem ladder_source : ladder = .Ssequence (.Ssequence (.Ssequence (.Ssequence (.Ssequence
    set72 if72) if73) if74) if76) if77 := rfl
private theorem set72_source : set72 = zeroSet Arm64Program._t'72 := rfl
private theorem if72_source : if72 = .Sifthenelse (zeroTest Arm64Program._t'72) yes72 (zeroSet Arm64Program._t'73) := rfl
private theorem if73_source : if73 = .Sifthenelse (zeroTest Arm64Program._t'73) yes73 (zeroSet Arm64Program._t'74) := rfl
private theorem if74_source : if74 = .Sifthenelse (zeroTest Arm64Program._t'74) yes74 (zeroSet Arm64Program._t'76) := rfl
private theorem if76_source : if76 = .Sifthenelse (zeroTest Arm64Program._t'76) yes76 (zeroSet Arm64Program._t'77) := rfl
private theorem if77_source : if77 = .Sifthenelse (zeroTest Arm64Program._t'77) yes77 .Sskip := rfl
private theorem tag_loop_source : tagLoop = .Sloop tagBody .Sbreak := rfl
private theorem tag_body_source : tagBody = .Ssequence tiSet shiftRest := rfl
private theorem shift_source : shiftRest = .Ssequence shiftSet address := rfl
private theorem address_source : address = .Ssequence (.Ssequence header pointer) statement := rfl
private theorem statement_source : statement = .Ssequence (.Ssequence load copy) store := rfl

def noCopyTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((((le).set Arm64Program.___a64_mt_tag (.Vint 0)).set Arm64Program._t'72 (.Vint 0)).set Arm64Program._t'73 (.Vint 0)).set Arm64Program._t'74 (.Vint 0)).set Arm64Program._t'76 (.Vint 0)).set Arm64Program._t'77 (.Vint 0)

private theorem zero_if (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (id : CC.Ident) (yes no : CC.Stmt) (h : le.get id = some (.Vint 0)) :
    CC.doStep world (.State handler (.Sifthenelse (zeroTest id) yes no) k e le m) =
      some (CC.E0,.State handler no k e le m) := by
  simp only [CC.doStep,zeroTest,CC.doEvalExpr,h]
  rfl

private theorem clear_branch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (input output : CC.Ident) (yes : CC.Stmt) (h : le.get input = some (.Vint 0)) :
    InternalRun world 3
      (.State handler .Sskip (.Kseq (.Sifthenelse (zeroTest input) yes (zeroSet output)) k) e le m)
      (.State handler .Sskip k e (le.set output (.Vint 0)) m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ (zero_if e le m k input yes (zeroSet output) h))
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

private def ladderTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((le.set Arm64Program._t'72 (.Vint 0)).set Arm64Program._t'73 (.Vint 0)).set
    Arm64Program._t'74 (.Vint 0)).set Arm64Program._t'76 (.Vint 0)).set Arm64Program._t'77 (.Vint 0)

private theorem ladder_run (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 20 (.State handler ladder k e le m) (.State handler .Sskip k e (ladderTemps le) m) := by
  let k4 := CC.Cont.Kseq if77 k
  let k3 := CC.Cont.Kseq if76 k4
  let k2 := CC.Cont.Kseq if74 k3
  let k1 := CC.Cont.Kseq if73 k2
  let l1 := le.set Arm64Program._t'72 (.Vint 0)
  let l2 := l1.set Arm64Program._t'73 (.Vint 0)
  let l3 := l2.set Arm64Program._t'74 (.Vint 0)
  let l4 := l3.set Arm64Program._t'76 (.Vint 0)
  have start : InternalRun world 6 (.State handler ladder k e le m)
      (.State handler .Sskip (.Kseq if72 k1) e l1 m) := by
    apply internalRun_of_steps
    · simp [steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,ladder_source,set72_source,zeroSet,k1,k2,k3,k4]
    · rfl
  have first := clear_branch e l1 m k1 Arm64Program._t'72 Arm64Program._t'73 yes72 (by simp only [l1,CC.PTree.gss])
  rw [←if72_source] at first
  have second := clear_branch e l2 m k2 Arm64Program._t'73 Arm64Program._t'74 yes73 (by simp only [l2,CC.PTree.gss])
  rw [←if73_source] at second
  have third := clear_branch e l3 m k3 Arm64Program._t'74 Arm64Program._t'76 yes74 (by simp only [l3,CC.PTree.gss])
  rw [←if74_source] at third
  have fourth := clear_branch e l4 m k4 Arm64Program._t'76 Arm64Program._t'77 yes76 (by simp only [l4,CC.PTree.gss])
  rw [←if76_source] at fourth
  have last : InternalRun world 2 (.State handler .Sskip k4 e (ladderTemps le) m)
      (.State handler .Sskip k e (ladderTemps le) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [if77_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ (zero_if e _ m k Arm64Program._t'77 yes77 .Sskip
      (by simp only [ladderTemps,CC.PTree.gss]))) (.refl _)
  exact ((((start.trans first).trans second).trans third).trans fourth).trans last

/-- Execute the original scalar tag assignment and all actual COPY0 false
arms, retaining their true subtrees and the real tag-write loop. -/
theorem no_copy (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 25 (.State handler Arm64Program.s_kprog_arm64_program_memset_106 k e le m)
      (.State handler tagLoop k e (noCopyTemps le) m) := by
  let marked := le.set Arm64Program.___a64_mt_tag (.Vint 0)
  have start : InternalRun world 4
      (.State handler Arm64Program.s_kprog_arm64_program_memset_106 k e le m)
      (.State handler ladder (.Kseq tagLoop k) e marked m) := by
    rw [root_source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [rest_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have ladder := ladder_run e marked m (.Kseq tagLoop k)
  have last : InternalRun world 1 (.State handler .Sskip (.Kseq tagLoop k) e (noCopyTemps le) m)
      (.State handler tagLoop k e (noCopyTemps le) m) := .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (start.trans ladder).trans last

def position (high : Bool) : BitVec 64 := if high then 72 else 64
private def tagIndex (high : Bool) : BitVec 64 := if high then 9 else 8
private def tagShift (high : Bool) : BitVec 32 := if high then 8 else 0
private def mathTemps (le : CC.TempEnv) (high : Bool) : CC.TempEnv :=
  (le.set Arm64Program.___ti__7 (.Vlong (tagIndex high))).set Arm64Program.___ts__6 (.Vint (tagShift high))
def preparedTemps (le : CC.TempEnv) (high : Bool) (tags : CC.Block) : CC.TempEnv :=
  ((mathTemps le high).set Arm64Program._t'81 (.Vptr tags 0)).set Arm64Program.___tp__6 (.Vptr tags 8)
private def tagCont (k : CC.Cont) : CC.Cont := .Kloop1 tagBody .Sbreak k

private theorem math_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (high : Bool)
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position high))) :
    InternalRun world 7 (.State handler tagLoop k e le m)
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
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'81 (.Vptr tags 0)) m) := by
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
    InternalRun world 13 (.State handler tagLoop k e le m)
      (.State handler statement (tagCont k) e (preparedTemps le high tags) m) :=
  (math_setup e le m k high hat).trans (address_setup e le m k entry tags high hentry read)

private def builtinArgs (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  unless actual.isAppOfArity ``CC.Stmt.Sbuiltin 4 do throwError "original transfer tag builtin changed"
  Lean.Elab.Tactic.closeMainGoal `actual_transfer_builtin_arguments actual.getAppArgs[3]!
private def loadArgs : List CC.Expr := by run_tac builtinArgs (← `(load))
private def storeArgs : List CC.Expr := by run_tac builtinArgs (← `(store))
private theorem load_source : load = .Sbuiltin (some Arm64Program._t'78) (.EF_vload .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong)] loadArgs := rfl
private theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] storeArgs := rfl
private def rmwTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'78 (.Vlong 0)).set Arm64Program.___tv__6 (.Vlong 0)

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
      (.State handler .Sskip k e (le.set Arm64Program._t'78 (.Vlong 0)) m) := by
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
      (.State handler .Sskip readCont e (le.set Arm64Program._t'78 (.Vlong 0)) m)
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
      (.State handler .Sskip readCont e (le.set Arm64Program._t'78 (.Vlong 0)) m) :=
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
  rmwTemps (preparedTemps (noCopyTemps le) high tags)

private theorem no_copy_tag (le : CC.TempEnv) :
    (noCopyTemps le).get Arm64Program.___a64_mt_tag = some (.Vint 0) := by
  have n72 : Arm64Program._t'72 ≠ Arm64Program.___a64_mt_tag := by decide +kernel
  have n73 : Arm64Program._t'73 ≠ Arm64Program.___a64_mt_tag := by decide +kernel
  have n74 : Arm64Program._t'74 ≠ Arm64Program.___a64_mt_tag := by decide +kernel
  have n76 : Arm64Program._t'76 ≠ Arm64Program.___a64_mt_tag := by decide +kernel
  have n77 : Arm64Program._t'77 ≠ Arm64Program.___a64_mt_tag := by decide +kernel
  simp only [noCopyTemps,CC.PTree.gso _ _ _ _ n72,CC.PTree.gso _ _ _ _ n73,
    CC.PTree.gso _ _ _ _ n74,CC.PTree.gso _ _ _ _ n76,CC.PTree.gso _ _ _ _ n77,CC.PTree.gss]

/-- Every original loop input needed after this real tag store survives all
COPY0, packing, header and volatile-read/copy temporary assignments. -/
theorem inputs (le : CC.TempEnv) (high : Bool) (tags : CC.Block) :
    (temps le high tags).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le high tags).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (temps le high tags).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (temps le high tags).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte ∧
    (temps le high tags).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le high tags).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le high tags).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len := by
  refine ⟨?_,?_,?_,?_,?_,?_,?_⟩ <;>
    simp +decide only [temps,rmwTemps,preparedTemps,mathTemps,noCopyTemps,CC.PTree.gso]

/-- Execute the complete actual s106 body at each of its two selected byte
positions. Both builtin operations and the real store equation stay explicit. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (high : Bool)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position high)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ after,
      CC.Star (CC.Step2 world) (.State handler Arm64Program.s_kprog_arm64_program_memset_106 k e le m) CC.E0
        (.State handler .Sskip k e (temps le high view.tags.block) after) ∧
      CC.Mem.store .Mint64 m view.tags.block 8 (.Vlong 0) = some after ∧
      CC.Mem.load .Mint64 after view.tags.block 8 = some (.Vlong 0) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) ∧
      (∀ j : Fin 24, CC.Mem.load .Mint8unsigned after view.tags.block (j.val : Int) = some (.Vint 0)) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int) =
        CC.Mem.load .Mint8unsigned m view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int)) := by
  have beforeRun := no_copy e le m k
  have entryRead : (noCopyTemps le).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simpa +decide only [noCopyTemps,CC.PTree.gso] using hentry
  have atRead : (noCopyTemps le).get Arm64Program.___a64_mt_at = some (.Vlong (position high)) := by
    simpa +decide only [noCopyTemps,CC.PTree.gso] using hat
  have setup := to_statement e (noCopyTemps le) m k entry.block view.tags.block high entryRead atRead view.tagPointer
  have pointer : (preparedTemps (noCopyTemps le) high view.tags.block).get Arm64Program.___tp__6 =
      some (.Vptr view.tags.block 8) := by simp only [preparedTemps,CC.PTree.gss]
  have shift : (preparedTemps (noCopyTemps le) high view.tags.block).get Arm64Program.___ts__6 =
      some (.Vint (tagShift high)) := by
    simp +decide only [preparedTemps,mathTemps,CC.PTree.gso,CC.PTree.gss]
  have scalar : (preparedTemps (noCopyTemps le) high view.tags.block).get Arm64Program.___a64_mt_tag = some (.Vint 0) := by
    simpa +decide only [preparedTemps,mathTemps,CC.PTree.gso] using no_copy_tag le
  have word := Arm64MemsetTagWords.original m view.tags.block tagBytes ⟨1,by decide⟩
  change CC.Mem.load .Mint64 m view.tags.block 8 = some (.Vlong 0) at word
  have writable := (Arm64MemsetStoreExecution.ranges view resources).1
  obtain ⟨after,bodyRun,stored,read,access,next⟩ := statement_execute e
    (preparedTemps (noCopyTemps le) high view.tags.block) m (tagCont k) view.tags.block high pointer shift scalar word writable
  have exit := exit_loop e (temps le high view.tags.block) after k
  have outside (chunk : CC.Chunk) (block : CC.Block) (offset : Int) (notTag : block ≠ view.tags.block) :=
    CC.Mem.load_store_other stored chunk block offset (.inl notTag)
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have stackOther : view.stack.block ≠ view.tags.block :=
    separate _ _ _ _ view.stack.binding view.tags.binding (by decide +kernel)
  refine ⟨after,?_,stored,read,FrameBelow.store view.tags.fresh stored,access,next,outside,
    Arm64MemsetTagByteTransport.word_store stored tagBytes,fun j => outside .Mint8unsigned view.stack.block
      ((Arm64MemsetStoreExecution.index j).val : Int) stackOther⟩
  simpa only [temps,CC.E0,CC.Eapp,List.nil_append] using
    star_trans (star_trans (star_trans beforeRun.sound setup.sound) bodyRun) exit.sound

section SingleStore
open Arm64Producer Arm64ProducerRegisterStorage
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial before entry)
    (stored : CC.Mem.store .Mint64 before view.tags.block 8 (.Vlong 0) = some after)
include view stored

private theorem other (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (notTag : id ≠ tailLocalName 2) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  exact CC.Mem.load_store_other stored chunk block offset (.inl
    (separate _ _ _ _ binding view.tags.binding notTag))

omit view stored
private theorem tables_other : ∀ tags, tableName tags ≠ tailLocalName 2 := by decide +kernel
private theorem cells_other : ∀ tags (i : Fin 31), tableCellName tags i ≠ tailLocalName 2 := by decide +kernel

/-- Actual single tag-word store transport preserves all architectural storage
and permissions, with the same original tables, SP, flags and vector objects. -/
def storage_after (old : Storage initial before entry) : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.roots tags)
  slots := fun tags i => (other view stored _ _ _ (old.tables tags).binding (tables_other tags) CC.Mptr _).trans (old.slots tags i)
  writable := fun tags i => (CC.Mem.validAccess_store_eq stored (cellChunk tags) ((old.tables tags).cellBlock i) 0 .Writable).trans (old.writable tags i)
  sp := old.sp
  spPointer := (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 40).trans old.spPointer
  spValue := old.spValue
  spRead := (other view stored _ _ _ old.sp.binding (by decide +kernel) .Mint64 0).trans old.spRead
  flags := old.flags
  flagPointers := fun flag => (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.flagPointers flag)
  flagWritable := fun flag => (CC.Mem.validAccess_store_eq stored .Mint8unsigned (old.flags flag).block 0 .Writable).trans (old.flagWritable flag)
  vectors := old.vectors
  vectorPointers := fun high i => (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.vectorPointers high i)
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans old.vectorWritable

include view stored

/-- The actual single tag store retains the entire current Freeable/cache
resource packet through the genuine header and access frame. -/
theorem resources_after (old : Arm64ProgramEntryResources.Resources initial before entry) :
    Arm64ProgramEntryResources.Resources initial after entry :=
  Arm64MemsetIterationResources.resources old
    (fun chunk offset => other view stored _ _ _ entry.binding (by decide +kernel) chunk offset)
    (fun block _ => congrArg (CC.PMap.get block) (CC.Mem.store_access stored))

/-- Retain the same canonical stack/tag objects and their actual header loads. -/
def view_after : Arm64MemsetHeaderView.View initial after entry where
  stack := view.stack
  tags := view.tags
  stackPointer := (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 608).trans view.stackPointer
  tagPointer := (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 648).trans view.tagPointer
  capacity := (other view stored _ _ _ entry.binding (by decide +kernel) .Mint32 656).trans view.capacity
  bias := (other view stored _ _ _ entry.binding (by decide +kernel) .Mint64 672).trans view.bias

/-- The same current register reader follows the same canonical cells after
this real tag store; each raw value/tag load is protected by allocation names. -/
theorem gpr_after (old : Storage initial before entry) (i : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage_after view stored old) i,Arm64RegisterWrite.storage_gpr old i]
  change (do let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock i) 0
             let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock i) 0
             pure (word,tag)) = _
  rw [other view stored _ _ _ ((old.tables false).cellBinding i) (cells_other false i) .Mint64 0,
    other view stored _ _ _ ((old.tables true).cellBinding i) (cells_other true i) .Mint8unsigned 0]

end SingleStore

end KProgFormal.ClightRefinement.Arm64MemsetTagTransferStore
