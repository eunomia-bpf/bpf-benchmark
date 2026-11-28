import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorSequence

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorEntry
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation LRLocal)
open Arm64CiliumCallerContext (ABI)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table tableName)
open Arm64CiliumCallerInitializers (Cells lastCell)
open Arm64CiliumCallerGPRSource (declaration)
open Arm64CiliumCallerGPRFrames (localRead Initialized)
open Arm64CiliumCallerGPRSequence (Outcomes finalTemps)
open Arm64CiliumCallerVectorSource (Storage)
open Arm64CiliumCallerVectorSequence (Outside)

theorem observers_outside :
    (∀ i : Fin 31,Outside (declaration i).word ∧ Outside (declaration i).tag) ∧
    Outside ___a64_sim_abi ∧
    (∀ i : Fin 9,Outside (Arm64CiliumCallerDefaults.name i)) ∧
    (∀ tags : Bool,Outside (tableName tags)) ∧
    (∀ i : Fin 4,Outside (Arm64CiliumCallerFlags.declaration i).name) ∧
    Outside ___a64_lr := by
  unfold Outside
  decide +kernel

theorem bound_frame {m before after : CC.Mem}
    (locals : ∀ id,Outside id → ∀ c o,
      localRead m after id c o = localRead m before id c o)
    {id : CC.Ident} {ty : CC.Ty} {b : CC.Block}
    (binding : (allocation m).1.get id = some (b,ty)) (outside : Outside id) :
    ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o := by
  intro c o
  simpa only [localRead,binding,Option.bind_some] using locals id outside c o

/-- SAME original function entry through all64vector inputs,retaining all
earlier observers and the original table initializer execution resources. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (inputs : Fin 30 → BitVec 64) (outcomes : Outcomes m inputs)
    (flagInputs : Fin 4 → BitVec 64)
    (flagOutcomes : Arm64CiliumCallerFlagSequence.Outcomes m flagInputs)
    (vectors : Storage m) (vectorInputs : Fin 64 → BitVec 64)
    (vectorOutcomes : Arm64CiliumCallerVectorSequence.Outcomes vectors vectorInputs) (k : CC.Cont) :
    ∃ lr : LRLocal m,∃ words : Table false m,∃ tags : Table true m,
    ∃ wordCells : Cells false m,∃ tagCells : Cells true m,∃ locals : Locals m,
    ∃ traceFirst traceSecond traceGPR traceFlags traceVectors finalMem,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR) traceFlags) traceVectors)
        (.State procedure Arm64CiliumCallerVectorSource.after k (allocation m).1
          (Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
            (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
            (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)))) finalMem) ∧
      Arm64CiliumCallerVectorSequence.Initialized vectors finalMem vectorInputs 64 ∧
      CC.Mem.load .Mint64 finalMem lr.block 0 = some (.Vlong (0#64)) ∧
      Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 ∧
      Initialized m finalMem inputs 31 ∧
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
        some (Arm64CiliumCallerDefaults.value i)) ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,beforeVectors,
      firstRun,lrRead,flags,gprs,wordReads,tagReads,⟨wordEntry⟩,⟨tagEntry⟩,dataRead,endRead,cbReads,
      defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerLR.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes
      flagInputs flagOutcomes k
  let temps := Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
    (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets))
  obtain ⟨traceVectors,finalMem,vectorRun,vectorReads,vectorAccess,vectorNext,vectorFrame,localFrames⟩ :=
    Arm64CiliumCallerVectorSequence.execute vectors vectorInputs vectorOutcomes firstAccess temps k
  have wordFrame := bound_frame localFrames words.binding (observers_outside.2.2.2.1 false)
  have tagFrame := bound_frame localFrames tags.binding (observers_outside.2.2.2.1 true)
  have abiFrame := bound_frame localFrames abi.binding observers_outside.2.1
  have lrFrame := bound_frame localFrames lr.binding observers_outside.2.2.2.2.2
  have gprReads : Initialized m finalMem inputs 31 := by
    constructor
    · intro i below
      exact (localFrames _ (observers_outside.1 i).1 .Mint64 0).trans (gprs.word i below)
    · intro i below
      exact (localFrames _ (observers_outside.1 i).2 .Mint8unsigned 0).trans (gprs.tag i below)
  have flagReads : Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 := by
    intro i below
    exact (localFrames _ (observers_outside.2.2.2.2.1 i) .Mint8unsigned 0).trans (flags i below)
  have defaultFrame (i : Fin 9) :=
    bound_frame localFrames (locals.binding i) (observers_outside.2.2.1 i)
      (Arm64CiliumCallerDefaults.chunk i) 0
  refine ⟨lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,
    finalMem,?_,vectorReads,(lrFrame .Mint64 0).trans lrRead,flagReads,gprReads,
    (fun i => (wordFrame .Mint64 _).trans (wordReads i)),
    (fun i => (tagFrame .Mint64 _).trans (tagReads i)),
    ⟨Arm64CiliumCallerFlagEntry.table_frame wordEntry wordFrame⟩,
    ⟨Arm64CiliumCallerFlagEntry.table_frame tagEntry tagFrame⟩,
    (abiFrame .Mint64 0).trans dataRead,(abiFrame .Mint64 8).trans endRead,
    (fun i => (abiFrame .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    (fun i => (defaultFrame i).trans (defaultReads i)),firstFrame.trans vectorFrame,
    vectorAccess.trans firstAccess,vectorNext.trans firstNext⟩
  simpa only [temps] using star_trans firstRun vectorRun

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorEntry
