import KProgFormal.ClightRefinement.Arm64MemcpyReadCallerPhysical
import KProgFormal.ClightRefinement.Arm64MemcpyStorePhysical

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyBodyPhysical
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- The complete original body executes its actual reader call/free/caller
and actual tag/byte stores ONCE. Its reached loaded X3 feeds the following
fetched STRB on the SAME native state and program, in real read/write order. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents before base.stack.block origin profile native.machine)
    (source : Reference.AArch64.gpr native 1 = address origin (Arm64MemsetStoreExecution.index i))
    (destination : Reference.AArch64.gpr native 0 = address origin (Arm64MemcpyStorePhysical.index i))
    (noError : read_err native.machine = .None)
    (fetchedRead : fetch_inst (read_pc native.machine) native.machine = some Arm64MemcpyByteNativeRead.instruction.encoding)
    (fetchedWrite : fetch_inst (read_pc native.machine+4#64) native.machine = some (Arm64ByteStoreNative.instruction 3).encoding) :
    ∃ readAfter tagged after nextLe,
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
    ∃ read : Arm64MemcpySourcePhysicalRead.Result readAfter base.stack.block origin profile native (Arm64MemsetStoreExecution.index i) byte,
    ∃ written : Arm64MemcpyStorePhysical.Result after base.stack.block origin profile read.final i byte,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.write k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.store .Mint64 readAfter base.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged base.stack.block (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after base.stack.block (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      read_pc written.final.machine = read_pc native.machine+8#64 ∧
      read_err written.final.machine = .None ∧
      written.final.extraFlags = native.extraFlags ∧
      (∀ field : StateField, field ≠ .PC → field ≠ .GPR (3#5) → r field written.final.machine = r field native.machine) ∧
      (∀ a : BitVec 64, a ≠ address origin (Arm64MemcpyStorePhysical.index i) → read_mem a written.final.machine = read_mem a native.machine) ∧
      read_memory_accesses written.final.machine = read_memory_accesses native.machine ++
        [.memory .read (address origin (Arm64MemsetStoreExecution.index i)) [byte] true,
         .memory .write (address origin (Arm64MemcpyStorePhysical.index i)) [byte] true] := by
  obtain ⟨readAfter,readLe,readCurrent,read,readRun,off,width,value,readFrame,readFlag,pbound,cbound⟩ :=
    Arm64MemcpyReadCallerPhysical.execute le k i prior producerBound callerBound cell flagValue flag
      origin profile native represented source noError fetchedRead
  have actualValue : readLe.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)) := by
    simpa only [read.data] using value
  have destinationAfter : Reference.AArch64.gpr read.final 0 = address origin (Arm64MemcpyStorePhysical.index i) :=
    (read.fields (.GPR (0#5)) (by decide) (by decide)).trans destination
  have data : (Reference.AArch64.gpr read.final 3).setWidth 8 = byte := by
    rw [read.data]
    simp
  have errorAfter : read_err read.final.machine = .None :=
    (read.fields .ERR (by decide) (by decide)).trans noError
  have codeAfter : fetch_inst (read_pc read.final.machine) read.final.machine = some (Arm64ByteStoreNative.instruction 3).encoding := by
    rw [read.pc]
    simpa only [fetch_inst,read.program] using fetchedWrite
  obtain ⟨tagged,after,nextLe,next,written,writeRun,tagStored,byteStored,copied,flagAfter,writeFrame,nextblock⟩ :=
    Arm64MemcpyStorePhysical.execute readLe k i readCurrent pbound cbound off width actualValue
      cell flagValue readFlag origin profile read.final read.mapped destinationAfter data errorAfter codeAfter
  have oldBound : initial.nextblock.toNat ≤ before.nextblock.toNat := by
    have owned := ((allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64Producer.allocation initial)).symm)).1 _ _ entry.binding)
    omega
  have oldFrame : FrameBelow initial.nextblock before readAfter := fun block below => readFrame block (by omega)
  refine ⟨readAfter,tagged,after,nextLe,next,read,written,?_,tagStored,byteStored,copied,flagAfter,
    oldFrame.trans writeFrame,?_,?_,?_,?_,written.extra.trans read.extra,?_,?_,?_⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans readRun writeRun
  · simpa only [nextblock] using pbound
  · simpa only [nextblock] using cbound
  · simpa only [read.pc,BitVec.add_assoc,show (4#64)+(4#64) = 8#64 by decide] using written.pc
  · exact (written.fields .ERR (by decide)).trans errorAfter
  · intro field notPC notGpr
    exact (written.fields field notPC).trans (read.fields field notPC notGpr)
  · intro a other
    exact (written.bytes a other).trans (by simpa only [read_mem] using congrArg (fun mem => read_store a mem) read.memory)
  · simpa only [read.history,List.append_assoc,List.cons_append,List.nil_append] using written.history

end KProgFormal.ClightRefinement.Arm64MemcpyBodyPhysical
