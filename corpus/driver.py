#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import signal
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs import ROOT_DIR
from runner.libs.benchmark_catalog import (
    DEFAULT_CORPUS_SAMPLES,
    DEFAULT_CORPUS_WORKLOAD_DURATION_S,
)
from runner.libs.app_runners import get_app_runner
from runner.libs.app_runners.base import AppRunner
from runner.libs.app_suite_schema import AppSpec, AppSuite, load_app_suite_from_yaml
from runner.libs.bpf_stats import enable_bpf_stats
from runner.libs.case_common import (
    CaseLifecycleState,
    LifecycleRunResult,
    prepare_daemon_session,
    wait_for_suite_quiescence,
)
from runner.libs.kinsn import prepare_kinsn_modules
from runner.libs.rejit import (
    DaemonSession,
    benchmark_rejit_enabled_passes,
    benchmark_run_provenance,
)
from runner.libs.run_artifacts import (
    ArtifactSession,
    current_process_identity,
    derive_run_type,
)
from runner.libs.workspace_layout import inside_runtime_image
from runner.suites._common import (
    base_suite_runtime_env,
    csv_tokens,
    ensure_bpf_stats_enabled,
    ensure_katran_artifacts,
    env_with_suite_runtime_ld,
    resolve_daemon_binary,
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    suite_main_setup,
)


DEFAULT_MACRO_APPS_YAML = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
_CORPUS_APPS_ENV = "BPFREJIT_CORPUS_APPS"


def _filter_suite_apps(suite: AppSuite) -> AppSuite:
    """Filter suite apps by BPFREJIT_CORPUS_APPS env var (CSV of app names).

    If the env var is unset or empty, all apps are run.
    If set, only apps whose name matches one of the CSV tokens are run.
    Exits 1 if the filter references an app not present in the manifest.
    """
    raw = os.environ.get(_CORPUS_APPS_ENV, "").strip()
    if not raw:
        return suite
    requested = [token.strip() for token in raw.split(",") if token.strip()]
    if not requested:
        return suite
    manifest_names = {app.name for app in suite.apps}
    unknown = [name for name in requested if name not in manifest_names]
    if unknown:
        raise SystemExit(
            f"{_CORPUS_APPS_ENV} references unknown apps: {unknown!r}; "
            f"available: {sorted(manifest_names)!r}"
        )
    from dataclasses import replace as _dc_replace
    requested_set = set(requested)
    filtered = _dc_replace(suite, apps=tuple(app for app in suite.apps if app.name in requested_set))
    return filtered


def _env_str(name: str, default: str = "") -> str:
    return os.environ.get(name, "").strip() or default


def _env_bool(name: str) -> bool:
    return _env_str(name).lower() in ("1", "true", "yes", "on")


def _keep_workdirs_enabled() -> bool:
    raw = _env_str("KEEP_WORKDIRS").lower()
    if raw in ("", "0"):
        return False
    if raw in ("1", "all"):
        return True
    raise SystemExit("KEEP_WORKDIRS must be empty, 0, 1, or all")


def _env_int(name: str, default: int) -> int:
    raw = _env_str(name)
    return default if not raw else int(raw)


def _env_float(name: str, default: float) -> float:
    raw = _env_str(name)
    return default if not raw else float(raw)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Build the driver Namespace entirely from Make-provided env vars."""
    del argv
    target_name = _env_str("RUN_TARGET_NAME", _env_str("TARGET", "x86-kvm"))
    target_arch = _env_str("RUN_TARGET_ARCH")
    executor = _env_str("RUN_EXECUTOR")
    run_token = _env_str("RUN_TOKEN")
    python_bin = _env_str("RUN_REMOTE_PYTHON_BIN")
    bpftool_bin = _env_str("RUN_BPFTOOL_BIN")
    native_repos = [
        token.strip()
        for token in _env_str("RUN_NATIVE_REPOS_CSV").split(",")
        if token.strip()
    ]
    for name, value in (
        ("RUN_TARGET_ARCH", target_arch),
        ("RUN_EXECUTOR", executor),
        ("RUN_TOKEN", run_token),
        ("RUN_REMOTE_PYTHON_BIN", python_bin),
        ("RUN_BPFTOOL_BIN", bpftool_bin),
    ):
        if not value:
            raise SystemExit(f"{name} is required; run corpus through Make")
    ns = argparse.Namespace(
        workspace=str(ROOT_DIR),
        target_arch=target_arch,
        target_name=target_name,
        executor=executor,
        run_token=run_token,
        python_bin=python_bin,
        bpftool_bin=bpftool_bin,
        daemon_binary="",  # resolved later via resolve_daemon_binary()
        suite=str(DEFAULT_MACRO_APPS_YAML),
        native_repos=native_repos,
        output_json="",  # filled in by _setup_runtime_env
        samples=_env_int("SAMPLES", 0),
        duration_s=_env_float("WORKLOAD_DURATION", 0.0),
        warmups=_env_int("WARMUPS", 1),
        skip_rejit=_env_bool("SKIP_REJIT"),
        keep_failure_artifacts=_keep_workdirs_enabled(),
    )
    if ns.samples < 0:
        raise SystemExit("SAMPLES must be >= 0")
    if ns.warmups < 0:
        raise SystemExit("WARMUPS must be >= 0")
    if ns.duration_s < 0:
        raise SystemExit("WORKLOAD_DURATION must be >= 0")
    return ns

def _print_progress(event: str, **fields: object) -> None:
    payload = {"event": event}
    payload.update(fields)
    print(json.dumps(payload, sort_keys=True), flush=True)


def _daemon_exit_error(daemon_session: DaemonSession) -> str | None:
    returncode = daemon_session.proc.poll()
    if returncode is None:
        return None
    return f"daemon session exited early (rc={returncode})"


def _workload_seconds(args: argparse.Namespace | None = None) -> float:
    """Single global workload duration. CLI/env override beats catalog default."""
    if args is not None:
        explicit = float(getattr(args, "duration_s", 0) or 0)
        if explicit > 0:
            return explicit
    return float(DEFAULT_CORPUS_WORKLOAD_DURATION_S)


def _sample_count(args: argparse.Namespace) -> int:
    explicit = int(args.samples or 0)
    if explicit > 0: return explicit
    return int(DEFAULT_CORPUS_SAMPLES)


def _build_runner_state(
    app: AppSpec,
    runner: AppRunner,
) -> CaseLifecycleState:
    artifacts: dict[str, object] = {"rejit_policy_context": {
        "repo": str(app.name).strip(), "category": str(app.runner).strip(), "level": "corpus"}}
    result_details = runner.artifacts.get("result_details")
    if isinstance(result_details, Mapping):
        artifacts["result_details"] = dict(result_details)
    return CaseLifecycleState(
        runtime=runner,
        artifacts=artifacts,
    )


def _build_app_error_result(
    app: AppSpec,
    *,
    error: str,
    baseline_measurement: Mapping[str, object] | None = None,
    apply_result: Mapping[str, object] | None = None,
    rejit_measurement: Mapping[str, object] | None = None,
) -> dict[str, object]:
    return {
        "app": app.name,
        "runner": app.runner,
        "selected_workload": app.workload_for("corpus"),
        "status": "error",
        "error": str(error),
        "baseline": dict(baseline_measurement) if isinstance(baseline_measurement, Mapping) else None,
        "post_rejit": dict(rejit_measurement) if isinstance(rejit_measurement, Mapping) else None,
        "rejit_result": dict(apply_result) if isinstance(apply_result, Mapping) else None,
    }


def _build_app_ok_result(
    app: AppSpec,
    *,
    baseline_measurement: Mapping[str, object],
    apply_result: Mapping[str, object] | None,
    rejit_measurement: Mapping[str, object] | None,
) -> dict[str, object]:
    return {
        "app": app.name,
        "runner": app.runner,
        "selected_workload": app.workload_for("corpus"),
        "status": "ok",
        "error": "",
        "baseline": dict(baseline_measurement),
        "post_rejit": dict(rejit_measurement) if isinstance(rejit_measurement, Mapping) else None,
        "rejit_result": dict(apply_result) if isinstance(apply_result, Mapping) else None,
    }


def _build_app_result_from_lifecycle(
    app: AppSpec,
    lifecycle: LifecycleRunResult | None,
    *,
    fatal_error: str = "",
) -> dict[str, object]:
    def with_runner_details(payload: dict[str, object]) -> dict[str, object]:
        state = lifecycle.state if lifecycle is not None else None
        artifacts = state.artifacts if state is not None else {}
        result_details = artifacts.get("result_details") if isinstance(artifacts, Mapping) else None
        if isinstance(result_details, Mapping):
            payload["runner_details"] = dict(result_details)
        return payload

    baseline_measurement = (
        dict(lifecycle.baseline)
        if lifecycle is not None and isinstance(lifecycle.baseline, Mapping)
        else None
    )
    apply_result = dict(lifecycle.rejit_result or {}) if lifecycle is not None else {}
    rejit_measurement = (
        dict(lifecycle.post_rejit)
        if lifecycle is not None and isinstance(lifecycle.post_rejit, Mapping)
        else None
    )
    error_message = str(lifecycle.error or "") if lifecycle is not None else ""
    stop_error = str(lifecycle.stop_error or "") if lifecycle is not None else ""
    if fatal_error:
        error_message = fatal_error if not error_message else f"{error_message}; {fatal_error}"
    if stop_error:
        error_message = stop_error if not error_message else f"{error_message}; stop failed: {stop_error}"
    if error_message:
        return with_runner_details(
            _build_app_error_result(
                app,
                error=error_message,
                baseline_measurement=baseline_measurement,
                apply_result=apply_result,
                rejit_measurement=rejit_measurement,
            )
        )

    if baseline_measurement is None:
        return with_runner_details(
            _build_app_error_result(
                app,
                error="baseline measurement is missing",
                baseline_measurement=baseline_measurement,
                apply_result=apply_result,
                rejit_measurement=rejit_measurement,
            )
        )
    return with_runner_details(
        _build_app_ok_result(
            app,
            baseline_measurement=baseline_measurement,
            apply_result=apply_result,
            rejit_measurement=rejit_measurement,
        )
    )


@dataclass
class CorpusAppSession:
    app: AppSpec
    runner: AppRunner
    state: CaseLifecycleState
    workload_seconds: float


def _run_suite_lifecycle_sessions(
    prepared_daemon_session: object,
    sessions: Sequence[CorpusAppSession],
    *,
    samples: int,
    warmups: int = 1,
    skip_rejit: bool = False,
) -> tuple[list[LifecycleRunResult], str]:
    if not hasattr(prepared_daemon_session, "session"):
        raise RuntimeError("prepared daemon session is required")
    active_daemon_session = prepared_daemon_session.session
    session_list = list(sessions)
    lifecycle_results = [
        LifecycleRunResult(state=session.state, baseline=None, rejit_result=None, post_rejit=None)
        for session in session_list
    ]
    session_results = list(zip(session_list, lifecycle_results))
    fatal_error = ""
    apply_enabled_passes = benchmark_rejit_enabled_passes()

    def stop_session(session: CorpusAppSession, result: LifecycleRunResult) -> None:
        if result.stopped:
            return
        try:
            session.runner.stop()
        except Exception as exc:
            result.stop_error = str(exc)
        finally:
            result.stopped = True

    def record_baseline_failure(
        session: CorpusAppSession,
        result: LifecycleRunResult,
        error: str,
    ) -> None:
        result.error = str(error)
        stop_session(session, result)
        try:
            wait_for_suite_quiescence()
        except Exception as quiesce_exc:
            extra = str(quiesce_exc)
            result.error = f"{result.error}; {extra}" if result.error else extra

    def check_daemon() -> None:
        if daemon_error := _daemon_exit_error(active_daemon_session):
            raise RuntimeError(daemon_error)

    def session_workload(session: CorpusAppSession) -> str:
        workload_for = getattr(session.app, "workload_for", None)
        if callable(workload_for):
            return str(workload_for("corpus"))
        return str(getattr(session.app, "workload", ""))

    def session_pids(session: CorpusAppSession) -> list[int]:
        raw = getattr(session.runner, "pids", None)
        pids = raw if isinstance(raw, Sequence) and not isinstance(raw, (str, bytes, bytearray)) else [session.runner.pid]
        result = [int(pid) for pid in pids if pid is not None and int(pid) > 0]
        if not result:
            raise RuntimeError(f"{session.app.name}: runner did not expose any shim pids")
        return result

    try:
        active_pairs = list(session_results)
        surviving_pairs: list[tuple[CorpusAppSession, LifecycleRunResult]] = []
        for session, result in active_pairs:
            try:
                _print_progress(
                    "measurement_start",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="baseline",
                    workload=session_workload(session),
                    samples=samples,
                )
                result.baseline = active_daemon_session.measure_phase(
                    app_pids=session_pids(session),
                    runner=session.runner,
                    workload_seconds=session.workload_seconds,
                    samples=samples,
                    warmups=warmups,
                )
                _print_progress(
                    "measurement_done",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="baseline",
                    status="ok",
                )
                surviving_pairs.append((session, result))
            except Exception as exc:
                _print_progress(
                    "measurement_done",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="baseline",
                    status="error",
                    error=str(exc),
                )
                record_baseline_failure(session, result, str(exc))
            check_daemon()

        active_pairs = surviving_pairs
        for session, result in active_pairs:
            if skip_rejit:
                _print_progress(
                    "rejit_skipped",
                    app=session.app.name,
                    runner=session.app.runner,
                )
                result.rejit_result = {"status": "skipped"}
                continue
            _print_progress(
                "rejit_start",
                app=session.app.name,
                runner=session.app.runner,
            )
            # Per-app pass yaml lookup uses the lib short name (first slash
            # segment) so config dirs live as runner/config/passes/<pass>/
            # <katran|cilium|bcc|...>.yaml regardless of which sub-target
            # (`/agent`, `/set`, `/profiling`) the corpus selects.
            yaml_app_name = str(session.app.name).split("/")[0]
            result.rejit_result = active_daemon_session.apply_rejit_for_app(
                app_pids=session_pids(session),
                enabled_passes=apply_enabled_passes,
                failure_artifacts_dir=prepared_daemon_session.failure_artifacts_dir,
                app_name=yaml_app_name,
            )
            _print_progress(
                "rejit_done",
                app=session.app.name,
                runner=session.app.runner,
                status=str(result.rejit_result.get("status") or "error"),
            )
            check_daemon()

        for session, result in active_pairs:
            try:
                _print_progress(
                    "measurement_start",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="post_rejit",
                    workload=session_workload(session),
                    samples=samples,
                )
                result.post_rejit = active_daemon_session.measure_phase(
                    app_pids=session_pids(session),
                    runner=session.runner,
                    workload_seconds=session.workload_seconds,
                    samples=samples,
                    warmups=warmups,
                )
                _print_progress(
                    "measurement_done",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="post_rejit",
                    status="ok",
                )
            except Exception as exc:
                result.error = str(exc)
                _print_progress(
                    "measurement_done",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="post_rejit",
                    status="error",
                    error=str(exc),
                )
            check_daemon()
    except Exception as exc:
        fatal_error = str(exc)
    finally:
        for session, result in session_results:
            if not result.stopped:
                stop_session(session, result)

    return lifecycle_results, fatal_error


def _sanitize_app_filename(app_name: str) -> str:
    """Return a filesystem-safe filename stem for an app name (slashes become double underscores)."""
    return app_name.replace("/", "__")


def _write_incremental_app_result(
    run_dir: Path,
    app_name: str,
    result: dict[str, object],
    apps_done: int,
    total_apps: int,
) -> None:
    """Write per-app JSON and update progress.json + metadata.json after each app completes."""
    safe_name = _sanitize_app_filename(app_name)
    apps_dir = run_dir / "details" / "apps"
    apps_dir.mkdir(parents=True, exist_ok=True)
    app_path = apps_dir / f"{safe_name}.json"
    app_path.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")

    progress_path = run_dir / "details" / "progress.json"
    progress: dict[str, object] = {}
    if progress_path.exists():
        try:
            progress = json.loads(progress_path.read_text())
        except (OSError, json.JSONDecodeError):
            progress = {}
    progress["apps_done"] = apps_done
    progress["total_apps"] = total_apps
    progress["last_app"] = app_name
    progress["last_app_status"] = str(result.get("status") or "error")
    progress["last_updated_at"] = datetime.now(timezone.utc).isoformat()
    progress_path.write_text(json.dumps(progress, indent=2, sort_keys=True) + "\n")

    metadata_path = run_dir / "metadata.json"
    if metadata_path.exists():
        try:
            metadata: dict[str, object] = json.loads(metadata_path.read_text())
        except (OSError, json.JSONDecodeError):
            metadata = {}
        metadata["last_updated_at"] = datetime.now(timezone.utc).isoformat()
        metadata_path.write_text(json.dumps(metadata, indent=2, sort_keys=True) + "\n")


def run_suite(
    args: argparse.Namespace,
    suite: AppSuite,
    *,
    artifact_session: "ArtifactSession | None" = None,
    partial_results: "dict[str, dict[str, object]] | None" = None,
) -> dict[str, object]:
    suite_path = suite.manifest_path.resolve()
    daemon_binary = Path(args.daemon_binary).resolve()
    if not daemon_binary.exists():
        raise RuntimeError(f"daemon binary not found: {daemon_binary}")

    workload_seconds = _workload_seconds(args)
    samples = _sample_count(args)
    warmups = max(0, int(getattr(args, "warmups", 1) or 0))
    skip_rejit = bool(getattr(args, "skip_rejit", False))
    results_by_name: dict[str, dict[str, object]] = {}
    completed_apps: set[str] = set()
    fatal_error = ""
    total_apps = len(suite.apps)

    daemon_log_dir = artifact_session.run_dir / "details"
    # Load all kinsn .ko modules into the running kernel before any app
    # starts. Stock-kernel BTF probing happens inside shim_init via
    # kinsnprober; that probe needs the modules already resident, otherwise
    # rotate/cond_select/endian_fusion/lea pass-emitted kfunc calls land on
    # btf_ids the kernel can't resolve (EACCES / EINVAL during PROG_LOAD).
    # daemon used to do this implicitly; with the shim path it must be
    # explicit at suite start.
    kinsn_module_metadata = prepare_kinsn_modules()
    with DaemonSession.start(
        daemon_binary,
        stdout_path=daemon_log_dir / "daemon.stdout.log",
        stderr_path=daemon_log_dir / "daemon.stderr.log",
    ) as daemon_session:
        # Inject the freshly-loaded module set so suite metadata reflects
        # actual resident kfunc providers instead of an empty stub.
        daemon_session.kinsn_metadata.update(kinsn_module_metadata)
        prepared_daemon_session = prepare_daemon_session(
            daemon_session,
            failure_artifacts_dir=(
                artifact_session.run_dir / "details" / "failure-artifacts"
                if args.keep_failure_artifacts else None
            ),
        )

        with enable_bpf_stats():
            for app in suite.apps:
                _print_progress("app_start", app=app.name, runner=app.runner, workload=app.workload_for("corpus"))
                runner: AppRunner | None = None
                result: dict[str, object] | None = None
                try:
                    runner = get_app_runner(app.runner, workload=app.workload_for("corpus"), **app.args)
                    runner.start()
                    state = _build_runner_state(app, runner)
                    session = CorpusAppSession(
                        app=app,
                        runner=runner,
                        state=state,
                        workload_seconds=workload_seconds,
                    )
                    lifecycle_results, app_fatal_error = _run_suite_lifecycle_sessions(
                        prepared_daemon_session,
                        [session],
                        samples=samples,
                        warmups=warmups,
                        skip_rejit=skip_rejit,
                    )
                    wait_for_suite_quiescence()
                    fatal_error = str(app_fatal_error or "")
                    lifecycle = lifecycle_results[0] if lifecycle_results else None
                    result = _build_app_result_from_lifecycle(
                        app,
                        lifecycle,
                        fatal_error=fatal_error,
                    )
                    results_by_name[app.name] = result
                    completed_apps.add(app.name)
                    _print_progress("app_done", app=app.name, status=result.get("status"),
                                    error=result.get("error"))
                except Exception as exc:
                    stop_error = ""
                    quiesce_error = ""
                    if runner is not None:
                        try:
                            runner.stop()
                        except Exception as stop_exc:
                            stop_error = str(stop_exc)
                        try:
                            wait_for_suite_quiescence()
                        except Exception as quiesce_exc:
                            quiesce_error = str(quiesce_exc)
                    error_message = str(exc)
                    if stop_error:
                        error_message = f"{error_message}; stop failed: {stop_error}"
                    if quiesce_error:
                        error_message = f"{error_message}; quiesce failed: {quiesce_error}"
                    result = _build_app_error_result(app, error=error_message)
                    results_by_name[app.name] = result
                    completed_apps.add(app.name)
                    _print_progress("app_done", app=app.name, status=result.get("status"),
                                    error=result.get("error"))
                if result is not None:
                    if partial_results is not None:
                        partial_results[app.name] = result
                    if artifact_session is not None:
                        try:
                            _write_incremental_app_result(
                                artifact_session.run_dir,
                                app.name,
                                result,
                                apps_done=len(completed_apps),
                                total_apps=total_apps,
                            )
                        except Exception as write_exc:
                            _print_progress("incremental_write_error", app=app.name, error=str(write_exc))
                daemon_error = _daemon_exit_error(daemon_session)
                if daemon_error is not None:
                    fatal_error = daemon_error
                    break
                if fatal_error:
                    break

        kinsn_metadata = dict(prepared_daemon_session.metadata)

    # No top-level results array. Per-app data is in details/apps/<safe>.json
    # (incrementally written). Only suite status is copied into result.json.
    any_app_failed = any(
        str((results_by_name.get(app.name) or {}).get("status") or "error") != "ok"
        for app in suite.apps
    )
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(suite_path),
        "suite_name": suite.suite_name,
        "daemon": str(daemon_binary),
        "samples": samples,
        "warmups": warmups,
        "skip_rejit": skip_rejit,
        "workload_seconds": workload_seconds,
        "kinsn_modules": kinsn_metadata,
        "status": "error" if any_app_failed else "ok",
    }
    if fatal_error:
        payload["fatal_error"] = fatal_error
    return payload


def build_run_metadata(
    args: argparse.Namespace,
    *,
    resolved_samples: int,
    resolved_workload_seconds: float,
) -> dict[str, object]:
    metadata = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": "corpus",
        "manifest": str(Path(args.suite).resolve()),
        "samples": int(resolved_samples),
        "workload_seconds": float(resolved_workload_seconds),
    }
    metadata.update(benchmark_run_provenance())
    metadata.update(current_process_identity())
    return metadata


def _finalize_partial(
    session: "ArtifactSession",
    suite: "AppSuite",
    partial_results: dict[str, dict[str, object]],
    *,
    error_message: str,
    fatal_error: str = "",
) -> dict[str, object]:
    """Build and write a partial result payload from whatever per-app results were collected."""
    payload: dict[str, object] = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite_name": getattr(suite, "suite_name", ""),
        "samples": 0,
        "workload_seconds": 0.0,
        "status": "error",
        "partial": True,
    }
    if fatal_error:
        payload["fatal_error"] = fatal_error
    session.write(
        status="error",
        progress_payload={
            "suite": "corpus",
            "status": "error",
            "failed_at": datetime.now(timezone.utc).isoformat(),
            "error_message": error_message,
        },
        result_payload=payload,
        error_message=error_message,
    )
    return payload


def _setup_runtime_env(args: argparse.Namespace) -> Path:
    """Resolve workspace, set up container runtime env, validate artifacts.

    Replaces the former runner/suites/corpus.py wrapper; runs once at the
    start of main(). Mutates args in place (workspace, target_arch, daemon_binary).
    """
    workspace = suite_main_setup(args, str(ROOT_DIR), _setup_die)
    env = base_suite_runtime_env(workspace, args, "corpus", _setup_die)
    python_bin = args.python_bin or sys.executable
    resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_setup_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_setup_die)

    os.chdir(workspace)
    import shutil
    if inside_runtime_image() and shutil.which("ip", path=env["PATH"]) is not None:
        run_checked(["ip", "link", "set", "lo", "up"], cwd=workspace, env=env, die=_setup_die)
    ensure_bpf_stats_enabled(workspace, _setup_die)
    runtime_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    ensure_katran_artifacts(workspace, args.target_arch, args.native_repos, _setup_die)
    args.daemon_binary = str(resolve_daemon_binary(workspace, args.target_arch, args.daemon_binary, _setup_die))
    # Apply runtime env to current process (PATH, LD_LIBRARY_PATH, BPFREJIT_*, etc.)
    os.environ.update(runtime_env)
    if not args.output_json:
        args.output_json = str(workspace / "corpus" / "results" / f"{args.target_name}_corpus.json")
    args.output_json = str(resolve_workspace_path(workspace, args.output_json))
    return workspace


def _setup_die(message: str) -> None:
    raise SystemExit(f"[corpus-driver] {message}")


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    _setup_runtime_env(args)
    output_json = Path(args.output_json).resolve()
    suite = _filter_suite_apps(load_app_suite_from_yaml(Path(args.suite).resolve()))
    resolved_workload_seconds = _workload_seconds(args)
    resolved_samples = _sample_count(args)
    run_type = derive_run_type(output_json, "vm_corpus")
    started_at = datetime.now(timezone.utc).isoformat()
    progress_payload: dict[str, object] = {
        "suite": "corpus",
        "status": "running",
        "samples": int(resolved_samples),
        "workload_seconds": float(resolved_workload_seconds),
    }

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, object]:
        metadata = build_run_metadata(
            args,
            resolved_samples=resolved_samples,
            resolved_workload_seconds=resolved_workload_seconds,
        )
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

    # State shared between the main execution path and the SIGTERM handler.
    _partial_results: dict[str, dict[str, object]] = {}
    _sigterm_received: list[bool] = [False]

    def _sigterm_handler(signum: int, frame: object) -> None:
        _sigterm_received[0] = True
        _print_progress("sigterm_received", signal=signum)
        try:
            _finalize_partial(
                session,
                suite,
                _partial_results,
                error_message="corpus run terminated by SIGTERM",
                fatal_error="SIGTERM received",
            )
        except Exception as finalize_exc:
            _print_progress("sigterm_finalize_error", error=str(finalize_exc))
        raise SystemExit(130)

    signal.signal(signal.SIGTERM, _sigterm_handler)

    try:
        payload = run_suite(args, suite, artifact_session=session, partial_results=_partial_results)

        payload_status = str(payload.get("status") or "error").lower()
        error_message = str(payload.get("fatal_error") or "").strip()
        if payload_status == "ok":
            session.write(
                status="completed",
                progress_payload={
                    "suite": "corpus",
                    "status": "completed",
                    "completed_at": datetime.now(timezone.utc).isoformat(),
                },
                result_payload=payload,
            )
        else:
            session.write(
                status="error",
                progress_payload={
                    "suite": "corpus",
                    "status": "error",
                    "failed_at": datetime.now(timezone.utc).isoformat(),
                    "error_message": error_message or "corpus suite reported errors",
                },
                result_payload=payload,
                error_message=error_message or "corpus suite reported errors",
            )
        print(
            json.dumps(
                {
                    "status": payload_status,
                    "artifact_run_dir": str(session.run_dir),
                    "artifact_metadata": str(session.run_dir / "metadata.json"),
                },
                indent=2,
            )
        )
        # Per-app failures (verifier reject after rewrite, EBUSY tail-calls,
        # transient stats-sample errors) are recorded as raw errors. Only fail
        # when the suite never started (payload.fatal_error) or every app failed.
        suite_fatal = bool(str(payload.get("fatal_error") or "").strip())
        results = payload.get("results") or []
        all_apps_failed = bool(results) and all(
            str(r.get("status") or "error") != "ok" for r in results
        )
        return 1 if (suite_fatal or all_apps_failed) else 0
    except Exception as exc:
        exc_message = str(exc)
        _finalize_partial(
            session,
            suite,
            _partial_results,
            error_message=exc_message,
        )
        raise

if __name__ == "__main__":
    raise SystemExit(main())
