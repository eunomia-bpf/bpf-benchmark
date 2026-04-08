from __future__ import annotations

import os
import re
import shlex
import sys
from pathlib import Path

from runner.libs import ROOT_DIR


TARGETS_DIR = ROOT_DIR / "runner" / "targets"
SUITES_DIR = ROOT_DIR / "runner" / "suites"

SCALAR_PATTERN = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)=(.*)$")
ARRAY_PATTERN = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)=\((.*)\)$")


def _die(message: str) -> "NoReturn":
    print(f"[run-contract][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def parse_manifest(manifest_path: Path) -> dict[str, str | list[str]]:
    parsed: dict[str, str | list[str]] = {}
    for raw_line in manifest_path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        array_match = ARRAY_PATTERN.match(line)
        if array_match:
            name, raw_value = array_match.groups()
            parsed[name] = shlex.split(raw_value)
            continue
        scalar_match = SCALAR_PATTERN.match(line)
        if scalar_match:
            name, raw_value = scalar_match.groups()
            values = shlex.split(raw_value)
            parsed[name] = values[0] if values else ""
            continue
        raise RuntimeError(f"unsupported manifest line: {raw_line}")
    return parsed


def load_manifest_environment(manifest_path: Path) -> dict[str, str | list[str]]:
    parsed = parse_manifest(manifest_path)
    for name, value in parsed.items():
        os.environ[name] = shlex.join(value) if isinstance(value, list) else value
    return parsed


def render_shell_assignments(manifest_path: Path) -> str:
    return render_shell_assignments_from_mapping(parse_manifest(manifest_path))


def render_shell_assignments_from_mapping(values: dict[str, str | list[str]]) -> str:
    lines: list[str] = []
    for name, value in values.items():
        if isinstance(value, list):
            rendered = " ".join(shlex.quote(token) for token in value)
            lines.append(f"{name}=( {rendered} )")
        else:
            lines.append(f"{name}={shlex.quote(value)}")
    return "\n".join(lines)


def render_null_assignments_from_mapping(values: dict[str, str | list[str]]) -> bytes:
    parts: list[bytes] = []
    for name, value in values.items():
        scalar = shlex.join(value) if isinstance(value, list) else value
        parts.append(f"{name}={scalar}".encode("utf-8") + b"\0")
    return b"".join(parts)


def render_null_assignments(manifest_path: Path) -> bytes:
    return render_null_assignments_from_mapping(parse_manifest(manifest_path))


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
    values = dict(os.environ if env is None else env)
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
    run_bundled_repos = ""
    run_fetch_repos = ""
    run_native_repos = suite.get("SUITE_DEFAULT_NATIVE_REPOS", "")
    run_scx_packages = suite.get("SUITE_DEFAULT_SCX_PACKAGES", "")
    run_needs_sched_ext = suite.get("SUITE_NEEDS_SCHED_EXT", "0")
    run_needs_llvmbpf = suite.get("SUITE_NEEDS_LLVMBPF", "0")
    run_remote_commands = suite.get("SUITE_DEFAULT_REMOTE_COMMANDS", "")
    run_workload_tools = suite.get("SUITE_DEFAULT_WORKLOAD_TOOLS", "")
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
    run_upstream_selftest_llvm_suffix = ""
    run_upstream_test_progs_filters = ""
    run_upstream_test_progs_deny = ""
    run_corpus_argv: list[str] = []
    run_e2e_argv: list[str] = []

    if target.get("TARGET_EXECUTOR", "") == "aws-ssh":
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if not aws_env_prefix:
            _die(f"AWS target {target_name} is missing TARGET_AWS_ENV_PREFIX")
        run_aws_instance_mode = "dedicated" if suite.get("SUITE_VM_CLASS", "") == "benchmark" else "shared"
        run_name_tag = _prefixed_env_or_default(values, aws_env_prefix, "NAME_TAG", target.get("TARGET_NAME_TAG_DEFAULT", ""))
        run_instance_type = _prefixed_env_or_default(values, aws_env_prefix, "INSTANCE_TYPE", target.get("TARGET_INSTANCE_TYPE_DEFAULT", ""))
        run_remote_user = _prefixed_env_or_default(values, aws_env_prefix, "REMOTE_USER", target.get("TARGET_REMOTE_USER_DEFAULT", ""))
        run_remote_stage_dir = _prefixed_env_or_default(values, aws_env_prefix, "REMOTE_STAGE_DIR", target.get("TARGET_REMOTE_STAGE_DIR_DEFAULT", ""))
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
        run_aws_key_name = _prefixed_env_or_default(values, aws_env_prefix, "KEY_NAME")
        if not run_aws_key_name:
            _die(f"{aws_env_prefix}_KEY_NAME is required for AWS targets")
        run_aws_key_path = _prefixed_env_or_default(values, aws_env_prefix, "KEY_PATH")
        if not run_aws_key_path:
            _die(f"{aws_env_prefix}_KEY_PATH is required for AWS targets")
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
        run_upstream_selftest_llvm_suffix = _env_or_default(values, "UPSTREAM_SELFTEST_LLVM_SUFFIX", suite.get("SUITE_DEFAULT_UPSTREAM_SELFTEST_LLVM_SUFFIX", "-20"))
        run_upstream_test_progs_filters = _normalize_csv(
            _env_or_default(
                values,
                "UPSTREAM_TEST_PROGS_FILTERS",
                suite.get("SUITE_DEFAULT_UPSTREAM_TEST_PROGS_FILTERS", "verifier,jit"),
            )
        )
        run_upstream_test_progs_deny = _normalize_csv(
            _env_or_default(
                values,
                "UPSTREAM_TEST_PROGS_DENY",
                suite.get("SUITE_DEFAULT_UPSTREAM_TEST_PROGS_DENY", "verifier_private_stack"),
            )
        )
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
        run_workload_tools = ""
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
        run_workload_tools = ""
    elif suite_name == "corpus":
        if target_name == "x86-kvm" and not values.get("SAMPLES", "").strip():
            run_bench_samples = _env_or_default(values, "VM_CORPUS_SAMPLES", "30")
    elif suite_name == "e2e":
        if not run_e2e_cases:
            run_e2e_cases = suite.get("SUITE_DEFAULT_E2E_CASES", "all")
        _validate_e2e_cases(run_e2e_cases)
        run_benchmark_repos = _suite_repos_for_e2e_cases(run_e2e_cases)
        run_native_repos = _native_repos_for_e2e_cases(run_e2e_cases)
        run_scx_packages = ""
        if _csv_has(run_e2e_cases, "all") or _csv_has(run_e2e_cases, "scx"):
            run_scx_packages = suite.get("SUITE_DEFAULT_SCX_PACKAGES", "")
            run_needs_sched_ext = "1"
            run_workload_tools = _append_csv_list(run_workload_tools, suite.get("SUITE_E2E_SCX_WORKLOAD_TOOLS", ""))
        else:
            run_needs_sched_ext = "0"
        if _csv_has(run_e2e_cases, "all") or _csv_has(run_e2e_cases, "tracee"):
            run_workload_tools = _append_csv_list(run_workload_tools, suite.get("SUITE_E2E_TRACEE_WORKLOAD_TOOLS", ""))
        if _csv_has(run_e2e_cases, "all") or _csv_has(run_e2e_cases, "bpftrace"):
            run_workload_tools = _append_csv_list(run_workload_tools, suite.get("SUITE_E2E_BPFTRACE_WORKLOAD_TOOLS", ""))
        if _csv_has(run_e2e_cases, "all") or _csv_has(run_e2e_cases, "katran"):
            run_needs_katran_bundle = "1"
    else:
        _die(f"unsupported suite: {suite_name}")

    if run_needs_sched_ext == "1" and target.get("TARGET_SUPPORTS_SCHED_EXT", "0") != "1":
        _die(f"target {target_name} does not support required sched_ext for suite {suite_name}")

    run_bundled_repos = run_benchmark_repos
    run_fetch_repos = _append_csv_list(run_bundled_repos, run_native_repos)

    return {
        "RUN_TARGET_NAME": target_name,
        "RUN_TARGET_ARCH": target.get("TARGET_ARCH", ""),
        "RUN_EXECUTOR": target.get("TARGET_EXECUTOR", ""),
        "RUN_SUITE_NAME": suite_name,
        "RUN_TOKEN": run_token,
        "RUN_SUITE_NEEDS_RUNTIME_BTF": suite.get("SUITE_NEEDS_RUNTIME_BTF", "0"),
        "RUN_SUITE_NEEDS_SCHED_EXT": run_needs_sched_ext,
        "RUN_SUITE_NEEDS_LLVMBPF": run_needs_llvmbpf,
        "RUN_NEEDS_RUNNER_BINARY": run_needs_runner_binary,
        "RUN_NEEDS_DAEMON_BINARY": run_needs_daemon_binary,
        "RUN_NEEDS_KINSN_MODULES": run_needs_kinsn_modules,
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
        "RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX": run_upstream_selftest_llvm_suffix,
        "RUN_UPSTREAM_TEST_PROGS_FILTERS": run_upstream_test_progs_filters,
        "RUN_UPSTREAM_TEST_PROGS_DENY": run_upstream_test_progs_deny,
        "RUN_BENCH_SAMPLES": run_bench_samples,
        "RUN_BENCH_WARMUPS": run_bench_warmups,
        "RUN_BENCH_INNER_REPEAT": run_bench_inner_repeat,
        "RUN_CORPUS_FILTERS": run_corpus_filters,
        "RUN_CORPUS_WORKLOAD_SECONDS": run_corpus_workload_seconds,
        "RUN_E2E_CASES": run_e2e_cases,
        "RUN_E2E_SMOKE": run_e2e_smoke,
        "RUN_BUNDLED_REPOS_CSV": run_bundled_repos,
        "RUN_FETCH_REPOS_CSV": run_fetch_repos,
        "RUN_NATIVE_REPOS_CSV": run_native_repos,
        "RUN_SCX_PACKAGES_CSV": run_scx_packages,
        "RUN_REMOTE_COMMANDS_CSV": run_remote_commands,
        "RUN_WORKLOAD_TOOLS_CSV": run_workload_tools,
        "RUN_NEEDS_KATRAN_BUNDLE": run_needs_katran_bundle,
        "RUN_BPFTOOL_BIN": run_bpftool_bin,
        "RUN_CORPUS_ARGV": run_corpus_argv,
        "RUN_E2E_ARGV": run_e2e_argv,
    }


def build_manifest(target_name: str, suite_name: str, *, env: dict[str, str] | None = None) -> dict[str, str | list[str]]:
    return _build_manifest_mapping(target_name, suite_name, env=env)


def build_target_manifest(target_name: str, *, env: dict[str, str] | None = None) -> dict[str, str | list[str]]:
    values = dict(os.environ if env is None else env)
    target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
    run_token = values.get("RUN_TOKEN", "").strip() or f"target_{target_name}"
    run_name_tag = ""
    run_aws_region = ""
    run_aws_profile = ""
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
