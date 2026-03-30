#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from runner.libs import (  # noqa: E402
    ROOT_DIR,
    prepare_bpftool_environment,
    smoke_output_path,
    write_json,
    write_text,
)
from runner.libs.rejit import benchmark_rejit_enabled_passes  # noqa: E402
from runner.libs.run_artifacts import (  # noqa: E402
    ArtifactSession,
    derive_run_type,
    repo_relative_path,
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
from e2e.cases.scx.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_SCX_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_SCX_OUTPUT_MD,
    build_markdown as build_scx_markdown,
    run_scx_case,
)
from e2e.cases.tetragon.case import (  # noqa: E402
    DEFAULT_CONFIG as DEFAULT_TETRAGON_CONFIG,
    DEFAULT_OUTPUT_JSON as DEFAULT_TETRAGON_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_TETRAGON_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TETRAGON_SETUP_SCRIPT,
    build_markdown as build_tetragon_markdown,
    run_tetragon_case,
)
from e2e.cases.bcc.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_BCC_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_BCC_OUTPUT_MD,
    DEFAULT_REPORT_MD as DEFAULT_BCC_REPORT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_BCC_SETUP_SCRIPT,
    build_markdown as build_bcc_markdown,
    build_report as build_bcc_report,
    run_bcc_case,
)
from e2e.cases.tracee.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TRACEE_SETUP_SCRIPT,
    build_markdown as build_tracee_markdown,
    run_tracee_case,
)
from runner.libs.case_common import (  # noqa: E402
    attach_pending_result_metadata,
    reset_pending_result_metadata,
)

@dataclass(frozen=True)
class CaseSpec:
    run_case: Callable[[argparse.Namespace], dict[str, object]]
    build_markdown: Callable[[dict[str, object]], str]
    default_output_json: Path
    default_output_md: Path
    default_setup_script: str | None = None
    build_report: Callable[[dict[str, object]], str] | None = None


CASE_SPECS: dict[str, CaseSpec] = {
    "tracee": CaseSpec(
        run_case=run_tracee_case,
        build_markdown=build_tracee_markdown,
        default_output_json=DEFAULT_OUTPUT_JSON,
        default_output_md=DEFAULT_OUTPUT_MD,
        default_setup_script=str(DEFAULT_TRACEE_SETUP_SCRIPT),
    ),
    "tetragon": CaseSpec(
        run_case=run_tetragon_case,
        build_markdown=build_tetragon_markdown,
        default_output_json=DEFAULT_TETRAGON_OUTPUT_JSON,
        default_output_md=DEFAULT_TETRAGON_OUTPUT_MD,
        default_setup_script=str(DEFAULT_TETRAGON_SETUP_SCRIPT),
    ),
    "bpftrace": CaseSpec(
        run_case=run_bpftrace_case,
        build_markdown=build_bpftrace_markdown,
        build_report=build_bpftrace_report,
        default_output_json=DEFAULT_BPFTRACE_OUTPUT_JSON,
        default_output_md=DEFAULT_BPFTRACE_OUTPUT_MD,
    ),
    "scx": CaseSpec(
        run_case=run_scx_case,
        build_markdown=build_scx_markdown,
        default_output_json=DEFAULT_SCX_OUTPUT_JSON,
        default_output_md=DEFAULT_SCX_OUTPUT_MD,
    ),
    "katran": CaseSpec(
        run_case=run_katran_case,
        build_markdown=build_katran_markdown,
        default_output_json=DEFAULT_KATRAN_OUTPUT_JSON,
        default_output_md=DEFAULT_KATRAN_OUTPUT_MD,
        default_setup_script=str(DEFAULT_KATRAN_SETUP_SCRIPT),
    ),
    "bcc": CaseSpec(
        run_case=run_bcc_case,
        build_markdown=build_bcc_markdown,
        build_report=build_bcc_report,
        default_output_json=DEFAULT_BCC_OUTPUT_JSON,
        default_output_md=DEFAULT_BCC_OUTPUT_MD,
        default_setup_script=str(DEFAULT_BCC_SETUP_SCRIPT),
    ),
}


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Unified entrypoint for repository end-to-end benchmarks.")
    parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "scx", "katran", "bcc", "all"))
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
    parser.add_argument("--scheduler-binary", default=str(ROOT_DIR / "runner" / "repos" / "scx" / "target" / "release" / "scx_rusty"))
    parser.add_argument("--scheduler-object", default=str(ROOT_DIR / "corpus" / "build" / "scx" / "scx_rusty_main.bpf.o"))
    parser.add_argument("--scx-repo", default=str(ROOT_DIR / "runner" / "repos" / "scx"))
    parser.add_argument("--katran-object", default=str(DEFAULT_KATRAN_CASE_OBJECT))
    parser.add_argument("--katran-iface", default="katran0")
    parser.add_argument("--katran-router-peer-iface")
    parser.add_argument("--katran-packet-repeat", type=int)
    parser.add_argument("--katran-use-wrk", action="store_true")
    parser.add_argument("--katran-wrk-connections", type=int)
    parser.add_argument("--katran-wrk-threads", type=int)
    parser.add_argument("--katran-warmup-duration", type=float)
    parser.add_argument("--katran-samples", type=int)
    parser.add_argument("--kernel-config", default=str(ROOT_DIR / "vendor" / "linux-framework" / ".config"))
    parser.add_argument("--bpftool", default="/usr/local/sbin/bpftool", help="Explicit bpftool path for Tetragon runs.")
    parser.add_argument("--scheduler-extra-arg", action="append", default=[])
    parser.add_argument("--tools-dir", default="", help="Directory with compiled libbpf-tools binaries (bcc case).")
    parser.add_argument("--tool", action="append", dest="tools", help="Select specific libbpf-tools by name (bcc case).")
    parser.add_argument(
        "--rejit-passes",
        default=None,
        help="Comma-separated ReJIT passes to enable for e2e apply. Pass an empty string to run zero passes.",
    )
    return parser


def apply_case_defaults(args: argparse.Namespace) -> None:
    spec = CASE_SPECS.get(args.case)
    if spec is None:
        return
    if args.output_json == str(DEFAULT_OUTPUT_JSON):
        args.output_json = str(spec.default_output_json)
    if args.output_md == str(DEFAULT_OUTPUT_MD):
        args.output_md = str(spec.default_output_md)
    if spec.default_setup_script is not None and args.setup_script == str(DEFAULT_TRACEE_SETUP_SCRIPT):
        args.setup_script = spec.default_setup_script
    # BCC case: fix report_md and config defaults
    if args.case == "bcc":
        if args.report_md == str(DEFAULT_BPFTRACE_REPORT_MD):
            args.report_md = str(DEFAULT_BCC_REPORT_MD)
        if args.config == str(ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"):
            args.config = str(ROOT_DIR / "e2e" / "cases" / "bcc" / "config.yaml")
    if args.case == "tetragon":
        if args.config == str(ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"):
            args.config = str(DEFAULT_TETRAGON_CONFIG)


def resolve_primary_output_json(args: argparse.Namespace, spec: CaseSpec) -> Path:
    output_json = Path(args.output_json).resolve()
    default_output_json = spec.default_output_json.resolve()
    if bool(args.smoke) and output_json == default_output_json:
        return smoke_output_path(default_output_json.parent, args.case).resolve()
    return output_json


ALL_CASES = ("tracee", "tetragon", "bpftrace", "scx", "katran", "bcc")


def _restore_environment(saved_env: dict[str, str]) -> None:
    for key in list(os.environ.keys()):
        if key not in saved_env:
            del os.environ[key]
    os.environ.update(saved_env)


def _payload_status(payload: object) -> str:
    if not isinstance(payload, dict):
        return ""
    return str(payload.get("status", "")).lower()


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
        "selected_rejit_passes": benchmark_rejit_enabled_passes(),
        "output_hint_json": repo_relative_path(primary_output_json),
        "optimization_summary": _trim_e2e_value(payload),
    }
    metadata["output_hint_md"] = repo_relative_path(Path(args.output_md).resolve())
    metadata["output_hint_report_md"] = repo_relative_path(Path(args.report_md).resolve())
    return metadata


def _run_single_case(args: argparse.Namespace, *, clear_existing: bool = False) -> dict[str, object]:
    """Run a single e2e case and persist its outputs progressively."""
    spec = CASE_SPECS[args.case]
    output_json = resolve_primary_output_json(args, spec)
    output_md = Path(args.output_md).resolve()
    report_md = Path(args.report_md).resolve()
    run_type = derive_run_type(output_json, args.case)
    started_at = datetime.now(timezone.utc).isoformat()

    progress_payload: dict[str, object] = {
        "case": args.case,
        "status": "running",
        "smoke": bool(args.smoke),
    }
    metadata_payload: dict[str, object] = progress_payload

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, object]:
        metadata = build_run_metadata(args, metadata_payload, primary_output_json=output_json)
        metadata["status"] = status
        metadata["started_at"] = session_started_at
        metadata["last_updated_at"] = updated_at
        if error_message:
            metadata["error_message"] = error_message
        return metadata

    session = ArtifactSession(
        output_path=output_json,
        run_type=run_type,
        generated_at=started_at,
        metadata_builder=build_artifact_metadata,
        clear_existing=clear_existing,
    )
    artifact_dir = session.run_dir
    session.write(status="running", progress_payload=progress_payload)
    saved_env = os.environ.copy()
    reset_pending_result_metadata()

    try:
        payload = spec.run_case(args)
        attach_pending_result_metadata(payload)
        detail_texts = {"result.md": spec.build_markdown(payload) + "\n"}
        if spec.build_report is not None:
            detail_texts["report.md"] = spec.build_report(payload) + "\n"
        payload_status = _payload_status(payload)
        if payload_status not in {"ok", "error"}:
            payload_status = "error"
            if isinstance(payload, dict):
                payload.setdefault("status", "error")
                payload.setdefault(
                    "error_message",
                    f"{args.case} returned an invalid status: {payload.get('status')!r}",
                )

        completed_at = datetime.now(timezone.utc).isoformat()
        metadata_payload = payload
        write_json(output_json, payload)
        write_text(output_md, detail_texts["result.md"])
        if "report.md" in detail_texts:
            write_text(report_md, detail_texts["report.md"])
        if payload_status == "ok":
            progress_payload = {
                "case": args.case,
                "status": "completed",
                "case_status": payload_status,
                "smoke": bool(args.smoke),
                "completed_at": completed_at,
            }
            session.write(
                status="completed",
                progress_payload=progress_payload,
                result_payload=payload,
                detail_texts=detail_texts,
            )
            return payload

        error_message = (
            str(payload.get("error_message") or "").strip()
            if isinstance(payload, dict)
            else ""
        ) or f"{args.case} returned status={payload_status or 'missing'}"
        error_payload = {
            "case": args.case,
            "status": "error",
            "case_status": payload_status or "missing",
            "smoke": bool(args.smoke),
            "error_message": error_message,
            "failed_at": completed_at,
        }
        attach_pending_result_metadata(error_payload)
        metadata_payload = payload if isinstance(payload, dict) else error_payload
        session.write(
            status="error",
            progress_payload=error_payload,
            result_payload=payload if isinstance(payload, dict) else None,
            detail_texts=detail_texts,
            error_message=error_message,
        )
        raise RuntimeError(error_message)
    except Exception as exc:
        failed_at = datetime.now(timezone.utc).isoformat()
        error_payload = {
            "case": args.case,
            "status": "error",
            "smoke": bool(args.smoke),
            "error_message": str(exc),
            "failed_at": failed_at,
        }
        attach_pending_result_metadata(error_payload)
        metadata_payload = error_payload
        session.write(
            status="error",
            progress_payload=error_payload,
            error_message=str(exc),
        )
        raise
    finally:
        _restore_environment(saved_env)

    print(f"  e2e: wrote {artifact_dir / 'metadata.json'}")
    return payload


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    prepare_bpftool_environment()
    if args.rejit_passes is not None:
        os.environ["BPFREJIT_BENCH_PASSES"] = str(args.rejit_passes).strip()

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
                _run_single_case(case_args)
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
