from __future__ import annotations

import os
import signal
import subprocess
import time
from typing import Callable, Sequence

from . import ROOT_DIR, resolve_bpftool_binary, run_json_command


_SHIM_GLIBC_PATH = "/usr/local/lib/bpfrejit/libbpfrejit_shim.so"
_SHIM_MUSL_PATH = "/usr/local/lib/bpfrejit/libbpfrejit_shim_musl.so"
_SHIM_SOCK_DIR = "/var/run/bpfrejit"


def _binary_is_musl(binary: str) -> bool:
    """Detect whether `binary` (or any --from chain via /usr/bin/env) links
    against musl by reading its PT_INTERP. Tracee ships as a musl static-pie."""
    try:
        with open(binary, "rb") as f:
            f.seek(0)
            header = f.read(4)
            if header != b"\x7fELF":
                return False
            f.seek(0)
            data = f.read()
        # PT_INTERP path is a NUL-terminated string referenced from one of the
        # program headers; rather than parsing ELF, just scan for the musl
        # loader signature. Both /lib/ld-musl-x86_64.so.1 and
        # /lib/ld-musl-aarch64.so.1 contain "ld-musl-".
        return b"ld-musl-" in data[: min(len(data), 65536)]
    except OSError:
        return False


def _shim_env_for(binary: str) -> dict[str, str]:
    """Build the LD_PRELOAD environment that attaches the bpfrejit shim to
    `binary`. Picks the musl-linked shim variant for musl binaries; otherwise
    the glibc variant. The shim looks for BPFREJIT_SHIM_SOCK_DIR to know where
    to place its per-pid socket (matching the runner's apply_rejit lookup)."""
    shim = _SHIM_MUSL_PATH if _binary_is_musl(binary) else _SHIM_GLIBC_PATH
    if not os.path.exists(shim):
        # Outside the runtime image (unit tests, host scripts), the shim
        # may not be installed. Run without it and let downstream rejit fail
        # at socket connect with a clear error.
        return {}
    return {"LD_PRELOAD": shim, "BPFREJIT_SHIM_SOCK_DIR": _SHIM_SOCK_DIR}


def start_agent(
    binary: str,
    args: Sequence[str] = (),
    env: dict[str, str] | None = None,
) -> subprocess.Popen[str]:
    merged_env = os.environ.copy()
    merged_env.update(_shim_env_for(binary))
    if env:
        merged_env.update(env)
    os.makedirs(_SHIM_SOCK_DIR, exist_ok=True)
    return subprocess.Popen(
        [binary, *args],
        cwd=ROOT_DIR,
        env=merged_env,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        bufsize=1,
    )


def wait_healthy(
    proc: subprocess.Popen[str],
    timeout: int | float,
    health_check_fn: Callable[[], bool],
) -> bool:
    deadline = time.monotonic() + float(timeout)
    while time.monotonic() < deadline:
        if proc.poll() is not None:
            return False
        if health_check_fn():
            return True
        time.sleep(0.5)
    return proc.poll() is None and health_check_fn()


def stop_agent(proc: subprocess.Popen[str], timeout: int | float = 10) -> int:
    if proc.poll() is None:
        proc.send_signal(signal.SIGINT)
        try:
            return proc.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            proc.terminate()
            try:
                return proc.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                proc.kill()
                return proc.wait(timeout=max(float(timeout), 100.0))
    return int(proc.returncode or 0)
def _payload_preview(payload: object, *, limit: int = 240) -> str:
    text = repr(payload)
    return text if len(text) <= limit else f"{text[:limit]}..."


def bpftool_prog_show_records() -> list[dict[str, object]]:
    payload = run_json_command([resolve_bpftool_binary(), "-j", "prog", "show"], timeout=300)
    if not isinstance(payload, list):
        raise RuntimeError(
            "bpftool prog show returned unexpected payload type "
            f"{type(payload).__name__}: {_payload_preview(payload)}"
        )
    records: list[dict[str, object]] = []
    for index, record in enumerate(payload):
        if not isinstance(record, dict):
            raise RuntimeError(
                "bpftool prog show returned unexpected record type "
                f"at index {index}: {type(record).__name__}: {_payload_preview(record)}"
            )
        records.append(dict(record))
    return records
