#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import signal
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path("/home/yunwei37/workspace/bpf-benchmark")
SCX_BIN = ROOT / "runner" / "repos" / "scx" / "target" / "release" / "scx_rusty"
DAEMON_BIN = ROOT / "daemon" / "target" / "release" / "bpfrejit-daemon"
OUTDIR = ROOT / "docs" / "tmp" / "20260325" / "scx_rejit_workload_probe"
SCX_STDOUT = OUTDIR / "scx.stdout"
SCX_STDERR = OUTDIR / "scx.stderr"
PROGRESS_LOG = OUTDIR / "progress.log"


def parse_struct_ops_ids(stdout: str) -> list[int]:
    ids: list[int] = []
    for line in stdout.splitlines():
        fields = line.split()
        if len(fields) < 4 or not fields[0].isdigit():
            continue
        if fields[1] != "27":
            continue
        ids.append(int(fields[0]))
    return ids


def log_progress(message: str) -> None:
    with PROGRESS_LOG.open("a") as fh:
        fh.write(f"{message}\n")
        fh.flush()
        os.fsync(fh.fileno())


def workload_command(name: str) -> list[str]:
    if name == "hackbench":
        return ["hackbench", "-g", "4", "-l", "1000"]
    if name == "stress-ng":
        return ["stress-ng", "--cpu", "4", "--timeout", "10s", "--metrics-brief"]
    if name == "sysbench":
        return ["sysbench", "cpu", "--threads=4", "--time=10", "run"]
    raise ValueError(f"unsupported workload: {name}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("workload", choices=["hackbench", "stress-ng", "sysbench"])
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    OUTDIR.mkdir(parents=True, exist_ok=True)
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
            check=False,
        )
        (OUTDIR / "enumerate.stdout").write_text(enum.stdout)
        (OUTDIR / "enumerate.stderr").write_text(enum.stderr)
        if enum.returncode != 0:
            log_progress(f"ENUMERATE rc={enum.returncode}")
            return enum.returncode

        prog_ids = parse_struct_ops_ids(enum.stdout)
        log_progress(f"STRUCT_OPS_IDS={prog_ids}")
        for prog_id in prog_ids:
            log_progress(f"APPLY {prog_id}")
            result = subprocess.run(
                [str(DAEMON_BIN), "apply", str(prog_id)],
                cwd=ROOT,
                capture_output=True,
                text=True,
                check=False,
            )
            (OUTDIR / f"apply-{prog_id}.stdout").write_text(result.stdout)
            (OUTDIR / f"apply-{prog_id}.stderr").write_text(result.stderr)
            log_progress(f"APPLY {prog_id} rc={result.returncode}")

        cmd = workload_command(args.workload)
        log_progress(f"WORKLOAD {args.workload} start")
        result = subprocess.run(
            cmd,
            cwd=ROOT,
            capture_output=True,
            text=True,
            check=False,
            timeout=90,
        )
        (OUTDIR / f"{args.workload}.stdout").write_text(result.stdout)
        (OUTDIR / f"{args.workload}.stderr").write_text(result.stderr)
        log_progress(f"WORKLOAD {args.workload} rc={result.returncode}")
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
