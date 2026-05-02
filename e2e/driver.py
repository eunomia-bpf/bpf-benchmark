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
    RESULTS_DIR,
    ROOT_DIR,
)
from runner.libs.rejit import (  # noqa: E402
    DaemonSession,
    benchmark_run_provenance,
    compact_rejit_results_for_artifact,
)
from runner.libs.run_artifacts import (  # noqa: E402
    ArtifactSession,
    current_process_identity,
    derive_run_type,
)
from e2e.cases.bpftrace.case import (  # noqa: E402
    build_markdown as build_bpftrace_markdown,
    run_bpftrace_case,
)
from e2e.cases.tetragon.case import (  # noqa: E402
    build_markdown as build_tetragon_markdown,
    run_tetragon_case,
)
from e2e.cases.bcc.case import (  # noqa: E402
    build_markdown as build_bcc_markdown,
    run_bcc_case,
)
from e2e.cases.tracee.case import (  # noqa: E402
    build_markdown as build_tracee_markdown,
    run_tracee_case,
)
from e2e.cases.katran.case import (  # noqa: E402
    build_markdown as build_katran_markdown,
    run_katran_case,
)
from runner.libs.case_common import (  # noqa: E402
    prepare_daemon_session,
    wait_for_suite_quiescence,
)

DEFAULT_OUTPUT_JSON = RESULTS_DIR / "tracee.json"
DEFAULT_TETRAGON_OUTPUT_JSON = RESULTS_DIR / "tetragon.json"
DEFAULT_BPFTRACE_OUTPUT_JSON = RESULTS_DIR / "bpftrace.json"
DEFAULT_BCC_OUTPUT_JSON = RESULTS_DIR / "bcc.json"
DEFAULT_KATRAN_OUTPUT_JSON = RESULTS_DIR / "katran.json"

@dataclass(frozen=True)
class CaseSpec:
    run_case: Callable[[argparse.Namespace], dict[str, object]]
    build_markdown: Callable[[dict[str, object]], str]
    default_output_json: Path


CASE_SPECS: dict[str, CaseSpec] = {
    "tracee": CaseSpec(
        run_case=run_tracee_case,
        build_markdown=build_tracee_markdown,
        default_output_json=DEFAULT_OUTPUT_JSON,
    ),
    "tetragon": CaseSpec(
        run_case=run_tetragon_case,
        build_markdown=build_tetragon_markdown,
        default_output_json=DEFAULT_TETRAGON_OUTPUT_JSON,
    ),
    "bpftrace": CaseSpec(
        run_case=run_bpftrace_case,
        build_markdown=build_bpftrace_markdown,
        default_output_json=DEFAULT_BPFTRACE_OUTPUT_JSON,
    ),
    "bcc": CaseSpec(
        run_case=run_bcc_case,
        build_markdown=build_bcc_markdown,
        default_output_json=DEFAULT_BCC_OUTPUT_JSON,
    ),
    "katran": CaseSpec(
        run_case=run_katran_case,
        build_markdown=build_katran_markdown,
        default_output_json=DEFAULT_KATRAN_OUTPUT_JSON,
    ),
}

def _args_no_kinsn(args: argparse.Namespace) -> bool:
    return bool(getattr(args, "no_kinsn", False))


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the repository end-to-end benchmark suite driver.")
    parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "bcc", "katran", "all"))
    parser.add_argument("--duration", type=int, help="Override the per-workload duration in seconds.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--daemon", default=str(ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"))
    parser.add_argument(
        "--no-kinsn",
        action="store_true",
        help="Disable loading kinsn modules for this e2e run.",
    )
    return parser


def apply_case_defaults(args: argparse.Namespace) -> None:
    spec = CASE_SPECS.get(args.case)
    if spec is None:
        return
    if args.output_json == str(DEFAULT_OUTPUT_JSON):
        args.output_json = str(spec.default_output_json)


def resolve_primary_output_json(args: argparse.Namespace) -> Path:
    return Path(args.output_json).resolve()


ALL_CASES = ("tracee", "tetragon", "bpftrace", "bcc", "katran")
def _payload_status(payload: object) -> str:
    if not isinstance(payload, dict):
        return ""
    return str(payload.get("status", "")).lower()


def build_run_metadata(
    args: argparse.Namespace,
) -> dict[str, object]:
    metadata = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": "e2e",
        "case": args.case,
        "kinsn_enabled": not _args_no_kinsn(args),
    }
    metadata.update(benchmark_run_provenance())
    metadata.update(current_process_identity())
    return metadata


def _run_single_case(
    args: argparse.Namespace,
    *,
    prepared_daemon_session: object | None = None,
) -> dict[str, object]:
    """Run a single e2e case and persist its outputs progressively."""
    spec = CASE_SPECS[args.case]
    output_json = resolve_primary_output_json(args)
    run_type = derive_run_type(output_json, args.case)
    started_at = datetime.now(timezone.utc).isoformat()

    progress_payload: dict[str, object] = {
        "case": args.case,
        "status": "running",
        "kinsn_enabled": not _args_no_kinsn(args),
    }

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, object]:
        metadata = build_run_metadata(args)
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
    )
    session.write(status="running", progress_payload=progress_payload)
    artifact_error_written = False

    try:
        if prepared_daemon_session is not None:
            setattr(args, "_prepared_daemon_session", prepared_daemon_session)
        payload = spec.run_case(args)
        payload = compact_rejit_results_for_artifact(payload)
        detail_texts = {"result.md": spec.build_markdown(payload) + "\n"}
        raw_payload_status = payload.get("status") if isinstance(payload, dict) else None
        payload_status = _payload_status(payload)
        if payload_status not in {"ok", "error"}:
            invalid_payload_status = raw_payload_status
            payload_status = "error"
            if isinstance(payload, dict):
                payload["status"] = "error"
                payload.setdefault(
                    "error_message",
                    f"{args.case} returned an invalid status: {invalid_payload_status!r}",
                )

        completed_at = datetime.now(timezone.utc).isoformat()
        if payload_status == "ok":
            progress_payload = {
                "case": args.case,
                "status": "completed",
                "case_status": payload_status,
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
            "error_message": error_message,
            "failed_at": completed_at,
        }
        session.write(
            status="error",
            progress_payload=error_payload,
            result_payload=payload if isinstance(payload, dict) else None,
            detail_texts=detail_texts,
            error_message=error_message,
        )
        artifact_error_written = True
        raise RuntimeError(error_message)
    except Exception as exc:
        if artifact_error_written:
            raise
        failed_at = datetime.now(timezone.utc).isoformat()
        error_payload = {
            "case": args.case,
            "status": "error",
            "error_message": str(exc),
            "failed_at": failed_at,
        }
        session.write(
            status="error",
            progress_payload=error_payload,
            error_message=str(exc),
        )
        raise


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)

    if args.case == "all":
        cases_to_run = list(ALL_CASES)
        failed: list[str] = []
        daemon_binary = Path(args.daemon).resolve()
        e2e_output_json = resolve_primary_output_json(args)
        with DaemonSession.start(daemon_binary, load_kinsn=not bool(args.no_kinsn)) as daemon_session:
            prepared = prepare_daemon_session(daemon_session)
            for index, case_name in enumerate(cases_to_run):
                print(f"\n{'='*60}")
                print(f"  e2e: running {case_name}")
                print(f"{'='*60}")
                case_args = argparse.Namespace(**vars(args))
                case_args.case = case_name
                apply_case_defaults(case_args)
                try:
                    _run_single_case(case_args, prepared_daemon_session=prepared)
                    print(f"  e2e: {case_name} OK")
                except Exception as exc:
                    print(f"  e2e: {case_name} FAILED: {exc}")
                    failed.append(case_name)
                if index + 1 < len(cases_to_run):
                    wait_for_suite_quiescence()
        if failed:
            print(f"\ne2e: FAILED cases: {', '.join(failed)}")
            return 1
        print("\ne2e: ALL PASSED")
        return 0

    apply_case_defaults(args)
    daemon_binary = Path(args.daemon).resolve()
    single_output_json = resolve_primary_output_json(args)
    with DaemonSession.start(daemon_binary, load_kinsn=not bool(args.no_kinsn)) as daemon_session:
        prepared = prepare_daemon_session(daemon_session)
        _run_single_case(args, prepared_daemon_session=prepared)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
