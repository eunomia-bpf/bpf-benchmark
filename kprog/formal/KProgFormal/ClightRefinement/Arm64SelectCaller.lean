import KProgFormal.ClightRefinement.Arm64SelectCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select.Call

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)

/-- Every finite relational execution is a silent prefix of the same actual
freed-frame return. Its endpoint is unique and infinite execution is excluded;
no external-call determinism or already-silent candidate trace is assumed. -/
theorem Result.all_behaviors {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {native : Reference.AArch64.State}
    {count : Nat} {value : CC.Val} {raw : BitVec 64} {tag : BitVec 8}
    {finalStorage : Storage initial after entry}
    (result : Result storage addresses origins native .Kstop count value raw tag written after finalStorage) :
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntrySelectCall.arguments entry.block) .Kstop before) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun world remaining other (.Returnstate .Vundef .Kstop after)) ∧
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntrySelectCall.arguments entry.block) .Kstop before) t other →
      (∀ u next, ¬ CC.Step2 world other u next) →
      t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Arm64Nop.handler) (Arm64ProgramEntrySelectCall.arguments entry.block) .Kstop before ∧
      ∀ j, ∃ t, CC.Step2 world (states j) t (states (j+1))) := by
  have stuck : ∀ t next, ¬ CC.Step2 world (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => result.run.finish_prefix stuck observed,
    fun _ _ observed endpoint => result.run.endpoint_unique stuck observed endpoint,
    result.run.no_infinite stuck⟩

/-- Invoke the real seventh source call after CMP and resume its unchanged
successor with the original fixture environment and temporaries. The generic
callee's allocation, actual stores and free come from execute on this memory. -/
theorem returned {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (decoded : instruction.decoded = .DPR (.Conditional_select (Native.fields 5 1 2 (0#4))))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count value raw tag written after, ∃ finalStorage : Storage initial after entry,
      Result storage addresses origins native (Arm64ProgramEntrySelectCall.callCont initial le k)
        count value raw tag written after finalStorage ∧
      InternalRun world (2 + count + 2)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySelectCall.afterSelect k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) := by
  obtain ⟨count,value,raw,tag,written,after,finalStorage,result⟩ := execute storage bound addresses origins
    native instruction represented decoded noError fetched (Arm64ProgramEntrySelectCall.callCont initial le k) rfl
  exact ⟨count,value,raw,tag,written,after,finalStorage,result,
    ((Arm64ProgramEntrySelectCall.enter entry le k before).trans result.run).trans
      (Arm64ProgramEntrySelectCall.leave initial le k after)⟩

end KProgFormal.ClightRefinement.Arm64Select.Call
