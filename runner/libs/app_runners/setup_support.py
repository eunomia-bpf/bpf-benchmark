from __future__ import annotations

import os
import platform
import struct
from pathlib import Path
from typing import Sequence

from .. import which

_ELF_MAGIC = b"\x7fELF"
_HOST_ELF_MACHINES = {
    "aarch64": 183,
    "arm64": 183,
    "x86_64": 62,
    "amd64": 62,
}


def _read_elf_machine(candidate: Path) -> int | None:
    try:
        header = candidate.read_bytes()[:20]
    except OSError:
        return None
    if len(header) < 20 or header[:4] != _ELF_MAGIC:
        return None
    data_encoding = int(header[5])
    if data_encoding == 1:
        endian = "<"
    elif data_encoding == 2:
        endian = ">"
    else:
        return None
    return int(struct.unpack_from(f"{endian}H", header, 18)[0])


def binary_matches_host_arch(candidate: str | Path) -> bool:
    path = Path(candidate).resolve()
    machine = _read_elf_machine(path)
    if machine is None:
        return True
    expected = _HOST_ELF_MACHINES.get(platform.machine().lower())
    if expected is None:
        return True
    return machine == expected


def pick_host_executable(*candidates: str | Path | None) -> Path | None:
    for candidate in candidates:
        if candidate is None:
            continue
        path = Path(candidate).expanduser()
        if not path.is_file() or not os.access(path, os.X_OK):
            continue
        if binary_matches_host_arch(path):
            return path.resolve()
    return None


def missing_required_commands(commands: Sequence[str]) -> list[str]:
    missing: list[str] = []
    for command in commands:
        if which(str(command).strip()) is None:
            missing.append(str(command))
    return missing


def first_existing_dir(*candidates: str | Path | None) -> Path | None:
    for candidate in candidates:
        if candidate is None:
            continue
        path = Path(candidate).expanduser()
        if path.is_dir():
            return path.resolve()
    return None

