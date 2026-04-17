from __future__ import annotations

import os
from pathlib import Path

from runner.libs import ROOT_DIR


_RUNTIME_IMAGE_SUITES = {"test", "micro", "corpus", "e2e"}
RUNTIME_IMAGE_WORKSPACE = ROOT_DIR
RUNTIME_IMAGE_ARTIFACT_ROOT = Path("/opt/bpf-benchmark")

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

def image_artifact_root(target_arch: str, subdir: str) -> Path:
    return RUNTIME_IMAGE_ARTIFACT_ROOT / subdir / str(target_arch).strip()

def inside_runtime_image() -> bool:
    return os.environ.get("BPFREJIT_INSIDE_RUNTIME_CONTAINER", "").strip() == "1"

def runtime_workspace(workspace: Path) -> Path:
    if not inside_runtime_image():
        return workspace
    configured = os.environ.get("BPFREJIT_IMAGE_WORKSPACE", "").strip()
    return Path(configured) if configured else RUNTIME_IMAGE_WORKSPACE

def micro_program_root(workspace: Path, target_arch: str) -> Path:
    if inside_runtime_image():
        return image_artifact_root(target_arch, "micro-programs")
    return _cache(runtime_workspace(workspace), target_arch, "micro-programs")

def daemon_binary_path(workspace: Path, target_arch: str) -> Path:
    return _p(runtime_workspace(workspace), target_arch, "daemon_binary_path")

def runner_binary_path(workspace: Path, target_arch: str) -> Path:
    return _p(runtime_workspace(workspace), target_arch, "runner_binary_path")

def runtime_repo_artifact_root(workspace: Path, target_arch: str) -> Path:
    if inside_runtime_image():
        return image_artifact_root(target_arch, "repo-artifacts")
    return repo_artifact_root(runtime_workspace(workspace), target_arch)

def runtime_workload_tools_root(workspace: Path, target_arch: str) -> Path:
    if inside_runtime_image():
        return image_artifact_root(target_arch, "workload-tools")
    return workload_tools_root(runtime_workspace(workspace), target_arch)

def runtime_container_image_tar_path(workspace: Path, target_arch: str) -> Path:
    return workspace / ".cache" / "container-images" / f"{str(target_arch).strip()}-runner-runtime.image.tar"

def kinsn_module_dir(workspace: Path, target_arch: str) -> Path:
    if inside_runtime_image():
        return runtime_workspace(workspace) / "module" / ("arm64" if _is_arm64(target_arch) else "x86")
    return workspace / "module" / ("arm64" if _is_arm64(target_arch) else "x86")

def kernel_modules_root(workspace: Path, target_arch: str, executor: str) -> Path:
    del target_arch
    if inside_runtime_image():
        return Path("/")
    return repo_artifact_root(workspace, "x86_64") / "kernel-modules" if str(executor).strip() == "kvm" else Path("/")

def kvm_kernel_image_path(workspace: Path) -> Path:
    return workspace / ".cache" / "runtime-kernel" / "x86_64" / "bzImage"


def runtime_path_value(workspace: Path, target_arch: str) -> str:
    path_entries: list[str] = []
    arch = str(target_arch).strip()
    if arch:
        candidates: list[Path] = []
        if inside_runtime_image():
            candidates.append(runner_binary_path(workspace, arch).parent)
        path_entries.extend(str(path) for path in candidates if path.is_dir())
    for standard_dir in ("/usr/local/sbin", "/usr/local/bin", "/usr/sbin", "/usr/bin", "/sbin", "/bin"):
        if standard_dir not in path_entries:
            path_entries.append(standard_dir)
    return ":".join(path_entries)


def local_prep_targets(*, workspace, suite_name, target_arch, executor) -> list[Path]:
    arch, suite = str(target_arch).strip(), str(suite_name).strip()
    targets: list[Path] = []
    if suite in _RUNTIME_IMAGE_SUITES:      targets.append(runtime_container_image_tar_path(workspace, arch))
    if str(executor).strip() == "kvm":
        targets.append(kvm_kernel_image_path(workspace))
    seen: set[Path] = set()
    return [t for t in targets if not (t in seen or seen.add(t))]  # type: ignore[func-returns-value]
