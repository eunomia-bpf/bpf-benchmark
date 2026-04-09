from __future__ import annotations

import fcntl
import os
import shutil
import subprocess
import tarfile
from dataclasses import dataclass
from pathlib import Path
from typing import Callable

from runner.libs import ROOT_DIR
from runner.libs.arm64_kernel_config import generate_aws_config
from runner.libs.local_prep_common import die, require_nonempty_dir, require_path
from runner.libs.source_tree import snapshot_git_subtree


@dataclass(frozen=True)
class AwsKernelPaths:
    target_cache_dir: Path
    run_prep_root: Path
    artifact_dir: Path
    x86_setup_artifact_root: Path
    x86_kinsn_module_stage_dir: Path
    arm64_worktree_dir: Path
    arm64_aws_build_dir: Path
    arm64_aws_base_config: Path
    arm64_setup_artifact_root: Path
    arm64_kinsn_module_stage_dir: Path
    arm64_upstream_test_kmods_dir: Path
    cross_compile_prefix: str

    @property
    def root_dir(self) -> Path:
        return ROOT_DIR

    @property
    def kernel_dir(self) -> Path:
        return self.root_dir / "vendor/linux-framework"

    @property
    def x86_kernel_build_lock_file(self) -> Path:
        return self.root_dir / ".cache/kernel-build.lock"

    @property
    def arm64_kernel_build_lock_file(self) -> Path:
        return self.root_dir / ".cache/kernel-build-arm64.lock"

    @property
    def kernel_defconfig_src(self) -> Path:
        return self.root_dir / "vendor/bpfrejit_defconfig"

    @property
    def kernel_config_stamp_file(self) -> Path:
        return self.kernel_dir / ".bpfrejit_config.stamp"

    @property
    def x86_bzimage(self) -> Path:
        return self.kernel_dir / "arch/x86/boot/bzImage"

    @property
    def x86_vmlinux(self) -> Path:
        return self.kernel_dir / "vmlinux"

    @property
    def x86_kinsn_module_build_src(self) -> Path:
        return self.run_prep_root / "module-src/x86"

    @property
    def arm64_kinsn_module_build_src(self) -> Path:
        return self.run_prep_root / "module-src/arm64"

    @property
    def arm64_upstream_test_kmods_source_dir(self) -> Path:
        return self.root_dir / "vendor/linux-framework/tools/testing/selftests/bpf/test_kmods"


def build_paths_from_prep(prep) -> AwsKernelPaths:
    return AwsKernelPaths(
        target_cache_dir=prep.target_cache_dir,
        run_prep_root=prep.run_prep_root,
        artifact_dir=prep.artifact_dir,
        x86_setup_artifact_root=prep.x86_setup_artifact_root,
        x86_kinsn_module_stage_dir=prep.x86_kinsn_stage_dir,
        arm64_worktree_dir=prep.arm64_worktree_dir,
        arm64_aws_build_dir=prep.arm64_aws_build_dir,
        arm64_aws_base_config=prep.arm64_aws_base_config,
        arm64_setup_artifact_root=prep.arm64_setup_artifact_root,
        arm64_kinsn_module_stage_dir=prep.arm64_kinsn_stage_dir,
        arm64_upstream_test_kmods_dir=prep.arm64_upstream_test_kmods_dir,
        cross_compile_prefix=(prep.env.get("CROSS_COMPILE_ARM64", "aarch64-linux-gnu-").strip() or "aarch64-linux-gnu-"),
    )


def build_paths_from_ctx(ctx) -> AwsKernelPaths:
    target_cache_dir = ctx.target_cache_dir
    run_prep_root = ctx.run_prep_root
    return AwsKernelPaths(
        target_cache_dir=target_cache_dir,
        run_prep_root=run_prep_root,
        artifact_dir=run_prep_root / "artifacts",
        x86_setup_artifact_root=target_cache_dir / "setup-artifacts" / "x86",
        x86_kinsn_module_stage_dir=run_prep_root / "test-artifacts/kinsn-modules/x86",
        arm64_worktree_dir=ROOT_DIR / ".worktrees/linux-framework-arm64-src",
        arm64_aws_build_dir=target_cache_dir / "kernel-build",
        arm64_aws_base_config=target_cache_dir / "config-al2023-arm64",
        arm64_setup_artifact_root=target_cache_dir / "setup-artifacts",
        arm64_kinsn_module_stage_dir=run_prep_root / "test-artifacts/kinsn-modules/arm64",
        arm64_upstream_test_kmods_dir=target_cache_dir / "upstream-selftests-kmods-arm64",
        cross_compile_prefix=(ctx.contract.get("CROSS_COMPILE_ARM64", "") if isinstance(ctx.contract.get("CROSS_COMPILE_ARM64", ""), str) else "") or "aarch64-linux-gnu-",
    )


def _run(command: list[str], *, cwd: Path | None = None, input_text: str | None = None, env: dict[str, str] | None = None) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        cwd=cwd,
        input=input_text,
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )
    if completed.returncode != 0:
        output = completed.stderr.strip() or completed.stdout.strip() or "command failed"
        die(f"{output}: {' '.join(command)}")
    return completed


def _run_passthrough(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    completed = subprocess.run(command, cwd=cwd, env=env, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _with_lock(lock_path: Path, fn: Callable[[], None]) -> None:
    lock_path.parent.mkdir(parents=True, exist_ok=True)
    with lock_path.open("w", encoding="utf-8") as handle:
        fcntl.flock(handle.fileno(), fcntl.LOCK_EX)
        try:
            fn()
        finally:
            fcntl.flock(handle.fileno(), fcntl.LOCK_UN)


def stage_module_binaries(source_dir: Path, dest_dir: Path) -> None:
    shutil.rmtree(dest_dir, ignore_errors=True)
    dest_dir.mkdir(parents=True, exist_ok=True)
    copied = False
    for module in sorted(source_dir.glob("*.ko")):
        shutil.copy2(module, dest_dir / module.name)
        copied = True
    if not copied:
        die(f"module staging source has no .ko files: {source_dir}")


def _snapshot_kinsn_module_source_tree(paths: AwsKernelPaths, arch_dir_rel: str, dest_dir: Path) -> None:
    parent_dir = dest_dir.parent
    shutil.rmtree(dest_dir, ignore_errors=True)
    shutil.rmtree(parent_dir / "include", ignore_errors=True)
    parent_dir.mkdir(parents=True, exist_ok=True)
    snapshot_git_subtree(paths.root_dir, "module/include", parent_dir / "include", die=die)
    snapshot_git_subtree(paths.root_dir, arch_dir_rel, dest_dir, die=die)


def _modules_tar_has_entry(modules_tar: Path, suffix: str) -> bool:
    if not modules_tar.is_file():
        return False
    with tarfile.open(modules_tar, "r:gz") as handle:
        return any(member.name.endswith(suffix) for member in handle.getmembers())


def _cached_setup_artifacts_ready(cache_dir: Path, kernel_release: str, kernel_image_filename: str) -> bool:
    return (
        (cache_dir / f"vmlinux-{kernel_release}").is_file()
        and (cache_dir / kernel_image_filename).is_file()
        and (cache_dir / f"modules-{kernel_release}.tar.gz").is_file()
    )


def _link_cached_setup_artifacts(paths: AwsKernelPaths, cache_dir: Path, kernel_release: str, kernel_image_filename: str) -> None:
    shutil.rmtree(paths.artifact_dir, ignore_errors=True)
    paths.artifact_dir.mkdir(parents=True, exist_ok=True)
    for src_name, dest_name in (
        (f"vmlinux-{kernel_release}", f"vmlinux-{kernel_release}"),
        (kernel_image_filename, kernel_image_filename),
        (f"modules-{kernel_release}.tar.gz", f"modules-{kernel_release}.tar.gz"),
    ):
        link = paths.artifact_dir / dest_name
        if link.exists() or link.is_symlink():
            link.unlink()
        link.symlink_to((cache_dir / src_name).resolve())


def _config_symbol_value(config_path: Path, symbol: str) -> str:
    if not config_path.is_file():
        return "unknown"
    for line in config_path.read_text(encoding="utf-8", errors="replace").splitlines():
        if line == f"{symbol}=y":
            return "y"
        if line == f"{symbol}=m":
            return "m"
        if line == f"# {symbol} is not set":
            return "n"
    return "unknown"


def _elf_has_btf(elf_path: Path) -> bool:
    completed = subprocess.run(["readelf", "-S", str(elf_path)], check=False, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
    return completed.returncode == 0 and ".BTF" in completed.stdout


def _efi_binary_is_valid(image_path: Path) -> bool:
    completed = subprocess.run(["file", str(image_path)], check=False, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
    return completed.returncode == 0 and "EFI application" in completed.stdout


def _x86_cached_kinsn_modules_dir(cache_dir: Path) -> Path:
    return cache_dir / "kinsn-modules/x86"


def _arm64_cached_kinsn_modules_dir(cache_dir: Path) -> Path:
    return cache_dir / "kinsn-modules/arm64"


def _x86_setup_config_fingerprint_path(cache_dir: Path) -> Path:
    return cache_dir / "config.sha256"


def _x86_setup_config_fingerprint(paths: AwsKernelPaths) -> str:
    require_path(paths.kernel_dir / ".config", "x86 kernel config")
    return _run(["sha256sum", str(paths.kernel_dir / ".config")]).stdout.split()[0]


def _x86_cached_setup_matches_config(cache_dir: Path, expected_fingerprint: str) -> bool:
    fingerprint_path = _x86_setup_config_fingerprint_path(cache_dir)
    return fingerprint_path.is_file() and fingerprint_path.read_text(encoding="utf-8").strip() == expected_fingerprint


def _x86_write_cached_setup_fingerprint(cache_dir: Path, fingerprint: str) -> None:
    _x86_setup_config_fingerprint_path(cache_dir).write_text(f"{fingerprint}\n", encoding="utf-8")


def _x86_cached_setup_artifacts_ready(cache_dir: Path, kernel_release: str, kernel_image_filename: str, config_fingerprint: str) -> bool:
    return _cached_setup_artifacts_ready(cache_dir, kernel_release, kernel_image_filename) and _x86_cached_setup_matches_config(cache_dir, config_fingerprint)


def _x86_cached_kinsn_modules_ready(cache_dir: Path, kernel_release: str) -> bool:
    module_dir = _x86_cached_kinsn_modules_dir(cache_dir)
    if not module_dir.is_dir() or not any(module_dir.glob("*.ko")):
        return False
    for module in module_dir.glob("*.ko"):
        actual_release = _run(["modinfo", "-F", "vermagic", str(module)]).stdout.strip().split()
        if not actual_release or actual_release[0] != kernel_release:
            return False
    return True


def _arm64_cached_kinsn_modules_ready(cache_dir: Path, kernel_release: str) -> bool:
    module_dir = _arm64_cached_kinsn_modules_dir(cache_dir)
    if not module_dir.is_dir() or not any(module_dir.glob("*.ko")):
        return False
    for module in module_dir.glob("*.ko"):
        actual_release = _run(["modinfo", "-F", "vermagic", str(module)]).stdout.strip().split()
        if not actual_release or actual_release[0] != kernel_release:
            return False
    return True


def _prepare_x86_aws_config_locked(paths: AwsKernelPaths) -> None:
    config_file = paths.kernel_dir / ".config"
    config_script = paths.kernel_dir / "scripts/config"
    require_path(paths.kernel_defconfig_src, "x86 kernel defconfig")
    require_path(config_script, "x86 kernel config helper")
    shutil.copy2(paths.kernel_defconfig_src, config_file)
    _run(
        [
            str(config_script),
            "--file",
            str(config_file),
            "--enable",
            "UNWINDER_ORC",
            "--disable",
            "UNWINDER_FRAME_POINTER",
            "--disable",
            "DEBUG_INFO_BTF_MODULES",
            "--set-str",
            "SYSTEM_TRUSTED_KEYS",
            "",
            "--set-str",
            "SYSTEM_REVOCATION_KEYS",
            "",
            "--enable",
            "NET_VENDOR_AMAZON",
            "--enable",
            "ENA_ETHERNET",
            "--module",
            "NVME_CORE",
            "--module",
            "BLK_DEV_NVME",
            "--module",
            "XFS_FS",
            "--module",
            "EXT4_FS",
            "--enable",
            "VIRTIO_NET",
            "--enable",
            "VIRTIO_PCI",
            "--module",
            "VIRTIO_BLK",
        ]
    )
    paths.kernel_config_stamp_file.unlink(missing_ok=True)
    _run_passthrough(["make", "-C", str(paths.kernel_dir), "olddefconfig"])


def _build_x86_kinsn_modules_into_cache(paths: AwsKernelPaths, cache_dir: Path) -> None:
    _snapshot_kinsn_module_source_tree(paths, "module/x86", paths.x86_kinsn_module_build_src)
    _run_passthrough(["make", "-C", str(paths.x86_kinsn_module_build_src), f"KDIR={paths.kernel_dir}", "clean"])
    _run_passthrough(["make", "-C", str(paths.x86_kinsn_module_build_src), f"KDIR={paths.kernel_dir}"])
    stage_module_binaries(paths.x86_kinsn_module_build_src, _x86_cached_kinsn_modules_dir(cache_dir))


def _require_installed_kernel_module(modules_root: Path, relative_path: str, description: str) -> None:
    base = modules_root / relative_path
    candidates = (
        base,
        base.with_name(base.name + ".zst"),
        base.with_name(base.name + ".xz"),
        base.with_name(base.name + ".gz"),
    )
    for candidate in candidates:
        if candidate.is_file():
            return
    tried = ", ".join(str(candidate) for candidate in candidates)
    die(f"{description} not found: tried {tried}")


def _build_x86_kernel_artifacts_locked(paths: AwsKernelPaths) -> tuple[str, Path, Path]:
    _prepare_x86_aws_config_locked(paths)
    config_fingerprint = _x86_setup_config_fingerprint(paths)
    release_path = paths.kernel_dir / "include/config/kernel.release"
    if release_path.is_file():
        cached_release = release_path.read_text(encoding="utf-8").strip()
        if cached_release:
            cache_dir = paths.x86_setup_artifact_root / cached_release
            if _x86_cached_setup_artifacts_ready(cache_dir, cached_release, f"bzImage-{cached_release}", config_fingerprint):
                if _modules_tar_has_entry(cache_dir / f"modules-{cached_release}.tar.gz", "modules.dep") and _x86_cached_kinsn_modules_ready(cache_dir, cached_release):
                    _link_cached_setup_artifacts(paths, cache_dir, cached_release, f"bzImage-{cached_release}")
                    return (
                        cached_release,
                        (paths.artifact_dir / f"bzImage-{cached_release}").resolve(),
                        (paths.artifact_dir / f"modules-{cached_release}.tar.gz").resolve(),
                    )
                shutil.rmtree(cache_dir, ignore_errors=True)
    _run_passthrough(["make", "-C", str(paths.kernel_dir), f"-j{os.cpu_count() or 1}", "bzImage", "modules_prepare"])
    if (paths.kernel_dir / "vmlinux.symvers").is_file():
        shutil.copy2(paths.kernel_dir / "vmlinux.symvers", paths.kernel_dir / "Module.symvers")
    kernel_release = (paths.kernel_dir / "include/config/kernel.release").read_text(encoding="utf-8").strip()
    if not kernel_release:
        die("x86 kernel release is empty")
    cache_dir = paths.x86_setup_artifact_root / kernel_release
    if _x86_cached_setup_artifacts_ready(cache_dir, kernel_release, f"bzImage-{kernel_release}", config_fingerprint):
        if _modules_tar_has_entry(cache_dir / f"modules-{kernel_release}.tar.gz", "modules.dep") and _x86_cached_kinsn_modules_ready(cache_dir, kernel_release):
            _link_cached_setup_artifacts(paths, cache_dir, kernel_release, f"bzImage-{kernel_release}")
            return (
                kernel_release,
                (paths.artifact_dir / f"bzImage-{kernel_release}").resolve(),
                (paths.artifact_dir / f"modules-{kernel_release}.tar.gz").resolve(),
            )
        shutil.rmtree(cache_dir, ignore_errors=True)
    _run_passthrough(["make", "-C", str(paths.kernel_dir), f"-j{os.cpu_count() or 1}", "modules"])
    cached_stage = cache_dir / "modules-stage"
    shutil.rmtree(cache_dir, ignore_errors=True)
    cache_dir.mkdir(parents=True, exist_ok=True)
    cached_stage.mkdir(parents=True, exist_ok=True)
    _run_passthrough(["make", "-C", str(paths.kernel_dir), f"INSTALL_MOD_PATH={cached_stage}", "modules_install"])
    modules_root = cached_stage / f"lib/modules/{kernel_release}"
    for link_name in ("build", "source"):
        (modules_root / link_name).unlink(missing_ok=True)
    _require_installed_kernel_module(modules_root, "kernel/drivers/nvme/host/nvme-core.ko", "x86 nvme-core module")
    _require_installed_kernel_module(modules_root, "kernel/drivers/nvme/host/nvme.ko", "x86 nvme module")
    _require_installed_kernel_module(modules_root, "kernel/fs/ext4/ext4.ko", "x86 ext4 module")
    _require_installed_kernel_module(modules_root, "kernel/fs/xfs/xfs.ko", "x86 xfs module")
    _require_installed_kernel_module(modules_root, "kernel/drivers/block/virtio_blk.ko", "x86 virtio_blk module")
    shutil.copy2(paths.x86_vmlinux, cache_dir / f"vmlinux-{kernel_release}")
    shutil.copy2(paths.x86_bzimage, cache_dir / f"bzImage-{kernel_release}")
    with tarfile.open(cache_dir / f"modules-{kernel_release}.tar.gz", "w:gz") as handle:
        handle.add(cached_stage / "lib/modules", arcname="lib/modules")
    shutil.rmtree(cached_stage, ignore_errors=True)
    if not _modules_tar_has_entry(cache_dir / f"modules-{kernel_release}.tar.gz", "modules.dep"):
        die("generated x86 modules archive is invalid")
    _build_x86_kinsn_modules_into_cache(paths, cache_dir)
    if not _x86_cached_kinsn_modules_ready(cache_dir, kernel_release):
        die("generated x86 kinsn module cache is invalid")
    _x86_write_cached_setup_fingerprint(cache_dir, config_fingerprint)
    _link_cached_setup_artifacts(paths, cache_dir, kernel_release, f"bzImage-{kernel_release}")
    return (
        kernel_release,
        (paths.artifact_dir / f"bzImage-{kernel_release}").resolve(),
        (paths.artifact_dir / f"modules-{kernel_release}.tar.gz").resolve(),
    )


def build_x86_kernel_artifacts(paths: AwsKernelPaths) -> tuple[str, Path, Path]:
    result: tuple[str, Path, Path] | None = None

    def _build() -> None:
        nonlocal result
        result = _build_x86_kernel_artifacts_locked(paths)

    paths.artifact_dir.mkdir(parents=True, exist_ok=True)
    _with_lock(paths.x86_kernel_build_lock_file, _build)
    if result is None:
        die("x86 kernel artifact build returned no result")
    return result


def ensure_x86_kinsn_modules_ready(paths: AwsKernelPaths) -> None:
    def _build() -> None:
        _prepare_x86_aws_config_locked(paths)
        config_fingerprint = _x86_setup_config_fingerprint(paths)
        expected_release = (paths.kernel_dir / "include/config/kernel.release").read_text(encoding="utf-8").strip() if (paths.kernel_dir / "include/config/kernel.release").is_file() else ""
        if not expected_release:
            _build_x86_kernel_artifacts_locked(paths)
            return
        cache_dir = paths.x86_setup_artifact_root / expected_release
        if not _x86_cached_setup_artifacts_ready(cache_dir, expected_release, f"bzImage-{expected_release}", config_fingerprint):
            shutil.rmtree(cache_dir, ignore_errors=True)
            _build_x86_kernel_artifacts_locked(paths)
            return
        if not _x86_cached_kinsn_modules_ready(cache_dir, expected_release):
            shutil.rmtree(_x86_cached_kinsn_modules_dir(cache_dir), ignore_errors=True)
            _build_x86_kinsn_modules_into_cache(paths, cache_dir)
        if not _x86_cached_kinsn_modules_ready(cache_dir, expected_release):
            die(f"x86 cached kinsn modules are missing or invalid for {expected_release}")
        stage_module_binaries(_x86_cached_kinsn_modules_dir(cache_dir), paths.x86_kinsn_module_stage_dir)

    _with_lock(paths.x86_kernel_build_lock_file, _build)


def _arm64_build_config_matches_aws_base(paths: AwsKernelPaths) -> bool:
    current_config = paths.arm64_aws_build_dir / ".config"
    if not paths.arm64_aws_base_config.is_file() or not current_config.is_file():
        return False
    for symbol in ("CONFIG_MODVERSIONS", "CONFIG_MODULE_SIG", "CONFIG_MODULE_SIG_ALL", "CONFIG_LOCALVERSION_AUTO"):
        if _config_symbol_value(paths.arm64_aws_base_config, symbol) != _config_symbol_value(current_config, symbol):
            return False
    return True


def refresh_aws_arm64_base_config(paths: AwsKernelPaths, *, remote_kernel_release: str, fetch_config_text: Callable[[], str]) -> None:
    if not remote_kernel_release.endswith(".amzn2023.aarch64"):
        if paths.arm64_aws_base_config.is_file():
            return
        die(f"cannot seed AWS ARM64 base config from non-stock kernel {remote_kernel_release}; relaunch a fresh AL2023 instance")
    config_text = fetch_config_text()
    if "CONFIG_ARM64=y" not in config_text:
        die("captured AWS ARM64 base config is invalid")
    paths.arm64_aws_base_config.parent.mkdir(parents=True, exist_ok=True)
    paths.arm64_aws_base_config.write_text(config_text, encoding="utf-8")


def _rebuild_arm64_kinsn_modules(paths: AwsKernelPaths) -> None:
    _ensure_arm64_worktree(paths)
    _snapshot_kinsn_module_source_tree(paths, "module/arm64", paths.arm64_kinsn_module_build_src)
    _run_passthrough(
        [
            "make",
            "-C",
            str(paths.arm64_worktree_dir),
            f"O={paths.arm64_aws_build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={paths.cross_compile_prefix}",
            "modules_prepare",
        ]
    )
    _run_passthrough(
        [
            "make",
            "-C",
            str(paths.arm64_worktree_dir),
            f"O={paths.arm64_aws_build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={paths.cross_compile_prefix}",
            f"M={paths.arm64_kinsn_module_build_src}",
            "modules",
        ]
    )


def _build_arm64_kinsn_modules_into_cache(paths: AwsKernelPaths, cache_dir: Path) -> None:
    _rebuild_arm64_kinsn_modules(paths)
    stage_module_binaries(paths.arm64_kinsn_module_build_src, _arm64_cached_kinsn_modules_dir(cache_dir))


def ensure_arm64_upstream_test_kmods_ready(paths: AwsKernelPaths, *, kernel_release: str) -> None:
    def _rebuild() -> None:
        _ensure_arm64_worktree(paths)
        require_path(paths.arm64_upstream_test_kmods_source_dir, "ARM64 upstream selftest kmod source dir")
        shutil.rmtree(paths.arm64_upstream_test_kmods_dir, ignore_errors=True)
        paths.arm64_upstream_test_kmods_dir.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(paths.arm64_upstream_test_kmods_source_dir, paths.arm64_upstream_test_kmods_dir)
        for pattern in ("*.ko", "*.o", "*.mod", "*.mod.c", ".*.cmd", ".module-common.o", "Module.symvers", "modules.order"):
            for path in paths.arm64_upstream_test_kmods_dir.glob(pattern):
                if path.is_dir():
                    shutil.rmtree(path)
                else:
                    path.unlink(missing_ok=True)
        _run_passthrough(
            [
                "make",
                "-C",
                str(paths.arm64_worktree_dir),
                f"O={paths.arm64_aws_build_dir}",
                "ARCH=arm64",
                f"CROSS_COMPILE={paths.cross_compile_prefix}",
                f"M={paths.arm64_upstream_test_kmods_dir}",
                "modules",
            ]
        )

    def _ensure() -> None:
        required = [
            paths.arm64_upstream_test_kmods_dir / "bpf_testmod.ko",
            paths.arm64_upstream_test_kmods_dir / "bpf_test_no_cfi.ko",
            paths.arm64_upstream_test_kmods_dir / "bpf_test_modorder_x.ko",
            paths.arm64_upstream_test_kmods_dir / "bpf_test_modorder_y.ko",
            paths.arm64_upstream_test_kmods_dir / "bpf_test_rqspinlock.ko",
        ]
        for module_path in required:
            if not module_path.is_file():
                _rebuild()
                break
            actual_release = _run(["modinfo", "-F", "vermagic", str(module_path)]).stdout.strip().split()
            if not actual_release or actual_release[0] != kernel_release:
                _rebuild()
                break
        for module_path in required:
            actual_release = _run(["modinfo", "-F", "vermagic", str(module_path)]).stdout.strip().split()
            if not actual_release or actual_release[0] != kernel_release:
                die(f"ARM64 upstream selftest kmod release mismatch for {module_path.name}")

    _with_lock(paths.arm64_kernel_build_lock_file, _ensure)


def _build_arm64_kernel_artifacts_locked(paths: AwsKernelPaths) -> tuple[str, Path, Path]:
    _ensure_arm64_worktree(paths)
    for path in (
        paths.arm64_aws_build_dir / ".config",
        paths.arm64_aws_build_dir / "arch/arm64/boot/Image",
        paths.arm64_aws_build_dir / "arch/arm64/boot/vmlinuz",
        paths.arm64_aws_build_dir / "arch/arm64/boot/vmlinuz.efi",
        paths.arm64_aws_build_dir / "arch/arm64/boot/vmlinuz.efi.elf",
        paths.arm64_aws_build_dir / "vmlinux",
    ):
        path.unlink(missing_ok=True)
    generate_aws_config(paths.arm64_worktree_dir, paths.arm64_aws_build_dir, paths.cross_compile_prefix, paths.arm64_aws_base_config)
    _run_passthrough(
        [
            "make",
            "-C",
            str(paths.arm64_worktree_dir),
            f"O={paths.arm64_aws_build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={paths.cross_compile_prefix}",
            "Image",
            f"-j{os.cpu_count() or 1}",
        ]
    )
    _run_passthrough(
        [
            "make",
            "-C",
            str(paths.arm64_worktree_dir),
            f"O={paths.arm64_aws_build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={paths.cross_compile_prefix}",
            "vmlinuz.efi",
            f"-j{os.cpu_count() or 1}",
        ]
    )
    kernel_release = (paths.arm64_aws_build_dir / "include/config/kernel.release").read_text(encoding="utf-8").strip()
    if not kernel_release:
        die("ARM64 kernel release is empty")
    cache_dir = paths.arm64_setup_artifact_root / kernel_release
    if _cached_setup_artifacts_ready(cache_dir, kernel_release, f"vmlinuz-{kernel_release}.efi"):
        if _elf_has_btf(cache_dir / f"vmlinux-{kernel_release}") and _efi_binary_is_valid(cache_dir / f"vmlinuz-{kernel_release}.efi") and _modules_tar_has_entry(cache_dir / f"modules-{kernel_release}.tar.gz", "modules.dep"):
            _link_cached_setup_artifacts(paths, cache_dir, kernel_release, f"vmlinuz-{kernel_release}.efi")
            return (
                kernel_release,
                (paths.artifact_dir / f"vmlinuz-{kernel_release}.efi").resolve(),
                (paths.artifact_dir / f"modules-{kernel_release}.tar.gz").resolve(),
            )
    _run_passthrough(
        [
            "make",
            "-C",
            str(paths.arm64_worktree_dir),
            f"O={paths.arm64_aws_build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={paths.cross_compile_prefix}",
            "modules",
            f"-j{os.cpu_count() or 1}",
        ]
    )
    cached_stage = cache_dir / "modules-stage"
    shutil.rmtree(cache_dir, ignore_errors=True)
    cache_dir.mkdir(parents=True, exist_ok=True)
    cached_stage.mkdir(parents=True, exist_ok=True)
    _run_passthrough(
        [
            "make",
            "-C",
            str(paths.arm64_worktree_dir),
            f"O={paths.arm64_aws_build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={paths.cross_compile_prefix}",
            f"INSTALL_MOD_PATH={cached_stage}",
            "modules_install",
        ]
    )
    modules_root = cached_stage / f"lib/modules/{kernel_release}"
    for link_name in ("build", "source"):
        (modules_root / link_name).unlink(missing_ok=True)
    require_path(paths.arm64_aws_build_dir / "vmlinux", "ARM64 vmlinux")
    require_path(paths.arm64_aws_build_dir / "arch/arm64/boot/vmlinuz.efi", "ARM64 EFI kernel image")
    shutil.copy2(paths.arm64_aws_build_dir / "vmlinux", cache_dir / f"vmlinux-{kernel_release}")
    shutil.copy2(paths.arm64_aws_build_dir / "arch/arm64/boot/vmlinuz.efi", cache_dir / f"vmlinuz-{kernel_release}.efi")
    with tarfile.open(cache_dir / f"modules-{kernel_release}.tar.gz", "w:gz") as handle:
        handle.add(cached_stage / "lib/modules", arcname="lib/modules")
    shutil.rmtree(cached_stage, ignore_errors=True)
    if not _elf_has_btf(cache_dir / f"vmlinux-{kernel_release}"):
        die("generated ARM64 vmlinux is missing .BTF")
    if not _efi_binary_is_valid(cache_dir / f"vmlinuz-{kernel_release}.efi"):
        die("generated ARM64 EFI kernel image is invalid")
    if not _modules_tar_has_entry(cache_dir / f"modules-{kernel_release}.tar.gz", "modules.dep"):
        die("generated ARM64 modules archive is missing modules.dep")
    _link_cached_setup_artifacts(paths, cache_dir, kernel_release, f"vmlinuz-{kernel_release}.efi")
    return (
        kernel_release,
        (paths.artifact_dir / f"vmlinuz-{kernel_release}.efi").resolve(),
        (paths.artifact_dir / f"modules-{kernel_release}.tar.gz").resolve(),
    )


def build_arm64_kernel_artifacts(paths: AwsKernelPaths) -> tuple[str, Path, Path]:
    result: tuple[str, Path, Path] | None = None

    def _build() -> None:
        nonlocal result
        result = _build_arm64_kernel_artifacts_locked(paths)

    paths.artifact_dir.mkdir(parents=True, exist_ok=True)
    _with_lock(paths.arm64_kernel_build_lock_file, _build)
    if result is None:
        die("ARM64 kernel artifact build returned no result")
    return result


def ensure_arm64_kinsn_modules_ready(paths: AwsKernelPaths, *, state_kernel_release: str) -> None:
    def _ensure() -> None:
        expected_release = state_kernel_release.strip()
        if not expected_release:
            die("ARM64 kinsn module staging requires STATE_KERNEL_RELEASE")
        cache_dir = paths.arm64_setup_artifact_root / expected_release
        if not _cached_setup_artifacts_ready(cache_dir, expected_release, f"vmlinuz-{expected_release}.efi"):
            shutil.rmtree(cache_dir, ignore_errors=True)
            _build_arm64_kernel_artifacts_locked(paths)
        if paths.arm64_aws_base_config.is_file() and not _arm64_build_config_matches_aws_base(paths):
            _build_arm64_kernel_artifacts_locked(paths)
        current_build_release = (paths.arm64_aws_build_dir / "include/config/kernel.release").read_text(encoding="utf-8").strip() if (paths.arm64_aws_build_dir / "include/config/kernel.release").is_file() else ""
        if current_build_release != expected_release:
            _build_arm64_kernel_artifacts_locked(paths)
        if not _arm64_cached_kinsn_modules_ready(cache_dir, expected_release):
            shutil.rmtree(_arm64_cached_kinsn_modules_dir(cache_dir), ignore_errors=True)
            _build_arm64_kinsn_modules_into_cache(paths, cache_dir)
        if not _arm64_cached_kinsn_modules_ready(cache_dir, expected_release):
            die(f"ARM64 cached kinsn modules are missing or invalid for {expected_release}")
        stage_module_binaries(_arm64_cached_kinsn_modules_dir(cache_dir), paths.arm64_kinsn_module_stage_dir)

    _with_lock(paths.arm64_kernel_build_lock_file, _ensure)


def _ensure_arm64_worktree(paths: AwsKernelPaths) -> None:
    paths.arm64_worktree_dir.parent.mkdir(parents=True, exist_ok=True)
    _run_passthrough(["git", "-C", str(paths.kernel_dir), "worktree", "prune"])
    head = _run(["git", "-C", str(paths.kernel_dir), "rev-parse", "HEAD"]).stdout.strip()
    if not head:
        die("failed to resolve linux-framework HEAD for ARM64 worktree")
    if not (paths.arm64_worktree_dir / ".git").exists():
        _run_passthrough(
            [
                "git",
                "-C",
                str(paths.kernel_dir),
                "worktree",
                "add",
                "--detach",
                str(paths.arm64_worktree_dir),
                head,
            ]
        )
        return
    _run_passthrough(
        [
            "git",
            "-C",
            str(paths.arm64_worktree_dir),
            "checkout",
            "--detach",
            head,
        ]
    )
