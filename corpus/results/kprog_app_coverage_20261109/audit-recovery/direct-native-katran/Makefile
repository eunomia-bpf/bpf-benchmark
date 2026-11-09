SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
HERE := /workspaces/repository/corpus/results/kprog_app_coverage_20261109/audit-recovery/direct-native-katran
.PHONY: payloads
payloads:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/producer.py
