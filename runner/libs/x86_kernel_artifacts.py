from __future__ import annotations

import argparse
import fcntl
import os
import shutil
import subprocess
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail, require_path


die = partial(fail, "x86-kernel-artifacts")

KERNEL_DIR = ROOT_DIR / "vendor" / "linux-framework"
DEFCONFIG_SRC = ROOT_DIR / "vendor" / "bpfrejit_defconfig"
KINSN_MODULE_DIR = ROOT_DIR / "module" / "x86"
KERNEL_BUILD_LOCK = ROOT_DIR / ".cache" / "kernel-build.lock"
VIRTME_MODULE_STAGE = KERNEL_DIR / ".virtme_mods"
VIRTME_HOSTFS_MODULES = (
    "drivers/block/null_blk/null_blk.ko",
    "drivers/net/veth.ko",
    "net/ipv4/ip_tunnel.ko",
    "net/ipv4/tunnel4.ko",
    "net/ipv4/ipip.ko",
    "net/sched/sch_netem.ko",
    "fs/netfs/netfs.ko",
    "net/9p/9pnet.ko",
    "net/9p/9pnet_virtio.ko",
    "fs/9p/9p.ko",
    "fs/fuse/virtiofs.ko",
    "fs/overlayfs/overlay.ko",
)
VIRTME_HOSTFS_MODULE_ORDER = (
    "drivers/block/null_blk/null_blk.o",
    "drivers/net/veth.o",
    "net/ipv4/ip_tunnel.o",
    "net/ipv4/tunnel4.o",
    "net/ipv4/ipip.o",
    "net/sched/sch_netem.o",
    "fs/netfs/netfs.o",
    "net/9p/9pnet.o",
    "net/9p/9pnet_virtio.o",
    "fs/9p/9p.o",
    "fs/fuse/virtiofs.o",
    "fs/overlayfs/overlay.o",
)


def _run(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    completed = subprocess.run(command, cwd=cwd, env=env, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _run_capture(
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
        details = completed.stderr.strip() or completed.stdout.strip() or "command failed"
        die(f"{details}: {' '.join(command)}")
    return completed


def _with_lock(lock_path: Path, fn) -> None:
    lock_path.parent.mkdir(parents=True, exist_ok=True)
    with lock_path.open("w", encoding="utf-8") as handle:
        fcntl.flock(handle.fileno(), fcntl.LOCK_EX)
        try:
            fn()
        finally:
            fcntl.flock(handle.fileno(), fcntl.LOCK_UN)


def _sync_config(kernel_dir: Path, defconfig_src: Path) -> None:
    config_path = kernel_dir / ".config"
    scripts_config = kernel_dir / "scripts" / "config"
    require_path(defconfig_src, tag="x86-kernel-artifacts", description="x86 defconfig source")
    require_path(scripts_config, tag="x86-kernel-artifacts", description="kernel scripts/config")
    if not config_path.is_file() or config_path.read_bytes() != defconfig_src.read_bytes():
        shutil.copy2(defconfig_src, config_path)
    _run(
        [
            str(scripts_config),
            "--file",
            str(config_path),
            "--enable",
            "UNWINDER_ORC",
            "--disable",
            "UNWINDER_FRAME_POINTER",
            "--set-str",
            "SYSTEM_TRUSTED_KEYS",
            "",
            "--set-str",
            "SYSTEM_REVOCATION_KEYS",
            "",
        ]
    )
    _run(["make", "-C", str(kernel_dir), "olddefconfig"])


def _kernel_release(kernel_dir: Path) -> str:
    release_path = kernel_dir / "include" / "config" / "kernel.release"
    require_path(release_path, tag="x86-kernel-artifacts", description="kernel release file")
    release = release_path.read_text(encoding="utf-8").strip()
    if not release:
        die(f"kernel release file is empty: {release_path}")
    return release


def _stage_virtme_modules(kernel_dir: Path) -> None:
    kernel_release = _kernel_release(kernel_dir)
    stage_dir = kernel_dir / ".virtme_mods"
    tmp_stage = kernel_dir / ".virtme_mods.tmp"
    prev_stage = kernel_dir / ".virtme_mods.prev"
    _run(["make", "-C", str(kernel_dir), f"INSTALL_MOD_PATH={tmp_stage}", "modules_install"])
    modules_root = tmp_stage / "lib" / "modules" / kernel_release
    for link_name in ("build", "source"):
        (modules_root / link_name).unlink(missing_ok=True)
    for module in VIRTME_HOSTFS_MODULES:
        installed_path = modules_root / "kernel" / module
        if not installed_path.is_file():
            die(f"missing installed hostfs module: {installed_path}")
    shutil.rmtree(prev_stage, ignore_errors=True)
    if stage_dir.exists():
        stage_dir.rename(prev_stage)
    tmp_stage.rename(stage_dir)
    shutil.rmtree(prev_stage, ignore_errors=True)


def ensure_kvm_kernel_ready(
    *,
    kernel_dir: Path = KERNEL_DIR,
    defconfig_src: Path = DEFCONFIG_SRC,
    jobs: int | None = None,
    bzimage: Path | None = None,
) -> None:
    resolved_kernel_dir = kernel_dir.resolve()
    resolved_defconfig = defconfig_src.resolve()
    resolved_bzimage = bzimage.resolve() if bzimage is not None else (resolved_kernel_dir / "arch" / "x86" / "boot" / "bzImage")
    job_count = max(int(jobs or (os.cpu_count() or 1)), 1)

    def _build() -> None:
        _sync_config(resolved_kernel_dir, resolved_defconfig)
        _run(["make", "-C", str(resolved_kernel_dir), f"-j{job_count}", "bzImage", "modules_prepare"])
        if (resolved_kernel_dir / "vmlinux.symvers").is_file():
            shutil.copy2(resolved_kernel_dir / "vmlinux.symvers", resolved_kernel_dir / "Module.symvers")
        module_symvers = resolved_kernel_dir / "Module.symvers"
        if not module_symvers.is_file():
            module_symvers.write_text("", encoding="utf-8")
        _run(["make", "-C", str(resolved_kernel_dir), "-j1", *VIRTME_HOSTFS_MODULES])
        for module in VIRTME_HOSTFS_MODULES:
            built_path = resolved_kernel_dir / module
            if not built_path.is_file():
                die(f"missing built hostfs module: {built_path}")
        (resolved_kernel_dir / "modules.order").write_text(
            "\n".join(VIRTME_HOSTFS_MODULE_ORDER) + "\n",
            encoding="utf-8",
        )
        _stage_virtme_modules(resolved_kernel_dir)
        if not resolved_bzimage.is_file():
            die(f"missing built kernel image: {resolved_bzimage}")

    _with_lock(KERNEL_BUILD_LOCK, _build)


def stage_kinsn_modules(
    *,
    kernel_dir: Path = KERNEL_DIR,
    module_dir: Path = KINSN_MODULE_DIR,
    output_dir: Path,
) -> None:
    resolved_kernel_dir = kernel_dir.resolve()
    resolved_module_dir = module_dir.resolve()
    resolved_output_dir = output_dir.resolve()

    def _build() -> None:
        _run(["make", "-C", str(resolved_module_dir), f"KDIR={resolved_kernel_dir}", "clean"])
        _run(["make", "-C", str(resolved_module_dir), f"KDIR={resolved_kernel_dir}"])
        shutil.rmtree(resolved_output_dir, ignore_errors=True)
        resolved_output_dir.mkdir(parents=True, exist_ok=True)
        copied = False
        for module_path in sorted(resolved_module_dir.glob("*.ko")):
            shutil.copy2(module_path, resolved_output_dir / module_path.name)
            copied = True
        if not copied:
            die(f"no kinsn modules staged under {resolved_output_dir}")

    _with_lock(KERNEL_BUILD_LOCK, _build)


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest="action", required=True)

    kernel_parser = subparsers.add_parser("ensure-kvm-kernel")
    kernel_parser.add_argument("--kernel-dir", default=str(KERNEL_DIR))
    kernel_parser.add_argument("--defconfig", default=str(DEFCONFIG_SRC))
    kernel_parser.add_argument("--bzimage", default=str(KERNEL_DIR / "arch/x86/boot/bzImage"))
    kernel_parser.add_argument("--jobs", type=int, default=max(os.cpu_count() or 1, 1))

    kinsn_parser = subparsers.add_parser("stage-kinsn")
    kinsn_parser.add_argument("--kernel-dir", default=str(KERNEL_DIR))
    kinsn_parser.add_argument("--module-dir", default=str(KINSN_MODULE_DIR))
    kinsn_parser.add_argument("--output-dir", required=True)

    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    if args.action == "ensure-kvm-kernel":
        ensure_kvm_kernel_ready(
            kernel_dir=Path(args.kernel_dir),
            defconfig_src=Path(args.defconfig),
            jobs=int(args.jobs),
            bzimage=Path(args.bzimage),
        )
        return
    if args.action == "stage-kinsn":
        stage_kinsn_modules(
            kernel_dir=Path(args.kernel_dir),
            module_dir=Path(args.module_dir),
            output_dir=Path(args.output_dir),
        )
        return
    die(f"unsupported action: {args.action}")


if __name__ == "__main__":
    main()
