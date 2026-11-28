import KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriterExecute

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPReturn
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)

/-- The original call, actual internal writer and return retain the same caller frame. -/
theorem resume {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun ge 44
        (.State procedure Arm64CiliumCallerSPPreindex.call k (allocation m).1
          (Arm64CiliumCallerSPPreindex.resultEnv le) before)
        (.State procedure .Sskip k (allocation m).1
          (Arm64CiliumCallerSPPreindex.resultEnv le) result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  let cont := CC.Cont.Kcall none procedure (allocation m).1
    (Arm64CiliumCallerSPPreindex.resultEnv le) k
  obtain ⟨result,run,read⟩ :=
    Arm64CiliumCallerSPWriterExecute.execute header sources scalars access pointers reads cont rfl
  have returned : InternalRun ge 1
      (.Returnstate .Vundef cont result.after)
      (.State procedure .Sskip k (allocation m).1
        (Arm64CiliumCallerSPPreindex.resultEnv le) result.after) :=
    .step trivial (.returnstate _ _ _ _ _ _ _) (.refl _)
  exact ⟨result,(Arm64CiliumCallerLinkedSPCall.call_ready header le before k).trans
    (run.trans returned),read⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPReturn
