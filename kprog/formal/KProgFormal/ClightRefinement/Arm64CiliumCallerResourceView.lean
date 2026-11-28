import KProgFormal.ClightRefinement.Arm64CiliumCallerScalarView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerResourceView
open Arm64CiliumCallerLink (allocation LRLocal)
open Arm64CiliumCallerHeaderSource (Header Sources declaration)
open Arm64CiliumCallerContextEntry (defaultValue)

/-- Lookup uniqueness identifies the real source cell, without an allocator bridge. -/
theorem source_readback {m memory : CC.Mem} (header : Header m) (sources : Sources m)
    (i : Fin 12) (chunk : CC.Chunk) (value : CC.Val) {block : CC.Block} {ty : CC.Ty}
    (binding : (allocation m).1.get (declaration i).sourceName = some (block,ty))
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources memory 12)
    (read : CC.Mem.load chunk memory block 0 = some value) :
    Arm64EntryMemory.borrowed memory.nextblock chunk memory (.Vptr header.block 0)
      (declaration i).field = some value := by
  have same : sources.block i = block :=
    congrArg Prod.fst (Option.some.inj ((sources.binding i).symm.trans binding))
  apply Arm64CiliumCallerScalarView.borrowed_readback header sources i chunk value pointers
  rw [same]
  exact read

private theorem scalar_names :
    (declaration 5).sourceName = Arm64CiliumCallerEntryScalars.name 0 ∧
    (declaration 4).sourceName = Arm64CiliumCallerUnit.___a64_lr := by
  decide +kernel

/-- The reached SP and LR are both actual zero-valued locals. -/
theorem sp_lr_readbacks {m memory : CC.Mem} (header : Header m) (sources : Sources m)
    (scalars : Arm64CiliumCallerEntryScalars.Locals m) (lr : LRLocal m)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources memory 12)
    (scalarReads : ∀ i : Fin 2,
      CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i) memory (scalars.block i) 0 =
        some (Arm64CiliumCallerEntryScalars.value i))
    (lrRead : CC.Mem.load .Mint64 memory lr.block 0 = some (.Vlong (0#64))) :
    Arm64EntryMemory.borrowed memory.nextblock .Mint64 memory (.Vptr header.block 0)
      Arm64Program._sp = some (.Vlong (0#64)) ∧
    Arm64EntryMemory.borrowed memory.nextblock .Mint64 memory (.Vptr header.block 0)
      Arm64Program._lr = some (.Vlong (0#64)) := by
  have spBinding := scalars.binding 0
  rw [← scalar_names.1] at spBinding
  have lrBinding := lr.binding
  rw [← scalar_names.2] at lrBinding
  constructor
  · exact source_readback header sources 5 .Mint64 (.Vlong (0#64))
      spBinding pointers (scalarReads 0)
  · exact source_readback header sources 4 .Mint64 (.Vlong (0#64))
      lrBinding pointers lrRead

def defaultIndex (i : Fin 4) : Fin 9 := ⟨2+i.val,by have := i.isLt;omega⟩
def fieldIndex (i : Fin 4) : Fin 12 :=
  if i.val < 2 then ⟨2+i.val,by omega⟩ else ⟨4+i.val,by have := i.isLt;omega⟩
def defaultChunk (i : Fin 4) : CC.Chunk := if i.val < 2 then .Mint64 else .Mint8unsigned
def defaultZero (i : Fin 4) : CC.Val :=
  if i.val < 2 then .Vlong (0#64) else .Vint (0#32)

private theorem default_names : ∀ i : Fin 4,
    (declaration (fieldIndex i)).sourceName = Arm64CiliumCallerDefaults.name (defaultIndex i) := by
  decide +kernel

/-- Later helper/XDP updates leave these four original defaults zero. -/
theorem default_values (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (abi : CC.Block) :
    ∀ i : Fin 4,
      Arm64CiliumCallerDefaults.chunk (defaultIndex i) = defaultChunk i ∧
      defaultValue ctx ctxOfs abi (defaultIndex i) = defaultZero i := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

/-- Numeric SP/return bases and their validity bytes retain the real default reads. -/
theorem base_readbacks {m memory : CC.Mem} (header : Header m) (sources : Sources m)
    (locals : Arm64CiliumCallerDefaults.Locals m)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (abi : CC.Block)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources memory 12)
    (reads : ∀ i : Fin 9,
      CC.Mem.load (Arm64CiliumCallerDefaults.chunk i) memory (locals.block i) 0 =
        some (defaultValue ctx ctxOfs abi i)) :
    ∀ i : Fin 4,
      Arm64EntryMemory.borrowed memory.nextblock (defaultChunk i) memory (.Vptr header.block 0)
        (declaration (fieldIndex i)).field = some (defaultZero i) := by
  intro i
  have binding := locals.binding (defaultIndex i)
  rw [← default_names i] at binding
  have read := reads (defaultIndex i)
  rw [(default_values ctx ctxOfs abi i).1,(default_values ctx ctxOfs abi i).2] at read
  exact source_readback header sources (fieldIndex i) (defaultChunk i) (defaultZero i)
    binding pointers read

end KProgFormal.ClightRefinement.Arm64CiliumCallerResourceView
