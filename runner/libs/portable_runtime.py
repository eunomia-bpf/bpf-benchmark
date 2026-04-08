from __future__ import annotations

import argparse
import os
import shutil
import subprocess
from collections import deque
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.arm64_sysroot import Arm64SysrootConfig, ensure_sysroot
from runner.libs.cli_support import fail


_SKIP_ARM64_RUNTIME_LIBS = {
    "ld-linux-aarch64.so.1",
    "libc.so.6",
    "libm.so.6",
    "libpthread.so.0",
    "librt.so.1",
    "libdl.so.2",
    "libresolv.so.2",
    "libutil.so.1",
}


_die = partial(fail, "portable-runtime")


def _run(command: list[str], *, env: dict[str, str] | None = None, cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        cwd=cwd,
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )
    if completed.returncode != 0:
        output = completed.stderr.strip() or completed.stdout.strip() or "command failed"
        _die(f"{output}: {' '.join(command)}")
    return completed


def _require_command(name: str) -> str:
    resolved = shutil.which(name)
    if not resolved:
        _die(f"missing required command: {name}")
    return resolved


def _require_arch_signature(path: Path, needle: str, description: str) -> None:
    completed = _run(["file", str(path)])
    if needle not in completed.stdout:
        _die(f"{description} does not match expected file signature {needle}: {path}")


def _symlink_or_replace(path: Path, target: str) -> None:
    if path.exists() or path.is_symlink():
        path.unlink()
    os.symlink(target, path)


def _ensure_arm64_sysroot(
    *,
    sysroot_root: Path,
    sysroot_lock_file: Path,
    remote_host: str,
    remote_user: str,
    ssh_key_path: str,
) -> None:
    ensure_sysroot(
        Arm64SysrootConfig(
            sysroot_root=sysroot_root,
            sysroot_lock_file=sysroot_lock_file,
            remote_host=remote_host,
            remote_user=remote_user,
            ssh_key_path=Path(ssh_key_path),
        )
    )


def _readelf_needed_libraries(binary: Path, *, readelf_bin: str) -> list[str]:
    completed = _run([readelf_bin, "-d", str(binary)])
    libs: set[str] = set()
    for line in completed.stdout.splitlines():
        marker = "Shared library: ["
        if marker in line:
            libs.add(line.split(marker, 1)[1].split("]", 1)[0])
    return sorted(libs)


def _readelf_soname(binary: Path, *, readelf_bin: str) -> str:
    completed = _run([readelf_bin, "-d", str(binary)])
    for line in completed.stdout.splitlines():
        marker = "Library soname: ["
        if marker in line:
            return line.split(marker, 1)[1].split("]", 1)[0]
    return ""


def _resolve_arm64_library_path(soname: str, *, sysroot_root: Path) -> Path:
    for candidate in (
        sysroot_root / "usr/lib" / soname,
        sysroot_root / "usr/lib64" / soname,
        sysroot_root / "lib" / soname,
        sysroot_root / "lib64" / soname,
    ):
        if candidate.exists():
            return candidate
    _die(f"unable to resolve ARM64 shared library {soname}")


def copy_arm64_runtime_bundle(
    *,
    binary: Path,
    lib_output_dir: Path,
    sysroot_root: Path,
    readelf_bin: str = "",
) -> None:
    readelf = readelf_bin or _require_command("aarch64-linux-gnu-readelf")
    lib_output_dir.mkdir(parents=True, exist_ok=True)
    queue: deque[Path] = deque([binary])
    seen: set[Path] = set()
    while queue:
        current = queue.popleft()
        if current in seen or not current.exists():
            continue
        seen.add(current)
        for soname in _readelf_needed_libraries(current, readelf_bin=readelf):
            if soname in _SKIP_ARM64_RUNTIME_LIBS:
                continue
            resolved = _resolve_arm64_library_path(soname, sysroot_root=sysroot_root)
            resolved_name = resolved.name
            copied = lib_output_dir / resolved_name
            shutil.copy2(resolved.resolve(), copied, follow_symlinks=True)
            if soname != resolved_name:
                _symlink_or_replace(lib_output_dir / soname, resolved_name)
            soname_value = _readelf_soname(resolved, readelf_bin=readelf)
            if soname_value and soname_value != resolved_name:
                _symlink_or_replace(lib_output_dir / soname_value, resolved_name)
            queue.append(resolved)


def bundle_arm64_portable_binary(
    *,
    input_binary: Path,
    real_output: Path,
    wrapper_output: Path,
    lib_output_dir: Path,
    sysroot_root: Path,
    sysroot_lock_file: Path,
    remote_host: str,
    remote_user: str,
    ssh_key_path: str,
    readelf_bin: str = "",
    strip_bin: str = "",
) -> None:
    readelf = readelf_bin or _require_command("aarch64-linux-gnu-readelf")
    if not input_binary.is_file():
        _die(f"input ARM64 binary is missing: {input_binary}")
    _require_arch_signature(input_binary, "ARM aarch64", "input ARM64 binary")

    _ensure_arm64_sysroot(
        sysroot_root=sysroot_root,
        sysroot_lock_file=sysroot_lock_file,
        remote_host=remote_host,
        remote_user=remote_user,
        ssh_key_path=ssh_key_path,
    )

    real_output.parent.mkdir(parents=True, exist_ok=True)
    wrapper_output.parent.mkdir(parents=True, exist_ok=True)
    lib_output_dir.mkdir(parents=True, exist_ok=True)
    shutil.copy2(input_binary, real_output)
    if strip_bin:
        subprocess.run([strip_bin, str(real_output)], check=False, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    copy_arm64_runtime_bundle(
        binary=real_output,
        lib_output_dir=lib_output_dir,
        sysroot_root=sysroot_root,
        readelf_bin=readelf,
    )

    wrapper_output.write_text(
        f"""#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${{BASH_SOURCE[0]}}")" && pwd)"
BUNDLE_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
LIB_DIR="$BUNDLE_ROOT/lib"
export LD_LIBRARY_PATH="$LIB_DIR${{LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}}"
exec "$SCRIPT_DIR/{real_output.name}" "$@"
""",
        encoding="utf-8",
    )
    wrapper_output.chmod(0o755)
    _require_arch_signature(real_output, "ARM aarch64", "portable ARM64 output")


def build_x86_portable_libbpf(output_root: Path) -> None:
    _require_command("docker")
    output_lib_dir = output_root / "lib"
    shutil.rmtree(output_lib_dir, ignore_errors=True)
    output_lib_dir.mkdir(parents=True, exist_ok=True)
    container_command = "\n".join(
        (
            "set -euo pipefail",
            "dnf -y install gcc make elfutils-libelf-devel binutils >/dev/null 2>&1",
            "rm -rf /tmp/libbpf-obj /tmp/libbpf-stage",
            'make -C /workspace/vendor/libbpf/src -j"$(nproc)" OBJDIR=/tmp/libbpf-obj DESTDIR=/tmp/libbpf-stage prefix= install >/dev/null',
            "lib_dir=/tmp/libbpf-stage/usr/lib64",
            'real_so="$(find "$lib_dir" -maxdepth 1 -type f -name "libbpf.so.*" | sort | tail -n1)"',
            'test -n "$real_so"',
            'cp -L "$real_so" /out/lib/',
            'real_name="$(basename "$real_so")"',
            'soname="$(readelf -d "$real_so" | sed -n "s/.*Library soname: \\[\\(.*\\)\\].*/\\1/p" | head -n1)"',
            'if [[ -n "$soname" && "$soname" != "$real_name" ]]; then ln -sfn "$real_name" "/out/lib/$soname"; fi',
        )
    )
    _run(
        [
            "docker",
            "run",
            "--rm",
            "-v",
            f"{ROOT_DIR}:/workspace:ro",
            "-v",
            f"{output_root}:/out",
            "amazonlinux:2023",
            "bash",
            "-lc",
            container_command,
        ]
    )
    candidates = list(output_lib_dir.glob("libbpf.so.*"))
    if not candidates:
        _die(f"portable x86 libbpf build did not produce libbpf.so.* under {output_lib_dir}")
    for candidate in candidates:
        _require_arch_signature(candidate, "x86-64", "portable x86 libbpf output")


def main(argv: list[str] | None = None) -> None:
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest="command", required=True)

    stage_parser = subparsers.add_parser("stage-arm64-portable")
    stage_parser.add_argument("input_binary")
    stage_parser.add_argument("real_output")
    stage_parser.add_argument("wrapper_output")
    stage_parser.add_argument("lib_output_dir")
    stage_parser.add_argument("sysroot_root")
    stage_parser.add_argument("sysroot_lock_file")
    stage_parser.add_argument("remote_host")
    stage_parser.add_argument("remote_user")
    stage_parser.add_argument("ssh_key_path")
    stage_parser.add_argument("--readelf-bin", default="")
    stage_parser.add_argument("--strip-bin", default="")

    bundle_parser = subparsers.add_parser("bundle-arm64-runtime")
    bundle_parser.add_argument("binary")
    bundle_parser.add_argument("lib_output_dir")
    bundle_parser.add_argument("sysroot_root")
    bundle_parser.add_argument("--readelf-bin", default="")

    x86_parser = subparsers.add_parser("build-x86-portable-libbpf")
    x86_parser.add_argument("output_root")

    args = parser.parse_args(argv)
    if args.command == "stage-arm64-portable":
        bundle_arm64_portable_binary(
            input_binary=Path(args.input_binary),
            real_output=Path(args.real_output),
            wrapper_output=Path(args.wrapper_output),
            lib_output_dir=Path(args.lib_output_dir),
            sysroot_root=Path(args.sysroot_root),
            sysroot_lock_file=Path(args.sysroot_lock_file),
            remote_host=args.remote_host,
            remote_user=args.remote_user,
            ssh_key_path=args.ssh_key_path,
            readelf_bin=args.readelf_bin,
            strip_bin=args.strip_bin,
        )
        return
    if args.command == "bundle-arm64-runtime":
        copy_arm64_runtime_bundle(
            binary=Path(args.binary),
            lib_output_dir=Path(args.lib_output_dir),
            sysroot_root=Path(args.sysroot_root),
            readelf_bin=args.readelf_bin,
        )
        return
    if args.command == "build-x86-portable-libbpf":
        build_x86_portable_libbpf(Path(args.output_root))
        return
    _die(f"unsupported command: {args.command}")


if __name__ == "__main__":
    main()
