import TrustedSimpleB29Blocks

/-! Physical payload embedding for the fresh published-CMP capture20e29.
The complete current82-byte JIT image is literal, including its own return
displacement. Only the emitted P60 body is transported here; host wrapper
memory effects and caller/platform provenance are separate obligations. -/
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleB29Embedding
open KProgFormal.Reference TrustedSimpleX86 TrustedSimpleSafety

def image : Array Byte := #[0xf,0x1f,0x44,0x0,0x0,0xf,0x1f,0x0,0x55,0x48,0x89,0xe5,0x41,0x57,0x48,0x8b,0xf,0x48,0x8b,0x57,0x8,0x48,0x89,0xce,0x31,0xc0,0x48,0x39,0xd6,0x77,0x2b,0x48,0x8d,0x7e,0x8,0x48,0x39,0xd7,0x77,0x22,0x48,0x83,0xc6,0x48,0x48,0x39,0xd6,0x77,0x19,0x66,0xc7,0x1,0x4e,0x61,0xc6,0x41,0x2,0xbc,0xc7,0x41,0x3,0x0,0x0,0x0,0x0,0xc6,0x41,0x7,0x0,0xb8,0x2,0x0,0x0,0x0,0x41,0x5f,0xc9,0xe9,0xbe,0x2f,0xc1,0xdf]
theorem image_size : image.size=82 := rfl
theorem emitted_payload : image.extract 14 74=native := by decide

theorem physical_decode_length_shape_0 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 14 (14+length))=
      if length<simpleNativeLength 0 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 0)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_3 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 17 (17+length))=
      if length<simpleNativeLength 3 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 3)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_7 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 21 (21+length))=
      if length<simpleNativeLength 7 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 7)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_10 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 24 (24+length))=
      if length<simpleNativeLength 10 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 10)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_12 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 26 (26+length))=
      if length<simpleNativeLength 12 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 12)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_15 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 29 (29+length))=
      if length<simpleNativeLength 15 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 15)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_17 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 31 (31+length))=
      if length<simpleNativeLength 17 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 17)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_21 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 35 (35+length))=
      if length<simpleNativeLength 21 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 21)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_24 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 38 (38+length))=
      if length<simpleNativeLength 24 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 24)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_26 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 40 (40+length))=
      if length<simpleNativeLength 26 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 26)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_30 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 44 (44+length))=
      if length<simpleNativeLength 30 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 30)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_33 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 47 (47+length))=
      if length<simpleNativeLength 33 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 33)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_35 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 49 (49+length))=
      if length<simpleNativeLength 35 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 35)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_40 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 54 (54+length))=
      if length<simpleNativeLength 40 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 40)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_44 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 58 (58+length))=
      if length<simpleNativeLength 44 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 44)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_51 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 65 (65+length))=
      if length<simpleNativeLength 51 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 51)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape_55 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract 69 (69+length))=
      if length<simpleNativeLength 55 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 55)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,image]; canonical_x86_decode)

theorem physical_decode_length_shape (s : X86.State) (offset length : Nat)
    (member : offset ∈ simpleNativeOffsets) (bounded : length≤15) :
    decodedNativeFallthrough s (image.extract (14+offset) (14+offset+length))=
      if length<simpleNativeLength offset then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength offset)) := by
  have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · exact physical_decode_length_shape_0 s length bounded
  · exact physical_decode_length_shape_3 s length bounded
  · exact physical_decode_length_shape_7 s length bounded
  · exact physical_decode_length_shape_10 s length bounded
  · exact physical_decode_length_shape_12 s length bounded
  · exact physical_decode_length_shape_15 s length bounded
  · exact physical_decode_length_shape_17 s length bounded
  · exact physical_decode_length_shape_21 s length bounded
  · exact physical_decode_length_shape_24 s length bounded
  · exact physical_decode_length_shape_26 s length bounded
  · exact physical_decode_length_shape_30 s length bounded
  · exact physical_decode_length_shape_33 s length bounded
  · exact physical_decode_length_shape_35 s length bounded
  · exact physical_decode_length_shape_40 s length bounded
  · exact physical_decode_length_shape_44 s length bounded
  · exact physical_decode_length_shape_51 s length bounded
  · exact physical_decode_length_shape_55 s length bounded

/-- Every complete captured instruction slice in this physical image is
exactly the corresponding native payload slice. -/
theorem payload_instruction_bytes (offset : Nat) (member : offset ∈ simpleNativeOffsets) :
    image.extract (14+offset) (14+offset+simpleNativeLength offset)=
      native.extract offset (offset+simpleNativeLength offset) := by
  have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals decide

/-- Accepted arbitrary physical extents at any body PC have exactly the
captured start/length, even when their input slice includes epilogue bytes. -/
theorem physical_extent_unique (base : Word) (s : X86.State) (offset : Nat)
    (entry : X86Path.Entry) (instruction : X86.Instruction)
    (member : offset ∈ simpleNativeOffsets)
    (position : s.pc=base+BitVec.ofNat 64 (14+offset))
    (accepted : X86Path.decodeAt base image entry s=.ok instruction) :
    entry.offset=14+offset ∧ entry.length=simpleNativeLength offset := by
  obtain ⟨pc,positive,bounded,inside,fall⟩ := decode_extent_constraints base image entry s instruction accepted
  obtain ⟨offsetBound,_,lengthBound⟩ := simple_native_metadata_bounds offset member
  have starts : base+BitVec.ofNat 64 entry.offset=base+BitVec.ofNat 64 (14+offset) := pc.symm.trans position
  have words := (BitVec.add_right_inj base).mp starts
  have nats := congrArg BitVec.toNat words
  change entry.offset % 18446744073709551616=(14+offset) % 18446744073709551616 at nats
  have codeBound : entry.offset+entry.length≤82 := inside
  have start : entry.offset=14+offset := by omega
  have raw := decode_extent_reflects_raw base image entry s instruction accepted
  have projected : decodedNativeFallthrough s (image.extract (14+offset) (14+offset+entry.length))=
      some (X86.Instruction.fallthrough instruction) := by
    rw [← start]
    unfold decodedNativeFallthrough
    rw [raw]
  have shape := physical_decode_length_shape s offset entry.length member bounded
  rw [projected] at shape
  by_cases truncated : entry.length<simpleNativeLength offset
  · simp only [truncated,ite_true] at shape
    cases shape
  · simp only [truncated,ite_false] at shape
    have sameFall := Option.some.inj shape
    have sameSum : s.pc+BitVec.ofNat 64 entry.length=s.pc+BitVec.ofNat 64 (simpleNativeLength offset) :=
      fall.symm.trans sameFall
    have lengths := (BitVec.add_right_inj s.pc).mp sameSum
    have sizes := congrArg BitVec.toNat lengths
    change entry.length % 18446744073709551616=(simpleNativeLength offset) % 18446744073709551616 at sizes
    exact ⟨start,by omega⟩

/-- Reflect actual physical-image decoding to the standalone payload at its
real emitted base, preserving the very same decoded canonical instruction. -/
theorem physical_decode_reflects (base : Word) (s : X86.State) (offset : Nat)
    (entry : X86Path.Entry) (instruction : X86.Instruction)
    (member : offset ∈ simpleNativeOffsets)
    (position : s.pc=(base+(14#64))+BitVec.ofNat 64 offset)
    (accepted : X86Path.decodeAt base image entry s=.ok instruction) :
    X86Path.decodeAt (base+(14#64)) native ⟨offset,simpleNativeLength offset⟩ s=.ok instruction := by
  have position' : s.pc=base+BitVec.ofNat 64 (14+offset) := by
    simpa only [BitVec.ofNat_add,BitVec.add_assoc] using position
  obtain ⟨start,length⟩ := physical_extent_unique base s offset entry instruction member position' accepted
  have raw := decode_extent_reflects_raw base image entry s instruction accepted
  rw [start,length,payload_instruction_bytes offset member] at raw
  obtain ⟨_,positive,bounded,_,fall⟩ := decode_extent_constraints base image entry s instruction accepted
  rw [length] at positive bounded fall
  have inside : offset+simpleNativeLength offset≤native.size := by
    have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
      simpa [simpleNativeOffsets] using member
    rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
    all_goals decide
  have nonzero : simpleNativeLength offset≠0 := by omega
  have notLong : ¬15<simpleNativeLength offset := by omega
  have notOutside : ¬native.size<offset+simpleNativeLength offset := by omega
  simp +decide [X86Path.decodeAt,position,nonzero,notLong,notOutside,raw,fall,
    X86Path.fallthrough,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]

/-- Segmentation at payload end, not an inserted runtime guard. Host wrapper
instructions after bodyPC74 have their own retained stack effects and are
outside P60, so a payload prefix ends before executing the wrapper epilogue. -/
def payloadInstructionStep (base : Word) (bytes : Array Byte) : BlockStep X86.State :=
  fun before events after => before.pc≠base+(74#64) ∧
    relationalNativeInstructionStep base bytes before events after

theorem physical_payload_step_reflects (base : Word) (s : X86.State)
    (valid : simpleClosedPC s.pc) {events : List Event} {next : X86.State}
    (step : payloadInstructionStep base image (shiftNativeState (base+(14#64)) s) events next) :
    ∃ logicalNext, relationalNativeInstructionStep 0 native s events logicalNext ∧
      shiftNativeState (base+(14#64)) logicalNext=next ∧ simpleClosedPC logicalNext.pc := by
  obtain ⟨beforeEnd,entry,instruction,actual,decoded,actualRun,traceEq,stateEq⟩ := step
  rcases List.mem_append.mp valid with member | atEnd
  · have position : (shiftNativeState (base+(14#64)) s).pc=
        (base+(14#64))+BitVec.ofNat 64 s.pc.toNat := by simp [shiftNativeState]
    have payloadDecoded := physical_decode_reflects base _ s.pc.toNat entry instruction member position decoded
    exact simple_native_based_step_reflects (base+(14#64)) s (List.mem_append_left _ member)
      ⟨⟨s.pc.toNat,simpleNativeLength s.pc.toNat⟩,instruction,actual,payloadDecoded,actualRun,traceEq,stateEq⟩
  · have endPC : s.pc=60 := by
      apply BitVec.eq_of_toNat_eq
      simpa only [List.mem_singleton] using atEnd
    exact False.elim (beforeEnd (by simp only [shiftNativeState,endPC,BitVec.add_assoc]; rfl))

/-- Arbitrary physical payload prefixes reflect to canonical logical native
execution with identical events and full translated architectural endpoint.
Arbitrary accepted extents, either successor, faults and undefined AF remain
covered; there is no fuel or selected-path premise. -/
theorem physical_payload_execution_reflects (base : Word)
    {first last : X86.State} {events : List Event}
    (run : Execution (payloadInstructionStep base image) first events last)
    (s : X86.State) (valid : simpleClosedPC s.pc)
    (starts : shiftNativeState (base+(14#64)) s=first) :
    ∃ logicalLast, Execution (relationalNativeInstructionStep 0 native) s events logicalLast ∧
      shiftNativeState (base+(14#64)) logicalLast=last := by
  induction run generalizing s with
  | refl physical => exact ⟨s,Execution.refl s,starts⟩
  | @next physical middle last head tail headStep tailRun ih =>
    have normalized : payloadInstructionStep base image (shiftNativeState (base+(14#64)) s) head middle := by
      rw [starts]; exact headStep
    obtain ⟨logicalMiddle,logicalHead,middleEq,middleValid⟩ := physical_payload_step_reflects base s valid normalized
    obtain ⟨logicalLast,logicalTail,lastEq⟩ := ih logicalMiddle middleValid middleEq
    exact ⟨logicalLast,Execution.next logicalHead logicalTail,lastEq⟩

/-- The actual emitted-image payload, accepted B29 and exact P60 binding
compose through physical decoding, complete-state code-origin transport and
the canonical arbitrary-prefix theorem. Caller/prologue/epilogue memory
operations are retained separately; this theorem covers P60 effects only. -/
theorem bound_physical_payload_prefix_effects_checked (env : BPF.Environment)
    (base : Word) (loadedImage : Array Byte) (emission : loadedImage=image)
    (n : X86.State) (p : BPF.State)
    (validated executed : Artifact) (binding : executed=validated)
    (nativeImage : validated.nativeBytes=native.toList)
    (proofImage : validated.proofBytes=TrustedSimpleB29.proof.toList) (entryImage : validated.entry=0)
    (accepted : Artifact → Prop) (proofEntry : Artifact → BPF.State → Prop)
    (checked : Artifact → Event → Prop)
    (verifierSound : ∀ artifact, accepted artifact → proofEntry artifact p →
      ∀ trace last, Execution (TrustedSimpleB29.boundProofStep env artifact) p trace last →
        ∀ event ∈ trace, checked artifact event)
    (acceptance : accepted validated) (admitted : proofEntry validated p)
    {events : List Event} {last : X86.State}
    (run : Execution (payloadInstructionStep base loadedImage) n events last)
    (stack : Word) (nativePC : n.pc=base+(14#64)) (proofPC : p.pc=0) (active : p.halted=false)
    (argument : n.gpr 7=p.regs 1) (memory : n.memory=p.memory)
    (nativeStack : env.nativeInput .stackPointer=.ok stack) :
    ∀ event ∈ events, checked validated event := by
  have physicalRun : Execution (payloadInstructionStep base image) n events last := by
    simpa only [emission] using run
  let logical := shiftNativeState (-(base+(14#64))) n
  have logicalPC : logical.pc=0 := by
    dsimp only [logical,shiftNativeState]
    rw [nativePC]
    unfold Word at *
    bv_decide
  have starts : shiftNativeState (base+(14#64)) logical=n := by
    simpa only [logical,BitVec.neg_neg] using shift_native_state_inverse (-(base+(14#64))) n
  have valid : simpleClosedPC logical.pc := by
    simp [simpleClosedPC,simpleNativeOffsets,logicalPC]
  obtain ⟨logicalLast,logicalRun,_⟩ :=
    physical_payload_execution_reflects base physicalRun logical valid starts
  have boundLogical : Execution (relationalNativeInstructionStep
      (BitVec.ofNat 64 executed.entry) executed.nativeBytes.toArray) logical events logicalLast := by
    simpa only [binding,nativeImage,entryImage,Array.toArray_toList] using logicalRun
  exact TrustedSimpleB29.bound_native_prefix_effects_checked env logical p validated executed binding
    nativeImage proofImage entryImage accepted proofEntry checked verifierSound acceptance admitted
    boundLogical stack logicalPC proofPC active argument memory nativeStack

end KProgTV.TrustedSimpleB29Embedding
#print axioms KProgTV.TrustedSimpleB29Embedding.emitted_payload
#print axioms KProgTV.TrustedSimpleB29Embedding.physical_decode_length_shape
#print axioms KProgTV.TrustedSimpleB29Embedding.payload_instruction_bytes

#print axioms KProgTV.TrustedSimpleB29Embedding.physical_extent_unique

#print axioms KProgTV.TrustedSimpleB29Embedding.physical_decode_reflects

#print axioms KProgTV.TrustedSimpleB29Embedding.physical_payload_step_reflects

#print axioms KProgTV.TrustedSimpleB29Embedding.physical_payload_execution_reflects

#print axioms KProgTV.TrustedSimpleB29Embedding.bound_physical_payload_prefix_effects_checked
