"""Regression: list_progs must wait for a synchronous native load to complete.

A real upstream app submits P to the real kernel queue. The test service keeps
that request active while querying the app's snapshot, then rejects the load.
"""
import argparse
import errno
import json
import os
from pathlib import Path
import socket
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "kprog"))
from trusted_service import COMPLETE, Result, ioctl, next_request


def run(output, shim, loader):
    output.mkdir(parents=True, exist_ok=True)
    sockets = output / "sockets"
    sockets.mkdir()
    environment = dict(os.environ, LD_PRELOAD=str(shim),
        BPFREJIT_SHIM_NATIVE_LOADER="1", BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF="1",
        BPFREJIT_NATIVE_LOADER_SO=str(loader),
        BPFREJIT_SHIM_NATIVE_MANIFEST=str(ROOT / "vendor/build/native-bpf/x86/stage/bcc/manifest.json"),
        BPFREJIT_SHIM_SOCK_DIR=str(sockets), BPFREJIT_SHIM_DIR=str(output / "shim"),
        BPFREJIT_SHIM_LOG=str(output / "shim.log"))
    service = os.open("/sys/kernel/debug/bpf_x86_native_lab/specializer", os.O_RDWR | os.O_CLOEXEC)
    app = None
    try:
        with (output / "app.stdout").open("w") as stdout, (output / "app.stderr").open("w") as stderr:
            app = subprocess.Popen([ROOT / "vendor/build/x86/bcc/bin/vfsstat", "-v", "1", "1"],
                                   env=environment, stdout=stdout, stderr=stderr)
            request, spans = next_request(service)
            (output / "kernel.native.o").write_bytes(spans[0])
            (output / "kernel.metadata.json").write_bytes(spans[2])
            with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as snapshot:
                snapshot.connect(str(sockets / f"shim-{app.pid}.sock"))
                snapshot.sendall(b'{"cmd":"list_progs"}\n')
                snapshot.settimeout(0.2)
                premature = False
                response = b""
                try:
                    response = snapshot.recv(65536)
                    premature = True
                except socket.timeout:
                    pass  # Expected: the kernel request is still active.
                ioctl(service, COMPLETE, Result(request_id=request.request_id, status=-errno.EACCES))
                os.close(service)
                service = -1
                returncode = app.wait(timeout=30)
                receipt = dict(source_prog_id=request.source_prog_id,
                    snapshot_before_load_completed=premature,
                    snapshot_response=response.decode(), app_returncode=returncode,
                    service_status=-errno.EACCES)
                (output / "observation.json").write_text(json.dumps(receipt, indent=2) + "\n")
                print(json.dumps(receipt), flush=True)
                if premature:
                    raise RuntimeError("snapshot published an incomplete synchronous native load")
                if returncode == 0:
                    raise RuntimeError("application ignored the deliberate service rejection")
    finally:
        if service >= 0:
            os.close(service)
        if app is not None and app.poll() is None:
            app.kill()
            app.wait()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("output", type=Path)
    parser.add_argument("shim", type=Path)
    parser.add_argument("loader", type=Path)
    args = parser.parse_args()
    run(args.output, args.shim, args.loader)
