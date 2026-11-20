ARM64_HOST_ENV := -include oracles/arm64_entry_environment_host.h -DKPROG_TEST_EXCLUSIVE_FAILURE=0 -include oracles/arm64_exclusive_choice_host.h
.PHONY: check

check:
	install -d build
	python3 tools/check_lookup_ambiguity.py
	lake build
	python3 tools/check_reference.py
	python3 tools/check_reference_x86_scalar.py
	python3 tools/check_reference_x86_map_lookup.py
	python3 tools/check_reference_x86_arithmetic.py
	python3 tools/check_reference_x86_logic.py
	python3 tools/check_reference_x86_legacy_shift.py
	python3 tools/check_reference_x86_unary.py
	python3 tools/check_reference_x86_popcount.py
	python3 tools/check_reference_x86_movx.py
	python3 tools/check_reference_x86_divide.py
	python3 tools/check_reference_x86_multiply.py
	python3 tools/check_reference_x86_mulx.py
	python3 tools/check_reference_x86_double_shift.py
	python3 tools/check_reference_x86_xmm0.py
	python3 tools/check_reference_x86_rep_movs.py
	python3 tools/check_reference_x86_call.py
	python3 tools/check_x86_divide_handler.py
	python3 tools/check_x86_rotate_handler.py
	python3 tools/check_x86_high_load.py
	python3 tools/check_x86_popcount_memory.py
	python3 tools/check_x86_encoded_handlers.py
	python3 tools/check_reference_x86_condition.py
	python3 tools/check_reference_x86_path.py
	python3 tools/check_x86_memory_widths.py
	python3 tools/check_arm64_pointer_access.py
	python3 tools/check_reference_arm64.py
	python3 tools/check_reference_arm64_addressed_memory.py
	python3 tools/check_reference_exclusive.py
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_six_flags_host.c -o build/test_x86_six_flags_host
	./build/test_x86_six_flags_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_full_condition_host.c -o build/test_x86_full_condition_host
	./build/test_x86_full_condition_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_cond_host.c -o build/test_arm64_cond_host
	./build/test_arm64_cond_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_branch_emit_host.c -o build/test_x86_branch_emit_host
	./build/test_x86_branch_emit_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/width_fallback_host.c -o build/width_fallback_host
	./build/width_fallback_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_alu_result_arm_host.c -o build/test_x86_alu_result_arm_host
	./build/test_x86_alu_result_arm_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_alu_memory_frame_host.c -o build/test_x86_alu_memory_frame_host
	./build/test_x86_alu_memory_frame_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_alu_source_frame_host.c -o build/test_x86_alu_source_frame_host
	./build/test_x86_alu_source_frame_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_imul_memory_frame_host.c -o build/test_x86_imul_memory_frame_host
	./build/test_x86_imul_memory_frame_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_bmi_memory_frame_host.c -o build/test_x86_bmi_memory_frame_host
	./build/test_x86_bmi_memory_frame_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_bit_memory_frame_host.c -o build/test_x86_bit_memory_frame_host
	./build/test_x86_bit_memory_frame_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_andn_bt_memory_frame_host.c -o build/test_x86_andn_bt_memory_frame_host
	./build/test_x86_andn_bt_memory_frame_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_xmm0_memory_frame_host.c -o build/test_x86_xmm0_memory_frame_host
	./build/test_x86_xmm0_memory_frame_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_mov_memory_frame_host.c -o build/test_x86_mov_memory_frame_host
	./build/test_x86_mov_memory_frame_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_imul_flags_host.c -o build/test_imul_flags_host
	./build/test_imul_flags_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_alu_decode_host.c -o build/test_x86_alu_decode_host
	./build/test_x86_alu_decode_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_specialization_host.c -o build/test_x86_specialization_host
	./build/test_x86_specialization_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_stack_index_host.c -o build/test_x86_stack_index_host
	./build/test_x86_stack_index_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_stack_arena_host.c -o build/test_x86_stack_arena_host
	./build/test_x86_stack_arena_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_ror_result_host.c -o build/test_x86_ror_result_host
	./build/test_x86_ror_result_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bswap_host.c -o build/test_x86_bswap_host
	./build/test_x86_bswap_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_signed_host.c -o build/test_x86_signed_host
	./build/test_x86_signed_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_popcount_host.c -o build/test_x86_popcount_host
	./build/test_x86_popcount_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bitops_host.c -o build/test_x86_bitops_host
	./build/test_x86_bitops_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_doubleshift_host.c -o build/test_x86_doubleshift_host
	./build/test_x86_doubleshift_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_shift_flags_host.c -o build/test_x86_shift_flags_host
	./build/test_x86_shift_flags_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_reg_lane_aux_host.c -o build/test_x86_reg_lane_aux_host
	./build/test_x86_reg_lane_aux_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_mem_aux_host.c -o build/test_x86_mem_aux_host
	./build/test_x86_mem_aux_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_mem_access_host.c -o build/test_mem_access_host
	./build/test_mem_access_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_alu_handler_host.c -o build/test_x86_mem_alu_handler_host
	./build/test_x86_mem_alu_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_store_alu_handler_host.c -o build/test_x86_mem_store_alu_handler_host
	./build/test_x86_mem_store_alu_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_unary_handler_host.c -o build/test_x86_mem_unary_handler_host
	./build/test_x86_mem_unary_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_logic_handler_host.c -o build/test_x86_mem_logic_handler_host
	./build/test_x86_mem_logic_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_shift_handler_host.c -o build/test_x86_mem_shift_handler_host
	./build/test_x86_mem_shift_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_bit_handler_host.c -o build/test_x86_mem_bit_handler_host
	./build/test_x86_mem_bit_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_imul_handler_host.c -o build/test_x86_mem_imul_handler_host
	./build/test_x86_mem_imul_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_compare_handler_host.c -o build/test_x86_mem_compare_handler_host
	./build/test_x86_mem_compare_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mulx_handler_host.c -o build/test_x86_mulx_handler_host
	./build/test_x86_mulx_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_imul_reg_imm_handler_host.c -o build/test_x86_imul_reg_imm_handler_host
	./build/test_x86_imul_reg_imm_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_index_host.c -o build/test_x86_mem_index_host
	./build/test_x86_mem_index_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_reg_dispatch_host.c -o build/test_x86_reg_dispatch_host
	./build/test_x86_reg_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_helper_dispatch_host.c -o build/test_x86_helper_dispatch_host
	./build/test_x86_helper_dispatch_host
	python3 tools/check_helper_errors.py --cc "$(CC)"
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_xchg_host.c -o build/test_x86_xchg_host
	./build/test_x86_xchg_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mulx_arm_host.c -o build/test_x86_mulx_arm_host
	./build/test_x86_mulx_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_div_host.c -o build/test_x86_div_host
	./build/test_x86_div_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_doubleshift_arm_host.c -o build/test_x86_doubleshift_arm_host
	./build/test_x86_doubleshift_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_popcnt_flags_host.c -o build/test_x86_popcnt_flags_host
	./build/test_x86_popcnt_flags_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bzhi_flags_host.c -o build/test_x86_bzhi_flags_host
	./build/test_x86_bzhi_flags_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_movx_shape_host.c -o build/test_x86_movx_shape_host
	./build/test_x86_movx_shape_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mov_reg_arm_host.c -o build/test_x86_mov_reg_arm_host
	./build/test_x86_mov_reg_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_stack_arm_host.c -o build/test_x86_stack_arm_host
	./build/test_x86_stack_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_write_width_arm_host.c -o build/test_x86_write_width_arm_host
	./build/test_x86_write_width_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_stack_write_lanes_host.c -o build/test_x86_stack_write_lanes_host
	./build/test_x86_stack_write_lanes_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_alu_flag_arm_host.c -o build/test_x86_alu_flag_arm_host
	./build/test_x86_alu_flag_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_dispatch_family_host.c -o build/test_x86_dispatch_family_host
	./build/test_x86_dispatch_family_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_dispatch_singleton_host.c -o build/test_x86_dispatch_singleton_host
	./build/test_x86_dispatch_singleton_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_reg_presence_host.c -o build/test_x86_reg_presence_host
	./build/test_x86_reg_presence_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_width_effective_host.c -o build/test_x86_width_effective_host
	./build/test_x86_width_effective_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_lea_handler_host.c -o build/test_x86_lea_handler_host
	./build/test_x86_lea_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mov_handler_host.c -o build/test_x86_mov_handler_host
	./build/test_x86_mov_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_movx_reg_host.c -o build/test_x86_movx_reg_host
	./build/test_x86_movx_reg_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_read_dispatch_host.c -o build/test_x86_mem_read_dispatch_host
	./build/test_x86_mem_read_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mov_load_host.c -o build/test_x86_mov_load_host
	./build/test_x86_mov_load_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_store_host.c -o build/test_x86_store_host
	./build/test_x86_store_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_setcc_host.c -o build/test_x86_setcc_host
	./build/test_x86_setcc_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_cc_decode_host.c -o build/test_x86_cc_decode_host
	./build/test_x86_cc_decode_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_cc_decode_host.c -o build/test_arm64_cc_decode_host
	./build/test_arm64_cc_decode_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_helper_idents_host.c -o build/test_arm64_helper_idents_host
	./build/test_arm64_helper_idents_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_setcc_mem_host.c -o build/test_x86_setcc_mem_host
	./build/test_x86_setcc_mem_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_cmov_host.c -o build/test_x86_cmov_host
	./build/test_x86_cmov_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_movbe_host.c -o build/test_x86_movbe_host
	./build/test_x86_movbe_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_mov_load_map_ptr_host.c -o build/test_x86_mov_load_map_ptr_host
	./build/test_x86_mov_load_map_ptr_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_xmm0_host.c -o build/test_x86_xmm0_host
	./build/test_x86_xmm0_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_callmem_host.c -o build/test_x86_callmem_host
	./build/test_x86_callmem_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_pushpop_host.c -o build/test_x86_pushpop_host
	./build/test_x86_pushpop_host
	$(CC) -Wall -Wextra -O2 -mno-red-zone -fsanitize=undefined -fno-sanitize-recover=all -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_rep_memory_frame_host.c -o build/test_x86_rep_memory_frame_host
	./build/test_x86_rep_memory_frame_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_rep_movs_host.c -o build/test_x86_rep_movs_host
	./build/test_x86_rep_movs_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_andn_host.c -o build/test_x86_andn_host
	./build/test_x86_andn_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bzhi_host.c -o build/test_x86_bzhi_host
	./build/test_x86_bzhi_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bt_host.c -o build/test_x86_bt_host
	./build/test_x86_bt_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_cmpop_host.c -o build/test_x86_cmpop_host
	./build/test_x86_cmpop_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/cross_isa_tag_host.c -o build/cross_isa_tag_host
	./build/cross_isa_tag_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/cross_isa_differential_host.c -o build/cross_isa_differential_host
	./build/cross_isa_differential_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_width_host.c -o build/test_arm64_width_host
	./build/test_arm64_width_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_width_effective_host.c -o build/test_arm64_width_effective_host
	./build/test_arm64_width_effective_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_flags_host.c -o build/test_arm64_flags_host
	./build/test_arm64_flags_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_alu_result_host.c -o build/test_arm64_alu_result_host
	./build/test_arm64_alu_result_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_alu_handler_host.c -o build/test_arm64_alu_handler_host
	./build/test_arm64_alu_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_alu_operand_host.c -o build/test_arm64_alu_operand_host
	./build/test_arm64_alu_operand_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_flag_operand_host.c -o build/test_arm64_flag_operand_host
	./build/test_arm64_flag_operand_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_imm_operand_host.c -o build/test_arm64_imm_operand_host
	./build/test_arm64_imm_operand_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_alu_operand_select_host.c -o build/test_arm64_alu_operand_select_host
	./build/test_arm64_alu_operand_select_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_flag_handler_host.c -o build/test_arm64_flag_handler_host
	./build/test_arm64_flag_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_logic_flag_handler_host.c -o build/test_arm64_logic_flag_handler_host
	./build/test_arm64_logic_flag_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_ccmp_handler_host.c -o build/test_arm64_ccmp_handler_host
	./build/test_arm64_ccmp_handler_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_ccmp_decode_host.c -o build/test_arm64_ccmp_decode_host
	./build/test_arm64_ccmp_decode_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_dispatch_family_host.c -o build/test_arm64_dispatch_family_host
	./build/test_arm64_dispatch_family_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_dispatch_singleton_host.c -o build/test_arm64_dispatch_singleton_host
	./build/test_arm64_dispatch_singleton_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mod_host.c -o build/test_arm64_mod_host
	./build/test_arm64_mod_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_bitfield_host.c -o build/test_arm64_bitfield_host
	./build/test_arm64_bitfield_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. oracles/test_arm64_mul_host.c -o build/test_arm64_mul_host
	./build/test_arm64_mul_host
	$(CC) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mul_wide_host.c -o build/test_arm64_mul_wide_host
	./build/test_arm64_mul_wide_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_imul_flags_wide_host.c -o build/test_x86_imul_flags_wide_host
	./build/test_x86_imul_flags_wide_host
	./build/mut_mulroute
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_extrev_host.c -o build/test_arm64_extrev_host
	./build/test_arm64_extrev_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_csel_host.c -o build/test_arm64_csel_host
	./build/test_arm64_csel_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_csel_ptr_host.c -o build/test_arm64_csel_ptr_host
	./build/test_arm64_csel_ptr_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_branch_host.c -o build/test_arm64_branch_host
	./build/test_arm64_branch_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_branch_emit_host.c -o build/test_arm64_branch_emit_host
	./build/test_arm64_branch_emit_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_control_flow_trace_host.c -o build/test_control_flow_trace_host
	./build/test_control_flow_trace_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_movk_host.c -o build/test_arm64_movk_host
	./build/test_arm64_movk_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_shift_host.c -o build/test_arm64_shift_host
	./build/test_arm64_shift_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_reduction_host.c -o build/test_arm64_reduction_host
	./build/test_arm64_reduction_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_unary_host.c -o build/test_arm64_unary_host
	./build/test_arm64_unary_host
	$(CC) -include oracles/arm64_entry_environment_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=all -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_memory_tokens_host.c -o build/test_arm64_memory_tokens_host
	./build/test_arm64_memory_tokens_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=all -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_return_token_host.c -o build/test_arm64_return_token_host
	./build/test_arm64_return_token_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_helper_call_host.c -o build/test_arm64_helper_call_host
	./build/test_arm64_helper_call_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_helper_call_host.c -o build/test_x86_helper_call_host
	./build/test_x86_helper_call_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_entry_context_host.c -o build/test_arm64_entry_context_host
	./build/test_arm64_entry_context_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_cneg_host.c -o build/test_arm64_cneg_host
	./build/test_arm64_cneg_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_orn_host.c -o build/test_arm64_orn_host
	./build/test_arm64_orn_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_adrp_host.c -o build/test_arm64_adrp_host
	./build/test_arm64_adrp_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stlxr_host.c -o build/test_arm64_stlxr_host
	./build/test_arm64_stlxr_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mov_host.c -o build/test_arm64_mov_host
	./build/test_arm64_mov_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_ldrsx_host.c -o build/test_arm64_ldrsx_host
	./build/test_arm64_ldrsx_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_ldrsx_op_host.c -o build/test_arm64_ldrsx_op_host
	./build/test_arm64_ldrsx_op_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_load_tag_host.c -o build/test_arm64_load_tag_host
	./build/test_arm64_load_tag_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_pair_load_tag_host.c -o build/test_arm64_pair_load_tag_host
	./build/test_arm64_pair_load_tag_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_offset_host.c -o build/test_arm64_mem_offset_host
	./build/test_arm64_mem_offset_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_index_host.c -o build/test_arm64_mem_index_host
	./build/test_arm64_mem_index_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_reg_presence_host.c -o build/test_arm64_reg_presence_host
	./build/test_arm64_reg_presence_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. oracles/test_arm64_reg_dispatch_host.c -o build/test_arm64_reg_dispatch_host
	./build/test_arm64_reg_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_fmov_host.c -o build/test_arm64_fmov_host
	./build/test_arm64_fmov_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_fmov_dest_host.c -o build/test_arm64_fmov_dest_host
	./build/test_arm64_fmov_dest_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_load_bytes_host.c -o build/test_arm64_load_bytes_host
	./build/test_arm64_load_bytes_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_store_bytes_host.c -o build/test_arm64_store_bytes_host
	./build/test_arm64_store_bytes_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_byte_lane_host.c -o build/test_arm64_byte_lane_host
	./build/test_arm64_byte_lane_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_dispatch_host.c -o build/test_arm64_mem_dispatch_host
	./build/test_arm64_mem_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_write_arm_host.c -o build/test_arm64_mem_write_arm_host
	./build/test_arm64_mem_write_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_tag_host.c -o build/test_arm64_stack_tag_host
	./build/test_arm64_stack_tag_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_arm_host.c -o build/test_arm64_stack_arm_host
	./build/test_arm64_stack_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_write_lanes_host.c -o build/test_arm64_stack_write_lanes_host
	./build/test_arm64_stack_write_lanes_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_write_tag_action_host.c -o build/test_arm64_stack_write_tag_action_host
	./build/test_arm64_stack_write_tag_action_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_read_tag_source_host.c -o build/test_arm64_stack_read_tag_source_host
	./build/test_arm64_stack_read_tag_source_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_helper_arg_ptr_host.c -o build/test_arm64_helper_arg_ptr_host
	./build/test_arm64_helper_arg_ptr_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_base_src_host.c -o build/test_arm64_mem_base_src_host
	./build/test_arm64_mem_base_src_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_index_value_host.c -o build/test_arm64_mem_index_value_host
	./build/test_arm64_mem_index_value_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_dq_mem_extra_host.c -o build/test_arm64_dq_mem_extra_host
	./build/test_arm64_dq_mem_extra_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_vreg_field_host.c -o build/test_arm64_vreg_field_host
	./build/test_arm64_vreg_field_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_write_arm_host.c -o build/test_arm64_write_arm_host
	./build/test_arm64_write_arm_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_dq_mem_host.c -o build/test_arm64_dq_mem_host
	./build/test_arm64_dq_mem_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_pair_mem_host.c -o build/test_arm64_pair_mem_host
	./build/test_arm64_pair_mem_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_prepost_host.c -o build/test_arm64_mem_prepost_host
	./build/test_arm64_mem_prepost_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_vreg_host.c -o build/test_arm64_vreg_host
	./build/test_arm64_vreg_host
	$(CC) -Wall -Wextra -O2 -I. -I../arm64 oracles/test_arm64_aux_host.c -o build/test_arm64_aux_host
	./build/test_arm64_aux_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_arena_host.c -o build/test_arm64_stack_arena_host
	./build/test_arm64_stack_arena_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_index_host.c -o build/test_arm64_stack_index_host
	./build/test_arm64_stack_index_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 oracles/test_arm64_decode_host.c -o build/test_arm64_decode_host
	./build/test_arm64_decode_host

# Both ISA forks define a Tests library; resolve nested LNSym test imports
# from its own package, after the combined external-library/regression build.
.PHONY: mature
mature:
	cd mature && lake build KProgMature @x86lean/+Tests.CanonicalAddress @x86lean/+Tests.CheckedAccess @lnsym/+Tests.ConditionalSelectTest @lnsym/+Tests.BranchTest @lnsym/+Tests.ThreadPointerTest @lnsym/+Tests.XZRTest @lnsym/+Tests.MultiplyDivideTest @lnsym/+Tests.ExtractCompareTest @lnsym/+Tests.SingleRegMemoryTest @lnsym/+Tests.LDSTTest @lnsym/+Tests.VectorReductionTest @lnsym/+Tests.ExtendedArithmeticTest @lnsym/+Tests.AtomicMemoryTest @lnsym/+Tests.ExclusiveMemoryTest @lnsym/+Tests.PairMemoryTest @lnsym/+Tests.CheckedMemoryTest @lnsym/+Tests.MayModifiedRegsTest @lnsym/+Arm.Memory.MemoryProofs
	cd external/LNSym && lake build Tests.Tactics.Sym Tests.Tactics.ReduceFetchInst

# Export with the existing CompCert frontend. Toolchain builds are disabled
# under the operator's 2026-11-20 instruction.
.PHONY: clight-sources clight

# Clight is a build product. Profile inputs are sole checked-in C snapshots;
# build symlinks preserve the frontend source_file metadata and include paths.
.DELETE_ON_ERROR:
CLIGHT_MODULES := Arm64Access Arm64Address Arm64Addressing Arm64Entry Arm64Numeric Arm64PayloadProfile Arm64Program Arm64ProgramContext Arm64ProgramFixture Arm64Stack X86Context X86ContextSkb X86ContextXdp X86Helpers X86Inline X86Memory X86Numeric X86Pointer X86ProgramProfile X86ReadonlyProfile X86StackProfile200 X86StackProfile376 X86TetragonWake
CLIGHT_OUTPUTS := $(addprefix KProgFormal/Clight/,$(addsuffix .lean,$(CLIGHT_MODULES)))
CLIGHT_INCLUDES := -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src
CLIGHT_PLAIN := Arm64Access Arm64Address Arm64Addressing Arm64Entry Arm64Numeric Arm64Program Arm64ProgramContext Arm64ProgramFixture Arm64Stack X86Context X86Helpers X86Inline X86Memory X86Numeric X86Pointer

$(addprefix KProgFormal/Clight/,$(addsuffix .lean,$(CLIGHT_PLAIN))): KProgFormal/Clight/%.lean: c/%.c
KProgFormal/Clight/X86TetragonWake.lean: c/TetragonWake.c
KProgFormal/Clight/X86ProgramProfile.lean: build/x86_program_profile.bpf.c
KProgFormal/Clight/X86ReadonlyProfile.lean: build/x86_readonly_profile.bpf.c
KProgFormal/Clight/X86ContextXdp.lean: build/x86_context_xdp.bpf.c
KProgFormal/Clight/X86ContextSkb.lean: build/x86_context_skb.bpf.c
KProgFormal/Clight/X86StackProfile200.lean: build/x86_stack_profile_200.bpf.c
KProgFormal/Clight/X86StackProfile376.lean: build/x86_stack_profile_376.bpf.c
KProgFormal/Clight/Arm64PayloadProfile.lean: build/arm64_payload_profile.bpf.c

KProgFormal/Clight/X86Inline.lean KProgFormal/Clight/X86TetragonWake.lean KProgFormal/Clight/X86ReadonlyProfile.lean KProgFormal/Clight/X86ContextXdp.lean KProgFormal/Clight/X86ContextSkb.lean KProgFormal/Clight/X86ProgramProfile.lean KProgFormal/Clight/X86StackProfile200.lean KProgFormal/Clight/X86StackProfile376.lean KProgFormal/Clight/Arm64Addressing.lean KProgFormal/Clight/Arm64Program.lean KProgFormal/Clight/Arm64ProgramFixture.lean KProgFormal/Clight/Arm64ProgramContext.lean KProgFormal/Clight/Arm64PayloadProfile.lean: CLIGHT_OPTIONS += -fstruct-passing
KProgFormal/Clight/X86TetragonWake.lean KProgFormal/Clight/X86ReadonlyProfile.lean KProgFormal/Clight/X86ContextXdp.lean KProgFormal/Clight/X86ContextSkb.lean KProgFormal/Clight/X86ProgramProfile.lean: CLIGHT_OPTIONS += -DKPROG_X86_PROGRAM_EXPORT=1 -include c/ProgramSections.h
KProgFormal/Clight/X86StackProfile200.lean KProgFormal/Clight/X86StackProfile376.lean: CLIGHT_OPTIONS += -include c/ProgramSections.h
KProgFormal/Clight/Arm64PayloadProfile.lean: CLIGHT_OPTIONS += -DKPROG_ARM64_PROGRAM_EXPORT=1
KProgFormal/Clight/X86Numeric.lean: CLIGHT_INCLUDES :=

build KProgFormal/Clight:
	install -d $@

build/%.bpf.c: c/%.bpf.c | build
	ln -s ../$< $@

external/clean/clightgen:
	$(error Existing clightgen is required; toolchain builds are disabled)

$(CLIGHT_OUTPUTS): Makefile external/clean/clightgen | build KProgFormal/Clight
	external/clean/clightgen -lean -normalize $(CLIGHT_OPTIONS) $(CLIGHT_INCLUDES) -MD -MP -MF build/clight-$(@F:.lean=.d) -MT $@ -o $@ $(firstword $(filter %.c,$^))

-include $(wildcard build/clight-*.d)

clight-sources: external/clean/clightgen
	$(MAKE) $(CLIGHT_OUTPUTS)

clight: clight-sources
	install -d build
	$(CC) -std=c11 -Wall -Wextra -O2 -I../../vendor/libbpf/include/uapi oracles/test_bpf_abi_layout.c -o build/test_bpf_abi_layout
	./build/test_bpf_abi_layout
	external/clean/clightgen -lean -normalize -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -o build/BpfABILayout.lean oracles/test_bpf_abi_layout.c
	../stock-path/bin/clang -c oracles/x86_readonly_profile.S -o build/x86_readonly_profile.native.o
	for adapter in 0 1; do \
	  flags=; if test $$adapter = 1; then flags=-D__COMPCERT__; fi; \
	  $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    $$flags -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
	    oracles/test_x86_readonly_host.c build/x86_readonly_profile.native.o -o build/test_x86_readonly_host && \
	  ./build/test_x86_readonly_host || exit $$?; \
	done
	for skb in 0 1; do for adapter in 0 1; do \
	  name=x86_context_xdp; if test $$skb = 1; then name=x86_context_skb; fi; \
	  flags=; if test $$adapter = 1; then flags=-D__COMPCERT__; fi; \
	  $(CC) -std=c11 -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    -DKPROG_X86_PROGRAM_EXPORT=1 -D__bpf_fastcall= $$flags \
	    -include oracles/compcert_memory_host.h -include oracles/x86_program_environment_host.h \
	    -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
	    -c build/$$name.bpf.c -o build/x86_context_program_host.o && \
	  $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    -DSKB=$$skb -DADAPTER=$$adapter oracles/test_x86_context_program_host.c \
	    build/x86_context_program_host.o -o build/test_x86_context_program_host && \
	  ./build/test_x86_context_program_host || exit $$?; \
	done; done
	$(CC) -std=c11 -Wall -Wextra -O1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c oracles/test_x86_program_callee_abi.c -o build/test_x86_program_callee_abi.o
	for bound in 0 1; do \
	  flags=; if test $$bound = 1; then flags='-D__COMPCERT__ -DKPROG_X86_PROGRAM_EXPORT=1'; fi; \
	  $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    $$flags -include oracles/compcert_memory_host.h -include oracles/x86_program_environment_host.h \
	    -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
	    -c build/x86_program_profile.bpf.c -o build/x86_program_profile_host.o && \
	  $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    oracles/test_x86_program_profile_host.c build/x86_program_profile_host.o -o build/test_x86_program_profile_host && \
	  ./build/test_x86_program_profile_host || exit $$?; \
	done
	for frame in 200 376; do for adapter in 0 1; do \
	  flags=; if test $$adapter = 1; then flags=-D__COMPCERT__; fi; \
	  $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    $$flags -include oracles/compcert_memory_host.h \
	    -DPROFILE=$$frame -DKPROG_X86_PROGRAM_SOURCE=\"../build/x86_stack_profile_$$frame.bpf.c\" \
	    -DKPROG_X86_PROGRAM_ENTRY=x86_stack_profile_$${frame}_x86_sim_xdp \
	    -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
	    oracles/test_x86_producer_profile_host.c -o build/test_x86_producer_profile_host && \
	  ./build/test_x86_producer_profile_host || exit $$?; \
	done; done
	$(CC) -std=c11 -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src c/Arm64Entry.c oracles/test_arm64_entry_binding_host.c -o build/test_arm64_entry_binding_host
	./build/test_arm64_entry_binding_host
	$(CC) -std=c11 -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -D__COMPCERT__ -DADAPTER=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src c/Arm64Entry.c oracles/test_arm64_entry_binding_host.c -o build/test_arm64_entry_binding_host
	./build/test_arm64_entry_binding_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -D__COMPCERT__ -include oracles/compcert_memory_host.h -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Address.c -o build/arm64_address_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -D__COMPCERT__ -include oracles/compcert_memory_host.h -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Numeric.c -o build/arm64_numeric_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -D__COMPCERT__ -include oracles/compcert_memory_host.h -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Addressing.c -o build/arm64_addressing_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_context_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_context_host
	./build/test_arm64_context_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_memory_binding_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_memory_binding_host
	./build/test_arm64_memory_binding_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=1 -DDISPATCH=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_memory_binding_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_memory_binding_host
	./build/test_arm64_memory_binding_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_execute_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_execute_host
	./build/test_arm64_execute_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -D__COMPCERT__ -include oracles/compcert_memory_host.h -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Program.c -o build/arm64_program_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=1 -DPROGRAM=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_execute_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o build/arm64_program_binding.o -o build/test_arm64_execute_host
	./build/test_arm64_execute_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=1 -DPROGRAM=1 -DDISPATCH=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_memory_binding_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o build/arm64_program_binding.o -o build/test_arm64_memory_binding_host
	./build/test_arm64_memory_binding_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -D__COMPCERT__ -include oracles/compcert_memory_host.h -DKPROG_ARM64_PROGRAM_EXPORT=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_payload_profile_host.c build/arm64_program_binding.o build/arm64_numeric_binding.o -o build/test_arm64_payload_profile_host
	./build/test_arm64_payload_profile_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Addressing.c -o build/arm64_addressing_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_addressing_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_addressing_host
	./build/test_arm64_addressing_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=0 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_memory_binding_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_memory_binding_host
	./build/test_arm64_memory_binding_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=0 -DDISPATCH=1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_memory_binding_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_memory_binding_host
	./build/test_arm64_memory_binding_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_execute_host.c build/arm64_addressing_binding.o build/arm64_address_binding.o build/arm64_numeric_binding.o -o build/test_arm64_execute_host
	./build/test_arm64_execute_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -D__COMPCERT__ -include oracles/compcert_memory_host.h -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Access.c -o build/arm64_access_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=1 -I../../vendor/libbpf/include/uapi oracles/test_arm64_access_host.c build/arm64_access_binding.o -o build/test_arm64_access_host
	./build/test_arm64_access_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Access.c -o build/arm64_access_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DADAPTER=0 -I../../vendor/libbpf/include/uapi oracles/test_arm64_access_host.c build/arm64_access_binding.o -o build/test_arm64_access_host
	./build/test_arm64_access_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Stack.c -o build/arm64_stack_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_stack_binding_host.c build/arm64_stack_binding.o -o build/test_arm64_stack_binding_host
	./build/test_arm64_stack_binding_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/Arm64Address.c -o build/arm64_address_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_address_cache_host.c build/arm64_address_binding.o -o build/test_arm64_address_cache_host
	./build/test_arm64_address_cache_host
	for fixture in 1:0 7:-3 9:4 160:96 200:160 376:280; do \
	  $(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DPROFILE=$${fixture%:*} -DBIAS=$${fixture#*:} -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_arm64_storage_profile_host.c build/arm64_address_binding.o -o build/test_arm64_storage_profile_host && \
	  ./build/test_arm64_storage_profile_host || exit $$?; \
	done
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Pointer.c -o build/x86_pointer_binding.o
	for fixture in 1:0 7:0 9:0 64:0 200:0 376:0 64:1 200:1 376:1; do \
	  $(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -DPROFILE=$${fixture%:*} -DSCALAR_FACTS=$${fixture#*:} -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_storage_profile_host.c build/x86_pointer_binding.o -o build/test_x86_storage_profile_host && \
	  ./build/test_x86_storage_profile_host || exit $$?; \
	done
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_tagged_load_host.c build/x86_pointer_binding.o -o build/test_x86_tagged_load_host
	./build/test_x86_tagged_load_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_recovery_host.c build/x86_pointer_binding.o -o build/test_x86_recovery_host
	./build/test_x86_recovery_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_mov_selectors_host.c build/x86_pointer_binding.o -o build/test_x86_mov_selectors_host
	./build/test_x86_mov_selectors_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_read_src_host.c build/x86_pointer_binding.o -o build/test_x86_read_src_host
	./build/test_x86_read_src_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_stack_read_host.c build/x86_pointer_binding.o -o build/test_x86_stack_read_host
	./build/test_x86_stack_read_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_store_selectors_host.c build/x86_pointer_binding.o -o build/test_x86_store_selectors_host
	./build/test_x86_store_selectors_host
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Pointer.c -o build/x86_pointer_binding.o
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_tagged_load_host.c build/x86_pointer_binding.o -o build/test_x86_tagged_load_host
	./build/test_x86_tagged_load_host
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_recovery_host.c build/x86_pointer_binding.o -o build/test_x86_recovery_host
	./build/test_x86_recovery_host
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_mov_selectors_host.c build/x86_pointer_binding.o -o build/test_x86_mov_selectors_host
	./build/test_x86_mov_selectors_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_read_src_host.c build/x86_pointer_binding.o -o build/test_x86_read_src_host
	./build/test_x86_read_src_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_stack_read_host.c build/x86_pointer_binding.o -o build/test_x86_stack_read_host
	./build/test_x86_stack_read_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_store_selectors_host.c build/x86_pointer_binding.o -o build/test_x86_store_selectors_host
	./build/test_x86_store_selectors_host
	for program in 0 1; do \
	  flags=; if test $$program = 1; then flags=-DKPROG_X86_PROGRAM_EXPORT=1; fi; \
	  $(CC) -D__COMPCERT__ $$flags -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_inline_binding_host.c -o build/test_x86_inline_binding_host && \
	  ./build/test_x86_inline_binding_host || exit $$?; \
	done
	for mode in 0:0 1:0 1:1; do \
	  flags=; if test $${mode#*:} = 1; then flags=-D__COMPCERT__; fi; \
	  $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    -DINLINE=$${mode%:*} $$flags -include oracles/compcert_memory_host.h \
	    -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
	    oracles/test_x86_incdec_host.c -o build/test_x86_incdec_host && \
	  ./build/test_x86_incdec_host || exit $$?; \
	done
	$(CC) -std=c11 -Wall -Wextra -O1 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c oracles/test_x86_helper_abi.c -o build/test_x86_helper_abi.o
	for adapter in 0 1; do \
	  flags=; if test $$adapter = 1; then flags=-D__COMPCERT__; fi; \
	  for source in x86_pointer:X86Pointer x86_helpers:X86Helpers; do \
	    $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	      $$flags -include oracles/compcert_memory_host.h -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
	      -c c/$${source#*:}.c -o build/$${source%:*}_binding.o || exit $$?; \
	  done; \
	  $(CC) -std=c11 -Wall -Wextra -O1 -fsanitize=undefined -fno-sanitize-recover=undefined \
	    -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_helpers_binding_host.c \
	    build/x86_helpers_binding.o build/x86_pointer_binding.o -o build/test_x86_helpers_binding_host && \
	  ./build/test_x86_helpers_binding_host || exit $$?; \
	done
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Pointer.c -o build/x86_pointer_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Memory.c -o build/x86_memory_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_memory_read_host.c build/x86_memory_binding.o build/x86_pointer_binding.o -o build/test_x86_memory_read_host
	./build/test_x86_memory_read_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Context.c -o build/x86_context_binding.o
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_context_host.c build/x86_context_binding.o build/x86_memory_binding.o build/x86_pointer_binding.o -o build/test_x86_context_host
	./build/test_x86_context_host
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Pointer.c -o build/x86_pointer_binding.o
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Memory.c -o build/x86_memory_binding.o
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_memory_read_host.c build/x86_memory_binding.o build/x86_pointer_binding.o -o build/test_x86_memory_read_host
	./build/test_x86_memory_read_host
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -c c/X86Context.c -o build/x86_context_binding.o
	$(CC) -D__COMPCERT__ -include oracles/compcert_memory_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src oracles/test_x86_context_host.c build/x86_context_binding.o build/x86_memory_binding.o build/x86_pointer_binding.o -o build/test_x86_context_host
	./build/test_x86_context_host
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_inline_compile.bpf.c -o build/x86_inline_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_helpers_compile.bpf.c -o build/x86_helpers_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c build/x86_program_profile.bpf.c -o build/x86_program_profile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_context_compile.bpf.c -o build/x86_context_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_stack_read_compile.bpf.c -o build/x86_stack_read_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_memory_read_compile.bpf.c -o build/x86_memory_read_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_xmm0_compile.bpf.c -o build/x86_xmm0_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_conditional_compile.bpf.c -o build/x86_conditional_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/x86_store_selectors_compile.bpf.c -o build/x86_store_selectors_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/arm64_address_compile.bpf.c -o build/arm64_address_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/arm64_stack_compile.bpf.c -o build/arm64_stack_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/arm64_access_compile.bpf.c -o build/arm64_access_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/arm64_addressing_compile.bpf.c -o build/arm64_addressing_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/arm64_execute_compile.bpf.c -o build/arm64_execute_compile.bpf.o
	../stock-path/bin/clang -g -O2 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c oracles/arm64_context_compile.bpf.c -o build/arm64_context_compile.bpf.o
