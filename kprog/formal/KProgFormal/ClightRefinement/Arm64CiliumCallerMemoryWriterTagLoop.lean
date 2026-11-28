import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTag

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTagLoop
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderTailValues (Storage)

noncomputable def statement : CC.Stmt := Arm64CiliumCallerMemoryWriterUnmaterialize.tags
noncomputable def index : CC.Stmt := .Sset ___ti
  (.Ebinop .Oshr (.Ecast (.Etempvar ___a64_stw_index CC.tulong) CC.tulong)
    (.Econst_int (CC.Integers.Int.repr 3) CC.tint) CC.tulong)
noncomputable def shift : CC.Stmt := s_trusted_arm64_arm64_sim_xdp_79
noncomputable def body : CC.Stmt :=
  .Ssequence index (.Ssequence shift Arm64CiliumCallerMemoryWriterTag.statement)

theorem source : statement = .Sloop body .Sbreak := rfl
theorem shift_source : shift = .Sset ___ts
    (.Ecast (.Ebinop .Omul
      (.Ebinop .Oand (.Etempvar ___ti CC.tulong)
        (.Econst_int (CC.Integers.Int.repr 7) CC.tuint) CC.tulong)
      (.Econst_int (CC.Integers.Int.repr 8) CC.tuint) CC.tulong) CC.tuint) := rfl

noncomputable def indexEnv (le : CC.TempEnv) : CC.TempEnv := le.set ___ti (.Vlong (0#64))
noncomputable def inputEnv (le : CC.TempEnv) : CC.TempEnv := (indexEnv le).set ___ts (.Vint (0#32))

theorem values (le : CC.TempEnv) :
    (inputEnv le).get ___ti = some (.Vlong (0#64)) ∧
    (inputEnv le).get ___ts = some (.Vint (0#32)) := by
  simp +decide only [inputEnv,indexEnv,CC.PTree.gss,CC.PTree.gso]

theorem tag_frame (le : CC.TempEnv) :
    (inputEnv le).get ___a64_store_tag = le.get ___a64_store_tag := by
  simp +decide only [inputEnv,indexEnv,CC.PTree.gso]

private theorem index_step {m : CC.Mem} (le : CC.TempEnv) (before : CC.Mem)
    (read : le.get ___a64_stw_index = some (.Vlong (0#64))) (k : CC.Cont) :
    CC.doStep ge (.State procedure index k (allocation m).1 le before) =
      some (CC.E0,.State procedure .Sskip k (allocation m).1 (indexEnv le) before) := by
  simp only [index,CC.doStep,CC.doEvalExpr,read] <;> rfl

private theorem shift_step {m : CC.Mem} (le : CC.TempEnv) (before : CC.Mem) (k : CC.Cont) :
    CC.doStep ge (.State procedure shift k (allocation m).1 (indexEnv le) before) =
      some (CC.E0,.State procedure .Sskip k (allocation m).1 (inputEnv le) before) := by
  have read : (indexEnv le).get ___ti = some (.Vlong (0#64)) := CC.PTree.gss _ _ _
  simp only [shift_source,CC.doStep,CC.doEvalExpr,read] <;> rfl

/-- The original tag-loop header derives ti0 and ts0 from the actual writer
index, without introducing new temporary-value premises. -/
theorem prepare {m : CC.Mem} (le : CC.TempEnv) (before : CC.Mem)
    (read : le.get ___a64_stw_index = some (.Vlong (0#64))) (k : CC.Cont) :
    InternalRun ge 7 (.State procedure statement k (allocation m).1 le before)
      (.State procedure Arm64CiliumCallerMemoryWriterTag.statement
        (.Kloop1 body .Sbreak k) (allocation m).1 (inputEnv le) before) := by
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  change InternalRun ge 6 (.State procedure body (.Kloop1 body .Sbreak k) (allocation m).1 le before) _
  rw [body]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (index_step le before read _)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (shift_step le before _)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The exact original loop header, both real volatile builtins and loop exit.
The numeric tag word remains an explicit current memory resource. -/
theorem advance {m before : CC.Mem} (header : Storage m) (le : CC.TempEnv)
    (original : BitVec 64) (access : before.access = (allocation m).2.access)
    (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (tag : le.get ___a64_store_tag = some (.Vint (10#32)))
    (read : CC.Mem.load .Mint64 before (header.block 2) 0 = some (.Vlong original)) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerMemoryWriterTag.Store (before := before) header original,
      CC.Star (CC.Step2 ge) (.State procedure statement k (allocation m).1 le before)
        CC.E0 (.State procedure .Sskip k (allocation m).1
          (Arm64CiliumCallerMemoryWriterTag.resultEnv header (inputEnv le) original) result.after) := by
  have tagValue := (tag_frame le).trans tag
  obtain ⟨result,written⟩ := Arm64CiliumCallerMemoryWriterTag.advance header (inputEnv le) original
    access (values le).1 (values le).2 tagValue read (.Kloop1 body .Sbreak k)
  have exited : CC.Star (CC.Step2 ge)
      (.State procedure .Sskip (.Kloop1 body .Sbreak k) (allocation m).1
        (Arm64CiliumCallerMemoryWriterTag.resultEnv header (inputEnv le) original) result.after)
      CC.E0 (.State procedure .Sskip k (allocation m).1
        (Arm64CiliumCallerMemoryWriterTag.resultEnv header (inputEnv le) original) result.after) := by
    refine .step _ _ _ _ _ _ (CC.Step.skip_or_continue_loop1 _ _ _ _ _ _ _ _ (Or.inl rfl)) ?_ rfl
    exact .step _ _ _ _ _ _ (CC.Step.break_loop2 _ _ _ _ _ _ _) (.refl _) rfl
  refine ⟨result,?_⟩
  simpa only [CC.Eapp,CC.E0,List.nil_append] using
    star_trans (prepare le before index k).sound (star_trans written exited)

theorem incoming_tag {m : CC.Mem}
    (wordCells : Arm64CiliumCallerInitializers.Cells false m)
    (tagCells : Arm64CiliumCallerInitializers.Cells true m) (le : CC.TempEnv) (base : BitVec 64) :
    (Arm64CiliumCallerMemoryWriterUnmaterialize.resultEnv
      (Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv wordCells tagCells le base) base).get
      ___a64_store_tag = some (.Vint (10#32)) := by
  rw [Arm64CiliumCallerMemoryWriterUnmaterialize.temp_frame _ base ___a64_store_tag
    (by decide +kernel) (by decide +kernel) (by decide +kernel)
    (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  exact Arm64CiliumCallerMemoryWriterUnmaterialize.incoming_tag wordCells tagCells le base

/-- The actual final tag store preserves the concrete data word and payload. -/
theorem data_values {m before : CC.Mem} {header : Storage m} {base original : BitVec 64}
    (word : Arm64CiliumCallerMemoryWriterWord.Store (before := before) header base)
    (payload : Arm64CiliumCallerMemoryWriterPayload.Store (before := word.after) header)
    (tag : Arm64CiliumCallerMemoryWriterTag.Store (before := payload.after) header original) :
    CC.Mem.load .Mint64 tag.after (header.block 0) 0 = some (.Vlong base) ∧
    CC.Mem.load .Mint64 tag.after (header.block 1) 0 = some (.Vlong (0#64)) := by
  constructor
  · exact (Arm64CiliumCallerMemoryWriterTag.bound_frame tag (header.binding 0)
      (by decide +kernel) .Mint64 0).trans (Arm64CiliumCallerMemoryWriterPayload.word_value word payload)
  · exact (Arm64CiliumCallerMemoryWriterTag.bound_frame tag (header.binding 1)
      (by decide +kernel) .Mint64 0).trans payload.read

/-- Compose the actual164-step cache/word prefix, real payload store and
the complete original tag loop. All three concrete stores are retained. -/
theorem from_payload {m supplied : CC.Mem} {locals : Arm64CiliumCallerDefaults.Locals m}
    {base original : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (tags : Arm64CiliumCallerTables.Table true m)
    (wordCells : Arm64CiliumCallerInitializers.Cells false m)
    (tagCells : Arm64CiliumCallerInitializers.Cells true m)
    (access : supplied.access = (allocation m).2.access)
    (spRead : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 = some (.Vlong Arm64CiliumCallerSPPreindex.delta))
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
            CC.E0 (.State procedure .Sskip
              (Arm64CiliumCallerMemoryWriterAddress.continuation
                (Arm64CiliumCallerMemoryWriterPrefix.continuation k)) (allocation m).1
              (Arm64CiliumCallerMemoryWriterTag.resultEnv header
                (inputEnv (Arm64CiliumCallerMemoryWriterUnmaterialize.resultEnv
                  (Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv wordCells tagCells le base) base))
                original) tagsWritten.after) := by
  obtain ⟨word,payload,prefixRun⟩ := Arm64CiliumCallerMemoryWriterPayload.from_word cache header scalars
    tags wordCells tagCells access spRead abi slot tag le width k
  have permissions := payload.access.trans (word.access.trans (cache.access.trans access))
  have read := Arm64CiliumCallerMemoryWriterTag.current_read cache header word payload current
  obtain ⟨tagsWritten,written⟩ := advance header
    (Arm64CiliumCallerMemoryWriterUnmaterialize.resultEnv
      (Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv wordCells tagCells le base) base)
    original permissions (Arm64CiliumCallerMemoryWriterPayload.incoming_index wordCells tagCells le base)
    (incoming_tag wordCells tagCells le base) read
    (Arm64CiliumCallerMemoryWriterAddress.continuation (Arm64CiliumCallerMemoryWriterPrefix.continuation k))
  refine ⟨word,payload,tagsWritten,?_⟩
  simpa only [CC.Eapp,CC.E0,List.nil_append] using star_trans prefixRun written

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTagLoop
