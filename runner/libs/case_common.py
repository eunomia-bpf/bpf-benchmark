from __future__ import annotations

import copy
import platform
import sys
import time
from dataclasses import dataclass, field
from typing import Callable, Mapping, Sequence

from runner.libs import run_command
from runner.libs.app_runners.base import AppRunner
from runner.libs.bpf_stats import list_program_ids
from runner.libs.rejit import DaemonSession
from runner.libs.kinsn import relpath

DEFAULT_SUITE_QUIESCE_TIMEOUT_S = 20.0
DEFAULT_SUITE_QUIESCE_STABLE_S = 2.0
DEFAULT_SUITE_QUIESCE_POLL_S = 0.2


def wait_for_suite_quiescence(
    *,
    stable_s: float = DEFAULT_SUITE_QUIESCE_STABLE_S,
    timeout_s: float = DEFAULT_SUITE_QUIESCE_TIMEOUT_S,
    poll_s: float = DEFAULT_SUITE_QUIESCE_POLL_S,
) -> None:
    deadline = time.monotonic() + max(0.0, float(timeout_s))
    stable_window, poll_interval = max(0.0, float(stable_s)), max(0.05, float(poll_s))
    previous_ids: tuple[int, ...] | None = None
    stable_since: float | None = None
    while True:
        now = time.monotonic()
        current_ids = tuple(sorted(list_program_ids()))
        if current_ids == previous_ids:
            if stable_since is None:
                stable_since = now
            if now - stable_since >= stable_window:
                return
        else:
            previous_ids = current_ids
            stable_since = now
        if now >= deadline:
            break
        time.sleep(min(poll_interval, max(0.0, deadline - now)))
    rendered = ", ".join(str(pid) for pid in (previous_ids or ()))
    raise RuntimeError(f"kernel program table did not quiesce between suite entries within "
                       f"{float(timeout_s):.1f}s; last visible prog_ids=[{rendered}]")

@dataclass
class CaseLifecycleState:
    runtime: AppRunner
    prog_ids: list[int] = field(default_factory=list)
    artifacts: dict[str, object] = field(default_factory=dict)


@dataclass
class PreparedDaemonSession:
    session: DaemonSession
    metadata: dict[str, object]


@dataclass
class LifecycleRunResult:
    state: CaseLifecycleState | None
    baseline: Mapping[str, object] | None
    rejit_result: dict[str, object] | None
    post_rejit: Mapping[str, object] | None
    artifacts: dict[str, object] = field(default_factory=dict)
    rejit_prog_ids: list[int] = field(default_factory=list)
    error: str = ""
    stop_error: str = ""
    stopped: bool = False


def prepare_daemon_session(
    daemon_session: DaemonSession,
) -> PreparedDaemonSession:
    metadata = copy.deepcopy(getattr(daemon_session, "kinsn_metadata", {}) or {})
    if not bool(getattr(daemon_session, "load_kinsn", False)):
        return PreparedDaemonSession(session=daemon_session, metadata={})
    if not metadata:
        raise RuntimeError("daemon session requested kinsn loading but did not capture kinsn metadata")
    metadata["daemon_binary"] = relpath(daemon_session.daemon_binary.resolve())
    return PreparedDaemonSession(session=daemon_session, metadata=metadata)

def _daemon_exit_error(daemon_session: DaemonSession) -> str | None:
    returncode = daemon_session.proc.poll()
    return None if returncode is None else f"daemon session exited early (rc={returncode})"


def _normalize_enabled_passes(enabled_passes: Sequence[str] | None) -> list[str]:
    if enabled_passes is None:
        return []
    seen: set[str] = set()
    result: list[str] = []
    for p in enabled_passes:
        if (n := str(p).strip()) and n not in seen:
            seen.add(n); result.append(n)
    return result

def run_lifecycle_sessions(
    *, daemon_session: PreparedDaemonSession, sessions: Sequence[object], get_state: Callable[[object], CaseLifecycleState],
    measure: Callable[[object, CaseLifecycleState, str], Mapping[str, object] | None],
    stop: Callable[[object, CaseLifecycleState], None], enabled_passes: Sequence[str] | None = None,
    after_baseline: Callable[[object, CaseLifecycleState, Mapping[str, object]], Mapping[str, object] | None] | None = None,
    resolve_rejit_prog_ids: Callable[[object, CaseLifecycleState, Mapping[str, object]], Sequence[int] | None] | None = None,
    refresh_sessions: Callable[[Sequence[object], str], None] | None = None,
    on_session_failure: Callable[[object, LifecycleRunResult, str], None] | None = None,
) -> tuple[list[LifecycleRunResult], str]:
    active_daemon_session = daemon_session.session
    session_list = list(sessions)
    lifecycle_results = [LifecycleRunResult(state=get_state(session), baseline=None, rejit_result=None, post_rejit=None)
                         for session in session_list]
    session_results = list(zip(session_list, lifecycle_results))
    fatal_error = ""

    def _effective_enabled_passes() -> list[str]:
        if enabled_passes is not None:
            return _normalize_enabled_passes(enabled_passes)
        from runner.libs.rejit import benchmark_rejit_enabled_passes

        return benchmark_rejit_enabled_passes()

    def _check_daemon() -> None:
        if daemon_error := _daemon_exit_error(active_daemon_session):
            raise RuntimeError(daemon_error)
    def _stop_session(session: object, result: LifecycleRunResult) -> None:
        if result.stopped:
            return
        try:
            stop(session, result.state)
        except Exception as exc:
            result.stop_error = str(exc)
        finally:
            result.stopped = True
    def _record_failure(session: object, result: LifecycleRunResult, error: str, phase: str) -> None:
        result.error = str(error)
        _stop_session(session, result)
        if on_session_failure is None:
            return
        try:
            on_session_failure(session, result, phase)
        except Exception as callback_exc:
            extra = str(callback_exc)
            result.error = f"{result.error}; {extra}" if result.error else extra
    try:
        active_pairs = list(session_results)
        if active_pairs and refresh_sessions is not None: refresh_sessions([session for session, _ in active_pairs], "baseline")
        surviving_pairs: list[tuple[object, LifecycleRunResult]] = []
        for session, result in active_pairs:
            prog_ids = [int(value) for value in result.state.prog_ids if int(value) > 0]
            if not prog_ids:
                _record_failure(session, result, "lifecycle did not provide any program ids", "baseline")
            else:
                try:
                    baseline = measure(session, result.state, "baseline")
                    if baseline is None: raise RuntimeError("baseline workload returned no result")
                    result.baseline = baseline
                    if after_baseline is not None and (artifacts := after_baseline(session, result.state, baseline)):
                        result.state.artifacts.update(dict(artifacts))
                    surviving_pairs.append((session, result))
                except Exception as exc:
                    _record_failure(session, result, str(exc), "baseline")
            _check_daemon()
        active_pairs = surviving_pairs
        if active_pairs and refresh_sessions is not None: refresh_sessions([session for session, _ in active_pairs], "rejit")
        surviving_pairs = []
        for session, result in active_pairs:
            prog_ids = [int(value) for value in result.state.prog_ids if int(value) > 0]
            if resolve_rejit_prog_ids is not None:
                prog_ids = [
                    int(value)
                    for value in (resolve_rejit_prog_ids(session, result.state, result.baseline or {}) or [])
                    if int(value) > 0
                ]
            if not prog_ids: raise RuntimeError("lifecycle did not provide any program ids after baseline")
            result.rejit_prog_ids = prog_ids
            surviving_pairs.append((session, result))
        active_pairs = surviving_pairs
        if active_pairs:
            apply_enabled_passes = _effective_enabled_passes()
            for _, result in active_pairs:
                result.rejit_result = active_daemon_session.apply_rejit(
                    result.rejit_prog_ids,
                    enabled_passes=apply_enabled_passes,
                )
                _check_daemon()
        for session, result in active_pairs:
            try:
                result.post_rejit = measure(session, result.state, "post_rejit")
            except Exception as exc:
                result.error = str(exc)
            _check_daemon()
    except Exception as exc:
        fatal_error = str(exc)
    finally:
        for session, result in session_results:
            if not result.stopped:
                _stop_session(session, result)

    return lifecycle_results, fatal_error


def run_case_lifecycle(
    *,
    daemon_session: PreparedDaemonSession,
    setup: Callable[[], object],
    start: Callable[[object], CaseLifecycleState],
    workload: Callable[[object, CaseLifecycleState, str], Mapping[str, object] | None],
    stop: Callable[[object, CaseLifecycleState], None],
    cleanup: Callable[[object], None],
    enabled_passes: Sequence[str] | None = None,
    after_baseline: Callable[[object, CaseLifecycleState, Mapping[str, object]], Mapping[str, object] | None] | None = None,
    resolve_rejit_prog_ids: Callable[[object, CaseLifecycleState, Mapping[str, object]], Sequence[int] | None] | None = None,
) -> LifecycleRunResult:
    setup_state = setup()
    try:
        lifecycle_state = start(setup_state)
        session_results, fatal_error = run_lifecycle_sessions(
            daemon_session=daemon_session,
            sessions=[lifecycle_state],
            get_state=lambda session: session,
            measure=lambda _, state, phase: workload(setup_state, state, phase),
            stop=lambda _, state: stop(setup_state, state),
            enabled_passes=enabled_passes,
            after_baseline=(
                None
                if after_baseline is None
                else lambda _, state, baseline: after_baseline(setup_state, state, baseline)
            ),
            resolve_rejit_prog_ids=(
                None
                if resolve_rejit_prog_ids is None
                else lambda _, state, baseline: resolve_rejit_prog_ids(setup_state, state, baseline)
            ),
        )
        session_result = session_results[0]
        error_message = fatal_error or session_result.error
        if session_result.stop_error:
            error_message = (
                f"{error_message}; stop failed: {session_result.stop_error}"
                if error_message
                else session_result.stop_error
            )
        if error_message:
                raise RuntimeError(error_message)
        return LifecycleRunResult(
            state=session_result.state,
            baseline=session_result.baseline,
            rejit_result=session_result.rejit_result,
            post_rejit=session_result.post_rejit,
            artifacts=dict(session_result.state.artifacts),
        )
    finally:
        cleanup(setup_state)


def _default_runner_lifecycle_state(runner: AppRunner, started_prog_ids: Sequence[int]) -> CaseLifecycleState:
    prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
    if not prog_ids:
        raise RuntimeError("app runner did not return any live prog_ids")
    programs = [dict(program) for program in runner.programs]
    if not programs:
        raise RuntimeError("app runner did not expose any live programs")
    return CaseLifecycleState(
        runtime=runner, prog_ids=list(prog_ids),
        artifacts={"programs": programs},
    )


def run_app_runner_lifecycle(
    *,
    daemon_session: PreparedDaemonSession,
    runner: AppRunner,
    measure: Callable[[CaseLifecycleState, str], Mapping[str, object] | None],
    enabled_passes: Sequence[str] | None = None,
    build_state: Callable[[AppRunner, list[int]], CaseLifecycleState] | None = None,
    resolve_rejit_prog_ids: Callable[[object, CaseLifecycleState, Mapping[str, object]], Sequence[int] | None] | None = None,
) -> LifecycleRunResult:
    def _start(_: object) -> CaseLifecycleState:
        ids = [int(v) for v in runner.start() if int(v) > 0]
        return build_state(runner, ids) if build_state is not None else _default_runner_lifecycle_state(runner, ids)

    return run_case_lifecycle(
        daemon_session=daemon_session,
        setup=lambda: None,
        start=_start,
        workload=lambda _, lc, ph: measure(lc, ph),
        stop=lambda _, lc: lc.runtime.stop(),
        cleanup=lambda _: None,
        enabled_passes=enabled_passes,
        resolve_rejit_prog_ids=resolve_rejit_prog_ids,
    )

def git_sha() -> str:
    value = run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    if not value:
        raise RuntimeError("git rev-parse returned an empty HEAD revision")
    return value


def host_metadata() -> dict[str, object]:
    metadata: dict[str, object] = {"hostname": platform.node(), "platform": platform.platform(),
                                    "kernel": platform.release(), "python": sys.version.split()[0]}
    try:
        metadata["git_sha"] = git_sha()
    except Exception as exc:
        metadata["git_sha"] = None
        metadata["git_sha_error"] = str(exc)
    return metadata
