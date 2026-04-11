from __future__ import annotations

import json
import sys
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


def merge_state(path: Path, values: dict[str, str]) -> None:
    current: dict[str, str] = {}
    if path.exists():
        current = read_state(path)
    current.update(values)
    write_state(path, current)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args:
        _die("usage: state_file.py <write|merge> ...")
    action = args[0]
    if action == "write":
        if len(args) < 2:
            _die("usage: state_file.py write <path> [KEY=VALUE ...]")
        path = Path(args[1]).resolve()
        values: dict[str, str] = {}
        for item in args[2:]:
            if "=" not in item:
                _die(f"invalid KEY=VALUE item: {item}")
            key, value = item.split("=", 1)
            if not key:
                _die(f"invalid state key in item: {item}")
            values[key] = value
        write_state(path, values)
        return
    if action == "merge":
        if len(args) < 2:
            _die("usage: state_file.py merge <path> [KEY=VALUE ...]")
        path = Path(args[1]).resolve()
        values: dict[str, str] = {}
        for item in args[2:]:
            if "=" not in item:
                _die(f"invalid KEY=VALUE item: {item}")
            key, value = item.split("=", 1)
            if not key:
                _die(f"invalid state key in item: {item}")
            values[key] = value
        merge_state(path, values)
        return
    _die(f"unsupported action: {action}")


if __name__ == "__main__":
    main()
