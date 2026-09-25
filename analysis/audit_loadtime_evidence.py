#!/usr/bin/env python3
"""Audit retained load-time rewrite, load, and workload evidence."""
from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


IDENTITY_RE = re.compile(r"pid=(\d+) tid=(\d+)")
OPTIMIZED_RE = re.compile(
    r"loadtime optimized prog=(\S*) insns=(\d+)->(\d+).*?workdir=(\S+)"
)
LOAD_RE = re.compile(r"PROG_LOAD -> fd=(-?\d+) errno=(\d+)")
PKTGEN_RE = re.compile(
    r"Result:\s+OK:\s+(\d+)\(c(\d+)\+d(\d+)\)\s+usec,\s+"
    r"(\d+)\s+\([^\n]*\)\s*\n\s*(\d+)pps[^\n]*errors:\s*(\d+)",
    re.MULTILINE,
)


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


def file_inventory(path: Path, root: Path) -> dict[str, Any]:
    stat = path.stat()
    return {
        "path": str(path.relative_to(root)),
        "bytes": stat.st_size,
        "mtime_utc": datetime.fromtimestamp(
            stat.st_mtime, tz=timezone.utc
        ).isoformat(),
    }


def app_stem(app: str) -> str:
    return app.replace("/", "__")


def parse_reports(
    run_dir: Path,
    report_path: Path,
    expected_pass: str,
) -> tuple[list[dict[str, Any]], list[str]]:
    rows: list[dict[str, Any]] = []
    errors: list[str] = []
    workdirs = run_dir / "details" / "loadtime-workdirs"

    try:
        lines = report_path.read_text().splitlines()
    except OSError as exc:
        raise AuditError(f"cannot read report stream {report_path}: {exc}") from exc

    for line_number, line in enumerate(lines, start=1):
        if not line.strip():
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError as exc:
            errors.append(f"line {line_number}: malformed JSON: {exc}")
            continue
        report = row.get("report")
        if not isinstance(report, dict):
            errors.append(f"line {line_number}: missing embedded report object")
            continue

        label = Path(str(row.get("workdir", ""))).name or f"line {line_number}"
        workdir = workdirs / label
        if row.get("step") != expected_pass or report.get("pass") != expected_pass:
            errors.append(f"{label}: report pass is not {expected_pass}")
        if row.get("step_index") != 0:
            errors.append(f"{label}: step_index is not zero")

        fields: dict[str, int] = {}
        for name in (
            "sites_matched",
            "sites_applied",
            "sites_skipped",
            "insn_count_before",
            "insn_count_after",
            "insn_delta",
        ):
            value = report.get(name)
            if not isinstance(value, int):
                errors.append(f"{label}: {name} is not an integer")
                value = 0
            fields[name] = value
        if any(fields[name] < 0 for name in (
            "sites_matched", "sites_applied", "sites_skipped",
            "insn_count_before", "insn_count_after",
        )):
            errors.append(f"{label}: negative report count")
        if fields["sites_matched"] != (
            fields["sites_applied"] + fields["sites_skipped"]
        ):
            errors.append(f"{label}: matched != applied + skipped")
        if fields["insn_delta"] != (
            fields["insn_count_after"] - fields["insn_count_before"]
        ):
            errors.append(f"{label}: instruction delta is inconsistent")
        entries = report.get("inlined_map_entries")
        if not isinstance(entries, list) or len(entries) != fields["sites_applied"]:
            errors.append(f"{label}: inlined-map-entry count is inconsistent")

        recorded_report = Path(str(row.get("report_path", "")))
        expected_report = workdir / "report.0.json"
        if recorded_report.name != "report.0.json" or recorded_report.parent.name != label:
            errors.append(f"{label}: recorded report path does not match workdir")
        try:
            if read_json(expected_report) != report:
                errors.append(f"{label}: retained report differs from JSONL report")
        except AuditError as exc:
            errors.append(f"{label}: {exc}")

        changed = fields["sites_applied"] > 0
        input_path = workdir / "input.step.0.bin"
        output_path = workdir / "output.next.0.bin"
        if changed:
            if not input_path.is_file():
                errors.append(f"{label}: missing input.step.0.bin")
            elif input_path.stat().st_size != 8 * fields["insn_count_before"]:
                errors.append(
                    f"{label}: input.step.0.bin bytes {input_path.stat().st_size} != "
                    f"reported before bytes {8 * fields['insn_count_before']}"
                )
            if not output_path.is_file():
                errors.append(f"{label}: missing output.next.0.bin")
            elif output_path.stat().st_size != 8 * fields["insn_count_after"]:
                errors.append(
                    f"{label}: output bytes {output_path.stat().st_size} != "
                    f"reported after bytes {8 * fields['insn_count_after']}"
                )
            if input_path.is_file() and output_path.is_file():
                if input_path.stat().st_size % 8 or output_path.stat().st_size % 8:
                    errors.append(f"{label}: bytecode file is not instruction-aligned")
                elif input_path.read_bytes() == output_path.read_bytes():
                    errors.append(f"{label}: changed input and output are identical")

        rows.append({
            "line": line_number,
            "workdir": label,
            "prog_name": str(row.get("prog_name", "")),
            "prog_type": str(row.get("prog_type", "")),
            **fields,
        })

    names = [row["workdir"] for row in rows]
    for name, count in Counter(names).items():
        if count != 1:
            errors.append(f"{name}: workdir occurs {count} times in report stream")
    return rows, errors


def parse_shim_log(log_path: Path) -> dict[str, Any]:
    try:
        lines = log_path.read_text(errors="replace").splitlines()
    except OSError as exc:
        raise AuditError(f"cannot read shim log {log_path}: {exc}") from exc

    pending: dict[tuple[str, str], dict[str, Any]] = {}
    optimized: list[dict[str, Any]] = []
    pairing_errors: list[str] = []
    original_rejections: list[str] = []
    candidate_errors: list[str] = []

    for line_number, line in enumerate(lines, start=1):
        if "loadtime original bytecode rejected" in line:
            original_rejections.append(line)
        elif "loadtime" in line and re.search(r"failed|rejected", line):
            candidate_errors.append(line)

        identity_match = IDENTITY_RE.search(line)
        if identity_match is None:
            continue
        identity = identity_match.groups()
        optimized_match = OPTIMIZED_RE.search(line)
        if optimized_match:
            if identity in pending:
                pairing_errors.append(
                    f"line {line_number}: second optimized event before load for "
                    f"pid/tid {identity[0]}/{identity[1]}"
                )
            program, before, after, workdir = optimized_match.groups()
            event = {
                "line": line_number,
                "pid": int(identity[0]),
                "tid": int(identity[1]),
                "program": program,
                "before": int(before),
                "after": int(after),
                "workdir": Path(workdir).name,
                "fd": None,
                "errno": None,
            }
            pending[identity] = event
            optimized.append(event)
            continue
        load_match = LOAD_RE.search(line)
        if load_match and identity in pending:
            event = pending.pop(identity)
            event["fd"] = int(load_match.group(1))
            event["errno"] = int(load_match.group(2))

    for identity, event in pending.items():
        pairing_errors.append(
            f"{event['workdir']}: no following PROG_LOAD for pid/tid "
            f"{identity[0]}/{identity[1]}"
        )
    return {
        "optimized": optimized,
        "pairing_errors": pairing_errors,
        "original_preflight_rejections": original_rejections,
        "candidate_errors": candidate_errors,
    }


def join_reports_and_events(
    reports: list[dict[str, Any]],
    events: list[dict[str, Any]],
) -> list[str]:
    errors: list[str] = []
    changed = {row["workdir"]: row for row in reports if row["sites_applied"] > 0}
    by_workdir: dict[str, list[dict[str, Any]]] = {}
    for event in events:
        by_workdir.setdefault(event["workdir"], []).append(event)

    for workdir in sorted(set(changed) | set(by_workdir)):
        row = changed.get(workdir)
        matches = by_workdir.get(workdir, [])
        if row is None:
            errors.append(f"{workdir}: optimized event has no changed report")
            continue
        if len(matches) != 1:
            errors.append(
                f"{workdir}: changed report has {len(matches)} optimized events"
            )
            continue
        event = matches[0]
        if event["program"] != row["prog_name"]:
            errors.append(f"{workdir}: program name differs between report and log")
        if event["before"] != row["insn_count_before"]:
            errors.append(f"{workdir}: before count differs between report and log")
        if event["after"] != row["insn_count_after"]:
            errors.append(f"{workdir}: after count differs between report and log")
    return errors


def summarize_integrity_errors(errors: list[str]) -> dict[str, Any]:
    categories: dict[str, list[str]] = {}
    for error in errors:
        if "missing output.next.0.bin" in error:
            category = "missing_retained_output"
        elif "input.step.0.bin" in error:
            category = "retained_input_not_before_image"
        elif "optimized event" in error or "PROG_LOAD" in error:
            category = "event_pairing"
        elif "report" in error:
            category = "report_integrity"
        else:
            category = "other"
        categories.setdefault(category, []).append(error)
    return {
        "total": len(errors),
        "categories": [
            {
                "category": category,
                "count": len(items),
                "examples": items[:3],
            }
            for category, items in sorted(categories.items())
        ],
    }


WORKLOAD_CONTRACTS: dict[str, dict[str, Any]] = {
    "cilium/agent": {
        "names": {
            "cilium_endpoint_pktgen_forward",
            "cilium_endpoint_pktgen_reverse",
        },
        "leaf_count": 2,
    },
    # Katran emits one pktgen leaf per available kpktgend thread (a machine
    # property, not a fixed number), all sharing one workload name.
    "katran": {
        "names": {"katran_kernel_pktgen_l2_udp_thread"},
        "leaf_count": None,
    },
}


def parse_workloads(data: dict[str, Any], app: str) -> dict[str, Any]:
    contract = WORKLOAD_CONTRACTS.get(app)
    require(contract is not None, f"no workload contract for app {app!r}")
    expected_names = contract["names"]
    expected_leaf_count = contract["leaf_count"]
    phases: dict[str, Any] = {}
    for phase in ("baseline", "post_rejit"):
        workloads = (data.get(phase) or {}).get("workloads")
        require(isinstance(workloads, list), f"{phase}: workloads are missing")
        components: list[dict[str, Any]] = []
        for workload in workloads:
            leaves = workload.get("components")
            require(isinstance(leaves, list), f"{phase}: workload components missing")
            for leaf in leaves:
                name = leaf.get("workload_name")
                require(name in expected_names, f"{phase}: unexpected workload {name}")
                require(leaf.get("returncode") == 0, f"{phase}/{name}: nonzero return code")
                require(
                    (leaf.get("config") or {}).get("tool") == "kernel_pktgen",
                    f"{phase}/{name}: workload is not kernel_pktgen",
                )
                matches = list(PKTGEN_RE.finditer(leaf.get("stdout") or ""))
                require(len(matches) == 1, f"{phase}/{name}: expected one pktgen result")
                usec, active_usec, delay_usec, packets, pps, errors = map(
                    int, matches[0].groups()
                )
                components.append({
                    "name": name,
                    "duration_s": leaf.get("duration_s"),
                    "result_usec": usec,
                    "active_usec": active_usec,
                    "delay_usec": delay_usec,
                    "packet_count": packets,
                    "packets_per_second": pps,
                    "error_count": errors,
                })
        names = {row["name"] for row in components}
        if expected_leaf_count is not None:
            require(
                names == expected_names and len(components) == expected_leaf_count,
                f"{phase}: expected exactly the declared pktgen leaves for {app}",
            )
        else:
            require(
                names == expected_names and len(components) >= 1,
                f"{phase}: expected at least one {app} pktgen leaf",
            )
        components.sort(key=lambda row: row["name"])
        phases[phase] = {
            "components": components,
            "packets_per_second_sum": sum(
                row["packets_per_second"] for row in components
            ),
            "packet_count_sum": sum(row["packet_count"] for row in components),
            "error_count_sum": sum(row["error_count"] for row in components),
        }
    require(
        len(phases["baseline"]["components"]) == len(phases["post_rejit"]["components"]),
        f"{app}: baseline and post-rejit leaf counts differ",
    )
    phases["policy_to_baseline_ratio"] = (
        phases["post_rejit"]["packets_per_second_sum"]
        / phases["baseline"]["packets_per_second_sum"]
    )
    return phases


def audit(args: argparse.Namespace) -> tuple[dict[str, Any], int]:
    run_dir = args.run_dir.resolve()
    require(run_dir.is_dir(), f"run directory not found: {run_dir}")
    stem = app_stem(args.app)
    paths = {
        "metadata": run_dir / "metadata.json",
        "start": run_dir / "provenance" / "start.json",
        "app": run_dir / "details" / "apps" / f"{stem}.json",
        "plan": run_dir / "details" / "loadtime-plans" / f"{stem}.json",
        "reports": run_dir / "details" / "loadtime-reports" / f"{stem}.jsonl",
        "shim_log": run_dir / "details" / "shim-logs" / f"{stem}.post_rejit.log",
    }
    for label, path in paths.items():
        require(path.is_file(), f"missing {label} file: {path}")

    metadata = read_json(paths["metadata"])
    start = read_json(paths["start"])
    app = read_json(paths["app"])
    plan = read_json(paths["plan"])
    require(metadata.get("status") == "completed", "suite status is not completed")
    require(metadata.get("suite") == "corpus", "suite is not corpus")
    require(metadata.get("run_type") == "x86_kvm_corpus", "run type is not x86 KVM corpus")
    require(metadata.get("samples") == args.expected_samples, "sample count mismatch")
    require(
        metadata.get("workload_seconds") == args.expected_workload_seconds,
        "workload duration mismatch",
    )
    enabled = (metadata.get("config") or {}).get("enabled_passes")
    require(enabled == [args.expected_pass], f"enabled passes {enabled!r} != [{args.expected_pass!r}]")
    require(app.get("app") == args.app, "application name mismatch")
    require(app.get("status") == "ok", "application status is not ok")
    require(app.get("error") == "", "application error is not empty")
    steps = plan.get("steps")
    require(plan.get("cmd") == "execute_plan", "load-time plan command mismatch")
    require(isinstance(steps, list) and len(steps) == 1, "load-time plan is not one step")
    require(steps[0].get("name") == args.expected_pass, "load-time plan step mismatch")
    require(
        f"--pass {args.expected_pass}" in str(steps[0].get("command", "")),
        "load-time plan command does not name expected pass",
    )

    reports, integrity_errors = parse_reports(
        run_dir, paths["reports"], args.expected_pass
    )
    log = parse_shim_log(paths["shim_log"])
    integrity_errors.extend(log["pairing_errors"])
    integrity_errors.extend(join_reports_and_events(reports, log["optimized"]))
    workloads = parse_workloads(app, args.app)

    changed = [row for row in reports if row["sites_applied"] > 0]
    successful = [event for event in log["optimized"] if event["fd"] is not None and event["fd"] >= 0]
    failed = [event for event in log["optimized"] if event["fd"] is not None and event["fd"] < 0]
    if integrity_errors:
        outcome = "invalid/inconclusive"
        exit_code = 1
    elif not changed:
        outcome = "contradicted"
        exit_code = 0
    elif successful and not failed:
        outcome = "supported"
        exit_code = 0
    elif successful and failed:
        outcome = "mixed"
        exit_code = 0
    else:
        outcome = "contradicted"
        exit_code = 0

    by_program: Counter[tuple[str, str]] = Counter()
    sites_by_program: Counter[tuple[str, str]] = Counter()
    for row in changed:
        key = (row["prog_name"], row["prog_type"])
        by_program[key] += 1
        sites_by_program[key] += row["sites_applied"]

    referenced_workdirs = {
        row["workdir"] for row in reports
    } | {
        event["workdir"] for event in log["optimized"]
    }
    workdir_file_count = 0
    workdir_bytes = 0
    workdirs_root = run_dir / "details" / "loadtime-workdirs"
    for name in referenced_workdirs:
        directory = workdirs_root / name
        if directory.is_dir():
            for path in directory.rglob("*"):
                if path.is_file():
                    workdir_file_count += 1
                    workdir_bytes += path.stat().st_size

    result = {
        "outcome": outcome,
        "artifact": {
            "path": str(args.run_dir),
            "tracked_or_public": False,
            "publication": "backlog",
            "source_revision": start.get("source_revision"),
            "make_command": start.get("command"),
            "core_files": [file_inventory(path, run_dir) for path in paths.values()],
            "referenced_workdirs": len(referenced_workdirs),
            "referenced_workdir_files": workdir_file_count,
            "referenced_workdir_bytes": workdir_bytes,
        },
        "reports": {
            "rows": len(reports),
            "changed_load_instances": len(changed),
            "sites_matched": sum(row["sites_matched"] for row in reports),
            "sites_applied": sum(row["sites_applied"] for row in reports),
            "sites_skipped": sum(row["sites_skipped"] for row in reports),
            "changed_insns_before": sum(row["insn_count_before"] for row in changed),
            "changed_insns_after": sum(row["insn_count_after"] for row in changed),
            "changed_insn_delta": sum(row["insn_delta"] for row in changed),
            "program_name_type_pairs": [
                {
                    "prog_name": key[0],
                    "prog_type": key[1],
                    "changed_load_instances": by_program[key],
                    "sites_applied": sites_by_program[key],
                }
                for key in sorted(by_program)
            ],
        },
        "bytecode_files": {
            "changed_workdirs": len(changed),
            "input_matches_reported_before": sum(
                (workdirs_root / row["workdir"] / "input.step.0.bin").is_file()
                and (workdirs_root / row["workdir"] / "input.step.0.bin").stat().st_size
                == 8 * row["insn_count_before"]
                for row in changed
            ),
            "mutable_input_matches_reported_after": sum(
                (workdirs_root / row["workdir"] / "input.bin").is_file()
                and (workdirs_root / row["workdir"] / "input.bin").stat().st_size
                == 8 * row["insn_count_after"]
                for row in changed
            ),
            "retained_output_next_0": sum(
                (workdirs_root / row["workdir"] / "output.next.0.bin").is_file()
                for row in changed
            ),
            "output_matches_reported_after": sum(
                (workdirs_root / row["workdir"] / "output.next.0.bin").is_file()
                and (workdirs_root / row["workdir"] / "output.next.0.bin").stat().st_size
                == 8 * row["insn_count_after"]
                for row in changed
            ),
        },
        "loads": {
            "optimized_events": len(log["optimized"]),
            "successful_changed_loads": len(successful),
            "failed_changed_loads": len(failed),
            "unpaired_optimized_events": sum(
                event["fd"] is None for event in log["optimized"]
            ),
            "original_preflight_pass_throughs": len(
                log["original_preflight_rejections"]
            ),
            "other_candidate_errors": log["candidate_errors"],
        },
        "workloads": workloads,
        "integrity_errors": summarize_integrity_errors(integrity_errors),
    }
    return result, exit_code


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    parser.add_argument("run_dir", type=Path)
    parser.add_argument("--app", required=True)
    parser.add_argument("--expected-pass", required=True)
    parser.add_argument("--expected-samples", required=True, type=int)
    parser.add_argument("--expected-workload-seconds", required=True, type=float)
    args = parser.parse_args()
    try:
        result, exit_code = audit(args)
    except AuditError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    print(json.dumps(result, indent=2, sort_keys=True))
    if exit_code:
        print(
            f"error: invalid/inconclusive evidence: "
            f"{result['integrity_errors']['total']} integrity errors",
            file=sys.stderr,
        )
    return exit_code


if __name__ == "__main__":
    raise SystemExit(main())
