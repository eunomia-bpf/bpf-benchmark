import KProgFormal.ClightRefinement.Arm64MemcpyReadFlag
import KProgFormal.ClightRefinement.Arm64MemsetTagTransferComplete
import KProgFormal.ClightRefinement.Arm64MemcpyProgramEntry

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyFlagMemory

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)

/-- The real sixteen-iteration memset byte loop preserves header696 and
its distinct initialized TailLocal5 cell on the same actual output heap. -/
theorem write_loop {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    (e : CC.Env) (k : CC.Cont) {le : CC.TempEnv}
    (start : Arm64MemsetWriteLoop.Invariant base abi byte 0 before le)
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe, ∃ _current : Arm64MemsetWriteLoop.Invariant base abi byte 16 after nextLe,
      CC.Star (CC.Step2 world) (.State Arm64MemsetSource.handler Arm64MemsetLoop.loop k e le before) CC.E0
        (.State Arm64MemsetSource.handler .Sskip k e nextLe after) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  obtain ⟨after,nextLe,current,run,_written,frame,access,next,outside⟩ := Arm64MemsetWriteLoop.execute e k start
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have header := outside CC.Mptr entry.block 696
    (separate _ _ _ _ entry.binding base.tags.binding (by decide +kernel))
    (separate _ _ _ _ entry.binding base.stack.binding (by decide +kernel))
  have value := outside .Mint8unsigned cell.block 0
    (separate _ _ _ _ cell.binding base.tags.binding (by decide +kernel))
    (separate _ _ _ _ cell.binding base.stack.binding (by decide +kernel))
  exact ⟨after,nextLe,current,run,⟨header.trans flag.header,value.trans flag.byte⟩,frame,access,next⟩

/-- Both original tag-transfer stores and all sixteen real transfer
iterations retain the initialized flag while executing their true source. -/
theorem transfer {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {le : CC.TempEnv} (ready : Arm64MemsetWriteLoop.Invariant base abi byte 16 before le)
    (addresses : Arm64Registers.PointerOrigins) (calleeBefore : CC.Mem) (k : CC.Cont)
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe, ∃ _current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State Arm64MemsetSource.handler .Sskip (.Kseq Arm64MemsetLoop.effects k)
          (Arm64MemsetSource.allocation calleeBefore).1 le before) CC.E0
        (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
          (Arm64MemsetSource.allocation calleeBefore).1 nextLe after) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  obtain ⟨after,nextLe,current,run,_written,frame,access,next,outside⟩ :=
    Arm64MemsetTagTransferComplete.execute ready addresses calleeBefore k
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have header := outside CC.Mptr entry.block 696
    (separate _ _ _ _ entry.binding base.tags.binding (by decide +kernel))
  have value := outside .Mint8unsigned cell.block 0
    (separate _ _ _ _ cell.binding base.tags.binding (by decide +kernel))
  exact ⟨after,nextLe,current,run,⟨header.trans flag.header,value.trans flag.byte⟩,frame,access,next⟩

/-- The actual program memcpy call, eight-local allocation, input reads
and counter initializer carry that same flag to real copy iteration zero. -/
theorem entry {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ copyLe, ∃ _current : Arm64MemcpyLoopState.Invariant base abi byte
        (Arm64MemcpyLengthState.words gprs) flags values before 0 (Arm64MemcpySource.allocation before).2 copyLe,
      InternalRun world 121
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.loop
          (Arm64MemcpyCopyEntry.continuation (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k)))
          (Arm64MemcpySource.allocation before).1 copyLe (Arm64MemcpySource.allocation before).2) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue (Arm64MemcpySource.allocation before).2 ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ (Arm64MemcpySource.allocation before).2.nextblock.toNat := by
  obtain ⟨copyLe,current,run⟩ := Arm64MemcpyProgramEntry.current prior bound le k
  have advanced := (FrameBelow.allocVariables (Arm64MemcpySource.allocated before)
    before.nextblock (Nat.le_refl _)).1
  exact ⟨copyLe,current,run,flag.frame before.nextblock bound (Arm64MemcpySource.entry_frame before),
    Nat.le_trans bound advanced⟩

end KProgFormal.ClightRefinement.Arm64MemcpyFlagMemory
