import KProgFormal.Reference.Memory
import Arm.Exec

/-! Native AArch64 execution is LNSym's checked step. This module only binds
native input/observation representations; it defines no ISA arithmetic,
instruction masks, register effects or memory-access interpreter. -/
namespace KProgFormal.Reference.AArch64

abbrev Register := Fin 32
abbrev Gpr := Fin 31
abbrev ExclusiveMonitor := _root_.ExclusiveMonitor
abbrev ExclusiveInputs := _root_.ExclusiveInputs

inductive ThreadPointerRegister | el1 | el2
  deriving DecidableEq, Repr

/-- Wire/native environment, with arbitrary byte contents and attributes. -/
structure Input where
  gpr : Gpr → Word
  sp : Word
  flags : Word
  vectors : Register → BitVec 128
  memory : Reference.Memory
  pc : Word
  spAlignmentCheck : Bool := true
  pairSingleAccess : Bool := false
  lse2UnalignedWithin16 : Bool := false
  exclusiveMonitor : Option ExclusiveMonitor := none
  exclusiveInputs : Option ExclusiveInputs := none
  threadPointer : Option _root_.ThreadPointerInputs := none

/-- All ISA state and observations remain in the external machine. The extra
word preserves native flag bits outside the NZCV fields modeled by LNSym. -/
structure State where
  machine : ArmState
  extraFlags : Word

/-- Retain the original native word and the external decoder's result together.
The proof prevents a wire-profile classifier from describing a different word. -/
structure Instruction where
  encoding : BitVec 32
  decoded : ArmInst
  valid : decode_raw_inst encoding = some decoded

def decode (bytes : Array Byte) : Except String Instruction := do
  if bytes.size != 4 then throw "AArch64 instruction must contain exactly four native bytes"
  let word := littleEndian 32 bytes.toList
  match valid : decode_raw_inst word with
  | none => throw "LNSym cannot decode this AArch64 instruction"
  | some decoded => pure { encoding := word, decoded, valid }

def ofInput (input : Input) (instruction : Instruction) : State :=
  let machine := (List.finRange 32).foldl (fun machine index =>
    let value := if h : index.val < 31 then input.gpr ⟨index.val,h⟩ else input.sp
    w (.GPR (BitVec.ofNat 5 index.val)) value machine) ArmState.default
  let machine := (List.finRange 32).foldl (fun machine index =>
    w (.SFP (BitVec.ofNat 5 index.val)) (input.vectors index) machine) machine
  let machine := write_pstate {
    n := (input.flags >>> 31).setWidth 1
    z := (input.flags >>> 30).setWidth 1
    c := (input.flags >>> 29).setWidth 1
    v := (input.flags >>> 28).setWidth 1 } machine
  let machine := set_program (write_pc input.pc machine) [(input.pc,instruction.encoding)]
  let profile : _root_.MemoryProfile := {
    readable := input.memory.readable
    writable := input.memory.writable
    initialized := input.memory.initialized
    spAlignmentCheck := input.spAlignmentCheck
    pairSingleAccess := input.pairSingleAccess
    lse2UnalignedWithin16 := input.lse2UnalignedWithin16 }
  { machine := { machine with
      mem := input.memory.value
      memoryProfile := some profile
      exclusive := { monitor := input.exclusiveMonitor, inputs := input.exclusiveInputs }
      threadPointerInputs := input.threadPointer }
    extraFlags := input.flags &&& 0xffffffff0fffffff }

def gpr (s : State) (index : Gpr) : Word :=
  r (.GPR (BitVec.ofNat 5 index.val)) s.machine

def sp (s : State) : Word := r (.GPR 31) s.machine

def readVector (s : State) (index : Register) : BitVec 128 :=
  r (.SFP (BitVec.ofNat 5 index.val)) s.machine

def pc (s : State) : Word := read_pc s.machine

def flags (s : State) : Word :=
  (s.extraFlags &&& 0xffffffff0fffffff) |||
  ((read_flag .N s.machine).setWidth 64 <<< 31) |||
  ((read_flag .Z s.machine).setWidth 64 <<< 30) |||
  ((read_flag .C s.machine).setWidth 64 <<< 29) |||
  ((read_flag .V s.machine).setWidth 64 <<< 28)

def profile (s : State) : Except String _root_.MemoryProfile :=
  match read_memory_profile s.machine with
  | none => .error "LNSym native view requires its explicit memory profile"
  | some profile => .ok profile

def memory (s : State) : Except String Reference.Memory := do
  let p ← profile s
  pure {
    value := s.machine.mem
    readable := p.readable
    writable := p.writable
    initialized := p.initialized }

def exclusiveMonitor (s : State) : Option ExclusiveMonitor := s.machine.exclusive.monitor

def threadPointer (s : State) (source : ThreadPointerRegister) : Option Word :=
  match s.machine.threadPointerInputs with
  | none => none
  | some inputs => match source with | .el1 => inputs.el1 | .el2 => inputs.el2

/-- Legacy V0-only wire requests remain valid for their original forms. Full
banks are required before any other modeled SIMD cell is used or modified.
These are external decoded fields, not another instruction decoder. -/
def requiresVectorBank (instruction : Instruction) : Bool :=
  match instruction.decoded with
  | .DPSFP (.Conversion_between_FP_and_Int i) =>
    (if DPSFP.isGPRdest instruction.decoded then i.Rn else i.Rd) != 0
  | .DPSFP (.Advanced_simd_two_reg_misc i) => i.Rn != 0 || i.Rd != 0
  | .DPSFP (.Advanced_simd_across_lanes i) => i.Rn != 0 || i.Rd != 0
  | .DPSFP _ => true
  | .LDST (.Reg_imm_pre_indexed i) => i.V == 1 && i.Rt != 0
  | .LDST (.Reg_imm_post_indexed i) => i.V == 1 && i.Rt != 0
  | .LDST (.Reg_unsigned_imm i) => i.V == 1 && i.Rt != 0
  | .LDST (.Reg_unscaled_imm i) => i.VR == 1 && i.Rt != 0
  | .LDST (.Reg_register_offset i) => i.V == 1 && i.Rt != 0
  | .LDST (.Reg_pair_pre_indexed i) => i.V == 1 && (i.Rt != 0 || i.Rt2 != 0)
  | .LDST (.Reg_pair_post_indexed i) => i.V == 1 && (i.Rt != 0 || i.Rt2 != 0)
  | .LDST (.Reg_pair_signed_offset i) => i.V == 1 && (i.Rt != 0 || i.Rt2 != 0)
  | _ => false

private def nativeFault : _root_.MemoryAccessFault → Fault
  | .read address bytes => .read address bytes
  | .write address bytes => .write address bytes
  | .spAlignment address => .spAlignment address
  | .alignment address bytes => .alignment address bytes

/-- Project only the newly appended observations. The entire original external
trace remains in State.machine, including atomic order and captured exclusive
values; the legacy native event view retains its byte/read/write/monitor data. -/
private def nativeEvents (events : List _root_.MemoryAccessEvent) : List Event × Option Fault :=
  events.foldl (fun (history,fault) event => match event with
    | .memory kind address value initialized =>
      let kind := match kind with | .read => AccessKind.read | .write => .write
      (history ++ [.memory kind address value initialized],fault)
    | .atomic access initialized =>
      (history ++ [.memory .atomic access.address (valueBytes access.oldValue access.bytes) initialized,
        .memory .write access.address (valueBytes access.newValue access.bytes) true],fault)
    | .exclusive access =>
      let action := match access.action with
        | .reserve => Reference.ExclusiveAction.reserve | .attempt => .attempt | .clear => .clear
      (history ++ [.exclusive action access.address access.bytes access.acquire access.release access.success],fault)
    | .fault reason =>
      let reason := nativeFault reason
      (history ++ [.fault reason],some reason)) ([],none)

def step (before : State) : Transition State :=
  let after := stepi_checked before.machine
  let delta := (read_memory_accesses after).drop (read_memory_accesses before.machine).length
  let (events,fault) := nativeEvents delta
  let (events,fault) := if read_err before.machine != .None then (events,fault) else
    match read_err after with
    | .SystemRegisterDenied encoding =>
      let denied := Fault.systemRegister encoding.toNat
      (events ++ [.fault denied],some denied)
    | _ => (events,fault)
  ⟨{ before with machine := after },events,fault⟩

/-- Architectural access faults have typed observations. Every other external
error stays a model refusal; there is no successful total-memory fallback. -/
def modelError (output : Transition State) : Option StateError :=
  if output.fault.isSome then none else
  match read_err output.state.machine with | .None => none | error => some error

def Step (before : State) (after : Transition State) : Prop := step before = after

end KProgFormal.Reference.AArch64
