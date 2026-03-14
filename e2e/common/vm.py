from __future__ import annotations

import shlex
import subprocess
import tempfile
from pathlib import Path
from typing import Sequence

from . import DEFAULT_VENV_ACTIVATE, RESULTS_DIR, ROOT_DIR, chown_to_invoking_user, which


def write_guest_script(commands: Sequence[str | Sequence[str]]) -> Path:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="tracee-e2e-guest-",
        suffix=".sh",
        dir=ROOT_DIR,
        delete=False,
    )
    # docs/tmp is mounted --rwdir in virtme-ng; use a vm-tmp subdirectory so that
    # Python's tempfile module (and any subprocesses) can create temp files even
    # when the VM's /tmp is read-only (virtme-ng only mounts specific --rwdir paths).
    vm_tmp_dir = ROOT_DIR / "docs" / "tmp" / "vm-tmp"
    with handle:
        handle.write("#!/bin/bash\nset -eu\n")
        handle.write(f"cd {shlex.quote(str(ROOT_DIR))}\n")
        handle.write('export PATH="/usr/local/sbin:$PATH"\n')
        handle.write(f"mkdir -p {shlex.quote(str(vm_tmp_dir))}\n")
        handle.write(f"export TMPDIR={shlex.quote(str(vm_tmp_dir))}\n")
        if DEFAULT_VENV_ACTIVATE.exists():
            handle.write(f". {shlex.quote(str(DEFAULT_VENV_ACTIVATE))}\n")
        for command in commands:
            if isinstance(command, str):
                handle.write(command.rstrip() + "\n")
                continue
            handle.write(" ".join(shlex.quote(str(part)) for part in command) + "\n")
    script_path = Path(handle.name)
    script_path.chmod(0o755)
    chown_to_invoking_user(script_path)
    return script_path


def run_in_vm(
    kernel_path: str | Path,
    script_path: str | Path,
    cpus: int,
    mem: str,
    timeout: int,
    *,
    networks: Sequence[str] = (),
) -> subprocess.CompletedProcess[str]:
    vng = which("vng") or str(Path.home() / ".local" / "bin" / "vng")
    kernel = Path(kernel_path).resolve()
    script = Path(script_path).resolve()
    guest_path = f"./{script.relative_to(ROOT_DIR).as_posix()}"
    RESULTS_DIR.mkdir(parents=True, exist_ok=True)
    command = [
        vng,
        "--run",
        str(kernel),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--cpus",
        str(max(1, int(cpus))),
        "--mem",
        str(mem),
        "--rwdir",
        str(RESULTS_DIR),
        "--rwdir",
        str(ROOT_DIR / "docs" / "tmp"),
    ]
    for network in networks:
        command.extend(["--network", str(network)])
    command.extend(["--exec", guest_path])
    try:
        return subprocess.run(
            command,
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout,
            check=False,
        )
    finally:
        script.unlink(missing_ok=True)


__all__ = [
    "run_in_vm",
    "write_guest_script",
]
