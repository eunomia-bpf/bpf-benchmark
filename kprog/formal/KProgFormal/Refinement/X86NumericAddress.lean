import KProgFormal.Refinement.EntryEnvironment
import KProgFormal.X86RegWrite

namespace KProgFormal.Refinement.X86NumericAddress
open Reference EntryEnvironment

abbrev NativeWord := Reference.Word

/-- Typed stack aliases address the private arena. Numeric observations replace
only its origin with the invocation's bound native entry-stack origin. -/
def projectAddress (env : Environment) (frame : Frame) (arena pointer : NativeWord) : NativeWord :=
  pointer - arena + base env frame .stack

theorem project_refines (env : Environment) (frame : Frame) (arena offset : NativeWord) :
    projectAddress env frame arena (arena + offset) =
      materialize env frame (.relative .stack offset) := by
  simp only [projectAddress, materialize]
  rw [BitVec.add_comm arena offset, BitVec.add_sub_cancel, BitVec.add_comm]

/-- Scalar RSP writes normalize native bits; typed-alias RSP writes normalize
the corresponding private pointer. Both preserve the actual architectural SP. -/
theorem scalar_stack_write_refines (env : Environment) (frame : Frame) (bits : NativeWord) :
    base env frame .stack + (bits - base env frame .stack) = bits := by
  rw [BitVec.add_comm, BitVec.sub_add_cancel]

theorem alias_stack_write_refines (env : Environment) (frame : Frame)
    (arena offset : NativeWord) :
    base env frame .stack + ((arena + offset) - arena) =
      materialize env frame (.relative .stack offset) := by
  simp only [materialize]
  rw [BitVec.add_comm arena offset, BitVec.add_sub_cancel]

/-- LEA RSP,[RSP+d] must normalize once, after adding to the native value;
normalizing an already relative value subtracts the native base twice. -/
theorem stack_lea_refines (env : Environment) (frame : Frame) (offset delta : NativeWord) :
    base env frame .stack + ((base env frame .stack + offset + delta) -
      base env frame .stack) = base env frame .stack + (offset + delta) := by
  rw [scalar_stack_write_refines, BitVec.add_assoc]

/-- Partial writes merge with native address bits before dropping the pointer
origin. The existing generated write theorem supplies every width and byte lane. -/
theorem partial_write_refines (env : Environment) (frame : Frame)
    (arena offset value : NativeWord) (tag : KProgFormal.Tag)
    (width : KProgFormal.X86Width) (lane : KProgFormal.X86ByteLane) :
    KProgFormal.generatedX86RegWriteAt
      { bits := projectAddress env frame arena (arena + offset), tag := tag } value width lane =
    KProgFormal.x86RegWriteAtSpec
      { bits := materialize env frame (.relative .stack offset), tag := tag } value width lane := by
  rw [project_refines, KProgFormal.x86_reg_write_at_refines]

/-- Guest stores contain native address bytes, never the arena pointer bytes. -/
theorem stored_alias_bytes (env : Environment) (frame : Frame)
    (arena offset : NativeWord) (bytes : Nat) :
    valueBytes (projectAddress env frame arena (arena + offset)) bytes =
      valueBytes (base env frame .stack + offset) bytes := by
  rw [project_refines]
  rfl

end KProgFormal.Refinement.X86NumericAddress
