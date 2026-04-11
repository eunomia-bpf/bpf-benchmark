from __future__ import annotations

import shlex
import shutil
import subprocess
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
        handle.write(f"chmod 1777 {shlex.quote(str(vm_tmp_dir))}\n")
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


def build_vng_command(
    *,
    kernel_path: str | Path,
    exec_path: str,
    cpus: int | None = None,
    mem: str | None = None,
    vm_executable: str | Path,
    machine_backend: str,
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
    vm_executable_text = str(vm_executable).strip()
    if not vm_executable_text:
        raise ValueError("vm_executable must be explicit")
    if Path(vm_executable_text).is_absolute() or "/" in vm_executable_text:
        launch_executable = str(Path(vm_executable_text).resolve())
    else:
        launch_executable = vm_executable_text
    resolved_cpus = max(1, int(cpus if cpus is not None else 1))
    resolved_mem = str(mem if mem is not None else "4G")
    kernel = Path(kernel_path).resolve()
    resolved_cwd = Path(cwd).resolve() if cwd is not None else ROOT_DIR

    command = [
        launch_executable,
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
    return command


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
    machine_backend: str,
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
        machine_backend=machine_backend,
        networks=networks,
        cwd=cwd,
        rwdirs=rwdirs,
    )
    try:
        return _run_command_with_script_pty(command, timeout)
    finally:
        script.unlink(missing_ok=True)


def _run_command_with_script_pty(command: list[str], timeout: int) -> subprocess.CompletedProcess[str]:
    if shutil.which("script") is None:
        return subprocess.CompletedProcess(
            command,
            127,
            "",
            "[kvm-executor][ERROR] missing required host command: script\n",
        )
    with tempfile.NamedTemporaryFile(prefix="vng-pty-log.", delete=False) as handle:
        log_path = Path(handle.name)
    try:
        completed = subprocess.run(
            ["script", "-qfec", shlex.join(command), str(log_path)],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout,
            check=False,
        )
        stdout = log_path.read_text(encoding="utf-8", errors="replace") if log_path.exists() else completed.stdout
        return subprocess.CompletedProcess(command, completed.returncode, stdout, completed.stderr)
    finally:
        log_path.unlink(missing_ok=True)


__all__ = [
    "build_vng_command",
    "run_in_vm",
    "write_guest_script",
]
