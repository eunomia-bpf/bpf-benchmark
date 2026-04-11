from __future__ import annotations

import json
import importlib
import os
import shlex
import subprocess
import sys
from dataclasses import dataclass
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.app_suite_schema import load_app_suite_from_yaml
from runner.libs.cli_support import fail
from runner.libs.state_file import write_json_object


TARGETS_DIR = ROOT_DIR / "runner" / "targets"
SUITES_DIR = ROOT_DIR / "runner" / "suites"
DEFAULT_CORPUS_APP_SUITE = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
DEFAULT_BUILD_CONTAINER_LLVM_DIR = "/usr/lib64/llvm20/lib64/cmake/llvm"
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

_die = partial(fail, "run-contract")

_RUNNER_CLASS_PATHS: dict[str, str] = {
    "bcc": "runner.libs.app_runners.bcc.BCCRunner",
    "bpftrace": "runner.libs.app_runners.bpftrace.BpftraceRunner",
    "katran": "runner.libs.app_runners.katran.KatranRunner",
    "scx": "runner.libs.app_runners.scx.ScxRunner",
    "tetragon": "runner.libs.app_runners.tetragon.TetragonRunner",
    "tracee": "runner.libs.app_runners.tracee.TraceeRunner",
}


@dataclass(frozen=True)
class RunIdentity:
    target_name: str
    target_arch: str
    executor: str
    suite_name: str
    token: str


@dataclass(frozen=True)
class SuiteRequirements:
    needs_runtime_btf: str = "0"
    needs_sched_ext: str = "0"
    needs_llvmbpf: str = "0"
    llvm_dir: str = ""


@dataclass(frozen=True)
class ArtifactRequirements:
    needs_runner_binary: str = "0"
    needs_daemon_binary: str = "0"
    needs_kinsn_modules: str = "0"
    needs_workload_tools: str = "0"
    native_repos: tuple[str, ...] = ()
    scx_packages: tuple[str, ...] = ()


@dataclass(frozen=True)
class RemoteConfig:
    user: str = ""
    stage_dir: str = ""
    kernel_stage_dir: str = ""
    python_bin: str = ""
    runtime_python_bin: str = "python3"
    python_modules: tuple[str, ...] = ("PyYAML",)
    container_runtime: str = "docker"
    runtime_container_image: str = ""
    runtime_container_image_tar: str = ""
    commands: tuple[str, ...] = ()
    bpftool_bin: str = "bpftool"
    swap_size_gb: str = ""


@dataclass(frozen=True)
class AwsConfig:
    name_tag: str = ""
    instance_type: str = ""
    ami_param: str = ""
    ami_id: str = ""
    root_volume_gb: str = ""
    key_name: str = ""
    key_path: str = ""
    security_group_id: str = ""
    subnet_id: str = ""
    region: str = ""
    profile: str = ""


@dataclass(frozen=True)
class KvmConfig:
    backend: str = ""
    executable: str = ""
    cpus: str = ""
    mem: str = ""
    host_python_bin: str = "python3"
    kernel_image: str = ""
    timeout_seconds: str = ""


@dataclass(frozen=True)
class TestConfig:
    mode: str = "test"
    fuzz_rounds: str = ""
    scx_prog_show_race_mode: str = ""
    scx_prog_show_race_iterations: str = ""
    scx_prog_show_race_load_timeout: str = ""
    scx_prog_show_race_skip_probe: str = ""


@dataclass(frozen=True)
class BenchmarkConfig:
    samples: str = ""
    warmups: str = ""
    inner_repeat: str = ""
    corpus_filters: tuple[str, ...] = ()
    corpus_workload_seconds: str = ""
    e2e_cases: tuple[str, ...] = ("all",)
    e2e_smoke: str = ""
    corpus_argv: tuple[str, ...] = ()
    e2e_argv: tuple[str, ...] = ()


@dataclass(frozen=True)
class RunConfig:
    identity: RunIdentity
    suite: SuiteRequirements
    artifacts: ArtifactRequirements
    remote: RemoteConfig
    aws: AwsConfig
    kvm: KvmConfig
    test: TestConfig
    benchmark: BenchmarkConfig

    def to_mapping(self) -> dict[str, str | list[str]]:
        arch = self.identity.target_arch.strip()
        i, s, a, r, aw, kv, t, b = self.identity, self.suite, self.artifacts, self.remote, self.aws, self.kvm, self.test, self.benchmark
        return {
            "RUN_TARGET_NAME": i.target_name, "RUN_TARGET_ARCH": arch,
            "RUN_EXECUTOR": i.executor, "RUN_SUITE_NAME": i.suite_name, "RUN_TOKEN": i.token,
            "RUN_SUITE_NEEDS_RUNTIME_BTF": s.needs_runtime_btf, "RUN_SUITE_NEEDS_SCHED_EXT": s.needs_sched_ext,
            "RUN_SUITE_NEEDS_LLVMBPF": s.needs_llvmbpf, "RUN_LLVM_DIR": s.llvm_dir,
            "RUN_NEEDS_RUNNER_BINARY": a.needs_runner_binary, "RUN_NEEDS_DAEMON_BINARY": a.needs_daemon_binary,
            "RUN_NEEDS_KINSN_MODULES": a.needs_kinsn_modules, "RUN_NEEDS_WORKLOAD_TOOLS": a.needs_workload_tools,
            "RUN_NAME_TAG": aw.name_tag, "RUN_INSTANCE_TYPE": aw.instance_type,
            "RUN_REMOTE_USER": r.user, "RUN_REMOTE_STAGE_DIR": r.stage_dir,
            "RUN_REMOTE_KERNEL_STAGE_DIR": r.kernel_stage_dir,
            "RUN_AMI_PARAM": aw.ami_param, "RUN_AMI_ID": aw.ami_id,
            "RUN_ROOT_VOLUME_GB": aw.root_volume_gb, "RUN_REMOTE_SWAP_SIZE_GB": r.swap_size_gb,
            "RUN_AWS_KEY_NAME": aw.key_name, "RUN_AWS_KEY_PATH": aw.key_path,
            "RUN_AWS_SECURITY_GROUP_ID": aw.security_group_id, "RUN_AWS_SUBNET_ID": aw.subnet_id,
            "RUN_AWS_REGION": aw.region, "RUN_AWS_PROFILE": aw.profile,
            "RUN_VM_BACKEND": kv.backend, "RUN_VM_EXECUTABLE": kv.executable,
            "RUN_VM_CPUS": kv.cpus, "RUN_VM_MEM": kv.mem,
            "RUN_HOST_PYTHON_BIN": kv.host_python_bin, "RUN_VM_KERNEL_IMAGE": kv.kernel_image,
            "RUN_VM_TIMEOUT_SECONDS": kv.timeout_seconds,
            "RUN_REMOTE_PYTHON_BIN": r.python_bin, "RUN_RUNTIME_PYTHON_BIN": r.runtime_python_bin,
            "RUN_REMOTE_PYTHON_MODULES_CSV": _join_csv(list(r.python_modules)),
            "RUN_CONTAINER_RUNTIME": r.container_runtime,
            "RUN_RUNTIME_CONTAINER_IMAGE": r.runtime_container_image,
            "RUN_RUNTIME_CONTAINER_IMAGE_TAR": r.runtime_container_image_tar,
            "RUN_TEST_MODE": t.mode, "RUN_TEST_FUZZ_ROUNDS": t.fuzz_rounds,
            "RUN_TEST_SCX_PROG_SHOW_RACE_MODE": t.scx_prog_show_race_mode,
            "RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS": t.scx_prog_show_race_iterations,
            "RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT": t.scx_prog_show_race_load_timeout,
            "RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE": t.scx_prog_show_race_skip_probe,
            "RUN_BENCH_SAMPLES": b.samples, "RUN_BENCH_WARMUPS": b.warmups,
            "RUN_BENCH_INNER_REPEAT": b.inner_repeat,
            "RUN_CORPUS_FILTERS": _join_csv(list(b.corpus_filters)),
            "RUN_CORPUS_WORKLOAD_SECONDS": b.corpus_workload_seconds,
            "RUN_E2E_CASES": _join_csv(list(b.e2e_cases)), "RUN_E2E_SMOKE": b.e2e_smoke,
            "RUN_NATIVE_REPOS_CSV": _join_csv(list(a.native_repos)),
            "RUN_SCX_PACKAGES_CSV": _join_csv(list(a.scx_packages)),
            "RUN_REMOTE_COMMANDS_CSV": _join_csv(list(r.commands)),
            "RUN_BPFTOOL_BIN": r.bpftool_bin,
            "RUN_CORPUS_ARGV": list(b.corpus_argv), "RUN_E2E_ARGV": list(b.e2e_argv),
        }

    def scalar(self, name: str, default: str = "") -> str:
        value = self.to_mapping().get(name, default)
        if isinstance(value, list):
            return shlex.join(str(token) for token in value)
        return str(value).strip()

    def required(self, name: str) -> str:
        value = self.scalar(name)
        if not value:
            raise RuntimeError(f"run config {name} is empty")
        return value

    def csv(self, name: str) -> list[str]:
        value = self.to_mapping().get(name, "")
        tokens = value if isinstance(value, list) else str(value).split(",")
        return [str(token).strip() for token in tokens if str(token).strip()]

    def argv(self, name: str) -> list[str]:
        value = self.to_mapping().get(name, [])
        if isinstance(value, list):
            return [str(token) for token in value]
        return shlex.split(str(value))

    def env(self) -> dict[str, str]:
        env: dict[str, str] = {}
        for name in ("PATH", "HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL"):
            value = os.environ.get(name, "").strip()
            if value:
                env[name] = value
        for name, value in self.to_mapping().items():
            env[name] = shlex.join(value) if isinstance(value, list) else str(value)
        return env

    def to_json_text(self) -> str:
        return json.dumps(self.to_mapping(), sort_keys=True, separators=(",", ":"))

    @classmethod
    def from_mapping(cls, values: dict[str, str | list[str]]) -> "RunConfig":
        def scalar(name: str, default: str = "") -> str:
            value = values.get(name, default)
            if isinstance(value, list):
                return shlex.join(str(token) for token in value)
            return str(value).strip()

        def csv(name: str) -> tuple[str, ...]:
            value = values.get(name, "")
            tokens = value if isinstance(value, list) else str(value).split(",")
            return tuple(str(token).strip() for token in tokens if str(token).strip())

        def argv(name: str) -> tuple[str, ...]:
            value = values.get(name, ())
            if isinstance(value, list):
                return tuple(str(token) for token in value)
            return tuple(shlex.split(str(value)))

        return cls(
            identity=RunIdentity(target_name=scalar("RUN_TARGET_NAME"), target_arch=scalar("RUN_TARGET_ARCH"),
                                 executor=scalar("RUN_EXECUTOR"), suite_name=scalar("RUN_SUITE_NAME"), token=scalar("RUN_TOKEN")),
            suite=SuiteRequirements(needs_runtime_btf=scalar("RUN_SUITE_NEEDS_RUNTIME_BTF", "0"),
                                    needs_sched_ext=scalar("RUN_SUITE_NEEDS_SCHED_EXT", "0"),
                                    needs_llvmbpf=scalar("RUN_SUITE_NEEDS_LLVMBPF", "0"), llvm_dir=scalar("RUN_LLVM_DIR")),
            artifacts=ArtifactRequirements(needs_runner_binary=scalar("RUN_NEEDS_RUNNER_BINARY", "0"),
                                           needs_daemon_binary=scalar("RUN_NEEDS_DAEMON_BINARY", "0"),
                                           needs_kinsn_modules=scalar("RUN_NEEDS_KINSN_MODULES", "0"),
                                           needs_workload_tools=scalar("RUN_NEEDS_WORKLOAD_TOOLS", "0"),
                                           native_repos=csv("RUN_NATIVE_REPOS_CSV"), scx_packages=csv("RUN_SCX_PACKAGES_CSV")),
            remote=RemoteConfig(user=scalar("RUN_REMOTE_USER"), stage_dir=scalar("RUN_REMOTE_STAGE_DIR"),
                                kernel_stage_dir=scalar("RUN_REMOTE_KERNEL_STAGE_DIR"), python_bin=scalar("RUN_REMOTE_PYTHON_BIN"),
                                runtime_python_bin=scalar("RUN_RUNTIME_PYTHON_BIN", "python3"),
                                python_modules=csv("RUN_REMOTE_PYTHON_MODULES_CSV") or ("PyYAML",),
                                container_runtime=scalar("RUN_CONTAINER_RUNTIME", "docker"),
                                runtime_container_image=scalar("RUN_RUNTIME_CONTAINER_IMAGE"),
                                runtime_container_image_tar=scalar("RUN_RUNTIME_CONTAINER_IMAGE_TAR"),
                                commands=csv("RUN_REMOTE_COMMANDS_CSV"), bpftool_bin=scalar("RUN_BPFTOOL_BIN", "bpftool"),
                                swap_size_gb=scalar("RUN_REMOTE_SWAP_SIZE_GB")),
            aws=AwsConfig(name_tag=scalar("RUN_NAME_TAG"), instance_type=scalar("RUN_INSTANCE_TYPE"),
                          ami_param=scalar("RUN_AMI_PARAM"), ami_id=scalar("RUN_AMI_ID"),
                          root_volume_gb=scalar("RUN_ROOT_VOLUME_GB"), key_name=scalar("RUN_AWS_KEY_NAME"),
                          key_path=scalar("RUN_AWS_KEY_PATH"), security_group_id=scalar("RUN_AWS_SECURITY_GROUP_ID"),
                          subnet_id=scalar("RUN_AWS_SUBNET_ID"), region=scalar("RUN_AWS_REGION"), profile=scalar("RUN_AWS_PROFILE")),
            kvm=KvmConfig(backend=scalar("RUN_VM_BACKEND"), executable=scalar("RUN_VM_EXECUTABLE"),
                          cpus=scalar("RUN_VM_CPUS"), mem=scalar("RUN_VM_MEM"),
                          host_python_bin=scalar("RUN_HOST_PYTHON_BIN", "python3"),
                          kernel_image=scalar("RUN_VM_KERNEL_IMAGE"), timeout_seconds=scalar("RUN_VM_TIMEOUT_SECONDS")),
            test=TestConfig(mode=scalar("RUN_TEST_MODE", "test"), fuzz_rounds=scalar("RUN_TEST_FUZZ_ROUNDS"),
                            scx_prog_show_race_mode=scalar("RUN_TEST_SCX_PROG_SHOW_RACE_MODE"),
                            scx_prog_show_race_iterations=scalar("RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS"),
                            scx_prog_show_race_load_timeout=scalar("RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT"),
                            scx_prog_show_race_skip_probe=scalar("RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE")),
            benchmark=BenchmarkConfig(samples=scalar("RUN_BENCH_SAMPLES"), warmups=scalar("RUN_BENCH_WARMUPS"),
                                      inner_repeat=scalar("RUN_BENCH_INNER_REPEAT"), corpus_filters=csv("RUN_CORPUS_FILTERS"),
                                      corpus_workload_seconds=scalar("RUN_CORPUS_WORKLOAD_SECONDS"),
                                      e2e_cases=csv("RUN_E2E_CASES") or ("all",), e2e_smoke=scalar("RUN_E2E_SMOKE"),
                                      corpus_argv=argv("RUN_CORPUS_ARGV"), e2e_argv=argv("RUN_E2E_ARGV")),
        )

    @classmethod
    def from_json_text(cls, text: str) -> "RunConfig":
        raw = json.loads(text)
        if not isinstance(raw, dict): raise RuntimeError("run config JSON must contain an object")
        values: dict[str, str | list[str]] = {}
        for key, value in raw.items():
            if not isinstance(key, str): raise RuntimeError("run config JSON keys must be strings")
            values[key] = [str(item) for item in value] if isinstance(value, list) else ("" if value is None else str(value))
        return cls.from_mapping(values)


def _runner_remote_commands(runner_name: str) -> tuple[str, ...]:
    name = str(runner_name).strip()
    dotted = _RUNNER_CLASS_PATHS.get(name)
    if dotted is None: _die(f"unsupported app runner in suite: {runner_name!r}")
    module_path, class_name = dotted.rsplit(".", 1)
    try:
        return tuple(getattr(importlib.import_module(module_path), class_name).required_remote_commands)
    except (AttributeError, ImportError) as exc:
        _die(f"failed to resolve remote command contract for runner {name!r}: {exc}")


def _load_assignment_file(path: Path) -> dict[str, str]:
    if not path.is_file(): _die(f"missing required file: {path}")
    data: dict[str, str] = {}
    for line_no, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        line = raw_line.strip()
        if not line or line.startswith("#"): continue
        if "=" not in line: _die(f"unsupported assignment in {path}:{line_no}: {raw_line}")
        key, value = line.split("=", 1); key = key.strip()
        if not key or not key.replace("_", "").isalnum() or key[0].isdigit():
            _die(f"invalid assignment key in {path}:{line_no}: {key!r}")
        data[key] = value.strip()
    return data


def _env_or_default(env: dict[str, str], name: str, default: str = "") -> str:
    return env.get(name, "").strip() or default


def _prefixed_env_or_default(env: dict[str, str], prefix: str, suffix: str, default: str = "") -> str:
    return _env_or_default(env, f"{prefix}_{suffix}", default)


def _normalize_csv(raw: str) -> str:
    return "".join(raw.split())


def _resolve_repo_path(path: str) -> str:
    if not path: return ""
    candidate = Path(path)
    return str(candidate) if candidate.is_absolute() else str((ROOT_DIR / candidate).resolve())


def _resolve_run_llvm_dir(values: dict[str, str]) -> str:
    if explicit_run_dir := _env_or_default(values, "RUN_LLVM_DIR"):
        return _resolve_repo_path(explicit_run_dir)
    if explicit_dir := _env_or_default(values, "LLVM_DIR"):
        return _resolve_repo_path(explicit_dir)
    llvm_config = _env_or_default(values, "LLVM_CONFIG")
    if not llvm_config: return ""
    completed = subprocess.run([llvm_config, "--cmakedir"], check=False, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if completed.returncode != 0: _die(f"LLVM_CONFIG failed to resolve cmake dir: {llvm_config}")
    cmake_dir = completed.stdout.strip()
    if not cmake_dir: _die(f"LLVM_CONFIG returned an empty cmake dir: {llvm_config}")
    return cmake_dir


def _host_cpu_count() -> int: return max(os.cpu_count() or 1, 1)


def _resolve_cpu_spec(spec: str) -> str:
    if not spec or spec == "auto": return str(_host_cpu_count())
    if spec.startswith("auto:"):
        return str(max(int(_host_cpu_count() * float(spec.split(":", 1)[1] or "1")), 1))
    return spec


def _csv_tokens(csv: str) -> list[str]: return [token for token in csv.split(",") if token]


def _append_csv(csv: str, token: str) -> str:
    if not token or token in _csv_tokens(csv): return csv
    return token if not csv else f"{csv},{token}"


def _append_csv_list(csv: str, extra_csv: str) -> str:
    merged = csv
    for token in _csv_tokens(extra_csv): merged = _append_csv(merged, token)
    return merged


def _join_csv(tokens: list[str]) -> str: return ",".join(token for token in tokens if token)


def _ordered_csv_from_tokens(tokens: set[str], *, order: tuple[str, ...]) -> str:
    return ",".join(token for token in order if token in tokens)


def _corpus_workload_requirements_for_selection(app_suite: object) -> str:
    remote_commands: set[str] = set()
    for app in getattr(app_suite, "apps", ()):
        remote_commands.update(_runner_remote_commands(str(getattr(app, "runner", "") or "").strip()))
        remote_commands.update(CORPUS_WORKLOAD_KIND_COMMANDS.get(str(app.workload_for("corpus") or "").strip(), ()))
    return _ordered_csv_from_tokens(remote_commands, order=REMOTE_COMMAND_ORDER)


def _apply_corpus_filter_selection(
    *,
    run_corpus_filters: str,
    suite: dict[str, str],
    run_benchmark_repos: str,
    run_native_repos: str,
    run_scx_packages: str,
    run_needs_sched_ext: str,
) -> tuple[str, str, str, str, str]:
    app_suite, _summary = load_app_suite_from_yaml(DEFAULT_CORPUS_APP_SUITE, filters=_csv_tokens(run_corpus_filters))
    selected_runners = {app.runner for app in app_suite.apps}
    filtered_benchmark_repos = _join_csv([t for t in _csv_tokens(run_benchmark_repos) if t in selected_runners])
    filtered_native_repos = _join_csv([t for t in _csv_tokens(run_native_repos) if t in selected_runners])
    return (filtered_benchmark_repos, filtered_native_repos,
            suite.get("SUITE_DEFAULT_SCX_PACKAGES", "") if "scx" in selected_runners else "",
            "1" if "scx" in selected_runners else "0",
            _corpus_workload_requirements_for_selection(app_suite))


def _apply_e2e_case_selection(*, run_e2e_cases: str, suite: dict[str, str]) -> tuple[str, str, str, str, str]:
    selected_cases = set(_csv_tokens(run_e2e_cases))
    include_all = "all" in selected_cases
    remote_commands: set[str] = set()
    for case_name in _RUNNER_CLASS_PATHS:
        if include_all or case_name in selected_cases:
            remote_commands.update(_runner_remote_commands(case_name))
    run_scx_packages, run_needs_sched_ext = ("", "0")
    if include_all or "scx" in selected_cases:
        run_scx_packages = suite.get("SUITE_DEFAULT_SCX_PACKAGES", ""); run_needs_sched_ext = "1"
    return (_suite_repos_for_e2e_cases(run_e2e_cases), _native_repos_for_e2e_cases(run_e2e_cases),
            run_scx_packages, run_needs_sched_ext, _ordered_csv_from_tokens(remote_commands, order=REMOTE_COMMAND_ORDER))


_COMMON_MANIFEST_INPUTS = {
    "PYTHON",
    "RUN_TOKEN",
    "LLVM_CONFIG",
    "LLVM_DIR",
    "CONTAINER_RUNTIME",
    "RUNTIME_PYTHON",
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


def _filtered_run_inputs(target_name: str, env: dict[str, str] | None) -> dict[str, str]:
    source_env = os.environ if env is None else env
    allowed = set(_COMMON_MANIFEST_INPUTS)
    if target_name == "x86-kvm":
        allowed.update(_KVM_MANIFEST_INPUTS)
    else:
        target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
        if aws_env_prefix := target.get("TARGET_AWS_ENV_PREFIX", ""):
            allowed.update(f"{aws_env_prefix}_{suffix}" for suffix in _AWS_MANIFEST_SUFFIXES)
    return {key: source_env[key] for key in allowed if key in source_env}


def _validate_test_mode(mode: str) -> None:
    if mode not in {"selftest", "negative", "test"}: _die(f"unsupported test mode: {mode}")


def _validate_e2e_cases(cases_csv: str) -> None:
    if not cases_csv: _die("e2e cases must not be empty")
    if cases_csv == "all": return
    for token in _csv_tokens(cases_csv):
        if token not in {"tracee", "tetragon", "bpftrace", "scx", "bcc", "katran"}:
            _die(f"unsupported e2e case: {token}")


def _suite_repos_for_e2e_cases(cases_csv: str) -> str:
    if cases_csv == "all": return "tracee,tetragon,bpftrace,scx,bcc,katran"
    repos = ""
    for token in _csv_tokens(cases_csv): repos = _append_csv(repos, token)
    return repos


def _native_repos_for_e2e_cases(cases_csv: str) -> str:
    if cases_csv == "all": return "bcc,bpftrace,katran,tracee,tetragon"
    repos = ""
    for token in _csv_tokens(cases_csv):
        if token in {"bcc", "bpftrace", "katran", "tracee", "tetragon"}: repos = _append_csv(repos, token)
    return repos


def _build_run_config_mapping(target_name: str, suite_name: str, *, env: dict[str, str] | None = None) -> dict[str, str | list[str]]:
    values = _filtered_run_inputs(target_name, env)
    target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
    suite = _load_assignment_file(SUITES_DIR / f"{suite_name}.env")

    run_token = values.get("RUN_TOKEN", "").strip() or f"{target_name}_{suite_name}"
    (run_name_tag, run_instance_type, run_remote_user, run_remote_stage_dir,
     run_remote_kernel_stage_dir, run_ami_param, run_ami_id, run_root_volume_gb,
     run_aws_key_name, run_aws_key_path, run_aws_security_group_id,
     run_aws_subnet_id, run_aws_region, run_aws_profile, run_remote_swap_size_gb,
     run_bench_samples, run_bench_warmups, run_bench_inner_repeat,
     run_corpus_filters, run_corpus_args, run_corpus_workload_seconds,
     run_e2e_args, run_e2e_smoke, run_llvm_dir,
     run_vm_backend, run_vm_executable, run_vm_cpus, run_vm_mem, run_vm_kernel_image,
     run_test_fuzz_rounds, run_test_scx_prog_show_race_mode,
     run_test_scx_prog_show_race_iterations, run_test_scx_prog_show_race_load_timeout,
     run_test_scx_prog_show_race_skip_probe) = ("",) * 34
    run_corpus_argv: list[str] = []
    run_e2e_argv: list[str] = []
    run_test_mode = "test"; run_e2e_cases = "all"; run_bpftool_bin = "bpftool"
    run_remote_python_modules = "PyYAML"
    run_benchmark_repos = suite.get("SUITE_DEFAULT_REPOS", "")
    run_native_repos = suite.get("SUITE_DEFAULT_NATIVE_REPOS", "")
    run_scx_packages = suite.get("SUITE_DEFAULT_SCX_PACKAGES", "")
    run_needs_sched_ext = suite.get("SUITE_NEEDS_SCHED_EXT", "0")
    run_needs_llvmbpf = suite.get("SUITE_NEEDS_LLVMBPF", "0")
    run_remote_commands = suite.get("SUITE_DEFAULT_REMOTE_COMMANDS", "")
    run_needs_runner_binary = suite.get("SUITE_NEEDS_RUNNER_BINARY", "0")
    run_needs_daemon_binary = suite.get("SUITE_NEEDS_DAEMON_BINARY", "0")
    run_needs_kinsn_modules = suite.get("SUITE_NEEDS_KINSN_MODULES", "0")
    run_vm_timeout_seconds = suite.get("SUITE_DEFAULT_VM_TIMEOUT_SECONDS", "7200")
    run_host_python_bin = _env_or_default(values, "PYTHON", "python3")
    run_runtime_python_bin = _env_or_default(values, "RUNTIME_PYTHON", "python3")
    run_container_runtime = _env_or_default(values, "CONTAINER_RUNTIME", "docker")
    run_remote_python_bin = target.get("TARGET_REMOTE_PYTHON_DEFAULT", suite.get("SUITE_DEFAULT_REMOTE_PYTHON_BIN", ""))
    if target.get("TARGET_EXECUTOR", "") == "aws-ssh":
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if not aws_env_prefix:
            _die(f"AWS target {target_name} is missing TARGET_AWS_ENV_PREFIX")
        _penv = lambda suf, dflt="": _prefixed_env_or_default(values, aws_env_prefix, suf, dflt)
        _treq = lambda suf: _die(f"{aws_env_prefix}_{suf} is required for AWS targets")
        run_name_tag = _penv("NAME_TAG", target.get("TARGET_NAME_TAG_DEFAULT", ""))
        default_instance_type = target.get("TARGET_INSTANCE_TYPE_DEFAULT", "")
        if suite.get("SUITE_VM_CLASS", "") == "benchmark":
            default_instance_type = target.get("TARGET_BENCH_INSTANCE_TYPE_DEFAULT", default_instance_type)
        else:
            default_instance_type = target.get("TARGET_TEST_INSTANCE_TYPE_DEFAULT", default_instance_type)
        run_instance_type = _penv("INSTANCE_TYPE", default_instance_type)
        run_remote_user = _penv("REMOTE_USER", target.get("TARGET_REMOTE_USER_DEFAULT", ""))
        remote_stage_root = _penv("REMOTE_STAGE_DIR", target.get("TARGET_REMOTE_STAGE_DIR_DEFAULT", "")).rstrip("/")
        run_remote_stage_dir = f"{remote_stage_root}/{suite_name}/{run_token}" if suite_name else f"{remote_stage_root}/{run_token}"
        run_remote_kernel_stage_dir = _penv("REMOTE_KERNEL_STAGE_DIR", target.get("TARGET_REMOTE_KERNEL_STAGE_DIR_DEFAULT", ""))
        run_ami_param = _penv("AMI_PARAM", target.get("TARGET_AMI_PARAM_DEFAULT", ""))
        run_ami_id = _penv("AMI_ID")
        run_root_volume_gb = _penv("ROOT_VOLUME_GB", target.get("TARGET_ROOT_VOLUME_GB_DEFAULT", ""))
        run_remote_swap_size_gb = _penv("REMOTE_SWAP_SIZE_GB", target.get("TARGET_REMOTE_SWAP_SIZE_GB_DEFAULT", "8"))
        run_test_mode = _penv("TEST_MODE", "test").lower()
        run_bench_samples = _penv("BENCH_SAMPLES", "1")
        run_bench_warmups = _penv("BENCH_WARMUPS", "0")
        run_bench_inner_repeat = _penv("BENCH_INNER_REPEAT", "10")
        run_corpus_filters = _normalize_csv(_penv("CORPUS_FILTERS", ""))
        run_corpus_args = _penv("CORPUS_ARGS", "")
        run_corpus_workload_seconds = _penv("CORPUS_WORKLOAD_SECONDS", "")
        run_e2e_cases = _normalize_csv(_penv("E2E_CASES", suite.get("SUITE_DEFAULT_E2E_CASES", "all")))
        run_e2e_args = _penv("E2E_ARGS", ""); run_e2e_smoke = _penv("E2E_SMOKE", "0")
        run_aws_key_path = _penv("KEY_PATH")
        if not run_aws_key_path: _treq("KEY_PATH")
        run_aws_key_name = _penv("KEY_NAME") or Path(run_aws_key_path).stem
        if not run_aws_key_name: _die(f"{aws_env_prefix}_KEY_NAME could not be derived from {aws_env_prefix}_KEY_PATH")
        run_aws_security_group_id = _penv("SECURITY_GROUP_ID")
        if not run_aws_security_group_id: _treq("SECURITY_GROUP_ID")
        run_aws_subnet_id = _penv("SUBNET_ID")
        if not run_aws_subnet_id: _treq("SUBNET_ID")
        run_aws_region = _penv("REGION", target.get("TARGET_AWS_REGION_DEFAULT", ""))
        if not run_aws_region: _treq("REGION")
        run_aws_profile = _penv("PROFILE")
        if not run_aws_profile: _treq("PROFILE")
    elif target_name == "x86-kvm":
        run_vm_backend = target.get("TARGET_KVM_BACKEND", "")
        run_vm_executable = target.get("TARGET_KVM_EXECUTABLE", "")
        run_host_python_bin = _env_or_default(values, "PYTHON", target.get("TARGET_KVM_HOST_PYTHON_DEFAULT", "python3"))
        run_vm_kernel_image = _resolve_repo_path(_env_or_default(values, "BZIMAGE", target.get("TARGET_KVM_KERNEL_IMAGE_DEFAULT", "vendor/linux-framework/arch/x86/boot/bzImage")))
        if not run_vm_backend: _die("x86-kvm target is missing TARGET_KVM_BACKEND")
        if not run_vm_executable: _die("x86-kvm target is missing TARGET_KVM_EXECUTABLE")
        if not Path(run_vm_executable).is_absolute() and "/" in run_vm_executable:
            run_vm_executable = str((ROOT_DIR / run_vm_executable).resolve())
        _kenv = lambda k, dflt="": _env_or_default(values, k, dflt)
        run_test_mode = _kenv("TEST_MODE", "test")
        run_bench_samples = _kenv("SAMPLES", "1"); run_bench_warmups = _kenv("WARMUPS", "0"); run_bench_inner_repeat = _kenv("INNER_REPEAT", "10")
        run_corpus_filters = _normalize_csv(_kenv("FILTERS", ""))
        run_corpus_args = _kenv("VM_CORPUS_ARGS", ""); run_corpus_workload_seconds = _kenv("VM_CORPUS_WORKLOAD_SECONDS", "")
        run_e2e_cases = _normalize_csv(_kenv("E2E_CASE", "all")); run_e2e_args = _kenv("E2E_ARGS", ""); run_e2e_smoke = _kenv("E2E_SMOKE", "0")
        suite_vm_class = suite.get("SUITE_VM_CLASS", "")
        if suite_vm_class == "test":
            run_vm_cpus = _kenv("VM_CPUS", _resolve_cpu_spec(target.get("TARGET_KVM_TEST_CPUS_SPEC", "auto:0.8")))
            run_vm_mem = _kenv("VM_MEM", target.get("TARGET_KVM_TEST_MEM", "16G"))
        elif suite_vm_class == "benchmark":
            run_vm_cpus = _kenv("VM_CPUS", _resolve_cpu_spec(target.get("TARGET_KVM_BENCH_CPUS_SPEC", "4")))
            run_vm_mem = _kenv("VM_MEM", target.get("TARGET_KVM_BENCH_MEM", "16G"))
        elif suite_vm_class:
            _die(f"unsupported KVM suite class: {suite_vm_class}")
    else:
        _die(f"unsupported target: {target_name}")

    if suite_name == "test":
        run_vm_timeout_seconds = _env_or_default(values, "VM_TEST_TIMEOUT", run_vm_timeout_seconds)
        _senv = lambda k, skey, dflt: _env_or_default(values, k, suite.get(skey, dflt))
        run_test_fuzz_rounds = _senv("FUZZ_ROUNDS", "SUITE_DEFAULT_FUZZ_ROUNDS", "1000")
        run_test_scx_prog_show_race_mode = _senv("SCX_PROG_SHOW_RACE_MODE", "SUITE_DEFAULT_SCX_PROG_SHOW_RACE_MODE", "bpftool-loop")
        run_test_scx_prog_show_race_iterations = _senv("SCX_PROG_SHOW_RACE_ITERATIONS", "SUITE_DEFAULT_SCX_PROG_SHOW_RACE_ITERATIONS", "20")
        run_test_scx_prog_show_race_load_timeout = _senv("SCX_PROG_SHOW_RACE_LOAD_TIMEOUT", "SUITE_DEFAULT_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT", "20")
        run_test_scx_prog_show_race_skip_probe = _senv("SCX_PROG_SHOW_RACE_SKIP_PROBE", "SUITE_DEFAULT_SCX_PROG_SHOW_RACE_SKIP_PROBE", "0")
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
            corpus_remote_commands,
        ) = _apply_corpus_filter_selection(
            run_corpus_filters=run_corpus_filters,
            suite=suite,
            run_benchmark_repos=run_benchmark_repos,
            run_native_repos=run_native_repos,
            run_scx_packages=run_scx_packages,
            run_needs_sched_ext=run_needs_sched_ext,
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
        run_llvm_dir = _resolve_run_llvm_dir(values) or DEFAULT_BUILD_CONTAINER_LLVM_DIR

    arch = target.get("TARGET_ARCH", "").strip()
    return {
        "RUN_TARGET_NAME": target_name, "RUN_TARGET_ARCH": arch,
        "RUN_EXECUTOR": target.get("TARGET_EXECUTOR", ""), "RUN_SUITE_NAME": suite_name,
        "RUN_SUITE_NEEDS_RUNTIME_BTF": suite.get("SUITE_NEEDS_RUNTIME_BTF", "0"),
        "RUN_RUNTIME_CONTAINER_IMAGE": f"bpf-benchmark/runner-runtime:{arch}",
        "RUN_RUNTIME_CONTAINER_IMAGE_TAR": f".cache/container-images/{arch}-runner-runtime.image.tar",
        "RUN_TOKEN": run_token, "RUN_SUITE_NEEDS_SCHED_EXT": run_needs_sched_ext,
        "RUN_SUITE_NEEDS_LLVMBPF": run_needs_llvmbpf, "RUN_LLVM_DIR": run_llvm_dir,
        "RUN_NEEDS_RUNNER_BINARY": run_needs_runner_binary, "RUN_NEEDS_DAEMON_BINARY": run_needs_daemon_binary,
        "RUN_NEEDS_KINSN_MODULES": run_needs_kinsn_modules, "RUN_NEEDS_WORKLOAD_TOOLS": run_needs_workload_tools,
        "RUN_NAME_TAG": run_name_tag, "RUN_INSTANCE_TYPE": run_instance_type,
        "RUN_REMOTE_USER": run_remote_user, "RUN_REMOTE_STAGE_DIR": run_remote_stage_dir,
        "RUN_REMOTE_KERNEL_STAGE_DIR": run_remote_kernel_stage_dir,
        "RUN_AMI_PARAM": run_ami_param, "RUN_AMI_ID": run_ami_id,
        "RUN_ROOT_VOLUME_GB": run_root_volume_gb, "RUN_REMOTE_SWAP_SIZE_GB": run_remote_swap_size_gb,
        "RUN_AWS_KEY_NAME": run_aws_key_name, "RUN_AWS_KEY_PATH": run_aws_key_path,
        "RUN_AWS_SECURITY_GROUP_ID": run_aws_security_group_id, "RUN_AWS_SUBNET_ID": run_aws_subnet_id,
        "RUN_AWS_REGION": run_aws_region, "RUN_AWS_PROFILE": run_aws_profile,
        "RUN_VM_BACKEND": run_vm_backend, "RUN_VM_EXECUTABLE": run_vm_executable,
        "RUN_VM_CPUS": run_vm_cpus, "RUN_VM_MEM": run_vm_mem,
        "RUN_HOST_PYTHON_BIN": run_host_python_bin, "RUN_VM_KERNEL_IMAGE": run_vm_kernel_image,
        "RUN_VM_TIMEOUT_SECONDS": run_vm_timeout_seconds,
        "RUN_REMOTE_PYTHON_BIN": run_remote_python_bin, "RUN_RUNTIME_PYTHON_BIN": run_runtime_python_bin,
        "RUN_REMOTE_PYTHON_MODULES_CSV": run_remote_python_modules, "RUN_CONTAINER_RUNTIME": run_container_runtime,
        "RUN_TEST_MODE": run_test_mode, "RUN_TEST_FUZZ_ROUNDS": run_test_fuzz_rounds,
        "RUN_TEST_SCX_PROG_SHOW_RACE_MODE": run_test_scx_prog_show_race_mode,
        "RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS": run_test_scx_prog_show_race_iterations,
        "RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT": run_test_scx_prog_show_race_load_timeout,
        "RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE": run_test_scx_prog_show_race_skip_probe,
        "RUN_BENCH_SAMPLES": run_bench_samples, "RUN_BENCH_WARMUPS": run_bench_warmups,
        "RUN_BENCH_INNER_REPEAT": run_bench_inner_repeat, "RUN_CORPUS_FILTERS": run_corpus_filters,
        "RUN_CORPUS_WORKLOAD_SECONDS": run_corpus_workload_seconds,
        "RUN_E2E_CASES": run_e2e_cases, "RUN_E2E_SMOKE": run_e2e_smoke,
        "RUN_NATIVE_REPOS_CSV": run_native_repos, "RUN_SCX_PACKAGES_CSV": run_scx_packages,
        "RUN_REMOTE_COMMANDS_CSV": run_remote_commands, "RUN_BPFTOOL_BIN": run_bpftool_bin,
        "RUN_CORPUS_ARGV": run_corpus_argv, "RUN_E2E_ARGV": run_e2e_argv,
    }


def build_run_config(target_name: str, suite_name: str, *, env: dict[str, str] | None = None) -> RunConfig:
    return RunConfig.from_mapping(_build_run_config_mapping(target_name, suite_name, env=env))


def build_target_config(target_name: str, *, env: dict[str, str] | None = None) -> RunConfig:
    values = _filtered_run_inputs(target_name, env)
    target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
    run_token = values.get("RUN_TOKEN", "").strip() or f"target_{target_name}"
    run_name_tag = run_aws_region = run_aws_profile = ""
    if target.get("TARGET_EXECUTOR", "") == "aws-ssh":
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if not aws_env_prefix: _die(f"AWS target {target_name} is missing TARGET_AWS_ENV_PREFIX")
        _penv = lambda suf, dflt="": _prefixed_env_or_default(values, aws_env_prefix, suf, dflt)
        run_name_tag = _penv("NAME_TAG", target.get("TARGET_NAME_TAG_DEFAULT", ""))
        run_aws_region = _penv("REGION", target.get("TARGET_AWS_REGION_DEFAULT", ""))
        if not run_aws_region: _die(f"{aws_env_prefix}_REGION is required for AWS targets")
        run_aws_profile = _penv("PROFILE")
        if not run_aws_profile: _die(f"{aws_env_prefix}_PROFILE is required for AWS targets")
    return RunConfig.from_mapping({"RUN_TARGET_NAME": target_name, "RUN_TARGET_ARCH": target.get("TARGET_ARCH", ""),
                                   "RUN_EXECUTOR": target.get("TARGET_EXECUTOR", ""), "RUN_SUITE_NAME": "",
                                   "RUN_TOKEN": run_token, "RUN_NAME_TAG": run_name_tag,
                                   "RUN_AWS_REGION": run_aws_region, "RUN_AWS_PROFILE": run_aws_profile})


def write_run_config_file(path: Path, config: RunConfig) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    write_json_object(path, config.to_mapping())


def read_run_config_file(path: Path) -> RunConfig:
    if not path.is_file():
        _die(f"run config is missing: {path}")
    return RunConfig.from_json_text(path.read_text(encoding="utf-8"))


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args: _die("usage: python -m runner.libs.run_contract <print-json|write-config|write-target-config> ...")
    action = args[0]
    if action == "print-json":
        if len(args) != 2: _die("usage: python -m runner.libs.run_contract print-json <config_path>")
        print(read_run_config_file(Path(args[1]).resolve()).to_json_text()); return
    if action == "write-config":
        if len(args) != 4: _die("usage: python -m runner.libs.run_contract write-config <target> <suite> <config_path>")
        write_run_config_file(Path(args[3]).resolve(), build_run_config(args[1], args[2])); return
    if action == "write-target-config":
        if len(args) != 3: _die("usage: python -m runner.libs.run_contract write-target-config <target> <config_path>")
        write_run_config_file(Path(args[2]).resolve(), build_target_config(args[1])); return
    _die(f"unsupported action: {action}")


if __name__ == "__main__":
    main()
