import KProgFormal.ClightRefinement.Arm64ProgramEntryColdRead

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryWarmRead

open Arm64ProgramEntryAllocation (world)

/-- The reached warm SP cache feeds the actual linked reader. It returns
the represented native SP in71 internal transitions, preserving the exact
memory and arbitrary caller continuation, with no additional provider call. -/
theorem read (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (memory : CC.Mem) (k : CC.Cont)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier memory (.Vptr b ofs) native)
    (cache : Arm64RegisterReads.WarmEntryCache false frontier memory (.Vptr b ofs) origins.stack) :
    InternalRun world 71
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong (32#64)] k memory)
      (.Returnstate (.Vlong (Reference.AArch64.sp native)) (CC.callCont k) memory) := by
  obtain ⟨offset, observed, bits⟩ := represented.sp
  have run := Arm64RegisterReads.sp_read_warm_bound world Arm64ProgramEntryColdRead.stack_layout
    frontier b ofs memory k offset origins.stack observed cache
  simpa only [← bits] using run

/-- Every relational execution of the warm reader is a silent prefix of its
same-memory native-SP return, every stuck result is that return, and no infinite
execution exists. No trace-silence or external-determinism premise is added. -/
theorem all_behaviors (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (memory : CC.Mem) (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier memory (.Vptr b ofs) native)
    (cache : Arm64RegisterReads.WarmEntryCache false frontier memory (.Vptr b ofs) origins.stack) :
    InternalRun world 71
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong (32#64)] .Kstop memory)
      (.Returnstate (.Vlong (Reference.AArch64.sp native)) .Kstop memory) ∧
    (∀ trace other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong (32#64)] .Kstop memory) trace other →
      trace = CC.E0 ∧ ∃ remaining, InternalRun world remaining other
        (.Returnstate (.Vlong (Reference.AArch64.sp native)) .Kstop memory)) ∧
    (∀ trace other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong (32#64)] .Kstop memory) trace other →
      (∀ t next, ¬ CC.Step2 world other t next) →
      trace = CC.E0 ∧ other = .Returnstate (.Vlong (Reference.AArch64.sp native)) .Kstop memory) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong (32#64)] .Kstop memory ∧
      ∀ j, ∃ trace, CC.Step2 world (states j) trace (states (j + 1))) := by
  have run := read addresses origins frontier b ofs memory .Kstop native represented cache
  have stopped : ∀ trace next, ¬ CC.Step2 world
      (.Returnstate (.Vlong (Reference.AArch64.sp native)) .Kstop memory) trace next := by
    intro trace next step
    cases step
  exact ⟨run, fun _ _ observed => run.finish_prefix stopped observed,
    fun _ _ observed otherStopped => run.endpoint_unique stopped observed otherStopped,
    run.no_infinite stopped⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryWarmRead
