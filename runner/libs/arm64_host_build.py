from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.arm64_sysroot import Arm64SysrootConfig, ensure_sysroot
from runner.libs.cli_support import fail, require_nonempty_dir as _require_nonempty_dir
from runner.libs.portable_runtime import copy_arm64_runtime_bundle

_die = partial(fail, "arm64-host-build")
_require_nonempty_dir = partial(_require_nonempty_dir, tag="arm64-host-build")


def _log(scope: str, message: str) -> None:
    print(f"[{scope}] {message}", file=sys.stderr)


def _env(name: str, default: str = "") -> str:
    return os.environ.get(name, default).strip()


def _require_command(name: str) -> str:
    resolved = shutil.which(name)
    if not resolved:
        _die(f"missing required command: {name}")
    return resolved


def _require_env(name: str) -> str:
    value = _env(name)
    if not value:
        _die(f"{name} is required")
    return value


def _run(
    command: list[str],
    *,
    env: dict[str, str] | None = None,
    cwd: Path | None = None,
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        cwd=cwd,
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )
    if completed.returncode != 0:
        output = completed.stderr.strip() or completed.stdout.strip() or "command failed"
        _die(f"{output}: {' '.join(command)}")
    return completed


def _require_arch_signature(path: Path, needle: str, description: str) -> None:
    completed = _run(["file", str(path)])
    if needle not in completed.stdout:
        _die(f"{description} does not match expected file signature {needle}: {path}")


def _write_executable(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")
    path.chmod(0o755)


def _resolve_llvm_tool(base: str, *, preferred_suffix: str = "", preferred_name: str = "") -> str:
    if preferred_name:
        return _require_command(preferred_name)
    candidates = []
    if preferred_suffix:
        candidates.extend((f"{base}-{preferred_suffix}", f"{base}{preferred_suffix}"))
    candidates.append(base)
    for candidate in candidates:
        resolved = shutil.which(candidate)
        if resolved:
            return resolved
    _die(f"missing LLVM tool: {base}")


def _git_path_is_clean(repo_root: Path, pathspec: str = "") -> bool:
    diff = ["git", "-C", str(repo_root), "diff", "--quiet"]
    cached = ["git", "-C", str(repo_root), "diff", "--cached", "--quiet"]
    if pathspec:
        diff.extend(["--", pathspec])
        cached.extend(["--", pathspec])
    return (
        subprocess.run(diff, check=False).returncode == 0
        and subprocess.run(cached, check=False).returncode == 0
    )


def _snapshot_git_subtree(repo_root: Path, src_rel: str, dest: Path) -> None:
    if subprocess.run(["git", "-C", str(repo_root), "rev-parse", "--verify", "HEAD"], check=False).returncode != 0:
        _die(f"expected git checkout for promoted snapshot: {repo_root}")
    if src_rel:
        if not _git_path_is_clean(repo_root, src_rel):
            _die(f"git subtree has local modifications and cannot be promoted: {repo_root / src_rel}")
    else:
        if not _git_path_is_clean(repo_root):
            _die(f"git checkout has local modifications and cannot be promoted: {repo_root}")
    shutil.rmtree(dest, ignore_errors=True)
    dest.mkdir(parents=True, exist_ok=True)
    archive = subprocess.Popen(
        ["git", "-C", str(repo_root), "archive", "--format=tar", "HEAD", *(["--", src_rel] if src_rel else [])],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    extract = subprocess.run(
        ["tar", "-xf", "-", "-C", str(dest), *(["--strip-components", str(len(Path(src_rel).parts))] if src_rel else [])],
        stdin=archive.stdout,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )
    stderr_bytes = archive.stderr.read() if archive.stderr is not None else b""
    archive_code = archive.wait()
    if archive.stdout is not None:
        archive.stdout.close()
    if archive.stderr is not None:
        archive.stderr.close()
    if archive_code != 0:
        _die(stderr_bytes.decode("utf-8", errors="replace").strip() or f"git archive failed for {repo_root}")
    if extract.returncode != 0:
        _die(extract.stderr.decode("utf-8", errors="replace").strip() or f"failed to extract snapshot from {repo_root}")
    _require_nonempty_dir(dest, "promoted snapshot")


def _ensure_arm64_sysroot_from_env() -> Path:
    host_cache_root = ROOT_DIR / ".cache/arm64-host"
    config = Arm64SysrootConfig(
        sysroot_root=Path(_env("ARM64_SYSROOT_ROOT", str(host_cache_root / "sysroot"))),
        sysroot_lock_file=Path(_env("ARM64_SYSROOT_LOCK_FILE", str(host_cache_root / "sysroot.lock"))),
        remote_host=_env("ARM64_SYSROOT_REMOTE_HOST"),
        remote_user=_env("ARM64_SYSROOT_REMOTE_USER"),
        ssh_key_path=Path(_env("ARM64_SYSROOT_SSH_KEY_PATH")),
        ssh_port=int(_env("ARM64_SYSROOT_SSH_PORT", "22") or "22"),
    )
    return ensure_sysroot(config)


def _prepare_cc_wrapper(
    *,
    wrapper_path: Path,
    compiler: str,
    sysroot_root: Path,
    extra_include_dirs: list[Path] | None = None,
) -> None:
    usr_lib = sysroot_root / "usr/lib"
    usr_lib64 = sysroot_root / "usr/lib64"
    lib = sysroot_root / "lib"
    lib64 = sysroot_root / "lib64"
    include_flags = " ".join(f'-isystem "{path}"' for path in (extra_include_dirs or []))
    _write_executable(
        wrapper_path,
        "\n".join(
            (
                "#!/usr/bin/env bash",
                f'exec "{compiler}" --sysroot="{sysroot_root}" {include_flags} '
                f'-Wl,-rpath-link,"{usr_lib}" '
                f'-Wl,-rpath-link,"{usr_lib64}" '
                f'-Wl,-rpath-link,"{lib}" '
                f'-Wl,-rpath-link,"{lib64}" "$@"',
                "",
            )
        ),
    )


def _copy_optional_libs(lib_dir: Path, output_lib_dir: Path) -> None:
    output_lib_dir.mkdir(parents=True, exist_ok=True)
    for pattern in ("libelf.so*", "libz.so*", "libzstd.so*"):
        for path in lib_dir.glob(pattern):
            shutil.copy2(path, output_lib_dir / path.name)


def build_daemon_from_env() -> None:
    host_cache_root = ROOT_DIR / ".cache/arm64-host"
    rust_target = _env("ARM64_HOST_DAEMON_RUST_TARGET", "aarch64-unknown-linux-gnu") or "aarch64-unknown-linux-gnu"
    cross_linker = _env("ARM64_HOST_CARGO_LINKER", f"{_env('CROSS_COMPILE_ARM64', 'aarch64-linux-gnu-')}gcc")
    target_dir = Path(_env("ARM64_HOST_DAEMON_TARGET_DIR", str(host_cache_root / "daemon-host-cross/target")))
    output_dir = Path(_env("ARM64_HOST_DAEMON_OUTPUT_DIR", str(host_cache_root / "daemon-host-cross/output")))
    output_binary = Path(_env("ARM64_HOST_DAEMON_BINARY", str(output_dir / "bpfrejit-daemon")))
    cargo_home = Path(_env("ARM64_HOST_DAEMON_CARGO_HOME", str(host_cache_root / "cargo-home-host-daemon")))
    sysroot_root = _ensure_arm64_sysroot_from_env()
    linker_wrapper = output_dir / "toolchain/bin/aarch64-linux-gnu-gcc-sysroot"

    _require_command("cargo")
    _require_command("file")
    _require_command(cross_linker)

    target_dir.mkdir(parents=True, exist_ok=True)
    output_dir.mkdir(parents=True, exist_ok=True)
    cargo_home.mkdir(parents=True, exist_ok=True)
    _prepare_cc_wrapper(wrapper_path=linker_wrapper, compiler=cross_linker, sysroot_root=sysroot_root)
    env = os.environ.copy()
    env.update(
        {
            "CARGO_HOME": str(cargo_home),
            "CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER": str(linker_wrapper),
            "CARGO_TARGET_DIR": str(target_dir),
        }
    )
    _run(
        [
            "cargo",
            "build",
            "--release",
            "--target",
            rust_target,
            "--manifest-path",
            str(ROOT_DIR / "daemon/Cargo.toml"),
        ],
        env=env,
    )
    shutil.copy2(target_dir / rust_target / "release" / "bpfrejit-daemon", output_binary)
    _require_arch_signature(output_binary, "ARM aarch64", "host daemon cross-build")


def build_runner_from_env() -> None:
    host_cache_root = ROOT_DIR / ".cache/arm64-host"
    build_dir = Path(_env("ARM64_HOST_RUNNER_BUILD_DIR", str(host_cache_root / "runner-host-cross/build")))
    output_dir = Path(_env("ARM64_HOST_RUNNER_OUTPUT_DIR", str(host_cache_root / "runner-host-cross/output")))
    output_binary = Path(_env("ARM64_HOST_RUNNER_BINARY", str(output_dir / "micro_exec")))
    cross_cc = _env("ARM64_HOST_RUNNER_CC", f"{_env('CROSS_COMPILE_ARM64', 'aarch64-linux-gnu-')}gcc")
    cross_cxx = _env("ARM64_HOST_RUNNER_CXX", f"{_env('CROSS_COMPILE_ARM64', 'aarch64-linux-gnu-')}g++")
    cross_ar = _env("ARM64_HOST_RUNNER_AR", f"{_env('CROSS_COMPILE_ARM64', 'aarch64-linux-gnu-')}ar")
    pkg_config = _env("ARM64_HOST_RUNNER_PKG_CONFIG", "pkg-config") or "pkg-config"
    llvmbpf = _env("MICRO_EXEC_ENABLE_LLVMBPF", "OFF") or "OFF"
    sysroot_root = _ensure_arm64_sysroot_from_env()
    toolchain_dir = output_dir / "toolchain/bin"
    cc_wrapper = toolchain_dir / "aarch64-linux-gnu-gcc-sysroot"
    cxx_wrapper = toolchain_dir / "aarch64-linux-gnu-g++-sysroot"
    pkg_wrapper = toolchain_dir / "pkg-config"

    _require_command("cmake")
    _require_command("make")
    _require_command("file")
    _require_command(cross_cc)
    _require_command(cross_cxx)
    _require_command(cross_ar)
    _require_command(pkg_config)
    if llvmbpf == "ON":
        _die("host ARM64 runner cross-build does not support MICRO_EXEC_ENABLE_LLVMBPF=ON yet")

    build_dir.mkdir(parents=True, exist_ok=True)
    output_dir.mkdir(parents=True, exist_ok=True)
    toolchain_dir.mkdir(parents=True, exist_ok=True)
    _prepare_cc_wrapper(wrapper_path=cc_wrapper, compiler=cross_cc, sysroot_root=sysroot_root)
    _prepare_cc_wrapper(wrapper_path=cxx_wrapper, compiler=cross_cxx, sysroot_root=sysroot_root)
    _write_executable(
        pkg_wrapper,
        "\n".join(
            (
                "#!/usr/bin/env bash",
                f'export PKG_CONFIG_SYSROOT_DIR="{sysroot_root}"',
                f'export PKG_CONFIG_LIBDIR="{sysroot_root}/usr/lib64/pkgconfig:{sysroot_root}/usr/lib/pkgconfig"',
                f'exec "{pkg_config}" "$@"',
                "",
            )
        ),
    )

    env = os.environ.copy()
    env.update(
        {
            "CC": str(cc_wrapper),
            "CXX": str(cxx_wrapper),
            "AR": cross_ar,
            "PKG_CONFIG": str(pkg_wrapper),
            "MICRO_EXEC_ENABLE_LLVMBPF": "OFF",
        }
    )
    _run(
        [
            "make",
            "-C",
            str(ROOT_DIR / "runner"),
            f"BUILD_DIR={build_dir}",
            "JOBS=1",
            "micro_exec",
        ],
        env=env,
    )
    shutil.copy2(build_dir / "micro_exec", output_binary)
    _require_arch_signature(output_binary, "ARM aarch64", "host runner cross-build")


def build_repo_tests_from_env() -> None:
    host_cache_root = ROOT_DIR / ".cache/arm64-host"
    jobs = _env("ARM64_CROSSBUILD_JOBS", "4") or "4"
    test_mode = (_env("ARM64_TEST_MODE", "test") or "test").lower()
    artifacts_root = Path(_env("ARM64_TEST_ARTIFACTS_ROOT", str(host_cache_root / "test-artifacts")))
    unittest_build_dir = Path(_env("ARM64_TEST_UNITTEST_BUILD_DIR", str(artifacts_root / "unittest/build-arm64")))
    negative_build_dir = Path(_env("ARM64_TEST_NEGATIVE_BUILD_DIR", str(artifacts_root / "negative/build-arm64")))
    daemon_output_dir = Path(_env("ARM64_TEST_DAEMON_OUTPUT_DIR", str(artifacts_root / "daemon")))
    upstream_output_dir = Path(_env("ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR", str(artifacts_root / "upstream-bpf-selftests")))
    llvm_suffix = _env("ARM64_UPSTREAM_SELFTEST_LLVM_SUFFIX", "")
    prebuilt_daemon = Path(_env("ARM64_TEST_PREBUILT_DAEMON_BINARY"))
    vmlinux_btf = _env("VMLINUX_BTF")
    host_python = _require_env("ARM64_HOST_PYTHON_BIN")
    sysroot_root = _ensure_arm64_sysroot_from_env()
    usr_lib = sysroot_root / "usr/lib"
    usr_lib64 = sysroot_root / "usr/lib64"
    lib = sysroot_root / "lib"
    lib64 = sysroot_root / "lib64"
    pkgconfig_libdir = ":".join(
        (
            str(usr_lib / "pkgconfig"),
            str(usr_lib64 / "pkgconfig"),
            str(lib / "pkgconfig"),
            str(lib64 / "pkgconfig"),
            str(sysroot_root / "usr/share/pkgconfig"),
        )
    )
    cross_cc = _env("ARM64_HOST_TEST_CC", f"{_env('CROSS_COMPILE_ARM64', 'aarch64-linux-gnu-')}gcc")
    toolchain_dir = artifacts_root / "toolchain/bin"
    cc_wrapper = toolchain_dir / "aarch64-linux-gnu-gcc-sysroot"
    preferred_clang = _env("ARM64_HOST_TEST_BPF_CLANG")
    clang_bin = _resolve_llvm_tool("clang", preferred_name=preferred_clang)

    need_unittest = test_mode in {"selftest", "test"}
    need_negative = test_mode in {"selftest", "negative", "test"}
    need_daemon = test_mode in {"selftest", "test"}
    need_upstream = test_mode in {"selftest", "test"}
    if test_mode not in {"selftest", "negative", "test"}:
        _die(f"unsupported ARM64_TEST_MODE: {test_mode}")

    _require_command("make")
    _require_command("file")
    _require_command(host_python)
    _require_command(cross_cc)
    if need_unittest:
        if not vmlinux_btf:
            _die("VMLINUX_BTF is required for ARM64 unittest host build")
        if not Path(vmlinux_btf).is_file():
            _die(f"missing ARM64 kernel BTF image: {vmlinux_btf}")
        vmlinux_btf = str(Path(vmlinux_btf).resolve())

    shutil.rmtree(unittest_build_dir, ignore_errors=True)
    shutil.rmtree(negative_build_dir, ignore_errors=True)
    shutil.rmtree(daemon_output_dir, ignore_errors=True)
    shutil.rmtree(upstream_output_dir, ignore_errors=True)
    (unittest_build_dir / "lib").mkdir(parents=True, exist_ok=True)
    negative_build_dir.mkdir(parents=True, exist_ok=True)
    daemon_output_dir.mkdir(parents=True, exist_ok=True)
    _prepare_cc_wrapper(
        wrapper_path=cc_wrapper,
        compiler=cross_cc,
        sysroot_root=sysroot_root,
        extra_include_dirs=[sysroot_root / "usr/include"],
    )

    host_ext_libs = (
        f"-L{usr_lib} -L{usr_lib64} -L{lib} -L{lib64} "
        f"-Wl,-rpath-link,{usr_lib} -Wl,-rpath-link,{usr_lib64} "
        f"-Wl,-rpath-link,{lib} -Wl,-rpath-link,{lib64} "
        "-lelf -lz -lzstd"
    )

    if need_unittest:
        _log("arm64-repo-tests-host", "Building ARM64 repo-owned unittest binaries on host")
        common = [
            "make",
            "-C",
            str(ROOT_DIR / "tests/unittest"),
            f"BUILD_DIR={unittest_build_dir}",
            f"CC={cc_wrapper}",
            f"CLANG={clang_bin}",
            f"VMLINUX_BTF={vmlinux_btf}",
            f"HOST_EXT_LIBS={host_ext_libs}",
        ]
        _run(common + ["clean"])
        _run(common + [f"-j{jobs}", "all"])
        for lib_dir in (usr_lib, usr_lib64, lib64, lib):
            _copy_optional_libs(lib_dir, unittest_build_dir / "lib")

    if need_negative:
        _log("arm64-repo-tests-host", "Building ARM64 repo-owned negative binaries on host")
        common = [
            "make",
            "-C",
            str(ROOT_DIR / "tests/negative"),
            f"BUILD_DIR={negative_build_dir}",
            f"CC={cc_wrapper}",
        ]
        _run(common + ["clean"])
        _run(common + [f"-j{jobs}", "all"])

    if need_daemon:
        if not prebuilt_daemon or not prebuilt_daemon.is_file():
            _die(f"missing prebuilt ARM64 daemon binary: {prebuilt_daemon}")
        shutil.copy2(prebuilt_daemon.resolve(), daemon_output_dir / "bpfrejit-daemon")

    if need_upstream:
        _log("arm64-repo-tests-host", "Building ARM64 upstream selftests on host")
        env = os.environ.copy()
        env.update(
            {
                "UPSTREAM_SELFTEST_SOURCE_DIR": str(ROOT_DIR / "vendor/linux-framework/tools/testing/selftests/bpf"),
                "UPSTREAM_SELFTEST_OUTPUT_DIR": str(upstream_output_dir),
                "UPSTREAM_SELFTEST_HOST_PYTHON_BIN": host_python,
                "UPSTREAM_SELFTEST_ARCH": "arm64",
                "UPSTREAM_SELFTEST_CROSS_COMPILE": _env("CROSS_COMPILE_ARM64", "aarch64-linux-gnu-"),
                "UPSTREAM_SELFTEST_SYSROOT_ROOT": str(sysroot_root),
                "UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR": pkgconfig_libdir,
                "UPSTREAM_SELFTEST_LLVM_SUFFIX": llvm_suffix,
                "VMLINUX_BTF": vmlinux_btf,
                "PYTHONPATH": str(ROOT_DIR) + (f":{os.environ['PYTHONPATH']}" if os.environ.get("PYTHONPATH") else ""),
            }
        )
        _run([host_python, "-m", "runner.libs.build_upstream_selftests"], env=env)

    if need_unittest:
        _require_arch_signature(unittest_build_dir / "rejit_kinsn", "ARM aarch64", "host unittest cross-build")
    if need_negative:
        _require_arch_signature(negative_build_dir / "adversarial_rejit", "ARM aarch64", "host negative cross-build")
    if need_daemon:
        _require_arch_signature(daemon_output_dir / "bpfrejit-daemon", "ARM aarch64", "prebuilt daemon copy")
    if need_upstream:
        _require_arch_signature(upstream_output_dir / "test_verifier", "ARM aarch64", "host upstream test_verifier build")
        _require_arch_signature(upstream_output_dir / "test_progs", "ARM aarch64", "host upstream test_progs build")


def build_scx_from_env() -> None:
    host_cache_root = ROOT_DIR / ".cache/arm64-host"
    source_repo_root = Path(_env("ARM64_SCX_SOURCE_REPO_ROOT", str(ROOT_DIR / "runner/repos")))
    build_root = Path(_env("ARM64_SCX_BUILD_ROOT", str(host_cache_root / "scx-host-build")))
    promote_root = Path(_env("ARM64_SCX_PROMOTE_ROOT", str(host_cache_root / "binaries")))
    cargo_home = Path(_env("ARM64_SCX_CARGO_HOME", str(host_cache_root / "cargo-home-host-scx")))
    packages_raw = _env("ARM64_SCX_PACKAGES")
    target_triple = _env("ARM64_SCX_TARGET_TRIPLE", "aarch64-unknown-linux-gnu") or "aarch64-unknown-linux-gnu"
    linker = _env("ARM64_NATIVE_CARGO_LINKER", f"{_env('CROSS_COMPILE_ARM64', 'aarch64-linux-gnu-')}gcc")
    preferred_suffix = _env("ARM64_CROSSBUILD_LLVM_SUFFIX", "20")
    readelf_bin = _env("ARM64_CROSSBUILD_READELF", "aarch64-linux-gnu-readelf")
    rustfmt_bin = _env("ARM64_CROSSBUILD_RUSTFMT", "rustfmt")
    host_python = _require_env("ARM64_HOST_PYTHON_BIN")
    sysroot_root = _ensure_arm64_sysroot_from_env()
    usr_lib64 = sysroot_root / "usr/lib64"
    lib64 = sysroot_root / "lib64"
    pkgconfig_dir = usr_lib64 / "pkgconfig"
    scx_build_repo_root = build_root / "runner/repos"
    scx_build_repo_dir = scx_build_repo_root / "scx"
    toolchain_dir = build_root / "toolchain/bin"
    linker_wrapper = toolchain_dir / "aarch64-linux-gnu-gcc-sysroot"
    jobs = _env("ARM64_CROSSBUILD_JOBS", "4") or "4"

    if not packages_raw:
        _die("ARM64_SCX_PACKAGES must not be empty")
    packages = [package for package in packages_raw.split(",") if package]
    if not packages:
        _die("ARM64_SCX_PACKAGES did not contain any valid package names")

    _require_command(host_python)
    _require_command("cargo")
    _require_command("file")
    _require_command("readelf")
    _require_command("git")
    _require_command("tar")
    _require_command(linker)
    _require_command(readelf_bin)
    _require_command(rustfmt_bin)

    source_checkout = source_repo_root / "scx"
    if not source_checkout.is_dir():
        _die(f"source repo {source_checkout} is missing; fetch it locally first")
    if subprocess.run(["git", "-C", str(source_checkout), "rev-parse", "--is-inside-work-tree"], check=False).returncode != 0:
        _die(f"source repo {source_checkout} is not a git checkout")
    if not _git_path_is_clean(source_checkout):
        _die(f"source repo {source_checkout} has local modifications and cannot be sealed")
    archive_commit = _run(["git", "-C", str(source_checkout), "rev-parse", "HEAD"]).stdout.strip()
    shutil.rmtree(scx_build_repo_dir, ignore_errors=True)
    scx_build_repo_dir.mkdir(parents=True, exist_ok=True)
    _log("arm64-scx-host", f"Staging tracked scx checkout at {archive_commit} into {scx_build_repo_dir}")
    _snapshot_git_subtree(source_checkout, "", scx_build_repo_dir)

    clang_bin = _resolve_llvm_tool("clang", preferred_suffix=preferred_suffix)
    clangxx_bin = _resolve_llvm_tool("clang++", preferred_suffix=preferred_suffix)
    llc_bin = _resolve_llvm_tool("llc", preferred_suffix=preferred_suffix)
    llvm_config_bin = _resolve_llvm_tool("llvm-config", preferred_suffix=preferred_suffix)
    llvm_objcopy_bin = _resolve_llvm_tool("llvm-objcopy", preferred_suffix=preferred_suffix)
    llvm_strip_bin = _resolve_llvm_tool("llvm-strip", preferred_suffix=preferred_suffix)

    shutil.rmtree(toolchain_dir, ignore_errors=True)
    toolchain_dir.mkdir(parents=True, exist_ok=True)
    _prepare_cc_wrapper(wrapper_path=linker_wrapper, compiler=linker, sysroot_root=sysroot_root)

    promote_root.mkdir(parents=True, exist_ok=True)
    cargo_home.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    env.update(
        {
            "PATH": f"{toolchain_dir}:{env.get('PATH', '')}",
            "CARGO_HOME": str(cargo_home),
            "CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER": str(linker_wrapper),
            "RUSTFMT": rustfmt_bin,
            "RUSTFLAGS": f"-L native={usr_lib64} -L native={lib64}" + (f" {env['RUSTFLAGS']}" if env.get("RUSTFLAGS") else ""),
            "PKG_CONFIG_SYSROOT_DIR": str(sysroot_root),
            "PKG_CONFIG_LIBDIR": f"{pkgconfig_dir}:{sysroot_root / 'usr/share/pkgconfig'}",
            "C_INCLUDE_PATH": str(sysroot_root / "usr/include") + (f":{env['C_INCLUDE_PATH']}" if env.get("C_INCLUDE_PATH") else ""),
            "CPLUS_INCLUDE_PATH": str(sysroot_root / "usr/include") + (f":{env['CPLUS_INCLUDE_PATH']}" if env.get("CPLUS_INCLUDE_PATH") else ""),
            "SCX_TARGET_TRIPLE": target_triple,
            "SCX_BUILD_JOBS": jobs,
            "BPF_CLANG": clang_bin,
            "CLANG": clang_bin,
            "LLC": llc_bin,
            "LLVM_CONFIG": llvm_config_bin,
            "LLVM_OBJCOPY": llvm_objcopy_bin,
            "LLVM_STRIP": llvm_strip_bin,
            "CC": clang_bin,
            "CXX": clangxx_bin,
        }
    )
    command = [
        host_python,
        str(ROOT_DIR / "runner/scripts/build_scx_artifacts.py"),
        "--force",
        "--jobs",
        jobs,
        "--target-triple",
        target_triple,
        "--repo-root",
        str(scx_build_repo_root),
        "--promote-root",
        str(promote_root),
    ]
    for package in packages:
        command.extend(["--package", package])
    _log("arm64-scx-host", f"Building ARM64 scx artifacts on host for {packages_raw}")
    _run(command, env=env)

    release_dir = scx_build_repo_dir / "target" / target_triple / "release"
    destination_release_dir = promote_root / "runner/repos/scx/target/release"
    destination_release_dir.mkdir(parents=True, exist_ok=True)
    for package in packages:
        built_binary = release_dir / package
        if not built_binary.is_file():
            _die(f"expected scx binary missing after build: {built_binary}")
        destination = destination_release_dir / package
        shutil.copy2(built_binary, destination)
        copy_arm64_runtime_bundle(
            binary=destination,
            lib_output_dir=promote_root / "lib",
            sysroot_root=sysroot_root,
            readelf_bin=readelf_bin,
        )


def _prepare_source_checkout(repo_url: str, repo_ref: str, repo_name: str, dest_dir: Path, cache_root: Path) -> None:
    cache_dir = cache_root / ".workload-tool-sources" / repo_name
    shutil.rmtree(dest_dir, ignore_errors=True)
    cache_dir.parent.mkdir(parents=True, exist_ok=True)
    if (cache_dir / ".git").is_dir() and not _git_path_is_clean(cache_dir):
        shutil.rmtree(cache_dir, ignore_errors=True)
    if not (cache_dir / ".git").is_dir():
        _run(["git", "clone", "--no-checkout", repo_url, str(cache_dir)])
    current_head = _run(["git", "-C", str(cache_dir), "rev-parse", "HEAD"]).stdout.strip() if (cache_dir / ".git").is_dir() else ""
    if current_head != repo_ref:
        _run(["git", "-C", str(cache_dir), "fetch", "--depth", "1", "origin", repo_ref])
        _run(["git", "-C", str(cache_dir), "checkout", "--detach", "FETCH_HEAD"])
    _snapshot_git_subtree(cache_dir, "", dest_dir)


def _copy_sibling_lib_wrapper(wrapper: Path, real_name: str) -> None:
    _write_executable(
        wrapper,
        "\n".join(
            (
                "#!/usr/bin/env bash",
                "set -euo pipefail",
                'SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"',
                'LIB_DIR="$(cd "$SCRIPT_DIR/../lib" && pwd)"',
                'export LD_LIBRARY_PATH="$LIB_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"',
                f'exec "$SCRIPT_DIR/{real_name}" "$@"',
                "",
            )
        ),
    )


def _stage_arm64_portable_binary(
    *,
    tool_name: str,
    source_binary: Path,
    output_bin_dir: Path,
    output_lib_dir: Path,
    sysroot_root: Path,
    readelf_bin: str,
    strip_bin: str,
) -> None:
    if not source_binary.is_file():
        _die(f"missing built ARM64 workload tool binary: {source_binary}")
    output_bin_dir.mkdir(parents=True, exist_ok=True)
    output_lib_dir.mkdir(parents=True, exist_ok=True)
    real_binary = output_bin_dir / f"{tool_name}.real"
    shutil.copy2(source_binary, real_binary)
    subprocess.run([strip_bin, str(real_binary)], check=False, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    _require_arch_signature(real_binary, "ARM aarch64", "built workload tool")
    copy_arm64_runtime_bundle(
        binary=real_binary,
        lib_output_dir=output_lib_dir,
        sysroot_root=sysroot_root,
        readelf_bin=readelf_bin,
    )
    _copy_sibling_lib_wrapper(output_bin_dir / tool_name, f"{tool_name}.real")


def build_workload_tools_from_env() -> None:
    host_cache_root = ROOT_DIR / ".cache/arm64-host"
    source_cache_root = Path(_env("ARM64_WORKLOAD_TOOLS_SOURCE_ROOT", str(host_cache_root / "workload-tool-sources")))
    build_root = Path(_env("ARM64_WORKLOAD_TOOLS_BUILD_ROOT", str(host_cache_root / "workload-tools-host")))
    output_root = Path(_env("ARM64_WORKLOAD_TOOLS_OUTPUT_ROOT", str(host_cache_root / "workload-tools-output")))
    tools_raw = _env("ARM64_WORKLOAD_TOOLS_LIST")
    sysroot_root = _ensure_arm64_sysroot_from_env()
    toolchain_prefix = _env("CROSS_COMPILE_ARM64", "aarch64-linux-gnu-")
    host_cc = _env("ARM64_WORKLOAD_TOOLS_HOST_CC", "gcc")
    strip_bin = _env("ARM64_WORKLOAD_TOOLS_STRIP", f"{toolchain_prefix}strip")
    readelf_bin = _env("ARM64_WORKLOAD_TOOLS_READELF", f"{toolchain_prefix}readelf")
    host_python = _require_env("ARM64_HOST_PYTHON_BIN")

    workload_root = build_root / "workload-tools"
    workload_src_root = workload_root / "src"
    toolchain_dir = workload_root / "toolchain/bin"
    cross_prefix = toolchain_dir / toolchain_prefix
    usr_lib64 = sysroot_root / "usr/lib64"
    pkgconfig_libdir = f"{usr_lib64 / 'pkgconfig'}:{sysroot_root / 'usr/share/pkgconfig'}"
    output_tool_root = output_root / "workload-tools"
    output_bin_dir = output_tool_root / "bin"
    output_lib_dir = output_tool_root / "lib"
    rt_tests_repo_url = "https://git.kernel.org/pub/scm/utils/rt-tests/rt-tests.git"
    rt_tests_ref = _env("ARM64_WORKLOAD_TOOL_RT_TESTS_REF", "f9c82184ce88d8de3ffe588279b0bc41d3887998")
    sysbench_repo_url = "https://github.com/akopytov/sysbench.git"
    sysbench_ref = _env("ARM64_WORKLOAD_TOOL_SYSBENCH_REF", "3ceba0b1e115f8c50d1d045a4574d8ed643bd497")
    wrk_repo_url = "https://github.com/wg/wrk.git"
    wrk_ref = _env("ARM64_WORKLOAD_TOOL_WRK_REF", "a211dd5a7050b1f9e8a9870b95513060e72ac4a0")
    jobs = str(os.cpu_count() or 1)

    if not tools_raw:
        _die("ARM64_WORKLOAD_TOOLS_LIST must not be empty")
    tools = [tool for tool in tools_raw.split(",") if tool]
    if not tools:
        _die("ARM64_WORKLOAD_TOOLS_LIST did not contain any valid tool names")

    _require_command("git")
    _require_command("unzip")
    _require_command(host_python)
    _require_command(host_cc)
    _require_command(f"{toolchain_prefix}ar")
    _require_command(f"{toolchain_prefix}ranlib")
    _require_command(f"{toolchain_prefix}gcc")
    _require_command(f"{toolchain_prefix}g++")
    _require_command(readelf_bin)
    _require_command(strip_bin)

    shutil.rmtree(toolchain_dir, ignore_errors=True)
    toolchain_dir.mkdir(parents=True, exist_ok=True)
    for wrapper in ("gcc", "g++"):
        target_bin = _require_command(f"{toolchain_prefix}{wrapper}")
        wrapper_path = toolchain_dir / wrapper
        _prepare_cc_wrapper(wrapper_path=wrapper_path, compiler=target_bin, sysroot_root=sysroot_root)
        _prepare_cc_wrapper(
            wrapper_path=toolchain_dir / f"{toolchain_prefix}{wrapper}",
            compiler=target_bin,
            sysroot_root=sysroot_root,
        )
    for tool in ("ar", "ranlib", "strip"):
        target = _require_command(f"{toolchain_prefix}{tool}")
        link = toolchain_dir / f"{toolchain_prefix}{tool}"
        if link.exists() or link.is_symlink():
            link.unlink()
        link.symlink_to(target)

    shutil.rmtree(workload_src_root, ignore_errors=True)
    shutil.rmtree(output_tool_root, ignore_errors=True)
    workload_src_root.mkdir(parents=True, exist_ok=True)
    output_bin_dir.mkdir(parents=True, exist_ok=True)
    output_lib_dir.mkdir(parents=True, exist_ok=True)

    def build_hackbench() -> None:
        src_root = workload_src_root / "rt-tests"
        _log("arm64-workload-tools-host", "Building ARM64 hackbench on host")
        _prepare_source_checkout(rt_tests_repo_url, rt_tests_ref, "rt-tests", src_root, source_cache_root)
        env = os.environ.copy()
        env["CROSS_COMPILE"] = str(cross_prefix)
        _run(["make", "-C", str(src_root), f"-j{jobs}", "hackbench"], env=env)
        _stage_arm64_portable_binary(
            tool_name="hackbench",
            source_binary=src_root / "hackbench",
            output_bin_dir=output_bin_dir,
            output_lib_dir=output_lib_dir,
            sysroot_root=sysroot_root,
            readelf_bin=readelf_bin,
            strip_bin=strip_bin,
        )

    def build_sysbench() -> None:
        src_root = workload_src_root / "sysbench"
        _log("arm64-workload-tools-host", "Building ARM64 sysbench on host")
        _prepare_source_checkout(sysbench_repo_url, sysbench_ref, "sysbench", src_root, source_cache_root)
        env = os.environ.copy()
        env.update(
            {
                "CC": str(toolchain_dir / "gcc"),
                "CXX": str(toolchain_dir / "g++"),
                "AR": str(cross_prefix) + "ar",
                "RANLIB": str(cross_prefix) + "ranlib",
                "STRIP": str(cross_prefix) + "strip",
                "PKG_CONFIG_SYSROOT_DIR": str(sysroot_root),
                "PKG_CONFIG_LIBDIR": pkgconfig_libdir,
            }
        )
        _run(["./autogen.sh"], cwd=src_root, env=env)
        _run(
            [
                "./configure",
                "--host=aarch64-linux-gnu",
                "--without-mysql",
                "--without-pgsql",
                f"--prefix={src_root / 'install'}",
            ],
            cwd=src_root,
            env=env,
        )
        make_env = env | {
            "HOST_CC": host_cc,
            "CROSS": str(cross_prefix),
            "TARGET_SYS": "Linux",
            "CK_CONFIGURE_FLAGS": "--platform=aarch64",
        }
        _run(["make", f"-j{jobs}"], cwd=src_root, env=make_env)
        _run(["make", "install"], cwd=src_root, env=make_env)
        _stage_arm64_portable_binary(
            tool_name="sysbench",
            source_binary=src_root / "install/bin/sysbench",
            output_bin_dir=output_bin_dir,
            output_lib_dir=output_lib_dir,
            sysroot_root=sysroot_root,
            readelf_bin=readelf_bin,
            strip_bin=strip_bin,
        )

    def build_wrk() -> None:
        src_root = workload_src_root / "wrk"
        _log("arm64-workload-tools-host", "Building ARM64 wrk on host")
        _prepare_source_checkout(wrk_repo_url, wrk_ref, "wrk", src_root, source_cache_root)
        _run(["unzip", "-q", *(sorted(str(path) for path in (src_root / "deps").glob("LuaJIT*.zip"))), "-d", str(src_root / "obj")])
        luajit_candidates = sorted((src_root / "obj").glob("LuaJIT-*"))
        if not luajit_candidates:
            _die(f"missing extracted LuaJIT source under {src_root / 'obj'}")
        luajit_dir = luajit_candidates[0]
        env = os.environ.copy()
        env.update(
            {
                "HOST_CC": host_cc,
                "CROSS": str(cross_prefix),
                "TARGET_SYS": "Linux",
                "TARGET_FLAGS": f"--sysroot={sysroot_root}",
                "PREFIX": str(src_root / "obj"),
                "BUILDMODE": "static",
            }
        )
        _run(["make", "-C", str(luajit_dir), "install"], env=env)
        bin_dir = src_root / "obj/bin"
        include_dir = src_root / "obj/include"
        bin_dir.mkdir(parents=True, exist_ok=True)
        include_dir.mkdir(parents=True, exist_ok=True)
        luajit_target = bin_dir / "luajit"
        if luajit_target.exists() or luajit_target.is_symlink():
            luajit_target.unlink()
        luajit_target.symlink_to("luajit-2.1.0-beta3")
        for header in (include_dir / "luajit-2.1").glob("*"):
            link = include_dir / header.name
            if link.exists() or link.is_symlink():
                link.unlink()
            link.symlink_to(header)
        openssl_root = src_root / "obj/openssl-root"
        openssl_root.mkdir(parents=True, exist_ok=True)
        include_link = openssl_root / "include"
        lib_link = openssl_root / "lib"
        if include_link.exists() or include_link.is_symlink():
            include_link.unlink()
        if lib_link.exists() or lib_link.is_symlink():
            lib_link.unlink()
        include_link.symlink_to(sysroot_root / "usr/include")
        lib_link.symlink_to(sysroot_root / "usr/lib64")
        wrk_env = os.environ.copy()
        wrk_env.update(
            {
                "PATH": f"{bin_dir}:{wrk_env.get('PATH', '')}",
                "CC": str(toolchain_dir / "gcc"),
                "STRIP": str(cross_prefix) + "strip",
                "WITH_LUAJIT": str(src_root / "obj"),
                "WITH_OPENSSL": str(openssl_root),
            }
        )
        _run(["make", f"-j{jobs}"], cwd=src_root, env=wrk_env)
        _stage_arm64_portable_binary(
            tool_name="wrk",
            source_binary=src_root / "wrk",
            output_bin_dir=output_bin_dir,
            output_lib_dir=output_lib_dir,
            sysroot_root=sysroot_root,
            readelf_bin=readelf_bin,
            strip_bin=strip_bin,
        )

    builders = {
        "hackbench": build_hackbench,
        "sysbench": build_sysbench,
        "wrk": build_wrk,
    }
    for tool in tools:
        builder = builders.get(tool)
        if builder is None:
            _die(f"unsupported ARM64 workload tool: {tool}")
        builder()


def main(argv: list[str] | None = None) -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("mode", choices=("daemon", "runner", "repo-tests", "scx", "workload-tools"))
    args = parser.parse_args(argv)
    if args.mode == "daemon":
        build_daemon_from_env()
        return
    if args.mode == "runner":
        build_runner_from_env()
        return
    if args.mode == "repo-tests":
        build_repo_tests_from_env()
        return
    if args.mode == "scx":
        build_scx_from_env()
        return
    if args.mode == "workload-tools":
        build_workload_tools_from_env()
        return
    _die(f"unsupported mode: {args.mode}")


if __name__ == "__main__":
    main()
