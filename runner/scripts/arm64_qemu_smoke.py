#!/usr/bin/env python3

import argparse
import os
import re
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


def normalize_output(output: bytes) -> str:
    return output.decode("utf-8", errors="ignore").replace("\r", "")


def shell_printf_literal(text: str) -> str:
    return "".join(f"\\{ord(ch):03o}" if ch == "_" else ch for ch in text)


def smoke_complete(output: str) -> bool:
    if "GNU/Linux" not in output:
        return False
    if "Linux version" not in output:
        return False
    return any(line.replace("#", " ").strip() in {"0", "1", "2"} for line in output.splitlines())


def run_guest_command(proc: subprocess.Popen[bytes], command: str, timeout: int, command_id: int) -> tuple[int, str]:
    if proc.stdin is None:
        raise RuntimeError("QEMU guest stdin is unavailable")

    rc_marker = f"__ARM64_QEMU_CMD_{command_id}_RC="
    done_marker_text = f"__ARM64_QEMU_CMD_{command_id}_DONE__"
    wrapped = "\n".join(
        (
            f"{{ {command}; }}",
            "rc=$?",
            f"printf '{shell_printf_literal(rc_marker)}%d\\137\\137\\n{shell_printf_literal(done_marker_text)}\\n' \"$rc\"",
        )
    ) + "\n"
    done_marker = done_marker_text.encode()

    proc.stdin.write(wrapped.encode())
    proc.stdin.flush()

    output = stream_until(proc, (done_marker,), timeout)
    normalized = normalize_output(output)
    match = re.search(rf"{re.escape(rc_marker)}(\d+)__", normalized)
    if not match:
        if proc.poll() is not None:
            raise RuntimeError(f"QEMU exited while running guest command: {command}")
        raise RuntimeError(f"Timed out waiting for guest command completion: {command}")

    return int(match.group(1)), normalized


def run_guest_commands(
    proc: subprocess.Popen[bytes], commands: list[str], timeout: int, start_id: int = 1
) -> tuple[str, int]:
    output_parts: list[str] = []
    command_id = start_id

    for command in commands:
        rc, output = run_guest_command(proc, command, timeout, command_id)
        output_parts.append(output)
        if rc != 0:
            raise RuntimeError(f"Guest command failed with exit {rc}: {command}")
        command_id += 1

    return "".join(output_parts), command_id


def main() -> int:
    parser = argparse.ArgumentParser(description="Boot an ARM64 kernel under QEMU and run guest smoke commands.")
    parser.add_argument("--qemu", default="qemu-system-aarch64")
    parser.add_argument("--kernel", required=True)
    parser.add_argument("--rootfs", required=True)
    parser.add_argument("--host-share")
    parser.add_argument("--guest-mount", default="/mnt")
    parser.add_argument("--command", action="append", default=[])
    parser.add_argument("--cpu-model", default="cortex-a72")
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
    if args.host_share and not os.path.isdir(args.host_share):
        print(f"host share path not found: {args.host_share}", file=sys.stderr)
        return 1

    cmd = [
        args.qemu,
        "-M",
        "virt",
        "-cpu",
        args.cpu_model,
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
    if args.host_share:
        cmd.extend(
            [
                "-fsdev",
                f"local,id=hostshare,path={os.path.abspath(args.host_share)},security_model=none,readonly=on",
                "-device",
                "virtio-9p-pci,fsdev=hostshare,mount_tag=hostshare",
            ]
        )

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

        smoke_output, next_command_id = run_guest_commands(
            proc,
            [
                "mount -t proc proc /proc",
                "mount -t sysfs sysfs /sys",
                "uname -a",
                "cat /proc/version",
                "cat /proc/sys/net/core/bpf_jit_enable",
            ],
            args.timeout,
        )
        if not smoke_complete(smoke_output):
            print("ARM64 smoke commands did not finish before timeout.", file=sys.stderr)
            return 1

        if args.host_share:
            _, next_command_id = run_guest_commands(
                proc,
                [
                    f"mount -t 9p -o trans=virtio,version=9p2000.L,cache=loose hostshare {args.guest_mount}",
                ],
                args.timeout,
                next_command_id,
            )

        if args.command:
            run_guest_commands(proc, args.command, args.timeout, next_command_id)
    except RuntimeError as exc:
        print(str(exc), file=sys.stderr)
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
