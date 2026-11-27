import KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete

open KProgFormal.ClightRefinement
#check Arm64ClobberRegisterComplete.step_supplied_framed
#print axioms Arm64ClobberRegisterComplete.step_supplied_framed
#check Arm64ClobberRegisterComplete.step_supplied
#print axioms Arm64ClobberRegisterComplete.step_supplied
#check Arm64ClobberRegisterComplete.step
#print axioms Arm64ClobberRegisterComplete.step

namespace KProgFormal.ClightRefinement.Arm64ClobberRegisterComplete
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 18 → BitVec 64}
    (k : CC.Cont) (i : Fin 18)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val values m le)
    (value : BitVec 64) (trace : CC.Trace) (provided : CC.Mem)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv Arm64ProgramEntryAllocation.world.genv_genv)
      [.Vint (6#32)] m trace (.Vlong value) provided)
    (cache : Arm64ProgramEntryCacheFrame.Frame initial false m provided) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe
      (i.val + 1) (updated values i value) after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper (stage i.val) k CC.emptyEnv le m) trace
        (.State Arm64MemsetClobberEntry.helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step_supplied k i prior value trace provided provider cache
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont) (i : Fin 18)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper (stage i.val) k CC.emptyEnv le m) trace
        (.State Arm64MemsetClobberEntry.helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step inputs k i prior
end KProgFormal.ClightRefinement.Arm64ClobberRegisterComplete
#check Arm64ClobberFlagsComplete.step_supplied_framed
#print axioms Arm64ClobberFlagsComplete.step_supplied_framed
#check Arm64ClobberFlagsComplete.step_supplied
#print axioms Arm64ClobberFlagsComplete.step_supplied
#check Arm64ClobberFlagsComplete.step
#print axioms Arm64ClobberFlagsComplete.step

namespace KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 4 → BitVec 64} {gprs : Fin 18 → BitVec 64}
    (k : CC.Cont) (i : Fin 4)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs i.val values m le)
    (value : BitVec 64) (trace : CC.Trace) (provided : CC.Mem)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv Arm64ProgramEntryAllocation.world.genv_genv)
      [.Vint (6#32)] m trace (.Vlong value) provided)
    (cache : Arm64ProgramEntryCacheFrame.Frame initial false m provided) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs
      (i.val + 1) (updated values i value) after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper (Arm64MemsetClobberFlags.stage i.val) k CC.emptyEnv le m) trace
        (.State Arm64MemsetClobberEntry.helper (Arm64MemsetClobberFlags.stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step_supplied k i prior value trace provided provider cache
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 4 → BitVec 64} {gprs : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs) (k : CC.Cont) (i : Fin 4)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper (Arm64MemsetClobberFlags.stage i.val) k CC.emptyEnv le m) trace
        (.State Arm64MemsetClobberEntry.helper (Arm64MemsetClobberFlags.stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step inputs k i prior
end KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete
#check Arm64ClobberVectorsComplete.step_supplied_framed
#print axioms Arm64ClobberVectorsComplete.step_supplied_framed
#check Arm64ClobberVectorsComplete.step_supplied
#print axioms Arm64ClobberVectorsComplete.step_supplied
#check Arm64ClobberVectorsComplete.step
#print axioms Arm64ClobberVectorsComplete.step

namespace KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 64 → BitVec 64}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (k : CC.Cont) (i : Fin 64)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags i.val values m le)
    (value : BitVec 64) (trace : CC.Trace) (provided : CC.Mem)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv Arm64ProgramEntryAllocation.world.genv_genv)
      [.Vint (6#32)] m trace (.Vlong value) provided)
    (cache : Arm64ProgramEntryCacheFrame.Frame initial false m provided) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags
      (i.val + 1) (updated values i value) after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper (stage i.val) k CC.emptyEnv le m) trace
        (.State Arm64MemsetClobberEntry.helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step_supplied k i prior value trace provided provider cache
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 64 → BitVec 64}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags) (k : CC.Cont) (i : Fin 64)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper (stage i.val) k CC.emptyEnv le m) trace
        (.State Arm64MemsetClobberEntry.helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step inputs k i prior
end KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete
