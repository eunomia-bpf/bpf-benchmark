import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopSequence

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopEntry
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation LRLocal)
open Arm64CiliumCallerContext (ABI)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table tableName)
open Arm64CiliumCallerInitializers (Cells lastCell)
open Arm64CiliumCallerGPRSource (declaration)
open Arm64CiliumCallerGPRFrames (localRead)
open Arm64CiliumCallerGPRSequence (Outcomes finalTemps)
open Arm64CiliumCallerVectorSource (Storage)
open Arm64CiliumCallerStackTags (StackTagLocal)
open Arm64CiliumCallerContextEntry (CurrentGPR defaultValue)
open Arm64CiliumCallerHeaderSource (Header Sources)

open Arm64CiliumCallerHeaderEntry (observers_outside bound_frame local_frame)

/-- Same original whole entry followed once by the complete vector pointer loop. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (inputs : Fin 30 → BitVec 64) (outcomes : Outcomes m inputs)
    (flagInputs : Fin 4 → BitVec 64)
    (flagOutcomes : Arm64CiliumCallerFlagSequence.Outcomes m flagInputs)
    (vectors : Storage m) (vectorInputs : Fin 64 → BitVec 64)
    (vectorOutcomes : Arm64CiliumCallerVectorSequence.Outcomes vectors vectorInputs) (k : CC.Cont) :
    ∃ tailLocals : Arm64CiliumCallerHeaderTailValues.Storage m,∃ header : Arm64CiliumCallerHeaderSource.Header m,∃ sources : Arm64CiliumCallerHeaderSource.Sources m,∃ updates : Arm64CiliumCallerContextGPR.Storage m,∃ resource : Arm64CiliumCallerABIBase.Storage m,∃ helper : Arm64CiliumCallerHelperSetup.Storage m,∃ scalars : Arm64CiliumCallerEntryScalars.Locals m,∃ stackTags : StackTagLocal m,∃ lr : LRLocal m,∃ words : Table false m,∃ tags : Table true m,
    ∃ wordCells : Cells false m,∃ tagCells : Cells true m,∃ locals : Locals m,
    ∃ traceFirst traceSecond traceGPR traceFlags traceVectors finalMem finalLe,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR) traceFlags) traceVectors)
        (.State procedure Arm64CiliumCallerVectorPointerLoopSource.after k (allocation m).1 finalLe finalMem) ∧
      finalLe.get _i = some (.Vint (32#32)) ∧
      (∀ id,id ≠ _i → finalLe.get id = ((Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
            (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
            (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets))))).get id) ∧
      Arm64CiliumCallerVectorPointerLoopSequence.Initialized header vectors finalMem 32 ∧
      Arm64CiliumCallerHeaderTailSequence.Initialized header tailLocals finalMem 16 ∧
      Arm64CiliumCallerHeaderSequence.Initialized header sources finalMem 12 ∧
      CC.Mem.load .Mint64 finalMem resource.block 0 = some (.Vptr abi.block 0) ∧
      CC.Mem.load .Mint64 finalMem helper.block 0 = some (.Vptr ctx ctxOfs) ∧
      (∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i) finalMem (scalars.block i) 0 =
        some (Arm64CiliumCallerEntryScalars.value i)) ∧
      (∀ i : Fin 8,CC.Mem.load .Mint8unsigned finalMem stackTags.block (i.val : Int) = some (.Vint 0)) ∧
      Arm64CiliumCallerVectorSequence.Initialized vectors finalMem vectorInputs 64 ∧
      CC.Mem.load .Mint64 finalMem lr.block 0 = some (.Vlong (0#64)) ∧
      Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 ∧
      CurrentGPR m finalMem ctx ctxOfs inputs ∧
      (∀ i,CC.Mem.load .Mint64 finalMem words.block (8*(i.val : Int)) =
        some (.Vptr (wordCells.block i) 0)) ∧
      (∀ i,CC.Mem.load .Mint64 finalMem tags.block (8*(i.val : Int)) =
        some (.Vptr (tagCells.block i) 0)) ∧
      Nonempty (Arm64CiliumCallerTableWrites.Initialized false m finalMem words (lastCell false wordCells)) ∧
      Nonempty (Arm64CiliumCallerTableWrites.Initialized true m finalMem tags (lastCell true tagCells)) ∧
      CC.Mem.load .Mint64 finalMem abi.block 0 = some (.Vptr (results false) (resultOffsets false)) ∧
      CC.Mem.load .Mint64 finalMem abi.block 8 = some (.Vptr (results true) (resultOffsets true)) ∧
      (∀ i,CC.Mem.load .Mint32 finalMem abi.block (Arm64CiliumCallerCB.offset i) = some (.Vint (0#32))) ∧
      (∀ i,CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) finalMem (locals.block i) 0 =
        some (defaultValue ctx ctxOfs abi.block i)) ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨tailLocals,header,sources,updates,resource,helper,scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,
      traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,beforeLoop,firstRun,oldTailReads,_,oldHeaderReads,
      baseRead,helperRead,scalarReads,stackReads,vectorReads,lrRead,flags,gprs,wordReads,tagReads,
      ⟨wordEntry⟩,⟨tagEntry⟩,dataRead,endRead,cbReads,defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerHeaderTailEntry.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes
      flagInputs flagOutcomes vectors vectorInputs vectorOutcomes k
  let temps := Arm64CiliumCallerHelperSetup.entryTemps ctx ctxOfs results resultOffsets inputs flagInputs vectorInputs
  obtain ⟨finalMem,finalLe,headerRun,finalIndex,tempsKept,vectorPointers,fixedFields,tailFields,blocks,
      headerFrame,headerAccess,headerNext⟩ :=
    Arm64CiliumCallerVectorPointerLoopSequence.execute header vectors temps k firstAccess
  have headerReads : Arm64CiliumCallerHeaderSequence.Initialized header sources finalMem 12 :=
    fun i below => (fixedFields i).trans (oldHeaderReads i below)
  have tailReads : Arm64CiliumCallerHeaderTailSequence.Initialized header tailLocals finalMem 16 :=
    fun i below => (tailFields i).trans (oldTailReads i below)
  rcases observers_outside with
    ⟨gprNames,abiName,defaultNames,tableNames,flagNames,lrName,vectorName,stackName,scalarNames,helperName,baseName⟩
  have abiBaseFrame := bound_frame header blocks resource.binding baseName
  have helperFrame := bound_frame header blocks helper.binding helperName
  have wordFrame := bound_frame header blocks words.binding (tableNames false)
  have tagFrame := bound_frame header blocks tags.binding (tableNames true)
  have abiFrame := bound_frame header blocks abi.binding abiName
  have lrFrame := bound_frame header blocks lr.binding lrName
  have vectorFrame := bound_frame header blocks vectors.binding vectorName
  have stackFrame := bound_frame header blocks stackTags.binding stackName
  have scalarFrame (i : Fin 2) := bound_frame header blocks (scalars.binding i) (scalarNames i)
  have gprReads : CurrentGPR m finalMem ctx ctxOfs inputs := by
    constructor
    · intro i
      exact (local_frame header blocks _ (gprNames i).1 .Mint64 0).trans (gprs.word i)
    · intro i
      exact (local_frame header blocks _ (gprNames i).2 .Mint8unsigned 0).trans (gprs.tag i)
  have flagReads : Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 := by
    intro i below
    exact (local_frame header blocks _ (flagNames i) .Mint8unsigned 0).trans (flags i below)
  have currentDefaults (i : Fin 9) :
      CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) finalMem (locals.block i) 0 =
        some (defaultValue ctx ctxOfs abi.block i) :=
    (bound_frame header blocks (locals.binding i) (defaultNames i) _ 0).trans (defaultReads i)
  refine ⟨tailLocals,header,sources,updates,resource,helper,scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,
    traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,finalMem,finalLe,?_,finalIndex,?_,vectorPointers,tailReads,headerReads,
    (abiBaseFrame .Mint64 0).trans baseRead,(helperFrame .Mint64 0).trans helperRead,
    (fun i => (scalarFrame i _ 0).trans (scalarReads i)),
    (fun i => (stackFrame .Mint8unsigned _).trans (stackReads i)),
    (fun i below => (vectorFrame .Mint64 _).trans (vectorReads i below)),
    (lrFrame .Mint64 0).trans lrRead,flagReads,gprReads,
    (fun i => (wordFrame .Mint64 _).trans (wordReads i)),
    (fun i => (tagFrame .Mint64 _).trans (tagReads i)),
    ⟨Arm64CiliumCallerFlagEntry.table_frame wordEntry wordFrame⟩,
    ⟨Arm64CiliumCallerFlagEntry.table_frame tagEntry tagFrame⟩,
    (abiFrame .Mint64 0).trans dataRead,(abiFrame .Mint64 8).trans endRead,
    (fun i => (abiFrame .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    currentDefaults,firstFrame.trans headerFrame,
    headerAccess.trans firstAccess,headerNext.trans firstNext⟩
  · simpa only [temps,Arm64CiliumCallerHelperSetup.entryTemps,CC.E0,CC.Eapp,List.append_nil] using
      star_trans firstRun headerRun.sound
  · simpa only [temps,Arm64CiliumCallerHelperSetup.entryTemps] using tempsKept

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopEntry
