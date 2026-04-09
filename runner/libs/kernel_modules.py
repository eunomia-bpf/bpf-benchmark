from __future__ import annotations

import os
from pathlib import Path

from . import run_command, tail_text, which


def repo_kernel_modules_root() -> Path:
    override = os.environ.get("BPFREJIT_KERNEL_MODULES_ROOT", "").strip()
    if not override:
        raise RuntimeError("BPFREJIT_KERNEL_MODULES_ROOT is required")
    root = Path(override).expanduser().resolve()
    release_dir = root / "lib" / "modules" / os.uname().release
    if not release_dir.is_dir():
        raise RuntimeError(
            "repo kernel module tree is missing for the running kernel: "
            f"{release_dir}"
        )
    return root


def load_kernel_module(module_name: str, *module_args: str, timeout: int | float = 10) -> None:
    modprobe_binary = which("modprobe")
    if modprobe_binary is None:
        raise RuntimeError(f"modprobe is required to load kernel module {module_name!r}")
    completed = run_command(
        [
            modprobe_binary,
            "-d",
            str(repo_kernel_modules_root()),
            module_name,
            *module_args,
        ],
        check=False,
        timeout=timeout,
    )
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"modprobe {module_name} failed: {details}")
