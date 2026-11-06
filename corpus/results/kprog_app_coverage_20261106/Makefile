ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
PHASE ?= baseline

.PHONY: compile verify guest-verify summarize
summarize:
	python3 $(HERE)/summarize.py

compile:
	taskset -c 8-15 python3 $(HERE)/coverage.py compile $(HERE)/$(PHASE)

verify:
	taskset -c 8-15 vng --run $(ROOT)/vendor/build/x86/linux/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor \
		--cpus 4 --memory 8G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f $(HERE)/Makefile guest-verify PHASE=$(PHASE)'

guest-verify:
	python3 $(HERE)/coverage.py verify $(HERE)/$(PHASE)
