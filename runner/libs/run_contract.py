from __future__ import annotations

import os
import re
import shlex
from pathlib import Path


SCALAR_PATTERN = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)=(.*)$")
ARRAY_PATTERN = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)=\((.*)\)$")


def parse_manifest(manifest_path: Path) -> dict[str, str | list[str]]:
    parsed: dict[str, str | list[str]] = {}
    for raw_line in manifest_path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
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


def load_manifest_environment(manifest_path: Path) -> dict[str, str | list[str]]:
    parsed = parse_manifest(manifest_path)
    for name, value in parsed.items():
        os.environ[name] = shlex.join(value) if isinstance(value, list) else value
    return parsed
