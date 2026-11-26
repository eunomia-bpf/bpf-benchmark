import KProgFormal.ClightRefinement.Arm64MemcpyDestinationTag

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyArmSelect

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  first : CC.Stmt
  zero : CC.Stmt
  setup : CC.Stmt
  select : CC.Stmt
  choose : CC.Stmt
  copy : CC.Stmt
  tested : CC.Stmt
  abi : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do
        throwError "original memcpy tag arm routing changed"
      pure actual.getAppArgs
    let route ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyDestinationTag.afterTag)) none) ``CC.Stmt.Ssequence 2
    let setup ← peel route[0]! ``CC.Stmt.Ssequence 2
    let select ← peel setup[0]! ``CC.Stmt.Ssequence 2
    let tested ← peel select[0]! ``CC.Stmt.Sifthenelse 3
    let choose ← peel select[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_arm_select
      (← Lean.Meta.mkAppM ``Parts.mk #[select[0]!,choose[1]!,route[0]!,setup[0]!,select[1]!,setup[1]!,tested[2]!,route[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_arm_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def first : CC.Stmt := by run_tac cachePart (← `(parts.first))
private def zero : CC.Stmt := by run_tac cachePart (← `(parts.zero))
private def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
private def select : CC.Stmt := by run_tac cachePart (← `(parts.select))
private def choose : CC.Stmt := by run_tac cachePart (← `(parts.choose))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
private def tested : CC.Stmt := by run_tac cachePart (← `(parts.tested))
def abi : CC.Stmt := by run_tac cachePart (← `(parts.abi))

theorem source : Arm64MemcpyDestinationTag.afterTag = .Ssequence setup abi := rfl
private theorem setup_source : setup = .Ssequence select copy := rfl
private theorem select_source : select = .Ssequence first choose := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  ((le.set Arm64Program._t'19 (.Vint 1)).set Arm64Program._t'20 (.Vint 0)).set
    Arm64Program.___a64_mwr_arm (.Vint 0)

/-- The actual tag4 test and real branch select arm0, retaining the original
ABI-read body and every source continuation and memory observation. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (tagged : le.get Arm64Program.___a64_mwr_tag = some (.Vint ((4#8).setWidth 32))) :
    InternalRun world 11 (.State handler Arm64MemcpyDestinationTag.afterTag k e le m)
      (.State handler abi k e (temps le) m) := by
  let l1 := le.set Arm64Program._t'19 (.Vint 1)
  let l2 := l1.set Arm64Program._t'20 (.Vint 0)
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [setup_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [select_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler tested (.Kseq choose (.Kseq copy (.Kseq abi k))) e le m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq choose (.Kseq copy (.Kseq abi k))) e l1 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [tested,CC.doStep,CC.doEvalExpr,tagged]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler zero
    (.Kseq copy (.Kseq abi k)) e l1 m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [choose,CC.doStep,CC.doEvalExpr,l1,CC.PTree.gss]
    rfl
  refine .step (mid := .State handler .Sskip (.Kseq copy (.Kseq abi k)) e l2 m)
    trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq abi k) e (temps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [copy,CC.doStep,CC.doEvalExpr,l2,CC.PTree.gss]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The actual routing setters retain every unrelated original input. -/
theorem kept (le : CC.TempEnv) (key : CC.Ident)
    (arm : Arm64Program.___a64_mwr_arm ≠ key) (t20 : Arm64Program._t'20 ≠ key) (t19 : Arm64Program._t'19 ≠ key) :
    (temps le).get key = le.get key := by
  simp only [temps,CC.PTree.gso _ _ _ _ arm,CC.PTree.gso _ _ _ _ t20,CC.PTree.gso _ _ _ _ t19]

/-- The current actual destination offset/tag path selects its real arm0
and reaches the original ABI reader without changing the reached heap. -/
theorem current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abiLocal : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (packet : Arm64MemcpyLoopState.Invariant base abiLocal byte gprs flags values calleeBefore i.val m le) :
    InternalRun world 117 (.State handler Arm64MemcpyLoop.write k e le m)
      (.State handler abi (Arm64MemcpyDestinationTag.continuation k) e
        (temps (Arm64MemcpyDestinationTag.finalTemps (Arm64MemcpyStackSetup.temps le (BitVec.ofNat 64 i.val))
          (packet.packet.storage.tables true).tableBlock ((packet.packet.storage.tables true).cellBlock 0) (4#8))) m) := by
  have start := Arm64MemcpyDestinationTag.current e le k i packet
  have choose := execute e
    (Arm64MemcpyDestinationTag.finalTemps (Arm64MemcpyStackSetup.temps le (BitVec.ofNat 64 i.val))
      (packet.packet.storage.tables true).tableBlock ((packet.packet.storage.tables true).cellBlock 0) (4#8))
    m (Arm64MemcpyDestinationTag.continuation k)
    (by simp only [Arm64MemcpyDestinationTag.finalTemps,CC.PTree.gss])
  exact start.trans choose

end KProgFormal.ClightRefinement.Arm64MemcpyArmSelect
