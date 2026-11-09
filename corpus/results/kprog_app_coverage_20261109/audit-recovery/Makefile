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

.PHONY: selftest-inputs
selftest-inputs: $(STATE)/selftests315/programs.json
$(STATE)/selftests315/programs.json: $(ROOT)/kprog/selftests/selftests.py
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(ROOT)/kprog/selftests/selftests.py --arch x86 --out $(STATE)/selftests315

.PHONY: native-inputs
native-inputs:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/native-inputs.py

.PHONY: native-manifests
native-manifests:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/native-inputs.py finish

REVISION ?= HEAD
ENTRY := $(ROOT)/corpus/results/kprog_app_coverage_20261109/entry-frame/Makefile
.PHONY: prepare safety48 selftests315 census
prepare:
	$(MAKE) -f $(ENTRY) prepare REVISION=$(REVISION) LOADER=/var/tmp/kprog-tmp/C/stock-entry/loader-build SELFTESTS=$(STATE)/selftests315
safety48:
	$(MAKE) -f $(ENTRY) isa48 REVISION=$(REVISION)
selftests315:
	$(MAKE) -f $(ENTRY) selftests315 REVISION=$(REVISION)
census:
	$(MAKE) -f $(ENTRY) census REVISION=$(REVISION)

.PHONY: app-image applications
app-image:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/application.py image --revision $(REVISION)
applications:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/application.py run --revision $(REVISION)
