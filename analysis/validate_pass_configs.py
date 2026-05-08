#!/usr/bin/env python3
"""Validate runner/config/passes/ yaml against `bpfopt list-passes --json`.

Catches drift between yaml step templates and the actual bpfopt CLI:
  - Yaml exists for every pass bpfopt reports
  - Yaml command's --pass argument matches the pass name
  - Pass declares the correct side-input flags vs Rust pass impl
    (--target ↔ needs_target, --verifier-states ↔ needs_verifier_states,
     --map-values / --map-ids ↔ needs_map_values)
  - Yaml `kinsns` block matches bpfopt's `kinsns_used` for that pass
  - App overrides only reference passes that exist
  - App override programs.<name>.command also has --pass <name>

Run from repo root::

    python analysis/validate_pass_configs.py
    python analysis/validate_pass_configs.py --bpfopt /custom/path/bpfopt

Exit code 0 if valid, 1 if any drift.
"""
from __future__ import annotations

import argparse
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Any

import yaml

REPO_ROOT = Path(__file__).resolve().parents[1]
CONFIG_ROOT = REPO_ROOT / "runner" / "config" / "passes"


def run_bpfopt_list(bpfopt_bin: str) -> dict[str, dict[str, Any]]:
    completed = subprocess.run(
        [bpfopt_bin, "list-passes", "--json"],
        check=True,
        capture_output=True,
        text=True,
    )
    entries = json.loads(completed.stdout)
    return {e["canonical_name"]: e for e in entries}


def load_yaml_file(path: Path) -> dict[str, Any]:
    with open(path) as fh:
        return yaml.safe_load(fh)


def extract_command_string(payload: dict[str, Any], where: str) -> str:
    cmd = payload.get("command")
    if not isinstance(cmd, str) or not cmd.strip():
        raise RuntimeError(f"{where}: missing or empty 'command' string")
    return " ".join(cmd.split())


def check_pass_yaml(
    pass_name: str,
    pass_meta: dict[str, Any],
    yaml_path: Path,
    errors: list[str],
) -> None:
    payload = load_yaml_file(yaml_path)
    cmd = extract_command_string(payload, str(yaml_path))

    # 1. --pass <name>
    if f"--pass {pass_name}" not in cmd:
        errors.append(f"{yaml_path}: command missing '--pass {pass_name}'")

    # 2. side-input flags
    needs_target = bool(pass_meta.get("needs_target"))
    needs_states = bool(pass_meta.get("needs_verifier_states"))
    needs_maps = bool(pass_meta.get("needs_map_values"))

    has_target_flag = "--target ${TARGET}" in cmd
    has_states_flag = "--verifier-states ${VERIFIER_STATES}" in cmd
    has_map_values_flag = "--map-values ${MAP_VALUES}" in cmd
    has_map_ids_flag = "--map-ids ${MAP_IDS}" in cmd

    if needs_target and not has_target_flag:
        errors.append(f"{yaml_path}: pass declares needs_target but command lacks '--target ${{TARGET}}'")
    if not needs_target and has_target_flag:
        errors.append(f"{yaml_path}: command has '--target' but pass does not declare needs_target")

    if needs_states and not has_states_flag:
        errors.append(f"{yaml_path}: pass declares needs_verifier_states but command lacks '--verifier-states ${{VERIFIER_STATES}}'")
    if not needs_states and has_states_flag:
        errors.append(f"{yaml_path}: command has '--verifier-states' but pass does not declare needs_verifier_states")

    if needs_maps and not (has_map_values_flag and has_map_ids_flag):
        errors.append(f"{yaml_path}: pass declares needs_map_values but command lacks '--map-values'/'--map-ids'")
    if not needs_maps and (has_map_values_flag or has_map_ids_flag):
        errors.append(f"{yaml_path}: command has '--map-values'/'--map-ids' but pass does not declare needs_map_values")

    # 3. log_level coherence: passes that need verifier states should have log_level=2,
    # passes that don't can be log_level=1 (predecessor doesn't need to spend the L2 cost).
    log_level = payload.get("log_level")
    if needs_states and log_level != 2:
        errors.append(
            f"{yaml_path}: pass needs verifier states but log_level={log_level!r} (must be 2)"
        )
    if not needs_states and log_level not in (1, 2):
        errors.append(
            f"{yaml_path}: log_level must be 1 or 2 (got {log_level!r})"
        )

    # 4. kinsns match
    expected_kinsns = {
        str(k.get("json_name") or "").strip(): tuple(sorted(
            str(a).strip()
            for a in (k.get("probe_aliases") or [])
            if str(a).strip()
        ))
        for k in (pass_meta.get("kinsns_used") or [])
    }
    declared_kinsns = {}
    for entry in payload.get("kinsns") or []:
        name = str(entry.get("name") or "").strip()
        aliases = tuple(sorted(
            str(a).strip()
            for a in (entry.get("aliases") or [])
            if str(a).strip()
        ))
        declared_kinsns[name] = aliases
    if expected_kinsns != declared_kinsns:
        errors.append(
            f"{yaml_path}: kinsns mismatch.\n"
            f"  yaml declares: {declared_kinsns}\n"
            f"  bpfopt reports: {expected_kinsns}"
        )


def check_app_yaml(
    pass_name: str,
    yaml_path: Path,
    errors: list[str],
) -> None:
    payload = load_yaml_file(yaml_path)
    programs = payload.get("programs")
    if not isinstance(programs, dict):
        errors.append(f"{yaml_path}: app override missing 'programs' map")
        return
    if "default" not in programs:
        errors.append(f"{yaml_path}: app override missing 'programs.default' fallback")
    for prog_name, entry in programs.items():
        if not isinstance(entry, dict):
            errors.append(f"{yaml_path}: programs.{prog_name} must be a map")
            continue
        if "command" not in entry:
            errors.append(f"{yaml_path}: programs.{prog_name} missing 'command'")
            continue
        cmd = " ".join(str(entry["command"]).split())
        if f"--pass {pass_name}" not in cmd:
            errors.append(
                f"{yaml_path}: programs.{prog_name}.command must contain '--pass {pass_name}'"
            )


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument(
        "--bpfopt",
        default=None,
        help="path to bpfopt binary (default: auto-detect via PATH or bpfopt/target/release/bpfopt)",
    )
    args = ap.parse_args()

    bpfopt_bin = args.bpfopt
    if bpfopt_bin is None:
        candidate = REPO_ROOT / "bpfopt" / "target" / "release" / "bpfopt"
        if candidate.is_file():
            bpfopt_bin = str(candidate)
        else:
            bpfopt_bin = shutil.which("bpfopt")
    if bpfopt_bin is None:
        print("error: bpfopt binary not found; pass --bpfopt or build bpfopt first", file=sys.stderr)
        return 2

    pass_meta_by_name = run_bpfopt_list(bpfopt_bin)
    errors: list[str] = []

    # 1. each pass reported by bpfopt has a runner default.yaml
    for pass_name in pass_meta_by_name:
        yaml_path = CONFIG_ROOT / pass_name / "default.yaml"
        if not yaml_path.is_file():
            errors.append(f"missing {yaml_path}: pass '{pass_name}' reported by bpfopt has no runner config")
            continue
        check_pass_yaml(pass_name, pass_meta_by_name[pass_name], yaml_path, errors)

    # 2. each pass dir under runner/config/passes/ corresponds to a real pass
    for pass_dir in sorted(CONFIG_ROOT.iterdir()):
        if not pass_dir.is_dir():
            continue
        if pass_dir.name not in pass_meta_by_name:
            errors.append(
                f"{pass_dir}: yaml dir for pass '{pass_dir.name}' but bpfopt does not report this pass"
            )

    # 3. validate app override yamls
    for pass_dir in sorted(CONFIG_ROOT.iterdir()):
        if not pass_dir.is_dir():
            continue
        for yaml_path in sorted(pass_dir.iterdir()):
            if yaml_path.name == "default.yaml" or not yaml_path.suffix == ".yaml":
                continue
            check_app_yaml(pass_dir.name, yaml_path, errors)

    if errors:
        print(f"FAIL: {len(errors)} pass-config validation error(s)", file=sys.stderr)
        for e in errors:
            print(f"  {e}", file=sys.stderr)
        return 1

    print(f"OK: {len(pass_meta_by_name)} passes validated, app overrides consistent")
    return 0


if __name__ == "__main__":
    sys.exit(main())
