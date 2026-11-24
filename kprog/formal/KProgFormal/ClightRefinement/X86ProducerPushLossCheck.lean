import KProgFormal.ClightRefinement.X86ProducerPushCachePrefix

namespace KProgFormal.ClightRefinement.X86ProducerPushLossCheck
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler)

private structure Parts where
  first : CC.Stmt
  second : CC.Stmt
  condition : CC.Expr
  release : CC.Stmt
private def parts : Parts := by
  run_tac do
    let norm (e : Lean.Expr) := Lean.Meta.withTransparency .all (Lean.Meta.whnf e)
    let first ← norm (← Lean.Elab.Term.elabTerm (← `(X86ProducerPushStorageSource.lossCheck)) none)
    unless first.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH loss-check first sequence changed"
    let second ← norm first.getAppArgs[1]!
    unless second.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH loss-check second sequence changed"
    let branch ← norm second.getAppArgs[1]!
    unless branch.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original PUSH signed loss branch changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_loss_check
      (← Lean.Meta.mkAppM ``Parts.mk #[first.getAppArgs[0]!,second.getAppArgs[0]!,branch.getAppArgs[0]!,branch.getAppArgs[1]!])

def first : CC.Stmt := parts.first
def second : CC.Stmt := parts.second
def condition : CC.Expr := parts.condition
def release : CC.Stmt := parts.release

theorem source : X86ProducerPushStorageSource.lossCheck = .Ssequence first (.Ssequence second (.Sifthenelse condition release .Sskip)) ∧
    first = .Sset X86_program_profile_bpf._t'200 X86ProducerPushRspSource.headerRead ∧
    second = .Sset X86_program_profile_bpf._t'201 (X86ProducerPushRspAddress.pointer X86_program_profile_bpf._t'200) ∧
    condition = .Ebinop .Olt (.Etempvar X86_program_profile_bpf.___x86_loss_off CC.tlong)
      (.Ecast (.Ecast (.Etempvar X86_program_profile_bpf._t'201 (CC.tptr CC.tvoid)) CC.tlong) CC.tlong) CC.tint := ⟨rfl,rfl,rfl,rfl⟩

def firstTemps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := le.set X86_program_profile_bpf._t'200 (.Vptr cells 0)
def temps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := (firstTemps le cells).set X86_program_profile_bpf._t'201 (.Vlong X86ProducerPushRspStore.nextRsp)

theorem execute (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (binding cells : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (offset : le.get X86_program_profile_bpf.___x86_loss_off = some (.Vlong X86ProducerPushRspStore.nextRsp))
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells 0))
    (rsp : CC.Mem.load CC.Mptr memory cells 64 = some (.Vlong X86ProducerPushRspStore.nextRsp)) :
    InternalRun ge 7 (.State handler X86ProducerPushStorageSource.lossCheck k e le memory)
      (.State handler .Sskip k e (temps le cells) memory) := by
  have h1 := X86ProducerPushRspAddress.header_value e le memory binding cells bound header
  have pointer : (firstTemps le cells).get X86_program_profile_bpf._t'200 = some (.Vptr cells 0) := CC.PTree.gss _ _ _
  have h2 := X86ProducerPushPointerRead.scalar e (firstTemps le cells) memory cells _ _ pointer rsp
  have word : (temps le cells).get X86_program_profile_bpf._t'201 = some (.Vlong X86ProducerPushRspStore.nextRsp) := CC.PTree.gss _ _ _
  have sameOffset : (temps le cells).get X86_program_profile_bpf.___x86_loss_off = some (.Vlong X86ProducerPushRspStore.nextRsp) := by
    simpa +decide [temps, firstTemps, CC.PTree.gso] using offset
  have test : CC.doEvalExpr ge e (temps le cells) memory condition = some (.Vint 0) := by
    rw [source.2.2.2]
    simp only [CC.doEvalExpr, sameOffset, word]
    rfl
  have type : CC.typeof condition = CC.tint := rfl
  have selected : CC.Cop.boolVal (.Vint 0) CC.tint memory = some false := rfl
  dsimp only [firstTemps, temps] at h2 test
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, source.1, source.2.1, source.2.2.1,
    h1, h2, test, type, selected, temps, firstTemps, CC.E0, CC.Eapp, List.nil_append, true_and]
  all_goals rfl

theorem from_cache {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (result : X86ProducerPushCachePrefix.Result metadata) (k : CC.Cont) :
    InternalRun ge 7
      (.State handler X86ProducerPushStorageSource.lossCheck k (X86ProducerPushBody.allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) result.after)
      (.State handler .Sskip k (X86ProducerPushBody.allocation ready.after).1 (temps (X86ProducerPushCachePrefix.temps metadata) ready.gprs.block) result.after) :=
  execute _ _ _ _ ready.entry.block ready.gprs.block (X86ProducerPushCachePrefix.inputs metadata).1
    (X86ProducerPushCachePrefix.inputs metadata).2 result.cells_read result.rsp_read

end KProgFormal.ClightRefinement.X86ProducerPushLossCheck
