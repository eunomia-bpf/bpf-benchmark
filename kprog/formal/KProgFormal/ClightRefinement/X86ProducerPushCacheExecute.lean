import KProgFormal.ClightRefinement.X86ProducerPushStorageSelect
import KProgFormal.ClightRefinement.X86ProducerPushCacheAddress
import KProgFormal.ClightRefinement.X86ProducerPushCacheStore

namespace KProgFormal.ClightRefinement.X86ProducerPushCacheExecute
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)
open X86ProducerPushStorageSource (cacheRead cacheStore)

/-- The actual selected cache read returns to its real qword assignment. -/
def following {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`rsp,`k,`memory].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing actual PUSH cache continuation argument"
      pure (Lean.mkFVar argument.fvarId)
    let cert ← Lean.Meta.mkAppM ``X86ProducerPushStorageSelect.secondCertificate arguments
    let continuation ← Lean.Meta.mkAppM ``X86ProducerPushStorageSelect.SecondCertificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf continuation)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original PUSH cache assignment continuation changed"
    let expected ← Lean.Elab.Term.elabTerm (← `(cacheStore)) none
    unless ← Lean.Meta.isDefEq node.getAppArgs[0]! expected do throwError "original PUSH selected a different store"
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_cache_continuation node.getAppArgs[1]!

theorem continuation_source {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) :
    (X86ProducerPushStorageSelect.secondCertificate rsp k memory).continuation = .Kseq cacheStore (following rsp k memory) := rfl

theorem load_header (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (binding cache : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (header : CC.Mem.load CC.Mptr memory binding 8 = some (.Vptr cache 0)) :
    InternalRun ge 2 (.State handler cacheRead (.Kseq cacheStore k) e le memory)
      (.State handler cacheStore k e (le.set X86_program_profile_bpf._t'211 (.Vptr cache 0)) memory) := by
  have value := X86ProducerPushCacheAddress.read_value e le memory binding cache bound header
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, X86ProducerPushCacheAddress.source.1,
    value, CC.E0, CC.Eapp, List.nil_append, true_and]

theorem assignment (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory after : CC.Mem) (cache : CC.Block) (word : BitVec 64)
    (pointer : le.get X86_program_profile_bpf._t'211 = some (.Vptr cache 0))
    (index : le.get X86_program_profile_bpf.___x86_stw_index = some (.Vlong (40#64)))
    (value : le.get X86_program_profile_bpf.___x86_loss_value = some (.Vlong word))
    (stored : CC.Mem.store .Mint64 memory cache 40 (.Vlong word) = some after) :
    InternalRun ge 1 (.State handler cacheStore k e le memory) (.State handler .Sskip k e le after) := by
  have address := X86ProducerPushCacheAddress.address e le memory cache pointer index
  have rhs : CC.doEvalExpr ge e le memory X86ProducerPushCacheAddress.rhs = some (.Vlong word) := value
  have cast : CC.Cop.semCast (.Vlong word) (CC.typeof X86ProducerPushCacheAddress.rhs)
      (CC.typeof X86ProducerPushCacheAddress.target) memory = some (.Vlong word) := rfl
  have access : CC.accessMode (CC.typeof X86ProducerPushCacheAddress.target) = .By_value .Mint64 := rfl
  have storev : CC.Mem.storev .Mint64 memory (.Vptr cache (40#64)) (.Vlong word) = some after := stored
  have step : CC.doStep ge (.State handler cacheStore k e le memory) = some (CC.E0,.State handler .Sskip k e le after) := by
    rw [X86ProducerPushCacheAddress.source.2]
    simp only [CC.doStep, address, rhs, cast, CC.doAssignLoc, access]
    change (match CC.Mem.storev .Mint64 memory (.Vptr cache (40#64)) (.Vlong word) with
      | some heap => some (CC.E0,CC.State.State handler .Sskip k e le heap)
      | none => none) = _
    rw [storev]
  exact .step trivial (CC.doStep_sound ge _ _ _ step) (.refl _)

theorem from_metadata {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (result : X86ProducerPushMetadataPrefix.Result rsp) (k : CC.Cont) :
    ∃ after, InternalRun ge (12 + 8 + (X86ProducerPushStorageSelect.firstCertificate rsp k result.after).count + 8 +
        (X86ProducerPushStorageSelect.secondCertificate rsp k result.after).count + 3)
      (.State handler X86ProducerPushStackSource.storage k (allocation ready.after).1 (X86ProducerPushStorageSetup.initialTemps rsp) result.after)
      (.State handler .Sskip (following rsp k result.after) (allocation ready.after).1
        ((X86ProducerPushStorageSelect.secondCertificate rsp k result.after).output.set X86_program_profile_bpf._t'211 (.Vptr (ready.sources 1).block 0)) after) ∧
    CC.Mem.store .Mint64 result.after (ready.sources 1).block 40 (.Vlong (ready.values 3)) = some after ∧
    CC.Mem.load .Mint64 after (ready.sources 1).block 40 = some (.Vlong (ready.values 3)) ∧
    (∀ c b ofs, b ≠ (ready.sources 1).block ∨ ofs + CC.sizeChunk c ≤ 40 ∨ 48 ≤ ofs → CC.Mem.load c after b ofs = CC.Mem.load c result.after b ofs) ∧
    FrameBelow before.nextblock result.after after ∧ after.access = result.after.access ∧ after.nextblock = result.after.nextblock := by
  obtain ⟨after,stored,back,frame,caller,access,frontier⟩ := X86ProducerPushCacheStore.write result
  have inputs := X86ProducerPushStorageSelect.cache_inputs rsp k result.after
  have selected := X86ProducerPushStorageSelect.from_metadata result k
  rw [continuation_source] at selected
  have loaded := load_header (allocation ready.after).1 _ (following rsp k result.after) result.after
    ready.entry.block (ready.sources 1).block inputs.1 result.cache_view.header
  have pointer : ((X86ProducerPushStorageSelect.secondCertificate rsp k result.after).output.set X86_program_profile_bpf._t'211 (.Vptr (ready.sources 1).block 0)).get X86_program_profile_bpf._t'211 = some (.Vptr (ready.sources 1).block 0) := CC.PTree.gss _ _ _
  have index : ((X86ProducerPushStorageSelect.secondCertificate rsp k result.after).output.set X86_program_profile_bpf._t'211 (.Vptr (ready.sources 1).block 0)).get X86_program_profile_bpf.___x86_stw_index = some (.Vlong (40#64)) := by
    simpa +decide [CC.PTree.gso] using inputs.2.1
  have value : ((X86ProducerPushStorageSelect.secondCertificate rsp k result.after).output.set X86_program_profile_bpf._t'211 (.Vptr (ready.sources 1).block 0)).get X86_program_profile_bpf.___x86_loss_value = some (.Vlong (ready.values 3)) := by
    simpa +decide [CC.PTree.gso] using inputs.2.2.1
  have assigned := assignment (allocation ready.after).1 _ (following rsp k result.after) result.after after (ready.sources 1).block (ready.values 3) pointer index value stored
  exact ⟨after,(selected.trans loaded).trans assigned,stored,back,frame,caller,access,frontier⟩

end KProgFormal.ClightRefinement.X86ProducerPushCacheExecute
