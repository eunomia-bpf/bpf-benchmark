from __future__ import annotations

import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Mapping

from runner.libs.bpf_stats import program_table_count
from runner.libs.kinsn import relpath
from runner.libs.rejit import DaemonSession

DEFAULT_SUITE_QUIESCE_TIMEOUT_S = 200.0
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
    previous_count: int | None = None
    stable_since: float | None = None
    while True:
        now = time.monotonic()
        current_count = program_table_count()
        if current_count == previous_count:
            if stable_since is None:
                stable_since = now
            if now - stable_since >= stable_window:
                return
        else:
            previous_count = current_count
            stable_since = now
        if now >= deadline:
            break
        time.sleep(min(poll_interval, max(0.0, deadline - now)))
    raise RuntimeError(
        "kernel program table did not quiesce between suite entries within "
        f"{float(timeout_s):.1f}s; last visible program count={previous_count}"
    )


@dataclass
class CaseLifecycleState:
    runtime: object
    artifacts: dict[str, object] = field(default_factory=dict)


@dataclass
class PreparedDaemonSession:
    session: DaemonSession
    metadata: dict[str, object]
    failure_artifacts_dir: Path | None = None


@dataclass
class LifecycleRunResult:
    state: CaseLifecycleState | None
    baseline: Mapping[str, object] | None
    rejit_result: dict[str, object] | None
    post_rejit: Mapping[str, object] | None
    artifacts: dict[str, object] = field(default_factory=dict)
    error: str = ""
    stop_error: str = ""
    stopped: bool = False


def prepare_daemon_session(
    daemon_session: DaemonSession,
    *,
    failure_artifacts_dir: Path | None = None,
) -> PreparedDaemonSession:
    metadata = dict(getattr(daemon_session, "kinsn_metadata", {}) or {})
    # Stock-kernel shim path has no kinsn modules; an empty dict is valid.
    metadata["daemon_binary"] = relpath(daemon_session.daemon_binary.resolve())
    return PreparedDaemonSession(
        session=daemon_session,
        metadata=metadata,
        failure_artifacts_dir=failure_artifacts_dir,
    )
