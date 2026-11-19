.PHONY: host check-census
host:
	cd kprog/x86/native_lab/native_link && cargo test --release map_operations_follow_native_arguments_across_reordered_calls
	cd kprog/x86/native_lab/native_link && cargo test --release runtime_known_maps_use_only_exact_named_map_facts

check-census:
	python3 kprog/results/checked-hash-ops-20261119/check_census.py kprog/results/checked-hash-ops-20261119/batch-progress.json $(OUT)
