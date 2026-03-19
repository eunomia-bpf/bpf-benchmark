#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

try:
    from results_layout import authoritative_output_path, smoke_output_path
except ImportError:
    from corpus.results_layout import authoritative_output_path, smoke_output_path

try:
    import _driver_impl_run_corpus_tracing_exec as tracing_exec_impl
except ImportError:
    from corpus import _driver_impl_run_corpus_tracing_exec as tracing_exec_impl

try:
    from orchestrator.inventory import discover_object_programs
except ImportError:
    from micro.orchestrator.inventory import discover_object_programs
try:
    from common import (
        add_corpus_build_report_argument,
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_scanner_argument,
        add_section_filter_argument,
        add_timeout_argument,
        ensure_parent,
        require_minimum,
        summarize_text,
        write_json_output,
        write_text_output,
    )
except ImportError:
    from corpus.common import (
        add_corpus_build_report_argument,
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_scanner_argument,
        add_section_filter_argument,
        add_timeout_argument,
        ensure_parent,
        require_minimum,
        summarize_text,
        write_json_output,
        write_text_output,
    )


ROOT_DIR = REPO_ROOT
SELF_RELATIVE = Path(__file__).resolve().relative_to(ROOT_DIR)
DEFAULT_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "tracing_corpus_vm")
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "tracing-corpus-vm-report.md"
DEFAULT_PLAN_MD = ROOT_DIR / "docs" / "tmp" / "tracing-corpus-vm-plan.md"
DEFAULT_KERNEL_IMAGE = ROOT_DIR / "vendor" / "linux-framework" / "arch" / "x86" / "boot" / "bzImage"
TARGET_SECTION_ROOTS = (
    "fentry",
    "fexit",
    "fmod_ret",
    "kprobe",
    "kretprobe",
    "ksyscall",
    "kretsyscall",
    "lsm",
    "raw_tp",
    "raw_tracepoint",
    "tp",
    "tp_btf",
    "tracepoint",
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run the tracing corpus exec driver on all tracing-style corpus programs "
            "inside the framework-kernel VM and report stock vs v5 recompile deltas."
        )
    )
    add_output_json_argument(parser, DEFAULT_OUTPUT_JSON)
    add_output_md_argument(parser, DEFAULT_OUTPUT_MD)
    parser.add_argument(
        "--plan-md",
        default=str(DEFAULT_PLAN_MD),
        help="Fallback markdown path used when the framework kernel image is unavailable.",
    )
    parser.add_argument(
        "--kernel-image",
        default=str(DEFAULT_KERNEL_IMAGE),
        help="Framework kernel bzImage used for the VM run.",
    )
    add_runner_argument(parser, help_text="Path to the micro_exec runner used for list-programs.")
    add_scanner_argument(parser, tracing_exec_impl.DEFAULT_SCANNER, help_text="Path to the bpf-jit-scanner binary.")
    add_corpus_build_report_argument(
        parser,
        help_text=(
            "Optional expanded corpus build JSON report. When omitted, "
            "corpus/results/expanded_corpus_build.latest.json is used if present."
        ),
    )
    add_repeat_argument(parser, tracing_exec_impl.DEFAULT_REPEAT, help_text="Measurement workload iterations per phase.")
    parser.add_argument(
        "--warmup-repeat",
        type=int,
        default=tracing_exec_impl.DEFAULT_WARMUP_REPEAT,
        help="Warmup workload iterations before baseline and recompile phases.",
    )
    add_timeout_argument(parser, tracing_exec_impl.DEFAULT_TIMEOUT_SECONDS, help_text="Per-program timeout budget in seconds.")
    parser.add_argument(
        "--vm-timeout",
        type=int,
        default=tracing_exec_impl.DEFAULT_VM_TIMEOUT_SECONDS,
        help="Wall-clock timeout for the guest run.",
    )
    parser.add_argument("--cpus", type=int, default=tracing_exec_impl.DEFAULT_VM_CPUS, help="Guest CPU count.")
    parser.add_argument("--mem", default=tracing_exec_impl.DEFAULT_VM_MEM, help="Guest memory size.")
    add_filter_argument(parser, help_text="Only include objects/programs containing this substring.")
    parser.add_argument("--source", action="append", dest="sources", help="Only include corpus/build/<source>/... objects.")
    add_section_filter_argument(parser, help_text="Only include matching section names.")
    add_max_programs_argument(parser, help_text="Optional cap for smoke tests.")
    parser.add_argument("--dry-run", action="store_true", help="List the tracing targets that would be tested, without booting the VM.")
    parser.add_argument("--guest-batch-json", help=argparse.SUPPRESS)
    parser.add_argument("--guest-single-target-json", help=argparse.SUPPRESS)
    return parser.parse_args(argv)


def write_json(path: Path, payload: dict[str, Any]) -> None:
    write_json_output(path, payload)


def write_text(path: Path, text: str) -> None:
    write_text_output(path, text)


def project_name_for_object(object_path: Path) -> str:
    try:
        return object_path.relative_to(ROOT_DIR / "corpus" / "build").parts[0]
    except Exception:
        return "unknown"


def tracing_family_for_root(section_root: str) -> str:
    if section_root in {"kprobe", "kretprobe", "ksyscall", "kretsyscall"}:
        return "kprobe"
    if section_root in {"tracepoint", "tp", "tp_btf"}:
        return "tracepoint"
    if section_root in {"raw_tracepoint", "raw_tp"}:
        return "raw_tracepoint"
    if section_root == "lsm":
        return "lsm"
    if section_root in {"fentry", "fmod_ret"}:
        return "fentry"
    if section_root == "fexit":
        return "fexit"
    return section_root


def corpus_layout() -> dict[str, Any]:
    expanded = ROOT_DIR / "corpus" / "expanded_corpus"
    objects = ROOT_DIR / "corpus" / "objects"
    build = ROOT_DIR / "corpus" / "build"
    return {
        "build_exists": build.exists(),
        "expanded_corpus_exists": expanded.exists(),
        "objects_dir_exists": objects.exists(),
        "note": (
            "Current repo layout uses corpus/build/ as the canonical object root; "
            "corpus/expanded_corpus/ and corpus/objects/ are absent in this snapshot."
            if build.exists() and not expanded.exists() and not objects.exists()
            else "Legacy corpus paths are still present."
        ),
    }


def ready_target_rows(records: list[dict[str, Any]]) -> list[list[Any]]:
    rows: list[list[Any]] = []
    for record in records:
        if record["status"] != "ready":
            continue
        attach_target = record.get("attach_target") or {}
        workload = record.get("workload") or {}
        rows.append(
            [
                f"{record['object_path']}:{record['program_name']}",
                record["project"],
                record["section_name"],
                record["section_root"],
                attach_target.get("display_name") or attach_target.get("attach_target") or "n/a",
                workload.get("name") or "n/a",
            ]
        )
    return rows


def discover_targets(args: argparse.Namespace, runner: Path) -> dict[str, Any]:
    corpus_build_report = Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    corpus_bpf_objects, skipped_non_bpf, corpus_source = tracing_exec_impl.discover_corpus_bpf_objects(corpus_build_report)
    corpus_objects = tracing_exec_impl.apply_filters(
        corpus_bpf_objects,
        sources=args.sources,
        filters=args.filters,
    )

    catalog = tracing_exec_impl.KernelCatalog()
    records: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []
    lowered_filters = [token.lower() for token in (args.filters or [])]

    for object_path in corpus_objects:
        try:
            inventory = discover_object_programs(runner, object_path, timeout_seconds=args.timeout)
        except Exception as exc:
            inventory_failures.append(
                {
                    "object_path": tracing_exec_impl.relpath(object_path),
                    "project": project_name_for_object(object_path),
                    "error": str(exc),
                }
            )
            continue

        for program in inventory:
            section_name = program.section_name
            if lowered_filters and not any(
                token in tracing_exec_impl.relpath(object_path).lower()
                or token in program.name.lower()
                or token in section_name.lower()
                for token in lowered_filters
            ):
                continue
            if args.section_filters and not any(token in section_name for token in args.section_filters):
                continue

            section_root = tracing_exec_impl.canonical_section_root(section_name)
            if section_root not in TARGET_SECTION_ROOTS:
                continue

            record: dict[str, Any] = {
                "object_path": tracing_exec_impl.relpath(object_path),
                "project": project_name_for_object(object_path),
                "program_name": program.name,
                "section_name": section_name,
                "section_root": section_root,
                "family": tracing_family_for_root(section_root),
                "insn_count": int(program.insn_count),
                "prog_type_name": str(program.prog_type_name),
                "attach_type_name": str(program.attach_type_name),
                "status": "ready",
            }

            attach_target, skip_reason = tracing_exec_impl.resolve_attach_target(
                catalog,
                object_path,
                program.name,
                section_name,
            )
            if attach_target is None:
                record["status"] = "skipped"
                record["skip_stage"] = "attach-target"
                record["skip_reason"] = skip_reason
                records.append(record)
                if args.max_programs is not None and len(records) >= args.max_programs:
                    break
                continue

            workload, skip_reason = tracing_exec_impl.choose_workload(
                attach_target,
                program.name,
                section_name,
            )
            if workload is None:
                record["status"] = "skipped"
                record["skip_stage"] = "workload"
                record["skip_reason"] = skip_reason
                record["attach_target"] = attach_target.to_dict()
                records.append(record)
                if args.max_programs is not None and len(records) >= args.max_programs:
                    break
                continue

            record["attach_target"] = attach_target.to_dict()
            record["workload"] = {
                "name": workload.name,
                "description": workload.description,
            }
            records.append(record)
            if args.max_programs is not None and len(records) >= args.max_programs:
                break

        if args.max_programs is not None and len(records) >= args.max_programs:
            break

    summary = build_discovery_summary(records, inventory_failures)
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "host-preflight",
        "corpus_source": corpus_source,
        "objects_found": len(corpus_objects),
        "skipped_non_bpf": skipped_non_bpf,
        "inventory_failures": inventory_failures,
        "summary": summary,
        "programs": records,
    }


def build_discovery_summary(records: list[dict[str, Any]], inventory_failures: list[dict[str, Any]]) -> dict[str, Any]:
    ready = [record for record in records if record["status"] == "ready"]
    skipped = [record for record in records if record["status"] != "ready"]
    by_root = Counter(record["section_root"] for record in ready)
    by_family = Counter(record["family"] for record in ready)
    by_project = Counter(record["project"] for record in ready)
    skip_reasons = Counter(record.get("skip_reason") or "skipped" for record in skipped)
    skip_stages = Counter(record.get("skip_stage") or "unknown" for record in skipped)
    return {
        "programs_considered": len(records),
        "ready_programs": len(ready),
        "skipped_programs": len(skipped),
        "inventory_failures": len(inventory_failures),
        "ready_by_root": dict(sorted(by_root.items())),
        "ready_by_family": dict(sorted(by_family.items())),
        "ready_by_project": dict(by_project.most_common(20)),
        "skip_stages": dict(sorted(skip_stages.items())),
        "skip_reasons": dict(skip_reasons.most_common(20)),
    }


def build_dry_run_markdown(payload: dict[str, Any], *, heading: str, lead_note: str | None = None) -> str:
    discovery = payload["discovery"]
    summary = discovery["summary"]
    ready_rows = ready_target_rows(discovery["programs"])
    skipped_rows = [
        [
            f"{record['object_path']}:{record['program_name']}",
            record["section_name"],
            record.get("skip_stage") or "unknown",
            record.get("skip_reason") or "skipped",
        ]
        for record in discovery["programs"]
        if record["status"] != "ready"
    ]

    lines: list[str] = [
        f"# {heading}",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Kernel image: `{payload['kernel_image']}`",
        f"- Kernel image present: {'yes' if payload['kernel_image_exists'] else 'no'}",
        f"- Target section roots: `{', '.join(payload['target_section_roots'])}`",
        f"- Discovery mode: `{payload['discovery_mode']}`",
        f"- Corpus source: {discovery['corpus_source']}",
        f"- Objects discovered: {discovery['objects_found']}",
        f"- Programs considered: {summary['programs_considered']}",
        f"- Ready programs: {summary['ready_programs']}",
        f"- Skipped programs: {summary['skipped_programs']}",
        f"- Inventory failures: {summary['inventory_failures']}",
        f"- Layout note: {payload['corpus_layout']['note']}",
        "",
    ]
    if lead_note:
        lines.extend([lead_note, ""])

    lines.extend(["## Summary", ""])
    lines.extend(
        tracing_exec_impl.markdown_table(
            ["Metric", "Value"],
            [
                ["Ready kprobe-family programs", summary["ready_by_family"].get("kprobe", 0)],
                ["Ready tracepoint-family programs", summary["ready_by_family"].get("tracepoint", 0)],
                ["Ready raw_tracepoint-family programs", summary["ready_by_family"].get("raw_tracepoint", 0)],
                ["Ready lsm programs", summary["ready_by_family"].get("lsm", 0)],
                ["Ready fentry programs", summary["ready_by_family"].get("fentry", 0)],
                ["Ready fexit programs", summary["ready_by_family"].get("fexit", 0)],
            ],
        )
    )
    lines.append("")

    if ready_rows:
        lines.extend(["## Ready Targets", ""])
        lines.extend(
            tracing_exec_impl.markdown_table(
                ["Program", "Project", "Section", "Root", "Attach Target", "Workload"],
                ready_rows,
            )
        )
        lines.append("")

    if skipped_rows:
        lines.extend(["## Skipped Targets", ""])
        lines.extend(
            tracing_exec_impl.markdown_table(
                ["Program", "Section", "Stage", "Reason"],
                skipped_rows,
            )
        )
        lines.append("")

    if discovery["inventory_failures"]:
        lines.extend(["## Inventory Failures", ""])
        lines.extend(
            tracing_exec_impl.markdown_table(
                ["Object", "Project", "Error"],
                [
                    [item["object_path"], item["project"], item["error"]]
                    for item in discovery["inventory_failures"]
                ],
            )
        )
        lines.append("")

    if summary["skip_reasons"]:
        lines.extend(["## Top Skip Reasons", ""])
        lines.extend(
            tracing_exec_impl.markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["skip_reasons"].items()],
            )
        )
        lines.append("")

    lines.extend(
        [
            "## Notes",
            "",
            "- This preview runs discovery on the current host environment. The actual VM run re-resolves attach targets and workloads inside the guest before measuring stock vs recompile.",
            "- Roots included here cover the requested tracing families plus their canonical aliases: `kretprobe`, `ksyscall`, `kretsyscall`, `tp`, `tp_btf`, `raw_tp`, and `fmod_ret`.",
            "",
        ]
    )
    return "\n".join(lines)


def build_plan_markdown(payload: dict[str, Any]) -> str:
    command_preview = [
        "python3",
        "micro/driver.py",
        "corpus",
        "tracing-vm",
        "--kernel-image",
        payload["kernel_image"],
        "--output-json",
        str(DEFAULT_OUTPUT_JSON),
        "--output-md",
        str(DEFAULT_OUTPUT_MD),
    ]
    lead_note = (
        "The framework kernel image is missing, so the script cannot boot the VM for the actual tracing corpus run. "
        "This file records the exact target set and command flow that should be used once the image exists."
    )
    body = build_dry_run_markdown(payload, heading="Tracing Corpus VM Plan", lead_note=lead_note)
    lines = body.splitlines()
    insert_at = lines.index("## Summary") if "## Summary" in lines else len(lines)
    extra = [
        "## Command Flow",
        "",
        "1. Build or locate the framework kernel image at the requested `--kernel-image` path.",
        "2. Run the driver below to boot `vng`, execute the tracing corpus driver in the guest, and write the final stock-vs-recompile report.",
        "3. Inspect the output JSON and markdown summary paths for the measured results.",
        "",
        "```bash",
        " ".join(command_preview),
        "```",
        "",
    ]
    lines[insert_at:insert_at] = extra
    return "\n".join(lines)


def print_dry_run_listing(payload: dict[str, Any]) -> None:
    discovery = payload["discovery"]
    summary = discovery["summary"]
    print(
        "dry-run "
        f"considered={summary['programs_considered']} "
        f"ready={summary['ready_programs']} "
        f"skipped={summary['skipped_programs']} "
        f"inventory_failures={summary['inventory_failures']}"
    )
    for row in ready_target_rows(discovery["programs"]):
        program, project, section, root, attach_target, workload = row
        print(
            f"{program} "
            f"[project={project} root={root} section={section} attach={attach_target} workload={workload}]"
        )


def parse_last_json_line(stdout: str) -> dict[str, Any]:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError("guest child produced no JSON output")
    return json.loads(lines[-1])


def failed_target_record(
    target: dict[str, Any],
    *,
    error: str,
    stdout: str = "",
    stderr: str = "",
) -> dict[str, Any]:
    record = dict(target)
    record["status"] = "failed"
    record["error"] = error
    if stdout:
        record["stdout_tail"] = summarize_text(stdout)
    if stderr:
        record["stderr_tail"] = summarize_text(stderr)
    tracing_exec_impl.summarize_program(record)
    return record


def run_guest_single_target_mode(args: argparse.Namespace, runner: Path, scanner: Path) -> int:
    tracing_exec_impl.ensure_root(argv=[str(Path(__file__).resolve()), *list(sys.argv[1:])])
    target_path = Path(args.guest_single_target_json).resolve()
    target = json.loads(target_path.read_text())
    libbpf = tracing_exec_impl.Libbpf()
    object_path = ROOT_DIR / target["object_path"]
    record = dict(target)
    try:
        tracing_exec_impl.run_program(
            libbpf,
            object_path,
            record,
            scanner,
            args.repeat,
            args.warmup_repeat,
        )
    except Exception as exc:
        record["status"] = "failed"
        record["error"] = str(exc)
        tracing_exec_impl.summarize_program(record)
    print(json.dumps(record, sort_keys=True))
    return 0


def run_guest_batch_mode(args: argparse.Namespace, runner: Path, scanner: Path) -> int:
    batch_path = Path(args.guest_batch_json).resolve()
    batch = json.loads(batch_path.read_text())
    targets = list(batch.get("targets") or [])
    records: list[dict[str, Any]] = []

    with tempfile.TemporaryDirectory(prefix="tracing-corpus-vm-guest-", dir="/tmp") as tmpdir:
        tmpdir_path = Path(tmpdir)
        total = len(targets)
        for index, target in enumerate(targets, start=1):
            if index == 1 or index == total or index % 25 == 0:
                print(
                    f"[guest {index}/{total}] {target['object_path']}:{target['program_name']}",
                    file=sys.stderr,
                    flush=True,
                )
            handle = tempfile.NamedTemporaryFile(
                mode="w",
                prefix="tracing-target-",
                suffix=".json",
                dir=tmpdir_path,
                delete=False,
            )
            try:
                with handle:
                    json.dump(target, handle)
                    handle.write("\n")
                target_json = Path(handle.name)
                command = [
                    sys.executable,
                    str(Path(__file__).resolve()),
                    "--guest-single-target-json",
                    str(target_json),
                    "--runner",
                    str(runner),
                    "--scanner",
                    str(scanner),
                    "--repeat",
                    str(int(args.repeat)),
                    "--warmup-repeat",
                    str(int(args.warmup_repeat)),
                    "--timeout",
                    str(int(args.timeout)),
                ]
                try:
                    completed = subprocess.run(
                        command,
                        cwd=ROOT_DIR,
                        capture_output=True,
                        text=True,
                        timeout=args.timeout + 60,
                        check=False,
                    )
                except subprocess.TimeoutExpired as exc:
                    records.append(
                        failed_target_record(
                            target,
                            error=f"subprocess timeout after {args.timeout + 60}s",
                            stdout=exc.stdout or "",
                            stderr=exc.stderr or "",
                        )
                    )
                    continue

                if completed.returncode != 0:
                    records.append(
                        failed_target_record(
                            target,
                            error=f"subprocess exit {completed.returncode}",
                            stdout=completed.stdout or "",
                            stderr=completed.stderr or "",
                        )
                    )
                    continue

                try:
                    record = parse_last_json_line(completed.stdout or "")
                except Exception as exc:
                    record = failed_target_record(
                        target,
                        error=f"failed to parse child JSON: {exc}",
                        stdout=completed.stdout or "",
                        stderr=completed.stderr or "",
                    )
                records.append(record)
            finally:
                Path(handle.name).unlink(missing_ok=True)

    summary = tracing_exec_impl.build_summary(records, [])
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "vm-guest-isolated",
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "scanner_binary": str(scanner),
        "corpus_source": batch.get("corpus_source") or "host-preflight ready target list",
        "objects_found": int(batch.get("objects_found") or 0),
        "repeat": int(args.repeat),
        "warmup_repeat": int(args.warmup_repeat),
        "inventory_failures": [],
        "summary": summary,
        "programs": records,
    }
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "tracing_corpus_vm")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    tracing_exec_impl.write_json(output_json, payload)
    tracing_exec_impl.write_text(output_md, tracing_exec_impl.build_markdown(payload) + "\n")
    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"considered={summary['programs_considered']} "
        f"attached={summary['attached_programs']} "
        f"paired={summary['paired_measurements']} "
        f"applied={summary['paired_applied_measurements']}"
    )
    return 0


def run_measurement_in_vm(
    args: argparse.Namespace,
    *,
    kernel_image: Path,
    runner: Path,
    scanner: Path,
    discovery: dict[str, Any],
) -> dict[str, Any]:
    ready_targets = [record for record in discovery["programs"] if record["status"] == "ready"]
    guest_rw_tmpdir = ROOT_DIR / "docs" / "tmp"
    guest_rw_tmpdir.mkdir(parents=True, exist_ok=True)
    batch_payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "corpus_source": discovery["corpus_source"],
        "objects_found": discovery["objects_found"],
        "targets": ready_targets,
    }

    with tempfile.TemporaryDirectory(prefix="tracing-corpus-vm-", dir=guest_rw_tmpdir) as tmpdir:
        tmpdir_path = Path(tmpdir)
        batch_json = tmpdir_path / "targets.json"
        raw_json = tmpdir_path / "raw-tracing-exec.json"
        raw_md = tmpdir_path / "raw-tracing-exec.md"
        batch_json.write_text(json.dumps(batch_payload, indent=2) + "\n")

        guest_command = [
            "python3",
            str(SELF_RELATIVE),
            "--guest-batch-json",
            str(batch_json),
            "--output-json",
            str(raw_json),
            "--output-md",
            str(raw_md),
            "--runner",
            str(runner),
            "--scanner",
            str(scanner),
            "--repeat",
            str(int(args.repeat)),
            "--warmup-repeat",
            str(int(args.warmup_repeat)),
            "--timeout",
            str(int(args.timeout)),
        ]
        guest_script = tracing_exec_impl.write_guest_script([guest_command])
        completed = tracing_exec_impl.run_in_vm(kernel_image, guest_script, args.cpus, args.mem, args.vm_timeout)
        if completed.stdout:
            sys.stdout.write(completed.stdout)
        if completed.returncode != 0:
            tail = summarize_text(completed.stderr or completed.stdout)
            raise SystemExit(f"vng run failed with exit {completed.returncode}: {tail}")
        if not raw_json.exists():
            raise SystemExit(f"tracing exec VM run did not produce JSON output: {raw_json}")
        return json.loads(raw_json.read_text())


def build_final_markdown(payload: dict[str, Any]) -> str:
    measurement = payload.get("measurement")
    discovery = payload["discovery"]
    summary = discovery["summary"]
    lines: list[str] = [
        "# Tracing Corpus VM Results",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Driver: `{payload['driver']}`",
        f"- Kernel image: `{payload['kernel_image']}`",
        f"- Target section roots: `{', '.join(payload['target_section_roots'])}`",
        f"- Discovery mode: `{payload['discovery_mode']}`",
        f"- Preview ready programs: {summary['ready_programs']}",
        f"- Preview skipped programs: {summary['skipped_programs']}",
        f"- Layout note: {payload['corpus_layout']['note']}",
        "",
        "## Preview Summary",
        "",
    ]
    lines.extend(
        tracing_exec_impl.markdown_table(
            ["Metric", "Value"],
            [
                ["Ready kprobe-family programs", summary["ready_by_family"].get("kprobe", 0)],
                ["Ready tracepoint-family programs", summary["ready_by_family"].get("tracepoint", 0)],
                ["Ready raw_tracepoint-family programs", summary["ready_by_family"].get("raw_tracepoint", 0)],
                ["Ready lsm programs", summary["ready_by_family"].get("lsm", 0)],
                ["Ready fentry programs", summary["ready_by_family"].get("fentry", 0)],
                ["Ready fexit programs", summary["ready_by_family"].get("fexit", 0)],
            ],
        )
    )
    lines.extend(["", "## Measured Comparison", ""])
    if measurement is None:
        lines.append("No measurement data was collected.")
        return "\n".join(lines) + "\n"

    embedded = tracing_exec_impl.build_markdown(measurement).splitlines()
    if embedded and embedded[0].startswith("# "):
        embedded = embedded[1:]
        if embedded and not embedded[0].strip():
            embedded = embedded[1:]
    lines.extend(embedded)
    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    require_minimum(args.repeat, 1, "--repeat")
    if args.warmup_repeat < 0:
        raise SystemExit("--warmup-repeat must be >= 0")

    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "tracing_corpus_vm")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    plan_md = Path(args.plan_md).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    runner = Path(args.runner).resolve() if args.runner else tracing_exec_impl.runner_binary_from_config()
    scanner = Path(args.scanner).resolve()

    if not runner.exists():
        raise SystemExit(f"runner binary not found: {runner}")
    if not scanner.exists():
        raise SystemExit(f"scanner binary not found: {scanner}")

    if args.guest_single_target_json:
        return run_guest_single_target_mode(args, runner, scanner)
    if args.guest_batch_json:
        return run_guest_batch_mode(args, runner, scanner)

    discovery = discover_targets(args, runner)
    payload: dict[str, Any] = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "driver": "micro/driver.py corpus tracing-vm",
        "mode": "dry-run" if args.dry_run else "vm",
        "kernel_image": str(kernel_image),
        "kernel_image_exists": kernel_image.exists(),
        "target_section_roots": list(TARGET_SECTION_ROOTS),
        "discovery_mode": "host-preflight",
        "corpus_layout": corpus_layout(),
        "discovery": discovery,
        "measurement": None,
    }

    if args.dry_run:
        markdown = build_dry_run_markdown(payload, heading="Tracing Corpus VM Dry Run")
        write_json(output_json, payload)
        write_text(output_md, markdown + "\n")
        print_dry_run_listing(payload)
        print(f"Wrote {output_json}")
        print(f"Wrote {output_md}")
        return 0

    if not kernel_image.exists():
        payload["mode"] = "plan"
        markdown = build_plan_markdown(payload)
        write_json(output_json, payload)
        write_text(output_md, markdown + "\n")
        write_text(plan_md, markdown + "\n")
        print(f"kernel image not found: {kernel_image}")
        print(f"Wrote {output_json}")
        print(f"Wrote {output_md}")
        print(f"Wrote {plan_md}")
        return 0

    payload["measurement"] = run_measurement_in_vm(
        args,
        kernel_image=kernel_image,
        runner=runner,
        scanner=scanner,
        discovery=discovery,
    )

    write_json(output_json, payload)
    write_text(output_md, build_final_markdown(payload))
    measurement_summary = (payload["measurement"] or {}).get("summary") or {}
    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        "vm-run "
        f"considered={measurement_summary.get('programs_considered', 0)} "
        f"attached={measurement_summary.get('attached_programs', 0)} "
        f"paired={measurement_summary.get('paired_measurements', 0)} "
        f"applied={measurement_summary.get('paired_applied_measurements', 0)}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
