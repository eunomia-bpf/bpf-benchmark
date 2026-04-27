from __future__ import annotations

import unittest
from types import SimpleNamespace

from runner.libs.case_common import (
    CaseLifecycleState,
    PreparedDaemonSession,
    WORKLOAD_MISS_LIMITATION,
    annotate_workload_measurement,
    measurement_workload_miss,
    merge_measurement_limitations,
    run_lifecycle_sessions,
)


class WorkloadMeasurementTests(unittest.TestCase):
    def test_annotates_workload_miss_when_all_run_counts_are_zero(self) -> None:
        measurement = annotate_workload_measurement(
            {
                "bpf": {
                    101: {"run_cnt_delta": 0},
                    102: {"run_cnt_delta": 0},
                },
                "limitations": ["existing limitation"],
            }
        )

        self.assertTrue(measurement_workload_miss(measurement))
        self.assertEqual(
            ["existing limitation", WORKLOAD_MISS_LIMITATION],
            measurement["limitations"],
        )

    def test_does_not_mark_workload_miss_when_any_program_ran(self) -> None:
        measurement = annotate_workload_measurement(
            {
                "bpf": {
                    101: {"run_cnt_delta": 0},
                    102: {"run_cnt_delta": 7},
                }
            }
        )

        self.assertFalse(measurement_workload_miss(measurement))
        self.assertEqual([], measurement["limitations"])

    def test_merge_measurement_limitations_deduplicates_entries(self) -> None:
        workload_miss = annotate_workload_measurement({"bpf": {101: {"run_cnt_delta": 0}}})
        merged = merge_measurement_limitations(
            workload_miss,
            {"limitations": [WORKLOAD_MISS_LIMITATION, "other limitation"]},
        )

        self.assertEqual([WORKLOAD_MISS_LIMITATION, "other limitation"], merged)


class _FakeProc:
    def poll(self) -> None:
        return None


class _FakeDaemonSession:
    def __init__(self) -> None:
        self.proc = _FakeProc()
        self.apply_calls: list[tuple[list[int], list[str]]] = []

    def apply_rejit(
        self,
        prog_ids: list[int],
        *,
        enabled_passes: list[str],
    ) -> dict[str, object]:
        self.apply_calls.append((list(prog_ids), list(enabled_passes)))
        return {"applied": True}


class LifecycleSessionTests(unittest.TestCase):
    def test_run_lifecycle_sessions_runs_fixed_phases(self) -> None:
        daemon_session = _FakeDaemonSession()
        prepared = PreparedDaemonSession(session=daemon_session, metadata={})
        state = CaseLifecycleState(
            runtime=SimpleNamespace(),
            prog_ids=[101],
            artifacts={"programs": [{"id": 101}]},
        )
        session = SimpleNamespace(state=state)
        phase_calls: list[str] = []
        stop_calls: list[list[int]] = []

        def measure(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
            phase_calls.append(phase_name)
            return {"status": "ok", "measurement": {"phase": phase_name, "prog_ids": list(lifecycle.prog_ids)}}

        def stop(_: object, lifecycle: CaseLifecycleState) -> None:
            stop_calls.append(list(lifecycle.prog_ids))

        results, fatal_error = run_lifecycle_sessions(
            daemon_session=prepared,
            sessions=[session],
            get_state=lambda current: current.state,
            measure=measure,
            stop=stop,
            enabled_passes=[" map_inline ", "map_inline", "dce"],
        )

        self.assertEqual("", fatal_error)
        self.assertEqual(["baseline", "post_rejit"], phase_calls)
        self.assertEqual([([101], ["map_inline", "dce"])], daemon_session.apply_calls)
        self.assertEqual([[101]], stop_calls)
        self.assertEqual({"applied": True}, results[0].rejit_result)
        self.assertEqual([101], results[0].rejit_prog_ids)


if __name__ == "__main__":
    unittest.main()
