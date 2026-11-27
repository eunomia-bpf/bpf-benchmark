import KProgFormal.ClightRefinement.Arm64ClobberRegisterComplete

open KProgFormal.ClightRefinement
#check Arm64ClobberRegisterComplete.step_supplied
#print axioms Arm64ClobberRegisterComplete.step_supplied
#check Arm64ClobberRegisterComplete.step
#print axioms Arm64ClobberRegisterComplete.step
#check Arm64ClobberRegisterComplete.original
#print axioms Arm64ClobberRegisterComplete.original

namespace KProgFormal.ClightRefinement.Arm64ClobberRegisterComplete
open Arm64Producer
example {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont) (i : Fin 18)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation.world) (.State KProgFormal.ClightRefinement.Arm64MemsetClobberEntry.helper (stage i.val) k CC.emptyEnv le m) trace
        (.State KProgFormal.ClightRefinement.Arm64MemsetClobberEntry.helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step inputs k i prior
end KProgFormal.ClightRefinement.Arm64ClobberRegisterComplete
