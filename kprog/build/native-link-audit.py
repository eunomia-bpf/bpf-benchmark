#!/usr/bin/env python3
"""Selected diagnostic wrapper: retain real link inputs/outputs without changing P.

Install beside native-link.real as native-link-on. Selection by the existing
native-link-binary setting is the opt-in switch; normal binaries are untouched.
All actual child failures and output bytes are forwarded. Inheritable descriptors
stay open, including original input ELF descriptors referenced through /proc/self.
"""
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import shutil
import signal
import subprocess
import sys
import tempfile


FLAGS = ["--runtime-map-lookups", "--local-memory-routines", "--runtime-known-map-lookups"]


def option(argv, name):
    for index, word in enumerate(argv):
        if word == name:
            return argv[index + 1] if index + 1 < len(argv) else None
        if word.startswith(name + "="):
            return word[len(name) + 1:]
    return None


def artifact(source, directory, filename):
    if source is None:
        return None
    path = Path(source)
    if not path.is_file():
        return dict(source=str(path), exists=False)
    target = directory / filename
    shutil.copyfile(path, target)
    return dict(source=str(path), exists=True, capture=filename,
                bytes=target.stat().st_size,
                sha256=hashlib.sha256(target.read_bytes()).hexdigest())


def capture(argv, payload):
    binary = payload / "native-link.real"
    root = payload / "audit"
    root.mkdir(exist_ok=True)
    directory = Path(tempfile.mkdtemp(prefix="link-", dir=root))
    command = [str(binary), *FLAGS, *argv]
    record = dict(version=1, started_at=datetime.now(timezone.utc).isoformat(),
                  pid=os.getpid(), boot_id=Path("/proc/sys/kernel/random/boot_id").read_text().strip(),
                  label=os.environ.get("KPROG_LINK_AUDIT_LABEL", "runtime"),
                  mode=option(argv, "--mode"), symbol=option(argv, "--symbol"), argv=argv,
                  command=command, binary_sha256=hashlib.sha256(binary.read_bytes()).hexdigest())
    (directory / "started.json").write_text(json.dumps(record, indent=2) + "\n")
    # Copy after execution but before returning to the caller, which still owns
    # the input/plan and temporary outputs. The CLI does not remove those files.
    result = subprocess.run(command, capture_output=True, close_fds=False)
    (directory / "stdout").write_bytes(result.stdout)
    (directory / "stderr").write_bytes(result.stderr)
    record.update(returncode=result.returncode, finished_at=datetime.now(timezone.utc).isoformat(),
                  input=artifact(option(argv, "--input"), directory, "input.elf"),
                  link_plan=artifact(option(argv, "--link-plan"), directory, "link-plan.json"),
                  outputs={name: artifact(option(argv, flag), directory, filename)
                           for name, flag, filename in [
                               ("image", "--output", "output.bin"),
                               ("relocs", "--output-relocs", "output.relocs"),
                               ("maps", "--output-map-patches", "output.maps"),
                               ("abi", "--output-abi", "output.abi")]})
    (directory / "result.json").write_text(json.dumps(record, indent=2) + "\n")
    sys.stdout.buffer.write(result.stdout)
    sys.stderr.buffer.write(result.stderr)
    sys.stdout.buffer.flush()
    sys.stderr.buffer.flush()
    return result.returncode


if __name__ == "__main__":
    status = capture(sys.argv[1:], Path(__file__).resolve().parent)
    if status < 0:
        number = -status
        if number not in (signal.SIGKILL, signal.SIGSTOP):
            signal.signal(number, signal.SIG_DFL)
        os.kill(os.getpid(), number)
    raise SystemExit(status)
