#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parents[2]
REPO_KERNEL_DIR = ROOT_DIR / "vendor/linux-framework"
REPO_KERNEL_IMAGE = REPO_KERNEL_DIR / "arch/x86/boot/bzImage"


def _run(command: list[str]) -> None:
    completed = subprocess.run(command, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _debug_enabled() -> bool:
    return os.environ.get("VNG_WRAPPER_DEBUG", "0").strip() == "1"


def _debug(message: str) -> None:
    if _debug_enabled():
        print(message, file=sys.stderr)


def _kernel_arg(args: list[str]) -> Path | None:
    for index, token in enumerate(args):
        if token == "--run" and index + 1 < len(args):
            try:
                return Path(args[index + 1]).resolve()
            except FileNotFoundError:
                return None
    return None


def ensure_repo_modules_fresh(args: list[str]) -> None:
    kernel_arg = _kernel_arg(args)
    if kernel_arg is None or kernel_arg != REPO_KERNEL_IMAGE.resolve():
        return

    hostfs_modules = [
        REPO_KERNEL_DIR / "drivers/block/null_blk/null_blk.ko",
        REPO_KERNEL_DIR / "drivers/net/veth.ko",
        REPO_KERNEL_DIR / "net/ipv4/ip_tunnel.ko",
        REPO_KERNEL_DIR / "net/ipv4/tunnel4.ko",
        REPO_KERNEL_DIR / "net/ipv4/ipip.ko",
        REPO_KERNEL_DIR / "net/sched/sch_netem.ko",
        REPO_KERNEL_DIR / "fs/netfs/netfs.ko",
        REPO_KERNEL_DIR / "net/9p/9pnet.ko",
        REPO_KERNEL_DIR / "net/9p/9pnet_virtio.ko",
        REPO_KERNEL_DIR / "fs/9p/9p.ko",
        REPO_KERNEL_DIR / "fs/fuse/virtiofs.ko",
        REPO_KERNEL_DIR / "fs/overlayfs/overlay.ko",
    ]
    rebuild_hostfs = any((not path.is_file()) or path.stat().st_mtime < REPO_KERNEL_IMAGE.stat().st_mtime for path in hostfs_modules)

    kinsn_dir = ROOT_DIR / "module/x86"
    kinsn_modules = sorted(kinsn_dir.glob("*.ko"))
    rebuild_kinsn = not kinsn_modules or any(path.stat().st_mtime < REPO_KERNEL_IMAGE.stat().st_mtime for path in kinsn_modules)

    if not rebuild_hostfs and not rebuild_kinsn:
        return
    if rebuild_hostfs:
        print(f"vng-wrapper: refreshing repo hostfs modules for {REPO_KERNEL_IMAGE.name}", file=sys.stderr)
        _run(["make", "-C", str(ROOT_DIR), "__virtme-hostfs-modules", f"BZIMAGE={REPO_KERNEL_IMAGE}"])
    if rebuild_kinsn:
        print(f"vng-wrapper: refreshing repo kinsn modules for {REPO_KERNEL_IMAGE.name}", file=sys.stderr)
        _run(["make", "-C", str(ROOT_DIR), "__kinsn-modules", f"BZIMAGE={REPO_KERNEL_IMAGE}"])


def _exec_vng(args: list[str]) -> None:
    ensure_repo_modules_fresh(args)
    _debug("vng-wrapper exec: vng " + " ".join(shlex.quote(arg) for arg in args))
    os.execvp("vng", ["vng", *args])


def _run_under_script(args: list[str]) -> None:
    with tempfile.NamedTemporaryFile(prefix="vng-wrapper-log.", delete=False) as handle:
        log_path = Path(handle.name)
    command = [sys.executable, str(Path(__file__).resolve()), "--exec-from-script", *args]
    try:
        completed = subprocess.run(
            ["script", "-qfec", shlex.join(command), str(log_path)],
            check=False,
        )
        if log_path.exists():
            sys.stdout.write(log_path.read_text(encoding="utf-8", errors="replace"))
        raise SystemExit(completed.returncode)
    finally:
        log_path.unlink(missing_ok=True)


def main(argv: list[str] | None = None) -> None:
    raw_args = list(sys.argv[1:] if argv is None else argv)
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument("--exec-from-script", action="store_true")
    known, remaining = parser.parse_known_args(raw_args)
    if known.exec_from_script:
        _exec_vng(remaining)
        return
    if all(os.isatty(fd) for fd in (0, 1, 2)):
        _exec_vng(remaining)
        return
    _run_under_script(remaining)


if __name__ == "__main__":
    main()
