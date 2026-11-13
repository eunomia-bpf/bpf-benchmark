TETRAGON_UPSTREAM ?= /workspaces/repository/vendor/repos/tetragon/bpf
include $(TETRAGON_UPSTREAM)/Makefile.defs
.PHONY: flags
flags:
	@printf '%s\n' '$(CLANG_FLAGS)'
