import KProgFormal.ClightRefinement.Arm64MemcpyClobberRelease

open KProgFormal.ClightRefinement

namespace KProgFormal.ClightRefinement.Arm64ClobberReleaseComplete
#check step_framed
#print axioms step_framed
#check step
#print axioms step
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont) (i : Fin 160)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val m le) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (i.val + 1) after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.loop k CC.emptyEnv le m) trace
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := step inputs k i prior
#check iterations_framed
#print axioms iterations_framed
#check iterations
#print axioms iterations
example {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont)
    (start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 0 before le) (n : Nat) (bound : n ≤ 160) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.loop k CC.emptyEnv le before) trace
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := iterations inputs k start n bound
#check execute_framed
#print axioms execute_framed
#check execute
#print axioms execute
section
variable {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe : CC.TempEnv}

example
    (current : Arm64ClobberCoreState.Saved (Arm64MemcpySource.allocation calleeBefore).1 base abi byte rawR0 copiedN cell flagValue before)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont) :
    ∃ after nextLe trace,
      ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 160 after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world)
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.loop (Arm64MemsetClobberEntry.continuation k) CC.emptyEnv
          (Arm64MemsetClobberEntry.temps entry.block current.memory.storage.sp.block) before) trace
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.tags (tagCont k) CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := execute current inputs k
end
end KProgFormal.ClightRefinement.Arm64ClobberReleaseComplete

namespace KProgFormal.ClightRefinement.Arm64ClobberReleaseTagComplete
#check step_framed
#print axioms step_framed
#check step
#print axioms step
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (k : CC.Cont) (i : Fin 20) (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val m le) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (i.val + 1) after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper Arm64MemsetReleaseTagLoop.loop k CC.emptyEnv le m) CC.E0
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetReleaseTagLoop.loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := step k i prior
#check iterations_framed
#print axioms iterations_framed
#check iterations
#print axioms iterations
example {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (k : CC.Cont) (start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 0 before le)
    (n : Nat) (bound : n ≤ 20) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper Arm64MemsetReleaseTagLoop.loop k CC.emptyEnv le before) CC.E0
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetReleaseTagLoop.loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) := iterations k start n bound
#check execute_framed
#print axioms execute_framed
#check execute
#print axioms execute
example {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (current : Arm64ClobberReleaseComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 160 m le)
    (called : CC.Cont) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 20 after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world) (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.tags
        (Arm64ClobberReleaseComplete.tagCont called) CC.emptyEnv le m) CC.E0
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.rest (Arm64MemsetReleaseTagLoop.restCont called) CC.emptyEnv nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (64+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := execute current called
#check original_framed
#print axioms original_framed
#check original
#print axioms original
example {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe : CC.TempEnv}
    (current : Arm64ClobberCoreState.Saved (Arm64MemcpySource.allocation calleeBefore).1 base abi byte rawR0 copiedN cell flagValue before)
    (inputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe)
    (called : CC.Cont) :
    ∃ after nextLe trace,
      ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 20 after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world)
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.loop (Arm64MemsetClobberEntry.continuation called) CC.emptyEnv
          (Arm64MemsetClobberEntry.temps entry.block current.memory.storage.sp.block) before) trace
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.rest (Arm64MemsetReleaseTagLoop.restCont called) CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := original current inputs called
end KProgFormal.ClightRefinement.Arm64ClobberReleaseTagComplete

namespace KProgFormal.ClightRefinement.Arm64MemcpyClobberRelease
#check execute_framed
#print axioms execute_framed
#check execute
#print axioms execute
example {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {outerLe : CC.TempEnv} {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 before outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (inputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (k : CC.Cont) :
    ∃ after nextLe trace,
      ∃ _current : Arm64ClobberReleaseTagComplete.Invariant base abi byte calleeBefore (-16#64) 16
        cell flagValue outerLe 20 after nextLe,
      CC.Star (CC.Step2 Arm64ProgramEntryAllocation.world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe before) trace
        (.State Arm64MemsetClobberEntry.helper Arm64MemsetClobberEntry.rest
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k))
          CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := execute current flag inputs k
end KProgFormal.ClightRefinement.Arm64MemcpyClobberRelease
