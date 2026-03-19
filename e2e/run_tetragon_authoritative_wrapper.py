from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any, Mapping


ROOT_DIR = Path(__file__).resolve().parent.parent
if str(ROOT_DIR) not in sys.path:
    sys.path.insert(0, str(ROOT_DIR))

from e2e.cases.tetragon.case import build_case_parser, build_markdown, run_tetragon_case  # noqa: E402
from e2e.common import chown_to_invoking_user, ensure_parent  # noqa: E402


def _scalar(value: object) -> bool:
    return value is None or isinstance(value, (str, int, float, bool))


def _prune_site(site: object) -> object:
    if not isinstance(site, Mapping):
        return site
    preferred = (
        "family",
        "offset",
        "insn_idx",
        "insn_off",
        "address",
        "kind",
        "symbol",
        "old",
        "new",
        "note",
    )
    pruned = {key: site.get(key) for key in preferred if key in site and _scalar(site.get(key))}
    if pruned:
        return pruned
    return {key: value for key, value in site.items() if _scalar(value)}


def _detail_program(name: object) -> bool:
    text = str(name or "").strip().lower()
    return "generic_kprobe" in text or "kprobe_multi" in text or "socket_connect" in text or "connect" in text


def _prune_enumerate_record(record: object, *, keep_sites: bool) -> object:
    if not isinstance(record, Mapping):
        return record
    pruned: dict[str, object] = {}
    for key in ("id", "name", "type", "summary", "family_counts", "error"):
        if key in record:
            pruned[key] = record.get(key)
    sites = record.get("sites")
    if keep_sites and isinstance(sites, list):
        pruned["sites"] = [_prune_site(site) for site in sites]
    return pruned


def _prune_live_manifest(manifest: object, *, keep_sites: bool) -> object:
    if not isinstance(manifest, Mapping):
        return manifest
    pruned: dict[str, object] = {}
    for key in ("id", "name", "type", "summary", "family_counts"):
        if key in manifest:
            pruned[key] = manifest.get(key)
    sites = manifest.get("sites")
    if keep_sites and isinstance(sites, list):
        pruned["sites"] = [_prune_site(site) for site in sites]
    return pruned


def _compact_scan_results(payload: Mapping[str, object]) -> dict[str, object]:
    results = payload.get("scan_results")
    if not isinstance(results, Mapping):
        return {}
    compact: dict[str, object] = {}
    for prog_id, raw in results.items():
        if not isinstance(raw, Mapping):
            compact[str(prog_id)] = raw
            continue
        program_name = raw.get("program_name")
        keep_sites = _detail_program(program_name)
        entry: dict[str, object] = {
            "program_name": program_name,
            "sites": raw.get("sites"),
            "error": raw.get("error"),
        }
        if raw.get("enumerate_record"):
            entry["enumerate_record"] = _prune_enumerate_record(raw.get("enumerate_record"), keep_sites=keep_sites)
        compact[str(prog_id)] = entry
    return compact


def _compact_recompile_results(payload: Mapping[str, object]) -> dict[str, object]:
    results = payload.get("recompile_results")
    if not isinstance(results, Mapping):
        return {}
    compact: dict[str, object] = {}
    for prog_id, raw in results.items():
        if not isinstance(raw, Mapping):
            compact[str(prog_id)] = raw
            continue
        program_name = raw.get("program_name")
        keep_sites = _detail_program(program_name)
        entry: dict[str, object] = {
            "program_name": program_name,
            "counts": raw.get("counts"),
            "applied": raw.get("applied"),
            "policy_file": raw.get("policy_file"),
            "policy_mode": raw.get("policy_mode"),
            "error": raw.get("error"),
            "remap_summary": raw.get("remap_summary"),
        }
        if raw.get("scan_record"):
            entry["scan_record"] = _prune_enumerate_record(raw.get("scan_record"), keep_sites=keep_sites)
        if raw.get("live_manifest"):
            entry["live_manifest"] = _prune_live_manifest(raw.get("live_manifest"), keep_sites=keep_sites)
        compact[str(prog_id)] = entry
    return compact


def build_compact_payload(payload: Mapping[str, object]) -> dict[str, object]:
    compact = {
        "generated_at": payload.get("generated_at"),
        "mode": payload.get("mode"),
        "smoke": payload.get("smoke"),
        "duration_s": payload.get("duration_s"),
        "tetragon_binary": payload.get("tetragon_binary"),
        "setup": payload.get("setup"),
        "host": payload.get("host"),
        "tetragon_launch_command": payload.get("tetragon_launch_command"),
        "tetragon_programs": payload.get("tetragon_programs"),
        "agent_logs": payload.get("agent_logs"),
        "baseline": payload.get("baseline"),
        "policy_matches": payload.get("policy_matches"),
        "policy_summary": payload.get("policy_summary"),
        "recompile_summary": payload.get("recompile_summary"),
        "post_rejit": payload.get("post_rejit"),
        "programs": payload.get("programs"),
        "comparison": payload.get("comparison"),
        "limitations": payload.get("limitations"),
        "fallback_reason": payload.get("fallback_reason"),
        "scan_results": _compact_scan_results(payload),
        "recompile_results": _compact_recompile_results(payload),
        "wrapper": {
            "compact_payload": True,
            "reason": "Avoid rwdir stalls from persisting full raw scan artifacts while preserving authoritative benchmark metrics and per-program site summaries.",
        },
    }
    if payload.get("policy_dir") is not None:
        compact["policy_dir"] = payload.get("policy_dir")
    if payload.get("policy_paths") is not None:
        compact["policy_paths"] = payload.get("policy_paths")
    return compact


def build_stdout_summary(payload: Mapping[str, object]) -> dict[str, object]:
    programs = payload.get("tetragon_programs") or []
    comparison = payload.get("comparison") or {}
    connect_delta = None
    if isinstance(comparison, Mapping):
        for row in comparison.get("workloads") or []:
            if isinstance(row, Mapping) and row.get("name") == "connect_storm":
                connect_delta = row.get("app_throughput_delta_pct")
                break
    return {
        "generated_at": payload.get("generated_at"),
        "mode": payload.get("mode"),
        "program_count": len(programs) if isinstance(programs, list) else None,
        "program_names": [record.get("name") for record in programs if isinstance(record, Mapping)],
        "applied_programs": ((payload.get("recompile_summary") or {}).get("applied_programs")),
        "connect_storm_delta_pct": connect_delta,
    }


def write_compact_json(path: Path, payload: Mapping[str, object]) -> None:
    ensure_parent(path)
    path.write_text(json.dumps(payload, sort_keys=True, separators=(",", ":")) + "\n")
    chown_to_invoking_user(path)


def write_markdown(path: Path, payload: Mapping[str, object]) -> None:
    ensure_parent(path)
    path.write_text(build_markdown(payload))
    chown_to_invoking_user(path)


def main(argv: list[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    payload = run_tetragon_case(args)
    compact = build_compact_payload(payload)
    print(json.dumps({"wrapper_status": "payload_ready", "summary": build_stdout_summary(payload)}, sort_keys=True), flush=True)
    write_compact_json(Path(args.output_json).resolve(), compact)
    write_markdown(Path(args.output_md).resolve(), compact)
    print(json.dumps({"wrapper_status": "persisted", "output_json": str(Path(args.output_json).resolve())}, sort_keys=True), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
