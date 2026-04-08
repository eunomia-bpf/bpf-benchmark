from __future__ import annotations

import argparse
import os
import pwd
import grp
import shutil
import subprocess
import sys
from pathlib import Path
from typing import NoReturn

from runner.libs import ROOT_DIR


def _die(message: str) -> NoReturn:
    print(f"[cross-arm64][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _log(message: str) -> None:
    print(f"[cross-arm64] {message}", file=sys.stderr)


def _env(name: str, default: str = "") -> str:
    return os.environ.get(name, default).strip()


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


def _require_nonempty_dir(path: Path, description: str) -> None:
    if not path.is_dir():
        _die(f"{description} is not a directory: {path}")
    try:
        next(path.iterdir())
    except StopIteration:
        _die(f"{description} is empty: {path}")


def _snapshot_git_tree(repo_root: Path, dest: Path) -> None:
    if subprocess.run(["git", "-C", str(repo_root), "rev-parse", "--verify", "HEAD"], check=False).returncode != 0:
        _die(f"expected git checkout for promoted snapshot: {repo_root}")
    if not _git_path_is_clean(repo_root):
        _die(f"source repo {repo_root} has local modifications and cannot be sealed")
    shutil.rmtree(dest, ignore_errors=True)
    dest.mkdir(parents=True, exist_ok=True)
    archive = subprocess.Popen(
        ["git", "-C", str(repo_root), "archive", "--format=tar", "HEAD"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    extract = subprocess.run(
        ["tar", "-xf", "-", "-C", str(dest)],
        stdin=archive.stdout,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
        text=False,
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
    _require_nonempty_dir(dest, str(dest))


class Arm64ContainerBuild:
    def __init__(self) -> None:
        self.repo_root = ROOT_DIR
        self.source_repo_root = Path(_env("ARM64_SOURCE_REPO_ROOT", str(self.repo_root / "runner/repos")))
        self.jobs = _env("ARM64_CROSSBUILD_JOBS", "4") or "4"
        self.preferred_llvm_suffix = _env("ARM64_CROSSBUILD_LLVM_SUFFIX", "20")
        self.micro_exec_enable_llvmbpf = _env("MICRO_EXEC_ENABLE_LLVMBPF", "OFF") or "OFF"
        self.scx_packages_raw = _env("ARM64_CROSSBUILD_SCX_PACKAGES")
        self.only_scx = _env("ARM64_CROSSBUILD_ONLY_SCX", "0") == "1"
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
        self.scx_build_repo_root = self.build_root / "runner/repos"
        self.scx_build_repo_dir = self.scx_build_repo_root / "scx"
        self.bench_build_repo_root = self.build_root / "benchmark/repos"
        self.bench_stage_root = self.build_root / "benchmark/stage"
        self.katran_build_root = Path(_env("ARM64_KATRAN_BUILD_ROOT", str(self.build_root / "katranbuild")))
        self.katran_source_dir = self.katran_build_root / "src"
        self.katran_build_dir = self.katran_source_dir / "_build"
        self.katran_install_dir = self.katran_build_dir / "deps"
        self.toolchain_dir = self.build_root / "toolchain/bin"
        self.native_cargo_linker = _env("ARM64_NATIVE_CARGO_LINKER", "gcc") or "gcc"
        self.rustfmt_bin = _env("ARM64_CROSSBUILD_RUSTFMT", "rustfmt") or "rustfmt"
        self.host_python = _env("ARM64_HOST_PYTHON_BIN", "python3") or "python3"
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
        for path in (self.output_root, self.build_root, Path(os.environ.get("CARGO_HOME", "")) if os.environ.get("CARGO_HOME") else None):
            if path and path.exists():
                for root, dirs, files in os.walk(path):
                    os.chown(root, uid, gid)
                    for name in dirs:
                        os.chown(os.path.join(root, name), uid, gid)
                    for name in files:
                        os.chown(os.path.join(root, name), uid, gid)

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
            "rustfmt": _require_command(self.rustfmt_bin),
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
        shutil.rmtree(dest_dir, ignore_errors=True)
        dest_dir.mkdir(parents=True, exist_ok=True)
        if subprocess.run(["git", "-C", str(src_dir), "rev-parse", "--verify", "HEAD"], check=False).returncode == 0:
            if not _git_path_is_clean(src_dir):
                _die(f"source repo {src_dir} has local modifications and cannot be sealed")
            _snapshot_git_tree(src_dir, dest_dir)
        else:
            _require_nonempty_dir(src_dir, str(src_dir))
            shutil.copytree(src_dir, dest_dir, dirs_exist_ok=True)
            _require_nonempty_dir(dest_dir, str(dest_dir))

    def build_vendor_bpftool(self) -> None:
        _run_passthrough(
            [
                "make",
                "-C",
                str(self.repo_root / "runner"),
                f"BUILD_DIR={self.runner_vendor_build_dir.resolve()}",
                "JOBS=1",
                "vendor_bpftool",
            ]
        )

    def build_bcc_artifacts(self) -> None:
        repo_dir = self.bench_build_repo_root / "bcc"
        tool_dir = repo_dir / "libbpf-tools"
        bpftool = self.runner_vendor_build_dir / "vendor/bpftool/bootstrap/bpftool"
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
        self.build_vendor_bpftool()
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

    def sync_katran_source_tree(self, repo_dir: Path) -> None:
        self.katran_source_dir.mkdir(parents=True, exist_ok=True)
        for child in list(self.katran_source_dir.iterdir()):
            if child.name == "_build":
                continue
            if child.is_dir():
                shutil.rmtree(child)
            else:
                child.unlink()
        shutil.copytree(repo_dir, self.katran_source_dir, dirs_exist_ok=True)

    def prepare_local_katran_dependencies(self, src_dir: Path, build_dir: Path, install_dir: Path) -> None:
        _log("Preparing local ARM64 Katran dependencies")
        shim_dir = build_dir / "pkgshim"
        build_dir.mkdir(parents=True, exist_ok=True)
        install_dir.mkdir(parents=True, exist_ok=True)
        shim_dir.mkdir(parents=True, exist_ok=True)
        shim_scripts = {
            "yum": '#!/usr/bin/env bash\nset -euo pipefail\necho "[cross-arm64][katran] skipping upstream yum invocation: $*" >&2\nexit 0\n',
            "yum-config-manager": '#!/usr/bin/env bash\nset -euo pipefail\necho "[cross-arm64][katran] skipping upstream yum-config-manager invocation: $*" >&2\nexit 0\n',
            "sudo": '#!/usr/bin/env bash\nset -euo pipefail\nif [[ $# -eq 0 ]]; then\n    exit 0\nfi\nexec "$@"\n',
        }
        for name, content in shim_scripts.items():
            path = shim_dir / name
            path.write_text(content, encoding="utf-8")
            path.chmod(0o755)
        env = os.environ.copy()
        env.update(
            {
                "PATH": f"{shim_dir}:{env.get('PATH', '')}",
                "CC": self.clang_bin,
                "CXX": self.clangxx_bin,
                "LD": self.ld_lld_bin,
                "CLANG": self.clang_bin,
                "LLC": self.llc_bin,
                "LLVM_CONFIG": self.llvm_config_bin,
                "LLVM_OBJCOPY": self.llvm_objcopy_bin,
                "LLVM_STRIP": self.llvm_strip_bin,
                "INSTALL_DEPS_ONLY": "1",
                "BUILD_EXAMPLE_GRPC": "1",
                "NCPUS": self.jobs,
            }
        )
        _run_passthrough(["bash", str(src_dir / "build_katran.sh"), "-p", str(build_dir), "-i", str(install_dir)], cwd=src_dir, env=env)

    def build_katran_binary_with_wrapper(self, src_dir: Path, build_dir: Path, install_dir: Path) -> None:
        cmake_build_dir = build_dir / "build"
        cmake_build_dir.mkdir(parents=True, exist_ok=True)
        env = os.environ.copy()
        env.update({"CC": self.clang_bin, "CXX": self.clangxx_bin, "LD": self.ld_lld_bin})
        _run_passthrough(
            [
                "cmake",
                "-G",
                "Ninja",
                f"-DCMAKE_C_COMPILER={self.clang_bin}",
                f"-DCMAKE_CXX_COMPILER={self.clangxx_bin}",
                f"-DCMAKE_LINKER={self.ld_lld_bin}",
                f"-DCMAKE_PREFIX_PATH={install_dir}",
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
        _run_passthrough(["cmake", "--build", ".", f"-j{self.jobs}", "--target", "katran_server_grpc"], cwd=cmake_build_dir, env=env)

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
        bundle_dir = self.output_root / "katran"
        binary_path = self.katran_build_dir / "build/example_grpc/katran_server_grpc"
        _log("Building local ARM64 katran_server_grpc bundle")
        self.sync_katran_source_tree(repo_dir)
        shutil.rmtree(self.katran_build_dir / "build", ignore_errors=True)
        shutil.rmtree(bundle_dir, ignore_errors=True)
        self.prepare_local_katran_dependencies(self.katran_source_dir, self.katran_build_dir, self.katran_install_dir)
        self.build_katran_binary_with_wrapper(self.katran_source_dir, self.katran_build_dir, self.katran_install_dir)
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
        repo_dir = self.bench_build_repo_root / "katran"
        self.prepare_repo_copy("katran", repo_dir)
        self.build_katran_bpf_artifacts()
        self.build_katran_server_bundle()

    def build_isolated_native_corpus_repo(self, repo_name: str) -> None:
        stage_dir = self.bench_stage_root / repo_name
        _log(f"Building isolated ARM64 {repo_name} artifacts")
        self.prepare_repo_copy(repo_name, self.bench_build_repo_root / repo_name)
        shutil.rmtree(stage_dir, ignore_errors=True)
        self.bench_stage_root.mkdir(parents=True, exist_ok=True)
        _run_passthrough(
            [
                self.host_python,
                str(self.repo_root / "runner/scripts/build_corpus_native.py"),
                "--jobs",
                self.jobs,
                "--repo-root",
                str(self.bench_build_repo_root),
                "--build-root",
                str(self.bench_stage_root),
                "--repo",
                repo_name,
            ]
        )
        if not stage_dir.is_dir():
            _die(f"missing staged ARM64 {repo_name} artifacts: {stage_dir}")

    def copy_staged_corpus_repo_tree(self, repo_name: str) -> None:
        stage_dir = self.bench_stage_root / repo_name
        output_dir = self.output_root / f"corpus/build/{repo_name}"
        if not stage_dir.is_dir():
            _die(f"missing staged ARM64 {repo_name} tree: {stage_dir}")
        shutil.rmtree(output_dir, ignore_errors=True)
        output_dir.mkdir(parents=True, exist_ok=True)
        shutil.copytree(stage_dir, output_dir, dirs_exist_ok=True)

    def build_tracee_artifacts(self) -> None:
        self.build_isolated_native_corpus_repo("tracee")
        binary = self.bench_stage_root / "tracee/bin/tracee"
        if not binary.is_file():
            _die(f"missing staged ARM64 tracee binary: {binary}")
        self.copy_staged_corpus_repo_tree("tracee")

    def build_tetragon_artifacts(self) -> None:
        self.build_isolated_native_corpus_repo("tetragon")
        binary = self.bench_stage_root / "tetragon/bin/tetragon"
        if not binary.is_file():
            _die(f"missing staged ARM64 tetragon binary: {binary}")
        self.copy_staged_corpus_repo_tree("tetragon")

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
        _run_passthrough(
            [
                "make",
                "-C",
                str(self.repo_root / "runner"),
                f"BUILD_DIR={self.runner_build_dir.resolve()}",
                "JOBS=1",
                f"LLVM_CONFIG={self.llvm_config_bin}",
                f"LLVMBPF_LLVM_DIR={_run([self.llvm_config_bin, '--cmakedir']).stdout.strip()}",
                f"MICRO_EXEC_ENABLE_LLVMBPF={self.micro_exec_enable_llvmbpf}",
                f"MICRO_LLVMBPF_LIBRARY={llvmbpf_library_path}",
                f"MICRO_LLVMBPF_BUILD_CACHE={llvmbpf_cache_path}",
                "micro_exec",
            ],
            env=os.environ | {"CC": self.clang_bin, "CXX": self.clangxx_bin},
        )

    def prepare_scx_checkout(self) -> None:
        self.prepare_repo_copy("scx", self.scx_build_repo_dir)
        shutil.rmtree(self.scx_build_repo_dir / "target", ignore_errors=True)

    def build_scx_artifacts(self) -> None:
        if not self.scx_packages_raw:
            return
        _log(f"Building ARM64 scx artifacts: {self.scx_packages_raw}")
        self.prepare_scx_checkout()
        packages = [token for token in self.scx_packages_raw.split(",") if token]
        command = [
            self.host_python,
            str(self.repo_root / "runner/scripts/build_scx_artifacts.py"),
            "--force",
            "--jobs",
            self.jobs,
            "--repo-root",
            str(self.scx_build_repo_root),
            "--promote-root",
            str(self.output_root),
        ]
        for package in packages:
            command.extend(["--package", package])
        env = os.environ.copy()
        env.update(
            {
                "CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER": self.native_cargo_linker,
                "SCX_BUILD_JOBS": self.jobs,
                "BPF_CLANG": self.clang_bin,
                "CLANG": self.clang_bin,
                "LLC": self.llc_bin,
                "LLVM_CONFIG": self.llvm_config_bin,
                "LLVM_OBJCOPY": self.llvm_objcopy_bin,
                "LLVM_STRIP": self.llvm_strip_bin,
                "CC": self.clang_bin,
                "CXX": self.clangxx_bin,
            }
        )
        _run_passthrough(command, env=env)
        release_dir = self.scx_build_repo_dir / "target/release"
        if not release_dir.is_dir():
            release_dir = self.scx_build_repo_dir / "target/aarch64-unknown-linux-gnu/release"
        target_release_dir = self.output_root / "runner/repos/scx/target/release"
        target_release_dir.mkdir(parents=True, exist_ok=True)
        (self.output_root / "corpus/build/scx").mkdir(parents=True, exist_ok=True)
        for package in packages:
            binary = release_dir / package
            if not binary.is_file():
                _die(f"expected scx binary missing after build: {binary}")
            destination = target_release_dir / package
            shutil.copy2(binary, destination)
            self.copy_runtime_bundle(destination)

    def run(self) -> None:
        for cmd in ("make", "cmake", "cargo", "file", "git", "ldd", self.host_python, self.rustfmt_bin, "tar"):
            _require_command(cmd)
        self.prepare_llvm_toolchain()
        Path(os.environ.get("HOME", "/tmp/codex")).mkdir(parents=True, exist_ok=True)
        subprocess.run(["git", "config", "--global", "--add", "safe.directory", "*"], check=False, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if os.uname().machine != "aarch64":
            _die("arm64_container_build.py must run inside an aarch64 userspace")
        (self.output_root / "lib").mkdir(parents=True, exist_ok=True)
        if not self.only_scx:
            if self.runtime_target_enabled("runner"):
                (self.output_root / "runner/build").mkdir(parents=True, exist_ok=True)
                shutil.rmtree(self.runner_build_dir, ignore_errors=True)
            if self.runtime_target_enabled("daemon"):
                (self.output_root / "daemon/build").mkdir(parents=True, exist_ok=True)
        self.build_root.mkdir(parents=True, exist_ok=True)
        self.build_scx_artifacts()
        if self.only_scx:
            return
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
