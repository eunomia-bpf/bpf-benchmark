import KProgFormal.ClightRefinement.Arm64RegisterWrite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64RegisterWrite

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

private theorem cell_header : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry._entry := by decide +kernel
private theorem cell_table : ∀ tags selected (i : Fin 31),
    tableCellName tags i ≠ tableName selected := by decide +kernel
private theorem cell_sp : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ headerSourceName 5 := by decide +kernel

/-- The actual stores retain the same allocation-bound tables, writable cells
and SP local. No second producer run or new choice of storage is used. -/
def Result.storage {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) : Storage m after entry where
  tables := storage.tables
  roots := fun tags =>
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr _).trans (storage.roots tags)
  slots := fun tags j =>
    (result.local_load _ _ _ (storage.tables tags).binding (cell_table false tags i)
      (cell_table true tags i) CC.Mptr _).trans (storage.slots tags j)
  writable := fun tags j =>
    (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (chunk := cellChunk tags) (b := (storage.tables tags).cellBlock j) (ofs := 0)
      (p := .Writable) (fun offset => by simp only [CC.Mem.perm, result.access])).trans
        (storage.writable tags j)
  sp := storage.sp
  spPointer :=
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr 40).trans storage.spPointer
  spValue := storage.spValue
  spRead :=
    (result.local_load _ _ _ storage.sp.binding (cell_sp false i) (cell_sp true i)
      .Mint64 0).trans storage.spRead
  flags := storage.flags
  flagPointers := fun flag =>
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr _).trans (storage.flagPointers flag)
  flagWritable := fun flag =>
    (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (chunk := .Mint8unsigned) (b := (storage.flags flag).block) (ofs := 0) (p := .Writable)
      (fun ofs => by simp only [CC.Mem.perm, result.access])).trans (storage.flagWritable flag)
  vectors := storage.vectors
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,result.access])).trans storage.vectorWritable
  vectorPointers := fun high j =>
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr _).trans (storage.vectorPointers high j)

/-- Imported Mem permission validity also covers unsuccessful loads: the
checked reader at the real nextblock is exactly the imported load. -/
theorem checked_load_eq (chunk : CC.Chunk) (memory : CC.Mem) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) :
    Arm64EntryMemory.load memory.nextblock chunk memory (.Vptr block offset) =
      CC.Mem.load chunk memory block (CC.Integers.Ptrofs.unsigned offset) := by
  cases read : CC.Mem.load chunk memory block (CC.Integers.Ptrofs.unsigned offset) with
  | none => simp only [Arm64EntryMemory.load, read, ite_self]
  | some value => exact checked_load chunk memory block offset value read

private theorem slot_unsigned : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      8 * (i.val : Int) := by decide +kernel

/-- Collapse only the actual pointer walk. Raw cell values, tags, undefined
values and refused loads retain upstream Mem semantics. -/
theorem storage_gpr {m memory : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m memory entry) (i : Fin 31) :
    Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      (do let word ← CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0
          let tag ← CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0
          pure (word, tag)) := by
  have wordRoot : CC.Mem.load CC.Mptr memory entry.block 0 =
      some (.Vptr (storage.tables false).tableBlock 0) := storage.roots false
  have tagRoot : CC.Mem.load CC.Mptr memory entry.block 8 =
      some (.Vptr (storage.tables true).tableBlock 0) := storage.roots true
  have wordField : Arm64EntryMemory.field memory.nextblock CC.Mptr memory (.Vptr entry.block 0)
      Arm64Program._cells = some (.Vptr (storage.tables false).tableBlock 0) :=
    header_field_readback memory entry.block 0 _ wordRoot
  have tagField : Arm64EntryMemory.field memory.nextblock CC.Mptr memory (.Vptr entry.block 0)
      Arm64Program._tag_cells = some (.Vptr (storage.tables true).tableBlock 0) :=
    header_field_readback memory entry.block 1 _ tagRoot
  have slot (tags : Bool) : Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (.Vptr (storage.tables tags).tableBlock
        (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) =
      some (.Vptr ((storage.tables tags).cellBlock i) 0) := by
    apply checked_load
    simpa only [slot_unsigned i] using storage.slots tags i
  simp only [Arm64EntryMemory.gpr, wordField, tagField, bind, Option.bind_some]
  change (do
    let cell ← Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (.Vptr (storage.tables false).tableBlock
        (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))))
    let tag ← Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (.Vptr (storage.tables true).tableBlock
        (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))))
    let word ← Arm64EntryMemory.load memory.nextblock .Mint64 memory cell
    let kind ← Arm64EntryMemory.load memory.nextblock .Mint8unsigned memory tag
    pure (word, kind)) = _
  have offset : CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      CC.Integers.Ptrofs.repr (8 * (i.val : Int)) := BitVec.zero_add _
  simp only [offset, slot, bind, pure, Option.bind_some, checked_load_eq]
  rfl

/-- One reader equation for the complete GPR bank, including failed or
undefined unselected reads. The established reader frontier stays unchanged. -/
theorem Result.gpr {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) (j : Fin 31) :
    Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) j.val =
      if j = i then some (.Vlong (written narrow value), .Vint 0)
      else Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [← result.nextblock, storage_gpr result.storage j]
  by_cases same : j = i
  · subst j
    simp only [eq_self, ite_true]
    change (do let word ← CC.Mem.load .Mint64 after ((storage.tables false).cellBlock i) 0
               let tag ← CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock i) 0
               pure (word, tag)) = _
    rw [result.word, result.tag]
    rfl
  · rw [ite_eq_right same, result.nextblock, storage_gpr storage j]
    change (do let word ← CC.Mem.load .Mint64 after ((storage.tables false).cellBlock j) 0
               let tag ← CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock j) 0
               pure (word, tag)) = _
    rw [result.other_cell false j same .Mint64 0,
      result.other_cell true j same .Mint8unsigned 0]

/-- SP still follows the actual signed-long producer local, at the same
reader frontier. Its value is unaffected by the ordinary GPR writes. -/
theorem Result.sp {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) :
    Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp =
      Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0) Arm64Program._sp := by
  have initial : Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong storage.spValue) :=
    header_borrowed_readback before entry.block 5 .Mint64 storage.sp.block 0 _ storage.spPointer storage.spRead
  have final : Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong storage.spValue) :=
    header_borrowed_readback after entry.block 5 .Mint64 storage.sp.block 0 _
      result.storage.spPointer result.storage.spRead
  simpa only [result.nextblock] using final.trans initial.symm

/-- The native observation uses LNSym's public register write. It leaves the
rest of the external state, including extra native flags, with that machine. -/
def nativeUpdate (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (narrow : Bool) :
    Reference.AArch64.State :=
  { s with machine := w (.GPR (BitVec.ofNat 5 i.val)) (written narrow value) s.machine }

private theorem register_index_injective : Function.Injective (fun i : Fin 31 => BitVec.ofNat 5 i.val) := by
  intro i j same
  apply Fin.ext
  have index := congrArg BitVec.toNat same
  simp only [BitVec.toNat_ofNat] at index
  rw [Nat.mod_eq_of_lt (by have := i.isLt; omega),
    Nat.mod_eq_of_lt (by have := j.isLt; omega)] at index
  exact index

/-- Pure read-over-write comes from the external machine, not a local ISA law. -/
theorem native_gpr (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (j : Fin 31) :
    Reference.AArch64.gpr (nativeUpdate s i value narrow) j =
      if j = i then written narrow value else Reference.AArch64.gpr s j := by
  by_cases same : j = i
  · subst j
    rw [ite_eq_left rfl]
    exact r_of_w_same
  · rw [ite_eq_right same]
    apply r_of_w_different
    intro equal
    exact same (register_index_injective (StateField.GPR.inj equal))

private theorem ordinary_not_sp : ∀ i : Fin 31,
    (31#5) ≠ BitVec.ofNat 5 i.val := by decide +kernel

/-- Simulator SP32 remains distinct from the external machine's GPR31/SP. -/
theorem native_sp (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (narrow : Bool) :
    Reference.AArch64.sp (nativeUpdate s i value narrow) = Reference.AArch64.sp s := by
  apply r_of_w_different
  intro equal
  exact ordinary_not_sp i (StateField.GPR.inj equal)

/-- Every GPR observation of the actual writer agrees with the mature native
write. The identity cell map is explicit; no arbitrary map is assumed injective.
This GPR-bank law is not a complete instruction or non-GPR frame theorem. -/
theorem Result.gpr_update {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) (j : Reference.AArch64.Gpr) :
    ∃ word raw tag,
      Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) j.val =
        some (word, .Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses word raw ∧
      Reference.AArch64.gpr (nativeUpdate s i value narrow) j =
        Reference.Provenance.AArch64.materialize origins raw tag := by
  by_cases same : j = i
  · subst j
    refine ⟨.Vlong (written narrow value), written narrow value, (0 : BitVec 8), ?_, rfl, ?_⟩
    · change Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) i.val =
        some (.Vlong (written narrow value), .Vint 0)
      simpa only [eq_self, ite_true] using result.gpr i
    · rw [native_gpr, ite_eq_left rfl]
      rfl
  · obtain ⟨word, raw, tag, read, bits, native⟩ := represented.gpr j
    refine ⟨word, raw, tag, ?_, bits, ?_⟩
    · rw [result.gpr, ite_eq_right same]
      exact read
    · rw [native_gpr, ite_eq_right same]
      exact native

/-- The existing SP representation survives the same actual procedure result
and agrees with the external machine's unchanged SP. -/
theorem Result.sp_update {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ offset, Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong offset) ∧
      Reference.AArch64.sp (nativeUpdate s i value narrow) = offset + origins.stack := by
  simp only [result.sp, native_sp]
  exact represented.sp

end KProgFormal.ClightRefinement.Arm64RegisterWrite
