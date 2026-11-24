import KProgFormal.ClightRefinement.X86ProducerPushRspAddress

namespace KProgFormal.ClightRefinement.X86ProducerPushRspRead
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler)
open X86ProducerPushRspSource (update store)

def firstTemps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := le.set X86_program_profile_bpf._t'228 (.Vptr cells 0)
def secondTemps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := (firstTemps le cells).set X86_program_profile_bpf._t'229 (.Vptr cells 0)
def temps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := (secondTemps le cells).set X86_program_profile_bpf._t'230 (.Vlong 0)

/-- The original two header loads and RSP union load execute in source order,
including all actual sequence transitions, without changing complete memory. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (binding cells : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells 0))
    (rsp : CC.Mem.load CC.Mptr memory cells 64 = some (.Vlong 0)) :
    InternalRun ge 9 (.State handler update k e le memory)
      (.State handler store k e (temps le cells) memory) := by
  have boundFirst : (firstTemps le cells).get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    simpa +decide [firstTemps, CC.PTree.gso] using bound
  have h1 := X86ProducerPushRspAddress.header_value e le memory binding cells bound header
  have h2 := X86ProducerPushRspAddress.header_value e (firstTemps le cells) memory binding cells boundFirst header
  have lastCell : (secondTemps le cells).get X86_program_profile_bpf._t'229 = some (.Vptr cells 0) := CC.PTree.gss _ _ _
  have h3 := X86ProducerPushRspAddress.current_value e (secondTemps le cells) memory cells lastCell rsp
  dsimp only [firstTemps, secondTemps] at h2 h3
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, X86ProducerPushRspSource.source,
    X86ProducerPushRspSource.reads.1, X86ProducerPushRspSource.reads.2.1, X86ProducerPushRspSource.reads.2.2.1,
    h1, h2, h3, firstTemps, secondTemps, temps, CC.E0, CC.Eapp, List.nil_append, true_and]

/-- Actual initialized source resources supply every read, including genuine
abstract-RSP zero. No independent header/load or reader-run premise is added. -/
theorem from_ready {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (bodyCont k : CC.Cont) :
    InternalRun ge 9
      (.State handler update k (X86ProducerPushBody.allocation ready.after).1
        (X86ProducerPushReadReturn.temps ready.entry.block bodyCont ready.after (ready.values 3)) (X86ProducerPushBody.allocation ready.after).2)
      (.State handler store k (X86ProducerPushBody.allocation ready.after).1
        (temps (X86ProducerPushReadReturn.temps ready.entry.block bodyCont ready.after (ready.values 3)) ready.gprs.block)
        (X86ProducerPushBody.allocation ready.after).2) := by
  have rsp := (X86ProducerPushResources.observations ready).1 4 (by decide +kernel)
  rw [ready.rsp_zero] at rsp
  exact execute _ _ _ _ ready.entry.block ready.gprs.block
    (X86ProducerPushRspSource.inputs ready.entry.block bodyCont ready.after (ready.values 3)).1
    (X86ProducerPushResources.views ready).2.2.1 rsp.1

end KProgFormal.ClightRefinement.X86ProducerPushRspRead
