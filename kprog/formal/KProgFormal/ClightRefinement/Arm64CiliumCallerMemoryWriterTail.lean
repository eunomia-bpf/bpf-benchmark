import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTagLoop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTail
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderTailValues (Storage)
open Arm64CiliumCallerSPPreindex (delta)

private noncomputable def cold : CC.Stmt := by
  run_tac do
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemoryWriterAddress.rest)) none
    let sequence ← Lean.Meta.withTransparency .all (Lean.Meta.whnf original)
    unless sequence.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original loss-tail sequence changed"
    let guard ← Lean.Meta.withTransparency .all (Lean.Meta.whnf sequence.getAppArgs[1]!)
    unless guard.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original loss-tail comparison changed"
    Lean.Elab.Tactic.closeMainGoal `actual_loss_cold guard.getAppArgs[1]!

private noncomputable def readStmt : CC.Stmt := .Sset _t'13859 (.Evar ___a64_sp CC.tlong)
private noncomputable def guardStmt : CC.Stmt := .Sifthenelse
  (.Ebinop .Olt (.Etempvar ___a64_loss_off CC.tlong) (.Etempvar _t'13859 CC.tlong) CC.tint) cold .Sskip

theorem rest_source : Arm64CiliumCallerMemoryWriterAddress.rest = .Ssequence readStmt guardStmt := rfl
theorem break_source : s_trusted_arm64_arm64_sim_xdp_142 = .Sbreak := rfl
noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv := le.set _t'13859 (.Vlong delta)

theorem sp_read {m supplied : CC.Mem} {locals : Arm64CiliumCallerDefaults.Locals m}
    {base original : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base)
    (payload : Arm64CiliumCallerMemoryWriterPayload.Store (before := word.after) header)
    (tags : Arm64CiliumCallerMemoryWriterTag.Store (before := payload.after) header original)
    (read : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 = some (.Vlong delta)) :
    CC.Mem.load .Mint64 tags.after (scalars.block 0) 0 = some (.Vlong delta) := by
  have cached := Arm64CiliumCallerReturnMemory.bound_frame cache (scalars.binding 0)
    (by decide +kernel) (by decide +kernel) .Mint64 0
  have wordFrame := Arm64CiliumCallerMemoryWriterWord.bound_frame word (scalars.binding 0)
    (by decide +kernel) .Mint64 0
  have payloadFrame := Arm64CiliumCallerMemoryWriterPayload.bound_frame payload (scalars.binding 0)
    (by decide +kernel) .Mint64 0
  have tagFrame := Arm64CiliumCallerMemoryWriterTag.bound_frame tags (scalars.binding 0)
    (by decide +kernel) .Mint64 0
  exact tagFrame.trans (payloadFrame.trans (wordFrame.trans (cached.trans read)))

noncomputable def incomingEnv {m : CC.Mem} (header : Storage m)
    (wordCells : Arm64CiliumCallerInitializers.Cells false m)
    (tagCells : Arm64CiliumCallerInitializers.Cells true m)
    (le : CC.TempEnv) (base original : BitVec 64) : CC.TempEnv :=
  Arm64CiliumCallerMemoryWriterTag.resultEnv header
    (Arm64CiliumCallerMemoryWriterTagLoop.inputEnv
      (Arm64CiliumCallerMemoryWriterUnmaterialize.resultEnv
        (Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv wordCells tagCells le base) base)) original

theorem loss_offset {m : CC.Mem} (header : Storage m)
    (wordCells : Arm64CiliumCallerInitializers.Cells false m)
    (tagCells : Arm64CiliumCallerInitializers.Cells true m)
    (le : CC.TempEnv) (base original : BitVec 64) :
    (incomingEnv header wordCells tagCells le base original).get ___a64_loss_off = some (.Vlong delta) := by
  simp +decide only [incomingEnv,Arm64CiliumCallerMemoryWriterTag.resultEnv,
    Arm64CiliumCallerMemoryWriterTag.loadEnv,Arm64CiliumCallerMemoryWriterTag.pointerEnv,
    Arm64CiliumCallerMemoryWriterTagLoop.inputEnv,Arm64CiliumCallerMemoryWriterTagLoop.indexEnv,CC.PTree.gso]
  rw [Arm64CiliumCallerMemoryWriterUnmaterialize.temp_frame _ base ___a64_loss_off
    (by decide +kernel) (by decide +kernel) (by decide +kernel)
    (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  unfold Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv
  rw [Arm64CiliumCallerMemoryWriterMask.temp_frame _ base ___a64_loss_off
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  exact (Arm64CiliumCallerMemoryWriterAddress.values _ delta base).1

private theorem read_step {m : CC.Mem} (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (le : CC.TempEnv) (before : CC.Mem)
    (read : CC.Mem.load .Mint64 before (scalars.block 0) 0 = some (.Vlong delta)) (k : CC.Cont) :
    CC.doStep ge (.State procedure readStmt k (allocation m).1 le before) =
      some (CC.E0,.State procedure .Sskip k (allocation m).1 (resultEnv le) before) := by
  have binding : (allocation m).1.get ___a64_sp = some (scalars.block 0,CC.tlong) := scalars.binding 0
  simp only [readStmt,CC.doStep,CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
  change (match CC.Mem.load .Mint64 before (scalars.block 0) 0 with
    | some v => some (CC.E0,CC.State.State procedure .Sskip k (allocation m).1 (le.set _t'13859 v) before)
    | none => none) = _
  rw [read]
  rfl

private theorem guard_step {m : CC.Mem} (le : CC.TempEnv) (before : CC.Mem)
    (offset : le.get ___a64_loss_off = some (.Vlong delta)) (k : CC.Cont) :
    CC.doStep ge (.State procedure guardStmt k (allocation m).1 (resultEnv le) before) =
      some (CC.E0,.State procedure .Sskip k (allocation m).1 (resultEnv le) before) := by
  have off : (resultEnv le).get ___a64_loss_off = some (.Vlong delta) := by
    simpa +decide only [resultEnv,CC.PTree.gso] using offset
  have sp : (resultEnv le).get _t'13859 = some (.Vlong delta) := CC.PTree.gss _ _ _
  simp only [guardStmt,CC.doStep,CC.doEvalExpr,off,sp] <;> rfl

/-- Consume the actual SP read and loss_off=SP comparison, skip its original
cold branch and exit the three original writer loops to the original rest. -/
theorem execute {m : CC.Mem} (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (le : CC.TempEnv) (before : CC.Mem)
    (read : CC.Mem.load .Mint64 before (scalars.block 0) 0 = some (.Vlong delta))
    (offset : le.get ___a64_loss_off = some (.Vlong delta)) (k : CC.Cont) :
    InternalRun ge 12
      (.State procedure .Sskip (Arm64CiliumCallerMemoryWriterAddress.continuation
        (Arm64CiliumCallerMemoryWriterPrefix.continuation k)) (allocation m).1 le before)
      (.State procedure Arm64CiliumCallerMemoryWriterPrefix.rest k (allocation m).1 (resultEnv le) before) := by
  unfold Arm64CiliumCallerMemoryWriterAddress.continuation Arm64CiliumCallerMemoryWriterPrefix.continuation
  rw [rest_source,break_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (read_step scalars le before read _)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (guard_step le before offset _)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The actual writer prefix and all three concrete stores now reach the
original caller statement following the memory writer; no heap step is hidden. -/
theorem advance {m supplied : CC.Mem} {locals : Arm64CiliumCallerDefaults.Locals m}
    {base original : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (tags : Arm64CiliumCallerTables.Table true m)
    (wordCells : Arm64CiliumCallerInitializers.Cells false m)
    (tagCells : Arm64CiliumCallerInitializers.Cells true m)
    (access : supplied.access = (allocation m).2.access)
    (spRead : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 = some (.Vlong delta))
    (abi : CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 = some (.Vint (1#32)))
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (current : CC.Mem.load .Mint64 supplied (header.block 2) 0 = some (.Vlong original))
    (le : CC.TempEnv) (width : le.get ___a64_l_width = some (.Vint (8#32))) (k : CC.Cont) :
    ∃ word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base,
      ∃ payload : Arm64CiliumCallerMemoryWriterPayload.Store (before := word.after) header,
        ∃ tagsWritten : Arm64CiliumCallerMemoryWriterTag.Store (before := payload.after) header original,
          CC.Star (CC.Step2 ge)
            (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
              (Arm64CiliumCallerReturnOutcomes.resultEnv
                (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) cache.after)
            CC.E0 (.State procedure Arm64CiliumCallerMemoryWriterPrefix.rest k (allocation m).1
              (resultEnv (incomingEnv header wordCells tagCells le base original)) tagsWritten.after) := by
  obtain ⟨word,payload,tagsWritten,writerRun⟩ := Arm64CiliumCallerMemoryWriterTagLoop.from_payload
    cache header scalars tags wordCells tagCells access spRead abi slot tag current le width k
  have read := sp_read cache header scalars word payload tagsWritten spRead
  have offset := loss_offset header wordCells tagCells le base original
  have tailRun := execute scalars (incomingEnv header wordCells tagCells le base original)
    tagsWritten.after read offset k
  refine ⟨word,payload,tagsWritten,?_⟩
  simpa only [CC.Eapp,CC.E0,List.nil_append] using star_trans writerRun tailRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTail
