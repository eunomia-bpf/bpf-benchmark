#!/usr/bin/env python3
"""Attribute reported map_inline sites to retained workdir-local map snapshots."""
from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from pathlib import Path
from typing import Any


EXPECTED_PASSES = ["map_inline"]

# Accepted corpus run types: x86 KVM and arm64 QEMU both drive the same
# loader-interception protocol, so the audit gates on the suite and the run's
# own records rather than on the executor architecture.
CORPUS_RUN_TYPES = {"x86_kvm_corpus", "arm64_qemu_corpus"}


class AuditError(ValueError):
    """An input or declared-contract error that prevents the audit."""


def read_json(path: Path) -> Any:
    try:
        return json.loads(path.read_text())
    except (OSError, json.JSONDecodeError) as exc:
        raise AuditError(f"cannot read JSON {path}: {exc}") from exc


def require(condition: bool, message: str) -> None:
    if not condition:
        raise AuditError(message)


def parse_hex(value: Any, label: str) -> bytes:
    require(isinstance(value, str), f"{label}: expected a hex string")
    require(len(value) % 2 == 0, f"{label}: hex string has odd length")
    try:
        return bytes.fromhex(value)
    except ValueError as exc:
        raise AuditError(f"{label}: malformed hex string") from exc


def dump_bytes(value: Any, label: str) -> bytes:
    require(isinstance(value, list), f"{label}: expected a byte array")
    result = bytearray()
    for index, item in enumerate(value):
        require(isinstance(item, str), f"{label}[{index}]: expected a byte string")
        try:
            parsed = int(item, 16)
        except ValueError as exc:
            raise AuditError(f"{label}[{index}]: malformed byte") from exc
        require(0 <= parsed <= 255, f"{label}[{index}]: byte is out of range")
        result.append(parsed)
    return bytes(result)


# Per-application audit contract. `expected_entries` names the map population
# that must account for every reported applied site; it is the falsifiable
# expectation this audit checks, not a derived metric. `dump_key_match` states
# whether the workdir map snapshot is expected to contain the inlined key:
# Cilium's values come from snapshotted maps, while Katran's hinted maps are
# size-skipped or filled from static overlays, so the dump holds no entry.
APP_CONTRACTS: dict[str, dict[str, Any]] = {
    "cilium/agent": {
        "stem": "cilium__agent",
        "expected_entries": "rodata_config",
        "dump_key_match": "required",
    },
    # Katran's map_inline policy specializes exactly the hinted maps (see
    # runner/config/passes/map_inline/katran.yaml); any other map inlined into
    # balancer_ingress would mean an unhinted site was rewritten.
    "katran": {
        "stem": "katran",
        "expected_entries": "katran_hinted_maps",
        "entry_maps": {
            "ctl_array",
            "vip_map",
            "ch_rings",
            "reals",
            "server_id_map",
        },
        "dump_key_match": "optional",
    },
    # Tracee's default map_inline policy inlines its two global config arrays
    # (see corpus/config/benchmark_config.yaml `full-x86`); their values are
    # snapshotted from the live map, so the inlined key must be present.
    "tracee/monitor": {
        "stem": "tracee__monitor",
        "expected_entries": "declared_entry_maps",
        "entry_maps": {"config_map", "netconfig_map"},
        "dump_key_match": "required",
    },
    # Tetragon's default map_inline policy has no hint file either; the
    # optimizer discovers its map references through --map-ids. The declared
    # set is the union of the array maps its own programs reference
    # (tg_conf_map's policy/config/stat arrays, the cgroup rate opts, the
    # frozen .rodata, and one generic tracing config_map), and the audit's
    # falsifiable expectation is that no *other* map is inlined.
    "tetragon/observer": {
        "stem": "tetragon__observer",
        "expected_entries": "declared_entry_maps",
        "entry_maps": {
            "tg_conf_map",
            "policy_conf",
            "policy_stats",
            "cgroup_rate_opt",
            ".rodata",
            "config_map",
        },
        "dump_key_match": "required",
    },
}


def validate_protocol(run_dir: Path, app: str) -> tuple[dict[str, Any], Path]:
    contract = APP_CONTRACTS.get(app)
    require(contract is not None, f"no audit contract for app {app!r}")
    stem = contract["stem"]
    metadata = read_json(run_dir / "metadata.json")
    app_path = run_dir / "details" / "apps" / f"{stem}.json"
    plan_path = run_dir / "details" / "loadtime-plans" / f"{stem}.json"
    reports_path = run_dir / "details" / "loadtime-reports" / f"{stem}.jsonl"
    app_data = read_json(app_path)
    plan = read_json(plan_path)

    require(metadata.get("status") == "completed", "suite status is not completed")
    require(metadata.get("suite") == "corpus", "suite is not corpus")
    require(
        metadata.get("run_type") in CORPUS_RUN_TYPES,
        f"run type {metadata.get('run_type')!r} is not a corpus run type",
    )
    require(metadata.get("samples") == 1, "sample count is not one")
    require(metadata.get("workload_seconds") == 30.0, "workload duration is not 30 seconds")
    require(
        (metadata.get("config") or {}).get("enabled_passes") == EXPECTED_PASSES,
        "enabled pass list is not exactly map_inline",
    )
    require(app_data.get("app") == app, f"application is not {app}")
    require(app_data.get("status") == "ok", f"{app} application status is not ok")
    require(app_data.get("error") == "", f"{app} application error is not empty")
    require(plan.get("cmd") == "execute_plan", "load-time plan command mismatch")
    steps = plan.get("steps")
    require(isinstance(steps, list) and len(steps) == 1, "plan is not one step")
    require(steps[0].get("name") == "map_inline", "plan step is not map_inline")
    require(
        "--pass map_inline" in str(steps[0].get("command", "")),
        "plan command does not select map_inline",
    )
    require(reports_path.is_file(), f"missing report stream: {reports_path}")
    return metadata, reports_path


def load_report_rows(reports_path: Path) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    try:
        lines = reports_path.read_text().splitlines()
    except OSError as exc:
        raise AuditError(f"cannot read report stream {reports_path}: {exc}") from exc
    for line_number, line in enumerate(lines, start=1):
        if not line.strip():
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError as exc:
            raise AuditError(f"report line {line_number}: malformed JSON: {exc}") from exc
        require(isinstance(row, dict), f"report line {line_number}: row is not an object")
        row["_line_number"] = line_number
        rows.append(row)
    require(rows, "report stream is empty")
    return rows


def find_dump_entry(dump: Any, key: bytes, label: str) -> dict[str, Any]:
    require(isinstance(dump, list), f"{label}: dump is not a list")
    matches: list[dict[str, Any]] = []
    for index, entry in enumerate(dump):
        require(isinstance(entry, dict), f"{label}[{index}]: entry is not an object")
        if dump_bytes(entry.get("key"), f"{label}[{index}].key") == key:
            matches.append(entry)
    require(len(matches) == 1, f"{label}: key has {len(matches)} dump matches")
    return matches[0]


def audit(
    run_dir: Path, selected_workdir: str | None, app: str
) -> tuple[dict[str, Any], int]:
    run_dir = run_dir.resolve()
    require(run_dir.is_dir(), f"run directory not found: {run_dir}")
    metadata, reports_path = validate_protocol(run_dir, app)
    contract = APP_CONTRACTS[app]
    rows = load_report_rows(reports_path)
    workdirs_root = run_dir / "details" / "loadtime-workdirs"

    available_workdirs = [Path(str(row.get("workdir", ""))).name for row in rows]
    if selected_workdir is not None:
        require(
            available_workdirs.count(selected_workdir) == 1,
            f"selected workdir occurs {available_workdirs.count(selected_workdir)} times",
        )

    report_rows = 0
    unchanged_rows = 0
    changed_rows = 0
    sites_applied = 0
    weak_value_matches = 0
    weak_value_dump_skipped = 0
    weak_value_misses = 0
    map_groups: Counter[tuple[str, str, int, int]] = Counter()
    map_group_workdirs: dict[tuple[str, str, int, int], set[str]] = {}
    program_groups: Counter[tuple[str, str, str, str, int]] = Counter()
    changed_programs: Counter[tuple[str, str]] = Counter()
    dump_cache: dict[Path, Any] = {}
    metadata_cache: dict[Path, dict[str, Any]] = {}

    for row in rows:
        workdir_name = Path(str(row.get("workdir", ""))).name
        if selected_workdir is not None and workdir_name != selected_workdir:
            continue
        line = row["_line_number"]
        label = f"report line {line} ({workdir_name})"
        report_rows += 1
        require(row.get("step") == "map_inline", f"{label}: step is not map_inline")
        require(row.get("step_index") == 0, f"{label}: step index is not zero")
        report = row.get("report")
        require(isinstance(report, dict), f"{label}: report object is missing")
        require(report.get("pass") == "map_inline", f"{label}: report pass mismatch")

        counts: dict[str, int] = {}
        for field in ("sites_matched", "sites_applied", "sites_skipped"):
            value = report.get(field)
            require(isinstance(value, int) and value >= 0, f"{label}: invalid {field}")
            counts[field] = value
        require(
            counts["sites_matched"]
            == counts["sites_applied"] + counts["sites_skipped"],
            f"{label}: matched != applied + skipped",
        )
        entries = report.get("inlined_map_entries")
        require(isinstance(entries, list), f"{label}: inlined entries are not a list")
        require(
            len(entries) == counts["sites_applied"],
            f"{label}: entry count differs from applied sites",
        )
        if not counts["sites_applied"]:
            unchanged_rows += 1
            continue

        changed_rows += 1
        sites_applied += counts["sites_applied"]
        prog_name = str(row.get("prog_name", ""))
        prog_type = str(row.get("prog_type", ""))
        changed_programs[(prog_name, prog_type)] += 1
        workdir = workdirs_root / workdir_name
        require(workdir.is_dir(), f"{label}: retained workdir is missing")

        for entry_index, entry in enumerate(entries):
            entry_label = f"{label}: entry {entry_index}"
            require(isinstance(entry, dict), f"{entry_label}: entry is not an object")
            map_id = entry.get("map_id")
            require(isinstance(map_id, int) and map_id > 0, f"{entry_label}: invalid map_id")
            require(
                entry.get("stability") == "phase-stable",
                f"{entry_label}: stability is not phase-stable",
            )
            key = parse_hex(entry.get("key_hex"), f"{entry_label}.key_hex")
            value = parse_hex(entry.get("value_hex"), f"{entry_label}.value_hex")


            show_path = workdir / "map-values" / f"map-{map_id}.show.json"
            dump_path = workdir / "map-values" / f"map-{map_id}.dump.json"
            require(show_path.is_file(), f"{entry_label}: map metadata is missing")
            if show_path not in metadata_cache:
                show = read_json(show_path)
                require(isinstance(show, dict), f"{entry_label}: map metadata is not an object")
                metadata_cache[show_path] = show
            show = metadata_cache[show_path]
            require(show.get("id") == map_id, f"{entry_label}: map metadata ID mismatch")
            map_name = show.get("name")
            map_type = show.get("type")
            flags = show.get("flags")
            frozen = show.get("frozen")
            require(isinstance(map_name, str) and map_name, f"{entry_label}: missing map name")
            require(isinstance(map_type, str) and map_type, f"{entry_label}: missing map type")
            require(isinstance(flags, int) and flags >= 0, f"{entry_label}: invalid flags")
            require(frozen in (0, 1), f"{entry_label}: invalid frozen state")

            require(dump_path.is_file(), f"{entry_label}: map dump is missing")
            if dump_path not in dump_cache:
                dump_cache[dump_path] = read_json(dump_path)
            dump = dump_cache[dump_path]
            dump_entry = None
            if isinstance(dump, dict) and dump.get("skipped") is True:
                pass
            elif isinstance(dump, list):
                candidates = [
                    entry
                    for entry in dump
                    if isinstance(entry, dict)
                    and dump_bytes(entry.get("key"), f"{entry_label}.dump.key") == key
                ]
                require(
                    len(candidates) <= 1,
                    f"{entry_label}: key has {len(candidates)} dump matches",
                )
                if candidates:
                    dump_entry = candidates[0]
                elif contract["dump_key_match"] == "required":
                    require(False, f"{entry_label}: key has 0 dump matches")
            else:
                require(False, f"{entry_label}: map dump is neither list nor skip record")
            if dump_entry is None:
                # Snapshot value is unavailable (size-skipped map, or a hinted
                # map whose entry is injected from a static overlay); the value
                # check is excluded from this diagnostic's denominator rather
                # than counted as a miss.
                weak_value_dump_skipped += 1
            else:
                snapshot_value = dump_bytes(
                    dump_entry.get("value"), f"{entry_label}: dump value"
                )
                if value in snapshot_value:
                    weak_value_matches += 1
                else:
                    weak_value_misses += 1

            map_key = (map_name, map_type, int(frozen), flags)
            map_groups[map_key] += 1
            map_group_workdirs.setdefault(map_key, set()).add(workdir_name)
            program_groups[(prog_name, prog_type, map_name, map_type, int(frozen))] += 1

    require(report_rows > 0, "workdir filter selected no report rows")
    if contract["expected_entries"] == "rodata_config":
        expected_entries = sum(
            count
            for (name, map_type, frozen, _flags), count in map_groups.items()
            if name == ".rodata.config" and map_type == "array" and frozen == 1
        )
    else:
        allowed = contract["entry_maps"]
        expected_entries = sum(
            count
            for (name, _map_type, _frozen, _flags), count in map_groups.items()
            if name in allowed
        )
        unexpected = sorted(
            {
                name
                for (name, _map_type, _frozen, _flags) in map_groups
                if name not in allowed
            }
        )
        require(
            not unexpected,
            f"{app}: inlined maps outside the declared hint set: {unexpected}",
        )
    if sites_applied == 0:
        outcome = "contradicted"
    elif expected_entries == sites_applied:
        outcome = "supported"
    elif expected_entries:
        outcome = "mixed"
    else:
        outcome = "contradicted"

    result = {
        "outcome": outcome,
        "scope": {
            "artifact": str(run_dir),
            "application": app,
            "enabled_passes": EXPECTED_PASSES,
            "samples": metadata["samples"],
            "workload_seconds": metadata["workload_seconds"],
            "selected_workdir": selected_workdir,
            "claim_boundary": (
                "attributes optimizer-reported entries to workdir-local map metadata; "
                "does not prove bytecode rewriting, exact value offsets, attachment, "
                "execution, stability across starts, or throughput causality"
            ),
        },
        "reports": {
            "rows": report_rows,
            "rows_without_applied_sites": unchanged_rows,
            "changed_load_instances": changed_rows,
            "sites_applied": sites_applied,
            "changed_program_name_type_pairs": [
                {
                    "prog_name": key[0],
                    "prog_type": key[1],
                    "changed_load_instances": changed_programs[key],
                }
                for key in sorted(changed_programs)
            ],
        },
        "map_classes": [
            {
                "map_name": key[0],
                "map_type": key[1],
                "frozen": key[2],
                "flags": key[3],
                "applied_entry_occurrences": map_groups[key],
                "changed_workdirs": len(map_group_workdirs[key]),
            }
            for key in sorted(map_groups)
        ],
        "program_map_classes": [
            {
                "prog_name": key[0],
                "prog_type": key[1],
                "map_name": key[2],
                "map_type": key[3],
                "frozen": key[4],
                "applied_entry_occurrences": program_groups[key],
            }
            for key in sorted(program_groups)
        ],
        "weak_value_diagnostic": {
            "description": (
                "reported value bytes occur contiguously in the snapshot value; "
                "the report omits source offsets, so matches are not provenance proof"
            ),
            "matches": weak_value_matches,
            "misses": weak_value_misses,
            "skipped_dump_unavailable": weak_value_dump_skipped,
        },
    }
    return result, 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("run_dir", type=Path)
    parser.add_argument("--app", required=True)
    parser.add_argument("--workdir")
    args = parser.parse_args()
    try:
        result, exit_code = audit(args.run_dir, args.workdir, args.app)
    except AuditError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    print(json.dumps(result, indent=2, sort_keys=True))
    return exit_code


if __name__ == "__main__":
    raise SystemExit(main())
