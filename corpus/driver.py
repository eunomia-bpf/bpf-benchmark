#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import signal
import shutil
import sys
import time
from contextlib import contextmanager
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable, Mapping, Sequence

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
from runner.libs.case_common import (
    LifecycleRunResult,
    wait_for_suite_quiescence,
)
from runner.libs.kinsn import prepare_kinsn_modules
from runner.libs import rejit_plan
from runner.libs.rejit import (
    benchmark_rejit_enabled_passes,
    benchmark_run_provenance,
    measure_app_phase,
    skip_rejit_disables_shim,
    skip_rejit_enabled,
)
from runner.libs.workload import WorkloadResult, run_named_workload
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
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    suite_main_setup,
)


DEFAULT_MACRO_APPS_YAML = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
_CORPUS_APPS_ENV = "BPFREJIT_CORPUS_APPS"
_CORPUS_APP_TIMEOUT_ENV = "BPFREJIT_CORPUS_APP_TIMEOUT"
_CORPUS_REJIT_TIMEOUT_ENV = "BPFREJIT_CORPUS_REJIT_TIMEOUT"
_CORPUS_NATIVE_LOADER_POST_ONLY_ENV = "BPFREJIT_CORPUS_NATIVE_LOADER_POST_ONLY"
_DEFAULT_CORPUS_APP_TIMEOUT_S = 1800.0
_DEFAULT_CORPUS_REJIT_TIMEOUT_S = 900.0
_TIMEOUT_STACK: list[tuple[float, str, float]] = []
_NATIVE_LOADER_ENV_NAMES = (
    "BPFREJIT_SHIM_NATIVE_LOADER",
    "BPFREJIT_SHIM_NATIVE_MANIFEST",
    "BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT",
    "BPFREJIT_SHIM_NATIVE_KMSG_PROGRESS",
    "BPFREJIT_NATIVE_LOADER_SO",
    "BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF",
    "BPFREJIT_NATIVE_LINK_BINARY",
    "BPFREJIT_NATIVE_DISABLE_MAP_LOWERING",
)


class _AppLifecycleComplete(Exception):
    pass


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


def _skip_rejit_enabled() -> bool:
    try:
        return skip_rejit_enabled(_env_str("SKIP_REJIT"))
    except ValueError as exc:
        raise SystemExit(str(exc)) from exc


def _local_docker_executor(args: argparse.Namespace) -> bool:
    return str(getattr(args, "executor", "")).strip() == "local-docker"


def _wait_for_suite_quiescence(args: argparse.Namespace) -> None:
    if _local_docker_executor(args):
        # Host Docker shares the host-wide BPF program table with unrelated
        # workloads, so the global count is not an isolation signal here.
        time.sleep(2.0)
        return
    wait_for_suite_quiescence()


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


def _env_bool(name: str, default: bool = False) -> bool:
    raw = _env_str(name).lower()
    if not raw:
        return bool(default)
    if raw in ("1", "true", "yes", "on"):
        return True
    if raw in ("0", "false", "no", "off"):
        return False
    raise SystemExit(f"{name} must be boolean: empty, 0/1, false/true, no/yes, or off/on")


def _native_loader_post_only_enabled() -> bool:
    mode = _env_str(_CORPUS_NATIVE_LOADER_POST_ONLY_ENV).lower()
    if mode in {"1", "true", "yes", "on", "post", "post_only", "post-only", "post_rejit"}:
        return True
    if mode not in {"", "0", "false", "no", "off"}:
        raise SystemExit(
            f"{_CORPUS_NATIVE_LOADER_POST_ONLY_ENV} must be boolean or post-only mode"
        )
    raw = _env_str("BPFREJIT_SHIM_NATIVE_LOADER").lower()
    if not raw or raw in {"0", "false", "no", "off", "1", "true", "yes", "on"}:
        return False
    if raw in {"post", "post_only", "post-only", "post_rejit"}:
        return True
    raise SystemExit(
        "BPFREJIT_SHIM_NATIVE_LOADER must be empty, 0/1, true/false, or post"
    )


def _validate_native_loader_skip_rejit(
    *,
    skip_rejit: bool,
    native_loader_post_only: bool,
) -> None:
    if not (skip_rejit and native_loader_post_only):
        return
    raise SystemExit(
        "native-loader post-only mode is incompatible with SKIP_REJIT; "
        "unset SKIP_REJIT to benchmark native replacement, or unset "
        f"{_CORPUS_NATIVE_LOADER_POST_ONLY_ENV}/BPFREJIT_SHIM_NATIVE_LOADER=post "
        "to run a no-ReJIT diagnostic"
    )


def _effective_rejit_enabled_passes(*, native_loader_post_only: bool) -> list[str]:
    enabled_passes = benchmark_rejit_enabled_passes()
    if native_loader_post_only and "BPFREJIT_BENCH_PASSES" not in os.environ:
        return []
    return enabled_passes


def _current_native_loader_env() -> dict[str, str]:
    return {
        name: value
        for name in _NATIVE_LOADER_ENV_NAMES
        if (value := os.environ.get(name)) is not None
    }


def _active_native_loader_env_keys(*, include_control_env: bool = True) -> list[str]:
    names = _NATIVE_LOADER_ENV_NAMES
    if include_control_env:
        names = (*names, _CORPUS_NATIVE_LOADER_POST_ONLY_ENV)
    return sorted(name for name in names if os.environ.get(name) is not None)


def _enable_native_loader_env(saved_env: Mapping[str, str]) -> dict[str, str | None]:
    updates: dict[str, str | None] = {name: None for name in _NATIVE_LOADER_ENV_NAMES}
    updates.update(saved_env)
    updates["BPFREJIT_SHIM_NATIVE_LOADER"] = "1"
    return updates


def _disable_native_loader_env() -> dict[str, str | None]:
    updates: dict[str, str | None] = {name: None for name in _NATIVE_LOADER_ENV_NAMES}
    updates[_CORPUS_NATIVE_LOADER_POST_ONLY_ENV] = None
    return updates


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
    skip_rejit = _skip_rejit_enabled()
    native_loader_post_only = _native_loader_post_only_enabled()
    _validate_native_loader_skip_rejit(
        skip_rejit=skip_rejit,
        native_loader_post_only=native_loader_post_only,
    )
    ns = argparse.Namespace(
        workspace=str(ROOT_DIR),
        target_arch=target_arch,
        target_name=target_name,
        executor=executor,
        run_token=run_token,
        python_bin=python_bin,
        bpftool_bin=bpftool_bin,
        suite=str(DEFAULT_MACRO_APPS_YAML),
        native_repos=native_repos,
        output_json="",  # filled in by _setup_runtime_env
        samples=_env_int("SAMPLES", 0),
        duration_s=_env_float("WORKLOAD_DURATION", 0.0),
        warmups=_env_int("WARMUPS", 1),
        app_timeout_s=_env_float(_CORPUS_APP_TIMEOUT_ENV, _DEFAULT_CORPUS_APP_TIMEOUT_S),
        rejit_timeout_s=_env_float(_CORPUS_REJIT_TIMEOUT_ENV, _DEFAULT_CORPUS_REJIT_TIMEOUT_S),
        skip_rejit=skip_rejit,
        keep_failure_artifacts=_keep_workdirs_enabled(),
        workload_only=_env_bool("BPFREJIT_CORPUS_WORKLOAD_ONLY"),
        collect_bpf_stats=_env_bool("BPFREJIT_CORPUS_BPF_STATS", True),
    )
    if ns.samples < 0:
        raise SystemExit("SAMPLES must be >= 0")
    if ns.warmups < 0:
        raise SystemExit("WARMUPS must be >= 0")
    if ns.duration_s < 0:
        raise SystemExit("WORKLOAD_DURATION must be >= 0")
    if ns.app_timeout_s < 0:
        raise SystemExit(f"{_CORPUS_APP_TIMEOUT_ENV} must be >= 0")
    if ns.rejit_timeout_s < 0:
        raise SystemExit(f"{_CORPUS_REJIT_TIMEOUT_ENV} must be >= 0")
    return ns

def _print_progress(event: str, **fields: object) -> None:
    payload = {"event": event}
    payload.update(fields)
    print(json.dumps(payload, sort_keys=True), flush=True)


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


def _build_runner_artifacts(
    app: AppSpec,
    runner: AppRunner,
) -> dict[str, object]:
    artifacts: dict[str, object] = {"rejit_policy_context": {
        "repo": str(app.name).strip(), "category": str(app.runner).strip(), "level": "corpus"}}
    result_details = runner.artifacts.get("result_details")
    if isinstance(result_details, Mapping):
        artifacts["result_details"] = dict(result_details)
    process_output = getattr(runner, "process_output", None)
    if isinstance(process_output, Mapping) and process_output:
        details = dict(artifacts.get("result_details") or {})
        details["process_output"] = dict(process_output)
        command_used = getattr(runner, "command_used", None)
        if isinstance(command_used, Sequence) and not isinstance(command_used, (str, bytes, bytearray)):
            details["command_used"] = [str(part) for part in command_used]
        artifacts["result_details"] = details
    return artifacts


def _app_workload_name(app: AppSpec) -> str:
    workload_for = getattr(app, "workload_for", None)
    if callable(workload_for):
        return str(workload_for("corpus"))
    return str(getattr(app, "workload", ""))


def _runner_pids(app: AppSpec, runner: AppRunner) -> list[int]:
    raw = getattr(runner, "pids", None)
    pids = raw if isinstance(raw, Sequence) and not isinstance(raw, (str, bytes, bytearray)) else [runner.pid]
    result = [int(pid) for pid in pids if pid is not None and int(pid) > 0]
    if not result:
        raise RuntimeError(f"{app.name}: runner did not expose any shim pids")
    return result


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
) -> dict[str, object]:
    def with_runner_details(payload: dict[str, object]) -> dict[str, object]:
        artifacts = lifecycle.artifacts if lifecycle is not None else {}
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

def _sanitize_app_filename(app_name: str) -> str:
    """Return a filesystem-safe filename stem for an app name (slashes become double underscores)."""
    return app_name.replace("/", "__")


@contextmanager
def _temporary_env(updates: Mapping[str, str | None]):
    previous: dict[str, str | None] = {key: os.environ.get(key) for key in updates}
    try:
        _apply_env_updates(updates)
        yield
    finally:
        _apply_env_updates(previous)


def _apply_env_updates(updates: Mapping[str, str | None]) -> None:
    for key, value in updates.items():
        if value is None:
            os.environ.pop(key, None)
        else:
            os.environ[key] = str(value)


def _arm_timeout_timer() -> None:
    if not _TIMEOUT_STACK:
        signal.setitimer(signal.ITIMER_REAL, 0.0)
        return
    next_deadline = min(entry[0] for entry in _TIMEOUT_STACK)
    signal.setitimer(signal.ITIMER_REAL, max(0.001, next_deadline - time.monotonic()))


def _timeout_signal_handler(signum: int, frame: object) -> None:
    del signum, frame
    if not _TIMEOUT_STACK:
        return
    entry = min(_TIMEOUT_STACK, key=lambda item: item[0])
    try:
        _TIMEOUT_STACK.remove(entry)
    except ValueError:
        pass
    _arm_timeout_timer()
    _deadline, label, seconds = entry
    raise TimeoutError(f"{label} timed out after {seconds:.1f}s")


@contextmanager
def _timeout_scope(seconds: float, label: str):
    budget = float(seconds or 0.0)
    if budget <= 0.0:
        yield
        return
    signal.signal(signal.SIGALRM, _timeout_signal_handler)
    entry = (time.monotonic() + budget, str(label), budget)
    _TIMEOUT_STACK.append(entry)
    _arm_timeout_timer()
    try:
        yield
    finally:
        try:
            _TIMEOUT_STACK.remove(entry)
        except ValueError:
            pass
        _arm_timeout_timer()


def _write_loadtime_plan(
    app: AppSpec,
    enabled_passes: Sequence[str],
    *,
    artifact_session: ArtifactSession | None,
) -> tuple[Path, dict[str, object]]:
    yaml_app_name = str(app.name).split("/")[0]
    payload = rejit_plan.build_execute_all_payload(enabled_passes, app_name=yaml_app_name)
    if artifact_session is not None:
        plan_dir = artifact_session.run_dir / "details" / "loadtime-plans"
    else:
        plan_dir = Path(os.environ.get("TMPDIR", "/tmp")) / "bpfrejit-loadtime-plans"
    plan_dir.mkdir(parents=True, exist_ok=True)
    plan_path = plan_dir / f"{_sanitize_app_filename(app.name)}.json"
    plan_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    return plan_path, payload


def _loadtime_reports_path(
    app: AppSpec,
    *,
    artifact_session: ArtifactSession | None,
) -> Path:
    if artifact_session is not None:
        reports_dir = artifact_session.run_dir / "details" / "loadtime-reports"
    else:
        reports_dir = Path(os.environ.get("TMPDIR", "/tmp")) / "bpfrejit-loadtime-reports"
    reports_dir.mkdir(parents=True, exist_ok=True)
    return reports_dir / f"{_sanitize_app_filename(app.name)}.jsonl"


def _shim_log_path(
    app: AppSpec,
    phase: str,
    *,
    artifact_session: ArtifactSession | None,
) -> Path:
    if artifact_session is not None:
        log_dir = artifact_session.run_dir / "details" / "shim-logs"
    else:
        log_dir = Path(os.environ.get("TMPDIR", "/tmp")) / "bpfrejit-shim-logs"
    log_dir.mkdir(parents=True, exist_ok=True)
    return log_dir / f"{_sanitize_app_filename(app.name)}.{phase}.log"


def _run_workload_without_ebpf_app(app: AppSpec, seconds: float) -> WorkloadResult:
    workload_name = _app_workload_name(app)
    if app.runner == "cilium":
        from runner.libs.app_runners.cilium import run_cilium_workload_without_app

        return run_cilium_workload_without_app(workload_name, seconds)
    if app.runner == "katran":
        from runner.libs.app_runners.katran import run_katran_workload_without_app

        return run_katran_workload_without_app(workload_name, seconds)
    return run_named_workload(workload_name, seconds)


def _measure_workload_without_ebpf_app(
    app: AppSpec,
    *,
    workload_seconds: float,
    samples: int,
    warmups: int,
) -> dict[str, object]:
    for _ in range(max(0, int(warmups))):
        _run_workload_without_ebpf_app(app, workload_seconds)
    return {
        "workloads": [
            _run_workload_without_ebpf_app(app, workload_seconds).to_dict()
            for _ in range(samples)
        ],
        "bpf": {},
    }


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


def _measure_app_phase_with_stats(
    *,
    workspace: Path,
    collect_bpf_stats: bool,
    app_pids: Sequence[int],
    runner: AppRunner,
    workload_seconds: float,
    samples: int,
    warmups: int,
) -> dict[str, object]:
    def die(message: str) -> None:
        raise RuntimeError(message)

    if collect_bpf_stats:
        _set_bpf_stats_enabled(workspace, True, die=die)
    try:
        return measure_app_phase(
            app_pids=app_pids,
            runner=runner,
            workload_seconds=workload_seconds,
            samples=samples,
            warmups=warmups,
        )
    finally:
        if collect_bpf_stats:
            _set_bpf_stats_enabled(workspace, False, die=die)


def _disable_bpf_stats_after_stop(workspace: Path, collect_bpf_stats: bool) -> None:
    if not collect_bpf_stats:
        return

    def die(message: str) -> None:
        raise RuntimeError(message)

    _set_bpf_stats_enabled(workspace, False, die=die)


def run_suite(
    args: argparse.Namespace,
    suite: AppSuite,
    *,
    artifact_session: "ArtifactSession | None" = None,
    partial_results: "dict[str, dict[str, object]] | None" = None,
) -> dict[str, object]:
    workspace = ROOT_DIR
    suite_path = suite.manifest_path.resolve()
    workload_seconds = _workload_seconds(args)
    samples = _sample_count(args)
    warmups = max(0, int(getattr(args, "warmups", 1) or 0))
    skip_rejit = bool(getattr(args, "skip_rejit", False))
    workload_only = bool(getattr(args, "workload_only", False))
    collect_bpf_stats = bool(getattr(args, "collect_bpf_stats", True))
    native_loader_post_only = _native_loader_post_only_enabled()
    _validate_native_loader_skip_rejit(
        skip_rejit=skip_rejit,
        native_loader_post_only=native_loader_post_only,
    )
    post_only_native_env = _current_native_loader_env()
    if native_loader_post_only:
        _apply_env_updates(_disable_native_loader_env())
    _print_progress(
        "native_loader_mode",
        post_only=native_loader_post_only,
        saved_env_keys=sorted(post_only_native_env),
        active_env_keys=_active_native_loader_env_keys(),
    )
    results_by_name: dict[str, dict[str, object]] = {}
    completed_apps: set[str] = set()
    total_apps = len(suite.apps)
    apply_enabled_passes = _effective_rejit_enabled_passes(
        native_loader_post_only=native_loader_post_only
    )

    # Kinsn modules are only valid on the benchmark kernel that built them.
    # Host Docker runs on the host kernel and must not install image modules.
    should_load_kinsn = (
        not workload_only
        and not skip_rejit_disables_shim()
        and not _local_docker_executor(args)
    )
    kinsn_module_metadata = prepare_kinsn_modules() if should_load_kinsn else {}
    for app in suite.apps:
            _print_progress("app_start", app=app.name, runner=app.runner, workload=app.workload_for("corpus"))
            runner: AppRunner | None = None
            lifecycle: LifecycleRunResult | None = None
            startup_error = ""
            phase = ""
            try:
                with _timeout_scope(float(getattr(args, "app_timeout_s", 0.0) or 0.0),
                                    f"{app.name} app lifecycle"):
                    if workload_only:
                        workload_name = _app_workload_name(app)
                        lifecycle = LifecycleRunResult(
                            baseline=None,
                            rejit_result={"status": "skipped", "mode": "workload_only"},
                            post_rejit=None,
                            artifacts={},
                        )
                        phase = "workload_only"
                        _print_progress(
                            "measurement_start",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            workload=workload_name,
                            samples=samples,
                        )
                        lifecycle.baseline = _measure_workload_without_ebpf_app(
                            app,
                            workload_seconds=workload_seconds,
                            samples=samples,
                            warmups=warmups,
                        )
                        _print_progress(
                            "measurement_done",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            status="ok",
                        )
                        _wait_for_suite_quiescence(args)
                        raise _AppLifecycleComplete

                    phase = "baseline_start"
                    _print_progress(
                        "phase_start",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        workload=app.workload_for("corpus"),
                    )
                    runner = get_app_runner(app.runner, workload=app.workload_for("corpus"), **app.args)
                    baseline_env: dict[str, str | None] = {
                        "BPFREJIT_SHIM_LOADTIME_PLAN": "",
                        "BPFREJIT_SHIM_LOG": str(_shim_log_path(
                            app,
                            "baseline",
                            artifact_session=artifact_session,
                        )),
                    }
                    _print_progress(
                        "native_loader_phase_env",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        active_env_keys=_active_native_loader_env_keys(),
                        temporary_set_keys=sorted(
                            key for key, value in baseline_env.items() if value is not None
                        ),
                        temporary_unset_keys=sorted(
                            key for key, value in baseline_env.items() if value is None
                        ),
                    )
                    with _temporary_env(baseline_env):
                        runner.start()
                    _print_progress(
                        "phase_done",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        status="ok",
                    )
                    lifecycle = LifecycleRunResult(
                        baseline=None,
                        rejit_result=None,
                        post_rejit=None,
                        artifacts=_build_runner_artifacts(app, runner),
                    )
                    app_pids = _runner_pids(app, runner)
                    workload_name = _app_workload_name(app)

                    phase = "baseline"
                    _print_progress(
                        "measurement_start",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        workload=workload_name,
                        samples=samples,
                    )
                    lifecycle.baseline = _measure_app_phase_with_stats(
                        workspace=workspace,
                        collect_bpf_stats=collect_bpf_stats,
                        app_pids=app_pids,
                        runner=runner,
                        workload_seconds=workload_seconds,
                        samples=samples,
                        warmups=warmups,
                    )
                    _print_progress(
                        "measurement_done",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        status="ok",
                    )

                    phase = "baseline_stop"
                    try:
                        _print_progress(
                            "phase_start",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                        )
                        runner.stop()
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="runner_stop_done",
                        )
                        runner = None
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="quiesce_start",
                        )
                        _wait_for_suite_quiescence(args)
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="quiesce_done",
                        )
                        _disable_bpf_stats_after_stop(workspace, collect_bpf_stats)
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="bpf_stats_disabled",
                        )
                        _print_progress(
                            "phase_done",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            status="ok",
                        )
                    except Exception as stop_exc:
                        raise RuntimeError(f"baseline app stop failed: {stop_exc}") from stop_exc

                    if skip_rejit_disables_shim():
                        lifecycle.rejit_result = {"status": "skipped", "mode": "skip_rejit_all"}
                        raise _AppLifecycleComplete

                    phase = "loadtime_plan"
                    loadtime_env: dict[str, str | None] = {
                        "BPFREJIT_REPO_ROOT": str(REPO_ROOT),
                        "BPFREJIT_SHIM_LOADTIME_PLAN": "",
                        "BPFREJIT_SHIM_LOG": str(_shim_log_path(
                            app,
                            "post_rejit",
                            artifact_session=artifact_session,
                        )),
                    }
                    if native_loader_post_only:
                        loadtime_env.update(_enable_native_loader_env(post_only_native_env))
                    _print_progress(
                        "native_loader_phase_env",
                        app=app.name,
                        runner=app.runner,
                        phase="post_rejit_start",
                        active_env_keys=_active_native_loader_env_keys(),
                        temporary_set_keys=sorted(
                            key for key, value in loadtime_env.items() if value is not None
                        ),
                        temporary_unset_keys=sorted(
                            key for key, value in loadtime_env.items() if value is None
                        ),
                    )
                    if skip_rejit:
                        _print_progress("rejit_skipped", app=app.name, runner=app.runner)
                        lifecycle.rejit_result = {"status": "skipped", "mode": "loadtime"}
                    elif native_loader_post_only and not apply_enabled_passes:
                        lifecycle.rejit_result = {
                            "status": "ok",
                            "mode": "native_loader",
                            "enabled_passes": [],
                        }
                        _print_progress(
                            "loadtime_plan_done",
                            app=app.name,
                            runner=app.runner,
                            status="native_loader_only",
                        )
                    else:
                        _print_progress("loadtime_plan_start", app=app.name, runner=app.runner)
                        plan_path, _plan_payload = _write_loadtime_plan(
                            app,
                            apply_enabled_passes,
                            artifact_session=artifact_session,
                        )
                        loadtime_env["BPFREJIT_SHIM_LOADTIME_PLAN"] = str(plan_path)
                        reports_path = _loadtime_reports_path(
                            app,
                            artifact_session=artifact_session,
                        )
                        loadtime_env["BPFREJIT_SHIM_LOADTIME_REPORTS"] = str(reports_path)
                        lifecycle.rejit_result = {
                            "status": "ok",
                            "mode": "loadtime",
                            "plan_path": str(plan_path),
                            "report_path": str(reports_path),
                            "enabled_passes": list(apply_enabled_passes),
                        }
                        _print_progress(
                            "loadtime_plan_done",
                            app=app.name,
                            runner=app.runner,
                            status=str(lifecycle.rejit_result.get("status") or "error"),
                        )

                    phase = "post_rejit_start"
                    _print_progress(
                        "phase_start",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        workload=app.workload_for("corpus"),
                    )
                    runner = get_app_runner(app.runner, workload=app.workload_for("corpus"), **app.args)
                    with _timeout_scope(float(getattr(args, "rejit_timeout_s", 0.0) or 0.0),
                                        f"{app.name} loadtime rejit"):
                        with _temporary_env(loadtime_env):
                            runner.start()
                    _print_progress(
                        "phase_done",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        status="ok",
                    )
                    app_pids = _runner_pids(app, runner)

                    phase = "post_rejit"
                    _print_progress(
                        "measurement_start",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        workload=workload_name,
                        samples=samples,
                    )
                    lifecycle.post_rejit = _measure_app_phase_with_stats(
                        workspace=workspace,
                        collect_bpf_stats=collect_bpf_stats,
                        app_pids=app_pids,
                        runner=runner,
                        workload_seconds=workload_seconds,
                        samples=samples,
                        warmups=warmups,
                    )
                    _print_progress(
                        "measurement_done",
                        app=app.name,
                        runner=app.runner,
                        phase=phase,
                        status="ok",
                    )

                    phase = "post_rejit_stop"
                    try:
                        _print_progress(
                            "phase_start",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                        )
                        runner.stop()
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="runner_stop_done",
                        )
                        runner = None
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="quiesce_start",
                        )
                        _wait_for_suite_quiescence(args)
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="quiesce_done",
                        )
                        _disable_bpf_stats_after_stop(workspace, collect_bpf_stats)
                        _print_progress(
                            "phase_step",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            step="bpf_stats_disabled",
                        )
                        _print_progress(
                            "phase_done",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            status="ok",
                        )
                    except Exception as stop_exc:
                        raise RuntimeError(f"post app stop failed: {stop_exc}") from stop_exc
            except _AppLifecycleComplete:
                pass
            except Exception as exc:
                error_message = str(exc)
                if lifecycle is None:
                    startup_error = error_message
                else:
                    lifecycle.error = error_message
                    if phase in {"baseline_start", "loadtime_plan", "post_rejit_start", "baseline_stop", "post_rejit_stop"}:
                        _print_progress(
                            "phase_error",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            error=error_message,
                        )
                    elif phase:
                        _print_progress(
                            "measurement_done",
                            app=app.name,
                            runner=app.runner,
                            phase=phase,
                            status="error",
                            error=error_message,
                        )
            finally:
                stop_error = ""
                quiesce_error = ""
                if runner is not None:
                    try:
                        runner.stop()
                    except Exception as stop_exc:
                        stop_error = str(stop_exc)
                    if lifecycle is not None:
                        lifecycle.artifacts.update(_build_runner_artifacts(app, runner))
                    try:
                        _wait_for_suite_quiescence(args)
                    except Exception as quiesce_exc:
                        quiesce_error = str(quiesce_exc)
                    if not stop_error:
                        try:
                            _disable_bpf_stats_after_stop(workspace, collect_bpf_stats)
                        except Exception as stats_exc:
                            quiesce_error = (
                                f"{quiesce_error}; bpf stats disable failed: {stats_exc}"
                                if quiesce_error else f"bpf stats disable failed: {stats_exc}"
                            )
                if lifecycle is not None:
                    lifecycle.stop_error = stop_error
                    if quiesce_error:
                        lifecycle.error = (
                            f"{lifecycle.error}; quiesce failed: {quiesce_error}"
                            if lifecycle.error else f"quiesce failed: {quiesce_error}"
                        )
                elif startup_error:
                    if stop_error:
                        startup_error = f"{startup_error}; stop failed: {stop_error}"
                    if quiesce_error:
                        startup_error = f"{startup_error}; quiesce failed: {quiesce_error}"

            result = (
                _build_app_result_from_lifecycle(app, lifecycle)
                if lifecycle is not None
                else _build_app_error_result(app, error=startup_error or "app lifecycle did not start")
            )
            results_by_name[app.name] = result
            completed_apps.add(app.name)
            _print_progress("app_done", app=app.name, status=result.get("status"),
                            error=result.get("error"))
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

    kinsn_metadata = dict(kinsn_module_metadata)

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
        "samples": samples,
        "warmups": warmups,
        "skip_rejit": skip_rejit,
        "workload_only": workload_only,
        "bpf_stats": collect_bpf_stats,
        "workload_seconds": workload_seconds,
        "kinsn_modules": kinsn_metadata,
        "status": "error" if any_app_failed else "ok",
    }
    return payload


def build_run_metadata(
    args: argparse.Namespace,
    *,
    resolved_samples: int,
    resolved_workload_seconds: float,
    enabled_passes: Sequence[str] | None = None,
) -> dict[str, object]:
    metadata = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": "corpus",
        "manifest": str(Path(args.suite).resolve()),
        "samples": int(resolved_samples),
        "workload_seconds": float(resolved_workload_seconds),
        "workload_only": bool(getattr(args, "workload_only", False)),
        "bpf_stats": bool(getattr(args, "collect_bpf_stats", True)),
    }
    metadata.update(benchmark_run_provenance(enabled_passes=enabled_passes))
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
    detail_payloads: dict[str, object] = {}
    apps_done = 0
    for app in getattr(suite, "apps", []):
        app_name = str(getattr(app, "name", ""))
        if not app_name:
            continue
        result = partial_results.get(app_name)
        if result is None:
            result = {
                "app": app_name,
                "status": "error",
                "error": error_message,
                "baseline": None,
                "post_rejit": None,
                "rejit_result": None,
            }
        elif str(result.get("status") or "error") == "ok":
            apps_done += 1
        detail_payloads[
            f"apps/{_sanitize_app_filename(app_name)}.json"
        ] = result
    session.write(
        status="error",
        progress_payload={
            "suite": "corpus",
            "status": "error",
            "apps_done": apps_done,
            "total_apps": len(getattr(suite, "apps", [])),
            "failed_at": datetime.now(timezone.utc).isoformat(),
            "error_message": error_message,
        },
        result_payload=payload,
        detail_payloads=detail_payloads,
        error_message=error_message,
    )
    return payload


def _setup_runtime_env(args: argparse.Namespace) -> Path:
    """Resolve workspace, set up container runtime env, validate artifacts.

    Runs once at the start of main(). Mutates args in place for resolved
    runtime paths.
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
    if bool(getattr(args, "collect_bpf_stats", True)):
        ensure_bpf_stats_enabled(workspace, _setup_die)
        _set_bpf_stats_enabled(workspace, False)
    else:
        _set_bpf_stats_enabled(workspace, False)
    runtime_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    ensure_katran_artifacts(workspace, args.target_arch, args.native_repos, _setup_die)
    # Apply runtime env to current process (PATH, LD_LIBRARY_PATH, BPFREJIT_*, etc.)
    os.environ.update(runtime_env)
    if not args.output_json:
        args.output_json = str(workspace / "corpus" / "results" / f"{args.target_name}_corpus.json")
    args.output_json = str(resolve_workspace_path(workspace, args.output_json))
    return workspace


def _set_bpf_stats_enabled(
    workspace: Path,
    enabled: bool,
    *,
    die: Callable[[str], object] | None = None,
) -> None:
    if die is None:
        die = _setup_die
    sysctl_bin = shutil.which("sysctl")
    value = "1" if enabled else "0"
    if sysctl_bin:
        run_checked(
            [sysctl_bin, "-q", "-w", f"kernel.bpf_stats_enabled={value}"],
            cwd=workspace,
            env={"PATH": os.environ.get("PATH", "") or "/usr/sbin:/usr/bin:/sbin:/bin"},
            die=die,
        )
    else:
        run_checked(
            ["sh", "-c", f"printf '{value}\\n' > /proc/sys/kernel/bpf_stats_enabled"],
            cwd=workspace,
            env=os.environ.copy(),
            die=die,
        )
    stats_path = Path("/proc/sys/kernel/bpf_stats_enabled")
    if stats_path.read_text(encoding="utf-8").strip() != value:
        action = "enable" if enabled else "disable"
        die(f"failed to {action} kernel.bpf_stats_enabled={value}")


def _setup_die(message: str) -> None:
    raise SystemExit(f"[corpus-driver] {message}")


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    _setup_runtime_env(args)
    output_json = Path(args.output_json).resolve()
    suite = _filter_suite_apps(load_app_suite_from_yaml(Path(args.suite).resolve()))
    resolved_workload_seconds = _workload_seconds(args)
    resolved_samples = _sample_count(args)
    native_loader_post_only = _native_loader_post_only_enabled()
    effective_enabled_passes = _effective_rejit_enabled_passes(
        native_loader_post_only=native_loader_post_only
    )
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
            enabled_passes=effective_enabled_passes,
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
        # Per-app failures are recorded as raw errors. Only fail when the suite
        # never started or hit a fatal orchestration error.
        suite_fatal = bool(str(payload.get("fatal_error") or "").strip())
        return 1 if suite_fatal else 0
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
