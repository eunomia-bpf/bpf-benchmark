import KProgFormal.ClightRefinement.Arm64MemsetStackPhysical
import KProgFormal.ClightRefinement.Arm64MemcpyStoreSuffix
import KProgFormal.ClightRefinement.Arm64MemcpyStorePrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyStorePhysical
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

def index (i : Fin 16) : Fin 160 := ⟨80+i.val,by omega⟩

private theorem index_offset : ∀ i : Fin 16,
    BitVec.ofNat 64 (index i).val - 96#64 = BitVec.ofNat 64 i.val - 16#64 := by decide +kernel

theorem physical_address (origin : BitVec 64) (i : Fin 16) :
    address origin (index i) = origin+(BitVec.ofNat 64 i.val - 16#64) := by
  simp only [address,index_offset]

/-- The actual checked W3 store, including every physical byte/profile/frame
observation needed by the next instruction on the same native machine. -/
structure Result (after : CC.Mem) (stack : CC.Block) (origin : BitVec 64) (profile : MemoryProfile)
    (native : Reference.AArch64.State) (i : Fin 16) (byte : BitVec 8) where
  profileAfter : MemoryProfile
  final : Reference.AArch64.State
  step : Reference.AArch64.step native = ⟨final,[.memory .write (address origin (index i)) [byte] true],none⟩
  mapped : Represents after stack origin profileAfter final.machine
  pc : read_pc final.machine = read_pc native.machine+4#64
  extra : final.extraFlags = native.extraFlags
  fields : ∀ field : StateField, field ≠ .PC → r field final.machine = r field native.machine
  bytes : ∀ a : BitVec 64, a ≠ address origin (index i) → read_mem a final.machine = read_mem a native.machine
  history : read_memory_accesses final.machine = read_memory_accesses native.machine ++ [.memory .write (address origin (index i)) [byte] true]
  program : final.machine.program = native.machine.program
  exclusive : final.machine.exclusive = native.machine.exclusive
  atomic : final.machine.atomicAccesses = native.machine.atomicAccesses
  thread : final.machine.threadPointerInputs = native.machine.threadPointerInputs
  readable : profileAfter.readable = profile.readable
  writable : profileAfter.writable = profile.writable
  initialized : profileAfter.initialized (address origin (index i)) = true
  initializedOther : ∀ j : Fin 160, j ≠ index i → profileAfter.initialized (address origin j) = profile.initialized (address origin j)

/-- Execute the original bias/index/mask/action prefix and full source81
suffix once. Keep the actual private Mint64 tag and volatile Mint8 stores,
source loop/caller/flag observations, and their SAME physical W3 write. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)))
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents before base.stack.block origin profile native.machine)
    (destination : Reference.AArch64.gpr native 0 = address origin (index i))
    (data : (Reference.AArch64.gpr native 3).setWidth 8 = byte)
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some (Arm64ByteStoreNative.instruction 3).encoding) :
    ∃ tagged after nextLe,
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
    ∃ result : Result after base.stack.block origin profile native i byte,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyReadCall.store (Arm64MemcpyReadCaller.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged base.stack.block (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after base.stack.block (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧ after.nextblock = before.nextblock := by
  have prefixRun := Arm64MemcpyStorePrefix.execute (Arm64MemcpySource.allocation calleeBefore).1
    le before (Arm64MemcpyReadCaller.continuation k) entry.block byte i prior.entryRead hoff hwidth hvalue prior.packet.view.bias
  let prefixLe := Arm64MemcpyStorePrefix.temps le byte i
  let prefixCurrent := Arm64MemcpyStorePrefix.current i prior
  have outputs := Arm64MemcpyStorePrefix.outputs le byte i
  have prefixOff : prefixLe.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)) :=
    (Arm64MemcpyStorePrefix.kept le byte i _ (by decide +kernel)).trans hoff
  obtain ⟨tagged,after,nextLe,next,suffixRun,tagStored,byteStored,read,flagAfter,frame,nextblock⟩ :=
    Arm64MemcpyStoreSuffix.execute prefixLe k i prefixCurrent producerBound callerBound
      outputs.1 outputs.2.1 outputs.2.2 prefixOff cell flagValue flag
  have allocation := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm
  have separate : base.tags.block ≠ base.stack.block :=
    (allocated_local_storage allocation).2 _ _ _ _ base.tags.binding base.stack.binding (by decide +kernel)
  have actualByte : CC.Mem.store .Mint8unsigned tagged base.stack.block ((index i).val : Int)
      (.Vint (byte.setWidth 32)) = some after := by
    have actual : ((index i).val : Int) = 80+(i.val : Int) := by dsimp [index]
    simpa only [actual] using byteStored
  obtain ⟨profileAfter,nativeAfter,step,mapped,pc,extra,fields,bytes,history,program,exclusive,atomic,thread,
    readable,writable,initialized,initializedOther⟩ :=
    Arm64MemsetStackPhysical.pair_stores_register 3 (index i) byte 8 (.Vlong 0) tagStored actualByte separate
      origin profile native represented destination data noError fetched
  let result : Result after base.stack.block origin profile native i byte :=
    ⟨profileAfter,nativeAfter,step,mapped,pc,extra,fields,bytes,history,program,exclusive,atomic,thread,
      readable,writable,initialized,initializedOther⟩
  refine ⟨tagged,after,nextLe,next,result,?_,tagStored,byteStored,read,flagAfter,frame,nextblock⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans prefixRun.sound suffixRun

end KProgFormal.ClightRefinement.Arm64MemcpyStorePhysical
