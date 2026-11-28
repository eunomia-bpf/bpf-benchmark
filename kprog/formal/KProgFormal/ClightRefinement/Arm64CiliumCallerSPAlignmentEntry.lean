import KProgFormal.ClightRefinement.Arm64CiliumCallerSPAlignment

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerSPAlignmentEntry
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


open Arm64CiliumCallerReaderEntry (Reads)

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv :=
  Arm64CiliumCallerSPAlignment.resultEnv
    (Arm64CiliumCallerOperandGuard.resultEnv (Arm64CiliumCallerWidthPrefix.resultEnv le))

noncomputable def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak
    (.Kseq Arm64CiliumCallerSPAlignment.afterGroup
      (.Kloop1 s_trusted_arm64_arm64_sim_xdp_150 s_trusted_arm64_arm64_sim_xdp_151
        (.Kloop1 Arm64CiliumCallerWidthPrefix.body .Sbreak
          (.Kseq Arm64CiliumCallerWidthPrefix.rest k))))

/-- Only the six actual width/operand/alignment temporaries may change. -/
theorem temp_frame (le : CC.TempEnv) :
    (resultEnv le).get _i = le.get _i ∧
    ∀ id,id ≠ _t'133 → id ≠ ___a64_l_width → id ≠ _t'134 → id ≠ _t'135 →
      id ≠ _t'13901 → id ≠ _t'136 → (resultEnv le).get id = le.get id := by
  have names : _t'133 ≠ _i ∧ ___a64_l_width ≠ _i ∧ _t'134 ≠ _i ∧
      _t'135 ≠ _i ∧ _t'13901 ≠ _i ∧ _t'136 ≠ _i := by decide +kernel
  rcases names with ⟨a,b,c,d,e,f⟩
  constructor
  · simp [resultEnv,Arm64CiliumCallerWidthPrefix.resultEnv,Arm64CiliumCallerOperandGuard.resultEnv,
      Arm64CiliumCallerSPAlignment.resultEnv,CC.PTree.gso,a,b,c,d,e,f]
  · intro id h1 h2 h3 h4 h5 h6
    simp [resultEnv,Arm64CiliumCallerWidthPrefix.resultEnv,Arm64CiliumCallerOperandGuard.resultEnv,
      Arm64CiliumCallerSPAlignment.resultEnv,CC.PTree.gso,
      Ne.symm h1,Ne.symm h2,Ne.symm h3,Ne.symm h4,Ne.symm h5,Ne.symm h6]

/-- The same entry and original operand/SP guards, each executed once on one heap. -/
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
    ∃ traceFirst traceSecond traceGPR traceFlags traceVectors finalMem beforeWidthLe,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR) traceFlags) traceVectors)
        (.State procedure Arm64CiliumCallerSPAlignment.tail (continuation k)
          (allocation m).1 (resultEnv beforeWidthLe) finalMem) ∧
      beforeWidthLe.get _i = some (.Vint (32#32)) ∧
      (∀ id,id ≠ _i → beforeWidthLe.get id = ((Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
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
      (Arm64CiliumCallerWidthPrefix.resultEnv beforeWidthLe).get _i = some (.Vint (32#32)) ∧
      (∀ id,id ≠ _t'133 → id ≠ ___a64_l_width →
        (Arm64CiliumCallerWidthPrefix.resultEnv beforeWidthLe).get id = beforeWidthLe.get id) ∧
      (resultEnv beforeWidthLe).get _i = some (.Vint (32#32)) ∧
      (∀ id,id ≠ _t'133 → id ≠ ___a64_l_width → id ≠ _t'134 → id ≠ _t'135 →
        id ≠ _t'13901 → id ≠ _t'136 → (resultEnv beforeWidthLe).get id = beforeWidthLe.get id) ∧
      Reads finalMem header.block ctx ctxOfs inputs flagInputs vectorInputs ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨tailLocals,header,sources,updates,resource,helper,scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,
      traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,finalMem,beforeWidthLe,run,finalIndex,temps,
      vectorPointers,tailReads,headerReads,baseRead,helperRead,scalarReads,stackReads,vectorReads,
      lrRead,flags,gprs,wordReads,tagReads,wordEntry,tagEntry,dataRead,endRead,cbReads,defaultReads,
      widthIndex,widthTemps,reads,frame,access,next⟩ :=
    Arm64CiliumCallerWidthEntry.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes
      flagInputs flagOutcomes vectors vectorInputs vectorOutcomes k
  let widthEnv := Arm64CiliumCallerWidthPrefix.resultEnv beforeWidthLe
  let widthK := CC.Cont.Kloop1 Arm64CiliumCallerWidthPrefix.body .Sbreak
    (.Kseq Arm64CiliumCallerWidthPrefix.rest k)
  let operandK := CC.Cont.Kloop1 s_trusted_arm64_arm64_sim_xdp_150 s_trusted_arm64_arm64_sim_xdp_151 widthK
  have operandRun := Arm64CiliumCallerOperandGuard.execute (allocation m).1 widthEnv finalMem widthK
  have alignmentRun := Arm64CiliumCallerSPAlignment.execute scalars scalarReads
    (Arm64CiliumCallerOperandGuard.resultEnv widthEnv) operandK
  refine ⟨tailLocals,header,sources,updates,resource,helper,scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,
    traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,finalMem,beforeWidthLe,?_,finalIndex,temps,
    vectorPointers,tailReads,headerReads,baseRead,helperRead,scalarReads,stackReads,vectorReads,
    lrRead,flags,gprs,wordReads,tagReads,wordEntry,tagEntry,dataRead,endRead,cbReads,defaultReads,
    widthIndex,widthTemps,(temp_frame beforeWidthLe).1.trans finalIndex,(temp_frame beforeWidthLe).2,
    reads,frame,access,next⟩
  simpa only [CC.Eapp,CC.E0,List.append_nil,continuation,resultEnv,operandK,widthK,widthEnv] using
    star_trans (star_trans run operandRun.sound) alignmentRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerSPAlignmentEntry
