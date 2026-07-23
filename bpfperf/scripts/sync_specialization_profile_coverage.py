#!/usr/bin/env python3
"""Synchronize exact program-hash coverage across specialization profiles.

The canonical coverage directory records every program hash observed for an
application.  This tool creates explicit empty profiles for missing hashes in
the selected target passes.  Existing profiles, including nonempty PMU-derived
profiles, are never overwritten.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import re
import sys
from typing import Any


PROGRAM_PROFILE_RE = re.compile(r"hash-([0-9a-f]{16})\.json")
EMPTY_PAYLOADS: dict[str, dict[str, Any]] = {
    "tail_call_icache": {"per_site": {}},
    "hot_region_version": {"per_site": {}},
}


class CoverageError(ValueError):
    pass


def load_profile(path: Path) -> dict[str, Any]:
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise CoverageError(f"{path}: cannot read profile: {error}") from error
    if not isinstance(value, dict):
        raise CoverageError(f"{path}: profile must be a JSON object")
    return value


def profile_hash(path: Path) -> str:
    match = PROGRAM_PROFILE_RE.fullmatch(path.name)
    if match is None:
        raise CoverageError(
            f"{path}: expected filename hash-<16 lowercase hex>.json"
        )
    value = load_profile(path)
    expected = match.group(1)
    if value.get("program_hash") != expected:
        raise CoverageError(
            f"{path}: program_hash must match filename ({expected})"
        )
    return expected


def sync_coverage(
    coverage_root: Path,
    pass_roots: dict[str, Path],
) -> list[Path]:
    coverage_files = sorted(coverage_root.glob("hash-*.json"))
    if not coverage_files:
        raise CoverageError(
            f"{coverage_root}: no canonical hash profiles found"
        )
    hashes = [profile_hash(path) for path in coverage_files]
    created: list[Path] = []
    for pass_name, target_root in pass_roots.items():
        payload = EMPTY_PAYLOADS[pass_name]
        target_root.mkdir(parents=True, exist_ok=True)
        for program_hash in hashes:
            target = target_root / f"hash-{program_hash}.json"
            if target.exists():
                profile_hash(target)
                continue
            profile = {
                "schema_version": 1,
                "pass": pass_name,
                "program_hash": program_hash,
                **payload,
            }
            target.write_text(
                json.dumps(profile, indent=2, sort_keys=True) + "\n",
                encoding="utf-8",
            )
            created.append(target)
    return created


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--coverage-root", required=True, type=Path)
    parser.add_argument(
        "--target",
        required=True,
        action="append",
        metavar="PASS=DIR",
        help="target pass and profile directory; may be repeated",
    )
    return parser.parse_args()


def parse_targets(raw_targets: list[str]) -> dict[str, Path]:
    targets: dict[str, Path] = {}
    for raw in raw_targets:
        pass_name, separator, raw_path = raw.partition("=")
        if not separator or not raw_path:
            raise CoverageError(f"invalid --target {raw!r}; expected PASS=DIR")
        if pass_name not in EMPTY_PAYLOADS:
            supported = ", ".join(sorted(EMPTY_PAYLOADS))
            raise CoverageError(
                f"unsupported target pass {pass_name!r}; expected {supported}"
            )
        if pass_name in targets:
            raise CoverageError(f"duplicate --target for {pass_name}")
        targets[pass_name] = Path(raw_path)
    return targets


def main() -> int:
    args = parse_args()
    try:
        targets = parse_targets(args.target)
        created = sync_coverage(args.coverage_root, targets)
    except CoverageError as error:
        print(f"sync_specialization_profile_coverage: {error}", file=sys.stderr)
        return 1
    print(f"created {len(created)} explicit empty profiles")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
