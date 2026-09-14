.PHONY: check

check:
	install -d build
	python3 generate_ptr_add_spec.py --check
	python3 generate_abi_load_spec.py --check
	python3 generate_arm64_width_spec.py --check
	python3 generate_arm64_flags_spec.py --check
	python3 generate_arm64_decode_spec.py --check
	python3 generate_arm64_alu_result_spec.py --check
	python3 generate_arm64_mod_spec.py --check
	python3 generate_arm64_cond_spec.py --check
	python3 generate_x86_cond_spec.py --check
	python3 generate_x86_logic_flags_spec.py --check
	python3 generate_x86_width_spec.py --check
	python3 generate_x86_immediate_spec.py --check
	python3 generate_x86_alu_decode_spec.py --check
	python3 generate_x86_not_spec.py --check
	python3 generate_x86_shift_count_spec.py --check
	python3 generate_x86_shift_result_spec.py --check
	python3 generate_x86_shift_flags_spec.py --check
	python3 generate_x86_reg_write_spec.py --check
	python3 generate_x86_reg_read_spec.py --check
	python3 generate_x86_reg_lane_aux_spec.py --check
	python3 generate_x86_sub_flags_spec.py --check
	python3 generate_x86_add_flags_spec.py --check
	python3 generate_x86_sbb_result_spec.py --check
	python3 generate_x86_sbb_flags_spec.py --check
	python3 generate_x86_adc_spec.py --check
	python3 generate_x86_imul_flags_spec.py --check
	python3 generate_x86_mem_access_spec.py --check
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
	lake env lean KProgFormal/Arm64Flags.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_flags_host.c -o build/test_arm64_flags_host
	./build/test_arm64_flags_host
	lake env lean KProgFormal/Arm64AluResult.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_alu_result_host.c -o build/test_arm64_alu_result_host
	./build/test_arm64_alu_result_host
	lake env lean KProgFormal/Arm64Mod.lean
	$(CC) -Wall -Wextra -O2 -I. test_arm64_mod_host.c -o build/test_arm64_mod_host
	./build/test_arm64_mod_host
	lake env lean KProgFormal/Arm64Decode.lean
