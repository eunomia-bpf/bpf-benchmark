from __future__ import annotations

import os
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Sequence

from . import DEFAULT_VENV_ACTIVATE, ROOT_DIR, which
from .machines import resolve_machine, resolve_machine_executable


DEFAULT_VM_TARGET = os.environ.get("TARGET", "").strip() or "local-x86-vng"


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
    return script_path


def wrap_with_vm_lock(
    command: Sequence[str],
    *,
    target: str | None = None,
    action: str | None = None,
) -> list[str]:
    wrapper = ROOT_DIR / "runner" / "scripts" / "with_vm_lock.py"
    locked = [sys.executable, str(wrapper)]
    if target:
        locked.extend(["--target", target])
    if action:
        locked.extend(["--action", action])
    locked.append("--")
    locked.extend(str(part) for part in command)
    return locked


def build_vng_command(
    *,
    kernel_path: str | Path,
    guest_exec: str,
    cpus: int | None = None,
    mem: str | None = None,
    vm_executable: str | Path | None = None,
    target: str = DEFAULT_VM_TARGET,
    action: str | None = None,
    networks: Sequence[str] = (),
    rwdirs: Sequence[str | Path] = (),
) -> list[str]:
    machine = resolve_machine(target=target, action=action)
    if machine.backend != "vng":
        raise ValueError(
            f"machine target {machine.name} uses backend {machine.backend!r}; "
            "runner.libs.vm.build_vng_command only supports vng targets"
        )
    vng_path = str(vm_executable) if vm_executable is not None else str(
        resolve_machine_executable(target=target, action=action)
    )
    kernel = Path(kernel_path).resolve()
    resolved_cpus = max(1, int(cpus if cpus is not None else machine.cpus or 1))
    resolved_mem = str(mem if mem is not None else machine.memory or "4G")

    command = [
        vng_path,
        *machine.args,
        "--run",
        str(kernel),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--cpus",
        str(resolved_cpus),
        "--mem",
        resolved_mem,
    ]
    rwdir_values = [ROOT_DIR / "docs" / "tmp", ROOT_DIR]
    rwdir_values.extend(Path(value).resolve() for value in rwdirs)
    seen: set[Path] = set()
    for rwdir in rwdir_values:
        if rwdir in seen:
            continue
        seen.add(rwdir)
        command.extend(["--rwdir", str(rwdir)])
    for network in networks:
        command.extend(["--network", str(network)])
    command.extend(["--exec", guest_exec])
    return wrap_with_vm_lock(command, target=target, action=action)


def run_in_vm(
    kernel_path: str | Path,
    script_path: str | Path,
    cpus: int | None,
    mem: str | None,
    timeout: int,
    *,
    vm_executable: str | Path | None = None,
    target: str = DEFAULT_VM_TARGET,
    action: str | None = None,
    networks: Sequence[str] = (),
) -> subprocess.CompletedProcess[str]:
    script = Path(script_path).resolve()
    guest_path = str(script)
    command = build_vng_command(
        kernel_path=kernel_path,
        guest_exec=guest_path,
        cpus=cpus,
        mem=mem,
        vm_executable=vm_executable,
        target=target,
        action=action,
        networks=networks,
    )
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
    "DEFAULT_VM_TARGET",
    "build_vng_command",
    "run_in_vm",
    "wrap_with_vm_lock",
    "write_guest_script",
]
