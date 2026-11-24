import KProgFormal.ClightRefinement.X86ReleaseByteComplete
import KProgFormal.ClightRefinement.X86ReleaseByteCacheFrame

namespace KProgFormal.ClightRefinement.X86ReleaseByteCompleteFrame
open X86ReleaseProvider (Frame View Core)
open X86ReleaseByteComplete (AtLane)
open X86ReleaseByteCacheFrame (AboveFrame)

/-- Explicit stronger platform ABI for the current new-SP boundary. It
supplies actual outcomes plus private-cache read preservation; the existing
outside-cache Available contract does not establish this premise. -/
def PreservingInputs (ge : CC.CGenv) (binding stack : CC.Block) (base : CC.Integers.Ptrofs)
    (next : BitVec 64) : Prop := ∀ memory, View memory binding stack base →
  ∃ outcome : X86ReleaseProvider.Outcome ge stack memory, AboveFrame stack base next memory outcome.supplied

private theorem iteration (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack input : CC.Block) (base : CC.Integers.Ptrofs) (slot : Fin 6) (lane : Fin 8) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (separate : binding ≠ stack) (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack base) (core : Core le binding slot old next) (atLane : AtLane le lane.val) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseByteLoop.body
        (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e le memory) trace
      (.State function X86RegisterWriteRspReleaseByteLoop.body
        (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e finalTemps after) ∧
    View after binding stack base ∧ Core finalTemps binding slot old next ∧ AtLane finalTemps (lane.val + 1) ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack memory after ∧ AboveFrame stack base next memory after := by
  have laneRead : le.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)) := atLane
  cases decision : X86RegisterWriteRspReleaseByteLoop.released slot lane old next
  · let ready := (X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next).set
      X86_program_profile_bpf.___x86_release_lane__5 (.Vint (BitVec.ofNat 32 (lane.val + 1)))
    refine ⟨[], memory, ready,
      (X86RegisterWriteRspReleaseByteCall.skipped ge function e le k memory slot lane old next
        laneRead core.index core.offset core.old core.next decision).sound,
      view, X86ReleaseProvider.core_control le binding slot lane old next _ core, ?_, rfl, rfl, ?_, ?_⟩
    · exact CC.PTree.gss _ _ _
    · intro chunk block offset different
      rfl
    · intro readSlot readLane above
      rfl
  · obtain ⟨outcome, outcomeFrame⟩ := available memory view
    have suppliedView := X86ReleaseProvider.outcome_view ge binding stack base memory view separate outcome
    obtain ⟨after, selectedRun, stored, readback, access, frontier, frame, bytes, aboveFrame⟩ :=
      X86ReleaseByteCacheFrame.selected ge layout stackLayout function e le k memory outcome.supplied
        binding stack input base slot lane old next outcome.value outcome.trace symbol global notLocal
        core.binding core.index laneRead core.offset core.old core.next decision outcome.call suppliedView.header
        (suppliedView.bytes slot lane) outcomeFrame
    let ready := X86RegisterWriteRspReleaseByteCall.temps
      (X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next) outcome.value stack base
    have readyLane : ready.get X86_program_profile_bpf.___x86_release_lane__5 =
        some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)) := by
      simp +decide [ready, X86RegisterWriteRspReleaseByteCall.temps, X86RegisterWriteRspReleaseByteLoop.temps,
        CC.PTree.gso, laneRead]
    have coreReady := X86ReleaseProvider.core_byte le binding stack base slot lane old next outcome.value core
    have advance := X86RegisterWriteRspReleaseByteLoop.advance ge function e ready k after lane readyLane
    have sameAccess := access.trans outcome.access
    have sameFrontier := frontier.trans outcome.frontier
    have entireFrame : Frame stack memory after := by
      intro chunk block offset different
      exact (frame chunk block offset different).trans (outcome.frame chunk block offset different)
    refine ⟨outcome.trace, after,
      ready.set X86_program_profile_bpf.___x86_release_lane__5 (.Vint (BitVec.ofNat 32 (lane.val + 1))),
      ?_, X86ReleaseProvider.view_transport binding stack base memory after view separate sameAccess entireFrame,
      X86ReleaseProvider.core_lane ready binding slot old next _ coreReady,
      CC.PTree.gss _ _ _, sameAccess, sameFrontier, entireFrame, aboveFrame⟩
    simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans selectedRun advance.sound

private theorem lanes (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (function : CC.Function) (e : CC.Env) (k : CC.Cont) (binding stack input : CC.Block)
    (base : CC.Integers.Ptrofs) (slot : Fin 6) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (separate : binding ≠ stack) (available : PreservingInputs ge binding stack base next)
    (fuel : Nat) (start : Nat) (le : CC.TempEnv) (memory : CC.Mem)
    (remaining : start + fuel = 8) (view : View memory binding stack base)
    (core : Core le binding slot old next) (atLane : AtLane le start) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseByteLoop.body
        (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧
    View after binding stack base ∧ Core finalTemps binding slot old next ∧ AtLane finalTemps 8 ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack memory after ∧ AboveFrame stack base next memory after := by
  induction fuel generalizing start le memory with
  | zero =>
    have index : start = 8 := by omega
    subst start
    have exitRead : le.get X86_program_profile_bpf.___x86_release_lane__5 = some (.Vint (8#32)) := atLane
    refine ⟨[], memory, le, (X86RegisterWriteRspReleaseByteLoop.exit ge function e le k memory exitRead).sound,
      view, core, atLane, rfl, rfl, ?_, ?_⟩
    · intro chunk block offset different
      rfl
    · intro readSlot readLane above
      rfl
  | succ fuel ih =>
    have bound : start < 8 := by omega
    let lane : Fin 8 := ⟨start, bound⟩
    obtain ⟨firstTrace, middle, middleTemps, firstRun, middleView, middleCore, middleLane,
      firstAccess, firstNext, firstFrame, firstAbove⟩ :=
      iteration ge layout stackLayout function e le k memory binding stack input base slot lane old next
        symbol global notLocal separate available view core atLane
    have residual : (start + 1) + fuel = 8 := by omega
    obtain ⟨lastTrace, after, finalTemps, lastRun, finalView, finalCore, finalLane,
      lastAccess, lastNext, lastFrame, lastAbove⟩ :=
      ih (start + 1) middleTemps middle residual middleView middleCore middleLane
    refine ⟨firstTrace ++ lastTrace, after, finalTemps, ?_, finalView, finalCore, finalLane,
      lastAccess.trans firstAccess, lastNext.trans firstNext, ?_, ?_⟩
    · exact star_trans firstRun lastRun
    · intro chunk block offset different
      exact (lastFrame chunk block offset different).trans (firstFrame chunk block offset different)
    · exact X86ReleaseByteCacheFrame.frame_trans stack base next memory middle after firstAbove lastAbove

/-- The entire original8-lane byte fallback executes every real guard,
provider/store or skip, counter/backedge and exit, retaining prior source
contracts and additionally cache-byte reads at/above new SP. The stronger
per-provider PreservingInputs premise is explicit, not a derived ABI fact. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack input : CC.Block) (base : CC.Integers.Ptrofs) (slot : Fin 6) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (separate : binding ≠ stack) (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack base) (core : Core le binding slot old next) :
    ∃ trace after finalTemps, CC.Star (CC.Step2 ge)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_111 k e le memory) trace
      (.State function .Sskip k e finalTemps after) ∧
    View after binding stack base ∧ Core finalTemps binding slot old next ∧ AtLane finalTemps 8 ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧ Frame stack memory after ∧ AboveFrame stack base next memory after := by
  let ready := le.set X86_program_profile_bpf.___x86_release_lane__5 (.Vint (0#32))
  have readyCore := X86ReleaseProvider.core_lane le binding slot old next (0#32) core
  have readyLane : AtLane ready 0 := CC.PTree.gss _ _ _
  obtain ⟨trace, after, finalTemps, run, finalView, finalCore, finalLane, access, frontier, frame, aboveFrame⟩ :=
    lanes ge layout stackLayout function e k binding stack input base slot old next symbol global notLocal separate
      available 8 0 ready memory rfl view readyCore readyLane
  refine ⟨trace, after, finalTemps, ?_, finalView, finalCore, finalLane, access, frontier, frame, aboveFrame⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append] using
    star_trans (X86RegisterWriteRspReleaseByteLoop.enter ge function e le k memory).sound run

end KProgFormal.ClightRefinement.X86ReleaseByteCompleteFrame
