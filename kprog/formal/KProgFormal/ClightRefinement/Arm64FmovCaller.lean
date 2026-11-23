import KProgFormal.ClightRefinement.Arm64FmovCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Call

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)

/-- All finite executions are silent prefixes of the same real freed-frame
return; the stuck endpoint is unique and infinite execution is excluded. -/
theorem Result.all_behaviors {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial before entry} {value : BitVec 64}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {native : Reference.AArch64.State} {count : Nat} {finalStorage : Storage initial after entry}
    (result : Result old value addresses origins native .Kstop count written after finalStorage) :
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntryFmovCall.arguments entry.block) .Kstop before) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun world remaining other (.Returnstate .Vundef .Kstop after)) ∧
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntryFmovCall.arguments entry.block) .Kstop before) t other →
      (∀ u next, ¬ CC.Step2 world other u next) →
      t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntryFmovCall.arguments entry.block) .Kstop before ∧
      ∀ j, ∃ t, CC.Step2 world (states j) t (states (j+1))) := by
  have stuck : ∀ t next, ¬ CC.Step2 world (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => result.run.finish_prefix stuck observed,
    fun _ _ observed endpoint => result.run.endpoint_unique stuck observed endpoint,
    result.run.no_infinite stuck⟩

/-- Execute the true tenth source call after ORN and resume afterFmov,
including the real generic allocation, both stores, release and return. -/
theorem returned {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (writable : Arm64VectorWritable.Writable old.vectors before) (oldLow value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (oldVector : CC.Mem.load .Mint64 before old.vectors.block 48 = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 before ((old.tables false).cellBlock 7) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned before ((old.tables true).cellBlock 7) 0 = some (.Vint 0))
    (decoded : instruction.decoded = .DPSFP (.Conversion_between_FP_and_Int Native.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count written after, ∃ finalStorage : Storage initial after entry,
      Result old value addresses origins native (Arm64ProgramEntryFmovCall.callCont initial le k)
        count written after finalStorage ∧
      InternalRun world (2 + count + 2)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrnCall.afterOrn k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryFmovCall.afterFmov k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) := by
  obtain ⟨count,written,after,finalStorage,result⟩ := execute old bound writable oldLow value
    addresses origins native instruction represented oldVector word tag decoded noError fetched
    (Arm64ProgramEntryFmovCall.callCont initial le k) rfl
  exact ⟨count,written,after,finalStorage,result,
    ((Arm64ProgramEntryFmovCall.enter entry le k before).trans result.run).trans
      (Arm64ProgramEntryFmovCall.leave initial le k after)⟩

end KProgFormal.ClightRefinement.Arm64Fmov.Call
