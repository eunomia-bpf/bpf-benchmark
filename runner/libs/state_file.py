from __future__ import annotations

import json
from functools import partial
from pathlib import Path
from runner.libs.cli_support import fail

_die = partial(fail, "state-file")


def read_json_object(path: Path) -> dict[str, object]:
    if not path.is_file():
        _die(f"JSON file is missing: {path}")
    text = path.read_text(encoding="utf-8")
    if not text.strip():
        _die(f"JSON file is empty: {path}")
    try:
        raw = json.loads(text)
    except json.JSONDecodeError as exc:
        _die(f"file is not valid JSON: {path} ({exc})")
    if not isinstance(raw, dict):
        _die(f"JSON file must contain an object: {path}")
    return dict(raw)


def write_json_object(path: Path, values: dict[str, object]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(values, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def read_state(path: Path) -> dict[str, str]:
    raw = read_json_object(path)
    state: dict[str, str] = {}
    for key, value in raw.items():
        if not isinstance(key, str) or not isinstance(value, str):
            _die(f"state file values must be string scalars: {path}")
        state[key] = value
    return state


def write_state(path: Path, values: dict[str, str]) -> None:
    write_json_object(path, values)
