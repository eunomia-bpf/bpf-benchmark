import KProgFormal.ClightRefinement.X86ProducerPushStackSource
import KProgFormal.ClightRefinement.X86ProducerPushPointerRead

namespace KProgFormal.ClightRefinement.X86ProducerPushStackSetup
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler)
open X86ProducerPushStackSource

def firstTemps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := le.set X86_program_profile_bpf._t'226 (.Vptr cells 0)
def secondTemps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := (firstTemps le cells).set X86_program_profile_bpf._t'227 (.Vlong X86ProducerPushRspStore.nextRsp)
def temps (le : CC.TempEnv) (cells : CC.Block) : CC.TempEnv := (secondTemps le cells).set X86_program_profile_bpf.___x86_sv_index (.Vlong (40#64))

def indexValue : CC.Expr := .Ebinop .Oadd
  (.Ecast (.Ecast (.Ecast (.Etempvar X86_program_profile_bpf._t'227 (CC.tptr CC.tvoid)) CC.tlong) CC.tlong) CC.tulong)
  (.Ecast (.Econst_int (CC.Integers.Int.repr 48) CC.tuint) CC.tulong) CC.tulong

theorem index_source : indexExpression = indexValue := rfl

theorem index_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (current : le.get X86_program_profile_bpf._t'227 = some (.Vlong X86ProducerPushRspStore.nextRsp)) :
    CC.doEvalExpr ge e le memory indexExpression = some (.Vlong (40#64)) := by
  rw [index_source]
  simp only [indexValue, CC.doEvalExpr, current]
  rfl

/-- Fourteen true source transitions enter both loops, reload current cells
and RSP, compute the actual wrapping cache index and reach the genuine width Scall. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (binding cells : CC.Block)
    (bound : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells 0))
    (rsp : CC.Mem.load CC.Mptr memory cells 64 = some (.Vlong X86ProducerPushRspStore.nextRsp)) :
    InternalRun ge 14 (.State handler X86ProducerPushRspSource.stackLoop k e le memory)
      (.State handler widthCall (widthCont k) e (temps le cells) memory) := by
  have h1 := X86ProducerPushRspAddress.header_value e le memory binding cells bound header
  have cellRead : (firstTemps le cells).get X86_program_profile_bpf._t'226 = some (.Vptr cells 0) := CC.PTree.gss _ _ _
  have h2 := X86ProducerPushPointerRead.scalar e (firstTemps le cells) memory cells _ _ cellRead rsp
  have wordRead : (secondTemps le cells).get X86_program_profile_bpf._t'227 = some (.Vlong X86ProducerPushRspStore.nextRsp) := CC.PTree.gss _ _ _
  have h3 := index_value e (secondTemps le cells) memory wordRead
  dsimp only [firstTemps, secondTemps] at h2 h3
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, loop_source, body_source, prepare_source,
    reads_source.1, reads_source.2.1, reads_source.2.2, h1, h2, h3,
    firstTemps, secondTemps, temps, widthCont, prepareCont, outerCont,
    CC.E0, CC.Eapp, List.nil_append, true_and]

/-- The SAME accepted traced producer result supplies all reloads and input
values after its real RSP store, without an independent load/View premise. -/
theorem from_rsp {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (result : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) :
    InternalRun ge 14
      (.State handler X86ProducerPushRspSource.stackLoop k (X86ProducerPushBody.allocation ready.after).1
        (X86ProducerPushRspPrefix.temps ready) result.after)
      (.State handler widthCall (widthCont k) (X86ProducerPushBody.allocation ready.after).1
        (temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block) result.after) := by
  have bound : (X86ProducerPushRspPrefix.temps ready).get X86_program_profile_bpf.___x86_bind = some (.Vptr ready.entry.block 0) := rfl
  exact execute _ _ _ _ ready.entry.block ready.gprs.block bound result.cells_read result.rsp_read

theorem inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) :
    (temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block).get X86_program_profile_bpf.___x86_sv_index = some (.Vlong (40#64)) ∧
    (temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block).get X86_program_profile_bpf.___x86_l_pp_width = some (.Vint (8#32)) ∧
    (temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block).get X86_program_profile_bpf.___x86_l_pp_value = some (.Vlong (ready.values 3)) :=
  ⟨CC.PTree.gss _ _ _, rfl, rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushStackSetup
