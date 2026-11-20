import KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView
import KProgFormal.ClightRefinement.Arm64MovKeepLinked

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryColdRead

open Arm64Producer Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBodyView (Result)
open Arm64RegisterReads

/-- The actual linked header supplies precisely the STACK/cache layouts. -/
theorem stack_layout : StackLayout world :=
  ⟨by decide +kernel, by decide +kernel, by decide +kernel, by decide +kernel⟩

/-- Resolve the existing external declaration at its actual linked block. -/
theorem input_binding :
    CC.Genv.findSymbol world.genv_genv Arm64Program._native_lab_entry_input = some (CC.Positive.ofNat 59) ∧
    CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 59) = some Arm64OriginCache.inputFunction :=
  Arm64ProgramEntryLinked.input_binding

private theorem cache_other : ∀ returns,
    (baseName returns ≠ Arm64Entry.___a64_sp ∧ ∀ i : Fin 4, baseName returns ≠ Arm64ProgramEntryBody.flagName i) ∧
    (validName returns ≠ Arm64Entry.___a64_sp ∧ ∀ i : Fin 4, validName returns ≠ Arm64ProgramEntryBody.flagName i) := by
  decide +kernel

/-- Both actual caches remain cold through SP/NZCV setup. The zero bytes and
bases come from the reached initializer, not new warm/cold assumptions. -/
theorem cold_cache_reads {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {le k ctxBlock ctxOfs fields}
    (result : Result storage le k ctxBlock ctxOfs fields after)
    {values flags vectors}
    (data : Arm64ProgramEntryInitialized.Values initial before (.Vptr ctxBlock ctxOfs) values flags vectors)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0)) :
    ∀ returns : Bool,
      Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0)
        (if returns then Arm64Program._return_base else Arm64Program._sp_base) = some (.Vlong 0) ∧
      Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
        (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) = some (.Vint 0) := by
  intro returns
  obtain ⟨locals, _, _, baseRead, validRead⟩ := data.cacheReads returns
  change CC.Mem.load .Mint64 before locals.baseBlock 0 = some (.Vlong 0) at baseRead
  change CC.Mem.load .Mint8unsigned before locals.validBlock 0 = some (.Vint 0) at validRead
  have baseAfter := (result.local_load _ _ _ locals.baseBinding
    (cache_other returns).1.1 (cache_other returns).1.2 .Mint64 0).trans baseRead
  have validAfter := (result.local_load _ _ _ locals.validBinding
    (cache_other returns).2.1 (cache_other returns).2.2 .Mint8unsigned 0).trans validRead
  have baseSame : (header (if returns then 3 else 2)).block = locals.baseBlock := by
    cases returns
    · exact congrArg Prod.fst (Option.some.inj ((header 2).binding.symm.trans locals.baseBinding))
    · exact congrArg Prod.fst (Option.some.inj ((header 3).binding.symm.trans locals.baseBinding))
  have validSame : (header (if returns then 7 else 6)).block = locals.validBlock := by
    cases returns
    · exact congrArg Prod.fst (Option.some.inj ((header 6).binding.symm.trans locals.validBinding))
    · exact congrArg Prod.fst (Option.some.inj ((header 7).binding.symm.trans locals.validBinding))
  have basePointer := pointers (if returns then 3 else 2)
  have validPointer := pointers (if returns then 7 else 6)
  rw [baseSame] at basePointer
  rw [validSame] at validPointer
  have base := header_borrowed_readback after entry.block (if returns then 3 else 2)
    .Mint64 locals.baseBlock 0 (.Vlong 0) basePointer baseAfter
  have valid := header_borrowed_readback after entry.block (if returns then 7 else 6)
    .Mint8unsigned locals.validBlock 0 (.Vint 0) validPointer validAfter
  cases returns <;> rw [← result.nextblock] <;> exact ⟨base, valid⟩

/-- The existing reader body executes in the actual linked world, retaining
the supplied external outcome and deriving both cache stores from permissions. -/
theorem read_cold (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (before supplied : CC.Mem) (k : CC.Cont) (offset base : BitVec 64) (trace : CC.Trace)
    (observed : Arm64EntryMemory.borrowed frontier .Mint64 before (.Vptr b ofs)
      Arm64Program._sp = some (.Vlong offset))
    (cold : Arm64EntryMemory.borrowed frontier .Mint8unsigned before (.Vptr b ofs)
      Arm64Program._sp_valid = some (.Vint 0))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint 1] before trace (.Vlong base) supplied)
    (storage : BorrowedCacheStorage false frontier b ofs supplied) :
    ∃ middle after,
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong 32] k before)
        trace (.Returnstate (.Vlong (offset + base)) (CC.callCont k) after) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr storage.baseBlock storage.baseOffset) (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr storage.validBlock storage.validOffset) (.Vint 1) = some after ∧
      WarmEntryCache false frontier after (.Vptr b ofs) base ∧
      after.access = supplied.access ∧ after.nextblock = supplied.nextblock :=
  sp_read_cold_bound world stack_layout (CC.Positive.ofNat 59) input_binding frontier b ofs
    before supplied k offset base trace observed cold provider storage

/-- The reached setup feeds the real cold SP32 reader. Its relative SP is
read before the provider; provider purity and post-provider storage are separate. -/
theorem setup_read_cold {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {le setupK ctxBlock ctxOfs fields}
    (result : Result storage le setupK ctxBlock ctxOfs fields after)
    {values flags vectors}
    (data : Arm64ProgramEntryInitialized.Values initial before (.Vptr ctxBlock ctxOfs) values flags vectors)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (supplied : CC.Mem) (k : CC.Cont) (base : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint 1] after trace (.Vlong base) supplied)
    (cache : BorrowedCacheStorage false before.nextblock entry.block 0 supplied) :
    ∃ middle finished,
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr entry.block 0, .Vlong 32] k after)
        trace (.Returnstate (.Vlong (BitVec.ofInt 64 (-32) + base)) (CC.callCont k) finished) ∧
      CC.Mem.storev .Mint64 supplied (.Vptr cache.baseBlock cache.baseOffset) (.Vlong base) = some middle ∧
      CC.Mem.storev .Mint8unsigned middle (.Vptr cache.validBlock cache.validOffset) (.Vint 1) = some finished ∧
      WarmEntryCache false before.nextblock finished (.Vptr entry.block 0) base ∧
      finished.access = supplied.access ∧ finished.nextblock = supplied.nextblock :=
  read_cold before.nextblock entry.block 0 after supplied k (BitVec.ofInt 64 (-32)) base trace
    result.sp_read (cold_cache_reads result data header pointers false).2 provider cache

end KProgFormal.ClightRefinement.Arm64ProgramEntryColdRead
