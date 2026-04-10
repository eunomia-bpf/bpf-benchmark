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
_BCC_TOOLS = ("capable", "execsnoop", "bindsnoop", "biosnoop", "vfsstat", "opensnoop", "syscount", "tcpconnect", "tcplife", "runqlat")


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


def kvm_kernel_image_path(workspace: Path) -> Path:
    return workspace / ".cache" / "x86-kernel-build" / "arch" / "x86" / "boot" / "bzImage"


def scx_targets(workspace: Path, target_arch: str, packages: list[str]) -> list[Path]:
    root = repo_artifact_root(workspace, target_arch) / "scx"
    targets: list[Path] = []
    for package in packages:
        targets.append(root / "bin" / package)
        targets.append(root / f"{package}_main.bpf.o")
    return targets


def native_repo_targets(workspace: Path, target_arch: str, native_repos: list[str]) -> list[Path]:
    root = repo_artifact_root(workspace, target_arch)
    targets: list[Path] = []
    for repo_name in native_repos:
        if repo_name == "bcc":
            bcc_root = root / "bcc" / "libbpf-tools" / ".output"
            for tool in _BCC_TOOLS:
                targets.append(bcc_root / tool)
                targets.append(bcc_root / f"{tool}.bpf.o")
            continue
        if repo_name == "tracee":
            tracee_root = root / "tracee"
            targets.extend(
                (
                    tracee_root / "bin" / "tracee",
                    tracee_root / "tracee.bpf.o",
                    tracee_root / "lsm_support" / "kprobe_check.bpf.o",
                    tracee_root / "lsm_support" / "lsm_check.bpf.o",
                )
            )
            continue
        if repo_name == "tetragon":
            tetragon_root = root / "tetragon"
            targets.extend(
                (
                    tetragon_root / "bin" / "tetragon",
                    tetragon_root / "bpf_execve_event.o",
                    tetragon_root / "bpf_generic_kprobe.o",
                )
            )
            continue
        if repo_name == "katran":
            katran_root = root / "katran"
            targets.extend(
                (
                    katran_root / "bin" / "katran_server_grpc",
                    katran_root / "bpf" / "balancer.bpf.o",
                    katran_root / "bpf" / "healthchecking_ipip.bpf.o",
                )
            )
    return targets


def kinsn_targets(workspace: Path, target_arch: str) -> list[Path]:
    root = kinsn_module_dir(workspace, target_arch)
    names = ["bpf_rotate.ko", "bpf_select.ko", "bpf_extract.ko", "bpf_endian.ko", "bpf_bulk_memory.ko"]
    if str(target_arch).strip() == "arm64":
        names.insert(4, "bpf_ldp.ko")
    return [root / name for name in names]


def workload_tool_targets(workspace: Path, target_arch: str) -> list[Path]:
    root = workload_tools_root(workspace, target_arch) / "bin"
    return [root / "hackbench", root / "sysbench", root / "wrk"]


def _artifact_transfer_root(workspace: Path, target_arch: str, target: Path) -> Path | None:
    arch = str(target_arch).strip()
    artifact_root = repo_artifact_root(workspace, arch)
    if target.is_relative_to(artifact_root):
        relative = target.relative_to(artifact_root)
        if relative.parts:
            return artifact_root / relative.parts[0]
    workload_root = workload_tools_root(workspace, arch)
    if target.is_relative_to(workload_root):
        return workload_root
    daemon_binary = daemon_binary_path(workspace, arch)
    if target == daemon_binary:
        return daemon_binary.parent.parent
    runner_binary = runner_binary_path(workspace, arch)
    if target == runner_binary:
        return runner_binary.parent
    module_root = workspace / "module"
    if target.is_relative_to(module_root):
        return module_root
    return None


def local_prep_targets(
    *,
    workspace: Path,
    suite_name: str,
    target_arch: str,
    executor: str,
    needs_runner_binary: bool,
    needs_daemon_binary: bool,
    needs_kinsn_modules: bool,
    needs_workload_tools: bool,
    native_repos: list[str],
    scx_packages: list[str],
) -> list[Path]:
    targets: list[Path] = []
    arch = str(target_arch).strip()
    suite = str(suite_name).strip()
    if str(executor).strip() == "kvm":
        targets.append(kvm_kernel_image_path(workspace))
        targets.append(kernel_modules_root(workspace, arch, executor) / "lib" / "modules")
    libbpf_target = libbpf_runtime_path(workspace, arch, suite)
    if libbpf_target is not None:
        targets.append(libbpf_target)
    if needs_daemon_binary:
        targets.append(daemon_binary_path(workspace, arch))
    if needs_runner_binary:
        targets.append(runner_binary_path(workspace, arch))
    if suite == "test":
        targets.append(test_unittest_build_dir(workspace, arch) / "rejit_regression")
        targets.append(test_negative_build_dir(workspace, arch) / "scx_prog_show_race")
    if needs_kinsn_modules:
        targets.extend(kinsn_targets(workspace, arch))
    targets.extend(scx_targets(workspace, arch, scx_packages))
    targets.extend(native_repo_targets(workspace, arch, native_repos))
    if needs_workload_tools:
        targets.extend(workload_tool_targets(workspace, arch))
    if suite == "micro":
        targets.append(workspace / "micro" / "programs" / "simple.bpf.o")
    ordered: list[Path] = []
    seen: set[Path] = set()
    for target in targets:
        if target in seen:
            continue
        seen.add(target)
        ordered.append(target)
    return ordered


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
) -> list[str]:
    roots = set(_BASE_TRANSFER_ROOTS.get(str(suite_name).strip(), ()))
    arch = str(target_arch).strip()
    for target in local_prep_targets(
        workspace=ROOT_DIR,
        suite_name=suite_name,
        target_arch=arch,
        executor=executor,
        needs_runner_binary=needs_runner_binary,
        needs_daemon_binary=needs_daemon_binary,
        needs_kinsn_modules=needs_kinsn_modules,
        needs_workload_tools=needs_workload_tools,
        native_repos=native_repos,
        scx_packages=scx_packages,
    ):
        transfer_root = _artifact_transfer_root(ROOT_DIR, arch, target)
        if transfer_root is None:
            continue
        roots.add(str(transfer_root.relative_to(ROOT_DIR)))
    ordered = [entry for entry in _TRANSFER_ROOT_ORDER if entry in roots]
    ordered.extend(sorted(entry for entry in roots if entry not in _TRANSFER_ROOT_ORDER))
    return ordered
