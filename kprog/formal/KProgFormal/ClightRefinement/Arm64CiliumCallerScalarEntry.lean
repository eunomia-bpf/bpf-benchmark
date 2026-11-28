import KProgFormal.ClightRefinement.Arm64CiliumCallerEntryScalars
import KProgFormal.ClightRefinement.Arm64CiliumCallerStackTagEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerScalarEntry
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

def Outside (id : CC.Ident) : Prop := ∀ i : Fin 2,id ≠ Arm64CiliumCallerEntryScalars.name i

def defaultValue (i : Fin 9) : CC.Val :=
  if i = 6 then .Vint (1#32) else Arm64CiliumCallerDefaults.value i

theorem default_replaced : Arm64CiliumCallerDefaults.name 6 = Arm64CiliumCallerEntryScalars.name 1 ∧
    Arm64CiliumCallerDefaults.ty 6 = Arm64CiliumCallerEntryScalars.ty 1 ∧
    Arm64CiliumCallerDefaults.chunk 6 = Arm64CiliumCallerEntryScalars.chunk 1 := by
  repeat' constructor
  all_goals rfl

theorem observers_outside :
    (∀ i : Fin 31,Outside (declaration i).word ∧ Outside (declaration i).tag) ∧
    Outside ___a64_sim_abi ∧
    (∀ i : Fin 9,i ≠ 6 → Outside (Arm64CiliumCallerDefaults.name i)) ∧
    (∀ tags : Bool,Outside (tableName tags)) ∧
    (∀ i : Fin 4,Outside (Arm64CiliumCallerFlags.declaration i).name) ∧
    Outside ___a64_lr ∧ Outside Arm64Entry.___a64_vectors ∧ Outside ___a64_stack_tag := by
  unfold Outside
  decide +kernel

theorem bound_frame {m before after : CC.Mem} (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (blocks : ∀ b,b ≠ scalars.block 0 → b ≠ scalars.block 1 → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    {id : CC.Ident} {ty : CC.Ty} {b : CC.Block}
    (binding : (allocation m).1.get id = some (b,ty)) (outside : Outside id) :
    ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o :=
  blocks b
    ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2 _ _ _ _ binding (scalars.binding 0) (outside 0))
    ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2 _ _ _ _ binding (scalars.binding 1) (outside 1))

theorem local_frame {m before after : CC.Mem} (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (blocks : ∀ b,b ≠ scalars.block 0 → b ≠ scalars.block 1 → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    (id : CC.Ident) (outside : Outside id) (c : CC.Chunk) (o : Int) :
    localRead m after id c o = localRead m before id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    simpa only [localRead,binding,Option.bind_some] using bound_frame scalars blocks binding outside c o

/-- SAME entry,64vector/eight stack tags,then actual SPzero/is_xdp=1;
all earlier readbacks and original table resources preserved. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (inputs : Fin 30 → BitVec 64) (outcomes : Outcomes m inputs)
    (flagInputs : Fin 4 → BitVec 64)
    (flagOutcomes : Arm64CiliumCallerFlagSequence.Outcomes m flagInputs)
    (vectors : Storage m) (vectorInputs : Fin 64 → BitVec 64)
    (vectorOutcomes : Arm64CiliumCallerVectorSequence.Outcomes vectors vectorInputs) (k : CC.Cont) :
    ∃ scalars : Arm64CiliumCallerEntryScalars.Locals m,∃ stackTags : StackTagLocal m,∃ lr : LRLocal m,∃ words : Table false m,∃ tags : Table true m,
    ∃ wordCells : Cells false m,∃ tagCells : Cells true m,∃ locals : Locals m,
    ∃ traceFirst traceSecond traceGPR traceFlags traceVectors finalMem,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR) traceFlags) traceVectors)
        (.State procedure Arm64CiliumCallerEntryScalars.after k (allocation m).1
          (Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
            (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
            (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)))) finalMem) ∧
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
        some (defaultValue i)) ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨stackTags,lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,
      traceVectors,beforeScalars,firstRun,stackReads,vectorReads,lrRead,flags,gprs,wordReads,tagReads,
      ⟨wordEntry⟩,⟨tagEntry⟩,dataRead,endRead,cbReads,defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerStackTagEntry.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes
      flagInputs flagOutcomes vectors vectorInputs vectorOutcomes k
  let temps := Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
    (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
    (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)))
  obtain ⟨scalars⟩ := Arm64CiliumCallerEntryScalars.local_storage m
  obtain ⟨finalMem,scalarRun,scalarReads,blocks,scalarFrame,scalarAccess,scalarNext⟩ :=
    Arm64CiliumCallerEntryScalars.execute scalars firstAccess temps k
  have wordFrame := bound_frame scalars blocks words.binding (observers_outside.2.2.2.1 false)
  have tagFrame := bound_frame scalars blocks tags.binding (observers_outside.2.2.2.1 true)
  have abiFrame := bound_frame scalars blocks abi.binding observers_outside.2.1
  have lrFrame := bound_frame scalars blocks lr.binding observers_outside.2.2.2.2.2.1
  have vectorFrame := bound_frame scalars blocks vectors.binding observers_outside.2.2.2.2.2.2.1
  have stackFrame := bound_frame scalars blocks stackTags.binding observers_outside.2.2.2.2.2.2.2
  have gprReads : Initialized m finalMem inputs 31 := by
    constructor
    · intro i below
      exact (local_frame scalars blocks _ (observers_outside.1 i).1 .Mint64 0).trans (gprs.word i below)
    · intro i below
      exact (local_frame scalars blocks _ (observers_outside.1 i).2 .Mint8unsigned 0).trans (gprs.tag i below)
  have flagReads : Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 := by
    intro i below
    exact (local_frame scalars blocks _ (observers_outside.2.2.2.2.1 i) .Mint8unsigned 0).trans (flags i below)
  have currentDefaults (i : Fin 9) :
      CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) finalMem (locals.block i) 0 =
        some (defaultValue i) := by
    by_cases changed : i = 6
    · subst i
      have oldBinding := locals.binding 6
      change (allocation m).1.get (Arm64CiliumCallerEntryScalars.name 1) =
        some (locals.block 6,Arm64CiliumCallerEntryScalars.ty 1) at oldBinding
      have same : locals.block 6 = scalars.block 1 :=
        congrArg Prod.fst (Option.some.inj (oldBinding.symm.trans (scalars.binding 1)))
      change CC.Mem.load .Mint8unsigned finalMem (locals.block 6) 0 = some (.Vint (1#32))
      rw [same]
      exact scalarReads 1
    · have frame := bound_frame scalars blocks (locals.binding i) (observers_outside.2.2.1 i changed)
        (Arm64CiliumCallerDefaults.chunk i) 0
      simpa only [defaultValue,if_neg changed] using frame.trans (defaultReads i)
  refine ⟨scalars,stackTags,lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,traceVectors,
    finalMem,?_,scalarReads,(fun i => (stackFrame .Mint8unsigned _).trans (stackReads i)),(fun i below => (vectorFrame .Mint64 _).trans (vectorReads i below)),(lrFrame .Mint64 0).trans lrRead,flagReads,gprReads,
    (fun i => (wordFrame .Mint64 _).trans (wordReads i)),
    (fun i => (tagFrame .Mint64 _).trans (tagReads i)),
    ⟨Arm64CiliumCallerFlagEntry.table_frame wordEntry wordFrame⟩,
    ⟨Arm64CiliumCallerFlagEntry.table_frame tagEntry tagFrame⟩,
    (abiFrame .Mint64 0).trans dataRead,(abiFrame .Mint64 8).trans endRead,
    (fun i => (abiFrame .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    currentDefaults,firstFrame.trans scalarFrame,
    scalarAccess.trans firstAccess,scalarNext.trans firstNext⟩
  simpa only [temps,CC.E0,CC.Eapp,List.append_nil] using star_trans firstRun scalarRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerScalarEntry
