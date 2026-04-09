from __future__ import annotations

from pathlib import Path

from runner.libs import ROOT_DIR


_BASE_TRANSFER_ROOTS = {
    "test": ("runner/__init__.py", "runner/libs", "tests"),
    "micro": ("runner/__init__.py", "runner/libs", "micro"),
    "corpus": ("runner/__init__.py", "runner/libs", "corpus/driver.py", "corpus/config"),
    "e2e": ("runner/__init__.py", "runner/libs", "corpus/config", "e2e/driver.py", "e2e/cases"),
}

_TRANSFER_ROOT_ORDER = ("runner", "daemon", "module", "tests", "micro", "corpus", "e2e")


def repo_artifact_root(workspace: Path, target_arch: str) -> Path:
    return workspace / ".cache" / "repo-artifacts" / str(target_arch).strip()


def workload_tools_root(workspace: Path, target_arch: str) -> Path:
    return workspace / ".cache" / "workload-tools" / str(target_arch).strip()


def daemon_binary_path(workspace: Path, target_arch: str) -> Path:
    if str(target_arch).strip() == "arm64":
        return workspace / "daemon" / "target" / "aarch64-unknown-linux-gnu" / "release" / "bpfrejit-daemon"
    return workspace / "daemon" / "target" / "release" / "bpfrejit-daemon"


def runner_binary_path(workspace: Path, target_arch: str) -> Path:
    if str(target_arch).strip() == "arm64":
        return workspace / "runner" / "build-arm64" / "micro_exec"
    return workspace / "runner" / "build" / "micro_exec"


def test_unittest_build_dir(workspace: Path, target_arch: str) -> Path:
    if str(target_arch).strip() == "arm64":
        return workspace / "tests" / "unittest" / "build-arm64"
    return workspace / "tests" / "unittest" / "build"


def test_negative_build_dir(workspace: Path, target_arch: str) -> Path:
    if str(target_arch).strip() == "arm64":
        return workspace / "tests" / "negative" / "build-arm64"
    return workspace / "tests" / "negative" / "build"


def kinsn_module_dir(workspace: Path, target_arch: str) -> Path:
    return workspace / "module" / ("arm64" if str(target_arch).strip() == "arm64" else "x86")


def suite_uses_libbpf_runtime(suite_name: str, target_arch: str) -> bool:
    return str(target_arch).strip() != "arm64" and str(suite_name).strip() in {"test", "corpus", "e2e"}


def libbpf_runtime_path(workspace: Path, target_arch: str, suite_name: str) -> Path | None:
    if not suite_uses_libbpf_runtime(suite_name, target_arch):
        return None
    return repo_artifact_root(workspace, target_arch) / "libbpf" / "lib" / "libbpf.so"


def kernel_modules_root(workspace: Path, target_arch: str, executor: str) -> Path:
    del target_arch
    if str(executor).strip() == "kvm":
        return repo_artifact_root(workspace, "x86_64") / "kernel-modules"
    return Path("/")


def remote_transfer_roots(
    *,
    suite_name: str,
    target_arch: str,
    executor: str,
    needs_runner_binary: bool,
    needs_daemon_binary: bool,
    needs_kinsn_modules: bool,
    needs_workload_tools: bool,
    native_repos: list[str],
    scx_packages: list[str],
    needs_katran_bundle: bool,
) -> list[str]:
    roots = set(_BASE_TRANSFER_ROOTS.get(str(suite_name).strip(), ()))
    arch = str(target_arch).strip()
    if needs_runner_binary:
        roots.add(str(runner_binary_path(ROOT_DIR, arch).relative_to(ROOT_DIR).parent))
    if needs_daemon_binary:
        roots.add(str(daemon_binary_path(ROOT_DIR, arch).relative_to(ROOT_DIR).parent.parent))
    if needs_kinsn_modules:
        roots.add("module")
    if needs_workload_tools:
        roots.add(str(workload_tools_root(ROOT_DIR, arch).relative_to(ROOT_DIR)))
    artifact_root = repo_artifact_root(ROOT_DIR, arch)
    if suite_uses_libbpf_runtime(suite_name, arch):
        roots.add(str((artifact_root / "libbpf").relative_to(ROOT_DIR)))
    if scx_packages:
        roots.add(str((artifact_root / "scx").relative_to(ROOT_DIR)))
    for repo_name in native_repos:
        roots.add(str((artifact_root / repo_name).relative_to(ROOT_DIR)))
    if needs_katran_bundle:
        roots.add(str((artifact_root / "katran").relative_to(ROOT_DIR)))
    if str(executor).strip() == "kvm" and needs_kinsn_modules:
        roots.add(str((artifact_root / "kernel-modules").relative_to(ROOT_DIR)))
    ordered = [entry for entry in _TRANSFER_ROOT_ORDER if entry in roots]
    ordered.extend(sorted(entry for entry in roots if entry not in _TRANSFER_ROOT_ORDER))
    return ordered
