from __future__ import annotations

import argparse
import fcntl
import os
import shutil
import subprocess
from dataclasses import dataclass
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail

_die = partial(fail, "arm64-sysroot")


def _env(name: str, default: str = "") -> str:
    return os.environ.get(name, default).strip()


def _require_command(name: str) -> str:
    resolved = shutil.which(name)
    if not resolved:
        _die(f"missing required command: {name}")
    return resolved


def _run(
    command: list[str],
    *,
    stdin: str | None = None,
    cwd: Path | None = None,
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        input=stdin,
        cwd=cwd,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )
    if completed.returncode != 0:
        output = completed.stderr.strip() or completed.stdout.strip() or "command failed"
        _die(f"{output}: {' '.join(command)}")
    return completed


@dataclass(frozen=True)
class Arm64SysrootConfig:
    sysroot_root: Path
    sysroot_lock_file: Path
    remote_host: str
    remote_user: str
    ssh_key_path: Path
    ssh_port: int = 22


_REQUIRED_PATHS = (
    "usr/lib/ld-linux-aarch64.so.1",
    "usr/lib64/libc.so.6",
    "usr/lib64/libm.so.6",
    "usr/lib64/libpthread.so.0",
    "lib64/libgcc_s.so.1",
    "usr/include/libelf.h",
    "usr/include/llvm/IR/LLVMContext.h",
    "usr/include/yaml-cpp/yaml.h",
    "usr/include/zlib.h",
    "usr/include/zstd.h",
    "usr/lib64/libelf.so",
    "usr/lib64/libelf.so.1",
    "usr/lib64/libLLVM-15.so",
    "usr/lib64/libyaml-cpp.so",
    "usr/lib64/libyaml-cpp.so.0.6",
    "usr/lib64/libz.so",
    "usr/lib64/libz.so.1",
    "usr/lib64/libzstd.so",
    "usr/lib64/libzstd.so.1",
    "usr/lib64/libcrypto.so.3",
    "usr/lib64/cmake/llvm/LLVMConfig.cmake",
    "usr/lib64/pkgconfig/libelf.pc",
    "usr/lib64/pkgconfig/yaml-cpp.pc",
    "usr/lib64/pkgconfig/zlib.pc",
    "usr/lib64/pkgconfig/libzstd.pc",
)

_REQUIRED_REMOTE_PACKAGES = (
    "glibc",
    "glibc-devel",
    "elfutils-libelf",
    "libgcc",
    "libstdc++",
    "libstdc++-devel",
    "elfutils-libelf-devel",
    "llvm-libs",
    "llvm-devel",
    "yaml-cpp",
    "yaml-cpp-devel",
    "zlib",
    "zlib-devel",
    "libzstd",
    "libzstd-devel",
    "openssl-libs",
    "openssl-devel",
)


def _ssh_base_args(config: Arm64SysrootConfig) -> list[str]:
    return [
        "-o",
        "BatchMode=yes",
        "-o",
        "StrictHostKeyChecking=no",
        "-o",
        "UserKnownHostsFile=/dev/null",
        "-p",
        str(config.ssh_port),
        "-i",
        str(config.ssh_key_path),
    ]


def _remote_exec(config: Arm64SysrootConfig, script: str) -> subprocess.CompletedProcess[str]:
    return _run(
        [
            "ssh",
            *_ssh_base_args(config),
            f"{config.remote_user}@{config.remote_host}",
            "bash",
            "-seuo",
            "pipefail",
        ],
        stdin=script,
    )


def _have_sysroot(config: Arm64SysrootConfig) -> bool:
    fingerprint_file = config.sysroot_root / ".package-fingerprint"
    source_file = config.sysroot_root / ".source"
    if not fingerprint_file.is_file() or not source_file.is_file():
        return False
    return all((config.sysroot_root / relative).exists() for relative in _REQUIRED_PATHS)


def _require_remote_contract(config: Arm64SysrootConfig) -> None:
    if not config.remote_host:
        _die("ARM64_SYSROOT_REMOTE_HOST is required to populate the ARM64 sysroot")
    if not config.remote_user:
        _die("ARM64_SYSROOT_REMOTE_USER is required to populate the ARM64 sysroot")
    if not config.ssh_key_path:
        _die("ARM64_SYSROOT_SSH_KEY_PATH is required to populate the ARM64 sysroot")
    if not config.ssh_key_path.is_file():
        _die(f"missing ARM64 sysroot SSH key: {config.ssh_key_path}")


def _remote_package_fingerprint(config: Arm64SysrootConfig) -> str:
    package_list = " ".join(f"'{name}'" for name in _REQUIRED_REMOTE_PACKAGES)
    completed = _remote_exec(
        config,
        "\n".join(
            (
                f"packages=({package_list})",
                'rpm -q "${packages[@]}"',
            )
        ),
    )
    return completed.stdout


def _ensure_remote_packages_installed(config: Arm64SysrootConfig) -> None:
    package_list = " ".join(f"'{name}'" for name in _REQUIRED_REMOTE_PACKAGES)
    _remote_exec(
        config,
        "\n".join(
            (
                f"packages=({package_list})",
                "missing=()",
                'for pkg in "${packages[@]}"; do',
                '    rpm -q "$pkg" >/dev/null 2>&1 || missing+=("$pkg")',
                "done",
                'if (( ${#missing[@]} )); then',
                '    sudo dnf -y install "${missing[@]}" >/dev/null',
                "fi",
            )
        ),
    )


def _populate_sysroot_from_remote(config: Arm64SysrootConfig) -> None:
    tmp_root = Path(f"{config.sysroot_root}.tmp")
    shutil.rmtree(tmp_root, ignore_errors=True)
    tmp_root.mkdir(parents=True, exist_ok=True)
    package_list = " ".join(f"'{name}'" for name in _REQUIRED_REMOTE_PACKAGES)

    remote_tar_script = "\n".join(
        (
            f"packages=({package_list})",
            'rpm -ql "${packages[@]}" |',
            '    while IFS= read -r path; do',
            '        [[ -n "$path" ]] || continue',
            '        [[ -e "$path" ]] || continue',
            '        [[ -d "$path" ]] && continue',
            '        case "$path" in',
            '            /usr/include/*|/usr/lib/*|/usr/lib64/*|/lib64/*)',
            '                printf "%s\\0" "$path"',
            "                ;;",
            "        esac",
            "    done |",
            "    sort -zu |",
            "    tar --null -T - -chf -",
        )
    )

    tar_command = [
        "ssh",
        *_ssh_base_args(config),
        f"{config.remote_user}@{config.remote_host}",
        "bash",
        "-seuo",
        "pipefail",
    ]
    tar_process = subprocess.Popen(
        tar_command,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=False,
    )
    assert tar_process.stdin is not None
    tar_process.stdin.write(remote_tar_script.encode("utf-8"))
    tar_process.stdin.close()
    extract = subprocess.run(
        ["tar", "-xf", "-", "-C", str(tmp_root)],
        stdin=tar_process.stdout,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
        text=False,
    )
    stderr_bytes = tar_process.stderr.read() if tar_process.stderr is not None else b""
    return_code = tar_process.wait()
    if tar_process.stdout is not None:
        tar_process.stdout.close()
    if tar_process.stderr is not None:
        tar_process.stderr.close()
    if return_code != 0:
        _die(stderr_bytes.decode("utf-8", errors="replace").strip() or "failed to stream ARM64 sysroot archive over ssh")
    if extract.returncode != 0:
        _die(extract.stderr.decode("utf-8", errors="replace").strip() or "failed to unpack ARM64 sysroot archive")

    (tmp_root / "lib").mkdir(exist_ok=True)
    (tmp_root / "lib64").mkdir(exist_ok=True)
    symlinks = {
        "lib/ld-linux-aarch64.so.1": "../usr/lib/ld-linux-aarch64.so.1",
        "lib64/libc.so.6": "../usr/lib64/libc.so.6",
        "lib64/libm.so.6": "../usr/lib64/libm.so.6",
        "lib64/libpthread.so.0": "../usr/lib64/libpthread.so.0",
        "lib64/librt.so.1": "../usr/lib64/librt.so.1",
        "lib64/libdl.so.2": "../usr/lib64/libdl.so.2",
        "lib64/libresolv.so.2": "../usr/lib64/libresolv.so.2",
        "lib64/libutil.so.1": "../usr/lib64/libutil.so.1",
    }
    for relative_path, target in symlinks.items():
        symlink_path = tmp_root / relative_path
        if not symlink_path.exists():
            symlink_path.symlink_to(target)

    fingerprint = _remote_package_fingerprint(config)
    (tmp_root / ".package-fingerprint").write_text(fingerprint, encoding="utf-8")
    (tmp_root / ".source").write_text(f"{config.remote_user}@{config.remote_host}\n", encoding="utf-8")

    shutil.rmtree(config.sysroot_root, ignore_errors=True)
    tmp_root.rename(config.sysroot_root)


def ensure_sysroot(config: Arm64SysrootConfig) -> Path:
    _require_command("ssh")
    _require_command("tar")
    config.sysroot_lock_file.parent.mkdir(parents=True, exist_ok=True)
    with config.sysroot_lock_file.open("a+", encoding="utf-8") as lock_file:
        fcntl.flock(lock_file.fileno(), fcntl.LOCK_EX)
        if _have_sysroot(config):
            _require_remote_contract(config)
            _ensure_remote_packages_installed(config)
            remote_fingerprint = _remote_package_fingerprint(config)
            current_fingerprint = (config.sysroot_root / ".package-fingerprint").read_text(encoding="utf-8")
            if current_fingerprint == remote_fingerprint:
                return config.sysroot_root
        _require_remote_contract(config)
        _ensure_remote_packages_installed(config)
        _populate_sysroot_from_remote(config)
        if not _have_sysroot(config):
            _die(f"failed to populate required ARM64 sysroot paths under {config.sysroot_root}")
        return config.sysroot_root


def ensure_sysroot_from_env() -> Path:
    host_cache_root = ROOT_DIR / ".cache/arm64-host"
    config = Arm64SysrootConfig(
        sysroot_root=Path(_env("ARM64_SYSROOT_ROOT", str(host_cache_root / "sysroot"))),
        sysroot_lock_file=Path(_env("ARM64_SYSROOT_LOCK_FILE", str(host_cache_root / "sysroot.lock"))),
        remote_host=_env("ARM64_SYSROOT_REMOTE_HOST"),
        remote_user=_env("ARM64_SYSROOT_REMOTE_USER"),
        ssh_key_path=Path(_env("ARM64_SYSROOT_SSH_KEY_PATH")),
        ssh_port=int(_env("ARM64_SYSROOT_SSH_PORT", "22") or "22"),
    )
    return ensure_sysroot(config)


def main(argv: list[str] | None = None) -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--print-path", action="store_true")
    _ = parser.parse_args(argv)
    sysroot_root = ensure_sysroot_from_env()
    print(sysroot_root)


if __name__ == "__main__":
    main()
