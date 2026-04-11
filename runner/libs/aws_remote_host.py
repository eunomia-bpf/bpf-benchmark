from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

STANDARD_REMOTE_PATH = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"


def die(message: str) -> None:
    print(f"[aws-remote-host][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def run_checked(*command: str, sudo: bool = False, capture_output: bool = False) -> subprocess.CompletedProcess[str]:
    final_command = (["sudo"] if sudo and os.geteuid() != 0 else []) + list(command)
    env = os.environ.copy()
    path_entries: list[str] = []
    for entry in (STANDARD_REMOTE_PATH.split(":") + env.get("PATH", "").split(":")):
        if entry and entry not in path_entries: path_entries.append(entry)
    env["PATH"] = ":".join(path_entries)
    completed = subprocess.run(final_command, text=True, capture_output=capture_output, check=False, env=env)
    if completed.returncode != 0: raise SystemExit(completed.returncode)
    return completed


def _write_root_file(destination: Path, content: str) -> None:
    with tempfile.NamedTemporaryFile("w", encoding="utf-8", delete=False) as handle:
        handle.write(content); temp_path = Path(handle.name)
    try:
        run_checked("mkdir", "-p", str(destination.parent), sudo=True)
        run_checked("cp", str(temp_path), str(destination), sudo=True)
    finally: temp_path.unlink(missing_ok=True)


def cmd_prepare_dir(args: argparse.Namespace) -> None:
    path = Path(args.path)
    run_checked("mkdir", "-p", str(path), sudo=True)
    run_checked("chown", f"{os.getuid()}:{os.getgid()}", str(path), sudo=True)


def cmd_path_exists(args: argparse.Namespace) -> None:
    if not Path(args.path).exists(): raise SystemExit(1)


def cmd_uname_r(args: argparse.Namespace) -> None:
    del args; print(os.uname().release)


def cmd_root_volume_size_gb(args: argparse.Namespace) -> None:
    del args
    root_source = run_checked("findmnt", "-n", "-o", "SOURCE", "/", capture_output=True).stdout.strip()
    if not root_source: raise SystemExit(1)
    root_device = root_source
    if parent_kname := run_checked("lsblk", "-no", "PKNAME", root_source, capture_output=True).stdout.strip().splitlines():
        root_device = f"/dev/{parent_kname[0].strip()}"
    size_bytes_text = run_checked("lsblk", "-nb", "-o", "SIZE", root_device, capture_output=True).stdout.strip().splitlines()
    if not size_bytes_text or not size_bytes_text[0].strip().isdigit(): raise SystemExit(1)
    print((int(size_bytes_text[0].strip()) + 1073741824 - 1) // 1073741824)


def cmd_has_runtime_btf(args: argparse.Namespace) -> None:
    del args
    if not Path("/sys/kernel/btf/vmlinux").is_file() or Path("/sys/kernel/btf/vmlinux").stat().st_size <= 0: raise SystemExit(1)


def cmd_has_sched_ext(args: argparse.Namespace) -> None:
    del args
    if not Path("/sys/kernel/sched_ext/state").exists(): raise SystemExit(1)


def cmd_verify_base_prereqs(args: argparse.Namespace) -> None:
    for command_name in [t for t in args.commands_csv.split(",") if t]:
        if shutil.which(command_name, path=STANDARD_REMOTE_PATH) is None:
            die(f"required command is missing: {command_name}")


def cmd_print_kernel_config(args: argparse.Namespace) -> None:
    del args; release = os.uname().release
    if (boot_config := Path(f"/boot/config-{release}")).is_file():
        sys.stdout.write(boot_config.read_text(encoding="utf-8")); return
    if (proc_config := Path("/proc/config.gz")).is_file():
        sys.stdout.write(run_checked("zcat", str(proc_config), capture_output=True).stdout); return
    raise SystemExit(1)


def _staged_modules_root(stage_dir: Path, version: str) -> Path:
    modules_root = stage_dir / "lib" / "modules" / version
    if not modules_root.is_dir(): die(f"kernel modules are missing from {modules_root}")
    return modules_root


def cmd_setup_kernel_x86(args: argparse.Namespace) -> None:
    version = args.version; stage_dir = Path(args.stage_dir)
    modules_root = _staged_modules_root(stage_dir, version); target_root = Path("/lib/modules") / version
    run_checked("mkdir", "-p", str(target_root), sudo=True)
    run_checked("rsync", "-a", "--delete", f"{modules_root}/", f"{target_root}/", sudo=True)
    kernel_image = stage_dir / "boot" / "bzImage"
    run_checked("install", "-o", "root", "-g", "root", "-m", "0755", str(kernel_image), f"/boot/vmlinuz-{version}", sudo=True)
    run_checked("depmod", "-a", version, sudo=True)
    run_checked("dracut", "--force", "--no-hostonly", "--add-drivers", "nvme nvme-core xfs ext4 virtio_blk",
                f"/boot/initramfs-{version}.img", version, sudo=True)
    link_output = run_checked("ip", "-brief", "link", capture_output=True).stdout.splitlines()
    primary_netdev = next((line.split()[0] for line in link_output if line.split() and line.split()[0] != "lo"), "")
    if not primary_netdev: die("failed to detect primary network interface")
    primary_mac = Path(f"/sys/class/net/{primary_netdev}/address").read_text(encoding="utf-8").strip()
    if not primary_mac: die("failed to read primary network MAC")
    _write_root_file(Path("/etc/systemd/network/10-codex-ena.link"), f"[Match]\nMACAddress={primary_mac}\n\n[Link]\nName=ens5\n")
    _write_root_file(Path("/etc/systemd/network/10-codex-ena.network"),
                     f"[Match]\nMACAddress={primary_mac}\n\n[Network]\nDHCP=yes\nLinkLocalAddressing=yes\nIPv6AcceptRA=yes\n")
    run_checked("grubby", "--add-kernel", f"/boot/vmlinuz-{version}", "--initrd", f"/boot/initramfs-{version}.img",
                "--title", f"Codex x86 ({version})", "--copy-default", sudo=True)
    run_checked("grubby", "--set-default", f"/boot/vmlinuz-{version}", sudo=True)


def cmd_setup_kernel_arm64(args: argparse.Namespace) -> None:
    version = args.version; stage_dir = Path(args.stage_dir)
    modules_root = _staged_modules_root(stage_dir, version); target_root = Path("/lib/modules") / version
    run_checked("mkdir", "-p", str(target_root), sudo=True)
    run_checked("rsync", "-a", "--delete", f"{modules_root}/", f"{target_root}/", sudo=True)
    kernel_image = stage_dir / "boot" / "vmlinuz.efi"
    run_checked("install", "-o", "root", "-g", "root", "-m", "0755", str(kernel_image), f"/boot/vmlinuz-{version}", sudo=True)
    run_checked("depmod", "-a", version, sudo=True)
    run_checked("dracut", "--force", f"/boot/initramfs-{version}.img", version, sudo=True)
    run_checked("grubby", "--add-kernel", f"/boot/vmlinuz-{version}", "--initrd", f"/boot/initramfs-{version}.img",
                "--title", f"Codex ARM64 ({version})", "--copy-default", sudo=True)
    run_checked("grubby", "--set-default", f"/boot/vmlinuz-{version}", sudo=True)


def cmd_verify_kernel(args: argparse.Namespace) -> None:
    version = args.version
    print(os.uname().release)
    try:
        address_output = run_checked("ip", "-brief", "addr", "show", "ens5", capture_output=True).stdout
    except SystemExit:
        address_output = run_checked("ip", "-brief", "addr", capture_output=True).stdout
    sys.stdout.write(address_output)
    default_kernel = run_checked("grubby", "--default-kernel", sudo=True, capture_output=True).stdout.strip()
    print(default_kernel)
    if os.uname().release != version:
        raise SystemExit(1)
    if default_kernel != f"/boot/vmlinuz-{version}":
        raise SystemExit(1)
    if not Path("/sys/kernel/btf/vmlinux").is_file() or Path("/sys/kernel/btf/vmlinux").stat().st_size <= 0:
        raise SystemExit(1)
    if args.require_sched_ext == "1" and not Path("/sys/kernel/sched_ext/state").exists():
        raise SystemExit(1)


def cmd_run_workspace(args: argparse.Namespace) -> None:
    env = os.environ.copy()
    env["PYTHONPATH"] = args.workspace if not env.get("PYTHONPATH") else f"{args.workspace}:{env['PYTHONPATH']}"
    Path(args.log_path).parent.mkdir(parents=True, exist_ok=True)
    command = [args.remote_python, "-m", "runner.libs.suite_entrypoint", args.workspace, args.config_path]
    if os.geteuid() != 0:
        preserved = [f"{n}={v}" for n in ("PATH", "PYTHONPATH", "HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL")
                     if (v := env.get(n, "").strip())]
        command = ["sudo", "env", *preserved, *command]
    with Path(args.log_path).open("w", encoding="utf-8") as log_file:
        completed = subprocess.run(command, env=env, stdout=log_file, stderr=subprocess.STDOUT, check=False, text=True)
    if completed.returncode != 0: raise SystemExit(completed.returncode)

def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(prog="aws_remote_host.py")
    sp = parser.add_subparsers(dest="command", required=True)

    def _cmd(name: str, func, *args: str) -> None:
        sub = sp.add_parser(name)
        for a in args: sub.add_argument(a)
        sub.set_defaults(func=func)

    _cmd("prepare-dir", cmd_prepare_dir, "path")
    _cmd("path-exists", cmd_path_exists, "path")
    _cmd("uname-r", cmd_uname_r)
    _cmd("root-volume-size-gb", cmd_root_volume_size_gb)
    _cmd("has-runtime-btf", cmd_has_runtime_btf)
    _cmd("has-sched-ext", cmd_has_sched_ext)
    _cmd("verify-base-prereqs", cmd_verify_base_prereqs, "commands_csv")
    _cmd("print-kernel-config", cmd_print_kernel_config)
    _cmd("setup-kernel-x86", cmd_setup_kernel_x86, "version", "stage_dir")
    _cmd("setup-kernel-arm64", cmd_setup_kernel_arm64, "version", "stage_dir")
    _cmd("verify-kernel", cmd_verify_kernel, "version", "require_sched_ext")
    _cmd("run-workspace", cmd_run_workspace, "workspace", "config_path", "log_path", "remote_python")
    return parser


def main(argv: list[str] | None = None) -> None:
    parser = build_parser()
    args = parser.parse_args(argv)
    args.func(args)


if __name__ == "__main__":
    main()
