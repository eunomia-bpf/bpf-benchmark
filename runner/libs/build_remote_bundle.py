from __future__ import annotations

import hashlib
import json
import os
import shutil
import stat
import subprocess
import sys
import tarfile
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail, require_nonempty_dir, require_path
from runner.libs.manifest_file import parse_manifest, render_shell_assignments_from_mapping
from runner.libs.state_file import read_state

_die = partial(fail, "build-remote-bundle")
_require_path = partial(require_path, tag="build-remote-bundle")
_require_nonempty_dir = partial(require_nonempty_dir, tag="build-remote-bundle")

_BUNDLE_CACHE_IGNORED_MANIFEST_KEYS = {"RUN_TOKEN"}


def _parse_scalar_manifest(path: Path) -> dict[str, str]:
    parsed = parse_manifest(path)
    values: dict[str, str] = {}
    for key, value in parsed.items():
        if isinstance(value, list):
            values[key] = " ".join(value)
        else:
            values[key] = value
    return values


def _git_ok(args: list[str], *, cwd: Path) -> bool:
    return subprocess.run(args, cwd=cwd, check=False, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL).returncode == 0


def _git_output(args: list[str], *, cwd: Path) -> bytes:
    completed = subprocess.run(args, cwd=cwd, check=False, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if completed.returncode != 0:
        message = completed.stderr.decode("utf-8", errors="replace").strip() or "git command failed"
        _die(message)
    return completed.stdout


def _git_untracked_paths(repo_root: Path, pathspec: str | None = None) -> list[Path]:
    args = ["git", "ls-files", "--others", "--exclude-standard", "-z"]
    if pathspec:
        args.extend(["--", pathspec])
    raw = _git_output(args, cwd=repo_root)
    tokens = [token.decode("utf-8") for token in raw.split(b"\0") if token]
    return [Path(token) for token in tokens]


def _git_path_is_clean(repo_root: Path, pathspec: str | None = None) -> bool:
    args = ["git", "diff", "--quiet"]
    if pathspec:
        args.extend(["--", pathspec])
    if not _git_ok(args, cwd=repo_root):
        return False
    args = ["git", "diff", "--cached", "--quiet"]
    if pathspec:
        args.extend(["--", pathspec])
    return _git_ok(args, cwd=repo_root)


def _copy_symlink(src: Path, dest: Path) -> None:
    dest.parent.mkdir(parents=True, exist_ok=True)
    if dest.exists() or dest.is_symlink():
        if dest.is_dir() and not dest.is_symlink():
            shutil.rmtree(dest)
        else:
            dest.unlink()
    os.symlink(os.readlink(src), dest)


def _copy_path(src: Path, dest: Path) -> None:
    if src.is_symlink():
        _copy_symlink(src, dest)
        return
    if src.is_dir():
        shutil.copytree(src, dest, symlinks=True, dirs_exist_ok=True)
        return
    dest.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dest)


def _iter_git_tracked_paths(repo_root: Path, pathspec: str | None = None) -> list[Path]:
    args = ["git", "ls-files", "-z"]
    if pathspec:
        args.extend(["--", pathspec])
    raw = _git_output(args, cwd=repo_root)
    tokens = [token.decode("utf-8") for token in raw.split(b"\0") if token]
    return [Path(token) for token in tokens]


def _hash_git_tracked_tree(repo_root: Path, pathspec: str) -> str:
    if not _git_ok(["git", "rev-parse", "--verify", "HEAD"], cwd=repo_root):
        _die(f"expected git checkout for tracked-tree hash: {repo_root}")
    untracked = _git_untracked_paths(repo_root, pathspec)
    if untracked:
        sample = ", ".join(str(path) for path in untracked[:5])
        extra = "" if len(untracked) <= 5 else f" (+{len(untracked) - 5} more)"
        _die(f"bundled tracked tree contains untracked files and cannot be sealed: {sample}{extra}")
    digest = hashlib.sha256()
    digest.update(pathspec.encode("utf-8"))
    digest.update(b"\0")
    for rel_path in _iter_git_tracked_paths(repo_root, pathspec):
        absolute = repo_root / rel_path
        digest.update(rel_path.as_posix().encode("utf-8"))
        digest.update(b"\0")
        if not absolute.exists() and not absolute.is_symlink():
            digest.update(b"MISSING\0")
            continue
        if absolute.is_symlink():
            digest.update(b"L\0")
            digest.update(os.readlink(absolute).encode("utf-8"))
            digest.update(b"\0")
            continue
        if absolute.is_dir():
            digest.update(b"D\0")
            continue
        if not absolute.is_file():
            _die(f"tracked bundle input is missing: {absolute}")
        digest.update(b"F\0")
        digest.update(_hash_file(absolute).encode("utf-8"))
        digest.update(b"\0")
    return digest.hexdigest()


def _copy_tracked_tree(repo_root: Path, src_rel: str, dest_root: Path) -> None:
    untracked = _git_untracked_paths(repo_root, src_rel)
    if untracked:
        sample = ", ".join(str(path) for path in untracked[:5])
        extra = "" if len(untracked) <= 5 else f" (+{len(untracked) - 5} more)"
        _die(f"bundled tracked tree contains untracked files and cannot be sealed: {sample}{extra}")
    for rel_path in _iter_git_tracked_paths(repo_root, src_rel):
        source = repo_root / rel_path
        if not source.exists() and not source.is_symlink():
            continue
        _copy_path(source, dest_root / rel_path)


def _copy_repo_tracked_tree(repo_root: Path, src_rel: str, dest_root: Path) -> None:
    if not _git_ok(["git", "rev-parse", "--verify", "HEAD"], cwd=repo_root):
        _die(f"expected git checkout for bundled repo subtree: {repo_root}")
    if not _git_path_is_clean(repo_root, src_rel):
        _die(f"bundled repo subtree has local modifications and cannot be sealed: {repo_root}/{src_rel}")
    _copy_tracked_tree(repo_root, src_rel, dest_root)


def _copy_git_snapshot(src: Path, dest: Path) -> None:
    if _git_ok(["git", "rev-parse", "--verify", "HEAD"], cwd=src):
        untracked = _git_untracked_paths(src)
        if untracked:
            sample = ", ".join(str(path) for path in untracked[:5])
            extra = "" if len(untracked) <= 5 else f" (+{len(untracked) - 5} more)"
            _die(f"bundled repo snapshot contains untracked files and cannot be sealed: {sample}{extra}")
        if not _git_path_is_clean(src):
            _die(f"bundled repo snapshot has local modifications and cannot be sealed: {src}")
        shutil.rmtree(dest, ignore_errors=True)
        dest.mkdir(parents=True, exist_ok=True)
        archive = subprocess.Popen(
            ["git", "-C", str(src), "archive", "--format=tar", "HEAD"],
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
            _die(stderr_bytes.decode("utf-8", errors="replace").strip() or f"git archive failed for {src}")
        if extract.returncode != 0:
            _die(extract.stderr.decode("utf-8", errors="replace").strip() or f"failed to extract snapshot from {src}")
        if not dest.exists() or not any(dest.iterdir()):
            _die(f"bundled repo snapshot is empty: {src}")
        return
    _require_nonempty_dir(src, "bundled promoted snapshot dir")
    shutil.copytree(src, dest, symlinks=True, dirs_exist_ok=True)


def _readelf_output(binary: Path, *args: str) -> str:
    completed = subprocess.run(
        ["readelf", *args, str(binary)],
        check=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
        text=True,
    )
    if completed.returncode != 0:
        return ""
    return completed.stdout


def _sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def _hash_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def _hash_tree(path: Path) -> str:
    digest = hashlib.sha256()
    root = path.resolve()
    if not root.exists():
        _die(f"cache input path is missing: {root}")
    if root.is_symlink():
        digest.update(b"L\0")
        digest.update(os.readlink(root).encode("utf-8"))
        return digest.hexdigest()
    if root.is_file():
        digest.update(b"F\0")
        digest.update(root.name.encode("utf-8"))
        digest.update(b"\0")
        digest.update(_hash_file(root).encode("utf-8"))
        return digest.hexdigest()
    digest.update(b"D\0")
    for candidate in sorted(root.rglob("*")):
        rel = candidate.relative_to(root).as_posix().encode("utf-8")
        digest.update(rel)
        digest.update(b"\0")
        if candidate.is_symlink():
            digest.update(b"L\0")
            digest.update(os.readlink(candidate).encode("utf-8"))
            digest.update(b"\0")
            continue
        if candidate.is_dir():
            digest.update(b"D\0")
            continue
        digest.update(b"F\0")
        digest.update(_hash_file(candidate).encode("utf-8"))
        digest.update(b"\0")
    return digest.hexdigest()


def _git_head_revision(path: Path) -> str:
    completed = subprocess.run(
        ["git", "-C", str(path), "rev-parse", "HEAD"],
        check=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    if completed.returncode != 0:
        message = completed.stderr.strip() or f"failed to resolve git revision for {path}"
        _die(message)
    revision = completed.stdout.strip()
    if not revision:
        _die(f"empty git revision for {path}")
    return revision


def _binary_requires_runtime_loader(binary: Path) -> bool:
    return "Requesting program interpreter" in _readelf_output(binary, "-l")


def _materialize_library_soname_links(lib_dir: Path) -> None:
    if not lib_dir.is_dir():
        return
    for lib_path in lib_dir.iterdir():
        if not lib_path.is_file():
            continue
        soname = ""
        for line in _readelf_output(lib_path, "-d").splitlines():
            marker = "Library soname: ["
            if marker in line:
                soname = line.split(marker, 1)[1].split("]", 1)[0]
                break
        if soname and soname != lib_path.name:
            link_path = lib_dir / soname
            if link_path.exists() or link_path.is_symlink():
                link_path.unlink()
            os.symlink(lib_path.name, link_path)


def _stage_runtime_libs(binary: Path, dest_dir: Path) -> None:
    dest_dir.mkdir(parents=True, exist_ok=True)
    binary_dir = binary.parent.resolve()
    sibling_lib_dir = (binary_dir / ".." / "lib").resolve()
    sibling_lib64_dir = (binary_dir / ".." / "lib64").resolve()
    runtime_ld_path = [str(binary_dir)]
    if sibling_lib_dir.is_dir():
        runtime_ld_path.append(str(sibling_lib_dir))
    if sibling_lib64_dir.is_dir():
        runtime_ld_path.append(str(sibling_lib64_dir))
    env = os.environ.copy()
    env["LD_LIBRARY_PATH"] = ":".join(runtime_ld_path)
    completed = subprocess.run(
        ["ldd", str(binary)],
        env=env,
        check=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    output = completed.stdout
    if completed.returncode != 0:
        if "not a dynamic executable" in output or "statically linked" in output:
            return
        print(output, file=sys.stderr, end="" if output.endswith("\n") else "\n")
        _die(f"failed to inspect runtime libraries for {binary}")
    for line in output.splitlines():
        dep = ""
        if "=> not found" in line:
            missing = line.split("=>", 1)[0].strip()
            _die(f"missing runtime library for {binary}: {missing}")
        if "=>" in line:
            dep = line.split("=>", 1)[1].strip().split()[0]
        else:
            fields = line.strip().split()
            if fields and fields[0].startswith("/"):
                dep = fields[0]
        if not dep:
            continue
        dep_path = Path(dep)
        if dep_path.is_file():
            shutil.copy2(dep_path, dest_dir / dep_path.name, follow_symlinks=True)


def _write_portable_runtime_wrapper(wrapper_path: Path, loader_name: str) -> None:
    wrapper_path.write_text(
        f"""#!/usr/bin/env bash
set -euo pipefail
script_path="$(readlink -f "$0")"
real_binary="${{script_path}}.bin"
search_dir="$(cd "$(dirname "$script_path")" && pwd)"
bundle_root=""
while [[ "$search_dir" != "/" ]]; do
    if [[ -x "$search_dir/lib/{loader_name}" ]]; then
        bundle_root="$search_dir"
        break
    fi
    search_dir="$(dirname "$search_dir")"
done
[[ -n "$bundle_root" ]] || {{
    echo "portable runtime loader not found for $script_path" >&2
    exit 1
}}
script_dir="$(cd "$(dirname "$script_path")" && pwd)"
bundle_lib_path="$script_dir"
case_lib_dir="$script_dir/../lib"
case_lib64_dir="$script_dir/../lib64"
if [[ -d "$case_lib_dir" ]]; then
    bundle_lib_path="$bundle_lib_path:$case_lib_dir"
fi
if [[ -d "$case_lib64_dir" ]]; then
    bundle_lib_path="$bundle_lib_path:$case_lib64_dir"
fi
bundle_lib_path="$bundle_lib_path:$bundle_root/lib"
[[ -f "$real_binary" ]] || {{
    echo "wrapped binary is missing for $script_path: $real_binary" >&2
    exit 1
}}
exec "$bundle_root/lib/{loader_name}" --library-path "$bundle_lib_path" "$real_binary" "$@"
""",
        encoding="utf-8",
    )
    wrapper_path.chmod(0o755)


def _write_passthrough_wrapper(wrapper_path: Path) -> None:
    wrapper_path.write_text(
        """#!/usr/bin/env bash
set -euo pipefail
script_path="$(readlink -f "$0")"
real_binary="${script_path}.bin"
[[ -f "$real_binary" ]] || {
    echo "wrapped binary is missing for $script_path: $real_binary" >&2
    exit 1
}
exec "$real_binary" "$@"
""",
        encoding="utf-8",
    )
    wrapper_path.chmod(0o755)


def _iter_executable_files(root: Path) -> list[Path]:
    if not root.is_dir():
        return []
    results: list[Path] = []
    for path in root.rglob("*"):
        if not path.is_file() or path.is_symlink():
            continue
        mode = path.stat().st_mode
        if mode & stat.S_IXUSR:
            results.append(path)
    return results


def _wrap_dynamic_executable_tree(root: Path, loader_name: str, *, bundle_lib_dir: Path) -> None:
    if not root.is_dir():
        return
    bundle_lib_dir.mkdir(parents=True, exist_ok=True)
    for candidate in _iter_executable_files(root):
        if not _binary_requires_runtime_loader(candidate):
            continue
        _stage_runtime_libs(candidate, bundle_lib_dir)
        wrapped_binary = candidate.with_name(candidate.name + ".bin")
        candidate.rename(wrapped_binary)
        wrapped_binary.chmod(wrapped_binary.stat().st_mode & ~stat.S_IXUSR & ~stat.S_IXGRP & ~stat.S_IXOTH)
        _write_portable_runtime_wrapper(candidate, loader_name)
    _materialize_library_soname_links(bundle_lib_dir)


class BundleBuilder:
    def __init__(
        self,
        manifest_path: Path,
        bundle_inputs_path: Path,
        bundle_dir: Path | None = None,
        bundle_tar: Path | None = None,
    ) -> None:
        self.manifest_path = manifest_path
        self.bundle_inputs_path = bundle_inputs_path
        self.bundle_dir = bundle_dir
        self.bundle_tar = bundle_tar
        if not manifest_path.is_file():
            _die(f"manifest is missing: {manifest_path}")
        if not bundle_inputs_path.is_file():
            _die(f"bundle inputs are missing: {bundle_inputs_path}")
        self.manifest = _parse_scalar_manifest(manifest_path)
        self.bundle_inputs = read_state(bundle_inputs_path)
        self.values = {**self.manifest, **self.bundle_inputs}

    def _cache_manifest_values(self) -> dict[str, str]:
        return {
            key: value
            for key, value in self.manifest.items()
            if key not in _BUNDLE_CACHE_IGNORED_MANIFEST_KEYS
        }

    def value(self, key: str, default: str = "") -> str:
        return self.values.get(key, default)

    def required_value(self, key: str, description: str | None = None) -> str:
        value = self.value(key).strip()
        if value:
            return value
        label = description or key
        _die(f"{label} is missing")

    def target_arch_is_arm64(self) -> bool:
        return self.value("RUN_TARGET_ARCH") == "arm64"

    def target_arch_is_x86(self) -> bool:
        return self.value("RUN_TARGET_ARCH") == "x86_64"

    def executor_is_kvm(self) -> bool:
        return self.value("RUN_EXECUTOR") == "kvm"

    def test_mode_needs_unittest(self) -> bool:
        return self.value("RUN_TEST_MODE", "test") in {"selftest", "test"}

    def test_mode_needs_negative(self) -> bool:
        return self.value("RUN_TEST_MODE", "test") in {"selftest", "negative", "test"}

    def test_mode_needs_upstream(self) -> bool:
        return self.value("RUN_TEST_MODE", "test") == "test"

    def copy_tree(self, src: Path, dest: Path) -> None:
        _copy_path(src, dest)

    def copy_tracked_tree(self, src_rel: str, dest_root: Path) -> None:
        _copy_tracked_tree(ROOT_DIR, src_rel, dest_root)

    def copy_repo_tracked_tree(self, repo_root: Path, src_rel: str, dest_root: Path) -> None:
        _copy_repo_tracked_tree(repo_root, src_rel, dest_root)

    def copy_git_snapshot(self, src: Path, dest: Path) -> None:
        _copy_git_snapshot(src, dest)

    def _cache_path_inputs(self) -> list[tuple[str, Path]]:
        inputs: list[tuple[str, Path]] = []
        if self.value("RUN_NEEDS_RUNNER_BINARY", "0") == "1":
            if self.target_arch_is_arm64():
                inputs.extend(
                    [
                        ("arm64-cross-runner", Path(self.required_value("ARM64_CROSS_RUNNER", "ARM64 runner wrapper"))),
                        ("arm64-cross-runner-real", Path(self.required_value("ARM64_CROSS_RUNNER_REAL", "ARM64 runner binary"))),
                        ("arm64-cross-lib", Path(self.required_value("ARM64_CROSS_LIB_DIR", "ARM64 runtime lib dir"))),
                    ]
                )
            elif self.target_arch_is_x86():
                inputs.append(("x86-runner", Path(self.required_value("X86_RUNNER", "x86 runner binary"))))
        if self.value("RUN_NEEDS_DAEMON_BINARY", "0") == "1":
            if self.target_arch_is_arm64():
                inputs.extend(
                    [
                        ("arm64-cross-daemon", Path(self.required_value("ARM64_CROSS_DAEMON", "ARM64 daemon wrapper"))),
                        ("arm64-cross-daemon-real", Path(self.required_value("ARM64_CROSS_DAEMON_REAL", "ARM64 daemon binary"))),
                        ("arm64-cross-lib", Path(self.required_value("ARM64_CROSS_LIB_DIR", "ARM64 runtime lib dir"))),
                    ]
                )
            elif self.target_arch_is_x86():
                inputs.append(("x86-daemon", Path(self.required_value("X86_DAEMON", "x86 daemon binary"))))
        if self.value("RUN_NEEDS_KINSN_MODULES", "0") == "1":
            inputs.append(("kinsn-modules", Path(self.required_value("RUN_KINSN_MODULE_DIR", "selected kinsn module dir"))))
        scx_packages = [token for token in self.value("RUN_SCX_PACKAGES_CSV").split(",") if token]
        if scx_packages:
            if self.target_arch_is_arm64():
                inputs.extend(
                    [
                        ("arm64-scx-binaries", Path(self.required_value("ARM64_SCX_BINARY_ROOT", "manifest scx binary root"))),
                        ("arm64-scx-objects", Path(self.required_value("ARM64_SCX_OBJECT_ROOT", "manifest scx object root"))),
                    ]
                )
            elif self.target_arch_is_x86():
                inputs.extend(
                    [
                        ("x86-scx-binaries", Path(self.required_value("X86_SCX_BINARY_ROOT", "manifest scx binary root"))),
                        ("x86-scx-objects", Path(self.required_value("X86_SCX_OBJECT_ROOT", "manifest scx object root"))),
                    ]
                )
        bundled_repos = [token for token in self.value("RUN_BUNDLED_REPOS_CSV").split(",") if token]
        if bundled_repos:
            repo_root = Path(self.required_value("RUN_LOCAL_REPO_ROOT", "local repo root"))
            for repo in bundled_repos:
                inputs.append((f"bundled-repo:{repo}", repo_root / repo))
        bundled_tools = self.value("RUN_BUNDLED_WORKLOAD_TOOLS_CSV")
        if bundled_tools:
            inputs.append(("bundled-workload-tools", Path(self.required_value("RUN_LOCAL_WORKLOAD_TOOL_ROOT", "local bundled workload tool root"))))
        if self.target_arch_is_x86() and self.value("X86_PORTABLE_LIBBPF_ROOT"):
            inputs.append(("x86-portable-libbpf", Path(self.value("X86_PORTABLE_LIBBPF_ROOT"))))
        native_repos = [token for token in self.value("RUN_NATIVE_REPOS_CSV").split(",") if token]
        if native_repos:
            root_key = "ARM64_NATIVE_BUILD_ROOT" if self.target_arch_is_arm64() else "X86_NATIVE_BUILD_ROOT"
            native_root = Path(self.required_value(root_key, root_key))
            for repo in native_repos:
                inputs.append((f"native-repo:{repo}", native_root / repo))
        suite = self.value("RUN_SUITE_NAME")
        if suite == "test":
            if self.target_arch_is_arm64():
                if self.test_mode_needs_unittest():
                    inputs.append(("arm64-test-unittest", Path(self.required_value("ARM64_TEST_UNITTEST_BUILD_DIR", "bundled ARM64 unittest inputs"))))
                if self.test_mode_needs_negative():
                    inputs.append(("arm64-test-negative", Path(self.required_value("ARM64_TEST_NEGATIVE_BUILD_DIR", "bundled ARM64 negative inputs"))))
                if self.test_mode_needs_upstream():
                    inputs.append(("arm64-upstream-selftests", Path(self.required_value("ARM64_UPSTREAM_SELFTEST_DIR", "bundled ARM64 upstream selftest inputs"))))
                    inputs.append(("arm64-upstream-kmods", Path(self.required_value("ARM64_UPSTREAM_TEST_KMODS_DIR", "bundled ARM64 upstream selftest kmods"))))
            else:
                if self.test_mode_needs_unittest():
                    inputs.append(("x86-test-unittest", Path(self.required_value("X86_TEST_UNITTEST_BUILD_DIR", "bundled x86 unittest inputs"))))
                if self.test_mode_needs_negative():
                    inputs.append(("x86-test-negative", Path(self.required_value("X86_TEST_NEGATIVE_BUILD_DIR", "bundled x86 negative inputs"))))
                if self.test_mode_needs_upstream():
                    inputs.append(("x86-upstream-selftests", Path(self.required_value("X86_UPSTREAM_SELFTEST_DIR", "x86 upstream selftest dir"))))
        elif suite == "micro":
            inputs.append(("micro-programs", Path(self.required_value("MICRO_PROGRAMS_GENERATED_DIR", "micro generated programs dir"))))
        if self.executor_is_kvm() and self.target_arch_is_x86():
            inputs.append(("kvm-virtme-mods", ROOT_DIR / "vendor/linux-framework/.virtme_mods"))
        deduped: list[tuple[str, Path]] = []
        seen: set[tuple[str, str]] = set()
        for label, path in inputs:
            key = (label, str(path.resolve()))
            if key in seen:
                continue
            seen.add(key)
            deduped.append((label, path.resolve()))
        return deduped

    def compute_cache_key(self) -> str:
        payload = {
            "version": 2,
            "manifest": self._cache_manifest_values(),
            "bundle_inputs": {},
            "source_revisions": {
                "vendor_libbpf": _git_head_revision(ROOT_DIR / "vendor/libbpf"),
                "vendor_bpftool": _git_head_revision(ROOT_DIR / "vendor/bpftool"),
            },
            "path_inputs": [],
            "tracked_tree_inputs": [],
        }
        for key, value in sorted(self.bundle_inputs.items()):
            candidate = Path(value)
            if candidate.is_absolute() and candidate.exists():
                payload["bundle_inputs"][key] = {"path_tree_sha256": _hash_tree(candidate)}
            else:
                payload["bundle_inputs"][key] = {"scalar": value}
        for label, path in self._cache_path_inputs():
            payload["path_inputs"].append({"label": label, "tree_sha256": _hash_tree(path)})
        for label, repo_root, pathspec in self._cache_tracked_tree_inputs():
            payload["tracked_tree_inputs"].append(
                {
                    "label": label,
                    "repo_root": str(repo_root),
                    "pathspec": pathspec,
                    "tree_sha256": _hash_git_tracked_tree(repo_root, pathspec),
                }
            )
        encoded = json.dumps(payload, sort_keys=True, separators=(",", ":")).encode("utf-8")
        return _sha256_bytes(encoded)

    def _cache_tracked_tree_inputs(self) -> list[tuple[str, Path, str]]:
        suite = self.value("RUN_SUITE_NAME")
        inputs: list[tuple[str, Path, str]] = [
            ("runner-init", ROOT_DIR, "runner/__init__.py"),
            ("runner-cmake", ROOT_DIR, "runner/CMakeLists.txt"),
            ("runner-include", ROOT_DIR, "runner/include"),
            ("runner-repos-yaml", ROOT_DIR, "runner/repos.yaml"),
            ("runner-libs", ROOT_DIR, "runner/libs"),
            ("runner-src", ROOT_DIR, "runner/src"),
            ("vendor-linux-include", ROOT_DIR / "vendor/linux-framework", "include"),
            ("vendor-linux-scripts", ROOT_DIR / "vendor/linux-framework", "scripts"),
            ("vendor-linux-arch", ROOT_DIR / "vendor/linux-framework", "arch"),
        ]
        if self.value("RUN_NEEDS_KINSN_MODULES", "0") == "1":
            inputs.append(("module-tree", ROOT_DIR, "module"))
        if suite == "test":
            inputs.append(("tests-tree", ROOT_DIR, "tests"))
            if self.test_mode_needs_upstream():
                inputs.extend(
                    [
                        ("runner-config", ROOT_DIR, "runner/config"),
                        ("vendor-linux-tools-build", ROOT_DIR / "vendor/linux-framework", "tools/build"),
                        ("vendor-linux-tools-bpf", ROOT_DIR / "vendor/linux-framework", "tools/bpf"),
                        ("vendor-linux-tools-include", ROOT_DIR / "vendor/linux-framework", "tools/include"),
                        ("vendor-linux-tools-lib", ROOT_DIR / "vendor/linux-framework", "tools/lib"),
                        ("vendor-linux-tools-scripts", ROOT_DIR / "vendor/linux-framework", "tools/scripts"),
                        ("vendor-linux-tools-testing", ROOT_DIR / "vendor/linux-framework", "tools/testing"),
                        ("vendor-linux-disasm-c", ROOT_DIR / "vendor/linux-framework", "kernel/bpf/disasm.c"),
                        ("vendor-linux-disasm-h", ROOT_DIR / "vendor/linux-framework", "kernel/bpf/disasm.h"),
                    ]
                )
        elif suite == "micro":
            inputs.append(("micro-tree", ROOT_DIR, "micro"))
        elif suite == "corpus":
            inputs.extend(
                [
                    ("corpus-tree", ROOT_DIR, "corpus"),
                    ("e2e-cases-tree", ROOT_DIR, "e2e/cases"),
                ]
            )
        elif suite == "e2e":
            inputs.extend(
                [
                    ("e2e-tree", ROOT_DIR, "e2e"),
                    ("corpus-config-tree", ROOT_DIR, "corpus/config"),
                    ("corpus-inputs-tree", ROOT_DIR, "corpus/inputs"),
                ]
            )
        return inputs

    def copy_runner_tree(self) -> None:
        for rel in (
            "runner/__init__.py",
            "runner/CMakeLists.txt",
            "runner/include",
            "runner/repos.yaml",
            "runner/libs",
            "runner/src",
        ):
            self.copy_tracked_tree(rel, self.bundle_dir)
        for stale in (
            self.bundle_dir / "runner/__pycache__",
            self.bundle_dir / "runner/scripts/__pycache__",
            self.bundle_dir / "runner/libs/__pycache__",
            self.bundle_dir / "runner/libs/app_runners/__pycache__",
        ):
            if stale.exists():
                shutil.rmtree(stale)

    def copy_test_runner_tree(self) -> None:
        if self.test_mode_needs_upstream():
            self.copy_tracked_tree("runner/config", self.bundle_dir)

    def stage_target_runtime(self) -> None:
        needs_runner = self.value("RUN_NEEDS_RUNNER_BINARY", "0") == "1"
        needs_daemon = self.value("RUN_NEEDS_DAEMON_BINARY", "0") == "1"
        if not (needs_runner or needs_daemon):
            return
        lib_dir = self.bundle_dir / "lib"
        lib_dir.mkdir(parents=True, exist_ok=True)
        if needs_runner:
            (self.bundle_dir / "runner/build").mkdir(parents=True, exist_ok=True)
        if needs_daemon:
            (self.bundle_dir / "daemon/build").mkdir(parents=True, exist_ok=True)
            (self.bundle_dir / "daemon/target/release").mkdir(parents=True, exist_ok=True)
        if self.target_arch_is_arm64():
            if needs_runner:
                runner_wrapper = Path(self.required_value("ARM64_CROSS_RUNNER", "ARM64 runner wrapper"))
                runner_real = Path(self.required_value("ARM64_CROSS_RUNNER_REAL", "ARM64 runner binary"))
                _require_path(runner_wrapper, "ARM64 runner wrapper")
                _require_path(runner_real, "ARM64 runner binary")
                shutil.copy2(runner_wrapper, self.bundle_dir / "runner/build/micro_exec")
                shutil.copy2(runner_real, self.bundle_dir / "runner/build/micro_exec.real")
            if needs_runner or needs_daemon:
                runtime_lib_dir = Path(self.required_value("ARM64_CROSS_LIB_DIR", "ARM64 runtime lib dir"))
                _require_path(runtime_lib_dir, "ARM64 runtime lib dir")
                shutil.copytree(runtime_lib_dir, lib_dir, symlinks=True, dirs_exist_ok=True)
                _materialize_library_soname_links(lib_dir)
            if needs_daemon:
                daemon_wrapper = Path(self.required_value("ARM64_CROSS_DAEMON", "ARM64 daemon wrapper"))
                daemon_real = Path(self.required_value("ARM64_CROSS_DAEMON_REAL", "ARM64 daemon binary"))
                _require_path(daemon_wrapper, "ARM64 daemon wrapper")
                _require_path(daemon_real, "ARM64 daemon binary")
                shutil.copy2(daemon_wrapper, self.bundle_dir / "daemon/build/bpfrejit-daemon")
                shutil.copy2(daemon_real, self.bundle_dir / "daemon/build/bpfrejit-daemon.real")
                shutil.copy2(daemon_wrapper, self.bundle_dir / "daemon/target/release/bpfrejit-daemon")
                shutil.copy2(daemon_real, self.bundle_dir / "daemon/target/release/bpfrejit-daemon.real")
            return
        if self.target_arch_is_x86():
            if needs_runner:
                runner_binary = Path(self.required_value("X86_RUNNER", "x86 runner binary"))
                _require_path(runner_binary, "x86 runner binary")
                staged_runner = self.bundle_dir / "runner/build/micro_exec.bin"
                shutil.copy2(runner_binary, staged_runner)
                staged_runner.chmod(staged_runner.stat().st_mode & ~stat.S_IXUSR & ~stat.S_IXGRP & ~stat.S_IXOTH)
                _stage_runtime_libs(runner_binary, lib_dir)
                if _binary_requires_runtime_loader(runner_binary):
                    _write_portable_runtime_wrapper(self.bundle_dir / "runner/build/micro_exec", "ld-linux-x86-64.so.2")
                else:
                    _write_passthrough_wrapper(self.bundle_dir / "runner/build/micro_exec")
            if needs_daemon:
                daemon_binary = Path(self.required_value("X86_DAEMON", "x86 daemon binary"))
                _require_path(daemon_binary, "x86 daemon binary")
                staged_daemon = self.bundle_dir / "daemon/target/release/bpfrejit-daemon.bin"
                shutil.copy2(daemon_binary, staged_daemon)
                staged_daemon.chmod(staged_daemon.stat().st_mode & ~stat.S_IXUSR & ~stat.S_IXGRP & ~stat.S_IXOTH)
                _stage_runtime_libs(daemon_binary, lib_dir)
                if _binary_requires_runtime_loader(daemon_binary):
                    _write_portable_runtime_wrapper(self.bundle_dir / "daemon/target/release/bpfrejit-daemon", "ld-linux-x86-64.so.2")
                else:
                    _write_passthrough_wrapper(self.bundle_dir / "daemon/target/release/bpfrejit-daemon")
            _materialize_library_soname_links(lib_dir)
            return
        _die(f"unsupported remote target arch: {self.value('RUN_TARGET_ARCH')}")

    def stage_modules(self) -> None:
        if self.value("RUN_NEEDS_KINSN_MODULES", "0") != "1":
            return
        self.copy_tracked_tree("module", self.bundle_dir)
        if self.target_arch_is_arm64():
            module_subdir = "arm64"
            shutil.rmtree(self.bundle_dir / "module/x86", ignore_errors=True)
            shutil.rmtree(self.bundle_dir / "module/arm64", ignore_errors=True)
        elif self.target_arch_is_x86():
            module_subdir = "x86"
            shutil.rmtree(self.bundle_dir / "module/arm64", ignore_errors=True)
            shutil.rmtree(self.bundle_dir / "module/x86", ignore_errors=True)
        else:
            _die(f"unsupported target arch for bundled modules: {self.value('RUN_TARGET_ARCH')}")
        module_dir = Path(self.required_value("RUN_KINSN_MODULE_DIR", "selected kinsn module dir"))
        _require_path(module_dir, "selected kinsn module dir")
        self.copy_tree(module_dir, self.bundle_dir / f"module/{module_subdir}")

    def stage_scx(self) -> None:
        packages = [token for token in self.value("RUN_SCX_PACKAGES_CSV").split(",") if token]
        if not packages:
            return
        binary_root = Path(
            self.required_value(
                "ARM64_SCX_BINARY_ROOT" if self.target_arch_is_arm64() else "X86_SCX_BINARY_ROOT",
                "manifest scx binary root",
            )
        )
        object_root = Path(
            self.required_value(
                "ARM64_SCX_OBJECT_ROOT" if self.target_arch_is_arm64() else "X86_SCX_OBJECT_ROOT",
                "manifest scx object root",
            )
        )
        release_dir = self.bundle_dir / "runner/repos/scx/target/release"
        object_dir = self.bundle_dir / "corpus/build/scx"
        release_dir.mkdir(parents=True, exist_ok=True)
        object_dir.mkdir(parents=True, exist_ok=True)
        for package in packages:
            destination = release_dir / package
            shutil.copy2(binary_root / package, destination)
            shutil.copy2(object_root / f"{package}_main.bpf.o", object_dir / f"{package}_main.bpf.o")
        if self.target_arch_is_x86():
            _wrap_dynamic_executable_tree(release_dir, "ld-linux-x86-64.so.2", bundle_lib_dir=self.bundle_dir / "lib")
            return
        if self.target_arch_is_arm64():
            for package in packages:
                candidate = release_dir / package
                wrapped_binary = candidate.with_name(candidate.name + ".bin")
                candidate.rename(wrapped_binary)
                wrapped_binary.chmod(wrapped_binary.stat().st_mode & ~stat.S_IXUSR & ~stat.S_IXGRP & ~stat.S_IXOTH)
                _write_portable_runtime_wrapper(candidate, "ld-linux-aarch64.so.1")

    def stage_repo_build_dir(self, repo_name: str) -> None:
        root_key = "ARM64_NATIVE_BUILD_ROOT" if self.target_arch_is_arm64() else "X86_NATIVE_BUILD_ROOT"
        source_dir = Path(self.required_value(root_key, f"{root_key}")) / repo_name
        _require_nonempty_dir(source_dir, f"bundled native repo build dir for {repo_name}")
        dest = self.bundle_dir / f"corpus/build/{repo_name}"
        shutil.copytree(source_dir, dest, symlinks=True, dirs_exist_ok=True)
        lib_dir = dest / "lib"
        if lib_dir.is_dir():
            _materialize_library_soname_links(lib_dir)

    def remove_tracked_katran_runtime_tree(self) -> None:
        for stale in (
            self.bundle_dir / "e2e/cases/katran/bin",
            self.bundle_dir / "e2e/cases/katran/lib",
        ):
            if stale.exists():
                shutil.rmtree(stale, ignore_errors=True)

    def stage_selected_repos(self) -> None:
        repos = [token for token in self.value("RUN_BUNDLED_REPOS_CSV").split(",") if token]
        if not repos:
            return
        repo_root = Path(self.required_value("RUN_LOCAL_REPO_ROOT", "local repo root"))
        for repo in repos:
            self.copy_git_snapshot(repo_root / repo, self.bundle_dir / f"runner/repos/{repo}")

    def stage_workload_tools(self) -> None:
        if not self.value("RUN_BUNDLED_WORKLOAD_TOOLS_CSV"):
            return
        root = Path(self.required_value("RUN_LOCAL_WORKLOAD_TOOL_ROOT", "local bundled workload tool root"))
        _require_nonempty_dir(root / "bin", "bundled workload tool bin dir")
        dest = self.bundle_dir / ".cache/workload-tools"
        shutil.copytree(root, dest, symlinks=True, dirs_exist_ok=True)
        if self.target_arch_is_x86():
            _wrap_dynamic_executable_tree(dest / "bin", "ld-linux-x86-64.so.2", bundle_lib_dir=self.bundle_dir / "lib")

    def stage_x86_portable_libbpf(self) -> None:
        if not self.target_arch_is_x86():
            return
        root = self.value("X86_PORTABLE_LIBBPF_ROOT")
        if not root:
            return
        lib_dir = Path(root) / "lib"
        _require_nonempty_dir(lib_dir, "portable x86 libbpf dir")
        shutil.copytree(lib_dir, self.bundle_dir / ".cache/portable-libbpf/lib", symlinks=True, dirs_exist_ok=True)

    def stage_native_repo_build_dirs(self) -> None:
        repos = [token for token in self.value("RUN_NATIVE_REPOS_CSV").split(",") if token]
        for repo in repos:
            self.stage_repo_build_dir(repo)
            if self.target_arch_is_x86():
                _wrap_dynamic_executable_tree(
                    self.bundle_dir / f"corpus/build/{repo}",
                    "ld-linux-x86-64.so.2",
                    bundle_lib_dir=self.bundle_dir / "lib",
                )

    def write_bundle_manifest(self) -> None:
        manifest = parse_manifest(self.manifest_path)
        manifest["RUN_BUNDLED_WORKLOAD_TOOLS_CSV"] = self.value("RUN_BUNDLED_WORKLOAD_TOOLS_CSV", "")
        if self.value("RUN_BUNDLED_WORKLOAD_TOOLS_CSV"):
            manifest["RUN_REMOTE_WORKLOAD_TOOL_BIN"] = ".cache/workload-tools/bin"
        else:
            manifest.pop("RUN_REMOTE_WORKLOAD_TOOL_BIN", None)
        if "bcc" in [token for token in self.value("RUN_NATIVE_REPOS_CSV").split(",") if token]:
            manifest["RUN_BCC_TOOLS_DIR"] = "corpus/build/bcc/libbpf-tools/.output"
        if self.value("RUN_NEEDS_KATRAN_BUNDLE", "0") == "1":
            manifest["RUN_KATRAN_SERVER_BINARY"] = "corpus/build/katran/bin/katran_server_grpc"
            manifest["RUN_KATRAN_SERVER_LIB_DIR"] = "corpus/build/katran/lib"
        rendered = render_shell_assignments_from_mapping(manifest)
        (self.bundle_dir / "run-contract.env").write_text(rendered + "\n", encoding="utf-8")

    def stage_kvm_kernel_module_tree(self) -> None:
        if not (self.executor_is_kvm() and self.target_arch_is_x86()):
            return
        source = ROOT_DIR / "vendor" / "linux-framework" / ".virtme_mods"
        _require_nonempty_dir(source, "x86 KVM kernel module tree")
        self.copy_tree(source, self.bundle_dir / "vendor/linux-framework/.virtme_mods")

    def prepare_common_bundle(self) -> None:
        shutil.rmtree(self.bundle_dir, ignore_errors=True)
        self.bundle_dir.mkdir(parents=True, exist_ok=True)
        self.write_bundle_manifest()
        self.copy_runner_tree()
        self.stage_modules()
        self.stage_target_runtime()
        self.copy_git_snapshot(ROOT_DIR / "vendor/libbpf", self.bundle_dir / "vendor/libbpf")
        self.copy_git_snapshot(ROOT_DIR / "vendor/bpftool", self.bundle_dir / "vendor/bpftool")
        for rel in ("include", "scripts", "arch"):
            self.copy_repo_tracked_tree(ROOT_DIR / "vendor/linux-framework", rel, self.bundle_dir / "vendor/linux-framework")
        self.stage_kvm_kernel_module_tree()

    def prepare_test_bundle(self) -> None:
        self.copy_test_runner_tree()
        self.copy_tracked_tree("tests", self.bundle_dir)
        if self.target_arch_is_arm64():
            if self.test_mode_needs_unittest():
                unittest_dir = Path(self.required_value("ARM64_TEST_UNITTEST_BUILD_DIR", "bundled ARM64 unittest inputs"))
                _require_path(unittest_dir, "bundled ARM64 unittest inputs")
                self.copy_tree(unittest_dir, self.bundle_dir / "tests/unittest/build-arm64")
            if self.test_mode_needs_negative():
                negative_dir = Path(self.required_value("ARM64_TEST_NEGATIVE_BUILD_DIR", "bundled ARM64 negative inputs"))
                _require_path(negative_dir, "bundled ARM64 negative inputs")
                self.copy_tree(negative_dir, self.bundle_dir / "tests/negative/build-arm64")
            if self.test_mode_needs_upstream():
                selftest_dir = Path(self.required_value("ARM64_UPSTREAM_SELFTEST_DIR", "bundled ARM64 upstream selftest inputs"))
                kmods_dir = Path(self.required_value("ARM64_UPSTREAM_TEST_KMODS_DIR", "bundled ARM64 upstream selftest kmods"))
                _require_path(selftest_dir, "bundled ARM64 upstream selftest inputs")
                _require_path(kmods_dir, "bundled ARM64 upstream selftest kmods")
                self.copy_tree(selftest_dir, self.bundle_dir / ".cache/upstream-bpf-selftests")
                kmod_dest = self.bundle_dir / "upstream-selftests-kmods"
                kmod_dest.mkdir(parents=True, exist_ok=True)
                for ko in kmods_dir.glob("*.ko"):
                    shutil.copy2(ko, kmod_dest / ko.name)
        else:
            if self.test_mode_needs_unittest():
                unittest_dir = Path(self.required_value("X86_TEST_UNITTEST_BUILD_DIR", "bundled x86 unittest inputs"))
                _require_path(unittest_dir, "bundled x86 unittest inputs")
                self.copy_tree(unittest_dir, self.bundle_dir / "tests/unittest/build")
                _wrap_dynamic_executable_tree(self.bundle_dir / "tests/unittest/build", "ld-linux-x86-64.so.2", bundle_lib_dir=self.bundle_dir / "lib")
            if self.test_mode_needs_negative():
                negative_dir = Path(self.required_value("X86_TEST_NEGATIVE_BUILD_DIR", "bundled x86 negative inputs"))
                _require_path(negative_dir, "bundled x86 negative inputs")
                self.copy_tree(negative_dir, self.bundle_dir / "tests/negative/build")
                _wrap_dynamic_executable_tree(self.bundle_dir / "tests/negative/build", "ld-linux-x86-64.so.2", bundle_lib_dir=self.bundle_dir / "lib")
            if self.test_mode_needs_upstream():
                selftest_dir = Path(self.required_value("X86_UPSTREAM_SELFTEST_DIR", "x86 upstream selftest dir"))
                _require_path(selftest_dir, "x86 upstream selftest dir")
                self.copy_tree(selftest_dir, self.bundle_dir / ".cache/upstream-bpf-selftests")
                _wrap_dynamic_executable_tree(self.bundle_dir / ".cache/upstream-bpf-selftests", "ld-linux-x86-64.so.2", bundle_lib_dir=self.bundle_dir / "lib")
        if self.test_mode_needs_upstream():
            for rel in (
                "tools/build",
                "tools/bpf",
                "tools/include",
                "tools/lib",
                "tools/scripts",
                "tools/testing",
                "kernel/bpf/disasm.c",
                "kernel/bpf/disasm.h",
            ):
                self.copy_repo_tracked_tree(ROOT_DIR / "vendor/linux-framework", rel, self.bundle_dir / "vendor/linux-framework")
        self.stage_scx()

    def prepare_micro_bundle(self) -> None:
        self.copy_tracked_tree("micro", self.bundle_dir)
        shutil.rmtree(self.bundle_dir / "micro/results", ignore_errors=True)
        generated_dir = Path(self.required_value("MICRO_PROGRAMS_GENERATED_DIR", "micro generated programs dir"))
        _require_nonempty_dir(generated_dir, "micro generated programs dir")
        programs_dir = self.bundle_dir / "micro/programs"
        programs_dir.mkdir(parents=True, exist_ok=True)
        for generated_file in generated_dir.iterdir():
            if generated_file.is_file() and (
                generated_file.name.endswith(".bpf.o")
                or generated_file.name.endswith(".directive.bin")
                or generated_file.name.endswith(".policy.bin")
                or generated_file.name == ".build.stamp"
            ):
                shutil.copy2(generated_file, programs_dir / generated_file.name)

    def prepare_corpus_bundle(self) -> None:
        self.copy_tracked_tree("corpus", self.bundle_dir)
        self.copy_tracked_tree("e2e/cases", self.bundle_dir)
        self.remove_tracked_katran_runtime_tree()
        shutil.rmtree(self.bundle_dir / "corpus/results", ignore_errors=True)
        shutil.rmtree(self.bundle_dir / "corpus/build", ignore_errors=True)
        (self.bundle_dir / "corpus/build").mkdir(parents=True, exist_ok=True)
        self.stage_workload_tools()
        self.stage_x86_portable_libbpf()
        self.stage_selected_repos()
        self.stage_scx()
        self.stage_native_repo_build_dirs()

    def prepare_e2e_bundle(self) -> None:
        self.copy_tracked_tree("e2e", self.bundle_dir)
        self.remove_tracked_katran_runtime_tree()
        shutil.rmtree(self.bundle_dir / "e2e/results", ignore_errors=True)
        self.copy_tracked_tree("corpus/config", self.bundle_dir)
        self.copy_tracked_tree("corpus/inputs", self.bundle_dir)
        (self.bundle_dir / "corpus/build").mkdir(parents=True, exist_ok=True)
        self.stage_workload_tools()
        self.stage_x86_portable_libbpf()
        self.stage_selected_repos()
        self.stage_scx()
        self.stage_native_repo_build_dirs()

    def archive_bundle(self) -> None:
        if self.bundle_tar is None or self.bundle_dir is None:
            _die("bundle builder archive requires an explicit bundle_dir and bundle_tar")
        self.bundle_tar.parent.mkdir(parents=True, exist_ok=True)
        with tarfile.open(self.bundle_tar, "w:gz") as archive:
            for child in sorted(self.bundle_dir.iterdir()):
                archive.add(child, arcname=child.name, recursive=True)

    def build(self) -> None:
        if self.bundle_dir is None or self.bundle_tar is None:
            _die("bundle builder build requires an explicit bundle_dir and bundle_tar")
        self.prepare_common_bundle()
        suite = self.value("RUN_SUITE_NAME")
        if suite == "test":
            self.prepare_test_bundle()
        elif suite == "micro":
            self.prepare_micro_bundle()
        elif suite == "corpus":
            self.prepare_corpus_bundle()
        elif suite == "e2e":
            self.prepare_e2e_bundle()
        else:
            _die(f"unsupported suite for remote bundle: {suite}")
        self.archive_bundle()


def compute_bundle_cache_key(manifest_path: Path, bundle_inputs_path: Path) -> str:
    return BundleBuilder(manifest_path, bundle_inputs_path).compute_cache_key()


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 4:
        _die("usage: build_remote_bundle.py <manifest_path> <bundle_inputs_path> <bundle_dir> <bundle_tar>")
    builder = BundleBuilder(
        manifest_path=Path(args[0]).resolve(),
        bundle_inputs_path=Path(args[1]).resolve(),
        bundle_dir=Path(args[2]).resolve(),
        bundle_tar=Path(args[3]).resolve(),
    )
    builder.build()


if __name__ == "__main__":
    main()
