from __future__ import annotations

import json
import shlex
import sys
from functools import partial
from pathlib import Path
from runner.libs.cli_support import fail

_die = partial(fail, "state-file")


def read_state(path: Path) -> dict[str, str]:
    if not path.is_file():
        _die(f"state file is missing: {path}")
    text = path.read_text(encoding="utf-8")
    if not text.strip():
        _die(f"state file is empty: {path}")
    try:
        raw = json.loads(text)
    except json.JSONDecodeError as exc:
        _die(f"state file is not valid JSON: {path} ({exc})")
    if not isinstance(raw, dict):
        _die(f"state file must contain a JSON object: {path}")
    state: dict[str, str] = {}
    for key, value in raw.items():
        if not isinstance(key, str) or not isinstance(value, str):
            _die(f"state file values must be string scalars: {path}")
        state[key] = value
    return state


def write_state(path: Path, values: dict[str, str]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(values, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def merge_state(path: Path, values: dict[str, str]) -> None:
    current: dict[str, str] = {}
    if path.exists():
        current = read_state(path)
    current.update(values)
    write_state(path, current)


def render_shell_assignments(path: Path) -> str:
    return "\n".join(f"{name}={shlex.quote(value)}" for name, value in read_state(path).items())


def render_null_assignments(path: Path) -> bytes:
    return b"".join(f"{name}={value}".encode("utf-8") + b"\0" for name, value in read_state(path).items())


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args:
        _die("usage: state_file.py <export|export0|write|merge> ...")
    action = args[0]
    if action == "export":
        if len(args) != 2:
            _die("usage: state_file.py export <path>")
        print(render_shell_assignments(Path(args[1]).resolve()))
        return
    if action == "export0":
        if len(args) != 2:
            _die("usage: state_file.py export0 <path>")
        sys.stdout.buffer.write(render_null_assignments(Path(args[1]).resolve()))
        return
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
