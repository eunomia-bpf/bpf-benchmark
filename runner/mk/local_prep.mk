empty :=
space := $(empty) $(empty)
comma := ,

define _native_repo_targets
$(strip \
	$(foreach repo,$(1), \
		$(if $(filter bcc,$(repo)),$(ACTIVE_BCC_REQUIRED)) \
		$(if $(filter tracee,$(repo)),$(ACTIVE_TRACEE_REQUIRED)) \
		$(if $(filter tetragon,$(repo)),$(ACTIVE_TETRAGON_REQUIRED)) \
		$(if $(filter katran,$(repo)),$(ACTIVE_KATRAN_REQUIRED)) \
	) \
)
endef

_PREP_ARCH = $(RUN_TARGET_ARCH)
_PREP_KERNEL_DEPS = $(if $(filter kvm,$(RUN_EXECUTOR)),$(X86_BUILD_DIR)/arch/x86/boot/bzImage)
_PREP_LIBBPF_DEPS = $(if $(and $(filter-out arm64,$(RUN_TARGET_ARCH)),$(filter test corpus e2e,$(RUN_SUITE_NAME))),$(ACTIVE_LIBBPF_RUNTIME_PRIMARY))
_PREP_KERNEL_MODULE_DEPS = $(if $(filter kvm,$(RUN_EXECUTOR)),$(REPO_KERNEL_MODULES_ROOT)/lib/modules)
_PREP_DAEMON_DEPS = $(if $(filter 1,$(RUN_NEEDS_DAEMON_BINARY)),$(ACTIVE_DAEMON_BINARY))
_PREP_RUNNER_DEPS = $(if $(filter 1,$(RUN_NEEDS_RUNNER_BINARY)),$(ACTIVE_RUNNER_BINARY))
_PREP_TEST_DEPS = $(if $(filter test,$(RUN_SUITE_NAME)),$(ACTIVE_TEST_UNITTEST_PRIMARY) $(ACTIVE_TEST_NEGATIVE_PRIMARY))
_PREP_KINSN_DEPS = $(if $(filter 1,$(RUN_NEEDS_KINSN_MODULES)),$(ACTIVE_KINSN_PRIMARY) $(ACTIVE_KINSN_SECONDARIES))
_PREP_SCX_DEPS = $(strip $(foreach package,$(subst $(comma),$(space),$(RUN_SCX_PACKAGES_CSV)),$(REPO_SCX_ROOT)/bin/$(package) $(REPO_SCX_ROOT)/$(package)_main.bpf.o))
_PREP_NATIVE_REPO_DEPS = $(call _native_repo_targets,$(subst $(comma),$(space),$(RUN_NATIVE_REPOS_CSV)))
_PREP_WORKLOAD_TOOL_DEPS = $(if $(filter 1,$(RUN_NEEDS_WORKLOAD_TOOLS)),$(ACTIVE_WORKLOAD_TOOLS_REQUIRED))
_PREP_MICRO_PROGRAM_DEPS = $(if $(filter micro,$(RUN_SUITE_NAME)),$(ACTIVE_MICRO_PROGRAM_PRIMARY))

__prepare-local: \
	$(_PREP_KERNEL_DEPS) \
	$(_PREP_LIBBPF_DEPS) \
	$(_PREP_KERNEL_MODULE_DEPS) \
	$(_PREP_DAEMON_DEPS) \
	$(_PREP_RUNNER_DEPS) \
	$(_PREP_TEST_DEPS) \
	$(_PREP_KINSN_DEPS) \
	$(_PREP_SCX_DEPS) \
	$(_PREP_NATIVE_REPO_DEPS) \
	$(_PREP_WORKLOAD_TOOL_DEPS) \
	$(_PREP_MICRO_PROGRAM_DEPS)
	@test -n "$(RUN_TARGET_NAME)" || { echo "RUN_TARGET_NAME is required" >&2; exit 1; }
	@test -n "$(RUN_SUITE_NAME)" || { echo "RUN_SUITE_NAME is required" >&2; exit 1; }
	@test -n "$(RUN_TARGET_ARCH)" || { echo "RUN_TARGET_ARCH is required" >&2; exit 1; }
