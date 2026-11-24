import KProgFormal.ClightRefinement.X86ProducerPushStorageSource
import KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix

namespace KProgFormal.ClightRefinement.X86ProducerPushStorageSetup
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler)
open X86ProducerPushStorageSource

def firstTemps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := le.set X86_program_profile_bpf._t'212 (.Vptr cells 0)
def secondTemps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := (firstTemps le cells).set X86_program_profile_bpf._t'213 (.Vlong X86ProducerPushRspStore.nextRsp)
def temps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := (secondTemps le cells).set X86_program_profile_bpf.___x86_loss_off (.Vlong X86ProducerPushRspStore.nextRsp)

theorem execute (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (binding cells : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells 0))
    (rsp : CC.Mem.load CC.Mptr memory cells 64 = some (.Vlong X86ProducerPushRspStore.nextRsp)) :
    InternalRun ge 12 (.State handler X86ProducerPushStackSource.storage k e le memory)
      (.State handler widthCall (widthCont k) e (temps le cells) memory) := by
  have h1 := X86ProducerPushRspAddress.header_value e le memory binding cells bound header
  have cellRead : (firstTemps le cells).get X86_program_profile_bpf._t'212 = some (.Vptr cells 0) := CC.PTree.gss _ _ _
  have h2 := X86ProducerPushPointerRead.scalar e (firstTemps le cells) memory cells _ _ cellRead rsp
  have wordRead : (secondTemps le cells).get X86_program_profile_bpf._t'213 = some (.Vlong X86ProducerPushRspStore.nextRsp) := CC.PTree.gss _ _ _
  have h3 : CC.doEvalExpr ge e (secondTemps le cells) memory
      (.Ecast (.Ecast (.Etempvar X86_program_profile_bpf._t'213 (CC.tptr CC.tvoid)) CC.tlong) CC.tlong) =
        some (.Vlong X86ProducerPushRspStore.nextRsp) := by
    simp only [CC.doEvalExpr, wordRead]
    rfl
  dsimp only [firstTemps, secondTemps] at h2 h3
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, source.1, source.2.1,
    inputs_source.1, inputs_source.2.1, inputs_source.2.2, h1, h2, h3,
    firstTemps, secondTemps, temps, widthCont, loopCont, CC.E0, CC.Eapp, List.nil_append, true_and]

def initialTemps {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} (rsp : X86ProducerPushRspPrefix.Result ready) : CC.TempEnv :=
  X86ProducerPushMetadataExecute.temps ready (X86ProducerPushMetadataPrefix.control ready) rsp.after

theorem from_metadata {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (result : X86ProducerPushMetadataPrefix.Result rsp) (k : CC.Cont) :
    InternalRun ge 12
      (.State handler X86ProducerPushStackSource.storage k (X86ProducerPushBody.allocation ready.after).1 (initialTemps rsp) result.after)
      (.State handler widthCall (widthCont k) (X86ProducerPushBody.allocation ready.after).1
        (temps (initialTemps rsp) ready.gprs.block) result.after) :=
  execute _ _ _ _ ready.entry.block ready.gprs.block
    (X86ProducerPushMetadataExecute.inputs ready (X86ProducerPushMetadataPrefix.control ready) rsp.after).1 result.cells_read result.rsp_read

theorem inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} (rsp : X86ProducerPushRspPrefix.Result ready) :
    (temps (initialTemps rsp) ready.gprs.block).get X86_program_profile_bpf.___x86_bind = some (.Vptr ready.entry.block 0) ∧
    (temps (initialTemps rsp) ready.gprs.block).get X86_program_profile_bpf.___x86_l_pp_width = some (.Vint (8#32)) ∧
    (temps (initialTemps rsp) ready.gprs.block).get X86_program_profile_bpf.___x86_l_pp_value = some (.Vlong (ready.values 3)) := ⟨rfl,rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushStorageSetup
