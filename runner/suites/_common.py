"""Shared utilities for standalone suite entrypoints."""
from __future__ import annotations

import argparse
import os
import shlex
import shutil
import subprocess
import sys
import time
from pathlib import Path
from typing import Sequence

from runner.libs.workspace_layout import (
    daemon_binary_path,
    inside_runtime_image as inside_runtime_container,
    kernel_modules_root,
    runtime_container_image_tar_path,
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
# container helpers
# ---------------------------------------------------------------------------

def append_bind_mount(command: list[str], source: Path, target: Path | None = None, *, readonly: bool = False) -> None:
    if not source.exists():
        return
    destination = target or source
    suffix = ":ro" if readonly else ""
    command.extend(["-v", f"{source}:{destination}{suffix}"])


def _command_summary(command: Sequence[str], result: subprocess.CompletedProcess[str]) -> str:
    output = (result.stderr.strip() or result.stdout.strip())[-1000:]
    suffix = f": {output}" if output else ""
    return f"{shlex.join(command)} exited {result.returncode}{suffix}"


def _try_start_container_runtime(runtime: str) -> str:
    if Path(runtime).name != "docker":
        return ""
    attempts: list[str] = []
    for command in (["systemctl", "start", "docker"], ["service", "docker", "start"]):
        if shutil.which(command[0]) is None:
            attempts.append(f"{command[0]} not found")
            continue
        try:
            result = subprocess.run(command, capture_output=True, text=True, check=False, timeout=20)
        except subprocess.TimeoutExpired:
            attempts.append(f"{shlex.join(command)} timed out")
            continue
        attempts.append(_command_summary(command, result))
        if result.returncode == 0:
            return "\n".join(attempts)
    if shutil.which("dockerd") is None:
        attempts.append("dockerd not found")
        return "\n".join(attempts)
    Path("/var/run").mkdir(parents=True, exist_ok=True)
    dockerd_log = Path("/tmp/bpf-benchmark-dockerd.log")
    log_file = dockerd_log.open("ab")
    subprocess.Popen(
        [
            "dockerd",
            "--host=unix:///var/run/docker.sock",
            "--data-root=/tmp/bpf-benchmark-docker",
            "--exec-root=/tmp/bpf-benchmark-docker-exec",
            "--pidfile=/tmp/bpf-benchmark-docker.pid",
        ],
        stdout=log_file,
        stderr=log_file,
        start_new_session=True,
    )
    attempts.append(f"started dockerd, log={dockerd_log}")
    return "\n".join(attempts)


def _dockerd_log_tail() -> str:
    path = Path("/tmp/bpf-benchmark-dockerd.log")
    if not path.is_file():
        return ""
    return path.read_text(encoding="utf-8", errors="replace")[-2000:]


def _ensure_runtime_container_image(workspace: str, container_runtime: str, image: str, target_arch: str) -> None:
    """Load the container image from the cached tar if it is not already present."""
    runtime = container_runtime or "docker"
    last_error = ""
    start_detail = ""
    start_attempted = False
    for _ in range(120):
        info_result = subprocess.run(
            [runtime, "info"],
            capture_output=True, text=True, check=False,
        )
        if info_result.returncode == 0:
            break
        last_error = (info_result.stderr.strip() or info_result.stdout.strip())[-1000:]
        if not start_attempted:
            start_detail = _try_start_container_runtime(runtime)
            start_attempted = True
        time.sleep(1)
    else:
        details = [part for part in (last_error, start_detail, _dockerd_log_tail()) if part]
        detail = ":\n" + "\n".join(details) if details else ""
        raise SystemExit(f"container runtime '{runtime}' is unavailable{detail}")
    inspect_result = subprocess.run(
        [runtime, "image", "inspect", image],
        capture_output=True, text=True, check=False,
    )
    if inspect_result.returncode == 0:
        return
    tar_path = runtime_container_image_tar_path(Path(workspace), target_arch)
    if not tar_path.is_file():
        raise SystemExit(
            f"runtime container image '{image}' not found locally and tar is missing: {tar_path}"
        )
    load_result = subprocess.run(
        [runtime, "load", "-i", str(tar_path)],
        text=True, check=False,
    )
    if load_result.returncode != 0:
        raise SystemExit(
            f"failed to load runtime container image from {tar_path} (exit {load_result.returncode})"
        )


def run_in_runtime_container(workspace: str, args_module: str, module_argv: list[str],
                              container_runtime: str, image: str, runtime_python_bin: str,
                              target_arch: str = "") -> None:
    if not image:
        raise SystemExit("runtime container image is empty")
    _ensure_runtime_container_image(workspace, container_runtime, image, target_arch)
    command = [
        container_runtime or "docker",
        "run",
        "--rm",
        "--privileged",
        "--pid=host",
        "--network=host",
        "--ipc=host",
        "-e",
        "BPFREJIT_INSIDE_RUNTIME_CONTAINER=1",
        "-e",
        f"PYTHONPATH={workspace}",
        "-e",
        "HOME=/root",
        "-v",
        f"{workspace}:{workspace}",
        "-w",
        workspace,
    ]
    for name in ("TMPDIR", "TMP", "TEMP", "BPFREJIT_RUNTIME_TMPDIR"):
        if value := os.environ.get(name, "").strip():
            command.extend(["-e", f"{name}={value}"])
    append_bind_mount(command, Path("/sys"))
    append_bind_mount(command, Path("/sys/fs/bpf"))
    append_bind_mount(command, Path("/sys/kernel/debug"))
    append_bind_mount(command, Path("/lib/modules"), readonly=True)
    append_bind_mount(command, Path("/boot"), readonly=True)
    command.extend([image, runtime_python_bin or "python3", "-m", args_module, *module_argv])
    completed = subprocess.run(command, cwd=workspace, text=True, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


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
        for name in ("HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL")
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
    parser.add_argument("--container-runtime", default="docker", help="Container runtime for runtime-container mode.")
    parser.add_argument("--runtime-container-image", default="", help="Runtime container image. Empty disables container mode.")
    parser.add_argument("--runtime-python-bin", default="python3", help="Python binary used inside the runtime container.")


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
