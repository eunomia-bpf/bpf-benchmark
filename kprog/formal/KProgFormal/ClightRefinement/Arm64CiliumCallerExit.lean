import KProgFormal.ClightRefinement.Arm64CiliumCallerTableWrites

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerExit
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation token)
open Arm64CiliumCallerTables
open Arm64CiliumCallerTableWrites (Initialized)

/-- The actual reg30 branch has literal30==32,so it skips stack release.
Both original do-while loop continuations are then discharged. -/
theorem finish (m : CC.Mem) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 6
      (.State procedure .Sskip
        (.Kseq Arm64CiliumCallerWriterGuard.afterStores
          (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k)))
        e le m)
      (.State procedure .Sskip k e le m) := by
  have condition : CC.doEvalExpr ge e le m
      (.Ebinop .Oeq (.Econst_int (CC.Integers.Int.repr 30) CC.tuint)
        (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) =
      some (.Vint (0#32)) := rfl
  have run : steps ge 6
      (.State procedure .Sskip
        (.Kseq Arm64CiliumCallerWriterGuard.afterStores
          (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k)))
        e le m) = some (CC.E0,.State procedure .Sskip k e le m) := by
    simp only [steps,CC.doStep,Arm64CiliumCallerWriterGuard.afterStores,condition,
      Arm64CiliumCallerWriter.continuation,Arm64CiliumCallerWriter.outerContinuation]
    rfl
  have path : InternalPath ge 6
      (.State procedure .Sskip
        (.Kseq Arm64CiliumCallerWriterGuard.afterStores
          (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k)))
        e le m) := by
    simp [InternalPath,InternalState,CC.doStep,Arm64CiliumCallerWriterGuard.afterStores,
      condition,Arm64CiliumCallerWriter.continuation,Arm64CiliumCallerWriter.outerContinuation]
    trivial
  exact internalRun_of_steps path run

noncomputable def finalTemps (le : CC.TempEnv) (oldSP : CC.Val)
    (word tag : CC.Block) : CC.TempEnv :=
  ((Arm64CiliumCallerWriterGuard.temps (le.set ___a64_write_old_sp oldSP)).set
    _t'12900 (.Vptr word 0)).set _t'12899 (.Vptr tag 0)

/-- One original inline LINK invocation executes once from a heap carrying
its two genuine initialization resources. It stores LR/raw88 and X30/raw88,
writes CODE9,then returns through both original loops to the supplied caller.
Reaching this site with these resources remains a separate prefix obligation. -/
theorem execute {m before : CC.Mem} (words : Table false m) (tags : Table true m)
    (word : Cell false m) (tag : Cell true m)
    (wordEntry : Initialized false m before words word)
    (tagEntry : Initialized true m before tags tag)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ lr : Arm64CiliumCallerLink.LRLocal m, ∃ afterLR afterWord after spBlock oldSP,
      InternalRun ge 51
        (.State procedure Arm64CiliumCallerLink.site k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1 (finalTemps le oldSP word.block tag.block) after) ∧
      CC.Mem.store .Mint64 before lr.block 0 (.Vlong token) = some afterLR ∧
      CC.Mem.store .Mint64 afterLR word.block 0 (.Vlong token) = some afterWord ∧
      CC.Mem.store .Mint8unsigned afterWord tag.block 0 (.Vint (9#32)) = some after ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token) ∧
      CC.Mem.load .Mint64 after word.block 0 = some (.Vlong token) ∧
      CC.Mem.load .Mint8unsigned after tag.block 0 = some (.Vint (9#32)) ∧
      (allocation m).1.get ___a64_sp = some (spBlock,CC.tlong) ∧
      CC.Mem.load .Mint64 afterLR spBlock 0 = some oldSP ∧
      Nonempty (Initialized false m after words word) ∧
      Nonempty (Initialized true m after tags tag) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨lr⟩ := Arm64CiliumCallerLink.lr_local m
  have live : CC.Mem.rangePerm before lr.block 0 8 .Cur .Freeable = true := by
    rw [CC.Mem.rangePerm_congr (m2 := (allocation m).2)
      (fun _ => by simp only [CC.Mem.perm,access])]
    exact lr.live
  obtain ⟨afterLR,lrRun,lrStore,lrRead,lrFrame,lrAccess,lrNext⟩ :=
    Arm64CiliumCallerLink.begin_link lr le k live
  have accessLR := lrAccess.trans access
  obtain ⟨spBlock,spBinding,spLive⟩ := Arm64CiliumCallerWriter.sp_local m
  have readable : CC.Mem.validAccess afterLR .Mint64 spBlock 0 .Readable = true := by
    change (CC.Mem.rangePerm afterLR spBlock 0 8 .Cur .Readable && true) = true
    have permission := CC.Mem.rangePerm_implies spLive
      (by decide : CC.permOrder .Freeable .Readable = true)
    rw [CC.Mem.rangePerm_congr (m2 := (allocation m).2)
      (fun _ => by simp only [CC.Mem.perm,accessLR])]
    rw [permission]
    rfl
  obtain ⟨oldSP,spRead⟩ : ∃ v,CC.Mem.load .Mint64 afterLR spBlock 0 = some v := by
    simp only [CC.Mem.load,readable,ite_true]
    exact ⟨_,rfl⟩
  have spRun := Arm64CiliumCallerWriter.read_sp spBlock oldSP spBinding spRead le
    (Arm64CiliumCallerWriter.outerContinuation k)
  have setup := Arm64CiliumCallerWriterPrefix.execute_stored lr lrStore
    (le.set ___a64_write_old_sp oldSP)
    (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k))
  have guard := Arm64CiliumCallerWriterGuard.execute afterLR (allocation m).1
    (le.set ___a64_write_old_sp oldSP)
    (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k))
  have tableLR (which : Bool) (table : Table which m) : table.block ≠ lr.block := by
    apply (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ table.binding lr.binding
    cases which <;> decide +kernel
  have wordEntryLR := wordEntry.after_store lrStore (tableLR false words)
  have tagEntryLR := tagEntry.after_store lrStore (tableLR true tags)
  obtain ⟨afterWord,after,writes,wordStore,tagStore,wordRead,tagRead,wordFinal,tagFinal,
      writeFrame,writeAccess,writeNext⟩ :=
    Arm64CiliumCallerTableWrites.execute words tags word tag wordEntryLR tagEntryLR accessLR
      (le.set ___a64_write_old_sp oldSP)
      (.Kseq Arm64CiliumCallerWriterGuard.afterStores
        (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k)))
  have wordLR : lr.block ≠ word.block := by
    apply (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ lr.binding word.binding
    decide +kernel
  have tagLR : lr.block ≠ tag.block := by
    apply (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ lr.binding tag.binding
    decide +kernel
  have lrFinal : CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token) :=
    (CC.Mem.load_store_other tagStore .Mint64 lr.block 0 (.inl tagLR)).trans
      ((CC.Mem.load_store_other wordStore .Mint64 lr.block 0 (.inl wordLR)).trans lrRead)
  have last := finish after (allocation m).1 (finalTemps le oldSP word.block tag.block) k
  have run : InternalRun ge 51
      (.State procedure Arm64CiliumCallerLink.site k (allocation m).1 le before)
      (.State procedure .Sskip k (allocation m).1 (finalTemps le oldSP word.block tag.block) after) :=
    ((((lrRun.trans spRun).trans setup).trans guard).trans writes).trans last
  exact ⟨lr,afterLR,afterWord,after,spBlock,oldSP,run,lrStore,wordStore,tagStore,lrFinal,
    wordRead,tagRead,spBinding,spRead,wordFinal,tagFinal,lrFrame.trans writeFrame,
    writeAccess.trans lrAccess,writeNext.trans lrNext⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerExit
