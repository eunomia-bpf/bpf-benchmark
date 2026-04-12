from __future__ import annotations

from pathlib import Path

from runner.libs import ROOT_DIR


_BASE_TRANSFER_ROOTS = {
    "test":   ("runner/__init__.py", "runner/libs", "runner/suites", "tests"),
    "micro":  ("runner/__init__.py", "runner/libs", "runner/suites", "micro/driver.py", "micro/catalog.py", "micro/config", "micro/generated-inputs"),
    "corpus": ("runner/__init__.py", "runner/libs", "runner/suites", "corpus/driver.py", "corpus/config", "e2e/cases"),
    "e2e":    ("runner/__init__.py", "runner/libs", "runner/suites", "corpus/config", "e2e/driver.py", "e2e/cases"),
}

_TRANSFER_ROOT_ORDER = ("runner", "daemon", "module", "tests", "micro", "corpus", "e2e")
_BCC_TOOLS = ("capable", "execsnoop", "bindsnoop", "biosnoop", "vfsstat", "opensnoop", "syscount", "tcpconnect", "tcplife", "runqlat")

# (arm64_parts, x86_parts)
_ARCH_PATHS: dict[str, tuple[tuple[str, ...], tuple[str, ...]]] = {
    "daemon_binary_path":      (("daemon", "target", "aarch64-unknown-linux-gnu", "release", "bpfrejit-daemon"), ("daemon", "target", "release", "bpfrejit-daemon")),
    "runner_binary_path":      (("runner", "build-arm64", "micro_exec"), ("runner", "build", "micro_exec")),
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
def micro_program_root(workspace: Path, target_arch: str) -> Path:       return _cache(workspace, target_arch, "micro-programs")
def daemon_binary_path(workspace: Path, target_arch: str) -> Path:       return _p(workspace, target_arch, "daemon_binary_path")
def runner_binary_path(workspace: Path, target_arch: str) -> Path:       return _p(workspace, target_arch, "runner_binary_path")
def test_unittest_build_dir(workspace: Path, target_arch: str) -> Path:  return _p(workspace, target_arch, "test_unittest_build_dir")
def test_negative_build_dir(workspace: Path, target_arch: str) -> Path:  return _p(workspace, target_arch, "test_negative_build_dir")

def runtime_container_image_tar_path(workspace: Path, target_arch: str) -> Path:
    return workspace / ".cache" / "container-images" / f"{str(target_arch).strip()}-runner-runtime.image.tar"

def kinsn_module_dir(workspace: Path, target_arch: str) -> Path:
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
        candidates = (
            repo_artifact_root(workspace, arch) / "bpftrace" / "bin",
            workload_tools_root(workspace, arch) / "bin",
        )
        path_entries.extend(str(path) for path in candidates if path.is_dir())
    for standard_dir in ("/usr/local/sbin", "/usr/local/bin", "/usr/sbin", "/usr/bin", "/sbin", "/bin"):
        if standard_dir not in path_entries:
            path_entries.append(standard_dir)
    return ":".join(path_entries)


def scx_targets(workspace: Path, target_arch: str, packages: list[str]) -> list[Path]:
    root = repo_artifact_root(workspace, target_arch) / "scx"
    return [p for pkg in packages for p in (root / "bin" / pkg, root / f"{pkg}_main.bpf.o")]

def native_repo_targets(workspace: Path, target_arch: str, native_repos: list[str]) -> list[Path]:
    root = repo_artifact_root(workspace, target_arch)
    targets: list[Path] = []
    for repo_name in native_repos:
        if repo_name == "bcc":
            bcc = root / "bcc" / "libbpf-tools" / ".output"
            for t in _BCC_TOOLS:
                targets += [bcc / t, bcc / f"{t}.bpf.o"]
        elif repo_name == "tracee":
            tr = root / "tracee"
            targets += [tr / "bin" / "tracee", tr / "tracee.bpf.o",
                        tr / "lsm_support" / "kprobe_check.bpf.o", tr / "lsm_support" / "lsm_check.bpf.o"]
        elif repo_name == "bpftrace":
            targets.append(root / "bpftrace" / "bin" / "bpftrace")
        elif repo_name == "tetragon":
            tg = root / "tetragon"
            targets += [tg / "bin" / "tetragon", tg / "bpf_execve_event.o", tg / "bpf_generic_kprobe.o"]
        elif repo_name == "katran":
            kt = root / "katran"
            targets += [kt / "bin" / "katran_server_grpc", kt / "bpf" / "balancer.bpf.o", kt / "bpf" / "healthchecking_ipip.bpf.o"]
    return targets

def kinsn_targets(workspace: Path, target_arch: str) -> list[Path]:
    root = kinsn_module_dir(workspace, target_arch)
    names = ["bpf_rotate.ko", "bpf_select.ko", "bpf_extract.ko", "bpf_endian.ko", "bpf_bulk_memory.ko"]
    if _is_arm64(target_arch):
        names.insert(4, "bpf_ldp.ko")
    return [root / n for n in names]

def workload_tool_targets(workspace: Path, target_arch: str) -> list[Path]:
    root = workload_tools_root(workspace, target_arch) / "bin"
    return [root / "hackbench", root / "sysbench", root / "wrk"]

def micro_program_targets(workspace: Path, target_arch: str) -> list[Path]:
    return [micro_program_root(workspace, target_arch) / "simple.bpf.o"]


def _base_transfer_paths(workspace: Path, suite_name: str) -> list[Path]:
    return [workspace / e for e in _BASE_TRANSFER_ROOTS.get(str(suite_name).strip(), ())]

def _artifact_transfer_paths(*, workspace, suite_name, target_arch, needs_runner_binary,
                              needs_daemon_binary, needs_kinsn_modules, needs_workload_tools,
                              native_repos, scx_packages) -> list[Path]:
    arch, suite = str(target_arch).strip(), str(suite_name).strip()
    paths: list[Path] = []
    if suite in _BASE_TRANSFER_ROOTS:       paths.append(runtime_container_image_tar_path(workspace, arch))
    if needs_daemon_binary:                 paths.append(daemon_binary_path(workspace, arch).parent)
    if needs_runner_binary:                 paths.append(runner_binary_path(workspace, arch).parent)
    if needs_kinsn_modules:                 paths.append(workspace / "module")
    if needs_workload_tools:                paths.append(workload_tools_root(workspace, arch))
    if suite == "micro":                    paths.append(micro_program_root(workspace, arch))
    if scx_packages:                        paths.append(repo_artifact_root(workspace, arch) / "scx")
    for r in native_repos:                  paths.append(repo_artifact_root(workspace, arch) / str(r).strip())
    if suite == "test":                     paths += [test_unittest_build_dir(workspace, arch), test_negative_build_dir(workspace, arch)]
    return paths

def local_prep_targets(*, workspace, suite_name, target_arch, executor, needs_runner_binary,
                        needs_daemon_binary, needs_kinsn_modules, needs_workload_tools,
                        native_repos, scx_packages) -> list[Path]:
    arch, suite = str(target_arch).strip(), str(suite_name).strip()
    targets: list[Path] = []
    if suite in _BASE_TRANSFER_ROOTS:       targets.append(runtime_container_image_tar_path(workspace, arch))
    if str(executor).strip() == "kvm":
        targets += [kvm_kernel_image_path(workspace), kernel_modules_root(workspace, arch, executor) / "lib" / "modules"]
    if needs_daemon_binary:                 targets.append(daemon_binary_path(workspace, arch))
    if needs_runner_binary:                 targets.append(runner_binary_path(workspace, arch))
    if suite == "test":
        targets += [test_unittest_build_dir(workspace, arch) / "rejit_regression",
                    test_negative_build_dir(workspace, arch) / "scx_prog_show_race"]
    if needs_kinsn_modules:                 targets.extend(kinsn_targets(workspace, arch))
    targets.extend(scx_targets(workspace, arch, scx_packages))
    targets.extend(native_repo_targets(workspace, arch, native_repos))
    if needs_workload_tools:                targets.extend(workload_tool_targets(workspace, arch))
    if suite == "micro":                    targets.extend(micro_program_targets(workspace, arch))
    seen: set[Path] = set()
    return [t for t in targets if not (t in seen or seen.add(t))]  # type: ignore[func-returns-value]

def remote_transfer_roots(*, suite_name, target_arch, needs_runner_binary, needs_daemon_binary,
                           needs_kinsn_modules, needs_workload_tools, native_repos, scx_packages) -> list[str]:
    roots: list[str] = []
    seen: set[str] = set()
    for path in [*_base_transfer_paths(ROOT_DIR, suite_name),
                 *_artifact_transfer_paths(workspace=ROOT_DIR, suite_name=suite_name, target_arch=target_arch,
                                           needs_runner_binary=needs_runner_binary, needs_daemon_binary=needs_daemon_binary,
                                           needs_kinsn_modules=needs_kinsn_modules, needs_workload_tools=needs_workload_tools,
                                           native_repos=native_repos, scx_packages=scx_packages)]:
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
