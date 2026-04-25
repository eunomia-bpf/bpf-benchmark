"""Shared suite and runtime image command-line builders."""
from __future__ import annotations

from dataclasses import replace
from pathlib import Path
from typing import Any

from runner.libs.workspace_layout import RUNTIME_IMAGE_WORKSPACE


_CONTAINER_RESULT_DIR_BY_SUITE = {
    "micro": "micro/results",
    "corpus": "corpus/results",
    "e2e": "e2e/results",
    "test": "tests/results",
}
_CONTAINER_RUNTIME_TMP_DIR = "docs/tmp/runtime-container-tmp"


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


def runtime_container_host_dirs(host_workspace: Path, suite_name: str, *, die: Any) -> list[Path]:
    return [*runtime_container_result_dirs(host_workspace, suite_name, die=die), host_workspace / _CONTAINER_RUNTIME_TMP_DIR]


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
    remote_python = _required(config.remote.python_bin, "RUN_REMOTE_PYTHON_BIN", die)
    return [
        remote_python,
        "-m",
        suite_module,
        "--workspace",
        str(workspace),
        "--target-arch",
        _required(config.identity.target_arch, "RUN_TARGET_ARCH", die),
        "--target-name",
        _required(config.identity.target_name, "RUN_TARGET_NAME", die),
        "--executor",
        _required(config.identity.executor, "RUN_EXECUTOR", die),
        "--run-token",
        _required(config.identity.token, "RUN_TOKEN", die),
        "--python-bin",
        remote_python,
        "--bpftool-bin",
        _required(config.remote.bpftool_bin, "RUN_BPFTOOL_BIN", die),
    ]


def _append_artifact_args(
    argv: list[str],
    *,
    native_repos: tuple[str, ...] | list[str] = (),
    scx_packages: tuple[str, ...] | list[str] = (),
) -> None:
    if native_repos:
        argv.extend(["--native-repos", ",".join(str(repo_name) for repo_name in native_repos)])
    if scx_packages:
        argv.extend(["--scx-packages", ",".join(str(package_name) for package_name in scx_packages)])


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
    suite_argv = build_suite_argv(
        image_workspace,
        _container_suite_config(config, runtime_python),
        suite_args,
        die=die,
    )
    if len(suite_argv) < 3 or suite_argv[1] != "-m":
        die(f"unexpected suite argv shape: {suite_argv}")
    command = [
        "docker",
        "run",
        "--rm",
        "--privileged",
        "--pid=host",
        "--network=host",
        "--ipc=host",
        "-e",
        "BPFREJIT_INSIDE_RUNTIME_CONTAINER=1",
        "-e",
        "HOME=/root",
        "-w",
        str(image_workspace),
        "-v",
        f"{host_workspace}:{image_workspace}",
    ]
    for result_dir in runtime_container_result_dirs(host_workspace, suite_name, die=die):
        command.extend(["-v", f"{result_dir}:{image_workspace / result_dir.relative_to(host_workspace)}"])
    command.extend([
        "-v",
        f"{host_workspace / _CONTAINER_RUNTIME_TMP_DIR}:/var/tmp/bpfrejit-runtime",
    ])
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
    target_name = _required(config.identity.target_name, "RUN_TARGET_NAME", die)
    command = _build_base_suite_argv(workspace, "runner.suites.micro", config, die=die)
    command.extend([
        "--output",
        str(workspace / "micro" / "results" / f"{target_name}_micro.json"),
    ])
    command.extend(suite_args)
    return command


def build_corpus_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    target_name = _required(config.identity.target_name, "RUN_TARGET_NAME", die)
    command = _build_base_suite_argv(workspace, "runner.suites.corpus", config, die=die)
    command.extend([
        "--output-json",
        str(workspace / "corpus" / "results" / f"{target_name}_corpus.json"),
    ])
    _append_artifact_args(
        command,
        native_repos=config.artifacts.native_repos,
        scx_packages=config.artifacts.scx_packages,
    )
    command.extend(suite_args)
    return command


def build_e2e_suite_argv(
    workspace: Path,
    config: Any,
    suite_args: list[str],
    *,
    die: Any,
) -> list[str]:
    command = _build_base_suite_argv(workspace, "runner.suites.e2e", config, die=die)
    _append_artifact_args(
        command,
        native_repos=config.artifacts.native_repos,
        scx_packages=config.artifacts.scx_packages,
    )
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
    run_token = _required(config.identity.token, "RUN_TOKEN", die)
    command = _build_base_suite_argv(workspace, "runner.suites.test", config, die=die)
    command.extend(["--artifact-dir", str(workspace / "tests" / "results" / run_token)])
    if config_path is not None:
        command.extend(["--run-contract-path", str(config_path)])
    else:
        command.extend(["--run-contract-json", config.to_json_text()])
    _append_artifact_args(command, scx_packages=config.artifacts.scx_packages)
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
