import KProgFormal.ClightRefinement.Arm64MemsetTagRead

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetArmSelect

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
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
        throwError "original memset tag arm routing changed"
      pure actual.getAppArgs
    let route ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetTagRead.afterTag)) none) ``CC.Stmt.Ssequence 2
    let setup ← peel route[0]! ``CC.Stmt.Ssequence 2
    let select ← peel setup[0]! ``CC.Stmt.Ssequence 2
    let tested ← peel select[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memset_arm_select
      (← Lean.Meta.mkAppM ``Parts.mk #[route[0]!,setup[0]!,select[1]!,setup[1]!,tested[2]!,route[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_arm_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
private def select : CC.Stmt := by run_tac cachePart (← `(parts.select))
private def choose : CC.Stmt := by run_tac cachePart (← `(parts.choose))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
private def tested : CC.Stmt := by run_tac cachePart (← `(parts.tested))
def abi : CC.Stmt := by run_tac cachePart (← `(parts.abi))

theorem source : Arm64MemsetTagRead.afterTag = .Ssequence setup abi := rfl
private theorem setup_source : setup = .Ssequence select copy := rfl
private theorem select_source : select = .Ssequence Arm64Program.s_kprog_arm64_program_memset_12 choose := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  ((le.set Arm64Program._t'18 (.Vint 1)).set Arm64Program._t'19 (.Vint 0)).set
    Arm64Program.___a64_mwr_arm (.Vint 0)

/-- The actual tag4 test and real branch select arm0, retaining the original
ABI-read body and every source continuation and memory observation. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (tagged : le.get Arm64Program.___a64_mwr_tag = some (.Vint ((4#8).setWidth 32))) :
    InternalRun world 11 (.State handler Arm64MemsetTagRead.afterTag k e le m)
      (.State handler abi k e (temps le) m) := by
  let l1 := le.set Arm64Program._t'18 (.Vint 1)
  let l2 := l1.set Arm64Program._t'19 (.Vint 0)
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
  refine .step (mid := .State handler Arm64Program.s_kprog_arm64_program_memset_13
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

/-- The same original pointer/MOV effects and actual tag loads reach the
real ABI body in287 transitions. Canonical storage, all eight local allocations,
R0 and original SP observations remain in the full prefix contract. -/
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
      addresses origins next nextK constantWritten constantAfter) (k : CC.Cont) :
    ∃ current : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry,
      InternalRun world 287 (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter)
        (.State handler abi
          (Arm64MemsetTagRead.continuation
            (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
          (Arm64MemsetSource.allocation constantAfter).1
          (temps (Arm64MemsetTagRead.finalTemps (Arm64MemsetStackSetup.temps
            (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64)) 0)
            (current.tables true).tableBlock ((current.tables true).cellBlock 0) (4#8)))
          (Arm64MemsetSource.allocation constantAfter).2) ∧
      Arm64EntryMemory.gpr constantAfter.nextblock (Arm64MemsetSource.allocation constantAfter).2
        (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint ((4#8).setWidth 32)) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 40 = some (.Vptr storage.sp.block 0) ∧
      CC.Mem.load .Mint64 (Arm64MemsetSource.allocation constantAfter).2 storage.sp.block 0 = some (.Vlong storage.spValue) := by
  obtain ⟨current,prefixRun,r0,sp⟩ := Arm64MemsetTagRead.original mark pointer bound first second k
  have selected := execute (Arm64MemsetSource.allocation constantAfter).1
    (Arm64MemsetTagRead.finalTemps (Arm64MemsetStackSetup.temps
      (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64)) 0)
      (current.tables true).tableBlock ((current.tables true).cellBlock 0) (4#8))
    (Arm64MemsetSource.allocation constantAfter).2
    (Arm64MemsetTagRead.continuation
      (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
    (by simp only [Arm64MemsetTagRead.finalTemps,CC.PTree.gss])
  exact ⟨current,prefixRun.trans selected,r0,sp⟩

end KProgFormal.ClightRefinement.Arm64MemsetArmSelect
