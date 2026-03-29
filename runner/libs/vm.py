from __future__ import annotations

import json
import os
import selectors
import shlex
import subprocess
import sys
import tempfile
import time
from pathlib import Path
from typing import Any, Callable, Sequence

from . import DEFAULT_VENV_ACTIVATE, ROOT_DIR, docs_tmp_dir, scratch_date_stamp
from .corpus import packet_batch_timeout_seconds, serialize_resolved_object
from .machines import resolve_machine, resolve_machine_executable


DEFAULT_VM_TARGET = os.environ.get("TARGET", "").strip() or "local-x86-vng"
DEFAULT_GUEST_NOFILE = 65536


def write_guest_script(
    commands: Sequence[str | Sequence[str]],
    *,
    nofile: int | None = None,
) -> Path:
    scratch_stamp = scratch_date_stamp()
    script_dir = docs_tmp_dir("guest-scripts", stamp=scratch_stamp)
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="tracee-e2e-guest-",
        suffix=".sh",
        dir=script_dir,
        delete=False,
    )
    # docs/tmp is mounted --rwdir in virtme-ng; use a dated vm-tmp subdirectory so
    # Python's tempfile module (and any subprocesses) can create temp files even
    # when the VM's /tmp is read-only (virtme-ng only mounts specific --rwdir paths).
    vm_tmp_dir = docs_tmp_dir("vm-tmp", stamp=scratch_stamp)
    with handle:
        handle.write("#!/bin/bash\nset -eu\n")
        handle.write(f"cd {shlex.quote(str(ROOT_DIR))}\n")
        handle.write('export PATH="/usr/local/sbin:$PATH"\n')
        handle.write(f"mkdir -p {shlex.quote(str(vm_tmp_dir))}\n")
        handle.write(f"export TMPDIR={shlex.quote(str(vm_tmp_dir))}\n")
        if DEFAULT_VENV_ACTIVATE.exists():
            handle.write(f". {shlex.quote(str(DEFAULT_VENV_ACTIVATE))}\n")
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


def build_vm_shell_command(
    *,
    kernel_image: Path,
    guest_exec: str,
    timeout_seconds: int,
    vng_binary: str,
    nofile: int | None = None,
) -> list[str]:
    command = [
        sys.executable,
        str(ROOT_DIR / "runner" / "scripts" / "run_vm_shell.py"),
        "--action",
        "vm-corpus",
        "--kernel-image",
        str(kernel_image),
        "--timeout",
        str(timeout_seconds),
        "--command",
        guest_exec,
    ]
    if nofile is not None:
        command.extend(["--nofile", str(int(nofile))])
    if vng_binary != str(resolve_machine_executable(target=DEFAULT_VM_TARGET, action="vm-corpus")):
        command.extend(["--vm-executable", vng_binary])
    return command


def build_guest_exec(
    argv: list[str],
    *,
    load_script: str | Path | None = None,
) -> str:
    # Load kinsn kernel modules before running the guest command so the daemon
    # can apply platform-specific rewrites (rotate, cond_select, extract).
    resolved_load_script = Path(load_script).resolve() if load_script is not None else ROOT_DIR / "module" / "load_all.sh"
    kinsn_load = f"{shlex.quote(str(resolved_load_script))} && "
    main_cmd = " ".join(shlex.quote(part) for part in argv)
    return kinsn_load + main_cmd


def _parse_guest_event(line: str) -> dict[str, Any] | None:
    text = line.strip()
    if not text or not text.startswith("{"):
        return None
    try:
        payload = json.loads(text)
    except json.JSONDecodeError:
        return None
    if not isinstance(payload, dict) or not isinstance(payload.get("kind"), str):
        return None
    return payload


def run_corpus_targets_in_guest_batch(
    *,
    targets: Sequence[object],
    guest_driver: str,
    runner: Path,
    daemon: Path,
    kernel_image: Path,
    btf_custom_path: Path,
    profile: str | None,
    repeat: int,
    batch_size: int,
    timeout_seconds: int,
    vng_binary: str,
    kinsn_load_script: Path | None = None,
    on_guest_info: Callable[[dict[str, Any]], None] | None = None,
    on_record: Callable[[int, dict[str, Any]], None] | None = None,
) -> dict[str, Any]:
    batch_tmp_dir = docs_tmp_dir("corpus-rejit-batch")
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-rejit-vm-batch-",
        suffix=".json",
        dir=batch_tmp_dir,
        delete=False,
    )
    result_handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-rejit-vm-batch-result-",
        suffix=".json",
        dir=batch_tmp_dir,
        delete=False,
    )
    try:
        guest_target_payload = {
            "objects": [serialize_resolved_object(obj) for obj in targets],
        }
        with handle:
            json.dump(guest_target_payload, handle)
            handle.write("\n")
        target_path = Path(handle.name)
        with result_handle:
            json.dump({"records": []}, result_handle)
            result_handle.write("\n")
        result_path = Path(result_handle.name)
        guest_argv = [
            "python3",
            guest_driver,
            "--guest-target-json",
            str(target_path),
            "--guest-result-json",
            str(result_path),
            "--runner",
            str(runner),
            "--daemon",
            str(daemon),
            "--btf-custom-path",
            str(btf_custom_path),
            "--repeat",
            str(repeat),
            "--batch-size",
            str(batch_size),
            "--timeout",
            str(timeout_seconds),
        ]
        if profile:
            guest_argv.extend(["--profile", profile])
        guest_exec = build_guest_exec(guest_argv, load_script=kinsn_load_script)
        timeout_limit = packet_batch_timeout_seconds(len(targets), timeout_seconds)
        command = build_vm_shell_command(
            kernel_image=kernel_image,
            guest_exec=guest_exec,
            timeout_seconds=timeout_limit,
            vng_binary=vng_binary,
            nofile=DEFAULT_GUEST_NOFILE,
        )
        start = time.monotonic()
        process = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        selector = selectors.DefaultSelector()
        assert process.stdout is not None
        assert process.stderr is not None
        selector.register(process.stdout, selectors.EVENT_READ, data="stdout")
        selector.register(process.stderr, selectors.EVENT_READ, data="stderr")

        stdout_chunks: list[str] = []
        stderr_chunks: list[str] = []
        diagnostic_stdout_chunks: list[str] = []
        guest_info: dict[str, Any] | None = None
        emitted_records = 0
        timed_out = False
        guest_result_mtime_ns: int | None = None
        preserve_debug_artifacts = False
        last_heartbeat = start

        def sync_guest_records() -> None:
            nonlocal emitted_records, guest_result_mtime_ns
            if not result_path.exists():
                return
            stat = result_path.stat()
            if guest_result_mtime_ns == stat.st_mtime_ns:
                return
            guest_result_mtime_ns = stat.st_mtime_ns
            try:
                payload = json.loads(result_path.read_text())
            except json.JSONDecodeError:
                return
            records_payload = payload.get("records")
            if not isinstance(records_payload, list):
                return
            while emitted_records < len(records_payload):
                record = records_payload[emitted_records]
                emitted_records += 1
                if isinstance(record, dict) and on_record is not None:
                    on_record(emitted_records, record)

        while selector.get_map():
            remaining = timeout_limit - (time.monotonic() - start)
            if remaining <= 0:
                timed_out = True
                process.kill()
                break
            ready = selector.select(timeout=min(1.0, remaining))
            sync_guest_records()
            now = time.monotonic()
            if now - last_heartbeat >= 60:
                print(
                    "vm-corpus heartbeat "
                    f"elapsed={int(now - start)}s "
                    f"records={emitted_records}/{len(targets)}",
                    flush=True,
                )
                last_heartbeat = now
            if not ready:
                continue
            for key, _ in ready:
                stream = key.fileobj
                line = stream.readline()
                if line == "":
                    selector.unregister(stream)
                    continue
                if key.data == "stdout":
                    stdout_chunks.append(line)
                    event = _parse_guest_event(line)
                    if event is None:
                        diagnostic_stdout_chunks.append(line)
                        continue
                    if event["kind"] == "guest_info":
                        payload = event.get("payload")
                        if isinstance(payload, dict):
                            guest_info = payload
                            if on_guest_info is not None:
                                on_guest_info(payload)
                        continue
                    if event["kind"] == "program_record":
                        record = event.get("record")
                        if isinstance(record, dict):
                            emitted_records += 1
                            if on_record is not None:
                                on_record(emitted_records, record)
                        continue
                    if event["kind"] == "program_progress":
                        continue
                    diagnostic_stdout_chunks.append(line)
                else:
                    stderr_chunks.append(line)
        selector.close()

        try:
            process.wait(timeout=5)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()

        remaining_stdout = process.stdout.read() if process.stdout is not None else ""
        remaining_stderr = process.stderr.read() if process.stderr is not None else ""
        if remaining_stdout:
            for line in remaining_stdout.splitlines(keepends=True):
                stdout_chunks.append(line)
                event = _parse_guest_event(line)
                if event is None:
                    diagnostic_stdout_chunks.append(line)
                    continue
                if event["kind"] == "guest_info":
                    payload = event.get("payload")
                    if isinstance(payload, dict):
                        guest_info = payload
                        if on_guest_info is not None:
                            on_guest_info(payload)
                    continue
                if event["kind"] == "program_record":
                    record = event.get("record")
                    if isinstance(record, dict):
                        emitted_records += 1
                        if on_record is not None:
                            on_record(emitted_records, record)
                    continue
                if event["kind"] == "program_progress":
                    continue
                diagnostic_stdout_chunks.append(line)
        if remaining_stderr:
            stderr_chunks.append(remaining_stderr)
        sync_guest_records()

        stdout = "".join(stdout_chunks)
        stderr = "".join(stderr_chunks)
        diagnostic_stdout = "".join(diagnostic_stdout_chunks)
        ok = process.returncode == 0 and not timed_out and guest_info is not None and emitted_records == len(targets)
        error = None
        if timed_out:
            error = f"timeout after {timeout_limit}s"
        elif process.returncode != 0:
            lines = [line.strip() for line in (stderr + "\n" + stdout).splitlines() if line.strip()]
            error = f"{lines[-1]} (exit={process.returncode})" if lines else f"command failed (exit={process.returncode})"
        elif guest_info is None:
            error = "guest batch missing guest_info"
        elif emitted_records != len(targets):
            error = f"guest batch emitted {emitted_records}/{len(targets)} records"

        debug_artifacts: dict[str, str] | None = None
        if error is not None:
            preserve_debug_artifacts = True
            debug_artifacts = {}
            if target_path.exists():
                debug_artifacts["target_json"] = str(target_path)
            if result_path.exists():
                debug_artifacts["result_json"] = str(result_path)
            for suffix, text in (
                ("stdout_log", stdout),
                ("stderr_log", stderr),
                ("diagnostic_stdout_log", diagnostic_stdout),
            ):
                if not text:
                    continue
                log_path = result_path.with_name(f"{result_path.name}.{suffix}.txt")
                log_path.write_text(text)
                debug_artifacts[suffix] = str(log_path)
            if not debug_artifacts:
                debug_artifacts = None

        return {
            "invocation": {
                "ok": ok,
                "command": command,
                "returncode": process.returncode,
                "timed_out": timed_out,
                "duration_seconds": time.monotonic() - start,
                "stdout": stdout,
                "stderr": stderr,
                "diagnostic_stdout": diagnostic_stdout,
                "sample": None,
                "error": error,
                "debug_artifacts": debug_artifacts,
            },
            "guest_info": guest_info,
            "records_emitted": emitted_records,
        }
    finally:
        if not locals().get("preserve_debug_artifacts", False):
            Path(handle.name).unlink(missing_ok=True)
            Path(result_handle.name).unlink(missing_ok=True)


__all__ = [
    "build_guest_exec",
    "build_vm_shell_command",
    "DEFAULT_VM_TARGET",
    "build_vng_command",
    "run_corpus_targets_in_guest_batch",
    "run_in_vm",
    "wrap_with_vm_lock",
    "write_guest_script",
]
