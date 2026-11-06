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

-- The private marker must never decode as MOV imm=2 or expose fake effects.
def inputExternals : Environment :=
  { externals with nativeInput := fun
      | .stackPointer => .ok 0x12340000
      | .codeBase => .ok 0xffff000011112222
      | .returnAddress => .ok 0xffff000033334444 }

theorem native_entry_input_uses_bound_value :
    (step inputExternals #[0xb7,0x90,1,0,2,0,0,0] initial).map
      (fun r => (r.state.regs 0, r.state.pc, r.events, r.fault)) =
      .ok (0x12340000, 1, [], none) := by rfl

theorem native_code_input_keeps_all_bits :
    (step inputExternals #[0xb7,0x90,2,0,2,0,0,0] initial).map
      (fun r => r.state.regs 0) = .ok 0xffff000011112222 := by rfl

theorem native_return_input_keeps_all_bits :
    (step inputExternals #[0xb7,0x90,3,0,2,0,0,0] initial).map
      (fun r => r.state.regs 0) = .ok 0xffff000033334444 := by rfl

theorem numeric_input_preserves_word_and_memory (s : State) :
    execute inputExternals #[] s ⟨0xb7, 0, 9, 4, 2⟩ =
      .ok ⟨setReg { s with pc := s.pc + 1 } 0 (s.regs 1), [], none⟩ := by rfl

theorem unbound_entry_input_rejected :
    step externals #[0xb7,0x90,1,0,2,0,0,0] initial =
      .error "unbound native proof input" := by rfl

theorem native_input_rejects_wrong_abi :
    step inputExternals #[0xb7,0x90,1,0,1,0,0,0] initial =
      .error "invalid native proof input ABI/kind/register" := by rfl

theorem native_input_rejects_wrong_destination :
    step inputExternals #[0xb7,0x91,1,0,2,0,0,0] initial =
      .error "invalid native proof input ABI/kind/register" := by rfl

theorem native_input_rejects_unknown_kind :
    step inputExternals #[0xb7,0x90,6,0,2,0,0,0] initial =
      .error "invalid native proof input ABI/kind/register" := by rfl

theorem unbound_exclusive_choice_rejected :
    step externals #[0xb7,0x90,5,0,16,0,0,0] initial =
      .error "unbound exclusive environment choice" := by rfl

-- Reusing a source PC must not correlate retry outcomes with the first visit.
def retryExternals : Environment := { externals with
  exclusiveFailure := fun pc visit =>
    if pc = 16 then .ok (visit = 0) else .error "wrong exclusive source PC" }

theorem exclusive_retry_is_fresh :
    (BPFPath.evaluate retryExternals #[0xb7,0x90,5,0,16,0,0,0,
        0xb7,0x90,5,0,16,0,0,0] [0,1] initial).map
      (fun r => (r.state.regs 0, r.state.exclusiveVisit, r.events, r.fault)) =
      .ok (0, 2, [], none) := by rfl

theorem exclusive_choice_preserves_complete_state (s : State) (pc : BitVec 32)
    (outcome : Bool) :
    execute { externals with exclusiveFailure := fun _ _ => .ok outcome } #[] s
      ⟨0xb7, 0, 9, 5, pc⟩ =
      .ok ⟨setReg { s with pc := s.pc + 1, exclusiveVisit := s.exclusiveVisit + 1 } 0
        (if outcome then 1 else 0), [], none⟩ := by rfl

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

def counter : State :=
  { initial with
    regs := fun r => if r = 1 then 0x1004 else if r = 2 then 0xaabbccdd00000001 else initial.regs r
    memory := writeBytes memory 0x1000 (BPF.valueBytes 0x11223344ffffffff 8) }

-- FETCH returns the old low word, not the updated word, and clears its high32.
theorem atomic_fetch_add32_preserves_neighbor_bytes :
    (step externals #[0xc3,0x21,0xfc,0xff,1,0,0,0] counter).map
      (fun r => (r.state.regs 2, wordAt r.state.memory 0x1000 8, r.state.pc, r.events)) =
      .ok (0xffffffff, 0x1122334400000000, 1,
        [.memory .atomic 0x1000 [0xff,0xff,0xff,0xff] true]) := by rfl

theorem atomic_nonfetch_keeps_full_source_register :
    (step externals #[0xc3,0x21,0xfc,0xff,0,0,0,0] counter).map
      (fun r => (r.state.regs 2, wordAt r.state.memory 0x1000 8)) =
      .ok (0xaabbccdd00000001, 0x1122334400000000) := by rfl

theorem atomic_cmpxchg32_compares_low_word_and_returns_old :
    (step externals #[0xc3,0x21,0xfc,0xff,0xf1,0,0,0]
      { counter with regs := fun r => if r = 0 then 0xdeadbeefffffffff else counter.regs r }).map
      (fun r => (r.state.regs 0, r.state.regs 2, wordAt r.state.memory 0x1000 8)) =
      .ok (0xffffffff, 0xaabbccdd00000001, 0x1122334400000001) := by rfl

theorem failed_atomic_compare_does_not_write_or_initialize :
    (step externals #[0xc3,0x21,0xfc,0xff,0xf1,0,0,0]
      { counter with memory := { counter.memory with initialized := fun _ => false } }).map
      (fun r => (r.state.regs 0, wordAt r.state.memory 0x1000 8,
        initializedAt r.state.memory 0x1000 4, r.events)) =
      .ok (0xffffffff, 0x11223344ffffffff, false,
        [.memory .atomic 0x1000 [0xff,0xff,0xff,0xff] false]) := by rfl

theorem atomic_exchange64_returns_full_old_value :
    (step externals #[0xdb,0x21,0xfc,0xff,0xe1,0,0,0] counter).map
      (fun r => (r.state.regs 2, wordAt r.state.memory 0x1000 8)) =
      .ok (0x11223344ffffffff, 0xaabbccdd00000001) := by rfl

theorem atomic_logic_encodings_and_fetch_bit :
    (atomicValue 64 0x40 0xf0 0x0f 0, atomicValue 64 0x51 0xf0 0x3c 0,
      atomicValue 32 0xa1 0xf0 0xff 0) =
      (.ok (0xff, true), .ok (0x30, true), .ok (0x0f, true)) := by rfl

theorem atomic_write_fault_preserves_state_and_has_no_partial_read_event :
    (step externals #[0xc3,0x21,0xfc,0xff,1,0,0,0]
      { counter with memory := { counter.memory with writable := fun _ => false } }).map
      (fun r => (r.state.pc, r.state.regs 2, wordAt r.state.memory 0x1000 8, r.events)) =
      .ok (0, 0xaabbccdd00000001, 0x11223344ffffffff, [.fault (.write 0x1000 4)]) := by rfl

theorem atomic_fetch_cannot_overwrite_frame_pointer :
    (step externals #[0xc3,0xa1,0,0,1,0,0,0] counter).map (fun r => r.state.pc) =
      .error "BPF atomic fetch overwrites frame pointer" := by rfl

theorem atomic_rmw16_is_not_a_valid_width :
    (step externals #[0xcb,0x21,0,0,0,0,0,0] counter).map (fun r => r.state.pc) =
      .error "invalid BPF atomic read-modify-write width" := by rfl

end KProgTV.BPFChecks
