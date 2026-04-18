"""Shared utilities for standalone suite entrypoints."""
from __future__ import annotations

import argparse
import os
import shlex
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Sequence

from runner.libs.workspace_layout import (
    daemon_binary_path,
    inside_runtime_image,
    kernel_modules_root,
    runtime_path_value,
    runtime_repo_artifact_root,
    runtime_workload_tools_root,
)


# ---------------------------------------------------------------------------
# arch / token normalisation
# ---------------------------------------------------------------------------

def normalize_target_arch(target_arch: str) -> str:
    normalized = str(target_arch).strip()
    if normalized in {"x86", "x86-64", "amd64"}:
        return "x86_64"
    if normalized == "aarch64":
        return "arm64"
    return normalized


def csv_tokens(value: str) -> list[str]:
    return [token.strip() for token in str(value or "").split(",") if token.strip()]


def merge_csv_and_repeated(csv_value: str, repeated_values: Sequence[str] | None) -> list[str]:
    merged: list[str] = []
    for token in [*csv_tokens(csv_value), *(repeated_values or [])]:
        normalized = str(token).strip()
        if normalized and normalized not in merged:
            merged.append(normalized)
    return merged


# ---------------------------------------------------------------------------
# runtime env / PATH helpers
# ---------------------------------------------------------------------------

def cross_runtime_ld_library_path(workspace: Path, target_arch: str) -> str:
    if target_arch != "arm64":
        return ""
    entries: list[str] = []
    for path in (workspace / "tests" / "unittest" / "build-arm64" / "lib",):
        if path.is_dir():
            entries.append(str(path))
    return ":".join(entries)


def suite_runtime_ld_library_path(workspace: Path, target_arch: str) -> str:
    workload_root = runtime_workload_tools_root(workspace, target_arch)
    # Keep broad artifact lib directories out of the suite process environment:
    # Tracee, BCC, Katran, and workload-tools roots can contain libraries from
    # the build container. Only add narrow runtime library roots that are
    # needed by app-managed binaries and do not shadow system libraries.
    candidates = [
        workload_root / "lib" / "luajit",
    ]
    entries = [str(path) for path in candidates if path.is_dir()]
    for extra in (cross_runtime_ld_library_path(workspace, target_arch),):
        if extra:
            entries.extend(entry for entry in extra.split(":") if entry)
    ordered: list[str] = []
    for entry in entries:
        if entry and entry not in ordered:
            ordered.append(entry)
    return ":".join(ordered)


def env_with_suite_runtime_ld(workspace: Path, target_arch: str, env: dict[str, str]) -> tuple[dict[str, str], str]:
    runtime_env = env.copy()
    runtime_ld = suite_runtime_ld_library_path(workspace, target_arch)
    if runtime_ld:
        runtime_env["LD_LIBRARY_PATH"] = runtime_ld
    return runtime_env, runtime_ld


# ---------------------------------------------------------------------------
# executable resolution
# ---------------------------------------------------------------------------

def resolve_executable(path_or_name: str, *, path_value: str, description: str, die: object) -> str:
    """Resolve an executable by name or path; call die(message) on failure."""
    if not path_or_name:
        die(f"{description} is empty")  # type: ignore[operator]
        raise AssertionError("unreachable")
    resolved = shutil.which(path_or_name, path=path_value)
    if resolved is not None:
        return resolved
    candidate = Path(path_or_name).expanduser()
    if candidate.is_file() and os.access(candidate, os.X_OK):
        return str(candidate.resolve())
    die(f"{description} is missing or not executable: {path_or_name}")  # type: ignore[operator]
    raise AssertionError("unreachable")


def require_executable(path: Path, description: str, die: object) -> Path:
    if not path.is_file() or not os.access(path, os.X_OK):
        die(f"{description} is missing or not executable: {path}")  # type: ignore[operator]
        raise AssertionError("unreachable")
    return path


def resolve_workspace_path(workspace: Path, value: str) -> Path:
    path = Path(value)
    return path if path.is_absolute() else (workspace / path).resolve()


def resolve_daemon_binary(workspace: Path, target_arch: str, override: str, die: object) -> Path:
    if override:
        candidate = resolve_workspace_path(workspace, override)
    else:
        candidate = daemon_binary_path(workspace, target_arch)
    return require_executable(candidate, "daemon artifact", die)


# ---------------------------------------------------------------------------
# subprocess helpers
# ---------------------------------------------------------------------------

def run_checked(command: Sequence[str], *, cwd: Path, env: dict[str, str], die: object) -> None:
    completed = subprocess.run(list(command), cwd=cwd, env=env, text=True, check=False)
    if completed.returncode != 0:
        rendered = " ".join(shlex.quote(part) for part in command)
        die(f"command failed ({completed.returncode}): {rendered}")  # type: ignore[operator]


def argv_option_value(argv: Sequence[str], option: str, die: object) -> str:
    for index, token in enumerate(argv):
        if token == option:
            if index + 1 >= len(argv):
                die(f"missing value for {option}")  # type: ignore[operator]
                raise AssertionError("unreachable")
            return str(argv[index + 1]).strip()
        if token.startswith(option + "="):
            return token.split("=", 1)[1].strip()
    return ""


# ---------------------------------------------------------------------------
# artifact validation
# ---------------------------------------------------------------------------

def ensure_scx_artifacts(workspace: Path, target_arch: str, packages: Sequence[str], die: object) -> None:
    scx_root = runtime_repo_artifact_root(workspace, target_arch) / "scx"
    for package in packages:
        for target in (scx_root / "bin" / package, scx_root / f"{package}_main.bpf.o"):
            if target.name.endswith(".bpf.o"):
                if not target.is_file():
                    die(f"scx artifact object is missing: {target}")  # type: ignore[operator]
                continue
            require_executable(target, "scx artifact", die)


def ensure_katran_artifacts(workspace: Path, target_arch: str, native_repos: Sequence[str], die: object) -> None:
    if "katran" not in native_repos:
        return
    katran_root = runtime_repo_artifact_root(workspace, target_arch) / "katran"
    katran_targets = [
        katran_root / "bin" / "katran_server_grpc",
        katran_root / "bpf" / "balancer.bpf.o",
        katran_root / "bpf" / "healthchecking_ipip.bpf.o",
    ]
    for target in katran_targets:
        if target.name == "katran_server_grpc":
            require_executable(target, "Katran server artifact", die)
            continue
        if not target.is_file():
            die(f"Katran artifact is missing: {target}")  # type: ignore[operator]
    katran_lib_root = katran_root / "lib"
    if not katran_lib_root.is_dir():
        die(f"Katran runtime library artifact directory is missing: {katran_lib_root}")  # type: ignore[operator]


# ---------------------------------------------------------------------------
# kernel helpers
# ---------------------------------------------------------------------------

def ensure_bpf_stats_enabled(workspace: Path, die: object) -> None:
    bpf_stats_path = Path("/proc/sys/kernel/bpf_stats_enabled")
    sysctl_bin = shutil.which("sysctl")
    if sysctl_bin:
        run_checked(
            [sysctl_bin, "-q", "-w", "kernel.bpf_stats_enabled=1"],
            cwd=workspace,
            env={"PATH": os.environ.get("PATH", "") or "/usr/sbin:/usr/bin:/sbin:/bin"},
            die=die,
        )
    else:
        run_checked(
            ["sh", "-c", "printf '1\\n' > /proc/sys/kernel/bpf_stats_enabled"],
            cwd=workspace,
            env=os.environ.copy(),
            die=die,
        )
    if bpf_stats_path.read_text(encoding="utf-8").strip() != "1":
        die("failed to enable kernel.bpf_stats_enabled=1")  # type: ignore[operator]


# ---------------------------------------------------------------------------
# TMPDIR / runtime env base
# ---------------------------------------------------------------------------

def make_runtime_tmpdir(scratch_token: str) -> str:
    runtime_tmpdir = Path("/var/tmp/bpfrejit-runtime") / scratch_token
    runtime_tmpdir.mkdir(parents=True, exist_ok=True)
    runtime_tmpdir.chmod(0o1777)
    return str(runtime_tmpdir)


def base_runtime_env() -> dict[str, str]:
    """Copy standard env vars from the host environment."""
    return {
        name: value
        for name in (
            "HOME",
            "USER",
            "LOGNAME",
            "TERM",
            "TMPDIR",
            "LANG",
            "LC_ALL",
            "LC_CTYPE",
            "SHELL",
            "BPFREJIT_INSIDE_RUNTIME_CONTAINER",
            "BPFREJIT_IMAGE_WORKSPACE",
            "RUN_TARGET_ARCH",
        )
        if (value := os.environ.get(name, "").strip())
    }


def setup_tmpdir(env: dict[str, str], scratch_token: str) -> None:
    """Ensure TMPDIR is set (and created/chmod'd) in *env* in-place."""
    if not env.get("TMPDIR"):
        env["TMPDIR"] = make_runtime_tmpdir(scratch_token)
    else:
        Path(env["TMPDIR"]).mkdir(parents=True, exist_ok=True)
        Path(env["TMPDIR"]).chmod(0o1777)
    env.setdefault("TMP", env["TMPDIR"])
    env.setdefault("TEMP", env["TMPDIR"])
    env["BPFREJIT_RUNTIME_TMPDIR"] = env["TMPDIR"]


# ---------------------------------------------------------------------------
# Shared argparse helpers
# ---------------------------------------------------------------------------

def add_common_args(parser: argparse.ArgumentParser) -> None:
    """Add the standard arguments shared by all suite entrypoints."""
    parser.add_argument("--workspace", help="Benchmark workspace root.")
    parser.add_argument(
        "--target-arch",
        "--arch",
        dest="target_arch",
        default="x86_64",
        help="Target artifact architecture, for example x86, x86_64, aarch64, or arm64.",
    )
    parser.add_argument("--target-name", default="local", help="Target name used for run identity.")
    parser.add_argument("--executor", default="local", help="Executor name used for artifact path resolution.")
    parser.add_argument("--run-token", default="", help="Run token used for runtime scratch directories.")
    parser.add_argument("--python-bin", default="", help="Python binary used to run the suite driver.")
    parser.add_argument("--bpftool-bin", default="bpftool", help="bpftool binary name or path.")


def positive_int(value: str) -> int:
    parsed = int(value)
    if parsed <= 0:
        raise argparse.ArgumentTypeError("must be > 0")
    return parsed


def nonnegative_int(value: str) -> int:
    parsed = int(value)
    if parsed < 0:
        raise argparse.ArgumentTypeError("must be >= 0")
    return parsed


# ---------------------------------------------------------------------------
# Shared main() skeleton
# ---------------------------------------------------------------------------

def suite_main_setup(args: argparse.Namespace, default_workspace: str, die: object) -> Path:
    """Resolve workspace, normalise arch, validate workspace dir.

    Mutates args.workspace and args.target_arch in-place.
    Returns the resolved workspace Path.
    """
    if not args.workspace:
        args.workspace = default_workspace
    workspace = Path(args.workspace).resolve()
    args.workspace = str(workspace)
    args.target_arch = normalize_target_arch(args.target_arch)
    if not workspace.is_dir():
        die(f"workspace is missing: {workspace}")  # type: ignore[operator]
    return workspace


# ---------------------------------------------------------------------------
# Shared runtime env base (corpus / e2e / test share the same core)
# ---------------------------------------------------------------------------

def base_suite_runtime_env(
    workspace: Path,
    args: argparse.Namespace,
    scratch_suffix: str,
    die: object,
) -> dict[str, str]:
    """Build the common portion of the runtime env for corpus/e2e/test suites.

    Sets: TMPDIR, PATH, BPFREJIT_WORKLOAD_TOOL_BIN_DIR (if present),
    BPFREJIT_REPO_ARTIFACT_ROOT, BPFREJIT_REMOTE_PYTHON_BIN,
    BPFREJIT_KERNEL_MODULES_ROOT, PYTHONPATH, BPFTOOL_BIN.
    """
    env = base_runtime_env()
    setup_tmpdir(env, args.run_token or f"{args.target_name}_{scratch_suffix}")
    env["PATH"] = runtime_path_value(workspace, args.target_arch)
    workload_tool_bin = runtime_workload_tools_root(workspace, args.target_arch) / "bin"
    if workload_tool_bin.is_dir():
        env["BPFREJIT_WORKLOAD_TOOL_BIN_DIR"] = str(workload_tool_bin)
    env["BPFREJIT_REPO_ARTIFACT_ROOT"] = str(runtime_repo_artifact_root(workspace, args.target_arch))
    env["BPFREJIT_REMOTE_PYTHON_BIN"] = args.python_bin or sys.executable
    kernel_modules_dir = kernel_modules_root(workspace, args.target_arch, args.executor)
    if not kernel_modules_dir.is_dir():
        die(f"kernel module artifact root is missing: {kernel_modules_dir}")  # type: ignore[operator]
    env["BPFREJIT_KERNEL_MODULES_ROOT"] = str(kernel_modules_dir)
    env["PYTHONPATH"] = str(workspace)
    env["BPFTOOL_BIN"] = args.bpftool_bin
    return env
