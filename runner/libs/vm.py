from __future__ import annotations

import shlex
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Sequence

from . import ROOT_DIR, docs_tmp_dir, scratch_date_stamp


DEFAULT_GUEST_NOFILE = 65536


def write_guest_script(
    commands: Sequence[str | Sequence[str]],
    *,
    nofile: int | None = None,
    initial_cwd: str | Path | None = None,
) -> Path:
    scratch_stamp = scratch_date_stamp()
    script_dir = docs_tmp_dir("guest-scripts", stamp=scratch_stamp)
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="benchmark-guest-",
        suffix=".sh",
        dir=script_dir,
        delete=False,
    )
    # docs/tmp is mounted --rwdir in virtme-ng; use a dated vm-tmp subdirectory so
    # Python's tempfile module (and any subprocesses) can create temp files even
    # when the VM's /tmp is read-only (virtme-ng only mounts specific --rwdir paths).
    vm_tmp_dir = docs_tmp_dir("vm-tmp", stamp=scratch_stamp)
    resolved_initial_cwd = Path(initial_cwd).resolve() if initial_cwd is not None else ROOT_DIR
    with handle:
        handle.write("#!/bin/bash\nset -eu\n")
        handle.write(f"cd {shlex.quote(str(resolved_initial_cwd))}\n")
        handle.write('export PATH="/usr/local/sbin:$PATH"\n')
        handle.write(f"mkdir -p {shlex.quote(str(vm_tmp_dir))}\n")
        handle.write(f"export TMPDIR={shlex.quote(str(vm_tmp_dir))}\n")
        if nofile is not None:
            handle.write(f"ulimit -HSn {int(nofile)}\n")
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
    action: str | None = None,
    lock_scope: str,
    machine_name: str,
    backend: str,
    arch: str,
) -> list[str]:
    wrapper = ROOT_DIR / "runner" / "scripts" / "with_vm_lock.py"
    locked = [sys.executable, str(wrapper)]
    if action:
        locked.extend(["--action", action])
    locked.extend(["--lock-scope", lock_scope])
    locked.extend(["--machine-name", machine_name])
    locked.extend(["--backend", backend])
    locked.extend(["--arch", arch])
    locked.append("--")
    locked.extend(str(part) for part in command)
    return locked


def build_vng_command(
    *,
    kernel_path: str | Path,
    exec_path: str,
    cpus: int | None = None,
    mem: str | None = None,
    vm_executable: str | Path,
    action: str | None = None,
    machine_backend: str,
    machine_lock_scope: str,
    machine_name: str,
    machine_arch: str,
    networks: Sequence[str] = (),
    cwd: str | Path | None = None,
    rwdirs: Sequence[str | Path] = (),
) -> list[str]:
    resolved_backend = str(machine_backend).strip()
    if resolved_backend != "vng":
        raise ValueError(
            f"explicit machine backend {resolved_backend!r} is unsupported; "
            "runner.libs.vm.build_vng_command only supports vng"
        )
    resolved_machine_name = str(machine_name).strip()
    if not resolved_machine_name:
        raise ValueError("explicit vng machine configuration requires machine_name")
    resolved_machine_arch = str(machine_arch).strip()
    if not resolved_machine_arch:
        raise ValueError("explicit vng machine configuration requires machine_arch")
    resolved_lock_scope = str(machine_lock_scope).strip()
    if not resolved_lock_scope:
        raise ValueError("explicit vng machine configuration requires machine_lock_scope")
    resolved_vm_executable = Path(vm_executable).resolve()
    launch_prefix: list[str]
    if resolved_vm_executable.suffix == ".py":
        launch_prefix = [sys.executable, str(resolved_vm_executable)]
    else:
        launch_prefix = [str(resolved_vm_executable)]
    resolved_cpus = max(1, int(cpus if cpus is not None else 1))
    resolved_mem = str(mem if mem is not None else "4G")
    kernel = Path(kernel_path).resolve()
    resolved_cwd = Path(cwd).resolve() if cwd is not None else ROOT_DIR

    command = [
        *launch_prefix,
        "--run",
        str(kernel),
        "--cwd",
        str(resolved_cwd),
        "--disable-monitor",
        "--cpus",
        str(resolved_cpus),
        "--mem",
        resolved_mem,
    ]
    rwdir_values = [ROOT_DIR / "docs" / "tmp", resolved_cwd]
    rwdir_values.extend(Path(value).resolve() for value in rwdirs)
    seen: set[Path] = set()
    for rwdir in rwdir_values:
        if rwdir in seen:
            continue
        seen.add(rwdir)
        command.extend(["--rwdir", str(rwdir)])
    for network in networks:
        command.extend(["--network", str(network)])
    command.extend(["--exec", exec_path])
    return wrap_with_vm_lock(
        command,
        action=action,
        lock_scope=resolved_lock_scope,
        machine_name=resolved_machine_name,
        backend=resolved_backend,
        arch=resolved_machine_arch,
    )


def run_in_vm(
    kernel_path: str | Path,
    script_path: str | Path,
    cpus: int | None,
    mem: str | None,
    timeout: int,
    *,
    cwd: str | Path | None = None,
    rwdirs: Sequence[str | Path] = (),
    vm_executable: str | Path,
    action: str | None = None,
    machine_backend: str,
    machine_lock_scope: str,
    machine_name: str,
    machine_arch: str,
    networks: Sequence[str] = (),
) -> subprocess.CompletedProcess[str]:
    script = Path(script_path).resolve()
    guest_path = str(script)
    command = build_vng_command(
        kernel_path=kernel_path,
        exec_path=guest_path,
        cpus=cpus,
        mem=mem,
        vm_executable=vm_executable,
        action=action,
        machine_backend=machine_backend,
        machine_lock_scope=machine_lock_scope,
        machine_name=machine_name,
        machine_arch=machine_arch,
        networks=networks,
        cwd=cwd,
        rwdirs=rwdirs,
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
    "build_vng_command",
    "run_in_vm",
    "wrap_with_vm_lock",
    "write_guest_script",
]
