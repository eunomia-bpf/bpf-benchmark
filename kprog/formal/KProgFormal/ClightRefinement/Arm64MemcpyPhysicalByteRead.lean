import KProgFormal.ClightRefinement.Arm64MemsetPhysicalByte
import KProgFormal.ClightRefinement.Arm64MemcpyReadByte

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyPhysicalByteRead
open Arm64MemsetPhysicalByte (Represents address)

/-- The actual concrete source load derives native read permission and
initialization. Arbitrary uninitialized native contents remain arbitrary;
the source Vint observation is what rules out source Vundef here. -/
theorem observed {m : CC.Mem} {stack : CC.Block} {origin : BitVec 64}
    {profile : MemoryProfile} {native : ArmState}
    (represented : Represents m stack origin profile native) (i : Fin 160) (value : BitVec 8)
    (loaded : CC.Mem.load .Mint8unsigned m stack (i.val : Int) = some (.Vint (value.setWidth 32))) :
    profile.readable (address origin i) = true ∧
    profile.initialized (address origin i) = true ∧ read_mem (address origin i) native = value := by
  have valid : CC.Mem.validAccess m .Mint8unsigned stack (i.val : Int) .Readable = true := by
    by_cases yes : CC.Mem.validAccess m .Mint8unsigned stack (i.val : Int) .Readable = true
    · exact yes
    · simp [CC.Mem.load,yes] at loaded
  simp only [CC.Mem.validAccess,Bool.and_eq_true] at valid
  have permitted : profile.readable (address origin i) = true := by
    rw [represented.readable i]
    exact CC.Mem.rangePerm_perm m stack (i.val : Int) ((i.val : Int)+CC.sizeChunk .Mint8unsigned)
      .Cur .Readable valid.1 (i.val : Int) (by omega) (by simp only [CC.sizeChunk]; omega)
  have same := (represented.bytes i permitted).symm.trans loaded
  have initialized : profile.initialized (address origin i) = true := by
    cases actual : profile.initialized (address origin i) with
    | false => simp [actual] at same
    | true => rfl
  have values : (read_mem (address origin i) native).setWidth 32 = value.setWidth 32 := by
    simpa only [initialized,ite_true,Option.some.injEq,CC.Val.Vint.injEq] using same
  have byte := congrArg (fun word : BitVec 32 => word.setWidth 8) values
  have result : read_mem (address origin i) native = value := by
    simpa only [BitVec.setWidth_setWidth_of_le _ (by decide : 8 ≤ 32),BitVec.setWidth_eq] using byte
  exact ⟨permitted,initialized,result⟩

/-- The completed imported checked read retains the same source heap,
profile, native memory and every architectural field. Only its real ordered
read event is appended, with initialization derived from the source load. -/
theorem load {m : CC.Mem} {stack : CC.Block} {origin : BitVec 64}
    {profile : MemoryProfile} {native : ArmState}
    (represented : Represents m stack origin profile native) (i : Fin 160) (value : BitVec 8)
    (loaded : CC.Mem.load .Mint8unsigned m stack (i.val : Int) = some (.Vint (value.setWidth 32))) :
    ∃ readState,
      MemoryMode.read .checked 1 (address origin i) native = .ok (value,readState) ∧
      Represents m stack origin profile readState ∧
      profile.initialized (address origin i) = true ∧
      readState.mem = native.mem ∧ readState.memoryProfile = native.memoryProfile ∧
      read_memory_accesses readState = read_memory_accesses native ++ [.memory .read (address origin i) [value] true] ∧
      readState.program = native.program ∧ readState.exclusive = native.exclusive ∧
      readState.atomicAccesses = native.atomicAccesses ∧ readState.threadPointerInputs = native.threadPointerInputs ∧
      (∀ field : StateField, r field readState = r field native) := by
  obtain ⟨permitted,initialized,byte⟩ := observed represented i value loaded
  let readState := record_memory_access (.memory .read (address origin i) [value] true) native
  have checked : MemoryMode.read .checked 1 (address origin i) native = .ok (value,readState) := by
    simp [MemoryMode.read,represented.profileRead,MemoryMode.permitted,permitted,initialized,
      read_mem_bytes,byte,readState,BitVec.cast]
    apply BitVec.eq_of_toNat_eq
    simpa only [BitVec.toNat_cast] using congrArg BitVec.toNat
      (BitVec.empty_bitvector_append_left value (by decide))
  have mapped : Represents m stack origin profile readState := by
    refine ⟨?_,represented.readable,represented.writable,?_⟩
    · simpa [readState,read_memory_profile,record_memory_access] using represented.profileRead
    · intro j readable
      simpa [readState,read_mem,record_memory_access] using represented.bytes j readable
  refine ⟨readState,checked,mapped,initialized,rfl,rfl,rfl,rfl,rfl,rfl,rfl,?_⟩
  intro field
  cases field <;> simp [readState,record_memory_access,r,read_base_gpr,read_base_sfp,read_base_pc,read_base_flag,read_base_error]

end KProgFormal.ClightRefinement.Arm64MemcpyPhysicalByteRead
