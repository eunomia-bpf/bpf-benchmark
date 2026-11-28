import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTail

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterOutcomes
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerHeaderTailValues (Storage)
open Arm64CiliumCallerEntryScalars (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerSPPreindex (delta)

/-- The same original SP/R30 prefix and actual external outcome feed all three
writer stores and reach the original caller rest, retaining the provider trace.
Post-provider resources are explicit: no heap purity or successful provider is
inferred from the caller's initial memory. -/
theorem outcomes {m before : CC.Mem} (header : Header m) (sources : Sources m)
    (storage : Storage m) (scalars : Locals m)
    (words : Table false m) (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64)
    (slots : ∀ i : Fin 31, CC.Mem.load .Mint64 before words.block (8*(i.val : Int)) =
      some (.Vptr (wordCells.block i) 0))
    (tagSlots : ∀ i : Fin 31, CC.Mem.load .Mint64 before tags.block (8*(i.val : Int)) =
      some (.Vptr (tagCells.block i) 0))
    (current : Arm64CiliumCallerContextEntry.CurrentGPR m before ctx ctxOfs inputs)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2, CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (locals : Arm64CiliumCallerDefaults.Locals m)
    (zero : CC.Mem.load .Mint8unsigned before (locals.block 5) 0 = some (.Vint (0#32)))
    (le : CC.TempEnv) (width : le.get ___a64_l_width = some (.Vint (8#32))) (k : CC.Cont) :
    ∃ spResult : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      Arm64EntryMemory.borrowed spResult.after.nextblock .Mint64 spResult.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong delta) ∧
      ∀ (base original : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
          [.Vint (3#32)] spResult.after trace (.Vlong base) supplied →
        supplied.access = (allocation m).2.access →
        CC.Mem.load .Mint64 supplied (scalars.block 0) 0 = some (.Vlong delta) →
        CC.Mem.load .Mint8unsigned supplied (storage.block 6) 0 = some (.Vint (1#32)) →
        CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0) →
        CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)) →
        CC.Mem.load .Mint64 supplied (storage.block 2) 0 = some (.Vlong original) →
        ∃ cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base,
          ∃ word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) storage base,
            ∃ payload : Arm64CiliumCallerMemoryWriterPayload.Store (before := word.after) storage,
              ∃ tag : Arm64CiliumCallerMemoryWriterTag.Store (before := payload.after) storage original,
                CC.Star (CC.Step2 ge)
                  (.State procedure Arm64CiliumCallerSPAlignment.tail
                    (.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak
                      (.Kseq Arm64CiliumCallerMemOffsetPrefix.stage k)) (allocation m).1 le before)
                  trace (.State procedure Arm64CiliumCallerMemoryWriterPrefix.rest k (allocation m).1
                    (Arm64CiliumCallerMemoryWriterTail.resultEnv
                      (Arm64CiliumCallerMemoryWriterTail.incomingEnv storage wordCells tagCells le base original))
                    tag.after) ∧
                CC.Mem.load .Mint64 tag.after (storage.block 0) 0 = some (.Vlong base) ∧
                CC.Mem.load .Mint64 tag.after (storage.block 1) 0 = some (.Vlong (0#64)) ∧
                CC.Mem.load .Mint64 tag.after (storage.block 2) 0 =
                  some (.Vlong (Arm64CiliumCallerMemoryWriterTag.updated original)) ∧
                CC.Mem.load .Mint64 tag.after (scalars.block 0) 0 = some (.Vlong delta) := by
  obtain ⟨spResult,spRead,returned⟩ := Arm64CiliumCallerReturnOutcomes.outcomes
    header sources scalars words tags wordCells tagCells ctx ctxOfs inputs slots tagSlots
    current access pointers reads locals zero le k
  refine ⟨spResult,spRead,?_⟩
  intro base original trace supplied provider suppliedAccess suppliedSP abi slot suppliedTag tagword
  obtain ⟨cache,prefixRun,_⟩ := returned base trace supplied provider suppliedAccess
  obtain ⟨word,payload,tag,writerRun⟩ := Arm64CiliumCallerMemoryWriterTail.advance
    cache storage scalars tags wordCells tagCells suppliedAccess suppliedSP abi slot suppliedTag tagword le width k
  have values := Arm64CiliumCallerMemoryWriterTagLoop.data_values word payload tag
  refine ⟨cache,word,payload,tag,?_,values.1,values.2,tag.read,?_⟩
  · simpa only [CC.Eapp,CC.E0,List.append_nil] using star_trans prefixRun writerRun
  · exact Arm64CiliumCallerMemoryWriterTail.sp_read cache storage scalars word payload tag suppliedSP

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterOutcomes
