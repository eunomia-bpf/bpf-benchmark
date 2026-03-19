#!/usr/bin/env python3

import argparse
import os
import select
import subprocess
import sys
import time


BOOT_MARKERS = (
    b"Run /bin/sh as init process",
    b"/bin/sh: 0: can't access tty; job control turned off",
    b"# ",
)


def stream_until(proc: subprocess.Popen[bytes], markers: tuple[bytes, ...], timeout: int) -> bytes:
    deadline = time.time() + timeout
    buffer = bytearray()

    while time.time() < deadline:
        if proc.stdout is None:
            break

        wait_s = max(0.0, min(1.0, deadline - time.time()))
        readable, _, _ = select.select([proc.stdout], [], [], wait_s)

        if proc.stdout in readable:
            chunk = os.read(proc.stdout.fileno(), 4096)
            if not chunk:
                break
            sys.stdout.buffer.write(chunk)
            sys.stdout.buffer.flush()
            buffer.extend(chunk)
            if any(marker in buffer for marker in markers):
                return bytes(buffer)
        elif proc.poll() is not None:
            break

    return bytes(buffer)


def smoke_complete(output: str) -> bool:
    if "GNU/Linux" not in output:
        return False
    if "Linux version" not in output:
        return False
    return any(line.replace("#", " ").strip() in {"0", "1", "2"} for line in output.splitlines())


def main() -> int:
    parser = argparse.ArgumentParser(description="Boot an ARM64 kernel under QEMU and run a simple smoke test.")
    parser.add_argument("--qemu", default="qemu-system-aarch64")
    parser.add_argument("--kernel", required=True)
    parser.add_argument("--rootfs", required=True)
    parser.add_argument("--memory-mb", type=int, default=2048)
    parser.add_argument("--cpus", type=int, default=2)
    parser.add_argument("--timeout", type=int, default=180)
    args = parser.parse_args()

    if not os.path.isfile(args.kernel):
        print(f"kernel image not found: {args.kernel}", file=sys.stderr)
        return 1
    if not os.path.exists(os.path.join(args.rootfs, "bin", "sh")):
        print(f"ARM64 rootfs missing /bin/sh: {args.rootfs}", file=sys.stderr)
        return 1

    cmd = [
        args.qemu,
        "-M",
        "virt",
        "-cpu",
        "cortex-a72",
        "-smp",
        str(args.cpus),
        "-m",
        str(args.memory_mb),
        "-nographic",
        "-no-reboot",
        "-nic",
        "none",
        "-kernel",
        args.kernel,
        "-append",
        "console=ttyAMA0 "
        "root=/dev/root "
        "rootfstype=9p "
        "rootflags=trans=virtio,version=9p2000.L,cache=loose,msize=262144 "
        "ro init=/bin/sh",
        "-fsdev",
        f"local,id=rootfs,path={args.rootfs},security_model=none,readonly=on",
        "-device",
        "virtio-9p-pci,fsdev=rootfs,mount_tag=/dev/root",
    ]

    proc = subprocess.Popen(
        cmd,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )

    try:
        boot_output = stream_until(proc, BOOT_MARKERS, args.timeout)
        if proc.poll() is not None:
            print("QEMU exited before guest shell became available.", file=sys.stderr)
            return proc.returncode or 1
        if not any(marker in boot_output for marker in BOOT_MARKERS):
            print("Timed out waiting for the ARM64 guest shell.", file=sys.stderr)
            return 1

        commands = b"\n".join(
            (
                b"mount -t proc proc /proc",
                b"mount -t sysfs sysfs /sys",
                b"uname -a",
                b"cat /proc/version",
                b"cat /proc/sys/net/core/bpf_jit_enable",
            )
        ) + b"\n"

        assert proc.stdin is not None
        proc.stdin.write(commands)
        proc.stdin.flush()

        deadline = time.time() + args.timeout
        smoke_buffer = bytearray()
        normalized = ""

        while time.time() < deadline:
            smoke_output = stream_until(proc, tuple(), 1)
            if smoke_output:
                smoke_buffer.extend(smoke_output)
                normalized = smoke_buffer.decode("utf-8", errors="ignore").replace("\r", "")
                if smoke_complete(normalized):
                    break
            if proc.poll() is not None:
                break

        if not smoke_complete(normalized):
            print("ARM64 smoke commands did not finish before timeout.", file=sys.stderr)
            return 1
        if "GNU/Linux" not in normalized:
            print("uname -a output missing from ARM64 smoke output.", file=sys.stderr)
            return 1
        if "Linux version" not in normalized:
            print("/proc/version output missing from ARM64 smoke output.", file=sys.stderr)
            return 1

        bpf_jit_lines = [
            line.replace("#", " ").strip()
            for line in normalized.splitlines()
            if line.replace("#", " ").strip() in {"0", "1", "2"}
        ]
        if not bpf_jit_lines:
            print("/proc/sys/net/core/bpf_jit_enable output missing from ARM64 smoke output.", file=sys.stderr)
            return 1
    finally:
        if proc.poll() is None:
            proc.terminate()
        try:
            proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            proc.kill()
            proc.wait()

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
