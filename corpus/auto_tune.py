#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
from itertools import combinations
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from generate_default_policies import DEFAULT_WORKERS, discover_object_paths
from runner.libs.corpus import relpath as shared_relpath
from runner.libs.policy import (
    POLICY_DIR,
    ROOT_DIR,
    object_relative_path,
    object_roots,
    canonical_policy_family_name,
    policy_path_for_program,
    render_policy_v3_text,
)

try:
    from runner.libs.inventory import discover_object_programs, load_packet_test_run_targets
except ImportError:
    from runner.libs.inventory import discover_object_programs, load_packet_test_run_targets

from corpus.modes import (
    DEFAULT_BTF_PATH,
    DEFAULT_HOST_BTF_PATH,
    DEFAULT_INVENTORY_JSON,
    DEFAULT_REPEAT,
    DEFAULT_RUNNER,
    DEFAULT_DAEMON,
    DEFAULT_TIMEOUT_SECONDS,
    DEFAULT_VNG,
    families_from_scan,
    format_ratio,
    run_target_in_guest,
    run_target_locally,
)


FAMILY_ORDER = (
    "cmov",
    "wide",
    "rotate",
    "lea",
    "extract",
    "endian",
    "branch-flip",
)
PHASES = {1, 2, 3, 4, 5}
DEFAULT_OUTPUT_JSON = ROOT_DIR / "corpus" / "results" / "corpus_auto_tune.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-auto-tune.md"


def relpath(path: Path | str) -> str:
    return shared_relpath(path, ROOT_DIR)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Auto-tune corpus per-program version 3 per-site policy artifacts "
            "via census, all-apply screening, leave-one-out ablation, and "
            "pairwise combo search."
        )
    )
    parser.add_argument(
        "--inventory-json",
        default=str(DEFAULT_INVENTORY_JSON),
        help="Packet-test-run runnability inventory JSON used for measurable targets.",
    )
    parser.add_argument(
        "--runner",
        default=str(DEFAULT_RUNNER),
        help="Path to micro_exec.",
    )
    parser.add_argument(
        "--daemon",
        default=str(DEFAULT_DAEMON),
        help="Path to bpfrejit-daemon.",
    )
    parser.add_argument(
        "--kernel-image",
        help="Kernel image used for VM measurements. When omitted, tuning runs on the host.",
    )
    parser.add_argument(
        "--btf-custom-path",
        help="BTF path for measurements. VM default is vendor/linux-framework/vmlinux; host default is /sys/kernel/btf/vmlinux when available.",
    )
    parser.add_argument(
        "--vng",
        default=DEFAULT_VNG,
        help="vng executable used for VM measurements.",
    )
    parser.add_argument(
        "--policy-dir",
        default=str(POLICY_DIR),
        help="Directory where final per-program policy YAML files are written.",
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Path for structured auto-tuner output.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Path for markdown summary output.",
    )
    parser.add_argument(
        "--object-root",
        action="append",
        dest="object_roots",
        help="Object root to scan for *.bpf.o files. Repeatable; defaults to the standard corpus roots.",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=DEFAULT_WORKERS,
        help="Concurrent workers used for census scanning.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Timeout in seconds used for daemon, inventory, and per-candidate measurements.",
    )
    parser.add_argument(
        "--repeat",
        type=int,
        default=DEFAULT_REPEAT,
        help="Repeat count for each measurement candidate. Must be at least 200 unless --dry-run is set.",
    )
    parser.add_argument(
        "--phase",
        action="append",
        help="Only run the selected phase(s). Accepts 1-5, comma-separated lists, or ranges such as 3-5.",
    )
    parser.add_argument(
        "--programs",
        action="append",
        help="Limit work to object/program substrings. Repeatable and comma-separated.",
    )
    parser.add_argument(
        "--max-programs",
        type=int,
        help="Optional cap after filtering, primarily for smoke tests.",
    )
    parser.add_argument(
        "--combo-top-k",
        type=int,
        default=4,
        help="Maximum number of leave-one-out families kept as seeds for pairwise combo search.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Plan phases and candidate evaluations without running measurements or writing final policy files.",
    )
    parser.add_argument(
        "--resume",
        action="store_true",
        help="Resume from the existing --output-json payload and skip completed work.",
    )
    return parser.parse_args(argv)


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def load_json(path: Path) -> dict[str, Any]:
    return json.loads(path.read_text())


def parse_last_json_line(stdout: str, *, label: str) -> Any:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError(f"{label} produced no JSON output")
    return json.loads(lines[-1])


def run_json_command(command: list[str], *, timeout_seconds: int, label: str) -> Any:
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
        check=False,
    )
    if completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip() or f"exit={completed.returncode}"
        raise RuntimeError(f"{label} failed: {' '.join(command)}\n{detail}")
    return parse_last_json_line(completed.stdout, label=label)


def parse_program_filters(values: list[str] | None) -> list[str]:
    tokens: list[str] = []
    seen: set[str] = set()
    for raw in values or []:
        for piece in raw.split(","):
            token = piece.strip().lower()
            if token and token not in seen:
                seen.add(token)
                tokens.append(token)
    return tokens


def parse_phase_selection(values: list[str] | None) -> set[int]:
    if not values:
        return set(PHASES)
    selected: set[int] = set()
    for raw in values:
        for piece in raw.split(","):
            token = piece.strip().lower()
            if not token:
                continue
            if token == "all":
                selected.update(PHASES)
                continue
            if "-" in token:
                start_text, end_text = token.split("-", 1)
                start = int(start_text)
                end = int(end_text)
                if start > end:
                    raise SystemExit(f"invalid --phase range: {piece}")
                selected.update(range(start, end + 1))
                continue
            selected.add(int(token))
    invalid = sorted(selected - PHASES)
    if invalid:
        raise SystemExit(f"unsupported phase(s): {invalid} (expected 1-5)")
    return selected


def canonical_families(values: list[str] | None) -> list[str]:
    requested = set(values or [])
    return [family for family in FAMILY_ORDER if family in requested]


def candidate_id_for_allowlist(allowlist: list[str]) -> str:
    if not allowlist:
        return "stock"
    return "allow:" + ",".join(canonical_families(allowlist))


def program_key(object_path: str, program_name: str) -> str:
    return f"{object_path}:{program_name}"


def record_matches_filters(record: dict[str, Any], filters: list[str]) -> bool:
    if not filters:
        return True
    fields = [
        str(record.get("key", "")),
        str(record.get("object_path", "")),
        str(record.get("program_name", "")),
        str(record.get("section_name", "")),
        str(record.get("source_name", "")),
    ]
    lowered_fields = [field.lower() for field in fields]
    return any(token in field for token in filters for field in lowered_fields)


def phase_enabled(selected_phases: set[int], phase: int) -> bool:
    return phase in selected_phases


def best_tuned_trial(program: dict[str, Any]) -> dict[str, Any] | None:
    measured = [
        trial
        for trial in (program.get("trials") or {}).values()
        if isinstance(trial, dict) and isinstance(trial.get("speedup_ratio"), (int, float))
    ]
    if not measured:
        return None
    return max(
        measured,
        key=lambda trial: (
            float(trial["speedup_ratio"]),
            -len(trial.get("allowlist") or []),
            candidate_id_for_allowlist(trial.get("allowlist") or []),
        ),
    )


def choose_winner(program: dict[str, Any]) -> dict[str, Any] | None:
    eligible = canonical_families(program.get("eligible_families") or [])
    stock_candidate = {
        "candidate_id": "stock",
        "label": "stock",
        "allowlist": [],
        "skipped_families": eligible,
        "phase": 0,
        "speedup_ratio": 1.0,
        "size_ratio": 1.0,
        "record": None,
    }
    candidates = [stock_candidate]
    for trial in (program.get("trials") or {}).values():
        if isinstance(trial, dict) and isinstance(trial.get("speedup_ratio"), (int, float)):
            candidates.append(trial)
    if not candidates:
        return None
    return max(
        candidates,
        key=lambda trial: (
            float(trial["speedup_ratio"]),
            -len(trial.get("allowlist") or []),
            candidate_id_for_allowlist(trial.get("allowlist") or []),
        ),
    )


def render_policy_text(
    *,
    object_path: Path,
    program_name: str,
    program: dict[str, Any],
    allowlist: list[str],
    report_path: Path,
) -> str:
    relative = object_relative_path(object_path)
    allowed = set(canonical_families(allowlist))
    sites: list[dict[str, Any]] = []
    for entry in ((program.get("manifest") or {}).get("sites") or []):
        if not isinstance(entry, dict):
            continue
        insn = int(entry.get("insn", -1))
        if insn < 0:
            continue
        family = canonical_policy_family_name(str(entry.get("family", "")))
        if family not in allowed:
            continue
        pattern_kind = str(entry.get("pattern_kind", "")).strip()
        if not pattern_kind:
            continue
        sites.append(
            {
                "insn": insn,
                "family": family,
                "pattern_kind": pattern_kind,
            }
        )
    sites.sort(
        key=lambda item: (
            int(item["insn"]),
            str(item["family"]),
            str(item["pattern_kind"]),
        )
    )
    return render_policy_v3_text(
        program_name=program_name,
        sites=sites,
        comments=[
            "Auto-generated by corpus/auto_tune.py.",
            f"Object: {relative.as_posix()}",
            f"Program: {program_name}",
            "Source: auto-tuner",
            "Workload: packet-test-run/default",
            "Objective: exec_ns",
            "Allowed families: " + (", ".join(sorted(allowed)) if allowed else "stock"),
            f"Report: {relpath(report_path)}",
        ],
    )


def scan_program_manifest(
    daemon: Path,
    object_path: Path,
    program_name: str,
    *,
    timeout_seconds: int,
) -> dict[str, Any]:
    payload = run_json_command(
        [
            str(daemon),
            "scan",
            str(object_path),
            "--program-name",
            program_name,
            "--all",
            "--json",
        ],
        timeout_seconds=timeout_seconds,
        label=f"daemon:{relpath(object_path)}:{program_name}",
    )
    if not isinstance(payload, dict):
        raise RuntimeError(f"daemon output for {relpath(object_path)}:{program_name} was not a JSON object")
    return payload


def census_object(
    *,
    runner: Path,
    daemon: Path,
    object_path: Path,
    filters: list[str],
    timeout_seconds: int,
) -> dict[str, Any]:
    rel_object = relpath(object_path)
    try:
        programs = discover_object_programs(runner, object_path, timeout_seconds=timeout_seconds)
    except Exception as exc:
        return {
            "records": [],
            "inventory_failure": {
                "object_path": rel_object,
                "error": str(exc),
            },
        }

    relative_policy = object_relative_path(object_path)
    source_name = relative_policy.parts[0] if relative_policy.parts else object_path.parent.name
    records: list[dict[str, Any]] = []
    for entry in programs:
        key = program_key(rel_object, entry.name)
        record = {
            "key": key,
            "object_path": rel_object,
            "program_name": entry.name,
            "section_name": entry.section_name,
            "source_name": source_name,
        }
        if not record_matches_filters(record, filters):
            continue
        manifest = scan_program_manifest(
            daemon,
            object_path,
            entry.name,
            timeout_seconds=timeout_seconds,
        )
        summary = manifest.get("summary") or {}
        eligible = families_from_scan(summary)
        records.append(
            {
                **record,
                "insn_count": int((manifest.get("program") or {}).get("insn_cnt", entry.insn_count) or 0),
                "eligible_families": canonical_families(eligible),
                "site_total": int(summary.get("total_sites", 0) or 0),
                "manifest": manifest,
            }
        )
    return {"records": records, "inventory_failure": None}


def load_or_init_payload(args: argparse.Namespace, selected_phases: set[int]) -> dict[str, Any]:
    output_json = Path(args.output_json).resolve()
    if args.resume:
        if not output_json.exists():
            raise SystemExit(f"--resume requested but output JSON does not exist: {output_json}")
        payload = load_json(output_json)
        if not isinstance(payload.get("programs"), dict):
            raise SystemExit(f"resume payload has unexpected schema: {output_json}")
        return payload

    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(ROOT_DIR),
        "mode": "vm" if args.kernel_image else "host",
        "inventory_json": str(Path(args.inventory_json).resolve()),
        "runner_binary": str(Path(args.runner).resolve()),
        "daemon_binary": str(Path(args.daemon).resolve()),
        "kernel_image": str(Path(args.kernel_image).resolve()) if args.kernel_image else None,
        "btf_custom_path": None,
        "vng_binary": args.vng,
        "policy_dir": str(Path(args.policy_dir).resolve()),
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "selected_phases": sorted(selected_phases),
        "dry_run": args.dry_run,
        "combo_top_k": args.combo_top_k,
        "program_filters": parse_program_filters(args.programs),
        "programs": {},
        "inventory_failures": [],
        "inventory_summary": {},
        "summary": {},
    }


def selected_program_keys(
    programs: dict[str, Any],
    *,
    filters: list[str],
    max_programs: int | None,
) -> list[str]:
    records = sorted(programs.values(), key=lambda item: (item["object_path"], item["program_name"]))
    filtered = [record for record in records if record_matches_filters(record, filters)]
    if max_programs is not None:
        filtered = filtered[:max_programs]
    return [record["key"] for record in filtered]


def attach_measurement_targets(
    payload: dict[str, Any],
    *,
    inventory_json: Path,
    selected_keys: list[str],
) -> None:
    targets, inventory_summary = load_packet_test_run_targets(inventory_json)
    target_map = {
        program_key(str(target["object_path"]), str(target["program_name"])): dict(target)
        for target in targets
    }
    selected_key_set = set(selected_keys)
    for key, program in payload["programs"].items():
        if selected_keys and key not in selected_key_set:
            continue
        target = target_map.get(key)
        program["measurement_target"] = target
    payload["inventory_summary"] = inventory_summary


def ensure_program_entry(payload: dict[str, Any], census_record: dict[str, Any]) -> dict[str, Any]:
    key = census_record["key"]
    existing = payload["programs"].get(key) or {
        "key": key,
        "trials": {},
        "winner": None,
        "policy_path": None,
        "policy_written": False,
    }
    existing.update(
        {
            "object_path": census_record["object_path"],
            "program_name": census_record["program_name"],
            "section_name": census_record["section_name"],
            "source_name": census_record["source_name"],
            "insn_count": census_record["insn_count"],
            "eligible_families": canonical_families(census_record["eligible_families"]),
            "site_total": int(census_record["site_total"]),
            "manifest": census_record["manifest"],
        }
    )
    payload["programs"][key] = existing
    return existing


def build_summary(payload: dict[str, Any]) -> dict[str, Any]:
    programs = list((payload.get("programs") or {}).values())
    site_positive = [program for program in programs if int(program.get("site_total", 0) or 0) > 0]
    measurable = [program for program in programs if program.get("measurement_target")]
    measurable_positive = [program for program in measurable if int(program.get("site_total", 0) or 0) > 0]
    winners = [program.get("winner") for program in measurable_positive if isinstance(program.get("winner"), dict)]
    stock_winners = [winner for winner in winners if winner.get("candidate_id") == "stock"]
    non_stock_winners = [winner for winner in winners if winner.get("candidate_id") != "stock"]

    phase_trials: dict[int, int] = {phase: 0 for phase in sorted(PHASES)}
    measured_trials = 0
    for program in programs:
        for trial in (program.get("trials") or {}).values():
            if not isinstance(trial, dict):
                continue
            phase = int(trial.get("phase", 0) or 0)
            if phase in phase_trials:
                phase_trials[phase] += 1
            if isinstance(trial.get("speedup_ratio"), (int, float)):
                measured_trials += 1

    all_apply_regressors = 0
    combo_candidates = 0
    measurement_failures = 0
    for program in measurable_positive:
        eligible = all_apply_allowlist(program)
        all_apply_id = candidate_id_for_allowlist(eligible)
        all_apply_trial = (program.get("trials") or {}).get(all_apply_id)
        all_apply = (program.get("trials") or {}).get(candidate_id_for_allowlist(program.get("eligible_families") or []))
        if isinstance(all_apply, dict) and isinstance(all_apply.get("speedup_ratio"), (int, float)) and float(all_apply["speedup_ratio"]) < 1.0:
            all_apply_regressors += 1
        if any(
            isinstance(trial, dict) and int(trial.get("phase", 0) or 0) == 4
            for trial in (program.get("trials") or {}).values()
        ):
            combo_candidates += 1
        if payload.get("dry_run"):
            continue
        if 2 not in set(payload.get("selected_phases") or []):
            continue
        if all_apply_trial is None or not isinstance(all_apply_trial.get("speedup_ratio"), (int, float)):
            measurement_failures += 1

    winner_ratios = [
        float(winner["speedup_ratio"])
        for winner in winners
        if isinstance(winner.get("speedup_ratio"), (int, float)) and float(winner["speedup_ratio"]) > 0
    ]
    winner_geomean = math.exp(sum(math.log(value) for value in winner_ratios) / len(winner_ratios)) if winner_ratios else None

    return {
        "programs_total": len(programs),
        "site_positive_programs": len(site_positive),
        "measurable_programs": len(measurable),
        "measurable_site_positive_programs": len(measurable_positive),
        "all_apply_regressors": all_apply_regressors,
        "programs_with_combo_search": combo_candidates,
        "measured_trials": measured_trials,
        "phase_trial_counts": phase_trials,
        "policy_files_written": sum(1 for program in programs if program.get("policy_written")),
        "stock_winners": len(stock_winners),
        "non_stock_winners": len(non_stock_winners),
        "measurement_failures": measurement_failures,
        "winner_speedup_geomean": winner_geomean,
    }


def build_markdown(payload: dict[str, Any]) -> str:
    summary = build_summary(payload)
    programs = sorted((payload.get("programs") or {}).values(), key=lambda item: (item["object_path"], item["program_name"]))
    lines = [
        "# Corpus Auto-Tune Results",
        "",
        f"- Generated: {payload.get('generated_at')}",
        f"- Mode: `{payload.get('mode')}`",
        f"- Runner: `{payload.get('runner_binary')}`",
        f"- Daemon: `{payload.get('daemon_binary')}`",
        f"- Inventory: `{payload.get('inventory_json')}`",
        f"- Policy dir: `{payload.get('policy_dir')}`",
        f"- Repeat: {payload.get('repeat')}",
        f"- Timeout: {payload.get('timeout_seconds')}s",
        f"- Phases: `{', '.join(str(phase) for phase in payload.get('selected_phases') or [])}`",
        f"- Dry-run: `{payload.get('dry_run')}`",
        "",
        "## Summary",
        "",
        "| Metric | Value |",
        "| --- | --- |",
        f"| Programs discovered | {summary['programs_total']} |",
        f"| Site-positive programs | {summary['site_positive_programs']} |",
        f"| Measurable programs | {summary['measurable_programs']} |",
        f"| Measurable site-positive programs | {summary['measurable_site_positive_programs']} |",
        f"| All-apply regressors | {summary['all_apply_regressors']} |",
        f"| Combo-search programs | {summary['programs_with_combo_search']} |",
        f"| Measured trials | {summary['measured_trials']} |",
        f"| Policies written | {summary['policy_files_written']} |",
        f"| Stock winners | {summary['stock_winners']} |",
        f"| Non-stock winners | {summary['non_stock_winners']} |",
        f"| Winner geomean | {format_ratio(summary['winner_speedup_geomean'])} |",
        "",
        "## Winners",
        "",
        "| Program | Sites | Eligible | Winner | Ratio | Policy |",
        "| --- | --- | --- | --- | --- | --- |",
    ]
    for program in programs:
        if int(program.get("site_total", 0) or 0) <= 0 or not program.get("measurement_target"):
            continue
        winner = program.get("winner") or {}
        lines.append(
            "| "
            + " | ".join(
                [
                    program["key"],
                    str(program.get("site_total", 0)),
                    ", ".join(program.get("eligible_families") or []) or "none",
                    winner.get("label") or "pending",
                    format_ratio(winner.get("speedup_ratio")),
                    relpath(program["policy_path"]) if program.get("policy_path") else "pending",
                ]
            )
            + " |"
        )
    return "\n".join(lines) + "\n"


def persist_payload(payload: dict[str, Any], *, output_json: Path, output_md: Path) -> None:
    payload["updated_at"] = datetime.now(timezone.utc).isoformat()
    payload["summary"] = build_summary(payload)
    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    output_md.write_text(build_markdown(payload))


def measurement_btf_path(args: argparse.Namespace) -> Path | None:
    if args.btf_custom_path:
        return Path(args.btf_custom_path).resolve()
    if args.kernel_image:
        return DEFAULT_BTF_PATH.resolve()
    if DEFAULT_HOST_BTF_PATH.exists():
        return DEFAULT_HOST_BTF_PATH.resolve()
    if DEFAULT_BTF_PATH.exists():
        return DEFAULT_BTF_PATH.resolve()
    return None


def write_candidate_policy(
    *,
    policy_root: Path,
    program: dict[str, Any],
    allowlist: list[str],
    report_path: Path,
) -> Path:
    object_path = ROOT_DIR / program["object_path"]
    path = policy_path_for_program(object_path, program["program_name"], policy_root)
    ensure_parent(path)
    path.write_text(
        render_policy_text(
            object_path=object_path,
            program_name=program["program_name"],
            program=program,
            allowlist=allowlist,
            report_path=report_path,
        )
    )
    return path


def measure_candidate(
    *,
    args: argparse.Namespace,
    program: dict[str, Any],
    allowlist: list[str],
    phase: int,
    label: str,
) -> dict[str, Any]:
    candidate_id = candidate_id_for_allowlist(allowlist)
    skipped = [family for family in canonical_families(program.get("eligible_families") or []) if family not in allowlist]
    with tempfile.TemporaryDirectory(prefix="corpus-auto-tune-policy-", dir=ROOT_DIR) as tmpdir_name:
        tmpdir = Path(tmpdir_name)
        policy_path = write_candidate_policy(
            policy_root=tmpdir,
            program=program,
            allowlist=allowlist,
            report_path=Path(args.output_json).resolve(),
        )
        target = dict(program["measurement_target"])
        runner = Path(args.runner).resolve()
        daemon = Path(args.daemon).resolve()
        btf_custom_path = measurement_btf_path(args)
        if args.kernel_image:
            record = run_target_in_guest(
                target=target,
                runner=runner,
                daemon=daemon,
                kernel_image=Path(args.kernel_image).resolve(),
                btf_custom_path=btf_custom_path if btf_custom_path is not None else DEFAULT_BTF_PATH.resolve(),
                repeat=args.repeat,
                timeout_seconds=args.timeout,
                vng_binary=args.vng,
                skip_families=[],
                use_policy=True,
                policy_dir=tmpdir,
            )
        else:
            record = run_target_locally(
                target=target,
                runner=runner,
                daemon=daemon,
                repeat=args.repeat,
                timeout_seconds=args.timeout,
                execution_mode="host",
                btf_custom_path=btf_custom_path,
                enable_recompile=True,
                enable_exec=True,
                skip_families=[],
                use_policy=True,
                policy_dir=tmpdir,
            )
    return {
        "candidate_id": candidate_id,
        "label": label,
        "phase": phase,
        "allowlist": canonical_families(allowlist),
        "skipped_families": skipped,
        "speedup_ratio": record.get("speedup_ratio"),
        "size_ratio": record.get("size_ratio"),
        "record": record,
        "policy_path": str(policy_path),
    }


def store_trial(program: dict[str, Any], trial: dict[str, Any]) -> None:
    program.setdefault("trials", {})[trial["candidate_id"]] = trial


def all_apply_allowlist(program: dict[str, Any]) -> list[str]:
    return canonical_families(program.get("eligible_families") or [])


def missing_prerequisite(programs: list[dict[str, Any]], *, phase: int) -> list[str]:
    missing: list[str] = []
    for program in programs:
        if int(program.get("site_total", 0) or 0) <= 0 or not program.get("measurement_target"):
            continue
        if phase == 3:
            required_id = candidate_id_for_allowlist(all_apply_allowlist(program))
            if required_id not in (program.get("trials") or {}):
                missing.append(program["key"])
        elif phase == 4:
            has_phase3 = any(
                isinstance(trial, dict) and int(trial.get("phase", 0) or 0) == 3
                for trial in (program.get("trials") or {}).values()
            )
            if not has_phase3:
                missing.append(program["key"])
        elif phase == 5:
            required_id = candidate_id_for_allowlist(all_apply_allowlist(program))
            if int(program.get("site_total", 0) or 0) > 0 and program.get("measurement_target") and required_id not in (program.get("trials") or {}):
                missing.append(program["key"])
    return missing


def run_phase_1(
    *,
    payload: dict[str, Any],
    args: argparse.Namespace,
    output_json: Path,
    output_md: Path,
    filters: list[str],
) -> None:
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    selected_roots = (
        tuple(Path(item).resolve() for item in args.object_roots)
        if args.object_roots
        else object_roots()
    )
    if not selected_roots:
        raise SystemExit("no corpus object roots found")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")

    object_paths = discover_object_paths(
        selected_roots,
        filters=None,
        max_objects=None,
    )
    if not object_paths:
        raise SystemExit("no corpus objects matched the selected roots/filters")

    records: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as executor:
        future_map = {
            executor.submit(
                census_object,
                runner=runner,
                daemon=daemon,
                object_path=path,
                filters=filters,
                timeout_seconds=args.timeout,
            ): path
            for path in object_paths
        }
        for future in as_completed(future_map):
            result = future.result()
            records.extend(result["records"])
            if result["inventory_failure"] is not None:
                inventory_failures.append(result["inventory_failure"])

    records.sort(key=lambda item: (item["object_path"], item["program_name"]))
    if args.max_programs is not None:
        records = records[:args.max_programs]
    if not args.resume:
        payload["programs"] = {}
    for record in records:
        ensure_program_entry(payload, record)
    payload["inventory_failures"] = sorted(inventory_failures, key=lambda item: item["object_path"])
    persist_payload(payload, output_json=output_json, output_md=output_md)


def run_phase_2(
    *,
    payload: dict[str, Any],
    args: argparse.Namespace,
    selected_programs: list[dict[str, Any]],
    output_json: Path,
    output_md: Path,
) -> None:
    for program in selected_programs:
        if int(program.get("site_total", 0) or 0) <= 0:
            continue
        if not program.get("measurement_target"):
            continue
        allowlist = all_apply_allowlist(program)
        if not allowlist:
            continue
        candidate_id = candidate_id_for_allowlist(allowlist)
        if candidate_id in (program.get("trials") or {}):
            continue
        if args.dry_run:
            continue
        trial = measure_candidate(
            args=args,
            program=program,
            allowlist=allowlist,
            phase=2,
            label="all-apply",
        )
        store_trial(program, trial)
        persist_payload(payload, output_json=output_json, output_md=output_md)


def run_phase_3(
    *,
    payload: dict[str, Any],
    args: argparse.Namespace,
    selected_programs: list[dict[str, Any]],
    output_json: Path,
    output_md: Path,
) -> None:
    for program in selected_programs:
        if int(program.get("site_total", 0) or 0) <= 0 or not program.get("measurement_target"):
            continue
        eligible = all_apply_allowlist(program)
        if len(eligible) <= 0:
            continue
        all_apply_id = candidate_id_for_allowlist(eligible)
        all_apply_trial = (program.get("trials") or {}).get(all_apply_id)
        if not isinstance(all_apply_trial, dict):
            continue
        ratio = all_apply_trial.get("speedup_ratio")
        if not isinstance(ratio, (int, float)) or float(ratio) >= 1.0:
            continue
        for family in eligible:
            allowlist = [item for item in eligible if item != family]
            candidate_id = candidate_id_for_allowlist(allowlist)
            if candidate_id in (program.get("trials") or {}):
                continue
            if not allowlist:
                continue
            if args.dry_run:
                continue
            trial = measure_candidate(
                args=args,
                program=program,
                allowlist=allowlist,
                phase=3,
                label=f"skip-{family}",
            )
            store_trial(program, trial)
            persist_payload(payload, output_json=output_json, output_md=output_md)


def combo_seed_families(program: dict[str, Any], *, combo_top_k: int) -> list[str]:
    phase3_trials = [
        trial
        for trial in (program.get("trials") or {}).values()
        if isinstance(trial, dict) and int(trial.get("phase", 0) or 0) == 3 and trial.get("skipped_families")
    ]
    ranked = sorted(
        phase3_trials,
        key=lambda trial: (
            float(trial.get("speedup_ratio") or float("-inf")),
            trial["skipped_families"][0],
        ),
        reverse=True,
    )
    seeds: list[str] = []
    for trial in ranked:
        family = trial["skipped_families"][0]
        if family not in seeds:
            seeds.append(family)
        if len(seeds) >= max(2, combo_top_k):
            break
    return seeds


def run_phase_4(
    *,
    payload: dict[str, Any],
    args: argparse.Namespace,
    selected_programs: list[dict[str, Any]],
    output_json: Path,
    output_md: Path,
) -> None:
    for program in selected_programs:
        if int(program.get("site_total", 0) or 0) <= 0 or not program.get("measurement_target"):
            continue
        eligible = all_apply_allowlist(program)
        if len(eligible) < 2:
            continue
        all_apply_trial = (program.get("trials") or {}).get(candidate_id_for_allowlist(eligible))
        if not isinstance(all_apply_trial, dict):
            continue
        all_apply_ratio = all_apply_trial.get("speedup_ratio")
        if not isinstance(all_apply_ratio, (int, float)) or float(all_apply_ratio) >= 1.0:
            continue
        tuned = best_tuned_trial(program)
        if tuned is not None and isinstance(tuned.get("speedup_ratio"), (int, float)) and float(tuned["speedup_ratio"]) >= 1.0:
            continue
        seeds = combo_seed_families(program, combo_top_k=args.combo_top_k)
        if len(seeds) < 2:
            continue
        for combo in combinations(seeds, 2):
            allowlist = [family for family in eligible if family not in combo]
            if not allowlist:
                continue
            candidate_id = candidate_id_for_allowlist(allowlist)
            if candidate_id in (program.get("trials") or {}):
                continue
            if args.dry_run:
                continue
            trial = measure_candidate(
                args=args,
                program=program,
                allowlist=allowlist,
                phase=4,
                label="skip-" + "+".join(combo),
            )
            store_trial(program, trial)
            persist_payload(payload, output_json=output_json, output_md=output_md)


def run_phase_5(
    *,
    payload: dict[str, Any],
    args: argparse.Namespace,
    selected_programs: list[dict[str, Any]],
    output_json: Path,
    output_md: Path,
) -> None:
    policy_dir = Path(args.policy_dir).resolve()
    for program in selected_programs:
        if int(program.get("site_total", 0) or 0) <= 0 or not program.get("measurement_target"):
            continue
        all_apply_id = candidate_id_for_allowlist(all_apply_allowlist(program))
        all_apply_trial = (program.get("trials") or {}).get(all_apply_id)
        if not isinstance(all_apply_trial, dict) or not isinstance(all_apply_trial.get("speedup_ratio"), (int, float)):
            continue
        winner = choose_winner(program)
        if winner is None:
            continue
        program["winner"] = {
            "candidate_id": winner["candidate_id"],
            "label": winner["label"],
            "allowlist": canonical_families(winner.get("allowlist") or []),
            "skipped_families": winner.get("skipped_families") or [],
            "phase": int(winner.get("phase", 0) or 0),
            "speedup_ratio": winner.get("speedup_ratio"),
            "size_ratio": winner.get("size_ratio"),
        }
        final_policy_path = policy_path_for_program(
            ROOT_DIR / program["object_path"],
            program["program_name"],
            policy_dir,
        )
        program["policy_path"] = str(final_policy_path)
        program["policy_written"] = False
        if args.dry_run:
            continue
        ensure_parent(final_policy_path)
        final_policy_path.write_text(
            render_policy_text(
                object_path=ROOT_DIR / program["object_path"],
                program_name=program["program_name"],
                program=program,
                allowlist=winner.get("allowlist") or [],
                report_path=output_json,
            )
        )
        program["policy_written"] = True
        persist_payload(payload, output_json=output_json, output_md=output_md)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    selected_phases = parse_phase_selection(args.phase)
    filters = parse_program_filters(args.programs)
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    inventory_json = Path(args.inventory_json).resolve()
    if not inventory_json.exists():
        raise SystemExit(f"inventory JSON not found: {inventory_json}")
    if not args.dry_run and args.repeat < 200:
        raise SystemExit("--repeat must be >= 200 unless --dry-run is set")
    if args.kernel_image and not Path(args.kernel_image).resolve().exists():
        raise SystemExit(f"kernel image not found: {Path(args.kernel_image).resolve()}")
    btf_path = measurement_btf_path(args)
    if args.kernel_image and (btf_path is None or not btf_path.exists()):
        raise SystemExit(
            "VM mode requires a valid BTF path; pass --btf-custom-path or ensure "
            f"{DEFAULT_BTF_PATH} exists"
        )

    payload = load_or_init_payload(args, selected_phases)
    payload["mode"] = "vm" if args.kernel_image else "host"
    payload["inventory_json"] = str(inventory_json)
    payload["runner_binary"] = str(Path(args.runner).resolve())
    payload["daemon_binary"] = str(Path(args.daemon).resolve())
    payload["kernel_image"] = str(Path(args.kernel_image).resolve()) if args.kernel_image else None
    payload["btf_custom_path"] = str(btf_path) if btf_path is not None else None
    payload["policy_dir"] = str(Path(args.policy_dir).resolve())
    payload["repeat"] = args.repeat
    payload["timeout_seconds"] = args.timeout
    payload["selected_phases"] = sorted(selected_phases)
    payload["dry_run"] = args.dry_run
    payload["combo_top_k"] = args.combo_top_k
    payload["program_filters"] = filters

    if phase_enabled(selected_phases, 1) or not payload.get("programs"):
        run_phase_1(
            payload=payload,
            args=args,
            output_json=output_json,
            output_md=output_md,
            filters=filters,
        )

    if not payload.get("programs"):
        raise SystemExit("no census data available; run phase 1 first or use --resume with an existing payload")

    selected_keys = selected_program_keys(
        payload["programs"],
        filters=filters,
        max_programs=args.max_programs,
    )
    attach_measurement_targets(
        payload,
        inventory_json=inventory_json,
        selected_keys=selected_keys,
    )
    persist_payload(payload, output_json=output_json, output_md=output_md)

    selected_programs = [payload["programs"][key] for key in selected_keys]

    if phase_enabled(selected_phases, 3) and not phase_enabled(selected_phases, 2):
        missing = missing_prerequisite(selected_programs, phase=3)
        if missing:
            raise SystemExit(
                "phase 3 requires phase 2 all-apply results; missing programs include: "
                + ", ".join(missing[:10])
            )

    if phase_enabled(selected_phases, 4) and not phase_enabled(selected_phases, 3):
        missing = missing_prerequisite(selected_programs, phase=4)
        if missing:
            raise SystemExit(
                "phase 4 requires phase 3 leave-one-out results; missing programs include: "
                + ", ".join(missing[:10])
            )
    if phase_enabled(selected_phases, 5) and not phase_enabled(selected_phases, 2):
        missing = missing_prerequisite(selected_programs, phase=5)
        if missing:
            raise SystemExit(
                "phase 5 requires phase 2 all-apply results; missing programs include: "
                + ", ".join(missing[:10])
            )

    if phase_enabled(selected_phases, 2):
        run_phase_2(
            payload=payload,
            args=args,
            selected_programs=selected_programs,
            output_json=output_json,
            output_md=output_md,
        )
    if phase_enabled(selected_phases, 3):
        run_phase_3(
            payload=payload,
            args=args,
            selected_programs=selected_programs,
            output_json=output_json,
            output_md=output_md,
        )
    if phase_enabled(selected_phases, 4):
        run_phase_4(
            payload=payload,
            args=args,
            selected_programs=selected_programs,
            output_json=output_json,
            output_md=output_md,
        )
    if phase_enabled(selected_phases, 5):
        run_phase_5(
            payload=payload,
            args=args,
            selected_programs=selected_programs,
            output_json=output_json,
            output_md=output_md,
        )

    persist_payload(payload, output_json=output_json, output_md=output_md)
    summary = payload["summary"]
    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"programs={summary['programs_total']} "
        f"measurable_site_positive={summary['measurable_site_positive_programs']} "
        f"measured_trials={summary['measured_trials']} "
        f"policies_written={summary['policy_files_written']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
