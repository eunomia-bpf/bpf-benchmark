import KProgFormal.Reference.AArch64
import KProgFormal.Arm64RegDispatch
import KProgFormal.Arm64WriteArmShape
import KProgFormal.Generated.GeneratedArm64Width

namespace KProgFormal.Refinement.Arm64Register

open Reference
open Reference.AArch64 (Width Register Gpr)

def handlerWidth : Width → GeneratedArm64Width.Width
  | .w32 => .w32 | .w64 => .w64

def registerCode (r : Register) : BitVec 8 := BitVec.ofNat 8 r.val

theorem cell_refines (r : Register) :
    GeneratedArm64RegDispatch.cellOf (registerCode r) =
      (if r.val < 31 then some r.val else none) := by
  simp only [GeneratedArm64RegDispatch.cellOf, GeneratedArm64RegDispatch.gprCount,
    registerCode, BitVec.toNat_ofNat]
  rw [Nat.mod_eq_of_lt (by omega)]

/-- The cell array contains X0..X30; every arithmetic source field31 reads ZR. -/
def readReg (s : Reference.AArch64.State) (r : Register) : Reference.Word :=
  match GeneratedArm64RegDispatch.cellOf (registerCode r) with
  | some index => s.gpr ⟨index % 31, Nat.mod_lt _ (by decide)⟩
  | none => 0

theorem read_refines (s : Reference.AArch64.State) (r : Register) :
    readReg s r = Reference.AArch64.readReg s r := by
  by_cases h : r.val < 31 <;>
    simp [readReg, cell_refines, Reference.AArch64.readReg, h, Nat.mod_eq_of_lt]

/-- Actual write-arm selection follows the generated width mask and the
32-bit store through the GPR cell's integer member. -/
def writeValue (width : Width) (value : Reference.Word) : Reference.Word :=
  let value := GeneratedArm64Width.narrow value (handlerWidth width)
  match GeneratedArm64WriteArm.armOf (decide (width = .w32)) with
  | .narrow => (value.setWidth 32).setWidth 64
  | .full => value

theorem write_value_refines (width : Width) (value : Reference.Word) :
    writeValue width value = Reference.AArch64.narrow value width := by
  cases width <;>
    simp only [writeValue, handlerWidth, GeneratedArm64Width.narrow,
      GeneratedArm64Width.mask, GeneratedArm64WriteArm.armOf,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.Word, beq_self_eq_true, Bool.false_eq_true, reduceCtorEq, ↓reduceIte] <;> bv_decide

/-- Generated destination presence/cell dispatch discards ZR, for all32 native
register fields, with no assumption about the previous value or tag. -/
theorem write_selection : ∀ (dst : Register) (i : Gpr),
    (GeneratedArm64RegPresence.writable (registerCode dst) &&
      (GeneratedArm64RegDispatch.cellOf (registerCode dst) == some i.val)) =
      (i.val == dst.val) := by native_decide

def writeReg (s : Reference.AArch64.State) (dst : Register) (value : Reference.Word)
    (width : Width) : Reference.AArch64.State :=
  { s with gpr := fun i =>
      if GeneratedArm64RegPresence.writable (registerCode dst) &&
          (GeneratedArm64RegDispatch.cellOf (registerCode dst) == some i.val)
      then writeValue width value else s.gpr i }

theorem write_refines (s : Reference.AArch64.State) (dst : Register)
    (value : Reference.Word) (width : Width) :
    writeReg s dst value width =
      Reference.AArch64.writeReg s dst (Reference.AArch64.narrow value width) := by
  simp only [writeReg, Reference.AArch64.writeReg, write_selection,
    write_value_refines, beq_iff_eq]

/-- Native MRS encoding, retaining every destination bit. -/
def threadPointerBytes (source : Reference.AArch64.ThreadPointerRegister) (dst : Register) : Array Byte :=
  let word := BitVec.ofNat 32 (0xd5200000 + 32 * source.encoding + dst.val)
  #[word.setWidth 8, (word >>> 8).setWidth 8, (word >>> 16).setWidth 8, (word >>> 24).setWidth 8]

theorem thread_pointer_decode (source : Reference.AArch64.ThreadPointerRegister) : ∀ (dst : Register),
    Reference.AArch64.decode (threadPointerBytes source dst) = .ok (.readThreadPointer source dst) := by
  have all : (List.finRange 32).all (fun dst =>
      match Reference.AArch64.decode (threadPointerBytes source dst) with
      | .ok instruction => decide (instruction = .readThreadPointer source dst)
      | .error _ => false) = true := by
    cases source <;> native_decide
  intro dst
  have member : dst ∈ List.finRange 32 := by
    change dst ∈ List.ofFn (fun i : Fin 32 => i)
    exact List.mem_ofFn.mpr ⟨dst, rfl⟩
  have hit := List.all_eq_true.mp all dst member
  cases decoded : Reference.AArch64.decode (threadPointerBytes source dst) with
  | error message => simp [decoded] at hit
  | ok instruction =>
      have same : instruction = .readThreadPointer source dst := of_decide_eq_true (by simpa [decoded] using hit)
      rw [same]

/-- A successful system-register read has exactly the complete-state effect
of a64 MOV-immediate with the same full64 word. Profile/CPU value binding is
an explicit input for native-link kind4. -/
theorem thread_pointer_read_refines (source : Reference.AArch64.ThreadPointerRegister)
    (dst : Register) (value : Word) (s : Reference.AArch64.State)
    (permitted : s.threadPointer source = some value) :
    Reference.AArch64.step (.readThreadPointer source dst) s =
      Reference.AArch64.step (.moveImmediate .w64 dst value) s := by
  simp only [Reference.AArch64.step, Reference.AArch64.readThreadPointerStep, permitted]
  have narrow : Reference.AArch64.narrow value .w64 = value := by
    simp [Reference.AArch64.narrow, Reference.AArch64.Width.bits]
  rw [narrow]

/-- Access denial retains the full incoming state and identifies the system
register at the architectural fault boundary, including XZR destinations. -/
theorem thread_pointer_denied (source : Reference.AArch64.ThreadPointerRegister)
    (dst : Register) (s : Reference.AArch64.State) (denied : s.threadPointer source = none) :
    Reference.AArch64.step (.readThreadPointer source dst) s =
      ⟨s, [.fault (.systemRegister source.encoding)], some (.systemRegister source.encoding)⟩ := by
  simp only [Reference.AArch64.step, Reference.AArch64.readThreadPointerStep, denied]

/-- XZR discards a successful read while retaining SP and every other field. -/
theorem thread_pointer_xzr (source : Reference.AArch64.ThreadPointerRegister)
    (value : Word) (s : Reference.AArch64.State) (permitted : s.threadPointer source = some value) :
    Reference.AArch64.step (.readThreadPointer source 31) s = ⟨{ s with pc := s.pc + 4 }, [], none⟩ := by
  have registers : (fun i : Gpr => if i.val = (31 : Register).val then value else s.gpr i) = s.gpr := by
    funext i
    change (if i.val = 31 then value else s.gpr i) = s.gpr i
    rw [if_neg (by omega)]
  simp only [Reference.AArch64.step, Reference.AArch64.readThreadPointerStep, permitted,
    Reference.AArch64.writeReg, registers]

/-- The two kernel TP choices have the same complete canonical effect when
both resolved reads carry the same CPU-local word. -/
theorem thread_pointer_el_transport (dst : Register) (value : Word) (s : Reference.AArch64.State)
    (el1 : s.threadPointer .el1 = some value) (el2 : s.threadPointer .el2 = some value) :
    Reference.AArch64.step (.readThreadPointer .el1 dst) s =
      Reference.AArch64.step (.readThreadPointer .el2 dst) s := by
  simp only [Reference.AArch64.step, Reference.AArch64.readThreadPointerStep, el1, el2]

end KProgFormal.Refinement.Arm64Register
