.PHONY: check

check:
	install -d build
	python3 generate_ptr_add_spec.py --check
	python3 generate_abi_load_spec.py --check
	python3 generate_arm64_width_spec.py --check
	python3 generate_arm64_flags_spec.py --check
	python3 generate_arm64_decode_spec.py --check
	python3 generate_arm64_alu_result_spec.py --check
	python3 generate_arm64_alu_handler_spec.py --check
	python3 generate_arm64_alu_operand_spec.py --check
	python3 generate_arm64_flag_handler_spec.py --check
	python3 generate_arm64_logic_flag_handler_spec.py --check
	python3 generate_arm64_ccmp_handler_spec.py --check
	python3 generate_arm64_mod_spec.py --check
	python3 generate_arm64_bitfield_spec.py --check
	python3 generate_arm64_mul_spec.py --check
	python3 generate_arm64_extrev_spec.py --check
	python3 generate_arm64_csel_spec.py --check
	python3 generate_arm64_movk_spec.py --check
	python3 generate_arm64_shift_spec.py --check
	python3 generate_arm64_reduction_spec.py --check
	python3 generate_arm64_mem_offset_spec.py --check
	python3 generate_arm64_fmov_spec.py --check
	python3 generate_arm64_load_bytes_spec.py --check
	python3 generate_arm64_byte_lane_spec.py --check
	python3 generate_arm64_mem_dispatch_spec.py --check
	python3 generate_arm64_stack_tag_spec.py --check
	python3 generate_arm64_dq_mem_spec.py --check
	python3 generate_arm64_pair_mem_spec.py --check
	python3 generate_arm64_branch_spec.py --check
	python3 generate_arm64_branch_emit_spec.py --check
	python3 generate_arm64_cond_spec.py --check
	python3 generate_x86_cond_spec.py --check
	python3 generate_x86_logic_flags_spec.py --check
	python3 generate_x86_width_spec.py --check
	python3 generate_x86_immediate_spec.py --check
	python3 generate_x86_alu_decode_spec.py --check
	python3 generate_x86_not_spec.py --check
	python3 generate_x86_shift_count_spec.py --check
	python3 generate_x86_shift_result_spec.py --check
	python3 generate_x86_bswap_spec.py --check
	python3 generate_x86_signed_spec.py --check
	python3 generate_x86_popcount_spec.py --check
	python3 generate_x86_bitops_spec.py --check
	python3 generate_x86_doubleshift_spec.py --check
	python3 generate_x86_shift_flags_spec.py --check
	python3 generate_x86_reg_write_spec.py --check
	python3 generate_x86_mem_offset_spec.py --check
	python3 generate_x86_reg_read_spec.py --check
	python3 generate_x86_reg_lane_aux_spec.py --check
	python3 generate_x86_sub_flags_spec.py --check
	python3 generate_x86_add_flags_spec.py --check
	python3 generate_x86_sbb_result_spec.py --check
	python3 generate_x86_sbb_flags_spec.py --check
	python3 generate_x86_adc_spec.py --check
	python3 generate_x86_imul_flags_spec.py --check
	python3 generate_x86_mem_access_spec.py --check
	python3 generate_x86_mem_dispatch_spec.py --check
	python3 generate_x86_mov_load_spec.py --check
	python3 generate_x86_store_spec.py --check
	python3 generate_x86_setcc_spec.py --check
	python3 generate_x86_setcc_mem_spec.py --check
	python3 generate_x86_cmov_spec.py --check
	python3 generate_x86_movbe_spec.py --check
	python3 generate_x86_ptr_write_spec.py --check
	python3 generate_x86_xmm0_spec.py --check
	python3 generate_x86_callmem_spec.py --check
	python3 generate_x86_pushpop_spec.py --check
	python3 generate_x86_rep_movs_spec.py --check
	python3 generate_x86_andn_spec.py --check
	python3 generate_x86_bzhi_spec.py --check
	python3 generate_x86_bt_spec.py --check
	python3 generate_x86_cmpop_spec.py --check
	lake build
	lake env lean KProgFormal/TagErasure.lean
	lake env lean KProgFormal/Arm64ControlFlow.lean
	lake env lean KProgFormal/X86ControlFlow.lean
	lake env lean KProgFormal/X86LogicFlags.lean
	lake env lean KProgFormal/X86Width.lean
	lake env lean KProgFormal/X86Immediate.lean
	lake env lean KProgFormal/X86SubFlags.lean
	lake env lean KProgFormal/X86AddFlags.lean
	lake env lean KProgFormal/X86SbbResult.lean
	lake env lean KProgFormal/X86SbbFlags.lean
	lake env lean KProgFormal/X86Adc.lean
	lake env lean KProgFormal/X86AddResult.lean
	lake env lean KProgFormal/X86SubResult.lean
	lake env lean KProgFormal/X86AluDecode.lean
	lake env lean KProgFormal/X86IncDec.lean
	lake env lean KProgFormal/X86Not.lean
	lake env lean KProgFormal/X86ShiftCount.lean
	lake env lean KProgFormal/X86ShiftResult.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_ror_result_host.c -o build/test_x86_ror_result_host
	./build/test_x86_ror_result_host
	lake env lean KProgFormal/GeneratedX86Bswap.lean
	lake env lean KProgFormal/X86Bswap.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_bswap_host.c -o build/test_x86_bswap_host
	./build/test_x86_bswap_host
	lake env lean KProgFormal/GeneratedX86Signed.lean
	lake env lean KProgFormal/X86Signed.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_signed_host.c -o build/test_x86_signed_host
	./build/test_x86_signed_host
	lake env lean KProgFormal/GeneratedX86Popcount.lean
	lake env lean KProgFormal/X86Popcount.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_popcount_host.c -o build/test_x86_popcount_host
	./build/test_x86_popcount_host
	lake env lean KProgFormal/GeneratedX86Bitops.lean
	lake env lean KProgFormal/X86Bitops.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_bitops_host.c -o build/test_x86_bitops_host
	./build/test_x86_bitops_host
	lake env lean KProgFormal/GeneratedX86DoubleShift.lean
	lake env lean KProgFormal/X86DoubleShift.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_doubleshift_host.c -o build/test_x86_doubleshift_host
	./build/test_x86_doubleshift_host
	lake env lean KProgFormal/X86ShiftFlags.lean
	lake env lean KProgFormal/X86ImulFlags.lean
	lake env lean KProgFormal/X86RegWrite.lean
	lake env lean KProgFormal/X86AluWriteback.lean
	lake env lean KProgFormal/X86RegRead.lean
	lake env lean KProgFormal/X86RegLaneAux.lean
	lake env lean KProgFormal/X86UnaryWriteback.lean
	lake env lean KProgFormal/X86MemAccess.lean
	$(CC) -Wall -Wextra -O2 -I. test_mem_access_host.c -o build/test_mem_access_host
	./build/test_mem_access_host
	lake env lean KProgFormal/X86MemAluHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_alu_handler_host.c -o build/test_x86_mem_alu_handler_host
	./build/test_x86_mem_alu_handler_host
	lake env lean KProgFormal/X86MemStoreAluHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_store_alu_handler_host.c -o build/test_x86_mem_store_alu_handler_host
	./build/test_x86_mem_store_alu_handler_host
	lake env lean KProgFormal/X86MemUnaryHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_unary_handler_host.c -o build/test_x86_mem_unary_handler_host
	./build/test_x86_mem_unary_handler_host
	lake env lean KProgFormal/X86MemLogicHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_logic_handler_host.c -o build/test_x86_mem_logic_handler_host
	./build/test_x86_mem_logic_handler_host
	lake env lean KProgFormal/X86MemShiftHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_shift_handler_host.c -o build/test_x86_mem_shift_handler_host
	./build/test_x86_mem_shift_handler_host
	lake env lean KProgFormal/X86MemBitHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_bit_handler_host.c -o build/test_x86_mem_bit_handler_host
	./build/test_x86_mem_bit_handler_host
	lake env lean KProgFormal/X86MemImulHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_imul_handler_host.c -o build/test_x86_mem_imul_handler_host
	./build/test_x86_mem_imul_handler_host
	lake env lean KProgFormal/X86MemCompareHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_compare_handler_host.c -o build/test_x86_mem_compare_handler_host
	./build/test_x86_mem_compare_handler_host
	lake env lean KProgFormal/X86MulxHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mulx_handler_host.c -o build/test_x86_mulx_handler_host
	./build/test_x86_mulx_handler_host
	lake env lean KProgFormal/X86ImulRegImmHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_imul_reg_imm_handler_host.c -o build/test_x86_imul_reg_imm_handler_host
	./build/test_x86_imul_reg_imm_handler_host
	lake env lean KProgFormal/GeneratedX86MemOffset.lean
	lake env lean KProgFormal/X86MemOffset.lean
	lake env lean KProgFormal/X86LeaHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_lea_handler_host.c -o build/test_x86_lea_handler_host
	./build/test_x86_lea_handler_host
	lake env lean KProgFormal/X86MovHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mov_handler_host.c -o build/test_x86_mov_handler_host
	./build/test_x86_mov_handler_host
	lake env lean KProgFormal/X86MovxRegHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_movx_reg_host.c -o build/test_x86_movx_reg_host
	./build/test_x86_movx_reg_host
	lake env lean KProgFormal/GeneratedX86MemDispatch.lean
	lake env lean KProgFormal/X86MemDispatch.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mem_read_dispatch_host.c -o build/test_x86_mem_read_dispatch_host
	./build/test_x86_mem_read_dispatch_host
	lake env lean KProgFormal/GeneratedX86MovLoad.lean
	lake env lean KProgFormal/X86MovLoadHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mov_load_host.c -o build/test_x86_mov_load_host
	./build/test_x86_mov_load_host
	lake env lean KProgFormal/GeneratedX86Store.lean
	lake env lean KProgFormal/X86StoreHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_store_host.c -o build/test_x86_store_host
	./build/test_x86_store_host
	lake env lean KProgFormal/GeneratedX86Setcc.lean
	lake env lean KProgFormal/X86SetccHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_setcc_host.c -o build/test_x86_setcc_host
	./build/test_x86_setcc_host
	lake env lean KProgFormal/GeneratedX86SetccMem.lean
	lake env lean KProgFormal/X86SetccMemHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_setcc_mem_host.c -o build/test_x86_setcc_mem_host
	./build/test_x86_setcc_mem_host
	lake env lean KProgFormal/GeneratedX86Cmov.lean
	lake env lean KProgFormal/X86CmovHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_cmov_host.c -o build/test_x86_cmov_host
	./build/test_x86_cmov_host
	lake env lean KProgFormal/GeneratedX86Movbe.lean
	lake env lean KProgFormal/X86MovbeHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_movbe_host.c -o build/test_x86_movbe_host
	./build/test_x86_movbe_host
	lake env lean KProgFormal/GeneratedX86PtrWrite.lean
	lake env lean KProgFormal/X86PtrWriteHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_mov_load_map_ptr_host.c -o build/test_x86_mov_load_map_ptr_host
	./build/test_x86_mov_load_map_ptr_host
	lake env lean KProgFormal/GeneratedX86Xmm0.lean
	lake env lean KProgFormal/X86Xmm0Handler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_xmm0_host.c -o build/test_x86_xmm0_host
	./build/test_x86_xmm0_host
	lake env lean KProgFormal/GeneratedX86CallMem.lean
	lake env lean KProgFormal/X86CallMemHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_callmem_host.c -o build/test_x86_callmem_host
	./build/test_x86_callmem_host
	lake env lean KProgFormal/GeneratedX86PushPop.lean
	lake env lean KProgFormal/X86PushPopHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_pushpop_host.c -o build/test_x86_pushpop_host
	./build/test_x86_pushpop_host
	lake env lean KProgFormal/GeneratedX86RepMovs.lean
	lake env lean KProgFormal/X86RepMovsHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_rep_movs_host.c -o build/test_x86_rep_movs_host
	./build/test_x86_rep_movs_host
	lake env lean KProgFormal/GeneratedX86Andn.lean
	lake env lean KProgFormal/X86AndnHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_andn_host.c -o build/test_x86_andn_host
	./build/test_x86_andn_host
	lake env lean KProgFormal/GeneratedX86Bzhi.lean
	lake env lean KProgFormal/X86BzhiHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_bzhi_host.c -o build/test_x86_bzhi_host
	./build/test_x86_bzhi_host
	lake env lean KProgFormal/GeneratedX86Bt.lean
	lake env lean KProgFormal/X86BtHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_bt_host.c -o build/test_x86_bt_host
	./build/test_x86_bt_host
	lake env lean KProgFormal/GeneratedX86CmpOp.lean
	lake env lean KProgFormal/X86CmpOpHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_x86_cmpop_host.c -o build/test_x86_cmpop_host
	./build/test_x86_cmpop_host
	lake env lean KProgFormal/Arm64Flags.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_flags_host.c -o build/test_arm64_flags_host
	./build/test_arm64_flags_host
	lake env lean KProgFormal/Arm64AluResult.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_alu_result_host.c -o build/test_arm64_alu_result_host
	./build/test_arm64_alu_result_host
	lake env lean KProgFormal/GeneratedArm64AluHandler.lean
	lake env lean KProgFormal/Arm64AluHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_alu_handler_host.c -o build/test_arm64_alu_handler_host
	./build/test_arm64_alu_handler_host
	lake env lean KProgFormal/GeneratedArm64AluOperand.lean
	lake env lean KProgFormal/Arm64AluOperandHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_alu_operand_host.c -o build/test_arm64_alu_operand_host
	./build/test_arm64_alu_operand_host
	lake env lean KProgFormal/GeneratedArm64FlagHandler.lean
	lake env lean KProgFormal/Arm64FlagHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_flag_handler_host.c -o build/test_arm64_flag_handler_host
	./build/test_arm64_flag_handler_host
	lake env lean KProgFormal/GeneratedArm64LogicFlagHandler.lean
	lake env lean KProgFormal/Arm64LogicFlagHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_logic_flag_handler_host.c -o build/test_arm64_logic_flag_handler_host
	./build/test_arm64_logic_flag_handler_host
	lake env lean KProgFormal/GeneratedArm64CcmpHandler.lean
	lake env lean KProgFormal/Arm64CcmpHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_ccmp_handler_host.c -o build/test_arm64_ccmp_handler_host
	./build/test_arm64_ccmp_handler_host
	lake env lean KProgFormal/Arm64Mod.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_mod_host.c -o build/test_arm64_mod_host
	./build/test_arm64_mod_host
	lake env lean KProgFormal/GeneratedArm64Bitfield.lean
	lake env lean KProgFormal/Arm64Bitfield.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_bitfield_host.c -o build/test_arm64_bitfield_host
	./build/test_arm64_bitfield_host
	lake env lean KProgFormal/GeneratedArm64Mul.lean
	lake env lean KProgFormal/Arm64Mul.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_mul_host.c -o build/test_arm64_mul_host
	./build/test_arm64_mul_host
	lake env lean KProgFormal/GeneratedArm64Extrev.lean
	lake env lean KProgFormal/Arm64Extrev.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_extrev_host.c -o build/test_arm64_extrev_host
	./build/test_arm64_extrev_host
	lake env lean KProgFormal/GeneratedArm64Csel.lean
	lake env lean KProgFormal/Arm64Csel.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_csel_host.c -o build/test_arm64_csel_host
	./build/test_arm64_csel_host
	lake env lean KProgFormal/GeneratedArm64Branch.lean
	lake env lean KProgFormal/Arm64Branch.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_branch_host.c -o build/test_arm64_branch_host
	./build/test_arm64_branch_host
	lake env lean KProgFormal/GeneratedArm64BranchEmit.lean
	lake env lean KProgFormal/Arm64BranchEmit.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_branch_emit_host.c -o build/test_arm64_branch_emit_host
	./build/test_arm64_branch_emit_host
	lake env lean KProgFormal/GeneratedArm64Movk.lean
	lake env lean KProgFormal/Arm64Movk.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_movk_host.c -o build/test_arm64_movk_host
	./build/test_arm64_movk_host
	lake env lean KProgFormal/GeneratedArm64Shift.lean
	lake env lean KProgFormal/Arm64Shift.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_shift_host.c -o build/test_arm64_shift_host
	./build/test_arm64_shift_host
	lake env lean KProgFormal/GeneratedArm64Reduction.lean
	lake env lean KProgFormal/Arm64Reduction.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_reduction_host.c -o build/test_arm64_reduction_host
	./build/test_arm64_reduction_host
	lake env lean KProgFormal/GeneratedArm64MemOffset.lean
	lake env lean KProgFormal/Arm64MemOffset.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_mem_offset_host.c -o build/test_arm64_mem_offset_host
	./build/test_arm64_mem_offset_host
	lake env lean KProgFormal/GeneratedArm64Fmov.lean
	lake env lean KProgFormal/Arm64Fmov.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_fmov_host.c -o build/test_arm64_fmov_host
	./build/test_arm64_fmov_host
	lake env lean KProgFormal/GeneratedArm64LoadBytes.lean
	lake env lean KProgFormal/Arm64LoadBytes.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_load_bytes_host.c -o build/test_arm64_load_bytes_host
	./build/test_arm64_load_bytes_host
	lake env lean KProgFormal/GeneratedArm64ByteLane.lean
	lake env lean KProgFormal/Arm64ByteLane.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_byte_lane_host.c -o build/test_arm64_byte_lane_host
	./build/test_arm64_byte_lane_host
	lake env lean KProgFormal/GeneratedArm64MemDispatch.lean
	lake env lean KProgFormal/Arm64MemDispatch.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_mem_dispatch_host.c -o build/test_arm64_mem_dispatch_host
	./build/test_arm64_mem_dispatch_host
	lake env lean KProgFormal/GeneratedArm64StackTag.lean
	lake env lean KProgFormal/Arm64StackTag.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_stack_tag_host.c -o build/test_arm64_stack_tag_host
	./build/test_arm64_stack_tag_host
	lake env lean KProgFormal/GeneratedArm64DqMem.lean
	lake env lean KProgFormal/Arm64DqMemHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_dq_mem_host.c -o build/test_arm64_dq_mem_host
	./build/test_arm64_dq_mem_host
	lake env lean KProgFormal/GeneratedArm64PairMem.lean
	lake env lean KProgFormal/Arm64PairMemHandler.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_pair_mem_host.c -o build/test_arm64_pair_mem_host
	./build/test_arm64_pair_mem_host
	lake env lean KProgFormal/Arm64Decode.lean
