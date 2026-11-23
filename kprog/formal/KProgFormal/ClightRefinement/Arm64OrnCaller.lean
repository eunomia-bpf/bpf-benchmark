import KProgFormal.ClightRefinement.Arm64OrnCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Orn.Call

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)

/-- Every finite relational execution is a silent prefix of the same actual
freed-frame return. Its endpoint is unique and infinite execution is excluded;
no external-call determinism or already-silent candidate trace is assumed. -/
theorem Result.all_behaviors {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {native : Reference.AArch64.State}
    {count : Nat}
    {finalStorage : Storage initial after entry}
    (result : Result storage addresses origins native .Kstop count written after finalStorage) :
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntryOrnCall.arguments entry.block) .Kstop before) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun world remaining other (.Returnstate .Vundef .Kstop after)) ∧
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntryOrnCall.arguments entry.block) .Kstop before) t other →
      (∀ u next, ¬ CC.Step2 world other u next) →
      t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntryOrnCall.arguments entry.block) .Kstop before ∧
      ∀ j, ∃ t, CC.Step2 world (states j) t (states (j+1))) := by
  have stuck : ∀ t next, ¬ CC.Step2 world (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => result.run.finish_prefix stuck observed,
    fun _ _ observed endpoint => result.run.endpoint_unique stuck observed endpoint,
    result.run.no_infinite stuck⟩

/-- Execute the true ninth source call after CNEG and resume its original
successor, retaining the fixture environment and temporaries. The generic
call certificate derives allocation, source stores, free and native agreement. -/
theorem returned {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (raw : BitVec 64) (tag : BitVec 8) (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 6 =
      some (.Vlong raw, .Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false before.nextblock before
      (.Vptr entry.block 0) origins.stack)
    (rhsValue : BitVec 64)
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 3) 0 = some (.Vlong rhsValue))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 3) 0 = some (.Vint 0))
    (decoded : instruction.decoded = .DPR (.Logical_shifted_reg Native.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count written after, ∃ finalStorage : Storage initial after entry,
      Result storage addresses origins native (Arm64ProgramEntryOrnCall.callCont initial le k)
        count written after finalStorage ∧
      InternalRun world (2 + count + 2)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCnegCall.afterCneg k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrnCall.afterOrn k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) := by
  obtain ⟨count, written, after, finalStorage, result⟩ := execute storage bound header pointers
    addresses origins native instruction represented raw tag tags observed cache rhsValue rhsWord rhsTag decoded noError fetched
    (Arm64ProgramEntryOrnCall.callCont initial le k) rfl
  exact ⟨count, written, after, finalStorage, result,
    ((Arm64ProgramEntryOrnCall.enter entry le k before).trans result.run).trans
      (Arm64ProgramEntryOrnCall.leave initial le k after)⟩

end KProgFormal.ClightRefinement.Arm64Orn.Call
