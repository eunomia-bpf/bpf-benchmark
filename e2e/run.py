#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from datetime import datetime, timezone
from pathlib import Path

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from runner.libs import (  # noqa: E402
    ROOT_DIR,
    prepare_bpftool_environment,
)
from runner.libs.run_artifacts import (  # noqa: E402
    create_run_artifact_dir,
    derive_run_type,
    repo_relative_path,
    result_root_for_output,
    update_run_artifact,
)
from e2e.cases.bpftrace.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_BPFTRACE_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_BPFTRACE_OUTPUT_MD,
    DEFAULT_REPORT_MD as DEFAULT_BPFTRACE_REPORT_MD,
    build_markdown as build_bpftrace_markdown,
    build_report as build_bpftrace_report,
    run_case as run_bpftrace_case,
)
from e2e.cases.katran.case import (  # noqa: E402
    DEFAULT_KATRAN_OBJECT as DEFAULT_KATRAN_CASE_OBJECT,
    DEFAULT_OUTPUT_JSON as DEFAULT_KATRAN_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_KATRAN_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_KATRAN_SETUP_SCRIPT,
    build_markdown as build_katran_markdown,
    run_katran_case,
)
DEFAULT_KATRAN_POLICY_FILE = ROOT_DIR / "e2e" / "cases" / "katran" / "balancer_ingress.e2e.policy.yaml"
from e2e.cases.scx.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_SCX_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_SCX_OUTPUT_MD,
    build_markdown as build_scx_markdown,
    run_scx_case,
)
from e2e.cases.tetragon.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_TETRAGON_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_TETRAGON_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TETRAGON_SETUP_SCRIPT,
    build_markdown as build_tetragon_markdown,
    run_tetragon_case,
)
from e2e.cases.tracee.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TRACEE_SETUP_SCRIPT,
    build_markdown as build_tracee_markdown,
    run_tracee_case,
)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Unified entrypoint for repository end-to-end benchmarks.")
    parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "scx", "katran", "all"))
    parser.add_argument("--smoke", action="store_true", help="Run the smoke-sized configuration.")
    parser.add_argument("--duration", type=int, help="Override the per-workload duration in seconds.")
    parser.add_argument("--tracee-binary", help="Explicit Tracee binary path.")
    parser.add_argument("--tetragon-binary", help="Explicit Tetragon binary path.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--report-md", default=str(DEFAULT_BPFTRACE_REPORT_MD))
    parser.add_argument("--config", default=str(ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"))
    parser.add_argument("--setup-script", default=str(DEFAULT_TRACEE_SETUP_SCRIPT))
    parser.add_argument("--runner", default=str(ROOT_DIR / "runner" / "build" / "micro_exec"))
    parser.add_argument("--daemon", default=str(ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"))
    parser.add_argument("--load-timeout", type=int, default=20)
    parser.add_argument("--attach-timeout", type=int, default=20)
    parser.add_argument("--smoke-duration", type=int, default=5)
    parser.add_argument("--tracee-extra-arg", action="append", default=[])
    parser.add_argument("--script", action="append", dest="scripts")
    parser.add_argument("--skip-build", action="store_true")
    parser.add_argument("--scheduler-binary", default=str(ROOT_DIR / "corpus" / "repos" / "scx" / "target" / "release" / "scx_rusty"))
    parser.add_argument("--scheduler-object", default=str(ROOT_DIR / "corpus" / "build" / "scx" / "scx_rusty_main.bpf.o"))
    parser.add_argument("--scx-repo", default=str(ROOT_DIR / "corpus" / "repos" / "scx"))
    parser.add_argument("--katran-object", default=str(DEFAULT_KATRAN_CASE_OBJECT))
    parser.add_argument("--katran-policy", default=str(DEFAULT_KATRAN_POLICY_FILE))
    parser.add_argument("--katran-server-binary", help="Explicit Katran server binary path.")
    parser.add_argument("--katran-iface", default="katran0")
    parser.add_argument("--katran-router-peer-iface")
    parser.add_argument("--katran-packet-repeat", type=int)
    parser.add_argument("--katran-use-wrk", action="store_true")
    parser.add_argument("--katran-wrk-connections", type=int)
    parser.add_argument("--katran-wrk-threads", type=int)
    parser.add_argument("--katran-warmup-duration", type=float)
    parser.add_argument("--katran-samples", type=int)
    parser.add_argument("--katran-skip-attach", action="store_true")
    parser.add_argument("--kernel-config", default=str(ROOT_DIR / "vendor" / "linux-framework" / ".config"))
    parser.add_argument("--bpftool", default="/usr/local/sbin/bpftool", help="Explicit bpftool path for Tetragon runs.")
    parser.add_argument("--scheduler-extra-arg", action="append", default=[])
    parser.add_argument("--skip-setup", action="store_true", help=argparse.SUPPRESS)
    return parser


def apply_case_defaults(args: argparse.Namespace) -> None:
    if args.case == "katran":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_KATRAN_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_KATRAN_OUTPUT_MD)
        if args.setup_script == str(DEFAULT_TRACEE_SETUP_SCRIPT):
            args.setup_script = str(DEFAULT_KATRAN_SETUP_SCRIPT)
        return

    if args.case == "scx":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_SCX_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_SCX_OUTPUT_MD)
        return

    if args.case == "tetragon":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_TETRAGON_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_TETRAGON_OUTPUT_MD)
        if args.setup_script == str(DEFAULT_TRACEE_SETUP_SCRIPT):
            args.setup_script = str(DEFAULT_TETRAGON_SETUP_SCRIPT)
        return

    if args.case == "bpftrace":
        if args.output_json == str(DEFAULT_OUTPUT_JSON):
            args.output_json = str(DEFAULT_BPFTRACE_OUTPUT_JSON)
        if args.output_md == str(DEFAULT_OUTPUT_MD):
            args.output_md = str(DEFAULT_BPFTRACE_OUTPUT_MD)


ALL_CASES = ("tracee", "tetragon", "bpftrace", "scx", "katran")


def _is_skipped_payload(payload: object) -> bool:
    return isinstance(payload, dict) and str(payload.get("status", "")).lower() == "skipped"


def _trim_e2e_value(value: object) -> object:
    if isinstance(value, dict):
        return {key: _trim_e2e_value(inner) for key, inner in value.items()}
    if isinstance(value, list):
        return [_trim_e2e_value(item) for item in value]
    if isinstance(value, str) and len(value) > 4096:
        return value[:4096] + "\n...[truncated]"
    return value


def build_run_metadata(
    args: argparse.Namespace,
    payload: dict[str, object],
    *,
    primary_output_json: Path,
) -> dict[str, object]:
    metadata = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": "e2e",
        "case": args.case,
        "smoke": bool(args.smoke),
        "output_hint_json": repo_relative_path(primary_output_json),
        "paper_summary": _trim_e2e_value(payload),
    }
    metadata["output_hint_md"] = repo_relative_path(Path(args.output_md).resolve())
    metadata["output_hint_report_md"] = repo_relative_path(Path(args.report_md).resolve())
    return metadata


def _run_single_case(args: argparse.Namespace, *, clear_existing: bool = False) -> dict[str, object]:
    """Run a single e2e case and persist its outputs progressively."""
    output_json = Path(args.output_json).resolve()
    run_type = derive_run_type(output_json, args.case)
    started_at = datetime.now(timezone.utc).isoformat()
    artifact_dir = create_run_artifact_dir(
        results_dir=result_root_for_output(output_json),
        run_type=run_type,
        generated_at=started_at,
        clear_existing=clear_existing,
    )

    progress_payload: dict[str, object] = {
        "case": args.case,
        "status": "running",
        "smoke": bool(args.smoke),
    }
    running_metadata = build_run_metadata(args, progress_payload, primary_output_json=output_json)
    running_metadata["status"] = "running"
    running_metadata["started_at"] = started_at
    running_metadata["last_updated_at"] = started_at
    update_run_artifact(
        run_dir=artifact_dir,
        run_type=run_type,
        metadata=running_metadata,
        detail_payloads={"progress.json": progress_payload},
    )

    try:
        if args.case == "tracee":
            payload = run_tracee_case(args)
            detail_texts = {"result.md": build_tracee_markdown(payload) + "\n"}
        elif args.case == "tetragon":
            payload = run_tetragon_case(args)
            detail_texts = {"result.md": build_tetragon_markdown(payload) + "\n"}
        elif args.case == "bpftrace":
            payload = run_bpftrace_case(args)
            detail_texts = {
                "result.md": build_bpftrace_markdown(payload) + "\n",
                "report.md": build_bpftrace_report(payload) + "\n",
            }
        elif args.case == "scx":
            payload = run_scx_case(args)
            detail_texts = {"result.md": build_scx_markdown(payload) + "\n"}
        elif args.case == "katran":
            payload = run_katran_case(args)
            detail_texts = {"result.md": build_katran_markdown(payload) + "\n"}
        else:
            raise SystemExit(f"unsupported e2e case: {args.case}")

        completed_at = datetime.now(timezone.utc).isoformat()
        detail_payloads: dict[str, object] = {
            "result.json": payload,
            "progress.json": {
                "case": args.case,
                "status": "completed",
                "smoke": bool(args.smoke),
                "completed_at": completed_at,
            },
        }
        artifact_metadata = build_run_metadata(args, payload, primary_output_json=output_json)
        artifact_metadata["status"] = "completed"
        artifact_metadata["started_at"] = started_at
        artifact_metadata["last_updated_at"] = completed_at
        artifact_metadata["completed_at"] = completed_at
        update_run_artifact(
            run_dir=artifact_dir,
            run_type=run_type,
            metadata=artifact_metadata,
            detail_payloads=detail_payloads,
            detail_texts=detail_texts,
        )
    except Exception as exc:
        failed_at = datetime.now(timezone.utc).isoformat()
        error_payload = {
            "case": args.case,
            "status": "error",
            "smoke": bool(args.smoke),
            "error_message": str(exc),
            "failed_at": failed_at,
        }
        artifact_metadata = build_run_metadata(args, error_payload, primary_output_json=output_json)
        artifact_metadata["status"] = "error"
        artifact_metadata["started_at"] = started_at
        artifact_metadata["last_updated_at"] = failed_at
        artifact_metadata["error_message"] = str(exc)
        update_run_artifact(
            run_dir=artifact_dir,
            run_type=run_type,
            metadata=artifact_metadata,
            detail_payloads={"progress.json": error_payload},
        )
        raise

    print(f"  e2e: wrote {artifact_dir / 'metadata.json'}")
    return payload


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    prepare_bpftool_environment()

    if args.case == "all":
        # Run all cases sequentially, each with its own default outputs.
        failed: list[str] = []
        for case_name in ALL_CASES:
            print(f"\n{'='*60}")
            print(f"  e2e: running {case_name}")
            print(f"{'='*60}")
            # Build a fresh args copy with case-specific defaults.
            case_argv = [case_name] + [
                a for a in (argv or sys.argv[1:]) if a != "all"
            ]
            case_args = parser.parse_args(case_argv)
            apply_case_defaults(case_args)
            try:
                payload = _run_single_case(case_args)
                if _is_skipped_payload(payload):
                    print(f"  e2e: {case_name} SKIP")
                else:
                    print(f"  e2e: {case_name} OK")
            except Exception as exc:
                print(f"  e2e: {case_name} FAILED: {exc}")
                failed.append(case_name)
        if failed:
            print(f"\ne2e: FAILED cases: {', '.join(failed)}")
            return 1
        print("\ne2e: ALL PASSED")
        return 0

    apply_case_defaults(args)
    _run_single_case(args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
