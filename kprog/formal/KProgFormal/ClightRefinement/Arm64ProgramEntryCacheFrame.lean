import KProgFormal.ClightRefinement.Arm64ProgramEntryColdRead

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCacheFrame

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

/-- The used observation frame for a selected origin input. Cache-cell values
may change, and no equality of whole memories is required. Production input
admission remains explicit, as for the existing entry-provider contracts. -/
structure Frame (initial : CC.Mem) (returns : Bool) (before after : CC.Mem) : Prop where
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock
  caller : FrameBelow initial.nextblock before after
  local_load : ∀ id ty block, (allocation initial).1.get id = some (block, ty) →
    baseName returns ≠ id → validName returns ≠ id → ∀ chunk ofs,
    CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs

theorem Frame.trans {initial a b c : CC.Mem} {returns : Bool}
    (first : Frame initial returns a b) (second : Frame initial returns b c) : Frame initial returns a c :=
  ⟨second.access.trans first.access, second.nextblock.trans first.nextblock,
    first.caller.trans second.caller,
    fun id ty block binding baseOther validOther chunk ofs =>
      (second.local_load id ty block binding baseOther validOther chunk ofs).trans
        (first.local_load id ty block binding baseOther validOther chunk ofs)⟩

private theorem header_other : ∀ returns,
    baseName returns ≠ Arm64Entry._entry ∧ validName returns ≠ Arm64Entry._entry := by decide +kernel
private theorem table_other : ∀ returns tags,
    baseName returns ≠ tableName tags ∧ validName returns ≠ tableName tags := by decide +kernel
private theorem cell_other : ∀ returns tags (i : Fin 31),
    baseName returns ≠ tableCellName tags i ∧ validName returns ≠ tableCellName tags i := by decide +kernel
private theorem sp_other : ∀ returns,
    baseName returns ≠ headerSourceName 5 ∧ validName returns ≠ headerSourceName 5 := by decide +kernel
private theorem flag_other : ∀ returns (i : Fin 4),
    baseName returns ≠ headerSourceName (flagIndex i) ∧
      validName returns ≠ headerSourceName (flagIndex i) := by decide +kernel
private theorem vector_other : ∀ returns,
    baseName returns ≠ Arm64Entry.___a64_vectors ∧ validName returns ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- The same allocation-bound storage survives the provider/cache frame. -/
def Frame.storage {initial before after : CC.Mem} {returns : Bool} {entry : HeaderLocal initial}
    (frame : Frame initial returns before after) (storage : Storage initial before entry) :
    Storage initial after entry where
  tables := storage.tables
  roots := fun tags => (frame.local_load _ _ _ entry.binding
    (header_other returns).1 (header_other returns).2 CC.Mptr _).trans (storage.roots tags)
  slots := fun tags i => (frame.local_load _ _ _ (storage.tables tags).binding
    (table_other returns tags).1 (table_other returns tags).2 CC.Mptr _).trans (storage.slots tags i)
  writable := fun tags i => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (chunk := cellChunk tags) (b := (storage.tables tags).cellBlock i) (ofs := 0) (p := .Writable)
    (fun ofs => by simp only [CC.Mem.perm, frame.access])).trans (storage.writable tags i)
  sp := storage.sp
  spPointer := (frame.local_load _ _ _ entry.binding
    (header_other returns).1 (header_other returns).2 CC.Mptr 40).trans storage.spPointer
  spValue := storage.spValue
  spRead := (frame.local_load _ _ _ storage.sp.binding
    (sp_other returns).1 (sp_other returns).2 .Mint64 0).trans storage.spRead
  flags := storage.flags
  flagPointers := fun i => (frame.local_load _ _ _ entry.binding
    (header_other returns).1 (header_other returns).2 CC.Mptr _).trans (storage.flagPointers i)
  flagWritable := fun flag =>
    (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (chunk := .Mint8unsigned) (b := (storage.flags flag).block) (ofs := 0) (p := .Writable)
      (fun ofs => by simp only [CC.Mem.perm, frame.access])).trans (storage.flagWritable flag)
  vectors := storage.vectors
  vectorPointers := fun high i => (frame.local_load _ _ _ entry.binding
    (header_other returns).1 (header_other returns).2 CC.Mptr _).trans (storage.vectorPointers high i)

theorem Frame.gpr {initial before after : CC.Mem} {returns : Bool} {entry : HeaderLocal initial}
    (frame : Frame initial returns before after) (storage : Storage initial before entry) (i : Fin 31) :
    Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) i.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val := by
  rw [← frame.nextblock, Arm64RegisterWrite.storage_gpr (frame.storage storage),
    frame.nextblock, Arm64RegisterWrite.storage_gpr storage]
  change (do let word ← CC.Mem.load .Mint64 after ((storage.tables false).cellBlock i) 0
             let tag ← CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock i) 0
             pure (word, tag)) = _
  rw [frame.local_load _ _ _ ((storage.tables false).cellBinding i)
        (cell_other returns false i).1 (cell_other returns false i).2 .Mint64 0,
      frame.local_load _ _ _ ((storage.tables true).cellBinding i)
        (cell_other returns true i).1 (cell_other returns true i).2 .Mint8unsigned 0]

theorem Frame.sp {initial before after : CC.Mem} {returns : Bool} {entry : HeaderLocal initial}
    (frame : Frame initial returns before after) (storage : Storage initial before entry) :
    Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp =
      Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0) Arm64Program._sp := by
  have a := header_borrowed_readback after entry.block 5 .Mint64 storage.sp.block 0 _
    (frame.storage storage).spPointer (frame.storage storage).spRead
  have b := header_borrowed_readback before entry.block 5 .Mint64 storage.sp.block 0 _
    storage.spPointer storage.spRead
  change Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
    Arm64Program._sp = some (.Vlong storage.spValue) at a
  change Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0)
    Arm64Program._sp = some (.Vlong storage.spValue) at b
  rw [frame.nextblock] at a
  exact a.trans b.symm

theorem Frame.vector {initial before after : CC.Mem} {returns : Bool} {entry : HeaderLocal initial}
    (frame : Frame initial returns before after) (storage : Storage initial before entry) (i : Fin 32) :
    Arm64EntryMemory.vector before.nextblock after (.Vptr entry.block 0) i =
      Arm64EntryMemory.vector before.nextblock before (.Vptr entry.block 0) i := by
  rw [← frame.nextblock, Arm64RegisterWrite.storage_vector (frame.storage storage),
    frame.nextblock, Arm64RegisterWrite.storage_vector storage]
  change (do let lo ← CC.Mem.load .Mint64 after storage.vectors.block
               (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false i))
             let hi ← CC.Mem.load .Mint64 after storage.vectors.block
               (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true i))
             pure (lo, hi)) = _
  rw [frame.local_load _ _ _ storage.vectors.binding (vector_other returns).1 (vector_other returns).2
        .Mint64 (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false i)),
      frame.local_load _ _ _ storage.vectors.binding (vector_other returns).1 (vector_other returns).2
        .Mint64 (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true i))]

theorem Frame.flag {initial before after : CC.Mem} {returns : Bool} {entry : HeaderLocal initial}
    (frame : Frame initial returns before after) (storage : Storage initial before entry) (i : Fin 4) :
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (headerField (flagIndex i)) =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      (headerField (flagIndex i)) := by
  rw [← frame.nextblock, Arm64RegisterWrite.storage_flag (frame.storage storage),
    frame.nextblock, Arm64RegisterWrite.storage_flag storage]
  exact frame.local_load _ _ _ (storage.flags i).binding
    (flag_other returns i).1 (flag_other returns i).2 .Mint8unsigned 0

/-- The complete architectural register relation follows the preserved typed
walks; the provider/cache operation itself performs no native instruction. -/
theorem Frame.represents {initial before after : CC.Mem} {returns : Bool} {entry : HeaderLocal initial}
    (frame : Frame initial returns before after) (storage : Storage initial before entry)
    {addresses origins s}
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) s := by
  refine ⟨?_, ?_, ?_, ?_⟩
  · intro i; simpa only [frame.gpr storage i] using represented.gpr i
  · simpa only [frame.sp storage] using represented.sp
  · intro i; simpa only [frame.vector storage i] using represented.vectors i
  · have n := frame.flag storage 0
    have z := frame.flag storage 1
    have c := frame.flag storage 2
    have v := frame.flag storage 3
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._n = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
        (.Vptr entry.block 0) Arm64Program._n at n
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._z = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
        (.Vptr entry.block 0) Arm64Program._z at z
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._c = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
        (.Vptr entry.block 0) Arm64Program._c at c
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._v = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
        (.Vptr entry.block 0) Arm64Program._v at v
    simpa only [Arm64Nop.FlagsRepresent, Arm64EntryMemory.flags, n, z, c, v] using represented.flags

/-- The two real cache stores preserve every other canonical producer local,
all original caller bytes/permissions and the complete access map. -/
theorem stores_frame {initial supplied middle after : CC.Mem} {returns : Bool}
    (locals : CacheLocals returns initial) (base : BitVec 64)
    (storeBase : CC.Mem.store .Mint64 supplied locals.baseBlock 0 (.Vlong base) = some middle)
    (storeValid : CC.Mem.store .Mint8unsigned middle locals.validBlock 0 (.Vint 1) = some after) :
    Frame initial returns supplied after := by
  have separate := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm)).2
  refine ⟨(CC.Mem.store_access storeValid).trans (CC.Mem.store_access storeBase),
    (CC.Mem.store_nextblock storeValid).trans (CC.Mem.store_nextblock storeBase),
    (FrameBelow.store locals.baseFresh storeBase).trans (FrameBelow.store locals.validFresh storeValid), ?_⟩
  intro id ty block binding baseOther validOther chunk ofs
  have baseSeparate := separate _ _ _ _ locals.baseBinding binding baseOther
  have validSeparate := separate _ _ _ _ locals.validBinding binding validOther
  exact (CC.Mem.load_store_other storeValid chunk block ofs (.inl (Ne.symm validSeparate))).trans
    (CC.Mem.load_store_other storeBase chunk block ofs (.inl (Ne.symm baseSeparate)))

/-- Construct the post-provider cache resource from the original allocation,
retained typed header pointers and current permissions. Its addresses are the
actual canonical locals, rather than an assumed post-state resource. -/
def cache_storage (returns : Bool) (initial memory : CC.Mem) (frontier : CC.Block)
    (entry : HeaderLocal initial) (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (locals : CacheLocals returns initial)
    (access : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block memory.access = CC.PMap.get block (allocation initial).2.access)
    (next : memory.nextblock = frontier)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0)) :
    Arm64RegisterReads.BorrowedCacheStorage returns frontier entry.block 0 memory := by
  have entryEq : entry.block = locals.entryBlock :=
    congrArg Prod.fst (Option.some.inj (entry.binding.symm.trans locals.entryBinding))
  have baseEq : (header (if returns then 3 else 2)).block = locals.baseBlock := by
    cases returns
    · exact congrArg Prod.fst (Option.some.inj ((header 2).binding.symm.trans locals.baseBinding))
    · exact congrArg Prod.fst (Option.some.inj ((header 3).binding.symm.trans locals.baseBinding))
  have validEq : (header (if returns then 7 else 6)).block = locals.validBlock := by
    cases returns
    · exact congrArg Prod.fst (Option.some.inj ((header 6).binding.symm.trans locals.validBinding))
    · exact congrArg Prod.fst (Option.some.inj ((header 7).binding.symm.trans locals.validBinding))
  have basePointer := pointers (if returns then 3 else 2)
  have validPointer := pointers (if returns then 7 else 6)
  rw [baseEq] at basePointer
  rw [validEq] at validPointer
  have baseHeader := header_field_readback memory entry.block (if returns then 3 else 2) _ basePointer
  have validHeader := header_field_readback memory entry.block (if returns then 7 else 6) _ validPointer
  refine ⟨locals.validBlock, locals.baseBlock, 0, 0, ?_, ?_, ?_, ?_, ?_, ?_,
    .inl locals.separate, ?_, ?_⟩
  · cases returns <;> rw [← next] <;> exact validHeader
  · cases returns <;> rw [← next] <;> exact baseHeader
  · exact Nat.lt_of_lt_of_le locals.validOwned bound
  · exact Nat.lt_of_lt_of_le locals.baseOwned bound
  · simpa only [entryEq] using locals.entryValid
  · simpa only [entryEq] using locals.entryBase
  · exact (CC.Mem.validAccess_congr (m1 := memory) (m2 := (allocation initial).2)
      (chunk := .Mint64) (b := locals.baseBlock) (ofs := 0) (p := .Writable)
      (fun ofs => by simp only [CC.Mem.perm, access locals.baseBlock locals.baseOwned])).trans locals.baseWritable
  · exact (CC.Mem.validAccess_congr (m1 := memory) (m2 := (allocation initial).2)
      (chunk := .Mint8unsigned) (b := locals.validBlock) (ofs := 0) (p := .Writable)
      (fun ofs => by simp only [CC.Mem.perm, access locals.validBlock locals.validOwned])).trans locals.validWritable

/-- A framed actual origin outcome yields the complete linked SP reader,
both permission-derived stores, the same producer/register relation and caller
resources. The returned STACK origin is bound to the invocation's native SP.
Availability and production validity of the input frame remain explicit. -/
theorem read_framed {initial before supplied : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (access : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block before.access = CC.PMap.get block (allocation initial).2.access)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cold : Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (trace : CC.Trace) (k : CC.Cont)
    (provider : CC.externalCall Arm64OriginCache.inputEF
      (CC.Genv.toSenv Arm64ProgramEntryAllocation.world.genv_genv)
      [.Vint 1] before trace (.Vlong origins.stack) supplied)
    (outcome : Frame initial false before supplied) :
    ∃ locals : CacheLocals false initial, ∃ middle finished,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
          [.Vptr entry.block 0, .Vlong 32] k before)
        trace (.Returnstate (.Vlong (Reference.AArch64.sp s)) (CC.callCont k) finished) ∧
      CC.Mem.store .Mint64 supplied locals.baseBlock 0 (.Vlong origins.stack) = some middle ∧
      CC.Mem.store .Mint8unsigned middle locals.validBlock 0 (.Vint 1) = some finished ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock finished (.Vptr entry.block 0) origins.stack ∧
      Frame initial false before finished ∧
      Nonempty (Storage initial finished entry) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock finished (.Vptr entry.block 0) s := by
  have observed := header_borrowed_readback before entry.block 5 .Mint64 storage.sp.block 0 _
    storage.spPointer storage.spRead
  obtain ⟨offset, offsetRead, nativeSP⟩ := represented.sp
  have same : offset = storage.spValue := CC.Val.Vlong.inj (Option.some.inj (offsetRead.symm.trans observed))
  rw [same] at nativeSP
  have suppliedPointers : ∀ i, CC.Mem.load CC.Mptr supplied entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0) := fun i =>
    (outcome.local_load _ _ _ entry.binding (header_other false).1 (header_other false).2 CC.Mptr _).trans (pointers i)
  obtain ⟨locals⟩ := cache_locals false initial
  have suppliedAccess : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block supplied.access = CC.PMap.get block (allocation initial).2.access := by
    intro block owned
    exact (congrArg (CC.PMap.get block) outcome.access).trans (access block owned)
  let cache := cache_storage false initial supplied before.nextblock entry header locals
    suppliedAccess outcome.nextblock bound suppliedPointers
  obtain ⟨middle, finished, run, storeBase, storeValid, warm, finalAccess, finalNext⟩ :=
    Arm64ProgramEntryColdRead.read_cold before.nextblock entry.block 0 before supplied k
      storage.spValue origins.stack trace observed cold provider cache
  change CC.Mem.store .Mint64 supplied locals.baseBlock 0 (.Vlong origins.stack) = some middle at storeBase
  change CC.Mem.store .Mint8unsigned middle locals.validBlock 0 (.Vint 1) = some finished at storeValid
  have total := outcome.trans (stores_frame locals origins.stack storeBase storeValid)
  refine ⟨locals, middle, finished, ?_, storeBase, storeValid, warm, total,
    ⟨total.storage storage⟩, total.represents storage represented⟩
  simpa only [nativeSP] using run

end KProgFormal.ClightRefinement.Arm64ProgramEntryCacheFrame
