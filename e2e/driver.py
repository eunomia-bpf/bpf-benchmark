#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
import tempfile
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable

import yaml

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from runner.libs import (  # noqa: E402
    ROOT_DIR,
    smoke_output_path,
    write_json,
    write_text,
)
from runner.libs.app_suite_schema import AppSpec, load_app_suite_from_yaml  # noqa: E402
from runner.libs.rejit import DaemonSession, benchmark_rejit_enabled_passes, collect_effective_enabled_passes  # noqa: E402
from runner.libs.run_artifacts import (  # noqa: E402
    ArtifactSession,
    current_process_identity,
    derive_run_type,
)
from e2e.cases.bpftrace.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_BPFTRACE_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_BPFTRACE_OUTPUT_MD,
    DEFAULT_REPORT_MD as DEFAULT_BPFTRACE_REPORT_MD,
    build_markdown as build_bpftrace_markdown,
    build_report as build_bpftrace_report,
    run_bpftrace_case,
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
    build_markdown as build_tetragon_markdown,
    run_tetragon_case,
)
from e2e.cases.bcc.case import (  # noqa: E402
    DEFAULT_CONFIG as DEFAULT_BCC_CONFIG,
    DEFAULT_OUTPUT_JSON as DEFAULT_BCC_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_BCC_OUTPUT_MD,
    DEFAULT_REPORT_MD as DEFAULT_BCC_REPORT_MD,
    build_markdown as build_bcc_markdown,
    build_report as build_bcc_report,
    run_bcc_case,
)
from e2e.cases.tracee.case import (  # noqa: E402
    DEFAULT_CONFIG as DEFAULT_TRACEE_CONFIG,
    DEFAULT_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD,
    build_markdown as build_tracee_markdown,
    run_tracee_case,
)
from e2e.cases.katran.case import (  # noqa: E402
    DEFAULT_OUTPUT_JSON as DEFAULT_KATRAN_OUTPUT_JSON,
    DEFAULT_OUTPUT_MD as DEFAULT_KATRAN_OUTPUT_MD,
    build_markdown as build_katran_markdown,
    run_katran_case,
)
from runner.libs.case_common import (  # noqa: E402
    attach_pending_result_metadata,
    prepare_daemon_session,
    reset_pending_result_metadata,
    wait_for_suite_quiescence,
)

DEFAULT_SUITE = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
SUITE_RUNNER_TO_CASE = {
    "bcc": "bcc",
    "bpftrace": "bpftrace",
    "katran": "katran",
    "scx": "scx",
    "tetragon": "tetragon",
    "tracee": "tracee",
}

@dataclass(frozen=True)
class CaseSpec:
    run_case: Callable[[argparse.Namespace], dict[str, object]]
    build_markdown: Callable[[dict[str, object]], str]
    default_output_json: Path
    default_output_md: Path
    build_report: Callable[[dict[str, object]], str] | None = None
    default_report_md: Path | None = None
    default_config: Path | None = None


CASE_SPECS: dict[str, CaseSpec] = {
    "tracee": CaseSpec(
        run_case=run_tracee_case,
        build_markdown=build_tracee_markdown,
        default_output_json=DEFAULT_OUTPUT_JSON,
        default_output_md=DEFAULT_OUTPUT_MD,
        default_config=DEFAULT_TRACEE_CONFIG,
    ),
    "tetragon": CaseSpec(
        run_case=run_tetragon_case,
        build_markdown=build_tetragon_markdown,
        default_output_json=DEFAULT_TETRAGON_OUTPUT_JSON,
        default_output_md=DEFAULT_TETRAGON_OUTPUT_MD,
        default_config=DEFAULT_TETRAGON_CONFIG,
    ),
    "bpftrace": CaseSpec(
        run_case=run_bpftrace_case,
        build_markdown=build_bpftrace_markdown,
        build_report=build_bpftrace_report,
        default_output_json=DEFAULT_BPFTRACE_OUTPUT_JSON,
        default_output_md=DEFAULT_BPFTRACE_OUTPUT_MD,
        default_report_md=DEFAULT_BPFTRACE_REPORT_MD,
    ),
    "scx": CaseSpec(
        run_case=run_scx_case,
        build_markdown=build_scx_markdown,
        default_output_json=DEFAULT_SCX_OUTPUT_JSON,
        default_output_md=DEFAULT_SCX_OUTPUT_MD,
    ),
    "bcc": CaseSpec(
        run_case=run_bcc_case,
        build_markdown=build_bcc_markdown,
        build_report=build_bcc_report,
        default_output_json=DEFAULT_BCC_OUTPUT_JSON,
        default_output_md=DEFAULT_BCC_OUTPUT_MD,
        default_report_md=DEFAULT_BCC_REPORT_MD,
        default_config=DEFAULT_BCC_CONFIG,
    ),
    "katran": CaseSpec(
        run_case=run_katran_case,
        build_markdown=build_katran_markdown,
        default_output_json=DEFAULT_KATRAN_OUTPUT_JSON,
        default_output_md=DEFAULT_KATRAN_OUTPUT_MD,
    ),
}


def _normalize_default_pathlike(value: object) -> str:
    text = str(value or "").strip()
    if not text:
        return ""
    return str(Path(text).resolve())


def _known_case_default_values(attribute: str) -> set[str]:
    values: set[str] = set()
    for spec in CASE_SPECS.values():
        value: object | None = None
        if attribute == "report_md":
            value = spec.default_report_md
        elif attribute == "config":
            value = spec.default_config
        if value is None:
            continue
        normalized = _normalize_default_pathlike(value)
        if normalized:
            values.add(normalized)
    return values


def _uses_known_case_default(args: argparse.Namespace, attribute: str) -> bool:
    if not hasattr(args, attribute):
        return True
    current_value = _normalize_default_pathlike(getattr(args, attribute))
    if not current_value:
        return True
    return current_value in _known_case_default_values(attribute)


def _args_no_kinsn(args: argparse.Namespace) -> bool:
    return bool(getattr(args, "no_kinsn", False))


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the repository end-to-end benchmark suite driver.")
    parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "scx", "bcc", "katran", "all"))
    parser.add_argument("--suite", default=str(DEFAULT_SUITE))
    parser.add_argument("--smoke", action="store_true", help="Run the smoke-sized configuration.")
    parser.add_argument("--duration", type=int, help="Override the per-workload duration in seconds.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--daemon", default=str(ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"))
    parser.add_argument(
        "--rejit-passes",
        default=None,
        help="Comma-separated ReJIT passes to enable for e2e apply. Pass an empty string to run zero passes.",
    )
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
    if args.output_md == str(DEFAULT_OUTPUT_MD):
        args.output_md = str(spec.default_output_md)
    if spec.default_report_md is not None and _uses_known_case_default(args, "report_md"):
        args.report_md = str(spec.default_report_md)
    if spec.default_config is not None and _uses_known_case_default(args, "config"):
        args.config = str(spec.default_config)


def resolve_primary_output_json(args: argparse.Namespace, spec: CaseSpec) -> Path:
    output_json = Path(args.output_json).resolve()
    default_output_json = spec.default_output_json.resolve()
    if bool(args.smoke) and output_json == default_output_json:
        return smoke_output_path(default_output_json.parent, args.case).resolve()
    return output_json


ALL_CASES = ("tracee", "tetragon", "bpftrace", "scx", "bcc", "katran")


def _leaf_name(name: str) -> str:
    text = str(name or "").strip()
    if not text:
        return ""
    return text.rsplit("/", 1)[-1]


def _write_suite_temp_yaml(prefix: str, payload: object) -> Path:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        suffix=".yaml",
        prefix=prefix,
        delete=False,
        encoding="utf-8",
    )
    try:
        yaml.safe_dump(payload, handle, sort_keys=False)
    finally:
        handle.close()
    return Path(handle.name)


def _append_suite_temp_path(args: argparse.Namespace, path: Path) -> None:
    temp_paths = getattr(args, "_suite_temp_paths", None)
    if not isinstance(temp_paths, list):
        temp_paths = []
        setattr(args, "_suite_temp_paths", temp_paths)
    temp_paths.append(str(path))


def _cleanup_suite_temp_paths(args: argparse.Namespace) -> None:
    for raw_path in getattr(args, "_suite_temp_paths", []) or []:
        try:
            Path(raw_path).unlink(missing_ok=True)
        except OSError:
            continue


def _load_suite_case_apps(suite_path: Path) -> dict[str, list[AppSpec]]:
    suite, _summary = load_app_suite_from_yaml(suite_path)
    grouped: dict[str, list[AppSpec]] = {case_name: [] for case_name in ALL_CASES}
    for app in suite.apps:
        case_name = SUITE_RUNNER_TO_CASE.get(app.runner)
        if case_name is None:
            continue
        grouped.setdefault(case_name, []).append(app)
    return grouped


def _named_suite_apps(
    suite_apps: list[AppSpec],
    *,
    key: str,
) -> dict[str, AppSpec]:
    named: dict[str, AppSpec] = {}
    for app in suite_apps:
        if key == "tool":
            name = str(app.args.get("tool") or _leaf_name(app.name))
        elif key == "script":
            name = str(app.args.get("script") or _leaf_name(app.name))
        elif key == "scheduler":
            name = str(app.args.get("scheduler") or _leaf_name(app.name))
        else:
            name = _leaf_name(app.name)
        normalized = name.strip()
        if not normalized:
            raise RuntimeError(f"suite app {app.name!r} is missing a selectable {key}")
        named[normalized] = app
    return named


def _configure_tracee_case_from_suite(args: argparse.Namespace, suite_apps: list[AppSpec]) -> None:
    if not suite_apps:
        return
    payload = yaml.safe_load(Path(args.config).resolve().read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid Tracee config payload: {args.config}")
    wanted = [app.workload_for("e2e") for app in suite_apps]
    raw_workloads = payload.get("workloads")
    if not isinstance(raw_workloads, list):
        raise RuntimeError(f"invalid Tracee workloads in config: {args.config}")
    filtered = [
        dict(entry)
        for entry in raw_workloads
        if isinstance(entry, dict)
        and str(entry.get("name") or entry.get("kind") or "").strip() in wanted
    ]
    found = {str(entry.get("name") or entry.get("kind") or "").strip() for entry in filtered}
    missing = [name for name in wanted if name not in found]
    if missing:
        raise RuntimeError("Tracee suite workloads are missing from config: " + ", ".join(missing))
    payload["workloads"] = filtered
    temp_path = _write_suite_temp_yaml("tracee-suite-", payload)
    args.config = str(temp_path)
    _append_suite_temp_path(args, temp_path)


def _configure_tetragon_case_from_suite(args: argparse.Namespace, suite_apps: list[AppSpec]) -> None:
    if not suite_apps:
        return
    payload = yaml.safe_load(Path(args.config).resolve().read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid Tetragon config payload: {args.config}")
    wanted = [app.workload_for("e2e") for app in suite_apps]
    raw_workloads = payload.get("workloads")
    if not isinstance(raw_workloads, list):
        raise RuntimeError(f"invalid Tetragon workloads in config: {args.config}")
    filtered = [
        dict(entry)
        for entry in raw_workloads
        if isinstance(entry, dict)
        and str(entry.get("name") or entry.get("kind") or "").strip() in wanted
    ]
    found = {str(entry.get("name") or entry.get("kind") or "").strip() for entry in filtered}
    missing = [name for name in wanted if name not in found]
    if missing:
        raise RuntimeError("Tetragon suite workloads are missing from config: " + ", ".join(missing))
    payload["workloads"] = filtered
    temp_path = _write_suite_temp_yaml("tetragon-suite-", payload)
    args.config = str(temp_path)
    _append_suite_temp_path(args, temp_path)


def _configure_bcc_case_from_suite(args: argparse.Namespace, suite_apps: list[AppSpec]) -> None:
    if not suite_apps:
        return
    named = _named_suite_apps(suite_apps, key="tool")
    explicit = [name.strip() for name in (getattr(args, "tools", None) or []) if str(name).strip()]
    selected_names = explicit or list(named)
    missing = [name for name in selected_names if name not in named]
    if missing:
        raise RuntimeError("requested BCC tools are not enabled in suite: " + ", ".join(missing))
    payload = yaml.safe_load(Path(args.config).resolve().read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid BCC config payload: {args.config}")
    raw_tools = payload.get("tools")
    if not isinstance(raw_tools, list):
        raise RuntimeError(f"invalid BCC tools in config: {args.config}")
    filtered: list[dict[str, object]] = []
    for entry in raw_tools:
        if not isinstance(entry, dict):
            continue
        name = str(entry.get("name") or "").strip()
        app = named.get(name)
        if app is None or name not in selected_names:
            continue
        updated = dict(entry)
        updated["workload_kind"] = app.workload_for("e2e")
        filtered.append(updated)
    found = {str(entry.get("name") or "").strip() for entry in filtered}
    missing = [name for name in selected_names if name not in found]
    if missing:
        raise RuntimeError("suite-selected BCC tools are missing from config: " + ", ".join(missing))
    payload["tools"] = filtered
    temp_path = _write_suite_temp_yaml("bcc-suite-", payload)
    args.config = str(temp_path)
    args.tools = list(selected_names)
    _append_suite_temp_path(args, temp_path)


def _configure_bpftrace_case_from_suite(args: argparse.Namespace, suite_apps: list[AppSpec]) -> None:
    if not suite_apps:
        return
    named = _named_suite_apps(suite_apps, key="script")
    explicit = [name.strip() for name in (getattr(args, "scripts", None) or []) if str(name).strip()]
    selected_names = explicit or list(named)
    missing = [name for name in selected_names if name not in named]
    if missing:
        raise RuntimeError("requested bpftrace scripts are not enabled in suite: " + ", ".join(missing))
    args.scripts = list(selected_names)
    args._suite_workload_overrides = {
        name: named[name].workload_for("e2e")
        for name in selected_names
    }


def _configure_scx_case_from_suite(args: argparse.Namespace, suite_apps: list[AppSpec]) -> None:
    if not suite_apps:
        return
    named = _named_suite_apps(suite_apps, key="scheduler")
    args.workloads = [app.workload_for("e2e") for app in named.values()]


def _configure_katran_case_from_suite(args: argparse.Namespace, suite_apps: list[AppSpec]) -> None:
    if not suite_apps:
        return
    if len(suite_apps) > 1:
        raise RuntimeError("katran suite currently supports a single loader instance")
    args.workload = suite_apps[0].workload_for("e2e")


def apply_suite_case_config(args: argparse.Namespace, suite_case_apps: dict[str, list[AppSpec]]) -> None:
    apps = list(suite_case_apps.get(args.case, []))
    if not apps:
        return
    if args.case == "tracee":
        _configure_tracee_case_from_suite(args, apps)
        return
    if args.case == "tetragon":
        _configure_tetragon_case_from_suite(args, apps)
        return
    if args.case == "bcc":
        _configure_bcc_case_from_suite(args, apps)
        return
    if args.case == "bpftrace":
        _configure_bpftrace_case_from_suite(args, apps)
        return
    if args.case == "scx":
        _configure_scx_case_from_suite(args, apps)
        return
    if args.case == "katran":
        _configure_katran_case_from_suite(args, apps)


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
) -> dict[str, object]:
    requested_rejit_passes = benchmark_rejit_enabled_passes()
    selected_rejit_passes = collect_effective_enabled_passes(payload)
    if not selected_rejit_passes:
        selected_rejit_passes = list(requested_rejit_passes)
    if isinstance(payload, dict):
        payload_selected_passes = payload.get("selected_rejit_passes")
        if not selected_rejit_passes and isinstance(payload_selected_passes, list):
            selected_rejit_passes = [str(pass_name) for pass_name in payload_selected_passes]
    metadata = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": "e2e",
        "case": args.case,
        "smoke": bool(args.smoke),
        "kinsn_enabled": not _args_no_kinsn(args),
        "selected_rejit_passes": selected_rejit_passes,
        "optimization_summary": _trim_e2e_value(payload),
    }
    if selected_rejit_passes != requested_rejit_passes:
        metadata["requested_rejit_passes"] = list(requested_rejit_passes)
    metadata.update(current_process_identity())
    return metadata


def _run_single_case(
    args: argparse.Namespace,
    *,
    prepared_daemon_session: object | None = None,
) -> dict[str, object]:
    """Run a single e2e case and persist its outputs progressively."""
    spec = CASE_SPECS[args.case]
    output_json = resolve_primary_output_json(args, spec)
    report_md_raw = getattr(args, "report_md", None)
    report_md = Path(report_md_raw).resolve() if report_md_raw else None
    run_type = derive_run_type(output_json, args.case)
    started_at = datetime.now(timezone.utc).isoformat()

    progress_payload: dict[str, object] = {
        "case": args.case,
        "status": "running",
        "smoke": bool(args.smoke),
        "kinsn_enabled": not _args_no_kinsn(args),
    }
    metadata_payload: dict[str, object] = progress_payload

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, object]:
        metadata = build_run_metadata(args, metadata_payload)
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
    artifact_dir = session.run_dir
    artifact_result_json = artifact_dir / "result.json"
    artifact_result_md = artifact_dir / "result.md"
    artifact_report_md = None if report_md is None else artifact_dir / "report.md"
    session.write(status="running", progress_payload=progress_payload)
    reset_pending_result_metadata()
    artifact_error_written = False

    try:
        if prepared_daemon_session is not None:
            setattr(args, "_prepared_daemon_session", prepared_daemon_session)
        payload = spec.run_case(args)
        attach_pending_result_metadata(payload)
        detail_texts = {"result.md": spec.build_markdown(payload) + "\n"}
        if spec.build_report is not None:
            if report_md is None:
                raise RuntimeError(f"{args.case} requires a report output path")
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
        write_json(artifact_result_json, payload)
        write_text(artifact_result_md, detail_texts["result.md"])
        if "report.md" in detail_texts and report_md is not None:
            if artifact_report_md is None:
                raise RuntimeError(f"{args.case} requires an artifact report path")
            write_text(artifact_report_md, detail_texts["report.md"])
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
        artifact_error_written = True
        raise RuntimeError(error_message)
    except Exception as exc:
        if artifact_error_written:
            raise
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
        _cleanup_suite_temp_paths(args)


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    suite_case_apps = _load_suite_case_apps(Path(args.suite).resolve())

    if args.case == "all":
        cases_to_run = [case_name for case_name in ALL_CASES if suite_case_apps.get(case_name)]
        if not cases_to_run:
            raise RuntimeError(f"shared suite selected zero e2e cases: {args.suite}")
        failed: list[str] = []
        daemon_binary = Path(args.daemon).resolve()
        with DaemonSession.start(daemon_binary, load_kinsn=not bool(args.no_kinsn)) as daemon_session:
            prepared = prepare_daemon_session(daemon_session, daemon_binary=daemon_binary)
            for index, case_name in enumerate(cases_to_run):
                print(f"\n{'='*60}")
                print(f"  e2e: running {case_name}")
                print(f"{'='*60}")
                case_argv = [case_name] + [
                    a for a in (argv or sys.argv[1:]) if a != "all"
                ]
                case_args = parser.parse_args(case_argv)
                apply_case_defaults(case_args)
                apply_suite_case_config(case_args, suite_case_apps)
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
    apply_suite_case_config(args, suite_case_apps)
    daemon_binary = Path(args.daemon).resolve()
    with DaemonSession.start(daemon_binary, load_kinsn=not bool(args.no_kinsn)) as daemon_session:
        prepared = prepare_daemon_session(daemon_session, daemon_binary=daemon_binary)
        _run_single_case(args, prepared_daemon_session=prepared)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
