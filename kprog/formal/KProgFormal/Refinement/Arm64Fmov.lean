import KProgFormal.Refinement.Arm64Register
import KProgFormal.Generated.GeneratedArm64Fmov
import KProgFormal.Generated.GeneratedArm64FmovDest
import KProgFormal.Generated.GeneratedArm64DispatchSingleton

namespace KProgFormal.Refinement.Arm64Fmov

open Reference
open Reference.AArch64 (Width FmovInstruction)

/-- Operand selection for the four real FMOV directions. Unused integer fields
are ZR, not SP. Generated value and destination selectors are both exercised. -/
def fields : FmovInstruction → GeneratedArm64Fmov.Fmov × Width × Reference.AArch64.Register × Reference.AArch64.Register
  | .toVector .w64 src => (.d_from_x, .w64, 31, src)
  | .toVector .w32 src => (.s_from_w, .w32, 31, src)
  | .fromVector .w64 dst => (.x_from_d, .w64, dst, 31)
  | .fromVector .w32 dst => (.w_from_s, .w32, dst, 31)

def bankHandlerState (bank : Reference.AArch64.Register) (i : FmovInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  let (direction, width, dst, src) := fields i
  let value := GeneratedArm64Fmov.value direction ((Reference.AArch64.readVector s bank).setWidth 64) (Arm64Register.readReg s src)
  if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then
    let low := if direction = .s_from_w then (value.setWidth 32).setWidth 64 else value
    Reference.AArch64.writeVector s bank (low.setWidth 128)
  else Arm64Register.writeReg s dst value width

def bankHandlerStep (bank : Reference.AArch64.Register) (i : FmovInstruction)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ bankHandlerState bank i s with pc := s.pc + 4 }, [], none⟩

theorem bank_step_refines (bank : Reference.AArch64.Register) (i : FmovInstruction)
    (s : Reference.AArch64.State) :
    bankHandlerStep bank i s = Reference.AArch64.step (.fmovBank bank i) s := by
  cases i with
  | toVector width src =>
    cases width <;>
      simp [bankHandlerStep, bankHandlerState, fields, Reference.AArch64.step, Reference.AArch64.fmovBankStep,
        GeneratedArm64Fmov.value, GeneratedArm64Fmov.code, GeneratedArm64FmovDest.vectorDestination,
        Arm64Register.read_refines, Reference.AArch64.narrow, Reference.AArch64.Width.bits]
  | fromVector width dst =>
    cases width <;>
      simp [bankHandlerStep, bankHandlerState, fields, Reference.AArch64.step, Reference.AArch64.fmovBankStep,
        GeneratedArm64Fmov.value, GeneratedArm64Fmov.code, GeneratedArm64FmovDest.vectorDestination,
        Arm64Register.write_refines]

/-- Production SRC2 is a vector index, except NONE retains the original V0
encoding. This is independent of the integer register31/ZR selector. -/
def vectorIndex (src2 : Nat) : Option Reference.AArch64.Register :=
  if src2 = 255 then some 0 else if h : src2 < 32 then some ⟨src2, h⟩ else none

theorem vector_index_refines (index : Reference.AArch64.Register) :
    vectorIndex index.val = some index := by
  simp [vectorIndex, show index.val ≠ 255 by omega, index.isLt]

theorem legacy_vector_index : vectorIndex 255 = some 0 := by decide

def handlerState (i : FmovInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  bankHandlerState 0 i s

def handlerStep (i : FmovInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  bankHandlerStep 0 i s

theorem step_refines (i : FmovInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.fmov i) s := bank_step_refines 0 i s

theorem handler_refines (i : FmovInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.fmov i) s (handlerStep i s) := (step_refines i s).symm

/-- Adapter from the actual direction field to the same native FMOV
instruction. The output width is independent of the vector-bank selector. -/
def nativeMove (direction : GeneratedArm64Fmov.Fmov) (dst src : Reference.AArch64.Register) : FmovInstruction :=
  match direction with
  | .d_from_x => .toVector .w64 src | .s_from_w => .toVector .w32 src
  | .x_from_d => .fromVector .w64 dst | .w_from_s => .fromVector .w32 dst

def operandWidth : GeneratedArm64Fmov.Fmov → Width
  | .d_from_x | .x_from_d => .w64 | .s_from_w | .w_from_s => .w32

/-- Actual numeric FMOV body with independently supplied fields. The generated
value and destination selectors consume the direction code, and only the
S_FROM_W vector write truncates the source. Both vector writes clear high64. -/
def rawStep (bank : Reference.AArch64.Register) (direction : GeneratedArm64Fmov.Fmov)
    (dst src : Reference.AArch64.Register) (width : Width) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let code := GeneratedArm64Fmov.code direction
  let value := GeneratedArm64Fmov.value direction
    ((Reference.AArch64.readVector s bank).setWidth 64) (Arm64Register.readReg s src)
  let result := if GeneratedArm64FmovDest.vectorDestination code then
      let low := if code = GeneratedArm64Fmov.code .s_from_w then (value.setWidth 32).setWidth 64 else value
      Reference.AArch64.writeVector s bank (low.setWidth 128)
    else Arm64Register.writeReg s dst value width
  ⟨{ result with pc := s.pc + 4 }, [], none⟩

theorem raw_step_refines (bank : Reference.AArch64.Register) (direction : GeneratedArm64Fmov.Fmov)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    rawStep bank direction dst src (operandWidth direction) s =
      Reference.AArch64.step (.fmovBank bank (nativeMove direction dst src)) s := by
  cases direction <;>
    simp [rawStep, operandWidth, nativeMove, GeneratedArm64Fmov.value,
      GeneratedArm64Fmov.code, GeneratedArm64FmovDest.vectorDestination,
      Reference.AArch64.step, Reference.AArch64.fmovBankStep,
      Arm64Register.read_refines, Arm64Register.write_refines,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits]

def decodeDirection (aux : Nat) : Option GeneratedArm64Fmov.Fmov :=
  if aux = GeneratedArm64Fmov.code .d_from_x then some .d_from_x
  else if aux = GeneratedArm64Fmov.code .x_from_d then some .x_from_d
  else if aux = GeneratedArm64Fmov.code .s_from_w then some .s_from_w
  else if aux = GeneratedArm64Fmov.code .w_from_s then some .w_from_s
  else none

theorem decode_direction_code (direction : GeneratedArm64Fmov.Fmov) :
    decodeDirection (GeneratedArm64Fmov.code direction) = some direction := by
  cases direction <;> rfl

/-- Numeric singleton gate, direction AUX, vector index (including legacy
NONE=255), and the actual body. Invalid fields reject this slice, not execute a
successful no-op. The typed live integer fields are native GPR/ZR operands. -/
def dispatch (opcode aux src2 : Nat) (dst src : Reference.AArch64.Register) (width : Width)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  if opcode = GeneratedArm64DispatchSingleton.code .fmov then
    (decodeDirection aux).bind (fun direction =>
      (vectorIndex src2).map (fun bank => rawStep bank direction dst src width s))
  else none

theorem dispatch_refines (bank : Reference.AArch64.Register) (direction : GeneratedArm64Fmov.Fmov)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchSingleton.code .fmov) (GeneratedArm64Fmov.code direction)
      bank.val dst src (operandWidth direction) s =
      some (Reference.AArch64.step (.fmovBank bank (nativeMove direction dst src)) s) := by
  simp only [dispatch, ↓reduceIte, decode_direction_code, vector_index_refines]
  change some (rawStep bank direction dst src (operandWidth direction) s) = _
  rw [raw_step_refines]

theorem dispatch_legacy_refines (direction : GeneratedArm64Fmov.Fmov)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchSingleton.code .fmov) (GeneratedArm64Fmov.code direction)
      255 dst src (operandWidth direction) s =
      some (Reference.AArch64.step (.fmovBank 0 (nativeMove direction dst src)) s) := by
  simp only [dispatch, ↓reduceIte, decode_direction_code, legacy_vector_index]
  change some (rawStep 0 direction dst src (operandWidth direction) s) = _
  rw [raw_step_refines]

theorem dispatch_bad_bank (opcode aux src2 : Nat) (dst src : Reference.AArch64.Register)
    (width : Width) (s : Reference.AArch64.State) (outside : 32 ≤ src2) (notLegacy : src2 ≠ 255) :
    dispatch opcode aux src2 dst src width s = none := by
  have invalid : vectorIndex src2 = none := by simp [vectorIndex, notLegacy, show ¬src2 < 32 by omega]
  simp only [dispatch, invalid]
  split <;> simp

theorem dispatch_bad_direction (opcode aux src2 : Nat) (dst src : Reference.AArch64.Register)
    (width : Width) (s : Reference.AArch64.State) (outside : 3 < aux) :
    dispatch opcode aux src2 dst src width s = none := by
  have invalid : decodeDirection aux = none := by
    simp [decodeDirection, GeneratedArm64Fmov.code, show aux ≠ 0 by omega,
      show aux ≠ 1 by omega, show aux ≠ 2 by omega, show aux ≠ 3 by omega]
  simp [dispatch, invalid]

theorem dispatch_other (opcode aux src2 : Nat) (dst src : Reference.AArch64.Register)
    (width : Width) (s : Reference.AArch64.State)
    (other : opcode ≠ GeneratedArm64DispatchSingleton.code .fmov) :
    dispatch opcode aux src2 dst src width s = none := by simp [dispatch, other]

end KProgFormal.Refinement.Arm64Fmov
