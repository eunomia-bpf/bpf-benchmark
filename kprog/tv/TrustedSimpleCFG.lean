import TrustedSimpleX86

set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.TrustedSimpleX86
open KProgFormal.Reference


/-- Captured CFG metadata only; each length is checked against the single
canonical decoder below, including all truncations and extra suffix bytes. -/
def simpleNativeOffsets : List Nat := [0, 3, 7, 10, 12, 15, 17, 21, 24, 26, 30, 33, 35, 40, 44, 51, 55]

def simpleNativeLength : Nat → Nat
  | 0 => 3
  | 3 => 4
  | 7 => 3
  | 10 => 2
  | 12 => 3
  | 15 => 2
  | 17 => 4
  | 21 => 3
  | 24 => 2
  | 26 => 4
  | 30 => 3
  | 33 => 2
  | 35 => 5
  | 40 => 4
  | 44 => 7
  | 51 => 4
  | 55 => 5
  | _ => 0

/-- Projection of the canonical decoder, not a new decoder or ISA step. -/
def decodedNativeFallthrough (s : X86.State) (bytes : Array Byte) : Option Word :=
  match X86.decode bytes s with
  | .error _ => none
  | .ok instruction => some (X86.Instruction.fallthrough instruction)

theorem simple_native_metadata_bounds (offset : Nat) (member : offset ∈ simpleNativeOffsets) :
    offset<60 ∧ 0<simpleNativeLength offset ∧ simpleNativeLength offset≤15 := by
  have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> decide

theorem simple_native_decode_length_shape_0 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 0 (0+length)) =
      if length<simpleNativeLength 0 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 0)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_3 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 3 (3+length)) =
      if length<simpleNativeLength 3 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 3)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_7 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 7 (7+length)) =
      if length<simpleNativeLength 7 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 7)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_10 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 10 (10+length)) =
      if length<simpleNativeLength 10 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 10)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_12 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 12 (12+length)) =
      if length<simpleNativeLength 12 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 12)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_15 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 15 (15+length)) =
      if length<simpleNativeLength 15 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 15)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_17 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 17 (17+length)) =
      if length<simpleNativeLength 17 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 17)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_21 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 21 (21+length)) =
      if length<simpleNativeLength 21 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 21)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_24 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 24 (24+length)) =
      if length<simpleNativeLength 24 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 24)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_26 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 26 (26+length)) =
      if length<simpleNativeLength 26 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 26)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_30 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 30 (30+length)) =
      if length<simpleNativeLength 30 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 30)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_33 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 33 (33+length)) =
      if length<simpleNativeLength 33 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 33)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_35 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 35 (35+length)) =
      if length<simpleNativeLength 35 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 35)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_40 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 40 (40+length)) =
      if length<simpleNativeLength 40 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 40)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_44 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 44 (44+length)) =
      if length<simpleNativeLength 44 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 44)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_51 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 51 (51+length)) =
      if length<simpleNativeLength 51 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 51)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

theorem simple_native_decode_length_shape_55 (s : X86.State) (length : Nat)
    (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract 55 (55+length)) =
      if length<simpleNativeLength 55 then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength 55)) := by
  have lengths : length=0 ∨ length=1 ∨ length=2 ∨ length=3 ∨ length=4 ∨ length=5 ∨ length=6 ∨ length=7 ∨ length=8 ∨ length=9 ∨ length=10 ∨ length=11 ∨ length=12 ∨ length=13 ∨ length=14 ∨ length=15 := by omega
  rcases lengths with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals first
    | rfl
    | (simp only [decodedNativeFallthrough,simpleNativeLength,native]; canonical_x86_decode)

/-- All candidate lengths0..15 at the17 actual entries are checked by
canonical decoding. Each finite check has a separately audited proof. -/
theorem simple_native_decode_length_shape (s : X86.State) (offset length : Nat)
    (member : offset ∈ simpleNativeOffsets) (bounded : length≤15) :
    decodedNativeFallthrough s (native.extract offset (offset+length)) =
      if length<simpleNativeLength offset then none
      else some (s.pc+BitVec.ofNat 64 (simpleNativeLength offset)) := by
  have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · exact simple_native_decode_length_shape_0 s length bounded
  · exact simple_native_decode_length_shape_3 s length bounded
  · exact simple_native_decode_length_shape_7 s length bounded
  · exact simple_native_decode_length_shape_10 s length bounded
  · exact simple_native_decode_length_shape_12 s length bounded
  · exact simple_native_decode_length_shape_15 s length bounded
  · exact simple_native_decode_length_shape_17 s length bounded
  · exact simple_native_decode_length_shape_21 s length bounded
  · exact simple_native_decode_length_shape_24 s length bounded
  · exact simple_native_decode_length_shape_26 s length bounded
  · exact simple_native_decode_length_shape_30 s length bounded
  · exact simple_native_decode_length_shape_33 s length bounded
  · exact simple_native_decode_length_shape_35 s length bounded
  · exact simple_native_decode_length_shape_40 s length bounded
  · exact simple_native_decode_length_shape_44 s length bounded
  · exact simple_native_decode_length_shape_51 s length bounded
  · exact simple_native_decode_length_shape_55 s length bounded

/-- Successful decodeAt supplies all extent/PC guards and the decoded
fallthrough. These are conclusions, never new path assumptions. -/
theorem decode_extent_constraints (base : Word) (bytes : Array Byte) (entry : X86Path.Entry)
    (s : X86.State) (instruction : X86.Instruction)
    (accepted : X86Path.decodeAt base bytes entry s=.ok instruction) :
    s.pc=base+BitVec.ofNat 64 entry.offset ∧ 0<entry.length ∧ entry.length≤15 ∧
      entry.offset+entry.length≤bytes.size ∧
      X86.Instruction.fallthrough instruction=s.pc+BitVec.ofNat 64 entry.length := by
  have raw := decode_extent_reflects_raw base bytes entry s instruction accepted
  unfold X86Path.decodeAt at accepted
  simp only [Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad,raw] at accepted
  split at accepted
  · simp at accepted
  · rename_i pcGood
    split at accepted
    · simp at accepted
    · rename_i lengthGood
      split at accepted
      · simp at accepted
      · rename_i inside
        split at accepted
        · simp at accepted
        · rename_i fallGood
          have pc : s.pc=base+BitVec.ofNat 64 entry.offset := by simpa using pcGood
          have lengths : entry.length≠0 ∧ entry.length≤15 := by simpa using lengthGood
          have fall : X86.Instruction.fallthrough instruction=s.pc+BitVec.ofNat 64 entry.length := by
            simpa using fallGood
          exact ⟨pc,by omega,lengths.2,by omega,fall⟩

/-- At a captured instruction PC, no accepted arbitrary extent can select
another start or length. Canonical decode and its actual consumed bytes
establish both fields; neither is supplied by the caller. -/
theorem simple_native_extent_unique (s : X86.State) (offset : Nat) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (member : offset ∈ simpleNativeOffsets)
    (position : s.pc=BitVec.ofNat 64 offset)
    (accepted : X86Path.decodeAt 0 native entry s=.ok instruction) :
    entry.offset=offset ∧ entry.length=simpleNativeLength offset := by
  obtain ⟨pc,positive,bounded,inside,fall⟩ := decode_extent_constraints 0 native entry s instruction accepted
  obtain ⟨offsetBound,_,lengthBound⟩ := simple_native_metadata_bounds offset member
  have zeroPlus (v : Word) : (0 : Word)+v=v := BitVec.zero_add v
  have startWords : BitVec.ofNat 64 entry.offset=BitVec.ofNat 64 offset := by
    simpa only [zeroPlus] using pc.symm.trans position
  have startNats := congrArg BitVec.toNat startWords
  change entry.offset % 18446744073709551616=offset % 18446744073709551616 at startNats
  have codeBound : entry.offset+entry.length≤60 := inside
  have start : entry.offset=offset := by omega
  have raw := decode_extent_reflects_raw 0 native entry s instruction accepted
  have projected : decodedNativeFallthrough s (native.extract offset (offset+entry.length))=
      some (X86.Instruction.fallthrough instruction) := by
    rw [← start]
    unfold decodedNativeFallthrough
    rw [raw]
  have shape := simple_native_decode_length_shape s offset entry.length member bounded
  rw [projected] at shape
  by_cases truncated : entry.length<simpleNativeLength offset
  · simp only [truncated,ite_true] at shape
    cases shape
  · simp only [truncated,ite_false] at shape
    have sameFall := Option.some.inj shape
    have sameSum : s.pc+BitVec.ofNat 64 entry.length=s.pc+BitVec.ofNat 64 (simpleNativeLength offset) :=
      fall.symm.trans sameFall
    have lengthWords : BitVec.ofNat 64 entry.length=BitVec.ofNat 64 (simpleNativeLength offset) :=
      (BitVec.add_right_inj s.pc).mp sameSum
    have lengthNats := congrArg BitVec.toNat lengthWords
    change entry.length % 18446744073709551616=(simpleNativeLength offset) % 18446744073709551616 at lengthNats
    exact ⟨start,by omega⟩


/-- Canonical relational observation masks never alter PC, memory, events
or faults. Only the ISA's explicitly undefined flags/register bits vary. -/
theorem canonical_relational_observed_fields (instruction : X86.Instruction)
    (s : X86.State) (actual : Transition X86.State) (run : X86.Step instruction s actual) :
    actual.state.pc=(X86.step instruction s).state.pc ∧
    actual.state.memory=(X86.step instruction s).state.memory ∧
    actual.events=(X86.step instruction s).events ∧ actual.fault=(X86.step instruction s).fault := by
  obtain ⟨events,fault,states⟩ := run
  exact ⟨(congrArg X86.State.pc states).symm,(congrArg X86.State.memory states).symm,
    events.symm,fault.symm⟩

def simpleClosedPC (pc : Word) : Prop := pc.toNat ∈ simpleNativeOffsets++[60]

theorem simple_native_canonical_successor (s : X86.State) (offset : Nat)
    (member : offset ∈ simpleNativeOffsets) (position : s.pc=BitVec.ofNat 64 offset) :
    match X86.decode (native.extract offset (offset+simpleNativeLength offset)) s with
    | .error _ => False
    | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc := by
  have choices : offset=0 ∨ offset=3 ∨ offset=7 ∨ offset=10 ∨ offset=12 ∨ offset=15 ∨ offset=17 ∨ offset=21 ∨ offset=24 ∨ offset=26 ∨ offset=30 ∨ offset=33 ∨ offset=35 ∨ offset=40 ∨ offset=44 ∨ offset=51 ∨ offset=55 := by
    simpa [simpleNativeOffsets] using member
  rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · change (match X86.decode (native.extract 0 3) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode0]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 3 7) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode3]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 7 10) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode7]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 10 12) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode10]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 12 15) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode12]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 15 17) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode15]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 17 21) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode17]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 21 24) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode21]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 24 26) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode24]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 26 30) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode26]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 30 33) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode30]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 33 35) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode33]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 35 40) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode35]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 40 44) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode40]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 44 51) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode44]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 51 55) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode51]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])
  · change (match X86.decode (native.extract 55 60) s with
      | .error _ => False
      | .ok instruction => simpleClosedPC (X86.step instruction s).state.pc)
    rw [native_decode55]
    simp +decide [simpleClosedPC,simpleNativeOffsets,position,X86.step,X86.moveStep,
      X86.arithmeticStep,X86.logicalStep,X86.scalarRead,X86.scalarWrite,X86.readSource,
      X86.ScalarDestination.source,X86.ScalarWidth.bytes,writeMemory,
      Except.map,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
    all_goals repeat' (split <;> simp_all [simpleClosedPC,simpleNativeOffsets])


/-- There is no decoded instruction after the actual60-byte payload end. -/
theorem simple_native_end_no_decode (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (position : s.pc=60)
    (accepted : X86Path.decodeAt 0 native entry s=.ok instruction) : False := by
  obtain ⟨pc,positive,_,inside,_⟩ := decode_extent_constraints 0 native entry s instruction accepted
  have zeroPlus (v : Word) : (0 : Word)+v=v := by unfold Word at *; bv_decide
  have words : BitVec.ofNat 64 entry.offset=(60#64) := by
    simpa only [zeroPlus] using pc.symm.trans position
  have nats := congrArg BitVec.toNat words
  change entry.offset % 18446744073709551616=60 at nats
  have codeBound : entry.offset+entry.length≤60 := inside
  omega

/-- Arbitrary decoded extents and arbitrary canonical relational outputs
stay in the actual captured CFG; supplied successor annotations are unused. -/
theorem simple_native_relational_step_closed (s : X86.State) (entry : X86Path.Entry)
    (instruction : X86.Instruction) (actual : Transition X86.State)
    (valid : simpleClosedPC s.pc)
    (accepted : X86Path.decodeAt 0 native entry s=.ok instruction)
    (run : X86.Step instruction s actual) : simpleClosedPC actual.state.pc := by
  rcases List.mem_append.mp valid with start | finish
  · have position : s.pc=BitVec.ofNat 64 s.pc.toNat := by simp
    obtain ⟨offset,length⟩ := simple_native_extent_unique s s.pc.toNat entry instruction start position accepted
    have raw := decode_extent_reflects_raw 0 native entry s instruction accepted
    rw [offset,length] at raw
    have canonical := simple_native_canonical_successor s s.pc.toNat start position
    rw [raw] at canonical
    rw [(canonical_relational_observed_fields instruction s actual run).1]
    exact canonical
  · have endPC : s.pc=60 := by
      have asNat : s.pc.toNat=60 := by simpa only [List.mem_singleton] using finish
      apply BitVec.eq_of_toNat_eq
      simpa using asNat
    exact False.elim (simple_native_end_no_decode s entry instruction endPC accepted)

theorem simple_native_relational_path_closed {entries : List X86Path.Entry}
    {s : X86.State} {actual : Transition X86.State}
    (run : CanonicalRelationalPath 0 native entries s actual)
    (valid : simpleClosedPC s.pc) : simpleClosedPC actual.state.pc := by
  induction run with
  | nil state => exact valid
  | fault entry instruction decoded step failed =>
    exact simple_native_relational_step_closed _ entry instruction _ valid decoded step
  | next entry instruction decoded step continued suffix ih =>
    exact ih (simple_native_relational_step_closed _ entry instruction _ valid decoded step)

end KProgTV.TrustedSimpleX86

#print axioms KProgTV.TrustedSimpleX86.simple_native_metadata_bounds

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_0

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_3

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_7

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_10

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_12

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_15

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_17

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_21

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_24

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_26

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_30

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_33

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_35

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_40

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_44

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_51

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape_55

#print axioms KProgTV.TrustedSimpleX86.simple_native_decode_length_shape

#print axioms KProgTV.TrustedSimpleX86.decode_extent_constraints

#print axioms KProgTV.TrustedSimpleX86.simple_native_extent_unique


#print axioms KProgTV.TrustedSimpleX86.canonical_relational_observed_fields

#print axioms KProgTV.TrustedSimpleX86.simple_native_canonical_successor

#print axioms KProgTV.TrustedSimpleX86.simple_native_end_no_decode

#print axioms KProgTV.TrustedSimpleX86.simple_native_relational_step_closed

#print axioms KProgTV.TrustedSimpleX86.simple_native_relational_path_closed
