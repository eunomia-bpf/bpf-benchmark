.PHONY: __prepare-local

_PREP_ARCH := $(RUN_TARGET_ARCH)
_PREP_KERNEL_DEPS := $(if $(filter kvm,$(RUN_EXECUTOR)),__kernel)
_PREP_LIBBPF_DEPS := $(if $(RUN_LIBBPF_RUNTIME_PATH),__libbpf-runtime-$(_PREP_ARCH))
_PREP_KERNEL_MODULE_DEPS := $(if $(filter kvm,$(RUN_EXECUTOR)),__kernel-modules-$(_PREP_ARCH))
_PREP_DAEMON_DEPS := $(if $(filter 1,$(RUN_NEEDS_DAEMON_BINARY)),__daemon-binary-$(_PREP_ARCH))
_PREP_RUNNER_DEPS := $(if $(filter 1,$(RUN_NEEDS_RUNNER_BINARY)),__runner-binary-$(_PREP_ARCH))
_PREP_TEST_DEPS := $(if $(filter test,$(RUN_SUITE_NAME)),__repo-test-binaries-$(_PREP_ARCH))
_PREP_KINSN_DEPS := $(if $(filter 1,$(RUN_NEEDS_KINSN_MODULES)),__kinsn-modules-$(_PREP_ARCH))
_PREP_SCX_DEPS := $(if $(RUN_SCX_PACKAGES_CSV),__scx-binaries-$(_PREP_ARCH))
_PREP_NATIVE_REPO_DEPS := $(if $(RUN_NATIVE_REPOS_CSV),__native-repos-$(_PREP_ARCH))
_PREP_WORKLOAD_TOOL_DEPS := $(if $(filter 1,$(RUN_NEEDS_WORKLOAD_TOOLS)),__workload-tools-$(_PREP_ARCH))
_PREP_MICRO_PROGRAM_DEPS := $(if $(filter micro,$(RUN_SUITE_NAME)),__micro-programs)

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
