from __future__ import annotations

import argparse
import fcntl
import os
import shutil
import subprocess
import sys
from contextlib import contextmanager
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail, require_nonempty_dir as _require_nonempty_dir
from runner.libs.runner_artifacts import build_runner_binary, build_vendor_bpftool
from runner.libs.source_tree import snapshot_git_tree, source_tree_stamp

_die = partial(fail, "cross-arm64")
_require_nonempty_dir = partial(_require_nonempty_dir, tag="cross-arm64")


def _log(message: str) -> None:
    print(f"[cross-arm64] {message}", file=sys.stderr)


def _env(name: str, default: str = "") -> str:
    return os.environ.get(name, default).strip()


def _require_env(name: str) -> str:
    value = _env(name)
    if not value:
        _die(f"{name} is required")
    return value


def _require_command(name: str) -> str:
    resolved = shutil.which(name)
    if not resolved:
        _die(f"missing required command: {name}")
    return resolved


def _run(
    command: list[str],
    *,
    cwd: Path | None = None,
    env: dict[str, str] | None = None,
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


def _run_passthrough(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    completed = subprocess.run(command, cwd=cwd, env=env, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


class Arm64ContainerBuild:
    def __init__(self) -> None:
        self.repo_root = ROOT_DIR
        self.source_repo_root = Path(_env("ARM64_SOURCE_REPO_ROOT", str(self.repo_root / "runner/repos")))
        self.jobs = _env("ARM64_CROSSBUILD_JOBS", "4") or "4"
        self.preferred_llvm_suffix = _env("ARM64_CROSSBUILD_LLVM_SUFFIX", "20")
        self.micro_exec_enable_llvmbpf = _env("MICRO_EXEC_ENABLE_LLVMBPF", "OFF") or "OFF"
        self.bench_repos_raw = _env("ARM64_CROSSBUILD_BENCH_REPOS")
        self.only_bench = _env("ARM64_CROSSBUILD_ONLY_BENCH", "0") == "1"
        self.runtime_targets_raw = _env("ARM64_CROSSBUILD_RUNTIME_TARGETS", "runner,daemon") or "runner,daemon"
        self.output_root = Path(_env("ARM64_CROSSBUILD_OUTPUT_DIR") or _env("OUT_DIR") or "/out")
        self.build_root = Path(_env("ARM64_CROSSBUILD_BUILD_ROOT", str(self.output_root / ".build-root")))
        self.host_uid = _env("HOST_UID")
        self.host_gid = _env("HOST_GID")
        self.prebuilt_daemon_binary = Path(_env("ARM64_PREBUILT_DAEMON_BINARY")) if _env("ARM64_PREBUILT_DAEMON_BINARY") else None
        self.runner_build_dir = self.build_root / "runner"
        self.runner_vendor_build_dir = self.build_root / "runner-vendor"
        self.llvmbpf_build_dir = self.build_root / "llvmbpf-build"
        self.llvmbpf_library = self.build_root / "libllvmbpf_vm.a"
        self.bench_build_repo_root = Path(_env("ARM64_BENCH_REPO_ROOT", str(self.build_root / "benchmark/repos")))
        self.bench_repo_lock_root = self.bench_build_repo_root.parent / ".repo-locks"
        self.native_repo_build_root = Path(_env("ARM64_NATIVE_REPO_BUILD_ROOT", str(self.build_root / "benchmark/native-build-cache")))
        self.katran_build_root = Path(_env("ARM64_KATRAN_BUILD_ROOT", str(self.build_root / "katranbuild")))
        self.katran_source_dir = self.bench_build_repo_root / "katran"
        # Keep Katran source and build trees separate so the shared source cache
        # stays pristine across reruns and CMake can reuse a stable out-of-tree
        # build/install root.
        self.katran_build_dir = self.katran_build_root / "cmake"
        self.katran_install_dir = self.katran_build_root / "deps"
        self.katran_getdeps_root = Path(_env("ARM64_KATRAN_GETDEPS_ROOT", str(self.katran_build_root / "getdeps")))
        self.katran_getdeps_lock = Path(_env("ARM64_KATRAN_GETDEPS_LOCK", str(self.katran_getdeps_root.parent / "katran-getdeps.lock")))
        self.vendor_bpftool_root = Path(_env("ARM64_VENDOR_BPFTOOL_ROOT", str(self.build_root / "vendor-bpftool")))
        self.vendor_bpftool_lock = Path(_env("ARM64_VENDOR_BPFTOOL_LOCK", str(self.vendor_bpftool_root.parent / "vendor-bpftool.lock")))
        self.toolchain_dir = self.build_root / "toolchain/bin"
        self.host_python = _require_env("ARM64_HOST_PYTHON_BIN")
        self.clang_bin = ""
        self.clangxx_bin = ""
        self.llc_bin = ""
        self.llvm_config_bin = ""
        self.llvm_strip_bin = ""
        self.llvm_objcopy_bin = ""
        self.ld_lld_bin = ""

    def runtime_target_enabled(self, target: str) -> bool:
        return f",{target}," in f",{self.runtime_targets_raw},"

    def fix_output_ownership(self) -> None:
        if os.geteuid() != 0 or not self.host_uid or not self.host_gid:
            return
        uid = int(self.host_uid)
        gid = int(self.host_gid)
        for path in (
            self.output_root,
            self.build_root,
            self.bench_build_repo_root,
            self.native_repo_build_root,
            self.katran_getdeps_root,
            self.vendor_bpftool_root,
            Path(os.environ.get("CARGO_HOME", "")) if os.environ.get("CARGO_HOME") else None,
        ):
            if path and path.exists():
                for root, dirs, files in os.walk(path):
                    try:
                        os.chown(root, uid, gid)
                    except FileNotFoundError:
                        continue
                    for name in dirs:
                        try:
                            os.chown(os.path.join(root, name), uid, gid)
                        except FileNotFoundError:
                            continue
                    for name in files:
                        try:
                            os.chown(os.path.join(root, name), uid, gid)
                        except FileNotFoundError:
                            continue

    def resolve_llvm_tool(self, base: str) -> str:
        candidates = [f"{base}-{self.preferred_llvm_suffix}", f"{base}{self.preferred_llvm_suffix}", base]
        for candidate in candidates:
            resolved = shutil.which(candidate)
            if resolved:
                return resolved
        _die(f"missing LLVM tool for ARM64 crossbuild: {base}")

    def prepare_llvm_toolchain(self) -> None:
        self.clang_bin = self.resolve_llvm_tool("clang")
        self.clangxx_bin = self.resolve_llvm_tool("clang++")
        self.llc_bin = self.resolve_llvm_tool("llc")
        self.llvm_config_bin = self.resolve_llvm_tool("llvm-config")
        self.llvm_strip_bin = self.resolve_llvm_tool("llvm-strip")
        self.llvm_objcopy_bin = self.resolve_llvm_tool("llvm-objcopy")
        self.ld_lld_bin = self.resolve_llvm_tool("ld.lld")
        shutil.rmtree(self.toolchain_dir, ignore_errors=True)
        self.toolchain_dir.mkdir(parents=True, exist_ok=True)
        link_map = {
            "clang": self.clang_bin,
            "clang++": self.clangxx_bin,
            "llc": self.llc_bin,
            "llvm-config": self.llvm_config_bin,
            "llvm-strip": self.llvm_strip_bin,
            "llvm-objcopy": self.llvm_objcopy_bin,
            "ld.lld": self.ld_lld_bin,
        }
        for name, target in link_map.items():
            link = self.toolchain_dir / name
            if link.exists() or link.is_symlink():
                link.unlink()
            link.symlink_to(target)
        os.environ["PATH"] = f"{self.toolchain_dir}:{os.environ.get('PATH', '')}"

    def prepare_repo_copy(self, repo_name: str, dest_dir: Path) -> None:
        src_dir = self.source_repo_root / repo_name
        if not src_dir.is_dir():
            _die(f"source repo {src_dir} is missing; fetch it locally first")
        stamp = self._source_repo_stamp(src_dir)
        stamp_path = dest_dir.parent / f".{repo_name}.source-stamp"
        with self._lock_repo(repo_name, suffix=".source.lock"):
            if dest_dir.is_dir() and stamp_path.is_file() and stamp_path.read_text(encoding="utf-8").strip() == stamp:
                _require_nonempty_dir(dest_dir, str(dest_dir))
                return
            shutil.rmtree(dest_dir, ignore_errors=True)
            dest_dir.mkdir(parents=True, exist_ok=True)
            if stamp.startswith("git:"):
                snapshot_git_tree(src_dir, dest_dir, die=_die)
            else:
                _require_nonempty_dir(src_dir, str(src_dir))
                shutil.copytree(src_dir, dest_dir, dirs_exist_ok=True)
                _require_nonempty_dir(dest_dir, str(dest_dir))
            stamp_path.parent.mkdir(parents=True, exist_ok=True)
            stamp_path.write_text(stamp + "\n", encoding="utf-8")

    def _source_repo_stamp(self, src_dir: Path) -> str:
        return source_tree_stamp(src_dir, die=_die)

    @contextmanager
    def _lock_repo(self, repo_name: str, *, suffix: str = ".build.lock"):
        with self._lock_file(self.bench_repo_lock_root / f"{repo_name}{suffix}"):
            yield

    def build_vendor_bpftool(self) -> Path:
        cached_binary = self.vendor_bpftool_root / "vendor" / "bpftool" / "bootstrap" / "bpftool"
        if cached_binary.is_file():
            return cached_binary
        with self._lock_file(self.vendor_bpftool_lock):
            if cached_binary.is_file():
                return cached_binary
            return build_vendor_bpftool(
                build_dir=self.vendor_bpftool_root.resolve(),
                env={**os.environ, "BPFTOOL_JOBS": "1"},
                expected_arch_signature="ARM aarch64",
            )

    def build_bcc_artifacts(self) -> None:
        repo_dir = self.bench_build_repo_root / "bcc"
        tool_dir = repo_dir / "libbpf-tools"
        bpftool = self.build_vendor_bpftool()
        required_tools = [
            "capable",
            "execsnoop",
            "bindsnoop",
            "biosnoop",
            "vfsstat",
            "opensnoop",
            "syscount",
            "tcpconnect",
            "tcplife",
            "runqlat",
            "fsdist",
        ]
        _log("Building ARM64 bcc libbpf-tools artifacts (benchmark subset only)")
        self.prepare_repo_copy("bcc", repo_dir)
        with self._lock_repo("bcc"):
            if not bpftool.is_file():
                _die(f"missing vendor bpftool for ARM64 bcc build: {bpftool}")
            _run_passthrough(
                [
                    "make",
                    "-C",
                    str(tool_dir),
                    f"-j{self.jobs}",
                    f"CLANG={self.clang_bin}",
                    f"LLVM_STRIP={self.llvm_strip_bin}",
                    "USE_BLAZESYM=0",
                    f"BPFTOOL={bpftool}",
                    f"LIBBPF_SRC={self.repo_root / 'vendor/libbpf/src'}",
                    *required_tools,
                ]
            )
            repo_output = self.output_root / "runner/repos/bcc/libbpf-tools/.output"
            corpus_output = self.output_root / "corpus/build/bcc/libbpf-tools/.output"
            repo_output.mkdir(parents=True, exist_ok=True)
            corpus_output.mkdir(parents=True, exist_ok=True)
            for obj_path in sorted((tool_dir / ".output").glob("*.bpf.o")):
                shutil.copy2(obj_path, repo_output / obj_path.name)
                shutil.copy2(obj_path, corpus_output / obj_path.name)
                tool_name = obj_path.name.removesuffix(".bpf.o")
                tool_binary = tool_dir / tool_name
                if tool_binary.is_file() and os.access(tool_binary, os.X_OK):
                    shutil.copy2(tool_binary, repo_output / tool_name)
                    shutil.copy2(tool_binary, corpus_output / tool_name)

    def build_katran_bpf_artifacts(self) -> None:
        repo_dir = self.bench_build_repo_root / "katran"
        lib_dir = repo_dir / "katran/lib"
        work_dir = self.build_root / "katran-bpf-build"
        _log("Building ARM64 katran BPF objects")
        shutil.rmtree(work_dir, ignore_errors=True)
        (work_dir / "include").mkdir(parents=True, exist_ok=True)
        (work_dir / "katran/lib").mkdir(parents=True, exist_ok=True)
        (work_dir / "bpf").mkdir(parents=True, exist_ok=True)
        shutil.copy2(lib_dir / "Makefile-bpf", work_dir / "Makefile")
        shutil.copytree(lib_dir / "bpf", work_dir / "katran/lib/bpf", dirs_exist_ok=True)
        shutil.copytree(lib_dir / "linux_includes", work_dir / "katran/lib/linux_includes", dirs_exist_ok=True)
        for obj_path in (lib_dir / "linux_includes").iterdir():
            if obj_path.is_file():
                shutil.copy2(obj_path, work_dir / "include" / obj_path.name)
        _run_passthrough(["make", "-C", str(work_dir), f"-j{self.jobs}", f"CLANG={self.clang_bin}", f"LLC={self.llc_bin}"])
        output_dir = self.output_root / "corpus/build/katran"
        output_dir.mkdir(parents=True, exist_ok=True)
        for obj_path in sorted((work_dir / "bpf").glob("*.o")):
            stage_name = obj_path.name[:-2] + ".bpf.o" if obj_path.suffix == ".o" and not obj_path.name.endswith(".bpf.o") else obj_path.name
            shutil.copy2(obj_path, output_dir / stage_name)

    def prepare_local_katran_dependencies(self, src_dir: Path, build_dir: Path, install_dir: Path) -> None:
        _log("Preparing local ARM64 Katran dependencies via getdeps")
        build_dir.mkdir(parents=True, exist_ok=True)
        install_dir.mkdir(parents=True, exist_ok=True)
        self.katran_getdeps_root.mkdir(parents=True, exist_ok=True)
        getdeps_stamp = self._katran_getdeps_stamp(src_dir)
        getdeps_stamp_path = self.katran_getdeps_root / ".katran-deps.stamp"
        env = os.environ.copy()
        env.update(
            {
                "CC": self.clang_bin,
                "CXX": self.clangxx_bin,
                "LD": self.ld_lld_bin,
            }
        )
        with self._lock_katran_getdeps():
            if getdeps_stamp_path.is_file() and getdeps_stamp_path.read_text(encoding="utf-8").strip() == getdeps_stamp:
                prefixes = self._katran_dependency_prefixes_unlocked(src_dir)
                if prefixes:
                    _log("Reusing cached ARM64 Katran getdeps outputs")
                    return
            # fbcode_builder patches extracted sources in-place. When we need to
            # rerun getdeps on the shared scratch root, keep immutable downloads
            # and installed prefixes, but reset mutable extracted/build trees so
            # patch application starts from a clean source state.
            for mutable_dir in (self.katran_getdeps_root / "build", self.katran_getdeps_root / "extracted"):
                shutil.rmtree(mutable_dir, ignore_errors=True)
            _run_passthrough(
                [
                    self.host_python,
                    str(src_dir / "build/fbcode_builder/getdeps.py"),
                    "--scratch-path",
                    str(self.katran_getdeps_root),
                    "--num-jobs",
                    self.jobs,
                    "--allow-system-packages",
                    "--shared-libs",
                    "build",
                    "--no-tests",
                    "--only-deps",
                    "--current-project",
                    "katran",
                    "--src-dir",
                    str(src_dir),
                    "katran",
                ],
                cwd=src_dir,
                env=env,
            )
            getdeps_stamp_path.write_text(getdeps_stamp + "\n", encoding="utf-8")

    def katran_dependency_prefixes(self, src_dir: Path) -> list[str]:
        with self._lock_katran_getdeps():
            return self._katran_dependency_prefixes_unlocked(src_dir)

    def _katran_dependency_prefixes_unlocked(self, src_dir: Path) -> list[str]:
        completed = _run(
            [
                self.host_python,
                str(src_dir / "build/fbcode_builder/getdeps.py"),
                "--scratch-path",
                str(self.katran_getdeps_root),
                "--allow-system-packages",
                "--shared-libs",
                "query-paths",
                "--recursive",
                "--no-tests",
                "--current-project",
                "katran",
                "--src-dir",
                str(src_dir),
                "katran",
            ],
            cwd=src_dir,
        )
        prefixes: list[str] = []
        for raw_line in completed.stdout.splitlines():
            line = raw_line.strip()
            if not line or "_INSTALL=" not in line:
                continue
            name, value = line.split("_INSTALL=", 1)
            if name == "katran":
                continue
            value = value.strip()
            if value and value not in prefixes:
                prefixes.append(value)
        if not prefixes:
            _die("failed to resolve Katran dependency install prefixes from getdeps")
        return prefixes

    @contextmanager
    def _lock_katran_getdeps(self):
        with self._lock_file(self.katran_getdeps_lock):
            yield

    @contextmanager
    def _lock_file(self, path: Path):
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open("w", encoding="utf-8") as handle:
            fcntl.flock(handle.fileno(), fcntl.LOCK_EX)
            try:
                yield
            finally:
                fcntl.flock(handle.fileno(), fcntl.LOCK_UN)

    def build_katran_binary_with_wrapper(self, src_dir: Path, build_dir: Path, install_dir: Path) -> None:
        cmake_build_dir = build_dir / "build"
        cmake_build_dir.mkdir(parents=True, exist_ok=True)
        dependency_prefixes = self.katran_dependency_prefixes(src_dir)
        prefix_path = ":".join([*dependency_prefixes, str(install_dir)])
        configure_stamp = self._katran_configure_stamp(src_dir, prefix_path, install_dir)
        configure_stamp_path = build_dir / ".katran-cmake.stamp"
        pkgconfig_paths: list[str] = []
        for prefix in dependency_prefixes:
            for suffix in ("lib/pkgconfig", "lib64/pkgconfig", "share/pkgconfig"):
                candidate = Path(prefix) / suffix
                if candidate.is_dir():
                    pkgconfig_paths.append(str(candidate))
        env = os.environ.copy()
        env.update(
            {
                "CC": self.clang_bin,
                "CXX": self.clangxx_bin,
                "LD": self.ld_lld_bin,
                "CMAKE_PREFIX_PATH": prefix_path,
                "PKG_CONFIG_PATH": ":".join(pkgconfig_paths),
                "GETDEPS_INSTALL_DIR": str(self.katran_getdeps_root / "installed"),
            }
        )
        cache_file = cmake_build_dir / "CMakeCache.txt"
        if not (cache_file.is_file() and configure_stamp_path.is_file() and configure_stamp_path.read_text(encoding="utf-8").strip() == configure_stamp):
            _run_passthrough(
                [
                    "cmake",
                    "-G",
                    "Ninja",
                    f"-DCMAKE_C_COMPILER={self.clang_bin}",
                    f"-DCMAKE_CXX_COMPILER={self.clangxx_bin}",
                    f"-DCMAKE_LINKER={self.ld_lld_bin}",
                    f"-DCMAKE_PREFIX_PATH={prefix_path}",
                    f"-DCMAKE_INSTALL_PREFIX={install_dir}",
                    "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
                    "-DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON",
                    f"-DLIB_BPF_PREFIX={install_dir}",
                    "-DCMAKE_CXX_STANDARD=17",
                    "-DBUILD_TESTS=OFF",
                    "-DCMAKE_BUILD_EXAMPLE_GRPC=ON",
                    "-DCMAKE_BUILD_EXAMPLE_THRIFT=OFF",
                    "-DCMAKE_BUILD_TOOLS=OFF",
                    "-DCMAKE_BUILD_KATRAN_TPR=OFF",
                    str(src_dir),
                ],
                cwd=cmake_build_dir,
                env=env,
            )
            configure_stamp_path.write_text(configure_stamp + "\n", encoding="utf-8")
        else:
            _log("Reusing cached ARM64 Katran CMake configure")
        _run_passthrough(["cmake", "--build", ".", f"-j{self.jobs}", "--target", "katran_server_grpc"], cwd=cmake_build_dir, env=env)

    def _katran_getdeps_stamp(self, src_dir: Path) -> str:
        digest = hashlib.sha256()
        for token in (
            self._source_repo_stamp(src_dir),
            self.host_python,
            self.clang_bin,
            self.clangxx_bin,
            self.ld_lld_bin,
        ):
            digest.update(token.encode("utf-8"))
            digest.update(b"\0")
        return digest.hexdigest()

    def _katran_configure_stamp(self, src_dir: Path, prefix_path: str, install_dir: Path) -> str:
        digest = hashlib.sha256()
        for token in (
            self._source_repo_stamp(src_dir),
            prefix_path,
            str(install_dir.resolve()),
            self.clang_bin,
            self.clangxx_bin,
            self.ld_lld_bin,
            self.jobs,
        ):
            digest.update(token.encode("utf-8"))
            digest.update(b"\0")
        return digest.hexdigest()

    def copy_runtime_bundle(self, binary: Path, output_lib_dir: Path | None = None) -> None:
        output_lib_dir = output_lib_dir or (self.output_root / "lib")
        output_lib_dir.mkdir(parents=True, exist_ok=True)
        queue: list[Path] = [binary]
        seen: set[Path] = set()
        while queue:
            current = queue.pop(0)
            if current in seen or not current.exists():
                continue
            seen.add(current)
            completed = _run(["ldd", str(current)])
            libraries: list[Path] = []
            for line in completed.stdout.splitlines():
                line = line.strip()
                if "=>" in line:
                    parts = line.split("=>", 1)[1].strip().split()
                    if parts and parts[0].startswith("/"):
                        libraries.append(Path(parts[0]))
                elif line.startswith("/"):
                    libraries.append(Path(line.split()[0]))
            for lib in sorted(set(libraries)):
                resolved = lib.resolve()
                resolved_name = resolved.name
                if resolved_name in {
                    "ld-linux-aarch64.so.1",
                    "libc.so.6",
                    "libm.so.6",
                    "libpthread.so.0",
                    "librt.so.1",
                    "libdl.so.2",
                    "libresolv.so.2",
                    "libutil.so.1",
                }:
                    continue
                shutil.copy2(resolved, output_lib_dir / resolved_name)
                if lib.name != resolved_name:
                    link = output_lib_dir / lib.name
                    if link.exists() or link.is_symlink():
                        link.unlink()
                    link.symlink_to(resolved_name)
                soname_output = _run(["readelf", "-d", str(resolved)])
                soname = ""
                for soname_line in soname_output.stdout.splitlines():
                    marker = "Library soname: ["
                    if marker in soname_line:
                        soname = soname_line.split(marker, 1)[1].split("]", 1)[0]
                        break
                if soname and soname != resolved_name:
                    link = output_lib_dir / soname
                    if link.exists() or link.is_symlink():
                        link.unlink()
                    link.symlink_to(resolved_name)
                queue.append(resolved)

    def copy_wrapper(self, wrapper: Path, real_name: str) -> None:
        wrapper.parent.mkdir(parents=True, exist_ok=True)
        wrapper.write_text(
            "\n".join(
                (
                    "#!/usr/bin/env bash",
                    "set -euo pipefail",
                    'SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"',
                    'BUNDLE_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"',
                    'LIB_DIR="$BUNDLE_ROOT/lib"',
                    'export LD_LIBRARY_PATH="$LIB_DIR${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"',
                    f'exec "$SCRIPT_DIR/{real_name}" "$@"',
                    "",
                )
            ),
            encoding="utf-8",
        )
        wrapper.chmod(0o755)

    def build_katran_server_bundle(self) -> None:
        repo_dir = self.bench_build_repo_root / "katran"
        bundle_dir = self.output_root / "corpus" / "build" / "katran"
        binary_path = self.katran_build_dir / "build/example_grpc/katran_server_grpc"
        _log("Building local ARM64 katran_server_grpc bundle")
        shutil.rmtree(bundle_dir, ignore_errors=True)
        self.prepare_local_katran_dependencies(repo_dir, self.katran_build_dir, self.katran_install_dir)
        self.build_katran_binary_with_wrapper(repo_dir, self.katran_build_dir, self.katran_install_dir)
        if not binary_path.is_file() or not os.access(binary_path, os.X_OK):
            _die(f"missing local ARM64 katran_server_grpc: {binary_path}")
        _run(["file", str(binary_path)])
        bundle_bin = bundle_dir / "bin"
        bundle_lib = bundle_dir / "lib"
        bundle_bin.mkdir(parents=True, exist_ok=True)
        bundle_lib.mkdir(parents=True, exist_ok=True)
        shutil.copy2(binary_path, bundle_bin / "katran_server_grpc")
        self.copy_runtime_bundle(bundle_bin / "katran_server_grpc", bundle_lib)

    def build_katran_artifacts(self) -> None:
        self.prepare_repo_copy("katran", self.bench_build_repo_root / "katran")
        self.build_katran_bpf_artifacts()
        self.build_katran_server_bundle()

    def build_isolated_native_corpus_repo(self, repo_name: str) -> None:
        output_dir = self.output_root / f"corpus/build/{repo_name}"
        _log(f"Building isolated ARM64 {repo_name} artifacts")
        self.prepare_repo_copy(repo_name, self.bench_build_repo_root / repo_name)
        shutil.rmtree(output_dir, ignore_errors=True)
        output_dir.parent.mkdir(parents=True, exist_ok=True)
        with self._lock_repo(repo_name):
            _run_passthrough(
                [
                    "make",
                    "-C",
                    str(self.repo_root),
                    "__native-repo-build",
                    f"PYTHON={self.host_python}",
                    f"JOBS={self.jobs}",
                    f"NATIVE_REPO_ROOT={self.bench_build_repo_root}",
                    f"NATIVE_BUILD_ROOT={self.native_repo_build_root}",
                    f"NATIVE_STAGE_ROOT={self.output_root / 'corpus' / 'build'}",
                    f"NATIVE_REPOS_CSV={repo_name}",
                ]
            )
        if not output_dir.is_dir():
            _die(f"missing staged ARM64 {repo_name} artifacts: {output_dir}")

    def build_tracee_artifacts(self) -> None:
        self.build_isolated_native_corpus_repo("tracee")
        binary = self.output_root / "corpus" / "build" / "tracee" / "bin" / "tracee"
        if not binary.is_file():
            _die(f"missing staged ARM64 tracee binary: {binary}")

    def build_tetragon_artifacts(self) -> None:
        self.build_isolated_native_corpus_repo("tetragon")
        binary = self.output_root / "corpus" / "build" / "tetragon" / "bin" / "tetragon"
        if not binary.is_file():
            _die(f"missing staged ARM64 tetragon binary: {binary}")

    def build_benchmark_repo_artifacts(self) -> None:
        if not self.bench_repos_raw:
            return
        for repo in [token for token in self.bench_repos_raw.split(",") if token]:
            if repo == "bcc":
                self.build_bcc_artifacts()
            elif repo == "katran":
                self.build_katran_artifacts()
            elif repo == "tracee":
                self.build_tracee_artifacts()
            elif repo == "tetragon":
                self.build_tetragon_artifacts()
            else:
                _die(f"unsupported ARM64 benchmark crossbuild repo: {repo}")

    def build_llvmbpf_if_needed(self) -> None:
        if self.micro_exec_enable_llvmbpf != "ON":
            return
        _log("Building ARM64 llvmbpf static library")
        _run_passthrough(
            [
                "cmake",
                "-S",
                str(self.repo_root / "vendor/llvmbpf"),
                "-B",
                str(self.llvmbpf_build_dir),
                "-DCMAKE_BUILD_TYPE=Release",
                f"-DCMAKE_C_COMPILER={self.clang_bin}",
                f"-DCMAKE_CXX_COMPILER={self.clangxx_bin}",
                f"-DLLVM_DIR={_run([self.llvm_config_bin, '--cmakedir']).stdout.strip()}",
            ]
        )
        _run_passthrough(["cmake", "--build", str(self.llvmbpf_build_dir), "--target", "llvmbpf_vm", f"-j{self.jobs}"])
        if not self.llvmbpf_library.is_file():
            _die(f"missing ARM64 llvmbpf archive: {self.llvmbpf_library}")

    def build_runner(self) -> None:
        _log(f"Building ARM64 runner (MICRO_EXEC_ENABLE_LLVMBPF={self.micro_exec_enable_llvmbpf})")
        llvmbpf_library_path = str(self.llvmbpf_library.resolve()) if self.micro_exec_enable_llvmbpf == "ON" else ""
        llvmbpf_cache_path = str((self.llvmbpf_build_dir / "CMakeCache.txt").resolve()) if self.micro_exec_enable_llvmbpf == "ON" else ""
        llvmbpf_spdlog_library = ""
        if self.micro_exec_enable_llvmbpf == "ON":
            for candidate in (
                self.llvmbpf_build_dir / "_deps" / "spdlog-build" / "libspdlogd.a",
                self.llvmbpf_build_dir / "_deps" / "spdlog-build" / "libspdlog.a",
            ):
                if candidate.is_file():
                    llvmbpf_spdlog_library = str(candidate.resolve())
                    break
        llvm_cmake_dir = _run([self.llvm_config_bin, "--cmakedir"]).stdout.strip()
        build_runner_binary(
            build_dir=self.runner_build_dir.resolve(),
            env={
                **os.environ,
                "CC": self.clang_bin,
                "CXX": self.clangxx_bin,
                "JOBS": "1",
                "RUN_LLVM_DIR": llvm_cmake_dir,
                "MICRO_EXEC_ENABLE_LLVMBPF": self.micro_exec_enable_llvmbpf,
                "MICRO_LLVMBPF_LIBRARY": llvmbpf_library_path,
                "MICRO_LLVMBPF_BUILD_CACHE": llvmbpf_cache_path,
                "MICRO_LLVMBPF_SPDLOG_LIBRARY": llvmbpf_spdlog_library,
            },
            expected_arch_signature="ARM aarch64",
            llvmbpf_default=self.micro_exec_enable_llvmbpf,
        )

    def run(self) -> None:
        for cmd in ("make", "cmake", "cargo", "file", "git", "ldd", self.host_python, "tar"):
            _require_command(cmd)
        self.prepare_llvm_toolchain()
        Path(os.environ.get("HOME", "/tmp/codex")).mkdir(parents=True, exist_ok=True)
        subprocess.run(["git", "config", "--global", "--add", "safe.directory", "*"], check=False, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if os.uname().machine != "aarch64":
            _die("arm64_container_build.py must run inside an aarch64 userspace")
        (self.output_root / "lib").mkdir(parents=True, exist_ok=True)
        if self.runtime_target_enabled("runner"):
            (self.output_root / "runner/build").mkdir(parents=True, exist_ok=True)
            shutil.rmtree(self.runner_build_dir, ignore_errors=True)
        if self.runtime_target_enabled("daemon"):
            (self.output_root / "daemon/build").mkdir(parents=True, exist_ok=True)
        self.build_root.mkdir(parents=True, exist_ok=True)
        if self.only_bench:
            self.build_benchmark_repo_artifacts()
            return
        self.build_llvmbpf_if_needed()
        if not (self.runtime_target_enabled("runner") or self.runtime_target_enabled("daemon")):
            _die("ARM64 runtime build requested with no runtime targets enabled")
        if self.runtime_target_enabled("runner"):
            self.build_runner()
            real_runner = self.output_root / "runner/build/micro_exec.real"
            shutil.copy2(self.runner_build_dir / "micro_exec", real_runner)
            self.copy_runtime_bundle(real_runner)
            self.copy_wrapper(self.output_root / "runner/build/micro_exec", "micro_exec.real")
            _run(["file", str(real_runner)])
        if self.runtime_target_enabled("daemon"):
            if not self.prebuilt_daemon_binary or not self.prebuilt_daemon_binary.is_file():
                _die("ARM64 runtime build requires ARM64_PREBUILT_DAEMON_BINARY when daemon target is enabled")
            real_daemon = self.output_root / "daemon/build/bpfrejit-daemon.real"
            shutil.copy2(self.prebuilt_daemon_binary, real_daemon)
            self.copy_runtime_bundle(real_daemon)
            self.copy_wrapper(self.output_root / "daemon/build/bpfrejit-daemon", "bpfrejit-daemon.real")


def main(argv: list[str] | None = None) -> None:
    parser = argparse.ArgumentParser()
    _ = parser.parse_args(argv)
    builder = Arm64ContainerBuild()
    try:
        builder.run()
    finally:
        builder.fix_output_ownership()


if __name__ == "__main__":
    main()
