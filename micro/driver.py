#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

try:
    from benchmark_catalog import CONFIG_PATH, ROOT_DIR
except ImportError:
    from micro.benchmark_catalog import CONFIG_PATH, ROOT_DIR
try:
    from runner.libs.catalog import load_catalog
except ImportError:
    from runner.libs.catalog import load_catalog

try:
    import _driver_impl_run_micro as run_micro_impl
    import _driver_impl_run_rigorous as run_rigorous_impl
    import _driver_impl_run_rigorous_framework_vm as run_rigorous_framework_vm_impl
except ImportError:
    from micro import (
        _driver_impl_run_micro as run_micro_impl,
        _driver_impl_run_rigorous as run_rigorous_impl,
        _driver_impl_run_rigorous_framework_vm as run_rigorous_framework_vm_impl,
    )

def _strip_separator(argv: list[str]) -> list[str]:
    return [arg for arg in argv if arg != "--"]


def _require_micro_manifest(argv: list[str]) -> None:
    parser = argparse.ArgumentParser(prog="micro/driver.py suite", add_help=False)
    parser.add_argument("--suite", default=str(CONFIG_PATH))
    known, _ = parser.parse_known_args(argv)
    suite_path = Path(known.suite).resolve()
    try:
        catalog = load_catalog(suite_path)
    except Exception as exc:
        raise SystemExit(f"failed to load suite manifest {suite_path}: {exc}") from exc
    if str(catalog.manifest_kind) != "micro":
        raise SystemExit(
            f"micro/driver.py only supports micro manifests; "
            f"use corpus/driver.py for {catalog.manifest_kind} manifests ({suite_path})"
        )


def _suite_entry(argv: list[str]) -> int:
    argv = _strip_separator(list(argv))
    _require_micro_manifest(argv)
    return run_micro_impl.main(argv)


def _rigorous_entry(argv: list[str]) -> int:
    argv = _strip_separator(list(argv))
    parser = argparse.ArgumentParser(prog="micro/driver.py rigorous", add_help=False)
    parser.add_argument("--transport", choices=["local", "vm"], default="local")
    known, remaining = parser.parse_known_args(argv)
    remaining = _strip_separator(remaining)
    if known.transport == "vm":
        return run_rigorous_framework_vm_impl.main(remaining)
    return run_rigorous_impl.main(remaining)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Micro benchmark driver.")
    parser.add_argument("subcommand", choices=["suite", "rigorous"])
    parser.add_argument("args", nargs=argparse.REMAINDER)
    return parser


def main(argv: list[str] | None = None) -> int:
    parsed = build_parser().parse_args(argv)
    if parsed.args and parsed.args[0] == "--":
        forwarded = parsed.args[1:]
    else:
        forwarded = list(parsed.args)

    if parsed.subcommand == "suite":
        return _suite_entry(forwarded)
    if parsed.subcommand == "rigorous":
        return _rigorous_entry(forwarded)
    raise SystemExit(f"unsupported subcommand: {parsed.subcommand}")


if __name__ == "__main__":
    raise SystemExit(main())
