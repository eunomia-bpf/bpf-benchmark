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
    workspace: Path,
    suite_module: str,
    config: Any,
    *,
    die: Any,
) -> list[str]:
    """Build python -m invocation. corpus.driver rebuilds RunConfig in-container
    via build_run_config(TARGET, "corpus"); micro and test still consume legacy
    CLI infra args via argparse pending their own env migration.
    """
    remote_python = _required(config.remote.python_bin, "RUN_REMOTE_PYTHON_BIN", die)
    suite_name = config.identity.suite_name
    if suite_name == "corpus":
        return [remote_python, "-m", suite_module]
    return [
        remote_python, "-m", suite_module,
        "--workspace", str(workspace),
        "--target-arch", _required(config.identity.target_arch, "RUN_TARGET_ARCH", die),
        "--target-name", _required(config.identity.target_name, "RUN_TARGET_NAME", die),
        "--executor", _required(config.identity.executor, "RUN_EXECUTOR", die),
        "--run-token", _required(config.identity.token, "RUN_TOKEN", die),
        "--python-bin", remote_python,
        "--bpftool-bin", _required(config.remote.bpftool_bin, "RUN_BPFTOOL_BIN", die),
    ]


def build_runtime_container_command(
    host_workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    image = _required(config.remote.runtime_container_image, "RUN_RUNTIME_CONTAINER_IMAGE", die)
    runtime_python = config.remote.runtime_python_bin.strip() or "python3"
    image_workspace = RUNTIME_IMAGE_WORKSPACE
    suite_name = _required(config.identity.suite_name, "RUN_SUITE_NAME", die)
    container_config = _container_suite_config(config, runtime_python)
    suite_argv = build_suite_argv(image_workspace, container_config, suite_args, die=die)
    if len(suite_argv) < 3 or suite_argv[1] != "-m":
        die(f"unexpected suite argv shape: {suite_argv}")
    command = [
        "docker", "run", "--rm", "--privileged",
        "--pid=host", "--network=host", "--ipc=host", "--cgroupns=host",
        "-e", "BPFREJIT_INSIDE_RUNTIME_CONTAINER=1",
        "-e", "HOME=/root",
        "-w", str(image_workspace),
    ]
    # Forward every host env var (minus container-managed ones) so the in-container
    # driver sees TARGET, RUN_TOKEN, SAMPLES, WARMUPS, BPFREJIT_BENCH_PASSES, ...
    # without any allowlist or rename. The driver rebuilds RunConfig itself.
    for name, value in os.environ.items():
        if name in _HOST_ENV_BLOCKLIST or not value.strip():
            continue
        command.extend(["-e", f"{name}={value}"])
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
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
    config_path: Path | None = None,
) -> list[str]:
    """Compose `python -m <suite_module>` plus any legacy CLI tail args.

    Suite-specific knobs flow through BPFREJIT_* env vars (see _config_env_pairs).
    The micro and test suites still consume some legacy CLI args via suite_args
    while their respective drivers are migrated to env-only.
    """
    del config_path
    suite_name = config.identity.suite_name
    module = _SUITE_MODULE.get(suite_name)
    if module is None:
        die(f"unsupported suite: {suite_name}")
        raise AssertionError("unreachable")
    command = _build_base_suite_argv(workspace, module, config, die=die)
    # Legacy CLI for micro and test until those drivers migrate to env-only too.
    # corpus is fully env-driven, so it appends nothing here.
    if suite_name == "micro":
        target_name = _required(config.identity.target_name, "RUN_TARGET_NAME", die)
        command.extend(["--output", str(workspace / "micro" / "results" / f"{target_name}_micro.json")])
    elif suite_name == "test":
        run_token = _required(config.identity.token, "RUN_TOKEN", die)
        command.extend(["--artifact-dir", str(workspace / "tests" / "results" / run_token)])
        command.extend(["--run-contract-json", config.to_json_text()])
    command.extend(suite_args)
    return command
