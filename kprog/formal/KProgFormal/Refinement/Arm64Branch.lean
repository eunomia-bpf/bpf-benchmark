import KProgFormal.Refinement.Arm64Condition
import KProgFormal.Refinement.Arm64Register
import KProgFormal.Generated.GeneratedArm64Branch
import KProgFormal.Generated.GeneratedArm64BranchEmit
import KProgFormal.Generated.GeneratedArm64DispatchSingleton
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64Branch

open Reference
open Reference.AArch64 (Width Register)

/-- The generator may invert a backward condition and use two gotos. Both
shapes select the same architectural byte address under the label-address map. -/
def choosePc (shape : GeneratedArm64BranchEmit.Shape) (taken : Bool)
    (fallthrough target : Reference.Word) : Reference.Word :=
  BitVec.ofNat 64 (GeneratedArm64BranchEmit.nextPc shape taken fallthrough.toNat target.toNat)

theorem pc_refines (shape : GeneratedArm64BranchEmit.Shape) (taken : Bool)
    (fallthrough target : Reference.Word) :
    choosePc shape taken fallthrough target = if taken then target else fallthrough := by
  cases shape <;> cases taken <;> simp [choosePc, GeneratedArm64BranchEmit.nextPc]

def controlStep (shape : GeneratedArm64BranchEmit.Shape) (taken : Bool)
    (displacement : Reference.Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ s with pc := choosePc shape taken (s.pc + 4) (s.pc + displacement) }, [], none⟩

theorem control_refines (shape : GeneratedArm64BranchEmit.Shape) (taken : Bool)
    (displacement : Reference.Word) (s : Reference.AArch64.State) :
    controlStep shape taken displacement s = Reference.AArch64.branchStep taken displacement s := by
  rw [controlStep, pc_refines]
  rfl

def nopStep (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ s with pc := s.pc + 4 }, [], none⟩

theorem nop_handler_refines (s : Reference.AArch64.State) :
    GeneratedArm64DispatchSingleton.nopHandled .nop = true ∧ Reference.AArch64.Step .nop s (nopStep s) :=
  ⟨by decide, rfl⟩

theorem jump_handler_refines (displacement : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.branch displacement) s ⟨{ s with pc := s.pc + displacement }, [], none⟩ := rfl

def conditionStep (predicate : Arm64Cond) (shape : GeneratedArm64BranchEmit.Shape)
    (displacement : Reference.Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  controlStep shape (generatedArm64Cond (Arm64Condition.flags s.flags) predicate) displacement s

theorem condition_handler_refines (predicate : Arm64Cond) (shape : GeneratedArm64BranchEmit.Shape)
    (displacement : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.branchConditional (Arm64Condition.nativeCode predicate) displacement) s
      (conditionStep predicate shape displacement s) := by
  simp only [Reference.AArch64.Step, conditionStep, control_refines,
    Arm64Condition.condition_refines, Reference.AArch64.step]

theorem nv_handler_refines (shape : GeneratedArm64BranchEmit.Shape) (displacement : Reference.Word)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.branchConditional 15 displacement) s (conditionStep .al shape displacement s) :=
  condition_handler_refines .al shape displacement s

def zeroSource (width : Width) (value : Reference.Word) : Reference.Word :=
  match width with
  | .w32 => (value.setWidth 32).setWidth 64
  | .w64 => value

theorem zero_predicate_refines (width : Width) (nonzero : Bool) (value : Reference.Word) :
    GeneratedArm64Branch.value (if nonzero then .cbnz else .cbz) (zeroSource width value) 0 =
      Reference.AArch64.zeroBranch width nonzero value := by
  cases width <;> cases nonzero <;>
    simp only [GeneratedArm64Branch.value, zeroSource, Reference.AArch64.zeroBranch,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word,
      Bool.false_eq_true, ↓reduceIte] <;> bv_decide

def zeroStep (width : Width) (nonzero : Bool) (src : Register) (shape : GeneratedArm64BranchEmit.Shape)
    (displacement : Reference.Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  controlStep shape (GeneratedArm64Branch.value (if nonzero then .cbnz else .cbz)
    (zeroSource width (Arm64Register.readReg s src)) 0) displacement s

theorem zero_handler_refines (width : Width) (nonzero : Bool) (src : Register)
    (shape : GeneratedArm64BranchEmit.Shape) (displacement : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.branchZero width nonzero src displacement) s
      (zeroStep width nonzero src shape displacement s) := by
  simp only [Reference.AArch64.Step, zeroStep, control_refines, zero_predicate_refines,
    Arm64Register.read_refines, Reference.AArch64.step]

theorem bit_predicate_refines (nonzero : Bool) (value : Reference.Word) (bit : BitVec 6) :
    GeneratedArm64Branch.value (if nonzero then .tbnz else .tbz) value (bit.setWidth 64) =
      Reference.AArch64.bitBranch nonzero value bit := by
  cases nonzero with
  | false =>
    change decide (((value >>> ((bit.setWidth 64 : Reference.Word) &&& 63)) &&& 1) = 0) =
      (((value >>> bit.setWidth 64).setWidth 1) == 0)
    bv_decide
  | true =>
    change decide (((value >>> ((bit.setWidth 64 : Reference.Word) &&& 63)) &&& 1) = 1) =
      (((value >>> bit.setWidth 64).setWidth 1) != 0)
    bv_decide

def bitStep (nonzero : Bool) (src : Register) (bit : BitVec 6) (shape : GeneratedArm64BranchEmit.Shape)
    (displacement : Reference.Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  controlStep shape (GeneratedArm64Branch.value (if nonzero then .tbnz else .tbz)
    (Arm64Register.readReg s src) (bit.setWidth 64)) displacement s

theorem bit_handler_refines (nonzero : Bool) (src : Register) (bit : BitVec 6)
    (shape : GeneratedArm64BranchEmit.Shape) (displacement : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.branchBit nonzero src bit displacement) s
      (bitStep nonzero src bit shape displacement s) := by
  simp only [Reference.AArch64.Step, bitStep, control_refines, bit_predicate_refines,
    Arm64Register.read_refines, Reference.AArch64.step]

/-- Internal calls link to the actual native successor and dispatch to the
native target. This is the bit-state slice of A64_LINK/A64_CALL after the
existing code-address and finite-target checks, not a platform helper call. -/
def callStep (target successor : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  ⟨{ Arm64Register.writeReg s 30 successor .w64 with pc := target }, [], none⟩

theorem call_step_refines (displacement : Reference.Word) (s : Reference.AArch64.State) :
    callStep (s.pc + displacement) (s.pc + 4) s =
      Reference.AArch64.step (.branchLink displacement) s := by
  simp only [callStep, Arm64Register.write_refines, Reference.AArch64.step,
    Reference.AArch64.narrow, Reference.AArch64.Width.bits, BitVec.setWidth_eq]

theorem call_handler_refines (displacement : Reference.Word) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.branchLink displacement) s
      (callStep (s.pc + displacement) (s.pc + 4) s) :=
  (call_step_refines displacement s).symm

/-- Target selection reads the incoming register before the link write.
BR/RET keep X30 unchanged; BLR X30 branches to the old X30 value. -/
def indirectStep (link : Bool) (src : Register) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let target := Arm64Register.readReg s src
  if link then callStep target (s.pc + 4) s else ⟨{ s with pc := target }, [], none⟩

theorem indirect_step_refines (link : Bool) (src : Register) (s : Reference.AArch64.State) :
    indirectStep link src s = Reference.AArch64.step (.branchRegister link src) s := by
  cases link <;> simp only [indirectStep, callStep, Arm64Register.read_refines,
    Arm64Register.write_refines, Reference.AArch64.step, Reference.AArch64.narrow,
    Reference.AArch64.Width.bits, BitVec.setWidth_eq, Bool.false_eq_true, ↓reduceIte]

theorem indirect_handler_refines (link : Bool) (src : Register) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.branchRegister link src) s (indirectStep link src s) :=
  (indirect_step_refines link src s).symm

/-- Independent page arithmetic: remove the low twelve bits by subtraction,
then add the signed byte displacement (already shifted for ADRP). -/
def pcAddress (page : Bool) (pc displacement : Reference.Word) : Reference.Word :=
  (if page then pc - (pc &&& 0xfff) else pc) + displacement

theorem pc_address_refines (page : Bool) (pc displacement : Reference.Word) :
    pcAddress page pc displacement =
      (if page then pc &&& 0xfffffffffffff000 else pc) + displacement := by
  cases page <;> simp only [pcAddress, Bool.false_eq_true, ↓reduceIte, Reference.Word] <;> bv_decide

/-- ADR and linked ADRP materialize this native address in a full-width GPR.
Relocation identity and provenance tags remain the existing linker/entry
relation; the core preserves every other state component and emits no read. -/
def pcAddressStep (page : Bool) (dst : Register) (displacement : Reference.Word)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ Arm64Register.writeReg s dst (pcAddress page s.pc displacement) .w64 with pc := s.pc + 4 }, [], none⟩

theorem pc_address_step_refines (page : Bool) (dst : Register) (displacement : Reference.Word)
    (s : Reference.AArch64.State) :
    pcAddressStep page dst displacement s = Reference.AArch64.step (.pcAddress page dst displacement) s := by
  simp only [pcAddressStep, pc_address_refines, Arm64Register.write_refines,
    Reference.AArch64.step, Reference.AArch64.narrow, Reference.AArch64.Width.bits, BitVec.setWidth_eq]

theorem pc_address_handler_refines (page : Bool) (dst : Register) (displacement : Reference.Word)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.pcAddress page dst displacement) s (pcAddressStep page dst displacement s) :=
  (pc_address_step_refines page dst displacement s).symm

end KProgFormal.Refinement.Arm64Branch
