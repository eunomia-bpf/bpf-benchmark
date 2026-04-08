from __future__ import annotations

import os
import shutil
import subprocess
from functools import partial
from pathlib import Path
from typing import Callable

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail, require_nonempty_dir as _require_nonempty_dir, require_path as _require_path
from runner.libs.state_file import write_state


SUPPORTED_BUNDLED_X86_TOOLS = {"wrk", "sysbench", "hackbench", "stress-ng", "fio", "bpftrace"}


die = partial(fail, "local-prep")
require_path = partial(_require_path, tag="local-prep")
require_nonempty_dir = partial(_require_nonempty_dir, tag="local-prep")


def csv_tokens(value: str) -> list[str]:
    return [token for token in value.split(",") if token]


def csv_append_unique(csv: str, token: str) -> str:
    if not token:
        return csv
    tokens = csv_tokens(csv)
    if token in tokens:
        return csv
    return token if not csv else f"{csv},{token}"


def require_file_contains(path: Path, needle: str, description: str) -> None:
    require_path(path, description)
    completed = subprocess.run(
        ["file", str(path)],
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


def run_local_prep_phases(*, phases: list[str], phase_handlers: dict[str, Callable[[], None]], executor_name: str) -> None:
    for phase in phases:
        handler = phase_handlers.get(phase)
        if handler is None:
            die(f"no local-prep phase mapping for {executor_name}:{phase}")
        handler()


def x86_bundle_inputs(
    *,
    promote_root: Path,
    local_repo_root: Path,
    test_artifacts_root: Path,
    portable_libbpf_root: Path | None = None,
) -> dict[str, str]:
    values = {
        "X86_RUNNER": str(promote_root / "runner" / "build" / "micro_exec"),
        "X86_DAEMON": str(promote_root / "daemon" / "target" / "release" / "bpfrejit-daemon"),
        "X86_TEST_UNITTEST_BUILD_DIR": str(test_artifacts_root / "unittest" / "build"),
        "X86_TEST_NEGATIVE_BUILD_DIR": str(test_artifacts_root / "negative" / "build"),
        "X86_UPSTREAM_SELFTEST_DIR": str(test_artifacts_root / "upstream-bpf-selftests"),
        "X86_NATIVE_BUILD_ROOT": str(promote_root / "corpus" / "build"),
        "X86_SCX_BINARY_ROOT": str(local_repo_root / "scx" / "target" / "release"),
        "X86_SCX_OBJECT_ROOT": str(promote_root / "corpus" / "build" / "scx"),
        "X86_KATRAN_SERVER_BINARY": str(promote_root / "corpus" / "build" / "katran" / "bin" / "katran_server_grpc"),
        "X86_KATRAN_SERVER_LIB_DIR": str(promote_root / "corpus" / "build" / "katran" / "lib"),
    }
    if portable_libbpf_root is not None and (portable_libbpf_root / "lib").is_dir():
        values["X86_PORTABLE_LIBBPF_ROOT"] = str(portable_libbpf_root)
    return values


def _jobs_from_env(env: dict[str, str]) -> str:
    explicit = env.get("JOBS", "").strip()
    if explicit:
        return explicit
    return str(max(os.cpu_count() or 1, 1))


def _resolve_llvm_cmake_dir(env: dict[str, str]) -> str:
    explicit = env.get("LLVM_DIR", "").strip()
    if explicit:
        return explicit
    llvm_config = env.get("LLVM_CONFIG", "").strip()
    if not llvm_config:
        llvm_config = shutil.which("llvm-config") or ""
    if llvm_config:
        completed = subprocess.run(
            [llvm_config, "--cmakedir"],
            check=False,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        if completed.returncode == 0:
            cmake_dir = completed.stdout.strip()
            if cmake_dir:
                return cmake_dir
    cache_path = ROOT_DIR / "vendor" / "llvmbpf" / "build" / "CMakeCache.txt"
    if cache_path.is_file():
        for line in cache_path.read_text(encoding="utf-8").splitlines():
            prefix = "LLVM_DIR:PATH="
            if line.startswith(prefix):
                return line.removeprefix(prefix).strip()
    return ""


def finalize_staged_bundle(
    *,
    manifest_path: Path,
    bundle_inputs_path: Path,
    stage_root: Path,
    bundle_tar: Path,
    local_state_path: Path,
    host_python_bin: str,
    env: dict[str, str],
    executor_name: str,
) -> None:
    stage_root.parent.mkdir(parents=True, exist_ok=True)
    bundle_tar.parent.mkdir(parents=True, exist_ok=True)
    run_command(
        [
            host_python_bin,
            "-m",
            "runner.libs.build_remote_bundle",
            str(manifest_path),
            str(bundle_inputs_path),
            str(stage_root),
            str(bundle_tar),
        ],
        env=env,
    )
    if not bundle_tar.is_file():
        die(f"staged {executor_name} bundle tar is missing: {bundle_tar}")
    write_state(local_state_path, {"RUN_BUNDLE_TAR": str(bundle_tar)})


def run_python_script(
    host_python_bin: str,
    script_rel: str,
    *args: str,
    env: dict[str, str],
) -> None:
    run_command([host_python_bin, str(ROOT_DIR / script_rel), *args], env=env)


def stage_matching_micro_sidecars(output_dir: Path, source_dir: Path) -> None:
    if not output_dir.is_dir() or not source_dir.is_dir():
        return
    for generated_file in output_dir.glob("*.bpf.o"):
        program_name = generated_file.name.removesuffix(".bpf.o")
        for suffix in ("directive.bin", "policy.bin"):
            source = source_dir / f"{program_name}.{suffix}"
            if source.is_file():
                shutil.copy2(source, output_dir / source.name)


def build_x86_runner_binary(*, build_dir: Path, env: dict[str, str]) -> Path:
    jobs = _jobs_from_env(env)
    libbpf_build_dir = build_dir / "vendor" / "libbpf"
    libbpf_objdir = libbpf_build_dir / "obj"
    libbpf_prefix = libbpf_build_dir / "prefix"
    libbpf_a = libbpf_objdir / "libbpf.a"
    llvmbpf_setting = env.get("MICRO_EXEC_ENABLE_LLVMBPF", "ON").strip() or "ON"
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
    llvm_dir = _resolve_llvm_cmake_dir(env)
    if llvm_dir:
        cmake_command.append(f"-DLLVM_DIR={llvm_dir}")
    micro_llvmbpf_library = env.get("MICRO_LLVMBPF_LIBRARY", "").strip()
    if micro_llvmbpf_library:
        cmake_command.append(f"-DMICRO_LLVMBPF_LIBRARY={micro_llvmbpf_library}")
    micro_llvmbpf_build_cache = env.get("MICRO_LLVMBPF_BUILD_CACHE", "").strip()
    if micro_llvmbpf_build_cache:
        cmake_command.append(f"-DMICRO_LLVMBPF_BUILD_CACHE={micro_llvmbpf_build_cache}")
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
    require_file_contains(binary, "x86-64", "x86 runner binary")
    return binary


def build_x86_daemon_binary(*, daemon_target_dir: Path, env: dict[str, str]) -> Path:
    run_command(
        [
            "cargo",
            "build",
            "--release",
            "--target-dir",
            str(daemon_target_dir),
            "--manifest-path",
            str(ROOT_DIR / "daemon" / "Cargo.toml"),
        ],
        env=env,
    )
    binary = daemon_target_dir / "release" / "bpfrejit-daemon"
    require_file_contains(binary, "x86-64", "x86 daemon binary")
    return binary


def build_x86_repo_tests(
    *,
    unittest_build_dir: Path,
    negative_build_dir: Path,
    env: dict[str, str],
    test_mode: str,
) -> None:
    if test_mode in {"selftest", "test"}:
        run_command(
            [
                "make",
                "-C",
                str(ROOT_DIR / "tests" / "unittest"),
                f"BUILD_DIR={unittest_build_dir}",
                "all",
            ],
            env=env,
        )
        run_command(
            [
                "make",
                "-C",
                str(ROOT_DIR / "tests" / "negative"),
                f"BUILD_DIR={negative_build_dir}",
                "all",
            ],
            env=env,
        )
    elif test_mode == "negative":
        run_command(
            [
                "make",
                "-C",
                str(ROOT_DIR / "tests" / "negative"),
                f"BUILD_DIR={negative_build_dir}",
                "all",
            ],
            env=env,
        )
    else:
        die(f"unsupported x86 test mode: {test_mode}")
    if test_mode != "negative":
        require_file_contains(unittest_build_dir / "rejit_kinsn", "x86-64", "x86 unittest binary")
    require_file_contains(negative_build_dir / "adversarial_rejit", "x86-64", "x86 negative binary")


def build_x86_upstream_selftests(
    *,
    output_dir: Path,
    host_python_bin: str,
    env: dict[str, str],
    llvm_suffix: str,
) -> None:
    run_command(
        [host_python_bin, "-m", "runner.libs.build_upstream_selftests"],
        env={
            **env,
            "VMLINUX_BTF": str(ROOT_DIR / "vendor/linux-framework" / "vmlinux"),
            "UPSTREAM_SELFTEST_SOURCE_DIR": str(ROOT_DIR / "vendor/linux-framework" / "tools/testing/selftests/bpf"),
            "UPSTREAM_SELFTEST_OUTPUT_DIR": str(output_dir),
            "UPSTREAM_SELFTEST_HOST_PYTHON_BIN": host_python_bin,
            "UPSTREAM_SELFTEST_LLVM_SUFFIX": llvm_suffix,
            "UPSTREAM_SELFTEST_ARCH": "",
            "UPSTREAM_SELFTEST_CROSS_COMPILE": "",
            "UPSTREAM_SELFTEST_SYSROOT_ROOT": "",
            "UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR": "",
        },
    )
    require_path(output_dir / "test_verifier", "x86 upstream test_verifier")
    require_path(output_dir / "test_progs", "x86 upstream test_progs")


def build_micro_program_outputs(*, output_dir: Path, env: dict[str, str]) -> None:
    run_command(
        [
            "make",
            "-C",
            str(ROOT_DIR / "micro"),
            "programs",
            f"PROGRAM_OUTPUT_DIR={output_dir}",
        ],
        env=env,
    )
    stage_matching_micro_sidecars(output_dir, ROOT_DIR / "micro" / "generated-inputs")
    require_nonempty_dir(output_dir, "micro generated programs dir")


def fetch_selected_repos(*, repo_root: Path, repo_csv: str, host_python_bin: str, env: dict[str, str]) -> None:
    if not repo_csv:
        return
    args: list[str] = []
    for repo in csv_tokens(repo_csv):
        args.extend(["--repo", repo])
    run_python_script(
        host_python_bin,
        "runner/scripts/fetch_corpus_repos.py",
        "--repo-root",
        str(repo_root),
        *args,
        env=env,
    )


def build_scx_artifacts(
    *,
    repo_root: Path,
    promote_root: Path,
    package_csv: str,
    host_python_bin: str,
    env: dict[str, str],
    arch_signature: str,
) -> None:
    if not package_csv:
        return
    require_nonempty_dir(repo_root / "scx", "sealed scx source repo")
    args: list[str] = []
    for package in csv_tokens(package_csv):
        args.extend(["--package", package])
    run_python_script(
        host_python_bin,
        "runner/scripts/build_scx_artifacts.py",
        "--force",
        "--repo-root",
        str(repo_root),
        "--promote-root",
        str(promote_root),
        *args,
        env=env,
    )
    for package in csv_tokens(package_csv):
        require_file_contains(repo_root / "scx" / "target" / "release" / package, arch_signature, f"scx binary {package}")
        require_path(promote_root / "corpus" / "build" / "scx" / f"{package}_main.bpf.o", f"scx object {package}_main.bpf.o")


def build_native_repo_artifacts(
    *,
    repo_root: Path,
    promote_root: Path,
    native_repo_csv: str,
    host_python_bin: str,
    env: dict[str, str],
) -> None:
    if not native_repo_csv:
        return
    if not repo_root.is_dir():
        die(f"repo root missing for native repo build: {repo_root}")
    args: list[str] = []
    for repo in csv_tokens(native_repo_csv):
        args.extend(["--repo", repo])
    run_python_script(
        host_python_bin,
        "runner/scripts/build_corpus_native.py",
        "--jobs",
        str(max(os.cpu_count() or 1, 1)),
        "--repo-root",
        str(repo_root),
        "--build-root",
        str(promote_root / "corpus" / "build"),
        *args,
        env=env,
    )


def stage_x86_workload_tools(*, requested_csv: str, output_root: Path) -> tuple[str, str]:
    bundled_csv = ""
    if not requested_csv:
        return "", ""
    shutil.rmtree(output_root, ignore_errors=True)
    (output_root / "bin").mkdir(parents=True, exist_ok=True)
    for tool in csv_tokens(requested_csv):
        if tool not in SUPPORTED_BUNDLED_X86_TOOLS:
            continue
        tool_path = shutil.which(tool)
        if not tool_path:
            die(f"required x86 bundled workload tool is missing on the host: {tool}")
        target = output_root / "bin" / tool
        shutil.copy2(tool_path, target)
        target.chmod(0o755)
        require_path(target, f"x86 bundled workload tool {tool}")
        bundled_csv = csv_append_unique(bundled_csv, tool)
    return bundled_csv, str(output_root) if bundled_csv else ""
