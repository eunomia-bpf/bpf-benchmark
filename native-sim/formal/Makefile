.PHONY: check

check:
	python3 generate_ptr_add_spec.py --check
	python3 generate_abi_load_spec.py --check
	python3 generate_arm64_cond_spec.py --check
	python3 generate_x86_cond_spec.py --check
	python3 generate_x86_logic_flags_spec.py --check
	lake build
	lake env lean KProgFormal/TagErasure.lean
	lake env lean KProgFormal/Arm64ControlFlow.lean
	lake env lean KProgFormal/X86ControlFlow.lean
	lake env lean KProgFormal/X86LogicFlags.lean
