from __future__ import annotations

from pathlib import Path

from . import ensure_parent


_KATRAN_PACKET = bytes.fromhex(
    "02000000000a02000000001c08004500003200004000400625600a0000020a640101"
    "7a691f90000000010000000050102000591d00004b415452414e56495021"
)


def materialize_katran_packet(path: Path) -> Path:
    ensure_parent(path)
    if path.exists() and path.read_bytes() == _KATRAN_PACKET:
        return path
    path.write_bytes(_KATRAN_PACKET)
    return path


__all__ = ["materialize_katran_packet"]
