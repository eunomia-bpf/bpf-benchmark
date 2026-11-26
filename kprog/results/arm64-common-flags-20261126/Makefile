.PHONY: compiler-probe
compiler-probe:
	python3 compiler_probe.py

.PHONY: hash-code-audit
hash-code-audit:
	python3 hash_code_audit.py

.PHONY: atomic-probe
atomic-probe:
	python3 atomic_probe.py

.PHONY: atomic-ir-audit
atomic-ir-audit:
	python3 atomic_ir_audit.py

.PHONY: abi-probe
abi-probe:
	python3 abi_probe.py

.PHONY: abi-checked-before abi-checked-after
abi-checked-before:
	python3 abi_checked.py before
abi-checked-after:
	python3 abi_checked.py after

.PHONY: select-audit
select-audit:
	python3 select_audit.py

.PHONY: select-backend
select-backend:
	python3 select_backend.py

.PHONY: helpers-before helpers-after
helpers-before:
	python3 helpers_checked.py before
helpers-after:
	python3 helpers_checked.py after
