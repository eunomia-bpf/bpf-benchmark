"""Shared suite and runtime image command-line builders."""
from __future__ import annotations

from dataclasses import replace
from pathlib import Path
from typing import Any

from runner.libs.workspace_layout import RUNTIME_IMAGE_WORKSPACE


_CONTAINER_RESULT_DIRS = ("micro/results", "corpus/results", "e2e/results", "tests/results")


def _required(value: str, name: str, die: Any) -> str:
    normalized = str(value).strip()
    if not normalized:
        die(f"run config {name} is empty")
    return normalized


def runtime_container_result_dirs(host_workspace: Path) -> list[Path]:
    return [host_workspace / relative for relative in _CONTAINER_RESULT_DIRS]


def _container_suite_config(config: Any, python_bin: str) -> Any:
    return replace(
        config,
        remote=replace(
            config.remote,
            python_bin=python_bin,
            container_runtime="",
            runtime_container_image="",
            runtime_python_bin="",
        ),
    )


def build_runtime_container_command(
    host_workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    runtime = config.remote.container_runtime.strip() or "docker"
    image = _required(config.remote.runtime_container_image, "RUN_RUNTIME_CONTAINER_IMAGE", die)
    runtime_python = config.remote.runtime_python_bin.strip() or "python3"
    image_workspace = RUNTIME_IMAGE_WORKSPACE
    suite_argv = build_suite_argv(
        image_workspace,
        _container_suite_config(config, runtime_python),
        suite_args,
        die=die,
    )
    if len(suite_argv) < 3 or suite_argv[1] != "-m":
        die(f"unexpected suite argv shape: {suite_argv}")
    command = [
        runtime,
        "run",
        "--rm",
        "--privileged",
        "--pid=host",
        "--network=host",
        "--ipc=host",
        "-e",
        "BPFREJIT_INSIDE_RUNTIME_CONTAINER=1",
        "-e",
        f"BPFREJIT_IMAGE_WORKSPACE={image_workspace}",
        "-e",
        f"PYTHONPATH={image_workspace}",
        "-e",
        "HOME=/root",
        "-w",
        str(image_workspace),
    ]
    for relative in _CONTAINER_RESULT_DIRS:
        command.extend(["-v", f"{host_workspace / relative}:{image_workspace / relative}"])
    if config.artifacts.needs_kinsn_modules.strip() == "1":
        command.extend(["-v", f"{host_workspace / 'module'}:{image_workspace / 'module'}:ro"])
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


def build_micro_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    remote_python = _required(config.remote.python_bin, "RUN_REMOTE_PYTHON_BIN", die)
    target_name = _required(config.identity.target_name, "RUN_TARGET_NAME", die)
    target_arch = _required(config.identity.target_arch, "RUN_TARGET_ARCH", die)
    command = [
        remote_python,
        "-m",
        "runner.suites.micro",
        "--workspace", str(workspace),
        "--target-arch", target_arch,
        "--target-name", target_name,
        "--executor", _required(config.identity.executor, "RUN_EXECUTOR", die),
        "--run-token", _required(config.identity.token, "RUN_TOKEN", die),
        "--python-bin", remote_python,
        "--bpftool-bin", _required(config.remote.bpftool_bin, "RUN_BPFTOOL_BIN", die),
        "--output", str(workspace / "micro" / "results" / f"{target_name}_micro.json"),
    ]
    command.extend(suite_args)
    return command


def build_corpus_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    remote_python = _required(config.remote.python_bin, "RUN_REMOTE_PYTHON_BIN", die)
    target_name = _required(config.identity.target_name, "RUN_TARGET_NAME", die)
    target_arch = _required(config.identity.target_arch, "RUN_TARGET_ARCH", die)
    command = [
        remote_python,
        "-m",
        "runner.suites.corpus",
        "--workspace", str(workspace),
        "--target-arch", target_arch,
        "--target-name", target_name,
        "--executor", _required(config.identity.executor, "RUN_EXECUTOR", die),
        "--run-token", _required(config.identity.token, "RUN_TOKEN", die),
        "--python-bin", remote_python,
        "--bpftool-bin", _required(config.remote.bpftool_bin, "RUN_BPFTOOL_BIN", die),
        "--output-json", str(workspace / "corpus" / "results" / f"{target_name}_corpus.json"),
        "--output-md", str(workspace / "corpus" / "results" / f"{target_name}_corpus.md"),
    ]
    for repo_name in config.artifacts.native_repos:
        command.extend(["--native-repo", repo_name])
    for package_name in config.artifacts.scx_packages:
        command.extend(["--scx-package", package_name])
    command.extend(suite_args)
    return command


def build_e2e_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    remote_python = _required(config.remote.python_bin, "RUN_REMOTE_PYTHON_BIN", die)
    target_name = _required(config.identity.target_name, "RUN_TARGET_NAME", die)
    target_arch = _required(config.identity.target_arch, "RUN_TARGET_ARCH", die)
    command = [
        remote_python,
        "-m",
        "runner.suites.e2e",
        "--workspace", str(workspace),
        "--target-arch", target_arch,
        "--target-name", target_name,
        "--executor", _required(config.identity.executor, "RUN_EXECUTOR", die),
        "--run-token", _required(config.identity.token, "RUN_TOKEN", die),
        "--python-bin", remote_python,
        "--bpftool-bin", _required(config.remote.bpftool_bin, "RUN_BPFTOOL_BIN", die),
    ]
    for repo_name in config.artifacts.native_repos:
        command.extend(["--native-repo", repo_name])
    for package_name in config.artifacts.scx_packages:
        command.extend(["--scx-package", package_name])
    command.extend(suite_args)
    return command


def build_test_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
    config_path: Path | None = None,
) -> list[str]:
    remote_python = _required(config.remote.python_bin, "RUN_REMOTE_PYTHON_BIN", die)
    target_name = _required(config.identity.target_name, "RUN_TARGET_NAME", die)
    target_arch = _required(config.identity.target_arch, "RUN_TARGET_ARCH", die)
    run_token = _required(config.identity.token, "RUN_TOKEN", die)
    command = [
        remote_python,
        "-m",
        "runner.suites.test",
        "--workspace", str(workspace),
        "--target-arch", target_arch,
        "--target-name", target_name,
        "--executor", _required(config.identity.executor, "RUN_EXECUTOR", die),
        "--run-token", run_token,
        "--python-bin", remote_python,
        "--bpftool-bin", _required(config.remote.bpftool_bin, "RUN_BPFTOOL_BIN", die),
        "--artifact-dir", str(workspace / "tests" / "results" / run_token),
    ]
    if config_path is not None:
        command.extend(["--run-contract-path", str(config_path)])
    else:
        command.extend(["--run-contract-json", config.to_json_text()])
    for package_name in config.artifacts.scx_packages:
        command.extend(["--scx-package", package_name])
    command.extend(suite_args)
    return command


def build_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
    config_path: Path | None = None,
) -> list[str]:
    suite_name = config.identity.suite_name
    if suite_name == "micro":
        return build_micro_suite_argv(workspace, config, suite_args, die=die)
    if suite_name == "corpus":
        return build_corpus_suite_argv(workspace, config, suite_args, die=die)
    if suite_name == "e2e":
        return build_e2e_suite_argv(workspace, config, suite_args, die=die)
    if suite_name == "test":
        return build_test_suite_argv(workspace, config, suite_args, die=die, config_path=config_path)
    die(f"unsupported suite: {suite_name}")
    raise AssertionError("unreachable")
