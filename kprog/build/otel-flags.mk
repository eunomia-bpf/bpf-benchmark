OTEL_UPSTREAM ?= /workspaces/repository/vendor/repos/opentelemetry-ebpf-profiler/support/ebpf
include $(OTEL_UPSTREAM)/Makefile
.PHONY: flags
flags: $(OTEL_SOURCE)
	@printf '%s\n' '$(FLAGS)'
