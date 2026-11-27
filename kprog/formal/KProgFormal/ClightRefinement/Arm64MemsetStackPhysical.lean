import KProgFormal.ClightRefinement.Arm64MemsetByteNative
import KProgFormal.ClightRefinement.Arm64MemsetStackWrite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetStackPhysical
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- Actual private tag stores retain the guest stack relation and permissions;
the native guest machine takes no tag-store step. -/
private theorem private_store {m after : CC.Mem} {stack other : CC.Block} {origin : BitVec 64}
    {profile : MemoryProfile} {native : ArmState}
    (prior : Represents m stack origin profile native) (chunk : CC.Chunk) (offset : Int) (value : CC.Val)
    (stored : CC.Mem.store chunk m other offset value = some after) (different : stack ≠ other) :
    Represents after stack origin profile native where
  profileRead := prior.profileRead
  readable := fun i => (prior.readable i).trans (CC.Mem.perm_store stored stack (i.val : Int) .Cur .Readable).symm
  writable := fun i => (prior.writable i).trans (CC.Mem.perm_store stored stack (i.val : Int) .Cur .Writable).symm
  bytes := fun i readable =>
    (CC.Mem.load_store_other stored .Mint8unsigned stack (i.val : Int) (.inl different)).trans (prior.bytes i readable)

/-- The true native PC advance retains the actual memory/profile observation. -/
private theorem cursor {m : CC.Mem} {stack : CC.Block} {origin : BitVec 64}
    {profile : MemoryProfile} {native : ArmState}
    (prior : Represents m stack origin profile native) (pc : BitVec 64) :
    Represents m stack origin profile (write_pc pc native) where
  profileRead := by simpa [read_memory_profile,write_pc,w,write_base_pc] using prior.profileRead
  readable := prior.readable
  writable := prior.writable
  bytes := fun i readable => by simpa [read_mem,write_pc,w,write_base_pc] using prior.bytes i readable

/-- Pair the SAME actual private tag and guest-byte store effects with the
mature native STRB. Native permission follows from the successful source
store and mapped permission equality, without another source execution. -/
theorem pair_stores_register {m tagged after : CC.Mem} {tags stack : CC.Block}
    (data : Fin 31) (i : Fin 160) (value : BitVec 8) (offset : Int) (tagValue : CC.Val)
    (tagStored : CC.Mem.store .Mint64 m tags offset tagValue = some tagged)
    (byteStored : CC.Mem.store .Mint8unsigned tagged stack (i.val : Int) (.Vint (value.setWidth 32)) = some after)
    (stackSeparate : tags ≠ stack)
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents m stack origin profile native.machine)
    (base : Reference.AArch64.gpr native 0 = address origin i)
    (byte : (Reference.AArch64.gpr native data).setWidth 8 = value)
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some (Arm64ByteStoreNative.instruction data).encoding) :
    ∃ profileAfter, ∃ nativeAfter : Reference.AArch64.State,
      Reference.AArch64.step native = ⟨nativeAfter,[.memory .write (address origin i) [value] true],none⟩ ∧
      Represents after stack origin profileAfter nativeAfter.machine ∧
      read_pc nativeAfter.machine = read_pc native.machine + 4#64 ∧
      nativeAfter.extraFlags = native.extraFlags ∧
      (∀ field : StateField, field ≠ .PC → r field nativeAfter.machine = r field native.machine) ∧
      (∀ a : BitVec 64, a ≠ address origin i → read_mem a nativeAfter.machine = read_mem a native.machine) ∧
      read_memory_accesses nativeAfter.machine = read_memory_accesses native.machine ++
        [.memory .write (address origin i) [value] true] ∧
      nativeAfter.machine.program = native.machine.program ∧
      nativeAfter.machine.exclusive = native.machine.exclusive ∧
      nativeAfter.machine.atomicAccesses = native.machine.atomicAccesses ∧
      nativeAfter.machine.threadPointerInputs = native.machine.threadPointerInputs ∧
      profileAfter.readable = profile.readable ∧ profileAfter.writable = profile.writable ∧
      profileAfter.initialized (address origin i) = true ∧
      (∀ j : Fin 160, j ≠ i → profileAfter.initialized (address origin j) = profile.initialized (address origin j)) := by
  have taggedRep := private_store represented .Mint64 offset tagValue tagStored stackSeparate.symm
  have permitted : profile.writable (address origin i) = true := by
    rw [taggedRep.writable i]
    have valid := CC.Mem.store_valid_access byteStored
    simp only [CC.Mem.validAccess,Bool.and_eq_true] at valid
    have range := valid.1
    exact CC.Mem.rangePerm_perm tagged stack (i.val : Int) ((i.val : Int)+CC.sizeChunk .Mint8unsigned)
      .Cur .Writable range (i.val : Int) (by omega) (by simp only [CC.sizeChunk]; omega)
  obtain ⟨written,profileAfter,checked,mapped,readable,writable,initialized,initializedOther,
    otherBytes,history,program,exclusive,atomic,thread,fields⟩ := Arm64MemsetPhysicalByte.store taggedRep i value byteStored permitted
  have afterError : read_err written = .None := (fields .ERR).trans noError
  let nativeAfter : Reference.AArch64.State := {native with machine := write_pc (read_pc native.machine + 4#64) written}
  have step := Arm64ByteStoreNative.reference_step native data profile represented.profileRead
    (address origin i) value written base byte checked noError afterError history fetched
  refine ⟨profileAfter,nativeAfter,step,
    cursor mapped _,?_,rfl,?_,?_,?_,?_,?_,?_,?_,readable,writable,initialized,initializedOther⟩
  · simp [nativeAfter,read_pc,write_pc,r_of_w_same]
  · intro field otherPC
    exact (r_of_w_different otherPC).trans (fields field)
  · intro a different
    simpa [nativeAfter,read_mem,write_pc,w,write_base_pc] using otherBytes a different
  · simpa [nativeAfter,read_memory_accesses,write_pc,w,write_base_pc] using history
  · simpa [nativeAfter,write_pc,w,write_base_pc] using program
  · simpa [nativeAfter,write_pc,w,write_base_pc] using exclusive
  · simpa [nativeAfter,write_pc,w,write_base_pc] using atomic
  · simpa [nativeAfter,write_pc,w,write_base_pc] using thread

/-- The original W1 interface is the same shared physical-store theorem. -/
theorem pair_stores {m tagged after : CC.Mem} {tags stack : CC.Block}
    (i : Fin 160) (value : BitVec 8) (offset : Int) (tagValue : CC.Val)
    (tagStored : CC.Mem.store .Mint64 m tags offset tagValue = some tagged)
    (byteStored : CC.Mem.store .Mint8unsigned tagged stack (i.val : Int) (.Vint (value.setWidth 32)) = some after)
    (stackSeparate : tags ≠ stack)
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents m stack origin profile native.machine)
    (base : Reference.AArch64.gpr native 0 = address origin i)
    (byte : (Reference.AArch64.gpr native 1).setWidth 8 = value)
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some Arm64MemsetByteNative.instruction.encoding) :
    ∃ profileAfter, ∃ nativeAfter : Reference.AArch64.State,
      Reference.AArch64.step native = ⟨nativeAfter,[.memory .write (address origin i) [value] true],none⟩ ∧
      Represents after stack origin profileAfter nativeAfter.machine ∧
      read_pc nativeAfter.machine = read_pc native.machine + 4#64 ∧
      nativeAfter.extraFlags = native.extraFlags ∧
      (∀ field : StateField, field ≠ .PC → r field nativeAfter.machine = r field native.machine) ∧
      (∀ a : BitVec 64, a ≠ address origin i → read_mem a nativeAfter.machine = read_mem a native.machine) ∧
      read_memory_accesses nativeAfter.machine = read_memory_accesses native.machine ++
        [.memory .write (address origin i) [value] true] ∧
      nativeAfter.machine.program = native.machine.program ∧
      nativeAfter.machine.exclusive = native.machine.exclusive ∧
      nativeAfter.machine.atomicAccesses = native.machine.atomicAccesses ∧
      nativeAfter.machine.threadPointerInputs = native.machine.threadPointerInputs ∧
      profileAfter.readable = profile.readable ∧ profileAfter.writable = profile.writable ∧
      profileAfter.initialized (address origin i) = true ∧
      (∀ j : Fin 160, j ≠ i → profileAfter.initialized (address origin j) = profile.initialized (address origin j)) := by
  exact pair_stores_register 1 i value offset tagValue tagStored byteStored stackSeparate
    origin profile native represented base byte noError fetched


/-- The actual original two-store stack arm pairs with one fetched imported
STRB. Its private tag store, full source execution, real native write event,
source permissions/caller observations and complete native frame remain. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags stack : CC.Block) (i : Fin 160) (word : BitVec 64) (value : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (value.setWidth 64)))
    (tagPointer : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0))
    (stackPointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0))
    (observed : CC.Mem.load .Mint64 m tags (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i)) = some (.Vlong word))
    (tagRange : CC.Mem.rangePerm m tags 0 24 .Cur .Writable = true)
    (stackRange : CC.Mem.rangePerm m stack 0 160 .Cur .Writable = true)
    (entrySeparate : entry ≠ tags) (stackSeparate : tags ≠ stack)
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents m stack origin profile native.machine)
    (base : Reference.AArch64.gpr native 0 = address origin i)
    (byte : (Reference.AArch64.gpr native 1).setWidth 8 = value)
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some Arm64MemsetByteNative.instruction.encoding) :
    ∃ tagged after profileAfter, ∃ nativeAfter : Reference.AArch64.State,
      CC.Star (CC.Step2 world) (.State handler Arm64Program.s_kprog_arm64_program_memset_77 k e le m) CC.E0
        (.State handler .Sskip k e (Arm64MemsetStackWrite.temps le i tags stack word value) after) ∧
      CC.Mem.store .Mint64 m tags (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i))
        (.Vlong (Arm64MemsetTagWrite.cleared (Arm64MemsetTagSource.tagOf i) word)) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged stack (i.val : Int) (.Vint (value.setWidth 32)) = some after ∧
      Reference.AArch64.step native = ⟨nativeAfter,[.memory .write (address origin i) [value] true],none⟩ ∧
      Represents after stack origin profileAfter nativeAfter.machine ∧
      read_pc nativeAfter.machine = read_pc native.machine + 4#64 ∧
      nativeAfter.extraFlags = native.extraFlags ∧
      (∀ field : StateField, field ≠ .PC → r field nativeAfter.machine = r field native.machine) ∧
      (∀ a : BitVec 64, a ≠ address origin i → read_mem a nativeAfter.machine = read_mem a native.machine) ∧
      read_memory_accesses nativeAfter.machine = read_memory_accesses native.machine ++
        [.memory .write (address origin i) [value] true] ∧
      nativeAfter.machine.program = native.machine.program ∧
      nativeAfter.machine.exclusive = native.machine.exclusive ∧
      nativeAfter.machine.atomicAccesses = native.machine.atomicAccesses ∧
      nativeAfter.machine.threadPointerInputs = native.machine.threadPointerInputs ∧
      profileAfter.readable = profile.readable ∧ profileAfter.writable = profile.writable ∧
      profileAfter.initialized (address origin i) = true ∧
      (∀ j : Fin 160, j ≠ i → profileAfter.initialized (address origin j) = profile.initialized (address origin j)) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ tags → block ≠ stack →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  obtain ⟨tagged,after,run,tagStored,byteStored,byteRead,tagRead,access,next,kept⟩ :=
    Arm64MemsetStackWrite.execute e le m k entry tags stack i word value hentry hindex hwidth hvalue
      tagPointer stackPointer observed tagRange stackRange entrySeparate stackSeparate
  obtain ⟨profileAfter,nativeAfter,step,mapped,pc,extra,fields,bytes,history,program,exclusive,atomic,thread,
    readable,writable,initialized,initializedOther⟩ := pair_stores i value _ _ tagStored byteStored stackSeparate
      origin profile native represented base byte noError fetched
  exact ⟨tagged,after,profileAfter,nativeAfter,run,tagStored,byteStored,step,mapped,pc,extra,fields,bytes,
    history,program,exclusive,atomic,thread,readable,writable,initialized,initializedOther,access,next,kept⟩

end KProgFormal.ClightRefinement.Arm64MemsetStackPhysical
