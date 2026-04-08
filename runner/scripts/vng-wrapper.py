#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import shlex
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parents[2]


def _debug_enabled() -> bool:
    return os.environ.get("VNG_WRAPPER_DEBUG", "0").strip() == "1"


def _debug(message: str) -> None:
    if _debug_enabled():
        print(message, file=sys.stderr)


def _exec_vng(args: list[str]) -> None:
    _debug("vng-wrapper exec: vng " + " ".join(shlex.quote(arg) for arg in args))
    os.execvp("vng", ["vng", *args])


def _run_under_script(args: list[str]) -> None:
    if shutil.which("script") is None:
        raise SystemExit("[vng-wrapper][ERROR] missing required host command: script")
    with tempfile.NamedTemporaryFile(prefix="vng-wrapper-log.", delete=False) as handle:
        log_path = Path(handle.name)
    command = [sys.executable, str(Path(__file__).resolve()), "--exec-from-script", *args]
    try:
        completed = subprocess.run(
            ["script", "-qfec", shlex.join(command), str(log_path)],
            check=False,
        )
        if log_path.exists():
            sys.stdout.write(log_path.read_text(encoding="utf-8", errors="replace"))
        raise SystemExit(completed.returncode)
    finally:
        log_path.unlink(missing_ok=True)


def main(argv: list[str] | None = None) -> None:
    raw_args = list(sys.argv[1:] if argv is None else argv)
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument("--exec-from-script", action="store_true")
    known, remaining = parser.parse_known_args(raw_args)
    if known.exec_from_script:
        _exec_vng(remaining)
        return
    if all(os.isatty(fd) for fd in (0, 1, 2)):
        _exec_vng(remaining)
        return
    _run_under_script(remaining)


if __name__ == "__main__":
    main()
