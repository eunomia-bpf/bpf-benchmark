import KProgFormal.GeneratedAbiLoad
import KProgFormal.GeneratedPtrAdd

namespace KProgFormal

/-- Two registers make register-to-register movement nontrivial while keeping
the first refinement slice small enough to audit. -/
inductive Reg
  | r0
  | r1
  deriving DecidableEq, Repr

/-- Union of the verifier-facing provenance tags in the current x86-64 and
AArch64 simulator implementations. Tags are not architectural state. -/
inductive Tag
  | scalar
  | abi
  | packet
  | packetEnd
  | stack
  | mapPtr
  | mapValue
  | helperId
  | relocAddr
  | rodataAddr
  deriving DecidableEq, Repr

/-- `Fin` arithmetic gives the target's modulo-2^64 register semantics. -/
abbrev Word := Fin (2 ^ 64)

structure TaggedWord where
  bits : Word
  tag : Tag
  deriving DecidableEq, Repr

structure ProofState where
  r0 : TaggedWord
  r1 : TaggedWord
  deriving DecidableEq, Repr

structure ArchState where
  r0 : Word
  r1 : Word
  deriving DecidableEq, Repr

structure TagState where
  r0 : Tag
  r1 : Tag
  deriving DecidableEq, Repr

/-- Values exposed by either simulator entry ABI. All bytes other than the two
initialized pointer fields are zero in the bounded ABI model. -/
structure AbiEnv where
  packet : Word
  packetEnd : Word
  deriving DecidableEq, Repr

abbrev AbiKind := GeneratedAbiLoad.Kind

def readAbi (env : AbiEnv) : AbiKind -> Int -> Word
  | .xdp, offset =>
      if offset == 0 then env.packet
      else if offset == 8 then env.packetEnd
      else 0
  | .skb, offset =>
      if offset == 208 then env.packet
      else if offset == 80 then env.packetEnd
      else 0

/-- Independent statement of the verifier-visible ABI provenance policy. -/
def abiTagSpec : AbiKind -> Int -> Tag
  | .xdp, offset =>
      if offset == 0 then .packet
      else if offset == 8 then .packetEnd
      else .scalar
  | .skb, offset =>
      if offset == 208 then .packet
      else if offset == 80 then .packetEnd
      else .scalar

def readProof (s : ProofState) : Reg -> TaggedWord
  | .r0 => s.r0
  | .r1 => s.r1

def writeProof (s : ProofState) (r : Reg) (v : TaggedWord) : ProofState :=
  match r with
  | .r0 => { s with r0 := v }
  | .r1 => { s with r1 := v }

def readArch (s : ArchState) : Reg -> Word
  | .r0 => s.r0
  | .r1 => s.r1

def writeArch (s : ArchState) (r : Reg) (v : Word) : ArchState :=
  match r with
  | .r0 => { s with r0 := v }
  | .r1 => { s with r1 := v }

def readTag (s : TagState) : Reg -> Tag
  | .r0 => s.r0
  | .r1 => s.r1

def writeTag (s : TagState) (r : Reg) (v : Tag) : TagState :=
  match r with
  | .r0 => { s with r0 := v }
  | .r1 => { s with r1 := v }

def eraseBits (s : ProofState) : ArchState :=
  { r0 := s.r0.bits, r1 := s.r1.bits }

def eraseTags (s : ProofState) : TagState :=
  { r0 := s.r0.tag, r1 := s.r1.tag }

/-- Shared register-transfer fragment. `ptrAdd64` is the pointer-shaped
x86 LEA/AArch64 ADD case; `mulImm64` represents an integer operation that
must scalarize verifier provenance. -/
inductive Op
  | mov64 (dst src : Reg)
  | ptrAdd64 (dst src : Reg) (rhs : Word)
  | mulImm64 (dst : Reg) (imm : Word)
  | loadAbi64 (dst : Reg) (kind : AbiKind) (offset : Int)
  deriving DecidableEq, Repr

/-- Pure architectural semantics, independent of verifier metadata. -/
def stepArch (env : AbiEnv) : Op -> ArchState -> ArchState
  | .mov64 dst src, s =>
      writeArch s dst (readArch s src)
  | .ptrAdd64 dst src rhs, s =>
      writeArch s dst (readArch s src + rhs)
  | .mulImm64 dst imm, s =>
      writeArch s dst (readArch s dst * imm)
  | .loadAbi64 dst kind offset, s =>
      writeArch s dst (readAbi env kind offset)

/-- Verifier-facing implementation model. The pointer-add bits and tag
transition comes from the same declarative source as the two C handlers; its
independent architectural and policy specifications below make operand or
provenance drift break the refinement theorems. The other operations remain
model-only in this proof slice. -/
def stepProof (env : AbiEnv) : Op -> ProofState -> ProofState
  | .mov64 dst src, s =>
      writeProof s dst (readProof s src)
  | .ptrAdd64 dst src rhs, s =>
      let old := readProof s src
      writeProof s dst {
        bits := GeneratedPtrAdd.bits old.bits rhs
        tag := GeneratedPtrAdd.tag old.tag
      }
  | .mulImm64 dst imm, s =>
      let old := readProof s dst
      writeProof s dst { bits := old.bits * imm, tag := .scalar }
  | .loadAbi64 dst kind offset, s =>
      writeProof s dst {
        bits := readAbi env kind offset
        tag := GeneratedAbiLoad.tag .scalar .packet .packetEnd kind offset
      }

/-- Declarative provenance policy: MOV copies, pointer-shaped ADD preserves,
and integer MUL scalarizes provenance. -/
def stepTagSpec : Op -> TagState -> TagState
  | .mov64 dst src, s =>
      writeTag s dst (readTag s src)
  | .ptrAdd64 dst src _, s =>
      writeTag s dst (readTag s src)
  | .mulImm64 dst _, s =>
      writeTag s dst .scalar
  | .loadAbi64 dst kind offset, s =>
      writeTag s dst (abiTagSpec kind offset)

theorem step_bits_sound (env : AbiEnv) (op : Op) (s : ProofState) :
    eraseBits (stepProof env op s) = stepArch env op (eraseBits s) := by
  cases op with
  | mov64 dst src =>
      cases dst <;> cases src <;> cases s <;> rfl
  | ptrAdd64 dst src rhs =>
      cases dst <;> cases src <;> cases s <;> rfl
  | mulImm64 dst imm =>
      cases dst <;> cases s <;> rfl
  | loadAbi64 dst kind offset =>
      cases dst <;> cases kind <;> cases env <;> cases s <;> rfl

theorem step_tags_sound (env : AbiEnv) (op : Op) (s : ProofState) :
    eraseTags (stepProof env op s) = stepTagSpec op (eraseTags s) := by
  cases op with
  | mov64 dst src =>
      cases dst <;> cases src <;> cases s <;> rfl
  | ptrAdd64 dst src rhs =>
      cases dst <;> cases src <;> cases s <;> rfl
  | mulImm64 dst imm =>
      cases dst <;> cases s <;> rfl
  | loadAbi64 dst kind offset =>
      cases dst <;> cases kind <;> cases env <;> cases s <;> rfl

def runArch (env : AbiEnv) : List Op -> ArchState -> ArchState
  | [], s => s
  | op :: rest, s => runArch env rest (stepArch env op s)

def runProof (env : AbiEnv) : List Op -> ProofState -> ProofState
  | [], s => s
  | op :: rest, s => runProof env rest (stepProof env op s)

def runTagSpec : List Op -> TagState -> TagState
  | [], s => s
  | op :: rest, s => runTagSpec rest (stepTagSpec op s)

theorem run_bits_sound (env : AbiEnv) (ops : List Op) (s : ProofState) :
    eraseBits (runProof env ops s) = runArch env ops (eraseBits s) := by
  induction ops generalizing s with
  | nil => rfl
  | cons op rest ih =>
      simp only [runProof, runArch]
      calc
        eraseBits (runProof env rest (stepProof env op s)) =
            runArch env rest (eraseBits (stepProof env op s)) :=
              ih (stepProof env op s)
        _ = runArch env rest (stepArch env op (eraseBits s)) := by
              rw [step_bits_sound env]

theorem run_tags_sound (env : AbiEnv) (ops : List Op) (s : ProofState) :
    eraseTags (runProof env ops s) = runTagSpec ops (eraseTags s) := by
  induction ops generalizing s with
  | nil => rfl
  | cons op rest ih =>
      simp only [runProof, runTagSpec]
      calc
        eraseTags (runProof env rest (stepProof env op s)) =
            runTagSpec rest (eraseTags (stepProof env op s)) :=
              ih (stepProof env op s)
        _ = runTagSpec rest (stepTagSpec op (eraseTags s)) := by
              rw [step_tags_sound env]

/-- First machine-checked refinement theorem for the shared register
fragment: architectural fidelity after erasure and sound verifier-provenance
transitions. -/
theorem run_refines_arch_and_tags (env : AbiEnv) (ops : List Op) (s : ProofState) :
    eraseBits (runProof env ops s) = runArch env ops (eraseBits s) /\
    eraseTags (runProof env ops s) = runTagSpec ops (eraseTags s) :=
  And.intro (run_bits_sound env ops s) (run_tags_sound env ops s)

end KProgFormal
