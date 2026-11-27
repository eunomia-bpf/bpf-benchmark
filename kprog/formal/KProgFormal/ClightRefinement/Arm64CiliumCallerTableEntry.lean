import KProgFormal.ClightRefinement.Arm64CiliumCallerGPREntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerTableEntry
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerContext (ABI)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table tableName)
open Arm64CiliumCallerInitializers (Cells lastCell)
open Arm64CiliumCallerGPRSource (declaration)
open Arm64CiliumCallerGPRFrames (localRead Initialized)
open Arm64CiliumCallerGPRSequence (Outcomes finalTemps)

def OutsideTables (id : CC.Ident) : Prop := ∀ tags : Bool,id ≠ tableName tags

theorem observers_outside :
    (∀ i : Fin 31,OutsideTables (declaration i).word ∧ OutsideTables (declaration i).tag) ∧
    OutsideTables ___a64_sim_abi ∧
    (∀ i : Fin 9,OutsideTables (Arm64CiliumCallerDefaults.name i)) := by
  unfold OutsideTables
  decide +kernel

/-- Actual allocated identifiers give actual block separation from BOTH
tables;the same framed186-step witness supplies every preserved load. -/
theorem bound_frame {m before after : CC.Mem} (words : Table false m) (tags : Table true m)
    (blocks : ∀ b,b ≠ words.block → b ≠ tags.block → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    {id : CC.Ident} {ty : CC.Ty} {b : CC.Block}
    (binding : (allocation m).1.get id = some (b,ty)) (outside : OutsideTables id) :
    ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o := by
  have notWord := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding words.binding (outside false)
  have notTag := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding tags.binding (outside true)
  exact blocks b notWord notTag

theorem named_frame {m before after : CC.Mem} (words : Table false m) (tags : Table true m)
    (blocks : ∀ b,b ≠ words.block → b ≠ tags.block → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    (id : CC.Ident) (outside : OutsideTables id) (c : CC.Chunk) (o : Int) :
    localRead m after id c o = localRead m before id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    simpa only [localRead,binding,Option.bind_some] using
      bound_frame words tags blocks binding outside c o

theorem initialized_frame {m before after : CC.Mem} (words : Table false m) (tags : Table true m)
    (blocks : ∀ b,b ≠ words.block → b ≠ tags.block → ∀ c o,
      CC.Mem.load c after b o = CC.Mem.load c before b o)
    {inputs : Fin 30 → BitVec 64} {count : Nat} (old : Initialized m before inputs count) :
    Initialized m after inputs count := by
  constructor
  · intro i below
    exact (named_frame words tags blocks (declaration i).word (observers_outside.1 i).1
      .Mint64 0).trans (old.word i below)
  · intro i below
    exact (named_frame words tags blocks (declaration i).tag (observers_outside.1 i).2
      .Mint8unsigned 0).trans (old.tag i below)

/-- SAME original FunctionEntry through actual31GPRs then all62pointer
initializers,retaining both genuine LINK table resources and all observers. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (contextInputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (inputs : Fin 30 → BitVec 64) (outcomes : Outcomes m inputs) (k : CC.Cont) :
    ∃ words : Table false m,∃ tags : Table true m,
    ∃ wordCells : Cells false m,∃ tagCells : Cells true m,∃ locals : Locals m,
    ∃ traceFirst traceSecond traceGPR finalMem,
      CC.Star (CC.Step2 ge) (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp (CC.Eapp traceFirst traceSecond) traceGPR)
        (.State procedure Arm64CiliumCallerInitializers.afterTables k (allocation m).1
          (finalTemps inputs 0 31 (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)) finalMem) ∧
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
  obtain ⟨words⟩ := Arm64CiliumCallerTables.table_storage false m
  obtain ⟨tags⟩ := Arm64CiliumCallerTables.table_storage true m
  obtain ⟨wordCells⟩ := Arm64CiliumCallerInitializers.cells_storage false m
  obtain ⟨tagCells⟩ := Arm64CiliumCallerInitializers.cells_storage true m
  obtain ⟨locals,traceFirst,traceSecond,traceGPR,beforeTables,firstRun,gprs,dataRead,endRead,cbReads,
      defaultReads,firstFrame,firstAccess,firstNext⟩ :=
    Arm64CiliumCallerGPREntry.entry m abi ctx ctxOfs results resultOffsets contextInputs inputs outcomes k
  let temps := finalTemps inputs 0 31
    (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)
  obtain ⟨finalMem,tableRun,wordReads,tagReads,wordEntry,tagEntry,blocks,lastFrame,lastAccess,lastNext⟩ :=
    Arm64CiliumCallerInitializers.execute_framed words tags wordCells tagCells firstAccess temps k
  have abiReads := bound_frame words tags blocks abi.binding observers_outside.2.1
  have defaultFrame (i : Fin 9) :=
    bound_frame words tags blocks (locals.binding i) (observers_outside.2.2 i)
      (Arm64CiliumCallerDefaults.chunk i) 0
  refine ⟨words,tags,wordCells,tagCells,locals,traceFirst,traceSecond,traceGPR,finalMem,?_,
    initialized_frame words tags blocks gprs,wordReads,tagReads,wordEntry,tagEntry,
    (abiReads .Mint64 0).trans dataRead,(abiReads .Mint64 8).trans endRead,
    (fun i => (abiReads .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    (fun i => (defaultFrame i).trans (defaultReads i)),firstFrame.trans lastFrame,
    lastAccess.trans firstAccess,lastNext.trans firstNext⟩
  simpa only [CC.Eapp,CC.E0,List.append_nil,temps] using star_trans firstRun tableRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerTableEntry
