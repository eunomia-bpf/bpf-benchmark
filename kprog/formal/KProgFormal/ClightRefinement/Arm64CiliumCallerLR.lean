import KProgFormal.ClightRefinement.Arm64CiliumCallerFlagEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerLR
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation LRLocal)
open Arm64CiliumCallerContext (ABI)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table tableName)
open Arm64CiliumCallerInitializers (Cells lastCell)
open Arm64CiliumCallerGPRSource (declaration)
open Arm64CiliumCallerGPRFrames (localRead Initialized)
open Arm64CiliumCallerGPRSequence (Outcomes finalTemps)

theorem observers_outside :
    (∀ i : Fin 31,(declaration i).word ≠ ___a64_lr ∧ (declaration i).tag ≠ ___a64_lr) ∧
    ___a64_sim_abi ≠ ___a64_lr ∧
    (∀ i : Fin 9,Arm64CiliumCallerDefaults.name i ≠ ___a64_lr) ∧
    (∀ tags : Bool,tableName tags ≠ ___a64_lr) ∧
    (∀ i : Fin 4,(Arm64CiliumCallerFlags.declaration i).name ≠ ___a64_lr) := by
  decide +kernel

/-- Actual current write permission comes from the SAME795-local allocation.
The original LRzero statement executes once before the actual vector source. -/
theorem execute {m before : CC.Mem} (lr : LRLocal m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 3 (.State procedure Arm64CiliumCallerFlags.after k (allocation m).1 le before)
        (.State procedure Arm64CiliumCallerFlags.vectorStart k (allocation m).1 le after) ∧
      CC.Mem.store .Mint64 before lr.block 0 (.Vlong (0#64)) = some after ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong (0#64)) ∧
      (∀ b,b ≠ lr.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have live : CC.Mem.rangePerm before lr.block 0 8 .Cur .Freeable = true := by
    apply CC.Mem.rangePerm_intro
    intro o lower upper
    have permission := CC.Mem.rangePerm_perm _ _ _ _ _ _ lr.live o lower upper
    simpa only [CC.Mem.perm,access] using permission
  have range := CC.Mem.rangePerm_implies live (by decide : CC.permOrder .Freeable .Writable = true)
  have valid : CC.Mem.validAccess before .Mint64 lr.block 0 .Writable = true := by
    change (CC.Mem.rangePerm before lr.block 0 8 .Cur .Writable && true) = true
    rw [range]
    rfl
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 before lr.block 0 (.Vlong (0#64)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  let rest := Arm64CiliumCallerFlags.vectorStart
  have step : CC.Step2 ge
      (.State procedure (.Sassign (.Evar ___a64_lr CC.tulong) (.Econst_int (0#32) CC.tint))
        (.Kseq rest k) (allocation m).1 le before) CC.E0
      (.State procedure .Sskip (.Kseq rest k) (allocation m).1 le after) := by
    apply CC.Step.assign
    · exact .Evar_local _ _ _ lr.binding
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ rfl
    · rfl
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ stored
  refine ⟨after,?_,stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store lr.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  rw [Arm64CiliumCallerFlags.after_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

theorem local_frame {m before after : CC.Mem} (lr : LRLocal m)
    (frame : ∀ b,b ≠ lr.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o)
    (id : CC.Ident) (different : id ≠ ___a64_lr) (c : CC.Chunk) (o : Int) :
    localRead m after id c o = localRead m before id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    have separate := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ binding lr.binding different
    simpa only [localRead,binding,Option.bind_some] using frame cell.1 separate c o

theorem bound_frame {m before after : CC.Mem} (lr : LRLocal m)
    (frame : ∀ b,b ≠ lr.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o)
    {id : CC.Ident} {ty : CC.Ty} {b : CC.Block}
    (binding : (allocation m).1.get id = some (b,ty)) (different : id ≠ ___a64_lr) :
    ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o :=
  frame b ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding lr.binding different)

/-- SAME whole entry followed by the actual LRzero assignment. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (inputs : Fin 30 → BitVec 64) (outcomes : Outcomes m inputs)
    (flagInputs : Fin 4 → BitVec 64)
    (flagOutcomes : Arm64CiliumCallerFlagSequence.Outcomes m flagInputs) (k : CC.Cont) :
    ∃ lr : LRLocal m,∃ words : Table false m,∃ tags : Table true m,
    ∃ wordCells : Cells false m,∃ tagCells : Cells true m,∃ locals : Locals m,
    ∃ traceFirst traceSecond traceGPR traceFlags finalMem,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR) traceFlags)
        (.State procedure Arm64CiliumCallerFlags.vectorStart k (allocation m).1
          (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
            (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets))) finalMem) ∧
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
  obtain ⟨words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,beforeLR,
      firstRun,flags,gprs,wordReads,tagReads,⟨wordEntry⟩,⟨tagEntry⟩,dataRead,endRead,cbReads,
      defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerFlagEntry.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes
      flagInputs flagOutcomes k
  obtain ⟨lr⟩ := Arm64CiliumCallerLink.lr_local m
  let temps := Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
    (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets))
  obtain ⟨finalMem,lrRun,stored,lrRead,blocks,lastFrame,lastAccess,lastNext⟩ :=
    execute lr firstAccess temps k
  have wordFrame := bound_frame lr blocks words.binding (observers_outside.2.2.2.1 false)
  have tagFrame := bound_frame lr blocks tags.binding (observers_outside.2.2.2.1 true)
  have abiFrame := bound_frame lr blocks abi.binding observers_outside.2.1
  have gprReads : Initialized m finalMem inputs 31 := by
    constructor
    · intro i below
      exact (local_frame lr blocks _ (observers_outside.1 i).1 .Mint64 0).trans (gprs.word i below)
    · intro i below
      exact (local_frame lr blocks _ (observers_outside.1 i).2 .Mint8unsigned 0).trans (gprs.tag i below)
  have flagReads : Arm64CiliumCallerFlagSequence.Initialized m finalMem flagInputs 4 := by
    intro i below
    exact (local_frame lr blocks _ (observers_outside.2.2.2.2 i) .Mint8unsigned 0).trans (flags i below)
  have defaultFrame (i : Fin 9) :=
    bound_frame lr blocks (locals.binding i) (observers_outside.2.2.1 i)
      (Arm64CiliumCallerDefaults.chunk i) 0
  refine ⟨lr,words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,traceFlags,finalMem,?_,
    lrRead,flagReads,gprReads,(fun i => (wordFrame .Mint64 _).trans (wordReads i)),
    (fun i => (tagFrame .Mint64 _).trans (tagReads i)),
    ⟨Arm64CiliumCallerFlagEntry.table_frame wordEntry wordFrame⟩,
    ⟨Arm64CiliumCallerFlagEntry.table_frame tagEntry tagFrame⟩,
    (abiFrame .Mint64 0).trans dataRead,(abiFrame .Mint64 8).trans endRead,
    (fun i => (abiFrame .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    (fun i => (defaultFrame i).trans (defaultReads i)),firstFrame.trans lastFrame,
    lastAccess.trans firstAccess,lastNext.trans firstNext⟩
  simpa only [CC.Eapp,CC.E0,List.append_nil,temps] using star_trans firstRun lrRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerLR
