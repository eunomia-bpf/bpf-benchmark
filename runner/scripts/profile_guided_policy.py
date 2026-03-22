#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import ensure_parent, write_json  # noqa: E402
from runner.libs.policy import render_policy_v3_text, sanitize_program_name  # noqa: E402


DEFAULT_ALWAYS_FAMILIES = ("wide", "rotate", "lea", "extract", "endian")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Generate per-program policy v3 YAMLs from runtime profile and live site census."
    )
    parser.add_argument("--profile-json", required=True, help="Profile JSON produced by runner/scripts/bpf_profiler.py or runner/scripts/collect_e2e_profile.py.")
    parser.add_argument(
        "--census-json",
        help="Optional external daemon enumerate JSON. When omitted, uses sites embedded in --profile-json.",
    )
    parser.add_argument("--output-dir", required=True, help="Directory where per-program YAMLs are written.")
    parser.add_argument(
        "--summary-json",
        help="Optional structured decision summary output path. Defaults to <output-dir>/summary.json.",
    )
    parser.add_argument(
        "--run-cnt-threshold",
        type=int,
        default=1000,
        help="Only programs with delta run_cnt >= threshold are eligible for non-empty policies.",
    )
    parser.add_argument(
        "--run-time-threshold-ns",
        type=int,
        default=0,
        help="Optional minimum delta run_time_ns for non-empty policies.",
    )
    parser.add_argument(
        "--branch-miss-rate-threshold",
        type=float,
        default=0.03,
        help="Enable branch-flip only when branch_miss_rate >= threshold.",
    )
    parser.add_argument(
        "--cmov-max-branch-miss-rate",
        type=float,
        default=0.01,
        help="Enable cmov only when branch_miss_rate <= threshold.",
    )
    parser.add_argument(
        "--min-branch-samples",
        type=int,
        default=1000,
        help="Minimum branch counter samples required before enabling branch-sensitive families.",
    )
    parser.add_argument(
        "--always-families",
        default=",".join(DEFAULT_ALWAYS_FAMILIES),
        help="Comma-separated families allowed on hot programs regardless of branch data.",
    )
    parser.add_argument(
        "--deny-family",
        action="append",
        default=[],
        help="Repeatable family blocklist applied after all heuristics.",
    )
    parser.add_argument(
        "--deny-pattern-kind",
        action="append",
        default=[],
        help="Repeatable pattern_kind blocklist applied after family admission.",
    )
    parser.add_argument(
        "--emit-empty-policies",
        action="store_true",
        help="Write explicit empty v3 YAMLs for skipped/cold programs instead of omitting them.",
    )
    return parser


def parse_csv_tokens(value: str) -> list[str]:
    return [token.strip() for token in str(value).split(",") if token.strip()]


def load_json(path: Path) -> Any:
    return json.loads(path.read_text())


def resolve_profile_payload(payload: Any) -> Mapping[str, Any]:
    if isinstance(payload, Mapping) and isinstance(payload.get("programs"), list):
        return payload
    nested = payload.get("profile") if isinstance(payload, Mapping) else None
    if isinstance(nested, Mapping) and isinstance(nested.get("programs"), list):
        return nested
    raise SystemExit("--profile-json must be a profile object or a wrapper containing profile.programs")


def maybe_resolve_profile_payload(payload: Any) -> Any:
    if not isinstance(payload, Mapping):
        return payload
    if isinstance(payload.get("programs"), list):
        return payload
    if isinstance(payload.get("profile"), Mapping):
        return resolve_profile_payload(payload)
    return payload


def _record_prog_id(record: Mapping[str, Any]) -> int:
    for key in ("prog_id", "id"):
        value = record.get(key)
        if value is None:
            continue
        try:
            prog_id = int(value)
        except (TypeError, ValueError):
            continue
        if prog_id > 0:
            return prog_id
    program = record.get("program")
    if isinstance(program, Mapping):
        return _record_prog_id(program)
    return 0


def _record_name(record: Mapping[str, Any]) -> str:
    for key in ("name", "program_name"):
        value = record.get(key)
        if value is not None:
            text = str(value).strip()
            if text:
                return text
    program = record.get("program")
    if isinstance(program, Mapping):
        return _record_name(program)
    return ""


def _extract_sites(record: Mapping[str, Any]) -> list[dict[str, Any]]:
    raw_sites = record.get("sites")
    if isinstance(raw_sites, list) and raw_sites and isinstance(raw_sites[0], Mapping) and "family" in raw_sites[0]:
        return [dict(site) for site in raw_sites if isinstance(site, Mapping)]
    enumerate_record = record.get("enumerate_record")
    if isinstance(enumerate_record, Mapping):
        inner_sites = enumerate_record.get("sites")
        if isinstance(inner_sites, list):
            return [dict(site) for site in inner_sites if isinstance(site, Mapping)]
    manifest = record.get("manifest")
    if isinstance(manifest, Mapping):
        inner_sites = manifest.get("sites")
        if isinstance(inner_sites, list):
            return [dict(site) for site in inner_sites if isinstance(site, Mapping)]
    return []


def build_census_index(payload: Any) -> tuple[dict[int, list[dict[str, Any]]], dict[str, list[dict[str, Any]]]]:
    records: list[Mapping[str, Any]] = []
    if isinstance(payload, list):
        records = [record for record in payload if isinstance(record, Mapping)]
    elif isinstance(payload, Mapping):
        if isinstance(payload.get("programs"), list):
            records = [record for record in payload.get("programs") or [] if isinstance(record, Mapping)]
        else:
            records = [payload]
    by_id: dict[int, list[dict[str, Any]]] = {}
    by_name: dict[str, list[dict[str, Any]]] = {}
    for record in records:
        sites = _extract_sites(record)
        if not sites:
            continue
        prog_id = _record_prog_id(record)
        if prog_id > 0:
            by_id[prog_id] = sites
        name = _record_name(record)
        if name:
            by_name[name] = sites
    return by_id, by_name


def decide_sites(
    profile_record: Mapping[str, Any],
    sites: Sequence[Mapping[str, Any]],
    *,
    run_cnt_threshold: int,
    run_time_threshold_ns: int,
    branch_miss_rate_threshold: float,
    cmov_max_branch_miss_rate: float,
    min_branch_samples: int,
    always_families: set[str],
    deny_families: set[str],
    deny_pattern_kinds: set[str],
) -> dict[str, Any]:
    run_cnt = int(profile_record.get("run_cnt", 0) or 0)
    run_time_ns = int(profile_record.get("run_time_ns", 0) or 0)
    branch_miss_rate = profile_record.get("branch_miss_rate")
    branches = profile_record.get("branches")
    branches_value = int(branches) if isinstance(branches, (int, float)) else 0
    hot = run_cnt >= run_cnt_threshold and run_time_ns >= run_time_threshold_ns
    branch_data_ready = isinstance(branch_miss_rate, (int, float)) and branches_value >= min_branch_samples
    allow_branch_flip = hot and branch_data_ready and float(branch_miss_rate) >= float(branch_miss_rate_threshold)
    allow_cmov = hot and branch_data_ready and float(branch_miss_rate) <= float(cmov_max_branch_miss_rate)

    admitted: list[dict[str, Any]] = []
    family_counts = Counter()
    dropped_family_counts = Counter()
    dropped_pattern_counts = Counter()

    for raw_site in sites:
        family = str(raw_site.get("family", "")).strip()
        pattern_kind = str(raw_site.get("pattern_kind", "")).strip()
        if family in deny_families:
            dropped_family_counts[family] += 1
            continue
        if pattern_kind in deny_pattern_kinds:
            dropped_pattern_counts[pattern_kind] += 1
            continue
        allow = False
        if hot and family in always_families:
            allow = True
        elif family == "branch-flip":
            allow = allow_branch_flip
        elif family == "cmov":
            allow = allow_cmov
        if not allow:
            dropped_family_counts[family] += 1
            continue
        admitted_site = {
            "insn": int(raw_site.get("insn", 0) or 0),
            "family": family,
            "pattern_kind": pattern_kind,
        }
        admitted.append(admitted_site)
        family_counts[family] += 1

    reasons: list[str] = []
    if not hot:
        reasons.append(
            f"cold program: run_cnt={run_cnt} (<{run_cnt_threshold}) or run_time_ns={run_time_ns} (<{run_time_threshold_ns})"
        )
    else:
        reasons.append(f"hot program admitted: run_cnt={run_cnt}, run_time_ns={run_time_ns}")
    if not branch_data_ready:
        reasons.append(
            "branch-sensitive families gated off due to missing/insufficient perf branch data"
        )
    else:
        reasons.append(
            f"branch_miss_rate={float(branch_miss_rate):.6f}, allow_branch_flip={allow_branch_flip}, allow_cmov={allow_cmov}"
        )

    return {
        "hot": hot,
        "branch_data_ready": branch_data_ready,
        "allow_branch_flip": allow_branch_flip,
        "allow_cmov": allow_cmov,
        "selected_sites": admitted,
        "selected_family_counts": dict(family_counts),
        "dropped_family_counts": dict(dropped_family_counts),
        "dropped_pattern_counts": dict(dropped_pattern_counts),
        "reasons": reasons,
    }


def write_policy(path: Path, program_name: str, selected_sites: Sequence[Mapping[str, Any]], comments: Sequence[str]) -> None:
    ensure_parent(path)
    path.write_text(
        render_policy_v3_text(
            program_name=program_name,
            sites=selected_sites,
            comments=comments,
        )
    )


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    profile_path = Path(args.profile_json).resolve()
    census_path = Path(args.census_json).resolve() if args.census_json else None
    output_dir = Path(args.output_dir).resolve()
    summary_path = Path(args.summary_json).resolve() if args.summary_json else output_dir / "summary.json"

    raw_profile_payload = load_json(profile_path)
    if not isinstance(raw_profile_payload, Mapping):
        raise SystemExit("--profile-json must be a JSON object")
    profile_payload = resolve_profile_payload(raw_profile_payload)
    programs = profile_payload.get("programs")
    if not isinstance(programs, list):
        raise SystemExit("--profile-json is missing programs")

    raw_census_payload = load_json(census_path) if census_path else raw_profile_payload
    census_payload = maybe_resolve_profile_payload(raw_census_payload)
    census_by_id, census_by_name = build_census_index(census_payload)

    always_families = set(parse_csv_tokens(args.always_families))
    deny_families = set(args.deny_family or [])
    deny_pattern_kinds = set(args.deny_pattern_kind or [])
    decisions: list[dict[str, Any]] = []
    written_paths: list[str] = []

    for record in programs:
        if not isinstance(record, Mapping):
            continue
        prog_id = _record_prog_id(record)
        if prog_id <= 0:
            continue
        program_name = _record_name(record) or f"id-{prog_id}"
        sites = census_by_id.get(prog_id) or census_by_name.get(program_name) or _extract_sites(record)
        decision = decide_sites(
            record,
            sites,
            run_cnt_threshold=int(args.run_cnt_threshold),
            run_time_threshold_ns=int(args.run_time_threshold_ns),
            branch_miss_rate_threshold=float(args.branch_miss_rate_threshold),
            cmov_max_branch_miss_rate=float(args.cmov_max_branch_miss_rate),
            min_branch_samples=int(args.min_branch_samples),
            always_families=always_families,
            deny_families=deny_families,
            deny_pattern_kinds=deny_pattern_kinds,
        )
        policy_relname = f"{prog_id:05d}_{sanitize_program_name(program_name)}.policy.yaml"
        policy_path = output_dir / policy_relname
        selected_sites = decision["selected_sites"]
        if selected_sites or args.emit_empty_policies:
            comments = [
                f"Generated from profile: {profile_path}",
                f"Program id: {prog_id}",
                f"Program name: {program_name}",
                *decision["reasons"],
            ]
            write_policy(policy_path, program_name, selected_sites, comments)
            written_paths.append(str(policy_path))
        decisions.append(
            {
                "prog_id": prog_id,
                "name": program_name,
                "run_cnt": int(record.get("run_cnt", 0) or 0),
                "run_time_ns": int(record.get("run_time_ns", 0) or 0),
                "avg_ns": record.get("avg_ns"),
                "branch_miss_rate": record.get("branch_miss_rate"),
                "branches": record.get("branches"),
                "hotness": record.get("hotness"),
                "site_input_count": len(sites),
                "selected_site_count": len(selected_sites),
                "policy_path": str(policy_path) if (selected_sites or args.emit_empty_policies) else None,
                **decision,
            }
        )

    summary = {
        "profile_json": str(profile_path),
        "census_json": str(census_path) if census_path else None,
        "output_dir": str(output_dir),
        "written_policy_count": len(written_paths),
        "policies": written_paths,
        "decisions": decisions,
    }
    write_json(summary_path, summary)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
