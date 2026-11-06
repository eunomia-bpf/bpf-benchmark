import BPF
import BPFPath

namespace KProgTV.BPFChecks
open KProgFormal.Reference KProgTV.BPF

-- Catch register-nibble reversal and unsigned treatment of signed offsets.
theorem decode_wire_layout : decode #[0xbf, 0x83, 0xf8, 0xff, 0x44, 0x33, 0x22, 0x11] 0 =
    .ok ⟨0xbf, 3, 8, 0xfff8, 0x11223344⟩ := by rfl

theorem sdiv_minimum_overflow : alu 32 3 1 0x80000000 0xffffffff = .ok 0x80000000 := by rfl
theorem smod_truncates_toward_zero : alu 64 9 1 (-13) 3 = .ok (-1) := by rfl
theorem div_zero_is_zero : alu 64 3 0 123 0 = .ok 0 := by rfl
theorem mod_zero_preserves_low_word : alu 32 9 0 0x12345678 0 = .ok 0x12345678 := by rfl
theorem shift_masks_low_five_bits : alu 32 6 0 1 33 = .ok 2 := by rfl
theorem movsx_preserves_sign : alu 64 11 8 0 0x80 = .ok 0xffffffffffffff80 := by rfl

def memory : Memory where
  value := fun _ => 0xab
  readable := fun _ => true
  writable := fun _ => true
  initialized := fun _ => false

def initial : State where
  regs := fun r => if r = 10 then 0x10000 else 0
  memory := memory
  pc := 0

def externals : Environment where
  immediate := fun instruction high _ =>
    .ok (BitVec.ofNat 64 instruction.src + instruction.imm.setWidth 64 + high.setWidth 64)
  helperCall := fun instruction _ =>
    .ok ⟨instruction.imm.signExtend 64 + 1000, 2⟩
  helper := fun _ arguments m => .ok ⟨arguments.foldl (· + ·) 37, m, [], fun _ => 99⟩

-- JMP32 JA takes imm32, not off16. This catches the long-EXIT bug directly.
theorem gotol_uses_signed_imm32 :
    (step externals #[0x06,0,2,0, 0,0x80,0,0] initial).map (fun r => r.state.pc) =
      .ok 32769 := by rfl

theorem alu32_mov_zero_extends :
    (step externals #[0xb4,0,0,0, 0xff,0xff,0xff,0xff] initial).map (fun r => r.state.regs 0) =
      .ok 0xffffffff := by rfl

theorem alu64_mov_sign_extends :
    (step externals #[0xb7,0,0,0, 0xff,0xff,0xff,0xff] initial).map (fun r => r.state.regs 0) =
      .ok 0xffffffffffffffff := by rfl

-- Missing permission faults instead of producing an invented zero value.
theorem unreadable_memory_preserves_pc_and_reports_fault :
    (step externals #[0x79,0x10,0,0,0,0,0,0]
      { initial with memory := { memory with readable := fun _ => false } }).map
      (fun r => (r.state.pc, r.fault, r.events)) =
      .ok (0, some (.read 0 8), [.fault (.read 0 8)]) := by rfl

theorem uninitialized_bytes_are_arbitrary_input :
    readMemory memory 0 2 = .ok (0xabab, .memory .read 0 [0xab,0xab] false) := by rfl

theorem store_load_little_endian_and_initialization :
    (run externals #[0x62,0x0a,0xfc,0xff,0x78,0x56,0x34,0x12,
                    0x61,0xa0,0xfc,0xff,0,0,0,0, 0x95,0,0,0,0,0,0,0] 3 initial).map
      (fun r => (r.state.regs 0, r.state.halted, r.events)) =
      .ok (0x12345678, true,
        [.memory .write 0xfffc [0x78,0x56,0x34,0x12] true,
         .memory .read 0xfffc [0x78,0x56,0x34,0x12] true]) := by rfl

theorem helper_identity_arguments_result_and_clobbers_observable :
    (step externals #[0x85,0,0,0,7,0,0,0] initial).map
      (fun r => (r.state.regs 0, r.state.regs 1, r.events)) =
      .ok (37, 99, [.helper 1007 [0,0] 37]) := by rfl

theorem helper_arguments_come_from_actual_registers :
    (step externals #[0x85,0,0,0,7,0,0,0]
      { initial with regs := fun r => if r = 1 then 0x1122 else if r = 2 then 0x3344 else initial.regs r }).map
      (fun r => (r.state.regs 0, r.events)) =
      .ok (0x448b, [.helper 1007 [0x1122,0x3344] 0x448b]) := by rfl

theorem pseudo_immediate_requires_environment_resolution :
    (step externals #[0x18,0x10,0,0,7,0,0,0, 0,0,0,0,0,0,0,0] initial).map
      (fun r => (r.state.regs 0, r.state.pc)) = .ok (8, 2) := by rfl

theorem truncated_ldimm64_rejected :
    (step externals #[0x18,0,0,0,7,0,0,0] initial).map (fun r => r.state.pc) =
      .error "BPF instruction outside artifact" := by rfl

theorem exhausted_evaluation_is_not_partial_success :
    (run externals #[0xb7,0,0,0,2,0,0,0, 0x95,0,0,0,0,0,0,0] 1 initial).map
      (fun r => r.state.regs 0) =
      .error "BPF certificate evaluation exhausted before its boundary" := by rfl

theorem negative_pc_cannot_alias_entry :
    (step externals #[0xb7,0,0,0,2,0,0,0] { initial with pc := -1 }).map
      (fun r => r.state.regs 0) = .error "BPF PC before artifact" := by rfl

-- A certificate supplies a path witness, never permission to force a jump.
theorem path_cannot_override_actual_successor :
    (BPFPath.evaluate externals #[0x05,0,1,0,0,0,0,0, 0x95,0,0,0,0,0,0,0]
      [0,1] initial).map (fun r => r.state.pc) =
      .error "certificate BPF successor mismatch" := by rfl

theorem path_cannot_continue_after_return :
    (BPFPath.evaluate externals #[0x95,0,0,0,0,0,0,0] [0,0] initial).map
      (fun r => r.state.pc) = .error "certificate continues after BPF return" := by rfl

theorem path_cannot_continue_after_fault :
    (BPFPath.evaluate externals #[0x79,0x10,0,0,0,0,0,0] [0,0]
      { initial with memory := { memory with readable := fun _ => false } }).map
      (fun r => r.state.pc) = .error "certificate continues after BPF fault" := by rfl

end KProgTV.BPFChecks
