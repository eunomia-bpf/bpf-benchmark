ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
PHASE ?= baseline
DISPATCH := $(HERE)/dispatch-build
HOST_FLAGS := -O2 -Wno-c23-extensions -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi

.PHONY: compile verify guest-verify summarize dispatch-regression
dispatch-regression:
	python3 $(HERE)/check_dispatch.py $(GENERATOR)
	cc $(HOST_FLAGS) -DLICENSE=old_license -c $(DISPATCH)/old.c -o $(DISPATCH)/old.o
	cc $(HOST_FLAGS) -DLICENSE=current_license -c $(DISPATCH)/current.c -o $(DISPATCH)/current.o
	cc $(HOST_FLAGS) $(DISPATCH)/main.c $(DISPATCH)/native.S $(DISPATCH)/old.o $(DISPATCH)/current.o -o $(DISPATCH)/check
	taskset -c 8-15 $(DISPATCH)/check
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
