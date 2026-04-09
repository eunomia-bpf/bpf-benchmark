PREP_BASE_TARGET := $(if $(filter kvm,$(RUN_EXECUTOR)),__prepare-local-base-kvm,__prepare-local-noop)
PREP_RUNTIME_TARGET := __prepare-local-runtime-$(RUN_TARGET_ARCH)
PREP_KINSN_TARGET := $(if $(filter 1,$(RUN_NEEDS_KINSN_MODULES)),__prepare-local-kinsn-$(RUN_TARGET_ARCH),__prepare-local-noop)
PREP_SCX_TARGET := $(if $(strip $(RUN_SCX_PACKAGES_CSV)),__prepare-local-scx-$(RUN_TARGET_ARCH),__prepare-local-noop)
PREP_NATIVE_TARGET := $(if $(strip $(RUN_NATIVE_REPOS_CSV)),__prepare-local-native-$(RUN_TARGET_ARCH),__prepare-local-noop)
PREP_BENCHMARK_EXTRA_TARGET := __prepare-local-benchmark-extra-$(RUN_TARGET_ARCH)

__prepare-local:
	@test -n "$(RUN_TARGET_NAME)" || { echo "RUN_TARGET_NAME is required" >&2; exit 1; }
	@$(MAKE) --no-print-directory "__prepare-local-$(RUN_SUITE_NAME)"

__prepare-local-noop:
	@true

__prepare-local-test:
	@$(MAKE) --no-print-directory "$(PREP_BASE_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_RUNTIME_TARGET)"
	@$(MAKE) --no-print-directory "__prepare-local-test-outputs-$(RUN_TARGET_ARCH)"
	@$(MAKE) --no-print-directory "$(PREP_KINSN_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_SCX_TARGET)"

__prepare-local-micro:
	@$(MAKE) --no-print-directory "$(PREP_BASE_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_RUNTIME_TARGET)"
	@$(MAKE) --no-print-directory "__prepare-local-micro-programs-$(RUN_TARGET_ARCH)"

__prepare-local-corpus:
	@$(MAKE) --no-print-directory "$(PREP_BASE_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_RUNTIME_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_KINSN_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_SCX_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_NATIVE_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_BENCHMARK_EXTRA_TARGET)"

__prepare-local-e2e:
	@$(MAKE) --no-print-directory "$(PREP_BASE_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_RUNTIME_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_KINSN_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_SCX_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_NATIVE_TARGET)"
	@$(MAKE) --no-print-directory "$(PREP_BENCHMARK_EXTRA_TARGET)"

__prepare-local-base-kvm:
	@$(MAKE) --no-print-directory __kernel BZIMAGE="$(RUN_VM_KERNEL_IMAGE)"

__prepare-local-runtime-x86_64:
	@if [ "$(RUN_NEEDS_DAEMON_BINARY)" = "1" ]; then \
		$(MAKE) --no-print-directory __daemon-binary-x86_64; \
	fi
	@if [ "$(RUN_NEEDS_RUNNER_BINARY)" = "1" ]; then \
		$(MAKE) --no-print-directory __runner-binary-x86_64; \
	fi

__prepare-local-runtime-arm64:
	@if [ "$(RUN_NEEDS_DAEMON_BINARY)" = "1" ]; then \
		$(MAKE) --no-print-directory __daemon-binary-arm64; \
	fi
	@if [ "$(RUN_NEEDS_RUNNER_BINARY)" = "1" ]; then \
		$(MAKE) --no-print-directory __runner-binary-arm64; \
	fi

__prepare-local-kinsn-x86_64:
	@$(MAKE) --no-print-directory __kinsn-modules-x86_64

__prepare-local-kinsn-arm64:
	@$(MAKE) --no-print-directory __kinsn-modules-arm64

__prepare-local-test-outputs-x86_64:
	@$(MAKE) --no-print-directory __repo-test-binaries-x86_64

__prepare-local-test-outputs-arm64:
	@$(MAKE) --no-print-directory __repo-test-binaries-arm64

__prepare-local-micro-programs-x86_64:
	@$(MAKE) --no-print-directory __micro-programs

__prepare-local-micro-programs-arm64:
	@$(MAKE) --no-print-directory __micro-programs

__prepare-local-scx-x86_64:
	@$(MAKE) --no-print-directory __scx-binaries-x86_64

__prepare-local-scx-arm64:
	@$(MAKE) --no-print-directory __scx-binaries-arm64

__prepare-local-native-x86_64:
	@$(MAKE) --no-print-directory __native-repos-x86_64

__prepare-local-native-arm64:
	@$(MAKE) --no-print-directory __native-repos-arm64

__prepare-local-benchmark-extra-x86_64:
	@$(MAKE) --no-print-directory __x86-portable-libbpf

__prepare-local-benchmark-extra-arm64:
	@true
