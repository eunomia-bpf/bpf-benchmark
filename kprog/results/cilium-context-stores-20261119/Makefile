VMLINUX_DIR := vendor/bpf/targets/x86/$(shell cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)
.PHONY: layout prepare
layout:
	clang-18 -fsyntax-only -I$(VMLINUX_DIR) kprog/results/cilium-context-stores-20261119/layout.c
prepare:
	python3 kprog/results/cilium-context-stores-20261119/prepare.py $(OUT)
