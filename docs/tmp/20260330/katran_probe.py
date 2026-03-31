#!/usr/bin/env python3
from __future__ import annotations

import json
import os
import traceback
import sys
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import resolve_bpftool_binary, run_command
from runner.libs.app_runners.katran import KatranRunner
from runner.libs.app_runners.katran_support import (
    CLIENT_NS,
    VIP_IP,
    VIP_PORT,
    ns_exec_command,
    run_parallel_http_load,
)


def _dump_completed(label: str, completed) -> None:
    print(f"=== {label} rc={completed.returncode} ===")
    stdout = (completed.stdout or "").strip()
    stderr = (completed.stderr or "").strip()
    if stdout:
        print(stdout)
    if stderr:
        print(stderr)


def main() -> int:
    runner = KatranRunner(workload_kind="network", concurrency=1)
    try:
        prog_ids = runner.start()
        print("=== started ===")
        print(json.dumps({"prog_ids": prog_ids, "artifacts": runner.artifacts}, indent=2, default=str))

        if os.environ.get("KATRAN_REATTACH_GENERIC") == "1":
            bpftool = resolve_bpftool_binary()
            prog_id = int(prog_ids[0])
            run_command([bpftool, "net", "detach", "xdp", "dev", runner.iface], check=False, timeout=15)
            run_command(
                [bpftool, "net", "attach", "xdpgeneric", "id", str(prog_id), "dev", runner.iface, "overwrite"],
                timeout=30,
            )
            attach = run_command([bpftool, "-j", "net", "show", "dev", runner.iface], timeout=30)
            print("=== reattached_generic ===")
            print(attach.stdout)

        ping = ns_exec_command(
            CLIENT_NS,
            ["ping", "-c", "1", "-W", "1", VIP_IP],
            check=False,
            timeout=5,
        )
        _dump_completed("ping_vip", ping)

        connect = ns_exec_command(
            CLIENT_NS,
            [
                "python3",
                "-c",
                (
                    "import socket,sys; "
                    "s=socket.create_connection((sys.argv[1], int(sys.argv[2])), timeout=2.0); "
                    "s.sendall(b'GET / HTTP/1.0\\r\\nHost: katran\\r\\nConnection: close\\r\\n\\r\\n'); "
                    "data=s.recv(256); "
                    "print(data.decode('latin1', 'replace')); "
                    "s.close()"
                ),
                VIP_IP,
                str(VIP_PORT),
            ],
            check=False,
            timeout=5,
        )
        _dump_completed("single_http", connect)

        summary = run_parallel_http_load(duration_s=1, concurrency=1)
        print("=== parallel_http ===")
        print(json.dumps(summary, indent=2, default=str))
        return 0
    except Exception:
        print("=== exception ===")
        traceback.print_exc()
        return 1
    finally:
        try:
            runner.stop()
        except Exception:
            print("=== stop_exception ===")
            traceback.print_exc()


if __name__ == "__main__":
    raise SystemExit(main())
