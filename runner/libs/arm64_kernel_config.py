from __future__ import annotations

import argparse
import os
import subprocess
from functools import partial
from pathlib import Path
from runner.libs.cli_support import fail

_die = partial(fail, "arm64-kernel-config")


def _run(command: list[str], *, input_text: str | None = None, env: dict[str, str] | None = None) -> None:
    completed = subprocess.run(
        command,
        input=input_text,
        env=env,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _scripts_config(worktree: Path, config_path: Path, *args: str) -> None:
    _run([str(worktree / "scripts/config"), "--file", str(config_path), *args])


def apply_repo_required_config(worktree: Path, config_path: Path) -> None:
    _scripts_config(
        worktree,
        config_path,
        "-e",
        "BPF",
        "-e",
        "BPF_SYSCALL",
        "-e",
        "BPF_JIT",
        "-e",
        "BPF_LSM",
        "-e",
        "SCHED_CLASS_EXT",
        "-e",
        "TRACEPOINTS",
        "-e",
        "EVENT_TRACING",
        "-e",
        "TRACING",
        "-e",
        "FTRACE",
        "-e",
        "FUNCTION_TRACER",
        "-e",
        "DYNAMIC_FTRACE",
        "-e",
        "DYNAMIC_FTRACE_WITH_REGS",
        "-e",
        "DYNAMIC_FTRACE_WITH_DIRECT_CALLS",
        "-e",
        "DYNAMIC_FTRACE_WITH_ARGS",
        "-e",
        "FTRACE_SYSCALLS",
        "-e",
        "KPROBES",
        "-e",
        "KPROBES_ON_FTRACE",
        "-e",
        "KPROBE_EVENTS",
        "-e",
        "UPROBE_EVENTS",
        "-e",
        "BPF_EVENTS",
        "-e",
        "TRACING_MAP",
        "-e",
        "DEBUG_INFO",
        "-d",
        "DEBUG_INFO_REDUCED",
        "-d",
        "DEBUG_INFO_SPLIT",
        "-e",
        "DEBUG_INFO_BTF",
        "-d",
        "DEBUG_INFO_BTF_MODULES",
        "-e",
        "IPV6",
        "-e",
        "MPTCP",
        "-e",
        "MPTCP_IPV6",
        "-e",
        "NET_SCH_FQ",
        "-e",
        "NET_SCH_BPF",
        "-m",
        "NET_CLS_BPF",
        "-m",
        "NET_ACT_BPF",
        "-e",
        "NF_CONNTRACK_MARK",
    )


def finalize_kernel_config(worktree: Path, build_dir: Path, cross_compile: str) -> None:
    env = os.environ.copy()
    payload = ("\n" * 65536)
    _run(
        [
            "make",
            "-C",
            str(worktree),
            f"O={build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={cross_compile}",
            "olddefconfig",
        ],
        input_text=payload,
        env=env,
    )


def generate_local_config(worktree: Path, build_dir: Path, cross_compile: str) -> None:
    build_dir.mkdir(parents=True, exist_ok=True)
    _run(
        [
            "make",
            "-C",
            str(worktree),
            f"O={build_dir}",
            "ARCH=arm64",
            f"CROSS_COMPILE={cross_compile}",
            "defconfig",
        ]
    )
    config_path = build_dir / ".config"
    apply_repo_required_config(worktree, config_path)
    _scripts_config(
        worktree,
        config_path,
        "-e",
        "VIRTIO",
        "-e",
        "VIRTIO_BLK",
        "-e",
        "VIRTIO_NET",
        "-e",
        "NET_9P",
        "-e",
        "9P_FS",
        "-e",
        "NET_9P_VIRTIO",
        "-e",
        "PCI",
        "-e",
        "VIRTIO_PCI",
        "-e",
        "VIRTIO_MMIO",
        "-e",
        "BLK_DEV_INITRD",
        "-e",
        "DEVTMPFS",
        "-e",
        "DEVTMPFS_MOUNT",
        "-e",
        "TMPFS",
        "-e",
        "TMPFS_POSIX_ACL",
        "-e",
        "SERIAL_AMBA_PL011",
        "-e",
        "SERIAL_AMBA_PL011_CONSOLE",
    )
    finalize_kernel_config(worktree, build_dir, cross_compile)


def generate_aws_config(worktree: Path, build_dir: Path, cross_compile: str, base_config: Path) -> None:
    if not base_config.is_file():
        _die("ARM64_BASE_CONFIG must point to a readable AL2023 baseline config for AWS ARM64 kernel config generation")
    build_dir.mkdir(parents=True, exist_ok=True)
    config_path = build_dir / ".config"
    config_path.write_bytes(base_config.read_bytes())
    ena_mode = ""
    config_text = config_path.read_text(encoding="utf-8", errors="replace")
    if "CONFIG_ENA_ETHERNET=y" in config_text:
        ena_mode = "y"
    elif "CONFIG_ENA_ETHERNET=m" in config_text:
        ena_mode = "m"
    apply_repo_required_config(worktree, config_path)
    _scripts_config(
        worktree,
        config_path,
        "-d",
        "LOCALVERSION_AUTO",
        "-e",
        "NET_VENDOR_AMAZON",
        "-m",
        "ENA_ETHERNET",
    )
    if ena_mode == "y":
        _scripts_config(worktree, config_path, "-e", "NET_VENDOR_AMAZON", "-e", "ENA_ETHERNET")
    elif ena_mode == "m":
        _scripts_config(worktree, config_path, "-e", "NET_VENDOR_AMAZON", "-m", "ENA_ETHERNET")
    finalize_kernel_config(worktree, build_dir, cross_compile)


def main(argv: list[str] | None = None) -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("mode", choices=("local", "aws"))
    parser.add_argument("worktree")
    parser.add_argument("build_dir")
    parser.add_argument("cross_compile", nargs="?", default="aarch64-linux-gnu-")
    args = parser.parse_args(argv)
    worktree = Path(args.worktree)
    build_dir = Path(args.build_dir)
    if args.mode == "local":
        generate_local_config(worktree, build_dir, args.cross_compile)
        return
    if args.mode == "aws":
        generate_aws_config(worktree, build_dir, args.cross_compile, Path(os.environ.get("ARM64_BASE_CONFIG", "")))
        return
    _die(f"unsupported mode: {args.mode}")


if __name__ == "__main__":
    main()
