import KProgFormal.Reference.X86
import KProgFormal.Reference.AArch64
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.EntryEnvironment

open Reference

/-- Same-invocation values supplied by native_lab_input.h ABI2 kinds1..3,
after the host JIT prologue. Kind4 preserves CURRENT R1 bits and therefore is
not an additional cached base. No address, alignment or ABI bias is guessed. -/
structure Environment where
  bodyStack : Reference.Word
  bodyCode : Reference.Word
  outerReturn : Reference.Word

/-- Certified source/body offsets. Removing a prologue or permuting arguments
requires a separate ABI witness; marker1 is not assumed to be source-entry SP. -/
structure Frame where
  stackBias : Reference.Word
  codeBias : Reference.Word

inductive Base | stack | code | outerReturn
  deriving DecidableEq, Repr

def base (env : Environment) (frame : Frame) : Base → Reference.Word
  | .stack => env.bodyStack + frame.stackBias
  | .code => env.bodyCode + frame.codeBias
  | .outerReturn => env.outerReturn

/-- These are normalized native BYTE offsets, not simulator opcode indices.
A code-token decoder must establish its bound byte-offset table before using
this relation. Numeric address tags give no permission to dereference or RET. -/
inductive Value
  | scalar (bits : Reference.Word)
  | relative (origin : Base) (offset : Reference.Word)
  deriving DecidableEq, Repr

def materialize (env : Environment) (frame : Frame) : Value → Reference.Word
  | .scalar bits => bits
  | .relative origin offset => base env frame origin + offset

def add (value : Value) (delta : Reference.Word) : Value :=
  match value with
  | .scalar bits => .scalar (bits + delta)
  | .relative origin offset => .relative origin (offset + delta)

def sub (value : Value) (delta : Reference.Word) : Value :=
  match value with
  | .scalar bits => .scalar (bits - delta)
  | .relative origin offset => .relative origin (offset - delta)

/-- A partial write observes the numeric address before dropping its tag;
truncating the private offset alone loses low address bits. -/
def write32 (env : Environment) (frame : Frame) (value : Value) : Value :=
  .scalar (((materialize env frame value).setWidth 32).setWidth 64)

theorem add_refines (env : Environment) (frame : Frame) (value : Value) (delta : Reference.Word) :
    materialize env frame (add value delta) = materialize env frame value + delta := by
  cases value <;> simp only [add, materialize, Reference.Word] <;> bv_decide

theorem sub_refines (env : Environment) (frame : Frame) (value : Value) (delta : Reference.Word) :
    materialize env frame (sub value delta) = materialize env frame value - delta := by
  cases value <;> simp only [sub, materialize, Reference.Word] <;> bv_decide

/-- A native OR of only the low four bits can keep a relative pointer when
its actual base (including frame bias) is 16-byte aligned. This premise must
come from the entry ABI certificate; the private offset is not an address. -/
theorem aligned_low_or_refines (env : Environment) (frame : Frame) (origin : Base)
    (offset bits : Reference.Word)
    (aligned : base env frame origin &&& 15 = 0) (low : bits < 16) :
    materialize env frame (.relative origin (offset + (bits &&& ~~~offset))) =
      materialize env frame (.relative origin offset) ||| bits := by
  simp only [materialize, Reference.Word] at *
  bv_decide

/-- Same-base differences may cancel a base; flags, masks, partial writes and
stored words must still materialize their inputs before observing them. -/
theorem same_base_difference (env : Environment) (frame : Frame) (origin : Base)
    (left right : Reference.Word) :
    materialize env frame (.relative origin left) - materialize env frame (.relative origin right) =
      left - right := by
  simp only [materialize, Reference.Word]
  apply BitVec.sub_eq_iff_eq_add.mpr
  rw [BitVec.add_comm (base env frame origin) left,
    BitVec.add_comm (base env frame origin) right, ← BitVec.add_assoc, BitVec.sub_add_cancel]

theorem write32_after_add (env : Environment) (frame : Frame) (value : Value) (delta : Reference.Word) :
    materialize env frame (write32 env frame (add value delta)) =
      (((materialize env frame value + delta).setWidth 32).setWidth 64) := by
  change ((materialize env frame (add value delta)).setWidth 32).setWidth 64 = _
  rw [add_refines]

/-- Regression for SUB/ADD of SP around a restored stack: ZF observes the
actual nonzero stack address, rather than the private arena offset zero. -/
theorem restored_stack_zero_flag (env : Environment) (frame : Frame) (delta : Reference.Word)
    (nonzero : base env frame .stack ≠ 0) :
    Reference.X86.resultZero
      (materialize env frame (add (sub (.relative .stack 0) delta) delta)) = false := by
  simp only [Reference.X86.resultZero, materialize, add, sub, Reference.Word]
  bv_decide

/-- A private arena can retain offset indexing while stored guest bytes carry
the actual address. This equation is used with the existing store refinements. -/
theorem stored_address_bytes (env : Environment) (frame : Frame) (origin : Base)
    (offset : Reference.Word) (bytes : Nat) :
    valueBytes (materialize env frame (.relative origin offset)) bytes =
      valueBytes (base env frame origin + offset) bytes := rfl

/-- The initial x86 source relation names the actual saved return slot and the
actual numeric argument explicitly. The kernel/JIT/binding certificate must
supply these witnesses; a zero return sentinel or synthetic context is insufficient. -/
structure X86Entry (env : Environment) (frame : Frame) (argumentRegister : Reference.X86.Register)
    (numericArgument returnSlot : Reference.Word) (source : Reference.X86.State) : Prop where
  stack : source.gpr 4 = base env frame .stack
  code : source.pc = base env frame .code
  argument : source.gpr argumentRegister = numericArgument
  outerReturn : wordAt source.memory returnSlot 8 = env.outerReturn

/-- ARM source LR is the saved outer return word, independently of its body SP
bias. Argument-register permutation is explicit rather than assuming x0/r1. -/
structure Arm64Entry (env : Environment) (frame : Frame) (argumentRegister : Reference.AArch64.Gpr)
    (numericArgument : Reference.Word) (source : Reference.AArch64.State) : Prop where
  stack : source.sp = base env frame .stack
  code : source.pc = base env frame .code
  argument : source.gpr argumentRegister = numericArgument
  outerReturn : source.gpr 30 = env.outerReturn

/-- All entry observations use the same state witness, so aliased registers
cannot be assigned inconsistent independent symbolic values. -/
theorem x86_entry_observations (env : Environment) (frame : Frame)
    (argumentRegister : Reference.X86.Register) (numericArgument returnSlot : Reference.Word)
    (source : Reference.X86.State) (entry : X86Entry env frame argumentRegister numericArgument returnSlot source) :
    (source.gpr 4, source.pc, wordAt source.memory returnSlot 8, source.gpr argumentRegister) =
      (base env frame .stack, base env frame .code, env.outerReturn, numericArgument) := by
  rw [entry.stack, entry.code, entry.outerReturn, entry.argument]

theorem arm64_entry_observations (env : Environment) (frame : Frame)
    (argumentRegister : Reference.AArch64.Gpr) (numericArgument : Reference.Word)
    (source : Reference.AArch64.State) (entry : Arm64Entry env frame argumentRegister numericArgument source) :
    (source.sp, source.pc, source.gpr 30, source.gpr argumentRegister) =
      (base env frame .stack, base env frame .code, env.outerReturn, numericArgument) := by
  rw [entry.stack, entry.code, entry.outerReturn, entry.argument]

/-- Instantiating the symbolic base with this invocation's marker values gives
exact source-stack arithmetic, including wrapping and any certified frame bias. -/
theorem x86_stack_add (env : Environment) (frame : Frame) (argumentRegister : Reference.X86.Register)
    (numericArgument returnSlot : Reference.Word) (source : Reference.X86.State)
    (entry : X86Entry env frame argumentRegister numericArgument returnSlot source) (offset : Reference.Word) :
    materialize env frame (.relative .stack offset) = source.gpr 4 + offset := by
  rw [materialize, entry.stack]

theorem arm64_stack_add (env : Environment) (frame : Frame) (argumentRegister : Reference.AArch64.Gpr)
    (numericArgument : Reference.Word) (source : Reference.AArch64.State)
    (entry : Arm64Entry env frame argumentRegister numericArgument source) (offset : Reference.Word) :
    materialize env frame (.relative .stack offset) = source.sp + offset := by
  rw [materialize, entry.stack]

end KProgFormal.Refinement.EntryEnvironment
