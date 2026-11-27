import KProgFormal.ClightRefinement.Arm64MemcpyBodyPhysical

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyIterationPhysical
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- The actual source true guard, SAME physical byte body, and original
unsigned counter increment/backedge execute once. The genuine destination
readback extends the copied prefix in the same reached packet. Both actual
native read/write states and their precise admitted code domain remain. -/
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
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore (i.val+1) after nextLe,
    ∃ read : Arm64MemcpySourcePhysicalRead.Result readAfter base.stack.block origin profile native (Arm64MemsetStoreExecution.index i) byte,
    ∃ written : Arm64MemcpyStorePhysical.Result after base.stack.block origin profile read.final i byte,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
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
  let e := (Arm64MemcpySource.allocation calleeBefore).1
  have enter := Arm64MemcpyLoop.enter_current e le k i prior
  obtain ⟨readAfter,tagged,after,bodyLe,bodyCurrent,read,written,bodyRun,tagStored,byteStored,copied,
    flagAfter,frame,pbound,cbound,pc,error,extra,fields,bytes,history⟩ :=
    Arm64MemcpyBodyPhysical.execute le (Arm64MemcpyLoop.writeCont k) i prior producerBound callerBound
      cell flagValue flag origin profile native represented source destination noError fetchedRead fetchedWrite
  obtain ⟨next,advance⟩ := Arm64MemcpyLoop.advance_current e bodyLe k i bodyCurrent copied
  refine ⟨readAfter,tagged,after,_,next,read,written,?_,tagStored,byteStored,copied,flagAfter,
    frame,pbound,cbound,pc,error,extra,fields,bytes,history⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using
    star_trans enter.sound (star_trans bodyRun advance.sound)

end KProgFormal.ClightRefinement.Arm64MemcpyIterationPhysical
