"""Shared suite command-line builder.

Both kvm_executor (which shell-quotes the result) and aws_remote_host
(which passes the list directly to subprocess) use this to construct the
argv for ``python -m runner.suites.<name>``.
"""
from __future__ import annotations

from pathlib import Path
from typing import Any


def _required(value: str, name: str, die: Any) -> str:
    normalized = str(value).strip()
    if not normalized:
        die(f"run config {name} is empty")
    return normalized


def _append_runtime_container_args(command: list[str], config: Any) -> None:
    if config.remote.container_runtime:
        command.extend(["--container-runtime", config.remote.container_runtime])
    if config.remote.runtime_container_image:
        command.extend(["--runtime-container-image", config.remote.runtime_container_image])
    if config.remote.runtime_python_bin:
        command.extend(["--runtime-python-bin", config.remote.runtime_python_bin])


def build_micro_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    from runner.libs.workspace_layout import micro_program_root, runner_binary_path

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
        "--runner-binary", str(runner_binary_path(workspace, target_arch)),
        "--program-dir", str(micro_program_root(workspace, target_arch)),
        "--output", str(workspace / "micro" / "results" / f"{target_name}_micro.json"),
    ]
    _append_runtime_container_args(command, config)
    command.extend(suite_args)
    return command


def build_corpus_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    from runner.libs.workspace_layout import daemon_binary_path

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
        "--daemon-binary", str(daemon_binary_path(workspace, target_arch)),
        "--output-json", str(workspace / "corpus" / "results" / f"{target_name}_corpus.json"),
        "--output-md", str(workspace / "corpus" / "results" / f"{target_name}_corpus.md"),
    ]
    for repo_name in config.artifacts.native_repos:
        command.extend(["--native-repo", repo_name])
    for package_name in config.artifacts.scx_packages:
        command.extend(["--scx-package", package_name])
    _append_runtime_container_args(command, config)
    command.extend(suite_args)
    return command


def build_e2e_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    from runner.libs.workspace_layout import daemon_binary_path

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
        "--daemon-binary", str(daemon_binary_path(workspace, target_arch)),
    ]
    for repo_name in config.artifacts.native_repos:
        command.extend(["--native-repo", repo_name])
    for package_name in config.artifacts.scx_packages:
        command.extend(["--scx-package", package_name])
    _append_runtime_container_args(command, config)
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
    from runner.libs.workspace_layout import daemon_binary_path

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
        "--daemon-binary", str(daemon_binary_path(workspace, target_arch)),
        "--artifact-dir", str(workspace / "tests" / "results" / run_token),
    ]
    if config_path is not None:
        command.extend(["--run-contract-path", str(config_path)])
    else:
        command.extend(["--run-contract-json", config.to_json_text()])
    for package_name in config.artifacts.scx_packages:
        command.extend(["--scx-package", package_name])
    _append_runtime_container_args(command, config)
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
