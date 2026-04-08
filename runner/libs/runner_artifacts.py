from __future__ import annotations

import os
import subprocess
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail, require_path as _require_path


die = partial(fail, "runner-artifacts")
require_path = partial(_require_path, tag="runner-artifacts")


def require_file_contains(path: Path, needle: str, description: str) -> None:
    require_path(path, description)
    completed = subprocess.run(
        ["file", "-L", str(path)],
        check=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    if completed.returncode != 0 or needle not in completed.stdout:
        die(f"{description} does not match expected file signature {needle}: {path}")


def run_command(command: list[str], *, env: dict[str, str], cwd: Path = ROOT_DIR) -> None:
    completed = subprocess.run(
        command,
        cwd=cwd,
        env=env,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def jobs_from_env(env: dict[str, str], *, default: int | None = None) -> str:
    explicit = env.get("JOBS", "").strip()
    if explicit:
        return explicit
    if default is not None:
        return str(default)
    return str(max(os.cpu_count() or 1, 1))


def resolve_llvm_cmake_dir(env: dict[str, str]) -> str:
    explicit = env.get("RUN_LLVM_DIR", "").strip()
    if explicit:
        return explicit
    return env.get("LLVM_DIR", "").strip()


def _build_llvmbpf_library(
    *,
    build_dir: Path,
    llvm_dir: str,
    env: dict[str, str],
    jobs: str,
) -> tuple[str, str, str]:
    llvmbpf_build_dir = build_dir / "vendor" / "llvmbpf"
    llvmbpf_build_dir.mkdir(parents=True, exist_ok=True)
    run_command(
        [
            "cmake",
            "-S",
            str(ROOT_DIR / "vendor" / "llvmbpf"),
            "-B",
            str(llvmbpf_build_dir),
            "-DCMAKE_BUILD_TYPE=Release",
            f"-DLLVM_DIR={llvm_dir}",
        ],
        env=env,
    )
    run_command(
        [
            "cmake",
            "--build",
            str(llvmbpf_build_dir),
            "--target",
            "llvmbpf_vm",
            "-j",
            jobs,
        ],
        env=env,
    )
    llvmbpf_library = llvmbpf_build_dir / "libllvmbpf_vm.a"
    require_path(llvmbpf_library, "llvmbpf static library")
    spdlog_library = ""
    for candidate in (
        llvmbpf_build_dir / "_deps" / "spdlog-build" / "libspdlogd.a",
        llvmbpf_build_dir / "_deps" / "spdlog-build" / "libspdlog.a",
    ):
        if candidate.is_file():
            spdlog_library = str(candidate.resolve())
            break
    build_cache = llvmbpf_build_dir / "CMakeCache.txt"
    return str(llvmbpf_library.resolve()), str(build_cache.resolve()), spdlog_library


def build_vendor_bpftool(
    *,
    build_dir: Path,
    env: dict[str, str],
    expected_arch_signature: str | None = None,
) -> Path:
    jobs = env.get("BPFTOOL_JOBS", "").strip() or "1"
    output_dir = build_dir / "vendor" / "bpftool"
    output_dir.mkdir(parents=True, exist_ok=True)
    run_command(
        [
            "make",
            "-C",
            str(ROOT_DIR / "vendor" / "bpftool" / "src"),
            f"-j{jobs}",
            f"OUTPUT={output_dir}/",
            f"BPF_DIR={ROOT_DIR / 'vendor' / 'libbpf' / 'src'}",
            "bootstrap",
        ],
        env=env,
    )
    binary = output_dir / "bootstrap" / "bpftool"
    require_path(binary, "vendored bpftool bootstrap binary")
    if expected_arch_signature:
        require_file_contains(binary, expected_arch_signature, "vendored bpftool bootstrap binary")
    return binary


def build_runner_binary(
    *,
    build_dir: Path,
    env: dict[str, str],
    expected_arch_signature: str | None = None,
    llvmbpf_default: str = "ON",
) -> Path:
    jobs = jobs_from_env(env)
    libbpf_build_dir = build_dir / "vendor" / "libbpf"
    libbpf_objdir = libbpf_build_dir / "obj"
    libbpf_prefix = libbpf_build_dir / "prefix"
    libbpf_a = libbpf_objdir / "libbpf.a"
    llvmbpf_setting = env.get("MICRO_EXEC_ENABLE_LLVMBPF", llvmbpf_default).strip() or llvmbpf_default
    libbpf_objdir.mkdir(parents=True, exist_ok=True)
    (libbpf_prefix / "include").mkdir(parents=True, exist_ok=True)
    run_command(
        [
            "make",
            "-C",
            str(ROOT_DIR / "vendor" / "libbpf" / "src"),
            f"-j{jobs}",
            "BUILD_STATIC_ONLY=1",
            f"OBJDIR={libbpf_objdir}",
            "DESTDIR=",
            f"PREFIX={libbpf_prefix}",
            str(libbpf_a),
            "install_headers",
        ],
        env=env,
    )
    cmake_command = [
        "cmake",
        "-S",
        str(ROOT_DIR / "runner"),
        "-B",
        str(build_dir),
        "-DCMAKE_BUILD_TYPE=Release",
        f"-DMICRO_REPO_ROOT={ROOT_DIR}",
        f"-DMICRO_LIBBPF_PREFIX={libbpf_prefix}",
        f"-DMICRO_LIBBPF_LIBRARY={libbpf_a}",
        f"-DMICRO_EXEC_ENABLE_LLVMBPF={llvmbpf_setting}",
    ]
    llvm_dir = resolve_llvm_cmake_dir(env)
    if llvmbpf_setting == "ON":
        if not llvm_dir:
            die("MICRO_EXEC_ENABLE_LLVMBPF=ON requires RUN_LLVM_DIR")
        cmake_command.append(f"-DLLVM_DIR={llvm_dir}")
    micro_llvmbpf_library = env.get("MICRO_LLVMBPF_LIBRARY", "").strip()
    micro_llvmbpf_build_cache = env.get("MICRO_LLVMBPF_BUILD_CACHE", "").strip()
    micro_llvmbpf_spdlog_library = env.get("MICRO_LLVMBPF_SPDLOG_LIBRARY", "").strip()
    if llvmbpf_setting == "ON" and not micro_llvmbpf_library:
        (
            micro_llvmbpf_library,
            micro_llvmbpf_build_cache,
            built_spdlog_library,
        ) = _build_llvmbpf_library(
            build_dir=build_dir,
            llvm_dir=llvm_dir,
            env=env,
            jobs=jobs,
        )
        if not micro_llvmbpf_spdlog_library:
            micro_llvmbpf_spdlog_library = built_spdlog_library
    if micro_llvmbpf_library:
        cmake_command.append(f"-DMICRO_LLVMBPF_LIBRARY={micro_llvmbpf_library}")
    if micro_llvmbpf_build_cache:
        cmake_command.append(f"-DMICRO_LLVMBPF_BUILD_CACHE={micro_llvmbpf_build_cache}")
    if micro_llvmbpf_spdlog_library:
        cmake_command.append(f"-DMICRO_LLVMBPF_SPDLOG_LIBRARY={micro_llvmbpf_spdlog_library}")
    run_command(cmake_command, env=env)
    run_command(
        [
            "cmake",
            "--build",
            str(build_dir),
            "--target",
            "micro_exec",
            "-j",
            jobs,
        ],
        env=env,
    )
    binary = build_dir / "micro_exec"
    require_path(binary, "runner binary")
    if expected_arch_signature:
        require_file_contains(binary, expected_arch_signature, "runner binary")
    return binary
