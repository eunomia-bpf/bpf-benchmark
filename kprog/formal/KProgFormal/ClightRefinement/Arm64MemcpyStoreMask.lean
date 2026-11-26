import KProgFormal.ClightRefinement.Arm64MemcpyStoreIndex

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyStoreMask

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  width : CC.Stmt
  afterWidth : CC.Stmt
  maskValue : CC.Stmt
  afterValue : CC.Stmt
  choice : CC.Stmt
  value : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memcpy byte-mask route changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyStoreIndex.afterIndex)) none)
    let rest ← peel root[1]!
    let mask ← peel rest[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_store_mask
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,rest[0]!,rest[1]!,mask[0]!,mask[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_store_mask_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def width : CC.Stmt := by run_tac cachePart (← `(parts.width))
private def afterWidth : CC.Stmt := by run_tac cachePart (← `(parts.afterWidth))
private def maskValue : CC.Stmt := by run_tac cachePart (← `(parts.maskValue))
def afterValue : CC.Stmt := by run_tac cachePart (← `(parts.afterValue))
private def choice : CC.Stmt := by run_tac cachePart (← `(parts.choice))
private def value : CC.Stmt := by run_tac cachePart (← `(parts.value))

theorem source : Arm64MemcpyStoreIndex.afterIndex = .Ssequence width afterWidth ∧
    afterWidth = .Ssequence maskValue afterValue ∧ maskValue = .Ssequence choice value := ⟨rfl,rfl,rfl⟩

def temps (le : CC.TempEnv) (word : BitVec 64) : CC.TempEnv :=
  (((le.set Arm64Program.___a64_stw_width (.Vint 1)).set Arm64Program._t'30 (.Vlong 255))).set
    Arm64Program.___a64_stw_value (.Vlong (word &&& (255#64)))

/-- The original byte width selects the real mask255 assignment and actual
bitwise value expression before the source alignment/action logic. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (word : BitVec 64)
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong word)) :
    InternalRun world 10 (.State handler Arm64MemcpyStoreIndex.afterIndex k e le m)
      (.State handler afterValue k e (temps le word) m) := by
  apply internalRun_of_steps
  all_goals simp +decide [source.1,source.2.1,source.2.2,width,choice,value,temps,
    Arm64Program.s_kprog_arm64_program_memcpy_31,InternalPath,InternalState,steps,
    CC.doStep,CC.doEvalExpr,hwidth,hvalue,CC.PTree.gss,CC.PTree.gso,
    CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.semAnd,
    CC.Cop.classifyCmp,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,
    CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.classifyBool,CC.Cop.boolVal,
    CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tattr,CC.Archi.ptr64,
    CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
    CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,
    CC.Integers.MI.unsigned,CC.Integers.Int.signed,CC.Integers.MI.signed,
    CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.E0,CC.Eapp,List.nil_append]
  rfl

theorem byte_mask (byte : BitVec 8) : byte.setWidth 64 &&& (255#64) = byte.setWidth 64 := by
  change byte.setWidth 64 &&& (BitVec.allOnes 8).setWidth 64 = byte.setWidth 64
  rw [←BitVec.setWidth_and,BitVec.and_allOnes]

theorem observations (le : CC.TempEnv) (byte : BitVec 8) :
    (temps le (byte.setWidth 64)).get Arm64Program.___a64_stw_width = some (.Vint 1) ∧
    (temps le (byte.setWidth 64)).get Arm64Program.___a64_stw_value = some (.Vlong (byte.setWidth 64)) := by
  simp +decide only [temps,CC.PTree.gso,CC.PTree.gss,byte_mask]

end KProgFormal.ClightRefinement.Arm64MemcpyStoreMask
