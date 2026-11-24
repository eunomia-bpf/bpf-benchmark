import KProgFormal.ClightRefinement.X86ReleaseOuterComplete
import KProgFormal.ClightRefinement.X86ReleaseByteCompleteFrame
import KProgFormal.ClightRefinement.X86ReleaseWordCacheFrame

namespace KProgFormal.ClightRefinement.X86ReleaseOuterCacheFrame
open X86ReleaseProvider (Core)

open X86ReleaseOuterComplete (View Frame)
open X86ReleaseByteCacheFrame (AboveFrame)
open X86ReleaseByteCompleteFrame (PreservingInputs)

private theorem transport (before after : CC.Mem) (binding stack cells : CC.Block)
    (base cellOffset : CC.Integers.Ptrofs) (places : X86CallFrameComplete.Places) (sp : BitVec 64)
    (view : View before binding stack cells base cellOffset places sp)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (same : after.access = before.access) (frame : X86ReleaseProvider.Frame stack before after) :
    View after binding stack cells base cellOffset places sp := by
  refine ⟨X86ReleaseProvider.view_transport binding stack base before after view.cache bindingSeparate same frame,
    ?_, (frame CC.Mptr binding 0 bindingSeparate).trans view.table,
    (frame CC.Mptr cells _ cellsSeparate).trans view.rawSp⟩
  constructor
  · intro slot
    exact (frame CC.Mptr binding _ bindingSeparate).trans (view.metadata.tags slot)
  · intro slot
    exact (frame CC.Mptr binding _ bindingSeparate).trans (view.metadata.pointers slot)
  · intro slot
    exact (X86ReleaseProvider.access_rights before after same _ _ _ _).trans (view.metadata.tag_rights slot)
  · intro slot
    exact (X86ReleaseProvider.access_rights before after same _ _ _ _).trans (view.metadata.pointer_rights slot)

private theorem slot_run (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack input : CC.Block) (base : CC.Integers.Ptrofs) (slot : Fin 6) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (separate : binding ≠ stack) (available : PreservingInputs ge binding stack base next)
    (view : X86ReleaseProvider.View memory binding stack base) (core : Core le binding slot old next) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseLoop.iteration k e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧
    X86ReleaseProvider.View after binding stack base ∧ Core finalTemps binding slot old next ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ X86ReleaseProvider.Frame stack memory after ∧ AboveFrame stack base next memory after := by
  cases decision : X86RegisterWriteRspReleaseSelect.whole slot old next
  · let ready := X86RegisterWriteRspReleaseSelect.temps le slot old next
    have readyCore : Core ready binding slot old next := by
      constructor <;> simp +decide [ready, X86RegisterWriteRspReleaseSelect.temps, CC.PTree.gso,
        core.binding, core.index, core.offset, core.old, core.next]
    have chosen := X86RegisterWriteRspReleaseSelect.choose ge function e le k memory slot old next
      core.index core.offset core.old core.next
    simp only [X86RegisterWriteRspReleaseSelect.arm, decision, ite_false] at chosen
    obtain ⟨trace, after, finalTemps, run, finalView, finalCore, finalLane, access, frontier, frame, aboveFrame⟩ :=
      X86ReleaseByteCompleteFrame.execute ge layout stackLayout function e ready k memory binding stack input base slot old next
        symbol global notLocal separate available view readyCore
    refine ⟨trace, after, finalTemps, ?_, finalView, finalCore, access, frontier, frame, aboveFrame⟩
    simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans chosen.sound run
  · obtain ⟨outcome, outcomeFrame⟩ := available memory view
    have suppliedView := X86ReleaseProvider.outcome_view ge binding stack base memory view separate outcome
    obtain ⟨after, run, stored, readback, access, frontier, frame, aboveFrame⟩ :=
      X86ReleaseWordCacheFrame.selected ge layout stackLayout function e le k memory outcome.supplied
        binding stack input base slot old next outcome.value outcome.trace symbol global notLocal core.binding
        core.index core.offset core.old core.next decision outcome.call suppliedView.header (suppliedView.words slot) outcomeFrame
    have same := access.trans outcome.access
    have entireFrame : X86ReleaseProvider.Frame stack memory after := by
      intro chunk block offset different
      exact (frame chunk block offset different).trans (outcome.frame chunk block offset different)
    exact ⟨outcome.trace, after, _, run,
      X86ReleaseProvider.view_transport binding stack base memory after view separate same entireFrame,
      X86ReleaseProvider.core_word le binding stack base slot old next outcome.value core,
      same, frontier.trans outcome.frontier, entireFrame, aboveFrame⟩

private theorem next_core (le : CC.TempEnv) (binding : CC.Block) (slot : Fin 5) (old next : BitVec 64)
    (core : Core le binding slot.castSucc old next) :
    Core (X86RegisterWriteRspReleaseAdvance.temps
      (le.set X86_program_profile_bpf.___x86_release_i__5
        (.Vint (X86RegisterWriteRspReleaseSelect.index slot.succ))) slot.succ) binding slot.succ old next := by
  constructor <;> simp +decide [X86RegisterWriteRspReleaseAdvance.temps, CC.PTree.gss, CC.PTree.gso,
    core.binding, core.old, core.next]

private theorem slots (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (k : CC.Cont) (binding stack cells input helper : CC.Block)
    (base cellOffset : CC.Integers.Ptrofs) (places : X86CallFrameComplete.Places) (sp old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (helperNotLocal : e.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places) (available : PreservingInputs ge binding stack base next)
    (fuel : Nat) (slot : Fin 6) (le : CC.TempEnv) (memory : CC.Mem) (remaining : slot.val + fuel = 5)
    (view : View memory binding stack cells base cellOffset places sp) (core : Core le binding slot old next) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseLoop.iteration
        (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧ X86CallFrameComplete.View after binding places ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack places memory after ∧ AboveFrame stack base next memory after := by
  induction fuel generalizing slot le memory with
  | zero =>
    have lastSlot : slot = (5 : Fin 6) := Fin.ext (by omega)
    subst slot
    obtain ⟨trace, middle, middleTemps, firstRun, cacheView, middleCore, firstAccess, firstNext, firstFrame, firstAbove⟩ :=
      slot_run ge layout stackLayout function e le (X86RegisterWriteRspReleaseLoop.loopContinuation k) memory
        binding stack input base (5 : Fin 6) old next symbol global notLocal bindingSeparate available view.cache core
    have middleView := transport memory middle binding stack cells base cellOffset places sp view
      bindingSeparate cellsSeparate firstAccess firstFrame
    obtain ⟨n, after, completed, finalView, access, frontier, frame⟩ :=
      X86CallFrameComplete.after_last ge layout valueLayout function e middleTemps k middle binding cells helper
        cellOffset places sp helperSymbol helperGlobal helperNotLocal middleCore.binding middleCore.index
        middleView.table middleView.rawSp metadataSeparate middleView.metadata
    refine ⟨trace, after, middleTemps.set X86_program_profile_bpf.___x86_release_i__5 (.Vint (48#32)),
      ?_, finalView, access.trans firstAccess, frontier.trans firstNext, ?_, ?_⟩
    · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans firstRun completed.sound
    · intro chunk block offset notCache outside
      exact (frame chunk block offset outside).trans (firstFrame chunk block offset notCache)
    · intro readSlot readLane above
      exact (frame .Mint8unsigned stack _ cacheOutside).trans (firstAbove readSlot readLane above)
  | succ fuel ih =>
    have bound : slot.val < 5 := by omega
    let position : Fin 5 := ⟨slot.val, bound⟩
    obtain ⟨trace, middle, middleTemps, firstRun, cacheView, middleCore, firstAccess, firstNext, firstFrame, firstAbove⟩ :=
      slot_run ge layout stackLayout function e le (X86RegisterWriteRspReleaseLoop.loopContinuation k) memory
        binding stack input base slot old next symbol global notLocal bindingSeparate available view.cache core
    have middleView := transport memory middle binding stack cells base cellOffset places sp view
      bindingSeparate cellsSeparate firstAccess firstFrame
    let ready := X86RegisterWriteRspReleaseAdvance.temps
      (middleTemps.set X86_program_profile_bpf.___x86_release_i__5
        (.Vint (X86RegisterWriteRspReleaseSelect.index position.succ))) position.succ
    have readyCore := next_core middleTemps binding position old next middleCore
    have advance := X86RegisterWriteRspReleaseAdvance.next_iteration ge function e middleTemps k middle position middleCore.index
    have residual : position.succ.val + fuel = 5 := by dsimp [position]; omega
    obtain ⟨lastTrace, after, finalTemps, lastRun, finalView, lastAccess, lastNext, lastFrame, lastAbove⟩ :=
      ih position.succ ready middle residual middleView readyCore
    refine ⟨trace ++ lastTrace, after, finalTemps, ?_, finalView, lastAccess.trans firstAccess,
      lastNext.trans firstNext, ?_,
      X86ReleaseByteCacheFrame.frame_trans stack base next memory middle after firstAbove lastAbove⟩
    · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans (star_trans firstRun advance.sound) lastRun
    · intro chunk block offset notCache outside
      exact (lastFrame chunk block offset notCache outside).trans (firstFrame chunk block offset notCache)

/-- All6 original outer slots preserve actual at/above-new-SP cache reads
under stronger provider preservation and cache/ghost separation, and execute their real whole-word or8-byte paths,
backedges and final frame helper/caller restoration. Explicit actual-provider
ABI guarantees carry the source observations; no whole-loop result is assumed. -/
theorem from_first (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack cells input helper : CC.Block) (base cellOffset : CC.Integers.Ptrofs)
    (places : X86CallFrameComplete.Places) (sp old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (helperNotLocal : e.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places) (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack cells base cellOffset places sp) (core : Core le binding 0 old next) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseLoop.iteration
        (X86RegisterWriteRspReleaseLoop.loopContinuation k) e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧ X86CallFrameComplete.View after binding places ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack places memory after ∧ AboveFrame stack base next memory after :=
  slots ge layout stackLayout valueLayout function e k binding stack cells input helper base cellOffset places sp old next
    symbol global notLocal helperSymbol helperGlobal helperNotLocal bindingSeparate cellsSeparate cacheOutside metadataSeparate available
    5 0 le memory rfl view core

private theorem initialized_core (le : CC.TempEnv) (binding : CC.Block) (old next : BitVec 64)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (oldRead : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (nextRead : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next)) :
    Core (X86RegisterWriteRspReleaseLoop.temps le) binding 0 old next := by
  constructor <;> simp +decide [X86RegisterWriteRspReleaseLoop.temps,
    X86RegisterWriteRspReleaseSelect.index, X86RegisterWriteRspReleaseSelect.offset,
    CC.PTree.gss, CC.PTree.gso, bindingRead, oldRead, nextRead]

/-- Original counter initialization, all6 actual release slots and complete
frame helper run from the genuine increasing-SP source branch. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack cells input helper : CC.Block) (base cellOffset : CC.Integers.Ptrofs)
    (places : X86CallFrameComplete.Places) (sp old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (helperNotLocal : e.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places) (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack cells base cellOffset places sp)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (oldRead : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (nextRead : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next)) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspRelease.increasing k e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧ X86CallFrameComplete.View after binding places ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack places memory after ∧ AboveFrame stack base next memory after := by
  have readyCore := initialized_core le binding old next bindingRead oldRead nextRead
  obtain ⟨trace, after, finalTemps, run, finalView, access, frontier, frame, aboveFrame⟩ :=
    from_first ge layout stackLayout valueLayout function e (X86RegisterWriteRspReleaseLoop.temps le) k memory
      binding stack cells input helper base cellOffset places sp old next symbol global notLocal helperSymbol helperGlobal
      helperNotLocal bindingSeparate cellsSeparate cacheOutside metadataSeparate available view readyCore
  refine ⟨trace, after, finalTemps, ?_, finalView, access, frontier, frame, aboveFrame⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append] using
    star_trans (X86RegisterWriteRspReleaseLoop.enter ge function e le k memory).sound run

private theorem finish_release (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 2
      (.State function .Sskip (X86RegisterWriteRspRelease.releaseContinuation k) e le memory)
      (.State function .Sskip k e le memory) := by
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, X86RegisterWriteRspRelease.releaseContinuation,
    CC.doStep, CC.E0, CC.Eapp]

/-- Saved-old/new-cell reads and the actual positive signed branch compose
with the entire growing release and real enclosing-loop exits from table write. -/
theorem from_table (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack cells input helper : CC.Block) (base cellOffset : CC.Integers.Ptrofs)
    (places : X86CallFrameComplete.Places) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (helperNotLocal : e.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places) (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack cells base cellOffset places next)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (increasing : CC.Integers.Int64.cmp .Cgt next old = true) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function .Sskip (X86ShiftWriteback.tableCont k) e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧ X86CallFrameComplete.View after binding places ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack places memory after ∧ AboveFrame stack base next memory after := by
  let ready := X86RegisterWriteRspRelease.temps le cells cellOffset old next
  have readyBinding : ready.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    simp +decide [ready, X86RegisterWriteRspRelease.temps, CC.PTree.gso, bindingRead]
  have readyOld : ready.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old) := by
    simp +decide [ready, X86RegisterWriteRspRelease.temps, CC.PTree.gso, CC.PTree.gss]
  have readyNext : ready.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next) := CC.PTree.gss _ _ _
  have initialRun := X86RegisterWriteRspRelease.increasing_enter ge layout function e le k memory binding cells cellOffset
    old next bindingRead destination oldSp view.table view.rawSp increasing
  obtain ⟨trace, after, finalTemps, run, finalView, access, frontier, frame, aboveFrame⟩ :=
    execute ge layout stackLayout valueLayout function e ready (X86RegisterWriteRspRelease.releaseContinuation k) memory
      binding stack cells input helper base cellOffset places next old next symbol global notLocal helperSymbol helperGlobal
      helperNotLocal bindingSeparate cellsSeparate cacheOutside metadataSeparate available view readyBinding readyOld readyNext
  refine ⟨trace, after, finalTemps, ?_, finalView, access, frontier, frame, aboveFrame⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (star_trans initialRun.sound run) (finish_release ge function e finalTemps k after).sound

/-- Both signed raw-SP branches complete from the original table-write frontier.
The non-increasing branch reuses its real20-step unchanged path; growing offsets
execute all original slots and helper. Provider preservation and actual cache/ghost ownership remain explicit. -/
theorem all_offsets (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack cells input helper : CC.Block) (base cellOffset : CC.Integers.Ptrofs)
    (places : X86CallFrameComplete.Places) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (helperNotLocal : e.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places) (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack cells base cellOffset places next)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old)) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function .Sskip (X86ShiftWriteback.tableCont k) e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧ X86CallFrameComplete.View after binding places ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack places memory after ∧ AboveFrame stack base next memory after := by
  cases comparison : CC.Integers.Int64.cmp .Cgt next old
  · have run := X86RegisterWriteRspRelease.unchanged ge layout function e le k memory binding cells cellOffset
      old next bindingRead destination oldSp view.table view.rawSp comparison
    refine ⟨CC.E0, memory, X86RegisterWriteRspRelease.temps le cells cellOffset old next,
      run.sound, view.metadata, rfl, rfl, ?_, ?_⟩
    · intro chunk block offset notCache outside
      rfl
    · intro readSlot readLane above
      rfl
  · exact from_table ge layout stackLayout valueLayout function e le k memory binding stack cells input helper
      base cellOffset places old next symbol global notLocal helperSymbol helperGlobal helperNotLocal
      bindingSeparate cellsSeparate cacheOutside metadataSeparate available view bindingRead destination oldSp comparison

end KProgFormal.ClightRefinement.X86ReleaseOuterCacheFrame
