import KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPReturn

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPPreindex
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)

/-- Execute the original preindex loop in the actual linked world, including its real writer and exit. -/
theorem execute {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun ge 59
        (.State procedure Arm64CiliumCallerSPAlignment.tail k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1
          (Arm64CiliumCallerSPPreindex.resultEnv le) result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  let cont := CC.Cont.Kloop1 Arm64CiliumCallerSPPreindex.body .Sbreak k
  have prefixRun := Arm64CiliumCallerSPPreindex.execute_in ge scalars reads le k
  obtain ⟨result,run,read⟩ :=
    Arm64CiliumCallerLinkedSPReturn.resume header sources scalars access pointers reads le cont
  have exited : InternalRun ge 2
      (.State procedure .Sskip cont (allocation m).1
        (Arm64CiliumCallerSPPreindex.resultEnv le) result.after)
      (.State procedure .Sskip k (allocation m).1
        (Arm64CiliumCallerSPPreindex.resultEnv le) result.after) := by
    apply internalRun_of_steps
    all_goals
      simp only [steps,InternalPath,InternalState,CC.doStep,cont,CC.E0,CC.Eapp,List.nil_append] <;> trivial
  exact ⟨result,prefixRun.trans (run.trans exited),read⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPPreindex
