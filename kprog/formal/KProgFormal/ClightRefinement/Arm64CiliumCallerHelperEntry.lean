import KProgFormal.ClightRefinement.Arm64CiliumCallerHelperSetup

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHelperEntry
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

def Outside (id : CC.Ident) : Prop := id ≠ ___a64_sim_helper_ctx

def defaultValue (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (i : Fin 9) : CC.Val :=
  if i = 7 then .Vptr ctx ctxOfs else Arm64CiliumCallerScalarEntry.defaultValue i

theorem default_replaced : Arm64CiliumCallerDefaults.name 7 = ___a64_sim_helper_ctx ∧
    Arm64CiliumCallerDefaults.ty 7 = CC.tptr CC.tvoid ∧
    Arm64CiliumCallerDefaults.chunk 7 = CC.Chunk.Mint64 := by
  repeat' constructor
  all_goals rfl

theorem observers_outside :
    (∀ i : Fin 31,Outside (declaration i).word ∧ Outside (declaration i).tag) ∧
    Outside ___a64_sim_abi ∧
    (∀ i : Fin 9,i ≠ 7 → Outside (Arm64CiliumCallerDefaults.name i)) ∧
    (∀ tags : Bool,Outside (tableName tags)) ∧
    (∀ i : Fin 4,Outside (Arm64CiliumCallerFlags.declaration i).name) ∧
    Outside ___a64_lr ∧ Outside Arm64Entry.___a64_vectors ∧ Outside ___a64_stack_tag ∧
    (∀ i : Fin 2,Outside (Arm64CiliumCallerEntryScalars.name i)) := by
  unfold Outside
  decide +kernel

theorem bound_frame {m before after : CC.Mem} (resource : Arm64CiliumCallerHelperSetup.Storage m)
    (blocks : ∀ b,b ≠ resource.block → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    {id : CC.Ident} {ty : CC.Ty} {b : CC.Block}
    (binding : (allocation m).1.get id = some (b,ty)) (outside : Outside id) :
    ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o :=
  blocks b ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding resource.binding outside)

theorem local_frame {m before after : CC.Mem} (resource : Arm64CiliumCallerHelperSetup.Storage m)
    (blocks : ∀ b,b ≠ resource.block → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    (id : CC.Ident) (outside : Outside id) (c : CC.Chunk) (o : Int) :
    localRead m after id c o = localRead m before id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    simpa only [localRead,binding,Option.bind_some] using bound_frame resource blocks binding outside c o

/-- SAME actual whole entry followed by the original helper context store;
default7 updates to the original ctx pointer,default6 retains one. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (inputs : Fin 30 → BitVec 64) (outcomes : Outcomes m inputs)
    (flagInputs : Fin 4 → BitVec 64)
    (flagOutcomes : Arm64CiliumCallerFlagSequence.Outcomes m flagInputs)
    (vectors : Storage m) (vectorInputs : Fin 64 → BitVec 64)
    (vectorOutcomes : Arm64CiliumCallerVectorSequence.Outcomes vectors vectorInputs) (k : CC.Cont) :
    ∃ resource : Arm64CiliumCallerHelperSetup.Storage m,∃ scalars : Arm64CiliumCallerEntryScalars.Locals m,∃ stackTags : StackTagLocal m,∃ lr : LRLocal m,∃ words : Table false m,∃ tags : Table true m,
    ∃ wordCells : Cells false m,∃ tagCells : Cells true m,∃ locals : Locals m,
    ∃ traceFirst traceSecond traceGPR traceFlags traceVectors finalMem,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR) traceFlags) traceVectors)
        (.State procedure s_trusted_arm64_arm64_sim_xdp_9287 k (allocation m).1
          (Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
            (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
            (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)))) finalMem) ∧
      CC.Mem.load .Mint64 finalMem resource.block 0 = some (.Vptr ctx ctxOfs) ∧
      (∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i) finalMem (scalars.block i) 0 =
        some (Arm64CiliumCallerEntryScalars.value i)) ∧
      (∀ i : Fin 8,CC.Mem.load .Mint8unsigned finalMem stackTags.block (i.val : Int) = some (.Vint 0)) ∧
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
        some (defaultValue ctx ctxOfs i)) ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,
      traceVectors,beforeHelper,firstRun,scalarReads,stackReads,vectorReads,lrRead,flags,gprs,wordReads,tagReads,
      ⟨wordEntry⟩,⟨tagEntry⟩,dataRead,endRead,cbReads,defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerScalarEntry.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes
      flagInputs flagOutcomes vectors vectorInputs vectorOutcomes k
  let temps := Arm64CiliumCallerHelperSetup.entryTemps ctx ctxOfs results resultOffsets inputs flagInputs vectorInputs
  obtain ⟨resource⟩ := Arm64CiliumCallerHelperSetup.storage m
  obtain ⟨finalMem,helperRun,stored,helperRead,blocks,helperFrame,helperAccess,helperNext⟩ :=
    Arm64CiliumCallerHelperSetup.execute resource firstAccess ctx ctxOfs temps k
      (Arm64CiliumCallerHelperSetup.reached_context ctx ctxOfs results resultOffsets inputs flagInputs vectorInputs)
  have wordFrame := bound_frame resource blocks words.binding (observers_outside.2.2.2.1 false)
  have tagFrame := bound_frame resource blocks tags.binding (observers_outside.2.2.2.1 true)
  have abiFrame := bound_frame resource blocks abi.binding observers_outside.2.1
  have lrFrame := bound_frame resource blocks lr.binding observers_outside.2.2.2.2.2.1
  have vectorFrame := bound_frame resource blocks vectors.binding observers_outside.2.2.2.2.2.2.1
  have stackFrame := bound_frame resource blocks stackTags.binding observers_outside.2.2.2.2.2.2.2.1
  have scalarFrame (i : Fin 2) := bound_frame resource blocks (scalars.binding i) (observers_outside.2.2.2.2.2.2.2.2 i)
  have gprReads : Initialized m finalMem inputs 31 := by
    constructor
    · intro i below
      exact (local_frame resource blocks _ (observers_outside.1 i).1 .Mint64 0).trans (gprs.word i below)
    · intro i below
      exact (local_frame resource blocks _ (observers_outside.1 i).2 .Mint8unsigned 0).trans (gprs.tag i below)
  have flagReads : Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 := by
    intro i below
    exact (local_frame resource blocks _ (observers_outside.2.2.2.2.1 i) .Mint8unsigned 0).trans (flags i below)
  have currentDefaults (i : Fin 9) :
      CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) finalMem (locals.block i) 0 =
        some (defaultValue ctx ctxOfs i) := by
    by_cases changed : i = 7
    · subst i
      have oldBinding := locals.binding 7
      change (allocation m).1.get ___a64_sim_helper_ctx =
        some (locals.block 7,CC.tptr CC.tvoid) at oldBinding
      have same : locals.block 7 = resource.block :=
        congrArg Prod.fst (Option.some.inj (oldBinding.symm.trans resource.binding))
      change CC.Mem.load .Mint64 finalMem (locals.block 7) 0 = some (.Vptr ctx ctxOfs)
      rw [same]
      exact helperRead
    · have frame := bound_frame resource blocks (locals.binding i) (observers_outside.2.2.1 i changed)
        (Arm64CiliumCallerDefaults.chunk i) 0
      simpa only [defaultValue,if_neg changed] using frame.trans (defaultReads i)
  refine ⟨resource,scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,
    finalMem,?_,helperRead,(fun i => (scalarFrame i _ 0).trans (scalarReads i)),(fun i => (stackFrame .Mint8unsigned _).trans (stackReads i)),(fun i below => (vectorFrame .Mint64 _).trans (vectorReads i below)),(lrFrame .Mint64 0).trans lrRead,flagReads,gprReads,
    (fun i => (wordFrame .Mint64 _).trans (wordReads i)),
    (fun i => (tagFrame .Mint64 _).trans (tagReads i)),
    ⟨Arm64CiliumCallerFlagEntry.table_frame wordEntry wordFrame⟩,
    ⟨Arm64CiliumCallerFlagEntry.table_frame tagEntry tagFrame⟩,
    (abiFrame .Mint64 0).trans dataRead,(abiFrame .Mint64 8).trans endRead,
    (fun i => (abiFrame .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    currentDefaults,firstFrame.trans helperFrame,
    helperAccess.trans firstAccess,helperNext.trans firstNext⟩
  simpa only [temps,Arm64CiliumCallerHelperSetup.entryTemps,CC.E0,CC.Eapp,List.append_nil] using star_trans firstRun helperRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerHelperEntry
