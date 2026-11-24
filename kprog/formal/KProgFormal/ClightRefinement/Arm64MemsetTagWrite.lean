import KProgFormal.ClightRefinement.Arm64MemsetByteWrite

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagWrite

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  loop : CC.Stmt
  body : CC.Stmt
  statement : CC.Stmt
  load : CC.Stmt
  copy : CC.Stmt
  store : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do
        throwError "original memset tag read-modify-write changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memset_77)) none) ``CC.Stmt.Ssequence
    let loop ← peel root[0]! ``CC.Stmt.Sloop
    let index ← peel loop[0]! ``CC.Stmt.Ssequence
    let shift ← peel index[1]! ``CC.Stmt.Ssequence
    let pointer ← peel shift[1]! ``CC.Stmt.Ssequence
    let tail ← peel pointer[1]! ``CC.Stmt.Ssequence
    let read ← peel tail[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_rmw
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,loop[0]!,pointer[1]!,read[0]!,read[1]!,tail[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
def statement : CC.Stmt := by run_tac cachePart (← `(parts.statement))
private def load : CC.Stmt := by run_tac cachePart (← `(parts.load))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
private def store : CC.Stmt := by run_tac cachePart (← `(parts.store))

private def builtinArgs (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  unless actual.isAppOfArity ``CC.Stmt.Sbuiltin 4 do
    throwError "original memset tag builtin changed"
  Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_arguments actual.getAppArgs[3]!

private def loadArgs : List CC.Expr := by run_tac builtinArgs (← `(load))
private def storeArgs : List CC.Expr := by run_tac builtinArgs (← `(store))

theorem source : statement = .Ssequence (.Ssequence load copy) store := rfl
theorem loop_source : loop = .Sloop body .Sbreak := rfl
private theorem load_source : load = .Sbuiltin (some Arm64Program._t'35) (.EF_vload .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong)] loadArgs := rfl
private theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] storeArgs := rfl

/-- Packing positions of the original twenty stack-tag bytes in three
aligned words. These are C-storage offsets and shifts. -/
def offset (tag : Fin 20) : Int := 8 * (tag.val / 8 : Nat)
def shift (tag : Fin 20) : BitVec 32 := BitVec.ofNat 32 (8 * (tag.val % 8))
def cleared (tag : Fin 20) (word : BitVec 64) : BitVec 64 :=
  word &&& ~~~((255#64) <<< (8 * (tag.val % 8)))

private theorem offset_unsigned : ∀ tag : Fin 20,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset tag)) = offset tag := by decide +kernel
private theorem offset_bounds : ∀ tag : Fin 20,
    0 ≤ offset tag ∧ offset tag + 8 ≤ 24 ∧ offset tag % 8 = 0 := by decide +kernel
private theorem shift_data : ∀ tag : Fin 20,
    CC.Integers.Int.ltu (shift tag) (CC.Integers.Int.repr 64) = true ∧
    (CC.Integers.Int64.repr (CC.Integers.Int.unsigned (shift tag))).toNat = 8 * (tag.val % 8) := by decide +kernel

def temps (le : CC.TempEnv) (word : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Program._t'35 (.Vlong word)).set Arm64Program.___tv__1 (.Vlong word)

private theorem load_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block) (tag : Fin 20)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags (CC.Integers.Ptrofs.repr (offset tag)))) :
    CC.doEvalExprlist world e le m loadArgs [CC.tptr (CC.tvolatile CC.tulong)] =
      some [.Vptr tags (CC.Integers.Ptrofs.repr (offset tag))] := by
  simp only [loadArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.tptr,CC.tvolatile,CC.tulong,CC.Archi.ptr64,ite_true]

private theorem left_shift (value : BitVec 64) (tag : Fin 20) :
    CC.Cop.semShl (.Vlong value) (.Tlong .Unsigned CC.noattr)
      (.Vint (shift tag)) (.Tint .I32 .Unsigned CC.noattr) =
      some (.Vlong (value <<< (8 * (tag.val % 8)))) := by
  change (if CC.Integers.Int.ltu (shift tag) (CC.Integers.Int.repr 64) then
    some (CC.Val.Vlong (value <<< (CC.Integers.Int64.repr (CC.Integers.Int.unsigned (shift tag))).toNat))
    else none) = _
  rw [(shift_data tag).1,(shift_data tag).2]
  rfl

private theorem scalar_zero : BitVec.ofNat 64
    (BitVec.ofInt 32 0 &&& (BitVec.allOnes 32 >>> (32 - 8))).toNat = (0#64) := by decide +kernel

private theorem store_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (tags : CC.Block) (tag : Fin 20) (word : BitVec 64)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags (CC.Integers.Ptrofs.repr (offset tag))))
    (bits : le.get Arm64Program.___ts__1 = some (.Vint (shift tag)))
    (value : le.get Arm64Program.___tv__1 = some (.Vlong word)) :
    CC.doEvalExprlist world e le m storeArgs
      [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] =
      some [.Vptr tags (CC.Integers.Ptrofs.repr (offset tag)),.Vlong (cleared tag word)] := by
  simp +decide only [storeArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,bits,value,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semOr,CC.Cop.semUnaryOperation,CC.Cop.semNotint,
    left_shift,CC.Cop.classifyNotint,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tvolatile,CC.tulong,CC.tuint,CC.tuchar,
    CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int64.shl,CC.Integers.MI.shl,CC.Integers.Int64.not,CC.Integers.MI.not,
    CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.or,CC.Integers.MI.or,
    CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
    ite_true,ite_false,BitVec.toNat_zero,BitVec.ofInt_natCast,scalar_zero,BitVec.zero_shiftLeft,BitVec.or_zero,cleared]
  rfl

/-- Read the actual tag word through the original volatile load builtin. -/
theorem read_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (tags : CC.Block) (tag : Fin 20) (word : BitVec 64)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags (CC.Integers.Ptrofs.repr (offset tag))))
    (observed : CC.Mem.load .Mint64 m tags (offset tag) = some (.Vlong word)) :
    CC.Step2 world (.State handler load k e le m) CC.E0
      (.State handler .Sskip k e (le.set Arm64Program._t'35 (.Vlong word)) m) := by
  rw [load_source]
  apply CC.Step.builtin (vargs := [.Vptr tags (CC.Integers.Ptrofs.repr (offset tag))]) (vres := .Vlong word)
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (load_arguments e le m tags tag pointer)
  · exact CC.VolatileLoadSem.intro _ _ _ _ _ _
      (.nonvol _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags) (by simpa only [offset_unsigned tag] using observed))

/-- Store the exact byte-clear expression from the original C body. -/
theorem store_step (e : CC.Env) (le : CC.TempEnv) (m after : CC.Mem) (k : CC.Cont)
    (tags : CC.Block) (tag : Fin 20) (word : BitVec 64)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags (CC.Integers.Ptrofs.repr (offset tag))))
    (bits : le.get Arm64Program.___ts__1 = some (.Vint (shift tag)))
    (value : le.get Arm64Program.___tv__1 = some (.Vlong word))
    (stored : CC.Mem.store .Mint64 m tags (offset tag) (.Vlong (cleared tag word)) = some after) :
    CC.Step2 world (.State handler store k e le m) CC.E0 (.State handler .Sskip k e le after) := by
  rw [store_source]
  apply CC.Step.builtin (vargs := [.Vptr tags (CC.Integers.Ptrofs.repr (offset tag)),.Vlong (cleared tag word)])
    (vres := .Vundef)
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (store_arguments e le m tags tag word pointer bits value)
  · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
      (.nonvol _ _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags) (by simpa only [offset_unsigned tag] using stored))

/-- Execute both real volatile builtins, their copy and original sequencing.
The same tag allocation derives store success and exact word readback. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (tags : CC.Block) (tag : Fin 20) (word : BitVec 64)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags (CC.Integers.Ptrofs.repr (offset tag))))
    (bits : le.get Arm64Program.___ts__1 = some (.Vint (shift tag)))
    (observed : CC.Mem.load .Mint64 m tags (offset tag) = some (.Vlong word))
    (range : CC.Mem.rangePerm m tags 0 24 .Cur .Writable = true) :
    ∃ after,
      CC.Star (CC.Step2 world) (.State handler statement k e le m) CC.E0
        (.State handler .Sskip k e (temps le word) after) ∧
      CC.Mem.store .Mint64 m tags (offset tag) (.Vlong (cleared tag word)) = some after ∧
      CC.Mem.load .Mint64 after tags (offset tag) = some (.Vlong (cleared tag word)) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock := by
  have bounds := offset_bounds tag
  have valid : CC.Mem.validAccess m .Mint64 tags (offset tag) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro pos low high
      exact CC.Mem.rangePerm_perm m tags 0 24 .Cur .Writable range pos
        (by omega) (by change pos < offset tag + 8 at high; omega)
    · simpa only [CC.alignChunk,bounds.2.2] using (show ((0 : Int) == 0) = true from rfl)
  obtain ⟨after,stored⟩ : ∃ after,
      CC.Mem.store .Mint64 m tags (offset tag) (.Vlong (cleared tag word)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  let readCont := CC.Cont.Kseq copy (.Kseq store k)
  have enter : InternalRun world 2 (.State handler statement k e le m)
      (.State handler load readCont e le m) := by
    rw [source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have read := read_step e le m readCont tags tag word pointer observed
  have middle : InternalRun world 3
      (.State handler .Sskip readCont e (le.set Arm64Program._t'35 (.Vlong word)) m)
      (.State handler store k e (temps le word) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step (mid := .State handler .Sskip (.Kseq store k) e (temps le word) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [copy,CC.doStep,CC.doEvalExpr,CC.PTree.gss,temps]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have last := store_step e (temps le word) m after k tags tag word
    (by simpa +decide only [temps,CC.PTree.gso] using pointer)
    (by simpa +decide only [temps,CC.PTree.gso] using bits)
    (by simp only [temps,CC.PTree.gss]) stored
  have oneRead : CC.Star (CC.Step2 world) (.State handler load readCont e le m) CC.E0
      (.State handler .Sskip readCont e (le.set Arm64Program._t'35 (.Vlong word)) m) :=
    .step _ _ _ _ _ _ read (.refl _) rfl
  have oneWrite : CC.Star (CC.Step2 world) (.State handler store k e (temps le word) m) CC.E0
      (.State handler .Sskip k e (temps le word) after) := .step _ _ _ _ _ _ last (.refl _) rfl
  refine ⟨after,?_,stored,?_,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  · simpa only [CC.Eapp,CC.E0,List.nil_append] using
      star_trans (star_trans (star_trans enter.sound oneRead) middle.sound) oneWrite
  · exact CC.Mem.load_store_same stored

/-- The same actual24-byte producer tag local supplies writable permission
and the caller frame for every aligned word touched by the twenty tag bytes. -/
theorem execute_local {initial : CC.Mem} (tags : Arm64Producer.StackTagLocal initial)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (tag : Fin 20) (word : BitVec 64)
    (access : CC.PMap.get tags.block m.access = CC.PMap.get tags.block (Arm64Producer.allocation initial).2.access)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags.block (CC.Integers.Ptrofs.repr (offset tag))))
    (bits : le.get Arm64Program.___ts__1 = some (.Vint (shift tag)))
    (observed : CC.Mem.load .Mint64 m tags.block (offset tag) = some (.Vlong word)) :
    ∃ after,
      CC.Star (CC.Step2 world) (.State handler statement k e le m) CC.E0
        (.State handler .Sskip k e (temps le word) after) ∧
      CC.Mem.store .Mint64 m tags.block (offset tag) (.Vlong (cleared tag word)) = some after ∧
      CC.Mem.load .Mint64 after tags.block (offset tag) = some (.Vlong (cleared tag word)) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have range : CC.Mem.rangePerm m tags.block 0 24 .Cur .Writable = true :=
    (CC.Mem.rangePerm_congr (m1 := m) (m2 := (Arm64Producer.allocation initial).2)
      (fun pos => by simp only [CC.Mem.perm,access])).trans tags.range
  obtain ⟨after,run,stored,read,permissions,next⟩ := execute e le m k tags.block tag word pointer bits observed range
  exact ⟨after,run,stored,read,FrameBelow.store tags.fresh stored,permissions,next⟩

end KProgFormal.ClightRefinement.Arm64MemsetTagWrite
