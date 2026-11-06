import ARM64Path
import BPFPath
import SimpleCompiled

set_option maxRecDepth 4096
set_option maxHeartbeats 2000000

namespace KProgTV.SimpleStoreCounterexample
open KProgFormal.Reference KProgTV.SimpleCompiled

def memory : Memory :=
  ⟨fun _ => 0xaa, fun _ => true, fun _ => true, fun _ => true⟩

-- Entry of the actual success block, after data+72 <= data_end. This is a
-- block-level counterexample, not an assumed whole-program entry certificate.
def nativeBefore : AArch64.State where
  gpr := fun r => if r.val = 8 then 0x1000 else if r.val = 9 then 0x1050
    else if r.val = 10 then 0x1048 else if r.val = 11 then 0x1008 else 0
  sp := 0x9000
  flags := 0x80000000
  vector0 := 0
  memory := memory
  pc := 44

def proofBefore : BPF.State where
  regs := fun r => if r = 1 then 0x1000 else if r = 2 then 0x1050
    else if r = 3 then 0x1048 else if r = 10 then 0x8000 else 0
  memory := memory
  pc := 14

def externals : BPF.Environment where
  immediate := fun _ _ _ => .error "no external immediate in this block"
  helperCall := fun _ _ => .error "no helper in this block"
  helper := fun _ _ _ => .error "no helper effect in this block"

def nativeBlock := ARM64Path.evaluate 0 native [44,48,52,56,60,64,68,72] nativeBefore
def proofBlock := BPFPath.evaluate externals proof (List.range 13 |>.map (· + 14)) proofBefore

def write (address : Word) (bytes : List Byte) : Event := .memory .write address bytes true

theorem actual_native_block_accesses :
    nativeBlock.toOption.map (fun result => (result.state.gpr 0, result.state.pc, result.events, result.fault)) =
    some (2, 80,
      [write 0x1003 [0,0,0,0], write 0x1007 [0], write 0x1000 [0x4e,0x61], write 0x1002 [0xbc]], none) := by native_decide

theorem actual_clang_block_accesses :
    proofBlock.toOption.map (fun result => (result.state.regs 0, result.state.pc, result.events, result.fault)) =
    some (2, 27,
      [write 0x1003 [0], write 0x1004 [0], write 0x1005 [0], write 0x1006 [0],
       write 0x1007 [0], write 0x1000 [0x4e], write 0x1001 [0x61], write 0x1002 [0xbc]], none) := by native_decide

theorem strict_memory_trace_mismatch :
    nativeBlock.toOption.map (·.events) ≠ proofBlock.toOption.map (·.events) := by native_decide

def packet (memory : Memory) : List Byte :=
  (List.range 8).map fun index => memory.value (0x1000 + BitVec.ofNat 64 index)

theorem equal_packet_bytes_cannot_hide_trace_mismatch :
    nativeBlock.toOption.map (fun result => packet result.state.memory) =
      proofBlock.toOption.map (fun result => packet result.state.memory) := by native_decide

theorem native_block_is_real_execution :
    ∃ result, nativeBlock = .ok result ∧
      Execution (ARM64Path.instructionStep 0 native) nativeBefore result.events result.state := by
  cases evaluated : nativeBlock with
  | error error =>
      have checked := actual_native_block_accesses
      rw [evaluated] at checked
      cases checked
  | ok result =>
      exact ⟨result, rfl, ARM64Path.evaluate_sound 0 native [44,48,52,56,60,64,68,72] nativeBefore result evaluated⟩

theorem proof_block_is_real_execution :
    ∃ result, proofBlock = .ok result ∧
      Execution (BPFPath.instructionStep externals proof) proofBefore result.events result.state := by
  cases evaluated : proofBlock with
  | error error =>
      have checked := actual_clang_block_accesses
      rw [evaluated] at checked
      cases checked
  | ok result =>
      exact ⟨result, rfl, BPFPath.evaluate_sound externals proof (List.range 13 |>.map (· + 14)) proofBefore result evaluated⟩

end KProgTV.SimpleStoreCounterexample

#print axioms KProgTV.SimpleStoreCounterexample.strict_memory_trace_mismatch
#print axioms KProgTV.SimpleStoreCounterexample.native_block_is_real_execution
#print axioms KProgTV.SimpleStoreCounterexample.proof_block_is_real_execution
