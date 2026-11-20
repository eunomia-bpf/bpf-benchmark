import KProgFormal.ClightRefinement.Arm64ProgramEntryInitialized

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterView

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryInitialized (Values)
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal VectorLocal)
open Arm64ProducerEntryView (flagIndex flagValues)
open Arm64EntryAdmissibility (rawValue rawWord rawTag)

/-- The actual input ABI enumerates low/high words consecutively. -/
def vectorIndex (high : Bool) (i : Fin 32) : Fin 64 :=
  ⟨2 * i.val + (if high then 1 else 0), by cases high <;> have := i.isLt <;> simp_all <;> omega⟩

theorem vector_offset (high : Bool) (i : Fin 32) :
    8 * ((vectorIndex high i).val : Int) = 16 * (i.val : Int) + (if high then 8 else 0) := by
  cases high <;> simp only [vectorIndex, Bool.false_eq_true, ite_false, ite_true] <;> omega

/-- The actual stored32-bit tags are exactly the existing byte-tag view. -/
theorem tag_width (i : Fin 31) :
    Arm64ProgramEntryRawSetup.tagWord i = (rawTag i).setWidth 32 := by
  by_cases zero : i = 0 <;> by_cases lr : i = 30 <;>
    simp [Arm64ProgramEntryRawSetup.tagWord, rawTag, zero, lr]

private theorem flag_metadata : ∀ i : Fin 4,
    (Arm64ProgramEntryFlags.declaration i).name = Arm64Producer.headerSourceName (flagIndex i) ∧
    Arm64Producer.headerSourceType (flagIndex i) = CC.tuchar := by decide +kernel

/-- Read the reached flag bytes by canonical typed local identity. -/
theorem flag_loads {initial memory : CC.Mem} {ctx values flags vectors}
    (data : Values initial memory ctx values flags vectors)
    (header : (i : Fin 12) → HeaderSourceLocal initial i) :
    ∀ i, CC.Mem.load .Mint8unsigned memory (header (flagIndex i)).block 0 =
      some (.Vint (Arm64Producer.flagWord (flags i))) := by
  obtain ⟨blocks, _, bindings, _, _, _, reads, _⟩ := data.flagReads
  intro i
  have bound := bindings i
  rw [(flag_metadata i).1] at bound
  have headerBound := (header (flagIndex i)).binding
  rw [(flag_metadata i).2] at headerBound
  have same : (header (flagIndex i)).block = blocks i :=
    congrArg Prod.fst (Option.some.inj (headerBound.symm.trans bound))
  rw [same]
  exact reads i

/-- SP0 is read through the actual header pointer; it is not a native SP
assumption or a newly constructed store. -/
theorem sp_read {initial memory : CC.Mem} {ctx values flags vectors}
    (data : Values initial memory ctx values flags vectors)
    (entry : HeaderLocal initial) (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0)) :
    Arm64EntryMemory.borrowed memory.nextblock .Mint64 memory (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong 0) := by
  obtain ⟨_, block, _, _, bound, _, _, _, read, _⟩ := data.rawReads
  have same : (header 5).block = block :=
    congrArg Prod.fst (Option.some.inj ((header 5).binding.symm.trans bound))
  have actual : CC.Mem.load .Mint64 memory (header 5).block 0 = some (.Vlong 0) := by
    rw [same]
    exact read
  exact Arm64ProducerEntryView.header_borrowed_readback memory entry.block 5
    .Mint64 (header 5).block 0 (.Vlong 0) (pointers 5) actual

/-- Both vector halves are obtained from the initialized64-word data array
and the same reached pointer arrays. The source index/offset is derived. -/
theorem vector_reads {initial memory : CC.Mem} {ctx values flags vectors}
    (data : Values initial memory ctx values flags vectors)
    (entry : HeaderLocal initial) (localVector : VectorLocal initial)
    (pointers : ∀ high (i : Fin 32), CC.Mem.load CC.Mptr memory entry.block
      ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (Arm64Producer.vectorLoopSourceOffset high i))) :
    ∀ i, Arm64EntryMemory.vector memory.nextblock memory (.Vptr entry.block 0) i =
      some (.Vlong (vectors (vectorIndex false i)), .Vlong (vectors (vectorIndex true i))) := by
  obtain ⟨supplied, _, reads⟩ := data.vectorReads
  have same : localVector.block = supplied.block :=
    congrArg Prod.fst (Option.some.inj (localVector.binding.symm.trans supplied.binding))
  apply Arm64ProducerVectorView.vector_readbacks initial memory entry localVector
    (fun high i => .Vlong (vectors (vectorIndex high i))) pointers
  intro high i
  rw [same, ← vector_offset high i]
  exact reads (vectorIndex high i)

/-- Same-invocation ABI data required to match a native architectural state.
The context and RETURN origins, other GPRs, masked flags and vector halves
stay explicit; no register-relation or successful-reader premise is used. -/
structure NativeBindings (origins : Reference.Provenance.AArch64.Origins)
    (ctxWord : BitVec 64) (values : Fin 31 → BitVec 64) (flags : Fin 4 → BitVec 64)
    (vectors : Fin 64 → BitVec 64) (s : Reference.AArch64.State) : Prop where
  context : Reference.AArch64.gpr s 0 = ctxWord
  returns : Reference.AArch64.gpr s 30 = origins.returnAddress
  ordinary : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = values i
  sp : Reference.AArch64.sp s = origins.stack
  nzcv : ∀ i, .Vint (Arm64Producer.flagWord (flags i)) = flagValues s i
  vector : ∀ high i, vectors (vectorIndex high i) = Arm64ProducerVectorView.vectorHalf s high i

/-- Derive the existing full architectural register relation over the actual
body memory. The context's pointer ValueRep is reused; all scalar word and
byte-tag representations, table reads, SP, vectors and flags are derived. -/
theorem represents {initial memory : CC.Mem} {ctx values flags vectors}
    (data : Values initial memory ctx values flags vectors)
    (entry : HeaderLocal initial) (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (localVector : VectorLocal initial)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (vectorPointers : ∀ high (i : Fin 32), CC.Mem.load CC.Mptr memory entry.block
      ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (Arm64Producer.vectorLoopSourceOffset high i)))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctxWord : BitVec 64) (context : Arm64Registers.ValueRep addresses ctx ctxWord)
    (s : Reference.AArch64.State) (native : NativeBindings origins ctxWord values flags vectors s) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) s := by
  have words := Arm64EntryAdmissibility.raw_values_represent addresses ctx ctxWord values context
  have gprs := Arm64EntryAdmissibility.raw_native_registers origins ctxWord values s
    native.context native.returns native.ordinary
  refine ⟨?_, ⟨0, sp_read data entry header pointers, ?_⟩, ?_, ?_⟩
  · intro i
    refine ⟨rawValue ctx values i, rawWord ctxWord values i, rawTag i, ?_, words i, gprs i⟩
    rw [← tag_width]
    exact data.gpr_reads entry header pointers i
  · simpa using native.sp
  · intro i
    have read := vector_reads data entry localVector vectorPointers i
    rw [native.vector false i, native.vector true i] at read
    exact read
  · apply Arm64ProducerEntryView.header_flags_represent memory entry.block (fun i => (header i).block) s pointers
    intro i
    rw [← native.nzcv i]
    exact flag_loads data header i

/-- One actual entry execution carries the architectural register relation
alongside all initialized data, header readbacks, storage, freeable resources,
provider traces and original caller frame. Native ABI/provider admission is
still explicit and no separate source header execution is replayed. -/
theorem entry_represents (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses ctx ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : NativeBindings origins ctxWord values flags vectors s) :
    ∃ entry : HeaderLocal initial, ∃ cells : (i : Fin 12) → HeaderSourceLocal initial i,
    ∃ sources : (i : Fin 9) → TailLocal initial i, ∃ localVector : VectorLocal initial,
    ∃ after finalTemps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySource.body
          k (allocation initial).1 finalTemps after) ∧
      finalTemps.get Arm64Entry._i = some (.Vint 32) ∧
      finalTemps.get Arm64ProgramFixture._ctx = some ctx ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ high (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (Arm64Producer.vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (Arm64Producer.tailChunk i) after entry.block (Arm64Producer.tailOffset i) =
        some (Arm64ProgramEntryTail.actualValue sources i)) ∧
      Nonempty (Values initial after ctx values flags vectors) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0) s ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage initial after entry) ∧
      Arm64ProgramEntryResources.Resources initial after entry ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨entry, header, sources, localVector, after, temps, traces, length, run, index,
      ctxRead, pointers, vectorPointers, tailReads, ⟨data⟩, storage, resources, frame, access, next⟩ :=
    Arm64ProgramEntryInitialized.entry_initialized initial ctx k addresses ctxWord context
      values provider flags flagProvider vectors vectorProvider
  exact ⟨entry, header, sources, localVector, after, temps, traces, length, run, index,
    ctxRead, pointers, vectorPointers, tailReads, ⟨data⟩,
    represents data entry header localVector pointers vectorPointers addresses origins ctxWord context s native,
    storage, resources, frame, access, next⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterView
