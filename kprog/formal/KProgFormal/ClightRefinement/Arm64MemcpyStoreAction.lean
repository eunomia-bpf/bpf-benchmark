import KProgFormal.ClightRefinement.Arm64MemcpyStoreMask

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyStoreAction

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  setup : CC.Stmt
  test : CC.Stmt
  assign : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memcpy store action changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyStoreMask.afterValue)) none)
    let setup ← peel root[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_store_action
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,setup[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_store_action_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
private def test : CC.Stmt := by run_tac cachePart (← `(parts.test))
private def assign : CC.Stmt := by run_tac cachePart (← `(parts.assign))
theorem source : Arm64MemcpyStoreMask.afterValue = .Ssequence setup test ∧
    setup = .Ssequence Arm64Program.s_kprog_arm64_program_memcpy_33 assign := ⟨rfl,rfl⟩

def index (i : Fin 16) : BitVec 64 := BitVec.ofNat 64 (80+i.val)
def action (i : Fin 16) : BitVec 32 := if i.val=0 ∨ i.val=8 then 1 else 2
private def aligned (i : Fin 16) : BitVec 32 := if i.val=0 ∨ i.val=8 then 1 else 0
def temps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv :=
  (((((le.set Arm64Program._t'31 (.Vint 0)).set Arm64Program._t'33 (.Vint (aligned i))).set
    Arm64Program._t'32 (.Vint (action i))).set Arm64Program._t'32 (.Vint (action i))).set
    Arm64Program.___a64_stw_action (.Vint (action i)))

private theorem cases16 : ∀ i : Fin 16,
    i=⟨0,by decide⟩ ∨ i=⟨1,by decide⟩ ∨ i=⟨2,by decide⟩ ∨ i=⟨3,by decide⟩ ∨
    i=⟨4,by decide⟩ ∨ i=⟨5,by decide⟩ ∨ i=⟨6,by decide⟩ ∨ i=⟨7,by decide⟩ ∨
    i=⟨8,by decide⟩ ∨ i=⟨9,by decide⟩ ∨ i=⟨10,by decide⟩ ∨ i=⟨11,by decide⟩ ∨
    i=⟨12,by decide⟩ ∨ i=⟨13,by decide⟩ ∨ i=⟨14,by decide⟩ ∨ i=⟨15,by decide⟩ := by decide +kernel

/-- All sixteen actual byte destinations execute the original width8 test,
alignment alternatives, value casts and real nonzero-action dispatch. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (index i))) :
    InternalRun world 20 (.State handler Arm64MemcpyStoreMask.afterValue k e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81 k e (temps le i) m) := by
  rcases cases16 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals
    apply internalRun_of_steps
    all_goals simp +decide [source.1,source.2,Arm64Program.s_kprog_arm64_program_memcpy_33,
      assign,test,InternalPath,InternalState,steps,temps,action,aligned,index,
      CC.doStep,CC.doEvalExpr,hwidth,hindex,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.semAnd,
      CC.Cop.classifyCmp,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,
      CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.classifyBool,CC.Cop.boolVal,
      CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,CC.typeconv,CC.removeAttributes,
      CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tbool,CC.tattr,CC.Archi.ptr64,
      CC.Integers.Int.cmpu,CC.Integers.Int.cmp,CC.Integers.MI.cmpu,CC.Integers.MI.cmp,
      CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,
      CC.Integers.MI.unsigned,CC.Integers.Int.signed,CC.Integers.MI.signed,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.E0,CC.Eapp,List.nil_append]

theorem kept (le : CC.TempEnv) (i : Fin 16) (id : CC.Ident)
    (actionOther : Arm64Program.___a64_stw_action ≠ id) (choiceOther : Arm64Program._t'32 ≠ id)
    (alignedOther : Arm64Program._t'33 ≠ id) (guardOther : Arm64Program._t'31 ≠ id) :
    (temps le i).get id = le.get id := by
  simp only [temps,CC.PTree.gso _ _ _ _ actionOther,CC.PTree.gso _ _ _ _ choiceOther,
    CC.PTree.gso _ _ _ _ alignedOther,CC.PTree.gso _ _ _ _ guardOther]

end KProgFormal.ClightRefinement.Arm64MemcpyStoreAction
