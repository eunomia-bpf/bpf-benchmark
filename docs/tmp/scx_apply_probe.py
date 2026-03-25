#!/usr/bin/env python3
from __future__ import annotations

import os
import signal
import subprocess
import sys
import time
import argparse
from pathlib import Path


ROOT = Path("/home/yunwei37/workspace/bpf-benchmark")
SCX_BIN = ROOT / "runner" / "repos" / "scx" / "target" / "release" / "scx_rusty"
DAEMON_BIN = ROOT / "daemon" / "target" / "release" / "bpfrejit-daemon"
SCX_STDOUT = Path("/tmp/scx_probe.stdout")
SCX_STDERR = Path("/tmp/scx_probe.stderr")
PROGRESS_LOG = ROOT / "docs" / "tmp" / "20260325" / "scx_apply_probe.progress.log"


def parse_struct_ops_ids(stdout: str) -> list[int]:
    ids: list[int] = []
    for line in stdout.splitlines():
        fields = line.split()
        if len(fields) < 4 or not fields[0].isdigit():
            continue
        prog_type = fields[1]
        if prog_type != "27":
            continue
        ids.append(int(fields[0]))
    return ids


def tail(text: str, *, max_lines: int = 40) -> str:
    lines = text.splitlines()
    if len(lines) <= max_lines:
        return text
    return "\n".join(lines[-max_lines:])


def log_progress(message: str) -> None:
    line = f"{message}\n"
    with PROGRESS_LOG.open("a") as fh:
        fh.write(line)
        fh.flush()
        os.fsync(fh.fileno())


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("prog_ids", nargs="*", type=int)
    parser.add_argument(
        "--keep-going",
        action="store_true",
        help="continue to later program ids after a non-zero apply rc",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
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
        time.sleep(3)

        enum = subprocess.run(
            [str(DAEMON_BIN), "enumerate"],
            cwd=ROOT,
            capture_output=True,
            text=True,
        )
        sys.stdout.write(enum.stdout)
        sys.stderr.write(enum.stderr)
        if enum.returncode != 0:
            print(f"ENUMERATE failed rc={enum.returncode}", flush=True)
            return enum.returncode

        prog_ids = args.prog_ids or parse_struct_ops_ids(enum.stdout)
        print(f"STRUCT_OPS_IDS={prog_ids}", flush=True)
        log_progress(f"STRUCT_OPS_IDS={prog_ids}")

        final_rc = 0
        for prog_id in prog_ids:
            print(f"APPLY {prog_id}", flush=True)
            log_progress(f"APPLY {prog_id}")
            result = subprocess.run(
                [str(DAEMON_BIN), "apply", str(prog_id)],
                cwd=ROOT,
                capture_output=True,
                text=True,
            )
            print(f"APPLY {prog_id} rc={result.returncode}", flush=True)
            log_progress(f"APPLY {prog_id} rc={result.returncode}")
            if result.stdout:
                print(tail(result.stdout), flush=True)
            if result.stderr:
                print(tail(result.stderr), file=sys.stderr, flush=True)
            if result.returncode != 0:
                final_rc = result.returncode
                if not args.keep_going:
                    return final_rc

        return final_rc
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
        try:
            sys.stdout.write(SCX_STDERR.read_text())
        except OSError:
            pass


if __name__ == "__main__":
    raise SystemExit(main())
