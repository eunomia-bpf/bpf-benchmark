SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261109/entry-frame
STATE := /var/tmp/kprog-tmp/C/stock-entry
KERNEL_SOURCE := /var/tmp/kprog-tmp/CK/linux
KERNEL_BUILD := $(STATE)/kernel-build
.PHONY: kernel module compile-before compile-after
kernel:
	install -d $(KERNEL_BUILD)
	@if test ! -e $(KERNEL_BUILD)/Makefile; then cp -a --reflink=auto /var/tmp/kprog-tmp/S17/x86-build/. $(KERNEL_BUILD)/; fi
	TMPDIR=$(STATE) $(MAKE) -C $(KERNEL_SOURCE) O=$(KERNEL_BUILD) -j4 bzImage
module:
	TMPDIR=$(STATE) $(MAKE) -C $(KERNEL_BUILD) M=$(ROOT)/kprog/stock-path/module MO=$(STATE)/module -j4 modules
compile-before:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/compile.py before
compile-after:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/compile.py after

.PHONY: linker
linker:
	install -d $(STATE)/native-link-target
	@if test ! -e $(STATE)/native-link-target/CACHEDIR.TAG; then cp -a --reflink=auto $(ROOT)/kprog/x86/native_lab/native_link/target/. $(STATE)/native-link-target/; fi
	CARGO_TARGET_DIR=$(STATE)/native-link-target cargo test --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml tail_
	CARGO_TARGET_DIR=$(STATE)/native-link-target cargo test --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --features stock-entry-frame tail_
	CARGO_TARGET_DIR=$(STATE)/native-link-target cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --features stock-entry-frame
