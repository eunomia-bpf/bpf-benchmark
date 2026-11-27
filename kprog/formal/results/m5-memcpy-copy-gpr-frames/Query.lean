import KProgFormal.ClightRefinement.Arm64MemcpyCopyProgram

namespace KProgFormal.ClightRefinement.Arm64MemcpyStoreSuffix
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64Producer (HeaderLocal TailLocal)
#check execute
#print axioms execute
#check execute_framed
#print axioms execute_framed
example {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))))
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (byte.setWidth 64)))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)))
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ tagged after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81
          (Arm64MemcpyStoreIndex.continuation (Arm64MemcpyReadCaller.continuation k))
          (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged base.stack.block (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after base.stack.block (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧ after.nextblock = before.nextblock := by
  exact execute le k i prior producerBound callerBound hindex hwidth hvalue hoff cell flagValue flag
end KProgFormal.ClightRefinement.Arm64MemcpyStoreSuffix

namespace KProgFormal.ClightRefinement.Arm64MemcpyIteration
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64Producer (HeaderLocal TailLocal)
#check body
#print axioms body
#check body_framed
#print axioms body_framed
example {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.write k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.load .Mint8unsigned after base.stack.block (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  exact body le k i prior producerBound callerBound cell flagValue flag
end KProgFormal.ClightRefinement.Arm64MemcpyIteration

namespace KProgFormal.ClightRefinement.Arm64MemcpyIteration
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64Producer (HeaderLocal TailLocal)
#check execute
#print axioms execute
#check execute_framed
#print axioms execute_framed
example {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore (i.val+1) after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  exact execute le k i prior producerBound callerBound cell flagValue flag
end KProgFormal.ClightRefinement.Arm64MemcpyIteration

namespace KProgFormal.ClightRefinement.Arm64MemcpySequential
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64Producer (HeaderLocal TailLocal)
section
variable {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}

#check iterations
#print axioms iterations
#check iterations_framed
#print axioms iterations_framed
example (n : Nat) (limit : n ≤ 16) (le : CC.TempEnv) (k : CC.Cont)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 0 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  exact iterations n limit le k prior producerBound callerBound cell flagValue flag
end
end KProgFormal.ClightRefinement.Arm64MemcpySequential

namespace KProgFormal.ClightRefinement.Arm64MemcpySequential
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64Producer (HeaderLocal TailLocal)
section
variable {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}

#check execute
#print axioms execute
#check execute_framed
#print axioms execute_framed
example (le : CC.TempEnv) (k : CC.Cont)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 0 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop (Arm64MemcpyCopyEntry.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyCopyEntry.afterCopy k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (80+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  exact execute le k prior producerBound callerBound cell flagValue flag
end
end KProgFormal.ClightRefinement.Arm64MemcpySequential

namespace KProgFormal.ClightRefinement.Arm64MemcpyCopyProgram
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64Producer (HeaderLocal TailLocal)
#check execute
#print axioms execute
#check execute_framed
#print axioms execute_framed
example {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after copyLe, ∃ _current : Arm64MemcpyLoopState.Invariant base abi byte
        (Arm64MemcpyLengthState.words gprs) flags values before 16 after copyLe,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
          (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
          (Arm64MemcpySource.allocation before).1 copyLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (80+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ after.nextblock.toNat := by
  exact execute prior bound le k cell flagValue flag
end KProgFormal.ClightRefinement.Arm64MemcpyCopyProgram
