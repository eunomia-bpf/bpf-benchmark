import KProgFormal.Refinement.EntryEnvironment

namespace KProgFormal.Refinement.Arm64NumericAddress
open Reference EntryEnvironment

/-- The C cells retain relative payloads; numeric reads observe their
materialization in the same invocation and certified entry frame. -/
structure Cells where
  gpr : Reference.AArch64.Gpr → Value
  stackOffset : Word

def read (env : Environment) (frame : Frame) (cells : Cells) :
    Reference.AArch64.RegisterRef → Word
  | .general r => materialize env frame (cells.gpr r)
  | .zero => 0
  | .stack => base env frame .stack + cells.stackOffset

structure Related (env : Environment) (frame : Frame) (cells : Cells)
    (native : Reference.AArch64.State) : Prop where
  registers : ∀ r, materialize env frame (cells.gpr r) = native.gpr r
  stack : base env frame .stack + cells.stackOffset = native.sp

theorem read_refines (env : Environment) (frame : Frame) (cells : Cells)
    (native : Reference.AArch64.State) (relation : Related env frame cells native)
    (register : Reference.AArch64.RegisterRef) :
    read env frame cells register = Reference.AArch64.readData native register := by
  cases register with
  | general r => exact relation.registers r
  | zero => rfl
  | stack => exact relation.stack

/-- A scalar write to SP first narrows the actual bits, then normalizes the
stored offset. Truncating the old offset would lose the native base's low bits. -/
def scalarStackWrite (env : Environment) (frame : Frame)
    (width : Reference.AArch64.Width) (bits : Word) : Word :=
  Reference.AArch64.narrow bits width - base env frame .stack

theorem scalar_stack_write_refines (env : Environment) (frame : Frame)
    (width : Reference.AArch64.Width) (bits : Word) :
    base env frame .stack + scalarStackWrite env frame width bits =
      Reference.AArch64.narrow bits width := by
  simp only [scalarStackWrite, Word]
  bv_decide

/-- A full pointer spill keeps actual guest bytes and an independently stored
private payload. The tag permits using that payload only while the complete
word is intact. No guest initialization follows from this private metadata. -/
structure Spill where
  payload : Value
  guestBytes : List Byte

def Coherent (env : Environment) (frame : Frame) (spill : Spill) : Prop :=
  spill.guestBytes = valueBytes (materialize env frame spill.payload) 8

def spill (env : Environment) (frame : Frame) (payload : Value) : Spill :=
  ⟨payload, valueBytes (materialize env frame payload) 8⟩

theorem spill_coherent (env : Environment) (frame : Frame) (payload : Value) :
    Coherent env frame (spill env frame payload) := rfl

theorem reload_refines (env : Environment) (frame : Frame) (payload : Value) :
    materialize env frame (spill env frame payload).payload =
      materialize env frame payload := rfl

/-- Byte, narrow and vector observations use guest bytes, not the private
offset word. This includes each byte of a saved outer return address. -/
theorem observed_spill_bytes (env : Environment) (frame : Frame) (origin : Base)
    (offset : Word) :
    (spill env frame (.relative origin offset)).guestBytes =
      valueBytes (base env frame origin + offset) 8 := rfl

/-- Normalization is an inverse for all word values, including wrapping
addresses. A private reload must preserve the origin as well as the payload. -/
theorem normalize_materialize (env : Environment) (frame : Frame) (origin : Base)
    (offset : Word) :
    materialize env frame (.relative origin offset) - base env frame origin = offset := by
  simp only [materialize, Word]
  bv_decide

end KProgFormal.Refinement.Arm64NumericAddress
