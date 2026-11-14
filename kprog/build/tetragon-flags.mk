TETRAGON_UPSTREAM ?= /workspaces/repository/vendor/repos/tetragon/bpf
# Parse the upstream variant/object definitions without generating dependency
# files. This changes only the parse-time include condition; no clean recipe runs.
MAKECMDGOALS := clean
include $(TETRAGON_UPSTREAM)/Makefile
.PHONY: flags
flags:
	@printf '%s\n' '$(CLANG_FLAGS) $(CFLAGS_$(VARIANT)) $(CFLAGS_$(UNIT).o)'
