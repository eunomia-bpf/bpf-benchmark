#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import re
import shutil
import subprocess
import sys
import time
from collections import Counter, defaultdict, deque
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Iterable

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from generate_default_policies import DEFAULT_SCANNER, scan_program_manifest
from policy_utils import (
    POLICY_DIR,
    canonical_policy_family_name,
    object_relative_path,
    policy_path_for_program,
    render_policy_v3_text,
)


DEFAULT_INVENTORY_JSON = REPO_ROOT / "docs" / "tmp" / "corpus-runnability-results.json"
DEFAULT_DRIVER = SCRIPT_DIR / "_driver_impl_run_corpus_v5_vm_batch.py"
DEFAULT_KERNEL_IMAGE = REPO_ROOT / "vendor" / "linux-framework" / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_RESULTS_DIR = REPO_ROOT / "corpus" / "results" / "post_cmov_fix_corpus_ablation"
DEFAULT_OUTPUT_JSON = REPO_ROOT / "corpus" / "results" / "post_cmov_fix_corpus_ablation.json"
DEFAULT_OUTPUT_MD = REPO_ROOT / "docs" / "tmp" / "post-cmov-fix-corpus-ablation.md"
DEFAULT_SAMPLE_SIZE = 45
DEFAULT_SMOKE_SIZE = 10
DEFAULT_FULL_REPEAT = 200
DEFAULT_SMOKE_REPEAT = 80
DEFAULT_TIMEOUT_SECONDS = 240
CMOV_TOTAL_RE = re.compile(
    r"^# Family site totals: .*?\bcmov=(?P<count>\d+)\b",
    re.MULTILINE,
)
FAMILY_ORDER = (
    "cmov",
    "wide",
    "rotate",
    "lea",
    "extract",
    "zero-ext",
    "endian",
    "branch-flip",
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run the post-CMOV-fix corpus sampling ablation by generating a "
            "diverse packet-test-run sample, emitting with/without-CMOV "
            "policy trees, and comparing VM batch results."
        )
    )
    parser.add_argument(
        "--inventory-json",
        default=str(DEFAULT_INVENTORY_JSON),
        help="Path to the corpus runnability inventory JSON.",
    )
    parser.add_argument(
        "--scanner",
        default=str(DEFAULT_SCANNER),
        help="Path to bpf-jit-scanner.",
    )
    parser.add_argument(
        "--driver",
        default=str(DEFAULT_DRIVER),
        help="Path to corpus/_driver_impl_run_corpus_v5_vm_batch.py.",
    )
    parser.add_argument(
        "--kernel-image",
        default=str(DEFAULT_KERNEL_IMAGE),
        help="Framework kernel image passed to the VM batch driver.",
    )
    parser.add_argument(
        "--current-policy-dir",
        default=str(POLICY_DIR),
        help="Existing policy directory used as the CMOV-excluded baseline.",
    )
    parser.add_argument(
        "--results-dir",
        default=str(DEFAULT_RESULTS_DIR),
        help="Directory used for inventories, policies, raw group outputs, and logs.",
    )
    parser.add_argument(
        "--sample-size",
        type=int,
        default=DEFAULT_SAMPLE_SIZE,
        help="Full sampled program count (30-50 recommended).",
    )
    parser.add_argument(
        "--smoke-size",
        type=int,
        default=DEFAULT_SMOKE_SIZE,
        help="Small subset size used to validate the pipeline before the full run.",
    )
    parser.add_argument(
        "--smoke-repeat",
        type=int,
        default=DEFAULT_SMOKE_REPEAT,
        help="Repeat count for the smoke validation batch.",
    )
    parser.add_argument(
        "--full-repeat",
        type=int,
        default=DEFAULT_FULL_REPEAT,
        help="Repeat count for the full sampled batch.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-target timeout passed through to the VM batch driver.",
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Combined experiment JSON output path.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Markdown analysis output path.",
    )
    parser.add_argument(
        "--skip-smoke",
        action="store_true",
        help="Skip the initial 10-program smoke validation.",
    )
    parser.add_argument(
        "--skip-runs",
        action="store_true",
        help="Only build the sample and policy trees without running the VM batches.",
    )
    parser.add_argument(
        "--skip-build",
        action="store_true",
        help="Pass --skip-build to the VM batch driver.",
    )
    return parser.parse_args(argv)


def load_json(path: Path) -> Any:
    return json.loads(path.read_text())


def write_json(path: Path, payload: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")


def geomean(values: Iterable[float]) -> float | None:
    normalized = [float(value) for value in values if value is not None and float(value) > 0.0]
    if not normalized:
        return None
    return math.exp(sum(math.log(value) for value in normalized) / len(normalized))


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_pct(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:+.1f}%"


def markdown_table(headers: list[str], rows: list[list[Any]]) -> list[str]:
    rendered = ["| " + " | ".join(headers) + " |", "| " + " | ".join("---" for _ in headers) + " |"]
    for row in rows:
        rendered.append("| " + " | ".join(str(item) for item in row) + " |")
    return rendered


def parse_cmov_total(policy_path: Path) -> int:
    text = policy_path.read_text()
    match = CMOV_TOTAL_RE.search(text)
    if not match:
        return 0
    return int(match.group("count"))


def object_key(record: dict[str, Any]) -> tuple[str, str]:
    return str(record["object_path"]), str(record["program_name"])


def baseline_exec_ns(record: dict[str, Any]) -> int | None:
    return (((record.get("baseline_run") or {}).get("sample") or {}).get("exec_ns"))


def v5_exec_ns(record: dict[str, Any]) -> int | None:
    return (((record.get("v5_run") or {}).get("sample") or {}).get("exec_ns"))


def source_bucket_round_robin(records: list[dict[str, Any]]) -> list[dict[str, Any]]:
    by_object: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        by_object[str(record["object_path"])].append(record)

    object_queues: list[deque[dict[str, Any]]] = []
    for object_path, items in by_object.items():
        items.sort(
            key=lambda item: (
                -int(item["cmov_sites"]),
                str(item["program_name"]),
            )
        )
        object_queues.append(deque(items))

    object_queues.sort(
        key=lambda queue: (
            -int(queue[0]["cmov_sites"]),
            str(queue[0]["object_path"]),
        )
    )
    ordered: list[dict[str, Any]] = []
    while object_queues:
        next_round: list[deque[dict[str, Any]]] = []
        for queue in object_queues:
            if not queue:
                continue
            ordered.append(queue.popleft())
            if queue:
                next_round.append(queue)
        object_queues = next_round
    return ordered


def select_diverse_sample(candidates: list[dict[str, Any]], sample_size: int) -> list[dict[str, Any]]:
    per_source: dict[str, deque[dict[str, Any]]] = {}
    for source_name in sorted({str(item["source_name"]) for item in candidates}):
        source_items = [item for item in candidates if item["source_name"] == source_name]
        per_source[source_name] = deque(source_bucket_round_robin(source_items))

    selected: list[dict[str, Any]] = []
    seen: set[tuple[str, str]] = set()
    while len(selected) < sample_size:
        active_sources = [source for source, queue in per_source.items() if queue]
        if not active_sources:
            break
        active_sources.sort(key=lambda source: (-len(per_source[source]), source))
        made_progress = False
        for source in active_sources:
            if len(selected) >= sample_size:
                break
            queue = per_source[source]
            while queue:
                candidate = queue.popleft()
                key = object_key(candidate)
                if key in seen:
                    continue
                selected.append(candidate)
                seen.add(key)
                made_progress = True
                break
        if not made_progress:
            break
    return selected


def load_cmov_candidates(
    inventory_json: Path,
    current_policy_dir: Path,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    payload = load_json(inventory_json)
    candidates: list[dict[str, Any]] = []
    by_source = Counter()

    for record in payload.get("programs", []):
        if not isinstance(record, dict):
            continue
        if record.get("strategy") != "packet_test_run":
            continue
        if not (record.get("baseline_run") or {}).get("ok"):
            continue
        object_path = (REPO_ROOT / str(record["object_path"])).resolve()
        policy_path = policy_path_for_program(
            object_path,
            str(record["program_name"]),
            current_policy_dir,
        )
        if not policy_path.exists():
            continue
        cmov_total = parse_cmov_total(policy_path)
        if cmov_total <= 0:
            continue
        candidate = {
            "source_name": str(record["source_name"]),
            "object_path": str(record["object_path"]),
            "program_name": str(record["program_name"]),
            "section_name": str(record["section_name"]),
            "prog_type_name": str(record.get("prog_type_name") or ""),
            "io_mode": str(record.get("io_mode") or "context"),
            "input_size": int(record.get("input_size") or 0),
            "cmov_sites": cmov_total,
            "current_policy_path": str(policy_path),
        }
        by_source[candidate["source_name"]] += 1
        candidates.append(candidate)

    candidates.sort(
        key=lambda item: (
            item["source_name"],
            -int(item["cmov_sites"]),
            item["object_path"],
            item["program_name"],
        )
    )
    return candidates, {
        "eligible_programs": len(candidates),
        "eligible_sources": len(by_source),
        "eligible_by_source": dict(by_source),
        "inventory_summary": payload.get("summary") or {},
    }


def create_reduced_inventory(
    inventory_json: Path,
    selected_records: list[dict[str, Any]],
    output_path: Path,
    *,
    label: str,
) -> dict[str, Any]:
    original = load_json(inventory_json)
    wanted = {object_key(record) for record in selected_records}
    programs = [
        record
        for record in original.get("programs", [])
        if isinstance(record, dict)
        and object_key(record) in wanted
    ]
    reduced = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "label": label,
        "source_inventory_json": str(inventory_json),
        "summary": {
            "selected_programs": len(programs),
            "selected_sources": len({str(record["source_name"]) for record in programs}),
        },
        "programs": programs,
    }
    write_json(output_path, reduced)
    return reduced


def summarize_manifest(manifest: dict[str, Any]) -> tuple[dict[str, int], dict[str, int], list[dict[str, Any]]]:
    family_counts = Counter()
    cmov_pattern_counts = Counter()
    rendered_sites: list[dict[str, Any]] = []
    for entry in manifest.get("sites") or []:
        if not isinstance(entry, dict):
            continue
        family = canonical_policy_family_name(str(entry.get("family", "")))
        insn = int(entry.get("insn", entry.get("start_insn", -1)))
        pattern_kind = str(entry.get("pattern_kind", "")).strip()
        family_counts[family] += 1
        if family == "cmov" and pattern_kind:
            cmov_pattern_counts[pattern_kind] += 1
        if insn < 0 or not pattern_kind:
            continue
        rendered_sites.append(
            {
                "insn": insn,
                "family": family,
                "pattern_kind": pattern_kind,
            }
        )
    rendered_sites.sort(
        key=lambda item: (
            int(item["insn"]),
            str(item["family"]),
            str(item["pattern_kind"]),
        )
    )
    return dict(family_counts), dict(cmov_pattern_counts), rendered_sites


def render_with_cmov_policy_text(
    *,
    object_path: Path,
    program_name: str,
    section_name: str,
    manifest: dict[str, Any],
) -> tuple[str, dict[str, int], dict[str, int]]:
    family_counts, cmov_pattern_counts, rendered_sites = summarize_manifest(manifest)
    comments = [
        "Auto-generated by corpus/run_post_cmov_fix_corpus_ablation.py.",
        f"Object: {object_relative_path(object_path).as_posix()}",
        f"Program: {program_name}",
        f"Section: {section_name}",
        f"Total scanner sites: {int((manifest.get('summary') or {}).get('total_sites', 0) or 0)}",
        "Family site totals: "
        + ", ".join(f"{family}={family_counts.get(family, 0)}" for family in FAMILY_ORDER),
        "Selection model: explicit site allowlist; keep every discovered site including CMOV.",
        f"Included CMOV sites in allowlist: {family_counts.get('cmov', 0)}",
    ]
    return (
        render_policy_v3_text(
            program_name=program_name,
            sites=rendered_sites,
            comments=comments,
        ),
        family_counts,
        cmov_pattern_counts,
    )


def build_selected_policy_trees(
    *,
    selected_records: list[dict[str, Any]],
    current_policy_dir: Path,
    with_cmov_dir: Path,
    without_cmov_dir: Path,
    scanner: Path,
    timeout_seconds: int,
) -> list[dict[str, Any]]:
    if with_cmov_dir.exists():
        shutil.rmtree(with_cmov_dir)
    if without_cmov_dir.exists():
        shutil.rmtree(without_cmov_dir)
    with_cmov_dir.mkdir(parents=True, exist_ok=True)
    without_cmov_dir.mkdir(parents=True, exist_ok=True)

    summaries: list[dict[str, Any]] = []
    for selection_rank, record in enumerate(selected_records, start=1):
        object_path = (REPO_ROOT / str(record["object_path"])).resolve()
        current_policy_path = policy_path_for_program(
            object_path,
            str(record["program_name"]),
            current_policy_dir,
        )
        if not current_policy_path.exists():
            raise SystemExit(f"missing source policy for selected program: {current_policy_path}")

        without_policy_path = policy_path_for_program(
            object_path,
            str(record["program_name"]),
            without_cmov_dir,
        )
        without_policy_path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(current_policy_path, without_policy_path)

        manifest = scan_program_manifest(
            scanner,
            object_path,
            str(record["program_name"]),
            str(record["section_name"]),
            timeout_seconds=timeout_seconds,
        )
        with_policy_text, family_counts, cmov_pattern_counts = render_with_cmov_policy_text(
            object_path=object_path,
            program_name=str(record["program_name"]),
            section_name=str(record["section_name"]),
            manifest=manifest,
        )
        with_policy_path = policy_path_for_program(
            object_path,
            str(record["program_name"]),
            with_cmov_dir,
        )
        with_policy_path.parent.mkdir(parents=True, exist_ok=True)
        with_policy_path.write_text(with_policy_text)

        summaries.append(
            {
                **record,
                "selection_rank": selection_rank,
                "current_policy_path": str(current_policy_path),
                "without_cmov_policy_path": str(without_policy_path),
                "with_cmov_policy_path": str(with_policy_path),
                "scanner_summary": dict(manifest.get("summary") or {}),
                "family_counts": family_counts,
                "cmov_pattern_counts": cmov_pattern_counts,
            }
        )
    return summaries


def run_logged_command(command: list[str], log_path: Path) -> None:
    log_path.parent.mkdir(parents=True, exist_ok=True)
    started = time.time()
    print(f"[run] {' '.join(command)}", flush=True)
    with log_path.open("w", encoding="utf-8") as handle:
        completed = subprocess.run(
            command,
            cwd=REPO_ROOT,
            stdout=handle,
            stderr=subprocess.STDOUT,
            text=True,
            check=False,
        )
    duration = time.time() - started
    print(
        f"[done] exit={completed.returncode} duration={duration:.1f}s log={log_path.relative_to(REPO_ROOT).as_posix()}",
        flush=True,
    )
    if completed.returncode != 0:
        log_tail = "\n".join(log_path.read_text().splitlines()[-40:])
        raise SystemExit(
            f"command failed with exit={completed.returncode}: {' '.join(command)}\n"
            f"log tail:\n{log_tail}"
        )


def run_group(
    *,
    label: str,
    driver: Path,
    inventory_json: Path,
    policy_dir: Path,
    kernel_image: Path,
    repeat: int,
    timeout_seconds: int,
    results_dir: Path,
    skip_build: bool,
) -> dict[str, Any]:
    output_json = results_dir / f"{label}.json"
    output_md = results_dir / f"{label}.md"
    output_log = results_dir / "logs" / f"{label}.log"
    command = [
        "python3",
        str(driver),
        "--inventory-json",
        str(inventory_json),
        "--kernel-image",
        str(kernel_image),
        "--use-policy",
        "--policy-dir",
        str(policy_dir),
        "--repeat",
        str(repeat),
        "--timeout",
        str(timeout_seconds),
        "--output-json",
        str(output_json),
        "--output-md",
        str(output_md),
    ]
    if skip_build:
        command.append("--skip-build")
    run_logged_command(command, output_log)
    payload = load_json(output_json)
    return {
        "label": label,
        "json_path": str(output_json),
        "md_path": str(output_md),
        "log_path": str(output_log),
        "summary": payload.get("summary") or {},
        "programs": payload.get("programs") or [],
    }


def compare_groups(
    *,
    selected_programs: list[dict[str, Any]],
    with_group: dict[str, Any],
    without_group: dict[str, Any],
) -> dict[str, Any]:
    selected_lookup = {
        object_key(record): record
        for record in selected_programs
    }
    with_records = {
        object_key(record): record
        for record in with_group.get("programs") or []
    }
    without_records = {
        object_key(record): record
        for record in without_group.get("programs") or []
    }

    compared: list[dict[str, Any]] = []
    only_with = 0
    only_without = 0
    baseline_ratios: list[float] = []
    direct_ratios: list[float] = []
    normalized_ratios: list[float] = []

    for key, selected in sorted(selected_lookup.items()):
        with_record = with_records.get(key)
        without_record = without_records.get(key)
        if with_record is None:
            only_without += 1
            continue
        if without_record is None:
            only_with += 1
            continue

        with_baseline = baseline_exec_ns(with_record)
        without_baseline = baseline_exec_ns(without_record)
        with_exec = v5_exec_ns(with_record)
        without_exec = v5_exec_ns(without_record)

        baseline_ratio = None
        if with_baseline and without_baseline:
            baseline_ratio = float(without_baseline) / float(with_baseline)
            baseline_ratios.append(baseline_ratio)

        direct_ratio = None
        if with_exec and without_exec:
            direct_ratio = float(without_exec) / float(with_exec)
            direct_ratios.append(direct_ratio)

        with_speedup = with_record.get("speedup_ratio")
        without_speedup = without_record.get("speedup_ratio")
        normalized_ratio = None
        if with_speedup and without_speedup:
            normalized_ratio = float(with_speedup) / float(without_speedup)
            normalized_ratios.append(normalized_ratio)

        compared.append(
            {
                "source_name": selected["source_name"],
                "object_path": selected["object_path"],
                "program_name": selected["program_name"],
                "prog_type_name": selected["prog_type_name"],
                "cmov_sites": int(selected["cmov_sites"]),
                "cmov_pattern_counts": dict(selected.get("cmov_pattern_counts") or {}),
                "with_cmov_exec_ns": with_exec,
                "without_cmov_exec_ns": without_exec,
                "with_cmov_baseline_exec_ns": with_baseline,
                "without_cmov_baseline_exec_ns": without_baseline,
                "with_cmov_speedup_ratio": with_record.get("speedup_ratio"),
                "without_cmov_speedup_ratio": without_record.get("speedup_ratio"),
                "direct_without_over_with_exec_ratio": direct_ratio,
                "normalized_with_over_without_ratio": normalized_ratio,
                "baseline_ratio_without_over_with": baseline_ratio,
                "with_cmov_policy_mode": with_record.get("policy_mode"),
                "without_cmov_policy_mode": without_record.get("policy_mode"),
                "with_cmov_applied": bool(with_record.get("v5_run_applied")),
                "without_cmov_applied": bool(without_record.get("v5_run_applied")),
                "with_cmov_requested_families": list(with_record.get("requested_families_run") or []),
                "without_cmov_requested_families": list(without_record.get("requested_families_run") or []),
            }
        )

    wins = [
        row
        for row in compared
        if row.get("normalized_with_over_without_ratio") is not None
        and row["normalized_with_over_without_ratio"] > 1.0
    ]
    regressions = [
        row
        for row in compared
        if row.get("normalized_with_over_without_ratio") is not None
        and row["normalized_with_over_without_ratio"] < 1.0
    ]
    ties = [row for row in compared if row.get("normalized_with_over_without_ratio") == 1.0]

    by_source_rows: list[dict[str, Any]] = []
    by_source: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for row in compared:
        by_source[row["source_name"]].append(row)
    for source_name, rows in sorted(by_source.items()):
        ratios = [
            row["normalized_with_over_without_ratio"]
            for row in rows
            if row.get("normalized_with_over_without_ratio") is not None
        ]
        by_source_rows.append(
            {
                "source_name": source_name,
                "programs": len(rows),
                "cmov_sites": sum(int(row["cmov_sites"]) for row in rows),
                "normalized_with_over_without_ratio_geomean": geomean(ratios),
                "wins": sum(
                    1
                    for row in rows
                    if (row.get("normalized_with_over_without_ratio") or 0.0) > 1.0
                ),
                "regressions": sum(
                    1
                    for row in rows
                    if row.get("normalized_with_over_without_ratio") is not None
                    and row["normalized_with_over_without_ratio"] < 1.0
                ),
            }
        )

    pattern_rows: list[dict[str, Any]] = []
    pattern_buckets: dict[str, dict[str, Any]] = {}
    for row in compared:
        ratio = row.get("normalized_with_over_without_ratio")
        if ratio is None:
            continue
        for pattern_kind, count in (row.get("cmov_pattern_counts") or {}).items():
            bucket = pattern_buckets.setdefault(
                pattern_kind,
                {
                    "pattern_kind": pattern_kind,
                    "programs": 0,
                    "cmov_sites": 0,
                    "wins": 0,
                    "regressions": 0,
                    "ratios": [],
                },
            )
            bucket["programs"] += 1
            bucket["cmov_sites"] += int(count)
            if ratio > 1.0:
                bucket["wins"] += 1
            elif ratio < 1.0:
                bucket["regressions"] += 1
            bucket["ratios"].append(ratio)

    for bucket in pattern_buckets.values():
        pattern_rows.append(
            {
                "pattern_kind": bucket["pattern_kind"],
                "programs": bucket["programs"],
                "cmov_sites": bucket["cmov_sites"],
                "wins": bucket["wins"],
                "regressions": bucket["regressions"],
                "normalized_with_over_without_ratio_geomean": geomean(bucket["ratios"]),
            }
        )
    pattern_rows.sort(key=lambda row: (-row["cmov_sites"], row["pattern_kind"]))

    normalized_geomean = geomean(normalized_ratios)
    compared.sort(
        key=lambda row: (
            row["source_name"],
            row["object_path"],
            row["program_name"],
        )
    )
    top_wins = sorted(
        [row for row in wins if row.get("normalized_with_over_without_ratio") is not None],
        key=lambda row: (
            -(row["normalized_with_over_without_ratio"]),
            row["source_name"],
            row["program_name"],
        ),
    )[:10]
    top_regressions = sorted(
        [row for row in regressions if row.get("normalized_with_over_without_ratio") is not None],
        key=lambda row: (
            row["normalized_with_over_without_ratio"],
            row["source_name"],
            row["program_name"],
        ),
    )[:10]

    if normalized_geomean is None:
        conclusion = "insufficient-data"
    elif normalized_geomean > 1.0:
        conclusion = "cmov-net-positive"
    elif normalized_geomean < 1.0:
        conclusion = "cmov-net-negative"
    else:
        conclusion = "cmov-neutral"

    return {
        "pair_count": len(compared),
        "measured_programs": len(normalized_ratios),
        "missing_only_with": only_with,
        "missing_only_without": only_without,
        "normalized_with_over_without_ratio_geomean": normalized_geomean,
        "direct_without_over_with_exec_ratio_geomean": geomean(direct_ratios),
        "baseline_ratio_without_over_with_geomean": geomean(baseline_ratios),
        "wins": len(wins),
        "regressions": len(regressions),
        "ties": len(ties),
        "conclusion": conclusion,
        "by_source": by_source_rows,
        "by_pattern_kind": pattern_rows,
        "top_wins": top_wins,
        "top_regressions": top_regressions,
        "programs": compared,
    }


def build_markdown(
    *,
    combined: dict[str, Any],
) -> str:
    selection = combined["selection"]
    smoke = combined.get("smoke")
    full = combined.get("full")
    lines: list[str] = [
        "# Post-CMOV-Fix Corpus Ablation",
        "",
        f"- Generated: {combined['generated_at']}",
        f"- Source inventory: `{combined['inventory_json']}`",
        f"- Eligible runnable CMOV pool: {selection['eligible_programs']} programs across {selection['eligible_sources']} sources",
        f"- Full sample size: {selection['selected_programs']}",
        f"- Smoke sample size: {selection['smoke_programs']}",
        f"- Kernel image: `{combined['kernel_image']}`",
        "",
        "## Sample Selection",
        "",
        "The sample is restricted to loadable `packet_test_run` programs whose existing v3 policy comments report at least one CMOV site. This excludes non-runnable corpus projects such as Tetragon/Cilium from the VM timing run, even if they have CMOV-bearing policies.",
        "",
    ]
    lines.extend(
        markdown_table(
            ["Source", "Selected", "CMOV Sites"],
            [
                [
                    row["source_name"],
                    row["programs"],
                    row["cmov_sites"],
                ]
                for row in selection["selected_by_source"]
            ],
        )
    )
    lines.append("")

    if smoke is not None:
        comparison = smoke["comparison"]
        lines.extend(
            [
                "## Smoke Validation",
                "",
                f"- Group A (with CMOV) exec geomean vs stock: {format_ratio(smoke['with_cmov']['summary'].get('exec_ratio_geomean'))}",
                f"- Group B (without CMOV) exec geomean vs stock: {format_ratio(smoke['without_cmov']['summary'].get('exec_ratio_geomean'))}",
                f"- Normalized Group A / Group B geomean: {format_ratio(comparison.get('normalized_with_over_without_ratio_geomean'))}",
                f"- Direct Group B / Group A exec geomean: {format_ratio(comparison.get('direct_without_over_with_exec_ratio_geomean'))}",
                f"- Baseline drift geomean (Group B / Group A): {format_ratio(comparison.get('baseline_ratio_without_over_with_geomean'))}",
                f"- Paired programs: {comparison['pair_count']}",
                f"- Measured programs: {comparison['measured_programs']}",
                f"- Wins for Group A: {comparison['wins']}",
                f"- Regressions for Group A: {comparison['regressions']}",
                "",
            ]
        )

    if full is None:
        return "\n".join(lines) + "\n"

    comparison = full["comparison"]
    lines.extend(
        [
            "## Full Run",
            "",
            f"- Group A (with CMOV) exec geomean vs stock: {format_ratio(full['with_cmov']['summary'].get('exec_ratio_geomean'))}",
            f"- Group B (without CMOV) exec geomean vs stock: {format_ratio(full['without_cmov']['summary'].get('exec_ratio_geomean'))}",
            f"- Normalized Group A / Group B geomean: {format_ratio(comparison.get('normalized_with_over_without_ratio_geomean'))}",
            f"- Direct Group B / Group A exec geomean: {format_ratio(comparison.get('direct_without_over_with_exec_ratio_geomean'))}",
            f"- Baseline drift geomean (Group B / Group A): {format_ratio(comparison.get('baseline_ratio_without_over_with_geomean'))}",
            f"- Paired programs: {comparison['pair_count']}",
            f"- Measured programs: {comparison['measured_programs']}",
            f"- Wins for Group A: {comparison['wins']}",
            f"- Regressions for Group A: {comparison['regressions']}",
            f"- Ties: {comparison['ties']}",
            f"- Conclusion: `{comparison['conclusion']}`",
            "",
            "## By Source",
            "",
        ]
    )
    lines.extend(
        markdown_table(
            ["Source", "Programs", "CMOV Sites", "A/B Normalized", "A Wins", "A Regressions"],
            [
                [
                    row["source_name"],
                    row["programs"],
                    row["cmov_sites"],
                    format_ratio(row["normalized_with_over_without_ratio_geomean"]),
                    row["wins"],
                    row["regressions"],
                ]
                for row in comparison["by_source"]
            ],
        )
    )
    lines.extend(["", "## Largest Group-A Wins", ""])
    lines.extend(
        markdown_table(
            ["Program", "Source", "CMOV Sites", "A/B Normalized", "Patterns"],
            [
                [
                    f"{row['object_path']}:{row['program_name']}",
                    row["source_name"],
                    row["cmov_sites"],
                    format_ratio(row["normalized_with_over_without_ratio"]),
                    ", ".join(
                        f"{name}={count}"
                        for name, count in sorted((row.get("cmov_pattern_counts") or {}).items())
                    ) or "none",
                ]
                for row in comparison["top_wins"]
            ],
        )
    )
    lines.extend(["", "## Largest Group-A Regressions", ""])
    lines.extend(
        markdown_table(
            ["Program", "Source", "CMOV Sites", "A/B Normalized", "Patterns"],
            [
                [
                    f"{row['object_path']}:{row['program_name']}",
                    row["source_name"],
                    row["cmov_sites"],
                    format_ratio(row["normalized_with_over_without_ratio"]),
                    ", ".join(
                        f"{name}={count}"
                        for name, count in sorted((row.get("cmov_pattern_counts") or {}).items())
                    ) or "none",
                ]
                for row in comparison["top_regressions"]
            ],
        )
    )
    lines.extend(["", "## CMOV Pattern-Kind Association", ""])
    lines.extend(
        markdown_table(
            ["Pattern Kind", "Programs", "CMOV Sites", "A/B Normalized", "A Wins", "A Regressions"],
            [
                [
                    row["pattern_kind"],
                    row["programs"],
                    row["cmov_sites"],
                    format_ratio(row["normalized_with_over_without_ratio_geomean"]),
                    row["wins"],
                    row["regressions"],
                ]
                for row in comparison["by_pattern_kind"]
            ],
        )
    )
    lines.extend(
        [
            "",
            "The pattern-kind table is correlational rather than causal: a program can contain multiple CMOV sites and other non-CMOV directives, and the kernel may fail-close some requested CMOV sites back to stock emission.",
            "",
        ]
    )
    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)

    inventory_json = Path(args.inventory_json).resolve()
    scanner = Path(args.scanner).resolve()
    driver = Path(args.driver).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    current_policy_dir = Path(args.current_policy_dir).resolve()
    results_dir = Path(args.results_dir).resolve()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()

    if args.sample_size < 1:
        raise SystemExit("--sample-size must be >= 1")
    if args.smoke_size < 1:
        raise SystemExit("--smoke-size must be >= 1")
    if not inventory_json.exists():
        raise SystemExit(f"inventory JSON not found: {inventory_json}")
    if not scanner.exists():
        raise SystemExit(f"scanner not found: {scanner}")
    if not driver.exists():
        raise SystemExit(f"driver not found: {driver}")
    if not kernel_image.exists():
        raise SystemExit(f"kernel image not found: {kernel_image}")
    if not current_policy_dir.exists():
        raise SystemExit(f"policy dir not found: {current_policy_dir}")

    results_dir.mkdir(parents=True, exist_ok=True)
    eligible, eligibility_summary = load_cmov_candidates(inventory_json, current_policy_dir)
    if not eligible:
        raise SystemExit("no runnable packet-test-run programs with CMOV-bearing policies were found")

    sample_size = min(args.sample_size, len(eligible))
    selected = select_diverse_sample(eligible, sample_size)
    if not selected:
        raise SystemExit("failed to select any programs for the ablation sample")

    smoke_size = min(args.smoke_size, len(selected))
    smoke_selected = selected[:smoke_size]

    full_inventory_path = results_dir / "full_sample_inventory.json"
    smoke_inventory_path = results_dir / "smoke_sample_inventory.json"
    create_reduced_inventory(inventory_json, selected, full_inventory_path, label="post-cmov-fix-full")
    create_reduced_inventory(inventory_json, smoke_selected, smoke_inventory_path, label="post-cmov-fix-smoke")

    with_cmov_dir = results_dir / "policies_with_cmov"
    without_cmov_dir = results_dir / "policies_without_cmov"
    selected_programs = build_selected_policy_trees(
        selected_records=selected,
        current_policy_dir=current_policy_dir,
        with_cmov_dir=with_cmov_dir,
        without_cmov_dir=without_cmov_dir,
        scanner=scanner,
        timeout_seconds=args.timeout,
    )

    selected_by_source: list[dict[str, Any]] = []
    source_groups: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in selected_programs:
        source_groups[record["source_name"]].append(record)
    for source_name, rows in sorted(source_groups.items()):
        selected_by_source.append(
            {
                "source_name": source_name,
                "programs": len(rows),
                "cmov_sites": sum(int(row["cmov_sites"]) for row in rows),
            }
        )

    combined: dict[str, Any] = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "inventory_json": str(inventory_json),
        "kernel_image": str(kernel_image),
        "results_dir": str(results_dir),
        "selection": {
            **eligibility_summary,
            "selected_programs": len(selected_programs),
            "smoke_programs": len(smoke_selected),
            "selected_by_source": selected_by_source,
            "programs": selected_programs,
        },
        "artifacts": {
            "full_inventory_json": str(full_inventory_path),
            "smoke_inventory_json": str(smoke_inventory_path),
            "with_cmov_policy_dir": str(with_cmov_dir),
            "without_cmov_policy_dir": str(without_cmov_dir),
        },
    }

    smoke_result = None
    full_result = None
    if not args.skip_runs:
        if not args.skip_smoke:
            smoke_with = run_group(
                label="smoke_with_cmov",
                driver=driver,
                inventory_json=smoke_inventory_path,
                policy_dir=with_cmov_dir,
                kernel_image=kernel_image,
                repeat=args.smoke_repeat,
                timeout_seconds=args.timeout,
                results_dir=results_dir,
                skip_build=args.skip_build,
            )
            smoke_without = run_group(
                label="smoke_without_cmov",
                driver=driver,
                inventory_json=smoke_inventory_path,
                policy_dir=without_cmov_dir,
                kernel_image=kernel_image,
                repeat=args.smoke_repeat,
                timeout_seconds=args.timeout,
                results_dir=results_dir,
                skip_build=args.skip_build,
            )
            smoke_result = {
                "with_cmov": smoke_with,
                "without_cmov": smoke_without,
                "comparison": compare_groups(
                    selected_programs=[record for record in selected_programs if object_key(record) in {object_key(item) for item in smoke_selected}],
                    with_group=smoke_with,
                    without_group=smoke_without,
                ),
            }
            combined["smoke"] = smoke_result

        full_with = run_group(
            label="full_with_cmov",
            driver=driver,
            inventory_json=full_inventory_path,
            policy_dir=with_cmov_dir,
            kernel_image=kernel_image,
            repeat=args.full_repeat,
            timeout_seconds=args.timeout,
            results_dir=results_dir,
            skip_build=args.skip_build,
        )
        full_without = run_group(
            label="full_without_cmov",
            driver=driver,
            inventory_json=full_inventory_path,
            policy_dir=without_cmov_dir,
            kernel_image=kernel_image,
            repeat=args.full_repeat,
            timeout_seconds=args.timeout,
            results_dir=results_dir,
            skip_build=args.skip_build,
        )
        full_result = {
            "with_cmov": full_with,
            "without_cmov": full_without,
            "comparison": compare_groups(
                selected_programs=selected_programs,
                with_group=full_with,
                without_group=full_without,
            ),
        }
        combined["full"] = full_result

    write_json(output_json, combined)
    output_md.parent.mkdir(parents=True, exist_ok=True)
    output_md.write_text(build_markdown(combined=combined))
    print(f"[wrote] {output_json.relative_to(REPO_ROOT).as_posix()}")
    print(f"[wrote] {output_md.relative_to(REPO_ROOT).as_posix()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
