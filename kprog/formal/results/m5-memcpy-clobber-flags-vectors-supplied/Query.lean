import KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete

open KProgFormal.ClightRefinement
#check Arm64ClobberFlagsComplete.step_supplied
#print axioms Arm64ClobberFlagsComplete.step_supplied
#check Arm64ClobberFlagsComplete.step
#print axioms Arm64ClobberFlagsComplete.step

namespace KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete
example {initial seed m : CC.Mem} {entry : KProgFormal.ClightRefinement.Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : KProgFormal.ClightRefinement.Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : KProgFormal.ClightRefinement.Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 4 → BitVec 64} {gprs : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs) (k : CC.Cont) (i : Fin 4)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation.world) (.State KProgFormal.ClightRefinement.Arm64MemsetClobberEntry.helper (Arm64MemsetClobberFlags.stage i.val) k CC.emptyEnv le m) trace
        (.State KProgFormal.ClightRefinement.Arm64MemsetClobberEntry.helper (Arm64MemsetClobberFlags.stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step inputs k i prior
end KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete
#check Arm64ClobberVectorsComplete.step_supplied
#print axioms Arm64ClobberVectorsComplete.step_supplied
#check Arm64ClobberVectorsComplete.step
#print axioms Arm64ClobberVectorsComplete.step

namespace KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete
example {initial seed m : CC.Mem} {entry : KProgFormal.ClightRefinement.Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : KProgFormal.ClightRefinement.Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : KProgFormal.ClightRefinement.Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 64 → BitVec 64}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags) (k : CC.Cont) (i : Fin 64)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation.world) (.State KProgFormal.ClightRefinement.Arm64MemsetClobberEntry.helper (stage i.val) k CC.emptyEnv le m) trace
        (.State KProgFormal.ClightRefinement.Arm64MemsetClobberEntry.helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step inputs k i prior
end KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete
