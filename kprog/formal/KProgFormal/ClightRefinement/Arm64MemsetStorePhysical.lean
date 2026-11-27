import KProgFormal.ClightRefinement.Arm64MemsetStackPhysical
import KProgFormal.ClightRefinement.Arm64MemsetStoreExecution

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetStorePhysical
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)
open Arm64MemsetStoreExecution (index temps)
open Arm64MemsetPhysicalByte (Represents address)

/-- The original16 source offsets, mapped through actual stack bias96. -/
private theorem index_offset : ∀ i : Fin 16,
    BitVec.ofNat 64 (index i).val - 96#64 = BitVec.ofNat 64 i.val - 32#64 := by decide +kernel

theorem physical_address (origin : BitVec 64) (i : Fin 16) :
    address origin (index i) = origin + (BitVec.ofNat 64 i.val - 32#64) := by
  simp only [address,index_offset]

/-- Execute the original producer bias/index/action route ONCE, using its
actual View/Resources and two real stores. The same effects refine fetched
STRB at the real physical byte, with original caller/free/continuation facts. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (value : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (value.setWidth 64)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0))
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents m view.stack.block origin profile native.machine)
    (base : Reference.AArch64.gpr native 0 = address origin (index i))
    (byte : (Reference.AArch64.gpr native 1).setWidth 8 = value)
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some Arm64MemsetByteNative.instruction.encoding) :
    ∃ tagged after profileAfter, ∃ nativeAfter : Reference.AArch64.State,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetLossSetup.store k e le m) CC.E0
        (.State handler .Sskip (Arm64MemsetStoreRoute.continuation k) e (temps view le i value) after) ∧
      CC.Mem.store .Mint64 m view.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged view.stack.block ((index i).val : Int) (.Vint (value.setWidth 32)) = some after ∧
      FrameBelow initial.nextblock m after ∧
      after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block → block ≠ view.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) ∧
      Nonempty (Arm64MemsetHeaderView.View initial after entry) ∧
      Reference.AArch64.step native = ⟨nativeAfter,[.memory .write (address origin (index i)) [value] true],none⟩ ∧
      Represents after view.stack.block origin profileAfter nativeAfter.machine ∧
      read_pc nativeAfter.machine = read_pc native.machine + 4#64 ∧
      nativeAfter.extraFlags = native.extraFlags ∧
      (∀ field : StateField, field ≠ .PC → r field nativeAfter.machine = r field native.machine) ∧
      (∀ a : BitVec 64, a ≠ address origin (index i) → read_mem a nativeAfter.machine = read_mem a native.machine) ∧
      read_memory_accesses nativeAfter.machine = read_memory_accesses native.machine ++
        [.memory .write (address origin (index i)) [value] true] ∧
      nativeAfter.machine.program = native.machine.program ∧
      nativeAfter.machine.exclusive = native.machine.exclusive ∧
      nativeAfter.machine.atomicAccesses = native.machine.atomicAccesses ∧
      nativeAfter.machine.threadPointerInputs = native.machine.threadPointerInputs ∧
      profileAfter.readable = profile.readable ∧ profileAfter.writable = profile.writable ∧
      profileAfter.initialized (address origin (index i)) = true ∧
      (∀ j : Fin 160, j ≠ index i → profileAfter.initialized (address origin j) = profile.initialized (address origin j)) := by
  obtain ⟨tagged,after,run,tagStored,byteStored,byteRead,tagRead,frame,access,next,kept,current⟩ :=
    Arm64MemsetStoreExecution.execute view resources e le k i value hentry hoff hwidth hvalue tagBytes
  have allocation := CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm
  have owned := allocated_local_storage allocation
  have separate : view.tags.block ≠ view.stack.block :=
    owned.2 _ _ _ _ view.tags.binding view.stack.binding (by decide +kernel)
  obtain ⟨profileAfter,nativeAfter,step,mapped,pc,extra,fields,bytes,history,program,exclusive,atomic,thread,
    readable,writable,initialized,initializedOther⟩ :=
    Arm64MemsetStackPhysical.pair_stores (index i) value 8 (.Vlong 0) tagStored byteStored separate
      origin profile native represented base byte noError fetched
  exact ⟨tagged,after,profileAfter,nativeAfter,run,tagStored,byteStored,frame,access,next,kept,current,
    step,mapped,pc,extra,fields,bytes,history,program,exclusive,atomic,thread,readable,writable,initialized,initializedOther⟩

end KProgFormal.ClightRefinement.Arm64MemsetStorePhysical
