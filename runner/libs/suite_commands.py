"""Shared suite and runtime image command-line builders."""
from __future__ import annotations

import os
from dataclasses import replace
from pathlib import Path
from typing import Any

from runner.libs.workspace_layout import RUNTIME_IMAGE_WORKSPACE


_CONTAINER_RESULT_DIR_BY_SUITE = {
    "micro": "micro/results",
    "corpus": "corpus/results",
    "test": "tests/results",
}
# Variables docker (or container init) manages itself; never propagate from host.
_HOST_ENV_BLOCKLIST = frozenset({
    "PATH", "HOME", "USER", "LOGNAME", "PWD", "OLDPWD",
    "SHLVL", "_", "TERM", "DISPLAY", "XAUTHORITY",
})
_SUITE_ENV_NAMES = (
    "SAMPLES", "WARMUPS", "INNER_REPEAT", "BENCH", "SUITE", "RUNTIMES",
    "FUZZ_ROUNDS", "TEST_MODE", "WORKLOAD_DURATION", "KEEP_WORKDIRS",
    "BPFREJIT_BENCH_PASSES", "BPFREJIT_CORPUS_APPS", "SKIP_REJIT",
    "CPU", "STRICT_ENV", "SHUFFLE_SEED", "REGENERATE_INPUTS", "LIST",
    "MICRO_RUNNER_BINARY", "MICRO_PROGRAM_DIR", "MICRO_OUTPUT",
    "PERF_COUNTERS", "BPFREJIT_CORPUS_APP_TIMEOUT",
    "BPFREJIT_CORPUS_REJIT_TIMEOUT", "BPFREJIT_CORPUS_WORKLOAD_ONLY",
    "BPFREJIT_CORPUS_BPF_STATS", "BPFREJIT_KEEP_ALL_WORKDIRS",
)


def _required(value: str, name: str, die: Any) -> str:
    normalized = str(value).strip()
    if not normalized:
        die(f"run config {name} is empty")
    return normalized


def _container_result_dir(suite_name: str, die: Any) -> str:
    normalized = str(suite_name).strip()
    relative = _CONTAINER_RESULT_DIR_BY_SUITE.get(normalized)
    if relative is None:
        die(f"unsupported suite for runtime container result mount: {suite_name!r}")
    return relative


def runtime_container_result_dirs(host_workspace: Path, suite_name: str, *, die: Any) -> list[Path]:
    return [host_workspace / _container_result_dir(suite_name, die)]


def runtime_container_host_dirs(
    host_workspace: Path,
    suite_name: str,
    *,
    die: Any,
) -> list[Path]:
    return runtime_container_result_dirs(host_workspace, suite_name, die=die)


def _container_suite_config(config: Any, python_bin: str) -> Any:
    return replace(
        config,
        remote=replace(
            config.remote,
            python_bin=python_bin,
            runtime_container_image="",
            runtime_python_bin="",
        ),
    )


def _build_base_suite_argv(
    suite_module: str,
    config: Any,
    *,
    die: Any,
) -> list[str]:
    """Build python -m invocation for the runtime container."""
    remote_python = _required(config.remote.python_bin, "RUN_REMOTE_PYTHON_BIN", die)
    return [remote_python, "-m", suite_module]


def build_runtime_container_command(
    host_workspace: Path,
    config: Any,
    *,
    die: Any,
) -> list[str]:
    image = _required(config.remote.runtime_container_image, "RUN_RUNTIME_CONTAINER_IMAGE", die)
    runtime_python = config.remote.runtime_python_bin.strip() or "python3"
    image_workspace = RUNTIME_IMAGE_WORKSPACE
    suite_name = _required(config.identity.suite_name, "RUN_SUITE_NAME", die)
    container_config = _container_suite_config(config, runtime_python)
    suite_argv = build_suite_argv(container_config, die=die)
    if len(suite_argv) < 3 or suite_argv[1] != "-m":
        die(f"unexpected suite argv shape: {suite_argv}")
    command = [
        "docker", "run", "--rm", "--privileged",
        "--pid=host", "--network=host", "--ipc=host", "--cgroupns=host",
        "-e", "BPFREJIT_INSIDE_RUNTIME_CONTAINER=1",
        "-e", "HOME=/root",
        "-e", "PYTHONUNBUFFERED=1",
        "-w", str(image_workspace),
    ]
    runtime_env = {
        name: str(value)
        for name, value in config.to_mapping().items()
        if not isinstance(value, list) and str(value).strip()
    }
    for name in _SUITE_ENV_NAMES:
        if value := os.environ.get(name, "").strip():
            runtime_env[name] = value
    for name, value in sorted(runtime_env.items()):
        if name in _HOST_ENV_BLOCKLIST or not value.strip():
            continue
        command.extend(["-e", f"{name}={value}"])
    if suite_name == "test":
        command.extend(["-e", f"RUN_CONTRACT_JSON={config.to_json_text()}"])
    for result_dir in runtime_container_result_dirs(host_workspace, suite_name, die=die):
        command.extend(["-v", f"{result_dir}:{image_workspace / result_dir.relative_to(host_workspace)}"])
    for source, target, readonly in (
        ("/sys", "/sys", False),
        ("/sys/fs/bpf", "/sys/fs/bpf", False),
        ("/sys/kernel/debug", "/sys/kernel/debug", False),
        ("/lib/modules", "/lib/modules", True),
        ("/boot", "/boot", True),
    ):
        suffix = ":ro" if readonly else ""
        command.extend(["-v", f"{source}:{target}{suffix}"])
    command.extend([image, runtime_python, *suite_argv[1:]])
    return command


_SUITE_MODULE = {
    "micro": "runner.suites.micro",
    "corpus": "corpus.driver",
    "test": "runner.suites.test",
}


def build_suite_argv(
    config: Any,
    *,
    die: Any,
) -> list[str]:
    """Compose `python -m <suite_module>`; suite knobs are env-only."""
    suite_name = config.identity.suite_name
    module = _SUITE_MODULE.get(suite_name)
    if module is None:
        die(f"unsupported suite: {suite_name}")
        raise AssertionError("unreachable")
    return _build_base_suite_argv(module, config, die=die)
