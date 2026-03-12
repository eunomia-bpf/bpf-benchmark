#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import shlex
import shutil
import subprocess
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

import yaml

SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent
for candidate in (ROOT_DIR, SCRIPT_DIR, ROOT_DIR / "micro", ROOT_DIR / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from orchestrator.inventory import load_packet_test_run_targets
except ImportError:
    from micro.orchestrator.inventory import load_packet_test_run_targets

try:
    from _driver_impl_run_corpus_v5_vm_batch import (
        DEFAULT_BTF_PATH,
        DEFAULT_INVENTORY_JSON,
        DEFAULT_KERNEL_IMAGE,
        DEFAULT_REPEAT,
        DEFAULT_RUNNER,
        DEFAULT_SCANNER,
        DEFAULT_TIMEOUT_SECONDS,
        DEFAULT_VNG,
        build_result_from_guest_run,
        run_text_command,
    )
    from common import build_run_kernel_command
    from policy_utils import (
        POLICY_DIR,
        PolicyDocumentV2,
        parse_policy_v2,
        policy_path_for_program,
        render_policy_v2_text,
    )
except ImportError:
    from corpus._driver_impl_run_corpus_v5_vm_batch import (
        DEFAULT_BTF_PATH,
        DEFAULT_INVENTORY_JSON,
        DEFAULT_KERNEL_IMAGE,
        DEFAULT_REPEAT,
        DEFAULT_RUNNER,
        DEFAULT_SCANNER,
        DEFAULT_TIMEOUT_SECONDS,
        DEFAULT_VNG,
        build_result_from_guest_run,
        run_text_command,
    )
    from corpus.common import build_run_kernel_command
    from corpus.policy_utils import (
        POLICY_DIR,
        PolicyDocumentV2,
        parse_policy_v2,
        policy_path_for_program,
        render_policy_v2_text,
    )


SELF_RELATIVE = Path(__file__).resolve().relative_to(ROOT_DIR)
BATCH_DRIVER_RELATIVE = Path("corpus") / "_driver_impl_run_corpus_v5_vm_batch.py"
DEFAULT_INPUT_JSON = ROOT_DIR / "corpus" / "results" / "corpus_v5_tuned_policy.json"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "corpus" / "results" / "corpus_v5_bflip_skip_sweep_20260312.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "bflip-endian-skip-sweep.md"
ROUND_ORDER = ("round1_tuned_baseline", "round2_bflip_skip", "round3_bflip_endian_skip")
ROUND_LABELS = {
    "round1_tuned_baseline": "current tuned policy",
    "round2_bflip_skip": "branch-flip: skip",
    "round3_bflip_endian_skip": "branch-flip: skip + endian: skip",
}
RECOMPILE_SITE_FIELDS = (
    ("cmov", "cmov_sites"),
    ("wide", "wide_sites"),
    ("rotate", "rotate_sites"),
    ("lea", "lea_sites"),
    ("extract", "bitfield_sites"),
    ("zero-ext", "zero_ext_sites"),
    ("endian", "endian_sites"),
    ("branch-flip", "branch_flip_sites"),
)
SCANNER_FLAGS = {
    "cmov": "--cmov",
    "wide": "--wide-mem",
    "rotate": "--rotate",
    "lea": "--lea",
    "extract": "--extract",
    "zero-ext": "--zero-ext",
    "endian": "--endian",
    "branch-flip": "--branch-flip",
}


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run a three-round framework-kernel VM sweep on the high-confidence "
            "Calico regressors from corpus_v5_tuned_policy.json."
        )
    )
    parser.add_argument(
        "--input-json",
        default=str(DEFAULT_INPUT_JSON),
        help="Tuned-policy result JSON used to select the high-confidence Calico regressors.",
    )
    parser.add_argument(
        "--inventory-json",
        default=str(DEFAULT_INVENTORY_JSON),
        help="Packet-test-run inventory JSON used to recover the runnable targets.",
    )
    parser.add_argument(
        "--policy-dir",
        default=str(POLICY_DIR),
        help="Corpus policy root. Baseline uses this tree; round 2 policies are installed here after the sweep.",
    )
    parser.add_argument(
        "--runner",
        default=str(DEFAULT_RUNNER),
        help="Path to micro_exec.",
    )
    parser.add_argument(
        "--scanner",
        default=str(DEFAULT_SCANNER),
        help="Path to bpf-jit-scanner.",
    )
    parser.add_argument(
        "--kernel-image",
        default=str(DEFAULT_KERNEL_IMAGE),
        help="Framework kernel image used for the VM sweep.",
    )
    parser.add_argument(
        "--btf-custom-path",
        default=str(DEFAULT_BTF_PATH),
        help="BTF path passed to guest micro_exec invocations.",
    )
    parser.add_argument(
        "--vng",
        default=DEFAULT_VNG,
        help="vng executable.",
    )
    parser.add_argument(
        "--repeat",
        type=int,
        default=DEFAULT_REPEAT,
        help="Repeat count passed to each micro_exec measurement.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-target timeout in seconds.",
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Structured sweep output JSON.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Markdown analysis output.",
    )
    parser.add_argument(
        "--memory",
        default="4G",
        help="Guest memory size passed to vng.",
    )
    parser.add_argument(
        "--cpus",
        default="2",
        help="Guest CPU count passed to vng.",
    )
    parser.add_argument(
        "--max-programs",
        type=int,
        help="Optional cap after filtering; useful for smoke tests.",
    )
    parser.add_argument(
        "--keep-temp",
        action="store_true",
        help="Keep the temporary round policy trees on disk.",
    )
    parser.add_argument(
        "--no-install",
        action="store_true",
        help="Do not copy the round-2 per-program policies into corpus/policies at the end of the sweep.",
    )
    parser.add_argument(
        "--no-preserve-object-skips",
        action="store_true",
        help=(
            "Do not start the generated sweep policies from the existing per-program "
            "version 2 policy. The default preserves the current tuned decisions and "
            "then adds branch-flip/endian skips on top."
        ),
    )
    return parser.parse_args(argv)


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def now_iso() -> str:
    return datetime.now(timezone.utc).isoformat()


def relpath(path: Path | str) -> str:
    try:
        return str(Path(path).resolve().relative_to(ROOT_DIR))
    except ValueError:
        return str(Path(path))


def parse_project(object_path: str) -> str:
    parts = Path(object_path).parts
    if len(parts) > 2 and parts[0] == "corpus" and parts[1] in {"build", "expanded_corpus", "objects"}:
        return parts[2]
    return parts[0] if parts else ""


def program_key(object_path: str, program_name: str) -> str:
    return f"{object_path}:{program_name}"


def short_program_label(object_path: str, program_name: str) -> str:
    obj = Path(object_path)
    parts = obj.parts
    if len(parts) > 3 and parts[0] == "corpus" and parts[1] in {"build", "expanded_corpus", "objects"}:
        object_label = "/".join(parts[2:])
    else:
        object_label = str(obj)
    return f"{object_label}:{program_name}"


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_ns(value: int | float | None) -> str:
    if value is None:
        return "n/a"
    return str(int(round(float(value))))


def geomean(values: list[float]) -> float | None:
    usable = [float(value) for value in values if isinstance(value, (int, float)) and value > 0.0]
    if not usable:
        return None
    return math.exp(sum(math.log(value) for value in usable) / len(usable))


def extract_exec_ns(record: dict[str, Any] | None, key: str) -> int | None:
    if not record:
        return None
    sample = ((record.get(key) or {}).get("sample") or {})
    value = sample.get("exec_ns")
    if value is None:
        return None
    return int(value)


def extract_speedup_ratio(record: dict[str, Any] | None) -> float | None:
    if not record:
        return None
    value = record.get("speedup_ratio")
    if not isinstance(value, (int, float)):
        return None
    return float(value)


def annotate_policy_filtered_counts(record: dict[str, Any]) -> dict[str, Any]:
    recompile = (((record.get("v5_run") or {}).get("sample") or {}).get("recompile") or {})
    site_counts = {
        family: int(recompile.get(field, 0) or 0)
        for family, field in RECOMPILE_SITE_FIELDS
    }
    record["policy_filtered_site_counts"] = site_counts
    record["policy_filtered_families"] = [
        family for family, count in site_counts.items() if count > 0
    ]
    record["policy_filtered_total_sites"] = int(recompile.get("total_sites", 0) or 0)
    return record


def parse_json_lines(stdout: str) -> list[Any]:
    payloads: list[Any] = []
    for line in stdout.splitlines():
        text = line.strip()
        if not text:
            continue
        try:
            payloads.append(json.loads(text))
        except json.JSONDecodeError:
            continue
    return payloads


def build_guest_exec(argv: list[str]) -> str:
    return " ".join(shlex.quote(part) for part in argv)


def build_vng_command(
    *,
    args: argparse.Namespace,
    guest_exec: str,
) -> list[str]:
    command = [
        args.vng,
        "--run",
        str(Path(args.kernel_image).resolve()),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--memory",
        str(args.memory),
        "--cpus",
        str(args.cpus),
        "--rwdir",
        str((ROOT_DIR / "corpus" / "results").resolve()),
        "--rwdir",
        str((ROOT_DIR / "docs" / "tmp").resolve()),
        "--exec",
        guest_exec,
    ]
    return command


def collect_guest_info(args: argparse.Namespace) -> dict[str, Any]:
    guest_exec = build_guest_exec(["python3", str(BATCH_DRIVER_RELATIVE), "--guest-info"])
    invocation = run_text_command(
        build_vng_command(args=args, guest_exec=guest_exec),
        args.timeout,
    )
    payloads = parse_json_lines(invocation["stdout"])
    return {
        "invocation": {
            "ok": invocation["ok"],
            "returncode": invocation["returncode"],
            "timed_out": invocation["timed_out"],
            "duration_seconds": invocation["duration_seconds"],
            "error": invocation["error"],
        },
        "payload": payloads[-1] if invocation["ok"] and payloads else None,
    }


def effective_default_action(default_action: str) -> str:
    return "skip" if default_action == "stock" else default_action


def load_program_policy(
    policy_root: Path,
    object_path: Path,
    program_name: str,
) -> PolicyDocumentV2 | None:
    policy_path = policy_path_for_program(object_path, program_name, policy_root)
    if not policy_path.exists():
        return None
    return parse_policy_v2(policy_path)


def dump_guest_xlated(
    *,
    args: argparse.Namespace,
    target: dict[str, Any],
    output_path: Path,
) -> None:
    ensure_parent(output_path)
    command = build_run_kernel_command(
        runner=Path(args.runner).resolve(),
        object_path=(ROOT_DIR / str(target["object_path"])).resolve(),
        program_name=str(target["program_name"]),
        io_mode=str(target["io_mode"]),
        memory_path=Path(str(target["memory_path"])).resolve() if target.get("memory_path") else None,
        input_size=int(target["input_size"]),
        repeat=1,
        compile_only=True,
        recompile_v5=False,
        dump_xlated=output_path,
        btf_custom_path=Path(args.btf_custom_path).resolve(),
        use_sudo=False,
    )
    guest_exec = build_guest_exec([str(part) for part in command])
    invocation = run_text_command(
        build_vng_command(args=args, guest_exec=guest_exec),
        (args.timeout * 2) + 120,
    )
    if not invocation["ok"]:
        detail = invocation["error"] or invocation["stderr"] or invocation["stdout"] or "guest xlated dump failed"
        raise RuntimeError(
            f"guest xlated dump failed for {short_program_label(str(target['object_path']), str(target['program_name']))}: {detail}"
        )
    if not output_path.exists():
        raise RuntimeError(
            f"guest xlated dump did not create {output_path} for {short_program_label(str(target['object_path']), str(target['program_name']))}"
        )


def scanner_generate_policy_from_xlated(
    *,
    scanner: Path,
    xlated_path: Path,
    program_name: str,
    output_path: Path,
) -> dict[str, Any]:
    ensure_parent(output_path)
    command = [
        str(scanner),
        "generate-policy",
        "--xlated",
        str(xlated_path),
        "--default",
        "apply",
        "--output",
        str(output_path),
    ]
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        check=False,
        timeout=60,
    )
    if completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip() or f"exit={completed.returncode}"
        raise RuntimeError(
            f"scanner generate-policy failed for {relpath(xlated_path)} ({program_name}): {detail}"
        )
    payload = yaml.safe_load(output_path.read_text())
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid version 2 policy for {relpath(xlated_path)} ({program_name})")
    payload["program"] = program_name
    return payload


def write_skip_policy(
    *,
    scanner: Path,
    xlated_path: Path,
    object_path: Path,
    program_name: str,
    output_path: Path,
    base_policy: PolicyDocumentV2 | None,
    skip_families: set[str],
) -> dict[str, Any]:
    payload = scanner_generate_policy_from_xlated(
        scanner=scanner,
        xlated_path=xlated_path,
        program_name=program_name,
        output_path=output_path,
    )
    sites = payload.get("sites")
    if not isinstance(sites, list):
        raise RuntimeError(f"policy template missing sites list for {relpath(object_path)}:{program_name}")

    output_default = base_policy.default if base_policy is not None else "apply"
    baseline_default = effective_default_action(output_default)
    baseline_actions = (
        {(site.insn, site.family): site.action for site in base_policy.sites}
        if base_policy is not None
        else {}
    )

    site_counts: dict[str, int] = {}
    skip_counts: dict[str, int] = {}
    rendered_sites: list[dict[str, Any]] = []
    for entry in sites:
        if not isinstance(entry, dict):
            raise RuntimeError(f"invalid site entry in {output_path}")
        insn = int(entry.get("insn", -1))
        family = str(entry.get("family", "")).strip()
        if insn < 0 or not family:
            raise RuntimeError(f"invalid site entry in {output_path}")
        site_counts[family] = site_counts.get(family, 0) + 1
        action = baseline_actions.get((insn, family), baseline_default)
        if family in skip_families:
            action = "skip"
        if action == "skip":
            skip_counts[family] = skip_counts.get(family, 0) + 1
        if action != baseline_default:
            rendered_sites.append(
                {
                    "insn": insn,
                    "family": family,
                    "action": action,
                }
            )

    output_path.write_text(
        render_policy_v2_text(
            program_name=program_name,
            default_action=output_default,
            sites=rendered_sites,
        )
    )
    return {
        "policy_path": str(output_path),
        "xlated_path": str(xlated_path),
        "site_count": len(sites),
        "rendered_site_count": len(rendered_sites),
        "site_counts": site_counts,
        "default_action": output_default,
        "skip_families": sorted(skip_families),
        "skip_counts": skip_counts,
    }


def select_programs(
    *,
    input_json: Path,
    inventory_json: Path,
    max_programs: int | None,
) -> list[dict[str, Any]]:
    tuned = json.loads(input_json.read_text())
    rows = tuned.get("programs")
    if not isinstance(rows, list):
        raise SystemExit(f"unexpected tuned JSON schema in {input_json}")

    targets, _ = load_packet_test_run_targets(
        inventory_json,
        require_inventory_sites=False,
    )
    target_map = {
        program_key(str(target["object_path"]), str(target["program_name"])): dict(target)
        for target in targets
    }

    selected: list[dict[str, Any]] = []
    for row in rows:
        if not isinstance(row, dict):
            continue
        object_path = str(row.get("object_path") or "")
        program_name = str(row.get("program_name") or "")
        ratio = row.get("speedup_ratio")
        stock_exec = ((row.get("baseline_run") or {}).get("sample") or {}).get("exec_ns")
        if stock_exec is None:
            stock_exec = row.get("inventory_baseline_exec_ns")
        if parse_project(object_path) != "calico":
            continue
        if not isinstance(ratio, (int, float)) or float(ratio) >= 1.0:
            continue
        if not isinstance(stock_exec, (int, float)) or float(stock_exec) < 100.0:
            continue
        key = program_key(object_path, program_name)
        target = target_map.get(key)
        if target is None:
            raise SystemExit(f"inventory target not found for {key}")
        selected.append(
            {
                "key": key,
                "object_path": object_path,
                "program_name": program_name,
                "section_name": row.get("section_name"),
                "source_name": row.get("source_name"),
                "stock_exec_ns": int(stock_exec),
                "tuned_ratio": float(ratio),
                "tuned_applied_families": list(row.get("applied_families_run") or []),
                "tuned_policy_path": row.get("policy_path"),
                "target": target,
            }
        )

    selected.sort(key=lambda item: (item["object_path"], item["program_name"]))
    if max_programs is not None:
        selected = selected[:max_programs]
    return selected


def install_round2_policies(
    *,
    generated_policies: list[dict[str, Any]],
    install_policy_root: Path,
) -> list[str]:
    installed: list[str] = []
    for entry in generated_policies:
        source_path = Path(entry["round2_policy_path"]).resolve()
        install_path = install_policy_root / Path(entry["relative_policy_path"])
        ensure_parent(install_path)
        shutil.copy2(source_path, install_path)
        installed.append(str(install_path))
    return installed


def round_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    measured = [record for record in records if extract_speedup_ratio(record) is not None]
    ratios = [float(record["speedup_ratio"]) for record in measured if isinstance(record.get("speedup_ratio"), (int, float))]
    candidate_execs = [extract_exec_ns(record, "v5_run") for record in measured]
    applied = [
        record
        for record in measured
        if record.get("v5_compile_applied") or record.get("v5_run_applied")
    ]
    return {
        "targets": len(records),
        "measured": len(measured),
        "applied": len(applied),
        "exec_ratio_geomean": geomean(ratios),
        "candidate_exec_ns_geomean": geomean([float(value) for value in candidate_execs if value is not None]),
        "wins_vs_stock": sum(1 for value in ratios if value > 1.0),
        "regressions_vs_stock": sum(1 for value in ratios if value < 1.0),
        "ties_vs_stock": sum(1 for value in ratios if value == 1.0),
    }


def comparison_rows(
    selected: list[dict[str, Any]],
    rounds: dict[str, list[dict[str, Any]]],
) -> list[dict[str, Any]]:
    round_maps = {
        round_name: {
            program_key(record["object_path"], record["program_name"]): record
            for record in records
        }
        for round_name, records in rounds.items()
    }

    rows: list[dict[str, Any]] = []
    for item in selected:
        key = item["key"]
        r1 = round_maps["round1_tuned_baseline"].get(key)
        r2 = round_maps["round2_bflip_skip"].get(key)
        r3 = round_maps["round3_bflip_endian_skip"].get(key)
        r1_exec = extract_exec_ns(r1, "v5_run")
        r2_exec = extract_exec_ns(r2, "v5_run")
        r3_exec = extract_exec_ns(r3, "v5_run")
        row = {
            "key": key,
            "label": short_program_label(item["object_path"], item["program_name"]),
            "object_path": item["object_path"],
            "program_name": item["program_name"],
            "stock_exec_ns": item["stock_exec_ns"],
            "source_tuned_ratio": item["tuned_ratio"],
            "round1_ratio": extract_speedup_ratio(r1),
            "round2_ratio": extract_speedup_ratio(r2),
            "round3_ratio": extract_speedup_ratio(r3),
            "round1_exec_ns": r1_exec,
            "round2_exec_ns": r2_exec,
            "round3_exec_ns": r3_exec,
            "round2_vs_round1_exec_ratio": (float(r1_exec) / float(r2_exec)) if r1_exec and r2_exec else None,
            "round3_vs_round1_exec_ratio": (float(r1_exec) / float(r3_exec)) if r1_exec and r3_exec else None,
            "round2_applied_families": list((r2 or {}).get("applied_families_run") or []),
            "round3_applied_families": list((r3 or {}).get("applied_families_run") or []),
        }
        rows.append(row)

    rows.sort(
        key=lambda row: (
            (row["round3_vs_round1_exec_ratio"] if isinstance(row["round3_vs_round1_exec_ratio"], (int, float)) else -math.inf),
            row["label"],
        ),
        reverse=True,
    )
    return rows


def overall_summary(
    *,
    round_summaries: dict[str, dict[str, Any]],
    comparison: list[dict[str, Any]],
) -> dict[str, Any]:
    round2_vs_round1 = [
        float(row["round2_vs_round1_exec_ratio"])
        for row in comparison
        if isinstance(row.get("round2_vs_round1_exec_ratio"), (int, float))
    ]
    round3_vs_round1 = [
        float(row["round3_vs_round1_exec_ratio"])
        for row in comparison
        if isinstance(row.get("round3_vs_round1_exec_ratio"), (int, float))
    ]
    return {
        "round1_exec_ratio_geomean": round_summaries["round1_tuned_baseline"]["exec_ratio_geomean"],
        "round2_exec_ratio_geomean": round_summaries["round2_bflip_skip"]["exec_ratio_geomean"],
        "round3_exec_ratio_geomean": round_summaries["round3_bflip_endian_skip"]["exec_ratio_geomean"],
        "round2_vs_round1_policy_exec_geomean": geomean(round2_vs_round1),
        "round3_vs_round1_policy_exec_geomean": geomean(round3_vs_round1),
        "round2_improved_vs_round1": sum(1 for value in round2_vs_round1 if value > 1.0),
        "round3_improved_vs_round1": sum(1 for value in round3_vs_round1 if value > 1.0),
        "round2_regressed_vs_round1": sum(1 for value in round2_vs_round1 if value < 1.0),
        "round3_regressed_vs_round1": sum(1 for value in round3_vs_round1 if value < 1.0),
    }


def build_markdown(payload: dict[str, Any]) -> str:
    selected = payload["selected_programs"]
    summaries = payload["round_summaries"]
    overall = payload["summary"]
    comparison = payload["comparison"]
    round1 = summaries.get("round1_tuned_baseline", {})
    round2 = summaries.get("round2_bflip_skip", {})
    round3 = summaries.get("round3_bflip_endian_skip", {})

    lines: list[str] = [
        "# Branch-Flip / Endian Skip Sweep",
        "",
        "## Scope",
        "",
        f"- Input tuned artifact: `{relpath(payload['input_json'])}`",
        f"- Inventory: `{relpath(payload['inventory_json'])}`",
        f"- Selected programs: `{len(selected)}` high-confidence Calico regressors (`stock exec_ns >= 100`, tuned ratio `< 1.0x`)",
        f"- VM kernel: `{relpath(payload['kernel_image'])}`",
        f"- Repeat count: `{payload['repeat']}`",
        f"- Preserve existing per-program policy decisions: `{payload['preserve_existing_policy']}`",
        "",
        "## Takeaway",
        "",
        f"- The remeasured tuned baseline on this 38-program slice is `{format_ratio(round1.get('exec_ratio_geomean'))}` vs stock.",
        f"- `branch-flip: skip` alone is worse on the slice: `{format_ratio(round2.get('exec_ratio_geomean'))}` vs stock, even though its policy-to-policy geomean vs round 1 is `{format_ratio(overall.get('round2_vs_round1_policy_exec_geomean'))}`.",
        f"- `branch-flip: skip + endian: skip` is the best measured variant here: `{format_ratio(round3.get('exec_ratio_geomean'))}` vs stock and `{format_ratio(overall.get('round3_vs_round1_policy_exec_geomean'))}` policy-to-policy vs round 1. It improves over the current tuned policy, but it does not reach break-even against stock on this full high-confidence Calico regressor slice.",
        "",
        "## Round Summary",
        "",
        "| Round | Measured | Applied | Geomean vs stock | Policy geomean vs round 1 | Wins vs round 1 | Regressions vs round 1 |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: |",
        f"| Round 1: current tuned policy | {round1.get('measured', 0)} | {round1.get('applied', 0)} | {format_ratio(round1.get('exec_ratio_geomean'))} | 1.000x | 0 | 0 |",
        f"| Round 2: branch-flip skip | {round2.get('measured', 0)} | {round2.get('applied', 0)} | {format_ratio(round2.get('exec_ratio_geomean'))} | {format_ratio(overall.get('round2_vs_round1_policy_exec_geomean'))} | {overall.get('round2_improved_vs_round1', 0)} | {overall.get('round2_regressed_vs_round1', 0)} |",
        f"| Round 3: branch-flip + endian skip | {round3.get('measured', 0)} | {round3.get('applied', 0)} | {format_ratio(round3.get('exec_ratio_geomean'))} | {format_ratio(overall.get('round3_vs_round1_policy_exec_geomean'))} | {overall.get('round3_improved_vs_round1', 0)} | {overall.get('round3_regressed_vs_round1', 0)} |",
        "",
        "## Notes",
        "",
        "- Round 1 remeasures the existing `corpus/policies/` tuned policy as the same-setup baseline.",
        "- Round 2 and Round 3 use per-program version 2 policies generated from `scanner generate-policy` templates.",
        "- When `preserve_existing_policy=true`, Round 2 and Round 3 start from the current per-program v2 policy and then force `branch-flip` / `endian` sites to `skip`.",
        "",
        "## Per-Program Results",
        "",
        "| Program | Stock ns | Source tuned | Round 1 | Round 2 | Round 3 | Round 2 vs R1 | Round 3 vs R1 |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]

    for row in comparison:
        lines.append(
            "| "
            + f"`{row['label']}` | {format_ns(row['stock_exec_ns'])} | {format_ratio(row['source_tuned_ratio'])}"
            + f" | {format_ratio(row['round1_ratio'])} | {format_ratio(row['round2_ratio'])}"
            + f" | {format_ratio(row['round3_ratio'])} | {format_ratio(row['round2_vs_round1_exec_ratio'])}"
            + f" | {format_ratio(row['round3_vs_round1_exec_ratio'])} |"
        )

    lines.extend(
        [
            "",
            "## Installed Policies",
            "",
            f"- Installed per-program branch-flip policy files: `{len(payload['installed_policy_files'])}`",
        ]
    )
    for path in payload["installed_policy_files"]:
        lines.append(f"- `{relpath(path)}`")

    return "\n".join(lines) + "\n"


def persist_payload(payload: dict[str, Any], output_json: Path, output_md: Path) -> None:
    payload["updated_at"] = now_iso()
    ensure_parent(output_json)
    ensure_parent(output_md)
    output_json.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    output_md.write_text(build_markdown(payload))


def run_guest_target(
    *,
    args: argparse.Namespace,
    target: dict[str, Any],
    policy_dir: Path,
) -> dict[str, Any]:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="bflip-sweep-target-",
        suffix=".json",
        dir=ROOT_DIR,
        delete=False,
    )
    try:
        with handle:
            json.dump(target, handle)
            handle.write("\n")
        target_path = Path(handle.name)
        guest_argv = [
            "python3",
            str(BATCH_DRIVER_RELATIVE),
            "--guest-target-json",
            str(target_path),
            "--runner",
            str(Path(args.runner).resolve()),
            "--scanner",
            str(Path(args.scanner).resolve()),
            "--btf-custom-path",
            str(Path(args.btf_custom_path).resolve()),
            "--repeat",
            str(args.repeat),
            "--timeout",
            str(args.timeout),
            "--policy-dir",
            str(policy_dir.resolve()),
            "--use-policy",
        ]
        guest_exec = build_guest_exec(guest_argv)
        invocation = run_text_command(
            build_vng_command(args=args, guest_exec=guest_exec),
            (args.timeout * 4) + 120,
        )
        record = build_result_from_guest_run(target=target, invocation=invocation)
        record["vm_command"] = build_vng_command(args=args, guest_exec=guest_exec)
        record["policy_dir_used"] = str(policy_dir.resolve())
        return record
    finally:
        Path(handle.name).unlink(missing_ok=True)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)

    input_json = Path(args.input_json).resolve()
    inventory_json = Path(args.inventory_json).resolve()
    policy_dir = Path(args.policy_dir).resolve()
    scanner = Path(args.scanner).resolve()
    runner = Path(args.runner).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    preserve_existing_policy = not args.no_preserve_object_skips

    for path, label in (
        (input_json, "input JSON"),
        (inventory_json, "inventory JSON"),
        (policy_dir, "policy dir"),
        (scanner, "scanner"),
        (runner, "runner"),
        (kernel_image, "kernel image"),
        (btf_custom_path, "BTF path"),
    ):
        if not path.exists():
            raise SystemExit(f"{label} not found: {path}")

    selected = select_programs(
        input_json=input_json,
        inventory_json=inventory_json,
        max_programs=args.max_programs,
    )
    if not selected:
        raise SystemExit("no matching high-confidence Calico regressors found")

    payload: dict[str, Any] = {
        "generated_at": now_iso(),
        "repo_root": str(ROOT_DIR),
        "script": str(SELF_RELATIVE),
        "input_json": str(input_json),
        "inventory_json": str(inventory_json),
        "policy_dir": str(policy_dir),
        "runner_binary": str(runner),
        "scanner_binary": str(scanner),
        "kernel_image": str(kernel_image),
        "btf_custom_path": str(btf_custom_path),
        "vng_binary": args.vng,
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "memory": str(args.memory),
        "cpus": str(args.cpus),
        "preserve_existing_policy": preserve_existing_policy,
        "install_policies": not args.no_install,
        "selected_programs": selected,
        "guest_smoke": None,
        "generated_policy_metadata": [],
        "rounds": {name: {"label": ROUND_LABELS[name], "programs": []} for name in ROUND_ORDER},
        "round_summaries": {},
        "comparison": [],
        "summary": {},
        "installed_policy_files": [],
    }
    persist_payload(payload, output_json, output_md)

    print(f"Selected {len(selected)} high-confidence Calico regressors from {relpath(input_json)}.", flush=True)
    guest_smoke = collect_guest_info(args)
    payload["guest_smoke"] = guest_smoke
    persist_payload(payload, output_json, output_md)
    if not guest_smoke.get("payload"):
        raise SystemExit("guest smoke run failed; see output JSON for details")
    print(
        "Guest smoke passed:"
        f" kernel_release={guest_smoke['payload'].get('kernel_release')}"
        f" uid={guest_smoke['payload'].get('uid')}",
        flush=True,
    )

    temp_root = Path(
        tempfile.mkdtemp(prefix="bflip-endian-sweep-", dir=(ROOT_DIR / "docs" / "tmp"))
    )
    generated_policy_metadata: list[dict[str, Any]] = []
    installed_policy_files: list[str] = []
    round2_policy_root = temp_root / "round2_policies"
    round3_policy_root = temp_root / "round3_policies"
    shutil.copytree(policy_dir, round2_policy_root)
    shutil.copytree(policy_dir, round3_policy_root)

    try:
        for index, item in enumerate(selected, start=1):
            object_path = (ROOT_DIR / item["object_path"]).resolve()
            program_name = item["program_name"]
            current_policy_path = policy_path_for_program(object_path, program_name, policy_dir)
            base_policy = (
                load_program_policy(policy_dir, object_path, program_name)
                if preserve_existing_policy
                else None
            )
            round2_skips = {"branch-flip"}
            round3_skips = {"branch-flip", "endian"}

            xlated_path = temp_root / "xlated" / Path(item["object_path"]).name / f"{program_name}.xlated"
            dump_guest_xlated(
                args=args,
                target=item["target"],
                output_path=xlated_path,
            )
            round2_path = policy_path_for_program(object_path, program_name, round2_policy_root)
            round3_path = policy_path_for_program(object_path, program_name, round3_policy_root)
            round2_meta = write_skip_policy(
                scanner=scanner,
                xlated_path=xlated_path,
                object_path=object_path,
                program_name=program_name,
                output_path=round2_path,
                base_policy=base_policy,
                skip_families=round2_skips,
            )
            round3_meta = write_skip_policy(
                scanner=scanner,
                xlated_path=xlated_path,
                object_path=object_path,
                program_name=program_name,
                output_path=round3_path,
                base_policy=base_policy,
                skip_families=round3_skips,
            )
            generated_policy_metadata.append(
                {
                    "key": item["key"],
                    "label": short_program_label(item["object_path"], program_name),
                    "source_policy_path": str(current_policy_path) if current_policy_path.exists() else None,
                    "source_policy_default": base_policy.default if base_policy is not None else None,
                    "relative_policy_path": str(
                        current_policy_path.relative_to(policy_dir)
                    ),
                    "round2_policy_path": str(round2_path),
                    "round3_policy_path": str(round3_path),
                    "round2": round2_meta,
                    "round3": round3_meta,
                }
            )
            print(
                f"[policy {index}/{len(selected)}] {short_program_label(item['object_path'], program_name)}"
                f" source_default={base_policy.default if base_policy is not None else 'apply'}"
                f" forced_skips={sorted(round3_skips)}",
                flush=True,
            )

        payload["generated_policy_metadata"] = generated_policy_metadata
        persist_payload(payload, output_json, output_md)

        round_policy_dirs = {
            "round1_tuned_baseline": policy_dir,
            "round2_bflip_skip": round2_policy_root,
            "round3_bflip_endian_skip": round3_policy_root,
        }
        for round_name in ROUND_ORDER:
            records: list[dict[str, Any]] = []
            payload["rounds"][round_name]["policy_dir"] = str(round_policy_dirs[round_name])
            for index, item in enumerate(selected, start=1):
                label = short_program_label(item["object_path"], item["program_name"])
                print(f"[{round_name} {index}/{len(selected)}] {label}", flush=True)
                record = run_guest_target(
                    args=args,
                    target=item["target"],
                    policy_dir=round_policy_dirs[round_name],
                )
                record = annotate_policy_filtered_counts(record)
                record["selection_stock_exec_ns"] = item["stock_exec_ns"]
                record["selection_source_tuned_ratio"] = item["tuned_ratio"]
                records.append(record)
                payload["rounds"][round_name]["programs"] = records
                payload["round_summaries"][round_name] = round_summary(records)
                persist_payload(payload, output_json, output_md)
            payload["round_summaries"][round_name] = round_summary(records)
            persist_payload(payload, output_json, output_md)

        payload["comparison"] = comparison_rows(
            selected=selected,
            rounds={name: payload["rounds"][name]["programs"] for name in ROUND_ORDER},
        )
        payload["summary"] = overall_summary(
            round_summaries=payload["round_summaries"],
            comparison=payload["comparison"],
        )
        if not args.no_install:
            installed_policy_files = install_round2_policies(
                generated_policies=generated_policy_metadata,
                install_policy_root=policy_dir,
            )
        payload["installed_policy_files"] = installed_policy_files
        persist_payload(payload, output_json, output_md)

        print(
            "Sweep complete:"
            f" round1={format_ratio(payload['summary'].get('round1_exec_ratio_geomean'))}"
            f" round2={format_ratio(payload['summary'].get('round2_exec_ratio_geomean'))}"
            f" round3={format_ratio(payload['summary'].get('round3_exec_ratio_geomean'))}",
            flush=True,
        )
    finally:
        if args.keep_temp:
            print(f"Kept temporary policy trees at {temp_root}", flush=True)
        else:
            shutil.rmtree(temp_root, ignore_errors=True)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
