#!/usr/bin/env python3
"""Apply the native proof-region kernel fix, or verify it is already applied."""
from pathlib import Path
import fcntl
import subprocess


def apply(kernel: Path, patch: bytes) -> None:
    command = ["patch", "--batch", "--forward", "--no-backup-if-mismatch",
               "-p1", "-d", str(kernel)]
    pending = subprocess.run(command + ["--dry-run"], input=patch, capture_output=True)
    if pending.returncode == 0:
        subprocess.run(command, input=patch, check=True)
    else:
        applied = subprocess.run(command + ["--dry-run", "--reverse"], input=patch, capture_output=True)
        if applied.returncode:
            raise SystemExit("native proof kernel patch conflicts with the kernel source:\n" +
                             pending.stdout.decode() + pending.stderr.decode())
        print("native proof-region kernel patch already applied")


if __name__ == "__main__":
    root = Path(__file__).resolve().parents[2]
    build = Path(__file__).with_name("build")
    build.mkdir(exist_ok=True)
    with (build / "kernel-patch.lock").open("w") as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        apply(root / "vendor/linux-framework",
              Path(__file__).with_name("native-proof-regions.patch").read_bytes())
