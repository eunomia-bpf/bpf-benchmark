import KProgFormal.ClightRefinement.Arm64KernelMemcpySource
namespace KProgFormal.ClightRefinement.Arm64KernelMemcpySource
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)

#check execute
#print axioms execute
#check execute_framed
#print axioms execute_framed
example {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (physicalOrigin codeOrigin : BitVec 64) (input : MemoryProfile) (native current : Reference.AArch64.State)
    (represented : Represents before base.stack.block physicalOrigin input native.machine)
    (source : Reference.AArch64.gpr native 1 = physicalOrigin+(-32#64))
    (destination : Reference.AArch64.gpr native 0 = physicalOrigin+(-16#64))
    (loads : Arm64KernelMemcpyTwoLoads.Result native input codeOrigin) (reached : current = loads.final)
    (destinationEnd : Reference.AArch64.gpr native 5 = Reference.AArch64.gpr native 0+16#64) :
    ∃ after copyLe, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte
      (Arm64MemcpyLengthState.words gprs) flags values before 16 after copyLe,
    ∃ stores : Arm64KernelMemcpyTwoStores.Result current input codeOrigin,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
          (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
          (Arm64MemcpySource.allocation before).1 copyLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
        some (.Vint ((read_mem (address physicalOrigin (Arm64MemcpyStorePhysical.index j)) stores.final.machine).setWidth 32))) ∧
      read_memory_profile stores.final.machine = some
        (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr current 0)) ∧
      (∀ other : BitVec 64, 16 ≤ (other-Reference.AArch64.gpr current 0).toNat →
        read_mem other stores.final.machine = read_mem other current.machine) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ after.nextblock.toNat := by
  exact execute prior bound le k cell flagValue flag physicalOrigin codeOrigin input native current represented source destination loads reached destinationEnd
end KProgFormal.ClightRefinement.Arm64KernelMemcpySource
