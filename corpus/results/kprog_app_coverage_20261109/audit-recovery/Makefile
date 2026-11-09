SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261109/audit-recovery
STATE := /var/tmp/kprog-tmp/C/audit-recovery
.PHONY: paired-source kernel-modules
paired-source:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/paired-source.py
kernel-modules:
	TMPDIR=/var/tmp/kprog-tmp/C/stock-entry $(MAKE) -C /var/tmp/kprog-tmp/CK/linux O=/var/tmp/kprog-tmp/C/stock-entry/kernel-build -j4 modules
