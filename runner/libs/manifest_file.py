from __future__ import annotations

import re
import shlex
from pathlib import Path


SCALAR_PATTERN = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)=(.*)$")
ARRAY_PATTERN = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)=\((.*)\)$")
EXPORT_PATTERN = re.compile(r"^export\s+")


def parse_manifest(manifest_path: Path) -> dict[str, str | list[str]]:
    parsed: dict[str, str | list[str]] = {}
    for raw_line in manifest_path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        line = EXPORT_PATTERN.sub("", line, count=1).strip()
        if not line:
            continue
        array_match = ARRAY_PATTERN.match(line)
        if array_match:
            name, raw_value = array_match.groups()
            parsed[name] = shlex.split(raw_value)
            continue
        scalar_match = SCALAR_PATTERN.match(line)
        if scalar_match:
            name, raw_value = scalar_match.groups()
            values = shlex.split(raw_value)
            parsed[name] = values[0] if values else ""
            continue
        raise RuntimeError(f"unsupported manifest line: {raw_line}")
    return parsed


def render_shell_assignments_from_mapping(values: dict[str, str | list[str]]) -> str:
    lines: list[str] = []
    for name, value in values.items():
        if isinstance(value, list):
            rendered = " ".join(shlex.quote(token) for token in value)
            lines.append(f"{name}=( {rendered} )")
        else:
            lines.append(f"{name}={shlex.quote(value)}")
    return "\n".join(lines)


def render_shell_assignments(manifest_path: Path) -> str:
    return render_shell_assignments_from_mapping(parse_manifest(manifest_path))


def render_null_assignments_from_mapping(values: dict[str, str | list[str]]) -> bytes:
    parts: list[bytes] = []
    for name, value in values.items():
        scalar = shlex.join(value) if isinstance(value, list) else value
        parts.append(f"{name}={scalar}".encode("utf-8") + b"\0")
    return b"".join(parts)


def render_null_assignments(manifest_path: Path) -> bytes:
    return render_null_assignments_from_mapping(parse_manifest(manifest_path))
