from __future__ import annotations

import os
import shutil
import subprocess
import sys
from pathlib import Path

from runner.libs.prereq_contract import required_commands, tool_packages
from runner.libs.run_contract import load_manifest_environment


def die(message: str) -> "NoReturn":
    print(f"[aws-remote-prereqs][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def log(message: str) -> None:
    print(f"[aws-remote-prereqs] {message}", file=sys.stderr)


def have_cmd(command_name: str) -> bool:
    return shutil.which(command_name) is not None


def require_cmd(command_name: str) -> None:
    if not have_cmd(command_name):
        die(f"required command is missing: {command_name}")


def run_command(command: list[str], *, sudo: bool = False) -> None:
    final_command = list(command)
    if sudo and os.geteuid() != 0:
        if shutil.which("sudo") is None:
            die("AWS remote prereq setup requires sudo or root")
        final_command = ["sudo", *final_command]
    try:
        subprocess.run(final_command, check=True)
    except subprocess.CalledProcessError as exc:
        die(f"command failed ({exc.returncode}): {' '.join(final_command)}")


def dnf_install(packages: list[str]) -> None:
    if not packages:
        return
    run_command(["dnf", "-y", "install", *packages], sudo=True)


def install_base_packages() -> None:
    log(
        "Installing base AWS execution prerequisites "
        f"for {os.environ.get('RUN_TARGET_NAME', '')}/{os.environ.get('RUN_SUITE_NAME', '')}"
    )
    dnf_install(
        [
            "curl-minimal",
            "dracut",
            "elfutils-libelf",
            "file",
            "grubby",
            "gzip",
            "iproute",
            "kmod",
            "ncurses-libs",
            "procps-ng",
            "tar",
            "util-linux",
            "which",
            "zlib",
            "zstd",
        ]
    )


def install_explicit_runtime_packages() -> None:
    packages: list[str] = []
    for tool in (
        os.environ.get("RUN_BPFTOOL_BIN", "").strip(),
        os.environ.get("RUN_REMOTE_PYTHON_BIN", "").strip(),
    ):
        if not tool:
            continue
        for package_name in tool_packages("dnf", tool):
            if package_name not in packages:
                packages.append(package_name)
    dnf_install(packages)


def install_optional_base_packages() -> None:
    packages: list[str] = []
    python_bin = os.environ.get("RUN_REMOTE_PYTHON_BIN", "").strip()
    bpftool_bin = os.environ.get("RUN_BPFTOOL_BIN", "").strip()
    for tool in required_commands(mode="base"):
        if tool in {python_bin, bpftool_bin}:
            continue
        for package_name in tool_packages("dnf", tool):
            if package_name not in packages:
                packages.append(package_name)
    dnf_install(packages)


def verify_environment() -> None:
    for command_name in (
        os.environ.get("RUN_BPFTOOL_BIN", "").strip(),
        "curl",
        "dracut",
        "file",
        "grubby",
        "insmod",
        "ip",
        os.environ.get("RUN_REMOTE_PYTHON_BIN", "").strip(),
        "taskset",
        "tar",
    ):
        if command_name:
            require_cmd(command_name)
    for command_name in required_commands(mode="base"):
        if command_name:
            require_cmd(command_name)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 2:
        die("usage: aws_remote_prereqs.py <manifest_path> <stamp_path>")
    manifest_path = Path(args[0]).resolve()
    stamp_path = Path(args[1]).resolve()
    if not manifest_path.is_file():
        die(f"manifest is missing: {manifest_path}")
    load_manifest_environment(manifest_path)
    install_base_packages()
    install_explicit_runtime_packages()
    install_optional_base_packages()
    verify_environment()
    stamp_path.parent.mkdir(parents=True, exist_ok=True)
    stamp_path.touch()


if __name__ == "__main__":
    main()
