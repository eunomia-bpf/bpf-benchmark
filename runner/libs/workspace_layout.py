from __future__ import annotations

import os
from pathlib import Path

from runner.libs import ROOT_DIR


_BASE_TRANSFER_ROOTS = {
    "test":   ("runner/__init__.py", "runner/libs", "runner/suites", "tests"),
    "micro":  ("runner/__init__.py", "runner/libs", "runner/suites", "micro/driver.py", "micro/catalog.py", "micro/config", "micro/generated-inputs"),
    "corpus": ("runner/__init__.py", "runner/libs", "runner/suites", "corpus/driver.py", "corpus/config", "corpus/inputs", "e2e/cases"),
    "e2e":    ("runner/__init__.py", "runner/libs", "runner/suites", "corpus/config", "corpus/inputs", "e2e/driver.py", "e2e/cases"),
}

_TRANSFER_ROOT_ORDER = ("runner", "module", "tests", "micro", "corpus", "e2e")
RUNTIME_IMAGE_ROOT = Path("/opt/bpf-benchmark")

# (arm64_parts, x86_parts)
_ARCH_PATHS: dict[str, tuple[tuple[str, ...], tuple[str, ...]]] = {
    "daemon_binary_path":      (("daemon", "target", "aarch64-unknown-linux-gnu", "release", "bpfrejit-daemon"), ("daemon", "target", "release", "bpfrejit-daemon")),
    "runner_binary_path":      (("runner", "build-arm64-llvmbpf", "micro_exec"), ("runner", "build-llvmbpf", "micro_exec")),
    "test_unittest_build_dir": (("tests", "unittest", "build-arm64"), ("tests", "unittest", "build")),
    "test_negative_build_dir": (("tests", "negative", "build-arm64"), ("tests", "negative", "build")),
}


def _is_arm64(target_arch: str) -> bool:
    return str(target_arch).strip() == "arm64"

def _p(workspace: Path, target_arch: str, key: str) -> Path:
    arm64, x86 = _ARCH_PATHS[key]
    return workspace.joinpath(*(arm64 if _is_arm64(target_arch) else x86))

def _cache(workspace: Path, target_arch: str, subdir: str) -> Path:
    return workspace / ".cache" / subdir / str(target_arch).strip()


def repo_artifact_root(workspace: Path, target_arch: str) -> Path:       return _cache(workspace, target_arch, "repo-artifacts")
def workload_tools_root(workspace: Path, target_arch: str) -> Path:      return _cache(workspace, target_arch, "workload-tools")
def test_unittest_build_dir(workspace: Path, target_arch: str) -> Path:  return _p(workspace, target_arch, "test_unittest_build_dir")
def test_negative_build_dir(workspace: Path, target_arch: str) -> Path:  return _p(workspace, target_arch, "test_negative_build_dir")

def inside_runtime_image() -> bool:
    return os.environ.get("BPFREJIT_INSIDE_RUNTIME_CONTAINER", "").strip() == "1"

def micro_program_root(workspace: Path, target_arch: str) -> Path:
    return RUNTIME_IMAGE_ROOT / "micro-programs" if inside_runtime_image() else _cache(workspace, target_arch, "micro-programs")

def daemon_binary_path(workspace: Path, target_arch: str) -> Path:
    return RUNTIME_IMAGE_ROOT / "bin" / "bpfrejit-daemon" if inside_runtime_image() else _p(workspace, target_arch, "daemon_binary_path")

def runner_binary_path(workspace: Path, target_arch: str) -> Path:
    return RUNTIME_IMAGE_ROOT / "bin" / "micro_exec" if inside_runtime_image() else _p(workspace, target_arch, "runner_binary_path")

def runtime_repo_artifact_root(workspace: Path, target_arch: str) -> Path:
    return RUNTIME_IMAGE_ROOT / "repo-artifacts" if inside_runtime_image() else repo_artifact_root(workspace, target_arch)

def runtime_workload_tools_root(workspace: Path, target_arch: str) -> Path:
    return RUNTIME_IMAGE_ROOT / "workload-tools" if inside_runtime_image() else workload_tools_root(workspace, target_arch)

def runtime_container_image_tar_path(workspace: Path, target_arch: str) -> Path:
    return workspace / ".cache" / "container-images" / f"{str(target_arch).strip()}-runner-runtime.image.tar"

def kinsn_module_dir(workspace: Path, target_arch: str, target_name: str = "") -> Path:
    if str(target_name).strip() == "aws-x86":
        return workspace / ".cache" / "aws-x86" / "module" / "x86"
    return workspace / "module" / ("arm64" if _is_arm64(target_arch) else "x86")

def kernel_modules_root(workspace: Path, target_arch: str, executor: str) -> Path:
    del target_arch
    return repo_artifact_root(workspace, "x86_64") / "kernel-modules" if str(executor).strip() == "kvm" else Path("/")

def kvm_kernel_image_path(workspace: Path) -> Path:
    return workspace / ".cache" / "x86-kernel-build" / "arch" / "x86" / "boot" / "bzImage"


def runtime_path_value(workspace: Path, target_arch: str) -> str:
    path_entries: list[str] = []
    arch = str(target_arch).strip()
    if arch:
        candidates: list[Path] = []
        if inside_runtime_image():
            candidates.append(RUNTIME_IMAGE_ROOT / "bin")
        candidates.extend([
            runtime_repo_artifact_root(workspace, arch) / "bpftrace" / "bin",
            runtime_workload_tools_root(workspace, arch) / "bin",
        ])
        path_entries.extend(str(path) for path in candidates if path.is_dir())
    for standard_dir in ("/usr/local/sbin", "/usr/local/bin", "/usr/sbin", "/usr/bin", "/sbin", "/bin"):
        if standard_dir not in path_entries:
            path_entries.append(standard_dir)
    return ":".join(path_entries)


def kinsn_targets(workspace: Path, target_arch: str, target_name: str = "") -> list[Path]:
    root = kinsn_module_dir(workspace, target_arch, target_name)
    names = ["bpf_rotate.ko", "bpf_select.ko", "bpf_extract.ko", "bpf_endian.ko", "bpf_bulk_memory.ko"]
    if _is_arm64(target_arch):
        names.insert(4, "bpf_ldp.ko")
    return [root / n for n in names]

def _base_transfer_paths(workspace: Path, suite_name: str) -> list[Path]:
    return [workspace / e for e in _BASE_TRANSFER_ROOTS.get(str(suite_name).strip(), ())]

def _artifact_transfer_paths(*, workspace, suite_name, target_arch, needs_kinsn_modules) -> list[Path]:
    arch, suite = str(target_arch).strip(), str(suite_name).strip()
    paths: list[Path] = []
    if suite in _BASE_TRANSFER_ROOTS:       paths.append(runtime_container_image_tar_path(workspace, arch))
    if needs_kinsn_modules:                 paths.append(workspace / "module")
    if suite == "test":                     paths += [test_unittest_build_dir(workspace, arch), test_negative_build_dir(workspace, arch)]
    return paths

def local_prep_targets(*, workspace, suite_name, target_arch, executor, target_name="",
                        needs_kinsn_modules) -> list[Path]:
    arch, suite = str(target_arch).strip(), str(suite_name).strip()
    targets: list[Path] = []
    if suite in _BASE_TRANSFER_ROOTS:       targets.append(runtime_container_image_tar_path(workspace, arch))
    if str(executor).strip() == "kvm":
        targets += [kvm_kernel_image_path(workspace), kernel_modules_root(workspace, arch, executor) / "lib" / "modules"]
    if suite == "test":
        targets += [test_unittest_build_dir(workspace, arch) / "rejit_regression",
                    test_negative_build_dir(workspace, arch) / "scx_prog_show_race"]
    if needs_kinsn_modules:                 targets.extend(kinsn_targets(workspace, arch, target_name))
    seen: set[Path] = set()
    return [t for t in targets if not (t in seen or seen.add(t))]  # type: ignore[func-returns-value]

def remote_transfer_roots(*, suite_name, target_arch, needs_kinsn_modules) -> list[str]:
    roots: list[str] = []
    seen: set[str] = set()
    for path in [*_base_transfer_paths(ROOT_DIR, suite_name),
                 *_artifact_transfer_paths(workspace=ROOT_DIR, suite_name=suite_name, target_arch=target_arch,
                                           needs_kinsn_modules=needs_kinsn_modules)]:
        try:
            relative = str(path.relative_to(ROOT_DIR))
        except ValueError:
            continue
        if relative not in seen:
            seen.add(relative)
            roots.append(relative)
    ordered = [e for e in _TRANSFER_ROOT_ORDER if e in seen]
    ordered.extend(e for e in roots if e not in _TRANSFER_ROOT_ORDER)
    return ordered
