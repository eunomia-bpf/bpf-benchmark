import KProgFormal.ClightRefinement.Arm64MemsetReleaseTagLoop

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetReleaseTagStore

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

private structure Parts where
  body : CC.Stmt
  tiSet : CC.Stmt
  rest : CC.Stmt
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
      unless actual.isAppOfArity ctor arity do throwError "original release tag store changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetReleaseTagLoop.selected)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel body[1]! ``CC.Stmt.Ssequence 2
    let address ← peel rest[1]! ``CC.Stmt.Ssequence 2
    let header ← peel address[0]! ``CC.Stmt.Ssequence 2
    let statement ← peel address[1]! ``CC.Stmt.Ssequence 2
    let read ← peel statement[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_release_rmw_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,body[0]!,body[1]!,rest[0]!,rest[1]!,header[0]!,header[1]!,address[1]!,
        read[0]!,read[1]!,statement[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_release_rmw_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def tiSet : CC.Stmt := by run_tac cachePart (← `(parts.tiSet))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def shiftSet : CC.Stmt := by run_tac cachePart (← `(parts.shiftSet))
private def address : CC.Stmt := by run_tac cachePart (← `(parts.address))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def pointer : CC.Stmt := by run_tac cachePart (← `(parts.pointer))
def statement : CC.Stmt := by run_tac cachePart (← `(parts.statement))
private def load : CC.Stmt := by run_tac cachePart (← `(parts.load))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
private def store : CC.Stmt := by run_tac cachePart (← `(parts.store))

private theorem selected_source : Arm64MemsetReleaseTagLoop.selected = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence tiSet rest := rfl
private theorem rest_source : rest = .Ssequence shiftSet address := rfl
private theorem address_source : address = .Ssequence (.Ssequence header pointer) statement := rfl
private theorem statement_source : statement = .Ssequence (.Ssequence load copy) store := rfl

def shift (i : Fin 8) : BitVec 32 := BitVec.ofNat 32 (8 * i.val)
private def mathTemps (le : CC.TempEnv) (i : Fin 8) : CC.TempEnv :=
  (le.set Arm64Program.___ti (.Vlong (BitVec.ofNat 64 i.val))).set Arm64Program.___ts (.Vint (shift i))
private def preparedTemps (le : CC.TempEnv) (i : Fin 8) (tags : CC.Block) : CC.TempEnv :=
  ((mathTemps le i).set Arm64Program._t'231 (.Vptr tags 0)).set Arm64Program.___tp (.Vptr tags 0)
private def wordCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

private theorem wide_index : ∀ i : Fin 8,
    CC.Integers.Int64.repr (CC.Integers.Int.unsigned (BitVec.ofNat 32 i.val)) = BitVec.ofNat 64 i.val := by decide +kernel
private theorem shift_data : ∀ i : Fin 8,
    CC.Integers.Int.repr (CC.Integers.Int64.unsigned ((BitVec.ofNat 64 i.val &&& (7#64)) * (8#64))) = shift i := by decide +kernel
private theorem indices : ∀ i : Fin 8,
    i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 := by decide +kernel

private theorem ti_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 8)
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (BitVec.ofNat 32 i.val))) :
    CC.doStep world (.State helper tiSet k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program.___ti (.Vlong (BitVec.ofNat 64 i.val))) m) := by
  simp only [tiSet,CC.doStep,CC.doEvalExpr,counter,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuint,CC.tulong,CC.tattr,CC.Archi.ptr64,
    wide_index,ite_true,ite_false]

private theorem shift_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 8) :
    CC.doStep world (.State helper shiftSet k e (le.set Arm64Program.___ti (.Vlong (BitVec.ofNat 64 i.val))) m) =
      some (CC.E0,.State helper .Sskip k e (mathTemps le i) m) := by
  simp only [shiftSet,CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semMul,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntLong,CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tulong,CC.tuint,CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.mul,CC.Integers.MI.mul,mathTemps,ite_true,ite_false]
  change (match some (CC.Val.Vint (CC.Integers.Int.repr (CC.Integers.Int64.unsigned
      ((BitVec.ofNat 64 i.val &&& (7#64)) * (8#64))))) with
    | some value => some (CC.E0,CC.State.State helper .Sskip k e
        ((le.set Arm64Program.___ti (CC.Val.Vlong (BitVec.ofNat 64 i.val))).set Arm64Program.___ts value) m)
    | none => none) = _
  rw [shift_data]

private theorem math_run (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 8)
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (BitVec.ofNat 32 i.val))) :
    InternalRun world 7 (.State helper Arm64MemsetReleaseTagLoop.selected k e le m)
      (.State helper address (wordCont k) e (mathTemps le i) m) := by
  rw [selected_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (ti_step e le m _ i counter)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [rest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (shift_step e le m _ i)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._stack_tags entryComposite.co_members = .OK (648,.Full) := by
  constructor <;> decide +kernel

private theorem header_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry tags : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    CC.doStep world (.State helper header k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program._t'231 (.Vptr tags 0)) m) := by
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tulong,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,
    CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have fieldOffset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 648).toNat) : Nat) : Int) = 648 := by decide +kernel
  rw [fieldOffset,show CC.Mem.load .Mint64 m entry 648 = some (.Vptr tags 0) from read]

private theorem address_run (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry tags : CC.Block) (i : Fin 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 6 (.State helper address (wordCont k) e (mathTemps le i) m)
      (.State helper statement (wordCont k) e (preparedTemps le i tags) m) := by
  have carried : (mathTemps le i).get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [mathTemps,CC.PTree.gso] using hentry
  rw [address_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e _ m _ entry tags carried read)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip (.Kseq statement (wordCont k)) e (preparedTemps le i tags) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · rcases indices i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
    all_goals simp +decide [pointer,CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,mathTemps,preparedTemps,
      CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrLong,
      CC.Cop.semUnaryOperation,CC.Cop.semNotint,CC.Cop.classifyNotint,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvoid,CC.tvolatile,CC.tulong,CC.tuchar,
      CC.Archi.ptr64,CC.Archi.ptrWordsize,CC.sizeof,CC.Integers.Int64.not,CC.Integers.MI.not,
      CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
      CC.Integers.Ptrofs.repr,CC.Integers.Ptrofs.of_int64,CC.Integers.MI.add,CC.Integers.MI.mul]
    all_goals rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

theorem to_statement (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry tags : CC.Block) (i : Fin 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (BitVec.ofNat 32 i.val)))
    (read : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0)) :
    InternalRun world 13 (.State helper Arm64MemsetReleaseTagLoop.selected k e le m)
      (.State helper statement (wordCont k) e (preparedTemps le i tags) m) :=
  (math_run e le m k i counter).trans (address_run e le m k entry tags i hentry read)

private def builtinArgs (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  unless actual.isAppOfArity ``CC.Stmt.Sbuiltin 4 do throwError "original release tag builtin changed"
  Lean.Elab.Tactic.closeMainGoal `actual_release_rmw_arguments actual.getAppArgs[3]!
private def loadArgs : List CC.Expr := by run_tac builtinArgs (← `(load))
private def storeArgs : List CC.Expr := by run_tac builtinArgs (← `(store))
private theorem load_source : load = .Sbuiltin (some Arm64Program._t'3) (.EF_vload .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong)] loadArgs := rfl
private theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] storeArgs := rfl
private def rmwTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'3 (.Vlong 0)).set Arm64Program.___tv (.Vlong 0)
def temps (le : CC.TempEnv) (i : Fin 8) (tags : CC.Block) : CC.TempEnv := rmwTemps (preparedTemps le i tags)

private theorem load_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block)
    (pointer : le.get Arm64Program.___tp = some (.Vptr tags 0)) :
    CC.doEvalExprlist world e le m loadArgs [CC.tptr (CC.tvolatile CC.tulong)] = some [.Vptr tags 0] := by
  simp only [loadArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,CC.typeof,CC.Cop.semCast,
    CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tptr,CC.tvolatile,CC.tulong,CC.tattr,CC.Archi.ptr64]

private theorem store_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block) (i : Fin 8)
    (pointer : le.get Arm64Program.___tp = some (.Vptr tags 0))
    (packed : le.get Arm64Program.___ts = some (.Vint (shift i)))
    (word : le.get Arm64Program.___tv = some (.Vlong 0)) :
    CC.doEvalExprlist world e le m storeArgs [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] =
      some [.Vptr tags 0,.Vlong 0] := by
  rcases indices i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals simp only [storeArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,packed,word,shift,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semOr,CC.Cop.semShl,CC.Cop.semShift,CC.Cop.classifyShift,
    CC.Cop.semUnaryOperation,CC.Cop.semNotint,CC.Cop.classifyNotint,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tptr,CC.tvolatile,CC.tulong,CC.tuint,CC.tuchar,CC.Archi.ptr64,CC.Integers.Int.repr,
    CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.shl,CC.Integers.MI.shl,
    CC.Integers.Int64.not,CC.Integers.MI.not,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.Integers.Int64.or,CC.Integers.MI.or,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.ltu,CC.Integers.MI.ltu]
  all_goals rfl

/-- Execute this source's own volatile read, copied word and real offset0
clear store. The real store remains even when the observed word is zero. -/
theorem statement_execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (tags : CC.Block) (i : Fin 8)
    (pointer : le.get Arm64Program.___tp = some (.Vptr tags 0))
    (packed : le.get Arm64Program.___ts = some (.Vint (shift i)))
    (observed : CC.Mem.load .Mint64 m tags 0 = some (.Vlong 0))
    (range : CC.Mem.rangePerm m tags 0 24 .Cur .Writable = true) :
    ∃ after, CC.Star (CC.Step2 world) (.State helper statement k e le m) CC.E0
        (.State helper .Sskip k e (rmwTemps le) after) ∧
      CC.Mem.store .Mint64 m tags 0 (.Vlong 0) = some after ∧
      CC.Mem.load .Mint64 after tags 0 = some (.Vlong 0) ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have valid : CC.Mem.validAccess m .Mint64 tags 0 .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro pos low high
      exact CC.Mem.rangePerm_perm m tags 0 24 .Cur .Writable range pos low
        (by change pos < (0 : Int) + 8 at high; omega)
    · decide +kernel
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint64 m tags 0 (.Vlong 0) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  let readCont := CC.Cont.Kseq copy (.Kseq store k)
  have enter : InternalRun world 2 (.State helper statement k e le m) (.State helper load readCont e le m) := by
    rw [statement_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  have readStep : CC.Step2 world (.State helper load readCont e le m) CC.E0
      (.State helper .Sskip readCont e (le.set Arm64Program._t'3 (.Vlong 0)) m) := by
    rw [load_source]
    apply CC.Step.builtin (vargs := [.Vptr tags 0]) (vres := .Vlong 0)
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (load_arguments e le m tags pointer)
    · exact CC.VolatileLoadSem.intro _ _ _ _ _ _
        (.nonvol _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags) observed)
  have middle : InternalRun world 3
      (.State helper .Sskip readCont e (le.set Arm64Program._t'3 (.Vlong 0)) m)
      (.State helper store k e (rmwTemps le) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step (mid := .State helper .Sskip (.Kseq store k) e (rmwTemps le) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [copy,CC.doStep,CC.doEvalExpr,CC.PTree.gss,rmwTemps]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have writeStep : CC.Step2 world (.State helper store k e (rmwTemps le) m) CC.E0
      (.State helper .Sskip k e (rmwTemps le) after) := by
    rw [store_source]
    apply CC.Step.builtin (vargs := [.Vptr tags 0,.Vlong 0]) (vres := .Vundef)
    · apply CC.doEvalExprlist_sound
      exact store_arguments e _ m tags i
        (by simpa +decide only [rmwTemps,CC.PTree.gso] using pointer)
        (by simpa +decide only [rmwTemps,CC.PTree.gso] using packed) (by simp only [rmwTemps,CC.PTree.gss])
    · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
        (.nonvol _ _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags) stored)
  have oneRead : CC.Star (CC.Step2 world) (.State helper load readCont e le m) CC.E0
      (.State helper .Sskip readCont e (le.set Arm64Program._t'3 (.Vlong 0)) m) := .step _ _ _ _ _ _ readStep (.refl _) rfl
  have oneWrite : CC.Star (CC.Step2 world) (.State helper store k e (rmwTemps le) m) CC.E0
      (.State helper .Sskip k e (rmwTemps le) after) := .step _ _ _ _ _ _ writeStep (.refl _) rfl
  refine ⟨after,?_,stored,CC.Mem.load_store_same stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans (star_trans enter.sound oneRead) middle.sound) oneWrite

private theorem encoding : CC.encodeVal .Mint64 (.Vlong 0) = List.replicate 8 (.Byte 0) := by decide +kernel

/-- The actual zero-word store at offset0 preserves every24-byte tag
observation through imported encoding and genuine nonoverlap outside0..7. -/
theorem tag_bytes {before after : CC.Mem} {tags : CC.Block}
    (stored : CC.Mem.store .Mint64 before tags 0 (.Vlong 0) = some after)
    (prior : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before tags (j.val : Int) = some (.Vint 0)) :
    ∀ j : Fin 24, CC.Mem.load .Mint8unsigned after tags (j.val : Int) = some (.Vint 0) := by
  intro j
  by_cases above : 8 ≤ (j.val : Int)
  · exact (CC.Mem.load_store_other stored .Mint8unsigned tags (j.val : Int)
      (.inr (.inr (by change (8 : Int) ≤ (j.val : Int); exact above)))).trans (prior j)
  have readable := (Arm64MemsetTagWords.byte_zero before tags (j.val : Int) (prior j)).1
  have afterReadable : CC.Mem.validAccess after .Mint8unsigned tags (j.val : Int) .Readable = true :=
    (CC.Mem.validAccess_store_eq stored .Mint8unsigned tags (j.val : Int) .Readable).trans readable
  have bounded : j.val < 8 := by omega
  have raw := CC.Mem.setN_inside (List.replicate 8 (CC.MemVal.Byte 0)) 0
    (CC.PMap.get tags before.contents) j.val (by simpa using bounded)
  have cell : CC.ZMap.get (j.val : Int) (CC.PMap.get tags after.contents) = .Byte 0 := by
    rw [CC.Mem.store_contents stored,CC.PMap.gss,encoding]
    have item : (List.replicate 8 (CC.MemVal.Byte 0))[j.val]! = .Byte 0 := by
      rw [getElem!_pos _ _ (by simpa only [List.length_replicate] using bounded)]
      exact List.getElem_replicate _
    simpa only [Int.zero_add] using raw.trans item
  rw [CC.Mem.load,afterReadable]
  change some (CC.decodeVal .Mint8unsigned [CC.ZMap.get (j.val : Int) (CC.PMap.get tags after.contents)]) = some (.Vint 0)
  rw [cell]
  decide +kernel

private theorem exit_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.State helper .Sskip (wordCont k) e le m) (.State helper .Sskip k e le m) := by
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

theorem inputs (le : CC.TempEnv) (i : Fin 8) (tags : CC.Block) :
    (temps le i tags).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le i tags).get Arm64Program.___a64_release_w = le.get Arm64Program.___a64_release_w ∧
    (temps le i tags).get Arm64Program.___a64_release_old = le.get Arm64Program.___a64_release_old ∧
    (temps le i tags).get Arm64Program.___a64_release_new = le.get Arm64Program.___a64_release_new ∧
    (temps le i tags).get Arm64Program.___a64_release_i = le.get Arm64Program.___a64_release_i := by
  refine ⟨?_,?_,?_,?_,?_⟩ <;> simp +decide only [temps,rmwTemps,preparedTemps,mathTemps,CC.PTree.gso]

theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (BitVec.ofNat 32 i.val)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ after, CC.Star (CC.Step2 world) (.State helper Arm64MemsetReleaseTagLoop.selected k e le m) CC.E0
        (.State helper .Sskip k e (temps le i view.tags.block) after) ∧
      CC.Mem.store .Mint64 m view.tags.block 0 (.Vlong 0) = some after ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) ∧
      (∀ j : Fin 24, CC.Mem.load .Mint8unsigned after view.tags.block (j.val : Int) = some (.Vint 0)) := by
  have setup := to_statement e le m k entry.block view.tags.block i hentry counter view.tagPointer
  have pointer : (preparedTemps le i view.tags.block).get Arm64Program.___tp = some (.Vptr view.tags.block 0) := CC.PTree.gss ..
  have packed : (preparedTemps le i view.tags.block).get Arm64Program.___ts = some (.Vint (shift i)) := by
    simp +decide only [preparedTemps,mathTemps,CC.PTree.gso,CC.PTree.gss]
  have word := Arm64MemsetTagWords.original m view.tags.block tagBytes ⟨0,by decide⟩
  change CC.Mem.load .Mint64 m view.tags.block 0 = some (.Vlong 0) at word
  obtain ⟨after,bodyRun,stored,_read,access,next⟩ := statement_execute e _ m (wordCont k) view.tags.block i pointer packed word
    (Arm64MemsetStoreExecution.ranges view resources).1
  have leave := exit_loop e (temps le i view.tags.block) after k
  refine ⟨after,?_,stored,FrameBelow.store view.tags.fresh stored,access,next,?_,tag_bytes stored tagBytes⟩
  · simpa only [temps,CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans setup.sound bodyRun) leave.sound
  · intro chunk block offset other
    exact CC.Mem.load_store_other stored chunk block offset (.inl other)

section SingleStore
open Arm64Producer Arm64ProducerRegisterStorage
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial before entry)
    (stored : CC.Mem.store .Mint64 before view.tags.block 0 (.Vlong 0) = some after)
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

theorem resources_after (old : Arm64ProgramEntryResources.Resources initial before entry) :
    Arm64ProgramEntryResources.Resources initial after entry :=
  Arm64MemsetIterationResources.resources old
    (fun chunk offset => other view stored _ _ _ entry.binding (by decide +kernel) chunk offset)
    (fun block _ => congrArg (CC.PMap.get block) (CC.Mem.store_access stored))

def view_after : Arm64MemsetHeaderView.View initial after entry where
  stack := view.stack
  tags := view.tags
  stackPointer := (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 608).trans view.stackPointer
  tagPointer := (other view stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 648).trans view.tagPointer
  capacity := (other view stored _ _ _ entry.binding (by decide +kernel) .Mint32 656).trans view.capacity
  bias := (other view stored _ _ _ entry.binding (by decide +kernel) .Mint64 672).trans view.bias

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

end KProgFormal.ClightRefinement.Arm64MemsetReleaseTagStore
