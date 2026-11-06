import BPFPlatform
import KernelContexts

namespace KProgTV.ContextChecks
open KProgFormal.Reference KProgTV.KernelContexts

def bpf : BPF.Environment where
  immediate := fun _ _ _ => .error "context fixture has no pseudo immediates"
  helperCall := fun _ _ => .error "context fixture has no helper calls"
  helper := fun _ _ _ => .error "context fixture has no helper effects"

def environment (expansion : BPFPlatform.Expansion) : BPFPlatform.Environment where
  bpf := bpf
  access := fun pc _ => if pc = 0 then .ok (some expansion) else .ok none

def initial : BPF.State where
  regs := fun r => if r = 1 then 0x1000 else 0x12345678
  memory := ⟨fun _ => 0xab, fun _ => true, fun _ => true, fun _ => true⟩
  pc := 0

def observed (raw : Array Byte) (expansion : BPFPlatform.Expansion) :=
  (BPFPlatform.step (environment expansion) raw initial).map fun result =>
    (result.state.regs 1, result.state.regs 0, result.state.pc, result.events, result.fault)

def read (address : Word) (size : Nat) : Event :=
  .memory .read address (List.replicate size 0xab) true

-- These expose the actual truncation bug: virtual LDXW yields a physical64
-- packet pointer. Register0 and memory must survive this operation unchanged.
theorem data_keeps_pointer_high_bits_and_actual_access :
    observed raw_data expansion_data =
    .ok (0xabababababababab, 0x12345678, 1, [read 0x1000 8], none) := by rfl

theorem data_end_uses_physical_offset_eight :
    observed raw_data_end expansion_data_end =
    .ok (0xabababababababab, 0x12345678, 1, [read 0x1008 8], none) := by rfl

theorem data_meta_uses_physical_offset_sixteen :
    observed raw_data_meta expansion_data_meta =
    .ok (0xabababababababab, 0x12345678, 1, [read 0x1010 8], none) := by rfl

-- Nested context fields are several ordered memory operations, not one read
-- at the virtual xdp_md offset. Their final scalar load is zero extended.
theorem ingress_keeps_three_ordered_accesses :
    observed raw_ingress_ifindex expansion_ingress_ifindex =
    .ok (0xabababab, 0x12345678, 1,
      [read 0x1020 8, read 0xabababababababab 8, read 0xababababababac8b 4], none) := by rfl

theorem rx_queue_keeps_two_ordered_accesses :
    observed raw_rx_queue_index expansion_rx_queue_index =
    .ok (0xabababab, 0x12345678, 1,
      [read 0x1020 8, read 0xabababababababb3 4], none) := by rfl

theorem egress_uses_txq_not_rxq :
    observed raw_egress_ifindex expansion_egress_ifindex =
    .ok (0xabababab, 0x12345678, 1,
      [read 0x1028 8, read 0xabababababababab 8, read 0xababababababac8b 4], none) := by rfl

theorem ordinary_ldxw_demonstrates_wrong_pointer_value :
    (BPF.step bpf raw_data initial).map (fun result => result.state.regs 1) =
      .ok 0xabababab := by rfl

theorem wrong_original_context_offset_rejected :
    BPFPlatform.step (environment expansion_data_end) raw_data initial =
      .error "kernel context expansion does not match original instruction" := by rfl

theorem missing_context_cannot_use_ordinary_memory :
    BPFPlatform.step { bpf := bpf, access := fun _ _ => .error "missing context conversion" }
      raw_data initial = .error "missing context conversion" := by rfl

theorem truncated_expansion_cannot_erase_accesses :
    BPFPlatform.step (environment { expansion_ingress_ifindex with positions := fun _ => [0] })
      raw_ingress_ifindex initial =
      .error "kernel context expansion stopped before its boundary" := by rfl

theorem expansion_cannot_force_wrong_successor :
    BPFPlatform.step (environment { expansion_ingress_ifindex with positions := fun _ => [0,2] })
      raw_ingress_ifindex initial = .error "certificate BPF successor mismatch" := by rfl

theorem expansion_cannot_return_early :
    BPFPlatform.step (environment { expansion_data with
        bytes := #[0x95,0,0,0,0,0,0,0] }) raw_data initial =
      .error "kernel context expansion returned from program" := by rfl

theorem context_fault_keeps_virtual_pc_and_pointer :
    (BPFPlatform.expand bpf { expansion_data with positions := fun _ => [0] }
      { initial with pc := 7, memory := { initial.memory with readable := fun _ => false } }).map
      (fun result => (result.state.regs 1, result.state.pc, result.events, result.fault)) =
      .ok (0x1000, 7, [.fault (.read 0x1000 8)], some (.read 0x1000 8)) := by rfl

theorem zero_length_expansion_cannot_erase_a_context_load :
    BPFPlatform.step (environment { expansion_data with bytes := #[] }) raw_data initial =
      .error "invalid kernel context expansion extent" := by rfl

end KProgTV.ContextChecks
