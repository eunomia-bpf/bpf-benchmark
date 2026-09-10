.PHONY: check

check:
	python3 generate_ptr_add_spec.py --check
	python3 generate_abi_load_spec.py --check
	python3 generate_arm64_cond_spec.py --check
	python3 generate_x86_cond_spec.py --check
	python3 generate_x86_logic_flags_spec.py --check
	python3 generate_x86_width_spec.py --check
	python3 generate_x86_sub_flags_spec.py --check
	python3 generate_x86_add_flags_spec.py --check
	python3 generate_x86_sbb_result_spec.py --check
	python3 generate_x86_sbb_flags_spec.py --check
	python3 generate_x86_adc_spec.py --check
	lake build
	lake env lean KProgFormal/TagErasure.lean
	lake env lean KProgFormal/Arm64ControlFlow.lean
	lake env lean KProgFormal/X86ControlFlow.lean
	lake env lean KProgFormal/X86LogicFlags.lean
	lake env lean KProgFormal/X86Width.lean
	lake env lean KProgFormal/X86SubFlags.lean
	lake env lean KProgFormal/X86AddFlags.lean
	lake env lean KProgFormal/X86SbbResult.lean
	lake env lean KProgFormal/X86SbbFlags.lean
	lake env lean KProgFormal/X86Adc.lean
	lake env lean KProgFormal/X86AddResult.lean
	lake env lean KProgFormal/X86SubResult.lean
