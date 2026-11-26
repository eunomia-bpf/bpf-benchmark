import KProgFormal.ClightRefinement.Arm64MemcpyTagSetup
import KProgFormal.ClightRefinement.Arm64MemsetTagByteTransport

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTagWrite

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  load : CC.Stmt
  copy : CC.Stmt
  store : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memcpy tag builtins changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTagSetup.statement)) none)
    let read ← peel root[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_tag_builtins
      (← Lean.Meta.mkAppM ``Parts.mk #[read[0]!,read[1]!,root[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_tag_builtin_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def load : CC.Stmt := by run_tac cachePart (← `(parts.load))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
private def store : CC.Stmt := by run_tac cachePart (← `(parts.store))
private def builtinArgs (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  unless actual.isAppOfArity ``CC.Stmt.Sbuiltin 4 do throwError "original memcpy tag builtin arguments changed"
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_tag_builtin_arguments actual.getAppArgs[3]!
private def loadArgs : List CC.Expr := by run_tac builtinArgs (← `(load))
private def storeArgs : List CC.Expr := by run_tac builtinArgs (← `(store))
theorem source : Arm64MemcpyTagSetup.statement = .Ssequence (.Ssequence load copy) store := rfl
private theorem load_source : load = .Sbuiltin (some Arm64Program._t'38) (.EF_vload .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong)] loadArgs := rfl
private theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint64)
    [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] storeArgs := rfl

private def shift (i : Fin 16) : BitVec 32 := Arm64MemsetTagWrite.shift (Arm64MemcpyTagSetup.tag i)
private theorem shift_data : ∀ i : Fin 16,
    CC.Integers.Int.ltu (shift i) (CC.Integers.Int.repr 64) = true ∧
    (CC.Integers.Int64.repr (CC.Integers.Int.unsigned (shift i))).toNat =
      8*((Arm64MemcpyTagSetup.tag i).val % 8) := by decide +kernel
private theorem left_shift (value : BitVec 64) (i : Fin 16) :
    CC.Cop.semShl (.Vlong value) (.Tlong .Unsigned CC.noattr)
      (.Vint (shift i)) (.Tint .I32 .Unsigned CC.noattr) =
      some (.Vlong (value <<< (8*((Arm64MemcpyTagSetup.tag i).val % 8)))) := by
  change (if CC.Integers.Int.ltu (shift i) (CC.Integers.Int.repr 64) then
    some (CC.Val.Vlong (value <<< (CC.Integers.Int64.repr (CC.Integers.Int.unsigned (shift i))).toNat)) else none) = _
  rw [(shift_data i).1,(shift_data i).2]
  rfl
private theorem scalar_zero : BitVec.ofNat 64
    (BitVec.ofInt 32 0 &&& (BitVec.allOnes 32 >>> (32-8))).toNat = (0#64) := by decide +kernel

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'38 (.Vlong 0)).set Arm64Program.___tv__1 (.Vlong 0)

private theorem load_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags (8#64))) :
    CC.doEvalExprlist world e le m loadArgs [CC.tptr (CC.tvolatile CC.tulong)] = some [.Vptr tags (8#64)] := by
  simp only [loadArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.tptr,CC.tvolatile,CC.tulong,CC.Archi.ptr64,ite_true]

private theorem store_arguments (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (tags : CC.Block) (i : Fin 16)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags (8#64)))
    (bits : le.get Arm64Program.___ts__1 = some (.Vint (shift i)))
    (zero : le.get Arm64Program.___tv__1 = some (.Vlong 0)) :
    CC.doEvalExprlist world e le m storeArgs [CC.tptr (CC.tvolatile CC.tulong),CC.tvolatile CC.tulong] =
      some [.Vptr tags (8#64),.Vlong 0] := by
  simp +decide only [storeArgs,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,pointer,bits,zero,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semOr,CC.Cop.semUnaryOperation,CC.Cop.semNotint,
    left_shift,CC.Cop.classifyNotint,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tptr,CC.tvolatile,CC.tulong,CC.tuint,CC.tuchar,CC.Archi.ptr64,
    CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.shl,
    CC.Integers.MI.shl,CC.Integers.Int64.not,CC.Integers.MI.not,CC.Integers.Int64.and,
    CC.Integers.MI.and,CC.Integers.Int64.or,CC.Integers.MI.or,CC.Integers.Int.unsigned,
    CC.Integers.MI.unsigned,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,ite_true,ite_false,
    BitVec.toNat_zero,BitVec.ofInt_natCast,scalar_zero,BitVec.zero_shiftLeft,BitVec.or_zero,BitVec.zero_and]
  change some [CC.Val.Vptr tags (8#64),CC.Val.Vlong ((0#64) &&& ~~~((BitVec.ofInt 64 255) <<<
    (8*((Arm64MemcpyTagSetup.tag i).val % 8))))] = some [CC.Val.Vptr tags (8#64),CC.Val.Vlong 0]
  rw [BitVec.zero_and]
  rfl

/-- The real tag allocation and its twenty-four byte observations derive
both actual volatile builtins and their genuine zero-word effect. -/
theorem execute {initial : CC.Mem} (tags : Arm64Producer.StackTagLocal initial)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (range : CC.Mem.rangePerm m tags.block 0 24 .Cur .Writable = true)
    (pointer : le.get Arm64Program.___tp__1 = some (.Vptr tags.block (8#64)))
    (bits : le.get Arm64Program.___ts__1 = some (.Vint (shift i)))
    (zero : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ after, CC.Star (CC.Step2 world) (.State handler Arm64MemcpyTagSetup.statement k e le m) CC.E0
      (.State handler .Sskip k e (temps le) after) ∧
      CC.Mem.store .Mint64 m tags.block 8 (.Vlong 0) = some after ∧
      (∀ j : Fin 24, CC.Mem.load .Mint8unsigned after tags.block (j.val : Int) = some (.Vint 0)) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have observed : CC.Mem.load .Mint64 m tags.block 8 = some (.Vlong 0) :=
    Arm64MemsetTagWords.original m tags.block zero ⟨1,by decide⟩
  have valid : CC.Mem.validAccess m .Mint64 tags.block 8 .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro pos low high
      exact CC.Mem.rangePerm_perm m tags.block 0 24 .Cur .Writable range pos (by omega)
        (by change pos < 8+8 at high; omega)
    · decide +kernel
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint64 m tags.block 8 (.Vlong 0) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  let readCont := CC.Cont.Kseq copy (.Kseq store k)
  have enter : InternalRun world 2 (.State handler Arm64MemcpyTagSetup.statement k e le m)
      (.State handler load readCont e le m) := by
    rw [source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  have read : CC.Step2 world (.State handler load readCont e le m) CC.E0
      (.State handler .Sskip readCont e (le.set Arm64Program._t'38 (.Vlong 0)) m) := by
    rw [load_source]
    apply CC.Step.builtin (vargs := [.Vptr tags.block (8#64)]) (vres := .Vlong 0)
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (load_arguments e le m tags.block pointer)
    · exact CC.VolatileLoadSem.intro _ _ _ _ _ _
        (.nonvol _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags.block) observed)
  have middle : InternalRun world 3
      (.State handler .Sskip readCont e (le.set Arm64Program._t'38 (.Vlong 0)) m)
      (.State handler store k e (temps le) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step (mid := .State handler .Sskip (.Kseq store k) e (temps le) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [copy,CC.doStep,CC.doEvalExpr,CC.PTree.gss,temps]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have last : CC.Step2 world (.State handler store k e (temps le) m) CC.E0
      (.State handler .Sskip k e (temps le) after) := by
    rw [store_source]
    apply CC.Step.builtin (vargs := [.Vptr tags.block (8#64),.Vlong 0]) (vres := .Vundef)
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (store_arguments e (temps le) m tags.block i
        (by simpa +decide only [temps,CC.PTree.gso] using pointer)
        (by simpa +decide only [temps,CC.PTree.gso] using bits) (CC.PTree.gss _ _ _))
    · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
        (.nonvol _ _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile tags.block) stored)
  have oneRead : CC.Star (CC.Step2 world) (.State handler load readCont e le m) CC.E0
      (.State handler .Sskip readCont e (le.set Arm64Program._t'38 (.Vlong 0)) m) :=
    .step _ _ _ _ _ _ read (.refl _) rfl
  have oneWrite : CC.Star (CC.Step2 world) (.State handler store k e (temps le) m) CC.E0
      (.State handler .Sskip k e (temps le) after) := .step _ _ _ _ _ _ last (.refl _) rfl
  refine ⟨after,?_,stored,Arm64MemsetTagByteTransport.word_store stored zero,
    FrameBelow.store tags.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using
    star_trans enter.sound (star_trans oneRead (star_trans middle.sound oneWrite))

end KProgFormal.ClightRefinement.Arm64MemcpyTagWrite
