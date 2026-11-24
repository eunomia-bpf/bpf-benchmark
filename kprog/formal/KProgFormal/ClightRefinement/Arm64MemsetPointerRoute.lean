import KProgFormal.ClightRefinement.Arm64MemsetStackRoute

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetPointerRoute

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  guard : CC.Stmt
  path : CC.Stmt
  loop : CC.Stmt
  body : CC.Stmt
  regSet : CC.Stmt
  tail : CC.Stmt
  choice : CC.Stmt
  small : CC.Stmt
  ordinary : CC.Stmt
  cast : CC.Stmt
  setPointer : CC.Stmt
  copyBase : CC.Stmt
  loss : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memset R0 pointer route changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetStackRoute.afterSp)) none) ``CC.Stmt.Ssequence 2
    let guard ← peel root[0]! ``CC.Stmt.Sifthenelse 3
    let path ← peel guard[1]! ``CC.Stmt.Ssequence 2
    let loop ← peel path[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel body[1]! ``CC.Stmt.Ssequence 2
    let choice ← peel tail[0]! ``CC.Stmt.Sifthenelse 3
    let small ← peel choice[2]! ``CC.Stmt.Sifthenelse 3
    let ordinary ← peel small[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_route
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,guard[1]!,path[0]!,loop[0]!,body[0]!,body[1]!,tail[0]!,choice[2]!,small[1]!,ordinary[1]!,tail[1]!,path[1]!,root[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_route_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def path : CC.Stmt := by run_tac cachePart (← `(parts.path))
private def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def regSet : CC.Stmt := by run_tac cachePart (← `(parts.regSet))
private def tail : CC.Stmt := by run_tac cachePart (← `(parts.tail))
private def choice : CC.Stmt := by run_tac cachePart (← `(parts.choice))
private def small : CC.Stmt := by run_tac cachePart (← `(parts.small))
private def ordinary : CC.Stmt := by run_tac cachePart (← `(parts.ordinary))
private def cast : CC.Stmt := by run_tac cachePart (← `(parts.cast))
private def setPointer : CC.Stmt := by run_tac cachePart (← `(parts.setPointer))
private def copyBase : CC.Stmt := by run_tac cachePart (← `(parts.copyBase))
def loss : CC.Stmt := by run_tac cachePart (← `(parts.loss))

private theorem source : Arm64MemsetStackRoute.afterSp = .Ssequence guard loss := rfl
private theorem path_source : path = .Ssequence loop copyBase := rfl
private theorem loop_source : loop = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence regSet tail := rfl
private theorem tail_source : tail = .Ssequence choice setPointer := rfl
private theorem ordinary_source : ordinary = .Ssequence Arm64Program.s_kprog_arm64_program_memset_26 cast := rfl

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq cast (.Kseq setPointer (.Kloop1 body .Sbreak (.Kseq copyBase (.Kseq loss k))))

def regTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program.___a64_l_reg__5 (.Vlong 0)

/-- The actual bsrc guard, pointer loop and both register selectors choose
R0's real four-load union-member path, retaining its full continuation. -/
theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hbsrc : le.get Arm64Program.___a64_mwr_bsrc = some (.Vint 1)) :
    InternalRun world 11 (.State handler Arm64MemsetStackRoute.afterSp k e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_26 (continuation k) e (regTemps le) m) := by
  apply internalRun_of_steps
  · simp +decide [InternalPath,InternalState,steps,source,path_source,loop_source,body_source,tail_source,ordinary_source,guard,choice,small,regSet,
      CC.doStep,CC.doEvalExpr,hbsrc,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.classifyCmp,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.Cop.classifyBool,CC.Cop.boolVal,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tattr,CC.Archi.ptr64,
      CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
      CC.Integers.Int64.cmpu,CC.Integers.Int64.cmp,CC.Integers.Int.repr,CC.Integers.Int64.repr,
      CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.Int.signed,CC.Integers.MI.signed]
  · simp +decide [steps,regTemps,continuation,CC.E0,CC.Eapp,source,path_source,loop_source,body_source,tail_source,ordinary_source,guard,choice,small,regSet,
      CC.doStep,CC.doEvalExpr,hbsrc,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.classifyCmp,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.Cop.classifyBool,CC.Cop.boolVal,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tattr,CC.Archi.ptr64,
      CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
      CC.Integers.Int64.cmpu,CC.Integers.Int64.cmp,CC.Integers.Int.repr,CC.Integers.Int64.repr,
      CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.Int.signed,CC.Integers.MI.signed]
    exact ⟨rfl,rfl,rfl⟩

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private def unionComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._arm64_sim_gpr).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._cells entryComposite.co_members = .OK (0,.Full) := by
  constructor <;> decide +kernel
private theorem union_layout :
    world.genv_cenv.get Arm64Program._arm64_sim_gpr = some unionComposite ∧
    CC.unionFieldOffset world.genv_cenv Arm64Program._ptr unionComposite.co_members = .OK (0,.Full) := by
  constructor <;> decide +kernel

private def root : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memset_26)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_root actual.getAppArgs[0]!
private def rootRest : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memset_26)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_root_rest actual.getAppArgs[1]!
private def slot : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(rootRest)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_slot actual.getAppArgs[0]!
private def slotRest : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(rootRest)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_slot_rest actual.getAppArgs[1]!
private def word : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(slotRest)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_word actual.getAppArgs[0]!
private def copied : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(slotRest)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_memset_pointer_copied actual.getAppArgs[1]!
private theorem read_source : Arm64Program.s_kprog_arm64_program_memset_26 = .Ssequence root rootRest := rfl
private theorem root_rest_source : rootRest = .Ssequence slot slotRest := rfl
private theorem slot_rest_source : slotRest = .Ssequence word copied := rfl

private theorem root_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry table : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 0 = some (.Vptr table 0)) :
    CC.doStep world (.State handler root k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'152 (.Vptr table 0)) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 0).toNat) : Nat) : Int) = 0 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 0 = some (.Vptr table 0) from read]

private theorem slot_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (table cell : CC.Block)
    (hroot : le.get Arm64Program._t'152 = some (.Vptr table 0))
    (hreg : le.get Arm64Program.___a64_l_reg__5 = some (.Vlong 0))
    (read : CC.Mem.load CC.Mptr m table 0 = some (.Vptr cell 0)) :
    CC.doStep world (.State handler slot k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'153 (.Vptr cell 0)) m) := by
  simp only [slot,CC.doStep,CC.doEvalExpr,hroot,hreg,CC.doEvalLvalue,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,CC.Cop.ptrofsOfInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tptr,CC.tuchar,CC.tulong,CC.tint,CC.Archi.ptr64,CC.sizeof,CC.alignof,
    CC.Integers.Int.repr,CC.Integers.Int64.unsigned,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
    CC.Integers.MI.repr,CC.Integers.MI.unsigned,CC.Integers.Int.signed,CC.Integers.MI.signed,
    CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,CC.Integers.MI.add,CC.Integers.MI.mul,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,ite_true,ite_false]
  change (match CC.Mem.load .Mint64 m table 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e (le.set Arm64Program._t'153 value) m)
    | none => none) = _
  rw [show CC.Mem.load .Mint64 m table 0 = some (.Vptr cell 0) from read]

private theorem word_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (cell : CC.Block) (raw : BitVec 64)
    (hcell : le.get Arm64Program._t'153 = some (.Vptr cell 0))
    (read : CC.Mem.load .Mint64 m cell 0 = some (.Vlong raw)) :
    CC.doStep world (.State handler word k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'154 (.Vlong raw)) m) := by
  simp only [word,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hcell,CC.lvalOfField,union_layout.1,union_layout.2,
    CC.typeof,CC.tptr,CC.tvoid,CC.tattr,CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,
    CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  change (match CC.Mem.load .Mint64 m cell 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e (le.set Arm64Program._t'154 value) m)
    | none => none) = _
  rw [read]

/-- The actual current R0 readback yields its original union-word load. -/
theorem word_read {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint (tag.setWidth 32))) :
    CC.Mem.load .Mint64 m ((storage.tables false).cellBlock 0) 0 = some (.Vlong raw) := by
  have walk := Arm64RegisterWrite.storage_gpr storage (0 : Fin 31)
  simp only [Fin.val_zero] at walk
  rw [walk] at observed
  cases wordRead : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock 0) 0 with
  | none =>
    simp only [wordRead,bind,Option.bind_none] at observed
    cases observed
  | some word =>
    cases tagRead : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock 0) 0 with
    | none =>
      simp only [wordRead,tagRead,bind,Option.bind_some,Option.bind_none] at observed
      cases observed
    | some value =>
      have equal : (word,value) = (.Vlong raw,.Vint (tag.setWidth 32)) := by
        simpa only [wordRead,tagRead,bind,Option.bind_some,pure,Option.some.injEq] using observed
      exact congrArg some (congrArg Prod.fst equal)

def readTemps (le : CC.TempEnv) (table cell : CC.Block) (raw : BitVec 64) : CC.TempEnv :=
  (((le.set Arm64Program._t'152 (.Vptr table 0)).set Arm64Program._t'153 (.Vptr cell 0)).set
    Arm64Program._t'154 (.Vlong raw)).set Arm64Program._t'26 (.Vlong raw)

/-- Execute the original root, slot, union pointer-member and redundant cast
assignments. Every actual load is derived from the same Storage/R0 outcome. -/
theorem read {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (raw : BitVec 64) (tag : BitVec 8)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hreg : le.get Arm64Program.___a64_l_reg__5 = some (.Vlong 0))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint (tag.setWidth 32))) :
    InternalRun world 10 (.State handler Arm64Program.s_kprog_arm64_program_memset_26 k e le m)
      (.State handler .Sskip k e (readTemps le (storage.tables false).tableBlock ((storage.tables false).cellBlock 0) raw) m) := by
  let l1 := le.set Arm64Program._t'152 (.Vptr (storage.tables false).tableBlock 0)
  let l2 := l1.set Arm64Program._t'153 (.Vptr ((storage.tables false).cellBlock 0) 0)
  let l3 := l2.set Arm64Program._t'154 (.Vlong raw)
  have reg : l1.get Arm64Program.___a64_l_reg__5 = some (.Vlong 0) := by
    simpa +decide only [l1,CC.PTree.gso] using hreg
  rw [read_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (root_step e le m _ entry.block _ hentry (storage.roots false))) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [root_rest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (slot_step e l1 m _ (storage.tables false).tableBlock ((storage.tables false).cellBlock 0) (by simp only [l1,CC.PTree.gss]) reg
    (by simpa using storage.slots false (0 : Fin 31)))) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [slot_rest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (word_step e l2 m _ _ raw (by simp only [l2,CC.PTree.gss])
    (word_read storage raw tag observed))) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [copied,CC.doStep,CC.doEvalExpr,l3,CC.PTree.gss,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tptr,CC.tvoid,CC.tattr,CC.Archi.ptr64]
  rfl

def temps (le : CC.TempEnv) (raw : BitVec 64) : CC.TempEnv :=
  ((le.set Arm64Program._t'26 (.Vlong raw)).set Arm64Program.___a64_mwr_pointer (.Vlong raw)).set
    Arm64Program.___a64_mwr_base (.Vlong raw)

/-- Keep the actual redundant pointer cast, pointer assignment, loop exit
and pointer-to-long casts into the real loss loop, at every64-bit payload. -/
theorem finish (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (raw : BitVec 64)
    (hptr : le.get Arm64Program._t'26 = some (.Vlong raw)) :
    InternalRun world 9 (.State handler .Sskip (continuation k) e le m)
      (.State handler loss k e (temps le raw) m) := by
  apply internalRun_of_steps
  · simp +decide [InternalPath,InternalState,steps,continuation,cast,setPointer,copyBase,CC.doStep,CC.doEvalExpr,
      hptr,CC.PTree.gss,CC.PTree.gso,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,
      CC.tptr,CC.tvoid,CC.tlong,CC.tattr,CC.Archi.ptr64]
  · simp +decide [steps,continuation,cast,setPointer,copyBase,CC.doStep,CC.doEvalExpr,
      hptr,CC.PTree.gss,CC.PTree.gso,temps,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,
      CC.tptr,CC.tvoid,CC.tlong,CC.tattr,CC.Archi.ptr64,CC.E0,CC.Eapp,List.nil_append]

/-- The actual R0 pointer route reads and carries the SAME represented raw
bits into the loss loop; genuine guards, casts and saved continuations remain. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (raw : BitVec 64) (tag : BitVec 8)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hbsrc : le.get Arm64Program.___a64_mwr_bsrc = some (.Vint 1))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint (tag.setWidth 32))) :
    InternalRun world 30 (.State handler Arm64MemsetStackRoute.afterSp k e le m)
      (.State handler loss k e
        (temps (readTemps (regTemps le) (storage.tables false).tableBlock ((storage.tables false).cellBlock 0) raw) raw) m) := by
  have carried : (regTemps le).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simpa +decide only [regTemps,CC.PTree.gso] using hentry
  have actual := read storage raw tag e (regTemps le) (continuation k) carried
    (by simp only [regTemps,CC.PTree.gss]) observed
  exact ((enter e le m k hbsrc).trans actual).trans
    (finish e _ m k raw (by simp only [readTemps,CC.PTree.gss]))

private theorem initial_inputs (entry table cell abi : CC.Block) (mark : BitVec 32) :
    (Arm64MemsetStackRoute.inputTemps entry table cell abi mark).get Arm64Program._entry = some (.Vptr entry 0) ∧
    (Arm64MemsetStackRoute.inputTemps entry table cell abi mark).get Arm64Program.___a64_mwr_arm = some (.Vint 0) := by
  change (((Arm64MemsetAbiOriginal.beforeTemps entry table cell mark).set
    Arm64Program._t'172 (.Vptr abi 0)).set Arm64Program._t'173 (.Vint 2) |>.set
    Arm64Program._t'67 (.Vint 0)).get Arm64Program._entry = _ ∧
    (((Arm64MemsetAbiOriginal.beforeTemps entry table cell mark).set
      Arm64Program._t'172 (.Vptr abi 0)).set Arm64Program._t'173 (.Vint 2) |>.set
      Arm64Program._t'67 (.Vint 0)).get Arm64Program.___a64_mwr_arm = _
  constructor
  · simp +decide only [CC.PTree.gso,Arm64MemsetAbiOriginal.beforeTemps,Arm64MemsetArmSelect.temps,
      Arm64MemsetTagRead.finalTemps,Arm64MemsetTagRead.temps]
    rw [(Arm64MemsetStackSetup.selection _ 0).1]
    simp +decide only [Arm64MemsetLoop.initializedTemps,Arm64MemsetSource.readTemps,
      Arm64MemsetSource.byteTemps,Arm64MemsetSource.initialTemps,CC.PTree.gso,CC.PTree.gss]
  · simp +decide only [CC.PTree.gso,Arm64MemsetAbiOriginal.beforeTemps,Arm64MemsetArmSelect.temps,CC.PTree.gss]

def inputTemps (entry table cell abi sp : CC.Block) (spValue : BitVec 64) (mark : BitVec 32) : CC.TempEnv :=
  Arm64MemsetStackRoute.temps (Arm64MemsetStackRoute.inputTemps entry table cell abi mark) sp spValue

private theorem original_inputs (entry table cell abi sp : CC.Block) (spValue : BitVec 64) (mark : BitVec 32) :
    (inputTemps entry table cell abi sp spValue mark).get Arm64Program._entry = some (.Vptr entry 0) ∧
    (inputTemps entry table cell abi sp spValue mark).get Arm64Program.___a64_mwr_bsrc = some (.Vint 1) := by
  constructor
  · simpa +decide only [inputTemps,Arm64MemsetStackRoute.temps,Arm64MemsetStackRoute.selectedTemps,CC.PTree.gso]
      using (initial_inputs entry table cell abi mark).1
  · simp +decide only [inputTemps,Arm64MemsetStackRoute.temps,Arm64MemsetStackRoute.selectedTemps,CC.PTree.gso,CC.PTree.gss]

/-- The same original memset call reads its actual R0 pointer path and
reaches the original loss loop in342 transitions with the original64-bit raw bits. -/
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
      addresses origins next nextK constantWritten constantAfter)
    (abi : Arm64Producer.TailLocal initial 6)
    (header : CC.Mem.load CC.Mptr constantAfter entry.block 704 = some (.Vptr abi.block 0))
    (value : CC.Mem.load .Mint8unsigned constantAfter abi.block 0 = some (.Vint 2))
    (tags : ∀ (tagsLocal : Arm64Producer.StackTagLocal initial) (i : Fin 24),
      CC.Mem.load .Mint8unsigned constantAfter tagsLocal.block (i.val : Int) = some (.Vint 0))
    (k : CC.Cont) :
    ∃ current : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry,
      InternalRun world 342 (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter)
        (.State handler loss
          (Arm64MemsetTagRead.continuation
            (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
          (Arm64MemsetSource.allocation constantAfter).1
          (temps (readTemps (regTemps (inputTemps entry.block (current.tables true).tableBlock
            ((current.tables true).cellBlock 0) abi.block current.sp.block current.spValue mark))
            (current.tables false).tableBlock ((current.tables false).cellBlock 0) raw) raw)
          (Arm64MemsetSource.allocation constantAfter).2) ∧
      Arm64EntryMemory.gpr (Arm64MemsetSource.allocation constantAfter).2.nextblock
        (Arm64MemsetSource.allocation constantAfter).2 (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint ((4#8).setWidth 32)) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 40 = some (.Vptr storage.sp.block 0) ∧
      CC.Mem.load .Mint64 (Arm64MemsetSource.allocation constantAfter).2 storage.sp.block 0 = some (.Vlong storage.spValue) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0) ∧
      CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2) ∧
      ∀ (tagsLocal : Arm64Producer.StackTagLocal initial) (i : Fin 24),
        CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 tagsLocal.block (i.val : Int) = some (.Vint 0) := by
  obtain ⟨current,run,r0,spPointer,spValue,abiPointer,abiValue,tagValues⟩ :=
    Arm64MemsetStackRoute.original mark pointer bound first second abi header value tags k
  have inputs := original_inputs entry.block (current.tables true).tableBlock ((current.tables true).cellBlock 0)
    abi.block current.sp.block current.spValue mark
  have route := execute current raw (4#8) (Arm64MemsetSource.allocation constantAfter).1
    (inputTemps entry.block (current.tables true).tableBlock ((current.tables true).cellBlock 0)
      abi.block current.sp.block current.spValue mark)
    (Arm64MemsetTagRead.continuation
      (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k)))) inputs.1 inputs.2 r0
  exact ⟨current,run.trans route,r0,spPointer,spValue,abiPointer,abiValue,tagValues⟩

end KProgFormal.ClightRefinement.Arm64MemsetPointerRoute
