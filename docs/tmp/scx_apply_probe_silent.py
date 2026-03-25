#!/usr/bin/env python3
from __future__ import annotations

import os
import signal
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path("/home/yunwei37/workspace/bpf-benchmark")
SCX_BIN = ROOT / "runner" / "repos" / "scx" / "target" / "release" / "scx_rusty"
DAEMON_BIN = ROOT / "daemon" / "target" / "release" / "bpfrejit-daemon"
SCX_STDOUT = Path("/tmp/scx_probe_silent.stdout")
SCX_STDERR = Path("/tmp/scx_probe_silent.stderr")
PROGRESS_LOG = ROOT / "docs" / "tmp" / "20260325" / "scx_apply_probe_silent.progress.log"


def log_progress(message: str) -> None:
    with PROGRESS_LOG.open("a") as fh:
        fh.write(message + "\n")
        fh.flush()
        os.fsync(fh.fileno())


def main() -> int:
    PROGRESS_LOG.write_text("")
    so = SCX_STDOUT.open("w")
    se = SCX_STDERR.open("w")
    proc = subprocess.Popen(
        [str(SCX_BIN), "--stats", "1"],
        stdout=so,
        stderr=se,
        cwd=ROOT,
        text=True,
    )
    try:
        log_progress("scx_started")
        time.sleep(3)
        log_progress("before_enumerate")

        enum = subprocess.run(
            [str(DAEMON_BIN), "enumerate"],
            cwd=ROOT,
            capture_output=True,
            text=True,
        )
        log_progress(f"enumerate_rc={enum.returncode}")
        if enum.returncode != 0:
            return enum.returncode

        log_progress("before_apply_20")
        result = subprocess.run(
            [str(DAEMON_BIN), "apply", "20"],
            cwd=ROOT,
            capture_output=True,
            text=True,
        )
        log_progress(f"apply20_rc={result.returncode}")

        out = ROOT / "docs" / "tmp" / "20260325" / "scx_apply_probe_silent"
        out.mkdir(parents=True, exist_ok=True)
        (out / "enumerate.stdout").write_text(enum.stdout)
        (out / "enumerate.stderr").write_text(enum.stderr)
        (out / "apply.stdout").write_text(result.stdout)
        (out / "apply.stderr").write_text(result.stderr)
        return result.returncode
    finally:
        try:
            os.kill(proc.pid, signal.SIGTERM)
        except ProcessLookupError:
            pass
        try:
            proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            try:
                os.kill(proc.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass
            proc.wait()
        so.close()
        se.close()


if __name__ == "__main__":
    raise SystemExit(main())
