from __future__ import annotations

import os
import shutil
from functools import partial
from pathlib import Path
from typing import Callable

from runner.libs import ROOT_DIR
from runner.libs.build_remote_bundle import compute_bundle_cache_key
from runner.libs.cli_support import fail, require_nonempty_dir as _require_nonempty_dir, require_path as _require_path
from runner.libs.runner_artifacts import (
    build_runner_binary,
    require_file_contains,
    run_command,
)
from runner.libs.state_file import write_state


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
    katran_runtime_root = promote_root / "corpus" / "build" / "katran"
    values = {
        "X86_RUNNER": str(promote_root / "runner" / "build" / "micro_exec"),
        "X86_DAEMON": str(promote_root / "daemon" / "target" / "release" / "bpfrejit-daemon"),
        "X86_TEST_UNITTEST_BUILD_DIR": str(test_artifacts_root / "unittest" / "build"),
        "X86_TEST_NEGATIVE_BUILD_DIR": str(test_artifacts_root / "negative" / "build"),
        "X86_UPSTREAM_SELFTEST_DIR": str(test_artifacts_root / "upstream-bpf-selftests"),
        "X86_NATIVE_BUILD_ROOT": str(promote_root / "corpus" / "build"),
        "X86_SCX_BINARY_ROOT": str(local_repo_root / "scx" / "target" / "release"),
        "X86_SCX_OBJECT_ROOT": str(promote_root / "corpus" / "build" / "scx"),
        "RUN_KATRAN_SERVER_BINARY": str(katran_runtime_root / "bin" / "katran_server_grpc"),
        "RUN_KATRAN_SERVER_LIB_DIR": str(katran_runtime_root / "lib"),
    }
    if portable_libbpf_root is not None and (portable_libbpf_root / "lib").is_dir():
        values["X86_PORTABLE_LIBBPF_ROOT"] = str(portable_libbpf_root)
    return values


def finalize_staged_bundle(
    *,
    manifest_path: Path,
    bundle_inputs_path: Path,
    local_state_path: Path,
    host_python_bin: str,
    env: dict[str, str],
    executor_name: str,
) -> None:
    target_name = env.get("RUN_TARGET_NAME", "").strip()
    if not target_name:
        die("manifest RUN_TARGET_NAME is missing for bundle cache")
    cache_key = compute_bundle_cache_key(manifest_path, bundle_inputs_path)
    cache_root = ROOT_DIR / ".cache" / target_name / "bundle-cache"
    cache_dir = cache_root / cache_key
    cached_bundle_tar = cache_dir / "bundle.tar.gz"
    run_command(
        [
            "make",
            "-C",
            str(ROOT_DIR),
            "__bundle-cache",
            f"PYTHON={host_python_bin}",
            f"BUNDLE_MANIFEST_PATH={manifest_path}",
            f"BUNDLE_INPUTS_PATH={bundle_inputs_path}",
            f"BUNDLE_CACHE_DIR={cache_dir}",
        ],
        env=env,
    )
    if not cached_bundle_tar.is_file():
        die(f"cached {executor_name} bundle tar is missing: {cached_bundle_tar}")
    write_state(
        local_state_path,
        {
            "RUN_BUNDLE_TAR": str(cached_bundle_tar),
        },
    )


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
    return build_runner_binary(
        build_dir=build_dir,
        env=env,
        expected_arch_signature="x86-64",
        llvmbpf_default="ON",
    )


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
        [
            "make",
            "-C",
            str(ROOT_DIR),
            "__upstream-selftests",
            f"PYTHON={host_python_bin}",
        ],
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
    run_command(
        [
            "make",
            "-C",
            str(ROOT_DIR),
            "__scx-build",
            f"PYTHON={host_python_bin}",
            f"JOBS={max(os.cpu_count() or 1, 1)}",
            f"SCX_REPO_ROOT={repo_root}",
            f"SCX_PROMOTE_ROOT={promote_root}",
            f"SCX_PACKAGES_CSV={package_csv}",
        ],
        env=env,
    )
    for package in csv_tokens(package_csv):
        require_file_contains(repo_root / "scx" / "target" / "release" / package, arch_signature, f"scx binary {package}")
        require_path(promote_root / "corpus" / "build" / "scx" / f"{package}_main.bpf.o", f"scx object {package}_main.bpf.o")


def build_native_repo_artifacts(
    *,
    repo_root: Path,
    promote_root: Path,
    build_cache_root: Path,
    native_repo_csv: str,
    host_python_bin: str,
    env: dict[str, str],
    vmlinux_btf: Path | None = None,
) -> None:
    if not native_repo_csv:
        return
    if not repo_root.is_dir():
        die(f"repo root missing for native repo build: {repo_root}")
    vmlinux_arg = f"NATIVE_VMLINUX_BTF={vmlinux_btf}" if vmlinux_btf is not None else ""
    run_command(
        [
            "make",
            "-C",
            str(ROOT_DIR),
            "__native-repo-build",
            f"PYTHON={host_python_bin}",
            f"JOBS={max(os.cpu_count() or 1, 1)}",
            f"NATIVE_REPO_ROOT={repo_root}",
            f"NATIVE_BUILD_ROOT={build_cache_root}",
            f"NATIVE_STAGE_ROOT={promote_root / 'corpus' / 'build'}",
            f"NATIVE_REPOS_CSV={native_repo_csv}",
            *([vmlinux_arg] if vmlinux_arg else []),
        ],
        env=env,
    )


def stage_x86_workload_tools(*, requested_csv: str, output_root: Path) -> tuple[str, str]:
    del requested_csv, output_root
    # x86 guests should consume workload tools from the guest package manager.
    # Bundling host binaries creates a second tool plane and, on AWS, can route
    # setpriv-executed workloads through non-traversable workspace paths.
    return "", ""
