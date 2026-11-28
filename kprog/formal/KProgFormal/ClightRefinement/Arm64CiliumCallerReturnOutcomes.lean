import KProgFormal.ClightRefinement.Arm64CiliumCallerReturnMaterialize

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerReturnOutcomes
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)

noncomputable def resultEnv (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  Arm64CiliumCallerReturnMaterialize.resultEnv
    (Arm64CiliumCallerReturnMemory.resultEnv (Arm64CiliumCallerReturnProvider.resultEnv le) base) base

theorem values (le : CC.TempEnv) (base : BitVec 64) :
    (resultEnv le base).get ___a64_store_value = some (.Vlong base) ∧
    (resultEnv le base).get ___a64_mat_value__1 = some (.Vlong base) :=
  Arm64CiliumCallerReturnMaterialize.values
    (Arm64CiliumCallerReturnMemory.resultEnv (Arm64CiliumCallerReturnProvider.resultEnv le) base) base

/-- Resume every admitted actual linked-world provider outcome, retaining its
complete trace and supplied heap. No existence, purity or determinism is assumed. -/
theorem provider_returns {m before supplied : CC.Mem}
    (locals : Arm64CiliumCallerDefaults.Locals m) (base : BitVec 64)
    (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (3#32)] before trace (.Vlong base) supplied)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base,
      CC.Star (CC.Step2 ge)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (3#32)]
          (.Kcall (some _t'157) procedure (allocation m).1 (Arm64CiliumCallerReturnProvider.resultEnv le)
            (Arm64CiliumCallerReturnProvider.continuation k)) before)
        trace (.State procedure .Sskip k (allocation m).1 (resultEnv le base) result.after) ∧
      (resultEnv le base).get ___a64_store_value = some (.Vlong base) := by
  obtain ⟨result,suffix⟩ :=
    Arm64CiliumCallerReturnMaterialize.write_and_advance locals base access le k
  have external : CC.Step2 ge
      (.Callstate Arm64OriginCache.inputFunction [.Vint (3#32)]
        (.Kcall (some _t'157) procedure (allocation m).1 (Arm64CiliumCallerReturnProvider.resultEnv le)
          (Arm64CiliumCallerReturnProvider.continuation k)) before)
      trace (.Returnstate (.Vlong base)
        (.Kcall (some _t'157) procedure (allocation m).1 (Arm64CiliumCallerReturnProvider.resultEnv le)
          (Arm64CiliumCallerReturnProvider.continuation k)) supplied) := by
    apply CC.Step.external_function
    exact provider
  refine ⟨result,?_,(values le base).1⟩
  exact .step _ _ _ _ _ _ external suffix.sound (by simp only [CC.Eapp,CC.E0,List.append_nil])

noncomputable def reachedEnv {m : CC.Mem}
    (wordCells : Cells false m) (tagCells : Cells true m) (le : CC.TempEnv) : CC.TempEnv :=
  Arm64CiliumCallerR30Tag.resultEnv tagCells
    (Arm64CiliumCallerR30Word.resultEnv wordCells
      (Arm64CiliumCallerMemOffset.resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le)))

noncomputable def groupCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 (.Ssequence Arm64CiliumCallerR30Word.reader Arm64CiliumCallerR30Word.afterWord)
    .Sbreak (.Kseq Arm64CiliumCallerR30Word.rest k)

/-- Derive the actual202-step reached call once, then quantify over its actual external outcomes. -/
theorem outcomes {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (words : Table false m) (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (slots : ∀ i : Fin 31,CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (tagSlots : ∀ i : Fin 31,CC.Mem.load .Mint64 before tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : Arm64CiliumCallerContextEntry.CurrentGPR m before ctx ctxOfs inputs)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (locals : Arm64CiliumCallerDefaults.Locals m)
    (zero : CC.Mem.load .Mint8unsigned before (locals.block 5) 0 = some (.Vint (0#32)))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ spResult : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      Arm64EntryMemory.borrowed spResult.after.nextblock .Mint64 spResult.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) ∧
      ∀ (base : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
          [.Vint (3#32)] spResult.after trace (.Vlong base) supplied →
        supplied.access = (allocation m).2.access →
        ∃ cacheResult : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base,
          CC.Star (CC.Step2 ge)
            (.State procedure Arm64CiliumCallerSPAlignment.tail
              (.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak
                (.Kseq Arm64CiliumCallerMemOffsetPrefix.stage k)) (allocation m).1 le before)
            trace (.State procedure .Sskip (groupCont k) (allocation m).1
              (resultEnv (reachedEnv wordCells tagCells le) base) cacheResult.after) ∧
          (resultEnv (reachedEnv wordCells tagCells le) base).get ___a64_store_value =
            some (.Vlong base) := by
  obtain ⟨spResult,prefixRun,spRead⟩ := Arm64CiliumCallerReturnProvider.advance
    header sources scalars words tags wordCells tagCells ctx ctxOfs inputs slots tagSlots
      current access pointers reads locals zero le k
  refine ⟨spResult,spRead,?_⟩
  intro base trace supplied provider suppliedAccess
  obtain ⟨cacheResult,returned,value⟩ := provider_returns locals base trace provider suppliedAccess
    (reachedEnv wordCells tagCells le) (groupCont k)
  refine ⟨cacheResult,?_,value⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans prefixRun.sound returned

end KProgFormal.ClightRefinement.Arm64CiliumCallerReturnOutcomes
