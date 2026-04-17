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


def kernel_module_is_builtin(module_name: str) -> bool:
    release_dir = repo_kernel_modules_root() / "lib" / "modules" / os.uname().release
    builtin_path = release_dir / "modules.builtin"
    if not builtin_path.is_file():
        return False
    normalized_name = module_name.replace("-", "_")
    with builtin_path.open("r", encoding="utf-8", errors="replace") as builtin_file:
        for raw_line in builtin_file:
            module_path = raw_line.strip()
            if not module_path:
                continue
            basename = Path(module_path).name
            if basename.endswith(".ko"):
                basename = basename[:-3]
            if basename.replace("-", "_") == normalized_name:
                return True
    return False


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
