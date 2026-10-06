import KProgFormal.GeneratedX86SetccMem
import KProgFormal.GeneratedX86RegLaneAux
import KProgFormal.X86ControlFlow
import KProgFormal.X86MemOffset
import KProgFormal.X86SetccHandler
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Store (Arm)

/-- The effect of the x86-64 `SETCC_MEM` handler. The handler writes only
memory, so the effect has the same five fields as the store's: which arm was
written, at which width, with which value, at which effective address, and the
byte function of the buffer that arm updated. -/
abbrev X86SetccMemEffect := X86StoreEffect

/-- Independent statement of the condition-code field the handler reads: the
AUX source-shift byte at bits 24..31. The register form `X86_OP_SETCC` reads the
payload byte at bits 0..7 of the same word, so the two opcodes name different
conditions with one encoding. -/
def x86SetccMemConditionCodeSpec (aux : BitVec 32) : BitVec 8 :=
  (aux >>> 24).setWidth 8

/-- The generated source-shift-byte decode equals the independent byte extract.
-/
theorem x86_setcc_mem_condition_code_refines (aux : BitVec 32) :
    GeneratedX86SetccMem.conditionCode aux =
      x86SetccMemConditionCodeSpec aux := by
  rfl

/-- Independent statement of the null-base test: the destination register
number compared against `X86_REG_NONE`. -/
def x86SetccMemIsNoneSpec (dst : BitVec 8) : Bool := dst == 0xff

/-- Independent statement of the stack-arm test: the same destination register
number compared against `X86_RSP`. -/
def x86SetccMemIsRspSpec (dst : BitVec 8) : Bool := dst == 4

theorem x86_setcc_mem_is_none_refines (dst : BitVec 8) :
    GeneratedX86SetccMem.isNoneReg dst = x86SetccMemIsNoneSpec dst := by
  rfl

theorem x86_setcc_mem_is_rsp_refines (dst : BitVec 8) :
    GeneratedX86SetccMem.isRspReg dst = x86SetccMemIsRspSpec dst := by
  rfl

/-- The two selectors are tests of the same register *number*, and the null-base
number is not the stack-pointer number: a null base can therefore never take the
stack arm, whatever else the handler evaluates. The C body's base-pointer test
precedes its arm test, so the null pointer is what the memory arm then stores
through. -/
theorem x86_setcc_mem_null_base_is_not_stack (dst : BitVec 8)
    (h : x86SetccMemIsNoneSpec dst = true) :
    x86SetccMemIsRspSpec dst = false := by
  rw [x86SetccMemIsNoneSpec, beq_iff_eq] at h
  rw [x86SetccMemIsRspSpec, h]
  decide

/-- Independent statement of the generated base table: one test of the
destination register number. -/
def x86SetccMemBaseSpec (isNone : Bool) : GeneratedX86SetccMem.Base :=
  if isNone then .nullBase else .registerBase

theorem x86_setcc_mem_base_refines (isNone : Bool) :
    GeneratedX86SetccMem.base isNone = x86SetccMemBaseSpec isNone := by
  cases isNone <;> rfl

/-- Independent statement of the arm table: write the stack frame for the stack
pointer, ordinary process memory for every other destination. -/
def x86SetccMemArmSpec (isRsp : Bool) : Arm :=
  if isRsp then .stackWrite else .memoryStore

theorem x86_setcc_mem_arm_refines (isRsp : Bool) :
    GeneratedX86SetccMem.arm isRsp = x86SetccMemArmSpec isRsp := by
  cases isRsp <;> rfl

/-- The stack arm is exactly the stack-pointer destination: one selector, with
no opcode, width, or tag gate. -/
theorem x86_setcc_mem_arm_stack_iff (isRsp : Bool) :
    GeneratedX86SetccMem.arm isRsp = Arm.stackWrite ↔ isRsp = true := by
  cases isRsp <;> simp [GeneratedX86SetccMem.arm]

/-- The base pointer the handler forms: process null when the destination
register number is `X86_REG_NONE`, the destination register's own value
otherwise. The value is always read first and then discarded, so the arm store's
address is the addressing offset alone in the null case. -/
def generatedX86SetccMemBasePtr (isNone : Bool) (dstValue : BitVec 64) :
    BitVec 64 :=
  match GeneratedX86SetccMem.base isNone with
  | .nullBase => 0
  | .registerBase => dstValue

/-- Independent statement of the base pointer: the same two-way choice, written
as the predicate test the C performs. -/
def x86SetccMemBasePtrSpec (isNone : Bool) (dstValue : BitVec 64) :
    BitVec 64 :=
  if isNone then 0 else dstValue

theorem x86_setcc_mem_base_ptr_refines (isNone : Bool) (dstValue : BitVec 64) :
    generatedX86SetccMemBasePtr isNone dstValue =
      x86SetccMemBasePtrSpec isNone dstValue := by
  cases isNone <;> rfl

/-- A null base discards the destination register's value entirely: the effective
address is the addressing offset computed from address zero. This is an
asymmetry with the stack arm, whose base is the stack pointer's own value. -/
theorem x86_setcc_mem_null_base_ignores_dst (dstValue : BitVec 64) :
    generatedX86SetccMemBasePtr true dstValue = 0 := by
  rfl

/-- The access width is the opcode's constant 8-bit code. It takes both inputs
the handler has available — the AUX word and the FLAGS width code — so the
statement is that neither can move it: a nonzero AUX memory-width byte and a
nonzero FLAGS code that would otherwise force 64 bits both leave the width at the
8-bit code. -/
def x86SetccMemWidthSpec (_aux : BitVec 32) (_flags : BitVec 8) : X86Width := .w8

def generatedX86SetccMemWidth (_aux : BitVec 32) (_flags : BitVec 8) : X86Width :=
  GeneratedX86SetccMem.width

theorem x86_setcc_mem_width_refines (aux : BitVec 32) (flags : BitVec 8) :
    generatedX86SetccMemWidth aux flags = x86SetccMemWidthSpec aux flags := by
  rfl

/-- The handler's constant width is the 8-bit code whatever the handler's other
inputs hold. -/
theorem x86_setcc_mem_width_constant (aux : BitVec 32) (flags : BitVec 8) :
    x86SetccMemWidthSpec aux flags = .w8 := by
  rfl

/-- The displacement the memory form uses is the whole instruction artifact,
sign-extended nowhere and sliced nowhere — unlike the immediate store, which
consumes only its high half. -/
def x86SetccMemDispSpec (imm : BitVec 64) : BitVec 64 := imm

/-- The raw condition evaluator over the decoded source-shift byte: the
generated register-form expression table, which is the same `KPROG_X86_EVAL_CC`
the memory form calls. -/
def generatedX86SetccMemRaw (flags : X86Flags) (ccByte : BitVec 8) : Bool :=
  GeneratedX86Setcc.evalRaw flags.cf flags.zf flags.sf flags.of ccByte

/-- The same evaluator over the packed AUX word, through the generated
source-shift decode. -/
def generatedX86SetccMemRawAux (flags : X86Flags) (aux : BitVec 32) : Bool :=
  GeneratedX86SetccMem.evalRaw flags.cf flags.zf flags.sf flags.of aux

/-- The AUX form is the byte form composed with the generated decode: the only
difference between the two opcodes' condition reads is which byte of the same
word is taken. -/
theorem x86_setcc_mem_raw_aux_composes (flags : X86Flags) (aux : BitVec 32) :
    generatedX86SetccMemRawAux flags aux =
      generatedX86SetccMemRaw flags
        (GeneratedX86SetccMem.conditionCode aux) := by
  rfl

/-- The condition the handler writes, stated over the decoded condition byte and
the architectural condition table rather than the generated one. An unsupported
raw code is false, the C default. -/
def x86SetccMemConditionSpec (ccByte : BitVec 8) (flags : X86Flags) : Bool :=
  x86SetccCondition ccByte flags

/-- The value the handler writes: the condition's boolean, widened to a 64-bit
register value, exactly as the register form widens it. -/
def x86SetccMemValueSpec (ccByte : BitVec 8) (flags : X86Flags) : BitVec 64 :=
  x86BoolValue (x86SetccMemConditionSpec ccByte flags)

/-- An unsupported raw condition code evaluates to false through the memory
form's decode, exactly as the C `KPROG_X86_EVAL_CC` default arm does. -/
theorem x86_setcc_mem_raw_unsupported (ccByte : BitVec 8) (flags : X86Flags)
    (h : GeneratedX86Setcc.condOf ccByte = none) :
    generatedX86SetccMemRaw flags ccByte = false :=
  x86_setcc_raw_unsupported ccByte flags h

/-- Every condition the raw table accepts denotes exactly the architectural
condition of the same name, through the memory form's evaluator. -/
theorem x86_setcc_mem_raw_cond_sound (ccByte : BitVec 8) (flags : X86Flags)
    (cond : X86SetccCond) (h : GeneratedX86Setcc.condOf ccByte = some cond) :
    generatedX86SetccMemRaw flags ccByte = x86CondSpec flags cond :=
  x86_setcc_raw_cond_sound ccByte flags cond h

/-- The generated condition evaluator refines the architectural condition
statement over the decoded byte, for every accepted and every unsupported code:
the `KPROG_X86_SETCC_MEM_CONDITION` byte flows into the same expression table
`_SETCC` uses. -/
theorem x86_setcc_mem_value_refines (ccByte : BitVec 8) (flags : X86Flags) :
    x86BoolValue (generatedX86SetccMemRaw flags ccByte) =
      x86SetccMemValueSpec ccByte flags := by
  unfold x86SetccMemValueSpec x86SetccMemConditionSpec
  cases h : GeneratedX86Setcc.condOf ccByte with
  | some cond =>
      rw [x86_setcc_mem_raw_cond_sound ccByte flags cond h]
      simp only [x86SetccCondition, h]
  | none =>
      rw [x86_setcc_mem_raw_unsupported ccByte flags h]
      simp only [x86SetccCondition, h, x86BoolValue]

/-- Composition used by the x86-64 `SETCC_MEM` handler after the AUX word, the
destination register number, the destination register's value, the instruction
artifact, and the addressing mode have been decoded. The generated selectors
choose the condition byte, the base pointer, and the arm; the displacement then
flows through the generated effective-address contract at the handler's constant
8-bit width, and the arm selects which byte function the one-byte update
touches.

Three asymmetries with the register form are worth naming. The condition byte is
the AUX *source-shift* byte, not the payload byte; the width is the opcode's
constant, so neither FLAGS nor the AUX memory-width byte can widen it; and a
null destination base is admitted, which the register form has no analogue of.
-/
def generatedX86SetccMemStep (ccByte : BitVec 8) (isNone isRsp : Bool)
    (byte stackByte : Nat -> X86MemByte) (flags : X86Flags) (aux : BitVec 32)
    (flagsCode : BitVec 8) (disp dstValue : BitVec 64) (hasIndex : Bool)
    (scale index : BitVec 64) : X86SetccMemEffect :=
  let width := generatedX86SetccMemWidth aux flagsCode
  let value := x86BoolValue (generatedX86SetccMemRaw flags ccByte)
  let basePtr := generatedX86SetccMemBasePtr isNone dstValue
  let addr := basePtr + GeneratedX86MemOffset.value hasIndex scale disp index
  if GeneratedX86SetccMem.arm isRsp = Arm.stackWrite then
    { arm := .stackWrite, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdate stackByte width value }
  else
    { arm := .memoryStore, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdate byte width value }

/-- Independent statement of the same handler: the condition byte is the
architectural condition evaluator, the width is the constant 8-bit statement, the
base pointer is the independent two-way choice, the effective address is the
independent offset table, the value is the architecturally stated condition
value, the arm is the independent one-test nesting, and the byte update is the
independent little-endian statement. -/
def x86SetccMemStepSpec (ccByte : BitVec 8) (isNone isRsp : Bool)
    (byte stackByte : Nat -> X86MemByte) (flags : X86Flags) (aux : BitVec 32)
    (flagsCode : BitVec 8) (disp dstValue : BitVec 64) (hasIndex : Bool)
    (scale index : BitVec 64) : X86SetccMemEffect :=
  let width := x86SetccMemWidthSpec aux flagsCode
  let value := x86SetccMemValueSpec ccByte flags
  let basePtr := x86SetccMemBasePtrSpec isNone dstValue
  let addr := basePtr + GeneratedX86MemOffset.valueSpec hasIndex scale
    (x86SetccMemDispSpec disp) index
  if x86SetccMemArmSpec isRsp = Arm.stackWrite then
    { arm := .stackWrite, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdateSpec stackByte width value }
  else
    { arm := .memoryStore, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdateSpec byte width value }

/-- The generated selectors, width, base pointer, value, effective address, and
arm agree with the independent statements for arbitrary destination identity,
register values, memory and stack bytes, artifact fields, and addressing mode:
every non-byte field of the effect is identical on the two sides. -/
theorem x86_setcc_mem_step_fields_refines (ccByte : BitVec 8)
    (isNone isRsp : Bool) (byte stackByte : Nat -> X86MemByte)
    (flags : X86Flags) (aux : BitVec 32) (flagsCode : BitVec 8)
    (disp dstValue : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).arm =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).arm ∧
      (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).width =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).width ∧
      (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).value =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).value ∧
      (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).addr =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).addr := by
  cases isRsp <;> cases isNone <;>
    simp only [generatedX86SetccMemStep, x86SetccMemStepSpec,
      x86_setcc_mem_width_refines, x86SetccMemWidthSpec,
      x86_setcc_mem_value_refines, x86SetccMemValueSpec,
      x86_setcc_mem_base_ptr_refines, x86SetccMemBasePtrSpec,
      x86_setcc_mem_arm_refines, x86SetccMemArmSpec,
      x86SetccMemDispSpec, x86_mem_offset_refines,
      GeneratedX86SetccMem.arm, reduceCtorEq, ↓reduceIte, true_and]

/-- The observed bytes refine the independent little-endian statement pointwise,
for every arm. -/
theorem x86_setcc_mem_step_bytes_refines (ccByte : BitVec 8)
    (isNone isRsp : Bool) (byte stackByte : Nat -> X86MemByte)
    (flags : X86Flags) (aux : BitVec 32) (flagsCode : BitVec 8)
    (disp dstValue : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64)
    (i : Nat) :
    (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).bytes i =
      (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).bytes i := by
  cases isRsp <;> cases isNone <;>
    simp only [generatedX86SetccMemStep, x86SetccMemStepSpec,
      x86_setcc_mem_width_refines, x86SetccMemWidthSpec,
      x86_setcc_mem_value_refines, x86SetccMemValueSpec,
      x86_setcc_mem_base_ptr_refines, x86SetccMemBasePtrSpec,
      x86_setcc_mem_arm_refines, x86SetccMemArmSpec,
      x86SetccMemDispSpec, x86_mem_offset_refines,
      GeneratedX86SetccMem.arm, reduceCtorEq, ↓reduceIte, true_and]
  all_goals exact x86_store_byte_update_refines _ .w8 _ i

/-- The `SETCC_MEM` handler composition refines the independent
decode/base/width/value/offset/arm/store statement for arbitrary destination
identity, register values, memory and stack bytes, artifact fields, and
addressing mode. -/
theorem x86_setcc_mem_step_refines (ccByte : BitVec 8)
    (isNone isRsp : Bool) (byte stackByte : Nat -> X86MemByte)
    (flags : X86Flags) (aux : BitVec 32) (flagsCode : BitVec 8)
    (disp dstValue : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).arm =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).arm ∧
      (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).width =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).width ∧
      (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).value =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).value ∧
      (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
        flagsCode disp dstValue hasIndex scale index).addr =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).addr ∧
      ∀ i, (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags
          aux flagsCode disp dstValue hasIndex scale index).bytes i =
        (x86SetccMemStepSpec ccByte isNone isRsp byte stackByte flags aux
          flagsCode disp dstValue hasIndex scale index).bytes i := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩
  · exact (x86_setcc_mem_step_fields_refines ccByte isNone isRsp byte stackByte
      flags aux flagsCode disp dstValue hasIndex scale index).1
  · exact (x86_setcc_mem_step_fields_refines ccByte isNone isRsp byte stackByte
      flags aux flagsCode disp dstValue hasIndex scale index).2.1
  · exact (x86_setcc_mem_step_fields_refines ccByte isNone isRsp byte stackByte
      flags aux flagsCode disp dstValue hasIndex scale index).2.2.1
  · exact (x86_setcc_mem_step_fields_refines ccByte isNone isRsp byte stackByte
      flags aux flagsCode disp dstValue hasIndex scale index).2.2.2
  · intro i
    exact x86_setcc_mem_step_bytes_refines ccByte isNone isRsp byte stackByte
      flags aux flagsCode disp dstValue hasIndex scale index i

/-- The step over the packed AUX word and the destination register number — the
shape the `X86_OP_SETCC_MEM` dispatch actually has. -/
def generatedX86SetccMemStepAux (aux : BitVec 32) (dst : BitVec 8)
    (byte stackByte : Nat -> X86MemByte) (flags : X86Flags) (flagsCode : BitVec 8)
    (disp dstValue : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64) :
    X86SetccMemEffect :=
  generatedX86SetccMemStep (GeneratedX86SetccMem.conditionCode aux)
    (GeneratedX86SetccMem.isNoneReg dst) (GeneratedX86SetccMem.isRspReg dst)
    byte stackByte flags aux flagsCode disp dstValue hasIndex scale index

/-- The packed-AUX form of the handler contract: the generated decode of the
condition byte and of the two register-number tests is the only difference from
the independent statement, and each decode is bridged by its own refinement. -/
theorem x86_setcc_mem_step_aux_refines (aux : BitVec 32) (dst : BitVec 8)
    (byte stackByte : Nat -> X86MemByte) (flags : X86Flags) (flagsCode : BitVec 8)
    (disp dstValue : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64) :
    generatedX86SetccMemStepAux aux dst byte stackByte flags flagsCode disp
        dstValue hasIndex scale index =
      x86SetccMemStepSpec (x86SetccMemConditionCodeSpec aux)
        (x86SetccMemIsNoneSpec dst) (x86SetccMemIsRspSpec dst) byte stackByte
        flags aux flagsCode disp dstValue hasIndex scale index := by
  unfold generatedX86SetccMemStepAux generatedX86SetccMemStep
    x86SetccMemStepSpec
  rw [x86_setcc_mem_condition_code_refines, x86_setcc_mem_is_none_refines,
    x86_setcc_mem_is_rsp_refines]
  simp only [x86SetccMemDispSpec, x86_mem_offset_refines]
  cases h : x86SetccMemIsRspSpec dst <;>
    simp only [h, x86_setcc_mem_arm_refines, x86SetccMemArmSpec,
      x86_setcc_mem_base_ptr_refines, x86SetccMemBasePtrSpec,
      reduceCtorEq, ↓reduceIte, X86StoreEffect.mk.injEq]
  all_goals (refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;>
    (first | (funext i; exact x86_store_byte_update_refines _ .w8 _ i)
           | rfl | trivial))

/-- Both arms write at the same constant width, so no memory form can write a
different number of bytes than its own value was widened at. -/
theorem x86_setcc_mem_both_arms_use_one_width (ccByte : BitVec 8)
    (isNone isRsp : Bool) (byte stackByte : Nat -> X86MemByte)
    (flags : X86Flags) (aux : BitVec 32) (flagsCode : BitVec 8)
    (disp dstValue : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86SetccMemStep ccByte isNone isRsp byte stackByte flags aux
      flagsCode disp dstValue hasIndex scale index).width = .w8 := by
  cases isRsp <;> rfl

/-- Every byte at or beyond the one-byte access width survives, so the memory
form never touches a byte the register form's `_SETCC` would not have touched
either: at 8 bits the update is confined to the addressed byte. -/
theorem x86_setcc_mem_step_writes_one_byte (ccByte : BitVec 8) (isNone : Bool)
    (byte stackByte : Nat -> X86MemByte) (flags : X86Flags) (aux : BitVec 32)
    (flagsCode : BitVec 8) (disp dstValue : BitVec 64) (hasIndex : Bool)
    (scale index : BitVec 64) (i : Nat) (h : 1 ≤ i) :
    (x86SetccMemStepSpec ccByte isNone false byte stackByte flags aux flagsCode
        disp dstValue hasIndex scale index).bytes i = byte i := by
  simp only [x86SetccMemStepSpec, x86SetccMemArmSpec, reduceCtorEq, ↓reduceIte]
  exact x86_store_bytes_above_width_unchanged byte .w8 _ i
    (by simpa [x86WidthBitsSpec] using h)

/-- One AUX word names two different conditions for the two opcodes: the
source-shift byte of `0x05000004` is `ne`, while the payload byte the register
form reads is `e`, and the destination-shift byte is zero for both. -/
theorem x86_setcc_mem_condition_source_differs :
    GeneratedX86SetccMem.conditionCode 0x05000004 = 5 ∧
      GeneratedX86RegLaneAux.payload 0x05000004 = 4 ∧
      GeneratedX86RegLaneAux.dstShift 0x05000004 = 0 := by
  decide

/-- The memory form's displacement is the whole artifact, while the immediate
store's is the artifact's high half: the same field yields different addresses. -/
theorem x86_setcc_mem_disp_differs_from_imm_store :
    x86SetccMemDispSpec 0xdeadbeef00000008 = 0xdeadbeef00000008 ∧
      x86StoreDispSpec true 0xdeadbeef00000008 = 0xffffffffdeadbeef := by
  decide

/-- The constant width survives both inputs the handler could have consulted: a
nonzero AUX memory-width byte (`0x40` in bits 16..23) and a nonzero FLAGS code
that would otherwise force 64 bits both leave the width at the 8-bit code. -/
theorem x86_setcc_mem_width_ignores_inputs :
    x86SetccMemWidthSpec 0x00400000 0x08 = .w8 ∧
      x86SetccMemWidthSpec 0x00000000 0x00 = .w8 := by
  decide

/-- A null-base destination takes the ordinary memory arm: the base test and the
arm test are tests of the same register number, and `X86_REG_NONE` is not
`X86_RSP`, so the null pointer is what the little-endian store writes through. -/
theorem x86_setcc_mem_null_base_takes_memory_arm :
    GeneratedX86SetccMem.isNoneReg 0xff = true ∧
      GeneratedX86SetccMem.arm (GeneratedX86SetccMem.isRspReg 0xff) =
        Arm.memoryStore := by
  decide

/-- Canonical example: an `e` condition on a set zero flag writes one into the
addressed byte, little-endian, leaving the second byte alone, and the effective
address is the base pointer plus the whole-artifact displacement sign-extended
by the arithmetic. -/
theorem x86_setcc_mem_example :
    let old : Nat -> X86MemByte := fun i => 0xa5 + (i : X86MemByte)
    (generatedX86SetccMemStep 4 false false
        old (fun _ => 0x5a) ⟨false, true, false, false⟩ 0x04000000 0x00
        0xfffffffffffffff8 0x2000 false 0 0).value = 1 ∧
      (generatedX86SetccMemStep 4 false false
        old (fun _ => 0x5a) ⟨false, true, false, false⟩ 0x04000000 0x00
        0xfffffffffffffff8 0x2000 false 0 0).bytes 0 = 0x01 ∧
      (generatedX86SetccMemStep 4 false false
        old (fun _ => 0x5a) ⟨false, true, false, false⟩ 0x04000000 0x00
        0xfffffffffffffff8 0x2000 false 0 0).bytes 1 = old 1 ∧
      (generatedX86SetccMemStep 4 false false
        old (fun _ => 0x5a) ⟨false, true, false, false⟩ 0x04000000 0x00
        0xfffffffffffffff8 0x2000 false 0 0).addr =
        0x2000 + 0xfffffffffffffff8 := by
  decide

/-- Canonical example: a stack-pointer destination writes the stack frame
instead of process memory, at the same one-byte width and with the same
condition value. -/
theorem x86_setcc_mem_stack_arm_example :
    let old : Nat -> X86MemByte := fun i => 0xa5 + (i : X86MemByte)
    (generatedX86SetccMemStep 5 false true
        (fun _ => 0x11) old ⟨false, true, false, false⟩ 0x05000000 0x00
        0x08 0x4000 false 0 0).arm = Arm.stackWrite ∧
      (generatedX86SetccMemStep 5 false true
        (fun _ => 0x11) old ⟨false, true, false, false⟩ 0x05000000 0x00
        0x08 0x4000 false 0 0).bytes 0 = 0x00 ∧
      (generatedX86SetccMemStep 5 false true
        (fun _ => 0x11) old ⟨false, true, false, false⟩ 0x05000000 0x00
        0x08 0x4000 false 0 0).bytes 1 = old 1 := by
  decide

/-- Canonical example: an unsupported parity code writes the C default zero
through the same one-byte path. -/
theorem x86_setcc_mem_unsupported_example :
    (generatedX86SetccMemStep 10 false false
      (fun _ => 0xa5) (fun _ => 0x5a) ⟨true, true, true, true⟩ 0x0a000000 0x00
      0 0x40 false 0 0).value = 0 ∧
      (generatedX86SetccMemStep 10 false false
        (fun _ => 0xa5) (fun _ => 0x5a) ⟨true, true, true, true⟩ 0x0a000000
        0x00 0 0x40 false 0 0).bytes 0 = 0x00 := by
  decide

end KProgFormal
