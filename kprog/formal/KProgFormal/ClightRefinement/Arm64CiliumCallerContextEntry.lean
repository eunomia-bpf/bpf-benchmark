import KProgFormal.ClightRefinement.Arm64CiliumCallerContextGPR

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerContextEntry
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
open Arm64CiliumCallerStackTags (StackTagLocal)

def Outside (id : CC.Ident) : Prop := ∀ i : Fin 3,id ≠ Arm64CiliumCallerContextGPR.name i

def defaultValue := Arm64CiliumCallerABIEntry.defaultValue

def wordValue (ctx : CC.Block) (ofs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64) (i : Fin 31) : CC.Val :=
  if i=0 then .Vptr ctx ofs else .Vlong (Arm64CiliumCallerGPRFrames.value inputs i)
def tagValue (i : Fin 31) : CC.Val :=
  .Vint (if i=0 then 1#32 else if i=30 then 10#32 else 0#32)

structure CurrentGPR (m heap : CC.Mem) (ctx : CC.Block) (ofs : CC.Integers.Ptrofs) (inputs : Fin 30 → BitVec 64) : Prop where
  word : ∀ i : Fin 31,localRead m heap (declaration i).word .Mint64 0 = some (wordValue ctx ofs inputs i)
  tag : ∀ i : Fin 31,localRead m heap (declaration i).tag .Mint8unsigned 0 = some (tagValue i)

theorem targets :
    (declaration 0).word = Arm64CiliumCallerContextGPR.name 0 ∧
    (declaration 30).tag = Arm64CiliumCallerContextGPR.name 1 ∧
    (declaration 0).tag = Arm64CiliumCallerContextGPR.name 2 := by
  repeat' constructor
  all_goals rfl

theorem observers_outside :
    ((∀ i : Fin 31,i ≠ 0 → Outside (declaration i).word) ∧
      (∀ i : Fin 31,i ≠ 0 → i ≠ 30 → Outside (declaration i).tag)) ∧
    Outside ___a64_sim_abi ∧
    (∀ i : Fin 9,Outside (Arm64CiliumCallerDefaults.name i)) ∧
    (∀ tags : Bool,Outside (tableName tags)) ∧
    (∀ i : Fin 4,Outside (Arm64CiliumCallerFlags.declaration i).name) ∧
    Outside ___a64_lr ∧ Outside Arm64Entry.___a64_vectors ∧ Outside ___a64_stack_tag ∧
    (∀ i : Fin 2,Outside (Arm64CiliumCallerEntryScalars.name i)) := by
  unfold Outside
  decide +kernel

theorem bound_frame {m before after : CC.Mem} (updates : Arm64CiliumCallerContextGPR.Storage m)
    (blocks : ∀ b,(∀ i : Fin 3,b ≠ updates.block i) → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    {id : CC.Ident} {ty : CC.Ty} {b : CC.Block}
    (binding : (allocation m).1.get id = some (b,ty)) (outside : Outside id) :
    ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o :=
  blocks b (fun i => (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding (updates.binding i) (outside i))

theorem local_frame {m before after : CC.Mem} (updates : Arm64CiliumCallerContextGPR.Storage m)
    (blocks : ∀ b,(∀ i : Fin 3,b ≠ updates.block i) → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    (id : CC.Ident) (outside : Outside id) (c : CC.Chunk) (o : Int) :
    localRead m after id c o = localRead m before id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    simpa only [localRead,binding,Option.bind_some] using bound_frame updates blocks binding outside c o

/-- SAME whole entry followed by actual R0 context pointer and R30/R0 tag writes;
new GPR readbacks reflect the intentional original source updates. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (inputs : Fin 30 → BitVec 64) (outcomes : Outcomes m inputs)
    (flagInputs : Fin 4 → BitVec 64)
    (flagOutcomes : Arm64CiliumCallerFlagSequence.Outcomes m flagInputs)
    (vectors : Storage m) (vectorInputs : Fin 64 → BitVec 64)
    (vectorOutcomes : Arm64CiliumCallerVectorSequence.Outcomes vectors vectorInputs) (k : CC.Cont) :
    ∃ updates : Arm64CiliumCallerContextGPR.Storage m,∃ resource : Arm64CiliumCallerABIBase.Storage m,∃ helper : Arm64CiliumCallerHelperSetup.Storage m,∃ scalars : Arm64CiliumCallerEntryScalars.Locals m,∃ stackTags : StackTagLocal m,∃ lr : LRLocal m,∃ words : Table false m,∃ tags : Table true m,
    ∃ wordCells : Cells false m,∃ tagCells : Cells true m,∃ locals : Locals m,
    ∃ traceFirst traceSecond traceGPR traceFlags traceVectors finalMem,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR) traceFlags) traceVectors)
        (.State procedure Arm64CiliumCallerContextGPR.after k (allocation m).1
          (Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
            (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
            (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)))) finalMem) ∧
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
  obtain ⟨resource,helper,scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,
      traceVectors,beforeUpdates,firstRun,baseRead,helperRead,scalarReads,stackReads,vectorReads,lrRead,flags,gprs,wordReads,tagReads,
      ⟨wordEntry⟩,⟨tagEntry⟩,dataRead,endRead,cbReads,defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerABIEntry.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes
      flagInputs flagOutcomes vectors vectorInputs vectorOutcomes k
  let temps := Arm64CiliumCallerHelperSetup.entryTemps ctx ctxOfs results resultOffsets inputs flagInputs vectorInputs
  obtain ⟨updates⟩ := Arm64CiliumCallerContextGPR.storage m
  obtain ⟨finalMem,gprRun,updateReads,blocks,gprFrame,gprAccess,gprNext⟩ :=
    Arm64CiliumCallerContextGPR.execute updates firstAccess ctx ctxOfs temps k
      (Arm64CiliumCallerHelperSetup.reached_context ctx ctxOfs results resultOffsets inputs flagInputs vectorInputs)
  have abiBaseFrame := bound_frame updates blocks resource.binding
    (by unfold Outside;decide +kernel : Outside ___a64_sim_helper_abi_base)
  have helperFrame := bound_frame updates blocks helper.binding
    (by unfold Outside;decide +kernel : Outside ___a64_sim_helper_ctx)
  have wordFrame := bound_frame updates blocks words.binding (observers_outside.2.2.2.1 false)
  have tagFrame := bound_frame updates blocks tags.binding (observers_outside.2.2.2.1 true)
  have abiFrame := bound_frame updates blocks abi.binding observers_outside.2.1
  have lrFrame := bound_frame updates blocks lr.binding observers_outside.2.2.2.2.2.1
  have vectorFrame := bound_frame updates blocks vectors.binding observers_outside.2.2.2.2.2.2.1
  have stackFrame := bound_frame updates blocks stackTags.binding observers_outside.2.2.2.2.2.2.2.1
  have scalarFrame (i : Fin 2) := bound_frame updates blocks (scalars.binding i) (observers_outside.2.2.2.2.2.2.2.2 i)
  have changedRead (i : Fin 3) :
      localRead m finalMem (Arm64CiliumCallerContextGPR.name i) (Arm64CiliumCallerContextGPR.chunk i) 0 =
        some (Arm64CiliumCallerContextGPR.value ctx ctxOfs i) := by
    simpa only [localRead,updates.binding i,Option.bind_some] using updateReads i
  have gprReads : CurrentGPR m finalMem ctx ctxOfs inputs := by
    constructor
    · intro i
      by_cases zero : i=0
      · subst i
        change localRead m finalMem (declaration 0).word .Mint64 0 = some (.Vptr ctx ctxOfs)
        rw [targets.1]
        exact changedRead 0
      · have old := (local_frame updates blocks _ (observers_outside.1.1 i zero) .Mint64 0).trans (gprs.word i i.isLt)
        simpa only [wordValue,ite_eq_right zero] using old
    · intro i
      by_cases zero : i=0
      · subst i
        change localRead m finalMem (declaration 0).tag .Mint8unsigned 0 = some (.Vint (1#32))
        rw [targets.2.2]
        exact changedRead 2
      · by_cases last : i=30
        · subst i
          change localRead m finalMem (declaration 30).tag .Mint8unsigned 0 = some (.Vint (10#32))
          rw [targets.2.1]
          exact changedRead 1
        · have old := (local_frame updates blocks _ (observers_outside.1.2 i zero last) .Mint8unsigned 0).trans (gprs.tag i i.isLt)
          simpa only [tagValue,ite_eq_right zero,ite_eq_right last] using old
  have flagReads : Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 := by
    intro i below
    exact (local_frame updates blocks _ (observers_outside.2.2.2.2.1 i) .Mint8unsigned 0).trans (flags i below)
  have currentDefaults (i : Fin 9) :
      CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) finalMem (locals.block i) 0 =
        some (defaultValue ctx ctxOfs abi.block i) := by
    have frame := bound_frame updates blocks (locals.binding i) (observers_outside.2.2.1 i)
      (Arm64CiliumCallerDefaults.chunk i) 0
    simpa only [defaultValue] using frame.trans (defaultReads i)
  refine ⟨updates,resource,helper,scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,
    finalMem,?_,(abiBaseFrame .Mint64 0).trans baseRead,(helperFrame .Mint64 0).trans helperRead,(fun i => (scalarFrame i _ 0).trans (scalarReads i)),(fun i => (stackFrame .Mint8unsigned _).trans (stackReads i)),(fun i below => (vectorFrame .Mint64 _).trans (vectorReads i below)),(lrFrame .Mint64 0).trans lrRead,flagReads,gprReads,
    (fun i => (wordFrame .Mint64 _).trans (wordReads i)),
    (fun i => (tagFrame .Mint64 _).trans (tagReads i)),
    ⟨Arm64CiliumCallerFlagEntry.table_frame wordEntry wordFrame⟩,
    ⟨Arm64CiliumCallerFlagEntry.table_frame tagEntry tagFrame⟩,
    (abiFrame .Mint64 0).trans dataRead,(abiFrame .Mint64 8).trans endRead,
    (fun i => (abiFrame .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    currentDefaults,firstFrame.trans gprFrame,
    gprAccess.trans firstAccess,gprNext.trans firstNext⟩
  simpa only [temps,Arm64CiliumCallerHelperSetup.entryTemps,CC.E0,CC.Eapp,List.append_nil] using star_trans firstRun gprRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerContextEntry
