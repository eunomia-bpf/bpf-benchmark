ARM64_HOST_ENV := -include oracles/arm64_entry_environment_host.h -DKPROG_TEST_EXCLUSIVE_FAILURE=0 -include oracles/arm64_exclusive_choice_host.h
.PHONY: check

check:
	install -d build
	python3 tools/check_macro_hygiene.py
	python3 ../arm64/generate_sim_dispatch.py --check
	python3 tools/check_helper_idents.py
	python3 tools/check_jcc_opcodes.py
	python3 tools/check_lookup_ambiguity.py
	python3 tools/check_oracle_composition.py
	python3 tools/check_dual_emit_coverage.py
	python3 tools/mutate_contracts.py --check
	python3 tools/check_dispatch_model.py
	python3 tools/generate_ptr_add_spec.py --check
	python3 tools/generate_abi_load_spec.py --check
	python3 tools/generate_arm64_width_spec.py --check
	python3 tools/generate_arm64_flags_spec.py --check
	python3 tools/generate_arm64_decode_spec.py --check
	python3 tools/generate_arm64_alu_result_spec.py --check
	python3 tools/generate_arm64_alu_handler_spec.py --check
	python3 tools/generate_arm64_alu_operand_spec.py --check
	python3 tools/generate_arm64_alu_operand_select_spec.py --check
	python3 tools/generate_arm64_flag_operand_spec.py --check
	python3 tools/generate_arm64_flag_handler_spec.py --check
	python3 tools/generate_arm64_logic_flag_handler_spec.py --check
	python3 tools/generate_arm64_ccmp_handler_spec.py --check
	python3 tools/generate_arm64_ccmp_decode_spec.py --check
	python3 tools/generate_arm64_dispatch_family_spec.py --check
	python3 tools/generate_arm64_dispatch_singleton_spec.py --check
	python3 tools/generate_arm64_imm_operand_spec.py --check
	python3 tools/generate_arm64_mod_spec.py --check
	python3 tools/generate_arm64_bitfield_spec.py --check
	python3 tools/generate_arm64_mul_spec.py --check
	python3 tools/generate_arm64_extrev_spec.py --check
	python3 tools/generate_arm64_csel_spec.py --check
	python3 tools/generate_arm64_csel_ptr_spec.py --check
	python3 tools/generate_arm64_movk_spec.py --check
	python3 tools/generate_arm64_shift_spec.py --check
	python3 tools/generate_arm64_reduction_spec.py --check
	python3 tools/generate_arm64_unary_spec.py --check
	python3 tools/generate_arm64_cneg_spec.py --check
	python3 tools/generate_arm64_orn_spec.py --check
	python3 tools/generate_arm64_adrp_spec.py --check
	python3 tools/generate_arm64_stlxr_spec.py --check
	python3 tools/generate_arm64_mov_spec.py --check
	python3 tools/generate_arm64_ldrsx_spec.py --check
	python3 tools/generate_arm64_ldrsx_op_spec.py --check
	python3 tools/generate_arm64_load_tag_spec.py --check
	python3 tools/generate_arm64_pair_load_tag_spec.py --check
	python3 tools/generate_arm64_mem_offset_spec.py --check
	python3 tools/generate_arm64_mem_index_spec.py --check
	python3 tools/generate_arm64_reg_presence_spec.py --check
	python3 tools/generate_arm64_reg_dispatch_spec.py --check
	python3 tools/generate_control_flow_trace_spec.py --check
	python3 tools/generate_arm64_fmov_spec.py --check
	python3 tools/generate_arm64_fmov_dest_spec.py --check
	python3 tools/generate_arm64_load_bytes_spec.py --check
	python3 tools/generate_arm64_store_bytes_spec.py --check
	python3 tools/generate_arm64_byte_lane_spec.py --check
	python3 tools/generate_arm64_mem_dispatch_spec.py --check
	python3 tools/generate_arm64_stack_tag_spec.py --check
	python3 tools/generate_arm64_stack_arm_spec.py --check
	python3 tools/generate_arm64_dq_mem_spec.py --check
	python3 tools/generate_arm64_pair_mem_spec.py --check
	python3 tools/generate_arm64_mem_prepost_spec.py --check
	python3 tools/generate_arm64_vreg_spec.py --check
	python3 tools/generate_arm64_stack_arena_spec.py --check
	python3 tools/generate_arm64_stack_index_spec.py --check
	python3 tools/generate_arm64_aux_spec.py --check
	python3 tools/generate_arm64_branch_spec.py --check
	python3 tools/generate_arm64_branch_emit_spec.py --check
	python3 tools/generate_arm64_cond_spec.py --check
	python3 tools/generate_arm64_cc_decode_spec.py --check
	python3 tools/generate_arm64_helper_idents_spec.py --check
	python3 tools/generate_arm64_mem_write_arm_spec.py --check
	python3 tools/generate_arm64_stack_write_lanes_spec.py --check
	python3 tools/generate_arm64_stack_write_tag_action_spec.py --check
	python3 tools/generate_arm64_stack_read_tag_source_spec.py --check
	python3 tools/generate_arm64_helper_arg_ptr_spec.py --check
	python3 tools/generate_arm64_mem_base_src_spec.py --check
	python3 tools/generate_arm64_mem_index_value_spec.py --check
	python3 tools/generate_arm64_dq_mem_extra_spec.py --check
	python3 tools/generate_arm64_vreg_field_spec.py --check
	python3 tools/generate_arm64_write_arm_spec.py --check
	python3 tools/generate_x86_cond_spec.py --check
	python3 tools/generate_x86_full_condition_spec.py --check
	python3 tools/generate_x86_cc_decode_spec.py --check
	python3 tools/generate_x86_logic_flags_spec.py --check
	python3 tools/generate_x86_width_spec.py --check
	python3 tools/generate_x86_immediate_spec.py --check
	python3 tools/generate_x86_alu_decode_spec.py --check
	python3 tools/generate_x86_not_spec.py --check
	python3 tools/generate_x86_shift_count_spec.py --check
	python3 tools/generate_x86_stack_index_spec.py --check
	python3 tools/generate_x86_stack_arena_spec.py --check
	python3 tools/generate_x86_shift_result_spec.py --check
	python3 tools/generate_x86_alu_result_spec.py --check
	python3 tools/generate_x86_bswap_spec.py --check
	python3 tools/generate_x86_signed_spec.py --check
	python3 tools/generate_x86_popcount_spec.py --check
	python3 tools/generate_x86_bitops_spec.py --check
	python3 tools/generate_x86_doubleshift_spec.py --check
	python3 tools/generate_x86_shift_flags_spec.py --check
	python3 tools/generate_x86_reg_write_spec.py --check
	python3 tools/generate_x86_mem_offset_spec.py --check
	python3 tools/generate_x86_reg_read_spec.py --check
	python3 tools/generate_x86_reg_lane_aux_spec.py --check
	python3 tools/generate_x86_sub_flags_spec.py --check
	python3 tools/generate_x86_add_flags_spec.py --check
	python3 tools/generate_x86_aux_flags_spec.py --check
	python3 tools/generate_x86_sbb_result_spec.py --check
	python3 tools/generate_x86_sbb_flags_spec.py --check
	python3 tools/generate_x86_adc_spec.py --check
	python3 tools/generate_x86_imul_flags_spec.py --check
	python3 tools/generate_x86_mem_access_spec.py --check
	python3 tools/generate_x86_mem_dispatch_spec.py --check
	python3 tools/generate_x86_mov_load_spec.py --check
	python3 tools/generate_x86_store_spec.py --check
	python3 tools/generate_x86_setcc_spec.py --check
	python3 tools/generate_x86_setcc_mem_spec.py --check
	python3 tools/generate_x86_cmov_spec.py --check
	python3 tools/generate_x86_movbe_spec.py --check
	python3 tools/generate_x86_ptr_write_spec.py --check
	python3 tools/generate_x86_xmm0_spec.py --check
	python3 tools/generate_x86_branch_emit_spec.py --check
	python3 tools/generate_x86_callmem_spec.py --check
	python3 tools/generate_x86_pushpop_spec.py --check
	python3 tools/generate_x86_rep_movs_spec.py --check
	python3 tools/generate_x86_andn_spec.py --check
	python3 tools/generate_x86_bzhi_spec.py --check
	python3 tools/generate_x86_bt_spec.py --check
	python3 tools/generate_x86_cmpop_spec.py --check
	python3 tools/generate_x86_mem_aux_spec.py --check
	python3 tools/generate_x86_mem_index_spec.py --check
	python3 tools/generate_x86_reg_presence_spec.py --check
	python3 tools/generate_x86_reg_dispatch_spec.py --check
	python3 tools/generate_x86_helper_dispatch_spec.py --check
	python3 tools/generate_x86_xchg_spec.py --check
	python3 tools/generate_x86_div_spec.py --check
	python3 tools/generate_x86_doubleshift_arm_spec.py --check
	python3 tools/generate_x86_popcnt_flags_spec.py --check
	python3 tools/generate_x86_bzhi_flags_spec.py --check
	python3 tools/generate_x86_movx_shape_spec.py --check
	python3 tools/generate_x86_mov_reg_arm_spec.py --check
	python3 tools/generate_x86_stack_arm_spec.py --check
	python3 tools/generate_x86_write_width_arm_spec.py --check
	python3 tools/generate_x86_stack_write_lanes_spec.py --check
	python3 tools/generate_x86_mulx_arm_spec.py --check
	python3 tools/generate_x86_opcode_spec.py --check
	python3 tools/generate_x86_specialization_spec.py --check
	python3 tools/generate_x86_alu_flag_arm_spec.py --check
	python3 tools/generate_x86_dispatch_family_spec.py --check
	python3 tools/generate_x86_dispatch_singleton_spec.py --check
	python3 tools/generate_helper_oracle.py --check
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
	python3 tools/check_x86_flag_definedness.py
	python3 tools/check_reference_x86_condition.py
	python3 tools/check_reference_x86_path.py
	python3 tools/check_x86_memory_widths.py
	python3 tools/check_arm64_pointer_access.py
	python3 tools/check_reference_arm64.py
	python3 tools/check_reference_arm64_addressed_memory.py
	python3 tools/check_reference_exclusive.py
	python3 tools/check_no_sorry.py --check
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_six_flags_host.c -o build/test_x86_six_flags_host
	./build/test_x86_six_flags_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. -I../x86 -I../../vendor/libbpf/src oracles/test_x86_full_condition_host.c -o build/test_x86_full_condition_host
	./build/test_x86_full_condition_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_cond_host.c -o build/test_arm64_cond_host
	./build/test_arm64_cond_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_branch_emit_host.c -o build/test_x86_branch_emit_host
	./build/test_x86_branch_emit_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_branch_emit_route_host.c -o build/test_x86_branch_emit_route_host
	./build/test_x86_branch_emit_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/width_fallback_host.c -o build/width_fallback_host
	./build/width_fallback_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_alu_result_arm_host.c -o build/test_x86_alu_result_arm_host
	./build/test_x86_alu_result_arm_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_alu_result_route_host.c -o build/test_x86_alu_result_route_host
	./build/test_x86_alu_result_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_alu_mem_result_route_host.c -o build/test_x86_alu_mem_result_route_host
	./build/test_x86_alu_mem_result_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_shiftx_rorx_route_host.c -o build/test_x86_shiftx_rorx_route_host
	./build/test_x86_shiftx_rorx_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_movx_route_host.c -o build/test_x86_movx_route_host
	./build/test_x86_movx_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_imul_route_host.c -o build/test_x86_imul_route_host
	./build/test_x86_imul_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_imul_flags_host.c -o build/test_imul_flags_host
	./build/test_imul_flags_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_lea_route_host.c -o build/test_x86_lea_route_host
	./build/test_x86_lea_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_mov_route_host.c -o build/test_x86_mov_route_host
	./build/test_x86_mov_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_bswap_route_host.c -o build/test_x86_bswap_route_host
	./build/test_x86_bswap_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_alu_decode_host.c -o build/test_x86_alu_decode_host
	./build/test_x86_alu_decode_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_opcode_host.c -o build/test_x86_opcode_host
	./build/test_x86_opcode_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 oracles/test_x86_specialization_chain_host.c -o build/test_x86_specialization_chain_host
	./build/test_x86_specialization_chain_host
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
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_shift_flags_route_host.c -o build/test_x86_shift_flags_route_host
	./build/test_x86_shift_flags_route_host
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
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_mem_offset_route_host.c -o build/test_x86_mem_offset_route_host
	./build/test_x86_mem_offset_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_index_host.c -o build/test_x86_mem_index_host
	./build/test_x86_mem_index_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_mem_index_route_host.c -o build/test_x86_mem_index_route_host
	./build/test_x86_mem_index_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_reg_dispatch_host.c -o build/test_x86_reg_dispatch_host
	./build/test_x86_reg_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_reg_dispatch_route_host.c -o build/test_x86_reg_dispatch_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_helper_dispatch_host.c -o build/test_x86_helper_dispatch_host
	./build/test_x86_helper_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_helper_dispatch_route_host.c -o build/test_x86_helper_dispatch_route_host
	./build/test_x86_helper_dispatch_route_host
	python3 tools/check_helper_errors.py --cc "$(CC)"
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/x86_route_host.c -o build/x86_route_host
	./build/x86_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/btmem_index_route_host.c -o build/btmem_index_route_host
	./build/btmem_index_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/value_route_host.c -o build/value_route_host
	./build/value_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_xchg_host.c -o build/test_x86_xchg_host
	./build/test_x86_xchg_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_xchg_route_host.c -o build/test_x86_xchg_route_host
	./build/test_x86_xchg_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mulx_arm_host.c -o build/test_x86_mulx_arm_host
	./build/test_x86_mulx_arm_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_mulx_arm_route_host.c -o build/test_x86_mulx_arm_route_host
	./build/test_x86_mulx_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_div_host.c -o build/test_x86_div_host
	./build/test_x86_div_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_div_route_host.c -o build/test_x86_div_route_host
	./build/test_x86_div_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_doubleshift_arm_host.c -o build/test_x86_doubleshift_arm_host
	./build/test_x86_doubleshift_arm_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_doubleshift_arm_route_host.c -o build/test_x86_doubleshift_arm_route_host
	./build/test_x86_doubleshift_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_popcnt_flags_host.c -o build/test_x86_popcnt_flags_host
	./build/test_x86_popcnt_flags_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_popcnt_flags_route_host.c -o build/test_x86_popcnt_flags_route_host
	./build/test_x86_popcnt_flags_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bzhi_flags_host.c -o build/test_x86_bzhi_flags_host
	./build/test_x86_bzhi_flags_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_bzhi_flags_route_host.c -o build/test_x86_bzhi_flags_route_host
	./build/test_x86_bzhi_flags_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_movx_shape_host.c -o build/test_x86_movx_shape_host
	./build/test_x86_movx_shape_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_movx_shape_route_host.c -o build/test_x86_movx_shape_route_host
	./build/test_x86_movx_shape_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mov_reg_arm_host.c -o build/test_x86_mov_reg_arm_host
	./build/test_x86_mov_reg_arm_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_mov_reg_arm_route_host.c -o build/test_x86_mov_reg_arm_route_host
	./build/test_x86_mov_reg_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_stack_arm_host.c -o build/test_x86_stack_arm_host
	./build/test_x86_stack_arm_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_stack_arm_route_host.c -o build/test_x86_stack_arm_route_host
	./build/test_x86_stack_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_write_width_arm_host.c -o build/test_x86_write_width_arm_host
	./build/test_x86_write_width_arm_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_write_width_arm_route_host.c -o build/test_x86_write_width_arm_route_host
	./build/test_x86_write_width_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_stack_write_lanes_host.c -o build/test_x86_stack_write_lanes_host
	./build/test_x86_stack_write_lanes_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_stack_write_lanes_route_host.c -o build/test_x86_stack_write_lanes_route_host
	./build/test_x86_stack_write_lanes_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_alu_flag_arm_host.c -o build/test_x86_alu_flag_arm_host
	./build/test_x86_alu_flag_arm_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_alu_flag_arm_route_host.c -o build/test_x86_alu_flag_arm_route_host
	./build/test_x86_alu_flag_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_dispatch_family_host.c -o build/test_x86_dispatch_family_host
	./build/test_x86_dispatch_family_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_dispatch_family_route_host.c -o build/test_x86_dispatch_family_route_host
	./build/test_x86_dispatch_family_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_dispatch_singleton_host.c -o build/test_x86_dispatch_singleton_host
	./build/test_x86_dispatch_singleton_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_dispatch_singleton_route_host.c -o build/test_x86_dispatch_singleton_route_host
	./build/test_x86_dispatch_singleton_route_host
	./build/test_x86_reg_dispatch_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_reg_presence_host.c -o build/test_x86_reg_presence_host
	./build/test_x86_reg_presence_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_reg_presence_route_host.c -o build/test_x86_reg_presence_route_host
	./build/test_x86_reg_presence_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_width_effective_host.c -o build/test_x86_width_effective_host
	./build/test_x86_width_effective_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_width_effective_route_host.c -o build/test_x86_width_effective_route_host
	./build/test_x86_width_effective_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_lea_handler_host.c -o build/test_x86_lea_handler_host
	./build/test_x86_lea_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mov_handler_host.c -o build/test_x86_mov_handler_host
	./build/test_x86_mov_handler_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_movx_reg_host.c -o build/test_x86_movx_reg_host
	./build/test_x86_movx_reg_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mem_read_dispatch_host.c -o build/test_x86_mem_read_dispatch_host
	./build/test_x86_mem_read_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_mem_dispatch_route_host.c -o build/test_x86_mem_dispatch_route_host
	./build/test_x86_mem_dispatch_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mov_load_host.c -o build/test_x86_mov_load_host
	./build/test_x86_mov_load_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_mov_load_route_host.c -o build/test_x86_mov_load_route_host
	./build/test_x86_mov_load_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_store_host.c -o build/test_x86_store_host
	./build/test_x86_store_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_store_route_host.c -o build/test_x86_store_route_host
	./build/test_x86_store_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_setcc_host.c -o build/test_x86_setcc_host
	./build/test_x86_setcc_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_setcc_route_host.c -o build/test_x86_setcc_route_host
	./build/test_x86_setcc_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_cc_decode_host.c -o build/test_x86_cc_decode_host
	./build/test_x86_cc_decode_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_cc_decode_host.c -o build/test_arm64_cc_decode_host
	./build/test_arm64_cc_decode_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_helper_idents_host.c -o build/test_arm64_helper_idents_host
	./build/test_arm64_helper_idents_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_setcc_mem_host.c -o build/test_x86_setcc_mem_host
	./build/test_x86_setcc_mem_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_setcc_mem_route_host.c -o build/test_x86_setcc_mem_route_host
	./build/test_x86_setcc_mem_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_cmov_host.c -o build/test_x86_cmov_host
	./build/test_x86_cmov_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/cmov_step_route_host.c -o build/cmov_step_route_host
	./build/cmov_step_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_movbe_host.c -o build/test_x86_movbe_host
	./build/test_x86_movbe_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_movbe_route_host.c -o build/test_x86_movbe_route_host
	./build/test_x86_movbe_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_mov_load_map_ptr_host.c -o build/test_x86_mov_load_map_ptr_host
	./build/test_x86_mov_load_map_ptr_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_xmm0_host.c -o build/test_x86_xmm0_host
	./build/test_x86_xmm0_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_xmm0_route_host.c -o build/test_x86_xmm0_route_host
	./build/test_x86_xmm0_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_callmem_host.c -o build/test_x86_callmem_host
	./build/test_x86_callmem_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_callmem_route_host.c -o build/test_x86_callmem_route_host
	./build/test_x86_callmem_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_pushpop_host.c -o build/test_x86_pushpop_host
	./build/test_x86_pushpop_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_pushpop_route_host.c -o build/test_x86_pushpop_route_host
	./build/test_x86_pushpop_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_rep_movs_host.c -o build/test_x86_rep_movs_host
	./build/test_x86_rep_movs_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_rep_movs_route_host.c -o build/test_x86_rep_movs_route_host
	./build/test_x86_rep_movs_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_andn_host.c -o build/test_x86_andn_host
	./build/test_x86_andn_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_andn_route_host.c -o build/test_x86_andn_route_host
	./build/test_x86_andn_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bzhi_host.c -o build/test_x86_bzhi_host
	./build/test_x86_bzhi_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_bzhi_route_host.c -o build/test_x86_bzhi_route_host
	./build/test_x86_bzhi_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_bt_host.c -o build/test_x86_bt_host
	./build/test_x86_bt_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_bt_route_host.c -o build/test_x86_bt_route_host
	./build/test_x86_bt_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_x86_cmpop_host.c -o build/test_x86_cmpop_host
	./build/test_x86_cmpop_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_cmpop_route_host.c -o build/test_x86_cmpop_route_host
	./build/test_x86_cmpop_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_cmp_mem_route_host.c -o build/test_x86_cmp_mem_route_host
	./build/test_x86_cmp_mem_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_cmov_route_host.c -o build/test_x86_cmov_route_host
	./build/test_x86_cmov_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/cross_isa_tag_host.c -o build/cross_isa_tag_host
	./build/cross_isa_tag_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/cross_isa_differential_host.c -o build/cross_isa_differential_host
	./build/cross_isa_differential_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_width_host.c -o build/test_arm64_width_host
	./build/test_arm64_width_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_width_effective_host.c -o build/test_arm64_width_effective_host
	./build/test_arm64_width_effective_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_width_effective_route_host.c -o build/test_arm64_width_effective_route_host
	./build/test_arm64_width_effective_route_host
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
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_imm_operand_route_host.c -o build/test_arm64_imm_operand_route_host
	./build/test_arm64_imm_operand_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_alu_operand_select_host.c -o build/test_arm64_alu_operand_select_host
	./build/test_arm64_alu_operand_select_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_alu_operand_select_route_host.c -o build/test_arm64_alu_operand_select_route_host
	./build/test_arm64_alu_operand_select_route_host
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
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_dispatch_family_route_host.c -o build/test_arm64_dispatch_family_route_host
	./build/test_arm64_dispatch_family_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_dispatch_singleton_host.c -o build/test_arm64_dispatch_singleton_host
	./build/test_arm64_dispatch_singleton_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_dispatch_singleton_route_host.c -o build/test_arm64_dispatch_singleton_route_host
	./build/test_arm64_dispatch_singleton_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mod_host.c -o build/test_arm64_mod_host
	./build/test_arm64_mod_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_bitfield_host.c -o build/test_arm64_bitfield_host
	./build/test_arm64_bitfield_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. oracles/test_arm64_mul_host.c -o build/test_arm64_mul_host
	./build/test_arm64_mul_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mul_route_host.c -o build/test_arm64_mul_route_host
	./build/test_arm64_mul_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_flag_route_host.c -o build/test_arm64_flag_route_host
	./build/test_arm64_flag_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_csel_route_host.c -o build/test_arm64_csel_route_host
	./build/test_arm64_csel_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mul_wide_host.c -o build/test_arm64_mul_wide_host
	./build/test_arm64_mul_wide_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_imul_flags_wide_host.c -o build/test_x86_imul_flags_wide_host
	./build/test_x86_imul_flags_wide_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/mul_route_host.c -o build/mut_mulroute
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
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/a64_route_host.c -o build/a64_route_host
	./build/a64_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_control_flow_trace_host.c -o build/test_control_flow_trace_host
	./build/test_control_flow_trace_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../x86 -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_control_flow_trace_route_host.c -o build/test_control_flow_trace_route_host
	./build/test_control_flow_trace_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_movk_host.c -o build/test_arm64_movk_host
	./build/test_arm64_movk_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_shift_host.c -o build/test_arm64_shift_host
	./build/test_arm64_shift_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_reduction_host.c -o build/test_arm64_reduction_host
	./build/test_arm64_reduction_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/reduction_route_host.c -o build/reduction_route_host
	./build/reduction_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_unary_host.c -o build/test_arm64_unary_host
	./build/test_arm64_unary_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_unary_route_host.c -o build/test_arm64_unary_route_host
	./build/test_arm64_unary_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_cneg_route_host.c -o build/test_arm64_cneg_route_host
	./build/test_arm64_cneg_route_host
	$(CC) -include oracles/arm64_entry_environment_host.h -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_stlxr_route_host.c -o build/test_arm64_stlxr_route_host
	./build/test_arm64_stlxr_route_host
	$(CC) -include oracles/arm64_entry_environment_host.h -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=all -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_memory_tokens_host.c -o build/test_arm64_memory_tokens_host
	./build/test_arm64_memory_tokens_host
	$(CC) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=all -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_return_token_host.c -o build/test_arm64_return_token_host
	./build/test_arm64_return_token_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_reduction_route_host.c -o build/test_arm64_reduction_route_host
	./build/test_arm64_reduction_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_adrp_route_host.c -o build/test_arm64_adrp_route_host
	./build/test_arm64_adrp_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_extrev_route_host.c -o build/test_arm64_extrev_route_host
	./build/test_arm64_extrev_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_orn_route_host.c -o build/test_arm64_orn_route_host
	./build/test_arm64_orn_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_branch_emit_route_host.c -o build/test_arm64_branch_emit_route_host
	./build/test_arm64_branch_emit_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_cbz_tbz_route_host.c -o build/test_arm64_cbz_tbz_route_host
	./build/test_arm64_cbz_tbz_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_call_ret_route_host.c -o build/test_arm64_call_ret_route_host
	./build/test_arm64_call_ret_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_call_ret_route_host.c -o build/test_x86_call_ret_route_host
	./build/test_x86_call_ret_route_host
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
	$(CC) -include oracles/arm64_entry_environment_host.h -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/stlxr_route_host.c -o build/stlxr_route_host
	./build/stlxr_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mov_host.c -o build/test_arm64_mov_host
	./build/test_arm64_mov_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_ldrsx_host.c -o build/test_arm64_ldrsx_host
	./build/test_arm64_ldrsx_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/ldrsx_route_host.c -o build/ldrsx_route_host
	./build/ldrsx_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_ldrsx_op_host.c -o build/test_arm64_ldrsx_op_host
	./build/test_arm64_ldrsx_op_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_ldrsx_op_route_host.c -o build/test_arm64_ldrsx_op_route_host
	./build/test_arm64_ldrsx_op_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_load_tag_host.c -o build/test_arm64_load_tag_host
	./build/test_arm64_load_tag_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_pair_load_tag_host.c -o build/test_arm64_pair_load_tag_host
	./build/test_arm64_pair_load_tag_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_offset_host.c -o build/test_arm64_mem_offset_host
	./build/test_arm64_mem_offset_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_index_host.c -o build/test_arm64_mem_index_host
	./build/test_arm64_mem_index_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mem_index_route_host.c -o build/test_arm64_mem_index_route_host
	./build/test_arm64_mem_index_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_reg_presence_host.c -o build/test_arm64_reg_presence_host
	./build/test_arm64_reg_presence_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_reg_presence_route_host.c -o build/test_arm64_reg_presence_route_host
	./build/test_arm64_reg_presence_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. oracles/test_arm64_reg_dispatch_host.c -o build/test_arm64_reg_dispatch_host
	./build/test_arm64_reg_dispatch_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_reg_dispatch_route_host.c -o build/test_arm64_reg_dispatch_route_host
	./build/test_arm64_reg_dispatch_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_fmov_host.c -o build/test_arm64_fmov_host
	./build/test_arm64_fmov_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_fmov_dest_host.c -o build/test_arm64_fmov_dest_host
	./build/test_arm64_fmov_dest_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_load_bytes_host.c -o build/test_arm64_load_bytes_host
	./build/test_arm64_load_bytes_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_store_bytes_host.c -o build/test_arm64_store_bytes_host
	./build/test_arm64_store_bytes_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_store_bytes_route_host.c -o build/test_arm64_store_bytes_route_host
	./build/test_arm64_store_bytes_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_byte_lane_host.c -o build/test_arm64_byte_lane_host
	./build/test_arm64_byte_lane_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_dispatch_host.c -o build/test_arm64_mem_dispatch_host
	./build/test_arm64_mem_dispatch_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_write_arm_host.c -o build/test_arm64_mem_write_arm_host
	./build/test_arm64_mem_write_arm_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mem_write_arm_route_host.c -o build/test_arm64_mem_write_arm_route_host
	./build/test_arm64_mem_write_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_tag_host.c -o build/test_arm64_stack_tag_host
	./build/test_arm64_stack_tag_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_arm_host.c -o build/test_arm64_stack_arm_host
	./build/test_arm64_stack_arm_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_stack_arm_route_host.c -o build/test_arm64_stack_arm_route_host
	./build/test_arm64_stack_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_write_lanes_host.c -o build/test_arm64_stack_write_lanes_host
	./build/test_arm64_stack_write_lanes_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_stack_write_lanes_route_host.c -o build/test_arm64_stack_write_lanes_route_host
	./build/test_arm64_stack_write_lanes_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_write_tag_action_host.c -o build/test_arm64_stack_write_tag_action_host
	./build/test_arm64_stack_write_tag_action_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_stack_write_tag_action_route_host.c -o build/test_arm64_stack_write_tag_action_route_host
	./build/test_arm64_stack_write_tag_action_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_read_tag_source_host.c -o build/test_arm64_stack_read_tag_source_host
	./build/test_arm64_stack_read_tag_source_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_stack_read_tag_source_route_host.c -o build/test_arm64_stack_read_tag_source_route_host
	./build/test_arm64_stack_read_tag_source_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_helper_arg_ptr_host.c -o build/test_arm64_helper_arg_ptr_host
	./build/test_arm64_helper_arg_ptr_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_helper_arg_ptr_route_host.c -o build/test_arm64_helper_arg_ptr_route_host
	./build/test_arm64_helper_arg_ptr_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/helper_route_host.c -o build/helper_route_host
	./build/helper_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_base_src_host.c -o build/test_arm64_mem_base_src_host
	./build/test_arm64_mem_base_src_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mem_base_src_route_host.c -o build/test_arm64_mem_base_src_route_host
	./build/test_arm64_mem_base_src_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_index_value_host.c -o build/test_arm64_mem_index_value_host
	./build/test_arm64_mem_index_value_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mem_index_value_route_host.c -o build/test_arm64_mem_index_value_route_host
	./build/test_arm64_mem_index_value_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_dq_mem_extra_host.c -o build/test_arm64_dq_mem_extra_host
	./build/test_arm64_dq_mem_extra_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_dq_mem_extra_route_host.c -o build/test_arm64_dq_mem_extra_route_host
	./build/test_arm64_dq_mem_extra_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_vreg_field_host.c -o build/test_arm64_vreg_field_host
	./build/test_arm64_vreg_field_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_vreg_field_route_host.c -o build/test_arm64_vreg_field_route_host
	./build/test_arm64_vreg_field_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_write_arm_host.c -o build/test_arm64_write_arm_host
	./build/test_arm64_write_arm_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_write_arm_route_host.c -o build/test_arm64_write_arm_route_host
	./build/test_arm64_write_arm_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_dq_mem_host.c -o build/test_arm64_dq_mem_host
	./build/test_arm64_dq_mem_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_dq_mem_route_host.c -o build/test_arm64_dq_mem_route_host
	./build/test_arm64_dq_mem_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_pair_mem_host.c -o build/test_arm64_pair_mem_host
	./build/test_arm64_pair_mem_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_pair_mem_route_host.c -o build/test_arm64_pair_mem_route_host
	./build/test_arm64_pair_mem_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/pair_route_host.c -o build/pair_route_host
	./build/pair_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/fmov_route_host.c -o build/fmov_route_host
	./build/fmov_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/ccmp_decode_route_host.c -o build/ccmp_decode_route_host
	./build/ccmp_decode_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/flag_route_host.c -o build/flag_route_host
	./build/flag_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_mem_prepost_host.c -o build/test_arm64_mem_prepost_host
	./build/test_arm64_mem_prepost_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_mem_prepost_route_host.c -o build/test_arm64_mem_prepost_route_host
	./build/test_arm64_mem_prepost_route_host
	$(CC) -Wall -Wextra -O2 -I. oracles/test_arm64_vreg_host.c -o build/test_arm64_vreg_host
	./build/test_arm64_vreg_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_vreg_route_host.c -o build/test_arm64_vreg_route_host
	./build/test_arm64_vreg_route_host
	$(CC) -Wall -Wextra -O2 -I. -I../arm64 oracles/test_arm64_aux_host.c -o build/test_arm64_aux_host
	./build/test_arm64_aux_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_aux_route_host.c -o build/test_arm64_aux_route_host
	./build/test_arm64_aux_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_arena_host.c -o build/test_arm64_stack_arena_host
	./build/test_arm64_stack_arena_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. oracles/test_arm64_stack_index_host.c -o build/test_arm64_stack_index_host
	./build/test_arm64_stack_index_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_stack_arena_route_host.c -o build/test_arm64_stack_arena_route_host
	./build/test_arm64_stack_arena_route_host
	$(CC) $(ARM64_HOST_ENV) -Wall -Wextra -O2 -I. -I../arm64 oracles/test_arm64_decode_host.c -o build/test_arm64_decode_host
	./build/test_arm64_decode_host
	$(MAKE) -C ../tv native-link-arm-percpu-check
