import KProgFormal.Reference.AArch64
import KProgFormal.Reference.X86

/-! The C provenance representation is a coordinate system over the external
machines, not an ISA. Input/output tags come from the actual C handler.
Its refinement uses the existing native `Step` on `image` and `observe`,
requiring the complete physical output and ordered effects. No tag-transfer
callback or local instruction interpreter is used.
Physical memory/program coordinates and platform witnesses stay explicit. -/
namespace KProgFormal.Reference.Provenance
open KProgFormal.Reference

namespace AArch64

/-- Actual same-invocation origins from the entry ABI, not guessed addresses. -/
structure Origins where
  stack : Word
  returnAddress : Word

/-- All256 byte tags,31 GPRs, distinct SP and the entire external machine. -/
structure State where
  raw : Reference.AArch64.State
  tags : Reference.AArch64.Gpr → Byte

/-- ARM64_SIM_L_MATERIALIZE: STACK4 and RETURN10 use distinct origins. Other
byte tags already carry their numeric bits. PC/labels are bound separately. -/
def materialize (origins : Origins) (word : Word) (tag : Byte) : Word :=
  if tag = 4 then word + origins.stack
  else if tag = 10 then word + origins.returnAddress else word

/-- Public LNSym register writes preserve its complete frame, including all32
SIMD cells, program, permissions, initialization, exclusive/atomic histories,
MRS inputs and model-error state. GPR31 here is SP, never an invented XZR cell. -/
def image (origins : Origins) (state : State) : Reference.AArch64.State :=
  let machine := (List.finRange 31).foldl (fun machine index =>
    w (.GPR (BitVec.ofNat 5 index.val))
      (materialize origins (Reference.AArch64.gpr state.raw index) (state.tags index)) machine)
    state.raw.machine
  { state.raw with machine := w (.GPR 31) (Reference.AArch64.sp state.raw + origins.stack) machine }

def observe (origins : Origins) (result : Transition State) : Transition Reference.AArch64.State :=
  ⟨image origins result.state, result.events, result.fault⟩

/-- Execute only the external checked step on the actual physical image. -/
def execute (origins : Origins) (before : State) : Transition Reference.AArch64.State :=
  Reference.AArch64.step (image origins before)

end AArch64

namespace X86

structure Origins where
  stack : Word
  arena : Word

structure State where
  raw : Reference.X86.State
  tags : Reference.X86.Register → Byte

/-- X86_SIM_L_READ_REG_WIDTH_SHIFT: RSP is an offset regardless of its byte
tag. A non-RSP STACK4 word is a private-arena pointer; subtract that arena
before adding the native origin. All other tags keep their numeric bits. -/
def materialize (origins : Origins) (reg : Reference.X86.Register) (word : Word) (tag : Byte) : Word :=
  if reg = 4 then word + origins.stack
  else if tag = 4 then word - origins.arena + origins.stack else word

def image (origins : Origins) (state : State) : Reference.X86.State :=
  { state.raw with gpr := fun reg => materialize origins reg (state.raw.gpr reg) (state.tags reg) }

def observe (origins : Origins) (result : Transition State) : Transition Reference.X86.State :=
  ⟨image origins result.state, result.events, result.fault⟩

def execute (origins : Origins) (instruction : Reference.X86.Instruction) (before : State) :
    Transition Reference.X86.State :=
  Reference.X86.step instruction (image origins before)

end X86
end KProgFormal.Reference.Provenance
