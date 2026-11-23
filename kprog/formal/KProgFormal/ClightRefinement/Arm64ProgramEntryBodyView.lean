import KProgFormal.ClightRefinement.Arm64ProgramEntryBody
import KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterView
import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryBody (flagName flagBits contextIndex contextOffset setupTemps afterSetup)
open Arm64ProgramEntryAllocation (world)

private theorem header_other : Arm64Entry._entry ≠ Arm64Entry.___a64_sp ∧
    ∀ i : Fin 4, Arm64Entry._entry ≠ flagName i := by decide +kernel
private theorem table_other : ∀ tags, tableName tags ≠ Arm64Entry.___a64_sp ∧
    ∀ i : Fin 4, tableName tags ≠ flagName i := by decide +kernel
private theorem cell_other : ∀ tags (j : Fin 31), tableCellName tags j ≠ Arm64Entry.___a64_sp ∧
    ∀ i : Fin 4, tableCellName tags j ≠ flagName i := by decide +kernel
private theorem vector_other : Arm64Entry.___a64_vectors ≠ Arm64Entry.___a64_sp ∧
    ∀ i : Fin 4, Arm64Entry.___a64_vectors ≠ flagName i := by decide +kernel
private theorem flag_metadata : ∀ i : Fin 4,
    headerSourceName (flagIndex i) = flagName i ∧ headerSourceType (flagIndex i) = CC.tuchar := by
  decide +kernel

/-- Effects of the actual setup, expressed through the same previously reached
storage. No post-state storage or architectural relation is assumed. -/
structure Result {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (le : CC.TempEnv) (k : CC.Cont)
    (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (values : Fin 3 → BitVec 32)
    (after : CC.Mem) : Prop where
  run : InternalRun world 27
    (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySource.body
      k (Arm64ProgramEntryAllocation.allocation initial).1 le before)
    (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup
      k (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps le values) after)
  sp : CC.Mem.load .Mint64 after storage.sp.block 0 = some (.Vlong (BitVec.ofInt 64 (-32)))
  flags : ∀ i, CC.Mem.load .Mint8unsigned after (storage.flags i).block 0 =
    some (.Vint (flagBits i (values (contextIndex i))))
  local_load : ∀ id ty block, (allocation initial).1.get id = some (block, ty) →
    id ≠ Arm64Entry.___a64_sp → (∀ i, id ≠ flagName i) → ∀ chunk ofs,
    CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs
  frame : FrameBelow initial.nextblock initial after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock
  ctx : (setupTemps le values).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs)
  context : ∀ i, CC.Mem.loadv .Mint32 after (.Vptr ctxBlock
    (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (values i))

/-- Bind the actual store results to existing SP/flag locals by allocation
lookup uniqueness, retaining every execution and caller-resource fact. -/
theorem setup {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (le : CC.TempEnv) (k : CC.Cont)
    (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (values : Fin 3 → BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (caller : FrameBelow initial.nextblock initial before)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (values i)))
    (access : before.access = (allocation initial).2.access) :
    ∃ after, Result storage le k ctxBlock ctxOfs values after := by
  obtain ⟨spBlock, blocks, after, spBinding, flagBindings, run, spRead, flagReads,
    locals, frame, finalAccess, next, finalCtx, finalReads⟩ :=
    Arm64ProgramEntryBody.setup initial before le k ctxBlock ctxOfs values ctx old caller reads access
  have spSame : storage.sp.block = spBlock :=
    congrArg Prod.fst (Option.some.inj (storage.sp.binding.symm.trans spBinding))
  have flagsSame : ∀ i, (storage.flags i).block = blocks i := by
    intro i
    have bound := (storage.flags i).binding
    rw [(flag_metadata i).1, (flag_metadata i).2] at bound
    exact congrArg Prod.fst (Option.some.inj (bound.symm.trans (flagBindings i)))
  refine ⟨after, run, ?_, ?_, locals, frame, finalAccess, next, finalCtx, finalReads⟩
  · simpa only [spSame] using spRead
  · intro i; simpa only [flagsSame i] using flagReads i

/-- Rebuild the same live storage after the five actual writes. All pointer
walks and cell permissions are derived from the local frame/access equation. -/
def Result.storage {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {le k ctxBlock ctxOfs values}
    (result : Result storage le k ctxBlock ctxOfs values after) : Storage initial after entry where
  tables := storage.tables
  roots := fun tags => (result.local_load _ _ _ entry.binding header_other.1 header_other.2
    CC.Mptr _).trans (storage.roots tags)
  slots := fun tags j => (result.local_load _ _ _ (storage.tables tags).binding
    (table_other tags).1 (table_other tags).2 CC.Mptr _).trans (storage.slots tags j)
  writable := fun tags j => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (chunk := cellChunk tags) (b := (storage.tables tags).cellBlock j) (ofs := 0) (p := .Writable)
    (fun offset => by simp only [CC.Mem.perm, result.access])).trans (storage.writable tags j)
  sp := storage.sp
  spPointer := (result.local_load _ _ _ entry.binding header_other.1 header_other.2
    CC.Mptr 40).trans storage.spPointer
  spValue := BitVec.ofInt 64 (-32)
  spRead := result.sp
  flags := storage.flags
  flagPointers := fun i => (result.local_load _ _ _ entry.binding header_other.1 header_other.2
    CC.Mptr _).trans (storage.flagPointers i)
  flagWritable := fun flag =>
    (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (chunk := .Mint8unsigned) (b := (storage.flags flag).block) (ofs := 0) (p := .Writable)
      (fun ofs => by simp only [CC.Mem.perm, result.access])).trans (storage.flagWritable flag)
  vectors := storage.vectors
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,result.access])).trans storage.vectorWritable
  vectorPointers := fun high j => (result.local_load _ _ _ entry.binding header_other.1 header_other.2
    CC.Mptr _).trans (storage.vectorPointers high j)

/-- The complete GPR pointer walk and both cell loads survive unchanged,
including refused/undefined observations; the reader frontier is retained. -/
theorem Result.gpr {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {le k ctxBlock ctxOfs values}
    (result : Result storage le k ctxBlock ctxOfs values after) (j : Fin 31) :
    Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) j.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [← result.nextblock, Arm64RegisterWrite.storage_gpr result.storage,
    result.nextblock, Arm64RegisterWrite.storage_gpr storage]
  change (do let word ← CC.Mem.load .Mint64 after ((storage.tables false).cellBlock j) 0
             let tag ← CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock j) 0
             pure (word, tag)) = _
  rw [result.local_load _ _ _ ((storage.tables false).cellBinding j)
        (cell_other false j).1 (cell_other false j).2 .Mint64 0,
      result.local_load _ _ _ ((storage.tables true).cellBinding j)
        (cell_other true j).1 (cell_other true j).2 .Mint8unsigned 0]

/-- The same actual vector array and all 64 pointer slots retain their reads. -/
theorem Result.vector {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {le k ctxBlock ctxOfs values}
    (result : Result storage le k ctxBlock ctxOfs values after) (j : Fin 32) :
    Arm64EntryMemory.vector before.nextblock after (.Vptr entry.block 0) j =
      Arm64EntryMemory.vector before.nextblock before (.Vptr entry.block 0) j := by
  rw [← result.nextblock, Arm64RegisterWrite.storage_vector result.storage,
    result.nextblock, Arm64RegisterWrite.storage_vector storage]
  change (do let lo ← CC.Mem.load .Mint64 after storage.vectors.block
               (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false j))
             let hi ← CC.Mem.load .Mint64 after storage.vectors.block
               (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true j))
             pure (lo, hi)) = _
  rw [result.local_load _ _ _ storage.vectors.binding vector_other.1 vector_other.2
        .Mint64 (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false j)),
      result.local_load _ _ _ storage.vectors.binding vector_other.1 vector_other.2
        .Mint64 (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true j))]

/-- SP is observed through the original signed-long pointer field. -/
theorem Result.sp_read {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {le k ctxBlock ctxOfs values}
    (result : Result storage le k ctxBlock ctxOfs values after) :
    Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp =
      some (.Vlong (BitVec.ofInt 64 (-32))) := by
  rw [← result.nextblock]
  exact header_borrowed_readback after entry.block 5 .Mint64 storage.sp.block 0 _
    result.storage.spPointer result.sp

/-- Each actual flag byte is observed through its existing borrowed pointer. -/
theorem Result.flag_read {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {le k ctxBlock ctxOfs values}
    (result : Result storage le k ctxBlock ctxOfs values after) (i : Fin 4) :
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (headerField (flagIndex i)) = some (.Vint (flagBits i (values (contextIndex i)))) := by
  rw [← result.nextblock]
  exact header_borrowed_readback after entry.block (flagIndex i) .Mint8unsigned
    (storage.flags i).block 0 _ (result.storage.flagPointers i) (result.flags i)

/-- The native input view is updated through LNSym's public register/flag
writes. This binding does not claim execution of a native setup instruction. -/
def nativeSetup (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (values : Fin 3 → BitVec 32) : Reference.AArch64.State :=
  let flags := make_pstate ((values 0).setWidth 1) ((values 1).setWidth 1)
    ((values 2).setWidth 1) ((values 2 >>> 1).setWidth 1)
  let machine := w (.GPR 31) (BitVec.ofInt 64 (-32) + origins.stack) s.machine
  { s with machine := write_pstate flags machine }

private theorem gpr_not_sp : ∀ i : Fin 31, BitVec.ofNat 5 i.val ≠ (31#5) := by decide +kernel

/-- Every other external state field retains its original observation. -/
theorem native_other (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (values : Fin 3 → BitVec 32) (field : StateField) (notSP : field ≠ .GPR 31)
    (notFlag : ∀ flag, field ≠ .FLAG flag) :
    r field (nativeSetup s origins values).machine = r field s.machine := by
  simp only [nativeSetup, write_pstate, make_pstate]
  rw [r_of_w_different (notFlag .V), r_of_w_different (notFlag .C),
    r_of_w_different (notFlag .Z), r_of_w_different (notFlag .N), r_of_w_different notSP]

theorem native_gpr (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (values : Fin 3 → BitVec 32) (i : Fin 31) :
    Reference.AArch64.gpr (nativeSetup s origins values) i = Reference.AArch64.gpr s i := by
  exact native_other s origins values _
    (fun equal => gpr_not_sp i (StateField.GPR.inj equal)) (by intro flag equal; cases equal)

theorem native_sp (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (values : Fin 3 → BitVec 32) :
    Reference.AArch64.sp (nativeSetup s origins values) = BitVec.ofInt 64 (-32) + origins.stack := by
  simp [nativeSetup, Reference.AArch64.sp, write_pstate, make_pstate,
    r_of_w_different, r_of_w_same]

theorem native_vector (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (values : Fin 3 → BitVec 32) (i : Fin 32) :
    Reference.AArch64.readVector (nativeSetup s origins values) i = Reference.AArch64.readVector s i := by
  exact native_other s origins values _ (by intro equal; cases equal)
    (by intro flag equal; cases equal)

/-- Memory, program, access/event inputs and the unmodeled flag bits stay with
the original external machine. The input-view update executes no memory step. -/
theorem native_resources (s : Reference.AArch64.State)
    (origins : Reference.Provenance.AArch64.Origins) (values : Fin 3 → BitVec 32) :
    let changed := nativeSetup s origins values
    changed.machine.mem = s.machine.mem ∧ changed.machine.program = s.machine.program ∧
    changed.machine.memoryProfile = s.machine.memoryProfile ∧
    changed.machine.memoryAccesses = s.machine.memoryAccesses ∧
    changed.machine.atomicAccesses = s.machine.atomicAccesses ∧
    changed.machine.exclusive = s.machine.exclusive ∧
    changed.machine.threadPointerInputs = s.machine.threadPointerInputs ∧
    changed.extraFlags = s.extraFlags := by
  simp [nativeSetup, write_pstate, make_pstate, w, write_base_gpr, write_base_flag]

private theorem low_bit (value : BitVec 32) :
    (value.setWidth 1).setWidth 32 = value &&& (1#32) := by
  have masked := (BitVec.and_setWidth_allOnes 31 1 value).symm
  rw [BitVec.setWidth_eq_append (v := 1) (w := 32) (by decide)]
  exact masked

theorem native_flag_values (s : Reference.AArch64.State)
    (origins : Reference.Provenance.AArch64.Origins) (values : Fin 3 → BitVec 32) :
    ∀ i : Fin 4, flagValues (nativeSetup s origins values) i =
      .Vint (flagBits i (values (contextIndex i))) := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  refine ⟨?_, ?_, ?_, ?_, trivial⟩ <;>
    simp +decide [flagValues, nativeSetup, write_pstate, make_pstate, read_flag,
      r_of_w_different, r_of_w_same, low_bit, flagBits, contextIndex] <;> rfl

/-- The same actual setup result transports the complete register relation.
Native memory, input ABI and instruction admission remain explicit obligations. -/
theorem Result.represents {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {le k ctxBlock ctxOfs values}
    (result : Result storage le k ctxBlock ctxOfs values after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) (nativeSetup s origins values) := by
  refine ⟨?_, ⟨BitVec.ofInt 64 (-32), result.sp_read, native_sp s origins values⟩, ?_, ?_⟩
  · intro i
    obtain ⟨value, raw, tag, read, word, native⟩ := represented.gpr i
    exact ⟨value, raw, tag, (result.gpr i).trans read, word,
      (native_gpr s origins values i).trans native⟩
  · intro i
    rw [result.vector, native_vector]
    exact represented.vectors i
  · have n := result.flag_read 0
    have z := result.flag_read 1
    have c := result.flag_read 2
    have v := result.flag_read 3
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._n = some (.Vint (flagBits 0 (values 0))) at n
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._z = some (.Vint (flagBits 1 (values 1))) at z
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._c = some (.Vint (flagBits 2 (values 2))) at c
    change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      Arm64Program._v = some (.Vint (flagBits 3 (values 2))) at v
    have nn := native_flag_values s origins values 0
    have nz := native_flag_values s origins values 1
    have nc := native_flag_values s origins values 2
    have nv := native_flag_values s origins values 3
    change CC.Val.Vint ((read_flag .N (nativeSetup s origins values).machine).setWidth 32) = _ at nn
    change CC.Val.Vint ((read_flag .Z (nativeSetup s origins values).machine).setWidth 32) = _ at nz
    change CC.Val.Vint ((read_flag .C (nativeSetup s origins values).machine).setWidth 32) = _ at nc
    change CC.Val.Vint ((read_flag .V (nativeSetup s origins values).machine).setWidth 32) = _ at nv
    simp only [Arm64Nop.FlagsRepresent, Arm64EntryMemory.flags, n, z, c, v, nn, nz, nc, nv]
    rfl

/-- Compose the real setup execution and derived storage effects with the
preexisting architectural relation, without a post-relation premise. -/
theorem setup_represents {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (le : CC.TempEnv) (k : CC.Cont)
    (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (values : Fin 3 → BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (caller : FrameBelow initial.nextblock initial before)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (values i)))
    (access : before.access = (allocation initial).2.access)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, Result storage le k ctxBlock ctxOfs values after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeSetup s origins values) := by
  obtain ⟨after, result⟩ := setup storage le k ctxBlock ctxOfs values ctx old caller reads access
  exact ⟨after, result, result.represents addresses origins s represented⟩

/-- From the actual wrapper call, retain all98 provider traces and append
the real setup to the same initialized memory. Context fields are read from
the original caller object, independently of the provider outcomes. -/
theorem entry_setup_represents (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses (.Vptr ctxBlock ctxOfs) ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : Arm64ProgramEntryRegisterView.NativeBindings origins ctxWord values flags vectors s)
    (fields : Fin 3 → BitVec 32) (old : ctxBlock.toNat < initial.nextblock.toNat)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (fields i))) :
    ∃ entry : HeaderLocal initial, ∃ cells : (i : Fin 12) → HeaderSourceLocal initial i,
    ∃ sources : (i : Fin 9) → TailLocal initial i, ∃ localVector : VectorLocal initial,
    ∃ before temps after, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup
          k (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
        some (.Vptr (cells i).block 0)) ∧
      (∀ high (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) =
        some (Arm64ProgramEntryTail.actualValue sources i)) ∧
      ∃ storage : Storage initial before entry,
        Result storage temps k ctxBlock ctxOfs fields after ∧
        Arm64Registers.Represents addresses origins (fun r => r.val)
          before.nextblock after (.Vptr entry.block 0) (nativeSetup s origins fields) ∧
        Arm64ProgramEntryResources.Resources initial after entry ∧
        Nonempty (Arm64ProgramEntryInitialized.Values initial before (.Vptr ctxBlock ctxOfs)
          values flags vectors) ∧
        after.access = (Arm64Producer.allocation initial).2.access ∧
        before.nextblock = (Arm64ProgramEntryAllocation.allocation initial).2.nextblock := by
  obtain ⟨entry, cells, sources, localVector, before, temps, traces, length, run,
    index, ctx, pointers, vectorPointers, tailReads, data, registers, ⟨storage⟩,
    resources, frame, access, next⟩ :=
    Arm64ProgramEntryRegisterView.entry_represents initial (.Vptr ctxBlock ctxOfs) k
      addresses ctxWord context values provider flags flagProvider vectors vectorProvider origins s native
  have sourceAccess : before.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨after, result, finalRegisters⟩ := setup_represents storage temps k ctxBlock ctxOfs fields
    ctx old frame reads sourceAccess addresses origins s registers
  refine ⟨entry, cells, sources, localVector, before, temps, after, traces, length,
    ?_, ?_, ?_, ?_, storage, result, finalRegisters, ?_, data, result.access.trans sourceAccess, next⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans run result.run.sound
  · intro i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 CC.Mptr _).trans (pointers i)
  · intro high i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 CC.Mptr _).trans (vectorPointers high i)
  · intro i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 (tailChunk i) _).trans (tailReads i)
  · apply Arm64ProgramEntryResources.resources initial after entry cells (result.access.trans sourceAccess)
    intro i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 CC.Mptr _).trans (pointers i)

end KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView
