from __future__ import annotations

import os
import shlex
import subprocess
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.app_suite_schema import load_app_suite_from_yaml
from runner.libs.cli_support import fail
from runner.libs.manifest_file import (
    parse_manifest,
    render_null_assignments,
    render_shell_assignments,
    render_shell_assignments_from_mapping,
)


TARGETS_DIR = ROOT_DIR / "runner" / "targets"
SUITES_DIR = ROOT_DIR / "runner" / "suites"
DEFAULT_CORPUS_APP_SUITE = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
REMOTE_COMMAND_ORDER = ("ip", "taskset", "setpriv", "curl", "tar", "dd", "tc", "stress-ng", "fio", "bpftrace", "hackbench", "sysbench", "wrk")

CORPUS_WORKLOAD_KIND_COMMANDS = {
    "exec_storm": ("stress-ng", "setpriv"),
    "hackbench": ("hackbench",),
    "network": ("wrk",),
    "tracee_default": ("setpriv", "wrk"),
    "block_io": ("dd",),
    "oom_stress": ("stress-ng",),
    "tcp_retransmit": ("tc",),
}

CORPUS_RUNNER_EXTRA_COMMANDS = {
    "bcc": ("fio",),
    "bpftrace": ("bpftrace",),
    "tetragon": ("fio",),
}

E2E_CASE_REMOTE_COMMANDS = {
    "bcc": ("ip", "taskset", "setpriv", "curl", "stress-ng", "fio", "dd", "hackbench", "wrk"),
    "bpftrace": ("ip", "taskset", "setpriv", "stress-ng", "fio", "dd", "bpftrace", "tc", "hackbench", "wrk"),
    "katran": ("ip", "taskset", "wrk"),
    "scx": ("ip", "taskset", "stress-ng", "hackbench", "sysbench"),
    "tetragon": ("ip", "taskset", "setpriv", "curl", "tar", "stress-ng", "fio"),
    "tracee": ("ip", "taskset", "setpriv", "curl", "wrk"),
}

_die = partial(fail, "run-contract")


def _load_assignment_file(path: Path) -> dict[str, str]:
    if not path.is_file():
        _die(f"missing required file: {path}")
    parsed = parse_manifest(path)
    data: dict[str, str] = {}
    for key, value in parsed.items():
        if isinstance(value, list):
            _die(f"assignment files must contain only scalar values: {path}")
        data[key] = value
    return data


def _env_or_default(env: dict[str, str], name: str, default: str = "") -> str:
    return env.get(name, "").strip() or default


def _prefixed_env_or_default(env: dict[str, str], prefix: str, suffix: str, default: str = "") -> str:
    return _env_or_default(env, f"{prefix}_{suffix}", default)


def _normalize_csv(raw: str) -> str:
    return "".join(raw.split())


def _resolve_repo_path(path: str) -> str:
    if not path:
        return ""
    candidate = Path(path)
    if candidate.is_absolute():
        return str(candidate)
    return str((ROOT_DIR / candidate).resolve())


def _resolve_manifest_llvm_dir(values: dict[str, str]) -> str:
    explicit_dir = _env_or_default(values, "LLVM_DIR")
    if explicit_dir:
        return _resolve_repo_path(explicit_dir)
    llvm_config = _env_or_default(values, "LLVM_CONFIG")
    if not llvm_config:
        return ""
    completed = subprocess.run(
        [llvm_config, "--cmakedir"],
        check=False,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    if completed.returncode != 0:
        _die(f"LLVM_CONFIG failed to resolve cmake dir: {llvm_config}")
    cmake_dir = completed.stdout.strip()
    if not cmake_dir:
        _die(f"LLVM_CONFIG returned an empty cmake dir: {llvm_config}")
    return cmake_dir


def _host_cpu_count() -> int:
    return max(os.cpu_count() or 1, 1)


def _resolve_cpu_spec(spec: str) -> str:
    if not spec or spec == "auto":
        return str(_host_cpu_count())
    if spec.startswith("auto:"):
        ratio = float(spec.split(":", 1)[1] or "1")
        return str(max(int(_host_cpu_count() * ratio), 1))
    return spec


def _csv_tokens(csv: str) -> list[str]:
    return [token for token in csv.split(",") if token]


def _csv_has(csv: str, token: str) -> bool:
    return token in _csv_tokens(csv)


def _append_csv(csv: str, token: str) -> str:
    if not token or _csv_has(csv, token):
        return csv
    return token if not csv else f"{csv},{token}"


def _append_csv_list(csv: str, extra_csv: str) -> str:
    merged = csv
    for token in _csv_tokens(extra_csv):
        merged = _append_csv(merged, token)
    return merged


def _join_csv(tokens: list[str]) -> str:
    return ",".join(token for token in tokens if token)


def _ordered_csv_from_tokens(tokens: set[str], *, order: tuple[str, ...]) -> str:
    return ",".join(token for token in order if token in tokens)


def _ordered_csv_with_tail(tokens: set[str], *, order: tuple[str, ...]) -> str:
    ordered = [token for token in order if token in tokens]
    ordered.extend(sorted(token for token in tokens if token not in order))
    return ",".join(ordered)


def _corpus_workload_requirements_for_selection(app_suite: object) -> str:
    remote_commands: set[str] = set()
    for app in getattr(app_suite, "apps", ()):
        runner = str(getattr(app, "runner", "") or "").strip()
        workload_kind = str(app.workload_for("corpus") or "").strip()
        remote_commands.update(CORPUS_RUNNER_EXTRA_COMMANDS.get(runner, ()))
        remote_commands.update(CORPUS_WORKLOAD_KIND_COMMANDS.get(workload_kind, ()))
    return _ordered_csv_from_tokens(remote_commands, order=REMOTE_COMMAND_ORDER)


def _apply_corpus_filter_selection(
    *,
    run_corpus_filters: str,
    suite: dict[str, str],
    run_benchmark_repos: str,
    run_native_repos: str,
    run_scx_packages: str,
    run_needs_sched_ext: str,
    run_needs_katran_bundle: str,
) -> tuple[str, str, str, str, str, str]:
    filters = _csv_tokens(run_corpus_filters)
    app_suite, _summary = load_app_suite_from_yaml(DEFAULT_CORPUS_APP_SUITE, filters=filters)
    selected_runners = {app.runner for app in app_suite.apps}
    filtered_benchmark_repos = _join_csv(
        [token for token in _csv_tokens(run_benchmark_repos) if token in selected_runners]
    )
    filtered_native_repos = _join_csv(
        [token for token in _csv_tokens(run_native_repos) if token in selected_runners]
    )
    filtered_scx_packages = suite.get("SUITE_DEFAULT_SCX_PACKAGES", "") if "scx" in selected_runners else ""
    filtered_needs_sched_ext = "1" if "scx" in selected_runners else "0"
    filtered_needs_katran_bundle = "1" if "katran" in selected_runners else "0"
    filtered_remote_commands = _corpus_workload_requirements_for_selection(app_suite)
    return (
        filtered_benchmark_repos,
        filtered_native_repos,
        filtered_scx_packages,
        filtered_needs_sched_ext,
        filtered_needs_katran_bundle,
        filtered_remote_commands,
    )


def _apply_e2e_case_selection(
    *,
    run_e2e_cases: str,
    suite: dict[str, str],
) -> tuple[str, str, str, str, str, str]:
    selected_cases = set(_csv_tokens(run_e2e_cases))
    include_all = "all" in selected_cases
    run_benchmark_repos = _suite_repos_for_e2e_cases(run_e2e_cases)
    run_native_repos = _native_repos_for_e2e_cases(run_e2e_cases)
    run_scx_packages = ""
    run_needs_sched_ext = "0"
    run_needs_katran_bundle = "0"
    remote_commands: set[str] = set()
    for case_name, commands in E2E_CASE_REMOTE_COMMANDS.items():
        if include_all or case_name in selected_cases:
            remote_commands.update(commands)
    if include_all or "scx" in selected_cases:
        run_scx_packages = suite.get("SUITE_DEFAULT_SCX_PACKAGES", "")
        run_needs_sched_ext = "1"
    if include_all or "katran" in selected_cases:
        run_needs_katran_bundle = "1"
    return (
        run_benchmark_repos,
        run_native_repos,
        run_scx_packages,
        run_needs_sched_ext,
        run_needs_katran_bundle,
        _ordered_csv_from_tokens(remote_commands, order=REMOTE_COMMAND_ORDER),
    )


def _remote_transfer_roots(
    *,
    suite: dict[str, str],
    suite_name: str,
    target_arch: str,
    run_needs_daemon_binary: str,
    run_needs_kinsn_modules: str,
    run_repo_artifact_root: str,
    run_libbpf_runtime_path: str,
    run_native_repos: str,
    run_scx_packages: str,
    run_needs_katran_bundle: str,
    executor: str,
) -> str:
    roots: set[str] = set(_csv_tokens(suite.get("SUITE_REMOTE_TRANSFER_ROOTS", "")))
    normalized_roots: set[str] = set()
    for root in roots:
        if root == ".cache/workload-tools":
            normalized_roots.add(f"{root}/{target_arch}")
        else:
            normalized_roots.add(root)
    roots = normalized_roots
    if run_needs_daemon_binary == "1":
        roots.add("daemon")
    if run_needs_kinsn_modules == "1":
        roots.add("module")
    if run_repo_artifact_root:
        if run_libbpf_runtime_path:
            roots.add(f"{run_repo_artifact_root}/libbpf")
        if run_scx_packages:
            roots.add(f"{run_repo_artifact_root}/scx")
        for repo in _csv_tokens(run_native_repos):
            roots.add(f"{run_repo_artifact_root}/{repo}")
        if run_needs_katran_bundle == "1":
            roots.add(f"{run_repo_artifact_root}/katran")
        if executor == "kvm" and run_needs_kinsn_modules == "1":
            roots.add(f"{run_repo_artifact_root}/kernel-modules")
    return _ordered_csv_with_tail(roots, order=("runner", "daemon", "module", "tests", "micro", "corpus", "e2e"))


_COMMON_MANIFEST_INPUTS = {
    "PYTHON",
    "RUN_TOKEN",
    "LLVM_CONFIG",
    "LLVM_DIR",
}

_KVM_MANIFEST_INPUTS = {
    "BZIMAGE",
    "TEST_MODE",
    "SAMPLES",
    "WARMUPS",
    "INNER_REPEAT",
    "FILTERS",
    "VM_CORPUS_ARGS",
    "VM_CORPUS_SAMPLES",
    "VM_CORPUS_WORKLOAD_SECONDS",
    "E2E_CASE",
    "E2E_ARGS",
    "E2E_SMOKE",
    "VM_CPUS",
    "VM_MEM",
    "VM_TEST_TIMEOUT",
    "VM_MICRO_TIMEOUT",
    "VM_CORPUS_TIMEOUT",
    "VM_E2E_TIMEOUT",
    "FUZZ_ROUNDS",
    "SCX_PROG_SHOW_RACE_MODE",
    "SCX_PROG_SHOW_RACE_ITERATIONS",
    "SCX_PROG_SHOW_RACE_LOAD_TIMEOUT",
    "SCX_PROG_SHOW_RACE_SKIP_PROBE",
}

_AWS_MANIFEST_SUFFIXES = {
    "NAME_TAG",
    "INSTANCE_TYPE",
    "REMOTE_USER",
    "REMOTE_STAGE_DIR",
    "REMOTE_KERNEL_STAGE_DIR",
    "AMI_PARAM",
    "AMI_ID",
    "ROOT_VOLUME_GB",
    "REMOTE_SWAP_SIZE_GB",
    "TEST_MODE",
    "BENCH_SAMPLES",
    "BENCH_WARMUPS",
    "BENCH_INNER_REPEAT",
    "CORPUS_FILTERS",
    "CORPUS_ARGS",
    "CORPUS_WORKLOAD_SECONDS",
    "E2E_CASES",
    "E2E_ARGS",
    "E2E_SMOKE",
    "KEY_NAME",
    "KEY_PATH",
    "SECURITY_GROUP_ID",
    "SUBNET_ID",
    "REGION",
    "PROFILE",
}


def _filtered_manifest_inputs(target_name: str, env: dict[str, str] | None) -> dict[str, str]:
    source_env = os.environ if env is None else env
    filtered: dict[str, str] = {}
    allowed = set(_COMMON_MANIFEST_INPUTS)
    if target_name == "x86-kvm":
        allowed.update(_KVM_MANIFEST_INPUTS)
    else:
        target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if aws_env_prefix:
            allowed.update(f"{aws_env_prefix}_{suffix}" for suffix in _AWS_MANIFEST_SUFFIXES)
    for key in allowed:
        value = source_env.get(key)
        if value is not None:
            filtered[key] = value
    return filtered


def _validate_test_mode(mode: str) -> None:
    if mode not in {"selftest", "negative", "test"}:
        _die(f"unsupported test mode: {mode}")


def _validate_e2e_cases(cases_csv: str) -> None:
    if not cases_csv:
        _die("e2e cases must not be empty")
    if cases_csv == "all":
        return
    for token in _csv_tokens(cases_csv):
        if token not in {"tracee", "tetragon", "bpftrace", "scx", "bcc", "katran"}:
            _die(f"unsupported e2e case: {token}")


def _suite_repos_for_e2e_cases(cases_csv: str) -> str:
    if cases_csv == "all":
        return "tracee,tetragon,bpftrace,scx,bcc,katran"
    repos = ""
    for token in _csv_tokens(cases_csv):
        repos = _append_csv(repos, token)
    return repos


def _native_repos_for_e2e_cases(cases_csv: str) -> str:
    if cases_csv == "all":
        return "bcc,katran,tracee,tetragon"
    repos = ""
    for token in _csv_tokens(cases_csv):
        if token in {"bcc", "katran", "tracee", "tetragon"}:
            repos = _append_csv(repos, token)
    return repos


def _build_manifest_mapping(target_name: str, suite_name: str, *, env: dict[str, str] | None = None) -> dict[str, str | list[str]]:
    values = _filtered_manifest_inputs(target_name, env)
    target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
    suite = _load_assignment_file(SUITES_DIR / f"{suite_name}.env")

    run_token = values.get("RUN_TOKEN", "").strip() or f"{target_name}_{suite_name}"
    run_name_tag = ""
    run_instance_type = ""
    run_remote_user = ""
    run_remote_stage_dir = ""
    run_remote_kernel_stage_dir = ""
    run_ami_param = ""
    run_ami_id = ""
    run_root_volume_gb = ""
    run_test_mode = "test"
    run_e2e_cases = "all"
    run_benchmark_repos = suite.get("SUITE_DEFAULT_REPOS", "")
    run_native_repos = suite.get("SUITE_DEFAULT_NATIVE_REPOS", "")
    run_scx_packages = suite.get("SUITE_DEFAULT_SCX_PACKAGES", "")
    run_needs_sched_ext = suite.get("SUITE_NEEDS_SCHED_EXT", "0")
    run_needs_llvmbpf = suite.get("SUITE_NEEDS_LLVMBPF", "0")
    run_llvm_dir = ""
    run_remote_commands = suite.get("SUITE_DEFAULT_REMOTE_COMMANDS", "")
    run_needs_katran_bundle = suite.get("SUITE_NEEDS_KATRAN_BUNDLE", "0")
    run_bpftool_bin = "bpftool"
    run_aws_key_name = ""
    run_aws_key_path = ""
    run_aws_security_group_id = ""
    run_aws_subnet_id = ""
    run_aws_region = ""
    run_aws_profile = ""
    run_remote_swap_size_gb = ""
    run_aws_instance_mode = ""
    run_bench_samples = ""
    run_bench_warmups = ""
    run_bench_inner_repeat = ""
    run_corpus_filters = ""
    run_corpus_args = ""
    run_corpus_workload_seconds = ""
    run_e2e_args = ""
    run_e2e_smoke = ""
    run_vm_backend = ""
    run_vm_executable = ""
    run_vm_lock_scope = ""
    run_vm_machine_name = ""
    run_vm_machine_arch = ""
    run_vm_cpus = ""
    run_vm_mem = ""
    run_host_python_bin = _env_or_default(values, "PYTHON", "python3")
    run_vm_kernel_image = ""
    run_vm_timeout_seconds = suite.get("SUITE_DEFAULT_VM_TIMEOUT_SECONDS", "7200")
    run_remote_python_bin = target.get("TARGET_REMOTE_PYTHON_DEFAULT", suite.get("SUITE_DEFAULT_REMOTE_PYTHON_BIN", ""))
    run_remote_python_modules = "PyYAML"
    run_guest_package_manager = target.get("TARGET_GUEST_PACKAGE_MANAGER", "")
    run_needs_runner_binary = suite.get("SUITE_NEEDS_RUNNER_BINARY", "0")
    run_needs_daemon_binary = suite.get("SUITE_NEEDS_DAEMON_BINARY", "0")
    run_needs_kinsn_modules = suite.get("SUITE_NEEDS_KINSN_MODULES", "0")
    run_test_fuzz_rounds = ""
    run_test_scx_prog_show_race_mode = ""
    run_test_scx_prog_show_race_iterations = ""
    run_test_scx_prog_show_race_load_timeout = ""
    run_test_scx_prog_show_race_skip_probe = ""
    run_corpus_argv: list[str] = []
    run_e2e_argv: list[str] = []
    run_repo_artifact_root = f".cache/repo-artifacts/{target.get('TARGET_ARCH', '')}"
    run_libbpf_runtime_path = ""
    run_daemon_binary_path = ""
    run_runner_binary_path = ""
    run_test_unittest_build_dir = ""
    run_test_negative_build_dir = ""
    run_kinsn_module_dir = ""
    run_remote_transfer_roots = ""

    if target.get("TARGET_EXECUTOR", "") == "aws-ssh":
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if not aws_env_prefix:
            _die(f"AWS target {target_name} is missing TARGET_AWS_ENV_PREFIX")
        run_aws_instance_mode = _prefixed_env_or_default(values, aws_env_prefix, "INSTANCE_MODE", "shared")
        run_name_tag = _prefixed_env_or_default(values, aws_env_prefix, "NAME_TAG", target.get("TARGET_NAME_TAG_DEFAULT", ""))
        default_instance_type = target.get("TARGET_INSTANCE_TYPE_DEFAULT", "")
        if suite.get("SUITE_VM_CLASS", "") == "benchmark":
            default_instance_type = target.get("TARGET_BENCH_INSTANCE_TYPE_DEFAULT", default_instance_type)
        else:
            default_instance_type = target.get("TARGET_TEST_INSTANCE_TYPE_DEFAULT", default_instance_type)
        run_instance_type = _prefixed_env_or_default(values, aws_env_prefix, "INSTANCE_TYPE", default_instance_type)
        run_remote_user = _prefixed_env_or_default(values, aws_env_prefix, "REMOTE_USER", target.get("TARGET_REMOTE_USER_DEFAULT", ""))
        remote_stage_root = _prefixed_env_or_default(values, aws_env_prefix, "REMOTE_STAGE_DIR", target.get("TARGET_REMOTE_STAGE_DIR_DEFAULT", ""))
        run_remote_stage_dir = remote_stage_root.rstrip("/")
        if suite_name:
            run_remote_stage_dir = f"{run_remote_stage_dir}/{suite_name}"
        run_remote_kernel_stage_dir = _prefixed_env_or_default(values, aws_env_prefix, "REMOTE_KERNEL_STAGE_DIR", target.get("TARGET_REMOTE_KERNEL_STAGE_DIR_DEFAULT", ""))
        run_ami_param = _prefixed_env_or_default(values, aws_env_prefix, "AMI_PARAM", target.get("TARGET_AMI_PARAM_DEFAULT", ""))
        run_ami_id = _prefixed_env_or_default(values, aws_env_prefix, "AMI_ID")
        run_root_volume_gb = _prefixed_env_or_default(values, aws_env_prefix, "ROOT_VOLUME_GB", target.get("TARGET_ROOT_VOLUME_GB_DEFAULT", ""))
        run_remote_swap_size_gb = _prefixed_env_or_default(values, aws_env_prefix, "REMOTE_SWAP_SIZE_GB", target.get("TARGET_REMOTE_SWAP_SIZE_GB_DEFAULT", "8"))
        run_test_mode = _prefixed_env_or_default(values, aws_env_prefix, "TEST_MODE", "test").lower()
        run_bench_samples = _prefixed_env_or_default(values, aws_env_prefix, "BENCH_SAMPLES", "1")
        run_bench_warmups = _prefixed_env_or_default(values, aws_env_prefix, "BENCH_WARMUPS", "0")
        run_bench_inner_repeat = _prefixed_env_or_default(values, aws_env_prefix, "BENCH_INNER_REPEAT", "10")
        run_corpus_filters = _normalize_csv(_prefixed_env_or_default(values, aws_env_prefix, "CORPUS_FILTERS", ""))
        run_corpus_args = _prefixed_env_or_default(values, aws_env_prefix, "CORPUS_ARGS", "")
        run_corpus_workload_seconds = _prefixed_env_or_default(values, aws_env_prefix, "CORPUS_WORKLOAD_SECONDS", "")
        run_e2e_cases = _normalize_csv(_prefixed_env_or_default(values, aws_env_prefix, "E2E_CASES", suite.get("SUITE_DEFAULT_E2E_CASES", "all")))
        run_e2e_args = _prefixed_env_or_default(values, aws_env_prefix, "E2E_ARGS", "")
        run_e2e_smoke = _prefixed_env_or_default(values, aws_env_prefix, "E2E_SMOKE", "0")
        run_aws_key_path = _prefixed_env_or_default(values, aws_env_prefix, "KEY_PATH")
        if not run_aws_key_path:
            _die(f"{aws_env_prefix}_KEY_PATH is required for AWS targets")
        run_aws_key_name = _prefixed_env_or_default(values, aws_env_prefix, "KEY_NAME")
        if not run_aws_key_name:
            run_aws_key_name = Path(run_aws_key_path).stem
        if not run_aws_key_name:
            _die(f"{aws_env_prefix}_KEY_NAME could not be derived from {aws_env_prefix}_KEY_PATH")
        run_aws_security_group_id = _prefixed_env_or_default(values, aws_env_prefix, "SECURITY_GROUP_ID")
        if not run_aws_security_group_id:
            _die(f"{aws_env_prefix}_SECURITY_GROUP_ID is required for AWS targets")
        run_aws_subnet_id = _prefixed_env_or_default(values, aws_env_prefix, "SUBNET_ID")
        if not run_aws_subnet_id:
            _die(f"{aws_env_prefix}_SUBNET_ID is required for AWS targets")
        run_aws_region = _prefixed_env_or_default(values, aws_env_prefix, "REGION", target.get("TARGET_AWS_REGION_DEFAULT", ""))
        if not run_aws_region:
            _die(f"{aws_env_prefix}_REGION is required for AWS targets")
        run_aws_profile = _prefixed_env_or_default(values, aws_env_prefix, "PROFILE")
        if not run_aws_profile:
            _die(f"{aws_env_prefix}_PROFILE is required for AWS targets")
    elif target_name == "x86-kvm":
        run_vm_backend = target.get("TARGET_KVM_BACKEND", "")
        run_vm_executable = target.get("TARGET_KVM_EXECUTABLE", "")
        run_vm_lock_scope = target.get("TARGET_KVM_LOCK_SCOPE", "")
        run_vm_machine_name = target.get("TARGET_NAME", target_name)
        run_vm_machine_arch = target.get("TARGET_ARCH", "")
        run_host_python_bin = _env_or_default(values, "PYTHON", target.get("TARGET_KVM_HOST_PYTHON_DEFAULT", "python3"))
        run_vm_kernel_image = _resolve_repo_path(_env_or_default(values, "BZIMAGE", target.get("TARGET_KVM_KERNEL_IMAGE_DEFAULT", "vendor/linux-framework/arch/x86/boot/bzImage")))
        if not run_vm_backend:
            _die("x86-kvm target is missing TARGET_KVM_BACKEND")
        if not run_vm_executable:
            _die("x86-kvm target is missing TARGET_KVM_EXECUTABLE")
        if not run_vm_lock_scope:
            _die("x86-kvm target is missing TARGET_KVM_LOCK_SCOPE")
        if not Path(run_vm_executable).is_absolute():
            run_vm_executable = str((ROOT_DIR / run_vm_executable).resolve())
        run_test_mode = _env_or_default(values, "TEST_MODE", "test")
        run_bench_samples = _env_or_default(values, "SAMPLES", "1")
        run_bench_warmups = _env_or_default(values, "WARMUPS", "0")
        run_bench_inner_repeat = _env_or_default(values, "INNER_REPEAT", "10")
        run_corpus_filters = _normalize_csv(_env_or_default(values, "FILTERS", ""))
        run_corpus_args = _env_or_default(values, "VM_CORPUS_ARGS", "")
        run_corpus_workload_seconds = _env_or_default(values, "VM_CORPUS_WORKLOAD_SECONDS", "")
        run_e2e_cases = _normalize_csv(_env_or_default(values, "E2E_CASE", "all"))
        run_e2e_args = _env_or_default(values, "E2E_ARGS", "")
        run_e2e_smoke = _env_or_default(values, "E2E_SMOKE", "0")
        suite_vm_class = suite.get("SUITE_VM_CLASS", "")
        if suite_vm_class == "test":
            run_vm_cpus = _env_or_default(values, "VM_CPUS", _resolve_cpu_spec(target.get("TARGET_KVM_TEST_CPUS_SPEC", "auto:0.8")))
            run_vm_mem = _env_or_default(values, "VM_MEM", target.get("TARGET_KVM_TEST_MEM", "16G"))
        elif suite_vm_class == "benchmark":
            run_vm_cpus = _env_or_default(values, "VM_CPUS", _resolve_cpu_spec(target.get("TARGET_KVM_BENCH_CPUS_SPEC", "4")))
            run_vm_mem = _env_or_default(values, "VM_MEM", target.get("TARGET_KVM_BENCH_MEM", "16G"))
        elif suite_vm_class:
            _die(f"unsupported KVM suite class: {suite_vm_class}")
    else:
        _die(f"unsupported target: {target_name}")

    if suite_name == "test":
        run_vm_timeout_seconds = _env_or_default(values, "VM_TEST_TIMEOUT", run_vm_timeout_seconds)
        run_test_fuzz_rounds = _env_or_default(values, "FUZZ_ROUNDS", suite.get("SUITE_DEFAULT_FUZZ_ROUNDS", "1000"))
        run_test_scx_prog_show_race_mode = _env_or_default(values, "SCX_PROG_SHOW_RACE_MODE", suite.get("SUITE_DEFAULT_SCX_PROG_SHOW_RACE_MODE", "bpftool-loop"))
        run_test_scx_prog_show_race_iterations = _env_or_default(values, "SCX_PROG_SHOW_RACE_ITERATIONS", suite.get("SUITE_DEFAULT_SCX_PROG_SHOW_RACE_ITERATIONS", "20"))
        run_test_scx_prog_show_race_load_timeout = _env_or_default(values, "SCX_PROG_SHOW_RACE_LOAD_TIMEOUT", suite.get("SUITE_DEFAULT_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT", "20"))
        run_test_scx_prog_show_race_skip_probe = _env_or_default(values, "SCX_PROG_SHOW_RACE_SKIP_PROBE", suite.get("SUITE_DEFAULT_SCX_PROG_SHOW_RACE_SKIP_PROBE", "0"))
    elif suite_name == "micro":
        run_vm_timeout_seconds = _env_or_default(values, "VM_MICRO_TIMEOUT", run_vm_timeout_seconds)
    elif suite_name == "corpus":
        run_vm_timeout_seconds = _env_or_default(values, "VM_CORPUS_TIMEOUT", run_vm_timeout_seconds)
    elif suite_name == "e2e":
        run_vm_timeout_seconds = _env_or_default(values, "VM_E2E_TIMEOUT", run_vm_timeout_seconds)

    _validate_test_mode(run_test_mode)
    if not run_remote_python_bin:
        _die(f"suite {suite_name} is missing remote python contract")
    if not run_bpftool_bin:
        _die(f"suite {suite_name} is missing RUN_BPFTOOL_BIN")
    run_corpus_argv = shlex.split(run_corpus_args)
    run_e2e_argv = shlex.split(run_e2e_args)

    if suite_name == "test":
        run_benchmark_repos = ""
        run_native_repos = ""
        if run_test_mode == "selftest":
            run_scx_packages = ""
            run_needs_sched_ext = "0"
        elif run_test_mode == "negative":
            run_needs_daemon_binary = "0"
            run_needs_kinsn_modules = "0"
        elif run_test_mode != "test":
            _die(f"unsupported test mode: {run_test_mode}")
    elif suite_name == "micro":
        run_benchmark_repos = ""
        run_native_repos = ""
        run_scx_packages = ""
    elif suite_name == "corpus":
        if target_name == "x86-kvm" and not values.get("SAMPLES", "").strip():
            run_bench_samples = _env_or_default(values, "VM_CORPUS_SAMPLES", "30")
        (
            run_benchmark_repos,
            run_native_repos,
            run_scx_packages,
            run_needs_sched_ext,
            run_needs_katran_bundle,
            corpus_remote_commands,
        ) = _apply_corpus_filter_selection(
            run_corpus_filters=run_corpus_filters,
            suite=suite,
            run_benchmark_repos=run_benchmark_repos,
            run_native_repos=run_native_repos,
            run_scx_packages=run_scx_packages,
            run_needs_sched_ext=run_needs_sched_ext,
            run_needs_katran_bundle=run_needs_katran_bundle,
        )
        run_remote_commands = _append_csv_list(run_remote_commands, corpus_remote_commands)
    elif suite_name == "e2e":
        if not run_e2e_cases:
            run_e2e_cases = suite.get("SUITE_DEFAULT_E2E_CASES", "all")
        _validate_e2e_cases(run_e2e_cases)
        (
            run_benchmark_repos,
            run_native_repos,
            run_scx_packages,
            run_needs_sched_ext,
            run_needs_katran_bundle,
            run_remote_commands,
        ) = _apply_e2e_case_selection(
            run_e2e_cases=run_e2e_cases,
            suite=suite,
        )
        run_remote_commands = _append_csv_list(suite.get("SUITE_DEFAULT_REMOTE_COMMANDS", ""), run_remote_commands)
    else:
        _die(f"unsupported suite: {suite_name}")

    if run_needs_sched_ext == "1" and target.get("TARGET_SUPPORTS_SCHED_EXT", "0") != "1":
        _die(f"target {target_name} does not support required sched_ext for suite {suite_name}")

    run_needs_workload_tools = suite.get("SUITE_NEEDS_WORKLOAD_TOOLS", "0")
    if run_needs_llvmbpf == "1":
        run_llvm_dir = _resolve_manifest_llvm_dir(values)
        if not run_llvm_dir:
            _die(f"suite {suite_name} requires explicit LLVM_DIR or LLVM_CONFIG")

    if suite_name in {"test", "corpus", "e2e"}:
        run_libbpf_runtime_path = f"{run_repo_artifact_root}/libbpf/lib/libbpf.so"
    if target.get("TARGET_ARCH", "") == "arm64":
        run_daemon_binary_path = "daemon/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon"
        run_runner_binary_path = "runner/build-arm64/micro_exec"
        run_test_unittest_build_dir = "tests/unittest/build-arm64"
        run_test_negative_build_dir = "tests/negative/build-arm64"
        run_kinsn_module_dir = "module/arm64"
    else:
        run_daemon_binary_path = "daemon/target/release/bpfrejit-daemon"
        run_runner_binary_path = "runner/build/micro_exec"
        run_test_unittest_build_dir = "tests/unittest/build"
        run_test_negative_build_dir = "tests/negative/build"
        run_kinsn_module_dir = "module/x86"
    if target.get("TARGET_EXECUTOR", "") == "kvm":
        run_kernel_modules_root = f"{run_repo_artifact_root}/kernel-modules"
    else:
        run_kernel_modules_root = "/"
    run_remote_transfer_roots = _remote_transfer_roots(
        suite=suite,
        suite_name=suite_name,
        target_arch=target.get("TARGET_ARCH", ""),
        run_needs_daemon_binary=run_needs_daemon_binary,
        run_needs_kinsn_modules=run_needs_kinsn_modules,
        run_repo_artifact_root=run_repo_artifact_root,
        run_libbpf_runtime_path=run_libbpf_runtime_path,
        run_native_repos=run_native_repos,
        run_scx_packages=run_scx_packages,
        run_needs_katran_bundle=run_needs_katran_bundle,
        executor=target.get("TARGET_EXECUTOR", ""),
    )
    return {
        "RUN_TARGET_NAME": target_name,
        "RUN_TARGET_ARCH": target.get("TARGET_ARCH", ""),
        "RUN_EXECUTOR": target.get("TARGET_EXECUTOR", ""),
        "RUN_SUITE_NAME": suite_name,
        "RUN_TOKEN": run_token,
        "RUN_SUITE_NEEDS_RUNTIME_BTF": suite.get("SUITE_NEEDS_RUNTIME_BTF", "0"),
        "RUN_SUITE_NEEDS_SCHED_EXT": run_needs_sched_ext,
        "RUN_SUITE_NEEDS_LLVMBPF": run_needs_llvmbpf,
        "RUN_LLVM_DIR": run_llvm_dir,
        "RUN_NEEDS_RUNNER_BINARY": run_needs_runner_binary,
        "RUN_NEEDS_DAEMON_BINARY": run_needs_daemon_binary,
        "RUN_NEEDS_KINSN_MODULES": run_needs_kinsn_modules,
        "RUN_NEEDS_WORKLOAD_TOOLS": run_needs_workload_tools,
        "RUN_NAME_TAG": run_name_tag,
        "RUN_INSTANCE_TYPE": run_instance_type,
        "RUN_REMOTE_USER": run_remote_user,
        "RUN_REMOTE_STAGE_DIR": run_remote_stage_dir,
        "RUN_REMOTE_KERNEL_STAGE_DIR": run_remote_kernel_stage_dir,
        "RUN_AMI_PARAM": run_ami_param,
        "RUN_AMI_ID": run_ami_id,
        "RUN_ROOT_VOLUME_GB": run_root_volume_gb,
        "RUN_REMOTE_SWAP_SIZE_GB": run_remote_swap_size_gb,
        "RUN_AWS_KEY_NAME": run_aws_key_name,
        "RUN_AWS_KEY_PATH": run_aws_key_path,
        "RUN_AWS_SECURITY_GROUP_ID": run_aws_security_group_id,
        "RUN_AWS_SUBNET_ID": run_aws_subnet_id,
        "RUN_AWS_REGION": run_aws_region,
        "RUN_AWS_PROFILE": run_aws_profile,
        "RUN_AWS_INSTANCE_MODE": run_aws_instance_mode,
        "RUN_VM_BACKEND": run_vm_backend,
        "RUN_VM_EXECUTABLE": run_vm_executable,
        "RUN_VM_LOCK_SCOPE": run_vm_lock_scope,
        "RUN_VM_MACHINE_NAME": run_vm_machine_name,
        "RUN_VM_MACHINE_ARCH": run_vm_machine_arch,
        "RUN_VM_CPUS": run_vm_cpus,
        "RUN_VM_MEM": run_vm_mem,
        "RUN_HOST_PYTHON_BIN": run_host_python_bin,
        "RUN_VM_KERNEL_IMAGE": run_vm_kernel_image,
        "RUN_VM_TIMEOUT_SECONDS": run_vm_timeout_seconds,
        "RUN_REMOTE_PYTHON_BIN": run_remote_python_bin,
        "RUN_REMOTE_PYTHON_MODULES_CSV": run_remote_python_modules,
        "RUN_GUEST_PACKAGE_MANAGER": run_guest_package_manager,
        "RUN_TEST_MODE": run_test_mode,
        "RUN_TEST_FUZZ_ROUNDS": run_test_fuzz_rounds,
        "RUN_TEST_SCX_PROG_SHOW_RACE_MODE": run_test_scx_prog_show_race_mode,
        "RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS": run_test_scx_prog_show_race_iterations,
        "RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT": run_test_scx_prog_show_race_load_timeout,
        "RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE": run_test_scx_prog_show_race_skip_probe,
        "RUN_BENCH_SAMPLES": run_bench_samples,
        "RUN_BENCH_WARMUPS": run_bench_warmups,
        "RUN_BENCH_INNER_REPEAT": run_bench_inner_repeat,
        "RUN_CORPUS_FILTERS": run_corpus_filters,
        "RUN_CORPUS_WORKLOAD_SECONDS": run_corpus_workload_seconds,
        "RUN_E2E_CASES": run_e2e_cases,
        "RUN_E2E_SMOKE": run_e2e_smoke,
        "RUN_NATIVE_REPOS_CSV": run_native_repos,
        "RUN_SCX_PACKAGES_CSV": run_scx_packages,
        "RUN_REPO_ARTIFACT_ROOT": run_repo_artifact_root,
        "RUN_REMOTE_COMMANDS_CSV": run_remote_commands,
        "RUN_LIBBPF_RUNTIME_PATH": run_libbpf_runtime_path,
        "RUN_DAEMON_BINARY_PATH": run_daemon_binary_path,
        "RUN_RUNNER_BINARY_PATH": run_runner_binary_path,
        "RUN_TEST_UNITTEST_BUILD_DIR": run_test_unittest_build_dir,
        "RUN_TEST_NEGATIVE_BUILD_DIR": run_test_negative_build_dir,
        "RUN_KINSN_MODULE_DIR": run_kinsn_module_dir,
        "RUN_KERNEL_MODULES_ROOT": run_kernel_modules_root,
        "RUN_REMOTE_TRANSFER_ROOTS_CSV": run_remote_transfer_roots,
        "RUN_NEEDS_KATRAN_BUNDLE": run_needs_katran_bundle,
        "RUN_BPFTOOL_BIN": run_bpftool_bin,
        "RUN_CORPUS_ARGV": run_corpus_argv,
        "RUN_E2E_ARGV": run_e2e_argv,
    }


def build_manifest(target_name: str, suite_name: str, *, env: dict[str, str] | None = None) -> dict[str, str | list[str]]:
    return _build_manifest_mapping(target_name, suite_name, env=env)


def build_target_manifest(target_name: str, *, env: dict[str, str] | None = None) -> dict[str, str | list[str]]:
    values = _filtered_manifest_inputs(target_name, env)
    target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
    run_token = values.get("RUN_TOKEN", "").strip() or f"target_{target_name}"
    run_name_tag = ""
    run_aws_region = ""
    run_aws_profile = ""
    run_guest_package_manager = target.get("TARGET_GUEST_PACKAGE_MANAGER", "")
    if target.get("TARGET_EXECUTOR", "") == "aws-ssh":
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if not aws_env_prefix:
            _die(f"AWS target {target_name} is missing TARGET_AWS_ENV_PREFIX")
        run_name_tag = _prefixed_env_or_default(values, aws_env_prefix, "NAME_TAG", target.get("TARGET_NAME_TAG_DEFAULT", ""))
        run_aws_region = _prefixed_env_or_default(values, aws_env_prefix, "REGION", target.get("TARGET_AWS_REGION_DEFAULT", ""))
        if not run_aws_region:
            _die(f"{aws_env_prefix}_REGION is required for AWS targets")
        run_aws_profile = _prefixed_env_or_default(values, aws_env_prefix, "PROFILE")
        if not run_aws_profile:
            _die(f"{aws_env_prefix}_PROFILE is required for AWS targets")
    return {
        "RUN_TARGET_NAME": target_name,
        "RUN_TARGET_ARCH": target.get("TARGET_ARCH", ""),
        "RUN_EXECUTOR": target.get("TARGET_EXECUTOR", ""),
        "RUN_TOKEN": run_token,
        "RUN_NAME_TAG": run_name_tag,
        "RUN_AWS_REGION": run_aws_region,
        "RUN_AWS_PROFILE": run_aws_profile,
        "RUN_GUEST_PACKAGE_MANAGER": run_guest_package_manager,
    }


def write_manifest_file(path: Path, values: dict[str, str | list[str]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(render_shell_assignments_from_mapping(values) + "\n", encoding="utf-8")


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args:
        _die("usage: python -m runner.libs.run_contract <export|write-manifest|write-target-manifest> ...")
    action = args[0]
    if action == "export":
        if len(args) != 2:
            _die("usage: python -m runner.libs.run_contract export <manifest_path>")
        print(render_shell_assignments(Path(args[1]).resolve()))
        return
    if action == "export0":
        if len(args) != 2:
            _die("usage: python -m runner.libs.run_contract export0 <manifest_path>")
        sys.stdout.buffer.write(render_null_assignments(Path(args[1]).resolve()))
        return
    if action == "write-manifest":
        if len(args) != 4:
            _die("usage: python -m runner.libs.run_contract write-manifest <target> <suite> <manifest_path>")
        write_manifest_file(Path(args[3]).resolve(), build_manifest(args[1], args[2]))
        return
    if action == "write-target-manifest":
        if len(args) != 3:
            _die("usage: python -m runner.libs.run_contract write-target-manifest <target> <manifest_path>")
        write_manifest_file(Path(args[2]).resolve(), build_target_manifest(args[1]))
        return
    _die(f"unsupported action: {action}")


if __name__ == "__main__":
    main()
