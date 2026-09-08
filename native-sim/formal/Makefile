.PHONY: check

check:
	python3 generate_ptr_add_spec.py --check
	python3 generate_abi_load_spec.py --check
	lake build
	lake env lean KProgFormal/TagErasure.lean
