import KProgFormal.ClightRefinement.Arm64MemcpySourceTag

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyCopyEntry

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  guard : CC.Stmt
  afterGuard : CC.Stmt
  init : CC.Stmt
  loop : CC.Stmt
  afterCopy : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memcpy copy entry changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpySourceTag.afterTag)) none)
    let afterGuard ← peel outer[1]!
    let copy ← peel afterGuard[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_copy_entry
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,outer[1]!,copy[0]!,copy[1]!,afterGuard[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_copy_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def afterGuard : CC.Stmt := by run_tac cachePart (← `(parts.afterGuard))
private def init : CC.Stmt := by run_tac cachePart (← `(parts.init))
def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
def afterCopy : CC.Stmt := by run_tac cachePart (← `(parts.afterCopy))

theorem source : Arm64MemcpySourceTag.afterTag = .Ssequence guard afterGuard ∧
    afterGuard = .Ssequence (.Ssequence init loop) afterCopy := ⟨rfl,rfl⟩
def guardTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'3 (.Vint 0)
def temps (le : CC.TempEnv) : CC.TempEnv := (guardTemps le).set Arm64Program.___a64_lib_i (.Vlong 0)
def continuation (k : CC.Cont) : CC.Cont := .Kseq afterCopy k

/-- The actual nonzero length and stack tag4 evaluate the original scalar
source guard to false and select its real Sskip arm on the same heap. -/
theorem guarded (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (length : le.get Arm64Program.___a64_lib_len = some (.Vlong (16#64)))
    (tag : le.get Arm64Program.___a64_lib_src_tag = some (.Vint ((4#8).setWidth 32))) :
    InternalRun world 7 (.State handler Arm64MemcpySourceTag.afterTag k e le m)
      (.State handler afterGuard k e (guardTemps le) m) := by
  rw [source.1]
  apply internalRun_of_steps
  · simp +decide [InternalPath,InternalState,steps,CC.doStep,guard,CC.doEvalExpr,length,tag,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.semBinaryOperation,CC.Cop.classifyCmp,
      CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Cop.boolVal,CC.Cop.classifyBool,CC.Integers.Int64.eq,CC.Integers.Int64.zero,CC.typeof,CC.tbool,CC.tint,CC.tuint,CC.tuchar,CC.tulong,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.PTree.gss,CC.Val.ofBool,CC.Val.Vfalse,CC.Integers.Int.eq,
      CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero]
  · simp +decide [steps,CC.doStep,guard,CC.doEvalExpr,length,tag,guardTemps,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.semBinaryOperation,CC.Cop.classifyCmp,
      CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Cop.boolVal,CC.Cop.classifyBool,CC.Integers.Int64.eq,CC.Integers.Int64.zero,CC.typeof,CC.tbool,CC.tint,CC.tuint,CC.tuchar,CC.tulong,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.PTree.gss,CC.Val.ofBool,CC.Val.Vfalse,CC.Integers.Int.eq,
      CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero]

/-- The real initializer sets counter0 and enters the actual original copy
loop, keeping its real following tag-transfer/clobber continuation. -/
theorem initialized (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4 (.State handler afterGuard k e (guardTemps le) m)
      (.State handler loop (continuation k) e (temps le) m) := by
  rw [source.2]
  apply internalRun_of_steps
  · simp +decide [InternalPath,InternalState,steps,CC.doStep,init,CC.doEvalExpr,CC.typeof,CC.tulong,CC.tint,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.Integers.Int64.repr,CC.Integers.MI.repr]
  · simp +decide [steps,CC.doStep,init,CC.doEvalExpr,CC.typeof,CC.tulong,CC.tint,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.Integers.Int64.repr,CC.Integers.MI.repr,temps,continuation]
    all_goals rfl

theorem observations (le : CC.TempEnv) :
    (temps le).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (temps le).get Arm64Program.___a64_lib_src_tag = le.get Arm64Program.___a64_lib_src_tag ∧
    (temps le).get Arm64Program.___a64_lib_i = some (.Vlong 0) := by
  simp +decide only [temps,guardTemps,CC.PTree.gso,CC.PTree.gss]

/-- The same actual R1-tag path, scalar guard and counter initializer reach
copy iteration0 in37 transitions and preserve the entire memory. -/
theorem ready {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (length : le.get Arm64Program.___a64_lib_len = some (.Vlong (16#64)))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 1 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32))) :
    InternalRun world 37 (.State handler Arm64MemcpySource.afterLength k e le m)
      (.State handler loop (continuation k) e
        (temps (Arm64MemcpySourceTag.finalTemps le (storage.tables true).tableBlock ((storage.tables true).cellBlock 1) (4#8))) m) := by
  have tagRun := Arm64MemcpySourceTag.complete storage e le k (.Vlong (-32#64)) (4#8) hentry observed
  have current := Arm64MemcpySourceTag.observations le (storage.tables true).tableBlock ((storage.tables true).cellBlock 1) (4#8)
  have guardRun := guarded e _ m k (current.2.1.trans length) current.2.2
  exact (tagRun.trans guardRun).trans (initialized e _ m k)

end KProgFormal.ClightRefinement.Arm64MemcpyCopyEntry
